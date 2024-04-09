# Common Events of the NFC Subsystem
This document lists the common system events provided by the NFC subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED
Indicates that the state of the device NFC adapter has changed.

- Value: usual.event.nfc.action.ADAPTER_STATE_CHANGED
- Required subscriber permissions: none

When the state of the device NFC adapter changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED
Indicates that the NFC RF field is on.

- Value: usual.event.nfc.action.RF_FIELD_ON_DETECTED
- Required subscriber permissions: ohos.permission.MANAGE_SECURE_SETTINGS

When the NFC RF field becomes available, the event notification service is triggered to publish this event.

## COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED
Indicates that the NFC RF field is off.

- Value: usual.event.nfc.action.RF_FIELD_OFF_DETECTED
- Required subscriber permissions: ohos.permission.MANAGE_SECURE_SETTINGS

When the NFC RF field becomes unavailable, the event notification service is triggered to publish this event.
