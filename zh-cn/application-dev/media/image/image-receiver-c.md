# 使用Image_NativeModule完成图片接收器

图像接收类，用于获取组件surface id、接收最新的图片和读取下一张图片、释放ImageReceiver实例。结合camera API实现的相机预览示例代码可参考[C/C++预览流二次处理示例](../camera/native-camera-preview-imageReceiver.md)。

## 开发步骤

### 添加依赖

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libohimage.so、libimage_receiver.so、libnative_image.so以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libohimage.so libimage_receiver.so libnative_image.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/_image___native_module.md)。

在hello.cpp中实现C Native API接口调用逻辑，示例代码如下：

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
    // callback回调处理接收到的图像数据。
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer avaliable.");

    // 读取 OH_ImageReceiverNative 的下一个图片对象。
    OH_ImageNative* image = nullptr;
    errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image); 
    // 结合实际使用情况，此处也可以调用OH_ImageReceiverNative_ReadLatestImage方法获取图像数据。
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver next image failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 应用自行处理image图像数据。
    // ...

    // 释放 OH_ImageNative 实例。
    errCode = OH_ImageNative_Release(image);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image native failed, errCode: %{public}d.", errCode);
    }
}

static OH_ImageReceiverNative* receiver = nullptr;

static void ImageReceiverNativeCTest()
{
    // 创建 OH_ImageReceiverOptions 实例。
    OH_ImageReceiverOptions* options = nullptr;
    Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(&options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver options failed, errCode: %{public}d.", errCode);
        return;
    }

    Image_Size imgSize;
    imgSize.width = IMAGE_WIDTH;
    imgSize.height = IMAGE_HEIGHT;

    // 设置 OH_ImageReceiverOptions 的 size 属性。
    errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 设置 OH_ImageReceiverOptions 的 capacity 属性。
    errCode = OH_ImageReceiverOptions_SetCapacity(options, IMAGE_CAPACITY);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 读取 OH_ImageReceiverOptions 的 size 属性。
    Image_Size imgSizeRead;
    errCode = OH_ImageReceiverOptions_GetSize(options, &imgSizeRead);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 检查读取到的 size 值是否为设定值。
    if (imgSizeRead.width != IMAGE_WIDTH || imgSizeRead.height != IMAGE_HEIGHT) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options size failed, width: %{public}d, height: %{public}d.", imgSizeRead.width, imgSizeRead.height);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 读取 OH_ImageReceiverOptions 的 capacity 属性。
    int32_t capacity = 0；
    errCode = OH_ImageReceiverOptions_GetCapacity(options, &capacity);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 检查读取到的 capacity 值是否为设定值。
    if (capacity != IMAGE_CAPACITY) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver options capacity failed, capacity: %{public}d.", capacity);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 创建 OH_ImageReceiverNative 实例。
    errCode = OH_ImageReceiverNative_Create(options, &receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 注册一个回调事件，每当接收到新的图片，该回调事件就会响应。
    uint64_t surfaceID = 0;
    errCode = OH_ImageReceiverNative_On(receiver, OnCallback);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest image receiver on failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageReceiverNative 的 surfaceID 属性。
    uint64_t surfaceID = 0;
    errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(receiver, &surfaceID);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver surfaceID failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest get image receiver surfaceID: %{public}llu.", surfaceID);

    // 读取 OH_ImageReceiverNative 的 size 属性。
    errCode = OH_ImageReceiverNative_GetSize(receiver, &imgSizeRead);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest get image receiver size: width = %{public}d, height = %{public}d.", imgSizeRead.width, imgSizeRead.height);

    // 读取 OH_ImageReceiverNative 的 capacity 属性。
    errCode = OH_ImageReceiverNative_GetCapacity(receiver, &capacity);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }
    OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest get image receiver capacity: %{public}d.", capacity);

    // 释放 OH_ImageReceiverOptions 实例。
    errCode = OH_ImageReceiverOptions_Release(options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver options failed, errCode: %{public}d.", errCode);
    }
}

// 在合适时机释放ImageReceiverNative相关资源。
static void ImaggReceiverRelease()
{
    // 关闭被 OH_ImageReceiverNative_On 开启的回调事件。
    errCode = OH_ImageReceiverNative_Off(receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest image receiver off failed, errCode: %{public}d.", errCode);
    }

    // 释放 OH_ImageReceiverOptions 实例。
    errCode = OH_ImageReceiverNative_Release(receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver failed, errCode: %{public}d.", errCode);
    }
}

```
