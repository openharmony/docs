# Image Error Codes
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->


> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 501 API Call Failed

**Error Message**

Resource unavailable.

**Symptom**

This error code is reported when an API fails to be called.

**Possible Cause**

The image is transferred across threads, and the original object cannot call the API.

**Solution**

Check the image and follow the instructions to decode it.

## 62980096 Operation Failed

**Error Message**

The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.

**Symptom**

This error code is reported when the operations fails.

**Possible Cause**

1. An exception occurs during image upload.
2. Other operations are performed during decoding.
3. Image decoding is not performed as instructed.
4. The memory of the device is insufficient.
5. The processing on the decoding library fails.

**Solution**

Check the image and follow the instructions to decode it.

## 62980097 PixelMap Serialization Failed

**Error Message**

IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.

**Symptom**

This error code is reported when PixelMap serialization and transmission fails.

**Possible Cause**

1. An exception occurs during image upload.
2. Other operations are performed during decoding.
3. Image decoding is not performed as instructed.
4. The memory of the device is insufficient.

**Solution**

Check the image and follow the instructions to decode it.

## 62980098 Shared Memory Error

**Error Message**

Shared memory does not exist.

**Symptom**

This error code is reported when a shared memory space error occurs.

**Possible Cause**

1. The size of the shared memory is insufficient.
2. It is out-of-bounds access to the shared memory.
3. An invalid pointer is used.

**Solution**

Check the memory usage or restart the device.

## 62980099 Data Error in the Shared Memory

**Error Message**

The shared memory data is abnormal.

**Symptom**

This error code is reported when a data error occurs in the shared memory.

**Possible Cause**

1. The synchronization operation is not correctly performed when data is read from or written to the shared memory.
2. It is out-of-bounds access to the shared memory.
3. An invalid pointer is used.

**Solution**

Restart the device.

## 62980100 Image Decoding Error

**Error Message**

Image decoding abnormal.

**Symptom**

This error code is reported when an image decoding error occurs.

**Possible Cause**

1. An exception occurs during image upload.
2. Other operations are performed during decoding.
3. Image decoding is not performed as instructed.
4. The memory of the device is insufficient.

**Solution**

Check the image and follow the instructions to decode it.

## 62980101 Incorrect Input Image Data

**Error Message**

The image data is abnormal.

**Symptom**

This error code is reported when the input image data is incorrect.

**Possible Cause**

1. The input image data is incorrect.
2. The format of the image is incorrect.
3. The size of the image is incorrect.

**Solution**

Use a valid image.

## 62980102 Memory Allocation Error for Images

**Error Message**

Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data.

**Symptom**

This error code is reported when an error occurs during image memory allocation.

**Possible Cause**

The device memory is insufficient or occupied.

**Solution**

Clear the memory and try again.

## 62980103 Unsupported Image Type

**Error Message**

The image data is not supported.

**Symptom**

The image type is not supported.

**Possible Cause**

The input image type is not supported.

**Solution**

Change the image type and try again.

## 62980104 Image Initialization Error

**Error Message**

Image initialization abnormal. This status code is thrown when an error occurs during the process of creating empty pixelmap.

**Symptom**

This error code is reported when an image initialization error occurs.

**Possible Cause**

1. The image type is not supported.
2. The image size is not supported.
3. An error occurs during initialization.

**Solution**

Correct the parameters or user another image.

## 62980105 Failure in Obtaining Image Data

**Error Message**

Failed to get the data.

**Symptom**

This error code is reported when the image data fails to be obtained.

**Possible Cause**

1. The device does not support the image type.
2. Image data is lost.

**Solution**

Correct the image data or use another image.

## 62980106 Too Large Image Data

**Error Message**

The image data is too large. This status code is thrown when an error occurs during the process of checking size.

**Symptom**

This error code is reported when the image data is too large.

**Possible Cause**

The image is too large.

**Solution**

Use a smaller image.

## 62980107 Image Conversion Error

**Error Message**

