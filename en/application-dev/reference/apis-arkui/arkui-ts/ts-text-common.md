# Text Component Common APIs

>**NOTE**
>
>This topic covers the common APIs of text components.
>The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CaretStyle<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type                                  | Mandatory| Description|
| ------ | ------------------------------------------ | ---- | -------- |
| width  | [Length](ts-types.md#length)               | No  | Caret size. It cannot be set in percentage.|
| color  | [ResourceColor](ts-types.md#resourcecolor) | No  | Caret color.|

## LayoutManager<sup>12+</sup>

Implements a **LayoutManager** object.
> **NOTE**
>
> After the text content is changed, you must wait for the layout to be completed before you can obtain the most up-to-date layout information.

### Objects to Import
The following uses the **Text** component as an example.
```
controller: TextController = new TextController()
let layoutManager: LayoutManager = this.controller.getLayoutManager();
```

### getLineCount

getLineCount(): number

Obtains the total number of lines in the component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Total number of lines in the component.|

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

Obtains the position of a glyph close to a given coordinate.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| x | number | Yes   | X coordinate relative to the component, in px.|
| y | number | Yes   | Y coordinate relative to the component, in px.|

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity) | Position of the glyph.|

### getLineMetrics

getLineMetrics(lineNumber: number): LineMetrics

Obtains the metrics information of a specified line.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | Yes   | Line number, starting at 0.|

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| [LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | Button("Line Metrics")|

## PositionWithAffinity

Describes the position and affinity of a glyph.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                  | Read Only| Mandatory| Description                     |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | Yes  | Yes  | Index of the glyph relative to the paragraph. The value is an integer. |
| affinity  | [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | Yes  | Yes  | Affinity of the position.            |

## TextMenuItemId<sup>12+</sup>

Provides the menu ID.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name          | Type             | Read Only  | Mandatory  | Description    |
| ------------ |---------------------| ---- | ---- | ------ |
| CUT  | [TextMenuItemId](#textmenuitemid12) |  Yes |  No | Cut operation by default.|
| COPY  | [TextMenuItemId](#textmenuitemid12) |  Yes |  No | Copy operation by default.|
| PASTE | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Paste operation by default.|
| SELECT_ALL   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Select-all operation by default.|
| COLLABORATION_SERVICE   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Collaboration service.|
| CAMERA_INPUT   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Camera input|

### of

static of(id: ResourceStr): TextMenuItemId

Creates a **TextMenuItemId** object based on **id**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [ResourceStr](ts-types.md#resourcestr) | Yes  | Menu ID.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- | 
| [TextMenuItemId](#textmenuitemid12) | **TextMenuItemId** object.|

### equals

equals(id: TextMenuItemId): boolean

Checks whether this **TextMenuItemId** object is the same as another **TextMenuItemId** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [TextMenuItemId](#textmenuitemid12) | Yes  | ID of the **TextMenuItemId** object to compare.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- | 
| boolean | Whether the two **TextMenuItemId** objects are the same.|

## TextMenuItem

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| content | [ResourceStr](ts-types.md#resourcestr) | Yes  | Menu name.|
| icon | [ResourceStr](ts-types.md#resourcestr) | No  | Menu icon.<br>Online images are not supported.|
| id | [TextMenuItemId](#textmenuitemid12) | Yes  | Menu ID.|

## EditMenuOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onCreateMenu

onCreateMenu(menuItems: Array\<TextMenuItem>): Array\<TextMenuItem>

Creates a menu with the specified menu items.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array\<[TextMenuItem](#textmenuitem)> | Yes  | Menu items.<br>**NOTE**<br>Changes to the name of the default menu item do not take effect.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- | 
| Array\<[TextMenuItem](#textmenuitem)> | Menu items set.<br>**NOTE**<br>The icon of the default menu item is not returned.|

### onMenuItemClick

onMenuItemClick(menuItem: TextMenuItem, range: TextRange): boolean

Called when the specified menu item is clicked.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItem | [TextMenuItem](#textmenuitem) | Yes  | Menu item.|
| range | [TextRange](ts-universal-attributes-text-style.md#textrange12) | Yes  | Selected text.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- | 
| boolean | Execution logic of the menu item.<br>Returns **true** if the default system logic is intercepted and only the custom logic is executed.<br>Returns **false** if the custom logic is executed before the default system logic.|

## TextRange<sup>12+</sup>

Defines the text range.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## EditableTextOnChangeCallback<sup>12+</sup>

type EditableTextOnChangeCallback = (value: string, previewText?: PreviewText) => void

Invoked when the input in the text box changes.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| value | string | Yes| Text displayed in the text box.|
| previewText | [PreviewText](#previewtext12) | No| Information about the preview text, including its start position and text content.|

## TextDataDetectorType<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Description                                  |
| ----- | -------------------------------------- |
| PHONE_NUMBER  | Phone number.|
| URL | URL.|
| EMAIL | Email address.|
| ADDRESS | Address.|
| DATE_TIME | Time.|

## TextDeleteDirection<sup>12+</sup>

Defines the direction for deleting text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Value  | Description                              |
| ------- | ---- | ---------------------------------- |
| BACKWARD | 0    | Backward delete.|
| FORWARD    | 1    | Forward delete.|

## InsertValue<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Mandatory| Description                                                        |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| insertOffset  | number | Yes  | Position of the inserted text.|
| insertValue  | string | Yes  | Content of the inserted text.|

## DeleteValue<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Mandatory| Description                                                        |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| deleteOffset  | number | Yes  | Position of the deleted text.|
| direction  | [TextDeleteDirection](#textdeletedirection12) | Yes  | Direction for deleting the text.|
| deleteValue  | string | Yes  | Content of the deleted text.|

## TextDataDetectorConfig<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type | Mandatory| Description |
| ------ | -------- | ---- | ------------------------------------------- |
| types   | [TextDataDetectorType](ts-text-common.md#textdatadetectortype11)[] | Yes  | Entity types for text recognition. Values **null** and **[]** indicate that all types of entities can be recognized.|
| onDetectResultUpdate   | (result: string) => void | No  | Callback invoked when text recognition succeeds.<br>- **result**: text recognition result, in JSON format.|
| color<sup>12+</sup>   | [ResourceColor](ts-types.md#resourcecolor) | No  | Entity color when text recognition succeeds.<br>Default value: **'#ff007dff'**|
| decoration<sup>12+</sup>  | [DecorationStyleInterface](ts-universal-styled-string.md#decorationstyleinterface)| No  | Style of the entity decorative line when text recognition succeeds.<br>Default value:<br>{<br> type: TextDecorationType.Underline,<br> color: consistent with the entity color,<br> style: TextDecorationStyle.SOLID <br>} |
## PreviewText<sup>12+</sup>

Preview text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Mandatory| Description                                                    |
| -------- | ------------------------------------------------ | ---- | -------------------------------------------------------- |
| offset | number | Yes  | Start position of the preview text.|
| value    | string         | Yes  | Content of the preview text.        |

## FontSettingOptions<sup>12+</sup>

Defines the font settings.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Mandatory| Description                                                    |
| -------- | ------------------------------------------------ | ---- | -------------------------------------------------------- |
| enableVariableFontWeight | boolean | No  | Whether to support variable font weight adjustment.|

## OnDidChangeCallback<sup>12+</sup>

type OnDidChangeCallback = (rangeBefore: TextRange, rangeAfter: TextRange) => void

Represents the callback invoked after text changes.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| rangeBefore | [TextRange](ts-universal-attributes-text-style.md#textrange12) | Yes| Range of the text to be changed.|
| rangeAfter | [TextRange](ts-universal-attributes-text-style.md#textrange12) | Yes| Range of the text added.|

## StyledStringChangedListener<sup>12+</sup>

Defines the listener for changes of the styled string text content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| onWillChange | Callback<[StyledStringChangeValue](#styledstringchangevalue12), boolean> | No| Callback invoked when text is about to change.|
| onDidChange | [OnDidChangeCallback](#ondidchangecallback12) | No| Callback invoked when text is changed.|

## StyledStringChangeValue<sup>12+</sup>

Describes the text changes of the styled string.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| range | TextRange | Yes| Range of the styled string to be replaced in the original string.|
| replacementString | [StyledString](ts-universal-styled-string.md#styledstring) | Yes| Styled string used for replacement.|
