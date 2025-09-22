# MindSpore Lite Kit算子支持列表

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

本文档介绍了MindSpore Lite Kit与ONNX Opset18相比所支持的CPU后端算子列表以及对应关系。在使用模型转换工具将ONNX模型转换为ms模型进行部署时，通过查询此表可以知道MindSpore Lite Kit所支持的常用ONNX算子，以确保模型转换成功。

> **说明：**
>
> - 以下所有算子，均不支持int64类型输入。

| MindSpore Lite算子名称 | 算子功能                                                     | 对应ONNX算子名称                                             | 算子规格                                                     |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Abs                    | 逐元素计算绝对值                                             | Abs                                                          | 不支持uint8类型。不支持输入张量量化参数为空。                |
| Activation             | 激活函数                                                     | Celu<br/>Clip<br/>Elu<br/>Gelu<br/>HSigmoid<br/>LeakyRelu<br/>PRelu<br/>Relu<br/>Sigmoid<br/>SoftMax<br/>SoftPlus<br/>Tanh | -                                                            |
| AddFusion              | 逐元素计算加法                                               | Add                                                          | -                                                            |
| ArgMaxFusion           | 求某一维度最大值                                             | ArgMax                                                       | 不支持uint8类型。不支持输入张量量化参数为空。                |
| AvgPoolFusion          | 平均池化                                                     | AveragePool<br/>GlobalAveragePool<br/>GlobalMaxPool<br/>MaxPool | -                                                            |
| BatchNorm              | 批量归一化                                                   | BatchNormalization                                           | -                                                            |
| BroadcastTo            | 扩维                                                         | Expand                                                       | -                                                            |
| Cast                   | 数据类型转换                                                 | Cast                                                         | 不支持以下数值类型转换：fp32转int8、fp32转uint32、int32转int8、int32转uint32、int32转uint8、int8转bool、int8转uint8。 |
| Ceil                   | 向上取整                                                     | Ceil                                                         | -                                                            |
| Clip                   | 限制元素范围                                                 | Clip                                                         | -                                                            |
| Concat                 | 拼接张量                                                     | Concat                                                       | -                                                            |
| Conv2DFusion           | 2D卷积                                                       | Conv                                                         | -                                                            |
| Cos                    | 逐元素计算余弦                                               | Cos                                                          | -                                                            |
| CumSum                 | 累计元素和                                                   | CumSum                                                       | -                                                            |
| DepthToSpace           | 将深度数据重新排列到空间维度中                               | DepthToSpace                                                 | 不支持uint8类型。不支持未知维度输入。                        |
| DivFusion              | 逐元素除法                                                   | Div                                                          | 不支持除数为0。                                              |
| Eltwise                | 元素级求和                                                   | Sum                                                          | -                                                            |
| Equal                  | 判断输入是否相等                                             | Equal                                                        | 不支持uint8输入；int8输入不支持bool输出。                    |
| Erf                    | 误差函数                                                     | Erf                                                          | -                                                            |
| ExpFusion              | 逐元素取指数                                                 | Exp                                                          | -                                                            |
| Flatten                | 数据按维度展开                                               | Flatten                                                      | 不支持uint8类型。                                            |
| Floor                  | 向下取整                                                     | Floor                                                        | -                                                            |
| FusedBatchNorm         | 对输入做标准化                                               | BatchNormalization                                           | -                                                            |
| Gather                 | 沿单一维度收集指定索引位置的元素                             | Gather                                                       | 不支持uint8类型。不支持QuantType_QUANT_NONE量化类型。        |
| GatherD                | 将输入tensor中的元素根据索引tensor进行收集                   | GatherElements                                               | -                                                            |
| GatherNd               | 将输入张量的切片聚合成具有indices指定维度的新张量            | GatherND                                                     | -                                                            |
| InstanceNorm           | 实例归一化                                                   | InstanceNormalization                                        | -                                                            |
| Log                    | 逐元素求对数                                                 | Log                                                          | 不支持负数输入。                                             |
| LogicalNot             | 元素级逻辑非                                                 | Not                                                          | -                                                            |
| LogSoftmax             | 对输入向量进行softmax操作，然后再对softmax结果取对数         | LogSoftmax                                                   | 不支持inf输入。                                              |
| LRN                    | 局部响应标准化，用于防止数据过度拟合                         | LRN                                                          | -                                                            |
| MatMulFusion           | 对2个输入做矩阵乘法运算；使用输入张量、一组学习的权重计算内积，并添加偏差 | Gemm<br/>MatMul                                              | -                                                            |
| Maximum                | 取元素级最大值                                               | Max                                                          | -                                                            |
| MaxPoolFusion          | 最大池化                                                     | GlobalMaxPool<br/>MaxPool                                    | -                                                            |
| Minimum                | 取元素级最小值                                               | Min                                                          | -                                                            |
| Mod                    | 返回除法元素的余数                                           | Mod                                                          | -                                                            |
| MulFusion              | 逐元素乘法                                                   | Mul                                                          | -                                                            |
| Neg                    | 逐元素求负数                                                 | Neg                                                          | -                                                            |
| PadFusion              | 将输入张量加上指定的 padding，使其达到指定的大小             | Pad                                                          | 不支持int32类型。                                            |
| PowFusion              | 逐元素求幂                                                   | Pow                                                          | 仅支持指数为单个常数。                                       |
| PReLUFusion            | PRelu激活函数                                                | PRelu                                                        | -                                                            |
| Range                  | 生成某个区间内的元素                                         | Range                                                        | -                                                            |
| Reciprocal             | 返回倒数                                                     | Reciprocal                                                   | -                                                            |
| Reshape                | 改变张量形状，总元素个数不变                                 | Reshape                                                      | -                                                            |
| Round                  | 四舍五入到最接近的整数数值                                   | Round                                                        | -                                                            |
| ScatterNdUpdate        | 使用给定值以及输入索引更新输入数据的值                       | ScatterND                                                    | -                                                            |
| Shape                  | 获得张量shape                                                | Shape                                                        | -                                                            |
| Sin                    | 逐元素计算正弦                                               | Sin                                                          | -                                                            |
| Size                   | 获取张量维度大小                                             | Size                                                         | -                                                            |
| SliceFusion            | 张量切片操作                                                 | Slice                                                        | -                                                            |
| Softmax                | 归一化操作                                                   | Softmax                                                      | -                                                            |
| SpaceToDepth           | 高度和宽度维度的值移至深度维度                               | SpaceToDepth                                                 | -                                                            |
| Sqrt                   | 逐元素开根号                                                 | Sqrt                                                         | -                                                            |
| Squeeze                | 移除维度为1的维度                                            | Squeeze                                                      | -                                                            |
| StridedSlice           | Tensor切片                                                   | Slice                                                        | -                                                            |
| SubFusion              | 逐元素相减                                                   | Sub                                                          | -                                                            |
| TileFusion             | 平铺给定矩阵                                                 | Tile                                                         | 不支持int8类型。                                             |
| TopKFusion             | 从输入张量中返回top K个元素                                  | TopK                                                         | -                                                            |
| Transpose              | Tensor转置                                                   | Transpose                                                    | -                                                            |
| Tril                   | 下三角矩阵                                                   | Trilu（属性upper=0）                                         | -                                                            |
| Triu                   | 上三角矩阵                                                   | Trilu（属性upper=1）                                         | -                                                            |
| Unsqueeze              | 将输入张量添加一个新的维度                                   | Unsqueeze                                                    | -                                                            |
| Where                  | 元素选择                                                     | Where                                                        | -                                                            |
