# 多模输入子系统变更说明

## @ohos.multimodalInput.inputEventClient.d.ts 文件接口权限变更

**访问级别**

系统接口。

**变更原因**

根据安全要求规范，将该文件的所有接口函数添加注入权限。

**变更影响**

该变更为非兼容性变更，接口权限变更后，接口仍能编译成功，但是接口原本的功能无法正常使用，调用接口会抛出201错误码。

**起始API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口**

| 接口声明 | 变更前 | 变更后 |
| ------------------------------------------------------------ | --------- | ------ |
| function injectKeyEvent(keyEvent: KeyEventData): void;       | 不需要权限 | 需要ohos.permission.INJECT_INPUT_EVENT权限 |
| function injectEvent({ KeyEvent: KeyEvent }): void;          | 不需要权限 | 需要ohos.permission.INJECT_INPUT_EVENT权限 |
| function injectMouseEvent(mouseEvent: MouseEventData): void; | 不需要权限 | 需要ohos.permission.INJECT_INPUT_EVENT权限 |
| function injectTouchEvent(touchEvent: TouchEventData): void; | 不需要权限 | 需要ohos.permission.INJECT_INPUT_EVENT权限 |
| function permitInjection(result: boolean): void;             | 不需要权限 | 需要ohos.permission.INJECT_INPUT_EVENT权限 |

**适配指导**

业务申请并配置ohos.permission.INJECT_INPUT_EVENT权限，仅用于该场景使用。