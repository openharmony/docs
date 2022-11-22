# CodecCallbackType


## **概述**

Codec回调接口定义。

提供了以下3种回调函数:

- 组件错误事件、命令完成事件、端口设置等事件回调，详见[EventHandler](#eventhandler)。

- 输入端口处理完buffer回调，详见[EmptyBufferDone](#emptybufferdone)。

- 输出端口填充完buffer回调，详见[FillBufferDone](#fillbufferdone)。 通过以下两种方式注册回调：
  - 创建组件时，通过[CreateComponent](_codec_component_manager.md#createcomponent)方法。
  - 当组件处于OMX_StateLoaded状态时，通过[SetCallbacks](_codec_component_type.md#setcallbacks)方法注册回调。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [remote](#remote) | 指向HdfRemoteService的指针。 | 
| ([EventHandler](#eventhandler)&nbsp;)(struct&nbsp;CodecCallbackType&nbsp;\*self,&nbsp;enum&nbsp;OMX_EVENTTYPE&nbsp;event,&nbsp;struct&nbsp;EventInfo&nbsp;\*info) | 事件上报。 | 
| ([EmptyBufferDone](#emptybufferdone)&nbsp;)(struct&nbsp;CodecCallbackType&nbsp;\*self,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen,&nbsp;const&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 上报输入buffer编码或者解码处理完毕。 | 
| ([FillBufferDone](#fillbufferdone)&nbsp;)(struct&nbsp;CodecCallbackType&nbsp;\*self,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen,&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 上报输出buffer填充完毕。 | 


## **类成员变量说明**


### EmptyBufferDone

  
```
int32_t(* CodecCallbackType::EmptyBufferDone) (struct CodecCallbackType *self, int8_t *appData, uint32_t appDataLen, const struct OmxCodecBuffer *buffer)
```

**描述：**

上报输入buffer编码或者解码处理完毕。

组件运行过程中向上报告输入buffer已经使用完毕。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的callback指针。 | 
| appData | 输入参数，上层数据，通常是设置回调时给入的上层实例。 | 
| appDataLen | 输入参数，appData字节数。 | 
| buffer | 输入参数，已经处理完毕的输入buffer信息[OmxCodecBuffer](_omx_codec_buffer.md)。 | 

**返回:**

HDF_SUCCESS 表示上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，上报失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，上报失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，上报失败。


### EventHandler

  
```
int32_t(* CodecCallbackType::EventHandler) (struct CodecCallbackType *self, enum OMX_EVENTTYPE event, struct EventInfo *info)
```

**描述：**

事件上报。

组件运行过程中向上报告错误事件、命令完成事件、端口设置更改事件等。

- 当eEvent为OMX_EventCmdComplete，eventData为NULL，data1 数据为OMX_COMMANDTYPE, 此时，当data1为OMX_CommandStateSet，data2表示状态，其它情况下，data2表示端口。

- 当event为OMX_EventError时，data1表示错误码，data2和eventData都为0。

- 当event为OMX_EventMark时，data1和data2都为0，eventData指向mark指针。

- 当event为OMX_EventPortSettingsChanged时，data1表示端口，data2和eventData为0。

- 当event为OMX_EventBufferFlag时，data1表示端口，data2表示flag，eventData为0。

- 当event为OMX_EventResourcesAcquired或OMX_EventDynamicResourcesAvailable时，data1、data2和eventData都为0。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的callback指针。 | 
| event | 输入参数，要通知的事件类型。 | 
| info | 输入参数，指向事件上报携带的信息指针，详见[EventInfo](_event_info.md)。 | 

**返回:**

HDF_SUCCESS 表示事件上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，事件上报失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，事件上报失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，事件上报失败。


### FillBufferDone

  
```
int32_t(* CodecCallbackType::FillBufferDone) (struct CodecCallbackType *self, int8_t *appData, uint32_t appDataLen, struct OmxCodecBuffer *buffer)
```

**描述：**

上报输出buffer填充完毕。

组件运行过程中向上报告输出buffer已经填充完毕。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的callback指针。 | 
| appData | 输入参数，上层数据，通常是设置回调时给入的上层实例。 | 
| appDataLen | 输入参数，appData字节数。 | 
| buffer | 输入参数，已经填充完毕的buffer信息[OmxCodecBuffer](_omx_codec_buffer.md)。 | 

**返回:**

HDF_SUCCESS 表示上报成功。

HDF_ERR_INVALID_PARAM 表示参数无效，上报失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，上报失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，上报失败。


### remote

  
```
struct HdfRemoteService* CodecCallbackType::remote
```

**描述：**

指向HdfRemoteService的指针。
