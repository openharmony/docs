# CodecComponentType


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[GetComponentVersion](_codec.md#getcomponentversion)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;struct&nbsp;[CompVerInfo](_comp_ver_info.md)&nbsp;\*verInfo) | 获取Codec组件版本号。&nbsp;[更多...](_codec.md#getcomponentversion) | 
| (&nbsp;[SendCommand](_codec.md#sendcommand)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;enum&nbsp;OMX_COMMANDTYPE&nbsp;cmd,&nbsp;uint32_t&nbsp;param,&nbsp;int8_t&nbsp;\*cmdData,&nbsp;uint32_t&nbsp;cmdDataLen) | 发送命令给组件。&nbsp;[更多...](_codec.md#sendcommand) | 
| (&nbsp;[GetParameter](_codec.md#getparameter)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;paramIndex,&nbsp;int8_t&nbsp;\*paramStruct,&nbsp;uint32_t&nbsp;paramStructLen) | 获取组件参数设置。&nbsp;[更多...](_codec.md#getparameter) | 
| (&nbsp;[SetParameter](_codec.md#setparameter)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*paramStruct,&nbsp;uint32_t&nbsp;paramStructLen) | 设置组件需要的参数。&nbsp;[更多...](_codec.md#setparameter) | 
| (&nbsp;[GetConfig](_codec.md#getconfig)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*cfgStruct,&nbsp;uint32_t&nbsp;cfgStructLen) | 获取组件的配置结构。&nbsp;[更多...](_codec.md#getconfig) | 
| (&nbsp;[SetConfig](_codec.md#setconfig)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*cfgStruct,&nbsp;uint32_t&nbsp;cfgStructLen) | 设置组件的配置。&nbsp;[更多...](_codec.md#setconfig) | 
| (&nbsp;[GetExtensionIndex](_codec.md#getextensionindex)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;const&nbsp;char&nbsp;\*paramName,&nbsp;uint32_t&nbsp;\*indexType) | 根据字符串获取组件的扩展索引。&nbsp;[更多...](_codec.md#getextensionindex) | 
| (&nbsp;[GetState](_codec.md#getstate)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;enum&nbsp;OMX_STATETYPE&nbsp;\*state) | 获取组件的当前状态。&nbsp;[更多...](_codec.md#getstate) | 
| (&nbsp;[ComponentTunnelRequest](_codec.md#componenttunnelrequest)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;port,&nbsp;int32_t&nbsp;tunneledComp,&nbsp;uint32_t&nbsp;tunneledPort,&nbsp;struct&nbsp;OMX_TUNNELSETUPTYPE&nbsp;\*tunnelSetup) | 设置组件采用Tunnel方式通信。&nbsp;[更多...](_codec.md#componenttunnelrequest) | 
| (&nbsp;[UseBuffer](_codec.md#usebuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 指定组件端口的buffer。&nbsp;[更多...](_codec.md#usebuffer) | 
| (&nbsp;[AllocateBuffer](_codec.md#allocatebuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 向组件申请端口buffer。&nbsp;[更多...](_codec.md#allocatebuffer) | 
| (&nbsp;[FreeBuffer](_codec.md#freebuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 释放buffer。&nbsp;[更多...](_codec.md#freebuffer) | 
| (&nbsp;[EmptyThisBuffer](_codec.md#emptythisbuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 编解码输入待处理buffer。&nbsp;[更多...](_codec.md#emptythisbuffer) | 
| (&nbsp;[FillThisBuffer](_codec.md#fillthisbuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;const&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer) | 编解码输出填充buffer。&nbsp;[更多...](_codec.md#fillthisbuffer) | 
| (&nbsp;[SetCallbacks](_codec.md#setcallbacks)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*callback,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen) | 设置Codec组件的回调函数。&nbsp;[更多...](_codec.md#setcallbacks) | 
| (&nbsp;[ComponentDeInit](_codec.md#componentdeinit)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self) | 组件去初始化。&nbsp;[更多...](_codec.md#componentdeinit) | 
| (&nbsp;[UseEglImage](_codec.md#useeglimage)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;struct&nbsp;[OmxCodecBuffer](_omx_codec_buffer.md)&nbsp;\*buffer,&nbsp;uint32_t&nbsp;portIndex,&nbsp;int8_t&nbsp;\*eglImage,&nbsp;uint32_t&nbsp;eglImageLen) | 使用已在EGL中申请的空间。&nbsp;[更多...](_codec.md#useeglimage) | 
| (&nbsp;[ComponentRoleEnum](_codec.md#componentroleenum)&nbsp;)(struct&nbsp;[CodecComponentType&nbsp;\*self,&nbsp;uint8_t&nbsp;\*role,&nbsp;uint32_t&nbsp;roleLen,&nbsp;uint32_t&nbsp;index) | 获取组件角色。&nbsp;[更多...](_codec.md#componentroleenum) | 


## **详细描述**

Codec组件接口定义。

主要提供以下功能：

- 获取组件的版本。

- 组件参数配置的获取和设置。

- 发送命令至组件及获取组件状态。

- 设置回调函数。

- 设置/释放组件使用的buffer。

- 编解码输入输出buffer处理 具体方法使用详见函数说明。
