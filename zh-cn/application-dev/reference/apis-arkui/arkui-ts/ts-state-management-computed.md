# @Computed：计算属性

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@Computed为方法装饰器，用于[状态管理V2](../../../ui/state-management/arkts-state-management-overview.md#状态管理v2)中，装饰getter方法，使其变为计算属性，其返回值会被缓存，仅当依赖的源数据发生变化时才重新计算，减少重复计算带来的开销。

开发指南参考：[@Computed装饰器：计算属性](../../../ui/state-management/arkts-new-computed.md)。

> **说明：**
>
> 从API version 12开始，支持该装饰器。

## @Computed

const Computed: MethodDecorator

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
@Entry
@ComponentV2
struct Index {
  @Local firstName: string = 'Hua';
  @Local lastName: string = 'Li';

  // 声明Computed getter函数，避免重复计算
  @Computed
  get fullName() {
    return this.firstName + ' ' + this.lastName;
  }

  build() {
    Column() {
      Text(`${this.fullName}`)
    }
  }
}
```

