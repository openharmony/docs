# @ohos.PiPWindow (画中画窗口)

该模块提供画中画基础功能，包括判断当前系统是否开启画中画功能，以及创建画中画控制器用于启动、停止画中画等。主要用于视频播放、视频通话或视频会议场景下，以小窗（画中画）模式呈现内容。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 需要在支持SystemCapability.Window.SessionManager能力的系统上使用该模块，参考[系统能力SystemCapability使用指南](../syscap.md)。

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
let enable: boolean = pipWindow.isPiPEnabled();
console.info('isPipEnabled:' + enable);
```

## pipWindow.create

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

创建画中画控制器，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名          | 类型                                       | 必填        | 说明                                                                                                                                                                                                                                     |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| config       | [PiPConfiguration](#pipconfiguration)    | 是         | 创建画中画控制器的参数。该参数不能为空，并且构造该参数的context和componentController不能为空。构造该参数时，如果指定了templateType，需保证templateType是[PiPTemplateType](#piptemplatetype)类型；如果指定了controlGroups，需保证controlGroups与templateType匹配，详见[PiPControlGroup](#pipcontrolgroup12)。 |

**返回值：**

| 类型                                                         | 说明                       |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise对象。返回当前创建的画中画控制器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                         |
|-------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 801   | Capability not supported                                                                                                                     |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let pipController: pipWindow.PiPController | undefined = undefined;
let mXComponentController: XComponentController = new XComponentController(); // 开发者应使用该mXComponentController初始化XComponent: XComponent( {id: 'video', type: 'surface', controller: mXComponentController} )，保证XComponent的内容可以被迁移到画中画窗口。
let navId: string = "page_1"; // 假设当前页面的导航id为page_1，详见PiPConfiguration定义，具体导航名称由开发者自行定义。
let contentWidth: number = 800; // 假设当前内容宽度800px。
let contentHeight: number = 600; // 假设当前内容高度600px。
let config: pipWindow.PiPConfiguration = {
  context: getContext(this),
  componentController: mXComponentController,
  navigationId: navId,
  templateType: pipWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: contentWidth,
  contentHeight: contentHeight,
  controlGroups: [pipWinodw.VideoPlayControlGroup.VIDEO_PREVIOUS_NEXT],
};

let promise : Promise<pipWindow.PiPController> = pipWindow.create(config);
promise.then((data : pipWindow.PiPController) => {
  pipController = data;
  console.info(`Succeeded in creating pip controller. Data:${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
});
```

## PiPConfiguration

创建画中画控制器时的参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                  | 类型                                                                    | 必填  | 说明                                                                                                                                                                                                                                                                                                                                           |
|---------------------|-----------------------------------------------------------------------|-----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context             | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)               | 是   | 表示上下文环境。                                                                                                                                                                                                                                                                                                                                     |
| componentController | [XComponentController](arkui-ts/ts-basic-components-xcomponent.md) | 是   | 表示原始[XComponent](../../ui/arkts-common-components-xcomponent.md)控制器。                                                                                                                                                                                                                                                                         |
| navigationId        | string                                                                | 否   | 当前page导航id。<br/>1、UIAbility使用[Navigation](arkui-ts/ts-basic-components-navigation.md)管理页面，需要设置Navigation控件的id属性，并将该id设置给画中画控制器，确保还原场景下能够从画中画窗口恢复到原页面。<br/>2、UIAbility使用[Router](js-apis-router.md)管理页面时（画中画场景不推荐该导航方式），无需设置navigationId。注意：该场景下启动画中画后，不要进行页面切换，否则还原场景可能出现异常。<br/>3、UIAbility只有单页面时，无需设置navigationId，还原场景下也能够从画中画窗口恢复到原页面。 |
| templateType        | [PiPTemplateType](#piptemplatetype)                                   | 否   | 模板类型，用以区分视频播放、视频通话或视频会议。                                                                                                                                                                                                                                                                                                                     |
| contentWidth        | number                                                                | 否   | 原始内容宽度，单位为px。用于确定画中画窗口比例。                                                                                                                                                                                                                                                                                                                    |
| contentHeight       | number                                                                | 否   | 原始内容高度，单位为px。用于确定画中画窗口比例。                                                                                                                                                                                                                                                                                                                    |
| controlGroups<sup>12+</sup>       | Array<[PiPControlGroup](#pipcontrolgroup12)>                                                                | 否   | 画中画控制面板的可选控件组列表，应用可以配置是否显示可选控件。应用不配置，则显示模板的基础控件（如视频播放控件组的播放/暂停控件）。从API version 12开始支持此参数。 |

## PiPTemplateType

画中画媒体类型枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称            | 值   | 说明                                   |
|---------------|-----|--------------------------------------|
| VIDEO_PLAY    | 0   | 表示将要切换为画中画播放的媒体类型是视频，系统依此加载视频播放模板。   |
| VIDEO_CALL    | 1   | 表示将要切换为画中画播放的媒体类型是视频通话，系统依此加载视频通话模板。 |
| VIDEO_MEETING | 2   | 表示将要切换为画中画播放的媒体类型是视频会议，系统依此加载视频会议模板。 |
| VIDEO_LIVE    | 3   | 表示将要切换为画中画播放的媒体类型是直播，系统依此加载直播模板。     |

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
| ERROR                | 6   | 表示画中画生命周期执行过程出现了异常。   |

## PiPControlGroup<sup>12+</sup>

画中画控制面板的可选控件组列表，应用可以配置是否显示可选控件。默认情况下控制面板只显示基础控件（如视频播放控件组的播放/暂停控件）。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                                              | 说明          |
|-------------------------------------------------|-------------|
| [VideoPlayControlGroup](#videoplaycontrolgroup12)     | 视频播放控件组。 |
| [VideoCallControlGroup](#videocallcontrolgroup12)       | 视频通话控件组。 |
| [VideoMeetingControlGroup](#videomeetingcontrolgroup12) | 视频会议控件组。 |


## VideoPlayControlGroup<sup>12+</sup>

视频播放控件组。仅当[PiPTemplateType](#piptemplatetype) 为VIDEO_PLAY时使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| VIDEO_PREVIOUS_NEXT       | 101   | 视频上一个/下一个控件组。<br/>与视频快进/后退控件组为互斥控件组。如添加视频快进/后退控件组，则不可添加该控件组。           |
| FAST_FORWARD_BACKWARD    | 102   | 视频快进/后退控件组。<br/>与视频上一个/下一个控件组为互斥控件组。如添加视频上一个/下一个控件组，则不可添加该控件组。           |

## VideoCallControlGroup<sup>12+</sup>

视频通话控件组。仅当[PiPTemplateType](#piptemplatetype) 为VIDEO_CALL时使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| MICROPHONE_SWITCH       | 201   | 打开/关闭麦克风控件组。            |
| HANG_UP_BUTTON    | 202   | 挂断控件组。           |
| CAMERA_SWITCH    | 203   | 打开/关闭摄像头控件组。            |

## VideoMeetingControlGroup<sup>12+</sup>

视频会议控件组。仅当[PiPTemplateType](#piptemplatetype) 为VIDEO_MEETING时使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| HANG_UP_BUTTON       | 301   | 挂断控件组。          |
| CAMERA_SWITCH    | 302   | 打开/关闭摄像头控件组。           |
| MUTE_SWITCH    | 303   | 静音控件组。            |


## PiPActionEventType

画中画控制事件类型，支持以下四种。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                                              | 说明          |
|-------------------------------------------------|-------------|
| [PiPVideoActionEvent](#pipvideoactionevent)     | 视频播放控制事件类型。 |
| [PiPCallActionEvent](#pipcallactionevent)       | 视频通话控制事件类型。 |
| [PiPMeetingActionEvent](#pipmeetingactionevent) | 视频会议控制事件类型。 |
| [PiPLiveActionEvent](#pipliveactionevent)       | 直播控制事件类型。   |

## PiPVideoActionEvent

视频播放控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                     | 类型       | 说明                                                                                                  |
|------------------------|----------|-----------------------------------------------------------------------------------------------------|
| PiPVideoActionEvent    | string   | 有以下取值：<br/>-'playbackStateChanged'：播放状态发生了变化。<br/>-'nextVideo'：播放下一个视频。<br/>-'previousVideo'：播放上一个视频。<br/>-'fastForward'：视频进度快进。从API version 12 开始支持。<br/>-'fastBackward'：视频进度后退。从API version 12 开始支持。  |

## PiPCallActionEvent

视频通话控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                     | 类型     | 说明                                                                                             |
|------------------------|--------|------------------------------------------------------------------------------------------------|
| PiPCallActionEvent     | string | 有以下取值：<br/>-'hangUp'：挂断视频通话。<br/>-'micStateChanged'：打开或关闭麦克风。<br/>-'videoStateChanged'：打开或关闭摄像头。 |

## PiPMeetingActionEvent

视频会议控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                         | 类型         | 说明                                                                                              |
|----------------------------|------------|-------------------------------------------------------------------------------------------------|
| PiPMeetingActionEvent      | string     | 有以下取值：<br/>-'hangUp'：挂断视频会议。<br/>-'voiceStateChanged'：静音或解除静音。<br/>-'videoStateChanged'：打开或关闭摄像头。 |

## PiPLiveActionEvent

直播控制事件类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                       | 类型           | 说明                                |
|--------------------------|--------------|-----------------------------------|
| PiPLiveActionEvent       | string       | 值为'playbackStateChanged'：播放或暂停直播。 |

## ControlPanelActionEventCallback<sup>12+</sup>

描述画中画控制面板动作事件回调。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                       | 类型           | 说明                                |
|--------------------------|--------------|-----------------------------------|
| ControlPanelActionEventCallback       | (event: [PiPActionEventType](#pipactioneventtype), status?: number) => void       | 回调画中画控制事件。<br/>event表示控制事件类型。应用依据控制事件做相应处理，如触发'playbackStateChanged'事件时，需要开始或停止视频；<br/>status表示可切换状态的控件当前的状态，如具备打开和关闭两种状态的麦克风控件组、摄像头控件组和静音控件组，打开为1，关闭为0。其余控件该参数返回默认值-1。 |

## PiPController

画中画控制器实例。用于启动、停止画中画以及更新回调注册等。

下列API示例中都需先使用[pipWindow.create()](#pipwindowcreate)方法获取到PiPController实例，再通过此实例调用对应方法。

**系统能力：** SystemCapability.Window.SessionManager

### startPiP

startPiP(): Promise&lt;void&gt;

启动画中画，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                     | 说明                 |
|------------------------|--------------------|
| Promise&lt;void&gt;    | 无返回结果的Promise对象。   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID      | 错误信息                                                   |
|------------|--------------------------------------------------------|
| 1300012    | If PiP window state is abnormal.                       |
| 1300013    | Create pip window failed.                              |
| 1300014    | Error when load PiP window content or show PiP window. |
| 1300015    | If window has created.                                 |

**示例：**

```ts
let promise : Promise<void> = pipController.startPiP();
promise.then(() => {
  console.info(`Succeeded in starting pip.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to start pip. Cause:${err.code}, message:${err.message}`);
});
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

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                             |
|---------|----------------------------------|
| 1300011 | Stop PiP window failed.          |
| 1300012 | If PiP window state is abnormal. |
| 1300015 | If window is stopping.           |

