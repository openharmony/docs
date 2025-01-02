# multimedia子系统变更说明

## cl.multimedia.1 image.Component.rowStride接口返回值变更

**访问级别**

公开接口

**变更原因**

优化接口实现，当前返回值为图片的width，与接口定义不符，无法支撑开发者进行图片处理。

**变更影响**

该变更为兼容性变更。

变更前：
应用开发者根据预览流数据的width和height，处理相机预览流数据。
```ts
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080
// component.byteBuffer为相机返回的预览流数据buffer

receiver.readNextImage((err, nextImage: image.Image)=>{
    nextImage.getComponent(image.ComponentType.JPEG, async(err, component: image.Component)=>{
        let width = previewProfile.size.width
        let height = previewProfile.size.height
        // 相机预览流返回NV21格式
        let pixelMap = await image.createPixelMap(component.byteBuffer, {
            size:{height: height, width: width},
            srcPixelFormat: image.PixelMapFormat.NV21,
        })
        ...
    })
})
```

变更后：
应用开发者需要根据width,height,stride三个值，处理相机预览流数据。
```ts
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080
// component.byteBuffer为相机返回的预览流数据buffer
receiver.readNextImage((err, nextImage: image.Image)=>{
    nextImage.getComponent(image.ComponentType.JPEG, async(err, component: image.Component)=>{
        let width = previewProfile.size.width
        let height = previewProfile.size.height
        let stride = component.rowStride
        // 相机预览流返回NV21格式
        if (stride == width) {
            let pixelMap = await image.createPixelMap(component.byteBuffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
        } else {
            // 用法1.将component.byteBuffer中的数据去除掉stride，拷贝得到新的dstArr数据，传给其他不支持stride的接口处理。
            const dstBufferSize = width * height * 1.5
            const dstArr = new Uint8Array(dstBufferSize)
            for (let j = 0; j < height * 1.5; j++) {
                // component.byteBuffer的每行数据拷贝前width个字节到dstArr中
                const srcBuf = new Uint8Array(component.byteBuffer, j*stride, width)
                dstArr.set(srcBuf, j*width)
            }
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })

            // 用法2.如果仅想通过byteBuffer预览流数据创建pixelMap然后显示，可以根据stride*height创建pixelMap，然后调用crop方法裁剪掉多余的像素
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: stride},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
            pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0})

            // 用法3. 将byteBuffer预览流数据和stride信息一起传给支持stride的接口处理
        }
        ...
    })
})
```

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.0.0.50 版本开始。

**变更的接口/组件**
@ohos.multimedia.image.d.ts下的接口：

image.Component.rowStride接口

**适配指导**

变更：应用开发者需要根据width,height,stride三个值，处理相机预览流数据。

```ts
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080
// component.byteBuffer为相机返回的预览流数据buffer
receiver.readNextImage((err, nextImage: image.Image)=>{
    nextImage.getComponent(image.ComponentType.JPEG, async(err, component: image.Component)=>{
        let width = previewProfile.size.width
        let height = previewProfile.size.height
        let stride = component.rowStride
        // 相机预览流返回NV21格式
        if (stride == width) {
            let pixelMap = await image.createPixelMap(component.byteBuffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
        } else {
            // 用法1.将component.byteBuffer中的数据去除掉stride，拷贝得到新的dstArr数据，传给其他不支持stride的接口处理。
            const dstBufferSize = width * height * 1.5
            const dstArr = new Uint8Array(dstBufferSize)
            for (let j = 0; j < height * 1.5; j++) {
                // component.byteBuffer的每行数据拷贝前width个字节到dstArr中
                const srcBuf = new Uint8Array(component.byteBuffer, j*stride, width)
                dstArr.set(srcBuf, j*width)
            }
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })

            // 用法2.如果仅想通过byteBuffer预览流数据创建pixelMap然后显示，可以根据stride*height创建pixelMap，然后调用crop方法裁剪掉多余的像素
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: stride},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
            pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0})

            // 用法3. 将byteBuffer预览流数据和stride信息一起传给支持stride的接口处理
        }
        ...
    })
})
```

## cl.multimedia.2 OhosImageComponent接口中的rowStride返回值变更

**访问级别**

公开接口

**变更原因**

