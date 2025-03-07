# tab-content

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

**<tab-content\>** is a child component of **[<tabs\>](js-components-container-tabs.md)** and is used to provide the area for displaying the tab content. By default, its height is such that all the remaining space of the **<tabs\>** component is filled. The child components are arranged horizontally. When **<tab-content\>** is used as a child element in a container, its length along the main axis must be specified. Otherwise, it cannot be displayed. **\<tab-content>** does not support page scrolling. If page scrolling is required, consider nesting a list.

## Required Permissions

None


## Child Components

Supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| scrollable | boolean | No| Whether the tabs can be switched by swiping left or right. The default value is **true**. If this attribute is set to **false**, tab switching is implemented only through the association with **tab-bar**.|


## Styles

The [universal styles](js-components-common-styles.md) are supported.


## Events

The [universal events](js-components-common-events.md) are supported.


## Example

For details, see **Example** in [tabs](js-components-container-tabs.md#example).
