# dhclient


## Command Function<a name="section366714216619"></a>

This command is used to set and query  **dhclient**  parameters.

## Syntax<a name="section8833164614615"></a>

-   dhclient <_netif name_\>
-   dhclient -x <_netif name_\>

## Parameters<a name="section12809111019453"></a>

**Table  1**  Parameter description

<a name="table438mcpsimp"></a>
<table><thead align="left"><tr id="row444mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a><strong id="b20999054421160"><a name="b20999054421160"></a><a name="b20999054421160"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a><strong id="b16991513175018"><a name="b16991513175018"></a><a name="b16991513175018"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a><strong id="b9837196561160"><a name="b9837196561160"></a><a name="b9837196561160"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row15810322374"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p108030222712"><a name="p108030222712"></a><a name="p108030222712"></a>-h | --help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p14803132214716"><a name="p14803132214716"></a><a name="p14803132214716"></a>Displays parameters supported by the <strong id="b71961312874"><a name="b71961312874"></a><a name="b71961312874"></a>dhclient</strong> command and their usage.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p28038222716"><a name="p28038222716"></a><a name="p28038222716"></a>N/A</p>
</td>
</tr>
<tr id="row880917225712"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p6803162212717"><a name="p6803162212717"></a><a name="p6803162212717"></a>&lt;netif name&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p980352211712"><a name="p980352211712"></a><a name="p980352211712"></a>Enables Dynamic Host Configuration Protocol (DHCP) for a network interface card (NIC).</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p48031822276"><a name="p48031822276"></a><a name="p48031822276"></a>NIC name, <strong id="b178511243205513"><a name="b178511243205513"></a><a name="b178511243205513"></a>eth0</strong></p>
</td>
</tr>
<tr id="row78092222716"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p108032221379"><a name="p108032221379"></a><a name="p108032221379"></a>-x &lt;netif name&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1180318222710"><a name="p1180318222710"></a><a name="p1180318222710"></a>Disables DHCP for a NIC.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p78034222072"><a name="p78034222072"></a><a name="p78034222072"></a>NIC name, <strong id="b41988451673"><a name="b41988451673"></a><a name="b41988451673"></a>eth0</strong></p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section15935131220717"></a>

Run the following commands:

-   dhclient eth0
-   dhclient -x eth0

## Example<a name="section79281818476"></a>

Example 1: enabling DHCP for eth0

```
OHOS:/$ dhclient eth0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
OHOS:/$
```

Example 2: disabling DHCP for eth0

```
OHOS:/$ dhclient -x eth0
NetifStatusCallback(eth0): nsc event: 0xf0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:0.0.0.0 netmask:0.0.0.0 gateway:0.0.0.0
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
```

