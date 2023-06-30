# 使用MindSpore Lite进行离线模型的转换及推理

## 基本概念

- MindSpore Lite：OpenHarmony内置AI推理引擎，提供深度学习模型的推理部署能力。

- Neural Network Runtime：神经网络运行时，简称NNRt。作为中间桥梁，连通上层 AI 推理框架和底层加速芯片，实现 AI 模型的跨芯片推理计算。

- 离线模型：使用硬件厂商的离线模型转换工具转换得到的模型，由硬件厂商负责解析和推理。

## 场景介绍

常规的MindSpore Lite AI模型部署流程是：
- 开发者首先将三方格式模型（如：ONNX、CAFFE等）用MindSpore Lite模型转换工具，生成.ms模型；
- 然后在代码中调用MindSpore Lite推理引擎接口，执行模型推理。通过指定推理设备为NNRt，可利用系统中的AI硬件加速推理。

使用常规的MindSpore Lite + NNRt推理，初始阶段的动态构图会存在一定的模型加载时延。

当部署场景对加载时延要求严格时，开发者希望进一步降低加载时延，可采用另一种部署方案——基于离线模型的推理：
- 首先使用AI硬件厂商提供的离线转换工具，预先编译好一个离线模型。
- 然后使用MindSpore Lite转换工具，将离线模型整体作为黑盒，封装到.ms模型中。
- 最后将.ms模型输入给MindSpore Lite，执行推理。

执行推理时，MindSpore Lite会直接将离线模型传给接入NNRt的 AI 硬件，无需在线构图即可加载，大幅降低模型加载时延，并且可携带额外的硬件特定信息，协助 AI 硬件推理。

本文介绍离线模型推理及转换的详细流程。

## 约束与限制

- 离线模型仅支持在NNRt后端推理，硬件厂商需接入NNRt且支持离线模型推理。

## 离线模型转换


### 1、编译转换工具

取[MindSpore Lite源码](https://gitee.com/openharmony/third_party_mindspore)。此代码仓采用 “压缩包 + 补丁”的方式管理源码。首先执行以下命令解压源码，打入补丁：
```bash
cd mindspore
python3 build_helper.py --in_zip_path=./mindspore-v1.8.1.zip --patch_dir=./patches/ --out_src_path=./mindspore-src
```
执行完毕，MindSpore Lite完整源码位于：`mindspore-src/source/`。

执行编译：
```bash
cd mindspore-src/source/
bash build.sh -I x86_64 -j 8
```

编译完成后，可从源码根目录的`output/`子目录取得MindSpore Lite发布件。


### 2、编写转换工具扩展配置文件

离线模型本身作为黑盒，转换工具无法解析它得到模型输入输出张量信息，因此需要用户在转换工具的扩展配置文件手动配置。转换工具即可根据此配置，生成封装离线模型的.ms模型文件。

扩展配置样例如下：
- 首行[third_party_model]为固定关键词，表明此节为离线模型配置。
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

### 3、转换离线模型

解压上述步骤1编出的压缩包，解压后，转换工具位于`tools/converter/converter/`，进入该目录后执行：

```bash
export LD_LIBRARY_PATH=${PWD}/../lib
./converter_lite --fmk=THIRDPARTY --modelFile=/path/to/your_model --configFile=/path/to/your_config --outputFile=/path/to/output_model
```
即可完成离线模型转换。

转换参数说明：
- `--fmk`：输入模型的原始格式。`THIRDPARTY`表示输入为离线模型。
- `--modelFile`： 输入模型的路径。
- `--configFile`：扩展功能配置文件路径。此处用于离线模型的模型信息配置。
- `--outputFile`：输出模型的路径。无需加后缀，可自动生成.ms后缀。

> **说明：**
> 
> 当fmk指定为`THIRDPARTY`，执行离线模型转换，仅以上四个参数和扩展配置文件生效，其它参数配置无效。

## 离线模型推理

离线模型推理要求推理上下文只能添加NNRt设备，除此之外，与常规的.ms模型推理流程没有区别。

详细的MindSpore Lite推理流程请参考：[使用MindSpore Lite引擎进行模型推理](./mindspore-lite-guidelines.md)。
