# Key Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

| Name | Bubble&nbsp;Supported | Description |
| -------- | -------- | -------- |
| onKeyEvent(event:&nbsp;(event?:&nbsp;KeyEvent)&nbsp;=&gt;&nbsp;void) | Yes | Called&nbsp;when&nbsp;a&nbsp;key&nbsp;event&nbsp;occurs.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;event&nbsp;parameters,&nbsp;see&nbsp;[KeyEvent&nbsp;Object](#KeyEvent Object). |


### KeyEvent Object

- Attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | type | KeyType | Type&nbsp;of&nbsp;a&nbsp;key. | 
  | keyCode | number | Key&nbsp;code. | 
  | keyText | string | Key&nbsp;value. | 
  | keySource | KeySource | Type&nbsp;of&nbsp;the&nbsp;input&nbsp;device&nbsp;that&nbsp;triggers&nbsp;the&nbsp;key&nbsp;event. | 
  | deviceId | number | ID&nbsp;of&nbsp;the&nbsp;input&nbsp;device&nbsp;that&nbsp;triggers&nbsp;the&nbsp;key&nbsp;event. | 
  | metaKey | number | State&nbsp;of&nbsp;the&nbsp;metakey&nbsp;when&nbsp;the&nbsp;key&nbsp;is&nbsp;pressed.&nbsp;The&nbsp;value&nbsp;**1**&nbsp;means&nbsp;the&nbsp;pressed&nbsp;state,&nbsp;and&nbsp;**0**&nbsp;means&nbsp;the&nbsp;unpressed&nbsp;state. | 
  | timestamp | number | Timestamp&nbsp;when&nbsp;the&nbsp;key&nbsp;is&nbsp;pressed. | 

- APIs
    | Name | Description | 
  | -------- | -------- |
  | stopPropagation():&nbsp;void | Stops&nbsp;the&nbsp;event&nbsp;from&nbsp;bubbling&nbsp;upwards&nbsp;or&nbsp;downwards. | 

- KeyType enums
    | Name | Description | 
  | -------- | -------- |
  | Down | The&nbsp;key&nbsp;is&nbsp;pressed. | 
  | Up | The&nbsp;key&nbsp;is&nbsp;released. | 


- KeySource enums
    | Name | Description | 
  | -------- | -------- |
  | Unknown | Unknown&nbsp;input&nbsp;device. | 
  | Keyboard | The&nbsp;input&nbsp;device&nbsp;is&nbsp;a&nbsp;keyboard. | 

- Common KeyCode description
    | Value | Behavior | Physical&nbsp;Button | 
  | -------- | -------- | -------- |
  | 19 | Upward | Up&nbsp;button. | 
  | 20 | Downward | Down&nbsp;button. | 
  | 21 | Leftward | Left&nbsp;button. | 
  | 22 | Rightward | Right&nbsp;button. | 
  | 23 | OK | **OK**&nbsp;key&nbsp;on&nbsp;a&nbsp;remote&nbsp;control. | 
  | 66 | OK | **Enter**&nbsp;key&nbsp;on&nbsp;a&nbsp;keyboard. | 
  | 160 | OK | **Enter**&nbsp;button&nbsp;on&nbsp;the&nbsp;numeric&nbsp;keypad. | 


## Example


```
@Entry
@Component
struct KeyEventExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Column() {
      Button('KeyEvent').backgroundColor(0x2788D9)
        .onKeyEvent((event: KeyEvent) => {
          if (event.type === KeyType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === KeyType.Up) {
            this.eventType = 'Up'
          }
          console.info(this.text = 'KeyType:' + this.eventType + '\nkeyCode:' + event.keyCode + '\nkeyText:' + event.keyText)
        })
      Text(this.text).padding(15)
    }.height(300).width('100%').padding(35)
  }
}
```

![en-us_image_0000001257058433](figures/en-us_image_0000001257058433.gif)
