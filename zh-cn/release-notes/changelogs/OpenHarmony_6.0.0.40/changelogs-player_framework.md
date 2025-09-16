# 播放框架子系统变更说明

## cl.multimedia.1 Media Kit OH_AVScreenCapture_SetCaptureStrategy接口变更

**访问级别**

公开接口

**变更原因**

在启动屏幕录制后，调用该接口返回错误码AV_SCREEN_CAPTURE_ERR_UNSUPPORT，错误描述不准确，为优化开发者体验，更正错误码描述。

**变更影响**

变更前：在启动屏幕录制后，调用OH_AVScreenCapture_SetCaptureStrategy返回错误码AV_SCREEN_CAPTURE_ERR_UNSUPPORT。

变更后：在启动屏幕录制后，调用OH_AVScreenCapture_SetCaptureStrategy返回错误码AV_SCREEN_CAPTURE_ERR_INVALID_STATE。

**起始 API Level**

API 20

**变更发生版本**

从OpenHarmony SDK 6.0.0.40开始。

**变更的接口/组件**

native_avscreen_capture.h：

OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)

**适配指导**

若有对OH_AVScreenCapture_SetCaptureStrategy的返回值做精确判断，需要将对AV_SCREEN_CAPTURE_ERR_UNSUPPORT的处理修改为对AV_SCREEN_CAPTURE_ERR_INVALID_STATE的处理。
