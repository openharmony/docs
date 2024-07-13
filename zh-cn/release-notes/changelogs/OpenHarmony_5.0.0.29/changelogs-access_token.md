# 程序访问控制子系统变更说明

## cl.access_token.1 变更

**访问级别**

公开接口

**变更原因**

安全控件可设置背托的属性为不可见或透明，应用可利用此配置将安全控件对用户隐藏，若用户在不知情的情况下触发点击授权，应用就会获取用户的位置、剪切板等敏感信息。

**变更影响**

该变更为非兼容性变更。

变更前：

1. 安全控件按钮在构造函数中不设置背托时，安全控件不展示背托。

2. 安全控件按钮背景色高八位的α值低于0x1a（例如0x1800ff00）时，安全控件的背托透明度显示和开发者的设置值一致。

变更后：

1. 安全控件按钮在构造函数中不设置背托时，安全控件默认展示背托。

2. 安全控件按钮背景色高八位的α值低于0x1a（例如0x1800ff00）时，安全控件按钮背景色高八位的α值会被系统强制调整为0xff。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 版本开始。

**变更的接口/组件**

@internal/component/ets/location_button.d.ts中 LocationButton接口。

@internal/component/ets/save_button.d.ts中 SaveButton接口。

@internal/component/ets/paste_button.d.ts中 PasteButton接口。

**适配指导**

接口使用的示例代码可参考：

[LocationButton接口指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-locationbutton.md#接口)

[SaveButton接口指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md#接口)

[PasteButton接口指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-pastebutton.md#接口)
