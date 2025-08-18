# Telephony Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 8300001 Input Parameter Value Out of Range

**Error Message**

The input parameter value is out of range.

**Description**

This error code is reported if the value of the input parameter (for example, **slotId**) is not within the valid range. In this case, the API call will fail and the corresponding operation cannot be performed.

**Possible Causes**

The input parameter value is invalid.

**Procedure**

Enter a valid parameter value.



## 8300002 Service Connection Error

**Error Message**

Service connection failed.

**Description**

This error code is reported if the attempt to connect to a service fails.

**Possible Causes**

Service startup or IPC connection has failed.

**Procedure**

Operation error. Try again later.



## 8300003 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if an internal system error occurs.

**Possible Causes**

The possible cause is that data read/write has failed because the network is abnormal.

**Procedure**

Operation error. Try again later.


## 8300004 SIM Card Not Detected

**Error Message**

No SIM card found.

**Description**

This error code is reported if no SIM card is detected.

**Possible Causes**

No SIM card is inserted or the SIM card is not properly inserted.

**Procedure**

Insert the SIM card or remove and insert the SIM card again.


## 8300999 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported if an internal error occurs.

**Possible Causes**

The problem may arise due to insufficient memory, memory operation errors, or null pointers.

**Procedure**

Operation error. Try again later.


## 8301001 SIM Card Not Activated

**Error Message**

SIM card is not activated.

**Description**

This error code is reported if the SIM card is not activated.

**Possible Causes**

The SIM card is not activated.

**Procedure**

Activate the SIM card.


## 8301002 Failed to Read or Update SIM Card Data

**Error Message**

The SIM card failed to read or update data.

**Description**

This error code is reported if the attempt to read or update SIM card data has failed.

**Possible Causes**

The SIM card does not support the operation, or the SIM card is damaged.

**Procedure**

Contact the SIM card supplier, or replace the SIM card.


## 8301003 Incorrect SIM Card Configuration

**Error Message**

Operator config error.

**Description**

This error code is reported if the SIM card configuration is incorrect.

**Possible Causes**

The configuration file delivered with the SIM card is not properly preconfigured.

**Procedure**

Check whether the correct SIM card is inserted.

## 8401001 Failed to Connect to the UT

**Error Message**

UT is not connected.

**Description**

This error code is reported if the UT is not connected.

**Possible Causes**

The current carrier does not support sending of UT requests over a Wi-Fi network, but the phone is actually connected to the Wi-Fi network.

**Procedure**

Disconnect the Wi-Fi connection, and send a new UT request.


## 3120001 Service Connection Error

**Error Message**

Service connection failed.

**Description**

This error code is reported if the attempt to connect to a service fails.

**Possible Causes**

Service startup or IPC connection has failed.

**Procedure**

Operation error. Try again later.



## 3120002 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if an internal system error occurs.

**Possible Causes**

The possible cause is that data read/write has failed because the network is abnormal.

**Procedure**

Operation error. Try again later.
