# Bundle Manager Subsystem ChangeLog

## cl.bundlemanager.1 Bundle Manager API Changes
The bundle manager APIs use service logic return values to indicate the error information, which does not comply with the API error code specifications of OpenHarmony. APIs in API version 8 and earlier are deprecated. Replace them with APIs in API version 9 instead.

**Change Impacts**

The application developed based on the SDK versions of OpenHarmony 3.2.8.2 and later needs to adapt the modules and APIs (version 9) and their method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The new APIs are classified by module. The original **d.ts** file is divided into multiple ones. You can import the **d.ts** files as required. The newly added APIs support unified error code handling specifications and function the same as the original APIs. APIs whose functions are changed or added are listed separately.

For adaptation to the unified API exception handling mode, bundle manager APIs (version 8 and earlier) are deprecated (original APIs in the following table) and corresponding new APIs (version 9) in the following table are added.

| Original API (Deprecated)                      | New API (Added)                                              |
| ------------------------------------ | ------------------------------------------------------------ |
| @ohos.bundle.d.ts                    | [@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts) |
| @ohos.bundle.d.ts                    | [@ohos.bundle.freeInstall.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.freeInstall.d.ts) |
| @ohos.bundle.d.ts                    | [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts) |
| @ohos.bundle.innerBundleManager.d.ts | [@ohos.bundle.launcherBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.launcherBundleManager.d.ts) |
| @ohos.bundle.innerBundleManager.d.ts | [@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts) |
| @ohos.bundle.defaultAppManager.d.ts  | [@ohos.bundle.defaultAppManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.defaultAppManager.d.ts) |
| @ohos.distributedBundle.d.ts         | [@ohos.bundle.distributedBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.distributedBundleManager.d.ts) |
| N/A                                  | [@ohos.bundle.appControl.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.appControl.d.ts) |
| @system.package.d.ts                 | N/A                                                          |

**Adaptation Guide**
1. Call the bundle manager query API.
```
import bundle form '@ohos.bundle.bundleManager'
```
2. Call the bundle manager installation and uninstallation API.
```
import installer form '@ohos.bundle.installer'
```
3. Call the bundle manager installation-free API.
```
import freeInstall form '@ohos.bundle.freeInstall'
```
4. Call the bundle manager launcher APIs.
```
import launcherBundleManager form '@ohos.bundle.launcherBundleManager'
import bundleMonitor form '@ohos.bundle.bundleMonitor'
```
6. Call the bundle manager API for the default application.
```
import defaultAppManager form '@ohos.bundle.defaultAppManager'
```
7. Call the distributed bundle manager API.
```
import distributedBundle form '@ohos.bundle.distributedBundle'
```
In addition, exception handling is needed. For details, see the API reference for the new APIs.

## cl.bundlemanager.1 Bundle Manager API Structure Changes
The bundle manager APIs use service logic return values to indicate the error information, which does not comply with the API error code specifications of OpenHarmony. The structures of APIs in API version 8 and earlier are deprecated. Use the structures of APIs in API version 9 instead.

**Change Impacts**

The application developed based on the SDK versions of OpenHarmony 3.2.8.2 and later needs to adapt new structures. Otherwise, the original service logic will be affected. The export function of original level-2 modules will also be deprecated. Instead, the level-2 modules' export function of new APIs will be used, and new level-1 d.ts modules are imported.

**Key API/Component Changes**

The structures of APIs in API version 8 and earlier are sorted out and deprecated, and those of new APIs in API version 9 are added. The following table lists the comparison before and after the change. Some structures are combined. For example, replace **moduleInfo.d.ts** with **hapModuleInfo.d.ts** and **customizeData.d.ts** with **metadata.d.ts**. The structures' functions are the same as those of the original ones. Structures whose attributes are changed or added are listed separately.
| Original Structure (Deprecated)                | New Structure (Added)                                            |
| -------------------------------- | ------------------------------------------------------------ |
| bundle/abilityInfo.d.ts          | [bundleManager/AbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts) |
| bundle/applicationInfo.d.ts      | [bundleManager/ApplicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) |
| bundle/bundleInfo.d.ts           | [bundleManager/BundleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundleInfo.d.ts) |
| bundle/bundleInstaller.d.ts      | [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts) |
| bundle/bundleStatusCallback.d.ts | [@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts) |
| bundle/customizeData.d.ts        | [bundleManager/Metadata.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/Metadata.d.ts) |
| bundle/dispatchInfo.d.ts         | [bundleManager/DispatchInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/DispatchInfo.d.ts) |
| bundle/elementName.d.ts          | [bundleManager/ElementName.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ElementName.d.ts) |
| bundle/extensionAbilityInfo.d.ts | [bundleManager/ExtensionAbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts) |
| bundle/hapModuleInfo.d.ts        | [bundleManager/HapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) |
| bundle/launcherAbilityInfo.d.ts  | [bundleManager/LauncherAbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/LauncherAbilityInfo.d.ts) |
| bundle/metadata.d.ts             | [bundleManager/Metadata.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/Metadata.d.ts) |
| bundle/moduleInfo.d.ts           | [bundleManager/HapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts) |
| bundle/PermissionDef.d.ts        | [bundleManager/PermissionDef.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/PermissionDef.d.ts) |
| bundle/remoteAbilityInfo.d.ts    | [bundleManager/RemoteAbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/RemoteAbilityInfo.d.ts) |
| bundle/shortcutInfo.d.ts         | [bundleManager/ShortcutInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ShortcutInfo.d.ts) |

