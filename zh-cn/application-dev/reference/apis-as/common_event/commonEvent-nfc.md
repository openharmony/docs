# NFC子系统公共事件定义
NFC子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED
指示设备NFC状态已更改的公共事件的操作。

- 常量值：usual.event.nfc.action.ADAPTER_STATE_CHANGED
- 订阅者所需权限：无

指示设备NFC状态更改时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED
检测到NFC场强进入的公共事件。

- 常量值：usual.event.nfc.action.RF_FIELD_ON_DETECTED
- 订阅者所需权限：ohos.permission.MANAGE_SECURE_SETTINGS

当检测到NFC场强进入时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED
检测到NFC场强离开的公共事件。

- 常量值：usual.event.nfc.action.RF_FIELD_OFF_DETECTED
- 订阅者所需权限：ohos.permission.MANAGE_SECURE_SETTINGS

当检测到NFC场强离开时，将会触发事件通知服务发布该系统公共事件。