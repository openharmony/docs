# innerBundleManager模块(JS端SDK接口)

本模块提供内部包的管理

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import innerBundleManager from '@ohos.bundle.innerBundleManager';
```

## 系统能力

SystemCapability.BundleManager.BundleFramework

## 权限列表

| 权限                                       | 权限等级     | 描述                         |
| ------------------------------------------ | ------------ | ---------------------------- |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息           |
| ohos.permission.LISTEN_BUNDLE_CHANGE       | system_grant | 允许该应用获取应用变化消息。 |

权限等级参考[权限等级说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/accesstoken-overview.md#%E6%9D%83%E9%99%90%E7%AD%89%E7%BA%A7%E8%AF%B4%E6%98%8E)

## innerBundleManager.getLauncherAbilityInfos

getLauncherAbilityInfos(bundleName: string, userId: number, callback: AsyncCallback&lt;Array&lt;LauncherAbilityInfo&gt;&gt;) : void;

以异步方法根据给定的包名获取LauncherAbilityInfos，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                                  |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| bundleName | string                                                       | 是   | 要查询的应用程序包名称。                              |
| userId     | number                                                       | 是   | 用户ID。取值范围：大于等于0。 |
| callback   | AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回程序信息。            |



## innerBundleManager.getLauncherAbilityInfos

getLauncherAbilityInfos(bundleName: string, userId: number) : Promise&lt;Array&lt;LauncherAbilityInfo&gt;&gt;

以异步方法根据给定的包名获取LauncherAbilityInfos，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称       | 类型   | 必填 | 描述                                                  |
| ---------- | ------ | ---- | ----------------------------------------------------- |
| bundleName | string | 是   | 要查询的应用程序包名称。                              |
| userId     | number | 是   | 用户ID。取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | Promise形式返回程序信息。 |

## innerBundleManager.on

on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback, callback: AsyncCallback&lt;string&gt;) : void;

注册Callback，使用callback方式异步回调。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称                 | 类型                  | 必填 | 描述                                                 |
| -------------------- | --------------------- | ---- | ---------------------------------------------------- |
| type                 | string | 是   | 指示应执行命令，只支持BundleStatusChange。             |
| bundleStatusCallback | [BundleStatusCallback](js-apis-Bundle-BundleStatusCallback.md) | 是   | 指示要注册的回调。                                   |
| callback             | AsyncCallback\<string> | 是   | 程序启动作为入参的回调函数，返回正确结果或错误信息。 |

## innerBundleManager.on

on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback): Promise&lt;string&gt;

注册Callback，使用promise方式异步回调。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称                 | 类型                                                         | 必填 | 描述                                       |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| type                 | string                                                       | 是   | 指示应执行命令，只支持BundleStatusChange。 |
| bundleStatusCallback | [BundleStatusCallback](js-apis-Bundle-BundleStatusCallback.md) | 是   | 指示要注册的回调。                         |

**返回值：**

| 类型            | 说明                                |
| --------------- | ----------------------------------- |
| Promise\<string> | Promise形式返回正确结果或错误信息。 |

## innerBundleManager.off

off(type:"BundleStatusChange", callback: AsyncCallback&lt;string&gt;) : void;

取消注册Callback，使用callback方式异步回调。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称     | 类型                  | 必填 | 描述                                                 |
| -------- | --------------------- | ---- | ---------------------------------------------------- |
| type     | string | 是   | 指示应执行命令，只支持BundleStatusChange。               |
| callback | AsyncCallback\<string> | 是   | 程序启动作为入参的回调函数，返回正确结果或错误信息。 |

## innerBundleManager.off

off(type:"BundleStatusChange"): Promise&lt;string&gt;

取消注册Callback，使用promise方式异步回调。

**需要权限：**

ohos.permission.LISTEN_BUNDLE_CHANGE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称 | 类型   | 必填 | 描述                                       |
| ---- | ------ | ---- | ------------------------------------------ |
| type | string | 是   | 指示应执行命令，只支持BundleStatusChange。 |

**返回值：**

| 类型            | 说明                                |
| --------------- | ----------------------------------- |
| Promise\<string> | Promise形式返回正确结果或错误信息。 |

## innerBundleManager.getAllLauncherAbilityInfos

getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback&lt;Array&lt;LauncherAbilityInfo&gt;&gt;) : void;

以异步方法获取所有的LauncherAbilityInfos，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称     | 类型                                                         | 必填 | 描述                                                  |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| userId   | number                                                       | 是   | 用户ID。取值范围：大于等于0。 |
| callback | AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回程序信息。            |

## innerBundleManager.getAllLauncherAbilityInfos

getAllLauncherAbilityInfos(userId: number) : Promise&lt;Array&lt;LauncherAbilityInfo&gt;&gt;

以异步方法获取LauncherAbilityInfos，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称   | 类型   | 必填 | 描述                                                  |
| ------ | ------ | ---- | ----------------------------------------------------- |
| userId | number | 是   | 用户ID。取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundle-LauncherAbilityInfo.md)>> | Promise形式返回程序信息。 |

## innerBundleManager.getShortcutInfos

getShortcutInfos(bundleName :string, callback: AsyncCallback&lt;Array&lt;ShortcutInfo&gt;&gt;) : void;

以异步方法根据给定的包名获取快捷方式信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称       | 类型                                                         | 必填 | 描述                                           |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| bundleName | string                                                       | 是   | 要查询的应用程序包名称。                       |
| callback   | AsyncCallback\<Array<[ShortcutInfo](js-apis-bundle-ShortcutInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回快捷方式信息。 |

## innerBundleManager.getShortcutInfos

getShortcutInfos(bundleName : string) : Promise&lt;Array&lt;ShortcutInfo&gt;&gt;

以异步方法根据给定的包名获取快捷方式信息，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统API：**

此接口为系统接口，三方应用不支持调用

**参数：**

| 名称       | 类型   | 必填 | 描述                     |
| ---------- | ------ | ---- | ------------------------ |
| bundleName | string | 是   | 要查询的应用程序包名称。 |

**返回值：**

| 类型                                                     | 说明                          |
| -------------------------------------------------------- | ----------------------------- |
| Promise\<Array<[ShortcutInfo](js-apis-bundle-ShortcutInfo.md)>> | Promise形式返回快捷方式信息。 |