**Adaptation Guide**
1. Replace the code of original structures with the code of new ones.
2. Deprecate the export function of original level-2 modules. Instead, use the level-2 modules' export function of new APIs, and import new level-1 d.ts modules.

## cl.bundlemanager.3 Bundle Manager Query API Changes

Bundle manager query APIs are changed as follows: APIs of version 8 and earlier in **@ohos.bundle** are deprecated, and APIs of version 9 in **@ohos.bundle** are changed to **@ohos.bundle.bundleManager**, **@ohos.bundle.freeInstall**, and **@ohos.bundle.installer**. Most deprecated APIs are added to **@ohos.bundle.bundleManager** and changed to system APIs, and the exception handling capability is added.

API call mode: APIs are now used by the **@ohos.bundle.bundleManager**, **@ohos.bundle.freeInstall**, and **@ohos.bundle.installer** modules, instead of the **@ohos.bundle** module.

The system capability of the **@ohos.bundle.bundleManager** and **@ohos.bundle.installer** modules is **SystemCapability.BundleManager.BundleFramework.Core**, and that of **@ohos.bundle.freeInstall** is **SystemCapability.BundleManager.BundleFramework.FreeInstall**.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs. APIs of version 9 in **@ohos.bundle** are moved to the new **@ohos.bundle.bundleManager.d.ts**, **@ohos.bundle.freeInstall**, and **@ohos.bundle.installer** files.

**Key API/Component Changes**

The following table lists the deprecated and changed APIs involved in **@ohos.bundle.d.ts**. The APIs not listed in the table have no change in API names and input parameters, and they have new exception handling and import modules. The APIs can be directly used after being imported to **@ohos.bundle.bundleManager.d.ts**, **@ohos.bundle.freeInstall**, and **@ohos.bundle.installer**. The APIs listed in the table are changed in API version 9, and those marked with "N/A" are deprecated in API version 9.

