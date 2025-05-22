# Traffic Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2100001 Invalid Parameters

**Error Information**

Invalid parameter value.

**Description**

This error code is reported if any input parameter value is incorrect.

**Possible Causes**

The end time is earlier than the start time.

**Solution**

Check whether the start time and end time are properly set.


## 2100002 Service Connection Failure

**Error Information**

Failed to connect to the service.

**Description**

This error code is reported if a service connection failure occurs.

**Possible Causes**

The service is abnormal.

**Solution**

Check whether system services are running properly.

## 2100003 System Internal Error

**Error Information**

System internal error.

**Description**

This error code is reported if an internal system error occurs.

**Possible Causes**

1. The memory is abnormal.

2. A null pointer is present.

**Solution**

1. Check whether the memory space is sufficient. If not, clear the memory and try again.

2. Check whether the system is normal. If not, try again later or restart the device.

## 2103005 Failed to Read the System Map

**Error Information**

Failed to read the system map.

**Description**

This error code is reported if the attempt to read the system map fails.

**Possible Causes**

The attempt to read traffic data on the kernel map object fails.

**Solution**

Check whether traffic is generated for the specified NIC or application.

## 2103011 Failed to Create a System Map

**Error Information**

Failed to create a system map.

**Description**

This error code is reported if the attempt to create a kernel map object fails.

**Possible Causes**

No traffic is generated on the NIC and therefore a kernel traffic object has not been created.

**Solution**

Ensure that traffic is generated on the NIC.

## 2103012 Failed to Obtain the NIC Name

**Error Information**

Failed to obtain the NIC name.

**Description**

This error code is reported if the attempt to obtain the NIC name fails.

**Possible Causes**

The NIC name does not exist on the local host.

**Solution**

Check whether the input NIC name is correct.

## 2103017 Failed to Read the Database

**Error Information**

Failed to read the database.

**Description**

This error code is reported if the attempt to read the database fails.

**Possible Causes**

The database is damaged.

**Solution**

Check whether the database file on the local host is damaged.
