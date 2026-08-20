# @ohos.app.form.formInfo (formInfo)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

The **formInfo** module provides types and enumerations related to widget information and status, which are used for obtaining widget configuration, status information, parameter enums and other information. This module is suitable for scenarios where you need to query widget attributes, manage widget states, or handle widget parameters, helping you quickly access and manipulate widget-related information.

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

| Name       | Type                | Read-Only   | Optional   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| bundleName  | string               | No   | No    | Name of the bundle to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| moduleName  | string               | No   | No    | Name of the module to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| abilityName | string               | No   | No    | Name of the ability to which the widget belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| name        | string               | No   | No    | Widget name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayName<sup>11+</sup> | string               | No   | No    | Widget display name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayNameId<sup>11+</sup> | number               | No   | No    | ID of the widget name displayed during widget preview.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note:** The value is an integer greater than 0 and less than 2^32.|
| description | string               | No   | No    | Description of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| descriptionId<sup>10+</sup>      | number               | No   | No    | Widget description ID.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note:** The value is an integer greater than 0 and less than 2^32.|
| type        | [FormType](#formtype)             | No   | No    | Type of the widget. Currently, JS and ArkTS widgets are supported.<br>**Note:** When the widget type is JS,** isDynamic** is forcibly set to **true**, **transparencyEnabled** does not take effect, and **jsComponentName** is mandatory.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| jsComponentName      | string               | No   | No    | Component name of the JS widget. This parameter is valid only when the widget type is JS.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| colorMode<sup>(deprecated)</sup>  | [ColorMode](#colormodedeprecated) | No   | No    | Color mode of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br> **NOTE**<br> This API is supported since API version 9 and deprecated since API version 20. No substitute API is provided.|
| isDefault    | boolean      | No   | No    | Whether the widget is the default one.<br>- **true**: The widget is the default one.<br>- **false**: The widget is not the default one.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| updateEnabled  | boolean               | No   | No    | Whether the widget is updatable.<br>- **true**: The widget can be updated periodically.<br>- **false**: The widget cannot be updated periodically.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| formVisibleNotify  | boolean        | No   | No    | Whether to send a notification when the widget is visible.<br>- **true**: The widget provider is notified of the status change.<br>- **false**: The widget provider is not notified of the status change.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| scheduledUpdateTime        | string               | No   | No    | Time when the widget was updated.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| formConfigAbility | string               | No   | No    | Configuration ability of the widget, that is, the ability corresponding to the option in the selection box displayed when the widget is long pressed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| updateDuration        | number       | No   | No    | Update period of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note:** The value is an integer ranging from 0 to 336. An exception is thrown if the value is out of range.|
| defaultDimension  | number | No   | No    | Widget specifications. For details, see [FormDimension](#formdimension).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note:** The value is an integer ranging from 1 to 9. The value **5** is supported since API version 9 and deprecated since API version 20. An exception is thrown if the value is out of range.|
| supportDimensions    | Array&lt;number&gt;      | No   | No    | Dimensions supported by the widget. For details, see [FormDimension](#formdimension).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note:** The value is an array containing a maximum of 9 integers. The value of each array element ranges from [1, 9], where the value **5** is supported since API version 9 and deprecated since API version 20. An exception is thrown if the value is out of range.|
| customizeData    | Record&lt;string, string&gt;      | No   | No    | Custom data of the widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| isDynamic<sup>10+</sup>      | boolean               | No   | No    | Whether the widget is a dynamic widget.<br>ArkTS widgets are classified into dynamic and static widgets. JS widgets are all dynamic widgets.<br>- **true**: The widget is a dynamic widget.<br>- **false**: The widget is a static widget.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| transparencyEnabled<sup>11+</sup>      | boolean               | No   | No    | Whether the widget supports the setting of the background transparency.<br>For ArkTS widgets, the support for the background transparency setting depends on user configurations. For JS widgets, the background transparency setting is not supported.<br>- **true**: The widget is transparent.<br>- **false**: The widget is not transparent.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| supportedShapes<sup>12+</sup>    | Array&lt;number&gt;      | No   | No    | Shapes supported by the widget. For details about the available shapes, see [FormShape<sup>12+</sup>](#formshape12).<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**Note:** The value **1** indicates a square, and the value **2** indicates a circle.|

## FormType

Enumerates the widget types. JS widgets are implemented using Web technologies and are suitable for simple display-only widgets. ArkTS widgets are developed using the ArkTS language and support richer interactions and animations. When developing, you should choose the appropriate type based on the widget complexity and interaction requirements.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| JS      | 1    | JS widget. Developed using Web technologies, with relatively basic functionality, suitable for simple scenarios.  |
| eTS     | 2    | ArkTS widget. Developed using the ArkTS language, supporting rich interactions and animations, suitable for complex scenarios.|

## ColorMode<sup>(deprecated)</sup>

Enumerates the color modes supported by the widget. The widget theme style follows the system color mode.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. There is no substitute API.

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

| Name       | Type                | Read-Only   | Optional   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formState  | [FormState](#formstate)               | No   | No    | Widget state, which is used to identify the current state of the widget (for example, unknown, default, or ready).                         |
| want  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)         | No   | No    | Want object, which is used to carry the intent information during widget state switching.   |

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
| FORM_LOCATION_KEY<sup>12+</sup>    | 'ohos.extra.param.key.form_location'   | Widget location. For details, see [FormLocation](#formlocation20).|
| FORM_PERMISSION_NAME_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_name' | Name of the permission.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FORM_PERMISSION_GRANTED_KEY<sup>12+</sup> | 'ohos.extra.param.key.permission_granted' | Whether the permission is granted.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| ORIGINAL_FORM_KEY<sup>20+</sup> | 'ohos.extra.param.key.original_form_id' | Original widget ID. When a group of widgets associated by **groupId** is resized, new-sized widgets are created before old-sized widgets are deleted. When a new-sized widget is created, the old-sized widget ID is passed through this key in the **want** parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| EDIT_FORM_KEY<sup>22+</sup> | 'ohos.extra.param.key.edit_form_id' | ID of the edited widget. In the widget editing of the semi-modal page, this key is passed through the **onAddForm** callback to indicate the ID of the edited widget, ensuring that the preview widget and the edited widget are synchronized. If the **onAddForm** callback of the widget carries this key, the widget is a preview widget in the semi-modal page, and the content of the preview widget needs to be filtered based on the edited widget.<br>**Atomic service API**: This API can be used in atomic services since API version 22.|
| UPDATE_FORM_REASON_KEY<sup>24+</sup> | 'ohos.extra.param.key.update_form_reason' | Widget update reason. For details, see [FormUpdateReason](#formupdatereason24).<br>**Atomic service API**: This API can be used in atomic services since API version 24.<br>**Model restriction**: This API can be used only in the stage model.|

## FormDimension

Enumerates the widget dimensions.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| Dimension_1_2      | 1   | 1 x 2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_2      | 2   | 2 x 2.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_4      | 3   | 2 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_4_4      | 4   | 4 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Dimension_2_1<sup>(deprecated)</sup>      | 5   | 2 x 1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note**: This field is supported since API version 9 and deprecated since API version 20.|
| DIMENSION_1_1<sup>11+</sup>      | 6   | 1 x 1.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Note**: This dimension takes effect only on lock screen widgets.|
| DIMENSION_6_4<sup>12+</sup>      | 7   | 6 x 4.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| DIMENSION_2_3<sup>18+</sup>      | 8   | 2 x 3.<br>**Atomic service API**: This API can be used in atomic services since API version 18.<br>**Device behavior differences**: This field takes effect only on wearables.|
| DIMENSION_3_3<sup>18+</sup>      | 9   | 3 x 3.<br>**Atomic service API**: This API can be used in atomic services since API version 18.<br>**Device behavior differences**: This field takes effect only on wearables.|

## FormShape<sup>12+</sup> 

Enumerates the widget shapes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| RECT        | 1   | Rectangular.|
| CIRCLE      | 2   | Circle.|

## FormInfoFilter

Defines the widget information filter. Only the widget information that meets the filter is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       | Type  | Read-Only        | Optional        |Description        |
| ----------- | ---- | ------------ | ------------ |------------ |
| moduleName    | string    |No |Yes   | Name of the module to which the widget belongs, which is used to filter widget information. Only the widget information in which **moduleName** is the same as the provided value is returned. If this parameter is left unspecified, the widget information is not filtered by **moduleName**.  |



## VisibilityType

Enumerates the visibility types of the widget. The visibility type indicates the visibility state of a widget on the host interface. The state changes when the widget is moved into or out of the screen, or when the application is switched. You can optimize widget refresh strategies based on this information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN<sup>10+</sup> | 0   | The visibility type of the widget is unknown.|
| FORM_VISIBLE | 1   | The widget is visible. The widget is displayed in the foreground and can normally receive updates and visibility notifications.|
| FORM_INVISIBLE   | 2   | The widget is invisible. The widget is not displayed in the foreground, and the system may suspend updates to save resources.|


## LaunchReason<sup>10+</sup>

Enumerates the reasons for creating a widget.

**System capability**: SystemCapability.Ability.Form

| Name       |  Value  | Description        |
| ----------- | ---- | ------------ |
| FORM_DEFAULT | 1   | The widget is created by default.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FORM_SHARE   | 2   | The widget is created for sharing.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FORM_SIZE_CHANGE<sup>20+</sup>    | 3   | The widget is created due to dimension changes.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## FormUpdateReason<sup>24+</sup> 

Enumerates widget update reasons.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 24.

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| UNKNOWN        | -1 | The widget is updated for an unknown reason.|
| FORM_NODE_REUSE      | 0   | The widget is updated for node reuse.|

## OverflowInfo<sup>20+</sup>

Describes the widget animation information.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Read-Only| Optional | Description                             |
|-----|-----|------|-----|---------------------------------|
| area     | [Rect](#rect20) | No| No  | Interactive widget animation area. The upper-left corner of the widget is used as the origin.  |
| duration | number | No| No  | Animation duration, in ms. The value is an integer greater than 0, and <!--Del-->for third-party applications, <!--DelEnd-->the value cannot exceed 3500. <!--Del-->This restriction does not apply to system applications.<!--DelEnd-->|
| useDefaultAnimation | boolean | No| Yes  | Whether to enable the system-provided default animation when an interactive widget switches states. The default value is **true**.<br>- **true**: enable the system-provided default transition animation.<br>- **false**: disable the system-provided default transition animation. The widget state switches directly with no animation applied, which is applicable for scenarios where the widget UI is identical in both inactive and active states during switching.|

## Rect<sup>20+</sup>

Defines the common rectangular area information, including the widget coordinate area and interactive widget animation area.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Read-Only| Optional | Description|
|-----|-----|------|-----|-------|
| left   | number | No| No  | X-coordinate of the top-left corner of the rectangle, in vp. It is used to position the widget area. For details about the value ranges, see [Parameter Request](../../form/arkts-ui-liveform-sceneanimation-development.md#parameter-request).|
| top    | number | No| No  | Y-coordinate of the top-left corner of the rectangle, in vp. It is used to position the widget area. For details about the value ranges, see [Parameter Request](../../form/arkts-ui-liveform-sceneanimation-development.md#parameter-request).|
| width  | number | No| No  | Width of the rectangle, in vp. It is used to define the dimensions of the widget area. For details about the value ranges, see [Parameter Request](../../form/arkts-ui-liveform-sceneanimation-development.md#parameter-request).|
| height | number | No| No  | Height of the rectangle, in vp. It is used to define the dimensions of the widget area. For details about the value ranges, see [Parameter Request](../../form/arkts-ui-liveform-sceneanimation-development.md#parameter-request).|

## FormLocation<sup>20+</sup>

Enumerates the widget locations.

**System capability**: SystemCapability.Ability.Form

| Name                        | Value  | Description                            |
| ---------------------------- | ---- | -------------------------------- |
| DESKTOP                      | 0    | The widget is located on the home screen.<br>**Atomic service API**: This API can be used in atomic services since API version 20.              |
| FORM_CENTER                  | 1    | The widget is located in the widget center of the home screen.<br>**Atomic service API**: This API can be used in atomic services since API version 20.    |
| FORM_MANAGER                 | 2    | The widget is located in the Widget Manager of the home screen.<br>**Atomic service API**: This API can be used in atomic services since API version 20.  |
<!--RP1--><!--RP1End-->

## RunningFormInfo<sup>20+</sup>

Information about the widget that has been added to the home screen.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.Form

| Name       | Type                | Read-Only   | Optional   | Description                                                        |
| ----------- | -------- | -------- | -------------------- | ------------------------------------------------------------ |
| formId  | string               | Yes   | No    | Unique ID of a widget, which is used to identify and manage the widget instance that has been added to the home screen.                  |
| bundleName  | string               | Yes   | No    | Name of the bundle to which the widget provider belongs, which is used to locate the widget provider application.                  |
| moduleName  | string               | Yes   | No    | Name of the module to which the widget belongs, which is used to locate the specific module of the widget provider.                     |
| abilityName | string               | Yes   | No    | Name of the ability to which the widget belongs, which is used to locate the specific ability component of the widget provider.                      |
| formName        | string               | Yes   | No    | Name of the widget, which is used to identify and distinguish different widgets in the same module.                                |
| dimension | number               | Yes   | No    | Widget dimension, used to identify the size specification of the widget. For the values and their corresponding meanings, see [FormDimension](#formdimension).<br>**Note:** The value is an integer ranging from 1 to 9. The value **5** is supported since API version 9 and deprecated since API version 20.  |
| formLocation | [FormLocation](#formlocation20)| Yes   | No    | Widget position information, which is used to identify the current position of the widget (for example, home screen or widget center).  |
