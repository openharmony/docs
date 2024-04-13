# Using the MindSpore Lite Engine for On-Device Training (C/C++)

## When to Use

MindSpore Lite is an AI engine that implements AI model inference for different hardware devices. It has been used in a wide range of fields, such as image classification, target recognition, facial recognition, and character recognition. In addition, MindSpore Lite supports deployment of model training on devices, making it possible to adapt to user behavior in actual service scenarios.

This topic describes the general development process for using MindSpore Lite for model training on devices.


## Available APIs
The following table list some APIs for using MindSpore Lite for model training.

| API       | Description       |
| ------------------ | ----------------- |
|OH_AI_ContextHandle OH_AI_ContextCreate()|Creates a context object.|
|OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate(OH_AI_DeviceType device_type)|Creates a runtime device information object.|
|void OH_AI_ContextDestroy(OH_AI_ContextHandle *context)|Destroys a context object.|
|void OH_AI_ContextAddDeviceInfo(OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info)|Adds a runtime device information object.|
|OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate()|Creates the pointer to a training configuration object.|
|void OH_AI_TrainCfgDestroy(OH_AI_TrainCfgHandle *train_cfg)|Destroys the pointer to a training configuration object.|
|OH_AI_ModelHandle OH_AI_ModelCreate()|Creates a model object.|
|OH_AI_Status OH_AI_TrainModelBuildFromFile(OH_AI_ModelHandle model, const char *model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context, const OH_AI_TrainCfgHandle train_cfg)|Loads and builds a MindSpore training model from a model file.|
|OH_AI_Status OH_AI_RunStep(OH_AI_ModelHandle model, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after)|Runs a single-step training model.|
|OH_AI_Status OH_AI_ModelSetTrainMode(OH_AI_ModelHandle model, bool train)|Sets the training mode.|
|OH_AI_Status OH_AI_ExportModel(OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char *model_file, OH_AI_QuantizationType quantization_type, bool export_inference_only, char **output_tensor_name, size_t num)|Exports a trained MS model.|
|void OH_AI_ModelDestroy(OH_AI_ModelHandle *model)|Destroys a model object.|


## How to Develop
The following figure shows the development process for MindSpore Lite model training.

**Figure 1** Development process for MindSpore Lite model training
![how-to-use-train](figures/train_sequence_unify_api.png)

Before moving to the development process, you need to reference related header files and compile functions to generate random input. The sample code is as follows:

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

The development process consists of the following main steps:

