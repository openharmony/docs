# line

The  **<line\>**  component is used to draw a line.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

None

## Child Components

**animate**,  **animateMotion**, and  **animateTransform**  are supported.

## Attributes

The universal attributes as well as the attributes listed below are supported.

| Name | Type                     | Default Value | Mandatory | Description                                                  |
| ---- | ------------------------ | ------------- | --------- | ------------------------------------------------------------ |
| id   | string                   | -             | No        | Unique ID of the component.                                  |
| x1   | \<length>\|\<percentage> | -             | No        | X-coordinate of the start point of the line. Attribute animations are supported. |
| y1   | \<length>\|\<percentage> | -             | No        | Y-coordinate of the start point of the line. Attribute animations are supported. |
| x2   | \<length>\|\<percentage> | -             | No        | X-coordinate of the end point of the line. Attribute animations are supported. |
| y2   | \<length>\|\<percentage> | -             | No        | Y-coordinate of the end point of the line. Attribute animations are supported. |


## Example

```
<!-- xxx.hml -->
<div class="container">
  <svg width="400" height="400">
    <line x1="10" x2="300" y1="50" y2="50" stroke-width="4" fill="white" stroke="blue"></line>
    <line x1="10" x2="300" y1="100" y2="100" stroke-width="4" fill="white" stroke="blue"></line>
    <line x1="10" x2="300" y1="150" y2="150" stroke-width="10" stroke="red" stroke-dasharray="5 3" stroke-dashoffset="3"></line>
    <line x1="10" x2="300" y1="200" y2="200" stroke-width="10" stroke="black" stroke-linecap="round"></line>
    <line x1="10" x2="300" y1="220" y2="220" stroke-width="10" stroke="black" stroke-linecap="butt"></line>
    <line x1="10" x2="300" y1="240" y2="240" stroke-width="10" stroke="black" stroke-linecap="square"></line>
  </svg>
</div>
```

![](figures/en-us_image_0000001127284954.png)

