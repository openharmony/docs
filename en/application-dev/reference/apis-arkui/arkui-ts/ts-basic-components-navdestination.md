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

Supported types of child components: built-in components and custom components, with support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.

Number of child components: multiple.


## APIs

NavDestination()


## Attributes

In addition to the [backgroundColor](ts-universal-attributes-background.md) attribute, the following attributes are supported.

| Name        | Type                                                    | Description                                                        |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| title        | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle9) \| [NavigationCustomTitle](ts-basic-components-navigation.md#navigationcustomtitle9) | Page title.<br>**NOTE**<br>When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect.<br>When the title string is too long:<br>(1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...).<br>(2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).|
| hideTitleBar | boolean                                                      | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|
| mode<sup>11+</sup> | [NavDestinationMode](#navdestinationmode11)                                                   | Mode of the navigation destination page.<br>Default value: **NavDestinationMode.STANDARD**|
| backButtonIcon<sup>11+</sup> |   [ResourceStr](ts-types.md#resourcestr)  \|  [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)       | Icon of the back button on the title bar.|

## NavDestinationMode<sup>11+</sup>
| Name  | Description                                      |
| ---- | ---------------------------------------- |
| STANDARD | Standard mode.                      |
| DIALOG | Dialog mode, in which the navigation destination is transparent by default, adding or removing it from the navigation stack does not affect the lifecycle of the lower-layer navigation destination, and the system transition animation is not supported.   |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.


| Name                                                    | Description                                                  |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| onShown(callback: () =&gt; void)<sup>10+</sup>          | Called when the navigation destination page is displayed.    |
| onHidden(callback: () =&gt; void)<sup>10+</sup>         | Called when the navigation destination page is hidden.       |
| onBackPressed(callback: () =&gt; boolean)<sup>10+</sup> | Called when the back button is pressed.<br>This callback takes effect when there is one or more entries in the navigation stack bound to the **\<Navigation>** component.<br/>The value **true** means that the back button logic is overridden, and **false** means that the previous page is displayed. |
| onReady(callback: [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11)>)<sup>11+</sup> | Called when the **\<NavDestination>** component is about to build a child component. |

## NavDestinationContext<sup>11+</sup>

| Name  | Type    | Description    |
| ---- | ------ | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | Path information of the navigation destination page.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | Page stack where the current navigation destination page is located.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## Example

For details, see [Example in Navrouter](ts-basic-components-navrouter.md#example).
