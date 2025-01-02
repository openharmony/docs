# image_common.h


## 概述

声明图像接口使用的公共枚举和结构体。

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Image_Size](_image___size.md) | 图像大小结构体。 | 
| struct  [Image_Region](_image___region.md) | 待解码的图像源区域结构体。 | 
| struct  [Image_String](_image___string.md) | 字符串结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Image_Size](_image___size.md) [Image_Size](_image___native_module.md#image_size) | 声明图像大小结构。 | 
| typedef struct [Image_Region](_image___region.md) [Image_Region](_image___native_module.md#image_region) | 声明要解码的图像源区域结构体类型名称。 | 
| typedef struct [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) | 声明用于Picture的元数据。 | 
| typedef struct [Image_String](_image___string.md) [Image_String](_image___native_module.md#image_string) | 声明字符串结构的名称。 | 
| typedef struct [Image_String](_image___string.md) [Image_MimeType](_image___native_module.md#image_mimetype) | 声明一个图片格式类型的名称。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) {<br/>IMAGE_SUCCESS = 0,<br/>IMAGE_BAD_PARAMETER = 401,<br/>IMAGE_UNSUPPORTED_MIME_TYPE = 7600101,<br/>IMAGE_UNKNOWN_MIME_TYPE = 7600102,<br/>IMAGE_TOO_LARGE = 7600103,<br/>IMAGE_DMA_NOT_EXIST = 7600173,<br/>IMAGE_DMA_OPERATION_FAILED = 7600174,<br/>IMAGE_UNSUPPORTED_OPERATION = 7600201,<br/>IMAGE_UNSUPPORTED_METADATA = 7600202,<br/>IMAGE_UNSUPPORTED_CONVERSION = 7600203,<br/>IMAGE_INVALID_REGION = 7600204,<br/>IMAGE_UNSUPPORTED_MEMORY_FORMAT = 7600205,<br/>IMAGE_ALLOC_FAILED = 7600301,<br/>IMAGE_COPY_FAILED = 7600302,<br/>IMAGE_LOCK_UNLOCK_FAILED = 7600303,<br/>IMAGE_UNKNOWN_ERROR = 7600901,<br/>IMAGE_BAD_SOURCE = 7700101,<br/>IMAGE_DECODE_FAILED = 7700301,<br/>IMAGE_ENCODE_FAILED = 7800301<br/>} | 错误码。 | 
| [Image_MetadataType](_image___native_module.md#image_metadatatype) {<br/>EXIF_METADATA = 1,<br/>FRAGMENT_METADATA = 2<br/>} | 定义元数据类型。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const char \*[MIME_TYPE_BMP](_image___native_module.md#mime_type_bmp) = "image/bmp" | bmp图片格式。  | 
| static const char \*[MIME_TYPE_JPEG](_image___native_module.md#mime_type_jpeg) = "image/jpeg" | jpeg图片格式。  | 
| static const char \*[MIME_TYPE_HEIC](_image___native_module.md#mime_type_heic) = "image/heic" | heif图片格式。  | 
| static const char \*[MIME_TYPE_PNG](_image___native_module.md#mime_type_png) = "image/png" | png图片格式。  | 
| static const char \*[MIME_TYPE_WEBP](_image___native_module.md#mime_type_webp) = "image/webp" | webp图片格式。  | 
| static const char \*[MIME_TYPE_GIF](_image___native_module.md#mime_type_gif) = "image/gif" | gif图片格式。  | 
| static const char \*[MIME_TYPE_ICON](_image___native_module.md#mime_type_icon) = "image/x-icon" | ico图片格式。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](_image___native_module.md#ohos_image_property_bits_per_sample) = "BitsPerSample" | 每个像素比特数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_ORIENTATION](_image___native_module.md#ohos_image_property_orientation) = "Orientation" | 图片方向。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](_image___native_module.md#ohos_image_property_image_length) = "ImageLength" | 图片长度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](_image___native_module.md#ohos_image_property_image_width) = "ImageWidth" | 图片宽度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE](_image___native_module.md#ohos_image_property_gps_latitude) = "GPSLatitude" | 图片纬度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](_image___native_module.md#ohos_image_property_gps_longitude) = "GPSLongitude" | 图片经度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](_image___native_module.md#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | 纬度引用，例如N或S。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](_image___native_module.md#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | 经度引用，例如W或E。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](_image___native_module.md#ohos_image_property_date_time_original) = "DateTimeOriginal" | 拍摄时间，例如2022:09:06 15:48:00。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](_image___native_module.md#ohos_image_property_exposure_time) = "ExposureTime" | 曝光时间，例如1/33 sec。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_TYPE](_image___native_module.md#ohos_image_property_scene_type) = "SceneType" | 拍摄场景模式，例如人像、风光、运动、夜景等。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](_image___native_module.md#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | ISO感光度，例如400。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_F_NUMBER](_image___native_module.md#ohos_image_property_f_number) = "FNumber" | 光圈值，例如f/1.8。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](_image___native_module.md#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | 用于压缩图像的压缩模式，单位为每像素位数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSION](_image___native_module.md#ohos_image_property_compression) = "Compression" | 图像压缩方案。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION](_image___native_module.md#ohos_image_property_photometric_interpretation) = "PhotometricInterpretation" | 像素构成，例如RGB或YCbCr。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_OFFSETS](_image___native_module.md#ohos_image_property_strip_offsets) = "StripOffsets" | 每个strip的字节偏移量。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL](_image___native_module.md#ohos_image_property_samples_per_pixel) = "SamplesPerPixel" | 每个像素的分量数。由于该标准适用于 RGB 和 YCbCr 图像，因此该标签的值设置为 3。 在JPEG压缩数据中，使用JPEG标记代替该标签。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP](_image___native_module.md#ohos_image_property_rows_per_strip) = "RowsPerStrip" | 每个strip的图像数据行数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS](_image___native_module.md#ohos_image_property_strip_byte_counts) = "StripByteCounts" | 每个图像数据带的总字节数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_X_RESOLUTION](_image___native_module.md#ohos_image_property_x_resolution) = "XResolution" | 图像宽度方向的分辨率。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_RESOLUTION](_image___native_module.md#ohos_image_property_y_resolution) = "YResolution" | 图像高度方向的分辨率。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION](_image___native_module.md#ohos_image_property_planar_configuration) = "PlanarConfiguration" | 表示像素组件的记录格式，chunky格式或是planar格式。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT](_image___native_module.md#ohos_image_property_resolution_unit) = "ResolutionUnit" | 用于测量XResolution和YResolution的单位。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION](_image___native_module.md#ohos_image_property_transfer_function) = "TransferFunction" | 图像的传递函数，通常用于颜色校正。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOFTWARE](_image___native_module.md#ohos_image_property_software) = "Software" | 用于生成图像的软件的名称和版本。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_ARTIST](_image___native_module.md#ohos_image_property_artist) = "Artist" | 创建图像的用户名称。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_WHITE_POINT](_image___native_module.md#ohos_image_property_white_point) = "WhitePoint" | 图像的白点色度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES](_image___native_module.md#ohos_image_property_primary_chromaticities) = "PrimaryChromaticities" | 图像的主要颜色的色度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS](_image___native_module.md#ohos_image_property_ycbcr_coefficients) = "YCbCrCoefficients" | 从RGB到YCbCr图像数据的转换矩阵系数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING](_image___native_module.md#ohos_image_property_ycbcr_sub_sampling) = "YCbCrSubSampling" | 色度分量与亮度分量的采样比率。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING](_image___native_module.md#ohos_image_property_ycbcr_positioning) = "YCbCrPositioning" | 色度分量相对于亮度分量的位置。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE](_image___native_module.md#ohos_image_property_reference_black_white) = "ReferenceBlackWhite" | 参考黑点值和参考白点值。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_COPYRIGHT](_image___native_module.md#ohos_image_property_copyright) = "Copyright" | 图像的版权信息。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT](_image___native_module.md#ohos_image_property_jpeg_interchange_format) = "JPEGInterchangeFormat" | JPEG压缩缩略图数据开始字节（SOI）的偏移。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH](_image___native_module.md#ohos_image_property_jpeg_interchange_format_length) = "JPEGInterchangeFormatLength" | JPEG压缩缩略图数据的字节数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM](_image___native_module.md#ohos_image_property_exposure_program) = "ExposureProgram" | 拍照时相机用来设置曝光的程序的类别。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY](_image___native_module.md#ohos_image_property_spectral_sensitivity) = "SpectralSensitivity" | 表示所用相机的每个通道的光谱灵敏度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_OECF](_image___native_module.md#ohos_image_property_oecf) = "OECF" | 表示ISO 14524中规定的光电转换函数（OECF）。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXIF_VERSION](_image___native_module.md#ohos_image_property_exif_version) = "ExifVersion" | 支持的Exif标准版本。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED](_image___native_module.md#ohos_image_property_date_time_digitized) = "DateTimeDigitized" | 图像作为数字数据存储的日期和时间，格式为YYYY:MM:DD HH:MM:SS。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION](_image___native_module.md#ohos_image_property_components_configuration) = "ComponentsConfiguration" | 压缩数据的特定信息。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE](_image___native_module.md#ohos_image_property_shutter_speed_value) = "ShutterSpeedValue" | 快门速度，以APEX（摄影曝光的加法系统）值表示。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE](_image___native_module.md#ohos_image_property_brightness_value) = "BrightnessValue" | 图像的亮度值，以APEX单位表示。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE](_image___native_module.md#ohos_image_property_max_aperture_value) = "MaxApertureValue" | 最小F数镜头。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE](_image___native_module.md#ohos_image_property_subject_distance) = "SubjectDistance" | 测量单位为米的主体距离。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_AREA](_image___native_module.md#ohos_image_property_subject_area) = "SubjectArea" | 该标签指示整个场景中主要主体的位置和区域。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_MAKER_NOTE](_image___native_module.md#ohos_image_property_maker_note) = "MakerNote" | Exif/DCF制造商使用的标签，用于记录任何所需信息。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME](_image___native_module.md#ohos_image_property_subsec_time) = "SubsecTime" | 用于为DateTime标签记录秒的分数的标签。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL](_image___native_module.md#ohos_image_property_subsec_time_original) = "SubsecTimeOriginal" | 用于为DateTimeOriginal标签记录秒的分数的标签。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED](_image___native_module.md#ohos_image_property_subsec_time_digitized) = "SubsecTimeDigitized" | 用于为DateTimeDigitized标签记录秒的分数的标签。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION](_image___native_module.md#ohos_image_property_flashpix_version) = "FlashpixVersion" | 该标签表示FPXR文件支持的Flashpix格式版本，增强了设备兼容性。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_COLOR_SPACE](_image___native_module.md#ohos_image_property_color_space) = "ColorSpace" | 色彩空间信息标签，通常记录为色彩空间指定符。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE](_image___native_module.md#ohos_image_property_related_sound_file) = "RelatedSoundFile" | 与图像数据相关的音频文件的名称。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASH_ENERGY](_image___native_module.md#ohos_image_property_flash_energy) = "FlashEnergy" | 图像捕获时的闪光能量，以BCPS表示。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE](_image___native_module.md#ohos_image_property_spatial_frequency_response) = "SpatialFrequencyResponse" | 相机或输入设备的空间频率表。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION](_image___native_module.md#ohos_image_property_focal_plane_x_resolution) = "FocalPlaneXResolution" | 图像宽度中每FocalPlaneResolutionUnit的像素。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION](_image___native_module.md#ohos_image_property_focal_plane_y_resolution) = "FocalPlaneYResolution" | 图像高度中每FocalPlaneResolutionUnit的像素。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT](_image___native_module.md#ohos_image_property_focal_plane_resolution_unit) = "FocalPlaneResolutionUnit" | 测量FocalPlaneXResolution和FocalPlaneYResolution的单位。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION](_image___native_module.md#ohos_image_property_subject_location) = "SubjectLocation" | 主要对象相对于左边缘的位置。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX](_image___native_module.md#ohos_image_property_exposure_index) = "ExposureIndex" | 捕获时选定的曝光指数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SENSING_METHOD](_image___native_module.md#ohos_image_property_sensing_method) = "SensingMethod" | 相机上的图像传感器类型。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FILE_SOURCE](_image___native_module.md#ohos_image_property_file_source) = "FileSource" | 表明图像来源。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_CFA_PATTERN](_image___native_module.md#ohos_image_property_cfa_pattern) = "CFAPattern" | 图像传感器的色彩滤光片（CFA）几何图案。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED](_image___native_module.md#ohos_image_property_custom_rendered) = "CustomRendered" | 指示图像数据上的特殊处理。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_MODE](_image___native_module.md#ohos_image_property_exposure_mode) = "ExposureMode" | 拍摄时设置的曝光模式。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO](_image___native_module.md#ohos_image_property_digital_zoom_ratio) = "DigitalZoomRatio" | 捕获时的数字变焦比率。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE](_image___native_module.md#ohos_image_property_scene_capture_type) = "SceneCaptureType" | 捕获的场景类型。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GAIN_CONTROL](_image___native_module.md#ohos_image_property_gain_control) = "GainControl" | 整体图像增益调整的程度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_CONTRAST](_image___native_module.md#ohos_image_property_contrast) = "Contrast" | 相机应用的对比度处理方向。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SATURATION](_image___native_module.md#ohos_image_property_saturation) = "Saturation" | 相机应用的饱和度处理方向。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SHARPNESS](_image___native_module.md#ohos_image_property_sharpness) = "Sharpness" | 相机应用的锐度处理方向。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION](_image___native_module.md#ohos_image_property_device_setting_description) = "DeviceSettingDescription" | 特定相机模型的拍照条件信息。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE](_image___native_module.md#ohos_image_property_subject_distance_range) = "SubjectDistanceRange" | 表示主体到相机的距离范围。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID](_image___native_module.md#ohos_image_property_image_unique_id) = "ImageUniqueID" | 为每张图片唯一分配的标识符。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_VERSION_ID](_image___native_module.md#ohos_image_property_gps_version_id) = "GPSVersionID" | GPSInfoIFD的版本。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF](_image___native_module.md#ohos_image_property_gps_altitude_ref) = "GPSAltitudeRef" | 用于GPS高度的参照高度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE](_image___native_module.md#ohos_image_property_gps_altitude) = "GPSAltitude" | 基于GPSAltitudeRef的高度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SATELLITES](_image___native_module.md#ohos_image_property_gps_satellites) = "GPSSatellites" | 用于测量的GPS卫星。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_STATUS](_image___native_module.md#ohos_image_property_gps_status) = "GPSStatus" | 录制图像时GPS接收器的状态。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE](_image___native_module.md#ohos_image_property_gps_measure_mode) = "GPSMeasureMode" | GPS测量模式。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DOP](_image___native_module.md#ohos_image_property_gps_dop) = "GPSDOP" | GPS DOP（数据精度等级）。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED_REF](_image___native_module.md#ohos_image_property_gps_speed_ref) = "GPSSpeedRef" | 用来表示GPS接收器移动速度的单位。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED](_image___native_module.md#ohos_image_property_gps_speed) = "GPSSpeed" | GPS接收器的移动速度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK_REF](_image___native_module.md#ohos_image_property_gps_track_ref) = "GPSTrackRef" | GPS接收机移动方向的参照。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK](_image___native_module.md#ohos_image_property_gps_track) = "GPSTrack" | GPS接收机的移动方向。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF](_image___native_module.md#ohos_image_property_gps_img_direction_ref) = "GPSImgDirectionRef" | 图像方向的参照。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION](_image___native_module.md#ohos_image_property_gps_img_direction) = "GPSImgDirection" | 拍摄时图像的方向。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM](_image___native_module.md#ohos_image_property_gps_map_datum) = "GPSMapDatum" | GPS接收器使用的大地测量数据。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF](_image___native_module.md#ohos_image_property_gps_dest_latitude_ref) = "GPSDestLatitudeRef" | 目的地点的纬度参照。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE](_image___native_module.md#ohos_image_property_gps_dest_latitude) = "GPSDestLatitude" | 目的地点的纬度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF](_image___native_module.md#ohos_image_property_gps_dest_longitude_ref) = "GPSDestLongitudeRef" | 目的地点的经度参照。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD](_image___native_module.md#ohos_image_property_gps_processing_method) = "GPSProcessingMethod" | 记录定位方法名的字符字符串。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION](_image___native_module.md#ohos_image_property_gps_area_information) = "GPSAreaInformation" | 记录GPS区域名的字符字符串。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL](_image___native_module.md#ohos_image_property_gps_differential) = "GPSDifferential" | 此字段表示GPS数据是否应用了差分校正，对于精确的位置准确性至关重要。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER](_image___native_module.md#ohos_image_property_body_serial_number) = "BodySerialNumber" | 相机机身的序列号。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME](_image___native_module.md#ohos_image_property_camera_owner_name) = "CameraOwnerName" | 相机所有者的姓名。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE](_image___native_module.md#ohos_image_property_composite_image) = "CompositeImage" | 表示图像是否为合成图像。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_DNG_VERSION](_image___native_module.md#ohos_image_property_dng_version) = "DNGVersion" | DNG版本标签编码了符合DNG规范的四级版本号。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE](_image___native_module.md#ohos_image_property_gps_dest_longitude) = "GPSDestLongitude" | 目的地点的经度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF](_image___native_module.md#ohos_image_property_gps_dest_bearing_ref) = "GPSDestBearingRef" | 指向目的地点的方位参照。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING](_image___native_module.md#ohos_image_property_gps_dest_bearing) = "GPSDestBearing" | 目的地方位。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF](_image___native_module.md#ohos_image_property_gps_dest_distance_ref) = "GPSDestDistanceRef" | 目标点距离的测量单位。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE](_image___native_module.md#ohos_image_property_gps_dest_distance) = "GPSDestDistance" | 到目的地点的距离。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE](_image___native_module.md#ohos_image_property_default_crop_size) = "DefaultCropSize" | DefaultCropSize指定了原始坐标中的最终图像大小，考虑了额外的边缘像素。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GAMMA](_image___native_module.md#ohos_image_property_gamma) = "Gamma" | 表示系数伽马的值。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY](_image___native_module.md#ohos_image_property_iso_speed_latitudeyyy) = "ISOSpeedLatitudeyyy" | 该标签指示摄像机或输入设备的ISO速度纬度yyy值，该值在ISO 12232中定义。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ](_image___native_module.md#ohos_image_property_iso_speed_latitudezzz) = "ISOSpeedLatitudezzz" | 该标签指示摄像机或输入设备的ISO速度纬度zzz值，该值在ISO 12232中定义。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MAKE](_image___native_module.md#ohos_image_property_lens_make) = "LensMake" | 镜头的制造商。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MODEL](_image___native_module.md#ohos_image_property_lens_model) = "LensModel" | 镜头的型号名称。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER](_image___native_module.md#ohos_image_property_lens_serial_number) = "LensSerialNumber" | 镜头的序列号。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION](_image___native_module.md#ohos_image_property_lens_specification) = "LensSpecification" | 使用的镜头规格。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE](_image___native_module.md#ohos_image_property_new_subfile_type) = "NewSubfileType" | 在Exif中，"NewSubfileType"字段用于标识子文件的数据类型，如全分辨率图像、缩略图或多帧图像的一部分。 其值是位掩码，0代表全分辨率图像，1代表缩略图，2代表多帧图像的一部分。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME](_image___native_module.md#ohos_image_property_offset_time) = "OffsetTime" | 在Exif中，OffsetTime字段表示与UTC（协调世界时）的时间偏移，格式为±HH:MM，用于确定照片拍摄的本地时间。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED](_image___native_module.md#ohos_image_property_offset_time_digitized) = "OffsetTimeDigitized" | 此标签记录图像数字化时的UTC偏移量，有助于准确调整时间戳。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL](_image___native_module.md#ohos_image_property_offset_time_original) = "OffsetTimeOriginal" | 此标签记录原始图像创建时的UTC偏移量，对于时间敏感的应用至关重要。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE](_image___native_module.md#ohos_image_property_source_exposure_times_of_composite_image) = "SourceExposureTimesOfCompositeImage" | 合成图像的源图像曝光时间。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE](_image___native_module.md#ohos_image_property_source_image_number_of_composite_image) = "SourceImageNumberOfCompositeImage" | 用于合成图像的源图像数量。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBFILE_TYPE](_image___native_module.md#ohos_image_property_subfile_type) = "SubfileType" | 此标签指示此子文件中的数据类型。标签已弃用，请使用NewSubfileType替代。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR](_image___native_module.md#ohos_image_property_gps_h_positioning_error) = "GPSHPositioningError" | 此标签指示水平定位误差，单位为米。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY](_image___native_module.md#ohos_image_property_photographic_sensitivity) = "PhotographicSensitivity" | 此标签指示拍摄图像时相机或输入设备的灵敏度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_BURST_NUMBER](_image___native_module.md#ohos_image_property_burst_number) = "HwMnoteBurstNumber" | 连拍次数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_CONF](_image___native_module.md#ohos_image_property_face_conf) = "HwMnoteFaceConf" | 人脸置信度。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER](_image___native_module.md#ohos_image_property_face_leye_center) = "HwMnoteFaceLeyeCenter" | 左眼中心。被用于 [OH_ImageSource_GetImageProperty](_image___native_module.md#oh_imagesourcenative_getimageproperty) 和 [OH_ImageSource_ModifyImageProperty](_image___native_module.md#oh_imagesourcenative_modifyimageproperty)。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER](_image___native_module.md#ohos_image_property_face_mouth_center) = "HwMnoteFaceMouthCenter" | 嘴中心。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_POINTER](_image___native_module.md#ohos_image_property_face_pointer) = "HwMnoteFacePointer" | 脸部指针。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_RECT](_image___native_module.md#ohos_image_property_face_rect) = "HwMnoteFaceRect" | 脸部矩形。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER](_image___native_module.md#ohos_image_property_face_reye_center) = "HwMnoteFaceReyeCenter" | 右眼中心。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE](_image___native_module.md#ohos_image_property_face_smile_score) = "HwMnoteFaceSmileScore" | FaceCount张人脸的笑脸分数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_VERSION](_image___native_module.md#ohos_image_property_face_version) = "HwMnoteFaceVersion" | 人脸算法版本信息。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRONT_CAMERA](_image___native_module.md#ohos_image_property_front_camera) = "HwMnoteFrontCamera" | 是否是前置相机自拍。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_POINTER](_image___native_module.md#ohos_image_property_scene_pointer) = "HwMnoteScenePointer" | 场景指针。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_VERSION](_image___native_module.md#ohos_image_property_scene_version) = "HwMnoteSceneVersion" | 场景算法版本信息。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT](_image___native_module.md#ohos_image_property_gif_loop_count) = "GIFLoopCount" | GIF图片循环次数。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_X_IN_ORIGINAL](_image___native_module.md#ohos_image_property_x_in_original) = "XInOriginal" | 水印裁剪图左上角在原始图中的X坐标。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_IN_ORIGINAL](_image___native_module.md#ohos_image_property_y_in_original) = "XInOriginal" | 水印裁剪图左上角在原始图中的Y坐标。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRAGMENT_WIDTH](_image___native_module.md#ohos_image_property_fragment_width) = "FragmentImageWidth"| 水印裁剪图的宽。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRAGMENT_HEIGHT](_image___native_module.md#ohos_image_property_fragment_height) = "FragmentImageHeight" | 水印裁剪图的高。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_Create](_image___native_module.md#oh_picturemetadata_create) ([Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*metadata) | 创建OH_PictureMetadata指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_GetProperty](_image___native_module.md#oh_picturemetadata_getproperty) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 根据key获取Metadata的单条属性。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_SetProperty](_image___native_module.md#oh_picturemetadata_setproperty) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 根据key修改Metadata的单条属性。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_Release](_image___native_module.md#oh_picturemetadata_release) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata) | 释放OH_PictureMetadata指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureMetadata_Clone](_image___native_module.md#oh_picturemetadata_clone) ([OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*oldMetadata, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*newMetadata) | 拷贝元数据。 | 
