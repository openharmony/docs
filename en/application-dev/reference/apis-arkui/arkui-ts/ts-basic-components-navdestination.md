# NavDestination

**\<NavDestination>** is the root container of a destination page and represents the content area of the [\<Navigation>](ts-basic-components-navigation.md) component.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> Since API version 11, this component supports the safe area attribute by default, with the default attribute value being **expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM]))**. You can override this attribute to change the default behavior. In earlier versions, you need to use the [expandSafeArea](ts-universal-attributes-expand-safe-area.md) attribute to implement the safe area feature.
>
> **\<NavDestination>** must be used together with **\<Navigation>** as the root node of its destination page.

## Child Components

Built-in components and custom components are allowed, with support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.

Number of child components: multiple.


## APIs

NavDestination()

**Atomic service API**: This API can be used in atomic services since API version 11.

## Attributes

In addition to the [backgroundColor](ts-universal-attributes-background.md#backgroundcolor) attribute, the following attributes are supported.

### title

title(value: string | CustomBuilder | NavDestinationCommonTitle | NavDestinationCustomTitle)

Sets the page title. When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect. When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description      |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| value  | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle9) \| [NavigationCustomTitle](ts-basic-components-navigation.md#navigationcustomtitle9) | Yes  | Page title.|

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

Sets the mode of the navigation destination page.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [NavDestinationMode](#navdestinationmode11) | Yes  | Mode of the navigation destination page.<br>Default value: **NavDestinationMode.STANDARD**|

### backButtonIcon<sup>11+</sup>

backButtonIcon(value: ResourceStr | PixelMap)

Sets the icon of the back button on the title bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr) \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) | Yes  | Icon of the back button on the title bar.|

### menus<sup>12+</sup>

menus(value: Array&lt;NavigationMenuItem&gt; | CustomBuilder)

Sets the menu items in the upper right corner of the page. If this attribute is not set, no menu item is displayed. When the value type is Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt;, the menu shows a maximum of three icons in portrait mode and a maximum of five icons in landscape mode, with excess icons (if any) placed under the automatically generated **More** icon.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | No  | Menu items in the upper right corner of the page.|

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

onWillAppear(callback: () =&gt; void)

Called when the navigation destination is about to be mounted. You can change the navigation stack in this callback function, and the change takes effect in the current frame.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillShow<sup>12+</sup>

onWillShow(callback: () =&gt; void)

Called when the navigation destination is about to be displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillHide<sup>12+</sup>

onWillHide(callback: () =&gt; void)

Called when the navigation destination is about to be hidden.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillDisappear<sup>12+</sup>

onWillDisappear(callback: () =&gt; void)

Called when the navigation destination is about to be unmounted (or when the transition animation, if any, is about to start).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onBackPressed<sup>10+</sup>

This callback takes effect when there is one or more entries in the navigation stack bound to the **\<Navigation>** component. Called when the back button is pressed.

The value **true** means that the back button logic is overridden, and **false** means that the previous page is displayed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onReady<sup>11+</sup>

onReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11)>)

Called when the **\<NavDestination>** component is about to build a child component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## NavDestinationContext<sup>11+</sup>

| Name  | Type    | Description    |
| ---- | ------ | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | Path information of the navigation destination page.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | Page stack where the current navigation destination page is located.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

### getConfigInRouteMap<sup>12+</sup>

getConfigInRouteMap(): RouteMapConfig |undefined

**Return value**

| Type| Description|
| --- | --- |
| [RouteMapConfig](#routemapconfig12) | Route map configuration of the current page.|
| undefined | **undefined**, returned when the page is not configured through the route table.|

## RouteMapConfig<sup>12+</sup>

| Name  | Type  | Description|
| ----  | ---   | ----- |
| name  | string | Page name.|
| pageSourceFile| string | Path of the page in the current package.|
| data | object | Custom data of the page.|

## Example

For details, see [Example in Navigation](ts-basic-components-navigation.md#example-1).
