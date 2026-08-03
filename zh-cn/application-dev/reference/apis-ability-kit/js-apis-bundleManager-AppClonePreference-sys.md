# AppClonePreference (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @HelloCrease-->

应用分身偏好设置，用于配置应用启动时主应用和分身应用的选择策略，通过接口[bundleManager.getAppClonePreference](js-apis-bundleManager-sys.md#bundlemanagergetappclonepreference)获取，并通过[bundleManager.setAppClonePreference](js-apis-bundleManager-sys.md#bundlemanagersetappclonepreference)设置。

**起始版本：** 26.0.0

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## AppClonePreferenceMode

应用分身偏好设置的模式。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 值 | 说明 |
| --------------- | --- | --- |
| ALWAYS_ASK        | 0   | 每次启动应用时都询问用户选择主应用或分身应用。 |
| MAIN_APP          | 1   | 默认使用主应用。 |
| CLONE_APP         | 2   | 默认使用分身应用。 |

## AppClonePreference

应用分身偏好设置，用于配置应用启动时主应用和分身应用的选择策略。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| mode | [AppClonePreferenceMode](#appclonepreferencemode)         | 否   | 否   | 表示应用分身偏好设置的模式。 |
| appIndex | number         | 否   | 是   | 表示应用分身索引。<br>当mode取值为AppClonePreferenceMode.CLONE_APP时为必填参数，用于指定具体的分身应用，取值范围为1~5的整数（系统最多支持5个分身）。   |
