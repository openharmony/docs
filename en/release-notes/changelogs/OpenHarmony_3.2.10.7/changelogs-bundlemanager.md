# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Deleted getAbilityIcon

The **getAbilityIcon** API in [@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts) is deleted. The **getMediaContent** API in [@ohos.resourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.resourceManager.d.ts) can be used instead.

**Change Impact**<br>
The **getAbilityIcon** API does not take effect.

**Key API/Component Changes**<br>
The **getAbilityIcon** API is deleted from **@ohos.bundle.bundleManager.d.ts**.

**Adaptation Guide**<br>
If your application uses **getAbilityIcon** in **@ohos.bundle.bundleManager.d.ts**, replace it with **getMediaContent** in **@ohos.resourceManager.d.ts**. You need to obtain the icon ID in advance. For details, see [Usage Guide](../../../application-dev/reference/apis/js-apis-resource-manager.md#getmediacontent9).

## cl.bundlemanager.2 Bottom-Layer Capability Changed So That Only the System Resource HAP Supports Custom Permissions

Only the system resource HAP supports custom permissions. During HAP parsing, the bundle manager module parses the **definePermissions** field only in the configuration file of the resource HAP (bundle name: **ohos.global.systemres**), but not this field in other HAPs. This field is used to define permissions.
If an application requires custom permissions, add the permissions under the **definePermissions** field in the [configuration file](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) of the system resource HAP. For details about the permission format, see [Defining Permissions](../../../application-dev/quick-start/module-structure.md#internal-structure-of-the-definepermissions-attribute).


**Change Impact**<br>
After an upgrade to the new version image, the custom permission of the application does not take effect, and the authorization fails.

**Key API/Component Changes**<br>
The bottom-layer capability of the bundle manager module is changed. Only the system resource HAP supports custom permissions.

**Adaptation Guide**<br>
If an application requires custom permissions, add the permissions under the **definePermissions** field in the [configuration file](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) of the system resource HAP. For details about the permission format, see [Defining Permissions](../../../application-dev/quick-start/module-structure.md#internal-structure-of-the-definepermissions-attribute).

## cl.bundlemanager.3 Level-2 Module File Names Changed

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

## cl.bundlemanager.4 LaunchType Enum Type Name Changed from STANDARD to MULTITON

The enum type name of [LaunchType](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts) is changed from **STANDARD** to **MULTITON**. The enum value remains unchanged, indicating the multi-instance type.

**Change Impact**<br>
The **LaunchType.STANDARD** type does not take effect.

**Key API/Component Changes**<br>
The enum type name of **LaunchType** is changed from **STANDARD** to **MULTITON**.

**Adaptation Guide**<br>
Change **LaunchType.STANDARD** to **LaunchType.MULTITON** for your application.

## cl.bundlemanager.5 Changed the isVisible Field in the AbilityInfo Struct to exported

The **isVisible** field in the [AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts) struct is changed to **exported**. The type remains unchanged, indicating whether the ability can be exported and used by other abilities.

**Change Impact**<br>
The **isVisible** field does not take effect.

**Key API/Component Changes**<br>
The **isVisible** field in the [AbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts) struct is changed to **exported**, and the type remains unchanged.

**Adaptation Guide**<br>
Change **isVisible** to **exported** for your application.

## cl.bundlemanager.6 Changed the isVisible Field in the ExtensionAbilityInfo Struct to exported

The **isVisible** field in the [ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts) struct is changed to **exported**. The type remains unchanged, indicating whether the ability can be exported and used by other abilities.

**Change Impact**<br>
The **isVisible** field does not take effect.

**Key API/Component Changes**<br>
The **isVisible** field in the [ExtensionAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ExtensionAbilityInfo.d.ts) struct is changed to **exported**, and the type remains unchanged.

**Adaptation Guide**<br>
Change **isVisible** to **exported** for your application.

## cl.bundlemanager.7 Changed the visible Field in the ModuleAbilityInfo Struct to exported

The **visible** field in the [ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts) struct is changed to **exported**. The type remains unchanged, indicating whether the ability can be exported and used by other abilities.

**Change Impact**<br>
The **visible** field does not take effect.

**Key API/Component Changes**<br>
The **visible** field in the [ModuleAbilityInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/BundlePackInfo.d.ts) struct is changed to **exported**, and the type remains unchanged.

**Adaptation Guide**<br>
Change **visible** to **exported** for your application.

## cl.bundlemanager.8 Deleted the distributedNotificationEnabled Tag from the app.json File
The [distributedNotificationEnabled](../../../application-dev/quick-start/app-configuration-file.md) tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.9 Deleted the entityType Tag from the app.json File
The [entityType](../../../application-dev/quick-start/app-configuration-file.md) tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.10 Deleted the keepAlive Tag from the app.json File
The [keepAlive](../../../application-dev/quick-start/app-configuration-file.md) tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.11 Deleted the removable Tag from the app.json File
The [removable](../../../application-dev/quick-start/app-configuration-file.md) tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.12 Deleted the singleton Tag from the app.json File
The [singleton](../../../application-dev/quick-start/app-configuration-file.md) tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.13 Deleted the userDataClearable Tag from the app.json File
The [userDataClearable](../../../application-dev/quick-start/app-configuration-file.md) tag is deleted from the **app.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.14 No Longer Chinese Characters for the name Tag under module in the module.json File
The value of [name](../../../application-dev/quick-start/module-configuration-file.md) under **module** in the **module.json** file does not support Chinese characters.

**Change Impact**<br>
If the tag is set to Chinese, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Set this tag to English.

## cl.bundlemanager.15 No Longer Chinese Characters for the name Tag under ability in the module.json File
The value of [name](../../../application-dev/quick-start/module-configuration-file.md) under **ability** in the **module.json** file does not support Chinese characters.

**Change Impact**<br>
If the tag is set to Chinese, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Set this tag to English.

## cl.bundlemanager.16 Deleted the uiSyntax Tag from the module.json File
The [uiSyntax](../../../application-dev/quick-start/module-configuration-file.md) tag is deleted from the **module.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.17 Changed srcEntrance to srcEntry in the module.json File
The [srcEntrance](../../../application-dev/quick-start/module-configuration-file.md) tag under **module** and **ability** in the **module.json** file is changed to **srcEntry**.

**Change Impact**<br>
If the **srcEntrance** tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Replace the **srcEntrance** tag with **srcEntry** in the configuration file.

## cl.bundlemanager.18 Deleted the apiVersion Tag Under distroFilter from the module.json File
The **apiVersion** tag under [distroFilter](../../../application-dev/quick-start/module-configuration-file.md) is deleted from the **module.json** file.

**Change Impact**<br>
If this tag is used, an error is reported during compilation on DevEco Studio.

**Adaptation Guide**<br>
Delete this tag from the configuration file.

## cl.bundlemanager.19 Changed standard of launchType to multiton in the module.json File
The **standard** mode of the [launchType](../../../application-dev/quick-start/module-configuration-file.md) tag in the **module.json** file is changed to **multiton**.

**Adaptation Guide**<br>
Replace **standard** of **launchType** with **multiton** in the configuration file.

## cl.bundlemanager.20 Changed visible of abilities to exported in the module.json File
The **visible** tag under [abilities](../../../application-dev/quick-start/module-configuration-file.md) in the [module.json] file is changed to **exported**, indicating whether the ability supports export and can be used by other ability.

**Adaptation Guide**<br>
Replace **visible** under **abilities** with **exported** in the configuration file.
