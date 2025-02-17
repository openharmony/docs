# ArkUI子系统Changelog

## cl.arkui.1  DatePicker、DatePickerDialog、TextPicker、TextPickerDialog支持设置触控反馈（声音和振动）效果

**访问级别**

公开接口

**变更原因**

UX规范变更。

**变更影响**

此变更涉及应用适配。

- 变更前：在滑动选项时，DatePicker、DatePickerDialog、TextPicker、TextPickerDialog组件无触控反馈（声音和振动）效果。

- 变更后：在快速滑动选项时，DatePicker、DatePickerDialog、TextPicker、TextPickerDialog组件均匀触发声音和振动效果。在滑动选项居中时，DatePicker、DatePickerDialog、TextPicker、TextPickerDialog组件触发一次声音和振动效果。

**起始API Level**

16

**变更发生版本**

从OpenHarmony SDK 5.1.0.51开始。

**适配指导**

DatePicker、DatePickerDialog、TextPicker、TextPickerDialog默认支持触控反馈（声音和振动）效果，开发者可以通过如下代码关闭此效果。
```ts
@Entry
@Component
struct PickerHapticFeedbackExample {
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']
  build() {
    Row() {
      Column() {
        DatePicker()
          .enableHapticFeedback(false) //DatePicker设置关闭反馈效果

        Button("DatePickerDialog")
          .onClick(() => {
            DatePickerDialog.show({
              enableHapticFeedback: false, //DatePickerDialog设置关闭反馈效果
            })
          })

        TextPicker({ range: this.fruits })
          .enableHapticFeedback(false) //TextPicker设置关闭反馈效果
          
        Button("TextPickerDialog")
          .onClick(() => {
            TextPickerDialog.show({
              range: this.fruits,
              enableHapticFeedback: false, //TextPickerDialog设置关闭反馈效果
            })
          })
      }.width('100%')
    }.height('100%')
  }
}
```