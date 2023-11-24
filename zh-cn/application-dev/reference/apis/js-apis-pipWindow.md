# @ohos.PiPWindow (画中画窗口)

支持应用在视频播放、视频通话或视频会议场景下，以小窗（画中画）模式呈现内容。该模块提供画中画基础功能，包括判断当前系统是否开启画中画功能，以及创建画中画控制器用于启动、停止画中画等。

该模块提供以下常用功能：

- [PiPController](#pipcontroller)：画中画控制器。控制画中画启动、停止、状态或事件回调等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import pipWindow from '@ohos.PiPWindow';
```

## pipWindow.isPiPEnabled

isPiPEnabled(): boolean

用于判断当前系统是否开启画中画功能。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型       | 说明                                  |
|----------|-------------------------------------|
| boolean  | 当前系统是否开启画中画功能。true表示开启，false则表示未开启。 |

**示例：**

```ts
import pipWindow from '@ohos.PiPWindow';

let enable: boolean = pipWindow.isPiPEnabled();
console.log("isPipEnabled:" + enable);
```

## pipWindow.create

create(config: PiPConfiguration, callback: AsyncCallback&lt;[PiPController](#pipcontroller)&gt;): void

创建画中画控制器，使用callback异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                                                              | 必填   | 说明             |
|----------|-----------------------------------------------------------------|------|----------------|
| config   | [PiPConfiguration](#pipconfiguration)                | 是    | 创建窗口时的参数。      |
| callback | AsyncCallback&lt;[PiPController](#pipcontroller)&gt; | 是    | 回调函数。返回画中画控制器。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let pipController: pipWindow.PiPController | undefined = undefined;

if (!pipWindow.isPiPEnabled()) {
  return;
}
let config: pipWindow.PiPConfiguration = {
  context: getContext(this),
  componentController: xComponentController,
  navigationId: "navigationId",
  templateType: pipWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: 800,
  contentHeight: 600,
};
try {
  pipWindow.create(config, (err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to create pip controller. Cause: ${err}`);
      return;
    }
    pipController = data;
    console.info(`Succeeded in creating pip controller. Data: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to create pip controller. Cause: ${exception}`);
}
```

## pipWindow.create

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

创建画中画控制器，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名          | 类型                                       | 必填        | 说明             |
|--------------|------------------------------------------|-----------|----------------|
| config       | [PiPConfiguration](#pipconfiguration)    | 是         | 创建画中画控制器的参数。   |

**返回值：**

| 类型                                                         | 说明                       |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise对象。返回当前创建的画中画控制器。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let pipController: pipWindow.PiPController | undefined = undefined;
if (!pipWindow.isPiPEnabled()) {
  return;
}
let config: pipWindow.PiPConfiguration = {
  context: getContext(this),
  componentController: xComponentController,
  navigationId: "navigationId",
  templateType: pipWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: 800,
  contentHeight: 600,
};
try {
  let promise = pipWindow.create(config);
  promise.then((data) => {
    pipController = data;
    console.info(`Succeeded in creating pip controller. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create pip controller. Cause: ${err}`);
  });
} catch (exception) {
  console.error(`Failed to create pip controller. Cause: ${exception}`);
}
```

## PiPConfiguration

