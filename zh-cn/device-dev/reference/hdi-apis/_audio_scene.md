# AudioScene


## **概述**

AudioScene音频场景接口。

提供音频播放（Render）或录音（Capture）需要的公共场景驱动能力，包括选择音频场景等。

**Since：**

1.0

**Version：**

1.0

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([CheckSceneCapability](#checkscenecapability))(AudioHandle&nbsp;handle,&nbsp;const&nbsp;struct&nbsp;AudioSceneDescriptor&nbsp;\*scene,&nbsp;bool&nbsp;\*supported) | 是否支持某个音频场景的配置 | 
| ([SelectScene](#selectscene))(AudioHandle&nbsp;handle,&nbsp;const&nbsp;struct&nbsp;AudioSceneDescriptor&nbsp;\*scene) | 选择音频场景 | 


## **类成员变量说明**


### CheckSceneCapability

  
```
int32_t(* AudioScene::CheckSceneCapability) (AudioHandle handle, const struct AudioSceneDescriptor *scene, bool *supported)
```

**描述：**

是否支持某个音频场景的配置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| scene | 输入参数，待获取的音频场景描述符。 | 
| supported | 输出参数，是否支持的状态保存到supported中，true表示支持，false表示不支持。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SelectScene](#selectscene)


### SelectScene

  
```
int32_t(* AudioScene::SelectScene) (AudioHandle handle, const struct AudioSceneDescriptor *scene)
```

**描述：**

选择音频场景。

- 选择一个非常具体的音频场景（应用场景和输出设备的组合），例如同样是使用手机中的喇叭作为输出设备：
  - 在媒体播放场景scene为media_speaker
  - 在语音通话免提场景scene为voice_speaker

- 只是选择一个音频场景，例如使用场景为媒体播放（media）、电影播放（movie）、游戏播放（game）。

- 只是选择一个音频输出设备，例如输出设备为听筒（receiver）、喇叭（speaker）、有线耳机（headset）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| scene | 输入参数，待设置的音频场景描述符。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CheckSceneCapability](#checkscenecapability)
