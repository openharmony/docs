# Conditional Widget Updates

Form Kit provides the following methods for conditional updates:
 
- Network-triggered update: The widget content will be automatically updated by calling [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform) when the network changes. This can be configured by setting the **conditionUpdate** field in the [form_config.json](arkts-ui-widget-configuration.md) file to **network**.
 
> **NOTE**
> 1. A widget update is triggered when the device transitions from a no-network state to a connected state. However, an update is not triggered when a user switches between networks (for example, switching between different Wi-Fi networks or between Wi-Fi and cellular data) or goes from Internet connection to no Internet connection.
>
> 2. To minimize the frequency of widget process initiations during frequent network on/off scenarios, a no-network condition is determined after the network has been continuously unavailable for 10 minutes. Upon reconnection, a network-based update is then triggered.
>
> 3. This functionality is valid only for widgets of system applications.
 

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
        ],
        "conditionUpdate": [
          "network"
        ]
      }
    ]
  }
  ```
