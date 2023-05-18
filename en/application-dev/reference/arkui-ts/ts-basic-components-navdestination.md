# NavDestination

**\<NavDestination>** is a child component of the **\<NavRouter>** component and represents a destination in the navigation area.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

> **NOTE**
>
> - Supported types of child components: built-in components and custom components, with support for ([if/else](../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.
> - Number of child components: multiple.


## APIs

NavDestination()


## Attributes

In addition to the [backgroundColor](ts-universal-attributes-background.md) attribute, the following attributes are supported.

| Name        | Type                                                    | Description                                                        |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| title        | string \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle) \| [NavigationCustomTitle](ts-basic-components-navigation.md##navigationcustomtitle) | Page title.<br>**NOTE**<br>When the NavigationCustomTitle type is used to set the height, the **titleMode** attribute does not take effect.<br>When the title string is too long: (1) If no subtitle is set, the string is scaled down, wrapped in two lines, and then clipped with an ellipsis (...); (2) If a subtitle is set, the subtitle is scaled down and then clipped with an ellipsis (...).|
| hideTitleBar | boolean                                                      | Whether to hide the title bar.<br>Default value: **false**<br>**true**: Hide the title bar.<br>**false**: Display the title bar.|

## Events

The [universal events](ts-universal-events-click.md) are supported.
