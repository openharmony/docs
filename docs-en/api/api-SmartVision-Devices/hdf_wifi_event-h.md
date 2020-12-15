# hdf\_wifi\_event.h<a name="EN-US_TOPIC_0000001054879502"></a>

-   [Overview](#section379940061165627)
-   [Summary](#section55817024165627)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section379940061165627"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Declares WLAN driver events. 

The functions in this file are used to report events such as scanning results, scanning completion, and station disconnection to the WPA interface.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section55817024165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1217954969165627"></a>
<table><thead align="left"><tr id="row1974238022165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p856110610165627"><a name="p856110610165627"></a><a name="p856110610165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p806253966165627"><a name="p806253966165627"></a><a name="p806253966165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row770742204165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334976714165627"><a name="p1334976714165627"></a><a name="p1334976714165627"></a><a href="rateinfo.md">RateInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388937229165627"><a name="p388937229165627"></a><a name="p388937229165627"></a>Defines the rate information received or sent over WLAN. </p>
</td>
</tr>
<tr id="row521380690165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p381474275165627"><a name="p381474275165627"></a><a name="p381474275165627"></a><a href="stabssparameters.md">StaBssParameters</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690016584165627"><a name="p1690016584165627"></a><a name="p1690016584165627"></a>Defines parameters related to the WLAN module that works in station mode. </p>
</td>
</tr>
<tr id="row1063170438165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362549137165627"><a name="p1362549137165627"></a><a name="p1362549137165627"></a><a href="staflagupdate.md">StaFlagUpdate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1084482472165627"><a name="p1084482472165627"></a><a name="p1084482472165627"></a>Defines the update of the <strong id="b1213519224165627"><a name="b1213519224165627"></a><a name="b1213519224165627"></a>Sta</strong> flag. </p>
</td>
</tr>
<tr id="row541794262165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181914458165627"><a name="p181914458165627"></a><a name="p181914458165627"></a><a href="stationinfo.md">StationInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1277380988165627"><a name="p1277380988165627"></a><a name="p1277380988165627"></a>Defines station information. </p>
</td>
</tr>
<tr id="row1546919205165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616526504165627"><a name="p616526504165627"></a><a name="p616526504165627"></a><a href="auth.md">Auth</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684250363165627"><a name="p1684250363165627"></a><a name="p1684250363165627"></a>Defines authentication information. </p>
</td>
</tr>
<tr id="row399052664165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622428461165627"><a name="p1622428461165627"></a><a name="p1622428461165627"></a><a href="deauth.md">Deauth</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295597933165627"><a name="p1295597933165627"></a><a name="p1295597933165627"></a>Defines deauthentication information. </p>
</td>
</tr>
<tr id="row2030119706165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173210018165627"><a name="p1173210018165627"></a><a name="p1173210018165627"></a><a href="assocreq.md">AssocReq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p431869500165627"><a name="p431869500165627"></a><a name="p431869500165627"></a>Defines station association request. </p>
</td>
</tr>
<tr id="row620272195165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459135892165627"><a name="p1459135892165627"></a><a name="p1459135892165627"></a><a href="assocresp.md">AssocResp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p798535659165627"><a name="p798535659165627"></a><a name="p798535659165627"></a>Defines station association response. </p>
</td>
</tr>
<tr id="row449217626165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p924609852165627"><a name="p924609852165627"></a><a name="p924609852165627"></a><a href="reassocreq.md">ReassocReq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683750226165627"><a name="p683750226165627"></a><a name="p683750226165627"></a>Defines station reassociation request. </p>
</td>
</tr>
<tr id="row1400175855165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146273418165627"><a name="p146273418165627"></a><a name="p146273418165627"></a><a href="reassocresp.md">ReassocResp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456963451165627"><a name="p1456963451165627"></a><a name="p1456963451165627"></a>Defines station reassociation response. </p>
</td>
</tr>
<tr id="row445872862165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p150807040165627"><a name="p150807040165627"></a><a name="p150807040165627"></a><a href="disassoc.md">Disassoc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p915476631165627"><a name="p915476631165627"></a><a name="p915476631165627"></a>Defines station disconnection. </p>
</td>
</tr>
<tr id="row291393946165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377202983165627"><a name="p377202983165627"></a><a name="p377202983165627"></a><a href="beacon.md">Beacon</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2134772180165627"><a name="p2134772180165627"></a><a name="p2134772180165627"></a>Defines the update of the <strong id="b377574136165627"><a name="b377574136165627"></a><a name="b377574136165627"></a>Sta</strong> flag. </p>
</td>
</tr>
<tr id="row857978279165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1950319390165627"><a name="p1950319390165627"></a><a name="p1950319390165627"></a><a href="proberesp.md">ProbeResp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p512665304165627"><a name="p512665304165627"></a><a name="p512665304165627"></a>Defines scanning response. </p>
</td>
</tr>
<tr id="row810021215165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118828127165627"><a name="p1118828127165627"></a><a name="p1118828127165627"></a><a href="ieee80211mgmt.md">Ieee80211Mgmt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1266491753165627"><a name="p1266491753165627"></a><a name="p1266491753165627"></a>Defines management frame information. </p>
</td>
</tr>
<tr id="row1379254584165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1875170059165627"><a name="p1875170059165627"></a><a name="p1875170059165627"></a><a href="scannedbssinfo.md">ScannedBssInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920634856165627"><a name="p1920634856165627"></a><a name="p1920634856165627"></a>Represents the scanned BSS information. </p>
</td>
</tr>
<tr id="row262282792165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750580439165627"><a name="p1750580439165627"></a><a name="p1750580439165627"></a><a href="connetresult.md">ConnetResult</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p270977999165627"><a name="p270977999165627"></a><a name="p270977999165627"></a>Defines association results. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1991107656165627"></a>
<table><thead align="left"><tr id="row1198420991165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p559883801165627"><a name="p559883801165627"></a><a name="p559883801165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1480577421165627"><a name="p1480577421165627"></a><a name="p1480577421165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row534689919165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2077902407165627"><a name="p2077902407165627"></a><a name="p2077902407165627"></a><a href="wlan.md#gaf3e873b51f0cfa077aca9d33ed7a0960">WifiHmacMgmtStatus</a> {   <a href="wlan.md#ggaf3e873b51f0cfa077aca9d33ed7a0960ad9c7e2f362bd6fcadef189fa2a5d7c63">WIFI_HMAC_MGMT_SUCCESS</a> = 0, <a href="wlan.md#ggaf3e873b51f0cfa077aca9d33ed7a0960a539c65a358a20b9731fc66fc60ebcbc2">WIFI_HMAC_MGMT_INVALID</a> = 1, <a href="wlan.md#ggaf3e873b51f0cfa077aca9d33ed7a0960ad1731acef8ddb8c50bcc26ae80fa83a3">WIFI_HMAC_MGMT_TIMEOUT</a> = 2, <a href="wlan.md#ggaf3e873b51f0cfa077aca9d33ed7a0960a05f532edadae3b6afc80b7575dd46961">WIFI_HMAC_MGMT_REFUSED</a> = 3,   <a href="wlan.md#ggaf3e873b51f0cfa077aca9d33ed7a0960a9e241ef81e72de130e1fda573ce2a412">WIFI_HMAC_MGMT_TOMANY_REQ</a> = 4, <a href="wlan.md#ggaf3e873b51f0cfa077aca9d33ed7a0960aa3db4634dc2727e029aef13384bc3940">WIFI_HMAC_MGMT_ALREADY_BSS</a> = 5 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757317031165627"><a name="p1757317031165627"></a><a name="p1757317031165627"></a>Enumerates MLME management statuses, indicating whether a device is successfully associated or fails to be associated. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table384418869165627"></a>
<table><thead align="left"><tr id="row1912391463165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p719664737165627"><a name="p719664737165627"></a><a name="p719664737165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1145480981165627"><a name="p1145480981165627"></a><a name="p1145480981165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1097932219165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770657941165627"><a name="p1770657941165627"></a><a name="p1770657941165627"></a><a href="wlan.md#ga31edc1e9de8835e0e8a9c1e89fad3bd9">HdfWifiEventNewSta</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, const uint8_t *macAddr, uint8_t addrLen, const struct <a href="stationinfo.md">StationInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1378014600165627"><a name="p1378014600165627"></a><a name="p1378014600165627"></a>int32_t </p>
<p id="p710229597165627"><a name="p710229597165627"></a><a name="p710229597165627"></a>Reports a new STA event. </p>
</td>
</tr>
<tr id="row970594022165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775487489165627"><a name="p1775487489165627"></a><a name="p1775487489165627"></a><a href="wlan.md#ga208ef54b2a601f416a472bb1e21fae7e">HdfWifiEventDelSta</a> (struct <a href="netdevice.md">NetDevice</a> *netdev, const uint8_t *macAddr, uint8_t addrLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128977564165627"><a name="p1128977564165627"></a><a name="p1128977564165627"></a>int32_t </p>
<p id="p2102634830165627"><a name="p2102634830165627"></a><a name="p2102634830165627"></a>Reports a station deletion event. </p>
</td>
</tr>
<tr id="row2131600964165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243256130165627"><a name="p1243256130165627"></a><a name="p1243256130165627"></a><a href="wlan.md#ga941675fb683212e6e0d8e1529b300482">HdfWifiEventInformBssFrame</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, struct <a href="wiphy.md">Wiphy</a> *wiphy, const struct <a href="ieee80211channel.md">Ieee80211Channel</a> *channel, const struct <a href="scannedbssinfo.md">ScannedBssInfo</a> *bssInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1061514277165627"><a name="p1061514277165627"></a><a name="p1061514277165627"></a>int32_t </p>
<p id="p1680601992165627"><a name="p1680601992165627"></a><a name="p1680601992165627"></a>Reports a scanned BSS event. </p>
</td>
</tr>
<tr id="row1042181410165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p954291100165627"><a name="p954291100165627"></a><a name="p954291100165627"></a><a href="wlan.md#ga41efbd6788a80604b81ae117a363b657">HdfWifiEventScanDone</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, WifiScanStatus status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632890653165627"><a name="p632890653165627"></a><a name="p632890653165627"></a>int32_t </p>
<p id="p1043505023165627"><a name="p1043505023165627"></a><a name="p1043505023165627"></a>Reports a scanning completion event. </p>
</td>
</tr>
<tr id="row824803643165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2058959530165627"><a name="p2058959530165627"></a><a name="p2058959530165627"></a><a href="wlan.md#gaf9e61f36e11d7d2e94e7969a8ecf22f1">HdfWifiEventConnectResult</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, const struct <a href="connetresult.md">ConnetResult</a> *result)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1227661637165627"><a name="p1227661637165627"></a><a name="p1227661637165627"></a>int32_t </p>
<p id="p561770484165627"><a name="p561770484165627"></a><a name="p561770484165627"></a>Reports a connection result event. </p>
</td>
</tr>
<tr id="row230805886165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880740052165627"><a name="p1880740052165627"></a><a name="p1880740052165627"></a><a href="wlan.md#ga58b1a613d784233a1e84027079e1ea57">HdfWifiEventDisconnected</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, uint16_t reason, const uint8_t *ie, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1545058082165627"><a name="p1545058082165627"></a><a name="p1545058082165627"></a>int32_t </p>
<p id="p90276236165627"><a name="p90276236165627"></a><a name="p90276236165627"></a>Reports a disconnection event. </p>
</td>
</tr>
<tr id="row921895950165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718815678165627"><a name="p1718815678165627"></a><a name="p1718815678165627"></a><a href="wlan.md#ga1721c7e1b5af0240a663ea9f0fe12854">HdfWifiEventMgmtTxStatus</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, const uint8_t *buf, size_t len, uint8_t ack)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761737230165627"><a name="p1761737230165627"></a><a name="p1761737230165627"></a>int32_t </p>
<p id="p1393339869165627"><a name="p1393339869165627"></a><a name="p1393339869165627"></a>Reports a transmission management status event. </p>
</td>
</tr>
<tr id="row758474488165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1290984689165627"><a name="p1290984689165627"></a><a name="p1290984689165627"></a><a href="wlan.md#gad47d56e4332ccd14116368444a4b330f">HdfWifiEventRxMgmt</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, int32_t freq, int32_t sigMbm, const uint8_t *buf, size_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p69698234165627"><a name="p69698234165627"></a><a name="p69698234165627"></a>int32_t </p>
<p id="p2079095620165627"><a name="p2079095620165627"></a><a name="p2079095620165627"></a>Reports a receive management status event. </p>
</td>
</tr>
<tr id="row808956843165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p322515929165627"><a name="p322515929165627"></a><a name="p322515929165627"></a><a href="wlan.md#ga2aa62f7e8e72e8f9df0b2101c08a9d44">HdfWifiEventCsaChannelSwitch</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, int32_t freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351996010165627"><a name="p351996010165627"></a><a name="p351996010165627"></a>int32_t </p>
<p id="p1002929965165627"><a name="p1002929965165627"></a><a name="p1002929965165627"></a>Reports a CSA channel switching event. </p>
</td>
</tr>
<tr id="row1174325099165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p183169641165627"><a name="p183169641165627"></a><a name="p183169641165627"></a><a href="wlan.md#gafda13471995c91e65326a9aa374ae1c9">HdfWifiEventTimeoutDisconnected</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787813832165627"><a name="p1787813832165627"></a><a name="p1787813832165627"></a>int32_t </p>
<p id="p2027510318165627"><a name="p2027510318165627"></a><a name="p2027510318165627"></a>Reports a timeout disconnection event. </p>
</td>
</tr>
<tr id="row808956644165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1556429680165627"><a name="p1556429680165627"></a><a name="p1556429680165627"></a><a href="wlan.md#ga3e60f4568723471226107848ddbe582f">HdfWifiEventEapolRecv</a> (const char *name, void *context)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870620777165627"><a name="p1870620777165627"></a><a name="p1870620777165627"></a>int32_t </p>
<p id="p420584297165627"><a name="p420584297165627"></a><a name="p420584297165627"></a>Reports the event of receiving the EAPOL frame and notifies WPA to read the EAPOL frame. </p>
</td>
</tr>
</tbody>
</table>