| Original API (Deprecated)              | New API (Changed or Added)        | System API| New File Name                       |
| ---------------------------- | ---------------------------- | --------- | ------------------------------- |
| BundleFlag                   | BundleFlag                   | No       | @ohos.bundle.bundleManager.d.ts |
| N/A                          | ApplicationFlag              | Yes       | @ohos.bundle.bundleManager.d.ts |
| N/A                          | AbilityFlag                  | Yes       | @ohos.bundle.bundleManager.d.ts |
| ExtensionFlag                | ExtensionAbilityFlag         | Yes       | @ohos.bundle.bundleManager.d.ts |
| ColorMode                    | N/A                          | No       | N/A                             |
| GrantStatus                  | PermissionGrantState         | No       | @ohos.bundle.bundleManager.d.ts |
| AbilityType                  | AbilityType                  | No       | @ohos.bundle.bundleManager.d.ts |
| AbilitySubType               | N/A                          | No       | N/A                             |
| DisplayOrientation           | DisplayOrientation           | No       | @ohos.bundle.bundleManager.d.ts |
| LaunchMode                   | LaunchType                   | No       | @ohos.bundle.bundleManager.d.ts |
| ExtensionAbilityType         | ExtensionAbilityType         | Yes       | @ohos.bundle.bundleManager.d.ts |
| BundleOptions                | N/A                          | No       | N/A                             |
| InstallErrorCode             | N/A                          | No       | N/A                             |
| UpgradeFlag                  | UpgradeFlag                  | Yes       | @ohos.bundle.freeInstall.d.ts   |
| SupportWindowMode            | SupportWindowMode            | No       | @ohos.bundle.bundleManager.d.ts |
| getBundleInfo                | getBundleInfo                | Yes       | @ohos.bundle.bundleManager.d.ts |
| getBundleInstaller           | getBundleInstaller           | Yes       | @ohos.bundle.installer.d.ts     |
| getAbilityInfo               | queryAbilityInfo             | Yes       | @ohos.bundle.bundleManager.d.ts |
| getApplicationInfo           | getApplicationInfo           | Yes       | @ohos.bundle.bundleManager.d.ts |
| queryAbilityByWant           | queryAbilityInfo             | Yes       | @ohos.bundle.bundleManager.d.ts |
| getAllBundleInfo             | getAllBundleInfo             | Yes       | @ohos.bundle.bundleManager.d.ts |
| getAllApplicationInfo        | getAllApplicationInfo        | Yes       | @ohos.bundle.bundleManager.d.ts |
| getNameForUid                | getBundleNameByUid           | Yes       | @ohos.bundle.bundleManager.d.ts |
| getBundleArchiveInfo         | getBundleArchiveInfo         | Yes       | @ohos.bundle.bundleManager.d.ts |
| getLaunchWantForBundle       | getLaunchWantForBundle       | Yes       | @ohos.bundle.bundleManager.d.ts |
| cleanBundleCacheFiles        | cleanBundleCacheFiles        | Yes       | @ohos.bundle.bundleManager.d.ts |
| setApplicationEnabled        | setApplicationEnabled        | Yes       | @ohos.bundle.bundleManager.d.ts |
| setAbilityEnabled            | setAbilityEnabled            | Yes       | @ohos.bundle.bundleManager.d.ts |
| queryExtensionAbilityInfos   | queryExtensionAbilityInfo    | Yes       | @ohos.bundle.bundleManager.d.ts |
| getPermissionDef             | getPermissionDef             | Yes       | @ohos.bundle.bundleManager.d.ts |
| getAbilityLabel              | getAbilityLabel              | Yes       | @ohos.bundle.bundleManager.d.ts |
| getAbilityIcon               | getAbilityIcon               | Yes       | @ohos.bundle.bundleManager.d.ts |
| isAbilityEnabled             | isAbilityEnabled             | Yes       | @ohos.bundle.bundleManager.d.ts |
| isApplicationEnabled         | isApplicationEnabled         | Yes       | @ohos.bundle.bundleManager.d.ts |
| setModuleUpgradeFlag         | setHapModuleUpgradeFlag      | Yes       | @ohos.bundle.freeInstall.d.ts   |
| isModuleRemovable            | isHapModuleRemovable         | Yes       | @ohos.bundle.freeInstall.d.ts   |
| getBundlePackInfo            | getBundlePackInfo            | Yes       | @ohos.bundle.freeInstall.d.ts   |
| getDispatcherVersion         | getDispatchInfo              | Yes       | @ohos.bundle.freeInstall.d.ts   |
| getProfileByAbility          | getProfileByAbility          | No       | @ohos.bundle.bundleManager.d.ts |
| getProfileByExtensionAbility | getProfileByExtensionAbility | No       | @ohos.bundle.bundleManager.d.ts |
| setDisposedStatus            | setDisposedStatus            | Yes       | @ohos.bundle.appControl.d.ts    |
| getDisposedStatus            | getDisposedStatus            | Yes       | @ohos.bundle.appControl.d.ts    |
| N/A                          | deleteDisposedStatus         | Yes       | @ohos.bundle.appControl.d.ts    |
| getBundleInfoSync            | getBundleInfoSync            | Yes       | @ohos.bundle.bundleManager.d.ts |
| getApplicationInfoSync       | getApplicationInfoSync       | Yes       | @ohos.bundle.bundleManager.d.ts |
| N/A                          | getBundleInfoForSelf         | No       | @ohos.bundle.bundleManager.d.ts |

**Adaptation Guide**

Replace the original APIs with new ones of version 9 and import related modules.

Old import module:
```
import bundle form '@ohos.bundle'
```
New import module:
```
import bundle form '@ohos.bundle.bundleManager'
import freeInstall form '@ohos.bundle.freeInstall'
import installer form '@ohos.bundle.installer'
import appControl form '@ohos.bundle.appControl'
```

## cl.bundlemanager.4 BundleInfo Structure Changes

All **bundle/bundleInfo.d.ts** fields in the bundle manager are deprecated. [bundle/bundleInfo.d.ts]((https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundle/bundleInfo.d.ts)) is changed to [bundleManager/BundleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundleInfo.d.ts), involving field type changes.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs. When a level-2 module is used to export **BundleInfo**, the **@ohos.bundle.bundleManager** module needs to be imported.

**Key API/Component Changes**

The following table describes the changed fields in the **BundleInfo** structure. After other fields are deprecated in **bundle/bundleInfo.d.ts**, they have corresponding values in the new **[bundleManager/BundleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundleInfo.d.ts)**. If corresponding fields do not exist, the fields have been deprecated in API version 9.

| Deprecated               | Added or Changed in API Version 9       | Type                                      |
| --------------------- | --------------------- | ------------------------------------------ |
| type                  | N/A                   | string                                     |
| appId                 | N/A                   | string                                     |
| N/A                   | signatureInfo         | SignatureInfo                              |
| uid                   | N/A                   | number                                     |
| abilityInfos          | N/A                   | Array\<AbilityInfo>                        |
| reqPermissions        | N/A                   | Array<string>                              |
| compatibleVersion     | N/A                   | number                                     |
| isCompressNativeLibs  | N/A                   | boolean                                    |
| entryModuleName       | N/A                   | string                                     |
| cpuAbi                | N/A                   | string                                     |
| isSilentInstallation  | N/A                   | string                                     |
| entryInstallationFree | N/A                   | boolean                                    |
| reqPermissionStates   | permissionGrantStates | Array\<bundleManager.PermissionGrantState> |
| extensionAbilityInfo  | N/A                   | Array\<ExtensionAbilityInfo>               |
| hapModuleInfos        | hapModulesInfo        | Array\<HapModuleInfo>                      |

The **SignatureInfo** structure is added to API version 9 as follows.

