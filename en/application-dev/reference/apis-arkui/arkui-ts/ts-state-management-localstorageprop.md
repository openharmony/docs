# @LocalStorageProp: Unidirectional Data Synchronization with LocalStorage

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:00:48.495Z pushedAt=2026-08-14T01:54:05.423Z -->

**\@LocalStorageProp** is used in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to establish unidirectional data synchronization with the property corresponding to the specified key in [LocalStorage](./ts-state-management.md#localstorage9). After the establishment, changes to the property value in LocalStorage will be synchronized to the variable decorated with **\@LocalStorageProp**, but changes to the variable decorated with **\@LocalStorageProp** will not be synchronized back to LocalStorage. This is applicable to scenarios where LocalStorage needs to be shared among multiple components and only unidirectional data flow is required, avoiding unnecessary data writeback.

For details, see [LocalStorage: Storing Page-Level UI State](../../../ui/state-management/arkts-localstorage.md).

> **NOTE**
>
> This decorator is supported since API version 9.

## @LocalStorageProp

const LocalStorageProp: (value: string) => PropertyDecorator

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type | Mandatory | Description |
| ------ | ------ | ---- | ---------------------------- |
| value | string | Yes | Property key name in LocalStorage, which is used to establish unidirectional data synchronization with the property corresponding to the key name. If the property corresponding to the key name already exists in LocalStorage, the local initial value of the variable decorated with **\@LocalStorageProp** will be overwritten by the value of the corresponding property in LocalStorage. If the property corresponding to the key name does not exist in LocalStorage, the corresponding property will be created in LocalStorage based on the local initial value of the variable decorated with **\@LocalStorageProp**. |

**Return value**

| Type | Description |
| ----------------- | ------------------------------------ |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example**

```ts
// Create initial data for LocalStorage. The key is 'PropA' and the value is 47.
const initialData: Record<string, number> = { 'PropA': 47 };
const storage: LocalStorage = new LocalStorage(initialData);

// Use @Entry to mark the entry component and pass the LocalStorage instance.
@Entry(storage)
@Component
struct Parent {
  // Use @LocalStorageProp to establish unidirectional data synchronization with the 'PropA' property in LocalStorage.
  // Local changes will not be synchronized back to LocalStorage.
  @LocalStorageProp('PropA') propA: number = 1;

  build() {
    Column() {
      Button(`Parent from LocalStorage ${this.propA}`)
        // Set a click event. After the click, the value of propA is incremented by 1, but the change will not be synchronized back to LocalStorage.
        .onClick(() => {
          this.propA += 1;
        })
      Child()
    }
  }
}

@Component
struct Child {
  // Use @LocalStorageProp to establish unidirectional data synchronization with the 'PropA' property in LocalStorage.
  // The propB of the child component will read the value of 'PropA' from LocalStorage, but local changes will not be synchronized back.
  @LocalStorageProp('PropA') propB: number = 2;

  build() {
    Column() {
      Text(`Child from LocalStorage ${this.propB}`)
    }
  }
}
```