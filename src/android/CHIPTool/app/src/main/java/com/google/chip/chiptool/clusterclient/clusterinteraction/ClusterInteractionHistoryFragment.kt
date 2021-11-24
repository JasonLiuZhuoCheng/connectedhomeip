package com.google.chip.chiptool.clusterclient.clusterinteraction

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.recyclerview.widget.LinearLayoutManager
import com.google.chip.chiptool.R
import kotlinx.android.synthetic.main.cluster_interaction_history_fragment.view.historyCommandList

/**
 * A simple [Fragment] subclass.
 * Use the [ClusterInteractionHistoryFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class ClusterInteractionHistoryFragment : Fragment() {

  override fun onCreateView(
    inflater: LayoutInflater, container: ViewGroup?,
    savedInstanceState: Bundle?
  ): View? {
    // Inflate the layout for this fragment
    return inflater.inflate(R.layout.cluster_interaction_history_fragment, container, false).apply {
      var dataList: List<HistoryCommand> = ArrayList()
      for (i in 0 until 2) {
        dataList += HistoryCommand("test$i", "test$i", listOf("a", "b", "c"))
      }
      historyCommandList.adapter = HistoryCommandAdapter(dataList, HistoryCommandListener())
      historyCommandList.layoutManager = LinearLayoutManager(requireContext())
    }
  }

  companion object {
    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment ClusterInteractionHistoryFragment.
     */
    @JvmStatic
    fun newInstance() =
      ClusterInteractionHistoryFragment().apply {
        arguments = Bundle().apply {
        }
      }
  }

  private fun showFragment(fragment: Fragment, showOnBack: Boolean = true) {
    val fragmentTransaction = requireActivity().supportFragmentManager
      .beginTransaction()
      .replace(R.id.fragment_container, fragment, fragment.javaClass.simpleName)

    if (showOnBack) {
      fragmentTransaction.addToBackStack(null)
    }

    fragmentTransaction.commit()
  }

  inner class HistoryCommandListener : HistoryCommandAdapter.OnItemClickListener {
    override fun onItemClick(position: Int) {
      Toast.makeText(requireContext(), "Item $position clicked", Toast.LENGTH_SHORT).show()
    }
  }
}