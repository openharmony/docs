# Defining Animations with the background-position Attribute


By changing the **background-position** attribute (where the first value is the position on the x-axis and the second value is the position on the y-axis), you move a background image. If the background image goes beyond the respective component boundaries, the excess parts will not be displayed.


```html
<!-- xxx.hml -->
<div class="container">
  <div class="content"></div>
  <div class="content1"></div>
</div>
```


```css
/* xxx.css */
.container {
  height: 100%;
  background-color:#F1F3F5;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  width: 100%;
}
.content{
  width: 400px;
  height: 400px;
  /* The aspect ratio 1:1 is not recommended. */
  background-image: url('common/images/bg-tv.jpg');
  background-size: 100%;
  background-repeat: no-repeat;
  animation: change 3s infinite;
  border: 1px solid black;
}
.content1{
  margin-top:50px;
  width: 400px;
  height: 400px;
  background-image: url('common/images/bg-tv.jpg');
  background-size: 50%;
  background-repeat: no-repeat;
  animation: change1 5s infinite;
  border: 1px solid black;
}
/* Move the background image out of the component. */
@keyframes change{
  0%{
    background-position:0px top;
  }
  25%{
    background-position:400px top;
  }
  50%{
    background-position:0px top;
  }
  75%{
    background-position:0px bottom;
  }
  100%{
    background-position:0px top;
  }
}
/* Move the background image within the component. */
@keyframes change1{
  0%{
    background-position:left top;
  }
  25%{
    background-position:50% 50%;
  }
  50%{
    background-position:right bottom;
  }
  100%{
    background-position:left top;;
  }
}
```


> **NOTE**
>
> The **background-position** attribute can only be used to move background images, but not the background color (**background-color**).
>
> ![en-us_image_background_img.gif](figures/en-us_image_background_img.gif)
