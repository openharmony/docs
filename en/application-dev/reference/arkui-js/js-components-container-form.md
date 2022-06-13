# form

The **\<form>** component allows the content in **input** elements to be submitted and reset.

## Required Permissions

None

## Child Component

Supported

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

## Styles

Styles in [Universal Styles](js-components-common-styles.md) are supported.

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name   | Parameters                                    | Description                                  |
| ------ | --------------------------------------------- | -------------------------------------------- |
| submit | [FormResult](js-components-container-form.md) | Triggered when the Submit button is touched. |
| reset  | -                                             | Triggered when the Reset button is clicked.  |

**Table 1** FormResult



| Name  | Type   | Description                                            |
| ----- | ------ | ------------------------------------------------------ |
| value | Object | Values of **name** and **value** of the input element. |

## Methods

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example

```
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

![img](figures/001.gif)