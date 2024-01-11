# Data Synchronization Between UIAbility and UI Page


Based on the application model, you can use any of the following ways to implement data synchronization between UIAbility components and UI pages:

- [Using EventHub for Data Synchronization](#using-eventhub-for-data-synchronization): The **EventHub** object is provided by the base class **Context**. It allows events to be transferred using the publish/subscribe (pub/sub) pattern. Specifically, after subscribing to an event, your application will receive the event and process it accordingly when the event is published.
- [Using AppStorage or LocalStorage for Data Synchronization](#using-appstorage-or-localstorage-for-data-synchronization): ArkUI provides two application-level state management solutions: AppStorage and LocalStorage, which implement application- and UIAbility-level data synchronization, respectively.


## Using EventHub for Data Synchronization

[EventHub](../reference/apis/js-apis-inner-application-eventHub.md) provides an event mechanism for the UIAbility component so that they can subscribe to, unsubscribe from, and trigger events.

Before using the APIs provided by **EventHub**, you must obtain an **EventHub** object, which is provided by the [base class Context](application-context-stage.md).

1. Call [eventHub.on()](../reference/apis/js-apis-inner-application-eventHub.md#eventhubon) in the UIAbility in either of the following ways to register a custom event **event1**.

   ```ts
   import hilog from '@ohos.hilog';
   import Logger from '../utils/Logger';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import type window from '@ohos.window';
   import type { Context } from '@ohos.abilityAccessCtrl';
   import Want from '@ohos.app.ability.Want'
   
   const TAG: string = '[EventAbility]';
   
   export default class EntryAbility extends UIAbility {
   
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       // Obtain the context of the UIAbility instance.
       let context = this.context;
       // Obtain an eventHub object.
       let eventhub = this.context.eventHub;
       // Subscribe to the event.
       eventhub.on('event1', this.eventFunc);
       eventhub.on('event1', (data: string) => {
         // Trigger the event to complete the service operation.
       });
       hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');
     }
       
       // ...
       
     eventFunc(argOne: Context, argTwo: Context): void {
       Logger.info(TAG, '1. ' + `${argOne}, ${argTwo}`);
       return;
     }
   }
   ```

2. Call [eventHub.emit()](../reference/apis/js-apis-inner-application-eventHub.md#eventhubemit) on the UI page to trigger the event, and pass in the parameters as required.

   ```ts
   import common from '@ohos.app.ability.common';
   import promptAction from '@ohos.promptAction'
   import Want from '@ohos.app.ability.Want';
   
   @Entry
   @Component
   struct Page_EventHub {
   
     private context = getContext(this) as common.UIAbilityContext;
   
     eventHubFunc() : void {
       // Trigger the event without parameters.
       this.context.eventHub.emit('event1');
       // Trigger the event with one parameter.
       this.context.eventHub.emit('event1', 1);
       // Trigger the event with two parameters.
       this.context.eventHub.emit('event1', 2, 'test');
       // You can design the parameters based on your service requirements.
     }
   
     build() {
       Row() {
         Column() {
           Text($r('app.string.Page_UIAbilityFourth'))
             .fontSize(40)
             .fontWeight(FontWeight.Bold)
   
           Button(){
             Text($r('app.string.EventHubFuncA'))
               .fontColor($r('sys.color.ohos_id_color_foreground_contrary'))
               .fontSize($r('sys.float.ohos_id_text_size_button1'))
               .fontWeight(FontWeight.Bold)
           }
           .width(300)
           .height(40)
           .borderRadius($r('sys.float.ohos_id_corner_radius_button'))
           .backgroundColor($r('sys.color.ohos_id_color_component_activated'))
             .onClick(() => {
               this.eventHubFunc();
               promptAction.showToast({
                 message: $r('app.string.EventHubFuncA')
               });
             })
             .margin(3)
   
           Button(){
             Text($r('app.string.EventHubFuncB'))
               .fontColor($r('sys.color.ohos_id_color_foreground_contrary'))
               .fontSize($r('sys.float.ohos_id_text_size_button1'))
               .fontWeight(FontWeight.Bold)
           }
           .width(300)
           .height(40)
           .borderRadius($r('sys.float.ohos_id_corner_radius_button'))
           .backgroundColor($r('sys.color.ohos_id_color_component_activated'))
             .onClick(() => {
               this.context.eventHub.off('event1');
               promptAction.showToast({
                 message: $r('app.string.EventHubFuncB')
               });
             })
             .margin(3)
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

3. Obtain the event trigger result from the subscription callback of the UIAbility. The run log result is as follows:

   ```json
   [Example].[Entry].[EntryAbility] 1. []
   [Example].[Entry].[EntryAbility] 1. [1]
   [Example].[Entry].[EntryAbility] 1. [2,"test"]
   ```
   
4. When **event1** is not needed, call [eventHub.off()](../reference/apis/js-apis-inner-application-eventHub.md#eventhuboff) to unsubscribe from the event.

   ```ts
   // context is the AbilityContext of the UIAbility instance.
   this.context.eventHub.off('event1');
   ```

## Using AppStorage or LocalStorage for Data Synchronization

ArkUI provides AppStorage and LocalStorage to implement application- and UIAbility-level data synchronization, respectively. Both solutions can be used to manage the application state, enhance application performance, and improve user experience. The AppStorage is a global state manager that manages state data shared among multiple UIAbilities. The LocalStorage is a local state manager that manages state data used inside a single UIAbility. They help you control the application state more flexibly and improve the maintainability and scalability of applications. For details, see [State Management of Application-Level Variables](../quick-start/arkts-application-state-management-overview.md).
