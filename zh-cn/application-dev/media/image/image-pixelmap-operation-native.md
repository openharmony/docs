# 位图操作

开发者可以通过本指导了解如何使用Native Image的接口完成位图操作。

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
        { "createPixelMapTest", nullptr, CreatePixelMapTest, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "createAlphaPixelMap", nullptr, CreateAlphaPixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "transform", nullptr, Transform, nullptr, nullptr, nullptr, napi_default, nullptr },
    };

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

**Native接口调用**

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image.md)。

在hello.cpp文件中获取JS的资源对象，并转为Native的资源对象，即可调用Native接口，调用方式示例代码如下：

**添加引用文件**

```c++
#include <multimedia/image_framework/image_mdk_common.h>
#include <multimedia/image_framework/image_pixel_map_mdk.h>
#include <stdlib.h>
```

1. 创建一个 **PixelMap** 对象。

    ```c++
    napi_value CreatePixelMapTest(napi_env env, napi_callback_info info) {
        napi_value udfVar = nullptr;
        napi_value pixelMap = nullptr;

        struct OhosPixelMapCreateOps createOps;
        createOps.width = 4;
        createOps.height = 6;
        createOps.pixelFormat = 4;
        createOps.alphaType = 0;
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

2. 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的 **PixelMap** 对象。

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

3. 对 **PixelMap** 数据进行处理。

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
        
        // 初始化NativePixelMap对象。
        NativePixelMap *native = OH_PixelMap_InitNativePixelMap(env, argValue[0]);
        if (native == nullptr) {
            return result;
        }

        // 获取图片信息。
        struct OhosPixelMapInfos pixelMapInfo;
        OH_PixelMap_GetImageInfo(native, &pixelMapInfo);

        // 获取PixelMap对象每行字节数。
        int32_t rowBytes;
        OH_PixelMap_GetBytesNumberPerRow(native, &rowBytes);

        // 获取PixelMap对象是否可编辑的状态。
        int32_t editable = 0;
        OH_PixelMap_GetIsEditable(native, &editable);

        // 获取PixelMap对象是否支持Alpha通道。
        int32_t supportAlpha = 0;
        OH_PixelMap_IsSupportAlpha(native, &supportAlpha);

        // 设置PixelMap对象的Alpha通道。
        int32_t alphaAble = 0;
        OH_PixelMap_SetAlphaAble(native, alphaAble);

        // 获取PixelMap对象像素密度。
        int32_t densityG;
        OH_PixelMap_GetDensity(native, &densityG);

        // 设置PixelMap对象像素密度。
        int32_t densityS = 100;
        OH_PixelMap_SetDensity(native, densityS);

        // 设置PixelMap对象的透明度。
        float opacity = 0.5;
        OH_PixelMap_SetOpacity(native, opacity);

        // 设置缩放比例。
        // scaleX: 宽为原来的0.5。
        // scaleY: 高为原来的0.5。
        float scaleX = 0.5;
        float scaleY = 0.5;
        OH_PixelMap_Scale(native, scaleX, scaleY);

        // 设置偏移。
        // translateX: 向下偏移50。
        // translateY: 向右偏移50。
        float translateX = 50;
        float translateY = 50;
        OH_PixelMap_Translate(native, translateX, translateY);

        // 设置顺时针旋转90度。
        float angle = 90;
        OH_PixelMap_Rotate(native, angle);

        // 设置翻转
        // flipX: 水平翻转，0为不翻转，1为翻转。
        // flipY: 垂直翻转，0为不翻转，1为翻转。
        int32_t flipX = 0;
        int32_t flipY = 1;
        OH_PixelMap_Flip(native, flipX, flipY);

        // 设置裁剪区域。
        // cropX: 裁剪起始点横坐标。
        // cropY: 裁剪起始点纵坐标。
        // cropH: 裁剪高度10，方向为从上往下（裁剪后的图片高度为10）。
        // cropW: 裁剪宽度10，方向为从左到右（裁剪后的图片宽度为10）。
        int32_t cropX = 1;
        int32_t cropY = 1;
        int32_t cropW = 10;
        int32_t cropH = 10;
        OH_PixelMap_Crop(native, cropX, cropY, cropW, cropH);

        // 获取PixelMap对象数据的内存地址，并锁定该内存。
        void *pixelAddr = nullptr;
        OH_PixelMap_AccessPixels(native, &pixelAddr);

        // 释放PixelMap对象数据的内存锁。
        OH_PixelMap_UnAccessPixels(native);

        return result;
    }
    ```

**JS侧调用**

1. 打开src\main\cpp\types\libentry\index.d.ts（其中libentry根据工程名生成），导入如下引用文件：

    ```js
    import { image } from '@kit.ImageKit';

    export const createPixelMapTest: () => image.PixelMap;
    export const transform: (a: image.PixelMap) => void;
    ```

2. 打开src\main\ets\pages\index.ets, 导入"libentry.so"(根据工程名生成)，调用Native接口，传入JS的资源对象。示例如下：

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
