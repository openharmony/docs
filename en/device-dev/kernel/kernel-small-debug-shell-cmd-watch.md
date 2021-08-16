# watch<a name="EN-US_TOPIC_0000001134006258"></a>

-   [Command Function](#section20643141481314)
-   [Syntax](#section1075441721316)
-   [Parameters](#section1472810220135)
-   [Usage](#section186772414131)
-   [Example](#section4764192791314)
-   [Output Description](#section5791253155517)

## Command Function<a name="section20643141481314"></a>

This command is used to periodically monitor the execution result of a command.

## Syntax<a name="section1075441721316"></a>

watch

watch \[_-c/-n/-t/--count/--interval/-no-title/--over_\] \[_command_\]

## Parameters<a name="section1472810220135"></a>

**Table  1**  Parameter description

<a name="table966mcpsimp"></a>
<table><thead align="left"><tr id="row973mcpsimp"><th class="cellrowborder" valign="top" width="19.801980198019802%" id="mcps1.2.5.1.1"><p id="p975mcpsimp"><a name="p975mcpsimp"></a><a name="p975mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="29.222922292229224%" id="mcps1.2.5.1.2"><p id="p977mcpsimp"><a name="p977mcpsimp"></a><a name="p977mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="22.26222622262226%" id="mcps1.2.5.1.3"><p id="p979mcpsimp"><a name="p979mcpsimp"></a><a name="p979mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="28.712871287128717%" id="mcps1.2.5.1.4"><p id="p981mcpsimp"><a name="p981mcpsimp"></a><a name="p981mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row982mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p984mcpsimp"><a name="p984mcpsimp"></a><a name="p984mcpsimp"></a>-c / --count</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p986mcpsimp"><a name="p986mcpsimp"></a><a name="p986mcpsimp"></a>Specifies the number of times that the command is executed.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p988mcpsimp"><a name="p988mcpsimp"></a><a name="p988mcpsimp"></a>0xFFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p990mcpsimp"><a name="p990mcpsimp"></a><a name="p990mcpsimp"></a>(0, 0xFFFFFF]</p>
</td>
</tr>
<tr id="row991mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p993mcpsimp"><a name="p993mcpsimp"></a><a name="p993mcpsimp"></a>-n / --interval</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p995mcpsimp"><a name="p995mcpsimp"></a><a name="p995mcpsimp"></a>Specifies the interval for periodically running the command, in seconds.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p997mcpsimp"><a name="p997mcpsimp"></a><a name="p997mcpsimp"></a>1s</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p999mcpsimp"><a name="p999mcpsimp"></a><a name="p999mcpsimp"></a>(0, 0xFFFFFF]</p>
</td>
</tr>
<tr id="row1000mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1002mcpsimp"><a name="p1002mcpsimp"></a><a name="p1002mcpsimp"></a>-t / -no-title</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1004mcpsimp"><a name="p1004mcpsimp"></a><a name="p1004mcpsimp"></a>Disables time display on the top.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p1006mcpsimp"><a name="p1006mcpsimp"></a><a name="p1006mcpsimp"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p1008mcpsimp"><a name="p1008mcpsimp"></a><a name="p1008mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1009mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1011mcpsimp"><a name="p1011mcpsimp"></a><a name="p1011mcpsimp"></a>command</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1013mcpsimp"><a name="p1013mcpsimp"></a><a name="p1013mcpsimp"></a>Specifies the command to be monitored.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p1015mcpsimp"><a name="p1015mcpsimp"></a><a name="p1015mcpsimp"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p1017mcpsimp"><a name="p1017mcpsimp"></a><a name="p1017mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1018mcpsimp"><td class="cellrowborder" valign="top" width="19.801980198019802%" headers="mcps1.2.5.1.1 "><p id="p1020mcpsimp"><a name="p1020mcpsimp"></a><a name="p1020mcpsimp"></a>--over</p>
</td>
<td class="cellrowborder" valign="top" width="29.222922292229224%" headers="mcps1.2.5.1.2 "><p id="p1022mcpsimp"><a name="p1022mcpsimp"></a><a name="p1022mcpsimp"></a>Stops the current command monitoring.</p>
</td>
<td class="cellrowborder" valign="top" width="22.26222622262226%" headers="mcps1.2.5.1.3 "><p id="p1024mcpsimp"><a name="p1024mcpsimp"></a><a name="p1024mcpsimp"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.2.5.1.4 "><p id="p1026mcpsimp"><a name="p1026mcpsimp"></a><a name="p1026mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section186772414131"></a>

You can run the  **watch --over**  command to stop the currently running command monitoring.

## Example<a name="section4764192791314"></a>

Example:

watch  -n 2 -c 6 task

## Output Description<a name="section5791253155517"></a>

**Figure  1** **task**  command monitoring result<a name="fig125034159462"></a>  
![](figure/task-command-monitoring-result.png "task-command-monitoring-result")

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>In this example, the  **task**  command has been executed every 2 seconds for six times, and the preceding figure shows the output of the last execution.

