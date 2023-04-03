# animateMotion


>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **\<animateMotion>** component is used to define the animation along a path.

## Required Permissions

None.


## Child Components

Not supported


## Attributes

The **animate** attributes (**values** does not take effect) and the attributes in the following table are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| keyPoints | string | - | Yes| Point position of a group of key frames. The value of each frame is the distance proportion of the object along the path. The function is the same as that of **values** in the **animate** attribute.|
| path | string | - | Yes| Motion path. The syntax is the same as that of the **d** attribute of the **\<path>** component.|
| rotate | [auto \| auto-reverse \| &lt;number&gt;] | auto | No| Rotation direction of an animation object.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <path fill="none" stroke="blue" stroke-width="3" d="m40,60 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="none" stroke="blue" stroke-width="3" d="m40,130 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="none" stroke="blue" stroke-width="3" d="m40,200 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="auto" keyPoints="0;0.2;0.4;0.6;0.8;1" path="m40,60 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z">
      </animateMotion>
    </path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="auto-reverse"path="m40,130 c0,-100 160,100 160,0 c0,-100,-160,100 -160,0 z">
      </animateMotion>
    </path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="45"path="m40,200 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></animateMotion>
    </path>
  </svg>
</div>
```


![2-11](figures/2-11.gif)
