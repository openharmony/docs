# CustomizeData

自定义元数据。

> **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CustomizeData<sup>(deprecated)</sup>

> 从API version 9开始不再维护，建议使用[Metadata](js-apis-bundleManager-metadata.md)替代。

**系统能力**:  SystemCapability.BundleManager.BundleFramework



| 名称               | 类型   | 只读 | 可选 | 说明             |
| ------------------ | ------ | ---- | ---- | ---------------- |
| name               | string | 否   | 否   | 标识自定义数据项的键名称。 |
| value              | string | 否   | 否   | 标识自定义数据项的值名称。   |
| extra<sup>8+</sup> | string | 否   | 否   | 标识用户自定义数据格式，标签值为标识该数据的资源的索引值。       |