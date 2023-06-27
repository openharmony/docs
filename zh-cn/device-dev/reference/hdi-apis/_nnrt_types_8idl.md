# NnrtTypes.idl


## 概述

该文件定义了HDI接口中用到的类型。

**Since:**

3.2

**Version:**

2.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [SharedBuffer](_shared_buffer.md) | struct<br/>共享内存数据的结构体。 | 
| [ModelConfig](_model_config.md) | struct<br/>定义编译模型需要的参数配置。 | 
| [QuantParam](_quant_param.md) | struct<br/>量化参数结构体。 | 
| [IOTensor](_i_o_tensor.md) | struct<br/>AI模型的输入输出张量。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [DeviceType](_n_n_rt.md#devicetype)&nbsp;:&nbsp;int&nbsp;{&nbsp;OTHER&nbsp;,&nbsp;CPU&nbsp;,&nbsp;GPU&nbsp;,&nbsp;ACCELERATOR&nbsp;} | AI计算芯片的类型。 | 
| [DeviceStatus](_n_n_rt.md#devicestatus)&nbsp;:&nbsp;int&nbsp;{&nbsp;AVAILABLE&nbsp;,&nbsp;BUSY&nbsp;,&nbsp;OFFLINE&nbsp;,&nbsp;UNKNOWN&nbsp;} | 用于AI计算芯片的状态。 | 
| [PerformanceMode](_n_n_rt.md#performancemode)&nbsp;:&nbsp;int&nbsp;{PERFORMANCE_NONE&nbsp;,&nbsp;PERFORMANCE_LOW&nbsp;,&nbsp;PERFORMANCE_MEDIUM&nbsp;,&nbsp;PERFORMANCE_HIGH&nbsp;,PERFORMANCE_EXTREME<br/>} | 芯片执行AI计算的性能模式。 | 
| [Priority](_n_n_rt.md#priority)&nbsp;:&nbsp;int&nbsp;{&nbsp;PRIORITY_NONE&nbsp;,&nbsp;PRIORITY_LOW&nbsp;,&nbsp;PRIORITY_MEDIUM&nbsp;,&nbsp;PRIORITY_HIGH&nbsp;} | AI计算任务的优先级。 | 
| [Format](_n_n_rt.md#format)&nbsp;:&nbsp;byte&nbsp;{&nbsp;FORMAT_NONE&nbsp;=&nbsp;-1&nbsp;,&nbsp;FORMAT_NCHW&nbsp;=&nbsp;0&nbsp;,&nbsp;FORMAT_NHWC&nbsp;=&nbsp;1&nbsp;} | 算子数据排布。需要配合[Tensor](_tensor.md)使用。 | 
| [DataType](_n_n_rt.md#datatype)&nbsp;:&nbsp;byte&nbsp;{<br/>DATA_TYPE_UNKNOWN&nbsp;=&nbsp;0&nbsp;,&nbsp;DATA_TYPE_BOOL&nbsp;=&nbsp;30&nbsp;,&nbsp;DATA_TYPE_INT8&nbsp;=&nbsp;32&nbsp;,&nbsp;DATA_TYPE_INT16&nbsp;=&nbsp;33&nbsp;,&nbsp;DATA_TYPE_INT32&nbsp;=&nbsp;34&nbsp;,&nbsp;DATA_TYPE_INT64&nbsp;=&nbsp;35&nbsp;,&nbsp;DATA_TYPE_UINT8&nbsp;=&nbsp;37&nbsp;,&nbsp;DATA_TYPE_UINT16&nbsp;=&nbsp;38&nbsp;,&nbsp;DATA_TYPE_UINT32&nbsp;=&nbsp;39&nbsp;,&nbsp;DATA_TYPE_UINT64&nbsp;=&nbsp;40&nbsp;,&nbsp;DATA_TYPE_FLOAT16&nbsp;=&nbsp;42&nbsp;,&nbsp;DATA_TYPE_FLOAT32&nbsp;=&nbsp;43&nbsp;,DATA_TYPE_FLOAT64&nbsp;=&nbsp;44} | 张量的数据类型。需要配合[Tensor](_tensor.md)使用。 | 
| [QuantType](_n_n_rt.md#quanttype)&nbsp;:&nbsp;byte&nbsp;{&nbsp;QUANT_TYPE_NONE&nbsp;,&nbsp;QUANT_TYPE_ALL&nbsp;} | 量化类型。需要配合[Node](_node.md)使用。 | 
| [NodeType](_n_n_rt.md#nodetype)&nbsp;:&nbsp;unsigned&nbsp;int&nbsp;{<br/>NODE_TYPE_NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;NODE_TYPE_ACTIVATION&nbsp;=&nbsp;2&nbsp;,&nbsp;NODE_TYPE_ADD_FUSION&nbsp;=&nbsp;5&nbsp;,&nbsp;NODE_TYPE_ARGMAX_FUSION&nbsp;=&nbsp;11&nbsp;,&nbsp;NODE_TYPE_AVGPOOL_FUSION&nbsp;=&nbsp;17&nbsp;,&nbsp;NODE_TYPE_BATCH_TO_SPACE_ND&nbsp;=&nbsp;22&nbsp;,&nbsp;NODE_TYPE_BIAS_ADD&nbsp;=&nbsp;23&nbsp;,&nbsp;NODE_TYPE_CAST&nbsp;=&nbsp;28&nbsp;,<br/>NODE_TYPE_CONCAT&nbsp;=&nbsp;31&nbsp;,&nbsp;NODE_TYPE_CONV2D_FUSION&nbsp;=&nbsp;35&nbsp;,&nbsp;NODE_TYPE_CONV2D_TRANSPOSE_FUSION&nbsp;=&nbsp;36&nbsp;,&nbsp;NODE_TYPE_DIV_FUSION&nbsp;=&nbsp;47&nbsp;,&nbsp;NODE_TYPE_ELTWISE&nbsp;=&nbsp;52&nbsp;,&nbsp;NODE_TYPE_EXPAND_DIMS&nbsp;=&nbsp;56&nbsp;,&nbsp;NODE_TYPE_FILL&nbsp;=&nbsp;66&nbsp;,&nbsp;NODE_TYPE_FULL_CONNECTION&nbsp;=&nbsp;67&nbsp;,<br/>NODE_TYPE_FUSED_BATCH_NORM&nbsp;=&nbsp;68&nbsp;,&nbsp;NODE_TYPE_GATHER&nbsp;=&nbsp;69&nbsp;,&nbsp;NODE_TYPE_LAYER_NORM_FUSION&nbsp;=&nbsp;75&nbsp;,&nbsp;NODE_TYPE_LESS_EQUAL&nbsp;=&nbsp;78&nbsp;,<br/>NODE_TYPE_MATMUL_FUSION&nbsp;=&nbsp;89&nbsp;,&nbsp;NODE_TYPE_MAXIMUM&nbsp;=&nbsp;90&nbsp;,&nbsp;NODE_TYPE_MAX_POOL_FUSION&nbsp;=&nbsp;92&nbsp;,&nbsp;NODE_TYPE_MUL_FUSION&nbsp;=&nbsp;99&nbsp;,<br/>NODE_TYPE_ONE_HOT&nbsp;=&nbsp;105&nbsp;,&nbsp;NODE_TYPE_PAD_FUSION&nbsp;=&nbsp;107&nbsp;,&nbsp;NODE_TYPE_POW_FUSION&nbsp;=&nbsp;110&nbsp;,&nbsp;NODE_TYPE_PRELU_FUSION&nbsp;=&nbsp;112&nbsp;,<br/>NODE_TYPE_QUANT_DTYPE_CAST&nbsp;=&nbsp;113&nbsp;,&nbsp;NODE_TYPE_REDUCE_FUSION&nbsp;=&nbsp;118&nbsp;,&nbsp;NODE_TYPE_RESHAPE&nbsp;=&nbsp;119&nbsp;,&nbsp;NODE_TYPE_RESIZE&nbsp;=&nbsp;120&nbsp;,<br/>NODE_TYPE_RSQRT&nbsp;=&nbsp;126&nbsp;,&nbsp;NODE_TYPE_SCALE_FUSION&nbsp;=&nbsp;127&nbsp;,&nbsp;NODE_TYPE_SHAPE&nbsp;=&nbsp;130&nbsp;,&nbsp;NODE_TYPE_SLICE_FUSION&nbsp;=&nbsp;135&nbsp;,<br/>NODE_TYPE_SOFTMAX&nbsp;=&nbsp;138&nbsp;,&nbsp;NODE_TYPE_SPACE_TO_BATCH_ND&nbsp;=&nbsp;141&nbsp;,&nbsp;NODE_TYPE_SPLIT&nbsp;=&nbsp;145&nbsp;,&nbsp;NODE_TYPE_SQRT&nbsp;=&nbsp;146&nbsp;,<br/>NODE_TYPE_SQUEEZE&nbsp;=&nbsp;147&nbsp;,&nbsp;NODE_TYPE_SQUARED_DIFFERENCE&nbsp;=&nbsp;149&nbsp;,&nbsp;NODE_TYPE_STACK&nbsp;=&nbsp;150&nbsp;,&nbsp;NODE_TYPE_STRIDED_SLICE&nbsp;=&nbsp;151&nbsp;,<br/>NODE_TYPE_SUB_FUSION&nbsp;=&nbsp;152&nbsp;,&nbsp;NODE_TYPE_TILE_FUSION&nbsp;=&nbsp;160&nbsp;,&nbsp;NODE_TYPE_TOPK_FUSION&nbsp;=&nbsp;161&nbsp;,&nbsp;NODE_TYPE_TRANSPOSE&nbsp;=&nbsp;162&nbsp;,&nbsp;NODE_TYPE_UNSQUEEZE&nbsp;=&nbsp;165<br/>} | 算子类型。 | 
| [ResizeMethod](_n_n_rt.md#resizemethod)&nbsp;:&nbsp;byte&nbsp;{&nbsp;RESIZE_METHOD_UNKNOWN&nbsp;=&nbsp;-1&nbsp;,&nbsp;RESIZE_METHOD_LINEAR&nbsp;=&nbsp;0&nbsp;,&nbsp;RESIZE_METHOD_NEAREST&nbsp;=&nbsp;1&nbsp;,&nbsp;RESIZE_METHOD_CUBIC&nbsp;=&nbsp;2&nbsp;} | 调整尺寸的方法。需要配合[Resize](_resize.md)算子使用。 | 
| [CoordinateTransformMode](_n_n_rt.md#coordinatetransformmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;COORDINATE_TRANSFORM_MODE_ASYMMETRIC&nbsp;=&nbsp;0&nbsp;,&nbsp;COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS&nbsp;=&nbsp;1&nbsp;,&nbsp;COORDINATE_TRANSFORM_MODE_HALF_PIXEL&nbsp;=&nbsp;2&nbsp;} | 坐标变换模式，仅[Resize](_resize.md)算子使用这些枚举。 | 
| [NearestMode](_n_n_rt.md#nearestmode)&nbsp;:&nbsp;byte&nbsp;{<br/>NEAREST_MODE_NORMAL&nbsp;=&nbsp;0&nbsp;,&nbsp;NEAREST_MODE_ROUND_HALF_DOWN&nbsp;=&nbsp;1&nbsp;,&nbsp;NEAREST_MODE_ROUND_HALF_UP&nbsp;=&nbsp;2&nbsp;,&nbsp;NEAREST_MODE_FLOOR&nbsp;=&nbsp;3&nbsp;,&nbsp;NEAREST_MODE_CEIL&nbsp;=&nbsp;4<br/>} | 临近算法类型。需要配合[Resize](_resize.md)算子使用。 | 
| [ActivationType](_n_n_rt.md#activationtype)&nbsp;:&nbsp;byte&nbsp;{<br/>ACTIVATION_TYPE_NO_ACTIVATION&nbsp;=&nbsp;0&nbsp;,&nbsp;ACTIVATION_TYPE_RELU&nbsp;=&nbsp;1&nbsp;,&nbsp;ACTIVATION_TYPE_SIGMOID&nbsp;=&nbsp;2&nbsp;,&nbsp;ACTIVATION_TYPE_RELU6&nbsp;=&nbsp;3&nbsp;,<br/>ACTIVATION_TYPE_ELU&nbsp;=&nbsp;4&nbsp;,&nbsp;ACTIVATION_TYPE_LEAKY_RELU&nbsp;=&nbsp;5&nbsp;,&nbsp;ACTIVATION_TYPE_ABS&nbsp;=&nbsp;6&nbsp;,&nbsp;ACTIVATION_TYPE_RELU1&nbsp;=&nbsp;7&nbsp;,<br/>ACTIVATION_TYPE_SOFTSIGN&nbsp;=&nbsp;8&nbsp;,&nbsp;ACTIVATION_TYPE_SOFTPLUS&nbsp;=&nbsp;9&nbsp;,&nbsp;ACTIVATION_TYPE_TANH&nbsp;=&nbsp;10&nbsp;,&nbsp;ACTIVATION_TYPE_SELU&nbsp;=&nbsp;11&nbsp;,<br/>ACTIVATION_TYPE_HSWISH&nbsp;=&nbsp;12&nbsp;,&nbsp;ACTIVATION_TYPE_HSIGMOID&nbsp;=&nbsp;13&nbsp;,&nbsp;ACTIVATION_TYPE_THRESHOLDRELU&nbsp;=&nbsp;14&nbsp;,&nbsp;ACTIVATION_TYPE_LINEAR&nbsp;=&nbsp;15&nbsp;,&nbsp;ACTIVATION_TYPE_HARD_TANH&nbsp;=&nbsp;16&nbsp;,&nbsp;ACTIVATION_TYPE_SIGN&nbsp;=&nbsp;17&nbsp;,&nbsp;ACTIVATION_TYPE_SWISH&nbsp;=&nbsp;18&nbsp;,&nbsp;ACTIVATION_TYPE_GELU&nbsp;=&nbsp;19&nbsp;,<br/>ACTIVATION_TYPE_UNKNOWN&nbsp;=&nbsp;20} | 激活函数类型。 | 
| [ReduceMode](_n_n_rt.md#reducemode)&nbsp;:&nbsp;byte&nbsp;{<br/>REDUCE_MODE_MEAN&nbsp;=&nbsp;0&nbsp;,&nbsp;REDUCE_MODE_MAX&nbsp;=&nbsp;1&nbsp;,&nbsp;REDUCE_MODE_MIN&nbsp;=&nbsp;2&nbsp;,&nbsp;REDUCE_MODE_PROD&nbsp;=&nbsp;3&nbsp;,&nbsp;REDUCE_MODE_SUM&nbsp;=&nbsp;4&nbsp;,&nbsp;REDUCE_MODE_SUM_SQUARE&nbsp;=&nbsp;5&nbsp;,&nbsp;REDUCE_MODE_ASUM&nbsp;=&nbsp;6&nbsp;,&nbsp;REDUCE_MODE_ALL&nbsp;=&nbsp;7} | 用于维度移除的方法，需要配合[ReduceFusion](_reduce_fusion.md)算子使用。 | 
| [EltwiseMode](_n_n_rt.md#eltwisemode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;ELTWISE_MODE_PROD&nbsp;=&nbsp;0&nbsp;,&nbsp;ELTWISE_MODE_SUM&nbsp;=&nbsp;1&nbsp;,&nbsp;ELTWISE_MODE_MAXIMUM&nbsp;=&nbsp;2&nbsp;,&nbsp;ELTWISE_MODE_UNKNOWN&nbsp;=&nbsp;3&nbsp;} | 元素级别运算支持的计算类型，需要配合[Eltwise](_eltwise.md)算子使用。 | 
| [PadMode](_n_n_rt.md#padmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;PAD_MODE_PAD&nbsp;=&nbsp;0&nbsp;,&nbsp;PAD_MODE_SAME&nbsp;=&nbsp;1&nbsp;,&nbsp;PAD_MODE_VALID&nbsp;=&nbsp;2&nbsp;} | 填充类型，需要配合[AvgPoolFusion](_avg_pool_fusion.md)，[AvgPoolFusion](_avg_pool_fusion.md)，[Conv2DFusion](_conv2_d_fusion.md)，[MaxPoolFusion](_max_pool_fusion.md)使用。 | 
| [RoundMode](_n_n_rt.md#roundmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;ROUND_MODE_FLOOR&nbsp;=&nbsp;0&nbsp;,&nbsp;ROUND_MODE_CEIL&nbsp;=&nbsp;1&nbsp;} | 小数取整算法，需要配合[AvgPoolFusion](_avg_pool_fusion.md)算子使用。 | 
| [PaddingMode](_n_n_rt.md#paddingmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;PADDING_MODE_CONSTANT&nbsp;=&nbsp;0&nbsp;,&nbsp;PADDING_MODE_REFLECT&nbsp;=&nbsp;1&nbsp;,&nbsp;PADDING_MODE_SYMMETRIC&nbsp;=&nbsp;2&nbsp;,&nbsp;PADDING_MODE_RESERVED&nbsp;=&nbsp;3&nbsp;} | 填充类型，需要配合[PadFusion](_pad_fusion.md)算子使用。 | 
| [NNRT_ReturnCode](_n_n_rt.md#nnrt_returncode)&nbsp;:&nbsp;int&nbsp;{<br/>NNRT_SUCCESS&nbsp;=&nbsp;0&nbsp;,&nbsp;NNRT_FAILED&nbsp;=&nbsp;1&nbsp;,&nbsp;NNRT_NULL_PTR&nbsp;=&nbsp;2&nbsp;,&nbsp;NNRT_INVALID_PARAMETER&nbsp;=&nbsp;3&nbsp;,<br/>NNRT_MEMORY_ERROR&nbsp;=&nbsp;4&nbsp;,&nbsp;NNRT_OUT_OF_MEMORY&nbsp;=&nbsp;5&nbsp;,&nbsp;NNRT_OPERATION_FORBIDDEN&nbsp;=&nbsp;6&nbsp;,&nbsp;NNRT_INVALID_FILE&nbsp;=&nbsp;7&nbsp;,<br/>NNRT_INVALID_PATH&nbsp;=&nbsp;8&nbsp;,&nbsp;NNRT_INSUFFICIENT_BUFFER&nbsp;=&nbsp;9&nbsp;,&nbsp;NNRT_NO_CHANGE&nbsp;=&nbsp;10&nbsp;,&nbsp;NNRT_NOT_SUPPORT&nbsp;=&nbsp;11&nbsp;,<br/>NNRT_SERVICE_ERROR&nbsp;=&nbsp;12&nbsp;,&nbsp;NNRT_DEVICE_ERROR&nbsp;=&nbsp;13&nbsp;,&nbsp;NNRT_DEVICE_BUSY&nbsp;=&nbsp;14&nbsp;,&nbsp;NNRT_CANCELLED&nbsp;=&nbsp;15&nbsp;,<br/>NNRT_PERMISSION_DENIED&nbsp;=&nbsp;16&nbsp;,&nbsp;NNRT_TIME_OUT&nbsp;=&nbsp;17&nbsp;,&nbsp;NNRT_INVALID_TENSOR&nbsp;=&nbsp;18&nbsp;,&nbsp;NNRT_INVALID_NODE&nbsp;=&nbsp;19&nbsp;,<br/>NNRT_INVALID_INPUT&nbsp;=&nbsp;20&nbsp;,&nbsp;NNRT_INVALID_OUTPUT&nbsp;=&nbsp;21&nbsp;,&nbsp;NNRT_INVALID_DATATYPE&nbsp;=&nbsp;22&nbsp;,&nbsp;NNRT_INVALID_FORMAT&nbsp;=&nbsp;23&nbsp;,<br/>NNRT_INVALID_TENSOR_NAME&nbsp;=&nbsp;24&nbsp;,&nbsp;NNRT_INVALID_SHAPE&nbsp;=&nbsp;25&nbsp;,&nbsp;NNRT_OUT_OF_DIMENTION_RANGES&nbsp;=&nbsp;26&nbsp;,&nbsp;NNRT_INVALID_BUFFER&nbsp;=&nbsp;27&nbsp;,&nbsp;NNRT_INVALID_BUFFER_SIZE&nbsp;=&nbsp;28&nbsp;,&nbsp;NNRT_INVALID_PERFORMANCE_MODE&nbsp;=&nbsp;29&nbsp;,&nbsp;NNRT_INVALID_PRIORITY&nbsp;=&nbsp;30&nbsp;,&nbsp;NNRT_INVALID_MODEL&nbsp;=&nbsp;31&nbsp;,<br/>NNRT_INVALID_MODEL_CACHE&nbsp;=&nbsp;32&nbsp;,&nbsp;NNRT_UNSUPPORTED_OP&nbsp;=&nbsp;33<br/>} | NNRt定义的专用错误码，为HDI接口的返回值。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.nnrt.v2_0 | NNRt模块的包路径。 | 