Image conversion abnormal.

**Symptom**

This error code is reported when an image conversion error occurs.

**Possible Cause**

1. Image conversion stops unexpectedly.
2. Encoding parameters are incorrectly set.

**Solution**

Correct the encoding parameters or use another image.

## 62980108 Image Color Conversion Error

**Error Message**

Failed to convert the color space.

**Symptom**

This error code is reported when an image color conversion error occurs.

**Possible Cause**

1. Color conversion is not supported for the image type.
2. The device is faulty.

**Solution**

Try again or change the image type.

## 62980109 Cropping Error

**Error Message**

Failed to crop the image.

**Symptom**

This error code is reported when a cropping error occurs.

**Possible Cause**

1. Cropping parameters are incorrectly set.
2. The image data is incorrect.

**Solution**

Correct the cropping parameters or image data.

## 62980110 Incorrect Image Source Data

**Error Message**

The image source data is incorrect.

**Symptom**

The image source data is incorrect.

**Possible Cause**

The image source data is missing or incorrect.

**Solution**

Check the operation procedure or use another image.

## 62980111 Incomplete Image Source Data

**Error Message**

The image source data is incomplete.

**Symptom**

This error code is reported when the image source data is incomplete.

**Possible Cause**

The image source data is missing.

**Solution**

Check the operation procedure or use another image.

## 62980112 Image Format Mismatch

**Error Message**

The image format does not match.

**Symptom**

This error code is reported when an image format mismatch error occurs.

**Possible Cause**

The image format does not match.

**Solution**

Use an image in a matched format.

## 62980113 Unknown Image Format

**Error Message**

Unknown image format.The image data provided is not in a recognized or supported format, or it may be corrupted.

**Symptom**

This error code is reported when the image format is unknown.

**Possible Cause**

The image format is not supported.

**Solution**

Use another image.

## 62980114 Image Source Not Parsed

**Error Message**

Image source not parsed.

**Symptom**

This error code is reported when the image source is not parsed.

**Possible Cause**

The image source data is incorrect.

**Solution**

Correct the image source data.

## 62980115 Invalid Image Parameter

**Error Message**

Invalid image parameter.

**Symptom**

This error code is reported when the image parameter is invalid.

**Possible Cause**

An input parameter is invalid.

**Solution**

Correct the input parameter.

## 62980116 Decoding Failure

**Error Message**

Failed to decode the image.

**Symptom**

This error code is reported when decoding fails.

**Possible Cause**

1. The decoding process exits abnormally.
2. The image format is not supported.
3. No image is read.

**Solution**

Ensure that the image is read or use another image.

## 62980117 Plugin Registration Failure

**Error Message**

Failed to register the plugin.

**Symptom**

This error code is reported when the plugin registration fails.

**Possible Cause**

1. No decoding or encoding plugin of the corresponding format is found.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 62980118 Plugin Creation Failure

**Error Message**

Failed to create the image plugin.

**Symptom**

This error code is reported when the plugin creation fails.

**Possible Cause**

1. No decoding or encoding plugin of the corresponding format is found.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 62980119 Image Encoding Failure

**Error Message**

Failed to encode the image.

**Symptom**

This error code is reported when the image encoding fails.

**Possible Cause**

1. The encoding format is not supported.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 62980120 Failure in Adding Pixel Mappings

**Error Message**

Add pixelmap out of range.

**Symptom**

This error code is reported when pixel mapping fails to be added.

**Possible Cause**

1. Adding pixel mappings is not supported.
2. An exception occurs during the addition of the pixel mapping.

**Solution**

Check the operation procedure or use another image.

## 62980121 Hardware Decoding Not Supported

**Error Message**

Image hardware decoding is not supported.

**Symptom**

This error code is reported when image hardware decoding is not supported.

**Possible Cause**

Image hardware decoding is used.

**Solution**

Use another decoding mode.

## 62980122 Failure in Decoding the Image Header

**Error Message**

Failed to decode the image header.

