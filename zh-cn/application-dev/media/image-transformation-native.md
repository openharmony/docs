# 图像变换(Native)

开发者可以通过本指导了解如何使用Native Image进行图片处理，包括图片的裁剪、旋转、缩放、翻转、偏移、设置透明度等。

## 开发步骤


**添加依赖**

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加image的libpixelmap_ndk.z.so以及日志依赖libhilog_ndk.z.so。

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
            { "createPixelMap", nullptr, CreatePixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "createAlphaPixelMap", nullptr, CreateAlphaPixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "transform", nullptr, Transform, nullptr, nullptr, nullptr, napi_default, nullptr }
        };

        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```


**Native接口调用**

具体接口说明请参考[API文档](../reference/native-apis/image.md)

在hello.cpp文件中获取JS的资源对象，并转为Native的资源对象，即可调用Native接口，调用方式示例代码如下：
    
1. 根据像素数组创建PixelMap对象。

    ```c++
    //创建PixelMap对象
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

    //创建仅含有alpha通道的PixelMap对象
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

2. 图像变换。具体操作参考示例代码注释。

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

        //获取图片信息。
        struct OhosPixelMapInfo pixelmapInfo;
        OH_PixelMap_GetImageInfo(native, &pixelmapInfo);

        //获取PixelMap对象每行字节数。
        int32_t rowBytes;
        OH_PixelMap_GetBytesNumberPerRow(native, &rowBytes);

        //获取PixelMap对象是否可编辑的状态。
        int32_t editable = 0;
        OH_PixelMap_GetIsEditable(native, &editable);

        //获取PixelMap对象是否支持Alpha通道。
        int32_t supportAlpha = 0;
        OH_PixelMap_IsSupportAlpha(native, &supportAlpha);

        //设置PixelMap对象的Alpha通道。
        int32_t alphaAble = 0;
        OH_PixelMap_SetAlphaAble(native, alphaAble);

        //获取PixelMap对象像素密度。
        int32_t densityG;
        OH_PixelMap_GetDensity(native, &densityG);

        //设置PixelMap对象像素密度。
        int32_t densityS = 100;
        OH_PixelMap_SetDensity(native, densityS);

        //设置PixelMap对象的透明度。
        float opacity = 0.5;
        OH_PixelMap_SetOpacity(native, opacity);

        //设置缩放比例。
        //scaleX：宽为原来的0.5。
        //scaleY：高为原来的0.5。
        float scaleX = 0.5;
        float scaleY = 0.5;
        OH_PixelMap_Scale(native, scaleX, scaleY);

        //设置偏移。
        //translateX：向下偏移50。
        //translateY：向右偏移50。
        float translateX = 50;
        float translateY = 50;
        OH_PixelMap_Translate(native, translateX, translateY);

        //设置顺时针旋转90度。
        float angle = 90;
        OH_PixelMap_Rotate(native, angle);

        //设置翻转
        //flipX：水平翻转。0为不翻转，1为翻转。
        //flipY：垂直翻转。0为不翻转，1为翻转。
        int32_t flipX = 0;
        int32_t flipY = 1;
        OH_PixelMap_Flip(native, flipX, flipY);

        //设置裁剪区域。
        // cropX：裁剪起始点横坐标0
        // cropY：裁剪起始点纵坐标0
        // cropH：裁剪高度10，方向为从上往下（裁剪后的图片高度为10）
        // cropW：裁剪宽度10，方向为从左到右（裁剪后的图片宽度为10
        int32_t cropX = 1;
        int32_t cropY = 1;
        int32_t cropW = 10;
        int32_t cropH = 10;
        OH_PixelMap_Crop(native, cropX, cropY, cropW, cropH);

        uint8_t* pixelAddr = nullptr;
        //获取PixelMap对象数据的内存地址，并锁定该内存。
        OH_PixelMap_AccessPixels(native, &pixelAddr);
        //释放PixelMap对象数据的内存锁。
        OH_PixelMap_UnAccessPixels(native);

        return result;
    }
    ```

**JS侧调用**

1. 打开src\main\ets\pages\index.ets, 导入"libentry.so";
    
2. 调用Native接口，传入JS的资源对象。示例如下:

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