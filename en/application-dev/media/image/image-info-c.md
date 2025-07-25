# Using Image_NativeModule to Process Image Information

You can use the **ImageInfo** class to set and read the rectangle size, component information, and pixel information of an image.

## How to Develop

### Adding Dependencies

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libohimage.so**, **libimage_receiver.so**, **libnative_image.so**, and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libohimage.so libimage_receiver.so libnative_image.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

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

static void ImageNativeCTest()
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

    // Set the size property in OH_ImageReceiverOptions. This property is a mandatory input parameter and does not actually take effect. Image properties are determined by the producer, for example, the camera.
    errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Set the capacity property of OH_ImageReceiverOptions.
    errCode = OH_ImageReceiverOptions_SetCapacity(options, IMAGE_CAPACITY);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Create an OH_ImageReceiverNative instance.
    OH_ImageReceiverNative* receiver = nullptr;
    errCode = OH_ImageReceiverNative_Create(options, &receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // Read the next image object of OH_ImageReceiverNative.
    OH_ImageNative* image = nullptr;
    errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver next image failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the size property in OH_ImageNative. This property does not actually take effect. Image properties are determined by the producer, for example, the camera.
    Image_Size imgSizeRead;
    errCode = OH_ImageNative_GetImageSize(image, &imgSizeRead);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image size failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the number of elements in the component list of OH_ImageNative.
    size_t componentTypeSize = 0;
    errCode = OH_ImageNative_GetComponentTypes(image, nullptr, &componentTypeSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image component types failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the component list of OH_ImageNative.
    uint32_t* components = new uint32_t[componentTypeSize];
    errCode = OH_ImageNative_GetComponentTypes(image, &components, &componentTypeSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image component types failed, errCode: %{public}d.", errCode);
        delete [] components;
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    delete [] components;

    // Read the buffer object corresponding to the first component of OH_ImageNative.
    OH_NativeBuffer* nativeBuffer = nullptr;
    errCode = OH_ImageNative_GetByteBuffer(image, components[0], &nativeBuffer);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image byte buffer failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the size of the buffer corresponding to the first component of OH_ImageNative.
    size_t nativeBufferSize = 0;
    errCode = OH_ImageNative_GetBufferSize(image, components[0], &nativeBufferSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image buffer size failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the row stride corresponding to the first component of OH_ImageNative.
    int32_t rowStride = 0;
    errCode = OH_ImageNative_GetRowStride(image, components[0], &rowStride);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image row stride failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the pixel stride corresponding to the first component of OH_ImageNative.
    int32_t pixelStride = 0;
    errCode = OH_ImageNative_GetPixelStride(image, components[0], &pixelStride);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image pixel stride failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Read the timestamp of the OH_ImageNative instance.
    int64_t timestamp = 0;
    errCode = OH_ImageNative_GetTimestamp(image, &timestamp);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get timestamp failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // Release the OH_ImageNative instance.
    errCode = OH_ImageNative_Release(image);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image native failed, errCode: %{public}d.", errCode);
    }

    // Release the OH_ImageReceiverOptions instance.
    errCode = OH_ImageReceiverOptions_Release(options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver options failed, errCode: %{public}d.", errCode);
    }

    // Release the OH_ImageReceiverOptions instance.
    errCode = OH_ImageReceiverNative_Release(receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver failed, errCode: %{public}d.", errCode);
    }
}
```
