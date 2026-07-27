# 窗口错误码
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 1300001 重复操作
**错误信息**<br>
Repeated operation.

**错误描述**<br>
当进行某些重复操作时，系统会报此错误码。

**可能原因**<br>
1.窗口已经被创建。<br>
2.窗口已经处于当前状态。

**处理步骤**<br>
在创建窗口前，检查该窗口是否已经被创建或者是否已经处于当前状态。

## 1300002 窗口状态异常
**错误信息**<br>
This window state is abnormal.

**错误描述**<br>
当窗口状态异常，如未创建或已被销毁时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口未创建或已被销毁。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口是否存在，确保其已创建且未被销毁，再进行相关操作。

### 窗口销毁时调用getLastWindow崩溃
**可能原因**<br>
开发者在窗口销毁过程中（如onWindowStageDestroy、页面销毁等）调用[getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9-1)接口，导致应用崩溃。

**典型日志信息**<br>
故障日志格式：

```text
Error Name: Error
Error Message: [window][getLastWindow]msg: xxx
Error code: 1300002
Stack trace:
  at window.getLastWindow (WindowManagerService)
  at MyComponent.onWindowStageDestroy (MyAbility.ts:50)
```

关键信息：
- 错误码：1300002
- 堆栈：getLastWindow()调用位置
- 文件名和行号：定位具体代码位置

**处理步骤**<br>
根据日志堆栈定位getLastWindow()调用位置，检查是否在销毁流程中（onWindowStageDestroy、aboutToDisappear等）。常见场景：窗口创建时未调用[loadContent()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)加载页面，销毁流程中错误调用getLastWindow导致崩溃。

解决要点：
- getLastWindow()调用位置不在onWindowStageDestroy、aboutToDisappear、onDestroy等销毁回调中
- 异步任务不会在销毁后执行getLastWindow()

**正反案例**<br>
错误示例

```ts
// 错误：窗口创建时未加载页面，销毁流程中调用getLastWindow
onWindowStageCreate(windowStage: window.WindowStage) {
    // 缺失：未调用loadContent加载页面
    windowStage.getMainWindow((err, win) => {
        win.showWindow(); // 直接显示空窗口
    });
}

onWindowStageDestroy() {
    let lastWindow = window.getLastWindow(this.context); // 崩溃！
}
```

正确示例

```ts
// 正确：窗口创建时立即加载页面，销毁流程只做资源清理
onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.getMainWindow((err, win) => {
        win.loadContent('pages/MainPage'); // 创建时加载页面
    });
}

onWindowStageDestroy() {
    this.cleanupResources(); // 只做资源清理，不调用getLastWindow
}
```

### 子窗口调用setResizeByDragEnabled接口失败
**可能原因**<br>
开发者在子窗口上调用[setResizeByDragEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setresizebydragenabled14)接口设置窗口可拖拽缩放时，返回错误码1300002，无法实现拖拽缩放功能。

**典型日志信息**<br>
通过DevEco Studio或hdc查看错误日志：

```bash
hdc shell hilog | grep -i -E "1300002|setResizeByDragEnabled"
```

典型日志示例：

``` text
SetResizeByDragEnabled: This is not main window or decor enabled sub window
```

关键信息：
- 错误码：1300002（窗口状态异常）
- 错误信息：This is not main window or decor enabled sub window
- 原因：子窗口未启用标题栏，不支持拖拽缩放

**处理步骤**<br>
检查创建子窗口时是否在SubWindowOptions中将`decorEnabled`设置为`true`。

对于调用该接口的子窗口，要保证子窗口已开启窗口标题栏。

**正反案例**<br>
错误示例

```ts
windowStage.createSubWindowWithOptions('mySubWindow', {
  title: "",
  decorEnabled: false,    // 错误：未开启标题栏
  isModal: false,
  maximizeSupported: true
});
```

正确示例

