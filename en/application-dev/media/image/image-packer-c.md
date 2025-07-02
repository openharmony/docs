# Using Image_NativeModule to Encode Images

You can use the **ImagePacker** class to create and release ImagePacker instances.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_packer.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libimage_packer.so libpixelmap.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Encoding APIs**

After an ImagePacker instance is created and encoding parameters are specified, the ImageSource or Pixelmap object is encoded to a file or buffer.

> **NOTE**
>
> According to the MIME protocol, the standard encoding format is image/jpeg. When the APIs provided by the image module are used for encoding, **image_MimeType** of the encoding parameters must be set to **image/jpeg**. The file name extension of the encoded image file can be .jpg or .jpeg, and the file can be used on platforms that support image/jpeg decoding.

```c++
#include <linux/kd.h>
#include <string>
#include <set>
#include <hilog/log.h>
#include <multimedia/image_framework/image/image_common.h>
#include <multimedia/image_framework/image/image_packer_native.h>
#include <multimedia/image_framework/image/pixelmap_native.h>
#include <multimedia/image_framework/image/image_source_native.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "MY_TAG"

static std::set<std::string> g_encodeSupportedFormats;

Image_MimeType GetMimeTypeIfEncodable(const char *format)
{
    auto it = g_encodeSupportedFormats.find(format);
    if (it == g_encodeSupportedFormats.end()) {
        return {"", 0};
    }
    return {const_cast<char *>(format), strlen(format)};
}

Image_ErrorCode packToFileFromImageSourceTest(int fd)
{
    // Create an ImagePacker instance.
    OH_ImagePackerNative *testPacker = nullptr;
    Image_ErrorCode errCode = OH_ImagePackerNative_Create(&testPacker);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest CreatePacker OH_ImagePackerNative_Create failed, errCode: %{public}d.", errCode);
        return errCode;
    }
    // Obtain the encoding capability range.
    Image_MimeType* mimeType = nullptr;
    size_t length = 0;
    errCode = OH_ImagePackerNative_GetSupportedFormats(&mimeType, &length);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImagePackerNative_GetSupportedFormats failed, errCode: %{public}d.", errCode);
        return errCode;
    }
    for (size_t count = 0; count < length; count++) {
        OH_LOG_INFO(LOG_APP, "Encode supportedFormats:%{public}s", mimeType[count].data);
        if (mimeType[count].data != nullptr) {
            g_encodeSupportedFormats.insert(std::string(mimeType[count].data));
        }
    }
    // Create an ImageSource instance.
    OH_ImageSourceNative* imageSource = nullptr;
    errCode = OH_ImageSourceNative_CreateFromFd(fd, &imageSource);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImageSourceNative_CreateFromFd  failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Specify encoding parameters and encode the ImageSource into a file.
    OH_PackingOptions *option = nullptr;
    OH_PackingOptions_Create(&option);
    Image_MimeType image_MimeType = GetMimeTypeIfEncodable(MIME_TYPE_JPEG);
    if (image_MimeType.data == nullptr || image_MimeType.size == 0) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest GetMimeTypeIfEncodable failed, format can't support encode.");
        return IMAGE_BAD_PARAMETER;
    }
    OH_PackingOptions_SetMimeType(option, &image_MimeType);
    // Encode the content as HDR content. (The resource must be HDR resource and the JPEG format must be supported.)
    OH_PackingOptions_SetDesiredDynamicRange(option, IMAGE_PACKER_DYNAMIC_RANGE_AUTO);
    errCode = OH_ImagePackerNative_PackToFileFromImageSource(testPacker, option, imageSource, fd);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImagePackerNative_PackToFileFromImageSource failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Release the ImagePacker instance.
    errCode = OH_ImagePackerNative_Release(testPacker);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_ImagePackerNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }
    // Release the ImageSource instance.
    errCode = OH_ImageSourceNative_Release(imageSource);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_ImageSourceNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    return IMAGE_SUCCESS;
}

Image_ErrorCode packToFileFromPixelmapTest(uint8_t *buffer, size_t bufferSize, int fd)
{
    // Create an ImagePacker instance.
    OH_ImagePackerNative *testPacker = nullptr;
    Image_ErrorCode errCode = OH_ImagePackerNative_Create(&testPacker);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest CreatePacker OH_ImagePackerNative_Create failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Create a Pixelmap instance.
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, 6);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, 4);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, 3);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, 0);
    OH_PixelmapNative *pixelmap = nullptr;
    errCode = OH_PixelmapNative_CreatePixelmap(buffer, bufferSize, createOpts, &pixelmap);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_PixelmapNative_CreatePixelmap  failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Specify encoding parameters and encode the PixelMap into a file.
    OH_PackingOptions *option = nullptr;
    OH_PackingOptions_Create(&option);
    char type[] = "image/jpeg";
    Image_MimeType image_MimeType = {type, strlen(type)};
    OH_PackingOptions_SetMimeType(option, &image_MimeType);
    errCode = OH_ImagePackerNative_PackToFileFromPixelmap(testPacker, option, pixelmap, fd);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImagePackerNative_PackToFileFromPixelmap  failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Release the ImagePacker instance.
    errCode = OH_ImagePackerNative_Release(testPacker);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_ImagePackerNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Release the Pixelmap instance.
    errCode = OH_PixelmapNative_Release(pixelmap);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_PixelmapNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    return IMAGE_SUCCESS;
}
```
