# 图片框架Changelog

## cl.image.1 ImageInfo对象mimeType返回值变更

**访问级别**

公开接口

**变更原因**

该接口为图片信息查询接口，当前返回值与实际不符。
- 当处理raw格式图片时，实际mimeType应返回实际格式。因当前实际解码为raw格式图片的"previewImage"或"JpgFromRaw"字段，因此错误返回"image/jpeg"。
- 当处理icon格式图片时，未使用标准名称返回。

**变更影响**

此变更涉及应用适配。

| 实际格式 | 变更前返回 | 变更后返回 | 解码支持情况|编码支持情况|
| --- | --- | --- | --- | --- |
|jpeg|image/jpeg|image/jpeg|支持|支持|
|icon|image/ico|image/x-icon|支持|不支持|
|dng|image/jpeg|image/x-adobe-dng|支持|不支持|
|cr2|image/jpeg|image/x-canon-cr2|支持解码预览图|不支持|
|raf|image/jpeg|image/x-fuji-raf|支持解码预览图|不支持|
|nef|image/jpeg|image/x-nikon-nef|支持解码预览图|不支持|
|nrw|image/jpeg|image/x-nikon-nrw|支持解码预览图|不支持|
|orf|image/jpeg|image/x-olympus-orf|支持解码预览图|不支持|
|rw2|image/jpeg|image/x-panasonic-rw2|支持解码预览图|不支持|
|pef|image/jpeg|image/x-pentax-pef|支持解码预览图|不支持|
|srw|image/jpeg|image/x-samsung-srw|支持解码预览图|不支持|
|arw|image/jpeg|image/x-sony-arw|支持解码预览图|不支持|


**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

ImageInfo对象mimeType返回值变更。

**适配指导**

图片信息查询接口返回值变更，调用方式无需改变。
```js
const context: Context = getContext(this);
//此处'test.dng'仅作示例，请开发者自行替换。否则imageSource会创建失败，导致后续无法正常执行。
const path: string = context.filesDir + "/test.dng";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
if (imageSourceApi != undefined) {
  imageSourceApi.getImageInfo().then((imageInfo: image.ImageInfo) => {
    console.info("Succeeded in obtaining the image mimeType information.");
    // 调用方式无需修改，返回值修改后因支持识别实际raw格式，需要将此处判断更新。
    if (imageInfo.mimeType == "image/x-adobe-dng") {
      console.info("Image mimeType is image/x-adobe-dng.");
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to obtain the image information. code is ${error.code}, message is ${error.message}`);
  })
}
```