```ts
let options: window.SubWindowOptions = {
  title: "",
  decorEnabled: true,   // 开启窗口标题栏
  isModal: false,
  maximizeSupported: true
};
windowStage.createSubWindowWithOptions('mySubWindow', options).then((windowClass) => {
  // decorEnabled=true时可正常调用
  windowClass.setResizeByDragEnabled(true, (err: BusinessError) => {
    console.error("setResizeByDragEnabled failed.", ` code: ${err.code}, message: ${err.message}`)
  })
})
```

### 窗口名不存在，调用findWindow查找崩溃
**可能原因**<br>
开发者在调用[findWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowfindwindow9)查找不存在的窗口时，导致应用崩溃。

**典型日志信息**<br>
故障日志格式：

```text
Error Name: Error
Error Message: [window][findWindow]msg: The window is not created or destroyed
Error code: 1300002
Stack trace:
  at window.findWindow (WindowManagerService)
  at MyComponent.onCreate (MyAbility.ts:50)
```

关键信息：
- 错误码：1300002
- 堆栈：findWindow()调用位置
- 文件名和行号：定位具体代码位置

**处理步骤**<br>
1. 根据日志堆栈定位findWindow()调用位置，检查窗口名称是否正确。使用以下命令查找findWindow参数信息：

   ```bash
   grep -n "findWindow" src/**/*.ts
   ```

2. 使用hidumper验证窗口状态：

   ```bash
   hdc shell hidumper -s WindowManagerService -a '-a'
   ```

**正反案例**<br>
错误示例

```ts
// 错误：查找窗口时传入错误窗口名称
const currWindow = window.findWindow("test_Window");
// 错误：对为空的对象进行函数调用
currWindow.showWindow();
```

正确示例

```ts
// 正确：findWindow之后对获取到的对象进行空校验
const currWindow = window.findWindow("test_Window");
if (currWindow) {
    currWindow.showWindow();
} else {
    console.error('Window not found');
}
```

