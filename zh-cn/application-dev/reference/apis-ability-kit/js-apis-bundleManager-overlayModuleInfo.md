# OverlayModuleInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

OverlayModuleInfo信息，可以通过[overlay.getOverlayModuleInfo](js-apis-overlay.md#overlaygetoverlaymoduleinfo)接口获取当前应用中具有overlay特征模块的OverlayModuleInfo信息。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

``` ts
import { overlay } from '@kit.AbilityKit';
```

## OverlayModuleInfo

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称                  | 类型                                                | 只读 | 可选 | 说明                                            |
| --------------------- | ---------------------------------------------------| ---- | ---- | ---------------------------------------------- |
| bundleName            | string                                             | 是   | 否   | overlay特征模块所属应用的bundle名称。           |
| moduleName            | string                                             | 是   | 否   | overlay特征模块名称。                       |
| targetModuleName      | string                                             | 是   | 否   | overlay特征模块作用目标的模块名称，表示当前overlay包的资源需要替换生效的模块名称。        |
| priority              | number                                             | 是   | 否   | overlay特征模块的优先级。取值为整数，取值范围：[1, 100]，数值越大优先级越高。    |
| state                 | number                                             | 是   | 否   | overlay特征模块的禁用启用状态。取值为整数，取值范围：[0, 2]，0代表禁用状态，1代表启用状态，2代表无效状态。 |