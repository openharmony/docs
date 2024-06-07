# Navigation

The **\<Navigation>** component is the root view container for navigation. It typically functions as the root container of a page and includes a title bar, content area, and toolbar. The content area switches between the home page content (child components of **\<Navigation>**) and non-home page content (child components of [\<NavDestination>](ts-basic-components-navdestination.md)) through routing.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> Since API version 11, this component supports the safe area attribute by default, with the default attribute value being **expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])**. You can override this attribute to change the default behavior. In earlier versions, you need to use the [expandSafeArea](ts-universal-attributes-expand-safe-area.md) attribute to implement the safe area feature.


## Child Components

Supported

Since API version 9, it is recommended that this component be used together with the [\<NavRouter>](ts-basic-components-navrouter.md) component.

Since API version 10, it is recommended that this component be used together with the [\<NavPathStack>](#navpathstack10) component and **navDestination** attribute for page routing.

## APIs

### Navigation

Navigation()

### Navigation<sup>10+</sup>

Navigation(pathInfos: NavPathStack)

Binds a navigation stack to the **\<Navigation>** component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name      | Type                           | Mandatory  | Description  |
| --------- | ------------------------------- | ---- | ------ |
| pathInfos | [NavPathStack](#navpathstack10) | No   | Information about the navigation stack.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### title

title(value: ResourceStr | CustomBuilder | NavigationCommonTitle | NavigationCustomTitle, options?: NavigationTitleOptions)

Sets the page title.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup> \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](#navigationcommontitle9)<sup>9+</sup> \| [NavigationCustomTitle](#navigationcustomtitle9)<sup>9+</sup> | Yes  | Page title. When the NavigationCustomTitle type is used to set the height, [titleMode](#titlemode) does not take effect. When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).|
| options | [NavigationTitleOptions](#navigationtitleoptions11)<sup>11+</sup> | No  | Title bar options.                                                  |

### subTitle<sup>(deprecated)</sup>

subTitle(value: string)

Sets the page subtitle.

This API is deprecated since API version 9. You are advised to use [title](#title) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| value  | string | Yes  | Page subtitle.|

### menus

menus(value: Array&lt;NavigationMenuItem&gt; | CustomBuilder)

Sets the menu items in the upper right corner of the page. If this attribute is not set, no menu item is displayed. When the value type is Array<[NavigationMenuItem](#navigationmenuitem)&gt;, the menu shows a maximum of three icons in portrait mode and a maximum of five icons in landscape mode, with excess icons (if any) placed under the automatically generated **More** icon.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description            |
| ------ | ------------------------------------------------------------ | ---- | ---------------- |
| value  | Array<[NavigationMenuItem](#navigationmenuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Menu items in the upper right corner of the page.|

### titleMode

titleMode(value: NavigationTitleMode)

Sets the display mode of the page title bar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                               | Mandatory| Description                                                     |
| ------ | --------------------------------------------------- | ---- | --------------------------------------------------------- |
| value  | [NavigationTitleMode](#navigationtitlemode) | Yes  | Display mode of the page title bar.<br>Default value: **NavigationTitleMode.Free**|

### toolBar<sup>(deprecated)</sup>

toolBar(value: object | CustomBuilder)

Sets the content of the toolbar. If this attribute is not set, no toolbar is displayed. Items are evenly distributed on the toolbar at the bottom. Text and icons are evenly distributed in each content area. If the text is too long, it is scaled down level by level, wrapped in two lines, and then clipped with an ellipsis (...).

This API is deprecated since API version 10. You are advised to use [toolbarConfiguration](#toolbarconfiguration10) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description        |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [object](#object) \| [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Content of the toolbar.|

### toolbarConfiguration<sup>10+</sup>

toolbarConfiguration(value: Array&lt;ToolbarItem&gt; | CustomBuilder, options?: NavigationToolbarOptions)

Sets the content of the toolbar. If this attribute is not set, no toolbar is displayed.

**Widget capability**: Since API version 10, this API is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   |  Array&lt;[ToolbarItem](#toolbaritem10)&gt;  \| [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Content of the toolbar. When the value type is Array&lt;[ToolbarItem](#toolbaritem10), the toolbar exhibits the following features:<br>Items are evenly distributed on the toolbar at the bottom. Text and icons are evenly distributed in each content area.<br>If any item contains overlong text and there are fewer than five items, the following measures are taken: 1. Increase the item's width to accommodate the text until it is as large as the screen width; 2. Scale down the text level by level; 3. Wrap the text in two lines; 4. Clip the text with an ellipsis (...).<br>The toolbar shows a maximum of five icons in portrait mode, with excess icons (if any) placed under the automatically generated **More** icon. In landscape mode, this attribute must be used together with Array&lt;[NavigationMenuItem](#navigationmenuitem)&gt; of the **menus** attribute; the toolbar at the bottom is automatically hidden, and all items on the toolbar are moved to the menu in the upper right corner of the screen.<br>When the value type is [CustomBuilder](ts-types.md#custombuilder8), and the toolbar does not exhibit the preceding features except that items are evenly distributed on the toolbar at the bottom.|
| options | [NavigationToolbarOptions](#navigationtoolbaroptions11)<sup>11+</sup> | No  | Toolbar options.                                                |

### hideToolBar

hideToolBar(value: boolean)

Specifies whether to hide the toolbar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to hide the toolbar.<br>Default value: **false**<br>**true**: Hide the toolbar.<br>**false**: Show the toolbar.|

### hideTitleBar

hideTitleBar(value: boolean)

Specifies whether to hide the title bar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Show the title bar.|

### hideBackButton

hideBackButton(value: boolean)

Specifies whether to hide the back button in the title bar. The back button is available only when [titleMode](#titlemode) is set to **NavigationTitleMode.Mini**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to hide the back button in the title bar.<br>Default value: **false**<br>**true**: Hide the back button.<br>**false**: Show the back button.|

### navBarWidth<sup>9+</sup>

navBarWidth(value: Length)

Sets the width of the navigation bar. This attribute takes effect only when the **\<Navigation>** component is split.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                        | Mandatory| Description                                     |
| ------ | ---------------------------- | ---- | ----------------------------------------- |
| value  | [Length](ts-types.md#length) | Yes  | Width of the navigation bar.<br>Default value: **240**<br>Unit: vp<br>**undefined**: The behavior is not processed, and the width of the navigation bar is at the default value.|

### navBarPosition<sup>9+</sup>

navBarPosition(value: NavBarPosition)

Sets the position of the navigation bar. This attribute takes effect only when the **\<Navigation>** component is split.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                                         |
| ------ | ------------------------------------------ | ---- | --------------------------------------------- |
| value  | [NavBarPosition](#navbarposition9) | Yes  | Position of the navigation bar.<br>Default value: **NavBarPosition.Start**|

### mode<sup>9+</sup>

mode(value: NavigationMode)

Sets the display mode of the navigation bar. Available options are **Stack**, **Split**, and **Auto**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                                                        |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [NavigationMode](#navigationmode9) | Yes  | Display mode of the navigation bar.<br>Default value: **NavigationMode.Auto**<br>At the default settings, the component adapts to a single column or two columns based on the component width.|

### backButtonIcon<sup>9+</sup>

backButtonIcon(value: string | PixelMap | Resource)

Sets the icon of the back button in the title bar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                |
| ------ | ------------------------------------------------------------ | ---- | -------------------- |
| value  | string \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | Yes  | Icon of the back button in the title bar.|

### hideNavBar<sup>9+</sup>

hideNavBar(value: boolean)

Specifies whether to hide the navigation bar. If this parameter is set to **true**, the navigation bar, including the title bar, content area, and toolbar, is hidden. In this case, if the navigation destination page is in the navigation stack, it is moved to the top of the stack and displayed. Otherwise, a blank page is displayed.

From API version 9 to API version 10, this attribute takes effect only in dual-column mode. Since API version 11, this attribute takes effect in single-column, dual-column, and auto modes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                              |
| ------ | ------- | ---- | ---------------------------------- |
| value  | boolean | Yes  | Whether to hide the navigation bar.<br>Default value: **false**|

### navDestination<sup>10+</sup>

navDestination(builder: (name: string, param: unknown) => void)

Builder for a **\<NavDestination>** component. The **builder** function is used, with the **name** and **param** parameters passed in. The **builder** can have only one root node. In the builder, a layer of custom components can be included outside the **\<NavDestination>** component. However, no attributes or events can be set for the custom components. Otherwise, only blank components are displayed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                  | Mandatory| Description                    |
| ------- | -------------------------------------- | ---- | ------------------------ |
| builder | (name: string, param: unknown) => void | Yes  | Builder for a **\<NavDestination>** component.|

### navBarWidthRange<sup>10+</sup>

navBarWidthRange(value: [Dimension, Dimension])

Sets the minimum and maximum widths of the navigation bar (effective in dual-column mode).

For details about the priority rules, see **NOTE** below.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| builder | [[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)] | Yes  | Minimum and maximum widths of the navigation bar.<br>Default value: 240 for the minimum value; 40% of the component width (not greater than 432) for the maximum value; if either of the widths is not set, the default value is used for that width.<br>Unit: vp|

### minContentWidth<sup>10+</sup>

minContentWidth(value: Dimension)

Sets the minimum width of the navigation bar content area (effective in dual-column mode).

For details about the priority rules, see **NOTE** below.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                | Mandatory| Description                                                        |
| ------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| builder | [Dimension](ts-types.md#dimension10) | Yes  | Minimum width of the navigation bar content area.<br>Default value: **360**<br>Unit: vp<br>**undefined**: The behavior is not processed, and the minimum width of the navigation bar is at the default value.<br>Breakpoint calculation in Auto mode: default 600 vp = minNavBarWidth (240 vp) + minContentWidth (360 vp)|

>  **NOTE**
>
>  1. If only **navBarWidth** is set, no divider in the **\<Navigation>** component can be dragged.
>
>  2. **navBarWidthRange** specifies the range within which the divider can be dragged. If it is not set, the default value is used. The dragging of the divider is subject to both **navBarWidthRange** and **minContentWidth**.
>
>  3. If the size of the **\<Navigation>** component decreases, it carries out the following steps in sequence:<br>a. Scale down the content area. If **minContentWidth** is not set, the content area can be scaled down to 0. Otherwise, the content area can be scaled down to as small as the value specified by **minContentWidth**.b. Scale down the navigation bar until its width reaches the value defined by **navBarRange**.c. Clip the displayed content.

## Events

### onTitleModeChange

onTitleModeChange(callback: (titleMode: NavigationTitleMode) =&gt; void)

Called when [titleMode](#titlemode) is set to **NavigationTitleMode.Free** and the title bar mode changes as content scrolls.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                               | Mandatory| Description      |
| --------- | --------------------------------------------------- | ---- | ---------- |
| titleMode | [NavigationTitleMode](#navigationtitlemode) | Yes  | Title mode.|

### onNavBarStateChange<sup>9+</sup>

onNavBarStateChange(callback: (isVisible: boolean) =&gt; void) 

Called when the navigation bar visibility status changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type   | Mandatory| Description                                          |
| --------- | ------- | ---- | ---------------------------------------------- |
| isVisible | boolean | Yes  | Whether the navigation bar is visible. The value **true** means that the navigation bar is visible, and **false** means the opposite.|

### onNavigationModeChange<sup>11+</sup>

onNavigationModeChange(callback: (mode: NavigationMode) =&gt; void) 

Called when the **\<Navigation>** component is displayed for the first time or its display mode switches between single-column and dual-column.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type   | Mandatory| Description                                          |
| --------- | ------- | ---- | ---------------------------------------------- |
| mode | [NavigationMode](#navigationmode9) | Yes  | **NavigationMode.Split**: The component is displayed in two columns.<br>**NavigationMode.Stack**: The component is displayed in a single column.|

### customNavContentTransition<sup>11+</sup>

customNavContentTransition(delegate(from: NavContentInfo, to: NavContentInfo, operation: NavigationOperation) => NavigationAnimatedTransition | undefined)

Callback of the custom transition animation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                                 | Mandatory| Description                   |
| --------- | ----------------------------------------------------- | ---- | ----------------------- |
| from      | [NavContentInfo](#navcontentinfo11)                   | Yes  | Destination page to exit.|
| to        | [NavContentInfo](#navcontentinfo11)                   | Yes  | Destination page to enter.|
| operation | [NavigationOperation](#navigationoperation11) | Yes  | Transition type.             |

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [NavigationAnimatedTransition](#navigationanimatedtransition11) \| undefined | Custom transition animation agreement.<br>**undefined**: The default transition effect is executed.|

## NavPathStack<sup>10+</sup>

Implements a navigation stack.

### pushPath<sup>10+</sup>

pushPath(info: NavPathInfo, animated?: boolean): void

Pushes the navigation destination page specified by **info** to the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| info | [NavPathInfo](#navpathinfo10) | Yes   | Information about the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### pushPathByName<sup>10+</sup>

pushPathByName(name: string, param: unknown, animated?: boolean): void

Pushes the navigation destination page specified by **name**, with the data specified by **param**, to the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | unknown | Yes   | Detailed parameters of the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### pushPathByName<sup>11+</sup>

pushPathByName(name: string, param: Object, onPop: import('../api/@ohos.base').Callback\<PopInfo>, animated?: boolean): void

Pushes the navigation destination page specified by **name**, with the data specified by **param**, to the navigation stack. This API uses the **onPop** callback to receive the result returned when the page is popped out of the stack.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
|------|------|------|------|
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | Object | Yes   | Detailed parameters of the navigation destination page.|
| onPop | import('../api/@ohos.base').Callback\<[PopInfo](#popinfo11)> | Yes| Callback used to receive the result.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### pushDestination<sup>11+</sup>

pushDestination(info: NavPathInfo, animated?: boolean): Promise&lt;void&gt;

Pushes the navigation destination page specified by **info** to the navigation stack. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| info | [NavPathInfo](#navpathinfo10) | Yes   | Information about the navigation destination page.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../../errorcode-universal.md) and [Router Error Codes](../errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001    | Internal error.|
| 100005    | Builder function not registered. |
| 100006    | NavDestination not found.|

### pushDestinationByName<sup>11+</sup>

pushDestinationByName(name: string, param: Object, animated?: boolean): Promise&lt;void&gt;

Pushes the navigation destination page specified by **name**, with the data specified by **param**, to the navigation stack. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | Object | Yes   | Detailed parameters of the navigation destination page.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../../errorcode-universal.md) and [Router Error Codes](../errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001    | Internal error.|
| 100005    | Builder function not registered. |
| 100006    | NavDestination not found.|

### pushDestinationByName<sup>11+</sup>

pushDestinationByName(name: string, param: Object, onPop: import('../api/@ohos.base').Callback\<PopInfo>, animated?: boolean): Promise&lt;void&gt;

Pushes the navigation destination page specified by **name**, with the data specified by **param**, to the navigation stack. This API uses the **onPop** callback to handle the result returned when the page is popped out of the stack. It uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | Object | Yes   | Detailed parameters of the navigation destination page.|
| onPop | import('../api/@ohos.base').Callback\<[PopInfo](#popinfo11)> | Yes   | Callback used to handle the result returned when the page is popped out of the stack.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../../errorcode-universal.md) and [Router Error Codes](../errorcode-router.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001    | Internal error.|
| 100005    | Builder function not registered. |
| 100006    | NavDestination not found.|

### replacePath<sup>11+</sup>

replacePath(info: NavPathInfo, animated?: boolean): void

Replaces the top of the navigation stack with the page specified by **info**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| info | [NavPathInfo](#navpathinfo10) | Yes   | Parameters of the page to replace the top of the navigation stack.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### replacePathByName<sup>11+</sup>

replacePathByName(name: string, param: Object, animated?: boolean): void

Replaces the top of the navigation stack with the page specified by **name**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | Object | Yes   | Detailed parameters of the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### removeByIndexes<sup>11+</sup>

removeByIndexes(indexes: Array<number\>): number

Removes the navigation destination pages specified by **indexes** from the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| indexes  | Array<number\>  | Yes   | Array of indexes of the navigation destination pages to remove.  |

**Return value**

| Type         | Description                      |
| ----------- | ------------------------ |
| number | Number of the navigation destination pages removed.|

### removeByName<sup>11+</sup>

removeByName(name: string): number

Removes the navigation destination page specified by **name** from the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page to remove.  |

**Return value**

| Type         | Description                      |
| ----------- | ------------------------ |
| number | Number of the navigation destination pages removed.|

### pop<sup>10+</sup>

pop(animated?: boolean): NavPathInfo | undefined

Pops the top element out of the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type         | Description                      |
| ----------- | ------------------------ |
| [NavPathInfo](#navpathinfo10) | Returns the information about the navigation destination page at the top of the stack.|
| undefined   | Returns **undefined** if the navigation stack is empty.     |

### pop<sup>11+</sup>

pop(result: Object, animated?: boolean): NavPathInfo | undefined

Pops the top element out of the navigation stack and invokes the **onPop** callback to pass the page processing result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                           | Mandatory  | Description                  |
| ---- | ----------------------------- | ---- | -------------------- |
| result | Object | Yes| Custom processing result on the page.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type         | Description                      |
| ----------- | ------------------------ |
| [NavPathInfo](#navpathinfo10) | Returns the information about the navigation destination page at the top of the stack.|
| undefined   | Returns **undefined** if the navigation stack is empty.     |

### popToName<sup>10+</sup>

popToName(name: string, animated?: boolean): number

Pops pages until the first navigation destination page that matches **name** from the bottom of the navigation stack is at the top of the stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Returns the index of the first navigation destination page that matches **name** from the bottom of the navigation stack; returns **-1** if such a page does not exist.|

### popToName<sup>11+</sup>

popToName(name: string, result: Object, animated?: boolean): number

Pops pages until the first navigation destination page that matches **name** from the bottom of the navigation stack is at the top of the stack. This API uses the **onPop** callback to pass in the page processing result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|
| result | Object | Yes| Custom processing result on the page.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Returns the index of the first navigation destination page that matches **name** from the bottom of the navigation stack; returns **-1** if such a page does not exist.|

### popToIndex<sup>10+</sup>

popToIndex(index: number, animated?: boolean): void

Returns the navigation stack to the page specified by **index**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### popToIndex<sup>11+</sup>

popToIndex(index: number, result: Object, animated?: boolean): void

Returns the navigation stack to the page specified by **index** and invokes the **onPop** callback to pass the page processing result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|
| result | Object | Yes| Custom processing result on the page.|
| animated | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### moveToTop<sup>10+</sup>

moveToTop(name: string, animated?: boolean): number

Moves the first navigation destination page that matches **name** from the bottom of the navigation stack to the top of the stack

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Returns the index of the first navigation destination page that matches **name** from the bottom of the navigation stack; returns **-1** if such a page does not exist.|

### moveIndexToTop<sup>10+</sup>

moveIndexToTop(index: number, animated?: boolean): void

Moves to the top of the navigation stack the navigation destination page specified by **index**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### clear<sup>10+</sup>

clear(animated?: boolean): void

Clears the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| animated<sup>11+</sup> | boolean | No   | Whether to support transition animation.<br>Default value: **true**|

### getAllPathName<sup>10+</sup>

getAllPathName(): Array<string\>

Obtains the names of all navigation destination pages in the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type            | Description                        |
| -------------- | -------------------------- |
| Array<string\> | Names of all navigation destination pages in the navigation stack.|

### getParamByIndex<sup>10+</sup>

getParamByIndex(index: number): unknown | undefined

Obtains the parameter information of the navigation destination page specified by **index**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| index | number | Yes   | Index of the navigation destination page.|

**Return value**

| Type       | Description                        |
| --------- | -------------------------- |
| unknown   | Returns the parameter information of the matching navigation destination page.|
| undefined | Returns **undefined** if the passed index is invalid.    |

### getParamByName<sup>10+</sup>

getParamByName(name: string): Array<unknown\>

Obtains the parameter information of all the navigation destination pages that match **name**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|

**Return value**

| Type             | Description                               |
| --------------- | --------------------------------- |
| Array<unknown\> | Parameter information of all the matching navigation destination pages.|

### getIndexByName<sup>10+</sup>

getIndexByName(name: string): Array<number\>

Obtains the indexes of all the navigation destination pages that match **name**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory  | Description                 |
| ---- | ------ | ---- | ------------------- |
| name | string | Yes   | Name of the navigation destination page.|

**Return value**

| Type            | Description                               |
| -------------- | --------------------------------- |
| Array<number\> | Indexes of all the matching navigation destination pages.|

### size<sup>10+</sup>

size(): number

Obtains the stack size.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type    | Description    |
| ------ | ------ |
| number | Stack size.|

### disableAnimation<sup>11+</sup>

disableAnimation(value: boolean): void

Disables or enables the transition animation in the **\<Navigation>** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ----- | ------ | ---- | ---------------------- |
| value | boolean | No   | Whether to disable the transition animation.<br>Default value: **false**|

### getParent<sup>11+</sup>

getParent(): NavPathStack | null

Obtains the parent navigation path stack.<br>When a **\<Navigation>** component is nested (directly or indirectly) insider another **\<Navigation>** component, the internal one can obtain the navigation path stack of the external one.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type    | Description    |
| ------ | ------ |
| [NavPathStack](#navpathstack10) \| null | Navigation path stack of the external **\<Navigation>** component inside which the current **\<Navigation>** component is nested. If no nesting is involved, **null** is returned.|

### setInterception<sup>12+</sup>

setInterception(interception: NavigationInterception): void

Sets the interception callback for navigation page redirection.

**Parameters**

| Name   | Type    | Mandatory  | Description                    |
| ---- | ---- | --- | ---|
|interception| [NavigationInterception](#navigationinterception12)| Yes| Object to be intercepted during navigation redirection.|

## NavPathInfo<sup>10+</sup>

Provides the navigation page information.

### constructor

constructor(name: string, param: unknown)

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type     | Mandatory  | Description                   |
| ----- | ------- | ---- | --------------------- |
| name  | string  | Yes   | Name of the navigation destination page.  |
| param | unknown | Yes   | Detailed parameters of the navigation destination page.|
| onPop<sup>11+</sup> | import('../api/@ohos.base').Callback\<[PopInfo](#popinfo11)> | No| Callback returned when **pop** is called on the navigation destination page.|

## PopInfo<sup>11+</sup>

Provides the callback information returned when a page is popped out of the navigation stack.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
|------|-----|-----|-----|
| info | [NavPathInfo](#navpathinfo10) | Yes| Information about the current page when a back action is performed. The value is automatically obtained by the system.|
| result | Object | Yes| Result returned when a back action is performed. You must customize the object.|

## NavContentInfo<sup>11+</sup>

Provides the destination information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type | Mandatory | Description |
|-------|-------|------|-------|
| name | string | No| Name of the navigation destination. If the view is a root view (**NavBar**), the return value is **undefined**.|
| index | number | Yes| Index of the navigation destination in the navigation stack. If the view is a root view (**NavBar**), the return value is **-1**.|
| mode | [NavDestinationMode](ts-basic-components-navdestination.md#navdestinationmode) | No| Mode of the navigation destination. If the view is a root view (**NavBar**), the return value is **undefined**.|

## NavigationAnimatedTransition<sup>11+</sup>

Defines the custom transition animation protocol. You need to implement this protocol to define the redirection animation of the navigation route.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**
| Name| Type| Mandatory| Description|
|------|-----|-----|------|
| timeout | number | No| Animation timeout time.<br> Unit: ms<br> Default value: **1000**|
| transition | (transitionProxy : [NavigationTransitionProxy](#navigationtransitionproxy-11)): void | Yes| Callback for executing the custom transition animation.<br> **transitionProxy**: proxy for the custom transition animation.|
| onTransitionEnd | (success: boolean):void | No| Callback invoked when the transition is complete.<br> **success**: whether the transition is successful.|

## NavigationTransitionProxy <sup>11+</sup>

Implements a custom transition animation proxy.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type | Mandatory| Description |
|------|-------|-----|-------|
| from | [NavContentInfo](#navcontentinfo11) | Yes| Information about the exit page.|
| to | [NavContentInfo](#navcontentinfo11) | Yes| Information about the enter page.|

### finishTransition

Finishes this custom transition animation. This API must be manually called to end the animation. Otherwise, the system ends the animation when the timeout expires.

**Atomic service API**: This API can be used in atomic services since API version 12.

## NavigationInterception<sup>12+</sup>

Describes the object to be intercepted during navigation redirection.

| Name   | Type    | Mandatory| Description   |
| ---- | ----- | ----- | ----   |
| willShow | (from: [NavDestinationContext](ts-basic-components-navdestination.md#navdestinationcontext11) \|"navBar",<br> to: [NavDestinationContext](ts-basic-components-navdestination.md#navdestinationcontext11) \|"navBar",<br> operation: [NavigationOperation](#navigationoperation11),<br> isAnimated: boolean) =&gt;void | No| Interception before page redirection, allowing for stack operations. The setting takes effect in the current redirection.<br> **from**: information about the top page in the navigation stack before page redirection. The value **navBar** indicates that the top page is the home page.<br> **to**: information about the top page in the navigation stack after page redirection. The value **navBar** indicates that the top page is the home page.<br> **operation**: current page redirection type.<br> **isAnimated**: whether to support transition animation.|
| didShow | (from: [NavDestinationContext](ts-basic-components-navdestination.md#navdestinationcontext11) \|"navBar",<br> to: [NavDestinationContext](ts-basic-components-navdestination.md#navdestinationcontext11) \|"navBar",<br> operation: [NavigationOperation](#navigationoperation11),<br> isAnimated: boolean) =&gt;void | No| Callback after page redirection. The setting takes effect in the next redirection.<br> **from**: information about the top page in the navigation stack before page redirection. The value **navBar** indicates that the top page is the home page.<br> **to**: information about the top page in the navigation stack after page redirection. The value **navBar** indicates that the top page is the home page.<br> **operation**: current page redirection type.<br> **isAnimated**: whether to support transition animation.| No| Callback after page redirection.|
| modeChange | (mode: [NavigationMode](#navigationmode9)) =&gt;void | No| Callback invoked when the display mode of the **\<Navigation>** component switches between single-column and dual-column.|

## NavigationMenuItem

| Name    | Type           | Mandatory  | Description             |
| ------ | ------------- | ---- | --------------- |
| value  | string        | Yes   | Text of the menu item. Its visibility varies by the API version.<br>API version 9: visible.<br> API version 10: invisible.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| icon   | string        | No   | Icon path of the menu item.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| isEnabled<sup>12+</sup>   | boolean        | No   | Enabled status.<br>**true** (default): enabled<br>**false**: disabled|
| action | () =&gt; void | No   | Callback invoked when the menu item is selected.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## object

| Name    | Type           | Mandatory  | Description             |
| ------ | ------------- | ---- | --------------- |
| value  | string        | Yes   | Text of the toolbar item.  |
| icon   | string        | No   | Icon path of the toolbar item.|
| action | () =&gt; void | No   | Callback invoked when the toolbar item is selected.  |

## ToolbarItem<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name        | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value      | ResourceStr                              | Yes   | Text of the toolbar item.                           |
| icon       | ResourceStr                              | No   | Icon path of the toolbar item.                         |
| action     | () =&gt; void                            | No   | Callback invoked when the toolbar item is selected.                           |
| status     | [ToolbarItemStatus](#toolbaritemstatus10) | No   | Status of the toolbar item.<br>Default value: **ToolbarItemStatus.NORMAL**|
| activeIcon | ResourceStr                              | No   | Icon path of the toolbar item in the active state.               |

## ToolbarItemStatus<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name      | Description                                      |
| -------- | ---------------------------------------- |
| NORMAL   | Normal state. In this state, the toolbar item takes on the default style and can switch to another state-specific style by responding to the hover, press, and focus events.|
| DISABLED | Disabled state. In this state, the toolbar item is disabled and does not allow for user interactions.|
| ACTIVE   | Active state. In this state, the toolbar item can update its icon to the one specified by **activeIcon** by responding to a click event.|

## NavigationTitleMode

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Description                                      |
| ---- | ---------------------------------------- |
| Free | When the content is more than one screen in a scrollable component, the main title shrinks as the content scrolls down (the subtitle fades out with its size remaining unchanged) and restores as the content scrolls up to the top.<br>**NOTE**<br>The association between the title size and content scrolling works only when **title** is set to **ResourceStr** or **NavigationCommonTitle**. If **title** is set to any other value type, the main title changes in mere location when pulled down.<br>For the association to work when the content is less than one screen in a scrollable component, set the **options** parameter of the scrollable component's [edgeEffect](ts-container-list.md#attributes) attribute to **true**.|
| Mini | The title is fixed at mini mode.                               |
| Full | The title is fixed at full mode.                               |

## NavigationCommonTitle<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type    | Mandatory  | Description    |
| ---- | ------ | ---- | ------ |
| main | string | Yes   | Main title.|
| sub  | string | Yes   | Subtitle.|

## NavigationCustomTitle<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name     | Type                                      | Mandatory  | Description      |
| ------- | ---------------------------------------- | ---- | -------- |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | Yes   | Content of the title bar.|
| height  | [TitleHeight](#titleheight9) \| [Length](ts-types.md#length) | Yes   | Height of the title bar.|

## NavBarPosition<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name   | Description              |
| ----- | ---------------- |
| Start | When two columns are displayed, the main column is at the start of the main axis.|
| End   | When two columns are displayed, the main column is at the end of the main axis.|

## NavigationMode<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name | Description                                                        |
| ----- | ------------------------------------------------------------ |
| Stack | The navigation bar and content area are displayed independently of each other, which are equivalent to two pages.                    |
| Split | The navigation bar and content area are displayed in different columns.<br>The values of **navBarWidthRange** are represented by [minNavBarWidth,maxNavBarWidth].<br>1. When the value of **navBarWidth** is beyond the value range specified by **navBarWidthRange**, **navBarWidth** is set according to the following rules:<br>Value of **navBarWidth** < Value of **minNavBarWidth**: The value of **navBarWidth** is changed to that of **minNavBarWidth**.<br>Value of **navBarWidth** > Value of **maxNavBarWidth** and Result of [Component width - Value of **minContentWidth** - Divider width (1 vp)] > Value of **maxNavBarWidth**: The value of **navBarWidth** is changed to that of **maxNavBarWidth**.<br>Value of **navBarWidth** > Value of **maxNavBarWidth** and Result of [Component width - Value of **minContentWidth** - Divider width (1 vp)] < Value of **maxNavBarWidth**: The value of **navBarWidth** is changed to that of **minNavBarWidth**.<br>Value of **navBarWidth** > Value of **maxNavBarWidth** and Component width - Value of **minContentWidth** - Divider width (1 vp) is within the value range specified by **navBarWidthRange**: The value of **navBarWidth** is changed to Component width - Value of **minContentWidth** - Divider width (1 vp).<br>2. When the value of **navBarWidth** is within the value range specified by **navBarWidthRange**, **navBarWidth** is set according to the following rules:<br>Value of **minNavBarWidth** + Value of **minContentWidth** + Divider width (1 vp) > = Component width: The value of **navBarWidth** is changed to that of **minNavBarWidth**.<br>Value of **minNavBarWidth** + Value of **minContentWidth** + Divider width (1 vp) < Component width and Value of **navBarWidth** + Value of **minContentWidth** + Divider width (1 vp) > = Component width: The value of **navBarWidth** is changed to Component width - Value of **minContentWidth** - Divider width (1 vp).<br>Value of **minNavBarWidth** + Value of **minContentWidth** + Divider width (1 vp) < Component width and Value of **navBarWidth** + Value of **minContentWidth** + Divider width (1 vp) < Component width: The value of **navBarWidth** is the set value. <br>3. When the component size is decreased, the content area is shrunk until its width reaches the value defined by **minContentWidth**, and then the navigation bar is shrunk until its width reaches the value defined by **minNavBarWidth**; if the component size is further decreased, the content area is further shrunk until it disappears, and then navigation bar is shrunk.<br>4. When the navigation bar is set to a fixed size and the component size is continuously decreased, the navigation bar is shrunk.<br>5. If only **navBarWidth** is set, the width of the navigation bar is fixed at the value of **navBarWidth**, and the divider cannot be dragged.|
| Auto  | In API version 9 and earlier versions: If the window width is greater than or equal to 520 vp, the Split mode is used; otherwise, the Stack mode is used.<br>In API version 10 and later versions: If the window width is greater than or equal to 600 vp, the Split mode is used; otherwise, the Stack mode is used. 600 vp = minNavBarWidth (240 vp) + minContentWidth (360 vp).|

## TitleHeight<sup>9+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name         | Description                        |
| ----------- | -------------------------- |
| MainOnly    | Recommended height (56 vp) of the title bar when only the main title is available.     |
| MainWithSub | Recommended height (82 vp) of the title bar when both the main title and subtitle exist.|

## NavigationOperation<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name   | Description |
|---------|------|
|PUSH | The transition is enter transition.|
|POP | The transition is exit transition.|
| REPLACE | The transition is page replacement.|

## NavigationTitleOptions<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type           | Mandatory  | Description             |
| ------ | ------------- | ---- | --------------- |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor)  | No   | Background color of the title bar. If this parameter is not set, the default color is used.|
| backgroundBlurStyle   | [BlurStyle](ts-appendix-enums.md#blurstyle9)        | No   | Background blur style of the title bar. If this parameter is not set, the background blur effect is disabled.|

## NavigationToolbarOptions<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type           | Mandatory  | Description             |
| ------ | ------------- | ---- | --------------- |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor)  | No   | Background color of the toolbar. If this parameter is not set, the default color is used.|
| backgroundBlurStyle   | [BlurStyle](ts-appendix-enums.md#blurstyle9)        | No   | Background blur style of the toolbar. If this parameter is not set, the background blur effect is disabled.|

## Example

### Example 1

```ts
// xxx.ets
class A {
  text: string = ''
  num: number = 0
}

@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State currentIndex: number = 0

  @Builder NavigationTitle() {
    Column() {
      Text('Title')
        .fontColor('#182431')
        .fontSize(30)
        .lineHeight(41)
        .fontWeight(700)
      Text('subtitle')
        .fontColor('#182431')
        .fontSize(14)
        .lineHeight(19)
        .opacity(0.4)
        .margin({ top: 2, bottom: 20 })
    }.alignItems(HorizontalAlign.Start)
  }

  @Builder NavigationMenus() {
    Row() {
      Image('resources/base/media/ic_public_add.svg')
        .width(24)
        .height(24)
      Image('resources/base/media/ic_public_add.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
      Image('common/ic_public_more.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
    }
  }

  build() {
    Column() {
      Navigation() {
        TextInput({ placeholder: 'search...' })
          .width('90%')
          .height(40)
          .backgroundColor('#FFFFFF')
          .margin({ top: 8 })

        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.arr, (item: number) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(72)
                .backgroundColor('#FFFFFF')
                .borderRadius(24)
                .fontSize(16)
                .fontWeight(500)
                .textAlign(TextAlign.Center)
            }
          }, (item: number) => item.toString())
        }
        .height(324)
        .width('100%')
        .margin({ top: 12, left: '10%' })
      }
      .title(this.NavigationTitle)
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Full)
      .toolbarConfiguration([
        {
          value: $r("app.string.navigation_toolbar_add"),
          icon: $r("app.media.ic_public_highlightsed")
        },
        {
          value: $r("app.string.navigation_toolbar_app"),
          icon: $r("app.media.ic_public_highlights")
        },
        {
          value: $r("app.string.navigation_toolbar_collect"),
          icon: $r("app.media.ic_public_highlights")
        }
      ])
      .hideTitleBar(false)
      .hideToolBar(false)
      .onTitleModeChange((titleModel: NavigationTitleMode) => {
        console.info('titleMode' + titleModel)
      })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![en-us_image_navigation](figures/en-us_image_navigation.png)



### Example 2
```ts
// Index.ets

@Entry
@Component
struct NavigationExample {
  pageInfos: NavPathStack = new NavPathStack()
  isUseInterception: boolean = false;

  registerInterception() {
    this.pageInfos.setInterception({
      willShow: (from: NavDestinationContext | "navBar", to: NavDestinationContext | "navBar",
                 operation: NavigationOperation, animated: boolean) => {
        if (!this.isUseInterception) {
          return;
        }
        if (typeof to === "string") {
          console.log("target page is navigation home");
          return;
        }
        // redirect target page.Change pageTwo to pageOne.
        let target: NavDestinationContext = to as NavDestinationContext;
        if (target.pathInfo.name === 'pageTwo') {
          target.pathStack.pop();
          target.pathStack.pushPathByName('pageOne', null);
        }
      },
      didShow: (from: NavDestinationContext | "navBar", to: NavDestinationContext | "navBar",
                operation: NavigationOperation, isAnimated: boolean) => {
        if (!this.isUseInterception) {
          return;
        }
        if (typeof from === "string") {
          console.log("current transition is from navigation home");
        } else {
          console.log(`current transition is from  ${(from as NavDestinationContext).pathInfo.name}`)
        }
        if (typeof to === "string") {
          console.log("current transition to is navBar");
        } else {
          console.log(`current transition is to ${(to as NavDestinationContext).pathInfo.name}`);
        }
      },
      modeChange: (mode: NavigationMode) => {
        if (!this.isUseInterception) {
          return;
        }
        console.log(`current navigation mode is ${mode}`);
      }
    })
  }

  build() {
    Navigation(this.pageInfos) {
      Column() {
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.pushPath({ name:'pageOne'}) // Push the navigation destination page specified by name to the navigation stack.
          })
        Button('use interception', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.isUseInterception = !this.isUseInterception;
            if (this.isUseInterception) {
              this.registerInterception();
            } else {
              this.pageInfos.setInterception(undefined);
            }
          })
      }
    }.title('NavIndex')
  }
}
```
```ts
// PageOne.ets
class TmpClass{
  count:number=10
}

@Builder
export function PageOneBuilder(name: string, param: Object) {
  PageOne()
}

@Component
export struct PageOne {

  pageInfos: NavPathStack = new NavPathStack()

  build() {
    NavDestination() {
      Column() {
        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            let tmp = new TmpClass()
            this.pageInfos.pushPathByName('pageTwo', tmp) // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack.
          })
        Button('popToname', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.popToName('pageTwo') // Pop the first navigation destination page that matches the value of name to the top of the navigation stack.
            console.log('popToName' + JSON.stringify(this.pageInfos), 'Return value' + JSON.stringify(this.pageInfos.popToName('pageTwo')))
          })
        Button('popToIndex', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.popToIndex(1) // Return the navigation stack to the navigation destination page that matches the value of index.
            console.log('popToIndex' + JSON.stringify(this.pageInfos))
          })
        Button('moveToTop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.moveToTop('pageTwo') // Move to the top of the navigation stack the first navigation destination page that matches the value of name.
            console.log('moveToTop' + JSON.stringify(this.pageInfos), 'Return value' + JSON.stringify(this.pageInfos.moveToTop('pageTwo')))
          })
        Button('moveIndexToTop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.moveIndexToTop(1) // Move to the top of the navigation stack the navigation destination page that matches the value of index.
            console.log('moveIndexToTop' + JSON.stringify(this.pageInfos))
          })
        Button('clear', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.clear() // Clear the navigation stack.
          })
        Button('get', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            console.log('-------------------')
            console.log('Obtained the names of all pages in the navigation stack', JSON.stringify(this.pageInfos.getAllPathName()))
            console.log('Obtained parameter information of the navigation destination page specified by index', JSON.stringify(this.pageInfos.getParamByIndex(1)))
            console.log('Obtained parameter information of all the navigation destination pages specified by name', JSON.stringify(this.pageInfos.getParamByName('pageTwo')))
            console.log('Obtained the index information of all the navigation destination pages specified by name', JSON.stringify(this.pageInfos.getIndexByName('pageOne'))))
            console.log ('Obtained the stack size', JSON.stringify (this.pageInfos.size ()))
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      const popDestinationInfo = this.pageInfos.pop() // Pop the top element out of the navigation stack.
      console.log('pop' + 'Return value' + JSON.stringify(popDestinationInfo))
      return true
    }).onReady((context: NavDestinationContext) => {
      this.pageInfos = context.pathStack
    })
  }
}
```
```ts
// PageTwo.ets
@Builder
export function PageTwoBuilder(name: string, param: Object) {
  PageTwo()
}

@Component
export struct PageTwo {
  pathStack: NavPathStack = new NavPathStack()

  private menuItems: Array<NavigationMenuItem> = [
    {
      value: "1",
      icon: 'resources/base/media/undo.svg',
    },
    {
      value: "2",
      icon: 'resources/base/media/redo.svg',
      isEnabled: false,
    },
    {
      value: "3",
      icon: 'resources/base/media/ic_public_ok.svg',
      isEnabled: true,
    }
  ]

  build() {
    NavDestination() {
      Column() {
        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.pushPathByName('pageOne', null)
          })
      }.width('100%').height('100%')
    }.title('pageTwo')
    .menus(this.menuItems)
    .onBackPressed(() => {
      this.pathStack.pop()
      return true
    })
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
      console.log("current page config info is " + JSON.stringify(context.getConfigInRouteMap()))
    })
  }
}
```

```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5.
// route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    },
    {
      "name": "pageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder"
    }
  ]
}
```
![navigation.gif](figures/navigation.gif)

### Example 3

This example demonstrates how to set a custom transition animation for each subpage in **\<NavDestination>**.

```ts
// Index.ets
import { CustomTransition, AnimateCallback } from './CustomNavigationUtils'

@Entry
@Component
struct NavigationExample {
  pageInfos: NavPathStack = new NavPathStack()

  aboutToAppear() {
    if (this.pageInfos === undefined) {
      this.pageInfos = new NavPathStack();
    }
    this.pageInfos.pushPath({name: 'pageOne'}, false)
  }

  build() {
    Navigation(this.pageInfos) {
    }.title('NavIndex')
    .hideNavBar(true)
    .customNavContentTransition((from: NavContentInfo, to: NavContentInfo, operation: NavigationOperation) => {
      if (from.mode == NavDestinationMode.DIALOG || to.mode == NavDestinationMode.DIALOG) {
        return undefined;
      }
      console.log(`current info: ${to.name}, index: ${to.index}, mode: ${to.mode}`);
      console.log(`pre info: ${from.name}, index: ${from.index}, mode: ${from.mode}`);
      console.log(`operation: ${operation}`)
      if (from.index === -1 || to.index === -1) {
        return undefined;
      }
      let customAnimation: NavigationAnimatedTransition = {
        onTransitionEnd: (isSuccess: boolean)=>{
          console.log(`current transition result is ${isSuccess}`);
        },
        timeout: 700,
        // When the transition starts, the system calls this method and passes in the transition context proxy object.
        transition: (transitionProxy: NavigationTransitionProxy)=>{
          console.log("trigger transition callback");
          // Obtain the corresponding transition animation callback from the CustomTransition class based on the sequence of subpages.
          let fromParam: AnimateCallback = CustomTransition.getInstance().getAnimateParam(from.index);
          let toParam: AnimateCallback = CustomTransition.getInstance().getAnimateParam(to.index);
          if (fromParam.start != undefined) {
            fromParam.start(operation == NavigationOperation.PUSH, true);
          }
          if (toParam.start != undefined) {
            toParam.start(operation == NavigationOperation.PUSH, false);
          }
          animateTo({duration: 400, onFinish: ()=>{
            if (fromParam.onFinish != undefined) {
              fromParam.onFinish(operation === NavigationOperation.PUSH, true);
            }
            if (toParam.onFinish != undefined) {
              toParam.onFinish(operation === NavigationOperation.PUSH, true);
            }
            transitionProxy.finishTransition();
          }}, ()=>{
            if (fromParam.finish != undefined) {
              fromParam.finish(operation === NavigationOperation.PUSH, true);
            }
            if (toParam.finish != undefined) {
              toParam.finish(operation === NavigationOperation.PUSH, false);
            }
          })
        }
      };
      return customAnimation;
    })
  }
}
```

```ts
// PageOne.ets
import {CustomTransition} from './CustomNavigationUtils'

@Builder
export function PageOneBuilder(name: string, param: Object) {
  PageOne()
}

@Component
export struct PageOne {
  pageInfos: NavPathStack = new NavPathStack()
  @State x: number = 0
  @State scaleVal: number = 1
  pageId: number = 0;

  aboutToAppear() {
    this.pageId = this.pageInfos.getAllPathName().length - 1;
    CustomTransition.getInstance().registerNavParam(this.pageId, (isPush: boolean, isExit: boolean) => {
      this.x = isExit ? 0 : 300;
    }, (isPush: boolean, isExit: boolean)=> {
      this.x = isExit ? -300 : 0;
    }, (isPush: boolean, isExit: boolean) => {
      this.x = 0;
    }, 200);
  }

  build() {
    NavDestination() {
      Column() {
        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.pushPathByName('pageTwo', null) // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack.
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .mode(NavDestinationMode.STANDARD)
    .onBackPressed(() => {
      const popDestinationInfo = this.pageInfos.pop() // Pop the top element out of the navigation stack.
      console.log('pop' + 'Return value' + JSON.stringify(popDestinationInfo))
      return true
    })
    .onDisAppear(()=>{
      CustomTransition.getInstance().unRegisterNavParam(this.pageId)
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfos = context.pathStack
    })
    .translate({x: this.x, y: 0, z: 0})
    .backgroundColor(Color.White)
  }
}
```
```ts
// PageTwo.ets
import {CustomTransition} from './CustomNavigationUtils'

@Builder
export function PageTwoBuilder(name: string, param: Object) {
  PageTwo()
}

@Component
export struct PageTwoTemp {
  pathInfo: NavPathStack = new NavPathStack()
  @State x: number = 300
  pageId: number = 0

  aboutToAppear() {
    this.pageId = this.pageInfos.getAllPathName().length - 1;
    CustomTransition.getInstance().registerNavParam(this.pageId, (isPush: boolean, isExit: boolean)=>{
      console.log("current page is pageOne")
      this.x = isExit ? 0 : isPush ? 300 : -300;
    }, (isPush: boolean, isExit: boolean)=>{
      this.x = isExit ? isPush ? -300 : 300 : 0;
    }, (isPush: boolean, isExit: boolean) => {
      this.x = 0;
    }, 2000)
  }

  build() {
    NavDestination() {
      Column() {
        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.pushPathByName('pageOne', null) // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack.
          })
      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      const popDestinationInfo = this.pageInfos.pop() // Pop the top element out of the navigation stack.
      console.log('pop' + 'Return value' + JSON.stringify(popDestinationInfo))
      return true
    })
    .onDisAppear(()=>{
      CustomTransition.getInstance().unRegisterNavParam(this.pageId)
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfos = context.pathStack;
    })
    .opacity(0.5)
    .translate({x: this.x})
    .backgroundColor(Color.White)
  }
}
```
```ts
// CustomNavigationUtils.ts
// Custom API to save the transition animation callback and parameters related to a page.
export interface AnimateCallback {
  finish: ((isPush: boolean, isExit: boolean) => void | undefined) | undefined;
  start: ((isPush: boolean, isExit: boolean) => void | undefined) | undefined;
  onFinish: ((isPush: boolean, isExit: boolean) => void | undefined) | undefined;
  timeout: (number | undefined) | undefined;
}
const customTransitionMap: Map<number, AnimateCallback> = new Map()
export class CustomTransition {
  private constructor() {

  }

  static delegate = new CustomTransition();

  static getInstance() {
    return CustomTransition.delegate;
  }

  // Register the animation callback of a page.
  // startCallback: used to set the page status when the animation starts.
  // endCallback: used to set the page status when the animation ends.
  // onFinish: used to perform operations on the page after the animation ends.
  // timeout: timeout for ending the transition.
  registerNavParam(name: number, startCallback: (operation: boolean, isExit: boolean) => void,
                   endCallback:(operation: boolean, isExit: boolean) => void,
                   onFinish: (opeation: boolean, isExit: boolean) => void, timeout: number): void {

    if (customTransitionMap.has(name)) {
      let param = customTransitionMap.get(name);
      if (param != undefined) {
        param.start = startCallback;
        param.finish = endCallback;
        param.timeout = timeout;
        param.onFinish = onFinish;
        return;
      }
    }
    let params: AnimateCallback = {timeout: timeout, start: startCallback, finish: endCallback, onFinish: onFinish};
    customTransitionMap.set(name, params);
  }

  unRegisterNavParam(name: number): void {
    customTransitionMap.delete(name);
  }

  getAnimateParam(name: number): AnimateCallback {
    let result: AnimateCallback = {
      start: customTransitionMap.get(name)?.start,
      finish: customTransitionMap.get(name)?.finish,
      timeout: customTransitionMap.get(name)?.timeout,
      onFinish: customTransitionMap.get(name)?.onFinish
    };
    return result;
  }
}
```
```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5.
// route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    },
    {
      "name": "pageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder"
    }
  ]
}
```

![customNavigation.gif](figures/customNavigation.gif)

### Example 4
```ts
// Index.ets

@Entry
@Component
struct NavigationExample {
  pageInfo: NavPathStack = new NavPathStack()

  build() {
    Navigation(this.pageInfo) {
      Column() {
        Button('StartTest', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
          })
      }
    }.title('NavIndex')
  }
}
```
```ts
// PageOne.ets
import { BusinessError } from '@ohos.base';

class TmpClass{
  count:number = 10
}

class ParamWithOp {
  operation: number = 1
  count: number = 10
}

@Builder
export function PageOneBuilder(name: string, param: Object) {
  PageOne()
}

@Component
export struct PageOne {
  pageInfo: NavPathStack = new NavPathStack();
  @State message: string = 'Hello World'

  build() {
    NavDestination() {
      Column() {
        Text(this.message)
          .width('80%')
          .height(50)
          .margin(10)

        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(()=>{
            this.pageInfo.pushPath({name: 'pageTwo', param: new ParamWithOp(), onPop: (popInfo: PopInfo)=>{
              this.message = '[pushPath]last page is: ' + popInfo.info.name + ', result: ' + JSON.stringify(popInfo.result);
            }}); // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack. Use the onPop callback to receive the page processing result.
          })

        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(() => {
            let tmp = new TmpClass()
            this.pageInfo.pushPathByName('pageTwo', tmp, (popInfo)=>{
              this.message = '[pushPathByName]last page is: ' + popInfo.info.name + ', result: ' + JSON.stringify(popInfo.result);
            }); // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack. Use the onPop callback to receive the page processing result.
          })

        Button('pushDestination', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(()=>{
            let tmp = new TmpClass()
            // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack. Use the onPop callback to receive the page processing result.
            this.pageInfo.pushDestination({name: 'pageTwo', param: new ParamWithOp(), onPop: (popInfo: PopInfo)=>{
              this.message = '[pushDestination]last page is: ' + popInfo.info.name + ', result: ' + JSON.stringify(popInfo.result);
            }}).catch((error: BusinessError)=>{
              console.error(`[pushDestination]failed, error code = ${error.code}, error.message = ${error.message}.`);
            }).then(()=>{
              console.error('[pushDestination]success.');
            });
          })

        Button('pushDestinationByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(()=>{
            let tmp = new TmpClass()
            // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack. Use the onPop callback to receive the page processing result.
            this.pageInfo.pushDestinationByName('pageTwo', tmp, (popInfo)=>{
              this.message = '[pushDestinationByName]last page is: ' + popInfo.info.name + ', result: ' + JSON.stringify(popInfo.result);
            }).catch((error: BusinessError)=>{
              console.error(`[pushDestinationByName]failed, error code = ${error.code}, error.message = ${error.message}.`);
            }).then(()=>{
              console.error('[pushDestinationByName]success.');
            });
          })

        Button('pushPathWithoutOnPop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(()=>{
            this.pageInfo.pushPath({name: 'pageTwo', param: new ParamWithOp()}); // Push the navigation destination page specified by name to the navigation stack.
          })

        Button('pushPathByNameWithoutOnPop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(() => {
            let tmp = new TmpClass()
            this.pageInfo.pushPathByName('pageTwo', tmp); // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack.
          })

        Button('pushDestinationWithoutOnPop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(()=>{
            let tmp = new TmpClass()
            // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack. Use the onPop callback to receive the page processing result.
            this.pageInfo.pushDestination({name: 'pageTwo', param: new ParamWithOp()})
              .catch((error: BusinessError)=>{
              console.error(`[pushDestinationWithoutOnPop]failed, error code = ${error.code}, error.message = ${error.message}.`);
            }).then(()=>{
              console.error('[pushDestinationWithoutOnPop]success.');
            });
          })

        Button('pushDestinationByNameWithoutOnPop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(() => {
            let tmp = new TmpClass()
            // Push the navigation destination page specified by name, with the data specified by param, to the navigation stack.
            this.pageInfo.pushDestinationByName('pageTwo', tmp)
              .catch((error: BusinessError)=>{
                console.error(`[pushDestinationByNameWithoutOnPop]failed, error code = ${error.code}, error.message = ${error.message}.`);
              }).then(()=>{
              console.error('[pushDestinationByNameWithoutOnPop]success.');
            });
          })

        Button('clear', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(10)
          .onClick(() => {
            this.pageInfo.clear(); // Clear the navigation stack.
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop({number: 1}) // Pop the top element out of the navigation stack.
      return true
    }).onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}
```
```ts
// PageTwo.ets

class resultClass {
  constructor(count: number) {
    this.count = count;
  }
  count: number = 10
}

@Builder
export function PageTwoBuilder(name: string, pram: Object) {
  PageTwo()
}

@Component
export struct PageTwo {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    NavDestination() {
      Column() {
        Button('pop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.pop(new resultClass(1)); // Return to the previous page and pass in the processing result to the onPop callback of push.
          })

        Button('popToName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.popToName('pageOne', new resultClass(11)); // Move the first navigation destination page that matches name to the top of the navigation stack, and pass in the processing result to the onPop callback of push.
          })

        Button('popToIndex', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.popToIndex(0, new resultClass(111)); // Move the navigation destination page specified by index to the top of the navigation stack, and pass in the processing result to the onPop callback of push.
          })

        Button('popWithoutResult', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.pop();
          })

        Button('popToNameWithoutResult', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.popToName('pageOne');
          })

        Button('popToIndexWithoutResult', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pathStack.popToIndex(0);
          })
      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pathStack.pop(new resultClass(0)); // Return to the previous page and pass in the processing result to the onPop callback of push.
      return true;
    }).onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack
    })
  }
}
```
```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5.
// route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    },
    {
      "name": "pageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder"
    }
  ]
}
```
![navigationWithOnPop.gif](figures/navigationWithOnPop.gif)

### Example 5

```ts
// Set the background color and blur style of the title bar and toolbar of the <Navigation> component.
@Entry
@Component
struct NavigationExample {
  @State pathStack: NavPathStack = new NavPathStack();
  @State switchColor: boolean = false;
  @State switchBlur: boolean = false;

  @Builder
  BackgroundBuilder() {
    Row() {
      Column() {}
      .layoutWeight(1)
      .height('100%')
      .backgroundColor(Color.Red)
      Column() {}
      .layoutWeight(1)
      .height('100%')
      .backgroundColor(Color.Green)
      Column() {}
      .layoutWeight(1)
      .height('100%')
      .backgroundColor(Color.Blue)
    }
    .height('100%')
  }

  build() {
    Navigation(this.pathStack) {
      Column() {
        Button('switch color', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            console.log(`testTag switchColor`)
            this.switchColor = !this.switchColor;
          })
        Button('switch blur', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            console.log(`testTag switchBlur`)
            this.switchBlur = !this.switchBlur;
          })
      }
      .width('100%')
      .height('100%')
    }
    // You can use a custom background to make the background blur effect more noticeable.
    .background(this.BackgroundBuilder)
    .width('100%')
    .height('100%')
    // You can set the background color and background blur style of the title bar.
    .title("NavTitle", {
      backgroundColor: this.switchColor ? "#90D1D2D3" : "#90121314",
      backgroundBlurStyle: this.switchBlur ? BlurStyle.BACKGROUND_THICK : BlurStyle.BACKGROUND_THIN
    })
    // You can set the background color and background blur style of the toolbar.
    .toolbarConfiguration([
      {value: 'a'},
      {value: 'b'},
      {value: 'c'},
    ], {
      backgroundColor: this.switchColor ? "#90D1D2D3" : "#90121314",
      backgroundBlurStyle: this.switchBlur ? BlurStyle.BACKGROUND_THICK : BlurStyle.BACKGROUND_THIN
    })
  }
}
```
![navigationColorBlur.gif](figures/navigationColorBlur.gif)

### Example 6

```ts
// Obtain the parent navigation path stack for a nested <Navigation> component.
@Entry
@Component
struct NavigationExample1 {
  @State childNavStack: NavPathStack = new NavPathStack();

  build() {
    Navigation() {
      Stack({alignContent: Alignment.Center}) {
        Navigation(this.childNavStack) {
          Button('push Path to parent Navigation', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              // The parent the parent navigation path stack can be obtained.
              let parentStack = this.childNavStack.getParent();
              parentStack?.pushPath({ name: "pageOne"})
            })
        }
        .clip(true)
        .backgroundColor(Color.Orange)
        .width('80%')
        .height('80%')
        .title('ChildNavigation')
      }
      .width('100%')
      .height('100%')
    }
    .backgroundColor(Color.Green)
    .width('100%')
    .height('100%')
    .title('ParentNavigation')
  }
}
```
```ts
// PageOne.ets
  @Builder
  export function PageOneBuilder(name: string) {
    NavDestination() {
      Text("this is " + name)
    }
    .title(name)
  }
```
```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5.
// route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    }
  ]
}
```
![navPathStackGetParent.gif](figures/navPathStackGetParent.gif)

### Example 7

```ts
// This example demonstrates the following:
// 1. The navigation stack operation can be conducted even when NavPathStack is not declared as a state variable.
// 2. The <NavDestination> can obtain the corresponding NavPathInfo and NavPathStack through the onReady event.
class PageParam {
  constructor(num_: number) {
    this.num = num_;
  }
  num: number = 0;
}

@Builder
export function PageOneBuilder(name: string, param: Object) {
  PageOne()
}

@Component
struct PageOne {
  private stack: NavPathStack | null = null;
  private name: string = "";
  private paramNum: number = 0;

  build() {
    NavDestination() {
      Column() {
        Text("NavPathInfo: name: " + this.name + ", paramNum: " + this.paramNum)
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            if (this.stack) {
              let p = new PageParam(this.paramNum + 1);
              this.stack.pushPath({name: "pageOne", param: p});
            }
          })
        Button('pop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.stack?.pop()
          })
      }
      .width('100%')
      .height('100%')
    }
    .title('pageOne')
    .onReady((ctx: NavDestinationContext) => {
      // The passed NavPathInfo and the owning NavPathStack objects can be obtained for <NavDestination>.
      try {
        this.name = ctx?.pathInfo?.name;
        this.paramNum = (ctx?.pathInfo?.param as PageParam)?.num;
        this.stack = ctx.pathStack;
      } catch (e) {
        console.log(`testTag onReady catch exception: ${JSON.stringify(e)}`)
      }
    })
  }
}

@Entry
@Component
struct NavigationExample2 {
  private stack : NavPathStack = new NavPathStack();

  build() {
    Navigation(this.stack) {
      Stack({alignContent: Alignment.Center}) {
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            let p = new PageParam(1);
            this.stack.pushPath({ name: "pageOne", param: p })
          })
      }
      .width('100%')
      .height('100%')
    }
    .width('100%')
    .height('100%')
    .title('Navigation')
  }
}
```
```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5.
// route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/Index.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    }
  ]
}
```
![navigationOnReady1.gif](figures/navigationOnReady1.gif)

### Example 8

```ts
// This example demonstrates the lifecycle timing of <NavDestination>.
@Builder
export function PageOneBuilder(name: string, param: Object) {
  PageOneComponent()
}

@Component
struct PageOneComponent {
  private stack: NavPathStack | null = null;
  @State eventStr: string = "";

  build() {
    NavDestination() {
      Column() {
        Text("event: " + this.eventStr)
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            if (this.stack) {
              this.stack.pushPath({name: "pageOne"});
            }
          })
        Button('pop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.stack?.pop()
          })
      }
      .width('100%')
      .height('100%')
    }
    .title('pageOne')
    .onAppear(() => { this.eventStr += "<onAppear>"; })
    .onDisAppear(() => { this.eventStr += "<onDisAppear>"; })
    .onShown(() => { this.eventStr += "<onShown>"; })
    .onHidden(() => { this.eventStr += "<onHidden>"; })
    // onReady is called before onAppear.
    .onReady((ctx: NavDestinationContext) => {
      try {
        this.eventStr += "<onReady>";
        this.stack = ctx.pathStack;
      } catch (e) {
        console.log(`testTag onReady catch exception: ${JSON.stringify(e)}`)
      }
    })
  }
}

@Entry
@Component
struct NavigationExample3 {
  private stack : NavPathStack = new NavPathStack();

  build() {
    Navigation(this.stack) {
      Stack({alignContent: Alignment.Center}) {
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.stack.pushPath({ name: "pageOne" })
          })
      }
      .width('100%')
      .height('100%')
    }
    .width('100%')
    .height('100%')
    .title('Navigation')
  }
}
```
```json
// Configure {"routerMap": "$profile:route_map"} in the project configuration file module.json5.
// route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/Index.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    }
  ]
}
```
![navigationOnReady2.gif](figures/navigationOnReady2.gif)
