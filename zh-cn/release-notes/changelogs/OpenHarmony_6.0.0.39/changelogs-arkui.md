# ArkUI子系统Changelog

## cl.arkui.1 半模态SIDE侧边样式新增避让软键盘能力

**访问级别**

公开接口

**变更原因**

[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)半模态弹窗侧边样式默认支持避让软键盘，提升易用性。

**变更影响**

此变更涉及应用适配。

- 变更前：当半模态样式指定为[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE侧边样式时，[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode设置为[SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明)的避让软键盘方式无效，半模态默认不避让软键盘，需要开发者自定义避让软键盘。
  
- 变更后：当半模态样式指定为[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE侧边样式时，[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode设置为[SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明)的避让软键盘方式将生效，半模态支持避让软键盘，默认值为SheetKeyboardAvoidMode.TRANSLATE_AND_SCROLL。若开发者希望自定义避让软键盘，则需设置属性keyboardAvoidMode = SheetKeyboardAvoidMode.NONE。

**起始API Level**

API 20

**变更发生版本**

从OpenHarmony SDK 6.0.0.39开始。

**变更的接口/组件**

涉及接口：
[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的keyboardAvoidMode属性。

[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE半模态侧边样式。

**适配指导**

默认行为变更，当半模态样式指定为[SheetType](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheettype11枚举说明)的SIDE侧边样式时，若开发者期望自定义避让软键盘，则需要设置[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode = [SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明).NONE。

若开发者期望采用半模态控件自带的避让软键盘能力，则可以设置[bindSheet](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)的属性keyboardAvoidMode = [SheetKeyboardAvoidMode](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetkeyboardavoidmode13枚举说明)的其他枚举值，或者不设置属性keyboardAvoidMode，采用默认值。
