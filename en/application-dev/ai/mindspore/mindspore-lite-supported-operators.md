# MindSpore Lite Kit Operator List

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

This document provides the CPU backend operators supported by MindSpore Lite Kit and their mapping to ONNX Opset 18 operators. When using the model conversion tool to convert an ONNX model to an MS model for deployment, you can refer to this list for the supported ONNX operators, thereby ensuring the success of model conversion.

| MindSpore Lite Operator| Description                                                    | ONNX Operator                                            |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Abs                    | Computes the absolute value element-wise.                                            | Abs                                                          |
| Activation             | Computes the activation function.                                                    | Celu<br>Clip<br>Elu<br>Gelu<br>HSigmoid<br>LeakyRelu<br>PRelu<br>Relu<br>Sigmoid<br>SoftMax<br>SoftPlus<br>SoftSign<br>Tanh |
| AddFusion              | Computes element-wise addition.                                              | Add                                                          |
| ArgMaxFusion           | Computes the maximum value along a specified dimension.                                            | ArgMax                                                       |
| AvgPoolFusion          | Performs average pooling.                                                    | AveragePool<br>GlobalAveragePool<br>GlobalMaxPool<br>MaxPool |
| BatchNorm              | Performs batch normalization.                                                  | BatchNormalization                                           |
| BroadcastTo            | Expands the dimensions of a tensor.                                                        | Expand                                                       |
| Cast                   | Converts the data type.                                                | Cast                                                         |
| Ceil                   | Rounds up to an integer.                                                    | Ceil                                                         |
| Clip                   | Limits the element range.                                                | Clip                                                         |
| Concat                 | Concatenates tensors.                                                    | Concat                                                       |
| Conv2DFusion           | Performs 2D convolution.                                                      | Conv                                                         |
| Cos                    | Computes the cosine element-wise.                                              | Cos                                                          |
| CumSum                 | Accumulates the elements.                                                  | CumSum                                                       |
| DepthToSpace           | Rearranges data from depth into blocks of spatial data.                              | DepthToSpace                                                 |
| DivFusion              | Computes element-wise division.                                                  | Div                                                          |
| Eltwise                | Computes element-wise summation.                                                  | Sum                                                          |
| Equal                  | Checks whether the inputs are equal.                                            | Equal                                                        |
| Erf                    | Computes the error function.                                                    | Erf                                                          |
| ExpFusion              | Computes the exponential element-wise.                                                | Exp                                                          |
| Flatten                | Flattens data by dimension.                                              | Flatten                                                      |
| Floor                  | Rounds down to the nearest integer.                                                    | Floor                                                        |
| FusedBatchNorm         | Performs fused batch normalization.                                              | BatchNormalization                                           |
| Gather                 | Gathers elements from a tensor along a specified axis.                            | Gather                                                       |
| GatherD                | Gathers elements from a tensor using dynamic indices.                  | GatherElements                                               |
| GatherNd               | Gathers elements from a tensor using N-dimensional indices.           | GatherND                                                     |
| InstanceNorm           | Performs instance normalization.                                                  | InstanceNormalization                                        |
| Log                    | Computes the natural logarithm element-wise.                                                | Log                                                          |
| LogicalNot             | Computes the element-wise logical NOT.                                                | Not                                                          |
| LogSoftmax             | Applies Softmax followed by Log to the input tensor.        | LogSoftmax                                                   |
| LRN                    | Applies local response normalization to reduce overfitting.                        | LRN                                                          |
| MatMulFusion           | Performs matrix multiplication on two input tensors by computing the inner product using the input tensors and a set of learned weights, followed by adding a bias.| Gemm<br>MatMul                                             |
| Maximum                | Computes the element-wise maximum.                                              | Max                                                          |
| MaxPoolFusion          | Performs max pooling operation.                                                    | GlobalMaxPool<br>MaxPool                                   |
| Minimum                | Computes the element-wise minimum.                                              | Min                                                          |
| Mod                    | Computes the element-wise modulus.                                          | Mod                                                          |
| MulFusion              | Computes the element-wise multiplication.                                                  | Mul                                                          |
| Neg                    | Computes the element-wise negation.                                                | Neg                                                          |
| PadFusion              | Adds padding to a tensor.            | Pad                                                          |
| PowFusion              | Computes the element-wise power.                                                  | Pow                                                          |
| PReLUFusion            | Performs parametric ReLU activation.                                               | PRelu                                                        |
| Range                  | Generates a sequence of numbers with a specified start, end, and step.                                        | Range                                                        |
| Reciprocal             | Computes the element-wise reciprocal.                                                    | Reciprocal                                                   |
| Reshape                | Reshapes a tensor.                                | Reshape                                                      |
| Round                  | Rounds to the nearest integer.                                  | Round                                                        |
| ScatterNdUpdate        | Updates specified elements of a tensor using given indices and values.                      | ScatterND                                                    |
| Shape                  | Obtains the shape of a tensor.                                               | Shape                                                        |
| Sin                    | Computes the element-wise sine.                                              | Sin                                                          |
| Size                   | Obtains the size of a tensor.                                            | Size                                                         |
| SliceFusion            | Slices a tensor.                                                | Slice                                                        |
| Softmax                | Applies the Softmax function to normalize a tensor along a specified axis.                                                  | Softmax                                                      |
| SpaceToDepth           | Rearranges blocks of spatial data into depth.                              | SpaceToDepth                                                 |
| Sqrt                   | Computes the element-wise square root.                                                | Sqrt                                                         |
| Squeeze                | Removes dimensions of size 1.                                           | Squeeze                                                      |
| StridedSlice           | Slices a tensor with stride.                                                  | Slice                                                        |
| SubFusion              | Computes the element-wise subtraction.                                                  | Sub                                                          |
| TileFusion             | Constructs a tensor by replicating input tensor multiple times.                                                | Tile                                                         |
| TopKFusion             | Obtains the top K elements from the input tensor.                                 | TopK                                                         |
| Transpose              | Transposes a tensor.                                                  | Transpose                                                    |
| Tril                   | Obtains the lower triangular part of a matrix.                                                  | Trilu (upper=0)                                        |
| Triu                   | Obtains the upper triangular part of a matrix.                                                  | Trilu (upper=1)                                        |
| Unsqueeze              | Inserts a new dimension into the input tensor.                                  | Unsqueeze                                                    |
| Where                  | Selects elements based on specified conditions.                                                    | Where                                                        |
