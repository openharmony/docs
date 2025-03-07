# 程序访问控制子系统变更说明

## cl.access_token.1 安全控件offset属性设置行为变更

**访问级别**

公开接口

**变更原因**

应用在集成安全控件时，安全控件通过offset属性设置相对父组件的偏移后，若被父组件裁剪不能完整显示时，其仍可响应点击授权，存在隐私安全风险，可能被恶意应用利用。

**变更影响**

该变更为不兼容变更。

变更前：

应用在集成安全控件时，安全控件通过offset属性设置相对父组件的偏移后，且被父组件裁剪不能完整显示时，其仍可响应点击授权。

例如：

安全控件设置offset属性后被父组件裁剪不能完整显示时，安全控件仍可响应点击授权。

![be_clipped](security_component_be_clipped.png)

变更后：

应用在集成安全控件时，安全控件通过offset属性设置相对父组件的偏移后，且被父组件裁剪不能完整显示时，其不可响应点击授权。

例如：

安全控件设置offset属性后被父组件裁剪不能完整显示时，安全控件不响应点击授权。

![be_clipped](security_component_be_clipped.png)

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.46 版本开始。

**变更的接口/组件**

@internal/component/ets/location_button.d.ts中 LocationButton接口。

@internal/component/ets/save_button.d.ts中 SaveButton接口。

@internal/component/ets/paste_button.d.ts中 PasteButton接口。

**适配指导**

安全控件设置offset属性后被父组件裁剪不能完整显示时，可通过调整offset({x: value, y: value})中x或y值，使得安全控件完整显示。

![not_be_clipped](security_component_not_be_clipped.png)
