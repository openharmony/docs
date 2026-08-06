# Enums
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

A collection of enumeration types provided by Image Kit, covering image pixel formats, image formats, alpha types, image metadata, image property information (Exif and format-specific properties), auxiliary image types, scaling modes, cropping and scaling strategies, dynamic range, HDR metadata, memory allocation, interpolation algorithms, image orientation, focus modes, color modes, XMP tag types, and more. These enumerations are used to specify various configuration parameters in image encoding, decoding, processing, and display scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## PixelMapFormat<sup>7+</sup>

Enumerates image pixel formats.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | Unknown format.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.       |
| ARGB_8888<sup>18+</sup> | 1 | Color information consists of four components: transparency (Alpha), Red (R), Green (G), and Blue (B). Each component occupies 8 bits, totaling 32 bits. The components are stored in order from the most significant bit to the least significant bit. Currently, this format supports only PixelMap APIs.|
| RGB_565                | 2      | Color information consists of three components: Red (R), Green (G), and Blue (B). R occupies 5 bits, G occupies 6 bits, and B occupies 5 bits, totaling 16 bits. The components are stored in order from the most significant bit to the least significant bit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.    |
| RGBA_8888              | 3      | Color information consists of four components: Red (R), Green (G), Blue (B), and transparency (Alpha). Each component occupies 8 bits, totaling 32 bits. The components are stored in order from the most significant bit to the least significant bit. It corresponds to [CAMERA_FORMAT_RGBA_8888 in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| BGRA_8888<sup>9+</sup> | 4      | Color information consists of four components: Blue (B), Green (G), Red (R), and transparency (Alpha). Each component occupies 8 bits, totaling 32 bits. The components are stored in order from the most significant bit to the least significant bit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| RGB_888<sup>9+</sup>   | 5      | Color information consists of three components: Red (R), Green (G), and Blue (B). Each component occupies 8 bits, totaling 24 bits. The components are stored in order from the most significant bit to the least significant bit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| ALPHA_8<sup>9+</sup>   | 6      | Color information consists of only the transparency (Aalpha), with 8 bits per pixel, stored in order from the most significant bit to the least significant bit. Each row of pixels is composed of one or more pixels, and the data for each row is aligned to 4 bytes. If the byte count of a row is not a multiple of 4, blank bytes are padded at the end to ensure proper alignment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| RGBA_F16<sup>9+</sup>  | 7      | Color information consists of four components: Red (R), Green (G), Blue (B), and transparency (Alpha). Each component occupies 16 bits, totaling 64 bits. The components are stored in order from the most significant bit to the least significant bit, in FP16 half-precision floating-point format.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| NV21<sup>9+</sup>      | 8      | YVU pixel arrangement, where the V component precedes the U component. Color information consists of a luminance component Y and interleaved chrominance components V and U. The Y component occupies 8 bits, and the UV components occupy an average of 4 bits due to 4:2:0 subsampling, totaling an average of 12 bits. The components are stored in order from the most significant bit to the least significant bit. It corresponds to [CAMERA_FORMAT_YUV_420_SP in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| NV12<sup>9+</sup>      | 9      | YUV pixel arrangement, where the U component precedes the V component. Color information consists of a luminance component Y and interleaved chrominance components U and V. The Y component occupies 8 bits, and the UV components occupy an average of 4 bits due to 4:2:0 subsampling, totaling an average of 12 bits. The components are stored in order from the most significant bit to the least significant bit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| RGBA_1010102<sup>12+</sup> | 10 | Color information consists of four components: Red (R), Green (G), Blue (B), and transparency (Alpha). R, G, and B each occupy 10 bits, and Alpha occupies 2 bits, totaling 32 bits. The components are stored in order from the most significant bit to the least significant bit.|
| YCBCR_P010<sup>12+</sup> | 11 | Color information consists of a luminance component Y and chrominance components Cb and Cr. Each component has an effective bit depth of 10 bits. In storage, the Y plane occupies 16 bits per pixel (with 10 effective bits), and the UV plane is interleaved, occupying 32 bits for every 4 pixels (with 10 effective bits per chrominance component), resulting in an average effective bit depth of 15 bits. The data is stored in order from the most significant bit to the least significant bit. It corresponds to [CAMERA_FORMAT_YCBCR_P010 in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat). |
| YCRCB_P010<sup>12+</sup> | 12 | Color information consists of a luminance component Y and chrominance components Cb and Cr. Each component has an effective bit depth of 10 bits. In storage, the Y plane occupies 16 bits per pixel (with 10 effective bits), and the UV plane is interleaved, occupying 32 bits for every 4 pixels (with 10 effective bits per chrominance component), resulting in an average effective bit depth of 15 bits. The data is stored in order from the most significant bit to the least significant bit. It corresponds to [CAMERA_FORMAT_YCRCB_P010 in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat). |
| Y8 | 14 | Single-channel grayscale format that contains only the Y plane (luminance). Each pixel occupies 8 bits, stored in order from the most significant bit to the least significant bit.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model. |
| ALPHA_U8 | 15 | Color information consists of only the transparency (Aalpha), with 8 bits per pixel, stored in order from the most significant bit to the least significant bit. All pixels are tightly arranged without alignment.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 26.0.0. |
| ALPHA_F16 | 16 | Color information consists of only the transparency (Aalpha), with each pixel occupying 16 bits. The data is stored in order from the most significant bit to the least significant bit in FP16 half-precision floating-point format.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 26.0.0. |
| ASTC_4x4<sup>18+</sup> | 102 | The storage format is ASTC_4x4, and the memory usage is only 1/4 of that of RGBA_8888. This format is intended for direct display scenarios. It does not support pixel access or editing in post-processing, and does not support cascaded affine transformations. |

## AlphaType<sup>9+</sup>

Enumerates image transparency types.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    |   Value  | Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown type.           |
| OPAQUE   | 1      | No alpha channel, or the image is opaque.|
| PREMUL   | 2      | RGB channels are premultiplied with the alpha value.        |
| UNPREMUL | 3      | RGB channels are not premultiplied with the alpha value.      |

## AuxiliaryPictureType<sup>13+</sup>

Enumerates auxiliary picture types.

Auxiliary pictures do not directly participate in image display, and not all images contain auxiliary pictures.

Before obtaining and using a specific auxiliary picture, call [getAuxiliaryPicture](./arkts-apis-image-Picture.md#getauxiliarypicture13) in Picture to obtain the auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| GAINMAP       | 1    | Gain map.<br>It is used to generate HDR images more accurately.<br>HDR synthesis usually involves using the SDR main image, gain map, and HDR metadata (see [getMetadata](./arkts-apis-image-PixelMap.md#getmetadata12)) to calculate the luminance mapping.|
| DEPTH_MAP     | 2    | Depth map.<br>It is used to store the distance between each pixel and the camera, and provides the 3D structure of the scene.<br>It is useful for tasks like 3D reconstruction, background separation, and scene understanding.    |
| UNREFOCUS_MAP | 3    | Unrefocus map.<br>It is used to store the pixel content that is not refocused during capture.<br>It is useful for post-processing effects such as portrait blurring, allowing users to select focus areas freely. |
| LINEAR_MAP    | 4    | Linear map.<br>It records lighting, color, or other visual elements linearly, providing additional data for image processing.<br>It is useful for visual effect enhancement and color post-processing. |
| FRAGMENT_MAP  | 5    | Fragment map.<br>It records areas of the original image obscured by watermarks. These areas might be cropped from the original image or filled with placeholder pixel data.<br>It is useful for watermark removal and original image restoration.|
| LHDR_GAINMAP  | 10    | Special gain map (LHDR gain map).<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## MetadataType<sup>13+</sup>

Enumerates image metadata types.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value  | Description              |
| ----------------- | ---- | ------------------ |
| EXIF_METADATA     | 1    | Exif data.        |
| FRAGMENT_METADATA | 2    | Fragment map metadata.|
| GIF_METADATA<sup>20+</sup> | 5    | GIF image metadata.|
| HEIFS_METADATA<sup>23+</sup> | 15    | HEIF image sequence metadata.<br>**Model restriction**: This API can be used only in the stage model.|
| DNG_METADATA<sup>24+</sup> | 16    | DNG image metadata.<br>**Model restriction**: This API can be used only in the stage model.|
| WEBP_METADATA<sup>24+</sup> | 17    | WebP image metadata.<br>**Model restriction**: This API can be used only in the stage model.|
| PNG_METADATA | 19    | PNG image metadata.<br>**Model restriction**: This API can be used only in the stage model.<br>**Since**: 26.0.0|
| JFIF_METADATA | 20    | JFIF image metadata.<br>**Model restriction**: This API can be used only in the stage model.<br>**Since**: 26.0.0|
| TIFF_METADATA | 21    | TIFF image metadata.<br>**Model restriction**: This API can be used only in the stage model.<br>**Since**: 26.0.0|
| XMP_METADATA | 22    | XMP image metadata.<br>**Model restriction**: This API can be used only in the stage model.<br>**Since**: 26.0.0|
| AVIS_METADATA | 23    | AVIS image metadata.<br>**Model restriction**: This API can be used only in the stage model.<br>**Since**: 26.0.0|

## ScaleMode<sup>9+</sup>

Enumerates image scaling modes.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name           |   Value  | Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | Center cropping mode. The image is scaled proportionally to cover the entire target area (short side aligned), and then the excess area is cropped from the center.|
| FIT_TARGET_SIZE | 0      | Fit target size mode. The image is scaled proportionally to fit entirely within the target area (long side aligned). Any remaining space is filled with black or transparency.|

## PropertyKey<sup>7+</sup>

Enumerates the Exchangeable image file format (Exif) image information.



- The key in the format example is **image.PropertyKey.*XXX*** (where *XXX* is the name of an enumeration, for example, **NEW_SUBFILE_TYPE**).
- The format example is used only to show how to modify values and read results. For details about how to use them, see [modifyImageProperty](arkts-apis-image-ImageSource.md#modifyimageproperty11) (to modify a single Exif field), [modifyImageProperties](arkts-apis-image-ImageSource.md#modifyimageproperties12) (to modify multiple Exif fields), [getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11) (to read a single Exif field), and [getImageProperties](arkts-apis-image-ImageSource.md#getimageproperties12) (to read multiple Exif fields).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name              |   Value                   |   Description                   |   Format Example              |
| ----------------- | ----------------------- | ----------------------- | ----------------------- |
| NEW_SUBFILE_TYPE<sup>12+</sup>           | "NewSubfileType"            | In the Exif, the **NewSubfileType** field is used to identify the data type of a subfile, for example, full-resolution image, thumbnail, or part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Primary image');`<br>**Example of read result**: "0"|
| SUBFILE_TYPE<sup>12+</sup>               | "SubfileType"               | Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Full-resolution image data');`<br>**Example of read result**: "1"|
| IMAGE_WIDTH                               | "ImageWidth"                | Image width. The unit is px.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'4096');`<br>**Example of read result**: "4096"|
| IMAGE_LENGTH                              | "ImageLength"               | Image length. The unit is px.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3072');`<br>**Example of read result**: "3072"|
| BITS_PER_SAMPLE                           | "BitsPerSample"             | Number of bits per sample. For example, for RGB, which has three components, the format is 8,8,8.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use three non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'8 8 8');`<br>or `imageSource.modifyImageProperty(key,'8,8,8');`<br>**Example of read result**: "8,8,8"|
| COMPRESSION<sup>12+</sup>                | "Compression"               | Compression scheme used on the image data.<br> 1: "Uncompressed"<br> 2: "CCITT RLE"<br> 3: "T4/Group 3 Fax"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Uncompressed');`<br>**Example of read result**: "Uncompressed"|
| PHOTOMETRIC_INTERPRETATION<sup>12+</sup> | "PhotometricInterpretation" | Color space of the image data, for example, RGB or YCbCr.<br> 0: "Reversed mono"<br> 1: "Normal mono"<br> 2: "RGB"<br> 3: "Palette"<br> 5: "CMYK"<br> 6: "YCbCr"<br> 8: "CieLAB"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Normal mono');`<br>**Example of read result**: "Normal mono"|
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"          | Image description.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Image description info');`<br>**Example of read result**: "Image description info"|
| MAKE<sup>10+</sup>                        | "Make"                      | Manufacturer.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Make');`<br>**Example of read result**: "Make"|
| MODEL<sup>10+</sup>                       | "Model"                     | Device model.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Model');`<br>**Example of read result**: "Model"|
| STRIP_OFFSETS<sup>12+</sup>              | "StripOffsets"              | Byte offset of each strip.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'100');`<br>**Example of read result**: "100"|
| ORIENTATION                               | "Orientation"               | Image orientation.<br> 1: "Top-left" (Image not rotated)<br> 2: "Top-right" (Image flipped horizontally)<br> 3: "Bottom-right" (Image rotated by 180°)<br>4: "Bottom-left" (Image flipped vertically)<br> 5: "Left-top" (Image flipped horizontally and then rotated clockwise by 270°)<br> 6: "Right-top" (Image rotated clockwise by 90°)<br> 7: "Right-bottom" (Image flipped vertically and then rotated clockwise by 90°)<br>8: "Left-bottom" (Image rotated clockwise by 270°)<br> If an undefined value *x* is read, **Unknown Value x** is returned. The value of the property obtained is returned as a string. When modifying the property, you can specify the property either in the form of a number or a string.<br> For details about the image rotation angle, see [Obtaining the Rotation Angle of an Image](../../media/image/image-faqs/image-rotate-faq.md).<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Top-left');`<br>**Example of read result**: "Top-left"|
| SAMPLES_PER_PIXEL<sup>12+</sup>          | "SamplesPerPixel"           | Number of components per pixel. The value is **3** for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3');`<br>**Example of read result**: "3"|
| ROWS_PER_STRIP<sup>12+</sup>             | "RowsPerStrip"              | Number of rows per strip.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'10');`<br>**Example of read result**: "10"|
| STRIP_BYTE_COUNTS<sup>12+</sup>          | "StripByteCounts"           | Number of bytes in each strip after compression.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1024');`<br>**Example of read result**: "1024"|
| X_RESOLUTION<sup>12+</sup>               | "XResolution"               | Number of pixels per ResolutionUnit in the image width (X) direction.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'72');`<br>**Example of read result**: "72"|
| Y_RESOLUTION<sup>12+</sup>               | "YResolution"               | Number of pixels per ResolutionUnit in the image height (Y) direction.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'72');`<br>**Example of read result**: "72"|
| PLANAR_CONFIGURATION<sup>12+</sup>       | "PlanarConfiguration"       | Storage format of components of each pixel, which can be chunky or planar.<br>1: "Chunky format"<br>2: "Planar format"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Chunky format');`<br>**Example of read result**: "Chunky format"|
| RESOLUTION_UNIT<sup>12+</sup>            | "ResolutionUnit"            | Unit of measurement for XResolution and YResolution, in inches or centimeters.<br>2: "Inch"<br>3: "Centimeter"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2');`<br>or `imageSource.modifyImageProperty(key,'Inch');`<br>**Example of read result**: "Inch"|
| TRANSFER_FUNCTION<sup>12+</sup>          | "TransferFunction"          | Transfer function for the image, which is usually used for color correction.<br>**Read/Write capability**: readable and writable.<br>| This field is in a special format. Although it can be read and written, it is not parsed in the current version.|
| SOFTWARE<sup>12+</sup>                   | "Software"                  | Name and version number of the software used to create the image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Software name and version');`<br>**Example of read result**: "Software name and version"|
| DATE_TIME<sup>10+</sup>                   | "DateTime"                  | Date and time of image creation.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use either YYYY:MM:DD or YYYY:MM:DD HH:MM:SS.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br>or `imageSource.modifyImageProperty(key,'2024:07:07');`<br>**Example of read result**: "2024:07:07 13:45:59" or "2024:07:07"|
| ARTIST<sup>12+</sup>                     | "Artist"                    | Person who created the image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'User name');`<br>**Example of read result**: "User name"|
| WHITE_POINT<sup>12+</sup>                | "WhitePoint"                | Chromaticity coordinates of the white point, the reference for "white", in the color space of the image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use two non-negative rational numbers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1,2');`<br>or `imageSource.modifyImageProperty(key,'1 2');`<br>**Example of read result**: "1,2"|
| PRIMARY_CHROMATICITIES<sup>12+</sup>     | "PrimaryChromaticities"     | Chromaticities of the primaries of the image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'2/1');`<br>**Example of read result**: "0.5"|
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode"                 | Photographing mode.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: "1"|
| JPEG_INTERCHANGE_FORMAT<sup>12+</sup>    | "JPEGInterchangeFormat"     | Offset of the SOI marker of a JPEG interchange format bitstream.<br>**Read/Write capability**: read-only<br>| **Example of read result**: "1024"|
| JPEG_INTERCHANGE_FORMAT_LENGTH<sup>12+</sup> | "JPEGInterchangeFormatLength" | Number of bytes of the JPEG stream.<br>**Read/Write capability**: read-only<br>| **Example of read result**: "1024"|
| YCBCR_COEFFICIENTS<sup>12+</sup>         | "YCbCrCoefficients"         | Coefficients for the conversion matrix that transforms image data from RGB to YCbCr.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use three non-negative rational numbers, with a total sum of 1, as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0.299, 0.587, 0.114');`<br>**Example of read result**: "0.299, 0.587, 0.114"|
| YCBCR_SUB_SAMPLING<sup>12+</sup>         | "YCbCrSubSampling"          | Subsampling factors used for the chrominance components of a YCbCr image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use two non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2,2');`<br>or `imageSource.modifyImageProperty(key,'2 2');`<br>**Example of read result**: "2,2"|
| YCBCR_POSITIONING<sup>12+</sup>          | "YCbCrPositioning"          | Positioning of subsampled chrominance components relative to luminance samples.<br>1: "Centered" (Cb/Cr chrominance samples are center-aligned with luma pixels, which is a common practice.)<br>2: "Co-sited" (Cb/Cr chrominance samples are top-left aligned with Y samples.)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Centered');`<br>**Example of read result**: "Centered"|
| REFERENCE_BLACK_WHITE<sup>12+</sup>      | "ReferenceBlackWhite"       | Reference values for black and white points.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: "1,255, 0,255, 0,255"|
| COPYRIGHT<sup>12+</sup>                  | "Copyright"                 | Copyright notice of the image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'desc');`<br>**Example of read result**: "desc (Photographer) - [None] (Editor)"|
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"              | Exposure time. The unit is seconds.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'1/2');`<br>**Example of read result**: "1/33 sec."|
| F_NUMBER<sup>9+</sup>                     | "FNumber"                   | F number, for example, f/1.8.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'1/2');`<br>**Example of read result**: "f/1.0"|
| EXPOSURE_PROGRAM<sup>12+</sup>           | "ExposureProgram"           | Class of the program used by the camera to set exposure when the image was captured.<br>0: "Not defined"<br>1: "Manual"<br>2: "Normal program"<br>3: "Aperture priority"<br>4: "Shutter priority"<br>5: "Creative program (biased toward depth of field)"<br>6: "Creative program (biased toward fast shutter speed)"<br>7: "Portrait mode (for closeup photos with the background out of focus)"<br>8: "Landscape mode (for landscape photos with the background in focus)"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Not defined');`<br>**Example of read result**: "Not defined"|
| SPECTRAL_SENSITIVITY<sup>12+</sup>       | "SpectralSensitivity"       | Spectral sensitivity of each channel of the camera.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'SpectralSensitivity');`<br>**Example of read result**: "SpectralSensitivity"|
| GPS_VERSION_ID<sup>12+</sup>             | "GPSVersionID"              | GPS information version.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use four non-negative integers, separated by decimal points (.), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2.3.0.0');`<br>**Example of read result**: "2.3.0.0"|
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"            | Latitude reference (Northern or Southern Hemisphere) of the image capture location.<br>78: "North"<br>83: "South"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'78');`<br>or `imageSource.modifyImageProperty(key,'North');`<br>**Example of read result**: "N" or "78"|
| GPS_LATITUDE                              | "GPSLatitude"               | Image latitude. The value must be in the format of degree,minute,second, for example, **39,54,7.542**.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use three non-negative rational number strings, separated by commas (,).<br>**Example of modification**: `imageSource.modifyImageProperty(key,'39,54,7.542');`<br>**Example of read result**: "39,54,7.542"|
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"           | Longitude reference (Eastern or Western Hemisphere) of the image capture location.<br>69: "East"<br>87: "West"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'69');`<br>or `imageSource.modifyImageProperty(key,'East');`<br>**Example of read result**: "69" or "E"|
| GPS_LONGITUDE                             | "GPSLongitude"              | Image longitude. The value must be in the format of degree,minute,second, for example, **116,19,42.16**.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use three non-negative rational number strings, separated by commas (,).<br>**Example of modification**: `imageSource.modifyImageProperty(key,'116,19,42.16');`<br>**Example of read result**: "116,19,42.16"|
| GPS_ALTITUDE_REF<sup>12+</sup>           | "GPSAltitudeRef"            | Reference altitude for GPS altitude.<br>0: "Sea level" (Above sea level)<br>1: "Sea level reference" (Below sea level)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Sea level');`<br>**Example of read result**: "Sea level"|
| GPS_ALTITUDE<sup>12+</sup>               | "GPSAltitude"               | Altitude based on the reference in GPSAltitudeRef.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'123.45');`<br>**Example of read result**: "123.45"|
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"              | GPS timestamp.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use the format *HH:mm:ss.ddd*.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'12:30:30.123');`<br>**Example of read result**: "12:30:30.123"|
| GPS_SATELLITES<sup>12+</sup>             | "GPSSatellites"             | GPS satellites used for measurement.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'GPS Satellites');`<br>**Example of read result**: "GPSSatellites"|
| GPS_STATUS<sup>12+</sup>                 | "GPSStatus"                 | Status of the GPS receiver when the image was recorded.<br>  'A': "Measurement in progress" (GPS is working, satellite signals are locked, and location data is trustworthy.)<br>'V': "Measurement interrupted" (GPS is not working, positioning is unavailable currently, and location data may be missing or incorrect.)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use letters or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'A');`<br>or `imageSource.modifyImageProperty(key,'Measurement in progress');`<br>**Example of read result**: "A"|
| GPS_MEASURE_MODE<sup>12+</sup>           | "GPSMeasureMode"            | GPS measurement pmode. Whether the 2D (planar) or 3D (with height) measurement mode is used for GPS positioning.<br>2: "2-dimensional measurement" (Latitude+longitude)<br>3: "3-dimensional measurement" (Latitude + longitude + altitude)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2');`<br>or `imageSource.modifyImageProperty(key,'2-dimensional measurement');`<br>**Example of read result**: "2"|
| GPS_DOP<sup>12+</sup>                    | "GPSDOP"                    | GPS Dilution of Precision (DOP), which reflects the precision of GPS measurements taken when the photo was captured.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1.5');`<br>**Example of read result**: "1.5"|
| GPS_SPEED_REF<sup>12+</sup>              | "GPSSpeedRef"               | Unit used to express the movement speed of the GPS receiver.<br>'K': "km/h"<br>'M': "mph"<br>'N': "knots"<br>**Read/Write capability**: readable and writable.| **How to modify the parameter**: Use letters or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'K');`<br>or `imageSource.modifyImageProperty(key,'km/h');`<br>**Example of read result**: "K"|
| GPS_SPEED<sup>12+</sup>                  | "GPSSpeed"                  | Movement speed of the GPS receiver.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'123');`<br>or `imageSource.modifyImageProperty(key,'123.45');`<br>**Example of read result**: "123.45"|
| GPS_TRACK_REF<sup>12+</sup>              | "GPSTrackRef"               | Which type of "North" is used as the reference for the direction angle.<br> 'T': "True direction" (True north: direction to the geographic North Pole, suitable for mapping and navigation.)<br>'M': "Magnetic direction" (Magnetic north: Influenced by the Earth's magnetic field, the magnetic declination varies by region and over time.)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use letters or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'T');`<br>or `imageSource.modifyImageProperty(key,'True direction');`<br>**Example of read result**: "T"|
| GPS_TRACK<sup>12+</sup>                  | "GPSTrack"                  | Movement direction of the GPS receiver. Moving direction (travel direction) of the camera during photo capture, in degrees.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'180');`<br>**Example of read result**: "180"|
| GPS_IMG_DIRECTION_REF<sup>12+</sup>      | "GPSImgDirectionRef"        | Reference of the direction of the image when it was captured.<br> 'T': "True direction" (True north: direction to the geographic North Pole, suitable for mapping and navigation.)<br>'M': "Magnetic direction" (Magnetic north: Influenced by the Earth's magnetic field, the magnetic declination varies by region and over time.)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use letters or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'T');`<br>or `imageSource.modifyImageProperty(key,'True direction');`<br>**Example of read result**: "T"|
| GPS_IMG_DIRECTION<sup>12+</sup>          | "GPSImgDirection"           | Direction of the image when it was captured.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'120');`<br>**Example of read result**: "120"|
| GPS_MAP_DATUM<sup>12+</sup>              | "GPSMapDatum"               | Geodetic survey data used by the GPS receiver.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'GPS Map Datum');`<br>**Example of read result**: "GPS Map Datum"|
| GPS_DEST_LATITUDE_REF<sup>12+</sup>      | "GPSDestLatitudeRef"        | Whether the latitude of the destination point is north or south latitude.<br>78: "North"<br>83: "South"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'78');`<br>or `imageSource.modifyImageProperty(key,'North');`<br>**Example of read result**: "78"|
| GPS_DEST_LATITUDE<sup>12+</sup>          | "GPSDestLatitude"           | Latitude of the destination point.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use three non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'39,54,7');`<br>or `imageSource.modifyImageProperty(key,'39 54 7');`<br>**Example of read result**: "39,54,7"|
| GPS_DEST_LONGITUDE_REF<sup>12+</sup>     | "GPSDestLongitudeRef"       | Whether the longitude of the destination point is east or west longitude.<br>69: "East"<br>87: "West"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'69');`<br>or `imageSource.modifyImageProperty(key,'East');`<br>**Example of read result**: "69"|
| GPS_DEST_LONGITUDE<sup>12+</sup>         | "GPSDestLongitude"          | Longitude of the destination point.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use three non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'116,19,42');`<br>or `imageSource.modifyImageProperty(key,'116 19 42');`<br>**Example of read result**: "116,19,42"|
| GPS_DEST_BEARING_REF<sup>12+</sup>       | "GPSDestBearingRef"         | Reference of the bearing to the destination point.<br> 'T': "True direction" (True north: direction to the geographic North Pole, suitable for mapping and navigation.)<br>'M': "Magnetic direction" (Magnetic north: Influenced by the Earth's magnetic field, the magnetic declination varies by region and over time.)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use letters or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'T');`<br>or `imageSource.modifyImageProperty(key,'True direction');`<br>**Example of read result**: "T"|
| GPS_DEST_BEARING<sup>12+</sup>           | "GPSDestBearing"            | Bearing to the destination point.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'120');`<br>**Example of read result**: "120"|
| GPS_DEST_DISTANCE_REF<sup>12+</sup>      | "GPSDestDistanceRef"        | Unit used to express the distance to the destination point.<br>'K': "km"<br>'M': "miles"<br>'N': "nautical miles"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use letters or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'K');`<br>or `imageSource.modifyImageProperty(key,'km');`<br>**Example of read result**: "K"|
| GPS_DEST_DISTANCE<sup>12+</sup>          | "GPSDestDistance"           | Distance to the destination point.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'100');`<br>**Example of read result**: "100"|
| GPS_PROCESSING_METHOD<sup>12+</sup>      | "GPSProcessingMethod" |String that records the name of the method used for positioning.<br>**Read/Write capability**: readable and writable.<br>|**How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'GPS Processing Method');`<br>**Example of read result**: "GPS Processing Method"|
| GPS_AREA_INFORMATION<sup>12+</sup>       | "GPSAreaInformation"   | String that records the name of the GPS area.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'GPS Area Information');`<br>**Example of read result**: "GPS Area Information"|
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"         | GPS date stamp.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use the format "YY:MM:DD".<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2020:07:07');`<br>**Example of read result**: "2020:07:07"|
| GPS_DIFFERENTIAL<sup>12+</sup>           | "GPSDifferential"      | Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy.<br>  0: "Without correction" (No differential correction)<br> 1:"Correction applied" (Differential correction applied)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Without correction');`<br>**Example of read result**: "0"|
| GPS_H_POSITIONING_ERROR<sup>12+</sup>    | "GPSHPositioningError" | Horizontal positioning error. The unit is meters.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'100');`<br>**Example of read result**: "100"|
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"           | ISO sensitivity or ISO speed, for example, 400.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3200');`<br>**Example of read result**: "3200" |
| PHOTOGRAPHIC_SENSITIVITY<sup>12+</sup>   | "PhotographicSensitivity" | ISO sensitivity (ISO speed) used when the image was captured. It is the recommended field in Exif 2.3 and later. The earlier field, ISOSpeedRatings (Tag 0x8827), has the same data type and meaning. However, if both fields are present, the **PhotographicSensitivity** value should be used.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3200');`<br>**Example of read result**: "3200" |
| OECF<sup>12+</sup>                       | "OECF"                      | Opto-Electric Conversion Function (OECF) specified in ISO 14524.<br>**Read/Write capability**: readable and writable.<br>| This field is in a special format. Although it can be read and written, it is not parsed in the current version.|
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"      | Sensitivity type.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Standard output sensitivity (SOS)');`<br>**Example of read result**: "Standard output sensitivity (SOS)"|
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity" | Standard output sensitivity.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'400');`<br>**Example of read result**: "400"|
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex" | Recommended exposure index.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3200');`<br>**Example of read result**: "3200" |
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"           | ISO speed.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3200');`<br>**Example of read result**: "3200" |
| ISO_SPEED_LATITUDE_YYY<sup>12+</sup>     | "ISOSpeedLatitudeyyy"  | ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3200');`<br>**Example of read result**: "3200" |
| ISO_SPEED_LATITUDE_ZZZ<sup>12+</sup>     | "ISOSpeedLatitudezzz"  | ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3200');`<br>**Example of read result**: "3200" |
| EXIF_VERSION<sup>12+</sup>               | "ExifVersion"               | Version of the supported Exif standard.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string, separated by decimal points (.).<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2.3');`<br>**Example of read result**: "Exif Version 2.3"|
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"          | Time when the original image data was generated, for example, 2022:09:06 15:48:00.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use the format "YY:MM:DD HH:mm:ss" or "YY:MM:DD".<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br>or `imageSource.modifyImageProperty(key,'2024:07:07');`<br>**Example of read result**: "2024:07:07" or "2024:07:07 13:45:59"|
| DATE_TIME_DIGITIZED<sup>12+</sup>        | "DateTimeDigitized"         | Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:mm:ss.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use the format "YY:MM:DD HH:mm:ss" or "YY:MM:DD".<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br>or `imageSource.modifyImageProperty(key,'2024:07:07');`<br>**Example of read result**: "2024:07:07" or "2024:07:07 13:45:59"|
| OFFSET_TIME<sup>12+</sup>                | "OffsetTime"          | Time with an offset from UTC when the image was captured.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use the format "YY:MM:DD HH:mm:ss" or "YY:MM:DD".<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2024:07:07 13:45:59');`<br>or `imageSource.modifyImageProperty(key,'2024:07:07');`<br>**Example of read result**: "2024:07:07" or "2024:07:07 13:45:59"|
| OFFSET_TIME_ORIGINAL<sup>12+</sup>       | "OffsetTimeOriginal"  | Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Offset Time Original');`<br>**Example of read result**: "Offset Time Original"|
| OFFSET_TIME_DIGITIZED<sup>12+</sup>      | "OffsetTimeDigitized" | Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Offset Time Digitized');`<br>**Example of read result**: "Offset Time Digitized"|
| COMPONENTS_CONFIGURATION<sup>12+</sup>   | "ComponentsConfiguration"   | Specific information about compressed data.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: "Y Cb Cr -"<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Y Cb Cr -');`<br>**Example of read result**: "Y Cb Cr -"|
| COMPRESSED_BITS_PER_PIXEL<sup>12+</sup>  | "CompressedBitsPerPixel"    | Image compression mode. The unit is bits per pixel (bit/px).<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0.95');`<br>**Example of read result**: "0.95"|
| SHUTTER_SPEED<sup>12+</sup>              | "ShutterSpeedValue"         | Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: "1.00 EV (1/2 sec.)"|
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"             | Lens aperture. An example in the correct format is 4/1.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'5.6');`<br>**Example of read result**: "5.60 EV (f/7.0)"|
| BRIGHTNESS_VALUE<sup>12+</sup>           | "BrightnessValue"           | Value of brightness, expressed in APEX values.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2');`<br>**Example of read result**: "2.00 EV (13.71 cd/m^2)"|
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"         | Exposure bias.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: 1.00 EV|
| MAX_APERTURE_VALUE<sup>12+</sup>         | "MaxApertureValue"          | Smallest F number of the lens.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: "1.00 EV (f/1.4)"|
| SUBJECT_DISTANCE<sup>12+</sup>           | "SubjectDistance"           | Distance to the subject, in meters.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'100');`<br>**Example of read result**: "100.0 m"|
| METERING_MODE<sup>10+</sup>               | "MeteringMode"              | Metering mode.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Average');`<br>**Example of read result**: "Average"|
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"               | Light source. An example value is **Fluorescent**.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Daylight');`<br>**Example of read result**: "Daylight"|
| FLASH<sup>10+</sup>                      | "Flash"                     | Flash status.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0x00');`<br>or `imageSource.modifyImageProperty(key,'Flash did not fire');`<br>**Example of read result**: "Flash did not fire"|
| FOCAL_LENGTH<sup>10+</sup>               | "FocalLength"               | Focal length of the lens. The unit is millimeters.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'50');`<br>or `imageSource.modifyImageProperty(key,'50/1');`<br>**Example of read result**: "50.0 mm"|
| SUBJECT_AREA<sup>12+</sup>               | "SubjectArea"          | Location and area of the main subject in the entire scene.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use two non-negative rational numbers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'50 50');`<br>or `imageSource.modifyImageProperty(key,'50,50');`<br>**Example of read result**: "(x,y) = (50,50)"|
| MAKER_NOTE<sup>12+</sup>                 | "MakerNote"                 | Marker used by Exif/DCF manufacturers to record any required information.<br>This field is read-only in API versions 12 to 19 and is readable and writable in API version 20 and later.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Maker Note');`<br>**Example of read result**: "Maker Note"|
| USER_COMMENT<sup>10+</sup>               | "UserComment"               | User comments.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'User Comment');`<br>**Example of read result**: "User Comment"|
| SUBSEC_TIME<sup>12+</sup>                | "SubsecTime"                | Tag used to record fractions of seconds for the **DateTime** tag.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'629000');`<br>**Example of read result**: "629000"|
| SUBSEC_TIME_ORIGINAL<sup>12+</sup>       | "SubsecTimeOriginal"        | Tag used to record fractions of seconds for the **DateTimeOriginal** tag.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'629000');`<br>**Example of read result**: "629000"|
| SUBSEC_TIME_DIGITIZED<sup>12+</sup>      | "SubsecTimeDigitized"       | Tag used to record fractions of seconds for the **DateTimeDigitized** tag.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'62900');`<br>**Example of read result**: "62900"|
| FLASHPIX_VERSION<sup>12+</sup>           | "FlashpixVersion"           | FlashPix format version supported by an FPXR file. It is used to enhance device compatibility.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use the version number format "1.0".<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1.0');`<br>**Example of read result**: "FlashPix Version 1.0"|
| COLOR_SPACE<sup>12+</sup>                | "ColorSpace"                | Color space information, which is usually recorded as a color space specifier.<br>1: "sRGB" (sRGB standard color space, which is commonly used as the default value)<br>2: "Adobe RGB" (Not formally defined in Exif, but commonly used in practice)<br>0xffff: "Uncalibrated" (Uncalibrated and color space unknown)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'sRGB');`<br>**Example of read result**: "sRGB"|
| PIXEL_X_DIMENSION<sup>10+</sup>          | "PixelXDimension"           | Pixel X dimension. The unit is px.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'4096');`<br>**Example of read result**: "4096"|
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"           | Pixel Y dimension. The unit is px.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'3072');`<br>**Example of read result**: "3072"|
| RELATED_SOUND_FILE<sup>12+</sup>         | "RelatedSoundFile"          | Name of an audio file related to the image data.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Related Sound File');`<br>**Example of read result**: "Related Sound File|
| FLASH_ENERGY<sup>12+</sup>               | "FlashEnergy"               | Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS).<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'5.0');`<br>or `imageSource.modifyImageProperty(key,'5/1');`<br>**Example of read result**: "5"|
| SPATIAL_FREQUENCY_RESPONSE<sup>12+</sup> | "SpatialFrequencyResponse"  | Spatial frequency table of the camera or input device.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Spatial Frequency Response');`<br>**Example of read result**: "Spatial Frequency Response"|
| FOCAL_PLANE_X_RESOLUTION<sup>12+</sup>   | "FocalPlaneXResolution"     | Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'500');`<br>or `imageSource.modifyImageProperty(key,'500.0');`<br>**Example of read result**: "500"|
| FOCAL_PLANE_Y_RESOLUTION<sup>12+</sup>   | "FocalPlaneYResolution"     | Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'500');`<br>or `imageSource.modifyImageProperty(key,'500.0');`<br>**Example of read result**: "500"|
| FOCAL_PLANE_RESOLUTION_UNIT<sup>12+</sup> | "FocalPlaneResolutionUnit"  | Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.<br>2: "Inch"<br>3: "Centimeter"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2');`<br>or `imageSource.modifyImageProperty(key,'Inch');`<br>**Example of read result**: "Inch"|
| SUBJECT_LOCATION<sup>12+</sup>           | "SubjectLocation"           | Location of the main subject relative to the left edge.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use two non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'123 456');`<br>or `imageSource.modifyImageProperty(key,'123,456');`<br>**Example of read result**: "123,456"|
| EXPOSURE_INDEX<sup>12+</sup>             | "ExposureIndex"             | Exposure index selected at the time the image is captured.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: "1"|
| SENSING_METHOD<sup>12+</sup>             | "SensingMethod"             | Type of the image sensor on the camera.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'2');`<br>or `imageSource.modifyImageProperty(key,'One-chip color area sensor');`<br>**Example of read result**: "One-chip color area sensor"|
| FILE_SOURCE<sup>12+</sup>                | "FileSource"                | Image source.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'DSC');`<br>**Example of read result**: "DSC"|
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                 | Type of the scene, for example, portrait, scenery, motion, and night.<br>1: "Directly photographed" (Image captured by the image sensor)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Directly photographed');`<br>**Example of read result**: "Directly photographed" |
| CFA_PATTERN<sup>12+</sup>                | "CFAPattern"                | Color Filter Array (CFA) geometric pattern of the image sensor.<br>**Read/Write capability**: readable and writable.<br>| This field is in a special format. Although it can be read and written, it is not parsed in the current version.|
| CUSTOM_RENDERED<sup>12+</sup>            | "CustomRendered"       | Special processing on image data.<br>0: "Normal process" (Normal processing without any custom rendering)<br>1: "Custom process" (Custom processing such as artistic effect, beauty, and HDR)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Custom process');`<br>**Example of read result**: "Custom process"|
| EXPOSURE_MODE<sup>12+</sup>              | "ExposureMode"         | Exposure mode set when the image was captured.<br>0: "Auto exposure"<br>1: "Manual exposure"<br>2: "Auto bracket"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Auto exposure');`<br>**Example of read result**: "Auto exposure"|
| WHITE_BALANCE<sup>10+</sup>              | "WhiteBalance"         | White balance.<br>0: "Auto white balance"<br>1: "Manual white balance"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Auto white balance');`<br>**Example of read result**: "Auto white balance"|
| DIGITAL_ZOOM_RATIO<sup>12+</sup>         | "DigitalZoomRatio"     | Digital zoom ratio when the image was captured.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1/2');`<br>**Example of read result**: "0.5"|
| FOCAL_LENGTH_IN_35_MM_FILM<sup>10+</sup> | "FocalLengthIn35mmFilm" | 35 mm equivalent focal length. The unit is millimeters.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative integer string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'50');`<br>**Example of read result**: "50"|
| SCENE_CAPTURE_TYPE<sup>12+</sup>         | "SceneCaptureType"     | Type of the scene that was captured.<br>0: "Standard"<br>1: "Landscape"<br>2: "Portrait"<br>3: "Night scene"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Standard');`<br>**Example of read result**: "Standard"|
| GAIN_CONTROL<sup>12+</sup>               | "GainControl"          | Degree of overall image gain adjustment.<br>0: "Normal" (No gain control)<br>1: "Low gain up"<br>2: "High gain up"<br>3: "Low gain down"<br>4: "High gain down"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Normal');`<br>**Example of read result**: "Normal"|
| CONTRAST<sup>12+</sup>                   | "Contrast"             | Direction of contrast processing used by the camera.<br>0: "Normal" (Normal contrast)<br>1: "Soft" (Soft contrast)<br>2: "Hard" (Hard contrast)<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Normal');`<br>**Example of read result**: "Normal"|
| SATURATION<sup>12+</sup>                 | "Saturation"           | Direction of saturation processing used by the camera.<br>0:"Normal"<br>1: "Low saturation"<br>2: "High saturation"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Normal');`<br>**Example of read result**: "Normal"|
| SHARPNESS<sup>12+</sup>                  | "Sharpness"            | Direction of sharpness processing used by the camera.<br>0:"Normal"<br>1: "Soft"<br>2: "Hard"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'0');`<br>or `imageSource.modifyImageProperty(key,'Normal');`<br>**Example of read result**: "Normal"|
| DEVICE_SETTING_DESCRIPTION<sup>12+</sup> | "DeviceSettingDescription" | Information about the photographing conditions of a specific camera model.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of Modification**: `imageSource.modifyImageProperty(key,'Device Setting Description');`<br>**Example of read result**: "Device Setting Description"|
| SUBJECT_DISTANCE_RANGE<sup>12+</sup>     | "SubjectDistanceRange" | Distance to the subject.<br>0: "Unknown"<br>1: "Macro"<br>2: "Close view"<br>3: "Distant view"<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use numbers or strings.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'Macro');`<br>**Example of read result**: "Macro"|
| IMAGE_UNIQUE_ID<sup>12+</sup>            | "ImageUniqueID"        | Unique identifier assigned to each image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Image Unique ID');`<br>**Example of read result**: "Image Unique ID"|
| CAMERA_OWNER_NAME<sup>12+</sup>          | "CameraOwnerName"      | Name of the camera owner.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Camera Owner Name');`<br>**Example of read result**: "Camera Owner Name"|
| BODY_SERIAL_NUMBER<sup>12+</sup>         | "BodySerialNumber"     | Serial number of the camera body.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Body Serial Number');`<br>**Example of read result**: "Body Serial Number"|
| LENS_SPECIFICATION<sup>12+</sup>         | "LensSpecification"    | Specifications of the lens.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use four non-negative rational number strings, separated by spaces or commas (,).<br>**Example of modification**: `imageSource.modifyImageProperty(key,'12 12 12 12');` or `imageSource.modifyImageProperty(key,'12,12,12,12');`<br>**Example of read result**: "12,12,12,12"|
| LENS_MAKE<sup>12+</sup>                  | "LensMake"             | Manufacturer of the lens.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Lens Make');`<br>**Example of read result**: "Lens Make"|
| LENS_MODEL<sup>12+</sup>                 | "LensModel"            | Model of the lens.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Lens Model');`<br>**Example of read result**: "Lens Model"|
| LENS_SERIAL_NUMBER<sup>12+</sup>         | "LensSerialNumber"     | Serial number of the lens.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Lens Serial Number');`<br>**Example of read result**: "Lens Serial Number"|
| COMPOSITE_IMAGE<sup>12+</sup>            | "CompositeImage"      | Whether the image is a composite image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1');`<br>or `imageSource.modifyImageProperty(key,'NonComposite');`<br>**Example of read result**: "1"|
| SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE<sup>12+</sup>   | "SourceImageNumberOfCompositeImage" | Number of source images of the composite image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use two non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'1 5');`<br>or `imageSource.modifyImageProperty(key,'1,5');`<br>**Example of read result**: "1,5" |
| SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE<sup>12+</sup> | "SourceExposureTimesOfCompositeImage" | Exposure time of source images of the composite image.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'Source Exposure Times Of CompositeImage');`<br>**Example of read result**: "Source Exposure Times Of CompositeImage"|
| GAMMA<sup>12+</sup>                      | "Gamma"                | Gamma value.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use a non-negative rational number as a string.<br>**Example of modification**<br>`imageSource.modifyImageProperty(key,'1');`<br>**Example of read result**: "1"|
| DNG_VERSION<sup>12+</sup>                | "DNGVersion"                | DNG version. It encodes the DNG 4-tier version number.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use four non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**<br>`imageSource.modifyImageProperty(key,'1 1 1 1');`<br>or `imageSource.modifyImageProperty(key,'1,1,1,1');`<br>**Example of read result**: "1,1,1,1"|
| DEFAULT_CROP_SIZE<sup>12+</sup>          | "DefaultCropSize"           | Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image. The unit is px.<br>**Read/Write capability**: readable and writable.<br>| **How to modify the parameter**: Use two non-negative integers, separated by spaces or commas (,), as a string.<br>**Example of modification**: `imageSource.modifyImageProperty(key,'400 400');`<br>or `imageSource.modifyImageProperty(key,'400,400');`<br>**Example of read result**: "400,400" |
| GIF_LOOP_COUNT<sup>12+</sup>             | "GIFLoopCount"              | Number of GIF loops. The value **0** indicates infinite looping, and another value indicates the actual number of loops.<br>**Read/Write capability**: read-only<br>| _ |
| IS_XMAGE_SUPPORTED<sup>12+</sup> | "HwMnoteIsXmageSupported" | Whether XMAGE is supported.<br>**Read/Write capability**: readable and writable.<br>| _ |
| XMAGE_MODE<sup>12+</sup> | "HwMnoteXmageMode" | XMAGE watermark mode.<br>**Read/Write capability**: readable and writable.<br>| _ |
| XMAGE_LEFT<sup>12+</sup> | "HwMnoteXmageLeft" | X1 coordinate of the watermark region.<br>**Read/Write capability**: readable and writable.<br>| _ |
| XMAGE_TOP<sup>12+</sup> | "HwMnoteXmageTop" | Y1 coordinate of the watermark region.<br>**Read/Write capability**: readable and writable.<br>| _ |
| XMAGE_RIGHT<sup>12+</sup> | "HwMnoteXmageRight" | X2 coordinate of the watermark region.<br>**Read/Write capability**: readable and writable.<br>| _ |
| XMAGE_BOTTOM<sup>12+</sup> | "HwMnoteXmageBottom" | Y2 coordinate of the watermark region.<br>**Read/Write capability**: readable and writable.<br>| _ |
| CLOUD_ENHANCEMENT_MODE<sup>12+</sup> | "HwMnoteCloudEnhancementMode" | Cloud enhancement mode.<br>**Read/Write capability**: readable and writable.<br>| _ |
| WIND_SNAPSHOT_MODE<sup>12+</sup> | "HwMnoteWindSnapshotMode" | Motion snapshot mode.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_POINTER<sup>12+</sup> | "HwMnoteScenePointer" | Pointer to the scene.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_VERSION<sup>12+</sup> | "HwMnoteSceneVersion" | Scene algorithm version.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_FOOD_CONF<sup>11+</sup> | "HwMnoteSceneFoodConf" | Photographing scene: food.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_STAGE_CONF<sup>11+</sup> | "HwMnoteSceneStageConf" | Photographing scene: stage.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_BLUE_SKY_CONF<sup>11+</sup> | "HwMnoteSceneBlueSkyConf" | Photographing scene: blue sky.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_GREEN_PLANT_CONF<sup>11+</sup> | "HwMnoteSceneGreenPlantConf" | Photographing scene: green plant.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_BEACH_CONF<sup>11+</sup> | "HwMnoteSceneBeachConf" | Photographing scene: beach.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_SNOW_CONF<sup>11+</sup> | "HwMnoteSceneSnowConf" | Photographing scene: snow.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_SUNSET_CONF<sup>11+</sup> | "HwMnoteSceneSunsetConf" | Photographing scene: sunset.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_FLOWERS_CONF<sup>11+</sup> | "HwMnoteSceneFlowersConf" | Photographing scene: flowers.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_NIGHT_CONF<sup>11+</sup> | "HwMnoteSceneNightConf" | Photographing scene: night.<br>**Read/Write capability**: read-only<br>| _ |
| SCENE_TEXT_CONF<sup>11+</sup> | "HwMnoteSceneTextConf" | Photographing scene: text.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_POINTER<sup>12+</sup> | "HwMnoteFacePointer" | Face pointer.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_VERSION<sup>12+</sup> | "HwMnoteFaceVersion" | Facial recognition algorithm version.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_COUNT<sup>11+</sup> | "HwMnoteFaceCount" | Number of faces.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_CONF<sup>12+</sup> | "HwMnoteFaceConf" | Face confidence.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_SMILE_SCORE<sup>12+</sup> | "HwMnoteFaceSmileScore" | Smile scores of faces (the number of faces is specified by **FaceCount**).<br>**Read/Write capability**: read-only<br>| _ |
| FACE_RECT<sup>12+</sup> | "HwMnoteFaceRect" | Face rectangle.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_LEYE_CENTER<sup>12+</sup> | "HwMnoteFaceLeyeCenter" | Left eye centered.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_REYE_CENTER<sup>12+</sup> | "HwMnoteFaceReyeCenter" | Right eye centered.<br>**Read/Write capability**: read-only<br>| _ |
| FACE_MOUTH_CENTER<sup>12+</sup> | "HwMnoteFaceMouthCenter" | Mouth centered.<br>**Read/Write capability**: read-only<br>| _ |
| CAPTURE_MODE<sup>10+</sup> | "HwMnoteCaptureMode" | Capture mode.<br>**Read/Write capability**: readable and writable.<br>| _ |
| BURST_NUMBER<sup>12+</sup> | "HwMnoteBurstNumber" | Number of burst shooting times.<br>**Read/Write capability**: read-only<br>| _ |
| FRONT_CAMERA<sup>12+</sup> | "HwMnoteFrontCamera" | Whether the front camera is used to take a selfie.<br>**Read/Write capability**: read-only<br>| _ |
| ROLL_ANGLE<sup>11+</sup> | "HwMnoteRollAngle" | Roll angle.<br>**Read/Write capability**: read-only<br>| _ |
| PITCH_ANGLE<sup>11+</sup> | "HwMnotePitchAngle" | Pitch angle.<br>**Read/Write capability**: read-only<br>| _ |
| PHYSICAL_APERTURE<sup>10+</sup> | "HwMnotePhysicalAperture" | Physical aperture. The unit is millimeters.<br>**Read/Write capability**: read-only<br>| _ |
| FOCUS_MODE<sup>11+</sup> | "HwMnoteFocusMode" | Focus mode.<br>**Read/Write capability**: read-only<br>| _ |