1. Prepare the model.

    The prepared model is in **.ms** format. This topic uses [lenet_train.ms](https://gitee.com/openharmony-sig/compatibility/tree/master/test_suite/resource/master/standard%20system/acts/resource/ai/mindspore/lenet_train/lenet_train.ms) as an example. To use a custom model, perform the following steps:

    - Use Python to create a network model based on the MindSpore architecture and export the model as a **.mindir** file. For details, see [Quick Start](https://www.mindspore.cn/tutorials/en/r2.1/beginner/quick_start.html).
    - Convert the **.mindir** model file into an **.ms** file. For details about the conversion procedure, see [Converting MindSpore Lite Models](https://www.mindspore.cn/lite/docs/en/r2.1/use/converter_train.html). The **.ms** file can be imported to the device to implement training based on the MindSpore device framework.

2. Create a context and set parameters such as the device type and training configuration.

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

3. Create, load, and build the model.

    Call **OH_AI_TrainModelBuildFromFile** to load and build the model.

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
        return ret;
    }
    ```

4. Input data.

    Before executing model training, you need to populate data to the input tensor. In this example, random data is used to populate the model.

    ```c
    // Get Inputs
    OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
    if (inputs.handle_list == NULL) {
        printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        return ret;
    }

    // Generate random data as input data.
    ret = GenerateInputDataWithRandom(inputs);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        return ret;
    }
    ```

5. Execute model training.

    Use **OH_AI_ModelSetTrainMode** to set the training mode and use **OH_AI_RunStep** to run model training.

    ```c
    // Set Traim Mode
    ret = OH_AI_ModelSetTrainMode(model, true);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_ModelSetTrainMode failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        return ret;
    }

    // Model Train Step
    ret = OH_AI_RunStep(model, NULL, NULL);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_RunStep failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        return ret;
    }
    printf("Train Step Success.\n");
    ```

6. Export the trained model.

    Use **OH_AI_ExportModel** to export the trained model.

    ```c
    // Export Train Model
    ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_train_model, OH_AI_NO_QUANT, false, NULL, 0);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_ExportModel train failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        return ret;
    }
    printf("Export Train Model Success.\n");

    // Export Inference Model
    ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_infer_model, OH_AI_NO_QUANT, true, NULL, 0);
    if (ret != OH_AI_STATUS_SUCCESS) {
        printf("OH_AI_ExportModel inference failed, ret: %d.\n", ret);
        OH_AI_ModelDestroy(&model);
        return ret;
    }
    printf("Export Inference Model Success.\n");
    ```

7. Destroy the model.

    If the MindSpore Lite inference framework is no longer needed, you need to destroy the created model.

    ```c
    // Delete model.
    OH_AI_ModelDestroy(&model);
    ```


## Verification

1. Write **CMakeLists.txt**.
    ```c
    cmake_minimum_required(VERSION 3.14)
    project(TrainDemo)

    add_executable(train_demo main.c)

    target_link_libraries(
            train_demo
            mindspore_lite_ndk
    )
    ```

   - To use ohos-sdk for cross compilation, you need to set the native toolchain path for the CMake tool as follows: `-DCMAKE_TOOLCHAIN_FILE="/xxx/native/build/cmake/ohos.toolchain.camke"`.

   - Start cross compilation. When running the compilation command, set **OHOS_NDK** to the native toolchain path.
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

2. Run the executable program for compilation.

    - Use hdc to connect to the device and put **train_demo** and **lenet_train.ms** to the same directory on the device.
    - Use hdc shell to access the device, go to the directory where **train_demo** is located, and run the following command:

    ```shell
    ./train_demo ./lenet_train.ms export_train_model export_infer_model
    ```

    The operation is successful if the output is similar to the following:

    ```shell
    Train Step Success.
    Export Train Model Success.
    Export Inference Model Success.
    Tensor name: Default/network-WithLossCell/_backbone-LeNet5/fc3-Dense/BiasAdd-op121, tensor size is 80, elements num: 20.
    output data is:
    0.000265 0.000231 0.000254 0.000269 0.000238 0.000228
    ```

    In the directory where **train_demo** is located, you can view the exported model files **export_train_model.ms** and **export_infer_model.ms**.


## Sample

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
    return ret;
  }

  // Get Inputs
  OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
  if (inputs.handle_list == NULL) {
    printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }

  // Generate random data as input data.
  ret = GenerateInputDataWithRandom(inputs);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }

  // Model Predict
  OH_AI_TensorHandleArray outputs;
  ret = OH_AI_ModelPredict(model, inputs, &outputs, NULL, NULL);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("MSModelPredict failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
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
    return ret;
  }

  // Get Inputs
  OH_AI_TensorHandleArray inputs = OH_AI_ModelGetInputs(model);
  if (inputs.handle_list == NULL) {
    printf("OH_AI_ModelGetInputs failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }

  // Generate random data as input data.
  ret = GenerateInputDataWithRandom(inputs);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("GenerateInputDataWithRandom failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }

  // Set Traim Mode
  ret = OH_AI_ModelSetTrainMode(model, true);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ModelSetTrainMode failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }

  // Model Train Step
  ret = OH_AI_RunStep(model, NULL, NULL);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_RunStep failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }
  printf("Train Step Success.\n");

  // Export Train Model
  ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_train_model, OH_AI_NO_QUANT, false, NULL, 0);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ExportModel train failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }
  printf("Export Train Model Success.\n");

  // Export Inference Model
  ret = OH_AI_ExportModel(model, OH_AI_MODELTYPE_MINDIR, export_infer_model, OH_AI_NO_QUANT, true, NULL, 0);
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("OH_AI_ExportModel inference failed, ret: %d.\n", ret);
    OH_AI_ModelDestroy(&model);
    return ret;
  }
  printf("Export Inference Model Success.\n");

  // Delete model.
  OH_AI_ModelDestroy(&model);

  // Use The Exported Model to predict
  ret = ModelPredict(strcat(export_infer_model, ".ms"));
  if (ret != OH_AI_STATUS_SUCCESS) {
    printf("Exported Model to predict failed, ret: %d.\n", ret);
    return ret;
  }
  return OH_AI_STATUS_SUCCESS;
}

int main(int argc, const char **argv) { return TrainDemo(argc, argv); }

```
<!--no_check-->