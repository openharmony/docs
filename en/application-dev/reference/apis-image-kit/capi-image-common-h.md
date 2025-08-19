# image_common.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The file declares the common enums and structs used by the image interface.

**File to include**: <multimedia/image_framework/image/image_common.h>

**Library**: libimage_common.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Image_Size](capi-image-nativemodule-image-size.md) | Image_Size | Describes the image size.|
| [Image_Region](capi-image-nativemodule-image-region.md) | Image_Region | Describes the region of an image to decode.|
| [Image_String](capi-image-nativemodule-image-string.md) | Image_String/Image_MimeType | Describes an image string.<br>**Image_String**: describes an image string.<br>**Image_MimeType**: describes an image format type.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) | OH_PictureMetadata | Describes the picture metadata.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Image_ErrorCode](#image_errorcode) | Image_ErrorCode | Enumerates the error codes.|
| [Image_MetadataType](#image_metadatatype) | Image_MetadataType | Enumerates the metadata types.|
| [IMAGE_ALLOCATOR_MODE](#image_allocator_mode) | IMAGE_ALLOCATOR_MODE | Enumerates the types of memory allocation for a PixelMap.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_PictureMetadata_Create(Image_MetadataType metadataType, OH_PictureMetadata **metadata)](#oh_picturemetadata_create) | Creates the pointer to an OH_PictureMetadata struct.|
| [Image_ErrorCode OH_PictureMetadata_GetProperty(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)](#oh_picturemetadata_getproperty) | Obtains a property of metadata based on the key.|
| [Image_ErrorCode OH_PictureMetadata_SetProperty(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)](#oh_picturemetadata_setproperty) | Sets a property of metadata based on the key.|
| [Image_ErrorCode OH_PictureMetadata_GetPropertyWithNull(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)](#oh_picturemetadata_getpropertywithnull) | Obtains the metadata value of an OH_PictureMetadata instance. The output **value.data** is terminated with a string terminator.|
| [Image_ErrorCode OH_PictureMetadata_Release(OH_PictureMetadata *metadata)](#oh_picturemetadata_release) | Releases the pointer to an OH_PictureMetadata struct.|
| [Image_ErrorCode OH_PictureMetadata_Clone(OH_PictureMetadata *oldMetadata, OH_PictureMetadata **newMetadata)](#oh_picturemetadata_clone) | Clones metadata.|

### Variables

| Name| Description|
| -- | -- |
| static const char* MIME_TYPE_BMP = "image/bmp" | BMP image format.<br>**Since**: 12|
| static const char* MIME_TYPE_JPEG = "image/jpeg" | JPEG image format.<br>**Since**: 12|
| static const char* MIME_TYPE_HEIC = "image/heic" | HEIC image format.<br>**Since**: 12|
| static const char* MIME_TYPE_PNG = "image/png" | PNG image format.<br>**Since**: 12|
| static const char* MIME_TYPE_WEBP = "image/webp" | WebP image format.<br>**Since**: 12|
| static const char* MIME_TYPE_GIF = "image/gif" | GIF image format.<br>**Since**: 12|
| static const char* MIME_TYPE_ICON = "image/x-icon" | ICO image format.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample" | Number of bits per sample.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation" | Image orientation.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength" | Image length.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth" | Image width.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude" | Image latitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude" | Image longitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef" | Whether the latitude is north or south latitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef" | Whether the longitude is east or west longitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal" | Shooting time, for example, 2022:09:06 15:48:00.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime" | Exposure time, for example, 1/33 seconds.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType" | Type of the scene, for example, portrait, scenery, motion, and night.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings" | ISO sensitivity or ISO speed, for example, 400.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber" | F number, for example, f/1.8.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel" | Number of bits per pixel. It is specific to compressed data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_COMPRESSION = "Compression" | Compression scheme used on the image data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION = "PhotometricInterpretation" | Color space of the image data, for example, RGB or YCbCr.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_STRIP_OFFSETS = "StripOffsets" | Byte offset of each strip.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL = "SamplesPerPixel" | Number of components per pixel. The value is **3** for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP = "RowsPerStrip" | Number of rows per strip.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS = "StripByteCounts" | Number of bytes in each strip after compression.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_X_RESOLUTION = "XResolution" | Number of pixels per ResolutionUnit in the image width (X) direction.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_Y_RESOLUTION = "YResolution" | Number of pixels per ResolutionUnit in the image height (Y) direction.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION = "PlanarConfiguration" | Storage format of components of each pixel, which can be chunky or planar.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT = "ResolutionUnit" | Unit of measurement for XResolution and YResolution.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION = "TransferFunction" | Transfer function for the image, which is usually used for color correction.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SOFTWARE = "Software" | Name and version number of the software used to create the image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_ARTIST = "Artist" | Person who created the image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_WHITE_POINT = "WhitePoint" | Chromaticity of the white point of the image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES = "PrimaryChromaticities" | Chromaticities of the primaries of the image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS = "YCbCrCoefficients" | Transformation from RGB to YCbCr image data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING = "YCbCrSubSampling" | Subsampling factors used for the chrominance components of a YCbCr image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING = "YCbCrPositioning" | Positioning of subsampled chrominance components relative to luminance samples.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE = "ReferenceBlackWhite" | A pair of headroom and footroom image data values (codes) for each pixel component.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_COPYRIGHT = "Copyright" | Copyright notice of the image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT = "JPEGInterchangeFormat" | Offset of the SOI marker of a JPEG interchange format bitstream.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH = "JPEGInterchangeFormatLength" | Number of bytes of the JPEG stream.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM = "ExposureProgram" | Class of the program used by the camera to set exposure when the image was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY = "SpectralSensitivity" | Spectral sensitivity of each channel of the camera.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_OECF = "OECF" | Opto-Electric Conversion Function (OECF) specified in ISO 14524.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_EXIF_VERSION = "ExifVersion" | Version of the supported EXIF standard.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED = "DateTimeDigitized" | Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:MM:SS.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION = "ComponentsConfiguration" | Specific information about compressed data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE = "ShutterSpeedValue" | Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE = "BrightnessValue" | Value of brightness, expressed in APEX values.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE = "MaxApertureValue" | Smallest F number of the lens.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE = "SubjectDistance" | Distance to the subject, in meters.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBJECT_AREA = "SubjectArea" | Location and area of the main subject in the entire scene.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_MAKER_NOTE = "MakerNote" | Marker used by EXIF/DCF manufacturers to record any required information.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME = "SubsecTime" | Tag used to record fractions of seconds for the **DateTime** tag.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL = "SubsecTimeOriginal" | Tag used to record fractions of seconds for the **DateTimeOriginal** tag.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED = "SubsecTimeDigitized" | Tag used to record fractions of seconds for the **DateTimeDigitized** tag.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION = "FlashpixVersion" | FlashPix format version supported by an FPXR file. It is used to enhance device compatibility.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_COLOR_SPACE = "ColorSpace" | Color space information, which is usually recorded as a color space specifier.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE = "RelatedSoundFile" | Name of an audio file related to the image data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FLASH_ENERGY = "FlashEnergy" | Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS).<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE = "SpatialFrequencyResponse" | Spatial frequency table of the camera or input device.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION = "FocalPlaneXResolution" | Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION = "FocalPlaneYResolution" | Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT = "FocalPlaneResolutionUnit" | Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION = "SubjectLocation" | Location of the main subject relative to the left edge.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX = "ExposureIndex" | Exposure index selected at the time the image is captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SENSING_METHOD = "SensingMethod" | Type of the image sensor on the camera.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FILE_SOURCE = "FileSource" | Image source.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_CFA_PATTERN = "CFAPattern" | Color Filter Array (CFA) geometric pattern of the image sensor.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED = "CustomRendered" | Special processing on image data.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_MODE = "ExposureMode" | Exposure mode set when the image was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO = "DigitalZoomRatio" | Digital zoom ratio when the image was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE = "SceneCaptureType" | Type of the scene that was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GAIN_CONTROL = "GainControl" | Degree of overall image gain adjustment.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_CONTRAST = "Contrast" | Direction of contrast processing used by the camera.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SATURATION = "Saturation" | Direction of saturation processing used by the camera.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SHARPNESS = "Sharpness" | Direction of sharpness processing used by the camera.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION = "DeviceSettingDescription" | Information about the photographing conditions of a specific camera model.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE = "SubjectDistanceRange" | Distance to the subject.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID = "ImageUniqueID" | Unique identifier assigned to each image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_VERSION_ID = "GPSVersionID" | Version of GPSInfoIFD.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF = "GPSAltitudeRef" | Whether the latitude is north or south latitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE = "GPSAltitude" | Altitude based on the reference in GPSAltitudeRef.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_SATELLITES = "GPSSatellites" | GPS satellites used for measurement.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_STATUS = "GPSStatus" | Status of the GPS receiver when the image was recorded.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE = "GPSMeasureMode" | GPS measurement pmode.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DOP = "GPSDOP" | GPS DOP (data degree of precision)<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_SPEED_REF = "GPSSpeedRef" | Unit used to express the movement speed of the GPS receiver.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_SPEED = "GPSSpeed" | Movement speed of the GPS receiver.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_TRACK_REF = "GPSTrackRef" | Reference of the movement direction of the GPS receiver.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_TRACK = "GPSTrack" | Movement direction of the GPS receiver.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF = "GPSImgDirectionRef" | Reference of the direction of the image when it was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION = "GPSImgDirection" | Direction of the image when it was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM = "GPSMapDatum" | Geodetic survey data used by the GPS receiver.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF = "GPSDestLatitudeRef" | Whether the latitude of the destination point is north or south latitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE = "GPSDestLatitude" | Latitude of the destination point.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF = "GPSDestLongitudeRef" | Whether the longitude of the destination point is east or west longitude.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD = "GPSProcessingMethod" | String that records the name of the method used for positioning.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION = "GPSAreaInformation" | String that records the name of the GPS area.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL = "GPSDifferential" | Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER = "BodySerialNumber" | Serial number of the camera body.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME = "CameraOwnerName" | Name of the camera owner.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE = "CompositeImage" | Whether the image is a composite image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_DNG_VERSION = "DNGVersion" | DNG version. It encodes the DNG 4-tier version number.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE = "GPSDestLongitude" | Longitude of the destination point.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF = "GPSDestBearingRef" | Reference of the bearing to the destination point.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING = "GPSDestBearing" | Bearing to the destination point.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF = "GPSDestDistanceRef" | Unit used to express the distance to the destination point.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE = "GPSDestDistance" | Distance to the destination point.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE = "DefaultCropSize" | Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GAMMA = "Gamma" | Gamma value.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY = "ISOSpeedLatitudeyyy" | ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ = "ISOSpeedLatitudezzz" | ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_LENS_MAKE = "LensMake" | Manufacturer of the lens.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_LENS_MODEL = "LensModel" | Model of the lens.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER = "LensSerialNumber" | Serial number of the lens.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION = "LensSpecification" | Specifications of the lens.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE = "NewSubfileType" | Data type of a subfile, such as a full-resolution image, a thumbnail, or a part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME = "OffsetTime" | Time with an offset from UTC when the image was captured, in the format of ±HH:MM.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED = "OffsetTimeDigitized" | Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL = "OffsetTimeOriginal" | Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE = "SourceExposureTimesOfCompositeImage" | Exposure time of source images of the composite image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE = "SourceImageNumberOfCompositeImage" | Number of source images of the composite image.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SUBFILE_TYPE = "SubfileType" | Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR = "GPSHPositioningError" | Horizontal positioning error, in meters.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY = "PhotographicSensitivity" | Sensitivity of the camera or input device when the image was captured.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_BURST_NUMBER = "HwMnoteBurstNumber" | Number of burst shooting times.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_CONF = "HwMnoteFaceConf" | Face confidence.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER = "HwMnoteFaceLeyeCenter" | Left eye centered.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER = "HwMnoteFaceMouthCenter" | Mouth centered.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_POINTER = "HwMnoteFacePointer" | Face pointer.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_RECT = "HwMnoteFaceRect" | Face rectangle.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER = "HwMnoteFaceReyeCenter" | Right eye centered.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE = "HwMnoteFaceSmileScore" | Smile score of for faces.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FACE_VERSION = "HwMnoteFaceVersion" | Facial recognition algorithm version.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_FRONT_CAMERA = "HwMnoteFrontCamera" | Whether the front camera is used to take a selfie.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SCENE_POINTER = "HwMnoteScenePointer" | Pointer to the scene.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_SCENE_VERSION = "HwMnoteSceneVersion" | Scene algorithm version.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_IS_XMAGE_SUPPORTED = "HwMnoteIsXmageSupported" | Whether XMAGE is supported.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_XMAGE_MODE = "HwMnoteXmageMode" | XMAGE watermark mode.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_XMAGE_LEFT = "HwMnoteXmageLeft" | X1 coordinate of the watermark region.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_XMAGE_TOP = "HwMnoteXmageTop" | Y1 coordinate of the watermark region.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_XMAGE_RIGHT = "HwMnoteXmageRight" | X2 coordinate of the watermark region.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_XMAGE_BOTTOM = "HwMnoteXmageBottom" | Y2 coordinate of the watermark region.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_CLOUD_ENHANCEMENT_MODE = "HwMnoteCloudEnhancementMode" | Cloud enhancement mode.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_WIND_SNAPSHOT_MODE = "HwMnoteWindSnapshotMode" | Motion snapshot mode.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT = "GIFLoopCount" | Number of GIF loops.<br>**Since**: 12|
| static const char* OHOS_IMAGE_PROPERTY_X_IN_ORIGINAL = "XInOriginal" | X coordinate of the upper left corner of the fragment map in the original image.<br>**Since**: 13|
| static const char* OHOS_IMAGE_PROPERTY_Y_IN_ORIGINAL = "YInOriginal" | Y coordinate of the upper left corner of the fragment map in the original image.<br>**Since**: 13|
| static const char* OHOS_IMAGE_PROPERTY_FRAGMENT_WIDTH = "FragmentImageWidth" | Width of the fragment map.<br>**Since**: 13|
| static const char* OHOS_IMAGE_PROPERTY_FRAGMENT_HEIGHT = "FragmentImageHeight" | Height of the fragment map.<br>**Since**: 13|
| static const char* IMAGE_PROPERTY_GIF_DELAY_TIME = "GifDelayTime" | Duration for playing each frame of a GIF image, in milliseconds.<br>**Since**: 20|
| static const char* IMAGE_PROPERTY_GIF_DISPOSAL_TYPE = "GifDisposalType" | Disposal type of each frame in a GIF image.<br>**Since**: 20|

## Enum Description

### Image_ErrorCode

```
enum Image_ErrorCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| IMAGE_SUCCESS = 0 | Operation successful.|
| IMAGE_BAD_PARAMETER = 401 | Invalid parameter.|
| IMAGE_UNSUPPORTED_MIME_TYPE = 7600101 | Unsupported MIME type.|
| IMAGE_UNKNOWN_MIME_TYPE = 7600102 | Unknown MIME type.|
| IMAGE_TOO_LARGE = 7600103 | The data or image is too large.|
| IMAGE_DMA_NOT_EXIST = 7600173 | The memory is not the DMA memory.|
| IMAGE_DMA_OPERATION_FAILED = 7600174 | The operation on the DMA memory fails.|
| IMAGE_UNSUPPORTED_OPERATION = 7600201 | Unsupported operation.|
| IMAGE_UNSUPPORTED_METADATA = 7600202 | Unsupported metadata.|
| IMAGE_UNSUPPORTED_CONVERSION = 7600203 | Unsupported conversion.|
| IMAGE_INVALID_REGION = 7600204 | Invalid region.|
| IMAGE_UNSUPPORTED_MEMORY_FORMAT = 7600205 |  The memory format is not supported.<br>**Since**: 13|
| IMAGE_ALLOC_FAILED = 7600301 | Failed to allocate the memory.|
| IMAGE_COPY_FAILED = 7600302 | Failed to copy the memory.|
| IMAGE_LOCK_UNLOCK_FAILED = 7600303 |  Failed to lock or unlock the memory.<br>**Since**: 15|
| IMAGE_ALLOCATOR_MODE_UNSUPPORTED = 7600501 |  The memory allocator type is not supported, for example, creating HDR images using shared memory.<br> DMA memory supports HDR metadata.<br>**Since**: 20|
| IMAGE_UNKNOWN_ERROR = 7600901 | Unknown error.|
| IMAGE_BAD_SOURCE = 7700101 | Abnormal data source.|
| IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE = 7700102 |  Unsupported MIME type during image decoding.<br>**Since**: 15|
| IMAGE_SOURCE_TOO_LARGE = 7700103 |  The image is too large.<br>**Since**: 15|
| IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE = 7700201 |  The allocator type is not supported. For example, decoding HDR images using shared memory is unsupported because only DMA supports HDR metadata.<br>**Since**: 15|
| IMAGE_SOURCE_UNSUPPORTED_OPTIONS = 7700203 |  Unsupported options. For example, an image cannot be converted into the required pixel format.<br>**Since**: 15|
| IMAGE_SOURCE_INVALID_PARAMETER = 7700204 |  Invalid **ImageSource** parameter.<br>**Since**: 19|
| IMAGE_DECODE_FAILED = 7700301 | Decoding failed.|
| IMAGE_SOURCE_ALLOC_FAILED = 7700302 |  Memory allocation failed.<br>**Since**: 15|
| IMAGE_PACKER_INVALID_PARAMETER = 7800202 |  Invalid **ImagePacker** parameter.<br>**Since**: 19|
| IMAGE_ENCODE_FAILED = 7800301 | Encoding failed.|
| IMAGE_RECEIVER_INVALID_PARAMETER = 7900201 |  Invalid **ImageReceiver** parameter.<br>**Since**: 20|

### Image_MetadataType

```
enum Image_MetadataType
```

**Description**

Enumerates the metadata types.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| EXIF_METADATA = 1 | EXIF metadata.|
| FRAGMENT_METADATA = 2 | Fragment map metadata.|
| GIF_METADATA = 5 | GIF image metadata.<br>**Since**: 20|

### IMAGE_ALLOCATOR_MODE

```
enum IMAGE_ALLOCATOR_MODE
```

**Description**

Enumerates the types of memory allocation for a PixelMap.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| IMAGE_ALLOCATOR_MODE_AUTO = 0 | The system determines the type of memory to allocate when creating a PixelMap.|
| IMAGE_ALLOCATOR_MODE_DMA = 1 | Allocates a DMA-type memory buffer.|
| IMAGE_ALLOCATOR_MODE_DMA = 2 | Uses shared memory to create a PixelMap.|


## Function Description

### OH_PictureMetadata_Create()

```
Image_ErrorCode OH_PictureMetadata_Create(Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```

**Description**

Creates the pointer to an OH_PictureMetadata struct.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [Image_MetadataType](#image_metadatatype) metadataType | Metadata type.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) **metadata | Double pointer to the OH_PictureMetadata struct created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureMetadata_GetProperty()

```
Image_ErrorCode OH_PictureMetadata_GetProperty(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)
```

**Description**

Obtains a property of metadata based on the key.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *metadata | Pointer to an OH_PictureMetadata struct.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the key of the property.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the value of the property.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_METADATA**: The metadata type is not supported, or the metadata type and the auxiliary picture type do not match.|

### OH_PictureMetadata_SetProperty()

```
Image_ErrorCode OH_PictureMetadata_SetProperty(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)
```

**Description**

Sets a property of metadata based on the key.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *metadata | Pointer to an OH_PictureMetadata struct.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the key of the property.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the value of the property.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_METADATA**: The metadata type is not supported, or the metadata type and the auxiliary picture type do not match.|

### OH_PictureMetadata_GetPropertyWithNull()

```
Image_ErrorCode OH_PictureMetadata_GetPropertyWithNull(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)
```

**Description**

Obtains the metadata value of an OH_PictureMetadata instance. The output **value.data** is terminated with a string terminator.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *metadata | Pointer to an OH_PictureMetadata struct.|
| [Image_String](capi-image-nativemodule-image-string.md) *key | Pointer to the key of the property.|
| [Image_String](capi-image-nativemodule-image-string.md) *value | Pointer to the value of the property.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: The **metadata**, **key**, or **value** parameter is a null pointer.<br>         **IMAGE_UNSUPPORTED_METADATA**: The metadata type is not supported, or the metadata type and the auxiliary picture type do not match.|

### OH_PictureMetadata_Release()

```
Image_ErrorCode OH_PictureMetadata_Release(OH_PictureMetadata *metadata)
```

**Description**

Releases the pointer to an OH_PictureMetadata struct.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *metadata | Pointer to an OH_PictureMetadata struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PictureMetadata_Clone()

```
Image_ErrorCode OH_PictureMetadata_Clone(OH_PictureMetadata *oldMetadata, OH_PictureMetadata **newMetadata)
```

**Description**

Clones metadata.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) *oldMetadata | Pointer to an OH_PictureMetadata struct.|
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) **newMetadata | Double pointer to the OH_PictureMetadata struct obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_ALLOC_FAILED**: The memory allocation fails.<br>         **IMAGE_COPY_FAILED**: The memory copy fails.|
