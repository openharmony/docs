# 挂载卸载事件

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 事件

| 名称                                       | 支持冒泡 | 功能描述          |
| ---------------------------------------- | ---- | ------------- |
| onAppear(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | 否    | 组件挂载显示时触发此回调。 |
| onDisappear(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | 否    | 组件卸载消失时触发此回调。 |


## 示例

```ts
// xxx.ets
import prompt from '@system.prompt'

@Entry
@Component
struct AppearExample {
  @State isShow: boolean = true
  private myText: string = 'Text for onAppear'
  private changeAppear: string = 'Hide Text'

  build() {
    Column() {
      Button(this.changeAppear)
        .onClick(() => {
          this.isShow = !this.isShow
        }).margin(3).backgroundColor(0x2788D9)
      if (this.isShow) {
        Text(this.myText)
          .onAppear(() => {
            this.changeAppear = 'Show Text'
            prompt.showToast({ message: 'The text is shown', duration: 2000 })
          })
          .onDisAppear(() => {
            this.changeAppear = 'Hide Text'
            prompt.showToast({ message: 'The text is hidden', duration: 2000 })
          })
      }
    }.padding(30).width('100%')
  }
}
```

![zh-cn_image_0000001219864151](figures/zh-cn_image_0000001219864151.gif)
