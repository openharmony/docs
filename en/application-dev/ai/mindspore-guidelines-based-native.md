# Using MindSpore Lite Native APIs to Develop AI Applications

## Scenarios

You can use the native APIs provided by [MindSpore Lite](../reference/native-apis/_mind_spore.md) to deploy AI algorithms and provides APIs for the UI layer to invoke the algorithms for model inference. A typical scenario is the AI SDK development.

## Basic concepts

- [N-API](../reference/native-lib/third_party_napi/napi.md): a set of native APIs used to build JavaScript components. N-APIs can be used to encapsulate libraries developed using C/C++ into JavaScript modules.

## Preparing the Environment

- Install DevEco Studio 3.1.0.500 or later, and update the SDK to API version 10 or later.

## How to Develop

### 1. Create a native C++ project.

Open DevEco Studio, choose **File** > **New** > **Create Project** to create a native C++ template project. By default, the **entry/src/main/** directory of the created project contains the **cpp/** directory. You can store C/C++ code in this directory and provide JavaScript APIs for the UI layer to call the code.

### 2. Compile the C++ inference code.

Assume that you have prepared a model in the **.ms** format.

Before using the Native APIs provided by MindSpore Lite for development, you need to reference the corresponding header files.

```c
#include <iostream>
#include <mindspore/model.h>
#include <mindspore/context.h>
#include <mindspore/status.h>
#include <mindspore/tensor.h>
#include <rawfile/raw_file_manager.h>
```

(1). Read model files.

```C++
void *ReadModelFile(NativeResourceManager *nativeResourceManager, const std::string &modelName, size_t *modelSize) {
    auto rawFile = OH_ResourceManager_OpenRawFile(nativeResourceManager, modelName.c_str());
    if (rawFile == nullptr) {
        LOGE("Open model file failed");
        return nullptr;
    }
    long fileSize = OH_ResourceManager_GetRawFileSize(rawFile);
    void *modelBuffer = malloc(fileSize);
    if (modelBuffer == nullptr) {
        LOGE("Get model file size failed");
    }
    int ret = OH_ResourceManager_ReadRawFile(rawFile, modelBuffer, fileSize);
    if (ret == 0) {
        LOGI("Read model file failed");
        OH_ResourceManager_CloseRawFile(rawFile);
        return nullptr;
    }
    OH_ResourceManager_CloseRawFile(rawFile);
    *modelSize = fileSize;
    return modelBuffer;
}
```

(2). Create a context, set parameters such as the number of threads and device type, and load the model.

```c++
void DestroyModelBuffer(void **buffer) {
    if (buffer == nullptr) {
        return;
    }
    free(*buffer);
    *buffer = nullptr;
}

OH_AI_ModelHandle CreateMSLiteModel(void *modelBuffer, size_t modelSize) {
    // Create a context.
    auto context = OH_AI_ContextCreate();
    if (context == nullptr) {
        DestroyModelBuffer(&modelBuffer);
        LOGE("Create MSLite context failed.\n");
        return nullptr;
    }
    auto cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
    OH_AI_ContextAddDeviceInfo(context, cpu_device_info);

    // Load the .ms model file.
    auto model = OH_AI_ModelCreate();
    if (model == nullptr) {
        DestroyModelBuffer(&modelBuffer);
        LOGE("Allocate MSLite Model failed.\n");
        return nullptr;
    }

    auto build_ret = OH_AI_ModelBuild(model, modelBuffer, modelSize, OH_AI_MODELTYPE_MINDIR, context);
    DestroyModelBuffer(&modelBuffer);
    if (build_ret != OH_AI_STATUS_SUCCESS) {
        OH_AI_ModelDestroy(&model);
        LOGE("Build MSLite model failed.\n");
        return nullptr;
    }
    LOGI("Build MSLite model success.\n");
    return model;
}
```

(3). Set the model input data, perform model inference, and obtain the output data.

```c++
#define GET_PARAMS(env, info, num)    \
    size_t argc = num;                \
    napi_value argv[num] = {nullptr}; \
    napi_value thisVar = nullptr;     \
    void *data = nullptr;             \
    napi_get_cb_info(env, info, &argc, argv, &thisVar, &data)

constexpr int kNumPrintOfOutData = 10;
constexpr int RANDOM_RANGE = 128;

void FillTensorWithRandom(OH_AI_TensorHandle msTensor) {
    auto size = OH_AI_TensorGetDataSize(msTensor);
    char *data = (char *)OH_AI_TensorGetMutableData(msTensor);
    for (size_t i = 0; i < size; i++) {
        data[i] = (char)(rand() / RANDOM_RANGE);
    }
}

// fill data to inputs tensor
int FillInputTensors(OH_AI_TensorHandleArray &inputs) {
    for (size_t i = 0; i < inputs.handle_num; i++) {
        FillTensorWithRandom(inputs.handle_list[i]);
    }
    return OH_AI_STATUS_SUCCESS;
}

void RunMSLiteModel(OH_AI_ModelHandle model) {
    // Set the model input data.
    auto inputs = OH_AI_ModelGetInputs(model);
    FillInputTensors(inputs);

    auto outputs = OH_AI_ModelGetOutputs(model);
    
    // Perform inference and print the output.
    auto predict_ret = OH_AI_ModelPredict(model, inputs, &outputs, nullptr, nullptr);
    if (predict_ret != OH_AI_STATUS_SUCCESS) {
        OH_AI_ModelDestroy(&model);
        LOGE("Predict MSLite model error.\n");
        return;
    }
    LOGI("Run MSLite model success.\n");

    LOGI("Get model outputs:\n");
    for (size_t i = 0; i < outputs.handle_num; i++) {
        auto tensor = outputs.handle_list[i];
        LOGI("- Tensor %{public}d name is: %{public}s.\n", static_cast<int>(i), OH_AI_TensorGetName(tensor));
        LOGI("- Tensor %{public}d size is: %{public}d.\n", static_cast<int>(i), (int)OH_AI_TensorGetDataSize(tensor));
        auto out_data = reinterpret_cast<const float *>(OH_AI_TensorGetData(tensor));
        std::cout << "Output data is:";
        for (int i = 0; (i < OH_AI_TensorGetElementNum(tensor)) && (i <= kNumPrintOfOutData); i++) {
            std::cout << out_data[i] << " ";
        }
        std::cout << std::endl;
    }
    OH_AI_ModelDestroy(&model);
}
```


(4). Implement a complete model inference process.

```C++
static napi_value RunDemo(napi_env env, napi_callback_info info)
{
    LOGI("Enter runDemo()");
    GET_PARAMS(env, info, 2);
    napi_value error_ret;
    napi_create_int32(env, -1, &error_ret);
    
    const std::string modelName = "ml_headpose.ms";
    size_t modelSize;
    auto resourcesManager = OH_ResourceManager_InitNativeResourceManager(env, argv[1]);
    auto modelBuffer = ReadModelFile(resourcesManager, modelName, &modelSize);
    if (modelBuffer == nullptr) {
        LOGE("Read model failed");
        return error_ret;
    }
    LOGI("Read model file success");

    auto model = CreateMSLiteModel(modelBuffer, modelSize);
    if (model == nullptr) {
        OH_AI_ModelDestroy(&model);
        LOGE("MSLiteFwk Build model failed.\n");
        return error_ret;
    }

    RunMSLiteModel(model);

    napi_value success_ret;
    napi_create_int32(env, 0, &success_ret);

    LOGI("Exit runDemo()");
    return success_ret;
}
```

(5). Write the **CMake** script to link the MindSpore Lite dynamic library `libmindspore_lite_ndk.so`.

```cmake
cmake_minimum_required(VERSION 3.4.1)
project(OHOSMSLiteNapi)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(mslite_napi SHARED mslite_napi.cpp)
target_link_libraries(mslite_napi PUBLIC mindspore_lite_ndk) # MindSpore Lite dynamic library to link
target_link_libraries(mslite_napi PUBLIC hilog_ndk.z)
target_link_libraries(mslite_napi PUBLIC rawfile.z)
target_link_libraries(mslite_napi PUBLIC ace_napi.z)
```


### 3. Use N-APIs to encapsulate C++ dynamic libraries into JavaScript modules.


Create the **libmslite_api/** subdirectory in **entry/src/main/cpp/types/**, and create the **index.d.ts** file in the subdirectory. The file content is as follows:

```ts
export const runDemo: (a:String, b:Object) => number;
```

Use the preceding code to define the JavaScript API `runDemo()`.

In addition, add the **oh-package.json5** file to associate the API with the **.so** file to form a complete JavaScript module.

```json
{
  "name": "libmslite_napi.so",
  "types": "./index.d.ts"
}
```

### 4. Invoke the encapsulated MindSpore module in the UI code.

In **entry/src/ets/MainAbility/pages/index.ets**, define the **onClick()** event and call the encapsulated **runDemo()** API in the event callback.

```ts
import hilog from '@ohos.hilog'
import msliteNapi from'libmslite_napi.so' // Import the msliteNapi module.
import resManager from '@ohos.resourceManager'

const TAG = 'MSLiteNativeDemo'

@Entry
@Component
struct Index {
    @State message: string = 'MindSpore Lite Demo'
    build() {
        Row() {
            Column() {
                Text(this.message)
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
                    .onClick(() => {
                        resManager.getResourceManager().then(mgr => {
                            hilog.info(0x0000, TAG, '*** Start MSLite Demo ***');
                            let ret: number = 0;
                            ret = msliteNapi.runDemo("", mgr); // Call runDemo() to perform AI model inference.
                            if (ret == -1) {
                                hilog.info(0x0000, TAG, 'Error when running MSLite Demo!');
                            }
                            hilog.info(0x0000, TAG, '*** Finished MSLite Demo ***');
                        })
                    })
            }
            .width('100%')
        }
        .height('100%')
    }
}
```

## Debugging and Verification

On DevEco Studio, connect to the device and click **Run entry**. The following log is generated for the application process:

```text
08-08 16:55:33.766 1513-1529/com.mslite.native_demo I A00000/MSLiteNativeDemo: *** Start MSLite Demo ***
08-08 16:55:33.766 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: Enter runDemo()
08-08 16:55:33.772 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: Read model file success
08-08 16:55:33.799 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: Build MSLite model success.
08-08 16:55:33.818 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: Run MSLite model success.
08-08 16:55:33.818 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: Get model outputs:
08-08 16:55:33.818 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: - Tensor 0 name is: output_node_0.
08-08 16:55:33.818 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: - Tensor 0 size is: 12.
08-08 16:55:33.826 1513-1529/com.mslite.native_demo I A00000/[MSLiteNapi]: Exit runDemo()
08-08 16:55:33.827 1513-1529/com.mslite.native_demo I A00000/MSLiteNativeDemo: *** Finished MSLite Demo ***
```
