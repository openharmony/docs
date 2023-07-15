# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理API异常处理方式变更，原有API8及之前的接口全部废弃，需要使用新的API9接口
包管理接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。对原有接口进行整改，原有API8及之前的接口全部废弃，需要使用新的API9接口。

**变更影响**

基于OpenHarmony3.2.8.2及之后的SDK版本开发的应用，需适配API9的模块和接口，以及的API异常处理返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

新增接口按照模块进行了划分，将原有的的d.ts分成多个d.ts，可以根据业务需要导入不同的d.ts。新增接口支持统一的错误码异常处理规范，功能上与原接口保持一致。部分功能有变更或者新增的接口会单独列出。

为适配统一的API异常处理方式，对包管理API8及之前的接口进行废弃（下表中**原接口**列内容），并新增对应API9接口（下表中**新接口**列内容）。

| 原接口（废弃）       |       新接口（新增） |
| ------              |           ------ |
|   @ohos.bundle.d.ts   |   [@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)     |
|   @ohos.bundle.d.ts   |   [@ohos.bundle.freeInstall.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.freeInstall.d.ts)     |
|   @ohos.bundle.d.ts   |   [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts)     |
|   @ohos.bundle.innerBundleManager.d.ts   |   [@ohos.bundle.launcherBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.launcherBundleManager.d.ts)      |
|  @ohos.bundle.innerBundleManager.d.ts |  [@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts) |
|   @ohos.bundle.defaultAppManager.d.ts   |   [@ohos.bundle.defaultAppManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.defaultAppManager.d.ts)     |
|   @ohos.distributedBundle.d.ts   |   [@ohos.bundle.distributedBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.distributedBundleManager.d.ts)     |
|  无  |  [@ohos.bundle.appControl.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.appControl.d.ts)  |
|  @system.package.d.ts |  无 |

**适配指导**<br>
1. 调用包管理查询相关接口。
```
import bundle form '@ohos.bundle.bundleManager'
```
2. 调用包管理安装卸载相关接口
```
import installer form '@ohos.bundle.installer'
```
3. 调用包管理免安装相关接口
```
import freeInstall form '@ohos.bundle.freeInstall'
```
4. 调用包管理launcher相关接口
```
import launcherBundleManager form '@ohos.bundle.launcherBundleManager'
import bundleMonitor form '@ohos.bundle.bundleMonitor'
```
6. 调用包管理默认应用相关接口
```
import defaultAppManager form '@ohos.bundle.defaultAppManager'
```
7. 调用包管理分布式相关接口
```
import distributedBundle form '@ohos.bundle.distributedBundle'
```
此外还需要适配异常处理，具体参考新接口的接口文档。

## cl.bundlemanager.2 包管理API结构体变更，原有API8及之前的结构体全部废弃，需要使用新的API9结构体
包管理接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。原有API8及之前的结构体全部废弃，需要使用新的API9结构体。

**变更影响**

基于OpenHarmony3.2.8.2及之后的SDK版本开发的应用，需适配变更结构体，否则会影响原有业务逻辑。原有二级模块的导出功能也会废弃，需要使用新接口的二级模块到处能力，需要导入新的一级d.ts模块。

**关键接口/组件变更**

新增结构体对原有的API8及之前的结构体进行梳理，将原有API8及之前的结构体全部废弃，新增新的API9结构体，变更前后的对比如下表所示，部分结构体进行了合并，例如moduleInfo.d.ts替换为hapModuleInfo.d.ts，customizeData.d.ts替换为metadata.d.ts。结构体功能上与原结构体保持一致。部分功能有变更或者新增的结构体属性会单独列出。
| 原结构体（废弃）       |       新结构体（新增） |
| ------              |         ------ |
| bundle/abilityInfo.d.ts          | [bundleManager/abilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts) |
| bundle/applicationInfo.d.ts      | [bundleManager/applicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) |
| bundle/bundleInfo.d.ts           | [bundleManager/bundleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundleInfo.d.ts) |
| bundle/bundleInstaller.d.ts      | [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts) |
| bundle/bundleStatusCallback.d.ts | [@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts) |
| bundle/customizeData.d.ts        | [bundleManager/metadata.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/Metadata.d.ts) |
| bundle/dispatchInfo.d.ts         | [bundleManager/dispatchInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/DispatchInfo.d.ts) |
| bundle/elementName.d.ts          | [bundleManager/elementName.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ElementName.d.ts) |
| bundle/extensionAbilityInfo.d.ts | [bundleManager/extensionAbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts) |
| bundle/hapModuleInfo.d.ts        | [bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) |
| bundle/launcherAbilityInfo.d.ts  | [bundleManager/launcherAbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/LauncherAbilityInfo.d.ts) |
| bundle/metadata.d.ts             | [bundleManager/metadata.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/Metadata.d.ts) |
| bundle/moduleInfo.d.ts           | [bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) |
| bundle/PermissionDef.d.ts        | [bundleManager/permissionDef.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/PermissionDef.d.ts) |
| bundle/remoteAbilityInfo.d.ts    | [bundleManager/remoteAbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/RemoteAbilityInfo.d.ts) |
| bundle/shortcutInfo.d.ts         | [bundleManager/shortcutInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ShortcutInfo.d.ts) |

