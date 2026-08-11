# list-item

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @wind_-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:27:02.585Z pushedAt=2026-07-27T09:23:36.733Z -->

**\<list-item>** is a child component of the [\<list>](js-lite-components-container-list.md) component and is used to display items in a list.

> **NOTE**
>
> This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Supported.

## Attributes

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | No| Unique ID of the component.|
| style | string | - | No| Style declaration of the component.|
| class | string | - | No| Style class of the component, which is used to refer to a style table.|
| ref | string | - | No| Reference information of child elements, which is registered with the parent component on **$refs**.|

## Events

| Name| Parameter| Description|
| -------- | -------- | -------- |
| click | - | Triggered when the component is clicked.|
| longpress | - | Triggered when the component is long pressed.|
| swipe<sup>5+</sup> | [SwipeEvent](js-lite-common-events.md#swipeevent) | Triggered when a user quickly swipes on the component. |

## Styles

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| width | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | - | No| Component width.<br>If this attribute is not set, default value **0** is used.|
| height | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | - | No| Component height.<br>If this attribute is not set, default value **0** is used.|
| padding | &lt;length&gt; | 0 | No| Shorthand attribute to set the padding for all sides in a declaration.<br>The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom] | &lt;length&gt; | 0 | No| Left, top, right, and bottom padding.|
| border-width | &lt;length&gt; | 0 | No| Shorthand attribute to set the border width for all sides.|
| border-color | &lt;color&gt; | black | No| Shorthand attribute to set the border color for all sides.|
| border-radius | &lt;length&gt; | - | No| Radius of border corners.|
| background-color | &lt;color&gt; | - | No| Background color.|
| opacity<sup>5+</sup> | number | 1 | No| Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.|
| display | string | flex | No| Whether to display a box containing the element and the layout for its child elements. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|

## Example

See [Example](js-lite-components-container-list.md#example) of the **\<list>** component.