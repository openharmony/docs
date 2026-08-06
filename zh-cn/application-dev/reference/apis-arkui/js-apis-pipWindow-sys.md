# @ohos.PiPWindow (画中画窗口)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @betafringe007-->
<!--Designer: @taoweihua-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

该模块提供画中画基础功能，包括判断当前设备是否支持画中画功能，以及创建画中画控制器用于启动或停止画中画等。支持用户在进行其他操作时以小窗形式继续观看视频内容，提升多任务处理效率。适用于视频播放、视频通话、视频会议或车载影像场景下，以小窗（画中画）模式呈现内容。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 在<!--RP2-->OpenHarmony 6.0<!--RP2End-->之前，支持在Phone、Tablet设备使用画中画功能，其他设备不可用；从<!--RP2-->OpenHarmony 6.0<!--RP2End-->开始，支持在Phone、PC/2in1、Tablet设备使用画中画功能，其他设备不可用；从OpenHarmony 7.0.0开始，支持在Phone、PC/2in1、Tablet、Car设备使用画中画功能，其他设备不可用。
>
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.PiPWindow (画中画窗口)](js-apis-pipWindow.md)。

## 导入模块

```ts
import { PiPWindow } from '@kit.ArkUI';
```


## PiPTemplateType

画中画模板类型枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称            | 值   | 说明                                   |
|---------------|-----|--------------------------------------|
| VIDEO_DRIVE   | 4   | 表示车载影像画中画模板类型，系统依此加载车载影像模板。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0 开始，该接口支持在原子化服务中使用。<br> **设备行为差异：** 该模板类型在Car设备中正常调用，在其他设备中返回401错误码。|

## PiPController

画中画控制器实例。用于启动、停止画中画以及更新回调注册等。

下列API示例中都需先使用[PiPWindow.create()](js-apis-pipWindow.md#pipwindowcreate)方法获取到PiPController实例，再通过此实例调用对应方法。

**系统能力：** SystemCapability.Window.SessionManager

### isPiPSupported<sup>18+</sup>

isPiPSupported(): boolean

判断当前设备是否支持画中画功能。在启动画中画前，建议先调用此方法判断设备是否支持画中画功能，以避免在不支持的设备上调用画中画相关接口导致功能异常。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 18

**返回值：**

| 类型      | 说明                                  |
|----------|-------------------------------------|
| boolean  | 当前设备是否支持画中画功能。true表示支持，false表示不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                    |
|-------|---------------------------------------------|
| 202   | Not System App. Interface caller is not a system app. |
| 1300014    | PiP internal error.                                    |

**示例：**

```ts
try {
  if (!this.pipController) {
    return;
  }
  // pipController需通过PiPWindow.create()方法获取
  // 判断当前设备是否支持画中画功能
  let isSupported: boolean = this.pipController!.isPiPSupported();
  console.info('isPiPSupported: ' + isSupported);
} catch (exception) {
  console.error(`Failed to check if pip is supported. Code: ${exception.code}, message: ${exception.message}`);
}
```