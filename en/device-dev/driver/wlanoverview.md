# WLAN Overview<a name="EN-US_TOPIC_0000001051643558"></a>

-   [Introduction](#section23087361515)
-   [WLAN Driver API Architecture](#section1533192516212)
-   [Available APIs](#section87491484213)

## Introduction<a name="section23087361515"></a>

The WLAN module is developed based on the Hardware Driver Foundation \(HDF\). It supports cross-OS migration, component adaptation, and modular assembly and compilation. Based on the unified APIs provided by the WLAN module, driver developers of WLAN vendors can adapt their driver code and are capable of creating, disabling, scanning, and connecting to WLAN hotspots. The WLAN driver provides the Hardware Driver Interface \(HDI\) layer with the capabilities of setting and obtaining the device MAC address and setting the transmit power. The following figure shows the framework of the  [WLAN module](#fig967034316227):

**Figure  1**  WLAN framework<a name="fig967034316227"></a>  


![](figures/en-us_image_0000001055299108.png)

## WLAN Driver API Architecture<a name="section1533192516212"></a>

The WLAN module provides the following three types of APIs:

1. Capability APIs for the HDI layer

2. Capability APIs directly invoked by drivers

3. Capability APIs for vendors

**Figure  2**  Available APIs of the WLAN module<a name="fig15016395217"></a>  


![](figures/接口分布图4.png)

## Available APIs<a name="section87491484213"></a>

The WLAN driver module provides APIs that can be directly called by driver developers, such as creating/releasing a  **WifiModule**, connecting to/disconnecting from a WLAN hotspot, applying for/releasing a  **NetBuf**, and converting between the  **pbuf**  structure of Lightweight IP \(lwIP\) and a  **NetBuf**.  [Table 1](#table1521573319472)  provides some APIs.

**Table  1**  APIs that can be directly called by driver developers

<a name="table1521573319472"></a>
<table><thead align="left"><tr id="row121519334474"><th class="cellrowborder" valign="top" width="15.079999999999998%" id="mcps1.2.4.1.1"><p id="p1221510339475"><a name="p1221510339475"></a><a name="p1221510339475"></a>File</p>
</th>
<th class="cellrowborder" valign="top" width="60.33%" id="mcps1.2.4.1.2"><p id="p0215153344716"><a name="p0215153344716"></a><a name="p0215153344716"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="24.59%" id="mcps1.2.4.1.3"><p id="p1421503315478"><a name="p1421503315478"></a><a name="p1421503315478"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row112150333476"><td class="cellrowborder" rowspan="4" valign="top" width="15.079999999999998%" headers="mcps1.2.4.1.1 "><p id="p2155710125317"><a name="p2155710125317"></a><a name="p2155710125317"></a>wifi_module.h</p>
<p id="p189132019183"><a name="p189132019183"></a><a name="p189132019183"></a></p>
</td>
<td class="cellrowborder" valign="top" width="60.33%" headers="mcps1.2.4.1.2 "><p id="p363110387399"><a name="p363110387399"></a><a name="p363110387399"></a>struct WifiModule *WifiModuleCreate(const struct HdfConfigWifiModuleConfig *config);</p>
</td>
<td class="cellrowborder" valign="top" width="24.59%" headers="mcps1.2.4.1.3 "><p id="p1363012387393"><a name="p1363012387393"></a><a name="p1363012387393"></a>Creates a <strong id="b17218103820131"><a name="b17218103820131"></a><a name="b17218103820131"></a>WifiModule</strong>.</p>
</td>
</tr>
<tr id="row112151233194714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7629163817393"><a name="p7629163817393"></a><a name="p7629163817393"></a>void WifiModuleDelete(struct WifiModule *module);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2627638173917"><a name="p2627638173917"></a><a name="p2627638173917"></a>Deletes and releases data of a <strong id="b17674114211319"><a name="b17674114211319"></a><a name="b17674114211319"></a>WifiModule</strong>.</p>
</td>
</tr>
<tr id="row1121533316475"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p12626103814399"><a name="p12626103814399"></a><a name="p12626103814399"></a>int32_t DelFeature(struct WifiModule *module, uint16_t featureType);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1162543816393"><a name="p1162543816393"></a><a name="p1162543816393"></a>Deletes a feature from a <strong id="b12747104710136"><a name="b12747104710136"></a><a name="b12747104710136"></a>WifiModule</strong>.</p>
</td>
</tr>
<tr id="row172153335473"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p162433816392"><a name="p162433816392"></a><a name="p162433816392"></a>int32_t AddFeature(struct WifiModule *module, uint16_t featureType, struct WifiFeature *featureData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p186235383393"><a name="p186235383393"></a><a name="p186235383393"></a>Adds a feature to a <strong id="b61351114111410"><a name="b61351114111410"></a><a name="b61351114111410"></a>WifiModule</strong>.</p>
</td>
</tr>
<tr id="row451796205011"><td class="cellrowborder" rowspan="4" valign="top" width="15.079999999999998%" headers="mcps1.2.4.1.1 "><p id="p2659417135013"><a name="p2659417135013"></a><a name="p2659417135013"></a>wifi_mac80211_ops.h</p>
</td>
<td class="cellrowborder" valign="top" width="60.33%" headers="mcps1.2.4.1.2 "><p id="p175181615011"><a name="p175181615011"></a><a name="p175181615011"></a>int32_t (*startAp)(NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" width="24.59%" headers="mcps1.2.4.1.3 "><p id="p195182610507"><a name="p195182610507"></a><a name="p195182610507"></a>Starts an AP.</p>
</td>
</tr>
<tr id="row5518663503"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p125181260501"><a name="p125181260501"></a><a name="p125181260501"></a>int32_t (*stopAp)(NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1151815635014"><a name="p1151815635014"></a><a name="p1151815635014"></a>Stops an AP.</p>
</td>
</tr>
<tr id="row851915617503"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20519865500"><a name="p20519865500"></a><a name="p20519865500"></a>int32_t (*connect)(NetDevice *netDev, WifiConnectParams *param);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14519469509"><a name="p14519469509"></a><a name="p14519469509"></a>Connects to a hotspot.</p>
</td>
</tr>
<tr id="row18519136185016"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p145195620502"><a name="p145195620502"></a><a name="p145195620502"></a>int32_t (*disconnect)(NetDevice *netDev, uint16_t reasonCode);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p175191863503"><a name="p175191863503"></a><a name="p175191863503"></a>Disconnects from a hotspot.</p>
</td>
</tr>
<tr id="row176421942125016"><td class="cellrowborder" rowspan="5" valign="top" width="15.079999999999998%" headers="mcps1.2.4.1.1 "><p id="p7937165012500"><a name="p7937165012500"></a><a name="p7937165012500"></a>hdf_netbuf.h</p>
</td>
<td class="cellrowborder" valign="top" width="60.33%" headers="mcps1.2.4.1.2 "><p id="p1964211423505"><a name="p1964211423505"></a><a name="p1964211423505"></a>static inline void NetBufQueueInit(struct NetBufQueue *q);</p>
</td>
<td class="cellrowborder" valign="top" width="24.59%" headers="mcps1.2.4.1.3 "><p id="p364254211507"><a name="p364254211507"></a><a name="p364254211507"></a>Initializes a <strong id="b8331245144114"><a name="b8331245144114"></a><a name="b8331245144114"></a>NetBuf</strong> queue.</p>
</td>
</tr>
<tr id="row664264225020"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p166421942115017"><a name="p166421942115017"></a><a name="p166421942115017"></a>struct NetBuf *NetBufAlloc(uint32_t size);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3642164215501"><a name="p3642164215501"></a><a name="p3642164215501"></a>Applies for a <strong id="b15893135016416"><a name="b15893135016416"></a><a name="b15893135016416"></a>NetBuf</strong>.</p>
</td>
</tr>
<tr id="row19642134215018"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p964310425501"><a name="p964310425501"></a><a name="p964310425501"></a>void NetBufFree(struct NetBuf *nb);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1464312427503"><a name="p1464312427503"></a><a name="p1464312427503"></a>Releases a <strong id="b87021256204112"><a name="b87021256204112"></a><a name="b87021256204112"></a>NetBuf</strong>.</p>
</td>
</tr>
<tr id="row7643194215013"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20643164218508"><a name="p20643164218508"></a><a name="p20643164218508"></a>struct NetBuf *Pbuf2NetBuf(const struct NetDevice *netdev, struct pbuf *lwipBuf);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p186437429509"><a name="p186437429509"></a><a name="p186437429509"></a>Converts the <strong id="b108101241316"><a name="b108101241316"></a><a name="b108101241316"></a>pbuf</strong> structure of <strong id="b148154412318"><a name="b148154412318"></a><a name="b148154412318"></a>lwIP</strong> to a <strong id="b8994115217371"><a name="b8994115217371"></a><a name="b8994115217371"></a>NetBuf</strong>.</p>
</td>
</tr>
<tr id="row7657132317518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p86576231557"><a name="p86576231557"></a><a name="p86576231557"></a>struct pbuf *NetBuf2Pbuf(const struct NetBuf *nb);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1965702312510"><a name="p1965702312510"></a><a name="p1965702312510"></a>Converts a <strong id="b92856616388"><a name="b92856616388"></a><a name="b92856616388"></a>NetBuf</strong> to the <strong id="b993215663110"><a name="b993215663110"></a><a name="b993215663110"></a>pbuf</strong> structure of <strong id="b10933563310"><a name="b10933563310"></a><a name="b10933563310"></a>lwIP</strong>.</p>
</td>
</tr>
</tbody>
</table>

The WLAN driver module provides APIs for driver developers, such as initializing/deregistering, opening/stopping a  **NetDevice**, and obtaining the state of a  **NetDevice**.  [Table 2](#table74613501475)  provides some APIs.

**Table  2**  APIs for driver developers of WLAN vendors to implement

<a name="table74613501475"></a>
<table><thead align="left"><tr id="row194625016476"><th class="cellrowborder" valign="top" width="20.75%" id="mcps1.2.4.1.1"><p id="p10468502479"><a name="p10468502479"></a><a name="p10468502479"></a>File</p>
</th>
<th class="cellrowborder" valign="top" width="52.75%" id="mcps1.2.4.1.2"><p id="p184615501477"><a name="p184615501477"></a><a name="p184615501477"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="26.5%" id="mcps1.2.4.1.3"><p id="p1146135044719"><a name="p1146135044719"></a><a name="p1146135044719"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row04616509472"><td class="cellrowborder" rowspan="6" valign="top" width="20.75%" headers="mcps1.2.4.1.1 "><p id="p14615017477"><a name="p14615017477"></a><a name="p14615017477"></a>net_device.h</p>
</td>
<td class="cellrowborder" valign="top" width="52.75%" headers="mcps1.2.4.1.2 "><p id="p144943564611"><a name="p144943564611"></a><a name="p144943564611"></a>int32_t (*init)(struct NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" width="26.5%" headers="mcps1.2.4.1.3 "><p id="p18822442135411"><a name="p18822442135411"></a><a name="p18822442135411"></a>Initializes a <strong id="b1947112374310"><a name="b1947112374310"></a><a name="b1947112374310"></a>NetDevice</strong>.</p>
</td>
</tr>
<tr id="row1546250114713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1490010315564"><a name="p1490010315564"></a><a name="p1490010315564"></a>struct NetDevStats *(*getStats)(struct NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5900163115564"><a name="p5900163115564"></a><a name="p5900163115564"></a>Obtains the state of a <strong id="b4952125574216"><a name="b4952125574216"></a><a name="b4952125574216"></a>NetDevice</strong>.</p>
</td>
</tr>
<tr id="row1646165010470"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16909135319564"><a name="p16909135319564"></a><a name="p16909135319564"></a>int32_t (*setMacAddr)(struct NetDevice *netDev, void *addr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p122001431115713"><a name="p122001431115713"></a><a name="p122001431115713"></a>Sets the MAC address.</p>
</td>
</tr>
<tr id="row12471250184711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p154213655215"><a name="p154213655215"></a><a name="p154213655215"></a>void (*deInit)(struct NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14845675719"><a name="p14845675719"></a><a name="p14845675719"></a>Deinitializes a <strong id="b18383143517427"><a name="b18383143517427"></a><a name="b18383143517427"></a>NetDevice</strong>.</p>
</td>
</tr>
<tr id="row13471050104719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16686131655218"><a name="p16686131655218"></a><a name="p16686131655218"></a>int32_t (*open)(struct NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p164825613576"><a name="p164825613576"></a><a name="p164825613576"></a>Opens a <strong id="b226313919425"><a name="b226313919425"></a><a name="b226313919425"></a>NetDevice</strong>.</p>
</td>
</tr>
<tr id="row1747125054714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2310615407"><a name="p2310615407"></a><a name="p2310615407"></a>int32_t (*stop)(struct NetDevice *netDev);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1982212428542"><a name="p1982212428542"></a><a name="p1982212428542"></a>Stops a <strong id="b81039430429"><a name="b81039430429"></a><a name="b81039430429"></a>NetDevice</strong>.</p>
</td>
</tr>
</tbody>
</table>

The WLAN driver provides the HDI layer with the APIs for creating and destroying an  **IWiFi**  object and setting the MAC address.  [Table 3](#table141076311618)  provides some APIs.

**Table  3**  APIs provided by the WLAN HAL module

<a name="table141076311618"></a>
<table><thead align="left"><tr id="row010716312120"><th class="cellrowborder" valign="top" width="15.950000000000001%" id="mcps1.2.4.1.1"><p id="p1110713311116"><a name="p1110713311116"></a><a name="p1110713311116"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="59.46%" id="mcps1.2.4.1.2"><p id="p161073311610"><a name="p161073311610"></a><a name="p161073311610"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="24.59%" id="mcps1.2.4.1.3"><p id="p110716315118"><a name="p110716315118"></a><a name="p110716315118"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row41077311218"><td class="cellrowborder" rowspan="4" valign="top" width="15.950000000000001%" headers="mcps1.2.4.1.1 "><p id="p1810719311013"><a name="p1810719311013"></a><a name="p1810719311013"></a>wifi_hal.h</p>
<p id="p12107931715"><a name="p12107931715"></a><a name="p12107931715"></a></p>
</td>
<td class="cellrowborder" valign="top" width="59.46%" headers="mcps1.2.4.1.2 "><p id="p1910815311519"><a name="p1910815311519"></a><a name="p1910815311519"></a>int32_t WifiConstruct(struct IWiFi **wifiInstance);</p>
</td>
<td class="cellrowborder" valign="top" width="24.59%" headers="mcps1.2.4.1.3 "><p id="p12108133112115"><a name="p12108133112115"></a><a name="p12108133112115"></a>Creates an <strong id="b218481014265"><a name="b218481014265"></a><a name="b218481014265"></a>IWiFi</strong> object with basic capabilities.</p>
</td>
</tr>
<tr id="row20108183110111"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p71083311617"><a name="p71083311617"></a><a name="p71083311617"></a>int32_t WifiDestruct(struct IWiFi **wifiInstance);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1010810315118"><a name="p1010810315118"></a><a name="p1010810315118"></a>Destroys an <strong id="b1269381514265"><a name="b1269381514265"></a><a name="b1269381514265"></a>IWiFi</strong> object.</p>
</td>
</tr>
<tr id="row19108131417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p810818315118"><a name="p810818315118"></a><a name="p810818315118"></a>int32_t (*start)(struct IWiFi *);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9108113116119"><a name="p9108113116119"></a><a name="p9108113116119"></a>Creates a channel between the HAL and the driver and obtains the NIC supported by the driver.</p>
</td>
</tr>
<tr id="row810803112116"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1310823110116"><a name="p1310823110116"></a><a name="p1310823110116"></a>int32_t (*stop)(struct IWiFi *);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12108183112110"><a name="p12108183112110"></a><a name="p12108183112110"></a>Stops the channel between the HAL and the driver.</p>
</td>
</tr>
<tr id="row91081731717"><td class="cellrowborder" rowspan="4" valign="top" width="15.950000000000001%" headers="mcps1.2.4.1.1 "><p id="p1910814312115"><a name="p1910814312115"></a><a name="p1910814312115"></a>wifi_hal_base_feature.h</p>
</td>
<td class="cellrowborder" valign="top" width="59.46%" headers="mcps1.2.4.1.2 "><p id="p2108123113111"><a name="p2108123113111"></a><a name="p2108123113111"></a>int32_t (*getFeatureType)(const struct IWiFiBaseFeature *);</p>
</td>
<td class="cellrowborder" valign="top" width="24.59%" headers="mcps1.2.4.1.3 "><p id="p910843113113"><a name="p910843113113"></a><a name="p910843113113"></a>Obtains the feature type.</p>
</td>
</tr>
<tr id="row161081931318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1610814318119"><a name="p1610814318119"></a><a name="p1610814318119"></a>int32_t (*setMacAddress)(const struct IWiFiBaseFeature *, unsigned char *, uint8_t);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p101081031818"><a name="p101081031818"></a><a name="p101081031818"></a>Sets the MAC address.</p>
</td>
</tr>
<tr id="row191081631318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p191087311317"><a name="p191087311317"></a><a name="p191087311317"></a>int32_t (*getDeviceMacAddress)(const struct IWiFiBaseFeature *, unsigned char *, uint8_t);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1110810312012"><a name="p1110810312012"></a><a name="p1110810312012"></a>Obtains the device MAC address.</p>
</td>
</tr>
<tr id="row21080317115"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p310873115118"><a name="p310873115118"></a><a name="p310873115118"></a>int32_t (*setTxPower)(const struct IWiFiBaseFeature *, int32_t);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p410817311911"><a name="p410817311911"></a><a name="p410817311911"></a>Sets the transmit power.</p>
</td>
</tr>
</tbody>
</table>