**Symptom**

This error code is reported when the image header fails to be decoded.

**Possible Cause**

1. An exception occurs during the decoding of the image header.
2. The image header does not meet the decoding requirements.

**Solution**

Correct the image data or use another image.

## 62980123 Exif Decoding Not Supported

**Error Message**

The image does not support EXIF decoding.

**Symptom**

The image does not support Exif decoding.

**Possible Cause**

The image does not support Exif decoding.

**Solution**

Use another image.

## 62980124 Missing Image Property

**Error Message**

The image property does not exist.

**Symptom**

This error code is reported when the image property does not exist.

**Possible Cause**

1. The image property is missing.
2. The image is modified improperly.

**Solution**

Use another image.

## 62980133 Image Property Value Out of Range

**Error Message**

The EXIF data is out of range.

**Symptom**

The value of the image property is out of range.

**Possible Cause**

The value of the image property is out of range.

**Solution**

Change the image or check the length of the image property value.

## 62980135 Invalid Image Property Value

**Error Message**

The EXIF value is invalid.

**Symptom**

This error code is reported when the image property value is invalid.

**Possible Cause**

The image property is missing.

**Solution**

Correct the image data or use another image.

## 62980137 Invalid Image Operation

**Error Message**

Invalid media operation.

**Symptom**

This error code is reported when the image operation is invalid.

**Possible Cause**

The current image format does not support this operation.

**Solution**

Use another image.

## 62980146 Failed to Write Image Property Values to the File

**Error Message**

The EXIF data failed to be written to the file.

**Symptom**

This error code is reported when image property values fail to be written to the file.

**Possible Cause**

The property values of the image are abnormal.

**Solution**

Use another image.

## 62980149 Invalid Image Parameter

**Error Message**

Invalid MIME type for the image source.

**Symptom**

This error code is reported when the image parameter is invalid.

**Possible Cause**

The current image format does not support this operation.

**Solution**

Use another image.

## 62980172 Failed to Encode ICC

**Error Message**

Failed to encode icc.

**Symptom**

This error code is reported when ICC encoding fails.

**Possible Cause**

The image ICC information is incorrect.

**Solution**

Verify the image data or use another image.

## 62980173 DMA Memory Space Error

**Error Message**

The DMA memory does not exist.

**Symptom**

This error code is reported when a DMA memory space error occurs.

**Possible Cause**

1. The size of the shared memory is insufficient.
2. Out-of-bounds memory access occurs.
3. An invalid pointer is used.

**Solution**

Check the memory usage or restart the device.

## 62980174 Abnormal DMA Memory Data

**Error Message**

The DMA memory data is abnormal.

**Symptom**

This error code is reported when the DMA memory data is abnormal.

**Possible Cause**

1. The synchronization operation is not correctly performed when data is read from or written to the shared memory.
2. Out-of-bounds memory access occurs.
3. An invalid pointer is used.

**Solution**

Restart the device.

## 62980177 Abnormal API Environment

**Error Message**

Abnormal API environment.

**Symptom**

This error code is reported when the API environment is abnormal.

**Possible Cause**

The environment where the API is used is incorrect.

**Solution**

Check the SDK version.

## 62980178 Failure in Creating a PixelMap

**Error Message**

Failed to create the PixelMap.

**Symptom**

This error code is reported when the PixelMap fails to be created.

**Possible Cause**

1. Input parameters are incorrect. For example, the region size exceeds the upper limit or an invalid value is passed in.
2. The instance is incorrectly released in advance.

**Solution**

Ensure that the input parameters are correct and the instance is available.

## 62980179 Abnormal Buffer Size

**Error Message**

Abnormal buffer size.

**Symptom**

This error code is reported when the buffer size is abnormal.

**Possible Cause**

Input parameters are incorrect. For example, the region size exceeds the upper limit or an invalid value is passed in.

**Solution**

Check the input parameters.

## 62980180 Failure in Mapping the File Descriptor

**Error Message**

