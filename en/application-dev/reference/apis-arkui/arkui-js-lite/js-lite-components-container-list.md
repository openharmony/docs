# list

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @wind_-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:27:07.491Z pushedAt=2026-07-27T09:23:36.742Z -->

The **\<list>** component provides a list container that presents a series of list items arranged in a column with the same width. It supports presentations of the same data in a multiple and coherent row style, for example, images or text.

> **NOTE**
>
> This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Only the [\<list-item>](js-lite-components-container-list-item.md) child component is supported.


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
| scrollend | - | Triggered when the list stops scrolling.|
| click | - | Triggered when the component is clicked.|
| longpress | - | Triggered when the component is long pressed.|
| swipe<sup>5+</sup> | [SwipeEvent](js-lite-common-events.md#swipeevent) | Triggered when a user quickly swipes on the component.|
| scrolltop<sup>8+</sup> | - | Triggered when the list is scrolled to the top.|
| scrollbottom<sup>8+</sup> | - | Triggered when the list is scrolled to the bottom.|


## Styles

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| flex-direction | string | column | No| Main axis direction of the flex container. It specifies how items are placed in the flex container.<br>- **column**: Items are placed vertically from top to bottom.<br>- **row**: Items are placed horizontally from left to right.<br>For the **\<list>** component, the default value is **column**. For other components, the default value is **row**. Dynamic modification is not supported on lite wearables.|
| width | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | - | No| Component width.<br>If this attribute is not set, the default value **0** is used.|
| height | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | - | No| Component height.<br>If this attribute is not set, the default value **0** is used.|
| padding | &lt;length&gt; | 0 | No| Shorthand attribute to set the padding for all sides.<br>The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom] | &lt;length&gt; | 0 | No| Left, top, right, and bottom padding.|
| margin | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0 | No | Shorthand attribute to set the margin for all sides. The attribute can have one to four values:<br/>-&nbsp;If you set only one value, it specifies the margin for all the four sides.<br/>-&nbsp;If you set two values, the first value specifies the top and bottom margins, and the second value specifies the left and right margins.<br/>-&nbsp;If you set three values, the first value specifies the top margin, the second value specifies the left and right margins, and the third value specifies the bottom margin.<br/>-&nbsp;If you set four values, they respectively specify the margin for top, right, bottom, and left sides (in clockwise order). |
| margin-[left\|top\|right\|bottom] | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0 | No| Left, top, right, and bottom margins.|
| border-width | &lt;length&gt; | 0 | No| Shorthand attribute to set the border width for all sides.|
| border-color | &lt;color&gt; | black | No| Shorthand attribute to set the color for all borders.|
| border-radius | &lt;length&gt; | - | No| Radius of border corners.|
| background-color | &lt;color&gt; | - | No| Background color.|
| opacity<sup>5+</sup> | number | 1 | No| Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.|
| display | string | flex | No| Whether to display a box containing the element and the layout for its child elements. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|
| [left\|top] | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | - | No| Edge of the element.<br>- The **left** attribute specifies the left edge position of the element. This attribute defines the offset between the left edge of the margin area of a positioned element and left edge of its containing block.<br>- The **top** attribute specifies the top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.|


## Methods

| Name| Parameter| Description|
| -------- | -------- | -------- |
| scrollTo | { index: number(position) }| Scrolls the list to the position of the item at the specified index.|
| rotation | {&nbsp;focus:&nbsp;boolean&nbsp;} | Specifies whether to request focus for crown rotation. **focus: true**: acquires focus, allowing users to scroll options by rotating the crown (only works for single-column pickers). **focus: false**: releases focus.|
## Example


```html
<!-- index.hml -->
<div class="container">
    <list class="todo-wrapper" ref="listObj">
        <list-item for="{{todolist}}" class="todo-item">
            <div style="width: 454px;height: 80px;flex-direction: column;align-items: center;justify-content: center;">
                <text class="todo-title">{{$item.title}}</text>
                <text class="todo-title">{{$item.date}}</text>
            </div>
        </list-item>
    </list>
</div>
```


```js
// index.js
export default {
    data: {
        todolist: [{
            title: 'Prepare for the interview',
            date: '2021-12-31 10:00:00',
        }, {
            title: 'Watch the movie',
            date: '2021-12-31 20:00:00',
        }
        , {
            title: 'Read a book',
            date: '2021-12-31 21:00:00',
        },
        {
            title: 'Take a shower',
            date: '2021-12-31 22:00:00',
        },
        {
            title: 'Sleep',
            date: '2021-12-31 23:00:00',
        }],
    },
    onShow() {
        this.$refs.listObj.rotation({focus: true})
    },
    onHide() {
        this.$refs.listObj.rotation({focus: false})
    }
}
```


```css
/* index.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.todo-wrapper {
  width: 454px;
  height: 500px;
}
.todo-item {
  width: 454px;
  height: 80px;
  flex-direction: column;
}
.todo-title {
  width: 454px;
  height: 40px;
  text-align: center;
}
```

![list](figures/list-lite.png)