# image-animator

The **\<image-animator>** component is used to provide an image frame animator.

> **NOTE**
>
> This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## Attributes

| Name                 | Type                      | Default Value  | Mandatory| Description                                                        |
| --------------------- | -------------------------- | -------- | ---- | ------------------------------------------------------------ |
| images                | Array&lt;ImageFrame&gt;    | -        | Yes  | Image frame information. The frame information includes the image path, size, and location. The supported image formats include PNG, JPG, and BMP. For details about **ImageFrame**, see Table 1.<br>**NOTE**<br>1. Use data binding, for example, **images = {{images}}**, to specify the image. Declare the corresponding variable in JavaScript: **images: [{src: "/common/heart-rate01.png"}, {src: "/common/heart-rate02.png"}]**.<br>2. Some lightweight devices are not able to parse images in their original format. To address this issue, in the application compilation phase, the image is directly compiled into a parseable bitmap (total number of bytes: image length x width x 4) and packed in the application installation package. Naturally, larger images result in a larger application installation package. To maintain a proper size of the application installation package, reduce the image resolution as appropriate.|
| iteration             | number \| string | infinite | No  | Number of times that the frame animation is played. **number** indicates a fixed number of playback operations, and **infinite** indicates an unlimited number of playback operations.|
| reverse               | boolean                    | false    | No   | Playback sequence.<br/>- **true**: Images are played from the last one to the first one.<br/>- **false**: Images are played from the first one to the last one.|
| fixedsize             | boolean                    | true     | No  | Whether the image size is the same as the component size.<br> **true**: The image size is the same as the component size. In this case, the width, height, top, and left attributes of the image are invalid.<br> **false**: The image size is different from the component size. In this case, the width, height, top, and left attributes of each image must be set separately.|
| duration              | string                     | -        | Yes  | Single video playback duration, in seconds (s) or milliseconds (ms). The default unit is ms. If the value is **0**, no image is played. The value change takes effect only at the start of the next cycle.|
| fillmode<sup>5+</sup> | string                     | forwards | No  | Status of the frame animation after its playback is complete. Available values are as follows:<br>- **none**: restores to the initial status.<br>- **forwards**: retains the ending status defined for the last key frame.|
| id                    | string                     | -        | No  | Unique ID of the component.                                            |
| style                 | string                     | -        | No  | Style declaration of the component.                                            |
| class                 | string                     | -        | No  | Style class of the component, which is used to refer to a style table.                              |
| ref                   | string                     | -        | No  | Reference information of child elements, which is registered with the parent component on **$refs**.|

  **Table 1** ImageFrame

| Name    | Type            | Default Value | Mandatory  | Description              |
| ------ | -------------- | ---- | ---- | ---------------- |
| src    | &lt;uri&gt;    | -    | Yes   | Image path.           |
| width  | &lt;length&gt; | 0    | No   | Image width.           |
| height | &lt;length&gt; | 0    | No   | Image height.           |
| top    | &lt;length&gt; | 0    | No   | Vertical coordinate of the image relative to the upper left corner of the component.|
| left   | &lt;length&gt; | 0    | No   | Horizontal coordinate of the image relative to the upper left corner of the component.|


## Events

| Name                | Parameter                               | Description         |
| ------------------ | --------------------------------- | ----------- |
| stop               | -                                 | Triggered when the frame animation stops  |
| click              | -                                 | Triggered when the component is clicked. |
| longpress          | -                                 | Triggered when the component is long pressed. |
| swipe<sup>5+</sup> | [SwipeEvent](js-lite-common-events.md) | Triggered when a user quickly swipes on the component.|


## Styles

