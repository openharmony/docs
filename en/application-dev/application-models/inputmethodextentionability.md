# InputMethodExtensionAbility

## When to Use
[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md), inherited from [ExtensionAbility](extensionability-overview.md), is used for developing input method applications.

The entire lifecycle of the [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) instance and the owning ExtensionAbility process is scheduled and managed by the input method framework. The input method framework provides the [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) base class. Derive this base class to implement initialization and resource clearing.

[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) provides related capabilities through [InputMethodExtensionContext](../reference/apis-ime-kit/js-apis-inputmethod-extension-context.md).


## Implementing an Input Method Application

[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) provides the **onCreate()** and **onDestroy()** callbacks, as described below. Override them as required.  

- **onCreate()**

  This callback is triggered when a service is created for the first time. You can perform initialization operations, for example, registering a common event listener.

  > **NOTE**
  >
  > If a service has been created, starting it again does not trigger the **onCreate()** callback.

- **onDestroy()**

  This callback is triggered when the service is no longer used and the instance is ready for destruction. You can clear resources in this callback, for example, deregister the listener.


## How to Develop

To implement an input method application, manually create an InputMethodExtensionAbility component in DevEco Studio. The procedure is as follows:

1. In the **ets** directory of the target module, right-click and choose **New > Directory** to create a directory named **InputMethodExtensionAbility**.

2. Right-click the **InputMethodExtensionAbility** directory, choose **New** > **File**, and create four files: **KeyboardController.ts**, **InputMethodService.ts**, **Index.ets**, and **KeyboardKeyData.ts**. The file directory is as follows:

