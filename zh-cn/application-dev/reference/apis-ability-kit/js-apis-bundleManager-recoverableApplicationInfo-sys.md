# RecoverableApplicationInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

预置应用被卸载后可以恢复的预置应用信息，通过接口[bundleManager.getRecoverableApplicationInfo](./js-apis-bundleManager-sys.md#bundlemanagergetrecoverableapplicationinfo11)获取。

> **说明：**
>
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## RecoverableApplicationInfo

预置应用被卸载后可以恢复的预置应用信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称             | 类型                           | 只读 | 可选 | 说明                   |
| ---------------- | ------------------------------ | ---- | ---- | ---------------------- |
| bundleName       | string                         | 是   | 否   | 应用包的名称。       |
| moduleName       | string                         | 是   | 否   | 模块名称。 |
| labelId          | number                         | 是   | 否   | 模块标签的资源ID值。     |
| iconId           | number                         | 是   | 否   | 模块图标的资源ID值。    |
| systemApp<sup>12+</sup>       | boolean                        | 是   | 否   | 标识应用是否为系统应用，取值为true表示系统应用，取值为false表示非系统应用。  |
| bundleType<sup>12+</sup>       |[BundleType](js-apis-bundleManager.md#bundletype)             | 是   | 否   | 标识应用类型。                                |
| codePaths<sup>12+</sup>        | Array\<string>                 | 是   | 否   | 应用程序的安装目录。          |