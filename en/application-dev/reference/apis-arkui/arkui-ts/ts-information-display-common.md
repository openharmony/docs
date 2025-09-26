# Information Display APIs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyujie43-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @HelloCrease-->

Provides APIs for displaying information in [Gauge](ts-basic-components-gauge.md) and [DataPanel](ts-basic-components-datapanel.md) components.

>**NOTE**
>
>The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## MultiShadowOptions

Defines shadow style properties.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name         | Type| Read-Only| Optional| Description|
| ------------- | ------- | -- | -- | -------- |
| radius | number \| [Resource](ts-types.md#resource) | No| Yes| Shadow blur radius.<br>The default value varies by API version.<br>API version 10 and earlier versions: **5**<br>Since API version 11: **20**<br>Unit: vp.<br>The value of the number type must be greater than 0.<br>**NOTE**<br>A value less than or equal to 0 is handled as the default value.|
| offsetX | number \| [Resource](ts-types.md#resource) | No| Yes| X-axis offset.<br>There is no value range restriction for the number type.<br>Default value: **5**.<br>Unit: vp.|
| offsetY | number \| [Resource](ts-types.md#resource) | No| Yes| Y-axis offset.<br>There is no value range restriction for the number type.<br>Default value: **5**.<br>Unit: vp.|
