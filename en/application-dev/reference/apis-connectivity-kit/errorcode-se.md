# SE Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 3300101 Abnormal SE Service Status

**Error Message**

IllegalStateError, an attempt is made to use an SE session that has been closed.

**Description**

The SecureElement (SE) service is abnormal.

**Possible Causes**

1. The SE service is disconnected.

**Solution**

1. Close the SE service.

2. Set up a connection with the SE service again.

## 3300102 No Such SE

**Error Message**

NoSuchElementError, the AID on the SE is not available or cannot be selected.

**Description**

The SE is unavailable.

**Possible Causes**

1. Communication with the SE service is abnormal.
2. Communication of the SE chip is abnormal.

**Solution**

1. Close the SE service and set up a connection with the SE service again.
2. Restart the device.

## 3300103 Failed to Obtain the Access Rule

**Error Message**

SecurityError, the calling application cannot be granted access to this AID or the default applet on this session.

**Description**

The access rule cannot be obtained.

**Possible Causes**

1. There is no access rule for the application on the SE.

**Solution**

1. Write correct access rules to the SE.
2. Close the SE service and set up a connection with the SE service again.

## 3300104 SE Chip I/O Exception

**Error Message**

IOError, there is a communication problem to the reader or the SE.

**Description**

The I/O of the SE chip is abnormal.

**Possible Causes**

1. The communication with the SE chip is abnormal.
2. The SE chip is abnormal.

**Solution**

1. Close the SE service and set up a connection with the SE service again.

2. Restart the device.
