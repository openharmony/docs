# ProgressButtonV2


文本下载按钮，可显示具体下载进度。使用状态管理v2。


> **说明：**
>
> 该组件从API Version 16开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { ColorMetrics, LengthMetrics, ProgressButtonV2,  ProgressButtonV2Color } from '@kit.ArkUI'
```

## 属性
支持[通用属性](ts-universal-attributes-size.md)

## ProgressButtonV2

文本下载按钮，可显示具体下载进度。

ProgressButtonV2({progress: number, content: ResourceStr, progressButtonWidth?: LengthMetrics, onClicked: ClickCallback, isEnabled: boolean, colorOptions: ProgressButtonV2Color})

**装饰器类型：**\@ComponentV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                                          | 必填 | 装饰器类型             | 说明                                                                   |
| -------- |-------------------------------------------------------------|----|-------------------|----------------------------------------------------------------------|
| progress | number                                                      | 是  | \@Require <br/>\@Param | 下载按钮的当前进度值。                                                          |
| content | [ResourceStr](ts-types.md#resourcestr)                      | 是  | \@Require <br/>\@Param | 下载按钮的文本。                                                             |
| progressButtonWidth | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否  | \@Require <br/>\@Once  | 下载按钮的宽度。<br/>默认值：44vp。                                               |
| onClicked | [ClickCallback](#clickcallback)                             | 否  | \@Param               | 下载按钮的点击回调。默认值  () => {};                                             |
| isEnabled | boolean                                                     | 否  | \@Param       | 下载按钮是否可以点击。<br> isEnabled为true时，表示可以点击。<br> isEnabled为false时，表示不可点击。 |
| colorOptions | [ProgressButtonV2Color](#progressbuttonv2color)             | 否  | \@Param       | 下载按钮颜色选项。默认值undefined。                                               |

## ClickCallback

type ClickCallback = () => void

下载按钮的点击回调

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


| 名称 | 类型              | 说明                                                             |
| -------- | ------- |----------------------------------------------------------------|
| ClickCallback | () => void  | 下载按钮的当前进度值。                            |

### ProgressButtonV2Color
下载按钮颜色选项

**装饰器类型：**\@ObservedV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型         | 说明                 |
| -------- | -------- |---|---------------|--------------------|
| progressColor | ColorMetrics | 否 | \@Trace       | 进度条颜色。默认值undefined |
| borderColor | ColorMetrics | 否 | \@Trace | 按钮描边颜色。默认值undefined            |
| textColor | ColorMetrics | 否 | \@Trace | 按钮文本颜色。默认值undefined            |
| backgroundColor | ColorMetrics | 否 | \@Trace       | 按钮背景颜色。默认值undefined            |

### constructor
constructor(options: ProgressButtonV2ColorOptions);

下载按钮颜色选项构造函数

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型 | 必填 | 说明    |
|---------| -------- |----|-------|
| options | ProgressButtonV2ColorOptions | 是  | 色彩信息。 |

## ProgressButtonV2ColorOptions

下载按钮色彩信息选项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 |  说明      |
| -------- | -------- |---|---------|
| progressColor | ColorMetrics | 否 | 进度条颜色。默认值undefined  |
| borderColor | ColorMetrics | 否 | 按钮描边颜色。默认值undefined |
| textColor | ColorMetrics | 否 | 按钮文本颜色。默认值undefined |
| backgroundColor | ColorMetrics | 否 | 按钮背景颜色。默认值undefined |

## 事件
支持[通用事件](ts-universal-events-click.md)

## 示例

该示例实现了一个简单的带加载进度的文本下载按钮。
```ts
import { ColorMetrics, LengthMetrics, ProgressButtonV2, ProgressButtonV2Color } from '@kit.ArkUI'

@Entry
@ComponentV2
struct Index {
  @Local progressIndex: number = 0;
  @Local textState: string = '下载';
  @Local ButtonWidth: LengthMetrics = LengthMetrics.vp(200);
  @Local isRunning: boolean = false;
  @Local enableState: boolean = true;
  @Local value: number = 0;
  @Local colorOptions: ProgressButtonV2Color = new ProgressButtonV2Color({
    progressColor: ColorMetrics.resourceColor(Color.Red),
    borderColor: ColorMetrics.resourceColor(Color.Red),
    textColor: ColorMetrics.resourceColor(Color.Red),
    backgroundColor: ColorMetrics.resourceColor(Color.Red)
  });

  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          ProgressButtonV2({
            progress: this.progressIndex,
            progressButtonWidth: this.ButtonWidth,
            content: this.textState,
            isEnabled: this.enableState,
            colorOptions: this.colorOptions,
            onClicked: () => {
              if (this.textState && !this.isRunning && this.progressIndex < 100) {
                this.textState = '继续';
              }
              this.isRunning = !this.isRunning;
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {

                  } else {
                    this.progressIndex++
                    if (this.progressIndex === 100) {
                      this.textState = '已完成';
                      this.enableState = false;
                    }
                  }
                } else {
                  clearInterval(timer);
                }
              }, 20);
            }
          })
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 });
      }
    }
  }
}
```


![img.png](./figures/img.png)