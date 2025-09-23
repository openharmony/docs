# Text Component Common APIs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @kangshihui-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

>**NOTE**
>
>This topic covers the common APIs of text components.
>The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CaretStyle<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type                                  | Read Only| Optional| Description|
| ------ | ------------------------------------------ | ---- | ---- | -------- |
| width  | [Length](ts-types.md#length)               | No  | Yes| Caret size. It cannot be set in percentage.<br>Default value: **'2vp'**.|
| color  | [ResourceColor](ts-types.md#resourcecolor) | No  | Yes  | Caret color.<br>Default value: **'#ff007dff'**.|

## LayoutManager<sup>12+</sup>

Implements a **LayoutManager** object.

> **NOTE**
>
> After the text content is changed, you must wait for the layout to be completed before you can obtain the most up-to-date layout information.

### Objects to Import
The **Text** component is used as an example. For details, see [Example 10: Obtaining Text Information](./ts-basic-components-text.md#example-10-obtaining-text-information).
```ts
controller: TextController = new TextController();
let layoutManager: LayoutManager = this.controller.getLayoutManager();
```

### getLineCount

getLineCount(): number

Obtains the total number of lines in the component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Total number of lines in the component.|

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

Obtains the position of a glyph close to a given coordinate.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| x | number | Yes   | X coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md)|
| y | number | Yes   | Y coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md)|

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity12) | Position of the glyph.|

### getLineMetrics

getLineMetrics(lineNumber: number): LineMetrics

