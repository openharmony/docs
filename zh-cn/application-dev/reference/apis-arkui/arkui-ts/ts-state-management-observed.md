# @Observed：嵌套类对象属性变化

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

\@Observed是类装饰器，用于[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)中，观察嵌套类对象的属性变化。

开发指南参考：[\@Observed装饰器和\@ObjectLink装饰器：嵌套类对象属性变化](../../../ui/state-management/arkts-observed-and-objectlink.md)。

> **说明：**
>
> 从API version 7开始，支持该装饰器。

## @Observed

const Observed: ClassDecorator

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
// 使用@Observed类装饰器，使Info类的属性变化可被ArkUI框架观察
@Observed
class Info {
  name: string;
  constructor(name: string) {
    this.name = name;
  }
}

@Entry
@Component
struct Index {
  @State info: Info = new Info('Tom');
  build() {
    Column() {
      Text(`name: ${this.info.name}`)
    }
  }
}
```



