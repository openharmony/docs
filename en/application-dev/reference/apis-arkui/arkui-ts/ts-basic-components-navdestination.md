# NavDestination

**NavDestination** is the root container of a destination page and represents the content area of the [Navigation](ts-basic-components-navigation.md) component.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> Since API version 11, this component supports the safe area attribute by default, with the default attribute value being **expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM]))**. You can override this attribute to change the default behavior. In earlier versions, you need to use the [expandSafeArea](ts-universal-attributes-expand-safe-area.md) attribute to implement the safe area feature.
>
> The **NavDestination** component must be used in conjunction with the **Navigation** component to act as the root node for the navigation destination page. When used alone, it can only function as a standard container component and does not possess any routing-related attributes or capabilities.
>
> If the lifecycle of a page in the middle of the navigation stack changes, the lifecycle of the destination page at the top of the stack before the transition (**onWillShow**, **onShown**, **onHidden**, **onWillDisappear**) and the lifecycle of the destination page after the transition (**onWillShow**, **onShown**, **onHidden**, **onWillDisappear**) are both triggered at the end.

## Child Components

Built-in components and custom components are allowed, with support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.

Number of child components: multiple.


## APIs

NavDestination()

**Atomic service API**: This API can be used in atomic services since API version 11.

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

Avoid setting layout-related attributes such as the position and size. They may result in display issues on the page.

### title

title(value: string | CustomBuilder | NavDestinationCommonTitle | NavDestinationCustomTitle, options?: NavigationTitleOptions)

