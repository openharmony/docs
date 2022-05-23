# ifconfig


## Command Function<a name="section174940284379"></a>

This command can be used to:

-   Query and set parameters of a network interface card \(NIC\), such as the IP address, network mask, gateway, and MAC address.
-   Enable or disable a NIC.

## Syntax<a name="section136073203715"></a>

ifconfig \[option\]

option:

-   \[_-a_\]
-   <_interface_\> <_address_\> \[_netmask <mask\>_\] \[_gateway <address\>_\]
-   \[_hw ether <address\>_\] \[_mtu <size\>_\]
-   \[_inet6 add <address\>_\]
-   \[_inet6 del <address\>_\]
-   \[_up|down_\]

## Parameters<a name="section6493235203710"></a>

**Table  1**  Parameter description

<a name="table2005mcpsimp"></a>
<table><thead align="left"><tr id="row2011mcpsimp"><th class="cellrowborder" valign="top" width="17.93%" id="mcps1.2.4.1.1"><p id="p2013mcpsimp"><a name="p2013mcpsimp"></a><a name="p2013mcpsimp"></a><strong id="b207545880811653"><a name="b207545880811653"></a><a name="b207545880811653"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="53.669999999999995%" id="mcps1.2.4.1.2"><p id="p2015mcpsimp"><a name="p2015mcpsimp"></a><a name="p2015mcpsimp"></a><strong id="b519711279124"><a name="b519711279124"></a><a name="b519711279124"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="28.4%" id="mcps1.2.4.1.3"><p id="p2017mcpsimp"><a name="p2017mcpsimp"></a><a name="p2017mcpsimp"></a><strong id="b19371475311653"><a name="b19371475311653"></a><a name="b19371475311653"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row71475414535"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p11941141534"><a name="p11941141534"></a><a name="p11941141534"></a>No parameter</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p1594124175315"><a name="p1594124175315"></a><a name="p1594124175315"></a>Displays all NIC information, which includes the IP address, network mask, gateway, MAC address, maximum transmission unit (MTUs), and running status of each NIC.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p1194174145311"><a name="p1194174145311"></a><a name="p1194174145311"></a>N/A</p>
</td>
</tr>
<tr id="row1814615495314"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p194144135316"><a name="p194144135316"></a><a name="p194144135316"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p13941445534"><a name="p13941445534"></a><a name="p13941445534"></a>Displays data sent and received by the protocol stack.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p1294154155314"><a name="p1294154155314"></a><a name="p1294154155314"></a>N/A</p>
</td>
</tr>
<tr id="row31466417533"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p199410445319"><a name="p199410445319"></a><a name="p199410445319"></a>interface</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p139415485312"><a name="p139415485312"></a><a name="p139415485312"></a>Specifies the NIC name, for example, <strong id="b1368975571410"><a name="b1368975571410"></a><a name="b1368975571410"></a>eth0</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p9944415315"><a name="p9944415315"></a><a name="p9944415315"></a>N/A</p>
</td>
</tr>
<tr id="row9145114165319"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p7947412538"><a name="p7947412538"></a><a name="p7947412538"></a>address</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p119454165313"><a name="p119454165313"></a><a name="p119454165313"></a>Specifies the IP address, for example, <strong id="b530715731519"><a name="b530715731519"></a><a name="b530715731519"></a>192.168.1.10</strong>. The NIC name must be specified.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p99424185316"><a name="p99424185316"></a><a name="p99424185316"></a>N/A</p>
</td>
</tr>
<tr id="row1614415418534"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p1694942532"><a name="p1694942532"></a><a name="p1694942532"></a>netmask</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p194749536"><a name="p194749536"></a><a name="p194749536"></a>Specifies the subnet mask, for example, <strong id="b1625513191514"><a name="b1625513191514"></a><a name="b1625513191514"></a>255.255.255.0</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p094124175316"><a name="p094124175316"></a><a name="p094124175316"></a>N/A</p>
</td>
</tr>
<tr id="row13144942537"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p1494174125316"><a name="p1494174125316"></a><a name="p1494174125316"></a>gateway</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p109413413534"><a name="p109413413534"></a><a name="p109413413534"></a>Specifies the gateway, for example, <strong id="b52931945195112"><a name="b52931945195112"></a><a name="b52931945195112"></a>192.168.1.1</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p19946465313"><a name="p19946465313"></a><a name="p19946465313"></a>N/A</p>
</td>
</tr>
<tr id="row914313405310"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p169415455310"><a name="p169415455310"></a><a name="p169415455310"></a>hw ether</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p20946412532"><a name="p20946412532"></a><a name="p20946412532"></a>Specifies the MAC address, for example, <strong id="b85669109525"><a name="b85669109525"></a><a name="b85669109525"></a>00:11:22:33:44:55</strong>. Currently, only the <strong id="b534492414613"><a name="b534492414613"></a><a name="b534492414613"></a>ether</strong> hardware type is supported.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p19948418537"><a name="p19948418537"></a><a name="p19948418537"></a>N/A</p>
</td>
</tr>
<tr id="row141421142532"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p13941049535"><a name="p13941049535"></a><a name="p13941049535"></a>mtu</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p159418414536"><a name="p159418414536"></a><a name="p159418414536"></a>Specifies the MTU size, for example, <strong id="b2852192012261"><a name="b2852192012261"></a><a name="b2852192012261"></a>1000</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><a name="ul7956417536"></a><a name="ul7956417536"></a><ul id="ul7956417536"><li>IPv4:<p id="p29519485319"><a name="p29519485319"></a><a name="p29519485319"></a>[68,1500]</p>
</li><li>IPv6:<p id="p69524195316"><a name="p69524195316"></a><a name="p69524195316"></a>[1280, 1500]</p>
</li></ul>
</td>
</tr>
<tr id="row1914214419532"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p119554125313"><a name="p119554125313"></a><a name="p119554125313"></a>add</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p1952046539"><a name="p1952046539"></a><a name="p1952046539"></a>Specifies the IPv6 address, for example, <strong id="b12509153516279"><a name="b12509153516279"></a><a name="b12509153516279"></a>2001:a:b:c:d:e:f:d</strong>. The NIC name and <strong id="b912123842916"><a name="b912123842916"></a><a name="b912123842916"></a>inet6</strong> must be specified.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p49516418533"><a name="p49516418533"></a><a name="p49516418533"></a>N/A</p>
</td>
</tr>
<tr id="row17141144175319"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p4952445318"><a name="p4952445318"></a><a name="p4952445318"></a>del</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p1556618562119"><a name="p1556618562119"></a><a name="p1556618562119"></a>Deletes an IPv6 address. You need to specify the NIC name and add the <strong id="b166212197409"><a name="b166212197409"></a><a name="b166212197409"></a>inet6</strong> option. For details, see the example.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p1995248536"><a name="p1995248536"></a><a name="p1995248536"></a>N/A</p>
</td>
</tr>
<tr id="row714064175312"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p12951849536"><a name="p12951849536"></a><a name="p12951849536"></a>up</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p119510455314"><a name="p119510455314"></a><a name="p119510455314"></a>Enables the data processing function of the NIC. The NIC name must be specified.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p695944533"><a name="p695944533"></a><a name="p695944533"></a>N/A</p>
</td>
</tr>
<tr id="row31405465313"><td class="cellrowborder" valign="top" width="17.93%" headers="mcps1.2.4.1.1 "><p id="p49516455316"><a name="p49516455316"></a><a name="p49516455316"></a>down</p>
</td>
<td class="cellrowborder" valign="top" width="53.669999999999995%" headers="mcps1.2.4.1.2 "><p id="p1795164105312"><a name="p1795164105312"></a><a name="p1795164105312"></a>Disables the data processing function of the NIC. The NIC name must be specified.</p>
</td>
<td class="cellrowborder" valign="top" width="28.4%" headers="mcps1.2.4.1.3 "><p id="p12951644532"><a name="p12951644532"></a><a name="p12951644532"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section05763403371"></a>

