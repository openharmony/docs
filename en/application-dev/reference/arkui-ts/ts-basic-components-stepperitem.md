# StepperItem


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;StepperItem&gt;** component provides an element for the **&lt;Stepper&gt;** component.


## Required Permissions

None


## Child Components

This component supports only one child component.


## APIs

StepperItem()


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| prevLabel | string | - | When&nbsp;the&nbsp;**&lt;Stepper&gt;**&nbsp;contains&nbsp;more&nbsp;than&nbsp;one&nbsp;page,&nbsp;the&nbsp;default&nbsp;value&nbsp;for&nbsp;all&nbsp;pages&nbsp;except&nbsp;the&nbsp;first&nbsp;page&nbsp;is&nbsp;**Back**. |
| nextLabel | string | - | When&nbsp;the&nbsp;stepper&nbsp;contains&nbsp;more&nbsp;than&nbsp;one&nbsp;page,&nbsp;the&nbsp;default&nbsp;value&nbsp;for&nbsp;the&nbsp;last&nbsp;page&nbsp;is&nbsp;**Start**,&nbsp;and&nbsp;the&nbsp;default&nbsp;value&nbsp;for&nbsp;other&nbsp;pages&nbsp;is&nbsp;**Next**. |
| status | ItemState | ItemState.Normal | Status&nbsp;of&nbsp;the&nbsp;**&lt;StepperItem&gt;**. |

- ItemState enums
    | Name | Description | 
  | -------- | -------- |
  | Normal | The&nbsp;right&nbsp;button&nbsp;is&nbsp;clickable&nbsp;and&nbsp;can&nbsp;navigate&nbsp;users&nbsp;to&nbsp;the&nbsp;next&nbsp;**&lt;StepperItem&gt;**&nbsp;when&nbsp;it&nbsp;is&nbsp;clicked.. | 
  | Disabled | The&nbsp;right&nbsp;button&nbsp;is&nbsp;grayed&nbsp;out&nbsp;and&nbsp;unavailable. | 
  | Waiting | The&nbsp;right&nbsp;button&nbsp;is&nbsp;not&nbsp;displayed,&nbsp;and&nbsp;a&nbsp;progress&nbsp;bar&nbsp;is&nbsp;displayed&nbsp;instead. | 
  | Skip | The&nbsp;current&nbsp;**&lt;StepperItem&gt;**&nbsp;is&nbsp;skipped,&nbsp;and&nbsp;the&nbsp;next&nbsp;**&lt;StepperItem&gt;**&nbsp;is&nbsp;displayed. | 


## Example

See [Stepper](ts-basic-components-stepper.md).

