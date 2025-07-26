# 使用MindSpore Lite进行端侧训练 (C/C++)

## 场景介绍

MindSpore Lite是一款AI引擎，它提供了面向不同硬件设备AI模型推理的功能，目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用，同时支持在端侧设备上进行部署训练，让模型在实际业务场景中自适应用户的行为。

本文介绍使用MindSpore Lite端侧AI引擎进行模型训练的通用开发流程。


## 接口说明
此处给出使用MindSpore Lite进行模型训练相关的部分接口，具体请见下方表格。更多接口及详细内容，请见[MindSpore](../../reference/apis-mindspore-lite-kit/capi-mindspore.md)。

| 接口名称        | 描述        |
| ------------------ | ----------------- |
|OH_AI_ContextHandle OH_AI_ContextCreate()|创建一个上下文的对象。注意：此接口需跟OH_AI_ContextDestroy配套使用。|
|OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate(OH_AI_DeviceType device_type)|创建一个运行时设备信息对象。|
|void OH_AI_ContextDestroy(OH_AI_ContextHandle *context)|释放上下文对象。|
|void OH_AI_ContextAddDeviceInfo(OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info)|添加运行时设备信息。|
|OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate()|创建训练配置对象指针。|
|void OH_AI_TrainCfgDestroy(OH_AI_TrainCfgHandle *train_cfg)|销毁训练配置对象指针。|
|OH_AI_ModelHandle OH_AI_ModelCreate()|创建一个模型对象。|
|OH_AI_Status OH_AI_TrainModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context, const OH_AI_TrainCfgHandle train_cfg)|通过模型文件加载并编译MindSpore训练模型。|
|OH_AI_Status OH_AI_RunStep(OH_AI_ModelHandle model, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after)|单步训练模型。|
|OH_AI_Status OH_AI_ModelSetTrainMode(OH_AI_ModelHandle model, bool train)|设置训练模式。|
|OH_AI_Status OH_AI_ExportModel(OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char *model_file, OH_AI_QuantizationType quantization_type, bool export_inference_only, char **output_tensor_name, size_t num)|导出训练后的ms模型。|
|void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)|释放一个模型对象。|


## 开发步骤
使用MindSpore Lite进行模型训练的开发流程如下图所示。

**图 1** 使用MindSpore Lite进行模型训练的开发流程
![how-to-use-train](figures/train_sequence_unify_api.png)

进入主要流程之前需要先引用相关的头文件，并编写函数生成随机的输入，具体如下：

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mindspore/model.h"

