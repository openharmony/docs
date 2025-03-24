# Resource

本模块提供资源相关信息，包括应用包名、应用模块名、资源id等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { resourceManager } from '@kit.LocalizationKit'
```

## Resource

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称         | 类型     | 可读   | 可写  |说明          |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | 是    | 否 | 应用的bundle名称。 |
| moduleName | string | 是    | 否 | 应用的module名称。 |
| id         | number | 是    | 否 | 资源的id值。      |
| params     | any[] | 是    | 否 | 其他资源参数（可选）。      |
| type       | number | 是    | 否 | 资源的类型（可选）。      |