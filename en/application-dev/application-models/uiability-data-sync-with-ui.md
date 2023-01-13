# Data Synchronization Between UIAbility and UI


Based on the OpenHarmony application model, you can use either of the following ways to implement data synchronization between the UIAbility component and UI:

- EventHub: It is implemented based on the publish/subscribe (pub/sub) pattern. Your application subscribes to an event and when the event occurs, receives a notification.

- globalThis: It is a global object accessible in the ArkTS engine instance.


## Using EventHub for Data Synchronization

EventHub provides an event mechanism at the UIAbility or ExtensionAbility component level. Centered on the UIAbility or ExtensionAbility component, EventHub provides data communication capabilities for subscribing to, unsubscribing from, and triggering events. For details, see [EventHub](../reference/apis/js-apis-inner-application-eventHub.md).

Before using EventHub, you must obtain an EventHub object, which is provided by the [base class Context](application-context-stage.md). This section uses EventHub as an example to describe how to implement data synchronization between the UIAbility component and the UI.

1. Call eventHub.on() in the UIAbility in either of the following ways to register a custom event **event1**.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';

   const TAG: string = '[Example].[Entry].[EntryAbility]';

   export default class EntryAbility extends UIAbility {
       func1(...data) {
           // Trigger the event to complete the service operation.
           console.info(TAG, '1. ' + JSON.stringify(data));
       }

       onCreate(want, launch) {
           // Obtain an eventHub object.
           let eventhub = this.context.eventHub;
           // Subscribe to the event.
           eventhub.on('event1', this.func1);
           eventhub.on('event1', (...data) => {
               // Trigger the event to complete the service operation.
               console.info(TAG, '2. ' + JSON.stringify(data));
           });
       }
   }
   ```

2. Call eventHub.emit() on the UI to trigger the event, and pass the parameters as required.

   ```ts
   import common from '@ohos.app.ability.common';

   @Entry
   @Component
   struct Index {
     private context = getContext(this) as common.UIAbilityContext;

     eventHubFunc() {
       // Trigger the event without parameters.
       this.context.eventHub.emit('event1');
       // Trigger the event with one parameter.
       this.context.eventHub.emit('event1', 1);
       // Trigger the event with two parameters.
       this.context.eventHub.emit('event1', 2, 'test');
       // You can design the parameters based on your service requirements.
     }

     // Page display.
     build() {
       // ...
     }
   }
   ```

3. Obtain the event trigger result from the subscription callback of UIAbility. The run log result is as follows:

   ```ts
   []

   [1]

   [2,'test']
   ```

4. After **event1** is used, you can call eventHub.off() to unsubscribe from the event.

   ```ts
   // context is the ability context of the UIAbility instance.
   this.context.eventHub.off('event1');
   ```


## Using globalThis for Data Synchronization


**globalThis** is a global object inside the [ArkTS engine instance](thread-model-stage.md) and can be used by UIAbility, ExtensionAbility, and Page inside the engine. Therefore, you can use **globalThis** for data synchronization.

  **Figure 1** Using globalThis for data synchronization
<img src="figures/globalThis1.png" alt="globalThis1" style="zoom:67%;" />


The following describes how to use **globalThis** in three scenarios. Precautions are provided as well.

- [Using globalThis Between UIAbility and Page](#using-globalthis-between-uiability-and-page)
- [Using globalThis Between UIAbility and UIAbility](##using-globalthis-between-uiability-and-uiability)
- [Use globalThis Between UIAbility and ExtensionAbility](#using-globalthis-between-uiability-and-extensionability)
- [Precautions for Using globalThis](#precautions-for-using-globalthis)

### Using globalThis Between UIAbility and Page

You can use **globalThis** to bind attributes or methods to implement data synchronization between the UIAbility component and UI. For example, if you bind the **want** parameter in the UIAbility component, you can use the **want** parameter information on the UI corresponding to the UIAbility component.

1. When **startAbility()** is called to start a UIAbility instance, the **onCreate()** callback is invoked, and the **want** parameter can be passed in the callback. Therefore, you can bind the **want** parameter to **globalThis**.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class EntryAbility extends UIAbility {
       onCreate(want, launch) {
           globalThis.entryAbilityWant = want;
           // ...
       }

       // ...
   }
   ```

2. Use **globalThis** on the UI to obtain the **want** parameter information.

   ```ts
   let entryAbilityWant;
   
   @Entry
   @Component
   struct Index {
     aboutToAppear() {
       entryAbilityWant = globalThis.entryAbilityWant;
     }
   
     // Page display.
     build() {
       // ...
     }
   }
   ```


### Using globalThis Between UIAbility and UIAbility

To implement data synchronization between two UIAbility components in the same application, you can bind data to **globalThis**. For example, you can save data in **globalThis** in AbilityA and obtain the data from AbilityB.

