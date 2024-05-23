# @ohos.arkui.UIContext (UIContext)

在Stage模型中，WindowStage/Window可以通过[loadContent](js-apis-window.md#loadcontent9)接口加载页面并创建UI的实例，并将页面内容渲染到关联的窗口中，所以UI实例和窗口是一一关联的。一些全局的UI接口是和具体UI实例的执行上下文相关的，在当前接口调用时，通过追溯调用链跟踪到UI的上下文，来确定具体的UI实例。若在非UI页面中或者一些异步回调中调用这类接口，可能无法跟踪到当前UI的上下文，导致接口执行失败。

@ohos.window在API version 10 新增[getUIContext](js-apis-window.md#getuicontext10)接口，获取UI上下文实例UIContext对象，使用UIContext对象提供的替代方法，可以直接作用在对应的UI实例上。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 示例效果请以真机运行为准，当前IDE预览器不支持。

## UIContext

以下API需先使用ohos.window中的[getUIContext()](js-apis-window.md#getuicontext10)方法获取UIContext实例，再通过此实例调用对应方法。或者可以通过自定义组件内置方法[getUIContext()](arkui-ts/ts-custom-component-api.md#getuicontext)获取。本文中UIContext对象以uiContext表示。

### getFont

getFont(): Font

获取Font对象。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                            | 说明                  |
| ----------------------------- | ------------------- |
| [PromptAction](#promptaction) | 返回PromptAction实例对象。 |

**示例：**

```ts
uiContext.getPromptAction();
```

### getOverlayManager<sup>12+</sup>

getOverlayManager(): OverlayManager

获取OverlayManager对象。

**系统能力：**: SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                           | 说明                 |
| ----------------------------- | ------------------- |
| [OverlayManager](#overlaymanager12) | 返回OverlayManager实例对象。 |

**示例：**

```ts
uiContext.getOverlayManager();
```

### animateTo

animateTo(value: AnimateParam, event: () => void): void

提供animateTo接口来指定由于闭包代码导致的状态变化插入过渡动效。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                       | 必填   | 说明                                    |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](arkui-ts/ts-explicit-animation.md#animateparam对象说明) | 是    | 设置动画效果相关参数。                           |
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
### animateToImmediately<sup>12+</sup>

animateToImmediately(param: AnimateParam , event: () => void): void

animateToImmediately接口允许用户通过UIContext对象，获取显式立即动画的能力。同时加载多个属性动画的情况下，使用该接口可以立即执行闭包代码中状态变化导致的过渡动效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                       | 必填   | 说明                                    |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| param | [AnimateParam](arkui-ts/ts-explicit-animation.md#animateparam对象说明) | 是    | 设置动画效果相关参数。                           |
| event | () => void                               | 是    | 指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。 |

**示例：**

该示例实现了通过UIContext对象获取显式立即动画的能力，调用animateToImmediately接口实现参数定义的动画效果。

```ts
// xxx.ets
@Entry
@Component
struct AnimateToImmediatelyExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State opacitySize: number = 0
  private flag: boolean = true
  uiContext: UIContext | null | undefined = this.getUIContext();

  build() {
    Column() {
      Column()
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Green)
        .opacity(this.opacitySize)
      Button('change size')
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            this.uiContext?.animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.opacitySize = 1
            })
            this.uiContext?.animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            this.uiContext?.animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
            this.uiContext?.animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.opacitySize = 0
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```
![animateToImmediately](figures/animateToImmediately.gif) 

### getSharedLocalStorage<sup>12+</sup>

getSharedLocalStorage(): LocalStorage | undefined

获取当前stage共享的LocalStorage实例。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型                             | 描述                |
| ------------------------------ | ----------------- |
| [LocalStorage](arkui-ts/ts-state-management.md#localstorage9) | 返回LocalStorage实例。 |
| undefined | 共享的LocalStorage实例不存在时返回undefined。|

**示例：**

```ts
// index.ets
import router from '@ohos.router';

@Entry
@Component
struct SharedLocalStorage {
  localStorage = this.getUIContext().getSharedLocalStorage()

  build() {
    Row() {
      Column() {
        Button("Change Local Storage to 47")
          .onClick(() => {
            this.localStorage?.setOrCreate("propA",47)
          })
        Button("Get Local Storage")
          .onClick(() => {
            console.log(`localStorage: ${this.localStorage?.get("propA")}`)
          })
        Button("To Page")
          .onClick(() => {
            router.pushUrl({
              url: 'pages/GetSharedLocalStorage'
            })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}

// GetSharedLocalStorage.ets
import router from '@ohos.router';

@Entry
@Component
struct GetSharedLocalStorage {
  localStorage = this.getUIContext().getSharedLocalStorage()

  build() {
    Row() {
      Column() {
        Button("Change Local Storage to 100")
          .onClick(() => {
            this.localStorage?.setOrCreate("propA",100)
          })
        Button("Get Local Storage")
          .onClick(() => {
            console.log(`localStorage: ${this.localStorage?.get("propA")}`)
          })

        Button("Back Index")
          .onClick(() => {
            router.back()
          })
      }
      .width('100%')
    }
  }
}
```

### getHostContext<sup>12+</sup>

getHostContext(): Context | undefined

获得当前元能力的Context。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明                             |
| ------ | ------------------------------- |
| [Context](../../application-models/application-context-stage.md#应用上下文context)  | 返回当前组件所在Ability的Context，Context的具体类型为当前Ability关联的Context对象。例如：在UIAbility窗口中的页面调用该接口，返回类型为UIAbilityContext。在ExtensionAbility窗口中的页面调用该接口，返回类型为ExtensionContext。    |
| undefined | ability上下文不存在时返回undefined。|

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Index {
  uiContext = this.getUIContext();

  build() {
    Row() {
      Column() {
        Text("cacheDir="+this.uiContext?.getHostContext().cacheDir).fontSize(25)
        Text("bundleCodeDir="+this.uiContext?.getHostContext().bundleCodeDir).fontSize(25)
      }
      .width('100%')
    }
    .height('100%')
  }
}

```

### getFrameNodeById<sup>12+</sup>

getFrameNodeById(id: string): FrameNode | null

提供getFrameNodeById接口通过组件的id获取组件树的实体节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                       | 必填   | 说明                                    |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| id | string | 是    | 节点对应的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)                          |

**返回值：**

| 类型                                       | 说明            |
| ---------------------------------------- | ------------- |
| [FrameNode](js-apis-arkui-frameNode.md)  \| null | 返回的组件树的实体节点或者空节点。 |

**示例：**

```ts
uiContext.getFrameNodeById("TestNode")
```

### getFrameNodeByUniqueId<sup>12+</sup>

getFrameNodeByUniqueId(id: number): FrameNode | null

提供getFrameNodeByUniqueId接口通过组件的uniqueId获取组件树的实体节点。
1. 当uniqueId对应的是内置组件时，返回组件所对应的FrameNode；
2. 当uniqueId对应的是自定义组件时，若其有渲染内容，则返回其FrameNode，类型为__Common__；若其无渲染内容，则返回其第一个子组件的FrameNode。
3. 当uniqueId无对应的组件时，返回null。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                       | 必填   | 说明                                    |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| id | number | 是    | 节点对应的UniqueId                          |

**返回值：**

| 类型                                       | 说明            |
| ---------------------------------------- | ------------- |
| [FrameNode](js-apis-arkui-frameNode.md)  \| null | 返回的组件树的实体节点或者空节点。 |

**示例：**

```ts
import { UIContext } from '@ohos.arkui.UIContext';
import { FrameNode } from '@ohos.arkui.node';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let uniqueId: number = this.getUniqueId();
    let uiContext: UIContext = this.getUIContext();
    if (uiContext) {
      let node: FrameNode = uiContext.getFrameNodeByUniqueId(uniqueId);
    }
  }

  build() {
    // ...
  }
}
```

### showAlertDialog

showAlertDialog(options: AlertDialogParamWithConfirm | AlertDialogParamWithButtons | AlertDialogParamWithOptions): void

显示警告弹窗组件，可设置文本内容与响应回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明                  |
| ------- | ---------------------------------------- | ---- | ------------------- |
| options | [AlertDialogParamWithConfirm](arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithconfirm对象说明)&nbsp;\|&nbsp;[AlertDialogParamWithButtons](arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithbuttons对象说明)&nbsp;\|&nbsp;[AlertDialogParamWithOptions](arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithoptions10对象说明) | 是    | 定义并显示AlertDialog组件。 |


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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                 |
| ------ | ------------------------------------------------------------ | ---- | -------------------- |
| value  | [ActionSheetOptions](arkui-ts/ts-methods-action-sheet.md#actionsheetoptions对象说明) | 是   | 配置列表弹窗的参数。 |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                           |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| options | [DatePickerDialogOptions](arkui-ts/ts-methods-datepicker-dialog.md#datepickerdialogoptions对象说明) | 是   | 配置日期滑动选择器弹窗的参数。 |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                           |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| options | [TimePickerDialogOptions](arkui-ts/ts-methods-timepicker-dialog.md#timepickerdialogoptions对象说明) | 是   | 配置时间滑动选择器弹窗的参数。 |

**示例：**

```ts
// xxx.ets

class SelectTime{
  selectTime: Date = new Date('2020-12-25T08:30:00')
  hours(h:number,m:number){
    this.selectTime.setHours(h,m)
  }
}

@Entry
@Component
struct TimePickerDialogExample {
  @State selectTime: Date = new Date('2023-12-25T08:30:00');

  build() {
    Column() {
      Button('showTimePickerDialog')
        .margin(30)
        .onClick(() => {
          this.getUIContext().showTimePickerDialog({
            selected: this.selectTime,
            onAccept: (value: TimePickerResult) => {
              // 设置selectTime为按下确定按钮时的时间，这样当弹窗再次弹出时显示选中的为上一次确定的时间
              let time = new SelectTime()
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
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

### showTextPickerDialog

showTextPickerDialog(options: TextPickerDialogOptions): void

定义文本滑动选择器弹窗并弹出。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                           |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| options | [TextPickerDialogOptions](arkui-ts/ts-methods-textpicker-dialog.md#textpickerdialogoptions对象说明) | 是   | 配置文本滑动选择器弹窗的参数。 |

**示例：**

```ts
// xxx.ets

class SelectedValue{
  select: number = 2
  set(val:number){
    this.select = val
  }
}
class SelectedArray{
  select: number[] = []
  set(val:number[]){
    this.select = val
  }
}
@Entry
@Component
struct TextPickerDialogExample {
  @State selectTime: Date = new Date('2023-12-25T08:30:00');
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4', 'banana5']
  private select : number  = 0;
  build() {
    Column() {
      Button('showTextPickerDialog')
        .margin(30)
        .onClick(() => {
          this.getUIContext().showTextPickerDialog({
            range: this.fruits,
            selected: this.select,
            onAccept: (value: TextPickerResult) => {
              // 设置select为按下确定按钮时候的选中项index，这样当弹窗再次弹出时显示选中的是上一次确定的选项
              let selectedVal = new SelectedValue()
              let selectedArr = new SelectedArray()
              if(value.index){
                  value.index instanceof Array?selectedArr.set(value.index) : selectedVal.set(value.index)
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
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

### createAnimator

createAnimator(options: AnimatorOptions): AnimatorResult

定义Animator类。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [AnimatorOptions](js-apis-animator.md#animatoroptions) | 是    | 定义动画选项。 |

**返回值：**

| 类型                                       | 说明            |
| ---------------------------------------- | ------------- |
| [AnimatorResult](js-apis-animator.md#animatorresult) | Animator结果接口。 |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**示例：**

```ts
import { AnimatorOptions } from '@ohos.animator';
onWindowStageCreate(windowStage: window.WindowStage) {
  // Main window is created, set main page for this ability
  hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
  windowStage.loadContent('pages/Index', (err, data) => {
    if (err.code) {
      hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
      return;
    }
    hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    let uiContext = windowStage.getMainWindowSync().getUIContext();
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
  });
}
```

### runScopedTask

runScopedTask(callback: () => void): void

在当前UI上下文执行传入的回调函数。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型         | 必填   | 说明   |
| -------- | ---------- | ---- | ---- |
| value | [KeyboardAvoidMode](#keyboardavoidmode11)| 是    | 键盘避让时的页面避让模式。<br />默认值:KeyboardAvoidMode.OFFSET |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型         | 说明   |
| ---------- | ---- |
| [KeyboardAvoidMode](#keyboardavoidmode11)| 返回当前的页面避让模式。|

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                              | 说明                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| Nullable<[AtomicServiceBar](#atomicservicebar11)> | 如果是原子化服务则返回AtomicServerBar类型，否则返回undefined。 |

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

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型|说明|
|----|----|
|[DragController](js-apis-arkui-dragController.md#dragController)| 获取DragController对象。|

**示例：**

```ts
uiContext.getDragController();
```

### getDragPreview<sup>11+</sup>

getDragPreview(): dragController.DragPreview

返回一个代表拖拽背板的对象。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：** 

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [dragController.DragPreview](js-apis-arkui-dragController.md#dragpreview11) | 一个代表拖拽背板的对象，提供背板样式设置的接口，在OnDrop和OnDragEnd回调中使用不生效。 |

**错误码：** 通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

**示例：**

请参考[animate](js-apis-arkui-dragController.md#animate11)

### keyframeAnimateTo<sup>11+</sup>

keyframeAnimateTo(param: KeyframeAnimateParam, keyframes: Array&lt;KeyframeState&gt;): void

产生关键帧动画。该接口的使用说明请参考[keyframeAnimateTo](arkui-ts/ts-keyframeAnimateTo.md)。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                              | 必填 | 说明                      |
| ------------ | ---------------------------------------------------- | ------- | ---------------------------- |
| param        | [KeyframeAnimateParam](arkui-ts/ts-keyframeAnimateTo.md#keyframeanimateparam对象说明) | 是      | 关键帧动画的整体动画参数。     |
| keyframes    | Array&lt;[KeyframeState](arkui-ts/ts-keyframeAnimateTo.md#keyframestate对象说明)&gt;  | 是      | 所有的关键帧状态。            |

### getFocusController<sup>12+</sup>

getFocusController(): FocusController

获取[FocusController](js-apis-arkui-UIContext.md#focuscontroller12)对象，可通过该对象控制焦点。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型|说明|
|----|----|
|[FocusController](js-apis-arkui-UIContext.md#focuscontroller12)| 获取FocusController对象。|

**示例：**

```ts
uiContext.getFocusController();
```

### getFilteredInspectorTree<sup>12+</sup>

getFilteredInspectorTree(filters?: Array\<string\>): string

获取组件树及组件属性。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型            | 必填 | 说明                                                         |
| ------- | --------------- | ---- | ------------------------------------------------------------ |
| filters | Array\<string\> | 否   | 需要获取的组件属性的过滤列表。目前仅支持过滤字段："id", "src", "content", "editable", "scrollable", "selectable", "focusable", "forcused"，其余字段仅供测试场景使用。 |

**返回值：** 

| 类型   | 说明                               |
| ------ | ---------------------------------- |
| string | 获取组件树及组件属性的JSON字符串。 |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**示例：**

```ts
uiContext.getFilteredInspectorTree(['id', 'src', 'content']);
```

### getFilteredInspectorTreeById<sup>12+</sup>

getFilteredInspectorTreeById(id: string, depth: number, filters?: Array\<string\>): string

获取指定的组件及其子组件的属性。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型            | 必填 | 说明                                                         |
| ------- | --------------- | ---- | ------------------------------------------------------------ |
| id      | string          | 是   | 指定的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)id。 |
| depth   | number          | 是   | 获取子组件的层数。当取值0时，获取指定的组件及其所有的子孙组件的属性。当取值1时，仅获取指定的组件的属性。当取值2时，指定的组件及其1层子组件的属性。以此类推。 |
| filters | Array\<string\> | 否   | 需要获取的组件属性的过滤列表。目前仅支持过滤字段："id", "src", "content", "editable", "scrollable", "selectable", "focusable", "forcused"，其余字段仅供测试场景使用。 |

**返回值：** 

| 类型   | 说明                                         |
| ------ | -------------------------------------------- |
| string | 获取指定的组件及其子组件的属性的JSON字符串。 |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**示例：**

```ts
uiContext.getFilteredInspectorTreeById('testId', 0, ['id', 'src', 'content']);
```

### getCursorController<sup>12+</sup>

getCursorController(): CursorController

获取[CursorController](js-apis-arkui-UIContext.md#cursorcontroller12)对象，可通过该对象控制光标。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型|说明|
|----|----|
|[CursorController](js-apis-arkui-UIContext.md#cursorcontroller12)| 获取CursorController对象。|

**示例：**

```ts
uiContext.CursorController();
```

### getContextMenuController<sup>12+</sup>

getContextMenuController(): ContextMenuController

获取[ContextMenuController](js-apis-arkui-UIContext.md#contextmenucontroller12)对象，可通过该对象控制菜单。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型|说明|
|----|----|
|[ContextMenuController](js-apis-arkui-UIContext.md#contextmenucontroller12)| 获取ContextMenuController对象。|

**示例：**

```ts
uiContext.getContextMenuController();
```

### getMeasureUtils<sup>12+</sup>

getMeasureUtils(): MeasureUtils

允许用户通过UIContext对象，获取MeasureUtils对象进行文本计算。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：** 

| 类型   | 说明                                         |
| ------ | -------------------------------------------- |
| [MeasureUtils](js-apis-arkui-UIContext.md#measureutils12) | 提供文本宽度、高度等相关计算。 |

**示例：**

```ts
uiContext.getMeasureUtils();
```

### getComponentSnapshot<sup>12+</sup>

getComponentSnapshot(): ComponentSnapshot

获取ComponentSnapshot对象，可通过该对象获取组件截图的能力。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| [ComponentSnapshot](js-apis-arkui-UIContext.md#componentsnapshot12) | 获取ComponentSnapshot对象。 |

**示例：**

```ts
uiContext.getComponentSnapshot();
```

### vp2px<sup>12+</sup>

vp2px(value : number) : number

将vp单位的数值转换为以px为单位的数值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| value | number | 是   | 将vp单位的数值转换为以px为单位的数值。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 转换后的数值。 |

**示例：**

```tx
uiContext.vp2px(200);
```

### px2vp<sup>12+</sup>

px2vp(value : number) : number

将px单位的数值转换为以vp为单位的数值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| value | number | 是   | 将px单位的数值转换为以vp为单位的数值。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 转换后的数值。 |

**示例：**

```tx
uiContext.px2vp(200);
```

### fp2px<sup>12+</sup>

fp2px(value : number) : number

将fp单位的数值转换为以px为单位的数值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| value | number | 是   | 将fp单位的数值转换为以px为单位的数值。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 转换后的数值。 |

**示例：**

```tx
uiContext.fp2px(200);
```

### px2fp<sup>12+</sup>

px2fp(value : number) : number

将px单位的数值转换为以fp为单位的数值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| value | number | 是   | 将px单位的数值转换为以fp为单位的数值。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 转换后的数值。 |

**示例：**

```tx
uiContext.px2fp(200);
```

### lpx2px<sup>12+</sup>

lpx2px(value : number) : number

将lpx单位的数值转换为以px为单位的数值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                    |
| ------ | ------ | ---- | --------------------------------------- |
| value | number | 是   | 将lpx单位的数值转换为以px为单位的数值。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 转换后的数值。 |

**示例：**

```tx
uiContext.lpx2px(200);
```

### px2lpx<sup>12+</sup>

px2lpx(value : number) : number

将px单位的数值转换为以lpx为单位的数值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                    |
| ------ | ------ | ---- | --------------------------------------- |
| value | number | 是   | 将px单位的数值转换为以lpx为单位的数值。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 转换后的数值。 |

**示例：**

```tx
uiContext.px2lpx(200);
```

### getWindowName<sup>12+</sup>

getWindowName(): string | undefined

获取当前实例所在窗口的名称。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：** 

| 类型   | 说明                                         |
| ------ | -------------------------------------------- |
| string \| undefined | 当前实例所在窗口的名称。若窗口不存在，则返回undefined。 |

**示例：**

```ts
import window from '@ohos.window';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  aboutToAppear() {
    const windowName = this.getUIContext().getWindowName();
    console.error('WindowName ' + windowName);
    const currWindow = window.findWindow(windowName);
    const windowProperties = currWindow.getWindowProperties();
    console.error(`Window width ${windowProperties.windowRect.width}, height ${windowProperties.windowRect.height}`);
  }

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## Font

以下API需先使用UIContext中的[getFont()](#getfont)方法获取到Font对象，再通过该对象调用对应方法。

### registerFont

registerFont(options: font.FontOptions): void

在字体管理中注册自定义字体。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型     | 必填   | 说明      |
| -------- | ------ | ---- | ------- |
| fontName | string | 是    | 系统的字体名。 |

**返回值：** 

| 类型                                      | 说明           |
| ----------------------------------------- | -------------- |
| [font.FontInfo](js-apis-font.md#fontinfo) | 字体的详细信息 |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明      |
| ---- | ------ | ---- | ------- |
| id   | string | 是    | 指定组件id。 |

**返回值：** 

| 类型                                                         | 说明                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [inspector.ComponentObserver](js-apis-arkui-inspector.md#componentobserver) | 组件回调事件监听句柄，用于注册和取消注册监听回调。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let inspector:UIInspector = uiContext.getUIInspector();
let listener = inspector.createComponentObserver('COMPONENT_ID');
```

## UIObserver<sup>11+</sup>

以下API需先使用UIContext中的[getUIObserver()](#getuiobserver11)方法获取到UIObserver对象，再通过该对象调用对应方法。

### on('navDestinationUpdate')<sup>11+</sup>

on(type: 'navDestinationUpdate', callback: Callback\<observer.NavDestinationInfo\>): void

监听NavDestination组件的状态变化。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<observer.[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\> | 是   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.on('navDestinationUpdate', (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

### off('navDestinationUpdate')<sup>11+</sup>

off(type: 'navDestinationUpdate', callback?: Callback\<observer.NavDestinationInfo\>): void

取消监听NavDestination组件的状态变化。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<observer.[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\> | 否   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.off('navDestinationUpdate');
```

### on('navDestinationUpdate')<sup>11+</sup>

on(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback: Callback\<observer.NavDestinationInfo\>): void

监听NavDestination组件的状态变化。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                   |
| callback | Callback\<observer.[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\>        | 是   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.on('navDestinationUpdate', { navigationId: "testId" }, (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

### off('navDestinationUpdate')<sup>11+</sup>

off(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback?: Callback\<observer.NavDestinationInfo\>): void

取消监听NavDestination组件的状态变化。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                   |
| callback | Callback\<observer.[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo)\>        | 否   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
import { UIObserver } from '@ohos.arkui.UIContext';
let observer:UIObserver = uiContext.getUIObserver();
observer.off('navDestinationUpdate', { navigationId: "testId" });
```

### on('scrollEvent')<sup>12+</sup>

on(type: 'scrollEvent', callback: Callback\<observer.ScrollEventInfo\>): void

监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。      |
| callback | Callback\<observer.[ScrollEventInfo](js-apis-arkui-observer.md#scrolleventinfo12)\> | 是   | 回调函数。返回滚动事件的信息。   |

**示例：**

请参考[offscrollevent示例](#offscrollevent12-1)

### off('scrollEvent')<sup>12+</sup>

off(type: 'scrollEvent', callback?: Callback\<observer.ScrollEventInfo\>): void

取消监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。      |
| callback | Callback\<observer.[ScrollEventInfo](js-apis-arkui-observer.md#scrolleventinfo12)\> | 否   | 回调函数。返回滚动事件的信息。   |

**示例：**

请参考[offscrollevent示例](#offscrollevent12-1)

### on('scrollEvent')<sup>12+</sup>

on(type: 'scrollEvent', options: observer.ObserverOptions, callback: Callback\<observer.ScrollEventInfo\>): void

监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。 |
| options  | [observer.ObserverOptions](js-apis-arkui-observer.md#observeroptions12) | 是   | Observer选项，包含指定监听的滚动组件的id。                    |
| callback | Callback\<observer.[ScrollEventInfo](js-apis-arkui-observer.md#scrolleventinfo12)\>        | 是   | 回调函数。返回滚动事件的信息。                 |

**示例：**

请参考[offscrollevent示例](#offscrollevent12-1)

### off('scrollEvent')<sup>12+</sup>

off(type: 'scrollEvent', options: observer.ObserverOptions, callback?: Callback\<observer.ScrollEventInfo\>): void

取消监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。 |
| options  | [observer.ObserverOptions](js-apis-arkui-observer.md#observeroptions12) | 是   | Observer选项，包含指定监听的滚动组件的id。                    |
| callback | Callback\<observer.[ScrollEventInfo](js-apis-arkui-observer.md#scrolleventinfo12)\>        | 否   | 回调函数。返回滚动事件的信息。                 |

**示例：**

```ts
import uiContext, { UIObserver } from '@ohos.arkui.UIContext';

@Entry
@Component
struct Index {
  scroller: Scroller = new Scroller();
  observer: uiContext.UIObserver = new UIObserver();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7]

  build() {
    Row() {
      Column() {
        Scroll(this.scroller) {
          Column() {
            ForEach(this.arr, (item: number) => {
              Text(item.toString())
                .width('90%')
                .height(150)
                .backgroundColor(0xFFFFFF)
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
                .margin({ top: 10 })
            }, (item: string) => item)
          }.width('100%')
        }
        .id("testId")
        .height('80%')
      }
      .width('100%')

      Row() {
        Button('UIObserver on')
          .onClick(() => {
            this.observer.on('scrollEvent', (info) => {
              console.info('scrollEventInfo', JSON.stringify(info));
            });
          })
        Button('UIObserver off')
          .onClick(() => {
            this.observer.off('scrollEvent');
          })
      }

      Row() {
        Button('UIObserverWithId on')
          .onClick(() => {
            this.observer.on('scrollEvent', { id:"testId" }, (info) => {
              console.info('scrollEventInfo', JSON.stringify(info));
            });
          })
        Button('UIObserverWithId off')
          .onClick(() => {
            this.observer.off('scrollEvent', { id:"testId" });
          })
      }
    }
    .height('100%')
  }
}
```

### on('routerPageUpdate')<sup>11+</sup>

on(type: 'routerPageUpdate', callback: Callback\<observer.RouterPageInfo\>): void

监听router中page页面的状态变化。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'routerPageUpdate'，即router中page页面的状态变化。 |
| callback | Callback\<observer.[RouterPageInfo](js-apis-arkui-observer.md#routerpageinfo)\>        | 是   | 回调函数。携带pageInfo，返回当前的page页面状态。                 |

**示例：**

```ts
import {UIContext, UIObserver } from '@kit.ArkUI';

let observer:UIObserver = this.getUIContext().getUIObserver();
observer.on('routerPageUpdate', (info) => {
    console.info('RouterPage state updated, called by ' + `${info.name}`);
});
```

### off('routerPageUpdate')<sup>11+</sup>

off(type: 'routerPageUpdate', callback?: Callback\<observer.RouterPageInfo\>): void

取消监听router中page页面的状态变化。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'routerPageUpdate'，即router中page页面的状态变化。 |
| callback | Callback\<observer.[RouterPageInfo](js-apis-arkui-observer.md#routerpageinfo)\>        | 否   | 需要被注销的回调函数。                 |

**示例：**

```ts
import {UIContext, UIObserver } from '@kit.ArkUI';

let observer:UIObserver = this.getUIContext().getUIObserver();
function callBackFunc(info:observer.RouterPageInfo) {};
// callBackFunc is defined and used before
observer.off('routerPageUpdate', callBackFunc);
```

### on('densityUpdate')<sup>12+</sup>

on(type: 'densityUpdate', callback: Callback\<observer.DensityInfo\>): void

监听屏幕像素密度变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'densityUpdate'，即屏幕像素密度变化。 |
| callback | Callback\<observer.[DensityInfo](./js-apis-arkui-observer.md#densityinfo12)\>        | 是   | 回调函数。携带densityInfo，返回变化后的屏幕像素密度。                 |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  @State density: number = 0;
  @State message: string = '未注册监听'

  densityUpdateCallback = (info: observer.DensityInfo) => {
    this.density = info.density;
    this.message = '变化后的DPI：' + this.density.toString();
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      Button('注册屏幕像素密度变化监听')
        .onClick(() => {
          this.message = '已注册监听'
          this.getUIContext().getUIObserver().on('densityUpdate', this.densityUpdateCallback);
        })
    }
  }
}
```

### off('densityUpdate')<sup>12+</sup>

off(type: 'densityUpdate', callback?: Callback\<observer.DensityInfo\>): void

取消监听屏幕像素密度的变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                                 | 必填 | 说明                                                                                         |
| -------- | -------------------------------------------------------------------- | ---- | -------------------------------------------------------------------------------------------- |
| type     | string                                                               | 是   | 监听事件，固定为'densityUpdate'，即屏幕像素密度变化。                                        |
| callback | Callback\<observer.[DensityInfo](./js-apis-arkui-observer.md#densityinfo12)\> | 否   | 需要被注销的回调函数。若不指定具体的回调函数，则注销该UIContext下所有densityUpdate事件监听。 |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  @State density: number = 0;
  @State message: string = '未注册监听'

  densityUpdateCallback = (info: observer.DensityInfo) => {
    this.density = info.density;
    this.message = '变化后的DPI：' + this.density.toString();
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      Button('注册屏幕像素密度变化监听')
        .onClick(() => {
          this.message = '已注册监听'
          this.getUIContext().getUIObserver().on('densityUpdate', this.densityUpdateCallback);
        })
      Button('解除注册屏幕像素密度变化监听')
        .onClick(() => {
          this.message = '未注册监听'
          this.getUIContext().getUIObserver().off('densityUpdate', this.densityUpdateCallback);
        })
    }
  }
}
```

### observer.on('willDraw')<sup>12+</sup>

on(type: 'willDraw', callback: Callback\<void\>): void

监听每一帧绘制指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'willDraw'，即是否将要绘制。 |
| callback | Callback\<void\>        | 是   | 回调函数。                 |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  willDrawCallback = () => {
    console.log("willDraw指令下发");
  }
  build() {
    Column() {
      Button('注册绘制指令下发监听')
        .onClick(() => {
          this.getUIContext().getUIObserver().on('willDraw', this.willDrawCallback);
        })
    }
  }
}
```

### observer.off('willDraw')<sup>12+</sup>

off(type: 'willDraw', callback?: Callback\<void\>): void

取消监听每一帧绘制指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'willDraw'，即是否将要绘制。 |
| callback | Callback\<void\>        | 否   | 需要被注销的回调函数。                  |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  willDrawCallback = () => {
    console.log("willDraw指令下发")
  }

  build() {
    Column() {
      Button('注册绘制指令下发监听')
        .onClick(() => {
          this.getUIContext().getUIObserver().on('willDraw', this.willDrawCallback);
        })
      Button('解除注册绘制指令下发监听')
        .onClick(() => {
          this.getUIContext().getUIObserver().off('willDraw', this.willDrawCallback);
        })
    }
  }
}
```

### observer.on('didLayout')<sup>12+</sup>

on(type: 'didLayout', callback: Callback\<void\>): void

监听每一帧布局完成情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'didLayout'，即是否布局完成。 |
| callback | Callback\<void\>        | 是   | 回调函数。                 |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  didLayoutCallback = () => {
    console.log("layout布局完成");
  }
  build() {
    Column() {
      Button('注册布局完成监听')
        .onClick(() => {
          this.getUIContext().getUIObserver().on('didLayout', this.didLayoutCallback);
        })
    }
  }
}
```

### observer.off('didLayout')<sup>12+</sup>

off(type: 'didLayout', callback?: Callback\<void\>): void

取消监听每一帧布局完成情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'didLayout'，即是否将要绘制。 |
| callback | Callback\<void\>        | 否   | 需要被注销的回调函数。                  |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  didLayoutCallback = () => {
    console.log("layout布局完成")
  }

  build() {
    Column() {
      Button('注册布局完成监听')
        .onClick(() => {
          this.getUIContext().getUIObserver().on('didLayout', this.didLayoutCallback);
        })
      Button('解除注册注册布局完成监听')
        .onClick(() => {
          this.getUIContext().getUIObserver().off('didLayout', this.didLayoutCallback);
        })
    }
  }
}
```

### on('navDestinationSwitch')<sup>12+</sup>

on(type: 'navDestinationSwitch', callback: Callback\<observer.NavDestinationSwitchInfo\>): void

监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| callback | Callback\<observer.[NavDestinationSwitchInfo](js-apis-arkui-observer.md#navdestinationswitchinfo12)\>        | 是   | 回调函数。携带NavDestinationSwitchInfo，返回页面切换事件的信息。                 |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (info: observer.NavDestinationSwitchInfo) => {
    console.info(`navigation page switched, switchInfo: ${JSON.stringify(info)}`);
};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.on('navDestinationSwitch', callback);
```

### off('navDestinationSwitch')<sup>12+</sup>

off(type: 'navDestinationSwitch', callback?: Callback\<observer.NavDestinationSwitchInfo\>): void

取消监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| callback | Callback\<observer.[NavDestinationSwitchInfo](js-apis-arkui-observer.md#navdestinationswitchinfo12)\>        | 否   | 需要被注销的回调函数。                 |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (info: observer.NavDestinationSwitchInfo) => {
    console.info(`navigation page switched, switchInfo: ${JSON.stringify(info)}`);
};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.off('navDestinationSwitch', callback);
```

### on('navDestinationSwitch')<sup>12+</sup>

on(type: 'navDestinationSwitch', observerOptions: observer.NavDestinationSwitchObserverOptions, callback: Callback\<observer.NavDestinationSwitchInfo\>): void

监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| observerOptions | observer.[NavDestinationSwitchObserverOptions](js-apis-arkui-observer.md#navdestinationswitchobserveroptions12)        | 是   | 监听选项。   |
| callback | Callback\<observer.[NavDestinationSwitchInfo](js-apis-arkui-observer.md#navdestinationswitchinfo12)\>        | 是   | 回调函数。携带NavDestinationSwitchInfo，返回页面切换事件的信息。                 |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (info: observer.NavDestinationSwitchInfo) => {
    console.info(`navigation page switched, switchInfo: ${JSON.stringify(info)}`);
};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.on('navDestinationSwitch', { navigationId: "myNavId" }, callback);
```

### off('navDestinationSwitch')<sup>12+</sup>

off(type: 'navDestinationSwitch', observerOptions: observer.NavDestinationSwitchObserverOptions, callback?: Callback\<observer.NavDestinationSwitchInfo\>): void

取消监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| observerOptions | observer.[NavDestinationSwitchObserverOptions](js-apis-arkui-observer.md#navdestinationswitchobserveroptions12)        | 是   | 监听选项。   |
| callback | Callback\<observer.[NavDestinationSwitchInfo](js-apis-arkui-observer.md#navdestinationswitchinfo12)\>        | 否   | 需要被注销的回调函数。                 |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (info: observer.NavDestinationSwitchInfo) => {
    console.info(`navigation page switched, switchInfo: ${JSON.stringify(info)}`);
};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.off('navDestinationSwitch', { navigationId: "myNavId" }, callback);
```

### on('willClick')<sup>12+</sup>

on(type: 'willClick', callback: GestureEventListenerCallback): void

监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'willClick'，用于监听点击事件指令下发情况，所注册回调将于点击事件触发前触发。 |
| callback | [GestureEventListenerCallback](#gestureeventlistenercallback12) | 是   | 回调函数。可以获得点击事件的GestureEvent和组件的FrameNode。  |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: GestureEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.on('willClick', callback);
```

### off('willClick')<sup>12+</sup>

off(type: 'willClick', callback?: GestureEventListenerCallback): void

取消监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                  |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 监听事件，固定为'willClick'，即点击事件指令下发情况。 |
| callback | [GestureEventListenerCallback](#gestureeventlistenercallback12) | 否   | 需要被注销的回调函数。                                |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: GestureEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.off('willClick', callback);
```

### on('didClick')<sup>12+</sup>

on(type: 'didClick', callback: GestureEventListenerCallback): void

监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'didClick'，用于监听点击事件指令下发情况，所注册回调将于点击事件触发前触发。 |
| callback | [GestureEventListenerCallback](#gestureeventlistenercallback12) | 是   | 回调函数。可以获得点击事件的GestureEvent和组件的FrameNode。  |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: GestureEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.on('didClick', callback);
```

### off('didClick')<sup>12+</sup>

off(type: 'didClick', callback?: GestureEventListenerCallback): void

取消监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                 |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| type     | string                                                       | 是   | 监听事件，固定为'didClick'，即点击事件指令下发情况。 |
| callback | [GestureEventListenerCallback](#gestureeventlistenercallback12) | 否   | 需要被注销的回调函数。                               |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: GestureEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.off('didClick', callback);
```

### on('willClick')<sup>12+</sup>

on(type: 'willClick', callback: ClickEventListenerCallback): void

监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'willClick'，用于监听点击事件指令下发情况，所注册回调将于点击事件触发前触发。 |
| callback | [ClickEventListenerCallback](#clickeventlistenercallback12) | 是   | 回调函数。可以获得点击事件的ClickEvent和组件的FrameNode。    |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: ClickEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.on('willClick', callback);
```

### off('willClick')<sup>12+</sup>

off(type: 'willClick', callback?: ClickEventListenerCallback): void

取消监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                        | 必填 | 说明                                                  |
| -------- | ----------------------------------------------------------- | ---- | ----------------------------------------------------- |
| type     | string                                                      | 是   | 监听事件，固定为'willClick'，即点击事件指令下发情况。 |
| callback | [ClickEventListenerCallback](#clickeventlistenercallback12) | 否   | 需要被注销的回调函数。                                |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: ClickEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.off('willClick', callback);
```

### on('didClick')<sup>12+</sup>

on(type: 'didClick', callback: ClickEventListenerCallback): void

监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'didClick'，用于监听点击事件指令下发情况，所注册回调将于点击事件触发前触发。 |
| callback | [ClickEventListenerCallback](#clickeventlistenercallback12) | 是   | 回调函数。可以获得点击事件的ClickEvent和组件的FrameNode。    |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: ClickEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.on('didClick', callback);
```

### off('didClick')<sup>12+</sup>

off(type: 'didClick', callback?: ClickEventListenerCallback): void

取消监听点击事件指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                        | 必填 | 说明                                                 |
| -------- | ----------------------------------------------------------- | ---- | ---------------------------------------------------- |
| type     | string                                                      | 是   | 监听事件，固定为'didClick'，即点击事件指令下发情况。 |
| callback | [ClickEventListenerCallback](#clickeventlistenercallback12) | 否   | 需要被注销的回调函数。                               |

**示例：**

```ts
// 在页面Component中使用
import { UIContext, UIObserver } from '@ohos.arkui.UIContext';
// callback是开发者定义的监听回调函数
let callback = (event: ClickEvent, frameNode: FrameNode) => {};
let observer: UIObserver = this.getUIContext().getUIObserver();
observer.off('didClick', callback);
```

## GestureEventListenerCallback<sup>12+</sup>
type GestureEventListenerCallback = (event: GestureEvent, node?: FrameNode) => void

ArkTS GestureEvent事件监听函数类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| event | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-settings.md#gestureevent对象说明) | 是 | 触发事件监听的手势事件的相关信息。 |
| node | [FrameNode](js-apis-arkui-frameNode.md#framenode) | 否 | 触发事件监听的手势事件所绑定的组件。 |

## ClickEventListenerCallback<sup>12+</sup>
type ClickEventListenerCallback = (event: ClickEvent, node?: FrameNode) => void

ArkTS GestureEvent事件监听函数类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| event | [ClickEvent](../apis-arkui/arkui-ts/ts-universal-events-click.md#clickevent对象说明) | 是 | 触发事件监听的点击事件的相关信息。 |
| node | [FrameNode](js-apis-arkui-frameNode.md#framenode) | 否 | 触发事件监听的点击事件所绑定的组件。 |

## MediaQuery

以下API需先使用UIContext中的[getMediaQuery()](#getmediaquery)方法获取到MediaQuery对象，再通过该对象调用对应方法。

### matchMediaSync

matchMediaSync(condition: string): mediaQuery.MediaQueryListener

设置媒体查询的查询条件，并返回对应的监听句柄。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型     | 必填   | 说明                                       |
| --------- | ------ | ---- | ---------------------------------------- |
| condition | string | 是    | 媒体事件的匹配条件，具体可参考[媒体查询语法规则](../../ui/arkts-layout-development-media-query.md#语法规则)。 |

**返回值：**

| 类型                                                         | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| [mediaQuery.MediaQueryListener](js-apis-mediaquery.md#mediaquerylistener) | 媒体事件监听句柄，用于注册和去注册监听回调。 |

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

跳转到应用内的指定页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100002 | Uri error. The URI of the page to redirect is incorrect or does not exist.           |
| 100003 | Page stack error. Too many pages are pushed.  |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100002 | Uri error. The URI of the page to redirect is incorrect or does not exist.           |
| 100003 | Page stack error. Too many pages are pushed.  |

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

跳转到应用内的指定页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100002 | Uri error. The URI of the page to redirect is incorrect or does not exist.           |
| 100003 | Page stack error. Too many pages are pushed.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 跳转页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100002 | Uri error. The URI of the page to redirect is incorrect or does not exist.           |
| 100003 | Page stack error. Too many pages are pushed.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

用应用内的某个页面替换当前页面，并销毁被替换的页面，通过Promise获取跳转异常的返回的结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002 | Uri error. The URI of the page to be used for replacement is incorrect or does not exist.                 |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | The UI execution context is not found. This error code is thrown only in the standard system. |
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

用应用内的某个页面替换当前页面，并销毁被替换的页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | if can not get the delegate, only throw in standard system. |
| 200002 | Uri error. The URI of the page to be used for replacement is incorrect or does not exist.                 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | 是    | 替换页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | The UI execution context is not found. This error code is thrown only in the standard system. |
| 200002 | Uri error. The URI of the page to be used for replacement is incorrect or does not exist.               |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector,  MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

跳转到指定的命名路由页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100003 | Page stack error. Too many pages are pushed.  |
| 100004 | Named route error. The named route does not exist.   |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 跳转页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100003 | Page stack error. Too many pages are pushed.  |
| 100004 | Named route error. The named route does not exist.  |

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

跳转到指定的命名路由页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100003 | Page stack error. Too many pages are pushed.  |
| 100004 | Named route error. The named route does not exist.  |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 跳转页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |
| 100003 | Page stack error. Too many pages are pushed.  |
| 100004 | Named route error. The named route does not exist.   |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

用指定的命名路由页面替换当前页面，并销毁被替换的页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004 | Named route error. The named route does not exist.        |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 替换页面描述信息。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004 | Named route error. The named route does not exist.         |

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

用指定的命名路由页面替换当前页面，并销毁被替换的页面，通过Promise获取跳转异常的返回结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | if can not get the delegate, only throw in standard system. |
| 100004 | Named route error. The named route does not exist.       |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | 是    | 替换页面描述信息。  |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | 是    | 跳转页面使用的模式。 |
| callback | AsyncCallback&lt;void&gt;                | 是    | 异常响应回调。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | The UI execution context is not found. This error code is thrown only in the standard system. |
| 100004 | Named route error. The named route does not exist.        |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
import router from '@ohos.router';
let routerF:Router = uiContext.getRouter();
class RouterTmp{
  Standard:router.RouterMode = router.RouterMode.Standard
}
let rtm:RouterTmp = new RouterTmp()
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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

### back<sup>12+</sup>

back(index: number, params?: Object): void;

返回指定的页面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| index | number | 是    | 跳转目标页面的索引值。  |
| params    | Object      | 否    | 页面返回时携带的参数。 |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.back(1);
```

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.back(1, {info:'来自Home页'}); //携带参数返回
```

### clear

clear(): void

清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

### getStateByIndex<sup>12+</sup>

getStateByIndex(index: number): router.RouterState | undefined

通过索引值获取对应页面的状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| index    | number | 是   | 表示要获取的页面索引。  |

**返回值：**

| 类型                          | 说明      |
| --------------------------- | ------- |
| router.[RouterState](js-apis-router.md#outerstate) | 页面状态信息。 |
| undefined   | 索引不存在时返回undefined。|

**示例：** 

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
let options:router.RouterState = router.getStateByIndex(1);
console.log('index = ' + options.index);
console.log('name = ' + options.name);
console.log('path = ' + options.path);
console.log('params = ' + options.params);
```
### getStateByUrl<sup>12+</sup>

getStateByUrl(url: string): Array<router.[RouterState](js-apis-router.md#outerstate)>

通过url获取当前页面的状态信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明         |
| ------- | ------------------------------- | ---- | ---------- |
| url    | string | 是   | 表示要获取对应页面信息的url。  |

**返回值：**

| 类型                          | 说明      |
| --------------------------- | ------- |
| Array<router.[RouterState](js-apis-router.md#outerstate)> | 页面状态信息。 |

**示例：** 

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
let options:Array<router.RouterState> = router.getStateByUrl('pages/index');
for (let i: number = 0; i < options.length; i++) {
  console.log('index = ' + options[i].index);
  console.log('name = ' + options[i].name);
  console.log('path = ' + options[i].path);
  console.log('params = ' + options[i].params);
}
```

### showAlertBeforeBackPage

showAlertBeforeBackPage(options: router.EnableAlertOptions): void

开启页面返回询问对话框。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明        |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.EnableAlertOptions](js-apis-router.md#enablealertoptions) | 是    | 文本弹窗信息描述。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.router(页面路由)](errorcode-router.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [promptAction.ShowToastOptions](js-apis-promptAction.md#showtoastoptions) | 是    | 文本弹窗选项。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |

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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                       | 必填   | 说明           |
| -------- | ---------------------------------------- | ---- | ------------ |
| options  | [promptAction.ShowDialogOptions](js-apis-promptAction.md#showdialogoptions) | 是    | 页面显示对话框信息描述。 |
| callback | AsyncCallback&lt;[promptAction.ShowDialogSuccessResponse](js-apis-promptAction.md#showdialogsuccessresponse)&gt; | 是    | 对话框响应结果回调。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |

**示例：**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
class ButtonsModel {
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
      } as ButtonsModel,
      {
        text: 'button2',
        color: '#000000'
      } as ButtonsModel
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

创建并显示对话框，对话框响应后同步返回结果，通过Promise获取对话框响应结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[ 通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |

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

### showActionMenu<sup>11+</sup>

showActionMenu(options: promptAction.ActionMenuOptions, callback: AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)&gt;):void

创建并显示操作菜单，菜单响应结果异步返回。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| options  | [promptAction.ActionMenuOptions](js-apis-promptAction.md#actionmenuoptions) | 是   | 操作菜单选项。     |
| callback | AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)&gt; | 是   | 菜单响应结果回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID | 错误信息                           |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001   | Internal error. |

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

### showActionMenu<sup>(deprecated)</sup>

showActionMenu(options: promptAction.ActionMenuOptions, callback: [promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)):void

创建并显示操作菜单，菜单响应结果异步返回。

从API version11开始不再维护，建议使用[showActionMenu](#showactionmenu11)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| options  | [promptAction.ActionMenuOptions](js-apis-promptAction.md#actionmenuoptions) | 是   | 操作菜单选项。     |
| callback | [promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse) | 是   | 菜单响应结果回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |

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
  }, { index:0 });
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```

### showActionMenu

showActionMenu(options: promptAction.ActionMenuOptions): Promise&lt;promptAction.ActionMenuSuccessResponse&gt;

创建并显示操作菜单，通过Promise获取菜单响应结果。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 100001 | Internal error. |

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

### openCustomDialog<sup>12+</sup>

openCustomDialog\<T extends Object>(dialogContent: ComponentContent\<T>, options?: promptAction.BaseDialogOptions): Promise&lt;void&gt;

创建并弹出dialogContent对应的自定义弹窗，使用Promise异步回调。通过该接口弹出的弹窗内容样式完全按照dialogContent中设置的样式显示，即相当于customdialog设置customStyle为true时的显示效果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| dialogContent | [ComponentContent\<T>](./js-apis-arkui-ComponentContent.md) | 是 | 自定义弹窗中显示的组件内容。 |
| options | [promptAction.BaseDialogOptions](js-apis-promptAction.md#basedialogoptions11) | 否    |   弹窗样式。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
|   Promise&lt;void&gt;           |    异常返回Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 103301 | the ComponentContent is incorrect. |
| 103302 | Dialog content already exists.|

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import { ComponentContent } from "@ohos.arkui.node";

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({bottom: 36})
  }.backgroundColor('#FFF0F0F0')
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        Button("click me")
            .onClick(() => {
                let uiContext = this.getUIContext();
                let promptAction = uiContext.getPromptAction();
                let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
                try {
                  promptAction.openCustomDialog(contentNode);
                } catch (error) {
                  let message = (error as BusinessError).message;
                  let code = (error as BusinessError).code;
                  console.error(`OpenCustomDialog args error code is ${code}, message is ${message}`);
                };
            })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

### closeCustomDialog<sup>12+</sup>

closeCustomDialog\<T extends Object>(dialogContent: ComponentContent\<T>): Promise&lt;void&gt;

关闭已弹出的dialogContent对应的自定义弹窗，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| dialogContent | [ComponentContent\<T>](./js-apis-arkui-ComponentContent.md) | 是 | 自定义弹窗中显示的组件内容。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
|   Promise&lt;void&gt;           |    异常返回Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 103301 | the ComponentContent is incorrect. |
| 103303 | the ComponentContent cannot be found. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import { ComponentContent } from "@ohos.arkui.node";

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({bottom: 36})
  }.backgroundColor('#FFF0F0F0')
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        Button("click me")
            .onClick(() => {
                let uiContext = this.getUIContext();
                let promptAction = uiContext.getPromptAction();
                let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
                try {
                  promptAction.openCustomDialog(contentNode);
                } catch (error) {
                  let message = (error as BusinessError).message;
                  let code = (error as BusinessError).code;
                  console.error(`OpenCustomDialog args error code is ${code}, message is ${message}`);
                };

                setTimeout(() => {
                  try {
                    promptAction.closeCustomDialog(contentNode);
                  } catch (error) {
                    let message = (error as BusinessError).message;
                    let code = (error as BusinessError).code;
                    console.error(`closeCustomDialog args error code is ${code}, message is ${message}`);
                  };
                }, 2000);     //2秒后自动关闭
            })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

### updateCustomDialog<sup>12+</sup>

updateCustomDialog\<T extends Object>(dialogContent: ComponentContent\<T>, options: promptAction.BaseDialogOptions): Promise&lt;void&gt;

更新已弹出的dialogContent对应的自定义弹窗的样式，使用Promise异步回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| dialogContent | [ComponentContent\<T>](./js-apis-arkui-ComponentContent.md) | 是 | 自定义弹窗中显示的组件内容。 |
| options | [promptAction.BaseDialogOptions](js-apis-promptAction.md#basedialogoptions11) | 是    |   弹窗样式，目前仅支持更新alignment、offset、autoCancel、maskColor。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
|   Promise&lt;void&gt;           |    异常返回Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.promptAction(弹窗)](errorcode-promptAction.md)错误码。

| 错误码ID  | 错误信息                               |
| ------ | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 103301 | the ComponentContent is incorrect. |
| 103303 | the ComponentContent cannot be found. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import { ComponentContent } from "@ohos.arkui.node";

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({bottom: 36})
  }.backgroundColor('#FFF0F0F0')
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        Button("click me")
            .onClick(() => {
                let uiContext = this.getUIContext();
                let promptAction = uiContext.getPromptAction();
                let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
                try {
                  promptAction.openCustomDialog(contentNode);
                } catch (error) {
                  let message = (error as BusinessError).message;
                  let code = (error as BusinessError).code;
                  console.error(`OpenCustomDialog args error code is ${code}, message is ${message}`);
                };

                setTimeout(() => {
                  try {
                    promptAction.updateCustomDialog(contentNode, { alignment: DialogAlignment.CenterEnd });
                  } catch (error) {
                    let message = (error as BusinessError).message;
                    let code = (error as BusinessError).code;
                    console.error(`updateCustomDialog args error code is ${code}, message is ${message}`);
                  };
                }, 2000);   //2秒后自动更新弹窗位置
            })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

## DragController<sup>11+</sup>
以下API需先使用UIContext中的[getDragController()](js-apis-arkui-UIContext.md#getdragcontroller11)方法获取UIContext实例，再通过此实例调用对应方法。

### executeDrag<sup>11+</sup>

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: dragController.DragInfo, callback: AsyncCallback&lt; {event: DragEvent, extraParams: string}&gt;): void

主动发起拖拽能力，传入拖拽发起后跟手效果所拖拽的对象以及携带拖拽信息。通过回调返回拖拽事件结果。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是   | 拖拽发起后跟手效果所拖拽的对象。 <br/> **说明：** <br/>不支持全局builder。如果builder中使用了[Image](arkui-ts/ts-basic-components-image.md)组件，应尽量开启同步加载，即配置Image的[syncLoad](arkui-ts/ts-basic-components-image.md#属性)为true。该builder只用于生成当次拖拽中显示的图片，builder的修改不会同步到当前正在拖拽的图片，对builder的修改需要在下一次拖拽时生效。 |
| dragInfo | [dragController.DragInfo](js-apis-arkui-dragController.md#draginfo)                                        | 是   | 拖拽信息。                       |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;{event: [DragEvent](arkui-ts/ts-universal-events-drag-drop.md#dragevent说明), extraParams: string}&gt; | 是   | 拖拽结束返回结果的回调<br/>- event：拖拽事件信息，仅包括拖拽结果。<br/>- extraParams：拖拽事件额外信息。          |

**错误码：**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)错误码。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed. |
| 100001   | Internal handling failed. |

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

### executeDrag<sup>11+</sup>

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: dragController.DragInfo): Promise&lt;{event: DragEvent, extraParams: string}&gt;

主动发起拖拽能力，传入拖拽发起后跟手效果所拖拽的对象以及携带拖拽信息。通过Promise返回拖拽事件结果。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [dragController.DragInfo](js-apis-arkui-dragController.md#draginfo)                                        | 是   | 拖拽信息。                       |

**返回值：**

| 类型                                                   | 说明               |
| ------------------------------------------------------ | ------------------ |
| Promise&lt;{event: [DragEvent](arkui-ts/ts-universal-events-drag-drop.md#dragevent说明), extraParams: string}&gt; | 拖拽结束返回结果的回调<br/>- event：拖拽事件信息，仅包括拖拽结果。<br/>- extraParams：拖拽事件额外信息。 |

**错误码：**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)错误码。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed. |
| 100001   | Internal handling failed. |

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

### createDragAction<sup>11+</sup>

createDragAction(customArray: Array&lt;CustomBuilder \| DragItemInfo&gt;, dragInfo: dragController.DragInfo): dragController.DragAction

创建拖拽的Action对象，需要显式指定拖拽背板图(可多个)，以及拖拽的数据，跟手点等信息；当通过一个已创建的 Action 对象发起的拖拽未结束时，无法再次创建新的 Action 对象，接口会抛出异常。

**说明：** 建议控制传递的拖拽背板数量，传递过多容易导致拖起的效率问题。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| --------      | ------------------------------------------------------------ | ---- | -------------------------------- |
| customArray  | Array&lt;[CustomBuilder](arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明)&gt; | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [dragController.DragInfo](js-apis-arkui-dragController.md#draginfo)                                | 是   | 拖拽信息。                       |

**返回值：**

| 类型                                                   | 说明               |
| ------------------------------------------------------ | ------------------ |
| [dragController.DragAction](js-apis-arkui-dragController.md#dragaction11)| 创建拖拽Action对象，主要用于后面实现注册监听拖拽状态改变事件和启动拖拽服务。 |

**错误码：**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)错误码。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed. |
| 100001   | Internal handling failed. |

**示例：**
1.在EntryAbility.ets中获取UI上下文并保存至LocalStorage中。
```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import { UIContext } from '@ohos.arkui.UIContext';

let uiContext: UIContext;
let localStorage: LocalStorage = new LocalStorage('uiContext');

export default class EntryAbility extends UIAbility {
  storage: LocalStorage = localStorage;
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    let storage: LocalStorage = new LocalStorage();
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', storage, (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
      windowStage.getMainWindow((err, data) =>
      {
        if (err.code) {
          console.log('Failed to abtain the main window. Cause:' + err.message);
          return;
        }
        let windowClass: window.Window = data;
        uiContext = windowClass.getUIContext();
        this.storage.setOrCreate<UIContext>('uiContext', uiContext);
        // 获取UIContext实例
      })
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```
2.通过LocalStorage.getShared()获取上下文，进而获取DragController对象实施后续操作。
```ts
import dragController from "@ohos.arkui.dragController"
import componentSnapshot from '@ohos.arkui.componentSnapshot';
import image from '@ohos.multimedia.image';
import UDC from '@ohos.data.unifiedDataChannel';
import { UIContext, DragController } from '@ohos.arkui.UIContext'

let storages = LocalStorage.getShared();

@Entry(storages)
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
            try{
              let uiContext: UIContext = storages.get<UIContext>('uiContext') as UIContext;
              this.dragAction = uiContext.getDragController().createDragAction(this.customBuilders, dragInfo)
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
            } catch(err) {
              console.log("create dragAction Error:" + err.message);
            }
          }
        }
      }).margin({top:20})
    }
  }
}
```

## OverlayManager<sup>12+</sup>

以下API需先使用UIContext中的[getOverlayManager()](#getoverlaymanager12)方法获取到OverlayManager对象，再通过该对象调用对应方法。
> **说明：**
>
> OverlayManager上节点的层级在Page页面层级之上，在Dialog、Popup、Menu、BindSheet、BindContentCover和Toast等之下。
>
> OverlayManager上节点安全区域内外的绘制方式与Page一致，键盘避让方式与Page一致。
>
> 与OverlayManager相关的属性推荐采用AppStorage来进行应用全局存储，以免切换页面后属性值发生变化从而导致业务错误。

### addComponentContent<sup>12+</sup>

addComponentContent(content: ComponentContent, index?: number): void

在OverlayManager上新增指定节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上新增指定节点上添加此content。 <br>**说明：** <br/> 新增的节点默认处于页面居中，按层级堆叠。|
| index | number | 否    | 新增节点在OverlayManager上的层级位置。<br>**说明：** <br/> 当index ≥ 0时，若index的值越大，则ComponentContent的层级越高；当多个ComponentContent的index相同时，若ComponentContent添加的时间越晚，则层级越高。<br/> 当index < 0、index = null或index = undefined时，ComponentContent默认添加至最高层。<br/>当同一个ComponentContent被添加多次时，只保留最后一次添加的ComponentContent。<br/>

**示例：**

```ts
import { OverlayManager } from '@ohos.arkui.UIContext';
import { ComponentContent } from '@ohos.arkui.node';
import router from '@ohos.router';

class Params {
  text: string = ""
  offset: Position
  constructor(text: string, offset: Position) {
    this.text = text
    this.offset = offset
  }
}
@Builder
function builderText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }.offset(params.offset)
}

@Entry
@Component
struct OverlayExample {
  @State message: string = 'ComponentContent';
  private uiContext: UIContext = this.getUIContext()
  private overlayNode: OverlayManager = this.uiContext.getOverlayManager()
  @StorageLink('contentArray') contentArray: ComponentContent<Params>[] = []
  @StorageLink('componentContentIndex') componentContentIndex: number = 0
  @StorageLink('arrayIndex') arrayIndex: number = 0
  @StorageLink("componentOffset") componentOffset: Position = {x: 0, y: 80}

  build() {
    Column() {
      Button("++componentContentIndex: " + this.componentContentIndex).onClick(()=>{
        ++this.componentContentIndex
      })
      Button("--componentContentIndex: " + this.componentContentIndex).onClick(()=>{
        --this.componentContentIndex
      })
      Button("增加ComponentContent" + this.contentArray.length).onClick(()=>{
        let componentContent = new ComponentContent(
          this.uiContext, wrapBuilder<[Params]>(builderText),
          new Params(this.message + (this.contentArray.length), this.componentOffset)
        )
        this.contentArray.push(componentContent)
        this.overlayNode.addComponentContent(componentContent, this.componentContentIndex)
      })
      Button("++arrayIndex: " + this.arrayIndex).onClick(()=>{
        ++this.arrayIndex
      })
      Button("--arrayIndex: " + this.arrayIndex).onClick(()=>{
        --this.arrayIndex
      })
      Button("删除ComponentContent" + this.arrayIndex).onClick(()=>{
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray.splice(this.arrayIndex, 1)
          this.overlayNode.removeComponentContent(componentContent.pop())
        } else {
          console.log("arrayIndex有误")
        }
      })
      Button("显示ComponentContent" + this.arrayIndex).onClick(()=>{
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex]
          this.overlayNode.showComponentContent(componentContent)
        } else {
          console.log("arrayIndex有误")
        }
      })
      Button("隐藏ComponentContent" + this.arrayIndex).onClick(()=>{
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex]
          this.overlayNode.hideComponentContent(componentContent)
        } else {
          console.log("arrayIndex有误")
        }
      })
      Button("显示所有ComponentContent").onClick(()=>{
          this.overlayNode.showAllComponentContents()
      })
      Button("隐藏所有ComponentContent").onClick(()=>{
        this.overlayNode.hideAllComponentContents()
      })

      Button("跳转页面").onClick(()=>{
        router.pushUrl({
          url: 'pages/Second'
        })
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

### removeComponentContent<sup>12+</sup>

removeComponentContent(content: ComponentContent): void

在overlay上删除指定节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上删除此content。 |

**示例：**

请参考[addComponentContent示例](#addcomponentcontent12)

### showComponentContent<sup>12+</sup>

showComponentContent(content: ComponentContent): void

在OverlayManager上显示指定节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上显示此content。|

**示例：**

请参考[addComponentContent示例](#addcomponentcontent12)

### hideComponentContent<sup>12+</sup>

hideComponentContent(content: ComponentContent): void

在OverlayManager上显示指定节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明          |
| ------- | ---------------------------------------- | ---- | ----------- |
| content | [ComponentContent](js-apis-arkui-ComponentContent.md) | 是    | 在OverlayManager上隐藏此content。 |

**示例：**

请参考[addComponentContent示例](#addcomponentcontent12)

### showAllComponentContents<sup>12+</sup>

showAllComponentContents(): void

显示OverlayManager上所有的ComponentContent。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

请参考[addComponentContent示例](#addcomponentcontent12)

### hideAllComponentContents<sup>12+</sup>

hideAllComponentContents(): void

隐藏OverlayManager上的所有ComponentContent。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

请参考[addComponentContent示例](#addcomponentcontent12)


### setDragEventStrictReportingEnabled<sup>12+</sup>

setDragEventStrictReportingEnabled(enable: boolean): void

当目标从父组件拖拽到子组件时，通过该方法设置是否会触发父组件的onDragLeave的回调。

**系统能力：** : SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名|类型|必填|说明|
| ------- | ------- | ------- | ------- |
| enable | boolean | 是| 将目标从父组件拖拽到子组件时，是否会触发父组件的onDragLeave的回调。|

**示例：**
```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { UIContext } from '@ohos.arkui.UIContext';
 export default class EntryAbility extends UIAbility {
   onWindowStageCreate(windowStage: window.WindowStage): void {
       windowStage.loadContent('pages/Index', (err, data) => {
         if (err.code) {
         return;
       }
       windowStage.getMainWindow((err, data) => {
         if (err.code) {
           return;
         }
         let windowClass: window.Window = data;
         let uiContext: UIContext = windowClass.getUIContext();
         uiContext.getDragController().setDragEventStrictReportingEnabled(true);
     });
   });
 }
}
```

## AtomicServiceBar<sup>11+</sup>

以下接口需要先使用UIContext中的[getAtomicServiceBar](#getatomicservicebar11)方法获取到AtomicServiceBar对象，再通过该对象调用对应方法。
> **说明：**
>
> 从API version 12开始原子化服务menuBar样式变更，以下接口将失效。

### setVisible<sup>11+</sup>

setVisible(visible: boolean): void

通过该方法设置原子化服务menuBar是否可见。
> **说明：**
>
> 从API version 12开始原子化服务menuBar样式变更，menuBar默认隐藏，变为悬浮按钮，通过该接口无法改变menuBar的可见性。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| visible | boolean | 是 | 原子化服务menuBar是否可见。|


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
> **说明：**
>
> 从API version 12开始原子化服务menuBar样式变更，menuBar的背景默认隐藏，通过该接口无法改变menuBar的背景颜色。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| color | color:Nullable\<[Color](arkui-ts/ts-appendix-enums.md#color) \| number \| string> | 是 | 通过该方法设置原子化服务menuBar的背景颜色，undefined代表使用默认颜色。|

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
> **说明：**
>
> 从API version 12开始原子化服务menuBar样式变更，menuBar的标题默认隐藏，通过该接口无法改变menuBar的标题内容。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

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
> **说明：**
>
> 从API version 12开始原子化服务menuBar样式变更，menuBar的标题默认隐藏，通过该接口无法改变menuBar的字体样式。

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| font | [FontStyle](arkui-ts/ts-appendix-enums.md#fontstyle) | 是 | 原子化服务menuBar中的字体样式。 |

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
> **说明：**
>
> 从API version 12开始原子化服务menuBar样式变更，menuBar默认隐藏，悬浮按钮图标不予用户设置，通过该接口无法改变menuBar的图标颜色。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| color | Nullable\<[Color](arkui-ts/ts-appendix-enums.md#color) \| number \| string> | 是 | 原子化服务图标的颜色，undefined代表使用默认颜色。 |


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

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 说明       |
| ------ | ---------- |
| OFFSET | 上抬模式。 |
| RESIZE | 压缩模式。 |


## FocusController<sup>12+</sup>
以下API需先使用UIContext中的[getFocusController()](js-apis-arkui-UIContext.md#getFocusController12)方法获取UIContext实例，再通过此实例调用对应方法。

### clearFocus<sup>12+</sup>

clearFocus(): void

清除焦点，将焦点强制转移到页面根容器节点，焦点链路上其他节点失焦。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
@Entry
@Component
struct ClearFocusExample {
  @State inputValue: string = ''
  @State btColor: Color = Color.Blue

  build() {
    Column({ space: 20 }) {
      Column({ space: 5 }) {
        Button('button1')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(Color.Blue)
        Button('button2')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor)
          .defaultFocus(true)
          .onFocus(() => {
            this.btColor = Color.Red
          })
          .onBlur(() => {
            this.btColor = Color.Blue
          })
        Button('clearFocus')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .backgroundColor(Color.Blue)
          .onClick(() => {
            this.getUIContext().getFocusController().clearFocus()
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

### requestFocus<sup>12+</sup>

requestFocus(key: string): void

通过组件的id将焦点转移到组件树对应的实体节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| key | string | 是 | 节点对应的[组件标识](arkui-ts/ts-universal-attributes-component-id.md)。|

**错误码：**

以下错误码的详细介绍请参见[焦点错误码](errorcode-focus.md)。

| 错误码ID  | 错误信息                                     |
| ------ | ---------------------------------------- |
| 150001 | This component is not focusable. |
| 150002 | This component has an unfocusable ancestor.      |
| 150003 | The component doesn't exist, is currently invisible, or has been disabled. |

**示例：**

```ts
@Entry
@Component
struct RequestExample {
  @State btColor: Color = Color.Blue

  build() {
    Column({ space: 20 }) {
      Column({ space: 5 }) {
        Button('Button')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor)
          .onFocus(() => {
            this.btColor = Color.Red
          })
          .onBlur(() => {
            this.btColor = Color.Blue
          })
          .id("testButton")

        Divider()
          .vertical(false)
          .width("80%")
          .backgroundColor(Color.Black)
          .height(10)

        Button('requestFocus')
          .width(200)
          .height(70)
          .onClick(() => {
            this.getUIContext().getFocusController().requestFocus("testButton")
          })

        Button('requestFocus fail')
          .width(200)
          .height(70)
          .onClick(() => {
            try {
              this.getUIContext().getFocusController().requestFocus("eee")
            } catch (error) {
              console.error('requestFocus failed code is ' + error.code + ' message is ' + error.message)
            }
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

## CursorController<sup>12+</sup>
以下API需先使用UIContext中的[getCursorController()](js-apis-arkui-UIContext.md#getcursorcontroller12)方法获取CursorController实例，再通过此实例调用对应方法。

### restoreDefault<sup>12+</sup>

restoreDefault(): void

恢复默认的光标样式

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**
当光标移出绿框时，通过CursorController的restoreDefault方法恢复默认光标样式

```ts
import pointer from '@ohos.multimodalInput.pointer';
import uiContext, { CursorController } from '@ohos.arkui.UIContext';

@Entry
@Component
struct CursorControlExample {
  @State text: string = ''
  cursorCustom: CursorController = this.getUIContext().getCursorController();

  build() {
    Column() {
      Row().height(200).width(200).backgroundColor(Color.Green).position({x: 150 ,y:70})
        .onHover((flag) => {
          if (flag) {
            this.cursorCustom.setCursor(pointer.PointerStyle.EAST)
          } else {
            console.log("restoreDefault");
            this.cursorCustom.restoreDefault();
          }
        })
    }.width('100%')
  }
}
```
![cursor-restoreDefault](figures/cursor-restoreDefault.gif)

### setCursor<sup>12+</sup>

setCursor(value: PointerStyle): void

更改当前的鼠标光标样式

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                       | 必填   | 说明      |
| ------- | ---------------------------------------- | ---- | ------- |
| value | [PointerStyle](../../reference/apis-input-kit/js-apis-pointer.md#pointerstyle) | 是    | 光标样式 |

**示例：**
当光标进入蓝框时，通过CursorController的setCursor方法修改光标样式为PointerStyle.WEST

```ts
import pointer from '@ohos.multimodalInput.pointer';
import uiContext, { CursorController } from '@ohos.arkui.UIContext';

@Entry
@Component
struct CursorControlExample {
  @State text: string = ''
  cursorCustom: CursorController = this.getUIContext().getCursorController();

  build() {
    Column() {
      Row().height(200).width(200).backgroundColor(Color.Blue).position({x: 100 ,y:70})
        .onHover((flag) => {
          if (flag) {
            this.cursorCustom.setCursor(pointer.PointerStyle.WEST)
          } else {
            this.cursorCustom.restoreDefault();
          }
        })
    }.width('100%')
  }
}
```
![cursor-setCursor](figures/cursor-setCursor.gif)

## ContextMenuController<sup>12+</sup>
以下API需先使用UIContext中的[getContextMenuController()](js-apis-arkui-UIContext.md#getcontextmenucontroller12)方法获取ContextMenuController实例，再通过此实例调用对应方法。

### close<sup>12+</sup>

close(): void

关闭菜单

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**
通过定时器触发，调用ContextMenuController的close方法关闭菜单

```ts
import uiContext, { ContextMenuController } from '@ohos.arkui.UIContext';

@Entry
@Component
struct Index {
  menu: ContextMenuController = this.getUIContext().getContextMenuController();

  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button('Test ContextMenu1 Close')
      Divider().strokeWidth(2).margin(5).color(Color.Black)
      Button('Test ContextMenu2')
      Divider().strokeWidth(2).margin(5).color(Color.Black)
      Button('Test ContextMenu3')
    }
    .width(200)
    .height(160)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button("启动定时器").onClick(()=>
      {
        setTimeout(() => {
          this.menu.close();
        }, 10000);
      })

      Column() {
        Text("Test ContextMenu close")
          .fontSize(20)
          .width('100%')
          .height(500)
          .backgroundColor(0xAFEEEE)
          .textAlign(TextAlign.Center)
      }
      .bindContextMenu(this.MenuBuilder, ResponseType.LongPress)
    }
    .width('100%')
    .height('100%')
  }
}
```

![contextMenuController_close](figures/contextMenuController_close.gif)

## MeasureUtils<sup>12+</sup>

以下API需先使用UIContext中的[getMeasureUtils()](js-apis-arkui-UIContext.md#getmeasureutils12)方法获取MeasureUtils实例，再通过此实例调用对应方法。

### measureText<sup>12+</sup>

measureText(options: MeasureOptions): number

计算指定文本单行布局下的宽度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](js-apis-measure.md#measureoptions) | 是    | 被计算文本描述信息。 |

**返回值：**

| 类型          | 说明       |
| ------------  | --------- |
| number        | 文本宽度。<br/>**说明:**<br/>单位px。 |


**示例：**
通过MeasureUtils的measureText方法获取"Hello World"文字的宽度。

```ts
import { MeasureUtils } from '@ohos.arkui.UIContext';

@Entry
@Component
struct Index {
  @State uiContext: UIContext = this.getUIContext();
  @State uiContextMeasure: MeasureUtils = this.uiContext.getMeasureUtils();
  @State textWidth: number = this.uiContextMeasure.measureText({
    textContent: "Hello word",
    fontSize: '50px'
  })

  build() {
    Row() {
      Column() {
        Text(`The width of 'Hello World': ${this.textWidth}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### measureTextSize<sup>12+</sup>

measureTextSize(options: MeasureOptions): SizeOptions

计算指定文本单行布局下的宽度和高度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](js-apis-measure.md#measureoptions) | 是    | 被计算文本描述信息。 |

**返回值：**

| 类型          | 说明       |
| ------------  | --------- |
| [SizeOption](arkui-ts/ts-types.md#sizeoptions)   | 返回文本所占布局宽度和高度。<br/>**说明:**<br/> 文本宽度以及高度返回值单位均为px。 |


**示例：**
通过MeasureUtils的measureTextSize方法获取"Hello World"文字的宽度和高度

```ts
import { MeasureUtils } from '@ohos.arkui.UIContext';

@Entry
@Component
struct Index {
  @State uiContext: UIContext = this.getUIContext();
  @State uiContextMeasure: MeasureUtils = this.uiContext.getMeasureUtils();
  textSize : SizeOptions = this.uiContextMeasure.measureTextSize({
    textContent: "Hello word",
    fontSize: '50px'
  })
  build() {
    Row() {
      Column() {
        Text(`The width of 'Hello World': ${this.textSize.width}`)
        Text(`The height of 'Hello World': ${this.textSize.height}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## ComponentSnapshot<sup>12+</sup>

以下API需先使用UIContext中的[getComponentSnapshot()](js-apis-arkui-UIContext.md#getcomponentsnapshot12)方法获取ComponentSnapshot对象，再通过此实例调用对应方法。

### get<sup>12+</sup>

get(id: string, callback: AsyncCallback<image.PixelMap>): void

获取已加载的组件的截图，传入组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md#组件标识)，找到对应组件进行截图。通过回调返回结果。

> **说明：** 
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| id       | string                                                       | 是   | 目标组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md#组件标识) |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;image.[PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 是   | 截图返回结果的回调。                                         |

**错误码：** 

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 100001   | if id is not valid. |

**示例：**

```ts
import image from '@ohos.multimedia.image'
import { UIContext } from '@ohos.arkui.UIContext';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined
  uiContext: UIContext = this.getUIContext();
  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(150).height(150).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.img')).autoResize(true).width(150).height(150).margin(5).id("root")
      }
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot().get("root", (error: Error, pixmap: image.PixelMap) => {
            if (error) {
              console.log("error: " + JSON.stringify(error))
              return;
            }
            this.pixmap = pixmap
          })
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

### get<sup>12+</sup>

get(id: string): Promise<image.PixelMap>

获取已加载的组件的截图，传入组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md#组件标识)，找到对应组件进行截图。通过Promise返回结果。

> **说明：**
>
> 截图会获取最近一帧的绘制内容。如果在组件触发更新的同时调用截图，更新的渲染内容不会被截取到，截图会返回上一帧的绘制内容。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| id     | string | 是   | 目标组件的[组件标识](arkui-ts/ts-universal-attributes-component-id.md#组件标识) |

**返回值：**

| 类型                                                         | 说明             |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 截图返回的结果。 |

**错误码：** 

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 100001   | if id is not valid. |

**示例：**

```ts
import image from '@ohos.multimedia.image'
import { UIContext } from '@ohos.arkui.UIContext';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined
  uiContext: UIContext = this.getUIContext();

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(150).height(150).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.icon')).autoResize(true).width(150).height(150).margin(5).id("root")
      }
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot()
            .get("root")
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap
            })
            .catch((err: Error) => {
              console.log("error: " + err)
            })
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

### createFromBuilder<sup>12+</sup>

createFromBuilder(builder: CustomBuilder, callback: AsyncCallback<image.PixelMap>): void

在应用后台渲染[CustomBuilder](arkui-ts/ts-types.md#custombuilder8)自定义组件，并输出其截图。通过回调返回结果。
> **说明：** 
>
> 由于需要等待组件构建、渲染成功，离屏截图的回调有500ms以内的延迟。
>
> 部分执行耗时任务的组件可能无法及时在截图前加载完成，因此会截取不到加载成功后的图像。例如：加载网络图片的[Image](arkui-ts/ts-basic-components-image.md)组件、[Web](../apis-arkweb/ts-basic-components-web.md)组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8)         | 是   | 自定义组件构建函数。<br/>**说明：** 不支持全局builder。      |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;image.[PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 是   | 截图返回结果的回调。支持在回调中获取离屏组件绘制区域坐标和大小。 |

**错误码：** 

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 100001   | if builder is not a valid build function. |

**示例：**

```ts
import image from '@ohos.multimedia.image'
import { UIContext } from '@ohos.arkui.UIContext';

@Entry
@Component
struct ComponentSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined
  uiContext: UIContext = this.getUIContext();
  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }

  build() {
    Column() {
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot().createFromBuilder(() => {
            this.RandomBuilder()
          },
            (error: Error, pixmap: image.PixelMap) => {
              if (error) {
                console.log("error: " + JSON.stringify(error))
                return;
              }
              this.pixmap = pixmap
            })
        })
      Image(this.pixmap)
        .margin(10)
        .height(200)
        .width(200)
        .border({ color: Color.Black, width: 2 })
    }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
  }
}
```

### createFromBuilder<sup>12+</sup>

createFromBuilder(builder: CustomBuilder): Promise<image.PixelMap>

在应用后台渲染[CustomBuilder](arkui-ts/ts-types.md#custombuilder8)自定义组件，并输出其截图。通过Promise返回结果。

> **说明：** 
>
> 由于需要等待组件构建、渲染成功，离屏截图的回调有500ms以内的延迟。
>
> 部分执行耗时任务的组件可能无法及时在截图前加载完成，因此会截取不到加载成功后的图像。例如：加载网络图片的[Image](arkui-ts/ts-basic-components-image.md)组件、[Web](../apis-arkweb/ts-basic-components-web.md)组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                                    |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------------------------- |
| builder | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8) | 是   | 自定义组件构建函数。<br/>**说明：** 不支持全局builder。 |

**返回值：**

| 类型                                                         | 说明             |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 截图返回的结果。 |

**错误码：** 

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 100001   | if builder is not a valid build function. |

**示例：**

```ts
import image from '@ohos.multimedia.image'
import { UIContext } from '@ohos.arkui.UIContext';

@Entry
@Component
struct ComponentSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined
  uiContext: UIContext = this.getUIContext();
  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }
  build() {
    Column() {
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot()
            .createFromBuilder(() => {
              this.RandomBuilder()
            })
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap
            })
            .catch((err: Error) => {
              console.log("error: " + err)
            })
        })
      Image(this.pixmap)
        .margin(10)
        .height(200)
        .width(200)
        .border({ color: Color.Black, width: 2 })
    }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
  }
}
```
