# 使用Image_NativeModule完成多图对象解码
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

创建ImageSource，解码得到Picture，以及释放ImageSource实例。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libimage_source.so 以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**解码接口使用示例**

在创建ImageSource实例后，进行指定属性值的获取和修改，通过解码参数创建PixelMap对象，获取图像帧数等操作。

```c++
#include <hilog/log.h>
#include <bits/alltypes.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>
#include <multimedia/image_framework/image/image_native.h>
#include <multimedia/image_framework/image/image_packer_native.h>
#include <multimedia/image_framework/image/image_source_native.h>
#include <multimedia/image_framework/image/picture_native.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

#define AUTO 0
#define SDR 1

class ImagePictureNative {
public:
    Image_ErrorCode errorCode = IMAGE_SUCCESS;
    OH_DecodingOptionsForPicture *options = nullptr;
    OH_ImagePackerNative *imagePacker = nullptr;
    OH_PackingOptions *packerOptions = nullptr;
    OH_PictureNative *picture = nullptr;
    OH_ImageSourceNative *source = nullptr;
    ImagePictureNative() {}
    ~ImagePictureNative() {}
};

class ImageAuxiliaryPictureNative {
public:
    Image_ErrorCode errorCode = IMAGE_SUCCESS;
    Image_AuxiliaryPictureType type = AUXILIARY_PICTURE_TYPE_GAINMAP;
    OH_AuxiliaryPictureNative *auxiliaryPicture = nullptr;
    size_t BUFF_SIZE = 640 * 480 * 4; 	//辅助图size 长*宽*每像素占用字节数。
    ImageAuxiliaryPictureNative() {}
    ~ImageAuxiliaryPictureNative() {}
};

static ImagePictureNative *thisPicture = new ImagePictureNative();
static ImageAuxiliaryPictureNative *thisAuxiliaryPicture = new ImageAuxiliaryPictureNative();

// 释放ImageSource。
Image_ErrorCode ReleaseImageSource(OH_ImageSourceNative *&source) {
    if (source != nullptr) {
        thisPicture->errorCode = OH_ImageSourceNative_Release(source);
        source = nullptr;
        return thisPicture->errorCode;
    }
    OH_LOG_DEBUG(LOG_APP, "ReleaseImageSource source is null !");
    return IMAGE_SUCCESS;
}

// 处理napi返回值。
napi_value getJsResult(napi_env env, int result) {
    napi_value resultNapi = nullptr;
    napi_create_int32(env, result, &resultNapi);
    return resultNapi;
}

// 创造解码参数。
static napi_value CreateDecodingOptions(napi_env env, napi_callback_info info) {
    thisPicture->errorCode = OH_DecodingOptionsForPicture_Create(&thisPicture->options);

    if (thisPicture->errorCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_DecodingOptionsForPicture_Create failed, errCode: %{public}d.",
            thisPicture->errorCode);
        return getJsResult(env, thisPicture->errorCode);
    } else {
        OH_LOG_DEBUG(LOG_APP, "OH_DecodingOptionsForPicture_Create success !");
    }

    return getJsResult(env, thisPicture->errorCode);
}

// 配置解码参数 从应用层传入。
static napi_value SetDesiredAuxiliaryPictures(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok || argc < 1 || args[0] == nullptr) {
        OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed !");
        return getJsResult(env, IMAGE_BAD_PARAMETER);
    }

    uint32_t length = 0;
    napi_get_array_length(env, args[0], &length);
    if (length <= 0) {
        OH_LOG_ERROR(LOG_APP, "napi_get_array_length failed !");
        return getJsResult(env, IMAGE_UNKNOWN_ERROR);
    }
    Image_AuxiliaryPictureType typeList[length];
    for (int index = 0; index < length; index++) {
        napi_value element;
        uint32_t ulType = 0;
        napi_get_element(env, args[0], index, &element);
        napi_get_value_uint32(env, element, &ulType);
        typeList[index] = static_cast<Image_AuxiliaryPictureType>(ulType);
        OH_LOG_DEBUG(LOG_APP, "ulType is :%{public}d", ulType);
    }

    thisPicture->errorCode =
        OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(thisPicture->options, typeList, length);
    if (thisPicture->errorCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures failed,errCode: %{public}d.",
            thisPicture->errorCode);
        return getJsResult(env, thisPicture->errorCode);
    } else {
        OH_LOG_DEBUG(LOG_APP, "OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures success !");
    }

    return getJsResult(env, thisPicture->errorCode);
}


// 解码。
static napi_value CreatePictureByImageSource(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value result = nullptr;

    if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok || argc < 1 || args[0] == nullptr) {
        OH_LOG_ERROR(LOG_APP, "CreatePicture_ napi_get_cb_info failed !");
        return getJsResult(env, IMAGE_BAD_PARAMETER);
    }
    char filePath[1024];
    size_t filePathSize;
    napi_get_value_string_utf8(env, args[0], filePath, 1024, &filePathSize);
    ReleaseImageSource(thisPicture->source);

    thisPicture->errorCode = OH_ImageSourceNative_CreateFromUri(filePath, filePathSize, &thisPicture->source);
    if (thisPicture->errorCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_CreateFromUri failed, errCode: %{public}d.",
            thisPicture->errorCode);
        return getJsResult(env, thisPicture->errorCode);
    } else {
        OH_LOG_DEBUG(LOG_APP, "OH_ImageSourceNative_CreateFromUri success !");
    }

    thisPicture->errorCode =
        OH_ImageSourceNative_CreatePicture(thisPicture->source, thisPicture->options, &thisPicture->picture);
    thisAuxiliaryPicture->errorCode = OH_PictureNative_GetAuxiliaryPicture(thisPicture->picture,
        thisAuxiliaryPicture->type, &thisAuxiliaryPicture->auxiliaryPicture);
    if (thisAuxiliaryPicture->errorCode == IMAGE_SUCCESS) {
        uint8_t* buff = new uint8_t[thisAuxiliaryPicture->BUFF_SIZE];
        OH_AuxiliaryPictureNative_ReadPixels(thisAuxiliaryPicture->auxiliaryPicture, buff,
            &thisAuxiliaryPicture->BUFF_SIZE);
        OH_AuxiliaryPictureNative_Release(thisAuxiliaryPicture->auxiliaryPicture);
        delete []buff;
    }
    if (thisPicture->errorCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNative_CreatePicture failed, errCode: %{public}d.", thisPicture->errorCode);
        return getJsResult(env, thisPicture->errorCode);
    } else {
        napi_status status =
            napi_create_external(env, reinterpret_cast<void *>(thisPicture->picture), nullptr, nullptr, &result);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Failed to create external object");
            return nullptr;
        }
        OH_LOG_DEBUG(LOG_APP, "ImageSourceNative_CreatePicture success !");
    }

    return result;
}
```
