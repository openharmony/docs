# Image Transformation

This topic describes how to use native image APIs to implement image transformation.

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
        { "testGetImageInfo", nullptr, TestGetImageInfo, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "testAccessPixels", nullptr, TestAccessPixels, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "testUnAccessPixels", nullptr, TestUnAccessPixels, nullptr, nullptr, nullptr, napi_default, nullptr },
    };

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

**Calling the Native APIs**

For details about the APIs, see [Image](../../reference/apis-image-kit/image.md).

Obtain the JS resource object from the **hello.cpp** file and convert it to a native resource object. Then you can call native APIs. The sample code is as follows:

Open **src/main/cpp/hello.cpp**, and add the reference file.

```c++
#include<multimedia/image_framework/image_pixel_map_napi.h>
```

1. Obtain the **PixelMap** information and store the information to the **OhosPixelMapInfo** struct.

   ```c++
   static napi_value TestGetImageInfo(napi_env env, napi_callback_info info)
    {
        napi_value result = nullptr;
        napi_get_undefined(env, &result);

        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr);
        
        OHOS::Media::OhosPixelMapInfo pixelMapInfo;
        OHOS::Media::OH_GetImageInfo(env, argValue[0], &pixelMapInfo);
        return result;
    }
    ```

2. Obtain the memory address of a **PixelMap** object and lock the memory.

    ```c++
    static napi_value TestAccessPixels(napi_env env, napi_callback_info info)
    {
        napi_value result = nullptr;
        napi_get_undefined(env, &result);

        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr);

        void* addrPtr = nullptr;
        OHOS::Media::OH_AccessPixels(env, argValue[0], &addrPtr);
        return result;
    }
    ```

3. Unlock the memory of the **PixelMap** object.

    ```c++
    static napi_value TestUnAccessPixels(napi_env env, napi_callback_info info)
    {
        napi_value result = nullptr;
        napi_get_undefined(env, &result);

        napi_value thisVar = nullptr;
        napi_value argValue[1] = {0};
        size_t argCount = 1;

        napi_get_cb_info(env, info, &argCount, argValue, &thisVar, nullptr);

        OHOS::Media::OH_UnAccessPixels(env, argValue[0]);
        return result;
    }
    ```

**Calling APIs on the JS Side**

1. Open **src\main\cpp\types\*libentry*\index.d.ts** (where **libentry** varies according to the project name), and import the following files:

    ```js
    import { image } from '@kit.ImageKit';
    export const add:(a: number, b: number) => image.PixelMap;
    export const transform: (a: image.PixelMap) => image.PixelMap;
    export const testGetImageInfo: (a: image.PixelMap) => image.PixelMap;
    export const testAccessPixels: (a: image.PixelMap) => image.PixelMap;
    export const testUnAccessPixels: (a: image.PixelMap) => image.PixelMap;
    ```

2. Open **src\main\ets\pages\index.ets**, import ***libentry*.so** (where **libentry** varies according to the project name), call the native APIs, and pass in the JS resource object. The sample code is as follows:

    ```js
    import testNapi from 'libentry.so'
    import { image } from '@kit.ImageKit';

    @Entry
    @Component
    struct Index {
    @State message: string = 'IMAGE'
    @State _PixelMap : image.PixelMap | undefined = undefined;

    build() {
        Row() {
        Column() {
            Button(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
                const color : ArrayBuffer = new ArrayBuffer(96);
                let opts: image.InitializationOptions = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 4, width: 6 } }
                image.createPixelMap(color, opts)
                .then( (pixelmap : image.PixelMap) => {
                    this._PixelMap = pixelmap;
                    testNapi.testGetImageInfo(this._PixelMap);
                    console.info("Test GetImageInfo success");

                    testNapi.testAccessPixels(this._PixelMap);
                    console.info("Test AccessPixels success");

                    testNapi.testUnAccessPixels(this._PixelMap);
                    console.info("Test UnAccessPixels success");
                })
            })
        }
        .width('100%')
        }
        .height('100%')
    }
    }
    ```
