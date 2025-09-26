# SendableResource

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供SendableResource资源相关信息，包括应用包名、应用模块名、资源类型等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { resourceManager } from '@kit.LocalizationKit';
```

## SendableResource

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称         | 类型     | 只读   | 可选  |说明          |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | 否    | 否 | 应用的bundle名称。 |
| moduleName | string | 否    | 否 | 应用的module名称。 |
| id         | number | 否    | 否 | 资源的id值。      |
| params     | collections.Array<string \| number> | 否    | 是 | 其他资源参数，包括资源名、格式化接口的替换值、复数接口的量词。      |
| type       | number | 否    | 是 | 资源的类型。      |