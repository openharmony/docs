# BundleResourceInfo (系统接口)

应用配置的图标和名称信息，可以通过[getBundleResourceInfo](js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo)获取。

> **说明：**
>
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## BundleResourceInfo

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**系统接口：** 此接口为系统接口。

| 名称                      | 类型   | 只读 | 可选 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| bundleName              | string | 是   | 否   | 应用的包名。 |
| icon              | string | 是   | 否   | 应用图标，为Base64编码格式。  |
| label                     | string | 是   | 否   | 应用名称。 |
| drawableDescriptor<sup>12+</sup>                     | [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor-sys.md) | 是   | 否   | 应用图标的drawableDescriptor对象。 |
| appIndex<sup>12+</sup>           | number | 是   | 否   | 应用分身Id。 |
