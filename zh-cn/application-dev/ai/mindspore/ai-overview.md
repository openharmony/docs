# AI开发概述

## 简介

OpenHarmony提供的原生AI框架，AI子系统部件包括：
- MindSpore Lite：AI推理框架，为开发者提供统一的AI推理接口；
- Neural Network Runtime：神经网络运行时，作为中间桥梁连接推理框架和AI硬件。

## MindSpore Lite

MindSpore Lite是OpenHarmony内置的AI推理框架，提供面向不同硬件设备的AI模型推理能力，使能全场景智能应用，为开发者提供端到端的解决方案，目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用。

**图 1** 使用MindSpore Lite进行模型推理的开发流程
![mindspore workflow](figures/mindspore_workflow.png)

MindSpore Lite开发流程分为两个阶段：

- 模型转换

   MindSpore Lite使用`.ms`格式模型进行推理。对于第三方框架模型，比如 TensorFlow、TensorFlow Lite、Caffe、ONNX等，可以使用MindSpore Lite提供的模型转换工具转换为`.ms`模型，使用方法可参考[推理模型转换](https://www.mindspore.cn/lite/docs/zh-CN/r1.8/use/converter_tool.html)。

- 模型推理

   调用MindSpore Lite运行时接口，实现模型推理，大致步骤如下：

   1. 创建推理上下文，包括指定推理硬件、设置线程数等。
   2. 加载`.ms`模型文件。
   3. 设置模型输入数据。
   4. 执行推理，读取输出。

MindSpore Lite已作为系统部件在OpenHarmony标准系统内置，基于MindSpore Lite开发AI应用的开发方式有：

- 方式一：[使用MindSpore Lite JS API开发AI应用](./mindspore-guidelines-based-js.md)。开发者直接在UI代码中调用 MindSpore Lite JS API 加载模型并进行AI模型推理，此方式可快速验证效果。
- 方式二：[使用MindSpore Lite Native API开发AI应用](./mindspore-guidelines-based-native.md)。开发者将算法模型和调用 MindSpore Lite Native API 的代码封装成动态库，并通过N-API封装成JS接口，供UI调用。

## Neural Network Runtime

Neural Network Runtime（NNRt, 神经网络运行时）是面向AI领域的跨芯片推理计算运行时，作为中间桥梁连通上层AI推理框架和底层加速芯片，实现AI模型的跨芯片推理计算。

MindSpore Lite已支持配置Neural Network Runtime后端，开发者可直接配置MindSpore Lite来使用NNRt硬件。因此，这里不再对NNRt具体展开说明，主要针对MindSpore开发AI应用提供指导。关于更多NNRt的Native使用，请参见[NNRt Native模块](../napi/neural-network-runtime-guidelines.md)。

