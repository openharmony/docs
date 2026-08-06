# 环境变量错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @zhangwenhan12-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 140000 @Env无效键

**错误信息**

Invalid key for @Env

**错误描述**

[@Env](./arkui-ts/ts-env-system-property.md#env)无效键。

**可能原因**

使用了@Env不支持的键。@Env仅接受预定义的[SystemProperties](./arkui-ts/ts-env-system-property.md#systemproperties)和[SystemEnvKey\<T\>](./arkui-ts/ts-env-system-property.md#systemenvkeyt)类型参数，传入不在支持范围内的键将触发此错误。详情见[@Env支持参数](../../ui/arkts-env-system-property.md#env支持参数)。

**处理步骤**

确保@Env参数类型为[SystemProperties](./arkui-ts/ts-env-system-property.md#systemproperties) \| [SystemEnvKey\<T\>](./arkui-ts/ts-env-system-property.md#systemenvkeyt)，详情见[@Env支持开发指南](../../ui/arkts-env-system-property.md)。