1. AbilityA stores a string and binds it to globalThis.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class AbilityA extends UIAbility {
       onCreate(want, launch) {
           globalThis.entryAbilityStr = 'AbilityA'; // AbilityA stores the string "AbilityA" to globalThis.
           // ...
       }
   }
   ```

2. Obtain the data from AbilityB.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'
   
   export default class AbilityB extends UIAbility {
       onCreate(want, launch) {
           // AbilityB reads the name from globalThis and outputs it.
           console.info('name from entryAbilityStr: ' + globalThis.entryAbilityStr);
           // ...
       }
   }
   ```


### Using globalThis Between UIAbility and ExtensionAbility

To implement data synchronization between the UIAbility and ExtensionAbility components in the same application, you can bind data to **globalThis**. For example, you can save data in **globalThis** in AbilityA and obtain the data from ServiceExtensionAbility.

1. AbilityA stores a string and binds it to globalThis.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class AbilityA extends UIAbility {
       onCreate(want, launch) {
           // AbilityA stores the string "AbilityA" to globalThis.
           globalThis.entryAbilityStr = 'AbilityA';
           // ...
       }
   }
   ```

2. Obtain the data from ExtensionAbility.

   ```ts
   import Extension from '@ohos.app.ability.ServiceExtensionAbility'
   
   export default class ServiceExtAbility extends Extension {
       onCreate(want) {
           / / ServiceExtAbility reads name from globalThis and outputs it.
           console.info('name from entryAbilityStr: ' + globalThis.entryAbilityStr);
           // ...
       }
   }
   ```


### Precautions for Using globalThis

  **Figure 2** Precautions for globalThis
![globalThis2](figures/globalThis2.png)

- In the stage model, all the UIAbility components in a process share one ArkTS engine instance. When using **globalThis**, do not store objects with the same name. For example, if AbilityA and AbilityB use **globalThis** to store two objects with the same name, the object stored earlier will be overwritten.

- This problem does not occur in the FA model because each UIAbility component uses an independent engine.

- The lifecycle of an object bound to **globalThis** is the same as that of the ArkTS engine instance. You are advised to assign the value **null** after using the object to minimize memory usage.

The following provides an example to describe the object overwritten problem in the stage model.

1. In the AbilityA file, [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) is stored in **globalThis**.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class AbilityA extends UIAbility {
       onCreate(want, launch) {
           globalThis.context = this.context; // AbilityA stores the context in globalThis.
           // ...
       }
   }
   ```

2. Obtain and use [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) on the page of Ability A. After the AbilityA instance is used, switch it to the background.

   ```ts
   @Entry
   @Component
   struct Index {
     onPageShow() {
       let ctx = globalThis.context; // Obtain the context from globalThis and use it.
       let permissions = ['com.example.permission']
       ctx.requestPermissionsFromUser(permissions,(result) => {
          // ...
       });
     }
     // Page display.
     build() {
       // ...
     }
   }
   ```

3. In the AbilityB file, [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) is stored in **globalThis** and has the same name as that in the AbilityA file.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class AbilityB extends UIAbility {
       onCreate(want, launch) {
           // AbilityB overwrites the context stored by AbilityA in globalThis.
           globalThis.context = this.context;
           // ...
       }
   }
   ```

4. Obtain and use [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) on the page of Ability B. The obtained **globalThis.context** is the value of [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) in AbilityB.

   ```ts
   @Entry
   @Component
   struct Index {
     onPageShow() {
       let ctx = globalThis.context; // Obtain the context from globalThis and use it.
       let permissions = ['com.example.permission']
       ctx.requestPermissionsFromUser(permissions,(result) => {
         console.info('requestPermissionsFromUser result:' + JSON.stringify(result));
       });
     }
     // Page display.
     build() {
       // ...
     }
   }
   ```

5. Switch the AbilityB instance to the background and switch the AbilityA instance to the foreground. In this case, AbilityA will not enter the **onCreate()** lifecycle again.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility'

   export default class AbilityA extends UIAbility {
       onCreate(want, launch) { // AbilityA will not enter this lifecycle.
           globalThis.context = this.context;
           // ...
       }
   }
   ```

6. When the page of AbilityA is displayed, the obtained **globalThis.context** is [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) of AbilityB instead of AbilityA. An error occurs.

   ```ts
   @Entry
   @Component
   struct Index {
     onPageShow() {
       let ctx = globalThis.context; // The context in globalThis is the context of AbilityB.
       let permissions=['com.example.permission'];
       ctx.requestPermissionsFromUser(permissions,(result) => { // Using this object causes a process breakdown.
          console.info('requestPermissionsFromUser result:' + JSON.stringify(result));
       });
     }
     // Page display.
     build() {
       // ...
     }
   }
   ```
