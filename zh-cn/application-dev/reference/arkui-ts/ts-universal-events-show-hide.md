# 挂载卸载事件

挂载卸载事件指组件从组件树上挂载、卸载时触发的事件。

> **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 事件

| 名称                                             | 支持冒泡 | 功能描述                                                     |
| ------------------------------------------------ | -------- | ------------------------------------------------------------ |
| onAppear(event:&nbsp;()&nbsp;=&gt;&nbsp;void)    | 否       | 组件挂载显示时触发此回调。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| onDisAppear(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 否       | 组件卸载消失时触发此回调。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |


## 示例

```ts
// xxx.ets
import promptAction from '@ohos.promptAction'

@Entry
@Component
struct AppearExample {
  @State isShow: boolean = true
  @State changeAppear: string = 'Hide Text'
  private myText: string = 'Text for onAppear'

  build() {
    Column() {
      Button(this.changeAppear)
        .onClick(() => {
          this.isShow = !this.isShow
        }).margin(15)
      if (this.isShow) {
        Text(this.myText).fontSize(26).fontWeight(FontWeight.Bold)
          .onAppear(() => {
            this.changeAppear = 'Hide Text'
            promptAction.showToast({
              message: 'The text is shown',
              duration: 2000
            })
          })
          .onDisAppear(() => {
            this.changeAppear = 'Show Text'
            promptAction.showToast({
              message: 'The text is hidden',
              duration: 2000
            })
          })
      }
    }.padding(30).width('100%')
  }
}
```

![zh-cn_image_0000001219864151](figures/zh-cn_image_0000001219864151.gif)
