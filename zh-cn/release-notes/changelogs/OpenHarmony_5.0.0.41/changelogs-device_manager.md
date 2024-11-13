# 设备管理子系统Changelog

## cl.device_manager.1 使用udid-hash与appid和盐值基于sha256混淆截断后保留前16位值作为deviceid，调用行为变更

**访问级别**

公开接口

**变更原因**

分布式设备管理deviceid接口存在安全漏洞，应用获取的deviceid在设备重置后或者应用卸载重装后不变，对于同一个应用可以标识设备。

**变更影响**

该变更为不兼容变更。

变更前：
同一个应用在设备重置后，或者app卸载重装后，获取的deviceid相同

变更后：
1、同一个应用在设备重置后获取的deviceid不同；
2、应用卸载后重装，获取的deviceid不同；
3、不同应用在同一个设备上获取的deviceid不同；
4、同一个应用在不同设备上获取的同一个设备的deviceid不同。

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.0.0.41开始。

**变更的接口/组件**

不涉及。

**适配指导**

1、设备间传递deviceid比较：将networkid发送到对端进行比较；
2、应用将deviceid与SA获取的deviceid进行比较：使用networkid进行比较。

