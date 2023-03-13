# Bundle Manager Subsystem Changelog
## cl.bundlemanager.1 Bottom-Layer Capability Changed So That Only the System Resource HAP Supports Custom Permissions

Only the system resource HAP supports custom permissions. During HAP parsing, the bundle manager module parses the **definePermissions** field only in the configuration file of the resource HAP (bundle name: **ohos.global.systemres**), but not this field in other HAPs. This field is used to define permissions.
If an application requires custom permissions, add the permissions under the **definePermissions** field in the [configuration file](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) of the system resource HAP. For details about the permission format, see [Defining Permissions](../../../application-dev/quick-start/module-structure.md#internal-structure-of-the-definepermissions-attribute).


**Change Impact**<br>
After an upgrade to the new version image, the custom permission of the application does not take effect, and the authorization fails.

**Key API/Component Changes**<br>
The bottom-layer capability of the bundle manager module is changed. Only the system resource HAP supports custom permissions.

**Adaptation Guide**<br>
If an application requires custom permissions, add the permissions under the **definePermissions** field in the [configuration file](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) of the system resource HAP. For details about the permission format, see [Defining Permissions](../../../application-dev/quick-start/module-structure.md#internal-structure-of-the-definepermissions-attribute).

## cl.bundlemanager.2 Level-2 Module File Names Changed

The level-2 module file names of the bundle manager module are changed to their respective API names in the file, as listed below.

| Original File Name|New File Name|
|----|----|
| bundleManager/abilityInfo.d.ts |  bundleManager/AbilityInfo.d.ts |
| bundleManager/applicationInfo.d.ts |  bundleManager/ApplicationInfo.d.ts |
| bundleManager/bundleInfo.d.ts |  bundleManager/BundleInfo.d.ts |
| bundleManager/dispatchInfo.d.ts |  bundleManager/DispatchInfo.d.ts |
| bundleManager/elementName.d.ts |  bundleManager/ElementName.d.ts |
| bundleManager/extensionAbilityInfo.d.ts |  bundleManager/ExtensionAbilityInfo.d.ts |
| bundleManager/hapModuleInfo.d.ts |  bundleManager/HapModuleInfo.d.ts |
| bundleManager/launcherAbilityInfo.d.ts |  bundleManager/LauncherAbilityInfo.d.ts |
| bundleManager/metadata.d.ts |  bundleManager/Metadata.d.ts |
| bundleManager/packInfo.d.ts |  bundleManager/BundlePackInfo.d.ts |
| bundleManager/permissionDef.d.ts |  bundleManager/PermissionDef.d.ts |
| bundleManager/remoteAbilityInfo.d.ts |  bundleManager/RemoteAbilityInfo.d.ts |
| bundleManager/shortcutInfo.d.ts |  bundleManager/ShortcutInfo.d.ts |

To sum up, except **packInfo**, which is changed to **BundlePackInfo**, the other file names are changed to start with uppercase letters.

**Change Impact**<br>
The change of the level-2 module file names does not affect the use of the level-1 module. If a level-2 module interface under **bundleManager** is directly imported to the .ts file and an error is reported during compilation on DevEco Studio, you must change the name of the imported file.

**Key API/Component Changes**<br>
The .d.ts file names in the **bundleManager** folder are changed to their respective API names in the file.

**Adaptation Guide**<br>
Generally, no adaptation is required. If a file in the **bundleManager** folder is directly imported to the application, you must change the imported file name as follows:

**Before change:**
```ts
import {AbilityInfo} from 'bundleManger/abilityInfo';
import {ExtensionAbilityInfo} from 'bundleManger/extensionAbilityInfo';
import {BundlePackInfo} from 'bundleManger/packInfo';
```
**After change:**
```ts
import {AbilityInfo} from 'bundleManger/AbilityInfo';
import {ExtensionAbilityInfo} from 'bundleManger/ExtensionAbilityInfo';
import {BundlePackInfo} from 'bundleManger/BundlePackInfo';
```

## cl.bundlemanager.3 LaunchType Enum Type Name Changed from STANDARD to MULTITON

The enum type name of [LaunchType](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts) is changed from **STANDARD** to **MULTITON**. The enum value remains unchanged, indicating the multi-instance type.

**Change Impact**<br>
The **LaunchType.STANDARD** type does not take effect.

**Key API/Component Changes**<br>
The enum type name of **LaunchType** is changed from **STANDARD** to **MULTITON**.

**Adaptation Guide**<br>
Change **LaunchType.STANDARD** to **LaunchType.MULTITON** for your application.

## cl.bundlemanager.4 Changed the isVisible Field in the AbilityInfo Struct to exported

The **isVisible** field in the [AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts) struct is changed to **exported**. The type remains unchanged, indicating whether the ability can be exported and used by other abilities.

**Change Impact**<br>
The **isVisible** field does not take effect.

**Key API/Component Changes**<br>
The **isVisible** field in the [AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts) struct is changed to **exported**, and the type remains unchanged.

**Adaptation Guide**<br>
Change **isVisible** to **exported** for your application.

## cl.bundlemanager.5 Changed the isVisible Field in the ExtensionAbilityInfo Struct to exported

The **isVisible** field in the [ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts) struct is changed to **exported**. The type remains unchanged, indicating whether the ability can be exported and used by other abilities.

**Change Impact**<br>
The **isVisible** field does not take effect.

**Key API/Component Changes**<br>
The **isVisible** field in the [ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts) struct is changed to **exported**, and the type remains unchanged.

**Adaptation Guide**<br>
Change **isVisible** to **exported** for your application.

## cl.bundlemanager.6 Changed the visible Field in the ModuleAbilityInfo Struct to exported

The **visible** field in the [ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts) struct is changed to **exported**. The type remains unchanged, indicating whether the ability can be exported and used by other abilities.

**Change Impact**<br>
The **visible** field does not take effect.

**Key API/Component Changes**<br>
The **visible** field in the [ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts) struct is changed to **exported**, and the type remains unchanged.

**Adaptation Guide**<br>
Change **visible** to **exported** for your application.