**适配指导**<br>
1. 使用原有结构体的代码需要修改为新结构体。
2. 原有二级模块的导出功能也会废弃，可以使用新接口的二级模块到处能力，需要导入新的一级d.ts模块。

## cl.bundlemanager.3 包管理查询模块接口变更，@ohos.bundle.d.ts中接口全部废弃，新增@ohos.bundle.bundleManager.d.ts、@ohos.bundle.freeInstall.d.ts和@ohos.bundle.installer.d.ts模块，将原有接口新增或者变更至新d.ts中

包管理模块查询接口变更，废弃了@ohos.bundle中API8及之前的全部接口，其中的API9接口变更至@ohos.bundle.bundleManager、@ohos.bundle.freeInstall和@ohos.bundle.installer中，@ohos.bundle.bundleManager中新增了之前废弃的大部分接口，修改为systemapi，并增加了异常处理能力。

使用方式的变化：由原来的@ohos.bundle修改为@ohos.bundle.bundleManager、@ohos.bundle.freeInstall和@ohos.bundle.installer模块来使用相关的接口。

@ohos.bundle.bundleManager和@ohos.bundle.installer模块系统能力为SystemCapability.BundleManager.BundleFramework.Core，@ohos.bundle.freeInstall模块系统能力为SystemCapability.BundleManager.BundleFramework.FreeInstall。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。在@ohos.bundle原有的API9接口，变更到新的@ohos.bundle.bundleManager.d.ts、@ohos.bundle.freeInstall和@ohos.bundle.installer文件中。

**关键的接口/组件变更**<br>
@ohos.bundle.d.ts中涉及到的废弃和变更接口如下表所示。未在表格中列出的表明除了增加异常处理和变更导入模块外，接口名称和入参均未发生变化，直接导入新的@ohos.bundle.bundleManager.d.ts、@ohos.bundle.freeInstall和@ohos.bundle.installer就可使用。在表格中列出的均表示在API9接口上发生变更，标记为无的表示在API9上已废弃。

| 原接口（废弃） | 新接口（变更或新增）| systemapi|新文件名|
| ---| ---| --- | --|
| BundleFlag |  BundleFlag | 否 |  @ohos.bundle.bundleManager.d.ts |
| 无 |  ApplicationFlag | 是 |  @ohos.bundle.bundleManager.d.ts |
| 无 |  AbilityFlag | 是 |  @ohos.bundle.bundleManager.d.ts |
| ExtensionFlag | ExtensionAbilityFlag | 是 | @ohos.bundle.bundleManager.d.ts |
| ColorMode |  无 |  否 |  无 |
| GrantStatus |  PermissionGrantState | 否  |  @ohos.bundle.bundleManager.d.ts |
| AbilityType |  AbilityType | 否 |  @ohos.bundle.bundleManager.d.ts |
| AbilitySubType |  无 |  否 |  无 |
| DisplayOrientation | DisplayOrientation | 否 |  @ohos.bundle.bundleManager.d.ts |
| LaunchMode |  LaunchType | 否 | @ohos.bundle.bundleManager.d.ts |
| ExtensionAbilityType | ExtensionAbilityType  |  是 |  @ohos.bundle.bundleManager.d.ts |
| BundleOptions | 无  | 否 | 无 |
| InstallErrorCode | 无 |  否 | 无  |
| UpgradeFlag | UpgradeFlag | 是 | @ohos.bundle.freeInstall.d.ts |
| SupportWindowMode | SupportWindowMode  | 否 | @ohos.bundle.bundleManager.d.ts |
| getBundleInfo | getBundleInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getBundleInstaller | getBundleInstaller | 是 | @ohos.bundle.installer.d.ts |
| getAbilityInfo | queryAbilityInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getApplicationInfo | getApplicationInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| queryAbilityByWant | queryAbilityInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getAllBundleInfo | getAllBundleInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getAllApplicationInfo | getAllApplicationInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getNameForUid | getBundleNameByUid | 是 | @ohos.bundle.bundleManager.d.ts |
| getBundleArchiveInfo |getBundleArchiveInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getLaunchWantForBundle | getLaunchWantForBundle | 是 | @ohos.bundle.bundleManager.d.ts |
| cleanBundleCacheFiles | cleanBundleCacheFiles | 是 | @ohos.bundle.bundleManager.d.ts |
| setApplicationEnabled | setApplicationEnabled | 是 | @ohos.bundle.bundleManager.d.ts |
| setAbilityEnabled | setAbilityEnabled | 是 | @ohos.bundle.bundleManager.d.ts |
| queryExtensionAbilityInfos | queryExtensionAbilityInfo | 是 | @ohos.bundle.bundleManager.d.ts |
| getPermissionDef | getPermissionDef | 是 | @ohos.bundle.bundleManager.d.ts |
| getAbilityLabel | getAbilityLabel | 是 | @ohos.bundle.bundleManager.d.ts |
| getAbilityIcon | getAbilityIcon | 是 | @ohos.bundle.bundleManager.d.ts |
| isAbilityEnabled | isAbilityEnabled | 是 | @ohos.bundle.bundleManager.d.ts |
| isApplicationEnabled | isApplicationEnabled | 是 | @ohos.bundle.bundleManager.d.ts |
| setModuleUpgradeFlag | setHapModuleUpgradeFlag | 是 | @ohos.bundle.freeInstall.d.ts |
| isModuleRemovable | isHapModuleRemovable | 是 | @ohos.bundle.freeInstall.d.ts |
| getBundlePackInfo | getBundlePackInfo | 是 | @ohos.bundle.freeInstall.d.ts |
| getDispatcherVersion | getDispatchInfo | 是 | @ohos.bundle.freeInstall.d.ts |
| getProfileByAbility |  getProfileByAbility | 否 | @ohos.bundle.bundleManager.d.ts |
| getProfileByExtensionAbility | getProfileByExtensionAbility | 否 | @ohos.bundle.bundleManager.d.ts |
| setDisposedStatus | setDisposedStatus | 是 | @ohos.bundle.appControl.d.ts |
| getDisposedStatus | getDisposedStatus | 是 | @ohos.bundle.appControl.d.ts |
| 无 | deleteDisposedStatus |  是 | @ohos.bundle.appControl.d.ts |
| getBundleInfoSync | getBundleInfoSync | 是 | @ohos.bundle.bundleManager.d.ts |
| getApplicationInfoSync | getApplicationInfoSync | 是 | @ohos.bundle.bundleManager.d.ts |
|无| getBundleInfoForSelf | 否 | @ohos.bundle.bundleManager.d.ts |


