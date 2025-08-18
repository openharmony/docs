# @ohos.bundle.bundleMonitor (bundleMonitor模块)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供监听应用安装，卸载，更新的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
```

## BundleChangedInfo

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：**  此接口为系统接口。

| 名称       | 类型   | 只读 | 可选 | 说明                       |
| ---------- | ------ | ---- | ---- | -------------------------- |
| bundleName | string | 是   | 否   | 应用状态发生变化的应用Bundle名称。 |
| userId     | number | 是   | 否   | 应用状态发生变化的用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。   |
| appIndex<sup>12+</sup>   | number | 是   | 否   |  应用状态发生变化的应用分身索引。  |

## BundleChangedEvent

监听的事件类型。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：**  此接口为系统接口。

| 名称       | 说明             |
| ---------- | --------------- |
| add        | 监听应用安装事件。   |
| update     | 监听应用更新事件。   |
| remove     | 监听应用卸载事件。   |

## bundleMonitor.on

on(type: BundleChangedEvent, callback: Callback\<BundleChangedInfo>): void

注册监听应用的安装、卸载、更新。
>**说明:**
>
>该方法需要与[bundleMonitor.off](#bundlemonitoroff)配合使用，在组件、页面、应用的生命周期结束时，使用[bundleMonitor.off](#bundlemonitoroff)注销对应用的安装、卸载、更新等事件的监听。

**需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE

**系统接口：**  此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                       | 类型     | 必填 | 说明               |
| ---------------------------- | -------- | ---- | ------------------ |
| type| [BundleChangedEvent](js-apis-bundleMonitor-sys.md#bundlechangedevent)| 是   | 注册监听的事件类型。 |
| callback | callback\<BundleChangedInfo>| 是   | 注册监听的[回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
import { BusinessError } from '@ohos.base';

try {
    bundleMonitor.on('add', (bundleChangeInfo) => {
        console.info(`bundleName : ${bundleChangeInfo.bundleName} userId : ${bundleChangeInfo.userId}`);
	})
} catch (errData) {
    let message = (errData as BusinessError).message;
    let errCode = (errData as BusinessError).code;
    console.error(`errData is errCode:${errCode}  message:${message}`);
}
```

## bundleMonitor.off

off(type: BundleChangedEvent, callback?: Callback\<BundleChangedInfo>): void

注销监听应用的安装，卸载，更新。

**需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE

**系统接口：**  此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                       | 类型     | 必填 | 说明                                                       |
| ---------------------------- | -------- | ---- | ---------------------------------------------------------- |
| type| [BundleChangedEvent](js-apis-bundleMonitor-sys.md#bundlechangedevent)| 是   | 注销监听的事件类型。                                         |
| callback | callback\<BundleChangedInfo>| 否   | 注销监听的[回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，默认值：注销当前事件的所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
import { BusinessError } from '@ohos.base';

try {
    bundleMonitor.off('add');
} catch (errData) {
    let message = (errData as BusinessError).message;
    let errCode = (errData as BusinessError).code;
    console.error(`errData is errCode:${errCode}  message:${message}`);
}
```