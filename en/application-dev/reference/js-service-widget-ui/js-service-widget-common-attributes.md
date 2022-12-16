# Universal Attributes

> **NOTE**
>
>The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Common Attributes

Common attributes are used to set component identities and appearance.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | No| Unique ID of the component.|
| style | string | - | No| Style declaration of the component.|
| class | string | - | No| Style class of the component, which is used to refer to a style table.|
| ref | string | - | No| Reference information of child elements or child components, which is registered with the parent component on **$refs**.|
| disabled | boolean | false | No| Whether the component is disabled. If it is disabled, it cannot respond to user interactions.|
| dir | string | auto | No| Component layout mode. Available values are as follows:<br>- **rtl**: right-to-left layout.<br>- **ltr**: left-to-right layout.<br>- **auto**: follows the system language environment.|


## Rendering Attributes

Rendering attributes are used to set whether a component is rendered.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| for | Array | - | Expands the component based on the configured data list.|
| if | boolean | - | Whether the component is added or removed.|
| show | boolean | - | Whether the component is displayed or hidden.|

>  **NOTE**
>
>  Do not set styles in attribute fields.
