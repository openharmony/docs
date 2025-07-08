# 使用MindSpore Lite实现图像分类（C/C++）

## 场景说明

开发者可以使用[MindSpore](../../reference/apis-mindspore-lite-kit/capi-mindspore.md)，在UI代码中直接集成MindSpore Lite能力，快速部署AI算法，进行AI模型推理，实现图像分类的应用。

图像分类可实现对图像中物体的识别，在医学影像分析、自动驾驶、电子商务、人脸识别等有广泛的应用。

## 基本概念

- N-API：用于构建ArkTS本地化组件的一套接口。可利用N-API，将C/C++开发的库封装成ArkTS模块。

## 开发流程

1. 选择图像分类模型。
2. 在端侧使用MindSpore Lite推理模型，实现对选择的图片进行分类。

## 环境准备

安装DevEco Studio，要求版本 >= 4.1，并更新SDK到API 11或以上。

## 开发步骤

本文以对相册的一张图片进行推理为例，提供使用MindSpore Lite实现图像分类的开发指导。

### 选择模型

本示例程序中使用的图像分类模型文件为[mobilenetv2.ms](https://download.mindspore.cn/model_zoo/official/lite/mobilenetv2_openimage_lite/1.5/mobilenetv2.ms)，放置在entry/src/main/resources/rawfile工程目录下。

如果开发者有其他图像分类的预训练模型，请参考[MindSpore Lite 模型转换](mindspore-lite-converter-guidelines.md)介绍，将原始模型转换成.ms格式。

### 编写代码

#### 图像输入和预处理

1. 此处以获取相册图片为例，调用[@ohos.file.picker](../../reference/apis-core-file-kit/js-apis-file-picker.md) 实现相册图片文件的选择。

2. 根据模型的输入尺寸，调用[@ohos.multimedia.image](../../reference/apis-image-kit/arkts-apis-image.md) （实现图片处理）、[@ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md) （实现基础文件操作） API对选择图片进行裁剪、获取图片buffer数据，并进行标准化处理。

   ```ts
   // Index.ets
   import { fileIo } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { image } from '@kit.ImageKit';
   
   @Entry
   @Component
   struct Index {
     @State modelName: string = 'mobilenetv2.ms';
     @State modelInputHeight: number = 224;
     @State modelInputWidth: number = 224;
     @State uris: Array<string> = [];
   
     build() {
       Row() {
         Column() {
           Button() {
             Text('photo')
               .fontSize(30)
               .fontWeight(FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({
             top: 20
           })
           .backgroundColor('#0D9FFB')
           .width('40%')
           .height('5%')
           .onClick(() => {
             let resMgr = this.getUIContext()?.getHostContext()?.getApplicationContext().resourceManager;
   
             // 获取相册图片
             // 1.创建图片文件选择实例
             let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   
             // 2.设置选择媒体文件类型为IMAGE，设置选择媒体文件的最大数目
             photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
             photoSelectOptions.maxSelectNumber = 1;
   
             // 3.创建图库选择器实例，调用select()接口拉起图库界面进行文件选择。文件选择成功后，返回photoSelectResult结果集。
             let photoPicker = new photoAccessHelper.PhotoViewPicker();
             photoPicker.select(photoSelectOptions,
               async (err: BusinessError, photoSelectResult: photoAccessHelper.PhotoSelectResult) => {
                 if (err) {
                   console.error('MS_LITE_ERR: PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
                   return;
                 }
                 console.info('MS_LITE_LOG: PhotoViewPicker.select successfully, photoSelectResult uri: ' +
                 JSON.stringify(photoSelectResult));
                 this.uris = photoSelectResult.photoUris;
                 console.info('MS_LITE_LOG: uri: ' + this.uris);
                 // 预处理图片数据
                 try {
                   // 1.使用fileIo.openSync接口，通过uri打开这个文件得到fd
                   let file = fileIo.openSync(this.uris[0], fileIo.OpenMode.READ_ONLY);
                   console.info('MS_LITE_LOG: file fd: ' + file.fd);
   
                   // 2.通过fd使用fileIo.readSync接口读取这个文件内的数据
                   let inputBuffer = new ArrayBuffer(4096000);
                   let readLen = fileIo.readSync(file.fd, inputBuffer);
                   console.info('MS_LITE_LOG: readSync data to file succeed and inputBuffer size is:' + readLen);
   
                   // 3.通过PixelMap预处理
                   let imageSource = image.createImageSource(file.fd);
                   imageSource.createPixelMap().then((pixelMap) => {
                     pixelMap.getImageInfo().then((info) => {
                       console.info('MS_LITE_LOG: info.width = ' + info.size.width);
                       console.info('MS_LITE_LOG: info.height = ' + info.size.height);
                       // 4.根据模型输入的尺寸，将图片裁剪为对应的size，获取图片buffer数据readBuffer
                       pixelMap.scale(256.0 / info.size.width, 256.0 / info.size.height).then(() => {
                         pixelMap.crop({
                           x: 16,
                           y: 16,
                           size: { height: this.modelInputHeight, width: this.modelInputWidth }
                         })
                           .then(async () => {
                             let info = await pixelMap.getImageInfo();
                             console.info('MS_LITE_LOG: crop info.width = ' + info.size.width);
                             console.info('MS_LITE_LOG: crop info.height = ' + info.size.height);
                             // 需要创建的像素buffer大小
                             let readBuffer = new ArrayBuffer(this.modelInputHeight * this.modelInputWidth * 4);
                             await pixelMap.readPixelsToBuffer(readBuffer);
                             console.info('MS_LITE_LOG: Succeeded in reading image pixel data, buffer: ' +
                             readBuffer.byteLength);
                             // 处理readBuffer，转换成float32格式，并进行标准化处理
                             const imageArr =
                               new Uint8Array(readBuffer.slice(0, this.modelInputHeight * this.modelInputWidth * 4));
                             console.info('MS_LITE_LOG: imageArr length: ' + imageArr.length);
                             let means = [0.485, 0.456, 0.406];
                             let stds = [0.229, 0.224, 0.225];
                             let float32View = new Float32Array(this.modelInputHeight * this.modelInputWidth * 3);
                             let index = 0;
                             for (let i = 0; i < imageArr.length; i++) {
                               if ((i + 1) % 4 == 0) {
                                 float32View[index] = (imageArr[i - 3] / 255.0 - means[0]) / stds[0]; // B
                                 float32View[index+1] = (imageArr[i - 2] / 255.0 - means[1]) / stds[1]; // G
                                 float32View[index+2] = (imageArr[i - 1] / 255.0 - means[2]) / stds[2]; // R
                                 index += 3;
                               }
                             }
                             console.info('MS_LITE_LOG: float32View length: ' + float32View.length);
                             let printStr = 'float32View data:';
                             for (let i = 0; i < 20; i++) {
                               printStr += ' ' + float32View[i];
                             }
                             console.info('MS_LITE_LOG: float32View data: ' + printStr);
                           })
                       })
                     })
                   })
                 } catch (err) {
                   console.error('MS_LITE_LOG: uri: open file fd failed.' + err);
                 }
               })
           })
         }.width('100%')
       }
       .height('100%')
     }
   }
   ```

#### 编写推理代码

调用[MindSpore](../../reference/apis-mindspore-lite-kit/capi-mindspore.md)实现端侧推理，推理代码流程如下。

1. 引用对应的头文件

   ```c++
   #include <iostream>
   #include <sstream>
   #include <stdlib.h>
   #include <hilog/log.h>
   #include <rawfile/raw_file_manager.h>
   #include <mindspore/types.h>
   #include <mindspore/model.h>
   #include <mindspore/context.h>
   #include <mindspore/status.h>
   #include <mindspore/tensor.h>
   #include "napi/native_api.h"
   ```

2. 读取模型文件

   ```c++
   #define LOGI(...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
   #define LOGD(...) ((void)OH_LOG_Print(LOG_APP, LOG_DEBUG, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
   #define LOGW(...) ((void)OH_LOG_Print(LOG_APP, LOG_WARN, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
   #define LOGE(...) ((void)OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, "[MSLiteNapi]", __VA_ARGS__))
   
   void *ReadModelFile(NativeResourceManager *nativeResourceManager, const std::string &modelName, size_t *modelSize) {
       auto rawFile = OH_ResourceManager_OpenRawFile(nativeResourceManager, modelName.c_str());
       if (rawFile == nullptr) {
           LOGE("MS_LITE_ERR: Open model file failed");
           return nullptr;
       }
       long fileSize = OH_ResourceManager_GetRawFileSize(rawFile);
       void *modelBuffer = malloc(fileSize);
       if (modelBuffer == nullptr) {
           LOGE("MS_LITE_ERR: OH_ResourceManager_ReadRawFile failed");
       }
       int ret = OH_ResourceManager_ReadRawFile(rawFile, modelBuffer, fileSize);
       if (ret == 0) {
           LOGI("MS_LITE_LOG: OH_ResourceManager_ReadRawFile failed");
           OH_ResourceManager_CloseRawFile(rawFile);
           return nullptr;
       }
       OH_ResourceManager_CloseRawFile(rawFile);
       *modelSize = fileSize;
       return modelBuffer;
   }
   ```
   
3. 创建上下文，设置线程数、设备类型等参数，并加载模型。本样例模型，不支持使用NNRt推理。

   ```c++
   void DestroyModelBuffer(void **buffer) {
       if (buffer == nullptr) {
           return;
       }
       free(*buffer);
       *buffer = nullptr;
   }
   
   OH_AI_ContextHandle CreateMSLiteContext(void *modelBuffer) {
       // Set executing context for model.
       auto context = OH_AI_ContextCreate();
       if (context == nullptr) {
           DestroyModelBuffer(&modelBuffer);
           LOGE("MS_LITE_ERR: Create MSLite context failed.\n");
           return nullptr;
       }
       // 本样例模型，不支持配置OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_NNRT)
       auto cpu_device_info = OH_AI_DeviceInfoCreate(OH_AI_DEVICETYPE_CPU);
   
       OH_AI_DeviceInfoSetEnableFP16(cpu_device_info, true);
       OH_AI_ContextAddDeviceInfo(context, cpu_device_info);
       
       LOGI("MS_LITE_LOG: Build MSLite context success.\n");
       return context;
   }
   
   OH_AI_ModelHandle CreateMSLiteModel(void *modelBuffer, size_t modelSize, OH_AI_ContextHandle context) {
       // Create model
       auto model = OH_AI_ModelCreate();
       if (model == nullptr) {
           DestroyModelBuffer(&modelBuffer);
           LOGE("MS_LITE_ERR: Allocate MSLite Model failed.\n");
           return nullptr;
       }
   
       // Build model object
       auto build_ret = OH_AI_ModelBuild(model, modelBuffer, modelSize, OH_AI_MODELTYPE_MINDIR, context);
       DestroyModelBuffer(&modelBuffer);
       if (build_ret != OH_AI_STATUS_SUCCESS) {
           OH_AI_ModelDestroy(&model);
           LOGE("MS_LITE_ERR: Build MSLite model failed.\n");
           return nullptr;
       }
       LOGI("MS_LITE_LOG: Build MSLite model success.\n");
       return model;
   }
   ```

4. 设置模型输入数据，执行模型推理。

   ```c++
   constexpr int K_NUM_PRINT_OF_OUT_DATA = 20;
   
   // 设置模型输入数据
   int FillInputTensor(OH_AI_TensorHandle input, std::vector<float> input_data) {
       if (OH_AI_TensorGetDataType(input) == OH_AI_DATATYPE_NUMBERTYPE_FLOAT32) {
           float *data = (float *)OH_AI_TensorGetMutableData(input);
           for (size_t i = 0; i < OH_AI_TensorGetElementNum(input); i++) {
               data[i] = input_data[i];
           }
           return OH_AI_STATUS_SUCCESS;
       } else {
           return OH_AI_STATUS_LITE_ERROR;
       }
   }
   
   // 执行模型推理
   int RunMSLiteModel(OH_AI_ModelHandle model, std::vector<float> input_data) {
       // Set input data for model.
       auto inputs = OH_AI_ModelGetInputs(model);
   
       auto ret = FillInputTensor(inputs.handle_list[0], input_data);
       if (ret != OH_AI_STATUS_SUCCESS) {
           LOGE("MS_LITE_ERR: RunMSLiteModel set input error.\n");
           return OH_AI_STATUS_LITE_ERROR;
       }
       // Get model output.
       auto outputs = OH_AI_ModelGetOutputs(model);
       // Predict model.
       auto predict_ret = OH_AI_ModelPredict(model, inputs, &outputs, nullptr, nullptr);
       if (predict_ret != OH_AI_STATUS_SUCCESS) {
           LOGE("MS_LITE_ERR: MSLite Predict error.\n");
           return OH_AI_STATUS_LITE_ERROR;
       }
       LOGI("MS_LITE_LOG: Run MSLite model Predict success.\n");
       // Print output tensor data.
       LOGI("MS_LITE_LOG: Get model outputs:\n");
       for (size_t i = 0; i < outputs.handle_num; i++) {
           auto tensor = outputs.handle_list[i];
           LOGI("MS_LITE_LOG: - Tensor %{public}d name is: %{public}s.\n", static_cast<int>(i),
                OH_AI_TensorGetName(tensor));
           LOGI("MS_LITE_LOG: - Tensor %{public}d size is: %{public}d.\n", static_cast<int>(i),
                (int)OH_AI_TensorGetDataSize(tensor));
           LOGI("MS_LITE_LOG: - Tensor data is:\n");
           auto out_data = reinterpret_cast<const float *>(OH_AI_TensorGetData(tensor));
           std::stringstream outStr;
           for (int i = 0; (i < OH_AI_TensorGetElementNum(tensor)) && (i <= K_NUM_PRINT_OF_OUT_DATA); i++) {
               outStr << out_data[i] << " ";
           }
           LOGI("MS_LITE_LOG: %{public}s", outStr.str().c_str());
       }
       return OH_AI_STATUS_SUCCESS;
   }
   ```

5. 调用以上方法，实现完整的模型推理流程。

   ```c++
   static napi_value RunDemo(napi_env env, napi_callback_info info) {
       LOGI("MS_LITE_LOG: Enter runDemo()");
       napi_value error_ret;
       napi_create_int32(env, -1, &error_ret);
       // 传入数据处理
       size_t argc = 2;
       napi_value argv[2] = {nullptr};
       napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
       bool isArray = false;
       napi_is_array(env, argv[0], &isArray);
       uint32_t length = 0;
       // 获取数组的长度
       napi_get_array_length(env, argv[0], &length);
   	LOGI("MS_LITE_LOG: argv array length = %{public}d", length);
       std::vector<float> input_data;
       double param = 0;
       for (int i = 0; i < length; i++) {
           napi_value value;
           napi_get_element(env, argv[0], i, &value);
           napi_get_value_double(env, value, &param);
           input_data.push_back(static_cast<float>(param));
       }
       std::stringstream outstr;
       for (int i = 0; i < K_NUM_PRINT_OF_OUT_DATA; i++) {
           outstr << input_data[i] << " ";
       }
   	LOGI("MS_LITE_LOG: input_data = %{public}s", outstr.str().c_str());
       // Read model file
       const std::string modelName = "mobilenetv2.ms";
       LOGI("MS_LITE_LOG: Run model: %{public}s", modelName.c_str());
       size_t modelSize;
       auto resourcesManager = OH_ResourceManager_InitNativeResourceManager(env, argv[1]);
       auto modelBuffer = ReadModelFile(resourcesManager, modelName, &modelSize);
       if (modelBuffer == nullptr) {
           LOGE("MS_LITE_ERR: Read model failed");
           return error_ret;
       }
       LOGI("MS_LITE_LOG: Read model file success");
       
       auto context = CreateMSLiteContext(modelBuffer);
       if (context == nullptr) {
           LOGE("MS_LITE_ERR: MSLiteFwk Build context failed.\n");
           return error_ret;
       }
       auto model = CreateMSLiteModel(modelBuffer, modelSize, context);
       if (model == nullptr) {
           OH_AI_ContextDestroy(&context);
           LOGE("MS_LITE_ERR: MSLiteFwk Build model failed.\n");
           return error_ret;
       }
       int ret = RunMSLiteModel(model, input_data);
       if (ret != OH_AI_STATUS_SUCCESS) {
           OH_AI_ModelDestroy(&model);
           OH_AI_ContextDestroy(&context);
           LOGE("MS_LITE_ERR: RunMSLiteModel failed.\n");
           return error_ret;
       }
       napi_value out_data;
       napi_create_array(env, &out_data);
       auto outputs = OH_AI_ModelGetOutputs(model);
       OH_AI_TensorHandle output_0 = outputs.handle_list[0];
       float *output0Data = reinterpret_cast<float *>(OH_AI_TensorGetMutableData(output_0));
       for (size_t i = 0; i < OH_AI_TensorGetElementNum(output_0); i++) {
           napi_value element;
           napi_create_double(env, static_cast<double>(output0Data[i]), &element);
           napi_set_element(env, out_data, i, element);
       }
       OH_AI_ModelDestroy(&model);
       OH_AI_ContextDestroy(&context);
       LOGI("MS_LITE_LOG: Exit runDemo()");
       return out_data;
   }
   ```

6. 编写CMake脚本，链接MindSpore Lite动态库。

   ```c++
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(MindSporeLiteCDemo)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   if(DEFINED PACKAGE_FIND_FILE)
       include(${PACKAGE_FIND_FILE})
   endif()
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   
   add_library(entry SHARED mslite_napi.cpp)
   target_link_libraries(entry PUBLIC mindspore_lite_ndk)
   target_link_libraries(entry PUBLIC hilog_ndk.z)
   target_link_libraries(entry PUBLIC rawfile.z)
   target_link_libraries(entry PUBLIC ace_napi.z)
   ```

#### 使用N-API将C++动态库封装成ArkTS模块

1. 在 entry/src/main/cpp/types/libentry/Index.d.ts，定义ArkTS接口`runDemo()` 。内容如下：

   ```ts
   export const runDemo: (a: number[], b:Object) => Array<number>;
   ```

2. 在 oh-package.json5 文件，将API与so相关联，成为一个完整的ArkTS模块：

   ```json
   {
     "name": "libentry.so",
     "types": "./Index.d.ts",
     "version": "1.0.0",
     "description": "MindSpore Lite inference module"
   }
   ```

#### 调用封装的ArkTS模块进行推理并输出结果

在 entry/src/main/ets/pages/Index.ets 中，调用封装的ArkTS模块，最后对推理结果进行处理。

```ts
// Index.ets
import msliteNapi from 'libentry.so'

@Entry
@Component
struct Index {
  @State modelInputHeight: number = 224;
  @State modelInputWidth: number = 224;
  @State max: number = 0;
  @State maxIndex: number = 0;
  @State maxArray: Array<number> = [];
  @State maxIndexArray: Array<number> = [];

  build() {
    Row() {
      Column() {
        Button() {
          Text('photo')
            .fontSize(30)
            .fontWeight(FontWeight.Bold)
        }
        .type(ButtonType.Capsule)
        .margin({
          top: 20
        })
        .backgroundColor('#0D9FFB')
        .width('40%')
        .height('5%')
        .onClick(() => {
          let resMgr = this.getUIContext()?.getHostContext()?.getApplicationContext().resourceManager;
          let float32View = new Float32Array(this.modelInputHeight * this.modelInputWidth * 3);
          // 图像输入和预处理。
          // 调用c++的runDemo方法，完成图像输入和预处理后的buffer数据保存在float32View，具体可见上文图像输入和预处理中float32View的定义和处理。
          console.info('MS_LITE_LOG: *** Start MSLite Demo ***');
          let output: Array<number> = msliteNapi.runDemo(Array.from(float32View), resMgr);

          // 取分类占比的最大值
          this.max = 0;
          this.maxIndex = 0;
          this.maxArray = [];
          this.maxIndexArray = [];
          let newArray = output.filter(value => value !== this.max);
          for (let n = 0; n < 5; n++) {
            this.max = output[0];
            this.maxIndex = 0;
            for (let m = 0; m < newArray.length; m++) {
              if (newArray[m] > this.max) {
                this.max = newArray[m];
                this.maxIndex = m;
              }
            }
            this.maxArray.push(Math.round(this.max * 10000));
            this.maxIndexArray.push(this.maxIndex);
            // filter数组过滤函数
            newArray = newArray.filter(value => value !== this.max);
          }
          console.info('MS_LITE_LOG: max:' + this.maxArray);
          console.info('MS_LITE_LOG: maxIndex:' + this.maxIndexArray);
          console.info('MS_LITE_LOG: *** Finished MSLite Demo ***');
        })
      }.width('100%')
    }
    .height('100%')
  }
}
```

### 调测验证

1. 在DevEco Studio中连接设备，点击Run entry，编译Hap，有如下显示：

   ```shell
   Launching com.samples.mindsporelitecdemo
   $ hdc shell aa force-stop com.samples.mindsporelitecdemo
   $ hdc shell mkdir data/local/tmp/xxx
   $ hdc file send C:\Users\xxx\MindSporeLiteCDemo\entry\build\default\outputs\default\entry-default-signed.hap "data/local/tmp/xxx"
   $ hdc shell bm install -p data/local/tmp/xxx
   $ hdc shell rm -rf data/local/tmp/xxx
   $ hdc shell aa start -a EntryAbility -b com.samples.mindsporelitecdemo
   ```

2. 在设备屏幕点击photo按钮，选择图片，点击确定。设备屏幕显示所选图片的分类结果，在日志打印结果中，过滤关键字”MS_LITE“，可得到如下结果：

   ```verilog
   08-05 17:15:52.001   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: PhotoViewPicker.select successfully, photoSelectResult uri: {"photoUris":["file://media/Photo/13/IMG_1501955351_012/plant.jpg"]}
   ...
   08-05 17:15:52.627   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: crop info.width = 224
   08-05 17:15:52.627   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: crop info.height = 224
   08-05 17:15:52.628   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: Succeeded in reading image pixel data, buffer: 200704
   08-05 17:15:52.971   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: float32View data: float32View data: 1.2385478019714355 1.308123230934143 1.4722440242767334 1.2385478019714355 1.308123230934143 1.4722440242767334 1.2385478019714355 1.308123230934143 1.4722440242767334 1.2385478019714355 1.308123230934143 1.4722440242767334 1.2385478019714355 1.308123230934143 1.4722440242767334 1.2385478019714355 1.308123230934143 1.4722440242767334 1.2385478019714355 1.308123230934143
   08-05 17:15:52.971   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: *** Start MSLite Demo ***
   08-05 17:15:53.454   4684-4684    A00000/[MSLiteNapi]            pid-4684              I     MS_LITE_LOG: Build MSLite model success.
   08-05 17:15:53.753   4684-4684    A00000/[MSLiteNapi]            pid-4684              I     MS_LITE_LOG: Run MSLite model Predict success.
   08-05 17:15:53.753   4684-4684    A00000/[MSLiteNapi]            pid-4684              I     MS_LITE_LOG: Get model outputs:
   08-05 17:15:53.753   4684-4684    A00000/[MSLiteNapi]            pid-4684              I     MS_LITE_LOG: - Tensor 0 name is: Default/head-MobileNetV2Head/Sigmoid-op466.
   08-05 17:15:53.753   4684-4684    A00000/[MSLiteNapi]            pid-4684              I     MS_LITE_LOG: - Tensor data is:
   08-05 17:15:53.753   4684-4684    A00000/[MSLiteNapi]            pid-4684              I     MS_LITE_LOG: 3.43385e-06 1.40285e-05 9.11969e-07 4.91007e-05 9.50266e-07 3.94537e-07 0.0434676 3.97196e-05 0.00054832 0.000246202 1.576e-05 3.6494e-06 1.23553e-05 0.196977 5.3028e-05 3.29346e-05 4.90475e-07 1.66109e-06 7.03273e-06 8.83677e-07 3.1365e-06
   08-05 17:15:53.781   4684-4684    A03d00/JSAPP                   pid-4684              W     MS_LITE_WARN: output length =  500 ;value =  0.0000034338463592575863,0.000014028532859811094,9.119685273617506e-7,0.000049100715841632336,9.502661555416125e-7,3.945370394831116e-7,0.04346757382154465,0.00003971960904891603,0.0005483203567564487,0.00024620210751891136,0.000015759984307806008,0.0000036493988773145247,0.00001235533181898063,0.1969769448041916,0.000053027983085485175,0.000032934600312728435,4.904751449430478e-7,0.0000016610861166554969,0.000007032729172351537,8.836767619868624e-7
   08-05 17:15:53.831   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: max:9497,7756,1970,435,46
   08-05 17:15:53.831   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: maxIndex:323,46,13,6,349
   08-05 17:15:53.831   4684-4684    A03d00/JSAPP                   pid-4684              I     MS_LITE_LOG: *** Finished MSLite Demo ***
   ```


### 效果示意

在设备上，点击photo按钮，选择相册中的一张图片，点击确定。在图片下方显示此图片占比前4的分类信息。

![stepc1](figures/stepc1.png)           ![step2](figures/step2.png)

![step3](figures/step3.png)         ![stepc4](figures/stepc4.png) 

## 相关实例

针对使用MindSpore Lite进行图像分类应用的开发，有以下相关实例可供参考：

- [基于Native接口的MindSpore Lite应用开发（C/C++）（API11）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ApplicationModels/MindSporeLiteCDemo)

