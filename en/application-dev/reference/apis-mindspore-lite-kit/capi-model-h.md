# model.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Provides model-related APIs for model creation and inference. These APIs are non-thread-safe.

**File to include**: <mindspore/model.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Structs

| Name                                                                  | Description                             |
|----------------------------------------------------------------------|---------------------------------|
| [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.     |
| [OH_AI_ShapeInfo](capi-mindspore-oh-ai-shapeinfo.md)                 | Maximum number of shapes. The maximum value reserved is **32**, and the maximum number currently supported is **8**.|
| [OH_AI_CallBackParam](capi-mindspore-oh-ai-callbackparam.md)         | Defines the operator information passed in a callback.                  |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md)                                                | Defines the pointer to a model object.                               |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md)                                             | Defines the pointer to a training configuration object.                               |

### Functions

| Name| typedef Keyword| Description                                                                                                                                                                                                                                                 |
| -- | -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [typedef bool (\*OH_AI_KernelCallBack)(const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs,const OH_AI_CallBackParam kernel_Info)](#oh_ai_kernelcallback) | OH_AI_KernelCallBack | Defines the pointer to a callback.<br> This pointer is used to set the two callback functions in [OH_AI_ModelPredict](capi-model-h.md#oh_ai_modelpredict).<br> Each callback function must contain three parameters, where **inputs** and **outputs** indicate the input and output tensors of the operator, and **kernel_Info** indicates information about the current operator.<br> You can use the callback functions to monitor the operator execution status, for example, operator execution time and the operator correctness.                                 |
| [OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate(void)](#oh_ai_modelcreate) | - | Creates a model object.                                                                                                                                                                                                                                          |
| [OH_AI_API void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)](#oh_ai_modeldestroy) | - | Destroys a model object.                                                                                                                                                                                                                                          |
| [OH_AI_API OH_AI_Status OH_AI_ModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)](#oh_ai_modelbuild) | - | Loads and builds a MindSpore model from the memory buffer.<br> Note that the same [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) object can only be passed to [OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild) or [OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile) once. If you call this function multiple times, make sure that you create multiple [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) objects accordingly.|
| [OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)](#oh_ai_modelbuildfromfile) | - | Loads and builds a MindSpore model from a model file.<br> Note that the same [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) object can only be passed to [OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild) or [OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile) once. If you call this function multiple times, make sure that you create multiple [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) objects accordingly.    |
| [OH_AI_API OH_AI_Status OH_AI_ModelResize(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_ShapeInfo *shape_infos, size_t shape_info_num)](#oh_ai_modelresize) | - | Adjusts the input tensor shapes of a built model.                                                                                                                                                                                                                                      |
| [OH_AI_API OH_AI_Status OH_AI_ModelPredict(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_TensorHandleArray *outputs, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)](#oh_ai_modelpredict) | - | Performs model inference.                                                                                                                                                                                                                                            |
| [OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs(const OH_AI_ModelHandle model)](#oh_ai_modelgetinputs) | - | Obtains the input tensor array structure of a model.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs(const OH_AI_ModelHandle model)](#oh_ai_modelgetoutputs) | - | Obtains the output tensor array structure of a model.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)](#oh_ai_modelgetinputbytensorname) | - | Obtains the input tensor of a model by tensor name.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)](#oh_ai_modelgetoutputbytensorname) | - | Obtains the output tensor of a model by tensor name.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate()](#oh_ai_traincfgcreate) | - | Creates the pointer to the training configuration object. This API is used only for on-device training.                                                                                                                                                                                                                                |
| [OH_AI_API void OH_AI_TrainCfgDestroy(OH_AI_TrainCfgHandle *train_cfg)](#oh_ai_traincfgdestroy) | - | Destroys the pointer to the training configuration object. This API is used only for on-device training.                                                                                                                                                                                                                                |
| [OH_AI_API char **OH_AI_TrainCfgGetLossName(OH_AI_TrainCfgHandle train_cfg, size_t *num)](#oh_ai_traincfggetlossname) | - | Obtains the list of loss functions, which are used only for on-device training.                                                                                                                                                                                                                               |
| [OH_AI_API void OH_AI_TrainCfgSetLossName(OH_AI_TrainCfgHandle train_cfg, const char **loss_name, size_t num)](#oh_ai_traincfgsetlossname) | - | Sets the list of loss functions, which are used only for on-device training.                                                                                                                                                                                                                               |
| [OH_AI_API OH_AI_OptimizationLevel OH_AI_TrainCfgGetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg)](#oh_ai_traincfggetoptimizationlevel) | - | Obtains the optimization level of the training configuration object. This API is used only for on-device training.                                                                                                                                                                                                                               |
| [OH_AI_API void OH_AI_TrainCfgSetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg, OH_AI_OptimizationLevel level)](#oh_ai_traincfgsetoptimizationlevel) | - | Sets the optimization level of the training configuration object. This API is used only for on-device training.                                                                                                                                                                                                                               |
| [OH_AI_API OH_AI_Status OH_AI_TrainModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)](#oh_ai_trainmodelbuild) | - | Loads a training model from the memory buffer and compiles the model to a state ready for running on the device. This API is used only for on-device training.                                                                                                                                                                                                        |
| [OH_AI_API OH_AI_Status OH_AI_TrainModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type,const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)](#oh_ai_trainmodelbuildfromfile) | - | Loads the training model from the specified path and compiles the model to a state ready for running on the device. This API is used only for on-device training.                                                                                                                                                                                                        |
| [OH_AI_API OH_AI_Status OH_AI_RunStep(OH_AI_ModelHandle model, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)](#oh_ai_runstep) | - | Defines a single-step training model. This API is used only for on-device training.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_Status OH_AI_ModelSetLearningRate(OH_AI_ModelHandle model, float learning_rate)](#oh_ai_modelsetlearningrate) | - | Sets the learning rate for model training. This API is used only for on-device training.                                                                                                                                                                                                                                  |
| [OH_AI_API float OH_AI_ModelGetLearningRate(OH_AI_ModelHandle model)](#oh_ai_modelgetlearningrate) | - | Obtains the learning rate for model training. This API is used only for on-device training.                                                                                                                                                                                                                                  |
| [OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetWeights(OH_AI_ModelHandle model)](#oh_ai_modelgetweights) | - | Obtains all weight tensors of a model. This API is used only for on-device training.                                                                                                                                                                                                                          |
| [OH_AI_API OH_AI_Status OH_AI_ModelUpdateWeights(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray new_weights)](#oh_ai_modelupdateweights) | - | Updates the weight tensors of a model. This API is used only for on-device training.                                                                                                                                                                                                                           |
| [OH_AI_API bool OH_AI_ModelGetTrainMode(OH_AI_ModelHandle model)](#oh_ai_modelgettrainmode) | - | Obtains the training mode.                                                                                                                                                                                                                                            |
| [OH_AI_API OH_AI_Status OH_AI_ModelSetTrainMode(OH_AI_ModelHandle model, bool train)](#oh_ai_modelsettrainmode) | - | Sets the training mode. This API is used only for on-device training.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_Status OH_AI_ModelSetupVirtualBatch(OH_AI_ModelHandle model, int virtual_batch_multiplier, float lr,float momentum)](#oh_ai_modelsetupvirtualbatch) | - | Sets the virtual batch for training. This API is used only for on-device training.                                                                                                                                                                                                                             |
| [OH_AI_API OH_AI_Status OH_AI_ExportModel(OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char *model_file,OH_AI_QuantizationType quantization_type, bool export_inference_only,char **output_tensor_name, size_t num)](#oh_ai_exportmodel) | - | Exports a training model. This API is used only for on-device training.                                                                                                                                                                                                                                    |
| [OH_AI_API OH_AI_Status OH_AI_ExportModelBuffer(OH_AI_ModelHandle model, OH_AI_ModelType model_type, void *model_data,size_t *data_size, OH_AI_QuantizationType quantization_type,bool export_inference_only, char **output_tensor_name, size_t num)](#oh_ai_exportmodelbuffer) | - | Exports the memory cache of the training model. This API is used only for on-device training.                                                                                                                                                                                                                                |
| [OH_AI_API OH_AI_Status OH_AI_ExportWeightsCollaborateWithMicro(OH_AI_ModelHandle model, OH_AI_ModelType model_type,const char *weight_file, bool is_inference,bool enable_fp16, char **changeable_weights_name,size_t num)](#oh_ai_exportweightscollaboratewithmicro) | - | Exports the weight file of the training model for micro inference. This API is used only for on-device training.                                                                                                                                                                                                                        |
| [OH_AI_API OH_AI_Status OH_AI_ModelLoadConfig(OH_AI_ModelHandle model, const char *config_path)](#oh_ai_modelloadconfig) | - | Loads the model configuration file.|

## Function Description

### OH_AI_KernelCallBack()

```
typedef bool (*OH_AI_KernelCallBack)(const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs,const OH_AI_CallBackParam kernel_Info)
```

**Description**

Defines the pointer to a callback.<br>This pointer is used to set the two callback functions in [OH_AI_ModelPredict](capi-model-h.md#oh_ai_modelpredict).<br>Each callback function must contain three parameters, where **inputs** and **outputs** indicate the input and output tensors of the operator, and **kernel_Info** indicates information about the current operator.<br>You can use the callback functions to monitor the operator execution status, for example, operator execution time and the operator correctness.

**Since**: 9


**Parameters**

| Name                                                                               | Description     |
|------------------------------------------------------------------------------------|---------|
| const [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) inputs  | Tensor array structure corresponding to the model input.|
| const [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) outputs | Tensor array structure corresponding to the model output.       |
| const [OH_AI_CallBackParam](capi-mindspore-oh-ai-callbackparam.md) kernel_Info   | Information about the current operator.       |

**Returns**

| Type  | Description|
|------|----|
| bool | **true** if the operation is successful; **false** otherwise.|

### OH_AI_ModelCreate()

```
OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate(void)
```

**Description**

Creates a model object.

**Since**: 9

**Returns**

| Type                             | Description|
|---------------------------------| -- |
| OH_AI_API [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) | Pointer to the model object.|

### OH_AI_ModelDestroy()

```
OH_AI_API void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)
```

**Description**

Destroys a model object.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) *model | Pointer to the model object.|

### OH_AI_ModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)
```

**Description**

Loads and builds a MindSpore model from the memory buffer.<br>Note that the same [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) object can only be passed to [OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild) or [OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile) once. If you call this function multiple times, make sure that you create multiple [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) objects accordingly.

**Since**: 9


**Parameters**

| Name| Description                                                                           |
| -- |-------------------------------------------------------------------------------|
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.                                                                      |
| const void *model_data | Address of the loaded model data in the memory.                                                              |
| size_t data_size | Length of the model data.                                                                     |
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).                |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md).|

**Returns**

| Type| Description                                                                                                |
| -- |----------------------------------------------------------------------------------------------------|
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)
```

**Description**

Loads and builds a MindSpore model from a model file.<br>Note that the same [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) object can only be passed to [OH_AI_ModelBuild](capi-model-h.md#oh_ai_modelbuild) or [OH_AI_ModelBuildFromFile](capi-model-h.md#oh_ai_modelbuildfromfile) once. If you call this function multiple times, make sure that you create multiple [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) objects accordingly.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| const char *model_path | Path of the model file.|
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).|
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md).|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelResize()

```
OH_AI_API OH_AI_Status OH_AI_ModelResize(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_ShapeInfo *shape_infos, size_t shape_info_num)
```

**Description**

Adjusts the input tensor shapes of a built model.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| [const OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) inputs | Tensor array structure corresponding to the model input.|
| [OH_AI_ShapeInfo](capi-mindspore-oh-ai-shapeinfo.md) *shape_infos | Input shape information array, which consists of tensor shapes arranged in the model input sequence. The model adjusts the tensor shapes in sequence.|
| size_t shape_info_num | Length of the shape information array.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelPredict()

```
OH_AI_API OH_AI_Status OH_AI_ModelPredict(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs,OH_AI_TensorHandleArray *outputs, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)
```

**Description**

Performs model inference.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| [const OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) inputs | Tensor array structure corresponding to the model input.|
| [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) *outputs | Pointer to the tensor array structure corresponding to the model output.|
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) before | Callback function executed before model inference.|
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) after | Callback function executed after model inference.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelGetInputs()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs(const OH_AI_ModelHandle model)
```

**Description**

Obtains the input tensor array structure of a model.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|

**Returns**

| Type                                   | Description|
|---------------------------------------| -- |
| OH_AI_API [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | Tensor array structure corresponding to the model input.|

### OH_AI_ModelGetOutputs()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs(const OH_AI_ModelHandle model)
```

**Description**

Obtains the output tensor array structure of a model.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | Tensor array structure corresponding to the model output.|

### OH_AI_ModelGetInputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)
```

**Description**

Obtains the input tensor of a model by tensor name.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| const char *tensor_name | Tensor name.|

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| OH_AI_API [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | Pointer to the input tensor indicated by **tensor_name**. If the tensor does not exist, **null** will be returned.|

### OH_AI_ModelGetOutputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName(const OH_AI_ModelHandle model, const char *tensor_name)
```

**Description**

Obtains the output tensor of a model by tensor name.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| const char *tensor_name | Tensor name.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_TensorHandle](capi-mindspore-oh-ai-tensorHandle.md) | Pointer to the input tensor indicated by **tensor_name**. If the tensor does not exist, **null** will be returned.|

### OH_AI_TrainCfgCreate()

```
OH_AI_API OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate()
```

**Description**

Creates the pointer to the training configuration object. This API is used only for on-device training.

**Since**: 11

**Returns**

| Type                                | Description|
|------------------------------------| -- |
| OH_AI_API [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) | Pointer to the training configuration object.|

### OH_AI_TrainCfgDestroy()

```
OH_AI_API void OH_AI_TrainCfgDestroy(OH_AI_TrainCfgHandle *train_cfg)
```

**Description**

Destroys the pointer to the training configuration object. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name                                | Description|
|-------------------------------------| -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) *train_cfg | Pointer to the training configuration object.|

### OH_AI_TrainCfgGetLossName()

```
OH_AI_API char **OH_AI_TrainCfgGetLossName(OH_AI_TrainCfgHandle train_cfg, size_t *num)
```

**Description**

Obtains the list of loss functions, which are used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | Pointer to the training configuration object.|
| size_t *num | Number of loss functions.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API char ** | List of loss functions.|

### OH_AI_TrainCfgSetLossName()

```
OH_AI_API void OH_AI_TrainCfgSetLossName(OH_AI_TrainCfgHandle train_cfg, const char **loss_name, size_t num)
```

**Description**

Sets the list of loss functions, which are used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | Pointer to the training configuration object.|
| const char **loss_name | List of loss functions.|
| size_t num | Number of loss functions.|

### OH_AI_TrainCfgGetOptimizationLevel()

```
OH_AI_API OH_AI_OptimizationLevel OH_AI_TrainCfgGetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg)
```

**Description**

Obtains the optimization level of the training configuration object. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | Pointer to the training configuration object.|

**Returns**

| Type                                                                          | Description|
|------------------------------------------------------------------------------| -- |
| OH_AI_API [OH_AI_OptimizationLevel](capi-types-h.md#oh_ai_optimizationlevel) | Optimization level.|

### OH_AI_TrainCfgSetOptimizationLevel()

```
OH_AI_API void OH_AI_TrainCfgSetOptimizationLevel(OH_AI_TrainCfgHandle train_cfg, OH_AI_OptimizationLevel level)
```

**Description**

Sets the optimization level of the training configuration object. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | Pointer to the training configuration object.|
| [OH_AI_OptimizationLevel](capi-types-h.md#oh_ai_optimizationlevel) level | Optimization level.|

### OH_AI_TrainModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuild(OH_AI_ModelHandle model, const void *model_data, size_t data_size,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)
```

**Description**

Loads a training model from the memory buffer and compiles the model to a state ready for running on the device. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| const void *model_data | Pointer to the buffer that stores the model file to be read.|
| size_t data_size | Buffer size.|
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).|
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md).|
| const [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | Pointer to the training configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_TrainModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type,const OH_AI_ContextHandle model_context,const OH_AI_TrainCfgHandle train_cfg)
```

**Description**

Loads the training model from the specified path and compiles the model to a state ready for running on the device. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| const char *model_path | Path of the model file.|
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).|
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md).|
| const [OH_AI_TrainCfgHandle](capi-mindspore-oh-ai-traincfghandle.md) train_cfg | Pointer to the training configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_RunStep()

```
OH_AI_API OH_AI_Status OH_AI_RunStep(OH_AI_ModelHandle model, const OH_AI_KernelCallBack before,const OH_AI_KernelCallBack after)
```

**Description**

Defines a single-step training model. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) before | Callback function executed before model inference.|
| [const OH_AI_KernelCallBack](capi-model-h.md#oh_ai_kernelcallback) after | Callback function executed after model inference.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelSetLearningRate()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetLearningRate(OH_AI_ModelHandle model, float learning_rate)
```

**Description**

Sets the learning rate for model training. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| float learning_rate | Learning rate.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelGetLearningRate()

```
OH_AI_API float OH_AI_ModelGetLearningRate(OH_AI_ModelHandle model)
```

**Description**

Obtains the learning rate for model training. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API float | Learning rate. If no optimizer is set, the value is **0.0**.|

### OH_AI_ModelGetWeights()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetWeights(OH_AI_ModelHandle model)
```

**Description**

Obtains all weight tensors of a model. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) | All weight tensors of the model.|

### OH_AI_ModelUpdateWeights()

```
OH_AI_API OH_AI_Status OH_AI_ModelUpdateWeights(OH_AI_ModelHandle model, const OH_AI_TensorHandleArray new_weights)
```

**Description**

Updates the weight tensors of a model. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| [const OH_AI_TensorHandleArray](capi-mindspore-oh-ai-tensorhandlearray.md) new_weights | Weight tensors to be updated.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelGetTrainMode()

```
OH_AI_API bool OH_AI_ModelGetTrainMode(OH_AI_ModelHandle model)
```

**Description**

Obtains the training mode.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API bool | Whether the training mode is used.|

### OH_AI_ModelSetTrainMode()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetTrainMode(OH_AI_ModelHandle model, bool train)
```

**Description**

Sets the training mode. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| bool train | Whether the training mode is used.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelSetupVirtualBatch()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetupVirtualBatch(OH_AI_ModelHandle model, int virtual_batch_multiplier, float lr,float momentum)
```

**Description**

Sets the virtual batch for training. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| int virtual_batch_multiplier | Virtual batch multiplier. If the value is less than **1**, the virtual batch is disabled.|
| float lr | Learning rate. The default value is **-1.0f**.|
| float momentum | Momentum. The default value is **-1.0f**.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ExportModel()

```
OH_AI_API OH_AI_Status OH_AI_ExportModel(OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char *model_file,OH_AI_QuantizationType quantization_type, bool export_inference_only,char **output_tensor_name, size_t num)
```

**Description**

Exports a training model. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model                     | Pointer to the model object.|
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type                      | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).|
| const char *model_file                                                             | Path of the exported model file.|
| [OH_AI_QuantizationType](capi-types-h.md#oh_ai_quantizationtype) quantization_type | Quantization type.|
| bool export_inference_only                                                         | Whether to export an inference model.|
| char **output_tensor_name                                                          | Output tensor of the exported model. This parameter is left blank by default, which indicates full export.|
| size_t num                                                                         | Number of output tensors.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ExportModelBuffer()

```
OH_AI_API OH_AI_Status OH_AI_ExportModelBuffer(OH_AI_ModelHandle model, OH_AI_ModelType model_type, void *model_data,size_t *data_size, OH_AI_QuantizationType quantization_type,bool export_inference_only, char **output_tensor_name, size_t num)
```

**Description**

Exports the memory cache of the training model. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).|
| void *model_data | Pointer to the buffer that stores the exported model file.|
| size_t *data_size | Buffer size.|
| [OH_AI_QuantizationType](capi-types-h.md#oh_ai_quantizationtype) quantization_type | Quantization type.|
| bool export_inference_only | Whether to export an inference model.|
| char **output_tensor_name | Output tensor of the exported model. This parameter is left blank by default, which indicates full export.|
| size_t num | Number of output tensors.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ExportWeightsCollaborateWithMicro()

```
OH_AI_API OH_AI_Status OH_AI_ExportWeightsCollaborateWithMicro(OH_AI_ModelHandle model, OH_AI_ModelType model_type,const char *weight_file, bool is_inference,bool enable_fp16, char **changeable_weights_name,size_t num)
```

**Description**

Exports the weight file of the training model for micro inference. This API is used only for on-device training.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype) model_type | Model file type, which is specified by [OH_AI_ModelType](capi-types-h.md#oh_ai_modeltype).|
| const char *weight_file | Path of the exported weight file.|
| bool is_inference | Whether to export inference models. Currently, this parameter can only be set to **true**.|
| bool enable_fp16 | Whether to save floating-point weights in float16 format.|
| char **changeable_weights_name | Name of the weight tensor with a variable shape.|
| size_t num | Number of weight tensors with a variable shape.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|

### OH_AI_ModelLoadConfig()

```
OH_AI_API OH_AI_Status OH_AI_ModelLoadConfig(OH_AI_ModelHandle model, const char *config_path);
```

**Description**

Loads the model configuration file.

**Since**: 20

**Parameters**

| Name                                                      | Description          |
| ------------------------------------------------------------ | -------------- |
| [OH_AI_ModelHandle](capi-mindspore-oh-ai-modelhandle.md) model | Pointer to the model object.|
| const char *config_path                                      | Configuration file path.|

**Returns**

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|
