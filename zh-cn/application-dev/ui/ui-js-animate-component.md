# 组件动画

在组件上创建和运行动画的快捷方式。具体用法请参考[通用方法](../reference/apis-arkui/arkui-js/js-components-common-methods.md)。


## 获取动画对象

通过调用animate方法获得animation对象，animation对象支持动画属性、动画方法和动画事件。

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
        options: {},
        frames: {}
    },
    onInit() {
        this.options = {
            duration: 1500,
        };
        this.frames = [
            {
                width: 200, height: 200,
            },
            {
                width: 300, height: 300,
            }
        ];
    },
    Show() {
        this.animation = this.$element('content').animate(this.frames, this.options); //获取动画对象
        this.animation.play();
    }
}
```

![zh-cn_image_0000001175235138](figures/zh-cn_image_0000001175235138.gif)

> **说明：**
> -   使用animate方法时必须传入Keyframes和Options参数。
> -   多次调用animate方法时，采用replace策略，即最后一次调用时传入的参数生效。


## 设置动画参数

在获取动画对象后，通过设置参数Keyframes设置动画在组件上的样式。

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

![zh-cn_image_0000001174916742](figures/zh-cn_image_0000001174916742.gif)

> **说明：**
> - translate、scale和rtotate的先后顺序会影响动画效果。
>
> - transformOrigin只对scale和rtotate起作用。

在获取动画对象后，通过设置参数Options来设置动画的属性。

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
        options: {},
        frames: {}
    },
    onInit() {
        this.options = {
            duration: 1500,
            easing: 'ease-in',
            delay: 5,
            iterations: 2,
            direction: 'normal',
        };
        this.frames = [
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
    },
    Show() {
        this.animation = this.$element('content').animate(this.frames, this.options);
        this.animation.play();
    }
}
```

![zh-cn_image_0000001220396499](figures/zh-cn_image_0000001220396499.gif)

> **说明：** 
>
> direction：指定动画的播放模式。
>
> normal： 动画正向循环播放。
>
> reverse： 动画反向循环播放。
>
> alternate：动画交替循环播放，奇数次正向播放，偶数次反向播放。
>
> alternate-reverse：动画反向交替循环播放，奇数次反向播放，偶数次正向播放。


