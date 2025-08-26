# Data Synchronization Between UIAbility and UI Page


Based on the application model, you can use any of the following ways to implement data synchronization between [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) components and UI pages:

- [Using EventHub for Data Synchronization](#using-eventhub-for-data-synchronization): The [EventHub](../reference/apis-ability-kit/js-apis-inner-application-eventHub.md) object is provided by the [base class Context](../reference/apis-ability-kit/js-apis-inner-application-context.md). It allows events to be transferred using the publish/subscribe (pub/sub) pattern. Specifically, after subscribing to an event, your application will receive the event and process it accordingly when the event is published.
- [Using AppStorage or LocalStorage for Data Synchronization](#using-appstorage-or-localstorage-for-data-synchronization): ArkUI provides two application-level state management solutions: [AppStorage](../ui/state-management/arkts-appstorage.md) and [LocalStorage](../ui/state-management/arkts-localstorage.md), which implement application- and UIAbility-level data synchronization, respectively.


## Using EventHub for Data Synchronization

[EventHub](../reference/apis-ability-kit/js-apis-inner-application-eventHub.md) provides an event mechanism for the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component so that they can subscribe to, unsubscribe from, and trigger events.

In the [base class Context](../reference/apis-ability-kit/js-apis-inner-application-context.md), the EventHub object is provided for communication within the UIAbility component instance. Before using EventHub to implement data communication between the UIAbility and UI, you must obtain an EventHub object. This section uses EventHub as an example. 

1. Call [eventHub.on()](../reference/apis-ability-kit/js-apis-inner-application-eventHub.md#eventhubon) in the UIAbility in either of the following ways to register a custom event **event1**.

    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { UIAbility, Context, Want, AbilityConstant } from '@kit.AbilityKit';

    const DOMAIN_NUMBER: number = 0xFF00;
    const TAG: string = '[EventAbility]';

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
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
        hilog.info(DOMAIN_NUMBER, TAG, '1. ' + `${argOne}, ${argTwo}`);
        return;
      }
    }
    ```

2. Call [eventHub.emit()](../reference/apis-ability-kit/js-apis-inner-application-eventHub.md#eventhubemit) on the UI page to trigger the event, and pass in the parameters as required.

    ```ts
    import { common } from '@kit.AbilityKit';

    @Entry
    @Component
    struct Page_EventHub {
      private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

      eventHubFunc(): void {
        // Trigger the event without parameters.
        this.context.eventHub.emit('event1');
        // Trigger the event with one parameter.
        this.context.eventHub.emit('event1', 1);
        // Trigger the event with two parameters.
        this.context.eventHub.emit('event1', 2, 'test');
        // You can design the parameters based on your service requirements.
      }

      build() {
        Column() {
          // ...
          List({ initialIndex: 0 }) {
            ListItem() {
              Row() {
                // ...
              }
              .onClick(() => {
                this.eventHubFunc();
                this.getUIContext().getPromptAction().showToast({
                  message: 'EventHubFuncA'
                });
              })
            }

            // ...
            ListItem() {
              Row() {
                // ...
              }
              .onClick(() => {
                this.context.eventHub.off('event1');
                this.getUIContext().getPromptAction().showToast({
                  message: 'EventHubFuncB'
                });
              })
            }
            // ...
          }
          // ...
        }
        // ...
      }
    }
    ```

3. Obtain the event trigger result from the subscription callback of the UIAbility. The run log result is as follows:

    ```json
    [Example].[Entry].[EntryAbility] 1. []
    [Example].[Entry].[EntryAbility] 1. [1]
    [Example].[Entry].[EntryAbility] 1. [2,"test"]
    ```
   
4. When **event1** is not needed, call [eventHub.off()](../reference/apis-ability-kit/js-apis-inner-application-eventHub.md#eventhuboff) to unsubscribe from the event.

    ```ts
    import { UIAbility } from '@kit.AbilityKit';

    export default class EntryAbility extends UIAbility {
      // ... 
      onDestroy(): void {
        this.context.eventHub.off('event1');
      }
    }
    ```

## Using AppStorage or LocalStorage for Data Synchronization

ArkUI provides two application-level state management solutions: [AppStorage](../ui/state-management/arkts-appstorage.md) and [LocalStorage](../ui/state-management/arkts-localstorage.md), which implement data synchronization at the application or [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) level, respectively. Both solutions can be used to manage the application state, enhance application performance, and improve user experience. The AppStorage is a global state manager that manages state data shared among multiple UIAbility components. The LocalStorage is a local state manager that manages state data used inside a single UIAbility. They help you control the application state more flexibly and improve the maintainability and scalability of applications. For details, see [State Management of Application-Level Variables](../ui/state-management/arkts-application-state-management-overview.md).
