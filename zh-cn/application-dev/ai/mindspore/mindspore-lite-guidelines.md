# 使用MindSpore Lite进行模型推理 (C/C++)

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--SE: @zhuguodong8; @jjfeing-->
<!--TSE: @principal87-->

## 场景介绍

MindSpore Lite是一款AI引擎，它提供了面向不同硬件设备AI模型推理的功能，目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用。

本文介绍使用MindSpore Lite推理引擎进行模型推理的通用开发流程。

## 基本概念

在进行开发前，请先了解以下概念。

**张量**：它与数组和矩阵非常相似，是MindSpore Lite网络运算中的基本数据结构。

**Float16推理模式**：  Float16又称半精度，它使用16比特表示一个数。Float16推理模式表示推理的时候用半精度进行推理。 



## 接口说明

这里给出MindSpore Lite推理的通用开发流程中涉及的一些接口，具体请见下列表格。更多接口及详细内容，请见[MindSpore](../../reference/apis-mindspore-lite-kit/capi-mindspore.md)。

### Context 相关接口

| 接口名称        | 描述        |
| ------------------ | ----------------- |
|OH_AI_ContextHandle OH_AI_ContextCreate()|创建一个上下文的对象。注意：此接口需跟OH_AI_ContextDestroy配套使用。|
|void OH_AI_ContextSetThreadNum(OH_AI_ContextHandle context, int32_t thread_num)|设置运行时的线程数量。|
|void OH_AI_ContextSetThreadAffinityMode(OH_AI_ContextHandle context, int mode)|设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。|
|OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate(OH_AI_DeviceType device_type)|创建一个运行时设备信息对象。|
|void OH_AI_ContextDestroy(OH_AI_ContextHandle *context)|释放上下文对象。|
|void OH_AI_DeviceInfoSetEnableFP16(OH_AI_DeviceInfoHandle device_info, bool is_fp16)|设置是否开启Float16推理模式，仅CPU/GPU设备可用。|
|void OH_AI_ContextAddDeviceInfo(OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info)|添加运行时设备信息。|

### Model 相关接口

| 接口名称        | 描述        |
| ------------------ | ----------------- |
|OH_AI_ModelHandle OH_AI_ModelCreate()|创建一个模型对象。|
|OH_AI_Status OH_AI_ModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path,OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context)|通过模型文件加载并编译MindSpore模型。|
|void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)|释放一个模型对象。|

### Tensor 相关接口

| 接口名称        | 描述        |
| ------------------ | ----------------- |
|OH_AI_TensorHandleArray OH_AI_ModelGetInputs(const OH_AI_ModelHandle model)|获取模型的输入张量数组结构体。|
|int64_t OH_AI_TensorGetElementNum(const OH_AI_TensorHandle tensor)|获取张量元素数量。|
|const char *OH_AI_TensorGetName(const OH_AI_TensorHandle tensor)|获取张量的名称。|
|OH_AI_DataType OH_AI_TensorGetDataType(const OH_AI_TensorHandle tensor)|获取张量数据类型。|
|void *OH_AI_TensorGetMutableData(const OH_AI_TensorHandle tensor)|获取可变的张量数据指针。|

## 开发步骤

使用MindSpore Lite进行模型推理的开发流程如下图所示。

**图 1** 使用MindSpore Lite进行模型推理的开发流程

![how-to-use-mindspore-lite](figures/01.png)

进入主要流程之前需要先引用相关的头文件，并编写函数生成随机的输入，具体如下：

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mindspore/model.h"