**适配指导**<br>
将原接口替换为API9新增的接口，导入相关的模块。

旧的导入模块：
```
import bundle form '@ohos.bundle'
```
新的导入模块：
```
import bundle form '@ohos.bundle.bundleManager'
import freeInstall form '@ohos.bundle.freeInstall'
import installer form '@ohos.bundle.installer'
import appControl form '@ohos.bundle.appControl'
```

## cl.bundlemanager.4 BundleInfo结构体变更，包管理原有bundle/bundleInfo.d.ts字段全部废弃变更为bundleManager/bundleInfo.d.ts，涉及字段属性变化。

包管理原有bundle/bundleInfo.d.ts字段全部废弃。由老的[bundle/bundleInfo.d.ts]((https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundle/bundleInfo.d.ts))变更为[bundleManager/bundleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundleInfo.d.ts)，涉及字段属性变化。


**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。使用二级模块导出BundleInfo时，需要导入@ohos.bundle.bundleManager模块。

**关键的接口/组件变更**<br>

BundleInfo结构体发生变化的字段内容如下表所示。其余字段在bundle/bundleInfo.d.ts中废弃后，在新的[bundleManager/bundleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundleInfo.d.ts)中均有对应值。没有对应字段，则表明该字段已经在API9上废弃。

| 已废弃 | API9新增或变更 | 类型 |
| --- | --- | --- |
| type  | 无  | string |
| appId  | 无 | string |
| 无  |signatureInfo | SignatureInfo |
| uid  | 无  | number |  无|
| abilityInfos  | 无 | Array\<AbilityInfo> |
| reqPermissions  | 无 |  Array<string> |
| compatibleVersion | 无 | number |
| isCompressNativeLibs  | 无  | boolean | 
|  entryModuleName | 无 | string |
|  cpuAbi  | 无 | string |
|  isSilentInstallation  | 无  | string | 
| entryInstallationFree  | 无  | boolean |
| reqPermissionStates  | permissionGrantStates  | Array\<bundleManager.PermissionGrantState> |
|  extensionAbilityInfo  | 无 |Array\<ExtensionAbilityInfo>|
| hapModuleInfos | hapModulesInfo | Array\<HapModuleInfo> |

API9中新增SignatureInfo结构体，该结构体如下：

| 属性名      | 类型   |
| ----------- | ------ |
| appId       | string |
| fingerprint | string |


**适配指导**<br>
导入包管理查询的模块，使用API9 version的BundleInfo结构体，使用二级模块导出时也需要引入下面模块。
```
import bundle form '@ohos.bundle.bundleManager'
```

## cl.bundlemanager.5 ApplicationInfo结构体变更，包管理原有bundle/applicationInfo.d.ts字段全部废弃，变更为bundleManager/applicationInfo.d.ts，涉及字段属性变化。
ApplicationInfo结构体变更，包管理原有bundle/applicationInfo.d.ts字段全部废弃，变更为bundleManager/applicationInfo.d.ts，涉及字段属性变化。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。使用二级模块导出ApplicationInfo时，需要导入@ohos.bundle.bundleManager模块。

