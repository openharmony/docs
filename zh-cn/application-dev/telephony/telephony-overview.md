# 电话服务开发概述

电话服务系统提供了一系列的API用于[拨打电话](../reference/apis/js-apis-call.md)、获取[无线蜂窝网络](../reference/apis/js-apis-telephony-data.md)和[SIM卡](../reference/apis/js-apis-sim.md)相关信息。

应用可以通过调用API来获取当前注册网络名称、网络服务状态、信号强度以及SIM卡的相关信息，具体可参考[获取当前蜂窝网络信号信息](cellular-network-signal-info.md)开发指导。

直接拨打电话需要系统权限ohos.permission.PLACE_CALL，建议应用使用makeCall()，跳转到拨号界面，并显示拨号的号码，具体可参考[跳转拨号界面](jumping-to-the-dial-screen.md)开发指导。


## 约束与限制

搭载设备需要支持以下硬件：

可以进行独立蜂窝通信的Modem以及SIM卡。