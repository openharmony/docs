# OHOS::SysInfo::OnFPSChangedListener<a name="EN-US_TOPIC_0000001055039550"></a>

-   [Overview](#section1472841716165635)
-   [Summary](#section1811819279165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1472841716165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Called when the FPS changes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1811819279165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table881715049165635"></a>
<table><thead align="left"><tr id="row1651221046165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1208864102165635"><a name="p1208864102165635"></a><a name="p1208864102165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p866124300165635"><a name="p866124300165635"></a><a name="p866124300165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18002074165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p597687520165635"><a name="p597687520165635"></a><a name="p597687520165635"></a><a href="graphic.md#ga3e24fe52ec7c4bf9fc9f5703982b3568">OnFPSChangedListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1446455123165635"><a name="p1446455123165635"></a><a name="p1446455123165635"></a> </p>
<p id="p500929347165635"><a name="p500929347165635"></a><a name="p500929347165635"></a>A constructor used to create an <strong id="b1090063599165635"><a name="b1090063599165635"></a><a name="b1090063599165635"></a><a href="ohos-sysinfo-onfpschangedlistener.md">OnFPSChangedListener</a></strong> instance with the default sampling type <strong id="b1342298277165635"><a name="b1342298277165635"></a><a name="b1342298277165635"></a>FPS_CT_FIXED_TIME</strong>. </p>
</td>
</tr>
<tr id="row1992580056165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p642376327165635"><a name="p642376327165635"></a><a name="p642376327165635"></a><a href="graphic.md#ga4e103243c2fd1e2e5206262280f1b80c">~OnFPSChangedListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804862856165635"><a name="p804862856165635"></a><a name="p804862856165635"></a>virtual </p>
<p id="p201776535165635"><a name="p201776535165635"></a><a name="p201776535165635"></a>A destructor used to delete the <strong id="b102205462165635"><a name="b102205462165635"></a><a name="b102205462165635"></a><a href="ohos-sysinfo-onfpschangedlistener.md">OnFPSChangedListener</a></strong> instance. </p>
</td>
</tr>
<tr id="row1909727913165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332904333165635"><a name="p1332904333165635"></a><a name="p1332904333165635"></a><a href="graphic.md#ga82a8426a18e30ff3e9d4d388c53b4af5">OnFPSChanged</a> (float newFPS)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091069405165635"><a name="p1091069405165635"></a><a name="p1091069405165635"></a>virtual void </p>
<p id="p286778756165635"><a name="p286778756165635"></a><a name="p286778756165635"></a>Called when the FPS data changes. </p>
</td>
</tr>
<tr id="row1308129407165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41658950165635"><a name="p41658950165635"></a><a name="p41658950165635"></a><a href="graphic.md#gaf7c8d9a4d44cee2001ad0cd40c827c47">GetFPSCalculateType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1237536866165635"><a name="p1237536866165635"></a><a name="p1237536866165635"></a><a href="graphic.md#ga75d850e3abff6c2f617b689a0cb9a3d1">FPSCalculateType</a> </p>
<p id="p1051681101165635"><a name="p1051681101165635"></a><a name="p1051681101165635"></a>Obtains the FPS sampling type. </p>
</td>
</tr>
<tr id="row1049071177165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1966294323165635"><a name="p1966294323165635"></a><a name="p1966294323165635"></a><a href="graphic.md#ga5eb3d62fce38f8d2fcf2a0a4560a3640">SetFPSCalculateType</a> (<a href="graphic.md#ga75d850e3abff6c2f617b689a0cb9a3d1">FPSCalculateType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727363944165635"><a name="p727363944165635"></a><a name="p727363944165635"></a>void </p>
<p id="p485542014165635"><a name="p485542014165635"></a><a name="p485542014165635"></a>Sets the FPS sampling type. </p>
</td>
</tr>
<tr id="row176563050165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1067291101165635"><a name="p1067291101165635"></a><a name="p1067291101165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920055867165635"><a name="p1920055867165635"></a><a name="p1920055867165635"></a>void * </p>
<p id="p1989670473165635"><a name="p1989670473165635"></a><a name="p1989670473165635"></a>Overrides the <strong id="b1304161583165635"><a name="b1304161583165635"></a><a name="b1304161583165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row319199149165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1794406922165635"><a name="p1794406922165635"></a><a name="p1794406922165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464344798165635"><a name="p1464344798165635"></a><a name="p1464344798165635"></a>void </p>
<p id="p1971057423165635"><a name="p1971057423165635"></a><a name="p1971057423165635"></a>Overrides the <strong id="b118242098165635"><a name="b118242098165635"></a><a name="b118242098165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

