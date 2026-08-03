# native_audio_suite_engine.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明与音频编创相关接口。（包括引擎、管线、节点）。

**引用文件：** <ohaudiosuite/native_audio_suite_engine.h>

**库：** libohaudiosuite.so

**系统能力：** SystemCapability.Multimedia.Audio.SuiteEngine

**起始版本：** 22

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_Create(OH_AudioSuiteEngine** audioSuiteEngine)](#oh_audiosuiteengine_create) | - | 创建音频编创引擎。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_Destroy(OH_AudioSuiteEngine* audioSuiteEngine)](#oh_audiosuiteengine_destroy) | - | 销毁音频编创引擎句柄。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_CreatePipeline(OH_AudioSuiteEngine* audioSuiteEngine, OH_AudioSuitePipeline** audioSuitePipeline, OH_AudioSuite_PipelineWorkMode workMode)](#oh_audiosuiteengine_createpipeline) | - | 在当前音频编创引擎中创建1个管线。管线是引擎内负责音频编创的执行单元，1个引擎可创建多个管线。<br> 支持最多创建10条管线。在API版本26.0.0之前，实时预览管线最多创建1条；在API版本26.0.0及以后，不再对实时预览管线的数量做单独限制，但管线的总数仍不得超过10条。<br> 每个管线必须至少包含1个输入节点，有且只有1个输出节点。<br> 当管线在[OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode).AUDIOSUITE_PIPELINE_EDIT_MODE模式下工作时，支持所有的效果节点。<br> 在API version 23之前，当管线在[OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode).AUDIOSUITE_PIPELINE_REALTIME_MODE模式下工作时，仅支持[OH_AudioNode_Type](capi-native-audio-suite-base-h.md#oh_audionode_type).EFFECT_NODE_TYPE_EQUALIZER效果节点；<br> 在API version 23及以后，当管线在[OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode).AUDIOSUITE_PIPELINE_REALTIME_MODE模式下工作时，支持所有效果节点。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_DestroyPipeline(OH_AudioSuitePipeline* audioSuitePipeline)](#oh_audiosuiteengine_destroypipeline) | - | 销毁音频编创管线句柄。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_StartPipeline(OH_AudioSuitePipeline* audioSuitePipeline)](#oh_audiosuiteengine_startpipeline) | - | 开始运行该管线，管线会进入[OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate).AUDIOSUITE_PIPELINE_RUNNING运行状态。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_StopPipeline(OH_AudioSuitePipeline* audioSuitePipeline)](#oh_audiosuiteengine_stoppipeline) | - | 停止运行该管线，管线会进入[OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate).AUDIOSUITE_PIPELINE_STOPPED停止状态。该函数不会改变管线中节点之间的连接关系，管线一旦被停止，[OH_AudioSuiteEngine_RenderFrame](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe)就不能再进行音频处理。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetPipelineState(OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioSuite_PipelineState* pipelineState)](#oh_audiosuiteengine_getpipelinestate) | - | 获取当前管线的状态。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_RenderFrame(OH_AudioSuitePipeline* audioSuitePipeline, void* audioData, int32_t requestFrameSize, int32_t* responseSize, bool* finishedFlag)](#oh_audiosuiteengine_renderframe) | - | 应用调用此接口获取管线处理后的音频数据（针对单输出效果节点）。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_MultiRenderFrame(OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioDataArray* audioDataArray, int32_t* responseSize, bool* finishedFlag)](#oh_audiosuiteengine_multirenderframe) | - | 渲染该管线，获取管线处理后的音频数据。针对多输出效果节点，比如包含音源分离节点的管线，audioDataArray的大小需与效果节点的输出数量一一对应（例如：音源分离节点需两个：第1个为人声，第2个为背景声）。 |
| [OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Create(OH_AudioNodeBuilder** builder)](#oh_audiosuitenodebuilder_create) | - | 获取一个音频编创节点构造器，用于配置并创建音频节点。构建器可复用，但若新节点属性与之前不同，必须使用[OH_AudioSuiteNodeBuilder_Reset](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_reset)重置。 |
| [OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Destroy(OH_AudioNodeBuilder* builder)](#oh_audiosuitenodebuilder_destroy) | - | 销毁一个音频编创节点构造器。使用完构造器后必须调用此函数进行销毁。 |
| [OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Reset(OH_AudioNodeBuilder* builder)](#oh_audiosuitenodebuilder_reset) | - | 重置一个音频编创节点构造器，同时将之前使用接口设置参数重置。若需复用构建器创建属性不同的新节点，必须调用此接口清除所有属性（如节点类型等）。 |
| [OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetNodeType(OH_AudioNodeBuilder* builder, OH_AudioNode_Type type)](#oh_audiosuitenodebuilder_setnodetype) | - | 设置当前节点构造器需要构造的节点类型。创建节点时会根据类型验证其他参数，所有节点类型的创建均需设置此属性。 |
| [OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetFormat(OH_AudioNodeBuilder* builder, OH_AudioFormat audioFormat)](#oh_audiosuitenodebuilder_setformat) | - | 配置输入/输出节点的音频格式。其余节点不配置，且只能在创建节点之前使用。对于输入节点，此函数可使应用指定写入数据的音频格式；<br> 对于输出节点，此函数可使应用指定其期望获取数据的音频格式；<br> 对于其他类型的节点则不支持调用此函数进行音频格式设置。 |
| [typedef int32_t (\*OH_InputNode_RequestDataCallback)(OH_AudioNode* audioNode, void* userData, void* audioData, int32_t audioDataSize, bool* finished)](#oh_inputnode_requestdatacallback) | OH_InputNode_RequestDataCallback | 定义输入节点请求数据的回调函数。 |
| [OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetRequestDataCallback(OH_AudioNodeBuilder* builder, OH_InputNode_RequestDataCallback callback, void* userData)](#oh_audiosuitenodebuilder_setrequestdatacallback) | - | 配置当前输入节点构造器的写入音频数据回调函数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_CreateNode(OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioNodeBuilder* builder, OH_AudioNode** audioNode)](#oh_audiosuiteengine_createnode) | - | 根据音频编创构造器在音频管线中构造一个音频节点。当执行此函数，系统会基于builder中设置的节点类型校验参数的合法性。<br> 应用可以通过返回值确定错误发生的原因。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_DestroyNode(OH_AudioNode* audioNode)](#oh_audiosuiteengine_destroynode) | - | 销毁一个音频编创节点。节点是否可以被销毁取决于它所属管线的状态，如果管线不处于[OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate).AUDIOSUITE_PIPELINE_STOPPED停止状态，而节点处于管线处理路径中，将销毁失败。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetNodeBypassStatus(OH_AudioNode* audioNode, bool* bypassStatus)](#oh_audiosuiteengine_getnodebypassstatus) | - | 获取当前节点的效果使能状态。仅效果节点支持获取。<br> 若对输入或输出节点调用此接口，将返回AUDIOSUITE_ERROR_INVALID_PARAM错误码。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_BypassEffectNode(OH_AudioNode* audioNode, bool bypass)](#oh_audiosuiteengine_bypasseffectnode) | - | 设置当前节点的效果使能状态（仅效果节点支持）。当bypass为true时，效果节点仅透传数据，不进行任何效果处理。<br> 当bypass为false时，效果节点进行对应的效果处理。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetAudioFormat(OH_AudioNode* audioNode, OH_AudioFormat *audioFormat)](#oh_audiosuiteengine_setaudioformat) | - | 配置输入/输出节点的音频格式，在创建节点之后使用，只有输入和输出节点能够设置。输入节点指定音源格式，输出节点指定目标格式。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_ConnectNodes(OH_AudioNode* sourceAudioNode, OH_AudioNode* destAudioNode)](#oh_audiosuiteengine_connectnodes) | - | 连接两个节点，数据流走向从sourceAudioNode到destAudioNode。连接节点将改变管道拓扑，可能导致部分数据丢失，建议在引擎停止状态下执行此操作。<br> 节点连接顺序：输入节点 -> 效果节点 -> 输出节点。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_DisconnectNodes(OH_AudioNode* sourceAudioNode, OH_AudioNode* destAudioNode)](#oh_audiosuiteengine_disconnectnodes) | - | 断开两个节点的连接。此操作将改变管道拓扑并可能导致数据丢失，建议在引擎停止状态下执行。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(OH_AudioNode* audioNode, OH_EqualizerFrequencyBandGains frequencyBandGains)](#oh_audiosuiteengine_setequalizerfrequencybandgains) | - | 设置当前均衡器节点的频段增益效果。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetEqualizerFrequencyBandGains(OH_AudioNode* audioNode, OH_EqualizerFrequencyBandGains* frequencyBandGains)](#oh_audiosuiteengine_getequalizerfrequencybandgains) | - | 获取当前均衡器节点的频段增益效果。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetSoundFieldType(OH_AudioNode* audioNode, OH_SoundFieldType soundFieldType)](#oh_audiosuiteengine_setsoundfieldtype) | - | 设置声场效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetSoundFieldType(OH_AudioNode* audioNode, OH_SoundFieldType* soundFieldType)](#oh_audiosuiteengine_getsoundfieldtype) | - | 获取声场效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetEnvironmentType(OH_AudioNode* audioNode, OH_EnvironmentType environmentType)](#oh_audiosuiteengine_setenvironmenttype) | - | 设置环境效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetEnvironmentType(OH_AudioNode* audioNode, OH_EnvironmentType* environmentType)](#oh_audiosuiteengine_getenvironmenttype) | - | 获取环境效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetVoiceBeautifierType(OH_AudioNode* audioNode, OH_VoiceBeautifierType voiceBeautifierType)](#oh_audiosuiteengine_setvoicebeautifiertype) | - | 设置声音美化效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetVoiceBeautifierType(OH_AudioNode* audioNode, OH_VoiceBeautifierType* voiceBeautifierType)](#oh_audiosuiteengine_getvoicebeautifiertype) | - | 获取声音美化效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_IsNodeTypeSupported(OH_AudioNode_Type nodeType, bool* isSupported)](#oh_audiosuiteengine_isnodetypesupported) | - | 查询当前系统是否支持创建指定的节点类型，避免节点创建失败。调用该接口时不依赖引擎及管线状态，仅跟系统相关，无需创建引擎及管线。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetSpaceRenderPositionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderPositionParams position)](#oh_audiosuiteengine_setspacerenderpositionparams) | - | 设置空间渲染效果节点固定摆位模式的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetSpaceRenderPositionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderPositionParams* position)](#oh_audiosuiteengine_getspacerenderpositionparams) | - | 获取空间渲染效果节点固定摆位模式的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetSpaceRenderRotationParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderRotationParams rotation)](#oh_audiosuiteengine_setspacerenderrotationparams) | - | 设置空间渲染效果节点旋转模式的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetSpaceRenderRotationParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderRotationParams* rotation)](#oh_audiosuiteengine_getspacerenderrotationparams) | - | 获取空间渲染效果节点旋转模式的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetSpaceRenderExtensionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderExtensionParams extension)](#oh_audiosuiteengine_setspacerenderextensionparams) | - | 设置空间渲染效果节点扩展模式的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetSpaceRenderExtensionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderExtensionParams* extension)](#oh_audiosuiteengine_getspacerenderextensionparams) | - | 获取空间渲染效果节点扩展模式的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetTempoAndPitch(OH_AudioNode* audioNode, float speed, float pitch)](#oh_audiosuiteengine_settempoandpitch) | - | 设置变速变调效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetTempoAndPitch(OH_AudioNode* audioNode, float* speed, float* pitch)](#oh_audiosuiteengine_gettempoandpitch) | - | 获取变速变调效果节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetPureVoiceChangeOption(OH_AudioNode* audioNode, OH_AudioSuite_PureVoiceChangeOption option)](#oh_audiosuiteengine_setpurevoicechangeoption) | - | 设置传统变声节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetPureVoiceChangeOption(OH_AudioNode* audioNode, OH_AudioSuite_PureVoiceChangeOption* option)](#oh_audiosuiteengine_getpurevoicechangeoption) | - | 获取传统变声节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_SetGeneralVoiceChangeType(OH_AudioNode* audioNode, OH_AudioSuite_GeneralVoiceChangeType type)](#oh_audiosuiteengine_setgeneralvoicechangetype) | - | 设置通用变声节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuiteEngine_GetGeneralVoiceChangeType(OH_AudioNode* audioNode, OH_AudioSuite_GeneralVoiceChangeType* type)](#oh_audiosuiteengine_getgeneralvoicechangetype) | - | 获取通用变声节点的配置参数。 |
| [OH_AudioSuite_Result OH_AudioSuite_PrintInfo(OH_AudioSuiteEngine* audioSuiteEngine, OH_AudioSuitePipeline* audioSuitePipeline, int fd)](#oh_audiosuite_printinfo) | - | 打印AudioSuite运行时快照。 |

## 函数说明

### OH_AudioSuiteEngine_Create()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_Create(OH_AudioSuiteEngine** audioSuiteEngine)
```

**描述**

创建音频编创引擎。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuiteEngine](capi-ohaudiosuite-oh-audiosuiteenginestruct.md)** audioSuiteEngine | 音频编创引擎句柄，指向接收audioSuiteEngine变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioSuiteEngine为空指针。<br>         AUDIOSUITE_ERROR_INVALID_STATE：引擎已经被初始化。<br>         AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED：内存申请失败。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_Destroy()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_Destroy(OH_AudioSuiteEngine* audioSuiteEngine)
```

**描述**

销毁音频编创引擎句柄。

>**说明：** 
>销毁引擎时会同时销毁该引擎下的所有管线。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuiteEngine](capi-ohaudiosuite-oh-audiosuiteenginestruct.md)* audioSuiteEngine | 音频编创引擎句柄，通过[OH_AudioSuiteEngine_Create](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_create)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioSuiteEngine为空指针。<br>         AUDIOSUITE_ERROR_INVALID_STATE：引擎已被去初始化、引擎未创建或未初始化引擎。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_CreatePipeline()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_CreatePipeline(OH_AudioSuiteEngine* audioSuiteEngine, OH_AudioSuitePipeline** audioSuitePipeline, OH_AudioSuite_PipelineWorkMode workMode)
```

**描述**

在当前音频编创引擎中创建1个管线。管线是引擎内负责音频编创的执行单元，1个引擎可创建多个管线。<br> 支持最多创建10条管线。在API版本26.0.0之前，实时预览管线最多创建1条；在API版本26.0.0及以后，不再对实时预览管线的数量做单独限制，但管线的总数仍不得超过10条。<br> 每个管线必须至少包含1个输入节点，有且只有1个输出节点。<br> 当管线在[OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode).AUDIOSUITE_PIPELINE_EDIT_MODE模式下工作时，支持所有的效果节点。<br> 在API version 23之前，当管线在[OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode).AUDIOSUITE_PIPELINE_REALTIME_MODE模式下工作时，仅支持[OH_AudioNode_Type](capi-native-audio-suite-base-h.md#oh_audionode_type).EFFECT_NODE_TYPE_EQUALIZER效果节点；<br> 在API version 23及以后，当管线在[OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode).AUDIOSUITE_PIPELINE_REALTIME_MODE模式下工作时，支持所有效果节点。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuiteEngine](capi-ohaudiosuite-oh-audiosuiteenginestruct.md)* audioSuiteEngine | 音频编创引擎句柄。通过[OH_AudioSuiteEngine_Create](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_create)获取句柄。 |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)** audioSuitePipeline | 音频编创管线句柄。 |
| [OH_AudioSuite_PipelineWorkMode](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelineworkmode) workMode | 管线工作模式。<br> 1. AUDIOSUITE_PIPELINE_EDIT_MODE: 支持所有效果节点；<br> 2. AUDIOSUITE_PIPELINE_REALTIME_MODE：支持均衡器等节点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioSuiteEngine为空指针或参数audioSuitePipeline为空指针。<br>         AUDIOSUITE_ERROR_ENGINE_NOT_EXIST：未初始化引擎。<br>         AUDIOSUITE_ERROR_CREATED_EXCEED_SYSTEM_LIMITS：创建管线数量超过系统最大数量限制（引擎最多创建10条管线）。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED：内存申请失败。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_DestroyPipeline()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_DestroyPipeline(OH_AudioSuitePipeline* audioSuitePipeline)
```

**描述**

销毁音频编创管线句柄。

>**说明：** 
>销毁管线时会同时销毁该管线下的所有节点。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取需要销毁的句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioSuitePipeline为空指针。<br>         AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST：管线不存在或已经被销毁。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_StartPipeline()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_StartPipeline(OH_AudioSuitePipeline* audioSuitePipeline)
```

**描述**

开始运行该管线，管线会进入[OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate).AUDIOSUITE_PIPELINE_RUNNING运行状态。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioSuitePipeline为空指针。<br>         AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST：管线不存在或已经被销毁。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线已在运行或节点连接异常。<br>         可能的原因如下：<br>         1. 管线已经在运行状态；<br>         2. 当前管线中不存在输出类型节点；<br>         3. 起始节点不是输入类型节点。<br>         4. HOA输入节点未连接HOA空间渲染节点，或HOA空间渲染节点的前置节点不是HOA输入节点。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_StopPipeline()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_StopPipeline(OH_AudioSuitePipeline* audioSuitePipeline)
```

**描述**

停止运行该管线，管线会进入[OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate).AUDIOSUITE_PIPELINE_STOPPED停止状态。该函数不会改变管线中节点之间的连接关系，管线一旦被停止，[OH_AudioSuiteEngine_RenderFrame](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe)就不能再进行音频处理。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioSuitePipeline为空指针。<br>         AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST：管线不存在或已经被销毁。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线已在停止状态。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetPipelineState()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetPipelineState(OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioSuite_PipelineState* pipelineState)
```

**描述**

获取当前管线的状态。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取句柄。 |
| [OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate)* pipelineState | 管线状态的输出参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioSuitePipeline为空指针等。<br>         AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST：管线不存在或已经被销毁。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_RenderFrame()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_RenderFrame(OH_AudioSuitePipeline* audioSuitePipeline, void* audioData, int32_t requestFrameSize, int32_t* responseSize, bool* finishedFlag)
```

**描述**

应用调用此接口获取管线处理后的音频数据（针对单输出效果节点）。

> **说明：** 
>
> 应用程序需调用此接口获取经过效果处理后的音频数据。
> * 调用后，管线会从输出节点向前依次拉取数据、应用效果处理，
> * 最终将处理后的数据填充到应用程序传入的audioData指针中。
> * 系统会尝试按requestFrameSize请求的大小填充数据，实际处理的数据大小通过responseSize返回给应用程序。
> * 当应用程序为所有输入节点准备好数据并通过回调提交最后一次数据时，应在回调中设置完成标志。
> * 当管线中所有输入都传递了完成标志后，接口处理完成后会通过finishedFlag通知应用程序。
> * 若finishedFlag为true，应用程序不应再调用此接口。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取句柄。 |
| void* audioData | 获取音频需要写入的数据地址。 |
| int32_t requestFrameSize | audioData的内存字节大小，需大于0。 |
| int32_t* responseSize | 管线写入audioData的音频数据大小，不会大于requestFrameSize，单位为字节。 |
| bool* finishedFlag | 标识当前管线是否渲染完成。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数为空指针或无效值。<br>         可能的原因如下：<br>         1. 参数audioSuitePipeline为空指针；<br>         2. 参数audioData为空指针；<br>         3. 参数requestFrameSize小于等于0；<br>         4. 参数responseSize为空指针；<br>         5. 参数finishedFlag为空指针。<br>         AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST：管线不存在或已经被销毁。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线不在运行状态。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：管线渲染已完成（之前调用该接口时finishedFlag已写入为true）。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_MultiRenderFrame()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_MultiRenderFrame(OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioDataArray* audioDataArray, int32_t* responseSize, bool* finishedFlag)
```

**描述**

渲染该管线，获取管线处理后的音频数据。针对多输出效果节点，比如包含音源分离节点的管线，audioDataArray的大小需与效果节点的输出数量一一对应（例如：音源分离节点需两个：第1个为人声，第2个为背景声）。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取句柄。 |
| [OH_AudioDataArray](capi-ohaudiosuite-oh-audiodataarray.md)* audioDataArray | 用户读取音频数据时所使用的数组指针，每个一维数组大小需一致。 |
| int32_t* responseSize | 管线写入audioData的音频数据大小。系统会确保每个一维数组被填充的数据大小一致，单位为字节。 |
| bool* finishedFlag | 标记当前管线是否渲染完成。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数为空指针或无效值。<br>         可能的原因如下：<br>         1. 参数audioSuitePipeline为空指针；<br>         2. 参数audioDataArray为空指针；<br>         3. 参数audioDataArray中的某个成员为空指针；<br>         4. 参数audioDataArray中的requestFrameSize小于等于0；<br>         5. 参数responseSize为空指针；<br>         6. 参数finishedFlag为空指针。<br>         AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST：管线不存在或已经被销毁。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线不在运行状态。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：管线渲染已完成（之前调用该接口时finishedFlag已写入为true）。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteNodeBuilder_Create()

```c
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Create(OH_AudioNodeBuilder** builder)
```

**描述**

获取一个音频编创节点构造器，用于配置并创建音频节点。构建器可复用，但若新节点属性与之前不同，必须使用[OH_AudioSuiteNodeBuilder_Reset](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_reset)重置。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)** builder | 音频编创节点构造器句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，builder为空指针。<br>         AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED：内存申请失败。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteNodeBuilder_Destroy()

```c
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Destroy(OH_AudioNodeBuilder* builder)
```

**描述**

销毁一个音频编创节点构造器。使用完构造器后必须调用此函数进行销毁。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)* builder | 音频编创节点构造器句柄。通过[OH_AudioSuiteNodeBuilder_Create](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_create)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，builder为空指针。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteNodeBuilder_Reset()

```c
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Reset(OH_AudioNodeBuilder* builder)
```

**描述**

重置一个音频编创节点构造器，同时将之前使用接口设置参数重置。若需复用构建器创建属性不同的新节点，必须调用此接口清除所有属性（如节点类型等）。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)* builder | 音频编创节点构造器句柄。通过[OH_AudioSuiteNodeBuilder_Create](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_create)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，builder为空指针。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteNodeBuilder_SetNodeType()

```c
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetNodeType(OH_AudioNodeBuilder* builder, OH_AudioNode_Type type)
```

**描述**

设置当前节点构造器需要构造的节点类型。创建节点时会根据类型验证其他参数，所有节点类型的创建均需设置此属性。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)* builder | 音频编创节点构造器句柄。通过[OH_AudioSuiteNodeBuilder_Create](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_create)获取句柄。 |
| [OH_AudioNode_Type](capi-native-audio-suite-base-h.md#oh_audionode_type) type | 节点类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：配置节点类型成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效，例如，builder为空指针。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteNodeBuilder_SetFormat()

```c
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetFormat(OH_AudioNodeBuilder* builder, OH_AudioFormat audioFormat)
```

**描述**

配置输入/输出节点的音频格式。其余节点不配置，且只能在创建节点之前使用。对于输入节点，此函数可使应用指定写入数据的音频格式；<br> 对于输出节点，此函数可使应用指定其期望获取数据的音频格式；<br> 对于其他类型的节点则不支持调用此函数进行音频格式设置。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)* builder | 音频编创节点构造器句柄。通过[OH_AudioSuiteNodeBuilder_Create](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_create)获取句柄。 |
| [OH_AudioFormat](capi-ohaudiosuite-oh-audioformat.md) audioFormat | 音频流格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效，例如，builder为空指针。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_FORMAT：audioFormat中的channelCount不支持。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_InputNode_RequestDataCallback()

```c
typedef int32_t (*OH_InputNode_RequestDataCallback)(OH_AudioNode* audioNode, void* userData, void* audioData, int32_t audioDataSize, bool* finished)
```

**描述**

定义输入节点请求数据的回调函数。

> **说明：**
>  
> 用户把需要处理的PCM音频数据写入到audioData，OHAudioSuite从audioData拿到数据进行音频编创。
> * 应用程序在此回调中向audioData写入不超过audioDataSize大小的数据。
> * 当所有数据通过回调传递给管线后，应用程序应在最后一次回调中将finished设为true，此后管线不再调用此接口。
> * 只有输入节点需要配置，其余节点不配置。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_AudioNode* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| void* userData | 用户使用的数据指针。系统调用此回调函数时，将使用[OH_AudioSuiteNodeBuilder_SetRequestDataCallback](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_setrequestdatacallback)接口传入的userData。 |
| void* audioData | 系统提供的内存地址，用于将需要处理的音频数据流写入（需由用户填充）。 |
| int32_t audioDataSize | audioData内存地址的字节大小。 |
| bool* finished | 标记audioNode节点需要处理的音频数据流是否已经写入完成。true表示已完成，false表示未完成。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 写入audioData缓冲区的有效数据长度（单位为字节）。<br> 返回值范围必须在[0, audioDataSize]范围内，如果返回值小于0，系统会将其修改为0，<br> 如果返回值大于audioDataSize，系统会将其修改为audioDataSize。 |

### OH_AudioSuiteNodeBuilder_SetRequestDataCallback()

```c
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetRequestDataCallback(OH_AudioNodeBuilder* builder, OH_InputNode_RequestDataCallback callback, void* userData)
```

**描述**

配置当前输入节点构造器的写入音频数据回调函数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)* builder | 音频编创节点构造器句柄。通过[OH_AudioSuiteNodeBuilder_Create](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_create)获取句柄。 |
| [OH_InputNode_RequestDataCallback](capi-native-audio-suite-engine-h.md#oh_inputnode_requestdatacallback) callback | 写入当前节点音频数据的回调接口。 |
| void* userData | 用户自定义数据，会在callback函数中将地址传入给用户，如果不使用，可以传入空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：<br>         可能的原因如下：<br>         1. 参数builder为空指针；<br>         2. 参数callback为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_CreateNode()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_CreateNode(OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioNodeBuilder* builder, OH_AudioNode** audioNode)
```

**描述**

根据音频编创构造器在音频管线中构造一个音频节点。当执行此函数，系统会基于builder中设置的节点类型校验参数的合法性。<br> 应用可以通过返回值确定错误发生的原因。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 音频编创管线句柄。通过[OH_AudioSuiteEngine_CreatePipeline](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createpipeline)获取句柄。 |
| [OH_AudioNodeBuilder](capi-ohaudiosuite-oh-audionodebuilderstruct.md)* builder | 音频编创节点构造器句柄。通过[OH_AudioSuiteNodeBuilder_Create](capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_create)获取句柄。 |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)** audioNode | 音频编创节点句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数为空指针或无效值。<br>         可能的原因如下：<br>         1. 参数audioSuitePipeline为空指针；<br>         2. 参数builder为空指针；<br>         3. 参数audioNode为空指针。<br>         AUDIOSUITE_ERROR_CREATED_EXCEED_SYSTEM_LIMITS：当构建当前类型的节点数量超过管线限制。<br>         例如，在API version 24之前，创建效果类节点的数量超过5个；在API version 24及以后，创建效果类节点的数量超过15个。<br>         AUDIOSUITE_ERROR_REQUIRED_PARAMETERS_MISSING：构建builder中type类型的节点时缺少必要参数。<br>         例如，builder未设置节点类型。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：当前构造器节点类型为输出节点但设置了回调函数，<br>         或构造器节点类型为效果节点但设置了音频格式或回调函数。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED：内存申请失败。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_DestroyNode()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_DestroyNode(OH_AudioNode* audioNode)
```

**描述**

销毁一个音频编创节点。节点是否可以被销毁取决于它所属管线的状态，如果管线不处于[OH_AudioSuite_PipelineState](capi-native-audio-suite-base-h.md#oh_audiosuite_pipelinestate).AUDIOSUITE_PIPELINE_STOPPED停止状态，而节点处于管线处理路径中，将销毁失败。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioNode为空指针。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线不在停止状态。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetNodeBypassStatus()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetNodeBypassStatus(OH_AudioNode* audioNode, bool* bypassStatus)
```

**描述**

获取当前节点的效果使能状态。仅效果节点支持获取。<br> 若对输入或输出节点调用此接口，将返回AUDIOSUITE_ERROR_INVALID_PARAM错误码。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| bool* bypassStatus | 获取当前效果类节点使能状态，false表示未跳过节点处理，true表示已跳过节点处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：<br>         参数audioNode或bypassStatus为空指针。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非效果类节点。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_BypassEffectNode()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_BypassEffectNode(OH_AudioNode* audioNode, bool bypass)
```

**描述**

设置当前节点的效果使能状态（仅效果节点支持）。当bypass为true时，效果节点仅透传数据，不进行任何效果处理。<br> 当bypass为false时，效果节点进行对应的效果处理。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| bool bypass | 当前效果类节点使能状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioNode为空指针。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode为非效果节点。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetAudioFormat()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetAudioFormat(OH_AudioNode* audioNode, OH_AudioFormat *audioFormat)
```

**描述**

配置输入/输出节点的音频格式，在创建节点之后使用，只有输入和输出节点能够设置。输入节点指定音源格式，输出节点指定目标格式。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioFormat](capi-ohaudiosuite-oh-audioformat.md) *audioFormat | 音频流格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数audioNode或audioFormat为空指针。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode是效果节点。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_FORMAT：（API版本26.0.0新增）参数audioFormat为不支持的格式。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线不在停止状态。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_ConnectNodes()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_ConnectNodes(OH_AudioNode* sourceAudioNode, OH_AudioNode* destAudioNode)
```

**描述**

连接两个节点，数据流走向从sourceAudioNode到destAudioNode。连接节点将改变管道拓扑，可能导致部分数据丢失，建议在引擎停止状态下执行此操作。<br> 节点连接顺序：输入节点 -> 效果节点 -> 输出节点。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* sourceAudioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* destAudioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数sourceAudioNode或destAudioNode为空指针。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_CONNECT：节点之间不支持连接。<br>         可能的原因如下：<br>         1. 参数sourceAudioNode类型为输出类型节点；<br>         2. 参数destAudioNode类型为输入类型节点；<br>         3. 参数sourceAudioNode和destAudioNode为同一个节点；<br>         4. 参数sourceAudioNode为音源分离类型，但是destAudioNode类型不为输出类型节点；<br>         5. 参数sourceAudioNode和destAudioNode不为同一个管线中的节点；<br>         6. 管线状态为运行状态，但是destAudioNode不为mix类型节点；<br>         7. 管线状态为运行状态，destAudioNode为mix类型节点，但是sourceAudioNode节点未连接输入类型节点。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线为无效状态。例如，无法找到输出节点。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_DisconnectNodes()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_DisconnectNodes(OH_AudioNode* sourceAudioNode, OH_AudioNode* destAudioNode)
```

**描述**

断开两个节点的连接。此操作将改变管道拓扑并可能导致数据丢失，建议在引擎停止状态下执行。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* sourceAudioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* destAudioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数sourceAudioNode或destAudioNode为空指针。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：不支持操作。<br>         可能的原因如下：<br>         1. 参数sourceAudioNode类型为输出类型节点；<br>         2. 参数destAudioNode为类型为输入类型节点；<br>         3. 参数sourceAudioNode和destAudioNode为同一个节点；<br>         4. 参数sourceAudioNode和destAudioNode不为同一个管线中的节点；<br>         5. 管线状态为运行状态，但是destAudioNode不为mix类型节点；<br>         6. 管线状态为运行状态，destAudioNode为mix类型节点，但是mix节点当前只连接了sourceAudioNode一个输入。<br>         AUDIOSUITE_ERROR_INVALID_STATE：管线为无效状态。例如，无法找到输出节点。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(OH_AudioNode* audioNode, OH_EqualizerFrequencyBandGains frequencyBandGains)
```

**描述**

设置当前均衡器节点的频段增益效果。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_EqualizerFrequencyBandGains](capi-ohaudiosuite-oh-equalizerfrequencybandgains.md) frequencyBandGains | 均衡器节点的均衡参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非均衡器节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：<br>         可能的原因如下：<br>         1. 参数audioNode为空指针；<br>         2. 参数frequencyBandGains每个成员的值范围不在[-10, 10]。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetEqualizerFrequencyBandGains()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetEqualizerFrequencyBandGains(OH_AudioNode* audioNode, OH_EqualizerFrequencyBandGains* frequencyBandGains)
```

**描述**

获取当前均衡器节点的频段增益效果。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_EqualizerFrequencyBandGains](capi-ohaudiosuite-oh-equalizerfrequencybandgains.md)* frequencyBandGains | 均衡器节点的均衡参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非均衡器节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode或frequencyBandGains为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetSoundFieldType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetSoundFieldType(OH_AudioNode* audioNode, OH_SoundFieldType soundFieldType)
```

**描述**

设置声场效果节点的配置参数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_SoundFieldType](capi-native-audio-suite-base-h.md#oh_soundfieldtype) soundFieldType | 声场效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非声场节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetSoundFieldType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetSoundFieldType(OH_AudioNode* audioNode, OH_SoundFieldType* soundFieldType)
```

**描述**

获取声场效果节点的配置参数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_SoundFieldType](capi-native-audio-suite-base-h.md#oh_soundfieldtype)* soundFieldType | 声场效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非soundFieldType节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode或soundFieldType为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetEnvironmentType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetEnvironmentType(OH_AudioNode* audioNode, OH_EnvironmentType environmentType)
```

**描述**

设置环境效果节点的配置参数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_EnvironmentType](capi-native-audio-suite-base-h.md#oh_environmenttype) environmentType | 环境效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非环境节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetEnvironmentType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetEnvironmentType(OH_AudioNode* audioNode, OH_EnvironmentType* environmentType)
```

**描述**

获取环境效果节点的配置参数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_EnvironmentType](capi-native-audio-suite-base-h.md#oh_environmenttype)* environmentType | 环境效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非环境效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode或environmentType为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetVoiceBeautifierType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetVoiceBeautifierType(OH_AudioNode* audioNode, OH_VoiceBeautifierType voiceBeautifierType)
```

**描述**

设置声音美化效果节点的配置参数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_VoiceBeautifierType](capi-native-audio-suite-base-h.md#oh_voicebeautifiertype) voiceBeautifierType | 声音美化效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非声音美化效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetVoiceBeautifierType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetVoiceBeautifierType(OH_AudioNode* audioNode, OH_VoiceBeautifierType* voiceBeautifierType)
```

**描述**

获取声音美化效果节点的配置参数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_VoiceBeautifierType](capi-native-audio-suite-base-h.md#oh_voicebeautifiertype)* voiceBeautifierType | 声音美化效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非声音美化效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。<br>         例如，audioNode或voiceBeautifierType为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_IsNodeTypeSupported()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_IsNodeTypeSupported(OH_AudioNode_Type nodeType, bool* isSupported)
```

**描述**

查询当前系统是否支持创建指定的节点类型，避免节点创建失败。调用该接口时不依赖引擎及管线状态，仅跟系统相关，无需创建引擎及管线。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode_Type](capi-native-audio-suite-base-h.md#oh_audionode_type) nodeType | 待查的节点类型。 |
| bool* isSupported | 表示是否支持当前节点的创建。false表示未支持，true表示已支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：查询函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：传入非法参数。<br>         例如，入参nodeType不在OH_AudioNode_Type枚举类型范围内、isSupported为空指针等。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetSpaceRenderPositionParams()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetSpaceRenderPositionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderPositionParams position)
```

**描述**

设置空间渲染效果节点固定摆位模式的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_SpaceRenderPositionParams](capi-ohaudiosuite-oh-audiosuite-spacerenderpositionparams.md) position | 空间渲染效果节点固定摆位模式的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非空间渲染效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetSpaceRenderPositionParams()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetSpaceRenderPositionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderPositionParams* position)
```

**描述**

获取空间渲染效果节点固定摆位模式的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_SpaceRenderPositionParams](capi-ohaudiosuite-oh-audiosuite-spacerenderpositionparams.md)* position | 空间渲染效果节点固定摆位模式的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非空间渲染效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetSpaceRenderRotationParams()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetSpaceRenderRotationParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderRotationParams rotation)
```

**描述**

设置空间渲染效果节点旋转模式的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_SpaceRenderRotationParams](capi-ohaudiosuite-oh-audiosuite-spacerenderrotationparams.md) rotation | 空间渲染效果节点旋转模式的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非空间渲染效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetSpaceRenderRotationParams()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetSpaceRenderRotationParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderRotationParams* rotation)
```

**描述**

获取空间渲染效果节点旋转模式的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_SpaceRenderRotationParams](capi-ohaudiosuite-oh-audiosuite-spacerenderrotationparams.md)* rotation | 空间渲染效果节点旋转模式的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非空间渲染效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetSpaceRenderExtensionParams()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetSpaceRenderExtensionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderExtensionParams extension)
```

**描述**

设置空间渲染效果节点扩展模式的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_SpaceRenderExtensionParams](capi-ohaudiosuite-oh-audiosuite-spacerenderextensionparams.md) extension | 空间渲染效果节点扩展模式的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非空间渲染效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetSpaceRenderExtensionParams()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetSpaceRenderExtensionParams(OH_AudioNode* audioNode, OH_AudioSuite_SpaceRenderExtensionParams* extension)
```

**描述**

获取空间渲染效果节点扩展模式的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_SpaceRenderExtensionParams](capi-ohaudiosuite-oh-audiosuite-spacerenderextensionparams.md)* extension | 空间渲染效果节点扩展模式的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非空间渲染效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetTempoAndPitch()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetTempoAndPitch(OH_AudioNode* audioNode, float speed, float pitch)
```

