# circle

The  **<circle\>**  component is used to draw circles.

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
| cx   | \<length>\|\<percentage> | 0             | No        | X-coordinate of the circle center. Attribute animations are supported. |
| cy   | \<length>\|\<percentage> | 0             | No        | Y-coordinate of the circle center. Attribute animations are supported. |
| r    | \<length>\|\<percentage> | 0             | No        | Radius of the circle. Attribute animations are supported.    |


## Example

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <circle cx="60" cy="200" r="50" stroke-width="4" fill="red" stroke="blue"></circle>
    <circle cx="180" cy="200" r="50" stroke-width="10" stroke="red" stroke-dasharray="10 5" stroke-dashoffset="3"></circle>
  </svg>
</div>
```

![](figures/en-us_image_0000001173164853.png)

