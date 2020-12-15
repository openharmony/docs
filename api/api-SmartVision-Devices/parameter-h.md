# parameter.h<a name="ZH-CN_TOPIC_0000001054598137"></a>

-   [Overview](#section1819494151165628)
-   [Summary](#section1757813547165628)
-   [Functions](#func-members)

## **Overview**<a name="section1819494151165628"></a>

**Related Modules:**

[Parameter](Parameter.md)

**Description:**

Declares functions for obtaining system parameters. 

You can use the provided functions to obtain device information such as device type and manufacturer. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1757813547165628"></a>

## Functions<a name="func-members"></a>

<a name="table1228620143165628"></a>
<table><thead align="left"><tr id="row516584067165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1109339236165628"><a name="p1109339236165628"></a><a name="p1109339236165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1966020983165628"><a name="p1966020983165628"></a><a name="p1966020983165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row442134358165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443238704165628"><a name="p443238704165628"></a><a name="p443238704165628"></a><a href="Parameter.md#gae6a476fa36d2b1876eee0e4f256db6a6">GetParameter</a> (const char *key, const char *def, char *value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764650990165628"><a name="p1764650990165628"></a><a name="p1764650990165628"></a>int </p>
<p id="p2138348356165628"><a name="p2138348356165628"></a><a name="p2138348356165628"></a>Obtains a system parameter matching the specified <strong id="b1593864665165628"><a name="b1593864665165628"></a><a name="b1593864665165628"></a>key</strong>. </p>
</td>
</tr>
<tr id="row554036375165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117970495165628"><a name="p1117970495165628"></a><a name="p1117970495165628"></a><a href="Parameter.md#ga2779b5e59d43308c51f7be38b9c98ddb">SetParameter</a> (const char *key, const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1549192394165628"><a name="p1549192394165628"></a><a name="p1549192394165628"></a>int </p>
<p id="p1297640186165628"><a name="p1297640186165628"></a><a name="p1297640186165628"></a>Sets or updates a system parameter. </p>
</td>
</tr>
<tr id="row1795551326165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p421306486165628"><a name="p421306486165628"></a><a name="p421306486165628"></a><a href="Parameter.md#ga2d6e83004da9cfdef6f3162d484163f1">GetProductType</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p219780879165628"><a name="p219780879165628"></a><a name="p219780879165628"></a>char * </p>
<p id="p312459369165628"><a name="p312459369165628"></a><a name="p312459369165628"></a>Obtains the device type. </p>
</td>
</tr>
<tr id="row1487083116165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120223041165628"><a name="p2120223041165628"></a><a name="p2120223041165628"></a><a href="Parameter.md#gad6d21dda3b027eb603dd24c7315ee6ea">GetManufacture</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140152724165628"><a name="p1140152724165628"></a><a name="p1140152724165628"></a>char * </p>
<p id="p1053766622165628"><a name="p1053766622165628"></a><a name="p1053766622165628"></a>Obtains the device manufacturer. </p>
</td>
</tr>
<tr id="row620011168165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p630408761165628"><a name="p630408761165628"></a><a name="p630408761165628"></a><a href="Parameter.md#gaba787cc6f740d7d8f5e7ccd5a98fc7ed">GetBrand</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834288716165628"><a name="p1834288716165628"></a><a name="p1834288716165628"></a>char * </p>
<p id="p1895336488165628"><a name="p1895336488165628"></a><a name="p1895336488165628"></a>Obtains the device brand. </p>
</td>
</tr>
<tr id="row650208819165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029486104165628"><a name="p2029486104165628"></a><a name="p2029486104165628"></a><a href="Parameter.md#gaa3adb204e5affd0a9e18828c1fbf2b0b">GetMarketName</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297238521165628"><a name="p1297238521165628"></a><a name="p1297238521165628"></a>char * </p>
<p id="p1158430215165628"><a name="p1158430215165628"></a><a name="p1158430215165628"></a>Obtains the device marketing name. </p>
</td>
</tr>
<tr id="row825345735165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p211372525165628"><a name="p211372525165628"></a><a name="p211372525165628"></a><a href="Parameter.md#ga8a0d394075a3cbafe7ef0f51d08319a8">GetProductSeries</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1918057197165628"><a name="p1918057197165628"></a><a name="p1918057197165628"></a>char * </p>
<p id="p1224363203165628"><a name="p1224363203165628"></a><a name="p1224363203165628"></a>Obtains the device series name. </p>
</td>
</tr>
<tr id="row1993207628165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1232718745165628"><a name="p1232718745165628"></a><a name="p1232718745165628"></a><a href="Parameter.md#gaa62644b77184644fac848f54837f4e5b">GetProductModel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p477672144165628"><a name="p477672144165628"></a><a name="p477672144165628"></a>char * </p>
<p id="p1254513702165628"><a name="p1254513702165628"></a><a name="p1254513702165628"></a>Obtains the device authentication model. </p>
</td>
</tr>
<tr id="row1460891679165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p803862632165628"><a name="p803862632165628"></a><a name="p803862632165628"></a><a href="Parameter.md#ga309a7fb6d9a60f6d6453e3faea030d7a">GetSoftwareModel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p886800405165628"><a name="p886800405165628"></a><a name="p886800405165628"></a>char * </p>
<p id="p95819103165628"><a name="p95819103165628"></a><a name="p95819103165628"></a>Obtains the device software model. </p>
</td>
</tr>
<tr id="row574803634165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1965664661165628"><a name="p1965664661165628"></a><a name="p1965664661165628"></a><a href="Parameter.md#ga0ff61721ab17eb07fcece1ccaf40293a">GetHardwareModel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p547865096165628"><a name="p547865096165628"></a><a name="p547865096165628"></a>char * </p>
<p id="p2037739075165628"><a name="p2037739075165628"></a><a name="p2037739075165628"></a>Obtains the device hardware model. </p>
</td>
</tr>
<tr id="row439770383165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887750122165628"><a name="p887750122165628"></a><a name="p887750122165628"></a><a href="Parameter.md#gaf98290ad8bd5328aff40293ff42d6a9b">GetHardwareProfile</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441500384165628"><a name="p441500384165628"></a><a name="p441500384165628"></a>char * </p>
<p id="p1864266413165628"><a name="p1864266413165628"></a><a name="p1864266413165628"></a>Obtains the device hardware profile. </p>
</td>
</tr>
<tr id="row260838653165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p739969539165628"><a name="p739969539165628"></a><a name="p739969539165628"></a><a href="Parameter.md#gacc29ceeab6d312f3becdf19b28b9185d">GetSerial</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019884513165628"><a name="p1019884513165628"></a><a name="p1019884513165628"></a>char * </p>
<p id="p1179498542165628"><a name="p1179498542165628"></a><a name="p1179498542165628"></a>Obtains the device serial number (SN). </p>
</td>
</tr>
<tr id="row1727991348165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133421901165628"><a name="p2133421901165628"></a><a name="p2133421901165628"></a><a href="Parameter.md#ga1402657e793875973f8801f631c29781">GetOsName</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475986647165628"><a name="p475986647165628"></a><a name="p475986647165628"></a>char * </p>
<p id="p774719411165628"><a name="p774719411165628"></a><a name="p774719411165628"></a>Obtains the operating system (OS) name. </p>
</td>
</tr>
<tr id="row983501123165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1034729191165628"><a name="p1034729191165628"></a><a name="p1034729191165628"></a><a href="Parameter.md#gaacd61c8a367a307d5b5c3e907822f271">GetDisplayVersion</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1685109952165628"><a name="p1685109952165628"></a><a name="p1685109952165628"></a>char * </p>
<p id="p1645376600165628"><a name="p1645376600165628"></a><a name="p1645376600165628"></a>Obtains the software version visible to users. </p>
</td>
</tr>
<tr id="row1935784899165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282602449165628"><a name="p282602449165628"></a><a name="p282602449165628"></a><a href="Parameter.md#gab033380f4acabc3304c401ea40034a3b">GetBootloaderVersion</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030300422165628"><a name="p1030300422165628"></a><a name="p1030300422165628"></a>char * </p>
<p id="p1601723414165628"><a name="p1601723414165628"></a><a name="p1601723414165628"></a>Obtains the bootloader version of this device. </p>
</td>
</tr>
<tr id="row1532691756165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459959145165628"><a name="p1459959145165628"></a><a name="p1459959145165628"></a><a href="Parameter.md#gaa2407d8ce39e4a151b7e9d45123794c2">GetSecurityPatchTag</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1023490359165628"><a name="p1023490359165628"></a><a name="p1023490359165628"></a>char * </p>
<p id="p17523033165628"><a name="p17523033165628"></a><a name="p17523033165628"></a>Obtains the security patch tag. </p>
</td>
</tr>
<tr id="row2046368789165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p944024446165628"><a name="p944024446165628"></a><a name="p944024446165628"></a><a href="Parameter.md#gaa5e3d6179f398e407b632cc53410cd1a">GetAbiList</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39046446165628"><a name="p39046446165628"></a><a name="p39046446165628"></a>char * </p>
<p id="p1152732447165628"><a name="p1152732447165628"></a><a name="p1152732447165628"></a>Obtains the list of application binary interfaces (ABIs) supported on this device. </p>
</td>
</tr>
<tr id="row243775692165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p822282140165628"><a name="p822282140165628"></a><a name="p822282140165628"></a><a href="Parameter.md#ga4720291ec5700581109e2f7943e2e371">GetSdkApiLevel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1340313514165628"><a name="p1340313514165628"></a><a name="p1340313514165628"></a>char * </p>
<p id="p1152007262165628"><a name="p1152007262165628"></a><a name="p1152007262165628"></a>Obtains the SDK API level that matches the current system software. </p>
</td>
</tr>
<tr id="row126505516165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p508817301165628"><a name="p508817301165628"></a><a name="p508817301165628"></a><a href="Parameter.md#ga6f62d683d76a160775b3ac46e856955e">GetFirstApiLevel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p463775456165628"><a name="p463775456165628"></a><a name="p463775456165628"></a>char * </p>
<p id="p1338706440165628"><a name="p1338706440165628"></a><a name="p1338706440165628"></a>Obtains the first SDK API level of the system software. </p>
</td>
</tr>
<tr id="row919275229165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1187168703165628"><a name="p1187168703165628"></a><a name="p1187168703165628"></a><a href="Parameter.md#ga3d52b0a354555dbb16c265d5d5923546">GetIncrementalVersion</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1376290555165628"><a name="p1376290555165628"></a><a name="p1376290555165628"></a>char * </p>
<p id="p1046445544165628"><a name="p1046445544165628"></a><a name="p1046445544165628"></a>Obtains the incremental version. </p>
</td>
</tr>
<tr id="row799152773165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p9559053165628"><a name="p9559053165628"></a><a name="p9559053165628"></a><a href="Parameter.md#gaea3cb294680fcef18a0a52f35fdaa124">GetVersionId</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p340099766165628"><a name="p340099766165628"></a><a name="p340099766165628"></a>char * </p>
<p id="p834788559165628"><a name="p834788559165628"></a><a name="p834788559165628"></a>Obtains the version ID. </p>
</td>
</tr>
<tr id="row158201372165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p410313154165628"><a name="p410313154165628"></a><a name="p410313154165628"></a><a href="Parameter.md#gad1a95a2a073bf7f78c6a8513e29c3ddc">GetBuildType</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353260804165628"><a name="p1353260804165628"></a><a name="p1353260804165628"></a>char * </p>
<p id="p1140877495165628"><a name="p1140877495165628"></a><a name="p1140877495165628"></a>Obtains the build type. </p>
</td>
</tr>
<tr id="row732101672165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396685369165628"><a name="p1396685369165628"></a><a name="p1396685369165628"></a><a href="Parameter.md#gaa49edb9e675d928790a8ca7332905659">GetBuildUser</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722181528165628"><a name="p722181528165628"></a><a name="p722181528165628"></a>char * </p>
<p id="p664314737165628"><a name="p664314737165628"></a><a name="p664314737165628"></a>Obtains the build account user name. </p>
</td>
</tr>
<tr id="row1301333583165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p305338346165628"><a name="p305338346165628"></a><a name="p305338346165628"></a><a href="Parameter.md#ga54aad44d8a1c01ee1a3af82b5464e616">GetBuildHost</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p123460386165628"><a name="p123460386165628"></a><a name="p123460386165628"></a>char * </p>
<p id="p927150291165628"><a name="p927150291165628"></a><a name="p927150291165628"></a>Obtains the build host name. </p>
</td>
</tr>
<tr id="row1763594485165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1951101946165628"><a name="p1951101946165628"></a><a name="p1951101946165628"></a><a href="Parameter.md#ga6707dd0565fd65ab18149aa70ec233ac">GetBuildTime</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499938060165628"><a name="p499938060165628"></a><a name="p499938060165628"></a>char * </p>
<p id="p1653300448165628"><a name="p1653300448165628"></a><a name="p1653300448165628"></a>Obtains the version build time. </p>
</td>
</tr>
<tr id="row10452495165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1554999076165628"><a name="p1554999076165628"></a><a name="p1554999076165628"></a><a href="Parameter.md#ga26f28a1bf6f0f3c550c716223397673c">GetBuildRootHash</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034410987165628"><a name="p1034410987165628"></a><a name="p1034410987165628"></a>char * </p>
<p id="p1839048201165628"><a name="p1839048201165628"></a><a name="p1839048201165628"></a>Obtains the buildroot hash value of this version. </p>
</td>
</tr>
</tbody>
</table>

