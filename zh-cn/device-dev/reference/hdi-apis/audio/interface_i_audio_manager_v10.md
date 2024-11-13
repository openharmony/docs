# IAudioManager


## 概述

AudioManager音频适配器管理接口。

按照音频服务下发的音频适配器（声卡）描述符加载一个具体的音频适配器驱动程序。

参见

[IAudioAdapter](interface_i_audio_adapter_v10.md)

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetAllAdapters](#getalladapters) ([out] struct [AudioAdapterDescriptor](_audio_adapter_descriptor_v10.md)[] descs) | 获取音频驱动中支持的所有适配器的列表。 | 
| [LoadAdapter](#loadadapter) ([in] struct [AudioAdapterDescriptor](_audio_adapter_descriptor_v10.md) desc, [out] [IAudioAdapter](interface_i_audio_adapter_v10.md) adapter) | 加载一个音频适配器（声卡）的驱动。 | 
| [UnloadAdapter](#unloadadapter) ([in] String adapterName) | 卸载音频适配器（声卡）的驱动。 | 
| [ReleaseAudioManagerObject](#releaseaudiomanagerobject) () | 释放音频管理接口对象。 | 


## 成员函数说明


### GetAllAdapters()

```
IAudioManager::GetAllAdapters ([out] struct AudioAdapterDescriptor[] descs)
```

**描述**

获取音频驱动中支持的所有适配器的列表。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descs | 获取到的音频适配器列表保存到descs中，详请参考[AudioAdapterDescriptor](_audio_adapter_descriptor_v10.md)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[LoadAdapter](#loadadapter)


### LoadAdapter()

```
IAudioManager::LoadAdapter ([in] struct AudioAdapterDescriptor desc, [out] IAudioAdapter adapter )
```

**描述**

加载一个音频适配器（声卡）的驱动。

加载一个具体的音频驱动，例如usb驱动，在具体实现中可能加载的是一个动态链接库（\*.so）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| desc | 待加载的音频适配器描述符，详请参考[AudioAdapterDescriptor](_audio_adapter_descriptor_v10.md)。 | 
| adapter | 获取的音频适配器接口的对象实例保存到adapter中，详请参考[IAudioAdapter](interface_i_audio_adapter_v10.md)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetAllAdapters](#getalladapters)

[UnloadAdapter](#unloadadapter)


### ReleaseAudioManagerObject()

```
IAudioManager::ReleaseAudioManagerObject ()
```

**描述**

释放音频管理接口对象。

**起始版本：** 4.0

**返回：**

功返回值0，失败返回负值。


### UnloadAdapter()

```
IAudioManager::UnloadAdapter ([in] String adapterName)
```

**描述**

卸载音频适配器（声卡）的驱动。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapterName | 待卸载的音频适配器接口的对象名称。 | 

**参见：**

[LoadAdapter](#loadadapter)
