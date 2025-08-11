# Implementing an Input Method Application
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) provides the **onCreate()** and **onDestroy()** callbacks, as described below. Override them as required. InputMethodExtensionAbility lifecycle:

- **onCreate()**

  This callback is triggered when a service is created for the first time. You can perform initialization operations, for example, registering a common event listener.

  > **NOTE**
  >
  > If an InputMethodExtensionAbility has been created, starting it again does not trigger the **onCreate()** callback.

- **onDestroy()**

  This callback is triggered when the service is no longer used and the instance is ready for destruction. You can clear resources in this callback, for example, deregister the listener.


## How to Develop

<!--RP1-->
To implement an input method application, manually create an InputMethodExtensionAbility component in DevEco Studio. The procedure is as follows:

1. In the **ets** directory of the target module, right-click and choose **New** > **Directory** to create a directory named **InputMethodExtensionAbility**.

2. Right-click the **InputMethodExtensionAbility** directory, choose **New** > **File**, and create four files: **KeyboardController.ts**, **InputMethodService.ts**, **Index.ets**, and **KeyboardKeyData.ts**. The file directory is as follows:

``` 
/src/main/
├── ets/InputMethodExtensionAbility
│       └──model/KeyboardController.ts			# Shows the keyboard.
│       └──InputMethodService.ts				# Customizes a class that inherits from InputMethodExtensionAbility and add the required lifecycle callbacks.
│       └──pages
│         └── Index.ets						# Draws the keyboard and adds the input and deletion features.
│         └── KeyboardKeyData.ts			    # Defines keyboard attributes.
├── resources/base/profile/main_pages.json  
```
<!--RP1End-->

## Related Files

1. **InputMethodService.ts** file:

   In the **InputMethodService.ts** file, add the dependency package for importing InputMethodExtensionAbility. Customize a class that inherits from InputMethodExtensionAbility and add the required lifecycle callbacks.

   ```ts
   import { Want } from '@kit.AbilityKit';
   import keyboardController from './model/KeyboardController';
   import { InputMethodExtensionAbility } from '@kit.IMEKit';
   
   export default class InputDemoService extends InputMethodExtensionAbility {
   
     onCreate(want: Want): void {
       keyboardController.onCreate(this.context); // Initialize the window and register an event listener for the input method framework.
     }
   
     onDestroy(): void {
       console.log("onDestroy.");
       keyboardController.onDestroy(); // Destroy the window and deregister the event listener.
     }
   }
   ```

<!--RP2-->
2. **KeyboardController.ts** file:

   ```ts
   import { display } from '@kit.ArkUI';
   import { inputMethodEngine, InputMethodExtensionContext } from '@kit.IMEKit';
   
   // Call the getInputMethodAbility API to obtain an instance, and then call the other APIs of the input method framework based on the instance.
   const inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
   
   export class KeyboardController {
     private mContext: InputMethodExtensionContext | undefined = undefined; // Save the context attribute in InputMethodExtensionAbility.
     private panel: inputMethodEngine.Panel | undefined = undefined; 
     private textInputClient: inputMethodEngine.InputClient | undefined = undefined; 
     private keyboardController: inputMethodEngine.KeyboardController | undefined = undefined;
   
     constructor() {
     }
   
     public onCreate(context: InputMethodExtensionContext): void
     {
       this.mContext = context;
       this.initWindow(); // Initialize the window.
       this.registerListener(); // Register an event listener for the input method framework.
     }
   
     public onDestroy(): void // Destroy the instance.
     {
       this.unRegisterListener(); // Deregister the event listener.
       if(this.panel) { // Destroy the window.
         inputMethodAbility.destroyPanel(this.panel);
       }
       if(this.mContext) {
         this.mContext.destroy();
       }
     }
   
     public insertText(text: string): void {
       if(this.textInputClient) {
         this.textInputClient.insertText(text);
       }
     }
   
     public deleteForward(length: number): void {
       if(this.textInputClient) {
         this.textInputClient.deleteForward(length);
       }
     }
   
     private initWindow(): void // Initialize the window.
     {
       if(this.mContext === undefined) {
         return;
       }
       let dis = display.getDefaultDisplaySync();
       let dWidth = dis.width;
       let dHeight = dis.height;
       let keyHeightRate = 0.47;
       let keyHeight = dHeight * keyHeightRate;
       let nonBarPosition = dHeight - keyHeight;
       let panelInfo: inputMethodEngine.PanelInfo = {
         type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
         flag: inputMethodEngine.PanelFlag.FLG_FIXED
       };
       inputMethodAbility.createPanel(this.mContext, panelInfo).then(async (inputPanel: inputMethodEngine.Panel) => {
         this.panel = inputPanel;
         if(this.panel) {
           await this.panel.resize(dWidth, keyHeight);
           await this.panel.moveTo(0, nonBarPosition);
           await this.panel.setUiContent('InputMethodExtensionAbility/pages/Index');
         }
       });
     }
   
     private registerListener(): void
     {
       this.registerInputListener(); // Register an event listener for the input method framework service.
       // Register a listener for keyboard hiding.
     }
   
     private registerInputListener(): void { // Register a listener for the enabling and disabling events of the input method framework service.
       inputMethodAbility.on('inputStart', (kbController, textInputClient) => {
         this.textInputClient = textInputClient; // This is an input method client instance, based on which you can call the APIs that the input method framework provides for the input method.
         this.keyboardController = kbController;
       })
       inputMethodAbility.on('inputStop', () => {
         this.onDestroy (); // Destroy the KeyboardController instance.
       });
     }
   
     private unRegisterListener(): void
     {
       inputMethodAbility.off('inputStart');
       inputMethodAbility.off('inputStop', () => {});
     }
   }
   
   const keyboardController = new KeyboardController();
   
   export default keyboardController;
   ```
