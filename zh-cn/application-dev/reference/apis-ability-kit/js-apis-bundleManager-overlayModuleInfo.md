# OverlayModuleInfo

OverlayModuleInfo信息，可以通过[overlay.getOverlayModuleInfo](js-apis-overlay.md#overlaygetoverlaymoduleinfo)获取当前应用中overlay特征module的OverlayModuleInfo信息。

> **说明：**
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## OverlayModuleInfo

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称                  | 类型                                                | 只读 | 可选 | 说明                                            |
| --------------------- | ---------------------------------------------------| ---- | ---- | ---------------------------------------------- |
| bundleName            | string                                             | 是   | 否   | overlay特征module所属的应用的bundle名称。           |
| moduleName            | string                                             | 是   | 否   | overlay特征module的名称。                       |
| targetModuleName      | string                                             | 是   | 否   | overlay特征module指定的目标module的名称。        |
| priority              | number                                             | 是   | 否   | overlay特征module的优先级。取值为整数，取值范围1 ~ 100，数值越大优先级越高。    |
| state                 | number                                             | 是   | 否   | overlay特征module的[禁用使能状态](js-apis-overlay.md#overlaysetoverlayenabled)。0代表禁用状态，1代表使能状态。                       |