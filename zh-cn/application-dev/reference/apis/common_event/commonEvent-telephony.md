# 电话服务子系统公共事件定义
电话服务子系统面向应用发布如下系统公共事件。


## COMMON_EVENT_SIM_STATE_CHANGED

提示SIM卡状态更新。

- 值：usual.event.SIM_STATE_CHANGED
- 订阅者所需权限：无

在设备上面的SIM卡状态发生变化时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SMS_RECEIVED_COMPLETED

提示短信接收完成。

- 值：usual.event.SMS_RECEIVED_COMPLETED
- 订阅者所需权限：ohos.permission.RECEIVE_SMS

在设备接收到短信时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED

提示紧急小区广播短信接收完成。

- 值：usual.event.SMS_EMERGENCY_CB_RECEIVE_COMPLETED
- 订阅者所需权限：ohos.permission.RECEIVE_SMS

在设备接收到紧急小区广播短信时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED

提示小区广播短信接收完成。

- 值：usual.event.SMS_CB_RECEIVE_COMPLETED
- 订阅者所需权限：ohos.permission.RECEIVE_SMS

在设备接收到小区广播短信时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_STK_COMMAND

（预留事件，暂未支持）提示STK命令。

- 值：usual.event.STK_COMMAND
- 订阅者所需权限：无

在发送STK命令时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_STK_SESSION_END

（预留事件，暂未支持）提示STK会话结束。

- 值：usual.event.STK_SESSION_END
- 订阅者所需权限：无

在STK会话结束时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_STK_CARD_STATE_CHANGED

（预留事件，暂未支持）提示STK卡状态已更新。

- 值：usual.event.STK_CARD_STATE_CHANGED
- 订阅者所需权限：无

在STK卡状态更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_STK_ALPHA_IDENTIFIER

（预留事件，暂未支持）提示STK ALPHA标识符。

- 值：usual.event.STK_ALPHA_IDENTIFIER
- 订阅者所需权限：无

在发送STK ALPHA标识符时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED

提示服务信息短信接收完成。

- 值：usual.event.SMS_WAPPUSH_RECEIVE_COMPLETED
- 订阅者所需权限：ohos.permission.RECEIVE_SMS

在设备接收短信完成时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_OPERATOR_CONFIG_CHANGED

提示运营商配置已更新。

- 值：usual.event.OPERATOR_CONFIG_CHANGED
- 订阅者所需权限：无

在设备运营商配置更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED

提示SIM卡默认短信主卡已更新。

- 值：usual.event.DEFAULT_SMS_SUBSCRIPTION_CHANGED
- 订阅者所需权限：无

在设备SIM卡默认短信主卡更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED

提示SIM卡默认数据主卡已更新。

- 值：usual.event.DEFAULT_DATA_SUBSCRIPTION_CHANGED
- 订阅者所需权限：无

在设备SIM卡默认数据主卡更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED

提示SIM卡默认主卡已更新。

- 值：usual.event.SIM.DEFAULT_MAIN_SUBSCRIPTION_CHANGED
- 订阅者所需权限：无

在设备SIM卡默认主卡更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SET_PRIMARY_SLOT_STATUS

提示SIM卡默认主卡的设置状态，已完成或执行中。

- 值：usual.event.SET_PRIMARY_SLOT_STATUS
- 订阅者所需权限：无

在设备设置SIM卡默认主卡的执行状态发生变化时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_PRIMARY_SLOT_ROAMING

提示SIM卡默认主卡的漫游状态已更新。

- 值：usual.event.PRIMARY_SLOT_ROAMING
- 订阅者所需权限：无

在设备SIM卡默认主卡的漫游状态发生变化时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED

提示SIM卡默认语音主卡已更新。

- 值：usual.event.DEFAULT_VOICE_SUBSCRIPTION_CHANGED
- 订阅者所需权限：无

在设备SIM卡默认语音主卡更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_CALL_STATE_CHANGED

提示呼叫状态更新。

- 值：usual.event.CALL_STATE_CHANGED
- 订阅者所需权限：ohos.permission.GET_TELEPHONY_STATE

在设备呼叫状态更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED

提示蜂窝数据状态更新。

- 值：usual.event.CELLULAR_DATA_STATE_CHANGED
- 订阅者所需权限：无

在设备蜂窝数据状态更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_NETWORK_STATE_CHANGED

提示网络状态更新。

- 值：usual.event.NETWORK_STATE_CHANGED
- 订阅者所需权限：无

在设备网络状态更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SIGNAL_INFO_CHANGED

提示信号信息更新。

- 值：usual.event.SIGNAL_INFO_CHANGED
- 订阅者所需权限：无

在设备信号信息更新时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_INCOMING_CALL_MISSED

提示未接来电。

- 值：usual.event.INCOMING_CALL_MISSED
- 订阅者所需权限：ohos.permission.GET_TELEPHONY_STATE

在设备有未接来电时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_RADIO_STATE_CHANGE

提示设备modem上下电状态变化。

- 值：usual.event.RADIO_STATE_CHANGE
- 订阅者所需权限：无

在设备modem上下电状态变化时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_DIALER_SPECIAL_CODE

提示暗码发送成功。

- 值：usual.event.DIALER_SPECIAL_CODE
- 订阅者所需权限：无

在设备上发送暗码成功时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_AUDIO_QUALITY_CHANGE

提示音频质量发生变化。

- 值：usual.event.AUDIO_QUALITY_CHANGE
- 订阅者所需权限：无

在设备音频质量发送变化时，将会触发事件通知服务发布该系统公共事件。
