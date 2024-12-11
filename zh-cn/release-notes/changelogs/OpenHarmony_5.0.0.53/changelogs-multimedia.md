# multimedia子系统变更说明

## cl.multimedia.1 image.Component.OH_PackingOptions_SetMimeType()接口Heif格式参数类型变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

该变更为不兼容变更。

变更前：设置Heif格式图片mimeType传入参数为image/heif。

变更后：设置Heif格式图片mimeType传入参数为image/heic。

**起始API Level**

API 12

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

image_paker_native.h下的接口：

Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)

**适配指导**

调用OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)设置Heif格式图片mimeType时，需要将传入的format参数更新为image/heic。


## cl.multimedia.2 image.Component.OH_PackingOptions_GetMimeType()接口Heif格式返回类型变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

该变更为不兼容变更。

变更前：获取Heif格式图片mimeType为image/heif。

变更后：获取Heif格式图片mimeType为image/heic。

**起始API Level**

API 12

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

image_paker_native.h下的接口：

Image_ErrorCode OH_PackingOptions_GetMimeType (OH_PackingOptions * options, Image_MimeType * format)

**适配指导**

调用OH_PackingOptions_GetMimeType(OH_PackingOptions *options, Image_MimeType *format)获取Heif格式图片mimeType时，返回的format为image/heic，开发者需检视应用的示例工程，根据实际情况修改。


## cl.multimedia.3 image.Component.supportedFormats属性查询设备支持解码Heif格式返回类型变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

该变更为不兼容变更。

变更前：查询设备支持的解码类型Heif格式返回值为image/heif。

变更后：查询设备支持的解码类型Heif格式返回值为image/heic。

**起始API Level**

API 10

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

/interface/sdk-js/api/@ohos.multimedia.image.d.ts下的属性：

image.Component.readonly supportedFormats: Array\<string>

**适配指导**

调用该属性查询设备的解码类型时，开发者调用行为不变，如果设备支持Heif类型，返回值将由image/heif变更为image/heic。


## cl.multimedia.4 image.Component.supportedFormats属性查询设备支持编码Heif格式返回类型变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

该变更为不兼容变更。

变更前：查询设备支持的编码类型Heif格式返回值为image/heif。

变更后：查询设备支持的编码类型Heif格式返回值为image/heic。

**起始API Level**

API 10

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

/interface/sdk-js/api/@ohos.multimedia.image.d.ts下的属性：

image.Component.readonly supportedFormats: Array\<string>

**适配指导**

调用该属性查询设备的编码类型时，开发者调用行为不变，如果设备支持Heif类型，返回值将由image/heif变更为image/heic。


## cl.multimedia.5 image.Component.packing()接口Heif格式编码参数变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

该变更为兼容性变更。

变更前：Heif格式图片编码参数的mimeType类型为image/heif。

变更后：Heif格式图片编码参数的mimeType类型为image/heif或者image/heic。

**起始API Level**

API 12

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

/interface/sdk-js/api/@ohos.multimedia.image.d.ts下的接口：

image.Component.packing()

**适配指导**

在调用该接口进行Heif图片编码时，开发者调用参数可以使用变更前的image/heif类型，也可以使用image/heic类型。


## cl.multimedia.6 image.Component.OH_PackingOptions结构体Heif格式编码参数变更

**访问级别**

公开接口

**变更原因**

相机Heif编码时，使用图片标准定义image/heic参数编码失败，当前版本Image中的格式参数定义为image/heif，不符合图片标准定义，为提升规范性，将Heif格式图片mimeType变更为image/heic。

**变更影响**

该变更为兼容性变更。

变更前：Heif格式图片编码参数的mimeType类型为image/heif。

变更后：Heif格式图片编码参数的mimeType类型为image/heif或者image/heic。

**起始API Level**

API 12

**变更发生的版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

image_packer_native.h下的属性：

image.Component.OH_PackingOptions

**适配指导**

在调用该属性进行Heif图片编码时，开发者调用参数可以使用变更前的image/heif类型，也可以使用image/heic类型。