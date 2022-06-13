# rating

The **\<rating>** component provides a rating bar used for reviews and ratings.

## Required Permissions

None

## Child Components

Not supported

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name      | Type    | Default Value | Mandatory | Description                                                  |
| --------- | ------- | ------------- | --------- | ------------------------------------------------------------ |
| numstars  | number  | 5             | No        | Maximum number of rating stars.                              |
| rating    | number  | 0             | No        | Current rating stars.                                        |
| stepsize  | number  | 0.5           | No        | Step to increment the rating value.                          |
| indicator | boolean | false         | No        | Whether to make the rating icons as an indicator (not-editable by users). |

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name            | Type                   | Default Value                  | Mandatory | Description                                                  |
| --------------- | ---------------------- | ------------------------------ | --------- | ------------------------------------------------------------ |
| star-background | string                 | -                              | No        | Background image when a rating star is unselected. Only PNG and JPG images in a local path are supported. |
| star-foreground | string                 | -                              | No        | Foreground image when a rating star is selected. Only PNG and JPG images in a local path are supported. |
| star-secondary  | string                 | -                              | No        | Secondary background image when a rating star is partially selected. This image will cover the background image and can only be a PNG or JPG image from a local path. |
| width           | \<length>\|\<percentage> | 120 px60 px (cannot be edited) | No        | Image width. The default value is the width of the default image for five-star ratings. If you do not set the maximum rating value and background images of the rating stars, the default value will be used. |
| height          | \<length>\|\<percentage> | 24px12 px (cannot be edited)   | No        | Image height. The default value is the height of the default image for five-star ratings. If you do not set the maximum rating value and background images of the rating stars, the default value will be used. |
| rtl-flip        | boolean                | true                           | No        | Whether the image source is automatically flipped in the RTL text direction. |

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** You must set **star-background**, **star-secondary**, and **star-foreground**. Otherwise, the rating star is gray, indicating that the image is set incorrectly.

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name   | Parameter          | Description                              |
| ------ | ------------------ | ---------------------------------------- |
| change | { rating: number } | Triggered when the rating value changes. |

## Methods

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example

```
<!-- xxx.hml -->
<div class="container">
  <rating numstars="5" rating="5" @change="changeRating" id="rating">
  </rating>
</div>
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
rating {
  width: 200px;
}
// xxx.js
import prompt from '@system.prompt';
export default {
    changeRating(e){
        prompt.showToast({
            message: e.rating
        });
    }
}
```

![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/1-6.png)