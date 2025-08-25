# Enums
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## PixelMapFormat<sup>7+</sup>

Enumerates the pixel formats of images.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | Unknown format.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.       |
| ARGB_8888<sup>18+</sup> | 1 | The color information consists of four components: alpha, R (Red), G (Green), and B (Blue). Each component occupies 8 bits, and the total length is 32 bits. Currently, this format supports only PixelMap APIs.|
| RGB_565                | 2      | The color information consists of three components: R (Red), G (Green), and B (Blue), which occupies five bits, six bits, and five bits, respectively. The total length is 16 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.    |
| RGBA_8888              | 3      | The color information consists of four components: R (Red), G (Green), B (Blue), and alpha. Each component occupies 8 bits, and the total length is 32 bits. It corresponds to [CAMERA_FORMAT_RGBA_8888 in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| BGRA_8888<sup>9+</sup> | 4      | The color information consists of four components: B (Blue), G (Green), R (Red), and alpha. Each component occupies 8 bits, and the total length is 32 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| RGB_888<sup>9+</sup>   | 5      | The color information consists of three components: R (Red), G (Green), and B (Blue). Each component occupies 8 bits, and the total length is 24 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| ALPHA_8<sup>9+</sup>   | 6      | The color information consists of only the alpha component, which occupies eight bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| RGBA_F16<sup>9+</sup>  | 7      | The color information consists of four components: R (Red), G (Green), B (Blue), and alpha. Each component occupies 16 bits, and the total length is 64 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| NV21<sup>9+</sup>      | 8      | YVU pixel arrangement, where the V component precedes the U component. The color information consists of the luminance component Y and the interleaved chrominance components V and U. The Y component occupies 8 bits, and the UV components occupy 4 bits on average due to 4:2:0 sampling. The total length is 12 bits on average.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| NV12<sup>9+</sup>      | 9      | YUV pixel arrangement, where the U component precedes the V component. The color information consists of the luminance component Y and the interleaved chrominance components U and V. The Y component occupies 8 bits, and the UV components occupy 4 bits on average due to 4:2:0 sampling. The total length is 12 bits on average. It corresponds to [CAMERA_FORMAT_YUV_420_SP in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| RGBA_1010102<sup>12+</sup> | 10 | The color information consists of four components: R (Red), G (Green), B (Blue), and alpha. R, G, and B each occupy 10 bits, and alpha occupies 2 bits. The total length is 32 bits.|
| YCBCR_P010<sup>12+</sup> | 11 | The color information consists of the luminance component Y and the chrominance components Cb and Cr. Each component has effective 10 bits. In storage, the Y plane uses 16 bits per pixel (10 of which are effective). The UV plane is interleaved, with every four pixels taking up 32 bits of data (each chrominance component having 10 effective bits), resulting in an average of 15 effective bits overall. It corresponds to [CAMERA_FORMAT_YCBCR_P010 in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat). |
| YCRCB_P010<sup>12+</sup> | 12 | The color information consists of the luminance component Y and the chrominance components Cr and Cb. Each component has effective 10 bits. In storage, the Y plane uses 16 bits per pixel (10 of which are effective). The UV plane is interleaved, with every four pixels taking up 32 bits of data (each chrominance component having 10 effective bits), resulting in an average of 15 effective bits overall. It corresponds to [CAMERA_FORMAT_YCRCB_P010 in CameraFormat](../apis-camera-kit/arkts-apis-camera-e.md#cameraformat). |
| ASTC_4x4<sup>18+</sup> | 102 | The storage format is ASTC_4x4, and the memory usage is only 1/4 of that of RGBA_8888. This format is intended for direct display scenarios. It does not support pixel access or editing in post-processing, and does not support cascaded affine transformations. |

## AlphaType<sup>9+</sup>

Enumerates the alpha types of images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    |   Value  | Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown alpha type.           |
| OPAQUE   | 1      | There is no alpha or the image is opaque.|
| PREMUL   | 2      | Premultiplied alpha.        |
| UNPREMUL | 3      | RGB non-premultiplied alpha.      |

## AuxiliaryPictureType<sup>13+</sup>

Enumerates the auxiliary pictures types.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| GAINMAP       | 1    | Gain map, a mechanism for transforming an SDR image into an HDR image capable of display adjustment. It is a set of combinations describing how to apply gain map metadata.    |
| DEPTH_MAP     | 2    | Depth map, which stores the depth data of an image. It captures the distance between each pixel and the camera to provide 3D scene structure. It is usually used for 3D modeling and scene comprehension.    |
| UNREFOCUS_MAP | 3    | Defocused portrait original image, which provides a method to emphasize background blur in portrait photographing. It helps users select a focus region in post-processing, allowing for greater creative control.  |
| LINEAR_MAP    | 4    | Linear map, which is used to provide additional viewpoints or supplementary information. It is usually used to enhance visual effects and can contain linear representations of lighting, colors, or other visual elements in a scene.    |
| FRAGMENT_MAP  | 5    | Fragment map, which indicates regions obscured by watermarks in the original image. It is used to remove or correct the watermark interference, thereby enhancing the image completeness and visibility.|

## MetadataType<sup>13+</sup>

Enumerates image metadata types.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value  | Description              |
| ----------------- | ---- | ------------------ |
| EXIF_METADATA     | 1    | EXIF data.        |
| FRAGMENT_METADATA | 2    | Fragment map metadata.|
| GIF_METADATA<sup>20+</sup> | 5    | GIF image metadata.|

## ScaleMode<sup>9+</sup>

Enumerates the scale modes of images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name           |   Value  | Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | Scales the image so that it fills the requested bounds of the target and crops the extra.|
| FIT_TARGET_SIZE | 0      | Reduces the image size to the dimensions of the target.                          |

## PropertyKey<sup>7+</sup>

Describes the exchangeable image file format (EXIF) data of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name              |   Value                   |   Description                   |
| ----------------- | ----------------------- |---------------------------|
| NEW_SUBFILE_TYPE <sup>12+</sup>           | "NewSubfileType"            | **Read/Write capability**: readable and writable<br> Data type of a subfile, such as a full-resolution image, a thumbnail, or a part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image.|
| SUBFILE_TYPE <sup>12+</sup>               | "SubfileType"               | **Read/Write capability**: readable and writable<br> Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead.|
| IMAGE_WIDTH                               | "ImageWidth"                | **Read/Write capability**: readable and writable<br> Image width.|
| IMAGE_LENGTH                              | "ImageLength"               | **Read/Write capability**: readable and writable<br> Image length.|
| BITS_PER_SAMPLE                           | "BitsPerSample"             | **Read/Write capability**: readable and writable<br> Number of bits per sample. For example, for RGB, which has three components, the format is 8, 8, 8.|
| COMPRESSION <sup>12+</sup>                | "Compression"               | **Read/Write capability**: readable and writable<br> Compression scheme used on the image data.|
| PHOTOMETRIC_INTERPRETATION <sup>12+</sup> | "PhotometricInterpretation" | **Read/Write capability**: readable and writable<br> Color space of the image data, for example, RGB or YCbCr.|
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"          | **Read/Write capability**: readable and writable<br> Image description.|
| MAKE<sup>10+</sup>                        | "Make"                      | **Read/Write capability**: readable and writable<br> Manufacturer.|
| MODEL<sup>10+</sup>                       | "Model"                     | **Read/Write capability**: readable and writable<br> Device model.|
| STRIP_OFFSETS <sup>12+</sup>              | "StripOffsets"              | **Read/Write capability**: readable and writable<br> Byte offset of each strip.|
| ORIENTATION                               | "Orientation"               | **Read/Write capability**: readable and writable<br> Image orientation.<br> 1: **Top-left**: The image is not rotated.<br> 2: **Top-right**: The image is flipped horizontally.<br> 3: **Bottom-right**: The image is rotated by 180°.<br> 4: **Bottom-left**: The image is flipped vertically.<br> 5: **Left-top**: The image is flipped horizontally and then rotated clockwise by 270°.<br> 6: **Right-top**: The image is rotated clockwise by 90°.<br> 7: **Right-bottom**: The image is vertically flipped and then rotated clockwise by 90°.<br> 8: **Left-bottom**: The image is rotated clockwise by 270°.<br> If an undefined value is read, **Unknown Value 0** is returned. The value of the property obtained is returned as a string. When modifying the property, you can specify the property either in the form of a number or a string.|
| SAMPLES_PER_PIXEL <sup>12+</sup>          | "SamplesPerPixel"           | **Read/Write capability**: readable and writable<br> Number of components per pixel. The value is 3 for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.|
| ROWS_PER_STRIP <sup>12+</sup>             | "RowsPerStrip"              | **Read/Write capability**: readable and writable<br> Number of rows per strip.|
| STRIP_BYTE_COUNTS <sup>12+</sup>          | "StripByteCounts"           | **Read/Write capability**: readable and writable<br> Number of bytes in each strip after compression.|
| X_RESOLUTION <sup>12+</sup>               | "XResolution"               | **Read/Write capability**: readable and writable<br> Number of pixels per ResolutionUnit in the image width (X) direction.|
| Y_RESOLUTION <sup>12+</sup>               | "YResolution"               | **Read/Write capability**: readable and writable<br> Number of pixels per ResolutionUnit in the image height (Y) direction.|
| PLANAR_CONFIGURATION <sup>12+</sup>       | "PlanarConfiguration"       | **Read/Write capability**: readable and writable<br> Storage format of components of each pixel, which can be chunky or planar.|
| RESOLUTION_UNIT <sup>12+</sup>            | "ResolutionUnit"            | **Read/Write capability**: readable and writable<br> Unit of measurement for XResolution and YResolution.|
| TRANSFER_FUNCTION <sup>12+</sup>          | "TransferFunction"          | **Read/Write capability**: readable and writable<br> Transfer function for the image, which is usually used for color correction.|
| SOFTWARE <sup>12+</sup>                   | "Software"                  | **Read/Write capability**: readable and writable<br> Name and version number of the software used to create the image.|
| DATE_TIME<sup>10+</sup>                   | "DateTime"                  | **Read/Write capability**: readable and writable<br> Date and time of image creation. An example in the correct format is 2024:01:25 05:51:34.|
| ARTIST <sup>12+</sup>                     | "Artist"                    | **Read/Write capability**: readable and writable<br> Person who created the image.|
| WHITE_POINT <sup>12+</sup>                | "WhitePoint"                | **Read/Write capability**: readable and writable<br> Chromaticity of the white point of the image.|
| PRIMARY_CHROMATICITIES <sup>12+</sup>     | "PrimaryChromaticities"     | **Read/Write capability**: readable and writable<br> Chromaticities of the primaries of the image.|
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode"                 | **Read/Write capability**: readable and writable<br> Photographing mode.|
| JPEG_INTERCHANGE_FORMAT <sup>12+</sup>    | "JPEGInterchangeFormat"     | **Read/Write capability**: read-only<br> Offset of the SOI marker of a JPEG interchange format bitstream.|
| JPEG_INTERCHANGE_FORMAT_LENGTH <sup>12+</sup> | "JPEGInterchangeFormatLength" | **Read/Write capability**: read-only<br> Number of bytes of the JPEG stream.|
| YCBCR_COEFFICIENTS <sup>12+</sup>         | "YCbCrCoefficients"         | **Read/Write capability**: readable and writable<br> Transformation from RGB to YCbCr image data.|
| YCBCR_SUB_SAMPLING <sup>12+</sup>         | "YCbCrSubSampling"          | **Read/Write capability**: readable and writable<br> Subsampling factors used for the chrominance components of a YCbCr image.|
| YCBCR_POSITIONING <sup>12+</sup>          | "YCbCrPositioning"          | **Read/Write capability**: readable and writable<br> Positioning of subsampled chrominance components relative to luminance samples.|
| REFERENCE_BLACK_WHITE <sup>12+</sup>      | "ReferenceBlackWhite"       | **Read/Write capability**: readable and writable<br> A pair of headroom and footroom image data values (codes) for each pixel component.|
| COPYRIGHT <sup>12+</sup>                  | "Copyright"                 | **Read/Write capability**: readable and writable<br> Copyright notice of the image.|
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"              | **Read/Write capability**: readable and writable<br> Exposure time, for example, 1/33 seconds.|
| F_NUMBER<sup>9+</sup>                     | "FNumber"                   | **Read/Write capability**: readable and writable<br> F number, for example, f/1.8.|
| EXPOSURE_PROGRAM <sup>12+</sup>           | "ExposureProgram"           | **Read/Write capability**: readable and writable<br> Class of the program used by the camera to set exposure when the image was captured.|
| SPECTRAL_SENSITIVITY <sup>12+</sup>       | "SpectralSensitivity"       | **Read/Write capability**: readable and writable<br> Spectral sensitivity of each channel of the camera.|
| GPS_VERSION_ID <sup>12+</sup>             | "GPSVersionID"              | **Read/Write capability**: readable and writable<br> Version of GPSInfoIFD.|
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"            | **Read/Write capability**: readable and writable<br> Whether the latitude is north or south latitude.|
| GPS_LATITUDE                              | "GPSLatitude"               | **Read/Write capability**: readable and writable<br> Image latitude. The value must be in the format of degree,minute,second, for example, 39,54,7.542.|
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"           | **Read/Write capability**: readable and writable<br> Whether the longitude is east or west longitude.|
| GPS_LONGITUDE                             | "GPSLongitude"              | **Read/Write capability**: readable and writable<br> Image longitude. The value must be in the format of degree,minute,second, for example, 116,19,42.16.|
| GPS_ALTITUDE_REF <sup>12+</sup>           | "GPSAltitudeRef"            | **Read/Write capability**: readable and writable<br> Whether the latitude is north or south latitude.|
| GPS_ALTITUDE <sup>12+</sup>               | "GPSAltitude"               | **Read/Write capability**: readable and writable<br> Altitude based on the reference in GPSAltitudeRef.|
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"              | **Read/Write capability**: readable and writable<br> GPS timestamp.|
| GPS_SATELLITES <sup>12+</sup>             | "GPSSatellites"             | **Read/Write capability**: readable and writable<br> GPS satellites used for measurement.|
| GPS_STATUS <sup>12+</sup>                 | "GPSStatus"                 | **Read/Write capability**: readable and writable<br> Status of the GPS receiver when the image was recorded.|
| GPS_MEASURE_MODE <sup>12+</sup>           | "GPSMeasureMode"            | **Read/Write capability**: readable and writable<br> GPS measurement pmode.|
| GPS_DOP <sup>12+</sup>                    | "GPSDOP"                    | **Read/Write capability**: readable and writable<br> GPS DOP (data degree of precision)|
| GPS_SPEED_REF <sup>12+</sup>              | "GPSSpeedRef"               | **Read/Write capability**: readable and writable<br> Unit used to express the movement speed of the GPS receiver.|
| GPS_SPEED <sup>12+</sup>                  | "GPSSpeed"                  | **Read/Write capability**: readable and writable<br> Movement speed of the GPS receiver.|
| GPS_TRACK_REF <sup>12+</sup>              | "GPSTrackRef"               | **Read/Write capability**: readable and writable<br> Reference of the movement direction of the GPS receiver.|
| GPS_TRACK <sup>12+</sup>                  | "GPSTrack"                  | **Read/Write capability**: readable and writable<br> Movement direction of the GPS receiver.|
| GPS_IMG_DIRECTION_REF <sup>12+</sup>      | "GPSImgDirectionRef"        | **Read/Write capability**: readable and writable<br> Reference of the direction of the image when it was captured.|
| GPS_IMG_DIRECTION <sup>12+</sup>          | "GPSImgDirection"           | **Read/Write capability**: readable and writable<br> Direction of the image when it was captured.|
| GPS_MAP_DATUM <sup>12+</sup>              | "GPSMapDatum"               | **Read/Write capability**: readable and writable<br> Geodetic survey data used by the GPS receiver.|
| GPS_DEST_LATITUDE_REF <sup>12+</sup>      | "GPSDestLatitudeRef"        | **Read/Write capability**: readable and writable<br> Whether the latitude of the destination point is north or south latitude.|
| GPS_DEST_LATITUDE <sup>12+</sup>          | "GPSDestLatitude"           | **Read/Write capability**: readable and writable<br> Latitude of the destination point.|
| GPS_DEST_LONGITUDE_REF <sup>12+</sup>     | "GPSDestLongitudeRef"       | **Read/Write capability**: readable and writable<br> Whether the longitude of the destination point is east or west longitude.|
| GPS_DEST_LONGITUDE <sup>12+</sup>         | "GPSDestLongitude"          | **Read/Write capability**: readable and writable<br> Longitude of the destination point.|
| GPS_DEST_BEARING_REF <sup>12+</sup>       | "GPSDestBearingRef"         | **Read/Write capability**: readable and writable<br> Reference of the bearing to the destination point.|
| GPS_DEST_BEARING <sup>12+</sup>           | "GPSDestBearing"            | **Read/Write capability**: readable and writable<br> Bearing to the destination point.|
| GPS_DEST_DISTANCE_REF <sup>12+</sup>      | "GPSDestDistanceRef"        | **Read/Write capability**: readable and writable<br> Unit used to express the distance to the destination point.|
| GPS_DEST_DISTANCE <sup>12+</sup>          | "GPSDestDistance"           | **Read/Write capability**: readable and writable<br> Distance to the destination point.|
| GPS_PROCESSING_METHOD <sup>12+</sup>      | "GPSProcessingMethod"       | **Read/Write capability**: readable and writable<br> String that records the name of the method used for positioning.|
| GPS_AREA_INFORMATION <sup>12+</sup>       | "GPSAreaInformation"        | **Read/Write capability**: readable and writable<br> String that records the name of the GPS area.|
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"              | **Read/Write capability**: readable and writable<br> GPS date stamp.|
| GPS_DIFFERENTIAL <sup>12+</sup>           | "GPSDifferential"           | **Read/Write capability**: readable and writable<br> Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy.|
| GPS_H_POSITIONING_ERROR <sup>12+</sup>    | "GPSHPositioningError"      | **Read/Write capability**: readable and writable<br> Horizontal positioning error, in meters.|
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"           | **Read/Write capability**: readable and writable<br> ISO sensitivity or ISO speed, for example, 400.|
| PHOTOGRAPHIC_SENSITIVITY <sup>12+</sup>   | "PhotographicSensitivity"   | **Read/Write capability**: readable and writable<br> Sensitivity of the camera or input device when the image was captured.|
| OECF <sup>12+</sup>                       | "OECF"                      | **Read/Write capability**: readable and writable<br> Opto-Electric Conversion Function (OECF) specified in ISO 14524.|
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"           | **Read/Write capability**: readable and writable<br> Sensitivity type.|
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity" | **Read/Write capability**: readable and writable<br> Standard output sensitivity.|
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex"  | **Read/Write capability**: readable and writable<br> Recommended exposure index.|
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"           | **Read/Write capability**: readable and writable<br> ISO speed.|
| ISO_SPEED_LATITUDE_YYY <sup>12+</sup>     | "ISOSpeedLatitudeyyy"       | **Read/Write capability**: readable and writable<br> ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232.|
| ISO_SPEED_LATITUDE_ZZZ <sup>12+</sup>     | "ISOSpeedLatitudezzz"       | **Read/Write capability**: readable and writable<br> ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232.|
| EXIF_VERSION <sup>12+</sup>               | "ExifVersion"               | **Read/Write capability**: readable and writable<br> Version of the supported EXIF standard.|
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"          | **Read/Write capability**: readable and writable<br> Time when the original image data was generated, for example, 2022:09:06 15:48:00.|
| DATE_TIME_DIGITIZED <sup>12+</sup>        | "DateTimeDigitized"         | **Read/Write capability**: readable and writable<br> Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:MM:SS.|
| OFFSET_TIME <sup>12+</sup>                | "OffsetTime"                | **Read/Write capability**: readable and writable<br> Time with an offset from UTC when the image was captured, in the format of ±HH:MM.|
| OFFSET_TIME_ORIGINAL <sup>12+</sup>       | "OffsetTimeOriginal"        | **Read/Write capability**: readable and writable<br> Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications.|
| OFFSET_TIME_DIGITIZED <sup>12+</sup>      | "OffsetTimeDigitized"       | **Read/Write capability**: readable and writable<br> Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp.|
| COMPONENTS_CONFIGURATION <sup>12+</sup>   | "ComponentsConfiguration"   | **Read/Write capability**: readable and writable<br> Specific information about compressed data.|
| COMPRESSED_BITS_PER_PIXEL <sup>12+</sup>  | "CompressedBitsPerPixel"    | **Read/Write capability**: readable and writable<br> Number of bits per pixel. It is specific to compressed data.|
| SHUTTER_SPEED <sup>12+</sup>              | "ShutterSpeedValue"         | **Read/Write capability**: readable and writable<br> Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values.|
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"             | **Read/Write capability**: readable and writable<br> Lens aperture. An example in the correct format is 4/1.|
| BRIGHTNESS_VALUE <sup>12+</sup>           | "BrightnessValue"           | **Read/Write capability**: readable and writable<br> Value of brightness, expressed in APEX values.|
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"         | **Read/Write capability**: readable and writable<br> Exposure bias.|
| MAX_APERTURE_VALUE <sup>12+</sup>         | "MaxApertureValue"          | **Read/Write capability**: readable and writable<br> Smallest F number of the lens.|
| SUBJECT_DISTANCE <sup>12+</sup>           | "SubjectDistance"           | **Read/Write capability**: readable and writable<br> Distance to the subject, in meters.|
| METERING_MODE<sup>10+</sup>               | "MeteringMode"              | **Read/Write capability**: readable and writable<br> Metering mode.|
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"               | **Read/Write capability**: readable and writable<br> Light source. An example value is **Fluorescent**.|
| FLASH <sup>10+</sup>                      | "Flash"                     | **Read/Write capability**: readable and writable<br> Flash status.|
| FOCAL_LENGTH <sup>10+</sup>               | "FocalLength"               | **Read/Write capability**: readable and writable<br> Focal length of the lens.|
| SUBJECT_AREA <sup>12+</sup>               | "SubjectArea"               | **Read/Write capability**: readable and writable<br> Location and area of the main subject in the entire scene.|
| MAKER_NOTE <sup>12+</sup>                 | "MakerNote"                 | **Read/Write capability**: readable and writable<br> Marker used by EXIF/DCF manufacturers to record any required information.<br>This field is read-only in API versions 12 to 19 and is readable and writable in API version 20 and later.|
| SCENE_POINTER <sup>12+</sup>              | "HwMnoteScenePointer"       | **Read/Write capability**: read-only<br> Pointer to the scene.|
| SCENE_VERSION <sup>12+</sup>              | "HwMnoteSceneVersion"       | **Read/Write capability**: read-only<br> Scene algorithm version.|
| SCENE_FOOD_CONF<sup>11+</sup>             | "HwMnoteSceneFoodConf"      | **Read/Write capability**: read-only<br> Photographing scene: food.|
| SCENE_STAGE_CONF<sup>11+</sup>            | "HwMnoteSceneStageConf"     | **Read/Write capability**: read-only<br> Photographing scene: stage.|
| SCENE_BLUE_SKY_CONF<sup>11+</sup>         | "HwMnoteSceneBlueSkyConf"   | **Read/Write capability**: read-only<br> Photographing scene: blue sky.|
| SCENE_GREEN_PLANT_CONF<sup>11+</sup>      | "HwMnoteSceneGreenPlantConf" | **Read/Write capability**: read-only<br> Photographing scene: green plant.|
| SCENE_BEACH_CONF<sup>11+</sup>            | "HwMnoteSceneBeachConf"     | **Read/Write capability**: read-only<br> Photographing scene: beach.|
| SCENE_SNOW_CONF<sup>11+</sup>             | "HwMnoteSceneSnowConf"      | **Read/Write capability**: read-only<br> Photographing scene: snow.|
| SCENE_SUNSET_CONF<sup>11+</sup>           | "HwMnoteSceneSunsetConf"    | **Read/Write capability**: read-only<br> Photographing scene: sunset.|
| SCENE_FLOWERS_CONF<sup>11+</sup>          | "HwMnoteSceneFlowersConf"   | **Read/Write capability**: read-only<br> Photographing scene: flowers.|
| SCENE_NIGHT_CONF<sup>11+</sup>            | "HwMnoteSceneNightConf"     | **Read/Write capability**: read-only<br> Photographing scene: night.|
| SCENE_TEXT_CONF<sup>11+</sup>             | "HwMnoteSceneTextConf"      | **Read/Write capability**: read-only<br> Photographing scene: text.|
| FACE_POINTER <sup>12+</sup>               | "HwMnoteFacePointer"        | **Read/Write capability**: read-only<br> Face pointer.|
| FACE_VERSION <sup>12+</sup>               | "HwMnoteFaceVersion"        | **Read/Write capability**: read-only<br> Facial recognition algorithm version.|
| FACE_COUNT<sup>11+</sup>                  | "HwMnoteFaceCount"          | **Read/Write capability**: read-only<br> Number of faces.|
| FACE_CONF <sup>12+</sup>                  | "HwMnoteFaceConf"           | **Read/Write capability**: read-only<br> Face confidence.|
| FACE_SMILE_SCORE <sup>12+</sup>           | "HwMnoteFaceSmileScore"     | **Read/Write capability**: read-only<br> Smile score of for faces.|
| FACE_RECT <sup>12+</sup>                  | "HwMnoteFaceRect"           | **Read/Write capability**: read-only<br> Face rectangle.|
| FACE_LEYE_CENTER <sup>12+</sup>           | "HwMnoteFaceLeyeCenter"     | **Read/Write capability**: read-only<br> Left eye centered.|
| FACE_REYE_CENTER <sup>12+</sup>           | "HwMnoteFaceReyeCenter"     | **Read/Write capability**: read-only<br> Right eye centered.|
| FACE_MOUTH_CENTER <sup>12+</sup>          | "HwMnoteFaceMouthCenter"    | **Read/Write capability**: read-only<br> Mouth centered.|
| CAPTURE_MODE <sup>10+</sup>               | "HwMnoteCaptureMode"        | **Read/Write capability**: readable and writable<br> Capture mode.|
| BURST_NUMBER <sup>12+</sup>               | "HwMnoteBurstNumber"        | **Read/Write capability**: read-only<br> Number of burst shooting times.|
| FRONT_CAMERA <sup>12+</sup>               | "HwMnoteFrontCamera"        | **Read/Write capability**: read-only<br> Whether the front camera is used to take a selfie.|
| ROLL_ANGLE <sup>11+</sup>                 | "HwMnoteRollAngle"          | **Read/Write capability**: read-only<br> Roll angle.|
| PITCH_ANGLE<sup>11+</sup>                 | "HwMnotePitchAngle"         | **Read/Write capability**: read-only<br> Pitch angle.|
| PHYSICAL_APERTURE <sup>10+</sup>          | "HwMnotePhysicalAperture"   | **Read/Write capability**: read-only<br> Physical aperture.|
| FOCUS_MODE<sup>11+</sup>                  | "HwMnoteFocusMode"          | **Read/Write capability**: read-only<br> Focus mode.|
| USER_COMMENT <sup>10+</sup>               | "UserComment"               | **Read/Write capability**: readable and writable<br> User comments.|
| SUBSEC_TIME <sup>12+</sup>                | "SubsecTime"                | **Read/Write capability**: readable and writable<br> Tag used to record fractions of seconds for the **DateTime** tag.|
| SUBSEC_TIME_ORIGINAL <sup>12+</sup>       | "SubsecTimeOriginal"        | **Read/Write capability**: readable and writable<br> Tag used to record fractions of seconds for the **DateTimeOriginal** tag.|
| SUBSEC_TIME_DIGITIZED <sup>12+</sup>      | "SubsecTimeDigitized"       | **Read/Write capability**: readable and writable<br> Tag used to record fractions of seconds for the **DateTimeDigitized** tag.|
| FLASHPIX_VERSION <sup>12+</sup>           | "FlashpixVersion"           | **Read/Write capability**: readable and writable<br> FlashPix format version supported by an FPXR file. It is used to enhance device compatibility.|
| COLOR_SPACE <sup>12+</sup>                | "ColorSpace"                | **Read/Write capability**: readable and writable<br> Color space information, which is usually recorded as a color space specifier.|
| PIXEL_X_DIMENSION <sup>10+</sup>          | "PixelXDimension"           | **Read/Write capability**: readable and writable<br> Pixel X dimension.|
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"           | **Read/Write capability**: readable and writable<br> Pixel Y dimension.|
| RELATED_SOUND_FILE <sup>12+</sup>         | "RelatedSoundFile"          | **Read/Write capability**: readable and writable<br> Name of an audio file related to the image data.|
| FLASH_ENERGY <sup>12+</sup>               | "FlashEnergy"               | **Read/Write capability**: readable and writable<br> Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS).|
| SPATIAL_FREQUENCY_RESPONSE <sup>12+</sup> | "SpatialFrequencyResponse"  | **Read/Write capability**: readable and writable<br> Spatial frequency table of the camera or input device.|
| FOCAL_PLANE_X_RESOLUTION <sup>12+</sup>   | "FocalPlaneXResolution"     | **Read/Write capability**: readable and writable<br> Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit.|
| FOCAL_PLANE_Y_RESOLUTION <sup>12+</sup>   | "FocalPlaneYResolution"     | **Read/Write capability**: readable and writable<br> Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit.|
| FOCAL_PLANE_RESOLUTION_UNIT <sup>12+</sup> | "FocalPlaneResolutionUnit"  | **Read/Write capability**: readable and writable<br> Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.|
| SUBJECT_LOCATION <sup>12+</sup>           | "SubjectLocation"           | **Read/Write capability**: readable and writable<br> Location of the main subject relative to the left edge.|
| EXPOSURE_INDEX <sup>12+</sup>             | "ExposureIndex"             | **Read/Write capability**: readable and writable<br> Exposure index selected at the time the image is captured.|
| SENSING_METHOD <sup>12+</sup>             | "SensingMethod"             | **Read/Write capability**: readable and writable<br> Type of the image sensor on the camera.|
| FILE_SOURCE <sup>12+</sup>                | "FileSource"                | **Read/Write capability**: readable and writable<br> Image source.|
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                 | **Read/Write capability**: readable and writable<br> Type of the scene, for example, portrait, scenery, motion, and night.|
| CFA_PATTERN <sup>12+</sup>                | "CFAPattern"                | **Read/Write capability**: readable and writable<br> Color Filter Array (CFA) geometric pattern of the image sensor.|
| CUSTOM_RENDERED <sup>12+</sup>            | "CustomRendered"            | **Read/Write capability**: readable and writable<br> Special processing on image data.|
| EXPOSURE_MODE <sup>12+</sup>              | "ExposureMode"              | **Read/Write capability**: readable and writable<br> Exposure mode set when the image was captured.|
| WHITE_BALANCE <sup>10+</sup>              | "WhiteBalance"              | **Read/Write capability**: readable and writable<br> White balance.|
| DIGITAL_ZOOM_RATIO <sup>12+</sup>         | "DigitalZoomRatio"          | **Read/Write capability**: readable and writable<br> Digital zoom ratio when the image was captured.|
| FOCAL_LENGTH_IN_35_MM_FILM <sup>10+</sup> | "FocalLengthIn35mmFilm"     | **Read/Write capability**: readable and writable<br> Focal length in 35mm film.|
| SCENE_CAPTURE_TYPE <sup>12+</sup>         | "SceneCaptureType"          | **Read/Write capability**: readable and writable<br> Type of the scene that was captured.|
| GAIN_CONTROL <sup>12+</sup>               | "GainControl"               | **Read/Write capability**: readable and writable<br> Degree of overall image gain adjustment.|
| CONTRAST <sup>12+</sup>                   | "Contrast"                  | **Read/Write capability**: readable and writable<br> Direction of contrast processing used by the camera.|
| SATURATION <sup>12+</sup>                 | "Saturation"                | **Read/Write capability**: readable and writable<br> Direction of saturation processing used by the camera.|
| SHARPNESS <sup>12+</sup>                  | "Sharpness"                 | **Read/Write capability**: readable and writable<br> Direction of sharpness processing used by the camera.|
| DEVICE_SETTING_DESCRIPTION <sup>12+</sup> | "DeviceSettingDescription"  | **Read/Write capability**: readable and writable<br> Information about the photographing conditions of a specific camera model.|
| SUBJECT_DISTANCE_RANGE <sup>12+</sup>     | "SubjectDistanceRange"      | **Read/Write capability**: readable and writable<br> Distance to the subject.|
| IMAGE_UNIQUE_ID <sup>12+</sup>            | "ImageUniqueID"             | **Read/Write capability**: readable and writable<br> Unique identifier assigned to each image.|
| CAMERA_OWNER_NAME <sup>12+</sup>          | "CameraOwnerName"           | **Read/Write capability**: readable and writable<br> Name of the camera owner.|
| BODY_SERIAL_NUMBER <sup>12+</sup>         | "BodySerialNumber"          | **Read/Write capability**: readable and writable<br> Serial number of the camera body.|
| LENS_SPECIFICATION <sup>12+</sup>         | "LensSpecification"         | **Read/Write capability**: readable and writable<br> Specifications of the lens.|
| LENS_MAKE <sup>12+</sup>                  | "LensMake"                  | **Read/Write capability**: readable and writable<br> Manufacturer of the lens.|
| LENS_MODEL <sup>12+</sup>                 | "LensModel"                 | **Read/Write capability**: readable and writable<br> Model of the lens.|
| LENS_SERIAL_NUMBER <sup>12+</sup>         | "LensSerialNumber"          | **Read/Write capability**: readable and writable<br> Serial number of the lens.|
| COMPOSITE_IMAGE <sup>12+</sup>            | "CompositeImage"            | **Read/Write capability**: readable and writable<br> Whether the image is a composite image.|
| SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE <sup>12+</sup>   | "SourceImageNumberOfCompositeImage"       | **Read/Write capability**: readable and writable<br> Number of source images of the composite image.|
| SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE <sup>12+</sup> | "SourceExposureTimesOfCompositeImage"     | **Read/Write capability**: readable and writable<br> Exposure time of source images of the composite image.|
| GAMMA <sup>12+</sup>                      | "Gamma"                     | **Read/Write capability**: readable and writable<br> Gamma value.|
| DNG_VERSION <sup>12+</sup>                | "DNGVersion"                | **Read/Write capability**: readable and writable<br> DNG version. It encodes the DNG 4-tier version number.|
| DEFAULT_CROP_SIZE <sup>12+</sup>          | "DefaultCropSize"           | **Read/Write capability**: readable and writable<br> Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image.|
| GIF_LOOP_COUNT <sup>12+</sup>             | "GIFLoopCount"              | **Read/Write capability**: read-only<br> Number of GIF loops. The value **0** means an infinite loop, and other values means the number of loops.|
| IS_XMAGE_SUPPORTED <sup>12+</sup> | "HwMnoteIsXmageSupported" | **Read/Write capability**: readable and writable<br>Whether XMAGE is supported.|
| XMAGE_MODE <sup>12+</sup> | "HwMnoteXmageMode" | **Read/Write capability**: readable and writable<br>XMAGE watermark mode.|
| XMAGE_LEFT <sup>12+</sup> | "HwMnoteXmageLeft" | **Read/Write capability**: readable and writable<br>X1 coordinate of the watermark region.|
| XMAGE_TOP <sup>12+</sup> | "HwMnoteXmageTop" | **Read/Write capability**: readable and writable<br>Y1 coordinate of the watermark region.|
| XMAGE_RIGHT <sup>12+</sup> | "HwMnoteXmageRight" | **Read/Write capability**: readable and writable<br>X2 coordinate of the watermark region.|
| XMAGE_BOTTOM <sup>12+</sup> | "HwMnoteXmageBottom" | **Read/Write capability**: readable and writable<br>Y2 coordinate of the watermark region.|
| CLOUD_ENHANCEMENT_MODE <sup>12+</sup> | "HwMnoteCloudEnhancementMode" | **Read/Write capability**: readable and writable<br>Cloud enhancement mode.|
| WIND_SNAPSHOT_MODE <sup>12+</sup> | "HwMnoteWindSnapshotMode" | **Read/Write capability**: read-only<br>Motion snapshot mode.|

## FragmentMapPropertyKey<sup>13+</sup>

Enumerates the fragment map information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value                   | Description                               |
| ------------- | --------------------- | ----------------------------------- |
| X_IN_ORIGINAL | "XInOriginal"         | X coordinate of the upper left corner of the fragment map in the original image.|
| Y_IN_ORIGINAL | "YInOriginal"         | Y coordinate of the upper left corner of the fragment map in the original image.|
| WIDTH         | "FragmentImageWidth"  | Width of the fragment map.                   |
| HEIGHT        | "FragmentImageHeight" | Height of the fragment map.                   |

## GifPropertyKey<sup>20+</sup>

Enumerates the GIF image information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value               | Description                  |
| ----------------- | ----------------- | --------------------- |
| GIF_DELAY_TIME    | "GifDelayTime"    | Duration for playing each frame of a GIF image, in milliseconds.|
| GIF_DISPOSAL_TYPE | "GifDisposalType" | Disposal type of each frame in a GIF image.|

## ImageFormat<sup>9+</sup>

Enumerates the image formats.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        |   Value  | Description                |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422 semi-planar format.|
| JPEG         | 2000   | JPEG encoding format.      |

## ComponentType<sup>9+</sup>

Enumerates the color component types of images.

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

Enumerates the order of cropping and scaling.

If the **cropAndScaleStrategy** parameter is not specified in [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) and both **desiredRegion** and **desiredSize** are set, the final decoding result may vary slightly due to differences in decoding algorithms used for different image formats.

For example, if the original image size is 200x200, and you specify **desiredSize:{width: 150, height: 150}, desiredRegion:{x: 0, y: 0, width: 100, height: 100}**, the expectation is to decode the top-left 1/4 region of the original image and then scale the pixelMap size to 150x150.

For JPEG and WebP images (as well as some DNG images that decode a JPEG preview within the file and therefore are treated as JPEG format), the system first performs downsampling. For instance, it might downsample by 7/8 and then crop the region based on a 175x175 image size. As a result, the final cropped region will be slightly larger than the top-left 1/4 of the original image.

For SVG images, which are vector-based and can be scaled without losing clarity, the system scales the image based on the ratio of **desiredSize** to the original image size and then crops the region. This results in a decoded region that may differ from the exact 1/4 region of the original image.

To ensure consistent results when both **desiredRegion** and **desiredSize** are set, set the **cropAndScaleStrategy** parameter to **CROP_FIRST**.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| SCALE_FIRST   | 1    | If both **desiredRegion** and **desiredSize** are specified, the image is first scaled based on **desiredSize** and then cropped based on **desiredRegion**.    |
| CROP_FIRST    | 2    | If both **desiredRegion** and **desiredSize** are specified, the image is first cropped based on **desiredRegion** and then scaled based on **desiredSize**.    |

## HdrMetadataKey<sup>12+</sup>

Enumerates the keys of HDR metadata used by [pixelmap](arkts-apis-image-PixelMap.md).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| HDR_METADATA_TYPE    | 0    | Metadata type used by [pixelmap](arkts-apis-image-PixelMap.md). |
| HDR_STATIC_METADATA  | 1    | Static metadata.  |
| HDR_DYNAMIC_METADATA | 2    | Dynamic metadata.  |
| HDR_GAINMAP_METADATA | 3    | Metadata used by gain maps.  |

## HdrMetadataType<sup>12+</sup>

Enumerates the values available for **HDR_METADATA_TYPE** in [HdrMetadataKey](#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| NONE     | 0    | No metadata. |
| BASE     | 1    | Metadata used for base graphics.  |
| GAINMAP  | 2    | Metadata used for gain maps.  |
| ALTERNATE| 3    | Metadata used for synthesized HDR graphics.  |

## AntiAliasingLevel<sup>12+</sup>

Enumerates the anti-aliasing levels.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| NONE                | 0      | Nearest neighbor interpolation.  |
| LOW                 | 1      | Bilinear interpolation.  |
| MEDIUM              | 2      | Bilinear interpolation with mipmap enabled. You are advised to use this value when zooming out an image.  |
| HIGH                | 3      | Cubic interpolation.  |

## AllocatorType<sup>15+</sup>

Enumerates the types of the memory used for image decoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        | Value  | Description                              |
| ------------ | ---- | ---------------------------------- |
| AUTO         | 0    | The system determines whether DMA memory or shared memory is used.    |
| DMA          | 1    | DMA memory is used.           |
| SHARE_MEMORY | 2    | Shared memory is used.|
