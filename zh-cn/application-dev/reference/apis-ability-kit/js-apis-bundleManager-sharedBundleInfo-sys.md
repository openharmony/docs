# SharedBundleInfo (系统接口)

共享包信息，通过接口[bundleManager.getSharedBundleInfo](js-apis-bundleManager-sys.md#bundlemanagergetsharedbundleinfo10)获取。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## SharedBundleInfo

 共享包信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称             | 类型                           | 只读 | 可选 | 说明                   |
| ---------------- | ------------------------------ | ---- | ---- | ---------------------- |
| name             | string                         | 是   | 否   | 应用共享包名称。       |
| compatiblePolicy | bundleManager.[CompatiblePolicy](js-apis-bundleManager.md#compatiblepolicy10) | 是   | 否   | 共享包兼容策略的类型。 |
| sharedModuleInfo | Array\<SharedModuleInfo>       | 是   | 否   | 应用共享模块信息。     |

## SharedModuleInfo

共享模块信息。

 **系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称          | 类型   | 只读 | 可选 | 说明                       |
| ------------- | ------ | ---- | ---- | -------------------------- |
| name          | string | 是   | 否   | 共享包模块名称。           |
| versionCode   | number | 是   | 否   | 共享包的版本号。           |
| versionName   | string | 是   | 否   | 共享包的版本文本描述信息。 |
| description   | string | 是   | 否   | 共享包的模块描述信息。     |
| descriptionId | number | 是   | 否   | 共享包描述的资源id值。     |
