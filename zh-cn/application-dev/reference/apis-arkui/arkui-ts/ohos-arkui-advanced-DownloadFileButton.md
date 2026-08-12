# DownloadFileButton

<!--Kit: ArkUI--> 
<!--Subsystem: ArkUI--> 
<!--Owner: @yaoyao1798--> 
<!--Designer: @yaoyao1798-->  
<!--Tester: @yangjiayong2686--> 
<!--Adviser: @Brilliantry_Rui-->

下载文件按钮，在下载文件场景中提供统一样式的下载按钮。


> **说明：**
>
> 该组件从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import { DownloadFileButton } from '@kit.ArkUI';
```

## 子组件

无

## 属性

支持[通用属性](ts-component-general-attributes.md)。

## DownloadFileButton

DownloadFileButton({ contentOptions: DownloadContentOptions, styleOptions: DownloadStyleOptions })

下载文件按钮，在下载文件场景中提供统一样式的下载按钮。

**装饰器类型：**@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------------- | ------------------------------------------------- | ---- | ---------- | -------------------------------- |
| contentOptions | [DownloadContentOptions](#downloadcontentoptions) | 是 | @State | 设置下载按钮显示的内容。 |
| styleOptions   | [DownloadStyleOptions](#downloadstyleoptions)     | 是   | @State     | 创建包含指定元素样式的下载按钮。 |

## DownloadContentOptions

下载文件按钮中显示的内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| icon | [DownloadIconStyle](#downloadiconstyle) | 否   | 是   | 设置下载按钮的图标风格。<br>默认值：不设置。不传入该参数表示没有图标，icon和text至少存在一个，若两者均未设置则组件无法正常显示。 |
| text | [DownloadDescription](#downloaddescription) | 否   | 是   | 设置下载按钮的文本描述。<br>默认值：不设置。不传入该参数表示没有文字描述，icon和text至少存在一个，若两者均未设置则组件无法正常显示。 |

## DownloadStyleOptions

下载文件按钮中图标和文字的样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                                                         | 只读 | 可选 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| iconSize | [Dimension](ts-types.md#dimension10) | 否 | 是 | 下载文件控件上图标的尺寸，不支持百分比。仅当contentOptions.icon设置时生效。<br>默认值：16vp<br>单位：vp |
| layoutDirection | [DownloadLayoutDirection](#downloadlayoutdirection) | 否 | 是 | 下载文件按钮上图标和文字分布的方向。仅当contentOptions.icon和contentOptions.text都设置时生效。 <br>默认值：DownloadLayoutDirection.HORIZONTAL |
| fontSize        | [Dimension](ts-types.md#dimension10) | 否   | 是   | 下载文件控件上文字的尺寸，不支持百分比。仅当contentOptions.text设置时生效。<br>默认值：16fp<br>单位：fp |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | 否 | 是 | 下载文件按钮上文字的样式。仅当contentOptions.text设置时生效。 <br>默认值：FontStyle.Normal |
| fontWeight | number\|[FontWeight](ts-appendix-enums.md#fontweight)\|string | 否 | 是 | 下载文件按钮上文字粗细，仅当contentOptions.text设置时生效。number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。 <br>默认值：FontWeight.Medium |
| fontFamily | string\|[Resource](ts-types.md#resource) | 否 | 是 | 下载文件按钮上文字的字体。仅当contentOptions.text设置时生效。<br> 默认字体：'HarmonyOS Sans'|
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 是 | 下载文件按钮上文字的颜色。仅当contentOptions.text设置时生效。<br>默认值：#ffffffff |
| iconColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 是 | 下载文件按钮上图标的颜色。仅当contentOptions.icon设置时生效。 <br>默认值：#ffffffff |
| textIconSpace | [Dimension](ts-types.md#dimension10) | 否 | 是 | 下载文件按钮中图标和文字的间距。仅当contentOptions.icon和contentOptions.text都设置时生效。<br> 默认值：4vp<br>单位：vp |

## DownloadIconStyle

下载文件按钮中图标的风格。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称        | 值   | 说明                       |
| ----------- | ---- | -------------------------- |
| FULL_FILLED | 1    | 下载按钮展示填充样式图标。 |
| LINES       | 2    | 下载按钮展示线条样式图标。 |



## DownloadDescription

下载按钮中文字的内容。不同文本描述适用于不同场景：DOWNLOAD用于一般文件下载场景，DOWNLOAD_FILE用于需要强调文件对象的下载场景，SAVE系列用于保存场景（如保存图片、保存文件），DOWNLOAD_AND_SHARE用于下载后需要分享的场景，RECEIVE系列用于接收文件场景。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称                | 值   | 说明                             |
| ------------------- | ---- | -------------------------------- |
| DOWNLOAD            | 1    | 下载按钮的文字描述为“下载”。     |
| DOWNLOAD_FILE       | 2    | 下载按钮的文字描述为“下载文件”。 |
| SAVE                | 3    | 下载按钮的文字描述为“保存”。     |
| SAVE_IMAGE          | 4    | 下载按钮的文字描述为“保存图片”。 |
| SAVE_FILE           | 5    | 下载按钮的文字描述为“保存文件”。 |
| DOWNLOAD_AND_SHARE  | 6    | 下载按钮的文字描述为“下载分享”。 |
| RECEIVE             | 7    | 下载按钮的文字描述为“接收”。     |
| CONTINUE_TO_RECEIVE | 8    | 下载按钮的文字描述为“继续接收”。 |



## DownloadLayoutDirection

下载文件按钮中图标和文字的排列方式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称       | 值   | 说明                                       |
| ---------- | ---- | ------------------------------------------ |
| HORIZONTAL | 0    | 下载文件按钮上图标和文字分布的方向为水平排列。 |
| VERTICAL   | 1    | 下载文件按钮上图标和文字分布的方向为垂直排列。 |

## 事件

支持[通用事件](ts-component-general-events.md)。

##  示例

```ts
// xxx.ets

