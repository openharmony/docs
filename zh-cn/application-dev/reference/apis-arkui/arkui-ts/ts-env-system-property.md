# \@Env：环境变量
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @zhangwenhan12-->
<!--Adviser: @zhang_yixin13-->

\@Env装饰器用于获取系统环境变量，帮助开发者感知系统环境变化并动态调整UI显示。

> **说明：**
>
> 本模块首批接口从API version 22开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[\@Env开发者指南](../../../ui/arkts-env-system-property.md)。


## \@Env
Env\<T\>(key: SystemEnvKey\<T\> | SystemProperties): PropertyDecorator

用于获取系统环境变量。API版本26.0.0之前仅支持传入SystemProperties枚举，API版本26.0.0及以后版本支持传入[SystemEnvKey\<T\>](#systemenvkeyt)类或[SystemProperties](#systemproperties)枚举作为参数。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称|类型|说明|
| ----- | ----- | ------ |
|Env| PropertyDecorator | 环境变量装饰器。|

**示例：**

```ts
import { uiObserver } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  // @Env读取系统环境变量
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

定义EnvDecorator属性装饰器类型。 

**模型约束**：此接口仅可在Stage模型下使用。 

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。 

**系统能力：** SystemCapability.ArkUI.ArkUI.Full 

**参数：** 

| 参数名   | 类型                  | 必填 | 说明          |
| -------- | -------------------- | ---- | --------- | 
| value    |      [SystemProperties](#systemproperties)          | 是   |       环境变量属性名，用于指定要获取的系统环境变量。    | 

**返回值：** 

|类型|说明| 
| ----- | ----- | 
| PropertyDecorator| 属性装饰器，开发者无需关注该返回值。 | 

**错误码：** 

详细介绍请参见[环境变量错误码](../errorcode-env.md)。 
| 错误码ID | 错误信息 | 
| ------- | -------------------------------- | 
|140000|Invalid key for @Env| 
 
## SystemProperties

定义环境变量枚举值，用于通过[@Env](#env)装饰器获取系统环境变量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 值   | 说明                                       |
| ----------- | ---- | ------------------------------------------------------------ |
|BREAK_POINT|'system.arkui.breakpoint'|[@Env](#env)变量参数，通过\@Env(SystemProperties.BREAK_POINT)可获取[WindowSizeLayoutBreakpointInfo](../js-apis-arkui-observer.md#windowsizelayoutbreakpointinfo22)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的尺寸布局断点信息。<br/>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|
|WINDOW_SIZE<sup>23+</sup>|'system.window.size'|[@Env](#env)变量参数，通过\@Env(SystemProperties.WINDOW_SIZE)可获取[SizeInVP](../arkts-apis-window-i.md#sizeinvp23)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的大小信息，单位为vp。<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|
|WINDOW_SIZE_PX<sup>23+</sup>|'system.window.size.px'|[@Env](#env)变量参数，通过\@Env(SystemProperties.WINDOW_SIZE_PX)可获取[Size](../arkts-apis-window-i.md#size7)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的大小信息，单位为px。<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|
|WINDOW_AVOID_AREA<sup>23+</sup>|'system.window.avoidarea'|[@Env](#env)变量参数，通过\@Env(SystemProperties.WINDOW_AVOID_AREA)可获取[UIEnvWindowAvoidAreaInfoVP](../arkts-apis-window-i.md#uienvwindowavoidareainfovp23)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的避让区域信息，单位为vp。<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|
|WINDOW_AVOID_AREA_PX<sup>23+</sup>|'system.window.avoidarea.px'|[@Env](#env)变量参数，通过\@Env(SystemProperties.WINDOW_AVOID_AREA_PX)可获取[UIEnvWindowAvoidAreaInfoPX](../arkts-apis-window-i.md#uienvwindowavoidareainfopx23)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的避让区域信息，单位为px。<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|
|WINDOW_DISPLAY_ID|'system.window.displayid'|[@Env](#env)变量参数，通过\@Env(SystemProperties.WINDOW_DISPLAY_ID)可获取number类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的屏幕ID。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|
|WINDOW_SYSTEM_DENSITY|'system.window.density.system'|[@Env](#env)变量参数，通过\@Env(SystemProperties.WINDOW_SYSTEM_DENSITY)可获取number类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的系统显示大小缩放系数。该参数为浮点数，取值范围为[0.5, 4.0]或-1.0。4.0表示窗口可显示的最大显示大小缩放系数，-1.0表示窗口使用系统显示大小缩放系数。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束**：此接口仅可在Stage模型下使用。|

## SystemEnvKey\<T\>

系统环境变量Key对应的类型。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


### 属性

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                              |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------|
| type | T | 否 | 是 | 系统环境变量Key对应值的数据类型，默认值为undefined。|

### constructor

protected constructor()

用于创建该类的实例对象。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## WritableSystemEnvKey\<T\>

定义可写的系统环境变量Key，继承自[SystemEnvKey\<T\>](#systemenvkeyt)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## ReadonlySystemEnvKey\<T\>

定义只读的系统环境变量Key，继承自[SystemEnvKey\<T\>](#systemenvkeyt)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


## WritableEnvKey

定义可写的系统环境变量Key集合，用于通过@Env装饰器获取对应的系统环境变量。可通过[WithEnv](./ts-container-with-env.md)中的[env](./ts-container-with-env.md#env)方法设置局部环境变量值以影响后代组件渲染，具体示例请参见[示例2（设置局部布局方向）](./ts-container-with-env.md#示例2设置局部布局方向)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                              |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------|
| DIRECTION | [WritableSystemEnvKey\<T\>](#writablesystemenvkeyt)| 是 | 否 |[\@Env](#env)变量参数，通过\@Env(WritableEnvKey.DIRECTION)可获取[Direction](./ts-appendix-enums.md#direction)枚举类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取窗口所在屏幕的布局方向。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| FONT_SCALE | [WritableSystemEnvKey\<T\>](#writablesystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(WritableEnvKey.FONT_SCALE)可获取number类型的值，取值无上限，小于等于0的值按0处理。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于为后代组件提供局部字体缩放倍数。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。|

## ReadonlyEnvKey

定义只读的系统环境变量key集合，用于通过\@Env装饰器获取对应的系统环境变量。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | ------ |
| WINDOW_AVOID_AREA | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_AVOID_AREA)可获取[UIEnvWindowAvoidAreaInfoVP](../arkts-apis-window-i.md#uienvwindowavoidareainfovp23)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的避让区域信息，单位为vp。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_AVOID_AREA_PX | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_AVOID_AREA_PX)可获取[UIEnvWindowAvoidAreaInfoPX](../arkts-apis-window-i.md#uienvwindowavoidareainfopx23)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的避让区域信息，单位为px。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_SIZE | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_SIZE)可获取[SizeInVP](../arkts-apis-window-i.md#sizeinvp23)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的大小信息，单位为vp。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_SIZE_PX | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_SIZE_PX)可获取[Size](../arkts-apis-window-i.md#size7)实例。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的大小信息，单位为px。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_DISPLAY_ID | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_DISPLAY_ID)可获取number类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的屏幕ID。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_SYSTEM_DENSITY | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_SYSTEM_DENSITY)可获取number类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口的系统显示大小缩放系数。该参数为浮点数，取值范围为[0.5, 4.0]或-1.0。4.0表示窗口可显示的最大显示大小缩放系数，-1.0表示窗口使用系统显示大小缩放系数。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_IS_FOCUSED | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_IS_FOCUSED)可获取boolean类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口是否处于获焦状态，true表示当前处于获焦状态，false表示当前不处于获焦状态。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |
| WINDOW_IS_HIGHLIGHTED | [ReadonlySystemEnvKey\<T\>](#readonlysystemenvkeyt) | 是 | 否 |[\@Env](#env)变量参数，通过\@Env(ReadonlyEnvKey.WINDOW_IS_HIGHLIGHTED)可获取boolean类型的值。<br/>当该装饰器声明在[\@Component](../../../ui/state-management/arkts-create-custom-components.md#component)或[\@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2)中时，用于获取当前自定义组件所在窗口是否处于高亮状态，true表示当前处于高亮状态，false表示当前不处于高亮状态。<br/>**起始版本：** 26.0.0<br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |