# @ohos.bundle.launcherBundleManager (launcherBundleManager)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module providers APIs for the launcher application to obtain the [launcher ability information](js-apis-bundleManager-launcherAbilityInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { launcherBundleManager } from '@kit.AbilityKit';
```

## launcherBundleManager.getLauncherAbilityInfoSync

getLauncherAbilityInfoSync(bundleName: string, userId: number) : Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>

Obtains the launcher ability information based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|

**Returns**

| Type                         | Description                                              |
| ----------------------------- | -------------------------------------------------- |
| Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\> | Array of the LauncherAbilityInfo objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.       |

**Example**

```ts
import { launcherBundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let data = launcherBundleManager.getLauncherAbilityInfoSync("com.example.demo", 100);
    console.info("data is " + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## LauncherAbilityInfo

type LauncherAbilityInfo = _LauncherAbilityInfo

Defines the information about the launcher ability.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md) | Ability information of the home screen application.|

## ShortcutInfo<sup>20+</sup>

type ShortcutInfo = _ShortcutInfo

Defines the shortcut information defined in the [module.json5](../../quick-start/module-configuration-file.md#shortcuts) file of the application.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ShortcutInfo](./js-apis-bundleManager-shortcutInfo.md#shortcutinfo-1) | Shortcut information defined in the **module.json5** file.|

## ShortcutWant<sup>20+</sup>

type ShortcutWant = _ShortcutWant

Defines the target [wants](../../quick-start/module-configuration-file.md#wants) defined in the shortcut configuration.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ShortcutWant](./js-apis-bundleManager-shortcutInfo.md#shortcutwant) | Target [wants](../../quick-start/module-configuration-file.md#wants) defined in the shortcut configuration.|

## ParameterItem<sup>20+</sup>

type ParameterItem = _ParameterItem

Defines the custom data in the shortcut configuration.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ParameterItem](./js-apis-bundleManager-shortcutInfo.md#parameteritem) | Custom data in the shortcut configuration.|
