# 泛Sensor服务开发常见问题

## 是否对个人开发者开放PPG和ECG血压监测传感器的的数据获取接口

适用于OpenHarmony 3.1 Beta5  API 9

PPG和ECG的血压监测传感器属于可穿戴设备传感器，传感器数据设计个人隐私数据，暂未对个人开发者开放接口。

## 如何正确使用震动模块接口

适用于：OpenHarmony 3.2版本  API 9 Stage模型

**问题现象**

震动模块接口调用报错，错误码201。

vibrate fail, error.code: 201error.message: NaN

**解决措施**

权限校验失败。需要申请ohos.permission.VIBRATE权限。

参考文档：[权限申请](../security/accesstoken-guidelines.md)

