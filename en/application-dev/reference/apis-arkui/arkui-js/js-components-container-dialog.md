# dialog

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<dialog>** component is a custom dialog box.

## Required Permissions

None


## Child Components

This component supports only one child component.


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name                   | Type     | Default Value  | Mandatory  | Description          |
| --------------------- | ------- | ----- | ---- | ------------ |
| dragable<sup>7+</sup> | boolean | false | No   | Whether the dialog box can be dragged.|

>  **NOTE**
>
>  The **\<dialog>** component does not support the **focusable** and **click-effect** attributes.


## Styles

Only the **width**, **height**, **margin**, **margin-[left|top|right|bottom]**, and **margin-[start|end]** styles in [Universal Styles](js-components-common-styles.md) are supported.


## Events

The following events are supported. The [universal events](js-components-common-events.md) are not supported.

| Name                | Parameter  | Description                        |
| ------------------ | ---- | -------------------------- |
| cancel             | -    | Triggered when a user touches an area outside the dialog box to cancel the dialog box.|
| show<sup>7+</sup>  | -    | Triggered when the dialog box is displayed.              |
| close<sup>7+</sup> | -    | Triggered when the dialog box is closed.              |


## Methods

The following methods are supported. The [universal methods](js-components-common-methods.md) are not supported.

| Name   | Parameter  | Description    |
| ----- | ---- | ------ |
| show  | -    | Shows a dialog box.|
| close | -    | Close the dialog box.|

>  **NOTE**
>
>  Attributes and styles of a **\<dialog>** component cannot be dynamically updated.


## Example

```html
<!-- xxx.hml -->
<div class="doc-page">
  <div class="btn-div">
    <button type="capsule" value="Click here" class="btn" onclick="showDialog"></button>
  </div>
  <dialog id="simpledialog" dragable="true" class="dialog-main" oncancel="cancelDialog">
    <div class="dialog-div">
      <div class="inner-txt">
        <text class="txt" ondoubleclick="doubleclick">Simple dialog</text>
      </div>
      <div class="inner-btn">
        <button type="capsule" value="Cancel" onclick="cancelSchedule" class="btn-txt"></button>
        <button type="capsule" value="Confirm" onclick="setSchedule" class="btn-txt"></button>
      </div>
    </div>
  </dialog>
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
.btn {
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
.txt {
  color: #000000;
  font-weight: bold;
  font-size: 39px;
}
.dialog-main {
  width: 500px;
}
.dialog-div {
  flex-direction: column;
  align-items: center;
}
.inner-txt {
  width: 400px;
  height: 160px;
  flex-direction: column;
  align-items: center;
  justify-content: space-around;
}
.inner-btn {
  width: 400px;
  height: 120px;
  justify-content: space-around;
  align-items: center;
}
.btn-txt {
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  showDialog() {
    this.$element('simpledialog').show()
  },
  cancelDialog() {
    promptAction.showToast({
      message: 'Dialog cancelled'
    })
  },
  cancelSchedule() {
    this.$element('simpledialog').close()
    promptAction.showToast({
      message: 'Successfully cancelled'
    })
  },
  setSchedule() {
    this.$element('simpledialog').close()
    promptAction.showToast({
      message: 'Successfully confirmed'
    })
  },
  doubleclick(){
    promptAction.showToast({
      message: 'doubleclick'
    })
  }
}
```

![4](figures/4.gif)
