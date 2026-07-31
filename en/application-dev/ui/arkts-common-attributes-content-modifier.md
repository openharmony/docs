# Content Modifier (ContentModifier)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=b8421fa94775fa4bceb1b522857b705478302935 translatedAt=2026-07-29T12:44:05.939Z pushedAt=2026-07-30T02:09:11.986Z -->

**ContentModifier** allows you to customize the content area of supported components. For example, you can display a star inside a **Checkbox** component.

Currently, the following components support **ContentModifier**: [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md), [Checkbox](../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md), [DataPanel](../reference/apis-arkui/arkui-ts/ts-basic-components-datapanel.md), [TextTimer](../reference/apis-arkui/arkui-ts/ts-basic-components-texttimer.md), [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md), [Select](../reference/apis-arkui/arkui-ts/ts-basic-components-select.md), [Rating](../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md), [Radio](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md), [Gauge](../reference/apis-arkui/arkui-ts/ts-basic-components-gauge.md), [Toggle](../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md), [TextClock](../reference/apis-arkui/arkui-ts/ts-basic-components-textclock.md).

The following example shows how to use **ContentModifier** to replace the default check box with a pentagon shape. When the check box is selected, a red triangle appears inside the pentagon and the title updates to **selected**. When the check box is deselected, the triangle disappears and the title changes to **not selected**.

 <!-- @[checkbox_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Modifier/entry/src/main/ets/pages/MyCheckboxStyle.ets) -->

 ``` TypeScript
 import { hilog } from '@kit.PerformanceAnalysisKit';
 import { resourceManager } from '@kit.LocalizationKit';
 
 const DOMAIN = 0x0000;
 // xxx.ets
 class MyCheckboxStyle implements ContentModifier<CheckBoxConfiguration> {
   public selectedColor: Color = Color.White;
 
   constructor(selectedColor: Color) {
     this.selectedColor = selectedColor;
   }
 
   applyContent(): WrappedBuilder<[CheckBoxConfiguration]> {
     return wrapBuilder(buildCheckbox);
   }
 }
 
 @Builder
 function buildCheckbox(config: CheckBoxConfiguration) {
   Column({ space: 10 }) {
     Text() {
       Span(config.name)
       // Replace $r('app.string.checked_context') with the actual resource file. In this example, the value in the resource file is "selected."
       // Replace $r('app.string.unchecked_context') with the actual resource file. In this example, the value in the resource file is "unselected."
       Span(config.selected ? $r('app.string.checked_context') : $r('app.string.unchecked_context'))
     }
     Shape() {
       // Pentagon check box style
       Path()
         .width(200)
         .height(60)
         .commands('M100 0 L0 100 L50 200 L150 200 L200 100 Z')
         .fillOpacity(0)
         .strokeWidth(3)
       // Red triangle pattern style
       Path()
         .width(10)
         .height(10)
         .commands('M50 0 L100 100 L0 100 Z')
         .visibility(config.selected ? Visibility.Visible : Visibility.Hidden)
         .fill(config.selected ? (config.contentModifier as MyCheckboxStyle).selectedColor : Color.Black)
         .stroke((config.contentModifier as MyCheckboxStyle).selectedColor)
         .margin({ left: 11, top: 10 })
     }
     .width(300)
     .height(200)
     .viewPort({
       x: 0,
       y: 0,
       width: 310,
       height: 310
     })
     .strokeLineJoin(LineJoinStyle.Miter)
     .strokeMiterLimit(5)
     .onClick(() => {
       // Trigger the check box state change upon click.
       if (config.selected) {
         config.triggerChange(false);
       } else {
         config.triggerChange(true);
       }
     })
     .margin({ left: 150 })
   }
 }
 
 @Entry
 @Component
 struct Index {
   private resmg: resourceManager.ResourceManager | undefined = this.getUIContext().getHostContext()?.resourceManager
   build() {
     Row() {
       Column() {
         // Selected and unselected buttons
         // Replace $r('app.string.checkbox_status') with the actual resource file. In this example, the value in the resource file is "Check box status."
         Checkbox({ name: this.resmg?.getStringSync($r('app.string.checkbox_status').id), group: 'checkboxGroup' })
           .select(true)
           .contentModifier(new MyCheckboxStyle(Color.Red))
           .onChange((value: boolean) => {
             hilog.info(DOMAIN, 'testTag', 'Checkbox change is' + value);
           })
       }
       .width('100%')
     }
     .height('100%')
   }
 }
 ```

![](figures/common_builder.gif)