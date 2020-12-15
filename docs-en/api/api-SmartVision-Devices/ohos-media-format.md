# OHOS::Media::Format<a name="EN-US_TOPIC_0000001055039530"></a>

-   [Overview](#section141884443165633)
-   [Summary](#section2084623564165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section141884443165633"></a>

**Related Modules:**

[MultiMedia\_MediaCommon](multimedia_mediacommon.md)

**Description:**

Saves and sets media metadata, such as the media playback duration. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2084623564165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1662692173165633"></a>
<table><thead align="left"><tr id="row1089080074165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p677295950165633"><a name="p677295950165633"></a><a name="p677295950165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p443704105165633"><a name="p443704105165633"></a><a name="p443704105165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1080586781165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1422083326165633"><a name="p1422083326165633"></a><a name="p1422083326165633"></a><a href="multimedia_mediacommon.md#ga42435567c8fd61fd2da4834465aca98e">Format</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225274296165633"><a name="p225274296165633"></a><a name="p225274296165633"></a> </p>
<p id="p113082950165633"><a name="p113082950165633"></a><a name="p113082950165633"></a>Default constructor of the <a href="ohos-media-format.md">Format</a> instance. </p>
</td>
</tr>
<tr id="row497857014165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466973719165633"><a name="p466973719165633"></a><a name="p466973719165633"></a><a href="multimedia_mediacommon.md#ga66771efe315d001e79a14d316c58718e">PutIntValue</a> (const std::string &amp;key, int32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p984540698165633"><a name="p984540698165633"></a><a name="p984540698165633"></a>bool </p>
<p id="p1046937788165633"><a name="p1046937788165633"></a><a name="p1046937788165633"></a>Sets metadata of the integer type. </p>
</td>
</tr>
<tr id="row680115810165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320541763165633"><a name="p1320541763165633"></a><a name="p1320541763165633"></a><a href="multimedia_mediacommon.md#ga5b4477636095d80ec4e65c1be617c61c">PutLongValue</a> (const std::string &amp;key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p919161587165633"><a name="p919161587165633"></a><a name="p919161587165633"></a>bool </p>
<p id="p2080002434165633"><a name="p2080002434165633"></a><a name="p2080002434165633"></a>Sets metadata of the long integer type. </p>
</td>
</tr>
<tr id="row440171162165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p756210436165633"><a name="p756210436165633"></a><a name="p756210436165633"></a><a href="multimedia_mediacommon.md#gabec9417120824f5bb9eb676be380016f">PutFloatValue</a> (const std::string &amp;key, float value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608260116165633"><a name="p608260116165633"></a><a name="p608260116165633"></a>bool </p>
<p id="p724860036165633"><a name="p724860036165633"></a><a name="p724860036165633"></a>Sets metadata of the single-precision floating-point type. </p>
</td>
</tr>
<tr id="row1269475390165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p421568162165633"><a name="p421568162165633"></a><a name="p421568162165633"></a><a href="multimedia_mediacommon.md#ga9a98a92eb4436301853a049b5f3313c6">PutDoubleValue</a> (const std::string &amp;key, double value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1723055316165633"><a name="p1723055316165633"></a><a name="p1723055316165633"></a>bool </p>
<p id="p1938503216165633"><a name="p1938503216165633"></a><a name="p1938503216165633"></a>Sets metadata of the double-precision floating-point type. </p>
</td>
</tr>
<tr id="row1524143118165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922498140165633"><a name="p1922498140165633"></a><a name="p1922498140165633"></a><a href="multimedia_mediacommon.md#gabdc104597559320256930f420eaab82f">PutStringValue</a> (const std::string &amp;key, const std::string &amp;value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1702345725165633"><a name="p1702345725165633"></a><a name="p1702345725165633"></a>bool </p>
<p id="p857298867165633"><a name="p857298867165633"></a><a name="p857298867165633"></a>Sets metadata of the string type. </p>
</td>
</tr>
<tr id="row663535345165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056520090165633"><a name="p1056520090165633"></a><a name="p1056520090165633"></a><a href="multimedia_mediacommon.md#ga798ef733a253558757f49714090b3969">GetIntValue</a> (const std::string &amp;key, int32_t &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1407703346165633"><a name="p1407703346165633"></a><a name="p1407703346165633"></a>bool </p>
<p id="p1010350758165633"><a name="p1010350758165633"></a><a name="p1010350758165633"></a>Obtains the metadata value of the integer type. </p>
</td>
</tr>
<tr id="row776925703165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596139557165633"><a name="p1596139557165633"></a><a name="p1596139557165633"></a><a href="multimedia_mediacommon.md#ga7f1c503f40b78083cb9b9ae9ce93d3b4">GetLongValue</a> (const std::string &amp;key, int64_t &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167688426165633"><a name="p167688426165633"></a><a name="p167688426165633"></a>bool </p>
<p id="p1132651985165633"><a name="p1132651985165633"></a><a name="p1132651985165633"></a>Obtains the metadata value of the long integer type. </p>
</td>
</tr>
<tr id="row414240581165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980260749165633"><a name="p1980260749165633"></a><a name="p1980260749165633"></a><a href="multimedia_mediacommon.md#gac4e963a9fe320c0143ed33df5f737cb3">GetFloatValue</a> (const std::string &amp;key, float &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p947709922165633"><a name="p947709922165633"></a><a name="p947709922165633"></a>bool </p>
<p id="p1001905584165633"><a name="p1001905584165633"></a><a name="p1001905584165633"></a>Obtains the metadata value of the single-precision floating-point type. </p>
</td>
</tr>
<tr id="row402689736165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487261451165633"><a name="p1487261451165633"></a><a name="p1487261451165633"></a><a href="multimedia_mediacommon.md#gafe949ed0c2d9dcb5c5e57c7fde226f3e">GetDoubleValue</a> (const std::string &amp;key, double &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p291443948165633"><a name="p291443948165633"></a><a name="p291443948165633"></a>bool </p>
<p id="p213687919165633"><a name="p213687919165633"></a><a name="p213687919165633"></a>Obtains the metadata value of the double-precision floating-point type. </p>
</td>
</tr>
<tr id="row77921189165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385751815165633"><a name="p385751815165633"></a><a name="p385751815165633"></a><a href="multimedia_mediacommon.md#ga089a3e44e128fb662b72c56b53c7068b">GetStringValue</a> (const std::string &amp;key, std::string &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p317433623165633"><a name="p317433623165633"></a><a name="p317433623165633"></a>bool </p>
<p id="p164114404165633"><a name="p164114404165633"></a><a name="p164114404165633"></a>Obtains the metadata value of the string type. </p>
</td>
</tr>
<tr id="row1858796154165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1384618244165633"><a name="p1384618244165633"></a><a name="p1384618244165633"></a><a href="multimedia_mediacommon.md#ga4adff4846515cef00987a360a4d117af">GetFormatMap</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p365369562165633"><a name="p365369562165633"></a><a name="p365369562165633"></a>const std::map&lt; std::string, <a href="ohos-media-formatdata.md">FormatData</a> * &gt; &amp; </p>
<p id="p251180521165633"><a name="p251180521165633"></a><a name="p251180521165633"></a>Obtains the metadata map. </p>
</td>
</tr>
<tr id="row1283764964165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236856624165633"><a name="p236856624165633"></a><a name="p236856624165633"></a><a href="multimedia_mediacommon.md#ga528134c9f87bf755077b3ef51d64e198">CopyFrom</a> (const <a href="ohos-media-format.md">Format</a> &amp;format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047448899165633"><a name="p2047448899165633"></a><a name="p2047448899165633"></a>bool </p>
<p id="p1465268650165633"><a name="p1465268650165633"></a><a name="p1465268650165633"></a>Sets all metadata to a specified format. </p>
</td>
</tr>
</tbody>
</table>

