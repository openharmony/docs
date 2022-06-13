# ellipse

The  **<ellipse\>**  component is used to draw oval shapes.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

None

## Child Components

**animate**,  **animateMotion**, and  **animateTransform**  are supported.

## Attributes

The  [universal attributes](js-components-svg-common-attributes.md)  and the attributes listed below are supported.

| Name | Type                     | Default Value | Mandatory | Description                                                  |
| ---- | ------------------------ | ------------- | --------- | ------------------------------------------------------------ |
| id   | string                   | -             | No        | Unique ID of the component.                                  |
| cx   | \<length>\|\<percentage> | 0             | No        | X-coordinate of the oval shape. Attribute animations are supported. |
| cy   | \<length>\|\<percentage> | 0             | No        | Y-coordinate of the oval shape. Attribute animations are supported. |
| rx   | \<length>\|\<percentage> | 0             | No        | Radius of the oval shape on the x-axis. Attribute animations are supported. |
| ry   | \<length>\|\<percentage> | 0             | No        | Radius of the oval shape on the y-axis. Attribute animations are supported. |


## Example

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <ellipse cx="60" cy="200" rx="50" ry="100" stroke-width="4" fill="red" stroke="blue"></ellipse>
    <ellipse cx="220" cy="200" rx="100" ry="50" stroke-width="5" stroke="red" stroke-dasharray="10 5" stroke-dashoffset="3"></ellipse>
  </svg>
</div>
```

![](figures/en-us_image_0000001173164793.png)

