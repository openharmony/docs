# Image Transformation (Native)

You will learn how to use native image APIs to process images, including cropping, rotating, scaling, flipping, translating, and opacity setting.

## How to Develop


**Adding Dependencies**

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libpixelmap_ndk.z.so** of the image and **libhilog_ndk.z.so** of the log to the **target_link_libraries** dependency.

    ```txt
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libpixelmap_ndk.z.so)
    ```

**Adding API Mappings**

Open the **src/main/cpp/hello.cpp** file and add the following API mappings to the **Init** function:

    ```c++
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "createPixelMap", nullptr, CreatePixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "createAlphaPixelMap", nullptr, CreateAlphaPixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "transform", nullptr, Transform, nullptr, nullptr, nullptr, napi_default, nullptr }
        };

        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```


**Calling the Native APIs**

For details about the APIs, see [Image API Reference](../reference/native-apis/image.md).

Obtain the JS resource object from the **hello.cpp** file and convert it to a native resource object. Then you can call native APIs. The sample code is as follows:
    
1. Create a **PixelMap** object based on a pixel array.

    ```c++
    // Create a PixelMap object.
    napi_value CreatePixelMap(napi_env env, napi_callback_info info)
    {
        napi_value udfVar = nullptr;
        napi_value thisVar = nullptr;
        napi_value argValue[2] = {0};
        size_t argCount = 2;

        void* buffer = nullptr;
        size_t bufferSize = 0;
        struct OhosPixelMapCreateOps createOps;
        napi_value pixelmap = nullptr;

        napi_get_undefined(env, &udfVar);
        napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr);
        if (napi_get_arraybuffer_info(env, argValue[0], &buffer, &bufferSize) != napi_ok ||
            buffer == nullptr || bufferSize == 0) {
            return udfVar;
        }

        createOps.width = 4;
        createOps.height = 6;
        createOps.pixelFormat = 4;
        createOps.alphaType = 0;
        int32_t res = OH_PixelMap_CreatePixelMap(env, createOps, (uint8_t *)buffer, bufferSize, &pixelmap);
        if (res != OHOS_IMAGE_RESULT_SUCCESS || pixelmap == nullptr) {
            return udfVar;
        }
        return pixelmap;
    }

    // Create a PixelMap object that contains only the alpha channel.
    napi_value CreateAlphaPixelMap(napi_env env, napi_callback_info info)
    {
        napi_value udfVar = nullptr;
        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        napi_value alphaPixelmap = nullptr;

        napi_get_undefined(env, &udfVar);

        if (napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr) != napi_ok ||
            argCount < 1 || argValue[0] == nullptr) {
            return udfVar;
        }
        int32_t res = OH_PixelMap_CreateAlphaPixelMap(env, argValue[0], &alphaPixelmap);
        if (res != OHOS_IMAGE_RESULT_SUCCESS || alphaPixelmap == nullptr) {
            return udfVar;
        }
        return alphaPixelmap;
    }
    ```

2. Perform image transformation. For details about the operation, read the comments in the sample code below.

    ```c++
    napi_value Transform(napi_env env, napi_callback_info info)
    {
        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        if (napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr) != napi_ok ||
            argCount < 1 || argValue[0] == nullptr) {
            return nullptr;
        }
        napi_value result = nullptr;
        napi_get_undefined(env, &result);

        NativePixelMap* native = OH_PixelMap_InitNativePixelMap(env, argValue[0]);
        if (native == nullptr) {
            return result;
        }

        // Obtain image information.
        struct OhosPixelMapInfo pixelmapInfo;
        OH_PixelMap_GetImageInfo(native, &pixelmapInfo);

        // Obtain the number of bytes per row of the PixelMap object.
        int32_t rowBytes;
        OH_PixelMap_GetBytesNumberPerRow(native, &rowBytes);

        // Check whether the PixelMap object is editable.
        int32_t editable = 0;
        OH_PixelMap_GetIsEditable(native, &editable);

        // Check whether the PixelMap object supports alpha channels.
        int32_t supportAlpha = 0;
        OH_PixelMap_IsSupportAlpha(native, &supportAlpha);

        // Set an alpha channel for the PixelMap object.
        int32_t alphaAble = 0;
        OH_PixelMap_SetAlphaAble(native, alphaAble);

        // Obtain the pixel density of the PixelMap object.
        int32_t densityG;
        OH_PixelMap_GetDensity(native, &densityG);

        // Set the pixel density for the PixelMap object.
        int32_t densityS = 100;
        OH_PixelMap_SetDensity(native, densityS);

        // Set the opacity for the PixelMap object.
        float opacity = 0.5;
        OH_PixelMap_SetOpacity(native, opacity);

        // Scale the image.
        // scaleX: The width of the image after scaling is 0.5 of the original width.
        // scaleY: The height of the image after scaling is 0.5 of the original height.
        float scaleX = 0.5;
        float scaleY = 0.5;
        OH_PixelMap_Scale(native, scaleX, scaleY);

        // Translate the image.
        // translateX: Translate the image by 50 units downwards.
        // translateY: Translate the image by 50 units rightwards.
        float translateX = 50;
        float translateY = 50;
        OH_PixelMap_Translate(native, translateX, translateY);

        // Rate the image clockwise by 90°.
        float angle = 90;
        OH_PixelMap_Rotate(native, angle);

        // Flip the image.
        // flipX: whether to flip the image horizontally. The value 1 means to flip the image and 0 means the opposite.
        // flipY: whether to flip the image vertically. The value 1 means to flip the image and 0 means the opposite.
        int32_t flipX = 0;
        int32_t flipY = 1;
        OH_PixelMap_Flip(native, flipX, flipY);

        // Crop the image.
        // cropX: x-axis coordinate of the start point for cropping (0).
        // cropY: y-axis coordinate of the start point for cropping (0).
        // cropH: height after cropping (10), cropping from top to bottom.
        // cropW: width after cropping (10), cropping from left to right.
        int32_t cropX = 1;
        int32_t cropY = 1;
        int32_t cropW = 10;
        int32_t cropH = 10;
        OH_PixelMap_Crop(native, cropX, cropY, cropW, cropH);

        uint8_t* pixelAddr = nullptr;
        // Obtain the memory address of the PixelMap object and lock the memory.
        OH_PixelMap_AccessPixels(native, &pixelAddr);
        // Unlock the memory of the PixelMap object.
        OH_PixelMap_UnAccessPixels(native);

        return result;
    }
    ```

**Calling APIs on the JS Side**

1. Open **src\main\ets\pages\index.ets**, and import **libentry.so**.
    
2. Call the native APIs and pass in the JS resource object. The sample code is as follows:

    ```js
    import testNapi from 'libentry.so'
    import image from '@ohos.multimedia.image'

    @Entry
    @Component
    struct Index {
        @State _pixelMap: image.PixelMap = undefined;
        build() {
            Row() {
            Column() {
                Button("PixelMap")
                .width(100)
                .height(100)
                .onClick(() => {
                    const color = new ArrayBuffer(96);
                    var bufferArr = new Uint8Array(color);
                    for (var i = 0; i < bufferArr.length; i++) {
                        bufferArr[i] = 0x80;
                    }

                    this._pixelMap = testNapi.createPixelMap(color);
                    testNapi.transform(this._pixelMap);
                })

                Image(this._pixelMap)
                .width(500)
                .height(500)
                .objectFit(ImageFit.Cover)
            }
            .width('100%')
            }
            .height('100%')
        }
    }
    ```