FD mapping failed.

**Symptom**

This error code is reported when the file descriptor fails to be mapped.

**Possible Cause**

The input file descriptor is incorrect.

**Solution**

Pass a correct file descriptor.

## 62980246 Failure in Reading the PixelMap

**Error Message**

Failed to read the pixel map.

**Symptom**

This error code is reported when the PixelMap fails to be read.

**Possible Cause**

1. The PixelMap data is incorrect.
2. You do not have the permission to read data from the PixelMap.

**Solution**

Create another PixelMap or request the read permission.

## 62980247 Failure in Writing the PixelMap

**Error Message**

Failed to write the pixel map.

**Symptom**

This error code is reported when the PixelMap fails to be written.

**Possible Cause**

1. The PixelMap data is incorrect.
2. You do not have the permission to write data to the PixelMap.

**Solution**

Create another PixelMap or request the read permission.

## 62980248 No Modification to the PixelMap

**Error Message**

PixelMap does not allow modification.

**Symptom**

This error code is reported when the PixelMap is modified, which is not allowed.

**Possible Cause**

Users try to modify a PixelMap.

**Solution**

Do not modify the PixelMap.

## 62980252 Failed to Create a Surface

**Error Message**

Failed to create surface.

**Symptom**

This error code is reported when a surface fails to be created.

**Possible Cause**

An error occurred when requesting memory for image encoding.

**Solution**

Try again or use another image.

## 62980259 Incorrect Configuration

**Error Message**

Configuration error.

**Symptom**

This error code is reported when the configuration is incorrect.

**Possible Cause**

The configuration is incorrect.

**Solution**

Correct the configuration.

## 62980274 Failed to Convert Images

**Error Message**

The conversion failed.

**Symptom**

This error code is reported when image conversion fails.

**Possible Cause**

1. Image conversion stops unexpectedly.
2. Encoding parameters are incorrectly set.

**Solution**

Correct the encoding parameters or use another image.

## 62980276 Unsupported Image Conversion Target Type

**Error Message**

The type to be converted is an unsupported target pixel format.

**Symptom**

This error code is reported when the image conversion target type is not supported.

**Possible Cause**

The conversion to the target type is not supported.

**Solution**

Use another image or change the target type.

## 62980286 Failed to Set a Memory Identifier for a PixelMap

**Error Message**

Memory format not supported.

**Symptom**

This error code is reported when the memory identifier fails to be set for PixelMap.

**Possible Cause**

1. The memory type of the PixelMap does not match.
2. The FD of the PixelMap is invalid.
3. Unknown kernel error.

**Solution**

Check whether the PixelMap instance has been released. Check whether the memory type matches.

## 62980302 Memory Copy Failed

**Error Message**

Memory copy failed.

**Symptom**

This error code is reported when memory copy fails.

**Possible Cause**

1. The memory type does not match.
2. The FD is invalid.
3. Unknown kernel error.

**Solution**

Check whether the instance to be copied has been released. Check whether the memory type matches.

## 7600101 Unsupported MIME Type

**Error Message**

Unsupported mime type.

**Symptom**

This error code is reported when the MIME type is not supported.

**Possible Cause**

The device does not support the MIME type.

**Solution**

Verify the image data or use another image. You can call relevant APIs to query the codec capability range.

## 7600102 Unknown MIME Type

**Error Message**

Unknown mime type.

**Symptom**

This error is reported for an unknown MIME type.

**Possible Cause**

The device does not support the image type or the image is damaged.

**Solution**

Verify the image data or use another image.

## 7600103 Data or Image Too Large

**Error Message**

Too large data or image.

**Symptom**

This error code is reported if the data or image is too large.

**Possible Cause**

The image dimensions are too large.

**Solution**

Use a smaller image.

## 7600104 Failed to Obtain Image Data

**Error Message**

Failed to get the data from Surface.

**Symptom**

This error code is reported when image data fails to be obtained.

**Possible Cause**

