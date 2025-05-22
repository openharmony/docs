# @ohos.multimedia.image (图片处理)(系统接口)

本模块提供图片处理效果，包括通过属性创建PixelMap、读取图像像素数据、读取区域内的图片数据等。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.image (图片处理)](js-apis-image.md)。

## 导入模块

```ts
import image from '@ohos.multimedia.image';
```

## DecodingOptions<sup>12+</sup>

图像解码设置选项。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称               | 类型                               | 可读 | 可写 | 说明             |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| resolutionQuality         | number                             | 是   | 是   | 画质效果等级。 |


## ResolutionQuality <sup>12+</sup>

枚举，画质效果等级类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| LOW     | 1     | 低画质效果，解码耗时短。<br/>此接口为系统接口。|
| MEDIUM             | 2    | 中等画质效果，解码耗时中等。<br/>此接口为系统接口。|
| HIGH             | 3    | 最高等级画质效果，解码耗时长。<br/>此接口为系统接口。|
