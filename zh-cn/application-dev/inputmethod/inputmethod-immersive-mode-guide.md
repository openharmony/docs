# 输入法应用沉浸模式
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## 场景介绍

为了让应用能够提供一致的沉浸式体验，我们提供了前台应用和输入法应用之间的通信机制。通过该机制，输入法应用根据前台应用设置的沉浸模式来决定最终沉浸模式。

## 框架原理
![输入法沉浸模式原理图](./figures/输入法沉浸模式原理图.png)
- 前台应用根据应用场景，设置应用期望的沉浸模式。
- 输入法框架在拉起输入法应用时会将前台应用期望的沉浸模式传递给输入法应用。
- 输入法应用根据前台应用的沉浸模式决定最终的沉浸模式，并设置最终沉浸模式给输入法框架。

## 接入指导
1. 前台应用[设置编辑框沉浸模式](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#keyboardappearance15)。示例代码如下。
   ```ts
   TextArea({text: "hello world"})
      .keyboardAppearance(KeyboardAppearance.IMMERSIVE)
   ```

2. 输入法应用[订阅编辑框属性变化事件](../reference/apis-ime-kit/js-apis-inputmethodengine.md#oneditorattributechanged10)，通过回调参数EditorAttribute中的immersiveMode字段感知前台应用期望的沉浸模式。示例代码如下。

   ```ts
   import { inputMethodEngine } from '@kit.IMEKit';

   inputMethodEngine.getKeyboardDelegate().on("editorAttributeChanged", (attr : inputMethodEngine.EditorAttribute) => {
      console.info("received editorAttributeChanged, immersiveMode: " + attr.immersiveMode);
   })
   ```

3. 输入法应用[设置沉浸模式](../reference/apis-ime-kit/js-apis-inputmethodengine.md#setimmersivemode15)。 
   - IMMERSIVE表示沉浸模式由输入法应用决定。
   - 输入法应用不能设置IMMERSIVE模式给输入法框架。
   - 如果输入法应用收到前台应用期望的沉浸模式为IMMERSIVE，建议输入法应用根据当前系统所处颜色模式，将最终沉浸模式设置为浅色沉浸模式（LIGHT_IMMERSIVE）或深色沉浸模式（DARK_IMMERSIVE）。


   设置沉浸模式，示例代码如下。setImmersiveMode接口需使用[createPanel](../reference/apis-ime-kit/js-apis-inputmethodengine.md#createpanel10)获取到Panel实例后，通过实例调用。
   ```ts
   import { inputMethodEngine } from '@kit.IMEKit';
   
   let panelInfo: inputMethodEngine.PanelInfo = {
     type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
     flag: inputMethodEngine.PanelFlag.FLG_FIXED
   };
   let inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
   // createPanel需要在InputMethodExtensionAbility的Create声明周期中完成，this.context是InputMethodExtensionAbility中的InputMethodExtensionContext
   inputMethodAbility.createPanel(this.context, panelInfo).then(async (panel: inputMethodEngine.Panel) => {
     let inputPanel: inputMethodEngine.Panel = panel;
     try {
       inputPanel?.setImmersiveMode(inputMethodEngine.ImmersiveMode.LIGHT_IMMERSIVE);
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       console.error(`Failed to setImmersiveMode, code: ${error.code}, message: ${error.message}`);
     }
   }).catch((err: BusinessError) => {
     console.log(`Failed to createPanel, code: ${err.code}, message: ${err.message}`);
   });
   ```
