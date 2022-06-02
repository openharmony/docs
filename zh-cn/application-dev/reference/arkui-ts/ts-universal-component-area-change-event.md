# 组件区域变化事件

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 事件

| 名称 | 支持冒泡 | 功能描述 | 
| -------- | -------- | -------- | 
| onAreaChange(event:&nbsp;(oldValue:&nbsp;Area,&nbsp;newValue:&nbsp;Area)&nbsp;=&gt;&nbsp;void) | 否 | 组件区域变化时触发该回调，Area类型说明见[Area对象](ts-universal-events-click.md)介绍。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct AreaExample {
  @State value: string = 'Text'
  @State size: string = ''

  build() {
    Column() {
      Text(this.value)
        .backgroundColor(Color.Green).margin(30).fontSize(20)
        .onClick(() => {
          this.value = this.value + 'Text'
        })
        .onAreaChange((oldValue: Area, newValue: Area) => {
          console.info(`Ace: on area change, oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
          this.size = JSON.stringify(newValue)
        })
      Text('new area is: \n' + this.size).margin({ right: 30, left: 30 })
    }
    .width('100%').height('100%').margin({ top: 30 })
  }
}
```

![zh-cn_image_0000001189634870](figures/zh-cn_image_0000001189634870.gif)
