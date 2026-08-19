# Text Component Common APIs

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=7b34bfffe7374f8545e76279cf6c71ed9f41e8fc translatedAt=2026-08-17T10:33:06.337Z pushedAt=2026-08-18T03:38:44.449Z -->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The common APIs of text components provide basic text processing capabilities, including caret style settings, layout management, text selection control, and menu item customization. This module is suitable for scenarios that require fine-grained control over text components, such as text editors, rich text apps, and input forms. With these APIs, developers can customize the caret style, obtain text layout information, handle text selection, customize the editing menu, and so on, thereby improving the text interaction experience of the app.

## CaretStyle<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type                                  | Read-Only| Optional| Description|
| ------ | ------------------------------------------ | ---- | ---- | -------- |
| width  | [Length](ts-types.md#length)               | No   | Yes | Cursor size. Percentage is not supported.<br>Default value: '2vp' |
| color  | [ResourceColor](ts-types.md#resourcecolor) | No   | Yes   | Cursor color.<br>Default value: '#ff007dff', which indicates blue. |

## LayoutManager<sup>12+</sup>

Implements a layout manager object.

> **NOTE**
>
> After the text content is changed, you must wait for the layout to be completed before you can obtain the most up-to-date layout information.

### Objects to Import

Take the Text component as an example. For a complete example, see [Example 10: Obtaining Text Information](./ts-basic-components-text.md#example-10-obtaining-text-information) of the Text component.

```ts
controller: TextController = new TextController();
let layoutManager: LayoutManager = this.controller.getLayoutManager();
```

### getLineCount<sup>12+</sup>

getLineCount(): number

Obtains the total number of lines in the component.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest total number of lines.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Total number of lines of the component content. Returns 0 when [LayoutManager](#layoutmanager12) is not bound to the component. |

### getGlyphPositionAtCoordinate<sup>12+</sup>

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

Obtains the position information of the character close to the given coordinate.

> **NOTE**
>
> - This API actually obtains the UTF-16 character offset, rather than the glyph offset.
>
> - After the text content changes, wait until the layout is complete before obtaining the latest position information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| x | number | Yes    | Horizontal coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md#basic-pixel-units) |
| y | number | Yes    | Vertical coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md#basic-pixel-units) |

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity12) | Character position information. Returns an invalid value when [LayoutManager](#layoutmanager12) is not bound to the component.|

### getCharacterPositionAtCoordinate<sup>24+</sup>

getCharacterPositionAtCoordinate(x: number, y: number): PositionWithAffinity | undefined

Obtains the position information of the character closest to the specified coordinate.

> **NOTE**
>
> - After the text content changes, wait until the layout is complete before obtaining the latest position information.
>
> - The character position returned by this API is the UTF-8 encoding offset.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name    | Type   | Mandatory   | Description                 |
| ------ | ------ | ---- | -------------------- |
| x | number | Yes    | Horizontal coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md#basic-pixel-units) |
| y | number | Yes    | Vertical coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md#basic-pixel-units) |

**Return value**

| Type                                          | Description        |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity12) \| undefined | Position information of the character. If [LayoutManager](#layoutmanager12) is not bound to the component, this API returns undefined.|

### getCharacterPositionAtCoordinate

getCharacterPositionAtCoordinate(x: number, y: number, encoding?: TextEncoding): PositionWithAffinity | undefined

Obtains the position information of the character closest to the specified coordinate based on the specified encoding type.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest position information.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| x | number | Yes | Horizontal coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md#basic-pixel-units) |
| y | number | Yes | Vertical coordinate relative to the component.<br>Unit: [px](ts-pixel-units.md#basic-pixel-units) |
| encoding | [TextEncoding](#textencoding) | No | Encoding type used for the character position. In UTF-8 encoding, the character position is in bytes; in UTF-16 encoding, the character position is in UTF-16 code units.<br>Default value: TextEncoding.TEXT_ENCODING_UTF8 |

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity12) \| undefined | Character position. Returns **undefined** when [LayoutManager](#layoutmanager12) is not bound to a component.|

### getGlyphRangeForCharacterRange<sup>24+</sup>

getGlyphRangeForCharacterRange(charRange: [TextRange](#textrange12)): Array&lt;[TextRange](#textrange12)&gt; | undefined

Obtains the glyph range and the actual character range based on the specified text character range. The character offset of this API is UTF-8 encoding.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest glyph range information.

Take the text "世界Hello" as an example. The correspondence between the glyph index and the character index under UTF-8 encoding is as follows:

| Text | 世 | 界 | H | e | l | l | o |
|---|---|---|---|---|---|---|---|
| Glyph index range | [0, 1] | [1, 2] | [2, 3] | [3, 4] | [4, 5] | [5, 6] | [6, 7] |
| Character index range (UTF-8) | [0, 3] | [3, 6] | [6, 7] | [7, 8] | [8, 9] | [9, 10] | [10, 11] |

The glyph index range of the character "世" is [0, 1]. Since a Chinese character occupies 3 bytes, its corresponding character index range is [0, 3]. If the specified character index range is [0, 1], it is impossible to parse one-third of a Chinese character, so the actual character index range is [0, 3].

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| charRange | [TextRange](#textrange12) | Yes   | Character range of the text.|

**Return value**

| Type                                          | Description        |
| --------------------------------------------- | ----------- |
|  Array&lt;[TextRange](#textrange12)&gt; \| undefined | The array contains two elements. The first element is the glyph range, and the second element is the actual character range.<br>If the returned range is an abnormal value, the elements in the range are -1.<br>If [LayoutManager](#layoutmanager12) is not bound to the component, this API returns undefined.|

### getGlyphRangeForCharacterRange

getGlyphRangeForCharacterRange(charRange: TextRange, encoding?: TextEncoding): Array&lt;TextRange&gt; | undefined

Obtains the glyph range and the actual character range based on the specified encoding type and text character range.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest glyph range information.

Take the text "世界Hello" as an example. The correspondence between the glyph index and the character index under different encoding types is as follows:

| Text | 世 | 界 | H | e | l | l | o |
|---|---|---|---|---|---|---|---|
| Glyph index range | [0, 1] | [1, 2] | [2, 3] | [3, 4] | [4, 5] | [5, 6] | [6, 7] |
| Character index range (UTF-8) | [0, 3] | [3, 6] | [6, 7] | [7, 8] | [8, 9] | [9, 10] | [10, 11] |
| Character index range (UTF-16) | [0, 1] | [1, 2] | [2, 3] | [3, 4] | [4, 5] | [5, 6] | [6, 7] |

Under UTF-8 encoding, a Chinese character occupies 3 bytes. The glyph index range of "世" is [0, 1], and its corresponding character index range is [0, 3]. If the specified character index range is [0, 1], it is impossible to parse one-third of a Chinese character, so the actual character index range is [0, 3].

Under UTF-16 encoding, the character index is measured in UTF-16 code units. A BMP character (such as "世") occupies 1 code unit (2 bytes), and a supplementary plane character (such as an emoji) occupies 2 code units (a 4-byte surrogate pair). The glyph index range of "世" is [0, 1], and its corresponding character index range is [0, 1].

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type   | Mandatory   | Description                 |
| ------ | ------ | ---- | -------------------- |
| charRange | [TextRange](#textrange12) | Yes    | Character range of the text.|
| encoding | [TextEncoding](#textencoding) | No | Encoding type used by the character range. Under UTF-8 encoding, the character index is measured in bytes; under UTF-16 encoding, the character index is measured in UTF-16 code units.<br>Default value: TextEncoding.TEXT_ENCODING_UTF8 |

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
|  Array&lt;[TextRange](#textrange12)&gt; \| undefined | The array contains two elements. The first element is the glyph range, and the second is the actual character range.<br>When the returned range is an abnormal value, the elements in the range are -1.<br>When [LayoutManager](#layoutmanager12) is not bound to a component, this API returns undefined.|

### getCharacterRangeForGlyphRange<sup>24+</sup>

getCharacterRangeForGlyphRange(glyphRange: [TextRange](#textrange12)): Array&lt;[TextRange](#textrange12)&gt; | undefined

Obtains the character range and the actual glyph range based on the specified text glyph range. The character offset of this API is UTF-8 encoding.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest character range information.

Take the text "世界Hello" as an example. The correspondence between the glyph index and the character index under UTF-8 encoding is as follows:

| Text | 世 | 界 | H | e | l | l | o |
|---|---|---|---|---|---|---|---|
| Glyph index range | [0, 1] | [1, 2] | [2, 3] | [3, 4] | [4, 5] | [5, 6] | [6, 7] |
| Character index range (UTF-8) | [0, 3] | [3, 6] | [6, 7] | [7, 8] | [8, 9] | [9, 10] | [10, 11] |

Its glyph index range is [0, 7]. Since a Chinese character occupies 3 bytes, its corresponding character index range is [0, 11]. If the specified glyph index range is [0, 11], but there are only 7 glyphs in total, the actual glyph index range is [0, 7].

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| glyphRange | [TextRange](#textrange12) | Yes   | Glyph range of the text.|

**Return value**

| Type                                          | Description        |
| --------------------------------------------- | ----------- |
| Array&lt;[TextRange](#textrange12)&gt; \| undefined | The array contains two elements. The first element is the character range, and the second element is the actual glyph range.<br>If the returned range is an abnormal value, the elements in the range are -1.<br>If [LayoutManager](#layoutmanager12) is not bound to the component, this API returns undefined.|

### getCharacterRangeForGlyphRange

getCharacterRangeForGlyphRange(glyphRange: TextRange, encoding?: TextEncoding): Array&lt;TextRange&gt; | undefined

Obtains the character range and the actual glyph range based on the specified encoding type and text glyph range.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest character range information.

Take the text "世界Hello" as an example. The correspondence between the glyph index and the character index under different encoding types is as follows:

| Text | 世 | 界 | H | e | l | l | o |
|---|---|---|---|---|---|---|---|
| Glyph index range | [0, 1] | [1, 2] | [2, 3] | [3, 4] | [4, 5] | [5, 6] | [6, 7] |
| Character index range (UTF-8) | [0, 3] | [3, 6] | [6, 7] | [7, 8] | [8, 9] | [9, 10] | [10, 11] |
| Character index range (UTF-16) | [0, 1] | [1, 2] | [2, 3] | [3, 4] | [4, 5] | [5, 6] | [6, 7] |

Under UTF-8 encoding, its glyph index range is [0, 7]. Since a Chinese character occupies 3 bytes, the corresponding character index range is [0, 11]. If the specified glyph index range exceeds the actual number of glyphs (for example, [0, 11]), since there are only 7 glyphs in total, the returned actual glyph index range is [0, 7].

Under UTF-16 encoding, the character index is measured in UTF-16 code units. A BMP character (such as "世") occupies 1 code unit (2 bytes), and a supplementary plane character (such as an emoji) occupies 2 code units (a 4-byte surrogate pair). Its glyph index range is [0, 7], and the corresponding character index range is [0, 7]. If the specified glyph index range exceeds the actual number of glyphs (for example, [0, 10]), since there are only 7 glyphs in total, the returned actual glyph index range is [0, 7].

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type   | Mandatory   | Description                 |
| ------ | ------ | ---- | -------------------- |
| glyphRange | [TextRange](#textrange12) | Yes    | Glyph range of the text.|
| encoding | [TextEncoding](#textencoding) | No | Encoding type used by the character range. Under UTF-8 encoding, the character index is measured in bytes; under UTF-16 encoding, the character index is measured in UTF-16 code units.<br>Default value: TextEncoding.TEXT_ENCODING_UTF8 |

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
| Array&lt;[TextRange](#textrange12)&gt; \| undefined | The array contains two elements. The first element is the character range, and the second element is the actual glyph range.<br>When the returned range is an abnormal value, the elements in the range are -1.<br>When [LayoutManager](#layoutmanager12) is not bound to the component, this API returns undefined.|

### getLineMetrics<sup>12+</sup>

getLineMetrics(lineNumber: number): LineMetrics

Obtains the information about the specified line, including line metrics, text style information, and font properties.

> **NOTE**
>
> After the text content changes, wait until the layout is complete before obtaining the latest line information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description                |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | Yes    | Line number, with a value range of [0, actual line count - 1], starting from 0. When the line number is less than 0 or exceeds the actual line count, an invalid value is returned. |

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| [LineMetrics](#linemetrics12) | Line information, text style information, and font attribute information.<br>When the line number is less than 0 or exceeds the actual line, returns invalid. When [LayoutManager](#layoutmanager12) is not bound to the component, returns invalid. |

### getRectsForRange<sup>14+</sup>

getRectsForRange(range: TextRange, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox\>

Obtains the drawing area information of the characters or placeholders within any range of the text, based on the specified rectangle width and height styles.

> **NOTE**
>
> - After the text content changes, wait until the layout is complete before obtaining the latest drawing area information.
>
> - The [TextRange](#textrange12) of the **range** parameter is a UTF-16 character offset.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                | Mandatory| Description                    |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [TextRange](#textrange12)| Yes  | Text range of the area to be obtained. |
| widthStyle  | [RectWidthStyle](#rectwidthstyle14)   | Yes   | Width specification of the returned rectangular area, used to control how the width of the returned rectangle is calculated. Different specification values affect the width boundary of the rectangle. |
| heightStyle | [RectHeightStyle](#rectheightstyle14) | Yes   | Height specification of the returned rectangular area, used to control how the height of the returned rectangle is calculated. Different specification values affect the height boundary of the rectangle. |

**Return value**

| Type                        | Description       |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox14)\> | Array of rectangular areas. If [LayoutManager](#layoutmanager12) is not bound to the component, an empty array is returned. |

## PositionWithAffinity<sup>12+</sup>

Describes the position and affinity of a glyph.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                  | Read-Only| Optional| Description                     |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | No  | No  | Index of the glyph or character to the component. The value is an integer. |
| affinity  | [Affinity](#affinity12) | No   | No   | Position affinity, which indicates the tendency of the cursor position at glyph boundaries. For details, see the Affinity enum. |

## TextMenuItemId<sup>12+</sup>

Defines the unique identifier for a custom menu item. It is used to identify menu items. The IDs for built-in menu items are listed in the table below.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type              | Read-Only   | Optional  | Description     |
| ------------ |---------------------| ---- | ---- | ------ |
| CUT  | [TextMenuItemId](#textmenuitemid12) |  Yes  |  No | Default cut, a level-1 menu item.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| COPY  | [TextMenuItemId](#textmenuitemid12) |  Yes  |  No  | Default copy, a level-1 menu item.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| PASTE | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Default paste, a level-1 menu item.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| SELECT_ALL   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Default select all, a level-1 menu item.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| COLLABORATION_SERVICE   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Collaboration service, a level-1 menu item.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| CAMERA_INPUT   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No   | Camera input, a level-1 menu item.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| AI_WRITER<sup>13+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | <!--RP1--><!--RP1End-->Can polish, summarize, and format the selected text. It is a level-1 menu item. This menu item depends on the large model capability; otherwise, it does not take effect.<br>**Atomic service API:** This API can be used in atomic services since API version 13. |
| TRANSLATE<sup>15+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Translate, a level-1 menu item. Provides a translation service for the selected text.<br>**Atomic service API:** This API can be used in atomic services since API version 15. |
| SHARE<sup>18+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Share, a level-1 menu item. Provides a sharing service for the selected text and opens the sharing window to share the selected text content.<br>**Atomic service API:** This API can be used in atomic services since API version 18. |
| SEARCH<sup>18+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Search, a level-1 menu item. Provides a search service for the selected text and opens the browser to search for the selected text content.<br>**Atomic service API:** This API can be used in atomic services since API version 18. |
| url<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Open link, a level-1 menu item. Provides a jump service for the selected URL and opens the browser search or an app page.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |
| email<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | New email, a level-1 menu item. Provides a jump service for the selected email address and opens the email app.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |
| phoneNumber<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Call, a level-1 menu item. Provides a jump service for the selected phone number and opens the dialing page.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |
| address<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Navigate, a level-1 menu item. Provides a jump service for the selected address and opens the map app.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |
| dateTime<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | New schedule, a level-1 menu item. Provides a jump service for the selected date and time and opens the new schedule page.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |
| askAI<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | <!--RP2--><!--RP2End-->Provides AI query capability for the selected text. It is a level-1 menu item. This menu item depends on the large model capability; otherwise, it does not take effect.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |
| autoFill<sup>23+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Auto fill, a level-1 menu item. After it is tapped, the level-2 menu item "Password Vault" is expanded. It is supported only by [Search](ts-basic-components-search.md), [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md), or [RichEditor](ts-basic-components-richeditor.md).<br>**Atomic service API:** This API can be used in atomic services since API version 23. |
| passwordVault<sup>23+</sup>   | [TextMenuItemId](#textmenuitemid12)   | Yes    | No    | Password Vault, a level-2 menu item. After this menu item is tapped, the Password Vault app is opened. This app provides the capability of auto-filling account names and passwords. It is supported only by [Search](ts-basic-components-search.md), [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md), or [RichEditor](ts-basic-components-richeditor.md).<br>**Atomic service API:** This API can be used in atomic services since API version 23.<br>**Model restriction:** This API can be used only in the stage model. |

### of

static of(id: ResourceStr): TextMenuItemId

Creates a **TextMenuItemId** object based on **id**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [ResourceStr](ts-types.md#resourcestr) | Yes | Identifier of the menu item, used to create a TextMenuItemId object to identify the menu option. |

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| [TextMenuItemId](#textmenuitemid12) | Identifier object of a menu item created based on the passed-in ID, used to identify the menu option. |

### equals

equals(id: TextMenuItemId): boolean

Checks whether this **TextMenuItemId** object is the same as another **TextMenuItemId** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [TextMenuItemId](#textmenuitemid12) | Yes | TextMenuItemId object to be compared. |

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| boolean | Whether two TextMenuItemId values are equal.<br>The value **true** indicates that they are equal, and **false** indicates that they are not equal. |

## TextMenuItem<sup>12+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type                             | Read-Only| Optional| Description  |
| ------- | --------------------------------- | ---- | ---- | --------------------------------- |
| content | [ResourceStr](ts-types.md#resourcestr) | No | No | Menu name.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| icon | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Menu icon.<br>Network images are not supported.<br>Default value: **undefined**, which means no menu icon is displayed.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| id | [TextMenuItemId](#textmenuitemid12) | No | No | Menu ID.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| labelInfo<sup>15+</sup> | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Shortcut key hint.<br>This field is supported only on 2-in-1 devices.<br>Default value: **undefined**, which means no shortcut key hint is displayed.<br>**Atomic service API:** This API can be used in atomic services since API version 15. |

## EditMenuOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type  | Read-Only| Optional  | Description |
| ------- | ------ | ---- | ----- | ----- |
| onPrepareMenu<sup>20+</sup> | [OnPrepareMenuCallback](#onpreparemenucallback20) | No | Yes | Triggered before the menu is displayed after the text selection area changes. You can set menu data in this callback.<br>Similar to [onCreateMenu](#oncreatemenu12) but with a different trigger timing: onCreateMenu is triggered when the menu is created and is suitable for initializing menu items; this API is triggered after each selection area change and before the menu is displayed, and is suitable for dynamically adjusting the menu based on the selected content. The two can be used together.<br>**Atomic service API:** This API can be used in atomic services since API version 20.|

### onCreateMenu<sup>12+</sup>

onCreateMenu(menuItems: Array\<TextMenuItem\>): Array\<TextMenuItem\>

Triggered when the menu is being created. Menu data can be configured within this callback. Both the input parameter and return value contain only level-1 menu items; level-2 menu items are not included.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem12)> | Yes   |  Menu items to be displayed.<br>**NOTE**<br>Modifications to the names, icons, and shortcut key hints of the default menu items do not take effect. |

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12)\> | Processed menu items.|

### onMenuItemClick<sup>12+</sup>

onMenuItemClick(menuItem: TextMenuItem, range: TextRange): boolean

Triggered when a menu item is tapped, used to handle the tap behavior of the menu item.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItem | [TextMenuItem](#textmenuitem12) | Yes   | Menu item.<br>**NOTE**<br>Since API version 23, for a first-level menu item that supports an expandable secondary menu, such as autofill, only the system default logic is executed, and user-defined logic is not executed. |
| range | [TextRange](#textrange12) | Yes  | Selected text.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| boolean | Execution logic of the menu item.<br>The value **true** indicates that the system default logic is intercepted and only the custom logic is executed.<br>The value **false** indicates that the custom logic is executed first, followed by the system logic. |

## OnPrepareMenuCallback<sup>20+</sup>

type OnPrepareMenuCallback = (menuItems: Array\<TextMenuItem\>) => Array\<TextMenuItem\>

Triggered before the menu is displayed after the text selection area changes. Menu data can be configured within this callback. Both the input parameter and return value contain only level-1 menu items; level-2 menu items are not included.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                             | Mandatory| Description  |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem12)> | Yes   | Menu items to be displayed.<br>**NOTE**<br>Modifications to the names, icons, and shortcut key hints of the default menu items do not take effect. |

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12)> | Menu items after the processing.|

## TextRange<sup>12+</sup>

Defines the text range.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read-Only| Optional| Description|
| -- | -- | -- | -- | -- |
| start | number | No | Yes | Start index, starting from 0. |
| end | number | No | Yes | End index, starting from 0. |

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
| options<sup>15+</sup> | [TextChangeOptions](#textchangeoptions15) | No| Information about the text change, including the selection range, text displayed in the text box, and preview text.|

## TextDataDetectorType<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value  | Description                              |
| ----- | ----- | --------------------------------- |
| PHONE_NUMBER  | 0 | Phone number.|
| URL | 1 | URL.|
| EMAIL | 2 | Email address.|
| ADDRESS | 3 | Address.|
| DATE_TIME<sup>12+</sup> | 4 | Date and time. |

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
| IMMERSIVE | 1 | Immersive mode, following the system.|
| LIGHT_IMMERSIVE | 2 | Immersive style in light mode.|
| DARK_IMMERSIVE | 3 | Immersive style in dark mode.|

## IncrementalUpdatePolicy

Incremental update policy for text rendering.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Value | Description |
| ------- | ---- | ------------------- |
| NONE | 0 | Incremental update is disabled, and full layout rendering is used. |
| PARAGRAPH_CACHE | 1 | Incremental update is enabled, and paragraph-level cache is used. This policy takes effect only when the attributed string object bound to the text remains unchanged. If the attributed string object changes, the cache cannot be hit. |

## InsertValue<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                         | Read-Only| Optional| Description                                                        |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| insertOffset  | number | No   | No | Position index of the inserted value, starting from 0. |
| insertValue  | string | No  | No  | Content of the inserted text.|

## DeleteValue<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| deleteOffset  | number | No   | No | Position index of the deleted value, starting from 0. |
| direction  | [TextDeleteDirection](#textdeletedirection12) | No  | No  | Direction for deleting the text.|
| deleteValue  | string | No  | No  | Content of the deleted text.|

## TextDataDetectorConfig<sup>11+</sup>

This configuration is only available for the [Text](ts-basic-components-text.md) and [RichEditor](ts-basic-components-richeditor.md) components.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type | Read-Only| Optional| Description |
| ------ | -------- | ---- | ---- | ------------------------------------------- |
| types   | [TextDataDetectorType](#textdatadetectortype11)[] | No | No  | Sets the entity types for text recognition. If **types** is set to null or [], all entity types are recognized; otherwise, only the specified entity types are recognized.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| onDetectResultUpdate   | Callback\<string\> | No | Yes  | Callback invoked when text recognition succeeds.<br>Default value: **undefined**, which means the callback is not triggered.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| color<sup>12+</sup>   | [ResourceColor](ts-types.md#resourcecolor) | No | Yes   | Sets the entity color after text recognition succeeds.<br>Default value: **'#ff0a59f7'**, which indicates blue (with 100% opacity).<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| decoration<sup>12+</sup>  | [DecorationStyleInterface](ts-universal-styled-string.md#decorationstyleinterface)| No | Yes   | Sets the decoration line style of entities after text recognition succeeds.<br>Default value:<br>{<br>&nbsp;type:&nbsp;TextDecorationType.Underline,<br>&nbsp;color:&nbsp;same as the entity color,<br>&nbsp;style:&nbsp;TextDecorationStyle.SOLID&nbsp;<br>}<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| enablePreviewMenu<sup>20+</sup>   | boolean | No | Yes   | Sets whether to enable the preview menu displayed on long press after text recognition. The value **true** indicates enabled, and **false** indicates disabled.<br>Default value: **false**<br>When [copyOptions](ts-basic-components-richeditor.md#copyoptions) is set to **None**, the preview menu is not displayed on long press of an AI entity even if **enablePreviewMenu** is set to **true**.<br>**Device behavior differences:** The actual device types supported by this API (phones and tablets) are fewer than those supported by its system capability (phones, 2-in-1 devices, tablets, TVs, cars, and wearables). Due to hardware form limitations, this API does not respond on 2-in-1 devices, TVs, cars, and wearables.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |

## PreviewText<sup>12+</sup>

Preview text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Read-Only| Optional| Description                                                    |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| offset | number | No | No | Start position index of the preview text, starting from 0. |
| value    | string         | No  | No  | Content of the preview text.        |

## FontSettingOptions<sup>12+</sup>

Defines font setting options.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Read-Only| Optional| Description                                                    |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| enableVariableFontWeight | boolean | No | Yes | Whether to enable variable font weight adjustment. This font configuration item is used as an input parameter of the [fontWeight](./ts-basic-components-text.md#fontweight12) API. When the value of **weight** in the **fontWeight** API is a non-multiple-of-100 value within [100, 900], **enableVariableFontWeight** determines whether the value of **weight** takes effect.<br>Default value: **false**<br>**true**: Variable font weight adjustment is enabled. In this case, if the value of **weight** is any integer within [100, 900], the font weight is the value of **weight**; otherwise, the default value **400** is used.<br>**false**: Variable font weight adjustment is disabled. In this case, if the value of **weight** is a multiple of 100 within [100, 900], the font weight is the value of **weight**; if **weight** is a non-multiple-of-100 value, the default value **400** is used.|

## FontConfigs<sup>24+</sup>

Defines font configurations.

**Atomic service API**: This API can be used in atomic services since API version 24.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Read-Only| Optional| Description                                                    |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| fontWeightConfigs | [FontWeightConfigs](#fontweightconfigs24) | No | Yes | Font weight configuration. The default value inherits from [FontWeightConfigs](#fontweightconfigs24).<br>**Model restriction:** This API can be used only in the stage model. |

## FontWeightConfigs<sup>24+</sup>

Defines font weight configurations. When the configuration object (including an empty object **{}**) is passed, the default values are used for properties that are not explicitly set. When **null** or **undefined** is passed, default values are not applied, and the font weight behavior is consistent with that of the parent component text.

**Atomic service API**: This API can be used in atomic services since API version 24.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                                            | Read-Only| Optional| Description                                                    |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| enableVariableFontWeight | boolean | No | Yes | Whether to enable variable font weight adjustment. When the font weight value **weight** is set to a non-hundred value within [100, 900], **enableVariableFontWeight** determines whether the **weight** value takes effect.<br>Default value: **false**<br>**true**: Variable font weight adjustment is enabled. In this case, if **weight** is any integer within [100, 900], the font weight is **weight**; otherwise, the default value 400 is used.<br>**false**: Variable font weight adjustment is disabled. In this case, if **weight** is a hundred value within [100, 900], the font weight is **weight**; if **weight** is a non-hundred value, the default value 400 is used.|
| enableDeviceFontWeightCategory | boolean | No | Yes | Whether to automatically update the font weight based on the device font weight level.<br>Default value: **true**<br>**true**: When the device font weight level changes, the font weight is automatically updated.<br>**false**: When the device font weight level changes, the font weight is not automatically updated. |

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

| Name| Type| Read-Only| Optional| Description|
| -- | -- | -- | -- | -- |
| onWillChange | Callback<[StyledStringChangeValue](#styledstringchangevalue12), boolean> | No | Yes | Callback invoked when the text content is about to change.<br>Default value: null, which means no callback is triggered.<br>The value **true** indicates that the text content change is allowed, and **false** indicates that the change is blocked. |
| onDidChange | [OnDidChangeCallback](#ondidchangecallback12) | No | Yes | Callback invoked when the text content change is complete.<br>Default value: null, which means no callback is triggered. |

## StyledStringChangeValue<sup>12+</sup>

Describes the text changes of the styled string.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read-Only| Optional| Description|
| -- | -- | -- | -- | -- |
| range | [TextRange](#textrange12) | No| No| Range of the styled string to be replaced in the original string.|
| replacementString | [StyledString](ts-universal-styled-string.md#styledstring) | No| No| Styled string used for replacement.|
| previewText | [StyledString](ts-universal-styled-string.md#styledstring) | No | Yes | Preview content attribute string.<br>Default value: **null**, indicating no preview content.<br>This attribute is used to represent the temporary input content that has not been committed to the screen in voice input, camera input, and input method preview text scenarios.|

## AutoCapitalizationMode<sup>20+</sup>

Automatic capitalization mode type. It only provides the API capability, and the specific implementation is determined by the input method app.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ------- | ---- | ------------------- |
| NONE | 0 | Default state. No automatic capitalization is performed. |
| WORDS | 1 | Automatic capitalization is applied per word: The first character of each word is capitalized, others are lowercase.|
| SENTENCES | 2 | Automatic capitalization is applied per sentence: The first character of each sentence is capitalized, others are lowercase.|
| ALL_CHARACTERS | 3 | Automatic capitalization applied to all characters.|

## TextBaseController<sup>12+</sup>

Defines a text selection controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### setSelection<sup>12+</sup>

setSelection(selectionStart:&nbsp;number, selectionEnd:&nbsp;number, options?:&nbsp;SelectionOptions): void

Sets the range of content selection. The selected content is highlighted.

If both **selectionStart** and **selectionEnd** are set to **-1**, the entire content is selected.

The component must be focused for the API call to have effect.

Since API version 12, on PC/2-in-1 devices, calling the setSelection API does not pop up a menu regardless of the value of **options**. In addition, if a menu already exists in the component, calling the setSelection API closes the menu.

On non-2-in-1 devices, when **options** is set to **MenuPolicy.DEFAULT**, the following rules apply after the API is called:

1. If the component has a menu with a selection handle, the menu remains open and is relocated according to the selection.

2. If the component has a menu without a selection handle, the menu remains open and its position remains unchanged.

3. If there is no menu open, no menu will appear after the selection.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name           | Type  | Mandatory  | Description   |
| -------------- | ------ | ---- | ------- |
| selectionStart | number | Yes    | Start position of the selection.<br>If the value is less than 0, it is processed as 0. If the value is greater than the text length, it is processed as the current text length.<br>Special value effect: when both selectionStart and selectionEnd are -1, all text is selected. |
| selectionEnd   | number | Yes    | End position of the selection.<br>If the value is less than 0, it is processed as 0. If the value is greater than the text length, it is processed as the current text length.<br>Special value effect: when both selectionStart and selectionEnd are -1, all text is selected. |
| options   | [SelectionOptions](ts-universal-attributes-text-style.md#selectionoptions12) | No   | Configuration of options. The default value is inherited from [SelectionOptions](ts-universal-attributes-text-style.md#selectionoptions12).|

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
| [LayoutManager](#layoutmanager12) | Layout manager object, used to obtain text layout information, such as the number of lines, line metrics, glyph positions, and so on. |

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

Sets the offset of the caret.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory  | Description               |
| ------ | ------ | ---- | -------------------- |
| offset | number | Yes | Cursor offset position. The value range is [0, text length]. If the value exceeds the content range, the setting fails. |

**Return value**

| Type     | Description       |
| ------- | --------- |
| boolean | Whether the cursor is set successfully.<br>The value **true** indicates that the cursor is set successfully, and **false** indicates the opposite. |

### getPreviewText<sup>12+</sup>

getPreviewText?(): PreviewText

Obtains the preview text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [PreviewText](#previewtext12) | Preview text information, including the start position index and text content of the preview text. |

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
| styledString | [StyledString](ts-universal-styled-string.md#styledstring) | Yes    | Styled string.<br>**NOTE**<br>A subclass of StyledString, [MutableStyledString](ts-universal-styled-string.md#mutablestyledstring), can also be used as the input parameter value. |

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

| Name | Type                             | Read-Only| Optional| Description  |
| ------- | --------------------------------- | ---- | ---- | --------------------------------- |
| type | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | No | No | Type of the decoration line.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| color | [ResourceColor](ts-types.md#resourcecolor) | No | No | Color of the decoration line.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| style | [TextDecorationStyle](ts-appendix-enums.md#textdecorationstyle12) | No | Yes | Style of the decoration line.<br>Default value: TextDecorationStyle.SOLID<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| thicknessScale<sup>20+</sup> | number | No | Yes | Scale ratio of the decoration line thickness.<br>Default value: 1.0<br>Value range: [0, +∞) <br>**Note:** A negative value is processed as the default value.<br> **Atomic service API:** This API can be used in atomic services since API version 20. |

## LineMetrics<sup>12+</sup>

type LineMetrics = import('../api/@ohos.graphics.text').default.LineMetrics

Describes the measurement information of a single line in the text layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | Describes the metrics of a single line of text in the text layout. |

## Affinity<sup>12+</sup>

type Affinity = import('../api/@ohos.graphics.text').default.Affinity

Enumerates the affinity modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | Position affinity enum. |

## TextBox<sup>14+</sup>

type TextBox = import('../api/@ohos.graphics.text').default.TextBox

Describes the rectangle that contains the text.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[TextBox](../../apis-arkgraphics2d/js-apis-graphics-text.md#textbox) | Text box area. |

## Paragraph<sup>20+</sup>

type Paragraph = import('../api/@ohos.graphics.text').default.Paragraph

Implements a carrier that stores the text content and style. It supports operations such as layout and drawing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[Paragraph](../../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph) | Carrier that stores text content and styles, and supports layout and drawing operations. |

## RectHeightStyle<sup>14+</sup>

type RectHeightStyle = import('../api/@ohos.graphics.text').default.RectHeightStyle

Enumerates the rectangle height styles.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[RectHeightStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectheightstyle) | Enumerates the height specifications of a rectangular area. |

## RectWidthStyle<sup>14+</sup>

type RectWidthStyle = import('../api/@ohos.graphics.text').default.RectWidthStyle

Enumerates the rectangle width styles.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[RectWidthStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectwidthstyle) | Enumerates the width specifications of a rectangular area. |

## TextEncoding

Text encoding types supported by the text layout query APIs.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Value | Description |
| ------- | ---- | ------------------- |
| TEXT_ENCODING_UTF8 | 0 | UTF-8 encoding. |
| TEXT_ENCODING_UTF16 | 1 | UTF-16 encoding. |

## TextChangeOptions<sup>15+</sup>

Text change information, including the selection range before and after the change and the text content before the change.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| rangeBefore  | [TextRange](#textrange12) | No  | No| Selection range before the change.|
| rangeAfter  | [TextRange](#textrange12) | No  | No  | Selection range after the change.|
| oldContent  | string | No  | No  | Text content before the change.|
| oldPreviewText | [PreviewText](#previewtext12) | No  | No| Preview text before the change.|

## EditableTextChangeValue<sup>15+</sup>

Provides detailed information of text changes, including preview text.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| content  | string | No  | No| Current text content.|
| previewText  | [PreviewText](#previewtext12) | No   | Yes   | Preview text content.<br>Default value: **undefined**, which means there is no preview text content. |
| options  | [TextChangeOptions](#textchangeoptions15) | No   | Yes   | Changed text content information.<br>Default value: **undefined**. |

## TextMenuShowMode<sup>16+</sup>

Enumerates the text menu display modes.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ------- | ---- | ------------------- |
| DEFAULT | 0 | Displayed in the current window.<br>|
| PREFER_WINDOW | 1 | Preferentially displayed in a separate window. If a separate window is not supported, it is displayed in the current window.<br>**NOTE**<br>Except for app main windows, app subwindows, system modal windows, and system desktop windows, other types of windows do not support displaying the text selection menu in a separate window.<br>The previewer does not support displaying the text selection menu in a separate window.<br>[UIExtension](../js-apis-arkui-uiExtension.md) does not support displaying the text selection menu in a separate window.<br>When a text component is already displayed in a subwindow-type [Popup](./ohos-arkui-advanced-Popup.md), [Dialog](./ohos-arkui-advanced-Dialog.md), [Toast](../../../ui/arkts-create-toast.md), or [Menu](./ts-basic-components-menu.md), the corresponding text selection menu cannot be displayed in a separate window.<br>When TextInput and TextArea support triggering AutoFill, the corresponding text selection menu cannot be displayed in a separate window.<br>|

## TextMenuOptions<sup>16+</sup>

Provides the options for customizing the context menu on selection.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| showMode  | [TextMenuShowMode](#textmenushowmode16) | No   | Yes | Display mode of the menu.<br>Default value: TextMenuShowMode.DEFAULT |

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

| Name | Type  | Read-Only| Optional  | Description |
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
| options | [LinearGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#lineargradientoptions18) | Yes | Displays a linear gradient effect.<br>The default value of direction in [LinearGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#lineargradientoptions18) is processed as NONE in [GradientDirection](ts-appendix-enums.md#gradientdirection). |

## RadialGradientStyle<sup>20+</sup>

Displays a radial gradient. **RadialGradientStyle** inherits from [ShaderStyle](#shaderstyle20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
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

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
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

### Properties

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Read-Only| Optional| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| nodeId  | number | No | No| Unique ID of the current input component. The value must be greater than or equal to 0.|

### setExtraConfig<sup>22+</sup>

setExtraConfig(config: InputMethodExtraConfig): void

Sets the extension configuration of an input method.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| config  | [InputMethodExtraConfig](#inputmethodextraconfig22) | Yes  | Extension configuration of an input method.|

## MaxLinesOptions<sup>20+</sup>

Configures the display effect of the **TextArea** component when the text exceeds the maximum number of lines.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Type   | Read-Only| Optional | Description                                                        |
| ------------------- | ------- | ------- | ------- | ------------------------------------------------------------ |
| overflowMode | [MaxLinesMode](#maxlinesmode20)  | No  | Yes | `overflowMode` configures the non-inline mode of the [TextArea](./ts-basic-components-textarea.md) component. When the number of lines exceeds the configured `maxLines`, scrolling is enabled. It must be used together with [textOverflow](ts-basic-components-textarea.md#textoverflow12), and `MaxLinesMode` takes effect only when `textOverflow` is set to None or Clip. By default, the value of `MaxLinesMode` is Clip, and text is truncated when the number of lines exceeds `maxLines`. |

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

| Name| Type                                                        | Read-Only| Optional| Description            |
| ------ | ------------------------------------------------------------ | ---- | ---- | ---------------- |
| onlyBetweenLines  | boolean | No   | Yes | Whether the line spacing of the text takes effect only between lines.<br>When set to true, the line spacing applies only between lines, with no extra line spacing above the first line or below the last line. When set to false, line spacing exists both above the first line and below the last line.<br>Default value: false |

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

| Name                                      | Type                                                        | Read-Only| Optional| Description                                                        |
| ------------------------------------------ | ---------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| flipDirection                             | [FlipDirection](#flipdirection20)    | No  | Yes| Direction of the flip animation.<br>Default value: **FlipDirection.DOWN**|
| enableBlur                                 | boolean                              | No  | Yes| Whether to enable the blur effect for the flip animation.<br>Default value: **false**<br>**true**: Enable the blur effect.<br>**false**: Disable the blur effect.|

### constructor<sup>20+</sup>

constructor(options?: NumericTextTransitionOptions)

A constructor used to create a **NumericTextTransition** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory  | Description |
| ------- | ------ | ---- | ----- |
| options | [NumericTextTransitionOptions](#numerictexttransitionoptions20) | No   | Options of the numeric flip animation. The default value is inherited from [NumericTextTransitionOptions](#numerictexttransitionoptions20).|

## NumericTextTransitionOptions<sup>20+</sup>

Defines the options of the numeric flip animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                                      | Type                                                        | Read-Only| Optional| Description                                                        |
| ------------------------------------------ | ---------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| flipDirection                              | [FlipDirection](#flipdirection20)    | No  | Yes| Direction of the flip animation.<br>Default value: **FlipDirection.DOWN**|
| enableBlur                                 | boolean                              | No  | Yes| Whether to enable the blur effect for the flip animation.<br>Default value: **false**<br>**true**: Enable the blur effect.<br>**false**: Disable the blur effect.|

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

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| constraintWidth | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)  | No| Yes| Layout width of the measured text. If not set, the width is the maximum width occupied by a single-line layout.|

## SelectedDragPreviewStyle<sup>23+</sup>

Defines the drag preview style for selected text.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor)  | No | Yes | Used to set the background color of the text during dragging.<br>Default value: follows the theme. With the default theme, white is displayed in light mode and black in dark mode. |

## TextContentAlign<sup>21+</sup>

Enumerates the vertical alignment directions of the text content area.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Value | Description                 |
| --------------------- | -------  | ------------------- |
| TOP                   | 0  | Aligns the content area to the top.|
| CENTER                | 1  | Aligns the content area to the center.|
| BOTTOM                | 2  | Aligns the content area to the bottom.|

## StrokeJoinStyle

Defines the style of line corners, that is, the brush style at the corners of line segments when drawing polylines.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name                   | Value  | Description                  |
| --------------------- | -------  | ------------------- |
| MITER_JOIN            | 0  | The corner type is a sharp angle. |
| ROUND_JOIN            | 1  | The corner type is a round angle. |
| BEVEL_JOIN            | 2  | The corner type is a flat angle. |

## TextDirection<sup>22+</sup>

Enumerates the text layout directions.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Value | Description                 |
| --------------------- | -------  | ------------------- |
| LTR                   | 0  | Text layout direction is from left to right.<br>**Atomic service API:** This API can be used in atomic services since API version 22. |
| RTL                   | 1  | Text layout direction is from right to left.<br>**Atomic service API:** This API can be used in atomic services since API version 22. |
| DEFAULT<sup>23+</sup> | 2  | The text layout direction follows the component layout direction.<br>**Atomic service API:** This API can be used in atomic services since API version 23. |
| AUTO<sup>23+</sup>    | 3  | The layout direction follows the actual text content. If the text is in an RTL (Right-to-Left) language (such as Tibetan or Uyghur), the text layout direction is from right to left. If the text is in an LTR (Left-to-Right) language (such as Chinese or English), the text layout direction is from left to right.<br>**Atomic service API:** This API can be used in atomic services since API version 23. |

## InputMethodExtraConfig<sup>22+</sup>

type InputMethodExtraConfig = import('../api/@ohos.inputMethod.ExtraConfig').InputMethodExtraConfig

Represents the extension configuration of an input method.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                             | Description  |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.inputMethod.ExtraConfig').[InputMethodExtraConfig](../../apis-ime-kit/js-apis-inputmethod-extraconfig.md#inputmethodextraconfig) | Extended information of the input method. |

## AccessibilitySpanOptions<sup>23+</sup>

Defines accessibility options for the span.

**Atomic service API**: This API can be used in atomic services since API version 23.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences**: On wearables, calling this API results in a runtime exception indicating that the API is undefined. On other devices, the API works correctly.

| Name| Type| Read-Only| Optional| Description|
| ------ | ---------- | ---- | ------------------ | ------------------ |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No| Yes| Accessibility text, that is, accessible label name. If a component has no text property, it will not be announced when selected by a screen reader. Setting this property allows you to define accessibility text for such components, which will be announced by a screen reader to help users identify the selected component.<br>Default value: **''**<br>If the value is **undefined**, the default value is used.|
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No| Yes| Accessibility description. This description provides users with a detailed explanation of the current component to help users understand the intended operation and its consequences, especially when these consequences cannot be directly obtained from the component's attributes and accessibility text alone.<br>Default value: **''**<br>If the value is **undefined**, the default value is used.|
| accessibilityLevel | string | No | Yes | Accessibility importance. Used to set whether the component can be recognized by the accessibility service.<br>The following values are supported:<br>"auto": The accessibility service and ArkUI comprehensively determine whether the component can be recognized by the accessibility service.<br>"yes": The component can be recognized by the accessibility service.<br>"no": The component cannot be recognized by the accessibility service.<br>"no-hide-descendants": The component and all its child components cannot be recognized by the accessibility service.<br>Default value: "auto"<br>If the value is undefined, the default value is used.<br>**NOTE**<br>When accessibilityLevel is set to "auto", whether the component can be recognized by the accessibility service depends on the following factors:<br>1. Whether the component can be recognized is determined internally by the accessibility service, which makes its own choice.<br>2. If isGroup in the accessibilityGroup attribute of the parent component is set to true, the accessibility service no longer focuses on the content of its child components, and the component cannot be recognized by the accessibility service.<br>3. If the accessibilityLevel attribute of the parent component is set to "no-hide-descendants", the component cannot be recognized by the accessibility service. |

## FontVariation

type FontVariation = import('../api/@ohos.graphics.text').default.FontVariation

Properties of a variable font.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Type                              | Description   |
| --------------------------------- | --------------------------------- |
| import('../api/@ohos.graphics.text').default.[FontVariation](../../apis-arkgraphics2d/js-apis-graphics-text.md#fontvariation) | Properties of a variable font. |

## OnCreateMenuCallback

type OnCreateMenuCallback = (menuItems: Array\<TextMenuItem\>) => Array\<TextMenuItem\>

Triggered when the menu is created.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                              | Mandatory | Description   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem12)> | Yes   | Menu items currently displayed.<br/>**Note:** <br/>Modifications to the name, icon, and shortcut key prompt of the default menu items do not take effect. |

**Return value**

| Type              |       Description       |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12)> | Menu items after processing.|
<!--no_check-->