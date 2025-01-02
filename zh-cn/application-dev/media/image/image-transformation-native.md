# 使用Image完成图像变换

开发者可以通过本指导了解如何使用Native Image的接口。

## 开发步骤

**添加依赖**

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加image的libace_napi.z.so、libpixelmap_ndk.z.so以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libpixelmap_ndk.z.so)
```

**添加接口映射**

打开src/main/cpp/hello.cpp文件，在Init函数中添加接口映射如下：

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

**Native接口调用**

具体接口说明请参考[API文档](../../reference/apis-image-kit/image.md)。

在hello.cpp文件中获取JS的资源对象，并转为Native的资源对象，即可调用Native接口，调用方式示例代码如下：

打开src/main/cpp/hello.cpp，添加引用文件。

```c++
#include<multimedia/image_framework/image_pixel_map_napi.h>
```

1. 获取**PixelMap**的信息，并记录信息到**OhosPixelMapInfo**结构中。

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

2. 获取**PixelMap**对象数据的内存地址，并锁定该内存。

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

3. 释放**PixelMap**对象数据的内存锁。

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

**JS侧调用**

1. 打开src\main\cpp\types\libentry\index.d.ts(其中libentry根据工程名生成)，导入如下引用文件:

    ```js
    import { image } from '@kit.ImageKit';
    export const add:(a: number, b: number) => image.PixelMap;
    export const transform: (a: image.PixelMap) => image.PixelMap;
    export const testGetImageInfo: (a: image.PixelMap) => image.PixelMap;
    export const testAccessPixels: (a: image.PixelMap) => image.PixelMap;
    export const testUnAccessPixels: (a: image.PixelMap) => image.PixelMap;
    ```

2. 打开src\main\ets\pages\index.ets, 导入"libentry.so"(根据工程名生成)；调用Native接口，传入JS的资源对象。示例如下:

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
