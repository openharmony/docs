# ArkUI子系统Changelog

## cl.arkui.1 带标题栏窗口应用内菜单弹出位置变更

**访问级别**

公开接口

**变更原因**

对于带标题栏窗口使用非子窗的Menu组件场景，菜单默认弹出位置调整，UX体验更佳。


**变更影响**

该变更为不兼容变更。

变更前：带标题栏窗口应用内弹出菜单位置偏移4vp，菜单没有和按钮对齐。

变更后：带标题栏窗口应用内弹出菜单位置正确，菜单和按钮对齐。

| 变更前 | 变更后 |
|---------|---------|
|  ![变更前](figures/menu-item-4vp-before.png)       |  ![变更后](figures/menu-item-4vp-after.png)       |

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.1.0.45开始。

**变更的接口/组件**

Menu组件。

**适配指导**

Menu UX默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。

## cl.arkui.2 MenuItem设置padding属性时默认布局行为变更

**访问级别**

公开接口

**变更原因**

优化MenuItem添加padding时布局效果，变更后效果更佳。

**变更影响**

该变更为不兼容变更。

变更前：MenuItem设置padding属性时，布局和预期不符合。

变更后：MenuItem设置padding属性时，布局符合预期。

```ts
@Entry
@Component
struct Index {
  @Builder
  MenuWithPadding() {
    Menu() {
      MenuItemGroup() {
        MenuItem({content:"top bottom padding is 20vp"})
          .padding({top:20, bottom: 20})
          .borderWidth(2)
          .borderColor(Color.Black)
        MenuItem({content:"top padding is 20vp"})
          .padding({top:20})
          .borderWidth(2)
          .borderColor(Color.Black)
        MenuItem({content:"bottom padding is 20vp"})
          .padding({bottom: 20})
          .borderWidth(2)
          .borderColor(Color.Black)
      }
    }
  }

  build() {
    Column() {
      Button("菜单")
        .bindMenu(this.MenuWithPadding)
    }
    .width('100%')
  }
}
```

| 变更前 | 变更后 |
|---------|---------|
|  ![变更前](figures/item-padding-before.png)       |  ![变更后](figures/item-padding-after.png)       |

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony SDK 5.1.0.45 版本开始。

**变更的接口/组件**

MenuItem组件。

**适配指导**

MenuItem设置padding属性时默认布局效果变更，开发者无需适配。

## cl.arkui.3 DatePickerDialog和TimePickerDialog调用show()方法，参数缺省时的行为变更

**访问级别**

公开接口

**变更原因**

DatePickerDialog和TimePickerDialog调用show()方法，若参数缺省，无法弹出对话框。该参数为可选参数，会对开发者造成困惑。

**变更影响**

该变更为不兼容变更。

举例说明，执行以下用例：

```ts
@Entry
@Component
struct PickerDialogExample {
  build() {
    Column() {
      Button("DatePickerDialog")
        .onClick(() => {
          DatePickerDialog.show()
        })

      Button("TimePickerDialog")
        .margin(20)
        .onClick(() => {
          TimePickerDialog.show()
        })
    }
  }
}
```

变更前:  
DatePickerDialog.show()和TimePickerDialog.show()无法弹出日期选择器对话框。 

变更后:  
DatePickerDialog.show()和TimePickerDialog.show()可以弹出日期选择器对话框。

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.1.0.45开始。

**变更的接口/组件**

TimePickerDialog和DatePickerDialog组件。

**适配指导**

DatePickerDialog和TimePickerDialog调用show()方法，参数缺省时，可弹出默认样式的对话框。