**关键的接口/组件变更**<br>
ApplicationInfo结构体发生变化的字段内容如下表所示。其余字段在bundle/applicationInfo.d.ts中废弃后，在新的[bundleManager/applicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)中均有对应值。没有对应字段，则表明该字段已经在API9上废弃。

| 废弃 | API9新增或变更 | 类型 |
| --- | --- | --- |
| systemApp | 无 | boolean  |
| labelId |  无 | string |
| labelIndex | labelId | number |
| iconId | 无 | string |
| iconIndex | iconId | number |
| supportedModes | 无 | number  |
| moduleSourceDirs | 无 | Array\<string> |
| moduleInfos | 无 | Array\<ModuleInfo> |
| metaData | 无 | Map\<string,Array\<CustomizeData>> |
| entityType | 无 | string |
| fingerprint | 无 | string |


**适配指导**<br>
导入包管理查询的模块，使用API9 version的ApplicationInfo结构体。


## cl.bundlemanager.6 HapModuleInfo结构体字段变更，包管理原有bundle/hapModuleInfo.d.ts 和 moduleInfo.d.ts字段全部废弃，变更为bundleManager/hapModuleInfo.d.ts，涉及字段属性变化。

HapModuleInfo结构体字段变更，包管理原有bundle/hapModuleInfo.d.ts 和 moduleInfo.d.ts字段全部废弃，变更为[bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)，涉及字段属性变化。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。使用二级模块导出HapModuleInfo时，需要导入@ohos.bundle.bundleManager模块。

**关键的接口/组件变更**<br>
HapModuleInfo结构体发生变化的字段内容如下表所示。其余字段在bundle/hapModuleInfo.d.ts中废弃后，在新的bundleManager/hapModuleInfo.d.ts中均有对应值。
| 废弃 | API9新增或变更 | 类型 |
| --- | --- | --- |
| abilityInfo |  abilitiesInfo | Array<AbilityInfo> |
| 无 | moduleSourceDir | string |
| backgroundImg | 无  | string |
| supportedModes | 无  | string |
| reqCapabilities | 无  | Array\<string> |
| moduleName | 无 | string |
| mainAbilityName | 无 | string |
| extensionAbilityInfo | extensionAbilitiesInfo | Array\<ExtensionAbilityInfo> |

**适配指导**<br>
导入包管理查询的模块，使用API9 version的HapModuleInfo结构体。

## cl.bundlemanager.7 ModuleInfo结构体废弃，使用bundleManager/hapModuleInfo.d.ts中的HapModuleInfo代替。

包管理原有bundle/hapModuleInfo.d.ts 和 moduleInfo.d.ts字段全部废弃，变更为[bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)，涉及字段属性变化。
ModuleInfo结构体废弃，使用[bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)中的HapModuleInfo代替。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。ModuleInfo被废弃，使用HapModuleInfo代替。

**关键的接口/组件变更**<br>

ModuleInfo结构体被废弃，使用HapModuleInfo代替。

**适配指导**<br>
使用API9 version的HapModuleInfo结构体。

## cl.bundlemanager.8 AbilityInfo结构体字段变更，原bundle/abilityInfo.d.ts全部废弃，变更为bundleManager/abilityInfo.d.ts，涉及到字段属性变化

AbilityInfo结构体字段变更，原bundle/abilityInfo.d.ts全部废弃，变更为bundleManager/abilityInfo.d.ts，涉及到字段属性变化

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。

**关键的接口/组件变更**<br>

包管理AbilityInfo结构体字段变更如下表所示，未在表格中列出的表明废弃后均在新的AbilityInfo中存在，标记为无的表明该字段已在API9废弃，在新的AbilityInfo中不存在。

|废弃 | API9新增或变更 | 类型|
|----|  --| --|
| launchMode | launchType | number |
| supportWindowMode | supportWindowModes | Array\<number> |
| targetAbility | 无 | string |
| backgroundModes | 无 | number |
| formEnabled | 无 |  boolean |
| subType | 无 | AbilitySubType |
|deviceCapabilities |无| Array\<string>|
| metaData        | 无 | Array\<CustomizeData>|
| maxWindowRatio  | 无 | number  |
| minWindowRatio  | 无 | number |
| maxWindowWidth  | 无 | number  |
| minWindowWidth  | 无 | number  |
| maxWindowHeight | 无 | number  |
| minWindowHeight | 无 | number   |
| 无| windowSize | WindowSize |

其中API9新增结构体WindowSize属性如下：

|     属性名      |  类型  |
| :-------------: | :----: |
| maxWindowRatio  | number |
| minWindowRatio  | number |
| maxWindowWidth  | number |
| minWindowWidth  | number |
| maxWindowHeight | number |
| minWindowHeight | number |

**适配指导**<br>
使用API9 version的AbilityInfo结构体。

