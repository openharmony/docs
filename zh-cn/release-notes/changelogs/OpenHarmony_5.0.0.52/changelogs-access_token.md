# 程序访问控制子系统变更说明

## cl.access_token.1 安全控件UX显示异常的默认行为变更

**访问级别**

公开接口

**变更原因**

应用在集成安全控件时，若安全控件UX显示异常，其仍可点击响应。

**变更影响**

该变更为不兼容变更。

变更前：

应用在集成安全控件时，安全控件UX显示异常时，仍可点击响应。

变更后：

应用在集成安全控件时，安全控件UX显示异常时，点击不响应。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.52 版本开始。

**变更的接口/组件**

@internal/component/ets/location_button.d.ts中 LocationButton接口。

@internal/component/ets/save_button.d.ts中 SaveButton接口。

@internal/component/ets/paste_button.d.ts中 PasteButton接口。

**适配指导**

安全控件的父组件设置[图像效果属性](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md)后，若导致安全控件UX显示不正常，排查安全控件父组件所设置的属性是否为图像效果属性并调整为无效果，不能对安全控件叠加影响UX显示的图像效果。

