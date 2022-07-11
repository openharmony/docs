# Key Event


> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

| Name | Bubbling Supported | Description |
| -------- | -------- | -------- |
| onKeyEvent(event: (event?: KeyEvent) =&gt; void) | Yes | Called when a key event occurs. For details about the event parameters, see [KeyEvent Object](#KeyEvent Object). |


## KeyEvent

- Attributes
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | type | [KeyType](#keytype-enums) | Type of a key. |
  | keyCode | number | Key code. |
  | keyText | string | Key value. |
  | keySource | [KeySource](#keysource-enums) | Type of the input device that triggers the key event. |
  | deviceId | number | ID of the input device that triggers the key event. |
  | metaKey | number | State of the metakey when the key is pressed. The value **1** means the pressed state, and **0** means the unpressed state. |
  | timestamp | number | Timestamp when the key is pressed. |

- APIs
  | Name | Description |
  | -------- | -------- |
  | stopPropagation(): void | Stops the event from bubbling upwards or downwards. |

##  KeyType Enums

| Name | Description |
| -------- | -------- |
| Down | The key is pressed. |
| Up | The key is released. |


## KeySource Enums
| Name | Description |
| -------- | -------- |
| Unknown | Unknown input device. |
| [KeyCode](#common-keycode-enums) | The input device is a keyboard. |

## Common KeyCode Enums

| Value | Behavior | Physical Button |
| -------- | -------- | -------- |
| 19 | Upward | Up button. |
| 20 | Downward | Down button. |
| 21 | Leftward | Left button. |
| 22 | Rightward | Right button. |
| 23 | OK | **OK** key on a remote control. |
| 66 | OK | **Enter** key on a keyboard. |
| 160 | OK | **Enter** button on the numeric keypad. |


## Example


```ts
// xxx.ets
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
