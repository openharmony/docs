# @SyncMonitor: Synchronous Listening for Value Changes of the State Variables

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2996efc9552d09a1d03764710258d0fca6157cdc translatedAt=2026-08-13T07:02:03.983Z pushedAt=2026-08-14T03:18:38.836Z -->

**\@SyncMonitor** is used for [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to synchronously listen to the changes of state variables, enabling deep listening for state variables. It is applicable to scenarios where precise listening to deep state changes, such as changes in nested object properties and in elements in an array, is required. This addresses the issue that traditional listening methods cannot detect changes in deep-level properties, thereby improving the accuracy of state management and development efficiency.

For details, see [@SyncMonitor Decorator: Synchronous Listening for Value Changes of the State Variables](../../../ui/state-management/arkts-new-syncmonitor.md).

> **NOTE**
>
> This decorator is supported since API version 23.

## @SyncMonitor

const SyncMonitor: MonitorDecorator

**Atomic service API:** This API can be used in atomic services since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Type     | Description                                         |
| -------- | -------------------------------------------- |
| [MonitorDecorator](./ts-state-management-monitor.md#monitordecorator) | @SyncMonitor decorator type. |

**Error codes**

For details about the error codes, see [State Management Error Codes](../errorcode-stateManagement.md).

| ID | Error Message             |
| -------- | -------------------- |
| 130001   | The path is invalid. |

**Example**

```ts
@Entry
@ComponentV2
struct Index {
  @Local message: string = 'Hello World';
  @Local name: string = 'Tom';

  // Use @SyncMonitor to listen for the changes of message and name at the same time.
  @SyncMonitor('message', 'name')
  onStrChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`message: ${this.message}`)
      Text(`name: ${this.name}`)
      Button('change string')
        .onClick(() => {
          // Modify message and trigger the onStrChange callback.
          this.message += '!';
          // Modify name and trigger the onStrChange callback.
          this.name = 'Jack';
        })
    }
  }
}
```