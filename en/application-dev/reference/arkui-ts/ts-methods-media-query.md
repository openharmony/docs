# Media Query


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import mediaquery from '@ohos.mediaquery'
```


## Required Permissions

None


## mediaquery.matchMediaSync

matchMediaSync(condition: string): MediaQueryListener

Sets the media query criteria and returns the corresponding listening handle.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | condition | string | Yes | Matching&nbsp;condition&nbsp;of&nbsp;a&nbsp;media&nbsp;event. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | MediaQueryListener | Listening&nbsp;handle&nbsp;to&nbsp;a&nbsp;media&nbsp;event,&nbsp;which&nbsp;is&nbsp;used&nbsp;to&nbsp;register&nbsp;or&nbsp;unregister&nbsp;the&nbsp;listening&nbsp;callback. | 

- Example
  
  ```
  listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen to landscape events.
  ```


## MediaQueryListener

Media query handle, including the first query result when the handle is applied for.


### Attributes

  | Name | Type | Readable | Writable | Description | 
| -------- | -------- | -------- | -------- | -------- |
| matches | boolean | Yes | No | Whether&nbsp;the&nbsp;match&nbsp;condition&nbsp;is&nbsp;met. | 
| media | string | Yes | No | Matching&nbsp;condition&nbsp;of&nbsp;a&nbsp;media&nbsp;event. | 


### on

on(type: 'change', callback: Callback&lt;MediaQueryResult&gt;): void

Registers a callback with the corresponding query condition by using the handle. This callback is triggered when the media attributes change.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Must&nbsp;enter&nbsp;the&nbsp;string&nbsp;**change**. | 
  | callback | Callback&lt;MediaQueryResult&gt; | Yes | Callback&nbsp;registered&nbsp;with&nbsp;media&nbsp;query. | 

- Example
  For details, see the [off example](#off).


### off

off(type: 'change', callback?: Callback&lt;MediaQueryResult&gt;): void

  Unregisters a callback with the corresponding query condition by using the handle, so that no callback is triggered when the media attributes change.
- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | boolean | Yes | Must&nbsp;enter&nbsp;the&nbsp;string&nbsp;**change**. | 
  | callback | Callback&lt;MediaQueryResult&gt; | No | Callback&nbsp;to&nbsp;be&nbsp;unregistered.&nbsp;If&nbsp;the&nbsp;default&nbsp;value&nbsp;is&nbsp;used,&nbsp;all&nbsp;callbacks&nbsp;of&nbsp;the&nbsp;handle&nbsp;are&nbsp;unregistered. | 

- Example
  
  ```
  listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listens to landscape events.
  onPortrait(mediaQueryResult) {
      if (mediaQueryResult.matches) {
          // do something here
      } else {
          // do something here
      }
  }
  listener.on('change', onPortrait) // Register a callback.
  listener.off('change', onPortrait) // Unregister a callback.
  ```


## MediaQueryResult


### Attributes

  | Name | Type | Readable | Writable | Description | 
| -------- | -------- | -------- | -------- | -------- |
| matches | boolean | Yes | No | Whether&nbsp;the&nbsp;match&nbsp;condition&nbsp;is&nbsp;met. | 
| media | string | Yes | No | Matching&nbsp;condition&nbsp;of&nbsp;a&nbsp;media&nbsp;event. | 


### Example


```
import mediaquery from '@ohos.mediaquery'

let portraitFunc = null

@Entry
@Component
struct MediaQueryExample {
  @State color: string = '#DB7093'
  @State text: string = 'Portrait'
  listener = mediaquery.matchMediaSync('(orientation: landscape)')

  onPortrait(mediaQueryResult) {
    if (mediaQueryResult.matches) {
      this.color = '#FFD700'
      this.text = 'Landscape'
    } else {
      this.color = '#DB7093'
      this.text = 'Portrait'
    }
  }

  aboutToAppear() {
    portraitFunc = this.onPortrait.bind(this) //bind current js instance
    this.listener.on('change', portraitFunc)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(this.text).fontSize(24).fontColor(this.color)
    }
    .width('100%').height('100%')
  }
}
```

![en-us_image_0000001257138369](figures/en-us_image_0000001257138369.gif)
