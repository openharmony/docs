# Parameter<a name="EN-US_TOPIC_0000001054718083"></a>

-   [Overview](#section462213396165625)
-   [Summary](#section766550006165625)
-   [Files](#files)
-   [Functions](#func-members)
-   [Details](#section1594484957165625)
-   [Function](#section932383220165625)
-   [GetAbiList\(\)](#gaa5e3d6179f398e407b632cc53410cd1a)
-   [GetBootloaderVersion\(\)](#gab033380f4acabc3304c401ea40034a3b)
-   [GetBrand\(\)](#gaba787cc6f740d7d8f5e7ccd5a98fc7ed)
-   [GetBuildHost\(\)](#ga54aad44d8a1c01ee1a3af82b5464e616)
-   [GetBuildRootHash\(\)](#ga26f28a1bf6f0f3c550c716223397673c)
-   [GetBuildTime\(\)](#ga6707dd0565fd65ab18149aa70ec233ac)
-   [GetBuildType\(\)](#gad1a95a2a073bf7f78c6a8513e29c3ddc)
-   [GetBuildUser\(\)](#gaa49edb9e675d928790a8ca7332905659)
-   [GetDisplayVersion\(\)](#gaacd61c8a367a307d5b5c3e907822f271)
-   [GetFirstApiLevel\(\)](#ga6f62d683d76a160775b3ac46e856955e)
-   [GetHardwareModel\(\)](#ga0ff61721ab17eb07fcece1ccaf40293a)
-   [GetHardwareProfile\(\)](#gaf98290ad8bd5328aff40293ff42d6a9b)
-   [GetIncrementalVersion\(\)](#ga3d52b0a354555dbb16c265d5d5923546)
-   [GetManufacture\(\)](#gad6d21dda3b027eb603dd24c7315ee6ea)
-   [GetMarketName\(\)](#gaa3adb204e5affd0a9e18828c1fbf2b0b)
-   [GetOsName\(\)](#ga1402657e793875973f8801f631c29781)
-   [GetParameter\(\)](#gae6a476fa36d2b1876eee0e4f256db6a6)
-   [GetProductModel\(\)](#gaa62644b77184644fac848f54837f4e5b)
-   [GetProductSeries\(\)](#ga8a0d394075a3cbafe7ef0f51d08319a8)
-   [GetProductType\(\)](#ga2d6e83004da9cfdef6f3162d484163f1)
-   [GetSdkApiLevel\(\)](#ga4720291ec5700581109e2f7943e2e371)
-   [GetSecurityPatchTag\(\)](#gaa2407d8ce39e4a151b7e9d45123794c2)
-   [GetSerial\(\)](#gacc29ceeab6d312f3becdf19b28b9185d)
-   [GetSoftwareModel\(\)](#ga309a7fb6d9a60f6d6453e3faea030d7a)
-   [GetVersionId\(\)](#gaea3cb294680fcef18a0a52f35fdaa124)
-   [SetParameter\(\)](#ga2779b5e59d43308c51f7be38b9c98ddb)

## **Overview**<a name="section462213396165625"></a>

**Description:**

Provides functions for obtaining system parameters. 

This module can obtain device information such as device type and manufacturer. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section766550006165625"></a>

## Files<a name="files"></a>

<a name="table1226116983165625"></a>
<table><thead align="left"><tr id="row291092015165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1501365619165625"><a name="p1501365619165625"></a><a name="p1501365619165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1247875787165625"><a name="p1247875787165625"></a><a name="p1247875787165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row107677850165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p152445116165625"><a name="p152445116165625"></a><a name="p152445116165625"></a><a href="parameter-h.md">parameter.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795430765165625"><a name="p795430765165625"></a><a name="p795430765165625"></a>Declares functions for obtaining system parameters. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table440599890165625"></a>
<table><thead align="left"><tr id="row1995386829165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1499249846165625"><a name="p1499249846165625"></a><a name="p1499249846165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p163050826165625"><a name="p163050826165625"></a><a name="p163050826165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1287168983165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560821850165625"><a name="p1560821850165625"></a><a name="p1560821850165625"></a><a href="parameter.md#gae6a476fa36d2b1876eee0e4f256db6a6">GetParameter</a> (const char *key, const char *def, char *value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182888168165625"><a name="p182888168165625"></a><a name="p182888168165625"></a>int </p>
<p id="p1258966940165625"><a name="p1258966940165625"></a><a name="p1258966940165625"></a>Obtains a system parameter matching the specified <strong id="b706844651165625"><a name="b706844651165625"></a><a name="b706844651165625"></a>key</strong>. </p>
</td>
</tr>
<tr id="row1831765545165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900094968165625"><a name="p1900094968165625"></a><a name="p1900094968165625"></a><a href="parameter.md#ga2779b5e59d43308c51f7be38b9c98ddb">SetParameter</a> (const char *key, const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1181943751165625"><a name="p1181943751165625"></a><a name="p1181943751165625"></a>int </p>
<p id="p1304054264165625"><a name="p1304054264165625"></a><a name="p1304054264165625"></a>Sets or updates a system parameter. </p>
</td>
</tr>
<tr id="row230075868165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934258519165625"><a name="p1934258519165625"></a><a name="p1934258519165625"></a><a href="parameter.md#ga2d6e83004da9cfdef6f3162d484163f1">GetProductType</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833315792165625"><a name="p833315792165625"></a><a name="p833315792165625"></a>char * </p>
<p id="p282869798165625"><a name="p282869798165625"></a><a name="p282869798165625"></a>Obtains the device type. </p>
</td>
</tr>
<tr id="row201767757165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206195092165625"><a name="p1206195092165625"></a><a name="p1206195092165625"></a><a href="parameter.md#gad6d21dda3b027eb603dd24c7315ee6ea">GetManufacture</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912912586165625"><a name="p1912912586165625"></a><a name="p1912912586165625"></a>char * </p>
<p id="p1507399697165625"><a name="p1507399697165625"></a><a name="p1507399697165625"></a>Obtains the device manufacturer. </p>
</td>
</tr>
<tr id="row1204326288165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p986725447165625"><a name="p986725447165625"></a><a name="p986725447165625"></a><a href="parameter.md#gaba787cc6f740d7d8f5e7ccd5a98fc7ed">GetBrand</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p999406784165625"><a name="p999406784165625"></a><a name="p999406784165625"></a>char * </p>
<p id="p1295724527165625"><a name="p1295724527165625"></a><a name="p1295724527165625"></a>Obtains the device brand. </p>
</td>
</tr>
<tr id="row1802518286165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1145201595165625"><a name="p1145201595165625"></a><a name="p1145201595165625"></a><a href="parameter.md#gaa3adb204e5affd0a9e18828c1fbf2b0b">GetMarketName</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98293428165625"><a name="p98293428165625"></a><a name="p98293428165625"></a>char * </p>
<p id="p1332721124165625"><a name="p1332721124165625"></a><a name="p1332721124165625"></a>Obtains the device marketing name. </p>
</td>
</tr>
<tr id="row1597307664165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1288025326165625"><a name="p1288025326165625"></a><a name="p1288025326165625"></a><a href="parameter.md#ga8a0d394075a3cbafe7ef0f51d08319a8">GetProductSeries</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926267617165625"><a name="p1926267617165625"></a><a name="p1926267617165625"></a>char * </p>
<p id="p278067342165625"><a name="p278067342165625"></a><a name="p278067342165625"></a>Obtains the device series name. </p>
</td>
</tr>
<tr id="row1240682659165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p438867966165625"><a name="p438867966165625"></a><a name="p438867966165625"></a><a href="parameter.md#gaa62644b77184644fac848f54837f4e5b">GetProductModel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2129524463165625"><a name="p2129524463165625"></a><a name="p2129524463165625"></a>char * </p>
<p id="p1267459503165625"><a name="p1267459503165625"></a><a name="p1267459503165625"></a>Obtains the device authentication model. </p>
</td>
</tr>
<tr id="row356472436165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482001417165625"><a name="p1482001417165625"></a><a name="p1482001417165625"></a><a href="parameter.md#ga309a7fb6d9a60f6d6453e3faea030d7a">GetSoftwareModel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1132098343165625"><a name="p1132098343165625"></a><a name="p1132098343165625"></a>char * </p>
<p id="p776133796165625"><a name="p776133796165625"></a><a name="p776133796165625"></a>Obtains the device software model. </p>
</td>
</tr>
<tr id="row223219094165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800765906165625"><a name="p800765906165625"></a><a name="p800765906165625"></a><a href="parameter.md#ga0ff61721ab17eb07fcece1ccaf40293a">GetHardwareModel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p270703769165625"><a name="p270703769165625"></a><a name="p270703769165625"></a>char * </p>
<p id="p1516718532165625"><a name="p1516718532165625"></a><a name="p1516718532165625"></a>Obtains the device hardware model. </p>
</td>
</tr>
<tr id="row1849748363165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080906905165625"><a name="p2080906905165625"></a><a name="p2080906905165625"></a><a href="parameter.md#gaf98290ad8bd5328aff40293ff42d6a9b">GetHardwareProfile</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1554756583165625"><a name="p1554756583165625"></a><a name="p1554756583165625"></a>char * </p>
<p id="p515065489165625"><a name="p515065489165625"></a><a name="p515065489165625"></a>Obtains the device hardware profile. </p>
</td>
</tr>
<tr id="row1047610107165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919239381165625"><a name="p919239381165625"></a><a name="p919239381165625"></a><a href="parameter.md#gacc29ceeab6d312f3becdf19b28b9185d">GetSerial</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100529244165625"><a name="p100529244165625"></a><a name="p100529244165625"></a>char * </p>
<p id="p481365135165625"><a name="p481365135165625"></a><a name="p481365135165625"></a>Obtains the device serial number (SN). </p>
</td>
</tr>
<tr id="row1723363849165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p617534898165625"><a name="p617534898165625"></a><a name="p617534898165625"></a><a href="parameter.md#ga1402657e793875973f8801f631c29781">GetOsName</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p960035699165625"><a name="p960035699165625"></a><a name="p960035699165625"></a>char * </p>
<p id="p1191914555165625"><a name="p1191914555165625"></a><a name="p1191914555165625"></a>Obtains the operating system (OS) name. </p>
</td>
</tr>
<tr id="row368379516165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1870757884165625"><a name="p1870757884165625"></a><a name="p1870757884165625"></a><a href="parameter.md#gaacd61c8a367a307d5b5c3e907822f271">GetDisplayVersion</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1971889902165625"><a name="p1971889902165625"></a><a name="p1971889902165625"></a>char * </p>
<p id="p867198754165625"><a name="p867198754165625"></a><a name="p867198754165625"></a>Obtains the software version visible to users. </p>
</td>
</tr>
<tr id="row544851583165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162419862165625"><a name="p162419862165625"></a><a name="p162419862165625"></a><a href="parameter.md#gab033380f4acabc3304c401ea40034a3b">GetBootloaderVersion</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p676912665165625"><a name="p676912665165625"></a><a name="p676912665165625"></a>char * </p>
<p id="p1324236894165625"><a name="p1324236894165625"></a><a name="p1324236894165625"></a>Obtains the bootloader version of this device. </p>
</td>
</tr>
<tr id="row1781525682165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1810147003165625"><a name="p1810147003165625"></a><a name="p1810147003165625"></a><a href="parameter.md#gaa2407d8ce39e4a151b7e9d45123794c2">GetSecurityPatchTag</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001991297165625"><a name="p1001991297165625"></a><a name="p1001991297165625"></a>char * </p>
<p id="p1173919597165625"><a name="p1173919597165625"></a><a name="p1173919597165625"></a>Obtains the security patch tag. </p>
</td>
</tr>
<tr id="row592315119165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478077760165625"><a name="p1478077760165625"></a><a name="p1478077760165625"></a><a href="parameter.md#gaa5e3d6179f398e407b632cc53410cd1a">GetAbiList</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736152883165625"><a name="p736152883165625"></a><a name="p736152883165625"></a>char * </p>
<p id="p1084670343165625"><a name="p1084670343165625"></a><a name="p1084670343165625"></a>Obtains the list of application binary interfaces (ABIs) supported on this device. </p>
</td>
</tr>
<tr id="row1302069639165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145372489165625"><a name="p145372489165625"></a><a name="p145372489165625"></a><a href="parameter.md#ga4720291ec5700581109e2f7943e2e371">GetSdkApiLevel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651718004165625"><a name="p1651718004165625"></a><a name="p1651718004165625"></a>char * </p>
<p id="p196041772165625"><a name="p196041772165625"></a><a name="p196041772165625"></a>Obtains the SDK API level that matches the current system software. </p>
</td>
</tr>
<tr id="row1055526979165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p808048732165625"><a name="p808048732165625"></a><a name="p808048732165625"></a><a href="parameter.md#ga6f62d683d76a160775b3ac46e856955e">GetFirstApiLevel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508302793165625"><a name="p1508302793165625"></a><a name="p1508302793165625"></a>char * </p>
<p id="p654648404165625"><a name="p654648404165625"></a><a name="p654648404165625"></a>Obtains the first SDK API level of the system software. </p>
</td>
</tr>
<tr id="row961537032165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p762491855165625"><a name="p762491855165625"></a><a name="p762491855165625"></a><a href="parameter.md#ga3d52b0a354555dbb16c265d5d5923546">GetIncrementalVersion</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p444693652165625"><a name="p444693652165625"></a><a name="p444693652165625"></a>char * </p>
<p id="p2080329053165625"><a name="p2080329053165625"></a><a name="p2080329053165625"></a>Obtains the incremental version. </p>
</td>
</tr>
<tr id="row1038959849165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112762551165625"><a name="p1112762551165625"></a><a name="p1112762551165625"></a><a href="parameter.md#gaea3cb294680fcef18a0a52f35fdaa124">GetVersionId</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p822836991165625"><a name="p822836991165625"></a><a name="p822836991165625"></a>char * </p>
<p id="p901019265165625"><a name="p901019265165625"></a><a name="p901019265165625"></a>Obtains the version ID. </p>
</td>
</tr>
<tr id="row586538071165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1686549847165625"><a name="p1686549847165625"></a><a name="p1686549847165625"></a><a href="parameter.md#gad1a95a2a073bf7f78c6a8513e29c3ddc">GetBuildType</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639323878165625"><a name="p1639323878165625"></a><a name="p1639323878165625"></a>char * </p>
<p id="p1278884336165625"><a name="p1278884336165625"></a><a name="p1278884336165625"></a>Obtains the build type. </p>
</td>
</tr>
<tr id="row640085161165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1940733752165625"><a name="p1940733752165625"></a><a name="p1940733752165625"></a><a href="parameter.md#gaa49edb9e675d928790a8ca7332905659">GetBuildUser</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639047318165625"><a name="p1639047318165625"></a><a name="p1639047318165625"></a>char * </p>
<p id="p146376729165625"><a name="p146376729165625"></a><a name="p146376729165625"></a>Obtains the build account user name. </p>
</td>
</tr>
<tr id="row2025868931165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264911207165625"><a name="p1264911207165625"></a><a name="p1264911207165625"></a><a href="parameter.md#ga54aad44d8a1c01ee1a3af82b5464e616">GetBuildHost</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435281041165625"><a name="p435281041165625"></a><a name="p435281041165625"></a>char * </p>
<p id="p868472547165625"><a name="p868472547165625"></a><a name="p868472547165625"></a>Obtains the build host name. </p>
</td>
</tr>
<tr id="row1086265011165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p737333855165625"><a name="p737333855165625"></a><a name="p737333855165625"></a><a href="parameter.md#ga6707dd0565fd65ab18149aa70ec233ac">GetBuildTime</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715643385165625"><a name="p715643385165625"></a><a name="p715643385165625"></a>char * </p>
<p id="p1778980345165625"><a name="p1778980345165625"></a><a name="p1778980345165625"></a>Obtains the version build time. </p>
</td>
</tr>
<tr id="row566075925165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1069782408165625"><a name="p1069782408165625"></a><a name="p1069782408165625"></a><a href="parameter.md#ga26f28a1bf6f0f3c550c716223397673c">GetBuildRootHash</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1406686130165625"><a name="p1406686130165625"></a><a name="p1406686130165625"></a>char * </p>
<p id="p516327576165625"><a name="p516327576165625"></a><a name="p516327576165625"></a>Obtains the buildroot hash value of this version. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1594484957165625"></a>

## **Function **<a name="section932383220165625"></a>

## GetAbiList\(\)<a name="gaa5e3d6179f398e407b632cc53410cd1a"></a>

```
char* GetAbiList (void )
```

 **Description:**

Obtains the list of application binary interfaces \(ABIs\) supported on this device. 

The interfaces in the ABI list are separated by commas \(,\). This function is available only for an OS with an ecosystem accommodating native applications. 

**Returns:**

Returns the ABI list if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBootloaderVersion\(\)<a name="gab033380f4acabc3304c401ea40034a3b"></a>

```
char* GetBootloaderVersion (void )
```

 **Description:**

Obtains the bootloader version of this device. 

The bootloader version can have a maximum length of 64 characters. 

**Returns:**

Returns the bootloader version if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBrand\(\)<a name="gaba787cc6f740d7d8f5e7ccd5a98fc7ed"></a>

```
char* GetBrand (void )
```

 **Description:**

Obtains the device brand. 

The device brand can have a maximum length of 32 characters. 

**Returns:**

Returns the device brand if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBuildHost\(\)<a name="ga54aad44d8a1c01ee1a3af82b5464e616"></a>

```
char* GetBuildHost (void )
```

 **Description:**

Obtains the build host name. 

The build host name can have a maximum length of 32 characters. 

**Returns:**

Returns the build host name if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBuildRootHash\(\)<a name="ga26f28a1bf6f0f3c550c716223397673c"></a>

```
char* GetBuildRootHash (void )
```

 **Description:**

Obtains the buildroot hash value of this version. 

The buildroot hash value is represented by the root hash value in the software version hash tree. 

**Returns:**

Returns the buildroot hash value if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBuildTime\(\)<a name="ga6707dd0565fd65ab18149aa70ec233ac"></a>

```
char* GetBuildTime (void )
```

 **Description:**

Obtains the version build time. 

The version build time is represented by the number of milliseconds elapsed since 1970-01-01 00:00:00 GMT. 

**Returns:**

Returns the version build time if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBuildType\(\)<a name="gad1a95a2a073bf7f78c6a8513e29c3ddc"></a>

```
char* GetBuildType (void )
```

 **Description:**

Obtains the build type. 

Different build types with the same baseline codes will be returned, for example,  **debug/release**  and  **log/nolog**. Multiple build types can be separated by semicolons \(;\). 

**Returns:**

Returns the build type if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetBuildUser\(\)<a name="gaa49edb9e675d928790a8ca7332905659"></a>

```
char* GetBuildUser (void )
```

 **Description:**

Obtains the build account user name. 

The build account user name can have a maximum length of 32 characters. 

**Returns:**

Returns the build account user name if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetDisplayVersion\(\)<a name="gaacd61c8a367a307d5b5c3e907822f271"></a>

```
char* GetDisplayVersion (void )
```

 **Description:**

Obtains the software version visible to users. 

The software version visible to users can have a maximum length of 64 characters. 

**Returns:**

Returns the software version visible to users if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetFirstApiLevel\(\)<a name="ga6f62d683d76a160775b3ac46e856955e"></a>

```
char* GetFirstApiLevel (void )
```

 **Description:**

Obtains the first SDK API level of the system software. 

In general, the first SDK API level is an integer. This function is only available for an OS with an ecosystem. 

**Returns:**

Returns the first SDK API level if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetHardwareModel\(\)<a name="ga0ff61721ab17eb07fcece1ccaf40293a"></a>

```
char* GetHardwareModel (void )
```

 **Description:**

Obtains the device hardware model. 

The device hardware model can have a maximum length of 32 characters. 

**Returns:**

Returns the device hardware model if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetHardwareProfile\(\)<a name="gaf98290ad8bd5328aff40293ff42d6a9b"></a>

```
char* GetHardwareProfile (void )
```

 **Description:**

Obtains the device hardware profile. 

The device hardware profile is a string in JSON format and has a maximum length of 1000 characters. 

**Returns:**

Returns the device hardware profile if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. The JSON field in the device hardware profile is defined as follows: 

<a name="table982667784165625"></a>
<table><thead align="left"><tr id="row1192769796165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p480537839165625"><a name="p480537839165625"></a><a name="p480537839165625"></a>Description </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p78044770165625"><a name="p78044770165625"></a><a name="p78044770165625"></a>key  </p>
</th>
</tr>
</thead>
<tbody><tr id="row201240374165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1390461370165625"><a name="p1390461370165625"></a><a name="p1390461370165625"></a>Audio playback </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p439090729165625"><a name="p439090729165625"></a><a name="p439090729165625"></a>aout </p>
</td>
</tr>
<tr id="row2082830168165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p965937782165625"><a name="p965937782165625"></a><a name="p965937782165625"></a>Display </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p801240301165625"><a name="p801240301165625"></a><a name="p801240301165625"></a>display </p>
</td>
</tr>
<tr id="row1616541263165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949492709165625"><a name="p949492709165625"></a><a name="p949492709165625"></a>Camera </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1855066563165625"><a name="p1855066563165625"></a><a name="p1855066563165625"></a>camera </p>
</td>
</tr>
<tr id="row1092471855165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83407796165625"><a name="p83407796165625"></a><a name="p83407796165625"></a>2D acceleration capability </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034321201165625"><a name="p2034321201165625"></a><a name="p2034321201165625"></a>DMA_2D </p>
</td>
</tr>
<tr id="row902003446165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2058424322165625"><a name="p2058424322165625"></a><a name="p2058424322165625"></a>Random-access memory </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p425355498165625"><a name="p425355498165625"></a><a name="p425355498165625"></a>RAM </p>
</td>
</tr>
<tr id="row114138997165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1503019930165625"><a name="p1503019930165625"></a><a name="p1503019930165625"></a>Read-only memory </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p173821300165625"><a name="p173821300165625"></a><a name="p173821300165625"></a>ROM </p>
</td>
</tr>
<tr id="row1540756789165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p54943034165625"><a name="p54943034165625"></a><a name="p54943034165625"></a>Graphics processing unit </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143318177165625"><a name="p1143318177165625"></a><a name="p1143318177165625"></a>GPU </p>
</td>
</tr>
<tr id="row818092800165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1367863029165625"><a name="p1367863029165625"></a><a name="p1367863029165625"></a>Neural-network processing unit </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p440999132165625"><a name="p440999132165625"></a><a name="p440999132165625"></a>NPU </p>
</td>
</tr>
<tr id="row23663368165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374407190165625"><a name="p374407190165625"></a><a name="p374407190165625"></a>Radio </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812194943165625"><a name="p812194943165625"></a><a name="p812194943165625"></a>radio </p>
</td>
</tr>
<tr id="row1105514238165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1521326134165625"><a name="p1521326134165625"></a><a name="p1521326134165625"></a>Bluetooth </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041388022165625"><a name="p2041388022165625"></a><a name="p2041388022165625"></a>bluetooth </p>
</td>
</tr>
<tr id="row1771717151165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p470755508165625"><a name="p470755508165625"></a><a name="p470755508165625"></a>Wi-Fi </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p952003335165625"><a name="p952003335165625"></a><a name="p952003335165625"></a>WIFI </p>
</td>
</tr>
<tr id="row1799282348165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p609472587165625"><a name="p609472587165625"></a><a name="p609472587165625"></a>USB </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964039443165625"><a name="p1964039443165625"></a><a name="p1964039443165625"></a>usbhost </p>
</td>
</tr>
</tbody>
</table>

## GetIncrementalVersion\(\)<a name="ga3d52b0a354555dbb16c265d5d5923546"></a>

```
char* GetIncrementalVersion (void )
```

 **Description:**

Obtains the incremental version. 

The incremental version can be used as the unique software version when the device model is the same. 

**Returns:**

Returns the incremental version if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetManufacture\(\)<a name="gad6d21dda3b027eb603dd24c7315ee6ea"></a>

```
char* GetManufacture (void )
```

 **Description:**

Obtains the device manufacturer. 

The device manufacturer can have a maximum length of 32 characters. 

**Returns:**

Returns the device manufacturer if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetMarketName\(\)<a name="gaa3adb204e5affd0a9e18828c1fbf2b0b"></a>

```
char* GetMarketName (void )
```

 **Description:**

Obtains the device marketing name. 

The device marketing name can have a maximum length of 32 characters. 

**Returns:**

Returns the device marketing name if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetOsName\(\)<a name="ga1402657e793875973f8801f631c29781"></a>

```
char* GetOsName (void )
```

 **Description:**

Obtains the operating system \(OS\) name. 

The device OS name can have a maximum length of 32 characters. 

**Returns:**

Returns the device OS name if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetParameter\(\)<a name="gae6a476fa36d2b1876eee0e4f256db6a6"></a>

```
int GetParameter (const char * key, const char * def, char * value, unsigned int len )
```

 **Description:**

Obtains a system parameter matching the specified  **key**. 

If no system parameter is found, the  **def**  parameter will be returned. 

**Parameters:**

<a name="table470465421165625"></a>
<table><thead align="left"><tr id="row491919059165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p648953179165625"><a name="p648953179165625"></a><a name="p648953179165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1339429935165625"><a name="p1339429935165625"></a><a name="p1339429935165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1581217531165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key for the system parameter to query. The value can contain lowercase letters, digits, underscores (_), and dots (.). Its length cannot exceed 32 bytes (including the end-of-text character in the string). </td>
</tr>
<tr id="row1825143649165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the default value to return when no query result is found. This parameter is specified by the caller. </td>
</tr>
<tr id="row490429114165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data buffer that stores the query result. This parameter is applied for and released by the caller and can be used as an output parameter. </td>
</tr>
<tr id="row1964646243165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the data in the buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes of the system parameter if the operation is successful; returns  **-9**  if a parameter is incorrect; returns  **-1**  in other scenarios. 

## GetProductModel\(\)<a name="gaa62644b77184644fac848f54837f4e5b"></a>

```
char* GetProductModel (void )
```

 **Description:**

Obtains the device authentication model. 

The device authentication model can have a maximum length of 32 characters. 

**Returns:**

Returns the device authentication model if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetProductSeries\(\)<a name="ga8a0d394075a3cbafe7ef0f51d08319a8"></a>

```
char* GetProductSeries (void )
```

 **Description:**

Obtains the device series name. 

The device series name can have a maximum length of 32 characters. 

**Returns:**

Returns the device series name if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetProductType\(\)<a name="ga2d6e83004da9cfdef6f3162d484163f1"></a>

```
char* GetProductType (void )
```

 **Description:**

Obtains the device type. 

The device type can have a maximum length of 32 characters. 

**Returns:**

Returns the device type if a result is found, for example, returns  **wifiiot**  if the application is running on a Wi-Fi connected IoT device; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetSdkApiLevel\(\)<a name="ga4720291ec5700581109e2f7943e2e371"></a>

```
char* GetSdkApiLevel (void )
```

 **Description:**

Obtains the SDK API level that matches the current system software. 

In general, the SDK API level is an integer. This function is only available for an OS with an ecosystem. 

**Returns:**

Returns the SDK API level if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetSecurityPatchTag\(\)<a name="gaa2407d8ce39e4a151b7e9d45123794c2"></a>

```
char* GetSecurityPatchTag (void )
```

 **Description:**

Obtains the security patch tag. 

**Returns:**

Returns the security patch tag if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetSerial\(\)<a name="gacc29ceeab6d312f3becdf19b28b9185d"></a>

```
char* GetSerial (void )
```

 **Description:**

Obtains the device serial number \(SN\). 

The device SN can have a maximum length of 64 characters. 

**Returns:**

Returns the device SN if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetSoftwareModel\(\)<a name="ga309a7fb6d9a60f6d6453e3faea030d7a"></a>

```
char* GetSoftwareModel (void )
```

 **Description:**

Obtains the device software model. 

The device software model can have a maximum length of 32 characters. 

**Returns:**

Returns the device software model if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## GetVersionId\(\)<a name="gaea3cb294680fcef18a0a52f35fdaa124"></a>

```
char* GetVersionId (void )
```

 **Description:**

Obtains the version ID. 

The version ID can have a maximum length of 127 characters. It is the unique identifier of a device. 

**Returns:**

Returns the version ID if a result is found; returns  **NULL**  otherwise. The return result is released by the caller. 

## SetParameter\(\)<a name="ga2779b5e59d43308c51f7be38b9c98ddb"></a>

```
int SetParameter (const char * key, const char * value )
```

 **Description:**

Sets or updates a system parameter. 

You can use this function to set a system parameter that matches  **key**  as  **value**. 

**Parameters:**

<a name="table295109552165625"></a>
<table><thead align="left"><tr id="row961104245165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2095033951165625"><a name="p2095033951165625"></a><a name="p2095033951165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p266370851165625"><a name="p266370851165625"></a><a name="p266370851165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1915276815165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key for the parameter to set or update. The value can contain lowercase letters, digits, underscores (_), and dots (.). Its length cannot exceed 32 bytes (including the end-of-text character in the string). </td>
</tr>
<tr id="row1036941785165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the system parameter value. Its length cannot exceed 128 bytes (including the end-of-text character in the string). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-9**  if a parameter is incorrect; returns  **-1**  in other scenarios. 

