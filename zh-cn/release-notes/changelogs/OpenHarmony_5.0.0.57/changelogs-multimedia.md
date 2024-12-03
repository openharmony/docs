# multimedia子系统变更说明

## cl.multimedia.1 image.Component.OH_AuxiliaryPictureNative_SetInfo()接口行为变更。

**访问级别**

公开接口

**变更原因**

通过OH_AuxiliaryPictureNative_SetInfo设置辅助图信息时，会将辅助图信息中的size、pixelFormat等信息同步到pixelMap的ImageInfo中，需要对size和pixelFormat信息做合法校验，防止对pixelMap像素数据信息的越界访问。

**变更影响**

该变更为不兼容变更。

变更前：

OH_AuxiliaryPictureNative_SetInfo()接口设置辅助图信息时，对pixelFormat没有校验，都可以设置成功。

变更后：

OH_AuxiliaryPictureNative_SetInfo()接口设置辅助图信息时，若将存储像素字节数变大，则设置不成功，返回错误码401。例如将pixelFormat从RGBA_8888设置为RGBA_F16。

**起始 API Level**

13

**变更发生版本**

从OpenHarmony [5.0.0.57](http://5.0.0.57)版本开始。

**变更的接口/组件**

picture_native.h下的接口： 

Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,    OH_AuxiliaryPictureInfo *info);

**适配指导**

设置辅助图信息时，如果将存储像素字节数变大，则设置不成功，返回错误码401。

```c++
	char filePath[1024];
    size_t filePathSize;
	napi_get_value_string_utf8(env, args[0], filePath, 1024, &filePathSize);
    OH_ImageSourceNative* imageSource = nullptr;
    Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreateFromUri(filePath, filePathSize, &imageSource);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || imageSource == nullptr) {
        H_LOGE("OH_ImageSourceNative_CreateFromUri failed.");
    }
    OH_DecodingOptionsForPicture* opts = nullptr;
    OH_DecodingOptionsForPicture_Create(&opts);
    OH_PictureNative* picture = nullptr;
    image_ErrorCode = OH_ImageSourceNative_CreatePicture(imageSource, opts, &picture);
    OH_ImageSourceNative_Release(imageSource);
    OH_DecodingOptionsForPicture_Release(opts);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || picture == nullptr) {
        H_LOGE("OH_ImageSourceNative_CreatePicture failed. image_ErrorCode=%d", image_ErrorCode);
    }
    OH_PixelmapNative* pixelmap = nullptr;
    image_ErrorCode = OH_PictureNative_GetMainPixelmap(picture, &pixelmap);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || pixelmap == nullptr) {
        H_LOGE("OH_PictureNative_GetMainPixelmap failed! image_ErrorCode=%d", image_ErrorCode);
    }
    uint32_t positionx = 0;
    uint32_t positionY = 3686;
    uint32_t width = 3072;
    uint32_t height = 410;
    Image_Region image_Region ={.x= positionx, .y = positionY, .width = width, .height = height};
    image_ErrorCode = OH_PixelmapNative_Crop(pixelmap, &image_Region);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS) {
        H_LOGE("OH_PixeLmapNative_Crop failed. image_ErrorCode=%d", image_ErrorCode);
    }
    uint32_t PIXEL_BYTES_FOUR = 4;
    unsigned char *data = new unsigned char[width * height * PIXEL_BYTES_FOUR];
    size_t bufferSize = width * height * PIXEL_BYTES_FOUR;

    image_ErrorCode = OH_PixelmapNative_ReadPixels(pixelmap, data, &bufferSize);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS) {
        H_LOGE("OH_PixeLmapNative_ReadPixels fail! image_ErrorCode=%d", image_ErrorCode);
        delete[] data;
    }
    OH_PixelmapNative_Release(pixelmap);

    size_t dataLength = width * height * PIXEL_BYTES_FOUR;
    Image_Size size = {.width = width,.height = height};
    OH_AuxiliaryPictureNative* auxiliaryPicture = nullptr;
    image_ErrorCode = OH_AuxiliaryPictureNative_Create(
    data, dataLength, &size, Image_AuxiliaryPictureType::AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP, &auxiliaryPicture);
    delete[] data;
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || auxiliaryPicture == nullptr) {
        H_LOGE("OH_AuxiliaryPictureNative_Create fail! image_ErrorCode=%d", image_ErrorCode);
    }

    OH_AuxiliaryPictureInfo *auxInfo;
    image_ErrorCode = OH_AuxiliaryPictureInfo_Create(&auxInfo);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS || auxInfo == nullptr) {
        H_LOGE("OH_AuxiliaryPictureInfo_Create FRAGMENT_MAP fail! image_ErrorCode=%d", image_ErrorCode);
    }

    image_ErrorCode = OH_AuxiliaryPictureInfo_SetPixelFormat(auxInfo, PIXEL_FORMAT_RGBA_F16);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS) {
    H_LOGE("OH_AuxiliaryPictureInfo_SetSize FRAGMENT_MAP fail! image_ErrorCode=%d", image_ErrorCode);
    OH_AuxiliaryPictureInfo_Release(auxInfo);
    }
    image_ErrorCode = OH_AuxiliaryPictureNative_SetInfo(auxiliaryPicture, auxInfo);
    OH_AuxiliaryPictureInfo_Release(auxInfo);
    if (image_ErrorCode != Image_ErrorCode::IMAGE_SUCCESS) {
        H_LOGE("OH_AuxiliaryPictureNative_SetInfo FRAGMENT_MAP fail! image_ErrorCode=%d", image_ErrorCode);
    }
```

