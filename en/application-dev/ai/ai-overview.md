# AI Development

## Overview

Built on the native AI framework provided by OpenHarmony, the AI subsystem consists of the following components:
- MindSpore Lite: an AI inference framework that provides unified APIs for AI inference.
- Neural Network Runtime (NNRt): a bridge that connects MindSpore Lite and AI hardware.

## MindSpore Lite

MindSpore Lite is a built-in AI inference framework of OpenHarmony. It provides AI model inference capabilities for hardware devices and end-to-end solutions for developers to empower intelligent applications in all scenarios. So far, MindSpore Lite has been widely used in applications such as image classification, target recognition, facial recognition, and character recognition.

**Figure 1** Development process for MindSpore Lite model inference
![mindspore workflow](figures/mindspore_workflow.png)

The MindSpore Lite development process consists of two phases:

- Model conversion

   MindSpore Lite uses models in `.ms` format for inference. You can use the model conversion tool provided by MindSpore Lite to convert third-party framework models, such as TensorFlow, TensorFlow Lite, Caffe, and ONNX, into `.ms` models. For details, see [Converting Models for Inference](https://www.mindspore.cn/lite/docs/en/r1.8/use/converter_tool.html).

- Model inference

   You can call the MindSpore Lite runtime APIs to implement model inference. The procedure is as follows:

   1. Create an inference context by setting the inference hardware and number of threads.
   2. Load the **.ms** model file.
   3. Set the model input data.
   4. Perform model inference, and read the output.

MindSpore Lite is built in the OpenHarmony standard system as a system component. You can develop AI applications based on MindSpore Lite in the following ways:

- Method 1: [Using MindSpore Lite JavaScript APIs to develop AI applications](./mindspore-guidelines-based-js.md). You can directly call MindSpore Lite JavaScript APIs in the UI code to load the AI model and perform model inference. An advantage of this method is the quick verification of the inference effect.
- Method 2: [Using MindSpore Lite native APIs to develop AI applications](./mindspore-guidelines-based-native.md). You can encapsulate the algorithm models and the code for calling MindSpore Lite native APIs into a dynamic library, and then use N-API to encapsulate the dynamic library into JavaScript APIs for the UI to call.

## NNRt

NNRt functions as a bridge to connect the upper-layer AI inference framework and underlying acceleration chip, implementing cross-chip inference computing of AI models.

MindSpore Lite supports configuration of the NNRt backend, and therefore you can configure MindSpore Lite to use the NNRt hardware. The focus of this topic is about how to develop AI applications using MindSpore Lite. For details about how to use NNRt, see [Connecting the Neural Network Runtime to an AI Inference Framework](../napi/neural-network-runtime-guidelines.md).
