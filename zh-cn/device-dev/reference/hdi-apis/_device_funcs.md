# DeviceFuncs


## 概述

显示设备控制接口结构体，定义显示设备控制接口函数指针。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| (\*&nbsp;[RegHotPlugCallback](_display.md#reghotplugcallback)&nbsp;)([HotPlugCallback](_display.md#hotplugcallback)&nbsp;callback,&nbsp;void&nbsp;\*data) | int32_t<br/>注册热插拔事件回调。 | 
| (\*&nbsp;[RegDisplayVBlankCallback](_display.md#regdisplayvblankcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[VBlankCallback](_display.md#vblankcallback)&nbsp;callback,&nbsp;void&nbsp;\*data) | int32_t<br/>注册VBlank事件回调。 | 
| (\*&nbsp;[RegDisplayRefreshCallback](_display.md#regdisplayrefreshcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[RefreshCallback](_display.md#refreshcallback)&nbsp;callback,&nbsp;void&nbsp;\*data) | int32_t<br/>刷新请求回调。 | 
| (\*&nbsp;[GetDisplayCapability](_display.md#getdisplaycapability)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DisplayCapability](_display_capability.md)&nbsp;\*info) | int32_t<br/>获取显示设备能力集。 | 
| (\*&nbsp;[GetDisplaySupportedModes](_display.md#getdisplaysupportedmodes)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[DisplayModeInfo](_display_mode_info.md)&nbsp;\*modes) | int32_t<br/>获取显示设备支持的显示模式信息。 | 
| (\*&nbsp;[GetDisplayMode](_display.md#getdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*modeId) | int32_t<br/>获取显示设备当前的显示模式。 | 
| (\*&nbsp;[SetDisplayMode](_display.md#setdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;modeId) | int32_t<br/>设置显示设备的显示模式。 | 
| (\*&nbsp;[GetDisplayPowerStatus](_display.md#getdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DispPowerStatus](_display.md#disppowerstatus)&nbsp;\*status) | int32_t<br/>获取显示设备当前的电源状态。 | 
| (\*&nbsp;[SetDisplayPowerStatus](_display.md#setdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DispPowerStatus](_display.md#disppowerstatus)&nbsp;status) | int32_t<br/>设置显示设备当前的电源状态。 | 
| (\*&nbsp;[GetDisplayBacklight](_display.md#getdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*level) | int32_t<br/>获取显示设备当前的背光值。 | 
| (\*&nbsp;[SetDisplayBacklight](_display.md#setdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;level) | int32_t<br/>设置显示设备当前的背光值。 | 
| (\*&nbsp;[GetDisplayProperty](_display.md#getdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;\*value) | int32_t<br/>获取显示设备属性值。 | 
| (\*&nbsp;[SetDisplayProperty](_display.md#setdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;value) | int32_t<br/>设置显示设备属性值。 | 
| (\*&nbsp;[PrepareDisplayLayers](_display.md#preparedisplaylayers)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;\*needFlushFb) | int32_t<br/>显示设备合成前准备。 | 
| (\*&nbsp;[GetDisplayCompChange](_display.md#getdisplaycompchange)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*Layers,&nbsp;int32_t&nbsp;\*type) | int32_t<br/>获取显示设备合成类型有变化的layer。 | 
| (\*&nbsp;[SetDisplayClientCrop](_display.md#setdisplayclientcrop)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>设置显示设备的裁剪区域。 | 
| (\*&nbsp;[SetDisplayClientDestRect](_display.md#setdisplayclientdestrect)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>设置显示设备的显示区域。 | 
| (\*&nbsp;[SetDisplayClientBuffer](_display.md#setdisplayclientbuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | int32_t<br/>设置显示设备的显示缓存。 | 
| (\*&nbsp;[SetDisplayClientDamage](_display.md#setdisplayclientdamage)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;num,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | int32_t<br/>设置显示设备的显示脏区。 | 
| (\*&nbsp;[SetDisplayVsyncEnabled](_display.md#setdisplayvsyncenabled)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;enabled) | int32_t<br/>使能垂直同步信号。 | 
| (\*&nbsp;[GetDisplayReleaseFence](_display.md#getdisplayreleasefence)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*layers,&nbsp;int32_t&nbsp;\*fences) | int32_t<br/>获取显示图层fence。 | 
| (\*&nbsp;[GetDisplaySupportedColorGamuts](_display.md#getdisplaysupportedcolorgamuts)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[ColorGamut](_display.md#colorgamut)&nbsp;\*gamuts) | int32_t<br/>获取显示设备支持的色域信息。 | 
| (\*&nbsp;[GetDisplayColorGamut](_display.md#getdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](_display.md#colorgamut)&nbsp;\*gamut) | int32_t<br/>获取显示设备当前的色域模式。 | 
| (\*&nbsp;[SetDisplayColorGamut](_display.md#setdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](_display.md#colorgamut)&nbsp;gamut) | int32_t<br/>设置显示设备当前的色域模式。 | 
| (\*&nbsp;[GetDisplayGamutMap](_display.md#getdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[GamutMap](_display.md#gamutmap)&nbsp;\*gamutMap) | int32_t<br/>获取显示设备当前的色域映射模式。 | 
| (\*&nbsp;[SetDisplayGamutMap](_display.md#setdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[GamutMap](_display.md#gamutmap)&nbsp;gamutMap) | int32_t<br/>设置显示设备当前的色域映射模式。 | 
| (\*&nbsp;[SetDisplayColorTransform](_display.md#setdisplaycolortransform)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;float&nbsp;\*matrix) | int32_t<br/>设置显示设备当前的4x4的颜色转换矩阵。 | 
| (\*&nbsp;[GetHDRCapabilityInfos](_display.md#gethdrcapabilityinfos)&nbsp;)(uint32_t&nbsp;devId,&nbsp;[HDRCapability](_h_d_r_capability.md)&nbsp;\*info) | int32_t<br/>获取显示设备支持的HDR属性信息。 | 
| (\*&nbsp;[GetSupportedMetadataKey](_display.md#getsupportedmetadatakey)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[HDRMetadataKey](_display.md#hdrmetadatakey)&nbsp;\*keys) | int32_t<br/>获取显示设备支持的&nbsp;HDRMetadataKey。 | 
| (\*&nbsp;[Commit](_display.md#commit)&nbsp;)(uint32_t&nbsp;devId,&nbsp;int32_t&nbsp;\*fence) | int32_t<br/>提交合成送显请求。 | 
| (\*&nbsp;[InvokeDisplayCmd](_display.md#invokedisplaycmd)&nbsp;)(uint32_t&nbsp;devId,...) | int32_t<br/>调用显示设备命令。 | 
| (\*&nbsp;[CreateVirtualDisplay](_display.md#createvirtualdisplay)&nbsp;)(uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format,&nbsp;uint32_t&nbsp;\*devId) | int32_t<br/>创建虚拟显示设备。 | 
| (\*&nbsp;[DestroyVirtualDisplay](_display.md#destroyvirtualdisplay)&nbsp;)(uint32_t&nbsp;devId) | int32_t<br/>销毁虚拟显示设备。 | 
| (\*&nbsp;[SetVirtualDisplayBuffer](_display.md#setvirtualdisplaybuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | int32_t<br/>设置虚拟屏的输出缓存。 | 
| (\*&nbsp;[GetWriteBackFrame](_display.md#getwritebackframe)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;\*fence) | int32_t<br/>获取显示设备的回写帧。 | 
| (\*&nbsp;[CreateWriteBack](#createwriteback)&nbsp;)(uint32_t&nbsp;\*devId,&nbsp;uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format) | int32_t<br/>PixelFormat,&nbsp;接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 
| (\*&nbsp;[DestroyWriteBack](#destroywriteback)&nbsp;)(uint32_t&nbsp;devId) | int32_t<br/>销毁指定显示设备的回写点。 | 


## 类成员变量说明


### CreateWriteBack

  
```
int32_t(* DeviceFuncs::CreateWriteBack) (uint32_t *devId, uint32_t width, uint32_t height, int32_t *format)
```

**描述:**

PixelFormat, 接口实现层可以根据硬件需求，修改format并返回给图形服务。

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### DestroyWriteBack

  
```
int32_t(* DeviceFuncs::DestroyWriteBack) (uint32_t devId)
```

**描述:**

销毁指定显示设备的回写点。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。