创建画中画控制器时的参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                  | 类型                                                                    | 必填  | 说明                                                         |
|---------------------|-----------------------------------------------------------------------|-----|------------------------------------------------------------|
| context             | [BaseContext](js-apis-inner-application-baseContext.md)               | 是   | 表示上下文环境。                                                   |
| componentController | [XComponentController](../arkui-ts/ts-basic-components-xcomponent.md) | 是   | 表示原始XComponent控制器。                                         |
| navigationId        | string                                                                | 否   | 当前page导航ID。如果当前页面是通过NavRouter跳转而来，取NavRouter的name属性；否则取空值。 |
| templateType        | [PiPTemplateType](#piptemplatetype)                                   | 否   | 模板类型，用以区分视频播放、视频通话或视频会议。                                   |
| contentWidth        | number                                                                | 否   | 原始内容宽度，用于确定画中画窗口比例。                                        |
| contentHeight       | number                                                                | 否   | 原始内容高度，用于确定画中画窗口比例。                                        |

## PiPTemplateType

画中画媒体类型枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                     | 值       | 说明                                      |
|------------------------|---------|-----------------------------------------|
| VIDEO_PLAY             | 0       | 表示将要切换为画中画播放的媒体类型是视频，系统依此加载视频播放模板。      |
| VIDEO_CALL             | 1       | 表示将要切换为画中画播放的媒体类型是视频通话，系统依此加载视频通话模板。    |
| VIDEO_MEETING          | 2       | 表示将要切换为画中画播放的媒体类型是视频会议，系统依此加载视频会议模板。    |

## PiPState

画中画生命周期状态枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| ABOUT_TO_START       | 1   | 表示画中画将要启动。            |
| STARTED              | 2   | 表示画中画已经启动。            |
| ABOUT_TO_STOP        | 3   | 表示画中画将要停止。            |
| STOPPED              | 4   | 表示画中画已经停止。            |
| ABOUT_TO_RESTORE     | 5   | 表示画中画将从小窗播放恢复到原始播放界面。 |
| ERROR                | 6   | 表示画中画生命周期执行过程出现异常。    |

## PiPActionEventType

画中画窗口控制事件类型，支持以下三种。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                                               | 说明            |
|--------------------------------------------------|---------------|
| [PiPVideoActionEvent](#pipvideoactionevent)      | 视频播放控制事件类型。   |
| [PiPCallActionEvent](#pipcallactionevent)        | 视频通话控制事件类型。   |
| [PiPMeetingActionEvent](#pipmeetingactionevent)  | 视频会议控制事件类型。   |

## PiPVideoActionEvent

视频播放控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                     | 类型       | 说明                                                                                                 |
|------------------------|----------|----------------------------------------------------------------------------------------------------|
| PiPVideoActionEvent    | string   | 有以下取值：<br/>-'playbackStateChanged'：播放状态变化，如播放、暂停。<br>-'nextVideo'：播放下一个视频。<br>-'previousVideo'：播放上一个视频。 |

## PiPCallActionEvent

视频通话控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                     | 类型     | 说明                  |
|------------------------|--------|---------------------|
| PiPCallActionEvent     | string | 值为 'hangUp'：挂断视频通话。 |

## PiPMeetingActionEvent

视频会议控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                         | 类型         | 说明                  |
|----------------------------|------------|---------------------|
| PiPMeetingActionEvent      | string     | 值为 'hangUp'：挂断视频会议。 |

## PiPController

画中画控制器实例。用于启动、停止画中画以及更新回调注册等。

下列API实例中都需先使用pipWindow.create(config: PiPConfiguration)或

pipWindow.create(config: PiPConfiguration, callback: AsyncCallback<PiPController>)

方法获取到PiPController实例，再通过此实例调用对应方法。

**系统能力：** SystemCapability.Window.SessionManager

### startPiP

startPiP(callback: AsyncCallback&lt;void&gt;): void

启动画中画，使用callback异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名         | 类型                          | 必填   | 说明                 |
|-------------|-----------------------------|------|--------------------|
| callback    | AsyncCallback&lt;void&gt;   | 是    | 回调函数。              |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID      | 错误信息                                                   |
|------------|--------------------------------------------------------|
| 1300012    | If PiP window state is abnormal.                       |
| 1300013    | Create pip window failed.                              |
| 1300014    | Error when load PiP window content or show PiP window. |
| 1300015    | If window has created.                                 |

**示例：**

```ts
try {
  let promise = pipController.startPiP((err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Succeeded in starting pip. Cause: ${err}`);
      return;
    }
    console.info('Failed to start pip.');
  });
} catch (exception) {
  console.error(`Failed to start pip: ${exception}`);
}
```

### startPiP

startPiP(): Promise&lt;void&gt;

启动画中画，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                     | 说明                 |
|------------------------|--------------------|
| Promise&lt;void&gt;    | 无返回结果的Promise对象。   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID      | 错误信息                                                   |
|------------|--------------------------------------------------------|
| 1300012    | If PiP window state is abnormal.                       |
| 1300013    | Create pip window failed.                              |
| 1300014    | Error when load PiP window content or show PiP window. |
| 1300015    | If window has created.                                 |

**示例：**

```ts
try {
  let promise = pipController.startPiP();
  promise.then((data) => {
    console.info(`Succeeded in starting pip. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to start pip. Cause: ${err}`);
  });
} catch (exception) {
  console.error(`Failed to start pip. Cause: ${exception}`);
}
```

### stopPiP

stopPiP(callback: AsyncCallback&lt;void&gt;): void

停止画中画，使用callback异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名         | 类型                          | 必填   | 说明        |
|-------------|-----------------------------|------|-----------|
| callback    | AsyncCallback&lt;void&gt;   | 是    | 回调函数。     |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID   | 错误信息                             |
|---------|----------------------------------|
| 1300011 | Stop PiP window failed.          |
| 1300012 | If PiP window state is abnormal. |
| 1300015 | If window is stopping.           |

**示例：**

```ts
try {
  let promise = pipController.stopPiP((err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Succeeded in stopping pip. Cause: ${err}`);
      return;
    }
    console.info('Failed to stop pip.');
  });
} catch (exception) {
  console.error(`Failed to stop pip: ${exception}`);
}
```

### stopPiP

stopPiP(): Promise&lt;void&gt;

停止画中画，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                   | 说明                  |
|----------------------|---------------------|
| Promise&lt;void&gt;  | 无返回结果的Promise对象。    |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID   | 错误信息                             |
|---------|----------------------------------|
| 1300011 | Stop PiP window failed.          |
| 1300012 | If PiP window state is abnormal. |
| 1300015 | If window is stopping.           |

**示例：**

```ts
try {
  let promise = pipController.stopPiP();
  promise.then((data) => {
    console.info(`Succeeded in stopping pip. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop pip. Cause: ${err}`);
  });
} catch (exception) {
  console.error(`Failed to stop pip. Cause: ${exception}`);
}
```

### setAutoStartEnabled

setAutoStartEnabled(enable: boolean): void

设置是否需要在返回桌面时自动启动画中画。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型        | 必填    | 说明                      |
|----------|-----------|-------|-------------------------|
| enable   | boolean   | 是     | true表示设置为自动拉起，否则为false。 |

```ts
pipController.setAutoStartEnabled(enable);
```

### updateContentSize

updateContentSize(width: number, height: number): void

当媒体源切换时，向画中画控制器更新媒体源尺寸信息。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型     | 必填  | 说明                    |
|--------|--------|-----|-----------------------|
| width  | number | 是   | 表示媒体内容宽度，用于更新画中画窗口比例。 |
| height | number | 是   | 表示媒体内容高度，用于更新画中画窗口比例。 |

```ts
pipController.updateContentSize(width, height);
```

### on('stateChange')

on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void

开启画中画生命周期状态的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型        | 必填   | 说明                                                                                                             |
|------------|-----------|------|----------------------------------------------------------------------------------------------------------------|
| type       | string    | 是    | 监听事件，固定为'stateChange'，即画中画生命周期状态变化事件。                                                                          |
| callback   | function  | 是    | 回调生命周期状态变化事件以及原因:<br/>state: [PiPState](#pipstate)，表示当前画中画生命周期状态；<br/>reason: string，表示当前生命周期的切换原因。 |

```ts
pipController.on("stateChange", (state: pipWindow.PiPState, reason: string) => {
  let curState: string = "";
  switch (state) {
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = "ABOUT_TO_START";
      break;
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = "ABOUT_TO_START";
      break;
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = "ABOUT_TO_START";
      break;
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = "ABOUT_TO_START";
      break;
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = "ABOUT_TO_START";
      break;
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = "ABOUT_TO_START";
      break;
    default:
      break;
  }
  console.log("stateChange:" + curState + " reason:" + reason);
});
```

### off('stateChange')

off(type: 'stateChange'): void

关闭画中画生命周期状态的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名       | 类型            | 必填    | 说明                                           |
|-----------|---------------|-------|----------------------------------------------|
| type      | string        | 是     | 监听事件，固定为'windowSizeChange'，即画中画生命周期状态变化事件。   |

**示例：**

```ts
pipController.off("stateChange");
```

### on('controlPanelActionEvent')

on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void

开启画中画控制事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型         | 必填    | 说明                                                                                                                            |
|----------|------------|-------|-------------------------------------------------------------------------------------------------------------------------------|
| type     | string     | 是     | 监听事件，固定为'controlPanelActionEvent'，即画中画控制事件。                                                                                   |
| callback | function   | 是     | 回调画中画控制事件:<br/>event: [PiPActionEventType](#pipactioneventtype)，表示控制事件类型。应用依据控制事件做相应处理，如收到'playbackStateChanged'时，需要开始/停止媒体流。 |

```ts
pipController.on("controlPanelActionEvent", (event: pipWindow.PiPActionEventType) => {
  switch (event) {
    case "playbackStateChanged":
    // start or stop video
      break;
    case "nextVideo":
    // next video, change video source here
      break;
    case "previousVideo":
    // previousVideo, change video source here
      break;
    default:
      break;
  }
  console.log("registerActionEventCallback, event:" + event);
});
```

### off('controlPanelActionEvent')

off(type: 'controlPanelActionEvent'): void

关闭画中画控制事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型                           | 必填   | 说明                                            |
|------------|------------------------------|------|-----------------------------------------------|
| type       | string                       | 是    | 监听事件，固定为'controlPanelActionEvent'，即画中画控制事件。   |

**示例：**

```ts
pipController.off("controlPanelActionEvent");
```