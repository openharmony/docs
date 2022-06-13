# span

The **\<span>** child component of **\<[text](js-components-basic-text.md)>** is used as a text modifier.

## Required Permissions

None

## Child Components

The **\<span>** child component is supported.

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** The **focusable** and **disabled** attributes are not supported.

## Styles

Only the following style attributes are supported.



| Name            | Type             | Default Value | Mandatory | Description                                                  |
| --------------- | ---------------- | ------------- | --------- | ------------------------------------------------------------ |
| color           | \<color>          | -             | No        | Font color of the modified text.                             |
| font-size       | \<length>         | 30px          | No        | Font size of the modified text.                              |
| allow-scale     | boolean          | true          | No        | Whether the font size of the modified text changes with the system's font size settings.<br/>NOTE:<br/>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart. |
| font-style      | string           | normal        | No        | Font style of the modified text. For details, see [font-style](js-components-basic-text.md) of the **text** component. |
| font-weight     | number \| string | normal        | No        | Font weight of the modified text. For details, see [font-weight](js-components-basic-text.md) of the **text** component. |
| text-decoration | string           | none          | No        | Text decoration of the modified text. For details, see [text-decoration](js-components-basic-text.md) of the **text** component. |
| font-family     | string           | sans-serif    | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) is used for the text. |

## Events

Only the click event in [Universal Events](js-components-common-events.md) is supported.

## Method

Not supported

## Example Code

```
<!-- xxx.hml -->
<div class="container">
  <text class="title">
    <span class="spanTxt">span</span>
  </text>
</div>
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.title {
  font-size: 30px;
  text-align: center;
  width: 100%;
  height: 100px;
}
.spanTxt{
  color: chartreuse;
  font-size: 100px;
}
```

![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/en-us_image_0000001152588626.png)