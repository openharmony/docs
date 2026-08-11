# 振动错误码
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
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
1. 建议间隔1-2秒重试操作，或按指数增长间隔（如1秒、2秒、4秒）重试；连续重试3次不可用则停止尝试，期间通过获取器件列表进一步确认设备可用性。
2. 等待当前振动任务完成后再重试操作。
<!--RP2End-->