# @ohos.pipWindow (画中画窗口)

画中画窗口提供画中画基础功能，包括判断判断当前系统是否使能画中画功能，以及创建画中画控制器。

该模块提供以下常用功能：

- [PiPController](#pipcontroller-sup-11-sup)：画中画控制器。控制画中画启动、停止、回调等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import pipWindow from '@ohos.PiPWindow';
```

## pipWindow.isPiPEnabled<sup>11</sup>

isPiPEnabled(): boolean

用于判断当前系统是否使能画中画功能。

**系统能力：** SystemCapability.Window.SessionManager.

**返回值：**

| 类型       | 说明                                   |
|----------|--------------------------------------|
| boolean  | 当前系统是否使能画中画功能。true表示使能，false则表示未使能。  |

## pipWindow.create<sup>11</sup>

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

创建画中画控制器，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager.

**参数：**

| 参数名          | 类型                                                | 必填        | 说明              |
|--------------|---------------------------------------------------|-----------|-----------------|
| config       | [PiPConfiguration](#pipconfiguration-sup-11-sup)  | 是         | 创建窗口时的参数。       |

**返回值：**

| 类型                                                         | 说明                       |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller-sup-11-sup)&gt;  | Promise对象。返回当前创建的画中画控制器。 |

**示例：**

```ts
//待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "alertWindow",
  windowType: window.WindowType.TYPE_SYSTEM_ALERT
};
try {
  let promise = window.createWindow(config);
  promise.then((data) => {
    windowClass = data;
    console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));
}
```

## pipWindow.create<sup>11</sup>
create(config: PiPConfiguration, callback: AsyncCallback<PiPController>): void

创建画中画控制器，使用callback异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                                                              | 必填   | 说明             |
|----------|-----------------------------------------------------------------|------|----------------|
| config   | [PiPConfiguration](#pipconfiguration-sup-11-sup)                | 是    | 创建窗口时的参数。      |
| callback | AsyncCallback&lt;[PiPController](#pipcontroller-sup-11-sup)&gt; | 是    | 回调函数。返回画中画控制器。 |

**示例：**

```ts
待修改
let windowClass: window.Window | undefined = undefined;
try {
  windowClass = window.findWindow('alertWindow');
} catch (exception) {
  console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
}
```

## PiPConfiguration<sup>11</sup>

创建画中画控制器时的参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                  | 类型                                                                    | 必填  | 说明                       |
|---------------------|-----------------------------------------------------------------------|-----|--------------------------|
| context             | [BaseContext](js-apis-inner-application-baseContext.md)               | 是   | 表示上下文环境。                 |
| componentController | [XComponentController](../arkui-ts/ts-basic-components-xcomponent.md) | 是   | 表示原始XComponent控制器。       |
| navigationId        | string                                                                | 否   | 当前page导航ID               |
| templateType        | [PiPTemplateType](#piptemplatetype-sup-11-sup)                        | 否   | 模板类型，用以区分视频播放、视频通话或视频会议。 |
| contentWidth        | number                                                                | 否   | 原始内容宽度，用于确定画中画窗口比例。      |
| contentHeight       | number                                                                | 否   | 原始内容高度，用于确定画中画窗口比例。      |

## PiPTemplateType<sup>11</sup>

画中画媒体类型枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                     | 值       | 说明                                      |
|------------------------|---------|-----------------------------------------|
| VIDEO_PLAY             | 0       | 表示将要切换为画中画播放的媒体类型是视频，系统依此加载视频播放模板。      |
| VIDEO_CALL             | 1       | 表示将要切换为画中画播放的媒体类型是视频通话，系统依此加载视频通话模板。    |
| VIDEO_MEETING          | 2       | 表示将要切换为画中画播放的媒体类型是视频会议，系统依此加载视频会议模板。    |

## PiPState<sup>11</sup>

画中画生命周期状态枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值      | 说明                        |
|----------------------|--------|---------------------------|
| ABOUT_TO_START       | 0      | 表示画中画将要启动。                |
| STARTED              | 1      | 表示画中画已经启动。                |
| ABOUT_TO_STOP        | 2      | 表示画中画将要停止。                |
| STOPPED              | 3      | 表示画中画已经停止                 |
| ABOUT_TO_RESTORE     | 4      | 表示画中画将从小窗播放恢复到原始播放界面      |
| ERROR                | 5      | 表示画中画生命周期执行过程中异常          |

## PiPActionEventType<sup>11</sup>

画中画窗口控制事件类型，支持以下三种。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                                                         | 说明          |
|------------------------------------------------------------|-------------|
| [PiPVideoActionEvent](#pipvideoactionevent-sup-11-sup)     | 视频播放控制事件类型。 |
| [PiPCallActionEvent](#pipcallactionevent-sup-11-sup)       | 视频通话控制事件类型。 |
| [PiPMeetingActionEvent](#pipmeetingactionevent-sup-11-sup) | 视频会议控制事件类型。 |

## PiPVideoActionEvent<sup>11</sup>

视频播放控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 类型        | 说明                                        |
|-----------|-------------------------------------------|
| string    | 固定为‘playbackStateChanged’，播放状态变化，如播放、暂停。  |
| string    | 固定为‘nextVideo’，播放下一个视频。                   |
| string    | 固定为‘previousVideo’，播放上一个视频。               |

## PiPCallActionEvent<sup>11</sup>

视频通话控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 类型          | 说明                    |
|-------------|-----------------------|
| string      | 固定为‘hangUp’，挂断视频通话。   |

## PiPMeetingActionEvent<sup>11</sup>

视频会议控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 类型          | 说明                  |
|-------------|---------------------|
| string      | 固定为‘hangUp’，挂断视频通话。 |

## PiPController<sup>11</sup>

画中画控制器，用于启动、停止画中画以及更新回调注册等。

**系统能力：** SystemCapability.Window.SessionManager

### startPiP<sup>11</sup>

startPiP(): Promise&lt;void&gt;

启动画中画，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                     | 说明                 |
|------------------------|--------------------|
| Promise&lt;void&gt;    | 无返回结果的Promise对象。   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID      | 错误信息                            |
|------------|---------------------------------|
| 1300012    | Abnormal state of pip window.   |
| 1300013    | Create pip window failed.       |
| 1300014    | Pip internal error.             |
| 1300015    | Repeat operation of pip.        |

**示例：**

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

startPiP(callback: AsyncCallback&lt;void&gt;): void

启动画中画，使用callback异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名         | 类型                          | 必填   | 说明                 |
|-------------|-----------------------------|------|--------------------|
| callback    | AsyncCallback&lt;void&gt;   | 是    | 回调函数。              |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID      | 错误信息                           |
|------------|--------------------------------|
| 1300012    | Abnormal state of pip window.  |
| 1300013    | Create pip window failed.      |
| 1300014    | Pip internal error.            |
| 1300015    | Repeat operation of pip.       |

**示例：**

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### stopPiP<sup>11</sup>

stopPiP(): Promise&lt;void&gt;

停止画中画，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                   | 说明                  |
|----------------------|---------------------|
| Promise&lt;void&gt;  | 无返回结果的Promise对象。    |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID   | 错误信息                          |
|---------|-------------------------------|
| 1300011 | Destroy pip window failed.    |
| 1300012 | Abnormal state of pip window. |
| 1300015 | Repeat operation of pip.      |

**示例：**

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

stopPiP(callback: AsyncCallback&lt;void&gt;): void

停止画中画，使用callback异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名         | 类型                          | 必填   | 说明        |
|-------------|-----------------------------|------|-----------|
| callback    | AsyncCallback&lt;void&gt;   | 是    | 回调函数。     |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID   | 错误信息                          |
|---------|-------------------------------|
| 1300011 | Destroy pip window failed.    |
| 1300012 | Abnormal state of pip window. |
| 1300015 | Repeat operation of pip.      |

**示例：**

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### setAutoStartEnabled<sup>11</sup>

setAutoStartEnabled(enable: boolean): void

设置是否需要在返回桌面时自动启动画中画。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型        | 必填    | 说明                     |
|----------|-----------|-------|------------------------|
| enable   | boolean   | 是     | true表示自动拉起使能，否则为false。 |

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### updateContentSize<sup>11</sup>

updateContentSize(width: number, height: number): void

当媒体源切换时，向画中画控制器更新媒体源尺寸信息。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型     | 必填  | 说明                         |
|--------|--------|-----|----------------------------|
| width  | number | 是   | true表示自动拉起使能，否则为false。     |
| height | number | 是   | true表示自动拉起使能，否则为false。     |

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### on('stateChange')<sup>11</sup>

on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void

开启画中画生命周期状态的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型        | 必填   | 说明                                                                                                             |
|------------|-----------|------|----------------------------------------------------------------------------------------------------------------|
| type       | string    | 是    | 监听事件，固定为'stateChange'，即画中画生命周期状态变化事件。                                                                          |
| callback   | function  | 是    | 回调生命周期状态变化事件以及原因:<br/>state: [PiPState](#pipstate-sup-11-sup)，表示当前画中画生命周期状态；<br/>reason: string，表示当前生命周期的切换原因。 |

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### off('windowSizeChange')<sup>7+</sup>

off(type: 'stateChange'): void

关闭画中画生命周期状态的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名       | 类型            | 必填    | 说明                                           |
|-----------|---------------|-------|----------------------------------------------|
| type      | string        | 是     | 监听事件，固定为'windowSizeChange'，即画中画生命周期状态变化事件。   |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.off('windowSizeChange');
} catch (exception) {
  console.error('Failed to disable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

### on('controlPanelActionEvent')<sup>11</sup>

on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void

开启画中画控制事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型         | 必填    | 说明                                                                                   |
|----------|------------|-------|--------------------------------------------------------------------------------------|
| type     | string     | 是     | 监听事件，固定为'controlPanelActionEvent'，即画中画控制事件。                                          |
| callback | function   | 是     | 回调画中画控制事件:<br/>event: [PiPActionEventType](#pipactioneventtype-sup-11-sup)，表示控制事件类型。 |

```ts
// 待修改
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### off('controlPanelActionEvent')<sup>7+</sup>

off(type: 'controlPanelActionEvent'): void

关闭画中画控制事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型                           | 必填   | 说明                                            |
|------------|------------------------------|------|-----------------------------------------------|
| type       | string                       | 是    | 监听事件，固定为'controlPanelActionEvent'，即画中画控制事件。   |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.off('windowSizeChange');
} catch (exception) {
  console.error('Failed to disable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```