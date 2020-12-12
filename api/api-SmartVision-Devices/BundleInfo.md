# BundleInfo<a name="ZH-CN_TOPIC_0000001055678086"></a>

-   [Overview](#section1282840164165630)
-   [Summary](#section607899683165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section402726232165630)
-   [Field](#section472693729165630)
-   [abilityInfos](#a3ada4a71ec78f2f2d6c78b8db9406d40)
-   [appId](#ad0eff56be21d5023221ce20da5ab9efb)
-   [bigIconPath](#a8e34521fed8544d56fe744e895504940)
-   [bundleName](#aec3498345b5e999424348aff0a723db7)
-   [codePath](#a48870c542ef26637af24b6e424af9e66)
-   [compatibleApi](#af672c11317ab2608732ebfadf0bfdc94)
-   [dataPath](#ac4fcbb75da508f66f815c275d3e53888)
-   [gid](#a9d43b35b1e8310173e75a3fd3e9e2e5d)
-   [isKeepAlive](#a6f953f1be6da55f3b0afb292ae36d30f)
-   [isNativeApp](#a4c9154f98628fff6b2016d9fe3e6bc23)
-   [isSystemApp](#ae4572da0f7c456734c7fcc6158e5a5f1)
-   [label](#a008c2aab5a80d72a283ebb033f3a00e9)
-   [moduleInfos](#a7f558b993f8ffd70264b490ea079e178)
-   [numOfAbility](#a0691b2c2822bc661f6618b7d376010b9)
-   [numOfModule](#ae6d0d5a10be24006397e1436a757f899)
-   [targetApi](#a7cbe4debddb5d278af13ca09e55409c9)
-   [uid](#a4c469e7cb5dbea185de3a70f18adeeb4)
-   [vendor](#aa82cb2180789691e20e75d0371dec7cd)
-   [versionCode](#a10ebbd5523a9f9f7b38b04ac365fa9ee)
-   [versionName](#a5381cbf05a30ee5cb5bc1a7daa18084e)

## **Overview**<a name="section1282840164165630"></a>

**Related Modules:**

[BundleManager](BundleManager.md)

**Description:**

Defines the bundle information. 

## **Summary**<a name="section607899683165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table272858043165630"></a>
<table><thead align="left"><tr id="row2099368327165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1247396803165630"><a name="p1247396803165630"></a><a name="p1247396803165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1323998256165630"><a name="p1323998256165630"></a><a name="p1323998256165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1273439460165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402140638165630"><a name="p1402140638165630"></a><a name="p1402140638165630"></a><a href="BundleInfo.md#a6f953f1be6da55f3b0afb292ae36d30f">isKeepAlive</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1879987730165630"><a name="p1879987730165630"></a><a name="p1879987730165630"></a>bool </p>
</td>
</tr>
<tr id="row349775401165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p291381662165630"><a name="p291381662165630"></a><a name="p291381662165630"></a><a href="BundleInfo.md#a4c9154f98628fff6b2016d9fe3e6bc23">isNativeApp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1747646960165630"><a name="p1747646960165630"></a><a name="p1747646960165630"></a>bool </p>
</td>
</tr>
<tr id="row419992360165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1843152999165630"><a name="p1843152999165630"></a><a name="p1843152999165630"></a><a href="BundleInfo.md#a4c469e7cb5dbea185de3a70f18adeeb4">uid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044438522165630"><a name="p2044438522165630"></a><a name="p2044438522165630"></a>int32_t </p>
</td>
</tr>
<tr id="row1181788489165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323738012165630"><a name="p1323738012165630"></a><a name="p1323738012165630"></a><a href="BundleInfo.md#a9d43b35b1e8310173e75a3fd3e9e2e5d">gid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929827365165630"><a name="p929827365165630"></a><a name="p929827365165630"></a>int32_t </p>
</td>
</tr>
<tr id="row974250661165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281639780165630"><a name="p1281639780165630"></a><a name="p1281639780165630"></a><a href="BundleInfo.md#ae4572da0f7c456734c7fcc6158e5a5f1">isSystemApp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p222934246165630"><a name="p222934246165630"></a><a name="p222934246165630"></a>bool </p>
</td>
</tr>
<tr id="row915380620165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1366968653165630"><a name="p1366968653165630"></a><a name="p1366968653165630"></a><a href="BundleInfo.md#af672c11317ab2608732ebfadf0bfdc94">compatibleApi</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605873034165630"><a name="p1605873034165630"></a><a name="p1605873034165630"></a>int32_t </p>
</td>
</tr>
<tr id="row1481384525165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1127428963165630"><a name="p1127428963165630"></a><a name="p1127428963165630"></a><a href="BundleInfo.md#a7cbe4debddb5d278af13ca09e55409c9">targetApi</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624230133165630"><a name="p624230133165630"></a><a name="p624230133165630"></a>int32_t </p>
</td>
</tr>
<tr id="row608526678165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788638201165630"><a name="p1788638201165630"></a><a name="p1788638201165630"></a><a href="BundleInfo.md#a10ebbd5523a9f9f7b38b04ac365fa9ee">versionCode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789473478165630"><a name="p1789473478165630"></a><a name="p1789473478165630"></a>int32_t </p>
</td>
</tr>
<tr id="row1635625193165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032456230165630"><a name="p1032456230165630"></a><a name="p1032456230165630"></a><a href="BundleInfo.md#a5381cbf05a30ee5cb5bc1a7daa18084e">versionName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892125567165630"><a name="p1892125567165630"></a><a name="p1892125567165630"></a>char * </p>
</td>
</tr>
<tr id="row1252361730165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282904453165630"><a name="p282904453165630"></a><a name="p282904453165630"></a><a href="BundleInfo.md#aec3498345b5e999424348aff0a723db7">bundleName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p620069246165630"><a name="p620069246165630"></a><a name="p620069246165630"></a>char * </p>
</td>
</tr>
<tr id="row1525540244165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p479487558165630"><a name="p479487558165630"></a><a name="p479487558165630"></a><a href="BundleInfo.md#a008c2aab5a80d72a283ebb033f3a00e9">label</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p408677231165630"><a name="p408677231165630"></a><a name="p408677231165630"></a>char * </p>
</td>
</tr>
<tr id="row160015809165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2043128300165630"><a name="p2043128300165630"></a><a name="p2043128300165630"></a><a href="BundleInfo.md#a8e34521fed8544d56fe744e895504940">bigIconPath</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2065635902165630"><a name="p2065635902165630"></a><a name="p2065635902165630"></a>char * </p>
</td>
</tr>
<tr id="row666330452165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32224663165630"><a name="p32224663165630"></a><a name="p32224663165630"></a><a href="BundleInfo.md#a48870c542ef26637af24b6e424af9e66">codePath</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804938941165630"><a name="p804938941165630"></a><a name="p804938941165630"></a>char * </p>
</td>
</tr>
<tr id="row963659888165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1070206769165630"><a name="p1070206769165630"></a><a name="p1070206769165630"></a><a href="BundleInfo.md#ac4fcbb75da508f66f815c275d3e53888">dataPath</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182035550165630"><a name="p182035550165630"></a><a name="p182035550165630"></a>char * </p>
</td>
</tr>
<tr id="row1990712221165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016757430165630"><a name="p2016757430165630"></a><a name="p2016757430165630"></a><a href="BundleInfo.md#aa82cb2180789691e20e75d0371dec7cd">vendor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152863722165630"><a name="p152863722165630"></a><a name="p152863722165630"></a>char * </p>
</td>
</tr>
<tr id="row1532741832165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p514147158165630"><a name="p514147158165630"></a><a name="p514147158165630"></a><a href="BundleInfo.md#a7f558b993f8ffd70264b490ea079e178">moduleInfos</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151276686165630"><a name="p151276686165630"></a><a name="p151276686165630"></a><a href="ModuleInfo.md">ModuleInfo</a> * </p>
</td>
</tr>
<tr id="row652070661165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p512411942165630"><a name="p512411942165630"></a><a name="p512411942165630"></a><a href="BundleInfo.md#ae6d0d5a10be24006397e1436a757f899">numOfModule</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708171279165630"><a name="p708171279165630"></a><a name="p708171279165630"></a>int32_t </p>
</td>
</tr>
<tr id="row147487996165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p434382759165630"><a name="p434382759165630"></a><a name="p434382759165630"></a><a href="BundleInfo.md#ad0eff56be21d5023221ce20da5ab9efb">appId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p436493053165630"><a name="p436493053165630"></a><a name="p436493053165630"></a>char * </p>
</td>
</tr>
<tr id="row1960541311165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1109092668165630"><a name="p1109092668165630"></a><a name="p1109092668165630"></a><a href="BundleInfo.md#a3ada4a71ec78f2f2d6c78b8db9406d40">abilityInfos</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523000115165630"><a name="p1523000115165630"></a><a name="p1523000115165630"></a><a href="AbilityInfo.md">AbilityInfo</a> * </p>
</td>
</tr>
<tr id="row253829953165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336693577165630"><a name="p1336693577165630"></a><a name="p1336693577165630"></a><a href="BundleInfo.md#a0691b2c2822bc661f6618b7d376010b9">numOfAbility</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1980778113165630"><a name="p1980778113165630"></a><a name="p1980778113165630"></a>int32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section402726232165630"></a>

## **Field **<a name="section472693729165630"></a>

## abilityInfos<a name="a3ada4a71ec78f2f2d6c78b8db9406d40"></a>

```
[AbilityInfo](AbilityInfo.md)* BundleInfo::abilityInfos
```

 **Description:**

Pointer to the ability information about the application. The ability information is encapsulated in  [AbilityInfo](AbilityInfo.md)  objects. 

## appId<a name="ad0eff56be21d5023221ce20da5ab9efb"></a>

```
char* BundleInfo::appId
```

 **Description:**

Application ID, which uniquely identifies an application. It is a combination of the bundle name and signature of the application. 

## bigIconPath<a name="a8e34521fed8544d56fe744e895504940"></a>

```
char* BundleInfo::bigIconPath
```

 **Description:**

Pointer to the big icon of the application 

## bundleName<a name="aec3498345b5e999424348aff0a723db7"></a>

```
char* BundleInfo::bundleName
```

 **Description:**

Pointer to the bundle name of the application 

## codePath<a name="a48870c542ef26637af24b6e424af9e66"></a>

```
char* BundleInfo::codePath
```

 **Description:**

Pointer to the installation path of the application, which is in the  **/app/run/bundle name**  format 

## compatibleApi<a name="af672c11317ab2608732ebfadf0bfdc94"></a>

```
int32_t BundleInfo::compatibleApi
```

 **Description:**

Minimum API version required 

## dataPath<a name="ac4fcbb75da508f66f815c275d3e53888"></a>

```
char* BundleInfo::dataPath
```

 **Description:**

Pointer to the path for storing data files of the application. The data path is  **/app/data**. 

## gid<a name="a9d43b35b1e8310173e75a3fd3e9e2e5d"></a>

```
int32_t BundleInfo::gid
```

 **Description:**

Application group ID allocated during application installation 

## isKeepAlive<a name="a6f953f1be6da55f3b0afb292ae36d30f"></a>

```
bool BundleInfo::isKeepAlive
```

 **Description:**

Whether the application is kept alive 

## isNativeApp<a name="a4c9154f98628fff6b2016d9fe3e6bc23"></a>

```
bool BundleInfo::isNativeApp
```

 **Description:**

Whether the application is a local application. A local application refers to an application developed using C++ in the system. The value  **true**  indicates a local application, and  **false**  indicates a non-local application. 

## isSystemApp<a name="ae4572da0f7c456734c7fcc6158e5a5f1"></a>

```
bool BundleInfo::isSystemApp
```

 **Description:**

Whether the application is a system application. System applications cannot be uninstalled. The value  **true**  indicates a system application, and  **false**  indicates a non-system application. 

## label<a name="a008c2aab5a80d72a283ebb033f3a00e9"></a>

```
char* BundleInfo::label
```

 **Description:**

Pointer to the application name visible to users 

## moduleInfos<a name="a7f558b993f8ffd70264b490ea079e178"></a>

```
[ModuleInfo](ModuleInfo.md)* BundleInfo::moduleInfos
```

 **Description:**

Pointer to the HAP package information about the application. The HAP information is encapsulated in  [ModuleInfo](ModuleInfo.md)  objects. 

## numOfAbility<a name="a0691b2c2822bc661f6618b7d376010b9"></a>

```
int32_t BundleInfo::numOfAbility
```

 **Description:**

Number of  [AbilityInfo](AbilityInfo.md)  objects in the application 

## numOfModule<a name="ae6d0d5a10be24006397e1436a757f899"></a>

```
int32_t BundleInfo::numOfModule
```

 **Description:**

Number of  [ModuleInfo](ModuleInfo.md)  objects included in the application 

## targetApi<a name="a7cbe4debddb5d278af13ca09e55409c9"></a>

```
int32_t BundleInfo::targetApi
```

 **Description:**

Target API version 

## uid<a name="a4c469e7cb5dbea185de3a70f18adeeb4"></a>

```
int32_t BundleInfo::uid
```

 **Description:**

UID allocated during application installation 

## vendor<a name="aa82cb2180789691e20e75d0371dec7cd"></a>

```
char* BundleInfo::vendor
```

 **Description:**

Pointer to the vendor name of the application 

## versionCode<a name="a10ebbd5523a9f9f7b38b04ac365fa9ee"></a>

```
int32_t BundleInfo::versionCode
```

 **Description:**

Version code of the application, which is the internal version number 

## versionName<a name="a5381cbf05a30ee5cb5bc1a7daa18084e"></a>

```
char* BundleInfo::versionName
```

 **Description:**

Pointer to the version name visible to users 

