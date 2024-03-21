# 剪贴板子系统ChangeLog

OpenHarmony 5.0.0.18 版本相较于OpenHarmony 之前的版本，剪贴板子系统的API变更如下。

## cl.pasteboard.1 getData()接口所需权限变更。

增加了访问getData()接口时所需的权限。

**变更影响**

5.0.0.18及后续版本中，业务需要申请ohos.permission.READ_PASTEBOARD权限，用于访问剪贴板内容。

**关键接口/组件变更**

getData()

API 12之前，业务访问剪贴板数据不会校验ohos.permission.READ_PASTEBOARD权限。

API 12及之后，业务在使用非安全控件访问剪贴板数据时，如没有ohos.permission.READ_PASTEBOARD权限，访问会被拦截。

**适配指导**

按新的语义进行适配。