# Multimedia Subsystem Changelog

## cl.multimedia.1 Changed the Return Value of image.Component.rowStride

**Access Level**

Public API

**Reason for Change**

The current return value is the width of the image. It does not align with the API definition.

**Change Impact**

This change is a compatible change.

Before change:

Developers process the camera preview stream data based on the width and height.

```ts
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.
// component.byteBuffer is the buffer for storing the preview stream data returned by the camera.

receiver.readNextImage((err, nextImage: image.Image)=>{
    nextImage.getComponent(image.ComponentType.JPEG, async(err, component: image.Component)=>{
        let width = previewProfile.size.width
        let height = previewProfile.size.height
        // The preview stream data is returned in NV21 format.
        let pixelMap = await image.createPixelMap(component.byteBuffer, {
            size:{height: height, width: width},
            srcPixelFormat: image.PixelMapFormat.NV21,
        })
        ...
    })
})
```

After change:

Developers process the camera preview stream data based on the width, height, and stride.

```ts
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.
// component.byteBuffer is the buffer for storing the preview stream data returned by the camera.
receiver.readNextImage((err, nextImage: image.Image)=>{
    nextImage.getComponent(image.ComponentType.JPEG, async(err, component: image.Component)=>{
        let width = previewProfile.size.width
        let height = previewProfile.size.height
        let stride = component.rowStride
        // The preview stream data is returned in NV21 format.
        if (stride == width) {
            let pixelMap = await image.createPixelMap(component.byteBuffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
        } else {
            // Usage 1: Remove the stride from the data contained in component.byteBuffer, create a new array called dstArr with the copied data, and pass it to other APIs that do not support stride.
            const dstBufferSize = width * height * 1.5
            const dstArr = new Uint8Array(dstBufferSize)
            for (let j = 0; j < height * 1.5; j++) {
                // Copy the first width bytes of each line of data in component.byteBuffer to dstArr.
                const srcBuf = new Uint8Array(component.byteBuffer, j*stride, width)
                dstArr.set(srcBuf, j*width)
            }
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })

            // Usage 2: To create a PixelMap for display purposes based on the preview stream data contained in the byteBuffer, you can create a PixelMap using the product of stride and height, and then call the crop API to remove any extra pixels.
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: stride},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
            pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0})

            // Usage 3: Pass the preview stream data contained in the byteBuffer and stride to the API that supports stride.
        }
        ...
    })
})
```

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.50

**Key API/Component Changes**

API in @ohos.multimedia.image.d.ts:

image.Component.rowStride

**Adaptation Guide**

Process the camera preview stream data based on the width, height, and stride.

```ts
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.
// component.byteBuffer is the buffer for storing the preview stream data returned by the camera.
receiver.readNextImage((err, nextImage: image.Image)=>{
    nextImage.getComponent(image.ComponentType.JPEG, async(err, component: image.Component)=>{
        let width = previewProfile.size.width
        let height = previewProfile.size.height
        let stride = component.rowStride
        // The preview stream data is returned in NV21 format.
        if (stride == width) {
            let pixelMap = await image.createPixelMap(component.byteBuffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
        } else {
            // Usage 1: Remove the stride from the data contained in component.byteBuffer, create a new array called dstArr with the copied data, and pass it to other APIs that do not support stride.
            const dstBufferSize = width * height * 1.5
            const dstArr = new Uint8Array(dstBufferSize)
            for (let j = 0; j < height * 1.5; j++) {
                // Copy the first width bytes of each line of data in component.byteBuffer to dstArr.
                const srcBuf = new Uint8Array(component.byteBuffer, j*stride, width)
                dstArr.set(srcBuf, j*width)
            }
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: width},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })

            // Usage 2: To create a PixelMap for display purposes based on the preview stream data contained in the byteBuffer, you can create a PixelMap using the product of stride and height, and then call the crop API to remove any extra pixels.
            let pixelMap = await image.createPixelMap(dstArr.buffer, {
                size:{height: height, width: stride},
                srcPixelFormat: image.PixelMapFormat.NV21,
            })
            pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0})

            // Usage 3: Pass the preview stream data contained in the byteBuffer and stride to the API that supports stride.
        }
        ...
    })
})
```

## cl.multimedia.2 Changed the Return Value of rowStride in the OhosImageComponent API

**Access Level**

Public API

**Reason for Change**

The current return value is the width of the image. It does not align with the API definition.

**Change Impact**

This change is a compatible change.

Before change:

Developers process the camera preview stream data based on the width and height.