优化接口实现，当前返回值为图片的width，与接口定义不符，无法支撑开发者进行图片处理。

**变更影响**

该变更为兼容性变更。

变更前：
应用开发者根据预览流数据的width和height，处理相机预览流数据。
```C++
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080
// component.byteBuffer为相机返回的预览流数据buffer
int32_t ret;
napi_value nextImage;
ret = OH_Image_Receiver_ReadNextImage(imageReceiver_c, &nextImage);
ImageNative* nextImage_native = OH_Image_InitImageNative(env, nextImage);
OhosImageComponent imgComponent;
ret = OH_Image_GetComponent(nextImage_native, jpegComponent, &imgComponent);

uint8_t* srcBuffer = imgComponent.byteBuffer;
OH_Pixelmap_InitializationOptions* options = nullptr;
OH_PixelmapInitializationOptions_Create(&options);
OH_PixelmapInitializationOptions_SetWidth(options, previewProfile.size.width);
OH_PixelmapInitializationOptions_SetHeight(options, previewProfile.size.height);
OH_PixelmapInitializationOptions_SetSrcPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapInitializationOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapNative* pixelmap = nullptr;
OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
```

变更后：
应用开发者需要根据width,height,stride三个值，处理相机预览流数据
```C++
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080
// srcBuffer为相机返回的预览流数据buffer
int32_t ret;
napi_value nextImage;
ret = OH_Image_Receiver_ReadNextImage(imageReceiver_c, &nextImage);
ImageNative* nextImage_native = OH_Image_InitImageNative(env, nextImage);
OhosImageComponent imgComponent;
ret = OH_Image_GetComponent(nextImage_native, jpegComponent, &imgComponent);

uint8_t* srcBuffer = imgComponent.byteBuffer;
OH_Pixelmap_InitializationOptions* options = nullptr;
OH_PixelmapInitializationOptions_Create(&options);
OH_PixelmapInitializationOptions_SetWidth(options, previewProfile.size.width);
OH_PixelmapInitializationOptions_SetHeight(options, previewProfile.size.height);
OH_PixelmapInitializationOptions_SetSrcPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapInitializationOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
// 相机预览流返回NV21格式
OH_PixelmapNative* pixelmap = nullptr;
if (stride == width) {
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
} else {
    // 用法1.将srcBuffer中的数据去除掉stride，拷贝得到新的dstBuffer数据，传给其他不支持stride的接口处理。
    size_t dstbufferSize = previewProfile.size.width * previewProfile.size.height * 1.5;
    std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstbufferSize);
    uint8_t* dstPtr = dstBuffer.get();
    for (int j = 0; j < previewProfile.size.height * 1.5; j++) {
        memcpy_s(dstPtr, srcBuffer, previewProfile.size.width);
        dstPtr += previewProfile.size.width;
        srcBuffer += imgComponent.rowStride;
    }
    OH_PixelmapNative_CreatePixelmap(dstBuffer.get(), dstbufferSize, options, &pixelmap);

    // 用法2.如果仅想通过srcBuffer预览流数据创建pixelMap然后显示，可以根据stride*height创建pixelMap，然后调用crop方法裁剪掉多余的像素
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // 用法3. 将srcBuffer预览流数据和stride信息一起传给支持stride的接口处理
}
```

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony 5.0.0.50 版本开始。

**变更的接口/组件**
<multimedia/image_framework/image_mdk.h>下的接口：

OhosImageComponent接口中的rowStride属性

**适配指导**

