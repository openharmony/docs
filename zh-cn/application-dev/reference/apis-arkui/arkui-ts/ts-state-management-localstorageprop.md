# @LocalStorageProp：LocalStorage单向数据同步

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@LocalStorageProp在[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)中使用，用于与[LocalStorage](./ts-state-management.md#localstorage9)中指定键名对应的属性建立单向数据同步：LocalStorage中对应属性值的变更会同步到@LocalStorageProp装饰的变量，但仅修改@LocalStorageProp装饰的变量不会同步回LocalStorage。适用于需要在多个组件间共享LocalStorage且仅保持单向数据流的场景，可避免不必要的数据回写。

开发指南参考：[LocalStorage：页面级UI状态存储](../../../ui/state-management/arkts-localstorage.md)。

> **说明：**
>
> 从API version 9开始，支持该装饰器。

## @LocalStorageProp

const LocalStorageProp: (value: string) => PropertyDecorator

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| value  | string | 是   | LocalStorage中的属性键名，用于与该键名对应的属性建立单向数据同步。若LocalStorage中已存在该键名对应的属性，则@LocalStorageProp装饰变量的本地初始值将被LocalStorage中对应属性的值覆盖；若LocalStorage中不存在该键名对应的属性，则使用@LocalStorageProp装饰变量的本地初始值在LocalStorage中创建该属性。|

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | 属性装饰器，开发者无需关注该返回值。 |


**示例：**

```ts
// 创建LocalStorage的初始数据，键为'PropA'，值为47
const initialData: Record<string, number> = { 'PropA': 47 };
const storage: LocalStorage = new LocalStorage(initialData);

// 使用@Entry装饰器标记入口组件，并传入LocalStorage实例
@Entry(storage)
@Component
struct Parent {
  // 使用@LocalStorageProp装饰器与LocalStorage中'PropA'属性建立单向数据同步
  // 本地修改不会同步回LocalStorage
  @LocalStorageProp('PropA') propA: number = 1;

  build() {
    Column() {
      Button(`Parent from LocalStorage ${this.propA}`)
        // 设置点击事件，点击后propA值加1，但不会同步回LocalStorage
        .onClick(() => {
          this.propA += 1;
        })
      Child()
    }
  }
}

@Component
struct Child {
  // 使用@LocalStorageProp装饰器与LocalStorage中'PropA'属性建立单向数据同步
  // 子组件的propB会从LocalStorage读取'PropA'的值，但本地修改不会同步回去
  @LocalStorageProp('PropA') propB: number = 2;

  build() {
    Column() {
      Text(`Child from LocalStorage ${this.propB}`)
    }
  }
}
```

