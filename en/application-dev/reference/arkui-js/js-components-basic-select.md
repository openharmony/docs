# select

The **<select\>** component provides a drop-down list that allows users to select among multiple options.

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

The **<[option](js-components-basic-option.md)\>** child component is supported.


## Attributes

The [universal attributes](../arkui-js/js-components-common-attributes.md) are supported.


## Ad Asset

In addition to the [universal styles](../arkui-js/js-components-common-styles.md), the following styles are supported.

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| font-family | string | No  | Font family, in which fonts are separated by commas (,). The first font in the family or the specified [custom font](./js-components-common-customizing-font.md) is used for the text.<br>Default value: **sans-serif**|


## Events

In addition to the [universal events](../arkui-js/js-components-common-events.md), the following events are supported.

| Name  | Parameter                     | Description                                                        |
| ------ | ------------------------- | ------------------------------------------------------------ |
| change | {newValue:&nbsp;newValue} | Triggered when an option is selected from the drop-down list to return an object. The value of **newValue** is the value of the selected option.|

>  **NOTE**
>
>  The **\<select>** component does not support the **click** event.


## Methods

The [universal methods](../arkui-js/js-components-common-methods.md) are supported.


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <select @change="changeFruit">
    <option value="bananaValue">
      Banana
    </option>
    <option value="appleValue" selected="true">
      Apple
    </option>
    <option value="pearValue">
      Pear
    </option>
  </select>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
```

```js
// ×××.js
export default {
  changeFruit(e){
    console.log("newValue:" + e.newValue)
  }
}
```

![en-us_image_0000001152588538](figures/en-us_image_0000001152588538.png)
