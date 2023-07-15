# NavDestination

**\<NavDestination>** is a child component of the **\<NavRouter>** component and represents a destination in the navigation area.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported types of child components: built-in components and custom components, with support for ([if/else](../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.

Number of child components: multiple.


## APIs

NavDestination()


## Attributes

In addition to the [backgroundColor](ts-universal-attributes-background.md) attribute, the following attributes are supported.

| Name        | Type                                                    | Description                                                        |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| title        | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle) \| [NavigationCustomTitle](ts-basic-components-navigation.md##navigationcustomtitle) | Page title.<br>**NOTE**<br>When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect.<br>When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).|
| hideTitleBar | boolean                                                      | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.


| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onShown(callback: (param: unknown) =&gt; void)<sup>10+</sup> | Called when the navigation destination page is displayed. **param**: parameter information of the navigation destination page.<br>**NOTE**<br>The **onShown** API will be changed to **onShown(callback: () =&gt; void)**.|
| onHidden(callback: () =&gt; void)<sup>10+</sup> | Called when the navigation destination page is hidden.|
| onBackPressed(callback: () =&gt; boolean)<sup>10+</sup> | Called when the back button is pressed.<br>The value **true** means that the back button logic is overridden, and **false** means that the previous page is displayed.<br>|
