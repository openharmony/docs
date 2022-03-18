# Lottie


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Modules to Import

  
```
import lottie from 'lottie-ohos-ets'
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> In the **Terminal** window, run the **npm install'lottie-ohos-ets...** command to download Lottie.


## lottie.loadAnimation

loadAnimation(

path: string, container: object, render: string, loop: boolean, autoplay: boolean, name: string ): AnimationItem

Loads an animation. Before calling this method, declare the **Animator('__lottie_ets')** object and check that the canvas layout is complete. This method can be used together with a lifecycle callback of the **Canvas** component, for example, **onAppear()** and **onPageShow()**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | path | string | Yes | Path&nbsp;of&nbsp;the&nbsp;animation&nbsp;resource&nbsp;file&nbsp;in&nbsp;the&nbsp;HAP&nbsp;file.&nbsp;The&nbsp;resource&nbsp;file&nbsp;must&nbsp;be&nbsp;in&nbsp;JSON&nbsp;format.&nbsp;Example:&nbsp;**path:&nbsp;"common/lottie/data.json"**. | 
  | container | object | Yes | Canvas&nbsp;drawing&nbsp;context.&nbsp;A&nbsp;**CanvasRenderingContext2D**&nbsp;object&nbsp;must&nbsp;be&nbsp;declared&nbsp;in&nbsp;advance. | 
  | render | string | Yes | Rendering&nbsp;type.&nbsp;The&nbsp;value&nbsp;can&nbsp;only&nbsp;be&nbsp;**"canvas"**. | 
  | loop | boolean&nbsp;\|&nbsp;number | No | If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;Boolean&nbsp;type,&nbsp;this&nbsp;parameter&nbsp;indicates&nbsp;whether&nbsp;to&nbsp;repeat&nbsp;the&nbsp;animation&nbsp;cyclically&nbsp;after&nbsp;the&nbsp;animation&nbsp;ends;&nbsp;the&nbsp;default&nbsp;value&nbsp;is&nbsp;**true**.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type&nbsp;and&nbsp;is&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;1,&nbsp;this&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;number&nbsp;of&nbsp;times&nbsp;the&nbsp;animation&nbsp;plays. | 
  | autoplay | boolean | No | Whether&nbsp;to&nbsp;automatically&nbsp;play&nbsp;the&nbsp;animation.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**true**. | 
  | name | string | No | Custom&nbsp;animation&nbsp;name.&nbsp;In&nbsp;later&nbsp;versions,&nbsp;the&nbsp;name&nbsp;can&nbsp;be&nbsp;used&nbsp;to&nbsp;reference&nbsp;and&nbsp;control&nbsp;the&nbsp;animation.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;null. | 
  | initialSegment | [number,&nbsp;number] | No | Start&nbsp;frame&nbsp;and&nbsp;end&nbsp;frame&nbsp;of&nbsp;the&nbsp;animation,&nbsp;respectively. | 


## lottie.destroy

destroy(name: string): void

Destroys the animation. This method must be called when a page exits. This method can be used together with a lifecycle callback of the **Canvas** component, for example, **onDisappear()** and **onPageHide()**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;animation&nbsp;to&nbsp;destroy,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;destroyed. | 

- Example
    
  ```
  import lottie from 'lottie-web'
  
  @Entry
  @Component
  struct Index {
    private controller: CanvasRenderingContext2D = new CanvasRenderingContext2D()
    private animateName: string = "animate"
    private animatePath: string = "common/lottie/data.json"
    private animateItem: any = null
  
    private onPageHide(): void {
      console.log('onPageHide')
      lottie.destroy()
    }
  
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.controller)
        .width('30%')
        .height('20%')
        .backgroundColor('#0D9FFB')
        .onAppear(() => {
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

  ![en-us_image_0000001256978355](figures/en-us_image_0000001256978355.gif)


## lottie.play

play(name: string): void

Plays a specified animation.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;animation&nbsp;to&nbsp;play,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;played. | 

- Example
    
  ```
  lottie.play(this.animateName)
  ```


## lottie.pause

pause(name: string): void

Pauses a specified animation. The next time **lottie.play()** is called, the animation starts from the current frame.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;animation&nbsp;to&nbsp;pause,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;paused. | 

- Example
    
  ```
  lottie.pause(this.animateName)
  ```


## lottie.togglePause

togglePause(name: string): void

Pauses or plays a specified animation. This method is equivalent to the switching between **lottie.play()** and **lottie.pause()**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;paused. | 

- Example
    
  ```
  lottie.togglePause(this.animateName)
  ```


## lottie.stop

stop(name: string): void

Stops the specified animation. The next time **lottie.play()** is called, the animation starts from the first frame.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;paused. | 

- Example
    
  ```
  lottie.stop(this.animateName)
  ```


## lottie.setSpeed

setSpeed(speed: number, name: string): void

Sets the playback speed of the specified animation.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | speed | number | Yes | Playback&nbsp;speed.&nbsp;The&nbsp;value&nbsp;is&nbsp;a&nbsp;floating-point&nbsp;number.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;in&nbsp;forward&nbsp;direction.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;in&nbsp;reversed&nbsp;direction.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;0,&nbsp;the&nbsp;animation&nbsp;is&nbsp;paused.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;1.0&nbsp;or&nbsp;-1.0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;at&nbsp;the&nbsp;normal&nbsp;speed. | 
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;stopped. | 

- Example
    
  ```
  lottie.setSpeed(5, this.animateName)
  ```


## lottie.setDirection

setDirection(direction: AnimationDirection, name: string): void

Sets the direction in which the specified animation plays.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | direction | AnimationDirection | Yes | Direction&nbsp;in&nbsp;which&nbsp;the&nbsp;animation&nbsp;plays.&nbsp;**1**:&nbsp;forwards;&nbsp;**-1**:&nbsp;backwards.&nbsp;When&nbsp;set&nbsp;to&nbsp;play&nbsp;backwards,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;from&nbsp;the&nbsp;current&nbsp;playback&nbsp;progress&nbsp;to&nbsp;the&nbsp;first&nbsp;frame.&nbsp;When&nbsp;this&nbsp;setting&nbsp;is&nbsp;combined&nbsp;with&nbsp;**loop**&nbsp;being&nbsp;set&nbsp;to&nbsp;**true**,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;backwards&nbsp;continuously.&nbsp;When&nbsp;the&nbsp;value&nbsp;of&nbsp;**speed**&nbsp;is&nbsp;less&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;also&nbsp;plays&nbsp;backwards.<br/>**AnimationDirection**:&nbsp;1&nbsp;\|&nbsp;-1. | 
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation,&nbsp;which&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**name**&nbsp;in&nbsp;the&nbsp;**loadAnimation**&nbsp;interface.&nbsp;By&nbsp;default,&nbsp;all&nbsp;animations&nbsp;are&nbsp;set. | 

- Example
    
  ```
  lottie.setDirection(-1, this.animateName)
  ```


## AnimationItem

Defines an **AnimationItem** object, which is returned by the **loadAnimation** interface and has attributes and interfaces. The attributes are described as follows:

  | Name | Type | Description | 
| -------- | -------- | -------- |
| name | string | Animation&nbsp;name. | 
| isLoaded | boolean | Whether&nbsp;the&nbsp;animation&nbsp;is&nbsp;loaded. | 
| currentFrame | number | Frame&nbsp;that&nbsp;is&nbsp;being&nbsp;played.&nbsp;The&nbsp;default&nbsp;precision&nbsp;is&nbsp;a&nbsp;floating-point&nbsp;number&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;0.0.&nbsp;After&nbsp;**setSubframe(false)**&nbsp;is&nbsp;called,&nbsp;the&nbsp;value&nbsp;is&nbsp;a&nbsp;positive&nbsp;integer&nbsp;without&nbsp;decimal&nbsp;points. | 
| currentRawFrame | number | Number&nbsp;of&nbsp;frames&nbsp;that&nbsp;are&nbsp;being&nbsp;played.&nbsp;The&nbsp;precision&nbsp;is&nbsp;a&nbsp;floating&nbsp;point&nbsp;number&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;0.0. | 
| firstFrame | number | First&nbsp;frame&nbsp;of&nbsp;the&nbsp;animation&nbsp;segment&nbsp;that&nbsp;is&nbsp;being&nbsp;played. | 
| totalFrames | number | Total&nbsp;number&nbsp;of&nbsp;frames&nbsp;in&nbsp;the&nbsp;animation&nbsp;segment&nbsp;that&nbsp;is&nbsp;being&nbsp;played. | 
| frameRate | number | Frame&nbsp;rate&nbsp;(frame/s). | 
| frameMult | number | Frame&nbsp;rate&nbsp;(frame/ms). | 
| playSpeed | number | Playback&nbsp;speed.&nbsp;The&nbsp;value&nbsp;is&nbsp;a&nbsp;floating-point&nbsp;number.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;in&nbsp;forward&nbsp;direction.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;in&nbsp;reversed&nbsp;direction.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;0,&nbsp;the&nbsp;animation&nbsp;is&nbsp;paused.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**1.0**&nbsp;or&nbsp;**-1.0**,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;at&nbsp;the&nbsp;normal&nbsp;speed. | 
| playDirection | number | Playback&nbsp;direction.&nbsp;The&nbsp;options&nbsp;are&nbsp;**1**&nbsp;(forward)&nbsp;and&nbsp;**-1**&nbsp;(backward). | 
| playCount | number | Number&nbsp;of&nbsp;times&nbsp;the&nbsp;animation&nbsp;plays. | 
| isPaused | boolean | Whether&nbsp;the&nbsp;current&nbsp;animation&nbsp;is&nbsp;paused.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;that&nbsp;the&nbsp;animation&nbsp;is&nbsp;paused. | 
| autoplay | boolean | Whether&nbsp;to&nbsp;automatically&nbsp;play&nbsp;the&nbsp;animation&nbsp;upon&nbsp;completion&nbsp;of&nbsp;the&nbsp;loading.&nbsp;The&nbsp;value&nbsp;**false**&nbsp;means&nbsp;that&nbsp;the&nbsp;**play()**&nbsp;interface&nbsp;needs&nbsp;to&nbsp;be&nbsp;called&nbsp;to&nbsp;start&nbsp;playing. | 
| loop | boolean&nbsp;\|&nbsp;number | If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;Boolean&nbsp;type,&nbsp;this&nbsp;parameter&nbsp;indicates&nbsp;whether&nbsp;to&nbsp;repeat&nbsp;the&nbsp;animation&nbsp;cyclically&nbsp;after&nbsp;the&nbsp;animation&nbsp;ends.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type&nbsp;and&nbsp;is&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;1,&nbsp;this&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;number&nbsp;of&nbsp;times&nbsp;the&nbsp;animation&nbsp;plays. | 
| renderer | any | Animation&nbsp;rendering&nbsp;object,&nbsp;which&nbsp;depends&nbsp;on&nbsp;the&nbsp;rendering&nbsp;type. | 
| animationID | string | Animation&nbsp;ID. | 
| timeCompleted | number | Number&nbsp;of&nbsp;frames&nbsp;that&nbsp;are&nbsp;played&nbsp;for&nbsp;an&nbsp;animation&nbsp;sequence.&nbsp;The&nbsp;value&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;setting&nbsp;of&nbsp;**AnimationSegment**&nbsp;and&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;value&nbsp;of&nbsp;**totalFrames**. | 
| segmentPos | number | ID&nbsp;of&nbsp;the&nbsp;current&nbsp;animation&nbsp;segment.&nbsp;The&nbsp;value&nbsp;is&nbsp;a&nbsp;positive&nbsp;integer&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;0. | 
| isSubframeEnabled | boolean | Whether&nbsp;the&nbsp;precision&nbsp;of&nbsp;**currentFrame**&nbsp;is&nbsp;a&nbsp;floating&nbsp;point&nbsp;number. | 
| segments | AnimationSegment&nbsp;\|&nbsp;AnimationSegment[] | Current&nbsp;segment&nbsp;of&nbsp;the&nbsp;animation. | 


## AnimationItem.play

play(name?: string): void

Plays an animation.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  this.animateItem.play()
  ```


## AnimationItem.destroy

destroy(name?: string): void

Destroys an animation.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  this.animateItem.destroy()
  ```


## AnimationItem.pause

pause(name?: string): void

Pauses an animation. When the **play** interface is called next time, the animation is played from the current frame.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  this.animateItem.pause()
  ```


## AnimationItem.togglePause

togglePause(name?: string): void

Pauses or plays an animation. This method is equivalent to the switching between **play** and **pause**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  this.animateItem.togglePause()
  ```


## AnimationItem.stop

stop(name?: string): void

Stops an animation. When the **play** interface is called next time, the animation is played from the first frame.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  this.animateItem.stop()
  ```


## AnimationItem.setSpeed

setSpeed(speed: number): void

Sets the playback speed of an animation.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | speed | number | Yes | Playback&nbsp;speed.&nbsp;The&nbsp;value&nbsp;is&nbsp;a&nbsp;floating-point&nbsp;number.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;in&nbsp;forward&nbsp;direction.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;in&nbsp;reversed&nbsp;direction.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;0,&nbsp;the&nbsp;animation&nbsp;is&nbsp;paused.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**1.0**&nbsp;or&nbsp;**-1.0**,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;at&nbsp;the&nbsp;normal&nbsp;speed. | 

- Example
    
  ```
  this.animateItem.setSpeed(5);
  ```


## AnimationItem.setDirection

setDirection(direction: AnimationDirection): void

Sets the playback direction of an animation.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | direction | AnimationDirection | Yes | Direction&nbsp;in&nbsp;which&nbsp;the&nbsp;animation&nbsp;plays.&nbsp;**1**:&nbsp;forwards;&nbsp;**-1**:&nbsp;backwards.&nbsp;When&nbsp;set&nbsp;to&nbsp;play&nbsp;backwards,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;from&nbsp;the&nbsp;current&nbsp;playback&nbsp;progress&nbsp;to&nbsp;the&nbsp;first&nbsp;frame.&nbsp;When&nbsp;this&nbsp;setting&nbsp;is&nbsp;combined&nbsp;with&nbsp;**loop**&nbsp;being&nbsp;set&nbsp;to&nbsp;**true**,&nbsp;the&nbsp;animation&nbsp;plays&nbsp;backwards&nbsp;continuously.&nbsp;When&nbsp;the&nbsp;value&nbsp;of&nbsp;**speed**&nbsp;is&nbsp;less&nbsp;than&nbsp;0,&nbsp;the&nbsp;animation&nbsp;also&nbsp;plays&nbsp;backwards.<br/>**AnimationDirection**:&nbsp;1&nbsp;\|&nbsp;-1. | 

- Example
    
  ```
  this.animateItem.setDirection(-1)
  ```


## AnimationItem.goToAndStop

goToAndStop(value: number, isFrame: boolean): void

Sets the animation to stop at the specified frame or time.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | number | Yes | Frame&nbsp;ID&nbsp;(greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;0)&nbsp;or&nbsp;time&nbsp;progress&nbsp;(ms)&nbsp;at&nbsp;which&nbsp;the&nbsp;animation&nbsp;will&nbsp;stop. | 
  | isFrame | boolean | No | Whether&nbsp;to&nbsp;set&nbsp;the&nbsp;animation&nbsp;to&nbsp;stop&nbsp;at&nbsp;the&nbsp;specified&nbsp;frame.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;to&nbsp;set&nbsp;the&nbsp;animation&nbsp;to&nbsp;stop&nbsp;at&nbsp;the&nbsp;specified&nbsp;frame,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;to&nbsp;set&nbsp;the&nbsp;animation&nbsp;to&nbsp;stop&nbsp;at&nbsp;the&nbsp;specified&nbsp;time&nbsp;progress.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. | 
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  // Set the animation to stop at the specified frame.
  this.animateItem.goToAndStop(25, true)
  // Set the animation to stop at the specified time progress.
  this.animateItem.goToAndStop(300, false, this.animateName)
  ```


## AnimationItem.goToAndPlay

goToAndPlay(value: number, isFrame: boolean): void

Sets the animation to start from the specified frame or time progress.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | number | Yes | Frame&nbsp;ID&nbsp;(greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;0)&nbsp;or&nbsp;time&nbsp;progress&nbsp;(ms)&nbsp;at&nbsp;which&nbsp;the&nbsp;animation&nbsp;will&nbsp;start. | 
  | isFrame | boolean | Yes | Whether&nbsp;to&nbsp;set&nbsp;the&nbsp;animation&nbsp;to&nbsp;start&nbsp;from&nbsp;the&nbsp;specified&nbsp;frame.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;to&nbsp;set&nbsp;the&nbsp;animation&nbsp;to&nbsp;start&nbsp;from&nbsp;the&nbsp;specified&nbsp;frame,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;to&nbsp;set&nbsp;the&nbsp;animation&nbsp;to&nbsp;start&nbsp;from&nbsp;the&nbsp;specified&nbsp;time&nbsp;progress.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. | 
  | name | string | No | Name&nbsp;of&nbsp;the&nbsp;target&nbsp;animation.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null. | 

- Example
    
  ```
  // Set the animation to stop at the specified frame.
  this.animateItem.goToAndPlay(25, true)
  // Set the animation to stop at the specified time progress.
  this.animateItem.goToAndPlay(300, false, this.animateName)
  ```


## AnimationItem.playSegments

playSegments(segments: AnimationSegment | AnimationSegment[], forceFlag: boolean): void

Sets the animation to play only the specified segment.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | segments | AnimationSegment&nbsp;=&nbsp;[number,&nbsp;number]&nbsp;\|&nbsp;AnimationSegment[] | Yes | Segment&nbsp;or&nbsp;segment&nbsp;list.<br/>If&nbsp;all&nbsp;segments&nbsp;in&nbsp;the&nbsp;segment&nbsp;list&nbsp;are&nbsp;played,&nbsp;only&nbsp;the&nbsp;last&nbsp;segment&nbsp;is&nbsp;played&nbsp;in&nbsp;the&nbsp;next&nbsp;cycle. | 
  | forceFlag | boolean | Yes | Whether&nbsp;the&nbsp;settings&nbsp;take&nbsp;effect&nbsp;immediately.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;the&nbsp;settings&nbsp;take&nbsp;effect&nbsp;immediately,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;the&nbsp;settings&nbsp;take&nbsp;effect&nbsp;until&nbsp;the&nbsp;current&nbsp;cycle&nbsp;of&nbsp;playback&nbsp;is&nbsp;completed. | 

- Example
    
  ```
  // Set the animation to play the specified segment.
  this.animateItem.playSegments([10, 20], false)
  // Set the animation to play the specified segment list.
  this.animateItem.playSegments([[0, 5], [20, 30]], true)
  ```


## AnimationItem.resetSegments

resetSegments(forceFlag: boolean): void

Resets the settings configured by the **playSegments** method to play all the frames.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | forceFlag | boolean | Yes | Whether&nbsp;the&nbsp;settings&nbsp;take&nbsp;effect&nbsp;immediately.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;the&nbsp;settings&nbsp;take&nbsp;effect&nbsp;immediately,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;the&nbsp;settings&nbsp;take&nbsp;effect&nbsp;until&nbsp;the&nbsp;current&nbsp;cycle&nbsp;of&nbsp;playback&nbsp;is&nbsp;completed. | 

- Example
    
  ```
  this.animateItem.resetSegments(true)
  ```


## AnimationItem.resize

resize(): void

Resizes the animation layout.

- Example
    
  ```
  this.animateItem.resize()
  ```


## AnimationItem.setSubframe

setSubframe(useSubFrame: boolean): void

Sets the precision of the **currentFrame** attribute to display floating-point numbers.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | useSubFrames | boolean | Yes | Whether&nbsp;the&nbsp;**currentFrame**&nbsp;attribute&nbsp;displays&nbsp;floating-point&nbsp;numbers.&nbsp;By&nbsp;default,&nbsp;the&nbsp;attribute&nbsp;displays&nbsp;floating-point&nbsp;numbers.<br/>**true**:&nbsp;The&nbsp;**currentFrame**&nbsp;attribute&nbsp;displays&nbsp;floating-point&nbsp;numbers.<br/>**false**:&nbsp;The&nbsp;**currentFrame**&nbsp;attribute&nbsp;displays&nbsp;an&nbsp;integer&nbsp;and&nbsp;does&nbsp;not&nbsp;display&nbsp;floating-point&nbsp;numbers. | 

- Example
    
  ```
  this.animateItem.setSubframe(false)
  ```


## AnimationItem.getDuration

getDuration(inFrames?: boolean): void

Obtains the duration (irrelevant to the playback speed) or number of frames for playing an animation sequence. The settings are related to the input parameter **initialSegment** of the **Lottie.loadAnimation** interface.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | inFrames | boolean | No | Whether&nbsp;to&nbsp;obtain&nbsp;the&nbsp;duration&nbsp;or&nbsp;number&nbsp;of&nbsp;frames.&nbsp;**true**:&nbsp;number&nbsp;of&nbsp;frames.&nbsp;**false**:&nbsp;duration,&nbsp;in&nbsp;ms.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. | 

- Example
    
  ```
  this.animateItem.getDuration(true)
  ```


## AnimationItem.addEventListener

addEventListener&lt;T = any&gt;(name: AnimationEventName, callback: AnimationEventCallback&lt;T&gt;): () =&gt; void

Adds an event listener. After the event is complete, the specified callback function is triggered. This method returns the function object that can delete the event listener.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | AnimationEventName | Yes | Animation&nbsp;event&nbsp;type.&nbsp;The&nbsp;available&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>'enterFrame',&nbsp;'loopComplete',&nbsp;'complete',&nbsp;'segmentStart',&nbsp;'destroy',&nbsp;'config_ready',&nbsp;'data_ready',&nbsp;'DOMLoaded',&nbsp;'error',&nbsp;'data_failed',&nbsp;'loaded_images' | 
  | callback | AnimationEventCallback&lt;T&gt; | Yes | Custom&nbsp;callback. | 

- Example
    
  ```
  private callbackItem: any = function() {
      console.log("grunt loopComplete")
  }
  let delFunction = this.animateItem.addEventListener('loopComplete', this.animateName)
  
  // Delete the event listener.
  delFunction()
  ```


## AnimationItem.removeEventListener

removeEventListener&lt;T = any&gt;(name: AnimationEventName, callback?: AnimationEventCallback&lt;T&gt;): void

Removes an event listener.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | AnimationEventName | Yes | Animation&nbsp;event&nbsp;type.&nbsp;The&nbsp;available&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>'enterFrame',&nbsp;'loopComplete',&nbsp;'complete',&nbsp;'segmentStart',&nbsp;'destroy',&nbsp;'config_ready',&nbsp;'data_ready',&nbsp;'DOMLoaded',&nbsp;'error',&nbsp;'data_failed',&nbsp;'loaded_images' | 
  | callback | AnimationEventCallback&lt;T&gt; | Yes | Custom&nbsp;callback.&nbsp;By&nbsp;default,&nbsp;the&nbsp;value&nbsp;is&nbsp;null,&nbsp;meaning&nbsp;that&nbsp;all&nbsp;callbacks&nbsp;of&nbsp;the&nbsp;event&nbsp;will&nbsp;be&nbsp;removed. | 

- Example
    
  ```
  this.animateItem.removeEventListener('loopComplete', this.animateName)
  ```


## AnimationItem.triggerEvent

triggerEvent&lt;T = any&gt;(name: AnimationEventName, args: T): void

Directly triggers all configured callbacks of a specified event.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | AnimationEventName | Yes | Animation&nbsp;event&nbsp;type. | 
  | args | any | Yes | Custom&nbsp;callback&nbsp;parameters. | 

- Example
    
  ```
  private triggerCallBack: any = function(item) {
      console.log("trigger loopComplete, name:" + item.name)
  }
  
  this.animateItem.addEventListener('loopComplete', this.triggerCallBack)
  this.animateItem.triggerEvent('loopComplete', this.animateItem)
  this.animateItem.removeEventListener('loopComplete', this.triggerCallBack)
  ```
