# DeviceFuncs


## **概述**

显示设备控制接口结构体，定义显示设备控制接口函数指针。

**相关模块:**

[Display](_display.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([DeviceFuncs::RegHotPlugCallback](_display.md#reghotplugcallback)&nbsp;)(HotPlugCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册热插拔事件回调。 | 
| ([DeviceFuncs::RegDisplayVBlankCallback](_display.md#regdisplayvblankcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;VBlankCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册VBlank事件回调。 | 
| ([DeviceFuncs::RegDisplayRefreshCallback](_display.md#regdisplayrefreshcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;RefreshCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 刷新请求回调。 | 
| ([DeviceFuncs::GetDisplayCapability](_display.md#getdisplaycapability)&nbsp;)(uint32_t&nbsp;devId,&nbsp;DisplayCapability&nbsp;\*info) | 获取显示设备能力集。 | 
| ([DeviceFuncs::GetDisplaySupportedModes](_display.md#getdisplaysupportedmodes)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;DisplayModeInfo&nbsp;\*modes) | 获取显示设备支持的显示模式信息。 | 
| ([DeviceFuncs::GetDisplayMode](_display.md#getdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*modeId) | 获取显示设备当前的显示模式。 | 
| ([DeviceFuncs::SetDisplayMode](_display.md#setdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;modeId) | 设置显示设备的显示模式。 | 
| ([DeviceFuncs::GetDisplayPowerStatus](_display.md#getdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;DispPowerStatus&nbsp;\*status) | 获取显示设备当前的电源状态。 | 
| ([DeviceFuncs::SetDisplayPowerStatus](_display.md#setdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;DispPowerStatus&nbsp;status) | 设置显示设备当前的电源状态。 | 
| ([DeviceFuncs::GetDisplayBacklight](_display.md#getdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*level) | 获取显示设备当前的背光值。 | 
| ([DeviceFuncs::SetDisplayBacklight](_display.md#setdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;level) | 设置显示设备当前的背光值。 | 
| ([DeviceFuncs::GetDisplayProperty](_display.md#getdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;\*value) | 获取显示设备属性值。 | 
| ([DeviceFuncs::SetDisplayProperty](_display.md#setdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;value) | 设置显示设备属性值。 | 
| ([DeviceFuncs::PrepareDisplayLayers](_display.md#preparedisplaylayers)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;\*needFlushFb) | 显示设备合成前准备。 | 
| ([DeviceFuncs::GetDisplayCompChange](_display.md#getdisplaycompchange)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*Layers,&nbsp;int32_t&nbsp;\*type) | 获取显示设备合成类型有变化的layer。 | 
| ([DeviceFuncs::SetDisplayClientCrop](_display.md#setdisplayclientcrop)&nbsp;)(uint32_t&nbsp;devId,&nbsp;IRect&nbsp;\*rect) | 设置显示设备的裁剪区域。 | 
| ([DeviceFuncs::SetDisplayClientDestRect](_display.md#setdisplayclientdestrect)&nbsp;)(uint32_t&nbsp;devId,&nbsp;IRect&nbsp;\*rect) | 设置显示设备的显示区域。 | 
| ([DeviceFuncs::SetDisplayClientBuffer](_display.md#setdisplayclientbuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置显示设备的显示缓存。 | 
| ([DeviceFuncs::SetDisplayClientDamage](_display.md#setdisplayclientdamage)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;num,&nbsp;IRect&nbsp;\*rect) | 设置显示设备的显示脏区。 | 
| ([DeviceFuncs::SetDisplayVsyncEnabled](_display.md#setdisplayvsyncenabled)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;enabled) | 使能垂直同步信号。 | 
| ([DeviceFuncs::GetDisplayReleaseFence](_display.md#getdisplayreleasefence)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*layers,&nbsp;int32_t&nbsp;\*fences) | 获取显示图层fence。 | 
| ([DeviceFuncs::GetDisplaySupportedColorGamuts](_display.md#getdisplaysupportedcolorgamuts)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;ColorGamut&nbsp;\*gamuts) | 获取显示设备支持的色域信息。 | 
| ([DeviceFuncs::GetDisplayColorGamut](_display.md#getdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;ColorGamut&nbsp;\*gamut) | 获取显示设备当前的色域模式。 | 
| ([DeviceFuncs::SetDisplayColorGamut](_display.md#setdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;ColorGamut&nbsp;gamut) | 设置显示设备当前的色域模式。 | 
| ([DeviceFuncs::GetDisplayGamutMap](_display.md#getdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;GamutMap&nbsp;\*gamutMap) | 获取显示设备当前的色域映射模式。 | 
| ([DeviceFuncs::SetDisplayGamutMap](_display.md#setdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;GamutMap&nbsp;gamutMap) | 设置显示设备当前的色域映射模式。 | 
| ([DeviceFuncs::SetDisplayColorTransform](_display.md#setdisplaycolortransform)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;float&nbsp;\*matrix) | 设置显示设备当前的4x4的颜色转换矩阵。 | 
| ([DeviceFuncs::GetHDRCapabilityInfos](_display.md#gethdrcapabilityinfos)&nbsp;)(uint32_t&nbsp;devId,&nbsp;HDRCapability&nbsp;\*info) | 获取显示设备支持的HDR属性信息。 | 
| ([DeviceFuncs::GetSupportedMetadataKey](_display.md#getsupportedmetadatakey)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;DisplayInfo::widthHDRMetadataKey&nbsp;\*keys) | 获取显示设备支持的&nbsp;HDRMetadataKey。 | 
| ([DeviceFuncs::Commit](_display.md#commit)&nbsp;)(uint32_t&nbsp;devId,&nbsp;int32_t&nbsp;\*fence) | 提交合成送显请求。 | 
| ([DeviceFuncs::InvokeDisplayCmd](_display.md#invokedisplaycmd)&nbsp;)(uint32_t&nbsp;devId,...) | 调用显示设备命令。 | 
| ([DeviceFuncs::CreateVirtualDisplay](_display.md#createvirtualdisplay)&nbsp;)(uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format,&nbsp;uint32_t&nbsp;\*devId) | 创建虚拟显示设备。 | 
| ([DeviceFuncs::DestroyVirtualDisplay](_display.md#destroyvirtualdisplay)&nbsp;)(uint32_t&nbsp;devId) | 销毁虚拟显示设备。 | 
| ([DeviceFuncs::SetVirtualDisplayBuffer](_display.md#setvirtualdisplaybuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置虚拟屏的输出缓存。 | 
| ([DeviceFuncs::GetWriteBackFrame](_display.md#getwritebackframe)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;\*fence) | 获取显示设备的回写帧。 | 
| ([DeviceFuncs::CreateWriteBack](#createwriteback)DeviceFuncs::CreateWriteBack)(uint32_t&nbsp;\*devId,&nbsp;uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format) | PixelFormat,&nbsp;接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 
| ([DeviceFuncs::DestroyWriteBack](#destroywriteback)&nbsp;)(uint32_t&nbsp;devId) | 销毁指定显示设备的回写点。 | 


## **类成员变量说明**


### CreateWriteBack

  
```
int32_t(* DeviceFuncs::CreateWriteBack) (uint32_t *devId, uint32_t width, uint32_t height, int32_t *format)
```

**描述：**

PixelFormat, 接口实现层可以根据硬件需求，修改format并返回给图形服务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID，接口实现层在创建完回写点后将回写点设备ID存放在该参数中返回给图形服务。 | 
| width | 输入参数，回写像素宽度。 | 
| height | 输入参数，回写像素高度。 | 
| format | 输入参数，回写点数据格式，详情参考[PixelFormat](_display.md#pixelformat)，接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### DestroyWriteBack

  
```
int32_t(* DeviceFuncs::DestroyWriteBack) (uint32_t devId)
```

**描述：**

销毁指定显示设备的回写点。

该接口用來销毁指定的回写点。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。