| Field     | Type  |
| ----------- | ------ |
| appId       | string |
| fingerprint | string |

**Adaptation Guide**

Use the **BundleInfo** structure of API version 9 for modules imported for bundle manager query. The following module needs to be imported when a level-2 module is used for export.

```
import bundle form '@ohos.bundle.bundleManager'
```

## cl.bundlemanager.5 ApplicationInfo Structure Changes
The **ApplicationInfo** structure is changed. The original **bundle/applicationInfo.d.ts** fields in the bundle manager are deprecated, and the file is changed from **bundle/applicationInfo.d.ts** to **bundleManager/ApplicationInfo.d.ts**, involving field type changes.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs. When a level-2 module is used to export **ApplicationInfo**, the **@ohos.bundle.bundleManager** module needs to be imported.

**Key API/Component Changes**

The following table describes the changed fields in the **ApplicationInfo** structure. After other fields are deprecated in **bundle/applicationInfo.d.ts**, they have corresponding values in the new [bundleManager/ApplicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts). If corresponding fields do not exist, the fields have been deprecated in API version 9.

| Deprecated            | Added or Changed in API Version 9| Type                              |
| ---------------- | -------------- | ---------------------------------- |
| systemApp        | N/A            | boolean                            |
| labelId          | N/A            | string                             |
| labelIndex       | labelId        | number                             |
| iconId           | N/A            | string                             |
| iconIndex        | iconId         | number                             |
| supportedModes   | N/A            | number                             |
| moduleSourceDirs | N/A            | Array\<string>                     |
| moduleInfos      | N/A            | Array\<ModuleInfo>                 |
| metaData         | N/A            | Map\<string,Array\<CustomizeData>> |
| entityType       | N/A            | string                             |
| fingerprint      | N/A            | string                             |

**Adaptation Guide**

Use the **ApplicationInfo** structure of API version 9 for modules imported for bundle manager query.


## cl.bundlemanager.6 HapModuleInfo Structure Changes

The **HapModuleInfo** structure is changed. The original **bundle/hapModuleInfo.d.ts** and **moduleInfo.d.ts** fields in the bundle manager are deprecated, and the files are changed to [bundleManager/HapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts), involving field type changes.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs. When a level-2 module is used to export **HapModuleInfo**, the **@ohos.bundle.bundleManager** module needs to be imported.

**Key API/Component Changes**

The following table describes the changed fields in the **HapModuleInfo** structure. After other fields are deprecated in **bundle/hapModuleInfo.d.ts**, they have corresponding values in the new **bundleManager/HapModuleInfo.d.ts** file.

| Deprecated                | Added or Changed in API Version 9        | Type                        |
| -------------------- | ---------------------- | ---------------------------- |
| abilityInfo          | abilitiesInfo          | Array<AbilityInfo>           |
| N/A                  | moduleSourceDir        | string                       |
| backgroundImg        | N/A                    | string                       |
| supportedModes       | N/A                    | string                       |
| reqCapabilities      | N/A                    | Array\<string>               |
| moduleName           | N/A                    | string                       |
| mainAbilityName      | N/A                    | string                       |
| extensionAbilityInfo | extensionAbilitiesInfo | Array\<ExtensionAbilityInfo> |

**Adaptation Guide**

Use the **HapModuleInfo** structure of API version 9 for modules imported for bundle manager query.

## cl.bundlemanager.7 ModuleInfo Structure Changes

The original **bundle/hapModuleInfo.d.ts** and **moduleInfo.d.ts** fields in the bundle manager are deprecated, and the files are changed to [bundleManager/HapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts), involving field changes.

The **ModuleInfo** structure is deprecated and replaced by **HapModuleInfo** in [bundleManager/HapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts).

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs. The **ModuleInfo** structure is deprecated and replaced by **HapModuleInfo**.

**Key API/Component Changes**

The **ModuleInfo** structure is deprecated and replaced by **HapModuleInfo**.

**Adaptation Guide**

Use the **HapModuleInfo** structure of API version 9.

## cl.bundlemanager.8 AbilityInfo Structure Changes

The **AbilityInfo** structure is changed. The original **bundle/abilityInfo.d.ts** file is deprecated and changed to **bundleManager/AbilityInfo.d.ts**, involving field type changes.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new modules and APIs.

**Key API/Component Changes**

The following table lists the field changes in the **AbilityInfo** structure for the bundle manager. Fields that are not listed in the table exist in the new **AbilityInfo** structure after being deprecated. Fields marked with "N/A" have been deprecated in API version 9 and do not exist in the new **AbilityInfo** structure.

| Deprecated              | Added or Changed in API Version 9    | Type                 |
| ------------------ | ------------------ | --------------------- |
| launchMode         | launchType         | number                |
| supportWindowMode  | supportWindowModes | Array\<number>        |
| targetAbility      | N/A                | string                |
| backgroundModes    | N/A                | number                |
| formEnabled        | N/A                | boolean               |
| subType            | N/A                | AbilitySubType        |
| deviceCapabilities | N/A                | Array\<string>        |
| metaData           | N/A                | Array\<CustomizeData> |
| maxWindowRatio     | N/A                | number                |
| minWindowRatio     | N/A                | number                |
| maxWindowWidth     | N/A                | number                |
| minWindowWidth     | N/A                | number                |
| maxWindowHeight    | N/A                | number                |
| minWindowHeight    | N/A                | number                |
| N/A                | windowSize         | WindowSize            |

