# AudioAdapter


## **概述**

AudioAdapter音频适配器接口。

提供音频适配器（声卡）对外支持的驱动能力，包括初始化端口、创建Render、创建Capture、获取端口能力集等。

**Since:**

1.0

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)

**参见：**

[AudioRender](_audio_render.md)

[AudioCapture](_audio_capture.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([InitAllPorts](#initallports))(struct&nbsp;AudioAdapter&nbsp;\*adapter) | 初始化一个音频适配器所有的端口驱动 | 
| ([CreateRender](#createrender)&nbsp;)(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;const&nbsp;struct&nbsp;AudioDeviceDescriptor&nbsp;\*desc,&nbsp;const&nbsp;struct&nbsp;AudioSampleAttributes&nbsp;\*attrs,&nbsp;struct&nbsp;AudioRender&nbsp;\*\*render) | 创建一个音频播放（Render）接口的对象 | 
| ([DestroyRender](#destroyrender)&nbsp;)(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;struct&nbsp;AudioRender&nbsp;\*render) | 销毁一个音频播放（Render）接口的对象 | 
| ([CreateCapture](#createcapture))(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;const&nbsp;struct&nbsp;AudioDeviceDescriptor&nbsp;\*desc,&nbsp;const&nbsp;struct&nbsp;AudioSampleAttributes&nbsp;\*attrs,&nbsp;struct&nbsp;AudioCapture&nbsp;\*\*capture) | 创建一个音频录音（Capture）接口的对象 | 
| ([DestroyCapture](#destroycapture))(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;struct&nbsp;AudioCapture&nbsp;\*capture) | 销毁一个音频录音（Capture）接口的对象 | 
| ([GetPortCapability](#getportcapability)&nbsp;)(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;struct&nbsp;AudioPort&nbsp;\*port,&nbsp;struct&nbsp;AudioPortCapability&nbsp;\*capability) | 获取一个音频适配器的端口驱动的能力集 | 
| ([SetPassthroughMode](#setpassthroughmode)&nbsp;)(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;struct&nbsp;AudioPort&nbsp;\*port,&nbsp;enum&nbsp;AudioPortPassthroughMode&nbsp;mode) | 设置音频端口驱动的数据透传模式 | 
| ([GetPassthroughMode](#getpassthroughmode))(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;struct&nbsp;AudioPort&nbsp;\*port,&nbsp;enum&nbsp;AudioPortPassthroughMode&nbsp;\*mode) | 获取音频端口驱动的数据透传模式 | 
| ([UpdateAudioRoute](#updateaudioroute))(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;const&nbsp;struct&nbsp;AudioRoute&nbsp;\*route,&nbsp;int32_t&nbsp;\*routeHandle) | 更新一个或多个发送端和接受端之间的路由 | 
| ([ReleaseAudioRoute](#releaseaudioroute))(struct&nbsp;AudioAdapter&nbsp;\*adapter,&nbsp;int32_t&nbsp;routeHandle) | 释放一个音频路由 | 


## **类成员变量说明**


### CreateCapture

  
```
int32_t(* AudioAdapter::CreateCapture) (struct AudioAdapter *adapter, const struct AudioDeviceDescriptor *desc, const struct AudioSampleAttributes *attrs, struct AudioCapture **capture)
```

**描述：**

创建一个音频录音（Capture）接口的对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器的指针 | 
| desc | 指向要启动的音频适配器的描述符的指针 | 
| attrs | 指向要打开的音频采样属性的指针 | 
| capture | 指向AudioCapture对象的二级指针 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetPortCapability](#getportcapability)

[DestroyCapture](#destroycapture)


### CreateRender

  
```
int32_t(* AudioAdapter::CreateRender) (struct AudioAdapter *adapter, const struct AudioDeviceDescriptor *desc, const struct AudioSampleAttributes *attrs, struct AudioRender **render)
```

**描述：**

创建一个音频播放（Render）接口的对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| desc | 待打开的音频设备描述符 | 
| attrs | 待打开的音频采样属性 | 
| render | 获取的音频播放接口的对象实例保存到render中 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetPortCapability](#getportcapability)

[DestroyRender](#destroyrender)


### DestroyCapture

  
```
int32_t(* AudioAdapter::DestroyCapture) (struct AudioAdapter *adapter, struct AudioCapture *capture)
```

**描述：**

销毁一个音频录音（Capture）接口的对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| capture | 待操作的音频录音接口对象 | 

**注意:**

在音频录音过程中，不能销毁该接口对象。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CreateCapture](#createcapture)


### DestroyRender

  
```
int32_t(* AudioAdapter::DestroyRender) (struct AudioAdapter *adapter, struct AudioRender *render)
```

**描述：**

销毁一个音频播放（Render）接口的对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| render | 待操作的音频播放接口对象 | 

**注意:**

在音频播放过程中，不能销毁该接口对象

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CreateRender](#createrender)


### GetPassthroughMode

  
```
int(* AudioAdapter::GetPassthroughMode) (struct AudioAdapter *adapter, struct AudioPort *port, enum AudioPortPassthroughMode *mode)
```

**描述：**

获取音频端口驱动的数据透传模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| port | 待获取的端口 | 
| mode | 获取的传输模式保存到mode中 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetPassthroughMode](#setpassthroughmode)


### GetPortCapability

  
```
int(* AudioAdapter::GetPortCapability) (struct AudioAdapter *adapter, struct AudioPort *port, struct AudioPortCapability *capability)
```

**描述：**

获取一个音频适配器的端口驱动的能力集。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| port | 待获取的端口 | 
| capability | 获取的端口能力保存到capability中 | 

**返回:**

成功返回值0，失败返回负值。


### InitAllPorts

  
```
int(* AudioAdapter::InitAllPorts) (struct AudioAdapter *adapter)
```

**描述：**

初始化一个音频适配器所有的端口驱动。

在音频服务中，调用其他驱动接口前需要首先调用该接口检查端口是否已经初始化完成：

- 如果端口驱动初始化完成，则函数返回值0， 否则返回负值。

- 如果端口没有初始化完成，则需要等待一段时间（例如100ms）后重新进行检查，直到端口初始化完成后再继续操作。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 

**返回:**

成功返回值0，失败返回负值。


### ReleaseAudioRoute

  
```
int32_t(* AudioAdapter::ReleaseAudioRoute) (struct AudioAdapter *adapter, int32_t routeHandle)
```

**描述：**

释放一个音频路由。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| routeHandle | 待释放的路由句柄 | 

**返回:**

成功返回值0，失败返回负值。


### SetPassthroughMode

  
```
int(* AudioAdapter::SetPassthroughMode) (struct AudioAdapter *adapter, struct AudioPort *port, enum AudioPortPassthroughMode mode)
```

**描述：**

设置音频端口驱动的数据透传模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| port | 待设置的端口 | 
| mode | 待设置的传输模式 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetPassthroughMode](#getpassthroughmode)


### UpdateAudioRoute

  
```
int32_t(* AudioAdapter::UpdateAudioRoute) (struct AudioAdapter *adapter, const struct AudioRoute *route, int32_t *routeHandle)
```

**描述：**

更新一个或多个发送端和接受端之间的路由。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| adapter | 待操作的音频适配器对象 | 
| route | 路由信息 | 
| routeHandle | 生成的路由句柄 | 

**返回:**

成功返回值0，失败返回负值。
