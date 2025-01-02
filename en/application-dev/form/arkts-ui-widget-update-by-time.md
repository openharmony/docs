# Configuring a Widget to Update Periodically

The widget framework provides the following modes of updating widgets periodically:


- Setting the update interval: The widget will be updated at the specified interval by calling [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform). You can specify the interval by setting the [updateDuration](arkts-ui-widget-configuration.md) field in the **form_config.json** file. For example, you can configure the widget to update once an hour.

  > **NOTE**
  >
  > - Before configuring a widget to update periodically, enable the periodic update feature by setting the **updateEnabled** field to **true** in the **form_config.json** file. If both **updateDuration** and **scheduledUpdateTime** are set, the value specified by **updateDuration** is used.
  >
  > - To reduce the number of passive periodic update times and power consumption of widgets, the update interval can be set from the application market – for applications that are being or have been installed.
  >  - If an update interval is set from the application market, it is compared with the value of **updateDuration** in the **form_config.json** file. Whichever longer is used.
  >   - If no update interval is set from the application market, the value in the **form_config.json** file is used.
  >   - This rule does not apply when the periodic update feature is disabled.
  >   - The update interval set from the application market ranges from 1 to 336, in the unit of 30 minutes. That is, the minimum update interval is half an hour (1 x 30 minutes) and the maximum update interval is one week (336 x 30 minutes).
  >   - This rule takes effect since API version 11. In earlier versions, the periodic update follows the settings in the **form_config.json** file.

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

- Setting the scheduled update time: The widget will be updated at the scheduled time every day. You can specify the time by setting the [scheduledUpdateTime](arkts-ui-widget-configuration.md) field in the **form_config.json** file. For example, you can configure the widget to update at 10:30 a.m. every day.

  > **NOTE**
  >
  > **updateDuration** takes precedence over **scheduledUpdateTime**. For the **scheduledUpdateTime** settings to take effect, set **updateDuration** to **0**.
  
  ```json
  {
    "forms": [
    	{
        "name": "ScheduledUpdateTime",
        "description": "$string:widget_scheupdatetime_desc",
        "src": "./ets/scheduledupdatetime/pages/ScheduledUpdateTimeCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
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

- Setting the next update time: The widget will be updated next time at the specified time. You can specify the time by calling the [setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#setformnextrefreshtime) API. The minimum update interval is 5 minutes. For example, you can configure the widget to update within 5 minutes after the API is called.

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
    ...    
  }
  ```


When periodic update is triggered, the system calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback of the FormExtensionAbility. In the callback, [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) can be used to update the widget. For details about how to use **onUpdateForm**, see [Updating Widget Content Through FormExtensionAbility](arkts-ui-widget-event-formextensionability.md).


> **NOTE**
> - Each widget can be updated at the specified interval for a maximum of 50 times every day, including updates triggered by setting [updateDuration](arkts-ui-widget-configuration.md) or calling [setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#setformnextrefreshtime). When the limit is reached, the widget cannot be updated in this mode again. The number of update times is reset at 00:00 every day.
>
> - A single timer is used for timing updates at the specified interval. Therefore, if a widget is configured to update at scheduled intervals, the first scheduled update may have a maximum deviation of 30 minutes. For example, if widget A (updated every half an hour) is added at 03:20 and widget B (also updated every half an hour) is added at 03:40, the first update of widget B has a deviation of 10 minutes to the expected time: The timer starts at 03:20 when widget A is added, triggers an update for widget A at 03:50, and triggers another update for widget B at 04:20 (instead of 04:10 as expected).
>
> - Updates at the specified interval and updates at the scheduled time are triggered only when the screen is on. The update action is merely recorded when the screen is off and is performed once the screen is on.
> - If the update-through-proxy feature is enabled, periodic update at the scheduled time (either every day or for the next time) does not take effect.
