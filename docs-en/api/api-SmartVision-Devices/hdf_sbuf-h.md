# hdf\_sbuf.h<a name="EN-US_TOPIC_0000001055039486"></a>

-   [Overview](#section1524808677165627)
-   [Summary](#section1506980006165627)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1524808677165627"></a>

**Related Modules:**

[Core](core.md)

**Description:**

Defines functions related to a  **[HdfSBuf](hdfsbuf.md)**. The HDF provides data serialization and deserialization capabilities for data transmission between user-mode applications and kernel-mode drivers. 

**Since:**

1.0

## **Summary**<a name="section1506980006165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table671727679165627"></a>
<table><thead align="left"><tr id="row1719022888165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1847281259165627"><a name="p1847281259165627"></a><a name="p1847281259165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p671684334165627"><a name="p671684334165627"></a><a name="p671684334165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row243236168165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1529701812165627"><a name="p1529701812165627"></a><a name="p1529701812165627"></a><a href="hdfsbuf.md">HdfSBuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812210415165627"><a name="p812210415165627"></a><a name="p812210415165627"></a>Defines a <strong id="b1085058623165627"><a name="b1085058623165627"></a><a name="b1085058623165627"></a><a href="hdfsbuf.md">HdfSBuf</a></strong>. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table2013059265165627"></a>
<table><thead align="left"><tr id="row1271263659165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1631909901165627"><a name="p1631909901165627"></a><a name="p1631909901165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p498948483165627"><a name="p498948483165627"></a><a name="p498948483165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1492643998165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249188867165627"><a name="p249188867165627"></a><a name="p249188867165627"></a><a href="core.md#ga567eb533aa53051d0beec43f08e72dd8">HdfSbufWriteBuffer</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, const void *data, uint32_t writeSize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282594590165627"><a name="p1282594590165627"></a><a name="p1282594590165627"></a>bool </p>
<p id="p181894699165627"><a name="p181894699165627"></a><a name="p181894699165627"></a>Writes a data segment to a <strong id="b1485697654165627"><a name="b1485697654165627"></a><a name="b1485697654165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1839686968165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p322110164165627"><a name="p322110164165627"></a><a name="p322110164165627"></a><a href="core.md#ga164de95ad00302b599290bdb476a032f">HdfSbufWriteUint64</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305771665165627"><a name="p1305771665165627"></a><a name="p1305771665165627"></a>bool </p>
<p id="p595295751165627"><a name="p595295751165627"></a><a name="p595295751165627"></a>Writes a 64-bit unsigned integer to a <strong id="b767670483165627"><a name="b767670483165627"></a><a name="b767670483165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row309631145165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1431933798165627"><a name="p1431933798165627"></a><a name="p1431933798165627"></a><a href="core.md#ga23f2331cdfb0bf91a29f47f20ffd50df">HdfSbufWriteUint32</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465157997165627"><a name="p465157997165627"></a><a name="p465157997165627"></a>bool </p>
<p id="p714412955165627"><a name="p714412955165627"></a><a name="p714412955165627"></a>Writes a 32-bit unsigned integer to a <strong id="b1614454640165627"><a name="b1614454640165627"></a><a name="b1614454640165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row246614721165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2007948705165627"><a name="p2007948705165627"></a><a name="p2007948705165627"></a><a href="core.md#ga31c9edfd9b20d6e44d34839efa0e08f7">HdfSbufWriteUint16</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638112598165627"><a name="p1638112598165627"></a><a name="p1638112598165627"></a>bool </p>
<p id="p2077171512165627"><a name="p2077171512165627"></a><a name="p2077171512165627"></a>Writes a 16-bit unsigned integer to a <strong id="b466700345165627"><a name="b466700345165627"></a><a name="b466700345165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row937963519165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111986209165627"><a name="p1111986209165627"></a><a name="p1111986209165627"></a><a href="core.md#gafb4fe74246f85a158c140bf4c4951256">HdfSbufWriteUint8</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint8_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p757255629165627"><a name="p757255629165627"></a><a name="p757255629165627"></a>bool </p>
<p id="p1018660076165627"><a name="p1018660076165627"></a><a name="p1018660076165627"></a>Writes an 8-bit unsigned integer to a <strong id="b1957580281165627"><a name="b1957580281165627"></a><a name="b1957580281165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row338087010165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930950710165627"><a name="p930950710165627"></a><a name="p930950710165627"></a><a href="core.md#ga7c63eb006b19e2aac43c23318c4ebe3b">HdfSbufWriteInt64</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p660591975165627"><a name="p660591975165627"></a><a name="p660591975165627"></a>bool </p>
<p id="p405152379165627"><a name="p405152379165627"></a><a name="p405152379165627"></a>Writes a 64-bit signed integer to a <strong id="b819705735165627"><a name="b819705735165627"></a><a name="b819705735165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1842163715165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p157102181165627"><a name="p157102181165627"></a><a name="p157102181165627"></a><a href="core.md#ga3913510d670da2f8ffa3103b5ff293f1">HdfSbufWriteInt32</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1289575351165627"><a name="p1289575351165627"></a><a name="p1289575351165627"></a>bool </p>
<p id="p478058380165627"><a name="p478058380165627"></a><a name="p478058380165627"></a>Writes a 32-bit signed integer to a <strong id="b1248073134165627"><a name="b1248073134165627"></a><a name="b1248073134165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1353182650165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74438199165627"><a name="p74438199165627"></a><a name="p74438199165627"></a><a href="core.md#gaaa278bf9aa182a4c65c390c6c9ff06d2">HdfSbufWriteInt16</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p292484673165627"><a name="p292484673165627"></a><a name="p292484673165627"></a>bool </p>
<p id="p811514857165627"><a name="p811514857165627"></a><a name="p811514857165627"></a>Writes a 16-bit signed integer to a <strong id="b1983646572165627"><a name="b1983646572165627"></a><a name="b1983646572165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1357365405165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614741938165627"><a name="p614741938165627"></a><a name="p614741938165627"></a><a href="core.md#gac514c3debd605043ad1bfa9c05a115a0">HdfSbufWriteInt8</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int8_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1527868789165627"><a name="p1527868789165627"></a><a name="p1527868789165627"></a>bool </p>
<p id="p1099146503165627"><a name="p1099146503165627"></a><a name="p1099146503165627"></a>Writes an 8-bit signed integer to a <strong id="b644499396165627"><a name="b644499396165627"></a><a name="b644499396165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1408158022165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p897221966165627"><a name="p897221966165627"></a><a name="p897221966165627"></a><a href="core.md#gaf782f8a08dcd81f4038ab9d9bbc1cf9b">HdfSbufWriteString</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360378471165627"><a name="p360378471165627"></a><a name="p360378471165627"></a>bool </p>
<p id="p1382722846165627"><a name="p1382722846165627"></a><a name="p1382722846165627"></a>Writes a string to a <strong id="b481226986165627"><a name="b481226986165627"></a><a name="b481226986165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1512395628165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p363840523165627"><a name="p363840523165627"></a><a name="p363840523165627"></a><a href="core.md#ga345e8524a6cea44a0424e23b8f659792">HdfSbufReadBuffer</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, const void **data, uint32_t *readSize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203584065165627"><a name="p1203584065165627"></a><a name="p1203584065165627"></a>bool </p>
<p id="p986254660165627"><a name="p986254660165627"></a><a name="p986254660165627"></a>Reads a data segment from a <strong id="b985888061165627"><a name="b985888061165627"></a><a name="b985888061165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1474876668165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p415448332165627"><a name="p415448332165627"></a><a name="p415448332165627"></a><a href="core.md#gabb10a71c031d3633c5745ba6fd62b0a4">HdfSbufReadUint64</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint64_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1207773004165627"><a name="p1207773004165627"></a><a name="p1207773004165627"></a>bool </p>
<p id="p1529082261165627"><a name="p1529082261165627"></a><a name="p1529082261165627"></a>Reads a 64-bit unsigned integer from a <strong id="b491492517165627"><a name="b491492517165627"></a><a name="b491492517165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1516105014165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768487656165627"><a name="p768487656165627"></a><a name="p768487656165627"></a><a href="core.md#gac953788575b0c22947f18fa9f19a5bf5">HdfSbufReadUint32</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint32_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p740381156165627"><a name="p740381156165627"></a><a name="p740381156165627"></a>bool </p>
<p id="p925581621165627"><a name="p925581621165627"></a><a name="p925581621165627"></a>Reads a 32-bit unsigned integer from a <strong id="b1005995749165627"><a name="b1005995749165627"></a><a name="b1005995749165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row603048426165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1941070015165627"><a name="p1941070015165627"></a><a name="p1941070015165627"></a><a href="core.md#gabc151ad38bdecd5589623a6298c31930">HdfSbufReadUint16</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint16_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016876847165627"><a name="p2016876847165627"></a><a name="p2016876847165627"></a>bool </p>
<p id="p2029777165627"><a name="p2029777165627"></a><a name="p2029777165627"></a>Reads a 16-bit unsigned integer from a <strong id="b394591883165627"><a name="b394591883165627"></a><a name="b394591883165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1341317998165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p352925693165627"><a name="p352925693165627"></a><a name="p352925693165627"></a><a href="core.md#ga07d93e6bcd8a6a8646067783d6f46e74">HdfSbufReadUint8</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, uint8_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126392665165627"><a name="p1126392665165627"></a><a name="p1126392665165627"></a>bool </p>
<p id="p1663855963165627"><a name="p1663855963165627"></a><a name="p1663855963165627"></a>Reads an 8-bit unsigned integer from a <strong id="b2109593172165627"><a name="b2109593172165627"></a><a name="b2109593172165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row148914143165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026027850165627"><a name="p1026027850165627"></a><a name="p1026027850165627"></a><a href="core.md#ga7fb121b4351f85e1735c6e63a5c951cc">HdfSbufReadInt64</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int64_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p334867375165627"><a name="p334867375165627"></a><a name="p334867375165627"></a>bool </p>
<p id="p1988246839165627"><a name="p1988246839165627"></a><a name="p1988246839165627"></a>Reads a 64-bit signed integer from a <strong id="b726855372165627"><a name="b726855372165627"></a><a name="b726855372165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row221074316165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p179493063165627"><a name="p179493063165627"></a><a name="p179493063165627"></a><a href="core.md#ga22e7b97735f54e57c0d3bed2fa3a47c4">HdfSbufReadInt32</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int32_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605961285165627"><a name="p1605961285165627"></a><a name="p1605961285165627"></a>bool </p>
<p id="p2078293939165627"><a name="p2078293939165627"></a><a name="p2078293939165627"></a>Reads a 32-bit signed integer from a <strong id="b287642794165627"><a name="b287642794165627"></a><a name="b287642794165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row2033850876165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p875928722165627"><a name="p875928722165627"></a><a name="p875928722165627"></a><a href="core.md#ga3fce62cbc34a70259d21399d5ff91b32">HdfSbufReadInt16</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int16_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006140169165627"><a name="p2006140169165627"></a><a name="p2006140169165627"></a>bool </p>
<p id="p1433632025165627"><a name="p1433632025165627"></a><a name="p1433632025165627"></a>Reads a 16-bit signed integer from a <strong id="b1819313030165627"><a name="b1819313030165627"></a><a name="b1819313030165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1822454130165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1624202240165627"><a name="p1624202240165627"></a><a name="p1624202240165627"></a><a href="core.md#gafff778f76f9142602ef25e8afff47c83">HdfSbufReadInt8</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf, int8_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1334988506165627"><a name="p1334988506165627"></a><a name="p1334988506165627"></a>bool </p>
<p id="p32363401165627"><a name="p32363401165627"></a><a name="p32363401165627"></a>Reads an 8-bit signed integer from a <strong id="b356855442165627"><a name="b356855442165627"></a><a name="b356855442165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row354641867165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433167543165627"><a name="p1433167543165627"></a><a name="p1433167543165627"></a><a href="core.md#gab03aa25c90fda50138496b0f874a664e">HdfSbufReadString</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178995496165627"><a name="p178995496165627"></a><a name="p178995496165627"></a>const char * </p>
<p id="p2105604175165627"><a name="p2105604175165627"></a><a name="p2105604175165627"></a>Reads a string from a <strong id="b1663979638165627"><a name="b1663979638165627"></a><a name="b1663979638165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1429175614165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p266906224165627"><a name="p266906224165627"></a><a name="p266906224165627"></a><a href="core.md#ga3f4f5fdb03f64c23f318ecf7c602ac59">HdfSbufGetData</a> (const struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1802167558165627"><a name="p1802167558165627"></a><a name="p1802167558165627"></a>uint8_t * </p>
<p id="p1546356500165627"><a name="p1546356500165627"></a><a name="p1546356500165627"></a>Obtains the pointer to the data stored in a<strong id="b1290886948165627"><a name="b1290886948165627"></a><a name="b1290886948165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1018355937165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957942329165627"><a name="p1957942329165627"></a><a name="p1957942329165627"></a><a href="core.md#ga2b7a5750bf42151edd7bd686fb11a39d">HdfSbufFlush</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339684561165627"><a name="p1339684561165627"></a><a name="p1339684561165627"></a>void </p>
<p id="p143503607165627"><a name="p143503607165627"></a><a name="p143503607165627"></a>Clears the data stored in a <strong id="b1983957770165627"><a name="b1983957770165627"></a><a name="b1983957770165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row2129351116165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p430552765165627"><a name="p430552765165627"></a><a name="p430552765165627"></a><a href="core.md#ga74941de5883ae39cb6103591f67dbea0">HdfSbufGetCapacity</a> (const struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261843724165627"><a name="p1261843724165627"></a><a name="p1261843724165627"></a>size_t </p>
<p id="p1133724025165627"><a name="p1133724025165627"></a><a name="p1133724025165627"></a>Obtains the capacity of a <strong id="b2121359428165627"><a name="b2121359428165627"></a><a name="b2121359428165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1735316681165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145958028165627"><a name="p2145958028165627"></a><a name="p2145958028165627"></a><a href="core.md#gaf983c174acfb5b1f8f9dc5b6c2f52e0d">HdfSbufGetDataSize</a> (const struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1796606664165627"><a name="p1796606664165627"></a><a name="p1796606664165627"></a>size_t </p>
<p id="p1491981817165627"><a name="p1491981817165627"></a><a name="p1491981817165627"></a>Obtains the size of the data stored in a <strong id="b1510291604165627"><a name="b1510291604165627"></a><a name="b1510291604165627"></a>SBuf</strong>. </p>
</td>
</tr>
<tr id="row1784066264165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519967339165627"><a name="p1519967339165627"></a><a name="p1519967339165627"></a><a href="core.md#ga5e3dee8b1a2128da70cc5718b631c8ba">HdfSBufObtain</a> (size_t capacity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1189735865165627"><a name="p1189735865165627"></a><a name="p1189735865165627"></a>struct <a href="hdfsbuf.md">HdfSBuf</a> * </p>
<p id="p202220209165627"><a name="p202220209165627"></a><a name="p202220209165627"></a>Obtains a <strong id="b574467280165627"><a name="b574467280165627"></a><a name="b574467280165627"></a>SBuf</strong> instance. </p>
</td>
</tr>
<tr id="row2007139493165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171583382165627"><a name="p1171583382165627"></a><a name="p1171583382165627"></a><a href="core.md#ga479315c09d0d927aa211de829388122d">HdfSBufObtainDefaultSize</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1799654394165627"><a name="p1799654394165627"></a><a name="p1799654394165627"></a>struct <a href="hdfsbuf.md">HdfSBuf</a> * </p>
<p id="p997185460165627"><a name="p997185460165627"></a><a name="p997185460165627"></a>Obtains a <strong id="b2096856616165627"><a name="b2096856616165627"></a><a name="b2096856616165627"></a>SBuf</strong> instance of the default capacity (256 bytes). </p>
</td>
</tr>
<tr id="row418243783165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1931303815165627"><a name="p1931303815165627"></a><a name="p1931303815165627"></a><a href="core.md#gabcc9a442a3b2615828d60a1d4664b4a9">HdfSBufBind</a> (uintptr_t base, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p659770432165627"><a name="p659770432165627"></a><a name="p659770432165627"></a>struct <a href="hdfsbuf.md">HdfSBuf</a> * </p>
<p id="p685037279165627"><a name="p685037279165627"></a><a name="p685037279165627"></a>Creates a <strong id="b92873864165627"><a name="b92873864165627"></a><a name="b92873864165627"></a>SBuf</strong> instance with the specified data and size. The pointer to the data stored in the <strong id="b667737128165627"><a name="b667737128165627"></a><a name="b667737128165627"></a>SBuf</strong> is released by the caller, and the written data size should not exceed the specified value of <strong id="b122963808165627"><a name="b122963808165627"></a><a name="b122963808165627"></a>size</strong>. </p>
</td>
</tr>
<tr id="row1058252027165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466687837165627"><a name="p466687837165627"></a><a name="p466687837165627"></a><a href="core.md#gaa0041d238cfc7cf00779191aa58e7ee0">HdfSBufRecycle</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57356208165627"><a name="p57356208165627"></a><a name="p57356208165627"></a>void </p>
<p id="p111540804165627"><a name="p111540804165627"></a><a name="p111540804165627"></a>Releases a <strong id="b427081813165627"><a name="b427081813165627"></a><a name="b427081813165627"></a>SBuf </strong>. </p>
</td>
</tr>
<tr id="row1590788899165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656503894165627"><a name="p1656503894165627"></a><a name="p1656503894165627"></a><a href="core.md#ga22d4a953c89a941337e593647ebe2f5b">HdfSBufMove</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p604707218165627"><a name="p604707218165627"></a><a name="p604707218165627"></a>struct <a href="hdfsbuf.md">HdfSBuf</a> * </p>
<p id="p1509614764165627"><a name="p1509614764165627"></a><a name="p1509614764165627"></a>Creates a <strong id="b1618466877165627"><a name="b1618466877165627"></a><a name="b1618466877165627"></a>SBuf</strong> instance with an original <strong id="b1844127446165627"><a name="b1844127446165627"></a><a name="b1844127446165627"></a>SBuf</strong>. This function moves the data stored in the original <strong id="b927216083165627"><a name="b927216083165627"></a><a name="b927216083165627"></a>SBuf</strong> to the new one without memory copy. </p>
</td>
</tr>
<tr id="row621568737165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1542908319165627"><a name="p1542908319165627"></a><a name="p1542908319165627"></a><a href="core.md#ga406275df686ff556fd5bdb20349e4972">HdfSBufCopy</a> (const struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203263831165627"><a name="p1203263831165627"></a><a name="p1203263831165627"></a>struct <a href="hdfsbuf.md">HdfSBuf</a> * </p>
<p id="p505768431165627"><a name="p505768431165627"></a><a name="p505768431165627"></a>Creates a <strong id="b1534203205165627"><a name="b1534203205165627"></a><a name="b1534203205165627"></a>SBuf</strong> instance with an original <strong id="b1817381419165627"><a name="b1817381419165627"></a><a name="b1817381419165627"></a>SBuf</strong>. This function copies the data stored in the original <strong id="b1770484758165627"><a name="b1770484758165627"></a><a name="b1770484758165627"></a>SBuf</strong> to the new one. </p>
</td>
</tr>
<tr id="row1787413410165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752042160165627"><a name="p752042160165627"></a><a name="p752042160165627"></a><a href="core.md#gaf391e9f47cc668daf3150c00f369bf1f">HdfSbufTransDataOwnership</a> (struct <a href="hdfsbuf.md">HdfSBuf</a> *sbuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892307809165627"><a name="p1892307809165627"></a><a name="p1892307809165627"></a>void </p>
<p id="p1085040332165627"><a name="p1085040332165627"></a><a name="p1085040332165627"></a>Transfers the data ownership to a <strong id="b988318665165627"><a name="b988318665165627"></a><a name="b988318665165627"></a>SBuf</strong>. Once the <strong id="b733172004165627"><a name="b733172004165627"></a><a name="b733172004165627"></a>SBuf</strong> is released, the bound data memory is also released. This function is used together with <a href="core.md#gabcc9a442a3b2615828d60a1d4664b4a9">HdfSBufBind</a>. </p>
</td>
</tr>
</tbody>
</table>

