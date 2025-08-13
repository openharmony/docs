# model.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--SE: @zhuguodong8; @jjfeing-->
<!--TSE: @principal87-->

## 概述

提供了模型相关接口，可以用于模型创建、模型推理等，该接口是非线程安全的。

**引用文件：** <mindspore/model.h>

**库：** libmindspore_lite_ndk.so

**系统能力：** SystemCapability.Ai.MindSpore

**起始版本：** 9

**相关模块：** [MindSpore](capi-mindspore.md)

## 汇总

### 结构体

| 名称                                                                   | 描述                              |
|----------------------------------------------------------------------|---------------------------------|
| [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | 张量数组结构体，用于存储张量数组指针和张量数组长度。      |
| [OH_AI_ShapeInfo](capi-mindspore-oh-ai-shapeinfo.md)                 | 形状维度大小，预留最大维度是32，当前实际支持的最大维度是8。 |
| [OH_AI_CallBackParam](capi-mindspore-oh-ai-callbackparam.md)         | 回调函数中传入的算子信息。                   |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md)                                                | 指向模型对象的指针。                                |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md)                                             | 指向训练配置对象的指针。                                |

### 函数

| 名称 | typedef关键字 | 描述                                                                                                                                                                                                                                                  |
| -- | -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [typedef bool (\*OH_AI_KernelCallBack)(const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs,const OH_AI_CallBackParam kernel_Info)](#oh_ai_kernelcallback) | OH_AI_KernelCallBack | 回调函数指针。<br> 该函数指针是用于设置[OH_AI_ModelPredict](capi-model-h.md#oh_ai_modelpredict)函数参数中的两个回调函数。<br> 该指针指向的函数需要包含三个参数，其中inputs和outputs对应了算子的输入和输出张量，kernel_Info表示当前算子的信息。<br> 可以通过回调函数监控算子执行的情况，例如统计算子的执行时间，校验算子的正确性等等。                                  |
| [OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate(void)](#oh_ai_modelcreate) | - | 创建一个模型对象。                                                                                                                                                                                                                                           |
| [OH_AI_API void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)](#oh_ai_modeldestroy) | - | 释放一个模型对象。                                                                                                                                                                                                                                           |
| [OH_AI_API OH_AI_Status OH_AI_ModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)](#oh_ai_modelbuild) | - | 从内存缓冲区加载并编译MindSpore模型。<br> 注意，同一个[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)对象仅能传递给[OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild)或者[OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile)一次，如果多次调用该函数需要创建多个不同的[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。 |
| [OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)](#oh_ai_modelbuildfromfile) | - | 通过模型文件加载并编译MindSpore模型。<br> 注意，同一个[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)对象仅能传递给[OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild)或者[OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile)一次，如果多次调用该函数需要创建多个不同的[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。     |
| [OH_AI_API OH_AI_Status OH_AI_ModelResize(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_ShapeInfo *shape_infos, size_t shape_info_num)](#oh_ai_modelresize) | - | 调整已编译模型的输入形状。                                                                                                                                                                                                                                       |
| [OH_AI_API OH_AI_Status OH_AI_ModelPredict(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_TensorHandleArray *outputs, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)](#oh_ai_modelpredict) | - | 执行模型推理。                                                                                                                                                                                                                                             |
| [OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs(const OH_AI_ModelHandle model)](#oh_ai_modelgetinputs) | - | 获取模型的输入张量数组结构体。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs(const OH_AI_ModelHandle model)](#oh_ai_modelgetoutputs) | - | 获取模型的输出张量数组结构体。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)](#oh_ai_modelgetinputbytensorname) | - | 通过张量名获取模型的输入张量。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)](#oh_ai_modelgetoutputbytensorname) | - | 通过张量名获取模型的输出张量。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate()](#oh_ai_traincfgcreate) | - | 创建训练配置对象指针，仅用于端侧训练。                                                                                                                                                                                                                                 |
| [OH_AI_API void OH_AI_TrainCfgDestroy(OH_AI_TrainCfgHandle *train_cfg)](#oh_ai_traincfgdestroy) | - | 销毁训练配置对象指针，仅用于端侧训练。                                                                                                                                                                                                                                 |
| [OH_AI_API char **OH_AI_TrainCfgGetLossName(OH_AI_TrainCfgHandle train_cfg, size_t *num)](#oh_ai_traincfggetlossname) | - | 获取损失函数的名称列表，仅用于端侧训练。                                                                                                                                                                                                                                |
| [OH_AI_API void OH_AI_TrainCfgSetLossName(OH_AI_TrainCfgHandle train_cfg, const char **loss_name, size_t num)](#oh_ai_traincfgsetlossname) | - | 设置损失函数的名称列表，仅用于端侧训练。                                                                                                                                                                                                                                |
| [OH_AI_API OH_AI_OptimizationLevel OH_AI_TrainCfgGetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg)](#oh_ai_traincfggetoptimizationlevel) | - | 获取训练配置的优化等级，仅用于端侧训练。                                                                                                                                                                                                                                |
| [OH_AI_API void OH_AI_TrainCfgSetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg, OH_AI_OptimizationLevel level)](#oh_ai_traincfgsetoptimizationlevel) | - | 设置训练配置的优化等级，仅用于端侧训练。                                                                                                                                                                                                                                |
| [OH_AI_API OH_AI_Status OH_AI_TrainModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)](#oh_ai_trainmodelbuild) | - | 从内存缓冲区加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。                                                                                                                                                                                                         |
| [OH_AI_API OH_AI_Status OH_AI_TrainModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type,const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)](#oh_ai_trainmodelbuildfromfile) | - | 根据路径读取加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。                                                                                                                                                                                                         |
| [OH_AI_API OH_AI_Status OH_AI_RunStep(OH_AI_ModelHandle model, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)](#oh_ai_runstep) | - | 单步训练模型，仅用于端侧训练。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_Status OH_AI_ModelSetLearningRate(OH_AI_ModelHandle model, float learning_rate)](#oh_ai_modelsetlearningrate) | - | 设置训练的学习率，仅用于端侧训练。                                                                                                                                                                                                                                   |
| [OH_AI_API float OH_AI_ModelGetLearningRate(OH_AI_ModelHandle model)](#oh_ai_modelgetlearningrate) | - | 获取训练的学习率，仅用于端侧训练。                                                                                                                                                                                                                                   |
| [OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetWeights(OH_AI_ModelHandle model)](#oh_ai_modelgetweights) | - | 获取模型的所有权重Tensors，仅用于端侧训练。                                                                                                                                                                                                                           |
| [OH_AI_API OH_AI_Status OH_AI_ModelUpdateWeights(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray new_weights)](#oh_ai_modelupdateweights) | - | 更新模型的权重Tensor内容，仅用于端侧训练。                                                                                                                                                                                                                            |
| [OH_AI_API bool OH_AI_ModelGetTrainMode(OH_AI_ModelHandle model)](#oh_ai_modelgettrainmode) | - | 获取训练模式。                                                                                                                                                                                                                                             |
| [OH_AI_API OH_AI_Status OH_AI_ModelSetTrainMode(OH_AI_ModelHandle model, bool train)](#oh_ai_modelsettrainmode) | - | 设置训练模式，仅用于端侧训练。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_Status OH_AI_ModelSetupVirtualBatch(OH_AI_ModelHandle model, int virtual_batch_multiplier, float lr,float momentum)](#oh_ai_modelsetupvirtualbatch) | - | 设置虚拟batch用于训练，仅用于端侧训练。                                                                                                                                                                                                                              |
| [OH_AI_API OH_AI_Status OH_AI_ExportModel(OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char *model_file,OH_AI_QuantizationType quantization_type, bool export_inference_only,char **output_tensor_name, size_t num)](#oh_ai_exportmodel) | - | 导出训练模型，仅用于端侧训练。                                                                                                                                                                                                                                     |
| [OH_AI_API OH_AI_Status OH_AI_ExportModelBuffer(OH_AI_ModelHandle model, OH_AI_ModelType model_type, void *model_data,size_t *data_size, OH_AI_QuantizationType quantization_type,bool export_inference_only, char **output_tensor_name, size_t num)](#oh_ai_exportmodelbuffer) | - | 导出训练模型内存缓存，仅用于端侧训练。                                                                                                                                                                                                                                 |
| [OH_AI_API OH_AI_Status OH_AI_ExportWeightsCollaborateWithMicro(OH_AI_ModelHandle model, OH_AI_ModelType model_type,const char *weight_file, bool is_inference,bool enable_fp16, char **changeable_weights_name,size_t num)](#oh_ai_exportweightscollaboratewithmicro) | - | 导出模型权重，只能用于micro推理，仅用于端侧训练。                                                                                                                                                                                                                         |

## 函数说明

### OH_AI_KernelCallBack()

```
typedef bool (*OH_AI_KernelCallBack)(const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs,const OH_AI_CallBackParam kernel_Info)
```

**描述**

回调函数指针。<br>该函数指针是用于设置[OH_AI_ModelPredict](capi-model-h.md#oh_ai_modelpredict)函数参数中的两个回调函数。<br>该指针指向的函数需要包含三个参数，其中inputs和outputs对应了算子的输入和输出张量，kernel_Info表示当前算子的信息。<br>可以通过回调函数监控算子执行的情况，例如统计算子的执行时间，校验算子的正确性等等。

**起始版本：** 9


**参数：**

| 参数项                                                                                | 描述      |
|------------------------------------------------------------------------------------|---------|
| const [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) inputs  | 模型输入对应的张量数组结构体。 |
| const [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) outputs | 模型输出对应的张量数组结构体。        |
| const [OH_AI_CallBackParam](capi-mindspore-oh-ai-callbackparam.md) kernel_Info   | 当前算子的信息。        |

**返回：**

| 类型   | 说明 |
|------|----|
| bool | 回调执行是否成功，若成功返回true，失败则返回false。 |

### OH_AI_ModelCreate()

```
OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate(void)
```

**描述**

创建一个模型对象。

**起始版本：** 9

**返回：**

| 类型                              | 说明 |
|---------------------------------| -- |
| OH_AI_API [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) | 模型对象指针。 |

### OH_AI_ModelDestroy()

```
OH_AI_API void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)
```

**描述**

释放一个模型对象。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) *model | 模型对象指针。 |

### OH_AI_ModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)
```

**描述**

从内存缓冲区加载并编译MindSpore模型。<br>注意，同一个[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)对象仅能传递给[OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild)或者[OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile)一次，如果多次调用该函数需要创建多个不同的[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。

**起始版本：** 9


**参数：**

| 参数项 | 描述                                                                            |
| -- |-------------------------------------------------------------------------------|
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。                                                                       |
| const void *model_data | 内存中已经加载的模型数据地址。                                                               |
| size_t data_size | 模型数据的长度。                                                                      |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。                 |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。 |

**返回：**

| 类型 | 说明                                                                                                 |
| -- |----------------------------------------------------------------------------------------------------|
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)
```

**描述**

通过模型文件加载并编译MindSpore模型。<br>注意，同一个[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)对象仅能传递给[OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild)或者[OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile)一次，如果多次调用该函数需要创建多个不同的[OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| const char *model_path | 模型文件路径。 |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。 |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelResize()

```
OH_AI_API OH_AI_Status OH_AI_ModelResize(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_ShapeInfo *shape_infos, size_t shape_info_num)
```

**描述**

调整已编译模型的输入形状。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| [const OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) inputs | 模型输入对应的张量数组结构体。 |
| [OH_AI_ShapeInfo](capi-mindspore-oh-ai-shapeinfo.md) *shape_infos | 输入形状信息数组，按模型输入顺序排列的由形状信息组成的数组，模型会按顺序依次调整张量形状。 |
| size_t shape_info_num | 形状信息数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelPredict()

```
OH_AI_API OH_AI_Status OH_AI_ModelPredict(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_TensorHandleArray *outputs, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)
```

**描述**

执行模型推理。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| [const OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) inputs | 模型输入对应的张量数组结构体。 |
| [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) *outputs | 模型输出对应的张量数组结构体的指针。 |
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) before | 模型推理前执行的回调函数。 |
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) after | 模型推理后执行的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelGetInputs()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs(const OH_AI_ModelHandle model)
```

**描述**

获取模型的输入张量数组结构体。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |

**返回：**

| 类型                                    | 说明 |
|---------------------------------------| -- |
| OH_AI_API [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | 模型输入对应的张量数组结构体。 |

### OH_AI_ModelGetOutputs()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs(const OH_AI_ModelHandle model)
```

**描述**

获取模型的输出张量数组结构体。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | 模型输出对应的张量数组结构体。 |

### OH_AI_ModelGetInputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)
```

**描述**

通过张量名获取模型的输入张量。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| const char *tensor_name | 张量名称。 |

**返回：**

| 类型                               | 说明 |
|----------------------------------| -- |
| OH_AI_API [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | tensor_name所对应的输入张量的张量指针，如果输入中没有该张量则返回空。 |

### OH_AI_ModelGetOutputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)
```

**描述**

通过张量名获取模型的输出张量。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| const char *tensor_name | 张量名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | tensor_name所对应的输入张量的张量指针，如果输出中没有该张量则返回空。 |

### OH_AI_TrainCfgCreate()

```
OH_AI_API OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate()
```

**描述**

创建训练配置对象指针，仅用于端侧训练。

**起始版本：** 11

**返回：**

| 类型                                 | 说明 |
|------------------------------------| -- |
| OH_AI_API [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) | 训练配置对象指针。 |

### OH_AI_TrainCfgDestroy()

```
OH_AI_API void OH_AI_TrainCfgDestroy(OH_AI_TrainCfgHandle *train_cfg)
```

**描述**

销毁训练配置对象指针，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项                                 | 描述 |
|-------------------------------------| -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) *train_cfg | 训练配置对象指针。 |

### OH_AI_TrainCfgGetLossName()

```
OH_AI_API char **OH_AI_TrainCfgGetLossName(OH_AI_TrainCfgHandle train_cfg, size_t *num)
```

**描述**

获取损失函数的名称列表，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | 训练配置对象指针。 |
| size_t *num | 损失函数数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API char ** | 损失函数的名称列表。 |

### OH_AI_TrainCfgSetLossName()

```
OH_AI_API void OH_AI_TrainCfgSetLossName(OH_AI_TrainCfgHandle train_cfg, const char **loss_name, size_t num)
```

**描述**

设置损失函数的名称列表，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | 训练配置对象指针。 |
| const char **loss_name | 损失函数的名称列表。 |
| size_t num | 损失函数数量。 |

### OH_AI_TrainCfgGetOptimizationLevel()

```
OH_AI_API OH_AI_OptimizationLevel OH_AI_TrainCfgGetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg)
```

**描述**

获取训练配置的优化等级，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | 训练配置对象指针。 |

**返回：**

| 类型                                                                           | 说明 |
|------------------------------------------------------------------------------| -- |
| OH_AI_API [OH_AI_OptimizationLevel](capi-types-h.md#oh_ai_optimizationlevel) | 优化等级。 |

### OH_AI_TrainCfgSetOptimizationLevel()

```
OH_AI_API void OH_AI_TrainCfgSetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg, OH_AI_OptimizationLevel level)
```

**描述**

设置训练配置的优化等级，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | 训练配置对象指针。 |
| [OH_AI_OptimizationLevel](capi-types-h.md#oh_ai_optimizationlevel) level | 优化等级。 |

### OH_AI_TrainModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)
```

**描述**

从内存缓冲区加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| const void *model_data | 指向存储读入模型文件缓冲区的指针。 |
| size_t data_size | 缓冲区大小。 |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。 |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。 |
| const [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | 训练配置对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_TrainModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type,const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)
```

**描述**

根据路径读取加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| const char *model_path | 模型文件路径。 |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。 |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md)。 |
| const [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | 训练配置对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_RunStep()

```
OH_AI_API OH_AI_Status OH_AI_RunStep(OH_AI_ModelHandle model, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)
```

**描述**

单步训练模型，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) before | 模型推理前执行的回调函数。 |
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) after | 模型推理后执行的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelSetLearningRate()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetLearningRate(OH_AI_ModelHandle model, float learning_rate)
```

**描述**

设置训练的学习率，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| float learning_rate | 学习率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelGetLearningRate()

```
OH_AI_API float OH_AI_ModelGetLearningRate(OH_AI_ModelHandle model)
```

**描述**

获取训练的学习率，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API float | 学习率，没有设置优化器时为0.0。 |

### OH_AI_ModelGetWeights()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetWeights(OH_AI_ModelHandle model)
```

**描述**

获取模型的所有权重Tensors，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | 模型的所有权重Tensor。 |

### OH_AI_ModelUpdateWeights()

```
OH_AI_API OH_AI_Status OH_AI_ModelUpdateWeights(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray new_weights)
```

**描述**

更新模型的权重Tensor内容，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| [const OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) new_weights | 要更新的权重Tensor。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelGetTrainMode()

```
OH_AI_API bool OH_AI_ModelGetTrainMode(OH_AI_ModelHandle model)
```

**描述**

获取训练模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API bool | 表示是否是训练模式。 |

### OH_AI_ModelSetTrainMode()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetTrainMode(OH_AI_ModelHandle model, bool train)
```

**描述**

设置训练模式，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| bool train | 是否为训练模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ModelSetupVirtualBatch()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetupVirtualBatch(OH_AI_ModelHandle model, int virtual_batch_multiplier, float lr,float momentum)
```

**描述**

设置虚拟batch用于训练，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| int virtual_batch_multiplier | 虚拟batch乘法器，当设置值小于1时，表示禁用虚拟batch。 |
| float lr | 学习率，默认为-1.0f。 |
| float momentum | 动量，默认为-1.0f。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ExportModel()

```
OH_AI_API OH_AI_Status OH_AI_ExportModel(OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char *model_file,OH_AI_QuantizationType quantization_type, bool export_inference_only,char **output_tensor_name, size_t num)
```

**描述**

导出训练模型，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项                                                                                | 描述 |
|------------------------------------------------------------------------------------| -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model                     | 模型对象指针。 |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type                      | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。 |
| const char *model_file                                                             | 导出的模型文件路径。 |
| [OH_AI_QuantizationType](capi-types-h.md#oh_ai_quantizationtype) quantization_type | 量化类型。 |
| bool export_inference_only                                                         | 是否导出推理模型。 |
| char **output_tensor_name                                                          | 设置导出模型的输出Tensor，默认为空表示全量导出。 |
| size_t num                                                                         | 输出Tensor的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ExportModelBuffer()

```
OH_AI_API OH_AI_Status OH_AI_ExportModelBuffer(OH_AI_ModelHandle model, OH_AI_ModelType model_type, void *model_data,size_t *data_size, OH_AI_QuantizationType quantization_type,bool export_inference_only, char **output_tensor_name, size_t num)
```

**描述**

导出训练模型内存缓存，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。 |
| void *model_data | 指向导出模型文件缓冲区的指针。 |
| size_t *data_size | 缓冲区大小。 |
| [OH_AI_QuantizationType](capi-types-h.md#oh_ai_quantizationtype) quantization_type | 量化类型。 |
| bool export_inference_only | 是否导出推理模型。 |
| char **output_tensor_name | 设置导出模型的输出Tensor，默认为空表示全量导出。 |
| size_t num | 输出Tensor的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |

### OH_AI_ExportWeightsCollaborateWithMicro()

```
OH_AI_API OH_AI_Status OH_AI_ExportWeightsCollaborateWithMicro(OH_AI_ModelHandle model, OH_AI_ModelType model_type,const char *weight_file, bool is_inference,bool enable_fp16, char **changeable_weights_name,size_t num)
```

**描述**

导出模型权重，只能用于micro推理，仅用于端侧训练。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | 模型对象指针。 |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | 模型文件类型，具体见[OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype)。 |
| const char *weight_file | 导出的权重文件路径。 |
| bool is_inference | 是否导出推理模型，当前只支持设置为true。 |
| bool enable_fp16 | 浮点权重是否保存为float16格式。 |
| char **changeable_weights_name | shape可变的权重Tensor名称。 |
| size_t num | shape可变的权重Tensor名称的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | 枚举类型的状态码[OH_AI_Status](capi-status-h.md#oh_ai_status)，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。 |


