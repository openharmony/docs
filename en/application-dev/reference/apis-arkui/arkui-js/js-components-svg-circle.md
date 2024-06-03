# circle


>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **\<circle>** component is used to draw circles.

## Required Permissions

None


## Child Components

The following are supported: [\<animate>](js-components-svg-animate.md), [\<animateMotion>](js-components-svg-animatemotion.md), and [\<animateTransform>](js-components-svg-animatetransform.md).


## Attributes

The [universal attributes](js-components-svg-common-attributes.md) and the attributes listed below are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | No| Unique ID of the component.|
| cx | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| X-coordinate of the circle center. Attribute animations are supported.|
| cy | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| Y-coordinate of the circle center. Attribute animations are supported.|
| r | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| Radius of the circle. Attribute animations are supported.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <circle cx="60" cy="200" r="50" stroke-width="4" fill="red" stroke="blue"></circle>
    <circle cx="180" cy="200" r="50" stroke-width="10" stroke="red" stroke-dasharray="10 5" stroke-dashoffset="3"></circle>
  </svg>
</div>
```


![en-us_image_0000001173164853](figures/en-us_image_0000001173164853.png)
