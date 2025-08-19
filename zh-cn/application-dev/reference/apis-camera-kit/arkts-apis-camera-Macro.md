# Interface (Macro)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 19开始支持。

Macro 继承自 [MacroQuery](arkts-apis-camera-MacroQuery.md)。

提供使能微距能力的接口。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## enableMacro<sup>19+</sup>

enableMacro(enabled: boolean): void

使能当前的微距能力，需要在支持微距能力的情况下进行调用。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | 是   | 是否开启微距能力。true表示开启微距能力，false表示关闭微距能力。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID    | 错误信息                     |
|----------|--------------------------|
| 7400102  | Operation not allowed.   |
| 7400103  | Session not config.      |

**示例：**

```ts
function enableMacro(photoSession: camera.PhotoSession): void {
  let isSupported: boolean = photoSession.isMacroSupported();
  if (isSupported) {
    photoSession.enableMacro(true);
  }
}
```
