# multimedia子系统变更说明

## cl.multimedia.1 image接口Heif格式类型变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

1.  OH_PackingOptions_SetMimeType()接口Heif格式参数类型变更，此变更涉及应用适配。
      变更前：设置Heif格式图片mimeType传入参数为image/heif。
      变更后：设置Heif格式图片mimeType传入参数为image/heic。
     
 2. OH_PackingOptions_GetMimeType()接口Heif格式返回类型变更，此变更涉及应用适配。
      变更前：获取Heif格式图片mimeType为image/heif。
      变更后：获取Heif格式图片mimeType为image/heic。
      
 3. supportedFormats属性查询设备支持解码Heif格式返回类型变更，此变更涉及应用适配。
     变更前：查询设备支持的解码类型Heif格式返回值为image/heif。
     变更后：查询设备支持的解码类型Heif格式返回值为image/heic。
     
 4. supportedFormats属性查询设备支持编码Heif格式返回类型变更，此变更涉及应用适配。
     变更前：查询设备支持的编码类型Heif格式返回值为image/heif。
     变更后：查询设备支持的编码类型Heif格式返回值为image/heic。
     
 5. packing()接口Heif格式编码参数变更，此变更不涉及应用适配。
     变更前：Heif格式图片编码参数的mimeType类型为image/heif。
     变更后：Heif格式图片编码参数的mimeType类型为image/heif或者image/heic。
     
 6. OH_PackingOptions结构体Heif格式编码参数变更，此变更不涉及应用适配。
     变更前：Heif格式图片编码参数的mimeType类型为image/heif。
     变更后：Heif格式图片编码参数的mimeType类型为image/heif或者image/heic。

**起始API Level**

API 10

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

| API类型 | 所在d.ts/头文件 | 接口名 | 接口起始版本 |
|--|--|--|--|
| C API | image_packer_native.h | Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format) | 12 |
| C API | image_packer_native.h | Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions * options, Image_MimeType * format) | 12 |
| ArkTS API | @ohos.multimedia.image.d.ts |  imagePacker.supportedFormats: Array\<string> | 10 |
| ArkTS API | @ohos.multimedia.image.d.ts |  imageSource.supportedFormats: Array\<string> | 10 |
| ArkTS API | @ohos.multimedia.image.d.ts | imagePacker.packing() | 12 |
| C API | image_packer_native.h | OH_PackingOptions | 12 |

**适配指导**

1.调用OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)设置Heif格式图片mimeType时，需要将传入的format参数更新为image/heic。

2.调用OH_PackingOptions_GetMimeType(OH_PackingOptions *options, Image_MimeType *format)获取Heif格式图片mimeType时，返回的format为image/heic，开发者需检视应用的示例工程，根据实际情况修改。

3.调用supportedFormats查询设备的解码类型时，开发者调用行为不变，如果设备支持Heif类型，返回值将由image/heif变更为image/heic。

4.调用supportedFormats查询设备的编码类型时，开发者调用行为不变，如果设备支持Heif类型，返回值将由image/heif变更为image/heic。

5.调用imagePacker.packing()进行Heif图片编码时，开发者调用参数可以使用变更前的image/heif类型，也可以使用image/heic类型。

6.调用OH_PackingOptions进行Heif图片编码时，开发者调用参数可以使用变更前的image/heif类型，也可以使用image/heic类型。