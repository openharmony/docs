# Attribute Style Animation

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=5c418d4bf2581cd8ca625b8865e73773ebc27789 translatedAt=2026-08-05T10:10:28.386Z pushedAt=2026-08-06T03:47:23.600Z -->

Keyframes are used to animate the scaling of a component by dynamically adjusting the width and height of its parent container. To scale both the child and parent components simultaneously, set the **scale** attribute on the child component. Then, set the **opacity** attribute to control the visibility of both the child and parent components.

```html
<!-- xxx.hml -->
<div class="container">
  <div class="fade">
    <text>fading away</text>
  </div>
  <div class="bigger">
    <text>getting bigger</text>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  background-color:#F1F3F5;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;
  width: 100%;
  height: 100%;
}
.fade {
  width: 30%;
  height: 200px;
  left: 35%;
  top: 25%;
  position: absolute;
  animation: 2s change infinite friction;
}
.bigger {
  width: 20%;
  height: 100px;
  background-color: blue;
  animation: 2s change1 infinite linear-out-slow-in;
}
text {
  width: 100%;
  height: 100%;
  text-align: center;
  color: white;
  font-size: 35px;
  animation: 2s change2 infinite linear-out-slow-in;
}
/* Color and opacity change. */
@keyframes change{
  from {
    background-color: #f76160;
    opacity: 1;
  }
  to {
    background-color: #09ba07;
    opacity: 0;
  }
}
/* Scaling of the parent component */
@keyframes change1 {
  0% {
    width: 20%;
    height: 100px;
  }
  100% {
    width: 80%;
    height: 200px;
  }
}
/* Text scaling of the child component */
@keyframes change2 {
  0% {
    transform: scale(0);
  }
  100% {
    transform: scale(1.5);
  }
}
```

![animation3](figures/animation3.gif)

> **NOTE**
> - The values of **animation** attributes are not sequenced. However, the values of **duration** and **delay** are parsed based on the sequence in which they are displayed.
>
> - The **animation-duration** attribute must be set. Otherwise, the duration is **0**, which means there is no animation effect. When **animation-fill-mode** is set to **forwards**, the component directly displays the style of the last frame.