The fields of the new structure **WindowSize** of API version 9 are as follows.

|     Field     |  Type |
| :-------------: | :----: |
| maxWindowRatio  | number |
| minWindowRatio  | number |
| maxWindowWidth  | number |
| minWindowWidth  | number |
| maxWindowHeight | number |
| minWindowHeight | number |

**Adaptation Guide**

Use the **AbilityInfo** structure of API version 9.

## cl.bundlemanager.9 BundleFlag Changes

**BundleFlag** is changed to **BundleFlag**, **ApplicationFlag**, and **AbilityFlag** in **@ohos.bundle.bundleManager**. Different types of flags are passed based on the input parameters of new APIs.

**Change Impacts**

**BundleFlag** is changed to **BundleFlag**, **ApplicationFlag**, and **AbilityFlag** in **@ohos.bundle.bundleManager**. Different types of flags are passed based on the input parameters of new APIs. If **BundleFlag** of a version earlier than API version 9 is directly used, the query may fail.

**Key API/Component Changes**

**BundleFlag** in the original **@ohos.bundle** is deprecated and replaced by **BundleFlag**, **ApplicationFlag**, and **AbilityFlag** in the new **@ohos.bundle.bundleManager**.

The following table describes **BundleFlag** of API version 9.

| BundleFlag                               | Value        | Description                                                        |
| ----------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_DEFAULT                   | 0x00000000 | Obtains the default **BundleInfo**. The obtained **BundleInfo** does not contain **signatureInfo**, **hapModuleInfo**, **appInfo**, **reqPermissionDetails**, or **permissionGrantStates**.|
| GET_BUNDLE_INFO_WITH_APPLICATION          | 0x00000001 | Obtains **appInfos** with the default **BundleInfo**.                                            |
| GET_BUNDLE_INFO_WITH_HAP_MODULE           | 0x00000002 | Obtains **hapModulesInfo** with the default **BundleInfo**.                                      |
| GET_BUNDLE_INFO_WITH_ABILITY              | 0x00000004 | Indicates whether **abilitiesInfo** is obtained with **hapModulesInfo**. This flag must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE** and cannot be used independently.|
| GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY    | 0x00000008 | Indicates whether **extensionAbilitiesInfo** is obtained with **hapModulesInfo**. This flag must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE** and cannot be used independently.|
| GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION | 0x00000010 | Obtains **reqPermissionDetails** and **permissionGrantStates** with the default **BundleInfo**.         |
| GET_BUNDLE_INFO_WITH_METADATA             | 0x00000020 | Indicates whether the returned **ApplicationInfo**, **AbilityInfo**, and **ExtensionAbilityInfo** contain metadata. This flag cannot be used independently.|
| GET_BUNDLE_INFO_WITH_DISABLE              | 0x00000040 | Obtains **BundleInfo** of a disabled application and disabled ability information in **abilitiesInfo**.|
| GET_BUNDLE_INFO_WITH_SIGNATURE_INFO       | 0x00000080 | Obtains **signatureInfo** with the default **BundleInfo**.                                       |

The following table describes **ApplicationFlag** of API version 9.

| ApplicationFlag                     | Value        | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| GET_APPLICATION_INFO_DEFAULT         | 0x00000000 | Obtains the default **ApplicationInfo**. The obtained **ApplicationInfo** does not contain permission or metadata information.|
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | Obtains **permissions** with the default **ApplicationInfo**.                                         |
| GET_APPLICATION_INFO_WITH_METADATA   | 0x00000002 | Obtains **metadata** with the default **ApplicationInfo**.                                            |
| GET_APPLICATION_INFO_WITH_DISABLE    | 0x00000004 | Obtains disabled application information.                               |


The following table describes **AbilityFlag** of API version 9.
| AbilityFlag                      | Value        | Description                                                        |
| --------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_ABILITY_INFO_DEFAULT          | 0x00000000 | Obtains the default **AbilityInfo**. The obtained **AbilityInfo** does not contain permission, metadata, or disabled ability information.|
| GET_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Obtains **AbilityInfo** with permission information.                     |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Obtains **AbilityInfo** with the **ApplicationInfo** structure.          |
| GET_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Obtains **AbilityInfo** with metadata information.                       |
| GET_ABILITY_INFO_WITH_DISABLE     | 0x00000008 | Obtains all **AbilityInfo**, including disabled abilities.              |
| GET_ABILITY_INFO_ONLY_SYSTEM_APP  | 0x00000010 | Obtains **AbilityInfo** for system applications.                                 |

**Adaptation Guide**

Use various flags according to the called API in **@ohos.bundle.bundleManager.d.ts**.

