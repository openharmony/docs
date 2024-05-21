# switch

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<switch>** component is used to enable or disable a function.

## Required Permissions

None


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name      | Type     | Default Value  | Mandatory  | Description        |
| -------- | ------- | ----- | ---- | ---------- |
| checked  | boolean | false | No   | Whether the component is checked or not.     |
| showtext | boolean | false | No   | Whether the component displays text.   |
| texton   | string  | "On"  | No   | Text displayed when the component is checked. |
| textoff  | string  | "Off" | No   | Text displayed when the component is not checked.|


## Styles



In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name           | Type                        | Default Value       | Mandatory  | Description                                      |
| ------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| texton-color  | &lt;color&gt;              | \#000000   | No   | Text color displayed when the component is checked. This attribute is available only when **texton** and **textoff** are set.         |
| textoff-color | &lt;color&gt;              | \#000000   | No   | Text color displayed when the component is not checked. This attribute is available only when **texton** and **textoff** are set.        |
| text-padding  | number                     | 0px        | No   | Distance between the two sides of the longest text in **texton** and **textoff** and the border of the slider.         |
| font-size     | &lt;length&gt;             | -          | No   | Font size. This attribute is available only when **texton** and **textoff** are set.               |
| allow-scale   | boolean                    | true       | No   | Whether the font size changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| font-style    | string                     | normal     | No   | Font style. This attribute is available only when **texton** and **textoff** are set. For details, see [font-style](js-components-basic-text.md#styles) of the **\<text>** component.|
| font-weight   | number \| string | normal     | No   | Font weight. This attribute is available only when **texton** and **textoff** are set. For details, see [font-weight](js-components-basic-text.md#styles) of the **\<text>** component.|
| font-family   | string                     | sans-serif | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](js-components-common-customizing-font.md) is used for the text. This attribute is available only when **texton** and **textoff** are set.|


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name    | Parameter                                      | Description           |
| ------ | ---------------------------------------- | ------------- |
| change | { checked: checkedValue } | Triggered when the **checked** state changes.|

## Methods

The [universal methods](js-components-common-methods.md) are supported.

## Example

```html
<!-- xxx.hml -->
<div class="container">
    <switch @change="normalswitchChange">
    </switch>
    <switch class="switch" showtext="true" texton="On" textoff="Off" @change="switchChange">
    </switch>
    <switch class="switch text" showtext="true" texton="Switch on" textoff="Switch off" checked="true" @change="switchChange">
    </switch>
</div>
```

```css
/* xxx.css */
.container {
    display: flex;
    justify-content: center;
    align-items: center;
}
.switch {
    texton-color: red;
    textoff-color: forestgreen;
}
.text {
    text-padding: 20px;
    font-size: 30px;
    font-weight: 700;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
    data: {
        title: 'World'
    },
    switchChange(e) {
        if (e.checked) {
            promptAction.showToast({
                message: "Switch on."
            });
        } else {
            promptAction.showToast({
                message: "Switch off."
            });
        }
    },
    normalswitchChange(e) {
        if (e.checked) {
            promptAction.showToast({
                message: "switch on"
            });
        } else {
            promptAction.showToast({
                message: "switch off"
            });
        }
    }
}
```

![en-us_image_0000001152862510](figures/switch.gif)
