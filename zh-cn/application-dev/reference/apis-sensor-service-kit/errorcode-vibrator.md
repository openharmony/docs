# 振动错误码
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @butterls-->
<!--Tester: @murphy84-->
<!--Adviser: @hu-zhiqiong-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 14600101 操作设备失败

**错误信息**

Device operation failed.

**错误描述**

当调用vibrator模块startVibration接口时，若hdi服务异常或者设备被占用，会报此错误码。

**可能原因**
<!--RP1-->
1. 访问hdi服务状态异常。
2. 当前设备被占用。
<!--RP1End-->

**处理步骤**
<!--RP2-->
1. 间隔一段时间重试操作，或按指数增长间隔重试；连续重试3次不可用则停止尝试，期间可优先尝试获取器件列表方式进一步获取设备可用性。
2. 设置振动优先级较低，尝试设置更高优先级。
<!--RP2End-->