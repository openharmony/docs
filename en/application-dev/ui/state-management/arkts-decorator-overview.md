# UI Decorator Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @zhangwenhan-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:02:20.483Z pushedAt=2026-07-22T07:42:00.532Z -->

In the declarative UI development paradigm, the UI is the running result of the program state, and changes in state drive UI updates. ArkUI provides a set of decorator mechanisms that enable you to conveniently define and manage state variables, achieving data-UI linkage.

The following table lists the V2 state management decorators in ArkUI.

| V2 State Management Decorator                                   | Decorator Description          |
| --------------------------------------------------- | -------------------- |
| [\@ComponentV2](./arkts-create-custom-components.md#componentv2) | Creates a custom component.       |
| [\@Local](./arkts-new-local.md)                     | Component internal state.       |
| [\@Param](./arkts-new-param.md)                     | Component external input.       |
| [\@Once](./arkts-new-once.md)                       | Synchronizes once during initialization.     |
| [\@Event](./arkts-new-event.md)                     | Standardizes component output.       |
| [\@Provider](./arkts-new-provider-and-consumer.md)  | Two-way synchronization with descendant state. |
| [\@Consumer](./arkts-new-provider-and-consumer.md)  | Two-way synchronization with ancestor state. |
| [\@Monitor](./arkts-new-monitor.md)                 | Asynchronously monitors state variable changes.   |
| [\@SyncMonitor](./arkts-new-syncmonitor.md)                 | Synchronously monitors state variable changes.   |
| [\@Computed](./arkts-new-computed.md)               | Computed property.           |
| [\@ObservedV2](./arkts-new-observedV2-and-trace.md) | Marks a class as observable.       |
| [\@Trace](./arkts-new-observedV2-and-trace.md)      | Marks a class property as observable.   |
| [\@Type](./arkts-new-type.md)                       | Marks the type of a class property.   |
| [\@ReusableV2](./arkts-new-reusableV2.md)           | Marks a component as reusable.     |

The following table lists the V1 state management decorators in ArkUI.

| V1 State Management Decorator                                            | Description                                  |
| ------------------------------------------------------------ | -------------------------------------------- |
| [@Component](./arkts-create-custom-components.md#component) | Creates a custom component.                             |
| [@State](./arkts-state.md)                                  | Basic state variable.                              |
| [@Prop](./arkts-prop.md)                                    | Establishes one-way synchronization between the parent and child states.                      |
| [@Link](./arkts-link.md)                                    | Establishes two-way synchronization between the parent and child states.                      |
| [@ObjectLink](./arkts-observed-and-objectlink.md)           | Observes the changes of nested class object attributes.                    |
| [@Provide](./arkts-provide-and-consume.md)                  | Establishes two-way synchronization with the descendant states.                        |
| [@Consume](./arkts-provide-and-consume.md)                  | Establishes two-way synchronization with the ancestor state.                        |
| [@Watch](./arkts-watch.md)                                  | Observes state variable changes.                          |
| [@StorageLink](./arkts-appstorage.md#storagelink)           | Establishes two-way data synchronization with the corresponding attribute in the AppStorage.  |
| [@StorageProp](./arkts-appstorage.md#storageprop)            | Establishes one-way data synchronization with the corresponding attribute in the AppStorage.  |
| [@LocalStorageLink](./arkts-localstorage.md#localstoragelink) | Establishes two-way data synchronization with the corresponding attribute in the LocalStorage.|
| [@LocalStorageProp](./arkts-localstorage.md#localstorageprop) | Establishes one-way data synchronization with the corresponding attribute in the LocalStorage.|
| [@Observed](./arkts-observed-and-objectlink.md)             | Marks the class observable.                              |
| [@Track](./arkts-track.md)                                  | Class object attribute-level update.                          |
| [@Reusable](./arkts-reusable.md)                            | Marks the component reusable.                            |

The following table lists the common UI decorators in ArkUI.

| Common Decorator                                         | Decorator Description          |
| -------------------------------------------------- | ------------------- |
| [\@Entry](../../reference/apis-arkui/arkui-ts/ts-universal-entry.md#entry) | Marks a page entry.      |
| [\@Builder](./arkts-builder.md)                    | Custom builder function.    |
| [\@LocalBuilder](./arkts-localBuilder.md)          | Maintains component relationships.      |
| [\@BuilderParam](./arkts-builderparam.md)          | References a \@Builder function. |
| [\@Styles](./arkts-style.md)                       | Defines reusable component styles.  |
| [\@Extend](./arkts-extend.md)                      | Defines extended component styles.  |
| [\@AnimatableExtend](./arkts-animatable-extend.md) | Defines animatable attributes.    |
| [\@Require](./arkts-require.md)                    | Validates constructor parameters.      |
| [\@Env](../arkts-env-system-property.md)           | Environment variable.          |