**示例：**

```ts
let promise : Promise<void> = pipController.stopPiP();
promise.then(() => {
  console.info(`Succeeded in stopping pip.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to stop pip. Cause:${err.code}, message:${err.message}`);
});
```

### setAutoStartEnabled

setAutoStartEnabled(enable: boolean): void

设置是否需要在返回桌面时自动启动画中画。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型        | 必填    | 说明                              |
|----------|-----------|-------|---------------------------------|
| enable   | boolean   | 是     | 如返回桌面时需自动启动画中画，则该参数配置为true，否则为false。若设置中自动启动画中画开关为关闭状态，就算该参数配置为true，应用返回桌面时也不会自动启动画中画窗口。  |

```ts
let enable: boolean = true;
pipController.setAutoStartEnabled(enable);
```

### updateContentSize

updateContentSize(width: number, height: number): void

当媒体源切换时，向画中画控制器更新媒体源尺寸信息。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型     | 必填  | 说明                                     |
|--------|--------|-----|----------------------------------------|
| width  | number | 是   | 表示媒体内容宽度，必须为大于0的数字，单位为px。用于更新画中画窗口比例。  |
| height | number | 是   | 表示媒体内容高度，必须为大于0的数字，单位为px。用于更新画中画窗口比例。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

```ts
let width: number = 540; // 假设当前内容宽度变为540px。
let height: number = 960; // 假设当前内容高度变为960px。
pipController.updateContentSize(width, height);
```

