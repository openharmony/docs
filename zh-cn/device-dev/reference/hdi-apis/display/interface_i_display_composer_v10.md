# IDisplayComposer


## 概述

显示合成接口声明。

主要提供注册热插拔事件回调、获取显示设备能力集等功能，具体方法使用详见函数说明。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegHotPlugCallback](#reghotplugcallback) ([in] [IHotPlugCallback](interface_i_hot_plug_callback_v10.md) cb) | 注册热插拔事件回调。 | 
| [SetClientBufferCacheCount](#setclientbuffercachecount) ([in] unsigned int devId, [in] unsigned int count) | 设置显示设备的客户端缓冲区缓存计数。 | 
| [RegDisplayVBlankCallback](#regdisplayvblankcallback) ([in] unsigned int devId, [in] [IVBlankCallback](interface_i_v_blank_callback_v10.md) cb) | 注册VBlank事件回调。 | 
| [GetDisplayCapability](#getdisplaycapability) ([in] unsigned int devId, [out] struct [DisplayCapability](_display_capability_v10.md) info) | 获取显示设备能力集。 | 
| [GetDisplaySupportedModes](#getdisplaysupportedmodes) ([in] unsigned int devId, [out] struct [DisplayModeInfo](_display_mode_info_v10.md)[] modes) | 获取显示设备支持的显示模式信息。 | 
| [GetDisplayMode](#getdisplaymode) ([in] unsigned int devId, [out] unsigned int modeId) | 获取显示设备当前的显示模式。 | 
| [SetDisplayMode](#setdisplaymode) ([in] unsigned int devId, [in] unsigned int modeId) | 设置显示设备的显示模式。 | 
| [GetDisplayPowerStatus](#getdisplaypowerstatus) ([in] unsigned int devId, [out] enum [DispPowerStatus](_display_v10.md#disppowerstatus) status) | 获取显示设备当前的电源状态。 | 
| [SetDisplayPowerStatus](#setdisplaypowerstatus) ([in] unsigned int devId, [in] enum [DispPowerStatus](_display_v10.md#disppowerstatus) status) | 设置显示设备当前的电源状态。 | 
| [GetDisplayBacklight](#getdisplaybacklight) ([in] unsigned int devId, [out] unsigned int level) | 获取显示设备当前的背光值。 | 
| [SetDisplayBacklight](#setdisplaybacklight) ([in] unsigned int devId, [in] unsigned int level) | 设置显示设备当前的背光值。 | 
| [SetDisplayVsyncEnabled](#setdisplayvsyncenabled) ([in] unsigned int devId, [in] boolean enabled) | 使能垂直同步信号。 | 
| [CreateLayer](#createlayer) ([in] unsigned int devId, [in] struct [LayerInfo](_layer_info_v10.md) layerInfo, [in] unsigned int cacheCount, [out] unsigned int layerId) | 打开图层。 | 
| [DestroyLayer](#destroylayer) ([in] unsigned int devId, [in] unsigned int layerId) | 在指定的显示设备上打开图层。 | 
| [SetDisplayClientCrop](#setdisplayclientcrop) ([in] unsigned int devId, [in] struct [IRect](_i_rect_v10.md) rect) | 设置显示设备的裁剪区域。 | 
| [GetDisplayReleaseFence](#getdisplayreleasefence) ([in] unsigned int devId, [out] unsigned int[] layers, [out] HdifdParcelable[] fences) | 获取显示图层fence。 | 
| [CreateVirtualDisplay](#createvirtualdisplay) ([in] unsigned int width, [in] unsigned int height, [out] int format, [out] unsigned int devId) | 创建虚拟显示设备。 | 
| [DestroyVirtualDisplay](#destroyvirtualdisplay) ([in] unsigned int devId) | 销毁虚拟显示设备。 | 
| [SetVirtualDisplayBuffer](#setvirtualdisplaybuffer) ([in] unsigned int devId, [in] NativeBuffer buffer, [in] HdifdParcelable fence) | 设置虚拟屏的输出缓存。 | 
| [SetDisplayProperty](#setdisplayproperty) ([in] unsigned int devId, [in] unsigned int id, [in] unsigned long value) | 设置显示设备属性值。 | 
| [GetDisplayProperty](#getdisplayproperty) ([in] unsigned int devId, [in] unsigned int id, [out] unsigned long value) | 获取显示设备属性值。 | 
| [InitCmdRequest](#initcmdrequest) ([in] SharedMemQueue&lt; int &gt; request) | 初始化命令请求对象。 | 
| [CmdRequest](#cmdrequest) ([in] unsigned int inEleCnt, [in] struct [HdifdInfo](_hdifd_info_v10.md)[] inFds, [out] unsigned int outEleCnt, [out] struct [HdifdInfo](_hdifd_info_v10.md)[] outFds) | 发送命令请求。 | 
| [GetCmdReply](#getcmdreply) ([out] SharedMemQueue&lt; int &gt; reply) | 获取命令请求的返回结果。 | 


## 成员函数说明


### CmdRequest()

```
IDisplayComposer::CmdRequest ([in] unsigned int inEleCnt, [in] struct HdifdInfo[] inFds, [out] unsigned int outEleCnt, [out] struct HdifdInfo[] outFds)
```

**描述**


发送命令请求。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inEleCnt | 表示元素的个数。 | 
| inFds | 表示 HdifdParcelable 的 ID。 | 
| outEleCnt | 指示要获取的元素数。 | 
| outFds | 指示要获取的 HdifdParcelable 的 ID。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### CreateLayer()

```
IDisplayComposer::CreateLayer ([in] unsigned int devId, [in] struct LayerInfo layerInfo, [in] unsigned int cacheCount, [out] unsigned int layerId)
```

**描述**


打开图层。

GUI在使用图层时，需要先根据图层信息打开图层，打开图层成功可获得图层ID，根据图层ID使用图层各接口。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备，即取值范围0~4。 | 
| layerInfo | 图层信息，上层GUI打开图层时需传递图层信息，包括图层类型，图层大小，像素格式等信息。 |
| cacheCount | 缓冲区缓存的计数。 | 
| layerId | 图层ID，打开图层成功后返回给GUI的图层ID，用于标识唯一的图层。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。

**参见：**

CloseLayer


### CreateVirtualDisplay()

```
IDisplayComposer::CreateVirtualDisplay ([in] unsigned int width, [in] unsigned int height, [out] int format, [out] unsigned int devId)
```

**描述**


创建虚拟显示设备。

该接口用于创建一个虚拟显示设备。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| width | 指定显示设备的像素宽度。 | 
| height | 指定显示设备的像素高度。 | 
| format | 指定显示设备的像素格式。 详情参考[PixelFormat](_display_v10.md#pixelformat)，接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 
| devId | 用于接口层返回创建的设备ID。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### DestroyLayer()

```
IDisplayComposer::DestroyLayer ([in] unsigned int devId, [in] unsigned int layerId)
```

**描述**


在指定的显示设备上打开图层。

在 GUI 上使用图层之前，必须根据图层信息打开图层。在图层 打开后，可以获取图层 ID，然后根据图层 ID 使用其他功能。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId| 显示设备的ID。<br/>取值范围为  0 到 4，其中 0 表示第一个显示设备，4 表示最后一个显示设备。 | 
| layerId | 指示指向唯一标识层的层 ID 的指针。返回图层 ID到图层成功打开后添加到 GUI。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### DestroyVirtualDisplay()

```
IDisplayComposer::DestroyVirtualDisplay ([in] unsigned int devId)
```

**描述**


销毁虚拟显示设备。

该接口用于销毁指定的虚拟显示设备。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetCmdReply()

```
IDisplayComposer::GetCmdReply ([out] SharedMemQueue< int > reply)
```

**描述**


获取命令请求的返回结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| reply | 表示返回的结果。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayBacklight()

```
IDisplayComposer::GetDisplayBacklight ([in] unsigned int devId, [out] unsigned int level)
```

**描述**


获取显示设备当前的背光值。

图形服务可以通过该接口获取设置显示设备的背光值。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| level | 保存对应设备的背光值，由接口实现层进行写入。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayCapability()

```
IDisplayComposer::GetDisplayCapability ([in] unsigned int devId, [out] struct DisplayCapability info)
```

**描述**


获取显示设备能力集。

图形服务可以通过该接口获取显示设备具备哪些显示能力。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| info | 设备支持的能力集信息，详情参考 [DisplayCapability](_display_capability_v10.md)。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayMode()

```
IDisplayComposer::GetDisplayMode ([in] unsigned int devId, [out] unsigned int modeId)
```

**描述**


获取显示设备当前的显示模式。

图形服务可以通过该接口获取显示设备当前的显示模式，该模式由接口实现层进行数据的写入。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| modeId | 存放当前设备的显示模式ID。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayPowerStatus()

```
IDisplayComposer::GetDisplayPowerStatus ([in] unsigned int devId, [out] enum DispPowerStatus status)
```

**描述**


获取显示设备当前的电源状态。

图形服务可以通过该接口获取设置显示设备的电源状态，该电源状态由接口实现层进行状态的写入。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| status | 保存对应设备的电源状态，具体电源状态查看[DispPowerStatus](_display_v10.md#disppowerstatus)。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayProperty()

```
IDisplayComposer::GetDisplayProperty ([in] unsigned int devId, [in] unsigned int id, [out] unsigned long value)
```

**描述**


获取显示设备属性值。

图形服务可以通过该接口获取显示设备具体的属性值。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 指示需要操作的设备ID。 | 
| id | 由接口{\@Link GetDisplayCapability}返回的属性ID。 | 
| value | 属性ID对应的属性值，由接口实现层写入。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplayReleaseFence()

```
IDisplayComposer::GetDisplayReleaseFence ([in] unsigned int devId, [out] unsigned int[] layers, [out] HdifdParcelable[] fences)
```

**描述**


获取显示图层fence。

图形服务在调用接口Commit后，需要通过该接口获取图层的fence信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| layers | 图层首地址，指向图层数组的首地址。 | 
| fences | fence首地址，指向fence数组的首地址。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### GetDisplaySupportedModes()

```
IDisplayComposer::GetDisplaySupportedModes ([in] unsigned int devId, [out] struct DisplayModeInfo[] modes)
```

**描述**


获取显示设备支持的显示模式信息。

图形服务可以通过该接口获取到显示设备支持哪些显示模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| modes | 设备支持的所有模式信息，包括所有能支持的分辨率和刷新率，每一个模式实现层都有一个ID与之对应，在获取当前模式 和设置当前模式时都会使用到，详情参考 [DisplayModeInfo](_display_mode_info_v10.md)。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### InitCmdRequest()

```
IDisplayComposer::InitCmdRequest ([in] SharedMemQueue< int > request)
```

**描述**


初始化命令请求对象。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| request | 指示要初始化的 SharedMemQueue。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### RegDisplayVBlankCallback()

```
IDisplayComposer::RegDisplayVBlankCallback ([in] unsigned int devId, [in] IVBlankCallback cb)
```

**描述**


注册VBlank事件回调，当有VBlank事件发生时接口实现层需要回调注册的接口。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| cb | VBlank事件回调实例，当有VBlank事件发生时并且DisplayVsync处于Enable状态,接口实现层需要通过该实例通知图形服务。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### RegHotPlugCallback()

```
IDisplayComposer::RegHotPlugCallback ([in] IHotPlugCallback cb)
```

**描述**


注册热插拔事件回调，当有热插拔事件发生时接口实现层需要回调注册的接口，通过该实例通知图形服务。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cb | 热插拔事件回调实例。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetClientBufferCacheCount()

```
IDisplayComposer::SetClientBufferCacheCount ([in] unsigned int devId, [in] unsigned int count)
```

**描述**


设置显示设备的客户端缓冲区缓存计数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| count | 客户端缓冲区缓存计数。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayBacklight()

```
IDisplayComposer::SetDisplayBacklight ([in] unsigned int devId, [in] unsigned int level)
```

**描述**


设置显示设备当前的背光值。

图形服务可以通过该接口获取设置显示设备的背光值。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| level | 表示需要设置的背光值，背光值范围0~255。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayClientCrop()

```
IDisplayComposer::SetDisplayClientCrop ([in] unsigned int devId, [in] struct IRect rect)
```

**描述**


设置显示设备的裁剪区域。

图形服务可以通过该接口设置显示设备的ClientBuffer的裁剪区域，裁剪区域不能超过ClientBuffer的大小。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| rect | ClientBuffer的裁剪区域。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayMode()

```
IDisplayComposer::SetDisplayMode ([in] unsigned int devId, [in] unsigned int modeId)
```

**描述**


设置显示设备的显示模式。

图形服务可以通过该接口获取设置显示设备的显示模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| modeId | 指明需要设置的模式ID，接口实现层将设备切换到该参数对应的显示模式。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayPowerStatus()

```
IDisplayComposer::SetDisplayPowerStatus ([in] unsigned int devId, [in] enum DispPowerStatus status)
```

**描述**


设置显示设备当前的电源状态。

图形服务可以通过该接口获取设置显示设备的电源状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| status | 表示需要设置的电源状态，具体电源状态查看[DispPowerStatus](_display_v10.md#disppowerstatus)。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayProperty()

```
IDisplayComposer::SetDisplayProperty ([in] unsigned int devId, [in] unsigned int id, [in] unsigned long value)
```

**描述**


设置显示设备属性值。

图形服务可以通过该接口设置显示设备具体的属性值。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| id | 由接口[GetDisplayCapability](#getdisplaycapability)返回属性ID。 | 
| value | 需要设置的属性值。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetDisplayVsyncEnabled()

```
IDisplayComposer::SetDisplayVsyncEnabled ([in] unsigned int devId, [in] boolean enabled)
```

**描述**


使能垂直同步信号。

图形服务可以通过该接口使能或取消垂直同步信号，当有垂直同步信号产生时，接口实现层需要回调图形服务通过RegDisplayVBlankCallback注册的 VBlankCallback 回调。 图形服务在需要刷新显示时需要使能垂直同步信号，在收到**VBlankCallback**事件回调时再进行合成送显,不需要刷新显示时需要取消垂直同步信号。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| enabled | 使能状态，true表示能，false表示不能。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### SetVirtualDisplayBuffer()

```
IDisplayComposer::SetVirtualDisplayBuffer ([in] unsigned int devId, [in] NativeBuffer buffer, [in] HdifdParcelable fence)
```

**描述**


设置虚拟屏的输出缓存。

该接口用于设置虚拟屏输出缓存，接口实现层需要将虚拟屏的输出放入到该缓存中，接口实现层需要等待同步栅栏发送信号后才能使用缓存。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devId | 表示需要操作的设备ID。 | 
| buffer | 输出缓存。 | 
| fence | 同步栅栏。 | 

**返回：**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
