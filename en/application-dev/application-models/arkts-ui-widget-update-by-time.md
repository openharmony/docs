# Configuring a Widget to Update Periodically

Before configuring a widget to update periodically, enable the periodic update feature by setting the **updateEnabled** field to **true** in the **form_config.json** file.

The widget framework provides the following modes of updating widgets periodically:


- Set the update interval: The widget will be updated at the specified interval by calling [onUpdateForm](../reference/apis/js-apis-app-form-formExtensionAbility.md#onupdateform). You can specify the interval by setting the [updateDuration](arkts-ui-widget-configuration.md) field in the **form_config.json** file. For example, you can configure the widget to update once an hour.
  
  > **NOTE**
  >
  > **updateDuration** takes precedence over **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.
  
  ```json
  {
    "forms": [
      {
        "name": "widget",
        "description": "This is a service widget.",
        "src": "./ets/widget/pages/WidgetCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true, // Enable the periodic update feature.
        "scheduledUpdateTime": "10:30",                               
        "updateDuration": 2, // Set the interval to update the widget. The value is a natural number, in the unit of 30 minutes.
        "defaultDimension": "2*2",
        "supportDimensions": ["2*2"]
      }
    ]
  }
  ```
  
- Set the scheduled update time: The widget will be updated at the scheduled time every day. You can specify the time by setting the [scheduledUpdateTime](arkts-ui-widget-configuration.md) field in the **form_config.json** file. For example, you can configure the widget to update at 10:30 a.m. every day.
  
  > **NOTE**
  >
  > **updateDuration** takes precedence over **scheduledUpdateTime**. For the **scheduledUpdateTime** settings to take effect, set **updateDuration** to **0**.
  
  
  ```json
  {
    "forms": [
      {
        "name": "widget",
        "description": "This is a service widget.",
        "src": "./ets/widget/pages/WidgetCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true, // Enable the periodic update feature.
        "scheduledUpdateTime": "10:30", // Set the scheduled time to update the widget.
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": ["2*2"]
      }
    ]
  }
  ```
  
- Set the next update time: The widget will be updated next time at the specified time. You can specify the time by calling the [setFormNextRefreshTime()](../reference/apis/js-apis-app-form-formProvider.md#setformnextrefreshtime) API. The minimum update interval is 5 minutes. For example, you can configure the widget to update within 5 minutes after the API is called.
  
  ```ts
  import formProvider from '@ohos.app.form.formProvider';
  
  let formId = '123456789'; // Use the actual widget ID in real-world scenarios.
  try {
    // Configure the widget to update in 5 minutes.
    formProvider.setFormNextRefreshTime(formId, 5, (err, data) => {
      if (err) {
        console.error(`Failed to setFormNextRefreshTime. Code: ${err.code}, message: ${err.message}`);
        return;
      } else {
        console.info('Succeeded in setFormNextRefreshTimeing.');
      }
    });
  } catch (err) {
    console.error(`Failed to setFormNextRefreshTime. Code: ${err.code}, message: ${err.message}`);
  }
  ```


When periodic update is triggered, the system calls the [onUpdateForm()](../reference/apis/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback of the FormExtensionAbility. In the callback, [updateForm()](../reference/apis/js-apis-app-form-formProvider.md#updateform) can be used to update the widget by the provider. For details about how to use **onUpdateForm()**, see [Updating Widget Content Through FormExtensionAbility](arkts-ui-widget-event-formextensionability.md).


> **NOTE**
> 1. Each widget can be updated at the specified interval for a maximum of 50 times every day, including updates triggered by setting [updateDuration](arkts-ui-widget-configuration.md) or calling [setFormNextRefreshTime()](../reference/apis/js-apis-app-form-formProvider.md#setformnextrefreshtime). When the limit is reached, the widget cannot be updated in this mode again. The number of update times is reset at 00:00 every day.
> 
> 2. The same timer is used for timing updates at the specified interval. Therefore, the first scheduled update of widgets may have a maximum deviation of 30 minutes. For example, the first widget A (updated every half an hour) is added at 03:20. The timer starts and triggers an update every half an hour. The second widget B (updated every half an hour) is added at 03:40. When the timer event is triggered at 03:50, widget A is updated, and widget B will be updated at 04:20 next time.
> 
> 3. Updates at the specified interval and updates at the scheduled time are triggered only when the screen is on. When the screen is off, the update action is merely recorded. When the screen is on, the update action is performed.
