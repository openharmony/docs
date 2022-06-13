#  list-item

**\<list-item>** is a child component of the **<[list](js-components-container-list.md)>** component and is used to display items in a list. You can customize the width of each **\<list-item>**. However, if you retain the default value **stretch** of **align-items** for the parent component **\<list>**, the width of **\<list-item>** is equal to that of **\<list>**. You can set **align-items** to other values rather than **stretch** to make the customized **\<list-item-group>** width take effect.

## Required Permissions

None

## Child Components

This component supports only one child component.

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name          | Type    | Default Value | Mandatory | Description                                                  |
| ------------- | ------- | ------------- | --------- | ------------------------------------------------------------ |
| type          | string  | default       | No        | Type of the list-item. A list can contain multiple list-item types. The same type of list items should have the same view layout after being rendered. When the type is fixed, replace the **if** attribute with the **show** attribute to ensure that the view layout remains unchanged. |
| primary       | boolean | false         | No        | The value **true** indicates that the item is the primary item in the group, which is the item that appears in a collapsed group. If there is more than one item marked as primary, the first one is the primary item. If there is no item marked as primary, the first item is the primary item. |
| section       | string  | -             | No        | String used to match this item. This attribute can be left empty. The value cannot be dynamically updated. In a list item group, only the string set for the primary item is valid. |
| sticky        | string  | none          | No        | Whether the current item sticks in place at the top, and the effect when it disappears. This attribute supports vertical lists only and is invalid for items in a group.  <br>- **none**: The current item does not stick at the top. <br>- **normal**: The current item sticks at the top and disappears with a sliding effect. <br>- **opacity**: The current item sticks at the top and disappears gradually. This option is only supported on wearables. |
| clickeffect<sup>5+</sup> | boolean | true          | No        | Whether an effect is displayed when the current item is clicked.  <br>- **false**: No effect is displayed when the item is clicked. <br>- **true**: An effect is displayed when the item is clicked. |

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name        | Type      | Default Value | Mandatory | Description                                                  |
| ----------- | --------- | ------------- | --------- | ------------------------------------------------------------ |
| column-span | \<number> | 1             | No        | Number of columns occupied by the current list-item in the list. By default, the list-item occupies one column. This attribute is valid only when the list contains multiple columns. |

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name   | Parameter          | Description                                                  |
| ------ | ------------------ | ------------------------------------------------------------ |
| sticky | { state: boolean } | Callback events for a sticky component.  <br>- **value: false**: The current item is not in the sticky state. <br>- **value: true**: The current item is in the sticky state.<br>This event is supported only when the item is configured with the **sticky** attribute. |

## Methods

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example

For details, see the [list example code](js-components-container-list.md#section24931424488).