## cl.bundlemanager.9 BundleFlag变更，变更为@ohos.bundle.bundleManager中的BundleFlag、ApplicationFlag和AbilityFlag，涉及到接口入参修改。

BundleFlag变更，变更为@ohos.bundle.bundleManager中的BundleFlag、ApplicationFlag和AbilityFlag，根据新接口的入参，传入不同类型的flag。

**变更影响**<br>

BundleFlag变更，变更为@ohos.bundle.bundleManager中的BundleFlag、ApplicationFlag和AbilityFlag，根据新接口的入参描述，传入不同类型的flag。直接使用API Version 9之前的BundleFlag，可能查询失败。


**关键的接口/组件变更**<br>
原@ohos.bundle中的BundleFlag全部废弃，使用新的@ohos.bundle.bundleManager中的BundleFlag、ApplicationFlag和AbilityFlag代替。

API9的BundleFlag 如下表所示：

|  BundleFlag |值 |描述|
|---|---| --|
|GET_BUNDLE_INFO_DEFAULT|0x00000000|获取默认BundleInfo，获取到的BundleInfo不包含signatureInfo, hapModuleInfo, appInfo, reqPermissionDetails和permissionGrantStates|
|GET_BUNDLE_INFO_WITH_APPLICATION| 0x00000001|额外获取appInfos|
|GET_BUNDLE_INFO_WITH_HAP_MODULE|0x00000002|额外获取hapModulesInfo|
|GET_BUNDLE_INFO_WITH_ABILITY|0x00000004|指定在获取hapModulesInfo的信息中是否包含abilitiesInfo，需要和GET_BUNDLE_INFO_WITH_HAP_MODULE一起使用，不能单独使用。|
|GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY|0x00000008|指定在获取hapModulesInfo的信息中是否包含extensionAbilitiesInfo，需要和GET_BUNDLE_INFO_WITH_HAP_MODULE一起使用，不能单独使用。|
|GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION|0x00000010|额外获取reqPermissionDetails和permissionGrantStates|
|GET_BUNDLE_INFO_WITH_METADATA|0x00000020|控制返回的ApplicationInfo, AbilityInfo和ExtensionAbilityInfo中是否包含metadata信息，不能单独使用|
|GET_BUNDLE_INFO_WITH_DISABLE|0x00000040|可获取被禁用application的BundleInfo和获取abilitiesInfo中disabled ability信息|
|GET_BUNDLE_INFO_WITH_SIGNATURE_INFO|0x00000080|额外获取signatureInfo|

API9的 ApplicationFlag 如下表所示
：
|  ApplicationFlag  |值 |描述|
|---|---| --|
|GET_APPLICATION_INFO_DEFAULT|0x00000000|获取默认ApplicationInfo，获取的ApplicationInfo不包含permissions和matedata|
|GET_APPLICATION_INFO_WITH_PERMISSION|0x00000001|额外获取permissions|
|GET_APPLICATION_INFO_WITH_METADATA|0x00000002|额外获取metadata|
|GET_APPLICATION_INFO_WITH_DISABLE|0x00000004|获取disabled的application信息|


API9的 AbilityFlag 如下表所示：
|  AbilityFlag |值 |描述|
|---|---|---|
|GET_ABILITY_INFO_DEFAULT|  0x00000000|用于获取默认的AbilityInfo信息，不包含permission、metadata和 disabled 的 AbilityInfo|
|GET_ABILITY_INFO_WITH_PERMISSION | 0x00000001|用于获取带有permission信息的AbilityInfo|
|GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002|用于获取带有ApplicationInfo结构体信息的AbilityInfo|
| GET_ABILITY_INFO_WITH_METADATA | 0x00000004|用于获取带有metadata信息的AbilityInfo|
|GET_ABILITY_INFO_WITH_DISABLE | 0x00000008|用于获取所有的AbilityInfo，包含被禁用的Ability|
|GET_ABILITY_INFO_ONLY_SYSTEM_APP | 0x00000010| 用于系统应用获取AbilityInfo|

**适配指导**<br>
根据调用的@ohos.bundle.bundleManager.d.ts中的接口，使用不同的flag类型。

## cl.bundlemanager.10 默认应用模块ApplicationType枚举值变更
@ohos.bundle.defaultApp模块，相关接口功能未发生变化，使用方式未发生变化。只有ApplicationType的枚举值有变化。

**变更影响**<br>
相关接口版本为API version 9，对API9之前的应用无影响。API9应用需要适配新枚举值。

**关键的接口/组件变更**<br>
ApplicationType的枚举值变化如下：
|  ApplicationType   |      API9新增或变更       | API8及以前 |
| :-----: | :-------------: | :--------: |
| BROWSER |  "Web Browser"  | "BROWSER"  |
|  IMAGE  | "Image Gallery" |  "IMAGE"   |
|  AUDIO  | "Audio Player"  |  "AUDIO"   |
|  VIDEO  | "Video Player"  |  "VIDEO"   |
|   PDF   |  "PDF Viewer"   |   "PDF"    |
|  WORD   |  "Word Viewer"  |   "WORD"   |
|  EXCEL  | "Excel Viewer"  |  "EXCEL"   |
|   PPT   |  "PPT Viewer"   |   "PPT"    |

