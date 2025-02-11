# Using Image_NativeModule to Decode Pictures

In this process, you need to create an image source, decode a picture, and release the image source instance.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_source.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).

Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Decoding APIs**

After creating an **ImageSource** instance, obtain and modify property values, create a **PixelMap** object by using decoding parameters, and obtain the number of image frames.

   ```c++

    #include "imagepicture_native.h"
    #include "common/log_common.h"
    #include <bits/alltypes.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sstream>

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
        size_t BUFF_SIZE = 640 * 480 * 4;	// Size of the auxiliary picture (width * height * number of bytes per pixel).
        ImageAuxiliaryPictureNative() {}
        ~ImageAuxiliaryPictureNative() {}
    };

    static ImagePictureNative *thisPicture = new ImagePictureNative();
	static ImageAuxiliaryPictureNative *thisAuxiliaryPicture = new ImageAuxiliaryPictureNative();

    // Release the image source.
    Image_ErrorCode ReleaseImageSource(OH_ImageSourceNative *&source) {
        if (source != nullptr) {
            thisPicture->errorCode = OH_ImageSourceNative_Release(source);
            source = nullptr;
            return thisPicture->errorCode;
        }
        OH_LOG_DEBUG(LOG_APP, "ReleaseImageSource source is null !");
        return IMAGE_SUCCESS;
    }

    // Process the NAPI return value.
    napi_value getJsResult(napi_env env, int result) {
        napi_value resultNapi = nullptr;
        napi_create_int32(env, result, &resultNapi);
        return resultNapi;
    }

    // Create decoding parameters.
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

    // Configure decoding parameters, which are passed from the application layer.
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


    // Decode data.
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