1. The device does not support the image type.
2. The image data is damaged or lost.

**Solution**

Verify the image data source or use new image data.

## 7600105 PixelMap Object Has Been Released

**Error Message**

PixelMap has been released.

**Symptom**

The PixelMap object has been released.

**Possible Cause**

The PixelMap object has been released, and its associated native object no longer exists.

**Solution**

Check whether the PixelMap object may be released in advance (for example, released unexpectedly in an asynchronous task or another thread). Ensure that the object is not released before it is no longer used and all asynchronous methods are executed.

## 7600106 PixelMap Has Been Passed to Another Thread

**Error Message**

PixelMap has been passed to another thread.

**Symptom**

The PixelMap has been passed to another thread.

**Possible Cause**

The PixelMap object has been passed to another thread, and the object in the original thread cannot continue to call the API.

**Solution**

Do not call the API of the PixelMap object in the original thread after the object has been passed to another thread.

## 7600173 DMA Memory Does Not Exist

**Error Message**

DMA memory does not exist.

**Symptom**

This error code is reported if the DMA memory does not exist.

**Possible Cause**

The DMA memory is not used to decode HDR images.

**Solution**

Use a correct memory allocation type.

## 7600174 DMA Operation Failed

**Error Message**

DMA operation failed.

**Symptom**

This error code is reported if the operation on the DMA memory fails.

**Possible Cause**

The synchronization operation is not correctly performed when data is read from or written to the DMA memory.

**Solution**

Read and write the DMA memory in a correct way.

## 7600201 Unsupported Operation

**Error Message**

Unsupported operation, e.g. on cross-platform.

**Symptom**

This error code is reported when the operation is not supported, for example, modifying a PixelMap whose **Editable** property is **false**.

**Possible Cause**

The operation is not supported. For example, modify a PixelMap whose **Editable** property is **false**.

**Solution**

Use a supported operation.

## 7600202 Unsupported Metadata Read/Write Operation

**Error Message**

Unsupported metadata. Possible causes: Unsupported metadata type.

**Symptom**

This error code is reported when the metadata read/write operation is not supported.

**Possible Cause**

The metadata read/write operation is not supported. For example, the Exif field to read or write is not supported, or users attempt to obtain specific data from an auxiliary picture of an incorrect type (for example, attempt to obtain GainmapMetadata of a depth map).

**Solution**

Check whether the auxiliary picture type corresponds to the metadata type, and then perform the read and write operations.

## 7600203 Unsupported Conversion

**Error Message**

Unsupported conversion.

**Symptom**

This error code is reported for unsupported conversion.

**Possible Cause**

The PixelMap data cannot be converted.

**Solution**

Use PixelMap data with a matching format.

## 7600204 Invalid Region

**Error Message**

Invalid region.

**Symptom**

This error code is reported when a region is invalid.

**Possible Cause**

The area to crop (its position, width, or height) falls outside the dimensions of the original image.

**Solution**

Adjust the **Region** parameters so that the entire crop area falls within the dimensions of the original image.

## 7600205 Unsupported Format

**Error Message**

Unsupported memory format or pixel format.

**Symptom**

This error code is reported when the memory format or pixel format is not supported.

**Possible Cause**

The API does not support the memory format or pixel format of the PixelMap.

**Solution**

Check the API specifications for the list of supported formats, and convert the PixelMap to a compatible format before passing it to this API.

## 7600206 Invalid Parameter

**Error Message**

Invalid parameter.

**Symptom**

This error code is reported when the parameter is invalid.

**Possible Cause**

An input parameter is invalid.

**Solution**

Enter correct parameters.

## 7600207 Unsupported Data Format

**Error Message**

Unsupported data format.

**Symptom**

Unsupported data format.

**Possible Cause**

1. The API does not support the input pixel data format.
2. The data format in the object does not support the specific operation.

**Solution**

Check the API reference and use the data format supported by the API.

## 7600208 Failed to Decompose an HDR Image

**Error Message**

