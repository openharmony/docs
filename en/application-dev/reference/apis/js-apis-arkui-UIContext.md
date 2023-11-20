# @ohos.arkui.UIContext (UIContext)

In the stage model, a window stage or window can use the **loadContent** API to load pages, create a UI instance, and render page content to the associated window. Naturally, UI instances and windows are associated on a one-by-one basis. Some global UI APIs are executed in the context of certain UI instances. When calling these APIs, you must identify the UI context, and consequently UI instance, by tracing the call chain. If these APIs are called on a non-UI page or in some asynchronous callback, the current UI context may fail to be identified, resulting in API execution errors.

**@ohos.window** adds the [getUIContext](./js-apis-window.md#getuicontext10) API in API version 10 for obtaining the **UIContext** object of a UI instance. The API provided by the **UIContext** object can be directly applied to the corresponding UI instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.

## UIContext

In the following API examples, you must first use [getUIContext()](./js-apis-window.md#getuicontext10) in **@ohos.window** to obtain a **UIContext** instance, and then call the APIs using the obtained instance. In this document, the **UIContext** instance is represented by **uiContext**.

### getFont

getFont(): Font

Obtains a **Font** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type           | Description         |
| ------------- | ----------- |
| [Font](#font) | **Font** object.|

**Example**

```ts
uiContext.getFont();
```
### getComponentUtils

getComponentUtils(): ComponentUtils

Obtains the **ComponentUtils** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                               | Description                   |
| --------------------------------- | --------------------- |
| [ComponentUtils](#componentutils) | **ComponentUtils** object.|

**Example**

```ts
uiContext.getComponentUtils();
```

### getUIInspector

getUIInspector(): UIInspector

Obtains the **UIInspector** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                         | Description                |
| --------------------------- | ------------------ |
| [UIInspector](#uiinspector) | **UIInspector** object.|

**Example**

```ts
uiContext.getUIInspector();
```

### getMediaQuery

getMediaQuery(): MediaQuery

Obtains a **MediaQuery** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                       | Description               |
| ------------------------- | ----------------- |
| [MediaQuery](#mediaquery) | **MediaQuery** object.|

**Example**

```ts
uiContext.getMediaQuery();
```

### getRouter

getRouter(): Router

Obtains a **Router** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description           |
| ----------------- | ------------- |
| [Router](#router) | **Router** object.|

**Example**

```ts
uiContext.getRouter();
```

### getPromptAction

getPromptAction(): PromptAction

Obtains a **PromptAction** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                           | Description                 |
| ----------------------------- | ------------------- |
| [PromptAction](#promptaction) | **PromptAction** object.|

**Example**

```ts
uiContext.getPromptAction();
```

### animateTo

animateTo(value: AnimateParam, event: () => void): void

Applies a transition animation for state changes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                   |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](../arkui-ts/ts-explicit-animation.md#animateparam) | Yes   | Animation settings.                          |
| event | () => void                               | Yes   | Closure function that displays the dynamic effect. The system automatically inserts the transition animation if the status changes in the closure function.|

**Example**

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
            iterations: -1, // The value -1 indicates that the animation is played for an unlimited number of times.
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

Shows an alert dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description                 |
| ------- | ---------------------------------------- | ---- | ------------------- |
| options | [AlertDialogParamWithConfirm](../arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithconfirm) \| [AlertDialogParamWithButtons](../arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithbuttons) \| [AlertDialogParamWithOptions](../arkui-ts/ts-methods-alert-dialog-box.md#alertdialogparamwithoptions10) | Yes   | Defines and displays the **\<AlertDialog>** component.|


**Example**

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

Defines and shows the action sheet.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**ActionSheetOptions parameters**

| Name       | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| title      | [Resource](../arkui-ts/ts-types.md#resource) \| string | Yes   | Title of the dialog box.                                   |
| message    | [Resource](../arkui-ts/ts-types.md#resource) \| string | Yes   | Content of the dialog box.                                   |
| autoCancel | boolean                                  | No   | Whether to close the dialog box when the overlay is clicked.<br>Default value: **true**              |
| confirm    | {<br>value: [ResourceStr](../arkui-ts/ts-types.md#resourcestr),<br>action: () =&gt; void<br>} | No   | Text content of the confirm button and callback upon button clicking.<br>Default value:<br>**value**: button text.<br>**action**: callback upon button clicking.|
| cancel     | () =&gt; void                  | No   | Callback invoked when the dialog box is closed after the overlay is clicked.                      |
| alignment  | [DialogAlignment](../arkui-ts/ts-methods-alert-dialog-box.md#dialogalignment) | No   | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Bottom**|
| offset     | {<br>dx: [Length](../arkui-ts/ts-types.md#length),<br>dy: [Length](../arkui-ts/ts-types.md#length)<br>} | No   | Offset of the dialog box relative to the alignment position.{<br>dx: 0,<br>dy: 0<br>} |
| sheets     | Array&lt;SheetInfo&gt;                   | Yes   | Options in the dialog box. Each option supports the image, text, and callback.            |

**SheetInfo parameters**

| Name   | Type                                      | Mandatory  | Description            |
| ------ | ---------------------------------------- | ---- | -------------- |
| title  | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | Yes   | Text of the option.      |
| icon   | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | No   | Sheet icon. By default, no icon is displayed.|
| action | ()=&gt;void                              | Yes   | Callback when the sheet is selected.      |

**Example**

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

Shows a date picker dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**DatePickerDialogOptions parameters**

| Name               | Type                                      | Mandatory  | Description                                    |
| ------------------ | ---------------------------------------- | ---- | -------------------------------------- |
| start              | Date                                     | No   | Start date of the picker.<br>Default value: **Date('1970-1-1')**  |
| end                | Date                                     | No   | End date of the picker.<br>Default value: **Date('2100-12-31')**|
| selected           | Date                                     | No   | Selected date.<br>Default value: current system date             |
| lunar              | boolean                                  | No   | Whether to display the lunar calendar.<br>Default value: **false**              |
| showTime           | boolean                                  | No   | Whether to display the time item.<br>Default value: **false**                |
| useMilitaryTime    | boolean                                  | No   | Whether to display time in 24-hour format.<br>Default value: **false**           |
| disappearTextStyle | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width for the top and bottom items.        |
| textStyle          | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width of all items except the top, bottom, and selected items.    |
| selectedTextStyle  | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width of the selected item.                   |
| onAccept           | (value: [DatePickerResult](../arkui-ts/ts-basic-components-datepicker.md#datepickerresult)) => void | No   | Callback invoked when the OK button in the dialog box is clicked.                   |
| onCancel           | () => void                               | No   | Callback invoked when the Cancel button in the dialog box is clicked.                   |
| onChange           | (value: [DatePickerResult](../arkui-ts/ts-basic-components-datepicker.md#datepickerresult)) => void | No   | Callback invoked when the selected item in the picker changes.            |

**Example**

```ts
let selectedDate: Date = new Date("2010-1-1")
uiContext.showDatePickerDialog({
  start: new Date("2000-1-1"),
  end: new Date("2100-12-31"),
  selected: selectedDate,
  onAccept: (value: DatePickerResult) => {
    // Use the setFullYear method to set the date when the OK button is touched. In this way, when the date picker dialog box is displayed again, the selected date is the date last confirmed.
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

Shows a time picker dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**TimePickerDialogOptions parameters**

| Name               | Type                                      | Mandatory  | Description                                  |
| ------------------ | ---------------------------------------- | ---- | ------------------------------------ |
| selected           | Date                                     | No   | Selected time.<br>Default value: current system time           |
| useMilitaryTime    | boolean                                  | No   | Whether to display time in 24-hour format. The 12-hour format is used by default.<br>Default value: **false**|
| disappearTextStyle | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width for the top and bottom items.      |
| textStyle          | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width of all items except the top, bottom, and selected items.  |
| selectedTextStyle  | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width of the selected item.                 |
| onAccept           | (value: [TimePickerResult](../arkui-ts/ts-basic-components-timepicker.md#timepickerresult)) => void | No   | Callback invoked when the OK button in the dialog box is clicked.                 |
| onCancel           | () => void                               | No   | Callback invoked when the Cancel button in the dialog box is clicked.                 |
| onChange           | (value: [TimePickerResult](../arkui-ts/ts-basic-components-timepicker.md#timepickerresult)) => void | No   | Callback invoked when the selected time changes.           |

**Example**

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
    // Set selectTime to the time when the OK button is clicked. In this way, when the dialog box is displayed again, the selected time is the time when the operation was confirmed last time.
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

Shows a text picker in the given settings.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**TextPickerDialogOptions parameters**

| Name                    | Type                                      | Mandatory  | Description                                      |
| ----------------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| range                   | string[] \| [Resource](../arkui-ts/ts-types.md#resource)\|[TextPickerRangeContent](../arkui-ts/ts-basic-components-textpicker.md#textpickerrangecontent10)[] | Yes   | Data selection range of the picker. This parameter cannot be set to an empty array. If set to an empty array, it will not be displayed.   |
| selected                | number                                   | No   | Index of the selected item.<br>Default value: **0**                     |
| value                   | string                                   | No   | Text of the selected item. This parameter does not take effect when the **selected** parameter is set. If the value is not within the range, the first item in the range is used instead.|
| defaultPickerItemHeight | number \| string                         | No   | Height of the picker item.                            |
| disappearTextStyle      | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width for the top and bottom items.          |
| textStyle               | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width of all items except the top, bottom, and selected items.      |
| selectedTextStyle       | [PickerTextStyle](../arkui-ts/ts-basic-components-datepicker.md#pickertextstyle10) | No   | Font color, font size, and font width of the selected item.                     |
| onAccept                | (value: [TextPickerResult](../arkui-ts/ts-methods-textpicker-dialog.md#textpickerresult)) => void | No   | Callback invoked when the OK button in the dialog box is clicked.                     |
| onCancel                | () => void                               | No   | Callback invoked when the Cancel button in the dialog box is clicked.                     |
| onChange                | (value: [TextPickerResult](../arkui-ts/ts-methods-textpicker-dialog.md#textpickerresult)) => void | No   | Callback invoked when the selected item changes.                |

**Example**

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
    // Set select to the index of the item selected when the OK button is touched. In this way, when the text picker dialog box is displayed again, the selected item is the one last confirmed.
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

Creates an **Animator** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description     |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [AnimatorOptions](./js-apis-animator.md#animatoroptions) | Yes   | Animator options.|

**Return value**

| Type                                      | Description           |
| ---------------------------------------- | ------------- |
| [AnimatorResult](./js-apis-animator.md#animatorresult) | Animator result.|

**Example**

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

Executes the specified callback in this UI context.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type        | Mandatory  | Description  |
| -------- | ---------- | ---- | ---- |
| callback | () => void | Yes   | Callback used to return the result.|

**Example**

```ts
uiContext.runScopedTask(
  () => {
    console.log('Succeeded in runScopedTask');
  }
);
```

### setKeyboardAvoidMode<sup>11+</sup>

setKeyboardAvoidMode(value: KeyboardAvoidMode): void

Sets the avoidance mode for the virtual keyboard.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type        | Mandatory  | Description  |
| -------- | ---------- | ---- | ---- |
| value | [KeyboardAvoidMode](../apis/js-apis-arkui-UIContext.md#keyboardavoidmode11)| Yes   | Avoidance mode for the virtual keyboard.<br>Default value: **KeyboardAvoidMode.OFFSET**|

**Example**

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

Obtains the avoidance mode for the virtual keyboard.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type        | Description  |
| ---------- | ---- |
| [KeyboardAvoidMode](../apis/js-apis-arkui-UIContext.md#keyboardavoidmode11)| Avoidance mode for the virtual keyboard.|

**Example**

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

Obtains an **AtomicServiceBar** object, which can be used to set the properties of the atomic service menu bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type|Description|
|----|----|
|Nullable<[AtomicServiceBar](#atomicservicebar11)>| Returns the **AtomicServerBar** type if the service is an atomic service; returns **undefined** type otherwise.|

**Example**

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

## Font

In the following API examples, you must first use [getFont()](#getfont) in **UIContext** to obtain a **Font** instance, and then call the APIs using the obtained instance.

### registerFont

registerFont(options: font.FontOptions): void

Registers a custom font with the font manager.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description         |
| ------- | ---------------------------------------- | ---- | ----------- |
| options | [font.FontOptions](js-apis-font.md#fontoptions) | Yes   | Information about the custom font to register.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let font:Font = uiContext.getFont();
font.registerFont({
  familyName: 'medium',
  familySrc: '/font/medium.ttf'
});
```
### getStstemFontList

getSystemFontList(): Array\<string> 

Obtains the list of supported fonts.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type            | Description       |
| -------------- | --------- |
| Array\<string> | List of supported fonts.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let font:Font|undefined = uiContext.getFont();
if(font){
  font.getSystemFontList()
}
```

### getFontByName

getFontByName(fontName: string): font.FontInfo

Obtains information about a system font based on the font name.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type    | Mandatory  | Description     |
| -------- | ------ | ---- | ------- |
| fontName | string | Yes   | System font name.|

**Return value**

| Type                                  | Description     |
| ------------------------------------ | ------- |
| [FontInfo](js-apis-font.md#fontinfo10) | Information about the system font.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let font:Font|undefined = uiContext.getFont();
if(font){
  font.getFontByName('Sans Italic')
}
```

## ComponentUtils

In the following API examples, you must first use [getComponentUtils()](#getcomponentutils) in **UIContext** to obtain a **ComponentUtils** instance, and then call the APIs using the obtained instance.

### getRectangleById

getRectangleById(id: string): componentUtils.ComponentInfo

Obtains the size, position, translation, scaling, rotation, and affine matrix information of the specified component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| id   | string | Yes   | Unique component ID.|

**Return value**

| Type                                      | Description                      |
| ---------------------------------------- | ------------------------ |
| [ComponentInfo](js-apis-arkui-componentUtils.md#componentinfo) | Size, position, translation, scaling, rotation, and affine matrix information of the component.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let componentUtils:ComponentUtils = uiContext.getComponentUtils();
let modePosition = componentUtils.getRectangleById("onClick");
let localOffsetWidth = modePosition.size.width;
let localOffsetHeight = modePosition.size.height;
```

## UIInspector

In the following API examples, you must first use [getUIInspector()](#getuiinspector) in **UIContext** to obtain a **UIInspector** instance, and then call the APIs using the obtained instance.

### createComponentObserver

createComponentObserver(id: string): inspector.ComponentObserver

Creates an observer for the specified component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| id   | string | Yes   | Component ID.|

**Return value**

| Type                                      | Description                       |
| ---------------------------------------- | ------------------------- |
| [ComponentObserver](js-apis-arkui-inspector.md#componentobserver) | Component observer, which is used to register and unregister listeners for completion of component layout or drawing.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let inspector:UIInspector = uiContext.getUIInspector();
let listener = inspector.createComponentObserver('COMPONENT_ID');
```

## MediaQuery

In the following API examples, you must first use [getMediaQuery()](#getmediaquery) in **UIContext** to obtain a **MediaQuery** instance, and then call the APIs using the obtained instance.

### matchMediaSync

matchMediaSync(condition: string): mediaQuery.MediaQueryListener

Sets the media query criteria and returns the corresponding listening handle.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type    | Mandatory  | Description                                      |
| --------- | ------ | ---- | ---------------------------------------- |
| condition | string | Yes   | Media query condition. For details, see [Syntax](../../ui/arkts-layout-development-media-query.md#syntax).|

**Return value**

| Type                | Description                    |
| ------------------ | ---------------------- |
| MediaQueryListener | Listening handle to a media event, which is used to register or deregister the listening callback.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
let mediaquery: MediaQuery = uiContext.getMediaQuery();
let listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen for landscape events.
```

## Router

In the following API examples, you must first use [getRouter()](#getrouter) in **UIContext** to obtain a **Router** instance, and then call the APIs using the obtained instance.

### pushUrl

pushUrl(options: router.RouterOptions): Promise&lt;void&gt;

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Page routing parameters.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**Example**

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

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Page routing parameters.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**Example**

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

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description        |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Page routing parameters. |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**Example**

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

Navigates to a specified page in the application.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description        |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Page routing parameters. |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100002 | if the uri is not exist.           |
| 100003 | if the pages are pushed too much.  |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Description of the new page.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Description of the new page.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description        |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Description of the new page. |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if can not get the delegate, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**Example**

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

Replaces the current page with another one in the application and destroys the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description        |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.RouterOptions](js-apis-router.md#routeroptions) | Yes   | Description of the new page. |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 200002 | if the uri is not exist.                 |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Page routing parameters.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Page routing parameters.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description        |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Page routing parameters. |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**Example**

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

Navigates to a page using the named route. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description        |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Page routing parameters. |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |
| 100003 | if the pages are pushed too much.  |
| 100004 | if the named route is not exist.   |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Description of the new page.|

**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Description of the new page.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description        |
| ------- | ---------------------------------------- | ---- | ---------- |
| options | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Description of the new page. |
| mode    | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|


**Return value**

| Type                 | Description     |
| ------------------- | ------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if can not get the delegate, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**Example**

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

Replaces the current page with another one using the named route and destroys the current page. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description        |
| -------- | ---------------------------------------- | ---- | ---------- |
| options  | [router.NamedRouterOptions](js-apis-router.md#namedrouteroptions10) | Yes   | Description of the new page. |
| mode     | [router.RouterMode](js-apis-router.md#routermode9) | Yes   | Routing mode.|
| callback | AsyncCallback&lt;void&gt;                | Yes   | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if UI execution context not found, only throw in standard system. |
| 100004 | if the named route is not exist.         |

**Example**

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

Returns to the previous page or a specified page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description                                      |
| ------- | ---------------------------------------- | ---- | ---------------------------------------- |
| options | [router.RouterOptions](js-apis-router.md#routeroptions) | No   | Description of the page. The **url** parameter indicates the URL of the page to return to. If the specified page does not exist in the page stack, the application does not respond. If no URL is set, the application returns to the previous page, and the page is not rebuilt. The page in the page stack is not reclaimed. It will be reclaimed after being popped up.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.back({url:'pages/detail'});    
```

### clear

clear(): void

Clears all historical pages in the stack and retains only the current page at the top of the stack.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.clear();    
```

### getLength

getLength(): string

Obtains the number of pages in the current stack.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | Number of pages in the stack. The maximum value is **32**.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
let size = router.getLength();        
console.log('pages stack size = ' + size);    
```

### getState

getState(): router.RouterState

Obtains state information about the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [RouterState](js-apis-router.md#routerstate) | Page routing state.|

**Example**

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

Enables the display of a confirm dialog box before returning to the previous page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description       |
| ------- | ---------------------------------------- | ---- | --------- |
| options | [router.EnableAlertOptions](js-apis-router.md#enablealertoptions) | Yes   | Description of the dialog box.|

**Error codes**

For details about the error codes, see [Router Error Codes](../errorcodes/errorcode-router.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**Example**

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

Disables the display of a confirm dialog box before returning to the previous page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.hideAlertBeforeBackPage();    
```

### getParams

getParams(): Object

Obtains the parameters passed from the page that initiates redirection to the current page.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description               |
| ------ | ----------------- |
| object | Parameters passed from the page that initiates redirection to the current page.|

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
let router: Router = uiContext.getRouter();
router.getParams();
```

## PromptAction

In the following API examples, you must first use [getPromptAction()](#getpromptaction) in **UIContext** to obtain a **PromptAction** instance, and then call the APIs using the obtained instance.

### showToast

showToast(options: promptAction.ShowToastOptions): void

Shows a toast.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description     |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [promptAction.ShowToastOptions](js-apis-promptAction.md#showtoastoptions) | Yes   | Toast options.|

**Error codes**

For details about the error codes, see [promptAction Error Codes](../errorcodes/errorcode-promptAction.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**Example**

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

Shows a dialog box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description          |
| -------- | ---------------------------------------- | ---- | ------------ |
| options  | [promptAction.ShowDialogOptions](js-apis-promptAction.md#showdialogoptions) | Yes   | Dialog box options.|
| callback | AsyncCallback&lt;[promptAction.ShowDialogSuccessResponse](js-apis-promptAction.md#showdialogsuccessresponse)&gt; | Yes   | Callback used to return the dialog box response result.  |

**Error codes**

For details about the error codes, see [promptAction Error Codes](../errorcodes/errorcode-promptAction.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**Example**

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

Shows a dialog box. This API uses a promise to return the result synchronously.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description    |
| ------- | ---------------------------------------- | ---- | ------ |
| options | [promptAction.ShowDialogOptions](js-apis-promptAction.md#showdialogoptions) | Yes   | Dialog box options.|

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| Promise&lt;[promptAction.ShowDialogSuccessResponse](js-apis-promptAction.md#showdialogsuccessresponse)&gt; | Promise used to return the dialog box response result.|

**Error codes**

For details about the error codes, see [promptAction Error Codes](../errorcodes/errorcode-promptAction.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**Example**

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

showActionMenu(options: promptAction.ActionMenuOptions, callback:promptAction.ActionMenuSuccessResponse):void

Shows an action menu. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [promptAction.ActionMenuOptions](js-apis-promptAction.md#actionmenuoptions) | Yes   | Action menu options.  |
| callback | [promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse) | Yes   | Callback used to return the action menu response result.|

**Error codes**

For details about the error codes, see [promptAction Error Codes](../errorcodes/errorcode-promptAction.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**Example**

```ts
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';
class buttonsMoabl {
  text: string = ""
  color: string = ""
}
class dataR{
  err:Error = new Error;
  data:promptAction.ActionMenuSuccessResponse | undefined = undefined;
}
let dataAMSR:dataR = new dataR()
let promptActionF: PromptAction = uiContext.getPromptAction();
try {
  if(dataAMSR.data){
    promptActionF.showActionMenu({
      title: 'Title Info',
      buttons: [
        {
          text: 'item1',
          color: '#666666'
        } as buttonsMoabl,
        {
          text: 'item2',
          color: '#000000'
        } as buttonsMoabl
      ]
    }, (dataAMSR.data))
    if (dataAMSR.err) {
      console.info('showActionMenu err: ' + dataAMSR.err);
    }else{
      console.info('showActionMenu success callback, click button: ' + dataAMSR.data.index);
    }
  }
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```

### showActionMenu

showActionMenu(options: promptAction.ActionMenuOptions): Promise&lt;promptAction.ActionMenuSuccessResponse&gt;

Shows an action menu. This API uses a promise to return the result synchronously.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description     |
| ------- | ---------------------------------------- | ---- | ------- |
| options | [promptAction.ActionMenuOptions](js-apis-promptAction.md#actionmenuoptions) | Yes   | Action menu options.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise&lt;[promptAction.ActionMenuSuccessResponse](js-apis-promptAction.md#actionmenusuccessresponse)&gt; | Promise used to return the action menu response result.|

**Error codes**

For details about the error codes, see [promptAction Error Codes](../errorcodes/errorcode-promptAction.md).

| ID | Error Message                              |
| ------ | ---------------------------------- |
| 100001 | if UI execution context not found. |

**Example**

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

## AtomicServiceBar<sup>11+</sup>

In the following API examples, you must first use **getAtomicServiceBar** in **UIContext** to obtain an **AtomicServiceBar** instance, and then call the APIs using the obtained instance.

### setVisible<sup>11+</sup>

setVisible(visible: boolean): void

Sets whether the atomic service menu bar is visible.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| visiable | boolean | Yes| Whether the atomic service menu bar is visible.|


**Example**

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

Sets the background color of the atomic service menu bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| color | color:Nullable\<[Color](../arkui-ts/ts-appendix-enums.md#color) \| number \| string> | Yes| Background color of the atomic service menu bar. The value **undefined** means to use the default color.|

**Example**

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

Sets the title of the atomic service menu bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name|Type|Mandatory|Description|
| ------- | ------- | ------- | ------- |
| content | string | Yes| Title of the atomic service menu bar.|

**Example**

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

Sets the font style of the atomic service menu bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| font | [FontStyle](../arkui-ts/ts-appendix-enums.md#fontstyle) | Yes| Font style of the atomic service menu bar.|

**Example**

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

Sets the color of the atomic service icon.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| color | Nullable\<[Color](../arkui-ts/ts-appendix-enums.md#color) \| number \| string> | Yes| Color of the atomic service icon. The value **undefined** means to use the default color.|


**Example**

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

Enumerates the avoidance modes for the virtual keyboard.

| Name  | Description      |
| ------ | ---------- |
| OFFSET | Avoid the virtual keyboard through offset.|
| RESIZE | Avoid the virtual keyboard through resizing.|
