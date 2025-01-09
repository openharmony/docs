# Using Image_NativeModule to Receive Images

You can use the **ImageReceiver** class to obtain the surface ID of a component, read the latest image or the next image, and release **ImageReceiver** instances. For details about the sample code of camera preview implemented with the use of the camera API, see [Secondary Processing of Preview Streams (C/C++)](../camera/native-camera-preview-imageReceiver.md).

## How to Develop

### Adding Dependencies

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libohimage.so**, **libimage_receiver.so**, **libnative_image.so**, and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libohimage.so libimage_receiver.so libnative_image.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).

Implement the C native APIs in **hello.cpp**. Refer to the sample code below.

```c++
#include <hilog/log.h>
#include <multimedia/image_framework/image/image_native.h>
#include <multimedia/image_framework/image/image_receiver_native.h>

#undef LOG_DOMAIN
#define LOG_DOMAIN 0x3200

#undef LOG_TAG
#define LOG_TAG "MY_TAG"

#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 480
#define IMAGE_CAPACITY 2

static void OnCallback(OH_ImageReceiverNative *receiver)
{
    // Callback for processing the received image data.
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer avaliable.");

    // Read the next image object of OH_ImageReceiverNative.
    OH_ImageNative* image = nullptr;
    errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image); 
    // You can also call OH_ImageReceiverNative_ReadLatestImage to obtain image data.
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver next image failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // The application processes the image data.
    // ...

    // Release the OH_ImageNative instance.
    errCode = OH_ImageNative_Release(image);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image native failed, errCode: %{public}d.", errCode);
    }
}

static OH_ImageReceiverNative* receiver = nullptr;

static void ImageReceiverNativeCTest()
{
    // Create an OH_ImageReceiverOptions instance.
    OH_ImageReceiverOptions* options = nullptr;
    Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(&options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver options failed, errCode: %{public}d.", errCode);
        return;
    }

    Image_Size imgSize;
    imgSize.width = IMAGE_WIDTH;
    imgSize.height = IMAGE_HEIGHT;

    // Set the size attribute of OH_ImageReceiverOptions.
    errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Set the capacity attribute of OH_ImageReceiverOptions.
    errCode = OH_ImageReceiverOptions_SetCapacity(options, IMAGE_CAPACITY);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Read the size attribute of OH_ImageReceiverOptions.
    Image_Size imgSizeRead;
    errCode = OH_ImageReceiverOptions_GetSize(options, &imgSizeRead);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Check whether the size read is the same as the size set.
    if (imgSizeRead.width != IMAGE_WIDTH || imgSizeRead.height != IMAGE_HEIGHT) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options size failed, width: %{public}d, height: %{public}d.", imgSizeRead.width, imgSizeRead.height);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Read the capacity attribute of OH_ImageReceiverOptions.
    int32_t capacity = 0;
    errCode = OH_ImageReceiverOptions_GetCapacity(options, &capacity);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Check whether the capacity read is the same as the capacity set.
    if (capacity != IMAGE_CAPACITY) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options capacity failed, capacity: %{public}d.", capacity);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Create an OH_ImageReceiverNative instance.
    errCode = OH_ImageReceiverNative_Create(options, &receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Register a callback event. Each time a new image is received, the callback event is triggered.
    uint64_t surfaceID = 0;
    errCode = OH_ImageReceiverNative_On(receiver, OnCallback);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest image receiver on failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the surface ID attribute of OH_ImageReceiverNative.
    uint64_t surfaceID = 0;
    errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(receiver, &surfaceID);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver surfaceID failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest get image receiver surfaceID: %{public}llu.", surfaceID);

    // Read the size attribute of OH_ImageReceiverNative.
    errCode = OH_ImageReceiverNative_GetSize(receiver, &imgSizeRead);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest get image receiver size: width = %{public}d, height = %{public}d.", imgSizeRead.width, imgSizeRead.height);

    // Read the capacity attribute of OH_ImageReceiverNative.
    errCode = OH_ImageReceiverNative_GetCapacity(receiver, &capacity);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest get image receiver capacity: %{public}d.", capacity);

    // Release the OH_ImageReceiverOptions instance.
    errCode = OH_ImageReceiverOptions_Release(options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver options failed, errCode: %{public}d.", errCode);
    }
}

// Release ImageReceiverNative resources at a proper time.
static void ImaggReceiverRelease()
{
    // Unregister the callback event registered by calling OH_ImageReceiverNative_On.
    errCode = OH_ImageReceiverNative_Off(receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest image receiver off failed, errCode: %{public}d.", errCode);
    }

    // Release the OH_ImageReceiverOptions instance.
    errCode = OH_ImageReceiverNative_Release(receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver failed, errCode: %{public}d.", errCode);
    }
}

```