HDR image decomposition failed. Possible causes: 1. Decomposition processing is not supported. 2. Processing error occurs.

**Symptom**

Failed to decompose the HDR image.

**Possible Cause**

1. The decomposition is not supported.
2. An error occurred during HDR image processing.

**Solution**

Check whether the pixel format of the HDR PixelMap supports decomposition, or change the image and try again.

## 7600301 Memory Allocation Failure

**Error Message**

Memory alloc failed.

**Symptom**

This error code is reported when the memory allocation fails.

**Possible Cause**

The device memory is insufficient or occupied.

**Solution**

Clear the memory and try again.

## 7600302 Memory Copy Failure

**Error Message**

Memory copy failed.

**Symptom**

This error code is reported when memory copy fails.

**Possible Cause**

The memory to copy does not exist, or the device memory is insufficient.

**Solution**

Check whether the memory to copy exists. Clear the memory and try again.

## 7600303 Memory Lock or Unlock Failed

**Error Message**

Memory lock or unlock failed.

**Symptom**

This error is reported if memory lock or unlock fails.

**Possible Cause**

The PixelMap or memory address is invalid.

**Solution**

Ensure that the PixelMap or memory address is valid.

## 7600305 Failed to Create the PixelMap

**Error Message**

Failed to create the PixelMap.

**Symptom**

This error code is reported when the PixelMap fails to be created.

**Possible Cause**

1. Incorrect parameter. For example, the region is not in the valid range or an invalid value is passed in.
2. The instance is incorrectly released in advance.

**Solution**

Ensure that the input parameters are correct and the instance is available.

## 7600306 Data Conversion Failed

**Error Message**

Data conversion failed.

**Symptom**

Data conversion failed.

**Possible Cause**

1. The size of the input pixel data buffer does not meet the expectation.
2. The pixel data in the PixelMap is damaged.

**Solution**

1. If a buffer is passed, check whether the buffer size meets the expectation.
2. Ensure that the pixel data and metadata of the PixelMap are normal.

## 7600501 Unsupported Allocator Mode

**Error Message**

Unsupported allocator mode, e.g., use share memory to create a HDR image as only DMA supported hdr metadata.

**Symptom**

This error code is reported for unsupported allocator mode.

**Possible Cause**

No memory allocation type is specified, or an incorrect memory allocation type is specified. For example, an error occurs when an HDR image is decoded in shared memory mode, because only the DMA mode supports HDR metadata.

**Solution**

Use a correct memory allocation type.

## 7600901 Unknown Error

**Error Message**

Unknown error.

**Symptom**

This error code is reported when an unknown error occurs.

**Possible Cause**

Errors caused by unknown reasons.

**Solution**

Locate the cause based on logs.

## 7700101 Abnormal Image Source

**Error Message**

Bad source.

**Symptom**

This error code is reported when the image source is abnormal.

**Possible Cause**

1. The device does not support the image type.
2. Image decoding is not performed as instructed.
3. The image source data is incomplete. Starting from API version 17, the system has been optimized at the underlying level. When encountering incomplete data, the system will attempt partial decoding to output as much valid pixel data as possible. However, if the file header information (such as image dimensions or color configuration) of the image source data is incomplete, or if there is a severe lack of image pixel data blocks, the system may still fail to decode the image properly, resulting in a decoding failure. Currently, only JPEG, PNG, and BMP image formats support partial decoding for incomplete data.

**Solution**

Verify the image data or use another image.

## 7700102 Unsupported MIME Type

**Error Message**

Unsupported MIME type.

**Symptom**

This error code is reported when the MIME type is not supported.

**Possible Cause**

The device does not support the image type.

**Solution**

Verify the image data or use another image.

## 7700103 Image Oversized

**Error Message**

Image too large.

**Symptom**

The image is too large.

**Possible Cause**

The image size exceeds the upper limit.

**Solution**

Verify the image data or use another image.

## 7700201 Unsupported Memory Allocation Type

**Error Message**

Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata.

