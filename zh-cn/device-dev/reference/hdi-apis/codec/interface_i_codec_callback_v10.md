# ICodecCallback


## 概述

Codec回调接口定义。

提供了以下3种回调函数:

- 组件错误事件、命令完成事件、端口设置等事件回调，详见[EventHandler](#eventhandler)。

- 输入端口处理完buffer回调，详见[EmptyBufferDone](#emptybufferdone)。

- 输出端口填充完buffer回调，详见[FillBufferDone](#fillbufferdone)。 通过以下两种方式注册回调:

- 创建组件时，通过[CreateComponent](interface_i_codec_component_manager_v10.md#createcomponent)方法。

- 当组件处于OMX_StateLoaded状态时，通过[SetCallbacks](interface_i_codec_component_v10.md#setcallbacks)方法注册回调。

**起始版本：** 3.2

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [EventHandler](#eventhandler) ([in] enum OMX_EVENTTYPE event, [in] struct [EventInfo](_event_info_v10.md) info) | 事件上报。  | 
| [EmptyBufferDone](#emptybufferdone) ([in] long appData, [in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) buffer) | 上报输入buffer编码或者解码处理完毕。  | 
| [FillBufferDone](#fillbufferdone) ([in] long appData, [in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) buffer) | 上报输出buffer填充完毕。  | 


## 成员函数说明


### EmptyBufferDone()

```
ICodecCallback::EmptyBufferDone ([in] long appData, [in] struct OmxCodecBuffer buffer )
```
**描述**

上报输入buffer编码或者解码处理完毕。

组件运行过程中向上报告输入buffer已经使用完毕。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| appData | 上层数据，通常是设置回调时给入的上层实例。  | 
| buffer | 已经处理完毕的输入buffer信息[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，上报失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的[OMX_ERRORTYPE](https://gitee.com/openharmony/third_party_openmax/blob/master/api/1.1.2/OMX_Core.h)。


### EventHandler()

```
ICodecCallback::EventHandler ([in] enum OMX_EVENTTYPE event, [in] struct EventInfo info )
```
**描述**

事件上报。

组件运行过程中向上报告错误事件、命令完成事件、端口设置更改事件等。

- 当eEvent为OMX_EventCmdComplete，eventData为NULL，data1数据为OMX_COMMANDTYPE, 此时，当data1为OMX_CommandStateSet，data2表示状态，其它情况下，data2表示端口。

- 当event为OMX_EventError时，data1表示错误码，data2和eventData都为0。

- 当event为OMX_EventMark时，data1和data2都为0，eventData指向mark指针。

- 当event为OMX_EventPortSettingsChanged时，data1表示端口，data2和eventData为0。

- 当event为OMX_EventBufferFlag时，data1表示端口，data2表示flag，eventData为0。

- 当event为OMX_EventResourcesAcquired或OMX_EventDynamicResourcesAvailable时，data1、data2和eventData都为0。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 要通知的事件类型，详见[OMX_EVENTTYPE](https://gitee.com/openharmony/third_party_openmax/blob/master/api/1.1.2/OMX_Core.h)。  | 
| info | 指向事件上报携带的信息指针，详见[EventInfo](_event_info_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示事件上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，事件上报失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的[OMX_ERRORTYPE](https://gitee.com/openharmony/third_party_openmax/blob/master/api/1.1.2/OMX_Core.h)。


### FillBufferDone()

```
ICodecCallback::FillBufferDone ([in] long appData, [in] struct OmxCodecBuffer buffer )
```
**描述**

上报输出buffer填充完毕。

组件运行过程中向上报告输出buffer已经填充完毕。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| appData | 上层数据，通常是设置回调时给入的上层实例。  | 
| buffer | 已经填充完毕的buffer信息[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，上报失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的[OMX_ERRORTYPE](https://gitee.com/openharmony/third_party_openmax/blob/master/api/1.1.2/OMX_Core.h)。
