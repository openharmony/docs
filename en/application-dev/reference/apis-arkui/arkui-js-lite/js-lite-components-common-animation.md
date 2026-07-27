# Animation Styles

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:27:02.974Z pushedAt=2026-07-27T09:23:36.735Z -->

Components support dynamic rotation and translation effects. These effects can be set in the **style** attribute or **.css** files.

| Name                       | Type                                | Default Value        | Description                                      |
| ------------------------- | ---------------------------------- | ----------- | ---------------------------------------- |
| transform                 | string                             | -           | For details, see Table 1.                                   |
| animation-name            | string                             | -           | @keyframes rule. For details, see Table 2.                     |
| animation-delay           | &lt;time&gt;                       | 0           | Delay for playing the animation, in s or ms (default), for example, **1000 ms** or **1s**.|
| animation-duration        | &lt;time&gt;                       | 0           | Animation duration, in s or ms (default), for example, **1000 ms** or **1s**.<br>**NOTE**<br>**animation-duration** must be specified. Otherwise, the duration is **0**, which means the animation will not be played.|
| animation-iteration-count | number&nbsp;&nbsp;\|&nbsp;infinite | 1           | Number of times that an animation is played. The animation is played once by default. You can set the value to **infinite** to play the animation infinitely.   |
| animation-timing-function | string                             | <br>linear | Speed curve of an animation, which makes the animation more fluent.<br>Available values are as follows:<br>- **linear**: The animation speed is constant from start to finish.<br>- **ease-in**: The animation starts at a low speed. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used.<br>- **ease-out**: The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used.<br>- **ease-in-out**: The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used.|
| animation-fill-mode       | string                             | none        | Start and end styles of the animation.<br>- **none**: No style is applied to the target before or after the animation is executed.<br>- **forwards**: The target keeps the state at the end of the animation (defined in the last key frame) after the animation is executed.|

  **Table 1** transform

| Name        | Type                                  | Description        |
| ---------- | ------------------------------------ | ---------- |
| translateX | &lt;length&gt;                       | Moves an element along the x-axis.|
| translateY | &lt;length&gt;                       | Moves an element along the y-axis.|
| rotate     | &lt;deg&gt;&nbsp;\|&nbsp;&lt;rad&gt; | Rotates an element.    |

>  **NOTE**
>
>  Only images of the original size can be rotated on lite wearables.
>
>  **rotate** can only be used in \@keyframes and cannot be set in regular styles or dynamically bound.

  **Table 2** @keyframes

| Name              | Type            | Default Value | Description                |
| ---------------- | -------------- | ---- | ------------------ |
| background-color | &lt;color&gt;  | -    | Background color applied to the component at the keyframe time of an animation.  |
| width            | &lt;length&gt; | -    | Width value applied to the component at the keyframe time of an animation.   |
| height           | &lt;length&gt; | -    | Height value applied to the component at the keyframe time of an animation.   |
| transform        | string         | -    | Transformation type applied to a component. For details, see Table 1.|

If there is no default value for when an animation will start or end, use **from** and **to** to specify the start and end of the display. The following is an example:

```css
@keyframes Go
{
   from {
     background-color: #f76160;
   }
   to {
     background-color: #09ba07;
   }
}
```

![animation-demo1](figures/animation-demo1.gif)

>  **NOTE**
>
>  The \@keyframes rule with **from** and **to** defined cannot be dynamically bound to an element.