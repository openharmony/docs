# Common Text Component APIs

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

### Objects to Import
The following uses the **\<Text>** component as an example.
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
| content | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Menu name.|
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
| menuItems | Array<[TextMenuItem](#textmenuitem)> | Yes  | Menu items.|

**Return value**

| Type             |       Description      |
| ------- | --------------------------------- | 
| Array\<[TextMenuItem](#textmenuitem)> | Menu items set.|

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
