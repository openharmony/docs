# @ohos.multimodalAwareness.onScreen (屏上感知)(系统接口)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @wyxpku-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

本模块提供对屏上内容的感知能力。

> **说明：**
>
> 1. 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 2. 本模块为系统接口。

## 导入模块

```ts
import { onScreen } from '@kit.MultimodalAwarenessKit';
```

## Scenario

定义屏上内容的场景类型。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称                | 值   | 说明                   |
| ------------------- | ---- | ---------------------- |
| UNKNOWN | 0    | 表示屏上内容所处场景未知。 |
| ARTICLE | 1    | 表示屏上内容处于文章场景。 |

## EventType

定义控制事件的类型。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称                | 值   | 说明                   |
| ------------------- | ---- | ---------------------- |
| SCROLL_TO_HOOK  | 1    | 表示滚动到hook点事件。 |

## Paragraph

段落信息。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| hookId   | number | 否   | 是   | 段落对应的hook ID，每个主要段落的标识。 |
| chapterId   | number | 否   | 是   | 段落对应的chapter ID，每个子章节的标识。 |
| title    | string | 否   | 是   | 段落对应的标题。 |
| text    | string | 否   | 是   | 段落对应的内容。 |

## ContentOptions

屏上内容的获取选项。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| windowId   | number | 否   | 是   | 需要获取内容的窗口ID，不赋值或赋值undefined则默认获取全屏窗口。 |
| contentUnderstand   | boolean | 否   | 是   | 是否需要进行内容理解，默认为否。 |
| pageLink    | boolean | 否   | 是   | 是否获取复访链接，默认为否。 |
| textOnly    | boolean | 否   | 是   | 是否只获取文本并划分段落，默认为否。 |

## PageContent

