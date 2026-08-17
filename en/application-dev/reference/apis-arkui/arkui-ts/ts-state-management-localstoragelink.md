# @LocalStorageLink: Bidirectional Data Synchronization with LocalStorage

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:00:46.610Z pushedAt=2026-08-14T01:47:35.212Z -->

**\@LocalStorageLink** is used in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to establish bidirectional data synchronization with the property corresponding to the specified key in [LocalStorage](./ts-state-management.md#localstorage9). When either the variable decorated by **\@LocalStorageLink** or the corresponding property in LocalStorage changes, the change will be synchronized to the other party. This is applicable to scenarios where the UI state needs to be shared among multiple components and data needs to be synchronized with LocalStorage in real time. It can avoid layer-by-layer data transfer and ensure cross-component data consistency.

For details, see [LocalStorage: Storing Page-Level UI State](../../../ui/state-management/arkts-localstorage.md).

> **NOTE**
>
> This decorator is supported since API version 9.

## @LocalStorageLink

const LocalStorageLink: (value: string) => PropertyDecorator

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type   | Mandatory | Description                         |
| ------ | ------ | ---- | ---------------------------- |
| value  | string | Yes   | Property key name in LocalStorage, which is used to establish bidirectional data synchronization with the property corresponding to the key name. If the property corresponding to the key name already exists in LocalStorage, the local initial value of the variable decorated with **\@LocalStorageLink** will be overwritten by the value of the corresponding property in LocalStorage. If the property corresponding to the key name does not exist in LocalStorage, the corresponding property will be created in LocalStorage based on the local initial value of the variable decorated with **\@LocalStorageLink**. |

**Return value**

| Type              | Description                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
// Create initial data for LocalStorage. The key is 'LinkA' and the value is 47.
const initialData: Record<string, number> = { 'LinkA': 47 };
const storage: LocalStorage = new LocalStorage(initialData);

// Use @Entry to mark the entry component and pass the LocalStorage instance.
@Entry(storage)
@Component
struct Parent {
  // Use @LocalStorageLink to establish bidirectional data synchronization with the 'LinkA' property in LocalStorage.
  @LocalStorageLink('LinkA') linkA: number = 1;

  build() {
    Column() {
      Text(`incr @LocalStorageLink variable`)
        // Set a click event. After the click, the value of linkA is incremented by 1, and the change is synchronized to LocalStorage.
        .onClick(() => {
          this.linkA += 1;
        })
      // Display the value of the variable decorated with @LocalStorageLink.
      Text(`@LocalStorageLink: ${this.linkA}`)
    }
  }
}
```