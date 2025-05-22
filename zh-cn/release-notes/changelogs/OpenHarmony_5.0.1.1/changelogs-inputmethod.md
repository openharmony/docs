# 输入法子系统Changelog

## cl.inputmethod.1 更改InputMethodProperty中label字段取值方式

**访问级别**

公开接口

**变更原因**

为正确显示输入法在列表中的名称，更改InputmethodExtensionAbility中label的获取方式及优先级，明确字段定义，统一规则。

**变更影响**

该变更为不兼容变更。

更改输入法ExtensionAbility中label的获取方式及优先级，会优先获取输入法ExtensionAbility的的label名称。

变更前：

1. 单hap包输入法应用可以正常获取到App的label字段作为输入法列表显示的名称。
2. 多hap包输入法应用若InputmethodExtensionAbility所在的module为entry则可以正常获取到entry的label字段。
3. 多hap包输入法应用若InputmethodExtensionAbility所在的module非entry则无法获取label字段，显示为空。

变更后：

1. 输入法属性InputMethodProperty的label字段优先获取InputmethodExtensionAbility的label字段。

2. 若未填写InputmethodExtensionAbility的label字段并且存在entry的形况下，则使用entry的label字段。

3. 若未填写InputmethodExtensionAbility的label字段不并且存在entry的形况下，则使用AppScope的label字段。


**起始API Level**

8

**变更发生版本**

从OpenHarmony 5.0.1.1 版本开始。

**变更的接口/组件**

InputMethodProperty的属性label

**适配指导**

为确保输入法应用名称在输入法列表中名称的正确显示，建议输入法应用在InputmethodExtensionAbility的module.json5中配置正确的label字段，该字段用于对外显示输入法名称。