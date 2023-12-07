# USB子系统变更说明

## cl.USB .1 对部分接口鉴权方式进行整改

**访问级别**

系统接口

**变更原因**

修改不合理的鉴权方式整改。不允许使用调用方进程APL等级进行权限校验，需要修改为使用AccessTokenKit::VerifyAccessToken对访问者进行权限校验

**变更影响**

该变更为 非兼容性 变更。接口调用者需要申请ohos.permission. MANAGE_USB_CONFIG权限, 接口返回值、入参均未发生改变

**变更发生版本**

从OpenHarmony SDK 4.1.5.1 开始。

**变更的接口/组件**

addRight, usbFunctionsFromString, usbFunctionsToString, setCurrentFunctions, getCurrentFunctions, getPorts, getSupportedModes, setPortRoles

**适配指导**

变更前
应用配置文件xxx.cfg中的apl字段是system_basic 或者 system_core。
变更后
配置文件中的permission 字段需要添加ohos.permission.MANAGE_USB_CONFIG权限。
