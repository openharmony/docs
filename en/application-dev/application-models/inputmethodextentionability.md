# InputMethodExtensionAbility

## When to Use
[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md), inherited from [ExtensionAbility](extensionability-overview.md), is used for developing input method applications.

The entire lifecycle of the [InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md) instance and the owning ExtensionAbility process is scheduled and managed by the input method framework. The input method framework provides the [InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md) base class. Derive this base class to implement initialization and resource clearing.

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md) provides related capabilities through [InputMethodExtensionContext](../reference/apis/js-apis-inputmethod-extension-context.md).


## Implementing an Input Method Application

InputMethodExtensionAbility provides the **onCreate()** and **onDestory()** callbacks, as described below. Override them as required.  

- **onCreate**
  This callback is triggered when a service is created for the first time. You can perform initialization operations, for example, registering a common event listener.

  > **NOTE**
  >
  > If a service has been created, starting it again does not trigger the **onCreate()** callback.

- **onDestroy**
  This callback is triggered when the service is no longer used and the instance is ready for destruction. You can clear resources in this callback, for example, deregister the listener.


## How to Develop

To implement an input method application, manually create an InputMethodExtensionAbility component in DevEco Studio. The procedure is as follows:

In the **ets** directory of the target module, right-click and choose **New** > **Extension Ability** > **InputMethod** to a minimum template of InputMethodExtensionAbility.

> **NOTE**
> 
> When compiling the input method application, use the signature at the system_basic level. Otherwise, the application will not be able to start the keyboard.

The minimum template implements an input method application with the most basic features, such as starting the keyboard, entering text, and deleting input. You can diversify the feature set of the application by, for example, adding the feature to hide the keyboard.

The minimum template contains four files: **KeyboardController.ts**, **InputMethodService.ts**, **Index.ets**, and **KeyboardKeyData.ts**. The file directory is as follows:

```
/src/main/
├── ets/inputmethodextability
│   └──model/KeyboardController.ts			# Shows the keyboard.
│   └──InputMethodService.ts				# Customizes a class that inherits from InputMethodExtensionAbility and add the required lifecycle callbacks.
│   └──pages
│      └── Index.ets						# Draws the keyboard and adds the input and deletion features.
│      └── KeyboardKeyData.ts			    # Defines keyboard attributes.
├── resources/base/profile/main_pages.json   
```

## File Introduction

1. **InputMethodService.ts** file:

   In the **InputMethodService.ts** file, add the dependency package for importing InputMethodExtensionAbility. Customize a class that inherits from InputMethodExtensionAbility and add the required lifecycle callbacks.

   ```ts
   import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
   import { KeyboardController } from './model/KeyboardController'
   
   export default class InputDemoService extends InputMethodExtensionAbility {
     private keyboardController: KeyboardController;
   
     onCreate(want) {
       this.keyboardController = new KeyboardController(this.context);
       this.keyboardController.onCreate();  // Initialize the window and register an event listener for the input method framework.
     }
   
     onDestroy() {
       console.log("onDestroy.");
       this.keyboardController.onDestroy(); // Destroy the window and deregister the event listener.
     }
   }
   ```

