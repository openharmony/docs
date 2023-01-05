# Data and Event Configuration


Use the JSON file to configure the variables and events for service widgets. Declare the variables in the **data** field and events in the **actions** field.


Example:



```json
{
    "data": {
        "temperature": "35°C",
        "city": "hangzhou"
    },
    "actions": {
        "routerEventName": {
            "action": "router",
            "abilityName": "com.example.myapplication.FormAbility",
            "params": {
                "message": "weather",
                "temperature": "{{temperature}}"
            }
        },
        "messageEventName": {
            "action": "message",
            "params": {
                "message": "weather update"
            }
        }
    }
}
```

For details, see [input](./js-service-widget-basic-input.md) and [list](js-service-widget-container-list.md).
