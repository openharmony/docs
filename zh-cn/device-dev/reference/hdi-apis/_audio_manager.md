# AudioManager


## **概述**

AudioManager音频适配器管理接口。

按照音频服务下发的音频适配器（声卡）描述符加载一个具体的音频适配器驱动程序。

**Since:**

1.0

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)

**参见：**

[AudioAdapter](_audio_adapter.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([GetAllAdapters](#getalladapters))(struct&nbsp;AudioAdapterManager&nbsp;\*manager,&nbsp;struct&nbsp;AudioAdapterDescriptor&nbsp;\*\*descs,&nbsp;int&nbsp;\*size) | 获取音频驱动中支持的所有适配器的列表 | 
| ([LoadAdapter](#loadadapter))(struct&nbsp;AudioAdapterManager&nbsp;\*manager,&nbsp;const&nbsp;struct&nbsp;AudioAdapterDescriptor&nbsp;\*desc,&nbsp;struct&nbsp;AudioAdapter&nbsp;\*\*adapter) | 加载一个音频适配器（声卡）的驱动 | 
| ([UnloadAdapter](#unloadadapter))(struct&nbsp;AudioAdapterManager&nbsp;\*manager,&nbsp;struct&nbsp;AudioAdapter&nbsp;\*adapter) | 卸载音频适配器（声卡）的驱动 | 
| ([ReleaseAudioManagerObject](#releaseaudiomanagerobject))(struct&nbsp;AudioManager&nbsp;\*object) | 释放音频管理接口对象 | 


## **类成员变量说明**


### GetAllAdapters

  
```
int(* AudioManager::GetAllAdapters) (struct AudioAdapterManager *manager, struct AudioAdapterDescriptor **descs, int *size)
```

**描述：**

获取音频驱动中支持的所有适配器的列表。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| manager | 输入参数，待操作的音频管理接口对象。 | 
| descs | 输出参数，获取到的音频适配器列表保存到descs中。 | 
| size | 输出参数，获取到的音频适配器列表的长度保存到size中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[LoadAdapter](#loadadapter)


### LoadAdapter

  
```
int(* AudioManager::LoadAdapter) (struct AudioAdapterManager *manager, const struct AudioAdapterDescriptor *desc, struct AudioAdapter **adapter)
```

**描述：**

加载一个音频适配器（声卡）的驱动。

加载一个具体的音频驱动，例如USB驱动，在具体实现中可能加载的是一个动态链接库（\*.so）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| manager | 输入参数，待操作的音频管理接口对象。 | 
| desc | 输入参数，待加载的音频适配器描述符。 | 
| adapter | 输出参数，获取的音频适配器接口的对象实例保存到adapter中。| 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetAllAdapters](#getalladapters)

[UnloadAdapter](#unloadadapter)


### ReleaseAudioManagerObject

  
```
bool(* AudioManager::ReleaseAudioManagerObject) (struct AudioManager *object)
```

**描述：**

释放音频管理接口对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| object | 输入参数，待操作的音频管理接口对象。 | 

**返回:**

成功返回true，失败返回false。


### UnloadAdapter

  
```
void(* AudioManager::UnloadAdapter) (struct AudioAdapterManager *manager, struct AudioAdapter *adapter)
```

**描述：**

卸载音频适配器（声卡）的驱动。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| manager | 输入参数，待操作的音频管理接口对象。 | 
| adapter | 输入参数，待卸载的音频适配器接口的对象。 | 

**参见:**

[LoadAdapter](#loadadapter)
