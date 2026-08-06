# Passive Update of ArkTS Widgets

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=f2cd623d606ddf44ee1a12cd7214615ae69df40f translatedAt=2026-08-03T02:28:13.175Z pushedAt=2026-08-03T07:30:40.909Z -->

This section provides the development guidelines for passive update. For details about the update process, see [Passive Update](./arkts-ui-widget-interaction-overview.md#passive-update).

## Interval-based Update

Form Kit provides the following methods for interval-based update:

- Setting the update interval: The widget content will be automatically updated at the specified interval by calling [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform). The interval is specified by the `updateDuration` field in the [form_config.json](arkts-ui-widget-configuration.md#fields-in-configuration-file) file. For example, the value of the `updateDuration` field can be set to **2**, indicating that the update interval is 1 hour (2 periods of 30 minutes).

  ```json
  {
    "forms": [
      {
        "name": "UpdateDuration",
        "description": "$string:widget_updateduration_desc",
        "src": "./ets/updateduration/pages/UpdateDurationCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "updateDuration": 2,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

  > **NOTE**
  >
  > To use interval-based update, set the `updateEnabled` field to `true` in the **form_config.json** file.

- Setting the next update time: The widget will be updated at the next specified time, which is specified by calling [setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidersetformnextrefreshtime). The minimum refresh interval is 5 minutes. For example, you can set the widget to refresh 5 minutes after the API is called.

  <!-- @[set_form_next_refreshtime](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/updatebytimeformability/UpdateByTimeFormAbility.ts) -->

  ``` TypeScript
  // entry/src/main/ets/updatebytimeformability/UpdateByTimeFormAbility.ts
  import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Want } from '@kit.AbilityKit';
  
  const TAG: string = 'UpdateByTimeFormAbility';
  const FIVE_MINUTE: number = 5;
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class UpdateByTimeFormAbility extends FormExtensionAbility {
    onAddForm(want: Want): formBindingData.FormBindingData {
      // Called when the widget host creates a widget. The widget data binding class is returned.
      let formData: Record<string, Object | string> = {};
      return formBindingData.createFormBindingData(formData);
    }
  
    // ...
    onFormEvent(formId: string, message: string): void {
      // Called when the message event of the postCardAction API of the widget provider is triggered.
      hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
      try {
        // Configure the widget to update in 5 minutes.
        formProvider.setFormNextRefreshTime(formId, FIVE_MINUTE, (err: BusinessError) => {
          if (err) {
            hilog.error(DOMAIN_NUMBER, TAG,
              `Failed to setFormNextRefreshTime. Code: ${err.code}, message: ${err.message}`);
            return;
          } else {
            hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in setFormNextRefreshTiming.');
          }
        });
      } catch (err) {
        hilog.error(DOMAIN_NUMBER, TAG,
          `Failed to setFormNextRefreshTime. Code: ${(err as BusinessError).code},
           message: ${(err as BusinessError).message}`);
      }
    }
  
    onAcquireFormState(want: Want): formInfo.FormState {
      // Called when the widget host queries the widget state. The initial state is returned by default.
      return formInfo.FormState.READY;
    }
  
  }
  ```

After an interval-based or next refresh is triggered, the system calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) lifecycle callback of FormExtensionAbility. In this callback, you can use the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API to refresh the widget content. For details about the `onUpdateForm` lifecycle callback, see [Managing ArkTS Widget Lifecycle](./arkts-ui-widget-lifecycle.md).

**Constraints**

1. Each widget can be updated at the specified interval for a maximum of 50 times every day, including updates triggered by modifying the [updateDuration](arkts-ui-widget-configuration.md#fields-in-configuration-file) field or calling [setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidersetformnextrefreshtime). When the limit is reached, the widget cannot be updated in this mode again. The number of update times is reset at 00:00 every day.

2. A single timer is used for interval-based updates. Therefore, if a widget is configured to update at specified intervals, the first update may have a maximum deviation of 30 minutes. For example, if widget A (updated every half an hour) is added at 03:20 and widget B (also updated every half an hour) is added at 03:40, the first update of widget B has a deviation of 10 minutes to the expected time: The timer starts at 03:20 when widget A is added, triggers an update for widget A at 03:50, and triggers another update for widget B at 04:20 (instead of 04:10 as expected).

3. Interval-based updates are triggered only when the widget is visible. If the widget is invisible, the update action and data are recorded. The layout is refreshed once the widget becomes visible.

4. Before API version 26.0.0<!--Del-->, for third-party apps<!--DelEnd-->, when widget proxy update is enabled, interval-based update and next update do not take effect. Starting from API version 26.0.0, widget proxy update, interval-based update, and next update can take effect simultaneously.<!--Del-->For system apps, when widget proxy update is enabled, interval-based update and next update do not take effect.<!--DelEnd-->

## Time-specific Update

Form Kit provides the following methods for time-specific widget update:

- Setting a single update time: The widget content will be automatically updated at a designated time every day. This time is specified by the `scheduledUpdateTime` field in the **form_config.json** file. For example, you can configure the widget to update at 10:30 every day.

  ```json
  {
    "forms": [
      {
        "name": "ScheduledUpdateTime",
        "description": "$string:widget_scheduledUpdateTime_desc",
        "src": "./ets/scheduledupdatetime/pages/ScheduledUpdateTimeCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

- Setting multiple update times: The widget content will be automatically updated at several specific times every day. These times are specified by the `multiScheduledUpdateTime` field in the **form_config.json** file. For example, you can configure the widget to update at 11:30 and 16:30 every day.

  ```json
  {
    "forms": [
    {
        "name": "ScheduledUpdateTime",
        "description": "$string:widget_scheduledUpdateTime_desc",
        "src": "./ets/scheduledupdatetime/pages/ScheduledUpdateTimeCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "multiScheduledUpdateTime": "11:30,16:30",
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

After a time-specific update is triggered, the system calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) lifecycle callback of FormExtensionAbility. In this callback, you can use the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API to refresh the widget content. For details about the `onUpdateForm` lifecycle callback, see [Managing ArkTS Widget Lifecycle](./arkts-ui-widget-lifecycle.md).

> **NOTE**
> - If both interval-based update (`updateDuration`) and time-specific update (`scheduledUpdateTime`) are configured, the interval-based update takes precedence, and the time-specific update will not be executed. To enable time-specific updates, set `updateDuration` to **0**.
> - A maximum of 24 times can be set for `multiScheduledUpdateTime`.
> - If both update at a single time and update at multiple times are configured, only the update at multiple times takes effect.
> - To ensure forward compatibility, retain the `scheduledUpdateTime` field.

**Constraints**

1. Time-specific updates are triggered only when the widget is visible. If the widget is invisible, the update action and data are recorded. The layout is refreshed once the widget becomes visible.

## Conditional Update

Form Kit provides the following methods for conditional updates:

- Network-triggered update: <!--Del-->Starting from API version 18, this feature is supported only for system apps. <!--DelEnd-->Starting from API version 26.0.0, the widget content can be automatically refreshed by calling the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) lifecycle callback when the network status changes. You can configure this in the `conditionUpdate` field of the [form_config.json](arkts-ui-widget-configuration.md) configuration file by setting the field to `network`.

> **NOTE**
> - A widget update is triggered when the device transitions from a no-network state to a connected state. However, an update is not triggered when a user switches between networks (for example, switching between different Wi-Fi networks or between Wi-Fi and cellular data) or goes from Internet connection to no Internet connection.
>
> - To minimize the frequency of widget process initiations during frequent network on/off scenarios, a no-network condition is determined after the network has been continuously unavailable for 10 minutes. Upon reconnection, a network-based update is then triggered.

  ```json
  {
    "forms": [
      {
        "name": "UpdateDuration",
        "description": "$string:widget_updateduration_desc",
        "src": "./ets/updateduration/pages/UpdateDurationCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "updateDuration": 2,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ],
        "conditionUpdate": [
          "network"
        ]
      }
    ]
  }
  ```