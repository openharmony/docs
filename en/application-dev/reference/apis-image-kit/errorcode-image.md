# Image Error Codes


> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 501 API Call Failed

**Error Message**

Resource unavailable.

**Possible Cause**

The image is transferred across threads, and the original object cannot call the API.

**Solution**

Check the image and follow the instructions to decode it.

## 62980096 Operation Failed

**Error Message**

Transaction operation failed.

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

RPC error.

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

**Possible Cause**

1. The size of the shared memory is insufficient.
2. It is out-of-bounds access to the shared memory.
3. An invalid pointer is used.

**Solution**

Check the memory usage or restart the device.

## 62980099 Data Error in the Shared Memory

**Error Message**

Shared memory data abnormal.

**Possible Cause**

1. The synchronization operation is not correctly performed when data is read from or written to the shared memory.
2. It is out-of-bounds access to the shared memory.
3. An invalid pointer is used.

**Solution**

Restart the device.

## 62980100 Image Decoding Error

**Error Message**

Image decoding abnormal.

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

**Possible Cause**

1. The input image data is incorrect.
2. The format of the image is incorrect.
3. The size of the image is incorrect.

**Solution**

Use a valid image.

## 62980102 Memory Allocation Error for Images

**Error Message**

Image malloc abnormal.

**Possible Cause**

The device memory is insufficient or occupied.

**Solution**

Clear the memory and try again.

## 62980103 Unsupported Image Type

**Error Message**

Image types are not supported.

**Possible Cause**

The input image type is not supported.

**Solution**

Change the image type and try again.

## 62980104 Image Initialization Error

**Error Message**

Image initialization abnormal.  

**Possible Cause**

1. The image type is not supported.
2. The image size is not supported.
3. An error occurs during initialization.

**Solution**

Correct the parameters or user another image.

## 62980105 Failure in Obtaining Image Data

**Error Message**

Failed to get the image data.

**Possible Cause**

1. The device does not support the image type.
2. Image data is lost.

**Solution**

Correct the image data or use another image.

## 62980106 Too Large Image Data

**Error Message**

The image data is too large.

**Possible Cause**

The image is too large.

**Solution**

Use a smaller image.

## 62980107 Image Conversion Error

**Error Message**

Image conversion abnormal.

**Possible Cause**

1. Image conversion stops unexpectedly.
2. Encoding parameters are incorrectly set.

**Solution**

Correct the encoding parameters or use another image.

## 62980108 Image Color Conversion Error

**Error Message**

Image color conversion is abnormal.

**Possible Cause**

1. Color conversion is not supported for the image type.
2. The device is faulty.

**Solution**

Try again or change the image type.

## 62980109 Cropping Error

**Error Message**

Cropping exceptions.

**Possible Cause**

1. Cropping parameters are incorrectly set.
2. The image data is incorrect.

**Solution**

Correct the cropping parameters or image data.

## 62980110 Incorrect Image Source Data

**Error Message**

The image source data is abnormal.

**Possible Cause**

The image source data is missing or incorrect.

**Solution**

Check the operation procedure or use another image.

## 62980111 Incomplete Image Source Data

**Error Message**

The image source data is incomplete.

**Possible Cause**

The image source data is missing.

**Solution**

Check the operation procedure or use another image.

## 62980112 Image Format Mismatch

**Error Message**

The image format does not match.

**Possible Cause**

The image format does not match.

**Solution**

Use an image in a matched format.

## 62980113 Unknown Image Format

**Error Message**

Unknown image format.

**Possible Cause**

The image format is not supported.

**Solution**

Use another image.

## 62980114 Image Source Not Parsed

**Error Message**

Image source not parsed.

**Possible Cause**

The image source data is incorrect.

**Solution**

Correct the image source data.

## 62980115 Invalid Image Parameter

**Error Message**

Invalid image parameter.

**Possible Cause**

An input parameter is invalid.

**Solution**

Correct the input parameter.

## 62980116 Decoding Failure

**Error Message**

Decoding failed.

**Possible Cause**

1. The decoding process exits abnormally.
2. The image format is not supported.
3. No image is read.

**Solution**

Ensure that the image is read or use another image.

## 62980117 Plugin Registration Failure

**Error Message**

Failed to register the plugin.

**Possible Cause**

1. No decoding or encoding plugin of the corresponding format is found.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 62980118 Plugin Creation Failure

**Error Message**

Failed to create the plugin.

**Possible Cause**

1. No decoding or encoding plugin of the corresponding format is found.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 62980119 Image Encoding Failure

**Error Message**

Image encoding failed.

**Possible Cause**

1. The encoding format is not supported.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.

## 62980120 Failure in Adding Pixel Mappings

**Error Message**

Failed to add the pixel mappings.

**Possible Cause**

1. Adding pixel mappings is not supported.
2. An exception occurs during the addition of the pixel mapping.

**Solution**

