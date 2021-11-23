package com.google.chip.chiptool.clusterclient.clusterinteraction

data class HistoryCommand (val clusterName: String, val commandName: String, val parameterList: List<String>)