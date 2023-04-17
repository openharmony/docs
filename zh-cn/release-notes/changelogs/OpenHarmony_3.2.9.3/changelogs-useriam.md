# 用户IAM子系统Changelog

## cl.useriam.1 API9 GetVesion接口删除

为优化用户IAM接口，从当前版本开始做如下变更：

用户IAM删除GetVersion（API 9）接口。

**变更影响**

对用户IAM GetVersion（API 9）接口的使用有影响，需删除对此接口的调用，否则会调用失败。

**关键接口/组件变更**

|   模块名      |     类名     |     方法/属性/枚举/常量      |    变更类型     |
| ---------------------- | ------------------- | ------------------------- | ------------------------ |
| ohos.userIAM.userAuth | function | getVersion() : number | 删除 |

**适配指导**

需删除对用户IAM GetVersion（API 9）接口的调用。

## cl.useriam.2 API8 GetVesion接口返回值变更

为统一用户IAM GetVersion（API 8）接口的返回值。从当前版本开始做如下变更：

用户IAM GetVersion（API 8）接口的返回值由0变更为1。

**变更影响**

对用户IAM GetVersion（API 8）接口的使用有影响，如应用校验了此接口的返回值，修改后校验不通过。

**关键接口/组件变更**

用户IAM GetVersion（API 8）接口的返回值由0变更为1。

**适配指导**

此接口已废弃，需删除对用户IAM GetVersion（API 8）接口的使用。
