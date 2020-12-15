# BundleManager<a name="ZH-CN_TOPIC_0000001054918105"></a>

-   [Overview](#section931510718165623)
-   [Summary](#section1517998658165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section165948216165623)
-   [Typedef](#section160203913165623)
-   [BundleStateCallback](#gad7ea6d0bf78db2d59e6d339c31819885)
-   [InstallerCallback](#ga00f021e76d728d2d44e1a28887ccc3af)
-   [Enumeration Type](#section76133345165623)
-   [AbilityType](#ga44b675d687acff3d739404c1227b4259)
-   [AppexecfwkErrors](#gac318d4f4dc0125e2367ea8c539770ed1)
-   [InstallLocation](#ga4907fd26df42a0abdfd6ade10ac44efb)
-   [LaunchMode](#ga605d46d860e356a74db6842e66522854)
-   [Function](#section1955086544165623)
-   [ClearAbilityInfo\(\)](#ga7377545918725f75645b59b1b7a319fa)
-   [ClearBundleInfo\(\)](#ga78829b21273aefd65844eba4549162ca)
-   [ClearBundleStatusCallback\(\)](#gae5e0593438f073199bf6d69e47a84975)
-   [ClearElement\(\)](#ga3abe15ac14571de84ca72c98f4009724)
-   [ClearModuleInfo\(\)](#ga6c2242cc10f135d129b95444faacb345)
-   [GetBundleInfo\(\)](#ga5e81134e037911654e34cc8a7ba01a2f)
-   [GetBundleInfos\(\)](#ga2469dafbc61ba8e98b69041c13044cad)
-   [GetBundleInfosByMetaData\(\)](#ga711965038390aef4fa0a6b6a98f6998b)
-   [GetBundleNameForUid\(\)](#ga4afdc08ba78506fce95a066e137ac46d)
-   [Install\(\)](#gaf1f1521a64cc98f076b0082df6c0abdd)
-   [QueryAbilityInfo\(\)](#ga4360375d15224d89632f59ee110b74c9)
-   [QueryKeepAliveBundleInfos\(\)](#ga0c1cb00194993ecba7337fdf0a203314)
-   [RegisterCallback\(\)](#ga5c49620ca8b752cd6f43fabc5d5c7416)
-   [SetElementAbilityName\(\)](#ga93a575cc428cb96526ae02b3997f1f3b)
-   [SetElementBundleName\(\)](#ga60692e66a3a204a2f16f70c5cd452c1d)
-   [SetElementDeviceID\(\)](#ga90e16f159ee8e7f1a9385feebb3dbc0c)
-   [Uninstall\(\)](#gaa117e44378315a61b4e71fd252b2e496)
-   [UnregisterCallback\(\)](#ga095eee592eff6ce71a2a67a1a0e3e344)

## **Overview**<a name="section931510718165623"></a>

**Description:**

Provides structures and functions for managing application bundles and obtaining application information. 

You can use functions provided by this module to install, update, or uninstall an application, obtain  [AbilityInfo](AbilityInfo.md)  and  [BundleInfo](BundleInfo.md)  about an application, and obtain the bundle name of an application based on the application's user ID \(UID\).

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1517998658165623"></a>

## Files<a name="files"></a>

<a name="table1999413607165623"></a>
<table><thead align="left"><tr id="row2141790624165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1668137408165623"><a name="p1668137408165623"></a><a name="p1668137408165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1844325320165623"><a name="p1844325320165623"></a><a name="p1844325320165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1116596069165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p988198915165623"><a name="p988198915165623"></a><a name="p988198915165623"></a><a href="ability_info-h.md">ability_info.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493821708165623"><a name="p1493821708165623"></a><a name="p1493821708165623"></a>Declares structures and functions for managing ability information. </p>
</td>
</tr>
<tr id="row788880366165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821126534165623"><a name="p1821126534165623"></a><a name="p1821126534165623"></a><a href="appexecfwk_errors-h.md">appexecfwk_errors.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1108779841165623"><a name="p1108779841165623"></a><a name="p1108779841165623"></a>Declares error codes returned by bundle management functions. </p>
</td>
</tr>
<tr id="row953336904165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526648400165623"><a name="p1526648400165623"></a><a name="p1526648400165623"></a><a href="bundle_info-h.md">bundle_info.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1976261763165623"><a name="p1976261763165623"></a><a name="p1976261763165623"></a>Declares structures and functions for managing application bundle information. </p>
</td>
</tr>
<tr id="row681543600165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p39600106165623"><a name="p39600106165623"></a><a name="p39600106165623"></a><a href="bundle_manager-h.md">bundle_manager.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1161276675165623"><a name="p1161276675165623"></a><a name="p1161276675165623"></a>Declares functions used for managing application bundles and obtaining bundle information. </p>
</td>
</tr>
<tr id="row615534804165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1104630055165623"><a name="p1104630055165623"></a><a name="p1104630055165623"></a><a href="bundle_status_callback-h.md">bundle_status_callback.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447160930165623"><a name="p1447160930165623"></a><a name="p1447160930165623"></a>Declares the callback invoked upon state changes of an application and the structure defining the callback information. </p>
</td>
</tr>
<tr id="row1987533096165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605505675165623"><a name="p605505675165623"></a><a name="p605505675165623"></a><a href="element_name-h.md">element_name.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734863496165623"><a name="p734863496165623"></a><a name="p734863496165623"></a>Declares the structure that defines the required information for querying <a href="AbilityInfo.md">AbilityInfo</a>, including the device ID, bundle name, and class name, and functions for setting such information. </p>
</td>
</tr>
<tr id="row1437588871165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967319976165623"><a name="p967319976165623"></a><a name="p967319976165623"></a><a href="module_info-h.md">module_info.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942570504165623"><a name="p942570504165623"></a><a name="p942570504165623"></a>Declares structures and functions for managing HAP package information. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table504931217165623"></a>
<table><thead align="left"><tr id="row72137364165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p406955015165623"><a name="p406955015165623"></a><a name="p406955015165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p863251018165623"><a name="p863251018165623"></a><a name="p863251018165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row190621484165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p969231836165623"><a name="p969231836165623"></a><a name="p969231836165623"></a><a href="AbilityInfo.md">AbilityInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p958698132165623"><a name="p958698132165623"></a><a name="p958698132165623"></a>Defines the ability information. </p>
</td>
</tr>
<tr id="row177310896165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1508058970165623"><a name="p1508058970165623"></a><a name="p1508058970165623"></a><a href="BundleInfo.md">BundleInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p634973202165623"><a name="p634973202165623"></a><a name="p634973202165623"></a>Defines the bundle information. </p>
</td>
</tr>
<tr id="row875312647165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026340963165623"><a name="p1026340963165623"></a><a name="p1026340963165623"></a><a href="BundleStatusCallback.md">BundleStatusCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1027582539165623"><a name="p1027582539165623"></a><a name="p1027582539165623"></a>Defines the application state callback information. </p>
</td>
</tr>
<tr id="row606277947165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1189997270165623"><a name="p1189997270165623"></a><a name="p1189997270165623"></a><a href="ElementName.md">ElementName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2109971119165623"><a name="p2109971119165623"></a><a name="p2109971119165623"></a>Defines the ability information. </p>
</td>
</tr>
<tr id="row1915234988165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281105937165623"><a name="p1281105937165623"></a><a name="p1281105937165623"></a><a href="InstallParam.md">InstallParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643233191165623"><a name="p1643233191165623"></a><a name="p1643233191165623"></a>Defines parameters used for application installation, update, or uninstallation. </p>
</td>
</tr>
<tr id="row600753177165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32825566165623"><a name="p32825566165623"></a><a name="p32825566165623"></a><a href="MetaData.md">MetaData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006719422165623"><a name="p2006719422165623"></a><a name="p2006719422165623"></a>Defines the metadata information in a <a href="ModuleInfo.md">ModuleInfo</a> object. </p>
</td>
</tr>
<tr id="row1392623341165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656935074165623"><a name="p1656935074165623"></a><a name="p1656935074165623"></a><a href="ModuleInfo.md">ModuleInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235556049165623"><a name="p1235556049165623"></a><a name="p1235556049165623"></a>Defines the HAP information. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1747839108165623"></a>
<table><thead align="left"><tr id="row1431840193165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p579582674165623"><a name="p579582674165623"></a><a name="p579582674165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p949627881165623"><a name="p949627881165623"></a><a name="p949627881165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1098164463165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p767408137165623"><a name="p767408137165623"></a><a name="p767408137165623"></a><a href="BundleManager.md#ga00f021e76d728d2d44e1a28887ccc3af">InstallerCallback</a>) (const uint8_t resultCode, const void *resultMessage)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812078604165623"><a name="p812078604165623"></a><a name="p812078604165623"></a>typedef void(* </p>
<p id="p1295579240165623"><a name="p1295579240165623"></a><a name="p1295579240165623"></a>Called when an application is installed, updated, or uninstalled. </p>
</td>
</tr>
<tr id="row1435351286165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495348767165623"><a name="p495348767165623"></a><a name="p495348767165623"></a><a href="BundleManager.md#gad7ea6d0bf78db2d59e6d339c31819885">BundleStateCallback</a>) (const uint8_t installType, const uint8_t resultCode, const void *resultMessage, const char *bundleName, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1853827106165623"><a name="p1853827106165623"></a><a name="p1853827106165623"></a>typedef void(* </p>
<p id="p1170233179165623"><a name="p1170233179165623"></a><a name="p1170233179165623"></a>Called when the installation, update, or uninstallation state of an application changes. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table2076953210165623"></a>
<table><thead align="left"><tr id="row618876184165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1265118062165623"><a name="p1265118062165623"></a><a name="p1265118062165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p290368552165623"><a name="p290368552165623"></a><a name="p290368552165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row226246926165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280585233165623"><a name="p1280585233165623"></a><a name="p1280585233165623"></a><a href="BundleManager.md#ga44b675d687acff3d739404c1227b4259">AbilityType</a> { <a href="BundleManager.md#gga44b675d687acff3d739404c1227b4259a6ce26a62afab55d7606ad4e92428b30c">UNKNOWN</a> = 0, <a href="BundleManager.md#gga44b675d687acff3d739404c1227b4259ab788d9e2cde88d51a5cda409f75db490">PAGE</a>, <a href="BundleManager.md#gga44b675d687acff3d739404c1227b4259a5f6d448017ecd0a56245e38b76596e07">SERVICE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1921894278165623"><a name="p1921894278165623"></a><a name="p1921894278165623"></a>Enumerates types of templates used by an ability. </p>
</td>
</tr>
<tr id="row1805666762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1021152775165623"><a name="p1021152775165623"></a><a name="p1021152775165623"></a><a href="BundleManager.md#ga605d46d860e356a74db6842e66522854">LaunchMode</a> { <a href="BundleManager.md#gga605d46d860e356a74db6842e66522854a57da18394d2f90538c40b0b8d4a3a3c7">SINGLETON</a> = 0, <a href="BundleManager.md#gga605d46d860e356a74db6842e66522854a9de934790934fe831fe946c851e8338e">STANDARD</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220221921165623"><a name="p220221921165623"></a><a name="p220221921165623"></a>Enumerates startup modes of an ability. </p>
</td>
</tr>
<tr id="row143237948165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651763706165623"><a name="p1651763706165623"></a><a name="p1651763706165623"></a><a href="BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1">AppexecfwkErrors</a> {   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb">ERR_OK</a> = 0, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ac56903bcb53061d4ccd81f356e2e6dff">ERR_APPEXECFWK_QUERY_PARAMETER_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a6609bd5ca64e005d23794eb0a9e65058">ERR_APPEXECFWK_QUERY_NO_INFOS</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a862f4edaae059afe7505f3a2355ace7a">ERR_APPEXECFWK_QUERY_INFOS_INIT_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a5d6b76480d9c381a4ea582e42ae13723">ERR_APPEXECFWK_OBJECT_NULL</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ab6bf660df1f71efbbc1dc171026e8b19">ERR_APPEXECFWK_INSTALL_FAILED_INTERNAL_ERROR</a> = 10, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a0d0ff29443bea7409cb49aa65276a734">ERR_APPEXECFWK_INSTALL_FAILED_PARAM_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ab5e45300939da4427f50b6a765701e34">ERR_APPEXECFWK_INSTALL_FAILED_FILE_PATH_INVALID</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a6242775e55f8eb650cc92fd8a3388e32">ERR_APPEXECFWK_INSTALL_FAILED_FILE_NOT_EXISTS</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a3f98ba8a2755dbb204d87abc64744d62">ERR_APPEXECFWK_INSTALL_FAILED_INVALID_FILE_NAME</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a74a6ca143ea4633376530ee2e9ce6eb1">ERR_APPEXECFWK_INSTALL_FAILED_BAD_FILE</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a02521dcb943509971fe14bfb8468a98d">ERR_APPEXECFWK_INSTALL_FAILED_CREATE_FILE_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a72f16cafaafe6ff6e7069a2ef28507a7">ERR_APPEXECFWK_INSTALL_FAILED_CREATE_PERMISSIONS_DIR_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ab0d26918c1d8d1481601567cf87f2621">ERR_APPEXECFWK_INSTALL_FAILED_RENAME_DIR_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aaafdb262ffe01eed1722350d270cf09d">ERR_APPEXECFWK_INSTALL_FAILED_RENAME_FILE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a9e457f181dce9e221dfa01c257d7fe12">ERR_APPEXECFWK_INSTALL_FAILED_CREATE_DATA_DIR_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ac62be957615c89ae23b780d8d288419e">ERR_APPEXECFWK_INSTALL_FAILED_RECORD_INFO_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a438581dc1abee81ed846d9dafee34e83">ERR_APPEXECFWK_INSTALL_FAILED_UID_AND_GID_BACKUP_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a0d874b79e811844325c76f65630db989">ERR_APPEXECFWK_INSTALL_FAILED_VERSION_DOWNGRADE</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a6ef4ca2fed2c05c5ec553f4e12844bac">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_BUNDLE_NUMBER</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a8599367df053820365395e64ae536e81">ERR_APPEXECFWK_INSTALL_FAILED_STORE_PERMISSIONS_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1adb1e3b901e0a5b88460f661a533b08f8">ERR_APPEXECFWK_INSTALL_FAILED_FILE_DATA_INVALID</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a2b9a032c6b9c843e1101cf753b2fa6fa">ERR_APPEXECFWK_INSTALL_FAILED_INCOMPATIBLE_SIGNATURE</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ab1dc9dd09156cc2b06643624d8465ea9">ERR_APPEXECFWK_INSTALL_FAILED_INVALID_PROVISIONINFO</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a06b51bb80923d2d9271f902f75842063">ERR_APPEXECFWK_INSTALL_FAILED_OPERATE_SIGNED_FILE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a34439d18e6612f31ba634766c3da6457">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_APP_SIGNATURE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a553374f3e17c7a39f6fbf9ecd932b618">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_PROFILE_SIGNATURE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a2c992cbdee385fbc00fecd0e313b33fc">ERR_APPEXECFWK_INSTALL_FAILED_INTERNAL_SIGNATURE_ERROR</a> ,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a17e1305d5eeee7867a98c295c488e236">ERR_APPEXECFWK_SET_DEBUG_MODE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aef3bf9de62376b9d91070956c1a0b6a0">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_PROFILE_ERROR</a> = 40, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a014b98d9df51b98ff37f95aaba97c63f">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_BUNDLENAME_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a1ab7654bdb5ca8fcba99e6acb9ad4163">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_INVALID_BUNDLENAME</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a7f159724dde9d3ec69a22fd97c7c4275">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_VENDOR_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ad569e1e0e50704d8d94394b39df13599">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_VERSIONCODE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a26e4922b83c0a42f8576cb81cd0760e2">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_VERSIONNAME_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a022e0b7e7b978eda5e43db46efe9c916">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_PERMISSIONS_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ac449d6df4540c1794f1b76599435c4df">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_API_VERSION_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a05262a83fbc2d5817772db9a20d6c503">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DEVICE_CONFIG_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1abcb1a3e0509445e2bff7dad43c379971">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_KEEPALIVE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a27d9af1e04f75bc389f35b3318ad1590">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_MODULENAME_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a38afd7346c84b9d618aa1a477316c3ca">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_INVALID_MODULENAME</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1af244274d1cf39090d9818aac15882e4c">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_MODULE_DESCRIPTION_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ac36ac4af8d61e10431c39fe545f8f623">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DEVICETYPE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a04f7cee0fe708631364d56e53fc7a2d8">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aba3187880d4a57348ac2cd3943546dd1">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_MODULENAME_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a1c88e191b397644827022b0a238007da">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_MODULETYPE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a9ec099feb69dc64a4f3bd48475723bba">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_DELIVERY_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a98508d3e35c99d09320ffd498469b984">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_METADATA_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a1649053e390e2b20ac96674aa7d7ca88">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITIES_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1adbf64bab15b50b69286efa90f7f1dec1">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_NAME_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aeefcd3f1a247768fc5fb2f59c0f1b966">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_TYPE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a8a282ca74395e3007dd75c90d671fe23">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_ICONPATH_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a3c6dcb2ca14788595975cea51bf1cfed">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_LABEL_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a164231485c5ea694f9a0b4d8307d5901">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_DESCRIPTION_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a6a592b570f8c29dc1c4161faedcf2acd">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_LAUNCHTYPE_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a7d51c40e62b04e8bc2991db294fd10f3">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_VISIBLE_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa83132144c11442291f4a971e51dcbb1">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_INVALID_BUNDLENAME_LENGTH</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a1e7f0159d459e0f416c05bcd106d8782">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_LABEL_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1af6fb04f5b2b34761822d84670f19e7ce">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_VERSIONNAME_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a4d20732be30f3bc677ed0fff3b79aa93">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_METADATA_NAME_LENGTH_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a4ddea99589bb62ae0297742763a12c1a">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_METADATA_VALUE_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aabd55ad27e4671083b36aa1a9bce53b2">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_VENDOR_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a85ed32b668e813a868dff8f11d1a0259">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_MODULENAME_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a2fd9e57b401b4c4ecb7f737d9cfb7f1a">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_ABILITYNAME_LENGTH_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1acb65a2d440e7aee4541ea265317582e0">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_ABILITY_DESCRIPTION_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a7d764e29e35ead6dbbca9302c284ee00">ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_ABILITY_LABEL_LENGTH_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aebc061682db1151f24248f0ca34eca98">ERR_APPEXECFWK_INSTALL_FAILED_EXTRACTOR_NOT_INIT</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a797b7558d35fdb43a923aaac8c464187">ERR_APPEXECFWK_INSTALL_FAILED_EXTRACT_HAP_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aeacdda0db2432c52b0795208bf69408e">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_JS_DIR_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a3a521918e6b836de9b70325a0a643362">ERR_APPEXECFWK_INSTALL_FAILED_RESOURCE_INDEX_NOT_EXISTS</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1acc1f483da695764aa8f3f22d697c8969">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_LABEL_RES_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a572a4b52c204c83b1742eb1fc8364a1a">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ICON_RES_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a128bf2cca7073ed0a6299c7d8529e33d">ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DESCRIPTION_RES_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ac31bcc78028487c5be87399325332380">ERR_APPEXECFWK_INSTALL_FAILED_SEND_REQUEST_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a26ff3a2760ff20c60aba2ab125ecdd17">ERR_APPEXECFWK_UNINSTALL_FAILED_INTERNAL_ERROR</a> = 90, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ae0670ff00ddfc9f4642815d13e50e732">ERR_APPEXECFWK_UNINSTALL_FAILED_PARAM_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a8d6b6bf5861d928ca86ddaeeb15c062a">ERR_APPEXECFWK_UNINSTALL_FAILED_BUNDLE_NOT_EXISTS</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a4949cab6b3e4f97fd44151eba0d488bb">ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_DIRS_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a9e5f0727ceed161044cf4bfdacec12e2">ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_RECORD_INFO_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a0050a0cd61152432d89221b3ed178724">ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_PERMISSIONS_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a58c70df1bf55bc3c2b61e2c0f0571a2f">ERR_APPEXECFWK_UNINSTALL_FAILED_BUNDLE_NOT_UNINSTALLABLE</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a11b7780ad61c6085f475c5415de34191">ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_UID_INFO_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a1e2b896e9cc48287bed17cd2835f44cb">ERR_APPEXECFWK_UNINSTALL_FAILED_SEND_REQUEST_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a3fbc51865d3bf19ead1c7e42c6058a42">ERR_APPEXECFWK_DUMP_ERROR</a> = 100,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a35c07d2afc0f8b17822a9f64b19a8993">ERR_APPEXECFWK_COMMAND_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a4d22c64508c3f6c3a9c3e8972e54696c">ERR_APPEXECFWK_CALLBACK_REGISTER_FAILED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ae0dd6d1b6cc227e1a67c910182dee9f9">ERR_APPEXECFWK_CALLBACK_UNREGISTER_FAILED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a3fc6a7d606bdfc9a569c732f7fc0dc85">ERR_APPEXECFWK_CALLBACK_GENERATE_LOCAL_SERVICEID_FAILED</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a030663d47f1763759349ab34509a2c1c">ERR_APPEXECFWK_CALLBACK_SERVICEID_TRANSMITTED_FAILED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aeb276d0adcc605cee18e3e06f641626e">ERR_APPEXECFWK_CALLBACK_NEVER_REGISTERED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ab853bfd0b4558a663bd683ab6a365c8b">ERR_APPEXECFWK_CALLBACK_OBTAIN_ALL_BUNDLE_FAILED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a8e8a7a1f2d610d5f078dc79959776930">ERR_APPEXECFWK_CALLBACK_NULL_CORRESPONDING_CALLBACK</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1acb14a1daa5fe17eb25798bbcd98bcd57">ERR_APPEXECFWK_CALLBACK_GET_INSTALLTYPE_FAILED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a8898f52b989730709638b26bcb555f54">ERR_APPEXECFWK_CALLBACK_GET_ERROR_INSTALLTYPE</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1ae31533f402b130eb4cc8fed07706c5b6">ERR_APPEXECFWK_SERIALIZATION_FAILED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a66b8941c7c418eedc7df7f758cbacc42">ERR_APPEXECFWK_DESERIALIZATION_FAILED</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a19aa79fde7b3e4da78567e4fcbe306a7">ERR_APPEXECFWK_SYSTEM_INTERNAL_ERROR</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a0ad2ce2d577f995c2ba3ea946ce366e6">ERR_APPEXECFWK_NO_BUNDLENAME_FOR_UID</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a9161dd6c967af438a56b01cd916e01c2">ERR_APPEXECFWK_IPCIO_UNAVAILABLED</a>, <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a6cff9490f5817281ac9c2bcdafcf477f">ERR_APPEXECFWK_INVOKE_ERROR</a>,   <a href="BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1a2c357a03505c34ef9a843876af91739e">ERR_APPEXECFWK_PERMISSION_DENIED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43358892165623"><a name="p43358892165623"></a><a name="p43358892165623"></a>Enumerates error codes provided by the Bundle Manager <a href="Service.md">Service</a>. </p>
</td>
</tr>
<tr id="row1841111256165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1534722742165623"><a name="p1534722742165623"></a><a name="p1534722742165623"></a><a href="BundleManager.md#ga4907fd26df42a0abdfd6ade10ac44efb">InstallLocation</a> { <a href="BundleManager.md#gga4907fd26df42a0abdfd6ade10ac44efbac2928120cea5ab364b9a0d65ef2ab2dc">INSTALL_LOCATION_INTERNAL_ONLY</a> = 1, <a href="BundleManager.md#gga4907fd26df42a0abdfd6ade10ac44efba2322c010e922d34c040d41cc7ed664ec">INSTALL_LOCATION_PREFER_EXTERNAL</a> = 2 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1878294556165623"></a>
<table><thead align="left"><tr id="row1336369730165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p941334415165623"><a name="p941334415165623"></a><a name="p941334415165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1501536771165623"><a name="p1501536771165623"></a><a name="p1501536771165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1196547109165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005888200165623"><a name="p1005888200165623"></a><a name="p1005888200165623"></a><a href="BundleManager.md#ga7377545918725f75645b59b1b7a319fa">ClearAbilityInfo</a> (<a href="AbilityInfo.md">AbilityInfo</a> *abilityInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p953359898165623"><a name="p953359898165623"></a><a name="p953359898165623"></a>void </p>
<p id="p1213895168165623"><a name="p1213895168165623"></a><a name="p1213895168165623"></a>Clears an <a href="AbilityInfo.md">AbilityInfo</a> object. </p>
</td>
</tr>
<tr id="row1220219315165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895272955165623"><a name="p1895272955165623"></a><a name="p1895272955165623"></a><a href="BundleManager.md#ga78829b21273aefd65844eba4549162ca">ClearBundleInfo</a> (<a href="BundleInfo.md">BundleInfo</a> *bundleInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1298437040165623"><a name="p1298437040165623"></a><a name="p1298437040165623"></a>void </p>
<p id="p1050338163165623"><a name="p1050338163165623"></a><a name="p1050338163165623"></a>Clears a <a href="BundleInfo.md">BundleInfo</a> object. </p>
</td>
</tr>
<tr id="row538450532165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105470407165623"><a name="p2105470407165623"></a><a name="p2105470407165623"></a><a href="BundleManager.md#ga5c49620ca8b752cd6f43fabc5d5c7416">RegisterCallback</a> (<a href="BundleStatusCallback.md">BundleStatusCallback</a> *<a href="BundleStatusCallback.md">BundleStatusCallback</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876973435165623"><a name="p1876973435165623"></a><a name="p1876973435165623"></a>int32_t </p>
<p id="p1307769487165623"><a name="p1307769487165623"></a><a name="p1307769487165623"></a>Registers a callback to monitor the installation, update, and uninstallation state changes of an application. </p>
</td>
</tr>
<tr id="row1232708586165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p523832800165623"><a name="p523832800165623"></a><a name="p523832800165623"></a><a href="BundleManager.md#ga095eee592eff6ce71a2a67a1a0e3e344">UnregisterCallback</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p329141530165623"><a name="p329141530165623"></a><a name="p329141530165623"></a>int32_t </p>
<p id="p1100869036165623"><a name="p1100869036165623"></a><a name="p1100869036165623"></a>Unregisters a callback previously registered for monitoring the installation, update, and uninstallation stat changes of an application. </p>
</td>
</tr>
<tr id="row1465103778165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226749022165623"><a name="p1226749022165623"></a><a name="p1226749022165623"></a><a href="BundleManager.md#gaf1f1521a64cc98f076b0082df6c0abdd">Install</a> (const char *hapPath, const <a href="InstallParam.md">InstallParam</a> *installParam, <a href="BundleManager.md#ga00f021e76d728d2d44e1a28887ccc3af">InstallerCallback</a> installerCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p452800374165623"><a name="p452800374165623"></a><a name="p452800374165623"></a>bool </p>
<p id="p1165386559165623"><a name="p1165386559165623"></a><a name="p1165386559165623"></a>Installs or updates an application. </p>
</td>
</tr>
<tr id="row401399002165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1843704189165623"><a name="p1843704189165623"></a><a name="p1843704189165623"></a><a href="BundleManager.md#gaa117e44378315a61b4e71fd252b2e496">Uninstall</a> (const char *bundleName, const <a href="InstallParam.md">InstallParam</a> *installParam, <a href="BundleManager.md#ga00f021e76d728d2d44e1a28887ccc3af">InstallerCallback</a> installerCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p614419383165623"><a name="p614419383165623"></a><a name="p614419383165623"></a>bool </p>
<p id="p1601077778165623"><a name="p1601077778165623"></a><a name="p1601077778165623"></a>Uninstalls an application. </p>
</td>
</tr>
<tr id="row536387986165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p947264261165623"><a name="p947264261165623"></a><a name="p947264261165623"></a><a href="BundleManager.md#ga4360375d15224d89632f59ee110b74c9">QueryAbilityInfo</a> (const <a href="Want.md">Want</a> *want, <a href="AbilityInfo.md">AbilityInfo</a> *abilityInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173525507165623"><a name="p1173525507165623"></a><a name="p1173525507165623"></a>uint8_t </p>
<p id="p309961930165623"><a name="p309961930165623"></a><a name="p309961930165623"></a>Queries the <a href="AbilityInfo.md">AbilityInfo</a> of an ability based on the information carried in the <a href="Want.md">Want</a> structure. </p>
</td>
</tr>
<tr id="row490325890165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p8599976165623"><a name="p8599976165623"></a><a name="p8599976165623"></a><a href="BundleManager.md#ga5e81134e037911654e34cc8a7ba01a2f">GetBundleInfo</a> (const char *bundleName, int32_t flags, <a href="BundleInfo.md">BundleInfo</a> *bundleInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1331071033165623"><a name="p1331071033165623"></a><a name="p1331071033165623"></a>uint8_t </p>
<p id="p55568008165623"><a name="p55568008165623"></a><a name="p55568008165623"></a>Obtains the <a href="BundleInfo.md">BundleInfo</a> of an application based on the specified bundle name. </p>
</td>
</tr>
<tr id="row2022080032165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1705272238165623"><a name="p1705272238165623"></a><a name="p1705272238165623"></a><a href="BundleManager.md#ga2469dafbc61ba8e98b69041c13044cad">GetBundleInfos</a> (const int flags, <a href="BundleInfo.md">BundleInfo</a> **bundleInfos, int32_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2101422044165623"><a name="p2101422044165623"></a><a name="p2101422044165623"></a>uint8_t </p>
<p id="p1756202708165623"><a name="p1756202708165623"></a><a name="p1756202708165623"></a>Obtains the <a href="BundleInfo.md">BundleInfo</a> of all bundles in the system. </p>
</td>
</tr>
<tr id="row349045166165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169506489165623"><a name="p169506489165623"></a><a name="p169506489165623"></a><a href="BundleManager.md#ga0c1cb00194993ecba7337fdf0a203314">QueryKeepAliveBundleInfos</a> (<a href="BundleInfo.md">BundleInfo</a> **bundleInfos, int32_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978322013165623"><a name="p1978322013165623"></a><a name="p1978322013165623"></a>uint8_t </p>
<p id="p332869049165623"><a name="p332869049165623"></a><a name="p332869049165623"></a>Obtains the <a href="BundleInfo.md">BundleInfo</a> of all keep-alive applications in the system. </p>
</td>
</tr>
<tr id="row1202257294165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p902082350165623"><a name="p902082350165623"></a><a name="p902082350165623"></a><a href="BundleManager.md#ga711965038390aef4fa0a6b6a98f6998b">GetBundleInfosByMetaData</a> (const char *metaDataKey, <a href="BundleInfo.md">BundleInfo</a> **bundleInfos, int32_t *len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p896738519165623"><a name="p896738519165623"></a><a name="p896738519165623"></a>uint8_t </p>
<p id="p1720794993165623"><a name="p1720794993165623"></a><a name="p1720794993165623"></a>Obtains the <a href="BundleInfo.md">BundleInfo</a> of application bundles based on the specified <a href="MetaData.md">MetaData</a>. </p>
</td>
</tr>
<tr id="row817022751165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2089759407165623"><a name="p2089759407165623"></a><a name="p2089759407165623"></a><a href="BundleManager.md#ga4afdc08ba78506fce95a066e137ac46d">GetBundleNameForUid</a> (int32_t uid, char **bundleName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1608167682165623"><a name="p1608167682165623"></a><a name="p1608167682165623"></a>uint8_t </p>
<p id="p681796342165623"><a name="p681796342165623"></a><a name="p681796342165623"></a>Obtains the bundle name of an application based on the specified UID. </p>
</td>
</tr>
<tr id="row770624873165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1057693064165623"><a name="p1057693064165623"></a><a name="p1057693064165623"></a><a href="BundleManager.md#gae5e0593438f073199bf6d69e47a84975">ClearBundleStatusCallback</a> (<a href="BundleStatusCallback.md">BundleStatusCallback</a> *bundleStatusCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p862218043165623"><a name="p862218043165623"></a><a name="p862218043165623"></a>void </p>
<p id="p1801139273165623"><a name="p1801139273165623"></a><a name="p1801139273165623"></a>Clears and releases the memory occupied by the <a href="BundleStatusCallback.md">BundleStatusCallback</a> structure. </p>
</td>
</tr>
<tr id="row1304775218165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1176742114165623"><a name="p1176742114165623"></a><a name="p1176742114165623"></a><a href="BundleManager.md#ga3abe15ac14571de84ca72c98f4009724">ClearElement</a> (<a href="ElementName.md">ElementName</a> *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1469206467165623"><a name="p1469206467165623"></a><a name="p1469206467165623"></a>void </p>
<p id="p1689701059165623"><a name="p1689701059165623"></a><a name="p1689701059165623"></a>Clears the internal data of a specified <strong id="b1117130315165623"><a name="b1117130315165623"></a><a name="b1117130315165623"></a><a href="ElementName.md">ElementName</a></strong>. </p>
</td>
</tr>
<tr id="row1592867840165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496239066165623"><a name="p496239066165623"></a><a name="p496239066165623"></a><a href="BundleManager.md#ga90e16f159ee8e7f1a9385feebb3dbc0c">SetElementDeviceID</a> (<a href="ElementName.md">ElementName</a> *element, const char *deviceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36223033165623"><a name="p36223033165623"></a><a name="p36223033165623"></a>bool </p>
<p id="p1913690641165623"><a name="p1913690641165623"></a><a name="p1913690641165623"></a>Sets the device ID used to query <a href="AbilityInfo.md">AbilityInfo</a>. </p>
</td>
</tr>
<tr id="row55393774165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1359901838165623"><a name="p1359901838165623"></a><a name="p1359901838165623"></a><a href="BundleManager.md#ga60692e66a3a204a2f16f70c5cd452c1d">SetElementBundleName</a> (<a href="ElementName.md">ElementName</a> *element, const char *bundleName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307063635165623"><a name="p1307063635165623"></a><a name="p1307063635165623"></a>bool </p>
<p id="p1866271226165623"><a name="p1866271226165623"></a><a name="p1866271226165623"></a>Sets the bundle name used to query <a href="AbilityInfo.md">AbilityInfo</a>. </p>
</td>
</tr>
<tr id="row487608684165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1784259365165623"><a name="p1784259365165623"></a><a name="p1784259365165623"></a><a href="BundleManager.md#ga93a575cc428cb96526ae02b3997f1f3b">SetElementAbilityName</a> (<a href="ElementName.md">ElementName</a> *element, const char *abilityName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1388012638165623"><a name="p1388012638165623"></a><a name="p1388012638165623"></a>bool </p>
<p id="p546786518165623"><a name="p546786518165623"></a><a name="p546786518165623"></a>Sets the class name of the ability used to query <a href="AbilityInfo.md">AbilityInfo</a>. </p>
</td>
</tr>
<tr id="row736504932165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p521822054165623"><a name="p521822054165623"></a><a name="p521822054165623"></a><a href="BundleManager.md#ga6c2242cc10f135d129b95444faacb345">ClearModuleInfo</a> (<a href="ModuleInfo.md">ModuleInfo</a> *moduleInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710323169165623"><a name="p1710323169165623"></a><a name="p1710323169165623"></a>void </p>
<p id="p1733293736165623"><a name="p1733293736165623"></a><a name="p1733293736165623"></a>Clears a <a href="ModuleInfo.md">ModuleInfo</a> object. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section165948216165623"></a>

## **Typedef **<a name="section160203913165623"></a>

## BundleStateCallback<a name="gad7ea6d0bf78db2d59e6d339c31819885"></a>

```
typedef void(* BundleStateCallback) (const uint8_t installType, const uint8_t resultCode, const void *resultMessage, const char *bundleName, void *data)
```

 **Description:**

Called when the installation, update, or uninstallation state of an application changes. 

This callback is used to listen for state change results of applications in the system. 

**Parameters:**

<a name="table717329651165623"></a>
<table><thead align="left"><tr id="row1854718137165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1203157256165623"><a name="p1203157256165623"></a><a name="p1203157256165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1346922407165623"><a name="p1346922407165623"></a><a name="p1346922407165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row651392247165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">installType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the installation, update, or uninstallation state. The value <strong id="b1109887031165623"><a name="b1109887031165623"></a><a name="b1109887031165623"></a>0</strong> indicates that the application is being installed or updated, and <strong id="b878630170165623"><a name="b878630170165623"></a><a name="b878630170165623"></a>1</strong> indicates that the application is being uninstalled. </td>
</tr>
<tr id="row127492507165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resultCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the status code returned for the application installation, update, or uninstallation result. For details, see <a href="BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1">AppexecfwkErrors</a>. </td>
</tr>
<tr id="row1544101142165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resultMessage</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the result message returned with the status code. </td>
</tr>
<tr id="row418416965165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the bundle whose state has changed. </td>
</tr>
<tr id="row240778877165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data that will be used by the callback upon a state change. The data is passed through <a href="BundleStatusCallback.md">BundleStatusCallback</a> during callback registration.</td>
</tr>
</tbody>
</table>

## InstallerCallback<a name="ga00f021e76d728d2d44e1a28887ccc3af"></a>

```
typedef void(* InstallerCallback) (const uint8_t resultCode, const void *resultMessage)
```

 **Description:**

Called when an application is installed, updated, or uninstalled. 

This function can be registered through  [Install](BundleManager.md#gaf1f1521a64cc98f076b0082df6c0abdd)  and  [Uninstall](BundleManager.md#gaa117e44378315a61b4e71fd252b2e496)  to receive the installation, update, and uninstallation result.

**Parameters:**

<a name="table637128333165623"></a>
<table><thead align="left"><tr id="row1977441393165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1714061461165623"><a name="p1714061461165623"></a><a name="p1714061461165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1708038165623"><a name="p1708038165623"></a><a name="p1708038165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row571786041165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resultCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the status code returned for the application installation, update, or uninstallation result. For details, see <a href="BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1">AppexecfwkErrors</a>. </td>
</tr>
<tr id="row1417212895165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">resultMessage</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the result message returned with the status code.</td>
</tr>
</tbody>
</table>

## **Enumeration Type **<a name="section76133345165623"></a>

## AbilityType<a name="ga44b675d687acff3d739404c1227b4259"></a>

```
enum [AbilityType](BundleManager.md#ga44b675d687acff3d739404c1227b4259)
```

 **Description:**

Enumerates types of templates used by an ability. 

<a name="table2105517405165623"></a>
<table><thead align="left"><tr id="row1285998863165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p140919868165623"><a name="p140919868165623"></a><a name="p140919868165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p194876006165623"><a name="p194876006165623"></a><a name="p194876006165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1772687243165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga44b675d687acff3d739404c1227b4259a6ce26a62afab55d7606ad4e92428b30c"><a name="gga44b675d687acff3d739404c1227b4259a6ce26a62afab55d7606ad4e92428b30c"></a><a name="gga44b675d687acff3d739404c1227b4259a6ce26a62afab55d7606ad4e92428b30c"></a></strong>UNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1811623499165623"><a name="p1811623499165623"></a><a name="p1811623499165623"></a>Unknown </p>
 </td>
</tr>
<tr id="row1691889940165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga44b675d687acff3d739404c1227b4259ab788d9e2cde88d51a5cda409f75db490"><a name="gga44b675d687acff3d739404c1227b4259ab788d9e2cde88d51a5cda409f75db490"></a><a name="gga44b675d687acff3d739404c1227b4259ab788d9e2cde88d51a5cda409f75db490"></a></strong>PAGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1106144879165623"><a name="p1106144879165623"></a><a name="p1106144879165623"></a>Page </p>
 </td>
</tr>
<tr id="row664288275165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga44b675d687acff3d739404c1227b4259a5f6d448017ecd0a56245e38b76596e07"><a name="gga44b675d687acff3d739404c1227b4259a5f6d448017ecd0a56245e38b76596e07"></a><a name="gga44b675d687acff3d739404c1227b4259a5f6d448017ecd0a56245e38b76596e07"></a></strong>SERVICE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413209288165623"><a name="p413209288165623"></a><a name="p413209288165623"></a><a href="Service.md">Service</a> </p>
 </td>
</tr>
</tbody>
</table>

## AppexecfwkErrors<a name="gac318d4f4dc0125e2367ea8c539770ed1"></a>

```
enum [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)
```

 **Description:**

Enumerates error codes provided by the Bundle Manager  [Service](Service.md). 

<a name="table665422972165623"></a>
<table><thead align="left"><tr id="row293114316165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p827159835165623"><a name="p827159835165623"></a><a name="p827159835165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2056355452165623"><a name="p2056355452165623"></a><a name="p2056355452165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1829670780165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb"></a></strong>ERR_OK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342845368165623"><a name="p342845368165623"></a><a name="p342845368165623"></a>The function is successfully called. </p>
 </td>
</tr>
<tr id="row1475487715165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ac56903bcb53061d4ccd81f356e2e6dff"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac56903bcb53061d4ccd81f356e2e6dff"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac56903bcb53061d4ccd81f356e2e6dff"></a></strong>ERR_APPEXECFWK_QUERY_PARAMETER_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p414117613165623"><a name="p414117613165623"></a><a name="p414117613165623"></a>Incorrect parameter for querying <a href="AbilityInfo.md">AbilityInfo</a> or <a href="BundleInfo.md">BundleInfo</a>. </p>
 </td>
</tr>
<tr id="row1572517798165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a6609bd5ca64e005d23794eb0a9e65058"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6609bd5ca64e005d23794eb0a9e65058"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6609bd5ca64e005d23794eb0a9e65058"></a></strong>ERR_APPEXECFWK_QUERY_NO_INFOS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770604054165623"><a name="p770604054165623"></a><a name="p770604054165623"></a>No <a href="AbilityInfo.md">AbilityInfo</a> or <a href="BundleInfo.md">BundleInfo</a> is found. </p>
 </td>
</tr>
<tr id="row2000332726165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a862f4edaae059afe7505f3a2355ace7a"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a862f4edaae059afe7505f3a2355ace7a"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a862f4edaae059afe7505f3a2355ace7a"></a></strong>ERR_APPEXECFWK_QUERY_INFOS_INIT_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1248893987165623"><a name="p1248893987165623"></a><a name="p1248893987165623"></a>An error occurred when initializing <a href="BundleInfo.md">BundleInfo</a> or <a href="AbilityInfo.md">AbilityInfo</a> during information query. </p>
 </td>
</tr>
<tr id="row636438807165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a5d6b76480d9c381a4ea582e42ae13723"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a5d6b76480d9c381a4ea582e42ae13723"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a5d6b76480d9c381a4ea582e42ae13723"></a></strong>ERR_APPEXECFWK_OBJECT_NULL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432312161165623"><a name="p1432312161165623"></a><a name="p1432312161165623"></a>The object or pointer is null. </p>
 </td>
</tr>
<tr id="row1953909008165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ab6bf660df1f71efbbc1dc171026e8b19"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab6bf660df1f71efbbc1dc171026e8b19"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab6bf660df1f71efbbc1dc171026e8b19"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_INTERNAL_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1935921264165623"><a name="p1935921264165623"></a><a name="p1935921264165623"></a>Failed to install the application due to an internal logic error. </p>
 </td>
</tr>
<tr id="row701173812165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a0d0ff29443bea7409cb49aa65276a734"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0d0ff29443bea7409cb49aa65276a734"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0d0ff29443bea7409cb49aa65276a734"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARAM_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438931816165623"><a name="p438931816165623"></a><a name="p438931816165623"></a>Failed to install the application due to incorrect parameters. </p>
 </td>
</tr>
<tr id="row1117904224165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ab5e45300939da4427f50b6a765701e34"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab5e45300939da4427f50b6a765701e34"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab5e45300939da4427f50b6a765701e34"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_FILE_PATH_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1422823385165623"><a name="p1422823385165623"></a><a name="p1422823385165623"></a>Failed to install the application because the installation file path is invalid. </p>
 </td>
</tr>
<tr id="row1015058315165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a6242775e55f8eb650cc92fd8a3388e32"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6242775e55f8eb650cc92fd8a3388e32"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6242775e55f8eb650cc92fd8a3388e32"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_FILE_NOT_EXISTS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884272465165623"><a name="p884272465165623"></a><a name="p884272465165623"></a>Failed to install the application because the installation file does not exist. </p>
 </td>
</tr>
<tr id="row1995455108165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a3f98ba8a2755dbb204d87abc64744d62"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3f98ba8a2755dbb204d87abc64744d62"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3f98ba8a2755dbb204d87abc64744d62"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_INVALID_FILE_NAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2068828986165623"><a name="p2068828986165623"></a><a name="p2068828986165623"></a>Failed to install the application because the installation file name is invalid. </p>
 </td>
</tr>
<tr id="row1839818321165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a74a6ca143ea4633376530ee2e9ce6eb1"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a74a6ca143ea4633376530ee2e9ce6eb1"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a74a6ca143ea4633376530ee2e9ce6eb1"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_BAD_FILE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966433200165623"><a name="p966433200165623"></a><a name="p966433200165623"></a>Failed to install the application due to incorrect file content. </p>
 </td>
</tr>
<tr id="row1636883677165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a02521dcb943509971fe14bfb8468a98d"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a02521dcb943509971fe14bfb8468a98d"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a02521dcb943509971fe14bfb8468a98d"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_CREATE_FILE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039756072165623"><a name="p1039756072165623"></a><a name="p1039756072165623"></a>Failed to install the application due to a file creation error. </p>
 </td>
</tr>
<tr id="row1745479849165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a72f16cafaafe6ff6e7069a2ef28507a7"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a72f16cafaafe6ff6e7069a2ef28507a7"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a72f16cafaafe6ff6e7069a2ef28507a7"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_CREATE_PERMISSIONS_DIR_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p802246169165623"><a name="p802246169165623"></a><a name="p802246169165623"></a>Failed to install the application because an error occurred when creating the permission file directory. </p>
 </td>
</tr>
<tr id="row129272714165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ab0d26918c1d8d1481601567cf87f2621"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab0d26918c1d8d1481601567cf87f2621"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab0d26918c1d8d1481601567cf87f2621"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_RENAME_DIR_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1375791380165623"><a name="p1375791380165623"></a><a name="p1375791380165623"></a>Failed to install the application due to a path renaming error. </p>
 </td>
</tr>
<tr id="row486004612165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aaafdb262ffe01eed1722350d270cf09d"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aaafdb262ffe01eed1722350d270cf09d"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aaafdb262ffe01eed1722350d270cf09d"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_RENAME_FILE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639308370165623"><a name="p639308370165623"></a><a name="p639308370165623"></a>Failed to install the application due to a file renaming error. </p>
 </td>
</tr>
<tr id="row184255215165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a9e457f181dce9e221dfa01c257d7fe12"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9e457f181dce9e221dfa01c257d7fe12"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9e457f181dce9e221dfa01c257d7fe12"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_CREATE_DATA_DIR_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687768064165623"><a name="p1687768064165623"></a><a name="p1687768064165623"></a>Failed to install the application due to an error occurred when creating the data path. </p>
 </td>
</tr>
<tr id="row1509246575165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ac62be957615c89ae23b780d8d288419e"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac62be957615c89ae23b780d8d288419e"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac62be957615c89ae23b780d8d288419e"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_RECORD_INFO_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973380295165623"><a name="p973380295165623"></a><a name="p973380295165623"></a>Failed to install the application due to an error occurred when recording installation information. </p>
 </td>
</tr>
<tr id="row1199556809165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a438581dc1abee81ed846d9dafee34e83"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a438581dc1abee81ed846d9dafee34e83"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a438581dc1abee81ed846d9dafee34e83"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_UID_AND_GID_BACKUP_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1017177616165623"><a name="p1017177616165623"></a><a name="p1017177616165623"></a>Failed to install the application due to an error occurred when backing up the UID and GID. </p>
 </td>
</tr>
<tr id="row547891356165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a0d874b79e811844325c76f65630db989"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0d874b79e811844325c76f65630db989"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0d874b79e811844325c76f65630db989"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_VERSION_DOWNGRADE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p619477908165623"><a name="p619477908165623"></a><a name="p619477908165623"></a>Failed to install the application because an application of a later version has been installed. </p>
 </td>
</tr>
<tr id="row1559956684165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a6ef4ca2fed2c05c5ec553f4e12844bac"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6ef4ca2fed2c05c5ec553f4e12844bac"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6ef4ca2fed2c05c5ec553f4e12844bac"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_BUNDLE_NUMBER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1617531537165623"><a name="p1617531537165623"></a><a name="p1617531537165623"></a>Failed to install the application because the number of installed applications exceeds the maximum (30). This error code is available only to basic watches. </p>
 </td>
</tr>
<tr id="row1892464217165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a8599367df053820365395e64ae536e81"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8599367df053820365395e64ae536e81"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8599367df053820365395e64ae536e81"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_STORE_PERMISSIONS_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287350130165623"><a name="p1287350130165623"></a><a name="p1287350130165623"></a>Failed to install the application due to an error occurred when storing permission information. </p>
 </td>
</tr>
<tr id="row1612940365165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1adb1e3b901e0a5b88460f661a533b08f8"><a name="ggac318d4f4dc0125e2367ea8c539770ed1adb1e3b901e0a5b88460f661a533b08f8"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1adb1e3b901e0a5b88460f661a533b08f8"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_FILE_DATA_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709651198165623"><a name="p1709651198165623"></a><a name="p1709651198165623"></a>Failed to install the application due to invalid file data. This error code is available only to basic watches. </p>
 </td>
</tr>
<tr id="row982490641165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a2b9a032c6b9c843e1101cf753b2fa6fa"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2b9a032c6b9c843e1101cf753b2fa6fa"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2b9a032c6b9c843e1101cf753b2fa6fa"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_INCOMPATIBLE_SIGNATURE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455707573165623"><a name="p455707573165623"></a><a name="p455707573165623"></a>Failed to install the application due to unmatched signature used for version update. </p>
 </td>
</tr>
<tr id="row1920290311165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ab1dc9dd09156cc2b06643624d8465ea9"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab1dc9dd09156cc2b06643624d8465ea9"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab1dc9dd09156cc2b06643624d8465ea9"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_INVALID_PROVISIONINFO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806629166165623"><a name="p806629166165623"></a><a name="p806629166165623"></a>Failed to install the application due to unmatched provisioning information during signature verification. </p>
 </td>
</tr>
<tr id="row1151465962165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a06b51bb80923d2d9271f902f75842063"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a06b51bb80923d2d9271f902f75842063"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a06b51bb80923d2d9271f902f75842063"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_OPERATE_SIGNED_FILE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404260547165623"><a name="p404260547165623"></a><a name="p404260547165623"></a>Failed to install the application due to an error occurred when processing the signature file. </p>
 </td>
</tr>
<tr id="row251051257165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a34439d18e6612f31ba634766c3da6457"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a34439d18e6612f31ba634766c3da6457"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a34439d18e6612f31ba634766c3da6457"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_APP_SIGNATURE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211402759165623"><a name="p1211402759165623"></a><a name="p1211402759165623"></a>Failed to install the application due to an error occurred when parsing the application signature. </p>
 </td>
</tr>
<tr id="row857619525165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a553374f3e17c7a39f6fbf9ecd932b618"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a553374f3e17c7a39f6fbf9ecd932b618"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a553374f3e17c7a39f6fbf9ecd932b618"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_PROFILE_SIGNATURE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403734319165623"><a name="p403734319165623"></a><a name="p403734319165623"></a>Failed to install the application due to an error occurred when parsing the file signature. </p>
 </td>
</tr>
<tr id="row1330485682165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a2c992cbdee385fbc00fecd0e313b33fc"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2c992cbdee385fbc00fecd0e313b33fc"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2c992cbdee385fbc00fecd0e313b33fc"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_INTERNAL_SIGNATURE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p170286848165623"><a name="p170286848165623"></a><a name="p170286848165623"></a>Failed to install the application due to an internal error during signature verification. </p>
 </td>
</tr>
<tr id="row2116419305165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a17e1305d5eeee7867a98c295c488e236"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a17e1305d5eeee7867a98c295c488e236"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a17e1305d5eeee7867a98c295c488e236"></a></strong>ERR_APPEXECFWK_SET_DEBUG_MODE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408497570165623"><a name="p1408497570165623"></a><a name="p1408497570165623"></a>Failed to install the application due to an error occurred when setting the signature verification mode. </p>
 </td>
</tr>
<tr id="row1168765830165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aef3bf9de62376b9d91070956c1a0b6a0"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aef3bf9de62376b9d91070956c1a0b6a0"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aef3bf9de62376b9d91070956c1a0b6a0"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_PROFILE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305003545165623"><a name="p1305003545165623"></a><a name="p1305003545165623"></a>Failed to parse the file. </p>
 </td>
</tr>
<tr id="row1193164628165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a014b98d9df51b98ff37f95aaba97c63f"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a014b98d9df51b98ff37f95aaba97c63f"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a014b98d9df51b98ff37f95aaba97c63f"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_BUNDLENAME_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p831374833165623"><a name="p831374833165623"></a><a name="p831374833165623"></a>Failed to parse the bundle name. </p>
 </td>
</tr>
<tr id="row620082158165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a1ab7654bdb5ca8fcba99e6acb9ad4163"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1ab7654bdb5ca8fcba99e6acb9ad4163"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1ab7654bdb5ca8fcba99e6acb9ad4163"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_INVALID_BUNDLENAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1613380148165623"><a name="p1613380148165623"></a><a name="p1613380148165623"></a>Invalid bundle name. </p>
 </td>
</tr>
<tr id="row175476414165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a7f159724dde9d3ec69a22fd97c7c4275"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a7f159724dde9d3ec69a22fd97c7c4275"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a7f159724dde9d3ec69a22fd97c7c4275"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_VENDOR_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560749755165623"><a name="p560749755165623"></a><a name="p560749755165623"></a>Failed to parse the vendor information. </p>
 </td>
</tr>
<tr id="row987200669165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ad569e1e0e50704d8d94394b39df13599"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ad569e1e0e50704d8d94394b39df13599"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ad569e1e0e50704d8d94394b39df13599"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_VERSIONCODE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368867721165623"><a name="p368867721165623"></a><a name="p368867721165623"></a>Failed to parse the version code. </p>
 </td>
</tr>
<tr id="row933119014165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a26e4922b83c0a42f8576cb81cd0760e2"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a26e4922b83c0a42f8576cb81cd0760e2"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a26e4922b83c0a42f8576cb81cd0760e2"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_VERSIONNAME_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p471081048165623"><a name="p471081048165623"></a><a name="p471081048165623"></a>Failed to parse the version name. </p>
 </td>
</tr>
<tr id="row1591140626165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a022e0b7e7b978eda5e43db46efe9c916"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a022e0b7e7b978eda5e43db46efe9c916"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a022e0b7e7b978eda5e43db46efe9c916"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_PERMISSIONS_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343223818165623"><a name="p1343223818165623"></a><a name="p1343223818165623"></a>Failed to parse the installation permission information. </p>
 </td>
</tr>
<tr id="row1610131709165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ac449d6df4540c1794f1b76599435c4df"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac449d6df4540c1794f1b76599435c4df"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac449d6df4540c1794f1b76599435c4df"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_API_VERSION_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26726376165623"><a name="p26726376165623"></a><a name="p26726376165623"></a>Failed to parse the API version. </p>
 </td>
</tr>
<tr id="row1469180874165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a05262a83fbc2d5817772db9a20d6c503"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a05262a83fbc2d5817772db9a20d6c503"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a05262a83fbc2d5817772db9a20d6c503"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DEVICE_CONFIG_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1675442499165623"><a name="p1675442499165623"></a><a name="p1675442499165623"></a>Failed to parse the device configuration. </p>
 </td>
</tr>
<tr id="row1692437437165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1abcb1a3e0509445e2bff7dad43c379971"><a name="ggac318d4f4dc0125e2367ea8c539770ed1abcb1a3e0509445e2bff7dad43c379971"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1abcb1a3e0509445e2bff7dad43c379971"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_KEEPALIVE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660802513165623"><a name="p1660802513165623"></a><a name="p1660802513165623"></a>Failed to parse the <strong id="b1294226928165623"><a name="b1294226928165623"></a><a name="b1294226928165623"></a>isKeepAlive</strong> field of the application. </p>
 </td>
</tr>
<tr id="row239198881165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a27d9af1e04f75bc389f35b3318ad1590"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a27d9af1e04f75bc389f35b3318ad1590"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a27d9af1e04f75bc389f35b3318ad1590"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_MODULENAME_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1540086664165623"><a name="p1540086664165623"></a><a name="p1540086664165623"></a>Failed to parse the <strong id="b1937091465165623"><a name="b1937091465165623"></a><a name="b1937091465165623"></a>name</strong> field of the application's HAP package. The HAP information is encapsulated in a <a href="ModuleInfo.md">ModuleInfo</a> object. </p>
 </td>
</tr>
<tr id="row1336478686165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a38afd7346c84b9d618aa1a477316c3ca"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a38afd7346c84b9d618aa1a477316c3ca"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a38afd7346c84b9d618aa1a477316c3ca"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_INVALID_MODULENAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568897846165623"><a name="p568897846165623"></a><a name="p568897846165623"></a>Invalid HAP name. </p>
 </td>
</tr>
<tr id="row352156319165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1af244274d1cf39090d9818aac15882e4c"><a name="ggac318d4f4dc0125e2367ea8c539770ed1af244274d1cf39090d9818aac15882e4c"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1af244274d1cf39090d9818aac15882e4c"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_MODULE_DESCRIPTION_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671141447165623"><a name="p1671141447165623"></a><a name="p1671141447165623"></a>Failed to parse the HAP description information. </p>
 </td>
</tr>
<tr id="row1513251552165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ac36ac4af8d61e10431c39fe545f8f623"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac36ac4af8d61e10431c39fe545f8f623"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac36ac4af8d61e10431c39fe545f8f623"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DEVICETYPE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1674872744165623"><a name="p1674872744165623"></a><a name="p1674872744165623"></a>Failed to parse the <strong id="b1695102654165623"><a name="b1695102654165623"></a><a name="b1695102654165623"></a>deviceType</strong> field of the application's HAP package. </p>
 </td>
</tr>
<tr id="row978373809165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a04f7cee0fe708631364d56e53fc7a2d8"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a04f7cee0fe708631364d56e53fc7a2d8"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a04f7cee0fe708631364d56e53fc7a2d8"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p670637014165623"><a name="p670637014165623"></a><a name="p670637014165623"></a>Failed to parse the HAP information. </p>
 </td>
</tr>
<tr id="row1277246739165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aba3187880d4a57348ac2cd3943546dd1"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aba3187880d4a57348ac2cd3943546dd1"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aba3187880d4a57348ac2cd3943546dd1"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_MODULENAME_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p348567159165623"><a name="p348567159165623"></a><a name="p348567159165623"></a>Failed to parse the <strong id="b353194293165623"><a name="b353194293165623"></a><a name="b353194293165623"></a>moduleName</strong> field of the application's HAP package. </p>
 </td>
</tr>
<tr id="row130192983165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a1c88e191b397644827022b0a238007da"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1c88e191b397644827022b0a238007da"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1c88e191b397644827022b0a238007da"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_MODULETYPE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p681504981165623"><a name="p681504981165623"></a><a name="p681504981165623"></a>Invalid HAP type. </p>
 </td>
</tr>
<tr id="row506663132165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a9ec099feb69dc64a4f3bd48475723bba"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9ec099feb69dc64a4f3bd48475723bba"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9ec099feb69dc64a4f3bd48475723bba"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DISTRO_DELIVERY_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1315202509165623"><a name="p1315202509165623"></a><a name="p1315202509165623"></a>Failed to parse the <strong id="b1040615310165623"><a name="b1040615310165623"></a><a name="b1040615310165623"></a>isDeliveryInstall</strong> field of the application's HAP package. </p>
 </td>
</tr>
<tr id="row775849006165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a98508d3e35c99d09320ffd498469b984"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a98508d3e35c99d09320ffd498469b984"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a98508d3e35c99d09320ffd498469b984"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_METADATA_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870377336165623"><a name="p1870377336165623"></a><a name="p1870377336165623"></a>Failed to parse the <a href="MetaData.md">MetaData</a> information. </p>
 </td>
</tr>
<tr id="row980551415165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a1649053e390e2b20ac96674aa7d7ca88"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1649053e390e2b20ac96674aa7d7ca88"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1649053e390e2b20ac96674aa7d7ca88"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITIES_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2136193153165623"><a name="p2136193153165623"></a><a name="p2136193153165623"></a>Failed to parse the <a href="AbilityInfo.md">AbilityInfo</a>. </p>
 </td>
</tr>
<tr id="row673238617165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1adbf64bab15b50b69286efa90f7f1dec1"><a name="ggac318d4f4dc0125e2367ea8c539770ed1adbf64bab15b50b69286efa90f7f1dec1"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1adbf64bab15b50b69286efa90f7f1dec1"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_NAME_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391119288165623"><a name="p391119288165623"></a><a name="p391119288165623"></a>Failed to parse the class name of the ability. </p>
 </td>
</tr>
<tr id="row1414292429165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aeefcd3f1a247768fc5fb2f59c0f1b966"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aeefcd3f1a247768fc5fb2f59c0f1b966"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aeefcd3f1a247768fc5fb2f59c0f1b966"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_TYPE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p981476278165623"><a name="p981476278165623"></a><a name="p981476278165623"></a>Failed to parse the template used by the ability. </p>
 </td>
</tr>
<tr id="row372329542165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a8a282ca74395e3007dd75c90d671fe23"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8a282ca74395e3007dd75c90d671fe23"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8a282ca74395e3007dd75c90d671fe23"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_ICONPATH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775317019165623"><a name="p775317019165623"></a><a name="p775317019165623"></a>Failed to parse the icon path of the ability. </p>
 </td>
</tr>
<tr id="row2092774145165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a3c6dcb2ca14788595975cea51bf1cfed"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3c6dcb2ca14788595975cea51bf1cfed"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3c6dcb2ca14788595975cea51bf1cfed"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_LABEL_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977420810165623"><a name="p977420810165623"></a><a name="p977420810165623"></a>Failed to parse the label of the ability. </p>
 </td>
</tr>
<tr id="row590647483165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a164231485c5ea694f9a0b4d8307d5901"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a164231485c5ea694f9a0b4d8307d5901"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a164231485c5ea694f9a0b4d8307d5901"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_DESCRIPTION_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22760874165623"><a name="p22760874165623"></a><a name="p22760874165623"></a>Failed to parse the description of the ability. </p>
 </td>
</tr>
<tr id="row357315627165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a6a592b570f8c29dc1c4161faedcf2acd"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6a592b570f8c29dc1c4161faedcf2acd"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6a592b570f8c29dc1c4161faedcf2acd"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_LAUNCHTYPE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1908200186165623"><a name="p1908200186165623"></a><a name="p1908200186165623"></a>Failed to parse the startup mode of the ability. </p>
 </td>
</tr>
<tr id="row1921573829165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a7d51c40e62b04e8bc2991db294fd10f3"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a7d51c40e62b04e8bc2991db294fd10f3"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a7d51c40e62b04e8bc2991db294fd10f3"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ABILITY_VISIBLE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181623719165623"><a name="p181623719165623"></a><a name="p181623719165623"></a>Failed to parse the <strong id="b1840779111165623"><a name="b1840779111165623"></a><a name="b1840779111165623"></a>isVisible</strong> field of the ability. </p>
 </td>
</tr>
<tr id="row1868866506165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aa83132144c11442291f4a971e51dcbb1"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aa83132144c11442291f4a971e51dcbb1"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aa83132144c11442291f4a971e51dcbb1"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_INVALID_BUNDLENAME_LENGTH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429590497165623"><a name="p429590497165623"></a><a name="p429590497165623"></a>Invalid length of the bundle name. </p>
 </td>
</tr>
<tr id="row430063182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a1e7f0159d459e0f416c05bcd106d8782"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1e7f0159d459e0f416c05bcd106d8782"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1e7f0159d459e0f416c05bcd106d8782"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_LABEL_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1442721847165623"><a name="p1442721847165623"></a><a name="p1442721847165623"></a>The parsed application label exceeds the maximum length (255 bytes). </p>
 </td>
</tr>
<tr id="row1891535363165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1af6fb04f5b2b34761822d84670f19e7ce"><a name="ggac318d4f4dc0125e2367ea8c539770ed1af6fb04f5b2b34761822d84670f19e7ce"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1af6fb04f5b2b34761822d84670f19e7ce"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_VERSIONNAME_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647422895165623"><a name="p647422895165623"></a><a name="p647422895165623"></a>The parsed application version name exceeds the maximum length (127 bytes). </p>
 </td>
</tr>
<tr id="row229171670165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a4d20732be30f3bc677ed0fff3b79aa93"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4d20732be30f3bc677ed0fff3b79aa93"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4d20732be30f3bc677ed0fff3b79aa93"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_METADATA_NAME_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p876385410165623"><a name="p876385410165623"></a><a name="p876385410165623"></a>The parsed application metadata name exceeds the maximum length (255 bytes). </p>
 </td>
</tr>
<tr id="row1934090454165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a4ddea99589bb62ae0297742763a12c1a"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4ddea99589bb62ae0297742763a12c1a"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4ddea99589bb62ae0297742763a12c1a"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_METADATA_VALUE_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954122061165623"><a name="p954122061165623"></a><a name="p954122061165623"></a>The parsed application metadata value exceeds the maximum length (255 bytes). </p>
 </td>
</tr>
<tr id="row1831991699165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aabd55ad27e4671083b36aa1a9bce53b2"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aabd55ad27e4671083b36aa1a9bce53b2"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aabd55ad27e4671083b36aa1a9bce53b2"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_VENDOR_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040373581165623"><a name="p2040373581165623"></a><a name="p2040373581165623"></a>The parsed application vendor name exceeds the maximum length (255 bytes). </p>
 </td>
</tr>
<tr id="row829027272165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a85ed32b668e813a868dff8f11d1a0259"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a85ed32b668e813a868dff8f11d1a0259"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a85ed32b668e813a868dff8f11d1a0259"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_MODULENAME_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p767308764165623"><a name="p767308764165623"></a><a name="p767308764165623"></a>The parsed HAP name exceeds the maximum length (31 bytes). </p>
 </td>
</tr>
<tr id="row1164983867165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a2fd9e57b401b4c4ecb7f737d9cfb7f1a"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2fd9e57b401b4c4ecb7f737d9cfb7f1a"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2fd9e57b401b4c4ecb7f737d9cfb7f1a"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_ABILITYNAME_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p956749997165623"><a name="p956749997165623"></a><a name="p956749997165623"></a>The parsed ability class name exceeds the maximum length (127 bytes). </p>
 </td>
</tr>
<tr id="row1431331441165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1acb65a2d440e7aee4541ea265317582e0"><a name="ggac318d4f4dc0125e2367ea8c539770ed1acb65a2d440e7aee4541ea265317582e0"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1acb65a2d440e7aee4541ea265317582e0"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_ABILITY_DESCRIPTION_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p421901238165623"><a name="p421901238165623"></a><a name="p421901238165623"></a>The parsed ability description exceeds the maximum length (255 bytes). </p>
 </td>
</tr>
<tr id="row1023715828165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a7d764e29e35ead6dbbca9302c284ee00"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a7d764e29e35ead6dbbca9302c284ee00"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a7d764e29e35ead6dbbca9302c284ee00"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXCEED_MAX_ABILITY_LABEL_LENGTH_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502323543165623"><a name="p1502323543165623"></a><a name="p1502323543165623"></a>The parsed ability label exceeds the maximum length (255 bytes). </p>
 </td>
</tr>
<tr id="row575319190165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aebc061682db1151f24248f0ca34eca98"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aebc061682db1151f24248f0ca34eca98"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aebc061682db1151f24248f0ca34eca98"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXTRACTOR_NOT_INIT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1179885115165623"><a name="p1179885115165623"></a><a name="p1179885115165623"></a>Failed to initialize the extractor. </p>
 </td>
</tr>
<tr id="row394767588165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a797b7558d35fdb43a923aaac8c464187"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a797b7558d35fdb43a923aaac8c464187"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a797b7558d35fdb43a923aaac8c464187"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_EXTRACT_HAP_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45696108165623"><a name="p45696108165623"></a><a name="p45696108165623"></a>Failed to extract information from the HAP package. </p>
 </td>
</tr>
<tr id="row1168936676165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aeacdda0db2432c52b0795208bf69408e"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aeacdda0db2432c52b0795208bf69408e"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aeacdda0db2432c52b0795208bf69408e"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_JS_DIR_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104330493165623"><a name="p2104330493165623"></a><a name="p2104330493165623"></a>Failed to parse the JavaScript path. This error code is available only to basic watches. </p>
 </td>
</tr>
<tr id="row1092478856165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a3a521918e6b836de9b70325a0a643362"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3a521918e6b836de9b70325a0a643362"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3a521918e6b836de9b70325a0a643362"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_RESOURCE_INDEX_NOT_EXISTS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135185636165623"><a name="p135185636165623"></a><a name="p135185636165623"></a>The resource index does not exist. </p>
 </td>
</tr>
<tr id="row671473777165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1acc1f483da695764aa8f3f22d697c8969"><a name="ggac318d4f4dc0125e2367ea8c539770ed1acc1f483da695764aa8f3f22d697c8969"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1acc1f483da695764aa8f3f22d697c8969"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_LABEL_RES_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1402760864165623"><a name="p1402760864165623"></a><a name="p1402760864165623"></a>Failed to parse the label resource. </p>
 </td>
</tr>
<tr id="row875397903165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a572a4b52c204c83b1742eb1fc8364a1a"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a572a4b52c204c83b1742eb1fc8364a1a"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a572a4b52c204c83b1742eb1fc8364a1a"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_ICON_RES_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610492955165623"><a name="p1610492955165623"></a><a name="p1610492955165623"></a>Failed to parse the icon resource. </p>
 </td>
</tr>
<tr id="row1649646349165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a128bf2cca7073ed0a6299c7d8529e33d"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a128bf2cca7073ed0a6299c7d8529e33d"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a128bf2cca7073ed0a6299c7d8529e33d"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_PARSE_DESCRIPTION_RES_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1379877429165623"><a name="p1379877429165623"></a><a name="p1379877429165623"></a>Failed to parse the description resource. </p>
 </td>
</tr>
<tr id="row2139855049165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ac31bcc78028487c5be87399325332380"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac31bcc78028487c5be87399325332380"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ac31bcc78028487c5be87399325332380"></a></strong>ERR_APPEXECFWK_INSTALL_FAILED_SEND_REQUEST_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189294529165623"><a name="p189294529165623"></a><a name="p189294529165623"></a>Failed to install the application due to a request sending error. </p>
 </td>
</tr>
<tr id="row1113946065165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a26ff3a2760ff20c60aba2ab125ecdd17"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a26ff3a2760ff20c60aba2ab125ecdd17"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a26ff3a2760ff20c60aba2ab125ecdd17"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_INTERNAL_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608383694165623"><a name="p608383694165623"></a><a name="p608383694165623"></a>Failed to uninstall the application due to an internal error. </p>
 </td>
</tr>
<tr id="row2133159688165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ae0670ff00ddfc9f4642815d13e50e732"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ae0670ff00ddfc9f4642815d13e50e732"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ae0670ff00ddfc9f4642815d13e50e732"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_PARAM_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7577260165623"><a name="p7577260165623"></a><a name="p7577260165623"></a>Failed to uninstall the application due to incorrect input parameters. </p>
 </td>
</tr>
<tr id="row421886035165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a8d6b6bf5861d928ca86ddaeeb15c062a"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8d6b6bf5861d928ca86ddaeeb15c062a"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8d6b6bf5861d928ca86ddaeeb15c062a"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_BUNDLE_NOT_EXISTS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684453347165623"><a name="p1684453347165623"></a><a name="p1684453347165623"></a>Failed to uninstall the application because it does not exist. </p>
 </td>
</tr>
<tr id="row1431595773165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a4949cab6b3e4f97fd44151eba0d488bb"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4949cab6b3e4f97fd44151eba0d488bb"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4949cab6b3e4f97fd44151eba0d488bb"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_DIRS_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234332272165623"><a name="p234332272165623"></a><a name="p234332272165623"></a>Failed to uninstall the application due to an error occurred when deleting the path. </p>
 </td>
</tr>
<tr id="row1405155858165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a9e5f0727ceed161044cf4bfdacec12e2"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9e5f0727ceed161044cf4bfdacec12e2"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9e5f0727ceed161044cf4bfdacec12e2"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_RECORD_INFO_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415294121165623"><a name="p1415294121165623"></a><a name="p1415294121165623"></a>Failed to uninstall the application due to an error occurred when deleting the installation record. </p>
 </td>
</tr>
<tr id="row1509256391165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a0050a0cd61152432d89221b3ed178724"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0050a0cd61152432d89221b3ed178724"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0050a0cd61152432d89221b3ed178724"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_PERMISSIONS_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894711669165623"><a name="p1894711669165623"></a><a name="p1894711669165623"></a>Failed to uninstall the application due to an error occurred when deleting the permission information. </p>
 </td>
</tr>
<tr id="row334149289165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a58c70df1bf55bc3c2b61e2c0f0571a2f"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a58c70df1bf55bc3c2b61e2c0f0571a2f"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a58c70df1bf55bc3c2b61e2c0f0571a2f"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_BUNDLE_NOT_UNINSTALLABLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p934797697165623"><a name="p934797697165623"></a><a name="p934797697165623"></a>Failed to uninstall the application because the application cannot be uninstalled. </p>
 </td>
</tr>
<tr id="row1553895016165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a11b7780ad61c6085f475c5415de34191"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a11b7780ad61c6085f475c5415de34191"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a11b7780ad61c6085f475c5415de34191"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_DELETE_UID_INFO_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924661234165623"><a name="p924661234165623"></a><a name="p924661234165623"></a>Failed to uninstall the application due to an error occurred when deleting the UID information. </p>
 </td>
</tr>
<tr id="row1434201417165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a1e2b896e9cc48287bed17cd2835f44cb"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1e2b896e9cc48287bed17cd2835f44cb"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a1e2b896e9cc48287bed17cd2835f44cb"></a></strong>ERR_APPEXECFWK_UNINSTALL_FAILED_SEND_REQUEST_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743874775165623"><a name="p743874775165623"></a><a name="p743874775165623"></a>Failed to uninstall the application due to a request sending error. </p>
 </td>
</tr>
<tr id="row1835318611165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a3fbc51865d3bf19ead1c7e42c6058a42"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3fbc51865d3bf19ead1c7e42c6058a42"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3fbc51865d3bf19ead1c7e42c6058a42"></a></strong>ERR_APPEXECFWK_DUMP_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1095800366165623"><a name="p1095800366165623"></a><a name="p1095800366165623"></a>Incorrect dump information. </p>
 </td>
</tr>
<tr id="row1052842421165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a35c07d2afc0f8b17822a9f64b19a8993"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a35c07d2afc0f8b17822a9f64b19a8993"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a35c07d2afc0f8b17822a9f64b19a8993"></a></strong>ERR_APPEXECFWK_COMMAND_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1373203348165623"><a name="p1373203348165623"></a><a name="p1373203348165623"></a>Incorrect command. </p>
 </td>
</tr>
<tr id="row1179467338165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a4d22c64508c3f6c3a9c3e8972e54696c"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4d22c64508c3f6c3a9c3e8972e54696c"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a4d22c64508c3f6c3a9c3e8972e54696c"></a></strong>ERR_APPEXECFWK_CALLBACK_REGISTER_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786142286165623"><a name="p1786142286165623"></a><a name="p1786142286165623"></a>Failed to register the callback. </p>
 </td>
</tr>
<tr id="row1412999665165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ae0dd6d1b6cc227e1a67c910182dee9f9"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ae0dd6d1b6cc227e1a67c910182dee9f9"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ae0dd6d1b6cc227e1a67c910182dee9f9"></a></strong>ERR_APPEXECFWK_CALLBACK_UNREGISTER_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p947292734165623"><a name="p947292734165623"></a><a name="p947292734165623"></a>Failed to unregister the callback. </p>
 </td>
</tr>
<tr id="row1018819650165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a3fc6a7d606bdfc9a569c732f7fc0dc85"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3fc6a7d606bdfc9a569c732f7fc0dc85"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a3fc6a7d606bdfc9a569c732f7fc0dc85"></a></strong>ERR_APPEXECFWK_CALLBACK_GENERATE_LOCAL_SERVICEID_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114054539165623"><a name="p114054539165623"></a><a name="p114054539165623"></a>Failed to generate a service ID for the current process. </p>
 </td>
</tr>
<tr id="row1214694903165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a030663d47f1763759349ab34509a2c1c"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a030663d47f1763759349ab34509a2c1c"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a030663d47f1763759349ab34509a2c1c"></a></strong>ERR_APPEXECFWK_CALLBACK_SERVICEID_TRANSMITTED_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1551915989165623"><a name="p1551915989165623"></a><a name="p1551915989165623"></a>Failed to transmit the service ID of the current process. </p>
 </td>
</tr>
<tr id="row2003747175165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1aeb276d0adcc605cee18e3e06f641626e"><a name="ggac318d4f4dc0125e2367ea8c539770ed1aeb276d0adcc605cee18e3e06f641626e"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1aeb276d0adcc605cee18e3e06f641626e"></a></strong>ERR_APPEXECFWK_CALLBACK_NEVER_REGISTERED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1838375740165623"><a name="p1838375740165623"></a><a name="p1838375740165623"></a>The callback is never registered. </p>
 </td>
</tr>
<tr id="row2052754344165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ab853bfd0b4558a663bd683ab6a365c8b"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab853bfd0b4558a663bd683ab6a365c8b"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ab853bfd0b4558a663bd683ab6a365c8b"></a></strong>ERR_APPEXECFWK_CALLBACK_OBTAIN_ALL_BUNDLE_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p331698810165623"><a name="p331698810165623"></a><a name="p331698810165623"></a>Failed to obtain the bundle names of all applications in the system. </p>
 </td>
</tr>
<tr id="row1298427292165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a8e8a7a1f2d610d5f078dc79959776930"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8e8a7a1f2d610d5f078dc79959776930"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8e8a7a1f2d610d5f078dc79959776930"></a></strong>ERR_APPEXECFWK_CALLBACK_NULL_CORRESPONDING_CALLBACK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p255470674165623"><a name="p255470674165623"></a><a name="p255470674165623"></a>The required callback is unavailable. </p>
 </td>
</tr>
<tr id="row1653510829165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1acb14a1daa5fe17eb25798bbcd98bcd57"><a name="ggac318d4f4dc0125e2367ea8c539770ed1acb14a1daa5fe17eb25798bbcd98bcd57"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1acb14a1daa5fe17eb25798bbcd98bcd57"></a></strong>ERR_APPEXECFWK_CALLBACK_GET_INSTALLTYPE_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98019445165623"><a name="p98019445165623"></a><a name="p98019445165623"></a>Failed to obtain the installation type (installation or uninstallation). </p>
 </td>
</tr>
<tr id="row559218081165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a8898f52b989730709638b26bcb555f54"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8898f52b989730709638b26bcb555f54"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a8898f52b989730709638b26bcb555f54"></a></strong>ERR_APPEXECFWK_CALLBACK_GET_ERROR_INSTALLTYPE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1987471004165623"><a name="p1987471004165623"></a><a name="p1987471004165623"></a>Incorrect installation type. </p>
 </td>
</tr>
<tr id="row1827128529165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1ae31533f402b130eb4cc8fed07706c5b6"><a name="ggac318d4f4dc0125e2367ea8c539770ed1ae31533f402b130eb4cc8fed07706c5b6"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1ae31533f402b130eb4cc8fed07706c5b6"></a></strong>ERR_APPEXECFWK_SERIALIZATION_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1000133454165623"><a name="p1000133454165623"></a><a name="p1000133454165623"></a>Serialization failed. </p>
 </td>
</tr>
<tr id="row710570926165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a66b8941c7c418eedc7df7f758cbacc42"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a66b8941c7c418eedc7df7f758cbacc42"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a66b8941c7c418eedc7df7f758cbacc42"></a></strong>ERR_APPEXECFWK_DESERIALIZATION_FAILED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1416377763165623"><a name="p1416377763165623"></a><a name="p1416377763165623"></a>Deserialization failed. </p>
 </td>
</tr>
<tr id="row1721144994165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a19aa79fde7b3e4da78567e4fcbe306a7"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a19aa79fde7b3e4da78567e4fcbe306a7"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a19aa79fde7b3e4da78567e4fcbe306a7"></a></strong>ERR_APPEXECFWK_SYSTEM_INTERNAL_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p633416952165623"><a name="p633416952165623"></a><a name="p633416952165623"></a>Internal system error. </p>
 </td>
</tr>
<tr id="row1373293990165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a0ad2ce2d577f995c2ba3ea946ce366e6"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0ad2ce2d577f995c2ba3ea946ce366e6"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a0ad2ce2d577f995c2ba3ea946ce366e6"></a></strong>ERR_APPEXECFWK_NO_BUNDLENAME_FOR_UID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742965776165623"><a name="p1742965776165623"></a><a name="p1742965776165623"></a>No bundle name associated with the UID is found. </p>
 </td>
</tr>
<tr id="row2056820522165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a9161dd6c967af438a56b01cd916e01c2"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9161dd6c967af438a56b01cd916e01c2"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a9161dd6c967af438a56b01cd916e01c2"></a></strong>ERR_APPEXECFWK_IPCIO_UNAVAILABLED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1013961255165623"><a name="p1013961255165623"></a><a name="p1013961255165623"></a>The <strong id="b1079118460165623"><a name="b1079118460165623"></a><a name="b1079118460165623"></a>IpcIo</strong> structure is unavailable. </p>
 </td>
</tr>
<tr id="row1830181621165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a6cff9490f5817281ac9c2bcdafcf477f"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6cff9490f5817281ac9c2bcdafcf477f"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a6cff9490f5817281ac9c2bcdafcf477f"></a></strong>ERR_APPEXECFWK_INVOKE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043200504165623"><a name="p2043200504165623"></a><a name="p2043200504165623"></a>An error occurred when calling the <strong id="b1896337669165623"><a name="b1896337669165623"></a><a name="b1896337669165623"></a>invoke</strong> function of the Bundle Manager <a href="Service.md">Service</a>. </p>
 </td>
</tr>
<tr id="row1134792525165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac318d4f4dc0125e2367ea8c539770ed1a2c357a03505c34ef9a843876af91739e"><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2c357a03505c34ef9a843876af91739e"></a><a name="ggac318d4f4dc0125e2367ea8c539770ed1a2c357a03505c34ef9a843876af91739e"></a></strong>ERR_APPEXECFWK_PERMISSION_DENIED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354337627165623"><a name="p354337627165623"></a><a name="p354337627165623"></a>The server that invokes the Bundle Manager <a href="Service.md">Service</a> does not have required permission. </p>
 </td>
</tr>
</tbody>
</table>

## InstallLocation<a name="ga4907fd26df42a0abdfd6ade10ac44efb"></a>

```
enum [InstallLocation](BundleManager.md#ga4907fd26df42a0abdfd6ade10ac44efb)
```

<a name="table1923842389165623"></a>
<table><thead align="left"><tr id="row228965211165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2121898363165623"><a name="p2121898363165623"></a><a name="p2121898363165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1604632256165623"><a name="p1604632256165623"></a><a name="p1604632256165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row898444027165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4907fd26df42a0abdfd6ade10ac44efbac2928120cea5ab364b9a0d65ef2ab2dc"><a name="gga4907fd26df42a0abdfd6ade10ac44efbac2928120cea5ab364b9a0d65ef2ab2dc"></a><a name="gga4907fd26df42a0abdfd6ade10ac44efbac2928120cea5ab364b9a0d65ef2ab2dc"></a></strong>INSTALL_LOCATION_INTERNAL_ONLY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p210296208165623"><a name="p210296208165623"></a><a name="p210296208165623"></a>The installation or update path is <strong id="b397120182165623"><a name="b397120182165623"></a><a name="b397120182165623"></a>storage/app</strong> when <strong id="b1435180254165623"><a name="b1435180254165623"></a><a name="b1435180254165623"></a>installLocation</strong> is set to <strong id="b632547745165623"><a name="b632547745165623"></a><a name="b632547745165623"></a>1</strong>. </p>
 </td>
</tr>
<tr id="row578526874165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4907fd26df42a0abdfd6ade10ac44efba2322c010e922d34c040d41cc7ed664ec"><a name="gga4907fd26df42a0abdfd6ade10ac44efba2322c010e922d34c040d41cc7ed664ec"></a><a name="gga4907fd26df42a0abdfd6ade10ac44efba2322c010e922d34c040d41cc7ed664ec"></a></strong>INSTALL_LOCATION_PREFER_EXTERNAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804853769165623"><a name="p804853769165623"></a><a name="p804853769165623"></a>The installation or update path is <strong id="b626283677165623"><a name="b626283677165623"></a><a name="b626283677165623"></a>sdcard/app</strong> when <strong id="b485803883165623"><a name="b485803883165623"></a><a name="b485803883165623"></a>installLocation</strong> is set to <strong id="b258823813165623"><a name="b258823813165623"></a><a name="b258823813165623"></a>2</strong>. </p>
 </td>
</tr>
</tbody>
</table>

## LaunchMode<a name="ga605d46d860e356a74db6842e66522854"></a>

```
enum [LaunchMode](BundleManager.md#ga605d46d860e356a74db6842e66522854)
```

 **Description:**

Enumerates startup modes of an ability. 

<a name="table1353036061165623"></a>
<table><thead align="left"><tr id="row549319862165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1180742752165623"><a name="p1180742752165623"></a><a name="p1180742752165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p36077224165623"><a name="p36077224165623"></a><a name="p36077224165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row873517995165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga605d46d860e356a74db6842e66522854a57da18394d2f90538c40b0b8d4a3a3c7"><a name="gga605d46d860e356a74db6842e66522854a57da18394d2f90538c40b0b8d4a3a3c7"></a><a name="gga605d46d860e356a74db6842e66522854a57da18394d2f90538c40b0b8d4a3a3c7"></a></strong>SINGLETON </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p797622224165623"><a name="p797622224165623"></a><a name="p797622224165623"></a>Singleton mode, allowing only one instance </p>
 </td>
</tr>
<tr id="row1900554423165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga605d46d860e356a74db6842e66522854a9de934790934fe831fe946c851e8338e"><a name="gga605d46d860e356a74db6842e66522854a9de934790934fe831fe946c851e8338e"></a><a name="gga605d46d860e356a74db6842e66522854a9de934790934fe831fe946c851e8338e"></a></strong>STANDARD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178428791165623"><a name="p1178428791165623"></a><a name="p1178428791165623"></a>Standard mode, allowing multiple instances </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1955086544165623"></a>

## ClearAbilityInfo\(\)<a name="ga7377545918725f75645b59b1b7a319fa"></a>

```
void ClearAbilityInfo ([AbilityInfo](AbilityInfo.md) * abilityInfo)
```

 **Description:**

Clears an  [AbilityInfo](AbilityInfo.md)  object. 

This function clears and releases the memory occupied by the fields of the pointer type included in the specified  [AbilityInfo](AbilityInfo.md)  object. 

**Parameters:**

<a name="table1579734649165623"></a>
<table><thead align="left"><tr id="row1292918596165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1663324376165623"><a name="p1663324376165623"></a><a name="p1663324376165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p729552061165623"><a name="p729552061165623"></a><a name="p729552061165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row164539471165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">abilityInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="AbilityInfo.md">AbilityInfo</a> object to clear.</td>
</tr>
</tbody>
</table>

## ClearBundleInfo\(\)<a name="ga78829b21273aefd65844eba4549162ca"></a>

```
void ClearBundleInfo ([BundleInfo](BundleInfo.md) * bundleInfo)
```

 **Description:**

Clears a  [BundleInfo](BundleInfo.md)  object. 

This function clears and releases the memory occupied by the fields of the pointer type included in the specified  [BundleInfo](BundleInfo.md)  object. 

**Parameters:**

<a name="table1112541640165623"></a>
<table><thead align="left"><tr id="row1500382186165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1524087996165623"><a name="p1524087996165623"></a><a name="p1524087996165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1971747411165623"><a name="p1971747411165623"></a><a name="p1971747411165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2057796951165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="BundleInfo.md">BundleInfo</a> object to clear.</td>
</tr>
</tbody>
</table>

## ClearBundleStatusCallback\(\)<a name="gae5e0593438f073199bf6d69e47a84975"></a>

```
void ClearBundleStatusCallback ([BundleStatusCallback](BundleStatusCallback.md) * bundleStatusCallback)
```

 **Description:**

Clears and releases the memory occupied by the  [BundleStatusCallback](BundleStatusCallback.md)  structure. 

**Parameters:**

<a name="table948092290165623"></a>
<table><thead align="left"><tr id="row1664934833165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1438898594165623"><a name="p1438898594165623"></a><a name="p1438898594165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p720677127165623"><a name="p720677127165623"></a><a name="p720677127165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1341533631165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleStatusCallback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="BundleStatusCallback.md">BundleStatusCallback</a> structure to clear.</td>
</tr>
</tbody>
</table>

## ClearElement\(\)<a name="ga3abe15ac14571de84ca72c98f4009724"></a>

```
void ClearElement ([ElementName](ElementName.md) * element)
```

 **Description:**

Clears the internal data of a specified  **[ElementName](ElementName.md)**. 

After  [AbilityInfo](AbilityInfo.md)  is queried, clear the internal data of an  **[ElementName](ElementName.md)**  if it is no longer required. 

**Parameters:**

<a name="table108758122165623"></a>
<table><thead align="left"><tr id="row982072381165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1253779813165623"><a name="p1253779813165623"></a><a name="p1253779813165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1351547134165623"><a name="p1351547134165623"></a><a name="p1351547134165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1837347306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1137667737165623"><a name="b1137667737165623"></a><a name="b1137667737165623"></a><a href="ElementName.md">ElementName</a></strong> to clear. </td>
</tr>
</tbody>
</table>

## ClearModuleInfo\(\)<a name="ga6c2242cc10f135d129b95444faacb345"></a>

```
void ClearModuleInfo ([ModuleInfo](ModuleInfo.md) * moduleInfo)
```

 **Description:**

Clears a  [ModuleInfo](ModuleInfo.md)  object. 

This function clears and releases the memory occupied by the fields of the pointer type included in the specified  [ModuleInfo](ModuleInfo.md)  object. 

**Parameters:**

<a name="table1876941334165623"></a>
<table><thead align="left"><tr id="row2051132927165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p354935866165623"><a name="p354935866165623"></a><a name="p354935866165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1959744705165623"><a name="p1959744705165623"></a><a name="p1959744705165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2048234842165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">moduleInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="ModuleInfo.md">ModuleInfo</a> object to clear.</td>
</tr>
</tbody>
</table>

## GetBundleInfo\(\)<a name="ga5e81134e037911654e34cc8a7ba01a2f"></a>

```
uint8_t GetBundleInfo (const char * bundleName, int32_t flags, [BundleInfo](BundleInfo.md) * bundleInfo )
```

 **Description:**

Obtains the  [BundleInfo](BundleInfo.md)  of an application based on the specified bundle name. 

**Parameters:**

<a name="table851977784165623"></a>
<table><thead align="left"><tr id="row1303315243165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p538133323165623"><a name="p538133323165623"></a><a name="p538133323165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1059132265165623"><a name="p1059132265165623"></a><a name="p1059132265165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row802156302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the application bundle to query. </td>
</tr>
<tr id="row181401317165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether the obtained <a href="BundleInfo.md">BundleInfo</a> object can contain <a href="AbilityInfo.md">AbilityInfo</a>. The value <strong id="b715583576165623"><a name="b715583576165623"></a><a name="b715583576165623"></a>1</strong> indicates that it can contain <a href="AbilityInfo.md">AbilityInfo</a>, and <strong id="b1086762511165623"><a name="b1086762511165623"></a><a name="b1086762511165623"></a>0</strong> indicates that it cannot. </td>
</tr>
<tr id="row2059950001165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained <a href="BundleInfo.md">BundleInfo</a> object.</td>
</tr>
</tbody>
</table>

**Attention:**

Before querying a  [BundleInfo](BundleInfo.md)  object, you should first call  **memset**  on the constructed  [BundleInfo](BundleInfo.md)  object so that each field in it can be properly initialized for carrying the obtained information. 

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## GetBundleInfos\(\)<a name="ga2469dafbc61ba8e98b69041c13044cad"></a>

```
uint8_t GetBundleInfos (const int flags, [BundleInfo](BundleInfo.md) ** bundleInfos, int32_t * len )
```

 **Description:**

Obtains the  [BundleInfo](BundleInfo.md)  of all bundles in the system. 

**Parameters:**

<a name="table145801689165623"></a>
<table><thead align="left"><tr id="row1091025519165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p961866949165623"><a name="p961866949165623"></a><a name="p961866949165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p576277506165623"><a name="p576277506165623"></a><a name="p576277506165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9533894165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether each of the obtained <a href="BundleInfo.md">BundleInfo</a> objects can contain <a href="AbilityInfo.md">AbilityInfo</a>. The value <strong id="b960108949165623"><a name="b960108949165623"></a><a name="b960108949165623"></a>1</strong> indicates that it can contain <a href="AbilityInfo.md">AbilityInfo</a>, and <strong id="b272625305165623"><a name="b272625305165623"></a><a name="b272625305165623"></a>0</strong> indicates that it cannot. </td>
</tr>
<tr id="row1075997321165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleInfos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the obtained <a href="BundleInfo.md">BundleInfo</a> objects. </td>
</tr>
<tr id="row443238665165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the number of <a href="BundleInfo.md">BundleInfo</a> objects obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## GetBundleInfosByMetaData\(\)<a name="ga711965038390aef4fa0a6b6a98f6998b"></a>

```
uint8_t GetBundleInfosByMetaData (const char * metaDataKey, [BundleInfo](BundleInfo.md) ** bundleInfos, int32_t * len )
```

 **Description:**

Obtains the  [BundleInfo](BundleInfo.md)  of application bundles based on the specified  [MetaData](MetaData.md). 

**Parameters:**

<a name="table831090047165623"></a>
<table><thead align="left"><tr id="row1223779654165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1994058114165623"><a name="p1994058114165623"></a><a name="p1994058114165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p936122416165623"><a name="p936122416165623"></a><a name="p936122416165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row300109094165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">metaDataKey</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the metadata name in the <a href="MetaData.md">MetaData</a>. </td>
</tr>
<tr id="row1085282773165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleInfos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the obtained <a href="BundleInfo.md">BundleInfo</a> objects. </td>
</tr>
<tr id="row897018265165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the number of <a href="BundleInfo.md">BundleInfo</a> objects obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## GetBundleNameForUid\(\)<a name="ga4afdc08ba78506fce95a066e137ac46d"></a>

```
uint8_t GetBundleNameForUid (int32_t uid, char ** bundleName )
```

 **Description:**

Obtains the bundle name of an application based on the specified UID. 

**Parameters:**

<a name="table453405855165623"></a>
<table><thead align="left"><tr id="row1996257494165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1960877616165623"><a name="p1960877616165623"></a><a name="p1960877616165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2090968786165623"><a name="p2090968786165623"></a><a name="p2090968786165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1718030306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">uid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the UID of the application to query. </td>
</tr>
<tr id="row194478329165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the bundle name of the application. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## Install\(\)<a name="gaf1f1521a64cc98f076b0082df6c0abdd"></a>

```
bool Install (const char * hapPath, const [InstallParam](InstallParam.md) * installParam, [InstallerCallback](BundleManager.md#ga00f021e76d728d2d44e1a28887ccc3af) installerCallback )
```

 **Description:**

Installs or updates an application. 

**Parameters:**

<a name="table1076893616165623"></a>
<table><thead align="left"><tr id="row1311597403165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p802003237165623"><a name="p802003237165623"></a><a name="p802003237165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p848734840165623"><a name="p848734840165623"></a><a name="p848734840165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1086797739165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">hapPath</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the path for storing the OpenHarmony Ability Package (HAP) of the application to install or update. </td>
</tr>
<tr id="row1537359298165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">installParam</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parameters used for application installation or update. </td>
</tr>
<tr id="row820087608165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">installerCallback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback to be invoked for notifying the installation or update result. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if this function is successfully called; returns  **false**  otherwise.

## QueryAbilityInfo\(\)<a name="ga4360375d15224d89632f59ee110b74c9"></a>

```
uint8_t QueryAbilityInfo (const [Want](Want.md) * want, [AbilityInfo](AbilityInfo.md) * abilityInfo )
```

 **Description:**

Queries the  [AbilityInfo](AbilityInfo.md)  of an ability based on the information carried in the  [Want](Want.md)  structure. 

**Parameters:**

<a name="table587052112165623"></a>
<table><thead align="left"><tr id="row689026584165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p361804400165623"><a name="p361804400165623"></a><a name="p361804400165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1874940740165623"><a name="p1874940740165623"></a><a name="p1874940740165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1969097106165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">want</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="Want.md">Want</a> structure used for querying the specified ability. </td>
</tr>
<tr id="row1177236846165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">abilityInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained <a href="AbilityInfo.md">AbilityInfo</a> object.</td>
</tr>
</tbody>
</table>

**Attention:**

Before querying an  [AbilityInfo](AbilityInfo.md)  object, you should first call  **memset**  on the constructed  [AbilityInfo](AbilityInfo.md)  object so that each field in it can be properly initialized for carrying the obtained information. 

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## QueryKeepAliveBundleInfos\(\)<a name="ga0c1cb00194993ecba7337fdf0a203314"></a>

```
uint8_t QueryKeepAliveBundleInfos ([BundleInfo](BundleInfo.md) ** bundleInfos, int32_t * len )
```

 **Description:**

Obtains the  [BundleInfo](BundleInfo.md)  of all keep-alive applications in the system. 

**Parameters:**

<a name="table211469896165623"></a>
<table><thead align="left"><tr id="row1798248711165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p563089864165623"><a name="p563089864165623"></a><a name="p563089864165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1275382313165623"><a name="p1275382313165623"></a><a name="p1275382313165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1480028734165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleInfos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the obtained <a href="BundleInfo.md">BundleInfo</a> objects. </td>
</tr>
<tr id="row1288989035165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the number of <a href="BundleInfo.md">BundleInfo</a> objects obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## RegisterCallback\(\)<a name="ga5c49620ca8b752cd6f43fabc5d5c7416"></a>

```
int32_t RegisterCallback ([BundleStatusCallback](BundleStatusCallback.md) * BundleStatusCallback)
```

 **Description:**

Registers a callback to monitor the installation, update, and uninstallation state changes of an application. 

**Parameters:**

<a name="table59335295165623"></a>
<table><thead align="left"><tr id="row1850524181165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1941439871165623"><a name="p1941439871165623"></a><a name="p1941439871165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p938133813165623"><a name="p938133813165623"></a><a name="p938133813165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row763106755165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><a href="BundleStatusCallback.md">BundleStatusCallback</a></td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the callback to be invoked when the installation, update, or uninstallation state of the monitored application changes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

## SetElementAbilityName\(\)<a name="ga93a575cc428cb96526ae02b3997f1f3b"></a>

```
bool SetElementAbilityName ([ElementName](ElementName.md) * element, const char * abilityName )
```

 **Description:**

Sets the class name of the ability used to query  [AbilityInfo](AbilityInfo.md). 

**Parameters:**

<a name="table459460438165623"></a>
<table><thead align="left"><tr id="row1400994627165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1964525839165623"><a name="p1964525839165623"></a><a name="p1964525839165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1160732430165623"><a name="p1160732430165623"></a><a name="p1160732430165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row857278558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1791153335165623"><a name="b1791153335165623"></a><a name="b1791153335165623"></a><a href="ElementName.md">ElementName</a></strong> to set. </td>
</tr>
<tr id="row659917475165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">abilityName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the class name to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetElementBundleName\(\)<a name="ga60692e66a3a204a2f16f70c5cd452c1d"></a>

```
bool SetElementBundleName ([ElementName](ElementName.md) * element, const char * bundleName )
```

 **Description:**

Sets the bundle name used to query  [AbilityInfo](AbilityInfo.md). 

**Parameters:**

<a name="table766551837165623"></a>
<table><thead align="left"><tr id="row1162400358165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p923548735165623"><a name="p923548735165623"></a><a name="p923548735165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1734663167165623"><a name="p1734663167165623"></a><a name="p1734663167165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1943975699165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1538641850165623"><a name="b1538641850165623"></a><a name="b1538641850165623"></a><a href="ElementName.md">ElementName</a></strong> to set. </td>
</tr>
<tr id="row1137533660165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the bundle name to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetElementDeviceID\(\)<a name="ga90e16f159ee8e7f1a9385feebb3dbc0c"></a>

```
bool SetElementDeviceID ([ElementName](ElementName.md) * element, const char * deviceId )
```

 **Description:**

Sets the device ID used to query  [AbilityInfo](AbilityInfo.md). 

**Parameters:**

<a name="table879523225165623"></a>
<table><thead align="left"><tr id="row1429891164165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1448258936165623"><a name="p1448258936165623"></a><a name="p1448258936165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p678728530165623"><a name="p678728530165623"></a><a name="p678728530165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row439794661165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">element</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b242454184165623"><a name="b242454184165623"></a><a name="b242454184165623"></a><a href="ElementName.md">ElementName</a></strong> to set. </td>
</tr>
<tr id="row562084481165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the device ID to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## Uninstall\(\)<a name="gaa117e44378315a61b4e71fd252b2e496"></a>

```
bool Uninstall (const char * bundleName, const [InstallParam](InstallParam.md) * installParam, [InstallerCallback](BundleManager.md#ga00f021e76d728d2d44e1a28887ccc3af) installerCallback )
```

 **Description:**

Uninstalls an application. 

**Parameters:**

<a name="table126777820165623"></a>
<table><thead align="left"><tr id="row511576079165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1537656761165623"><a name="p1537656761165623"></a><a name="p1537656761165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2142082947165623"><a name="p2142082947165623"></a><a name="p2142082947165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2127373611165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bundleName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the bundle name of the application to uninstall. </td>
</tr>
<tr id="row1965659047165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">installParam</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parameters used for application uninstallation. </td>
</tr>
<tr id="row56667197165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">installerCallback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback to be invoked for notifying the uninstallation result. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if this function is successfully called; returns  **false**  otherwise.

## UnregisterCallback\(\)<a name="ga095eee592eff6ce71a2a67a1a0e3e344"></a>

```
int32_t UnregisterCallback ()
```

 **Description:**

Unregisters a callback previously registered for monitoring the installation, update, and uninstallation stat changes of an application. 

**Returns:**

Returns  [ERR\_OK](BundleManager.md#ggac318d4f4dc0125e2367ea8c539770ed1aa26c163b80b1f6786ca81dadc14b00fb)  if this function is successfully called; returns another error code defined in  [AppexecfwkErrors](BundleManager.md#gac318d4f4dc0125e2367ea8c539770ed1)  otherwise.

