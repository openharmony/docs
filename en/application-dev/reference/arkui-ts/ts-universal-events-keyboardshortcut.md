# Component Keyboard Shortcut Event

You can set one or more custom keyboard shortcuts for a component. The behavior of these keyboard shortcuts is the same as that of clicks. Components can respond to custom keyboard shortcuts even when they are not focused.

>  **NOTE**
>
>  The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

keyboardShortcut(value: string | [FunctionKey], keys: Array<[ModifierKey]>)

**Parameters**

| Name  | Type                                 | Mandatory  | Description                                    |
| ----- | ------------------------------------- | ---- | ---------------------------------------- |
| value | string \| [FunctionKey](#functionkey) | Yes   | Character key (which can be entered through the keyboard) or [function key](#functionkey).<br>|
| keys  | Array<[ModifierKey](#modifierkey)>    | Yes   | Modifier keys.<br>                              |

## ModifierKey

| Name   | Description          |
| ----- | ------------ |
| CTRL  | Ctrl key on the keyboard. |
| SHIFT | Shift key on the keyboard.|
| ALT   | Alt key on the keyboard.  |

## FunctionKey

| Name  | Description          |
| ---- | ------------ |
| ESC  | Esc key on the keyboard.|
| F1   | F1 key on the keyboard. |
| F2   | F2 key on the keyboard. |
| F3   | F3 key on the keyboard. |
| F4   | F4 key on the keyboard. |
| F5   | F5 key on the keyboard. |
| F6   | F6 key on the keyboard. |
| F7   | F7 key on the keyboard. |
| F8   | F8 key on the keyboard. |
| F9   | F9 key on the keyboard. |
| F10  | F10 key on the keyboard.|
| F11  | F11 key on the keyboard.|
| F12  | F12 key on the keyboard.|

## Precautions for Using Keyboard Shortcuts

| Scenario                                      | Processing Logic                           | Example                                      |
| ---------------------------------------- | ---------------------------------- | ---------------------------------------- |
| All components that support the **onClick** event                        | Custom keyboard shortcuts are supported.                          | –                                       |
| Requirements for custom keyboard shortcuts                                | A custom keyboard shortcut consists of one or more modifier keys (**Ctrl**, **Shift**, **Alt**, or any combination thereof) and a character key or function key.| Button('button1').keyboardShortcut('a',[ModifierKey.CTRL]) |
| Setting one custom keyboard shortcut for multiple components                           | Only the first component in the component tree responds to the custom keyboard shortcut.         | Button('button1').keyboardShortcut('a',[ModifierKey.CTRL])<br>Button('button2').keyboardShortcut('a',[ModifierKey.CTRL]) |
| When the component is focused or not                              | The component responds to the custom keyboard shortcut as long as the window is focused.                     | –                                       |
| When a single keyboard shortcut is set, it can be canceled by setting the **value**, **keys**, or both of them to null in the **keyboardShortcut** API.<br>When multiple keyboard shortcuts are set, they cannot be canceled.| Canceling the custom keyboard shortcut settings                          | Button('button1').keyboardShortcut('',[ModifierKey.CTRL])<br>Button('button2').keyboardShortcut('a',[l])<br>Button('button3').keyboardShortcut('',[]) |
| The independent pipeline sub-window and main window coexist                 | The focused window responds to the keyboard shortcut.                        | –                                       |
| Ctrl, Shift, or Alt key in the **keys** parameter of the **keyboardShortcut** API| Both the keys on the left or right sides of the keyboard work.                         | Button('button1').keyboardShortcut('a',[ModifierKey.CTRL, ModifierKey.ALT]) |
| Character key in the **value** parameter of the **keyboardShortcut** API           | The response is case-insensitive.                         | Button('button1').keyboardShortcut('a',[ModifierKey.CTRL])<br>Button('button2').keyboardShortcut('A',[ModifierKey.CTRL]) |
| Response to keyboard shortcuts                                  | The component responds continuously to the keyboard shortcut when all the set keys are pressed.             | –                                       |
| Hidden component<br>                              | The keyboard shortcut also works.                             | –                                       |
| Components in the disable state                             | The keyboard shortcut does not work.                            | –                                       |
| 1. The keyboard shortcut is the same as an existing one (including the system-defined ones).<br>2. The **value** parameter contains multiple character keys.<br>3. The **key** parameter has a duplicate modifier key.| In these cases, the keyboard shortcut is not added, and the previously added keyboard shortcuts still work.         | Button('button1').keyboardShortcut('c',[ModifierKey.CTRL])<br>Button('button2').keyboardShortcut('ab',[ModifierKey.CTRL])<br>Button('button3').keyboardShortcut('ab',[ModifierKey.CTRL,ModifierKey.CTRL]) |

## System-defined Keyboard Shortcuts

| Keyboard Shortcut           | Component                                      |
| -------------- | ---------------------------------------- |
| Ctrl + C       | [Image](ts-basic-components-image.md), [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Ctrl+ A        | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Ctrl+ V        | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Ctrl+ X        | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Shift + arrow keys   | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Ctrl+ Shift+ Z | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Ctrl+ Z        | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Ctrl+ Y        | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Arrow keys and Enter key       | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|
| Tab key          | [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md)|

## Example

Set a keyboard shortcut. You can then press the modifier key and accompanying key at the same time to trigger the component to respond to the shortcut and trigger the **onClick** event or other custom event.

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
        Button("Test short cut 1").onClick((event) => {
          this.message = "I clicked Button 1";
          console.log("I clicked 1");
        }).keyboardShortcut('.', [ModifierKey.SHIFT, ModifierKey.CTRL, ModifierKey.ALT])
          .onKeyEvent((event)=>{
            console.log("event.keyCode: " + JSON.stringify(event));
          })
        Button("Test short cut 2").onClick((event) => {
          this.message = "I clicked Button 2";
          console.log("I clicked 2");
        }).keyboardShortcut('1', [ModifierKey.CTRL])
        Button("Test short cut 3").onClick((event) => {
          this.message = "I clicked Button 3";
          console.log("I clicked 3");
        }).keyboardShortcut('A', [ModifierKey.SHIFT])
        Button("Test short cut 4").onClick((event) => {
          this.message = "I clicked Button 4";
          console.log("I clicked 4");
        }).keyboardShortcut(FunctionKey.F5, [], () => {
          this.message = "I clicked Button 4";
          console.log("I clicked user callback.");
        }).keyboardShortcut(FunctionKey.F3, [])
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
