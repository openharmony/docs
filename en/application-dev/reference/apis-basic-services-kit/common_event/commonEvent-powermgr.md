# Common Events of the Power Management Subsystem
This document lists the common system events provided by the power management subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_BATTERY_CHANGED
Indicates that the charging state, level, and other information about the battery have changed.

- Value: usual.event.BATTERY_CHANGED
- Required subscriber permissions: none

When any of the following information changes, the event notification service is triggered to publish this event: battery level, battery voltage, battery temperature, battery health status, type of the charger connected to the device, maximum current of the charger, maximum voltage of the charger, battery charging status, number of charging times, total battery capacity, remaining battery capacity, battery model, current of the battery, and battery charging type.

## COMMON_EVENT_BATTERY_LOW
Indicates that the battery level is low.

- Value: usual.event.BATTERY_LOW
- Required subscriber permissions: none

When the battery level drops to lower than the low battery level set for the device, the event notification service is triggered to publish this event. For details about how to set the low battery level, see [Battery Level Customization](../../../../device-dev/subsystems/subsys-power-battery-level-customization.md).

## COMMON_EVENT_BATTERY_OKAY
Indicates that the battery level is normal.

- Value: usual.event.BATTERY_OKAY
- Required subscriber permissions: none

When the battery level changes from the low level to normal level, the event notification service is triggered to publish this event.

## COMMON_EVENT_POWER_CONNECTED
Indicates that the device is connected to an external power supply.

- Value: usual.event.POWER_CONNECTED
- Required subscriber permissions: none

When the device connects to an external charger, the event notification service is triggered to publish this event.

## COMMON_EVENT_POWER_DISCONNECTED
Indicates that the device is disconnected from the external power supply.

- Value: usual.event.POWER_DISCONNECTED
- Required subscriber permissions: none

When the device is disconnected from the external power supply, the event notification service is triggered to publish this event.

## COMMON_EVENT_DISCHARGING
Indicates that the system stops charging the battery.

- Value: usual.event.DISCHARGING
- Required subscriber permissions: none

When the system stops charging the battery, the event notification service is triggered to publish this event.

## COMMON_EVENT_CHARGING
Indicates that the system starts charging the battery.

- Value: usual.event.CHARGING
- Required subscriber permissions: none

When the system starts charging the battery, the event notification service is triggered to publish this event.

## COMMON_EVENT_CHARGE_TYPE_CHANGED
Indicates that the system charging type has changed. This event is available only for system applications.
- Value: usual.event.CHARGE_TYPE_CHANGED

- Required subscriber permissions: none

When the system charging type changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED
Indicates that the device enters the charging idle mode.

- Value: usual.event.CHARGE_IDLE_MODE_CHANGED
- Required subscriber permissions: none

When the device starts charging in idle mode, and the temperature rise is acceptable, the event notification service is triggered to publish this event.

## COMMON_EVENT_SHUTDOWN
Indicates that the device is being and will be shut down.

- Value: usual.event.SHUTDOWN
- Required subscriber permissions: none

When the device is being shut down until it is powered off, the event notification service is triggered to publish this event.

## COMMON_EVENT_SCREEN_OFF
Indicates that the device screen is off and the device is in sleep mode.

- Value: usual.event.SCREEN_OFF
- Required subscriber permissions: none

When the device screen is turned off and the device is in sleep mode, the event notification service is triggered to publish this event.

## COMMON_EVENT_SCREEN_ON
Indicates that the device screen is on and the device is in the active state.

- Value: usual.event.SCREEN_ON
- Required subscriber permissions: none

When the device screen is turned on and in the active state, the event notification service is triggered to publish this event.

## COMMON_EVENT_POWER_SAVE_MODE_CHANGED
Indicates that the system power saving mode has changed.

- Value: usual.event.POWER_SAVE_MODE_CHANGED
- Required subscriber permissions: none

When the system power saving mode changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_THERMAL_LEVEL_CHANGED
Indicates that the device's thermal level has changed.

- Value: usual.event.THERMAL_LEVEL_CHANGED
- Required subscriber permissions: none

When the device's thermal level changes, the event notification service is triggered to publish this event. For details about how to configure the thermal level, see [Thermal Level Customization](../../../../device-dev/subsystems/subsys-thermal_level.md).
