# toolbar-item

The **\<toolbar-item>** component is the child component of **\<toolbar>** to display an operation option on the toolbar.

## Child Component

None

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name  | Type   | Default Value | Mandatory | Description                                                  |
| ----- | ------ | ------------- | --------- | ------------------------------------------------------------ |
| value | string | -             | Yes       | Text content of the operation option.                        |
| icon  | string | -             | Yes       | Icon image path, which is displayed on the option text. The value is a local path. Supported image formats are PNG, JPG, and SVG. |

## Styles

Only the following style attributes are supported.



| Name                | Type                                                         | Default Value | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------------------------ | ------------- | --------- | ------------------------------------------------------------ |
| color               | \<color>                                                     | #e6000000     | No        | Text color.                                                  |
| font-size           | \<length>                                                    | 16px          | No        | Text size.                                                   |
| allow-scale         | boolean                                                      | true          | No        | Whether the text size changes with the system's font size settings. |
| font-style          | string                                                       | normal        | No        | Text font style. Available values are as follows:<br/>-**normal**: standard font style<br/>-**italic**: italic font style |
| font-weight         | number\|string                                               | normal        | No        | Text font weight. The number value must be an exact multiple of 100 ranging from 100 to 900. The default value is 400. A larger value indicates a bigger weight. Available values of the string type are **lighter**, **normal**, **bold**, or **bolder**. |
| text-decoration     | string                                                       | none          | No        | Text decoration. Available values are as follows:<br/>-**underline**: An underline is used.<br/>-**line-through**: A strikethrough is used.<br/>-**none**: The standard text is used. |
| font-family         | string                                                       | sans-serif    | No        | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified by [Custom Font Styles](js-components-common-customizing-font.md) is used for the text. |
| background          | \<linear-gradient>                                           | -             | No        | This attribute supports [Gradient Styles](js-components-common-gradient.md) only but is not compatible with **background-color** or **background-image**. |
| background-color    | \<color>                                                     | -             | No        | Background color.                                            |
| background-image    | string                                                       | -             | No        | Background image. Currently, this attribute is not compatible with **background-color** or **background**. Both online and local image resources are supported. |
| background-size     | <br/>-string<br/>-\<length> \<length><br/>-\<percentage> \<percentage> | auto          | No        | Background image size.<br/>-The **string** values are as follows:<br/>  -**contain**: Expands the image to the maximum size so that the height and width of the image are applicable to the content area.<br/>  -**cover**: Extends the background image to a large enough size so that the background image completely covers the background area. Some parts of the image may not be displayed in the background area.<br/>  -**auto**: The original image width-height ratio is retained.<br/>-The two **\<length>** values are as follows:Width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to **auto** by default.<br/>-The two **\<percentage>** values are as follows:Width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to **auto** by default. |
| background-repeat   | string                                                       | repeat        | No        | Repeating attribute of a background image. By default, a background image is repeated both horizontally and vertically.<br/>-**repeat**: Repeatedly draws images along the x-axis and y-axis at the same time.<br/>-**repeat-x**: Repeatedly draws images along the x-axis.<br/>-**repeat-y**: Repeatedly draws images along the y-axis.<br/>-**no-repeat**: The image is not drawn repeatedly. |
| background-position | string string\<length> \<length>\<percentage> \<percentage>  | 0px 0px       | No        | <br/>-Using keywords: If only one keyword is specified, the other value is **center** by default. The two values define the horizontal position and vertical position, respectively.<br/>  -**left**: leftmost in the horizontal direction<br/>  -**right**: rightmost in the horizontal direction<br/>  -**top**: top in the vertical direction<br/>  -**bottom**: bottom in the vertical direction<br/>  -**center**: center position<br/>-Using **\<length>**: The first value indicates the horizontal position, and the second value indicates the vertical position. **0 0** indicates the upper left corner. The unit is pixel. If only one value is specified, the other one is **50%**.<br/>-Using **\<percentage>**: The first value indicates the horizontal position, and the second value indicates the vertical position. **0% 0%** indicates the upper left corner. **100% 100%** indicates the lower right corner. If only one value is specified, the other one is **50%**.<br/>-Using both **\<percentage>** and **\<length>**. |
| opacity             | number                                                       | 1             | No        | Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent. |
| display             | string                                                       | flex          | No        | Type of the box containing an element. Available values are as follows:<br/>-**flex**: flexible layout<br/>-**none**: The box is disabled. |
| visibility          | string                                                       | visible       | No        | Whether to display the box containing an element. The invisible box occupies layout space. (To remove the box, set the **display** attribute to **none**.) Available values are as follows:<br/>-**visible**: The box is visible.<br/>-**hidden**: The box is hidden but still takes up space.<br/>NOTE:<br/>If both **visibility** and **display** are set, only **display** takes effect. |

## Events

Events in [Universal Events](js-components-common-events.md) are supported.

## Method

Not supported

## Example

```
<!-- xxx.hml -->
<toolbar style="position: fixed; bottom: 0px; ">    
   <toolbar-item icon='common/Icon/location.png' value='Option 1' >   </toolbar-item>
   <toolbar-item icon='common/Icon/heart.png' value='Option 2'>   </toolbar-item>    
   <toolbar-item icon='common/Icon/diamond.png' value='Option 3'  >   </toolbar-item>    
   <toolbar-item icon='common/Icon/heart.png' value='Option 4' >   </toolbar-item>    
   <toolbar-item icon='common/Icon/heart.png' value='Option 5' >   </toolbar-item>
   <toolbar-item icon='common/Icon/heart.png' value='Option 6'>   </toolbar-item> 
</toolbar>
```

![img](figures/progress-7.jpg)