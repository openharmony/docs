# 图片接收
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

图片接收类，用于获取组件surface id，接收最新的图片和读取下一张图片，以及释放ImageReceiver实例。

## 开发步骤

### 添加依赖

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libace_napi.z.so、libimage_ndk.z.so、libimage_receiver_ndk.z.so、libnative_image.so以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libimage_ndk.z.so libimage_receiver_ndk.z.so libnative_image.so)
```

### 添加接口映射

打开src/main/cpp/hello.cpp文件，在Init函数中添加接口映射如下：

```c++
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "createFromReceiver", nullptr, createFromReceiver, nullptr, nullptr, nullptr, napi_default, nullptr },
    };

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

### 添加权限申请

此处通过camera图片获取输入数据，需要申请权限ohos.permission.CAMERA，申请方式请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### JS侧调用

1. 打开src\main\cpp\types\libentry\index.d.ts（其中libentry根据工程名生成），导入如下引用文件：

    ```js
    import { image } from '@kit.ImageKit';

    export const createFromReceiver: (a: image.ImageReceiver) => image.Image;
    ```

2. 打开src\main\ets\pages\index.ets，导入"libentry.so（根据工程名生成）"，调用Native接口，传入JS的资源对象。示例如下：

    ```js
    import testNapi from 'libentry.so';
    import { image } from '@kit.ImageKit';
    import { common, abilityAccessCtrl } from '@kit.AbilityKit';
    import { camera } from '@kit.CameraKit';

    @Entry
    @Component
    struct Index {
      private receiver: image.ImageReceiver | undefined = undefined;
      func (){
         let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
         abilityAccessCtrl.createAtManager().requestPermissionsFromUser(context,['ohos.permission.CAMERA']).then(async () => {
            let cameraManager = await camera.getCameraManager(context);
            // 获取支持的相机设备对象。
            let cameraDevices: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
            if (cameraDevices.length <= 0) {
            return;
            }
            // 获取对应相机设备的profiles。
            let profiles: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevices[0], camera.SceneMode.NORMAL_PHOTO);
            let previewProfiles: Array<camera.Profile> = profiles.previewProfiles;
            if (previewProfiles.length <= 0) {
            return;
            }
            let profileObj = previewProfiles[0];
            this.receiver = image.createImageReceiver({width:profileObj.size.width, height:profileObj.size.height}, image.ImageFormat.JPEG, 8);
            let receiverSurfaceId: string = await this.receiver.getReceivingSurfaceId();
            // 创建预览流输出对象。
            let previewOutput: camera.PreviewOutput = cameraManager.createPreviewOutput(profileObj,receiverSurfaceId);
            let cameraInput : camera.CameraInput = cameraManager.createCameraInput(cameraDevices[0]);
            // 打开相机。
            await cameraInput.open();
            // 会话流程。
            let session : camera.PhotoSession = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
            // 配置会话。
            session.beginConfig();
            // 把cameraInput加入到会话。
            session.addInput(cameraInput);
            // 把预览流加入到会话。
            session.addOutput(previewOutput);
            // 提交配置信息。
            await session.commitConfig();
            // 会话开始。
            await session.start();

            this.receiver.on('imageArrival', () => {
               let img : image.Image = testNapi.createFromReceiver(this.receiver);
               img.release();
            })

         });
      }

      build() {
         Row() {
            Column() {
            Button("start")
               .width(100)
               .height(100)
               .onClick(() => {
                  console.info("button click in");
                  if (this.receiver == undefined) {
                     this.func();
                  }
               })
            }
            .width('100%')
         }
         .height('100%')
      }
    }
    ```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image.md)。

在hello.cpp文件中获取JS的资源对象，并转为Native的资源对象，即可调用Native接口，调用方式示例代码如下：

**添加引用文件**

```c++
#include <multimedia/image_framework/image_mdk.h>
#include <multimedia/image_framework/image_receiver_mdk.h>
#include <malloc.h>
#include <hilog/log.h>

static napi_value createFromReceiver(napi_env env, napi_callback_info info)
{
   size_t argc = 1;
   napi_value args[2] = {nullptr};
   napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
   napi_valuetype valuetype0;
   napi_typeof(env, args[0], &valuetype0);
   napi_ref reference;
   napi_create_reference(env, args[0], 1 ,&reference);
   napi_value imgReceiver_js;
   napi_get_reference_value(env, reference, &imgReceiver_js);
   
   ImageReceiverNative * imgReceiver_c = OH_Image_Receiver_InitImageReceiverNative(env, imgReceiver_js);

   int32_t capacity;
   OH_Image_Receiver_GetCapacity(imgReceiver_c, &capacity);
   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[receiver]", "capacity: %{public}d", capacity);
   int32_t format;
   OH_Image_Receiver_GetFormat(imgReceiver_c, &format);
   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[receiver]", "format: %{public}d", format);
   char * surfaceId = static_cast<char *>(malloc(sizeof(char)));
   OH_Image_Receiver_GetReceivingSurfaceId(imgReceiver_c, surfaceId, sizeof(char));
   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[receiver]", "surfaceId: %{public}c", surfaceId[0]);
   OhosImageSize size;
   OH_Image_Receiver_GetSize(imgReceiver_c, &size);
   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[receiver]", "OH_Image_Receiver_GetSize  width: %{public}d, height:%{public}d", size.width, size.height);
   
   int32_t ret;
   napi_value nextImage;
   // 或调用 OH_Image_Receiver_ReadNextImage(imgReceiver_c, &nextImage);
   ret = OH_Image_Receiver_ReadLatestImage(imgReceiver_c, &nextImage);
   
   ImageNative * nextImage_native = OH_Image_InitImageNative(env, nextImage);

   OhosImageSize imageSize;
   OH_Image_Size(nextImage_native, &imageSize);
   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[receiver]", "OH_Image_Size  width: %{public}d, height:%{public}d", imageSize.width, imageSize.height);

   OhosImageComponent imgComponent;
   ret = OH_Image_GetComponent(nextImage_native, 4, &imgComponent); // 4=jpeg
   
   uint8_t *img_buffer = imgComponent.byteBuffer;
   
   ret = OH_Image_Release(nextImage_native);
   ret = OH_Image_Receiver_Release(imgReceiver_c);
   return nextImage;
}
```
