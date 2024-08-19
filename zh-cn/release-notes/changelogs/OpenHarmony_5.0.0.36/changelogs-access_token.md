# 程序访问控制子系统变更说明

## cl.access_token.1 变更

**访问级别**

公开接口

**变更原因**

若设置宽度小于当前属性组合下允许的最小宽度时，宽度不会缩减到设置值，此时宽度会大于设置宽度，以保证安全控件显示的完整性。Menu等组件集成安全控件后，若安全控件的实际宽度大于父组件的设定宽度，安全控件的按钮信息会被截断，导致安全控件不可用。

**变更影响**

该变更为不兼容变更。

变更前：

若设置宽度小于当前属性组合下允许的最小宽度时，宽度不会缩减到设置值，此时宽度会大于设置宽度，以保证安全控件显示的完整性。

变更后：

若设置宽度小于当前属性组合下允许的最小宽度时，宽度会调整到设置值，此时按钮文本信息会自动换行，以保证安全控件显示的完整性。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.36 版本开始。

**变更的接口/组件**

@internal/component/ets/location_button.d.ts中 LocationButton接口。

@internal/component/ets/save_button.d.ts中 SaveButton接口。

@internal/component/ets/paste_button.d.ts中 PasteButton接口。

**适配指导**

接口使用的示例代码可参考：

[LocationButton接口指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-locationbutton.md#接口)

[SaveButton接口指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md#接口)

[PasteButton接口指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-pastebutton.md#接口)
