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
| prevLabel | string | Text label of the button on the left. When the **\<Stepper>** contains more than one page, the default value for all pages except the first page is **Back**.|
| nextLabel | string | Text label of the button on the right. The default value is **Start** for the last page and **Next** for the other pages.|
| status | ItemState | Display status of **nextLabel** in the stepper.<br>Default value: **ItemState.Normal**|

## ItemState

|   Name   |   Value   | Description|
| -------- | -------- |-------- |
| Normal |  0  |The button on the right is clickable and can navigate users to the next **\<StepperItem>** when it is clicked.|
| Disabled |  1  |The button on the right is grayed out and unavailable.|
| Waiting |  2  | The button on the right is not displayed, and a progress bar is displayed instead.|
| Skip |  3  |The button on the right reads "Skip". You can define the processing logic for this state in the **onSkip** callback of the stepper.|


## Example

See [Stepper](ts-basic-components-stepper.md).
