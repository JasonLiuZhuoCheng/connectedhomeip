package com.google.chip.chiptool.clusterclient.clusterinteraction

import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.LinearLayout
import android.widget.TextView
import androidx.appcompat.app.AlertDialog
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.core.view.forEach
import androidx.recyclerview.widget.RecyclerView
import chip.clusterinfo.CommandParameterInfo
import chip.clusterinfo.CommandResponseInfo
import com.google.chip.chiptool.R
import kotlinx.android.synthetic.main.cluster_callback_item.view.clusterCallbackDataTv
import kotlinx.android.synthetic.main.cluster_callback_item.view.clusterCallbackNameTv
import kotlinx.android.synthetic.main.cluster_callback_item.view.clusterCallbackTypeTv
import kotlinx.android.synthetic.main.cluster_interaction_history_item_info.view.historyClusterNameTv
import kotlinx.android.synthetic.main.cluster_interaction_history_item_info.view.historyCommandNameTv
import kotlinx.android.synthetic.main.cluster_parameter_item.view.clusterParameterData
import kotlinx.android.synthetic.main.cluster_parameter_item.view.clusterParameterNameTv
import kotlinx.android.synthetic.main.cluster_parameter_item.view.clusterParameterTypeTv

/**
 * EndpointAdapter implements the endpointList(RecycleView) Adapter and associates different
 * endpoint with the same onClick function provided in [ClusterInteractionFragment.EndpointListener]
 */
class HistoryCommandAdapter(
  private val HistoryCommandList: List<HistoryCommand>,
  private val listener: ClusterInteractionHistoryFragment.HistoryCommandListener,
  private val inflater: LayoutInflater,
) : RecyclerView.Adapter<HistoryCommandAdapter.HistoryCommandViewHolder>() {

  inner class HistoryCommandViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView),
                                                         View.OnClickListener {
    var historyInfo: LinearLayout = itemView.findViewById(R.id.historyInfo)
    var parameterList: LinearLayout = itemView.findViewById(R.id.historyParameterList)
    var responseValueList: LinearLayout = itemView.findViewById(R.id.historyResponseValueList)

    init {
      itemView.setOnClickListener(this)
    }

    override fun onClick(endpointItem: View) {
      val position = this.adapterPosition
      if (position != RecyclerView.NO_POSITION) {
        listener.onItemClick(position)
      }
    }
  }

  interface OnItemClickListener {
    fun onItemClick(position: Int)
  }

  override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): HistoryCommandViewHolder {
    val itemView =
      LayoutInflater.from(parent.context)
        .inflate(R.layout.cluster_interaction_history_item, parent, false)
    return HistoryCommandViewHolder(itemView)
  }

  override fun getItemCount(): Int {
    return HistoryCommandList.size
  }

  override fun getItemId(position: Int): Long {
    return position.toLong()
  }

  override fun getItemViewType(position: Int): Int {
    return position
  }

  override fun onBindViewHolder(
    holder: HistoryCommandAdapter.HistoryCommandViewHolder,
    position: Int
  ) {
    // go through each element and fill the data
    val info = inflater.inflate(
      R.layout.cluster_interaction_history_item_info,
      null,
      false
    ) as ConstraintLayout
    info.historyClusterNameTv.text = HistoryCommandList[position].clusterName
    info.historyCommandNameTv.text = HistoryCommandList[position].commandName
    holder.historyInfo.addView(info)
    Log.d("here", holder.parameterList.toString())
    if (HistoryCommandList[position].parameterList.isEmpty()) {
      val emptyParameterList =
        inflater.inflate(android.R.layout.simple_list_item_1, null, false) as TextView
      emptyParameterList.text = "No parameter"
      holder.parameterList.addView(emptyParameterList)
    } else {
      HistoryCommandList[position].parameterList.forEach {
        val param = inflater.inflate(R.layout.cluster_parameter_item, null, false) as ConstraintLayout
        param.clusterParameterData.setText(it.parameterData)
        param.clusterParameterNameTv.text = it.parameterName
        param.clusterParameterTypeTv.text = it.parameterType
        holder.parameterList.addView(param)
      }
    }
    if (HistoryCommandList[position].responseValue!!.isEmpty()) {
      val emptyResponseInfo =
        inflater.inflate(android.R.layout.simple_list_item_1, null, false) as TextView
      emptyResponseInfo.text = "No response"
      holder.responseValueList.addView(emptyResponseInfo)
    } else {
      populateCallbackResult(
        HistoryCommandList[position].responseValue!!,
        inflater,
        holder.responseValueList
      )
    }
  }

  private fun populateCallbackResult(
    responseValues: Map<CommandResponseInfo, Any>,
    inflater: LayoutInflater,
    callbackList: LinearLayout
  ) {
    responseValues.forEach { (variableNameType, response) ->
      if (response is List<*>) {
        createListResponseView(response, inflater, callbackList, variableNameType)
      } else {
        createBasicResponseView(response, inflater, callbackList, variableNameType)
      }
    }
  }

  private fun createBasicResponseView(
    response: Any,
    inflater: LayoutInflater,
    callbackList: LinearLayout,
    variableNameType: CommandResponseInfo
  ) {
    val callbackItem =
      inflater.inflate(R.layout.cluster_callback_item, null, false) as ConstraintLayout
    callbackItem.clusterCallbackNameTv.text = variableNameType.name
    callbackItem.clusterCallbackDataTv.text = if (response.javaClass == ByteArray::class.java) {
      (response as ByteArray).decodeToString()
    } else {
      response.toString()
    }
    callbackItem.clusterCallbackTypeTv.text = variableNameType.type
    callbackList.addView(callbackItem)
  }

  private fun createListResponseView(
    response: List<*>,
    inflater: LayoutInflater,
    callbackList: LinearLayout,
    variableNameType: CommandResponseInfo
  ) {
    if (response.isEmpty()) {
      val emptyCallback =
        inflater.inflate(R.layout.cluster_callback_item, null, false) as ConstraintLayout
      emptyCallback.clusterCallbackNameTv.text = "Result is empty"
      callbackList.addView(emptyCallback)
    } else {
      response.forEachIndexed { index, it ->
        val attributeCallbackItem =
          inflater.inflate(R.layout.cluster_callback_item, null, false) as ConstraintLayout
        attributeCallbackItem.clusterCallbackNameTv.text = variableNameType.name + "[$index]"
        val objectString = if (it!!.javaClass == ByteArray::class.java) {
          (it as ByteArray).contentToString()
        } else {
          it.toString()
        }
        var callbackClassName = if (it!!.javaClass == ByteArray::class.java) {
          "Byte[]"
        } else {
          it!!.javaClass.toString().split('$').last()
        }
        attributeCallbackItem.clusterCallbackDataTv.text = objectString
        attributeCallbackItem.clusterCallbackTypeTv.text = "List<$callbackClassName>"
        callbackList.addView(attributeCallbackItem)
      }
    }
  }
}