# SDIO<a name="ZH-CN_TOPIC_0000001055678042"></a>

-   [Overview](#section574200451165623)
-   [Summary](#section377336368165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section537442735165623)
-   [Typedef](#section1323710923165623)
-   [SdioIrqHandler](#ga858bec274683a4f50d53d1f9f43d204b)
-   [Enumeration Type](#section811257175165623)
-   [SdioCommonInfoType](#ga4037437ac001a9848dd242e8aa632678)
-   [Function](#section1893104624165623)
-   [SdioClaimHost\(\)](#ga19b0ab843f82c367ce211b794371ef00)
-   [SdioClaimIrq\(\)](#ga690a939e327e8c5cd5186e08b1b42506)
-   [SdioClose\(\)](#ga2e94ff04073420086e1453f125703ec7)
-   [SdioDisableFunc\(\)](#ga24a4ebbf4cbad86548feb97da46549c3)
-   [SdioEnableFunc\(\)](#gae67329c260a546d7d92eb42adf5f4a5a)
-   [SdioFlushData\(\)](#gad402b23097456f1116d1ac941b0f9787)
-   [SdioGetCommonInfo\(\)](#ga1289cc512ba56e3e904204c15d8ae23d)
-   [SdioOpen\(\)](#ga8156d7f64d72145312d92e33a532ebfd)
-   [SdioReadBytes\(\)](#ga14752ccc5cea77cfe30cfa9ab189815f)
-   [SdioReadBytesFromFixedAddr\(\)](#gabc1645bc8ab9068a13ae501efdb4a9fc)
-   [SdioReadBytesFromFunc0\(\)](#ga52d8f25705aef184f501528faac8eaa5)
-   [SdioReleaseHost\(\)](#ga8645ddd7f46ae24b0476f29b281e6ebf)
-   [SdioReleaseIrq\(\)](#gad5e826a7ff8c15d9b46b74db2dcf9243)
-   [SdioSetBlockSize\(\)](#ga4a91f3d668b99b22b3263241329ceb51)
-   [SdioSetCommonInfo\(\)](#ga6a8eb2f6413c4685f92236dd1c8083dc)
-   [SdioWriteBytes\(\)](#gaa4df7c3e2cde82f5cb7255561b99cc74)
-   [SdioWriteBytesToFixedAddr\(\)](#ga82d6b3047bd694cdbdfb0a3711797c7b)
-   [SdioWriteBytesToFunc0\(\)](#ga8606506dfdcb34a83f404d13c7128d5f)

## **Overview**<a name="section574200451165623"></a>

**Description:**

Declares standard APIs of basic secure digital input and output \(SDIO\) capabilities. 

You can use this module to access the SDIO and enable the driver to operate an SDIO-compliant device. These capabilities include reading and writing data based on SDIO, setting the block size, applying for and releasing interrupts, enabling and disabling devices, and occupying and releasing the bus.

**Since:**

1.0

## **Summary**<a name="section377336368165623"></a>

## Files<a name="files"></a>

<a name="table986221237165623"></a>
<table><thead align="left"><tr id="row886983129165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1957558412165623"><a name="p1957558412165623"></a><a name="p1957558412165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1285539435165623"><a name="p1285539435165623"></a><a name="p1285539435165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row557345929165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755141773165623"><a name="p755141773165623"></a><a name="p755141773165623"></a><a href="sdio_if-h.md">sdio_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1792229698165623"><a name="p1792229698165623"></a><a name="p1792229698165623"></a>Declares the standard SDIO APIs. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table2048894474165623"></a>
<table><thead align="left"><tr id="row2095118610165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p31856665165623"><a name="p31856665165623"></a><a name="p31856665165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1496690208165623"><a name="p1496690208165623"></a><a name="p1496690208165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row166334501165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p119337945165623"><a name="p119337945165623"></a><a name="p119337945165623"></a><a href="SdioFuncInfo.md">SdioFuncInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p617136252165623"><a name="p617136252165623"></a><a name="p617136252165623"></a>Defines the SDIO capabilities. </p>
</td>
</tr>
<tr id="row1864286746165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p436346882165623"><a name="p436346882165623"></a><a name="p436346882165623"></a><a href="SdioCommonInfo.md">SdioCommonInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1626242590165623"><a name="p1626242590165623"></a><a name="p1626242590165623"></a>Defines SDIO common information. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1339185210165623"></a>
<table><thead align="left"><tr id="row806986394165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1022837272165623"><a name="p1022837272165623"></a><a name="p1022837272165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2040684371165623"><a name="p2040684371165623"></a><a name="p2040684371165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row27645018165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203224968165623"><a name="p203224968165623"></a><a name="p203224968165623"></a><a href="SDIO.md#ga858bec274683a4f50d53d1f9f43d204b">SdioIrqHandler</a>(void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534552555165623"><a name="p1534552555165623"></a><a name="p1534552555165623"></a>typedef void </p>
<p id="p158712715165623"><a name="p158712715165623"></a><a name="p158712715165623"></a>Defines the function type of an SDIO IRQ. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table212331176165623"></a>
<table><thead align="left"><tr id="row1315978886165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1957515487165623"><a name="p1957515487165623"></a><a name="p1957515487165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1611120742165623"><a name="p1611120742165623"></a><a name="p1611120742165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1831072442165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600061489165623"><a name="p1600061489165623"></a><a name="p1600061489165623"></a><a href="SDIO.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a> { <a href="SDIO.md#gga4037437ac001a9848dd242e8aa632678aa4e25cb3b51d47da78d6b58d11d946cd">SDIO_FUNC_INFO</a> = 0, <a href="SDIO.md#gga4037437ac001a9848dd242e8aa632678a7aa994f868190924d0bf354c1bb0d67b">SDIO_OTHER_INFO</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283918432165623"><a name="p1283918432165623"></a><a name="p1283918432165623"></a>Enumerates SDIO common information types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table2003822821165623"></a>
<table><thead align="left"><tr id="row22278725165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1714620472165623"><a name="p1714620472165623"></a><a name="p1714620472165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1315801031165623"><a name="p1315801031165623"></a><a name="p1315801031165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1450924438165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1299518398165623"><a name="p1299518398165623"></a><a name="p1299518398165623"></a><a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a> (int16_t busNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861264510165623"><a name="p861264510165623"></a><a name="p861264510165623"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1710840215165623"><a name="p1710840215165623"></a><a name="p1710840215165623"></a>Opens an SDIO controller with a specified bus number. </p>
</td>
</tr>
<tr id="row2143401484165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1057020380165623"><a name="p1057020380165623"></a><a name="p1057020380165623"></a><a href="SDIO.md#ga2e94ff04073420086e1453f125703ec7">SdioClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770734141165623"><a name="p770734141165623"></a><a name="p770734141165623"></a>void </p>
<p id="p1171011953165623"><a name="p1171011953165623"></a><a name="p1171011953165623"></a>Closes an SDIO controller. </p>
</td>
</tr>
<tr id="row1245712609165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p748847606165623"><a name="p748847606165623"></a><a name="p748847606165623"></a><a href="SDIO.md#ga14752ccc5cea77cfe30cfa9ab189815f">SdioReadBytes</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985580640165623"><a name="p1985580640165623"></a><a name="p1985580640165623"></a>int32_t </p>
<p id="p1977497580165623"><a name="p1977497580165623"></a><a name="p1977497580165623"></a>Incrementally reads a given length of data from the specified SDIO address. </p>
</td>
</tr>
<tr id="row953312486165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894635420165623"><a name="p894635420165623"></a><a name="p894635420165623"></a><a href="SDIO.md#gaa4df7c3e2cde82f5cb7255561b99cc74">SdioWriteBytes</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1107924381165623"><a name="p1107924381165623"></a><a name="p1107924381165623"></a>int32_t </p>
<p id="p2088231413165623"><a name="p2088231413165623"></a><a name="p2088231413165623"></a>Incrementally writes a given length of data into the specified SDIO address. </p>
</td>
</tr>
<tr id="row2021052812165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635620968165623"><a name="p1635620968165623"></a><a name="p1635620968165623"></a><a href="SDIO.md#gabc1645bc8ab9068a13ae501efdb4a9fc">SdioReadBytesFromFixedAddr</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1366420216165623"><a name="p1366420216165623"></a><a name="p1366420216165623"></a>int32_t </p>
<p id="p1256378159165623"><a name="p1256378159165623"></a><a name="p1256378159165623"></a>Reads a given length of data from the fixed SDIO address. </p>
</td>
</tr>
<tr id="row1515425020165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1481754140165623"><a name="p1481754140165623"></a><a name="p1481754140165623"></a><a href="SDIO.md#ga82d6b3047bd694cdbdfb0a3711797c7b">SdioWriteBytesToFixedAddr</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459451335165623"><a name="p459451335165623"></a><a name="p459451335165623"></a>int32_t </p>
<p id="p1862471103165623"><a name="p1862471103165623"></a><a name="p1862471103165623"></a>Writes a given length of data into the fixed SDIO address. </p>
</td>
</tr>
<tr id="row620935283165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1598477005165623"><a name="p1598477005165623"></a><a name="p1598477005165623"></a><a href="SDIO.md#ga52d8f25705aef184f501528faac8eaa5">SdioReadBytesFromFunc0</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1644175825165623"><a name="p1644175825165623"></a><a name="p1644175825165623"></a>int32_t </p>
<p id="p223085304165623"><a name="p223085304165623"></a><a name="p223085304165623"></a>Reads a given length of data from the address space of SDIO function 0. </p>
</td>
</tr>
<tr id="row2024384380165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14441526165623"><a name="p14441526165623"></a><a name="p14441526165623"></a><a href="SDIO.md#ga8606506dfdcb34a83f404d13c7128d5f">SdioWriteBytesToFunc0</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t *data, uint32_t addr, uint32_t size, uint32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1074951509165623"><a name="p1074951509165623"></a><a name="p1074951509165623"></a>int32_t </p>
<p id="p1295711130165623"><a name="p1295711130165623"></a><a name="p1295711130165623"></a>Writes a given length of data into the address space of SDIO function 0. </p>
</td>
</tr>
<tr id="row1266793641165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p615319046165623"><a name="p615319046165623"></a><a name="p615319046165623"></a><a href="SDIO.md#ga4a91f3d668b99b22b3263241329ceb51">SdioSetBlockSize</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t blockSize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130666234165623"><a name="p1130666234165623"></a><a name="p1130666234165623"></a>int32_t </p>
<p id="p803215196165623"><a name="p803215196165623"></a><a name="p803215196165623"></a>Sets the block size. </p>
</td>
</tr>
<tr id="row1778332383165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286198858165623"><a name="p1286198858165623"></a><a name="p1286198858165623"></a><a href="SDIO.md#ga1289cc512ba56e3e904204c15d8ae23d">SdioGetCommonInfo</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, <a href="SdioCommonInfo.md">SdioCommonInfo</a> *info, <a href="SDIO.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a> infoType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312451751165623"><a name="p1312451751165623"></a><a name="p1312451751165623"></a>int32_t </p>
<p id="p549547990165623"><a name="p549547990165623"></a><a name="p549547990165623"></a>Obtains common information. </p>
</td>
</tr>
<tr id="row380042605165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990462324165623"><a name="p990462324165623"></a><a name="p990462324165623"></a><a href="SDIO.md#ga6a8eb2f6413c4685f92236dd1c8083dc">SdioSetCommonInfo</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, <a href="SdioCommonInfo.md">SdioCommonInfo</a> *info, <a href="SDIO.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a> infoType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p253298359165623"><a name="p253298359165623"></a><a name="p253298359165623"></a>int32_t </p>
<p id="p421757045165623"><a name="p421757045165623"></a><a name="p421757045165623"></a>Sets common information. </p>
</td>
</tr>
<tr id="row246352194165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1426823935165623"><a name="p1426823935165623"></a><a name="p1426823935165623"></a><a href="SDIO.md#gad402b23097456f1116d1ac941b0f9787">SdioFlushData</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787968944165623"><a name="p787968944165623"></a><a name="p787968944165623"></a>int32_t </p>
<p id="p108528907165623"><a name="p108528907165623"></a><a name="p108528907165623"></a>Flushes data. </p>
</td>
</tr>
<tr id="row394728062165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p361096122165623"><a name="p361096122165623"></a><a name="p361096122165623"></a><a href="SDIO.md#ga19b0ab843f82c367ce211b794371ef00">SdioClaimHost</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1431241711165623"><a name="p1431241711165623"></a><a name="p1431241711165623"></a>void </p>
<p id="p1719678288165623"><a name="p1719678288165623"></a><a name="p1719678288165623"></a>Claims a host exclusively. </p>
</td>
</tr>
<tr id="row846532727165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p895576012165623"><a name="p895576012165623"></a><a name="p895576012165623"></a><a href="SDIO.md#ga8645ddd7f46ae24b0476f29b281e6ebf">SdioReleaseHost</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909013851165623"><a name="p909013851165623"></a><a name="p909013851165623"></a>void </p>
<p id="p94405364165623"><a name="p94405364165623"></a><a name="p94405364165623"></a>Releases the exclusively claimed host. </p>
</td>
</tr>
<tr id="row2132953662165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1986227548165623"><a name="p1986227548165623"></a><a name="p1986227548165623"></a><a href="SDIO.md#gae67329c260a546d7d92eb42adf5f4a5a">SdioEnableFunc</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555556918165623"><a name="p1555556918165623"></a><a name="p1555556918165623"></a>int32_t </p>
<p id="p1387159638165623"><a name="p1387159638165623"></a><a name="p1387159638165623"></a>Enables the SDIO device so that its register can be accessed. </p>
</td>
</tr>
<tr id="row340273960165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616403260165623"><a name="p616403260165623"></a><a name="p616403260165623"></a><a href="SDIO.md#ga24a4ebbf4cbad86548feb97da46549c3">SdioDisableFunc</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2089797413165623"><a name="p2089797413165623"></a><a name="p2089797413165623"></a>int32_t </p>
<p id="p320080644165623"><a name="p320080644165623"></a><a name="p320080644165623"></a>Disables the SDIO device. </p>
</td>
</tr>
<tr id="row1187551391165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1881148228165623"><a name="p1881148228165623"></a><a name="p1881148228165623"></a><a href="SDIO.md#ga690a939e327e8c5cd5186e08b1b42506">SdioClaimIrq</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, <a href="SDIO.md#ga858bec274683a4f50d53d1f9f43d204b">SdioIrqHandler</a> *irqHandler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p205234095165623"><a name="p205234095165623"></a><a name="p205234095165623"></a>int32_t </p>
<p id="p83343748165623"><a name="p83343748165623"></a><a name="p83343748165623"></a>Claims an SDIO IRQ. </p>
</td>
</tr>
<tr id="row2003646673165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817350952165623"><a name="p1817350952165623"></a><a name="p1817350952165623"></a><a href="SDIO.md#gad5e826a7ff8c15d9b46b74db2dcf9243">SdioReleaseIrq</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2011496744165623"><a name="p2011496744165623"></a><a name="p2011496744165623"></a>int32_t </p>
<p id="p655385193165623"><a name="p655385193165623"></a><a name="p655385193165623"></a>Releases an SDIO IRQ. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section537442735165623"></a>

## **Typedef **<a name="section1323710923165623"></a>

## SdioIrqHandler<a name="ga858bec274683a4f50d53d1f9f43d204b"></a>

```
typedef void SdioIrqHandler(void *)
```

 **Description:**

Defines the function type of an SDIO IRQ. 

This function is registered when you call  [SdioClaimIrq](SDIO.md#ga690a939e327e8c5cd5186e08b1b42506)  to request the SDIO IRQ.

**Parameters:**

<a name="table1983078901165623"></a>
<table><thead align="left"><tr id="row1236993490165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p172004519165623"><a name="p172004519165623"></a><a name="p172004519165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1387064222165623"><a name="p1387064222165623"></a><a name="p1387064222165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1839151679165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the private data passed to this IRQ (The data is specified when the IRQ is registered).</td>
</tr>
</tbody>
</table>

## **Enumeration Type **<a name="section811257175165623"></a>

## SdioCommonInfoType<a name="ga4037437ac001a9848dd242e8aa632678"></a>

```
enum [SdioCommonInfoType](SDIO.md#ga4037437ac001a9848dd242e8aa632678)
```

 **Description:**

Enumerates SDIO common information types. 

When obtaining SDIO common information by calling  [SdioGetCommonInfo](SDIO.md#ga1289cc512ba56e3e904204c15d8ae23d)  or setting the information by calling  [SdioSetCommonInfo](SDIO.md#ga6a8eb2f6413c4685f92236dd1c8083dc), you need to pass the information type. 

<a name="table1757599835165623"></a>
<table><thead align="left"><tr id="row342018726165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1368620846165623"><a name="p1368620846165623"></a><a name="p1368620846165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1246141046165623"><a name="p1246141046165623"></a><a name="p1246141046165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row753479674165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4037437ac001a9848dd242e8aa632678aa4e25cb3b51d47da78d6b58d11d946cd"><a name="gga4037437ac001a9848dd242e8aa632678aa4e25cb3b51d47da78d6b58d11d946cd"></a><a name="gga4037437ac001a9848dd242e8aa632678aa4e25cb3b51d47da78d6b58d11d946cd"></a></strong>SDIO_FUNC_INFO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1704277581165623"><a name="p1704277581165623"></a><a name="p1704277581165623"></a>Functionality information </p>
 </td>
</tr>
<tr id="row1689344624165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4037437ac001a9848dd242e8aa632678a7aa994f868190924d0bf354c1bb0d67b"><a name="gga4037437ac001a9848dd242e8aa632678a7aa994f868190924d0bf354c1bb0d67b"></a><a name="gga4037437ac001a9848dd242e8aa632678a7aa994f868190924d0bf354c1bb0d67b"></a></strong>SDIO_OTHER_INFO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153865652165623"><a name="p1153865652165623"></a><a name="p1153865652165623"></a>Other information </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1893104624165623"></a>

## SdioClaimHost\(\)<a name="ga19b0ab843f82c367ce211b794371ef00"></a>

```
void SdioClaimHost ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Claims a host exclusively. 

You can call this function to enable the SDIO module to exclusively claim a host and then perform operations on the devices connected to the host. After performing required operations, release the host by calling  [SdioReleaseHost](SDIO.md#ga8645ddd7f46ae24b0476f29b281e6ebf).

**Parameters:**

<a name="table63818903165623"></a>
<table><thead align="left"><tr id="row1564819830165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1187103731165623"><a name="p1187103731165623"></a><a name="p1187103731165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1875428027165623"><a name="p1875428027165623"></a><a name="p1875428027165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row496645518165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>.</td>
</tr>
</tbody>
</table>

## SdioClaimIrq\(\)<a name="ga690a939e327e8c5cd5186e08b1b42506"></a>

```
int32_t SdioClaimIrq ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, [SdioIrqHandler](SDIO.md#ga858bec274683a4f50d53d1f9f43d204b) * irqHandler )
```

 **Description:**

Claims an SDIO IRQ. 

When there is data, commands, or events, the IRQ function is executed.

**Parameters:**

<a name="table2070473555165623"></a>
<table><thead align="left"><tr id="row992200897165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p790960969165623"><a name="p790960969165623"></a><a name="p790960969165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1008901164165623"><a name="p1008901164165623"></a><a name="p1008901164165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row454002953165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row414271698165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">irqHandler</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the SDIO IRQ function. For details, see <a href="SDIO.md#ga858bec274683a4f50d53d1f9f43d204b">SdioIrqHandler</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioClose\(\)<a name="ga2e94ff04073420086e1453f125703ec7"></a>

```
void SdioClose ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Closes an SDIO controller. 

After the SDIO interface is used, you can close the SDIO controller by calling  [SdioClose](SDIO.md#ga2e94ff04073420086e1453f125703ec7). This function is used in pair with  [SdioOpen](SDIO.md#ga8156d7f64d72145312d92e33a532ebfd).

**Parameters:**

<a name="table522488319165623"></a>
<table><thead align="left"><tr id="row2030074892165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p553356562165623"><a name="p553356562165623"></a><a name="p553356562165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p165619356165623"><a name="p165619356165623"></a><a name="p165619356165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1484748798165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller.</td>
</tr>
</tbody>
</table>

## SdioDisableFunc\(\)<a name="ga24a4ebbf4cbad86548feb97da46549c3"></a>

```
int32_t SdioDisableFunc ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Disables the SDIO device. 

This function is used in pair with  [SdioEnableFunc](SDIO.md#gae67329c260a546d7d92eb42adf5f4a5a).

**Parameters:**

<a name="table1004860225165623"></a>
<table><thead align="left"><tr id="row1213992781165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p362289654165623"><a name="p362289654165623"></a><a name="p362289654165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2078598512165623"><a name="p2078598512165623"></a><a name="p2078598512165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1952190578165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioEnableFunc\(\)<a name="gae67329c260a546d7d92eb42adf5f4a5a"></a>

```
int32_t SdioEnableFunc ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Enables the SDIO device so that its register can be accessed. 

**Parameters:**

<a name="table710239336165623"></a>
<table><thead align="left"><tr id="row1748058891165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74916699165623"><a name="p74916699165623"></a><a name="p74916699165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2104704767165623"><a name="p2104704767165623"></a><a name="p2104704767165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2073493334165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioFlushData\(\)<a name="gad402b23097456f1116d1ac941b0f9787"></a>

```
int32_t SdioFlushData ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Flushes data. 

You can call this function when an SDIO needs to be reinitialized or an unexpected error occurs.

**Parameters:**

<a name="table686464540165623"></a>
<table><thead align="left"><tr id="row1570228264165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p546208772165623"><a name="p546208772165623"></a><a name="p546208772165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p82617535165623"><a name="p82617535165623"></a><a name="p82617535165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row505080609165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioGetCommonInfo\(\)<a name="ga1289cc512ba56e3e904204c15d8ae23d"></a>

```
int32_t SdioGetCommonInfo ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, [SdioCommonInfo](SdioCommonInfo.md) * info, [SdioCommonInfoType](SDIO.md#ga4037437ac001a9848dd242e8aa632678) infoType )
```

 **Description:**

Obtains common information. 

You can call this function to obtain the capabilities and private data of the I/O function.

**Parameters:**

<a name="table1580324664165623"></a>
<table><thead align="left"><tr id="row431054161165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p199247517165623"><a name="p199247517165623"></a><a name="p199247517165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1718198699165623"><a name="p1718198699165623"></a><a name="p1718198699165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row941975671165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row1341080768165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the common information to be obtained. For details, see <a href="SdioCommonInfo.md">SdioCommonInfo</a>. </td>
</tr>
<tr id="row784542835165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">infoType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the common information to be obtained. For details, see <a href="SDIO.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioOpen\(\)<a name="ga8156d7f64d72145312d92e33a532ebfd"></a>

```
[DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) SdioOpen (int16_t busNum)
```

 **Description:**

Opens an SDIO controller with a specified bus number. 

Before using the SDIO interface, you can obtain the device handle of the SDIO controller by calling  [SdioOpen](SDIO.md#ga8156d7f64d72145312d92e33a532ebfd). This function is used in pair with  [SdioClose](SDIO.md#ga2e94ff04073420086e1453f125703ec7).

**Parameters:**

<a name="table723640212165623"></a>
<table><thead align="left"><tr id="row1159345508165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1734989393165623"><a name="p1734989393165623"></a><a name="p1734989393165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p574755149165623"><a name="p574755149165623"></a><a name="p574755149165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row843408316165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">busNum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the bus number.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the device handle  [DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041)  of the SDIO controller if the operation is successful; returns  **NULL**  otherwise. 

## SdioReadBytes\(\)<a name="ga14752ccc5cea77cfe30cfa9ab189815f"></a>

```
int32_t SdioReadBytes ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t addr, uint32_t size, uint32_t timeOut )
```

 **Description:**

Incrementally reads a given length of data from the specified SDIO address. 

If the length of the data to read is greater than the size of a block, the data is read by block, and the remaining data that is smaller than one block is read by byte. Otherwise, data is read by byte.

**Parameters:**

<a name="table734309206165623"></a>
<table><thead align="left"><tr id="row771788394165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1535408736165623"><a name="p1535408736165623"></a><a name="p1535408736165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1529995826165623"><a name="p1529995826165623"></a><a name="p1529995826165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1152546768165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row346772710165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to read. </td>
</tr>
<tr id="row185297589165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start address of the data to read. </td>
</tr>
<tr id="row1560632268165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to read. </td>
</tr>
<tr id="row827496800165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for reading data, in milliseconds. If the value is <strong id="b826241777165623"><a name="b826241777165623"></a><a name="b826241777165623"></a>0</strong>,the default value is used. The default value varies according to the application. Generally, the default value is <strong id="b1153475438165623"><a name="b1153475438165623"></a><a name="b1153475438165623"></a>1</strong> second.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioReadBytesFromFixedAddr\(\)<a name="gabc1645bc8ab9068a13ae501efdb4a9fc"></a>

```
int32_t SdioReadBytesFromFixedAddr ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t addr, uint32_t size, uint32_t timeOut )
```

 **Description:**

Reads a given length of data from the fixed SDIO address. 

If the length of the data to read is greater than the size of a block, the data is read by block, and the remaining data that is smaller than one block is read by byte. Otherwise, data is read by byte.

**Parameters:**

<a name="table747985921165623"></a>
<table><thead align="left"><tr id="row859609954165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p103637157165623"><a name="p103637157165623"></a><a name="p103637157165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1738351321165623"><a name="p1738351321165623"></a><a name="p1738351321165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1581812917165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row1594202780165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to read. </td>
</tr>
<tr id="row851323451165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the fixed address of the data to read. </td>
</tr>
<tr id="row398141579165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to read. </td>
</tr>
<tr id="row1391988935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for reading data, in milliseconds. If the value is <strong id="b775350294165623"><a name="b775350294165623"></a><a name="b775350294165623"></a>0</strong>, the default value is used. The default value varies according to the application. Generally, the default value is <strong id="b718620928165623"><a name="b718620928165623"></a><a name="b718620928165623"></a>1</strong> second.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioReadBytesFromFunc0\(\)<a name="ga52d8f25705aef184f501528faac8eaa5"></a>

```
int32_t SdioReadBytesFromFunc0 ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t addr, uint32_t size, uint32_t timeOut )
```

 **Description:**

Reads a given length of data from the address space of SDIO function 0. 

Currently, only one byte of data can be read.

**Parameters:**

<a name="table1259690628165623"></a>
<table><thead align="left"><tr id="row904537350165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p370091099165623"><a name="p370091099165623"></a><a name="p370091099165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1251946945165623"><a name="p1251946945165623"></a><a name="p1251946945165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2012593848165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row634110278165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to read. </td>
</tr>
<tr id="row807308925165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start address of the data to read. </td>
</tr>
<tr id="row39715990165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to read. </td>
</tr>
<tr id="row1556419659165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for reading data, in milliseconds. If the value is <strong id="b1489287523165623"><a name="b1489287523165623"></a><a name="b1489287523165623"></a>0</strong>, the default value is used. The default value varies according to the application. Generally, the default value is <strong id="b282340586165623"><a name="b282340586165623"></a><a name="b282340586165623"></a>1</strong> second.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioReleaseHost\(\)<a name="ga8645ddd7f46ae24b0476f29b281e6ebf"></a>

```
void SdioReleaseHost ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Releases the exclusively claimed host. 

This function is used in pair with  [SdioClaimHost](SDIO.md#ga19b0ab843f82c367ce211b794371ef00).

**Parameters:**

<a name="table709625329165623"></a>
<table><thead align="left"><tr id="row1897462979165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p954652629165623"><a name="p954652629165623"></a><a name="p954652629165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p830810890165623"><a name="p830810890165623"></a><a name="p830810890165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1239258723165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>.</td>
</tr>
</tbody>
</table>

## SdioReleaseIrq\(\)<a name="gad5e826a7ff8c15d9b46b74db2dcf9243"></a>

```
int32_t SdioReleaseIrq ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Releases an SDIO IRQ. 

This function is used in pair with  [SdioClaimIrq](SDIO.md#ga690a939e327e8c5cd5186e08b1b42506).

**Parameters:**

<a name="table1568673743165623"></a>
<table><thead align="left"><tr id="row1785089082165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2130586496165623"><a name="p2130586496165623"></a><a name="p2130586496165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1747239512165623"><a name="p1747239512165623"></a><a name="p1747239512165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1133646879165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioSetBlockSize\(\)<a name="ga4a91f3d668b99b22b3263241329ceb51"></a>

```
int32_t SdioSetBlockSize ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t blockSize )
```

 **Description:**

Sets the block size. 

If data to read or write is performed, use this function to set the block size.

**Parameters:**

<a name="table577788248165623"></a>
<table><thead align="left"><tr id="row474840570165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p205807803165623"><a name="p205807803165623"></a><a name="p205807803165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p897590436165623"><a name="p897590436165623"></a><a name="p897590436165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1165944712165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row1639660921165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">blockSize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the block size to be set. If the value is <strong id="b2105429168165623"><a name="b2105429168165623"></a><a name="b2105429168165623"></a>0</strong>, the default value is used. The value ranges from <strong id="b457890385165623"><a name="b457890385165623"></a><a name="b457890385165623"></a>1</strong> to <strong id="b1644186531165623"><a name="b1644186531165623"></a><a name="b1644186531165623"></a>2048</strong> bytes.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioSetCommonInfo\(\)<a name="ga6a8eb2f6413c4685f92236dd1c8083dc"></a>

```
int32_t SdioSetCommonInfo ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, [SdioCommonInfo](SdioCommonInfo.md) * info, [SdioCommonInfoType](SDIO.md#ga4037437ac001a9848dd242e8aa632678) infoType )
```

 **Description:**

Sets common information. 

You can call this function to set the maximum timeout duration and private data.

**Parameters:**

<a name="table1341278384165623"></a>
<table><thead align="left"><tr id="row1571516786165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1383000837165623"><a name="p1383000837165623"></a><a name="p1383000837165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1827380594165623"><a name="p1827380594165623"></a><a name="p1827380594165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2044920154165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row8139831165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the common information to be set. For details, see <a href="SdioCommonInfo.md">SdioCommonInfo</a>. </td>
</tr>
<tr id="row232193581165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">infoType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the common information to be set. For details, see <a href="SDIO.md#ga4037437ac001a9848dd242e8aa632678">SdioCommonInfoType</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioWriteBytes\(\)<a name="gaa4df7c3e2cde82f5cb7255561b99cc74"></a>

```
int32_t SdioWriteBytes ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t addr, uint32_t size, uint32_t timeOut )
```

 **Description:**

Incrementally writes a given length of data into the specified SDIO address. 

If the length of the data to write is greater than the size of a block, the data is written by block first, and the remaining data that is smaller than one block is written by byte. Otherwise, data is written by byte.

**Parameters:**

<a name="table1664789481165623"></a>
<table><thead align="left"><tr id="row1090721891165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p237378288165623"><a name="p237378288165623"></a><a name="p237378288165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1945893057165623"><a name="p1945893057165623"></a><a name="p1945893057165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1510401959165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row1610796001165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to write. </td>
</tr>
<tr id="row488680877165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start address of the data to write. </td>
</tr>
<tr id="row2058432917165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to write. </td>
</tr>
<tr id="row371689130165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for writing data, in milliseconds. If the value is <strong id="b1226811430165623"><a name="b1226811430165623"></a><a name="b1226811430165623"></a>0</strong>, the default value is used. The default value varies according to the application. Generally, the default value is <strong id="b1923253086165623"><a name="b1923253086165623"></a><a name="b1923253086165623"></a>1</strong> second.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioWriteBytesToFixedAddr\(\)<a name="ga82d6b3047bd694cdbdfb0a3711797c7b"></a>

```
int32_t SdioWriteBytesToFixedAddr ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t addr, uint32_t size, uint32_t timeOut )
```

 **Description:**

Writes a given length of data into the fixed SDIO address. 

If the length of the data to write is greater than the size of a block, the data is written by block first, and the remaining data that is smaller than one block is written by byte. Otherwise, data is written by byte.

**Parameters:**

<a name="table1778205137165623"></a>
<table><thead align="left"><tr id="row327257812165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1943538284165623"><a name="p1943538284165623"></a><a name="p1943538284165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p997329226165623"><a name="p997329226165623"></a><a name="p997329226165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1371056400165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row1801160123165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to write. </td>
</tr>
<tr id="row2067081364165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the fixed address of the data to write. </td>
</tr>
<tr id="row519581404165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to write. </td>
</tr>
<tr id="row179973676165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for writing data, in milliseconds. If the value is <strong id="b1393741218165623"><a name="b1393741218165623"></a><a name="b1393741218165623"></a>0</strong>, the default value is used. The default value varies according to the application. Generally, the default value is <strong id="b473606974165623"><a name="b473606974165623"></a><a name="b473606974165623"></a>1</strong> second.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

## SdioWriteBytesToFunc0\(\)<a name="ga8606506dfdcb34a83f404d13c7128d5f"></a>

```
int32_t SdioWriteBytesToFunc0 ([DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t * data, uint32_t addr, uint32_t size, uint32_t timeOut )
```

 **Description:**

Writes a given length of data into the address space of SDIO function 0. 

Currently, only one byte of data can be written.

**Parameters:**

<a name="table248654622165623"></a>
<table><thead align="left"><tr id="row188698777165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1795425820165623"><a name="p1795425820165623"></a><a name="p1795425820165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1057774854165623"><a name="p1057774854165623"></a><a name="p1057774854165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1420115971165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device handle of the SDIO controller obtained by <a href="SDIO.md#ga8156d7f64d72145312d92e33a532ebfd">SdioOpen</a>. </td>
</tr>
<tr id="row1305599542165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to write. </td>
</tr>
<tr id="row815473133165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start address of the data to write. </td>
</tr>
<tr id="row42717216165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data to write. </td>
</tr>
<tr id="row453283983165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for writing data, in milliseconds. If the value is <strong id="b692214465165623"><a name="b692214465165623"></a><a name="b692214465165623"></a>0</strong>, the default value is used. The default value varies according to the application. Generally, the default value is <strong id="b864132024165623"><a name="b864132024165623"></a><a name="b864132024165623"></a>1</strong> second.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. 

