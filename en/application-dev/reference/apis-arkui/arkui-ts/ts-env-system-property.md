# \@Env: Environment Variable

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @zhangwenhan12-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=fbb20f6c9a071d7bb7a6bce5d7a0a31f9c66fbdb translatedAt=2026-08-18T03:08:20.022Z pushedAt=2026-08-18T10:00:48.128Z -->

The **\@Env** decorator is used to obtain system environment variables, helping you sense system environment changes and dynamically adjust the UI display.

> **NOTE**
>
> The initial APIs of this module are supported since API version 22. Newly added APIs will be marked with a superscript to indicate their earliest API version.

For details about the developer guide, see [\@Env Developer Guide](../../../ui/arkts-env-system-property.md).

## \@Env

Env\<T\>(key: SystemEnvKey\<T\> | SystemProperties): PropertyDecorator

Obtains system environment variables. Before API version 26.0.0, only the **SystemProperties** enum can be passed in. Since API version 26.0.0, the [SystemEnvKey\<T\>](#systemenvkeyt) class or the [SystemProperties](#systemproperties) enum can be passed in as the parameter.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name| Type| Mandatory | Description|
| -------- | -------------------- | ---- | --------- | 
|key|SystemEnvKey\<T> \| SystemProperties|Yes|Environment variable key.|

**Return value** 

|Type|Description| 
| ----- | ----- | 
| PropertyDecorator| Property decorator. You do not need to pay attention to this return value. | 

**Example**

```ts
import { uiObserver } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  // @Env reads the system environment variable.
  @Env(SystemProperties.BREAK_POINT) breakpoint: uiObserver.WindowSizeLayoutBreakpointInfo;

  build() {
    Column() {
        Text(`breakpoint height ${this.breakpoint.heightBreakpoint}`)
        Text(`breakpoint width ${this.breakpoint.widthBreakpoint}`)
    }
  }
}
```

## EnvDecorator

type EnvDecorator = (value: SystemProperties) => PropertyDecorator 

Defines the **EnvDecorator** property decorator type. 

**Model restriction:** This API can be used only in the stage model. 

**Atomic service API**: This API can be used in atomic services since API version 22. 

**System capability:** SystemCapability.ArkUI.ArkUI.Full 

**Parameters** 

| Name  | Type                 | Mandatory| Description         |
| -------- | -------------------- | ---- | --------- |
| value    |      [SystemProperties](#systemproperties)          | Mandatory   |       Environment variable attribute name, used to specify the system environment variable to obtain.    |

**Return value** 

|Type|Description|
| ----- | ----- |
| PropertyDecorator| Property decorator. You do not need to care about this return value. |

**Error codes** 

For details, see [Environment Variable Error Codes](../errorcode-env.md). 

| ID| Error Message|
| ------- | -------------------------------- |
|140000|Invalid key for @Env|

## SystemProperties

Defines the environment variable enum values, which are used to obtain system environment variables through the [@Env](#env) decorator.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Value  | Description                                      |
| ----------- | ---- | ------------------------------------------------------------ |
|BREAK_POINT|'system.arkui.breakpoint'|Variable parameter of [@Env](#env). You can obtain a [WindowSizeLayoutBreakpointInfo](../js-apis-arkui-observer.md#windowsizelayoutbreakpointinfo22) instance through **\@Env(SystemProperties.BREAK_POINT)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the size layout breakpoint information of the window where the current custom component is located.<br/>**Atomic service API:** This API can be used in atomic services since API version 22.<br/>**Model restriction:** This API can be used only in the stage model.|
|WINDOW_SIZE<sup>23+</sup>|'system.window.size'|Variable parameter of [@Env](#env). You can obtain a [SizeInVP](../arkts-apis-window-i.md#sizeinvp23) instance through **\@Env(SystemProperties.WINDOW_SIZE)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the size information of the window where the current custom component is located, in vp.<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model.|
|WINDOW_SIZE_PX<sup>23+</sup>|'system.window.size.px'|Variable parameter of [@Env](#env). You can obtain a [Size](../arkts-apis-window-i.md#size7) instance through **\@Env(SystemProperties.WINDOW_SIZE_PX)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the size information of the window where the current custom component is located, in px.<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model.|
|WINDOW_AVOID_AREA<sup>23+</sup>|'system.window.avoidarea'|Variable parameter of [@Env](#env). You can obtain a [UIEnvWindowAvoidAreaInfoVP](../arkts-apis-window-i.md#uienvwindowavoidareainfovp23) instance through **\@Env(SystemProperties.WINDOW_AVOID_AREA)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the avoid area information of the window where the current custom component is located, in vp.<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model.|
|WINDOW_AVOID_AREA_PX<sup>23+</sup>|'system.window.avoidarea.px'|Variable parameter of [@Env](#env). You can obtain a [UIEnvWindowAvoidAreaInfoPX](../arkts-apis-window-i.md#uienvwindowavoidareainfopx23) instance through **\@Env(SystemProperties.WINDOW_AVOID_AREA_PX)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the avoid area information of the window where the current custom component is located, in px.<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model.|

## SystemEnvKey\<T\>

Defines the type corresponding to the system environment variable key.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description                                                                                              |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------|
| type | T | No | Yes | Data type of the system environment variable key. The default value is **undefined**.|

### constructor

protected constructor()

Creates an instance of this class.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

## WritableSystemEnvKey\<T\>

Defines a writable system environment variable key, which inherits from [SystemEnvKey\<T\>](#systemenvkeyt).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

## ReadonlySystemEnvKey\<T\>

Defines a read-only system environment variable key, which inherits from [SystemEnvKey\<T\>](#systemenvkeyt).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

## WritableEnvKey

Defines the set of writable system environment variable keys, which are used to obtain the corresponding system environment variables through the **@Env** decorator. You can use the [env](./ts-container-with-env.md#env) method in [WithEnv](./ts-container-with-env.md) to set local environment variable values to affect the rendering of descendant components. For details, see [Example 2: Setting Local Layout Direction](./ts-container-with-env.md#example-2-setting-local-layout-direction).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description                                                                                              |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------|
| DIRECTION | [WritableSystemEnvKey](#writablesystemenvkeyt)\<Direction\>| Yes | No |[\@Env](#env) variable parameter. The value of the [Direction](./ts-appendix-enums.md#direction) enum type can be obtained through **\@Env(WritableEnvKey.DIRECTION)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the layout direction of the screen where the window is located.|
| FONT_SCALE | [WritableSystemEnvKey](#writablesystemenvkeyt)\<number\> | Yes | No |[\@Env](#env) variable parameter. A value of the number type can be obtained through **\@Env(WritableEnvKey.FONT_SCALE)**. The value has no upper limit, and values less than or equal to 0 are treated as 0.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to provide a local font scale factor for descendant components.|

## ReadonlyEnvKey

Defines the set of read-only system environment variable keys, which are used to obtain the corresponding system environment variables through the **\@Env** decorator.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

### Attributes

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | ------ |
| WINDOW_AVOID_AREA | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<window.UIEnvWindowAvoidAreaInfoVP\> | Yes | No |[\@Env](#env) variable parameter. A [UIEnvWindowAvoidAreaInfoVP](../arkts-apis-window-i.md#uienvwindowavoidareainfovp23) instance can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_AVOID_AREA)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the avoid area information of the window where the current custom component is located, in vp.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_AVOID_AREA_PX | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<window.UIEnvWindowAvoidAreaInfoPX\> | Yes | No |[\@Env](#env) variable parameter. A [UIEnvWindowAvoidAreaInfoPX](../arkts-apis-window-i.md#uienvwindowavoidareainfopx23) instance can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_AVOID_AREA_PX)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the avoid area information of the window where the current custom component is located, in px.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_SIZE | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<window.SizeInVP\> | Yes | No |[\@Env](#env) variable parameter. A [SizeInVP](../arkts-apis-window-i.md#sizeinvp23) instance can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_SIZE)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the size information of the window where the current custom component is located, in vp.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_SIZE_PX | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<window.Size\> | Yes | No |[\@Env](#env) variable parameter. A [Size](../arkts-apis-window-i.md#size7) instance can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_SIZE_PX)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the size information of the window where the current custom component is located, in px.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_DISPLAY_ID | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<number\> | Yes | No |[\@Env](#env) variable parameter. A value of the number type can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_DISPLAY_ID)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the screen ID of the window where the current custom component is located.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_SYSTEM_DENSITY | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<number\> | Yes | No |[\@Env](#env) variable parameter. A value of the number type can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_SYSTEM_DENSITY)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain the system display size scale factor of the window where the current custom component is located. This parameter is a floating-point number, with a value range of [0.5, 4.0] or -1.0. 4.0 indicates the maximum display size scale factor that the window can display, and -1.0 indicates that the window uses the system display size scale factor.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_IS_FOCUSED | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<boolean\> | Yes | No |[\@Env](#env) variable parameter. A value of the boolean type can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_IS_FOCUSED)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain whether the window where the current custom component is located is in the focused state. true indicates that it is currently in the focused state, and false indicates that it is currently not in the focused state.<br/>**Since:** 26.0.0<br/>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_IS_HIGHLIGHTED | [ReadonlySystemEnvKey](#readonlysystemenvkeyt)\<boolean\> | Yes | No |[\@Env](#env) variable parameter. A value of the boolean type can be obtained through **\@Env(ReadonlyEnvKey.WINDOW_IS_HIGHLIGHTED)**.<br/>When this decorator is declared in [\@Component](../../../ui/state-management/arkts-create-custom-components.md#component) or [\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2), it is used to obtain whether the window where the current custom component is located is in the highlighted state. true indicates that it is currently in the highlighted state, and false indicates that it is currently not in the highlighted state.<br/>**Since:** 26.0.0<br/>**Model restriction:** This API can be used only in the stage model. |