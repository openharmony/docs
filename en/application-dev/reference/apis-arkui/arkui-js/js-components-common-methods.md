# Universal Methods

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

After a component is assigned the **id** attribute, you can use the ID to obtain the component objects and call methods on them.


## animate

animate( keyframes: Keyframes, options: Options): void

**Parameters**

| Name      | Type     | Mandatory  | Description                                  |
| --------- | --------- | ---- | ------------------------------------ |
| keyframes | keyframes | Yes   | Animation style.                              |
| options   | Options   | Yes   | Array of objects used to set animation attributes. For details, see **Options**.|

  **Table 1** keyframes

| Name    | Type                | Description                                    |
| ------ | ------------------ | -------------------------------------- |
| frames | Array&lt;Style&gt; | Array of objects used to set animation attributes. For details, see **Style attributes**.|

  **Table 2** Style attributes

| Name                | Type                                      | Default Value                 | Description                                      |
| ------------------ | ---------------------------------------- | -------------------- | ---------------------------------------- |
| width              | number                                   | -                    | Width set for the component during playback of the animation.                      |
| height             | number                                   | -                    | Height set for the component during playback of the animation.                      |
| backgroundColor    | &lt;color&gt;                            | none                 | Background color set for the component during playback of the animation.                     |
| opacity            | number                                   | 1                    | Opacity set for the component. The value ranges from 0 to 1.                     |
| backgroundPosition | string                                   | -                    | The value format is **"x y"**, in percentage or pixels.<br>The first value indicates the horizontal position, and the second value indicates the vertical position.<br>If only one value is specified, the other value is **50%**.|
| transformOrigin    | string                                   | 'center center' | Origin position of the transformed element.<br>The first value indicates the x-axis position. The value can be **left**, **center**, **right**, a length, or a percentage.<br>The second value indicates the y-axis position. The value can be **top**, **center**, **bottom**, a length, or a percentage.|
| transform          | [Transform](js-components-common-animation.md) | -                    | Transformation type set for a transformed element.                            |
| offset             | number                                   | -                    | - The value of **offset** must be within (0.0, 1.0] and sorted in ascending order if it is provided.<br>- If there are only two frames, **offset** can be left empty.<br>- If there are more than two frames, **offset** is mandatory.|

  **Table 3** Options

| Name                    | Type                        | Default Value   | Description                                      |
| ---------------------- | -------------------------- | ------ | ---------------------------------------- |
| duration               | number                     | 0      | Duration for playing the animation, in milliseconds.                       |
| easing                 | string                     | linear | Time curve of the animation. For details about the supported types, see **Available values of the easing attribute**.          |
| delay                  | number                     | 0      | Delay for the animation start. The default value indicates no delay.                   |
| iterations             | number \| string | 1      | Number of times the animation will be played. **number** indicates a fixed number of playback operations, and **Infinity** indicates an unlimited number of playback operations.|
| direction<sup>6+</sup> | string                     | normal | Mode of playing the animation.<br>**normal**: Plays the animation in forward loop mode.<br>**reverse**: Plays the animation in reverse loop mode.<br>**alternate**: Plays the animation in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in backward direction. <br>**alternate-reverse**: plays the animation in reverse alternating loop mode. When the animation is played for an odd number of times, the playback is in reverse direction. When the animation is played for an even number of times, the playback is in forward direction.|
| fill                   | string                     | none   | Start and end styles of the animation.<br>**none**: No style is applied to the target before or after the animation is executed.<br>**forwards**: The target keeps the state at the end of the animation (defined in the last key frame) after the animation is executed.<br>**backwards**<sup>6+</sup>: The animation uses the value defined in the first key frame during the **animation-delay**. When **animation-direction** is set to **normal** or **alternate**, the value in the **from** key frame is used. When **animation-direction** is set to **reverse** or **alternate-reverse**, the value in the **to** key frame is used.<br>**both**: The animation follows the **forwards** and **backwards** rules.|

  **Table 4** Available values of the easing attribute

| Value                                       | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| linear                                   | The animation speed keeps unchanged.                                 |
| ease-in                                  | The animation starts at a low speed and then picks up speed until the end. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used.|
| ease-out                                 | The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used.|
| ease-in-out                              | The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used.|
| friction                                 | The animation uses the friction cubic-bezier curve (0.2, 0.0, 0.2, 1.0).|
| extreme-deceleration                     | The animation uses the extreme deceleration cubic-bezier curve (0.0, 0.0, 0.0, 1.0).|
| sharp                                    | The animation uses the sharp cubic-bezier curve (0.33, 0.0, 0.67, 1.0).|
| rhythm                                   | The animation uses the rhythm cubic-bezier curve (0.7, 0.0, 0.2, 1.0).|
| smooth                                   | The animation uses the smooth cubic-bezier curve (0.4, 0.0, 0.4, 1.0).|
| cubic-bezier(x1, y1, x2, y2) | You can customize an animation speed curve in the **cubic-bezier()** function. The x and y values of each input parameter must be between 0 and 1.     |
| steps(number, step-position)<sup>6+</sup> | The animation uses the step curve.<br>The **number** must be set and only an integer is supported.<br>**step-position** is optional. It can be set to **start** or **end**. The default value is **end**.|