**描述**

设置变速变调效果节点的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| float speed | 变速参数。取值范围为[0.5, 10.0]。 |
| float pitch | 变调参数。取值范围为[0.1, 5.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非变速变调效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetTempoAndPitch()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetTempoAndPitch(OH_AudioNode* audioNode, float* speed, float* pitch)
```

**描述**

获取变速变调效果节点的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| float* speed | 变速参数。取值范围为[0.5, 10.0]。 |
| float* pitch | 变调参数。取值范围为[0.1, 5.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非变速变调效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetPureVoiceChangeOption()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetPureVoiceChangeOption(OH_AudioNode* audioNode, OH_AudioSuite_PureVoiceChangeOption option)
```

**描述**

设置传统变声节点的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_PureVoiceChangeOption](capi-ohaudiosuite-oh-audiosuite-purevoicechangeoption.md) option | 传统变声效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非传统变声效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetPureVoiceChangeOption()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetPureVoiceChangeOption(OH_AudioNode* audioNode, OH_AudioSuite_PureVoiceChangeOption* option)
```

**描述**

获取传统变声节点的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_PureVoiceChangeOption](capi-ohaudiosuite-oh-audiosuite-purevoicechangeoption.md)* option | 传统变声效果节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非传统变声效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_SetGeneralVoiceChangeType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_SetGeneralVoiceChangeType(OH_AudioNode* audioNode, OH_AudioSuite_GeneralVoiceChangeType type)
```