应用开发者需要根据width,height,stride三个值，处理相机预览流数据。
```C++
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080
// srcBuffer为相机返回的预览流数据buffer
int32_t ret;
napi_value nextImage;
ret = OH_Image_Receiver_ReadNextImage(imageReceiver_c, &nextImage);
ImageNative* nextImage_native = OH_Image_InitImageNative(env, nextImage);
OhosImageComponent imgComponent;
ret = OH_Image_GetComponent(nextImage_native, jpegComponent, &imgComponent);

uint8_t* srcBuffer = imgComponent.byteBuffer;
OH_Pixelmap_InitializationOptions* options = nullptr;
OH_PixelmapInitializationOptions_Create(&options);
OH_PixelmapInitializationOptions_SetWidth(options, previewProfile.size.width);
OH_PixelmapInitializationOptions_SetHeight(options, previewProfile.size.height);
OH_PixelmapInitializationOptions_SetSrcPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapInitializationOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
// 相机预览流返回NV21格式
OH_PixelmapNative* pixelmap = nullptr;
if (stride == width) {
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
} else {
    // 用法1.将srcBuffer中的数据去除掉stride，拷贝得到新的dstBuffer数据，传给其他不支持stride的接口处理。
    size_t dstbufferSize = previewProfile.size.width * previewProfile.size.height * 1.5;
    std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstbufferSize);
    uint8_t* dstPtr = dstBuffer.get();
    for (int j = 0; j < previewProfile.size.height * 1.5; j++) {
        memcpy_s(dstPtr, srcBuffer, previewProfile.size.width);
        dstPtr += previewProfile.size.width;
        srcBuffer += imgComponent.rowStride;
    }
    OH_PixelmapNative_CreatePixelmap(dstBuffer.get(), dstbufferSize, options, &pixelmap);

    // 用法2.如果仅想通过srcBuffer预览流数据创建pixelMap然后显示，可以根据stride*height创建pixelMap，然后调用crop方法裁剪掉多余的像素
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // 用法3. 将srcBuffer预览流数据和stride信息一起传给支持stride的接口处理
}
```

## cl.multimedia.3 OH_ImageNative_GetRowStride接口返回值变更

**访问级别**

公开接口

**变更原因**

优化接口实现，当前返回值为图片的width，与接口定义不符，无法支撑开发者进行图片处理。

**变更影响**

该变更为兼容性变更。

变更前：
应用开发者根据预览流数据的width和height，处理相机预览流数据。
```C++
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080

OH_ImageNative* image = nullptr;
Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
size_t typeSize = 0;
OH_ImageNative_GetComponentTypes(image, nullptr, &typeSize);
uint32_t* types = new uint32_t[typeSize];
OH_ImageNative_GetComponentTypes(image, &types, &typeSize);
uint32_t component = types[0];
OH_NativeBuffer* imageBuffer = nullptr;
errCode = OH_ImageNative_GetByteBuffer(image, component, &imageBuffer);
sizt_t bufferSize = 0;
errCode = OH_ImageNative_GetByteBufferSize(image, component, &bufferSize);

void* srcVir = nullptr;
OH_NativeBuffer_Map(imageBuffer, &srcVir);
OH_Pixelmap_InitializationOptions* options = nullptr;
OH_PixelmapInitializationOptions_Create(&options);
OH_PixelmapInitializationOptions_SetWidth(options, previewProfile.size.width);
OH_PixelmapInitializationOptions_SetHeight(options, previewProfile.size.height);
OH_PixelmapInitializationOptions_SetSrcPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapInitializationOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapNative* pixelmap = nullptr;
OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcVir), bufferSize, options, &pixelmap);
OH_NativeBuffer_Unmap(imageBuffer);
```

