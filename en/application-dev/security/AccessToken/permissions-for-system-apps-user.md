# user_grant Permissions for System Applications

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

Before requesting permissions for your application, read and understand the [permission request paths](determine-application-mode.md) and this topic to determine the permissions required.

> **NOTE**
>
> - The permissions listed in this topic are available to system_basic or higher-level applications, but not to normal applications.
> - The authorization mode of these permissions is user_grant.
> - Applications of a lower APL can request these permissions via [Access Control List (ACL)](app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

For details about the process for requesting permissions, see [Workflow for Requesting Permissions](determine-application-mode.md).

## ohos.permission.GET_INSTALLED_BUNDLE_LIST

Allows an application to obtain the list of installed applications.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 10

## ohos.permission.ANSWER_CALL

Allows an application to answer incoming calls.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 9

## ohos.permission.MANAGE_VOICEMAIL

Allows an application to manage messages in the voice mailbox.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.READ_CALL_LOG

Allows an application to read call logs.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.READ_CELL_MESSAGES

Allows an application to read cell broadcast messages received by the device.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.READ_MESSAGES

Allows an application to read messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.RECEIVE_MMS

Allows an application to receive and process MMS messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.RECEIVE_SMS

Allows an application to receive and process SMS messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.RECEIVE_WAP_MESSAGES

Allows an application to receive and process WAP messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.SEND_MESSAGES

Allows an application to send messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.WRITE_CALL_LOG

Allows an application to add, remove, and edit call logs.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.cli.WRITE_ACCESSIBILITY_CONFIG_VISION

Allows a system application to use visual-related accessibility functions via CLI commands.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.WRITE_ACCESSIBILITY_CONFIG_HEARING

Allows a system application to use hearing-related accessibility functions via CLI commands.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.WRITE_ACCESSIBILITY_CONFIG_ACTION

Allows a system application to use interaction-related accessibility functions via CLI commands.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.BUNDLE_ACTIVE_INFO

Allows an application to query the running status of specific applications using CLI commands.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 26.0.0

## ohos.permission.cli.INSTALL_BUNDLE

Allows an application to install and uninstall applications other than enterprise applications using CLI commands.

**Permission level**: system_core

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.UNINSTALL_BUNDLE

Allows an application to uninstall specific applications using CLI commands.

**Permission level**: system_core

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.GET_BUNDLE_INFO_PRIVILEGED

Allows an application to query information about specific applications using CLI commands, such as the bundle name and version.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.REMOVE_BUNDLE_DATA_AND_CACHE_FILES

Allows an application to clear the cache and data (including internal and external storage) of a specified application using CLI commands.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.MANAGE_DISPOSED_APP_STATUS

Allows an application to set and query the disposition status of specific applications using CLI commands.

**Permission level**: system_core

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.MANAGE_WIFI_TOGGLE

Allows an application to enable or disable Wi-Fi via CLI commands.

**Permission level**: system_core

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.MANAGE_WIFI_SCAN

Allows an application to set Wi-Fi scanning via CLI commands.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0

## ohos.permission.cli.MANAGE_WIFI_CONNECT

Allows an application to set Wi-Fi connections via CLI commands.

**Permission level**: system_core

**Authorization mode**: user_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Since**: 26.0.0
