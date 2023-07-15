# Common Events of the Telephony Subsystem
This document lists the common system events provided by the telephony subsystem to applications.


## COMMON_EVENT_SIM_STATE_CHANGED

Indicates that the SIM card status has changed.

- Value: usual.event.SIM_STATE_CHANGED
- Required subscriber permissions: none

When the there is a change in the SIM card status of the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_SMS_RECEIVED_COMPLETED

Indicates that an SMS message is received.

- Value: usual.event.SMS_RECEIVED_COMPLETED
- Required subscriber permissions: ohos.permission.RECEIVE_SMS

When the device receives an SMS message, the event notification service is triggered to publish this event.

## COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED

Indicates that an emergency cell broadcast message is received.

- Value: usual.event.SMS_EMERGENCY_CB_RECEIVE_COMPLETED
- Required subscriber permissions: ohos.permission.RECEIVE_SMS

When the device receives an emergency cell broadcast message, the event notification service is triggered to publish this event.

## COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED

Indicates that a cell broadcast message is received.

- Value: usual.event.SMS_CB_RECEIVE_COMPLETED
- Required subscriber permissions: ohos.permission.RECEIVE_SMS

When the device receives a cell broadcast message, the event notification service is triggered to publish this event.

## COMMON_EVENT_STK_COMMAND

(Reserved, not supported yet) Indicates that an STK command is sent.

- Value: usual.event.STK_COMMAND
- Required subscriber permissions: none

When an STK command is sent, the event notification service is triggered to publish this event.

## COMMON_EVENT_STK_SESSION_END

(Reserved event, not supported currently) Indicates that an STK session has ended.

- Value: usual.event.STK_SESSION_END
- Required subscriber permissions: none

When an STK session ends, the event notification service is triggered to publish this event.

## COMMON_EVENT_STK_CARD_STATE_CHANGED

(Reserved event, not supported currently) Indicates that the STK card status has been updated.

- Value: usual.event.STK_CARD_STATE_CHANGED
- Required subscriber permissions: none

When the STK card status is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_STK_ALPHA_IDENTIFIER

(Reserved event, not supported currently) Indicates that an STK Alpha identifier is sent.

- Value: usual.event.STK_ALPHA_IDENTIFIER
- Required subscriber permissions: none

When an STK Alpha identifier is sent, the event notification service is triggered to publish this event.

## COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED

Indicates that a WAP push message is received.

- Value: usual.event.SMS_WAPPUSH_RECEIVE_COMPLETED
- Required subscriber permissions: ohos.permission.RECEIVE_SMS

When the device receives a WAP push message, the event notification service is triggered to publish this event.

## COMMON_EVENT_OPERATOR_CONFIG_CHANGED

Indicates that the carrier configuration has been updated.

- Value: usual.event.OPERATOR_CONFIG_CHANGED
- Required subscriber permissions: none

When the carrier configuration of the device is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED

Indicates that the default primary SIM card for the SMS service has been updated.

- Value: usual.event.DEFAULT_SMS_SUBSCRIPTION_CHANGED
- Required subscriber permissions: none

When the default primary SIM card for the SMS service is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED

Indicates that the default primary SIM card for the data service has been updated.

- Value: usual.event.DEFAULT_DATA_SUBSCRIPTION_CHANGED
- Required subscriber permissions: none

When the default primary SIM card for the data service is updated, the event notification service is triggered to release the system common event.

## COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED

Indicates that the default primary SIM card of the device has been updated.

- Value: usual.event.SIM.DEFAULT_MAIN_SUBSCRIPTION_CHANGED
- Required subscriber permissions: none

When the default primary SIM card of the device is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED

When the default primary SIM card for the voice service is updated, the event notification service is triggered to publish this event.

- Value: usual.event.DEFAULT_VOICE_SUBSCRIPTION_CHANGED
- Required subscriber permissions: none

When the default primary SIM card for the voice service is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_CALL_STATE_CHANGED

Indicates that the call status has been updated.

- Value: usual.event.CALL_STATE_CHANGED
- Required subscriber permissions: ohos.permission.GET_TELEPHONY_STATE

When the call status of the device is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED

Indicates that the cellular data status has been updated.

- Value: usual.event.CELLULAR_DATA_STATE_CHANGED
- Required subscriber permissions: none

When the cellular data status of the device is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_NETWORK_STATE_CHANGED

Indicates that the network status has been updated.

- Value: usual.event.NETWORK_STATE_CHANGED
- Required subscriber permissions: none

When the network status of the device is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_SIGNAL_INFO_CHANGED

Indicates that the signal information has been updated.

- Value: usual.event.SIGNAL_INFO_CHANGED
- Required subscriber permissions: none

When the signal information of the device is updated, the event notification service is triggered to publish this event.

## COMMON_EVENT_INCOMING_CALL_MISSED

Indicates that an incoming call is missed.

- Value: usual.event.INCOMING_CALL_MISSED
- Required subscriber permissions: ohos.permission.GET_TELEPHONY_STATE

When an incoming call is missed on the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_RADIO_STATE_CHANGE

Indicates that the radio status of the device has changed.

- Value: usual.event.RADIO_STATE_CHANGE
- Required subscriber permissions: none

When there is a change in the radio status of the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_DIALER_SPECIAL_CODE

Indicates that a secret code is sent successfully.

- Value: usual.event.DIALER_SPECIAL_CODE
- Required subscriber permissions: none

When a secret code is successfully sent on the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_AUDIO_QUALITY_CHANGE

Indicates that the audio quality has changed.

- Value: usual.event.AUDIO_QUALITY_CHANGE
- Required subscriber permissions: none

When there is a change in the audio quality of the device, the event notification service is triggered to publish this event.
