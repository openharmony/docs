# image_common.h


## Overview

The **image_common.h** file declares the common enums and structs used by the image interface.

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [Image_Size](_image___size.md) | Describes the image size.| 
| struct  [Image_Region](_image___region.md) | Describes the region of an image to decode.| 
| struct  [Image_String](_image___string.md) | Describes an image string.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Image_Size](_image___size.md) [Image_Size](_image___native_module.md#image_size) | Defines a struct for the image size.| 
| typedef struct [Image_Region](_image___region.md) [Image_Region](_image___native_module.md#image_region) | Defines a struct for the region of an image to decode.| 
| typedef struct [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) | Defines a struct for the picture metadata.| 
| typedef struct [Image_String](_image___string.md) [Image_String](_image___native_module.md#image_string) | Defines a struct for an image string.| 
| typedef struct [Image_String](_image___string.md) [Image_MimeType](_image___native_module.md#image_mimetype) | Defines a struct for an image format type.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) {<br>IMAGE_SUCCESS = 0,<br>IMAGE_BAD_PARAMETER = 401,<br>IMAGE_UNSUPPORTED_MIME_TYPE = 7600101,<br>IMAGE_UNKNOWN_MIME_TYPE = 7600102,<br>IMAGE_TOO_LARGE = 7600103,<br>IMAGE_DMA_NOT_EXIST = 7600173,<br>IMAGE_DMA_OPERATION_FAILED = 7600174,<br>IMAGE_UNSUPPORTED_OPERATION = 7600201,<br>IMAGE_UNSUPPORTED_METADATA = 7600202,<br>IMAGE_UNSUPPORTED_CONVERSION = 7600203,<br>IMAGE_INVALID_REGION = 7600204,<br>IMAGE_UNSUPPORTED_MEMORY_FORMAT = 7600205,<br>IMAGE_ALLOC_FAILED = 7600301,<br>IMAGE_COPY_FAILED = 7600302,<br>IMAGE_LOCK_UNLOCK_FAILED = 7600303,<br>IMAGE_UNKNOWN_ERROR = 7600901,<br>IMAGE_BAD_SOURCE = 7700101,<br>IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE = 7700102,<br>IMAGE_SOURCE_TOO_LARGE = 7700103,<br>IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE = 7700201,<br>IMAGE_SOURCE_UNSUPPORTED_OPTIONS = 7700203, <br>IMAGE_DECODE_FAILED = 7700301,<br>IMAGE_SOURCE_ALLOC_FAILED = 7700302,<br>IMAGE_ENCODE_FAILED = 7800301<br>} | Enumerates the error codes.| 
| [Image_MetadataType](_image___native_module.md#image_metadatatype) {<br>EXIF_METADATA = 1,<br>FRAGMENT_METADATA = 2<br>} | Enumerates the metadata types.| 


### Variables

| Name| Description| 
| -------- | -------- |
| static const char \*[MIME_TYPE_BMP](_image___native_module.md#mime_type_bmp) = "image/bmp" | BMP image format. | 
| static const char \*[MIME_TYPE_JPEG](_image___native_module.md#mime_type_jpeg) = "image/jpeg" | JPEG image format. | 
| static const char \*[MIME_TYPE_HEIC](_image___native_module.md#mime_type_heic) = "image/heic" | HEIC image format. | 
| static const char \*[MIME_TYPE_PNG](_image___native_module.md#mime_type_png) = "image/png" | PNG image format. | 
| static const char \*[MIME_TYPE_WEBP](_image___native_module.md#mime_type_webp) = "image/webp" | WebP image format. | 
| static const char \*[MIME_TYPE_GIF](_image___native_module.md#mime_type_gif) = "image/gif" | GIF image format. | 
| static const char \*[MIME_TYPE_ICON](_image___native_module.md#mime_type_icon) = "image/x-icon" | ICO image format. | 
| static const char \*[OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](_image___native_module.md#ohos_image_property_bits_per_sample) = "BitsPerSample" | Number of bits per sample. | 
| static const char \*[OHOS_IMAGE_PROPERTY_ORIENTATION](_image___native_module.md#ohos_image_property_orientation) = "Orientation" | Image orientation. | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](_image___native_module.md#ohos_image_property_image_length) = "ImageLength" | Image length. | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](_image___native_module.md#ohos_image_property_image_width) = "ImageWidth" | Image width. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE](_image___native_module.md#ohos_image_property_gps_latitude) = "GPSLatitude" | Image latitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](_image___native_module.md#ohos_image_property_gps_longitude) = "GPSLongitude" | Image longitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](_image___native_module.md#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | Whether the latitude is north or south latitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](_image___native_module.md#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | Whether the longitude is east or west longitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](_image___native_module.md#ohos_image_property_date_time_original) = "DateTimeOriginal" | Shooting time, for example, 2022:09:06 15:48:00. | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](_image___native_module.md#ohos_image_property_exposure_time) = "ExposureTime" | Exposure time, for example, 1/33 seconds. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_TYPE](_image___native_module.md#ohos_image_property_scene_type) = "SceneType" | Type of the scene, for example, portrait, scenery, motion, and night. | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](_image___native_module.md#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | ISO sensitivity or ISO speed, for example, 400. | 
| static const char \*[OHOS_IMAGE_PROPERTY_F_NUMBER](_image___native_module.md#ohos_image_property_f_number) = "FNumber" | F number, for example, f/1.8. | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](_image___native_module.md#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | Number of bits per pixel. It is specific to compressed data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSION](_image___native_module.md#ohos_image_property_compression) = "Compression" | Compression scheme used on the image data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION](_image___native_module.md#ohos_image_property_photometric_interpretation) = "PhotometricInterpretation" | Color space of the image data, for example, RGB or YCbCr. | 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_OFFSETS](_image___native_module.md#ohos_image_property_strip_offsets) = "StripOffsets" | Byte offset of each strip. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL](_image___native_module.md#ohos_image_property_samples_per_pixel) = "SamplesPerPixel" | Number of components per pixel. The value is **3** for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP](_image___native_module.md#ohos_image_property_rows_per_strip) = "RowsPerStrip" | Number of rows per strip. | 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS](_image___native_module.md#ohos_image_property_strip_byte_counts) = "StripByteCounts" | Number of bytes in each strip after compression. | 
| static const char \*[OHOS_IMAGE_PROPERTY_X_RESOLUTION](_image___native_module.md#ohos_image_property_x_resolution) = "XResolution" | Number of pixels per ResolutionUnit in the image width (X) direction. | 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_RESOLUTION](_image___native_module.md#ohos_image_property_y_resolution) = "YResolution" | Number of pixels per ResolutionUnit in the image height (Y) direction. | 
| static const char \*[OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION](_image___native_module.md#ohos_image_property_planar_configuration) = "PlanarConfiguration" | Storage format of components of each pixel, which can be chunky or planar. | 
| static const char \*[OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT](_image___native_module.md#ohos_image_property_resolution_unit) = "ResolutionUnit" | Unit of measurement for XResolution and YResolution. | 
| static const char \*[OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION](_image___native_module.md#ohos_image_property_transfer_function) = "TransferFunction" | Transfer function for the image, which is usually used for color correction. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOFTWARE](_image___native_module.md#ohos_image_property_software) = "Software" | Name and version number of the software used to create the image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_ARTIST](_image___native_module.md#ohos_image_property_artist) = "Artist" | Person who created the image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_WHITE_POINT](_image___native_module.md#ohos_image_property_white_point) = "WhitePoint" | Chromaticity of the white point of the image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES](_image___native_module.md#ohos_image_property_primary_chromaticities) = "PrimaryChromaticities" | Chromaticities of the primaries of the image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS](_image___native_module.md#ohos_image_property_ycbcr_coefficients) = "YCbCrCoefficients" | Transformation from RGB to YCbCr image data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING](_image___native_module.md#ohos_image_property_ycbcr_sub_sampling) = "YCbCrSubSampling" | Subsampling factors used for the chrominance components of a YCbCr image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING](_image___native_module.md#ohos_image_property_ycbcr_positioning) = "YCbCrPositioning" | Positioning of subsampled chrominance components relative to luminance samples. | 
| static const char \*[OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE](_image___native_module.md#ohos_image_property_reference_black_white) = "ReferenceBlackWhite" | A pair of headroom and footroom image data values (codes) for each pixel component. | 
| static const char \*[OHOS_IMAGE_PROPERTY_COPYRIGHT](_image___native_module.md#ohos_image_property_copyright) = "Copyright" | Copyright notice of the image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT](_image___native_module.md#ohos_image_property_jpeg_interchange_format) = "JPEGInterchangeFormat" | Offset of the SOI marker of a JPEG interchange format bitstream. | 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH](_image___native_module.md#ohos_image_property_jpeg_interchange_format_length) = "JPEGInterchangeFormatLength" | Number of bytes of the JPEG stream. | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM](_image___native_module.md#ohos_image_property_exposure_program) = "ExposureProgram" | Class of the program used by the camera to set exposure when the image was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY](_image___native_module.md#ohos_image_property_spectral_sensitivity) = "SpectralSensitivity" | Spectral sensitivity of each channel of the camera. | 
| static const char \*[OHOS_IMAGE_PROPERTY_OECF](_image___native_module.md#ohos_image_property_oecf) = "OECF" | Opto-Electric Conversion Function (OECF) specified in ISO 14524. | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXIF_VERSION](_image___native_module.md#ohos_image_property_exif_version) = "ExifVersion" | Version of the supported EXIF standard. | 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED](_image___native_module.md#ohos_image_property_date_time_digitized) = "DateTimeDigitized" | Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:MM:SS. | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION](_image___native_module.md#ohos_image_property_components_configuration) = "ComponentsConfiguration" | Specific information about compressed data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE](_image___native_module.md#ohos_image_property_shutter_speed_value) = "ShutterSpeedValue" | Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values. | 
| static const char \*[OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE](_image___native_module.md#ohos_image_property_brightness_value) = "BrightnessValue" | Value of brightness, expressed in APEX values. | 
| static const char \*[OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE](_image___native_module.md#ohos_image_property_max_aperture_value) = "MaxApertureValue" | Smallest F number of the lens. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE](_image___native_module.md#ohos_image_property_subject_distance) = "SubjectDistance" | Distance to the subject, in meters. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_AREA](_image___native_module.md#ohos_image_property_subject_area) = "SubjectArea" | Location and area of the main subject in the entire scene. | 
| static const char \*[OHOS_IMAGE_PROPERTY_MAKER_NOTE](_image___native_module.md#ohos_image_property_maker_note) = "MakerNote" | Marker used by EXIF/DCF manufacturers to record any required information. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME](_image___native_module.md#ohos_image_property_subsec_time) = "SubsecTime" | Tag used to record fractions of seconds for the **DateTime** tag. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL](_image___native_module.md#ohos_image_property_subsec_time_original) = "SubsecTimeOriginal" | Tag used to record fractions of seconds for the **DateTimeOriginal** tag. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED](_image___native_module.md#ohos_image_property_subsec_time_digitized) = "SubsecTimeDigitized" | Tag used to record fractions of seconds for the **DateTimeDigitized** tag. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION](_image___native_module.md#ohos_image_property_flashpix_version) = "FlashpixVersion" | FlashPix format version supported by an FPXR file. It is used to enhance device compatibility. | 
| static const char \*[OHOS_IMAGE_PROPERTY_COLOR_SPACE](_image___native_module.md#ohos_image_property_color_space) = "ColorSpace" | Color space information, which is usually recorded as a color space specifier. | 
| static const char \*[OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE](_image___native_module.md#ohos_image_property_related_sound_file) = "RelatedSoundFile" | Name of an audio file related to the image data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASH_ENERGY](_image___native_module.md#ohos_image_property_flash_energy) = "FlashEnergy" | Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS). | 
| static const char \*[OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE](_image___native_module.md#ohos_image_property_spatial_frequency_response) = "SpatialFrequencyResponse" | Spatial frequency table of the camera or input device. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION](_image___native_module.md#ohos_image_property_focal_plane_x_resolution) = "FocalPlaneXResolution" | Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION](_image___native_module.md#ohos_image_property_focal_plane_y_resolution) = "FocalPlaneYResolution" | Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT](_image___native_module.md#ohos_image_property_focal_plane_resolution_unit) = "FocalPlaneResolutionUnit" | Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION](_image___native_module.md#ohos_image_property_subject_location) = "SubjectLocation" | Location of the main subject relative to the left edge. | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX](_image___native_module.md#ohos_image_property_exposure_index) = "ExposureIndex" | Exposure index selected at the time the image is captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SENSING_METHOD](_image___native_module.md#ohos_image_property_sensing_method) = "SensingMethod" | Type of the image sensor on the camera. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FILE_SOURCE](_image___native_module.md#ohos_image_property_file_source) = "FileSource" | Image source. | 
| static const char \*[OHOS_IMAGE_PROPERTY_CFA_PATTERN](_image___native_module.md#ohos_image_property_cfa_pattern) = "CFAPattern" | Color Filter Array (CFA) geometric pattern of the image sensor. | 
| static const char \*[OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED](_image___native_module.md#ohos_image_property_custom_rendered) = "CustomRendered" | Special processing on image data. | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_MODE](_image___native_module.md#ohos_image_property_exposure_mode) = "ExposureMode" | Exposure mode set when the image was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO](_image___native_module.md#ohos_image_property_digital_zoom_ratio) = "DigitalZoomRatio" | Digital zoom ratio when the image was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE](_image___native_module.md#ohos_image_property_scene_capture_type) = "SceneCaptureType" | Type of the scene that was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GAIN_CONTROL](_image___native_module.md#ohos_image_property_gain_control) = "GainControl" | Degree of overall image gain adjustment. | 
| static const char \*[OHOS_IMAGE_PROPERTY_CONTRAST](_image___native_module.md#ohos_image_property_contrast) = "Contrast" | Direction of contrast processing used by the camera. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SATURATION](_image___native_module.md#ohos_image_property_saturation) = "Saturation" | Direction of saturation processing used by the camera. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SHARPNESS](_image___native_module.md#ohos_image_property_sharpness) = "Sharpness" | Direction of sharpness processing used by the camera. | 
| static const char \*[OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION](_image___native_module.md#ohos_image_property_device_setting_description) = "DeviceSettingDescription" | Information about the photographing conditions of a specific camera model. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE](_image___native_module.md#ohos_image_property_subject_distance_range) = "SubjectDistanceRange" | Distance to the subject. | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID](_image___native_module.md#ohos_image_property_image_unique_id) = "ImageUniqueID" | Unique identifier assigned to each image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_VERSION_ID](_image___native_module.md#ohos_image_property_gps_version_id) = "GPSVersionID" | Version of GPSInfoIFD. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF](_image___native_module.md#ohos_image_property_gps_altitude_ref) = "GPSAltitudeRef" | Whether the latitude is north or south latitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE](_image___native_module.md#ohos_image_property_gps_altitude) = "GPSAltitude" | Altitude based on the reference in GPSAltitudeRef. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SATELLITES](_image___native_module.md#ohos_image_property_gps_satellites) = "GPSSatellites" | GPS satellites used for measurement. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_STATUS](_image___native_module.md#ohos_image_property_gps_status) = "GPSStatus" | Status of the GPS receiver when the image was recorded. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE](_image___native_module.md#ohos_image_property_gps_measure_mode) = "GPSMeasureMode" | GPS measurement pmode. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DOP](_image___native_module.md#ohos_image_property_gps_dop) = "GPSDOP" | GPS DOP (data degree of precision) | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED_REF](_image___native_module.md#ohos_image_property_gps_speed_ref) = "GPSSpeedRef" | Unit used to express the movement speed of the GPS receiver. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED](_image___native_module.md#ohos_image_property_gps_speed) = "GPSSpeed" | Movement speed of the GPS receiver. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK_REF](_image___native_module.md#ohos_image_property_gps_track_ref) = "GPSTrackRef" | Reference of the movement direction of the GPS receiver. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK](_image___native_module.md#ohos_image_property_gps_track) = "GPSTrack" | Movement direction of the GPS receiver. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF](_image___native_module.md#ohos_image_property_gps_img_direction_ref) = "GPSImgDirectionRef" | Reference of the direction of the image when it was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION](_image___native_module.md#ohos_image_property_gps_img_direction) = "GPSImgDirection" | Direction of the image when it was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM](_image___native_module.md#ohos_image_property_gps_map_datum) = "GPSMapDatum" | Geodetic survey data used by the GPS receiver. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF](_image___native_module.md#ohos_image_property_gps_dest_latitude_ref) = "GPSDestLatitudeRef" | Whether the latitude of the destination point is north or south latitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE](_image___native_module.md#ohos_image_property_gps_dest_latitude) = "GPSDestLatitude" | Latitude of the destination point. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF](_image___native_module.md#ohos_image_property_gps_dest_longitude_ref) = "GPSDestLongitudeRef" | Whether the longitude of the destination point is east or west longitude. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD](_image___native_module.md#ohos_image_property_gps_processing_method) = "GPSProcessingMethod" | String that records the name of the method used for positioning. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION](_image___native_module.md#ohos_image_property_gps_area_information) = "GPSAreaInformation" | String that records the name of the GPS area. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL](_image___native_module.md#ohos_image_property_gps_differential) = "GPSDifferential" | Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy. | 
| static const char \*[OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER](_image___native_module.md#ohos_image_property_body_serial_number) = "BodySerialNumber" | Serial number of the camera body. | 
| static const char \*[OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME](_image___native_module.md#ohos_image_property_camera_owner_name) = "CameraOwnerName" | Name of the camera owner. | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE](_image___native_module.md#ohos_image_property_composite_image) = "CompositeImage" | Whether the image is a composite image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_DNG_VERSION](_image___native_module.md#ohos_image_property_dng_version) = "DNGVersion" | DNG version. It encodes the DNG 4-tier version number. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE](_image___native_module.md#ohos_image_property_gps_dest_longitude) = "GPSDestLongitude" | Longitude of the destination point. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF](_image___native_module.md#ohos_image_property_gps_dest_bearing_ref) = "GPSDestBearingRef" | Reference of the bearing to the destination point. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING](_image___native_module.md#ohos_image_property_gps_dest_bearing) = "GPSDestBearing" | Bearing to the destination point. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF](_image___native_module.md#ohos_image_property_gps_dest_distance_ref) = "GPSDestDistanceRef" | Unit used to express the distance to the destination point. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE](_image___native_module.md#ohos_image_property_gps_dest_distance) = "GPSDestDistance" | Distance to the destination point. | 
| static const char \*[OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE](_image___native_module.md#ohos_image_property_default_crop_size) = "DefaultCropSize" | Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GAMMA](_image___native_module.md#ohos_image_property_gamma) = "Gamma" | Gamma value. | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY](_image___native_module.md#ohos_image_property_iso_speed_latitudeyyy) = "ISOSpeedLatitudeyyy" | ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232. | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ](_image___native_module.md#ohos_image_property_iso_speed_latitudezzz) = "ISOSpeedLatitudezzz" | ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232. | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MAKE](_image___native_module.md#ohos_image_property_lens_make) = "LensMake" | Manufacturer of the lens. | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MODEL](_image___native_module.md#ohos_image_property_lens_model) = "LensModel" | Model of the lens. | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER](_image___native_module.md#ohos_image_property_lens_serial_number) = "LensSerialNumber" | Serial number of the lens. | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION](_image___native_module.md#ohos_image_property_lens_specification) = "LensSpecification" | Specifications of the lens. | 
| static const char \*[OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE](_image___native_module.md#ohos_image_property_new_subfile_type) = "NewSubfileType" | Data type of a subfile, such as a full-resolution image, a thumbnail, or a part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME](_image___native_module.md#ohos_image_property_offset_time) = "OffsetTime" | Time with an offset from UTC when the image was captured, in the format of ±HH:MM. | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED](_image___native_module.md#ohos_image_property_offset_time_digitized) = "OffsetTimeDigitized" | Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp. | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL](_image___native_module.md#ohos_image_property_offset_time_original) = "OffsetTimeOriginal" | Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE](_image___native_module.md#ohos_image_property_source_exposure_times_of_composite_image) = "SourceExposureTimesOfCompositeImage" | Exposure time of source images of the composite image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE](_image___native_module.md#ohos_image_property_source_image_number_of_composite_image) = "SourceImageNumberOfCompositeImage" | Number of source images of the composite image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBFILE_TYPE](_image___native_module.md#ohos_image_property_subfile_type) = "SubfileType" | Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR](_image___native_module.md#ohos_image_property_gps_h_positioning_error) = "GPSHPositioningError" | Horizontal positioning error, in meters. | 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY](_image___native_module.md#ohos_image_property_photographic_sensitivity) = "PhotographicSensitivity" | Sensitivity of the camera or input device when the image was captured. | 
| static const char \*[OHOS_IMAGE_PROPERTY_BURST_NUMBER](_image___native_module.md#ohos_image_property_burst_number) = "HwMnoteBurstNumber" | Number of burst shooting times. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_CONF](_image___native_module.md#ohos_image_property_face_conf) = "HwMnoteFaceConf" | Face confidence. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER](_image___native_module.md#ohos_image_property_face_leye_center) = "HwMnoteFaceLeyeCenter" | Left eye centered. It is used in [OH_ImageSource_GetImageProperty](_image___native_module.md#oh_imagesourcenative_getimageproperty) and [OH_ImageSource_ModifyImageProperty](_image___native_module.md#oh_imagesourcenative_modifyimageproperty). | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER](_image___native_module.md#ohos_image_property_face_mouth_center) = "HwMnoteFaceMouthCenter" | Mouth centered. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_POINTER](_image___native_module.md#ohos_image_property_face_pointer) = "HwMnoteFacePointer" | Face pointer. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_RECT](_image___native_module.md#ohos_image_property_face_rect) = "HwMnoteFaceRect" | Face rectangle. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER](_image___native_module.md#ohos_image_property_face_reye_center) = "HwMnoteFaceReyeCenter" | Right eye centered. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE](_image___native_module.md#ohos_image_property_face_smile_score) = "HwMnoteFaceSmileScore" | Smile score of for faces. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_VERSION](_image___native_module.md#ohos_image_property_face_version) = "HwMnoteFaceVersion" | Facial recognition algorithm version. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRONT_CAMERA](_image___native_module.md#ohos_image_property_front_camera) = "HwMnoteFrontCamera" | Whether the front camera is used to take a selfie. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_POINTER](_image___native_module.md#ohos_image_property_scene_pointer) = "HwMnoteScenePointer" | Pointer to the scene. | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_VERSION](_image___native_module.md#ohos_image_property_scene_version) = "HwMnoteSceneVersion" | Scene algorithm version. | 
| static const char \*[OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT](_image___native_module.md#ohos_image_property_gif_loop_count) = "GIFLoopCount" | Number of GIF loops. | 
| static const char \*[OHOS_IMAGE_PROPERTY_X_IN_ORIGINAL](_image___native_module.md#ohos_image_property_x_in_original) = "XInOriginal" | X coordinate of the upper left corner of the fragment map in the original image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_IN_ORIGINAL](_image___native_module.md#ohos_image_property_y_in_original) = "YInOriginal" | Y coordinate of the upper left corner of the fragment map in the original image. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRAGMENT_WIDTH](_image___native_module.md#ohos_image_property_fragment_width) = "FragmentImageWidth"| Width of the fragment map. | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRAGMENT_HEIGHT](_image___native_module.md#ohos_image_property_fragment_height) = "FragmentImageHeight" | Height of the fragment map. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_Create](_image___native_module.md#oh_picturemetadata_create) ([Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*metadata) | Creates the pointer to an **OH_PictureMetadata** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_GetProperty](_image___native_module.md#oh_picturemetadata_getproperty) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | Obtains a property of metadata based on the key.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_SetProperty](_image___native_module.md#oh_picturemetadata_setproperty) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | Sets a property of metadata based on the key.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_Release](_image___native_module.md#oh_picturemetadata_release) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata) | Releases the pointer to an **OH_PictureMetadata** struct.| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_Clone](_image___native_module.md#oh_picturemetadata_clone) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*oldMetadata, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*newMetadata) | Clones metadata.| 
