# \@Styles装饰器：定义组件重用样式


如果每个组件的样式都需要单独设置，在开发过程中会出现大量代码在进行重复样式设置，虽然可以复制粘贴，但为了代码简洁性和后续方便维护，我们推出了可以提炼公共样式进行复用的装饰器\@Styles。


\@Styles装饰器可以将多条样式设置提炼成一个方法，直接在组件声明的位置调用。通过\@Styles装饰器可以快速定义并复用自定义样式。用于快速定义并复用自定义样式。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。


## 装饰器使用说明

- 当前\@Styles仅支持[通用属性](../reference/arkui-ts/ts-universal-attributes-size.md)和[通用事件](../reference/arkui-ts/ts-universal-events-click.md)。

- \@Styles方法不支持参数，反例如下。

  ```ts
  // 反例： @Styles不支持参数
  @Styles function globalFancy (value: number) {
    .width(value)
  }
  ```

- \@Styles可以定义在组件内或全局，在全局定义时需在方法名前面添加function关键字，组件内定义时则不需要添加function关键字。

  ```ts
  // 全局
  @Styles function functionName() { ... }

  // 在组件内
  @Component
  struct FancyUse {
    @Styles fancy() {
      .height(100)
    }
  }
  ```

- 定义在组件内的\@Styles可以通过this访问组件的常量和状态变量，并可以在\@Styles里通过事件来改变状态变量的值，示例如下：

  ```ts
  @Component
  struct FancyUse {
    @State heightVlaue: number = 100
    @Styles fancy() {
      .height(this.heightVlaue)
      .backgroundColor(Color.Yellow)
      .onClick(() => {
        this.heightVlaue = 200
      })
    }
  }
  ```

- 组件内\@Styles的优先级高于全局\@Styles。
  框架优先找当前组件内的\@Styles，如果找不到，则会全局查找。


## 使用场景

以下示例中演示了组件内\@Styles和全局\@Styles的用法。



```ts
// 定义在全局的@Styles封装的样式
@Styles function globalFancy  () {
  .width(150)
  .height(100)
  .backgroundColor(Color.Pink)
}

@Entry
@Component
struct FancyUse {
  @State heightVlaue: number = 100
  // 定义在组件内的@Styles封装的样式
  @Styles fancy() {
    .width(200)
    .height(this.heightVlaue)
    .backgroundColor(Color.Yellow)
    .onClick(() => {
      this.heightVlaue = 200
    })
  }

  build() {
    Column({ space: 10 }) {
      // 使用全局的@Styles封装的样式
      Text('FancyA')
        .globalFancy ()
        .fontSize(30)
      // 使用组件内的@Styles封装的样式
      Text('FancyB')
        .fancy()
        .fontSize(30)
    }
  }
}
```
