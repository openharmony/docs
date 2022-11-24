# USB服务错误码

## 14400001 连接USB设备被拒绝

**错误信息**

Permission denied. Need call requestRight to get permission.

**错误描述**

当调用USB模块部分接口时，如果没有相关权限，会报此错误码。

**可能原因**

没有获取到设备的使用权限。

**处理步骤**

调用requestRight方法申请设备的使用权限。