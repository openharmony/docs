# StepperItem


> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;StepperItem&gt;** component provides an element for the **&lt;Stepper&gt;** component.


## Required Permissions

None


## Child Components

This component supports only one child component.


## APIs

StepperItem()


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| prevLabel | string | - | When the **&lt;Stepper&gt;** contains more than one page, the default value for all pages except the first page is **Back**. |
| nextLabel | string | - | When the stepper contains more than one page, the default value for the last page is **Start**, and the default value for other pages is **Next**. |
| status | ItemState | ItemState.Normal | Status of the **&lt;StepperItem&gt;**. |

- ItemState enums
  | Name | Description | 
  | -------- | -------- |
  | Normal | The right button is clickable and can navigate users to the next **&lt;StepperItem&gt;** when it is clicked. | 
  | Disabled | The right button is grayed out and unavailable. | 
  | Waiting | The right button is not displayed, and a progress bar is displayed instead. | 
  | Skip | The current **&lt;StepperItem&gt;** is skipped, and the next **&lt;StepperItem&gt;** is displayed. | 


## Example

See [Stepper](ts-basic-components-stepper.md).

