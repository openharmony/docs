# StepperItem

The **StepperItem** component provides an element for the **Stepper** component.


>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component supports only one child component.


## APIs

StepperItem()

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Attributes

### prevLabel

prevLabel(value: string)

Sets the text label of the button on the left, which is not displayed on the first page. When the **Stepper** contains more than one page, the default value for all pages except the first page is **Back**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| Text label of the button on the left.|

### nextLabel

nextLabel(value: string)

Sets the text label of the button on the right. The default value is **Start** for the last page and **Next** for the other pages.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                           | Mandatory| Description                                                        |
| ------ | ------------------------------- | ---- | ------------------------------------------------------------ |
| value  | string                          | Yes  | Text label of the button on the right.                                          |

### status

status(value?: ItemState)

Sets the display status of **nextLabel** in the stepper.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                           | Mandatory| Description                                                        |
| ------ | ------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ItemState](#itemstate) | No  | Display status of **nextLabel** in the stepper.<br>Default value: **ItemState.Normal**|

>  **NOTE**
>
>  - The **StepperItem** component does not support setting of the universal width attribute. By default, its width is the same as that of the parent **Stepper** component.
>  - The **StepperItem** component does not support setting of the universal height attribute. Its height is the height of the parent **Stepper** component minus the height of the label button.
>  - The **StepperItem** component does not support setting of the **aspectRadio** or **constrainSize** attribute, which may affect the length and width.
## ItemState

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

|   Name   | Description|
| -------- |-------- |
| Normal |The button on the right is clickable and can navigate users to the next **StepperItem** when it is clicked.|
| Disabled |The button on the right is disabled.|
| Waiting | The button on the right is not displayed, and a progress bar is displayed instead.|
| Skip |The button on the right reads "Skip" by default. You can define the processing logic for this state in the **onSkip** callback of the stepper.|


## Example

See [Stepper](ts-basic-components-stepper.md).
