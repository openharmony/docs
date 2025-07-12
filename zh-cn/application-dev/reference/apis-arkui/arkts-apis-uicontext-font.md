# Class (Font)

注册自定义字体的信息。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 以下API需先使用UIContext中的[getFont()](./arkts-apis-uicontext-uicontext.md#getfont)方法获取到Font对象，再通过该对象调用对应方法。

## registerFont

registerFont(options: font.FontOptions): void

在字体管理中注册自定义字体。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| options | [font.FontOptions](js-apis-font.md#fontoptions) | 是    | 注册的自定义字体信息。 |

**示例：**

<!--code_no_check-->
```ts
import { Font } from '@kit.ArkUI';

let font:Font = uiContext.getFont();
font.registerFont({
  familyName: 'medium',
  familySrc: '/font/medium.ttf'
});
```
## getSystemFontList

getSystemFontList(): Array\<string> 

获取系统支持的字体名称列表。

>  **说明：**
>
>  该接口仅在2in1设备上生效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 说明        |
| -------------- | --------- |
| Array\<string> | 系统的字体名列表。 |


**示例：** 

<!--code_no_check-->
```ts
import { Font } from '@kit.ArkUI';

let font: Font | undefined = uiContext.getFont();
if (font) {
  font.getSystemFontList();
}
```

## getFontByName

getFontByName(fontName: string): font.FontInfo

根据传入的系统字体名称获取系统字体的相关信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型     | 必填   | 说明      |
| -------- | ------ | ---- | ------- |
| fontName | string | 是    | 系统的字体名。 |

**返回值：** 

| 类型                                      | 说明           |
| ----------------------------------------- | -------------- |
| [font.FontInfo](js-apis-font.md#fontinfo10) | 字体的详细信息。 |

**示例：** 

<!--code_no_check-->
```ts
import { Font } from '@kit.ArkUI';

let font: Font | undefined = uiContext.getFont();
if (font) {
  font.getFontByName('Sans Italic');
}
```
