# NavDestination

**\<NavDestination>** is the root container of a destination page and represents the content area of the [\<Navigation>](ts-basic-components-navigation.md) component.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> Since API version 11, this component supports the safe area attribute by default, with the default attribute value being **expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM]))**. You can override this attribute to change the default behavior. In earlier versions, you need to use the [expandSafeArea](ts-universal-attributes-expand-safe-area.md) attribute to implement the safe area feature.


## Child Components

Built-in components and custom components are allowed, with support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.

Number of child components: multiple.


## APIs

NavDestination()


## Attributes

In addition to the [backgroundColor](ts-universal-attributes-background.md#backgroundcolor) attribute, the following attributes are supported.

### title

title(value: string | CustomBuilder | NavDestinationCommonTitle | NavDestinationCustomTitle)

Sets the page title. When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect. When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description      |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| value  | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle9) \| [NavigationCustomTitle](ts-basic-components-navigation.md#navigationcustomtitle9) | Yes  | Page title.|

### hideTitleBar

hideTitleBar(value: boolean)

Specifies whether to hide the title bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|

### mode <sup>11+</sup>

mode(value: NavDestinationMode)

Sets the mode of the navigation destination page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [NavDestinationMode](#navdestinationmode11) | Yes  | Mode of the navigation destination page.<br>Default value: **NavDestinationMode.STANDARD**|

### backButtonIcon<sup>11+</sup>

backButtonIcon(value: ResourceStr | PixelMap)

Sets the icon of the back button on the title bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr) \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) | Yes  | Icon of the back button on the title bar.|

## NavDestinationMode<sup>11+</sup>
| Name  | Description                                      |
| ---- | ---------------------------------------- |
| STANDARD | Standard mode, where the lifecycle of the navigation destination page changes with the standard destination in the **NavPathStack**.                      |
| DIALOG | Dialog mode, where the navigation destination page is transparent by default, and the lifecycle of other navigation destination pages is not affected.   |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onShown<sup>10+</sup>

onShown(callback: () =&gt; void)

Called when the navigation destination page is displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onHidden<sup>10+</sup>

onHidden(callback: () =&gt; void)

Called when the navigation destination page is hidden.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onBackPressed<sup>10+</sup>

This callback takes effect when there is one or more entries in the navigation stack bound to the **\<Navigation>** component. Called when the back button is pressed.

The value **true** means that the back button logic is overridden, and **false** means that the previous page is displayed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onReady<sup>11+</sup>

onReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11)>)

Called when the **\<NavDestination>** component is about to build a child component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## NavDestinationContext<sup>11+</sup>

| Name  | Type    | Description    |
| ---- | ------ | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | Path information of the navigation destination page.|
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | Page stack where the current navigation destination page is located.|

## Example

For details, see [Example in Navigation](ts-basic-components-navigation.md#example-1).
