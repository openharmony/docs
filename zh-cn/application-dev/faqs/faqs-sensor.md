# 泛Sensor服务开发常见问题


## 是否对个人开发者开放PPG和ECG血压监测传感器的的数据获取接口(API 9)

PPG和ECG的血压监测传感器属于可穿戴设备传感器，传感器数据设计个人隐私数据，暂未对个人开发者开放接口。


## 如何正确使用震动模块接口(API 9)

**问题现象**

震动模块接口调用报错，错误码201。

vibrate fail, error.code: 201error.message: NaN

**解决措施**

权限校验失败。需要申请ohos.permission.VIBRATE权限。

**参考链接**

[声明权限](../security/AccessToken/declare-permissions.md)

