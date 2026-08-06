# slider Development
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->


The **&lt;slider&gt;** component is used to quickly adjust settings, such as the volume and brightness. For details, see [slider](../reference/apis-arkui/arkui-js/js-components-basic-slider.md).


## Creating a &lt;slider&gt; Component

Create a **&lt;slider&gt;** component in the .hml file under **pages/index**.



```html
<!-- xxx.hml -->
<div class="container">
  <slider></slider>
</div>
```

```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  background-color: #F1F3F5;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
```


![slider-Component](figures/slider-Component.gif)


## Setting Styles and Attributes

Use the **&lt;slider&gt;** component to set the background color, selected color, and slider color using the **color**, **selected-color**, and **block-color** attributes, respectively.


```html
<!-- xxx.hml -->
<div class="container">
  <slider class= "sli"></slider>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
.sli{
  color: #fcfcfc;
  scrollbar-color: aqua;
  background-color: #b7e3f3;
}
```

![Styles-and-Attributes](figures/Styles-and-Attributes.gif)

Add the **min**, **max**, **value**, **step**, and **mode** attributes to set the minimum value, maximum value, initial value, step, and style of the slider.


```html
<!-- xxx.hml -->
<div class="container">
  <slider min="0" max="100" value="1" step="2" mode="inset" showtips="true"></slider>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
```

![Styles-and-Attributes-1](figures/Styles-and-Attributes-1.gif)

> **NOTE**
>
> The **mode** attribute indicates the slider style. The options are as follows:
>
> - **outset**: The slider is on the slider bar.
>
> - **inset**: The slider is inside the sliding bar.


## Binding Events

Add the **change** event to the **&lt;slider&gt;** component and pass the **ChangeEvent** parameter when adding the event.


```html
<!-- xxx.hml -->
<div class="container">
  <text>slider start value is {{startValue}}</text>
  <text>slider current value is {{currentValue}}</text>
  <text>slider end value is {{endValue}}</text>
  <slider min="0" max="100" value="{{value}}" onchange="setValue"></slider>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%; 
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
```


```js
// xxx.js
export default {
  data: {
    value: 0,
    startValue: 0,
    currentValue: 0,
    endValue: 0,
  },
  setValue(e) {
    if (e.mode === "start") {
      this.value = e.value;
      this.startValue = e.value;
    } else if (e.mode === "move") {
      this.value = e.value;
      this.currentValue = e.value;
    } else if (e.mode === "end") {
      this.value = e.value;
      this.endValue = e.value;
    }
  }
}
```

![Binding-Events-4](figures/Binding-Events-4.gif)


## Example Scenario

Adjust the value of the slider to change the image size and dynamically print the width and height of the current image.


```html
<!-- xxx.hml -->
<div class="container">
  <image src="common/landscape3.jpg" style=" width: {{WidthVal}}px;height:{{HeightVal}}px;margin-top: -150px;"></image>
  <div class="text">
    <slider min="0" max="100" value="{{value}}" onchange="setValue"></slider>
    <text>The width of this picture is {{WidthVal}}</text>
    <text>The height of this picture is {{HeightVal}}</text>
  </div>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
.text{
  flex-direction: column;
  justify-content: center;
  align-items: center;
  position: fixed;
  top: 65%;
}
.text{
  margin-top: 30px;
}
```


```js
// xxx.js
export default{
  data: {
    value: 0,
    WidthVal: 200,
    HeightVal: 200
  },
  setValue(e) {
    this.WidthVal = 200 + e.value;
    this.HeightVal = 200 + e.value;
  }
}
```

![Example-Scenario-15](figures/Example-Scenario-15.gif)


## Samples

The following samples are provided to help you better understand how to develop **slider**:

- [Using slider Components (JS, API version 9)](https://gitcode.com/openharmony/codelabs/tree/master/JSUI/SliderApplication)

- [Simple Video Player (ArkTS, API version 9)](https://gitcode.com/openharmony/codelabs/tree/master/Media/VideoOpenHarmony)