Check the operation procedure or use another image.

## 62980121 Hardware Decoding Not Supported

**Error Message**

Image hardware decoding is not supported.

**Possible Cause**

Image hardware decoding is used.

**Solution**

Use another decoding mode.

## 62980122 Failure in Decoding the Image Header

**Error Message**

Failed to decode the image header.

**Possible Cause**

1. An exception occurs during the decoding of the image header.
2. The image header does not meet the decoding requirements.

**Solution**

Correct the image data or use another image.

## 62980123 EXIF Decoding Not Supported

**Error Message**

The image does not support EXIF decoding.

**Possible Cause**

The image does not support EXIF decoding.

**Solution**

Use another image.

## 62980124 Missing Image Attribute

**Error Message**

The image property does not exist.

**Possible Cause**

1. The image attribute is missing.
2. The image is modified improperly.

**Solution**

Use another image.

## 62980133 Image Attribute Value Out of Range

**Error Message**

The EXIF data is out of range.

**Possible Cause**

The value of the image attribute is out of range.

**Solution**

Change the image or check the length of the image attribute value.

## 62980135 Invalid Image Attribute Value

**Error Message**

The EXIF value is invalid.

**Possible Cause**

The image attribute is missing.

**Solution**

Correct the image data or use another image.

## 62980137 Invalid Image Operation

**Error Message**

Invalid media operation.

**Possible Cause**

The target image format does not support this operation.

**Solution**

Use another image.

## 62980149 Invalid Image Parameter

**Error Message**

Invalid MIME type for the image source.

**Possible Cause**

The target image format does not support this operation.

**Solution**

Use another image.

## 62980178 Failure in Creating a PixelMap

**Error Message**

Failed to create the PixelMap.

**Possible Cause**

1. Input parameters are incorrect. For example, the region size exceeds the upper limit or an invalid value is passed in.
2. The instance is incorrectly released in advance.

**Solution**

Check whether the input parameters are correct and whether the instance is released in advance.

## 62980246 Failure in Reading the PixelMap

**Error Message**

Failed to read the pixel map.

**Possible Cause**

1. The PixelMap data is incorrect.
2. You do not have the permission to read the PixelMap.

**Solution**

Re-create the PixelMap or change the read permission.

## 62980247 Failure in Writing the PixelMap

**Error Message**

Failed to write the pixel map.

**Possible Cause**

1. The PixelMap data is incorrect.
2. You do not have the permission to write the PixelMap.

**Solution**

Re-create the PixelMap or change the read permission.

## 62980248 No Modification to the PixelMap

**Error Message**

PixelMap does not allow modification.

**Possible Cause**

Users try to modify a PixelMap.

**Solution**

Do not modify the PixelMap.

## 62980259 Incorrect Configuration

**Error Message**

Configuration error.

**Possible Cause**

The configuration is incorrect.

**Solution**

Correct the configuration.

## 62980286 Failed to Set a Memory Identifier for a PixelMap

**Error Message**

fail set name.

**Possible Cause**

1. The memory type of the PixelMap does not match.
2. The FD of the PixelMap is invalid.
3. Unknown kernel error.

**Solution**

Check whether the PixelMap instance has been released. Check whether the memory type matches.

## 7600201 Unsupported Operation

**Error Message**

Unsupported operation.

**Possible Cause**

The operation is not supported.

**Solution**

Use a supported operation.

## 7600202 Unsupported Metadata Read/Write Operation

**Error Message**

Unsupported metadata. Possible causes: Unsupported metadata type.

**Possible Cause**

The metadata read/write operation is not supported. For example, the Exif field to read or write is not supported, or users attempt to obtain specific data from an auxiliary picture of an incorrect type (for example, attempt to obtain GainmapMetadata of a depth map).

**Solution**

Check whether the auxiliary picture type corresponds to the metadata type, and then perform the read and write operations.

## 7600301 Memory Allocation Failure

**Error Message**

Memory alloc failed.

**Possible Cause**

The device memory is insufficient or occupied.

**Solution**

Clear the memory and try again.

## 7600302 Memory Copy Failure

**Error Message**

Memory copy failed.

**Possible Cause**

The memory to copy does not exist, or the device memory is insufficient.

**Solution**

Check whether the memory to copy exists. Clear the memory and try again.

## 7600901 Unknown Error

**Error Message**

Unknown error.

**Possible Cause**

Errors caused by unknown reasons.

**Solution**

Locate the cause based on logs.

## 7700301 Decoding Failure

**Error Message**

Decode failed.

**Possible Cause**

1. The memory of the device is insufficient.
2. The device does not support the image type.
3. Image decoding is not performed as instructed.

**Solution**

Check the image data or replace the image.

## 7800301 Encoding Failure

**Error Message**

Encode failed.

**Possible Cause**

1. The encoding format is not supported.
2. The data passed in is incorrect.

**Solution**

Correct the input data or use another image.
