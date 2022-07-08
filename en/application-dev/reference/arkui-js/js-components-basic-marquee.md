# marquee

The **\<marquee>** component displays single-line scrolling text.

## Required Permissions

None

## Child Component

Not supported

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name         | Type   | Default Value | Mandatory | Description                                                  |
| ------------ | ------ | ------------- | --------- | ------------------------------------------------------------ |
| scrollamount | number | 6             | No        | Maximum length of each scroll.                               |
| loop         | number | -1            | No        | Number of rolling times. If this parameter is not set, the default value **-1** is used. When the value is less than or equal to **0**, the marquee scrolls continuously. |
| direction    | string | left          | No        | Direction in which the marquee scrolls, which can be **left** or **right**. |

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name        | Type             | Default Value | Mandatory | Description                                                  |
| ----------- | ---------------- | ------------- | --------- | ------------------------------------------------------------ |
| color       | \<color>          | #e5000000     | No        | Font color of the scrolling text.                            |
| font-size   | \<length>         | 37.5          | No        | Font size of the scrolling text.                             |
| allow-scale | boolean          | true          | No        | Whether the font size changes with the system's font size settings.NOTE:If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart. |
| font-weight | number \| string | normal        | No        | Font weight of the scrolling text. For details, see [font-weight](js-components-basic-text.md#section5775351116) of the **text** component. |
| font-family | string           | sans-serif    | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) in the family is selected as the font for the text. |

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name         | Parameter | Description                                                  |
| ------------ | --------- | ------------------------------------------------------------ |
| bounce(Rich) | -         | Triggered when the marquee scrolls to the end.               |
| finish(Rich) | -         | Triggered when the marquee finishes the specified number of scrollings (value of the **loop** attribute). It can be triggered only when the **loop** attribute is set to a number greater than 0. |
| start(Rich)  | -         | Triggered when the marquee starts to scroll.                 |

## Methods

In addition to the methods in [Universal Methods](js-components-common-methods.md), the following events are supported.



| Name  | Parameter | Description       |
| ----- | --------- | ----------------- |
| start | -         | Starts scrolling. |
| stop  | -         | Stops scrolling.  |

## Example Code

```
<!-- xxx.hml -->
<div class="container">
  <marquee id="customMarquee" class="customMarquee" scrollamount="{{scrollAmount}}" loop="{{loop}}"direction="{{marqueeDir}}"
    onbounce="onMarqueeBounce" onstart="onMarqueeStart" onfinish="onMarqueeFinish">{{marqueeCustomData}}</marquee>
  <div class="content">
    <button class="controlButton" onclick="onStartClick">Start</button>
    <button class="controlButton" onclick="onStopClick">Stop</button>
  </div>
</div>
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

![img](figures/lite_bar.gif)