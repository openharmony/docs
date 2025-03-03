# ArkUI子系统Changelog

## cl.arkui.1 DatePicker、TextPicker和TimePicker的enabled、visibility参数动态改变后文本显示颜色变更

**访问级别**

公开接口

**变更原因**

DatePicker、TextPicker和TimePicker的enabled、visibility属性动态改变后，文本颜色呈现半透明。

**变更影响**

此变更无需应用适配。   
DatePicker、TextPicker和TimePicker的enabled参数由false变为true或者visibility参数由None/Hidden变为Visible后，文本颜色由之前的半透明变为初始颜色。

执行以下TextPicker示例时：

```ts
@Entry
@Component
struct TextPickerExample {
  private fruits: string[] = ['apple', 'orange', 'peach', 'grape'];
  @State isEnabled: boolean = true;

  build() {
    Column() {
      TextPicker({ range: this.fruits })
        .onChange(() => {
        })
        .disappearTextStyle({ color: Color.Red, font: { size: 20, weight: FontWeight.Lighter } })
        .textStyle({ color: Color.Black, font: { size: 25, weight: FontWeight.Normal } })
        .selectedTextStyle({ color: Color.Blue, font: { size: 30, weight: FontWeight.Bolder } })
        .divider(null)
        .enabled(this.isEnabled)

      Button("enabled : " + this.isEnabled).onClick(() => {
        this.isEnabled = !this.isEnabled // 点击button，动态切换组件的使能
      })
    }.width('100%').height('100%')
  }
}
```

| 变更前 | 变更后 |
|---------|---------|
|  ![变更前](figures/textpicker-before.png)       |  ![变更后](figures/textpicker-after.png)       |

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.1.0.49开始。

**变更的接口/组件**

DatePicker、TextPicker和TimePicker组件。

**适配指导**

DatePicker、TextPicker和TimePicker的enabled参数由"false"变为"true"或者visibility参数由"None/Hidden"变为"Visible"后，文本颜色恢复默认，开发者无需适配。

## cl.arkui.2 属性字符串TextStyle类型fontStyle、fontWeight字段返回类型变更

**访问级别**

公开接口

**变更原因**

接口实际行为与文档描述不一致。

**变更影响**

此变更涉及应用适配。

| 字段名 | 描述 |变更前类型 | 变更后类型 |
|---------| ---------|---------| ------|
| fontWeight | 获取属性字符串的文本字体粗细。| string | number |
| fontStyle | 获取属性字符串的文本字体样式。 | string | FontStyle |

**起始API Level**

接口起始版本为API version 12。此变更从API version 16开始，做版本隔离。

**变更发生版本**

从OpenHarmony SDK 5.1.0.49开始。

**变更的接口/组件**

属性字符串的getStyles接口。

**适配指导**

变更后，使用getStyles接口获得的TextStyle类型变量中fontStyle、fontWeight字段将会返回FontStyle和number类型而非之前的string类型，应用需要使用新的返回类型来进行判断。

``` ts
@Entry
@Component
struct styled_string_demo1 {
  scroll: Scroller = new Scroller();
  fontStyleAttr1: TextStyle = new TextStyle({ fontColor: Color.Blue, fontWeight: FontWeight.Bolder, fontStyle: FontStyle.Normal });
  fontStyleAttr2: StyledStringValue = new TextStyle({ fontColor: Color.Orange, fontStyle: FontStyle.Italic, fontWeight: FontWeight.Lighter });
  mutableStyledString1: MutableStyledString = new MutableStyledString("运动45分钟", [{
    start: 0,
    length: 3,
    styledKey: StyledStringKey.FONT,
    styledValue: this.fontStyleAttr1
  }, {
    start: 3,
    length: 3,
    styledKey: StyledStringKey.FONT,
    styledValue: this.fontStyleAttr2
  }]);
  controller1: TextController = new TextController();

  build() {
    Column() {
      Scroll(this.scroll) {
        Column() {
          // 显示属性字符串
          Text(undefined, { controller: this.controller1 })
            .onAppear(() => {
              this.controller1.setStyledString(this.mutableStyledString1)
            })

          Button('查询样式')
            .onClick(() => {
              let styles = this.mutableStyledString1.getStyles(0, this.mutableStyledString1.length)
              for (let i = 0; i < styles.length; i++) {
                console.info('StyledString style object start:' + styles[i].start)
                console.info('StyledString style object length:' + styles[i].length)
                console.info('StyledString style object key:' + styles[i].styledKey)
                if (styles[i].styledKey === 0) {
                  let fontAttr = styles[i].styledValue as TextStyle;
                  console.info('StyledString fontStyle type:' + typeof fontAttr.fontStyle)
                  console.info('StyledString fontWeight type:' + typeof fontAttr.fontWeight)
                }
              }
            })
            .margin({ top: 10 })
        }.width('100%')
      }
    }
    .width('100%')
  }
}
```