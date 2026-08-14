# PixelMap Operation

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ba3f6c99832577d149cf0c227912c266e5256745 translatedAt=2026-08-11T01:46:05.276Z pushedAt=2026-08-11T07:48:24.066Z -->

> **NOTE**
>
> The APIs used in the current development guide are C APIs in the [Image](../../reference/apis-image-kit/capi-image.md) module, which support image encoding/decoding, image receivers, and image data processing. These APIs were released before API version 11 and will not receive new features in later versions. They are **no longer recommended**.<br>
> You can use the C APIs in the [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md) module, which not only provide the basic image framework features mentioned above but also support new capabilities such as multi-image encoding/decoding. For related development guidance, see the content under [Using Image_NativeModule to Decode Images](image-source-c.md). These APIs are available from API version 12 and will continue to evolve. They are **recommended for use**.<br>
> Using both sets of C APIs at the same time is not recommended, as they may be incompatible in certain scenarios.

This topic describes how to use native image APIs to perform PixelMap operations.

## How to Develop

**Adding Dependencies**

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libace_napi.z.so** and **libpixelmap_ndk.z.so** (on both of which the image APIs depend) and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

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
        { "createPixelMapTest", nullptr, CreatePixelMapTest, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "createAlphaPixelMap", nullptr, CreateAlphaPixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "transform", nullptr, Transform, nullptr, nullptr, nullptr, napi_default, nullptr },
    };

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

**Calling the Native APIs**

For details about the APIs, see [Image](../../reference/apis-image-kit/capi-image.md).

Obtain the JS resource object from the **hello.cpp** file and convert it to a native resource object. Then you can call native APIs.

**Adding Reference Files**

```c++
#include <multimedia/image_framework/image_mdk_common.h>
#include <multimedia/image_framework/image_pixel_map_mdk.h>
#include <stdlib.h>
```

1. Create a **PixelMap** object.

    ```c++
    napi_value CreatePixelMapTest(napi_env env, napi_callback_info info) {
        const int32_t PIXEL_FORMAT_BGRA_8888 = 4;
 	    const uint32_t ALPHA_TYPE_UNKNOWN = 0;

        napi_value udfVar = nullptr;
        napi_value pixelMap = nullptr;

        struct OhosPixelMapCreateOps createOps;
        createOps.width = 4;
        createOps.height = 6;
        createOps.pixelFormat = PIXEL_FORMAT_BGRA_8888;
        createOps.alphaType = ALPHA_TYPE_UNKNOWN;
        size_t bufferSize = createOps.width * createOps.height * 4;
        void *buff = malloc(bufferSize);
        if (buff == nullptr) {
            return udfVar;
        }

        char *cc = (char *)buff;
        for (int i = 0; i < 96; i++) {
            *(cc++) = (char)i;
        }
        int32_t res = OH_PixelMap_CreatePixelMap(env, createOps, (uint8_t *)buff, bufferSize, &pixelMap);
        free(buff);
        if (res != IMAGE_RESULT_SUCCESS || pixelMap == nullptr) {
            return udfVar;
        }
        return pixelMap;
    }
    ```

2. Create a **PixelMap** object that contains only alpha channel information.

    ```c++
    napi_value CreateAlphaPixelMap(napi_env env, napi_callback_info info) {
        napi_value udfVar = nullptr;
        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        napi_value alphaPixelMap = nullptr;

        napi_get_undefined(env, &udfVar);

        if (napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr) != napi_ok || argCount < 1 ||
            argValue[0] == nullptr) {
            return udfVar;
        }
        int32_t res = OH_PixelMap_CreateAlphaPixelMap(env, argValue[0], &alphaPixelMap);
        if (res != IMAGE_RESULT_SUCCESS || alphaPixelMap == nullptr) {
            return udfVar;
        }
        return alphaPixelMap;
    }
    ```

3. Process the PixelMap object.

    ```c++
    napi_value Transform(napi_env env, napi_callback_info info) {
        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        if (napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr) != napi_ok || argCount < 1 ||
            argValue[0] == nullptr) {
            return nullptr;
        }
        napi_value result = nullptr;
        napi_get_undefined(env, &result);
        
        // Initialize a NativePixelMap object.
        NativePixelMap *native = OH_PixelMap_InitNativePixelMap(env, argValue[0]);
        if (native == nullptr) {
            return result;
        }

        // Obtain image information.
        struct OhosPixelMapInfos pixelMapInfo;
        OH_PixelMap_GetImageInfo(native, &pixelMapInfo);

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
        // scaleX: The width is scaled to 0.5x of the original.
        // scaleY: The height is scaled to 0.5x of the original.
        float scaleX = 0.5;
        float scaleY = 0.5;
        OH_PixelMap_Scale(native, scaleX, scaleY);

        // Translate the image.
        // translateX: Offset downward by 50 pixels.
        // translateY: Offset rightward by 50 pixels.
        float translateX = 50;
        float translateY = 50;
        OH_PixelMap_Translate(native, translateX, translateY);

        // Set the rotation angle.
        // angle: Rotate 90 degrees clockwise.
        float angle = 90;
        OH_PixelMap_Rotate(native, angle);

        // Set the flip.
        // flipX: Horizontal flip. 0 means no flip, and 1 means flip.
        // flipY: Vertical flip. 0 means no flip, and 1 means flip.
        int32_t flipX = 0;
        int32_t flipY = 1;
        OH_PixelMap_Flip(native, flipX, flipY);

        // Crop the image.
        // cropX: The x-coordinate of the crop start point.
        // cropY: The y-coordinate of the crop start point.
        // cropH: Crop height 10, from top to bottom (the cropped image height is 10).
        // cropW: Crop width 10, from left to right (the cropped image width is 10).
        int32_t cropX = 1;
        int32_t cropY = 1;
        int32_t cropW = 10;
        int32_t cropH = 10;
        OH_PixelMap_Crop(native, cropX, cropY, cropW, cropH);

        // Obtain the memory address of the PixelMap object and lock the memory.
        void *pixelAddr = nullptr;
        int32_t ret = OH_PixelMap_AccessPixels(native, &pixelAddr);

        if (ret == IMAGE_RESULT_SUCCESS) {
            // Release the memory lock on the PixelMap object data.
            OH_PixelMap_UnAccessPixels(native);
        }

        return result;
    }
    ```

**Calling APIs on the JS Side**

1. Open **src\main\cpp\types\*libentry*\index.d.ts** (where **libentry** varies according to the project name), and import the following files:

    ```js
    import { image } from '@kit.ImageKit';

    export const createPixelMapTest: () => image.PixelMap;
    export const transform: (a: image.PixelMap) => void;
    ```

2. Open **src\main\ets\pages\index.ets**, import ***libentry*.so** (where **libentry** varies according to the project name), call the native APIs, and pass in the JS resource object. The sample code is as follows:

    ```js
    import testNapi from 'libentry.so';
    import { image } from '@kit.ImageKit';

    @Entry
    @Component
    struct Index {
    @State _pixelMap : image.PixelMap | undefined = undefined;

    build() {
        Row() {
            Column() {
                Button("PixelMap")
                .width(100)
                .height(100)
                .onClick(() => {
                    console.info("com.example.native_ndk_api10 button click in");
                    this._pixelMap = testNapi.createPixelMapTest();
                    testNapi.transform(this._pixelMap);
                })
                Image(this._pixelMap)
                .width(500)
                .height(500)
                .objectFit(ImageFit.Cover)
                .border({width: 1, color: Color.Blue})
                }
                .width('100%')
            }
            .height('100%')
        }
    }
    ```