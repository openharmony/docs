# 程序访问控制子系统变更说明

## cl.access_token.1 requestPermissionsFromUser接口变更

**访问级别**

公开接口

**变更原因**

应用通过requestPermissionsFromUser接口向用户申请授权，多次调用接口请求相同权限时，会多次弹出相同权限弹窗，且每个弹窗均需要用户点击操作。

**变更影响**

该变更为非兼容性变更。

变更前，通过requestPermissionsFromUser接口同时多次请求权限时，会同时弹出多个权限弹窗；相同权限需要多次点击操作。

变更后，通过requestPermissionsFromUser接口同时多次请求权限时，仅展示一个弹窗；相同权限仅需要点击操作一次。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.22 版本开始。

**变更的接口/组件**

@ohos.abilityAccessCtrl.d.ts中 requestPermissionsFromUser接口。

**适配指导**

接口使用的示例代码可参考[requestPermissionsFromUser接口指导](../../../application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)
