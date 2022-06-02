# 时间滑动选择器弹窗

>  **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

默认以00：00至23：59的时间区间创建滑动选择器，展示在弹窗上。

## 权限列表

无

## TimePickerDialog.show

show(options?: TimePickerDialogOptions)

定义时间滑动选择器弹窗并弹出。

- options参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | selected | Date | 否 | 当前系统时间 | 设置选中项的时间。 |
  | useMilitaryTime | boolean | 否 | false | 展示时间是否为24小时制。 |
  | onAccept | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult对象说明)) => void | 否 | - | 点击弹窗中确定按钮时触发。 |
  | onCancel | () => void | 否 | - | 点击弹窗中取消按钮时触发。 |
  | onChange | (value: [TimePickerResult](ts-basic-components-timepicker.md#TimePickerResult对象说明)) => void | 否 | - | 滑动选择器，当前选择项改变时触发。 |

## 示例

### 时间滑动选择器（24小时制）示例
```ts
// xxx.ets
@Entry
@Component
struct TimePickerDialogExample01 {
  @State isUseMilitaryTime: boolean = true

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("TimePickerDialog").onClick(() => {
        TimePickerDialog.show({
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: TimePickerResult) => {
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
    }
  }
}
```
### 时间滑动选择器（12小时制）示例
```ts
// xxx.ets
@Entry
@Component
struct TimePickerDialogExample02 {
  @State isUseMilitaryTime: boolean = false

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("TimePickerDialog").onClick(() => {
        TimePickerDialog.show({
          useMilitaryTime: this.isUseMilitaryTime,
          onAccept: (value: TimePickerResult) => {
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
    }
  }
}
```
