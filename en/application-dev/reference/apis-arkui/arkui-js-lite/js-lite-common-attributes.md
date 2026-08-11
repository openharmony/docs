# Universal Attributes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:25:59.164Z pushedAt=2026-07-27T09:23:36.710Z -->

Common attributes are used to describe the basic configuration capabilities supported by components, including the component ID, style reference, reference relationships, and rendering control. They are applicable to scenarios where the basic appearance and display behavior of components need to be set in a unified manner, helping developers manage the basic attributes of components in a consistent way.

## Common Attributes

Common attributes are used to set component identities and appearance.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | string | No| Unique ID of the component.|
| style | string | No| Style declaration of the component.|
| class | string | No| Style class of the component, which is used to refer to a style table.|
| ref | string | No| Reference information of child elements, which is registered with the parent component on **$refs**.|

## Rendering Attributes

Rendering attributes are used to set whether a component is rendered.

| Name| Type| Description|
| -------- | -------- | -------- |
| for | Array | Expands the current element based on the configured data list.|
| if | boolean | Whether the element is added or removed. The value **true** indicates that the current element is added, and **false** indicates the current element is removed. |
| show | boolean | Whether the element is displayed or hidden. The value **true** indicates that the current element is displayed, and **false** indicates the current element is hidden. |

> **NOTE**
>
> Do not set styles in attribute fields.