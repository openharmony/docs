# MindSpore Lite Kit简介

## 使用场景

MindSpore Lite是OpenHarmony内置的AI推理框架，面向全场景构建支持多处理器架构的开放AI架构，使能全场景智能应用，为开发者提供端到端的解决方案，为算法工程师和数据科学家提供开发友好、运行高效、部署灵活的体验，帮助人工智能软硬件应用生态繁荣发展。 

目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用。常用场景如：

- 图像分类：最基础的计算机视觉应用，属于有监督学习类别，如给定一张图像（猫、狗、飞机、汽车等等），判断图像所属的类别。
- 目标检测：您可以使用预置目标检测模型，检测标识摄像头输入帧中的对象并添加标签，并用边框标识出来。
- 图像分割：图像分割可用于检测目标在图片中的位置或者图片中某一像素是输入何种对象的。

## 亮点/优势

MindSpore Lite提供面向不同硬件设备的AI模型推理能力，使能全场景智能应用，为开发者提供端到端的解决方案，使用MindSpore Lite的优势如下：

- 更优性能：高效的内核算法和汇编级优化，支持CPU、GPU、NPU异构调度，最大化发挥硬件算力，最小化推理时延和功耗。
- 轻量化：提供超轻量的解决方案，支持模型量化压缩，模型更小跑得更快，使能AI模型极限环境下的部署执行。
- 全场景支持：支持多种操作系统以及嵌入式系统，适配多种软硬件智能设备上的AI应用。
- 高效部署：支持MindSpore/TensorFlow Lite/Caffe/Onnx模型，提供模型压缩、数据处理等能力，统一训练和推理IR，方便用户快速部署。

## 开发方式

MindSpore Lite已作为系统部件在OpenHarmony标准系统内置，基于MindSpore Lite开发AI应用的开发方式有：

- 方式一：[使用MindSpore Lite JS API开发AI应用](./mindspore-guidelines-based-js.md)。开发者直接在UI代码中调用 MindSpore Lite JS API 加载模型并进行AI模型推理，此方式可快速验证效果。
- 方式二：[使用MindSpore Lite Native API开发AI应用](./mindspore-guidelines-based-native.md)。开发者将算法模型和调用 MindSpore Lite Native API 的代码封装成动态库，并通过N-API封装成JS接口，供UI调用。

## 与其他Kit的关系

Neural Network Runtime（NNRt, 神经网络运行时）是面向AI领域的跨芯片推理计算运行时，作为中间桥梁连通上层AI推理框架和底层加速芯片，实现AI模型的跨芯片推理计算。

MindSpore Lite原生支持配置Neural Network Runtime使能AI专用芯片（如NPU）加速推理。
