# @ohos.arkui.advanced.Popup（气泡组件）

Popup是用于显示特定样式气泡。

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```
import { Popup , PopupOptions,PopupTextOptions, PopupButtonOptions, PopupIconOptions } from '@ohos.arkui.advanced.Popup';
```

##  子组件

无

## Popup

Popup(options: PopupOptions)

**装饰器类型：**@Builder

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称    | 类型                          | 必填 | 说明                  |
| ------- | ----------------------------- | ---- | --------------------- |
| options | [PopupOptions](#popupoptions) | 是   | 定义Popup组件的类型。 |

## PopupOptions

PopupOptions定义Popup的具体式样参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型       | 必填        | 说明                            |
| ----------- | ---------- | ------| --------------------------------- |
| icon      | [PopupIconOptions](#popupiconoptions)                        | 否   | 设置popup图标。                      |
| title     | [PopupTextOptions](#popuptextoptions)                        | 否   | 设置popup标题文本。                  |
| message   | [PopupTextOptions](#popuptextoptions)                        | 是   | 设置popup内容文本。                  |
| showClose | boolean                                                      | 否   | 设置popup关闭按钮。                  |
| onClose   | () => void                                                   | 否   | 设置popup关闭按钮回调函数。          |
| buttons   | [[PopupButtonOptions](#popupbuttonoptions)?,[PopupButtonOptions](#popupbuttonoptions)?] | 否   | 设置popup操作按钮,按钮最多设置两个。 |

## PopupTextOptions

PopupTextOptions设置文本样式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                                         | 必填 | 描述               |
| ---------- | ------------------------------------------------------------ | ---- | ------------------ |
| text       | [ResourceStr](ts-types.md#resourcestr)                       | 是   | 设置文本内容。     |
| fontSize   | number \| string \| [Resource](ts-types.md#resource)         | 否   | 设置文本字体大小。 |
| fontColor  | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | 设置文本字体颜色。 |
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight)\| string | 否   | 设置文本字体粗细。 |

## PopupButtonOptions

PopupButtonOptions定义按钮的相关属性和事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                                 | 必填 | 描述                   |
| --------- | ---------------------------------------------------- | ---- | ---------------------- |
| text      | [ResourceStr](ts-types.md#resourcestr)               | 是   | 设置按钮内容。         |
| action    | () => void                                           | 否   | 设置按钮click回调。    |
| fontSize  | number \| string \| [Resource](ts-types.md#resource) | 否   | 设置按钮文本字体大小。 |
| fontColor | [ResourceColor](ts-types.md#resourcecolor)           | 否   | 设置按钮文本字体颜色。 |

##  PopupIconOptions

PopupIconOptions定义icon（右上角图标）的属性。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                                         | 必填 | 描述               |
| ------------ | ------------------------------------------------------------ | ---- | ------------------ |
| image        | [PixelMap](../apis/js-apis-image.md#pixelmap7)\| [ResourceStr](ts-types.md#resourcestr)\| [DrawableDescriptor](../apis/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 是   | 设置图标内容。     |
| width        | [Dimension](ts-types.md#dimension10)                         | 否   | 设置图标宽度。     |
| height       | [Dimension](ts-types.md#dimension10)                         | 否   | 设置图标高度。     |
| fillColor    | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | 设置图标填充颜色。 |
| borderRadius | [Length](ts-types.md#length)\| [BorderRadiuses](ts-types.md#borderradiuses9) | 否   | 设置图标圆角。     |

## 示例   

```ts
// xxx.ets
import { Popup , PopupOptions,PopupTextOptions, PopupButtonOptions, PopupIconOptions } from '@ohos.arkui.advanced.Popup';

@Entry
@Component
struct PopupExample {

  build() {
    Row() {
      // popup 自定义高级组件
      Popup({
        //PopupIconOptions 类型设置图标内容
        icon: {
          image: $r('app.media.icon'),
          width:32,
          height:32,
          fillColor:Color.White,
          borderRadius: 16,
        } as PopupIconOptions,
        // PopupTextOptions 类型设置文字内容
        title: {
          text: 'This is a popup with PopupOptions',
          fontSize: 20,
          fontColor: Color.Black,
          fontWeight: FontWeight.Normal,

        } as PopupTextOptions,
        //PopupTextOptions 类型设置文字内容
        message: {
          text: 'This is the message',
          fontSize: 15,
          fontColor: Color.Black,
          fontWeight: FontWeight.Normal,
        } as PopupTextOptions,
        showClose: false,
        onClose: () => {
          console.info('close Button click')
        },
        // PopupButtonOptions 类型设置按钮内容
        buttons: [{
          text: 'confirm',
          action: () => {
            console.info('confirm button click')
          },
          fontSize: 15,
          fontColor: Color.Black,

        },
          {
            text: 'cancel',
            action: () => {
              console.info('cancel button click')
            },
            fontSize: 15,
            fontColor: Color.Black,
          },] as [PopupButtonOptions?, PopupButtonOptions?],
      })
    }
    .width(300)
    .height(200)
    .borderWidth(2)
    .borderColor(Color.Red)
    .justifyContent(FlexAlign.Center)
  }
}
```

![](figures/popup_7.png)