### 销毁未完成导致createSubWindow创建同名子窗口失败
**可能原因**<br>
开发者在[createSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindow9)创建窗口对象后，使用[destroyWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#destroywindow9)，在窗口还未销毁的情况下，再次调用[createSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindow9)，且使用相同名称，导致窗口创建失败，报错1300002。

**典型日志信息**<br>
故障日志格式：

```text
WindowSessionCreateCheck: WindowName(TestSubWindow) already exists.
Error code: 1300002
```

关键信息：
- 重复窗口名：TestSubWindow
- 错误码：1300002

**处理步骤**<br>
destroyWindow()接口用于销毁对应窗口实例，该接口为异步接口，若createSubWindow接口调用时，需要销毁的窗口实例还未销毁完成，则有可能创建同名，触发1300002错误。

1. 根据日志堆栈定位createSubWindow()调用位置，查找所有createSubWindow调用位置，检查是否有使用相同窗口名称的情况：

   ```bash
   grep -n "createSubWindow" src/**/*.ts
   ```

2. 在创建窗口失败后，使用hidumper查看当前窗口状态：

   ```bash
   hdc shell hidumper -s WindowManagerService -a '-a'
   ```

解决要点：
- 确保destroyWindow()调用后等待异步回调完成，使用await等待销毁完成
- 或使用不同的窗口名称避免重名

**正反案例**<br>
错误示例

```ts
let windowClass: window.Window | undefined = undefined;

let windowClass = await windowStage.createSubWindow('mySubWindow');

// 错误，destroyWindow为异步接口，却当做同步接口使用
windowClass.destroyWindow();
let newWindow = await windowStage.createSubWindow('mySubWindow'); // 此处可能会返回1300002错误
```

正确示例

```ts
// 正确：等待销毁完成后再创建
let windowClass = await windowStage.createSubWindow('mySubWindow');

// 调用销毁并等待完成
await windowClass.destroyWindow();
// 确保销毁完成后，再创建同名窗口
let newWindow = await windowStage.createSubWindow('mySubWindow');
```

或使用不同的窗口名称避免重名：

```ts
// 使用时间戳作为窗口名称的一部分，避免重名
let windowName = 'mySubWindow_' + Date.now();
let windowClass = await windowStage.createSubWindow(windowName);
```

### 窗口销毁时调用off('avoidAreaChange')崩溃
**可能原因**<br>
开发者在窗口销毁过程中（如[onWindowStageDestroy](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagedestroy)、[onDestroy](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#ondestroy)或页面销毁等）调用[off('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#offavoidareachange9)接口，导致应用崩溃。

**典型日志信息**<br>
```text
Error Name: Error
Error Message: [window][off]msg: Unregister listener failed.
Error code: 1300002
Stack trace:
  at windowClass.off('avoidAreaChange') (WindowManagerService)
  at MyComponent.onWindowStageDestroy (MyAbility.ts:50)
```

关键信息：
- 错误码：1300002
- 堆栈：off('avoidAreaChange')调用位置
- 文件名和行号：定位具体代码位置（如MyAbility.ts第50行）

**处理步骤**<br>
- 根据日志堆栈定位off('avoidAreaChange')调用位置不在onWindowStageDestroy或onDestroy等销毁回调中
- 异步任务不会在销毁后执行off('avoidAreaChange')

**正反案例**<br>
错误示例

```ts
// 错误：在onWindowStageDestroy中调用off
onWindowStageDestroy() {
    this.windowClass.off('avoidAreaChange'); // 窗口可能已经销毁，1300002崩溃！
}
```

正确示例

```ts
// 取消监听时机：页面隐藏或卸载前（非销毁流程）
onPageHide() {
  try {
    this.windowClass?.off('avoidAreaChange');
  } catch (exception) {
    console.error(`Failed to disable the listener. Cause code: ${exception.code}, message: ${exception.message}`);
  }
}
```

## 1300003 系统服务工作异常
**错误信息**<br>
This window manager service works abnormally.

**错误描述**<br>
当系统服务工作异常时，会报此错误码。

**可能原因**<br>
窗口内部服务没有正常启动。

**处理步骤**<br>
系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 1300004 无权限操作
**错误信息**<br>
Unauthorized operation.

**错误描述**<br>
当对无操作权限的对象进行操作时，会报此错误码。

**可能原因**<br>
1.操作了其它进程的窗口对象。<br>
2.不支持的窗口类型调用。

**处理步骤**<br>
1.请检查是否非法操作了其它进程的窗口对象，若存在，请删除相关操作。<br>
2.请确保相关操作与其支持的窗口类型对应一致。

### 子窗口调用restore失败
**可能原因**<br>
开发者对子窗口调用[restore()](../reference/apis-arkui/arkts-apis-window-Window.md#restore14)接口，导致操作失败，报错1300004。

**典型日志信息**<br>
故障日志：

```text
BusinessError 1300004: Unauthorized operation. Possible cause: Invalid window Type.Only main windows are supported.
```

**处理步骤**<br>
`restore()`接口只能对主窗口进行恢复操作，否则会报1300004错误。

1. 使用hidumper查看窗口类型，确认窗口是否为主窗口：

    ```bash
    hdc shell hidumper -s WindowManagerService -a '-a'
    ```

2. 在输出中查找目标窗口，根据Type字段判断：
   - 若Type为1，则对应为主窗口（MainWindow），可以调用restore()。
   - Type不为1的窗口，均不能调用restore()。例如，通过[createSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindow9)接口创建的窗口为子窗口，可在创建时指定子窗口名称。

### 子窗口调用getWindowSystemBarProperties崩溃
**可能原因**<br>
开发者在应用子窗口、全局悬浮窗等非应用主窗口上调用[getWindowSystemBarProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowsystembarproperties12)接口，报错1300004。

**典型日志信息**<br>
```text
Error Name: Error
Error Message: [window][getWindowSystemBarProperties]msg: Invalid window type. Only main windows are supported.
Error code: 1300004
Stack trace:
  at windowClass.getWindowSystemBarProperties() (WindowManagerService)
  at MyComponent.onWindowStageCreate (MyAbility.ts:50)
```

关键信息：
- 错误码：1300004
- 堆栈：getWindowSystemBarProperties()调用位置
- 文件名和行号：定位具体代码位置（如MyAbility.ts第50行）

**处理步骤**<br>
getWindowSystemBarProperties()接口只适用于应用主窗口调用，否则会报1300004错误。

1. 使用hidumper查看窗口类型，确认当前窗口是否为应用主窗口：

    ```bash
    hdc shell hidumper -s WindowManagerService -a '-a'
    ```
2. 在输出中查找目标窗口，根据Type字段判断。若Type为1，则对应为主窗口，可以调用getWindowSystemBarProperties()；否则不可以调用getWindowSystemBarProperties()。

**正反案例**<br>
错误示例

```ts
windowStage.createSubWindow('mySubWindow', (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  windowClass = data;
  console.info(`Succeeded in creating the subwindow. Data: ${JSON.stringify(data)}`);
  if (!windowClass) {
    console.info('Failed to load the content. Cause: windowClass is null');
  }
  let systemBarProperty = windowClass.getWindowSystemBarProperties()
});
```

正确示例

```ts
onWindowStageCreate(windowStage: window.WindowStage) {
  let windowClass = windowStage.getMainWindowSync();
  try {
    let systemBarProperty = windowClass.getWindowSystemBarProperties();
    console.info('Success in obtaining system bar properties. Property: ' + JSON.stringify(systemBarProperty));
  } catch (err) {
    console.error(`Failed to get system bar properties. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## 1300005 WindowStage异常
**错误信息**<br>
This window stage is abnormal.

**错误描述**<br>
当WindowStage异常，如已被销毁时，操作该WindowStage，会报此错误码。

**可能原因**<br>
该WindowStage没有被创建或者已经被销毁。

**处理步骤**<br>
在对WindowStage进行操作前，检查该WindowStage是否存在，若已被销毁，请释放该WindowStage下的窗口。

## 1300006 窗口上下文异常
**错误信息**<br>
This window context is abnormal.

**错误描述**<br>
当窗口上下文异常，如已被销毁时，操作该窗口上下文，会报此错误码。

**可能原因**<br>
操作窗口上下文时，该窗口上下文已被销毁。

**处理步骤**<br>
在对窗口上下文进行操作前，检查该窗口上下文是否存在，确保其未被销毁，再进行相关操作。

<!--Del-->
## 1300007 WindowExtension拉起应用失败

**错误信息**<br>
Failed to start the ability.

**错误描述**<br>
WindowExtension拉起应用失败。

**可能原因**<br>
WindowExtension拉起应用的参数异常。

**处理步骤**<br>
检查WindowExtension参数是否被异常修改，确保其参数合法，再进行相关操作。
<!--DelEnd-->

<!--Del-->
## 1300008 显示设备异常

**错误信息**<br>
The display device is abnormal.

**错误描述**<br>
显示设备异常。

**可能原因**<br>
1. 显示设备没有准备好。<br>
2. 显示设备被移除。<br>
3. 显示设备被损坏。

**处理步骤**<br>
确保显示设备正常，再进行相关开发。
<!--DelEnd-->

## 1300009 父窗口无效

**错误信息**<br>The parent window is invalid.

**错误描述**<br>父窗口无效。

**可能原因**<br>
1. 子窗口没有绑定父窗口。<br>
2. 子窗口绑定的父窗口异常，如父窗口已被销毁等。

**处理步骤**<br>
1. 检查确保子窗口成功绑定父窗口。<br>
2. 检查子窗口绑定的父窗口状态，确保父窗口状态正常。

## 1300010 当前窗口模式不支持该操作

**错误信息**<br>The operation in the current window status is invalid.

**错误描述**<br>当前窗口模式不支持该操作。

**可能原因**<br>
1. 对全屏或分屏窗口进行move操作。<br>
2. 对全屏或分屏窗口进行resize操作。

**处理步骤**<br>
1. 不要对全屏或分屏窗口进行move操作。<br>
2. 不要对全屏或分屏窗口进行resize操作。

## 1300011 销毁画中画窗口失败

**错误信息**<br>
Failed to destroy the PiP window.

**错误描述**<br>
销毁画中画窗口失败。

**可能原因**<br>
画中画窗口空指针。<br>

**处理步骤**<br>
无需处理。

## 1300012 画中画窗口状态异常

**错误信息**<br>
The PiP window state is abnormal.

**错误描述**<br>
画中画窗口状态异常。

**可能原因**<br>
画中画窗口状态异常。

**处理步骤**<br>
无需处理。

### 画中画窗口销毁后访问导致崩溃
**可能原因**<br>
开发者在画中画窗口销毁后（如用户退出画中画、窗口生命周期结束等）调用画中画窗口[stopPiP()](../reference/apis-arkui/js-apis-pipWindow.md#stoppip)接口，触发错误码1300012。

**典型日志信息**<br>
```text
Error Name: Error
Error Message: [PiPWindow][stopPiP]msg: The window is not created or destroyed.
Error code: 1300012
```

**处理步骤**<br>
- 是否在画中画生命周期状态为`ABOUT_TO_STOP`或`STOPPED`时调用stopPiP()接口。

  在以上状态时，代表画中画窗口即将停止或已经停止，此时不可调用stopPiP()接口。

- 是否在`setTimeout`、`Promise`等异步回调中调用stopPiP()，且回调执行时窗口可能已销毁。

  在异步回调中，画中画窗口可能已被销毁，代码中没有对画中画窗口状态进行校验，此时调用stopPiP()接口会导致错误。

**正反案例**<br>
错误示例

```ts
// 错误：异步任务在窗口销毁后调用stopPiP()接口
stopPiPTimer() {
    setTimeout(() => {
        this.pipController?.stopPiP();
    }, 1000);
}
```

正确示例
```ts
async stopPiPSafely(pipController: PiPController) {
  let state: string = 'undefined';
  
  pipController.on('stateChange', (newState: string, reason: string) => {
    state = newState;
    if (state === 'STARTED') {
      pipController?.stopPiP();
    }
  });
}
```

### 画中画窗口重复启动导致崩溃
**可能原因**<br>
开发者在画中画窗口处于已经启动或正在启动中的状态时，调用画中画窗口[startPiP()](../reference/apis-arkui/js-apis-pipWindow.md#startpip)接口，触发错误码1300012。

**典型日志信息**<br>
```text
Error Name: Error
Error Message: [PiPWindow][startPiP]msg: The window is already started or is about to start.
Error code: 1300012
```

**处理步骤**<br>
- 是否在画中画生命周期状态为`ABOUT_TO_START`或`STARTED`时调用startPiP()接口。

  在该状态时，代表画中画窗口即将启动或已经启动，此时不可调用startPiP()接口。

- 是否在`setTimeout`、`Promise`等异步回调中调用startPiP()，且回调执行时窗口可能已启动。

  在异步回调中，画中画窗口可能已经启动或正在启动中，代码中没有对画中画窗口状态进行校验，此时调用startPiP()接口会导致错误。

**正反案例**<br>
错误示例

```ts
// 错误：异步任务在窗口已创建后调用startPiP()接口
startPiPTimer() {
    setTimeout(() => {
        this.pipController?.startPiP();
    }, 1000);
}
```

正确示例
```ts
async startPiPSafely(pipController: PiPController) {
  let state: string = 'undefined';
  
  pipController.on('stateChange', (newState: string, reason: string) => {
    state = newState;
    if (state === 'STOPPED') {
      pipController?.startPiP();
    }
  });
}
```

## 1300013 创建画中画窗口失败

**错误信息**<br>
Failed to create the PiP window.

**错误描述**<br>
创建画中画窗口失败。

**可能原因**<br>
1. 启动画中画时传入参数有误。<br>
2. 在非全屏窗口下启动画中画。

**处理步骤**<br>
1. 检查启动画中画参数。<br>
2. 不要在非全屏窗口下启动画中画。

## 1300014 画中画内部错误

**错误信息**<br>
PiP internal error.

**错误描述**<br>
画中画内部错误。

**可能原因**<br>
1.画中画依赖的窗口异常，可能窗口为空。<br>
2.画中画控制器异常。

**处理步骤**<br>
无需处理。

## 1300015 重复操作画中画

**错误信息**<br>
Repeated PiP operation.

**错误描述**<br>
重复操作画中画。

**可能原因**<br>
这个画中画已经被拉起或者已经被关闭。

**处理步骤**<br>
不要重复启动/停止画中画。<br>

## 1300016 参数校验错误

**错误信息**

Parameter validation error.

**错误描述**

参数错误，如值超出允许的范围、字符串/数组的长度不符合要求、参数格式不正确等。

**可能原因**

1.参数的值超出允许的范围。

2.参数的长度超出允许的长度。

3.参数的格式不正确。

**处理步骤**

检查参数是否符合规范。

## 1300018 API调用超时

**错误信息**

API call timed out.

**错误描述**

接口调用超时。

**可能原因**

同步接口调用等待时间超出了限制范围。

**处理步骤**

需根据具体业务场景而定，常见的几种处理方式：

1.API接口在有限次数内进行重新调用。

2.降级处理，使用缓存或执行其他业务逻辑。

3.中断本次逻辑处理。

## 1300019 闪控球参数校验错误

**错误信息**

Wrong parameters for operating the floating ball.

**错误描述**

参数错误，包括值超出范围、字符串或数组长度不符、参数格式不正确。

**可能原因**

1.参数的值超出允许的范围。

2.参数的长度超出允许的长度。

3.参数的格式不正确。

4.必传的参数没有传入。

**处理步骤**

1.参数值应处于允许的范围内。

2.参数的长度应处于允许的长度范围内。

3.参数应使用正确的格式。

4.检查是否有未传入的必传参数。

闪控球相关参数具体可见[FloatingBallParams](js-apis-floatingBall.md#floatingballparams)。

## 1300020 创建闪控球窗口失败

**错误信息**

Failed to create the floating ball window.

**错误描述**

创建闪控球窗口失败。

**可能原因**

1.启动闪控球时参数有误。

2.在不支持的设备上启动闪控球。

3.应用在后台时启动闪控球。

**处理步骤**

1.启动闪控球前，请检查参数。

2.启动闪控球前，请检查设备环境是否支持。

3.在拉起闪控球前，判断应用是否处于前台。

## 1300021 启动多个闪控球失败

**错误信息**

Failed to start multiple floating ball windows.

**错误描述**

启动多个闪控球失败。

**可能原因**

同一应用创建多个闪控球控制器启动闪控球。

**处理步骤**

同一应用应仅创建一个闪控球控制器以启动闪控球，建议使用单例模式来持有闪控球控制器。

## 1300022 重复操作闪控球

**错误信息**

Repeated floating ball operation.

**错误描述**

重复操作闪控球。

**可能原因**

1.闪控球在启动状态下再次启动。

2.闪控球停止后，再次停止无效。

3.重复注册闪控球回调。

**处理步骤**

1.在启动操作前，检查闪控球是否已启动。

2.在停止操作前，检查闪控球是否已停止。

3.在注册闪控球回调操作前，确保回调未注册。

## 1300023 闪控球内部错误

**错误信息**

Floating ball internal error.

**错误描述**

闪控球内部错误。

**可能原因**

1.闪控球依赖的窗口异常，可能为空。

2.闪控球控制器异常，可能是控制器为空。

**处理步骤**

1.检查闪控球的窗口，确保其非空。

2.检查闪控球控制器的状态，确保其不为空。

## 1300024 闪控球窗口状态异常

**错误信息**

The floating ball window state is abnormal.

**错误描述**

闪控球窗口状态异常。

**可能原因**

闪控球窗口状态异常，可能未创建或已被销毁。

**处理步骤**

检查闪控球的窗口状态，确保窗口已创建且未被销毁。

## 1300025 闪控球状态不支持该操作

**错误信息**

The floating ball state does not support this operation.

**错误描述**

闪控球状态不支持该操作。

**可能原因**

1.在闪控球未启动时进行更新操作。

2.闪控球未启动时，查询窗口信息。

3.闪控球未启动时，拉起应用窗口。

4.调用闪控球停止接口，流程未完成时启动闪控球。

**处理步骤**

1.进行更新操作前，检查闪控球是否已启动。

2.进行查询闪控球窗口信息操作时，检查闪控球是否已启动。

3.进行拉起应用窗口操作时，检查闪控球是否已启动。

4.等待闪控球回调停止后，再次启动闪控球。

## 1300026 闪控球拉起应用窗口失败

**错误信息**

Failed to restore the main window.

**错误描述**

闪控球拉起应用窗口失败。

**可能原因**

1.传入参数有误。

2.应用未申请`ohos.permission.AUTO_RESTORE_MAIN_WINDOW`权限的情况下，拉起应用窗口前未点击闪控球。

3.拉起非本应用的窗口。

**处理步骤**

1.请检查应用窗口的拉起参数。

2.若希望不与用户交互直接拉起应用窗口，请申请`ohos.permission.AUTO_RESTORE_MAIN_WINDOW`权限。否则，请在点击闪控球之后再拉起应用窗口。

3.仅拉起本应用窗口。

## 1300027 更新闪控球时不能改变模板类型

**错误信息**

When updating the floating ball, the template type cannot be changed.

**错误描述**

更新闪控球时，模板类型与创建时不同。

**可能原因**

更新闪控球与创建闪控球时的模板类型不一致。

**处理步骤**

请确保在更新闪控球时，模板类型与创建闪控球时的模板类型一致。

## 1300028 不支持更新静态模板类型闪控球

**错误信息**

Updating static template-based floating balls is not supported.

**错误描述**

不支持更新静态模板类型闪控球。

**可能原因**

更新静态模板类型的闪控球。

**处理步骤**

请删除已有的静态模板类型闪控球，然后创建新的闪控球。

## 1300030 重复操作闪控窗

**错误信息**

Repeated operations on the float view.

**错误描述**

重复操作闪控窗。

**可能原因**

1. 闪控窗正在启动中或处于已启动的状态时，重复启动闪控窗。

2. 闪控窗正在停止中或处于已停止的状态时，重复停止闪控窗。

3. 重复注册闪控窗回调。

**处理步骤**

1. 建议通过[onStateChange](js-apis-floatView.md#onstatechange)获取当前状态变化。启动闪控窗前，检查闪控窗是否处于已启动的状态。

2. 建议通过[onStateChange](js-apis-floatView.md#onstatechange)获取当前状态变化。停止闪控窗前，检查闪控窗是否处于已停止的状态。

3. 注册闪控窗回调前，确保回调未注册。

## 1300031 闪控窗状态不支持该操作

**错误信息**

The floatView state does not support this operation.

**错误描述**

闪控窗状态不支持该操作。

**可能原因**

1. 闪控窗已启动但未停止时，执行要求停止态的操作（例如绑定、解绑等）。

2. 闪控窗未启动时，执行需要启动态的操作（例如停止、恢复主窗口或获取窗口属性）。

3. 闪控窗处于正在停止状态时，执行启动操作。

**处理步骤**

1. 操作前检查闪控窗当前状态，确保其满足接口的状态要求。

2. 如需停止闪控窗，请先确保闪控窗已启动。

3. 等待闪控窗停止完成（通过状态变化回调确认）后再执行后续操作。

## 1300032 恢复主窗口失败

**错误信息**

Failed to restore the main window.

**错误描述**

闪控窗拉起应用主窗口失败。

**可能原因**

1. 用户从未点击过闪控窗窗口。

2. 闪控窗窗口不在前台。

3. 主窗口处于PAUSED生命周期状态。

4. 主窗口处于多任务界面中。

**处理步骤**

1. 引导用户先点击闪控窗窗口，再尝试恢复主窗口。

2. 检查闪控窗窗口是否在前台显示。

3. 检查主窗口生命周期状态，避免在PAUSED状态下调用恢复接口。

4. 确保主窗口不处于多任务状态，再尝试恢复。

## 1300033 启动闪控窗失败

**错误信息**

Failed to start float view.

**错误描述**

启动闪控窗失败。

**可能原因**

1. 同一应用重复启动了多个闪控窗。

2. 启动闪控窗时，context关联的主窗口不在前台。

**处理步骤**

1. 同一应用只能启动一个闪控窗，请避免同时启动多个闪控窗。

2. 启动闪控窗前，请确保传入context的应用窗口处于前台。

## 1300034 闪控窗与其他悬浮窗口操作冲突

**错误信息**

This operation conflicts with other floating windows.

**错误描述**

该操作与其他悬浮窗口冲突。

**可能原因**

应用已启动闪控球窗口或画中画窗口。

**处理步骤**

启动闪控窗前，请先停止闪控球窗口和画中画窗口。

## 1001 窗口空指针异常<sup>(deprecated)</sup>
**错误信息**<br>
A window null pointer occurs.

**错误描述**<br>
窗口空指针异常，如出现空指针时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，出现空指针。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口是否存在空指针，确保其不存在空指针，再进行相关操作。

## 1002 无效的窗口类型<sup>(deprecated)</sup>
**错误信息**<br>
This window type is invalid.

**错误描述**<br>
窗口类型无效。

**可能原因**<br>
使用了无效的窗口类型，有效的窗口类型见[WindowType](arkts-apis-window-e.md#windowtype7)。

**处理步骤**<br>
请使用WindowType支持的窗口类型，再进行相关操作。

## 1003 无效的窗口参数<sup>(deprecated)</sup>
**错误信息**<br>
This window parameter is invalid.

**错误描述**<br>
当窗口参数无效时，操作该窗口，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口参数无效。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口参数是否有效，确保其参数有效，再进行相关操作。

## 1004 元能力服务异常<sup>(deprecated)</sup>
**错误信息**<br>
This system ability service works abnormally.

**错误描述**<br>
当元能力服务工作异常时，会报此错误码。

**可能原因**<br>
当销毁窗口时，如初始化proxy失败。

**处理步骤**<br>
元能力服务异常，重启设备尝试。

## 1005 IPC通信失败<sup>(deprecated)</sup>
**错误信息**<br>
This window IPC failed.

**错误描述**<br>
当IPC通信失败时，会报此错误码。

**可能原因**<br>
操作窗口时，该窗口参数IPC传输失败。

**处理步骤**<br>
在对窗口进行操作前，检查该窗口客户端和服务端服务正常，再进行相关操作。

## 1007 WindowExtension拉起应用失败<sup>(deprecated)</sup>
**错误信息**<br>
Failed to start the ability.

**错误描述**<br>
WindowExtension拉起应用失败。

**可能原因**<br>
WindowExtension拉起应用的参数异常。

**处理步骤**<br>
检查WindowExtension参数是否被异常修改，确保其参数合法，再进行相关操作。