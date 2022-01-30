# ping<a name="EN-US_TOPIC_0000001133846496"></a>

## Command Function<a name="section119672573385"></a>

This command is used to test an IPv4 network connection.

## Syntax<a name="section869419010390"></a>

ping_ _\[_-n cnt_\] \[_-w interval_\] \[_-l data\_len_\]_ <IP\>_

ping \[_-t_\] \[_-w interval_\]  _<IP\>_

ping  _-k_

## Parameters<a name="section9877183173918"></a>

**Table  1**  Parameter description

<a name="table2664mcpsimp"></a>
<table><thead align="left"><tr id="row2670mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p2672mcpsimp"><a name="p2672mcpsimp"></a><a name="p2672mcpsimp"></a><strong id="b8570451611622"><a name="b8570451611622"></a><a name="b8570451611622"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p2674mcpsimp"><a name="p2674mcpsimp"></a><a name="p2674mcpsimp"></a><strong id="b18214141162620"><a name="b18214141162620"></a><a name="b18214141162620"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p2676mcpsimp"><a name="p2676mcpsimp"></a><a name="p2676mcpsimp"></a><strong id="b54224635611622"><a name="b54224635611622"></a><a name="b54224635611622"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row2677mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2679mcpsimp"><a name="p2679mcpsimp"></a><a name="p2679mcpsimp"></a>IP</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2681mcpsimp"><a name="p2681mcpsimp"></a><a name="p2681mcpsimp"></a>Specifies the IPv4 address whose network connectivity is to be tested.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="entry2682mcpsimpp0"><a name="entry2682mcpsimpp0"></a><a name="entry2682mcpsimpp0"></a>N/A</p>
</td>
</tr>
<tr id="row2690mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2692mcpsimp"><a name="p2692mcpsimp"></a><a name="p2692mcpsimp"></a>-n cnt</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2694mcpsimp"><a name="p2694mcpsimp"></a><a name="p2694mcpsimp"></a>Specifies the number of execution times. If this parameter is not specified, the default value is <strong id="b1339603692614"><a name="b1339603692614"></a><a name="b1339603692614"></a>4</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p2696mcpsimp"><a name="p2696mcpsimp"></a><a name="p2696mcpsimp"></a>1-65535</p>
</td>
</tr>
<tr id="row2697mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2699mcpsimp"><a name="p2699mcpsimp"></a><a name="p2699mcpsimp"></a>-w interval</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2701mcpsimp"><a name="p2701mcpsimp"></a><a name="p2701mcpsimp"></a>Specifies the interval (in ms) between two ping packets.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p971414819577"><a name="p971414819577"></a><a name="p971414819577"></a>&gt;0</p>
</td>
</tr>
<tr id="row2703mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2705mcpsimp"><a name="p2705mcpsimp"></a><a name="p2705mcpsimp"></a>-l data_len</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2707mcpsimp"><a name="p2707mcpsimp"></a><a name="p2707mcpsimp"></a>Specifies the data length of the ICMP echo request packet, excluding the ICMP packet header.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p2710mcpsimp"><a name="p2710mcpsimp"></a><a name="p2710mcpsimp"></a>0-65500</p>
</td>
</tr>
<tr id="row2711mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2713mcpsimp"><a name="p2713mcpsimp"></a><a name="p2713mcpsimp"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2715mcpsimp"><a name="p2715mcpsimp"></a><a name="p2715mcpsimp"></a>Specifies a permanent ping thread, which will be killed until the <strong id="b153129414503"><a name="b153129414503"></a><a name="b153129414503"></a>ping -k</strong> command is executed.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p20501182215720"><a name="p20501182215720"></a><a name="p20501182215720"></a>N/A</p>
</td>
</tr>
<tr id="row2718mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2720mcpsimp"><a name="p2720mcpsimp"></a><a name="p2720mcpsimp"></a>-k</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2722mcpsimp"><a name="p2722mcpsimp"></a><a name="p2722mcpsimp"></a>Kills the ping thread and stops the ping operation.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p940472325719"><a name="p940472325719"></a><a name="p940472325719"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section1097046193914"></a>

-   Run the  **ping**  command by setting a destination IP address to check whether the network connection to the destination IP address is normal.
-   If the destination IP address is unreachable, the system displays a message indicating that the request times out.
-   If no route is available to the destination IP address, an error message is displayed.
-   This command can be used only after the TCP/IP protocol stack is enabled.

## Example<a name="section14564129113911"></a>

Run  **ping 192.168.1.10**.

## Output<a name="section1621732891215"></a>

**Figure  1**  Output of pinging the IP address of the TFTP server<a name="fig525762695417"></a>  


![](figure/snipaste_2021-01-26_10-38-58-26.png)

