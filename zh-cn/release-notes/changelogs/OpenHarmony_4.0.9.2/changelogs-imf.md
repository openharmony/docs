# 输入法框架子系统-输入法框架ChangeLog

## cl.imf.1 @ohos.InputMethod中on('imeShow')系统接口权限校验失败返回错误码变更

**变更影响**

使用on('imeShow')接口，系统权限校验失败的返回码从201变更为202。

## cl.imf.2 @ohos.InputMethod中on('imeHide')系统接口权限校验失败返回错误码变更

**变更影响**

使用on('imeHide')接口，系统权限校验失败的返回码从201变更为202。

## cl.imf.3 @ohos.InputMethod中off接口新增参数

off接口新增需要取消订阅的回调函数作为可选参数，需要与on接口传入的保持一致。

| 接口                      | 变更前                                | 变更后                                                       |
| ------------------------- | ------------------------------------- | ------------------------------------------------------------ |
| off('insertText')         | off(type: 'insertText'): void         | off(type: 'insertText', callback?: (text: string) => void): void |
| off('deleteLeft')         | off(type: 'deleteLeft'): void         | off(type: 'deleteLeft', callback?: (length: number) => void): void |
| off('deleteRight')        | off(type: 'deleteRight'): void        | off(type: 'deleteRight', callback?: (length: number) => void): void |
| off('sendKeyboardStatus') | off(type: 'sendKeyboardStatus'): void | off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void |
| off('sendFunctionKey')    | off(type: 'sendFunctionKey'): void    | off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void |
| off('moveCursor')         | off(type: 'moveCursor'): void         | off(type: 'moveCursor', callback?: (direction: Direction) => void): void |
| off('handleExtendAction') | off(type: 'handleExtendAction'): void | off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void |
| off('selectByRange')      | off(type: 'selectByRange'): void      | off(type: 'selectByRange', callback?: Callback\<Range\>): void |
| off('selectByMovement')   | off(type: 'selectByMovement'): void   | off(type: 'selectByMovement', callback?: Callback\<Movement\>): void |

**变更影响**

以上接口的调用，有多个订阅回调时，可传入订阅回调函数只取消单个回调函数的订阅，当该参数不填写时，取消订阅对应的所有回调事件。

**适配指导**

请参考接口说明：[@ohos.inputMethod.d.ts](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inputmethod.md)
