# DFX Subsystem Changelog

## cl.hiviewdfx.1 Event Verification Specification Change for the write Method of the HiAppEvent Module

Extended the event verification specifications for the **write** method of the HiAppEvent module to support predefined events of HUAWEI Analytics. Specific changes are as follows:

  - The event name can start with a dollar sign ($) and can contain uppercase letters, lowercase letters, digits, and underscores (_). Before the change, the event name can contain lowercase letters, digits, and underscores (_).
  - The event parameter name can start with a dollar sign ($) and can contain uppercase letters, lowercase letters, digits, and underscores (_). Before the change, the event parameter name can contain lowercase letters, digits, and underscores (_).

**Change Impact**

More event definition formats are supported for event logging.

**Key API/Component Changes**

Involved APIs:

  - hiAppEvent.write;

**Adaptation Guide**

The event verification specifications are downward compatible. No additional adaptation is required.
