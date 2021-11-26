package com.google.chip.chiptool.clusterclient.clusterinteraction

import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.LinearLayout
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.recyclerview.widget.LinearLayoutManager
import chip.clusterinfo.CommandResponseInfo
import com.google.chip.chiptool.R
import kotlinx.android.synthetic.main.cluster_callback_item.view.clusterCallbackDataTv
import kotlinx.android.synthetic.main.cluster_callback_item.view.clusterCallbackNameTv
import kotlinx.android.synthetic.main.cluster_callback_item.view.clusterCallbackTypeTv
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
    Log.d(TAG, clusterInteractionHistoryList.toString())
    return inflater.inflate(R.layout.cluster_interaction_history_fragment, container, false).apply {
      historyCommandList.adapter =
        HistoryCommandAdapter(clusterInteractionHistoryList, HistoryCommandListener(), inflater)
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

    private const val TAG = "ClusterInteractionHistoryFragment"
    var clusterInteractionHistoryList = ArrayDeque<HistoryCommand>()
    fun newInstance() =
      ClusterInteractionHistoryFragment().apply {
        arguments = Bundle().apply {
        }
      }
  }

  inner class HistoryCommandListener : HistoryCommandAdapter.OnItemClickListener {
    override fun onItemClick(position: Int) {
      Toast.makeText(requireContext(), "Item $position clicked", Toast.LENGTH_SHORT).show()
    }
  }
}