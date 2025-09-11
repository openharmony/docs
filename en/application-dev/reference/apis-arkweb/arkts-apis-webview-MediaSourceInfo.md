# Class (MediaSourceInfo)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhangyao75477-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements a **MediaSourceInfo** object to provide the information about the media source.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Attributes

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Read-Only| Optional| Description|
|------|------|------|------|------|
| type<sup>12+</sup> | [SourceType](./arkts-apis-webview-e.md#sourcetype12) | No| No| Type of the media source.|
| source<sup>12+</sup> | string | No| No| Address of the media source.|
| format<sup>12+</sup> | string | No| No| Format of the media source, which may be empty. You need to determine the format by yourself.|
