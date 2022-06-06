# DatePicker

>  **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


选择日期的滑动选择器组件。


## 权限列表

无


## 子组件

无


## 接口

DatePicker(options?: DatePickerOptions)

根据指定范围的Date创建可以选择日期的滑动选择器。

- options参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | start | Date | 否 | Date('1970-1-1') | 指定选择器的起始日期。 |
  | end | Date | 否 | Date('2100-12-31') | 指定选择器的结束日期。 |
  | selected | Date | 否 | 当前系统日期 | 设置选中项的日期。 |


## 属性

| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| lunar | boolean | false | 日期是否显示农历。<br/>-&nbsp;true：展示农历。<br/>-&nbsp;false：不展示农历。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- | 
| onChange(callback:&nbsp;(value:&nbsp;DatePickerResult)&nbsp;=&gt;&nbsp;void) | 选择日期时触发该事件。 | 

### DatePickerResult对象说明
  | 名称 | 参数类型 | 描述 | 
  | -------- | -------- | -------- |
  | year | number | 选中日期的年。 | 
  | month | number | 选中日期的月(0~11)，0表示1月，11表示12月。 | 
  | day | number | 选中日期的日。 | 


## 示例


### 日期选择器（显示农历）

```ts
// xxx.ets
@Entry
@Component
struct DatePickerExample01 {
  private selectedDate: Date = new Date('2021-08-08')

  build() {
    Column() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate,
      })
      .lunar(true)
      .onChange((date: DatePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![zh-cn_image_0000001251279761](figures/zh-cn_image_0000001251279761.gif)


### 日期选择器（不显示农历）

```ts
// xxx.ets
@Entry
@Component
struct DatePickerExample02 {
  private selectedDate: Date = new Date('2021-08-08')

  build() {
    Column() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate,
      })
      .lunar(false)
      .onChange((date: DatePickerResult) => {
        console.info('select current date is: ' + JSON.stringify(date))
      })
    }.width('100%')
  }
}
```

![zh-cn_image_0000001251092975](figures/zh-cn_image_0000001251092975.gif)

