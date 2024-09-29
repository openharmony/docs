# System Common Events (System API)

This document provides a list of common events defined by the system.

Common event types are defined in [Support enumeration of the ohos.commonEventManager module](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-commonEventManager.md#support).

> **NOTE**
>
> The current page contains only the system APIs of this module. For details about other public APIs, see [System Common Events](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md).


## Ability Kit


### COMMON_EVENT_BOOT_COMPLETED

Indicates that the boot is complete and the system is loaded.

When the specified user finishes the boot process on the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.RECEIVER_STARTUP_COMPLETED (for system applications only)

**Value:** "usual.event.BOOT_COMPLETED"

### COMMON_EVENT_PACKAGE_INSTALLATION_STARTED<sup>12+</sup>

Indicates that a package is sent by the system verifier when the package is verified.

When a new application starts to be installed by a specified user on the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** "usual.event.PACKAGE_INSTALLATION_STARTED"



## Background Tasks Kit 

### COMMON_EVENT_DEVICE_IDLE_EXEMPTION_LIST_UPDATED<sup>10+</sup>

Indicates that the exemption list for resource usage restrictions has been updated in idle mode.

When the exemption list for resource usage restrictions is updated, the event notification service is triggered to publish this event.
Resources include application network access, Timer usage, and WorkScheduler task usage.

System applications can call JavaScript APIs to apply for removing resource usage restrictions.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** "usual.event.DEVICE_IDLE_EXEMPTION_LIST_UPDATED"




## Basic Services Kit - Power Supply

### COMMON_EVENT_CHARGE_TYPE_CHANGED<sup>10+</sup>

Indicates that the system charging type has changed.

When the system charging type changes, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** "usual.event.CHARGE_TYPE_CHANGED"


### COMMON_EVENT_USER_ADDED

Indicates that a user has been added to the system.

When a system account is created, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **createOsAccount** and **createOsAccountForDomain**. These APIs are system APIs. For details, see [@ohos.account.osAccount (System Account Management)](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-osAccount.md).

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only)

**Value:** "usual.event.USER_ADDED"


### COMMON_EVENT_USER_REMOVED

Indicates that a user has been removed from the system.

When a system account is removed, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **removeOsAccount**. This API is a system API. For details, see [@ohos.account.osAccount (System Account Management)](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-osAccount.md).

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only)

**Value:** "usual.event.USER_REMOVED"


### COMMON_EVENT_DOMAIN_ACCOUNT_STATUS_CHANGED

Indicates that the status of the domain account status changes.

When a domain user account is authenticated, deleted, or has the token updated, the event notification service is triggered to publish this event carrying the system account ID, domain name, and account status.

APIs related to this event: **removeOsAccount**, **DomainAccountManager.auth**, and **updateAccountToken**. These APIs are system APIs. For details, see [@ohos.account.osAccount (System Account Management)](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-osAccount.md).

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.GET_LOCAL_ACCOUNTS (for system applications only)

**Value:** "usual.event.DOMAIN_ACCOUNT_STATUS_CHANGED"


### COMMON_EVENT_USER_SWITCHED

Indicates that a user switchover is complete.

When a system account is switched, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **activateOsAccount**. This API is a system API. For details, see [@ohos.account.osAccount (System Account Management)](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-osAccount.md).

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only)

**Value:** "usual.event.USER_SWITCHED"




## Core File Kit

This document lists the common system events provided by the file management subsystem to applications. Applications can use [APIs](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-commonEventManager.md) to subscribe to common system events.


### COMMON_EVENT_VOLUME_REMOVED

Indicates that an external storage device was removed.

This common event is triggered when an external storage device is removed.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.STORAGE_MANAGER

**Value:** "usual.event.data.VOLUME_REMOVED"

### COMMON_EVENT_VOLUME_UNMOUNTED

Indicates that an external storage device was unmounted.

This common event is triggered when an external storage device is successfully unmounted by calling the **unmount** API or by removing the device.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.STORAGE_MANAGER

**Value:** "usual.event.data.VOLUME_UNMOUNTED"


### COMMON_EVENT_VOLUME_MOUNTED

Indicates that an external storage device was mounted.

This common event is triggered when an external storage device is successfully mounted by calling the **mount** API or by inserting the device.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.STORAGE_MANAGER

**Value:** "usual.event.data.VOLUME_MOUNTED"


### COMMON_EVENT_VOLUME_BAD_REMOVAL

Indicates that an external storage device was removed without being unmounted.

This common event is triggered when an external storage device is directly removed without being unmounted.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.STORAGE_MANAGER

**Value:** "usual.event.data.VOLUME_BAD_REMOVAL"


### COMMON_EVENT_VOLUME_EJECT

Indicates that an external storage device is about to be ejected.

This common event is triggered when the user calls the **unmount** API on a mounted external storage device or removes the device.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.STORAGE_MANAGER

**Value:** "usual.event.data.VOLUME_EJECT"



## Telephony Kit

