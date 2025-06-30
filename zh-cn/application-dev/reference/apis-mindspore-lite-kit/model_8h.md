# model.h


## 概述

提供了模型相关接口，可以用于模型创建、模型推理等，该接口是非线程安全的。

**引用文件：** <mindspore/model.h>

**库：** libmindspore_lite_ndk.so

**系统能力：** SystemCapability.Ai.MindSpore

**起始版本：** 9

**相关模块：**[MindSpore](_mind_spore.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。 |
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | 回调函数中传入的算子信息。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](_mind_spore.md#oh_ai_max_shape_num) 32 | 张量维度的最大值。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) | 指向模型对象的指针。 |
| [OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) | 指向训练配置对象的指针。 |
| [OH_AI_TensorHandleArray](_mind_spore.md#oh_ai_tensorhandlearray) | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。 |
| [OH_AI_CallBackParam](_mind_spore.md#oh_ai_callbackparam) | 回调函数中传入的算子信息。 |
| [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback)) (const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) outputs, const [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) kernel_Info) | 回调函数指针。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelCreate](_mind_spore.md#oh_ai_modelcreate) (void) | 创建一个模型对象。 |
| [OH_AI_ModelDestroy](_mind_spore.md#oh_ai_modeldestroy) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) \*model) | 释放一个模型对象。 |
| [OH_AI_ModelBuild](_mind_spore.md#oh_ai_modelbuild) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context) | 从内存缓冲区加载并编译MindSpore模型。 |
| [OH_AI_ModelBuildFromFile](_mind_spore.md#oh_ai_modelbuildfromfile) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context) | 通过模型文件加载并编译MindSpore模型。 |
| [OH_AI_ModelResize](_mind_spore.md#oh_ai_modelresize) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) \*shape_infos, size_t shape_info_num) | 调整已编译模型的输入形状。 |
| [OH_AI_ModelPredict](_mind_spore.md#oh_ai_modelpredict) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) \*outputs, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) after) | 执行模型推理。 |
| [OH_AI_ModelGetInputs](_mind_spore.md#oh_ai_modelgetinputs) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | 获取模型的输入张量数组结构体。 |
| [OH_AI_ModelGetOutputs](_mind_spore.md#oh_ai_modelgetoutputs) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | 获取模型的输出张量数组结构体。 |
| [OH_AI_ModelGetInputByTensorName](_mind_spore.md#oh_ai_modelgetinputbytensorname) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*tensor_name) | 通过张量名获取模型的输入张量。 |
| [OH_AI_ModelGetOutputByTensorName](_mind_spore.md#oh_ai_modelgetoutputbytensorname) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*tensor_name) | 通过张量名获取模型的输出张量。 |
| [OH_AI_TrainCfgCreate](_mind_spore.md#oh_ai_traincfgcreate) () | 创建训练配置对象指针，仅用于端侧训练。 |
| [OH_AI_TrainCfgDestroy](_mind_spore.md#oh_ai_traincfgdestroy) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) \*train_cfg) | 销毁训练配置对象指针，仅用于端侧训练。 |
| [OH_AI_TrainCfgGetLossName](_mind_spore.md#oh_ai_traincfggetlossname) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg, size_t \*num) | 获取损失函数的名称列表，仅用于端侧训练。 |
| [OH_AI_TrainCfgSetLossName](_mind_spore.md#oh_ai_traincfgsetlossname) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg, const char \*\*loss_name, size_t num) | 设置损失函数的名称列表，仅用于端侧训练。 |
| [OH_AI_TrainCfgGetOptimizationLevel](_mind_spore.md#oh_ai_traincfggetoptimizationlevel) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg) | 获取训练配置的优化等级，仅用于端侧训练。 |
| [OH_AI_TrainCfgSetOptimizationLevel](_mind_spore.md#oh_ai_traincfgsetoptimizationlevel) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg, [OH_AI_OptimizationLevel](_mind_spore.md#oh_ai_optimizationlevel) level) | 设置训练配置的优化等级，仅用于端侧训练。 |
| [OH_AI_TrainModelBuild](_mind_spore.md#oh_ai_trainmodelbuild) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg) | 从内存缓冲区加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。 |
| [OH_AI_TrainModelBuildFromFile](_mind_spore.md#oh_ai_trainmodelbuildfromfile) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg) | 根据路径读取加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。 |
| [OH_AI_RunStep](_mind_spore.md#oh_ai_runstep) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) after) | 单步训练模型，仅用于端侧训练。 |
| [OH_AI_ModelSetLearningRate](_mind_spore.md#oh_ai_modelsetlearningrate) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, float learning_rate) | 设置训练的学习率，仅用于端侧训练。 |
| [OH_AI_ModelGetLearningRate](_mind_spore.md#oh_ai_modelgetlearningrate) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | 获取训练的学习率，仅用于端侧训练。 |
| [OH_AI_ModelGetWeights](_mind_spore.md#oh_ai_modelgetweights) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | 获取模型的所有权重Tensors，仅用于端侧训练。 |
| [OH_AI_ModelUpdateWeights](_mind_spore.md#oh_ai_modelupdateweights) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) new_weights) | 更新模型的权重Tensor内容，仅用于端侧训练。 |
| [OH_AI_ModelGetTrainMode](_mind_spore.md#oh_ai_modelgettrainmode) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | 获取训练模式。 |
| [OH_AI_ModelSetTrainMode](_mind_spore.md#oh_ai_modelsettrainmode) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, bool train) | 设置训练模式，仅用于端侧训练。 |
| [OH_AI_ModelSetupVirtualBatch](_mind_spore.md#oh_ai_modelsetupvirtualbatch) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, int virtual_batch_multiplier, float lr, float momentum) | 设置虚拟batch用于训练，仅用于端侧训练。 |
| [OH_AI_ExportModel](_mind_spore.md#oh_ai_exportmodel) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const char \*model_file, [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | 导出训练模型，仅用于端侧训练。 |
| [OH_AI_ExportModelBuffer](_mind_spore.md#oh_ai_exportmodelbuffer) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, void \*model_data, size_t \*data_size, [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | 导出训练模型内存缓存，仅用于端侧训练。 |
| [OH_AI_ExportWeightsCollaborateWithMicro](_mind_spore.md#oh_ai_exportweightscollaboratewithmicro) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const char \*weight_file, bool is_inference, bool enable_fp16, char \*\*changeable_weights_name, size_t num) | 导出模型权重，只能用于micro推理，仅用于端侧训练。 |
