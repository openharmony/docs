# Interval-based Widget Updates

Form Kit provides the following methods for interval-based updates:

- Setting the update interval: The widget content will be automatically updated at the specified interval by calling [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform). The interval is specified by the `updateDuration` field in the [form_config.json](arkts-ui-widget-configuration.md) file. For example, if **updateDuration** is set to **2**, the widget is updated every hour.

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
        "colorMode": "auto",
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
  > To use interval-based updates, set the **updateEnabled** field to **true** in the **form_config.json** file.
  >
  > To reduce the number of passive periodic update times and power consumption of widgets, the update interval can be set from the application market – for applications that are being or have been installed.
  > - If an update interval is set from the application market, it is compared with the value of `updateDuration` in the **form_config.json** file. Whichever longer is used.
  > - If no update interval is set from the application market, the value in the **form_config.json** file is used.
  > - This rule does not apply when the interval-based update feature is disabled.
  > - The update interval set from the application market ranges from 1 to 336, in the unit of 30 minutes. That is, the minimum update interval is half an hour (1 x 30 minutes) and the maximum update interval is one week (336 x 30 minutes).
  > - This rule takes effect since API version 11. In earlier versions, the interval-based update follows the settings in the **form_config.json** file.

- Setting the next update time: The widget will be updated next time at the specified time, which is specified by calling [setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#setformnextrefreshtime), at the minimum of 5 minutes. For example, you can configure the widget to update within 5 minutes after the API is called.

  ```ts
  import { FormExtensionAbility, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const TAG: string = 'UpdateByTimeFormAbility';
  const FIVE_MINUTE: number = 5;
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class UpdateByTimeFormAbility extends FormExtensionAbility {
    onFormEvent(formId: string, message: string): void {
      // Called when a specified message event defined by the form provider is triggered.
      hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
      try {
        // Configure the widget to update in 5 minutes.
        formProvider.setFormNextRefreshTime(formId, FIVE_MINUTE, (err: BusinessError) => {
          if (err) {
            hilog.info(DOMAIN_NUMBER, TAG, `Failed to setFormNextRefreshTime. Code: ${err.code}, message: ${err.message}`);
            return;
          } else {
            hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in setFormNextRefreshTiming.');
          }
        });
      } catch (err) {
        hilog.info(DOMAIN_NUMBER, TAG, `Failed to setFormNextRefreshTime. Code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
      }
    }
    // ... 
  }
  ```

When an interval-based update is triggered, the system calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback of the FormExtensionAbility. In the callback, [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) can be used to update the widget. For details about how to use `onUpdateForm`, see [Widget Lifecycle Management](./arkts-ui-widget-lifecycle.md).

**Constraints**
1. Each widget can be updated at the specified interval for a maximum of 50 times every day, including updates triggered by setting [updateDuration](arkts-ui-widget-configuration.md) or calling [setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#setformnextrefreshtime). When the limit is reached, the widget cannot be updated in this mode again. The number of update times is reset at 00:00 every day.
2. A single timer is used for interval-based updates. Therefore, if a widget is configured to update at specified intervals, the first update may have a maximum deviation of 30 minutes. For example, if widget A (updated every half an hour) is added at 03:20 and widget B (also updated every half an hour) is added at 03:40, the first update of widget B has a deviation of 10 minutes to the expected time: The timer starts at 03:20 when widget A is added, triggers an update for widget A at 03:50, and triggers another update for widget B at 04:20 (instead of 04:10 as expected).
3. Interval-based updates are triggered only when the widget is visible. If the widget is invisible, the update action and data are recorded. The layout is refreshed once the widget becomes visible.
4. If the update-through-proxy feature is enabled, the settings for the update interval and next update time will not take effect.
