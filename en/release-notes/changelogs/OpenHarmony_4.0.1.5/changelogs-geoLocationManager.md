# Location Subsystem ChangeLog

## cl.location.1 Deletion of the geoLocationManager.requestEnableLocation API in API Version 9

When the location function is disabled, your application can call the **geoLocationManager.requestEnableLocation** API to request the user to enable the location function. However, this API is seldom used because the user is not notified of the scenario in which your application uses the location information.

Therefore, your application shows a popup, asking the user to go to the settings page and enable the location function. In addition, the popup clearly states the scenarios in which the location information will be used, improving user experience.

**Change Impacts**

Your application cannot use the **geoLocationManager.requestEnableLocation** API in API version 9 to request the user to enable the location function. Instead, you need to implement a popup asking the user to enable the location function for your application.

**Key API/Component Changes**

| Class              | API Type| Declaration                                                    | Change Type          |
| ------------------ | -------- | ------------------------------------------------------------ | ------------------ |
| geoLocationManager | method   | function requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;): void; | Deleted from API version 9|
| geoLocationManager | method   | function requestEnableLocation(): Promise&lt;boolean&gt;;    | Deleted from API version 9|