### on('stateChange')

on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void

开启画中画生命周期状态的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型        | 必填   | 说明                                                                                                |
|------------|-----------|------|---------------------------------------------------------------------------------------------------|
| type       | string    | 是    | 监听事件，固定为'stateChange'，即画中画生命周期状态变化事件。                                                             |
| callback   | function  | 是    | 回调生命周期状态变化事件以及原因：<br/>state：[PiPState](#pipstate)，表示当前画中画生命周期状态；<br/>reason：string，表示当前生命周期的切换原因。 |

```ts
pipController.on('stateChange', (state: pipWindow.PiPState, reason: string) => {
  let curState: string = '';
  switch (state) {
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = 'ABOUT_TO_START';
      break;
    case pipWindow.PiPState.STARTED:
      curState = 'STARTED';
      break;
    case pipWindow.PiPState.ABOUT_TO_STOP:
      curState = 'ABOUT_TO_STOP';
      break;
    case pipWindow.PiPState.STOPPED:
      curState = 'STOPPED';
      break;
    case pipWindow.PiPState.ABOUT_TO_RESTORE:
      curState = 'ABOUT_TO_RESTORE';
      break;
    case pipWindow.PiPState.ERROR:
      curState = 'ERROR';
      break;
    default:
      break;
  }
  console.info('stateChange:' + curState + ' reason:' + reason);
});
```

### off('stateChange')

off(type: 'stateChange'): void

关闭画中画生命周期状态的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名       | 类型            | 必填    | 说明                                     |
|-----------|---------------|-------|----------------------------------------|
| type      | string        | 是     | 监听事件，固定为'stateChange'，即画中画生命周期状态变化事件。  |

**示例：**

```ts
pipController.off('stateChange');
```

### on('controlPanelActionEvent')

on(type: 'controlPanelActionEvent', callback: ControlPanelActionEventCallback): void

开启画中画控制事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型         | 必填    | 说明                                                                                                                             |
|----------|------------|-------|--------------------------------------------------------------------------------------------------------------------------------|
| type     | string     | 是     | 监听事件，固定为'controlPanelActionEvent'，即画中画控制事件。                                                                                    |
| callback | [ControlPanelActionEventCallback](#controlpanelactioneventcallback12)  | 是     | 描述画中画控制面板动作事件回调。 |

```ts
pipController.on('controlPanelActionEvent', (event: pipWindow.PiPActionEventType, status?: number) => {
  switch (event) {
    case 'playbackStateChanged':
      if (status === 0) {
        //停止视频
      } else if (status === 1) {
        //播放视频
      }
      break;
    case 'nextVideo':
      // 切换到下一个视频
      break;
    case 'previousVideo':
      // 切换到上一个视频
      break;
    case 'fastForward':
      // 视频进度快进
      break;
    case 'fastBackward':
      // 视频进度后退
      break;
    default:
      break;
  }
  console.info('registerActionEventCallback, event:' + event);
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
pipController.off('controlPanelActionEvent');
```