Sets the page title. When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect. When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description      |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| value  | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavDestinationCommonTitle](#navdestinationcommontitle) \| [NavDestinationCustomTitle](#navdestinationcustomtitle) | Yes  | Page title.|
| options<sup>12+</sup> | [NavigationTitleOptions](ts-basic-components-navigation.md#navigationtitleoptions11) | No  | Title bar options.|

### hideTitleBar

hideTitleBar(value: boolean)

Specifies whether to hide the title bar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|

### mode <sup>11+</sup>

mode(value: NavDestinationMode)

Sets the type of the navigation destination page. Dynamic modification is not supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [NavDestinationMode](#navdestinationmode11) | Yes  | Mode of the navigation destination page.<br>Default value: **NavDestinationMode.STANDARD**|

### backButtonIcon<sup>11+</sup>

backButtonIcon(value: ResourceStr | PixelMap | SymbolGlyphModifier)

> **NOTE**
>
> The following are not allowed: modify the icon size through the **fontSize** attribute of the **SymbolGlyphModifier** object, change the animation effects through the **effectStrategy** attribute, or change the type of animation effects through the **symbolEffect** attribute.


Sets the icon of the back button on the title bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr) \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [SymbolGlyphModifier<sup>12+</sup>](ts-universal-attributes-attribute-modifier.md)  | Yes  | Icon of the back button on the title bar.|

### menus<sup>12+</sup>

menus(value: Array&lt;NavigationMenuItem&gt; | CustomBuilder)

> **NOTE**
>
> The following are not allowed: modify the icon size through the **fontSize** attribute of the **SymbolGlyphModifier** object, change the animation effects through the **effectStrategy** attribute, or change the type of animation effects through the **symbolEffect** attribute.


Sets the menu items in the upper right corner of the page. If this attribute is not set, no menu item is displayed. When the value type is Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt;, the menu shows a maximum of three icons in portrait mode and a maximum of five icons in landscape mode, with excess icons (if any) placed under the automatically generated **More** icon.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Menu items in the upper right corner of the page.|

### ignoreLayoutSafeArea<sup>12+</sup>

ignoreLayoutSafeArea(types?: Array&lt;LayoutSafeAreaType&gt;, edges?: Array&lt;LayoutSafeAreaEdge&gt;)

Ignores the layout safe area by allowing the component to extend into the non-safe areas of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                              | Mandatory| Description                                                        |
| ------ | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| types  | Array <[LayoutSafeAreaType](ts-types.md#layoutsafeareatype12)> | No  | Types of non-safe areas to extend into.<br>Default value:<br>[LayoutSafeAreaType.SYSTEM] |
| edges  | Array <[LayoutSafeAreaEdge](ts-types.md#layoutsafeareaedge12)> | No  | Edges for expanding the safe area.<br> Default value:<br>[LayoutSafeAreaEdge.TOP, LayoutSafeAreaEdge.BOTTOM]|

>  **NOTE**
>   
>  After **LayoutSafeArea** is set:  
>  When **LayoutSafeAreaType.SYSTEM** is set, the component can extend into the non-safe area if its boundaries overlap with it. For example, if the device's status bar is 100 high, the component must have an absolute vertical offset between 0 and 100 to extend into the non-safe area. 
>   
>  If the component extends into the non-safe area, events triggered within that area (such as click events) might be intercepted by the system. This allows the system to prioritize responses to system components such as the status bar.

### systemBarStyle<sup>12+</sup>

systemBarStyle(style: Optional&lt;SystemBarStyle&gt;)

Sets the style of the system status bar when this **NavDestination** page is displayed in the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type        | Mandatory| Description              |
| ------ | -------------- | ---- | ------------------ |
| style  | Optional&lt;[SystemBarStyle](../js-apis-window.md#systembarstyle12)&gt; | Yes  | Style of the system status bar.|

> **NOTE**
>
> 1. The setting takes effect only when the **NavDestination** component is used in conjunction with the **Navigation** component.
> 2. For other usage restrictions, see the description of [systemBarStyle](ts-basic-components-navigation.md#systembarstyle12) for the **Navigation** component.

## NavDestinationMode<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Description                                      |
| ---- | ---------------------------------------- |
| STANDARD | Standard mode.                      |
| DIALOG | Dialog mode, in which the navigation destination is transparent by default, adding or removing it from the navigation stack does not affect the lifecycle of the lower-layer navigation destination, and the system transition animation is not supported.   |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onShown<sup>10+</sup>

onShown(callback: () =&gt; void)

Called when the navigation destination page is displayed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onHidden<sup>10+</sup>

onHidden(callback: () =&gt; void)

Called when the navigation destination page is hidden.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillAppear<sup>12+</sup>

onWillAppear(callback: Callback\<void>)

Called when the navigation destination is about to be mounted. You can change the navigation stack in this callback function, and the change takes effect in the current frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillShow<sup>12+</sup>

onWillShow(callback: Callback\<void>)

Called when the navigation destination is about to be displayed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillHide<sup>12+</sup>

onWillHide(callback: Callback\<void>)

Called when the navigation destination is about to be hidden.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillDisappear<sup>12+</sup>

onWillDisappear(callback: Callback\<void>)

Called when the navigation destination is about to be unmounted (or when the transition animation, if any, is about to start).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onBackPressed<sup>10+</sup>

onBackPressed(callback: () =&gt; boolean)

This callback takes effect when there is one or more entries in the navigation stack bound to the **Navigation** component. Called when the back button is pressed.

The value **true** means that the back button logic is overridden, and **false** means that the previous page is displayed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onReady<sup>11+</sup>

onReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11)>)

Called when the **NavDestination** component is about to build a child component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## NavDestinationCommonTitle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type    | Mandatory  | Description    |
| ---- | ------ | ---- | ------ |
| main | string | Yes   | Main title.|
| sub  | string | Yes   | Subtitle.|

## NavDestinationCustomTitle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                      | Mandatory  | Description      |
| ------- | ---------------------------------------- | ---- | -------- |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | Yes   | Content of the title bar.|
| height  | [TitleHeight](ts-basic-components-navigation.md#titleheight9) \| [Length](ts-types.md#length) | Yes   | Height of the title bar.|

## NavDestinationContext<sup>11+</sup>

| Name  | Type    | Mandatory  |  Description    |
| ---- | ------ | ----- | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | Yes| Path information of the navigation destination page.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | Yes| Page stack where the current navigation destination page is located.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| navDestinationId<sup>12+</sup> | string | No| Unique ID of the current navigation destination page, which is automatically generated by the system and is irrelevant to the universal attribute **id** of the component.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

### getConfigInRouteMap<sup>12+</sup>

getConfigInRouteMap(): RouteMapConfig |undefined

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type| Description|
| --- | --- |
| [RouteMapConfig](#routemapconfig12) | Route map configuration of the current page.|
| undefined | **undefined**, returned when the page is not configured through the route table.|

## RouteMapConfig<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type  | Description|
| ----  | ---   | ----- |
| name  | string | Page name.|
| pageSourceFile| string | Path of the page in the current package.|
| data | object | Custom data of the page.|

## Example

For details, see [Example in Navigation](ts-basic-components-navigation.md#example-1).