<!--RP2End-->
3. **KeyboardKeyData.ts** file:

   In this file you can define the content displayed on the soft keyboard.

   ```ts
   export interface sourceListType {
     content: string,
   }
   
   export let numberSourceListData: sourceListType[] = [
     {
       content: '1'
     },
     {
       content: '2'
     },
     {
       content: '3'
     },
     {
       content: '4'
     },
     {
       content: '5'
     },
     {
       content: '6'
     },
     {
       content: '7'
     },
     {
       content: '8'
     },
     {
       content: '9'
     },
     {
       content: '0'
     }
   ]
   ```

4. **Index.ets** file:

   This file describes the functions of keys. For example, the number keys print numbers in the text box, and the delete key deletes what's entered.

   Add the path to this file to the **src** field in the **resources/base/profile/main_pages.json** file.

   ```ets
   import { numberSourceListData, sourceListType } from './KeyboardKeyData';
   import keyboardController from '../model/KeyboardController';
   
   @Component
   struct keyItem {
     private keyValue: sourceListType = numberSourceListData[0];
     @State keyBgc: string = "#fff"
     @State keyFontColor: string = "#000"
   
     build() {
       Column() {
         Flex({ direction: FlexDirection.Column,
           alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
           Text(this.keyValue.content).fontSize(20).fontColor(this.keyFontColor)
         }
       }
       .backgroundColor(this.keyBgc)
       .borderRadius(6)
       .width("8%")
       .height("65%")
       .onClick(() => {
         keyboardController.insertText(this.keyValue.content);
       })
     }
   }
   
   // Component used for deletion
   @Component
   export struct deleteItem {
     @State keyBgc: string = "#fff"
     @State keyFontColor: string = "#000"
   
     build() {
       Column() {
         Flex({ direction: FlexDirection.Column,
           alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
           Text("Delete").fontSize(20).fontColor(this.keyFontColor)
         }
       }
       .backgroundColor(this.keyBgc)
       .width("13%")
       .borderRadius(6)
       .onClick(() => {
         keyboardController.deleteForward(1);
       })
     }
   }
   
   // Numeric keyboard
   @Component
   struct numberMenu {
     private numberList: sourceListType[] = numberSourceListData;
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceEvenly }) {
         Flex({ justifyContent: FlexAlign.SpaceBetween }) {
           ForEach(this.numberList, (item: sourceListType) => { // First row on the numeric keyboard
             keyItem({ keyValue: item })
           }, (item: sourceListType) => item.content);
         }
         .padding({ top: "2%" })
         .width("96%")
         .height("25%")
   
         Flex({ justifyContent: FlexAlign.SpaceBetween }) {
           deleteItem()
         }
         .width("96%")
         .height("25%")
       }
     }
   }
   
   @Entry
   @Component
   struct Index {
     private numberList: sourceListType[] = numberSourceListData
   
     build() {
       Stack() {
         Flex({
           direction: FlexDirection.Column,
           alignItems: ItemAlign.Center,
           justifyContent: FlexAlign.End
         }) {
               Flex({
                 direction: FlexDirection.Column,
                 alignItems: ItemAlign.Center,
                 justifyContent: FlexAlign.SpaceBetween
               }) {
                 numberMenu({
                   numberList: this.numberList
                 })
               }
               .align(Alignment.End)
               .width("100%")
               .height("75%")
             }
         .height("100%").align(Alignment.End).backgroundColor("#cdd0d7")
       }
       .position({ x: 0, y: 0 }).zIndex(99999)
     }
   }
   ```

<!--Del-->
5. **module.json5** file:<br>Register the InputMethodExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) corresponding to the **Module** project. Set **type** to **"inputMethod"** and **srcEntry** to the code path of the **InputMethodExtensionAbility** component.

   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "description": "inputMethod",
           "name": "InputMethodExtensionAbility",       
           "icon": "$media:app_icon",
           "srcEntry": "./ets/InputMethodExtensionAbility/InputMethodService.ts",
           "type": "inputMethod",
           "exported": true
         }
       ]
     }
   }
   ```
<!--DelEnd-->


<!--RP3-->

<!--RP3End-->

## Constraints

To protect the InputMethodExtensionAbility against abuse, functional constraints of the basic access mode are provided.

> **NOTE**
>
> Strictly comply with the functional constraints of the basic access mode. In this mode, you should provide only basic typing features, not interaction with online services in any form. The system will gradually introduce measures for compliance with the basic access mode, including but not limited to running the Extension process as an independent process and in sandbox mode, preventing the Extension process from creating subprocesses, and restricting inter-process communication and network access. Violations may result in service exceptions.
