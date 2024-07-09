# Common Events of the Notification Service
This document lists the common system events provided by the notification service to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_SLOT_CHANGE
Indicates that the notification slot or notification switch settings have changed.

- Value: "usual.event.SLOT_CHANGE"
- Required subscriber permissions: ohos.permission.NOTIFICATION_CONTROLLER (for system apps only)

When the notification slot settings (including the switch) change or the notification feature is enabled or disabled, the notification service is triggered to publish this event.

APIs related to this common event: **setSlotByBundle**, **setNotificationEnableSlot**, and **setNotificationEnable**, which are system APIs called by notification setting apps. For details, see [@ohos.notificationManager (NotificationManager)](../../apis-notification-kit/js-apis-notificationManager.md).
