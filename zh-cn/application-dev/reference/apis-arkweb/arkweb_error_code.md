# ArkWeb NDK接口异常错误码

> **说明：**
>
> 以下介绍ArkWeb NDK接口发生异常的错误码。

## 17100100, 未知错误

**错误信息**

Unknown error.

**错误描述**

调用NDK接口，发生未知错误。

**处理步骤**

1.重新调用NDK接口。
2.重启应用。

## 17100101, 参数错误

**错误信息**

Invalid param.

**错误描述**

调用NDK接口传入的参数发生异常。

**处理步骤**

请检查入参是否正确，比如是否是空指针。

## 17100102, 注册三方协议失败

**错误信息**

Register custom schemes should be called before create any ArkWeb.

**错误描述**

需要在创建ArkWeb之前注册三方协议的配置。

**处理步骤**

在创建ArkWeb之前注册三方协议的配置，比如可以放到EntryAbility的onCreate中去注册。