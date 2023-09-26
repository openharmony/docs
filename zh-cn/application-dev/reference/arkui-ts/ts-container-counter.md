# Counter

计数器组件，提供相应的增加或者减少的计数操作。

>  **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。


## 接口

Counter()

从API version 9开始，该接口支持在ArkTS卡片中使用。

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性。 

| 名称                          | 参数类型                               | 描述                                       |
| --------------------------- | ---------------------------------------- | ---------------------------------------- |
| enableInc<sup>10+</sup>              | boolean                            | 设置增加按钮禁用或使能。<br/>默认值：true   |
| enableDec<sup>10+</sup>           | boolean                                  | 设置减少按钮禁用或使能。<br/>默认值：true |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onInc(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 监听数值增加事件。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| onDec(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 监听数值减少事件。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct CounterExample {
  @State value: number = 0

  build() {
    Column() {
      Counter() {
        Text(this.value.toString())
      }.margin(100)
      .onInc(() => {
        this.value++
      })
      .onDec(() => {
        this.value--
      })
    }.width("100%")
  }
}
```

![zh-cn_image_0000001219982711](figures/zh-cn_image_0000001219982711.gif)
