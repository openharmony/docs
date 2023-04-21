# model.h


## Overview

Provides model-related APIs for model creation and inference.

**Since:**
9

**Related Modules:**

[MindSpore](_mind_spore.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.  | 
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**. | 
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | Defines the operator information passed in a callback.  | 


### Macros

| Name | Description | 
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](_mind_spore.md#oh_ai_max_shape_num)   32 | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) | Defines the pointer to a model object.  | 
| [OH_AI_TensorHandleArray](_mind_spore.md#oh_ai_tensorhandlearray) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.  | 
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**. | 
| [OH_AI_CallBackParam](_mind_spore.md#oh_ai_callbackparam) | Defines the operator information passed in a callback.  | 
| [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback)) (const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) outputs, const [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) kernel_Info) | Defines the pointer to a callback.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_AI_ModelCreate](_mind_spore.md#oh_ai_modelcreate) () | Creates a model object.  | 
| [OH_AI_ModelDestroy](_mind_spore.md#oh_ai_modeldestroy) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) \*model) | Destroys a model object.  | 
| [OH_AI_ModelBuild](_mind_spore.md#oh_ai_modelbuild) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context) | Loads and builds a MindSpore model from the memory buffer.  | 
| [OH_AI_ModelBuildFromFile](_mind_spore.md#oh_ai_modelbuildfromfile) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context) | Loads and builds a MindSpore model from a model file.  | 
| [OH_AI_ModelResize](_mind_spore.md#oh_ai_modelresize) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) \*shape_infos, size_t shape_info_num) | Adjusts the input tensor shapes of a built model.  | 
| [OH_AI_ModelPredict](_mind_spore.md#oh_ai_modelpredict) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) \*outputs, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) after) | Performs model inference.  | 
| [OH_AI_ModelGetInputs](_mind_spore.md#oh_ai_modelgetinputs) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains the input tensor array structure of a model.  | 
| [OH_AI_ModelGetOutputs](_mind_spore.md#oh_ai_modelgetoutputs) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains the output tensor array structure of a model.  | 
| [OH_AI_ModelGetInputByTensorName](_mind_spore.md#oh_ai_modelgetinputbytensorname) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*tensor_name) | Obtains the input tensor of a model by tensor name.  | 
| [OH_AI_ModelGetOutputByTensorName](_mind_spore.md#oh_ai_modelgetoutputbytensorname) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*tensor_name) | Obtains the output tensor of a model by tensor name.  | 
