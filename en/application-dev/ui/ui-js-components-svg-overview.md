# Basics


The **&lt;svg&gt;** component is used as the root node of the SVG canvas and can be nested in the SVG. For details, see [svg](../reference/apis-arkui/arkui-js/js-components-svg.md).


> **NOTE**
> 
> The width and height must be defined for the **&lt;svg&gt;** parent component or **&lt;svg&gt;** component. Otherwise, the component is not drawn.


## Creating an &lt;svg&gt; Component

Create a **&lt;svg&gt;** component in the .hml file under **pages/index**.


```html
<!-- xxx.hml -->
<div class="container">
  <svg width="400" height="400">  </svg>
</div>
```


```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
svg{
  background-color: blue;
}
```

![en-us_image_0000001232162324](figures/en-us_image_0000001232162324.png)


## Setting Attributes

Set the **width**, **height**, **x**, **y**, and **viewBox** attributes to define the width, height, X coordinate, Y coordinate, and SVG viewport of the **&lt;svg&gt;** component.


```html
<!-- xxx.hml -->
<div class="container">
  <svg width="400" height="400" viewBox="0 0 100 100">    
    <svg class="rect" width="100" height="100" x="20" y="10">    
    </svg>  
  </svg>
</div>
```


```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
svg{
  background-color: yellow;
}
.rect{
  background-color: red;
}
```

![en-us_image_0000001231683152](figures/en-us_image_0000001231683152.png)

> **NOTE**
>
> - If the **&lt;svg&gt;** component is the root node, the X-axis and Y-axis attributes are invalid.
>
> - If the width and height of **viewBox** are inconsistent with those of the **&lt;svg&gt;** component, the view box will be scaled in center-aligned mode.
