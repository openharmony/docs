# 窗口子系统变更说明

## cl.window.1 OH_NativeWindowManager_RegisterKeyEventFilter接口注册的回调事件中，回调函数参数Input_KeyEvent注入变更

**访问级别**

公开接口

**变更原因**

修复回调函数注入[Input_KeyEvent](../../../application-dev/reference/apis-input-kit/input.md)结构体的[Input_KeyEventAction](../../../application-dev/reference/apis-input-kit/input.md#input_keyeventaction)字段时，注入值无法匹配枚举的bug。变更前注入Input_KeyEventAction的值为1、2、3分别对应取消（KEY_ACTION_CANCEL）、按下（KEY_ACTION_DOWN）和抬起（KEY_ACTION_UP）三种行为，与枚举中定义的0（KEY_ACTION_CANCEL）、1（KEY_ACTION_DOWN）、2（KEY_ACTION_UP）不匹配。

**变更影响**

该变更为不兼容变更。<br/>
变更前，注入Input_KeyEvent中的Input_KeyEventAction为1、2、3，无法匹配枚举。<br/>
变更后，注入Input_KeyEvent中的Input_KeyEventAction为0、1、2，匹配枚举。<br/>

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.38 版本开始。

**变更的接口/组件**

OH_NativeWindowManager_RegisterKeyEventFilter接口中，回调函数OH_NativeWindowManager_KeyEventFilter的注入实现。

**适配指导**

注入行为bug修复，开发者之前用code作硬编码需要改为对应的Input_KeyEventAction枚举。   
