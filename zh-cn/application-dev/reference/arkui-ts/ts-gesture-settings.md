# 绑定手势方法

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 绑定手势识别


通过如下属性给组件绑定手势识别，手势识别成功后可以通过事件回调通知组件。


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| gesture | gesture:&nbsp;GestureType,<br/>mask?:&nbsp;GestureMask | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定手势识别。<br/>gesture:&nbsp;绑定的手势类型，&nbsp;mask:&nbsp;事件响应设置。 |
| priorityGesture | gesture:&nbsp;GestureType,<br/>mask?:&nbsp;GestureMask | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定优先识别手势。<br/>gesture:&nbsp;绑定的手势类型，&nbsp;mask:&nbsp;事件响应设置。<br/>默认情况下，子组件优先于父组件识别手势，当父组件配置priorityGesture时，父组件优先于子组件进行识别。 |
| parallelGesture | gesture:&nbsp;GestureType,<br/>mask?:&nbsp;GestureMask | gesture:&nbsp;-，<br/>mask:&nbsp;GestureMask.Normal | 绑定可与子组件手势同时触发的手势。<br/>gesture:&nbsp;绑定的手势类型，&nbsp;mask:&nbsp;事件响应设置。<br/>手势事件为非冒泡事件。父组件设置parallelGesture时，父子组件相同的手势事件都可以触发，实现类似冒泡效果。 |


- GestureMask枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | Normal | 不屏蔽子组件的手势，按照默认手势识别顺序进行识别。 | 
  | IgnoreInternal | 屏蔽子组件的手势，仅当前容器的手势进行识别。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;子组件上系统内置的手势不会被屏蔽，如子组件为List组件时，内置的滑动手势仍然会触发。 | 


- GestureType
  | 名称 | 描述 | 
  | -------- | -------- |
  | TapGesture | 点击手势，支持单次点击、多次点击识别。 | 
  | LongPressGesture | 长按手势。 | 
  | PanGesture | 平移手势，滑动最小距离为5vp时识别成功。 | 
  | PinchGesture | 捏合手势。 | 
  | RotationGesture | 旋转手势。 | 
  |SwipeGesture  | 滑动手势，滑动最小速度为100vp/s时识别成功。| 
  | GestureGroup | 手势识别组，多种手势组合为复合手势，支持连续识别、并行识别和互斥识别。 | 


## 响应手势事件

组件通过gesture方法绑定手势对象，可以通过手势对象提供的事件相应响应手势操作。如通过TapGesture对象的onAction事件响应点击事件。具体事件定义见各个手势对象章节。

- TapGesture事件说明
  | 名称 | 功能描述 | 
  | -------- | -------- |
  | onAction((event?:GestureEvent)&nbsp;=&gt;&nbsp;void) | Tap手势识别成功回调。 | 

- GestureEvent对象说明
  | 属性名称 | 属性类型 | 描述 |
  | -------- | -------- | -------- |
  | timestamp | number | 事件时间戳。 |
  | target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md) | 触发手势事件的元素对象。 |


## 示例

```
@Entry
@Component
struct GestureSettingsExample {
  @State value: string = ''

  build() {
    Column(){
      Column() {
        Text('Click\n' + this.value)
          .gesture(
          TapGesture()
            .onAction(() => {
              this.value = 'gesture onAction'
            }))
      }.height(200).width(300).padding(60).border({ width: 1 })
      //设置为priorityGesture时，会优先识别该绑定手势忽略内部gesture手势
      .priorityGesture(
      TapGesture()
        .onAction((event: GestureEvent) => {
          this.value = 'priorityGesture onAction' + '\ncomponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height
        }), GestureMask.IgnoreInternal
      )
    }.padding(60)
  }
}
```

![zh-cn_image_0000001210195016](figures/zh-cn_image_0000001210195016.gif)
