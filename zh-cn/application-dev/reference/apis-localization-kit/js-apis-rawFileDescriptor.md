# RawFileDescriptor

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供rawfile文件所在hap的descriptor信息。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { resourceManager } from '@kit.LocalizationKit'
```

## RawFileDescriptor

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 名称     | 类型    | 只读   | 可选  | 说明           |
| ------ | ------  | ---- | ---- | ------------------ |
| fd     | number  | 否    | 否 | 文件描述符。 |
| offset | number  | 否    | 否 | 起始偏移量。      |
| length | number  | 否    | 否 | 文件长度。       |