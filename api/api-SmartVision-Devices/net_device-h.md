# net\_device.h<a name="ZH-CN_TOPIC_0000001055358082"></a>

-   [Overview](#section146548793165628)
-   [Summary](#section1239553072165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section146548793165628"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Defines WLAN network device interfaces. 

This module provides network device operations for driver development. The operations are as follows: Initializes, adds, obtains, and deletes a network device. Reports network data, informs the network layer of the data link layer status, sets IP addresses, and starts or stops Dynamic Host Configuration Protocol \(DHCP\). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1239553072165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table752586885165628"></a>
<table><thead align="left"><tr id="row1869885734165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p538611791165628"><a name="p538611791165628"></a><a name="p538611791165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1039742666165628"><a name="p1039742666165628"></a><a name="p1039742666165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row409825279165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254710471165628"><a name="p254710471165628"></a><a name="p254710471165628"></a><a href="EtherHeader.md">EtherHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925198417165628"><a name="p925198417165628"></a><a name="p925198417165628"></a>Defines the Ethernet header information of a data frame, including the destination address, source address, and Ethernet type. </p>
</td>
</tr>
<tr id="row1223795704165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722379754165628"><a name="p722379754165628"></a><a name="p722379754165628"></a><a href="IpHeader.md">IpHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174154182165628"><a name="p1174154182165628"></a><a name="p1174154182165628"></a>Defines the IP header information of a data frame, including the version number, service type, and total length. </p>
</td>
</tr>
<tr id="row1558355787165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2106020369165628"><a name="p2106020369165628"></a><a name="p2106020369165628"></a><a href="UdpHeader.md">UdpHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6052584165628"><a name="p6052584165628"></a><a name="p6052584165628"></a>Defines the UDP header information of a data frame, including the source port number and destination port number. </p>
</td>
</tr>
<tr id="row1323766784165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257948869165628"><a name="p257948869165628"></a><a name="p257948869165628"></a><a href="TcpHeader.md">TcpHeader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1567957747165628"><a name="p1567957747165628"></a><a name="p1567957747165628"></a>Defines the TCP header information of a data frame, including the source port number and destination port number. </p>
</td>
</tr>
<tr id="row556112936165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437440930165628"><a name="p437440930165628"></a><a name="p437440930165628"></a><a href="IpV4Addr.md">IpV4Addr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603267873165628"><a name="p603267873165628"></a><a name="p603267873165628"></a>Defines an IPv4 address. </p>
</td>
</tr>
<tr id="row1725087025165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1879822858165628"><a name="p1879822858165628"></a><a name="p1879822858165628"></a><a href="NetDevNotify.md">NetDevNotify</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1010728800165628"><a name="p1010728800165628"></a><a name="p1010728800165628"></a>Defines a network device notification, including an IP address and the notification type. </p>
</td>
</tr>
<tr id="row256310405165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153865507165628"><a name="p153865507165628"></a><a name="p153865507165628"></a><a href="IfType.md">IfType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553876025165628"><a name="p1553876025165628"></a><a name="p1553876025165628"></a>Defines the network port type, for example, the WLAN network port. </p>
</td>
</tr>
<tr id="row925101782165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291414470165628"><a name="p1291414470165628"></a><a name="p1291414470165628"></a><a href="IfReq.md">IfReq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2038864156165628"><a name="p2038864156165628"></a><a name="p2038864156165628"></a>Defines ioctrl data. </p>
</td>
</tr>
<tr id="row957425652165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967552929165628"><a name="p967552929165628"></a><a name="p967552929165628"></a><a href="NetDevice.md">NetDevice</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66204835165628"><a name="p66204835165628"></a><a name="p66204835165628"></a>Defines a network device, including the network interface category and name, and network port type. </p>
</td>
</tr>
<tr id="row1174754151165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833556265165628"><a name="p833556265165628"></a><a name="p833556265165628"></a><a href="NetDeviceInterFace.md">NetDeviceInterFace</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250593017165628"><a name="p250593017165628"></a><a name="p250593017165628"></a>Defines interfaces that need to be implemented externally by network devices, including initializing, opening, and closing a network device. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2063966317165628"></a>
<table><thead align="left"><tr id="row940240940165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1000739447165628"><a name="p1000739447165628"></a><a name="p1000739447165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p412477976165628"><a name="p412477976165628"></a><a name="p412477976165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1548702273165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602470532165628"><a name="p602470532165628"></a><a name="p602470532165628"></a><a href="WLAN.md#gae01dbae885bc8abecb82bd865515c081">MAC_ADDR_SIZE</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p102211299165628"><a name="p102211299165628"></a><a name="p102211299165628"></a>Indicates a 6-byte MAC address. </p>
</td>
</tr>
<tr id="row1663526026165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1023218034165628"><a name="p1023218034165628"></a><a name="p1023218034165628"></a><a href="WLAN.md#gad9c939a90358c2cb6b788af7b84821a1">NET_DEVICE_IFF_RUNNING</a>   IFF_RUNNING</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031383056165628"><a name="p2031383056165628"></a><a name="p2031383056165628"></a>Indicates that the network port is working. </p>
</td>
</tr>
<tr id="row1744231119165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p483823106165628"><a name="p483823106165628"></a><a name="p483823106165628"></a><a href="WLAN.md#ga74e41a940b9c245f2bc8eaba01d4cee2">ETHER_TYPE_RARP</a>   0x8035</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2109903932165628"><a name="p2109903932165628"></a><a name="p2109903932165628"></a>Indicates Reverse Address Resolution Protocol (RARP). </p>
</td>
</tr>
<tr id="row1073738713165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1027689240165628"><a name="p1027689240165628"></a><a name="p1027689240165628"></a><a href="WLAN.md#ga3bc75b7ed75e7da0abf818f0f1a769d3">ETHER_TYPE_PAE</a>   0x888e</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621268913165628"><a name="p1621268913165628"></a><a name="p1621268913165628"></a>Indicates Port Access Entity (PAE). </p>
</td>
</tr>
<tr id="row1898868093165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888141039165628"><a name="p888141039165628"></a><a name="p888141039165628"></a><a href="WLAN.md#ga61a8e2c9705e0c7000235c60639f3f97">ETHER_TYPE_IP</a>   0x0800</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000012528165628"><a name="p2000012528165628"></a><a name="p2000012528165628"></a>Indicates Internet Protocol (IP). </p>
</td>
</tr>
<tr id="row9113006165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847902086165628"><a name="p847902086165628"></a><a name="p847902086165628"></a><a href="WLAN.md#ga4759f448b5669a1f33ff7d6912a1b131">ETHER_TYPE_AARP</a>   0x80f3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928696257165628"><a name="p1928696257165628"></a><a name="p1928696257165628"></a>Indicates AppleTalk Address Resolution Protocol (AARP). </p>
</td>
</tr>
<tr id="row2120419037165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1783822313165628"><a name="p1783822313165628"></a><a name="p1783822313165628"></a><a href="WLAN.md#gaa0b348d7d0f58adb49e152c79b93b519">ETHER_TYPE_IPX</a>   0x8137</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1438599590165628"><a name="p1438599590165628"></a><a name="p1438599590165628"></a>Indicates Internetwork Packet Exchange (IPX). </p>
</td>
</tr>
<tr id="row1303106456165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p504542603165628"><a name="p504542603165628"></a><a name="p504542603165628"></a><a href="WLAN.md#ga3f5d778e8eb1a7ad731921a460e6c1dd">ETHER_TYPE_ARP</a>   0x0806</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p240699984165628"><a name="p240699984165628"></a><a name="p240699984165628"></a>Indicates Address Resolution Protocol (ARP). </p>
</td>
</tr>
<tr id="row1686506992165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160082661165628"><a name="p160082661165628"></a><a name="p160082661165628"></a><a href="WLAN.md#gadd8fcb263b0d4f3e9c09aafe4c6b64e0">ETHER_TYPE_IPV6</a>   0x86dd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1843624190165628"><a name="p1843624190165628"></a><a name="p1843624190165628"></a>Indicates Internet Protocol version 6 (IPv6). </p>
</td>
</tr>
<tr id="row735553503165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p264589411165628"><a name="p264589411165628"></a><a name="p264589411165628"></a><a href="WLAN.md#ga0418380e708e716910958ed2aab3921d">ETHER_TYPE_TDLS</a>   0x890d</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p968206442165628"><a name="p968206442165628"></a><a name="p968206442165628"></a>Indicates Tunneled Direct Link Setup (TDLS). </p>
</td>
</tr>
<tr id="row970924374165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p676345771165628"><a name="p676345771165628"></a><a name="p676345771165628"></a><a href="WLAN.md#gaaaa516211cec2b61e3717c5fec36952f">ETHER_TYPE_VLAN</a>   0x8100</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p988584026165628"><a name="p988584026165628"></a><a name="p988584026165628"></a>Indicates Virtual Local Area Network (VLAN). </p>
</td>
</tr>
<tr id="row1200410233165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093650273165628"><a name="p1093650273165628"></a><a name="p1093650273165628"></a><a href="WLAN.md#ga89fb6635bc0c9eab11de63ec141938a6">ETHER_TYPE_WAI</a>   0x88b4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p598900344165628"><a name="p598900344165628"></a><a name="p598900344165628"></a>Indicates WLAN Authentication and Privacy Infrastructure (WAPI). </p>
</td>
</tr>
<tr id="row201502017165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658596151165628"><a name="p658596151165628"></a><a name="p658596151165628"></a><a href="WLAN.md#ga7da55985d58df9fac85217e1195d4b7c">ETHER_LLTD_TYPE</a>   0x88D9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198974129165628"><a name="p1198974129165628"></a><a name="p1198974129165628"></a>Indicates Link Layer Topology Discovery (LLTD). </p>
</td>
</tr>
<tr id="row1326616958165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1577707894165628"><a name="p1577707894165628"></a><a name="p1577707894165628"></a><a href="WLAN.md#ga0fb3b00b4300fcbd562e07d5f91aaca0">ETHER_ONE_X_TYPE</a>   0x888E</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168192389165628"><a name="p1168192389165628"></a><a name="p1168192389165628"></a>Indicates 802.1x network port authentication. </p>
</td>
</tr>
<tr id="row1976439359165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1619654551165628"><a name="p1619654551165628"></a><a name="p1619654551165628"></a><a href="WLAN.md#gaefd300f6277931e053c899367ad96536">ETHER_TUNNEL_TYPE</a>   0x88bd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525977215165628"><a name="p1525977215165628"></a><a name="p1525977215165628"></a>Indicates a tunnel protocol. </p>
</td>
</tr>
<tr id="row84337714165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1261941838165628"><a name="p1261941838165628"></a><a name="p1261941838165628"></a><a href="WLAN.md#ga70914271e18c471460d1d00cec8af522">ETHER_TYPE_PPP_DISC</a>   0x8863</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p952629898165628"><a name="p952629898165628"></a><a name="p952629898165628"></a>Indicates the point-to-point discovery type. </p>
</td>
</tr>
<tr id="row1947089327165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p809655890165628"><a name="p809655890165628"></a><a name="p809655890165628"></a><a href="WLAN.md#gaf4b193dda19de66eba7a99b64b3a0c6c">ETHER_TYPE_PPP_SES</a>   0x8864</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328949792165628"><a name="p328949792165628"></a><a name="p328949792165628"></a>Indicates the point-to-point session discovery type. </p>
</td>
</tr>
<tr id="row1143392732165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p64498357165628"><a name="p64498357165628"></a><a name="p64498357165628"></a><a href="WLAN.md#ga6fca23e8bd12854706021a45fe3cd352">ETHER_TYPE_6LO</a>   0xa0ed</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360321575165628"><a name="p360321575165628"></a><a name="p360321575165628"></a>Indicates IPv6 over Low Power Wireless Personal Area Networks (6LoWPANs). </p>
</td>
</tr>
<tr id="row1370896432165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p739337231165628"><a name="p739337231165628"></a><a name="p739337231165628"></a><a href="WLAN.md#ga96b31b1ec02746766191916559cec530">TCP_PROTOCAL</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652966440165628"><a name="p1652966440165628"></a><a name="p1652966440165628"></a>Indicates the Transmission Control Protocol (TCP). </p>
</td>
</tr>
<tr id="row567583374165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563324500165628"><a name="p563324500165628"></a><a name="p563324500165628"></a><a href="WLAN.md#ga06cdba6ef1f4bc477016c6bbae7ce444">UDP_PROTOCAL</a>   17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p295444594165628"><a name="p295444594165628"></a><a name="p295444594165628"></a>Indicates the User Datagram Protocol (UDP). </p>
</td>
</tr>
<tr id="row950241467165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041749244165628"><a name="p1041749244165628"></a><a name="p1041749244165628"></a><a href="WLAN.md#gab7ea98963ef9a6aecac843b0ea6bbcee">IP_PRI_SHIFT</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p414779016165628"><a name="p414779016165628"></a><a name="p414779016165628"></a>Indicates the shift in the priority for an IP address. </p>
</td>
</tr>
<tr id="row554031695165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p594809005165628"><a name="p594809005165628"></a><a name="p594809005165628"></a><a href="WLAN.md#ga2db7b9e1310a372d11d568e34958e158">DHCP_UDP_SRC_PORT</a>   68</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1996568027165628"><a name="p1996568027165628"></a><a name="p1996568027165628"></a>Indicates the source port number of DHCP. </p>
</td>
</tr>
<tr id="row762490939165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p703409253165628"><a name="p703409253165628"></a><a name="p703409253165628"></a><a href="WLAN.md#gad92d590d45b6f76db61dd87fed7fa770">DHCP_UDP_DES_PORT</a>   67</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1607544562165628"><a name="p1607544562165628"></a><a name="p1607544562165628"></a>Indicates the destination port number of DHCP. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table2003886061165628"></a>
<table><thead align="left"><tr id="row2116746835165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1637403168165628"><a name="p1637403168165628"></a><a name="p1637403168165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1639150342165628"><a name="p1639150342165628"></a><a name="p1639150342165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1657646130165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p898288731165628"><a name="p898288731165628"></a><a name="p898288731165628"></a><a href="WLAN.md#gac26e4b0cda623f27420f9ce77befbb1f">NetDevice</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345502145165628"><a name="p1345502145165628"></a><a name="p1345502145165628"></a>typedef struct <a href="NetDevice.md">NetDevice</a> </p>
<p id="p1098533114165628"><a name="p1098533114165628"></a><a name="p1098533114165628"></a>Defines a network device, including the network interface category and name, and network port type. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table666457348165628"></a>
<table><thead align="left"><tr id="row1686366095165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1157485874165628"><a name="p1157485874165628"></a><a name="p1157485874165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2113576883165628"><a name="p2113576883165628"></a><a name="p2113576883165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row233119012165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1471667847165628"><a name="p1471667847165628"></a><a name="p1471667847165628"></a><a href="WLAN.md#ga530241881cd17e03f8ae254ef1d9755e">NetIfCategory</a> { <a href="WLAN.md#gga530241881cd17e03f8ae254ef1d9755eaab9c78d744764e8f66591ee4a8d7b3cb">LITE_OS</a>, <a href="WLAN.md#gga530241881cd17e03f8ae254ef1d9755eafdfffeab76fab0306aa033c650ae0cfa">RICH_OS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p554174059165628"><a name="p554174059165628"></a><a name="p554174059165628"></a>Enumerates network interface categories, including lightweight OS and rich OS. </p>
</td>
</tr>
<tr id="row301385525165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518600561165628"><a name="p518600561165628"></a><a name="p518600561165628"></a><a href="WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf">NetIfStatus</a> { <a href="WLAN.md#gga0fb482694e5eac3f48c75de1749c8bafaeda2ad3830d5a42070617fd0211baf95">NETIF_DOWN</a>, <a href="WLAN.md#gga0fb482694e5eac3f48c75de1749c8bafa64a69f6624102c11bd658c09daf0f865">NETIF_UP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p58761652165628"><a name="p58761652165628"></a><a name="p58761652165628"></a>Enumerates network interface states, including online and offline. </p>
</td>
</tr>
<tr id="row19213295165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1153468010165628"><a name="p1153468010165628"></a><a name="p1153468010165628"></a><a href="WLAN.md#ga7b1187d116fb065d7927ad9f77edd842">NetIfLinkStatus</a> { <a href="WLAN.md#gga7b1187d116fb065d7927ad9f77edd842a8586d0e791ca4f7026853d85740650b5">NETIF_LINK_DOWN</a>, <a href="WLAN.md#gga7b1187d116fb065d7927ad9f77edd842ac3108dbea78b5f0f928e6e5e4ea045f2">NETIF_LINK_UP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639911257165628"><a name="p1639911257165628"></a><a name="p1639911257165628"></a>Enumerates network link layer states, including online and offline. </p>
</td>
</tr>
<tr id="row1669381114165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2014377119165628"><a name="p2014377119165628"></a><a name="p2014377119165628"></a><a href="WLAN.md#gad3175955d2e6ef3c4f52da9b509d5b4a">NetLinkType</a> { <a href="WLAN.md#ggad3175955d2e6ef3c4f52da9b509d5b4aa2d49c28127ce1d558ad5ea2f92e89fd7">ETHERNET_LINK</a> = 1, <a href="WLAN.md#ggad3175955d2e6ef3c4f52da9b509d5b4aadfed684cd7f64cc1aea5944657866db6">WIFI_LINK</a> = 801 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2081416844165628"><a name="p2081416844165628"></a><a name="p2081416844165628"></a>Enumerates data link types, including Ethernet and WLAN. </p>
</td>
</tr>
<tr id="row1949931382165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1464357522165628"><a name="p1464357522165628"></a><a name="p1464357522165628"></a><a href="WLAN.md#ga9c1d6e7df4468671742cb76f72b67af1">ProcessingResult</a> { <a href="WLAN.md#gga9c1d6e7df4468671742cb76f72b67af1a5ce4c56e88c31420a02d3b7f068e0799">PROCESSING_CONTINUE</a>, <a href="WLAN.md#gga9c1d6e7df4468671742cb76f72b67af1a2fcbb133dcd739ab4a04b00bececd70a">PROCESSING_COMPLETE</a>, <a href="WLAN.md#gga9c1d6e7df4468671742cb76f72b67af1afe177a1b88ea1cdcc0e41181c2c73e83">PROCESSING_ERROR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599078037165628"><a name="p599078037165628"></a><a name="p599078037165628"></a>Enumerates data processing results, including continuing processing, processing completed, and error. </p>
</td>
</tr>
<tr id="row751933307165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011537032165628"><a name="p2011537032165628"></a><a name="p2011537032165628"></a><a href="WLAN.md#ga9fb4e578a15db1b0087d7b3831591ced">NetDevTxResult</a> { <a href="WLAN.md#gga9fb4e578a15db1b0087d7b3831591ceda734cacd083ffc8d233cab8d4deb6b38b">NETDEV_TX_OK</a> = 0x00, <a href="WLAN.md#gga9fb4e578a15db1b0087d7b3831591cedaf0a0ac437358f6af42c3e38795c46d35">NETDEV_TX_BUSY</a> = 0x10, <a href="WLAN.md#gga9fb4e578a15db1b0087d7b3831591ceda7eb70cee5761fe8954f94b660c37eaa8">NETDEV_TX_LOCKED</a> = 0x20 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1489429747165628"><a name="p1489429747165628"></a><a name="p1489429747165628"></a>Enumerates data sending results, including sending succeeded, other data being sent at the link layer, and data link layer being locked. </p>
</td>
</tr>
<tr id="row623563803165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p42890396165628"><a name="p42890396165628"></a><a name="p42890396165628"></a><a href="WLAN.md#gac69954f56fcc99fc8aac68aa157831c7">Protocol80211IfType</a> {   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a6b209b916aabd18f2a950a82e68b6a4c">PROTOCOL_80211_IFTYPE_UNSPECIFIED</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a0926a98ddc2ceec4ba58ebfc01c5fe35">PROTOCOL_80211_IFTYPE_ADHOC</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7acd26f8cefbd658e9ea02feecefd054fb">PROTOCOL_80211_IFTYPE_STATION</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a9e92654b9ab6ed6eb62868f1e0e4ea8f">PROTOCOL_80211_IFTYPE_AP</a>,   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a991ad1a3f8c43b06c4eeb9dc88acdb1e">PROTOCOL_80211_IFTYPE_AP_VLAN</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7aa25631c32cd6c996a7c96ba4f61299e2">PROTOCOL_80211_IFTYPE_WDS</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a3ff1c1358af5a0c50b64e0ef0e96a970">PROTOCOL_80211_IFTYPE_MONITOR</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a382756b8a71015cd536cdbc113c4f483">PROTOCOL_80211_IFTYPE_MESH_POINT</a>,   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7acfd81d6e484c6f7a3b863327af112cfc">PROTOCOL_80211_IFTYPE_P2P_CLIENT</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7abca0ccb5cf4c14af9b6ff0bd9eeb4173">PROTOCOL_80211_IFTYPE_P2P_GO</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7ad63ad4a5a66892e842e4d75cc82b0755">PROTOCOL_80211_IFTYPE_P2P_DEVICE</a>, <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a7f1fa9726ab20597baaa9ebf884b26cd">PROTOCOL_80211_IFTYPE_NUM</a>,   <a href="WLAN.md#ggac69954f56fcc99fc8aac68aa157831c7a37b72ea7c4cd81dd4c427e2d721c9499">PROTOCOL_80211_IFTYPE_MAX</a> = PROTOCOL_80211_IFTYPE_NUM - 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114746431165628"><a name="p114746431165628"></a><a name="p114746431165628"></a>Enumerates 802.11 network port types, including AP, STA, and P2P. </p>
</td>
</tr>
<tr id="row863487330165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542509024165628"><a name="p542509024165628"></a><a name="p542509024165628"></a><a href="WLAN.md#ga9023c5dc1cc43758cbb468d78af41c2d">NetdeviceError</a> { <a href="WLAN.md#gga9023c5dc1cc43758cbb468d78af41c2dafe771f5d0d84d17922f466d3eed83d6b">COMMON_ERROR</a> = 1, <a href="WLAN.md#gga9023c5dc1cc43758cbb468d78af41c2daf5426609de8db5782b340a6bcd7e94d6">ADD_LWIP_ERROR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p995589946165628"><a name="p995589946165628"></a><a name="p995589946165628"></a>Enumerates network device errors, including common errors and errors in adding network devices to LwIP. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1160118314165628"></a>
<table><thead align="left"><tr id="row198634355165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p171504717165628"><a name="p171504717165628"></a><a name="p171504717165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1723109942165628"><a name="p1723109942165628"></a><a name="p1723109942165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row418476542165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828936855165628"><a name="p1828936855165628"></a><a name="p1828936855165628"></a><a href="WLAN.md#ga8d2bff6673ec21ba317d596a84df7ca8">NetDeviceInit</a> (const char *ifName, uint32_t len, <a href="WLAN.md#ga530241881cd17e03f8ae254ef1d9755e">NetIfCategory</a> ifCategory)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117758978165628"><a name="p2117758978165628"></a><a name="p2117758978165628"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
<p id="p159740060165628"><a name="p159740060165628"></a><a name="p159740060165628"></a>Initializes a network device to obtain its instance. </p>
</td>
</tr>
<tr id="row737269019165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1796587261165628"><a name="p1796587261165628"></a><a name="p1796587261165628"></a><a href="WLAN.md#gaf4a2fa8b1a35d4cadd8247ee8fed60a4">NetDeviceDeInit</a> (struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767147757165628"><a name="p1767147757165628"></a><a name="p1767147757165628"></a>int32_t </p>
<p id="p1419062978165628"><a name="p1419062978165628"></a><a name="p1419062978165628"></a>Deletes a network device. </p>
</td>
</tr>
<tr id="row1932494505165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979581797165628"><a name="p1979581797165628"></a><a name="p1979581797165628"></a><a href="WLAN.md#ga64be10f09b180d3098e9550163131dbd">NetDeviceAdd</a> (struct <a href="NetDevice.md">NetDevice</a> *netDevice, <a href="WLAN.md#gac69954f56fcc99fc8aac68aa157831c7">Protocol80211IfType</a> ifType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3320451165628"><a name="p3320451165628"></a><a name="p3320451165628"></a>int32_t </p>
<p id="p693470733165628"><a name="p693470733165628"></a><a name="p693470733165628"></a>Adds a network device to a protocol stack. </p>
</td>
</tr>
<tr id="row538274700165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p661242829165628"><a name="p661242829165628"></a><a name="p661242829165628"></a><a href="WLAN.md#ga6c93cb701cf2523eaa7bbeabd4acf3ab">NetDeviceDelete</a> (struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727125864165628"><a name="p727125864165628"></a><a name="p727125864165628"></a>int32_t </p>
<p id="p520434421165628"><a name="p520434421165628"></a><a name="p520434421165628"></a>Deletes a network device from a protocol stack. </p>
</td>
</tr>
<tr id="row1316665241165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725608349165628"><a name="p1725608349165628"></a><a name="p1725608349165628"></a><a href="WLAN.md#ga6d90d1bf783a83db1d838d03f8c1d93a">NetDeviceGetInstByName</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p716376084165628"><a name="p716376084165628"></a><a name="p716376084165628"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
<p id="p1647479586165628"><a name="p1647479586165628"></a><a name="p1647479586165628"></a>Obtains the initialized network device instance by a specified device name. </p>
</td>
</tr>
<tr id="row1290700250165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1616632920165628"><a name="p1616632920165628"></a><a name="p1616632920165628"></a><a href="WLAN.md#ga20fcbcc248e99917c17223a97fe5d70e">NetDeviceIsAnyInstRunning</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2094251785165628"><a name="p2094251785165628"></a><a name="p2094251785165628"></a>bool </p>
<p id="p1562416917165628"><a name="p1562416917165628"></a><a name="p1562416917165628"></a>Checks whether there are working devices among the added network devices. </p>
</td>
</tr>
<tr id="row1268215530165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2057025202165628"><a name="p2057025202165628"></a><a name="p2057025202165628"></a><a href="WLAN.md#ga05b08c890c69f3e633447f14e16d30f7">NetDeviceIsInstRunning</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9784864165628"><a name="p9784864165628"></a><a name="p9784864165628"></a>bool </p>
<p id="p1985831648165628"><a name="p1985831648165628"></a><a name="p1985831648165628"></a>Checks whether a specified network device is working. </p>
</td>
</tr>
<tr id="row688215574165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447574456165628"><a name="p1447574456165628"></a><a name="p1447574456165628"></a><a href="WLAN.md#ga8c8d400a6b4eb64445a2b4ea12102c9a">NetDevGetRegisterCount</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1489755104165628"><a name="p1489755104165628"></a><a name="p1489755104165628"></a>uint32_t </p>
<p id="p453448193165628"><a name="p453448193165628"></a><a name="p453448193165628"></a>Obtains the number of added network devices. </p>
</td>
</tr>
<tr id="row507185952165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489651757165628"><a name="p489651757165628"></a><a name="p489651757165628"></a><a href="WLAN.md#ga5d2a4fd370e2115b4c1fc8ecc46d64ab">NetDeviceGetCap</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118848633165628"><a name="p118848633165628"></a><a name="p118848633165628"></a>uint32_t </p>
<p id="p164513159165628"><a name="p164513159165628"></a><a name="p164513159165628"></a>Obtains the maximum number of network devices that can be registered with this system at the same time. </p>
</td>
</tr>
<tr id="row1669707689165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p537461294165628"><a name="p537461294165628"></a><a name="p537461294165628"></a><a href="WLAN.md#gab45261476e710c30335975726af3a834">NetDeviceGetInstByIndex</a> (uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048039151165628"><a name="p2048039151165628"></a><a name="p2048039151165628"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
<p id="p1110925094165628"><a name="p1110925094165628"></a><a name="p1110925094165628"></a>Obtains a network device instance based on the index number. </p>
</td>
</tr>
<tr id="row1746899076165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246198407165628"><a name="p1246198407165628"></a><a name="p1246198407165628"></a><a href="WLAN.md#gadd5c08aa8e65a12db062b1b88d53cece">NetIfSetAddr</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, const <a href="IpV4Addr.md">IpV4Addr</a> *ipAddr, const <a href="IpV4Addr.md">IpV4Addr</a> *netMask, const <a href="IpV4Addr.md">IpV4Addr</a> *gw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424552552165628"><a name="p1424552552165628"></a><a name="p1424552552165628"></a>int32_t </p>
<p id="p677041759165628"><a name="p677041759165628"></a><a name="p677041759165628"></a>Sets an IP address, mask, and gateway. </p>
</td>
</tr>
<tr id="row1892174066165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1170767292165628"><a name="p1170767292165628"></a><a name="p1170767292165628"></a><a href="WLAN.md#gaa14fc68a382284491a272992d5c477cb">NetIfSetStatus</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, <a href="WLAN.md#ga0fb482694e5eac3f48c75de1749c8baf">NetIfStatus</a> status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98988559165628"><a name="p98988559165628"></a><a name="p98988559165628"></a>int32_t </p>
<p id="p1141531154165628"><a name="p1141531154165628"></a><a name="p1141531154165628"></a>Notifies the network layer of the network port state. </p>
</td>
</tr>
<tr id="row1207528767165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049076142165628"><a name="p2049076142165628"></a><a name="p2049076142165628"></a><a href="WLAN.md#gaee9c68875ef541ed915045ab7a047ee8">NetIfSetLinkStatus</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, <a href="WLAN.md#ga7b1187d116fb065d7927ad9f77edd842">NetIfLinkStatus</a> status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878864533165628"><a name="p1878864533165628"></a><a name="p1878864533165628"></a>int32_t </p>
<p id="p31907480165628"><a name="p31907480165628"></a><a name="p31907480165628"></a>Notifies the network layer of the data link layer status. </p>
</td>
</tr>
<tr id="row1073498428165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p899274007165628"><a name="p899274007165628"></a><a name="p899274007165628"></a><a href="WLAN.md#ga44006f6e066aff9f6a3310559e781582">NetIfRx</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, struct <a href="NetBuf.md">NetBuf</a> *buff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992637962165628"><a name="p1992637962165628"></a><a name="p1992637962165628"></a>int32_t </p>
<p id="p150039082165628"><a name="p150039082165628"></a><a name="p150039082165628"></a>Transfers the input data packets from the network side to a protocol stack. </p>
</td>
</tr>
<tr id="row1851950844165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2027922382165628"><a name="p2027922382165628"></a><a name="p2027922382165628"></a><a href="WLAN.md#gad252107cdd20e9d3d0ab33fbfc2161e9">NetIfRxNi</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, struct <a href="NetBuf.md">NetBuf</a> *buff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176075098165628"><a name="p176075098165628"></a><a name="p176075098165628"></a>int32_t </p>
<p id="p1785656045165628"><a name="p1785656045165628"></a><a name="p1785656045165628"></a>Transfers data packets from the network side to a protocol stack in an interrupt processing thread. </p>
</td>
</tr>
<tr id="row902991561165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975887685165628"><a name="p1975887685165628"></a><a name="p1975887685165628"></a><a href="WLAN.md#gae97c7abcf556be34798622a85162c35e">NetIfDhcpsStart</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice, char *ip, u16_t ipNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20800575165628"><a name="p20800575165628"></a><a name="p20800575165628"></a>int32_t </p>
<p id="p727027247165628"><a name="p727027247165628"></a><a name="p727027247165628"></a>Starts the DHCP server. </p>
</td>
</tr>
<tr id="row1076672137165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p106427271165628"><a name="p106427271165628"></a><a name="p106427271165628"></a><a href="WLAN.md#gaadfeb819b4cb623870823fa5c9793b4c">NetIfDhcpsStop</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643931392165628"><a name="p643931392165628"></a><a name="p643931392165628"></a>int32_t </p>
<p id="p939471316165628"><a name="p939471316165628"></a><a name="p939471316165628"></a>Stops the DHCP server. </p>
</td>
</tr>
<tr id="row565023327165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865700402165628"><a name="p1865700402165628"></a><a name="p1865700402165628"></a><a href="WLAN.md#ga5fdd93c820b994adf1b76eb8d50e4f88">NetIfDhcpStart</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011504097165628"><a name="p1011504097165628"></a><a name="p1011504097165628"></a>int32_t </p>
<p id="p364610050165628"><a name="p364610050165628"></a><a name="p364610050165628"></a>Starts the DHCP client of a specified network device. </p>
</td>
</tr>
<tr id="row443518332165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284617748165628"><a name="p284617748165628"></a><a name="p284617748165628"></a><a href="WLAN.md#ga22f97a3fc45841e874ab2072c14e0f3e">NetIfDhcpStop</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652069366165628"><a name="p652069366165628"></a><a name="p652069366165628"></a>int32_t </p>
<p id="p247232032165628"><a name="p247232032165628"></a><a name="p247232032165628"></a>Stops the DHCP client of a specified network device. </p>
</td>
</tr>
<tr id="row1359908447165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200379984165628"><a name="p1200379984165628"></a><a name="p1200379984165628"></a><a href="WLAN.md#ga389ec95a3c8170c4ca74487f8bc1d8ac">NetIfDhcpIsBound</a> (const struct <a href="NetDevice.md">NetDevice</a> *netDevice)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p576669294165628"><a name="p576669294165628"></a><a name="p576669294165628"></a>int32_t </p>
<p id="p32805888165628"><a name="p32805888165628"></a><a name="p32805888165628"></a>Obtains the DHCP negotiation status of a specified network device. </p>
</td>
</tr>
</tbody>
</table>

