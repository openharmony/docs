# Account Subsystem Changelog

## cl.account_os_account.1. queryDistributedVirtualDeviceld Error Code Change

**Access Level**

Public API

**Reason for Change**

According to the JS error code specifications, error 201 is returned when access is denied due to insufficient permission. However, error 12300001 (system error) is also returned when access is denied due to insufficient permission. Developers cannot determine the error based on the error code thrown.

**Change Impact**

This change is a non-compatible change.

Before the change: 

If the caller does not have the permission when calling **queryDistributedVirtualDeviceld**, error 12300001 is returned.

After the modification: 

If the caller does not have the permission when calling **queryDistributedVirtualDeviceld**, error 201 is returned.

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

queryDistributedVirtualDeviceld

**Adaptation Guide**

No adaptation is required because the problem can be detected during development.
