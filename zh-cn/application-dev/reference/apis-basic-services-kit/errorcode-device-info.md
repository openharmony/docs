# deviceInfo错误码
<!--Kit: Basic Services Kit-->
<!--Subsystem: Startup-->
<!--Owner: @chenjinxiang3-->
<!--Designer: @chenjinxiang3-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->
> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 14700103 操作因权限被拒绝

**错误信息**

The operation on the system permission is denied.

**错误描述**

应用没有对应字段的权限时，系统会报此错误码。比如ohos.permission.sec.ACCESS_UDID权限。

**可能原因**

应用没有配置需要的权限，比如ohos.permission.sec.ACCESS_UDID。

**处理步骤**

在配置文件中添加相应的权限，例如：{"name": "ohos.permission.sec.ACCESS_UDID"}。不同字段可能需要不同权限，请参考[@ohos.deviceInfo (设备信息)](js-apis-device-info.md)。