**Return value**
  The **animation** attributes are as follows.

| Name       | Type     | Description                                      |
| --------- | ------- | ---------------------------------------- |
| finished  | boolean | Read-only attribute, which indicates whether the animation playback is complete.                     |
| pending   | boolean | Read-only attribute, which indicates whether the animation is waiting for the completion of other asynchronous operations (for example, start an animation with a delay).|
| playState | string  | Read-write attribute, which indicates the playback status of the animation:<br>- **idle**: The animation is not running (playback ended or not started).<br>- **running**: The animation is running.<br>- **paused**: The animation is paused.<br>- **finished**: The animation finishes playing.|
| startTime | number  | Read-write attribute, which indicates the animation start time. This attribute is similar to **delay** in the **options** attribute. |

  The **animation** methods are as follows.

| Method     | Parameter  | Description     |
| ------- | ---- | ------- |
| play    | -    | Plays the animation.|
| finish  | -    | Ends the animation.|
| pause   | -    | Pauses the animation.|
| cancel  | -    | Cancels the animation.|
| reverse | -    | Plays the animation in reverse.|

  The **animation** events are as follows.

| Event                | Description      |
| ------------------ | -------- |
| start<sup>6+</sup> | The animation starts. |
| cancel             | The animation is forcibly canceled.|
| finish             | The animation playback is complete. |
| repeat             | The animation repeats. |

**Example**
```html
<!-- xxx.hml -->
<div class="container">
  <div id="idName" class="box"></div>
  <div class="buttonBox">
    <button @click="start">
      start
    </button>
    <button @click="cancel">
      cancel
    </button>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  width: 100%;
}
.box{
  width: 200px;
  height: 200px;
  background-color: #ff0000;
  margin-top: 30px;
}
.buttonBox{
  margin-top: 30px;
  width: 250px;
  justify-content: space-between;
}
button{
  background-color: #8e8b89;
  color: white;
  width: 100px;
  height: 40px;
  font-size: 24px;
}
```

```js
// xxx.js
export default {
    data: {
        animation: '',
        options: {},
        frames: {}
    },
    onInit() {
        this.options = {
            duration: 1500,
            easing: 'friction',
            delay: 500,
            fill: 'forwards',
            iterations: 2,
            direction: 'normal',
        };
        this.frames = [
            {
                transform: {
                    translate: '-120px -0px'
                }, opacity: 0.1, offset: 0.0
            },
            {
                transform: {
                    translate: '120px 0px'
                }, opacity: 1.0, offset: 1.0
            }
        ];
    },

    start() {
        this.animation = this.$element('idName').animate(this.frames, this.options);
        this.animation.play();
    },
    cancel() {
        this.animation.cancel();
    }
}
```

![en-us_image_0000001229677045](figures/en-us_image_0000001229677045.gif)

## getBoundingClientRect

getBoundingClientRect(): \<Rect>

Obtains the size of the element and its position relative to the window.

**Return value**

  **Table 5** Rect<sup>6+</sup>

| Name    | Type    | Description            |
| ------ | ------ | -------------- |
| width  | number | Width of the element.       |
| height | number | Height of the element.       |
| left   | number | Offset between the left boundary of the element and the window.|
| top    | number | Offset between the upper boundary of the element and the window.|

**Example**
```js
// xxx.js
var rect = this.$element('id').getBoundingClientRect();
console.info(`current element position is ${rect.left}, ${rect.top}`);
```
## createIntersectionObserver

createIntersectionObserver(param?:  ObserverParam): Observer

Listens for the visibility of the element on the current page.

**Parameters**

| Name  | Type         | Mandatory  | Description            |
| ----- | ------------- | ---- | -------------- |
| param | ObserverParam | -    | Observer callback.|

  **Table 6** ObserverParam<sup>6+</sup>

| Name    | Type                 | Description                      |
| ------ | ------------------- | ------------------------ |
| ratios | Array&lt;number&gt; | Range for triggering the observer callback. If the component is not within the range, the observer callback is triggered.|

**Return value**

  **Table 7** Methods supported Observer<sup>6+</sup>

| Method       | Parameter                     | Description                                 |
| --------- | ----------------------- | ----------------------------------- |
| observe   | callback: function | Subscribes to events of the observed object. The callback method is called when the value is greater than or less than the threshold.|
| unobserve | -                       | Unsubscribes from events of the observed object.                   |

**Example**
```js
// xxx.js
let observer = this.$element('broad').createIntersectionObserver({
  ratios: [0.2, 0.5], // number
});

observer.observe((isVisible, ratio)=> {
    console.info('this element is ' + isVisible + 'ratio is ' + ratio)
})

observer.unobserve()
```
