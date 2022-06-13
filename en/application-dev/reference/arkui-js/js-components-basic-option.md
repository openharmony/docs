# option

When used as a child component of **\<[select](js-components-basic-select.md)>**, the **\<option>** component is used to display items in the drop-down list.

When used as a child component of **\<[menu](js-components-basic-menu.md)>**, the **\<option>** component is used to display items in the displayed menu.

## Required Permissions

None

## Child Component

None

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name     | Type    | Default Value | Mandatory | Description                                                  |
| -------- | ------- | ------------- | --------- | ------------------------------------------------------------ |
| selected | boolean | -             | No        | Whether an option is the default option in the drop-down list. This attribute is available only when the parent component is **\<select>**. |
| value    | string  | -             | Yes       | Value of an option, which is used as the return value of the selected event of the **\<select>**or **\<menu>** parent component.NOTE:The option value to be displayed on the UI must be put between the start and end tags, for example, **\<option value="10">October\</option>**. |
| icon     | string  | -             | No        | Icon resource path. This icon is displayed before the option text. The supported icon formats are JPG, PNG, and SVG. |

## Styles

The following style attributes are supported.



| Name            | Type             | Default Value | Mandatory | Description                                                  |
| --------------- | ---------------- | ------------- | --------- | ------------------------------------------------------------ |
| color           | \<color>          | #e6000000     | No        | Text color of the options.                                   |
| font-size       | \<length>         | 16px          | No        | Font size of the options.                                    |
| allow-scale     | boolean          | true          | No        | Whether the font size changes with the system's font size settings.NOTE:If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart. |
| font-weight     | number \| string | normal        | No        | Font weight. For details, see [font-weight](js-components-basic-text.md) of the **text** component. |
| text-decoration | string           | none          | No        | Text decoration. For details, see [text-decoration](js-components-basic-text.md) of the **text** component. |
| font-family     | string           | sans-serif    | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) is used for the text. |

## Events

None

## Methods

None

## Example Code

For details, see the [menu example code](js-components-basic-menu.md).