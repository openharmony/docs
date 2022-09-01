# Key Event

A key event is triggered when a component interacts with a keyboard, remote control, or any other input device with keys.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

| Name | Bubbling Supported | Description |
| -------- | -------- | -------- |
| onKeyEvent(event: (event?: KeyEvent) =&gt; void) | Yes | Called when a key event occurs. For details about **event**, see [KeyEvent](#keyevent). |


## KeyEvent

- Attributes
  | Name                                         | Type                   | Description                  |
  | ------------------------------------- | --------------------------- | -------------------------- |
  | type                                  | [KeyType](#keytype-enums)   | Type of a key.                 |
  | [keyCode](../apis/js-apis-keycode.md) | number                      | Key code.                      |
  | keyText                               | string                      | Key value.                     |
  | keySource                             | [KeySource](#keysource-enums) | Type of the input device that triggers the key event. |
  | deviceId                              | number                        | ID of the input device that triggers the key event. |
  | metaKey                               | number                        | State of the metakey when the key is pressed. The value **1** means the pressed state, and **0** means the unpressed state. |
  | timestamp                             | number                        | Timestamp when the key is pressed. |

- APIs
  | Name | Description |
  | -------- | -------- |
  | stopPropagation(): void | Stops the event from bubbling upwards or downwards. |

## KeyType Enums

| Name | Description |
| -------- | -------- |
| Down | The key is pressed. |
| Up | The key is released. |


## KeySource Enums
| Name | Description |
| -------- | -------- |
| Unknown  | Unknown input device. |
| Keyboard | The input device is a keyboard. |




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
