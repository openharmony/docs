# ping<a name="ZH-CN_TOPIC_0000001133846496"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

ping命令用于测试网络连接是否正常。

## 命令格式<a name="section02"></a>

ping _\[-4\] \[-c cnt\] \[-f\] \[-i interval\] \[-q\] \[-s size\] <IP\>_

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table2664mcpsimp"></a>
<table><thead align="left"><tr id="row2670mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p2672mcpsimp"><a name="p2672mcpsimp"></a><a name="p2672mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p2674mcpsimp"><a name="p2674mcpsimp"></a><a name="p2674mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p2676mcpsimp"><a name="p2676mcpsimp"></a><a name="p2676mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>查看ping命令支持的参数列表</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row2703mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2705mcpsimp"><a name="p2705mcpsimp"></a><a name="p2705mcpsimp"></a>-4</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2707mcpsimp"><a name="p2707mcpsimp"></a><a name="p2707mcpsimp"></a>强制以IPV4通讯协议ping目标地址。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p2710mcpsimp"><a name="p2710mcpsimp"></a><a name="p2710mcpsimp"></a>0-65500</p>
</td>
</tr>
<tr id="row2690mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2692mcpsimp"><a name="p2692mcpsimp"></a><a name="p2692mcpsimp"></a>-c CNT</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2694mcpsimp"><a name="p2694mcpsimp"></a><a name="p2694mcpsimp"></a>执行的次数，不带本参数则默认为3次。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p2696mcpsimp"><a name="p2696mcpsimp"></a><a name="p2696mcpsimp"></a>1-65535</p>
</td>
</tr>
<tr id="row2711mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2713mcpsimp"><a name="p2713mcpsimp"></a><a name="p2713mcpsimp"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2715mcpsimp"><a name="p2715mcpsimp"></a><a name="p2715mcpsimp"></a>隐式的ping IPv4地址，其默认参数配置等价于"-c 15 -i 0.2"</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p20501182215720"><a name="p20501182215720"></a><a name="p20501182215720"></a>N/A</p>
</td>
</tr>
<tr id="row2697mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2699mcpsimp"><a name="p2699mcpsimp"></a><a name="p2699mcpsimp"></a>-i interval</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2701mcpsimp"><a name="p2701mcpsimp"></a><a name="p2701mcpsimp"></a>发送两次ping包的时间间隔，单位毫秒。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p971414819577"><a name="p971414819577"></a><a name="p971414819577"></a>1-200</p>
</td>
</tr>
<tr id="row2718mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2720mcpsimp"><a name="p2720mcpsimp"></a><a name="p2720mcpsimp"></a>-q</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2722mcpsimp"><a name="p2722mcpsimp"></a><a name="p2722mcpsimp"></a>隐式的ping IPv4地址，如果主机还存活，则在返回 true 后停止ping。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p940472325719"><a name="p940472325719"></a><a name="p940472325719"></a>N/A</p>
</td>
</tr>
<tr id="row2718mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2720mcpsimp"><a name="p2720mcpsimp"></a><a name="p2720mcpsimp"></a>-s SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2722mcpsimp"><a name="p2722mcpsimp"></a><a name="p2722mcpsimp"></a>设置每个ping包的大小，SIZE是以字节为单位的数据（默认为56字节）。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p940472325719"><a name="p940472325719"></a><a name="p940472325719"></a>0-4088</p>
</td>
</tr>
<tr id="row2677mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2679mcpsimp"><a name="p2679mcpsimp"></a><a name="p2679mcpsimp"></a>IP</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2681mcpsimp"><a name="p2681mcpsimp"></a><a name="p2681mcpsimp"></a>要测试是否网络连通的IPv4地址。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="entry2682mcpsimpp0"><a name="entry2682mcpsimpp0"></a><a name="entry2682mcpsimpp0"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   ping命令用来测试到目的IP的网络连接是否正常，参数为目的IP地址。
-   如果目的IP不可达，会显示请求超时。
-   如果显示发送错误，说明没有到目的IP的路由。
-   命令需要启动TCP/IP协议栈后才能使用。

## 使用实例<a name="section05"></a>

举例：输入ping 192.168.1.3

## 输出说明<a name="section06"></a>

**示例 1**  ping tftp 服务器地址

```shell
OHOS:/$ ping 192.168.1.3
Ping 192.168.1.3 (192.168.1.3): 56(84) bytes.
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=1 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms

--- 192.168.1.3 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss
round-trip min/avg/max = 0/0/0 ms
```