2. **KeyboardController.ts** file:

   ```ts
   import inputMethodEngine from '@ohos.inputMethodEngine';
   import display from '@ohos.display';
   import windowManager from '@ohos.window';
   
   // Call the getInputMethodAbility API to obtain an instance, and then call the other APIs of the input method framework based on the instance.
   globalThis.inputAbility = inputMethodEngine.getInputMethodAbility();
   
   export class KeyboardController {
     mContext;	// Save the context attribute in InputMethodExtensionAbility.
     WINDOW_TYPE_INPUT_METHOD_FLOAT = 2105;		// Define the window type. The value 2105 indicates the input method window type, which is used to create an input method application window.
     windowName = 'inputApp';
     private windowHeight: number = 0;
     private windowWidth: number = 0;
     private nonBarPosition: number = 0;
     private isWindowShowing: boolean = false;
   
     constructor(context) {
       this.mContext = context;
     }
   
     public onCreate(): void
     {
       this.initWindow();				// Initialize the window.
       this.registerListener();		// Register an event listener for the input method framework.
     }
   
     public onDestroy(): void			// Destroy the instance.
     {
       this.unRegisterListener();		// Deregister the event listener.
       let win = windowManager.findWindow(this.windowName);
       win.destroyWindow();				// Destroy the window.
     }
   
     private initWindow(): void		// Initialize the window.
     {
       let dis = display.getDefaultDisplaySync();
       let dWidth = dis.width;
       let dHeight = dis.height;
       let keyHeightRate = 0.47;
       let keyHeight = dHeight * keyHeightRate;
       this.windowWidth = dWidth;
       this.windowHeight = keyHeight;
       this.nonBarPosition = dHeight - keyHeight;
   
       let config = {
         name: this.windowName,
         windowType: this.WINDOW_TYPE_INPUT_METHOD_FLOAT,
         ctx: this.mContext
       }
       windowManager.createWindow(config).then((win) => {	// Create a window of the specified type.
         win.resize(dWidth, keyHeight).then(() => {
           win.moveWindowTo(0, this.nonBarPosition).then(() => {
             win.setUIContent('pages/InputMethodExtAbility/Index').then(() => {
             });
           });
         });
       });
     }
   
     private registerListener(): void
     {
       this.registerInputListener();	// Register an event listener for the input method framework service.
       globalThis.inputAbility.on('keyboardShow', () => {// Register an event listener for the keyboard .
         if (this.isWindowShowing) {
           return;
         }
         this.isWindowShowing = true;
         this.showHighWindow(); // Show the window.
       });
       ...
       // Register a listener for keyboard hiding.
     }
   
     private registerInputListener() {		// Register a listener for the enabling and disabling events of the input method framework service.
       globalThis.inputAbility.on('inputStart', (kbController, textInputClient) => {
         globalThis.textInputClient = textInputClient;		// This is an input method client instance, based on which you can call the functional APIs that the input method framework provides for the input method application.
         globalThis.keyboardController = kbController;
       })
       globalThis.inputAbility.on('inputStop', (imeId) => {
         if (imeId == "Bundle name/Ability name") {
           this.mContext.destroy(); // Destroy the InputMethodExtensionAbility service.
         }
       });
     }
   
     private unRegisterListener(): void
     {
       globalThis.inputAbility.off('inputStart');
       globalThis.inputAbility.off('inputStop', () => {});
       globalThis.inputAbility.off('keyboardShow');
     }
   
     private showHighWindow() {
       let win = windowManager.findWindow(this.windowName)
       win.resize(this.windowWidth, this.windowHeight).then(() => {
         win.moveWindowTo(0, this.nonBarPosition).then(() => {
           win.showWindow().then(() => {
             this.isWindowShowing = false;
           })
         })
       })
     }
   }
   ```

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
   import { numberSourceListData, sourceListType } from './keyboardKeyData'
   
   @Component
   struct keyItem {
     private keyValue: sourceListType
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
       .onTouch((event: TouchEvent) => {
         if (event.type === TouchType.Down) {
           globalThis.textInputClient.insertText(this.keyValue.content);
         }
       })
     }
   }
   
   // Component used for deletion.
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
       .onTouch((event: TouchEvent) => {
         if (event.type === TouchType.Down) {
           globalThis.textInputClient.deleteForward(1);
         }
       })
     }
   }
   
   // Numeric keyboard
   @Component
   struct numberMenu {
     private numberList: sourceListType[]
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceEvenly }) {
         Flex({ justifyContent: FlexAlign.SpaceBetween }) {
           ForEach(this.numberList, (item: sourceListType) => {  // First row on the numeric keyboard
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

5. Register the InputMethodExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) corresponding to the **Module** project. Set **type** to **"inputMethod"** and **srcEntry** to the code path of the InputMethodExtensionAbility component.

   ```ts
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "description": "inputMethod",
           "icon": "$media:icon",
           "name": "InputMethodExtAbility",
           "srcEntry": "./ets/inputmethodextability/InputMethodService.ts",
           "type": "inputMethod",
           "exported": true,
         }
       ]
     }
   }
   ```


