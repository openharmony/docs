# multimedia子系统变更说明

## cl.multimedia.1 Image.ImageSource.DecodingOptionsForPicture接口的desiredAuxiliaryPictures属性系统能力变更

**访问级别**

公开接口

**变更原因**

接口DecodingOptionsForPicture与属性desiredAuxiliaryPictures归属的系统能力不一致，会影响对接口支持系统能力情况的判断，需要将desiredAuxiliaryPictures的SystemCapability中的SystemCapability.Multimedia.Image.Core改为SystemCapability.Multimedia.Image.ImageSource。

**变更影响**

此变更为不兼容变更。
对接口中属性的SystemCapability进行调整，对接口本身的使用方式无影响。

变更前：DecodingOptionsForPicture接口的系统能力要求为“SystemCapability.Multimedia.Image.Core”。

变更后：DecodingOptionsForPicture接口的系统能力要求为“SystemCapability.Multimedia.Image.ImageSource”。

**起始 API Level**

13

**变更发生版本**

从OpenHarmony 5.0.0.57版本开始。

**变更的接口/组件**

@ohos.multimedia.image中涉及修改的属性如下：

| 接口名| 接口说明 | 属性名 | 属性说明 |
| -------- | -------- | -------- | -------- |
|image.ImageSource.DecodingOptionsForPicture|图像解码设置选项|desiredAuxiliaryPictures|设置AuxiliaryPicture类型，默认解码所有AuxiliaryPicture类型。|


**适配指导**

接口中属性的SystemCapability正常应该与对应接口的SystemCapability一致。但如果代码中涉及调用canIUse()方法对本次变更涉及接口支持情况进行判断，则应修改canIUse()方法传入的SystemCapability，判断设备是否支持图片源解码解析能力需使用canIUse("SystemCapability.Multimedia.Image.ImageSource")。

## cl.multimedia.2 image.Component.OH_AuxiliaryPictureNative_SetInfo()接口行为变更

**访问级别**

公开接口

**变更原因**

通过OH_AuxiliaryPictureNative_SetInfo设置辅助图信息时，会将辅助图信息中的size、pixelFormat等信息同步到pixelMap的ImageInfo中，需要对size和pixelFormat信息做合法校验，防止对pixelMap像素数据信息的越界访问。

**变更影响**

该变更为不兼容变更。

变更前：OH_AuxiliaryPictureNative_SetInfo()接口设置辅助图信息时，对pixelFormat没有校验，都可以设置成功。

变更后：OH_AuxiliaryPictureNative_SetInfo()接口设置辅助图信息时，若将存储像素字节数变大，则设置不成功，返回错误码401。例如将pixelFormat从RGBA_8888设置为RGBA_F16。

**起始 API Level**

13

**变更发生版本**

从OpenHarmony 5.0.0.57版本开始。

**变更的接口/组件**

| API类型 | 所在头文件 | 接口名 | 接口起始版本 |
|--|--|--|--|
| C API | picture_native.h | Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo *info) | 13 |

**适配指导**

设置辅助图信息时，如果将存储像素字节数变大，则设置不成功，返回错误码401。

