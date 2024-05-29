# text

The **\<text>** component is used to display a piece of textual information.

> **NOTE**
>
> This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


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
| swipe<sup>5+</sup> | [SwipeEvent](js-lite-common-events.md) | Triggered when a user quickly swipes on the component.|


## Styles

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| color | &lt;color&gt; | \#ffffff | No| Font color.|
| font-size | &lt;length&gt; | 30px | No| Font size. |
| letter-spacing | &lt;length&gt; | 2px | No| Character spacing (px).|
| text-align | string | left | No| Text alignment mode. Available values are as follows:<br>- **left**: The text is left-aligned.<br>- **center**: The text is center-aligned.<br>- **right**: The text is right-aligned.|
| text-overflow | string | clip | No| Available values are as follows:<br>- **clip**: The text is clipped and displayed based on the size of the parent container.<br>- **ellipsis**: The text is displayed based on the size of the parent container. The text that cannot be displayed is replaced with ellipsis.|
| font-family | string | SourceHanSansSC-Regular | No| Font. Only the **SourceHanSansSC-Regular** font is supported.|
| width | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0px | No| Component width.<br>Unit: pixel<br>If this attribute is not set, the default value **0** is used.|
| height | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0px | No| Component height.<br>Unit: pixel<br>If this attribute is not set, the default value **0** is used.|
| padding | &lt;length&gt; | 0 | No| Shorthand attribute to set the padding for all sides.<br>The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom] | &lt;length&gt; | 0 | No| Left, top, right, and bottom padding.|
| margin | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0 | No| Shorthand attribute to set the margin for all sides. The attribute can have one to four values:<br>- If you set only one value, it specifies the margin for all the four sides.<br>- If you set two values, the first value specifies the top and bottom margins, and the second value specifies the left and right margins.<br>- If you set three values, the first value specifies the top margin, the second value specifies the left and right margins, and the third value specifies the bottom margin.<br>- If you set four values, they respectively specify the margin for top, right, bottom, and left sides (in clockwise order).|
| margin-[left\|top\|right\|bottom] | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0 | No| Left, top, right, and bottom margins.|
| border-width | &lt;length&gt; | 0 | No| Shorthand attribute to set the margin for all sides.|
| border-color | &lt;color&gt; | black | No| Shorthand attribute to set the color for all borders.|
| border-radius | &lt;length&gt; | - | No| Radius of round-corner borders.|
| background-color | &lt;color&gt; | - | No| Background color.|
| opacity<sup>5+</sup> | number | 1 | No| Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.|
| display | string | flex | No| How and whether to display the box containing an element. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|
| [left\|top] | &lt;length&gt; \| &lt;percentage&gt;<sup>6+</sup> | - | No| Edge of the element.<br>- **left**: left edge position of the element. This attribute defines the offset between the left edge of the margin area of a positioned element and left edge of its containing block.<br>- **top**: top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element. |
| line-height<sup>10+</sup> | number | 0px | No| Text line height.<br>Unit: pixel<br>If this attribute is not set, the text line height is adaptive.|

## Example

```html
<!-- xxx.hml -->
<div class="container">
    <text class="title">
        Hello {{ title }}
    </text>
</div>
```

```CSS
/* xxx.css */
.container {
    width: 100%;
    height: 100%;
    justify-content: center;
    align-items: center;
}

.title {
    width: 100px;
    font-size: 30px;
    text-align: center;
    color: red;
}
```

```javascript
// xxx.js
export default {
    data: {
        title: ""
    },
    onInit() {
        this.title = "World";
    }
}
```

![text](figures/text-lite.png)