## FragmentMapPropertyKey<sup>13+</sup>

Enumerates the image information of a watermark crop image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value                   | Description                               |
| ------------- | --------------------- | ----------------------------------- |
| X_IN_ORIGINAL | "XInOriginal"         | X coordinate of the top-left corner of the fragment map in the original image.|
| Y_IN_ORIGINAL | "YInOriginal"         | Y coordinate of the top-left corner of the fragment map in the original image.|
| WIDTH         | "FragmentImageWidth"  | Width of the fragment map. The unit is px.                   |
| HEIGHT        | "FragmentImageHeight" | Height of the fragment map. The unit is px.                   |

## GifPropertyKey<sup>20+</sup>

Enumerates GIF image information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value               | Description                  |
| ----------------- | ----------------- | --------------------- |
| GIF_DELAY_TIME    | 'GifDelayTime'    | Frame delay of the GIF image after clamping. The clamp range is [100, 65535].<br>The unit is milliseconds.|
| GIF_DISPOSAL_TYPE | 'GifDisposalType' | Disposal type for each frame of the GIF image.<br>- **0**: Unspecified.<br>- **1**: Do not dispose.<br>- **2**: Restore to the background color.<br>- **3**: Restore to the previous frame.<br>The value is a positive integer.|
| GIF_HAS_GLOBAL_COLOR_MAP | 'GifHasGlobalColorMap' | Whether the GIF image contains a global color table.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| GIF_CANVAS_WIDTH | 'GifCanvasWidth' | Canvas width of the GIF image.<br>The unit is px.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| GIF_CANVAS_HEIGHT | 'GifCanvasHeight' | Canvas height of the GIF image.<br>The unit is px.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| GIF_LOOP_COUNT | 'GifLoopCount' | Number of GIF loops.<br>The value can be **0** or a positive integer. The value **0** indicates infinite looping, and another value indicates the actual number of loops.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| GIF_UNCLAMPED_DELAY_TIME | 'GifUnclampedDelayTime' | Frame delay of a GIF image without clamping.<br>The unit is milliseconds.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## HeifsPropertyKey<sup>23+</sup>

