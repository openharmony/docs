# Cross-Device Notification Overview

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The cross-device notification is designed to implement collaborative interaction of notifications between a smartphone and another devices such as a watch. Typical scenarios are as follows:

<!--Del-->
  - [Cross-Device Notification Management (for System Applications Only)](./notification-distributed-notdistributed.md): Configure cross-device notifications for system applications and enable this feature as required.
<!--DelEnd-->
  - [Enabling Quick Reply for Cross-Device Notifications](./notification-quickreply.md): Enable quick reply for social communication applications so that users can quickly reply messages across devices.
  - [Clearing Repeated Notifications Across Devices](./notification-distributed-messageid.md): Clear repeated notifications published across devices and by the local device to prevent multiple notifications from disturbing users.

## Constraints
  - Cross-device notification is supported between phones and watches since API version 18, and between phones and tablets or 2-in-1 devices since API version 20.
  - [Notification slot types](../../application-dev/reference/apis-notification-kit/js-apis-notificationManager.md#slottype) supported for cross-device notification:
    - Watch: **SOCIAL_COMMUNICATION** and **LIVE_VIEW**.
    - Tablet: **SOCIAL_COMMUNICATION**, **SERVICE_INFORMATION**, **LIVE_VIEW**, and **CUSTOMER_SERVICE**.
    - 2-in-1 device: **SOCIAL_COMMUNICATION**, **SERVICE_INFORMATION**, and **CUSTOMER_SERVICE**.

## Working Principles

![distributed_overview](figures/distributed_overview.png)
