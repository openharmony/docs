# mDNS Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2100002 Service Connection Failure

**Error Message**

Failed to connect to the service.

**Description**

This error code is reported if a service connection failure occurs.

**Possible Causes**

The service is abnormal.

**Procedure**

Check whether system services are running properly.

## 2100003 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if a system internal error occurs.

**Possible Causes**

1. The memory is abnormal.

2. A null pointer is present.

**Procedure**

1. Check whether the memory space is sufficient. If not, clear the memory and try again.

2. Check whether the system is normal. If not, try again later or restart the device.

## 2204003 Repeated Registration

**Error Message**

Callback duplicated.

**Description**

This error code is reported if a callback already exists.

**Possible Causes**

An mDNS service with the same name and type is repeatedly registered.

**Procedure**

Check whether the mDNS service to be registered already exists.

## 2204007 Service Already Exists

**Error Message**

Service instance duplicated.

**Description**

This error code is reported if an mDNS service already exists.

**Possible Causes**

The previously registered mDNS service is still running.

**Procedure**

Check whether the mDNS service already exists.

## 2204008 Service Deletion Failure

**Error Message**

Failed to delete the service instance.

**Description**

This error code is reported if the mDNS service to be removed does not exist.

**Possible Causes**

The service has been deleted.

**Procedure**

Check whether the mDNS service to be deleted exists.

## 2204010 Message Sending Failure

**Error Message**

Failed to send the message.

**Description**

This error code is reported if messages fail to be sent through an mDNS service.

**Possible Causes**

The mDNS service does not exist on the LAN.

**Procedure**

Check whether the target mDNS service exists on the LAN.

## 2204006 Service Resolution Timeout

**Error Message**

Request timeout.

**Description**

This error code is reported if mDNS services of the specified type fail to be resolved.

**Possible Causes**

mDNS services of the specified type do not exist on the LAN.

**Procedure**

Check whether mDNS services of the specified type exist on the LAN.
