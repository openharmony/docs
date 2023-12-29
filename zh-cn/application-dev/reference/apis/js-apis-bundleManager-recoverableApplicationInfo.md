# RecoverableApplicationInfo

预置应用被卸载后可以恢复的预置应用信息，通过接口[bundleManager.getRecoverableApplicationInfo](js-apis-bundleManager.md)获取。

> **说明：**
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## RecoverableApplicationInfo

预置应用被卸载后可以恢复的预置应用信息。

**系统接口：** 此接口为系统接口。

**系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称             | 类型                           | 可读 | 可写 | 说明                   |
| ---------------- | ------------------------------ | ---- | ---- | ---------------------- |
| bundleName       | string                         | 是   | 否   | 应用包的名称。       |
| moduleName       | string                         | 是   | 否   | 模块名称。 |
| labelId          | number                         | 是   | 否   | 模块标签的资源ID值。     |
| iconId           | number                         | 是   | 否   | 模块图标的资源ID值。    |