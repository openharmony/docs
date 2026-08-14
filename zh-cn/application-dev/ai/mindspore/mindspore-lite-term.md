# MindSpore Lite Kit术语

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing; @LinHaier-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## C

### Context；上下文

MindSpore Lite运行时的配置对象，用于指定推理或训练的硬件设备类型、线程数、绑核策略等运行参数，在模型加载编译前创建并传入。

## D

### Dynamic Shape；动态Shape

模型输入维度可变的能力。启用动态Shape的模型可在推理时接受不同尺寸的输入。

## F

### Float16；半精度

IEEE 754标准定义的一种浮点数数据类型，在计算机中使用16比特（2字节）存储，因此称为Float16或FP16，它的存储位数只有单精度浮点数的一半，也称为Half（半精度）。这种数据类型适合对精度要求不高的场景，例如人工神经网络领域。Float16推理模式表示推理的时候用半精度进行推理，仅CPU/GPU设备可用，可在减少内存占用和计算量的同时保持较高的推理精度。

## H

### Heterogeneous Inference；异构推理

将模型中的不同算子调度到不同类型的硬件（如NNRt加速芯片与CPU）上分别执行推理的方式，优先将算子调度到加速硬件，不支持的算子回退到CPU执行，以兼顾推理性能与算子兼容性。

## M

### Model Conversion；模型转换

MindSpore Lite部署流程的第一阶段，使用模型转换工具将第三方框架模型（ONNX、CAFFE、TFLITE、TF、PyTorch等）或MindIR模型转换为`.ms`格式的端侧模型文件，以便在MindSpore Lite上进行推理或训练。

### MindIR

MindSpore训练框架的统一模型中间表示格式，文件后缀为`.mindir`，用于统一训练和推理的模型表示，可通过模型转换工具转换为`.ms`格式用于端侧部署。

### MS Model；MS模型

MindSpore Lite专用的端侧模型格式，文件后缀为`.ms`，针对端侧资源受限场景进行了ROM/RAM/推理时延等综合指标充分优化过的一种模型格式。由模型转换工具将第三方框架模型（ONNX、CAFFE、TFLITE等）或MindIR模型转换生成，可直接用于MindSpore Lite推理或训练。

## N

### NNRt；神经网络运行时

Neural Network Runtime的缩写，OpenHarmony面向AI领域的跨芯片推理计算运行时，作为中间桥梁连通上层AI推理框架和底层加速芯片，实现AI模型的跨芯片推理计算。MindSpore Lite支持配置NNRt使能AI专用芯片（如NPU）加速推理。

### NPU

Neural Processing Unit的缩写，即神经网络处理器，专用AI加速芯片，擅长执行神经网络推理计算，推理能力较强但支持的算子规格相对较少。

## O

### On-device Training；端侧训练

在端侧设备上对模型进行训练，使模型在实际业务场景中自适应用户行为。MindSpore Lite提供独立的训练开发流程和API体系（训练配置、训练模式设置、模型导出等），与推理流程形成对照。

### Offline Model；离线模型

使用硬件厂商的离线模型转换工具预先转换得到的模型，由硬件厂商负责解析和推理。MindSpore Lite推理时直接将离线模型传给接入NNRt的AI硬件，无需在线构图即可加载，可大幅降低模型加载时延。

### Operator；算子

神经网络中的基本计算单元，对应一种特定的数学运算（如卷积、池化、激活等），是构成模型计算图的基础节点。MindSpore Lite Kit对ONNX Opset18算子的支持范围可查询算子支持列表。

### Operator Fusion；算子融合

在模型转换阶段将多个连续算子合并为一个融合算子的优化技术，可减少计算图中的节点数量和内存访问次数，提升推理性能。模型转换工具支持通过配置关闭指定融合算子。

## P

### Post-Training Quantization；训练后量化

在模型训练完成后，对模型权重和激活值进行量化压缩的技术，可将浮点模型转换为低精度（如INT8）模型，使模型更小、推理更快，适用于资源受限的端侧部署场景。

## T

### Tensor；张量

与数组和矩阵非常相似，是MindSpore Lite网络运算中的基本数据结构，用于承载模型的输入、输出及中间计算结果。

### Thread Affinity；绑核策略

运行时线程绑定CPU核心的调度策略，按照CPU物理核频率分为大核、中核、小核三种类型，可配置线程优先绑定大核或中核，以优化推理性能。
