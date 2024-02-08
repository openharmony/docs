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
| prevLabel | string | Text label of the button on the left, which is not displayed on the first page. When the **\<Stepper>** contains more than one page, the default value for all pages except the first page is **Back**.|
| nextLabel | string | Text label of the button on the right. The default value is **Start** for the last page and **Next** for the other pages.|
| status | [ItemState](#itemstate) | Display status of **nextLabel** in the stepper. Optional.<br>Default value: **ItemState.Normal**|

>  **NOTE**
>
>  - The **\<StepperItem>** component does not support setting of the universal width attribute. By default, its width is the same as that of the parent **\<Stepper>** component.
>  - The **\<StepperItem>** component does not support setting of the universal height attribute. Its height is the height of the parent **\<Stepper>** component minus the height of the label button.
>  - The **\<StepperItem>** component does not support setting of the **aspectRadio** or **constrainSize** attribute, which may affect the length and width.
## ItemState

|   Name   | Description|
| -------- |-------- |
| Normal |The button on the right is clickable and can navigate users to the next **\<StepperItem>** when it is clicked.|
| Disabled |The button on the right is disabled.|
| Waiting | The button on the right is not displayed, and a progress bar is displayed instead.|
| Skip |The button on the right reads "Skip" by default. You can define the processing logic for this state in the **onSkip** callback of the stepper.|


## Example

See [Stepper](ts-basic-components-stepper.md).
