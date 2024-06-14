# 输入法子类型开发指南

输入法子类型允许输入法展现不同的输入模式或语言，用户可以根据需要在不同模式和语言中切换。如：输入法的中文键盘、英文键盘等都属于输入法的子类型。

## 输入法子类型的配置与实现

1. 输入法应用开发者只需要注册实现一个InputMethodExtensionAbility，所有的输入法子类型共用该InputMethodExtensionAbility，在[module.json5配置文件](../quick-start/module-configuration-file.md)中添加metadata，name为ohos_extension.input_method，用于配置所有子类型的资源信息。
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
   
2. 子类型配置文件格式如下，字段释义参照[InputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod-subtype.md#inputmethodsubtype)，开发者需要严格按照配置文件格式及字段进行子类型信息配置, locale字段的配置参照[BCP 47](https://tools.ietf.org/html/bcp47)。
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
   
3. 输入法应用中监听子类型事件，根据不同的子类型，可以加载不同的软键盘界面，或者使用状态变量控制界面中的软键盘显示。

   ```ts
   import { InputMethodSubtype, inputMethodEngine } from '@kit.IMEKit';
   
   let panel: inputMethodEngine.Panel;
   let inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
   inputMethodAbility.on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
     let subType = inputMethodSubtype; // 保存当前输入法子类型, 此处也可以改变状态变量的值，布局中判断状态变量，不同的子类型显示不同的布局控件
     if (inputMethodSubtype.id == 'InputMethodExtAbility') { // 根据不同的子类型，可以加载不同的软键盘界面
       panel.setUiContent('pages/Index'); 
     }
     if (inputMethodSubtype.id == 'InputMethodExtAbility1') { // 根据不同的子类型，可以加载不同的软键盘界面
       panel.setUiContent('pages/Index1');
     }
   });
   ```

## 输入法子类型相关信息的获取

1. 开发者可以通过调用[getCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodgetcurrentinputmethodsubtype9)获取当前输入法应用的当前子类型。

2. 开发者可以通过调用[listCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#listcurrentinputmethodsubtype9)获取当前输入法应用的所有子类型。

3. 开发者可以通过调用[listInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#listinputmethodsubtype9)获取指定输入法应用的所有子类型。


## 输入法子类型的切换

1. 开发者可以通过调用[switchCurrentInputMethodSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodsubtype9)切换当前输入法应用的子类型。

2. 开发者可以通过调用[switchCurrentInputMethodAndSubtype](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchcurrentinputmethodandsubtype9)切换至指定输入法应用的指定子类型。
