# @ohos.app.form.formInfo (formInfo)

The **formInfo** module provides types and enums related to the widget information and state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { formInfo } from '@kit.FormKit';
```

## FormInfo

Defines the widget information.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | Yes   | No    | Name of the bundle to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| moduleName  | string               | Yes   | No    | Name of the module to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| abilityName | string               | Yes   | No    | Name of the ability to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| name        | string               | Yes   | No    | Widget name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayName<sup>11+</sup> | string               | Yes   | No    | Widget display name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayNameId<sup>11+</sup> | number               | Yes   | No    | ID of the widget name displayed during widget preview.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| description | string               | Yes   | No    | Description of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| descriptionId<sup>10+</sup>      | number               | Yes   | No    | ID of the widget description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| type        | [FormType](#formtype)             | Yes   | No    | Type of the widget. Currently, JS and ArkTS widgets are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| jsComponentName      | string               | Yes   | No    | Name of the component used in the JS widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| colorMode<sup>(deprecated)</sup>  | [ColorMode](#colormodedeprecated) | Yes   | No    | Color mode of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| isDefault    | boolean      | Yes   | No    | Whether the widget is the default one.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| updateEnabled  | boolean               | Yes   | No    | Whether the widget is updatable.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| formVisibleNotify  | boolean        | Yes   | No    | Whether to send a notification when the widget is visible.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| scheduledUpdateTime        | string               | Yes   | No    | Time when the widget was updated.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| formConfigAbility | string               | Yes   | No    | Configuration ability of the widget, that is, the ability corresponding to the option in the selection box displayed when the widget is long pressed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| updateDuration        | number       | Yes   | No    | Update period of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| defaultDimension  | number | Yes   | No    | Widget specifications.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| supportDimensions    | Array&lt;number&gt;      | Yes   | No    | Dimensions supported by the widget. For details, see [FormDimension](#formdimension).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| customizeData    | Record\<string, string>      | Yes   | No    | Custom data of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| isDynamic<sup>10+</sup>      | boolean               | Yes   | No    | Whether the widget is a dynamic widget.<br>ArkTS widgets are classified into dynamic and static widgets. JS widgets are all dynamic widgets.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| transparencyEnabled<sup>11+</sup>      | boolean               | Yes   | No    | Whether the widget supports the setting of the background transparency.<br>For ArkTS widgets, the support for the background transparency setting depends on user configurations. For JS widgets, the background transparency setting is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| supportedShapes<sup>12+</sup>    | Array&lt;number&gt;      | Yes   | No    | Shapes supported by the widget. For details about the available shapes, see [FormShape<sup>12+</sup>](#formshape12).<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## FormType

Enumerates the widget types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| JS      | 1    | JS widget.  |
| eTS     | 2    | ArkTS widget.|

## ColorMode<sup>(deprecated)</sup>

This API is supported since API version 11 and deprecated since API version 20. The color mode follows the system color mode.

Enumerates the color modes supported by the widget.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| MODE_AUTO   | -1    | Auto mode.  |
| MODE_DARK    | 0   | Dark mode.  |
| MODE_LIGHT     | 1   | Light mode.  |

## FormStateInfo

Describes the widget state information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Readable   | Writable   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | Yes   | No    | Widget state.                         |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)         | Yes   | No    | Want text.   |

## FormState

Enumerates the widget states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN    | -1    | Unknown state.  |
| DEFAULT     | 0   | Default state.  |
| READY      | 1   | Ready state.  |

## FormParam

Enumerates the widget parameters.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| IDENTITY_KEY     | 'ohos.extra.param.key.form_identity'    | Widget ID.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DIMENSION_KEY      | 'ohos.extra.param.key.form_dimension'  | Widget dimension. For details, see [FormDimension](#formdimension).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| NAME_KEY       | 'ohos.extra.param.key.form_name'   | Widget name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MODULE_NAME_KEY        | 'ohos.extra.param.key.module_name'   | Name of the module to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| WIDTH_KEY        | 'ohos.extra.param.key.form_width'   | Widget width.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| HEIGHT_KEY         | 'ohos.extra.param.key.form_height'   | Widget height.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| TEMPORARY_KEY          | 'ohos.extra.param.key.form_temporary'   | Temporary widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ABILITY_NAME_KEY   | 'ohos.extra.param.key.ability_name'   | Ability name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| BUNDLE_NAME_KEY    | 'ohos.extra.param.key.bundle_name'   | Bundle name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LAUNCH_REASON_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_launch_reason'   | Reason for creating the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PARAM_FORM_CUSTOMIZE_KEY<sup>10+</sup>    | 'ohos.extra.param.key.form_customize'   | Custom data.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FORM_RENDERING_MODE_KEY<sup>11+</sup>    | 'ohos.extra.param.key.form_rendering_mode'   | Widget rendering mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| HOST_BG_INVERSE_COLOR_KEY<sup>12+</sup>    | 'ohos.extra.param.key.host_bg_inverse_color'   | Inverse background color of the widget client.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FORM_LOCATION_KEY<sup>12+</sup>    | 'ohos.extra.param.key.form_location'   | Widget location.<br>OTHER                         -1    (Other locations)<br>DESKTOP                       0     (Home screen)<br>FORM_CENTER                   1     (Widget center of the home screen)<br>FORM_MANAGER                  2     (Widget Manager of the home screen)<br>NEGATIVE_SCREEN               3     (Minus-one screen)<br>FORM_CENTER_NEGATIVE_SCREEN   4     (Widget center of the minus-one screen)<br>FORM_MANAGER_NEGATIVE_SCREEN  5     (Widget Manager of the minus-one screen)<br>SCREEN_LOCK                   6     (Screen lock)<br>AI_SUGGESTION                 7     (Celia suggestions area)|
| FORM_PERMISSION_NAME_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_name' | Name of the permission.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FORM_PERMISSION_GRANTED_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_granted' | Whether the permission is granted.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## FormDimension

Enumerates the widget dimensions.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_2      | 2   | 2 x 2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_4      | 3   | 2 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_4_4      | 4   | 4 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_1      | 5   | 2 x 1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DIMENSION_1_1<sup>11+<sup>      | 6   | 1 x 1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DIMENSION_6_4<sup>12+<sup>      | 7   | 6 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| DIMENSION_2_3<sup>18+<sup>      | 8   | 2 x 3.<br>**Atomic service API**: This API can be used for wearable devices in atomic services since API version 18.|
| DIMENSION_3_3<sup>18+<sup>      | 9   | 3 x 3.<br>**Atomic service API**: This API can be used for wearable devices in atomic services since API version 18.|

## FormShape<sup>12+</sup> 

Enumerates the widget shapes.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| RECT        | 1   | Rectangle.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| CIRCLE      | 2   | Circle.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## FormInfoFilter

Defines the widget information filter. Only the widget information that meets the filter is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type  | Mandatory        |Description        |
| ----------- | ---- | ------------ |------------ |
| moduleName    | string    |No   | Only the information about the widget whose **moduleName** is the same as the provided value is returned.<br>If this parameter is not set, **moduleName** is not used for filtering.  |



## VisibilityType

Enumerates the visibility types of the widget.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN<sup>10+</sup> | 0   | The visibility type of the widget is unknown.|
| FORM_VISIBLE | 1   | The widget is visible.|
| FORM_INVISIBLE   | 2   | The widget is invisible.|


## LaunchReason<sup>10+</sup>

Enumerates the reasons for creating a widget.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| FORM_DEFAULT | 1   | The widget is created by default.|
| FORM_SHARE   | 2   | The widget is created for sharing.|

## OverflowInfo<sup>20+</sup>

Describes the widget animation information.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Read-Only| Optional | Description                             |
|-----|-----|------|-----|---------------------------------|
| area     | [Rect](#rect20) | Yes| No  | Overflow animation area. The upper left corner of the widget is used as the origin, in vp.  |
| duration | number | Yes| No  | Animation duration. The value is an integer greater than 0 and less than or equal to 3,500, in milliseconds.|

## Rect<sup>20+</sup>

Defines the common rectangular area information, including the widget position and animation area.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Read-Only| Optional | Description|
|-----|-----|------|-----|-------|
| left   | number | Yes| No  | X coordinate of the upper left vertex of the rectangle, in vp.|
| top    | number | Yes| No  | Y coordinate of the upper left vertex of the rectangle, in vp.|
| width  | number | Yes| No  | Width of the rectangle, in vp.|
| height | number | Yes| No  | Height of the rectangle, in vp.|
## FormLocation<sup>20+</sup>

Enumerates the widget locations.

**System capability**: SystemCapability.Ability.Form

| Name                        | Value  | Description                            |
| ---------------------------- | ---- | -------------------------------- |
| DESKTOP                      | 0    | The widget is located on the home screen.              |
| FORM_CENTER                  | 1    | The widget is located in the widget center of the home screen.    |
| FORM_MANAGER                 | 2    | The widget is located in the Widget Manager of the home screen.  |
<!--RP1--><!--RP1End-->
