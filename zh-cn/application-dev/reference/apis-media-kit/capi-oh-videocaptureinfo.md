# OH_VideoCaptureInfo

## 概述

视频录制信息，当videoFrameWidth和videoFrameHeight同时为0时，忽略视频相关参数不录制屏幕数据

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint64_t displayId | 显示ID,指定窗口时需设置 |
| int32_t* missionIDs | missionID,指定窗口时需设置 |
| int32_t missionIDsLen | MissionIds长度, ,指定窗口时需设置 |
| int32_t videoFrameWidth | 宽度 |
| int32_t videoFrameHeight | 高度 |
| OH_VideoSourceType videoSource | 视频类型 |


