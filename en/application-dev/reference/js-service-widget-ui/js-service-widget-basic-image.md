# image


The **\<image>** component is used to render and display images.

> **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-service-widget-common-attributes.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| src | string | - | No| Image path.<br>- The local path is supported. Supported formats are as follows: PNG, JPG, BMP, SVG, and GIF.<br>- The path to the in-memory image is also supported in the scheme format of **memory://**.<br>**NOTE**<br>To display an online image, download it and then access it with its in-memory path. Do not use URLs.|
| alt | string | - | No| Placeholder image displayed during image loading.|


## Styles

In addition to the [universal styles](js-service-widget-common-styles.md), the following styles are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| object-fit | string | cover | No| Image scale type. For details about available values, see **object-fit**. This style is not supported for SVG images.|
| match-text-direction | boolean | false | No| Whether image orientation changes with the text direction. This style is not supported for SVG images.|
| fit-original-size | boolean | false | No| Whether the **\<image>** component adapts to the image source size when its width and height are not set. If this style is set to **true**, **object-fit** will not take effect. This style is not supported for SVG images.|

**Table 1** object-fit

| Type| Description|
| -------- | -------- |
| cover | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries and displayed in the middle.|
| contain | The image is scaled with the aspect ratio retained for the image to be completely displayed within the display boundaries and displayed in the middle.|
| fill | The image is scaled to fill the display area, and its aspect ratio is not retained.|
| none | The image is displayed in the middle with its aspect ratio and size retained.|
| scale-down | The image is displayed in the middle with its aspect ratio retained, in the size equal to or smaller than the original size.|

>  **NOTE**
>
>  When using an SVG image, note that:
>
>  - The SVG image will not be drawn if the length or width of the parent component is infinity. Therefore, you are advised to set the length and width for the **\<image>** component.
>
>  - If the image length and width are not specified in the SVG description, the SVG image fills the **\<image>** component area.
>
>  - If the image length and width are specified in the SVG description, the following rules are adopted to decide the final display effect:
>
>    - If the **\<image>** component is too small to afford the SVG image, the SVG image is cropped and only its upper left part is displayed in the component.
>
>    - If the **\<image>** component is big enough to afford the SVG image, the SVG image is displayed in the upper left corner of the component.


## Events

| Name| Parameter| Description|
| -------- | -------- | -------- |
| click | - | Triggered when the component is clicked.|
| complete | - | Triggered when the image is successfully loaded.|
| error | - | Triggered when an exception occurs during image loading.|


## Example


```html
<!-- xxx.hml -->
<stack class="content">
    <image src="/common/bg3.jpg" class="img"></image>
</stack>
```


```css
/* xxx.css */
.img{  
  object-fit: contain
}
```
**4 x 4 widget**

![image.jpg](figures/image.jpg)
