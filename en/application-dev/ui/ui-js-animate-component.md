# Component Animation


Create and run an animation shortcut on the component. For details, see [Universal Methods](../reference/arkui-js/js-components-common-methods.md).


## Obtaining an Animation Object

Call the **animate** method to obtain an animation object, which supports animation attributes, methods, and events.

```html
<!-- xxx.hml -->
<div class="container">
  <div id="content" class="box" onclick="Show"></div>
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
```

```js
/* xxx.js */
export default {
  data: {
    animation: '',
  },
  onInit() {
  },
  onShow() {
    var options = {
      duration: 1500,
    };
    var frames = [
      {
        width:200,height:200,
      },
      {
        width:300,height:300,
      }
    ];
    this.animation = this.$element('content').animate(frames, options);  // Obtain the animation object.
  },
  Show() {   
    this.animation.play();
  }
}
```

![en-us_image_0000001222807812](figures/en-us_image_0000001222807812.gif)

> **NOTE**
> - When using the animate method, you must pass the keyframes and options parameters.
> - If animate is called multiple times and the replace policy is used, parameters passed to the last call will take effect.


## Setting Animation Parameters

After obtaining an animation object, you can set its style working on the component by using the keyframes parameter.

```html
<!-- xxx.hml -->
<div class="container">
   <div id="content" class="box" onclick="Show"></div>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 100%;
}
.box{
  width: 200px;
  height: 200px;
  background-color: #ff0000;
  margin-top: 30px;
}
```

```js
/* xxx.js */
export default {
  data: {
    animation: '',
    keyframes:{},
    options:{}
  },
  onInit() {
    this.options = {
      duration: 4000,
    }
    this.keyframes = [
    {
      transform: {
        translate: '-120px -0px',   
        scale: 1,        
        rotate: 0
        },   
        transformOrigin: '100px 100px',  
        offset: 0.0, 
        width: 200,  
        height: 200   
      }, 
      {
        transform: {      
          translate: '120px 0px',     
          scale: 1.5,     
          rotate: 90   
          },
          transformOrigin: '100px 100px',
          offset: 1.0,
          width: 300,
          height: 300   
      }    
    ]
  },
  Show() {
    this.animation = this.$element('content').animate(this.keyframes, this.options)
    this.animation.play()
  }
}
```

![en-us_image_0000001267647897](figures/en-us_image_0000001267647897.gif)

> **NOTE**
> - The sequence of **translate**, **scale**, and **rotate** affects the animation effect.
> 
> - **transformOrigin** works only for scale and rotate.

Set the animation attributes by using the **options** parameter.

```html
<!-- xxx.hml -->
<div class="container">
   <div id="content" class="box" onclick="Show"></div>
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
```

```js
/* xxx.js */
export default {
  data: {
    animation: '',
  },
  onInit() {
  },
  onShow() {
    var options = {      
        duration: 1500,      
        easing: 'ease-in',      
        delay: 5,      
        iterations: 2,      
        direction: 'normal',    
    };
    var frames = [
      {
        transform: {
          translate: '-150px -0px'
        }
      },
      {
        transform: {
          translate: '150px 0px'
        }
      }
    ];
    this.animation = this.$element('content').animate(frames, options);
  },
  Show() {
    this.animation.play();
  }
}
```

![en-us_image_0000001222967796](figures/en-us_image_0000001222967796.gif)

> **NOTE**
>
> **direction**: mode of playing the animation.
>
> **normal**: plays the animation in forward loop mode.
>
> **reverse**: plays the animation in reverse loop mode.
>
> **alternate**: plays the animation in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in reverse direction.
>
> **alternate-reverse**: plays the animation in reverse alternating loop mode. When the animation is played for an odd number of times, the playback is in reverse direction. When the animation is played for an even number of times, the playback is in forward direction.


## Adding an Event and Calling a Method

Animation objects support animation events and methods. You can achieve the intended animation by adding start and cancel events and calling the play, pause, rewind, and stop methods.