## cl.bundlemanager.10 ApplicationType Enumerated Value Changes in the Default Application Module
For the **@ohos.bundle.defaultApp** module, both API functions and usage remain unchanged, but only the enumerated values of **ApplicationType** are changed.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt new enumerated values.

**Key API/Component Changes**

The enumerated values of **ApplicationType** are changed as follows.

| ApplicationType| Added or Changed in API Version 9 | API Version 8 and Earlier|
| :-------------: | :-------------: | :--------: |
|     BROWSER     |  "Web Browser"  | "BROWSER"  |
|      IMAGE      | "Image Gallery" |  "IMAGE"   |
|      AUDIO      | "Audio Player"  |  "AUDIO"   |
|      VIDEO      | "Video Player"  |  "VIDEO"   |
|       PDF       |  "PDF Viewer"   |   "PDF"    |
|      WORD       |  "Word Viewer"  |   "WORD"   |
|      EXCEL      | "Excel Viewer"  |  "EXCEL"   |
|       PPT       |  "PPT Viewer"   |   "PPT"    |

**Adaptation Guide**

Import the default application module and call related APIs.

```
import defaultApp form '@ohos.bundle.defaultAppManager'
```

## cl.bundlemanager.11 Distributed Bundle Manager Changes
API exception handling is rectified. The distributed bundle manager module is changed. The original **@ohos.distributedBundle.d.ts** APIs are deprecated, and the **@ohos.distributedBundle.d.ts** file is changed to [@ohos.bundle.distributedBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.distributedBundleManager.d.ts). The **getRemoteAbilityInfos** API is changed to **getRemoteAbilityInfo**. The export function of a level-2 module in the **RemoteAbilityInfo** structure can be used only after a new module is imported.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. The names of the distributed module and the **getRemoteAbilityInfos** API are changed. As a result, applications using APIs of version 9 may fail to be compiled using the new SDK.

**Key API/Component Changes**

All APIs in **@ohos.distributedBundle.d.ts** are deprecated. The **@ohos.bundle.distributedBundleManager.d.ts** file is added. The functions of some APIs are the same as those of the original ones. New APIs support exception handling. The API changes are as follows.

| Deprecated                 | Added or Changed in API Version 9      | System API|
| --------------------- | -------------------- | --------- |
| getRemoteAbilityInfos | getRemoteAbilityInfo | Yes       |

**Adaptation Guide**

Import a new distributed module.

```
import distributedBundle form '@ohos.bundle.distributedBundle'
```

## cl.bundlemanager.12 Installation-Free Module and API Changes
APIs support exception handling rectification. The installation-free module is moved from **@ohos.bundle.d.ts** to **@ohos.bundle.freeInstall.d.ts**, involving module and API changes. The system capability is **SystemCapability.BundleManager.BundleFramework.FreeInstall**.
1. The imported **@ohos.bundle** module needs to be changed to **@ohos.bundle.freeInstall**.
2. The **setModuleUpgradeFlag** API is changed to **setHapModuleUpgradeFlag**.
3. The **isModuleRemovable** API is changed to **isHapModuleRemovable**.
4. The **getDispatcher** API is changed to **getDispatchInfo**.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. Applications using APIs of version 9 will fail to be compiled.

**Key API/Component Changes**

The following table lists the installation-free API changes. For APIs not listed in the table, their names and usage are unchanged, but the module name is changed.

| Deprecated                | Added or Changed in API Version 9         | System API|
| -------------------- | ----------------------- | --------- |
| setModuleUpgradeFlag | setHapModuleUpgradeFlag | Yes       |
| isModuleRemovable    | isHapModuleRemovable    | Yes       |
| getDispatcher        | getDispatchInfo         | Yes       |

**Adaptation Guide**

To use installation-free APIs, import a new module and modify the APIs according to their mappings.

```
import freeInstall from '@ohos.bundle.freeInstall'
```

## cl.bundlemanager.13 Installation-Free Structure Field Changes
The fields of the **DisPatchInfo**, **AbilityFormInfo**, **ModuleDistroInfo**, and **ModuleConfigInfo** structures are changed as follows:
1. The name of the **dispatchAPI** field in **DispatchInfo** is changed to [dispatchAPIVersion](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/DispatchInfo.d.ts), and the type is string, which is unchanged. The field indicates the version of the installation-free API. The meaning remains unchanged.
2. The type of the **supportDimensions** field in the **AbilityFormInfo** structure is changed from **Array\<number>** to **Array\<string>**.
3. The type of the **defaultDimension** field in the **AbilityFormInfo** structure is changed from **number** to **string**.
4. The **mainAbility** field is deprecated in the **ModuleDistroInfo** structure and moved to the **ModuleConfigInfo** structure.
5. The **mainAbility** field is added to the **ModuleConfigInfo** structure.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. The value type of certain fields in the structures is changed. As a result, applications using APIs of version 9 may fail to be compiled using the new SDK.

**Key API/Component Changes**

1. DispatchInfo

| Deprecated       | Added or Changed in API Version 9    | Type  |
| ----------- | ------------------ | ------ |
| dispatchAPI | dispatchAPIVersion | string |

