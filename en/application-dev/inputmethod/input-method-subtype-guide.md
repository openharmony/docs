# Setting Input Method Subtypes

The input method subtypes allow the input method to switch to a specific mode or language, for example, the Chinese or English keyboard.

## Configuring and Implementing an Input Method Subtype

1. Implement an **InputMethodExtensionAbility** instance for an input method, which will be shared by all subtypes of the input method. Add **metadata** with the name **ohos_extension.input_method** to the [module.json5](../quick-start/module-configuration-file.md) file to configure resource information for all subtypes.
   ```ts
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "description": "InputMethodExtDemo",
           "icon": "$media:icon",
           "name": "InputMethodExtAbility",
           "srcEntry": "./ets/InputMethodExtensionAbility/InputMethodService.ts",
           "type": "inputMethod",
           "exported": true,
           "metadata": [
             {
               "name": "ohos.extension.input_method",
               "resource": "$profile:input_method_config"
             }
           ]
         }
       ]
     }
   }
   ```
   
2. Configure the subtype fields. For details about the fields, see [InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype). Make sure your configuration is in strict compliance with the configuration file and field specifications. For details about how to configure the **locale** field, see [BCP 47](https://tools.ietf.org/html/bcp47).
   ```
   {
     "subtypes": [
       {
         "icon": "$media:icon",
         "id": "InputMethodExtAbility",
         "label": "$string:english",
         "locale": "en-US",
         "mode": "lower"
       },
       {
         "icon": "$media:icon",
         "id": "InputMethodExtAbility1",
         "label": "$string:chinese",
         "locale": "zh-CN",
         "mode": "lower"
       }
     ]
   }
   ```
   
3. Register a listener in the input method application for subtype changes, so as to load a subtype-specific soft keyboard UI. You can also use a state variable to change the soft keyboard layout.

   ```ts
   import { InputMethodSubtype, inputMethodEngine } from '@kit.IMEKit';
   
   let panel: inputMethodEngine.Panel;
   let inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
   inputMethodAbility.on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
     let subType = inputMethodSubtype; // Save the current input method subtype. You can also change the state variable value here, based on which different layouts are displayed.
     if (inputMethodSubtype.id == 'InputMethodExtAbility') { // Different soft keyboard UIs are loaded according to the subtype.
       panel.setUiContent('pages/Index'); 
     }
     if (inputMethodSubtype.id == 'InputMethodExtAbility1') { // Different soft keyboard UIs are loaded according to the subtype.
       panel.setUiContent('pages/Index1');
     }
   });
   ```

## Obtaining Information About Input Method Subtypes

1. To obtain the current subtype of the current input method, call [getCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodgetcurrentinputmethodsubtype9).

2. To obtain all subtypes of the current input method, call [listCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#listcurrentinputmethodsubtype9).

3. To obtain all subtypes of a specified input method, call [listInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#listinputmethodsubtype9).


## Switching Between Input Method Subtypes

1. To switch to another subtype of the current input method, call [switchCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodsubtype9).

2. To switch to a specified subtype of a specified input method, call [switchCurrentInputMethodAndSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodandsubtype9).
