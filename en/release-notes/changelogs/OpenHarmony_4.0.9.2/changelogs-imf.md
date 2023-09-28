# Input Method Framework Subsystem – Input Method Framework Service Changelog

## cl.imf.1 Change of the Error Code Returned When Permission Verification of on('imeShow') Fails

**Change Impact**

For the **on('imeShow')** API, the return code for system permission verification failure is changed from 201 to 202.

## cl.imf.2 Change of the Error Code Returned When Permission Verification of on('imeHide') Fails

**Change Impact**

For the **on('imeHide')** API, the return code for system permission verification failure is changed from 201 to 202.

## cl.imf.3 Parameter Addition of off

An option **callback** parameter is added to the **off** API to specify the callback to be unsubscribed from. Its value must be the same as that passed in the **on** API.

| API                     | Before Change                               | After Change                                                      |
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

**Change Impact**

When calling the preceding APIs, you can pass the **callback** parameter to specify the callback to unsubscribe from. If this parameter is not passed, all callbacks corresponding to the specified type are unsubscribed from.

**Adaptation Guide**

Follow the description in [@ohos.inputMethod.d.ts](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-inputmethod.md).
