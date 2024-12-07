# IDisplayComposer


## 概述

显示合成接口声明。

主要提供注册热插拔事件回调、获取显示设备能力集等功能，具体方法使用详见函数说明。

**起始版本：** 4.1

**相关模块：**[Display](_display_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegSeamlessChangeCallback](#regseamlesschangecallback) ([in] [ISeamlessChangeCallback](interface_i_seamless_change_callback_v11.md) cb) | 注册要在准备好更改帧速率时调用的回调。 | 
| [GetDisplaySupportedModesExt](#getdisplaysupportedmodesext) ([in] unsigned int devId, [out] struct [DisplayModeInfoExt](_display_mode_info_ext_v11.md)[] modes) | 获取显示设备支持的显示模式。 | 
| [SetDisplayModeAsync](#setdisplaymodeasync) ([in] unsigned int devId, [in] unsigned int modeId, [in] [IModeCallback](interface_i_mode_callback_v11.md) cb) | 设置显示设备的显示模式。 | 
| [GetDisplayVBlankPeriod](#getdisplayvblankperiod) ([in] unsigned int devId, [out] unsigned long period) | 获取当前 vblank 周期。 | 
| [SetLayerPerFrameParameter](#setlayerperframeparameter) ([in] unsigned int devId, [in] unsigned int layerId, [in] String key, [out] byte[] value) | 设置给定图层的参数，参数更改必须在此调用后完全生效。 | 
| [GetSupportedLayerPerFrameParameterKey](#getsupportedlayerperframeparameterkey) ([out] String[] keys) | 返回支持的参数键的列表 | 
| [SetDisplayOverlayResolution](#setdisplayoverlayresolution) ([in] unsigned int devId, [in] unsigned int width, [in] unsigned int height) | 设置给定图层的参数，参数更改必须在此调用后完全生效。 | 
| [RegRefreshCallback](#regrefreshcallback) ([in] IRefreshCallback cb) | 注册要在发生刷新事件时调用的回调。 | 
| [GetDisplaySupportedColorGamuts](#getdisplaysupportedcolorgamuts) ([in] unsigned int devId, [out] struct ColorGamut[] gamuts) | 获取显示设备的色域。 | 
| [GetHDRCapabilityInfos](#gethdrcapabilityinfos) ([in] unsigned int devId, [out] struct HDRCapability info) | 获取显示设备的功能。 | 


## 成员函数说明


### GetDisplaySupportedColorGamuts()

```
IDisplayComposer::GetDisplaySupportedColorGamuts ([in] unsigned int devId, [out] struct ColorGamut[] gamuts )
```

**描述**


获取显示设备的色域。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| gamuts | 指示有关显示设备支持的所有色域的信息的向量。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplaySupportedModesExt()

```
IDisplayComposer::GetDisplaySupportedModesExt ([in] unsigned int devId, [out] struct DisplayModeInfoExt[] modes )
```

**描述**


获取显示设备支持的显示模式。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| modes | 表示有关显示设备支持的所有模式的信息向量， 包括所有支持的分辨率、刷新率和 groupId。每种模式都有一个 ID，该 ID 将在以下情况下使用 模式已设置或获取。有关详细信息，请参阅 [DisplayModeInfoExt](_display_mode_info_ext_v11.md)。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayVBlankPeriod()

```
IDisplayComposer::GetDisplayVBlankPeriod ([in] unsigned int devId, [out] unsigned long period )
```

**描述**


获取当前 vblank 周期。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| period | 指示 vblank 周期 （ns）。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetHDRCapabilityInfos()

```
IDisplayComposer::GetHDRCapabilityInfos ([in] unsigned int devId, [out] struct HDRCapability info )
```

**描述**


获取显示设备的功能。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| info | 指示指向 hdr 设备支持的功能的指针。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetSupportedLayerPerFrameParameterKey()

```
IDisplayComposer::GetSupportedLayerPerFrameParameterKey ([out] String[] keys)
```

**描述**


返回支持的参数键的列表

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keys | 指示支持的参数键。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### RegRefreshCallback()

```
IDisplayComposer::RegRefreshCallback ([in] IRefreshCallback cb)
```

**描述**


注册要在发生刷新事件时调用的回调。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cb | 指示用于通知图形服务发生刷新事件的实例。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### RegSeamlessChangeCallback()

```
IDisplayComposer::RegSeamlessChangeCallback ([in] ISeamlessChangeCallback cb)
```

**描述**


注册要在准备好更改帧速率时调用的回调。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cb | 指示用于通知图形服务已准备好更改帧速率的实例。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayModeAsync()

```
IDisplayComposer::SetDisplayModeAsync ([in] unsigned int devId, [in] unsigned int modeId, [in] IModeCallback cb )
```

**描述**


设置显示设备的显示模式。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| modeId | 指示显示模式的 ID。设备切换到指定的显示模式 此接口中的此参数。 | 
| cb | 表示更改模式时要调用的回调。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayOverlayResolution()

```
IDisplayComposer::SetDisplayOverlayResolution ([in] unsigned int devId, [in] unsigned int width, [in] unsigned int height )
```

**描述**


设置给定图层的参数，参数更改必须在此调用后完全生效。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| width | 指示显示设备的像素宽度 | 
| height | 指示显示设备的像素高度 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetLayerPerFrameParameter()

```
IDisplayComposer::SetLayerPerFrameParameter ([in] unsigned int devId, [in] unsigned int layerId, [in] String key, [out] byte[] value )
```

**描述**


设置给定图层的参数，参数更改必须在此调用后完全生效。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示显示设备的 ID。 | 
| layerId | 指示要操作的层的 ID。 | 
| key | 指示特定键。 | 
| value | 指示与键对应的值。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
