# ICodecComponent


## 概述

Codec组件接口定义。

主要提供以下功能：

- 获取组件的版本

- 组件参数配置的获取和设置

- 发送命令至组件及获取组件状态

- 设置回调函数

- 设置/释放组件使用的buffer

- 编解码输入输出buffer处理

具体方法使用详见函数说明。

**起始版本：** 3.2

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetComponentVersion](#getcomponentversion) ([out] struct [CompVerInfo](_comp_ver_info_v10.md) verInfo) | 获取Codec组件版本号。 | 
| [SendCommand](#sendcommand) ([in] enum OMX_COMMANDTYPE cmd, [in] unsigned int param, [in] byte[] cmdData) | 发送命令给组件。 | 
| [GetParameter](#getparameter) ([in] unsigned int index, [in] byte[] inParamStruct, [out] byte[] outParamStruct) | 获取组件参数设置。 | 
| [SetParameter](#setparameter) ([in] unsigned int index, [in] byte[] paramStruct) | 设置组件需要的参数。 | 
| [GetConfig](#getconfig) ([in] unsigned int index, [in] byte[] inCfgStruct, [out] byte[] outCfgStruct) | 获取组件的配置。 | 
| [SetConfig](#setconfig) ([in] unsigned int index, [in] byte[] cfgStruct) | 设置组件的配置。 | 
| [GetExtensionIndex](#getextensionindex) ([in] String paramName, [out] unsigned int indexType) | 根据字符串获取组件的扩展索引。 | 
| [GetState](#getstate) ([out] enum OMX_STATETYPE state) | 获取组件的当前状态。 | 
| [ComponentTunnelRequest](#componenttunnelrequest) ([in] unsigned int port, [in] int tunneledComp, [in] unsigned int tunneledPort, [in] struct [OMX_TUNNELSETUPTYPE](_o_m_x___t_u_n_n_e_l_s_e_t_u_p_t_y_p_e_v10.md) inTunnelSetup, [out] struct [OMX_TUNNELSETUPTYPE](_o_m_x___t_u_n_n_e_l_s_e_t_u_p_t_y_p_e_v10.md) outTunnelSetup) | 设置组件采用Tunnel方式通信。 | 
| [UseBuffer](#usebuffer) ([in] unsigned int portIndex, [in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) inBuffer, [out] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) outBuffer) | 指定组件端口的buffer。 | 
| [AllocateBuffer](#allocatebuffer) ([in] unsigned int portIndex, [in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) inBuffer, [out] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) outBuffer) | 向组件申请端口buffer。 | 
| [FreeBuffer](#freebuffer) ([in] unsigned int portIndex, [in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) buffer) | 释放buffer。 | 
| [EmptyThisBuffer](#emptythisbuffer) ([in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) buffer) | 编解码输入待处理buffer。 | 
| [FillThisBuffer](#fillthisbuffer) ([in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) buffer) | 编解码输出填充buffer。 | 
| [SetCallbacks](#setcallbacks) ([in] [ICodecCallback](interface_i_codec_callback_v10.md) callbacks, [in] long appData) | 设置Codec组件的回调函数。 | 
| [ComponentDeInit](#componentdeinit) () | 组件去初始化。 | 
| [UseEglImage](#useeglimage) ([in] unsigned int portIndex, [in] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) inBuffer, [out] struct [OmxCodecBuffer](_omx_codec_buffer_v10.md) outBuffer, [in] byte[] eglImage) | 使用已在EGL中申请的空间。 | 
| [ComponentRoleEnum](#componentroleenum) ([out] unsigned char[] role, [in] unsigned int index) | 获取组件角色。 | 


## 成员函数说明


### AllocateBuffer()

```
ICodecComponent::AllocateBuffer ([in] unsigned int portIndex, [in] struct OmxCodecBuffer inBuffer, [out] struct OmxCodecBuffer outBuffer )
```

**描述**

向组件申请端口buffer。

向组件申请分配新的buffer，此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且用户已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。 更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portIndex | 指定的组件端口。 | 
| inBuffer | 指向要申请的buffer结构的体指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 
| outBuffer | 指向要申请的buffer结构的体指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示申请buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，申请buffer失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### ComponentDeInit()

```
ICodecComponent::ComponentDeInit ()
```

**描述**

组件去初始化。

调用此接口使组件去初始化，当组件处于OMX_StateLoaded状态时，将直接关闭组件，更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**返回：**

HDF_SUCCESS 表示去初始化成功。

HDF_ERR_INVALID_PARAM 表示参数无效，去初始化失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### ComponentRoleEnum()

```
ICodecComponent::ComponentRoleEnum ([out] unsigned char[] role, [in] unsigned int index )
```

**描述**

获取组件角色。

根据组件角色索引获取对应组件角色。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| role | 角色名称。 | 
| index | 角色的索引，一个组件可能支持多种角色。 | 

**返回：**

HDF_SUCCESS 表示获取角色成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取角色失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### ComponentTunnelRequest()

```
ICodecComponent::ComponentTunnelRequest ([in] unsigned int port, [in] int tunneledComp, [in] unsigned int tunneledPort, [in] struct OMX_TUNNELSETUPTYPE inTunnelSetup, [out] struct OMX_TUNNELSETUPTYPE outTunnelSetup )
```

**描述**

设置组件采用Tunnel方式通信。

当组件处于OMX_StateLoaded状态时（表示组件已加载），用户通过调用此接口确定组件是否可以进行Tunnel传输，如果可以则设置组件的Tunnel传输。 更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| port | 组件设置的端口。 | 
| tunneledComp | 组件的tunnel组件句柄。 | 
| tunneledPort | 组件用来Tunnel通信的端口。 | 
| inTunnelSetup | 指向Tunnel设置的结构体[OMX_TUNNELSETUPTYPE](_o_m_x___t_u_n_n_e_l_s_e_t_u_p_t_y_p_e_v10.md)指针。 | 
| outTunnelSetup | 指向Tunnel设置的结构体[OMX_TUNNELSETUPTYPE](_o_m_x___t_u_n_n_e_l_s_e_t_u_p_t_y_p_e_v10.md)指针。 | 

**返回：**

HDF_SUCCESS 表示设置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### EmptyThisBuffer()

```
ICodecComponent::EmptyThisBuffer ([in] struct OmxCodecBuffer buffer)
```

**描述**

编解码输入待处理buffer。

此接口在组件处于OMX_StateExecuting或者OMX_StatePause状态时调用，更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向要输入的buffer结构体的指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示输入buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，输入buffer失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### FillThisBuffer()

```
ICodecComponent::FillThisBuffer ([in] struct OmxCodecBuffer buffer)
```

**描述**

编解码输出填充buffer。

此接口在组件处于OMX_StateExecuting或者OMX_StatePause状态时调用，更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向要填充的buffer结构体的指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示填充buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，填充buffer失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### FreeBuffer()

```
ICodecComponent::FreeBuffer ([in] unsigned int portIndex, [in] struct OmxCodecBuffer buffer )
```

**描述**

释放buffer。

此接口在以下情况下使用：

- 当组件处于OMX_StateIdle状态，并且已经向组件发送OMX_StateLoaded状态转换请求。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle时调用。 更多组件状态的说明请详见**OMX_STATETYPE**。

- 此接口调用可随时进行，但是如果未在上述情况下执行，可能会导致组件上报OMX_ErrorPortUnpopulated事件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portIndex | 指定的组件端口。 | 
| buffer | 指向要释放的buffer结构体的结构体的指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示释放buffer成功。

HDF_ERR_INVALID_PARAM 表示参数无效，释放buffer失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### GetComponentVersion()

```
ICodecComponent::GetComponentVersion ([out] struct CompVerInfo verInfo)
```

**描述**

获取Codec组件版本号。

通过查询组件，返回组件版本信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| verInfo | 指向组件版本信息的对象，详见[CompVerInfo](_comp_ver_info_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示获取版本号成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取版本号失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### GetConfig()

```
ICodecComponent::GetConfig ([in] unsigned int index, [in] byte[] inCfgStruct, [out] byte[] outCfgStruct )
```

**描述**

获取组件的配置。

加载组件后可以随时调用此接口获取组件的配置。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| index | 待填充结构的索引，详见OpenMAX IL定义的OMX_INDEXTYPE。 | 
| inCfgStruct | 指向由组件填充的应用程序分配的结构体指针。 | 
| outCfgStruct | 指向由组件填充的应用程序分配的结构体指针。 | 

**返回：**

HDF_SUCCESS 表示获取配置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取配置失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### GetExtensionIndex()

```
ICodecComponent::GetExtensionIndex ([in] String paramName, [out] unsigned int indexType )
```

**描述**

根据字符串获取组件的扩展索引。

将扩展字符串转换为Openmax IL结构索引，此索引可用于获取（[GetParameter](#getparameter)）或者设置（[SetParameter](#setparameter)）组件参数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramName | 组件用来转换为配置索引的字符串。 | 
| indexType | 由paramName转换的配置索引，详见OpenMAX IL定义的OMX_INDEXTYPE。 | 

**返回：**

HDF_SUCCESS 表示获取扩展索引成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取扩展索引失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### GetParameter()

```
ICodecComponent::GetParameter ([in] unsigned int index, [in] byte[] inParamStruct, [out] byte[] outParamStruct )
```

**描述**

获取组件参数设置。

当组件处于除了OMX_StateInvalid（组件状态异常）之外的其他状态，用户可通过此接口获取组件参数，组件状态详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| index | 待填充结构的索引，详见OpenMAX IL定义的OMX_INDEXTYPE。 | 
| inParamStruct | 指向由组件填充的应用程序分配的结构体指针。 | 
| outParamStruct | 指向由组件填充的应用程序分配的结构体指针。 | 

**返回：**

HDF_SUCCESS 表示获取参数成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取参数失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### GetState()

```
ICodecComponent::GetState ([out] enum OMX_STATETYPE state)
```

**描述**

获取组件的当前状态。

用户可调用此接口获取组件的当前状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| state | 指向获取到的状态指针，组件状态详见**OMX_STATETYPE**。 | 

**返回：**

HDF_SUCCESS 表示获取状态成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取状态失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### SendCommand()

```
ICodecComponent::SendCommand ([in] enum OMX_COMMANDTYPE cmd, [in] unsigned int param, [in] byte[] cmdData )
```

**描述**

发送命令给组件。

发送命令给组件，当命令为设置状态时，会有事件回调通知结果给上层，其他命令则没有事件上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cmd | 组件要执行的命令，详见**OMX_COMMANDTYPE**。 | 
| param | 组件要执行的命令携带的参数。<br/>- 当cmd为OMX_CommandStateSet时，param的值详见**OMX_STATETYPE**。<br/>- 当cmd为OMX_CommandFlush、OMX_CommandPortDisable、OMX_CommandPortEnable、OMX_CommandMarkBuffer时，param为目标端口。 | 
| cmdData | 当cmd为OMX_CommandMarkBuffer时，指向OMX_MARKTYPE结构体指针。 | 

**返回：**

HDF_SUCCESS 表示发送命令成功。

HDF_ERR_INVALID_PARAM 表示参数无效，发送命令失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### SetCallbacks()

```
ICodecComponent::SetCallbacks ([in] ICodecCallback callbacks, [in] long appData )
```

**描述**

设置Codec组件的回调函数。

当组件处于OMX_StateLoaded状态时，使用此回调函数向上通知事件以及上报可用的输入输出信息。更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbacks | 指向回调函数[ICodecCallback](interface_i_codec_callback_v10.md)对象的指针。 | 
| appData | 指向应用程序定义的值的指针，该值将在回调期间返回。 | 

**返回：**

HDF_SUCCESS 表示设置回调成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置回调失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### SetConfig()

```
ICodecComponent::SetConfig ([in] unsigned int index, [in] byte[] cfgStruct )
```

**描述**

设置组件的配置。

加载组件后可以随时调用此接口设置组件的配置。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| index | 要设置的结构索引，详见OpenMAX IL定义的OMX_INDEXTYPE。 | 
| cfgStruct | 指向组件用于初始化的应用程序分配结构的指针。 | 

**返回：**

HDF_SUCCESS 表示设置配置成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### SetParameter()

```
ICodecComponent::SetParameter ([in] unsigned int index, [in] byte[] paramStruct )
```

**描述**

设置组件需要的参数。

当出现如下情况时，用户可以通过此接口设置组件参数。

- 当组件处于OMX_StateLoaded（表示组件已加载）。

- 当组件处于OMX_StateWaitForResources（表示组件等待所需要的资源）。

- 当状态或者端口是去使能状态，用户可通过此接口设置组件参数。

更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| index | 要设置的结构索引，详见OpenMAX IL定义的OMX_INDEXTYPE。 | 
| paramStruct | 指向组件用于初始化的应用程序分配结构的指针。 | 

**返回：**

HDF_SUCCESS 表示设置参数成功。

HDF_ERR_INVALID_PARAM 表示参数无效，设置参数失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### UseBuffer()

```
ICodecComponent::UseBuffer ([in] unsigned int portIndex, [in] struct OmxCodecBuffer inBuffer, [out] struct OmxCodecBuffer outBuffer )
```

**描述**

指定组件端口的buffer。

此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态（表示组件已加载），并且用户已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portIndex | 指定的组件端口。 | 
| inBuffer | 指向要使用的buffer结构体的指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 
| outBuffer | 指向要使用的buffer结构体的指针，结构体介绍详见[OmxCodecBuffer](_omx_codec_buffer_v10.md)。 | 

**返回：**

HDF_SUCCESS 表示指定成功。

HDF_ERR_INVALID_PARAM 表示参数无效，指定失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。


### UseEglImage()

```
ICodecComponent::UseEglImage ([in] unsigned int portIndex, [in] struct OmxCodecBuffer inBuffer, [out] struct OmxCodecBuffer outBuffer, [in] byte[] eglImage )
```

**描述**

使用已在EGL中申请的空间。

此接口在以下情况下使用：

- 当组件处于OMX_StateLoaded状态，并且已经向组件发送OMX_StateIdle状态转换请求。

- 当组件处于OMX_StateWaitForResources状态，所需的资源可用，并且组件已准备好进入OMX_StateIdle状态。

- 在去使能端口上，组件处于OMX_StateExecuting、OMX_StatePause或OMX_StateIdle状态。

更多组件状态的说明请详见**OMX_STATETYPE**。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| portIndex | 指定的组件端口。 | 
| inBuffer | 指向[OmxCodecBuffer](_omx_codec_buffer_v10.md)结构体的指针。 | 
| outBuffer | 指向[OmxCodecBuffer](_omx_codec_buffer_v10.md)结构体的指针。 | 
| eglImage | EGL申请的图像指针。 | 

**返回：**

HDF_SUCCESS 表示使用成功。

HDF_ERR_INVALID_PARAM 表示参数无效，使用失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的OMX_ERRORTYPE。
