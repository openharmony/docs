# TimePicker

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


选择时间的滑动选择器组件。


## 权限列表

无


## 子组件

无


## 接口

TimePicker(options?: TimePickerOptions)

默认以00：00至23：59的时间区间创建滑动选择器。

- options参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | selected | Date | 否 | 当前系统时间 | 设置选中项的时间。 |


## 属性

| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| useMilitaryTime | boolean | false | 展示时间是否为24小时制，不支持动态修改。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- | 
| onChange(callback:&nbsp;(value:&nbsp;TimePickerResult )&nbsp;=&gt;&nbsp;void) | 选择时间时触发该事件。 | 

### TimePickerResult对象说明
  | 名称 | 参数类型 | 描述 | 
  | -------- | -------- | -------- |
  | hour | number | 选中时间的时。 | 
  | minute | number | 选中时间的分。 | 


## 示例


### 时间选择器

```ts
// xxx.ets
@Entry
@Component
struct TimePickerExample {
  private selectedTime: Date = new Date('08-00')

  build() {
    Column() {
      TimePicker({
        selected: this.selectedTime,
      })
      .useMilitaryTime(true)
      .onChange((date: TimePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![zh-cn_image_0000001251292933](figures/zh-cn_image_0000001251292933.gif)
