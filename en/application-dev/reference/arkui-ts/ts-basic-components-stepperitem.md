# StepperItem

The **\<StepperItem>** component provides an element for the **\<Stepper>** component.


>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component supports only one child component.


## APIs

StepperItem()


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| prevLabel | string | When the **\<Stepper>** contains more than one page, the default value for all pages except the first page is **Back**.|
| nextLabel | string | When the stepper contains more than one page, the default value for the last page is **Start**, and the default value for other pages is **Next**.|
| status | ItemState | Status of the **\<StepperItem>**.<br>Default value: **ItemState.Normal**|

## ItemState

| Name| Description|
| -------- | -------- |
| Normal | The right button is clickable and can navigate users to the next **\<StepperItem>** when it is clicked.|
| Disabled | The right button is grayed out and unavailable.|
| Waiting | The right button is not displayed, and a progress bar is displayed instead.|
| Skip | The current **\<StepperItem>** is skipped, and the next **\<StepperItem>** is displayed.|


## Example

See [Stepper](ts-basic-components-stepper.md).
