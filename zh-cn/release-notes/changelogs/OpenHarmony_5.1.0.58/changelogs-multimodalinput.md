# 多模输入子系统变更说明

## cl.multimodalinput.1 oh_input_manager.h 文件中 OH_Input_AddInputEventInterceptor 和 OH_Input_AddKeyEventInterceptor 接口规格变更

**访问级别**

公开接口

**变更原因**

规格变更，新增拦截事件的约束限制。

**变更影响**

此变更不涉及应用适配。

变更前：针对按键事件和输入事件，添加拦截后，拦截即可生效。
  
变更后：添加拦截后，按键事件仅在应用获焦时拦截，失焦时不拦截；输入事件仅在命中应用窗口时拦截，否则不拦截。

**起始API Level**

API 12

**变更发生的版本**

从OpenHarmony SDK 5.1.0.58开始。

**变更的接口**

oh_input_manager.h 文件中如下接口：

- [OH_Input_AddInputEventInterceptor](../../../application-dev/reference/apis-input-kit/input.md#oh_input_addinputeventinterceptor)
- [OH_Input_AddKeyEventInterceptor](../../../application-dev/reference/apis-input-kit/input.md#oh_input_addkeyeventinterceptor)

**适配指导**

无需适配。