2. AbilityFormInfo

| Field             | Type in API Version 9      | Original Type        |
| ----------------- | -------------- | -------------- |
| supportDimensions | Array\<string> | Array\<number> |
| defaultDimension  | string         | number         |

3. ModuleDistroInfo

| Field       | Added or Changed in API Version 9| Type  |
| ----------- | -------------- | ------ |
| mainAbility | N/A            | string |

4. MooduleConfigInfo

| Field| Added or Changed in API Version 9| Type  |
| ---- | -------------- | ------ |
| N/A  | mainAbility    | string |

**Adaptation Guide**

To use installation-free APIs, import a new module and modify the structures according to their mappings.

```
import freeInstall from '@ohos.bundle.freeInstall'
```

## cl.bundlemanager.14 Structure Changes
The structure **GrantStatus** is changed to **PermissionGrantState**. The enumeration type and values remain unchanged.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. The structure name is changed. As a result, applications using APIs of version 9 may fail to be compiled using the new SDK.

**Key API/Component Changes**

The **GrantStatus** structure indicating the authorization status is changed to **PermissionGrantState** in **@ohos.bundle.bundleManager.d.ts**.

| Name            | Value|
| ------------------ | ------ |
| PERMISSION_DENIED  | -1     |
| PERMISSION_GRANTED | 0      |

**Adaptation Guide**

Import a new module and change the structure name to **PermissionGrantState**.

```
import bundle form '@ohos.bundle.bundleManager'
```
## cl.bundlemanager.15 Bundle Manager ShortcutInfo Structure Field Changes
Fields in the **ShortcutInfo** structure of the bundle manager are changed. The **bundle/shortcutInfo.d.ts** fields are deprecated, and the file is changed to [bundleManager/ShortcutInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ShortcutInfo.d.ts). The **ShortcutInfo** and **ShortWant** structures are changed to system APIs.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. The value type of certain fields in the structures is changed. As a result, applications using APIs of version 9 may fail to be compiled using the new SDK.

**Key API/Component Changes**

The **ShortcutInfo** and **ShortcutWant** structures are involved. To use the level-2 module export function, import the new module **@ohos.bundle.launcherBundleManager**.
The following table lists the field changes of the **ShortcutInfo** structure. Fields that are not listed in the table still exist in API version 9.

| Deprecated          | Added or Changed in API Version 9| Type   |
| -------------- | -------------- | ------- |
| disableMessage | N/A            | string  |
| isStatic       | N/A            | boolean |
| isHomeShortcut | N/A            | boolean |
| isEnabled      | N/A            | boolean |
| disableMessage | N/A            | boolean |

The following table lists the field changes of the **ShortcutWant** structure. Fields that are not listed in the table still exist in API version 9.
| Deprecated       | Added or Changed in API Version 9| Type  |
| ----------- | -------------- | ------ |
| targetClass | targetAbility  | string |

**Adaptation Guide**

To use installation-free APIs, import a new module and modify the structures according to their mappings.

```
import launcherBundleManager form '@ohos.bundle.launcherBundleManager'
```

## cl.bundlemanager.16 getBundleInstaller API Changes
The **getBundleInstaller** API of the bundle manager is moved from **@ohos.bundle.d.ts** to [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts).
The system capability is **SystemCapability.BundleManager.BundleFramework.Core**.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. Applications that use APIs of version 9 need to adapt the new module and APIs.

**Key API/Component Changes**
1. For **getBundleInstaller**, the import module is changed from **@ohos.bundle** to **@ohos.bundle.installer**.

**Adaptation Guide**

Import the new bundle manager installation module and call **getBundleInstaller**.

```
import installer form '@ohos.bundle.installer'
```

## cl.bundlemanager.17 Bundle Manager Installation API Changes
The bundle manager installation API is moved from **bundle/bundleInstaller.d.ts** to [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts). The system capability is **SystemCapability.BundleManager.BundleFramework.Core**.

**Change Impacts**

Applications using APIs earlier than version 9 are not affected. Applications that use APIs of version 9 need to adapt the new module and APIs.

**Key API/Component Changes**

1. The exception handling capability is added to the **install**, **uninstall**, and **recover** APIs. The API names and input parameters remain unchanged, and only the module name is changed.
2. Fields are added to the **HashParam** structure as follows.

| Added in API Version 9  | Type  |
| ---------- | ------ |
| moduleName | string |
| hashValue  | string |

3. Fields are added to the **InstallParam** structure as follows.

| Added in API Version 9         | Type             |
| ----------------- | ----------------- |
| userId            | number            |
| installFlag       | number            |
| isKeepData        | boolean           |
| hashParams        | Array\<HashParam> |
| crowdtestDeadline | number            |

4. The **InstallStatus** structure is deprecated.

**Adaptation Guide**

Import the new bundle manager installation module and call **getBundleInstaller**.

```
import installer form '@ohos.bundle.installer'
```

## cl.bundlemanager.18 Bundle Manager Installation Function Changes
The installation specifications of the bundle manager module are changed, in which whether the application **deviceType** setting matches the device type is verified. If they do not match, the installation fails.

