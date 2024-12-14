# ArkData方舟数据管理变更说明

## cl.ArkData.1 SetAppShareOptions()和RemoveAppShareOptions()接口从System Api变更为Public Api，接口所需权限变更。

**访问级别**

公开接口

**变更原因**

新规格，申请了系统权限的应用设置或者删除本应用数据的拖拽范围时需要申请ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION权限。

**变更影响**

该变更为不兼容变更

变更前：SetAppShareOptions()和RemoveAppShareOptions()为System Api，只有系统应用可以调用。
        应用设置或者删除本应用数据的拖拽范围时不会校验ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION。

变更后：SetAppShareOptions()和RemoveAppShareOptions()为Public Api，申请白名单的普通应用可以调用。
        应用在设置或者删除本应用数据的拖拽范围时，如未申请ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION，访问会被拦截。

**起始API Level** 

12

**变更发生版本**

从OpenHarmony SDK 5.0.2.52开始。

**变更的接口/组件**

SetAppShareOptions()/标准化数据通路（unifiedDataChannel）
RemoveAppShareOptions()/标准化数据通路（unifiedDataChannel）

**适配指导**

应用需申请白名单，并且在module.json中按需声明ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION，示例代码片段如下：
```ts
"requestPermissions": [
  {
    "name": "ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION"
  }
]
```