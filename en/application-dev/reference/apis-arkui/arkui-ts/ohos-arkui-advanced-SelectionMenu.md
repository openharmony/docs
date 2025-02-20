# SelectionMenu


The **SelectionMenu** component is a context menu designed for use with the [RichEditor](ts-basic-components-richeditor.md) component, allowing you to bind a custom context menu on selection through the [bindSelectionMenu](./ts-basic-components-richeditor.md#bindselectionmenu) API. This component is not intended for standalone use, and you are advised to display it by right-clicking or by selecting text with a mouse device.


> **NOTE**
>
> This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { SelectionMenu, EditorMenuOptions, ExpandedMenuOptions, EditorEventInfo, SelectionMenuOptions } from '@kit.ArkUI'
```

## Child Components

Not supported

## SelectionMenu

SelectionMenu(options: SelectionMenuOptions): void

Defines a custom context menu on selection. When the input parameter is empty, the sizes of the menu and its content area are 0, making the menu invisible. In this case, for example, if a right-click context menu is bound to the **RichEditor** component, it will not be displayed when the component is right-clicked.

**Decorator**: @Builder

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SelectionMenuOptions](#selectionmenuoptions) | Yes| Options of the context menu on selection.|

## SelectionMenuOptions

Defines the options of the context menu on selection.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| editorMenuOptions | Array&lt;[EditorMenuOptions](#editormenuoptions)&gt; | No| Edit menu.<br>If **editorMenuOptions** is not set, the edit menu is not displayed.<br>When both **action** and **builder** in **EditorMenuOptions** are configured, clicking the edit icon will trigger both.<br>By default, the context menu is not closed when the edit menu icon is clicked. You can configure **closeSelectionMenu** of **RichEditorController** in **action** to enable the menu to be closed.|
| expandedMenuOptions | Array&lt;[ExpandedMenuOptions](#expandedmenuoptions)&gt; | No| Expanded drop-down menu options.<br>If this parameter is left empty, the expanded drop-down menu is not displayed.<br>The options configured for **ExpandedMenuOptions** are displayed in the **More** menu option, and clicking **More** shows the expanded drop-down menu.|
| controller | [RichEditorController](ts-basic-components-richeditor.md#richeditorcontroller) | No| Rich text editor controller. If **controller** is set, the default system menu (including the cut, copy, and paste options) is displayed, and the preset menu features are provided.<br>If **controller** is left empty, the **More** menu option is not displayed. If **expandedMenuOptions** is not empty, the expanded drop-down menu is displayed.<br>By default, the copy and paste feature is only available for rich text. To use the feature for content that includes both text and images, define custom **onCopy** and **onPaste** APIs. If a custom **onCopy** \| **onPaste** API is defined, the default copy and paste feature is ineffective, and the custom API is called instead.<br>**NOTE**<br> When the preset copy option is selected, the custom context menu on selection is hidden, while the selected text is still highlighted.<br> When the preset select-all option is selected, the custom context menu on selection is hidden, while all text is highlighted.<br> When the preset paste option is selected, the style of the copied text is retained, whether the text is pasted to a blank area or not.<br> When the **copyOptions** attribute of the [RichEditor](ts-basic-components-richeditor.md) component is set to **CopyOptions.None**, the preset copy and cut features are not restricted.|
| onCopy | (event?: [EditorEventInfo](#editoreventinfo)) =&gt; void | No| Event callback to take the place of the preset copy menu option.<br>It is effective only when the **controller** parameter is set and the preset menu is available.<br>**NOTE**<br> **event** indicates the returned information.|
| onPaste | (event?: [EditorEventInfo](#editoreventinfo)) =&gt; void | No| Event callback to take the place of the preset paste menu option.<br>It is effective only when the **controller** parameter is set and the preset menu is available.<br>**NOTE**<br> **event** indicates the returned information.|
| onCut | (event?: [EditorEventInfo](#editoreventinfo)) =&gt; void | No| Event callback to take the place of the preset cut menu option.<br>It is effective only when the **controller** parameter is set and the preset menu is available.<br>**NOTE**<br>**event** indicates the returned information.|
| onSelectAll | (event?: [EditorEventInfo](#editoreventinfo)) =&gt; void | No| Event callback to take the place of the preset select-all menu option.<br>It is effective only when the **controller** parameter is set and the preset menu is available.<br>**NOTE**<br>**event** indicates the returned information.|


## EditorMenuOptions

Describes the edit menu options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | [ResourceStr](ts-types.md#resourcestr) | Yes| Icon.|
| builder | () =&gt; void | No| Builder of the custom component displayed upon click. It must be used with @Builder for building the custom component.|
| action | () =&gt; void | No| Action triggered when the menu option is clicked.|


## ExpandedMenuOptions

Describes the expanded drop-down menu options.

Inherits from [MenuItemOptions](ts-basic-components-menuitem.md#menuitemoptions).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | () =&gt; void | No| Action triggered when the menu option is clicked.|

## EditorEventInfo

Provides the information about the selected content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| content | [RichEditorSelection](ts-basic-components-richeditor.md#richeditorselection) | No| Information about the selected content.|

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are not supported. The default width is 224 vp, and the height is adaptive.

## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

This example demonstrates the effects of a custom context menu on selection bound to text with different triggering modes.

```ts
import { SelectionMenu, EditorMenuOptions, ExpandedMenuOptions, EditorEventInfo, SelectionMenuOptions } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State select: boolean = true
  controller: RichEditorController = new RichEditorController();
  options: RichEditorOptions = { controller: this.controller }
  @State message: string = 'Hello word'
  @State textSize: number = 30
  @State fontWeight: FontWeight = FontWeight.Normal
  @State start: number = -1
  @State end: number = -1
  @State visibleValue: Visibility = Visibility.Visible
  @State colorTransparent: Color = Color.Transparent
  @State textStyle: RichEditorTextStyle = {}
  private editorMenuOptions: Array<EditorMenuOptions> =
    [
      { icon: $r("app.media.ic_notepad_textbold"), action: () => {
        if (this.controller) {
          let selection = this.controller.getSelection();
          let spans = selection.spans
          spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
            if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
              let span = item as RichEditorTextSpanResult
              this.textStyle = span.textStyle
              let start = span.offsetInSpan[0]
              let end = span.offsetInSpan[1]
              let offset = span.spanPosition.spanRange[0]
              if (this.textStyle.fontWeight != 11) {
                this.textStyle.fontWeight = FontWeight.Bolder
              } else {
                this.textStyle.fontWeight = FontWeight.Normal
              }
              this.controller.updateSpanStyle({
                start: offset + start,
                end: offset + end,
                textStyle: this.textStyle
              })
            }
          })
        }
      } },
      { icon: $r("app.media.ic_notepad_texttilt"), action: () => {
        if (this.controller) {
          let selection = this.controller.getSelection();
          let spans = selection.spans
          spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
            if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
              let span = item as RichEditorTextSpanResult
              this.textStyle = span.textStyle
              let start = span.offsetInSpan[0]
              let end = span.offsetInSpan[1]
              let offset = span.spanPosition.spanRange[0]
              if (this.textStyle.fontStyle == FontStyle.Italic) {
                this.textStyle.fontStyle = FontStyle.Normal
              } else {
                this.textStyle.fontStyle = FontStyle.Italic
              }
              this.controller.updateSpanStyle({
                start: offset + start,
                end: offset + end,
                textStyle: this.textStyle
              })
            }
          })
        }
      } },
      { icon: $r("app.media.ic_notepad_underline"),
        action: () => {
          if (this.controller) {
            let selection = this.controller.getSelection();
            let spans = selection.spans
            spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
              if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
                let span = item as RichEditorTextSpanResult
                this.textStyle = span.textStyle
                let start = span.offsetInSpan[0]
                let end = span.offsetInSpan[1]
                let offset = span.spanPosition.spanRange[0]
                if (this.textStyle.decoration) {
                  if (this.textStyle.decoration.type == TextDecorationType.Underline) {
                    this.textStyle.decoration.type = TextDecorationType.None
                  } else {
                    this.textStyle.decoration.type = TextDecorationType.Underline
                  }
                } else {
                  this.textStyle.decoration = { type: TextDecorationType.Underline, color: Color.Black }
                }
                this.controller.updateSpanStyle({
                  start: offset + start,
                  end: offset + end,
                  textStyle: this.textStyle
                })
              }
            })
          }
        }
      },
      { icon: $r("app.media.app_icon"), action: () => {
      }, builder: (): void => this.sliderPanel() },
      { icon: $r("app.media.ic_notepad_textcolor"), action: () => {
        if (this.controller) {
          let selection = this.controller.getSelection();
          let spans = selection.spans
          spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
            if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
              let span = item as RichEditorTextSpanResult
              this.textStyle = span.textStyle
              let start = span.offsetInSpan[0]
              let end = span.offsetInSpan[1]
              let offset = span.spanPosition.spanRange[0]
              if (this.textStyle.fontColor == Color.Orange || this.textStyle.fontColor == '#FFFFA500') {
                this.textStyle.fontColor = Color.Black
              } else {
                this.textStyle.fontColor = Color.Orange
              }
              this.controller.updateSpanStyle({
                start: offset + start,
                end: offset + end,
                textStyle: this.textStyle
              })
            }
          })
        }
      } }]
  private expandedMenuOptions: Array<ExpandedMenuOptions> =
    [{ startIcon: $r("app.media.icon"), content: 'Dictionary', action: () => {
    } }, { startIcon: $r("app.media.icon"), content: 'Translate', action: () => {
    } }, { startIcon: $r("app.media.icon"), content: 'Search', action: () => {
    } }]
  private expandedMenuOptions1: Array<ExpandedMenuOptions> = []
  private editorMenuOptions1: Array<EditorMenuOptions> = []
  private selectionMenuOptions: SelectionMenuOptions = {
    editorMenuOptions: this.editorMenuOptions,
    expandedMenuOptions: this.expandedMenuOptions,
    controller: this.controller,
    onCut: (event?: EditorEventInfo) => {
      if (event && event.content) {
        event.content.spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
          if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
            let span = item as RichEditorTextSpanResult
            console.info('test cut' + span.value)
            console.info('test start ' + span.offsetInSpan[0] + ' end: ' + span.offsetInSpan[1])
          }
        })
      }
    },
    onPaste: (event?: EditorEventInfo) => {
      if (event && event.content) {
        event.content.spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
          if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
            let span = item as RichEditorTextSpanResult
            console.info('test onPaste' + span.value)
            console.info('test start ' + span.offsetInSpan[0] + ' end: ' + span.offsetInSpan[1])
          }
        })
      }
    },
    onCopy: (event?: EditorEventInfo) => {
      if (event && event.content) {
        event.content.spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
          if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
            let span = item as RichEditorTextSpanResult
            console.info('test cut' + span.value)
            console.info('test start ' + span.offsetInSpan[0] + ' end: ' + span.offsetInSpan[1])
          }
        })
      }
    },
    onSelectAll: (event?: EditorEventInfo) => {
      if (event && event.content) {
        event.content.spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
          if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
            let span = item as RichEditorTextSpanResult
            console.info('test onPaste' + span.value)
            console.info('test start ' + span.offsetInSpan[0] + ' end: ' + span.offsetInSpan[1])
          }
        })
      }
    }
  }

  @Builder sliderPanel() {
    Column() {
      Flex({ justifyContent: FlexAlign.SpaceBetween, alignItems: ItemAlign.Center }) {
        Text('A').fontSize(15)
        Slider({ value: this.textSize, step: 10, style: SliderStyle.InSet })
          .width(210)
          .onChange((value: number, mode: SliderChangeMode) => {
            if (this.controller) {
              let selection = this.controller.getSelection();
              if (mode == SliderChangeMode.End) {
                if (this.textSize == undefined) {
                  this.textSize = 0
                }
                let spans = selection.spans
                spans.forEach((item: RichEditorTextSpanResult | RichEditorImageSpanResult, index) => {
                  if (typeof (item as RichEditorTextSpanResult)['textStyle'] != 'undefined') {
                    this.textSize = Math.max(this.textSize, (item as RichEditorTextSpanResult).textStyle.fontSize)
                  }
                })
              }
              if (mode == SliderChangeMode.Moving || mode == SliderChangeMode.Click) {
                this.start = selection.selection[0]
                this.end = selection.selection[1]
                this.textSize = value
                this.controller.updateSpanStyle({
                  start: this.start,
                  end: this.end,
                  textStyle: { fontSize: this.textSize }
                })
              }
            }
          })
        Text('A').fontSize(20).fontWeight(FontWeight.Medium)
      }.borderRadius($r('sys.float.ohos_id_corner_radius_card'))
    }
    .shadow(ShadowStyle.OUTER_DEFAULT_MD)
    .backgroundColor(Color.White)
    .borderRadius($r('sys.float.ohos_id_corner_radius_card'))
    .padding(15)
    .height(48)
  }

  @Builder
  MyMenu() {
    Column() {
      SelectionMenu(this.selectionMenuOptions)
    }
    .width(256)
    .backgroundColor(Color.Transparent)
  }

  @Builder
  MyMenu2() {
    Column() {
      SelectionMenu({
        editorMenuOptions: this.editorMenuOptions,
        expandedMenuOptions: this.expandedMenuOptions1,
        controller: this.controller,
      })
    }
    .width(256)
    .backgroundColor(Color.Transparent)
  }

  @Builder
  MyMenu3() {
    Column() {
      SelectionMenu({
        editorMenuOptions: this.editorMenuOptions1,
        expandedMenuOptions: this.expandedMenuOptions,
        controller: this.controller,
      })
    }
    .width(256)
    .backgroundColor(Color.Transparent)
  }

  build() {
    Column() {
      Button("SetSelection")
        .onClick((event: ClickEvent) => {
          if (this.controller) {
            this.controller.setSelection(0, 2)
          }
        })

      RichEditor(this.options)
        .onReady(() => {
          this.controller.addTextSpan(this.message, { style: { fontColor: Color.Orange, fontSize: 30 } })
          this.controller.addTextSpan(this.message, { style: { fontColor: Color.Black, fontSize: 25 } })
        })
        .onSelect((value: RichEditorSelection) => {
          if (value.selection[0] == -1 && value.selection[1] == -1) {
            return
          }
          this.start = value.selection[0]
          this.end = value.selection[1]
        })
        .bindSelectionMenu(RichEditorSpanType.TEXT, this.MyMenu3(), RichEditorResponseType.RIGHT_CLICK)
        .bindSelectionMenu(RichEditorSpanType.TEXT, this.MyMenu2(), RichEditorResponseType.SELECT)
        .borderWidth(1)
        .borderColor(Color.Red)
        .width(200)
        .height(200)
    }
  }
}
```
> **NOTE**
>
> Icons in bold and italics are not preset in the system. The sample code uses the default icons. You need to replace the icons in **editorMenuOptions** with the desired icons.

![selectionmenu](figures/selectionmenu.jpeg)
