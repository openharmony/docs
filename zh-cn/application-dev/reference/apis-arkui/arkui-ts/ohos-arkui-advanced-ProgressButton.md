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

该示例实现了一个简单的带加载进度的文本下载按钮。
```ts
import { ProgressButton } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State progressIndex: number = 0
  @State textState: string = '下载'
  @State ButtonWidth: number = 200
  @State isRunning: boolean = false
  @State enableState: boolean = true
  @State value: number = 0

  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          ProgressButton({
            progress: this.progressIndex,
            progressButtonWidth: this.ButtonWidth,
            content: this.textState,
            enable: this.enableState,
            clickCallback: () => {
              if (this.textState && !this.isRunning && this.progressIndex < 100) {
                this.textState = '继续'
              }
              this.isRunning = !this.isRunning
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {

                  } else {
                    this.progressIndex++
                    if (this.progressIndex === 100) {
                      this.textState = '已完成'
                      this.enableState = false
                    }
                  }
                } else {
                  clearInterval(timer)
                }
              }, 20)
            }
          })
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 })
      }
    }
  }
}
```


![img.png](./figures/img.png)