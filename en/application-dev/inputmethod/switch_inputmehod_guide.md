# Switching Between Input Methods

In the input method framework service, you can call the provided APIs to easily switch between input methods and input method subtypes.

> **NOTE**
>
> 1. The following APIs can be called only in the current input method application.
>
> 2. For details about how to implement an input method application, see [Implementing an Input Method Application](./inputmethod_application_guide.md).

## Switching Between Input Method Subtypes

1. When in the input method application in use, call **inputMethod.switchCurrentInputMethodSubtype** to switch to another subtype – specified by **InputMethodSubtype** – of the input method.

   ```ts
   import { InputMethodSubtype, inputMethod } from '@kit.IMEKit';
   
   export class KeyboardController {
     async switchCurrentInputMethodSubtype() {
       let subTypes = await inputMethod.getSetting().listCurrentInputMethodSubtype(); // Obtain all subtypes of the current input method.
       let currentSubType = await inputMethod.getCurrentInputMethodSubtype(); // Obtain the current subtype of the current input method.
       for(let i=0;i<subTypes.length;i++) {
         if(subTypes[i].id != currentSubType.id) { // If the current subtype is not the specified one, switch to the specified one. You can enter a fixed subtype as required.
           await inputMethod.switchCurrentInputMethodSubtype(subTypes[i]);
         }
       }
     }
   }
   ```

2. Register a listener in the input method application for subtype changes, so as to load a subtype-specific soft keyboard UI.

   ```ts
   import { InputMethodSubtype, inputMethod } from '@kit.IMEKit';
   
   export class KeyboardController {
     // Register a listener in the input method application for subtype changes.
     inputMethodAbility.on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
       if(inputMethodSubtype.id == 'InputMethodExtAbility') {
         this.panel.setUiContent('pages/Index'); // Assume that the panel has been created in the onCreate process in the input method application.
       }
       if(inputMethodSubtype.id == 'InputMethodExtAbility1') {
         this.panel.setUiContent('pages/Index1'); // Assume that the panel has been created in the onCreate process in the input method application.
       }
     });
   }
   ```

## Switching Between Input Methods

When in the input method application in use, call **inputMethod.switchInputMethod** to switch to another input method specified by **InputMethodProperty**.

```ts
import { inputMethod } from '@kit.IMEKit';

export class KeyboardController {
  async switchInputMethod(){
    let inputMethods = await inputMethod.getSetting().getInputMethods(true); // Obtain the list of enabled input methods.
    let currentInputMethod = await inputMethod.getCurrentInputMethod(); // Obtain the current input method.
    for(let i=0;i<inputMethods.length;i++) {
      if(inputMethods[i].name != currentInputMethod.name) { // If the current input method is not the specified one, switch to the specified one. You can enter a fixed input method as required.
        await inputMethod.switchInputMethod(inputMethods[i]);
      }
    }
  }
}
```

## Switching Between Input Methods and Subtypes

When in the input method application in use, call **inputMethod.switchCurrentInputMethodAndSubtype** to switch to a specific subtype (specified by **InputMethodSubtype**) of another input method (specified by **InputMethodProperty**).

```ts
import { inputMethod } from '@kit.IMEKit';

export class KeyboardController {
  async switchInputMethodAndSubtype() {
    let inputMethods = await inputMethod.getSetting().getInputMethods(true); // Obtain the list of enabled input methods.
    let currentInputMethod = await inputMethod.getCurrentInputMethod(); // Obtain the current input method.
    for (let i = 0;i < inputMethods.length; i++) {
      if (inputMethods[i].name != currentInputMethod.name) { // If the current input method is not the specified one, switch to the specified one. You can enter a fixed input method as required.
        let subTypes = await inputMethod.getSetting().listInputMethodSubtype(inputMethods[i]); // Obtain the subtypes of the target input method.
        await inputMethod.switchCurrentInputMethodAndSubtype(inputMethods[i], subTypes[0]); // This example switches to the first obtained subtype.
      }
    }
  }
}
```
