# panel

>  **NOTE**
>
>  This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The **\<panel>** component is a slidable, pop-up component that provides a lightweight content display window with flexible sizes.


## Child Components

Supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name        | Type            | Default Value     | Mandatory  | Description                                      |
| ---------- | -------------- | -------- | ---- | ---------------------------------------- |
| type       | string         | foldable | Yes   | Type of the slidable panel. This attribute cannot be dynamically changed. Available values are as follows:<br>- **minibar**: A minibar panel displays content in the minibar area or a large (fullscreen-like) area.<br>- **foldable**: A foldable panel displays permanent content in a large (fullscreen-like), medium-sized (halfscreen-like), or small area.<br>- **temporary**: A temporary panel displays content in a large (fullscreen-like) or medium-sized (halfscreen-like) area.|
| mode       | string         | full     | No   | Initial status of the slidable panel. Available values are as follows:<br>1. **mini**: Displays a **minibar** or **foldable** panel in its minimum size. This attribute does not take effect for **temporary** panels.<br>2. **half**: Displays a **foldable** or **temporary** panel in a medium-sized (halfscreen-like) area. This attribute does not take effect for **minibar** panels.<br>3. **full**: Displays a panel in a large (fullscreen-like) area.|
| dragbar    | boolean        | true     | No   | Whether to enable a drag bar. The value **true** means that the drag bar will be displayed, and **false** means the opposite.      |
| fullheight | &lt;length&gt; | -        | No   | Panel height in the **full** mode. The default value is the screen height minus 8 px.   |
| halfheight | &lt;length&gt; | -        | No   | Panel height in the **half** mode. The default value is half of the screen height.                |
| miniheight | &lt;length&gt; | -        | No   | Panel height in the **mini** mode. The default value is **48px**.                   |

>  **NOTE**
>  - Rendering attributes, including **for**, **if**, and **show**, are not supported.
>
>  - The **focusable** and **disabled** attributes are not supported.


## Styles

Only the following styles are supported.

| Name                                      | Type                                      | Default Value         | Mandatory  | Description                                      |
| ---------------------------------------- | ---------------------------------------- | ------------ | ---- | ---------------------------------------- |
| padding                                  | &lt;length&gt;                           | 0            | No   | The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom]       | &lt;length&gt;                           | 0            | No   | Left, top, right, and bottom padding.                         |
| padding-[start\|end]                     | &lt;length&gt;                           | 0            | No   | Start and end padding.                           |
| margin                                   | &lt;length&gt;                           | 0            | No   | Shorthand attribute to set the margin for all sides in a declaration. The attribute can have one to four values:<br>- If you set only one value, it specifies the margin for all the four sides.<br>- If you set two values, the first value specifies the top and bottom margins, and the second value specifies the left and right margins.<br>- If you set three values, the first value specifies the top margin, the second value specifies the left and right margins, and the third value specifies the bottom margin.<br>- If you set four values, they respectively specify the margin for top, right, bottom, and left sides (in clockwise order).|
| margin-[left\|top\|right\|bottom]        | &lt;length&gt;                           | 0            | No   | Left, top, right, and bottom margins.                         |
| margin-[start\|end]                      | &lt;length&gt;                           | 0            | No   | Start and end margins.                           |
| border                                   | -                                        | 0            | No   | Shorthand attribute to set all borders. Set **border-width**, **border-style**, and **border-color** in sequence. Default values are used for attributes that are not set.|
| border-style                             | string                                   | solid        | No   | Shorthand attribute to set the style for all borders. Available values are as follows:<br>- **dotted**: dotted border. The radius of a dot is half of **border-width**.<br>- **dashed**: dashed border.<br>- **solid**: solid border.|
| border-[left\|top\|right\|bottom]-style  | string                                   | solid        | No   | Styles of the left, top, right, and bottom borders. The available values are **dotted**, **dashed**, and **solid**.|
| border-[left\|top\|right\|bottom]        | -                                        | -            | No   | Shorthand attribute to set the borders for every side respectively. Set **border-width**, **border-style**, and **border-color** in sequence. Default values are used for attributes that are not set.|
| border-width                             | &lt;length&gt;                           | 0            | No   | Shorthand attribute to set the width for all borders, or separately set the width for each border.        |
| border-[left\|top\|right\|bottom]-width  | &lt;length&gt;                           | 0            | No   | Attribute to set widths of left, top, right, and bottom borders.                     |
| border-color                             | &lt;color&gt;                            | black        | No   | Shorthand attribute to set the color for all borders, or separately set the color for each border.        |
| border-[left\|top\|right\|bottom]-color  | &lt;color&gt;                            | black        | No   | Attribute to set colors for left, top, right, and bottom borders.                     |
| border-radius                            | &lt;length&gt;                           | -            | No   | Attribute to set the radius of round-corner borders. This attribute cannot be used to set the width or color of a specific border. To set the width or color, you must set **border-width** or **border-color** for all the borders at the same time. |
| border-[top\|bottom]-[left\|right]-radius | &lt;length&gt;                           | -            | No   | Attribute to respectively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners                |
| background                               | &lt;linear-gradient&gt;                  | -            | No   | Background. This attribute supports [gradient styles](js-components-common-gradient.md) only and is not compatible with **background-color** or **background-image**.|
| background-color                         | &lt;color&gt;                            | -            | No   | Background color.                                 |
| background-image                         | string                                   | -            | No   | Background image. This attribute is not compatible with **background-color** or **background**. Local image resources are supported. |
| background-size                          | - string<br>- &lt;length&gt; &lt;length&gt;<br>- &lt;percentage&gt; &lt;percentage&gt; | auto         | No   | Background image size.<br>- The **string** values are as follows:<br>  - **contain**: Expands the image to the maximum size so that its height and width are fully applicable to the content area.<br>  - **cover**: Extends the background image to a large enough size so that it completely covers the background area. Some parts of the image may not be displayed in the background area.<br>  - **auto**: Retains the original aspect ratio of the image.<br>- The two **length** values are width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to **auto** by default.<br>- The two **percentage** values are width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to **auto** by default. |
| background-repeat                        | string                                   | repeat       | No   | Repeating attribute of a background image. By default, a background image is repeated both horizontally and vertically.<br>- **repeat**: The image is repeated along the x-axis and y-axis at the same time.<br>- **repeat-x**: The image is repeated along the x-axis.<br>- **repeat-y**: The image is repeated along the y-axis.<br>- **no-repeat**: The image is not repeated.|
| background-position                      | - string string<br>- &lt;length&gt; &lt;length&gt;<br>- &lt;percentage&gt; &lt;percentage&gt; | 0px 0px | No   | - Using keywords: If only one keyword is specified, the other value is **center** by default. The two values define the horizontal position and vertical position, respectively.<br>  - **left**: leftmost in the horizontal direction.<br>  - **right**: rightmost in the horizontal direction.<br>  - **top**: top in the vertical direction.<br>  - **bottom**: bottom in the vertical direction.<br>  - **center**: center position.<br>- Using **length** values: The first value indicates the horizontal position, and the second value indicates the vertical position. For the upper left corner, the value is **0 0**. The unit is pixel. If only one value is specified, the other one is **50%**.<br>- Using **percentage** values: The first value indicates the horizontal position, and the second value indicates the vertical position. **0% 0%** indicates the upper left corner. **100% 100%** indicates the lower right corner. If only one value is specified, the other one is **50%**.<br>- Using both **percentage** and **length** values.|
| opacity                                  | number                                   | 1            | No   | Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.       |


