# option

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

When used as a child component of [\<select>](js-components-basic-select.md), the **\<option>** component is used to display items in the drop-down list.


When used as a child component of [\<menu>](js-components-basic-menu.md), the **\<option>** component is used to display items in the displayed menu.


## Required Permissions

None


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name      | Type     | Default Value | Mandatory  | Description                                      |
| -------- | ------- | ---- | ---- | ---------------------------------------- |
| selected | boolean | -    | No   | Whether the option is the default option in the drop-down list. This attribute is available only when the parent component is **\<select>**.         |
| value    | string  | -    | Yes   | Value of the option, which is used as the return value of the **selected** event of the **\<select>** or **\<menu>** parent component.<br>The value to be displayed on the UI must be put between the start and end tags, for example,<br>**\<option value="10">October\</option>**. |
| icon     | string  | -    | No   | Icon resource path. This icon is displayed before the option text. The supported icon formats are JPG, PNG, and SVG.    |


## Styles

The following styles are supported.

| Name             | Type                        | Default Value       | Mandatory  | Description                                      |
| --------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| color           | &lt;color&gt;              | \#e6000000 | No   | Font color of the option.                               |
| font-size       | &lt;length&gt;             | 16px       | No   | Font size of the option.                               |
| allow-scale     | boolean                    | true       | No   | Whether the font size changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| font-weight     | number \| string | normal     | No   | Font weight of the option. For details, see **font-weight** of the [**\<text>**](js-components-basic-text.md#styles) component. |
| text-decoration | string                     | none       | No   | Text modification of an option. For details, see **text-decoration** of the [**\<text>**](js-components-basic-text.md#styles) component. |
| font-family     | string                     | sans-serif | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](js-components-common-customizing-font.md) is used for the text.|


## Events

Not supported


## Methods

Not supported


## Example

For details, see [Example in menu](js-components-basic-menu.md#example).
