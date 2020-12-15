# sdio\_if.h<a name="EN-US_TOPIC_0000001054918133"></a>

-   [Overview](#section1871988065165628)
-   [Summary](#section1692669337165628)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1871988065165628"></a>

**Related Modules:**

[SDIO](sdio.md)

**Description:**

Declares the standard SDIO APIs. 

**Since:**

1.0

## **Summary**<a name="section1692669337165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table135720686165628"></a>
<table><thead align="left"><tr id="row40437984165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1141541118165628"><a name="p1141541118165628"></a><a name="p1141541118165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p986900698165628"><a name="p986900698165628"></a><a name="p986900698165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1106324364165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952313637165628"><a name="p952313637165628"></a><a name="p952313637165628"></a><a href="sdiofuncinfo.md">SdioFuncInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033051926165628"><a name="p2033051926165628"></a><a name="p2033051926165628"></a>Defines the SDIO capabilities. </p>
</td>
</tr>
<tr id="row513924571165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1618326693165628"><a name="p1618326693165628"></a><a name="p1618326693165628"></a><a href="sdiocommoninfo.md">SdioCommonInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166994657165628"><a name="p166994657165628"></a><a name="p166994657165628"></a>Defines SDIO common information. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1875535611165628"></a>
<table><thead align="left"><tr id="row1565664163165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p21216951165628"><a name="p21216951165628"></a><a name="p21216951165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p792613332165628"><a name="p792613332165628"></a><a name="p792613332165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1680347065165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p769724743165628"><a name="p769724743165628"></a><a name="p769724743165628"></a><a href="sdio.md#ga858bec274683a4f50d53d1f9f43d204b">SdioIrqHandler</a>(void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1288093732165628"><a name="p1288093732165628"></a><a name="p1288093732165628"></a>typedef void </p>
<p id="p1771605596165628"><a name="p1771605596165628"></a><a name="p1771605596165628"></a>Defines the function type of an SDIO IRQ. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1661196353165628"></a>
<table><thead align="left"><tr id="row694885317165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2004487703165628"><a name="p2004487703165628"></a><a name="p2004487703165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p517423591165628"><a name="p517423591165628"></a><a name="p517423591165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1823982417165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648767170165628"><a name="p648767170165628"></a><a name="p648767170165628"></a><a href="sdio.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a> { <a href="sdio.md#gga4037437ac001a9848dd242e8aa632678aa4e25cb3b51d47da78d6b58d11d946cd">SDIO_FUNC_INFO</a> = 0, <a href="sdio.md#gga4037437ac001a9848dd242e8aa632678a7aa994f868190924d0bf354c1bb0d67b">SDIO_OTHER_INFO</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1981683364165628"><a name="p1981683364165628"></a><a name="p1981683364165628"></a>Enumerates SDIO common information types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table110492406165628"></a>
<table><thead align="left"><tr id="row1754755848165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p34055027165628"><a name="p34055027165628"></a><a name="p34055027165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1684988893165628"><a name="p1684988893165628"></a><a name="p1684988893165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1774852803165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334961769165628"><a name="p1334961769165628"></a><a name="p1334961769165628"></a><a href="sdio.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a> (int16_t busNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1290032183165628"><a name="p1290032183165628"></a><a name="p1290032183165628"></a><a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1953192061165628"><a name="p1953192061165628"></a><a name="p1953192061165628"></a>Opens an SDIO controller with a specified bus number. </p>
</td>
</tr>
<tr id="row456476051165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p679021323165628"><a name="p679021323165628"></a><a name="p679021323165628"></a><a href="sdio.md#ga2e94ff04073420086e1453f125703ec7">SdioClose</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194333758165628"><a name="p194333758165628"></a><a name="p194333758165628"></a>void </p>
<p id="p151515656165628"><a name="p151515656165628"></a><a name="p151515656165628"></a>Closes an SDIO controller. </p>
</td>
</tr>
<tr id="row22544893165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1088307510165628"><a name="p1088307510165628"></a><a name="p1088307510165628"></a><a href="sdio.md#ga14752ccc5cea77cfe30cfa9ab189815f">SdioReadBytes</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465017450165628"><a name="p465017450165628"></a><a name="p465017450165628"></a>int32_t </p>
<p id="p1842191489165628"><a name="p1842191489165628"></a><a name="p1842191489165628"></a>Incrementally reads a given length of data from the specified SDIO address. </p>
</td>
</tr>
<tr id="row284783067165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p599254688165628"><a name="p599254688165628"></a><a name="p599254688165628"></a><a href="sdio.md#gaa4df7c3e2cde82f5cb7255561b99cc74">SdioWriteBytes</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p253257085165628"><a name="p253257085165628"></a><a name="p253257085165628"></a>int32_t </p>
<p id="p362576006165628"><a name="p362576006165628"></a><a name="p362576006165628"></a>Incrementally writes a given length of data into the specified SDIO address. </p>
</td>
</tr>
<tr id="row1679793306165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296574102165628"><a name="p296574102165628"></a><a name="p296574102165628"></a><a href="sdio.md#gabc1645bc8ab9068a13ae501efdb4a9fc">SdioReadBytesFromFixedAddr</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295998350165628"><a name="p1295998350165628"></a><a name="p1295998350165628"></a>int32_t </p>
<p id="p1730731556165628"><a name="p1730731556165628"></a><a name="p1730731556165628"></a>Reads a given length of data from the fixed SDIO address. </p>
</td>
</tr>
<tr id="row761923914165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566261500165628"><a name="p566261500165628"></a><a name="p566261500165628"></a><a href="sdio.md#ga82d6b3047bd694cdbdfb0a3711797c7b">SdioWriteBytesToFixedAddr</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242730134165628"><a name="p1242730134165628"></a><a name="p1242730134165628"></a>int32_t </p>
<p id="p1078868537165628"><a name="p1078868537165628"></a><a name="p1078868537165628"></a>Writes a given length of data into the fixed SDIO address. </p>
</td>
</tr>
<tr id="row2028778272165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p234451206165628"><a name="p234451206165628"></a><a name="p234451206165628"></a><a href="sdio.md#ga52d8f25705aef184f501528faac8eaa5">SdioReadBytesFromFunc0</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002042663165628"><a name="p2002042663165628"></a><a name="p2002042663165628"></a>int32_t </p>
<p id="p1366349426165628"><a name="p1366349426165628"></a><a name="p1366349426165628"></a>Reads a given length of data from the address space of SDIO function 0. </p>
</td>
</tr>
<tr id="row185931211165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242658906165628"><a name="p242658906165628"></a><a name="p242658906165628"></a><a href="sdio.md#ga8606506dfdcb34a83f404d13c7128d5f">SdioWriteBytesToFunc0</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916019577165628"><a name="p1916019577165628"></a><a name="p1916019577165628"></a>int32_t </p>
<p id="p452268290165628"><a name="p452268290165628"></a><a name="p452268290165628"></a>Writes a given length of data into the address space of SDIO function 0. </p>
</td>
</tr>
<tr id="row93916939165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1804666149165628"><a name="p1804666149165628"></a><a name="p1804666149165628"></a><a href="sdio.md#ga4a91f3d668b99b22b3263241329ceb51">SdioSetBlockSize</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t blockSize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8955752165628"><a name="p8955752165628"></a><a name="p8955752165628"></a>int32_t </p>
<p id="p808002551165628"><a name="p808002551165628"></a><a name="p808002551165628"></a>Sets the block size. </p>
</td>
</tr>
<tr id="row1170407948165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1311294132165628"><a name="p1311294132165628"></a><a name="p1311294132165628"></a><a href="sdio.md#ga1289cc512ba56e3e904204c15d8ae23d">SdioGetCommonInfo</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, <a href="sdiocommoninfo.md">SdioCommonInfo</a> *info, <a href="sdio.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a> infoType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033948881165628"><a name="p1033948881165628"></a><a name="p1033948881165628"></a>int32_t </p>
<p id="p310525388165628"><a name="p310525388165628"></a><a name="p310525388165628"></a>Obtains common information. </p>
</td>
</tr>
<tr id="row1293769967165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p462780366165628"><a name="p462780366165628"></a><a name="p462780366165628"></a><a href="sdio.md#ga6a8eb2f6413c4685f92236dd1c8083dc">SdioSetCommonInfo</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, <a href="sdiocommoninfo.md">SdioCommonInfo</a> *info, <a href="sdio.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a> infoType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460008442165628"><a name="p460008442165628"></a><a name="p460008442165628"></a>int32_t </p>
<p id="p1906594354165628"><a name="p1906594354165628"></a><a name="p1906594354165628"></a>Sets common information. </p>
</td>
</tr>
<tr id="row1757666882165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2096883765165628"><a name="p2096883765165628"></a><a name="p2096883765165628"></a><a href="sdio.md#gad402b23097456f1116d1ac941b0f9787">SdioFlushData</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230791485165628"><a name="p1230791485165628"></a><a name="p1230791485165628"></a>int32_t </p>
<p id="p1527579294165628"><a name="p1527579294165628"></a><a name="p1527579294165628"></a>Flushes data. </p>
</td>
</tr>
<tr id="row250821186165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1536975067165628"><a name="p1536975067165628"></a><a name="p1536975067165628"></a><a href="sdio.md#ga19b0ab843f82c367ce211b794371ef00">SdioClaimHost</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695684415165628"><a name="p1695684415165628"></a><a name="p1695684415165628"></a>void </p>
<p id="p84170446165628"><a name="p84170446165628"></a><a name="p84170446165628"></a>Claims a host exclusively. </p>
</td>
</tr>
<tr id="row2128966096165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p809977874165628"><a name="p809977874165628"></a><a name="p809977874165628"></a><a href="sdio.md#ga8645ddd7f46ae24b0476f29b281e6ebf">SdioReleaseHost</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031108030165628"><a name="p2031108030165628"></a><a name="p2031108030165628"></a>void </p>
<p id="p79497075165628"><a name="p79497075165628"></a><a name="p79497075165628"></a>Releases the exclusively claimed host. </p>
</td>
</tr>
<tr id="row1808863240165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889371497165628"><a name="p889371497165628"></a><a name="p889371497165628"></a><a href="sdio.md#gae67329c260a546d7d92eb42adf5f4a5a">SdioEnableFunc</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1123448737165628"><a name="p1123448737165628"></a><a name="p1123448737165628"></a>int32_t </p>
<p id="p100366807165628"><a name="p100366807165628"></a><a name="p100366807165628"></a>Enables the SDIO device so that its register can be accessed. </p>
</td>
</tr>
<tr id="row1925172359165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107028386165628"><a name="p1107028386165628"></a><a name="p1107028386165628"></a><a href="sdio.md#ga24a4ebbf4cbad86548feb97da46549c3">SdioDisableFunc</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152422593165628"><a name="p152422593165628"></a><a name="p152422593165628"></a>int32_t </p>
<p id="p447160284165628"><a name="p447160284165628"></a><a name="p447160284165628"></a>Disables the SDIO device. </p>
</td>
</tr>
<tr id="row1910456075165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298426486165628"><a name="p1298426486165628"></a><a name="p1298426486165628"></a><a href="sdio.md#ga690a939e327e8c5cd5186e08b1b42506">SdioClaimIrq</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, <a href="sdio.md#ga858bec274683a4f50d53d1f9f43d204b">SdioIrqHandler</a> *irqHandler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457339979165628"><a name="p457339979165628"></a><a name="p457339979165628"></a>int32_t </p>
<p id="p1598711342165628"><a name="p1598711342165628"></a><a name="p1598711342165628"></a>Claims an SDIO IRQ. </p>
</td>
</tr>
<tr id="row2108150240165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149187111165628"><a name="p1149187111165628"></a><a name="p1149187111165628"></a><a href="sdio.md#gad5e826a7ff8c15d9b46b74db2dcf9243">SdioReleaseIrq</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34111852165628"><a name="p34111852165628"></a><a name="p34111852165628"></a>int32_t </p>
<p id="p1486839103165628"><a name="p1486839103165628"></a><a name="p1486839103165628"></a>Releases an SDIO IRQ. </p>
</td>
</tr>
</tbody>
</table>

