# ArkUI子系统Changelog

## cl.arkui.1 属性字符串TextStyle类型fontStyle、fontWeight字段返回类型变更

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

接口起始版本为API version 12。

**变更发生版本**

从OpenHarmony SDK 5.1.0.49开始，API version 18及以上生效。

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

## cl.arkui.2 CanvasRenderer的measureText方法传undefined参数时返回值变更

**访问级别**

公开接口

**变更原因**

measureText方法传undefined参数时，返回的textMetrics为undefined，和W3C标准行为不一致。

**变更影响**

变更前：
measureText方法传undefined参数时，返回的textMetrics为undefined。

变更后：
measureText方法传undefined参数时，返回值为按照字符串"undefined"测量的textMetrics。


**起始API Level**

API 8

**变更发生版本**

从OpenHarmony SDK 5.1.0.49开始。

**变更的接口/组件**

CanvasRenderingContext2D和OffscreenCanvasRenderingContext2D的measureText方法

**适配指导**

如果应用无需获取undefined参数的textMetrics，可在调用measureText方法前对参数做判断。

**示例**

```ts
@Entry
@Component
struct Demo {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  measureText(text: string)
  {
    if (text != undefined) {
      let metrics = this.context.measureText(text);
      console.info('width = ' + metrics.width);
    }
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .onReady(() => {
          this.measureText(undefined)
          this.measureText('Hello World')
        })
    }
    .width('100%')
    .height('100%')
  }
}
```