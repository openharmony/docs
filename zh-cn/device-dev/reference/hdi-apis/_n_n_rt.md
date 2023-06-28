# NNRt


## 概述

NNRt（Neural Network Runtime，神经网络运行时）是面向AI领域的跨芯片推理计算运行时，作为中间桥梁连通上层AI推理框架和底层加速芯片，实现AI模型的跨芯片推理计算。提供统一AI芯片驱动接口，实现AI芯片驱动接入OpenHarmony。

**Since:**

3.2

**Version:**

2.0


## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [INnrtDevice.idl](_i_nnrt_device_8idl.md) | 该文件定义芯片设备相关的接口。 | 
| [IPreparedModel.idl](_i_prepared_model_8idl.md) | 该文件定义了AI模型推理、获取模型输入tensor维度范围、导出编译后模型等接口。 | 
| [ModelTypes.idl](_model_types_8idl.md) | 该文件定义AI模型相关的结构体。 | 
| [NnrtTypes.idl](_nnrt_types_8idl.md) | 该文件定义了HDI接口中用到的类型。 | 
| [NodeAttrTypes.idl](_node_attr_types_8idl.md) | 该文件定义AI模型算子的参数和功能。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [INnrtDevice](interface_i_nnrt_device.md) | interface<br/>定义了与设备相关的接口，实现设备管理和模型编译等操作。 | 
| [IPreparedModel](interface_i_prepared_model.md) | interface<br/>定义模型编译后的对象，包含编译后模型导出、模型推理接口。 | 
| [Tensor](_tensor.md) | struct<br/>张量结构体。 | 
| [Node](_node.md) | struct<br/>算子节点结构体。 | 
| [SubGraph](_sub_graph.md) | struct<br/>子图结构体。 | 
| [Model](_model.md) | struct<br/>模型结构体。 | 
| [SharedBuffer](_shared_buffer.md) | struct<br/>共享内存数据的结构体。 | 
| [ModelConfig](_model_config.md) | struct<br/>定义编译模型需要的参数配置。 | 
| [QuantParam](_quant_param.md) | struct<br/>量化参数结构体。 | 
| [IOTensor](_i_o_tensor.md) | struct<br/>AI模型的输入输出张量。 | 
| [Activation](_activation.md) | struct<br/>激活类型的算子，所有的激活函数都属于该算子，具体的激活函数类型一句参数来确定。 | 
| [AddFusion](_add_fusion.md) | struct<br/>输入Tensor逐元素相加，&nbsp;输出x和y的和，数据形状与输入broadcast之后一样，数据类型与较高精度的输入精度一致。 | 
| [ArgMaxFusion](_arg_max_fusion.md) | struct<br/>返回跨轴的tensor前K个索引或者是数值。 | 
| [AvgPoolFusion](_avg_pool_fusion.md) | struct<br/>在输入tensor上应用&nbsp;2D&nbsp;平均池化。支持int8量化输入。 | 
| [BatchToSpaceND](_batch_to_space_n_d.md) | struct<br/>将一个4维tensor的batch维度按block_shape切分成小块，并将这些小块拼接到空间维度。 | 
| [BiasAdd](_bias_add.md) | struct<br/>对给出的输入张量上的各个维度方向上的数据进行偏置。 | 
| [Cast](_cast.md) | struct<br/>根据输出张量的类型对张量数据类型进行转换。 | 
| [Concat](_concat.md) | struct<br/>在指定轴上连接张量，将输入张量按给定的轴连接起来。 | 
| [Conv2DFusion](_conv2_d_fusion.md) | struct<br/>对将4维的tensor执行带有偏置的二维卷积运算。 | 
| [Conv2dTransposeFusion](_conv2d_transpose_fusion.md) | struct<br/>对一个4维的tensor执行带有偏置的二维反卷积。 | 
| [DivFusion](_div_fusion.md) | struct<br/>将两个tensor执行除法运算。 | 
| [Eltwise](_eltwise.md) | struct<br/>元素级别操作的算子。 | 
| [ExpandDims](_expand_dims.md) | struct<br/>在给定轴上为tensor添加一个额外的维度。 | 
| [Fill](_fill.md) | struct<br/>根据指定的维度，创建由一个标量填充的tensor。 | 
| [FullConnection](_full_connection.md) | struct<br/>对输入数据做全连接。 | 
| [FusedBatchNorm](_fused_batch_norm.md) | struct<br/>对一个tensor进行批标准化的运算。 | 
| [Gather](_gather.md) | struct<br/>根据指定的索引和轴返回输入tensor的切片。 | 
| [LayerNormFusion](_layer_norm_fusion.md) | struct<br/>对一个tensor从某一axis开始做层归一化。 | 
| [LessEqual](_less_equal.md) | struct<br/>对输入x1和x2，计算每对元素的x1&lt;=x2的结果。 | 
| [MatMulFusion](_mat_mul_fusion.md) | struct<br/>对输入x1和x2，计算x1和x2的内积。 | 
| [Maximum](_maximum.md) | struct<br/>对输入x1和x2，计算x1和x2对应元素最大值，x1和x2的输入遵守隐式类型转换规则，使数据类型一致。 | 
| [MaxPoolFusion](_max_pool_fusion.md) | struct<br/>对输入x，计算&nbsp;2D&nbsp;最大值池化。 | 
| [MulFusion](_mul_fusion.md) | struct<br/>对输入x1和x2，将x1和x2相同的位置的元素相乘得到output。 | 
| [OneHot](_one_hot.md) | struct<br/>根据indices指定的位置，生成一个由one-hot向量构成的tensor。 | 
| [PadFusion](_pad_fusion.md) | struct<br/>在x指定维度的数据前后，添加指定数值进行增广。 | 
| [PowFusion](_pow_fusion.md) | struct<br/>求x的y次幂，输入必须是两个tensor或一个tensor和一个标量。 | 
| [PReLUFusion](_p_re_l_u_fusion.md) | struct<br/>计算x和weight的PReLU激活值。 | 
| [QuantDTypeCast](_quant_d_type_cast.md) | struct<br/>数据类型转换。 | 
| [ReduceFusion](_reduce_fusion.md) | struct<br/>减小x张量的维度。 | 
| [Reshape](_reshape.md) | struct<br/>根据inputShape调整input的形状。 | 
| [Resize](_resize.md) | struct<br/>按给定的参数对输入的张量进行变形。 | 
| [Rsqrt](_rsqrt.md) | struct<br/>求x的平方根的倒数。 | 
| [ScaleFusion](_scale_fusion.md) | struct<br/>给定一个tensor，计算其缩放后的值。 | 
| [Shape](_shape.md) | struct<br/>输出输入tensor的形状。 | 
| [SliceFusion](_slice_fusion.md) | struct<br/>在x各维度，在axes维度中，以begin为起点，截取size长度的切片。 | 
| [Softmax](_softmax.md) | struct<br/>给定一个tensor，计算其softmax结果。 | 
| [SpaceToBatchND](_space_to_batch_n_d.md) | struct<br/>将4维张量在空间维度上进行切分成多个小块，然后在batch维度上拼接这些小块。 | 
| [Split](_split.md) | struct<br/>算子沿&nbsp;axis&nbsp;维度将x拆分成多个张量，张量数量由outputNum指定。 | 
| [Sqrt](_sqrt.md) | struct<br/>给定一个tensor，计算其平方根。 | 
| [SquaredDifference](_squared_difference.md) | struct<br/>计算两个输入的差值并返回差值的平方。SquaredDifference算子支持tensor和tensor相减。 | 
| [Squeeze](_squeeze.md) | struct<br/>去除axis中，长度为1的维度。支持int8量化输入。 | 
| [Stack](_stack.md) | struct<br/>将一组tensor沿axis维度进行堆叠，堆叠前每个tensor的维数为n，则堆叠后output维数为n+1。 | 
| [StridedSlice](_strided_slice.md) | struct<br/>根据步长和索引对输入张量进行切片提取。 | 
| [SubFusion](_sub_fusion.md) | struct<br/>计算两个输入的差值。 | 
| [TileFusion](_tile_fusion.md) | struct<br/>以multiples指定的次数拷贝输入张量。 | 
| [TopKFusion](_top_k_fusion.md) | struct<br/>查找沿axis轴的前K个最大值和对应索引。 | 
| [Transpose](_transpose.md) | struct<br/>根据perm对x进行数据重排。 | 
| [Unsqueeze](_unsqueeze.md) | struct<br/>根据输入axis的值。增加一个维度。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [DeviceType](#devicetype)&nbsp;:&nbsp;int&nbsp;{&nbsp;OTHER&nbsp;,&nbsp;CPU&nbsp;,&nbsp;GPU&nbsp;,&nbsp;ACCELERATOR&nbsp;} | AI计算芯片的类型。 | 
| [DeviceStatus](#devicestatus)&nbsp;:&nbsp;int&nbsp;{&nbsp;AVAILABLE&nbsp;,&nbsp;BUSY&nbsp;,&nbsp;OFFLINE&nbsp;,&nbsp;UNKNOWN&nbsp;} | 用于AI计算芯片的状态。 | 
| [PerformanceMode](#performancemode)&nbsp;:&nbsp;int&nbsp;{PERFORMANCE_NONE&nbsp;,&nbsp;PERFORMANCE_LOW&nbsp;,&nbsp;PERFORMANCE_MEDIUM&nbsp;,&nbsp;PERFORMANCE_HIGH&nbsp;,PERFORMANCE_EXTREME<br/>} | 芯片执行AI计算的性能模式。 | 
| [Priority](#priority)&nbsp;:&nbsp;int&nbsp;{&nbsp;PRIORITY_NONE&nbsp;,&nbsp;PRIORITY_LOW&nbsp;,&nbsp;PRIORITY_MEDIUM&nbsp;,&nbsp;PRIORITY_HIGH&nbsp;} | AI计算任务的优先级。 | 
| [Format](#format)&nbsp;:&nbsp;byte&nbsp;{&nbsp;FORMAT_NONE&nbsp;=&nbsp;-1&nbsp;,&nbsp;FORMAT_NCHW&nbsp;=&nbsp;0&nbsp;,&nbsp;FORMAT_NHWC&nbsp;=&nbsp;1&nbsp;} | 算子数据排布。需要配合[Tensor](_tensor.md)使用。 | 
| [DataType](#datatype)&nbsp;:&nbsp;byte&nbsp;{<br/>DATA_TYPE_UNKNOWN&nbsp;=&nbsp;0&nbsp;,&nbsp;DATA_TYPE_BOOL&nbsp;=&nbsp;30&nbsp;,&nbsp;DATA_TYPE_INT8&nbsp;=&nbsp;32&nbsp;,&nbsp;DATA_TYPE_INT16&nbsp;=&nbsp;33&nbsp;,&nbsp;DATA_TYPE_INT32&nbsp;=&nbsp;34&nbsp;,&nbsp;DATA_TYPE_INT64&nbsp;=&nbsp;35&nbsp;,&nbsp;DATA_TYPE_UINT8&nbsp;=&nbsp;37&nbsp;,&nbsp;DATA_TYPE_UINT16&nbsp;=&nbsp;38&nbsp;,&nbsp;DATA_TYPE_UINT32&nbsp;=&nbsp;39&nbsp;,&nbsp;DATA_TYPE_UINT64&nbsp;=&nbsp;40&nbsp;,&nbsp;DATA_TYPE_FLOAT16&nbsp;=&nbsp;42&nbsp;,&nbsp;DATA_TYPE_FLOAT32&nbsp;=&nbsp;43&nbsp;,DATA_TYPE_FLOAT64&nbsp;=&nbsp;44} | 张量的数据类型。需要配合[Tensor](_tensor.md)使用。 | 
| [QuantType](#quanttype)&nbsp;:&nbsp;byte&nbsp;{&nbsp;QUANT_TYPE_NONE&nbsp;,&nbsp;QUANT_TYPE_ALL&nbsp;} | 量化类型。需要配合[Node](_node.md)使用。 | 
| [NodeType](#nodetype)&nbsp;:&nbsp;unsigned&nbsp;int&nbsp;{<br/>NODE_TYPE_NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;NODE_TYPE_ACTIVATION&nbsp;=&nbsp;2&nbsp;,&nbsp;NODE_TYPE_ADD_FUSION&nbsp;=&nbsp;5&nbsp;,&nbsp;NODE_TYPE_ARGMAX_FUSION&nbsp;=&nbsp;11&nbsp;,<br/>NODE_TYPE_AVGPOOL_FUSION&nbsp;=&nbsp;17&nbsp;,&nbsp;NODE_TYPE_BATCH_TO_SPACE_ND&nbsp;=&nbsp;22&nbsp;,&nbsp;NODE_TYPE_BIAS_ADD&nbsp;=&nbsp;23&nbsp;,&nbsp;NODE_TYPE_CAST&nbsp;=&nbsp;28&nbsp;,<br/>NODE_TYPE_CONCAT&nbsp;=&nbsp;31&nbsp;,&nbsp;NODE_TYPE_CONV2D_FUSION&nbsp;=&nbsp;35&nbsp;,&nbsp;NODE_TYPE_CONV2D_TRANSPOSE_FUSION&nbsp;=&nbsp;36&nbsp;,&nbsp;NODE_TYPE_DIV_FUSION&nbsp;=&nbsp;47&nbsp;,&nbsp;NODE_TYPE_ELTWISE&nbsp;=&nbsp;52&nbsp;,&nbsp;NODE_TYPE_EXPAND_DIMS&nbsp;=&nbsp;56&nbsp;,&nbsp;NODE_TYPE_FILL&nbsp;=&nbsp;66&nbsp;,&nbsp;NODE_TYPE_FULL_CONNECTION&nbsp;=&nbsp;67&nbsp;,<br/>NODE_TYPE_FUSED_BATCH_NORM&nbsp;=&nbsp;68&nbsp;,&nbsp;NODE_TYPE_GATHER&nbsp;=&nbsp;69&nbsp;,&nbsp;NODE_TYPE_LAYER_NORM_FUSION&nbsp;=&nbsp;75&nbsp;,&nbsp;NODE_TYPE_LESS_EQUAL&nbsp;=&nbsp;78&nbsp;,<br/>NODE_TYPE_MATMUL_FUSION&nbsp;=&nbsp;89&nbsp;,&nbsp;NODE_TYPE_MAXIMUM&nbsp;=&nbsp;90&nbsp;,&nbsp;NODE_TYPE_MAX_POOL_FUSION&nbsp;=&nbsp;92&nbsp;,&nbsp;NODE_TYPE_MUL_FUSION&nbsp;=&nbsp;99&nbsp;,<br/>NODE_TYPE_ONE_HOT&nbsp;=&nbsp;105&nbsp;,&nbsp;NODE_TYPE_PAD_FUSION&nbsp;=&nbsp;107&nbsp;,&nbsp;NODE_TYPE_POW_FUSION&nbsp;=&nbsp;110&nbsp;,&nbsp;NODE_TYPE_PRELU_FUSION&nbsp;=&nbsp;112&nbsp;,<br/>NODE_TYPE_QUANT_DTYPE_CAST&nbsp;=&nbsp;113&nbsp;,&nbsp;NODE_TYPE_REDUCE_FUSION&nbsp;=&nbsp;118&nbsp;,&nbsp;NODE_TYPE_RESHAPE&nbsp;=&nbsp;119&nbsp;,&nbsp;NODE_TYPE_RESIZE&nbsp;=&nbsp;120&nbsp;,<br/>NODE_TYPE_RSQRT&nbsp;=&nbsp;126&nbsp;,&nbsp;NODE_TYPE_SCALE_FUSION&nbsp;=&nbsp;127&nbsp;,&nbsp;NODE_TYPE_SHAPE&nbsp;=&nbsp;130&nbsp;,&nbsp;NODE_TYPE_SLICE_FUSION&nbsp;=&nbsp;135&nbsp;,<br/>NODE_TYPE_SOFTMAX&nbsp;=&nbsp;138&nbsp;,&nbsp;NODE_TYPE_SPACE_TO_BATCH_ND&nbsp;=&nbsp;141&nbsp;,&nbsp;NODE_TYPE_SPLIT&nbsp;=&nbsp;145&nbsp;,&nbsp;NODE_TYPE_SQRT&nbsp;=&nbsp;146&nbsp;,<br/>NODE_TYPE_SQUEEZE&nbsp;=&nbsp;147&nbsp;,&nbsp;NODE_TYPE_SQUARED_DIFFERENCE&nbsp;=&nbsp;149&nbsp;,&nbsp;NODE_TYPE_STACK&nbsp;=&nbsp;150&nbsp;,&nbsp;NODE_TYPE_STRIDED_SLICE&nbsp;=&nbsp;151&nbsp;,<br/>NODE_TYPE_SUB_FUSION&nbsp;=&nbsp;152&nbsp;,&nbsp;NODE_TYPE_TILE_FUSION&nbsp;=&nbsp;160&nbsp;,&nbsp;NODE_TYPE_TOPK_FUSION&nbsp;=&nbsp;161&nbsp;,&nbsp;NODE_TYPE_TRANSPOSE&nbsp;=&nbsp;162&nbsp;,<br/>NODE_TYPE_UNSQUEEZE&nbsp;=&nbsp;165<br/>} | 算子类型。 | 
| [ResizeMethod](#resizemethod)&nbsp;:&nbsp;byte&nbsp;{&nbsp;RESIZE_METHOD_UNKNOWN&nbsp;=&nbsp;-1&nbsp;,&nbsp;RESIZE_METHOD_LINEAR&nbsp;=&nbsp;0&nbsp;,&nbsp;RESIZE_METHOD_NEAREST&nbsp;=&nbsp;1&nbsp;,&nbsp;RESIZE_METHOD_CUBIC&nbsp;=&nbsp;2&nbsp;} | 调整尺寸的方法。需要配合[Resize](_resize.md)算子使用。 | 
| [CoordinateTransformMode](#coordinatetransformmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;COORDINATE_TRANSFORM_MODE_ASYMMETRIC&nbsp;=&nbsp;0&nbsp;,&nbsp;COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS&nbsp;=&nbsp;1&nbsp;,&nbsp;COORDINATE_TRANSFORM_MODE_HALF_PIXEL&nbsp;=&nbsp;2&nbsp;} | 坐标变换模式，仅[Resize](_resize.md)算子使用这些枚举。 | 
| [NearestMode](#nearestmode)&nbsp;:&nbsp;byte&nbsp;{<br/>NEAREST_MODE_NORMAL&nbsp;=&nbsp;0&nbsp;,&nbsp;NEAREST_MODE_ROUND_HALF_DOWN&nbsp;=&nbsp;1&nbsp;,&nbsp;NEAREST_MODE_ROUND_HALF_UP&nbsp;=&nbsp;2&nbsp;,&nbsp;NEAREST_MODE_FLOOR&nbsp;=&nbsp;3&nbsp;,<br/>NEAREST_MODE_CEIL&nbsp;=&nbsp;4<br/>} | 临近算法类型。需要配合[Resize](_resize.md)算子使用。 | 
| [ActivationType](#activationtype)&nbsp;:&nbsp;byte&nbsp;{<br/>ACTIVATION_TYPE_NO_ACTIVATION&nbsp;=&nbsp;0&nbsp;,&nbsp;ACTIVATION_TYPE_RELU&nbsp;=&nbsp;1&nbsp;,&nbsp;ACTIVATION_TYPE_SIGMOID&nbsp;=&nbsp;2&nbsp;,&nbsp;ACTIVATION_TYPE_RELU6&nbsp;=&nbsp;3&nbsp;,<br/>ACTIVATION_TYPE_ELU&nbsp;=&nbsp;4&nbsp;,&nbsp;ACTIVATION_TYPE_LEAKY_RELU&nbsp;=&nbsp;5&nbsp;,&nbsp;ACTIVATION_TYPE_ABS&nbsp;=&nbsp;6&nbsp;,&nbsp;ACTIVATION_TYPE_RELU1&nbsp;=&nbsp;7&nbsp;,<br/>ACTIVATION_TYPE_SOFTSIGN&nbsp;=&nbsp;8&nbsp;,&nbsp;ACTIVATION_TYPE_SOFTPLUS&nbsp;=&nbsp;9&nbsp;,&nbsp;ACTIVATION_TYPE_TANH&nbsp;=&nbsp;10&nbsp;,&nbsp;ACTIVATION_TYPE_SELU&nbsp;=&nbsp;11&nbsp;,<br/>ACTIVATION_TYPE_HSWISH&nbsp;=&nbsp;12&nbsp;,&nbsp;ACTIVATION_TYPE_HSIGMOID&nbsp;=&nbsp;13&nbsp;,&nbsp;ACTIVATION_TYPE_THRESHOLDRELU&nbsp;=&nbsp;14&nbsp;,&nbsp;ACTIVATION_TYPE_LINEAR&nbsp;=&nbsp;15&nbsp;,&nbsp;ACTIVATION_TYPE_HARD_TANH&nbsp;=&nbsp;16&nbsp;,&nbsp;ACTIVATION_TYPE_SIGN&nbsp;=&nbsp;17&nbsp;,&nbsp;ACTIVATION_TYPE_SWISH&nbsp;=&nbsp;18&nbsp;,&nbsp;ACTIVATION_TYPE_GELU&nbsp;=&nbsp;19&nbsp;,<br/>ACTIVATION_TYPE_UNKNOWN&nbsp;=&nbsp;20} | 激活函数类型。 | 
| [ReduceMode](#reducemode)&nbsp;:&nbsp;byte&nbsp;{<br/>REDUCE_MODE_MEAN&nbsp;=&nbsp;0&nbsp;,&nbsp;REDUCE_MODE_MAX&nbsp;=&nbsp;1&nbsp;,&nbsp;REDUCE_MODE_MIN&nbsp;=&nbsp;2&nbsp;,&nbsp;REDUCE_MODE_PROD&nbsp;=&nbsp;3&nbsp;,&nbsp;REDUCE_MODE_SUM&nbsp;=&nbsp;4&nbsp;,&nbsp;REDUCE_MODE_SUM_SQUARE&nbsp;=&nbsp;5&nbsp;,&nbsp;REDUCE_MODE_ASUM&nbsp;=&nbsp;6&nbsp;,&nbsp;REDUCE_MODE_ALL&nbsp;=&nbsp;7} | 用于维度移除的方法，需要配合[ReduceFusion](_reduce_fusion.md)算子使用。 | 
| [EltwiseMode](#eltwisemode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;ELTWISE_MODE_PROD&nbsp;=&nbsp;0&nbsp;,&nbsp;ELTWISE_MODE_SUM&nbsp;=&nbsp;1&nbsp;,&nbsp;ELTWISE_MODE_MAXIMUM&nbsp;=&nbsp;2&nbsp;,&nbsp;ELTWISE_MODE_UNKNOWN&nbsp;=&nbsp;3&nbsp;} | 元素级别运算支持的计算类型，需要配合[Eltwise](_eltwise.md)算子使用。 | 
| [PadMode](#padmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;PAD_MODE_PAD&nbsp;=&nbsp;0&nbsp;,&nbsp;PAD_MODE_SAME&nbsp;=&nbsp;1&nbsp;,&nbsp;PAD_MODE_VALID&nbsp;=&nbsp;2&nbsp;} | 填充类型，需要配合[AvgPoolFusion](_avg_pool_fusion.md)，[AvgPoolFusion](_avg_pool_fusion.md)，[Conv2DFusion](_conv2_d_fusion.md)，[MaxPoolFusion](_max_pool_fusion.md)使用。 | 
| [RoundMode](#roundmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;ROUND_MODE_FLOOR&nbsp;=&nbsp;0&nbsp;,&nbsp;ROUND_MODE_CEIL&nbsp;=&nbsp;1&nbsp;} | 小数取整算法，需要配合[AvgPoolFusion](_avg_pool_fusion.md)算子使用。 | 
| [PaddingMode](#paddingmode)&nbsp;:&nbsp;byte&nbsp;{&nbsp;PADDING_MODE_CONSTANT&nbsp;=&nbsp;0&nbsp;,&nbsp;PADDING_MODE_REFLECT&nbsp;=&nbsp;1&nbsp;,&nbsp;PADDING_MODE_SYMMETRIC&nbsp;=&nbsp;2&nbsp;,&nbsp;PADDING_MODE_RESERVED&nbsp;=&nbsp;3&nbsp;} | 填充类型，需要配合[PadFusion](_pad_fusion.md)算子使用。 | 
| [NNRT_ReturnCode](#nnrt_returncode)&nbsp;:&nbsp;int&nbsp;{<br/>NNRT_SUCCESS&nbsp;=&nbsp;0&nbsp;,&nbsp;NNRT_FAILED&nbsp;=&nbsp;1&nbsp;,&nbsp;NNRT_NULL_PTR&nbsp;=&nbsp;2&nbsp;,&nbsp;NNRT_INVALID_PARAMETER&nbsp;=&nbsp;3&nbsp;,<br/>NNRT_MEMORY_ERROR&nbsp;=&nbsp;4&nbsp;,&nbsp;NNRT_OUT_OF_MEMORY&nbsp;=&nbsp;5&nbsp;,&nbsp;NNRT_OPERATION_FORBIDDEN&nbsp;=&nbsp;6&nbsp;,&nbsp;NNRT_INVALID_FILE&nbsp;=&nbsp;7&nbsp;,<br/>NNRT_INVALID_PATH&nbsp;=&nbsp;8&nbsp;,&nbsp;NNRT_INSUFFICIENT_BUFFER&nbsp;=&nbsp;9&nbsp;,&nbsp;NNRT_NO_CHANGE&nbsp;=&nbsp;10&nbsp;,&nbsp;NNRT_NOT_SUPPORT&nbsp;=&nbsp;11&nbsp;,<br/>NNRT_SERVICE_ERROR&nbsp;=&nbsp;12&nbsp;,&nbsp;NNRT_DEVICE_ERROR&nbsp;=&nbsp;13&nbsp;,&nbsp;NNRT_DEVICE_BUSY&nbsp;=&nbsp;14&nbsp;,&nbsp;NNRT_CANCELLED&nbsp;=&nbsp;15&nbsp;,<br/>NNRT_PERMISSION_DENIED&nbsp;=&nbsp;16&nbsp;,&nbsp;NNRT_TIME_OUT&nbsp;=&nbsp;17&nbsp;,&nbsp;NNRT_INVALID_TENSOR&nbsp;=&nbsp;18&nbsp;,&nbsp;NNRT_INVALID_NODE&nbsp;=&nbsp;19&nbsp;,<br/>NNRT_INVALID_INPUT&nbsp;=&nbsp;20&nbsp;,&nbsp;NNRT_INVALID_OUTPUT&nbsp;=&nbsp;21&nbsp;,&nbsp;NNRT_INVALID_DATATYPE&nbsp;=&nbsp;22&nbsp;,&nbsp;NNRT_INVALID_FORMAT&nbsp;=&nbsp;23&nbsp;,<br/>NNRT_INVALID_TENSOR_NAME&nbsp;=&nbsp;24&nbsp;,&nbsp;NNRT_INVALID_SHAPE&nbsp;=&nbsp;25&nbsp;,&nbsp;NNRT_OUT_OF_DIMENTION_RANGES&nbsp;=&nbsp;26&nbsp;,&nbsp;NNRT_INVALID_BUFFER&nbsp;=&nbsp;27&nbsp;,<br/>NNRT_INVALID_BUFFER_SIZE&nbsp;=&nbsp;28&nbsp;,&nbsp;NNRT_INVALID_PERFORMANCE_MODE&nbsp;=&nbsp;29&nbsp;,&nbsp;NNRT_INVALID_PRIORITY&nbsp;=&nbsp;30&nbsp;,&nbsp;NNRT_INVALID_MODEL&nbsp;=&nbsp;31&nbsp;,<br/>NNRT_INVALID_MODEL_CACHE&nbsp;=&nbsp;32&nbsp;,&nbsp;NNRT_UNSUPPORTED_OP&nbsp;=&nbsp;33<br/>} | NNRt定义的专用错误码，为HDI接口的返回值。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.nnrt.v2_0 | NNRt模块的包路径。 | 


## 枚举类型说明


### ActivationType

  
```
enum ActivationType : byte
```

**描述:**

激活函数类型。

激活函数使得神经网络模型具有区分非线性函数的能力，这也让神经网络模型可以被应用于众多非线性模型中。[NodeAttrTypes.idl](_node_attr_types_8idl.md)文件中拥有ActivationType类型的参数的算子会在运行完成算子的运算之后执行相对应的激活函数。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ACTIVATION_TYPE_NO_ACTIVATION | 无激活函数。 | 
| ACTIVATION_TYPE_RELU | ReLU激活函数。逐元素求$&nbsp;max(x_i,&nbsp;0)&nbsp;$，负数输出值会被修改为0，正数输出不受影响。<br/>$&nbsp;\text{ReLU}(x_i)&nbsp;=&nbsp;(x_i)^+&nbsp;=&nbsp;\max(x_i,&nbsp;0),$<br/>其中$&nbsp;x_i&nbsp;$是输入元素。 | 
| ACTIVATION_TYPE_SIGMOID | Sigmoid激活函数。按元素计算Sigmoid激活函数。Sigmoid函数定义为：<br/>$&nbsp;\text{Sigmoid}(x_i)&nbsp;=&nbsp;\frac{1}{1&nbsp;+&nbsp;\exp(-x_i)}&nbsp;$<br/>其中$&nbsp;x_i&nbsp;$是输入的元素。 | 
| ACTIVATION_TYPE_RELU6 | ReLU6激活函数。ReLU6类似于ReLU，不同之处在于设置了上限，其上限为6，如果输入大于6，输出会被限制为6。ReLU6函数定义为：<br/>$&nbsp;\text{ReLU6}(x_i)&nbsp;=&nbsp;\min(\max(0,&nbsp;x_i),&nbsp;6)&nbsp;$<br/>其中$&nbsp;x_i&nbsp;$是输入的元素。 | 
| ACTIVATION_TYPE_ELU | 指数线性单元激活函数（Exponential&nbsp;Linear&nbsp;Unit&nbsp;activation&nbsp;function，ELU）激活函数。对输入的每个元素计算ELU。ELU函数定义为：<br/>$&nbsp;ELU(x_{i})&nbsp;=&nbsp;\begin{cases}&nbsp;x_i,&nbsp;&amp;\text{if&nbsp;}&nbsp;x_i&nbsp;\geq&nbsp;0;&nbsp;\cr&nbsp;\alpha&nbsp;\*&nbsp;(\exp(x_i)&nbsp;-&nbsp;1),&nbsp;&amp;\text{otherwise.}&nbsp;\end{cases}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素，$&nbsp;\alpha&nbsp;$表示alpha参数，该参数通过[Activation](_activation.md)进行设置。 | 
| ACTIVATION_TYPE_LEAKY_RELU | LeakyReLU激活函数。&nbsp;LeakyReLU函数定义为：<br/>$&nbsp;\text{LeakyReLU}(x_i)&nbsp;=&nbsp;\begin{cases}&nbsp;x_i,&nbsp;&amp;\text{if&nbsp;}&nbsp;x_i&nbsp;\geq&nbsp;0;&nbsp;\cr&nbsp;{\alpha}&nbsp;\*&nbsp;x_i,&nbsp;&amp;\text{otherwise.}&nbsp;\end{cases}$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素，$&nbsp;\alpha&nbsp;$表示alpha参数，该参数通过[Activation](_activation.md)进行设置。 | 
| ACTIVATION_TYPE_ABS | 计算绝对值的激活函数。函数定义为：<br/>$&nbsp;\text{abs}(x_i)&nbsp;=&nbsp;\|x_i\|&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_RELU1 | ReLU1激活函数。ReLU1函数定义为：<br/>$&nbsp;\text{ReLU1}(x_i)=&nbsp;\min(\max(0,&nbsp;x_i),&nbsp;1)&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_SOFTSIGN | SoftSign激活函数。SoftSign函数定义如下：<br/>$&nbsp;\text{SoftSign}(x_i)&nbsp;=&nbsp;\frac{x_i}{1&nbsp;+&nbsp;\|x_i\|}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_SOFTPLUS | Softplus激活函数。Softplus为ReLU函数的平滑近似。可对一组数值使用来确保转换后输出结果均为正值。Softplus函数定义如下：<br/>$&nbsp;\text{Softplus}(x_i)&nbsp;=&nbsp;\log(1&nbsp;+&nbsp;\exp(x_i))&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_TANH | Tanh激活函数。Tanh函数定义如下：<br/>$&nbsp;tanh(x)&nbsp;=&nbsp;\frac{\exp(x_i)&nbsp;-&nbsp;\exp(-x_i)}{\exp(x_i)&nbsp;+&nbsp;\exp(-x_i)}&nbsp;=&nbsp;\frac{\exp(2x_i)&nbsp;-&nbsp;1}{\exp(2x_i)&nbsp;+&nbsp;1}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_SELU | SELU（Scaled&nbsp;exponential&nbsp;Linear&nbsp;Unit）激活函数。SELU函数定义如下：<br/>$&nbsp;SELU(x_{i})&nbsp;=&nbsp;scale&nbsp;\*&nbsp;\begin{cases}&nbsp;x_{i},&nbsp;&amp;\text{if&nbsp;}&nbsp;x_{i}&nbsp;\geq&nbsp;0;&nbsp;\cr&nbsp;\text{alpha}&nbsp;\*&nbsp;(\exp(x_i)&nbsp;-&nbsp;1),&nbsp;&amp;\text{otherwise.}&nbsp;\end{cases}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$是输入元素，$&nbsp;\alpha&nbsp;$和$&nbsp;scale&nbsp;$是预定义的常量（&nbsp;$\alpha=1.67326324$，$scale=1.05070098$）。 | 
| ACTIVATION_TYPE_HSWISH | Hard&nbsp;Swish激活函数。<br/>$&nbsp;\text{Hardswish}(x_{i})&nbsp;=&nbsp;x_{i}&nbsp;\*&nbsp;\frac{ReLU6(x_{i}&nbsp;+&nbsp;3)}{6}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_HSIGMOID | Hard&nbsp;Sigmoid激活函数。&nbsp;Hard&nbsp;Sigmoid函数定义如下：<br/>$&nbsp;\text{Hardsigmoid}(x_{i})&nbsp;=&nbsp;max(0,&nbsp;min(1,&nbsp;\frac{x_{i}&nbsp;+&nbsp;3}{6}))&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_THRESHOLDRELU | ThresholdedReLU激活函数。类似ReLU激活函数，min数定义如下：<br/>$&nbsp;\text{ThresholdedReLU}(x_i)&nbsp;=&nbsp;\min(\max(0,&nbsp;x_i),&nbsp;t)&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$是输入元素，$&nbsp;t&nbsp;$是最大值。 | 
| ACTIVATION_TYPE_LINEAR | Linear激活函数。Linear函数定义如下：<br/>$&nbsp;\text{Linear}(x_i)&nbsp;=&nbsp;x_i&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_HARD_TANH | HardTanh激活函数。HardTanh函数定义如下：<br/>$&nbsp;\text{HardTanh}(x_i)&nbsp;=&nbsp;\begin{cases}&nbsp;\text{max_val}&nbsp;&amp;&nbsp;\text{&nbsp;if&nbsp;}&nbsp;x_i&nbsp;&gt;&nbsp;\text{&nbsp;max_val&nbsp;}&nbsp;\\&nbsp;\text{min_val}&nbsp;&amp;&nbsp;\text{&nbsp;if&nbsp;}&nbsp;x_i&nbsp;&lt;&nbsp;\text{&nbsp;min_val&nbsp;}&nbsp;\\&nbsp;x_i&nbsp;&amp;&nbsp;\text{&nbsp;otherwise&nbsp;}&nbsp;\\&nbsp;\end{cases}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$是输入，$&nbsp;max\_val&nbsp;$是最大值，$&nbsp;min\_val&nbsp;$是最小值，这两个参数通过[Activation](_activation.md)进行设置。 | 
| ACTIVATION_TYPE_SIGN | Sign激活函数。Sign函数定义如下：<br/>$&nbsp;Sign(x_i)&nbsp;=&nbsp;\begin{cases}&nbsp;-1,&nbsp;&amp;if\&nbsp;x_i&nbsp;&lt;&nbsp;0&nbsp;\cr&nbsp;0,&nbsp;&amp;if\&nbsp;x_i&nbsp;=&nbsp;0&nbsp;\cr&nbsp;1,&nbsp;&amp;if\&nbsp;x_i&nbsp;&gt;&nbsp;0\end{cases}&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_SWISH | Swish激活函数。Swish激活函数定义如下：<br/>$&nbsp;\text{Swish}(x_i)&nbsp;=&nbsp;x_i&nbsp;\*&nbsp;Sigmoid(x_i)&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$表示输入的元素。 | 
| ACTIVATION_TYPE_GELU | GELU（Gaussian&nbsp;error&nbsp;linear&nbsp;unit&nbsp;activation&nbsp;function）高斯误差线性单元激活函数。GELU函数定义如下：<br/>$&nbsp;GELU(x_i)&nbsp;=&nbsp;x_i\*P(X&nbsp;&lt;&nbsp;x_i)&nbsp;$<br/>其中，$&nbsp;x_i&nbsp;$是输入元素，$&nbsp;P&nbsp;$是标准高斯分布的累积分布函数。需要通过[Activation](_activation.md)的approximate参数指定是否使用近似。 | 
| ACTIVATION_TYPE_UNKNOWN | 未知 | 


### CoordinateTransformMode

  
```
enum CoordinateTransformMode : byte
```

**描述:**

坐标变换模式，仅[Resize](_resize.md)算子使用这些枚举。

以变换 Width 为例， 记 new_i 为resize之后的Tenosr沿X轴的第i个坐标；记 old_i 为输入Tensor沿X的轴的对应坐标；记 newWidth 是resize之后的Tensor沿着X的轴的长度；记 oldWidth 是输入Tenosr沿X的轴的长度。 可以通过下面的公式计算出 old_i :

- COORDINATE_TRANSFORM_MODE_ASYMMETRIC：
  $ old_i = newWidth != 0 ? new_i \* oldWidth / newWidth : 0 $

- COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS：
  $ old_i = newWidth != 1 ? new_i \* (oldWidth - 1) / (newWidth - 1) $

- COORDINATE_TRANSFORM_MODE_HALF_PIXEL：
  $ old_i = newWidth &gt; 1 ? (new_x + 0.5) \* oldWidth / newWidth - 0.5 : 0 $


| 枚举值 | 描述 | 
| -------- | -------- |
| COORDINATE_TRANSFORM_MODE_ASYMMETRIC | 不进行对齐，直接按照比例缩放 | 
| COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS | 对齐图像的4个角 | 
| COORDINATE_TRANSFORM_MODE_HALF_PIXEL | 对齐像素点中心 | 


### DataType

  
```
enum DataType : byte
```

**描述:**

张量的数据类型。需要配合[Tensor](_tensor.md)使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DATA_TYPE_UNKNOWN | 数据类型未知 | 
| DATA_TYPE_BOOL | 数据类型是BOOL | 
| DATA_TYPE_INT8 | 数据类型是INT8 | 
| DATA_TYPE_INT16 | 数据类型是INT16 | 
| DATA_TYPE_INT32 | 数据类型是INT32 | 
| DATA_TYPE_INT64 | 数据类型是INT64 | 
| DATA_TYPE_UINT8 | 数据类型是UINT8 | 
| DATA_TYPE_UINT16 | 数据类型是UINT16 | 
| DATA_TYPE_UINT32 | 数据类型是UINT32 | 
| DATA_TYPE_UINT64 | 数据类型是UINT64 | 
| DATA_TYPE_FLOAT16 | 数据类型是FLOAT16 | 
| DATA_TYPE_FLOAT32 | 数据类型是FLOAT32 | 
| DATA_TYPE_FLOAT64 | 数据类型是FLOAT64 | 


### DeviceStatus

  
```
enum DeviceStatus : int
```

**描述:**

用于AI计算芯片的状态。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AVAILABLE | 芯片当前处于可用状态 | 
| BUSY | 芯片当前处于忙碌状态，可能无法及时响应计算任务 | 
| OFFLINE | 芯片当前处于下线状态，无法响应计算任务 | 
| UNKNOWN | 芯片当前处于未知状态 | 


### DeviceType

  
```
enum DeviceType : int
```

**描述:**

AI计算芯片的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| OTHER | 不属于以下类型的芯片 | 
| CPU | CPU芯片 | 
| GPU | GPU芯片 | 
| ACCELERATOR | AI专用加速芯片，比如NPU、DSP | 


### EltwiseMode

  
```
enum EltwiseMode : byte
```

**描述:**

元素级别运算支持的计算类型，需要配合[Eltwise](_eltwise.md)算子使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ELTWISE_MODE_PROD | 两个tensor对应元素乘积。 | 
| ELTWISE_MODE_SUM | 两个tensor对应元素之差。 | 
| ELTWISE_MODE_MAXIMUM | 两个tensor对应元素的最大值。 | 
| ELTWISE_MODE_UNKNOWN | 未知。 | 


### Format

  
```
enum Format : byte
```

**描述:**

算子数据排布。需要配合[Tensor](_tensor.md)使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| FORMAT_NONE | 用于数据排列，作为Format初始的值。 | 
| FORMAT_NCHW | 数据排列为NCHW。 | 
| FORMAT_NHWC | 数据排列为NHWC。 | 


### NearestMode

  
```
enum NearestMode : byte
```

**描述:**

临近算法类型。需要配合[Resize](_resize.md)算子使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| NEAREST_MODE_NORMAL | 四舍五入取整 | 
| NEAREST_MODE_ROUND_HALF_DOWN | 向负无穷取整，例如23.5取整为23，−23.5取整为−24 | 
| NEAREST_MODE_ROUND_HALF_UP | 向正无穷取整，例如23.5取整为24，−23.5取整为−23 | 
| NEAREST_MODE_FLOOR | 向下取临近的整数，例如23.5取整为23，−23.5取整为−24 | 
| NEAREST_MODE_CEIL | 向上取临近的整数整，例如23.5取整为24，−23.5取整为−23 | 


### NNRT_ReturnCode

  
```
enum NNRT_ReturnCode : int
```

**描述:**

NNRt定义的专用错误码，为HDI接口的返回值。

  | 枚举值 | 描述 | 
| -------- | -------- |
| NNRT_SUCCESS | 成功 | 
| NNRT_FAILED | 失败 | 
| NNRT_NULL_PTR | 空指针 | 
| NNRT_INVALID_PARAMETER | 非法参数 | 
| NNRT_MEMORY_ERROR | 内存错误 | 
| NNRT_OUT_OF_MEMORY | 内存不足 | 
| NNRT_OPERATION_FORBIDDEN | 禁止的操作 | 
| NNRT_INVALID_FILE | 非法文件 | 
| NNRT_INVALID_PATH | 非法路径 | 
| NNRT_INSUFFICIENT_BUFFER | 缓存不足 | 
| NNRT_NO_CHANGE | 无变化 | 
| NNRT_NOT_SUPPORT | 不支持 | 
| NNRT_SERVICE_ERROR | 服务错误 | 
| NNRT_DEVICE_ERROR | 设备错误 | 
| NNRT_DEVICE_BUSY | 设备忙碌 | 
| NNRT_CANCELLED | 操作取消 | 
| NNRT_PERMISSION_DENIED | 拒绝访问 | 
| NNRT_TIME_OUT | 超时 | 
| NNRT_INVALID_TENSOR | 非法tensor | 
| NNRT_INVALID_NODE | 非法节点 | 
| NNRT_INVALID_INPUT | 非法输入 | 
| NNRT_INVALID_OUTPUT | 非法输出 | 
| NNRT_INVALID_DATATYPE | 非法数据类型 | 
| NNRT_INVALID_FORMAT | 非法数据布局 | 
| NNRT_INVALID_TENSOR_NAME | 非法tensor名称 | 
| NNRT_INVALID_SHAPE | 非法shape | 
| NNRT_OUT_OF_DIMENTION_RANGES | 超出维度范围 | 
| NNRT_INVALID_BUFFER | 非法缓存 | 
| NNRT_INVALID_BUFFER_SIZE | 非法缓存大小 | 
| NNRT_INVALID_PERFORMANCE_MODE | 非法性能模式 | 
| NNRT_INVALID_PRIORITY | 非法优先级 | 
| NNRT_INVALID_MODEL | 非法模型 | 
| NNRT_INVALID_MODEL_CACHE | 非法模型缓存 | 
| NNRT_UNSUPPORTED_OP | 算子不支持 | 


### NodeType

  
```
enum NodeType : unsigned int
```

**描述:**

算子类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| NODE_TYPE_NONE | 算子类型为NONE | 
| NODE_TYPE_ACTIVATION | 激活函数类型 | 
| NODE_TYPE_ADD_FUSION | ADD算子 | 
| NODE_TYPE_ARGMAX_FUSION | ArgMax算子 | 
| NODE_TYPE_AVGPOOL_FUSION | AVGPOOL算子 | 
| NODE_TYPE_BATCH_TO_SPACE_ND | BatchToSpaceND算子 | 
| NODE_TYPE_BIAS_ADD | BiasAdd算子 | 
| NODE_TYPE_CAST | Cast算子 | 
| NODE_TYPE_CONCAT | Concat算子 | 
| NODE_TYPE_CONV2D_FUSION | Conv2D算子，包含了普通卷积、可分离卷积和分组卷积 | 
| NODE_TYPE_CONV2D_TRANSPOSE_FUSION | 二维反卷积算子 | 
| NODE_TYPE_DIV_FUSION | Div算子 | 
| NODE_TYPE_ELTWISE | 元素级别算子 | 
| NODE_TYPE_EXPAND_DIMS | ExpandDims张算子 | 
| NODE_TYPE_FILL | Fill算子 | 
| NODE_TYPE_FULL_CONNECTION | FullConnection算子 | 
| NODE_TYPE_FUSED_BATCH_NORM | BatchNorm算子 | 
| NODE_TYPE_GATHER | Gather算子 | 
| NODE_TYPE_LAYER_NORM_FUSION | LayerNorm算子 | 
| NODE_TYPE_LESS_EQUAL | LessEqual算子 | 
| NODE_TYPE_MATMUL_FUSION | MatMul算子 | 
| NODE_TYPE_MAXIMUM | Maximum算子 | 
| NODE_TYPE_MAX_POOL_FUSION | MaxPool算子 | 
| NODE_TYPE_MUL_FUSION | Mul算子 | 
| NODE_TYPE_ONE_HOT | OneHot算子 | 
| NODE_TYPE_PAD_FUSION | Pad算子 | 
| NODE_TYPE_POW_FUSION | Pow算子 | 
| NODE_TYPE_PRELU_FUSION | PReLU算子 | 
| NODE_TYPE_QUANT_DTYPE_CAST | QuantDTypeCast算子 | 
| NODE_TYPE_REDUCE_FUSION | Reduce算子 | 
| NODE_TYPE_RESHAPE | Reshape算子 | 
| NODE_TYPE_RESIZE | Resize算子 | 
| NODE_TYPE_RSQRT | Rsqrt算子 | 
| NODE_TYPE_SCALE_FUSION | Scale算子 | 
| NODE_TYPE_SHAPE | Shape算子 | 
| NODE_TYPE_SLICE_FUSION | Slice算子 | 
| NODE_TYPE_SOFTMAX | Softmax算子 | 
| NODE_TYPE_SPACE_TO_BATCH_ND | SpaceToBatchND算子 | 
| NODE_TYPE_SPLIT | Split算子 | 
| NODE_TYPE_SQRT | Sqrt算子 | 
| NODE_TYPE_SQUEEZE | SquaredDifference算子 | 
| NODE_TYPE_SQUARED_DIFFERENCE | Squeeze算子 | 
| NODE_TYPE_STACK | Stack算子 | 
| NODE_TYPE_STRIDED_SLICE | StridedSlice算子 | 
| NODE_TYPE_SUB_FUSION | Sub算子 | 
| NODE_TYPE_TILE_FUSION | Tile算子 | 
| NODE_TYPE_TOPK_FUSION | TopK算子 | 
| NODE_TYPE_TRANSPOSE | Transpose算子 | 
| NODE_TYPE_UNSQUEEZE | Unsqueeze算子 | 


### PaddingMode

  
```
enum PaddingMode : byte
```

**描述:**

填充类型，需要配合[PadFusion](_pad_fusion.md)算子使用。

当输入的张量x= $[[1,2,3],[4,5,6],[7,8,9]]$、paddings= $[[2,2],[2,2]]$时效果如下：

- paddingMode==PADDING_MODE_CONSTANT并且constantValue = 0时输出为：
  $[[0. 0. 0. 0. 0. 0. 0.],\\ [0. 0. 0. 0. 0. 0. 0.],\\ [0. 0. 1. 2. 3. 0. 0.],\\ [0. 0. 4. 5. 6. 0. 0.],\\ [0. 0. 7. 8. 9. 0. 0.],\\ [0. 0. 0. 0. 0. 0. 0.],\\ [0. 0. 0. 0. 0. 0. 0.]]\\ $

- paddingMode==PADDING_MODE_REFLECT输出为：
  $[[9. 8. 7. 8. 9. 8. 7.],\\ [6. 5. 4. 5. 6. 5. 4.],\\ [3. 2. 1. 2. 3. 2. 1.],\\ [6. 5. 4. 5. 6. 5. 4.],\\ [9. 8. 7. 8. 9. 8. 7.],\\ [6. 5. 4. 5. 6. 5. 4.],\\ [3. 2. 1. 2. 3. 2. 1.]]\\ $

- paddingMode==PADDING_MODE_SYMMETRIC输出为：
  $[[5. 4. 4. 5. 6. 6. 5.],\\ [2. 1. 1. 2. 3. 3. 2.],\\ [2. 1. 1. 2. 3. 3. 2.],\\ [5. 4. 4. 5. 6. 6. 5.],\\ [8. 7. 7. 8. 9. 9. 8.],\\ [8. 7. 7. 8. 9. 9. 8.],\\ [5. 4. 4. 5. 6. 6. 5.]]\\ $


| 枚举值 | 描述 | 
| -------- | -------- |
| PADDING_MODE_CONSTANT | 使用常量填充，默认值为0。 | 
| PADDING_MODE_REFLECT | 以数据区的便捷为轴，使填充区和数据区的数据以该轴保持对称。 | 
| PADDING_MODE_SYMMETRIC | 此填充方法类似于&nbsp;PADDING_MODE_REFLECT，它以待填充区和数据区的交界为轴，使待填充区和数据区的数据以该轴保持对称。 | 
| PADDING_MODE_RESERVED | 预留，暂未使用。 | 


### PadMode

  
```
enum PadMode : byte
```

**描述:**

填充类型，需要配合[AvgPoolFusion](_avg_pool_fusion.md)，[AvgPoolFusion](_avg_pool_fusion.md)，[Conv2DFusion](_conv2_d_fusion.md)，[MaxPoolFusion](_max_pool_fusion.md)使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PAD_MODE_PAD | 在输入的高度和宽度方向上填充0。&nbsp;若设置该模式，算子的padding参数必须大于等于0。 | 
| PAD_MODE_SAME | 输出的高度和宽度分别与输入整除&nbsp;stride&nbsp;后的值相同。&nbsp;若设置该模式，算子的padding参数必须为0。 | 
| PAD_MODE_VALID | 在不填充的前提下返回有效计算所得的输出。不满足计算的多余像素会被丢弃。&nbsp;若设置此模式，则算子的padding参数必须为0。 | 


### PerformanceMode

  
```
enum PerformanceMode : int
```

**描述:**

芯片执行AI计算的性能模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PERFORMANCE_NONE | 不指定任何性能模式，具体运行模式由芯片定义 | 
| PERFORMANCE_LOW | 低性能模式，执行AI计算速度慢，功耗低 | 
| PERFORMANCE_MEDIUM | 中性能模式，执行AI计算速度较慢，功耗较低 | 
| PERFORMANCE_HIGH | 高性能模式，执行AI计算速度较快，功耗较高 | 
| PERFORMANCE_EXTREME | 最高性能模式，执行AI计算速度快，功耗高 | 


### Priority

  
```
enum Priority : int
```

**描述:**

AI计算任务的优先级。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PRIORITY_NONE | 不指定任何任务优先级，具体执行策略由芯片定义 | 
| PRIORITY_LOW | 低优先级，若有更高优先级的任务，芯片会执行更高优先级的任务 | 
| PRIORITY_MEDIUM | 中等优先级，若有更高优先级的任务，芯片会执行更高优先级的任务 | 
| PRIORITY_HIGH | 高优先级，高优先级任务最先执行 | 


### QuantType

  
```
enum QuantType : byte
```

**描述:**

量化类型。需要配合[Node](_node.md)使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| QUANT_TYPE_NONE | 不使用量化 | 
| QUANT_TYPE_ALL | int8全量化 | 


### ReduceMode

  
```
enum ReduceMode : byte
```

**描述:**

用于维度移除的方法，需要配合[ReduceFusion](_reduce_fusion.md)算子使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| REDUCE_MODE_MEAN | 使用指定维度所有元素的平均值代替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_MAX | 使用指定维度所有元素的最大值代替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_MIN | 使用指定维度所有元素的最小值代替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_PROD | 使用指定维度所有元素的乘积代替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_SUM | 使用指定维度所有元素的加和代替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_SUM_SQUARE | 使用指定维度所有元素的平方和替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_ASUM | 使用指定维度所有元素的绝对值和代替该维度的其他元素，以移除该维度。 | 
| REDUCE_MODE_ALL | 使用指定维度所有元素的逻辑与代替该维度的其他元素，以移除该维度。 | 


### ResizeMethod

  
```
enum ResizeMethod : byte
```

**描述:**

调整尺寸的方法。需要配合[Resize](_resize.md)算子使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| RESIZE_METHOD_UNKNOWN | 未知，默认值。 | 
| RESIZE_METHOD_LINEAR | 双线性插值。&nbsp;假设需要计算未知函数f在点$&nbsp;(x,y)&nbsp;$的值其中$&nbsp;x_1&nbsp;&lt;&nbsp;x&nbsp;&lt;&nbsp;x_2,&nbsp;y_1&nbsp;&lt;&nbsp;y&nbsp;&lt;&nbsp;y_2$，并且已知四个坐标点的值$&nbsp;Q_{11}&nbsp;=&nbsp;(x_1,&nbsp;y_1),&nbsp;Q_{12}&nbsp;=&nbsp;(x1,&nbsp;y2),&nbsp;Q_{21}&nbsp;=&nbsp;(x_2,&nbsp;y_1)，Q_{22}&nbsp;=&nbsp;(x_2,&nbsp;y_2)&nbsp;$，并且$&nbsp;f(Q_{11}),f(Q_{12}),f(Q_{21}),f(Q_{22})&nbsp;$表示四个点的数值，则通过如下公式可计算$&nbsp;f(x,y)&nbsp;$的值：<br/>$&nbsp;f(x,y_1)&nbsp;=&nbsp;\frac{x_2-x}{x_2-x_1}f(Q_{11})+\frac{x-x_1}{x_2-x_1}f(Q_{21})&nbsp;$<br/>$&nbsp;f(x,y_2)&nbsp;=&nbsp;\frac{x_2-x}{x_2-x_1}f(Q_{12})+\frac{x-x_1}{x_2-x_1}f(Q_{22})&nbsp;$<br/>$&nbsp;f(x,y)&nbsp;=&nbsp;\frac{y_2-y}{y_2-y_1}f(x,y_1)+\frac{y-y_1}{y_2-y_1}f(x,y_2)&nbsp;$ | 
| RESIZE_METHOD_NEAREST | 最近临近插值。假设需要计算未知函数f在点$&nbsp;(x,y)&nbsp;$的值其中$&nbsp;x_1&nbsp;&lt;&nbsp;x&nbsp;&lt;x_2,&nbsp;y_1&nbsp;&lt;&nbsp;y&nbsp;&lt;&nbsp;y_2&nbsp;$，并且已知四个坐标点的值$&nbsp;Q_{11}&nbsp;=&nbsp;(x_1,&nbsp;y_1),&nbsp;Q_{12}&nbsp;=&nbsp;(x1,&nbsp;y2),&nbsp;Q_{21}&nbsp;=&nbsp;(x_2,&nbsp;y_1)，Q_{22}&nbsp;=&nbsp;(x_2,&nbsp;y_2)&nbsp;$，则从4个点中选择距离点$&nbsp;(x,y)&nbsp;$最近的点的数值作为$&nbsp;f(x,y)&nbsp;$的值。 | 
| RESIZE_METHOD_CUBIC | 双三次插值。&nbsp;双三次插值是取采样点周围16个点的值的加权平均来计算采样点的数值。该参数需要配合[Resize](_resize.md)的cubicCoeff和coordinateTransformMode参数使用。&nbsp;当coordinateTransformMode==COORDINATE_TRANSFORM_MODE_HALF_PIXEL时,cubicCoeff=-0.5，其他情况cubicCoeff=-0.75。插值函数的权重函数如下：<br/>$&nbsp;W(x)&nbsp;=&nbsp;\begin{cases}&nbsp;(cubicCoeff+2)\|x\|^3&nbsp;-&nbsp;(cubicCoeff+3)\|x\|^2&nbsp;+1&nbsp;,&nbsp;&amp;\text{if&nbsp;}&nbsp;\|x\|&nbsp;\leq&nbsp;1;&nbsp;\cr&nbsp;cubicCoeff\|x\|^3&nbsp;-&nbsp;5cubicCoeff\|x\|^2&nbsp;+&nbsp;8cubicCoeff\|x\|&nbsp;-&nbsp;4a,&nbsp;&amp;\text{if&nbsp;}&nbsp;1&nbsp;\lt&nbsp;\|x\|&nbsp;\leq&nbsp;2;&nbsp;\cr&nbsp;0,&nbsp;&amp;\text{otherwise.}&nbsp;\end{cases}&nbsp;$ | 


### RoundMode

  
```
enum RoundMode : byte
```

**描述:**

小数取整算法，需要配合[AvgPoolFusion](_avg_pool_fusion.md)算子使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ROUND_MODE_FLOOR | 向下取临近的整数，例如23.5取整为23，−23.5取整为−24 | 
| ROUND_MODE_CEIL | 向上取临近的整数整，例如23.5取整为24，−23.5取整为−23 | 
