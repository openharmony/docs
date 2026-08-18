# @ohos.bundle.pluginBundleManager (pluginBundleManager module)

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @menghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=f6aebb5feee7366b8f8186d7dd8d5c650b89a049 translatedAt=2026-08-13T13:22:56.811Z pushedAt=2026-08-17T07:31:13.524Z -->

This module provides the capability of managing self-distributed plugins for an app, including installing and uninstalling local plugins.

**Since**: 26.0.0

## Modules to Import

```ts
import { pluginBundleManager } from '@kit.AbilityKit';
```

## pluginBundleManager.installLocalPlugin

installLocalPlugin(pluginFilePaths: Array\<string>): Promise\<void>

Installs a self-distributed plugin (that is, a plugin distributed and managed by the app through its own channels) for the current app. This API uses a promise to return the result.

**Since**: 26.0.0

**Required permissions:** ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type            | Mandatory | Description                                                         |
| ---------------- | --------------- | ---- | ------------------------------------------------------------ |
| pluginFilePaths  | Array\<string>  | Yes  | Array of plugin file paths, indicating the list of paths of the plugin files to install.           |

**Return value**

| Type           | Description              |
| -------------- | ------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID | Error Message                                 |
| -------- | ---------------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN'. |
| 17700010 | Failed to install the plugin because the plugin fails to be parsed. |
| 17700011 | Failed to install the plugin because the plugin signature fails to be verified. |
| 17700012 | Failed to install the plugin because the HSP path is invalid or the HSP is too large. |
| 17700015 | Failed to install the plugin because they have different configuration information. |
| 17700016 | Failed to install the plugin because of insufficient system disk space. |
| 17700017 | Failed to install the plugin since the version of the plugin to install is too early. |
| 17700048 | Failed to install the plugin because the code signature verification failed. |
| 17700052 | Failed to install the plugin because debug bundle cannot be installed under non-developer mode. |
| 17700073 | Failed to install the plugin because a plugin with the same bundle name but different signature information exists on the device. |
| 17700087 | Failed to install the plugin because the current device does not support plugins. |
| 17700091 | Failed to install the plugin because the plugin name is the same as the host bundle name. |

**Example**

```ts
import { pluginBundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Replace it with the actual plugin file path.
let pluginPaths: Array<string> = ["/data/storage/el2/base/haps/entry/plugin.hsp"];

pluginBundleManager.installLocalPlugin(pluginPaths)
  .then(() => {
    console.info('installLocalPlugin success');
  }).catch((err: BusinessError) => {
  console.error(`installLocalPlugin errData is errCode:${err.code}  message:${err.message}`);
});
```

## pluginBundleManager.uninstallLocalPlugin

uninstallLocalPlugin(pluginBundleName: string): Promise\<void>

Uninstalls the specified plugin installed by the current app through self-distribution. This API uses a promise to return the result.

**Since**: 26.0.0

**Required permissions:** ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type | Mandatory | Description |
| ---------------- | -------- | ---- | ------------------------------------------------------------ |
| pluginBundleName | string | Yes | Bundle name of the plugin, indicating the bundle name of the plugin to uninstall. |

**Return value**

| Type             | Description              |
| -------------- | --------------- |
| Promise\<void> | Promise used to return no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID | Error Message                                 |
| -------- | ---------------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN'. |
| 17700092 | Failed to uninstall the plugin because the specified plugin is not found. |

**Example**

```ts
import { pluginBundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Replace with the actual plugin bundle name.
let pluginBundleName = "com.example.plugin";

pluginBundleManager.uninstallLocalPlugin(pluginBundleName)
  .then(() => {
    console.info('uninstallLocalPlugin success');
  }).catch((err: BusinessError) => {
  console.error(`uninstallLocalPlugin errData is errCode:${err.code}  message:${err.message}`);
});
```

## pluginBundleManager.getAllLocalPluginInfoForSelf

getAllLocalPluginInfoForSelf(): Promise\<Array\<PluginBundleInfo>>

Queries the information about all self-distributed plugins in the current app. This API uses a promise to return the result.

**Since**: 26.0.0

**Required permissions:** ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                                                         | Description                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise<Array\<[PluginBundleInfo](js-apis-bundleManager-pluginBundleInfo.md#pluginbundleinfo-1)>> | Promise used to return the list of information about all local plugins installed in the current app. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                 |
| -------- | ---------------------------------------- |
| 201 | Calling interface without permission 'ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN'. |

**Example**

```ts
import { pluginBundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

pluginBundleManager.getAllLocalPluginInfoForSelf().then((data): void => {
  console.info('getAllLocalPluginInfoForSelf plugin data is' + JSON.stringify(data));
}).catch((err: Error): void => {
  const businessErr = err as BusinessError;
  console.error(`getAllLocalPluginInfoForSelf errData is errCode:${businessErr.code}  message:${businessErr.message}`);
});
```

## PluginBundleInfo

type PluginBundleInfo = _PluginBundleInfo

Plugin information.

**Since**: 26.0.0

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

| Type                                                         | Description           |
| ------------------------------------------------------------ | -------------- |
| [_PluginBundleInfo](js-apis-bundleManager-pluginBundleInfo.md#pluginbundleinfo-1) |Plugin information. |

## PluginModuleInfo

type PluginModuleInfo = _PluginModuleInfo

Module information of the plugin.

**Since**: 26.0.0

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

| Type                                                         | Description           |
| ------------------------------------------------------------ | -------------- |
| [_PluginModuleInfo](js-apis-bundleManager-pluginBundleInfo.md#pluginmoduleinfo) |Module information of the plugin. |