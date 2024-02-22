# path


>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **\<path>** component is used to draw a path.

## Required Permissions

None


## Child Components

The following are supported: [\<animate>](js-components-svg-animate.md), [\<animateMotion>](js-components-svg-animatemotion.md), and [\<animateTransform>](js-components-svg-animatetransform.md).


## Attributes

The [universal attributes](js-components-svg-common-attributes.md) and the attributes listed below are supported. The configured universal attributes are passed to the child components.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | - | No| Unique ID of the component.|
| d | string | - | No| Shape of the path. The value contains a group of character instructions. Uppercase letters are absolute paths, and lowercase letters are relative paths.<br>The meanings of the letters are as follows:<br>-&nbsp;M/m&nbsp;=&nbsp;moveto<br>-&nbsp;L/l&nbsp;=&nbsp;lineto<br>-&nbsp;H/h&nbsp;=&nbsp;horizontal&nbsp;lineto<br>-&nbsp;V/v&nbsp;=&nbsp;vertical&nbsp;lineto<br>-&nbsp;C/c&nbsp;=&nbsp;curveto<br>-&nbsp;S/s&nbsp;=&nbsp;smooth&nbsp;curveto<br>-&nbsp;Q/q&nbsp;=&nbsp;quadratic&nbsp;Belzier&nbsp;curve<br>-&nbsp;T/t&nbsp;=&nbsp;smooth&nbsp;quadratic&nbsp;Belzier&nbsp;curveto<br>-&nbsp;A/a&nbsp;=&nbsp;elliptical&nbsp;Arc<br>-&nbsp;Z/z&nbsp;=&nbsp;closepath |


## Example

```html
<!-- xxx.hml -->
<div class="container">
    <svg width="400" height="400">
        <path d="M 10,30 A 20,20 0,0,1 50,30 A 20,20 0,0,1 90,30 Q 90,60 50,90 Q 10,60 10,30 z"
          stroke="blue" stroke-width="3" fill="red">
        </path>
    </svg>
</div>
```


![en-us_image_0000001173164891](figures/en-us_image_0000001173164891.png)
