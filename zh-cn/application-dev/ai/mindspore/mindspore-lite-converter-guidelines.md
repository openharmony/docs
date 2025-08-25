# 使用MindSpore Lite进行模型转换

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## 基本概念

- MindSpore Lite：OpenHarmony内置AI推理引擎，提供深度学习模型的推理部署能力。

- Neural Network Runtime：神经网络运行时，简称NNRt。作为中间桥梁，连通上层AI推理框架和底层加速芯片，实现AI模型的跨芯片推理计算。

- 通用的神经网络模型格式，如MindSpore、ONNX、TensorFlow、CAFFE等。

- 离线模型：使用硬件厂商的离线模型转换工具转换得到的模型，由硬件厂商负责解析和推理。

## 场景介绍

MindSpore Lite AI模型部署流程是：
1. 开发者首先将原始模型（如：ONNX、CAFFE等）用MindSpore Lite模型转换工具，生成后缀为.ms的模型文件。MindSpore Lite Kit所支持的ONNX算子，可查询[MindSpore Lite Kit算子支持列表](mindspore-lite-supported-operators.md)，以确保模型转换成功。
2. 然后在代码中调用MindSpore Lite推理引擎接口，执行[模型推理](mindspore-lite-guidelines.md)。

## 获取模型转换工具

对于MindSpore Lite模型转换工具，有以下两种方式可以获取：

### 通过下载获取

