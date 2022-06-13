# tab-content

**\<tab-content>** is a child component of [\<tabs>](js-components-container-tabs.md) and is used to provide the area for displaying the tab content. By default, its height is such that all the remaining space of the **\<tabs>** component is filled. The child components are arranged horizontally. When **\<tab-content>** is used as a child element in a container, the length on the main axis direction must be specified. Otherwise, the child element cannot be displayed.

## Required Permissions

None

## Child Components

Supported

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name       | Type    | Default Value | Mandatory | Description                                                  |
| ---------- | ------- | ------------- | --------- | ------------------------------------------------------------ |
| scrollable | boolean | true          | No        | Whether the tabs can be switched by swiping left or right. The default value is **true**. If this attribute is set to **false**, tab switching is implemented only through the association with **tab-bar**. |

## Styles

Styles in [Universal Styles](js-components-common-styles.md) are supported.

## Events

Events in [Universal Events](js-components-common-events.md) are supported.

## Example

For details, see the [tabs example code](js-components-container-tabs.md).