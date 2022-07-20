# marquee

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.
>  Since API version 6, the text scrolls only when its width exceeds the width of the **\<marquee>** component.

The **\<marquee>** component is used to display a scrolling piece of text.

## Required Permissions

None


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](../arkui-js/js-components-common-attributes.md), the following attributes are supported.

| Name          | Type    | Default Value | Mandatory  | Description                                      |
| ------------ | ------ | ---- | ---- | ---------------------------------------- |
| scrollamount | number | 6    | No   | Maximum length of each scroll.                        |
| loop         | number | -1   | No   | Number of rolling times. If this parameter is not set, the default value **-1** is used. When the value is less than or equal to **0**, the marquee scrolls continuously.|
| direction    | string | left | No   | Direction in which the marquee scrolls, which can be **left** or **right**.            |


## Styles

In addition to the [universal styles](../arkui-js/js-components-common-styles.md), the following styles are supported.

| Name         | Type                        | Default Value       | Mandatory  | Description                                      |
| ----------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color       | &lt;color&gt;              | \#e5000000 | No   | Font color of the scrolling text.                          |
| font-size   | &lt;length&gt;             | 37.5       | No   | Font size of the scrolling text.                          |
| allow-scale | boolean                    | true       | No   | Whether the font size changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| font-weight | number&nbsp;\|&nbsp;string | normal     | No   | Font weight of the scrolling text. For details, see **font-weight** of the **[\<text> component](../arkui-js/js-components-basic-text.md#styles)**.|
| font-family | string                     | sans-serif | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](../arkui-js/js-components-common-customizing-font.md) is used for the text.|


## Events

In addition to the [universal events](../arkui-js/js-components-common-events.md), the following events are supported.

| Name          | Parameter  | Description                                      |
| ------------ | ---- | ---------------------------------------- |
| bounce(Rich) | -    | Triggered when the marquee scrolls to the end.                         |
| finish(Rich) | -    | Triggered when the marquee finishes the specified number of scrollings (value of the **loop** attribute). It can be triggered only when the **loop** attribute is set to a number greater than 0.|
| start(Rich)  | -    | Triggered when the marquee starts to scroll.                          |

## Methods

In addition to the [universal methods](../arkui-js/js-components-common-methods.md), the following methods are supported.

| Name   | Parameter | Description   |
| ----- | ---- | ----- |
| start | -    | Starts scrolling.|
| stop  | -    | Stops scrolling.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <marquee id="customMarquee" class="customMarquee" scrollamount="{{scrollAmount}}" loop="{{loop}}"direction="{{marqueeDir}}"
    onbounce="onMarqueeBounce" onstart="onMarqueeStart" onfinish="onMarqueeFinish">{{marqueeCustomData}}</marquee>
  <div class="content">
    <button class="controlButton" onclick="onStartClick">Start</button>
    <button class="controlButton" onclick="onStopClick">Stop</button>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #ffffff;
}
.customMarquee {
  width: 100%;
  height: 80px;
  padding: 10px;
  margin: 20px;
  border: 4px solid #ff8888;
  border-radius: 20px;
  font-size: 40px;
  color: #ff8888;
  font-weight: bolder;
  font-family: serif;
  background-color: #ffdddd;
}
.content {
  flex-direction: row;
}
.controlButton {
  flex-grow: 1;
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
```

```js
// xxx.js
export default {
  data: {
    scrollAmount: 30,
    loop: 3,
    marqueeDir: 'left',
    marqueeCustomData: 'Custom marquee',
  },
  onMarqueeBounce: function() {
    console.log("onMarqueeBounce");
  },
  onMarqueeStart: function() {
    console.log("onMarqueeStart");
  },
  onMarqueeFinish: function() {
    console.log("onMarqueeFinish");
  },
  onStartClick (evt) {
    this.$element('customMarquee').start();
  },
  onStopClick (evt) {
    this.$element('customMarquee').stop();
  }
}
```

![lite_bar](figures/lite_bar.gif)
