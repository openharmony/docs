# 动态属性设置

动态设置组件的属性，支持开发者在属性设置时使用if/else语法，且根据需要使用多态样式设置属性。

>  **说明：**
>
>  从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## attributeModifier

attributeModifier(modifier:&nbsp;AttributeModifier\<T>)

动态设置组件的属性方法。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| modifier | AttributeModifier\<T> | 是   | 在当前组件上，动态设置属性方法，支持使用if/else语法。<br/>modifier: 属性修改器，开发者需要自定义class实现AttributeModifier接口。 |

## AttributeModifier\<T>

开发者需要自定义class实现AttributeModifier接口。

### applyNormalAttribute
applyNormalAttribute(instance: T) : void

组件普通状态时的样式。

### applyPressedAttribute
applyPressedAttribute(instance: T) : void

组件按压状态的样式。

### applyFocusedAttribute
applyFocusedAttribute(instance: T) : void

组件获焦状态的样式。

### applyDisabledAttribute
applyDisabledAttribute(instance: T) : void

组件禁用状态的样式。

### applySelectedAttribute
applySelectedAttribute(instance: T) : void

组件选中状态的样式

开发者可根据需要自定义实现这些方法，通过传入的参数识别组件类型，对instance设置属性，支持使用if/else语法进行动态设置。

**参数**：

| 参数             | 描述                                                         |
| -------------------- | ------------------------------------------------------------ |
| instance |组件的属性类，用来标识进行属性设置的组件的类型，比如Button组件的ButtonAttribute，Text组件的TextAttribute等。|

**instance参数支持范围:**

AlphabetIndexerAttribute、BadgeAttribute、BlankAttribute、ButtonAttribute、CalendarPickerAttribute、CanvasAttribute、CheckboxAttribute、CheckboxGroupAttribute、CircleAttribute、ColumnAttribute、ColumnSplitAttribute、ShapeAttribute、CommonAttribute、CounterAttribute、DataPanelAttribute、DatePickerAttribute、DividerAttribute、EffectComponentAttribute、EllipseAttribute、FlexAttribute、FlowItemAttribute、FormComponentAttribute、FormLinkAttribute、GaugeAttribute、GridAttribute、GridColAttribute、ColumnAttribute、GridItemAttribute、GridRowAttribute、HyperlinkAttribute、ImageAttribute、ImageAnimatorAttribute、ImageSpanAttribute、LineAttribute、ListAttribute、ListItemAttribute、ListItemGroupAttribute、LoadingProgressAttribute、MarqueeAttribute、MenuAttribute、MenuItemAttribute、MenuItemGroupAttribute、NavDestinationAttribute、NavigationAttribute、NavigatorAttribute、NavRouterAttribute、PanelAttribute、PathAttribute、PatternLockAttribute、PluginComponentAttribute、PolygonAttribute、PolylineAttribute、ProgressAttribute、QRCodeAttribute、RadioAttribute、RatingAttribute、RectAttribute、RefreshAttribute、RelativeContainerAttribute、RemoteWindowAttribute、RichEditorAttribute、RichTextAttribute、RowAttribute、RowSplitAttribute、ScrollAttribute、ScrollBarAttribute、SearchAttribute、SelectAttribute、ShapeAttribute、SideBarContainerAttribute、SliderAttribute、SpanAttribute、StackAttribute、StepperAttribute、StepperItemAttribute、SwiperAttribute、TabContentAttribute、TabsAttribute、TextAttribute、TextAreaAttribute、TextClockAttribute、TextInputAttribute、TextPickerAttribute、TextTimerAttribute、TimePickerAttribute、ToggleAttribute、UIExtensionComponentAttribute、VideoAttribute、WaterFlowAttribute、WebAttribute、XComponentAttribute

**属性支持范围:**

不支持入参为[CustomBuilder](../arkui-ts/ts-types.md#custombuilder8)或Lamda表达式的属性，且不支持事件和手势。

## 示例

```ts
// xxx.ets
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  isDark: boolean = false
  applyNormalAttribute(instance: ButtonAttribute): void {
    if (this.isDark) {
      instance.backgroundColor(Color.Black)
    } else {
      instance.backgroundColor(Color.Red)
    }
  }
}

@Entry
@Component
struct attributeDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
          .onClick(() => {
            this.modifier.isDark = !this.modifier.isDark
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeModifier_ifelse](figures/attributeModifier_ifelse.gif)



```ts
// xxx.ets
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  applyNormalAttribute(instance: ButtonAttribute): void {
    instance.backgroundColor(Color.Black)
  }

  applyPressedAttribute(instance: ButtonAttribute): void {
    instance.backgroundColor(Color.Red)
  }
}

@Entry
@Component
struct attributePressedDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![attributeModifier_ifelse](figures/attributeModifier_ifelse.gif)