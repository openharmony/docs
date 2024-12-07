# IntelligentVoiceEngine


## 概述

IntelligentVoiceEngine模块向上层服务提供了统一接口。

上层服务开发人员可根据IntelligentVoiceEngine模块提供的向上统一接口获取如下能力：创建销毁唤醒算法引擎、启动停止唤醒算法引擎、写语音数据、读文件、回调函数注册等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IIntellVoiceEngineAdapter.idl](_i_intell_voice_engine_adapter_8idl.md) | IntelligentVoiceEngine模块智能语音引擎适配器接口，包括设置回调、加载唤醒算法引擎、卸载唤醒算法引擎、设置唤醒算法参数、获取唤醒算法参数、启动唤醒算法引擎、停止唤醒算法引擎、读写数据等。 | 
| [IIntellVoiceEngineCallback.idl](_i_intell_voice_engine_callback_8idl.md) | IntelligentVoiceEngine模块智能语音引擎回调接口，用于通知上层服务事件信息。 | 
| [IIntellVoiceEngineManager.idl](_i_intell_voice_engine_manager_8idl.md) | IntelligentVoiceEngine模块引擎管理接口，包括获取引擎适配器描述符、创建引擎适配器、释放引擎适配器等。 | 
| [IntellVoiceEngineTypes.idl](_intell_voice_engine_types_8idl.md) | IntelligentVoiceEngine模块接口定义中使用的数据类型，包括引擎适配器类型、数据类型、回调消息类型、回调消息错误码、引擎适配器描述、回调事件信息等。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IIntellVoiceEngineAdapter](interface_i_intell_voice_engine_adapter.md) | IntelligentVoiceEngine模块向上层服务提供了智能语音引擎适配器接口。 | 
| interface&nbsp;&nbsp;[IIntellVoiceEngineCallback](interface_i_intell_voice_engine_callback.md) | IntelligentVoiceEngine模块向上层服务提供了智能语音引擎回调接口。 | 
| interface&nbsp;&nbsp;[IIntellVoiceEngineManager](interface_i_intell_voice_engine_manager.md) | IntelligentVoiceEngine模块向上层服务提供了智能语音引擎管理接口。 | 
| struct&nbsp;&nbsp;[IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md) | 智能语音引擎适配器描述符。 | 
| struct&nbsp;&nbsp;[IntellVoiceEngineAdapterInfo](_intell_voice_engine_adapter_info.md) | 智能语音引擎适配器信息。 | 
| struct&nbsp;&nbsp;[StartInfo](_start_info.md) | 智能语音引擎启动信息。 | 
| struct&nbsp;&nbsp;[IntellVoiceEngineCallBackEvent](_intell_voice_engine_call_back_event.md) | 智能语音引擎回调事件信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [IntellVoiceEngineAdapterType](#intellvoiceengineadaptertype) { ENROLL_ADAPTER_TYPE = 0 , WAKEUP_ADAPTER_TYPE = 1 , UPDATE_ADAPTER_TYPE = 2 , ADAPTER_TYPE_BUT } | 智能语音引擎适配器类型。 | 
| [ContentType](#contenttype) { DSP_MODLE = 0 , CONTENT_TYPE_BUT } | 数据类型。 | 
| [IntellVoiceEngineMessageType](#intellvoiceenginemessagetype) {<br/>INTELL_VOICE_ENGINE_MSG_NONE = 0 , INTELL_VOICE_ENGINE_MSG_INIT_DONE = 1 , INTELL_VOICE_ENGINE_MSG_ENROLL_COMPLETE = 2 , INTELL_VOICE_ENGINE_MSG_COMMIT_ENROLL_COMPLETE = 3 , INTELL_VOICE_ENGINE_MSG_RECOGNIZE_COMPLETE = 4<br/>} | 回调消息类型。 | 
| [IntellVoiceEngineErrors](#intellvoiceengineerrors) {<br/>INTELL_VOICE_ENGINE_OK = 0 , INTELL_VOICE_ENGINE_ERROR_OFFSET = -100 , INTELL_VOICE_ENGINE_INVALID_PARAMS = -101 , INTELL_VOICE_ENGINE_INIT_FAILED = -102 , INTELL_VOICE_ENGINE_ENROLL_FAILED = -103 , INTELL_VOICE_ENGINE_COMMIT_ENROLL_FAILED = -104 , INTELL_VOICE_ENGINE_WAKEUP_FAILED = -105<br/>} | 回调消息错误码。 | 


## 枚举类型说明


### ContentType

```
enum ContentType
```

**描述**


数据类型。

上层服务读取的数据类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| DSP_MODLE | DSP模型文件 | 
| CONTENT_TYPE_BUT | 无效数据类型 | 


### IntellVoiceEngineAdapterType

```
enum IntellVoiceEngineAdapterType
```

**描述**


智能语音引擎适配器类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| ENROLL_ADAPTER_TYPE | 注册引擎适配器 | 
| WAKEUP_ADAPTER_TYPE | 唤醒引擎适配器 | 
| UPDATE_ADAPTER_TYPE | 静默升级引擎适配器 | 
| ADAPTER_TYPE_BUT | 无效引擎适配器 | 


### IntellVoiceEngineErrors

```
enum IntellVoiceEngineErrors
```

**描述**


回调消息错误码。

通知上层服务的消息错误码。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| INTELL_VOICE_ENGINE_OK | 成功 | 
| INTELL_VOICE_ENGINE_ERROR_OFFSET | 错误码偏移 | 
| INTELL_VOICE_ENGINE_INVALID_PARAMS | 无效参数 | 
| INTELL_VOICE_ENGINE_INIT_FAILED | 初始化失败 | 
| INTELL_VOICE_ENGINE_ENROLL_FAILED | 注册失败 | 
| INTELL_VOICE_ENGINE_COMMIT_ENROLL_FAILED | 确认注册失败 | 
| INTELL_VOICE_ENGINE_WAKEUP_FAILED | 唤醒失败 | 


### IntellVoiceEngineMessageType

```
enum IntellVoiceEngineMessageType
```

**描述**


回调消息类型。

通知上层服务的消息类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| INTELL_VOICE_ENGINE_MSG_NONE | 无效消息类型 | 
| INTELL_VOICE_ENGINE_MSG_INIT_DONE | 初始化完成消息 | 
| INTELL_VOICE_ENGINE_MSG_ENROLL_COMPLETE | 注册完成消息 | 
| INTELL_VOICE_ENGINE_MSG_COMMIT_ENROLL_COMPLETE | 确认注册完成消息 | 
| INTELL_VOICE_ENGINE_MSG_RECOGNIZE_COMPLETE | 唤醒识别消息 | 