**适配指导**<br>
导入默认应用的模块，调用相关的接口。
```
import defaultApp form '@ohos.bundle.defaultAppManager'
```

## cl.bundlemanager.11 分布式包管理模块变更，原@ohos.distributedBundle.d.ts接口全部废弃，变更为@ohos.bundle.distributedBundle.d.ts，涉及接口变更。
API异常错误整改，分布式包管理模块变更，原@ohos.distributedBundle.d.ts接口全部废弃，变更为[@ohos.bundle.distributedBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.distributedBundleManager.d.ts)。涉及接口getRemoteAbilityInfos，变更为getRemoteAbilityInfo。相关结构体RemoteAbilityInfo的二级模块导出功能也需要导入新模块才可以继续使用。

**变更影响**<br>
对API version 9之前的应用无影响。分布式模块和getRemoteAbilityInfos名称变更，会导致原有API version 9应用使用新的sdk编译失败。

**关键的接口/组件变更**<br>
@ohos.distributedBundle.d.ts中接口全部废弃，新增@ohos.bundle.distributedBundle.d.ts，其中部分接口保持与原接口功能一致。新接口全部支持异常处理。接口变更如下：
| 废弃 | API9新增或变更 | systemapi |
|----| ----| -- |
| getRemoteAbilityInfos | getRemoteAbilityInfo | 是|

**适配指导**<br>
需要导入新的分布式模块：
```
import distributedBundle form '@ohos.bundle.distributedBundle'
```

## cl.bundlemanager.12 免安装模块和接口变更，从@ohos.bundle.d.ts移到@ohos.bundle.freeInstall.d.ts，涉及模块和接口变更
API支持异常处理整改，免安装模块变更，从@ohos.bundle.d.ts移到@ohos.bundle.freeInstall.d.ts，涉及模块和接口变更，系统能力为SystemCapability.BundleManager.BundleFramework.FreeInstall。
1. 原导入的@ohos.bundle模块需要变更为@ohos.bundle.freeInstall。
2. setModuleUpgradeFlag变更为setHapModuleUpgradeFlag。
3. isModuleRemovable变更为isHapModuleRemovable。
4. getDispatcher变更为getDispatchInfo

**变更影响**<br>
对API version 9之前的应用无影响，使用API9接口的应用会编译失败。

**关键的接口/组件变更**<br>
免安装相关接口变更如下表所示。未在表中列出的表示接口名称和使用方法未发生变更，仅修改了模块名称。
|废弃  | API9新增或变更 | systemapi |
|----|----|----|
|setModuleUpgradeFlag|setHapModuleUpgradeFlag| 是 |
|isModuleRemovable|isHapModuleRemovable| 是 |
|getDispatcher|getDispatchInfo| 是 |

**适配指导**<br>
使用免安装相关接口，需要导入新的模块，按照接口前后对应关系进行修改。
```
import freeInstall from '@ohos.bundle.freeInstall'
```

## cl.bundlemanager.13 免安装相关结构体DisPatchInfo、AbilityFormInfo、ModuleDistroInfo和ModuleConfigInfo发生字段变更
免安装相关结构体DisPatchInfo、AbilityFormInfo、ModuleDistroInfo和ModuleConfigInfo发生字段变更：
1. DispatchInfo中字段dispatchAPI名称修改为[dispatchAPIVersion](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/DispatchInfo.d.ts)，属性不变，为string。表示免安装接口的版本信息，含义不变。
2. AbilityFormInfo结构体字段属性变更，原有字段supportDimensions属性由Array\<number>修改为Array\<string>;
3. AbilityFormInfo结构体字段属性变更，原有字段defaultDimension属性由number修改为string。
4. ModuleDistroInfo结构体废弃mainAbility字段，移至ModuleConfigInfo结构体中。
5. ModuleConfigInfo结构体新增mainAbility字段。

**变更影响**<br>
对API version 9之前的应用无影响。结构体名称字段属性变更，会导致原有API9应用使用新的sdk编译失败。

**关键的接口/组件变更**<br>
1. DispatchInfo

| 废弃 | API9新增或变更 | 属性|
|---|----|---|
| dispatchAPI | dispatchAPIVersion | string |

2. AbilityFormInfo

| 字段 | API9属性 | 原属性 |
|---|----|---|
| supportDimensions | Array\<string> | Array\<number> |
| defaultDimension | string| number |

3. ModuleDistroInfo

| 字段 | API9新增或变更 | 属性 |
|---|----|---|
| mainAbility | 无| string |

4. MooduleConfigInfo

| 字段 | API9新增或变更 | 属性 |
|---|----|---|
| 无 | mainAbility| string |