Enumerates HEIF sequence image information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value               | Description                  |
| ----------------- | ----------------- | --------------------- |
| HEIFS_DELAY_TIME    | 'HeifsDelayTime'    | Delay of each frame in an HEIF image sequence,<br>The unit is milliseconds.|
| HEIFS_UNCLAMPED_DELAY_TIME | 'HeifsUnclampedDelayTime' | Frame delay of a HEIF image sequence without clamping.<br>The unit is milliseconds.<br>**Since**: 26.0.0|
| HEIFS_CANVAS_HEIGHT | 'HeifsCanvasHeight' | Canvas height of a HEIF image sequence.<br>The unit is px.<br>**Since**: 26.0.0|
| HEIFS_CANVAS_WIDTH | 'HeifsCanvasWidth' | Canvas width of a HEIF sequence image.<br>The unit is px.<br>**Since**: 26.0.0|

## WebPPropertyKey<sup>24+</sup>

Enumerates WebP image information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value               | Description                  |
| ----------------- | ----------------- | --------------------- |
| CANVAS_WIDTH    | 'WebPCanvasWidth'    | Canvas width of a WebP image.<br>The unit is px.|
| CANVAS_HEIGHT    | 'WebPCanvasHeight'    | Canvas height of a WebP image.<br>The unit is px.|
| DELAY_TIME    | 'WebPDelayTime'    | Frame delay of a WebP image after clamping. The clamp range is [100, 65535].<br>The unit is milliseconds.|
| UNCLAMPED_DELAY_TIME    | 'WebPUnclampedDelayTime'    | Frame delay of a WebP image without clamping.<br>The unit is milliseconds.|
| LOOP_COUNT    | 'WebPLoopCount'    | Number of times the WebP image animation loops. If it is set to **0**, the number of animation loops is not limited.|