```html
<!-- xxx.hml -->
<div class="container">
    <div id="content" style="width: 350px;height: 350px;margin-top: 100px;background: linear-gradient(pink, purple);">
    </div>
    <div class="row">
        <button type="capsule" value="play" onclick="playAnimation"></button>
        <button type="capsule" value="pause" onclick="pauseAnimation"></button>
    </div>
    <div class="row1">
        <button type="capsule" value="reverse" onclick="reverseAnimation"></button>
        <button type="capsule" value="cancel" onclick="cancelAnimation"></button>
    </div>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  justify-content: center;
  width: 100%;
  height: 100%;
}
button{
  width: 200px;
}
.row{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 40px;
  position: fixed;
  top: 65%;
  left: 120px;
}
.row1{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 30px;
  position: fixed;
  top: 75%;
  left: 120px;
}
```

```js
// xxx.js
export default {
    data: {
        animation: '',
    },
    onShow() {
        var options = {
            duration: 1500,
            easing:'ease-in',
            delay:5,
            direction:'normal',
            iterations:2
        };
        var frames = [
            {
                transform: {
                    translate: '-150px -0px'
                },
                opacity: 0.1,
                offset: 0.0,
                width: 200,
                height: 200,
            },
            {
                transform: {
                    translate: '150px 0px'
                },
                opacity: 1.0,
                offset: 1.0,
                width: 300,
                height: 300,
            }
        ];
        this.animation = this.$element('content').animate(frames, options);
        this.animation.onstart = function() {
            console.info('animation start')
        }  // Add a start event.
        this.animation.onrepeat = function() {
            console.info('animation repeated')
        }  // Add a repeat event.
        this.animation.oncancel = function() {
            console.info('animation canceled')
        }   // Add a cancel event.
        this.animation.onfinish = function() {
            console.info('animation finish')
        }   // Add a finish event.
    },
    playAnimation() {
        this.animation.play()  // Start this animation.
    },
    pauseAnimation() {
        this.animation.pause()  // Pause this animation.
    },
    reverseAnimation() {
        this.animation.reverse()  // Reverse this animation.
    },
    cancelAnimation() {
        this.animation.cancel()  // Cancel this animation.
    }
}
```

![en-us_image_0000001223127752](figures/en-us_image_0000001223127752.gif)

Change the animation status by changing the **playState** attribute.

```html
<!-- xxx.hml -->
<div class="container">
  <div id="content" style="width: 350px;height: 350px;margin-top: 100px;background: linear-gradient(pink, purple);">
  </div>
  <div class="row">
     <button type="capsule" value="{{state}}" onclick="playStateClick"></button>
  </div>
  <div class="row1">
     <button type="capsule" value="{{state1}}" onclick="playStateClick1"></button>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
button{
  width: 200px;
}
.row{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 50px;
  margin-left: 260px;
  position: fixed;
  top: 65%;
}
.row1{
  width: 65%;
  height: 100px;
  align-items: center;
  justify-content: space-between;
  margin-top: 50px;
   margin-left: 260px;
  position: fixed;
  top: 75%;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  data: {
    animation: '',
    state:'play',
    state1:'play'
  },
  onInit() {
  },
  onShow() {
    var options = {
      duration: 1500,
      easing:'ease-in',
      elay:5,
      direction:'normal',
      iterations:2,
    };
    var frames = [
      {
        transform: {
          translate: '-150px -0px'
        },
        opacity: 0.1,
        offset: 0.0,
        width: 200,
        height: 200,
      },
      {
        transform: {
          translate: '150px 0px'
        },
          opacity: 1.0,
          offset: 1.0,
          width: 300,
          height: 300,
        }
      ];
      this.animation = this.$element('content').animate(frames, options);
      this.animation.onstart = function(){
        promptAction.showToast({
          message: "start"
        });
      };
      this.animation.onrepeat = function(){
        promptAction.showToast({
          message: " repeated"
        });
      };
      this.animation.onfinish = function(){
        promptAction.showToast({
          message: " finished"
      });
    };
  },
  playStateClick(){
    if(this.animation.playState != 'running'){
      this.animation.playState = 'running';// Set playState to running to run the animation.
      this.state = 'pause'
    }else{
      this.animation.playState = 'paused';// Set playState to paused to pause the animation.
      this.state = 'play'
    }
  },
  playStateClick1(){
    if(this.animation.playState != 'running'){
      this.animation.playState = 'running';
      this.state1 = 'finish'
    }else{
      this.animation.playState = 'finished';// Set playState to finished to stop the animation.
      this.state1 = 'play'
    }
  }
}
```

![en-us_image_0000001267607921](figures/en-us_image_0000001267607921.gif)
