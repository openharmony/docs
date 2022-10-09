# model.h


## 概述

提供了模型相关接口，可以用于模型创建、模型推理等。

**自从：**

9

**相关模块：**

[MindSpore](_mind_spore.md)


## 汇总


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | 张量数组结构体，用于存储张量数组指针和张量数组长度 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM** |
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | 回调函数中传入的算子信息。 |


### 宏定义

| 宏定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](_mind_spore.md#oh_ai_max_shape_num)   32 | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM**。 |


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) | 指向模型对象的指针。 |
| [OH_AI_TensorHandleArray](_mind_spore.md#oh_ai_tensorhandlearray) | 张量数组结构体，用于存储张量数组指针和张量数组长度 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM** |
| [OH_AI_CallBackParam](_mind_spore.md#oh_ai_callbackparam) | 回调函数中传入的算子信息。 |
| [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback)) (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info) | 回调函数指针。 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelCreate](_mind_spore.md#oh_ai_modelcreate) () | 创建一个模型对象。 |
| [OH_AI_ModelDestroy](_mind_spore.md#oh_ai_modeldestroy) (OH_AI_ModelHandle \*model) | 释放一个模型对象。 |
| [OH_AI_ModelBuild](_mind_spore.md#oh_ai_modelbuild) (OH_AI_ModelHandle model, const void \*model_data, <br/>size_t data_size, OH_AI_ModelType model_type, <br/>const OH_AI_ContextHandle model_context) | 从内存缓冲区加载并编译MindSpore模型。 |
| [OH_AI_ModelBuildFromFile](_mind_spore.md#oh_ai_modelbuildfromfile) (OH_AI_ModelHandle model, <br/>const char \*model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context) | 通过模型文件加载并编译MindSpore模型。 |
| [OH_AI_ModelResize](_mind_spore.md#oh_ai_modelresize) (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,<br/> OH_AI_ShapeInfo \*shape_infos, size_t shape_info_num) | 调整已编译模型的输入形状。 |
| [OH_AI_ModelPredict](_mind_spore.md#oh_ai_modelpredict) (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray \*outputs, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after) | 执行模型推理。 |
| [OH_AI_ModelGetInputs](_mind_spore.md#oh_ai_modelgetinputs) (const OH_AI_ModelHandle model) | 获取模型的输入张量数组结构体。 |
| [OH_AI_ModelGetOutputs](_mind_spore.md#oh_ai_modelgetoutputs) (const OH_AI_ModelHandle model) | 获取模型的输出张量数组结构体。 |
| [OH_AI_ModelGetInputByTensorName](_mind_spore.md#oh_ai_modelgetinputbytensorname) (const OH_AI_ModelHandle model, const char \*tensor_name) | 通过张量名获取模型的输入张量。 |
| [OH_AI_ModelGetOutputByTensorName](_mind_spore.md#oh_ai_modelgetoutputbytensorname) (const OH_AI_ModelHandle model, const char \*tensor_name) | 通过张量名获取模型的输出张量。 |
