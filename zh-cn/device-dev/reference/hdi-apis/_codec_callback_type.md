# CodecCallbackType


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [remote](_codec.md#remote) | 指向HdfRemoteService的指针。&nbsp;[更多...](_codec.md#remote) | 
| (&nbsp;[EventHandler](_codec.md#eventhandler)&nbsp;)(struct&nbsp;CodecCallbackType&nbsp;\*self,&nbsp;enum&nbsp;OMX_EVENTTYPE&nbsp;event,&nbsp;struct&nbsp;[EventInfo](_event_info.md)&nbsp;\*info) | 事件上报。&nbsp;[更多...](_codec.md#eventhandler) | 
| (&nbsp;[EmptyBufferDone](_codec.md#emptybufferdone)&nbsp;)(struct&nbsp;CodecCallbackType&nbsp;\*self,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 上报输入buffer编码或者解码处理完毕。&nbsp;[更多...](_codec.md#emptybufferdone) | 
| (&nbsp;[FillBufferDone](_codec.md#fillbufferdone)&nbsp;)(struct&nbsp;CodecCallbackType&nbsp;\*self,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 上报输出buffer填充完毕。&nbsp;[更多...](_codec.md#fillbufferdone) | 


## **详细描述**

Codec回调接口定义。

提供了以下3种回调函数:

- 组件错误事件、命令完成事件、端口设置等事件回调，详见EventHandler。

- 输入端口处理完buffer回调，详见EmptyBufferDone。

- 输出端口填充完buffer回调，详见FillBufferDone。 通过以下两种方式注册回调:

- 创建组件时，通过CreateComponent方法。

- 当组件处于OMX_StateLoaded状态时，通过SetCallbacks方法注册回调。
