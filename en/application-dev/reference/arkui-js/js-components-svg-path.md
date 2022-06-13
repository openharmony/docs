# path

The  **<path\>**  component is used to draw a path.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

None

## Child Components

**animate**,  **animateMotion**, and  **animateTransform**  are supported.

## Attributes

The  [universal attributes](js-components-svg-common-attributes.md)  and the attributes listed below are supported. The configured universal attributes are passed to the child components.

| Name | Type   | Default Value | Mandatory | Description                                                  |
| ---- | ------ | ------------- | --------- | ------------------------------------------------------------ |
| id   | string | -             | No        | Unique ID of the component.                                  |
| d    | string | -             | No        | Shape of the path. The value contains a group of character instructions. Uppercase letters are absolute paths, and lowercase letters are relative paths.<br/>The meanings of the letters are as follows:<br/>- M/m = moveto<br/>- L/l = lineto<br/>- H/h = horizontal lineto<br/>- V/v = vertical lineto<br/>- C/c = curveto<br/>- S/s = smooth curveto<br/>- Q/q = quadratic Belzier curve<br/>- T/t = smooth quadratic Belzier curveto<br/>- A/a = elliptical Arc<br/>- Z/z = closepath |


## Example

```
<!-- xxx.hml -->
<div class="container">
    <svg width="400" height="400">
        <path d="M 10,30 A 20,20 0,0,1 50,30 A 20,20 0,0,1 90,30 Q 90,60 50,90 Q 10,60 10,30 z"
          stroke="blue" stroke-width="3" fill="red">
        </path>
    </svg>
</div>
```

![](figures/en-us_image_0000001173164891.png)

