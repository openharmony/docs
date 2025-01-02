# Input Consumer Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 4200002 Shortcut Key Already Registered by a System Application

**Error Message**

The hotkey has been used by the system.

**Description**

This error code is reported if the shortcut key has been registered by a system application.

**Possible Cause**

1. The shortcut key has been registered by a system application.

**Solution**

1. Call **inputConsumer.getAllSystemHotkeys** to query all registered shortcut keys and use any available shortcut keys.

## 4200003 Shortcut Key Already Registered by a Third-party Application

**Error Message**

The hotkey has been subscribed to by another.

**Description**

This error code is generated when the shortcut key is registered by a third-party application.

**Possible Cause**

1. The shortcut key has been registered by a third-party application.

**Solution**

1. In the cmd window, run **hidumper -s 3101 -a -s** to query all registered shortcut keys and use any available shortcut keys.
