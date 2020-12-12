# capability.h<a name="ZH-CN_TOPIC_0000001055387980"></a>

-   [Overview](#section1132315430165626)
-   [Summary](#section1852449319165626)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1132315430165626"></a>

**Related Modules:**

[PROCESS](PROCESS.md)

**Description:**

Declares functions and related data structures for obtaining and setting process capabilities. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1852449319165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table152231112165626"></a>
<table><thead align="left"><tr id="row1319808876165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2100552165165626"><a name="p2100552165165626"></a><a name="p2100552165165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p340575607165626"><a name="p340575607165626"></a><a name="p340575607165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1037809273165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682460225165626"><a name="p682460225165626"></a><a name="p682460225165626"></a><a href="__user_cap_header_struct.md">__user_cap_header_struct</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p513191824165626"><a name="p513191824165626"></a><a name="p513191824165626"></a>Defines the user capability header. </p>
</td>
</tr>
<tr id="row1041161752165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p572391244165626"><a name="p572391244165626"></a><a name="p572391244165626"></a><a href="__user_cap_data_struct.md">__user_cap_data_struct</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987601530165626"><a name="p987601530165626"></a><a name="p987601530165626"></a>Defines user capability data. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table134194558165626"></a>
<table><thead align="left"><tr id="row1338024018165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p276466041165626"><a name="p276466041165626"></a><a name="p276466041165626"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1804990703165626"><a name="p1804990703165626"></a><a name="p1804990703165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row585439774165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1293234411165626"><a name="p1293234411165626"></a><a name="p1293234411165626"></a><a href="PROCESS.md#ga3da61b7092bd6eba9742619ed47fc554">CAP_CHOWN</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p420068901165626"><a name="p420068901165626"></a><a name="p420068901165626"></a>Indicates the capability of changing the file ownership. </p>
</td>
</tr>
<tr id="row809518735165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1365859849165626"><a name="p1365859849165626"></a><a name="p1365859849165626"></a><a href="PROCESS.md#gad9000e5b8b0ccb4c7639a6c79206ab84">CAP_DAC_OVERRIDE</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059147859165626"><a name="p2059147859165626"></a><a name="p2059147859165626"></a>Indicates the capability of ignoring discretionary access control (DAC) restrictions on files. </p>
</td>
</tr>
<tr id="row423336482165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107926172165626"><a name="p107926172165626"></a><a name="p107926172165626"></a><a href="PROCESS.md#ga852b6d011b35fc4a9440afab60818e7f">CAP_DAC_READ_SEARCH</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1576978260165626"><a name="p1576978260165626"></a><a name="p1576978260165626"></a>Indicates the capability of ignoring DAC restrictions on file read and search. </p>
</td>
</tr>
<tr id="row1499573869165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1617099084165626"><a name="p1617099084165626"></a><a name="p1617099084165626"></a><a href="PROCESS.md#ga5b98c4f060e4f89c9188d54eae2b1089">CAP_FOWNER</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488808055165626"><a name="p1488808055165626"></a><a name="p1488808055165626"></a>Indicates the capability of ignoring the restrictions on the matching between the user ID of the file owner and process ID. </p>
</td>
</tr>
<tr id="row1557807132165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1796217696165626"><a name="p1796217696165626"></a><a name="p1796217696165626"></a><a href="PROCESS.md#ga2c299b6690bebc22f1b17faf8e003d74">CAP_KILL</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p773641516165626"><a name="p773641516165626"></a><a name="p773641516165626"></a>Indicates the capability of ignoring the restrictions on sending signals to processes that do not belong to themselves. </p>
</td>
</tr>
<tr id="row1224171027165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835128148165626"><a name="p1835128148165626"></a><a name="p1835128148165626"></a><a href="PROCESS.md#ga0d81450d3ead5e1b5eff72be7c5c85ea">CAP_SETGID</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371970052165626"><a name="p371970052165626"></a><a name="p371970052165626"></a>Indicates the capability of changing the group ID of a process. </p>
</td>
</tr>
<tr id="row1889050269165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624653882165626"><a name="p624653882165626"></a><a name="p624653882165626"></a><a href="PROCESS.md#ga3f7c3cf791b090c9e3dcff1a024301af">CAP_SETUID</a>   7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386335932165626"><a name="p386335932165626"></a><a name="p386335932165626"></a>Indicates the capability of changing the user ID of a process. </p>
</td>
</tr>
<tr id="row20854371165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p286538426165626"><a name="p286538426165626"></a><a name="p286538426165626"></a><a href="PROCESS.md#gaf5f1284e7085a795e1af8304f97bd41c">CAP_SETPCAP</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1740686976165626"><a name="p1740686976165626"></a><a name="p1740686976165626"></a>Indicates the capability of transferring capabilities to other processes and deleting capabilities. </p>
</td>
</tr>
<tr id="row528154912165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1753950787165626"><a name="p1753950787165626"></a><a name="p1753950787165626"></a><a href="PROCESS.md#ga0e2799d4126fb5265cdf89deb094d641">CAP_NET_BIND_SERVICE</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p980709616165626"><a name="p980709616165626"></a><a name="p980709616165626"></a>Indicates the capability of binding a port. </p>
</td>
</tr>
<tr id="row884161727165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1477734086165626"><a name="p1477734086165626"></a><a name="p1477734086165626"></a><a href="PROCESS.md#ga8ed3167af6b08f73c71e1d97c094fd7b">CAP_NET_BROADCAST</a>   11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891016534165626"><a name="p891016534165626"></a><a name="p891016534165626"></a>Indicates the capability of network broadcasting or multicasting. </p>
</td>
</tr>
<tr id="row486178980165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p683154926165626"><a name="p683154926165626"></a><a name="p683154926165626"></a><a href="PROCESS.md#gab0effe6e11720ce4c4821b6228c1aa77">CAP_NET_ADMIN</a>   12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1132281140165626"><a name="p1132281140165626"></a><a name="p1132281140165626"></a>Indicates the capability of executing network management tasks. </p>
</td>
</tr>
<tr id="row1138074235165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362125058165626"><a name="p1362125058165626"></a><a name="p1362125058165626"></a><a href="PROCESS.md#gab8562849ab09873a8764f4b3f29e445b">CAP_NET_RAW</a>   13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p52990176165626"><a name="p52990176165626"></a><a name="p52990176165626"></a>Indicates the capability of using raw sockets. </p>
</td>
</tr>
<tr id="row1259810324165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184914129165626"><a name="p1184914129165626"></a><a name="p1184914129165626"></a><a href="PROCESS.md#ga2e789746fd07a8ec20095a832406c1dd">CAP_SYS_PTRACE</a>   19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1915916215165626"><a name="p1915916215165626"></a><a name="p1915916215165626"></a>Indicates the capability of tracing any process. </p>
</td>
</tr>
<tr id="row47436537165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446998484165626"><a name="p1446998484165626"></a><a name="p1446998484165626"></a><a href="PROCESS.md#gac2e0e57ff2c1f83a912b449da79e2e31">CAP_SYS_ADMIN</a>   21</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1496125617165626"><a name="p1496125617165626"></a><a name="p1496125617165626"></a>Indicates the capability of executing system management tasks. </p>
</td>
</tr>
<tr id="row1006612117165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1262705161165626"><a name="p1262705161165626"></a><a name="p1262705161165626"></a><a href="PROCESS.md#ga2f1e1c5d163162c7003c8e5df2ff1e8d">CAP_SYS_BOOT</a>   22</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1281944318165626"><a name="p1281944318165626"></a><a name="p1281944318165626"></a>Indicates the capability of rebooting system. </p>
</td>
</tr>
<tr id="row670617123165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509355119165626"><a name="p1509355119165626"></a><a name="p1509355119165626"></a><a href="PROCESS.md#gac1f5d5cc7fecda8ab88019a5a1d6dd08">CAP_SYS_NICE</a>   23</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089977968165626"><a name="p1089977968165626"></a><a name="p1089977968165626"></a>Indicates the capability of setting the priority. </p>
</td>
</tr>
<tr id="row1156721503165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660980330165626"><a name="p1660980330165626"></a><a name="p1660980330165626"></a><a href="PROCESS.md#ga1dab8ee99a12ffcddc5fe17c31df2726">CAP_SYS_TIME</a>   25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473958214165626"><a name="p1473958214165626"></a><a name="p1473958214165626"></a>Indicates the capability of changing the system clock. </p>
</td>
</tr>
<tr id="row764570481165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578369560165626"><a name="p578369560165626"></a><a name="p578369560165626"></a><a href="PROCESS.md#ga032cd8eaf96d91bca567c7938f8c2b3e">OHOS_CAP_CHOWN</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p660934972165626"><a name="p660934972165626"></a><a name="p660934972165626"></a>Indicates the capability of changing the file ownership. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row242330939165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809181753165626"><a name="p1809181753165626"></a><a name="p1809181753165626"></a><a href="PROCESS.md#gae473b71e022f789afd73d33e1feadb0f">OHOS_CAP_DAC_EXECUTE</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1517568485165626"><a name="p1517568485165626"></a><a name="p1517568485165626"></a>Indicates the capability of ignoring DAC restrictions on file execution. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1473023496165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949671961165626"><a name="p949671961165626"></a><a name="p949671961165626"></a><a href="PROCESS.md#ga99c916fddf88ab0dd4ec935714e2f496">OHOS_CAP_DAC_WRITE</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783139148165626"><a name="p783139148165626"></a><a name="p783139148165626"></a>Indicates the capability of ignoring DAC restrictions on file write. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row614744259165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p667223734165626"><a name="p667223734165626"></a><a name="p667223734165626"></a><a href="PROCESS.md#ga374aed9e2e2e95a9c08dd14cae04d278">OHOS_CAP_DAC_READ_SEARCH</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882220109165626"><a name="p1882220109165626"></a><a name="p1882220109165626"></a>Indicates the capability of ignoring DAC restrictions on file read and search. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row926067537165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2142252423165626"><a name="p2142252423165626"></a><a name="p2142252423165626"></a><a href="PROCESS.md#gad07da2d2d65ce1df68cb580ed7a2a2ec">OHOS_CAP_FOWNER</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211467436165626"><a name="p1211467436165626"></a><a name="p1211467436165626"></a>Indicates the capability of ignoring the restrictions on the matching between the user ID of the file owner and process ID. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row356730405165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056289368165626"><a name="p1056289368165626"></a><a name="p1056289368165626"></a><a href="PROCESS.md#ga54cb89e233d122cd843423a638b5dc93">OHOS_CAP_KILL</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361322327165626"><a name="p361322327165626"></a><a name="p361322327165626"></a>Indicates the capability of ignoring the restrictions on sending signals to processes that do not belong to themselves. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1737223306165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840545468165626"><a name="p840545468165626"></a><a name="p840545468165626"></a><a href="PROCESS.md#ga371a19d3b06310544131d2141d5a6839">OHOS_CAP_SETGID</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1943285188165626"><a name="p1943285188165626"></a><a name="p1943285188165626"></a>Indicates the capability of changing the group ID of a process. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1115299394165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032565176165626"><a name="p2032565176165626"></a><a name="p2032565176165626"></a><a href="PROCESS.md#ga90185cea91d0d291c11e141becf43450">OHOS_CAP_SETUID</a>   7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1020781412165626"><a name="p1020781412165626"></a><a name="p1020781412165626"></a>Indicates the capability of changing the user ID of a process. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row213979127165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1408662038165626"><a name="p1408662038165626"></a><a name="p1408662038165626"></a><a href="PROCESS.md#ga560a6ed84e6d4e4b7589c8c706f60640">OHOS_CAP_NET_BIND_SERVICE</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1814092472165626"><a name="p1814092472165626"></a><a name="p1814092472165626"></a>Indicates the capability of binding a port. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1816404660165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2050017781165626"><a name="p2050017781165626"></a><a name="p2050017781165626"></a><a href="PROCESS.md#ga807a12c78fd7702925c04df3fd8a9cbb">OHOS_CAP_NET_BROADCAST</a>   9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230816312165626"><a name="p230816312165626"></a><a name="p230816312165626"></a>Indicates the capability of network broadcasting or multicasting. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row173131196165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552263658165626"><a name="p552263658165626"></a><a name="p552263658165626"></a><a href="PROCESS.md#ga2d505755c54e0d2172ff5324ced29077">OHOS_CAP_NET_ADMIN</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758204698165626"><a name="p758204698165626"></a><a name="p758204698165626"></a>Indicates the capability of executing network management tasks. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row146172247165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012128835165626"><a name="p1012128835165626"></a><a name="p1012128835165626"></a><a href="PROCESS.md#ga870f352726d87e7d1e543cbd7e1bce8d">OHOS_CAP_NET_RAW</a>   11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1459319804165626"><a name="p1459319804165626"></a><a name="p1459319804165626"></a>Indicates the capability of using raw sockets. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row848818641165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387182834165626"><a name="p1387182834165626"></a><a name="p1387182834165626"></a><a href="PROCESS.md#ga9226dae5574b6386c87b0e6582560df9">OHOS_CAP_FS_MOUNT</a>   12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641516847165626"><a name="p1641516847165626"></a><a name="p1641516847165626"></a>Indicates the capability of mounting the file system. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1778769420165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334645818165626"><a name="p1334645818165626"></a><a name="p1334645818165626"></a><a href="PROCESS.md#ga5802143f3200cee5ecc1af6dbc5c3aa0">OHOS_CAP_FS_FORMAT</a>   13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546192117165626"><a name="p1546192117165626"></a><a name="p1546192117165626"></a>Indicates the capability of formatting the file system. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1006057293165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p947674700165626"><a name="p947674700165626"></a><a name="p947674700165626"></a><a href="PROCESS.md#ga65868d3c9629fc31f73678396aca3136">OHOS_CAP_SCHED_SETPRIORITY</a>   14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382092135165626"><a name="p1382092135165626"></a><a name="p1382092135165626"></a>Indicates the capability of setting the scheduling priority. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row591685333165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146622755165626"><a name="p146622755165626"></a><a name="p146622755165626"></a><a href="PROCESS.md#ga54901b8a0b89b410be9c846781b0a3ae">OHOS_CAP_SET_TIMEOFDAY</a>   15</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457735052165626"><a name="p457735052165626"></a><a name="p457735052165626"></a>Indicates the capability of setting the date. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row337414490165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2045630914165626"><a name="p2045630914165626"></a><a name="p2045630914165626"></a><a href="PROCESS.md#ga880e395b85296d3e2561ec2fd1fe315b">OHOS_CAP_CLOCK_SETTIME</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985832511165626"><a name="p985832511165626"></a><a name="p985832511165626"></a>Indicates the capability of setting the clock. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row62847197165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98693580165626"><a name="p98693580165626"></a><a name="p98693580165626"></a><a href="PROCESS.md#gaaf53607491c593ba91afc8accc89574f">OHOS_CAP_CAPSET</a>   17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832606429165626"><a name="p1832606429165626"></a><a name="p1832606429165626"></a>Indicates the capability of setting the capabilities. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row765971812165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775785279165626"><a name="p775785279165626"></a><a name="p775785279165626"></a><a href="PROCESS.md#gabc2e8c23ecf979bf3395d86a2d1eacfc">OHOS_CAP_REBOOT</a>   18</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196201392165626"><a name="p196201392165626"></a><a name="p196201392165626"></a>Indicates the capability of rebooting system. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
<tr id="row1948023338165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p439402061165626"><a name="p439402061165626"></a><a name="p439402061165626"></a><a href="PROCESS.md#gab4c5afb99569714f96f0bb05305ad0e7">OHOS_CAP_SHELL_EXEC</a>   19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397126956165626"><a name="p397126956165626"></a><a name="p397126956165626"></a>Indicates the capability of calling shell. This macro is used by <a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a>. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table922166890165626"></a>
<table><thead align="left"><tr id="row228876703165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p772871528165626"><a name="p772871528165626"></a><a name="p772871528165626"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p292541187165626"><a name="p292541187165626"></a><a name="p292541187165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row677553453165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775743395165626"><a name="p1775743395165626"></a><a name="p1775743395165626"></a><a href="PROCESS.md#gaf042e68224162d4eb2ce7668904831d9">cap_user_header_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578927648165626"><a name="p1578927648165626"></a><a name="p1578927648165626"></a> typedef struct <a href="__user_cap_header_struct.md">__user_cap_header_struct</a> * </p>
<p id="p1680137425165626"><a name="p1680137425165626"></a><a name="p1680137425165626"></a>Defines the user capability header. </p>
</td>
</tr>
<tr id="row959220879165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916538989165626"><a name="p1916538989165626"></a><a name="p1916538989165626"></a><a href="PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667">cap_user_data_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610394941165626"><a name="p610394941165626"></a><a name="p610394941165626"></a> typedef struct <a href="__user_cap_data_struct.md">__user_cap_data_struct</a> * </p>
<p id="p2143953200165626"><a name="p2143953200165626"></a><a name="p2143953200165626"></a>Defines user capability data. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table66402095165626"></a>
<table><thead align="left"><tr id="row239016040165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p959935483165626"><a name="p959935483165626"></a><a name="p959935483165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p952686991165626"><a name="p952686991165626"></a><a name="p952686991165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row428936592165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263257178165626"><a name="p1263257178165626"></a><a name="p1263257178165626"></a><a href="PROCESS.md#gaa284eba1654e9fc0672aca2a6d2cd0ce">capget</a> (<a href="PROCESS.md#gaf042e68224162d4eb2ce7668904831d9">cap_user_header_t</a> hdr_ptr, <a href="PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667">cap_user_data_t</a> data_ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708876453165626"><a name="p708876453165626"></a><a name="p708876453165626"></a>int </p>
<p id="p1224506234165626"><a name="p1224506234165626"></a><a name="p1224506234165626"></a>Obtains the capability information of a specified process based on the input parameters (compatible with the Linux API format). </p>
</td>
</tr>
<tr id="row1210370597165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105754451165626"><a name="p2105754451165626"></a><a name="p2105754451165626"></a><a href="PROCESS.md#gaaa15be01b20aff9efb09de5a8ead207e">capset</a> (<a href="PROCESS.md#gaf042e68224162d4eb2ce7668904831d9">cap_user_header_t</a> hdr_ptr, const <a href="PROCESS.md#gaafd3aaf8bb3f786614fee86c2fa93667">cap_user_data_t</a> data_ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1598708974165626"><a name="p1598708974165626"></a><a name="p1598708974165626"></a>int </p>
<p id="p2096970735165626"><a name="p2096970735165626"></a><a name="p2096970735165626"></a>Sets the capability information for a specified process based on the input parameters (compatible with the Linux API format). </p>
</td>
</tr>
<tr id="row471519956165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931177558165626"><a name="p931177558165626"></a><a name="p931177558165626"></a><a href="PROCESS.md#gaf254b29504e9733ff55014acdf5fbcc7">ohos_capget</a> (<a href="UTILS.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, unsigned int *caps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1519245629165626"><a name="p1519245629165626"></a><a name="p1519245629165626"></a>int </p>
<p id="p35812240165626"><a name="p35812240165626"></a><a name="p35812240165626"></a>Obtains the capability information of the specified process process based on the input parameters. </p>
</td>
</tr>
<tr id="row479016239165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025660976165626"><a name="p2025660976165626"></a><a name="p2025660976165626"></a><a href="PROCESS.md#ga77ad7758babf522e7ffb28551332a659">ohos_capset</a> (unsigned int caps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083321050165626"><a name="p1083321050165626"></a><a name="p1083321050165626"></a>int </p>
<p id="p1700762546165626"><a name="p1700762546165626"></a><a name="p1700762546165626"></a>Sets the capability information of the current process based on the input parameters. </p>
</td>
</tr>
</tbody>
</table>

