# 包管理子系统ChangeLog

## cl.bundlemanager.1 废弃VerifyCodeParam接口和InstallParam中的verifyCodeParams字段

**访问级别**

系统接口

**废弃原因**

应用的代码签名文件将集成到安装包中，不再需要该接口来指定安装包的代码签名文件。

**废弃影响**

包管理[installer](../../../application-dev/reference/apis/js-apis-installer.md)模块中废弃VerifyCodeParam接口和InstallParam中的verifyCodeParams字段，不再需要该接口来指定安装包的代码签名文件。

**废弃发生版本**

从OpenHarmony SDK 4.1.3.3开始

**废弃的接口/组件**

| 接口声明 | 废弃说明 |
| --------------- | ------- |
| interface VerifyCodeParam | 不再需要该接口来指定安装包的代码签名文件。 |
| verifyCodeParams?: Array<VerifyCodeParam>; | 不再需要该接口来指定安装包的代码签名文件。 |

**适配指导**

调用安装接口时无需再指定安装包的代码签名文件，因为应用的代码签名文件将集成到安装包中。
