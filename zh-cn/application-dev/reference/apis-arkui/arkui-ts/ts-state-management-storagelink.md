# @StorageLink：AppStorage双向数据同步

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@StorageLink是[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)的装饰器，用于与[AppStorage](./ts-state-management.md#appstorage)中指定键名的属性建立双向数据同步：当@StorageLink装饰的变量发生变化时，变更会同步到AppStorage中该键名对应的属性；当AppStorage中该键名对应的属性发生变化时，变更也会同步回@StorageLink装饰的变量。适用于需要跨页面、跨[Ability](../../apis-ability-kit/js-apis-ability-ability.md)共享AppStorage全局状态并与AppStorage保持双向数据同步的场景，可避免逐层传递状态数据，保证数据一致性。

开发指南参考：[AppStorage：应用全局的UI状态存储](../../../ui/state-management/arkts-appstorage.md)。

> **说明：**
>
> 从API version 7开始，支持该装饰器。

## @StorageLink

const StorageLink: (value: string) => PropertyDecorator

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| value  | string | 是   | AppStorage中的属性键名，用于与该键名对应的属性建立双向数据同步。若AppStorage中已存在该键名对应的属性，则@StorageLink装饰变量的本地初始值将被AppStorage中对应属性的值覆盖；若AppStorage中不存在该键名对应的属性，则以@StorageLink装饰变量的本地初始值在AppStorage中创建对应属性。 |

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | 属性装饰器，开发者无需关注该返回值。 |

**示例：**

```ts
// 创建AppStorage的初始数据，键为'LinkA'，值为47
AppStorage.setOrCreate('LinkA', 47);
// 创建AppStorage的初始数据，键为'LinkB'，值为undefined
AppStorage.setOrCreate('LinkB', undefined);

@Entry
@Component
struct StorageLinkComponent {
  // 使用@StorageLink装饰器与AppStorage中'LinkA'对应属性建立双向数据同步
  @StorageLink('LinkA') linkA: number | null = null;
  // 使用@StorageLink装饰器与AppStorage中'LinkB'对应属性建立双向数据同步
  @StorageLink('LinkB') linkB: number | undefined = undefined;

  build() {
    Column() {
      Text('@StorageLink接口初始化，@StorageLink取值')
      Text(`${this.linkA}`)
        .fontSize(20)
        .onClick(() => {
          // 点击切换linkA的值，变更会同步到AppStorage
          this.linkA = this.linkA ? null : 1;
        })
      Text(`${this.linkB}`)
        .fontSize(20)
        .onClick(() => {
          // 点击切换linkB的值，变更会同步到AppStorage
          this.linkB = this.linkB ? undefined : 1;
        })
    }
  }
}
```
