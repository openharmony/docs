# model.h


## Overview

Provides model-related APIs for model creation and inference. These APIs are non-thread-safe.

**Library**: libmindspore_lite_ndk.so

**Since**: 9

**Related module**: [MindSpore](_mind_spore.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.|
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **OH_AI_MAX_SHAPE_NUM**.|
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | Defines the operator information passed in a callback.|


### Macros

| Name| Description|
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](_mind_spore.md#oh_ai_max_shape_num) 32 | Defines the maximum tensor dimension.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) | Defines the pointer to a model object.|
| [OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) | Defines the pointer to a training configuration object.|
| [OH_AI_TensorHandleArray](_mind_spore.md#oh_ai_tensorhandlearray) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.|
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **OH_AI_MAX_SHAPE_NUM**.|
| [OH_AI_CallBackParam](_mind_spore.md#oh_ai_callbackparam) | Defines the operator information passed in a callback.|
| [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback)) (const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) outputs, const [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) kernel_Info) | Defines the pointer to a callback.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AI_ModelCreate](_mind_spore.md#oh_ai_modelcreate) (void) | Creates a model object.|
| [OH_AI_ModelDestroy](_mind_spore.md#oh_ai_modeldestroy) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) \*model) | Destroys a model object.|
| [OH_AI_ModelBuild](_mind_spore.md#oh_ai_modelbuild) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context) | Loads and builds a MindSpore model from the memory buffer.|
| [OH_AI_ModelBuildFromFile](_mind_spore.md#oh_ai_modelbuildfromfile) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context) | Loads and builds a MindSpore model from a model file.|
| [OH_AI_ModelResize](_mind_spore.md#oh_ai_modelresize) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) \*shape_infos, size_t shape_info_num) | Adjusts the input tensor shapes of a built model.|
| [OH_AI_ModelPredict](_mind_spore.md#oh_ai_modelpredict) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) \*outputs, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) after) | Performs model inference.|
| [OH_AI_ModelGetInputs](_mind_spore.md#oh_ai_modelgetinputs) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains the input tensor array structure of a model.|
| [OH_AI_ModelGetOutputs](_mind_spore.md#oh_ai_modelgetoutputs) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains the output tensor array structure of a model.|
| [OH_AI_ModelGetInputByTensorName](_mind_spore.md#oh_ai_modelgetinputbytensorname) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*tensor_name) | Obtains the input tensor of a model by tensor name.|
| [OH_AI_ModelGetOutputByTensorName](_mind_spore.md#oh_ai_modelgetoutputbytensorname) (const [OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*tensor_name) | Obtains the output tensor of a model by tensor name.|
| [OH_AI_TrainCfgCreate](_mind_spore.md#oh_ai_traincfgcreate) () | Creates the pointer to the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainCfgDestroy](_mind_spore.md#oh_ai_traincfgdestroy) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) \*train_cfg) | Destroys the pointer to the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainCfgGetLossName](_mind_spore.md#oh_ai_traincfggetlossname) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg, size_t \*num) | Obtains the list of loss functions, which are used only for on-device training.|
| [OH_AI_TrainCfgSetLossName](_mind_spore.md#oh_ai_traincfgsetlossname) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg, const char \*\*loss_name, size_t num) | Sets the list of loss functions, which are used only for on-device training.|
| [OH_AI_TrainCfgGetOptimizationLevel](_mind_spore.md#oh_ai_traincfggetoptimizationlevel) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg) | Obtains the optimization level of the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainCfgSetOptimizationLevel](_mind_spore.md#oh_ai_traincfgsetoptimizationlevel) ([OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg, [OH_AI_OptimizationLevel](_mind_spore.md#oh_ai_optimizationlevel) level) | Sets the optimization level of the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainModelBuild](_mind_spore.md#oh_ai_trainmodelbuild) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg) | Loads a training model from the memory buffer and compiles the model to a state ready for running on the device. This API is used only for on-device training.|
| [OH_AI_TrainModelBuildFromFile](_mind_spore.md#oh_ai_trainmodelbuildfromfile) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](_mind_spore.md#oh_ai_traincfghandle) train_cfg) | Loads the training model from the specified path and compiles the model to a state ready for running on the device. This API is used only for on-device training.|
| [OH_AI_RunStep](_mind_spore.md#oh_ai_runstep) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](_mind_spore.md#oh_ai_kernelcallback) after) | Defines a single-step training model. This API is used only for on-device training.|
| [OH_AI_ModelSetLearningRate](_mind_spore.md#oh_ai_modelsetlearningrate) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, float learning_rate) | Sets the learning rate for model training. This API is used only for on-device training.|
| [OH_AI_ModelGetLearningRate](_mind_spore.md#oh_ai_modelgetlearningrate) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains the learning rate for model training. This API is used only for on-device training.|
| [OH_AI_ModelGetWeights](_mind_spore.md#oh_ai_modelgetweights) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains all weight tensors of a model. This API is used only for on-device training.|
| [OH_AI_ModelUpdateWeights](_mind_spore.md#oh_ai_modelupdateweights) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) new_weights) | Updates the weight tensors of a model. This API is used only for on-device training.|
| [OH_AI_ModelGetTrainMode](_mind_spore.md#oh_ai_modelgettrainmode) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model) | Obtains the training mode.|
| [OH_AI_ModelSetTrainMode](_mind_spore.md#oh_ai_modelsettrainmode) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, bool train) | Sets the training mode. This API is used only for on-device training.|
| [OH_AI_ModelSetupVirtualBatch](_mind_spore.md#oh_ai_modelsetupvirtualbatch) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, int virtual_batch_multiplier, float lr, float momentum) | Sets the virtual batch for training. This API is used only for on-device training.|
| [OH_AI_ExportModel](_mind_spore.md#oh_ai_exportmodel) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const char \*model_file, [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | Exports a training model. This API is used only for on-device training.|
| [OH_AI_ExportModelBuffer](_mind_spore.md#oh_ai_exportmodelbuffer) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, void \*model_data, size_t \*data_size, [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | Exports the memory cache of the training model. This API is used only for on-device training.|
| [OH_AI_ExportWeightsCollaborateWithMicro](_mind_spore.md#oh_ai_exportweightscollaboratewithmicro) ([OH_AI_ModelHandle](_mind_spore.md#oh_ai_modelhandle) model, [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) model_type, const char \*weight_file, bool is_inference, bool enable_fp16, char \*\*changeable_weights_name, size_t num) | Exports the weight file of the training model for micro inference. This API is used only for on-device training.|
