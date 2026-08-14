# @StorageLink: Bidirectional Data Synchronization with AppStorage

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:01:58.171Z pushedAt=2026-08-14T03:10:55.639Z -->

**\@StorageLink** is used in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to establish bidirectional data synchronization with the property of a specified key in [AppStorage](./ts-state-management.md#appstorage). When the variable decorated with **\@StorageLink** changes, the change is synchronized to the property corresponding to the key in AppStorage. When the property corresponding to the key in AppStorage changes, the change is also synchronized back to the variable decorated with **\@StorageLink**. It is applicable to scenarios where the global state of AppStorage needs to be shared across pages and [abilities](../../apis-ability-kit/js-apis-ability-ability.md) and bidirectional data synchronization with AppStorage is required. It can avoid layer-by-layer state data transfer to ensure data consistency.

For details, see [AppStorage: Storing Application-wide UI State](../../../ui/state-management/arkts-appstorage.md).

> **NOTE**
>
> This decorator is supported since API version 7.

## @StorageLink

const StorageLink: (value: string) => PropertyDecorator

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Parameter Name | Type   | Required | Description                       |
| ------ | ------ | ---- | -------------------------- |
| value  | string | Yes   | Property key name in AppStorage, which is used to establish bidirectional data synchronization with the property corresponding to the key name. If the property corresponding to the key name already exists in AppStorage, the local initial value of the variable decorated with **\@StorageLink** will be overwritten by the value of the corresponding property in AppStorage. If the property corresponding to the key name does not exist in AppStorage, the corresponding property will be created in AppStorage based on the local initial value of the variable decorated with **\@StorageLink**. |

**Return value**

| Type              | Description                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
// Create initial data for AppStorage. The key is 'LinkA' and the value is 47.
AppStorage.setOrCreate('LinkA', 47);
// Create initial data for AppStorage. The key is 'LinkB' and the value is undefined.
AppStorage.setOrCreate('LinkB', undefined);

@Entry
@Component
struct StorageLinkComponent {
  // Use @StorageLink to establish bidirectional data synchronization with the property corresponding to 'LinkA' in AppStorage.
  @StorageLink('LinkA') linkA: number | null = null;
  // Use @StorageLink to establish bidirectional data synchronization with the property corresponding to 'LinkB' in AppStorage.
  @StorageLink('LinkB') linkB: number | undefined = undefined;

  build() {
    Column() {
      Text('@StorageLink initialization, @StorageLink value')
      Text(`${this.linkA}`)
        .fontSize(20)
        .onClick(() => {
          // Click to change the value of linkA. The change will be synchronized to AppStorage.
          this.linkA = this.linkA ? null : 1;
        })
      Text(`${this.linkB}`)
        .fontSize(20)
        .onClick(() => {
          // Click to change the value of linkB. The change will be synchronized to AppStorage.
          this.linkB = this.linkB ? undefined : 1;
        })
    }
  }
}
```