import { picker } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { DownloadFileButton, DownloadLayoutDirection, DownloadIconStyle, DownloadDescription } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      DownloadFileButton({
        contentOptions: {
          icon: DownloadIconStyle.FULL_FILLED,
          text: DownloadDescription.DOWNLOAD
        },
        styleOptions: {
          iconSize: '16vp',
          layoutDirection: DownloadLayoutDirection.HORIZONTAL,
          fontSize: '16vp',
          fontStyle: FontStyle.Normal,
          fontWeight: FontWeight.Medium,
          fontFamily: 'HarmonyOS Sans',
          fontColor: '#ffffffff',
          iconColor: '#ffffffff',
          textIconSpace: '4vp'
       }
      })
        .backgroundColor('#007dff')
        .borderStyle(BorderStyle.Dotted)
        .borderWidth(0)
        .borderRadius('24vp')
        .position({ x: 0, y: 0 })
        .markAnchor({ x: 0, y: 0 })
        .offset({ x: 0, y: 0 })
        .constraintSize({})
        .padding({
          top: '12vp',
          bottom: '12vp',
          left: '24vp',
          right: '24vp'
        })
        .onClick(() => {
          this.downloadAction();
        })
    }
  }

  downloadAction() {
    try {
      const document = new picker.DocumentSaveOptions();
      document.pickerMode = picker.DocumentPickerMode.DOWNLOAD;
      new picker.DocumentViewPicker().save(document, (err: BusinessError, result: Array<string>) => {
        if (err) {
          return;
        }
        console.info(`downloadAction result:  ${JSON.stringify(result)}`);
      });
    } catch (error) {
      const err: BusinessError = error as BusinessError;
      console.error(`downloadAction failed. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

![zh-cn_image_0000001643320073](figures/zh-cn_image_0000001643329999.png)
