# ICodecImage


## 概述

图像编解码器模块接口。

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetImageCapability](#getimagecapability) ([out] struct [CodecImageCapability](_codec_image_capability_v10.md)[] capList) | 获得图像编解码器功能。 | 
| [Init](#init) ([in] enum [CodecImageRole](_codec_v10.md#codecimagerole) role) | 图像编解码器模块初始化。 | 
| [DeInit](#deinit) ([in] enum [CodecImageRole](_codec_v10.md#codecimagerole) role) | 图像编解码器模块去初始化。 | 
| [DoJpegDecode](#dojpegdecode) ([in] struct [CodecImageBuffer](_codec_image_buffer_v10.md) inBuffer, [in] struct [CodecImageBuffer](_codec_image_buffer_v10.md) outBuffer, [in] struct [CodecJpegDecInfo](_codec_jpeg_dec_info_v10.md) decInfo) | 启动jpeg图像解码。 | 
| [AllocateInBuffer](#allocateinbuffer) ([out] struct [CodecImageBuffer](_codec_image_buffer_v10.md) inBuffer, [in] unsigned int size, [in] [CodecImageRole](_codec_v10.md#codecimagerole) role) | 分配输入缓冲区。 | 
| [FreeInBuffer](#freeinbuffer) ([in] struct [CodecImageBuffer](_codec_image_buffer_v10.md) inBuffer) | 释放输入缓冲区。 | 


## 成员函数说明


### AllocateInBuffer()

```
ICodecImage::AllocateInBuffer ([out] struct CodecImageBuffer inBuffer, [in] unsigned int size, [in] CodecImageRole role )
```

**描述**

分配输入缓冲区。

您可以使用此API为图像编解码器分配输入缓冲区。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inBuffer | 获得的图像编解码器的输入缓冲区[CodecImageBuffer](_codec_image_buffer_v10.md)。 | 
| size | 获得的输入缓冲区的大小[CodecImageBuffer](_codec_image_buffer_v10.md)。 | 
| role | 获取的输入缓冲区的图像编解码器格式[CodecImageRole](_codec_v10.md#codecimagerole)。 | 

**返回：**

成功返回HDF_SUCCESS

输入无效参数返回HDF_ERR_INVALID_PARAM

失败返回HDF_FAILURE

如果vendor层返回失败，则返回其他值。其他错误代码详见[HDF_STATUS](https://gitee.com/openharmony/drivers_hdf_core/blob/master/interfaces/inner_api/utils/hdf_base.h)的定义。


### DeInit()

```
ICodecImage::DeInit ([in] enum CodecImageRole role)
```

**描述**

图像编解码器模块去初始化。

您可以使用此API对图像编解码器模块进行去初始化。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| role | 指示获取的图像编解码器格式[CodecImageRole](_codec_v10.md#codecimagerole)。 | 

**返回：**

成功返回HDF_SUCCESS

如果vendor层返回失败，则返回其他值。其他错误代码详见[HDF_STATUS](https://gitee.com/openharmony/drivers_hdf_core/blob/master/interfaces/inner_api/utils/hdf_base.h)的定义。


### DoJpegDecode()

```
ICodecImage::DoJpegDecode ([in] struct CodecImageBuffer inBuffer, [in] struct CodecImageBuffer outBuffer, [in] struct CodecJpegDecInfo decInfo )
```

**描述**

启动jpeg图像解码。

您可以使用此API启动jpeg图像解码。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inBuffer | 获得的jpeg图像解码的输入缓冲区[CodecImageBuffer](_codec_image_buffer_v10.md)。 | 
| outBuffer | 获得的jpeg图像解码的输出缓冲区[CodecImageBuffer](_codec_image_buffer_v10.md)。 | 
| decInfo | 获得的jpeg图像解码的解码信息[CodecJpegDecInfo](_codec_jpeg_dec_info_v10.md)。 | 

**返回：**

成功返回HDF_SUCCESS

输入无效参数返回HDF_ERR_INVALID_PARAM

失败返回HDF_FAILURE

如果vendor层返回失败，则返回其他值。其他错误代码详见[HDF_STATUS](https://gitee.com/openharmony/drivers_hdf_core/blob/master/interfaces/inner_api/utils/hdf_base.h)的定义。


### FreeInBuffer()

```
ICodecImage::FreeInBuffer ([in] struct CodecImageBuffer inBuffer)
```

**描述**

释放输入缓冲区。

您可以使用这个API来释放输入缓冲区用于图像解码。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 获得的图像编解码器的输入缓冲区[CodecImageBuffer](_codec_image_buffer_v10.md)。 | 

**返回：**

成功返回HDF_SUCCESS

如果vendor层返回失败，则返回其他值。其他错误代码详见[HDF_STATUS](https://gitee.com/openharmony/drivers_hdf_core/blob/master/interfaces/inner_api/utils/hdf_base.h)的定义。


### GetImageCapability()

```
ICodecImage::GetImageCapability ([out] struct CodecImageCapability[] capList)
```

**描述**

获得图像编解码器功能。

您可以使用此API来获得图像编解码器模块提供的编解码能力集。详见[CodecImageCapability](_codec_image_capability_v10.md)。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capList | 指向获得的图像编解码器能力集[CodecImageCapability](_codec_image_capability_v10.md)。 | 

**返回：**

成功返回HDF_SUCCESS

失败返回HDF_FAILURE


### Init()

```
ICodecImage::Init ([in] enum CodecImageRole role)
```

**描述**

图像编解码器模块初始化。

您可以使用此API来初始化图像编解码器模块。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| role | 指示获取的图像编解码器格式[CodecImageRole](_codec_v10.md#codecimagerole)。 | 

**返回：**

成功返回HDF_SUCCESS

如果vendor层返回失败，则返回其他值。其他错误代码详见[HDF_STATUS](https://gitee.com/openharmony/drivers_hdf_core/blob/master/interfaces/inner_api/utils/hdf_base.h)的定义。