**描述**

设置通用变声节点的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_GeneralVoiceChangeType](capi-native-audio-suite-base-h.md#oh_audiosuite_generalvoicechangetype) type | 通用变声节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非通用变声效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuiteEngine_GetGeneralVoiceChangeType()

```c
OH_AudioSuite_Result OH_AudioSuiteEngine_GetGeneralVoiceChangeType(OH_AudioNode* audioNode, OH_AudioSuite_GeneralVoiceChangeType* type)
```

**描述**

获取通用变声节点的配置参数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioNode](capi-ohaudiosuite-oh-audionodestruct.md)* audioNode | 音频编创节点句柄。通过[OH_AudioSuiteEngine_CreateNode](capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_createnode)获取句柄。 |
| [OH_AudioSuite_GeneralVoiceChangeType](capi-native-audio-suite-base-h.md#oh_audiosuite_generalvoicechangetype)* type | 通用变声节点的配置参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_NODE_NOT_EXIST：节点不存在或者当前节点已经被销毁。<br>         AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION：audioNode节点类型为非通用变声效果节点。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数无效。例如，audioNode为空指针。<br>         AUDIOSUITE_ERROR_TIMEOUT：操作处理超时。<br>         AUDIOSUITE_ERROR_SYSTEM：系统发生其他异常。 |

### OH_AudioSuite_PrintInfo()

```c
OH_AudioSuite_Result OH_AudioSuite_PrintInfo(OH_AudioSuiteEngine* audioSuiteEngine, OH_AudioSuitePipeline* audioSuitePipeline, int fd)
```

**描述**

打印AudioSuite运行时快照。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuiteEngine](capi-ohaudiosuite-oh-audiosuiteenginestruct.md)* audioSuiteEngine | 指向需要显示运行时快照的AudioSuiteEngine的指针。 |
| [OH_AudioSuitePipeline](capi-ohaudiosuite-oh-audiosuitepipelinestruct.md)* audioSuitePipeline | 指向需要显示运行时快照的AudioSuitePipeline的指针。<br>                           如果audioSuitePipeline为空，输出所有管道（引擎下的所有管道/节点）。否则，仅输出此流程和节点的快照。 |
| int fd | 文件句柄，表示快照信息存储的位置。<br>           如果fd小于0，快照信息存储在日志中。否则，快照将以追加模式存储在由fd句柄指向的文件中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioSuite_Result](capi-native-audio-suite-base-h.md#oh_audiosuite_result) | AUDIOSUITE_SUCCESS：函数执行成功。<br>         AUDIOSUITE_ERROR_INVALID_PARAM：参数为nullptr或无效值。<br>         AUDIOSUITE_ERROR_SYSTEM：系统存在其他异常。 |


