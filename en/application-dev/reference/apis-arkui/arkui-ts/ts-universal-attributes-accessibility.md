# Accessibility

You can set accessibility attributes and events for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## accessibilityGroup

accessibilityGroup(value: boolean)

Sets whether to enable accessibility grouping. When accessibility grouping is enabled, the component and all its children are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components.

If accessibility grouping is enabled and the component does not contain a universal text attribute or an [accessibility text](#accessibilitytext) attribute, the system will concatenate the universal text attributes of its child components to form a merged text for the component. If a child component lacks a universal text attribute, it will be ignored in the concatenation process. The merged text will not use the accessibility text of the child components.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to enable accessibility grouping. When accessibility grouping is enabled, the component and all its children are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components.<br>Default value: **false**|

## accessibilityGroup<sup>14+</sup>

accessibilityGroup(isGroup: boolean, accessibilityOptions: AccessibilityOptions)

Sets whether to enable accessibility grouping, with support for prioritizing the concatenation of accessibility text for accessibility announcement. When accessibility grouping is enabled, the component and all its children are treated as a single selectable entity, and the accessibility service will no longer focus on the individual child components.

If accessibility grouping is enabled and the component does not contain a universal text attribute or an [accessibility text](#accessibilitytext) attribute, the system will concatenate the universal text attributes of its child components to form a merged text for the component. If a child component lacks a universal text attribute, it will be ignored in the concatenation process.

When **accessibilityPreferred** is set to **true**, the system will prioritize concatenating the accessibility text attributes of the child components to form the merged text. If a child component lacks an accessibility text attribute, the system will continue to concatenate its universal text attribute. If a child component lacks both, it will be ignored.

**Widget capability**: This API can be used in ArkTS widgets since API version 14.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name              | Type                                                   | Mandatory| Description                                                        |
| -------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| isGroup              | boolean                                                 | Yes  | Whether to enable accessibility grouping. When accessibility grouping is enabled, the component and all its children are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components.<br>Default value: **false**|
| accessibilityOptions | [AccessibilityOptions](#accessibilityoptions14) | Yes  | Options for accessibility grouping. When **accessibilityPreferred** is set to **true**, the system will prioritize concatenating the accessibility text attributes of the child components to form the merged text.<br>Default value: **false**           |

## AccessibilityOptions<sup>14+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Type   | Mandatory| Description                                                        |
| ---------------------- | ------- | ---- | ------------------------------------------------------------ |
| accessibilityPreferred | boolean | No  | Whether to prioritize the accessibility text of child components during a deep traversal. The value **true** means to prioritize the accessibility text of child components.<br>If a child component's accessibility text is empty, the accessibility service uses the component's own text content. The concatenated text is then assigned to the parent node if both its accessibility text and text content are empty.<br>Default value: **false**|

## accessibilityText

accessibilityText(value: string)

Sets the accessibility text. When a component does not contain a text attribute, you can use this API to set an accessibility text attribute, so that accessibility services can announce the specified content for the component.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility text. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>Default value: **""**<br>**NOTE**<br>If a component has both text content and accessibility text, only the accessibility text is announced.<br>If a component is grouped for accessibility purposes but lacks both text content and accessibility text, the screen reader will concatenate text from its child components (depth-first traversal).<br>To prioritize accessibility text concatenation, set **accessibilityPreferred** in **accessibilityGroup**.|

## accessibilityText<sup>12+</sup>

accessibilityText(text: Resource)

Sets the accessibility text, with support for resource references using **Resource**. When a component does not contain a text attribute, you can use this API to set an accessibility text attribute, so that accessibility services can announce the specified content for the component.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                  |
| ------ | ------ | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| text  | [Resource](ts-types.md#resource) | Yes  | Reference resource of accessibility text. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>**NOTE**<br>If a component has both text content and accessibility text, only the accessibility text is announced.<br>If a component is grouped for accessibility purposes but lacks both text content and accessibility text, the screen reader will concatenate text from its child components (depth-first traversal).<br>To prioritize accessibility text concatenation, set **accessibilityPreferred** in **accessibilityGroup**.|


## accessibilityDescription

accessibilityDescription(value: string)

Sets the accessibility description. This property provides additional context or explanation for the component, helping users understand the action or function it performs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.<br>Default value: **""**|

## accessibilityDescription<sup>12+</sup>

accessibilityDescription(description: Resource)

Sets the accessibility description, with support for resource references using **Resource**. This property provides additional context or explanation for the component, helping users understand the action or function it performs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                   |
| ------ | ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| description  | [Resource](ts-types.md#resource) | Yes  | Reference resource of the accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.|

## accessibilityLevel

accessibilityLevel(value: string)

Sets the accessibility level. This property determines whether the component can be recognized by accessibility services.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility level, which is used to decide whether a component can be identified by the accessibility service.<br>The options are as follows:<br>**"auto"**: The component's recognizability is determined by the accessibility grouping service and ArkUI.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the component nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>**NOTE**<br>When accessibilityLevel is set to **"auto"**, the component's recognizability depends on the following factors:<br>1. The accessibility service internally determines whether the component can be recognized.<br>2. If the parent component's **accessibilityGroup** property has **isGroup** set to **true**, the accessibility service will not focus on its child components, making them unrecognizable.<br>3. If the parent component's **accessibilityLevel** is set to **"no-hide-descendants"**, the component will not be recognized by accessibility services.|

## accessibilityVirtualNode<sup>11+</sup>

accessibilityVirtualNode(builder: CustomBuilder)

Sets an accessibility virtual child node. For custom drawing components, a **CustomBuilder** is passed, which is used to provide accessibility information. The components within the **CustomBuilder** are only used for layout and not for display. When the accessibility service obtains node information, it returns the node information from the **CustomBuilder**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Accessibility virtual node, which enables you to pass in a custom builder to the self-drawing component. The components in the custom builder are only laid out but not displayed at the backend. When the accessibility application obtains the accessibility node information, the node information in the custom builder is returned.|

## accessibilityChecked<sup>13+</sup>

accessibilityChecked(isCheck: boolean)

Sets the checked state of the accessibility component. This property is used in multiselect scenarios.

**Widget capability**: This API can be used in ArkTS widgets since API version 13.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| isCheck | boolean | Yes  | Whether the current component is selected.<br>The options are as follows:<br>**true**: The component is selected.<br>**false**: The component is not selected.<br>**undefined**: The component determines its own selected state.<br>Default value: **undefined**.<br>**NOTE**<br>1. Setting this parameter to **true** or **false** will automatically set the component's **checkable** attribute to **true**.<br>2. When this parameter is set to **true** or **false**, to use it with **accessibilitySelected**, set the **accessibilitySelected** parameter to **undefined**.|

## accessibilitySelected<sup>13+</sup>

accessibilitySelected(isSelect: boolean)

Sets the selected state of the accessibility component. This property is used in single-select scenarios.

**Widget capability**: This API can be used in ArkTS widgets since API version 13.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| isSelect | boolean | Yes  | Whether the current component is selected.<br>The options are as follows:<br>**true**: The component is selected.<br>**false**: The component is not selected.<br>**undefined**: The component determines its own selected state.<br>Default value: **undefined**.<br>**NOTE**<br>1. When this parameter is set to **true** or **false**, to use it with **accessibilityChecked**, set the **accessibilityChecked** parameter to **undefined**.|

## accessibilityRole<sup>18+</sup>

accessibilityRole(role: AccessibilityRoleType)

Sets the role type of the accessibility component, which affects how the component is announced by screen readers.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| role | [AccessibilityRoleType](ts-universal-attributes-accessibility.md#AccessibilityRoleType18) | Yes  | Role of the component as announced by screen readers (for example, button or chart). You can define custom roles.|

## onAccessibilityFocus<sup>18+</sup>

onAccessibilityFocus(callback: AccessibilityFocusCallback)

Triggered when the accessibility component gains or loses focus. Callback triggered when the component gains or loses focus.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityFocusCallback](ts-universal-attributes-accessibility.md#AccessibilityFocusCallback18) | Yes  | Callback that notifies the registered component of focus and blur events.|

## AccessibilityFocusCallback<sup>18+</sup>

type AccessibilityFocusCallback = (isFocus: boolean) => void

Defines the callback type used in **onAccessibilityFocus**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory| Description             |
| ------ | ------ | ---- | ---------------- |
| isFocus | boolean | Yes| Whether the component has gained or lost focus.|

## AccessibilityRoleType<sup>18+</sup>

Enumerates the component role types used by screen readers.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value | Description            |
| ---- | ---- | ------------------ |
| ACTION_SHEET | 0 | Action sheet.|
| ALERT_DIALOG | 1 | Alert dialog box.|
| INDEXER_COMPONENT | 2 | Indexer component.|
| BADGE_COMPONENT | 3 | Badge component.|
| BLANK  | 4 | Blank placeholder component.|
| BUTTON | 5 | Button.|
| BACK_BUTTON | 6 | Back button on a large image page.|
| SHEET_DRAG_BAR | 7 | Drag bar for sheets.|
| CALENDAR_PICKER | 8 | Calendar picker.|
| CALENDAR | 9 | Calendar.|
| CANVAS | 10 | Canvas component.|
| CANVAS_GRADIENT | 11 | Gradient object.|
| CANVAS_PATTERN | 12 | Pattern for image filling based on a specified source image and repetition mode.|
| CHECKBOX | 13 | Check box component.|
| CHECKBOX_GROUP | 14 | Check box group.|
| CIRCLE | 15 | Component for drawing circles.|
| COLUMN_SPLIT | 16 | Vertical layout of child components with horizontal dividers.|
| COLUMN | 17 | Container that lays out child components vertically.|
| CANVAS_RENDERING_CONTEXT_2D | 18 | 2D drawing object, which can be used to draw rectangles, images, and texts on the canvas component.|
| CHART | 19 | Chart component.|
| COUNTER | 20 | Counter component.|
| CONTAINER_MODAL | 21 | Modal container.|
| DATA_PANEL | 22 | Data panel component.|
| DATE_PICKER | 23 | Date picker.|
| DIALOG | 24 | Dialog box.|
| DIVIDER | 25 | Divider component.|
| DRAG_BAR | 26 | Drag bar.|
| EFFECT_COMPONENT | 27 | Container component for special effects.|
| ELLIPSE | 28 | Ellipse drawing component.|
| FLEX | 29 | Container that allows for flexible layout of child components.|
| FLOW_ITEM | 30 | Child component of a waterfall layout container.|
| FORM_COMPONENT | 31 | Widget component.|
| FORM_LINK | 32 | Static widget interaction component.|
| GAUGE | 33 | Gauge component.|
| GRID | 34 | Grid container.|
| GRID_COL | 35 | Grid column component.|
| GRID_CONTAINER | 36 | Grid container that lays out child components vertically.|
| GRID_ITEM | 37 | Single-item container within a grid container.|
| GRID_ROW | 38 | Grid row component.|
| HYPERLINK | 39 | Hyperlink component.|
| IMAGE | 40 | Image component|
| IMAGE_ANIMATOR | 41 | Frame animation component.|
| IMAGE_BITMAP | 42 | Pixel data for canvas rendering.|
| IMAGE_DATA | 43 | Pixel data for canvas rendering.|
| IMAGE_SPAN | 44 | Component used to display inline images.|
| LABEL | 45 | Label.|
| LINE | 46 | Line.|
| LIST | 47 | List.|
| LIST_ITEM | 48 | Specific item in a list.|
| LIST_ITEM_GROUP | 49 | List item group.|
| LOADING_PROGRESS | 50 | Component for display loading animations.|
| MARQUEE | 51 | Marquee component.|
| MATRIX2D | 52 | 2D matrix object.|
| MENU | 53 | Menu.|
| MENU_ITEM | 54 | Menu item.|
| MENU_ITEM_GROUP | 55 | Menu item group.|
| NAV_DESTINATION | 56 | Content area of the **Navigation** component.|
| NAV_ROUTER | 57 | Navigation component.|
| NAVIGATION | 58 | Root view container for navigation routing.|
| NAVIGATION_BAR | 59 | Navigation bar.|
| NAVIGATION_MENU | 60 | Navigation menu.|
| NAVIGATOR | 61 | Navigation container component.|
| OFFSCREEN_CANVAS | 62 | Canvas for custom drawing of graphics.|
| OFFSCREEN_CANVAS_RENDERING_CONTEXT2D | 63 | 2D drawing object, which can be used to draw rectangles, images, and texts on a canvas component.|
| OPTION | 64 | Specific item.|
| PANEL | 65 | Slidable panel.|
| PAPER_PAGE | 66 | Page.|
| PATH | 67 | Path drawing component.|
| PATH2D | 68 | Path object.|
| PATTERN_LOCK | 69 | Pattern lock component.|
| PICKER | 70 | Picker.|
| PICKER_VIEW | 71 | Picker view.|
| PLUGIN_COMPONENT | 72 | Plugin component.|
| POLYGON | 73 | Component used to draw a polygon.|
| POLYLINE | 74 | Component used to draw a polyline.|
| POPUP | 75 | Popup with a specific style.|
| PROGRESS | 76 | Text download button.|
| QRCODE | 77 | QR code.|
| RADIO | 78 | Radio button.|
| RATING | 79 | Component for selecting a rating within a given range.|
| RECT | 80 | Component used to draw a rectangle.|
| REFRESH | 81 | Pull-to-refresh container component.|
| RELATIVE_CONTAINER | 82 | Relative layout component.|
| REMOTE_WINDOW | 83 | Remote control window component.|
| RICH_EDITOR | 84 | Component that supports rich text editing and interactive text editing.|
| RICH_TEXT | 85 | Rich text component.|
| ROLE_PAGER | 86 | Pagination component.|
| ROW | 87 | Container that lays out child components horizontally.|
| ROW_SPLIT | 88 | Horizontal layout of child components with vertical dividers.|
| SCROLL | 89 | Scrollable container component.|
| SCROLL_BAR | 90 | Scrollbar.|
| SEARCH | 91 | Search box component.|
| SEARCH_FIELD | 92 | Search box.|
| SELECT | 93 | Drop-down list component.|
| SHAPE | 94 | Parent component of the drawing components.|
| SIDEBAR_CONTAINER | 95 | Sidebar container that can show and hide the sidebar.|
| SLIDER | 96 | Vertical slider.|
| SPAN | 97 | Component used to display inline text.|
| STACK | 98 | Stack container.|
| STEPPER | 99 | Stepper component.|
| STEPPER_ITEM | 100 | Page child component of the stepper component.|
| SWIPER | 101 | Swiper view container.|
| SWIPER_INDICATOR | 102 | Navigation indicator for the **Swiper** component.|
| SWITCH | 103 | Switch.|
| SYMBOL_GLYPH | 104 | Component for displaying a symbol glyph.|
| TAB_CONTENT | 105 | Content view for a tab in the **Tabs** component.|
| TAB_BAR | 106 | Tab bar.|
| TABS | 107 | Container that allows users to switch between content views through tabs.|
| TEXT | 108 | Text.|
| TEXT_CLOCK | 109 | Text clock component.|
| TEXT_ENTRY | 110 | Text input.|
| TEXT_INPUT | 111 | Text box component.|
| TEXT_PICKER | 112 | Text picker.|
| TEXT_TIMER | 113 | Component that displays timing information and is controlled in text format.|
| TEXT_AREA | 114 | Text area component.|
| TEXT_FIELD | 115 | Text box.|
| TIME_PICKER | 116 | Time picker.|
| TITLE_BAR | 117 | Title bar.|
| TOGGLER | 118 | Status component.|
| UI_EXTENSION_COMPONENT | 119 | UI extension component.|
| VIDEO | 120 | Component for playing video files and controlling playback.|
| WATER_FLOW | 121 | Waterfall layout container.|
| WEB | 122 | Component for loading web pages.|
| XCOMPONENT | 123 | Custom rendering component.|
| ROLE_NONE | 124 | Null.|

## accessibilityNextFocusId<sup>18+</sup>

accessibilityNextFocusId(nextId: string)

Sets the next focus target for the component during focus traversal.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| nextId | string | Yes  | [Unique ID](ts-universal-attributes-component-id.md#id) of the next component to receive focus. If the ID does not correspond to any component, the setting is invalid.|

## accessibilityDefaultFocus<sup>18+</sup>

accessibilityDefaultFocus(focus: boolean)

Sets whether the component is the default initial focus for screen readers on the current page.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| focus  | boolean | Yes  | Whether the component is the default initial focus for screen readers on the current page. The value **true** means the component is the default initial focus for screen readers on the current page. Other values are invalid.|

## accessibilityUseSamePage<sup>18+</sup>

accessibilityUseSamePage(pageMode: AccessibilitySamePageMode)

Solves focus jumping issues in sub-tree scenarios like UIExtensionComponent. Sets the same-page mode for this UIExtensionComponent and the host application. This property is intended to solve focus jumping issues in sub-tree scenarios. Due to the timing of page events sent by the UIExtensionComponent and the host application, focus may jump from one component to another, causing "focus jumping."

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                            |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| pageMode | [AccessibilitySamePageMode](#accessibilitysamepagemode18) | Yes  | Same-page mode for the current UIExtensionComponent and the host application.|

## AccessibilitySamePageMode<sup>18+</sup>

Enumerates the same-page modes for the current UIExtensionComponent and the host application.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Value  | Description                                                        |
| ----------- | ---- | ------------------------------------------------------------ |
| SEMI_SILENT | 0    | Ignores page events if it is the first page load or if the root node of the page sends the page event.|
| FULL_SILENT | 1    | Ignores all page events in the UIExtensionComponent.                                     |

## accessibilityScrollTriggerable<sup>18+</sup>

accessibilityScrollTriggerable(isTriggerable: boolean)

Sets whether to enable automatic scrolling for screen readers when the current page has no focusable components.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        |  Type   | Mandatory| Description                                                        |
| -------------- | ------- | ---- | ------------------------------------------------------------ |
| isTriggerable  | boolean | Yes  | Whether the component supports automatic scrolling for screen readers when the current page has no focusable components.<br>The options are as follows:<br>**true**: The component triggers automatic scrolling for screen readers when the current page has no focusable components.<br>**false**: The component does not trigger automatic scrolling for screen readers when the current page has no focusable components.<br>**undefined**: The default settings are restored.<br>Default value: **true**<br>**NOTE**<br>1. This parameter does not affect the original **scrollable** attribute of the component.<br>2. The final scrolling behavior is determined by the screen reader based on this parameter and whether the component supports scrolling.<br>3. This API applies to all basic components. It is recommended for scrollable components, including **List**, **Grid**, **Scroll**, and **WaterFlow**.|

## accessibilityTextHint<sup>12+</sup>

accessibilityTextHint(value: string)

Sets the text hint for the component, which can be queried by accessibility services.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        |  Type   | Mandatory| Description                                                        |
| -------------- | ------- | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Text hint for the component, which can be queried by accessibility services.|

## accessibilityFocusDrawLevel<sup>18+</sup>

accessibilityFocusDrawLevel(drawLevel: FocusDrawLevel)

Sets the drawing level for the accessibility focus highlight (green box) to ensure it is visible and not obscured by other components.
> **NOTE**
>
> 1. By default, the accessibility focus highlight (green box) is drawn at the same level as the focused component. This can sometimes result in the highlight being obscured or clipped by parent components or siblings with higher z-order.
>
> 2. Setting the drawing level to the topmost layer ensures that the accessibility focus highlight is not obscured by other components. This is useful when you want the highlight to be clearly visible at all times. However, this setting may not be suitable if you need to interact with components that should overlay the currently focused component and you do not want the accessibility highlight to be visible.


**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| drawLevel | [FocusDrawLevel](ts-appendix-enums.md#focusdrawlevel18) | Yes  | Drawing level for the accessibility focus highlight.|

## Example 1: Setting Accessibility Text and Description

This example demonstrates how to use **accessibilityText** and **accessibilityDescription** to customize the content announced by screen readers.

```
// xxx.ets
@Entry
@Component
struct Index {

  @Builder customAccessibilityNode() {
    Column() {
      Text(`virtual node`)
    }
    .width(10)
    .height(10)
  }

  build() {
    Row() {
      Column() {
        Text("Text 1")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Text("Text 2")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
      .accessibilityGroup(true)
      .accessibilityLevel("yes")
      .accessibilityText("Group") // If a component has both text content and accessibility text, only the accessibility text is announced.
      .accessibilityDescription("The Column component is selectable , and the text to be read out is "Group".)
      .accessibilityVirtualNode(this.customAccessibilityNode)
      .accessibilityChecked(true)
      .accessibilitySelected(undefined)
    }
    .height('100%')
  }
}
```

## Example 2: Setting the Accessibility Group

This example shows how to use **accessibilityGroup** to prioritize reading the accessibility text of child components.

```
// xxx.ets
@Entry
@Component
struct Focus {
  build() {
    Column({ space: 10 }) {
      Text('123456')
        .focusable(true)
        .borderRadius(5)
        .accessibilityText("Accessibility text is announced if both accessibility text and text content are present")
        .accessibilityLevel("yes")
      Button().accessibilityLevel("yes").accessibilityText("Accessibility text is announced if no text is present")
      Button("Text content is announced if no accessibility text is present").accessibilityLevel("yes")
      Button()
      Button('btnl23').accessibilityText("Button with both accessibility text and text").accessibilityLevel("yes")
      Button('btn123').accessibilityLevel("yes")
    }
    .accessibilityGroup(true, { accessibilityPreferred: true })
    //.accessibilityGroup(true)
    .borderWidth(5)
    .width('100%')
    .height('100%')
  }
}
```