```
/src/main/
├── ets/InputMethodExtensionAbility
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
   import Want from '@ohos.app.ability.Want';
   import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
   import keyboardController from './model/KeyboardController'
   
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

2. **KeyboardController.ts** file:

   ```ts
   import common from '@ohos.app.ability.common';
   import display from '@ohos.display';
   import inputMethodEngine from '@ohos.inputMethodEngine';
   import InputMethodExtensionContext from '@ohos.InputMethodExtensionContext';
   
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
         this.panel.hide();
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
           await this.panel.setUiContent('inputmethodextability/pages/Index');
         }
       });
     }
   
     private registerListener(): void
     {
       this.registerInputListener(); // Register an event listener for the input method framework service.
       ...
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
   import { numberSourceListData, sourceListType } from './keyboardKeyData';
   import keyboardController from '../InputMethodExtensionAbility/model/KeyboardController';
   
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
           ForEach(this.numberList, (item: sourceListType) => {// First row on the numeric keyboard
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

   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "description": "inputMethod",
           "icon": "$media:icon",
           "name": "InputMethodExtAbility",
           "srcEntry": "./ets/InputMethodExtensionAbility/InputMethodService.ts",
           "type": "inputMethod",
           "exported": true,
         }
       ]
     }
   }
   ```

## Verification

1. Run the hdc command to display the dialog box for switching between input methods: **hdc shell aa start ability -a InputMethod -b com.ohos.inputmethodchoosedialog**

2. In the dialog box for switching between input methods, switch the input method to the demo application.

3. When you touch any edit box, the demo application should start.

## Constraints

To protect the InputMethodExtensionAbility against abuse, the invoking of APIs in the modules listed below is restricted in the InputMethodExtensionAbility.

> **NOTE**
>
> - If a restricted module is imported, no error is reported during compilation, but an incorrect value (**undefined**) is returned during running, which renders the imported module ineffective.
> - Currently, access to the [@ohos.multimedia.audio (Audio Management)](../reference/apis-audio-kit/js-apis-audio.md) module is allowed, but subject to the following rules:
>   - Users who deny the recording permission should still be allowed to use the non-voice-input features of the input method application.
>   - Recording-related services are allowed only when the InputMethodExtensionAbility is in the foreground. For example, perform recording only when the soft keyboard is in the foreground and the user is proactively using the voice input method; stop recording when the application is switched to the background.
>   - Applications will be subject to increasingly stringent measures against violations with the preceding rules, and any violation may result in service exceptions.

**Module list:**

- [@ohos.ability.featureAbility (FeatureAbility)](../reference/apis-ability-kit/js-apis-ability-featureAbility.md)
- [@ohos.ability.particleAbility (ParticleAbility)](../reference/apis-ability-kit/js-apis-ability-particleAbility.md)
- [@ohos.account.distributedAccount (Distributed Account Management)](../reference/apis-basic-services-kit/js-apis-distributed-account.md)
- [@ohos.backgroundTaskManager (Background Task Management)](../reference/apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)
- [@ohos.bluetooth (Bluetooth)](../reference/apis-connectivity-kit/js-apis-bluetooth.md)
- [@ohos.bluetoothManager (Bluetooth)](../reference/apis-connectivity-kit/js-apis-bluetoothManager.md)
- [@ohos.connectedTag (Active Tags)](../reference/apis-connectivity-kit/js-apis-connectedTag.md)
- [@ohos.geolocation (Geolocation)](../reference/apis-location-kit/js-apis-geolocation.md)
- [@ohos.geoLocationManager (Geolocation Manager)](../reference/apis-location-kit/js-apis-geoLocationManager.md)
- [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../reference/apis-connectivity-kit/js-apis-cardEmulation.md)
- [@ohos.nfc.controller (Standard NFC)](../reference/apis-connectivity-kit/js-apis-nfcController.md)
- [@ohos.nfc.tag (Standard NFC Tags)](../reference/apis-connectivity-kit/js-apis-nfcTag.md)
- [@ohos.reminderAgent (reminderAgent)](../reference/apis-backgroundtasks-kit/js-apis-reminderAgent.md)
- [@ohos.reminderAgentManager (Agent-Powered Reminders)](../reference/apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)
- [@ohos.sensor (Sensor)](../reference/apis-sensor-service-kit/js-apis-sensor.md)
- [@ohos.telephony.call (Call)](../reference/apis-telephony-kit/js-apis-call.md)
- [@ohos.telephony.data (Cellular Data)](../reference/apis-telephony-kit/js-apis-telephony-data.md)
- [@ohos.telephony.observer (observer)](../reference/apis-telephony-kit/js-apis-observer.md)
- [@ohos.telephony.radio (Network Search)](../reference/apis-telephony-kit/js-apis-radio.md)
- [@ohos.telephony.sim (SIM Management)](../reference/apis-telephony-kit/js-apis-sim.md)
- [@ohos.telephony.sms (SMS)](../reference/apis-telephony-kit/js-apis-sms.md)
- [@ohos.telephony.call (Call) (System API)](../reference/apis-telephony-kit/js-apis-call-sys.md)
- [@ohos.telephony.data (Cellular Data) (System API)](../reference/apis-telephony-kit/js-apis-telephony-data-sys.md)
- [@ohos.telephony.observer (Observer) (System API)](../reference/apis-telephony-kit/js-apis-observer-sys.md)
- [@ohos.telephony.radio (Radio) (System API)](../reference/apis-telephony-kit/js-apis-radio-sys.md)
- [@ohos.telephony.sim (SIM Management) (System API)](../reference/apis-telephony-kit/js-apis-sim-sys.md)
- [@ohos.telephony.sms (SMS) (System API)](../reference/apis-telephony-kit/js-apis-sms-sys.md)
- [@ohos.wallpaper (Wallpaper)](../reference/apis-basic-services-kit/js-apis-wallpaper.md)
- [@ohos.wifiext (WLAN Extension)](../reference/apis-connectivity-kit/js-apis-wifiext.md)
- [@ohos.wifiManager (WLAN)](../reference/apis-connectivity-kit/js-apis-wifiManager.md)
- [@ohos.wifiManagerExt (WLAN Extension)](../reference/apis-connectivity-kit/js-apis-wifiManagerExt.md)
- [@system.geolocation (Geolocation)](../reference/apis-location-kit/js-apis-system-location.md)
- [nfctech (Standard NFC Technologies)](../reference/apis-connectivity-kit/js-apis-nfctech.md)
- [tagSession (Standard NFC Tag Session)](../reference/apis-connectivity-kit/js-apis-tagSession.md)

<!--no_check-->

  
