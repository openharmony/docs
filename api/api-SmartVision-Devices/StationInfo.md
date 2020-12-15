# StationInfo<a name="ZH-CN_TOPIC_0000001055039556"></a>

-   [Overview](#section1129406928165636)
-   [Summary](#section1714801527165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1129406928165636"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Defines station information. 

**Since:**

1.0

## **Summary**<a name="section1714801527165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table822074566165636"></a>
<table><thead align="left"><tr id="row1525702485165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1487073874165636"><a name="p1487073874165636"></a><a name="p1487073874165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p178951897165636"><a name="p178951897165636"></a><a name="p178951897165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row173770898165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1057627204165636"><a name="p1057627204165636"></a><a name="p1057627204165636"></a><a href="WLAN.md#ga14e0c28a09471313507c1ef6f704ad8a">filled</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1006700611165636"><a name="p1006700611165636"></a><a name="p1006700611165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row578138923165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934841495165636"><a name="p1934841495165636"></a><a name="p1934841495165636"></a><a href="WLAN.md#ga7a260a68741622c415faa30f345802f1">connectedTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1448975483165636"><a name="p1448975483165636"></a><a name="p1448975483165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1094718330165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487137683165636"><a name="p1487137683165636"></a><a name="p1487137683165636"></a><a href="WLAN.md#ga6326315bb50ed95fc0ce5ce65177cb78">inactiveTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2056395443165636"><a name="p2056395443165636"></a><a name="p2056395443165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1811550588165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755012387165636"><a name="p1755012387165636"></a><a name="p1755012387165636"></a><a href="WLAN.md#gadc926d27f91b736e04f9ba2ffe663aeb">llid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970111921165636"><a name="p970111921165636"></a><a name="p970111921165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1450547600165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1698065646165636"><a name="p1698065646165636"></a><a name="p1698065646165636"></a><a href="WLAN.md#ga7dedfef626385689a1baa20e9764ff05">plid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179295084165636"><a name="p179295084165636"></a><a name="p179295084165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1833631254165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18003724165636"><a name="p18003724165636"></a><a name="p18003724165636"></a><a href="WLAN.md#ga8445328bc8d5cc4ba8bc5d5f8ec0c1fa">rxBytes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743013000165636"><a name="p743013000165636"></a><a name="p743013000165636"></a>uint64_t </p>
</td>
</tr>
<tr id="row296757474165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983841019165636"><a name="p1983841019165636"></a><a name="p1983841019165636"></a><a href="WLAN.md#ga3084ceeea5b4c0ab032f59f5c5988ef8">txBytes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2143606897165636"><a name="p2143606897165636"></a><a name="p2143606897165636"></a>uint64_t </p>
</td>
</tr>
<tr id="row1361986763165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758567126165636"><a name="p1758567126165636"></a><a name="p1758567126165636"></a><a href="WLAN.md#ga959e150b0327d9a30db768aec89426ae">txRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1506090765165636"><a name="p1506090765165636"></a><a name="p1506090765165636"></a>struct <a href="RateInfo.md">RateInfo</a> </p>
</td>
</tr>
<tr id="row1181178811165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1254605996165636"><a name="p1254605996165636"></a><a name="p1254605996165636"></a><a href="WLAN.md#ga7ccb9050859ba196054590b2294f3a40">rxRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552548654165636"><a name="p552548654165636"></a><a name="p552548654165636"></a>struct <a href="RateInfo.md">RateInfo</a> </p>
</td>
</tr>
<tr id="row253263399165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1337104629165636"><a name="p1337104629165636"></a><a name="p1337104629165636"></a><a href="WLAN.md#gac890bb6b9e08670ec2bb1a0c41ab1cdc">rxPackets</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778505740165636"><a name="p778505740165636"></a><a name="p778505740165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1333173839165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714079715165636"><a name="p1714079715165636"></a><a name="p1714079715165636"></a><a href="WLAN.md#ga0f048248764942c6717dce0695039c1d">txPackets</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57443745165636"><a name="p57443745165636"></a><a name="p57443745165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row56853533165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498739347165636"><a name="p498739347165636"></a><a name="p498739347165636"></a><a href="WLAN.md#gaae49c0ae8a58b58adf92be62af7147fd">txPetries</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386965268165636"><a name="p386965268165636"></a><a name="p386965268165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1762715356165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p936774209165636"><a name="p936774209165636"></a><a name="p936774209165636"></a><a href="WLAN.md#gab02c662294106f07045b103fcf4eb689">txFailed</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328956182165636"><a name="p328956182165636"></a><a name="p328956182165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1019877199165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p661925103165636"><a name="p661925103165636"></a><a name="p661925103165636"></a><a href="WLAN.md#ga9506e6f1cd855cf8116dd650f68966ac">rxDroppedMisc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651077573165636"><a name="p1651077573165636"></a><a name="p1651077573165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1855640163165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1115317529165636"><a name="p1115317529165636"></a><a name="p1115317529165636"></a><a href="WLAN.md#ga4b17833011fe840879c7bcd74aac9f9d">generation</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p640270545165636"><a name="p640270545165636"></a><a name="p640270545165636"></a>int32_t </p>
</td>
</tr>
<tr id="row284237910165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519443574165636"><a name="p519443574165636"></a><a name="p519443574165636"></a><a href="WLAN.md#ga0b38e5935241d2f3cd05c2e5bba1c8e1">bssParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p617534320165636"><a name="p617534320165636"></a><a name="p617534320165636"></a>struct <a href="StaBssParameters.md">StaBssParameters</a> </p>
</td>
</tr>
<tr id="row1540710061165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p898855205165636"><a name="p898855205165636"></a><a name="p898855205165636"></a><a href="WLAN.md#gae3d8b6844b2838f2622405f27d9eb33b">staFlags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215554092165636"><a name="p215554092165636"></a><a name="p215554092165636"></a>struct <a href="StaFlagUpdate.md">StaFlagUpdate</a> </p>
</td>
</tr>
<tr id="row1231853334165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1760606518165636"><a name="p1760606518165636"></a><a name="p1760606518165636"></a><a href="WLAN.md#ga5f5c974dbd2e5608b3ea2e768e4559ca">offset</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1263052160165636"><a name="p1263052160165636"></a><a name="p1263052160165636"></a>int64_t </p>
</td>
</tr>
<tr id="row689817827165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1705146129165636"><a name="p1705146129165636"></a><a name="p1705146129165636"></a><a href="WLAN.md#gac2e13b44df4b4df0018f801f8a9e0494">assocReqIes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384433373165636"><a name="p1384433373165636"></a><a name="p1384433373165636"></a>const uint8_t * </p>
</td>
</tr>
<tr id="row2033063129165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1759020661165636"><a name="p1759020661165636"></a><a name="p1759020661165636"></a><a href="WLAN.md#ga7822f8e474e18a4f7ae7cee7cbd9bc7c">assocReqIesLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p390741442165636"><a name="p390741442165636"></a><a name="p390741442165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row339122368165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116578044165636"><a name="p116578044165636"></a><a name="p116578044165636"></a><a href="WLAN.md#gaa669232960c93e73558062e466d0fb02">beaconLossCount</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1358473337165636"><a name="p1358473337165636"></a><a name="p1358473337165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1936406470165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1222359625165636"><a name="p1222359625165636"></a><a name="p1222359625165636"></a><a href="WLAN.md#gaf505fd1078d9f5a0d5374d9538e8d5bb">plinkState</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059908704165636"><a name="p2059908704165636"></a><a name="p2059908704165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row784946740165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1544919103165636"><a name="p1544919103165636"></a><a name="p1544919103165636"></a><a href="WLAN.md#gaf34477153f092bd07bd8a80ca29d16bf">signal</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399027018165636"><a name="p1399027018165636"></a><a name="p1399027018165636"></a>int8_t </p>
</td>
</tr>
<tr id="row1399320346165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110608667165636"><a name="p110608667165636"></a><a name="p110608667165636"></a><a href="WLAN.md#ga5423c3f5c2797588018ae3e32582e0bf">signalAvg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553102517165636"><a name="p1553102517165636"></a><a name="p1553102517165636"></a>int8_t </p>
</td>
</tr>
<tr id="row694352380165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764786993165636"><a name="p764786993165636"></a><a name="p764786993165636"></a><a href="WLAN.md#ga4bf7e03861cdefd017d6669994a1df43">resv1</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p745843409165636"><a name="p745843409165636"></a><a name="p745843409165636"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

