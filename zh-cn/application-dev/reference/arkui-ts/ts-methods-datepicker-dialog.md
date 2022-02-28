# 日期时间滑动选择器弹窗

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

根据指定范围的Date创建可以选择时间或者日期的滑动选择器，展示在弹窗上。

## 权限列表

无

## DatePickerDialog.show

show(options?: DatePickerDialogOption)

定义日期时间滑动选择器弹窗并弹出。

- DatePickerDialogOption参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | start | Date | 否 | Date('1970-1-1') | 指定选择器的起始日期。 |
  | end | Date | 否 | Date('2100-12-31') | 指定选择器的结束日期。 |
  | selected | Date | 否 | 当前系统日期或时间 | 当type为DatePickerType.Date时，设置选中项的日期。当type为DatePickerType.Time时，设置选中项的时间。 |
  | type | [DatePickerType](ts-basic-components-datepicker.md) | 否 | DatePickerType.Date | 指定选择器的类型，包括日期选择器和时间选择器，缺省使用日期选择器。 |
  | lunar | boolean | 否 | false | 日期是否显示农历。 |
  | useMilitaryTime | boolean | 否 | false | 展示时间是否为24小时制。 |
  | onAccept | (value: [DatePickerResult](ts-basic-components-datepicker.md)) => void | 否 | - | 点击弹窗中确定按钮时触发。 |
  | onCancel | () => void | 否 | - | 点击弹窗中取消按钮时触发。 |
  | onChange | (value: [DatePickerResult](ts-basic-components-datepicker.md)) => void | 否 | - | 滑动选择器，当前选择项改变时触发。 |

## 示例

### 日期滑动选择器（显示农历）示例
```
@Entry
@Component
struct DatePickerDialogExample01 {
  @State isLunar: boolean = true
  @State isUseMilitaryTime: boolean = false
  @State datePickerType: DatePickerType = DatePickerType.Date
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
          },
          onCancel: () => {
            console.info("DatePickerDialog:onCancel()")
          },
          onChange: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
### 日期滑动选择器（不显示农历）示例
```
@Entry
@Component
struct DatePickerDialogExample02 {
  @State isLunar: boolean = false
  @State isUseMilitaryTime: boolean = false
  @State datePickerType: DatePickerType = DatePickerType.Date
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
          },
          onCancel: () => {
            console.info("DatePickerDialog:onCancel()")
          },
          onChange: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
### 时间滑动选择器（24小时制）示例
```
@Entry
@Component
struct DatePickerDialogExample03 {
  @State isLunar: boolean = false
  @State isUseMilitaryTime: boolean = true
  @State datePickerType: DatePickerType = DatePickerType.Time
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
          },
          onCancel: () => {
            console.info("DatePickerDialog:onCancel()")
          },
          onChange: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
### 时间滑动选择器（12小时制）示例
```
@Entry
@Component
struct DatePickerDialogExample04 {
  @State isLunar: boolean = false
  @State isUseMilitaryTime: boolean = false
  @State datePickerType: DatePickerType = DatePickerType.Time
  selectedDate: Date = new Date("2000-1-1")

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("DatePickerDialog").onClick(() => {
        DatePickerDialog.show({
          start: new Date("2000-1-1"),
          end: new Date("2005-1-1"),
          selected: this.selectedDate,
          type: this.datePickerType,
          lunar: this.isLunar,
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
            if (this.datePickerType == DatePickerType.Date) {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
            } else if (this.datePickerType == DatePickerType.Time) {
              this.selectedDate.setHours(value.hour, value.minute, value.second)
            }
          },
          onCancel: () => {
            console.info("DatePickerDialog:onCancel()")
          },
          onChange: (value: DatePickerResult) => {
            console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
