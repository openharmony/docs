# Setting Input Method Subtypes

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3103aea9f27e22b8029f7224f57c27c4f91680cc translatedAt=2026-08-04T08:28:50.086Z pushedAt=2026-08-04T08:42:34.431Z -->

The input method subtypes allow the input method to switch to a specific mode or language, for example, the Chinese or English keyboard.

## Configuring and Implementing an Input Method Subtype

1. An input method application developer only needs to register and implement one InputMethodExtensionAbility. All input method subtypes share this InputMethodExtensionAbility. Add [metadata](../quick-start/module-configuration-file.md#metadata) in the [module.json5 configuration file](../quick-start/module-configuration-file.md), with `name` set to `ohos.extension.input_method`, to configure resource information for all subtypes.

   <!-- @[input_case_entry_module_extensionAbilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/module.json5) -->

   ``` JSON5
   "extensionAbilities": [
     {
       "srcEntry": "./ets/InputMethodExtensionAbility/InputMethodService.ets",
       "name": "InputMethodService",
       "label": "$string:MainAbility_label",
       "description": "$string:extension_ability_descriptor",
       "type": "inputMethod",
       "exported": true,
       "metadata": [
         {
           "name": "ohos.extension.input_method",
           "resource": "$profile:input_method_config"
         }
       ]
     }
   ],
   ```

2. Configure the subtype information based on the configuration file format and fields, and place the subtype configuration file `input_method_config.json` in the **profile** folder under the application's resource directory. For details about the fields, see [InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype). For details about how to configure the **locale** field, see [i18n-locale-culture](.././internationalization/i18n-locale-culture.md#how-it-works).

   ``` JSON5
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

## Obtaining Information About Input Method Subtypes

1. To obtain the current subtype of the current input method, call [getCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodgetcurrentinputmethodsubtype9).

2. To obtain all subtypes of the current input method, call [listCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#listcurrentinputmethodsubtype9).

3. To obtain all subtypes of a specified input method, call [listInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#listinputmethodsubtype9).

## Switching Between Input Method Subtypes

1. To switch to another subtype of the current input method, call [switchCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodsubtype9).

2. To switch to a specified subtype of a specified input method, call [switchCurrentInputMethodAndSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodandsubtype9).