```C++
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.
// component.byteBuffer is the buffer for storing the preview stream data returned by the camera.
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

After change:

Developers process the camera preview stream data based on the width, height, and stride.

```C++
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.
// srcBuffer is the buffer for storing the preview stream data returned by the camera.
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
// The preview stream data is returned in NV21 format.
OH_PixelmapNative* pixelmap = nullptr;
if (stride == width) {
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
} else {
    // Usage 1: Remove the stride from the data contained in srcBuffer, create a new array called dstBuffer with the copied data, and pass it to other APIs that do not support stride.
    size_t dstbufferSize = previewProfile.size.width * previewProfile.size.height * 1.5;
    std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstbufferSize);
    uint8_t* dstPtr = dstBuffer.get();
    for (int j = 0; j < previewProfile.size.height * 1.5; j++) {
        memcpy_s(dstPtr, srcBuffer, previewProfile.size.width);
        dstPtr += previewProfile.size.width;
        srcBuffer += imgComponent.rowStride;
    }
    OH_PixelmapNative_CreatePixelmap(dstBuffer.get(), dstbufferSize, options, &pixelmap);

    // Usage 2: To create a PixelMap for display purposes based on the preview stream data contained in the srcBuffer, you can create a PixelMap using the product of stride and height, and then call the crop API to remove any extra pixels.
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // Usage 3: Pass the preview stream data contained in the srcBuffer and stride to the API that supports stride.
}
```

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.50

**Key API/Component Changes**

API in <multimedia/image_framework/image_mdk.h>:

**rowStride** in the **OhosImageComponent** API

**Adaptation Guide**

Process the camera preview stream data based on the width, height, and stride.
```C++
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.
// srcBuffer is the buffer for storing the preview stream data returned by the camera.
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
// The preview stream data is returned in NV21 format.
OH_PixelmapNative* pixelmap = nullptr;
if (stride == width) {
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
} else {
    // Usage 1: Remove the stride from the data contained in srcBuffer, create a new array called dstBuffer with the copied data, and pass it to other APIs that do not support stride.
    size_t dstbufferSize = previewProfile.size.width * previewProfile.size.height * 1.5;
    std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstbufferSize);
    uint8_t* dstPtr = dstBuffer.get();
    for (int j = 0; j < previewProfile.size.height * 1.5; j++) {
        memcpy_s(dstPtr, srcBuffer, previewProfile.size.width);
        dstPtr += previewProfile.size.width;
        srcBuffer += imgComponent.rowStride;
    }
    OH_PixelmapNative_CreatePixelmap(dstBuffer.get(), dstbufferSize, options, &pixelmap);

    // Usage 2: To create a PixelMap for display purposes based on the preview stream data contained in the srcBuffer, you can create a PixelMap using the product of stride and height, and then call the crop API to remove any extra pixels.
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // Usage 3: Pass the preview stream data contained in the srcBuffer and stride to the API that supports stride.
}
```

## cl.multimedia.3 Changed the Return Value of OH_ImageNative_GetRowStride

**Access Level**

Public API

**Reason for Change**

The current return value is the width of the image. It does not align with the API definition.

**Change Impact**

This change is a compatible change.

Before change:

Developers process the camera preview stream data based on the width and height.

```C++
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.

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

After change:

Developers process the camera preview stream data based on the width, height, and stride.

```C++
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.

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
    // The preview stream data is returned in NV21 format.
    // Usage 1: Remove the stride from the data contained in srcBuffer, create a new array called dstBuffer with the copied data, and pass it to other APIs that do not support stride.
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

    // Usage 2: To create a PixelMap for display purposes based on the preview stream data contained in the srcBuffer, you can create a PixelMap using the product of stride and height, and then call the crop API to remove any extra pixels.
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // Usage 3: Pass the preview stream data contained in the srcBuffer and stride to the API that supports stride.
}
OH_NativeBuffer_Unmap(imageBuffer);
```

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.50

**Key API/Component Changes**

API in <multimedia/image_framework/image/image_native.h>:

OH_ImageNative_GetRowStride

**Adaptation Guide**

Process the camera preview stream data based on the width, height, and stride.

```c++
// previewProfile indicates the width and height of the camera resolution chosen by the application, for example, 1080 x 1080.

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
    // The preview stream data is returned in NV21 format.
    // Usage 1: Remove the stride from the data contained in srcBuffer, create a new array called dstBuffer with the copied data, and pass it to other APIs that do not support stride.
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

    // Usage 2: To create a PixelMap for display purposes based on the preview stream data contained in the srcBuffer, you can create a PixelMap using the product of stride and height, and then call the crop API to remove any extra pixels.
    OH_PixelmapInitializationOptions_SetWidth(options, imgComponent.rowStride);
    OH_PixelmapNative_CreatePixelmap(static_cast<unsigned char*>(srcBuffer), imgComponent.size, options, &pixelmap);
    Image_Region region{0, 0, previewProfile.size.width, previewProfile.size.height};
    OH_PixelmapNative_Crop(pixelmap, &region);

    // Usage 3: Pass the preview stream data contained in the srcBuffer and stride to the API that supports stride.
}
OH_NativeBuffer_Unmap(imageBuffer);
```
