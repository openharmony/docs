# Radio

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


单选框，提供相应的用户交互选择项。


## 权限列表

无


## 子组件

无


## 接口

Radio(options: {value: string, group: string})

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | value | string | 是 | - | 当前单选框的值。|
  | group | string | 是 | - | 当前单选框的所属群组名称，相同group的Radio只能有一个被选中。|


## 属性

| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| checked | boolean | false | 设置单选框的选中状态。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- |
| onChange(callback: (value: boolean) => void) | 单选框选中状态改变时触发回调。<br> -value为true时，代表选中。<br> -value为false时，代表未选中。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct RadioExample {
  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Column() {
        Text('Radio1')
        Radio({ value: 'Radio1', group: 'radioGroup' }).checked(true)
          .height(50)
          .width(50)
          .onChange((value: boolean) => {
            console.log('Radio1 status is ' + value)
          })
      }
      Column() {
        Text('Radio2')
        Radio({ value: 'Radio2', group: 'radioGroup' }).checked(false)
          .height(50)
          .width(50)
          .onChange((value: boolean) => {
            console.log('Radio2 status is ' + value)
          })
      }
      Column() {
        Text('Radio3')
        Radio({ value: 'Radio3', group: 'radioGroup' }).checked(false)
          .height(50)
          .width(50)
          .onChange((value: boolean) => {
            console.log('Radio3 status is ' + value)
          })
      }
    }.padding({ top: 30 })
  }
}
```
![](figures/radio.gif)
