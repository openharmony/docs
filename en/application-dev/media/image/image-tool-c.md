# Using Image_NativeModule to Edit EXIF Data
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

Image Kit provides the capabilities of reading and editing Exchangeable Image File Format (EXIF) data.

EXIF is a file format dedicated for photos taken by digital cameras and is used to record attributes and shooting data of the photos. Currently, JPEG, PNG, and HEIF images that contain EXIF data are supported.

Users may need to view or modify the EXIF data of photos in the Gallery application, for example, when the manual lens parameters of the camera are not automatically written as part of the EXIF data or the shooting time is incorrect due to camera power-off.

Currently, OpenHarmony allows you to view and modify part of EXIF data. For details, see [OHOS_IMAGE_PROPERTY_XXX](../../reference/apis-image-kit/capi-image-common-h.md#variables).

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_source.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)
```

### Calling the Native APIs

For details about the C APIs for reading and editing EXIF data, see [OH_ImageSource_GetImageProperty](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) and [OH_ImageSource_ModifyImageProperty](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_modifyimageproperty).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example for Reading and Editing EXIF Data**

After an ImageSource instance is created, read and edit its EXIF data.

```c++

#include <linux/kd.h>
#include <string>

#include <hilog/log.h>
#include <multimedia/image_framework/image/image_source_native.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "MY_TAG"

#define NUM_0 0
#define NUM_1 1

// Process the NAPI return value.
napi_value getJsResult(napi_env env, int result) {
    napi_value resultNapi = nullptr;
    napi_create_int32(env, result, &resultNapi);
    return resultNapi;
}

static napi_value exifTest(napi_env env, napi_callback_info info)
{
    napi_value argValue[NUM_1] = {0};
    size_t argCount = NUM_1;
    if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < NUM_1 ||
        argValue[NUM_0] == nullptr) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest napi_get_cb_info failed, argCount: %{public}d.", argCount);
        return getJsResult(env, IMAGE_BAD_PARAMETER);
    }
    char name[1024];
    size_t nameSize = 1024;
    napi_get_value_string_utf8(env, argValue[NUM_0], name, 1024, &nameSize);

    // Create an ImageSource instance.
    OH_ImageSourceNative *source = nullptr;
    Image_ErrorCode errCode = OH_ImageSourceNative_CreateFromUri(name, nameSize, &source);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest OH_ImageSourceNative_CreateFromUri failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // Read the EXIF data, where OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE indicates the number of bits per pixel.
    Image_String getKey;
    const std::string PIXEL_X_DIMENSION = OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE;
    getKey.data = (char *)PIXEL_X_DIMENSION.c_str();
    getKey.size = PIXEL_X_DIMENSION.length();
    Image_String getValue;
    errCode = OH_ImageSourceNative_GetImageProperty(source, &getKey, &getValue);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest OH_ImageSourceNative_GetImageProperty failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // Edit the EXIF data, where OHOS_IMAGE_PROPERTY_ORIENTATION indicates the image orientation.
    Image_String setKey;
    const std::string ORIENTATION = OHOS_IMAGE_PROPERTY_ORIENTATION;
    setKey.data = (char *)ORIENTATION.c_str();
    setKey.size = ORIENTATION.length();
    Image_String setValue;
    setValue.data = (char *)"4";
    setValue.size = 1;
    errCode = OH_ImageSourceNative_ModifyImageProperty(source, &setKey, &setValue);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest OH_ImageSourceNative_ModifyImageProperty failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }
    
    // Release the ImageSource instance.
    OH_ImageSourceNative_Release(source);
    OH_LOG_INFO(LOG_APP, "ImageSourceNativeCTest exifTest success.");
    return getJsResult(env, IMAGE_SUCCESS);
}
```
