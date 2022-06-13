# image

The **\<image>** component is used to render and display images.

## Child Component

Not supported

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name | Type   | Default Value | Mandatory | Description                                                  |
| ---- | ------ | ------------- | --------- | ------------------------------------------------------------ |
| src  | string | -             | No        | Image path, which supports local paths. The supported image formats include PNG, JPG, BMP, SVG, and GIF.Base64 string6+ is supported. The format is data:image/[png \| jpeg \| bmp \| webp];base64, [base64 data],, where [base64 data] is a Base64 string.The path prefix of **dataability://** is supported, which allows access to the image path provided by the Data ability. |
| alt  | string | -             | No        | Placeholder image displayed during image loading.            |

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following style attributes are supported.



| Name                 | Type    | Default Value | Mandatory | Description                                                  |
| -------------------- | ------- | ------------- | --------- | ------------------------------------------------------------ |
| object-fit           | string  | cover         | No        | Image scale type. For details about available values, see [Types of the object-fit style](js-components-basic-image.md). The SVG format is not supported. |
| match-text-direction | boolean | false         | No        | Whether image orientation changes with the text direction. The SVG format is not supported. |
| fit-original-size    | boolean | false         | No        | Whether the **\<image>** component adapts to the image source size when the width and height are not set. If this attribute is set to **true**, the **object-fit** attribute does not take effect. SVG images do not support this attribute. |
| object-position7+    | string  | 0px 0px       | No        | Position of an image in the component.There are two setting types:1. Pixels. For example, **15px 15px** indicates the moving position along the x-axis or y-axis.2. Characters. Optional values are as follows:<br>-**left**: The image is displayed on the left of the component.<br>-**top** The image is displayed on the top of the component.<br>-**right** The image is displayed on the right of the component.<br>-**bottom** The image is displayed at the bottom of the component. |

**Table 1** Types of the object-fit style



| Type       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| cover      | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries and displayed in the middle. |
| contain    | The image is scaled with the aspect ratio retained for the image to be completely displayed within the display boundaries and displayed in the middle. |
| fill       | The image is resized to fill the display area and its aspect ratio is not retained. |
| none       | The image is displayed in the middle with its aspect ratio and size retained. |
| scale-down | The image is displayed in the middle with its aspect ratio retained. The size is equal to or smaller than the original size. |

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** When using an SVG image, note that:
>
> - The SVG image will not be drawn if the length or width of the **\<image>** component is infinity.
> - If the image length and width are not specified in the SVG description, the SVG fills the **\<image>** component area.
> - If the image length and width are specified in the SVG description, the following rules are adopted to decide the final display effect:
>
> 1. If the **\<image>** component is too small to afford the SVG image, the SVG image is cropped and only its upper left part is displayed in the component.
> 2. If the **\<image>** component is big enough to afford the SVG image, this SVG image is displayed in the upper left corner of the component.

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name           | Parameter                        | Description                                                  |
| -------------- | -------------------------------- | ------------------------------------------------------------ |
| complete(Rich) | { width: width, height: height } | Triggered when an image is successfully loaded. The loaded image is returned. |
| error(Rich)    | { width: width, height: height } | Triggered when an exception occurs during image loading. In this case, the width and height are **0**. |

## Methods

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example Code

```
<!-- xxx.hml -->
<div class="container">
  <image src="common/images/example.png" style="width: 300px; height: 300px; object-fit:{{fit}}; object-position: center center; border: 1px solid red; ">
  </image>
  <select class="selects" onchange="change_fit">
    <option for="{{fits}}" value="{{$item}}">{{$item}}</option>
  </select>
</div>
/* xxx.css */
.container {
  justify-content: center;
  align-items: center;
  flex-direction: column;
  
  
}
.selects{
  margin-top: 20px;
  width:300px;
  border:1px solid #808080;
  border-radius: 10px;
}
// xxx.js
export default {
  data: {
    fit:"cover",
    fits: ["cover", "contain", "fill", "none", "scale-down"],
  },
  change_fit(e) {
    this.fit = e.newValue;
  },
}
```

![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/example.gif)