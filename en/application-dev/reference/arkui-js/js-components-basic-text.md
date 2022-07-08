# text

The **\<text>** component is used to display a piece of textual information.

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:**
>
> - The text content must be written in the content area.

## Required Permissions

None

## Child Component

**\<[span](js-components-basic-span.md)>** is supported.

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name                    | Type                                     | Default Value  | Mandatory | Description                                                  |
| ----------------------- | ---------------------------------------- | -------------- | --------- | ------------------------------------------------------------ |
| color                   | \<color>                                 | #e5000000      | No        | Text color.                                                  |
| font-size               | \<length>                                | 30px           | No        | Font size (px).                                              |
| allow-scale             | boolean                                  | true           | No        | Whether the font size changes with the system's font size settings.<br/>NOTE:<br/>For details about how to make the configuration take effect dynamically, see the **config-changes** attribute in the **config.json** file. |
| letter-spacing          | \<length>                                | 0 px           | No        | Character spacing (px).                                      |
| word-spacing7+          | \<length> \| \<percentage> \| string     | normal         | No        | Spacing between texts. The options are as follows:**normal**: default spacing. |
| font-style              | string                                   | normal         | No        | Font style. Available values are as follows:<br/>-**normal**: standard font style<br/>-**italic**: italic font style |
| font-weight             | number \| string                         | normal         | No        | Font width. For the number type, the value ranges from 100 to 900. The default value is 400. A larger value indicates a larger font width.NOTE:The value must be an integer multiple of 100.The value of the string type can be **lighter**, **normal**, **bold**, or **bolder**. |
| text-decoration         | string                                   | none           | No        | Text decoration. Available values are as follows:<br/>-**underline**: An underline is used.<br/>-**line-through**: A strikethrough is used.<br/>-**none**: The standard text is used. |
| text-decoration-color7+ | \<color>                                 | -              | No        | Color of the text decoration.                                |
| text-align              | string                                   | start          | No        | Text alignment mode. Available values are as follows:<br/>-**left**: The text is left-aligned.<br/>-**center**: The text is center-aligned.<br/>-**right**: The text is right-aligned.<br/>-**start**: The text is aligned with the direction in which the text is written.<br/>-**end**: The text is aligned with the opposite direction in which the text is written.<br/>NOTE:<br/>If the text width is not specified, the alignment effect may not be obvious when the text width is the same as the width of the parent container. |
| line-height             | \<length> \| \<percentage>7+ \| string7+ | 0px1-6normal7+ | No        | Text line height. When this parameter is set to **0px**, the text line height is not limited and the font size is adaptive. The **string** values are as follows:**normal**7+: default line height |
| text-overflow           | string                                   | clip           | No        | Takes effect when the maximum number of lines is specified. Available values are as follows:<br/>-**clip**: The text is clipped and displayed based on the size of the parent container.<br/>-**ellipsis**: The text is displayed based on the size of the parent container. The text that cannot be displayed is replaced with ellipsis. This style must be used together with **max-lines**. |
| font-family             | string                                   | sans-serif     | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) in the family is selected as the font for the text. |
| max-lines               | number \| string7+                       | -              | No        | Maximum number of text lines. The **string** values are as follows:<br/>-**auto**7+: The number of text lines adapts to the container height. |
| min-font-size           | \<length>                                | -              | No        | Minimum font size in the text. This style must be used together with **max-font-size**. The font size can be changed dynamically. After the maximum and minimum font sizes are set, **font-size** does not take effect. |
| max-font-size           | \<length>                                | -              | No        | Maximum font size in the text. This style must be used together with **min-font-size**. The font size can be changed dynamically. After the maximum and minimum font sizes are set, **font-size** does not take effect. |
| font-size-step          | \<length>                                | 1px            | No        | Step for dynamically adjusting the font size in the text. The minimum and maximum font sizes must be set. |
| prefer-font-sizes       | \<array>                                 | -              | No        | Preset preferred font sizes. For dynamic font size adjustment, the preset sizes are used to match the maximum number of lines in the text. If the preferred font sizes were not set, the font size will be adjusted based on the maximum and minimum font sizes and the step you have set. If the maximum number of lines in the text cannot be met, **text-overflow** is used to truncate the text. If this parameter is set, **font-size**, **max-font-size**, **min-font-size**, and **font-size-step** do not take effect.Example values: **12px,14px,16px** |
| word-break6+            | string                                   | normal         | No        | Text line breaking mode. The options are as follows:<br/>-**normal**: Allows text line breaks between words as appropriate to the relevant language writing systems. This is the default mode.<br/>-**break-all**: Allows text line breaks between any characters for writing systems other than Chinese, Japanese, and Korean.<br/>-**break-word**: Has the same effect as **break-all**, except that it does not break unbreakable words. |
| text-indent7+           | \<length>                                | -              | No        | Indentation of the first line.                               |
| white-space7+           | string                                   | pre            | No        | Mode for processing blanks in the component. The options are as follows:<br/>-**normal**: All spaces, carriage returns, and tabs are combined into one space, and the text is automatically wrapped.<br/>-**nowrap**: All spaces, carriage returns, and tabs are combined into one space, and the text is not wrapped.<br/>-**pre**: All contents are output as-is.<br/>-**pre-wrap**: All contents are output as-is with line breaks.<br/>-**pre-line**: All spaces and tabs are combined into one space, the carriage return remains unchanged, and the text is wrapped. |
| adapt-height7+          | boolean                                  | false          | No        | Whether the text size adapts to the container height.NOTE:The settings take effect after font size auto-adaptation is configured. |

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:**
>
> - In dynamic font adjustment, both the preset size set and the minimum/maximum font sizes are used to adjust the font size to display the text within the maximum number of lines. The preset size set is checked from left to right, and the minimum/maximum font sizes are checked from large to small, to find a size meeting the requirement.
> - Use the escape character **\r\n** for newline.
> - The following escape characters are supported: **\a**, **\b**, **\f**, **\n**, **\r**, **\t**, **\v**, **\'**, **\"**, and **\0**.
> - When you use **\<span>** as a child component to form a text paragraph, note that if a **\<span>** style is abnormal, the text paragraph cannot be displayed.
> - The **letter-spacing**, **text-align**, **line-height**, **text-overflow**, and **max-lines** styles take effect on text content held by the **\<text>** component and its child components (**\<span>**).
> - The **\<text>** component does not support the coexistence of the text content and **\<span>** subcomponents. (If both of them exist, only the content in **\<span>** is displayed.)

## Events

Events in [Universal Events](js-components-common-events.md) are supported.

## Method

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example Code

```
<!-- xxx.hml -->
<div class="container">
  <div class="content">
    <text class="title">
      Hello {{ title }}
    </text>
  </div>
</div>
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.content{
  width: 400px;
  height: 400px;
  border: 20px;
}
.title {
  font-size: 80px;
  text-align: center;
  width: 400px;
  height: 400px;
}
// xxx.js
export default {
  data: {
    title: 'World'
  }
}
```

![img](figures/3.png)

```
<!-- xxx.hml -->
<div class="container">
  <text class="text1">
    This is a passage
  </text>
  <text class="text2">
    This is a passage
  </text>
</div>
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  background-color: #F1F3F5;
  justify-content: center;
}
.text1{
  word-spacing: 10px;
  adapt-height: true;
}
.text2{
  width: 200px;
  max-lines: 1;
  text-overflow: ellipsis;
  text-valign: middle;
  line-height: 40px;
  text-decoration: underline;
  text-decoration-color: red;
  text-indent: 20px;
  white-space: pre;
}
```

![img](figures/2.png)