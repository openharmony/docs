# fmtmsg.h<a name="ZH-CN_TOPIC_0000001055387982"></a>

-   [Overview](#section1412475761165627)
-   [Summary](#section330625145165627)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1412475761165627"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Provides a function for printing formatted messages. 

You can use the function in the file to write messages \(especially error messages\) into the output device specified by  **classification**.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section330625145165627"></a>

## Macros<a name="define-members"></a>

<a name="table1888733244165627"></a>
<table><thead align="left"><tr id="row542318173165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1155702832165627"><a name="p1155702832165627"></a><a name="p1155702832165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1101760629165627"><a name="p1101760629165627"></a><a name="p1101760629165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1655002781165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621403621165627"><a name="p621403621165627"></a><a name="p621403621165627"></a><a href="UTILS.md#ga7250644aab1a485bd6a24720d2867ad8">MM_HARD</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426430299165627"><a name="p1426430299165627"></a><a name="p1426430299165627"></a>A hardware error occurred. </p>
</td>
</tr>
<tr id="row1405544960165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585922628165627"><a name="p585922628165627"></a><a name="p585922628165627"></a><a href="UTILS.md#ga95d4386c5cab57599cf9fdad75dbd9ef">MM_SOFT</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216120103165627"><a name="p1216120103165627"></a><a name="p1216120103165627"></a>A software error occurred. </p>
</td>
</tr>
<tr id="row994903884165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727588027165627"><a name="p1727588027165627"></a><a name="p1727588027165627"></a><a href="UTILS.md#gaad8873c0512aaad8e20a95d8d7867fa6">MM_FIRM</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399470314165627"><a name="p399470314165627"></a><a name="p399470314165627"></a>A firmware error occurred. </p>
</td>
</tr>
<tr id="row340422122165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1801531510165627"><a name="p1801531510165627"></a><a name="p1801531510165627"></a><a href="UTILS.md#ga9c8b88fc46ddd4d418c05b4c5c685786">MM_APPL</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466700443165627"><a name="p466700443165627"></a><a name="p466700443165627"></a>An error is detected by an application. </p>
</td>
</tr>
<tr id="row1566323313165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p132187062165627"><a name="p132187062165627"></a><a name="p132187062165627"></a><a href="UTILS.md#ga5b43fa612f8e72db32d32385192f5bd9">MM_UTIL</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128264341165627"><a name="p1128264341165627"></a><a name="p1128264341165627"></a>An error is detected by a utility. </p>
</td>
</tr>
<tr id="row1067985276165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2146489054165627"><a name="p2146489054165627"></a><a name="p2146489054165627"></a><a href="UTILS.md#ga3257723578ef85fb0cef91ac18a6a8e9">MM_OPSYS</a>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1642250178165627"><a name="p1642250178165627"></a><a name="p1642250178165627"></a>An error is detected by the operating system. </p>
</td>
</tr>
<tr id="row679031816165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168764456165627"><a name="p168764456165627"></a><a name="p168764456165627"></a><a href="UTILS.md#ga655710ff6f4600613aba693f2c933844">MM_RECOVER</a>   64</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499803012165627"><a name="p499803012165627"></a><a name="p499803012165627"></a>The error is recoverable. </p>
</td>
</tr>
<tr id="row1410763946165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p749169678165627"><a name="p749169678165627"></a><a name="p749169678165627"></a><a href="UTILS.md#gaac7ced5531ea5e8af060a12930bd930b">MM_NRECOV</a>   128</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1517137826165627"><a name="p1517137826165627"></a><a name="p1517137826165627"></a>The error is non-recoverable. </p>
</td>
</tr>
<tr id="row866374479165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1284345761165627"><a name="p1284345761165627"></a><a name="p1284345761165627"></a><a href="UTILS.md#ga28f8601bbd8dfa8c1a1133892dbaaeaf">MM_PRINT</a>   256</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885644495165627"><a name="p885644495165627"></a><a name="p885644495165627"></a>Prints error messages on standard error (stderr). </p>
</td>
</tr>
<tr id="row1810221818165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1310378170165627"><a name="p1310378170165627"></a><a name="p1310378170165627"></a><a href="UTILS.md#ga28df3705304c876e17ee22267eaa01af">MM_CONSOLE</a>   512</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143787019165627"><a name="p143787019165627"></a><a name="p143787019165627"></a>Prints error messages on the system console. </p>
</td>
</tr>
<tr id="row493508000165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1349089774165627"><a name="p1349089774165627"></a><a name="p1349089774165627"></a><a href="UTILS.md#ga0d1ed1880858b3eb76f4173619c58c40">MM_NULLMC</a>   0L</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102595616165627"><a name="p1102595616165627"></a><a name="p1102595616165627"></a>Ignores the <strong id="b6693320165627"><a name="b6693320165627"></a><a name="b6693320165627"></a>classification</strong> parameter. </p>
</td>
</tr>
<tr id="row332094413165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1294305234165627"><a name="p1294305234165627"></a><a name="p1294305234165627"></a><a href="UTILS.md#ga3d5f92b4ab4f31431e764e04cd74de61">MM_HALT</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2081857746165627"><a name="p2081857746165627"></a><a name="p2081857746165627"></a>Fatal fault. </p>
</td>
</tr>
<tr id="row1509575549165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1068936411165627"><a name="p1068936411165627"></a><a name="p1068936411165627"></a><a href="UTILS.md#ga691f4cd7904d1f6579e093fb40226b98">MM_ERROR</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282469924165627"><a name="p1282469924165627"></a><a name="p1282469924165627"></a>Error-level fault. </p>
</td>
</tr>
<tr id="row1415474750165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1570145450165627"><a name="p1570145450165627"></a><a name="p1570145450165627"></a><a href="UTILS.md#ga277b9951914986b139db5750177091f3">MM_WARNING</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1458092672165627"><a name="p1458092672165627"></a><a name="p1458092672165627"></a>Warning condition. </p>
</td>
</tr>
<tr id="row982411881165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1132148966165627"><a name="p1132148966165627"></a><a name="p1132148966165627"></a><a href="UTILS.md#ga0c65f03a4d4009ddbc8b318c4cca2662">MM_INFO</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p329149569165627"><a name="p329149569165627"></a><a name="p329149569165627"></a>Informative message. </p>
</td>
</tr>
<tr id="row1567857483165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1545288244165627"><a name="p1545288244165627"></a><a name="p1545288244165627"></a><a href="UTILS.md#gaf4e60c7def20483a91f2c85b9a98420c">MM_NOSEV</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1204252350165627"><a name="p1204252350165627"></a><a name="p1204252350165627"></a>No severity level is set, equivalent to <a href="UTILS.md#gad65c53433554559cdc93e413786cc981">MM_NULLSEV</a>. </p>
</td>
</tr>
<tr id="row2018410790165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1959502409165627"><a name="p1959502409165627"></a><a name="p1959502409165627"></a><a href="UTILS.md#ga2d55c51901766d6400ea645cfaa56ad7">MM_OK</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1430902964165627"><a name="p1430902964165627"></a><a name="p1430902964165627"></a>The function succeeded. </p>
</td>
</tr>
<tr id="row621853273165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907499861165627"><a name="p1907499861165627"></a><a name="p1907499861165627"></a><a href="UTILS.md#ga6c6fa7e4345318cb7b7a12a6492f414b">MM_NOTOK</a>   (-1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118472227165627"><a name="p118472227165627"></a><a name="p118472227165627"></a>The function failed. </p>
</td>
</tr>
<tr id="row2031933445165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p520934372165627"><a name="p520934372165627"></a><a name="p520934372165627"></a><a href="UTILS.md#ga16ba492651e5414d28fbca6da09999e2">MM_NOMSG</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663517602165627"><a name="p1663517602165627"></a><a name="p1663517602165627"></a>Error writing to stderr. </p>
</td>
</tr>
<tr id="row2064797920165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p426080036165627"><a name="p426080036165627"></a><a name="p426080036165627"></a><a href="UTILS.md#ga47ee40d662d07179517362f5796fedc6">MM_NOCON</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126766253165627"><a name="p1126766253165627"></a><a name="p1126766253165627"></a>Error writing to the console. </p>
</td>
</tr>
<tr id="row938001510165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45887687165627"><a name="p45887687165627"></a><a name="p45887687165627"></a><a href="UTILS.md#ga174d0d4b9bbda298cd1faec4d4f27202">MM_NULLLBL</a>   ((char*)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166353236165627"><a name="p166353236165627"></a><a name="p166353236165627"></a>Ignores the <strong id="b1968387631165627"><a name="b1968387631165627"></a><a name="b1968387631165627"></a>label</strong> parameter. </p>
</td>
</tr>
<tr id="row1208401106165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p640363465165627"><a name="p640363465165627"></a><a name="p640363465165627"></a><a href="UTILS.md#ga345476b2492fd41e52ec6cbb08265b07">MM_NULLTXT</a>   ((char*)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875552297165627"><a name="p875552297165627"></a><a name="p875552297165627"></a>Ignores the <strong id="b1578705213165627"><a name="b1578705213165627"></a><a name="b1578705213165627"></a>text</strong> parameter. </p>
</td>
</tr>
<tr id="row1203364099165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1297302406165627"><a name="p1297302406165627"></a><a name="p1297302406165627"></a><a href="UTILS.md#ga715bfd49536d249ea7812a4114602db0">MM_NULLACT</a>   ((char*)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p504757829165627"><a name="p504757829165627"></a><a name="p504757829165627"></a>Ignores the <strong id="b1133931519165627"><a name="b1133931519165627"></a><a name="b1133931519165627"></a>action</strong> parameter. </p>
</td>
</tr>
<tr id="row292814534165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4018499165627"><a name="p4018499165627"></a><a name="p4018499165627"></a><a href="UTILS.md#ga64da80d889e56fc4dc22b0d8e07576cc">MM_NULLTAG</a>   ((char*)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130737811165627"><a name="p1130737811165627"></a><a name="p1130737811165627"></a>Ignores the <strong id="b619134174165627"><a name="b619134174165627"></a><a name="b619134174165627"></a>tag</strong> parameter. </p>
</td>
</tr>
<tr id="row791738979165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178986452165627"><a name="p178986452165627"></a><a name="p178986452165627"></a><a href="UTILS.md#gad65c53433554559cdc93e413786cc981">MM_NULLSEV</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1500516220165627"><a name="p1500516220165627"></a><a name="p1500516220165627"></a>Ignores the <strong id="b1393258873165627"><a name="b1393258873165627"></a><a name="b1393258873165627"></a>severity</strong> parameter. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1514129715165627"></a>
<table><thead align="left"><tr id="row930714893165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1669160518165627"><a name="p1669160518165627"></a><a name="p1669160518165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p509926345165627"><a name="p509926345165627"></a><a name="p509926345165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1029179381165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p66573251165627"><a name="p66573251165627"></a><a name="p66573251165627"></a><a href="UTILS.md#ga41115d5b017933dcee85d41ed7a743e7">fmtmsg</a> (long classification, const char *label, int severity, const char *text, const char *action, const char *tag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1701456410165627"><a name="p1701456410165627"></a><a name="p1701456410165627"></a>int </p>
<p id="p98535434165627"><a name="p98535434165627"></a><a name="p98535434165627"></a>Prints formatted messages. </p>
</td>
</tr>
</tbody>
</table>