| Name                                | Type                                      | Default Value  | Mandatory  | Description                                      |
| ---------------------------------- | ---------------------------------------- | ----- | ---- | ---------------------------------------- |
| width                              | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | -     | No   | Component width.<br><br>If this attribute is not set, the default value **0** is used.       |
| height                             | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | -     | No   | Component height.<br><br>If this attribute is not set, the default value **0** is used.       |
| padding                            | &lt;length&gt;                           | 0     | No   | Shorthand attribute to set the padding for all sides.<br>The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom] | &lt;length&gt;                           | 0     | No   | Left, top, right, and bottom padding.                         |
| margin                             | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0     | No   | Shorthand attribute to set the margin for all sides. The attribute can have one to four values:<br>- If you set only one value, it specifies the margin for all the four sides.<br>- If you set two values, the first value specifies the top and bottom margins, and the second value specifies the left and right margins.<br>- If you set three values, the first value specifies the top margin, the second value specifies the left and right margins, and the third value specifies the bottom margin.<br>- If you set four values, they respectively specify the margin for top, right, bottom, and left sides (in clockwise order).|
| margin-[left\|top\|right\|bottom]  | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0     | No   | Left, top, right, and bottom margins.                         |
| border-width                       | &lt;length&gt;                           | 0     | No   | Shorthand attribute to set the margin for all sides.                      |
| border-color                       | &lt;color&gt;                            | black | No   | Shorthand attribute to set the color for all borders.                      |
| border-radius                      | &lt;length&gt;                           | -     | No   | Radius of round-corner borders.           |
| background-color                   | &lt;color&gt;                            | -     | No   | Background color.                                 |
| opacity<sup>5+</sup>               | number                                   | 1     | No   | Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.       |
| display                            | string                                   | flex  | No   | How and whether to display the box containing an element. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|
| [left\|top]                        | &lt;length&gt; \| &lt;percentage&gt;<sup>6+</sup> | -     | No   | left\|Edge of the element.<br>- **left**: left edge position of the element. This attribute defines the offset between the left edge of the margin area of a positioned element and left edge of its containing block.<br>- **top**: top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.|


## Methods

| Name      | Parameter  | Description                                      |
| -------- | ---- | ---------------------------------------- |
| start    | -    | Starts to play the frame animation of an image. If this method is called again, the playback starts from the first frame.              |
| pause    | -    | Pauses the frame animation playback of an image.                              |
| stop     | -    | Stops the frame animation playback of an image.                              |
| resume   | -    | Resumes the frame animation playback of an image.                                |
| getState | -    | Obtains the playback state. Available values are as follows:<br>- playing<br>- paused<br>- stopped|


## Example


```html
<!-- xxx.hml -->
<div class="container">
  <image-animator class="animator" ref="animator" images="{{frames}}" duration="1s" />
  <div class="btn-box">
    <input class="btn" type="button" value="start" @click="handleStart" />
    <input class="btn" type="button" value="stop" @click="handleStop" />
    <input class="btn" type="button" value="pause" @click="handlePause" />
    <input class="btn" type="button" value="resume" @click="handleResume" />
  </div>
</div>
```


```css
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.animator {
  width: 70px;
  height: 70px;
}
.btn-box {
  width: 264px;
  height: 120px;
  flex-wrap: wrap;
  justify-content: space-around;
  align-items: center;
}
.btn {
  border-radius: 8px;
  width: 120px;
  margin-top: 8px;
}
```


```js
//xxx.js
export default {
  data: {
    frames: [
      {
        src: "/common/asserts/heart78.png",
      },
      {
        src: "/common/asserts/heart79.png",
      },
      {
        src: "/common/asserts/heart80.png",
      },
      {
        src: "/common/asserts/heart81.png",
      },
      {
        src: "/common/asserts/heart82.png",
      },
      {
        src: "/common/asserts/heart83.png",
      },
      {
        src: "/common/asserts/heart84.png",
      },
      {
        src: "/common/asserts/heart85.png",
      },
      {
        src: "/common/asserts/heart86.png",
      },
      {
        src: "/common/asserts/heart87.png",
      },
      {
        src: "/common/asserts/heart88.png",
      },
      {
        src: "/common/asserts/heart89.png",
      },
      {
        src: "/common/asserts/heart90.png",
      },
      {
        src: "/common/asserts/heart91.png",
      },
      {
        src: "/common/asserts/heart92.png",
      },
      {
        src: "/common/asserts/heart93.png",
      },
      {
        src: "/common/asserts/heart94.png",
      },
      {
        src: "/common/asserts/heart95.png",
      },
      {
        src: "/common/asserts/heart96.png",
      },
    ],
  },
  handleStart() {
    this.$refs.animator.start();
  },
  handlePause() {
    this.$refs.animator.pause();
  },
  handleResume() {
    this.$refs.animator.resume();
  },
  handleStop() {
    this.$refs.animator.stop();
  },
};
```

![image-animator](figures/image-animator-lite.gif)
