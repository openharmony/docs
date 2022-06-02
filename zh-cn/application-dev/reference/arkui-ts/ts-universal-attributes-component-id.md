# 组件标识

>  **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性

| 名称 | 参数说明 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| id | string | '' | 组件的唯一标识，唯一性由使用者保证。 | 


## 接口


### getInspectorByKey

getInspectorByKey(id: string): string

获取指定id的组件的所有属性，不包括子组件信息。

- 参数
  | 参数 | 类型 | 必填 | 默认值 | 描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | 是 | - | 要获取属性的组件id。 | 

- 返回值
  | 类型 | 描述 | 
  | -------- | -------- |
  | string | 组件属性列表的JSON字符串。 | 


### sendEventByKey

sendEventByKey(id: string, action: number, params: string): boolean

给指定id的组件发送事件。

- 参数
  | 参数 | 类型 | 必填 | 默认值 | 描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | 是 | - | 要触发事件的组件的id。 | 
  | action | number | 是 | - | 要触发的事件类型，目前支持取值：<br/>-&nbsp;点击事件Click:&nbsp;10<br/>-&nbsp;长按事件LongClick:&nbsp;11。 | 
  | params | string | 是 | - | 事件参数，无参数传空字符串&nbsp;""。 | 

- 返回值
  | 类型 | 描述 | 
  | -------- | -------- |
  | boolean | 找不到指定id的组件时返回false，其余情况返回true。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct IdExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button() {
        Text('click')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }
      .type(ButtonType.Capsule)
      .margin({
        top: 20
      }).onClick(() => {
        console.info(getInspectorByKey("click"))
        console.info(getInspectorTree())
        setTimeout(() => {
          sendEventByKey("longclick", 11, "")
        }, 2000)
      }).id('click')

      Button() {
        Text('longclick')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }
      .type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .backgroundColor('#0D9FFB')
      .gesture(
        LongPressGesture().onActionEnd(() => {
          console.info('long clicked')
        }))
      .id('longclick')
    }
    .width('100%')
    .height('100%')
  }
}
```