| 组件                                                    | 硬件平台 | 操作系统     | 链接                                                         | SHA-256                                                      |
| ------------------------------------------------------- | -------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 端侧推理和训练benchmark工具、converter工具、cropper工具 | CPU      | Linux-x86_64 | [mindspore-lite-2.3.0-linux-x64.tar.gz](https://ms-release.obs.cn-north-4.myhuaweicloud.com/2.3.0/MindSpore/lite/release/linux/x86_64/mindspore-lite-2.3.0-linux-x64.tar.gz) | 060d698a171b52c38b64c8d65927816daf4b81d8e2b5069718aeb91a9f8a154c |

### 通过源码编译

> **说明：**
>
> - 由于支持转换PyTorch模型的编译选项默认关闭，因此下载的安装包不支持转换PyTorch模型，只能通过源码编译方式获取。
>
> - 模型中有transpose与convolution算子融合，需要通过源码编译方式获取。否则可能会发生类似警告：node infer shape failed, node is Default/Conv2DFusion-xxx。
>
> - 当指定NPU后端进行推理时，需要自定义[关闭clip算子融合](#关闭指定算子融合)，模型转换工具需要通过源码编译方式获取。否则可能会发生类似报错：BuildKirinNPUModel# Create full model kernel failed。

1. 编译环境要求如下：

   - 系统环境：Linux x86_64，推荐使用Ubuntu 18.04.02LTS。
   - C++编译依赖：
     -  GCC >= 7.3.0
     -  CMake >= 3.18.3
     -  Git >= 2.28.0

2. 取[MindSpore Lite源码](https://gitee.com/openharmony/third_party_mindspore)。
   MindSpore Lite完整源码位于：`mindspore-src/source/`。

3. 执行编译。

   如要获取支持转换PyTorch模型的转换工具，编译前需要先`export MSLITE_ENABLE_CONVERT_PYTORCH_MODEL=on && export LIB_TORCH_PATH="/home/user/libtorch"`。转换前加入libtorch的环境变量：`export LD_LIBRARY_PATH="/home/user/libtorch/lib:${LD_LIBRARY_PATH}"`。用户可以下载CPU版本libtorch后解压到`/home/user/libtorch`的目录下。

   ```bash
   cd mindspore-src/source/
   bash build.sh -I x86_64 -j 8
   ```

   编译完成后，可从源码根目录的`output/`子目录取得MindSpore Lite发布件。解压后，转换工具位于`tools/converter/converter/`。

## 配置环境变量

获取到模型转换工具之后，还需要将转换工具需要的动态链接库加入环境变量LD_LIBRARY_PATH。

```bash
export LD_LIBRARY_PATH=${PACKAGE_PATH}/tools/converter/lib:${LD_LIBRARY_PATH}
```

其中，${PACKAGE_PATH}对应为编译或下载得到的MindSpore Lite发布件解压后的路径。


## 参数说明

MindSpore Lite模型转换工具提供了多种参数设置，用户可根据需要来选择使用。此外，用户可输入`./converter_lite --help`获取实时帮助。
下面提供详细的参数说明。


|        参数        | 是否必选            | 参数说明                                                     | 取值范围                                         |
| :----------------: | ------------------- | ------------------------------------------------------------ | ------------------------------------------------ |
|       --help       | 否                  | 打印全部帮助信息。                                           | -                                                |
|       --fmk        | 是                  | 输入模型的原始格式。只有在MS模型转换为Micro代码场景时，才支持设置为MSLITE。 | MINDIR、CAFFE、TFLITE、TF、ONNX、PYTORCH、MSLITE |
|    --modelFile     | 是                  | 输入模型的路径。                                             | -                                                |
|    --outputFile    | 是                  | 输出模型的路径，不需加后缀，可自动生成`.ms`后缀。            | -                                                |
|    --weightFile    | 转换CAFFE模型时必选 | 输入模型权重文件的路径。                                     | -                                                |
|    --configFile    | 否                  | 1）可作为训练后量化配置文件路径；2）可作为扩展功能配置文件路径。 | -                                                |
|       --fp16       | 否                  | 设定在模型序列化时是否需要将float32数据格式的权重存储为float16数据格式。<br/>默认值为off。 | on、off                                          |
|    --inputShape    | 否                  | 设定模型输入的维度，输入维度的顺序和原始模型保持一致。对某些特定的模型可以进一步优化模型结构，但是转化后的模型将可能失去动态shape的特性。输入名和shape之间用`:`分割，多个输入用`;`分割，同时加上双引号`""`。例如配置为"inTensorName_1: 1,32,32,4;inTensorName_2:1,64,64,4;"。 | -                                                |
| --inputDataFormat  | 否                  | 设定导出模型的输入format，只对四维输入有效。<br/>默认值为NHWC。 | NHWC、NCHW                                       |
|  --inputDataType   | 否                  | 设定量化模型输入tensor的数据类型。仅当模型输入tensor的量化参数（scale和zero point）配置时有效。默认与原始模型输入tensor的数据类型保持一致。<br/>默认值为DEFAULT。 | FLOAT32、INT8、UINT8、DEFAULT                    |
|  --outputDataType  | 否                  | 设定量化模型输出tensor的数据类型。仅当模型输出tensor的量化参数（scale和zero point）配置时有效。默认与原始模型输出tensor的数据类型保持一致。<br/>默认值为DEFAULT。 | FLOAT32、INT8、UINT8、DEFAULT                    |
| --outputDataFormat | 否                  | 设定导出模型的输出format，只对四维输出有效。                 | NHWC、NCHW                                       |

> **说明：**
> - 参数名和参数值之间用等号连接，中间不能有空格。
> - CAFFE模型一般分为两个文件：`*.prototxt`模型结构，对应`--modelFile`参数；`*.caffemodel`模型权值，对应`--weightFile`参数。

## 使用示例

以CAFFE模型LeNet为例，执行转换命令。

```bash
./converter_lite --fmk=CAFFE --modelFile=lenet.prototxt --weightFile=lenet.caffemodel --outputFile=lenet
```
本例中，因为采用了CAFFE模型，所以需要模型结构、模型权值两个输入文件。再加上其他必需的fmk类型和输出路径两个参数，即可成功执行。
结果显示为：

```bash
CONVERT RESULT SUCCESS:0
```
这表示已经成功将CAFFE模型转化为MindSpore Lite模型，获得新文件`lenet.ms`。

## 离线模型转换（可选）

当部署场景对加载时延要求严格时，开发者希望进一步降低加载时延，可采用另一种部署方案，即基于离线模型的推理。

执行推理时，MindSpore Lite会直接将离线模型传给接入NNRt的 AI 硬件，无需在线构图即可加载，大幅降低模型加载时延，并且可携带额外的硬件特定信息，协助AI硬件推理。

### 约束与限制

- 离线模型仅支持在NNRt后端推理，硬件厂商需接入NNRt且支持离线模型推理。
- 离线模型转换工具仅支持通过源码编译方式获取。
- 离线模型在转换时`fmk`必须指定为`THIRDPARTY`。
- 离线模型本身作为黑盒，转换工具无法直接解析它得到模型输入输出张量信息，因此需要用户在转换工具的扩展配置文件中手动配置。

### 扩展配置文件说明

扩展配置样例如下：
- 首行`[third_party_model]`为固定关键词，表明此节为离线模型配置。
- 下方依次是模型输入输出张量的名称、数据类型、形状、内存格式等信息，每个字段独占一行，先后顺序不限，采用键值对格式。
- 除数据类型和形状必选外，其它为可选配置。
- 最后，还提供扩展参数字段，可将离线模型所需的自定义配置用键值对的形式一同封装到.ms文件，在推理时由NNRt传递给AI硬件使用。

```text
[third_party_model]
input_names=in_0;in_1
input_dtypes=float32;float32
input_shapes=8,256,256;8,256,256,3
input_formats=NCHW;NCHW
output_names=out_0
output_dtypes=float32
output_shapes=8,64
output_formats=NCHW
extended_parameters=key_foo:value_foo;key_bar:value_bar
```

字段说明：

- `input_names`：[可选]模型输入名称，格式：字符串，多个输入用`;`间隔。
- `input_dtypes`：[必选]模型输入数据类型，格式：类型，多个输入用`;`间隔。
- `input_shapes`：[必选]模型输入形状，格式：整数数组，多个输入用`;`间隔。
- `input_formats`：[可选]模型输入内存布局，格式：字符串，多个输入用`;`间隔，默认值NHWC。
- `output_names`：[可选]模型输入名称，格式：字符串，多个输入用`;`间隔。
- `output_dtypes`：[必选]模型输出数据类型，格式：类型，多个输出用`;`间隔。
- `output_shapes`：[必选]模型输出形状，格式：整数数组，多个输出用`;`间隔。
- `output_formats`：[可选]模型输出内存布局，格式：字符串，多个输入用`;`间隔，默认值NHWC。
- `extended_parameters`：[可选]推理硬件自定义配置，字符串键值对格式，会通过NNRt后端传给硬件。

## 附录

### 关闭指定算子融合

如果用户需要关闭指定算子融合功能，可新建配置文件，如converter.cfg，配置文件内容如下：

```ini
[registry]
# 当参数disable_fusion=off时，可通过配置fusion_blacklists关闭指定融合；当参数disable_fusion=on时，关闭所有融合，参数fusion_blacklists不生效。默认值为off。
disable_fusion=off
# 关闭多个算子融合时，用逗号分隔。
fusion_blacklists=ConvActivationFusion,MatMulActivationFusion,clip_convert_activation_pass
```

在执行converter时，指定参数--configFile=converter.cfg即可。

支持关闭的融合算子如下所示：

- AddConcatActivationFusion
- SqueezeFusion
- TransposeFusion
- ReshapeReshapeFusion 
- ConvBiasaddFusion 
- ConvBatchNormFusion 
- ConvScaleFusion 
- GroupNormFusion 
- TfNormFusion 
- OnnxLayerNormFusion 
- OnnxLayerNormFusion2 
- BatchMatMulFusion 
- BatchNormToScaleFusion 
- SigmoidMulFusion 
- ActivationFusion 
- ConvActivationFusion 
- ConvTupleGetItemFusion 
- ConvTupleActivationFusion  
- TfliteLstmCellFusion 
- TfLstmCellFusion 
- TfBidirectionGruFusion 
- TfGeLUFusion 
- OnnxGeLUFusion 
- TfliteRelPosMultiHeadAttentionFusion  
- GLUFusion 
- ConstFoldPass 
- AffineFusion 
- AffineActivationFusion 
- ConvConvFusion 
- ConvPadFusion 
- MatMulAddFusion 
- MatMulMulFusion 
- TransposeMatMulFusion 
- MulAddFusion 
- ScaleActivationFusion 
- ScaleScaleFusion 
- FullConnectedFusion 
- FullconnectedAddFusion 
- TensorDotFusion 
- MatMulActivationFusion 
- clip_convert_activation_pass  