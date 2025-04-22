# @ohos.PiPWindow (画中画窗口)

该模块提供画中画基础功能，包括判断当前系统是否开启画中画功能，以及创建画中画控制器用于启动、停止画中画等。主要用于视频播放、视频通话或视频会议场景下，以小窗（画中画）模式呈现内容。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 需要在支持SystemCapability.Window.SessionManager能力的系统上使用该模块，<!--RP1-->参考[系统能力SystemCapability使用指南](../syscap.md)<!--RP1End-->。

## 导入模块

```ts
import { PiPWindow } from '@kit.ArkUI';
```

## PiPWindow.isPiPEnabled

isPiPEnabled(): boolean

用于判断当前系统是否支持画中画功能。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型       | 说明                                  |
|----------|-------------------------------------|
| boolean  | 当前系统是否开启画中画功能。true表示支持，false则表示不支持。 |

**示例：**

```ts
let enable: boolean = PiPWindow.isPiPEnabled();
console.info('isPipEnabled:' + enable);
```

## PiPWindow.create

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

创建画中画控制器，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |

**示例：**

```ts
//Index.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { BuilderNode, FrameNode, NodeController, PiPWindow, UIContext } from '@kit.ArkUI';

class Params {
  text: string = '';
  constructor(text: string) {
    this.text = text;
  }
}

// 开发者可以通过@Builder装饰器实现布局构建
@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(20)
      .fontColor(Color.Red)
  }
  .width('100%') // 宽度方向充满画中画窗口
  .height('100%') // 高度方向充满画中画窗口
}

// 开发者可通过继承NodeController实现自定义UI控制器
class TextNodeController extends NodeController {
  private message: string;
  private textNode: BuilderNode<[Params]> | null = null;
  constructor(message: string) {
    super();
    this.message = message;
  }

  // 通过BuilderNode加载自定义布局
  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message));
    return this.textNode.getFrameNode();
  }

  // 开发者可自定义该方法实现布局更新
  update(message: string) {
    console.log(`update message: ${message}`);
    if (this.textNode !== null) {
      this.textNode.update(new Params(message));
    }
  }
}

@Entry
@Component
struct Index {
  private message: string = 'createPiP';
  private pipController: PiPWindow.PiPController | undefined = undefined;
  private mXComponentController: XComponentController = new XComponentController(); // 开发者应使用该mXComponentController初始化XComponent: XComponent( {id: 'video', type: 'surface', controller: mXComponentController} )，保证XComponent的内容可以被迁移到画中画窗口。
  private nodeController: TextNodeController = new TextNodeController('this is custom UI');
  private navId: string = "page_1"; // 假设当前页面的导航id为page_1，详见PiPConfiguration定义，具体导航名称由开发者自行定义。
  private contentWidth: number = 800; // 假设当前内容宽度800px。
  private contentHeight: number = 600; // 假设当前内容高度600px。
  private para: Record<string, number> = { 'PropA': 47 };
  private localStorage: LocalStorage = new LocalStorage(this.para);
  private res: boolean = this.localStorage.setOrCreate('PropB', 121);
  private defaultWindowSizeType: number = 1; // 指定画中画第一次拉起窗口为小窗口。
  private config: PiPWindow.PiPConfiguration = {
    context: this.getUIContext().getHostContext() as Context,
    componentController: this.mXComponentController,
    navigationId: this.navId,
    templateType: PiPWindow.PiPTemplateType.VIDEO_PLAY,
    contentWidth: this.contentWidth,
    contentHeight: this.contentHeight,
    controlGroups: [PiPWindow.VideoPlayControlGroup.VIDEO_PREVIOUS_NEXT],
    customUIController: this.nodeController, // 可选，如果需要在画中画显示内容上方展示自定义UI，可设置该参数。
    localStorage: this.localStorage, // 可选，如果需要跟踪主窗实例，可设置此参数。
    defaultWindowSizeType: this.defaultWindowSizeType, // 可选，如果需要配置默认启动窗口档位，可设置此参数。
  };

  createPiP() {
    let promise: Promise<PiPWindow.PiPController> = PiPWindow.create(this.config);
    promise.then((data: PiPWindow.PiPController) => {
      this.pipController = data;
      console.info(`Succeeded in creating pip controller. Data:${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
    });
  }

  //仅用于功能测试，实际开发过程中开发者按功能需求设计组件
  build() {
    RelativeContainer() {
      Button(this.message)
        .onClick(() => {
          this.createPiP();
        })
    }
  }
}
```

## PiPWindow.create<sup>12+</sup>

create(config: PiPConfiguration, contentNode: typeNode.XComponent): Promise&lt;PiPController&gt;

通过typeNode创建画中画控制器，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**
 
| 参数名          | 类型                                       | 必填        | 说明                                                                                                                                                                                                                                     |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| config       | [PiPConfiguration](#pipconfiguration)    | 是         | 创建画中画控制器的参数。该参数不能为空，并且构造该参数的context不能为空。构造该参数时，如果指定了templateType，需保证templateType是[PiPTemplateType](#piptemplatetype)类型；如果指定了controlGroups，需保证controlGroups与templateType匹配，详见[PiPControlGroup](#pipcontrolgroup12)。 |
| contentNode       | [typeNode.XComponent](js-apis-arkui-frameNode.md#xcomponent12)    | 是         | 用于渲染画中画窗口中的内容。该参数不能为空。|

**返回值：**

| 类型                                                         | 说明                       |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise对象。返回当前创建的画中画控制器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                         |
|-------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |

**示例：**

```ts
//Index.ts
import { BusinessError } from '@kit.BasicServicesKit';
import { PiPWindow, UIContext } from '@kit.ArkUI';
import { typeNode } from '@ohos.arkui.node';