**Symptom**

This error code is reported when the memory allocator type is not supported.

**Possible Cause**

No memory allocation type is specified, or an incorrect memory allocation type is specified. For example, an error occurs when an HDR image is decoded in shared memory mode, because only the DMA mode supports HDR metadata.

**Solution**

Use a correct memory allocation type.

## 7700202 Unsupported Metadata

**Error Message**

Unsupported metadata.

**Symptom**

This error code is reported when the metadata is not supported.

**Possible Cause**

1. An unsupported metadata field is entered.
2. The value of the metadata field is invalid.

**Solution**

Check whether the metadata field is supported or whether the metadata value is valid.

## 7700203 Unsupported Options

**Error Message**

Unsupported options, e.g, cannot convert image into desired pixel format.

**Symptom**

This error code is reported when an option is not supported.

**Possible Cause**

Some parameters are incorrectly configured, or the operation required by the options is not supported.

**Solution**

Verify the parameter settings.

## 7700204 Invalid Parameter

**Error Message**

Invalid parameter.

**Symptom**

This error code is reported when the parameter is invalid.

**Possible Cause**

An input parameter is invalid.

**Solution**

Enter correct parameters.

## 7700301 Decoding Failure

**Error Message**

Decode failed.

**Symptom**

This error code is reported when decoding fails.

**Possible Cause**

1. The memory of the device is insufficient.
2. The device does not support the image type.
3. Image decoding is not performed as instructed.

**Solution**

Verify the image data or use another image.

## 7700302 Memory Allocation Failed

**Error Message**

Memory allocation failed.

**Symptom**

This error code is reported when the memory allocation fails.

**Possible Cause**

1. The memory of the device is insufficient.
2. Image decoding is not performed as instructed.

**Solution**

Check the device memory or input data.

## 7700303 Image Does Not Contain Thumbnail Data

**Error Message**

Image does not carry thumbnail data.

**Symptom**

This error is reported when the image does not contain thumbnail data.

**Possible Cause**

The image file does not contain thumbnail data, and the thumbnail generation function is not enabled.

**Solution**

Ensure that the image file contains thumbnail data and that the thumbnail generation function is enabled. Then try again.

## 7700305 Thumbnail Generation Failed

**Error Message**

Thumbnail generation failed.

**Symptom**

This error code is reported when the thumbnail generation fails.

**Possible Cause**

1. The input image data is abnormal.
2. The thumbnail generation parameters are improper.
3. Device resources are insufficient.

**Solution**

Verify the input image data and thumbnail generation parameters, and release the system resources if necessary. Then try again.

## 7700304 Failed to Write Image Information to the File

**Error Message**

Failed to write image properties to the file.

**Symptom**

This error code is reported when the image information fails to be written into the file.

**Possible Cause**

1. The image data is incorrect.
2. You do not have the necessary permissions to modify the image file.

**Solution**

Check the image data and confirm that you have the required permissions for the image file.

## 7800201 Unsupported Options

**Error Message**

Unsupported options.

**Symptom**

This error code is reported when an option is not supported.

**Possible Cause**

Some parameters are incorrectly configured, or the operation required by the options is not supported.

**Solution**

Verify the parameter settings.

## 7800202 Invalid ImagePacker Parameter

**Error Message**

Invalid parameter for ImagePacker.

**Symptom**

This error code is reported if the encoding parameter is invalid.

**Possible Cause**

The encoding parameter is empty or invalid.

**Solution**

Verify the encoding parameter settings.

## 7800301 Encoding Failure

**Error Message**

Encode failed.

**Symptom**

This error code is reported when encoding fails.

**Possible Cause**

1. The encoding format is not supported.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 7900201 Invalid Parameter

**Error Message**

Invalid parameter.

**Symptom**

This error code is reported when the parameter is invalid.

**Possible Cause**

1. The number of passed parameters is incorrect, or their value types are incorrect.
2. The image format is not supported.

**Solution**

Verify the parameter settings.
