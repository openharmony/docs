# wifi\_mac80211\_ops.h<a name="EN-US_TOPIC_0000001054879520"></a>

-   [Overview](#section1177149052165630)
-   [Summary](#section448189843165630)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1177149052165630"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Declares Media Access Control \(MAC\) APIs and functions related to control flows. 

This file declares APIs for scanning, connection, disconnection, and mode conversion, as well as data structures of the parameters of these APIs.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section448189843165630"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1484765292165630"></a>
<table><thead align="left"><tr id="row962298613165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p545362507165630"><a name="p545362507165630"></a><a name="p545362507165630"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p154823546165630"><a name="p154823546165630"></a><a name="p154823546165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row190023011165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509624954165630"><a name="p1509624954165630"></a><a name="p1509624954165630"></a><a href="keyparams.md">KeyParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1050904578165630"><a name="p1050904578165630"></a><a name="p1050904578165630"></a>Describes a key. </p>
</td>
</tr>
<tr id="row1446028821165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p494433070165630"><a name="p494433070165630"></a><a name="p494433070165630"></a><a href="ieee80211channel.md">Ieee80211Channel</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787650691165630"><a name="p787650691165630"></a><a name="p787650691165630"></a>Describes a communication channel. </p>
</td>
</tr>
<tr id="row1699650392165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152453214165630"><a name="p1152453214165630"></a><a name="p1152453214165630"></a><a href="ieee80211rate.md">Ieee80211Rate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1219082546165630"><a name="p1219082546165630"></a><a name="p1219082546165630"></a>Describes the IEEE 802.11 rate. </p>
</td>
</tr>
<tr id="row2003645560165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1128230211165630"><a name="p1128230211165630"></a><a name="p1128230211165630"></a><a href="ieee80211mcsinfo.md">Ieee80211McsInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1558812359165630"><a name="p1558812359165630"></a><a name="p1558812359165630"></a>Describes IEEE 802.11 Modulation and Coding Scheme (MCS) information. </p>
</td>
</tr>
<tr id="row1126121709165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315022437165630"><a name="p315022437165630"></a><a name="p315022437165630"></a><a href="ieee80211stahtcap.md">Ieee80211StaHtCap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882024506165630"><a name="p1882024506165630"></a><a name="p1882024506165630"></a>Describes the IEEE 802.11 high-throughput (HT) capability. </p>
</td>
</tr>
<tr id="row1083987682165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1785721407165630"><a name="p1785721407165630"></a><a name="p1785721407165630"></a><a href="ieee80211supportedband.md">Ieee80211SupportedBand</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p953046125165630"><a name="p953046125165630"></a><a name="p953046125165630"></a>Describes IEEE 802.11 band information. </p>
</td>
</tr>
<tr id="row1367114382165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p458333287165630"><a name="p458333287165630"></a><a name="p458333287165630"></a><a href="wiphy.md">Wiphy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1895282376165630"><a name="p1895282376165630"></a><a name="p1895282376165630"></a>Describes a wiphy device. </p>
</td>
</tr>
<tr id="row689295633165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383674786165630"><a name="p383674786165630"></a><a name="p383674786165630"></a><a href="wifissid.md">WifiSsid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942372985165630"><a name="p942372985165630"></a><a name="p942372985165630"></a>Describes an SSID. </p>
</td>
</tr>
<tr id="row1775613079165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p997867058165630"><a name="p997867058165630"></a><a name="p997867058165630"></a><a href="channeldef.md">ChannelDef</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883551561165630"><a name="p883551561165630"></a><a name="p883551561165630"></a>Describes a communication channel. </p>
</td>
</tr>
<tr id="row1540815018165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p942075632165630"><a name="p942075632165630"></a><a name="p942075632165630"></a><a href="wirelessdev.md">WirelessDev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680317824165630"><a name="p1680317824165630"></a><a name="p1680317824165630"></a>Describes a wireless device. </p>
</td>
</tr>
<tr id="row1965131233165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186049278165630"><a name="p186049278165630"></a><a name="p186049278165630"></a><a href="wifiscanrequest.md">WifiScanRequest</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018953319165630"><a name="p2018953319165630"></a><a name="p2018953319165630"></a>Describes scan request parameters. </p>
</td>
</tr>
<tr id="row1027344371165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1762587100165630"><a name="p1762587100165630"></a><a name="p1762587100165630"></a><a href="cryptosettings.md">CryptoSettings</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1782528545165630"><a name="p1782528545165630"></a><a name="p1782528545165630"></a>Describes cryptography settings. </p>
</td>
</tr>
<tr id="row1124990331165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696500683165630"><a name="p696500683165630"></a><a name="p696500683165630"></a><a href="macaddress.md">MacAddress</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664084522165630"><a name="p1664084522165630"></a><a name="p1664084522165630"></a>Describes the device MAC address. </p>
</td>
</tr>
<tr id="row431463626165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124173821165630"><a name="p2124173821165630"></a><a name="p2124173821165630"></a><a href="wificonnectparams.md">WifiConnectParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100878606165630"><a name="p100878606165630"></a><a name="p100878606165630"></a>Describes parameters for a connection request. </p>
</td>
</tr>
<tr id="row121082035165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712413081165630"><a name="p1712413081165630"></a><a name="p1712413081165630"></a><a href="vifparams.md">VifParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380642009165630"><a name="p380642009165630"></a><a name="p380642009165630"></a>Describes virtual API parameters. </p>
</td>
</tr>
<tr id="row1620096139165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p106795775165630"><a name="p106795775165630"></a><a name="p106795775165630"></a><a href="stationdelparameters.md">StationDelParameters</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380621845165630"><a name="p1380621845165630"></a><a name="p1380621845165630"></a>Describes parameters for canceling a connection. </p>
</td>
</tr>
<tr id="row966328695165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1458239393165630"><a name="p1458239393165630"></a><a name="p1458239393165630"></a><a href="macconfigparam.md">MacConfigParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1781906656165630"><a name="p1781906656165630"></a><a name="p1781906656165630"></a>Describes MAC configuration parameters. </p>
</td>
</tr>
<tr id="row35193347165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919750271165630"><a name="p919750271165630"></a><a name="p919750271165630"></a><a href="mac80211disconnectparam.md">Mac80211DisconnectParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1884681177165630"><a name="p1884681177165630"></a><a name="p1884681177165630"></a>Describes disconnection parameters. </p>
</td>
</tr>
<tr id="row571097434165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p745273834165630"><a name="p745273834165630"></a><a name="p745273834165630"></a><a href="mac80211ssids.md">Mac80211Ssids</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2023093076165630"><a name="p2023093076165630"></a><a name="p2023093076165630"></a>Describes SSIDs. </p>
</td>
</tr>
<tr id="row217043384165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200763091165630"><a name="p1200763091165630"></a><a name="p1200763091165630"></a><a href="mac80211beaconparam.md">Mac80211beaconParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p984048116165630"><a name="p984048116165630"></a><a name="p984048116165630"></a>Describes beacon parameters. </p>
</td>
</tr>
<tr id="row1258686563165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p134792281165630"><a name="p134792281165630"></a><a name="p134792281165630"></a><a href="wifimac80211ops.md">WifiMac80211Ops</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686237399165630"><a name="p1686237399165630"></a><a name="p1686237399165630"></a>Describes MAC-layer control APIs that need to be implemented by the driver. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table2017526555165630"></a>
<table><thead align="left"><tr id="row134648236165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p357898927165630"><a name="p357898927165630"></a><a name="p357898927165630"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p715826465165630"><a name="p715826465165630"></a><a name="p715826465165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row273756601165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107433721165630"><a name="p1107433721165630"></a><a name="p1107433721165630"></a><a href="wlan.md#ga3e8945c521d2392cb775494570c560b3">WifiConnectParams</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1483546735165630"><a name="p1483546735165630"></a><a name="p1483546735165630"></a>typedef struct <a href="wificonnectparams.md">WifiConnectParams</a> </p>
<p id="p1112294435165630"><a name="p1112294435165630"></a><a name="p1112294435165630"></a>Describes parameters for a connection request. </p>
</td>
</tr>
<tr id="row348435060165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1924662747165630"><a name="p1924662747165630"></a><a name="p1924662747165630"></a><a href="wlan.md#ga85f7d8a3795887f090e0a6439b1df6e1">Mac80211SetMacParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p372095986165630"><a name="p372095986165630"></a><a name="p372095986165630"></a>typedef struct <a href="macconfigparam.md">MacConfigParam</a> </p>
<p id="p944698906165630"><a name="p944698906165630"></a><a name="p944698906165630"></a>Describes MAC configuration parameters. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1263412076165630"></a>
<table><thead align="left"><tr id="row1963580486165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p698903926165630"><a name="p698903926165630"></a><a name="p698903926165630"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p921396382165630"><a name="p921396382165630"></a><a name="p921396382165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1743519680165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1168355498165630"><a name="p1168355498165630"></a><a name="p1168355498165630"></a><a href="wlan.md#ga75cba3dc6ab4c5dc5653b037433b3abf">MacSetType</a> { <a href="wlan.md#gga75cba3dc6ab4c5dc5653b037433b3abfa52532b66ba237505f04a57b382f67cb1">MAC_BEACON_SET</a> = 0, <a href="wlan.md#gga75cba3dc6ab4c5dc5653b037433b3abfa8bb6332eadf8a54cdcf7d02b6040e7f3">MAC_BEACON_ADD</a> = 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p248034440165630"><a name="p248034440165630"></a><a name="p248034440165630"></a>Enumerates setting types of MAC addresses. </p>
</td>
</tr>
<tr id="row2114951442165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p650395492165630"><a name="p650395492165630"></a><a name="p650395492165630"></a><a href="wlan.md#ga9882f415202cf9acb0f4cdfbc456a88d">Ieee80211Band</a> { <a href="wlan.md#gga9882f415202cf9acb0f4cdfbc456a88daf339f82c036557f42f668a358aa96da3">IEEE80211_BAND_2GHZ</a>, <a href="wlan.md#gga9882f415202cf9acb0f4cdfbc456a88da0871c8866251ec4e668e956bb0427cfa">IEEE80211_BAND_5GHZ</a>, <a href="wlan.md#gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4">IEEE80211_NUM_BANDS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133527685165630"><a name="p2133527685165630"></a><a name="p2133527685165630"></a>Enumerates frequency bands. </p>
</td>
</tr>
<tr id="row400407463165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335903440165630"><a name="p335903440165630"></a><a name="p335903440165630"></a><a href="wlan.md#ga9d902b330de99c24b2a8c3ba7120af21">WifiChannelType</a> { <a href="wlan.md#gga9d902b330de99c24b2a8c3ba7120af21ae0707e29a1748ee7f33d51acabaf8810">WIFI_CHAN_NO_HT</a>, <a href="wlan.md#gga9d902b330de99c24b2a8c3ba7120af21a255f513fd4efa8bce0c015086e0588ea">WIFI_CHAN_HT20</a>, <a href="wlan.md#gga9d902b330de99c24b2a8c3ba7120af21a1c6dbd2c2f6be59e4fa8312fe6009a98">WIFI_CHAN_HT40MINUS</a>, <a href="wlan.md#gga9d902b330de99c24b2a8c3ba7120af21abdc85daa4bd2fdda2cfb14a975099652">WIFI_CHAN_HT40PLUS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629927012165630"><a name="p629927012165630"></a><a name="p629927012165630"></a>Enumerates channel types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table983003074165630"></a>
<table><thead align="left"><tr id="row926870701165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p376702904165630"><a name="p376702904165630"></a><a name="p376702904165630"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1804009660165630"><a name="p1804009660165630"></a><a name="p1804009660165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1131774756165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p165189034165630"><a name="p165189034165630"></a><a name="p165189034165630"></a><a href="wlan.md#ga6542a735af0fe7496789c3c55380adfa">Mac80211RegisterOps</a> (struct <a href="wifimac80211ops.md">WifiMac80211Ops</a> *ops) __attribute__((weak))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1558438227165630"><a name="p1558438227165630"></a><a name="p1558438227165630"></a>int32_t </p>
<p id="p1178263775165630"><a name="p1178263775165630"></a><a name="p1178263775165630"></a>Registers a <a href="wifimac80211ops.md">WifiMac80211Ops</a> object. </p>
</td>
</tr>
<tr id="row79362894165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1349266054165630"><a name="p1349266054165630"></a><a name="p1349266054165630"></a><a href="wlan.md#gad7c34413d81d55ba090c90404d340c8a">Mac80211GetOps</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p172858700165630"><a name="p172858700165630"></a><a name="p172858700165630"></a>struct <a href="wifimac80211ops.md">WifiMac80211Ops</a> * </p>
<p id="p1715559245165630"><a name="p1715559245165630"></a><a name="p1715559245165630"></a>Obtains the <a href="wifimac80211ops.md">WifiMac80211Ops</a> object that the driver needs to implement. </p>
</td>
</tr>
</tbody>
</table>

