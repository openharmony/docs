# Ethernet Connection Error Codes

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

## 2201005 Device Information Not Exist

**Error Message**

The device information does not exist.

**Description**

This error code is reported if the device information does not exist.

**Cause**

The device to set or obtain does not exist.

**Procedure**

```
> hdc shell ifconfig
```
Check whether the device, for example, **eth0** or **eth1**, exists.

## 2201006 Device Not Connected

**Error Message**

Device disconnected.

**Description**

This error code is reported if the device is not connected.

**Cause**

The network interface card (NIC) is faulty.

**Procedure**

View the Ethernet service and netsys logs to check for the connection status information reported by the kernel.

## 2201007 Failed to Write the User Configuration

**Error Message**

Failed to write the user configuration.

**Description**

This error code is reported if an error occurs while writing data to the user configuration file.

**Cause**

The system reports an error.

**Procedure**

A system internal error occurs. You are advised to locate the fault based on logs.
