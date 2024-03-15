# polyline


>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **\<polyline>** component is used to draw a polyline.

## Required Permissions

None


## Child Components

The following are supported: [\<animate>](js-components-svg-animate.md), [\<animateMotion>](js-components-svg-animatemotion.md), and [\<animateTransform>](js-components-svg-animatetransform.md).


## Attributes

The [universal attributes](js-components-svg-common-attributes.md) and the attributes listed below are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | No| Unique ID of the component.|
| points | string | - | No| Multiple coordinates of the polyline.<br>The format is [x1,y1 x2,y2 x3,y3].<br>Attribute animations are supported. If the number of coordinates of the animation change value set in the attribute animation is different from the format of the original points, the attribute animation is invalid.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" stroke="blue" width="400" height="400">
    <polyline points="10,110 60,35 60,85 110,10" fill="red"></polyline>
    <polyline points="10,200 60,125 60,175 110,100" stroke-dasharray="10 5" stroke-dashoffset="3"></polyline>
  </svg>
</div>
```


![en-us_image_0000001173164845](figures/en-us_image_0000001173164845.png)
