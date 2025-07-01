# stepper-item

>  **NOTE**
> This component is supported since API version 5. Updates will be marked with a superscript to indicate their earliest API version.

The **\<stepper-item>** component displays a step in the step navigator. This component is the child component of **\<stepper>**.


## Required Permissions

None


## Child Components

Supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | Label | No| Button text at the bottom of the customized step navigator. Dynamic modification is not supported. If this attribute is not set, **BACK** and **NEXT** will be used by default as button text in case the system language is not Chinese. For the first step, there is no previous button. For the last step, the text on the next button is **START** for non-Chinese languages by default.|

**Table 1** label

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| prevLabel | string | - | Text content of the previous button at the bottom of the step navigator.|
| nextLabel | string | - | Text content of the next button at the bottom of the step navigator.|
| status | string | normal | Initial status of the current step in the step navigator. Available values are as follows:<br>- **normal**: The right button is clickable and can navigate users to the next step when it is clicked.<br>- **disabled**: The right button is grayed out and unavailable.<br>- **waiting**: The right button is not displayed, and a progress bar is displayed instead.|


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| color | &lt;color&gt; | - | No| Text color.|
| font-size | &lt;length&gt; | - | No| Text size.|
| allow-scale | boolean | true | No| Whether the font size changes with the system's font size settings.|
| font-style | string | normal | No| Text font style. Available values are as follows:<br>- **normal**: standard font style<br>- **italic**: italic font style|
| font-weight | number\|string | normal | No| Text font weight. The number value must be an exact multiple of 100 ranging from 100 to 900. The default value is 400. A larger value indicates a bigger weight. Available values of the string type are **lighter**, **normal**, **bold**, or **bolder**.|
| text-decoration | string | none | No| Text decoration. Available values are as follows:<br>- **underline**: An underline is used.<br>- **line-through**: A strikethrough is used.<br>- **none**: The standard text is used.|
| font-family | string | sans-serif | No| Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](js-components-common-customizing-font.md) is used for the text.|

>  **NOTE**
> - Height and width styles are not supported. The width of each item is the same as that of its container. The height of each item is the difference between the container height and the bottom button height.
> 
> - The **position** style is not supported.


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name| Parameter| Description|
| -------- | -------- | -------- |
| appear | - | Triggered when this step is displayed.|
| disappear | - | Triggered when this step disappears.|


## Method

The [universal methods](js-components-common-methods.md) are supported.


## Example

For details, see **Example** in [stepper](js-components-container-stepper.md).
