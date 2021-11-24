# dhclient<a name="ZH-CN_TOPIC_0000001179845937"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

设置和查看dhclient的参数。

## 命令格式<a name="section02"></a>

- dhclient <_netif name_\>

- dhclient -x <_netif name_\>

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table438mcpsimp"></a>
<table><thead align="left"><tr id="row444mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row1110416513817"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p110445143817"><a name="p110445143817"></a><a name="p110445143817"></a>-h | --help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1510414514386"><a name="p1510414514386"></a><a name="p1510414514386"></a>查看dhclient命令支持的参数列表，及使用方式。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1410445183811"><a name="p1410445183811"></a><a name="p1410445183811"></a>N/A</p>
</td>
</tr>
<tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>&lt;netif name&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>启动对应网卡的dhcp请求。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>网卡名字，eth0。</p>
</td>
</tr>
<tr id="row1110416513817"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p110445143817"><a name="p110445143817"></a><a name="p110445143817"></a>-x &lt;netif name&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1510414514386"><a name="p1510414514386"></a><a name="p1510414514386"></a>关闭对应网卡的dhcp功能。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1410445183811"><a name="p1410445183811"></a><a name="p1410445183811"></a>网卡名字，eth0。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

无。

## 使用实例<a name="section05"></a>

举例：

- dhclient eth0
- dhclient -x eth0


## 输出说明<a name="section06"></a>

**示例 1** 启动网卡eth0的dhcp请求

```shell
OHOS:/$ dhclient eth0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
OHOS:/$
```

**示例 2** 关闭网卡eth0的dhcp请求

```shell
OHOS:/$ dhclient -x eth0
NetifStatusCallback(eth0): nsc event: 0xf0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:0.0.0.0 netmask:0.0.0.0 gateway:0.0.0.0
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
```