## cl.multimedia.2 image.Component.setAuxiliaryPictureInfo接口行为变更。

**访问级别**

公开接口

**变更原因**

通过setAuxiliaryPictureInfo设置辅助图信息时，会将辅助图信息中的size、pixelFormat等信息同步到pixelMap的ImageInfo中，需要对size和pixelFormat信息做合法校验，防止对pixelMap像素数据信息的越界访问。

**变更影响**

该变更为不兼容变更。

变更前：

setAuxiliaryPictureInfo()接口设置辅助图信息时，对pixelFormat没有校验，都可以设置成功。

变更后：

setAuxiliaryPictureInfo()接口设置辅助图信息时，若将存储像素字节数变大，则设置不成功，返回错误码401。例如将pixelFormat从RGBA_8888设置为RGBA_F16。

**起始 API Level**

13

**变更发生版本**

从OpenHarmony [5.0.0.57](http://5.0.0.57)版本开始。

**变更的接口/组件**

@ohos.multimedia.image.d.ts中涉及的接口如下： 

setAuxiliaryPictureInfo(info: AuxiliaryPictureInfo): void

**适配指导**

设置辅助图信息时，如果将存储像素字节数变大，则设置不成功，返回错误码401。

```ts
const context = getContext(this);
const resourceMgr = context.resourceManager;
const rawFile = await resourceMgr.getRawFileContent('JpegFragmentMap.jpg');
let imageSource = image.createImageSource(rawFile.buffer as ArrayBuffer);
let options: image.DecodingOptionsForPicture = {
  desiredAuxiliaryPictures: [image.AuxiliaryPictureType.FRAGMENT_MAP]
};
try {
  let pictureObj = await imageSource.createPicture(options);
  let mainPixelMap = pictureObj.getMainPixelmap();
  let info01 = await mainPixelMap.getImageInfo();
  console.info(TAG, ' decode Picture success. height: ', info01.size.height, 'width: ', info01.size.width);
  try {
    let region: image.Region = { x: 0, y: 0, size: { height: 2160, width: 3840 } };
    mainPixelMap.crop(region);
    let info02 = await mainPixelMap.getImageInfo();
    console.info(TAG, ' crop main pixelMap success.height: ', info02.size.height, 'width: ', info02.size.width);
    try {
      const area: image.PositionArea = {
        pixels: new ArrayBuffer(2160 * 3840),
        offset: 0,
        stride: 2160 * 3840,
        region: { size: { height: 2160, width: 3840 }, x: 0, y: 0 }
      };
      let size: Size = { height: 2160 * 3, width: 3840 * 3 }
      mainPixelMap.readPixels(area)
      let auxPictureObj = image.createAuxiliaryPicture(area.pixels, size, image.AuxiliaryPictureType.FRAGMENT_MAP);
      let info: image.AuxiliaryPictureInfo = {
        auxiliaryPictureType: image.AuxiliaryPictureType.FRAGMENT_MAP,
        size: { height: 2160, width: 3840 },
        rowStride: 2,
        pixelFormat: image.PixelMapFormat.RGBA_F16,
        colorSpace: await colorSpaceManager.create(colorSpaceManager.ColorSpace.DCI_P3),
      };
      auxPictureObj.setAuxiliaryPictureInfo(info);

      console.info(TAG, ' create auxPicture success.');
    } catch (err) {
      console.error(TAG, ' create auxPicture failed !!!');
    }
  } catch (err) {
    console.error(TAG, ' crop main pixelMap failed !!!');
  }
} catch (err) {
  console.error(TAG, ' decode Picture failed !!!');
}
```
