# 安全区域

通过expandSafeArea属性支持组件扩展其安全区域，通过设置setKeyboardAvoidMode来配置虚拟键盘弹出时页面的避让模式。

> **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 属性

| 名称           | 参数                           | 参数描述                                |
| -------------- | ----------------------------- | --------------------------------------- |
| expandSafeArea | type?: Array <[SafeAreaType](ts-types.md#safeareatype10)>,<br />edges?: Array <[SafeAreaEdge](ts-types.md#safeareaedge10)> | 控制组件扩展其安全区域。<br />默认值: <br />type: [SafeAreaType.SYSTEM, SafeAreaType.CUTOUT, SafeAreaType.KEYBOARD],<br />edges: [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM, SafeAreaEdge.START, SafeAreaEdge.END]<br />扩展至所有非安全区域。<br />type: 非必填，配置扩展安全区域的类型。<br />edges: 非必填，配置扩展安全区域的方向。 |
| setKeyboardAvoidMode<sup>11+</sup> | value?: [KeyboardAvoidMode](ts-types.md#keyboardavoidmode11) | 控制虚拟键盘抬起时页面的避让模式。<br />默认值: KeyboardAvoidMode.OFFSET <br />键盘抬起时默认页面避让模式为上抬模式。<br />必填，配置虚拟键盘避让时的页面避让模式。 |
| getKeyboardAvoidMode<sup>11+</sup> | NULL| 返回虚拟键盘抬起时的页面避让模式。 |

## 示例

### 示例1

```
// xxx.ets
@Entry
@Component
struct SafeAreaExample1 {
  @State text: string = ''
  controller: TextInputController = new TextInputController()

  build() {
    Row() {
        Column()
          .height('100%').width('100%')
          .backgroundImage($r('app.media.bg')).backgroundImageSize(ImageSize.Cover)
          .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])
    }.height('100%')
  }
}
```

![expandSafeArea1](figures/expandSafeArea1.png)

### 示例2

```
@Entry
@Component
struct SafeAreaExample {
  @State text: string = ''
  controller: TextInputController = new TextInputController()

  build() {
    Row() {
      Stack() {
        Column()
          .height('100%').width('100%')
          .backgroundImage($r('app.media.bg')).backgroundImageSize(ImageSize.Cover)
          .expandSafeArea([SafeAreaType.KEYBOARD, SafeAreaType.SYSTEM])
        Column() {
          Button('Set caretPosition 1')
            .onClick(() => {
              this.controller.caretPosition(1)
            })
          TextInput({ text: this.text, placeholder: 'input your word...', controller: this.controller })
            .placeholderFont({ size: 14, weight: 400 })
            .width(320).height(40).offset({y: 120})
            .fontSize(14).fontColor(Color.Black)
            .backgroundColor(Color.White)
        }.width('100%').alignItems(HorizontalAlign.Center)
      }
    }.height('100%')
  }
}
```

![expandSafeArea2](figures/expandSafeArea2.png)

### 示例3

```ts
import { KeyboardAvoidMode } from '@ohos.arkui.UIContext';

  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      let a = windowStage.getMainWindowSync().getUIContext().getKeyboardAvoidMode();
      windowStage.getMainWindowSync().getUIContext().setKeyboardAvoidMode(KeyboardAvoidMode.RESIZE);
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

@Entry
@Component
struct KeyboardAvoidExample {
    build() {
    Column() {
      Row().height("30%").width("100%").backgroundColor(Color.Gray)
      TextArea().width("100%").borderWidth(1)
      Text("I can see the bottom of the page").width("100%").textAlign(TextAlign.Center).backgroundColor(Color.Pink).layoutWeight(1)
    }.width('100%').height("100%")
  }
}
```

![keyboardAvoidMode1](figures/keyboardAvoidMode1.jpg)

### 示例4

```ts
import { KeyboardAvoidMode } from '@ohos.arkui.UIContext';

  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      let a = windowStage.getMainWindowSync().getUIContext().getKeyboardAvoidMode();
      windowStage.getMainWindowSync().getUIContext().setKeyboardAvoidMode(KeyboardAvoidMode.OFFSET);
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

@Entry
@Component
struct KeyboardAvoidExample {
    build() {
    Column() {
      Row().height("30%").width("100%").backgroundColor(Color.Gray)
      TextArea().width("100%").borderWidth(1)
      Text("I can see the bottom of the page").width("100%").textAlign(TextAlign.Center).backgroundColor(Color.Pink).layoutWeight(1)
    }.width('100%').height("100%")
  }
}
```

![keyboardAvoidMode1](figures/keyboardAvoidMode2.jpg)