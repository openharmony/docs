# Resource

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

本模块提供资源相关信息，包括应用包名、应用模块名、资源ID等。

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

| 名称         | 类型     | 只读   | 可选  |说明          |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | 否    | 否 | 应用包名。 |
| moduleName | string | 否    | 否 | 应用模块名。 |
| id         | number | 否    | 否 | 资源ID，取值如下：<br/>-&nbsp;应用资源区间：[0x01000000, 0x06FFFFFF] 和 [0x08000000, 0xFFFFFFFF]，表示应用自身的资源ID。<br/>-&nbsp;系统资源区间：[0x07000000, 0x07FFFFFF]，表示系统预置的资源ID。 |
| params     | any[] | 否   | 是 | 资源参数，包括：资源名（string类型）、格式化接口替换值（按占位符顺序提供string或number）、复数接口量词（number类型，表示数量）。格式化接口的替换值用于字符串格式化时的参数替换，复数接口的量词用于选择多语言环境下的复数形式。      |
| type       | number | 否    | 是 | 资源类型，取值如下：<br/>-&nbsp;10001：color<br/>-&nbsp;10002：float<br/>-&nbsp;10003：string<br/>-&nbsp;10004：plural<br/>-&nbsp;10005：boolean<br/>-&nbsp;10006：intarray<br/>-&nbsp;10007：integer<br/>-&nbsp;10008：pattern<br/>-&nbsp;10009：strarray<br/>-&nbsp;20000：media<br/>-&nbsp;30000：rawfile<br/>-&nbsp;40000：symbol |