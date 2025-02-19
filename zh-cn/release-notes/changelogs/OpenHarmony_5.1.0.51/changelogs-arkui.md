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

## cl.arkui.2 TextController的SetStyledString接口支持保存设置的属性字符串信息到调用的TextController中

**访问级别**

公开接口

**变更原因**

优化属性字符串与Text组件的绑定时机。

**变更影响**

此变更涉及应用适配。

- 变更前：开发者调用TextController的setStyledString接口设置属性字符串时，如果调用时TextController还未绑定对应的Text，则此次设置无效。

- 变更后：开发者调用TextController的setStyledString接口时，调用的TextController会保存设置的属性字符串。当TextController和Text绑定时，如果TextController中已经存储之前调用setStyledString接口保存的属性字符串，则Text会自动设置保存的属性字符串，显示出对应的属性字符串。

**起始API Level**

12, 在api 15进行版本隔离。

**变更发生版本**

从OpenHarmony SDK 5.1.0.51开始。

**适配指导**

变更后对setStyledString的接口的调用可以更加灵活，Text能够正确地显示出属性字符串。
```ts
@Entry
@Component
struct StyledStringExample {
  controller: TextController = new TextController()

  aboutToAppear(): void {
    this.controller.setStyledString(new StyledString("123456")) // 变更前，由于此时controller还未和Text绑定，此次设置不生效。变更后，属性字符串可以正确的显示
  }

  build() {
    Row() {
      Column() {
        Text(undefined, {controller: this.controller})
      }.width('100%')
    }.height('100%')
  }
}
```