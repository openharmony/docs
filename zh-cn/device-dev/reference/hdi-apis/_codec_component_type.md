# CodecComponentType


## **概述**

Codec组件接口定义。

主要提供以下功能:

- 获取组件的版本。

- 组件参数配置的获取和设置。

- 发送命令至组件及获取组件状态。

- 设置回调函数。

- 设置/释放组件使用的buffer。

- 编解码输入输出buffer处理 具体方法使用详见函数说明。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([GetComponentVersion](#getcomponentversion)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;struct&nbsp;CompVerInfo&nbsp;\*verInfo) | 获取Codec组件版本号。 | 
| ([SendCommand](#sendcommand)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;enum&nbsp;OMX_COMMANDTYPE&nbsp;cmd,&nbsp;uint32_t&nbsp;param,&nbsp;int8_t&nbsp;\*cmdData,&nbsp;uint32_t&nbsp;cmdDataLen) | 发送命令给组件。 | 
| ([GetParameter](#getparameter)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;paramIndex,&nbsp;int8_t&nbsp;\*paramStruct,&nbsp;uint32_t&nbsp;paramStructLen) | 获取组件参数设置。 | 
| ([SetParameter](#setparameter)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*paramStruct,&nbsp;uint32_t&nbsp;paramStructLen) | 设置组件需要的参数。 | 
| ([GetConfig](#getconfig)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*cfgStruct,&nbsp;uint32_t&nbsp;cfgStructLen) | 获取组件的配置结构。 | 
| ([SetConfig](#setconfig)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;index,&nbsp;int8_t&nbsp;\*cfgStruct,&nbsp;uint32_t&nbsp;cfgStructLen) | 设置组件的配置。 | 
| ([GetExtensionIndex](#getextensionindex)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;const&nbsp;char&nbsp;\*paramName,&nbsp;uint32_t&nbsp;\*indexType) | 根据字符串获取组件的扩展索引。 | 
| ([GetState](#getstate)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;enum&nbsp;OMX_STATETYPE&nbsp;\*state) | 获取组件的当前状态。 | 
| ([ComponentTunnelRequest](#componenttunnelrequest)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;port,&nbsp;int32_t&nbsp;tunneledComp,&nbsp;uint32_t&nbsp;tunneledPort,&nbsp;struct&nbsp;OMX_TUNNELSETUPTYPE&nbsp;\*tunnelSetup) | 设置组件采用Tunnel方式通信。 | 
| ([UseBuffer](#usebuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 指定组件端口的buffer。 | 
| ([AllocateBuffer](#allocatebuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 向组件申请端口buffer。 | 
| ([FreeBuffer](#freebuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint32_t&nbsp;portIndex,&nbsp;const&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 释放buffer。 | 
| ([EmptyThisBuffer](#emptythisbuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;const&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 编解码输入待处理buffer。 | 
| ([FillThisBuffer](#fillthisbuffer)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;const&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer) | 编解码输出填充buffer。 | 
| ([SetCallbacks](#setcallbacks)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;struct&nbsp;CodecCallbackType&nbsp;\*callback,&nbsp;int8_t&nbsp;\*appData,&nbsp;uint32_t&nbsp;appDataLen) | 设置Codec组件的回调函数。 | 
| ([ComponentDeInit](#componentdeinit)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self) | 组件去初始化。 | 
| ([UseEglImage](#useeglimage)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;struct&nbsp;OmxCodecBuffer&nbsp;\*buffer,&nbsp;uint32_t&nbsp;portIndex,&nbsp;int8_t&nbsp;\*eglImage,&nbsp;uint32_t&nbsp;eglImageLen) | 使用已在EGL中申请的空间。 | 
| ([ComponentRoleEnum](#componentroleenum)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*self,&nbsp;uint8_t&nbsp;\*role,&nbsp;uint32_t&nbsp;roleLen,&nbsp;uint32_t&nbsp;index) | 获取组件角色。 | 


## **类成员变量说明**


### AllocateBuffer

  
```
int32_t(* CodecComponentType::AllocateBuffer) (struct CodecComponentType *self, uint32_t portIndex, struct OmxCodecBuffer *buffer)
```

**描述：**

向组件申请端口buffer。

向组件申请分配新的buffer，此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且用户已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| buffer | 输入输出参数，指向要申请的buffer结构体[OmxCodecBuffer](_omx_codec_buffer.md)指针。 | 

**返回:**

HDF_SUCCESS 表示申请buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，申请buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，申请buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，申请buffer失败。


### ComponentDeInit

  
```
int32_t(* CodecComponentType::ComponentDeInit) (struct CodecComponentType *self)
```

**描述：**

组件去初始化。

调用此接口使组件去初始化，当组件处于OMX_StateLoaded状态时，将直接关闭组件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 

**返回:**

HDF_SUCCESS 表示去初始化成功。

HDF_ERR_INVALID_PARAM 表示参数无效，去初始化失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，去初始化失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，去初始化失败。


### ComponentRoleEnum

  
```
int32_t(* CodecComponentType::ComponentRoleEnum) (struct CodecComponentType *self, uint8_t *role, uint32_t roleLen, uint32_t index)
```

**描述：**

获取组件角色。

根据组件角色索引获取对应组件角色。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| role | 输出参数，角色名称。 | 
| roleLen | 输入参数，role字节数。 | 
| index | 输入参数，角色的索引，一个组件可能支持多种角色。 | 

**返回:**

HDF_SUCCESS 表示获取角色成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取角色失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取角色失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取角色失败。


### ComponentTunnelRequest

  
```
int32_t(* CodecComponentType::ComponentTunnelRequest) (struct CodecComponentType *self, uint32_t port, int32_t tunneledComp, uint32_t tunneledPort, struct OMX_TUNNELSETUPTYPE *tunnelSetup)
```

**描述：**

设置组件采用Tunnel方式通信。

当组件处于OMX_StateLoaded 状态时，用户通过调用此接口确定组件是否可以进行Tunnel传输，如果可以则设置组件的Tunnel传输。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| port | 输入参数，组件设置的端口。 | 
| tunneledComp | 输入参数，组件的tunnel&nbsp;handle。 | 
| tunneledPort | 输入参数，组件用来Tunnel通信的端口。 | 
| tunnelSetup | 输入输出参数，指向Tunnel设置的结构体**OMX_TUNNELSETUPTYPE**指针。 | 

**返回:**

HDF_SUCCESS 表示设置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置失败。


### EmptyThisBuffer

  
```
int32_t(* CodecComponentType::EmptyThisBuffer) (struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)
```

**描述：**

编解码输入待处理buffer。

此接口在组件处于OMX_StateExecuting或者OMX_StatePause状态时调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| buffer | 输入参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 

**返回:**

HDF_SUCCESS 表示输入buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，输入buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，输入buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，输入buffer失败。


### FillThisBuffer

  
```
int32_t(* CodecComponentType::FillThisBuffer) (struct CodecComponentType *self, const struct OmxCodecBuffer *buffer)
```

**描述：**

编解码输出填充buffer。

此接口在组件处于OMX_StateExecuting或者OMX_StatePause状态时调用。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| buffer | 输入参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 

**返回:**

HDF_SUCCESS 表示填充buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，填充buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，填充buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，填充buffer失败。


### FreeBuffer

  
```
int32_t(* CodecComponentType::FreeBuffer) (struct CodecComponentType *self, uint32_t portIndex, const struct OmxCodecBuffer *buffer)
```

**描述：**

释放buffer。

此接口在以下情况下使用：

- 当组件处于OMX_StateIdle状态，并且已经向组件发送OMX_StateLoaded状态转换请求。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle时调用。

- 此接口调用可随时进行，但是如果未在上述情况下执行，可能会导致组件上报OMX_ErrorPortUnpopulated事件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| buffer | 输入参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 

**返回:**

HDF_SUCCESS 表示释放buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，释放buffer失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，释放buffer失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，释放buffer失败。


### GetComponentVersion

  
```
int32_t(* CodecComponentType::GetComponentVersion) (struct CodecComponentType *self, struct CompVerInfo *verInfo)
```

**描述：**

获取Codec组件版本号。

通过查询组件，返回组件版本信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| verInfo | 输出参数，指向组件版本信息的指针，详见[CompVerInfo](_comp_ver_info.md)。 | 

**返回:**

HDF_SUCCESS 表示获取版本号成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取版本号失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取版本号失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取版本号失败。


### GetConfig

  
```
int32_t(* CodecComponentType::GetConfig) (struct CodecComponentType *self, uint32_t index, int8_t *cfgStruct, uint32_t cfgStructLen)
```

**描述：**

获取组件的配置结构。

加载组件后可以随时调用此接口获取组件的配置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| index | 输入参数，待填充结构的索引，详见**OMX_INDEXTYPE**。 | 
| cfgStruct | 输入输出参数，指向由组件填充的应用程序分配的结构体指针。 | 
| cfgStructLen | 输入参数，上层传入的cfgStruct字节数。 | 

**返回:**

HDF_SUCCESS 表示获取配置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取配置失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取配置失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取配置失败。


### GetExtensionIndex

  
```
int32_t(* CodecComponentType::GetExtensionIndex) (struct CodecComponentType *self, const char *paramName, uint32_t *indexType)
```

**描述：**

根据字符串获取组件的扩展索引。

将扩展字符串转换为Openmax IL结构索引。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| paramName | 输入参数，组件用来转换为配置索引的字符串。 | 
| indexType | 输出参数，由paramName转换的配置索引，详见**OMX_INDEXTYPE**。 | 

**返回:**

HDF_SUCCESS 表示获取扩展索引成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取扩展索引失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取扩展索引失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取扩展索引失败。


### GetParameter

  
```
int32_t(* CodecComponentType::GetParameter) (struct CodecComponentType *self, uint32_t paramIndex, int8_t *paramStruct, uint32_t paramStructLen)
```

**描述：**

获取组件参数设置。

当组件处于除了OMX_StateInvalid（组件状态异常）之外的其他状态，用户可通过此接口获取组件参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| paramIndex | 输入参数，待填充结构的索引，详见**OMX_INDEXTYPE**。 | 
| paramStruct | 输入输出参数，指向由组件填充的应用程序分配的结构体指针。 | 
| paramStructLen | 输入参数，paramStruct字节数。 | 

**返回:**

HDF_SUCCESS 表示获取参数成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取参数失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取参数失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取参数失败。


### GetState

  
```
int32_t(* CodecComponentType::GetState) (struct CodecComponentType *self, enum OMX_STATETYPE *state)
```

**描述：**

获取组件的当前状态。

用户可调用此接口获取组件的当前状态，组件状态详见**OMX_STATETYPE**。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| state | 输出参数，指向获取到的状态指针，组件状态详见**OMX_STATETYPE**。 | 

**返回:**

HDF_SUCCESS 表示获取状态成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取状态失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取状态失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取状态失败。


### SendCommand

  
```
int32_t(* CodecComponentType::SendCommand) (struct CodecComponentType *self, enum OMX_COMMANDTYPE cmd, uint32_t param, int8_t *cmdData, uint32_t cmdDataLen)
```

**描述：**

发送命令给组件。

当命令为设置状态时，会有事件回调通知结果给上层，其他命令则没有事件上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| cmd | 输入参数，组件要执行的命令，详见**OMX_COMMANDTYPE**。 | 
| param | 输入参数，组件要执行的命令携带的参数。<br/>-&nbsp;当cmd为OMX_CommandStateSet时，param的值详见**OMX_STATETYPE**。<br/>-&nbsp;当cmd为OMX_CommandFlush、OMX_CommandPortDisable、OMX_CommandPortEnable、OMX_CommandMarkBuffer时，param为目标端口。 | 
| cmdData | 输入参数，当cmd为OMX_CommandMarkBuffer时，指向OMX_MARKTYPE结构体指针。 | 
| cmdDataLen | 输入参数，上层传递的cmdData字节数。 | 

**返回:**

HDF_SUCCESS 表示发送命令成功。

HDF_ERR_INVALID_PARAM 表示参数无效，发送命令失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，发送命令失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，发送命令失败。


### SetCallbacks

  
```
int32_t(* CodecComponentType::SetCallbacks) (struct CodecComponentType *self, struct CodecCallbackType *callback, int8_t *appData, uint32_t appDataLen)
```

**描述：**

设置Codec组件的回调函数。

当组件处于OMX_StateLoaded状态时，使用此回调函数向上通知事件以及上报可用的输入输出信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| callback | 输入参数，指向回调函数[CodecCallbackType](_codec_callback_type.md)对象指针。 | 
| appData | 输入参数，指向应用程序定义的值的指针，该值将在回调期间返回。 | 
| appDataLen | 输入参数，上层传递的appData字节数。 | 

**返回:**

HDF_SUCCESS 表示设置回调成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置回调失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置回调失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置回调失败。


### SetConfig

  
```
int32_t(* CodecComponentType::SetConfig) (struct CodecComponentType *self, uint32_t index, int8_t *cfgStruct, uint32_t cfgStructLen)
```

**描述：**

设置组件的配置。

加载组件后可以随时调用此接口设置组件的配置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| index | 输入参数，要设置的结构索引，详见**OMX_INDEXTYPE**。 | 
| cfgStruct | 输入参数，指向组件用于初始化的应用程序分配结构的指针。 | 
| cfgStructLen | 输入参数，cfgStruct字节数。 | 

**返回:**

HDF_SUCCESS 表示设置配置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置失败。


### SetParameter

  
```
int32_t(* CodecComponentType::SetParameter) (struct CodecComponentType *self, uint32_t index, int8_t *paramStruct, uint32_t paramStructLen)
```

**描述：**

设置组件需要的参数。

当组件处于OMX_StateLoaded、OMX_StateWaitForResources状态或者端口是去使能状态，用户可通过此接口设置组件参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| index | 输入参数，要设置的结构索引，详见**OMX_INDEXTYPE**。 | 
| paramStruct | 输入参数，指向组件用于初始化的应用程序分配结构的指针。 | 
| paramStructLen | 输入参数，paramStruct字节数。 | 

**返回:**

HDF_SUCCESS 表示设置参数成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置参数失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，设置参数失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，设置参数失败。


### UseBuffer

  
```
int32_t(* CodecComponentType::UseBuffer) (struct CodecComponentType *self, uint32_t portIndex, struct OmxCodecBuffer *buffer)
```

**描述：**

指定组件端口的buffer。

此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且用户已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| buffer | 输入输出参数，指向要使用的buffer结构体[OmxCodecBuffer](_omx_codec_buffer.md)指针。 | 

**返回:**

HDF_SUCCESS 表示指定成功。

HDF_ERR_INVALID_PARAM 表示参数无效，指定失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，指定失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，指定失败。


### UseEglImage

  
```
int32_t(* CodecComponentType::UseEglImage) (struct CodecComponentType *self, struct OmxCodecBuffer *buffer, uint32_t portIndex, int8_t *eglImage, uint32_t eglImageLen)
```

**描述：**

使用已在EGL中申请的空间。

此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| self | 输入参数，指向要操作的Codec组件指针。 | 
| buffer | 输入输出参数，指向[OmxCodecBuffer](_omx_codec_buffer.md)结构体的指针。 | 
| portIndex | 输入参数，指定的组件端口。 | 
| eglImage | 输入参数，EGL申请的图像指针。 | 
| eglImageLen | 输入参数，eglImage字节数。 | 

**返回:**

HDF_SUCCESS 表示使用成功。

HDF_ERR_INVALID_PARAM 表示参数无效，使用失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，使用失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，使用失败。
