# 录屏常见问题

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

## 实例数量超出限制时，录屏启动报错AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT

实例数量超出规格限制，当前规格为每种数据格式最多两个实例。建议释放多余实例后再使用新实例。

可能原因：录屏过程中，点击“不允许”、在通知栏停止录屏和通话打断录屏后，未释放资源。

解决方法：在录屏过程中因为状态改变导致的录屏停止，需要在[OH_AVScreenCapture_SetStateCallback()](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setstatecallback)（状态回调）中，对录屏资源进行异步释放。

录屏会话限制策略：

1. 客户端应用数量上限4个，比如会议屏幕共享、会议投屏、后台听歌识曲、系统录屏同时存在。

2. 单应用单模式（存为文件或存为码流）可创建实例上限2个，典型场景：在线上会议共享屏幕时，需要同步录制会议内容。

## 通话中未设置保持录屏策略时，无法启动录屏报错AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT

从API version 20开始，如需在通话中保持录屏，可使用[OH_AVScreenCapture_StrategyForKeepCaptureDuringCall()](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforkeepcaptureduringcall)设置“蜂窝通话时保持录屏”策略。

