# @LocalStorageLink：LocalStorage双向数据同步

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhushilin0206-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@LocalStorageLink在[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)中使用，用于与[LocalStorage](./ts-state-management.md#localstorage9)中指定键名对应的属性建立双向数据同步：@LocalStorageLink装饰的变量与LocalStorage中对应属性任一方发生变化时，变更均会同步到另一方。适用于需要在多个组件间共享UI状态并与LocalStorage保持数据实时同步的场景，可避免逐层传递数据，保证跨组件数据一致性。

开发指南参考：[LocalStorage：页面级UI状态存储](../../../ui/state-management/arkts-localstorage.md)。

> **说明：**
>
> 从API version 9开始，支持该装饰器。

## @LocalStorageLink

const LocalStorageLink: (value: string) => PropertyDecorator

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| value  | string | 是   | LocalStorage中的属性键名，用于与该键名对应的属性建立双向数据同步。若LocalStorage中已存在该键名对应的属性，则@LocalStorageLink装饰变量的本地初始值将被LocalStorage中对应属性的值覆盖；若LocalStorage中不存在该键名对应的属性，则使用@LocalStorageLink装饰变量的本地初始值在LocalStorage中创建该属性。|

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | 属性装饰器，开发者无需关注该返回值。 |

**示例：**

```ts
// 创建LocalStorage的初始数据，键为'LinkA'，值为47
const initialData: Record<string, number> = { 'LinkA': 47 };
const storage: LocalStorage = new LocalStorage(initialData);

// 使用@Entry装饰器标记入口组件，并传入LocalStorage实例
@Entry(storage)
@Component
struct Parent {
  // 使用@LocalStorageLink装饰器与LocalStorage中'LinkA'属性建立双向数据同步
  @LocalStorageLink('LinkA') linkA: number = 1;

  build() {
    Column() {
      Text(`incr @LocalStorageLink variable`)
        // 设置点击事件，点击后linkA值加1，变更会同步到LocalStorage
        .onClick(() => {
          this.linkA += 1;
        })
      // 显示当前@LocalStorageLink绑定的变量值
      Text(`@LocalStorageLink: ${this.linkA}`)
    }
  }
}
```

