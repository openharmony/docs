# dialog

The **&lt;dialog&gt;** component is a custom pop-up container.

## Required Permissions

None

## Child Components

A single child component is supported.

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name                  | Type    | Default Value | Mandatory | Description                        |
| --------------------- | ------- | ------------- | --------- | ---------------------------------- |
| dragable<sup>7+</sup> | boolean | false         | No        | Whether the pop-up can be dragged. |

> ![img](https://gitee.com/openharmony/docs/raw/master/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:**
>
> - The **&lt;dialog&gt;** component does not support the **focusable** and **click-effect** attributes.

## Styles

Only the **width**, **height**, **margin**, **margin-[left|top|right|bottom]**, and **margin-[start|end]** styles in [Universal Styles](js-components-common-styles.md) are supported.

## Events

Events in [Universal Events](js-components-common-events.md) are not supported. The following table lists the supported event.



| Name    | Parameter | Description                                                  |
| ------- | --------- | ------------------------------------------------------------ |
| cancel  | -         | Triggered when a user taps a non-dialog area to cancel the pop-up. |
| show7+  | -         | Triggered when the pop-up is displayed.                      |
| close7+ | -         | Triggered when the pop-up is closed.                         |

## Methods

Methods in [Universal Methods](js-components-common-methods.md) are not supported. The following table lists the supported methods.



| Name  | Parameter | Description          |
| ----- | --------- | -------------------- |
| show  | -         | Shows a dialog box.  |
| close | -         | Closes a dialog box. |

> ![img](https://gitee.com/openharmony/docs/raw/master/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** Attributes and styles of a **\<dialog>** component cannot be dynamically updated.

## Example Code

```
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
// xxx.js
import prompt from '@system.prompt';
export default {
  showDialog(e) {
    this.$element('simpledialog').show()
  },
  cancelDialog(e) {
    prompt.showToast({
      message: 'Dialog cancelled'
    })
  },
  cancelSchedule(e) {
    this.$element('simpledialog').close()
    prompt.showToast({
      message: 'Successfully cancelled'
    })
  },
  setSchedule(e) {
    this.$element('simpledialog').close()
    prompt.showToast({
      message: 'Successfully confirmed'
    })
  },
  doubleclick(e){
    prompt.showToast({
      message: 'doubleclick'
    })
  }
}
```

![img](figures/4.gif)