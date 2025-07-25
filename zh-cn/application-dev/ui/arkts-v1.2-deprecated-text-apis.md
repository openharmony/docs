# 文本类组件

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## onEditChanged

ArkTS1.1接口声明：[onEditChanged(callback: (isEditing:boolean) => void)](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#oneditchangeddeprecated)

替代的ArkTS1.2接口声明：[onEditChange(callback: Callback<boolean>)](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#oneditchange8)

适配方法如下：

ArkTS1.1

```
TextInput({ text: "TextInput支持输入状态变化时回调" })
  .onEditChanged((status: boolean) => {
    this.editStatus = status;
  })
```

ArkTS1.2

```
TextInput({ text: "TextInput支持输入状态变化时回调" })
  .onEditChange((status: boolean) => {
    this.editStatus = status;
  })
```

## measureTextSize

ArkTS1.1接口声明：[measureTextSize(options: MeasureOptions): SizeOptions](../reference/apis-arkui/js-apis-measure.md#measuretextmeasuretextsizedeprecated)

替代的ArkTS1.2接口声明：[measureTextSize(options: MeasureOptions): SizeOptions](../reference/apis-arkui/js-apis-arkui-UIContext.md#measuretextsize12)

适配方法如下：

ArkTS1.1

```
textSize: SizeOptions = MeasureText.measureTextSize({
  textContent: "Hello World",
  fontSize: '50px'
})
```

ArkTS1.2

```
@State uiContext: UIContext = this.getUIContext();

@State uiContextMeasure: MeasureUtils = this.uiContext.getMeasureUtils();

textSize : SizeOptions = this.uiContextMeasure.measureTextSize({
  textContent: "Hello World",
  fontSize: '50px'
})
```

## measureText

ArkTS1.1接口声明：[measureText(options: MeasureOptions): number](../reference/apis-arkui/js-apis-measure.md#measuretextmeasuretextdeprecated)

替代的ArkTS1.2接口声明：[measureText(options: MeasureOptions): number](../reference/apis-arkui/js-apis-arkui-UIContext.md#measuretext12)

适配方法如下：

ArkTS1.1

```
@State textWidth: number = MeasureText.measureText({
  textContent: "Hello World",
  fontSize: '50px'
})
```

ArkTS1.2

```
@State uiContext: UIContext = this.getUIContext();

@State uiContextMeasure: MeasureUtils = this.uiContext.getMeasureUtils();

@State textWidth: number = this.uiContextMeasure.measureText({
  textContent: "Hello World",
  fontSize: '50px'
})
```

## getFontByName

ArkTS1.1接口声明：[getFontByName(fontName: string): FontInfo](../reference/apis-arkui/js-apis-font.md#fontgetfontbynamedeprecated)

替代的ArkTS1.2接口声明：[getFontByName(fontName: string): font.FontInfo](../reference/apis-arkui/js-apis-arkui-UIContext.md#getfontbyname)

适配方法如下：

ArkTS1.1

```
import { font } from '@kit.ArkUI';
font.getFontByName('HarmonyOS Sans Italic')
```

ArkTS1.2

```
import { UIContext, Font } from '@ohos.arkui.UIContext';

let uiContext:UIContext = this.getUIContext();
let font: Font | undefined = uiContext.getFont();
if (font) {
  font.getFontByName('Sans Italic');
}
```

## getSystemFontList

ArkTS1.1接口声明：[getSystemFontList(): Array<string>](../reference/apis-arkui/js-apis-font.md#fontgetsystemfontlistdeprecated)

替代的ArkTS1.2接口声明：[getSystemFontList(): Array<string>](../reference/apis-arkui/js-apis-arkui-UIContext.md#getsystemfontlist)

适配方法如下：

ArkTS1.1

```
font.getSystemFontList()
```

ArkTS1.2

```
import { UIContext, Font } from '@ohos.arkui.UIContext';

let uiContext:UIContext = this.getUIContext();
let font: Font | undefined = uiContext.getFont();
if (font) {
  font.getSystemFontList();
}
```

## registerFont

ArkTS1.1接口声明：[registerFont(options: FontOptions): void](../reference/apis-arkui/js-apis-font.md#fontregisterfontdeprecated)

替代的ArkTS1.2接口声明：[registerFont(options: font.FontOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#registerfont)

适配方法如下：

ArkTS1.1

```
font.registerFont({familyName: 'mediumRawFile', familySrc: $rawfile('font/medium.ttf')})
```

ArkTS1.2

```
let uiContext:UIContext = this.getUIContext();
let font:Font = uiContext.getFont();

font.registerFont({familyName: 'medium', familySrc: '/font/medium.ttf'});
```

## CROSS_DEVICE

ArkTS1.1接口声明：[CopyOptions.CROSS_DEVICE](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#copyoptions9)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。
