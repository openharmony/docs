# 时间滑动选择器弹窗

以24小时的时间区间创建时间滑动选择器，展示在弹窗上。

>  **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## TimePickerDialog.show

show(options?: TimePickerDialogOptions)

定义时间滑动选择器弹窗并弹出。

- TimePickerDialogOptions参数

  | 参数名 | 参数类型 | 必填 | 参数描述 |
  | -------- | -------- | -------- | -------- |
  | selected | Date | 否 | 设置当前选中的时间。<br/>默认值：当前系统时间 |
  | useMilitaryTime | boolean | 否 | 展示时间是否为24小时制，默认为12小时制。<br/>默认值：false |
  | onAccept | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult对象说明)) => void | 否 | 点击弹窗中的“确定”按钮时触发该回调。 |
  | onCancel | () => void | 否 | 点击弹窗中的“取消”按钮时触发该回调。 |
  | onChange | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult对象说明)) => void | 否 | 滑动弹窗中的选择器使当前选中时间改变时触发该回调。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct TimePickerDialogExample {
  private selectTime: Date = new Date('2020-12-25T08:30:00')

  build() {
    Column() {
      Button("TimePickerDialog 12小时制")
        .margin(20)
        .onClick(() => {
          TimePickerDialog.show({
            selected: this.selectTime,
            onAccept: (value: TimePickerResult) => {
              // 设置selectTime为按下确定按钮时的时间，这样当弹窗再次弹出时显示选中的为上一次确定的时间
              this.selectTime.setHours(value.hour, value.minute)
              console.info("TimePickerDialog:onAccept()" + JSON.stringify(value))
            },
            onCancel: () => {
              console.info("TimePickerDialog:onCancel()")
            },
            onChange: (value: TimePickerResult) => {
              console.info("TimePickerDialog:onChange()" + JSON.stringify(value))
            }
          })
        })
      Button("TimePickerDialog 24小时制")
        .margin(20)
        .onClick(() => {
          TimePickerDialog.show({
            selected: this.selectTime,
            useMilitaryTime: true,
            onAccept: (value: TimePickerResult) => {
              this.selectTime.setHours(value.hour, value.minute)
              console.info("TimePickerDialog:onAccept()" + JSON.stringify(value))
            },
            onCancel: () => {
              console.info("TimePickerDialog:onCancel()")
            },
            onChange: (value: TimePickerResult) => {
              console.info("TimePickerDialog:onChange()" + JSON.stringify(value))
            }
          })
        })
    }.width('100%')
  }
}
```