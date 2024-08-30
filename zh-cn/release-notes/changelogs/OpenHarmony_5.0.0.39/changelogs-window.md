# 窗口子系统变更说明
## cl.window.1 WindowType.TYPE_INPUT_METHOD接口废弃

**访问级别**

系统接口

**变更原因**

输入法窗口通过输入法框架侧接口控制，其余直接控制输入法行为不可控，进行废弃。

**变更影响**

该变更为兼容性变更。

**起始API Level**

API 13

**变更发生版本**

从OpenHarmony 5.0.0.39 版本开始。

**变更的接口/组件**

window.WindowType.TYPE_INPUT_METHOD。

**适配指导**

不再推荐使用window.WindowType.TYPE_INPUT_METHOD，输入法相关控制都请调用[输入法框架侧接口](../../../application-dev/inputmethod/inputmethod_application_guide.md)执行。
