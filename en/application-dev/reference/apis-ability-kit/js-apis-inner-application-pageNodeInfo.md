# PageNodeInfo

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=dea48deb47f1cd9cbdd53d7140c1e6495638a26c translatedAt=2026-08-13T13:22:24.664Z pushedAt=2026-08-17T07:16:06.015Z -->

Page node information used for auto-fill.

**Since**: 26.0.0

## PageNodeInfo

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ------------ | ------- | ---- | ---- | ------------- |
| id | number | No | No | ID of the page node. |
| autoFillType | [AutoFillType](js-apis-inner-application-autoFillType.md) | No | No | Auto-fill type of the page node. |
| value | string | No | No | Value of the page node. |
| placeholder | string | No | Yes | Placeholder of the page node. |
| rect | [AutoFillRect](js-apis-inner-application-autoFillRect.md) | No | No | Coordinate and size information of the current node. |
| isFocus | boolean | No | No | Whether the current node is focused. The value true means the current node is focused, and false means the opposite. |