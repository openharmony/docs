# Image Receiving
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This guide uses the APIs provided by the [Image](../../reference/apis-image-kit/capi-image.md) module, which supports basic functionalities such as image encoding/decoding, image receiver operations, and image data processing. These APIs are introduced prior to API version 11, and no additional features will be included in later versions. Therefore, these APIs are not recommended.
>
> You can also use the C APIs provided by the [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md) module, which includes all the foundational features of the Image module while adding new capabilities like multi-image encoding/decoding. For details about the development guide, see [Using Image_NativeModule to Decode Images (C/C++)](image-source-c.md). These APIs are available since API version 12 and are expected to keep evolving. You are encouraged to use them.
>
> You are not advised to use both sets of C APIs in your code. It may cause compatibility issues in some scenarios.

You can use the **ImageReceiver** class to obtain the surface ID of a component, read the latest image or the next image, and release ImageReceiver instances.

## How to Develop

### Adding Dependencies

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libace_napi.z.so**, **libimage_ndk.z.so**, **libimage_receiver_ndk.z.so**, **libnative_image.so**, and **libhilog_ndk.z.so** (on which the native log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libimage_ndk.z.so libimage_receiver_ndk.z.so libnative_image.so)
```

### Adding API Mappings

Open the **src/main/cpp/hello.cpp** file and add the following API mappings to the **Init** function:

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

### Requesting Permissions

To obtain input data of an image from a camera, you must request the **ohos.permission.CAMERA** permission. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Calling APIs on the JS Side

1. Open **src\main\cpp\types\*libentry*\index.d.ts** (where **libentry** varies according to the project name), and import the following files:

    ```js
    import { image } from '@kit.ImageKit';

    export const createFromReceiver: (a: image.ImageReceiver) => image.Image;
    ```

2. Open **src\main\ets\pages\index.ets**, import ***libentry*.so** (where **libentry** varies according to the project name), call the native APIs, and pass in the JS resource object. The following is an example:

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
            // Obtain the supported camera devices.
            let cameraDevices: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
            if (cameraDevices.length <= 0) {
            return;
            }
            // Obtain the profiles of the cameras.
            let profiles: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevices[0], camera.SceneMode.NORMAL_PHOTO);
            let previewProfiles: Array<camera.Profile> = profiles.previewProfiles;
            if (previewProfiles.length <= 0) {
            return;
            }
            let profileObj = previewProfiles[0];
            this.receiver = image.createImageReceiver({width:profileObj.size.width, height:profileObj.size.height}, image.ImageFormat.JPEG, 8);
            let receiverSurfaceId: string = await this.receiver.getReceivingSurfaceId();
            // Create an output object for the preview stream.
            let previewOutput: camera.PreviewOutput = cameraManager.createPreviewOutput(profileObj,receiverSurfaceId);
            let cameraInput : camera.CameraInput = cameraManager.createCameraInput(cameraDevices[0]);
            // Open the camera.
            await cameraInput.open();
            // Create a session.
            let session : camera.PhotoSession = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
            // Configure the session.
            session.beginConfig();
            // Add a CameraInput instance to the session.
            session.addInput(cameraInput);
            // Add the preview stream to the session.
            session.addOutput(previewOutput);
            // Commit the configuration.
            await session.commitConfig();
            // Start the session.
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

### Calling the Native APIs

For details about the APIs, see [Image](../../reference/apis-image-kit/capi-image.md).

Obtain the JS resource object from the **hello.cpp** file and convert it to a native resource object. Then you can call native APIs.

**Adding Reference Files**

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
   // Alternatively, call OH_Image_Receiver_ReadNextImage(imgReceiver_c, &nextImage).
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
