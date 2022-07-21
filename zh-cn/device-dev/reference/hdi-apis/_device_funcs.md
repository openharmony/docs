# DeviceFuncs


## **概述**

**所属模块:**

[Display](_display.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;**RegHotPlugCallback**&nbsp;)(HotPlugCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册热插拔事件回调 | 
| (&nbsp;**RegDisplayVBlankCallback**&nbsp;)(uint32_t&nbsp;devId,&nbsp;VBlankCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册VBlank事件回调。 | 
| (&nbsp;**RegDisplayRefreshCallback**&nbsp;)(uint32_t&nbsp;devId,&nbsp;RefreshCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 刷新请求回调。 | 
| (&nbsp;**GetDisplayCapability**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DisplayCapability](_display_capability.md)&nbsp;\*info) | 获取显示设备能力集。 | 
| (&nbsp;**GetDisplaySupportedModes**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[DisplayModeInfo](_display_mode_info.md)&nbsp;\*modes) | 获取显示设备支持的显示模式信息。 | 
| (&nbsp;**GetDisplayMode**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*modeId) | 获取显示设备当前的显示模式。 | 
| (&nbsp;**SetDisplayMode**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;modeId) | 设置显示设备的显示模式。 | 
| (&nbsp;**GetDisplayPowerStatus**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DispPowerStatus](_display.md#disppowerstatus)&nbsp;\*status) | 获取显示设备当前的电源状态。 | 
| (&nbsp;**SetDisplayPowerStatus**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[DispPowerStatus](_display.md#disppowerstatus)&nbsp;status) | 设置显示设备当前的电源状态。 | 
| (&nbsp;**GetDisplayBacklight**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*level) | 获取显示设备当前的背光值。 | 
| (&nbsp;**SetDisplayBacklight**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;level) | 设置显示设备当前的背光值。 | 
| (&nbsp;**GetDisplayProperty**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;\*value) | 获取显示设备属性值。 | 
| (&nbsp;**SetDisplayProperty**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;value) | 设置显示设备属性值。 | 
| (&nbsp;**PrepareDisplayLayers**&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;\*needFlushFb) | 显示设备合成前准备 | 
| (&nbsp;**GetDisplayCompChange**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*Layers,&nbsp;int32_t&nbsp;\*type) | 获取显示设备合成类型有变化的layer | 
| (&nbsp;**SetDisplayClientCrop**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | 设置显示设备的裁剪区域。 | 
| (&nbsp;**SetDisplayClientDestRect**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | 设置显示设备的显示区域。 | 
| (&nbsp;**SetDisplayClientBuffer**&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置显示设备的显示缓存。 | 
| (&nbsp;**SetDisplayClientDamage**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;num,&nbsp;[IRect](_i_rect.md)&nbsp;\*rect) | 设置显示设备的显示脏区 | 
| (&nbsp;**SetDisplayVsyncEnabled**&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;enabled) | 使能垂直同步信号。 | 
| (&nbsp;**GetDisplayReleaseFence**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*layers,&nbsp;int32_t&nbsp;\*fences) | 获取显示图层fence。 | 
| (&nbsp;**GetDisplaySupportedColorGamuts**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[ColorGamut](_display.md#colorgamut)&nbsp;\*gamuts) | 获取显示设备支持的色域信息。 | 
| (&nbsp;**GetDisplayColorGamut**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](_display.md#colorgamut)&nbsp;\*gamut) | 获取显示设备当前的色域模式。 | 
| (&nbsp;**SetDisplayColorGamut**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[ColorGamut](_display.md#colorgamut)&nbsp;gamut) | 设置显示设备当前的色域模式。 | 
| (&nbsp;**GetDisplayGamutMap**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[GamutMap](_display.md#gamutmap)&nbsp;\*gamutMap) | 获取显示设备当前的色域映射模式。 | 
| (&nbsp;**SetDisplayGamutMap**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[GamutMap](_display.md#gamutmap)&nbsp;gamutMap) | 设置显示设备当前的色域映射模式。 | 
| (&nbsp;**SetDisplayColorTransform**&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;float&nbsp;\*matrix) | 设置显示设备当前的4x4的颜色转换矩阵。 | 
| (&nbsp;**GetHDRCapabilityInfos**&nbsp;)(uint32_t&nbsp;devId,&nbsp;[HDRCapability](_h_d_r_capability.md)&nbsp;\*info) | 获取显示设备支持的HDR属性信息。 | 
| (&nbsp;**GetSupportedMetadataKey**&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;[HDRMetadataKey](_display.md#hdrmetadatakey)&nbsp;\*keys) | 获取显示设备支持的&nbsp;HDRMetadataKey。 | 
| (&nbsp;**Commit**&nbsp;)(uint32_t&nbsp;devId,&nbsp;int32_t&nbsp;\*fence) | 提交合成送显请求。 | 
| (&nbsp;**InvokeDisplayCmd**&nbsp;)(uint32_t&nbsp;devId,...) | 调用显示设备命令。 | 
| (&nbsp;**CreateVirtualDisplay**&nbsp;)(uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format,&nbsp;uint32_t&nbsp;\*devId) | 创建虚拟显示设备。 | 
| (&nbsp;**DestroyVirtualDisplay**&nbsp;)(uint32_t&nbsp;devId) | 销毁虚拟显示设备。 | 
| (&nbsp;**SetVirtualDisplayBuffer**&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置虚拟屏的输出缓存。 | 
| (&nbsp;**GetWriteBackFrame**&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;\*fence) | 获取显示设备的回写帧。 | 
| (&nbsp;**CreateWriteBack**&nbsp;)(uint32_t&nbsp;\*devId,&nbsp;uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format) | 对指定显示设备创建回写点。 | 
| (&nbsp;**DestroyWriteBack**&nbsp;)(uint32_t&nbsp;devId) | 销毁指定显示设备的回写点。 | 


## **详细描述**

显示设备控制接口结构体，定义显示设备控制接口函数指针。
