# stepper

>  **NOTE**
>
>  This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The **\<stepper>** component provides a step navigator. When multiple steps are required to complete a task, you can use the **\<stepper>** component to navigate your users through the whole process.


## Required Permissions

None


## Child Components

Only the **\<stepper-item>** component is supported.

>  **NOTE**
>
>  Steps in the **\<stepper>** are sorted according to the sequence of its **\<stepper-item>** child components.


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name   | Type    | Default Value | Description                            |
| ----- | ------ | ---- | ------------------------------ |
| index | number | 0    | Index of the **\<stepper-item>** child component to display. By default, the first one is displayed.|


## Styles

The [universal styles](js-components-common-styles.md) are supported.

>  **NOTE**
>
>  By default, the **\<stepper>** component fills entire space of its container. To optimize user experience, it is recommended that the container should be as large as the application window in size, or should be the root component.


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name    | Parameter                                      | Description                                      |
| ------ | ---------------------------------------- | ---------------------------------------- |
| finish | -                                       | Triggered when the last step on the navigator is complete.                   |
| skip   | -                                       | Triggered when users click the skip button to skip steps.|
| change | { prevIndex: prevIndex, index: index} | Triggered when users click the left or right (text) button of the step navigator to switch between steps. **prevIndex** indicates the index of the previous step, and **index** indicates that of the current step.|
| next   | { index: index, pendingIndex: pendingIndex } | Triggered when users click the next (text) button. **index** indicates the index of the current step, and **pendingIndex** indicates that of the step to go. The return value is in { pendingIndex: pendingIndex } format. You can use **pendingIndex** to specify a **\<stepper-item>** child component as the next step to go. |
| back   | { index: index, pendingIndex: pendingIndex } | Triggered when users click the previous (text) button. **index** indicates the index of the current step, and **pendingIndex** indicates that of the step to go. The return value is in Object: { pendingIndex: pendingIndex } format. You can use **pendingIndex** to specify a **\<stepper-item>** child component as the previous step. |


## Methods

In addition to the [universal methods](js-components-common-methods.md), the following methods are supported.

| Name                 | Parameter                                      | Description                                      |
| ------------------- | ---------------------------------------- | ---------------------------------------- |
| setNextButtonStatus | { status: string, label: label } | Sets the text and status of the next button in the step navigator. **label** indicates the button text, and **status** indicates the button status. Available **status** values are as follows:<br>- **normal**: The next button is displayed normally and can navigate users to the next step when it is clicked.<br>- **disabled**: The next button is grayed out and unavailable.<br>- **waiting**: The next button is not displayed, and a process bar is displayed instead.<br>- **skip**: The skip button is displayed to allow users to skip all remaining steps.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
    <stepper class="stepper" id="mystepper" onnext="nextclick" onback="backclick" onchange="statuschange"
             onfinish="finish" onskip="skip" style="height : 100%;">
        <stepper-item class="stepper-item" label="{{ label_1 }}">
            <div class="item">
                <text>Page One</text>
                <button type="capsule" class="button" value="change status" onclick="setRightButton"></button>
            </div>
        </stepper-item>
        <stepper-item class="stepper-item" label="{{ label_2 }}">
            <div class="item">
                <text>Page Two</text>
                <button type="capsule" class="button" value="change status" onclick="setRightButton"></button>
            </div>
        </stepper-item>
        <stepper-item class="stepper-item" label="{{ label_3 }}">
            <div class="item">
                <text>Page Three</text>
                <button type="capsule" class="button" value="change status" onclick="setRightButton"></button>
            </div>
        </stepper-item>
    </stepper>
</div>
```

```css
/* xxx.css */
.container {
    flex-direction: column;
    align-items: center;
    height: 100%;
    width: 100%;
    background-color: #f7f7f7;
}
.stepper{
    width: 100%;
    height: 100%;
}
.stepper-item {
    width: 100%;
    height: 100%;
    flex-direction: column;
    align-items: center;
}
.item{
    width: 90%;
    height: 86%;
    margin-top: 80px;
    background-color: white;
    border-radius: 60px;
    flex-direction: column;
    align-items: center;
    padding-top: 160px;
}
text {
    font-size: 78px;
    color: #182431;
    opacity: 0.4;
}
.button {
    width: 40%;
    margin-top: 100px;
    justify-content: center;
}
```

```js
// xxx.js
import prompt from '@ohos.promptAction';

export default {
    data: {
        label_1:
        {
            prevLabel: 'BACK',
            nextLabel: 'NEXT',
            status: 'normal'
        },
        label_2:
        {
            prevLabel: 'BACK',
            nextLabel: 'NEXT',
            status: 'normal'
        },
        label_3:
        {
            prevLabel: 'BACK',
            nextLabel: 'NEXT',
            status: 'normal'
        }
    },
    setRightButton(e) {
        this.$element('mystepper').setNextButtonStatus({
            status: 'waiting', label: 'SKIP'
        });
    },
    nextclick(e) {
        var index = {
            pendingIndex: e.pendingIndex
        }
        return index;
    },
    backclick(e) {
        var index = {
            pendingIndex: e.pendingIndex
        }
        return index;
    },
    statuschange(e) {
        prompt.showToast({
            message: 'Previous step index' + e.prevIndex + 'Current step index' + e.index
        })
    },
    finish() {
        prompt.showToast({
            message:'Finished.'
        })
    },
    skip() {
        prompt.showToast({
            message: 'Skip triggered'
        })
    }
}
```

![](figures/stepper.gif)
