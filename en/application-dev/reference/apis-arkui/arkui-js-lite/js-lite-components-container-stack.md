# stack

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=45ec2d938cfede23d9ca90fe41c0d1f3e7b2b01d translatedAt=2026-08-11T01:54:44.377Z pushedAt=2026-08-11T02:10:38.833Z -->

The **\<stack>** component provides a stack container where child components are successively stacked and the latter one overwrites the previous one.

> **NOTE**
>
> This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Supported.

## Attributes

| Name   | Type    | Default Value | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| id    | string | -    | No   | Unique ID of the component.                                |
| style | string | -    | No   | Style declaration of the component.                                |
| class | string | -    | No   | Style class of the component, which is used to refer to a style table.                         |
| ref   | string | -    | No   | Reference information of child elements, which is registered with the parent component on **$refs**.|

## Events

| Name                | Parameter                               | Description         |
| ------------------ | --------------------------------- | ----------- |
| click              | -                                 | Triggered when the component is clicked. |
| longpress          | -                                 | Triggered when the component is long pressed. |
| swipe<sup>5+</sup> | [SwipeEvent](js-lite-common-events.md#swipeevent) | Triggered when a user quickly swipes on the component.|

## Styles

| Name                                | Type                                      | Default Value  | Mandatory  | Description                                      |
| ---------------------------------- | ---------------------------------------- | ----- | ---- | ---------------------------------------- |
| width                              | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | -     | No   | Component width.<br>If this attribute is not set, the default value **0** is used.       |
| height                             | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | -     | No   | Component height.<br>If this attribute is not set, the default value **0** is used.       |
| padding                            | &lt;length&gt;                           | 0     | No   | Shorthand attribute to set the padding for all sides.<br>The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom] | &lt;length&gt;                           | 0     | No   | Left, top, right, and bottom padding.                         |
| margin                             | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0     | No    | Shorthand attribute to set the margin for all sides. The attribute can have one to four values:<br/>-&nbsp;If you set only one value, it specifies the margin for all the four sides.<br/>-&nbsp;If you set two values, the first value specifies the top and bottom margins, and the second value specifies the left and right margins.<br/>-&nbsp;If you set three values, the first value specifies the top margin, the second value specifies the left and right margins, and the third value specifies the bottom margin.<br/>-&nbsp;If you set four values, they respectively specify the margin for top, right, bottom, and left sides (in clockwise order). |
| margin-[left\|top\|right\|bottom]  | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0     | No   | Left, top, right, and bottom margins.                         |
| border-width                       | &lt;length&gt;                           | 0     | No   | Shorthand attribute to set the border width for all sides.                      |
| border-color                       | &lt;color&gt;                            | black | No   | Shorthand attribute to set the color for all borders.                      |
| border-radius                      | &lt;length&gt;                           | -     | No   | Radius of border corners.           |
| background-color                   | &lt;color&gt;                            | -     | No   | Background color.                                 |
| opacity<sup>5+</sup>               | number                                   | 1     | No   | Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.       |
| display                            | string                                   | flex  | No   | Whether to display a box containing the element and the layout for its child elements. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|
| [left\|top]                        | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | -     | No   | Edge of the element.<br>- The **left** attribute specifies the left edge position of the element. This attribute defines the offset between the left edge of the margin area of a positioned element and left edge of its containing block.<br>- The **top** attribute specifies the top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.|

>  **NOTE**
>
> The absolute positioning does not support a percentage. Therefore, **margin** cannot be set for the child components of the **\<stack>** component.

## Example

```html
<!-- xxx.hml -->
<stack class="stack-parent">
  <div class="back-child bd-radius"></div>
  <div class="positioned-child bd-radius"></div>
  <div class="front-child bd-radius"></div>
</stack>
```

```css
/* xxx.css */
.stack-parent {
  width: 400px;
  height: 400px;
  background-color: #ffffff;
  border-width: 1px;
  border-style: solid;
}
.back-child {
  width: 300px;
  height: 300px;
  background-color: #3f56ea;
}
.front-child {
  width: 100px;
  height: 100px;
  background-color: #00bfc9;
}
.positioned-child {
  width: 100px;
  height: 100px;
  left: 50px;
  top: 50px;
  background-color: #47cc47;
}
.bd-radius {
  border-radius: 16px;
}
```

![stack](figures/stack.png)