屏上内容。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| windowId   | number | 否   | 否   | 获取到的屏上内容的窗口ID |
| sessionId   | number | 否   | 否   | 此次调用该接口的session ID，标识当次调用动作。 |
| bundleName    | string | 否   | 否   | 获取到的屏上内容的包名。 |
| scenario    | [Scenario](#scenario) | 否   | 是   | 获取到的屏上内容的场景。只有在options.contentUnderstand为true时，才会获取该属性。 |
| title    | string | 否   | 是   | 获取到的屏上内容的标题。只有在options.contentUnderstand为true时，才会获取该属性。 |
| content    | string | 否   | 是   | 获取到的屏上内容的正文。只有在options.contentUnderstand为true时，才会获取该属性。 |
| pageLink    | string | 否   | 是   | 获取到的屏上内容的复访链接。只有在options.pageLink为true时，才会获取该属性。 |
| paragraphs    | [Paragraph](#paragraph)[] | 否   | 是   | 获取到的文本段落信息。只有在options.textOnly为true时，才会获取该属性。 |

## ControlEvent

控制事件。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| windowId   | number | 否   | 否   | 控制事件要操作的窗口的window ID。 |
| sessionId   | number | 否   | 否   | 控制事件要操作的session ID。控制事件要操作的hook ID和该次会话对应的session ID都由某次会话获取的[PageContent](#pagecontent)提供。 |
| eventType    | [EventType](#eventtype) | 否   | 否   | 控制事件类型。 |
| hookId    | number | 否   | 是   | 控制事件对应的hook ID。控制事件要操作的hook ID和该次会话对应的session ID都由某次会话获取的[PageContent](#pagecontent)提供。 |

## OnscreenAwarenessCap<sup>23+</sup>

屏上感知能力（包括但不限于阅读场景感知、OCR识别等功能）。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| capList   | string[] | 否   | 是   | 表示能力集合，包含页面内容、页面链接、文本选择等能力。具体能力项见下表。|
| groupId | string | 否 | 是 | 业务分组ID。具体分组ID见下表。|

参数约束说明：<br>
用户可通过能力项（capList）或分组 ID（groupId）使用屏上感知功能。
* 逻辑关系：capList 与 groupId 互为补充必填项, 至少需提供其一，且不为空。<br>
* 校验规则：调用接口时，系统会单独检测capList和groupId。<br>
* 能力列表：按能力项或分组ID使用屏上感知功能，具体定义如下。
  * capList支持能力列表<br>
    按具体业务场景预设的能力，可进行单一订阅或者触发，如下：
    |capList支持能力列表|功能说明|
    | ---- | ------ |
    |Article|获取阅读场景的感知信息。|
    |ShortVideo|获取短视频场景的感知信息。|
    |Todo|获取待办场景的感知信息。|
    |Activity|获取基础服务的感知信息。|
    |UiImage|获取页面内子图信息。|
    |JumpContext|高亮跳转到指定上下文。|
    |QuickSnap|获取单次截屏信息。<br> **使用规格**：仅在capture接口使用，capList仅传递"QuickSnap"时生效，其他使用接口均返回401错误码。|
    |UiTree|获取页面内JSON树信息。<br> **起始版本：** 26.0.0|
    |InjectEvent|注入事件。<br> **起始版本：** 26.0.0|
    |CollectStrategy|获取屏幕采集策略。<br> **起始版本：** 26.0.0|

  * groupId支持能力列表<br>
    按业务场景预设的一组能力集合。可统一订阅业务场景，如下：

    |groupId支持能力列表|对应子项能力|功能说明|
    | ---- | ------ | ------|
    |SmartEdge|Article|获取阅读场景的感知信息。|
    |SmartEdge|ShortVideo|获取短视频场景的感知信息。|
    |SmartEdge|Todo|获取待办场景的感知信息。|
    |SmartEdge|Activity|获取基础服务的感知信息。|
    |CeliaMemory|Article|获取阅读场景的感知信息。|

## OnscreenAwarenessOptions<sup>23+</sup>

屏上感知参数列表，用于特定场景下获取屏上信息，如提供窗口ID用以采集应用界面内容和链接。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| parameters   | Record&lt;string, Object&gt; | 否   | 是   | 感知参数列表，参数结果是key-value数据对象。 |

## CollectStrategy<sup>23+</sup>

页面信息收集策略。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称                | 值   | 说明                   |
| ------------------- | ---- | ---------------------- |
| ALLOW | 1 << 0    | 应用支持采集。 |
| SPLIT_SCREEN | 1 << 1    | 应用分屏窗口采集策略。 |
| UNSUPPORTED_APP | 1 << 2  | 应用不支持自动采集。 |
| PRIVATE_WINDOW | 1 << 3  | 应用隐私窗口。 |
| ANCO_APP | 1 << 4 | 虚拟机应用，非鸿蒙应用。 |
| ALLOW_USER_CHANGE | 1 << 5  | 应用的采集策略可配置。|
| BUSINESS_APP | 1 << 6 | 应用数据可采集。 |
| FLOAT_SCREEN | 1 << 7  | 悬浮窗口。 |
| PIP_SCREEN | 1 << 8 | 画中画模式。 |
| LAUNCHER | 1 << 9 | 桌面应用。 |

## AwarenessItem<sup>23+</sup>

提供页面信息。包括：
* 页面基础信息，如页面内容、链接、截屏。
* 页面实体信息，如页面文章的标题、正文信息。
* 页面交互信息，如点击、滚动信息。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| itemInfo   | Record<string, Object> | 是   | 否   | 感知结果实体信息，包括内容、链接、截屏和其它实体信息。|

## EntityInfo<sup>23+</sup>

提供感知到的实体信息，包括内容、链接、图像和其他类型的实体。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| entityName   | string | 是   | 否   | 感知结果实体名称，固定内容。 |
| entityInfo   | Record<string, Object> | 是   | 否   | 感知结果实体信息，包括内容、链接、图像和其它实体。|

## OnscreenAwarenessInfo<sup>23+</sup>

屏上感知返回信息列表。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| resultCode  | number | 是   | 否   | 返回码，默认0 表示成功。 |
| timestamp   | number | 是   | 否   | 表示进入特定页面的时间戳。 |
| uid   | string | 是    | 是   | 表示应用UID。 |
| bundleName  | string | 是    | 是   | 应用包名。 |
| appName  | string | 是    | 是   | 应用名称。 |
| miniProgramId | string |是    | 是   | 小程序ID，如微信、支付宝等三方应用小程序ID。|
| miniProgramName | string | 是    | 是  | 小程序名称，三方应用小程序名称。 |
| appIndex   | number | 是    | 是   | 应用索引。 |
| pageId     | string | 是   | 是   | 应用页面ID。 |
| sampleId   | string | 是    | 是   | 采集记录ID。 |
| collectStrategy   | number | 是    | 是   | 页面采集策略，是 [CollectStrategy](#collectstrategy23) 的按位或运算组合。 |
| displayId   | number | 是    | 是   | 屏幕ID。 |
| windowId    | number | 是    | 是   | 窗口ID。 |
| languageInfo | string | 是  | 是 | 页面语言信息。|
| pageTags | string[] | 是  | 是 | 页面标签信息。|
| items  | [AwarenessItem](#awarenessitem23)[] | 是    | 是   | 数据项信息。|
| entityInfo  | [EntityInfo](#entityinfo23)[] | 是    | 是   | 实体信息。|

## ReadingScreenPermissionStatus<sup>23+</sup>

读取屏幕信息的授权状态。

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

| 名称 | 类型   | 只读 | 可选 | 说明                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| readingState  | number | 是    | 否   | 表示是否允许读屏。<br>0：不允许读屏。<br>1：允许读屏。 |
| readingCode   | number | 是    | 是   | 如果屏幕无法读取，将返回相应的状态码。 |


## onScreen.getPageContent

getPageContent(options?: [ContentOptions](#contentoptions)): Promise&lt;[PageContent](#pagecontent)&gt;

在需要抓取内容的窗口在桌面上时，调用该接口以获取屏上内容。

**需要权限**：ohos.permission.GET_SCREEN_CONTENT

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| options | [ContentOptions](#contentoptions)   | 否   | 获取屏上内容的选项，默认为不指定window ID，且其余选项均为false。 |

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000002 | The application or page is not supported. |
| 34000003 | The window ID is invalid. Possible causes: 1. window id is not passed when screen is split. 2. passed window id is not on screen or floating. |
| 34000004 | The page is not ready. |
| 34000006 | The request timed out. |

**示例**：

   ```ts
   import { onScreen } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let options: onScreen.ContentOptions = {
      contentUnderstand: true,
      pageLink: true
   };
   try {
      onScreen.getPageContent(options).then((pageContent: onScreen.PageContent) => {
         console.info("get page content succeed, bundleName = " + pageContent.bundleName);
      }).catch((err: BusinessError) => {
         console.error("get page content failed, errCode = " + err.code);
      });
   } catch (err) {
      console.error('get page content failed, errCode = ' + err.code);
   }
   ```

## onScreen.sendControlEvent

sendControlEvent(event: [ControlEvent](#controlevent)): Promise&lt;void&gt;

在需要控制的窗口在桌面上时，在调用[onScreen.getPageContent](#onscreengetpagecontent)后，根据其返回的段落信息，调用该接口发送屏上控制事件。

**需要权限**：ohos.permission.SIMULATE_USER_INPUT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**系统接口**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| event | [ControlEvent](#controlevent)   | 是   | 屏上控制事件。 |

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.SIMULATE_USER_INPUT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000005 | The target is not found. |

**示例**：

   ```ts
   import { onScreen } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let options: onScreen.ContentOptions = {
      contentUnderstand: true,
      textOnly: true
   };
   let event: onScreen.ControlEvent | undefined = undefined;
   try {
      onScreen.getPageContent(options).then((pageContent: onScreen.PageContent) => {
         if (pageContent.paragraphs != undefined && pageContent.paragraphs.length > 0 &&
            pageContent.paragraphs[0].hookId != undefined) {
            event = {
               windowId: pageContent.windowId,
               sessionId: pageContent.sessionId,
               hookId: pageContent.paragraphs[0].hookId,
               eventType: onScreen.EventType.SCROLL_TO_HOOK
            };
         }
      }).catch((err: BusinessError) => {
         console.error("get page content failed, errCode = " + err.code);
      });
   } catch (err) {
      console.error('invoke failed, errCode = ' + err.code);
   }
   if (event != undefined) {
      try {
         onScreen.sendControlEvent(event).catch((err: BusinessError) => {
            console.error("send control event failed, errCode =" + err.code);
         })
      } catch (err) {
         console.error('invoke failed, errCode = ' + err.code);
      }
   }
   ```

## onScreen.subscribe<sup>23+</sup>

subscribe(capability: OnscreenAwarenessCap, callback: Callback&lt;OnscreenAwarenessInfo[]&gt;, options?: OnscreenAwarenessOptions): void

开启屏幕内容主动感知，并订阅屏幕感知结果。

**需要权限**：

- API版本26+：ohos.permission.ONSCREEN_AWARENESS.
- API版本23-24：ohos.permission.GET_SCREEN_CONTENT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口在Phone和Tablet中可正常调用，在其他设备类型中返回801错误码。

**系统接口**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| capability | [OnscreenAwarenessCap](#onscreenawarenesscap23)   | 是   | 屏上感知能力列表。 |
| options|[OnscreenAwarenessOptions](#onscreenawarenessoptions23)| 否   | 屏上感知参数列表。|
| callback | Callback&lt;[OnscreenAwarenessInfo](#onscreenawarenessinfo23)[]&gt; | 是   | 回调函数，返回屏幕感知结果。返回的感知信息列表 OnscreenAwarenessInfo[] 最多同时返回2个感知信息项。|

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000002 | The application or page is not supported. |

**示例**：

   ```ts
   import onScreen from "@ohos.multimodalAwareness.onScreen";
   let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
      groupId: 'SmartEdge',
   }

   let onscreenAwarenessOptions: onScreen.OnscreenAwarenessOptions = {
      parameters: {
         "SmartEdge" : {
            "windowId":'102',
         }
      }
   }
   try {
      onScreen.subscribe(onscreenAwarenessCap, (info: onScreen.OnscreenAwarenessInfo[]) => {
         console.info(`subscribe resultCode: ${info[0].resultCode}`);
      }, onscreenAwarenessOptions);
   } catch (err) {
      console.error('subscribe failed, errCode = ' + err.code);
   }
   ```

## onScreen.unsubscribe<sup>23+</sup>

unsubscribe(capability: OnscreenAwarenessCap, callback?: Callback&lt;OnscreenAwarenessInfo[]&gt;): void

关闭屏幕内容主动感知，并取消订阅屏幕感知结果。

**需要权限**：

- API版本26+：ohos.permission.ONSCREEN_AWARENESS.
- API版本23-24：ohos.permission.GET_SCREEN_CONTENT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口在Phone和Tablet中可正常调用，在其他设备类型中返回801错误码。

**参数**：

| 参数名   | 类型                             | 必填 | 说明               |
| -------- | -------------------------------- | ---- | ---------------------------------------- |
| capability | [OnscreenAwarenessCap](#onscreenawarenesscap23)   | 是   | 屏上感知能力列表。 |
| callback | Callback&lt;[OnscreenAwarenessInfo](#onscreenawarenessinfo23)[]&gt; | 否   | 需取消的回调函数。省略则移除该感知能力的所有回调。返回的感知信息列表 OnscreenAwarenessInfo[] 最多同时返回2个感知信息项。|

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.ONSCREEN_AWARENESS or ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |

**示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
   groupId: 'SmartEdge'
}

try {
  onScreen.unsubscribe(onscreenAwarenessCap, (info: onScreen.OnscreenAwarenessInfo[]) => {
    console.info(`unsubscribe resultCode: ${info[0].resultCode}`);
  });
} catch (err) {
  console.error('unsubscribe failed, errCode = ' + err.code);
}
```

## onScreen.trigger<sup>23+</sup>

trigger(capability: OnscreenAwarenessCap, options?: OnscreenAwarenessOptions): Promise&lt;OnscreenAwarenessInfo&gt;

主动触发屏幕内容感知，获取当前屏幕感知结果。

**需要权限**：

- API版本26+：ohos.permission.ONSCREEN_AWARENESS.
- API版本23-24：ohos.permission.GET_SCREEN_CONTENT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口在Phone和Tablet中可正常调用，在其他设备类型中返回801错误码。

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| capability | [OnscreenAwarenessCap](#onscreenawarenesscap23)   | 是   | 屏上感知能力列表，支持列表见[OnscreenAwarenessCap](#onscreenawarenesscap23)。 |
| options|[OnscreenAwarenessOptions](#onscreenawarenessoptions23)| 否   | 屏上感知参数列表。|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[OnscreenAwarenessInfo](#onscreenawarenessinfo23)&gt; | Promise对象，返回屏幕感知结果。 |
  
**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.ONSCREEN_AWARENESS or ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000002 | The application or page is not supported. |

**示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
  capList: [
    'UiImage'
  ]
}

let onscreenAwarenessOptions: onScreen.OnscreenAwarenessOptions = {
  parameters: {
    "windowId": 102
  } as Record<string, Object>
}
try {
  let info: onScreen.OnscreenAwarenessInfo =
    await onScreen.trigger(onscreenAwarenessCap, onscreenAwarenessOptions);
  console.info(`trigger resultCode: ${info.resultCode}`);
} catch (err) {
  console.error('trigger failed, errCode = ' + err.code);
}
```

## onScreen.capture<sup>23+</sup>

capture(capability: OnscreenAwarenessCap, options?: OnscreenAwarenessOptions): Promise&lt;OnscreenAwarenessInfo[]&gt;

主动触发屏幕内容感知，获取页面信息。

**需要权限**：

- API版本26+：ohos.permission.ONSCREEN_AWARENESS.
- API版本23-24：ohos.permission.GET_SCREEN_CONTENT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口仅支持 Phone、Tablet 以及 Car 设备（Car 设备下需满足 capList 为 UiTree），在其余设备类型中调用将返回801错误码。

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| capability | [OnscreenAwarenessCap](#onscreenawarenesscap23)   | 是   | 屏上感知能力列表，具体见下面支持的能力列表。|
| options|[OnscreenAwarenessOptions](#onscreenawarenessoptions23)| 否   | 屏上感知参数列表。|

capture接口支持的capList能力列表，如下：
|capList能力列表|功能说明|
| ---- | ------ |
|UiImage|获取页面内子图信息。|
|QuickSnap|获取截屏信息。|
|UiTree|获取页面JSON树信息。<br> **起始版本：** 26.0.0|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[OnscreenAwarenessInfo](#onscreenawarenessinfo23)[]&gt; | Promise对象，返回屏幕感知结果。返回的感知信息列表 OnscreenAwarenessInfo[] 最多同时返回2个感知信息项。|
 
**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.ONSCREEN_AWARENESS or ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000002 | The application or page is not supported. |

**UiImage 示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
  capList: [
    'UiImage',
  ]
}
try {
  let info: onScreen.OnscreenAwarenessInfo[] = await onScreen.capture(onscreenAwarenessCap);
  console.error(`capture resultCode: ${info[0].resultCode}`);
} catch (err) {
  console.info(`capture failed, error: ${err}`);
}
```

**UiTree 示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
  capList: [
    'UiTree',
  ]
}
try {
  let info: onScreen.OnscreenAwarenessInfo[] = await onScreen.capture(onscreenAwarenessCap);
  console.error(`capture resultCode: ${info[0].resultCode}`);
} catch (err) {
  console.info(`capture failed, error: ${err}`);
}
```
## onScreen.interact<sup>23+</sup>

interact(capability: OnscreenAwarenessCap, options?: OnscreenAwarenessOptions): Promise&lt;OnscreenAwarenessInfo[]&gt;

主动触发屏幕行为交互，实现对界面行为的识别与行为反馈。例如：当capList能力列表为JumpContext时，点击后通过反馈信息精准跳转至指定段落并实现文字高亮。当capList能力列表为InjectEvent时，点击后执行相应的点击事件。

**需要权限**：

- API版本26+：ohos.permission.ONSCREEN_AWARENESS.
- API版本23-24：ohos.permission.GET_SCREEN_CONTENT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口仅支持Phone、Tablet以及Car设备（Car 设备下需满足 capList 为 InjectEvent），在其余设备类型中调用将返回801错误码。

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| capability | [OnscreenAwarenessCap](#onscreenawarenesscap23)   | 是   | 屏上感知能力列表，具体见下面支持的能力列表。|
| options|[OnscreenAwarenessOptions](#onscreenawarenessoptions23)| 否   | 屏上感知参数列表。|

interact接口支持的capList能力列表，如下：
|capList能力列表|功能说明|
| ---- | ------ |
|JumpContext|高亮跳转到指定上下文。|
|InjectEvent|注入事件。当capList能力列表为InjectEvent时，options字段为必填项，且其内容必须符合InjectEvent选项的规范（详见示例）。若options不符合规范，注入操作将失败，并返回错误码34000001。<br> **起始版本：** 26.0.0|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[OnscreenAwarenessInfo](#onscreenawarenessinfo23)[]&gt; | Promise对象，返回屏幕感知结果。返回的感知信息列表 OnscreenAwarenessInfo[] 最多同时返回2个感知信息项。|

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.ONSCREEN_AWARENESS or ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000002 | The application or page is not supported. |

**JumpContext 示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
  capList: [
    'JumpContext',
  ]
}

let onscreenAwarenessOptions: onScreen.OnscreenAwarenessOptions = {
  parameters: {
    "JumpContext" : {
      "pageId":'156',
      "textCompIdList": ['235'],
      "text": '文章开头'
    }
  }
}

try {
  let info: onScreen.OnscreenAwarenessInfo[] = await onScreen.interact(onscreenAwarenessCap, onscreenAwarenessOptions);
  console.error(`interact resultCode: ${info[0].resultCode}`);
} catch (err) {
  console.info(`interact failed, error: ${err}`);
}
```

**InjectEvent 示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
  capList: [
    'InjectEvent',    // （必填字段）注入事件能力：表示当前业务需要使用事件注入（如按键、点击、返回等系统事件注入）。
  ]
}

let onscreenAwarenessOptions: onScreen.OnscreenAwarenessOptions = {
  parameters: {
     // （必填字段）注入事件命令，用于向系统注入按键/操作事件。
    "InjectEvent": {
       // （injectEvent必填，其他可选）注入事件的具体内容：JSON字符串格式，包含组件类型、执行动作、参数。
      "injectEvent": '{"componentType":"","action":"back","params":{}}',
      "compId": ["0"],    // （可选）目标组件ID数组：指定要注入事件的组件。
      "windowId": 0,      // （可选）窗口ID：指定注入事件的目标窗口，0表示当前激活窗口。
      "displayId": -1     // （可选）显示设备ID：-1表示使用默认显示设备。
    }
  }
}

try {
  let info: onScreen.OnscreenAwarenessInfo[] = await onScreen.interact(onscreenAwarenessCap, onscreenAwarenessOptions);
  console.error(`interact resultCode: ${info[0].resultCode}`);
} catch (err) {
  console.info(`interact failed, error: ${err}`);
}
```

## onScreen.apperceive<sup>23+</sup>

apperceive(capability: OnscreenAwarenessCap, options?: OnscreenAwarenessOptions): Promise&lt;OnscreenAwarenessInfo[]&gt;

主动触发屏幕内容感知，获取屏幕内容进行快照分析。

**需要权限**：

- API版本26+：ohos.permission.ONSCREEN_AWARENESS.
- API版本23-24：ohos.permission.GET_SCREEN_CONTENT.

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口在Phone和Tablet中可正常调用，在其他设备类型中返回801错误码。

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| capability | [OnscreenAwarenessCap](#onscreenawarenesscap23)   | 是   | 屏上感知能力列表，具体见下面支持的能力列表。|
| options|[OnscreenAwarenessOptions](#onscreenawarenessoptions23)| 否   | 屏上感知参数列表。|

apperceive接口支持的groupId能力列表，如下：
|groupId能力列表|对应子项能力|功能说明|
| ---- | ------ | ------|
|SmartEdge|Article|获取阅读场景的感知信息。|
|SmartEdge|ShortVideo|获取短视频场景的感知信息。|
|SmartEdge|Todo|获取待办场景的感知信息。|
|SmartEdge|Activity|获取基础服务的感知信息。|
|CeliaMemory|Article|获取阅读场景的感知信息。|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[OnscreenAwarenessInfo](#onscreenawarenessinfo23)[]&gt; | Promise对象，返回屏幕感知结果。返回的感知信息列表 OnscreenAwarenessInfo[] 最多同时返回2个感知信息项。|

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.ONSCREEN_AWARENESS or ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |
| 34000002 | The application or page is not supported. |

**示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
let onscreenAwarenessCap: onScreen.OnscreenAwarenessCap = {
  groupId: 'SmartEdge'
}
try {
  let info: onScreen.OnscreenAwarenessInfo[] = await onScreen.apperceive(onscreenAwarenessCap);
  console.error(`apperceive resultCode: ${info[0].resultCode}`);
} catch (err) {
  console.info(`apperceive failed, error: ${err}`);
}
```

## onScreen.onReadingScreenPermissionListener<sup>23+</sup>

onReadingScreenPermissionListener(callback: Callback&lt;ReadingScreenPermissionStatus&gt;): void

开启屏幕内容访问权限监测，实时返回授权状态。

**需要权限**：ohos.permission.GET_SCREEN_CONTENT

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口在Phone和Tablet中可正常调用，在其他设备类型中返回801错误码。

**系统接口**：此接口为系统接口

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------- |
| callback | Callback&lt;[ReadingScreenPermissionStatus](#readingscreenpermissionstatus23)&gt; | 是   | 回调函数，返回读取屏幕信息的授权状态。|

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |

**示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
try {
   onScreen.onReadingScreenPermissionListener((info: onScreen.ReadingScreenPermissionStatus) => {
      console.info(`onReadingScreenPermissionListener succeeded, readingState: ${info.readingState}`);
   });
} catch (err) {
   console.error('onReadingScreenPermissionListener failed, errCode = ' + err.code);
}
```

## onScreen.offReadingScreenPermissionListener<sup>23+</sup>

offReadingScreenPermissionListener(callback?: Callback&lt;ReadingScreenPermissionStatus&gt;): void

关闭屏幕内容访问权限监测。

**需要权限**：ohos.permission.GET_SCREEN_CONTENT

**系统能力**：SystemCapability.MultimodalAwareness.OnScreenAwareness

**设备行为差异**：该接口在Phone和Tablet中可正常调用，在其他设备类型中返回801错误码。

**参数**：

| 参数名   | 类型                             | 必填 | 说明               |
| -------- | -------------------------------- | ---- | ---------------------------------------- |
| callback | Callback&lt;[ReadingScreenPermissionStatus](#readingscreenpermissionstatus23)&gt; | 否   | 回调函数。需要取消监听的回调函数，需与订阅时传入的回调函数一致。若不填，则取消当前监听该事件的所有回调函数。|

**错误码**：

以下错误码的详细介绍请参见[屏上感知错误码](errorcode-onScreen.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get page content forbidden by permission: ohos.permission.GET_SCREEN_CONTENT. |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities.|
| 34000001 | Service exception. |

**示例**：

```ts
import onScreen from "@ohos.multimodalAwareness.onScreen";
try {
  onScreen.offReadingScreenPermissionListener();
  console.info(`offReadingScreenPermissionListener succeeded.`);
} catch (err) {
  console.error('offReadingScreenPermissionListener failed, errCode = ' + err.code);
}
```
