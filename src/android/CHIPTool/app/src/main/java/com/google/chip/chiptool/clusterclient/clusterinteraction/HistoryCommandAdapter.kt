package com.google.chip.chiptool.clusterclient.clusterinteraction

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.google.chip.chiptool.R

/**
 * EndpointAdapter implements the endpointList(RecycleView) Adapter and associates different
 * endpoint with the same onClick function provided in [ClusterInteractionFragment.EndpointListener]
 */
class HistoryCommandAdapter(
  private val HistoryCommandList: List<HistoryCommand>,
  private val listener: ClusterInteractionHistoryFragment.HistoryCommandListener
) : RecyclerView.Adapter<HistoryCommandAdapter.HistoryCommandViewHolder>() {

  inner class HistoryCommandViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView),
                                                   View.OnClickListener {
    val clusterName: TextView = itemView.findViewById(R.id.historyClusterNameTv)
    val commandName: TextView = itemView.findViewById(R.id.historyCommandNameTv)
    val parameterList: TextView = itemView.findViewById(R.id.historyParameterListTv)

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
      LayoutInflater.from(parent.context).inflate(R.layout.cluster_interaction_history_command, parent, false)
    return HistoryCommandViewHolder(itemView)
  }

  override fun getItemCount(): Int {
    return HistoryCommandList.size
  }

  override fun onBindViewHolder(holder: HistoryCommandAdapter.HistoryCommandViewHolder, position: Int) {
    holder.clusterName.text = HistoryCommandList[position].clusterName
    holder.commandName.text = HistoryCommandList[position].commandName
  }
}