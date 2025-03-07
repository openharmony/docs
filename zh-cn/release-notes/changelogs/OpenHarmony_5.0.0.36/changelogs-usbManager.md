# USB服务子系统Changelog

## cl.usbManager.1 @ohos.usbManager controlTransfer接口废弃

**访问级别**

公开接口。

**废弃原因**

为了与USB标准协议对齐，废弃原有接口ControlTransfer。

**废弃影响**

该变更为不兼容性变更。
使用controlTransfer接口会有废弃提示。建议迁移使用替代接口。

**起始 API Level**

9

**废弃发生的版本**

从OpenHarmony SDK 5.0.0.36开始。

**废弃的接口/组件**

|            接口声明            |               废弃说明               |           代替接口            |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| usbManager.controlTransfer | 使用usbManager.usbControlTransfer替换 | usbManager.usbControlTransfer |


**适配指导**

开发者需将使用@ohos.usbManager模块废弃接口的地方适配修改为@ohos.usbManager.usbControlTransfer接口。