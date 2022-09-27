# AudioManager


## **概述**

**所属模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[GetAllAdapters](#getalladapters)&nbsp;)(struct&nbsp;AudioAdapterManager&nbsp;\*manager,&nbsp;struct&nbsp;[AudioAdapterDescriptor](_audio_adapter_descriptor.md)&nbsp;\*\*descs,&nbsp;int&nbsp;\*size) | 获取音频驱动中支持的所有适配器的列表&nbsp;[更多...](#getalladapters) | 
| (&nbsp;[LoadAdapter](#loadadapter)&nbsp;)(struct&nbsp;AudioAdapterManager&nbsp;\*manager,&nbsp;const&nbsp;struct&nbsp;[AudioAdapterDescriptor](_audio_adapter_descriptor.md)&nbsp;\*desc,&nbsp;struct&nbsp;[AudioAdapter](_audio_adapter.md)&nbsp;\*\*adapter) | 加载一个音频适配器（声卡）的驱动&nbsp;[更多...](#loadadapter) | 
| (&nbsp;[UnloadAdapter](#unloadadapter)&nbsp;)(struct&nbsp;AudioAdapterManager&nbsp;\*manager,&nbsp;struct&nbsp;[AudioAdapter](_audio_adapter.md)&nbsp;\*adapter) | 卸载音频适配器（声卡）的驱动&nbsp;[更多...](#unloadadapter) | 
| (&nbsp;[ReleaseAudioManagerObject](#releaseaudiomanagerobject)&nbsp;)(struct&nbsp;AudioManager&nbsp;\*object) | 释放音频管理接口对象&nbsp;[更多...](#releaseaudiomanagerobject) | 


## **详细描述**

AudioManager音频适配器管理接口

按照音频服务下发的音频适配器（声卡）描述符加载一个具体的音频适配器驱动程序

参见：

[AudioAdapter](_audio_adapter.md)

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### GetAllAdapters

  
```
int(* AudioManager::GetAllAdapters) (struct AudioAdapterManager *manager, struct AudioAdapterDescriptor **descs, int *size)
```

**描述：**

获取音频驱动中支持的所有适配器的列表

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| manager | 待操作的音频管理接口对象 | 
| descs | 获取到的音频适配器列表保存到descs中 | 
| size | 获取到的音频适配器列表的长度保存到size中 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[LoadAdapter](#loadadapter)


### LoadAdapter

  
```
int(* AudioManager::LoadAdapter) (struct AudioAdapterManager *manager, const struct AudioAdapterDescriptor *desc, struct AudioAdapter **adapter)
```

**描述：**

加载一个音频适配器（声卡）的驱动

加载一个具体的音频驱动，例如USB驱动，在具体实现中可能加载的是一个动态链接库（\*.so）

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| manager | 待操作的音频管理接口对象 | 
| desc | 待加载的音频适配器描述符 | 
| adapter | 获取的音频适配器接口的对象实例保存到adapter中 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetAllAdapters](#getalladapters)

[UnloadAdapter](#unloadadapter)


### ReleaseAudioManagerObject

  
```
bool(* AudioManager::ReleaseAudioManagerObject) (struct AudioManager *object)
```

**描述：**

释放音频管理接口对象

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| object | 待操作的音频管理接口对象 | 

**返回：**

成功返回true，失败返回false


### UnloadAdapter

  
```
void(* AudioManager::UnloadAdapter) (struct AudioAdapterManager *manager, struct AudioAdapter *adapter)
```

**描述：**

卸载音频适配器（声卡）的驱动

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| manager | 待操作的音频管理接口对象 | 
| adapter | 待卸载的音频适配器接口的对象 | 

**参见：**

[LoadAdapter](#loadadapter)