@Entry
@Component
struct Index {
  private message = 'createPiP'
  private pipController: PiPWindow.PiPController | undefined = undefined;
  private xComponentController: XComponentController = new XComponentController();
  private context: UIContext | undefined = this.getUIContext(); // 可传入UIContext或在布局中通过this.getUIContext()为context赋有效值
  private contentWidth: number = 800; // 假设当前内容宽度800px。
  private contentHeight: number = 600; // 假设当前内容高度600px。
  private config: PiPWindow.PiPConfiguration = {
    context: this.getUIContext().getHostContext() as Context,
    componentController: this.xComponentController,
    templateType: PiPWindow.PiPTemplateType.VIDEO_PLAY,
    contentWidth: this.contentWidth,
    contentHeight: this.contentHeight,
  };
  private options: XComponentOptions = {
    type: XComponentType.SURFACE,
    controller: this.xComponentController
  }
  private xComponent = typeNode.createNode(this.context, 'XComponent', this.options);

  createPiP() {
    let promise: Promise<PiPWindow.PiPController> = PiPWindow.create(this.config, this.xComponent);
    promise.then((data: PiPWindow.PiPController) => {
      this.pipController = data;
      console.info(`Succeeded in creating pip controller. Data:${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
    });
  }

  //仅用于功能测试，实际开发过程中开发者按功能需求设计组件
  build() {
    RelativeContainer() {
      Button(this.message)
        .onClick(() => {
          this.createPiP();
        })
    }
  }
}
```

## PiPConfiguration

创建画中画控制器时的参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                  | 类型                                                                         | 必填  | 说明                                                                                                                                                                                                                                                                                                                                        |
|---------------------|----------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context             | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 表示上下文环境。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                  |
| componentController | [XComponentController](arkui-ts/ts-basic-components-xcomponent.md#xcomponentcontroller) | 是   | 表示原始[XComponent](arkui-ts/ts-basic-components-xcomponent.md)控制器。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                      |
| navigationId        | string                                                                     | 否   | 当前page导航id。<br/>1、UIAbility使用[Navigation](arkui-ts/ts-basic-components-navigation.md)管理页面，需要设置Navigation控件的id属性，并将该id设置给画中画控制器，确保还原场景下能够从画中画窗口恢复到原页面。<br/>2、UIAbility使用[Router](js-apis-router.md)管理页面时，无需设置navigationId。<br/>3、UIAbility只有单页面时，无需设置navigationId，还原场景下也能够从画中画窗口恢复到原页面。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| templateType        | [PiPTemplateType](#piptemplatetype)                                        | 否   | 模板类型，用以区分视频播放、视频通话或视频会议。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                  |
| contentWidth        | number                                                                     | 否   | 原始内容宽度，单位为px。用于确定画中画窗口比例。当[使用typeNode的方式](#pipwindowcreate12)创建PiPController时，不传值则默认为1920。当[不使用typeNode的方式](#pipwindowcreate)创建PiPController时，不传值则默认为[XComponent](arkui-ts/ts-basic-components-xcomponent.md)组件的宽度。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                 |
| contentHeight       | number                                                                     | 否   | 原始内容高度，单位为px。用于确定画中画窗口比例。用于确定画中画窗口比例。当[使用typeNode的方式](#pipwindowcreate12)创建PiPController时，不传值则默认为1080。当[不使用typeNode的方式](#pipwindowcreate)创建PiPController时，不传值则默认为[XComponent](arkui-ts/ts-basic-components-xcomponent.md)组件的高度。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                 |
| controlGroups<sup>12+</sup>       | Array<[PiPControlGroup](#pipcontrolgroup12)>                               | 否   | 画中画控制面板的可选控件组列表，应用可以对此进行配置以决定是否显示。如果应用没有配置，面板将显示基础控件（如视频播放控件组的播放/暂停控件）；如果应用选择配置，则最多可以选择三个控件。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                 |
| customUIController<sup>12+</sup>      | [NodeController](js-apis-arkui-nodeController.md)           | 否   | 用于实现在画中画界面内容上方展示自定义UI功能。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                           |
| localStorage<sup>17+</sup>      | [LocalStorage](../../ui/state-management/arkts-localstorage.md)           | 否   | 页面级别的UI状态存储单元，多实例下可用来跟踪主窗实例。<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                           |
| defaultWindowSizeType<sup>18+</sup>| number                                                                     | 否   |  画中画第一次拉起窗口大小。<br/>0：代表不设置大小。按照上次画中画关闭前的大小启动；<br/>1：代表小窗；<br/>2：代表大窗；<br/>不传值则为默认值0。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                 |

## PiPWindowSize<sup>15+</sup>

画中画窗口大小。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 可读 | 可写 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | 是   | 否   | 窗口宽度，单位为px，该参数应为正整数，不大于屏幕宽。 |
| height | number   | 是   | 否   | 窗口高度，单位为px，该参数应为正整数，不大于屏幕高。 |
| scale  | number   | 是   | 否   | 窗口缩放比，显示大小相对于width和height的缩放比，该参数为浮点数，取值范围大于0.0，小于等于1.0。等于1表示与width和height一样大。 |

## PiPWindowInfo<sup>15+</sup>

画中画窗口信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 可读 | 可写 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| windowId  | number   | 是   | 否   | 画中画窗口ID。 |
| size  | [PiPWindowSize](#pipwindowsize15)  | 是   | 否   | 画中画窗口大小。 |

## PiPTemplateType

画中画媒体类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称            | 值   | 说明                                   |
|---------------|-----|--------------------------------------|
| VIDEO_PLAY    | 0   | 表示将要切换为画中画播放的媒体类型是视频，系统依此加载视频播放模板。   |
| VIDEO_CALL    | 1   | 表示将要切换为画中画播放的媒体类型是视频通话，系统依此加载视频通话模板。 |
| VIDEO_MEETING | 2   | 表示将要切换为画中画播放的媒体类型是视频会议，系统依此加载视频会议模板。 |
| VIDEO_LIVE    | 3   | 表示将要切换为画中画播放的媒体类型是直播，系统依此加载直播模板。     |

## PiPState

画中画生命周期状态枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

type PiPControlGroup = VideoPlayControlGroup | VideoCallControlGroup | VideoMeetingControlGroup | VideoLiveControlGroup

画中画控制面板的可选控件组列表，应用可以配置是否显示可选控件。默认情况下控制面板只显示基础控件（如视频播放控件组的播放/暂停控件）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                                              | 说明          |
|-------------------------------------------------|-------------|
| [VideoPlayControlGroup](#videoplaycontrolgroup12)     | 视频播放控件组。 |
| [VideoCallControlGroup](#videocallcontrolgroup12)       | 视频通话控件组。 |
| [VideoMeetingControlGroup](#videomeetingcontrolgroup12) | 视频会议控件组。 |
| [VideoLiveControlGroup](#videolivecontrolgroup12)     | 视频直播控件组。 |


## VideoPlayControlGroup<sup>12+</sup>

视频播放控件组枚举。仅当[PiPTemplateType](#piptemplatetype)为VIDEO_PLAY时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| VIDEO_PREVIOUS_NEXT       | 101   | 视频上一个/下一个控件组。<br/>与视频快进/后退控件组为互斥控件组。如添加视频快进/后退控件组，则不可添加该控件组。           |
| FAST_FORWARD_BACKWARD    | 102   | 视频快进/后退控件组。<br/>与视频上一个/下一个控件组为互斥控件组。如添加视频上一个/下一个控件组，则不可添加该控件组。           |

## VideoCallControlGroup<sup>12+</sup>

视频通话控件组枚举。仅当[PiPTemplateType](#piptemplatetype) 为VIDEO_CALL时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| MICROPHONE_SWITCH       | 201   | 打开/关闭麦克风控件组。            |
| HANG_UP_BUTTON    | 202   | 挂断控件组。           |
| CAMERA_SWITCH    | 203   | 打开/关闭摄像头控件组。            |
| MUTE_SWITCH    | 204   | 静音控件组。            |

## VideoMeetingControlGroup<sup>12+</sup>

视频会议控件组枚举。仅当[PiPTemplateType](#piptemplatetype) 为VIDEO_MEETING时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| HANG_UP_BUTTON       | 301   | 挂断控件组。          |
| CAMERA_SWITCH    | 302   | 打开/关闭摄像头控件组。           |
| MUTE_SWITCH    | 303   | 静音控件组。            |
| MICROPHONE_SWITCH       | 304   | 打开/关闭麦克风控件组。            |

## VideoLiveControlGroup<sup>12+</sup>

视频直播控件组枚举。仅当[PiPTemplateType](#piptemplatetype) 为VIDEO_LIVE时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| VIDEO_PLAY_PAUSE     | 401   |   播放/暂停直播控件组。 |
| MUTE_SWITCH         | 402   | 静音控件组。            |

## PiPActionEventType

type PiPActionEventType = PiPVideoActionEvent | PiPCallActionEvent | PiPMeetingActionEvent | PiPLiveActionEvent

画中画控制面板控件动作事件类型，支持以下四种。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                                              | 说明          |
|-------------------------------------------------|-------------|
| [PiPVideoActionEvent](#pipvideoactionevent)     | 视频播放控制面板控件事件类型。 |
| [PiPCallActionEvent](#pipcallactionevent)       | 视频通话控制面板控件事件类型。 |
| [PiPMeetingActionEvent](#pipmeetingactionevent) | 视频会议控制面板控件事件类型。 |
| [PiPLiveActionEvent](#pipliveactionevent)       | 直播控制面板控件事件类型。   |

## PiPVideoActionEvent

type PiPVideoActionEvent = 'playbackStateChanged' | 'nextVideo' | 'previousVideo' | 'fastForward' | 'fastBackward'

视频播放控制事件类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                         | 说明                                      |
| ---------------------------- | ----------------------------------------- |
| 'playbackStateChanged'       | 播放状态发生了变化。                      |
| 'nextVideo'                  | 播放下一个视频。                          |
| 'previousVideo'              | 播放上一个视频。                          |
| 'fastForward'<sup>12+</sup>  | 视频进度快进。从API version 12 开始支持。 |
| 'fastBackward'<sup>12+</sup> | 视频进度后退。从API version 12 开始支持。 |

## PiPCallActionEvent

type PiPCallActionEvent = 'hangUp' | 'micStateChanged' | 'videoStateChanged' | 'voiceStateChanged'

视频通话控制事件类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                | 说明               |
| ------------------- | ------------------ |
| 'hangUp'             | 挂断视频通话。     |
| 'micStateChanged'   | 打开或关闭麦克风。 |
| 'videoStateChanged' | 打开或关闭摄像头。 |
| 'voiceStateChanged'<sup>12+</sup> | 静音或解除静音。   |


## PiPMeetingActionEvent

type PiPMeetingActionEvent = 'hangUp' | 'voiceStateChanged' | 'videoStateChanged' | 'micStateChanged'

视频会议控制事件类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                | 说明               |
| ------------------- | ------------------ |
| 'hangUp'            | 挂断视频会议。     |
| 'voiceStateChanged' | 静音或解除静音。   |
| 'videoStateChanged' | 打开或关闭摄像头。 |
| 'micStateChanged'<sup>12+</sup>   | 打开或关闭麦克风。 |


## PiPLiveActionEvent

type PiPLiveActionEvent = 'playbackStateChanged' | 'voiceStateChanged'

直播控制事件类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 类型                   | 说明             |
| ---------------------- | ---------------- |
| 'playbackStateChanged' | 播放或暂停直播。 |
| 'voiceStateChanged'<sup>12+</sup> | 静音或解除静音。   |


## PiPControlStatus<sup>12+</sup>

控制面板控件状态枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                   | 值   | 说明                    |
|----------------------|-----|-----------------------|
| PLAY       | 1   | 播放。          |
| PAUSE    | 0   | 暂停。           |
| OPEN    | 1   | 打开。            |
| CLOSE       | 0   | 关闭。          |

## PiPControlType<sup>12+</sup>

控制面板控件类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                | 值   | 说明                                   |
|-------------------|-----|--------------------------------------|
| VIDEO_PLAY_PAUSE  | 0   | 播放/暂停控件。   |
| VIDEO_PREVIOUS    | 1   | 视频上一个控件。 |
| VIDEO_NEXT        | 2   | 视频下一个控件。 |
| FAST_FORWARD      | 3   | 视频快进控件     |
| FAST_BACKWARD     | 4   | 视频快退控件。   |
| HANG_UP_BUTTON           | 5   | 挂断控件。 |
| MICROPHONE_SWITCH | 6  | 打开/关闭麦克风控件。 |
| CAMERA_SWITCH     | 7   | 打开/关闭摄像头控件。     |
| MUTE_SWITCH       | 8   | 打开/关闭静音控件。     |


## ControlPanelActionEventCallback<sup>12+</sup>

type ControlPanelActionEventCallback = (event: PiPActionEventType, status?: number) => void

描述画中画控制面板控件动作事件回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名                       | 类型           | 必填    | 说明                                |
|--------------------------|--------------|--------------|-----------------------------------|
| event       |  [PiPActionEventType](#pipactioneventtype)       | 是 | 回调画中画控制面板控件动作事件类型。<br/>应用依据控件动作事件做相应处理，如触发'playbackStateChanged'事件时，需要开始或停止视频。 |
| status | number | 否 | 表示可切换状态的控件当前的状态，如具备打开和关闭两种状态的麦克风控件组、摄像头控件组和静音控件组，打开为1，关闭为0。其余控件该参数返回默认值-1。 |

## ControlEventParam<sup>12+</sup>

画中画控制面板控件动作回调的参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                       | 类型           | 必填    | 说明                                                                                                                                |
|--------------------------|--------------|--------------|-----------------------------------------------------------------------------------------------------------------------------------|
| controlType       |  [PiPControlType](#pipcontroltype12)      | 是 | 回调画中画控制面板控件动作事件类型。应用依据控件类型做相应处理，如视频模板中暂停/播放控件被点击时，需要开始或停止视频。                                                                      |
| status | [PiPControlStatus](#pipcontrolstatus12) | 否 | 表示可切换状态的控件当前的状态，如具备打开和关闭两种状态的麦克风控件组、摄像头控件组和静音控件组，打开为PiPControlStatus.PLAY，关闭为PiPControlStatus.PAUSE。如不具备开/关和播放/暂停状态的挂断控件默认返回值为-1。 |

## PiPController

画中画控制器实例。用于启动、停止画中画以及更新回调注册等。

下列API示例中都需先使用[PiPWindow.create()](#pipwindowcreate)方法获取到PiPController实例，再通过此实例调用对应方法。

**系统能力：** SystemCapability.Window.SessionManager

### startPiP

startPiP(): Promise&lt;void&gt;

启动画中画，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                     | 说明                 |
|------------------------|--------------------|
| Promise&lt;void&gt;    | 无返回结果的Promise对象。   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID    | 错误信息                                                |
|------------|--------------------------------------------------------|
| 1300012    | The PiP window state is abnormal.                      |
| 1300013    | Failed to create the PiP window.                       |
| 1300014    | PiP internal error.                                    |
| 1300015    | Repeated PiP operation.                                |

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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                   | 说明                  |
|----------------------|---------------------|
| Promise&lt;void&gt;  | 无返回结果的Promise对象。    |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                          |
|---------|-----------------------------------|
| 1300011 | Failed to destroy the PiP window. |
| 1300012 | The PiP window state is abnormal. |
| 1300015 | Repeated PiP operation.           |

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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型        | 必填    | 说明                              |
|----------|-----------|-------|---------------------------------|
| enable   | boolean   | 是     | 如返回桌面时需自动启动画中画，则该参数配置为true，否则为false。若设置中自动启动画中画开关为关闭状态，就算该参数配置为true，应用返回桌面时也不会自动启动画中画窗口。  |

**示例：**

```ts
let enable: boolean = true;
pipController.setAutoStartEnabled(enable);
```

### updateContentSize

updateContentSize(width: number, height: number): void

当媒体源切换时，向画中画控制器更新媒体源尺寸信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
let width: number = 540; // 假设当前内容宽度变为540px。
let height: number = 960; // 假设当前内容高度变为960px。
pipController.updateContentSize(width, height);
```

### updatePiPControlStatus<sup>12+</sup>
updatePiPControlStatus(controlType: PiPControlType, status: PiPControlStatus): void

更新控制面板控件功能状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型     | 必填  | 说明                                                                                                 |
|--------|--------|-----|----------------------------------------------------------------------------------------------------|
| controlType  | [PiPControlType](#pipcontroltype12)  | 是   | 表示画中画控制面板控件类型。目前仅支持VIDEO_PLAY_PAUSE、MICROPHONE_SWITCH、CAMERA_SWITCH和MUTE_SWITCH这几种控件类型，传入其他控件类型无效。 |
| status | [PiPControlStatus](#pipcontrolstatus12)  | 是   | 表示画中画控制面板控件状态。                                                                                     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed |

**示例：**

```ts
let controlType: PiPWindow.PiPControlType = PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE; // 视频播放控制面板中播放/暂停控件。
let status: PiPWindow.PiPControlStatus = PiPWindow.PiPControlStatus.PLAY; // 视频播放控制面板中播放/暂停控件为播放状态。
pipController.updatePiPControlStatus(controlType, status);
```

### updateContentNode<sup>18+</sup>
updateContentNode(contentNode: typeNode.XComponent): Promise&lt;void&gt;

更新画中画节点内容。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名          | 类型                                       | 必填        | 说明                                                                                                                                                                                                                                     |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| contentNode       | [typeNode.XComponent](js-apis-arkui-frameNode.md#xcomponent12)    | 是         | 用于渲染画中画窗口中的内容。该参数不能为空。|

**返回值：**

| 类型                   | 说明                  |
|----------------------|---------------------|
| Promise&lt;void&gt;  | 无返回结果的Promise对象。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |

**示例：**

```ts
import { typeNode, UIContext } from '@kit.ArkUI';

let context: UIContext | undefined = undefined; // 可传入UIContext或在布局中通过this.getUIContext()为context赋有效值

try {
  let contentNode = typeNode.createNode(context, "XComponent");
  pipController.updateContentNode(contentNode);
} catch (exception) {
  console.error(`Failed to update content node. Cause: ${exception.code}, message: ${exception.message}`);
}
```

### setPiPControlEnabled<sup>12+</sup>
setPiPControlEnabled(controlType: PiPControlType, enabled: boolean): void

更新控制面板控件使能状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名         | 类型     | 必填  | 说明                                     |
|-------------|--------|-----|----------------------------------------|
| controlType | [PiPControlType](#pipcontroltype12)  | 是   | 表示画中画控制面板控件类型。  |
| enabled     | boolean | 是   | 表示画中画控制面板控件使能状态。true表示控件为可使用状态，false则为禁用状态。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed |

**示例：**

```ts
let controlType: PiPWindow.PiPControlType = PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE; // 视频播放控制面板中播放/暂停控件。
let enabled: boolean = false; // 视频播放控制面板中播放/暂停控件为禁用状态。
pipController.setPiPControlEnabled(controlType, enabled);
```
### getPiPWindowInfo<sup>15+</sup>
getPiPWindowInfo(): Promise&lt;[PiPWindowInfo](#pipwindowinfo15)&gt;

获取画中画窗口信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                   | 说明                  |
|----------------------|---------------------|
| Promise&lt;[PiPWindowInfo](#pipwindowinfo15)&gt;  | Promise对象，返回当前画中画窗口信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                        |
|-------|-------------------------------------------------------------------------------------------------------------|
| 801   | Capability not supported. Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |

**示例：**

```ts
let pipWindowInfo: PiPWindow.PiPWindowInfo | undefined = undefined;
try {
  let promise : Promise<PiPWindow.PiPWindowInfo> = pipController.getPiPWindowInfo();
  promise.then((data) => {
    pipWindowInfo = data;
    console.info('Success in get pip window info. Info: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get pip window info. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to get pip window info. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('stateChange')

on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void

开启画中画生命周期状态的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型        | 必填   | 说明                                                                                                |
|------------|-----------|------|---------------------------------------------------------------------------------------------------|
| type       | string    | 是    | 监听事件，固定为'stateChange'，即画中画生命周期状态变化事件。                                                             |
| callback   | function  | 是    | 回调生命周期状态变化事件以及原因。<br/>state：[PiPState](#pipstate)，表示当前画中画生命周期状态。<br/>reason：string，表示当前生命周期的切换原因。 |

**示例：**

```ts
pipController.on('stateChange', (state: PiPWindow.PiPState, reason: string) => {
  let curState: string = '';
  switch (state) {
    case PiPWindow.PiPState.ABOUT_TO_START:
      curState = 'ABOUT_TO_START';
      break;
    case PiPWindow.PiPState.STARTED:
      curState = 'STARTED';
      break;
    case PiPWindow.PiPState.ABOUT_TO_STOP:
      curState = 'ABOUT_TO_STOP';
      break;
    case PiPWindow.PiPState.STOPPED:
      curState = 'STOPPED';
      break;
    case PiPWindow.PiPState.ABOUT_TO_RESTORE:  
      curState = 'ABOUT_TO_RESTORE';
      break;
    case PiPWindow.PiPState.ERROR:
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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

开启画中画控制面板控件动作事件的监听。推荐使用[on('controlEvent')](#oncontrolevent12)来开启画中画控制面板控件动作事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型         | 必填    | 说明                                                |
|----------|------------|-------|---------------------------------------------------|
| type     | string     | 是     | 监听事件，固定为'controlPanelActionEvent'，即画中画控制面板控件动作事件。 |
| callback | [ControlPanelActionEventCallback](#controlpanelactioneventcallback12)  | 是     | 描述画中画控制面板控件动作事件回调。                                |

**示例：**

```ts
pipController.on('controlPanelActionEvent', (event: PiPWindow.PiPActionEventType, status?: number) => {
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

### on('controlEvent')<sup>12+</sup>

on(type: 'controlEvent', callback: Callback&lt;ControlEventParam&gt;): void

开启画中画控制面板控件动作事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                                                  | 必填    | 说明                                     |
|----------|-----------------------------------------------------|-------|----------------------------------------|
| type     | string                                              | 是     | 监听事件，固定为'controlEvent'，即画中画控制面板控件动作事件。 |
| callback | Callback<[ControlEventParam](#controleventparam12)> | 是     | 描述画中画控制面板控件动作事件回调。                     |

**示例：**

```ts
pipController.on('controlEvent', (control) => {
  switch (control.controlType) {
    case PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE:
      if (control.status === PiPWindow.PiPControlStatus.PAUSE) {
        //停止视频
      } else if (control.status === PiPWindow.PiPControlStatus.PLAY) {
        //播放视频
      }
      break;
    case PiPWindow.PiPControlType.VIDEO_NEXT:
      // 切换到下一个视频
      break;
    case PiPWindow.PiPControlType.VIDEO_PREVIOUS:
      // 切换到上一个视频
      break;
    case PiPWindow.PiPControlType.FAST_FORWARD:
      // 视频进度快进
      break;
    case PiPWindow.PiPControlType.FAST_BACKWARD:
      // 视频进度后退
      break;
    default:
      break;
  }
  console.info('registerControlEventCallback, controlType:' + control.controlType + ', status' + control.status);
});
```

### off('controlPanelActionEvent')

off(type: 'controlPanelActionEvent'): void

关闭画中画控制面板控件动作事件的监听。推荐使用[off('controlEvent')](#offcontrolevent12)来关闭画中画控制面板控件动作事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型                           | 必填   | 说明                                            |
|------------|------------------------------|------|-----------------------------------------------|
| type       | string                       | 是    | 监听事件，固定为'controlPanelActionEvent'，即画中画控制面板控件动作事件。   |

**示例：**

```ts
pipController.off('controlPanelActionEvent');
```

### off('controlEvent')<sup>12+</sup>

off(type: 'controlEvent', callback?: Callback&lt;ControlEventParam&gt;): void

关闭画中画控制面板控件动作事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名        | 类型                                                  | 必填 | 说明                                                     |
|------------|-----------------------------------------------------|----|--------------------------------------------------------|
| type       | string                                              | 是  | 监听事件，固定为'controlEvent'，即画中画控制面板控件动作事件。                 |
| callback | Callback<[ControlEventParam](#controleventparam12)> | 否  | 描述画中画控制面板控件动作事件回调。如果不传该参数时，解除type为'controlEvent'的所有回调。 |

**示例：**

```ts
pipController.off('controlEvent', () => {});
```

### on('pipWindowSizeChange')<sup>15+</sup>

on(type: 'pipWindowSizeChange', callback: Callback&lt;PiPWindowSize&gt;): void

开启画中画窗口尺寸变化事件的监听。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                                          | 必填    | 说明                                                |
|----------|---------------------------------------------|-------|---------------------------------------------------|
| type     | string                                      | 是     | 监听事件，固定为'pipWindowSizeChange'，即画中画窗口尺寸变化事件。 |
| callback | Callback<[PiPWindowSize](#pipwindowsize15)> | 是     | 回调函数。返回当前画中画窗口的尺寸。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |    

**示例：**

```ts
try {
  pipController.on('pipWindowSizeChange', (size: PiPWindow.PiPWindowSize) => {
    console.info('Succeeded in enabling the listener for pip window size changes. size: ' + JSON.stringify(size));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for pip window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('pipWindowSizeChange')<sup>15+</sup>

off(type: 'pipWindowSizeChange', callback?: Callback&lt;PiPWindowSize&gt;): void

关闭画中画窗口尺寸变化事件的监听。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型         | 必填 | 说明                                                                  |
|----------|------------|----|---------------------------------------------------------------------|
| type     | string     | 是  | 监听事件，固定为'pipWindowSizeChange'，即画中画窗口尺寸变化事件。                         |
| callback | Callback<[PiPWindowSize](#pipwindowsize15)> | 否  | 回调函数。返回当前画中画窗口的尺寸。如果传入参数，则关闭该监听。如果未传入参数，解除type为'pipWindowSizeChange'的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |    

**示例：**

```ts
const callback = (size: PiPWindow.PiPWindowSize) => {
  // ...
}
try {
  // 通过on接口开启监听
  pipController.on('pipWindowSizeChange', callback);
} catch (exception) {
  console.error(`Failed to enable the listener for pip window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}

try {
  // 关闭指定callback的监听
  pipController.off('pipWindowSizeChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  pipController.off('pipWindowSizeChange');
} catch (exception) {
  console.error(`Failed to disable the listener for pip window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```