### COMMON_EVENT_SMS_RECEIVE_COMPLETED<sup>10+</sup>

Indicates that an SMS message is received.

When the device receives an SMS message, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.RECEIVE_SMS (for system apps only)

**Value:** usual.event.SMS_RECEIVED_COMPLETED


### COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED<sup>10+</sup>

Indicates that an emergency cell broadcast message is received.

When the device receives an emergency cell broadcast message, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.RECEIVE_SMS (for system apps only)

**Value:** usual.event.SMS_EMERGENCY_CB_RECEIVE_COMPLETED


### COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED<sup>10+</sup>

Indicates that a cell broadcast message is received.

When the device receives a cell broadcast message, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.RECEIVE_SMS (for system apps only)

**Value:** usual.event.SMS_CB_RECEIVE_COMPLETED

### COMMON_EVENT_OPERATOR_CONFIG_CHANGED<sup>10+</sup>

Indicates that the carrier configuration has been updated.

When the carrier configuration of the device is updated, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.OPERATOR_CONFIG_CHANGED


### COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED<sup>10+</sup>

Indicates that the default primary SIM card for the SMS service has been updated.

When the default primary SIM card for the SMS service is updated, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.DEFAULT_SMS_SUBSCRIPTION_CHANGED


### COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED<sup>10+</sup>

Indicates that the default primary SIM card for the data service has been updated.

When the default primary SIM card for the data service is updated, the event notification service is triggered to release the system common event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.DEFAULT_DATA_SUBSCRIPTION_CHANGED


### COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED<sup>10+</sup>

Indicates that the default primary SIM card of the device has been updated.

When the default primary SIM card of the device is updated, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.SIM.DEFAULT_MAIN_SUBSCRIPTION_CHANGED


### COMMON_EVENT_SET_PRIMARY_SLOT_STATUS<sup>11+</sup>

Indicates that the status of the action for setting the primary SIM card changes.

When the status of the action for setting the primary SIM card changes (for example, when the status is updated to executing or completed), the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.SET_PRIMARY_SLOT_STATUS


### COMMON_EVENT_PRIMARY_SLOT_ROAMING<sup>11+</sup>

Indicates that the roaming status of the default primary SIM card is updated.

When the roaming status of the default primary SIM card changes, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.PRIMARY_SLOT_ROAMING


### COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED<sup>10+</sup>

Indicates that the default primary SIM card for the data service has been updated. 

When the default primary SIM card for the voice service is updated, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.DEFAULT_VOICE_SUBSCRIPTION_CHANGED


### COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED<sup>10+</sup>

Indicates that the cellular data status has been updated.

When the cellular data status of the device is updated, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.CELLULAR_DATA_STATE_CHANGED


### COMMON_EVENT_INCOMING_CALL_MISSED<sup>10+</sup>

Indicates that an incoming call is missed.

When an incoming call is missed on the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.GET_TELEPHONY_STATE (for system apps only)

**Value:** usual.event.INCOMING_CALL_MISSED


### COMMON_EVENT_RADIO_STATE_CHANGE<sup>10+</sup>

Indicates that the radio status of the device has changed.

When there is a change in the radio status of the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.RADIO_STATE_CHANGE


### COMMON_EVENT_SPECIAL_CODE<sup>10+</sup>

Indicates that a secret code is sent successfully.

When a secret code is successfully sent on the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.DIALER_SPECIAL_CODE


### COMMON_EVENT_AUDIO_QUALITY_CHANGE<sup>10+</sup>

Indicates that the audio quality has changed.

When there is a change in the audio quality of the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.AUDIO_QUALITY_CHANGE




## Reserved Common Event

Below are reserved common events that are not supported yet.

### COMMON_EVENT_STK_COMMAND<sup>10+</sup>

(Reserved, not supported yet) Indicates that an STK command is sent.

When an STK command is sent, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.STK_COMMAND


### COMMON_EVENT_STK_SESSION_END<sup>10+</sup>

(Reserved, not supported yet) Indicates that an STK session has ended.

When an STK session ends, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.STK_SESSION_END


### COMMON_EVENT_STK_CARD_STATE_CHANGED<sup>10+</sup>

(Reserved, not supported yet) Indicates that the STK card status has been updated.

When the STK card status is updated, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none


**Value:** usual.event.STK_CARD_STATE_CHANGED

### COMMON_EVENT_STK_ALPHA_IDENTIFIER<sup>10+</sup>

(Reserved, not supported yet) Indicates that an STK Alpha identifier is sent.

When an STK Alpha identifier is sent, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** none

**Value:** usual.event.STK_ALPHA_IDENTIFIER


### COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED<sup>10+</sup>

(Reserved, not supported yet) Indicates that a WAP push message is received.

When the device receives a WAP push message, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.RECEIVE_SMS (for system apps only)

**Value:** usual.event.SMS_WAPPUSH_RECEIVE_COMPLETED