**适配指导**<br>
使用免安装相关接口，需要导入新的模块，按照结构体前后对应关系进行修改。
```
import freeInstall from '@ohos.bundle.freeInstall'
```

## cl.bundlemanager.14 结构体GrantStatus变更为PermissionGrantState
结构体GrantStatus变更为PermissionGrantState，枚举类型和值不变。

**变更影响**<br>
对API version 9之前的应用无影响。结构体名称字变更，会导致原有API9应用使用新的sdk编译失败。

**关键的接口/组件变更**<br>
表示授权状态的GrantStatus结构体变更为@ohos.bundle.bundleManager.d.ts中的PermissionGrantState。
| 枚举名 | 枚举值 |
| ---| ---|
|  PERMISSION_DENIED | -1 |
| PERMISSION_GRANTED | 0 |

**适配指导**<br>
需要导入新的模块，修改结构体名称为PermissionGrantState。
```
import bundle form '@ohos.bundle.bundleManager'
```
## cl.bundlemanager.15 包管理ShortcutInfo结构体字段变更
包管理ShortcutInfo结构体字段变更，原有bundle/shortcutInfo.d.ts字段全部废弃，变更为[bundleManager/shortcutInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ShortcutInfo.d.ts)。ShortcutInfo和ShortWant结构体全部为systemapi。

**变更影响**<br>
对API version 9之前的应用无影响。结构体名称字段属性变更，会导致原有API9应用使用新的sdk编译失败。

**关键的接口/组件变更**<br>
涉及到ShortcutInfo和ShortcutWant结构体。如果需要使用二级模块导出功能，需要导入新模块@ohos.bundle.launcherBundleManager。
ShortcutInfo结构体变化如下表，未在表格中列出的表明字段在API9上还存在。
| 废弃 | API9新增或变更 | 属性  |
| ---| ---| ---|
| disableMessage | 无 | string |
| isStatic | 无 | boolean |
| isHomeShortcut | 无 | boolean |
| isEnabled | 无 | boolean |
| disableMessage | 无 | boolean |

ShortcutWant结构体如下表，未在表格中列出的表明字段在API9上还存在。
| 废弃 | API9新增或变更 | 属性  |
| ---| ---| ---|
| targetClass | targetAbility | string |

**适配指导**<br>
使用免安装相关接口，需要导入新的模块，按照结构体前后对应关系进行修改。
```
import launcherBundleManager form '@ohos.bundle.launcherBundleManager'
```

## cl.bundlemanager.16 包管理getBundleInstaller接口变更，从@ohos.bundle.d.ts移至@ohos.bundle.installer.d.ts
包管理getBundleInstaller接口变更，从@ohos.bundle.d.ts移至[@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts)
.，系统能力为SystemCapability.BundleManager.BundleFramework.Core。

**变更影响**<br>
对API version 9之前的应用无影响。使用API9的应用需要适配新模块和新接口。

**关键的接口/组件变更**<br>
1. getBundleInstaller，导入模块由@ohos.bundle变更为@ohos.bundle.installer。

**适配指导**<br>
导入新的包管理安装模块，调用getBundleInstaller
```
import installer form '@ohos.bundle.installer'
```

## cl.bundlemanager.17 包管理安装接口变更，从bundle/bundleInstaller.d.ts移至@ohos.bundle.installer.d.ts
包管理安装接口变更，从bundle/bundleInstaller.d.ts移至[@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts),系统能力为SystemCapability.BundleManager.BundleFramework.Core。

**变更影响**<br>
对API version 9之前的应用无影响。使用API9的应用需要适配新模块和新接口。

**关键的接口/组件变更**<br>
1. install/uninstall/recover接口增加了异常处理能力，接口名称和入参均未发生变化，仅修改了模块名称。
2. HashParam结构体新增字段

| API9新增 | 属性 |
|---|---|
| moduleName | string |
| hashValue  | string |

3. InstallParam结构体变更如下：

| API9新增 | 属性 |
|---|--|
| userId | number |
| installFlag | number |
| isKeepData | boolean |
| hashParams | Array\<HashParam> |
| crowdtestDeadline | number |

4. InstallStatus，结构体已废弃。

**适配指导**<br>
导入新的包管理安装模块，调用getBundleInstaller
```
import installer form '@ohos.bundle.installer'
```

## cl.bundlemanager.18 包管理安装功能变更
包管理安装规格变更，增加了对应用deviceType配置和设备类型的匹配校验，如果两者匹配失败，则安装失败。

**变更影响**<br>
影响在此前版本已开发的应用，应用需要适配才能在新版本镜像安装成功。

**关键的接口/组件变更**<br>
不涉及

