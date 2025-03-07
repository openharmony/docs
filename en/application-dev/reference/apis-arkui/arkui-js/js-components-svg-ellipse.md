# ellipse


>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **\<ellipse>** component is used to draw oval shapes.

## Required Permissions

None


## Child Components

The following are supported: [\<animate>](js-components-svg-animate.md), [\<animateMotion>](js-components-svg-animatemotion.md), and [\<animateTransform>](js-components-svg-animatetransform.md).


## Attributes

The [universal attributes](js-components-svg-common-attributes.md) and the attributes listed below are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | No| Unique ID of the component.|
| cx | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| X-coordinate of the oval shape. Attribute animations are supported.|
| cy | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| Y-coordinate of the oval shape. Attribute animations are supported.|
| rx | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| Radius of the oval shape on the x-axis. Attribute animations are supported.|
| ry | &lt;length&gt;\|&lt;percentage&gt; | 0 | No| Radius of the oval shape on the y-axis. Attribute animations are supported.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <ellipse cx="60" cy="200" rx="50" ry="100" stroke-width="4" fill="red" stroke="blue"></ellipse>
    <ellipse cx="220" cy="200" rx="100" ry="50" stroke-width="5" stroke="red" stroke-dasharray="10 5" stroke-dashoffset="3"></ellipse>
  </svg>
</div>
```


![en-us_image_0000001173164793](figures/en-us_image_0000001173164793.png)
