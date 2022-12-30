# Lottie

提供Lottie动画。

> **说明：**
> 
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 导入模块

```
import lottie from '@ohos/lottieETS'
```

> **说明：**
>
> 在Terminal窗口使用 `npm install @ohos/lottieETS` 命令下载Lottie，下载之前需要配置权限。
>
> 安装ohos npm 三方包时，需要先执行`npm config set @ohos:registry=https://repo.harmonyos.com/npm/`设置仓库地址。


## lottie.loadAnimation

loadAnimation(

path: string, container: object, render: string, loop: boolean, autoplay: boolean, name: string ): AnimationItem

加载动画，须提前声明Animator('__lottie_ets')对象，并在Canvas完成布局后调用。可配合Canvas组件生命周期接口onReady()使用。

**参数：**

| 参数             | 类型                          | 必填   | 描述                                       |
| -------------- | --------------------------- | ---- | ---------------------------------------- |
| path           | string                      | 是    | hap包内动画资源文件路径，仅支持json格式。示例：path:&nbsp;"common/lottie/data.json" |
| container      | object                      | 是    | canvas绘图上下文，声明范式需提前声明CanvasRenderingContext2D。 |
| render         | string                      | 是    | 渲染类型，仅支持“canvas”。                        |
| loop           | boolean&nbsp;\|&nbsp;number | 否    | 动画播放结束后，是否循环播放，默认值true。值类型为number，且大于等于1时为设置的重复播放的次数。 |
| autoplay       | boolean                     | 否    | 是否自动播放动画，默认值true。                        |
| name           | string                      | 否    | 开发者自定义的动画名称，后续支持通过该名称引用控制动画，默认为空。        |
| initialSegment | [number,&nbsp;number]       | 否    | 指定动画播放的起始帧号，指定动画播放的结束帧号。                 |


## lottie.destroy

destroy(name: string): void

销毁动画，页面退出时，必须调用。可配合Canvas组件生命周期接口使用，比如onDisappear()与onPageHide()。

**参数：**

| 参数   | 类型     | 必填   | 描述                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是    | 被指定的动画名，同loadAnimation接口参数name,&nbsp;缺省时销毁所有动画。 |

