# Network Sharing Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2200001 Invalid Parameter Value

**Error Message**

Invalid parameter value.

**Description**

This error code is reported if the parameter value is invalid.

**Cause**

The input parameter value is not within the valid value range.

**Procedure**

Check whether the input parameter value is within the valid value range.

## 2200002 Service Connection Failure

**Error Message**

Failed to connect to the service.

**Description**

This error code is reported if a service connection failure occurs.

**Cause**

The service is abnormal.

**Procedure**

Check whether system services are running properly.

## 2200003 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if a system internal error occurs.

**Cause**

1. The memory is abnormal.

2. A null pointer is present.

**Procedure**

1. Check whether the memory space is sufficient. If not, clear the memory and try again.

2. Check whether the system is normal. If not, try again later or restart the device.

## 2202004 Shared Iface Unavailable

**Error Message**

Try to share an unavailable iface.

**Description**

This error code is reported if an Iface is used.

**Cause**

The specified Iface does not exist or the Iface name is incorrect.

**Procedure**

1. Run **ifconfig -a** to check whether the shared Iface is available.

2. Check whether the Iface name is correct.

## 2202005 Wi-Fi Sharing Failure

**Error Message**

WiFi sharing failed.

**Description**

This error code is reported if Wi-Fi sharing fails.

**Cause**

No connected network is available and therefore the attempt to obtain the default network fails.

**Procedure**

Check whether the network connection is normal.

## 2202006 Bluetooth Sharing Failure

**Error Message**

Bluetooth sharing failed.

**Description**

This error code is reported if Bluetooth sharing fails.

**Cause**

1. Bluetooth is disabled.

2. No connected network is available and therefore the attempt to obtain the default network fails.

**Procedure**

1. Touch the Bluetooth icon to turn on Bluetooth mode.

2. Check whether the network connection is normal.

## 2202009 Failed to Enable Forwarding for Network Sharing

**Error Message**

Failed to enable forwarding for network sharing.

**Description**

This error code is reported if an error occurs while enabling forwarding for network sharing.

**Cause**

The Iptables rule setting fails and therefore an error occurs while combining Iptables commands fails.

**Procedure**

Enable the debug log function, and check whether Iptables commands are correctly combined.

## 2202011 Failed to Obtain the Network Sharing Configuration

**Error Message**

Cannot get network sharing configuration.

**Description**

This error code is reported if an error occurs while obtaining the network sharing configuration.

**Cause**

The configuration file directory is incorrect.

**Procedure**

Specify a correct configuration file directory.
