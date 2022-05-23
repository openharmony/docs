# ping


## Command Function<a name="section119672573385"></a>

This command is used to test an IPv4 connection.

## Syntax<a name="section869419010390"></a>

ping  _\[-4\] \[-c cnt\] \[-f\] \[-i interval\] \[-q\] \[-s size\] <IP\>_

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
<tbody><tr id="row02916415585"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1028111418588"><a name="p1028111418588"></a><a name="p1028111418588"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p122810445818"><a name="p122810445818"></a><a name="p122810445818"></a>Displays the parameters supported by the <strong id="b1796144112279"><a name="b1796144112279"></a><a name="b1796144112279"></a>ping</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1028118410584"><a name="p1028118410584"></a><a name="p1028118410584"></a>N/A</p>
</td>
</tr>
<tr id="row15291104105819"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3281747588"><a name="p3281747588"></a><a name="p3281747588"></a>-4</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p16281846585"><a name="p16281846585"></a><a name="p16281846585"></a>Forcibly pings the destination address using the IPv4 protocol.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p202811548588"><a name="p202811548588"></a><a name="p202811548588"></a>0-65500</p>
</td>
</tr>
<tr id="row82911540582"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p18281646583"><a name="p18281646583"></a><a name="p18281646583"></a>-c CNT</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1281248583"><a name="p1281248583"></a><a name="p1281248583"></a>Specifies the number of execution times. The default value is <strong id="b209506262288"><a name="b209506262288"></a><a name="b209506262288"></a>3</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p528111412581"><a name="p528111412581"></a><a name="p528111412581"></a>1-65535</p>
</td>
</tr>
<tr id="row112911545588"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1028154135811"><a name="p1028154135811"></a><a name="p1028154135811"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p22811642583"><a name="p22811642583"></a><a name="p22811642583"></a>Pings an IPv4 address in implicit mode. The default parameter configuration is equivalent to <strong id="b12261222102915"><a name="b12261222102915"></a><a name="b12261222102915"></a>-c 15 -i 0.2</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p628118425815"><a name="p628118425815"></a><a name="p628118425815"></a>N/A</p>
</td>
</tr>
<tr id="row192917495812"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p02811416589"><a name="p02811416589"></a><a name="p02811416589"></a>-i interval</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p15281184125813"><a name="p15281184125813"></a><a name="p15281184125813"></a>Specifies the interval (in ms) for sending a ping packet.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p5281144195811"><a name="p5281144195811"></a><a name="p5281144195811"></a>1-200</p>
</td>
</tr>
<tr id="row182911647586"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p17281840587"><a name="p17281840587"></a><a name="p17281840587"></a>-q</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p13281124155815"><a name="p13281124155815"></a><a name="p13281124155815"></a>Implicitly pings an IPv4 address. If the host is active, the ping stops after <strong id="b3813112783011"><a name="b3813112783011"></a><a name="b3813112783011"></a>true</strong> is received.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p182811240582"><a name="p182811240582"></a><a name="p182811240582"></a>N/A</p>
</td>
</tr>
<tr id="row92900485818"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5281124125815"><a name="p5281124125815"></a><a name="p5281124125815"></a>-s SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p12281154165819"><a name="p12281154165819"></a><a name="p12281154165819"></a>Specifies the size of a ping packet, in bytes. The default size is <strong id="b145002224316"><a name="b145002224316"></a><a name="b145002224316"></a>56</strong> bytes.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p13281341582"><a name="p13281341582"></a><a name="p13281341582"></a>0-4088</p>
</td>
</tr>
<tr id="row1529016465815"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p202818413586"><a name="p202818413586"></a><a name="p202818413586"></a>IP</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p4282545588"><a name="p4282545588"></a><a name="p4282545588"></a>Specifies the IPv4 address to test.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1928284155810"><a name="p1928284155810"></a><a name="p1928284155810"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section1097046193914"></a>

-   The  **ping**  command is used to check whether the destination IP address is reachable.
-   If the destination IP address is unreachable, the system displays a message indicating that the request times out.
-   If no route is available to the destination IP address, an error message is displayed.
-   This command can be used only after the TCP/IP stack is enabled.

## Example<a name="section14564129113911"></a>

Run  **ping 192.168.1.3**.

## Output<a name="section1621732891215"></a>

Pinging a TFTP server IP address:

```
OHOS:/$ ping 192.168.1.3
Ping 192.168.1.3 (192.168.1.3): 56(84) bytes.
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=1 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
--- 192.168.1.3 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss
round-trip min/avg/max = 0/0/0 ms
```

