# ProgressButton


文本下载按钮，可显示具体下载进度。


> **说明：**
>
> 该组件从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { ProgressButton } from '@kit.ArkUI';
```

## 属性
不支持[通用属性](ts-component-general-attributes.md)。

## ProgressButton

ProgressButton({progress: number, content: string, progressButtonWidth?: Length, clickCallback: () =&gt; void, enable: boolean})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| progress | number | 是 | \@Prop | 下载按钮的当前进度值。<br/>取值范围：[0,100]。设置小于0的数值时置为0，设置大于100的数值置为100。<br/>默认值：0。 |
| content | string | 是 | \@Prop | 下载按钮的文本。<br/>默认值：空字符串。<br/>**说明**：最长显示组件宽度，超出部分用省略号代替。 |
| progressButtonWidth | [Length](ts-types.md#length) | 否 | - | 下载按钮的宽度，单位vp。<br/>取值范围：大于等于44vp。<br/>默认值：44vp，小于默认值和非法值设置为默认值。 |
| clickCallback | () =&gt; void | 是 | - | 下载按钮的点击回调。 |
| enable | boolean | 是 | \@Prop | 下载按钮是否可以点击。<br> enable为true时，表示可以点击。<br> enable为false时，表示不可点击。 |

## 事件
不支持[通用事件](ts-component-general-events.md)。

## 示例

该示例实现了一个简单的带加载进度的文本下载按钮。
```ts
import { ProgressButton } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State progressIndex: number = 0;
  @State textState: string = '下载';
  @State ButtonWidth: number = 200;
  @State isRunning: boolean = false;
  @State enableState: boolean = true;

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
                this.textState = '继续';
              }
              this.isRunning = !this.isRunning;
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {
                  } else {
                    this.progressIndex++;
                    if (this.progressIndex === 100) {
                      this.textState = '已完成';
                      this.enableState = false;
                    }
                  }
                } else {
                  clearInterval(timer);
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
