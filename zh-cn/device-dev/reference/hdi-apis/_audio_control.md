# AudioControl


## **概述**

AudioControl音频控制接口。

提供音频播放（Render）或录音（Capture）需要的公共控制驱动能力，包括Start、Stop、Pause、Resume、Flush等。

**Since:**

1.0

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([Start](#start))(AudioHandle&nbsp;handle) | 启动一个音频播放（Render）或录音（Capture）处理。 | 
| ([Stop](#stop))(AudioHandle&nbsp;handle) | 停止一个音频播放（Render）或录音（Capture）处理。 | 
| ([Pause](#pause))(AudioHandle&nbsp;handle) | 暂停一个音频播放（Render）或录音（Capture）处理。 | 
| ([Resume](#resume))(AudioHandle&nbsp;handle) | 恢复一个音频播放（Render）或录音（Capture）处理。 | 
| ([Flush](#flush))(AudioHandle&nbsp;handle) | 刷新音频缓冲区buffer中的数据。 | 
| ([TurnStandbyMode](#turnstandbymode))(AudioHandle&nbsp;handle) | 设置或去设置设备的待机模式。 | 
| ([AudioDevDump](#audiodevdump))(AudioHandle&nbsp;handle,&nbsp;int32_t&nbsp;range,&nbsp;int32_t&nbsp;fd) | Dump音频设备信息。 | 


## **类成员变量说明**


### AudioDevDump

  
```
int32_t(* AudioControl::AudioDevDump) (AudioHandle handle, int32_t range, int32_t fd)
```

**描述：**

Dump音频设备信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| range | Dump信息范围，分为简要信息、全量信息 | 
| fd | 指定Dump目标文件 | 

**返回:**

成功返回值0，失败返回负值。


### Flush

  
```
int32_t(* AudioControl::Flush) (AudioHandle handle)
```

**描述：**

刷新音频缓冲区buffer中的数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 

**返回:**

成功返回值0，失败返回负值。


### Pause

  
```
int32_t(* AudioControl::Pause) (AudioHandle handle)
```

**描述：**

暂停一个音频播放（Render）或录音（Capture）处理。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Resume](#resume)


### Resume

  
```
int32_t(* AudioControl::Resume) (AudioHandle handle)
```

**描述：**

恢复一个音频播放（Render）或录音（Capture）处理。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Pause](#pause)


### Start

  
```
int32_t(* AudioControl::Start) (AudioHandle handle)
```

**描述：**

启动一个音频播放（Render）或录音（Capture）处理。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Stop](#stop)


### Stop

  
```
int32_t(* AudioControl::Stop) (AudioHandle handle)
```

**描述：**

停止一个音频播放（Render）或录音（Capture）处理。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Start](#start)


### TurnStandbyMode

  
```
int32_t(* AudioControl::TurnStandbyMode) (AudioHandle handle)
```

**描述：**

设置或去设置设备的待机模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 

**返回:**

设置设备待机模式成功返回值0，再次执行后去设置待机模式成功返回正值，失败返回负值。