## Events

The following events are supported.

| Name        | Parameter                                      | Description                                      |
| ---------- | ---------------------------------------- | ---------------------------------------- |
| sizechange | { size: { height: heightLength, width: widthLength }, mode: modeStr } | Triggered when the status of the slidable panel changes. Available **mode** values are as follows:<br>- **mini**: Displays a **minibar** or **foldable** panel in its minimum size.<br>- **half**: Displays a **foldable** panel in a medium-sized (halfscreen-like) area.<br>- **full**: Displays a panel in a large (fullscreen-like) area.<br>The returned **height** value indicates the content area height. However, when the **dragbar** attribute is **true**, the **height** value is the height of the drag bar plus that of the content area.|


## Methods

The following methods are supported.

| Name   | Parameter  | Description           |
| ----- | ---- | ------------- |
| show  | -    | Pops the slidable panel up.|
| close | -    | Closes the slidable panel that has been popped up.|


## Example

```html
<!-- xxx.hml -->
<div class="doc-page">
    <div class="btn-div">
        <button type="capsule" value="Click here" onclick="showPanel"></button>
    </div>
    <panel id="simplepanel" type="foldable" mode="half" onsizechange="changeMode" miniheight="200px">
        <div class="panel-div">
            <div class="inner-txt">
                <text class="txt">Simple panel in {{ modeFlag }} mode</text>
            </div>
            <div class="inner-btn">
                <button type="capsule" value="Close" onclick="closePanel"></button>
            </div>
        </div>
    </panel>
</div>
```

```css
/* xxx.css */
.doc-page {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.btn-div {
    width: 100%;
    height: 200px;
    flex-direction: column;
    align-items: center;
    justify-content: center;
}

.txt {
    color: #000000;
    font-weight: bold;
    font-size: 39px;
}

.panel-div {
    width: 100%;
    flex-direction: column;
    align-items: center;
}

.inner-txt {
    width: 100%;
    height: 160px;
    flex-direction: column;
    align-items: center;
    justify-content: center;
}

.inner-btn {
    width: 100%;
    height: 120px;
    justify-content: center;
    align-items: center;
}
```

```js
// xxx.js
export default {
  data: {
    modeFlag: "half"
  },
  showPanel() {
    this.$element('simplepanel').show()
  },
  closePanel() {
    this.$element('simplepanel').close()
  },
  changeMode(e) {
    this.modeFlag = e.mode
  }
}
```

![panel6](figures/panel6.gif)
