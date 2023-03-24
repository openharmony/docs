# 自定义快捷键

开发者可以设置组件的自定义组合键，组合键的行为与click行为一致，组件在未获得焦点状态下也可以响应自定义组合键，每个组件可以设置多个组合键。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 接口

**方法：** keyboardShortcut(value: string | FunctionKey, keys: Array<CtrlKey>)

**参数：**

| 参数名 | 参数类型              | 必填 | 参数描述                                                     |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| value  | string \| FunctionKey | 是   | 热键的单个字符（可以通过键盘输入的字符）或FunctionKey。<br/>默认值：无 |
| keys   | Array<CtrlKey>        | 是   | 热键组合。<br/>默认值：无                                    |

## CtrlKey枚举说明

| 名称  | 描述      |
| ----- | --------- |
| CTRL  | ctrl键。  |
| SHIFT | shift键。 |
| ALT   | alt键。   |

## FunctionKey枚举说明

| 名称 | 描述    |
| ---- | ------- |
| ESC  | ESC键。 |
| F1   | F1键。  |
| F2   | F2键。  |
| F3   | F3键。  |
| F4   | F4键。  |
| F5   | F5键。  |
| F6   | F6键。  |
| F7   | F7键。  |
| F8   | F8键。  |
| F9   | F9键。  |
| F10  | F10键。 |
| F11  | F11键。 |
| F12  | F12键。 |

## 场景说明

| 场景                                                         | 处理                                                         | 例子                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 所有支持onClick事件的组件                                    | 支持自定义组合键                                             | 无                                                           |
| 自定义组合键要求                                             | 控制键Ctrl，Shift，Alt及它们的组合加上其它可输入字符按键     | Button('button1').keyboardShortcut('a',[CtrlKey.ctrl])       |
| 多个不同组件设置相同组合键                                   | 只响应结点树上的第一个组件、其它组件不响应快捷键。           | Button('button1').keyboardShortcut('a',[CtrlKey.ctrl])<br />Button('button2').keyboardShortcut('a',[CtrlKey.ctrl]) |
| 无论组件是否获得焦点                                         | 只要窗口获焦快捷键就会响应                                   | 无                                                           |
| 绑定单个快捷键时候，通过keyboardShortcut接口value值或者是keys值或两者都是空的情况下。<br />绑定多个快捷键的时候无法取消快捷键。 | 取消快捷键的设置                                             | Button('button1').keyboardShortcut('',[CtrlKey.ctrl])<br />Button('button2').keyboardShortcut('a',[l])<br />Button('button3').keyboardShortcut('',[]) |
| 独立pipeline子窗口、主窗口共存的情况下                       | 获焦的窗口响应快捷键                                         | 无                                                           |
| keyboardShortcut接口中的keys命令中ctrl、shift、alt           | 不区分左右键都响应                                           | Button('button1').keyboardShortcut('a',[CtrlKey.ctrl, CtrlKey.alt]) |
| keyboardShortcut接口中的value单个字符                        | 不区分大小写都响应                                           | Button('button1').keyboardShortcut('a',[CtrlKey.ctrl])<br />Button('button2').keyboardShortcut('A',[CtrlKey.ctrl]) |
| 快捷键的响应                                                 | 所有快捷键down的状态下响应、且连续响应                       | 无                                                           |
| 隐藏组件<br />                                               | 响应快捷键                                                   | 无                                                           |
| disable状态组件                                              | 不响应快捷键                                                 | 无                                                           |
| 这几种情况不绑定组合键, 先前绑定的组合键仍然有效             | 组件的组合键(包括系统预定义快捷键)相同时;<br />接口参数value有多个字符时;<br />接口参数keys有重复的控制键时; | Button('button1').keyboardShortcut('c',[CtrlKey.ctrl])<br />Button('button2').keyboardShortcut('ab',[CtrlKey.ctrl])<br />Button('button3').keyboardShortcut('ab',[CtrlKey.ctrl,CtrlKey.ctrl]) |

## 系统已有组合键

| 快捷键           | 组件                       |
| ---------------- | -------------------------- |
| ctrl + C         | Image、TextInput、TextArea |
| ctrl + A         | TextInput、TextArea        |
| ctrl + V         | TextInput、TextArea        |
| ctrl + X         | TextInput、TextArea        |
| shift + 方向键   | TextInput、TextArea        |
| ctrl + shift + Z | TextInput、TextArea        |
| ctrl + Z         | TextInput、TextArea        |
| ctrl + Y         | TextInput、TextArea        |
| 方向键、回车键   | TextInput、TextArea        |
| TAB键            | TextInput、TextArea        |

## 示例

```ts
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
        }).keyboardShortcut('.', [CtrlKey.SHIFT, CtrlKey.CTRL, CtrlKey.ALT])
        Button("Test short cut 2").onClick((event) => {
          this.message = "I clicked Button 2";
          console.log("I clicked 2");
        }).keyboardShortcut('1', [CtrlKey.CTRL])
        Button("Test short cut 3").onClick((event) => {
          this.message = "I clicked Button 3";
          console.log("I clicked 3");
        }).keyboardShortcut('A', [CtrlKey.CTRL])
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



