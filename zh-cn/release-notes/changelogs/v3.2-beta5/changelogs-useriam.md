# 用户IAM子系统Changelog

## cl.useriam.1 API9返回值命名变更

用户IAM API9的返回值枚举类类名发生变更，从 ResultCodeV9 更名为 UserAuthResultCode

**变更影响**

基于此版本以前开发的应用不受影响，以后的需适配错误码的类名，否则会影响业务逻辑。

**关键接口/组件变更**

无接口/组件变更

**适配指导**

需要修改返回值调用类名从 ResultCodeV9 改为 UserAuthResultCode