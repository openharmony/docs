# NnrtTypes.idl


## 概述

该文件定义了HDI接口中用到的类型。

模块包路径：ohos.hdi.nnrt.v1_0

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[SharedBuffer](_shared_buffer_v10.md) | 共享内存数据的结构体。 | 
| struct&nbsp;&nbsp;[ModelConfig](_model_config_v10.md) | 定义编译模型需要的参数配置。 | 
| struct&nbsp;&nbsp;[QuantParam](_quant_param_v10.md) | 量化参数结构体。 | 
| struct&nbsp;&nbsp;[IOTensor](_i_o_tensor_v10.md) | AI模型的输入输出张量。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DeviceType](_n_n_rt_v10.md#devicetype) : int { OTHER , CPU , GPU , ACCELERATOR } | AI计算芯片的类型。 | 
| [DeviceStatus](_n_n_rt_v10.md#devicestatus) : int { AVAILABLE , BUSY , OFFLINE , UNKNOWN } | 用于AI计算芯片的状态。 | 
| [PerformanceMode](_n_n_rt_v10.md#performancemode) : int {<br/>PERFORMANCE_NONE , PERFORMANCE_LOW , PERFORMANCE_MEDIUM , PERFORMANCE_HIGH , PERFORMANCE_EXTREME<br/>} | 芯片执行AI计算的性能模式。 | 
| [Priority](_n_n_rt_v10.md#priority) : int { PRIORITY_NONE , PRIORITY_LOW , PRIORITY_MEDIUM , PRIORITY_HIGH } | AI计算任务的优先级。 | 
| [Format](_n_n_rt_v10.md#format) : byte { FORMAT_NONE = -1 , FORMAT_NCHW = 0 , FORMAT_NHWC = 1 } | 算子数据排布。需要配合[Tensor](_tensor_v10.md)使用。 | 
| [DataType](_n_n_rt_v10.md#datatype) : byte {<br/>DATA_TYPE_UNKNOWN = 0 , DATA_TYPE_BOOL = 30 , DATA_TYPE_INT8 = 32 , DATA_TYPE_INT16 = 33 , DATA_TYPE_INT32 = 34 , DATA_TYPE_INT64 = 35 , DATA_TYPE_UINT8 = 37 , DATA_TYPE_UINT16 = 38 , DATA_TYPE_UINT32 = 39 , DATA_TYPE_UINT64 = 40 , DATA_TYPE_FLOAT16 = 42 , DATA_TYPE_FLOAT32 = 43 , DATA_TYPE_FLOAT64 = 44<br/>} | 张量的数据类型。需要配合[Tensor](_tensor_v10.md)使用。 | 
| [QuantType](_n_n_rt_v10.md#quanttype) : byte { QUANT_TYPE_NONE , QUANT_TYPE_ALL } | 量化类型。需要配合[Node](_node_v10.md)使用。 | 
| [NodeType](_n_n_rt_v10.md#nodetype) : unsigned int {<br/>NODE_TYPE_NONE = 0 , NODE_TYPE_ACTIVATION = 2 , NODE_TYPE_ADD_FUSION = 5 , NODE_TYPE_ARGMAX_FUSION = 11 , NODE_TYPE_AVGPOOL_FUSION = 17 , NODE_TYPE_BATCH_TO_SPACE_ND = 22 , NODE_TYPE_BIAS_ADD = 23 , NODE_TYPE_CAST = 28 , NODE_TYPE_CONCAT = 31 , NODE_TYPE_CONV2D_FUSION = 35 , NODE_TYPE_CONV2D_TRANSPOSE_FUSION = 36 , NODE_TYPE_DIV_FUSION = 47 , NODE_TYPE_ELTWISE = 52 , NODE_TYPE_EXPAND_DIMS = 56 , NODE_TYPE_FILL = 66 , NODE_TYPE_FULL_CONNECTION = 67 ,<br/>NODE_TYPE_FUSED_BATCH_NORM = 68 , NODE_TYPE_GATHER = 69 , NODE_TYPE_LAYER_NORM_FUSION = 75 , NODE_TYPE_LESS_EQUAL = 78 ,<br/>NODE_TYPE_MATMUL_FUSION = 89 , NODE_TYPE_MAXIMUM = 90 , NODE_TYPE_MAX_POOL_FUSION = 92 , NODE_TYPE_MUL_FUSION = 99 ,<br/>NODE_TYPE_ONE_HOT = 105 , NODE_TYPE_PAD_FUSION = 107 , NODE_TYPE_POW_FUSION = 110 , NODE_TYPE_PRELU_FUSION = 112 ,<br/>NODE_TYPE_QUANT_DTYPE_CAST = 113 , NODE_TYPE_REDUCE_FUSION = 118 , NODE_TYPE_RESHAPE = 119 , NODE_TYPE_RESIZE = 120 ,<br/>NODE_TYPE_RSQRT = 126 , NODE_TYPE_SCALE_FUSION = 127 , NODE_TYPE_SHAPE = 130 , NODE_TYPE_SLICE_FUSION = 135 ,<br/>NODE_TYPE_SOFTMAX = 138 , NODE_TYPE_SPACE_TO_BATCH_ND = 141 , NODE_TYPE_SPLIT = 145 , NODE_TYPE_SQRT = 146 ,<br/>NODE_TYPE_SQUEEZE = 147 , NODE_TYPE_SQUARED_DIFFERENCE = 149 , NODE_TYPE_STACK = 150 , NODE_TYPE_STRIDED_SLICE = 151 ,<br/>NODE_TYPE_SUB_FUSION = 152 , NODE_TYPE_TILE_FUSION = 160 , NODE_TYPE_TOPK_FUSION = 161 , NODE_TYPE_TRANSPOSE = 162 , NODE_TYPE_UNSQUEEZE = 165<br/>} | 算子类型。 | 
| [ResizeMethod](_n_n_rt_v10.md#resizemethod) : byte { RESIZE_METHOD_UNKNOWN = -1 , RESIZE_METHOD_LINEAR = 0 , RESIZE_METHOD_NEAREST = 1 , RESIZE_METHOD_CUBIC = 2 } | 调整尺寸的方法。需要配合[Resize](_resize_v10.md)算子使用。 | 
| [CoordinateTransformMode](_n_n_rt_v10.md#coordinatetransformmode) : byte { COORDINATE_TRANSFORM_MODE_ASYMMETRIC = 0 , COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS = 1 , COORDINATE_TRANSFORM_MODE_HALF_PIXEL = 2 } | 坐标变换模式，仅[Resize](_resize_v10.md)算子使用这些枚举。 以变换 Width 为例， 记 new_i 为resize之后的Tenosr沿x轴的第i个坐标； 记 old_i 为输入Tensor沿x的轴的对应坐标； 记 newWidth 是resize之后的Tensor沿着x的轴的长度； 记 oldWidth 是输入tensor沿x的轴的长度。 可以通过下面的公式计算出 old_i : | 
| [NearestMode](_n_n_rt_v10.md#nearestmode) : byte {<br/>NEAREST_MODE_NORMAL = 0 , NEAREST_MODE_ROUND_HALF_DOWN = 1 , NEAREST_MODE_ROUND_HALF_UP = 2 , NEAREST_MODE_FLOOR = 3 , NEAREST_MODE_CEIL = 4<br/>} | 临近算法类型。需要配合[Resize](_resize_v10.md)算子使用。 | 
| [ActivationType](_n_n_rt_v10.md#activationtype) : byte {<br/>ACTIVATION_TYPE_NO_ACTIVATION = 0 , ACTIVATION_TYPE_RELU = 1 , ACTIVATION_TYPE_SIGMOID = 2 , ACTIVATION_TYPE_RELU6 = 3 , ACTIVATION_TYPE_ELU = 4 , ACTIVATION_TYPE_LEAKY_RELU = 5 , ACTIVATION_TYPE_ABS = 6 , ACTIVATION_TYPE_RELU1 = 7 , ACTIVATION_TYPE_SOFTSIGN = 8 , ACTIVATION_TYPE_SOFTPLUS = 9 , ACTIVATION_TYPE_TANH = 10 , ACTIVATION_TYPE_SELU = 11 , ACTIVATION_TYPE_HSWISH = 12 , ACTIVATION_TYPE_HSIGMOID = 13 , ACTIVATION_TYPE_THRESHOLDRELU = 14 , ACTIVATION_TYPE_LINEAR = 15 , ACTIVATION_TYPE_HARD_TANH = 16 , ACTIVATION_TYPE_SIGN = 17 , ACTIVATION_TYPE_SWISH = 18 , ACTIVATION_TYPE_GELU = 19 , ACTIVATION_TYPE_UNKNOWN = 20<br/>} | 激活函数类型。激活函数使得神经网络模型具有区分非线性函数的能力，这也让神经网络模型可以被应用于众多非线性模型中。 [NodeAttrTypes.idl](_node_attr_types_8idl_v10.md)文件中拥有ActivationType类型的参数的算子会在运行完成算子的运算之后执行相对应的激活函数。 | 
| [ReduceMode](_n_n_rt_v10.md#reducemode) : byte {<br/>REDUCE_MODE_MEAN = 0 , REDUCE_MODE_MAX = 1 , REDUCE_MODE_MIN = 2 , REDUCE_MODE_PROD = 3 , REDUCE_MODE_SUM = 4 , REDUCE_MODE_SUM_SQUARE = 5 , REDUCE_MODE_ASUM = 6 , REDUCE_MODE_ALL = 7<br/>} | 用于维度移除的方法，需要配合[ReduceFusion](_reduce_fusion_v10.md)算子使用。 | 
| [EltwiseMode](_n_n_rt_v10.md#eltwisemode) : byte { ELTWISE_MODE_PROD = 0 , ELTWISE_MODE_SUM = 1 , ELTWISE_MODE_MAXIMUM = 2 , ELTWISE_MODE_UNKNOWN = 3 } | 元素级别运算支持的计算类型，需要配合[Eltwise](_eltwise_v10.md)算子使用。 | 
| [PadMode](_n_n_rt_v10.md#padmode) : byte { PAD_MODE_PAD = 0 , PAD_MODE_SAME = 1 , PAD_MODE_VALID = 2 } | 填充类型，需要配合[AvgPoolFusion](_avg_pool_fusion_v10.md)，[AvgPoolFusion](_avg_pool_fusion_v10.md)，[Conv2DFusion](_conv2_d_fusion_v10.md)，[MaxPoolFusion](_max_pool_fusion_v10.md)使用。 | 
| [RoundMode](_n_n_rt_v10.md#roundmode) : byte { ROUND_MODE_FLOOR = 0 , ROUND_MODE_CEIL = 1 } | 小数取整算法，需要配合[AvgPoolFusion](_avg_pool_fusion_v10.md)算子使用。 | 
| [PaddingMode](_n_n_rt_v10.md#paddingmode) : byte { PADDING_MODE_CONSTANT = 0 , PADDING_MODE_REFLECT = 1 , PADDING_MODE_SYMMETRIC = 2 , PADDING_MODE_RESERVED = 3 } | 填充类型，需要配合[PadFusion](_pad_fusion_v10.md)算子使用。 | 
