# Switching Between Input Methods

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8e856b06a34a819612cae112a81452d688b21bcf translatedAt=2026-08-15T01:52:28.625Z pushedAt=2026-08-15T08:40:27.867Z -->

You can use the APIs of the input method framework service to easily switch between input methods and input method subtypes.

> **NOTE**
>
> 1. The following APIs can be called only in the current input method application.
>
> 2. This example assumes that an input method application has been executed. For details about how to implement an input method application, see [Implementing an Input Method Application](./inputmethod-application-guide.md).

## Switching Between Input Method Subtypes

1. In the input method application in use, call [switchCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodsubtype9) with the target [InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype) to switch to another subtype of the current input method.

   <!-- @[input_case_input_switchInputMethodgetInputMethods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/ets/components/Submenu.ets) -->

   ``` TypeScript
   async switchCurrentInputMethodSubtype(item: InputMethodSubtype) {
     try {
       await inputMethod.switchCurrentInputMethodSubtype(item);
       this.currentInputMethodSubtype = inputMethod.getCurrentInputMethodSubtype().id;
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       console.error(`SwitchCurrentInputMethodSubtype error: ${error.code} ${error.message}`);
     }
   }
   ```

2. Register a listener in the input method application for subtype changes, so as to load a subtype-specific keyboard UI.

   <!-- @[input_case_input_KeyboardControllersetSubtype](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/ets/InputMethodExtensionAbility/model/KeyboardController.ets) -->

   ``` TypeScript
   // Register a listener in the input method application for subtype changes.
   inputMethodAbility.on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
     if (inputMethodSubtype.id === 'InputMethodExtAbility') {
       AppStorage.setOrCreate('subtypeChange', 0);
     }
     if (inputMethodSubtype.id === 'InputMethodExtAbility1') {
       AppStorage.setOrCreate('subtypeChange', 1);
     }
   });
   ```

## Switching Between Input Methods

In the input method application in use, call [switchInputMethod](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9) with the target [InputMethodProperty](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodproperty8) to switch to another input method.

   <!-- @[input_case_input_switchInputMethod](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/ets/components/Submenu.ets) -->

   ``` TypeScript
   async switchInputMethod(item: string) {
     try {
       this.inputMethods = await inputMethod.getSetting().getInputMethods(true); // Obtain the list of enabled input methods.
       let currentInputMethod = inputMethod.getCurrentInputMethod(); // Obtain the current input method.
       for (let i = 0; i < this.inputMethods.length; i++) {
         if (item != currentInputMethod.name) { // If the current input method is not the specified one, switch to the specified one. You can switch to a fixed input method as required.
           await inputMethod.switchInputMethod(this.inputMethods[i]);
         }
       }
     } catch (err) {
       let error = err as BusinessError;
       Log.showError(TAG, `switchInputMethod catch error: ${error.code} ${error.message}`);
     }
   }
   ```

## Switching Between Input Methods and Subtypes

In the input method application in use, call [switchCurrentInputMethodAndSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodandsubtype9) with the target [InputMethodProperty](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodproperty8) and [InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype) to switch to the specified subtype of another input method.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethod } from '@kit.IMEKit';

export class KeyboardController {
  async switchInputMethodAndSubtype() {
    try {
      let inputMethods: Array<inputMethod.InputMethodProperty> =
        await inputMethod.getSetting().getInputMethods(true); // Obtain the list of enabled input methods.
      let currentInputMethod: inputMethod.InputMethodProperty = inputMethod.getCurrentInputMethod(); // Obtain the current input method.
      for (let i = 0; i < inputMethods.length; i++) {
        if (inputMethods[i].name != currentInputMethod.name) { // If the current input method is not the specified one, switch to the specified one. You can enter a fixed input method as required.
          let subTypes = await inputMethod.getSetting().listInputMethodSubtype(inputMethods[i]); // Obtain the subtypes of the target input method.
          if (subTypes.length > 0) {
            await inputMethod.switchCurrentInputMethodAndSubtype(inputMethods[i], subTypes[0]); // This example switches to the first obtained subtype by default.
          }
          return;
        }
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`Failed to switchCurrentInputMethodAndSubtype, code: ${err.code}, message: ${err.message}`);
    }
  }
}
```