## DngPropertyKey<sup>24+</sup>

Enumerates DNG image information.

> **NOTE**
>
> - For details about the fields, see the DNG Specification 1.4.0.0.
> - For details about the return value type, see [DngMetadata](arkts-apis-image-i.md#dngmetadata24).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value               | Description                  |
| ----------------- | ----------------- | --------------------- |
| DNG_VERSION    | 'DNGVersion' | Version number of the DNG image.|
| DNG_BACKWARD_VERSION | 'DNGBackwardVersion' | Minimum backward-compatible version number of the DNG file.|
| UNIQUE_CAMERA_MODEL | 'UniqueCameraModel' | Unique model ID of the camera, which is used to distinguish different devices.|
| LOCALIZED_CAMERA_MODEL | 'LocalizedCameraModel' | Localized camera model name.|
| CFA_PLANE_COLOR | 'CFAPlaneColor' | Color channel definition for each CFA plane.|
| CFA_LAYOUT | 'CFALayout' | CFA layout type, such as RGGB and BGGR.|
| LINEARIZATION_TABLE | 'LinearizationTable' | Linearization lookup table, which is used to map raw sensor values to the linear light intensity.|
| BLACK_LEVEL_REPEAT_DIM | 'BlackLevelRepeatDim' | Black level repetition dimension.|
| BLACK_LEVEL | 'BlackLevel' | Black level under zero illumination, arranged in CFA plane order.|
| BLACK_LEVEL_DELTA_H | 'BlackLevelDeltaH' | Horizontal black level correction increment.|
| BLACK_LEVEL_DELTA_V | 'BlackLevelDeltaV' | Vertical black level correction increment.|
| WHITE_LEVEL | 'WhiteLevel' | White level, indicating the maximum valid output of the sensor.|
| DEFAULT_SCALE | 'DefaultScale' | Default scaling ratio.|
| DEFAULT_CROP_ORIGIN | 'DefaultCropOrigin' | Coordinates (x, y) of the upper left corner of the default crop area.|
| DEFAULT_CROP_SIZE | 'DefaultCropSize' | Width and height of the default crop area.|
| COLOR_MATRIX1 | 'ColorMatrix1' | Color transformation matrix under the first calibration illuminant.|
| COLOR_MATRIX2 | 'ColorMatrix2' | Color transformation matrix under the second calibration illuminant.|
| CAMERA_CALIBRATION1 | 'CameraCalibration1' | Camera transformation matrix under the first calibration illuminant.|
| CAMERA_CALIBRATION2 | 'CameraCalibration2' | Camera transformation matrix under the second calibration illuminant.|
| REDUCTION_MATRIX1 | 'ReductionMatrix1' | Dimension reduction matrix under the first calibration illuminant.|
| REDUCTION_MATRIX2 | 'ReductionMatrix2' | Dimension reduction matrix under the second calibration illuminant.|
| ANALOG_BALANCE | 'AnalogBalance' | Analog gain balance coefficient.|
| AS_SHOT_NEUTRAL | 'AsShotNeutral' | Neutral white point at capture.|
| AS_SHOT_WHITEXY | 'AsShotWhiteXY' | CIE x-y chromaticity coordinates of the white point at capture.|
| BASELINE_EXPOSURE | 'BaselineExposure' | Baseline exposure compensation value, in EV.|
| BASELINE_NOISE | 'BaselineNoise' | Baseline noise level.|
| BASELINE_SHARPNESS | 'BaselineSharpness' | Baseline sharpness gain.|
| BAYER_GREEN_SPLIT | 'BayerGreenSplit' | Separation degree of the two green channels in a Bayer image.|
| LINEAR_RESPONSE_LIMIT | 'LinearResponseLimit' | Upper limit of the linear response. The value range is [0.0, 1.0].|
| CAMERA_SERIAL_NUMBER | 'CameraSerialNumber' | Camera serial number.|
| LENS_INFO | 'LensInfo' | Lens information.|
| CHROMA_BLUR_RADIUS | 'ChromaBlurRadius' | Chrominance blur radius. The unit is px.|
| ANTI_ALIAS_STRENGTH | 'AntiAliasStrength' | Anti-aliasing filter strength.|
| SHADOW_SCALE | 'ShadowScale' | Shadow region scaling factor.|
| DNG_PRIVATE_DATA | 'DNGPrivateData' | Vendor-specific data block.|
| MAKER_NOTE_SAFETY | 'MakerNoteSafety' | Whether the EXIF MakerNote is secure and can be retained. The value **1** indicates yes, and the value **0** indicates no.|
| CALIBRATION_ILLUMINANT1 | 'CalibrationIlluminant1' | Type of the first calibration illuminant.|
| CALIBRATION_ILLUMINANT2 | 'CalibrationIlluminant2' | Type of the second calibration illuminant.|
| BEST_QUALITY_SCALE | 'BestQualityScale' | Scaling ratio for the optimal image quality.|
| RAW_DATA_UNIQUE_ID | 'RawDataUniqueID' | Unique ID of the raw image data.|
| ORIGINAL_RAW_FILE_NAME | 'OriginalRawFileName' | Original raw file name.|
| ORIGINAL_RAW_FILE_DATA | 'OriginalRawFileData' | Complete data of the original raw file.|
| ACTIVE_AREA | 'ActiveArea' | Valid image area.|
| MASKED_AREAS | 'MaskedAreas' | List of masked areas.|
| AS_SHOT_ICC_PROFILE | 'AsShotICCProfile' | ICC color profile used at capture.|
| AS_SHOT_PRE_PROFILE_MATRIX | 'AsShotPreProfileMatrix' | Pre-transformation matrix before the ICC color profile is applied.|
| CURRENT_ICC_PROFILE | 'CurrentICCProfile' | ICC color profile in use.|
| CURRENT_PRE_PROFILE_MATRIX | 'CurrentPreProfileMatrix' | Pre-transformation matrix used before the current ICC color profile.|
| COLORIMETRIC_REFERENCE | 'ColorimetricReference' | Chromaticity reference standard.|
| CAMERA_CALIBRATION_SIGNATURE | 'CameraCalibrationSignature' | Camera calibration signature.|
| PROFILE_CALIBRATION_SIGNATURE | 'ProfileCalibrationSignature' | Profile calibration signature.|
| EXTRA_CAMERA_PROFILES | 'ExtraCameraProfiles' | List of additional camera profile indexes.|
| AS_SHOT_PROFILE_NAME | 'AsShotProfileName' | Name of the profile used at capture.|
| NOISE_REDUCTION_APPLIED | 'NoiseReductionApplied' | Applied noise reduction intensity level.|
| PROFILE_NAME | 'ProfileName' | Color profile name.|
| PROFILE_HUE_SAT_MAP_DIMS | 'ProfileHueSatMapDims' | Dimensions of the hue/saturation mapping table.|
| PROFILE_HUE_SAT_MAP_DATA1 | 'ProfileHueSatMapData1' | First set of hue/saturation mapping table data.|
| PROFILE_HUE_SAT_MAP_DATA2 | 'ProfileHueSatMapData2' | Second set of hue/saturation mapping table data.|
| PROFILE_TONE_CURVE | 'ProfileToneCurve' | Tone curve of the profile.|
| PROFILE_EMBED_POLICY | 'ProfileEmbedPolicy' | Profile embedding policy.|
| PROFILE_COPYRIGHT | 'ProfileCopyright' | Profile copyright information.|
| FORWARD_MATRIX1 | 'ForwardMatrix1' | First forward transformation matrix.|
| FORWARD_MATRIX2 | 'ForwardMatrix2' | Second forward transformation matrix.|
| PREVIEW_APPLICATION_NAME | 'PreviewApplicationName' | Name of the application that generates the preview image.|
| PREVIEW_APPLICATION_VERSION | 'PreviewApplicationVersion' | Version of the application that generates the preview image.|
| PREVIEW_SETTINGS_NAME | 'PreviewSettingsName' | Name of the preview image processing configuration.|
| PREVIEW_SETTINGS_DIGEST | 'PreviewSettingsDigest' | MD5 digest of the preview image configuration.|
| PREVIEW_COLOR_SPACE | 'PreviewColorSpace' | Color space of the preview image.|
| PREVIEW_DATE_TIME | 'PreviewDateTime' | Preview image generation time.|
| RAW_IMAGE_DIGEST | 'RawImageDigest' | MD5 digest of the raw image data.|
| ORIGINAL_RAW_FILE_DIGEST | 'OriginalRawFileDigest' | MD5 digest of the original raw file data.|
| SUB_TILE_BLOCK_SIZE | 'SubTileBlockSize' | Block length and width for image titled storage.|
| ROW_INTERLEAVE_FACTOR | 'RowInterleaveFactor' | Row interleaving factor.|
| PROFILE_LOOK_TABLE_DIMS | 'ProfileLookTableDims' | **ProfileLookTableData** dimensions.|
| PROFILE_LOOK_TABLE_DATA | 'ProfileLookTableData' | Color table data.|
| OPCODE_LIST1 | 'OpcodeList1' | First operation code list.|
| OPCODE_LIST2 | 'OpcodeList2' | Second operation code list.|
| OPCODE_LIST3 | 'OpcodeList3' | Third operation code list.|
| NOISE_PROFILE | 'NoiseProfile' | Noise profile parameters.|
| ORIGINAL_DEFAULT_FINAL_SIZE | 'OriginalDefaultFinalSize' | Original default final output dimensions (width and height).|
| ORIGINAL_BEST_QUALITY_FINAL_SIZE | 'OriginalBestQualityFinalSize' | Original output dimensions (width and height) for optimal image quality.|
| ORIGINAL_DEFAULT_CROP_SIZE | 'OriginalDefaultCropSize' | Original default crop dimensions (width and height).|
| PROFILE_HUE_SAT_MAP_ENCODING | 'ProfileHueSatMapEncoding' | Encoding mode of the hue/saturation mapping table.|
| PROFILE_LOOK_TABLE_ENCODING | 'ProfileLookTableEncoding' | Color table encoding mode.|
| BASELINE_EXPOSURE_OFFSET | 'BaselineExposureOffset' | Baseline exposure offset, in EV.|
| DEFAULT_BLACK_RENDER | 'DefaultBlackRender' | Default black field rendering mode.|
| NEW_RAW_IMAGE_DIGEST | 'NewRawImageDigest' | New MD5 digest of the update raw image data.|
| RAW_TO_PREVIEW_GAIN | 'RawToPreviewGain' | Gain ratio of the main raw image to the preview image.|
| DEFAULT_USER_CROP | 'DefaultUserCrop' | Default user crop area.|

## PngPropertyKey

Enumerates PNG image information.

> **NOTE**
>
> For details about the return value type, see [PngMetadata](arkts-apis-image-PngMetadata.md).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Value| Description|
| ---- | -- | ---- |
| X_PIXELS_PER_METER | 'PngXPixelsPerMeter' | Number of pixels per meter in the X direction of the PNG image.|
| MODIFICATION_TIME | 'PngModificationTime' | Last modification time of the PNG image.|
| SOFTWARE | 'PngSoftware' | Name and version number of the software used to create the PNG image.|
| COPYRIGHT | 'PngCopyright' | Copyright notice of the PNG image.|
| CREATION_TIME | 'PngCreationTime' | Creation time of the PNG image.|
| SRGB_INTENT | 'PngSRGBIntent' | Standard Red Green Blue (sRGB) rendering intent of the PNG image.<br>- **0**: perceptual intent<br>- **1**: relative colorimetric intent<br>- **2**: saturation intent<br>- **3**: absolute colorimetric intent|
| AUTHOR | 'PngAuthor' | Author of the PNG image.|
| INTERLACE_TYPE | 'PngInterlaceType' | Interlace mode of the PNG image.<br>- **0**: no interlace mode. (The image is loaded sequentially from top to bottom and left to right.)<br>- **1**: interlace mode. (The image is displayed progressively through multiple scans, becoming clearer as loading proceeds.)|
| WARNING | 'PngWarning' | Warning information of the PNG image.|
| Y_PIXELS_PER_METER | 'PngYPixelsPerMeter' | Number of pixels per meter in the Y direction of the PNG image.|
| GAMMA | 'PngGamma' | Gamma coefficient value of the PNG image.|
| CHROMATICITIES | 'PngChromaticities' | Primary chromaticities and white point (cHRM) of the PNG image. This information can be used for device-independent color correction.|
| DESCRIPTION | 'PngDescription' | Description of the PNG image.|
| TITLE | 'PngTitle' | Title of the PNG image.|
| COMMENT | 'PngComment' | Comment of the PNG image.|
| DISCLAIMER | 'PngDisclaimer' | Disclaimer of the PNG image.|

## JfifPropertyKey

Enumerates JFIF image information.

> **NOTE**
>
> For details about the return value type, see [JfifMetadata](arkts-apis-image-JfifMetadata.md).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Value| Description|
| ---- | -- | ---- |
| DENSITY_UNIT | 'JfifDensityUnit' | Physical unit of measurement for **JfifXDensity** (horizontal pixel density) and **JfifYDensity** (vertical pixel density).<br>- **0**: no units (pixel aspect ratio only)<br>- **1**: pixels per inch (DPI)<br>- **2**: pixels per centimeter (DPC)<br>The value is a positive integer.|
| X_DENSITY | 'JfifXDensity' | Pixel density in the X direction of the JFIF image.|
| Y_DENSITY | 'JfifYDensity' | Pixel density in the Y direction of the JFIF image.|
| VERSION | 'JfifVersion' | JFIF image version.|
| IS_PROGRESSIVE | 'JfifIsProgressive' | Whether the image uses progressive encoding, that is, the image gradually improves in clarity through multiple scans during loading. The value **true** indicates yes, and the value **false** indicates no.|

## TiffPropertyKey

Enumerates TIFF image information.

> **NOTE**
>
> For details about the return value type, see [TiffMetadata](arkts-apis-image-TiffMetadata.md).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Value| Description|
| ---- | -- | ---- |
| DOCUMENT_NAME | 'TiffDocumentName' | Document or image name.|
| PHOTOMETRIC_INTERPRETATION | 'TiffPhotometricInterpretation' | Interpretation mode of pixel colors (such as RGB or grayscale).|
| ORIENTATION | 'TiffOrientation' | Image orientation.<br>- **1**: "Top-left" (Image not rotated)<br>- **2**: "Top-right" (Image flipped horizontally)<br>- **3**: "Bottom-right" (Image rotated by 180°)<br>- **4**: "Bottom-left" (Image flipped vertically)<br>- **5**: "Left-top" (Image flipped horizontally and then rotated clockwise by 270°)<br>- **6**: "Right-top" (Image rotated clockwise by 90°)<br>- **7**: "Right-bottom" (Image flipped horizontally and then rotated clockwise by 90°)<br>- **8**: "Left-bottom" (Image rotated clockwise by 270°)<br>If an undefined value is read, `Unknown Value x` is returned, where `x` indicates the original value of the tag.|
| RESOLUTION_UNIT | 'TiffResolutionUnit' | Unit of **XResolution** (horizontal resolution) and **YResolution** (vertical resolution). The value can be **Inch** or **Centimeter**.|
| COPYRIGHT | 'TiffCopyright' | Copyright notice of the image.|
| DATE_TIME | 'TiffDateTime' | Date and time associated with the image (usually the last modification time).|
| IMAGE_DESCRIPTION | 'TiffImageDescription' | Image description.|
| Y_RESOLUTION | 'TiffYResolution' | Vertical resolution (number of pixels per resolution unit).|
| X_RESOLUTION | 'TiffXResolution' | Horizontal resolution (number of pixels per resolution unit).|
| WHITE_POINT | 'TiffWhitePoint' | Chromaticity coordinates of the white point, the reference for "white", in the color space of the image.|
| TILE_LENGTH | 'TiffTileLength' | Height of each image tile. The unit is px.|
| TRANSFER_FUNCTION | 'TiffTransferFunction' | Transfer function for the image, which is usually used for color correction.|
| TILE_WIDTH | 'TiffTileWidth' | Width of each image tile. The unit is px.|
| MAKE | 'TiffMake' | Capture device manufacturer.|
| MODEL | 'TiffModel' | Capture device model name or ID.|
| HOST_COMPUTER | 'TiffHostComputer' | Host or system used for image processing.|
| COMPRESSION | 'TiffCompression' | Compression scheme used for TIFF image data.<br>- **1**: no compression.<br>- **5**: LZW (dictionary-based lossless compression algorithm)<br>- **7**: JPEG baseline.<br>- **8**: DEFLATE (lossless compression algorithm based on LZ77 and Huffman)|
| SOFTWARE | 'TiffSoftware' | Name and version number of the software used to create the image.|
| PRIMARY_CHROMATICITIES | 'TiffPrimaryChromaticities' | Chromaticity coordinates of the RGB primaries in the image.|
| ARTIST | 'TiffArtist' | Person who created the image.|

## AvisPropertyKey

Enumerates AVIS image information.

> **NOTE**
>
> For details about the return value type, see [AvisMetadata](arkts-apis-image-AvisMetadata.md).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value               | Description                  |
| ----------------- | ----------------- | --------------------- |
| DELAY_TIME    | 'AvisDelayTime'    | Playback duration of each frame in an AVIS image.<br>The unit is milliseconds.|

## ImageFormat<sup>9+</sup>

Enumerates image formats.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        |   Value  | Description                |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422 semi-planar format.|
| JPEG         | 2000   | JPEG encoding format.      |

## ComponentType<sup>9+</sup>

Enumerates image component types.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name |   Value  | Description       |
| ----- | ------ | ----------- |
| YUV_Y | 1      | Luminance component. |
| YUV_U | 2      | Chrominance component. |
| YUV_V | 3      | Chrominance component. |
| JPEG  | 4      | JPEG type.|

## DecodingDynamicRange<sup>12+</sup>

Enumerates the desired dynamic range of an image during decoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| AUTO          | 0    | The image is decoded based on the format. If the image is in HDR format, it is decoded based on the HDR content; otherwise, it is decoded based on the SDR content. The image source created by calling [CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9) is decoded into SDR content. |
| SDR           | 1    | The image is decoded according to the standard dynamic range.  |
| HDR           | 2    | The image is decoded according to the high dynamic range. The image source created by calling [CreateIncrementalSource](arkts-apis-image-f.md#imagecreateincrementalsource9) is decoded into SDR content.    |

## PackingDynamicRange<sup>12+</sup>

Enumerates the desired dynamic range of an image during encoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| AUTO          | 0    | Adaptive. The [pixelmap](arkts-apis-image-PixelMap.md) is encoded based on the format. If the PixelMap is in HDR format, it is encoded based on the HDR content; otherwise, it is encoded based on the SDR content. |
| SDR           | 1    | The image is decoded according to the standard dynamic range.  |

## CropAndScaleStrategy<sup>18+</sup>

Enumerates the order policies between cropping and scaling.

If the **cropAndScaleStrategy** parameter is not specified in [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) and both **desiredRegion** and **desiredSize** are set, the final decoding result may vary slightly due to differences in decoding algorithms used for different image formats.

For example, if the original image size is 200x200, and you specify **desiredSize:{width: 150, height: 150}, desiredRegion:{x: 0, y: 0, width: 100, height: 100}**, the expectation is to decode the top-left 1/4 region of the original image and then scale the pixelMap size to 150x150.

For JPEG and WebP images (as well as some DNG images that decode a JPEG preview within the file and therefore are treated as JPEG format), the system first performs downsampling. For instance, it might downsample by 7/8 and then crop the region based on a 175x175 image size. As a result, the final cropped region will be slightly larger than the top-left 1/4 of the original image.

For SVG images, since they are vector graphics, they can be scaled arbitrarily without loss of clarity. During decoding, the scaling ratio is determined based on the proportion between **desiredSize** and the original image size. Cropping is then performed on the scaled image. As a result, the actual decoded region returned may vary.

To ensure consistent results when both **desiredRegion** and **desiredSize** are set, set the **cropAndScaleStrategy** parameter to **CROP_FIRST**.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| SCALE_FIRST   | 1    | If both **desiredRegion** and **desiredSize** are specified, the image is first scaled based on **desiredSize** and then cropped based on **desiredRegion**.    |
| CROP_FIRST    | 2    | If both **desiredRegion** and **desiredSize** are specified, the image is first cropped based on **desiredRegion** and then scaled based on **desiredSize**.    |

## HdrMetadataKey<sup>12+</sup>

Enumerates the keys of HDR metadata used by [PixelMap](arkts-apis-image-PixelMap.md).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| HDR_METADATA_TYPE    | 0    | Metadata type used by [PixelMap](arkts-apis-image-PixelMap.md). |
| HDR_STATIC_METADATA  | 1    | Static metadata.  |
| HDR_DYNAMIC_METADATA | 2    | Dynamic metadata.  |
| HDR_GAINMAP_METADATA | 3    | Metadata used by the gain map.  |

## HdrMetadataType<sup>12+</sup>

Enumerates the values corresponding to the **HDR_METADATA_TYPE** keyword in [HdrMetadataKey](#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value | Description        |
| ------------- | --- | ------------ |
| NONE          | 0   | No metadata. |
| BASE          | 1   | Metadata used for base graphics.  |
| GAINMAP       | 2   | Metadata used for gain maps.  |
| ALTERNATE     | 3   | Metadata used for synthesized HDR graphics.  |

## AntiAliasingLevel<sup>12+</sup>

Enumerates the interpolation algorithm used during scaling. You can select the appropriate level based on scaling quality and performance requirements.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| NONE                | 0      | Nearest neighbor interpolation.<br>This is the fastest option but produces noticeable mosaic/aliasing artifacts when upscaling. It is suitable for scenarios with high performance requirements and low quality demands.|
| LOW                 | 1      | Bilinear interpolation.<br>It is suitable for general scaling scenarios.  |
| MEDIUM              | 2      | Bilinear interpolation with mipmap enabled.<br>It is suitable for image downscaling, effectively reducing aliasing and texture flickering when scaling down significantly.  |
| HIGH                | 3      | Bicubic convolution interpolation algorithm.<br>It is suitable for upscaling scenarios with high quality requirements.  |

## AllocatorType<sup>15+</sup>

Enumerates memory types used for image decoding. You can choose the appropriate memory allocation type based on the scenario.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        | Value  | Description                              |
| ------------ | ---- | ---------------------------------- |
| AUTO         | 0    | The system determines the memory allocation type.    |
| DMA          | 1    | The Direct Memory Access (DMA) memory type is used. This option is suitable for scenarios with high requirements for decoding and rendering performance. Depending on the hardware, padding bytes may be added at the end of each pixel row for memory alignment.           |
| SHARE_MEMORY | 2    | The shared memory is used.|

## Orientation<sup>23+</sup>

Enumerates image orientation types.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        | Value  | Description                               |
| ------------ | ---- | ----------------------------------- |
| TOP_LEFT     | 1    | Image not rotated.                       |
| TOP_RIGHT    | 2    | Image flipped horizontally.                 |
| BOTTOM_RIGHT | 3    | Image rotated by 180°.                  |
| BOTTOM_LEFT  | 4    | Image flipped vertically.                     |
| LEFT_TOP     | 5    | Image flipped horizontally and then rotated clockwise by 270°.|
| RIGHT_TOP    | 6    | Image rotated clockwise by 90°.               |
| RIGHT_BOTTOM | 7    | Image flipped horizontally and then rotated clockwise by 90°. |
| LEFT_BOTTOM  | 8    | Image rotated clockwise by 270°.              |

## FocusMode<sup>23+</sup>

Enumerates focus mode types.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Value  | Description          |
| ---- | ---- | -------------- |
| AF_A | 0    | Autofocus.    |
| AF_S | 1    | Single autofocus.|
| AF_C | 2    | Continuous autofocus.|
| MF   | 3    | Manual focus.    |

## XmageColorMode<sup>23+</sup>

Enumerates XMAGE color mode type.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| NORMAL | 0    | Standard.|
| BRIGHT | 1    | Bright.|
| SOFT   | 2    | Soft focus.|
| MONO   | 3    | Monochrome.|

## XMPTagType

Enumerates XMP tag types.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name           | Value  | Description                                                                |
| --------------- | ---- | ------------------------------------------------------------------- |
| UNKNOWN         | 0    | Unknown.                                                          |
| STRING          | 1    | String.                                                        |
| UNORDERED_ARRAY | 2    | Unordered array. During serialization, the format of this type in XMP metadata is \<rdf:Bag>.         |
| ORDERED_ARRAY   | 3    | Unordered array. During serialization, the format of this type in XMP metadata is \<rdf:Seq>.         |
| ALTERNATE_ARRAY | 4    | Alternative array. During serialization, the format of this type in XMP metadata is \<rdf:Alt>.         |
| ALTERNATE_TEXT  | 5    | Multi-language text. During serialization, this type is an alternative array of **xml:lang** qualifiers in XMP format.|
| STRUCTURE       | 6    | Struct. Unlike array elements, fields in the struct can belong to different namespaces.           |
