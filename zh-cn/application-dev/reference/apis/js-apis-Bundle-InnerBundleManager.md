# innerBundleManager模块<sup>(deprecated)</sup>

本模块提供launcher应用使用的接口

> 
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块从API version 9开始不再支持。建议使用[launcherBundleManager](js-apis-launcherBundleManager.md)及[bundleMonitor](js-apis-bundleMonitor.md)替代。

## 导入模块

```typescript
import innerBundleManager from '@ohos.bundle.innerBundleManager';
```

## 系统能力

SystemCapability.BundleManager.BundleFramework


## innerBundleManager.getLauncherAbilityInfos<sup>(deprecated)</sup>

getLauncherAbilityInfos(bundleName: string, userId: number, callback: AsyncCallback&lt;Array&lt;LauncherAbilityInfo&gt;&gt;) : void;

以异步方法根据给定的包名获取LauncherAbilityInfos，使用callback形式返回结果。
> 从API version 9开始不再支持。建议使用[launcherBundleManager#getLauncherAbilityInfo](js-apis-launcherBundleManager.md)替代。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                  |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| bundleName | string                                                       | 是   | 要查询的应用程序包名称。                              |
| userId     | number                                                       | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback   | AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回程序信息。            |


## innerBundleManager.getLauncherAbilityInfos<sup>(deprecated)</sup>

getLauncherAbilityInfos(bundleName: string, userId: number) : Promise&lt;Array&lt;LauncherAbilityInfo&gt;&gt;

以异步方法根据给定的包名获取LauncherAbilityInfos，使用Promise形式返回结果。
> 从API version 9开始不再支持。建议使用[launcherBundleManager#getLauncherAbilityInfo](js-apis-launcherBundleManager.md)替代。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                  |
| ---------- | ------ | ---- | ----------------------------------------------------- |
| bundleName | string | 是   | 要查询的应用程序包名称。                              |
| userId     | number | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | Promise形式返回程序信息。 |

## innerBundleManager.on<sup>(deprecated)</sup>

on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback, callback: AsyncCallback&lt;string&gt;) : void;

注册Callback。
> 从API version 9开始不再支持。建议使用[bundleMonitor#on](js-apis-bundleMonitor.md)替代。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名              | 类型                  | 必填 | 说明                                               |
| -------------------- | --------------------- | ---- | ---------------------------------------------------- |
| type                 | string | 是   | 指示应执行命令，只支持BundleStatusChange。             |
| bundleStatusCallback | [BundleStatusCallback](js-apis-Bundle-BundleStatusCallback.md) | 是   | 指示要注册的回调。                                   |
| callback             | AsyncCallback\<string> | 是   | 程序启动作为入参的回调函数，返回正确结果或错误信息。 |

## innerBundleManager.on<sup>(deprecated)</sup>

on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback) : Promise&lt;string&gt;

注册Callback。
> 从API version 9开始不再支持。建议使用[bundleMonitor#on](js-apis-bundleMonitor.md)替代。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名               | 类型                                                         | 必填 | 说明                                       |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| type                 | string                                                       | 是   | 指示应执行命令，只支持BundleStatusChange。 |
| bundleStatusCallback | [BundleStatusCallback](js-apis-Bundle-BundleStatusCallback.md) | 是   | 指示要注册的回调。                         |

**返回值：**

| 类型            | 说明                                |
| --------------- | ----------------------------------- |
| Promise\<string> | Promise形式返回正确结果或错误信息。 |

## innerBundleManager.off<sup>(deprecated)</sup>

off(type:"BundleStatusChange", callback: AsyncCallback&lt;string&gt;) : void;

取消注册Callback。
> 从API version 9开始不再支持。建议使用[bundleMonitor#off](js-apis-bundleMonitor.md)替代。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                               |
| -------- | --------------------- | ---- | ---------------------------------------------------- |
| type     | string | 是   | 指示应执行命令，只支持BundleStatusChange。               |
| callback | AsyncCallback\<string> | 是   | 程序启动作为入参的回调函数，返回正确结果或错误信息。 |

## innerBundleManager.off<sup>(deprecated)</sup>

off(type:"BundleStatusChange") : Promise&lt;string&gt;

取消注册Callback。
> 从API version 9开始不再支持。建议使用[bundleMonitor#off](js-apis-bundleMonitor.md)替代。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名 | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| type   | string | 是   | 指示应执行命令，只支持BundleStatusChange。 |

**返回值：**

| 类型            | 说明                                |
| --------------- | ----------------------------------- |
| Promise\<string> | Promise形式返回正确结果或错误信息。 |

## innerBundleManager.getAllLauncherAbilityInfos<sup>(deprecated)</sup>

getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback&lt;Array&lt;LauncherAbilityInfo&gt;&gt;) : void;

以异步方法获取所有的LauncherAbilityInfos，使用callback形式返回结果。
> 从API version 9开始不再支持。建议使用[launcherBundleManager#getAllLauncherAbilityInfo](js-apis-launcherBundleManager.md)替代。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                  |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| userId   | number                                                       | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| callback | AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回程序信息。            |

## innerBundleManager.getAllLauncherAbilityInfos<sup>(deprecated)</sup>

getAllLauncherAbilityInfos(userId: number) : Promise&lt;Array&lt;LauncherAbilityInfo&gt;&gt;

以异步方法获取LauncherAbilityInfos，使用Promise形式返回结果。
> 从API version 9开始不再支持。建议使用[launcherBundleManager#getAllLauncherAbilityInfo](js-apis-launcherBundleManager.md)替代。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                  |
| ------ | ------ | ---- | ----------------------------------------------------- |
| userId | number | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | Promise形式返回程序信息。 |

## innerBundleManager.getShortcutInfos<sup>(deprecated)</sup>

getShortcutInfos(bundleName :string, callback: AsyncCallback&lt;Array&lt;ShortcutInfo&gt;&gt;) : void;

以异步方法根据给定的包名获取快捷方式信息，使用callback形式返回结果。
> 从API version 9开始不再支持。建议使用[launcherBundleManager#getShortcutInfo](js-apis-launcherBundleManager.md)替代。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                           |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| bundleName | string                                                       | 是   | 要查询的应用程序包名称。                       |
| callback   | AsyncCallback\<Array<[ShortcutInfo](js-apis-bundle-ShortcutInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回快捷方式信息。 |

## innerBundleManager.getShortcutInfos<sup>(deprecated)</sup>

getShortcutInfos(bundleName : string) : Promise&lt;Array&lt;ShortcutInfo&gt;&gt;

以异步方法根据给定的包名获取快捷方式信息，使用Promise形式返回结果。
> 从API version 9开始不再支持。建议使用[launcherBundleManager#getShortcutInfo](js-apis-launcherBundleManager.md)替代。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名     | 类型   | 必填 | 说明                     |
| ---------- | ------ | ---- | ------------------------ |
| bundleName | string | 是   | 要查询的应用程序包名称。 |

**返回值：**

| 类型                                                     | 说明                          |
| -------------------------------------------------------- | ----------------------------- |
| Promise\<Array<[ShortcutInfo](js-apis-bundle-ShortcutInfo.md)>> | Promise形式返回快捷方式信息。 |

