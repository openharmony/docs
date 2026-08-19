# @StorageProp: Unidirectional Data Synchronization with AppStorage

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:02:06.332Z pushedAt=2026-08-14T03:16:13.580Z -->

**\@StorageProp** is used in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to establish unidirectional data synchronization with the corresponding property in [AppStorage](./ts-state-management.md#appstorage). The changes of the corresponding property in AppStorage are synchronized to the variable decorated with **\@StorageProp**, but the changes of the variable decorated with **\@StorageProp** will not be synchronized back to AppStorage. It is applicable to scenarios where the global state changes of AppStorage need to be detected across pages and [abilities](../../apis-ability-kit/js-apis-ability-ability.md) and only unidirectional data flow is required. This can avoid unnecessary data writeback.

For details, see [AppStorage: Storing Application-wide UI State](../../../ui/state-management/arkts-appstorage.md).

> **NOTE**
>
> This decorator is supported since API version 7.

## @StorageProp

const StorageProp: (value: string) => PropertyDecorator

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type   | Mandatory | Description                       |
| ------ | ------ | ---- | -------------------------- |
| value  | string | Yes   | Property key name in AppStorage, which is used to establish unidirectional data synchronization with the property corresponding to the key name. If the property corresponding to the key name already exists in AppStorage, the local initial value of the variable decorated with **\@StorageProp** will be overwritten by the value of the corresponding property in AppStorage. If the property corresponding to the key name does not exist in AppStorage, the corresponding property will be created in AppStorage based on the local initial value of the variable decorated with **\@StorageProp**. |

**Return value**

| Type              | Description                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
// Create initial data for AppStorage. The key is 'PropA' and the value is 47.
AppStorage.setOrCreate('PropA', 47);
// Create initial data for AppStorage. The key is 'PropB' and the value is undefined.
AppStorage.setOrCreate('PropB', undefined);

@Entry
@Component
struct StoragePropComponent {
  // Use @StorageProp to establish unidirectional data synchronization with the property corresponding to 'PropA' in AppStorage.
  // Changes in AppStorage will be synchronized to the component, but local changes in the component will not be synchronized back to AppStorage.
  @StorageProp('PropA') propA: number | null = null;
  // Use @StorageProp to establish unidirectional data synchronization with the property corresponding to 'PropB' in AppStorage.
  @StorageProp('PropB') propB: number | undefined = undefined;

  build() {
    Column() {
      Text('@StorageProp initialization, @StorageProp value')
      Text(`${this.propA}`)
        .fontSize(20)
        .onClick(() => {
          // Click to change the value of propA. The change will not be synchronized to AppStorage.
          this.propA = this.propA ? null : 1;
        })
      Text(`${this.propB}`)
        .fontSize(20)
        .onClick(() => {
          // Click to change the value of propB. The change will not be synchronized to AppStorage.
          this.propB = this.propB ? undefined : 1;
        })
    }
  }
}
```