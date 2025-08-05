# 拖拽事件（系统接口）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

拖拽事件是指在用户界面中，当用户拖动某个对象（如文件、控件或元素）时触发的一系列事件。这些事件允许开发者自定义拖拽行为，实现诸如拖放、调整位置等功能。

>  **说明：**
>
>  从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 应用本身预置的资源文件（即应用在安装前的HAP包中已经存在的资源文件）仅支持本地应用内拖拽。
> 
> 本文仅介绍当前模块的系统接口，其他公开接口参见[拖拽事件](ts-universal-events-drag-drop.md)。

## DragEvent<sup>7+</sup>

拖拽事件信息。

### enableInternalDropAnimation<sup>20+</sup>

enableInternalDropAnimation(configuration: string): void

使用系统的内置动效，且该动效只有系统应用可使用。仅支持在onDrop阶段使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名    | 类型                                      | 必填 | 说明                               |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| configuration | string | 是   | 动效配置参数，字符串内容为json格式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../../errorcode-universal.md)和[drag-event(拖拽事件)](../errorcode-drag-event.md)错误码。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 202       | Permission verification failed. A non-system application calls a system API. |
| 401       | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed. |
| 801       | Capability not supported. Failed to call the API due to limited device capabilities. |
| 190003    | Operation not allowed for current pharse. |
