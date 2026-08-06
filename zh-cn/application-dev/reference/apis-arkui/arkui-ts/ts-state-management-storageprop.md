# @StorageProp：AppStorage单向数据同步

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@StorageProp用于[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)中，与[AppStorage](./ts-state-management.md#appstorage)中对应的属性建立单向数据同步。AppStorage中对应属性的变化会同步到@StorageProp装饰的变量，但仅修改@StorageProp装饰的变量不会同步回AppStorage。适用于需要跨页面、跨[Ability](../../apis-ability-kit/js-apis-ability-ability.md)感知AppStorage全局状态变化且仅保持单向数据流的场景，可避免不必要的数据回写。

开发指南参考：[AppStorage：应用全局的UI状态存储](../../../ui/state-management/arkts-appstorage.md)。

> **说明：**
>
> 从API version 7开始，支持该装饰器。

## @StorageProp

const StorageProp: (value: string) => PropertyDecorator

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| value  | string | 是   | AppStorage中的属性键名，用于与该键名对应的属性建立单向数据同步。若AppStorage中已存在该键名对应的属性，则@StorageProp装饰变量的本地初始值将被AppStorage中对应属性的值覆盖；若AppStorage中不存在该键名对应的属性，则使用@StorageProp装饰变量的本地初始值在AppStorage中创建该属性。 |

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | 属性装饰器，开发者无需关注该返回值。 |

**示例：**

```ts
// 创建AppStorage的初始数据，键为'PropA'，值为47
AppStorage.setOrCreate('PropA', 47);
// 创建AppStorage的初始数据，键为'PropB'，值为undefined
AppStorage.setOrCreate('PropB', undefined);

@Entry
@Component
struct StoragePropComponent {
  // 使用@StorageProp装饰器与AppStorage中'PropA'对应属性建立单向数据同步
  // AppStorage变化会同步到组件，但组件本地修改不会同步回AppStorage
  @StorageProp('PropA') propA: number | null = null;
  // 使用@StorageProp装饰器与AppStorage中'PropB'对应属性建立单向数据同步
  @StorageProp('PropB') propB: number | undefined = undefined;

  build() {
    Column() {
      Text('@StorageProp接口初始化，@StorageProp取值')
      Text(`${this.propA}`)
        .fontSize(20)
        .onClick(() => {
          // 点击切换propA的值，该变更不会同步到AppStorage
          this.propA = this.propA ? null : 1;
        })
      Text(`${this.propB}`)
        .fontSize(20)
        .onClick(() => {
          // 点击切换propB的值，该变更不会同步到AppStorage
          this.propB = this.propB ? undefined : 1;
        })
    }
  }
}
```

