# LayerFuncs


## 概述

显示图层驱动接口结构体，定义显示图层驱动接口函数指针。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| (\*&nbsp;[InitDisplay](#initdisplay)&nbsp;)(uint32_t&nbsp;devId) | int32_t<br/>初始化显示设备。 | 
| (\*&nbsp;[DeinitDisplay](#deinitdisplay)&nbsp;)(uint32_t&nbsp;devId) | int32_t<br/>取消初始化显示设备。 | 
| (\*&nbsp;[GetDisplayInfo](#getdisplayinfo)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DisplayInfo](_display_info.md)&nbsp;\*dispInfo) | int32_t<br/>获取显示设备相关信息。 | 
| (\*&nbsp;[CreateLayer](#createlayer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;[LayerInfo](_layer_info.md)&nbsp;\*layerInfo,&nbsp;uint32_t&nbsp;\*layerId) | int32_t<br/>打开图层。 | 
| (\*&nbsp;[CloseLayer](#closelayer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId) | int32_t<br/>关闭图层。 | 
| (\*&nbsp;[SetLayerVisible](#setlayervisible)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;bool&nbsp;visible) | int32_t<br/>设置图层是否可见。 | 
| (\*&nbsp;[GetLayerVisibleState](#getlayervisiblestate)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;bool&nbsp;\*visible) | int32_t<br/>获取图层是否可见状态。 | 
| (\*&nbsp;[SetLayerSize](#setlayersize)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>设置图层大小。 | 
| (\*&nbsp;[GetLayerSize](#getlayersize)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>获取图层大小。 | 
| (\*&nbsp;[SetLayerCrop](#setlayercrop)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>设置图层裁剪区域。 | 
| (\*&nbsp;[SetLayerZorder](#setlayerzorder)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;zorder) | int32_t<br/>设置图层Z轴次序。 | 
| (\*&nbsp;[GetLayerZorder](#getlayerzorder)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;\*zorder) | int32_t<br/>获取图层Z轴次序。 | 
| (\*&nbsp;[SetLayerPreMulti](#setlayerpremulti)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;bool&nbsp;preMul) | int32_t<br/>设置图层预乘。 | 
| (\*&nbsp;[GetLayerPreMulti](#getlayerpremulti)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;bool&nbsp;\*preMul) | int32_t<br/>获取图层预乘标识。 | 
| (\*&nbsp;[SetLayerAlpha](#setlayeralpha)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[LayerAlpha](_layer_alpha.md)&nbsp;\*alpha) | int32_t<br/>设置图层alpha值。 | 
| (\*&nbsp;[GetLayerAlpha](#getlayeralpha)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[LayerAlpha](_layer_alpha.md)&nbsp;\*alpha) | int32_t<br/>获取图层alpha值。 | 
| (\*&nbsp;[SetLayerColorKey](#setlayercolorkey)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;bool&nbsp;enable,&nbsp;uint32_t&nbsp;key) | int32_t<br/>设置图层colorkey属性,在图层叠加时使用。 | 
| (\*&nbsp;[GetLayerColorKey](#getlayercolorkey)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;bool&nbsp;\*enable,&nbsp;uint32_t&nbsp;\*key) | int32_t<br/>获取图层colorkey。 | 
| (\*&nbsp;[SetLayerPalette](#setlayerpalette)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;\*palette,&nbsp;uint32_t&nbsp;len) | int32_t<br/>设置图层调色板。 | 
| (\*&nbsp;[GetLayerPalette](#getlayerpalette)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;\*palette,&nbsp;uint32_t&nbsp;len) | int32_t<br/>获取图层调色板。 | 
| (\*&nbsp;[SetTransformMode](#settransformmode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[TransformType](_display.md#transformtype)&nbsp;type) | int32_t<br/>设置图层变换模式，根据不同的场景设置图层的旋转、缩放、移位等。 | 
| (\*&nbsp;[SetLayerCompression](#setlayercompression)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;int32_t&nbsp;compType) | int32_t<br/>设置图层压缩功能 | 
| (\*&nbsp;[GetLayerCompression](#getlayercompression)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;int32_t&nbsp;\*compType) | int32_t<br/>获取图层压缩功能是否打开。 | 
| (\*&nbsp;[SetLayerDirtyRegion](#setlayerdirtyregion)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[IRect](_i_rect.md)&nbsp;\*region) | int32_t<br/>设置图层刷新区域。 | 
| (\*&nbsp;[GetLayerBuffer](#getlayerbuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[LayerBuffer](_layer_buffer.md)&nbsp;\*buffer) | int32_t<br/>获取图层的buffer。 | 
| (\*&nbsp;[Flush](#flush)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[LayerBuffer](_layer_buffer.md)&nbsp;\*buffer) | int32_t<br/>刷新图层。 | 
| (\*&nbsp;[WaitForVBlank](#waitforvblank)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;int32_t&nbsp;timeOut) | int32_t<br/>实现等待帧消隐期到来功能。 | 
| (\*&nbsp;[SnapShot](#snapshot)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[LayerBuffer](_layer_buffer.md)&nbsp;\*buffer) | int32_t<br/>实现抓图功能。 | 
| (\*&nbsp;[SetLayerVisibleRegion](#setlayervisibleregion)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;num,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>设置一个图层的可见区域 | 
| (\*&nbsp;[SetLayerBuffer](#setlayerbuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;const&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | int32_t<br/>设置一个层的缓冲区。 | 
| (\*&nbsp;[InvokeLayerCmd](#invokelayercmd)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;cmd,...) | int32_t<br/>扩展接口 | 
| (\*&nbsp;[SetLayerCompositionType](#setlayercompositiontype)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[CompositionType](_display.md#compositiontype)&nbsp;type) | int32_t<br/>设置客户端期望的组合类型 | 
| (\*&nbsp;[SetLayerBlendType](#setlayerblendtype)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[BlendType](_display.md#blendtype)&nbsp;type) | int32_t<br/>设置混合类型 | 
| (\*&nbsp;[SetLayerColorTransform](#setlayercolortransform)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;const&nbsp;float&nbsp;\*matrix) | int32_t<br/>设置图层当前的颜色转换矩阵。 | 
| (\*&nbsp;[SetLayerColorDataSpace](#setlayercolordataspace)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[ColorDataSpace](_display.md#colordataspace)&nbsp;colorSpace) | int32_t<br/>设置图层的颜色数据空间。 | 
| (\*&nbsp;[GetLayerColorDataSpace](#getlayercolordataspace)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[ColorDataSpace](_display.md#colordataspace)&nbsp;\*colorSpace) | int32_t<br/>获取图层当前的颜色数据空间。 | 
| (\*&nbsp;[SetLayerMetaData](#setlayermetadata)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;uint32_t&nbsp;num,&nbsp;const&nbsp;[HDRMetaData](_h_d_r_meta_data.md)&nbsp;\*metaData) | int32_t<br/>设置图层的HDRmetaData。 | 
| (\*&nbsp;[SetLayerMetaDataSet](#setlayermetadataset)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[HDRMetadataKey](_display.md#hdrmetadatakey)&nbsp;key,&nbsp;uint32_t&nbsp;num,&nbsp;const&nbsp;uint8_t&nbsp;\*metaData) | int32_t<br/>设置图层的metaData&nbsp;set。 | 
| (\*&nbsp;[GetSupportedPresentTimestamp](#getsupportedpresenttimestamp)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[PresentTimestampType](_display.md#presenttimestamptype)&nbsp;\*type) | int32_t<br/>获取图层支持的上屏时间戳类型。 | 
| (\*&nbsp;[GetHwPresentTimestamp](#gethwpresenttimestamp)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;[PresentTimestamp](_present_timestamp.md)&nbsp;\*pts) | int32_t<br/>获取图层的上屏时间戳信息。 | 
| (\*&nbsp;[SetLayerTunnelHandle](#setlayertunnelhandle)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;ExtDataHandle&nbsp;\*handle) | int32_t<br/>设置图层的tunnel句柄。 | 
| (\*&nbsp;[GetLayerReleaseFence](#getlayerreleasefence)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;layerId,&nbsp;int32_t&nbsp;\*fence) | int32_t<br/>获取图层的同步栅栏。 | 


## 类成员变量说明


### CloseLayer

  
```
int32_t(* LayerFuncs::CloseLayer) (uint32_t devId, uint32_t layerId)
```

**描述:**

关闭图层。

在完成显示后，如果不在需要使用图层，调用关闭图层接口关闭图层。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[CreateLayer](#createlayer)


### CreateLayer

  
```
int32_t(* LayerFuncs::CreateLayer) (uint32_t devId, const LayerInfo *layerInfo, uint32_t *layerId)
```

**描述:**

打开图层。

GUI在使用图层时，需要先根据图层信息打开图层，打开图层成功可获得图层ID，根据图层ID使用图层各接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerInfo | 输入参数，图层信息，上层GUI打开图层时需传递图层信息，包括图层类型，图层大小，像素格式等信息。 | 
| layerId | 输入参数，图层ID，打开图层成功后返回给GUI的图层ID，用于标识唯一的图层。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[CloseLayer](#closelayer)


### DeinitDisplay

  
```
int32_t(* LayerFuncs::DeinitDisplay) (uint32_t devId)
```

**描述:**

取消初始化显示设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[InitDisplay](#initdisplay)


### Flush

  
```
int32_t(* LayerFuncs::Flush) (uint32_t devId, uint32_t layerId, LayerBuffer *buffer)
```

**描述:**

刷新图层。

将buffer显示数据刷新到指定的layerId图层上，实现图像数据显示到屏幕上。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| buffer | 输出参数，待刷新的buffer。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### GetDisplayInfo

  
```
int32_t(* LayerFuncs::GetDisplayInfo) (uint32_t devId, DisplayInfo *dispInfo)
```

**描述:**

获取显示设备相关信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| dispInfo | 输出参数，显示相关信息。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### GetHwPresentTimestamp

  
```
int32_t(* LayerFuncs::GetHwPresentTimestamp) (uint32_t devId, uint32_t layerId, PresentTimestamp *pts)
```

**描述:**

获取图层的上屏时间戳信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| pts | 输出参数，保存图层的上屏时间戳信息，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### GetLayerAlpha

  
```
int32_t(* LayerFuncs::GetLayerAlpha) (uint32_t devId, uint32_t layerId, LayerAlpha *alpha)
```

**描述:**

获取图层alpha值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| alpha | 输出参数，保存获取的图层alpha值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerAlpha](#setlayeralpha)


### GetLayerBuffer

  
```
int32_t(* LayerFuncs::GetLayerBuffer) (uint32_t devId, uint32_t layerId, LayerBuffer *buffer)
```

**描述:**

获取图层的buffer。

向buffer中绘图后，调用Flush接口显示到屏幕上。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| buffer | 输出参数，保存获取的图层buffer。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[Flush](#flush)


### GetLayerColorDataSpace

  
```
int32_t(* LayerFuncs::GetLayerColorDataSpace) (uint32_t devId, uint32_t layerId, ColorDataSpace *colorSpace)
```

**描述:**

获取图层当前的颜色数据空间。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| colorSpace | 输出参数，保存对应图层的颜色数据空间。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### GetLayerColorKey

  
```
int32_t(* LayerFuncs::GetLayerColorKey) (uint32_t devId, uint32_t layerId, bool *enable, uint32_t *key)
```

**描述:**

获取图层colorkey。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| enable | 输出参数，保存获取的enable色键使能标识。 | 
| key | 输出参数，保存获取的色键值，即颜色值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerColorKey](#setlayercolorkey)


### GetLayerCompression

  
```
int32_t(* LayerFuncs::GetLayerCompression) (uint32_t devId, uint32_t layerId, int32_t *compType)
```

**描述:**

获取图层压缩功能是否打开。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| compType | 输出参数，保存获取的图层压缩功能状态。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerCompression](#setlayercompression)


### GetLayerPalette

  
```
int32_t(* LayerFuncs::GetLayerPalette) (uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)
```

**描述:**

获取图层调色板。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| palette | 输出参数，保存获取的图层调色板。 | 
| len | 输入参数，调色板长度。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerPalette](#setlayerpalette)


### GetLayerPreMulti

  
```
int32_t(* LayerFuncs::GetLayerPreMulti) (uint32_t devId, uint32_t layerId, bool *preMul)
```

**描述:**

获取图层预乘标识。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| preMul | 输出参数，保存获取的图层预乘使能标识。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerPreMulti](#setlayerpremulti)


### GetLayerReleaseFence

  
```
int32_t(* LayerFuncs::GetLayerReleaseFence) (uint32_t devId, uint32_t layerId, int32_t *fence)
```

**描述:**

获取图层的同步栅栏。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| fence | 输出参数，保存图层的&nbsp;release&nbsp;fence，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### GetLayerSize

  
```
int32_t(* LayerFuncs::GetLayerSize) (uint32_t devId, uint32_t layerId, IRect *rect)
```

**描述:**

获取图层大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| rect | 输出参数，保存获取的图层大小。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerSize](#setlayersize)


### GetLayerVisibleState

  
```
int32_t(* LayerFuncs::GetLayerVisibleState) (uint32_t devId, uint32_t layerId, bool *visible)
```

**描述:**

获取图层是否可见状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| visible | 输出参数，保存获取的图层可见状态，true表示图层可见，false表示图层不可见。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerVisible](#setlayervisible)


### GetLayerZorder

  
```
int32_t(* LayerFuncs::GetLayerZorder) (uint32_t devId, uint32_t layerId, uint32_t *zorder)
```

**描述:**

获取图层Z轴次序。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| zorder | 输出参数，保存获取的图层Z轴次序，为整数值，取值范围为[0,&nbsp;255]，值越大图层越往上排列。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[SetLayerZorder](#setlayerzorder)


### GetSupportedPresentTimestamp

  
```
int32_t(* LayerFuncs::GetSupportedPresentTimestamp) (uint32_t devId, uint32_t layerId, PresentTimestampType *type)
```

**描述:**

获取图层支持的上屏时间戳类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| type | 输出参数，保存图层支持的上屏时间戳类型，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### InitDisplay

  
```
int32_t(* LayerFuncs::InitDisplay) (uint32_t devId)
```

**描述:**

初始化显示设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[DeinitDisplay](#deinitdisplay)


### InvokeLayerCmd

  
```
int32_t(* LayerFuncs::InvokeLayerCmd) (uint32_t devId, uint32_t layerId, uint32_t cmd,...)
```

**描述:**

扩展接口

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备的ID。取值范围为0&nbsp;~&nbsp;4，其中0表示第一个显示设备，4表示最后一个显示设备。 | 
| layerId | 输入参数，层ID，唯一标识一个层。可以对该层进行操作。 | 
| cmd | 输入参数，表示扩展cmd，用于识别不同的意图。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerAlpha

  
```
int32_t(* LayerFuncs::SetLayerAlpha) (uint32_t devId, uint32_t layerId, LayerAlpha *alpha)
```

**描述:**

设置图层alpha值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| alpha | 输入参数，待设置的图层&nbsp;alpha&nbsp;值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerAlpha](#getlayeralpha)


### SetLayerBlendType

  
```
int32_t(* LayerFuncs::SetLayerBlendType) (uint32_t devId, uint32_t layerId, BlendType type)
```

**描述:**

设置混合类型

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备的ID。取值范围为0&nbsp;~&nbsp;4，其中0表示第一个显示设备，4表示最后一个显示设备。 | 
| layerId | 输入参数，层ID，唯一标识一个层。可以对该层进行操作。 | 
| type | 输入参数，指示混合类型。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerBuffer

  
```
int32_t(* LayerFuncs::SetLayerBuffer) (uint32_t devId, uint32_t layerId, const BufferHandle *buffer, int32_t fence)
```

**描述:**

设置一个层的缓冲区。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备的ID。取值范围为0&nbsp;~&nbsp;4，其中0表示第一个显示设备，4表示最后一个显示设备。 | 
| layerId | 输入参数，层ID，唯一标识一个层。可以对该层进行操作。 | 
| buffer | 输入参数，指示缓冲区句柄的指针，该指针包含所有用于合成的缓冲区的所有信息。 | 
| fence | 输入参数，同步文件的fd。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerColorDataSpace

  
```
int32_t(* LayerFuncs::SetLayerColorDataSpace) (uint32_t devId, uint32_t layerId, ColorDataSpace colorSpace)
```

**描述:**

设置图层的颜色数据空间。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| colorSpace | 输入参数，表示需要设置的颜色数据空间。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerColorKey

  
```
int32_t(* LayerFuncs::SetLayerColorKey) (uint32_t devId, uint32_t layerId, bool enable, uint32_t key)
```

**描述:**

设置图层colorkey属性，在图层叠加时使用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| enable | 输入参数，待设置的色键使能标识。 | 
| key | 输入参数，待设置的色键值，即颜色值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerColorKey](#getlayercolorkey)


### SetLayerColorTransform

  
```
int32_t(* LayerFuncs::SetLayerColorTransform) (uint32_t devId, uint32_t layerId, const float *matrix)
```

**描述:**

设置图层当前的颜色转换矩阵。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| matrix | 输入参数，表示需要设置的颜色转换模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerCompositionType

  
```
int32_t(* LayerFuncs::SetLayerCompositionType) (uint32_t devId, uint32_t layerId, CompositionType type)
```

**描述:**

设置客户端期望的组合类型

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备的ID。取值范围为0&nbsp;~&nbsp;4，其中0表示第一个显示设备，4表示最后一个显示设备。 | 
| layerId | 输入参数，层ID，唯一标识一个层。可以对该层进行操作。 | 
| type | 输入参数，指示客户端期望的组合类型。它可能随实现而变化。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerCompression

  
```
int32_t(* LayerFuncs::SetLayerCompression) (uint32_t devId, uint32_t layerId, int32_t compType)
```

**描述:**

设置图层压缩功能

在特定场景下，需要对图像数据进行压缩，可设置启动或关闭图层压缩功能。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| compType | 输入参数，图层压缩使能标识。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerCompression](#getlayercompression)


### SetLayerCrop

  
```
int32_t(* LayerFuncs::SetLayerCrop) (uint32_t devId, uint32_t layerId, IRect *rect)
```

**描述:**

设置图层裁剪区域。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| rect | 输入参数，待设置的裁剪区域。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerDirtyRegion

  
```
int32_t(* LayerFuncs::SetLayerDirtyRegion) (uint32_t devId, uint32_t layerId, IRect *region)
```

**描述:**

设置图层刷新区域。

GUI图形系统绘制好图像数据后，在调用Flush接口刷新屏幕之前需要设置图层刷新区域。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| region | 输入参数，待设置的刷新区域。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerMetaData

  
```
int32_t(* LayerFuncs::SetLayerMetaData) (uint32_t devId, uint32_t layerId, uint32_t num, const HDRMetaData *metaData)
```

**描述:**

设置图层的HDRmetaData。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| num | 输入参数，metadata&nbsp;数组个数。 | 
| metaData | 输入参数，表示需要设置的&nbsp;metadata&nbsp;数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerMetaDataSet

  
```
int32_t(* LayerFuncs::SetLayerMetaDataSet) (uint32_t devId, uint32_t layerId, HDRMetadataKey key, uint32_t num, const uint8_t *metaData)
```

**描述:**

设置图层的metaData set。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| key | 输入参数，表示需要设置的&nbsp;HDRMetadataKey。 | 
| num | 输入参数，metadata&nbsp;数组个数。 | 
| metaData | 输入参数，表示需要设置的&nbsp;metadata&nbsp;数组首地址，数据类型为uint8_t。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerPalette

  
```
int32_t(* LayerFuncs::SetLayerPalette) (uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)
```

**描述:**

设置图层调色板。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| palette | 输入参数，待设置的图层调色板。 | 
| len | 输入参数，调色板长度。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerPalette](#getlayerpalette)


### SetLayerPreMulti

  
```
int32_t(* LayerFuncs::SetLayerPreMulti) (uint32_t devId, uint32_t layerId, bool preMul)
```

**描述:**

设置图层预乘。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| preMul | 输入参数，待设置的图层预乘使能标识，1表示使能图层预乘，0表示不使能图层预乘。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerPreMulti](#getlayerpremulti)


### SetLayerSize

  
```
int32_t(* LayerFuncs::SetLayerSize) (uint32_t devId, uint32_t layerId, IRect *rect)
```

**描述:**

设置图层大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| rect | 输入参数，待设置的图层大小，单位为像素。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerSize](#getlayersize)


### SetLayerTunnelHandle

  
```
int32_t(* LayerFuncs::SetLayerTunnelHandle) (uint32_t devId, uint32_t layerId, ExtDataHandle *handle)
```

**描述:**

设置图层的tunnel句柄。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| layerId | 输入参数，指示需要操作的图层ID。 | 
| handle | 输入参数，表示需要设置的句柄。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerVisible

  
```
int32_t(* LayerFuncs::SetLayerVisible) (uint32_t devId, uint32_t layerId, bool visible)
```

**描述:**

设置图层是否可见。

不可见情况下图层不显示在屏幕上，可见情况下图层显示在屏幕上。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| visible | 输入参数，待设置的图层可见标识，设置true表示图层可见，设置false表示图层不可见。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerVisibleState](#getlayervisiblestate)


### SetLayerVisibleRegion

  
```
int32_t(* LayerFuncs::SetLayerVisibleRegion) (uint32_t devId, uint32_t layerId, uint32_t num, IRect *rect)
```

**描述:**

设置一个图层的可见区域

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备的ID。取值范围为0&nbsp;~&nbsp;4，其中0表示第一个显示设备，4表示最后一个显示设备。 | 
| layerId | 输入参数，层ID，唯一标识一个层。可以对该层进行操作。 | 
| num | 输入参数，指定rect的计数，该区域包含多个[IRect](_i_rect.md)，num表示该区域中有多少个rect区域。 | 
| rect | 输出参数，rectes对象的指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SetLayerZorder

  
```
int32_t(* LayerFuncs::SetLayerZorder) (uint32_t devId, uint32_t layerId, uint32_t zorder)
```

**描述:**

设置图层Z轴次序。

图层的Z序值越大，图层越靠上显示。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| zorder | 输入参数，待设置的图层Z序，为整数值，取值范围为[0,&nbsp;255]，值越大图层越往上排列。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[GetLayerZorder](#getlayerzorder)


### SetTransformMode

  
```
int32_t(* LayerFuncs::SetTransformMode) (uint32_t devId, uint32_t layerId, TransformType type)
```

**描述:**

设置图层变换模式，根据不同的场景设置图层的旋转、缩放、移位等。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| type | 输入参数，待设置的图层变换模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### SnapShot

  
```
int32_t(* LayerFuncs::SnapShot) (uint32_t devId, LayerBuffer *buffer)
```

**描述:**

实现抓图功能。

本函数将显示设备上的图像数据截图保存到buffer中，用于调试、应用截图等场景。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| buffer | 输出参数，保存截屏的buffer信息。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### WaitForVBlank

  
```
int32_t(* LayerFuncs::WaitForVBlank) (uint32_t devId, uint32_t layerId, int32_t timeOut)
```

**描述:**

实现等待帧消隐期到来功能。

该函数会让系统等待，直到帧消隐期到来，用于软件和硬件之间的同步。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。 | 
| layerId | 输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。 | 
| timeOut | 输入参数，超时时间，在设置的超时时间后，没有等到帧消隐期到来则超时返回。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。
