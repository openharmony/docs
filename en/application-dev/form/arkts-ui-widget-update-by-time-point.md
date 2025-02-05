# Time-specific Widget Updates

Form Kit provides the following methods for updating widgets at specific times:

- Setting a single update time: The widget content will be automatically updated at a designated time every day. This time is specified by the **scheduledUpdateTime** field in the **form_config.json** file. For example, you can configure the widget to update at 10:30 every day.

  
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

- Setting multiple update times: The widget content will be automatically updated at several specific times every day. These times are specified by the **multiScheduledUpdateTime** field in the **form_config.json** file. For example, you can configure the widget to update at 11:30 and 16:30 every day.
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
        "multiScheduledUpdateTime": "11:30,16:30,",
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

When a time-specific update is triggered, the system calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback of the FormExtensionAbility. In the callback, [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) can be used to update the widget. For details about how to use onUpdateForm, see [Widget Lifecycle Management](./arkts-ui-widget-lifecycle.md).

> **NOTE**
> 1. If both interval-based updates (**updateDuration**) and time-specific updates (**scheduledUpdateTime**) are configured, the interval-based updates take precedence, and the time-specific updates will not be executed. To enable time-specific updates, set **updateDuration** to **0**.
> 2. A maximum of 24 times can be set for **multiScheduledUpdateTime**.
> 3. If both update at a single time and update at multiple times are configured, only the update at multiple times takes effect.
> 4. To ensure backward compatibility, retain the **scheduledUpdateTime** parameter instead of deleting it.

**Constraints**

Time-specific updates are triggered only when the widget is visible. If the widget is invisible, the update action and data are recorded. The layout is refreshed once the widget becomes visible.