Obtains the information about the specified line, including line metrics, text style information, and font properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | Yes   | Line number, which is zero-based.|

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| [LineMetrics](#linemetrics12) | Information about the specified line, including line metrics, text style information, and font properties.<br>Returns an invalid value if the line number is less than 0 or exceeds the actual number of lines.|

### getRectsForRange<sup>14+</sup>

getRectsForRange(range: TextRange, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox>

Obtains the drawing area information for characters or placeholders within a specified text range, based on the specified width and height of a rectangle.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                | Mandatory| Description                    |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [TextRange](#textrange12)| Yes  | Text range for which to obtain the area information. |
| widthStyle  | [RectWidthStyle](#rectwidthstyle14)   | Yes  | Width of the rectangle.|
| heightStyle | [RectHeightStyle](#rectheightstyle14) | Yes  | Height of the rectangle.|

**Return value**

| Type                        | Description       |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox14)> | Array holding the rectangles obtained.|

## PositionWithAffinity<sup>12+</sup>

Describes the position and affinity of a glyph.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                  | Read Only| Optional| Description                     |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | No  | No  | Index of the glyph relative to the paragraph. The value is an integer. |
| affinity  | [Affinity](#affinity12) | No  | No  | Affinity of the position.            |

## TextMenuItemId<sup>12+</sup>

Defines the unique identifier for a custom menu item. It is used to identify menu items. The IDs for built-in menu items are listed in the table below.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name          | Type             | Read Only  | Optional | Description    |
| ------------ |---------------------| ---- | ---- | ------ |
| CUT  | [TextMenuItemId](#textmenuitemid12) |  Yes |  No| ID for the cut menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| COPY  | [TextMenuItemId](#textmenuitemid12) |  Yes |  No | ID for the paste menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PASTE | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the paste menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SELECT_ALL   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the select-all menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| COLLABORATION_SERVICE   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the collaboration service menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| CAMERA_INPUT   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No  | ID for the camera input menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| AI_WRITER<sup>13+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the menu item involving text enhancement features, such as polishing, summary extraction, and formatting, for selected text. This menu item requires foundation model capabilities to work.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| TRANSLATE<sup>15+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the translate menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| SHARE<sup>18+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the share menu item, which launches a window for sharing the selected text.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| SEARCH<sup>18+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | ID for the search menu item, which launches a browser to search the selected text.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| url<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Redirection service for the selected URL, launching a browser search or application page.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| email<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Redirection service for the selected email address, launching the email application.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| phoneNumber<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Redirection service for the selected phone number, launching the phone dialer page.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| address<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Redirection service for the selected address, launching the map application.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| dateTime<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | Redirection service for the selected date and time, launching the page for creating a calendar event.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| askAI<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes   | No   | AI query capability for the selected text.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
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

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [TextMenuItemId](#textmenuitemid12) | Yes  | ID of the **TextMenuItemId** object to compare.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| boolean | Whether the two **TextMenuItemId** objects are the same.<br>**true** if the objects are equal; **false** otherwise.|

## TextMenuItem<sup>12+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type                             | Read Only| Optional| Description  |
| ------- | --------------------------------- | ---- | ---- | --------------------------------- |
| content | [ResourceStr](ts-types.md#resourcestr) | No  | No| Menu name.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| icon | [ResourceStr](ts-types.md#resourcestr) | No  | Yes| Menu icon.<br>Online images are not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| id | [TextMenuItemId](#textmenuitemid12) |  No  | No | Menu ID.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| labelInfo<sup>15+</sup> | [ResourceStr](ts-types.md#resourcestr) | No  | Yes| Shortcut key hint.<br>This field is only supported on 2-in-1 devices.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|

## EditMenuOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onCreateMenu<sup>12+</sup>

onCreateMenu(menuItems: Array\<TextMenuItem>): Array\<TextMenuItem>

Triggered when the menu is being created. Menu data can be configured within this callback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array\<[TextMenuItem](#textmenuitem12)> | Yes  |  Menu items to be displayed.<br>**NOTE**<br>Modifications to the name, icon, or shortcut hint of default menu items do not take effect.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12)> | Menu items after the processing.|

### onMenuItemClick<sup>12+</sup>

onMenuItemClick(menuItem: TextMenuItem, range: TextRange): boolean

Triggered when the specified menu item is clicked.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItem | [TextMenuItem](#textmenuitem12) | Yes  | Menu item.|
| range | [TextRange](#textrange12) | Yes  | Selected text.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| boolean | Execution logic of the menu item.<br>Returns **true** if the default system logic is intercepted and only the custom logic is executed.<br>Returns **false** if the custom logic is executed before the default system logic.|

### onPrepareMenu<sup>20+</sup>

onPrepareMenu?: OnPrepareMenuCallback

Triggered before the menu is displayed after the text selection area changes. Menu data can be configured within this callback.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [OnPrepareMenuCallback](#onpreparemenucallback20) | Callback triggered before the menu is displayed after the text selection area changes. Menu data can be configured within this callback.|

## OnPrepareMenuCallback<sup>20+</sup>

type OnPrepareMenuCallback = (menuItems: Array\<TextMenuItem\>) => Array\<TextMenuItem\>

Represents the callback triggered before the menu is displayed after the text selection area changes. Menu data can be configured within this callback.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array\<[TextMenuItem](#textmenuitem12)> | Yes  | Menu items to be displayed.<br>**NOTE**<br>Modifications to the name, icon, or shortcut hint of default menu items do not take effect.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12)> | Menu items after the processing.|

## TextRange<sup>12+</sup>

Defines the text range.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read Only| Optional| Description|
| -- | -- | -- | -- | -- |
| start | number | No| Yes| Start index.|
| end | number | No| Yes| End index.|

## EditableTextOnChangeCallback<sup>12+</sup>

type EditableTextOnChangeCallback = (value: string, previewText?: PreviewText, options?: TextChangeOptions) => void

Represents the callback triggered when the content in the text box changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| value | string | Yes| Text displayed in the text box.|
| previewText | [PreviewText](#previewtext12) | No| Information about the preview text, including its start position and text content.|
| options<sup>15+</sup> | [TextChangeOptions](#textchangeoptions15) | No| Information about the text change, including the selection range before and after the change, the text content before the change, and the preview text information.|

## TextDataDetectorType<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value  | Description                              |
| ----- | ----- | --------------------------------- |
| PHONE_NUMBER  | 0 | Phone number.|
| URL | 1 | URL.|
| EMAIL | 2 | Email address.|
| ADDRESS | 3 | Address.|
| DATE_TIME<sup>12+</sup> | 4 | Time.|

## TextDeleteDirection<sup>12+</sup>

Defines the direction for deleting text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Value  | Description                       |
| ------- | ---- | ---------------------------------- |
| BACKWARD | 0    | Backward delete.|
| FORWARD    | 1    | Forward delete.|

## SuperscriptStyle<sup>20+</sup>

Enumerates the text superscript and subscript styles.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Value  | Description                       |
| ------- | ---- | ---------------------------------- |
| NORMAL | 0    | Normal text style.|
| SUPERSCRIPT    | 1    | Superscript text style.|
| SUBSCRIPT    | 2    | Subscript text style.|

## MenuType<sup>13+</sup>

Enumerates the menu types.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ------- | ---- | ------------------- |
| SELECTION_MENU | 0 | Text selection menu.|
| PREVIEW_MENU | 1 | Preview menu.|

## KeyboardAppearance<sup>15+</sup>

Enumerates the appearance modes of the keyboard.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ------- | ---- | ------------------- |
| NONE_IMMERSIVE | 0 | Default appearance mode, not using immersive style.|
| IMMERSIVE | 1 | Immersive style, following the system color mode.|
| LIGHT_IMMERSIVE | 2 | Immersive style in light mode.|
| DARK_IMMERSIVE | 3 | Immersive style in dark mode.|

## InsertValue<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                         | Read Only| Optional| Description                                                        |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| insertOffset  | number | No  | No| Position of the inserted text.|
| insertValue  | string | No  | No  | Content of the inserted text.|

## DeleteValue<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| deleteOffset  | number | No  | No| Position of the deleted text.|
| direction  | [TextDeleteDirection](#textdeletedirection12) | No  | No  | Direction for deleting the text.|
| deleteValue  | string | No  | No  | Content of the deleted text.|

## TextDataDetectorConfig<sup>11+</sup>

This configuration is only available for the [Text](ts-basic-components-text.md) and [RichEditor](ts-basic-components-richeditor.md) components.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type | Read Only| Optional| Description |
| ------ | -------- | ---- | ---- | ------------------------------------------- |
| types   | [TextDataDetectorType](ts-text-common.md#textdatadetectortype11)[] | No| No | Entity types for text recognition. Values **null** and **[]** indicate that all types of entities can be recognized.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onDetectResultUpdate   | Callback\<string> | No| Yes | Callback invoked when text recognition succeeds.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| color<sup>12+</sup>   | [ResourceColor](ts-types.md#resourcecolor) | No| Yes  | Entity color when text recognition succeeds.<br>Default value: **'#ff0a59f7'**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| decoration<sup>12+</sup>  | [DecorationStyleInterface](ts-universal-styled-string.md#decorationstyleinterface)| No| Yes  | Style of the entity decoration when text recognition succeeds.<br>Default value:<br>{<br> type: TextDecorationType.Underline,<br> color: same as the entity<br> style: TextDecorationStyle.SOLID <br>}<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| enablePreviewMenu<sup>20+</sup>   | boolean | No| Yes  | Whether to enable the preview menu displayed when long-pressing recognized text. The value **true** means to enable the preview menu, and **false** means the opposite.<br>Default value: **false**.<br>When [copyOptions](ts-basic-components-richeditor.md#copyoptions) is set to **None**, even if **enablePreviewMenu** is set to **true**, long-pressing AI entities will not display the preview menu.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## PreviewText<sup>12+</sup>

Preview text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Read Only| Optional| Description                                                    |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| offset | number | No  | No| Start position of the preview text.|
| value    | string         | No  | No  | Content of the preview text.        |

## FontSettingOptions<sup>12+</sup>

Defines the font configuration option for adjusting variable font weights, for example, by setting the font weight of components within an application.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Read Only| Optional| Description                                                    |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| enableVariableFontWeight | boolean | No| Yes | Whether to enable variable font weight adjustment.<br>Default value: **false**.<br>The value **true** means to enable variable font weight adjustment, and **false** means the opposite.|

## OnDidChangeCallback<sup>12+</sup>

type OnDidChangeCallback = (rangeBefore: TextRange, rangeAfter: TextRange) => void

Represents the callback invoked after text changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| rangeBefore | [TextRange](#textrange12) | Yes| Range of the text to be changed.|
| rangeAfter | [TextRange](#textrange12) | Yes| Range of the text added.|

## StyledStringChangedListener<sup>12+</sup>

Defines the listener for changes of the styled string text content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read Only| Optional| Description|
| -- | -- | -- | -- | -- |
| onWillChange | Callback<[StyledStringChangeValue](#styledstringchangevalue12), boolean> | No| Yes| Callback invoked when text is about to change.|
| onDidChange | [OnDidChangeCallback](#ondidchangecallback12) | No| Yes| Callback invoked when text is changed.|

## StyledStringChangeValue<sup>12+</sup>

Describes the text changes of the styled string.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read Only| Optional| Description|
| -- | -- | -- | -- | -- |
| range | [TextRange](#textrange12) | No| No| Range of the styled string to be replaced in the original string.|
| replacementString | [StyledString](ts-universal-styled-string.md#styledstring) | No| No| Styled string used for replacement.|
| previewText | [StyledString](ts-universal-styled-string.md#styledstring) | No| Yes| Preview styled string.|

## AutoCapitalizationMode<sup>20+</sup>

Enumerates automatic capitalization modes. This only provides API capabilities; the specific implementation depends on the input method application.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ------- | ---- | ------------------- |
| NONE | 0 | Default state; automatic capitalization is disabled.|
| WORDS | 1 | Automatic capitalization applied per word.|
| SENTENCES | 2 | Automatic capitalization applied per sentence.|
| ALL_CHARACTERS | 3 | Automatic capitalization applied to all characters.|

## TextBaseController<sup>12+</sup>

Defines a text selection controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### setSelection<sup>12+</sup>

setSelection(selectionStart: number, selectionEnd: number, options?: SelectionOptions): void

Sets the range of content selection. The selected content is highlighted.

If both **selectionStart** and **selectionEnd** are set to **-1**, the entire content is selected.

The component must be focused for the API call to have effect.

Since API version 12, on 2-in-1 devices, regardless of the value of **options**, calling the **setSelection** API will not display a menu; if a menu is already open, calling the API will close it.

On non-2-in-1 devices, when **options** is set to **MenuPolicy.DEFAULT**, the following rules apply after the API is called:

1. If the component has a menu with a selection handle, the menu remains open and is relocated according to the selection.

2. If the component has a menu without a selection handle, the menu remains open and its position remains unchanged.

3. If there is no menu open, no menu will appear after the selection.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name           | Type  | Mandatory  | Description   |
| -------------- | ------ | ---- | ------- |
| selectionStart | number | Yes   | Start position of the selection.<br>Values less than 0 are treated as **0**.|
| selectionEnd   | number | Yes   | End position of the selection.<br>If the value exceeds the text length, the current text length is used instead.|
| options   | [SelectionOptions](ts-universal-attributes-text-style.md) | No   | Configuration of options.|

### closeSelectionMenu<sup>12+</sup>

closeSelectionMenu(): void

Closes the custom or default text selection menu.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getLayoutManager<sup>12+</sup>

getLayoutManager(): LayoutManager

Obtains a **LayoutManager** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [LayoutManager](ts-text-common.md#layoutmanager12) | Implements a **LayoutManager** object.|

## TextEditControllerEx<sup>12+</sup>

Implements an extended text editing controller.

Inherits [TextBaseController](#textbasecontroller12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### isEditing<sup>12+</sup>

isEditing(): boolean

Obtains the editing status of the rich text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type   | Description                         |
| ------- | ----------------------------- |
| boolean | Editing status of the rich text. **true** means that the text is in editable state, and **false** means the opposite.|

### stopEditing<sup>12+</sup>

stopEditing(): void

Stops editing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getCaretOffset<sup>12+</sup>

getCaretOffset(): number

Obtains the current position of the caret.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Position of the caret.|

### setCaretOffset<sup>12+</sup>

setCaretOffset(offset: number): boolean

Sets the caret offset.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description               |
| ------ | ------ | ---- | -------------------- |
| offset | number | Yes   | Offset of the caret. If the offset is outside the range of all content, the setting fails.|

**Return value**

| Type     | Description       |
| ------- | --------- |
| boolean | Whether the caret offset is set successfully.<br>Returns **true** if it is set successfully; returns **false** otherwise.|

### getPreviewText<sup>12+</sup>

getPreviewText?(): PreviewText

Obtains the preview text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [PreviewText](#previewtext12) | Preview text.|.

## StyledStringController<sup>12+</sup>

Defines a styled string controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### setStyledString<sup>12+</sup>

setStyledString(styledString: StyledString): void

Sets the styled string displayed in the rich text component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory  | Description               |
| ----- | ------ | ---- | ------------------- |
| styledString | [StyledString](ts-universal-styled-string.md#styledstring) | Yes   | Styled string to set.<br>**NOTE**<br>The child class [MutableStyledString](ts-universal-styled-string.md#mutablestyledstring) of **StyledString** can also serve as the argument.|

### getStyledString<sup>12+</sup>

getStyledString(): MutableStyledString

Obtains the styled string displayed in the rich text component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type   | Description                         |
| ------- | ----------------------------- |
| [MutableStyledString](ts-universal-styled-string.md#mutablestyledstring) | Styled string displayed in the rich text component.|

## DecorationStyleResult<sup>12+</sup>

Provides the text decoration information returned by the backend.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type                             | Read Only| Optional| Description  |
| ------- | --------------------------------- | ---- | ---- | --------------------------------- |
| type | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | No  | No| Type of the text decoration.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| color | [ResourceColor](ts-types.md#resourcecolor) | No  | No  | Color of the text decoration.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| style | [TextDecorationStyle](ts-appendix-enums.md#textdecorationstyle12) | No  | Yes  | Style of the text decoration.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| thicknessScale<sup>20+</sup> | number | No  | Yes  | Scale factor of the text decoration thickness.<br>Default value: **1.0**.<br>Value range: [0, +∞).<br>Note: Negative values are treated as the default value.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|

## LineMetrics<sup>12+</sup>

type LineMetrics = LineMetrics

Describes the measurement information of a single line of text in the text layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | Measurement information of a single line of text in the text layout.|

## Affinity<sup>12+</sup>

type Affinity = Affinity

Enumerates the affinity modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | Affinity mode enum.|

## TextBox<sup>14+</sup>

type TextBox = TextBox

Describes the rectangle that holds the text.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [TextBox](../../apis-arkgraphics2d/js-apis-graphics-text.md#textbox) | Rectangle that holds the text.|

## Paragraph<sup>20+</sup>

type Paragraph = Paragraph

Implements a carrier that stores the text content and style. You can perform operations such as layout and drawing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [Paragraph](../../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph) | Carrier that stores the text content and style. You can perform operations such as layout and drawing.|

## RectHeightStyle<sup>14+</sup>

type RectHeightStyle = RectHeightStyle

Enumerates the rectangle height styles.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [RectHeightStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectheightstyle) | Rectangle height style enum.|

## RectWidthStyle<sup>14+</sup>

type RectWidthStyle = RectWidthStyle

Enumerates the rectangle width styles.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| [RectWidthStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectwidthstyle) | Rectangle width style enum.|

## TextChangeOptions<sup>15+</sup>

Provides information about the text before and after a change, including the selection ranges.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| rangeBefore  | [TextRange](#textrange12) | No  | No| Selection range before the change.|
| rangeAfter  | [TextRange](#textrange12) | No  | No  | Selection range after the change.|
| oldContent  | string | No  | No  | Text content before the change.|
| oldPreviewText | [PreviewText](#previewtext12) | No  | No| Preview text before the change.|

## EditableTextChangeValue<sup>15+</sup>

Provides detailed information of text changes, including preview text.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| content  | string | No  | No| Current text content.|
| previewText  | [PreviewText](#previewtext12) | No  | Yes  | Preview text.|
| options  | [TextChangeOptions](#textchangeoptions15) | No  | Yes  | Information about the text change.|

## TextMenuShowMode<sup>16+</sup>

Enumerates the display modes for context menus on selection.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ------- | ---- | ------------------- |
| DEFAULT | 0 | The menu is displayed in the current window.<br>|
| PREFER_WINDOW | 1 | The menu is preferentially displayed in a separate window. If a separate window is not supported, the menu is displayed in the current window.<br>**NOTE**<br>The context menu on selection cannot be displayed in a separate window under the following scenarios:<br>Windows other than the main application window, application subwindows, system modal windows, and system home screen windows<br>DevEco Studio Previewer<br>UIExtension<br>Text component that is already displayed in a child window (for example, **Popup**, **Dialog**, **Toast**, and **Menu**)<br>**TextInput** or **TextArea** components that support **AutoFill**<br>|

## TextMenuOptions<sup>16+</sup>

Provides the options for customizing the context menu on selection.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| showMode  | [TextMenuShowMode](#textmenushowmode16) | No  | Yes| Menu display mode.<br>Default value: **TextMenuShowMode.DEFAULT**|

## ShaderStyle<sup>20+</sup>

Defines the base class for text shader effects.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## LinearGradientStyle<sup>20+</sup>

Displays a linear gradient. **LinearGradientStyle** inherits from [ShaderStyle](#shaderstyle20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type  | Read Only| Optional  | Description |
| ------- | ------ | ---- | ----- | ----- |
| options | [LinearGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#lineargradientoptions18) | No| No | Options for displaying a linear gradient.|

### constructor<sup>20+</sup>

constructor(options: LinearGradientOptions)

A constructor used to create a **LinearGradientStyle** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory  | Description |
| ------- | ------ | ---- | ----- |
| options | [LinearGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#lineargradientoptions18) | Yes   | Options for displaying a linear gradient.|

## RadialGradientStyle<sup>20+</sup>

Displays a radial gradient. **RadialGradientStyle** inherits from [ShaderStyle](#shaderstyle20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| options | [RadialGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#radialgradientoptions18) | No | No| Options for displaying a radial gradient.|

### constructor<sup>20+</sup>

constructor(options: RadialGradientOptions)

A constructor used to create a **RadialGradientStyle** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RadialGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#radialgradientoptions18) | Yes   | Options for displaying a radial gradient.|

## ColorShaderStyle<sup>20+</sup>

Displays a solid color. **ColorShaderStyle** inherits from [ShaderStyle](#shaderstyle20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| color | [ResourceColor](ts-types.md#resourcecolor) | No | No | Options for displaying a solid color.|

### constructor<sup>20+</sup>

constructor(color: ResourceColor)

A constructor used to create a **ColorShaderStyle** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| color | [ResourceColor](ts-types.md#resourcecolor) | Yes   | Options for displaying a solid color.|

## IMEClient<sup>20+</sup>

Defines the input method client type bound to an input component.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| nodeId  | number | No | No| Unique ID of the current input component. The value must be greater than or equal to 0.|

## MaxLinesOptions<sup>20+</sup>

Configures the display effect of the **TextArea** component when the text exceeds the maximum number of lines.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Type   | Read Only| Optional | Description                                                        |
| ------------------- | ------- | ------- | ------- | ------------------------------------------------------------ |
| overflowMode | [MaxLinesMode](#maxlinesmode20)  | No | Yes| Non-inline mode of the **TextArea** component. When the text exceeds the set value of **maxLines** (maximum number of lines), a scroll effect is enabled. This requires simultaneous configuration of [textOverflow](ts-basic-components-textarea.md#textoverflow12), and **MaxLinesMode** takes effect only when **textOverflow** is set to **None** or **Clip**. By default, **MaxLinesMode** is set to **Clip**, indicating that text is clipped when it exceeds the value of **maxLines**.|

## MaxLinesMode<sup>20+</sup>

Enumerates the display effects of the **TextArea** component when text exceeds the maximum number of lines. The default value is **CLIP** (truncating text at the maximum line count).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Value | Description                 |
| --------------------- | -------  | ------------------- |
| CLIP                  | 0  | Text is clipped when it exceeds the maximum number of lines.|
| SCROLL                | 1  | Text can be scrolled when it exceeds the maximum number of lines.|

## LineSpacingOptions<sup>20+</sup>

Configures the line spacing of text and whether it applies only between lines.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Read Only| Optional| Description            |
| ------ | ------------------------------------------------------------ | ---- | ---- | ---------------- |
| onlyBetweenLines  | boolean | No  | Yes| Whether line spacing applies only between lines.<br>**true**: Line spacing applies only between lines; no extra spacing is added above the first line or below the last line. **false**: Extra line spacing is added both above the first line and below the last line.<br>Default value: **false**.|

## TextVerticalAlign<sup>20+</sup>

Defines the vertical alignment mode of text. The default value is **BASELINE** (aligning along the baseline).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        |  Value         | Description                 |
| --------------------- | -------------------| ------------------- |
| BASELINE |  0          | Aligns text along the baseline.|
| BOTTOM   |  1          | Aligns text to the bottom.|
| CENTER   |  2          | Aligns text vertically to the center.|
| TOP      |  3          | Aligns text to the top.|

## ContentTransition<sup>20+</sup>

Defines the base class for text transitions.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## NumericTextTransition<sup>20+</sup>

Implements a flip animation for numeric text. It applies only to positive integers (decimals and negative numbers are not supported). Gradient colors and text marquee mode are not supported. Text selection is not supported, and the [copyOption](../arkui-ts/ts-basic-components-text.md#copyoption9) property is ineffective. The flip animation fails if the text contains child components or is set via a styled string.

**NumericTextTransition** inherits from [ContentTransition](#contenttransition20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                                      | Type                                                        | Read Only| Optional| Description                                                        |
| ------------------------------------------ | ---------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| flipDirection                             | [FlipDirection](#flipdirection20)    | No  | Yes| Direction of the flip animation.<br>Default value: **FlipDirection.DOWN**.|
| enableBlur                                 | boolean                              | No  | Yes| Whether to enable the blur effect for the flip animation.<br>Default value: **false**.<br>**true**: Enable the blur effect.<br>**false**: Disable the blur effect.|

### constructor<sup>20+</sup>

constructor(options?: NumericTextTransitionOptions)

A constructor used to create a **NumericTextTransition** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory  | Description |
| ------- | ------ | ---- | ----- |
| options | [NumericTextTransitionOptions](#numerictexttransitionoptions20) | No   | Options of the numeric flip animation.|

## NumericTextTransitionOptions<sup>20+</sup>

Defines the options of the numeric flip animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                                      | Type                                                        | Read Only| Optional| Description                                                        |
| ------------------------------------------ | ---------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| flipDirection                              | [FlipDirection](#flipdirection20)    | No  | Yes| Direction of the flip animation.<br>Default value: **FlipDirection.DOWN**.|
| enableBlur                                 | boolean                              | No  | Yes| Whether to enable the blur effect for the flip animation.<br>Default value: **false**.<br>**true**: Enable the blur effect.<br>**false**: Disable the blur effect.|

## FlipDirection<sup>20+</sup>

Enumerates the directions of the flip animation. The default value is **DOWN**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Value | Description                 |
| --------------------- | -------  | ------------------- |
| DOWN                  | 0  | Content flips downward.|
| UP                    | 1  | Content flips upward.|

## TextLayoutOptions<sup>20+</sup>

Defines the text layout options.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| constraintWidth | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)  | No| Yes| Layout width of the measured text. If not set, the width is the maximum width occupied by a single-line layout.|

## TextContentAlign<sup>21+</sup>

Enumerates the vertical alignment directions of the text content area.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Value | Description                 |
| --------------------- | -------  | ------------------- |
| TOP                   | 0  | Aligns the content area to the top.|
| CENTER                | 1  | Aligns the content area to the center.|
| BOTTOM                | 2  | Aligns the content area to the bottom.|
