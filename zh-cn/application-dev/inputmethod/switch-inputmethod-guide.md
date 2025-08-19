# 切换输入法应用
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

输入法框架服务提供了切换输入法应用的API，支持切换输入法、切换输入法和子类型、切换当前输入法的子类型。

> **说明：**
>
> 1. 以下接口的使用仅允许在当前输入法应用中调用。
>
> 2. 本示例假设已经在输入法应用中执行，如何实现一个输入法应用，请参考[实现一个输入法应用](./inputmethod-application-guide.md)开发指导。

## 切换当前输入法子类型

1. 在已完成一个输入法应用的基础上，当输入法应用是当前输入法时，在输入法应用中使用[switchCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodsubtype9)接口，传入当前输入法的子类型[InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype)作为参数即可切换当前输入法子类型。

   ```ts
   import { InputMethodSubtype, inputMethod } from '@kit.IMEKit';
   
   export class KeyboardController {
     async switchCurrentInputMethodSubtype() {
       let subTypes = await inputMethod.getSetting().listCurrentInputMethodSubtype(); // 获取当前输入法的所有子类型
       let currentSubType = inputMethod.getCurrentInputMethodSubtype(); // 获取当前输入法当前的子类型
       for(let i=0;i<subTypes.length;i++) {
         if(subTypes[i].id != currentSubType.id) { // 判断不是当前的子类型时切换，实际开发中可以根据需要填固定子类型
           await inputMethod.switchCurrentInputMethodSubtype(subTypes[i]);
         }
       }
     }
   }
   ```

2. 输入法应用中注册子类型变化事件，根据不同子类型加载不同的输入界面。

   ```ts
   import { InputMethodSubtype, inputMethodEngine, inputMethod } from '@kit.IMEKit';

   export class KeyboardController {
     async switchCurrentInputMethodSubtype() {
       let panel: inputMethodEngine.Panel;
       let inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
       // 设置监听子类型事件，改变输入法应用界面
       inputMethodAbility.on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
         if(inputMethodSubtype.id == 'InputMethodExtAbility') {
           panel.setUiContent('pages/Index'); // 假设在输入法应用中此时Panel已经在onCreate流程中创建
         }
         if(inputMethodSubtype.id == 'InputMethodExtAbility1') {
           panel.setUiContent('pages/Index1'); // 假设在输入法应用中此时Panel已经在onCreate流程中创建
         }
       });
     }
   }


   ```

## 切换输入法应用

在已完成一个输入法应用的基础上，当输入法应用是当前输入法时，在输入法应用中使用[switchInputMethod](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9)接口，传入目标输入法的[InputMethodProperty](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodproperty8)信息，即可切换输入法到目标输入法应用。

```ts
import { inputMethod } from '@kit.IMEKit';

export class KeyboardController {
  async switchInputMethod(){
    let inputMethods = await inputMethod.getSetting().getInputMethods(true); // 获取已使能的输入法列表
    let currentInputMethod = inputMethod.getCurrentInputMethod(); // 获取当前输入法
    for(let i=0;i<inputMethods.length;i++) {
      if(inputMethods[i].name != currentInputMethod.name) { // 判断不是当前输入法时，切换到该输入法，实际开发中可以切换到固定输入法
        await inputMethod.switchInputMethod(inputMethods[i]);
      }
    }
  }
}
```

## 切换输入法应用和子类型

在已完成一个输入法应用的基础上，当输入法应用是当前输入法时，在输入法应用中使用[switchCurrentInputMethodAndSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodandsubtype9)接口，传入目标输入法的[InputMethodProperty](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodproperty8)，目标输入法的子类型[InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype)信息，即可切换输入法到目标输入法应用的目标子类型。

```ts
import { inputMethod } from '@kit.IMEKit';

export class KeyboardController {
  async switchInputMethodAndSubtype() {
    let inputMethods = await inputMethod.getSetting().getInputMethods(true); // 获取已使能的输入法列表
    let currentInputMethod = inputMethod.getCurrentInputMethod(); // 获取当前输入法
    for (let i = 0;i < inputMethods.length; i++) {
      if (inputMethods[i].name != currentInputMethod.name) { // 判断不是当前输入法时，切换到该输入法，实际开发中可以切换到固定输入法
        let subTypes = await inputMethod.getSetting().listInputMethodSubtype(inputMethods[i]); // 获取目标输入法的子类型
        await inputMethod.switchCurrentInputMethodAndSubtype(inputMethods[i], subTypes[0]); // 本示例默认切换到获取的第一个子类型
      }
    }
  }
}
```