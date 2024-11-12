# ProgressButton


文本下载按钮，可显示具体下载进度。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { ProgressButton } from '@kit.ArkUI'
```

## 属性
支持[通用属性](ts-universal-attributes-size.md)

## ProgressButton

ProgressButton({progress: number, content: string, progressButtonWidth?: Length, clickCallback: () =&gt; void, enable: boolean})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| progress | number | 是 | \@Prop | 下载按钮的当前进度值。 |
| content | string | 是 | \@Prop | 下载按钮的文本。 |
| progressButtonWidth | [Length](ts-types.md#length) | 否 | - | 下载按钮的宽度。<br/>默认值：44。 |
| clickCallback | () =&gt; void | 是 | - | 下载按钮的点击回调。 |
| enable | boolean | 是 | \@Prop | 下载按钮是否可以点击。<br> enable为true时，表示可以点击。<br> enable为false时，表示不可点击。 |

## 事件
支持[通用事件](ts-universal-events-click.md)

## 示例

```ts
import { ProgressButton } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State halfProgress: number = 0
  @State smallProgress: number = 0
  @State bigProgress: number = 0
  @State textState1: string = ''
  @State isRunning1: boolean = false
  @State enableState1: boolean = true
  @State progressState: Visibility = Visibility.None
  @State ButtonState: Visibility = Visibility.Visible
  @State buttonText: string = '下载'
  @State buttonEnable: boolean = true
  @State isEnd: boolean = false
  build() {
    Column({space: 20}) {
      Text('下载按钮')
      Button(this.buttonText)
        .fontSize($r('sys.float.ohos_id_text_size_button3'))
        .fontWeight(FontWeight.Medium)
        .fontColor($r('sys.color.ohos_id_color_emphasize'))
        .padding({left: 8, right: 8})
        .opacity(this.buttonEnable? 1: 0.4)
        .enabled(this.buttonEnable)
        .height(28)
        .borderRadius(14)
        .width(60)
        .backgroundColor($r("sys.color.ohos_id_color_button_normal"))
        .onClick(() => {
          if(!this.isEnd) {
            this.buttonText = '等待中'
            let timer1 = setInterval(() => {
              this.progressState = Visibility.Visible
              this.ButtonState = Visibility.None
              clearInterval(timer1)
              this.isRunning1 = true
              let timer = setInterval(() => {
                if (this.isRunning1) {
                  if (this.halfProgress === 100) {
                    this.isEnd = true
                  } else {
                    this.halfProgress++
                    if (this.halfProgress === 100) {
                      this.textState1 = '安装中'
                      this.enableState1 = false
                      this.ButtonState = Visibility.Visible
                      this.progressState = Visibility.None
                      this.buttonEnable = false
                      this.buttonText = '安装中'
                      let timer2 = setInterval(() => {
                        this.buttonText = '打开'
                        this.buttonEnable = true
                        this.isEnd = true
                        clearInterval(timer2)
                      }, 2000)
                    }
                    console.info('x progress++ = ' + this.halfProgress)
                  }
                } else {
                  console.info('x isRunning = ' + false)
                  clearInterval(timer)
                }
              }, 100)
            }, 2000)
          }
        }).visibility(this.ButtonState)
      ProgressButton({
        progress: this.halfProgress,
        progressButtonWidth: "60",
        content: this.textState1,
        enable: this.enableState1,

        clickCallback: () => {
          if (this.isRunning1 && this.halfProgress < 100) {
            this.textState1 = '继续'
          }
          this.isRunning1 = !this.isRunning1
          let timer = setInterval(() => {

            if (this.isRunning1) {
              if (this.halfProgress === 100) {
              } else {
                this.halfProgress++
                if (this.halfProgress === 100) {
                  this.textState1 = '安装中'
                  this.enableState1 = false
                  this.ButtonState = Visibility.Visible
                  this.progressState = Visibility.None
                  this.buttonEnable = false
                  this.buttonText = '安装中'
                  let timer2 = setInterval(() => {
                    this.buttonText = '打开'
                    this.buttonEnable = true
                    this.isEnd = true
                    clearInterval(timer2)
                  },2000)
                }
                console.info('x progress++ = ' + this.halfProgress)
              }
            } else {
              console.info('x isRunning = ' + false)
              clearInterval(timer)
            }
          }, 100)
        }
      }).visibility(this.progressState)
    }.alignItems(HorizontalAlign.Center).width('100%')
  }
}
```


![zh-cn_image_0000001664713029](figures/zh-cn_image_0000001664713029.png)
