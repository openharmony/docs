# 通用能力ChangeLog

## cl.common.1 SystemAPI使用规则变更

目前子系统提供的system-api在调用时未做系统应用校验，三方应用使用Full版本的SDK就可以使用这些system-api，存在安全隐患，因此在OpenHarmony 4.0.2.1版本开始增加应用身份校验。

**变更影响**

只有系统应用允许使用system-api，三方应用使用system-api将返回202错误，返回202错误的方式有两种：1.抛异常；2.异步回调

**适配指导**

非系统应用使用systemapi有两种方法：1.申请系统应用权限 2.更换接口使用
