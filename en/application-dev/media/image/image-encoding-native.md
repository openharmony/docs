# Image Encoding
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This guide uses the APIs provided by the [Image](../../reference/apis-image-kit/capi-image.md) module, which supports basic functionalities such as image encoding/decoding, image receiver operations, and image data processing. These APIs are introduced prior to API version 11, and no additional features will be included in later versions. Therefore, these APIs are not recommended.
>
> You can also use the C APIs provided by the [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md) module, which includes all the foundational features of the Image module while adding new capabilities like multi-image encoding/decoding. For details about the development guide, see [Using Image_NativeModule to Decode Images (C/C++)](image-source-c.md). These APIs are available since API version 12 and are expected to keep evolving. You are encouraged to use them.
>
> You are not advised to use both sets of C APIs in your code. It may cause compatibility issues in some scenarios.

You can call the native APIs provided by the ImagePacker module to encode images, that is, to compress a PixelMap object into an image in the desired format.

Currently, images can be encoded only into the JPEG, WebP, PNG, or HEIF format (depending on the hardware).

**Usage Scenario**

- Image codec conversion

  Import an image source, and encapsulate it into the desired format.
- Image editing

  Edit a PixelMap object, and export an image in the desired format.

## How to Develop

Read the [API reference](../../reference/apis-image-kit/capi-image-packer-mdk-h.md) for APIs related to image encoding.

Refer to the code snippet below to complete the entire image encoding process, including creating an encoder, initializing resources, performing encoding, and destroying the encoder.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.  

The figure below shows the call relationship of image encoding.

![Call relationship of image encoding](figures/image-encode-native.png)

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(entry PUBLIC libace_napi.z.so)
target_link_libraries(entry PUBLIC libimage_packer_ndk.z.so)
```

### How to Develop

1. Add the header file **image_packer_mdk.h**.

   ```cpp
   // Add the header file image_packer_mdk.h.
   #include <multimedia/image_framework/image_packer_mdk.h>
   ```

2. Create an encoder instance.

   You must use napi_env to create an encoder.

   ```cpp
   // Use napi_value to undertake the created encoder instance.
   napi_value packer;
   // Use napi_env to create an encoder. If result is IMAGE_RESULT_SUCCESS, the encoder is created.
   int32_t result = OH_ImagePacker_Create(env, &packer);
   ```

3. Initialize resources.

   Call **OH_ImagePacker_InitNative** to initialize the encoder instance.

   ```cpp
   // Initialize the instance through napi_env and the created encoder instance.
   ImagePacker_Native* nativePacker = OH_ImagePacker_InitNative(env, packer);
   ```

4. Perform encoding.

   The following input parameters are provided for the encoding APIs:

   - ImagePacker_Native instance obtained

   - Image source (napi_value), PixelMap object, or ImageSource object (when **CreatePixelMap** is not called yet) to be encoded

   - Encoding parameters, including the encoding format and encoding quality

      > **NOTE**
      >
      > According to the MIME protocol, the standard encoding format is image/jpeg. When the APIs provided by the image module are used for encoding, **format** of the encoding parameters must be set to **image/jpeg**. The file name extension of the encoded image file can be .jpg or .jpeg, and the file can be used on platforms that support image/jpeg decoding.

   The encoding APIs can output data to the buffer (memory) or a file. They have the same input parameters, as described previously. You can select either of them as required.

   Output data to the buffer (memory).

   ```cpp
   #include <cstdlib>
   #include <multimedia/image_framework/image_packer_mdk.h>

   int32_t packImageToData(napi_env env, napi_callback_info info)
   {
       napi_value source;
       // Use napi_value to undertake the created encoder instance.
       napi_value packer;
       // Use napi_env to create an encoder. If result is IMAGE_RESULT_SUCCESS, the encoder is created.
       int32_t errorCode = OH_ImagePacker_Create(env, &packer);
       if (errorCode != IMAGE_RESULT_SUCCESS) {
           return errorCode;
       }
       // Initialize the instance through napi_env and the created encoder instance.
       ImagePacker_Native* nativePacker = OH_ImagePacker_InitNative(env, packer);
       // Encoding parameters.
       struct ImagePacker_Opts_ opts;
       // (Mandatory) Configure the encoding format.
       opts.format = "image/jpeg";
       // (Mandatory) Configure the encoding quality.
       opts.quality = 95;
       // Set the output buffer size, for example, to 4 KB.
       size_t bufferSize = 4*1024;
       // Apply for a buffer for image encoding.
       uint8_t* outData = (uint8_t *)(malloc(bufferSize));
       if (outData == NULL) {
           errorCode = OH_ImagePacker_Release(nativePacker);
           if (errorCode != IMAGE_RESULT_SUCCESS) {
               return errorCode;
           } else {
               nativePacker = NULL; // The encoder cannot be destroyed repeatedly.
           }
           return IMAGE_RESULT_MALLOC_ABNORMAL;
       }
       // Start to encode the input source. If IMAGE_RESULT_SUCCESS is returned, the encoding is successful. In this case, bufferSize indicates the size of the buffer used for encoding.
       int32_t result = OH_ImagePacker_PackToData(nativePacker, source, &opts, outData, &bufferSize);
       free(outData);
       outData = NULL;
       errorCode = OH_ImagePacker_Release(nativePacker);
       if (errorCode != IMAGE_RESULT_SUCCESS) {
           return errorCode;
       } else {
           nativePacker = NULL; // The encoder cannot be destroyed repeatedly.
       }
       return result;
   }
   ```

   Output data to a file.

   ```cpp
   #include <fcntl.h>
   #include <unistd.h>
   #include <cstdlib>
   #include <multimedia/image_framework/image_packer_mdk.h>

   int32_t packImageToFile(napi_env env, napi_callback_info info)
   {
       napi_value source;
       // Use napi_value to undertake the created encoder instance.
       napi_value packer;
       // Use napi_env to create an encoder. If result is IMAGE_RESULT_SUCCESS, the encoder is created.
       int32_t errorCode = OH_ImagePacker_Create(env, &packer);
       if (errorCode != IMAGE_RESULT_SUCCESS) {
           return errorCode;
       }
       // Initialize the instance through napi_env and the created encoder instance.
       ImagePacker_Native* nativePacker = OH_ImagePacker_InitNative(env, packer);
       // Encoding parameters.
       struct ImagePacker_Opts_ opts;
       // (Mandatory) Configure the encoding format.
       opts.format = "image/jpeg";
       // (Mandatory) Configure the encoding quality.
       opts.quality = 100;
       // Open the file to which the data will be written. (Ensure that the application has the permission to access the file path.)
       int fd = open("/data/test.jpg", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
       int result;
       if (fd >= 0) {
           // Start to encode the input source. If IMAGE_RESULT_SUCCESS is returned, the encoding is successful.
           result = OH_ImagePacker_PackToFile(nativePacker, source, &opts, fd);
           // Close the file.
           close(fd);
       }
       errorCode = OH_ImagePacker_Release(nativePacker);
       if (errorCode != IMAGE_RESULT_SUCCESS) {
           return errorCode;
       } else {
           nativePacker = NULL; // The encoder cannot be destroyed repeatedly.
       }
       return result;
   }
   ```