//生成随机的输入
int GenerateInputDataWithRandom(OH_AI_TensorHandleArray inputs) {
  for (size_t i = 0; i < inputs.handle_num; ++i) {
    float *input_data = (float *)OH_AI_TensorGetMutableData(inputs.handle_list[i]);
    if (input_data == NULL) {
      printf("MSTensorGetMutableData failed.\n");
      return OH_AI_STATUS_LITE_ERROR;
    }
    int64_t num = OH_AI_TensorGetElementNum(inputs.handle_list[i]);
    const int divisor = 10;
    for (size_t j = 0; j < num; j++) {
      input_data[j] = (float)(rand() % divisor) / divisor;  // 0--0.9f
    }
  }
  return OH_AI_STATUS_SUCCESS;
}
```

然后进入主要的开发步骤，具括包括模型的准备、读取、编译、推理和释放，具体开发过程及细节请见下文的开发步骤及示例。

1. 模型准备。

    需要的模型可以直接下载，也可以通过模型转换工具获得。
  
     - 下载模型的格式若为`.ms`，则可以直接使用。本文以mobilenetv2.ms为例。
     - 如果是第三方框架的模型，比如 TensorFlow、TensorFlow Lite、Caffe、ONNX等，可以使用[模型转换工具](https://www.mindspore.cn/lite/docs/zh-CN/master/use/downloads.html#2-3-0)转换为`.ms`格式的模型文件。

2. 创建上下文，设置线程数、设备类型等参数。

    以下介绍两种典型情形。

    情形1：仅创建CPU推理上下文。
  
    ```c
    // 创建并配置上下文，设置运行时的线程数量为2，绑核策略为大核优先
    OH_AI_ContextHandle context = OH_AI_ContextCreate();
    if (context == NULL) {
      printf("OH_AI_ContextCreate failed.\n");
      return OH_AI_STATUS_LITE_ERROR;
    }
    const int thread_num = 2;
    OH_AI_ContextSetThreadNum(context, thread_num);
    OH_AI_ContextSetThreadAffinityMode(context, 1);
    //设置运行设备为CPU，不使用Float16推理
    OH_AI_DeviceInfoHandle cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
    if (cpu_device_info == NULL) {
      printf("OH_AI_DeviceInfoCreate failed.\n");
      OH_AI_ContextDestroy(&context);
      return OH_AI_STATUS_LITE_ERROR;
    }
    OH_AI_DeviceInfoSetEnableFP16(cpu_device_info, false);
    OH_AI_ContextAddDeviceInfo(context, cpu_device_info);
    ```

    情形2：创建NNRT（Neural Network Runtime）和CPU异构推理上下文。

    NNRT是面向AI领域的跨芯片推理计算运行时，一般来说，NNRT对接的加速硬件如NPU，推理能力较强，但支持的算子规格少；而通用CPU推理能力较弱，但支持算子规格更全面。MindSpore Lite支持配置NNRT硬件和CPU异构推理：优先将模型算子调度到NNRT推理，若某些算子NNRT不支持，将其调度到CPU进行推理。通过下面的操作即可配置NNRT/CPU异构推理。
   <!--Del-->
   > **说明：**
   >
   > NNRT/CPU异构推理，需要有实际的NNRT硬件接入，NNRT相关资料请参考：[OpenHarmony/ai_neural_network_runtime](https://gitee.com/openharmony/ai_neural_network_runtime)。
   <!--DelEnd-->
    ```c
    // 创建并配置上下文，设置运行时的线程数量为2，绑核策略为大核优先
    OH_AI_ContextHandle context = OH_AI_ContextCreate();
    if (context == NULL) {
      printf("OH_AI_ContextCreate failed.\n");
      return OH_AI_STATUS_LITE_ERROR;
    }
    // 优先使用NNRT推理。
    // 这里利用查找到的第一个ACCELERATORS类别的NNRT硬件，来创建nnrt设备信息，并设置硬件使用高性能模式推理。还可以通过如：OH_AI_GetAllNNRTDeviceDescs()接口获取当前环境中所有NNRT硬件的描述信息，按设备名、类型等信息查找，找到某一具体设备作为NNRT推理硬件。
    OH_AI_DeviceInfoHandle nnrt_device_info = OH_AI_CreateNNRTDeviceInfoByType(OH_AI_NNRTDEVICE_ACCELERATOR);
    if (nnrt_device_info == NULL) {
      printf("OH_AI_DeviceInfoCreate failed.\n");
      OH_AI_ContextDestroy(&context);
      return OH_AI_STATUS_LITE_ERROR;
    }
    OH_AI_DeviceInfoSetPerformanceMode(nnrt_device_info, OH_AI_PERFORMANCE_HIGH);
    OH_AI_ContextAddDeviceInfo(context, nnrt_device_info);

    // 其次设置CPU推理。
    OH_AI_DeviceInfoHandle cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
    if (cpu_device_info == NULL) {
      printf("OH_AI_DeviceInfoCreate failed.\n");
      OH_AI_ContextDestroy(&context);
      return OH_AI_STATUS_LITE_ERROR;
    }
    OH_AI_ContextAddDeviceInfo(context, cpu_device_info);
    ```

    

3. 创建、加载与编译模型。

    调用OH_AI_ModelBuildFromFile加载并编译模型。

    本例中传入OH_AI_ModelBuildFromFile的argv[1]参数是从控制台中输入的模型文件路径。

    ```c
    // 创建模型
    OH_AI_ModelHandle model = OH_AI_ModelCreate();
    if (model == NULL) {
      printf("OH_AI_ModelCreate failed.\n");
      OH_AI_ContextDestroy(&context);
      return OH_AI_STATUS_LITE_ERROR;
    }

    // 加载与编译模型，模型的类型为OH_AI_MODELTYPE_MINDIR
    if (access(argv[1], F_OK) != 0) {
        printf("model file not exists.\n");
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return OH_AI_STATUS_LITE_ERROR;
    }
    int ret = OH_AI_ModelBuildFromFile(model, argv[1], OH_AI_MODELTYPE_MINDIR, context);
    if (ret != OH_AI_STATUS_SUCCESS) {
      printf("OH_AI_ModelBuildFromFile failed, ret: %d.\n", ret);
      OH_AI_ModelDestroy(&model);
      OH_AI_ContextDestroy(&context);
      return ret;
    }
    ```

4. 输入数据。

    模型执行之前需要向输入的张量中填充数据。本例使用随机的数据对模型进行填充。

    ```c
    // 获得输入张量
    OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
    if (inputs.handle_list == NULL) {
      printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
      OH_AI_ModelDestroy(&model);
      OH_AI_ContextDestroy(&context);
      return ret;
    }
    // 使用随机数据填充张量
    ret = GenerateInputDataWithRandom(inputs);
    if (ret != OH_AI_STATUS_SUCCESS) {
      printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
      OH_AI_ModelDestroy(&model);
      OH_AI_ContextDestroy(&context);
      return ret;
    }
   ```

5. 执行推理。

    使用OH_AI_ModelPredict接口进行模型推理。

    ```c
    // 执行模型推理
    OH_AI_TensorHandleArray outputs;
    ret = OH_AI_ModelPredict(model, inputs, &outputs, NULL, NULL);
    if (ret != OH_AI_STATUS_SUCCESS) {
      printf("OH_AI_ModelPredict failed, ret: %d.\n", ret);
      OH_AI_ModelDestroy(&model);
      OH_AI_ContextDestroy(&context);
      return ret;
    }
    ```

6. 获取输出。

    模型推理结束之后，可以通过输出张量得到推理结果。

    ```c
    // 获取模型的输出张量，并打印
    for (size_t i = 0; i < outputs.handle_num; ++i) {
      OH_AI_TensorHandle tensor = outputs.handle_list[i];
      long long element_num = OH_AI_TensorGetElementNum(tensor);
      printf("Tensor name: %s, tensor size is %zu ,elements num: %lld.\n", OH_AI_TensorGetName(tensor),
            OH_AI_TensorGetDataSize(tensor), element_num);
      const float *data = (const float *)OH_AI_TensorGetData(tensor);
      if (data == NULL) {
        printf("OH_AI_TensorGetData failed.\n");
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return OH_AI_STATUS_LITE_ERROR;
      }
      printf("output data is:\n");
      const int max_print_num = 50;
      for (int j = 0; j < element_num && j <= max_print_num; ++j) {
        printf("%f ", data[j]);
      }
      printf("\n");
    }
    ```

7. 释放模型。

    不再使用MindSpore Lite推理框架时，需要释放已经创建的模型。

    ```c
    // 释放模型和上下文
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    ```

## 调测验证

1. 编写CMakeLists.txt。

    ```cmake
    cmake_minimum_required(VERSION 3.14)
    project(Demo)

    add_executable(demo main.c)

    target_link_libraries(
            demo
            mindspore_lite_ndk
            pthread
            dl
    )
    ```
   - 使用ohos-sdk交叉编译，需要指定CMake的工具链路径，即：`-DCMAKE_TOOLCHAIN_FILE="/{sdkPath}/native/build/cmake/ohos.toolchain.cmake"`。
     
     其中，sdkPath为DevEco Studio安装目录下的SDK路径，可在DevEco Studio工程界面，点击**File** > **Settings...** > **OpenHarmony SDK**，查看**Location**获取。
     
   - 工具链默认编译64位的程序，如果要编译32位，需要添加：`-DOHOS_ARCH="armeabi-v7a"`。

2. 运行。

    - 使用hdc_std连接设备，并将demo和mobilenetv2.ms推送到设备中的相同目录。
    - 使用hdc_std shell进入设备，并进入demo所在的目录执行如下命令，即可得到结果。

    ```shell
    ./demo mobilenetv2.ms
    ```

    得到如下输出:

    ```shell
    # ./demo ./mobilenetv2.ms                                            
    Tensor name: Softmax-65, tensor size is 4004 ,elements num: 1001.
    output data is:
    0.000018 0.000012 0.000026 0.000194 0.000156 0.001501 0.000240 0.000825 0.000016 0.000006 0.000007 0.000004 0.000004 0.000004 0.000015 0.000099 0.000011 0.000013 0.000005 0.000023 0.000004 0.000008 0.000003 0.000003 0.000008 0.000014 0.000012 0.000006 0.000019 0.000006 0.000018 0.000024 0.000010 0.000002 0.000028 0.000372 0.000010 0.000017 0.000008 0.000004 0.000007 0.000010 0.000007 0.000012 0.000005 0.000015 0.000007 0.000040 0.000004 0.000085 0.000023 
    ```

## 相关实例

针对MindSpore Lite 的使用，有以下相关实例可供参考：

- [简易MSLite教程](https://gitee.com/openharmony/third_party_mindspore/tree/OpenHarmony-3.2-Release/mindspore/lite/examples/quick_start_c)
