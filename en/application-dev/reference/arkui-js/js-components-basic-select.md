# select

The **\<select>** component provides a drop-down list that allows users to select among multiple options.

## Required Permissions

None

## Child Component

The **\<[option](js-components-basic-option.md)>** child component is supported.

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name        | Type   | Default Value | Mandatory | Description                                                  |
| ----------- | ------ | ------------- | --------- | ------------------------------------------------------------ |
| font-family | string | sans-serif    | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) in the family is selected as the font for the text. |

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name   | Parameter            | Description                                                  |
| ------ | -------------------- | ------------------------------------------------------------ |
| change | {newValue: newValue} | Triggered after a value is selected from the drop-down list. The value of **newValue** is the attribute value of the child component **option**. |

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:**
>
> - The **\<select>** component does not support the **click** event.

## Method

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example Code

```
<!-- xxx.hml -->
<div class="container">
  <select @change="changeFruit">
    <option value="bananaValue">
      Banana
    </option>
    <option value="appleValue" selected="true">
      Apple
    </option>
    <option value="pearValue">
      Pear
    </option>
  </select>
</div>
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
```

![img](figures/en-us_image_0000001152588538.png)