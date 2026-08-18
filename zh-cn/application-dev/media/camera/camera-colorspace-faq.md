# 色彩空间配置异常问题
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 问题现象

应用处于后处理或视频编码场景时，处理后的图片或视频出现偏色、亮度过曝等效果异常的现象。

## 问题分析

应用在处理预览流数据或者录像流数据时，需正确处理色彩空间，否则会导致处理后的数据存在偏色、过曝等效果异常问题。具体原因如下：

1. 应用未主动设置色彩空间，默认SDR的色彩空间，配置相机输出流时使用了HDR对应的格式。

2. 应用主动设置色彩空间，配置相机输出流数据时使用了不符合当前色彩空间的格式。

## 解决措施

1. 通过[getActiveColorSpace（ArkTs）](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagement.md#getactivecolorspace12)或者[getActiveColorSpace（C/C++）](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_getactivecolorspace)查询当前相机会话生效的色彩空间，处理相机输出流数据时配置正确的色彩空间信息。

2. 根据查询的colorSpace色彩空间信息，相机应用可通过setColorSpace相关接口配置对应的色彩空间参数信息。

   - ImageReceiver场景（ArkTS）：若[使用ImageReceiver完成图片接收](../image/image-receiver.md)时，首先需要将imageArrival事件监听获取底层返回的[Image](../../reference/apis-image-kit/arkts-apis-image-Image.md)数据转成[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)做图像数据处理或送显，并在创建[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)后，可通过[setColorSpace](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md#setcolorspace10)设置图像的色彩空间属性。

   - NativeWindow场景（C/C++）：若使用[NativeWindow](../../reference/apis-arkgraphics2d/capi-nativewindow.md)对相机获取的预览流或录像流数据进行拷贝处理，为了避免数据拷贝时丢失色彩空间属性，可先通过[OH_NativeWindow_GetColorSpace](../../reference/apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_getcolorspace)获取OHNativeWindow色彩空间属性，再通过[OH_NativeWindow_SetColorSpace](../../reference/apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_setcolorspace)设置NativeWindow色彩空间属性。
