# NodeAttrTypes.idl


## 概述

该文件定义AI模型算子的参数和功能。

该文文件中所有的结构体仅声明了算子的属性，并不包含执行算子函数的接口，具体介绍如下：

- 该文件中每一个算子都与[NodeType](_n_n_rt.md#nodetype)的枚举值一一对应，执行模型推理时，[NodeType](_n_n_rt.md#nodetype)会在[Node](_node.md)的nodeType中存储。

- 每一个算子都至少有一个“输入”与“输出”，“输入”即为该算子接收的张量，“输出”为经过算子运算之后得到的“张量”；“输入”、“算子”和“输出”之间的关系需要通过[Node](_node.md)结构体的inputIndex和outIndex来确认。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
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


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| package ohos.hdi.nnrt.v2_0 | NNRt模块的包路径。 | 
