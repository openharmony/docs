# @Watch：状态变量更改通知

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@Watch装饰器用于[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)中，监听状态变量的变化，并在变量变化时触发指定回调函数。适用于状态变量变化时需要自动执行联动逻辑、数据同步或计算衍生值的场景。

开发指南参考：[@Watch装饰器：状态变量更改通知](../../../ui/state-management/arkts-watch.md)。

> **说明：**
>
> 该装饰器从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## @Watch

const Watch: (value: string) => PropertyDecorator

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| value  | string | 是   | 监听状态变量变化的回调函数名，函数签名为`(propertyName: string) => void`，`propertyName`为变化的属性名。 |

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | 属性装饰器，开发者无需关注该返回值。 |

**示例：**

```ts
@Entry
@Component
struct Index {
  // 使用@State声明状态变量count，并使用@Watch装饰器监听其变化
  // 当count值变化时，自动调用名为'onChange'的回调函数
  @State @Watch('onChange') count: number = 0;
  @State total: number = 0;

  // @Watch监听的回调函数，参数为发生变化的属性名
  onChange(propertyName: string): void {
    this.total += this.count;
  }

  build() {
    Column() {
      Text(`Total: ${this.total}`)
      Button('change')
        // 设置点击事件，点击后count值加1，触发@Watch回调
        .onClick(() => {
          this.count++;
        })
    }
  }
}
```