-   The  **ifconfig**  command can be used only after the TCP/IP stack is enabled.
-   Detecting an IP address conflict takes time. Each time you run the  **ifconfig**  command to set an IP address, there is a delay of about 2 seconds.

## Example<a name="section168802042123717"></a>

-   ifconfig eth0 192.168.100.31 netmask 255.255.255.0 gateway 192.168.100.1 hw ether 00:49:cb:6c:a1:31
-   ifconfig -a
-   ifconfig eth0 inet6 add 2001:a:b:c:d:e:f:d
-   ifconfig eth0 inet6 del 2001:a:b:c:d:e:f:d

## Output<a name="section124638211109"></a>

-   Example 1: setting network parameters

    ```
    OHOS:/$ ifconfig eth0 192.168.100.31 netmask 255.255.255.0 gateway 192.168.100.1 hw ether 00:49:cb:6c:a1:31
    OHOS:/$ ifconfig
    lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
            ip6: ::1/64
            HWaddr 00 MTU:0 Running Link UP
    eth0    ip:192.168.100.31 netmask:255.255.255.0 gateway:192.168.100.1
            HWaddr 00:49:cb:6c:a1:31 MTU:1500 Running Default Link UP
    ```

    The following table describes the output parameters.

    **Table  2**  Output description

    <a name="table2147mcpsimp"></a>
    <table><thead align="left"><tr id="row2152mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2154mcpsimp"><a name="p2154mcpsimp"></a><a name="p2154mcpsimp"></a><strong id="b211311219311653"><a name="b211311219311653"></a><a name="b211311219311653"></a>Parameter</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p2156mcpsimp"><a name="p2156mcpsimp"></a><a name="p2156mcpsimp"></a><strong id="b336412763515"><a name="b336412763515"></a><a name="b336412763515"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17361516205420"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p107151611546"><a name="p107151611546"></a><a name="p107151611546"></a>ip</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p117111610549"><a name="p117111610549"></a><a name="p117111610549"></a>IP address of the board</p>
    </td>
    </tr>
    <tr id="row4363166543"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p15731635412"><a name="p15731635412"></a><a name="p15731635412"></a>netmask</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p187161616540"><a name="p187161616540"></a><a name="p187161616540"></a>Subnet mask</p>
    </td>
    </tr>
    <tr id="row435161665419"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1714162546"><a name="p1714162546"></a><a name="p1714162546"></a>gateway</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1471216175420"><a name="p1471216175420"></a><a name="p1471216175420"></a>Gateway</p>
    </td>
    </tr>
    <tr id="row93541615542"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p671167547"><a name="p671167547"></a><a name="p671167547"></a>HWaddr</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p157111665412"><a name="p157111665412"></a><a name="p157111665412"></a>MAC address of the board</p>
    </td>
    </tr>
    <tr id="row13421645418"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p487161543"><a name="p487161543"></a><a name="p487161543"></a>MTU</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p78016195415"><a name="p78016195415"></a><a name="p78016195415"></a>Maximum transmission unit</p>
    </td>
    </tr>
    <tr id="row433181615412"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10821612543"><a name="p10821612543"></a><a name="p10821612543"></a>Running/Stop</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p281516205410"><a name="p281516205410"></a><a name="p281516205410"></a>Indicates whether the NIC is running.</p>
    </td>
    </tr>
    <tr id="row33320167543"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p5821685419"><a name="p5821685419"></a><a name="p5821685419"></a>Default</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p881516145415"><a name="p881516145415"></a><a name="p881516145415"></a>Indicates that the NIC is connected to the default gateway.</p>
    </td>
    </tr>
    <tr id="row1321166546"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3881695417"><a name="p3881695417"></a><a name="p3881695417"></a>Link UP/Down</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18201614546"><a name="p18201614546"></a><a name="p18201614546"></a>Connection status of the NIC</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example 2: obtaining protocol stack statistics

    ```
    OHOS # ifconfig -a
    RX packets:6922  errors:0        ip dropped:4312         link dropped:67         overrun:0       bytes:0 (0.0 B)
    RX packets(ip6):3     errors:0        dropped:0       overrun:0       bytes:0 (0.0 B)
    TX packets:1394  errors:0        link dropped:67         overrun:0       bytes:0(0.0 B)
    TX packets(ip6):3     errors:0        overrun:0       bytes:0(0.0 B)
    ```

    The following table describes the output parameters.

    **Table  3**  ifconfig -a output description

    <a name="table2209mcpsimp"></a>
    <table><thead align="left"><tr id="row2214mcpsimp"><th class="cellrowborder" valign="top" width="28.999999999999996%" id="mcps1.2.3.1.1"><p id="p2216mcpsimp"><a name="p2216mcpsimp"></a><a name="p2216mcpsimp"></a><strong id="b120972048811653"><a name="b120972048811653"></a><a name="b120972048811653"></a>Parameter</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="71%" id="mcps1.2.3.1.2"><p id="p2218mcpsimp"><a name="p2218mcpsimp"></a><a name="p2218mcpsimp"></a><strong id="b8227191303719"><a name="b8227191303719"></a><a name="b8227191303719"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6921834553"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p117413375517"><a name="p117413375517"></a><a name="p117413375517"></a>RX packets</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p1174183145516"><a name="p1174183145516"></a><a name="p1174183145516"></a>Number of normal packets received at the IP layer.</p>
    </td>
    </tr>
    <tr id="row209212315518"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p274938554"><a name="p274938554"></a><a name="p274938554"></a>RX error</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p1274133195513"><a name="p1274133195513"></a><a name="p1274133195513"></a>Number of error packets received at the IP layer. The errors include the length error, verification error, IP option error, and IP header protocol error.</p>
    </td>
    </tr>
    <tr id="row692832556"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p474234551"><a name="p474234551"></a><a name="p474234551"></a>RX dropped</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p13741637551"><a name="p13741637551"></a><a name="p13741637551"></a>Number of packets discarded at the IP layer. Packets are discarded due to packet errors, packet forwarding failures, and disabled local NICs.</p>
    </td>
    </tr>
    <tr id="row199215312556"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p1674530552"><a name="p1674530552"></a><a name="p1674530552"></a>RX overrun</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p17742305517"><a name="p17742305517"></a><a name="p17742305517"></a>Number of packets that the MAC layer fails to deliver to the upper-layer protocol stack. The failure is caused by resource insufficiency at the protocol stack.</p>
    </td>
    </tr>
    <tr id="row69193145519"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p157417310551"><a name="p157417310551"></a><a name="p157417310551"></a>RX bytes</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p9741385519"><a name="p9741385519"></a><a name="p9741385519"></a>Total length of normal packets received at the IP layer, excluding the length of the fragments that are not reassembled.</p>
    </td>
    </tr>
    <tr id="row091333559"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p1741336554"><a name="p1741336554"></a><a name="p1741336554"></a>TX packets</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p19745375513"><a name="p19745375513"></a><a name="p19745375513"></a>Number of packets that have been normally sent or forwarded at the IP layer.</p>
    </td>
    </tr>
    <tr id="row5914345515"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p147443125513"><a name="p147443125513"></a><a name="p147443125513"></a>TX error</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p9756312553"><a name="p9756312553"></a><a name="p9756312553"></a>Number of packets that the IP layer fails to send. Packets may fail to be sent because the packets cannot be routed or the packets fail to be processed in the protocol stack.</p>
    </td>
    </tr>
    <tr id="row7911032557"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p13752316555"><a name="p13752316555"></a><a name="p13752316555"></a>TX dropped</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p87519395520"><a name="p87519395520"></a><a name="p87519395520"></a>Number of packets that the MAC layer discards due to delivery failures, for example, the NIC driver fails to process the packets.</p>
    </td>
    </tr>
    <tr id="row9901345510"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p27523205513"><a name="p27523205513"></a><a name="p27523205513"></a>TX overrun</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p107512325514"><a name="p107512325514"></a><a name="p107512325514"></a>Reserved.</p>
    </td>
    </tr>
    <tr id="row39016318552"><td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.3.1.1 "><p id="p1475933554"><a name="p1475933554"></a><a name="p1475933554"></a>TX bytes</p>
    </td>
    <td class="cellrowborder" valign="top" width="71%" headers="mcps1.2.3.1.2 "><p id="p7759375512"><a name="p7759375512"></a><a name="p7759375512"></a>Total length of the packets successfully sent or forwarded at the IP layer.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example 3: setting an IPv6 address

    ```
    OHOS:/$ ifconfig eth0 inet6 add 2001:a:b:c:d:e:f:d
    NetifStatusCallback(eth0): nsc event: 0x8
    NetifStatusCallback(eth0): nsc status changed: 0
    NetifStatusCallback(eth0): nsc event: 0x200
    NetifStatusCallback(eth0): nsc event: 0x8
    NetifStatusCallback(eth0): nsc status changed: 1
    NetifStatusCallback(eth0): nsc event: 0x200
    NetifStatusCallback(eth0): nsc event: 0x200
    OHOS:/$ ifconfig
    lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
            ip6: ::1/64
            HWaddr 00 MTU:0 Running Link UP
    eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
            ip6: 2001:A:B:C:D:E:F:D/64
            HWaddr 66:2f:e5:bd:24:e6 MTU:1500 Running Default Link UP
    ```

-   Example 4: deleting an IPv6 address

    ```
    OHOS:/$ ifconfig eth0 inet6 del 2001:a:b:c:d:e:f:d
    NetifStatusCallback(eth0): nsc event: 0x200
    OHOS:/$ ifconfig
    lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
            ip6: ::1/64
            HWaddr 00 MTU:0 Running Link UP
    eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
            HWaddr 66:2f:e5:bd:24:e6 MTU:1500 Running Default Link UP
    ```


