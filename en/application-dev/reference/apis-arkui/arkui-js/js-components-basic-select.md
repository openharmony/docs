# select

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **<select\>** component provides a drop-down list that allows users to select among multiple options.

## Child Components

The **[<option\>](js-components-basic-option.md)** child component is supported.


## Attributes

The [universal attributes](js-components-common-attributes.md) are supported.


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| font-family | string | No  | Font family, in which fonts are separated by commas (,). The first font in the family or the specified [custom font](./js-components-common-customizing-font.md) is used for the text.<br>Default value: **sans-serif**|


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name  | Parameter                     | Description                                                        |
| ------ | ------------------------- | ------------------------------------------------------------ |
| change | {newValue:&nbsp;newValue} | Triggered when an option is selected from the drop-down list to return an object. The value of **newValue** is the value of the selected option.|

>  **NOTE**
>
>  The **\<select>** component does not support the **click** event.


## Methods

The [universal methods](js-components-common-methods.md) are supported.


## Example

```html
<!-- xxx.hml -->
<div class="container">
    <select @change="onChange">
        <option for="{{ array }}" value="{{ $item.value }}">
            {{ $item.name }}
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
    width: 100%;
    height: 100%;
}
```

```js
// xxx.js
export default {
    data: {
        array: [
            {
                "value": "Option 0", "name": "Option 0"
            },
            {
                "value": "Option 1", "name": "Option 1"
            },
            {
                "value": "Option 2", "name": "Option 2"
            },
            {
                "value": "Option 3", "name": "Option 3"
            },
        ]
    },
    getData() {
        let other = [
            {
                "value": "Option A", "name": "Option A"
            },
            {
                "value": "Option B", "name": "Option B"
            },
            {
                "value": "Option C", "name": "Option C"
            },
            {
                "value": "Option D", "name": "Option D"
            },
        ]
        return other
    },
    onChange() {
        this.array = this.getData()
    }
}
```

![en-us_image_0000001152588538](figures/en-us_image_0000001152588538.gif)
