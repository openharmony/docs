# @ohos.arkui.UIContext (UIContext)

在Stage模型中，WindowStage/Window可以通过loadContent接口加载页面并创建UI的实例，并将页面内容渲染到关联的窗口中，所以UI实例和窗口是一一关联的。一些全局的UI接口是和具体UI实例的执行上下文相关的，在当前接口调用时，通过追溯调用链跟踪到UI的上下文，来确定具体的UI实例。若在非UI页面中或者一些异步回调中调用这类接口，可能无法跟踪到当前UI的上下文，导致接口执行失败。

@ohos.window在API version 10 新增[getUIContext](./js-apis-window.md#getuicontext10)接口，获取UI上下文实例UIContext对象，使用UIContext对象提供的替代方法，可以直接作用在对应的UI实例上。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 示例效果请以真机运行为准，当前IDE预览器不支持。

## UIContext

以下API需先使用ohos.window中的[getUIContext()](./js-apis-window.md#getuicontext10)方法获取UIContext实例，再通过此实例调用对应方法。本文中UIContext对象以uiContext表示。

### getFont

getFont(): Font

获取Font对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型            | 说明          |
| ------------- | ----------- |
| [Font](#font) | 返回Font实例对象。 |

**示例：**

```ts
uiContext.getFont();
```
### getComponentUtils

getComponentUtils(): ComponentUtils

获取ComponentUtils对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                | 说明                    |
| --------------------------------- | --------------------- |
| [ComponentUtils](#componentutils) | 返回ComponentUtils实例对象。 |

**示例：**

```ts
uiContext.getComponentUtils();
```

### getUIInspector

getUIInspector(): UIInspector

获取UIInspector对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                          | 说明                 |
| --------------------------- | ------------------ |
| [UIInspector](#uiinspector) | 返回UIInspector实例对象。 |

**示例：**

```ts
uiContext.getUIInspector();
```

### getUIObserver<sup>11+</sup>

getUIObserver(): UIObserver

获取UIObserver对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                          | 说明                 |
| --------------------------- | ------------------ |
| [UIObserver](#uiobserver11) | 返回UIObserver实例对象。 |

**示例：**

```ts
uiContext.getUIObserver();
```

### getMediaQuery

getMediaQuery(): MediaQuery

获取MediaQuery对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                        | 说明                |
| ------------------------- | ----------------- |
| [MediaQuery](#mediaquery) | 返回MediaQuery实例对象。 |

**示例：**

```ts
uiContext.getMediaQuery();
```

### getRouter

getRouter(): Router

获取Router对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明            |
| ----------------- | ------------- |
| [Router](#router) | 返回Router实例对象。 |

**示例：**

```ts
uiContext.getRouter();
```

### getPromptAction

getPromptAction(): PromptAction

获取PromptAction对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                            | 说明                  |
| ----------------------------- | ------------------- |
| [PromptAction](#promptaction) | 返回PromptAction实例对象。 |

**示例：**

```ts
uiContext.getPromptAction();
```

### animateTo

animateTo(value: AnimateParam, event: () => void): void

提供animateTo接口来指定由于闭包代码导致的状态变化插入过渡动效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                       | 必填   | 说明                                    |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](../arkui-ts/ts-explicit-animation.md#animateparam对象说明) | 是    | 设置动画效果相关参数。                           |
| event | () => void                               | 是    | 指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State rotateAngle: number = 0
  private flag: boolean = true

  build() {
    Column() {
      Button('change size')
        .width(this.widthSize)
        .height(this.heightSize)
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            uiContext.animateTo({
              duration: 2000,
              curve: Curve.EaseOut,
              iterations: 3,
              playMode: PlayMode.Normal,
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            uiContext.animateTo({}, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
          }
          this.flag = !this.flag
        })
      Button('change rotate angle')
        .margin(50)
        .rotate({ x: 0, y: 0, z: 1, angle: this.rotateAngle })
        .onClick(() => {
          uiContext.animateTo({
            duration: 1200,
            curve: Curve.Friction,
            delay: 500,
            iterations: -1, // 设置-1表示动画无限循环
            playMode: PlayMode.Alternate,
            onFinish: () => {
              console.info('play end')
            }
          }, () => {
            this.rotateAngle = 90
          })
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

### showAlertDialog

showAlertDialog(options: AlertDialogParamWithConfirm | AlertDialogParamWithButtons | AlertDialogParamWithOptions): void

显示警告弹窗组件，可设置文本内容与响应回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明                  |
| ------- | ---------------------------------------- | ---- | ------------------- |
| options | [AlertDialogParamWithConfirm](../arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithconfirm对象说明)&nbsp;\|&nbsp;[AlertDialogParamWithButtons](../arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithbuttons对象说明)&nbsp;\|&nbsp;[AlertDialogParamWithOptions](../arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithoptions10对象说明) | 是    | 定义并显示AlertDialog组件。 |


**示例：**

```ts
uiContext.showAlertDialog(
  {
    title: 'title',
    message: 'text',
    autoCancel: true,
    alignment: DialogAlignment.Bottom,
    offset: { dx: 0, dy: -20 },
    gridCount: 3,
    confirm: {
      value: 'button',
      action: () => {
        console.info('Button-clicking callback')
      }
    },
    cancel: () => {
      console.info('Closed callbacks')
    }
  }
)
```

### showActionSheet

showActionSheet(value: ActionSheetOptions): void

定义列表弹窗并弹出。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**ActionSheetOptions参数：**

| 参数名        | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| title      | [Resource](../arkui-ts/ts-types.md#resource)&nbsp;\|&nbsp;string | 是    | 弹窗标题。                                    |
| message    | [Resource](../arkui-ts/ts-types.md#resource)&nbsp;\|&nbsp;string | 是    | 弹窗内容。                                    |
| autoCancel | boolean                                  | 否    | 点击遮障层时，是否关闭弹窗。<br>默认值：true               |
| confirm    | {<br/>value:&nbsp;[ResourceStr](../arkui-ts/ts-types.md#resourcestr),<br/>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} | 否    | 确认按钮的文本内容和点击回调。<br>默认值：<br/>value：按钮文本内容。<br/>action:&nbsp;按钮选中时的回调。 |
| cancel     | ()&nbsp;=&gt;&nbsp;void                  | 否    | 点击遮障层关闭dialog时的回调。                       |
| alignment  | [DialogAlignment](../arkui-ts/ts-methods-alert-dialog-box.md#dialogalignment枚举说明) | 否    | 弹窗在竖直方向上的对齐方式。<br>默认值：DialogAlignment.Bottom |
| offset     | {<br/>dx:&nbsp;[Length](../arkui-ts/ts-types.md#length),<br/>dy:&nbsp;[Length](../arkui-ts/ts-types.md#length)<br/>} | 否    | 弹窗相对alignment所在位置的偏移量。{<br/>dx:&nbsp;0,<br/>dy:&nbsp;0<br/>} |
| sheets     | Array&lt;SheetInfo&gt;                   | 是    | 设置选项内容，每个选择项支持设置图片、文本和选中的回调。             |

**SheetInfo接口说明：**

| 参数名    | 类型                                       | 必填   | 说明             |
| ------ | ---------------------------------------- | ---- | -------------- |
| title  | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | 是    | 选项的文本内容。       |
| icon   | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | 否    | 选项的图标，默认无图标显示。 |
| action | ()=&gt;void                              | 是    | 选项选中的回调。       |

**示例：**

```ts
uiContext.showActionSheet({
  title: 'ActionSheet title',
  message: 'message',
  autoCancel: true,
  confirm: {
    value: 'Confirm button',
    action: () => {
      console.log('Get Alert Dialog handled')
    }
  },
  cancel: () => {
    console.log('actionSheet canceled')
  },
  alignment: DialogAlignment.Bottom,
  offset: { dx: 0, dy: -10 },
  sheets: [
    {
      title: 'apples',
      action: () => {
        console.log('apples')
      }
    },
    {
      title: 'bananas',
      action: () => {
        console.log('bananas')
      }
    },
    {
      title: 'pears',
      action: () => {
        console.log('pears')
      }
    }
  ]
})
```

### showDatePickerDialog

showDatePickerDialog(options: DatePickerDialogOptions): void

定义日期滑动选择器弹窗并弹出。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**DatePickerDialogOptions参数：**

| 参数名                | 类型                                       | 必填   | 说明                                     |
| ------------------ | ---------------------------------------- | ---- | -------------------------------------- |
| start              | Date                                     | 否    | 设置选择器的起始日期。<br/>默认值：Date('1970-1-1')   |
| end                | Date                                     | 否    | 设置选择器的结束日期。<br/>默认值：Date('2100-12-31') |
| selected           | Date                                     | 否    | 设置当前选中的日期。<br/>默认值：当前系统日期              |
| lunar              | boolean                                  | 否    | 日期是否显示为农历。<br/>默认值：false               |
| showTime           | boolean                                  | 否    | 是否展示时间项。<br/>默认值：false                 |
| useMilitaryTime    | boolean                                  | 否    | 展示时间是否为24小时制。<br/>默认值：false            |
| disappearTextStyle | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置所有选项中最上和最下两个选项的文本颜色、字号、字体粗细。         |
| textStyle          | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细。     |
| selectedTextStyle  | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置选中项的文本颜色、字号、字体粗细。                    |
| onAccept           | (value: [DatePickerResult](../arkui-ts/ts-basic-components-datepicker.md#datepickerresult对象说明)) => void | 否    | 点击弹窗中的“确定”按钮时触发该回调。                    |
| onCancel           | () => void                               | 否    | 点击弹窗中的“取消”按钮时触发该回调。                    |
| onChange           | (value: [DatePickerResult](../arkui-ts/ts-basic-components-datepicker.md#datepickerresult对象说明)) => void | 否    | 滑动弹窗中的滑动选择器使当前选中项改变时触发该回调。             |

**示例：**

```ts
let selectedDate: Date = new Date("2010-1-1")
uiContext.showDatePickerDialog({
  start: new Date("2000-1-1"),
  end: new Date("2100-12-31"),
  selected: selectedDate,
  onAccept: (value: DatePickerResult) => {
    // 通过Date的setFullYear方法设置按下确定按钮时的日期，这样当弹窗再次弹出时显示选中的是上一次确定的日期
    selectedDate.setFullYear(Number(value.year), Number(value.month), Number(value.day))
    console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))
  },
  onCancel: () => {
    console.info("DatePickerDialog:onCancel()")
  },
  onChange: (value: DatePickerResult) => {
    console.info("DatePickerDialog:onChange()" + JSON.stringify(value))
  }
})
```

### showTimePickerDialog

showTimePickerDialog(options: TimePickerDialogOptions): void

定义时间滑动选择器弹窗并弹出。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**TimePickerDialogOptions参数：**

| 参数名                | 类型                                       | 必填   | 说明                                   |
| ------------------ | ---------------------------------------- | ---- | ------------------------------------ |
| selected           | Date                                     | 否    | 设置当前选中的时间。<br/>默认值：当前系统时间            |
| useMilitaryTime    | boolean                                  | 否    | 展示时间是否为24小时制，默认为12小时制。<br/>默认值：false |
| disappearTextStyle | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置所有选项中最上和最下两个选项的文本颜色、字号、字体粗细。       |
| textStyle          | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细。   |
| selectedTextStyle  | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置选中项的文本颜色、字号、字体粗细。                  |
| onAccept           | (value: [TimePickerResult](../arkui-ts/ts-basic-components-timepicker.md#timepickerresult对象说明)) => void | 否    | 点击弹窗中的“确定”按钮时触发该回调。                  |
| onCancel           | () => void                               | 否    | 点击弹窗中的“取消”按钮时触发该回调。                  |
| onChange           | (value: [TimePickerResult](../arkui-ts/ts-basic-components-timepicker.md#timepickerresult对象说明)) => void | 否    | 滑动弹窗中的选择器使当前选中时间改变时触发该回调。            |

**示例：**

```ts
class sethours{
  selectTime: Date = new Date('2020-12-25T08:30:00')
  hours(h:number,m:number){
    this.selectTime.setHours(h,m)
  }
}
uiContext.showTimePickerDialog({
  selected: this.selectTime,
  onAccept: (value: TimePickerResult) => {
    // 设置selectTime为按下确定按钮时的时间，这样当弹窗再次弹出时显示选中的为上一次确定的时间
    let time = new sethours()
    if(value.hour&&value.minute){
      time.hours(value.hour, value.minute)
    }
    console.info("TimePickerDialog:onAccept()" + JSON.stringify(value))
  },
  onCancel: () => {
    console.info("TimePickerDialog:onCancel()")
  },
  onChange: (value: TimePickerResult) => {
    console.info("TimePickerDialog:onChange()" + JSON.stringify(value))
  }
})
```

### showTextPickerDialog

showTextPickerDialog(options: TextPickerDialogOptions): void

定义文本滑动选择器弹窗并弹出。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**TextPickerDialogOptions参数：**

| 参数名                     | 类型                                       | 必填   | 说明                                       |
| ----------------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| range                   | string[]&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)\|[TextPickerRangeContent](../arkui-ts/ts-basic-components-textpicker.md#textpickerrangecontent10类型说明)[] | 是    | 设置文本选择器的选择范围。不可设置为空数组，若设置为空数组，则不弹出弹窗。    |
| selected                | number                                   | 否    | 设置选中项的索引值。<br>默认值：0                      |
| value                   | string                                   | 否    | 设置选中项的文本内容。当设置了selected参数时，该参数不生效。如果设置的value值不在range范围内，则默认取range第一个元素。 |
| defaultPickerItemHeight | number \| string                         | 否    | 设置选择器中选项的高度。                             |
| disappearTextStyle      | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置所有选项中最上和最下两个选项的文本颜色、字号、字体粗细。           |
| textStyle               | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细。       |
| selectedTextStyle       | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10类型说明) | 否    | 设置选中项的文本颜色、字号、字体粗细。                      |
| onAccept                | (value: [TextPickerResult](../arkui-ts/ts-methods-textpicker-dialog.md#textpickerresult对象说明)) => void | 否    | 点击弹窗中的“确定”按钮时触发该回调。                      |
| onCancel                | () => void                               | 否    | 点击弹窗中的“取消”按钮时触发该回调。                      |
| onChange                | (value: [TextPickerResult](../arkui-ts/ts-methods-textpicker-dialog.md#textpickerresult对象说明)) => void | 否    | 滑动弹窗中的选择器使当前选中项改变时触发该回调。                 |

**示例：**

```ts
{ class setvalue{
  select: number = 2
  set(val:number){
    this.select = val
  }
}
class setvaluearr{
  select: number[] = []
  set(val:number[]){
    this.select = val
  }
}
let fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4', 'banana5']
uiContext.showTextPickerDialog({
  range: this.fruits,
  selected: this.select,
  onAccept: (value: TextPickerResult) => {
    // 设置select为按下确定按钮时候的选中项index，这样当弹窗再次弹出时显示选中的是上一次确定的选项
    let setv = new setvalue()
    let setvarr = new setvaluearr()
    if(value.index){
      value.index instanceof Array?setvarr.set(value.index) : setv.set(value.index)
    }
    console.info("TextPickerDialog:onAccept()" + JSON.stringify(value))
  },
  onCancel: () => {
    console.info("TextPickerDialog:onCancel()")
  },
  onChange: (value: TextPickerResult) => {
    console.info("TextPickerDialog:onChange()" + JSON.stringify(value))
  }
})
```

### createAnimator

createAnimator(options: AnimatorOptions): AnimatorResult

定义Animator类。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [AnimatorOptions](./js-apis-animator.md#animatoroptions) | 是    | 定义动画选项。 |

**返回值：**

| 类型                                       | 说明            |
| ---------------------------------------- | ------------- |
| [AnimatorResult](./js-apis-animator.md#animatorresult) | Animator结果接口。 |

**示例：**

```ts
import { AnimatorOptions } from '@ohos.animator';
let options:AnimatorOptions = {
  duration: 1500,
  easing: "friction",
  delay: 0,
  fill: "forwards",
  direction: "normal",
  iterations: 3,
  begin: 200.0,
  end: 400.0
};
uiContext.createAnimator(options);
```

### runScopedTask

runScopedTask(callback: () => void): void

在当前UI上下文执行传入的回调函数。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型         | 必填   | 说明   |
| -------- | ---------- | ---- | ---- |
| callback | () => void | 是    | 回调函数 |

**示例：**

```ts
uiContext.runScopedTask(
  () => {
    console.log('Succeeded in runScopedTask');
  }
);
```

### setKeyboardAvoidMode<sup>11+</sup>

setKeyboardAvoidMode(value: KeyboardAvoidMode): void

配置虚拟键盘弹出时，页面的避让模式。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型         | 必填   | 说明   |
| -------- | ---------- | ---- | ---- |
| value | [KeyboardAvoidMode](../apis/js-apis-arkui-UIContext.md#keyboardavoidmode11)| 是    | 键盘避让时的页面避让模式。<br />默认值:KeyboardAvoidMode.OFFSET |

**示例：**

```ts
import { KeyboardAvoidMode, UIContext } from '@ohos.arkui.UIContext';
onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext :UIContext = windowStage.getMainWindowSync().getUIContext();
      uiContext.setKeyboardAvoidMode(KeyboardAvoidMode.RESIZE);
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
```

### getKeyboardAvoidMode<sup>11+</sup>

getKeyboardAvoidMode(): KeyboardAvoidMode

获取虚拟键盘弹出时，页面的避让模式。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型         | 说明   |
| ---------- | ---- |
| [KeyboardAvoidMode](../apis/js-apis-arkui-UIContext.md#keyboardavoidmode11)| 返回当前的页面避让模式。|

**示例：**

```ts
import { KeyboardAvoidMode, UIContext } from '@ohos.arkui.UIContext';
onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext :UIContext = windowStage.getMainWindowSync().getUIContext();
      let KeyboardAvoidMode = uiContext.getKeyboardAvoidMode();
      console.log("KeyboardAvoidMode:", JSON.stringify(KeyboardAvoidMode));
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

```

### getAtomicServiceBar<sup>11+</sup>

getAtomicServiceBar(): Nullable\<AtomicServiceBar>

获取AtomicServiceBar对象，通过该对象设置原子化服务menuBar的属性。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型|说明|
|----|----|
|Nullable<[AtomicServiceBar](#atomicservicebar)>| 如果是原子化服务则返回AtomicServerBar类型，否则返回undefined。|

**示例：**

```ts
import {UIContext, AtomicServiceBar} from '@ohos.arkui.UIContext';
import hilog from '@ohos.hilog';
import window from "@ohos.window";
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
    let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (atomicServiceBar != undefined) {
      hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
    } else {
      hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
    }
  });
}
```
### getDragController<sup>11+</sup>

getDragController(): DragController

获取DragController对象，可通过该对象创建并发起拖拽。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型|说明|
|----|----|
|[DragController](js-apis-arkui-dragController.md#dragController)| 获取DragController对象。|

**示例：**

```ts
uiContext.getDragController();
```

### dragPreview<sup>11+</sup>

dragPreview(value: CustomBuilder | DragItemInfo): void

设置组件拖拽过程中的预览图。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | ----- |
| value | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是    | 组件拖拽过程中的预览图。<br/>默认值：空<br/>|

**示例：**
请参考[dragPreview用法示例](../arkui-ts/ts-universal-attributes-drag-drop.md#示例2)

## Font

以下API需先使用UIContext中的[getFont()](#getfont)方法获取到Font对象，再通过该对象调用对应方法。

### registerFont

registerFont(options: font.FontOptions): void

在字体管理中注册自定义字体。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| options | [font.FontOptions](js-apis-font.md#fontoptions) | 是    | 注册的自定义字体信息。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let font:Font = uiContext.getFont();
font.registerFont({
  familyName: 'medium',
  familySrc: '/font/medium.ttf'
});
```
### getSystemFontList

getSystemFontList(): Array\<string> 

获取系统支持的字体名称列表。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 说明        |
| -------------- | --------- |
| Array\<string> | 系统的字体名列表。 |

**示例：** 

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let font:Font|undefined = uiContext.getFont();
if(font){
  font.getSystemFontList()
}
```

### getFontByName

getFontByName(fontName: string): font.FontInfo

根据传入的系统字体名称获取系统字体的相关信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型     | 必填   | 说明      |
| -------- | ------ | ---- | ------- |
| fontName | string | 是    | 系统的字体名。 |

**返回值：** 

| 类型                                   | 说明      |
| ------------------------------------ | ------- |
| [FontInfo](js-apis-font.md#fontinfo) | 字体的详细信息 |

**示例：** 

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let font:Font|undefined = uiContext.getFont();
if(font){
  font.getFontByName('Sans Italic')
}
```

## ComponentUtils

以下API需先使用UIContext中的[getComponentUtils()](#getcomponentutils)方法获取到ComponentUtils对象，再通过该对象调用对应方法。

### getRectangleById

getRectangleById(id: string): componentUtils.ComponentInfo

获取组件大小、位置、平移缩放旋转及仿射矩阵属性信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明        |
| ---- | ------ | ---- | --------- |
| id   | string | 是    | 组件唯一标识id。 |

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| [ComponentInfo](js-apis-arkui-componentUtils.md#componentinfo) | 组件大小、位置、平移缩放旋转及仿射矩阵属性信息。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let componentUtils:ComponentUtils = uiContext.getComponentUtils();
let modePosition = componentUtils.getRectangleById("onClick");
let localOffsetWidth = modePosition.size.width;
let localOffsetHeight = modePosition.size.height;
```

## UIInspector

以下API需先使用UIContext中的[getUIInspector()](#getuiinspector)方法获取到UIInspector对象，再通过该对象调用对应方法。

### createComponentObserver

createComponentObserver(id: string): inspector.ComponentObserver

注册组件布局和绘制完成回调通知。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明      |
| ---- | ------ | ---- | ------- |
| id   | string | 是    | 指定组件id。 |

**返回值：** 

| 类型                                       | 说明                        |
| ---------------------------------------- | ------------------------- |
| [ComponentObserver](js-apis-arkui-inspector.md#componentobserver) | 组件回调事件监听句柄，用于注册和取消注册监听回调。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let inspector:UIInspector = uiContext.getUIInspector();
let listener = inspector.createComponentObserver('COMPONENT_ID');
```

## UIObserver<sup>11+</sup>

以下API需先使用UIContext中的[getUIObserver()](#getuiobserver11)方法获取到UIObserver对象，再通过该对象调用对应方法。

### on('navDestinationUpdate')<sup>11+</sup>

on(type: 'navDestinationUpdate', callback: Callback\<NavDestinationInfo\>): void

监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\> | 是   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.on('navDestinationUpdate', (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

### off('navDestinationUpdate')<sup>11+</sup>

off(type: 'navDestinationUpdate', callback?: Callback\<NavDestinationInfo\>): void

取消监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\> | 否   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.off('navDestinationUpdate');
```

### on('navDestinationUpdate')<sup>11+</sup>

on(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback: Callback<NavDestinationInfo>): void

监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](../arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                   |
| callback | Callback\<[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\>        | 是   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.on('navDestinationUpdate', { navigationId: "testId" }, (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

### off('navDestinationUpdate')<sup>11+</sup>

off(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback?: Callback<NavDestinationInfo>): void

取消监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](../arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                   |
| callback | Callback\<[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\>        | 否   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.off('navDestinationUpdate', { navigationId: "testId" });
```

## MediaQuery

以下API需先使用UIContext中的[getMediaQuery()](#getmediaquery)方法获取到MediaQuery对象，再通过该对象调用对应方法。

### matchMediaSync

matchMediaSync(condition: string): mediaQuery.MediaQueryListener

设置媒体查询的查询条件，并返回对应的监听句柄。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型     | 必填   | 说明                                       |
| --------- | ------ | ---- | ---------------------------------------- |
| condition | string | 是    | 媒体事件的匹配条件，具体可参考[媒体查询语法规则](../../ui/arkts-layout-development-media-query.md#语法规则)。 |

**返回值：**

| 类型                 | 说明                     |
| ------------------ | ---------------------- |
| MediaQueryListener | 媒体事件监听句柄，用于注册和去注册监听回调。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let mediaquery: MediaQuery = uiContext.getMediaQuery();
let listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件
```

## Router

以下API需先使用UIContext中的[getRouter()](#getrouter)方法获取到Router对象，再通过该对象调用对应方法。

### pushUrl

pushUrl(options: router.RouterOptions): Promise&lt;void&gt;

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 跳转页面描述信息。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
try {
  router.pushUrl({
    url: 'pages/routerpage2',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      }
    }
  })
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`pushUrl failed, code is ${code}, message is ${message}`);
}
```

### pushUrl

pushUrl(options: router.RouterOptions, callback: AsyncCallback&lt;void&gt;): void

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
router.pushUrl({
  url: 'pages/routerpage2',
  params: {
    data1: 'message',
    data2: {
      data3: [123, 456, 789]
    }
  }
}, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`pushUrl failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('pushUrl success');
})
```

### pushUrl

pushUrl(options: router.RouterOptions, mode: router.RouterMode): Promise&lt;void&gt;

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明         |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 跳转页面描述信息。  |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
try {
  routerF.pushUrl({
    url: 'pages/routerpage2',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      }
    }
  }, rtm.Standard)
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`pushUrl failed, code is ${code}, message is ${message}`);
}
```

### pushUrl

pushUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback&lt;void&gt;): void

跳转到应用内的指定页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 跳转页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
routerF.pushUrl({
  url: 'pages/routerpage2',
  params: {
    data1: 'message',
    data2: {
      data3: [123, 456, 789]
    }
  }
}, rtm.Standard, (err) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`pushUrl failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('pushUrl success');
})
```

### replaceUrl

replaceUrl(options: router.RouterOptions): Promise&lt;void&gt;

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 替换页面描述信息。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
try {
  router.replaceUrl({
    url: 'pages/detail',
    params: {
      data1: 'message'
    }
  })
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`replaceUrl failed, code is ${code}, message is ${message}`);
}
```

### replaceUrl

replaceUrl(options: router.RouterOptions, callback: AsyncCallback&lt;void&gt;): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
router.replaceUrl({
  url: 'pages/detail',
  params: {
    data1: 'message'
  }
}, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`replaceUrl failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('replaceUrl success');
})
```

### replaceUrl

replaceUrl(options: router.RouterOptions, mode: router.RouterMode): Promise&lt;void&gt;

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明         |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 替换页面描述信息。  |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if can not get the delegate, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
try {
  routerF.replaceUrl({
    url: 'pages/detail',
    params: {
      data1: 'message'
    }
  }, rtm.Standard)
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`replaceUrl failed, code is ${code}, message is ${message}`);
}
```

### replaceUrl

replaceUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback&lt;void&gt;): void

用应用内的某个页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 替换页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector,  MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
routerF.replaceUrl({
  url: 'pages/detail',
  params: {
    data1: 'message'
  }
}, rtm.Standard, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`replaceUrl failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('replaceUrl success');
});
```

### pushNamedRoute

pushNamedRoute(options: router.NamedRouterOptions): Promise&lt;void&gt;

跳转到指定的命名路由页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 跳转页面描述信息。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
try {
  router.pushNamedRoute({
    name: 'myPage',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      }
    }
  })
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);
}
```

### pushNamedRoute

pushNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback&lt;void&gt;): void

跳转到指定的命名路由页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
router.pushNamedRoute({
  name: 'myPage',
  params: {
    data1: 'message',
    data2: {
      data3: [123, 456, 789]
    }
  }
}, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('pushNamedRoute success');
})
```
### pushNamedRoute

pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise&lt;void&gt;

跳转到指定的命名路由页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明         |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 跳转页面描述信息。  |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
try {
  routerF.pushNamedRoute({
    name: 'myPage',
    params: {
      data1: 'message',
      data2: {
        data3: [123, 456, 789]
      }
    }
  }, rtm.Standard)
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);
}
```

### pushNamedRoute

pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback&lt;void&gt;): void

跳转到指定的命名路由页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 跳转页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
routerF.pushNamedRoute({
  name: 'myPage',
  params: {
    data1: 'message',
    data2: {
      data3: [123, 456, 789]
    }
  }
}, rtm.Standard, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('pushNamedRoute success');
})
```

### replaceNamedRoute

replaceNamedRoute(options: router.NamedRouterOptions): Promise&lt;void&gt;

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 替换页面描述信息。 |

**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
try {
  router.replaceNamedRoute({
    name: 'myPage',
    params: {
      data1: 'message'
    }
  })
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`replaceNamedRoute failed, code is ${code}, message is ${message}`);
}
```

### replaceNamedRoute

replaceNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback&lt;void&gt;): void

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router:Router = uiContext.getRouter();
router.replaceNamedRoute({
  name: 'myPage',
  params: {
    data1: 'message'
  }
}, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`replaceNamedRoute failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('replaceNamedRoute success');
})
```

### replaceNamedRoute

replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise&lt;void&gt;

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明         |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 替换页面描述信息。  |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |


**返回值：**

| 类型                  | 说明      |
| ------------------- | ------- |
| Promise&lt;void&gt; | 异常返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if can not get the delegate, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
try {
  routerF.replaceNamedRoute({
    name: 'myPage',
    params: {
      data1: 'message'
    }
  }, rtm.Standard)
} catch (err) {
  let message = (err as BusinessError).message;
  let code = (err as BusinessError).code;
  console.error(`replaceNamedRoute failed, code is ${code}, message is ${message}`);
}
```

### replaceNamedRoute

replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback&lt;void&gt;): void

用指定的命名路由页面替换当前页面，并销毁被替换的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 替换页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class routerTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:routerTmp = new routerTmp()
routerF.replaceNamedRoute({
  name: 'myPage',
  params: {
    data1: 'message'
  }
}, rtm.Standard, (err: Error) => {
  if (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`replaceNamedRoute failed, code is ${code}, message is ${message}`);
    return;
  }
  console.info('replaceNamedRoute success');
});
```

### back

back(options?: router.RouterOptions ): void

返回上一页面或指定的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明                                       |
| ------- | ---------------------------------------- | ---- | ---------------------------------------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | 否    | 返回页面描述信息，其中参数url指路由跳转时会返回到指定url的界面，如果页面栈上没有url页面，则不响应该情况。如果url未设置，则返回上一页，页面不会重新构建，页面栈里面的page不会回收，出栈后会被回收。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.back({url:'pages/detail'});    
```

### clear

clear(): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.clear();    
```

### getLength

getLength(): string

获取当前在页面栈内的页面数量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| string | 页面数量，页面栈支持最大数值是32。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
let size = router.getLength();        
console.log('pages stack size = ' + size);    
```

### getState

getState(): router.RouterState

获取当前页面的状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [RouterState](js-apis-router.md#routerstate) | 页面状态信息。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
let page = router.getState();
console.log('current index = ' + page.index);
console.log('current name = ' + page.name);
console.log('current path = ' + page.path);
```

### showAlertBeforeBackPage

showAlertBeforeBackPage(options: router.EnableAlertOptions): void

开启页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.EnableAlertOptions](js-apis-router.md#enablealertoptions) | 是    | 文本弹窗信息描述。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.router(页面路由)](../errorcodes/errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
try {
  router.showAlertBeforeBackPage({            
    message: 'Message Info'        
  });
} catch(error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showAlertBeforeBackPage failed, code is ${code}, message is ${message}`);
}
```

### hideAlertBeforeBackPage

hideAlertBeforeBackPage(): void

禁用页面返回询问对话框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.hideAlertBeforeBackPage();    
```

### getParams

getParams(): Object

获取发起跳转的页面往当前页传入的参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                |
| ------ | ----------------- |
| object | 发起跳转的页面往当前页传入的参数。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.getParams();
```

## PromptAction

以下API需先使用UIContext中的[getPromptAction()](#getpromptaction)方法获取到PromptAction对象，再通过该对象调用对应方法。

### showToast

showToast(options: promptAction.ShowToastOptions): void

创建并显示文本提示框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [promptAction.ShowToastOptions](js-apis-promptAction.md#showtoastoptions) | 是    | 文本弹窗选项。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.promptAction(弹窗)](../errorcodes/errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let promptAction: PromptAction = uiContext.getPromptAction();
try {
  promptAction.showToast({            
    message: 'Message Info',
    duration: 2000 
  });
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showToast args error code is ${code}, message is ${message}`);
};
```

### showDialog

showDialog(options: promptAction.ShowDialogOptions, callback: AsyncCallback&lt;promptAction.ShowDialogSuccessResponse&gt;): void

创建并显示对话框，对话框响应结果异步返回。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明           |
| -------- | ---------------------------------------- | ---- | ------------ |
| options  | [promptAction.ShowDialogOptions](js-apis-promptAction.md#showdialogoptions) | 是    | 页面显示对话框信息描述。 |
| callback | AsyncCallback&lt;[promptAction.ShowDialogSuccessResponse](js-apis-promptAction.md#showdialogsuccessresponse)&gt; | 是    | 对话框响应结果回调。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.promptAction(弹窗)](../errorcodes/errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
class buttonsMoabl {
  text: string = ""
  color: string = ""
}
let promptAction: PromptAction = uiContext.getPromptAction();
try {
  promptAction.showDialog({
    title: 'showDialog Title Info',
    message: 'Message Info',
    buttons: [
      {
        text: 'button1',
        color: '#000000'
      } as buttonsMoabl,
      {
        text: 'button2',
        color: '#000000'
      } as buttonsMoabl
    ]
  }, (err, data) => {
    if (err) {
      console.info('showDialog err: ' + err);
      return;
    }
    console.info('showDialog success callback, click button: ' + data.index);
  });
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showDialog args error code is ${code}, message is ${message}`);
};
```

### showDialog

showDialog(options: promptAction.ShowDialogOptions): Promise&lt;promptAction.ShowDialogSuccessResponse&gt;

创建并显示对话框，对话框响应后同步返回结果。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明     |
| ------- | ---------------------------------------- | ---- | ------ |
| options | [promptAction.ShowDialogOptions](js-apis-promptAction.md#showdialogoptions) | 是    | 对话框选项。 |

**返回值：**

| 类型                                       | 说明       |
| ---------------------------------------- | -------- |
| Promise&lt;[promptAction.ShowDialogSuccessResponse](js-apis-promptAction.md#showdialogsuccessresponse)&gt; | 对话框响应结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.promptAction(弹窗)](../errorcodes/errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let promptAction: PromptAction = uiContext.getPromptAction();
try {
  promptAction.showDialog({
    title: 'Title Info',
    message: 'Message Info',
    buttons: [
      {
        text: 'button1',
        color: '#000000'
      },
      {
        text: 'button2',
        color: '#000000'
      }
    ],
  })
    .then(data => {
      console.info('showDialog success, click button: ' + data.index);
    })
    .catch((err:Error) => {
      console.info('showDialog error: ' + err);
    })
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showDialog args error code is ${code}, message is ${message}`);
};
```

### showActionMenu

showActionMenu(options: promptAction.ActionMenuOptions, callback: AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)&gt;):void

创建并显示操作菜单，菜单响应结果异步返回。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [promptAction.ActionMenuOptions](js-apis-promptAction.md#actionmenuoptions) | 是    | 操作菜单选项。   |
| callback | AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)&gt; | 是    | 菜单响应结果回调。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.promptAction(弹窗)](../errorcodes/errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**示例：**

```ts
import { PromptAction } from '@ohos.arkui.UIContext';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';

let promptActionF: PromptAction = uiContext.getPromptAction();
try {
  promptActionF.showActionMenu({
    title: 'Title Info',
    buttons: [
      {
        text: 'item1',
        color: '#666666'
      },
      {
        text: 'item2',
        color: '#000000'
      }
    ]
  }, (err:BusinessError, data:promptAction.ActionMenuSuccessResponse) => {
    if (err) {
      console.info('showDialog err: ' + err);
      return;
    }
    console.info('showDialog success callback, click button: ' + data.index);
  });
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```

### showActionMenu

showActionMenu(options: promptAction.ActionMenuOptions): Promise&lt;promptAction.ActionMenuSuccessResponse&gt;

创建并显示操作菜单，菜单响应后同步返回结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [promptAction.ActionMenuOptions](js-apis-promptAction.md#actionmenuoptions) | 是    | 操作菜单选项。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise&lt;[promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)&gt; | 菜单响应结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.promptAction(弹窗)](../errorcodes/errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let promptAction: PromptAction = uiContext.getPromptAction();
try {
  promptAction.showActionMenu({
    title: 'showActionMenu Title Info',
    buttons: [
      {
        text: 'item1',
        color: '#666666'
      },
      {
        text: 'item2',
        color: '#000000'
      },
    ]
  })
    .then(data => {
      console.info('showActionMenu success, click button: ' + data.index);
    })
    .catch((err:Error) => {
      console.info('showActionMenu error: ' + err);
    })
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```
## DragController<sup>11+</sup>
以下API需先使用UIContext中的[getDragController()](./js-apis-arkui-UIContext.md#getdragcontroller11)方法获取UIContext实例，再通过此实例调用对应方法。

### executeDrag

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo, callback: AsyncCallback&lt; {event: DragEvent, extraParams: string}&gt;): void

主动发起拖拽能力，传入拖拽发起后跟手效果所拖拽的对象以及携带拖拽信息。通过回调返回拖拽事件结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [DragInfo](js-apis-arkui-dragController.md#draginfo)                                        | 是   | 拖拽信息。                       |
| callback | [AsyncCallback](./js-apis-base.md#asynccallback)&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent说明), extraParams: string}&gt; | 是   | 拖拽结束返回结果的回调<br/>- event：拖拽事件信息，仅包括拖拽结果。<br/>- extraParams：拖拽事件额外信息。          |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Invalid input parameter |
| 100001   | Internal error |

**示例：**

```ts
import dragController from "@ohos.arkui.dragController"
import UDC from '@ohos.data.unifiedDataChannel';

@Entry
@Component
struct DragControllerPage {
  @Builder DraggingBuilder() {
    Column() {
      Text("DraggingBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  build() {
    Column() {
      Button('touch to execute drag')
        .onTouch((event?:TouchEvent) => {
          if(event){
            if (event.type == TouchType.Down) {
              let text = new UDC.Text()
              let unifiedData = new UDC.UnifiedData(text)

              let dragInfo: dragController.DragInfo = {
                pointerId: 0,
                data: unifiedData,
                extraParams: ''
              }
              class tmp{
                event:DragEvent|undefined = undefined
                extraParams:string = ''
              }
              let eve:tmp = new tmp()
              dragController.executeDrag(()=>{this.DraggingBuilder()}, dragInfo, (err, eve) => {
                if(eve.event){
                  if (eve.event.getResult() == DragResult.DRAG_SUCCESSFUL) {
                  // ...
                  } else if (eve.event.getResult() == DragResult.DRAG_FAILED) {
                  // ...
                  }
                }
              })
            }
          }
        })
    }
  }
}
```

### executeDrag

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo): Promise&lt;{event: DragEvent, extraParams: string}&gt;

主动发起拖拽能力，传入拖拽发起后跟手效果所拖拽的对象以及携带拖拽信息。通过Promise返回拖拽事件结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [DragInfo](js-apis-arkui-dragController.md#draginfo)                                        | 是   | 拖拽信息。                       |

**返回值：**

| 类型                                                   | 说明               |
| ------------------------------------------------------ | ------------------ |
| Promise&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent说明), extraParams: string}&gt; | 拖拽结束返回结果的回调<br/>- event：拖拽事件信息，仅包括拖拽结果。<br/>- extraParams：拖拽事件额外信息。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Invalid input parameter |
| 100001   | Internal error |

**示例：**

```ts
import dragController from "@ohos.arkui.dragController"
import componentSnapshot from '@ohos.arkui.componentSnapshot';
import image from '@ohos.multimedia.image';
import UDC from '@ohos.data.unifiedDataChannel';

@Entry
@Component
struct DragControllerPage {
  @State pixmap: image.PixelMap|null = null

  @Builder DraggingBuilder() {
    Column() {
      Text("DraggingBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  @Builder PixmapBuilder() {
    Column() {
      Text("PixmapBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  build() {
    Column() {
      Button('touch to execute drag')
        .onTouch((event?:TouchEvent) => {
          if(event){
            if (event.type == TouchType.Down) {
              let text = new UDC.Text()
              let unifiedData = new UDC.UnifiedData(text)

              let dragInfo: dragController.DragInfo = {
                pointerId: 0,
                data: unifiedData,
                extraParams: ''
              }
              let pb:CustomBuilder = ():void=>{this.PixmapBuilder()}
              componentSnapshot.createFromBuilder(pb).then((pix: image.PixelMap) => {
                this.pixmap = pix;
                let dragItemInfo: DragItemInfo = {
                  pixelMap: this.pixmap,
                  builder: ()=>{this.DraggingBuilder()},
                  extraInfo: "DragItemInfoTest"
                }

                class tmp{
                  event:DragResult|undefined = undefined
                  extraParams:string = ''
                }
                let eve:tmp = new tmp()
                dragController.executeDrag(dragItemInfo, dragInfo)
                  .then((eve) => {
                    if (eve.event.getResult() == DragResult.DRAG_SUCCESSFUL) {
                      // ...
                    } else if (eve.event.getResult() == DragResult.DRAG_FAILED) {
                      // ...
                    }
                  })
                  .catch((err:Error) => {
                  })
              })
            }
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### createDragAction

createDragAction(customArray: Array&lt;CustomBuilder \| DragItemInfo&gt;, dragInfo: DragInfo): DragAction

创建拖拽的Action对象，需要显式指定拖拽背板图(可多个)，以及拖拽的数据，跟手点等信息；当通过一个已创建的 Action 对象发起的拖拽未结束时，无法再次创建新的 Action 对象，接口会抛出异常。

**说明：** 建议控制传递的拖拽背板数量，传递过多容易导致拖起的效率问题。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| --------      | ------------------------------------------------------------ | ---- | -------------------------------- |
| customArray  | Array&lt;[CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明)&gt; | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [DragInfo](js-apis-arkui-dragController.md#dragInfo)                                        | 是   | 拖拽信息。                       |

**返回值：**

| 类型                                                   | 说明               |
| ------------------------------------------------------ | ------------------ |
| [DragAction](js-apis-arkui-dragController.md#dragaction11)| 创建拖拽Action对象，主要用于后面实现注册监听拖拽状态改变事件和启动拖拽服务。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Invalid input parameter |
| 100001   | Internal error |

**示例：**

```ts
import dragController from "@ohos.arkui.dragController"
import componentSnapshot from '@ohos.arkui.componentSnapshot';
import image from '@ohos.multimedia.image';
import UDC from '@ohos.data.unifiedDataChannel';

@Entry
@Component
struct DragControllerPage {
  @State pixmap: image.PixelMap|null = null
  private dragAction: dragController.DragAction|null = null;
  customBuilders:Array<CustomBuilder | DragItemInfo> = new Array<CustomBuilder | DragItemInfo>();
  @Builder DraggingBuilder() {
    Column() {
      Text("DraggingBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  build() {
    Column() {

      Column() {
        Text("测试")
      }
      .width(100)
      .height(100)
      .backgroundColor(Color.Red)

      Button('多对象dragAction customBuilder拖拽').onTouch((event?:TouchEvent) => {
        if(event){
          if (event.type == TouchType.Down) {
            console.log("muti drag Down by listener");
            this.customBuilders.push(()=>{this.DraggingBuilder()});
            this.customBuilders.push(()=>{this.DraggingBuilder()});
            this.customBuilders.push(()=>{this.DraggingBuilder()});
            let text = new UDC.Text()
            let unifiedData = new UDC.UnifiedData(text)
            let dragInfo: dragController.DragInfo = {
              pointerId: 0,
              data: unifiedData,
              extraParams: ''
            }
            this.dragAction = dragController.createDragAction(this.customBuilders, dragInfo)
            if(!this.dragAction){
              console.log("listener dragAction is null");
              return
            }
            this.dragAction.on('statusChange', (dragAndDropInfo)=>{
              if (dragAndDropInfo.status == dragController.DragStatus.STARTED) {
                console.log("drag has start");
              } else if (dragAndDropInfo.status == dragController.DragStatus.ENDED){
                console.log("drag has end");
                if (!this.dragAction) {
                  return
                }
                this.customBuilders.splice(0, this.customBuilders.length)
                this.dragAction.off('statusChange')
              }
            })
            this.dragAction.startDrag().then(()=>{}).catch((err:Error)=>{
              console.log("start drag Error:" + err.message);
            })
          }
        }
      }).margin({top:20})
    }
  }
}
```

## AtomicServiceBar<sup>11+</sup>

以下接口需要先使用UIContext中的getAtomicServiceBar方法获取到AtomicServiceBar对象，再通过该对象调用对应方法。

### setVisible<sup>11+</sup>

setVisible(visible: boolean): void

通过该方法设置原子化服务menuBar是否可见。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| visiable | boolean | 是 | 原子化服务menuBar是否可见。|


**示例：**

```ts
import { UIContext, AtomicServiceBar } from '@ohos.arkui.UIContext';
import hilog from '@ohos.hilog';
import window from "@ohos.window";
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
    let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (atomicServiceBar != undefined) {
      hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
      atomicServiceBar.setVisible(false);
    } else {
      hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
    }
  });
}
```

### setBackgroundColor<sup>11+</sup>

setBackgroundColor(color:Nullable<Color | number | string>): void

通过该方法设置原子化服务menuBar的背景颜色。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| color | color:Nullable\<[Color](../arkui-ts/ts-appendix-enums.md#color) \| number \| string> | 是 | 通过该方法设置原子化服务menuBar的背景颜色，undefined代表使用默认颜色。|

**示例：**

```ts
import { UIContext, AtomicServiceBar } from '@ohos.arkui.UIContext';
import hilog from '@ohos.hilog';
import window from "@ohos.window";
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
    let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (atomicServiceBar != undefined) {
      hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
      atomicServiceBar.setBackgroundColor(0x88888888);
    } else {
      hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
    }
  });
}
```

### setTitleContent<sup>11+</sup>

setTitleContent(content:string): void

通过该方法设置原子化服务menuBar的标题内容。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名|类型|必填|说明 |
| ------- | ------- | ------- | ------- |
| content | string | 是 | 原子化服务menuBar中的标题内容。|

**示例：**

```ts
import { UIContext, AtomicServiceBar } from '@ohos.arkui.UIContext';
import hilog from '@ohos.hilog';
import window from "@ohos.window";
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
    let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (atomicServiceBar != undefined) {
      hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
      atomicServiceBar.setTitleContent('text2');
    } else {
      hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
    }
  });
}
```

### setTitleFontStyle<sup>11+</sup>

setTitleFontStyle(font:FontStyle):void

通过该方法设置原子化服务menuBar的字体样式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| font | [FontStyle](../arkui-ts/ts-appendix-enums.md#fontstyle) | 是 | 原子化服务menuBar中的字体样式。 |

**示例：**

```ts
import { UIContext, Font, AtomicServiceBar } from '@ohos.arkui.UIContext';
import hilog from '@ohos.hilog';
import window from "@ohos.window";
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
    let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (atomicServiceBar != undefined) {
      hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
      atomicServiceBar.setTitleFontStyle(FontStyle.Normal);
    } else {
      hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
    }
  });
}
```

### setIconColor<sup>11+</sup>

setIconColor(color:Nullable<Color | number | string>): void

通过该方法设置原子化服务图标的颜色。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| color | Nullable\<[Color](../arkui-ts/ts-appendix-enums.md#color) \| number \| string> | 是 | 原子化服务图标的颜色，undefined代表使用默认颜色。 |


**示例：**

```ts
import { UIContext, AtomicServiceBar } from '@ohos.arkui.UIContext';
import hilog from '@ohos.hilog';
import window from "@ohos.window";
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
    let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (atomicServiceBar != undefined) {
      hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
      atomicServiceBar.setIconColor(0x12345678);
    } else {
      hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
    }
  });
}
```
## KeyboardAvoidMode<sup>11+</sup>

配置键盘避让时页面的避让模式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 说明       |
| ------ | ---------- |
| OFFSET | 上抬模式。 |
| RESIZE | 压缩模式。 |
