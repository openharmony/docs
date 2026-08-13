# 色域空间配置异常问题
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 问题现象

应用处于后处理或视频编码场景时，未正常处理色彩空间，导致图片效果异常（偏色、亮度过曝等）。

## 可能原因

相机应用可通过[SetColorSpace](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagement.md#setcolorspace12)接口配置不同的色彩空间参数来支持P3广色域以及HDR的功能。若应用不主动设置色彩空间，拍照、录像模式均默认为SDR拍摄。应用在不同模式使能HDR效果时，需要设置的色彩空间和相机输出流[Profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile)中的[CameraFormat](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraformat)对应关系可参考下表。

拍照模式：

| SDR/HDR拍摄        | 预览输出格式 | 色彩空间 |
|--------------------|------------| ------------|
| SDR（Default）       | CAMERA_FORMAT_YUV_420_SP       | SRGB       |
| HDR P3               | CAMERA_FORMAT_YUV_420_SP | DISPLAY_P3 |
| HDR BT.2020 | CAMERA_FORMAT_YCRCB_P010、<br>CAMERA_FORMAT_YCBCR_P010 | BT2020_HLG |

在录像模式下，使能SDR或HDR_VIVID拍摄效果时，CameraFormat与ColorSpace必须按照下列表格中的对应关系配置，若不满足表格中CameraFormat与ColorSpace配置，会导致预览异常等问题。

录像模式：

| SDR/HDR拍摄         | CameraFormat             | ColorSpace       |
|--------------------|--------------------------|------------------|
| SDR（Default）     | CAMERA_FORMAT_YUV_420_SP | BT709_LIMIT      |
| HDR_VIVID          | CAMERA_FORMAT_YCRCB_P010 | BT2020_HLG_LIMIT、<br>BT2020_HLG |
| HDR_VIVID          | CAMERA_FORMAT_YCBCR_P010 | BT2020_HLG_LIMIT、<br>BT2020_HLG |

## 问题分析

因此，应用在处理预览流数据或者录像流数据时，需处理色彩空间，否则会导致处理后的数据存在偏色、过曝等效果异常问题。具体原因如下：

1. 应用未主动设置色彩空间，默认SDR的色彩空间，配置相机输出流时使用了HDR对应的格式。

2. 应用主动设置色彩空间，配置相机输出流数据时使用了不符合当前色彩空间的格式。

## 预防措施

通过[getSupportedColorSpace](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12)查询当前会话生效的色彩空间，处理相机输出流数据时配置正确的色彩空间信息。

1. 在[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)使用场景下，通过[setColorSpace](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md#setcolorspace10)设置图像的色彩空间属性。

2. 在[NativeWindow](../../reference/apis-arkgraphics2d/capi-nativewindow.md)使用场景下，可先通过[OH_NativeWindow_GetColorSpace](../../reference/apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_getcolorspace)获取OHNativeWindow色彩空间属性，再通过[OH_NativeWindow_SetColorSpace](../../reference/apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_setcolorspace)设置OHNativeWindow色彩空间属性。
