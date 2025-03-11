# IVideoProcessService


## 概述

声明视频处理进程服务。

创建视频处理会话，注册后台捕获后回调。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [CreateVideoProcessSession](#createvideoprocesssession) ([in] int userId, [in] [IVideoProcessCallback](interface_i_video_process_callback_v13.md) videoProcessCallback, [out] [IVideoProcessSession](interface_i_video_process_session_v13.md) videoProcessSession) | 创建视频处理会话。 | 


## 成员函数说明


### CreateVideoProcessSession()

```
IVideoProcessService::CreateVideoProcessSession ([in] int userId, [in] IVideoProcessCallback videoProcessCallback, [out] IVideoProcessSession videoProcessSession)
```

**描述**

创建视频处理会话。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| videoProcessCallback | 视频进程回调。有关详细信息，请参阅 [IVideoProcessCallback](interface_i_video_process_callback_v13.md)。 | 
| videoProcessSession | 视频处理会话。有关详细信息，请参阅[IVideoProcessSession](interface_i_video_process_session_v13.md)。 | 

**返回：**

NO_ERROR 表示执行成功。

其他值表示执行失败，具体错误码查看**[CamRetCode](_camera_v10.md#camretcode)**。
