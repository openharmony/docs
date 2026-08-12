# How to Properly Handle High-Resolution Images

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @AiShangyou-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b195649f86d4bb8f11886ed1f90fd8c9b8c6a6db translatedAt=2026-08-11T01:56:57.784Z pushedAt=2026-08-12T03:38:15.770Z -->

## Overview

With the development of camera sensor technologies, more and more devices support high-resolution photos (such as 200-megapixel photos). High-resolution images provide higher image resolution and clearer details when zoomed in. However, they also result in larger file sizes, higher memory consumption during decoding and rendering, increased network transmission costs, and longer processing time. When processing high-resolution images in scenarios such as uploading, sharing, backup, editing, previewing, and large image viewing, an app should first determine whether the original resolution is required, and then select an appropriate solution, such as obtaining high-resolution originals, downsampling decoding, region decoding, or pixel format conversion.

## Processing Principles

1. **Determine whether high-resolution originals are required.** For scenarios such as lists, covers, chat messages, and sharing previews, use downsampled images or thumbnails whenever possible.

2. **Use the actual obtained file as the basis.** After obtaining an image through Photo Picker, a URI, or media library APIs, read the actual width, height, encoding format, and metadata again. Do not rely only on the file name, URI extension, or device model to obtain image information.

3. **Control the output size during decoding.** Set `desiredSize` based on the display size, set `desiredRegion` based on the visible area, and set `desiredPixelFormat` based on the processing workflow.

4. **Release image resources in a timely manner.** Images consume a large amount of memory. Release `PixelMap` or `ImageSource` instances that are no longer used when switching images, decoding images again, or destroying pages.

## FAQs

### Scenarios Requiring High-Resolution Originals

**When to Use**

1. Apps such as gallery, album, and image viewers that require zooming in to view details of high-resolution originals.

2. Apps such as cloud drives, backup services, and file transfer services that require storing or synchronizing high-resolution originals.

3. Apps such as image editing, cropping, printing, and professional content creation that require the original resolution.

4. Apps such as document scanning and industrial inspection that require viewing local textures, text, or defect details.

**Scenarios That Usually Do Not Require High-Resolution Originals**

1. Scenarios such as chat messages, avatars, feeds, and product lists that only require small-size previews.

2. Scenarios such as sharing covers, list cards, and common page images that only need to fit the screen display size.

3. Scenarios where upload time, data usage, or storage space is sensitive and the original resolution does not need to be retained.

**Processing Methods**

1. If the app only needs to display the entire image, use downsampling decoding.

2. If the app needs to zoom in and view details, combine region decoding with downsampling-based full-image preview.

3. If the app needs to upload, back up, or edit high-resolution originals, declare in the page that the application supports high-resolution original image processing. Since processing high-resolution images takes relatively longer, appropriate memory, network, and storage strategies should be designed.

### Uploading or Sharing High-Resolution Images Fails or Causes an Unexpected Exit

**Possible Causes**

1. The app directly decodes high-resolution images at their original resolution, resulting in excessive peak memory usage during decoding.

2. The decoded `PixelMap` object consumes a large amount of memory, or multiple high-resolution `PixelMap` objects are held simultaneously on the same page.

3. The app directly renders high-resolution images, exceeding the memory capacity supported by the rendering pipeline, causing the app to exit unexpectedly or the page to become unresponsive.

4. Before uploading or sharing, the app performs operations such as compression, rotation, watermarking, or filtering. As a result, the high-resolution original image, decoded result (`PixelMap`), and intermediate processing images coexist temporarily, causing excessive peak memory usage and unexpected exits.

**Solution**

1. For scenarios such as previews, lists, and covers, use downsampling decoding and generate `PixelMap` based on the actual display size. When users need to view local details, use region decoding to decode only the currently visible area or the target area after zooming in.

2. Avoid holding multiple high-resolution `PixelMap` objects on the same page for a long time. Release image resources promptly when `PixelMap` objects are no longer needed.

