#  @ohos.arkui.advanced.Qrcode (二维码高级组件)

二维码高级组件。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## Qrcode

Qrcode({options:QrcodeOptions,state:QrcodeState,value:string})

**装饰器类型：**@ComponentV2

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称    | 类型          | 必填 | 装饰器类型      | 说明                   |
| ------- | ------------- | ---- | --------------- | ---------------------- |
| options | QrcodeOptions | 是   | @ObservedV2     | 定义Qrcode组件的参数。 |
| state   | QrcodeState   | 是   | @Require @Param | Qrcode的状态参数       |
| value   | string        | 是   | @Require @Param | 二维码内容参数         |



## QrcodeOptions

QrcodeOptions定义Qrcode的样式及具体式样参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称               | 类型                           | 必填 | 说明                                                         |
| ------------------ | ------------------------------ | ---- | ------------------------------------------------------------ |
| edgeLength         | LengthMetrics                  | 否   | 二维码衬底边长。<br/>默认值：125vp。                         |
| color              | ColorMetrics                   | 否   | 二维码颜色。<br>默认值：Color.Black。                        |
| backgroundColor    | ColorMetrics                   | 否   | 二维码衬底颜色。<br>默认值：Color.White                      |
| textColor          | ColorMetrics                   | 否   | 二维码过期提示文本颜色。<br>默认值：Color.White              |
| textContent        | string                         | 是   | 二维码过期提示文本。<br/>默认值：系统资源$r('sys.string.qrcode_expiration_prompt') ，<br/>默认提示内容：二维码已失效，点击刷新 |
| borderRadius       | LengthMetrics                  | 否   | 衬底矩形圆角。<br/>默认值：12vp。                            |
| opacity            | number \| Resource             | 否   | 刷新和加载状态下二维码透明度。<br/>默认值：0.4。             |
| animationCurve     | Curve \| string \| ICurve      | 否   | 页面切换淡入曲线。<br/>默认值：‘0.33,0,0.67,1’。             |
| animationDuration  | number                         | 否   | 页面切换淡入时长。<br/>默认值：200。<br/>单位：ms。          |
| qrcodeSideLength   | LengthMetrics                  | 否   | 二维码边长。<br/>默认值：101vp。                             |
| expiredImageLength | LengthMetrics                  | 否   | 失效图标边长。<br/>默认值：28vp。                            |
| textSize           | ResourceStr                    | 否   | 提示文本字体大小。<br/>默认值：11fp                          |
| textWeight         | number \| FontWeight \| string | 否   | 提示文本字重。<br/>默认值：FontWeight.Medium                 |
| space              | ResourceStr                    | 否   | 失效提示图标与失效提示文本间隔。<br/>默认值：6vp。           |
| loadingImageLength | LengthMetrics                  | 否   | 加载图标边长。<br/>默认值：34vp。                            |

## QrcodeState

QrcodeState是Qrcode可设置的状态类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 描述           |
| ------- | ---- | -------------- |
| NORMAL  | 0    | 正常显示状态。 |
| EXPIRED | 1    | 失效状态。     |
| LOADING | 2    | 加载状态。     |


## 示例

### 示例1

Qrcode使用示例。

```ts
import { Qrcode, QrcodeOptions, QrcodeState } from '@ohos.arkui.advanced.Qrcode'
import { LengthMetrics,ColorMetrics } from '@ohos.arkui.node';

@Entry
@ComponentV2
struct Index {
  @Local qrOptions: QrcodeOptions = new QrcodeOptions({})
  @Local state: QrcodeState = QrcodeState.NORMAL
  @Local value: string = 'Test Qrcode'
  build() {
    Column({space:6}) {
      Qrcode({
        options: this.qrOptions,
        value:this.value,
        state:this.state,
      })
        .onClick(()=>{
          console.info('1111111111111111')
          this.state = QrcodeState.LOADING
        })

      Column({space:6}) {
        Row({space:4}) {
          Button('失效')
            .onClick(() => {
              this.state = QrcodeState.EXPIRED
              console.info('失效' + this.state)
            })
            .margin({ top: 10 })

          Button('正常')
            .onClick(() => {
              this.state = QrcodeState.NORMAL
              this.value = '1111111111111111111'
              this.qrOptions.edgeLength = LengthMetrics.vp(125)
              this.qrOptions.color = ColorMetrics.resourceColor(Color.Black)
              this.qrOptions. textContent = '失效'
              this.qrOptions.textColor = ColorMetrics.resourceColor(Color.White)
              console.info('正常' + this.state)
            })
            .margin({ top: 10 })

          Button('刷新')
            .onClick(() => {
              this.state = QrcodeState.LOADING
              console.info('刷新' + this.state)
            })
            .margin({ top: 10 })
        }

        Row({space:4}) {
          Button('绿色').onClick(()=>{
            this.qrOptions.color = ColorMetrics.resourceColor(Color.Green)
          })

          Button('黄色').onClick(()=>{
            this.qrOptions.color = ColorMetrics.resourceColor(Color.Yellow)
          })

          Button('蓝色').onClick(()=>{
            this.qrOptions.color = ColorMetrics.resourceColor(Color.Blue)
          })

          Button('红色').onClick(()=>{
            this.qrOptions.color = ColorMetrics.resourceColor(Color.Red)
          })
        }

        Row({space:4}) {
          Button('100vp').onClick(()=>{
            this.qrOptions.edgeLength = LengthMetrics.vp(100);
          })

          Button('60vp').onClick(()=>{
            this.qrOptions.edgeLength = LengthMetrics.vp(60);
          })

          Button('80vp').onClick(()=>{
            this.qrOptions.edgeLength = LengthMetrics.vp(80);
          })

          Button('20vp').onClick(()=>{
            this.qrOptions.edgeLength =  LengthMetrics.vp(20);
          })
        }

        Row({space:4}){
          Button('失效提示').onClick(()=>{
            this.qrOptions.textContent ='The QR code has expired, please refresh'
          })

          Button('红色字体').onClick(()=>{
            this.qrOptions.textColor = ColorMetrics.resourceColor(Color.Red)
          })
        }
      }

    }
    .backgroundColor(Color.Black)
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}

```

![](C:\Users\jiaguoj\Desktop\qrcode.PNG)

