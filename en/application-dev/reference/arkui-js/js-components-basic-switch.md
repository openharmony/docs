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

In addition to the [universal attributes](../arkui-js/js-components-common-attributes.md), the following attributes are supported.

| Name      | Type     | Default Value  | Mandatory  | Description        |
| -------- | ------- | ----- | ---- | ---------- |
| checked  | boolean | false | No   | Whether the component is checked or not.     |
| showtext | boolean | false | No   | Whether the component displays text.   |
| texton   | string  | "On"  | No   | Text displayed when the component is checked. |
| textoff  | string  | "Off" | No   | Text displayed when the component is not checked.|


## Styles

In addition to the [universal styles](../arkui-js/js-components-common-styles.md), the following styles are supported.

| Name                 | Type                        | Default Value       | Mandatory  | Description                                      |
| ------------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| texton-color(Rich)  | &lt;color&gt;              | \#000000   | No   | Text color displayed when the component is checked.                             |
| textoff-color(Rich) | &lt;color&gt;              | \#000000   | No   | Text color displayed when the component is not checked.                            |
| text-padding(Rich)  | number                     | 0px        | No   | Distance between the two sides of the longest text in **texton** and **textoff** and the border of the slider.         |
| font-size(Rich)     | &lt;length&gt;             | -          | No   | Font size. This attribute is available only when **texton** and **textoff** are set.               |
| allow-scale(Rich)   | boolean                    | true       | No   | Whether the font size changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| font-style(Rich)    | string                     | normal     | No   | Font style. This attribute is available only when **texton** and **textoff** are set. For details, see **font-style** of the [**\<text>**](../arkui-js/js-components-basic-text.md#styles) component.|
| font-weight(Rich)   | number \| string | normal     | No   | Font weight. This attribute is available only when **texton** and **textoff** are set. For details, see **font-weight** of the [**\<text>**](../arkui-js/js-components-basic-text.md#styles) component.|
| font-family(Rich)   | string                     | sans-serif | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](../arkui-js/js-components-common-customizing-font.md) is used for the text. This attribute is available only when **texton** and **textoff** are set.|


## Events

In addition to the [universal events](../arkui-js/js-components-common-events.md), the following events are supported.

| Name    | Parameter                                      | Description           |
| ------ | ---------------------------------------- | ------------- |
| change | { checked: checkedValue } | Triggered when the **checked** state changes.|

## Methods

The [universal methods](../arkui-js/js-components-common-methods.md) are supported.

## Example

```html
<!-- xxx.hml -->
<div class="container">
  <switch showtext="true" texton="On" textoff="Off" checked="true" @change="switchChange">
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
switch{
  texton-color:#002aff;
  textoff-color:silver;
  text-padding:20px;
}
```

```js
// xxx.js
import prompt from '@system.prompt';
export default {
  data: {
    title: 'World'
  },
  switchChange(e){
    console.log(e.checked);
    if(e.checked){
      prompt.showToast({
        message: "Switch on."
      });
    }else{
      prompt.showToast({
        message: "Switch off."
      });
    }
  }
}
```

![en-us_image_0000001152862510](figures/en-us_image_0000001152862510.gif)
