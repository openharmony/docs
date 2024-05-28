# 剪贴板子系统ChangeLog

OpenHarmony 5.0.0.18 版本相较于OpenHarmony 之前的版本，剪贴板子系统的API变更如下。

## cl.pasteboard.1 getData()接口所需权限变更。

增加了访问getData()接口时所需的权限。

**访问级别**

公开接口

**变更原因** 

新规格，应用使用自定义控件后台访问剪贴板需要申请ohos.permission.READ_PASTEBOARD。

**变更影响**

非兼容性变更，需要使用者进行适配。

变更前：业务访问剪贴板数据不会校验ohos.permission.READ_PASTEBOARD权限。

变更后：业务在使用非安全控件访问剪贴板数据时，如未申请ohos.permission.READ_PASTEBOARD权限，访问会被拦截。

**起始API Level** 

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.18开始。

**变更的接口/组件**

getData()/剪贴板服务（pasteboard_service）

**适配指导**

在module.json5中按需声明ohos.permission.READ_PASTEBOARD权限以访问剪贴板，示例代码片段如下：
```ts
"requestPermissions": [
  {
    "name": "ohos.permission.READ_PASTEBOARD"
  }
]
```