变更后：
应用开发者需要根据width,height,stride三个值，处理相机预览流数据。
```C++
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080

OH_ImageNative* image = nullptr;
Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
size_t typeSize = 0;
OH_ImageNative_GetComponentTypes(image, nullptr, &typeSize);
uint32_t* types = new uint32_t[typeSize];
OH_ImageNative_GetComponentTypes(image, &types, &typeSize);
uint32_t component = types[0];
OH_NativeBuffer* imageBuffer = nullptr;
errCode = OH_ImageNative_GetByteBuffer(image, component, &imageBuffer);
size_t bufferSize = 0;
errCode = OH_ImageNative_GetByteBufferSize(image, component, &bufferSize);
int32_t stride = 0;
errCode = OH_ImageNative_GetRowStride(image, component, &stride);

void* srcVir = nullptr;
OH_NativeBuffer_Map(imageBuffer, &srcVir);
OH_Pixelmap_InitializationOptions* options = nullptr;
OH_PixelmapInitializationOptions_Create(&options);
OH_PixelmapInitializationOptions_SetWidth(options, previewProfile.size.width);
OH_PixelmapInitializationOptions_SetHeight(options, previewProfile.size.height);
OH_PixelmapInitializationOptions_SetSrcPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapInitializationOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapNative* pixelmap = nullptr;
if (stride == width) {
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcVir), bufferSize, options, &pixelmap);
} else {
    // 相机预览流返回NV21格式
    // 用法1.将srcBuffer中的数据去除掉stride，拷贝得到新的dstBuffer数据，传给其他不支持stride的接口处理。
    size_t dstbufferSize = previewProfile.size.width * previewProfile.size.height * 1.5;
    std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstbufferSize);
    uint8_t* dstPtr = dstBuffer.get();
    uint8_t* srcBuffer = static_cast<uint8_t*>(srcVir);
    for (int j = 0; j < previewProfile.size.height * 1.5; j++) {
        memcpy_s(dstPtr, srcBuffer, previewProfile.size.width);
        dstPtr += previewProfile.size.width;
        srcBuffer += imgComponent.rowStride;
    }
    OH_PixelmapNative_CreatePixelmap(dstBuffer.get(), dstbufferSize, options, &pixelmap);

    // 用法2.如果仅想通过srcBuffer预览流数据创建pixelMap然后显示，可以根据stride*height创建pixelMap，然后调用crop方法裁剪掉多余的像素
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // 用法3. 将srcBuffer预览流数据和stride信息一起传给支持stride的接口处理
}
OH_NativeBuffer_Unmap(imageBuffer);
```

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.50 版本开始。

**变更的接口/组件**
<multimedia/image_framework/image/image_native.h>下的接口：

OH_ImageNative_GetRowStride接口

**适配指导**

变更：应用开发者需要根据width,height,stride三个值，处理相机预览流数据。

```c++
// previewProfile为应用选中的某一个相机分辨率所对应的宽高，比如1080 * 1080

OH_ImageNative* image = nullptr;
Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
size_t typeSize = 0;
OH_ImageNative_GetComponentTypes(image, nullptr, &typeSize);
uint32_t* types = new uint32_t[typeSize];
OH_ImageNative_GetComponentTypes(image, &types, &typeSize);
uint32_t component = types[0];
OH_NativeBuffer* imageBuffer = nullptr;
errCode = OH_ImageNative_GetByteBuffer(image, component, &imageBuffer);
size_t bufferSize = 0;
errCode = OH_ImageNative_GetByteBufferSize(image, component, &bufferSize);
int32_t stride = 0;
errCode = OH_ImageNative_GetRowStride(image, component, &stride);

void* srcVir = nullptr;
OH_NativeBuffer_Map(imageBuffer, &srcVir);
OH_Pixelmap_InitializationOptions* options = nullptr;
OH_PixelmapInitializationOptions_Create(&options);
OH_PixelmapInitializationOptions_SetWidth(options, previewProfile.size.width);
OH_PixelmapInitializationOptions_SetHeight(options, previewProfile.size.height);
OH_PixelmapInitializationOptions_SetSrcPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapInitializationOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
OH_PixelmapNative* pixelmap = nullptr;
if (stride == width) {
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcVir), bufferSize, options, &pixelmap);
} else {
    // 相机预览流返回NV21格式
    // 用法1.将srcBuffer中的数据去除掉stride，拷贝得到新的dstBuffer数据，传给其他不支持stride的接口处理。
    size_t dstbufferSize = previewProfile.size.width * previewProfile.size.height * 1.5;
    std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstbufferSize);
    uint8_t* dstPtr = dstBuffer.get();
    uint8_t* srcBuffer = static_cast<uint8_t*>(srcVir);
    for (int j = 0; j < previewProfile.size.height * 1.5; j++) {
        memcpy_s(dstPtr, srcBuffer, previewProfile.size.width);
        dstPtr += previewProfile.size.width;
        srcBuffer += imgComponent.rowStride;
    }
    OH_PixelmapNative_CreatePixelmap(dstBuffer.get(), dstbufferSize, options, &pixelmap);

    // 用法2.如果仅想通过srcBuffer预览流数据创建pixelMap然后显示，可以根据stride*height创建pixelMap，然后调用crop方法裁剪掉多余的像素
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // 用法3. 将srcBuffer预览流数据和stride信息一起传给支持stride的接口处理
}
OH_NativeBuffer_Unmap(imageBuffer);
```