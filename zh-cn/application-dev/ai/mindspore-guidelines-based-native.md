# 使用MindSpore Lite Native API开发AI应用

## 使用场景

开发者可使用[MindSpore Lite提供的Native API](../reference/native-apis/_mind_spore.md)来部署AI算法，并提供高层接口供UI层调用，进行AI模型推理。典型场景如：AI套件SDK开发。

## 基本概念

- [N-API](../reference/native-lib/third_party_napi/napi.md)：用于构建JS本地化组件的一套接口。可利用N-API，将C/C++开发的库封装成JS模块。

## 环境准备

- 安装DevEco Studio，要求版本 >= 3.1.0.500，并更新SDK到API 10或以上。

## 开发步骤

### 1. 新建Native工程

打开DevEco Studio，新建工程，依次点击 **File -> New -> Create Project** 创建 **Native C++** 模板工程。在创建出的工程 **entry/src/main/** 目录下会默认包含 **cpp/** 目录，可以在此目录放置C/C++代码，并提供JS API供UI调用。

### 2. 编写C++推理代码

假设开发者已准备好.ms格式模型。

在使用MindSpore Lite Native API进行开发前，需要先引用对应的头文件。

```c
#include <iostream>
#include <mindspore/model.h>
#include <mindspore/context.h>
#include <mindspore/status.h>
#include <mindspore/tensor.h>
#include <rawfile/raw_file_manager.h>
```

(1). 读取模型文件。

```C++
#define LOGI(...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
#define LOGD(...) ((void)OH_LOG_Print(LOG_APP, LOG_DEBUG, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
#define LOGW(...) ((void)OH_LOG_Print(LOG_APP, LOG_WARN, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
#define LOGE(...) ((void)OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))

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
        LOGE("Read model file failed");
        OH_ResourceManager_CloseRawFile(rawFile);
        return nullptr;
    }
    OH_ResourceManager_CloseRawFile(rawFile);
    *modelSize = fileSize;
    return modelBuffer;
}
```

(2). 创建上下文，设置线程数、设备类型等参数，并加载模型。

```c++
void DestroyModelBuffer(void **buffer) {
    if (buffer == nullptr) {
        return;
    }
    free(*buffer);
    *buffer = nullptr;
}

OH_AI_ModelHandle CreateMSLiteModel(void *modelBuffer, size_t modelSize) {
    // 创建上下文
    auto context = OH_AI_ContextCreate();
    if (context == nullptr) {
        DestroyModelBuffer(&modelBuffer);
        LOGE("Create MSLite context failed.\n");
        return nullptr;
    }
    auto cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
    OH_AI_ContextAddDeviceInfo(context, cpu_device_info);

    // 加载.ms模型文件
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

(3). 设置模型输入数据，执行模型推理并获取输出数据。

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
    // 设置模型输入数据
    auto inputs = OH_AI_ModelGetInputs(model);
    FillInputTensors(inputs);

    auto outputs = OH_AI_ModelGetOutputs(model);
    
    // 执行推理并打印输出
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


(4). 调用以上3个方法，实现完整的模型推理流程。

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

(5). 编写CMake脚本，链接MindSpore Lite动态库`libmindspore_lite_ndk.so`。

```cmake
cmake_minimum_required(VERSION 3.4.1)
project(OHOSMSLiteNapi)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(mslite_napi SHARED mslite_napi.cpp)
target_link_libraries(mslite_napi PUBLIC mindspore_lite_ndk) # 链接MindSpore Lite动态库。
target_link_libraries(mslite_napi PUBLIC hilog_ndk.z)
target_link_libraries(mslite_napi PUBLIC rawfile.z)
target_link_libraries(mslite_napi PUBLIC ace_napi.z)
```


### 3. 使用N-API将C++动态库封装成JS模块


在 **entry/src/main/cpp/types/** 新建 **libmslite_api/** 子目录，并在子目录中创建 **index.d.ts**，内容如下：

```ts
export const runDemo: (a:String, b:Object) => number;
```

以上代码用于定义JS接口`runDemo()` 。

另外，新增 **oh-package.json5** 文件，将API与so相关联，成为一个完整的JS模块：

```json
{
  "name": "libmslite_napi.so",
  "types": "./index.d.ts"
}
```

### 4. 在UI代码中调用封装的MindSpore模块

在 **entry/src/ets/MainAbility/pages/index.ets** 中，定义`onClick()`事件，并在事件回调中调用封装的`runDemo()`接口。

```ts
import hilog from '@ohos.hilog'
import msliteNapi from 'libmslite_napi.so' // 导入msliteNapi模块。
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
                            ret = msliteNapi.runDemo("", mgr); // 调用runDemo()，执行AI模型推理。
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

## 调测验证

在DevEco Studio 中连接设备，点击Run entry运行，应用进程有如下日志：

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

