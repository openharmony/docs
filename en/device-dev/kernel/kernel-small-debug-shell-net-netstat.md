# netstat


## Command Function<a name="section13469162113816"></a>

The  **netstat**  command is a console command and is used for monitoring the TCP/IP network. It can display the actual network connections and the status of each network interface device. This command displays statistics related to TCP and UDP and can be used to check the network connection to each port on the device \(board\).

## Syntax<a name="section795712373812"></a>

netstat

## Parameters<a name="section17629431193817"></a>

None

## Usage<a name="section5277153519380"></a>

netstat

## Example<a name="section108141437163820"></a>

Run  **netstat**.

## Output<a name="section1357015107117"></a>

**netstat**  print information

```
OHOS # netstat
========== total sockets 128 ======  unused sockets 119 ==========
Proto   Recv-Q      Send-Q      Local Address           Foreign Address         State
tcp     0           0           192.168.1.10:578        192.168.1.3:2049        ESTABLISHED
tcp     0           0           192.168.1.10:58653      0.0.0.0:0               LISTEN
tcp     0           0           192.168.1.10:58652      0.0.0.0:0               LISTEN
tcp     0           0           192.168.1.10:58651      0.0.0.0:0               LISTEN
Proto   Recv-Q      Send-Q      Local Address           Foreign Address
udp     0           0           127.0.0.1:62177         127.0.0.1:62178
udp     0           0           0.0.0.0:5684            0.0.0.0:0
udp     0           0           127.0.0.1:62179         127.0.0.1:62180
udp     0           0           127.0.0.1:62180         127.0.0.1:62179
udp     0           0           127.0.0.1:62178         127.0.0.1:62177
```

**Table  1**  Output description

<a name="table2526mcpsimp"></a>
<table><thead align="left"><tr id="row2531mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2533mcpsimp"><a name="p2533mcpsimp"></a><a name="p2533mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p2535mcpsimp"><a name="p2535mcpsimp"></a><a name="p2535mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2536mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2538mcpsimp"><a name="p2538mcpsimp"></a><a name="p2538mcpsimp"></a>Proto</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2540mcpsimp"><a name="p2540mcpsimp"></a><a name="p2540mcpsimp"></a>Protocol type.</p>
</td>
</tr>
<tr id="row2546mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2548mcpsimp"><a name="p2548mcpsimp"></a><a name="p2548mcpsimp"></a>Recv-Q</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2550mcpsimp"><a name="p2550mcpsimp"></a><a name="p2550mcpsimp"></a>Amount of data that is not read by the user.</p>
<p id="p2551mcpsimp"><a name="p2551mcpsimp"></a><a name="p2551mcpsimp"></a>For Listen TCP, the value indicates the number of TCP connections that have finished three-way handshake but are not accepted by users.</p>
</td>
</tr>
<tr id="row2553mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2555mcpsimp"><a name="p2555mcpsimp"></a><a name="p2555mcpsimp"></a>Send-Q</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1250715415473"><a name="p1250715415473"></a><a name="p1250715415473"></a>For a TCP connection, this value indicates the amount of data that has been sent but not acknowledged.</p>
<p id="p1080412214470"><a name="p1080412214470"></a><a name="p1080412214470"></a>For a UDP connection, this value indicates the amount of data buffered before IP address resolution is complete.</p>
</td>
</tr>
<tr id="row2558mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2560mcpsimp"><a name="p2560mcpsimp"></a><a name="p2560mcpsimp"></a>Local Address</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2562mcpsimp"><a name="p2562mcpsimp"></a><a name="p2562mcpsimp"></a>Local IP address and port number.</p>
</td>
</tr>
<tr id="row2563mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2565mcpsimp"><a name="p2565mcpsimp"></a><a name="p2565mcpsimp"></a>Foreign Address</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2567mcpsimp"><a name="p2567mcpsimp"></a><a name="p2567mcpsimp"></a>Remote IP address and port number.</p>
</td>
</tr>
<tr id="row2568mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2570mcpsimp"><a name="p2570mcpsimp"></a><a name="p2570mcpsimp"></a>State</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2572mcpsimp"><a name="p2572mcpsimp"></a><a name="p2572mcpsimp"></a>TCP connection status. This parameter is meaningless for UDP.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The command output like "========== total sockets 32 ====== unused sockets 22 BootTime 27 s ==========" indicates that there are 32 sockets in total, 22 sockets are not used, and it has been 27 seconds since the system starts.

