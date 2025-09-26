# Drag Event (System API)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

A drag event refers to a sequence of events triggered in the UI when a user drags an object (such as a file, component, or element). These events allow you to customize drag and drop behaviors, enabling functionalities like drag and drop operations and position adjustments.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> The resource files preset in the application (that is, the resource files that are contained in the HAP file before the application is installed) can be dragged and dropped only within the application.
> 
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [Drag Event](ts-universal-events-drag-drop.md).

## DragEvent<sup>7+</sup>

Provides information about the drag event.

### enableInternalDropAnimation<sup>20+</sup>

enableInternalDropAnimation(configuration: string): void

Sets whether to enable the system's built-in drop animation effect. This API is available only to system applications and can only be used during the **onDrop** phase.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name   | Type                                     | Mandatory| Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| configuration | string | Yes  | Animation configuration parameters in JSON format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../../errorcode-universal.md) and [Drag Event Error Codes](../errorcode-drag-event.md).

| ID  | Error Message|
| --------- | ------- |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 801       | Capability not supported.|
| 190003    | Operation not allowed for current phase. |