**适配指导**<br>
提供指导，在应用配置文件config.json或者module.json的deviceType配置对应的设备类型。
```
{
    "module": {
        "name": "entry",
        "type": "entry",
        // ...
        "deviceTypes":[
            // 该示例配置了default和tablet，则支持在default和tablet上进行安装。
            "default",
            "tablet"
        ],
        // ...
    }
```
## cl.bundlemanager.19 包管理innerBundleManger模块接口变更，@ohos.bundle.innerBundleManger.d.ts接口全部废弃，移至@ohos.bundle.launcherBundleManager.d.ts。
innerBundleManager相关接口功能未发生变化，使用方式有变化。需要导入[@ohos.bundle.launcherBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.launcherBundleManager.d.ts)模块来使用innerBundleManager相关的接口，系统能力为SystemCapability.BundleManager.BundleFramework.Core。

**变更影响**<br>
相关接口版本为API version 9，对api9之前的应用无影响。使用了innerBundleManager接口能力的应用需要适配新的模块和接口。

**关键的接口/组件变更**<br>
以下接口功能和入参未发生变化，增加了API异常处理。使用二级模块导出ShortcutInfo和ShortcutWant时，需要导入新模块@ohos.bundle.launcherBundleManager。on/off接口从@ohos.bundle.innerBundleManger.d.ts中废弃，移至@ohos.bundle.bundleMonitor.d.ts中。
1. getLauncherAbilityInfos<br>
2. getAllLauncherAbilityInfos<br>
3. getShortcutInfos

**适配指导**<br>
需要导入新模块@ohos.bundle.launcherBundleManage
```
import launcherBundleManager form '@ohos.bundle.launcherBundleManage'
```

## cl.bundlemanager.20 innerBundleManagr模块变更，on, off接口从@ohos.bundle.innerBundleManager模块移到@ohos.bundle.bundleMonitor.d.ts模块
innerBundleManager相关接口功能未发生变化，使用方式有变化。需要导入[@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts)模块来使用innerBundleManager相关的接口，均为systemapi。系统能力为SystemCapability.BundleManager.BundleFramework.Core。

**变更影响**<br>
相关接口版本为API version 9，对API9之前的应用无影响。使用了innerBundleManager接口能力的应用需要适配新的模块和接口。

**关键的接口/组件变更**<br>
on/off变更至@ohos.bundle.bundleMonitor.d.ts，使用接口入参与老接口不同。API9函数原型为：
```
function on(type: BundleChangedEvent, callback: Callback<BundleChangedInfo>): void;
function off(type: BundleChangedEvent, callback?: Callback<BundleChangedInfo>): void;
```
其中BundleChangedEvent为：
```
type BundleChangedEvent = 'add' | 'update' | 'remove';
```
回调函数BundleChangedInfo为：
```
  interface BundleChangedInfo {
    readonly bundleName: string;
    readonly userId: number;
  }
```
由调用方获取到BundleChangedInfo后，继续执行相关操作（即老接口中BundleStatusCallback中的add、update和remove等函数)。

**适配指导**<br>
导入bundleMonitor的模块，调用相关接口。
```
import bundleMonitor form '@ohos.bundle.bundleMonitor'
``` 

## cl.bundlemanager.21 包管理bundleStatusCallback.d.ts接口全部废弃，移至@ohos.bundle.bundleMonitor.d.ts中。
包管理bundleStatusCallback.d.ts接口全部废弃，移至[@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts)中。原有BundleStatusCallback中的add、update和remove全部废弃，变更为BundleChangedEvent，为systemapi。系统能力为SystemCapability.BundleManager.BundleFramework.Core。

**变更影响**<br>
相关接口版本为API version 9，对API9之前的应用无影响。使用了BundleStatusCallback接口能力的应用需要适配新的模块和接口。

**关键的接口/组件变更**<br>.
以下接口全部废弃，在@ohos.bundle.bundleMonitor.d.ts中新增BundleChangedEvent。
1. add
2. update
3. remove

**适配指导**<br>
导入bundleMonitor的模块，调用相关接口。与之前的BundleStatusCallback方式不同，BundleStatusCallback是将add、update和remove方法传入on/off接口，API9的BundleMonitor接口是通过on/off接口将BundleChangedInfo通过回调函数返回出来给调用方使用。
```
import bundleMonitor form '@ohos.bundle.bundleMonitor'
``` 

## cl.bundlemanager.22 包管理Zlib模块接口变更，@ohos.zlib.d.ts中接口涉及废弃和变更。
包管理Zlib模块接口变更，[@ohos.zlib.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.zlib.d.ts)中接口涉及废弃和变更。系统能力为SystemCapability.BundleManager.Zlib。

**变更影响**<br>
相关接口版本为API version 9，对API9之前的应用无影响。使用了API9的应用需要适配新的模块和接口。

**关键的接口/组件变更**<br>
@ohos.zlib.d.ts中涉及到变更的接口如下表所示，新增API9接口使用方法与之前相同，支持API异常处理。
| 废弃 | API9新增或变更 | systemapi|
|---|----|---|
| zipFile | compressFile | 是 |
| unzipFile | decompressFile | 是 |
| ErrorCode | 无 | 是 |

**适配指导**<br>
导入模块未发生变化，直接使用新接口，适配异常处理。
```
import zlib form '@ohos.zlib'
```
