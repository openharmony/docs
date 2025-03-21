# NNRt (V1_0)

## 概述

Neural Network Runtime（NNRt, 神经网络运行时）是面向AI领域的跨芯片推理计算运行时，作为中间桥梁连通上层AI推理框架和底层加速芯片，实现AI模型的跨芯片推理计算。提供统一AI芯片驱动接口，实现AI芯片驱动接入OpenHarmony。

**起始版本：** 3.2

## 汇总

### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [INnrtDevice.idl](_i_nnrt_device_8idl_v10.md) | 该文件定义芯片设备相关的接口。 | 
| [IPreparedModel.idl](_i_prepared_model_8idl_v10.md) | 该文件定义了AI模型推理和导出编译后模型的接口。 | 
| [ModelTypes.idl](_model_types_8idlv.md) | 该文件定义AI模型相关的结构体。 | 
| [NnrtTypes.idl](_nnrt_types_8idl_v10.md) | 该文件定义了HDI接口中用到的类型。 | 
| [NodeAttrTypes.idl](_node_attr_types_8idl_v10.md) | 该文件定义AI模型算子的参数和功能。 | 

### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[INnrtDevice](interface_i_nnrt_device_v10.md) | 定义了与设备相关的接口，实现设备管理和模型编译等操作。 | 
| interface&nbsp;&nbsp;[IPreparedModel](interface_i_prepared_model_v10.md) | 定义模型编译后的对象，包含编译后模型导出、模型推理接口。 | 
| struct&nbsp;&nbsp;[Tensor](_tensor_v10.md) | 张量结构体。 | 
| struct&nbsp;&nbsp;[Node](_node_v10.md) | 算子节点结构体。 | 
| struct&nbsp;&nbsp;[SubGraph](_sub_graph_v10.md) | 子图结构体。 | 
| struct&nbsp;&nbsp;[Model](_model_v10.md) | 模型结构体。 | 
| struct&nbsp;&nbsp;[SharedBuffer](_shared_buffer_v10.md) | 共享内存数据的结构体。 | 
| struct&nbsp;&nbsp;[ModelConfig](_model_config_v10.md) | 定义编译模型需要的参数配置。 | 
| struct&nbsp;&nbsp;[QuantParam](_quant_param_v10.md) | 量化参数结构体。 | 
| struct&nbsp;&nbsp;[IOTensor](_i_o_tensor_v10.md) | AI模型的输入输出张量。 | 
| struct&nbsp;&nbsp;[Activation](_activation_v10.md) | 激活类型的算子，所有的激活函数都属于该算子，具体的激活函数类型依据参数来确定。 | 
| struct&nbsp;&nbsp;[AddFusion](_add_fusion_v10.md) | 输入Tensor逐元素相加， 输出x和y的和，数据形状与输入broadcast之后一样，数据类型与较高精度的输入精度一致。 | 
| struct&nbsp;&nbsp;[ArgMaxFusion](_arg_max_fusion_v10.md) | 返回跨轴的tensor前K个索引或者是数值。 | 
| struct&nbsp;&nbsp;[AvgPoolFusion](_avg_pool_fusion_v10.md) | 在输入tensor上应用 2D 平均池化。支持int8量化输入。 | 
| struct&nbsp;&nbsp;[BatchToSpaceND](_batch_to_space_n_d_v10.md) | 将一个4维tensor的batch维度按block_shape切分成小块，并将这些小块拼接到空间维度。 | 
| struct&nbsp;&nbsp;[BiasAdd](_bias_add_v10.md) | 对给出的输入张量上的各个维度方向上的数据进行偏置。 | 
| struct&nbsp;&nbsp;[Cast](_cast_v10.md) | 根据输出张量的类型对张量数据类型进行转换。 | 
| struct&nbsp;&nbsp;[Concat](_concat_v10.md) | 在指定轴上连接张量，将输入张量按给定的轴连接起来。 | 
| struct&nbsp;&nbsp;[Conv2DFusion](_conv2_d_fusion_v10.md) | 对将4维的tensor执行带有偏置的二维卷积运算。 | 
| struct&nbsp;&nbsp;[Conv2dTransposeFusion](_conv2d_transpose_fusion_v10.md) | 对一个4维的tensor执行带有偏置的二维反卷积。 | 
| struct&nbsp;&nbsp;[DivFusion](_div_fusion_v10.md) | 将两个tensor执行除法运算。 | 
| struct&nbsp;&nbsp;[Eltwise](_eltwise_v10.md) | 元素级别操作的算子。 | 
| struct&nbsp;&nbsp;[ExpandDims](_expand_dims_v10.md) | 在给定轴上为tensor添加一个额外的维度。 | 
| struct&nbsp;&nbsp;[Fill](_fill_v10.md) | 根据指定的维度，创建由一个标量填充的tensor。 | 
| struct&nbsp;&nbsp;[FullConnection](_full_connection_v10.md) | 对输入数据做全连接。 | 
| struct&nbsp;&nbsp;[FusedBatchNorm](_fused_batch_norm_v10.md) | 对一个tensor进行批标准化的运算。 | 
| struct&nbsp;&nbsp;[Gather](_gather_v10.md) | 根据指定的索引和轴返回输入tensor的切片。 | 
| struct&nbsp;&nbsp;[LayerNormFusion](_layer_norm_fusion_v10.md) | 对一个tensor从某一axis开始做层归一化。 | 
| struct&nbsp;&nbsp;[LessEqual](_less_equal_v10.md) | 对输入x1和x2，计算每对元素的x1&lt;=x2的结果。 | 
| struct&nbsp;&nbsp;[MatMulFusion](_mat_mul_fusion_v10.md) | 对输入x1和x2，计算x1和x2的内积。 | 
| struct&nbsp;&nbsp;[Maximum](_maximum_v10.md) | 对输入x1和x2，计算x1和x2对应元素最大值，x1和x2的输入遵守隐式类型转换规则，使数据类型一致。 | 
| struct&nbsp;&nbsp;[MaxPoolFusion](_max_pool_fusion_v10.md) | 对输入x，计算 2D 最大值池化。 | 
| struct&nbsp;&nbsp;[MulFusion](_mul_fusion_v10.md) | 对输入x1和x2，将x1和x2相同的位置的元素相乘得到output。 | 
| struct&nbsp;&nbsp;[OneHot](_one_hot_v10.md) | 根据indices指定的位置，生成一个由one-hot向量构成的tensor。 | 
| struct&nbsp;&nbsp;[PadFusion](_pad_fusion_v10.md) | 在x指定维度的数据前后，添加指定数值进行增广。 | 
| struct&nbsp;&nbsp;[PowFusion](_pow_fusion_v10.md) | 求x的y次幂，输入必须是两个tensor或一个tensor和一个标量。 | 
| struct&nbsp;&nbsp;[PReLUFusion](_p_re_l_u_fusion_v10.md) | 计算x和weight的PReLU激活值。 | 
| struct&nbsp;&nbsp;[QuantDTypeCast](_quant_d_type_cast_v10.md) | 数据类型转换。 | 
| struct&nbsp;&nbsp;[ReduceFusion](_reduce_fusion_v10.md) | 减小x张量的维度。 | 
| struct&nbsp;&nbsp;[Reshape](_reshape_v10.md) | 根据inputShape调整input的形状。 | 
| struct&nbsp;&nbsp;[Resize](_resize_v10.md) | 按给定的参数对输入的张量进行变形。 | 
| struct&nbsp;&nbsp;[Rsqrt](_rsqrt_v10.md) | 求x的平方根的倒数。 | 
| struct&nbsp;&nbsp;[ScaleFusion](_scale_fusion_v10.md) | 给定一个tensor，计算其缩放后的值。 | 
| struct&nbsp;&nbsp;[Shape](_shape_v10.md) | 输出输入tensor的形状。 | 
| struct&nbsp;&nbsp;[SliceFusion](_slice_fusion_v10.md) | 在x各维度，在axes维度中，以begin为起点，截取size长度的切片。 | 
| struct&nbsp;&nbsp;[Softmax](_softmax_v10.md) | 给定一个tensor，计算其softmax结果。 | 
| struct&nbsp;&nbsp;[SpaceToBatchND](_space_to_batch_n_d_v10.md) | 将4维张量在空间维度上进行切分成多个小块，然后在batch维度上拼接这些小块。 | 
| struct&nbsp;&nbsp;[Split](_split_v10.md) | 算子沿 axis 维度将x拆分成多个张量，张量数量由outputNum指定。 | 
| struct&nbsp;&nbsp;[Sqrt](_sqrt_v10.md) | 给定一个tensor，计算其平方根。 | 
| struct&nbsp;&nbsp;[SquaredDifference](_squared_difference_v10.md) | 计算两个输入的差值并返回差值的平方。SquaredDifference算子支持tensor和tensor相减。 | 
| struct&nbsp;&nbsp;[Squeeze](_squeeze_v10.md) | 去除axis中，长度为1的维度。支持int8量化输入。 | 
| struct&nbsp;&nbsp;[Stack](_stack_v10.md) | 将一组tensor沿axis维度进行堆叠，堆叠前每个tensor的维数为n，则堆叠后output维数为n+1。 | 
| struct&nbsp;&nbsp;[StridedSlice](_strided_slice_v10.md) | 根据步长和索引对输入张量进行切片提取。 | 
| struct&nbsp;&nbsp;[SubFusion](_sub_fusion_v10.md) | 计算两个输入的差值。 | 
| struct&nbsp;&nbsp;[TileFusion](_tile_fusion_v10.md) | 以multiples指定的次数拷贝输入张量。 | 
| struct&nbsp;&nbsp;[TopKFusion](_top_k_fusion_v10.md) | 查找沿axis轴的前K个最大值和对应索引。 | 
| struct&nbsp;&nbsp;[Transpose](_transpose_v10.md) | 根据perm对x进行数据重排。 | 
| struct&nbsp;&nbsp;[Unsqueeze](_unsqueeze_v10.md) | 根据输入axis的值。增加一个维度。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DeviceType](#devicetype) : int { OTHER , CPU , GPU , ACCELERATOR } | AI计算芯片的类型。 | 
| [DeviceStatus](#devicestatus) : int { AVAILABLE , BUSY , OFFLINE , UNKNOWN } | 用于AI计算芯片的状态。 | 
| [PerformanceMode](#performancemode) : int {<br/>PERFORMANCE_NONE , PERFORMANCE_LOW , PERFORMANCE_MEDIUM , PERFORMANCE_HIGH , PERFORMANCE_EXTREME<br/>} | 芯片执行AI计算的性能模式。 | 
| [Priority](#priority) : int { PRIORITY_NONE , PRIORITY_LOW , PRIORITY_MEDIUM , PRIORITY_HIGH } | AI计算任务的优先级。 | 
| [Format](#format) : byte { FORMAT_NONE = -1 , FORMAT_NCHW = 0 , FORMAT_NHWC = 1 } | 算子数据排布。需要配合[Tensor](_tensor_v10.md)使用。 | 
| [DataType](#datatype) : byte {<br/>DATA_TYPE_UNKNOWN = 0 , DATA_TYPE_BOOL = 30 , DATA_TYPE_INT8 = 32 , DATA_TYPE_INT16 = 33 , DATA_TYPE_INT32 = 34 , DATA_TYPE_INT64 = 35 , DATA_TYPE_UINT8 = 37 , DATA_TYPE_UINT16 = 38 , DATA_TYPE_UINT32 = 39 , DATA_TYPE_UINT64 = 40 , DATA_TYPE_FLOAT16 = 42 , DATA_TYPE_FLOAT32 = 43 , DATA_TYPE_FLOAT64 = 44<br/>} | 张量的数据类型。需要配合[Tensor](_tensor_v10.md)使用。 | 
| [QuantType](#quanttype) : byte { QUANT_TYPE_NONE , QUANT_TYPE_ALL } | 量化类型。需要配合[Node](_node_v10.md)使用。 | 
| [NodeType](#nodetype) : unsigned int {<br/>NODE_TYPE_NONE = 0 , NODE_TYPE_ACTIVATION = 2 , NODE_TYPE_ADD_FUSION = 5 , NODE_TYPE_ARGMAX_FUSION = 11 , NODE_TYPE_AVGPOOL_FUSION = 17 , NODE_TYPE_BATCH_TO_SPACE_ND = 22 , NODE_TYPE_BIAS_ADD = 23 , NODE_TYPE_CAST = 28 , NODE_TYPE_CONCAT = 31 , NODE_TYPE_CONV2D_FUSION = 35 , NODE_TYPE_CONV2D_TRANSPOSE_FUSION = 36 , NODE_TYPE_DIV_FUSION = 47 , NODE_TYPE_ELTWISE = 52 , NODE_TYPE_EXPAND_DIMS = 56 , NODE_TYPE_FILL = 66 , NODE_TYPE_FULL_CONNECTION = 67 ,<br/>NODE_TYPE_FUSED_BATCH_NORM = 68 , NODE_TYPE_GATHER = 69 , NODE_TYPE_LAYER_NORM_FUSION = 75 , NODE_TYPE_LESS_EQUAL = 78 ,<br/>NODE_TYPE_MATMUL_FUSION = 89 , NODE_TYPE_MAXIMUM = 90 , NODE_TYPE_MAX_POOL_FUSION = 92 , NODE_TYPE_MUL_FUSION = 99 ,<br/>NODE_TYPE_ONE_HOT = 105 , NODE_TYPE_PAD_FUSION = 107 , NODE_TYPE_POW_FUSION = 110 , NODE_TYPE_PRELU_FUSION = 112 ,<br/>NODE_TYPE_QUANT_DTYPE_CAST = 113 , NODE_TYPE_REDUCE_FUSION = 118 , NODE_TYPE_RESHAPE = 119 , NODE_TYPE_RESIZE = 120 ,<br/>NODE_TYPE_RSQRT = 126 , NODE_TYPE_SCALE_FUSION = 127 , NODE_TYPE_SHAPE = 130 , NODE_TYPE_SLICE_FUSION = 135 ,<br/>NODE_TYPE_SOFTMAX = 138 , NODE_TYPE_SPACE_TO_BATCH_ND = 141 , NODE_TYPE_SPLIT = 145 , NODE_TYPE_SQRT = 146 ,<br/>NODE_TYPE_SQUEEZE = 147 , NODE_TYPE_SQUARED_DIFFERENCE = 149 , NODE_TYPE_STACK = 150 , NODE_TYPE_STRIDED_SLICE = 151 ,<br/>NODE_TYPE_SUB_FUSION = 152 , NODE_TYPE_TILE_FUSION = 160 , NODE_TYPE_TOPK_FUSION = 161 , NODE_TYPE_TRANSPOSE = 162 , NODE_TYPE_UNSQUEEZE = 165<br/>} | 算子类型。 | 
| [ResizeMethod](#resizemethod) : byte { RESIZE_METHOD_UNKNOWN = -1 , RESIZE_METHOD_LINEAR = 0 , RESIZE_METHOD_NEAREST = 1 , RESIZE_METHOD_CUBIC = 2 } | 调整尺寸的方法。需要配合[Resize](_resize_v10.md)算子使用。 | 
| [CoordinateTransformMode](#coordinatetransformmode) : byte { COORDINATE_TRANSFORM_MODE_ASYMMETRIC = 0 , COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS = 1 , COORDINATE_TRANSFORM_MODE_HALF_PIXEL = 2 } | 坐标变换模式，仅[Resize](_resize_v10.md)算子使用这些枚举。 | 
| [NearestMode](#nearestmode) : byte {<br/>NEAREST_MODE_NORMAL = 0 , NEAREST_MODE_ROUND_HALF_DOWN = 1 , NEAREST_MODE_ROUND_HALF_UP = 2 , NEAREST_MODE_FLOOR = 3 , NEAREST_MODE_CEIL = 4<br/>} | 临近算法类型。需要配合[Resize](_resize_v10.md)算子使用。 | 
| [ActivationType](#activationtype) : byte {<br/>ACTIVATION_TYPE_NO_ACTIVATION = 0 , ACTIVATION_TYPE_RELU = 1 , ACTIVATION_TYPE_SIGMOID = 2 , ACTIVATION_TYPE_RELU6 = 3 , ACTIVATION_TYPE_ELU = 4 , ACTIVATION_TYPE_LEAKY_RELU = 5 , ACTIVATION_TYPE_ABS = 6 , ACTIVATION_TYPE_RELU1 = 7 , ACTIVATION_TYPE_SOFTSIGN = 8 , ACTIVATION_TYPE_SOFTPLUS = 9 , ACTIVATION_TYPE_TANH = 10 , ACTIVATION_TYPE_SELU = 11 , ACTIVATION_TYPE_HSWISH = 12 , ACTIVATION_TYPE_HSIGMOID = 13 , ACTIVATION_TYPE_THRESHOLDRELU = 14 , ACTIVATION_TYPE_LINEAR = 15 , ACTIVATION_TYPE_HARD_TANH = 16 , ACTIVATION_TYPE_SIGN = 17 , ACTIVATION_TYPE_SWISH = 18 , ACTIVATION_TYPE_GELU = 19 , ACTIVATION_TYPE_UNKNOWN = 20<br/>} | 激活函数类型。 | 
| [ReduceMode](#reducemode) : byte {<br/>REDUCE_MODE_MEAN = 0 , REDUCE_MODE_MAX = 1 , REDUCE_MODE_MIN = 2 , REDUCE_MODE_PROD = 3 , REDUCE_MODE_SUM = 4 , REDUCE_MODE_SUM_SQUARE = 5 , REDUCE_MODE_ASUM = 6 , REDUCE_MODE_ALL = 7<br/>} | 用于维度移除的方法，需要配合[ReduceFusion](_reduce_fusion_v10.md)算子使用。 | 
| [EltwiseMode](#eltwisemode) : byte { ELTWISE_MODE_PROD = 0 , ELTWISE_MODE_SUM = 1 , ELTWISE_MODE_MAXIMUM = 2 , ELTWISE_MODE_UNKNOWN = 3 } | 元素级别运算支持的计算类型，需要配合[Eltwise](_eltwise_v10.md)算子使用。 | 
| [PadMode](#padmode) : byte { PAD_MODE_PAD = 0 , PAD_MODE_SAME = 1 , PAD_MODE_VALID = 2 } | 填充类型，需要配合[AvgPoolFusion](_avg_pool_fusion_v10.md)，[AvgPoolFusion](_avg_pool_fusion_v10.md)，[Conv2DFusion](_conv2_d_fusion_v10.md)，[MaxPoolFusion](_max_pool_fusion_v10.md)使用。 | 
| [RoundMode](#roundmode) : byte { ROUND_MODE_FLOOR = 0 , ROUND_MODE_CEIL = 1 } | 小数取整算法，需要配合[AvgPoolFusion](_avg_pool_fusion_v10.md)算子使用。 | 
| [PaddingMode](#paddingmode) : byte { PADDING_MODE_CONSTANT = 0 , PADDING_MODE_REFLECT = 1 , PADDING_MODE_SYMMETRIC = 2 , PADDING_MODE_RESERVED = 3 } | 填充类型，需要配合[PadFusion](_pad_fusion_v10.md)算子使用。 | 

## 枚举类型说明

### ActivationType

```
enum ActivationType : byte
```

**描述**

激活函数类型。

激活函数使得神经网络模型具有区分非线性函数的能力，这也让神经网络模型可以被应用于众多非线性模型中。 [NodeAttrTypes.idl](_node_attr_types_8idl_v10.md)文件中拥有ActivationType类型的参数的算子会在运行完成算子的运算之后执行相对应的激活函数。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ACTIVATION_TYPE_NO_ACTIVATION | 无激活函数。 | 
| ACTIVATION_TYPE_RELU | ReLU激活函数。<br/>逐元素求$ max(x_i, 0) $，负数输出值会被修改为0，正数输出不受影响。<br/>$ \text{ReLU}(x_i) = (x_i)^+ = \max(x_i, 0),$<br/>其中$ x_i $是输入元素。 | 
| ACTIVATION_TYPE_SIGMOID | Sigmoid激活函数。<br/>按元素计算Sigmoid激活函数。Sigmoid函数定义为：<br/>$ \text{Sigmoid}(x_i) = \frac{1}{1 + \exp(-x_i)} $<br/>其中$ x_i $是输入的元素。 | 
| ACTIVATION_TYPE_RELU6 | ReLU6激活函数。<br/>ReLU6类似于ReLU，不同之处在于设置了上限，其上限为6，如果输入大于6，输出会被限制为6。ReLU6函数定义为：<br/>$ \text{ReLU6}(x_i) = \min(\max(0, x_i), 6) $<br/>其中$ x_i $是输入的元素。 | 
| ACTIVATION_TYPE_ELU | 指数线性单元激活函数（Exponential Linear Unit activation function，ELU）激活函数。<br/>对输入的每个元素计算ELU。ELU函数定义为：<br/>$ ELU(x_{i}) = \begin{cases} x_i, &amp;\text{if } x_i \geq 0; \cr \alpha \* (\exp(x_i) - 1), &amp;\text{otherwise.} \end{cases} $<br/>其中，$ x_i $表示输入的元素，$ \alpha $表示alpha参数，该参数通过[Activation](_activation_v10.md)进行设置。 | 
| ACTIVATION_TYPE_LEAKY_RELU | LeakyReLU激活函数。<br/>LeakyReLU函数定义为：<br/>$ \text{LeakyReLU}(x_i) = \begin{cases} x_i, &amp;\text{if } x_i \geq 0; \cr {\alpha} \* x_i, &amp;\text{otherwise.} \end{cases}$<br/>其中，$ x_i $表示输入的元素，$ \alpha $表示alpha参数，该参数通过[Activation](_activation_v10.md)进行设置。 | 
| ACTIVATION_TYPE_ABS | 计算绝对值的激活函数。<br/>函数定义为：<br/>$ \text{abs}(x_i) = \|x_i\| $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_RELU1 | ReLU1激活函数。<br/>ReLU1函数定义为：<br/>$ \text{ReLU1}(x_i)= \min(\max(0, x_i), 1) $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_SOFTSIGN | SoftSign激活函数。<br/>SoftSign函数定义如下：<br/>$ \text{SoftSign}(x_i) = \frac{x_i}{1 + \|x_i\|} $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_SOFTPLUS | Softplus激活函数。<br/>Softplus为ReLU函数的平滑近似。可对一组数值使用来确保转换后输出结果均为正值。Softplus函数定义如下：<br/>$ \text{Softplus}(x_i) = \log(1 + \exp(x_i)) $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_TANH | Tanh激活函数。<br/>Tanh函数定义如下：<br/>$ tanh(x) = \frac{\exp(x_i) - \exp(-x_i)}{\exp(x_i) + \exp(-x_i)} = \frac{\exp(2x_i) - 1}{\exp(2x_i) + 1} $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_SELU | SELU（Scaled exponential Linear Unit）激活函数。<br/>SELU函数定义如下：<br/>$ SELU(x_{i}) = scale \* \begin{cases} x_{i}, &amp;\text{if } x_{i} \geq 0; \cr \text{alpha} \* (\exp(x_i) - 1), &amp;\text{otherwise.} \end{cases} $<br/>其中，$ x_i $是输入元素，$ \alpha $和$ scale $是预定义的常量（ $\alpha=1.67326324$，$scale=1.05070098$）。 | 
| ACTIVATION_TYPE_HSWISH | Hard Swish激活函数。<br/>Hard Swish函数定义如下：<br/>$ \text{Hardswish}(x_{i}) = x_{i} \* \frac{ReLU6(x_{i} + 3)}{6} $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_HSIGMOID | Hard Sigmoid激活函数。<br/>Hard Sigmoid函数定义如下：<br/>$ \text{Hardsigmoid}(x_{i}) = max(0, min(1, \frac{x_{i} + 3}{6})) $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_THRESHOLDRELU | ThresholdedReLU激活函数。<br/>类似ReLU激活函数，min数定义如下：<br/>$ \text{ThresholdedReLU}(x_i) = \min(\max(0, x_i), t) $<br/>其中，$ x_i $是输入元素，$ t $是最大值。 | 
| ACTIVATION_TYPE_LINEAR | Linear激活函数。<br/>Linear函数定义如下：<br/>$ \text{Linear}(x_i) = x_i $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_HARD_TANH | HardTanh激活函数。<br/>HardTanh函数定义如下：<br/>$ \text{HardTanh}(x_i) = \begin{cases} \text{max_val} &amp; \text{ if } x_i &gt; \text{ max_val } \\ \text{min_val} &amp; \text{ if } x_i &lt; \text{ min_val } \\ x_i &amp; \text{ otherwise } \\ \end{cases} $<br/>其中，$ x_i $是输入，$ max\_val $是最大值，$ min\_val $是最小值，这两个参数通过[Activation](_activation_v10.md)进行设置。 | 
| ACTIVATION_TYPE_SIGN | Sign激活函数。<br/>Sign函数定义如下：<br/>$ Sign(x_i) = \begin{cases} -1, &amp;if\ x_i &lt; 0 \cr 0, &amp;if\ x_i = 0 \cr 1, &amp;if\ x_i &gt; 0\end{cases} $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_SWISH | Swish激活函数。<br/>Swish激活函数定义如下：<br/>$ \text{Swish}(x_i) = x_i \* Sigmoid(x_i) $<br/>其中，$ x_i $表示输入的元素。 | 
| ACTIVATION_TYPE_GELU | GELU（Gaussian error linear unit activation function）高斯误差线性单元激活函数。<br/>GELU函数定义如下：<br/>$ GELU(x_i) = x_i\*P(X &lt; x_i) $<br/>其中，$ x_i $是输入元素，$ P $是标准高斯分布的累积分布函数。需要通过[Activation](_activation_v10.md)的approximate参数指定是否使用近似。 | 
| ACTIVATION_TYPE_UNKNOWN | 未知 | 

### CoordinateTransformMode

```
enum CoordinateTransformMode : byte
```

**描述**

坐标变换模式，仅[Resize](_resize_v10.md)算子使用这些枚举。

以变换 Width 为例，记 new_i 为resize之后的Tenosr沿x轴的第i个坐标； 记 old_i 为输入Tensor沿x的轴的对应坐标； 记 newWidth 是resize之后的Tensor沿着x的轴的长度； 记 oldWidth 是输入tensor沿x的轴的长度。 可以通过下面的公式计算出 old_i :

- COORDINATE_TRANSFORM_MODE_ASYMMETRIC：
  $ old_i = newWidth != 0 ? new_i \* oldWidth / newWidth : 0 $

- COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS：
  $ old_i = newWidth != 1 ? new_i \* (oldWidth - 1) / (newWidth - 1) $

- COORDINATE_TRANSFORM_MODE_HALF_PIXEL：
  $ old_i = newWidth &gt; 1 ? (new_x + 0.5) \* oldWidth / newWidth - 0.5 : 0 $

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| COORDINATE_TRANSFORM_MODE_ASYMMETRIC | 不进行对齐，直接按照比例缩放。 | 
| COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS | 对齐图像的4个角。 | 
| COORDINATE_TRANSFORM_MODE_HALF_PIXEL | 对齐像素点中心。 | 

### DataType

```
enum DataType : byte
```

**描述**

张量的数据类型。需要配合[Tensor](_tensor_v10.md)使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| DATA_TYPE_UNKNOWN | 数据类型未知。 | 
| DATA_TYPE_BOOL | 数据类型是BOOL。 | 
| DATA_TYPE_INT8 | 数据类型是INT8。 | 
| DATA_TYPE_INT16 | 数据类型是INT16。 | 
| DATA_TYPE_INT32 | 数据类型是INT32。 | 
| DATA_TYPE_INT64 | 数据类型是INT64。 | 
| DATA_TYPE_UINT8 | 数据类型是UINT8。 | 
| DATA_TYPE_UINT16 | 数据类型是UINT16。 | 
| DATA_TYPE_UINT32 | 数据类型是UINT32。 | 
| DATA_TYPE_UINT64 | 数据类型是UINT64。 | 
| DATA_TYPE_FLOAT16 | 数据类型是FLOAT16。 | 
| DATA_TYPE_FLOAT32 | 数据类型是FLOAT32。 | 
| DATA_TYPE_FLOAT64 | 数据类型是FLOAT64。 | 

### DeviceStatus

```
enum DeviceStatus : int
```

**描述**

用于AI计算芯片的状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| AVAILABLE | 芯片当前处于可用状态。 | 
| BUSY | 芯片当前处于忙碌状态，可能无法及时响应计算任务。 | 
| OFFLINE | 芯片当前处于下线状态，无法响应计算任务。 | 
| UNKNOWN | 芯片当前处于未知状态。 | 

### DeviceType

```
enum DeviceType : int
```

**描述**

AI计算芯片的类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| OTHER | 不属于以下类型的芯片。 | 
| CPU | CPU芯片。 | 
| GPU | GPU芯片。 | 
| ACCELERATOR | AI专用加速芯片，比如NPU、DSP。 | 

### EltwiseMode

```
enum EltwiseMode : byte
```

**描述**

元素级别运算支持的计算类型，需要配合[Eltwise](_eltwise_v10.md)算子使用。

**起始版本：** 3.2

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

**描述**

算子数据排布。需要配合[Tensor](_tensor_v10.md)使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| FORMAT_NONE | 用于数据排列，作为Format初始的值。 | 
| FORMAT_NCHW | 数据排列为NCHW。 | 
| FORMAT_NHWC | 数据排列为NHWC。 | 

### NearestMode

```
enum NearestMode : byte
```

**描述**

临近算法类型。需要配合[Resize](_resize_v10.md)算子使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| NEAREST_MODE_NORMAL | 四舍五入取整。 | 
| NEAREST_MODE_ROUND_HALF_DOWN | 向负无穷取整，例如23.5取整为23，−23.5取整为−24。 | 
| NEAREST_MODE_ROUND_HALF_UP | 向正无穷取整，例如23.5取整为24，−23.5取整为−23。 | 
| NEAREST_MODE_FLOOR | 向下取临近的整数，例如23.5取整为23，−23.5取整为−24。 | 
| NEAREST_MODE_CEIL | 向上取临近的整数整，例如23.5取整为24，−23.5取整为−23。 | 

### NodeType

```
enum NodeType : unsigned int
```

**描述**

算子类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_TYPE_NONE | 算子类型为NONE。 | 
| NODE_TYPE_ACTIVATION | 激活函数类型。 | 
| NODE_TYPE_ADD_FUSION | ADD算子。 | 
| NODE_TYPE_ARGMAX_FUSION | ArgMax算子。 | 
| NODE_TYPE_AVGPOOL_FUSION | AVGPOOL算子。 | 
| NODE_TYPE_BATCH_TO_SPACE_ND | BatchToSpaceND算子。 | 
| NODE_TYPE_BIAS_ADD | BiasAdd算子。 | 
| NODE_TYPE_CAST | Cast算子。 | 
| NODE_TYPE_CONCAT | Concat算子。 | 
| NODE_TYPE_CONV2D_FUSION | Conv2D算子，包含了普通卷积、可分离卷积和分组卷积。 | 
| NODE_TYPE_CONV2D_TRANSPOSE_FUSION | 二维反卷积算子。 | 
| NODE_TYPE_DIV_FUSION | Div算子。 | 
| NODE_TYPE_ELTWISE | 元素级别算子。 | 
| NODE_TYPE_EXPAND_DIMS | ExpandDims张算子。 | 
| NODE_TYPE_FILL | Fill算子。 | 
| NODE_TYPE_FULL_CONNECTION | FullConnection算子。 | 
| NODE_TYPE_FUSED_BATCH_NORM | BatchNorm算子。 | 
| NODE_TYPE_GATHER | Gather算子。 | 
| NODE_TYPE_LAYER_NORM_FUSION | LayerNorm算子。 | 
| NODE_TYPE_LESS_EQUAL | LessEqual算子。 | 
| NODE_TYPE_MATMUL_FUSION | MatMul算子。 | 
| NODE_TYPE_MAXIMUM | Maximum算子。 | 
| NODE_TYPE_MAX_POOL_FUSION | MaxPool算子。 | 
| NODE_TYPE_MUL_FUSION | Mul算子。 | 
| NODE_TYPE_ONE_HOT | OneHot算子。 | 
| NODE_TYPE_PAD_FUSION | Pad算子。 | 
| NODE_TYPE_POW_FUSION | Pow算子。 | 
| NODE_TYPE_PRELU_FUSION | PReLU算子。 | 
| NODE_TYPE_QUANT_DTYPE_CAST | QuantDTypeCast算子。 | 
| NODE_TYPE_REDUCE_FUSION | Reduce算子。 | 
| NODE_TYPE_RESHAPE | Reshape算子。 | 
| NODE_TYPE_RESIZE | Resize算子。 | 
| NODE_TYPE_RSQRT | Rsqrt算子。 | 
| NODE_TYPE_SCALE_FUSION | Scale算子。 | 
| NODE_TYPE_SHAPE | Shape算子。 | 
| NODE_TYPE_SLICE_FUSION | Slice算子。 | 
| NODE_TYPE_SOFTMAX | Softmax算子。 | 
| NODE_TYPE_SPACE_TO_BATCH_ND | SpaceToBatchND算子。 | 
| NODE_TYPE_SPLIT | Split算子。 | 
| NODE_TYPE_SQRT | Sqrt算子。 | 
| NODE_TYPE_SQUEEZE | SquaredDifference算子。 | 
| NODE_TYPE_SQUARED_DIFFERENCE | Squeeze算子。 | 
| NODE_TYPE_STACK | Stack算子。 | 
| NODE_TYPE_STRIDED_SLICE | StridedSlice算子。 | 
| NODE_TYPE_SUB_FUSION | Sub算子。 | 
| NODE_TYPE_TILE_FUSION | Tile算子。 | 
| NODE_TYPE_TOPK_FUSION | TopK算子。 | 
| NODE_TYPE_TRANSPOSE | Transpose算子。 | 
| NODE_TYPE_UNSQUEEZE | Unsqueeze算子。 | 

### PaddingMode

```
enum PaddingMode : byte
```

**描述**

填充类型，需要配合[PadFusion](_pad_fusion_v10.md)算子使用。

当输入的张量x= \([[1,2,3],[4,5,6],[7,8,9]]\)，paddings= \([[2,2],[2,2]] \) 时效果如下：

- paddingMode==PADDING_MODE_CONSTANT并且constantValue = 0时输出为：
  $[[0. 0. 0. 0. 0. 0. 0.],\\ [0. 0. 0. 0. 0. 0. 0.],\\ [0. 0. 1. 2. 3. 0. 0.],\\ [0. 0. 4. 5. 6. 0. 0.],\\ [0. 0. 7. 8. 9. 0. 0.],\\ [0. 0. 0. 0. 0. 0. 0.],\\ [0. 0. 0. 0. 0. 0. 0.]]\\ $

- paddingMode==PADDING_MODE_REFLECT输出为：
  $[[9. 8. 7. 8. 9. 8. 7.],\\ [6. 5. 4. 5. 6. 5. 4.],\\ [3. 2. 1. 2. 3. 2. 1.],\\ [6. 5. 4. 5. 6. 5. 4.],\\ [9. 8. 7. 8. 9. 8. 7.],\\ [6. 5. 4. 5. 6. 5. 4.],\\ [3. 2. 1. 2. 3. 2. 1.]]\\ $

- paddingMode==PADDING_MODE_SYMMETRIC输出为：
  $[[5. 4. 4. 5. 6. 6. 5.],\\ [2. 1. 1. 2. 3. 3. 2.],\\ [2. 1. 1. 2. 3. 3. 2.],\\ [5. 4. 4. 5. 6. 6. 5.],\\ [8. 7. 7. 8. 9. 9. 8.],\\ [8. 7. 7. 8. 9. 9. 8.],\\ [5. 4. 4. 5. 6. 6. 5.]]\\ $

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PADDING_MODE_CONSTANT | 使用常量填充，默认值为0。 | 
| PADDING_MODE_REFLECT | 以数据区的便捷为轴，使填充区和数据区的数据以该轴保持对称。 | 
| PADDING_MODE_SYMMETRIC | 此填充方法类似于 PADDING_MODE_REFLECT，它以待填充区和数据区的交界为轴，使待填充区和数据区的数据以该轴保持对称。 | 
| PADDING_MODE_RESERVED | 预留，暂未使用。 | 

### PadMode

```
enum PadMode : byte
```

**描述**

填充类型，需要配合[AvgPoolFusion](_avg_pool_fusion_v10.md)，[AvgPoolFusion](_avg_pool_fusion_v10.md)，[Conv2DFusion](_conv2_d_fusion_v10.md)，[MaxPoolFusion](_max_pool_fusion_v10.md)使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PAD_MODE_PAD | 在输入的高度和宽度方向上填充0。 若设置该模式，算子的padding参数必须大于等于0。 | 
| PAD_MODE_SAME | 输出的高度和宽度分别与输入整除 stride 后的值相同。 若设置该模式，算子的padding参数必须为0。 | 
| PAD_MODE_VALID | 在不填充的前提下返回有效计算所得的输出。不满足计算的多余像素会被丢弃。 若设置此模式，则算子的padding参数必须为0。 | 

### PerformanceMode

```
enum PerformanceMode : int
```

**描述**

芯片执行AI计算的性能模式。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PERFORMANCE_NONE | 不指定任何性能模式，具体运行模式由芯片定义。 | 
| PERFORMANCE_LOW | 低性能模式，执行AI计算速度慢，功耗低。 | 
| PERFORMANCE_MEDIUM | 中性能模式，执行AI计算速度较慢，功耗较低。 | 
| PERFORMANCE_HIGH | 高性能模式，执行AI计算速度较快，功耗较高。 | 
| PERFORMANCE_EXTREME | 最高性能模式，执行AI计算速度快，功耗高。 | 

### Priority

```
enum Priority : int
```

**描述**

AI计算任务的优先级。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PRIORITY_NONE | 不指定任何任务优先级，具体执行策略由芯片定义。 | 
| PRIORITY_LOW | 低优先级，若有更高优先级的任务，芯片会执行更高优先级的任务。 | 
| PRIORITY_MEDIUM | 中等优先级，若有更高优先级的任务，芯片会执行更高优先级的任务。 | 
| PRIORITY_HIGH | 高优先级，高优先级任务最先执行。 | 

### QuantType

```
enum QuantType : byte
```

**描述**

量化类型。需要配合[Node](_node_v10.md)使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| QUANT_TYPE_NONE | 不使用量化。 | 
| QUANT_TYPE_ALL | int8全量化。 | 

### ReduceMode

```
enum ReduceMode : byte
```

**描述**

用于维度移除的方法，需要配合[ReduceFusion](_reduce_fusion_v10.md)算子使用。

**起始版本：** 3.2

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

**描述**

调整尺寸的方法。需要配合[Resize](_resize_v10.md)算子使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RESIZE_METHOD_UNKNOWN | 未知，默认值。 | 
| RESIZE_METHOD_LINEAR | 双线性插值。<br/>假设需要计算未知函数f在点$ (x,y) $的值其中$ x_1 &lt; x &lt; x_2, y_1 &lt; y &lt; y_2$，并且已知四个坐标点的值$ Q_{11} = (x_1, y_1), Q_{12} = (x1, y2), Q_{21} = (x_2, y_1)，Q_{22} = (x_2, y_2) $，并且$ f(Q_{11}),f(Q_{12}),f(Q_{21}),f(Q_{22}) $表示四个点的数值，则通过如下公式可计算$ f(x,y) $的值：<br/>$ f(x,y_1) = \frac{x_2-x}{x_2-x_1}f(Q_{11})+\frac{x-x_1}{x_2-x_1}f(Q_{21}) $<br/>$ f(x,y_2) = \frac{x_2-x}{x_2-x_1}f(Q_{12})+\frac{x-x_1}{x_2-x_1}f(Q_{22}) $<br/>$ f(x,y) = \frac{y_2-y}{y_2-y_1}f(x,y_1)+\frac{y-y_1}{y_2-y_1}f(x,y_2) $ | 
| RESIZE_METHOD_NEAREST | 最近临近插值。<br/>假设需要计算未知函数f在点$ (x,y) $的值其中$ x_1 &lt; x &lt;x_2, y_1 &lt; y &lt; y_2 $，并且已知四个坐标点的值$ Q_{11} = (x_1, y_1), Q_{12} = (x1, y2), Q_{21} = (x_2, y_1)，Q_{22} = (x_2, y_2) $，则从4个点中选择距离点$ (x,y) $最近的点的数值作为$ f(x,y) $的值。 | 
| RESIZE_METHOD_CUBIC | 双三次插值。<br/>双三次插值是取采样点周围16个点的值的加权平均来计算采样点的数值。该参数需要配合[Resize](_resize_v10.md)的cubicCoeff和coordinateTransformMode参数使用。 当coordinateTransformMode==COORDINATE_TRANSFORM_MODE_HALF_PIXEL时,cubicCoeff=-0.5，其他情况cubicCoeff=-0.75。插值函数的权重函数如下：<br/>$ W(x) = \begin{cases} (cubicCoeff+2)\|x\|^3 - (cubicCoeff+3)\|x\|^2 +1 , &amp;\text{if } \|x\| \leq 1; \cr cubicCoeff\|x\|^3 - 5cubicCoeff\|x\|^2 + 8cubicCoeff\|x\| - 4a, &amp;\text{if } 1 \lt \|x\| \leq 2; \cr 0, &amp;\text{otherwise.} \end{cases} $ | 

### RoundMode

```
enum RoundMode : byte
```

**描述**

小数取整算法，需要配合[AvgPoolFusion](_avg_pool_fusion_v10.md)算子使用。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ROUND_MODE_FLOOR | 向下取临近的整数，例如23.5取整为23，−23.5取整为−24。 | 
| ROUND_MODE_CEIL | 向上取临近的整数整，例如23.5取整为24，−23.5取整为−23。 | 