3. In upload or sharing scenarios, select high-resolution originals or downsampled images based on business requirements. If the original resolution is not required, upload or share downsampled images instead.

4. For workflows such as editing, compression, and watermarking, process operations sequentially whenever possible and reuse intermediate results to avoid holding multiple copies of large image data at the same time.

### Why Does an Image Obtained Through PhotoPicker or a URI Become a JPEG Image with Approximately 12 Megapixels or 12.5 Megapixels?

**Possible Causes**

In some access paths, the system converts high-resolution images into JPEG images with better compatibility to reduce the processing overhead for apps and improve compatibility. The converted images usually have approximately 12 megapixels or 12.5 megapixels. The actual result depends on the system implementation and image source.

**Solution**

Starting from API version 24, the `AssetCompatibleCapability` API is provided to configure whether an app supports high-resolution image assets.

If an app needs to obtain high-resolution originals, it must explicitly declare that it supports processing high-resolution image assets and implement appropriate downsampling, region decoding, and memory management in subsequent processing workflows.

When obtaining images through PhotoPicker, you can configure `assetCompatibleCapability` in [PhotoSelectOptions](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-class.md#photoselectoptions) to declare the capability to process high-resolution originals.

```typescript
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function pickerExample(): Promise<void> {
  try {
    const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    photoSelectOptions.assetCompatibleCapability = {
      supportedHighResolution: true
    } as photoAccessHelper.AssetCompatibleCapability;

    const photoPicker = new photoAccessHelper.PhotoViewPicker();
    const photoSelectResult: photoAccessHelper.PhotoSelectResult =
      await photoPicker.select(photoSelectOptions);
    console.info(`PhotoViewPicker.select successfully: ${JSON.stringify(photoSelectResult)}`);
  } catch (error) {
    const err = error as BusinessError;
    console.error(`PhotoViewPicker.select failed. code: ${err.code}, message: ${err.message}`);
  }
}
```

For apps that need to process media files as high-resolution originals, such as cloud storage and backup apps, use the [setAssetCompatibleCapability](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#setassetcompatiblecapability24) API to configure [AssetCompatibleCapability](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-i.md#assetcompatiblecapability24).

```typescript
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function enableHighResolution(
  phAccessHelper: photoAccessHelper.PhotoAccessHelper
): Promise<void> {
  const capability: photoAccessHelper.AssetCompatibleCapability = {
    supportedHighResolution: true
  };
  await phAccessHelper.setAssetCompatibleCapability(capability);
}

async function getHighResolutionAsset(
  phAccessHelper: photoAccessHelper.PhotoAccessHelper
): Promise<void> {
  try {
    await enableHighResolution(phAccessHelper);

    const predicates = new dataSharePredicates.DataSharePredicates();
    const fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [photoAccessHelper.PhotoKeys.URI],
      predicates
    };
    const fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> =
      await phAccessHelper.getAssets(fetchOptions);
    const asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    const srcFile = fs.openSync(asset.uri, fs.OpenMode.READ_ONLY);

    // After obtaining the fd, decode, upload, or back up as needed by your service.
    console.info(`Open source file successfully. fd: ${srcFile.fd}`);
  } catch (error) {
    const err = error as BusinessError;
    console.error(`Failed to get high resolution asset: code: ${err.code}, message: ${err.message}`);
  }
}
```

### The Obtained Image Has Unexpected Format, Size, or Metadata

**Possible Causes**

1. The app determines the image format based on the URI extension. However, the URI extension may not match the actual encoding format of the image.

2. The app directly uses the file attributes recorded in the media library for business logic decisions. However, the final obtained image file may have undergone compatibility conversion.

3. The app assumes that the file format, resolution, or metadata before and after obtaining the image are exactly the same, causing issues in upload validation, format branching, size checking, and other logic.

**Solution**

1. After obtaining the image URI or file descriptor (fd), use Image Kit APIs to read the actual image format, width, height, and other information.

2. Avoid determining image file attributes solely based on the URI extension, file name, or media library records.

3. For key workflows such as uploading, sharing, and editing, revalidate the format, size, and metadata using the final obtained image file.

**Example (ArkTS):**

Resolve the issue of incorrect image format detection by obtaining the actual MIME type. 

```typescript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getImageMimeType(filePath: string): string {
  try {
    const source: image.ImageSource = image.createImageSource(filePath);
    const info: image.ImageInfo = source.getImageInfoSync();
    const mime: string = info.mimeType;
    source.release();
    return mime;
  } catch (error) {
    return "";
  }
}
```

**Example (C/C++):**

Resolve the issue of incorrect image format detection by obtaining the actual MIME type.

Add `libimage_source.so` and `libimage_common.so` to the `target_link_libraries` dependency.

```cmake
target_link_libraries(entry PUBLIC libimage_source.so libimage_common.so)
```

```cpp
#include <cstdlib>
#include <cstring>
#include <multimedia/image_framework/image_source_native.h>
#include <multimedia/image_framework/image_common.h>

/**
 * @brief Obtains the MIME type of an image through a file descriptor.
 *
 * The returned string must be freed by the caller (using free()).
 *
 * @param fd Image file descriptor. The caller is responsible for opening and closing the fd.
 * @return Returns a dynamically allocated MIME type string on success; returns nullptr on failure.
 */
static char* GetImageMimeType(int32_t fd)
{
    if (fd < 0) {
        return nullptr;
    }

    OH_ImageSourceNative *source = nullptr;
    Image_ErrorCode ret = OH_ImageSourceNative_CreateFromFd(fd, &source);
    if (ret != IMAGE_SUCCESS || source == nullptr) {
        return nullptr;
    }

    OH_ImageSource_Info *info = nullptr;
    ret = OH_ImageSourceInfo_Create(&info);
    if (ret != IMAGE_SUCCESS || info == nullptr) {
        OH_ImageSourceNative_Release(source);
        return nullptr;
    }

    ret = OH_ImageSourceNative_GetImageInfo(source, 0, info);
    if (ret != IMAGE_SUCCESS) {
        OH_ImageSourceInfo_Release(info);
        OH_ImageSourceNative_Release(source);
        return nullptr;
    }

    Image_MimeType mime = {nullptr, 0};
    ret = OH_ImageSourceInfo_GetMimeType(info, &mime);
    if (ret != IMAGE_SUCCESS || mime.data == nullptr) {
        OH_ImageSourceInfo_Release(info);
        OH_ImageSourceNative_Release(source);
        return nullptr;
    }

    char *result = static_cast<char *>(malloc(mime.size + 1));
    if (result == nullptr) {
        OH_ImageSourceInfo_Release(info);
        OH_ImageSourceNative_Release(source);
        return nullptr;
    }

    memcpy(result, mime.data, mime.size);
    result[mime.size] = '\0';

    OH_ImageSourceInfo_Release(info);
    OH_ImageSourceNative_Release(source);
    return result;
}
```

### How to Determine Whether an Image Is a High-Resolution Image?

**How to Determine**

The app can calculate the total pixel count from the image width and height, and determine whether the image is a high-resolution image based on a service-defined threshold. The example in this document uses `width * height >= 100000000` as the criterion for high-resolution images, meaning the total pixel count is no less than 100 million.

This threshold is not a fixed standard; it is primarily used to identify images that impose high decoding and rendering memory pressure. The app can adjust the threshold based on the target device memory, page display size, performance metrics, and service experience requirements.

Note that the image width and height obtained are the original dimensions only when high-resolution original image access is enabled; otherwise, the dimensions of the converted compatibility file are obtained. For the access method, see [Why Does an Image Obtained Through PhotoPicker or a URI Become a JPEG Image with Approximately 12 Megapixels or 12.5 Megapixels?](#why-does-an-image-obtained-through-photopicker-or-a-uri-become-a-jpeg-image-with-approximately-12-megapixels-or-125-megapixels).

**Example (ArkTS):**

```typescript
import { image } from '@kit.ImageKit';

const HIGH_PIXEL_THRESHOLD: number = 100000000;

function isHighPixelImage(fd: number): boolean {
  let imageSource: image.ImageSource | undefined = undefined;
  try {
    imageSource = image.createImageSource(fd);
    const imageInfo: image.ImageInfo = imageSource.getImageInfoSync();
    const width: number = imageInfo.size.width;
    const height: number = imageInfo.size.height;
    const pixelCount: number = width * height;
    return pixelCount >= HIGH_PIXEL_THRESHOLD;
  } catch (error) {
    return false;
  } finally {
    imageSource?.release();
  }
}
```

**Example (C/C++):**

Add `libimage_source.so` to the `target_link_libraries` dependency.

```cmake
target_link_libraries(entry PUBLIC libimage_source.so)
```

```cpp
#include <cstdint>
#include <multimedia/image_framework/image_common.h>
#include <multimedia/image_framework/image_source_native.h>

static constexpr uint64_t HIGH_PIXEL_THRESHOLD = 100000000ULL;

/**
 * @brief Determines whether an image is a high-resolution image.
 *
 * Determination rule:
 * width * height >= 100000000.
 *
 * @param fd Image file descriptor. The caller is responsible for opening and closing the fd.
 * @return true indicates a high-resolution image.
 * @return false indicates not a high-resolution image, or failure to obtain image information.
 */
static bool IsHighPixelImage(int32_t fd)
{
    if (fd < 0) {
        return false;
    }

    OH_ImageSourceNative *imageSource = nullptr;
    Image_ErrorCode ret = OH_ImageSourceNative_CreateFromFd(fd, &imageSource);
    if (ret != IMAGE_SUCCESS || imageSource == nullptr) {
        return false;
    }

    OH_ImageSource_Info *imageInfo = nullptr;
    ret = OH_ImageSourceInfo_Create(&imageInfo);
    if (ret != IMAGE_SUCCESS || imageInfo == nullptr) {
        OH_ImageSourceNative_Release(imageSource);
        return false;
    }

    ret = OH_ImageSourceNative_GetImageInfo(imageSource, 0, imageInfo);
    if (ret != IMAGE_SUCCESS) {
        OH_ImageSourceInfo_Release(imageInfo);
        OH_ImageSourceNative_Release(imageSource);
        return false;
    }

    uint32_t width = 0;
    uint32_t height = 0;
    ret = OH_ImageSourceInfo_GetWidth(imageInfo, &width);
    if (ret != IMAGE_SUCCESS) {
        OH_ImageSourceInfo_Release(imageInfo);
        OH_ImageSourceNative_Release(imageSource);
        return false;
    }

    ret = OH_ImageSourceInfo_GetHeight(imageInfo, &height);
    if (ret != IMAGE_SUCCESS) {
        OH_ImageSourceInfo_Release(imageInfo);
        OH_ImageSourceNative_Release(imageSource);
        return false;
    }

    uint64_t pixelCount = static_cast<uint64_t>(width) * static_cast<uint64_t>(height);
    bool isHighPixel = pixelCount >= HIGH_PIXEL_THRESHOLD;
    OH_ImageSourceInfo_Release(imageInfo);
    OH_ImageSourceNative_Release(imageSource);
    return isHighPixel;
}
```

### How to Select a Pixel Format for Decoding?

**When to Use**

When `desiredPixelFormat` is not specified for image decoding APIs, `PixelMap` is generated using `RGBA_8888` by default for the display pipeline. `RGBA_8888` is suitable for image display, editing, and general-purpose image processing. However, when decoding high-resolution images using `RGBA_8888`, the memory usage is usually estimated based on `width * height * 4`.

If the app does not require an alpha channel, select a more appropriate format based on the subsequent processing workflow.

| Decoding Pixel Format | Applicable Scenario | Memory Estimation (Actual memory usage may be higher due to hardware alignment) |
| --- | --- | --- |
| `image.PixelMapFormat.RGBA_8888` | General display and editing, or scenarios requiring an alpha channel and high color precision. | Approximately 4 bytes/pixel. |
| `image.PixelMapFormat.RGB_565` | Preview, thumbnail, and list image scenarios that do not require an alpha channel and have lower color precision requirements. | Approximately 2 bytes/pixel. |
| `image.PixelMapFormat.NV21`, `image.PixelMapFormat.NV12` | Scenarios that do not require an alpha channel and need subsequent access to YUV processing pipelines such as camera, video, algorithm, or hardware codec. | Approximately 2 bytes/pixel. |

**Processing Methods**

1. For general display or editing, use `RGBA_8888` first because it provides better compatibility and easier processing.

2. For previews that do not require transparency and can accept lower color accuracy, select `RGB_565` to reduce memory usage.

3. When entering camera, video, algorithm, or certain hardware codec workflows, use `NV21` or `NV12` first to avoid unnecessary conversions between RGBA and YUV.

4. When specifying a target pixel format, verify that the target processing workflow and display pipeline support the specified format, and perform thorough validation.

**Example**

```typescript
import { image } from '@kit.ImageKit';

const decodingOptions: image.DecodingOptions = {
  desiredSize: { width: 0, height: 0 }, // This is the default value of desiredSize. Under this configuration, the image is decoded at its original size.
  desiredPixelFormat: image.PixelMapFormat.RGB_565 // Configure different decoding formats based on specific requirements.
};
```

### How to Optimize High-Resolution Image Memory Usage Using Downsampling or Region Decoding?

**When to Use**

For scenarios such as list previews, the first screen of a details page, and sharing previews that only require images to be displayed on the screen, use downsampling decoding whenever possible. When the app involves large image viewing, gesture-based zooming, or viewing local details (such as a custom image viewer), combine region decoding with downsampling decoding to balance display quality and memory safety.

**Processing Methods**

1. Use downsampling decoding to design the target size based on the target display size, screen resolution, and user experience requirements, such as 8K, 4K, or 2K.

2. When using downsampling decoding, set `desiredSize` to generate a `PixelMap` with the target size. It is recommended to configure this parameter based on the aspect ratio to avoid image distortion. If the original image size is small, do not configure this parameter to avoid unnecessary scaling performance overhead.

3. When users zoom in or drag an image, use region decoding to calculate the area of the original image that needs to be displayed based on the current interaction state.

4. Use `desiredRegion` in region decoding to load only the target area, and update the decoding region when the interaction state changes.

5. Region decoding releases image areas that are no longer displayed to avoid caching excessive `PixelMap` objects.

6. (Optional) If the app needs to control memory usage or integrate with a specific processing workflow, set `desiredPixelFormat` as well.

For examples of downsampling and region decoding, see [Image Region Decoding and Downsampling (C/C++)](../image/image-region-and-downsampling-c.md) or [Image Region Decoding and Downsampling (ArkTS)](../image/image-region-and-downsampling.md).

## Summary of High-Resolution Image Processing

1. After reading an image, obtain the actual width and height first, estimate the memory usage after decoding, and then determine the processing strategy.

2. For displaying the entire image only, use downsampling decoding. Do not directly decode and render the image at its original size.

3. For viewing high-resolution local details, use region decoding. Avoid decoding the entire original image just to view a local area.

4. Select a pixel format based on business requirements. For previews that do not require transparency, consider using `RGB_565`. For YUV processing workflows, consider using `NV21` or `NV12`.

5. Control the number of `PixelMap` objects held simultaneously on the same page. Release resources when switching images, decoding images again, or destroying pages.

6. For workflows such as uploading, editing, compression, and filtering, release resources promptly to avoid retaining multiple large intermediate images at the same time.