**Change Impacts**

Applications developed in earlier versions are affected. Applications can be successfully installed in the image of the new version only after adaptation.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Configure device types in the application configuration file **config.json** or **module.json**.

```
{
    "module": {
        "name": "entry",
        "type": "entry",
        // ...
        "deviceTypes":[
            // In this example, default and tablet are configured. In this case, the application can be installed on default and tablet.
            "default",
            "tablet"
        ],
        // ...
    }
```
## cl.bundlemanager.19 innerBundleManger Module API Changes
**innerBundleManager** API functions are unchanged, but API usage is changed. The [@ohos.bundle.launcherBundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.launcherBundleManager.d.ts) module needs to be imported to use **innerBundleManager** APIs. The system capability is **SystemCapability.BundleManager.BundleFramework.Core**.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. Applications that use the **innerBundleManager** API capabilities need to adapt the new module and APIs.

**Key API/Component Changes**

The functions and input parameters of the following APIs remain unchanged, and API exception handling is added. When a level-2 module is used to export **ShortcutInfo** and **ShortcutWant**, the **@ohos.bundle.launcherBundleManager** module needs to be imported. The **on** and **off** APIs are deprecated from **@ohos.bundle.innerBundleManger.d.ts** and moved to **@ohos.bundle.bundleMonitor.d.ts**.

1. getLauncherAbilityInfos<br>
2. getAllLauncherAbilityInfos<br>
3. getShortcutInfos

**Adaptation Guide**

Import the new module **@ohos.bundle.launcherBundleManage**.

```
import launcherBundleManager form '@ohos.bundle.launcherBundleManage'
```

## cl.bundlemanager.20 innerBundleManagr Module Changes
**innerBundleManager** API functions are unchanged, but API usage is changed. The [@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts) module needs to be imported to use **innerBundleManager** APIs, which are system APIs. The system capability is **SystemCapability.BundleManager.BundleFramework.Core**.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. Applications that use the **innerBundleManager** API capabilities need to adapt the new module and APIs.

**Key API/Component Changes**

The **on** and **off** APIs are changed to **@ohos.bundle.bundleMonitor.d.ts**. The input parameters are different from those of the original APIs. The function prototype of the APIs of version 9 is as follows:

```
function on(type: BundleChangedEvent, callback: Callback<BundleChangedInfo>): void;
function off(type: BundleChangedEvent, callback?: Callback<BundleChangedInfo>): void;
```
**BundleChangedEvent**:

```
type BundleChangedEvent = 'add' | 'update' | 'remove';
```
Callback function of **BundleChangedInfo**:
```
  interface BundleChangedInfo {
    readonly bundleName: string;
    readonly userId: number;
  }
```
After obtaining **BundleChangedInfo**, perform related operations (that is, the **add**, **update**, and **remove** functions in **BundleStatusCallback** of the original API).

**Adaptation Guide**

Import the **bundleMonitor** module and call related APIs.

```
import bundleMonitor form '@ohos.bundle.bundleMonitor'
```

## cl.bundlemanager.21 bundleStatusCallback.d.ts API Changes
The **bundleStatusCallback.d.ts** APIs of the bundle manager are deprecated and moved to [@ohos.bundle.bundleMonitor.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleMonitor.d.ts). The **add**, **update**, and **remove** functions in **BundleStatusCallback** are deprecated and changed to **BundleChangedEvent**, which is a system API. The system capability is **SystemCapability.BundleManager.BundleFramework.Core**.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. Applications that use the **BundleStatusCallback** API capabilities need to adapt the new module and APIs.

**Key API/Component Changes**

All the following functions are deprecated. The **BundleChangedEvent** API is added to **@ohos.bundle.bundleMonitor.d.ts**.

1. add
2. update
3. remove

**Adaptation Guide**

Import the **bundleMonitor** module and call related APIs. Different from the previous **BundleStatusCallback**, **BundleStatusCallback** passes the **add**, **update**, and **remove** functions to the **on** and **off** APIs. The **BundleMonitor** uses the **on** or **off** API of version 9 to return **BundleChangedInfo** to the caller through the callback.

```
import bundleMonitor form '@ohos.bundle.bundleMonitor'
```

## cl.bundlemanager.22 Zlib Module API Changes
The **Zlib** module APIs of the bundle manager are changed. Certain APIs in [@ohos.zlib.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.zlib.d.ts) are deprecated and changed. The system capability is **SystemCapability.BundleManager.Zlib**.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. Applications that use APIs of version 9 need to adapt the new module and APIs.

**Key API/Component Changes**

The following table lists the changed APIs in **@ohos.zlib.d.ts**. The usage of the new APIs of version 9 is the same, and API exception handling is supported.

| Deprecated     | Added or Changed in API Version 9| System API|
| --------- | -------------- | --------- |
| zipFile   | compressFile   | Yes       |
| unzipFile | decompressFile | Yes       |
| ErrorCode | N/A            | Yes       |

**Adaptation Guide**

The import module does not change. The new API is directly used to adapt exception handling.

```
import zlib form '@ohos.zlib'
```