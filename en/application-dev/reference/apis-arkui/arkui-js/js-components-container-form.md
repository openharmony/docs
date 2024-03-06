# form

>  **NOTE**
>
>  This component is supported since API version 6. Updates will be marked with a superscript to indicate their earliest API version.

The **\<form>** component allows the content in **input** elements to be submitted and reset.


## Required Permissions

None


## Child Components

Supported


## Attributes

The [universal attributes](js-components-common-attributes.md) are supported.


## Styles

The [universal styles](js-components-common-styles.md) are supported.


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name| Parameter| Description|
| -------- | -------- | -------- |
| submit | FormResult | Triggered when the **Submit** button is touched.|
| reset | - | Triggered when the **Reset** button is clicked.|

**Table 1** FormResult

| Name| Type| Description|
| -------- | -------- | -------- |
| value | Object | Values of **name** and **value** of the input element.|


## Methods

The [universal methods](js-components-common-methods.md) are supported.


## Example

```html
<!-- xxx.hml -->
<form onsubmit='onSubmit' onreset='onReset'>
  <div style="width: 600px;height: 150px;flex-direction: row;justify-content: space-around;">
    <label>Option 1</label>
    <input type='radio' name='radioGroup' value='radio1'></input>
    <label>Option 2</label>
    <input type='radio' name='radioGroup' value='radio2'></input>
  </div>
  <text style="margin-left: 50px;margin-bottom: 50px;">Enter text</text>
  <input type='text' name='user'></input>
  <div style="width: 600px;height: 150px;margin-top: 50px;flex-direction: row;justify-content: space-around;">
    <input type='submit'>Submit</input>
    <input type='reset'>Reset</input>
  </div>
</form>
```

```js
// xxx.js
export default{
  onSubmit(result) {
    console.log(result.value.radioGroup) // radio1 or radio2
    console.log(result.value.user) // text input value
  },
  onReset() {
    console.log('reset all value')
  }
}
```

![001](figures/001.gif)
