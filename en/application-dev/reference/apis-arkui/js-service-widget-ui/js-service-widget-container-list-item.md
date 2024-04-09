# list-item


**\<list-item>** is a child component of the **[\<list>](js-service-widget-container-list.md)** component and is used to display items in a list.


>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
> - You can customize the width of each **\<list-item>**. However, if you retain the default value **stretch** of **align-items** for the parent component **\<list>**, the width of **\<list-item>** is equal to that of **\<list>**. To make the customized **\<list-item>** width take effect, set **align-items** to other values rather than **stretch**.
> 
> - When possible, do not develop the long press and drag gestures on the **\<list-item>** component.


## Child Components

Supported


## Attributes

In addition to the [universal attributes](js-service-widget-common-attributes.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| type | string | default | No| Type of the list-item. A list can contain multiple list-item types. The same type of list items should have the same view layout after being rendered. When the type is fixed, replace the **if** attribute with the **show** attribute to ensure that the view layout remains unchanged.|
| section | string | - | No| String used to match this item. This attribute can be left empty. Type of the **Enter** key on the soft keyboard. The value cannot be dynamically updated. In a list item group, only the string set for the primary item is valid.|
| sticky | string | none | No| Whether the current item sticks in place at the top, and the effect when it disappears. This attribute supports vertical lists only and is invalid for items in a group.<br>- **none**: The current item does not stick at the top.<br>- **normal**: The current item sticks at the top and disappears with a sliding effect.<br>- **opacity**: The current item sticks at the top and disappears gradually. This option is only supported on wearables.|
| clickeffect | boolean | true | No| Whether an effect is displayed when the current item is clicked.<br>- **false**: No effect is displayed when the item is clicked.<br>- **true**: An effect is displayed when the item is clicked.|


## Styles

In addition to the [universal styles](js-service-widget-common-styles.md), the following styles are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| column-span | &lt;number&gt; | 1 | No| Number of columns occupied by the current list-item in the list. By default, the list-item occupies one column. This attribute is valid only when the list contains multiple columns.|
| click-color | &lt;color&gt; | - | No| Backplane color of a list-item when touched.|


## Events

The [universal events](js-service-widget-common-events.md) are supported.


## Example

For details, see [Example of the \<list> component](js-service-widget-container-list.md#example).