```c++
#include <hilog/log.h>
#include <multimedia/image_framework/image/image_native.h>
#include <multimedia/image_framework/image/image_packer_native.h>
#include <multimedia/image_framework/image/image_source_native.h>
#include <multimedia/image_framework/image/picture_native.h>
Image_ErrorCode SetAuxiliaryPictureInfoTest() {
    size_t filePathSize = 1024;
    OH_ImageSourceNative* imageSource = nullptr;
    Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreateFromUri("test.jpg", filePathSize, &imageSource);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || imageSource == nullptr) {
        OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_CreateFromUri failed.");
    }
    OH_DecodingOptionsForPicture *opts = nullptr;
    OH_DecodingOptionsForPicture_Create(&opts);
    OH_PictureNative *picture = nullptr;
    image_ErrorCode = OH_ImageSourceNative_CreatePicture(imageSource, opts, &picture);
    OH_ImageSourceNative_Release(imageSource);
    OH_DecodingOptionsForPicture_Release(opts);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || picture == nullptr) {
        OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_CreatePicture failed. image_ErrorCode=%{public}d", image_ErrorCode);
    }
    OH_AuxiliaryPictureNative *auxiliaryPicture = nullptr;
    image_ErrorCode = OH_PictureNative_GetAuxiliaryPicture(
        picture, Image_AuxiliaryPictureType::AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP, &auxiliaryPicture);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || auxiliaryPicture == nullptr) {
       OH_LOG_ERROR(LOG_APP, "OH_PictureNative_GetAuxiliaryPicture failed. image_ErrorCode=%{public}d", image_ErrorCode);
    }
    OH_AuxiliaryPictureInfo *auxInfo = nullptr;
    image_ErrorCode = OH_AuxiliaryPictureNative_GetInfo(auxiliaryPicture, &auxInfo);
    PIXEL_FORMAT newPixelFormat = PIXEL_FORMAT_RGBA_F16;
    OH_AuxiliaryPictureInfo_SetPixelFormat(auxInfo, newPixelFormat);
    image_ErrorCode = OH_AuxiliaryPictureNative_SetInfo(auxiliaryPicture, auxInfo);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || auxInfo == nullptr) {
       OH_LOG_ERROR(LOG_APP, "OH_AuxiliaryPictureNative_SetInfo failed. image_ErrorCode=%{public}d", image_ErrorCode);
    }
    OH_AuxiliaryPictureInfo_Release(auxInfo);
    OH_AuxiliaryPictureNative_Release(auxiliaryPicture);
    return IMAGE_SUCCESS;
}
```

## cl.multimedia.3 image.Component.setAuxiliaryPictureInfo接口行为变更

**访问级别**

公开接口

**变更原因**

通过setAuxiliaryPictureInfo设置辅助图信息时，会将辅助图信息中的size、pixelFormat等信息同步到pixelMap的ImageInfo中，需要对size和pixelFormat信息做合法校验，防止对pixelMap像素数据信息的越界访问。

**变更影响**

该变更为不兼容变更。

变更前：setAuxiliaryPictureInfo()接口设置辅助图信息时，对pixelFormat没有校验，都可以设置成功。

变更后：setAuxiliaryPictureInfo()接口设置辅助图信息时，若将存储像素字节数变大，则设置不成功，返回错误码401。例如将pixelFormat从RGBA_8888设置为RGBA_F16。

**起始 API Level**

13

**变更发生版本**

从OpenHarmony 5.0.0.57版本开始。

**变更的接口/组件**

| API类型 | 所在d.ts文件 | 接口名 | 接口起始版本 |
|--|--|--|--|
| ArkTS API | @ohos.multimedia.image.d.ts | setAuxiliaryPictureInfo(info: AuxiliaryPictureInfo): void | 13 |

**适配指导**

设置辅助图信息时，如果将存储像素字节数变大，则设置不成功，返回错误码401。

```ts
import { image } from '@kit.ImageKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

async function setAuxiliaryPitcutreInfo() {
  const array: ArrayBuffer = new ArrayBuffer(100);
  let imageSource: image.ImageSource = image.createImageSource(array);
  let options: image.DecodingOptionsForPicture = {
    desiredAuxiliaryPictures: [image.AuxiliaryPictureType.FRAGMENT_MAP]
  };
  try {
    let picture: image.Picture = await imageSource.createPicture(options);
    let auxiliaryPicture = picture.getAuxiliaryPicture(image.AuxiliaryPictureType.FRAGMENT_MAP);
    let originInfo = auxiliaryPicture?.getAuxiliaryPictureInfo();
    console.info("CreatePicture", 'originInfo = ' + JSON.stringify(originInfo));
    let changedInfo: image.AuxiliaryPictureInfo = {
      auxiliaryPictureType: image.AuxiliaryPictureType.FRAGMENT_MAP,
      size: { height: 410, width: 3072 },
      rowStride: 3072 * 8,
      pixelFormat: image.PixelMapFormat.RGBA_F16,
      colorSpace: colorSpaceManager.create(colorSpaceManager.ColorSpace.DCI_P3),
    };
    try {
      auxiliaryPicture?.setAuxiliaryPictureInfo(changedInfo);
      console.info("CreatePicture", `changedInfo us ${changedInfo}`);
    } catch (error) {
      console.error("CreatePicture", `setAuxiliaryPictureInfo, error.code is ${error.code}, error.message is ${error.message}`);
    }
  } catch (err) {
    console.error("CreatePicture", ' decode Picture failed !!!');
  }
}
```