**示例：**  
  ```ts
  // xxx.ets
  import lottie from '@ohos/lottieETS'

  @Entry
  @Component
  struct Index {
    private controller: CanvasRenderingContext2D = new CanvasRenderingContext2D()
    private animateName: string = "animate"
    private animatePath: string = "common/lottie/data.json"
    private animateItem: any = null

    onPageHide(): void {
      console.log('onPageHide')
      lottie.destroy()
    }

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.controller)
        .width('30%')
        .height('20%')
        .backgroundColor('#0D9FFB')
        .onReady(() => {
          console.log('canvas onAppear');
          this.animateItem = lottie.loadAnimation({
            container: this.controller,
            renderer: 'canvas',
            loop: true,
            autoplay: true,
            name: this.animateName,
            path: this.animatePath,
          })
        })

        Animator('__lottie_ets') // declare Animator('__lottie_ets') when use lottie
        Button('load animation')
          .onClick(() => {
          if (this.animateItem != null) {
            this.animateItem.destroy()
            this.animateItem = null
          }
          this.animateItem = lottie.loadAnimation({
            container: this.controller,
            renderer: 'canvas',
            loop: true,
            autoplay: true,
            name: this.animateName,
            path: this.animatePath,
            initialSegment: [10, 50],
          })
        })

        Button('destroy animation')
          .onClick(() => {
            lottie.destroy(this.animateName)
            this.animateItem = null
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![zh-cn_image_0000001194352468](figures/zh-cn_image_0000001194352468.gif)


## lottie.play

play(name: string): void

播放指定动画。

**参数：**

| 参数   | 类型     | 必填   | 描述                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是    | 被指定的动画名,&nbsp;同loadAnimation接口参数name，缺省时播放所有动画。 |

**示例：**

  ```ts
  lottie.play(this.animateName)
  ```


## lottie.pause

pause(name: string): void

暂停指定动画，下次调用lottie.play()从当前帧开始。

**参数：**

| 参数   | 类型     | 必填   | 描述                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是    | 被指定的动画名，同loadAnimation接口入参name，缺省时暂停所有动画。 |

**示例：**

  ```ts
  lottie.pause(this.animateName)
  ```


## lottie.togglePause

togglePause(name: string): void

暂停或播放指定动画，等效于lottie.play()与lottie.pause()切换调用。

**参数：**

| 参数   | 类型     | 必填   | 描述                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是    | 被指定的动画名，同loadAnimation接口参数name，缺省时停止所有动画。 |

**示例：**

  ```ts
  lottie.togglePause(this.animateName)
  ```


## lottie.stop

stop(name: string): void

停止指定动画，下次调用lottie.play()从第一帧开始。

**参数：**

| 参数   | 类型     | 必填   | 描述                                       |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | 是    | 被指定的动画名，同loadAnimation接口参数name，缺省时停止所有动画。 |

**示例：**

  ```ts
  lottie.stop(this.animateName)
  ```


## lottie.setSpeed

setSpeed(speed: number, name: string): void

设置指定动画播放速度。

**参数：**

| 参数    | 类型     | 必填   | 描述                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| speed | number | 是    | 值为浮点类型,&nbsp;speed&gt;0正向播放,&nbsp;speed&lt;0反向播放,&nbsp;speed=0暂停播放,&nbsp;speed=1.0/-1.0正常速度播放。 |
| name  | string | 是    | 被指定的动画，同loadAnimation接口参数name，缺省时停止所有动画。 |

**示例：**

  ```ts
  lottie.setSpeed(5, this.animateName)
  ```


## lottie.setDirection

setDirection(direction: AnimationDirection, name: string): void

设置指定动画播放顺序。

**参数：**

| 参数        | 类型                 | 必填   | 描述                                       |
| --------- | ------------------ | ---- | ---------------------------------------- |
| direction | AnimationDirection | 是    | 1为正向，-1为反向;&nbsp;当设置为反向时，从当前播放进度开始回播直到首帧，loop值为true时可无限倒放；speed&lt;0叠加时也是倒放。<br/>AnimationDirection：1&nbsp;\|&nbsp;-1 |
| name      | string             | 是    | 被指定的动画名，同loadAnimation接口参数name，缺省时设置所有动画方向。 |

**示例：**

  ```ts
  lottie.setDirection(-1, this.animateName)
  ```


## AnimationItem

loadAnimation接口的返回对象，具有属性与接口。属性描述如下：

| 参数名称              | 参数类型                                     | 参数描述                                     |
| ----------------- | ---------------------------------------- | ---------------------------------------- |
| name              | string                                   | 动画名称。                                    |
| isLoaded          | boolean                                  | 动画是否已加载。                                 |
| currentFrame      | number                                   | 当前播放的帧号,&nbsp;默认精度为&gt;=0.0的浮点数,&nbsp;调用setSubframe(false)后精度为去小数点后的正整数。 |
| currentRawFrame   | number                                   | 当前播放帧数,&nbsp;精度为&gt;=0.0的浮点数。            |
| firstFrame        | number                                   | 当前播放片段的第一帧帧号。                            |
| totalFrames       | number                                   | 当前播放片段的总帧数。                              |
| frameRate         | number                                   | 帧率&nbsp;(frame/s)。                       |
| frameMult         | number                                   | 帧率&nbsp;(frame/ms)。                      |
| playSpeed         | number                                   | 值为浮点类型,&nbsp;speed&gt;0正向播放,&nbsp;speed&lt;0反向播放,&nbsp;speed=0暂停播放,&nbsp;speed=1.0&nbsp;\|&nbsp;-1.0正常速度播放。 |
| playDirection     | number                                   | 播放方向,&nbsp;1为正放,&nbsp;-1为倒放。             |
| playCount         | number                                   | 动画完成播放的次数。                               |
| isPaused          | boolean                                  | 当前动画是否已暂停,&nbsp;值为true动画已暂停。             |
| autoplay          | boolean                                  | 加载动画后是否自动播放,&nbsp;若值为false需要再调用play()接口开始播放。 |
| loop              | boolean&nbsp;\|&nbsp;number              | 类型为boolean时是否循环播放,&nbsp;类型为number时播放次数。  |
| renderer          | any                                      | 动画渲染对象,&nbsp;根据渲染类型而定。                   |
| animationID       | string                                   | 动画ID。                                    |
| timeCompleted     | number                                   | 当前动画片段完成单次播放的帧数,&nbsp;受AnimationSegment设置影响,&nbsp;与totalFrames属性值相同。 |
| segmentPos        | number                                   | 当前动画片段序号,&nbsp;值为&gt;=0的正整数。             |
| isSubframeEnabled | boolean                                  | 关联了currentFrame的精度是否为浮点数。                |
| segments          | AnimationSegment&nbsp;\|&nbsp;AnimationSegment[] | 当前动画的播放片段。                               |


## AnimationItem.play

play(name?: string): void

播放动画。

**参数：**

| 参数   | 类型     | 必填   | 描述              |
| ---- | ------ | ---- | --------------- |
| name | string | 否    | 被指定的动画名，缺省默认为空。 |

**示例：**

  ```ts
  this.animateItem.play()
  ```


## AnimationItem.destroy

destroy(name?: string): void

销毁动画。

**参数：**

| 参数   | 类型     | 必填   | 描述              |
| ---- | ------ | ---- | --------------- |
| name | string | 否    | 被指定的动画名，缺省默认为空。 |

**示例：**

  ```ts
  this.animateItem.destroy()
  ```


## AnimationItem.pause

pause(name?: string): void

暂停动画，下次调用play接口从当前帧开始播放。

**参数：**

| 参数   | 类型     | 必填   | 描述              |
| ---- | ------ | ---- | --------------- |
| name | string | 否    | 被指定的动画名，缺省默认为空。 |

**示例：**

  ```ts
  this.animateItem.pause()
  ```


## AnimationItem.togglePause

togglePause(name?: string): void

暂停或播放动画，等效于play接口与pause接口之间轮换调用。

**参数：**

| 参数   | 类型     | 必填   | 描述              |
| ---- | ------ | ---- | --------------- |
| name | string | 否    | 被指定的动画名，缺省默认为空。 |

**示例：**

  ```ts
  this.animateItem.togglePause()
  ```


## AnimationItem.stop

stop(name?: string): void

停止动画，下次调用play接口从第一帧开始播放。

**参数：**

| 参数   | 类型     | 必填   | 描述              |
| ---- | ------ | ---- | --------------- |
| name | string | 否    | 被指定的动画名，缺省默认为空。 |

**示例：**

  ```ts
  this.animateItem.stop()
  ```


## AnimationItem.setSpeed

setSpeed(speed: number): void

设置动画播放速度。

**参数：**

| 参数    | 类型     | 必填   | 描述                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| speed | number | 是    | 值为浮点类型,&nbsp;speed&gt;0正向播放,&nbsp;speed&lt;0反向播放,&nbsp;speed=0暂停播放,&nbsp;speed=1.0&nbsp;\|&nbsp;-1.0正常速度播放。 |

**示例：**

  ```ts
  this.animateItem.setSpeed(5);
  ```


## AnimationItem.setDirection

setDirection(direction: AnimationDirection): void

设置动画播放顺序。

**参数：**

| 参数        | 类型                 | 必填   | 描述                                       |
| --------- | ------------------ | ---- | ---------------------------------------- |
| direction | AnimationDirection | 是    | 1为正向，-1为反向;&nbsp;当设置为反向时，从当前播放进度开始回播直到首帧，loop值为true时可无限倒放；speed&lt;0叠加时也是倒放。<br/>AnimationDirection：1&nbsp;\|&nbsp;-1。 |

**示例：**

  ```ts
  this.animateItem.setDirection(-1)
  ```


## AnimationItem.goToAndStop

goToAndStop(value: number, isFrame?: boolean): void

设置动画停止在指定帧或时间进度。

**参数：**

| 参数      | 类型      | 必填   | 描述                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| value   | number  | 是    | 帧号(值大于等于0)或时间进度(ms)。                     |
| isFrame | boolean | 否    | true:&nbsp;按指定帧控制，false:按指定时间控制，缺省默认false。 |
| name    | string  | 否    | 被指定的动画名，缺省默认为空。                          |

**示例：**

  ```ts
  // 按帧号控制
  this.animateItem.goToAndStop(25, true)
  // 按时间进度控制
  this.animateItem.goToAndStop(300, false, this.animateName)
  ```


## AnimationItem.goToAndPlay

goToAndPlay(value: number, isFrame: boolean, name?: string): void

设置动画从指定帧或时间进度开始播放。

**参数：**

| 参数      | 类型      | 必填   | 描述                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| value   | number  | 是    | 帧号(值大于等于0)或时间进度(ms)                      |
| isFrame | boolean | 是    | true：按指定帧控制，&nbsp;false：按指定时间控制，缺省默认false。 |
| name    | string  | 否    | 被指定的动画名，缺省默认为空。                          |

**示例：**

  ```ts
  // 按帧号控制
  this.animateItem.goToAndPlay(25, true)
  // 按时间进度控制
  this.animateItem.goToAndPlay(300, false, this.animateName)
  ```


## AnimationItem.playSegments

playSegments(segments: AnimationSegment | AnimationSegment[], forceFlag: boolean): void

设置动画仅播放指定片段。

**参数：**

| 参数        | 类型                                       | 必填   | 描述                                       |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| segments  | AnimationSegment&nbsp;=&nbsp;[number,&nbsp;number]&nbsp;\|&nbsp;AnimationSegment[] | 是    | 片段或片段列表；<br/>如果片段列表全部播放完毕后，下轮循环播放仅播放最后一个片段 |
| forceFlag | boolean                                  | 是    | true：即时生效播放，false：延迟到下轮循环播放再生效           |

**示例：**

  ```ts
  // 指定播放片段
  this.animateItem.playSegments([10, 20], false)
  // 指定播放片段列表
  this.animateItem.playSegments([[0, 5], [20, 30]], true)
  ```


## AnimationItem.resetSegments

resetSegments(forceFlag: boolean): void

重置动画播放片段，播放全帧。

**参数：**

| 参数        | 类型      | 必填   | 描述                             |
| --------- | ------- | ---- | ------------------------------ |
| forceFlag | boolean | 是    | true：即时生效播放，false：延迟到下轮循环播放再生效 |

**示例：**

  ```ts
  this.animateItem.resetSegments(true)
  ```


## AnimationItem.resize

resize(): void

刷新动画布局。

**示例：**

  ```ts
  this.animateItem.resize()
  ```


## AnimationItem.setSubframe

setSubframe(useSubFrame: boolean): void

设置属性currentFrame的精度显示浮点数。

**参数：**

| 参数           | 类型      | 必填   | 描述                                       |
| ------------ | ------- | ---- | ---------------------------------------- |
| useSubFrames | boolean | 是    | currentFrame属性默认显示浮点数，该接口参数将影响currentFrame属性的精度。<br/>true：属性currentFrame显示浮点。<br/>false：属性currentFrame去浮点数显示整数。 |

**示例：**

  ```ts
  this.animateItem.setSubframe(false)
  ```


## AnimationItem.getDuration

getDuration(inFrames?: boolean): void

获取动画单次完整播放的时间(与播放速度无关)或帧数, 与Lottie.loadAnimation接口入参initialSegment有关。

**参数：**

| 参数       | 类型      | 必填   | 描述                                       |
| -------- | ------- | ---- | ---------------------------------------- |
| inFrames | boolean | 否    | true：获取帧数，&nbsp;false：获取时间(单位ms)，缺省默认false。 |

**示例：**

  ```ts
  this.animateItem.getDuration(true)
  ```


## AnimationItem.addEventListener

addEventListener&lt;T = any&gt;(name: AnimationEventName, callback: AnimationEventCallback&lt;T&gt;): () =&gt; void

添加侦听事件, 事件完成后会触发指定回调函数。返回可删除该侦听事件的函数对象。

**参数：**

| 参数       | 类型                              | 必填   | 描述                                       |
| -------- | ------------------------------- | ---- | ---------------------------------------- |
| name     | AnimationEventName              | 是    | 指定动画事件类型，Lottie内置动画事件类型AnimationEventName：<br/>'enterFrame'、'loopComplete'、'complete'、'segmentStart'、'destroy'、'config_ready'、'data_ready'、'DOMLoaded'、'error'、'data_failed'、'loaded_images' |
| callback | AnimationEventCallback&lt;T&gt; | 是    | 用户自定义回调函数                                |

**示例：**

  ```ts
  private callbackItem: any = function() {
      console.log("grunt loopComplete")
  }
  let delFunction = this.animateItem.addEventListener('loopComplete', this.animateName)

  // 删除侦听
  delFunction()
  ```


## AnimationItem.removeEventListener

removeEventListener&lt;T = any&gt;(name: AnimationEventName, callback?: AnimationEventCallback&lt;T&gt;): void

删除侦听事件。

**参数：**

| 参数       | 类型                              | 必填   | 描述                                       |
| -------- | ------------------------------- | ---- | ---------------------------------------- |
| name     | AnimationEventName              | 是    | 指定动画事件类型，Lottie内置动画事件类型AnimationEventName：<br/>'enterFrame'、'loopComplete'、'complete'、'segmentStart'、'destroy'、'config_ready'、'data_ready'、'DOMLoaded'、'error'、'data_failed'、'loaded_images' |
| callback | AnimationEventCallback&lt;T&gt; | 否    | 用户自定义回调函数；缺省为空时，删除此事件的所有回调函数。            |

**示例：**

  ```ts
  this.animateItem.removeEventListener('loopComplete', this.animateName)
  ```


## AnimationItem.triggerEvent

triggerEvent&lt;T = any&gt;(name: AnimationEventName, args: T): void

直接触发指定事件的所有已设置的回调函数。

**参数：**

| 参数   | 类型                 | 必填   | 描述        |
| ---- | ------------------ | ---- | --------- |
| name | AnimationEventName | 是    | 指定动画事件类型  |
| args | any                | 是    | 用户自定义回调参数 |

**示例：**

  ```ts
  private triggerCallBack: any = function(item) {
      console.log("trigger loopComplete, name:" + item.name)
  }

  this.animateItem.addEventListener('loopComplete', this.triggerCallBack)
  this.animateItem.triggerEvent('loopComplete', this.animateItem)
  this.animateItem.removeEventListener('loopComplete', this.triggerCallBack)
  ```
