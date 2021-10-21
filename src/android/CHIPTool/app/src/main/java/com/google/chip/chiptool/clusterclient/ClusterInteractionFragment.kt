package com.google.chip.chiptool.clusterclient

import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.Fragment
import chip.clusterinfo.ClusterCommandCallback
import chip.clusterinfo.ClusterInfo
import chip.clusterinfo.CommandInfo
import chip.devicecontroller.ChipClusters
import chip.devicecontroller.ChipDeviceController
import com.google.chip.chiptool.ChipClient
import com.google.chip.chiptool.GenericChipDeviceListener
import com.google.chip.chiptool.R
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.cancel
import chip.devicecontroller.ClusterInfoMapping
import java.lang.Exception
import kotlin.coroutines.resume
import kotlin.coroutines.resumeWithException
import kotlin.coroutines.suspendCoroutine
import kotlinx.android.synthetic.main.cluster_interaction_fragment.view.getClusterMappingBtn
import kotlinx.coroutines.launch

class ClusterInteractionFragment : Fragment() {
  private val deviceController: ChipDeviceController
    get() = ChipClient.getDeviceController(requireContext())

  private val scope = CoroutineScope(Dispatchers.Main + Job())
  private lateinit var addressUpdateFragment: AddressUpdateFragment
  private lateinit var clusterMap: Map<String, ClusterInfo>
  private lateinit var deviceDescriptor: Pair<Int, Int>
  private lateinit var endpointDescriptor: List<EndpointDescriptor>

  override fun onCreateView(
    inflater: LayoutInflater,
    container: ViewGroup?,
    savedInstanceState: Bundle?
  ): View {
    return inflater.inflate(R.layout.cluster_interaction_fragment, container, false).apply {
      deviceController.setCompletionListener(ChipControllerCallback())
      addressUpdateFragment =
        childFragmentManager.findFragmentById(R.id.addressUpdateFragment) as AddressUpdateFragment
      clusterMap = ClusterInfoMapping().clusterMap;
//      deviceDescriptor = getDeviceDescriptor()
      scope.launch {
        val endpointDescriptor: List<EndpointDescriptor> = getEndpointDescriptors()
        Log.v(TAG, endpointDescriptor.toString())
      }
      getClusterMappingBtn.setOnClickListener { scope.launch { getClusterMapping() } }
    }
  }

  private suspend fun getClusterMapping() {
    // In real code: "OnOff" would be selected by the user.
    val methodSelected = "onOff"
    showMessage(methodSelected + " is initialized")
    val selectedClusterInfo = clusterMap[methodSelected]!!
    val devicePtr =
      ChipClient.getConnectedDevicePointer(requireContext(), addressUpdateFragment.deviceId)
    val endpointId = 1
    val selectedCluster = selectedClusterInfo.createClusterFunction.create(devicePtr, endpointId)
    // Imagine user wants to execute the command "OffWithEffect", pass the string here
    val selectedCommandInfo: CommandInfo = selectedClusterInfo.commands["on"]!!

    var selectedCommandCallback =  selectedCommandInfo.commandCallbackSupplier.get()
    selectedCommandCallback?.setCallbackDelegate(object : ClusterCommandCallback {
      override fun onSuccess(responseValues: List<Any>) {
        showMessage("Command success")
        // Populate UI based on response values. We know the types from CommandInfo.getCommandResponses().
        responseValues.forEach { Log.d(TAG, it.toString()) }
      }

      override fun onFailure(exception: Exception) {
        showMessage("Command failed")
        Log.e(TAG, exception.toString())
      }
    })

    var commandArguments: HashMap<String, Any> = HashMap<String, Any>()
    selectedCommandInfo.getCommandFunction().invokeCommand(selectedCluster, selectedCommandCallback, commandArguments)
  }

  private fun showMessage(msg: String) {
    requireActivity().runOnUiThread {
      Toast.makeText(requireContext(), msg, Toast.LENGTH_SHORT).show()
    }
  }

  private suspend fun getEndpointDescriptors(): List<EndpointDescriptor> {
    val devicePointer = ChipClient.getConnectedDevicePointer(requireContext(), addressUpdateFragment.deviceId)
    val queue = ArrayDeque<Int>()
    val endpointsMap = HashMap<Int, EndpointDescriptor>()
    queue.add(0)
    while (!queue.isEmpty()) {
      val endpointId = queue.removeFirst()
      if (!endpointsMap.containsKey(endpointId)) {
        val endpointDescriptor = getEndpointDescriptor(devicePointer, endpointId)
        endpointsMap.put(endpointId, endpointDescriptor)
        queue.addAll(endpointDescriptor.data.partsList)
      }
    }
    return endpointsMap.values.toList().sorted()
    // bfs here
  }

  private suspend fun getEndpointDescriptor(devicePointer: Long, endpointId: Int): EndpointDescriptor {
    val descriptorCLuster = ChipClusters.DescriptorCluster(devicePointer, endpointId)
    val partsList = descriptorCLuster.getPartsList()
    return EndpointDescriptor(endpointId, ClusterData(partsList))
  }


  private suspend fun ChipClusters.DescriptorCluster.getPartsList(): List<Int> {
    return suspendCoroutine { continuation ->
      readPartsListAttribute(object : ChipClusters.DescriptorCluster.PartsListAttributeCallback {
        override fun onSuccess(partsList: List<Int>) {
          Log.v(TAG, partsList.toString())
          continuation.resume(partsList)
        }

        override fun onError(error: Exception) {
          continuation.resumeWithException(error)
        }
      })
    }
  }

  inner class ChipControllerCallback : GenericChipDeviceListener() {
    override fun onConnectDeviceComplete() {}

    override fun onCommissioningComplete(nodeId: Long, errorCode: Int) {
    }

    override fun onNotifyChipConnectionClosed() {
      Log.d(TAG, "onNotifyChipConnectionClosed")
    }

    override fun onCloseBleComplete() {
      Log.d(TAG, "onCloseBleComplete")
    }

    override fun onError(error: Throwable?) {
      Log.d(TAG, "onError: $error")
    }
  }

  override fun onStop() {
    super.onStop()
    scope.cancel()
  }

  companion object {
    private const val TAG = "ClusterInteractionFragment"
    fun newInstance(): ClusterInteractionFragment = ClusterInteractionFragment()
  }

  data class EndpointDescriptor(val id: Int, val data: ClusterData) : Comparable<EndpointDescriptor> {
    override fun compareTo(other: EndpointDescriptor): Int {
      return compareValuesBy(this, other, EndpointDescriptor::id)
    }
  }


  /**
   * Represents information available on an endpoint from its Descriptor Cluster.
   *
   * @property partsList the list of endpoint IDs that are associated with this endpoint
   * @property deviceTypes the list of device types that this endpoint supports
   * @property serverClusterIds the list of server cluster IDs supported on this endpoint
   * @property clientClusterIds the list of client cluster IDs supported on this endpoint
   */
  data class ClusterData(
    val partsList: List<Int> = listOf(),
//    val deviceTypes: List<DeviceType> = listOf(),
//    val serverClusterIds: List<Long> = listOf(),
//    val clientClusterIds: List<Long> = listOf(),
  )

}