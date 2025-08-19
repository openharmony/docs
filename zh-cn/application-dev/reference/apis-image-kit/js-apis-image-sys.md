# @ohos.multimedia.image (图片处理)(系统接口)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

本模块提供图片处理效果，包括通过属性创建PixelMap、读取图像像素数据、读取区域内的图片数据等。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.image (图片处理)](arkts-apis-image.md)。

## 导入模块

```ts
import image from '@ohos.multimedia.image';
```

## DecodingOptions<sup>12+</sup>

图像解码设置选项。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称               | 类型              | 只读 | 可选 | 说明             |
| ----------------- | ----------------- | ---- | ---- | ---------------- |
| resolutionQuality | [ResolutionQuality](#resolutionquality12) | 否   | 是   | 画质效果等级。 |

## ResolutionQuality<sup>12+</sup>

枚举，画质效果等级类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| LOW     | 1     | 低画质效果，解码耗时短。<br/>此接口为系统接口。|
| MEDIUM             | 2    | 中等画质效果，解码耗时中等。<br/>此接口为系统接口。|
| HIGH             | 3    | 最高等级画质效果，解码耗时长。<br/>此接口为系统接口。|

## image.createPictureByHdrAndSdrPixelMap<sup>20+</sup>

createPictureByHdrAndSdrPixelMap(hdrPixelMap: PixelMap, sdrPixelMap: PixelMap): Promise\<Picture>

根据HDR PixelMap和SDR PixelMap创建Picture对象。系统将使用HDR和SDR PixelMap生成一个增益图（gainmap），返回的Picture对象将包含SDR PixelMap和生成的gainmap PixelMap，像素格式为RGBA8888。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名       | 类型                | 必填 | 说明             |
| ------------ | ------------------- | ---- | ---------------- |
| hdrPixelmap | [PixelMap](arkts-apis-image-PixelMap.md#interface-pixelmap) | 是   | HDR PixelMap，位深16bit或10bit，像素格式为FP16/RGBA1010102/YCBCR_P010，色彩空间是BT2020_HLG。 |
| sdrPixelmap | [PixelMap](arkts-apis-image-PixelMap.md#interface-pixelmap) | 是   | SDR PIxelMap，位深8bit，像素格式为RGBA8888/NV21，色彩空间是P3。 |

**返回值：**

| 类型               | 说明              |
| ------------------ | ----------------- |
|Promise\<[Picture](arkts-apis-image-Picture.md#interface-picture)> | 返回Picture包含sdr和gainmap，像素格式为RGBA8888。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 7600201      | Unsupported operation. HdrPixelMap's PixelMapFormat is not RGBA_F16\RGBA_1010102\YCBCR_P010, or its color space is not BT2020_HLG. Or sdrPixelMap's PixelMapFormat is not RGBA_8888\NV21\NV12, or its color space is not P3. |

**示例：**

```ts
import image from '@ohos.multimedia.image';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

async function CreatePictureTest(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg"); // SDR
  let imageSource: image.ImageSource = image.createImageSource(rawFile);
  let options1: image.DecodingOptions = {
    desiredDynamicRange : image.DecodingDynamicRange.SDR,
  }
  let options2: image.DecodingOptions = {
    desiredDynamicRange : image.DecodingDynamicRange.HDR, // 通过AIHDR将SDR解码为HDR。
  }
  let sdrPixelMap = await imageSource.createPixelMap(options1);
  let hdrPixelMap = await imageSource.createPixelMap(options2);

  // 获取计算生成的gainmap并编码。
  let picture: image.Picture = await image.createPictureByHdrAndSdrPixelMap(hdrPixelMap, sdrPixelMap);
  if (picture != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }
  const imagePackerApi = image.createImagePacker();
  let packOpts : image.PackingOption = { format : "image/jpeg", quality: 98};
  packOpts.desiredDynamicRange = image.PackingDynamicRange.AUTO;
  const path: string = context.filesDir + "/hdr-test.jpg";
  let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  imagePackerApi.packToFile(picture, file.fd, packOpts).then(() => {
  }).catch((error : BusinessError) => {
    console.error('Failed to pack the image. And the error is: ' + error);
  })
}
```