int GenerateInputDataWithRandom(OH_AI_TensorHandleArray inputs) {
  for (size_t i = 0; i < inputs.handle_num; ++i) {
    float *input_data = (float *)OH_AI_TensorGetMutableData(inputs.handle_list[i]);
    if (input_data == NULL) {
      printf("OH_AI_TensorGetMutableData failed.\n");
      return  OH_AI_STATUS_LITE_ERROR;
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

然后进入主要的开发步骤，包括模型的准备、读取、编译、训练、模型导出和释放，具体开发过程及细节请见下文的开发步骤及示例。

1. 模型准备。

    准备的模型格式为`.ms`，本文以lenet_train.ms为例（此模型是提前准备的`ms`模型，本文相关效果仅以此模型文件为例）。开发者请自行准备所需的模型，可以按如下步骤操作：

    - 首先基于MindSpore架构使用Python创建网络模型，并导出为`.mindir`文件，详细指南参考[这里](https://www.mindspore.cn/tutorials/zh-CN/r2.1/beginner/quick_start.html)。
    - 然后将`.mindir`模型文件转换成`.ms`文件，转换操作步骤可以参考[训练模型转换](https://www.mindspore.cn/lite/docs/zh-CN/r2.1/use/converter_train.html)，`.ms`文件可以导入端侧设备并基于MindSpore端侧框架进行训练。

2. 创建上下文，设置设备类型、训练配置等参数。

    ```c
    // Create and init context, add CPU device info
    OH_AI_ContextHandle context = OH_AI_ContextCreate();
    if (context == NULL) {
        printf("OH_AI_ContextCreate failed.\n");
        return OH_AI_STATUS_LITE_ERROR;
    }

    OH_AI_DeviceInfoHandle cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
    if (cpu_device_info == NULL) {
        printf("OH_AI_DeviceInfoCreate failed.\n");
        OH_AI_ContextDestroy(&context);
        return OH_AI_STATUS_LITE_ERROR;
    }
    OH_AI_ContextAddDeviceInfo(context, cpu_device_info);

    // Create trainCfg
    OH_AI_TrainCfgHandle trainCfg = OH_AI_TrainCfgCreate();
    if (trainCfg == NULL) {
        printf("OH_AI_TrainCfgCreate failed.\n");
        OH_AI_ContextDestroy(&context);
        return OH_AI_STATUS_LITE_ERROR;
    }
    ```

3. 创建、加载与编译模型。

    调用OH_AI_TrainModelBuildFromFile加载并编译模型。

    ```c
    // Create model
    OH_AI_ModelHandle model = OH_AI_ModelCreate();
    if (model == NULL) {
        printf("OH_AI_ModelCreate failed.\n");
        OH_AI_TrainCfgDestroy(&trainCfg);
        OH_AI_ContextDestroy(&context);
        return OH_AI_STATUS_LITE_ERROR;
    }

    // Build model
    int ret = OH_AI_TrainModelBuildFromFile(model, model_file, OH_AI_MODELTYPE_MINDIR, context, trainCfg);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_TrainModelBuildFromFile failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }
    ```

4. 输入数据。

    模型执行之前需要向输入的张量中填充数据。本例使用随机的数据对模型进行填充。

    ```c
    // Get Inputs
    OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
    if (inputs.handle_list == NULL) {
        printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }

    // Generate random data as input data.
    ret = GenerateInputDataWithRandom(inputs);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }
    ```

5. 执行训练。

    使用OH_AI_ModelSetTrainMode接口设置训练模式，使用OH_AI_RunStep接口进行模型训练。

    ```c
    // Set Train Mode
    ret = OH_AI_ModelSetTrainMode(model, true);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_ModelSetTrainMode failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }

    // Model Train Step
    ret = OH_AI_RunStep(model, NULL, NULL);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_RunStep failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }
    printf("Train Step Success.\n");
    ```

6. 导出训练后模型。

    使用OH_AI_ExportModel接口导出训练后模型。

    ```c
    // Export Train Model
    ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_train_model, OH_AI_NO_QUANT, false, NULL, 0);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_ExportModel train failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }
    printf("Export Train Model Success.\n");

    // Export Inference Model
    ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_infer_model, OH_AI_NO_QUANT, true, NULL, 0);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_ExportModel inference failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        OH_AI_ContextDestroy(&context);
        return ret;
    }
    printf("Export Inference Model Success.\n");
    ```

7. 释放模型。

    不再使用MindSpore Lite推理框架时，需要释放已经创建的模型。

    ```c
    // Delete model and context.
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    ```


## 调测验证

1. 编写CMakeLists.txt。
    ```c
    cmake_minimum_required(VERSION 3.14)
    project(TrainDemo)

    add_executable(train_demo main.c)

    target_link_libraries(
            train_demo
            mindspore_lite_ndk
    )
    ```

   - 使用ohos-sdk交叉编译，需要对CMake设置native工具链路径，即：`-DCMAKE_TOOLCHAIN_FILE="/xxx/native/build/cmake/ohos.toolchain.camke"`。

   - 编译命令如下，其中OHOS_NDK需要设置为native工具链路径：
      ```shell
        mkdir -p build

        cd ./build || exit
        OHOS_NDK=""
        cmake -G "Unix Makefiles" \
              -S ../ \
              -DCMAKE_TOOLCHAIN_FILE="$OHOS_NDK/build/cmake/ohos.toolchain.cmake" \
              -DOHOS_ARCH=arm64-v8a \
              -DCMAKE_BUILD_TYPE=Release

        make
      ```

2. 运行编译的可执行程序。

    - 使用hdc连接设备，并将train_demo和lenet_train.ms推送到设备中的相同目录。
    - 使用hdc shell进入设备，并进入train_demo所在的目录执行如下命令，即可得到结果。

    ```shell
    ./train_demo ./lenet_train.ms export_train_model export_infer_model
    ```

    得到如下输出：

    ```shell
    Train Step Success.
    Export Train Model Success.
    Export Inference Model Success.
    Tensor name: Default/network-WithLossCell/_backbone-LeNet5/fc3-Dense/BiasAdd-op121, tensor size is 80, elements num: 20.
    output data is:
    0.000265 0.000231 0.000254 0.000269 0.000238 0.000228
    ```

    在train_demo所在目录可以看到导出的两个模型文件：export_train_model.ms和export_infer_model.ms。


## 完整示例

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mindspore/model.h"

int GenerateInputDataWithRandom(OH_AI_TensorHandleArray inputs) {
  for (size_t i = 0; i < inputs.handle_num; ++i) {
    float *input_data = (float *)OH_AI_TensorGetMutableData(inputs.handle_list[i]);
    if (input_data == NULL) {
      printf("OH_AI_TensorGetMutableData failed.\n");
      return  OH_AI_STATUS_LITE_ERROR;
    }
    int64_t num = OH_AI_TensorGetElementNum(inputs.handle_list[i]);
    const int divisor = 10;
    for (size_t j = 0; j < num; j++) {
      input_data[j] = (float)(rand() % divisor) / divisor;  // 0--0.9f
    }
  }
  return OH_AI_STATUS_SUCCESS;
}

int ModelPredict(char* model_file) {
  // Create and init context, add CPU device info
  OH_AI_ContextHandle context = OH_AI_ContextCreate();
  if (context == NULL) {
    printf("OH_AI_ContextCreate failed.\n");
    return OH_AI_STATUS_LITE_ERROR;
  }

  OH_AI_DeviceInfoHandle cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
  if (cpu_device_info == NULL) {
    printf("OH_AI_DeviceInfoCreate failed.\n");
    OH_AI_ContextDestroy(&context);
    return OH_AI_STATUS_LITE_ERROR;
  }
  OH_AI_ContextAddDeviceInfo(context, cpu_device_info);

  // Create model
  OH_AI_ModelHandle model = OH_AI_ModelCreate();
  if (model == NULL) {
    printf("OH_AI_ModelCreate failed.\n");
    OH_AI_ContextDestroy(&context);
    return OH_AI_STATUS_LITE_ERROR;
  }

  // Build model
  int ret = OH_AI_ModelBuildFromFile(model, model_file, OH_AI_MODELTYPE_MINDIR, context);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ModelBuildFromFile failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Get Inputs
  OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
  if (inputs.handle_list == NULL) {
    printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Generate random data as input data.
  ret = GenerateInputDataWithRandom(inputs);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Model Predict
  OH_AI_TensorHandleArray outputs;
  ret = OH_AI_ModelPredict(model, inputs, &outputs, NULL, NULL);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("MSModelPredict failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Print Output Tensor Data.
  for (size_t i = 0; i < outputs.handle_num; ++i) {
    OH_AI_TensorHandle tensor = outputs.handle_list[i];
    int64_t element_num = OH_AI_TensorGetElementNum(tensor);
    printf("Tensor name: %s, tensor size is %ld ,elements num: %ld.\n", OH_AI_TensorGetName(tensor),
           OH_AI_TensorGetDataSize(tensor), element_num);
    const float *data = (const float *)OH_AI_TensorGetData(tensor);
    printf("output data is:\n");
    const int max_print_num = 50;
    for (int j = 0; j < element_num && j <= max_print_num; ++j) {
      printf("%f ", data[j]);
    }
    printf("\n");
  }

  OH_AI_ModelDestroy(&model);
  OH_AI_ContextDestroy(&context);
  return OH_AI_STATUS_SUCCESS;
}

int TrainDemo(int argc, const char **argv) {
  if (argc < 4) {
    printf("Model file must be provided.\n");
    printf("Export Train Model path must be provided.\n");
    printf("Export Inference Model path must be provided.\n");
    return OH_AI_STATUS_LITE_ERROR;
  }
  const char *model_file = argv[1];
  const char *export_train_model = argv[2];
  const char *export_infer_model = argv[3];

  // Create and init context, add CPU device info
  OH_AI_ContextHandle context = OH_AI_ContextCreate();
  if (context == NULL) {
    printf("OH_AI_ContextCreate failed.\n");
    return OH_AI_STATUS_LITE_ERROR;
  }

  OH_AI_DeviceInfoHandle cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
  if (cpu_device_info == NULL) {
    printf("OH_AI_DeviceInfoCreate failed.\n");
    OH_AI_ContextDestroy(&context);
    return OH_AI_STATUS_LITE_ERROR;
  }
  OH_AI_ContextAddDeviceInfo(context, cpu_device_info);

  // Create trainCfg
  OH_AI_TrainCfgHandle trainCfg = OH_AI_TrainCfgCreate();
  if (trainCfg == NULL) {
    printf("OH_AI_TrainCfgCreate failed.\n");
    OH_AI_ContextDestroy(&context);
    return OH_AI_STATUS_LITE_ERROR;
  }

  // Create model
  OH_AI_ModelHandle model = OH_AI_ModelCreate();
  if (model == NULL) {
    printf("OH_AI_ModelCreate failed.\n");
    OH_AI_TrainCfgDestroy(&trainCfg);
    OH_AI_ContextDestroy(&context);
    return OH_AI_STATUS_LITE_ERROR;
  }

  // Build model
  int ret = OH_AI_TrainModelBuildFromFile(model, model_file, OH_AI_MODELTYPE_MINDIR, context, trainCfg);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_TrainModelBuildFromFile failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Get Inputs
  OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
  if (inputs.handle_list == NULL) {
    printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Generate random data as input data.
  ret = GenerateInputDataWithRandom(inputs);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Set Train Mode
  ret = OH_AI_ModelSetTrainMode(model, true);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ModelSetTrainMode failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }

  // Model Train Step
  ret = OH_AI_RunStep(model, NULL, NULL);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_RunStep failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }
  printf("Train Step Success.\n");

  // Export Train Model
  ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_train_model, OH_AI_NO_QUANT, false, NULL, 0);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ExportModel train failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }
  printf("Export Train Model Success.\n");

  // Export Inference Model
  ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_infer_model, OH_AI_NO_QUANT, true, NULL, 0);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ExportModel inference failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    OH_AI_ContextDestroy(&context);
    return ret;
  }
  printf("Export Inference Model Success.\n");

  // Delete model and context.
  OH_AI_ModelDestroy(&model);
  OH_AI_ContextDestroy(&context);

  // Use The Exported Model to predict
  char *exported_model = strcat(export_infer_model, ".ms");
  ret = ModelPredict(exported_model);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("Exported Model to predict failed, ret: %d.\n", ret);
    return ret;
  }
  return OH_AI_STATUS_SUCCESS;
}

int main(int argc, const char **argv) { return TrainDemo(argc, argv); }

```