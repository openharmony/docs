# Time-specific Widget Updates

Form Kit provides the following method for updating widgets at specific times:

- Setting a update time: The widget content will be automatically updated at a designated time every day. This time is specified by the **scheduledUpdateTime** field in the **form_config.json** file. For example, you can configure the widget to update at 10:30 every day.

  
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


When a time-specific update is triggered, the system calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform) lifecycle callback of the FormExtensionAbility. In the callback, [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) can be used to update the widget. For details about how to use onUpdateForm, see [Widget Lifecycle Management](./arkts-ui-widget-lifecycle.md).

> **NOTE**
>
> If both interval-based updates (**updateDuration**) and time-specific updates (**scheduledUpdateTime**) are configured, the interval-based updates take precedence, and the time-specific updates will not be executed. To enable time-specific updates, set **updateDuration** to **0**.

**Constraints**

Time-specific updates are triggered only when the widget is visible. If the widget is invisible, the update action and data are recorded. The layout is refreshed once the widget becomes visible.