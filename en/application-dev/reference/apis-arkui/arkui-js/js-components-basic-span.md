# span

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

As a child component of **[\<text>](js-components-basic-text.md)**, the **\<span>** component is used as a text modifier.

## Required Permissions

None


## Child Components

Not supported


## Attributes

The [universal attributes](js-components-common-attributes.md) are supported.

>  **NOTE**
>
>  The **focusable** and **disabled** attributes are not supported.


## Styles

Only the following styles are supported.

| Name             | Type                        | Default Value       | Mandatory  | Description                                      |
| --------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color           | &lt;color&gt;              | -          | No   | Font color of the modified text.                            |
| font-size       | &lt;length&gt;             | 30px       | No   | Font size of the modified text.                            |
| allow-scale     | boolean                    | true       | No   | Whether the font size of the modified text changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| font-style      | string                     | normal     | No   | Font style of the modified text. For details, see **font-style** of the [**\<text>**](js-components-basic-text.md#styles) component.|
| font-weight     | number \| string | normal     | No   | Font weight of the modified text. For details, see **font-weight** of the [**\<text>**](js-components-basic-text.md#styles) component.|
| text-decoration | string                     | none       | No   | Text decoration of the modified text. For details, see **text-decoration** of the [**\<text>**](js-components-basic-text.md#styles) component.|
| font-family     | string                     | sans-serif | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](js-components-common-customizing-font.md) is used for the text.|


## Events

Only the click event in [Universal Events](js-components-common-events.md) is supported.


## Methods

Not supported


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <text class="title">
    <span class="spanTxt">span</span>
  </text>
</div>
```

```css
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
  font-size: 80px;
}
```

![en-us_image_0000001152588626](figures/en-us_image_0000001152588626.png)
