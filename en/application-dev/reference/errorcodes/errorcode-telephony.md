# Telephony Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 8300001 Input Parameter Value Out of Range

**Error Message**

The input parameter value is out of range.

**Description**

This error code is reported if the value of the input parameter (for example, **slotId**) is not within the valid range. In this case, the API call will fail and the corresponding operation cannot be performed.

**Cause**

The input parameter value is invalid.

**Solution**

Enter a valid parameter value.



## 8300002 Service Connection Error

**Error Message**

Operation failed. Cannot connect to service.

**Description**

This error code is reported if the attempt to connect to a service fails.

**Cause**

Service startup or IPC connection has failed.

**Solution**

Operation error. Try again later.



## 8300003 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if an internal error has occurred.

**Cause**

The possible cause is that data read/write has failed because the network is abnormal.

**Solution**

Operation error. Try again later.


## 8300004 SIM Card Not Detected

**Error Message**

Do not have sim card.

**Description**

This error code is reported if no SIM card is detected.

**Cause**

No SIM card is inserted or the SIM card is not properly inserted.

**Solution**

Insert the SIM card or remove and insert the SIM card again.


## 8300999 Unknown Error

**Error Message**

Unknown error code.

**Description**

This error code is reported if an unknown error occurs.

**Cause**

An unexpected error occurs in the system. The possible cause is that error codes of the bottom layer are not within the processing range.

**Solution**

Operation error. Try again later.


## 8301001 SIM Card Not Activated

**Error Message**

SIM card is not activated.

**Description**

This error code is reported if the SIM card is not activated.

**Cause**

The SIM card is not activated.

**Solution**

Activate the SIM card.


## 8301002 Failed to Read or Update SIM Card Data

**Error Message**

SIM card operation error.

**Description**

This error code is reported if the attempt to read or update SIM card data has failed.

**Cause**

The SIM card does not support the operation, or the SIM card is damaged.

**Solution**

Contact the SIM card supplier, or replace the SIM card.


## 8301003 Incorrect SIM Card Configuration

**Error Message**

Operator config error.

**Description**

This error code is reported if the SIM card configuration is incorrect.

**Cause**

The configuration file delivered with the SIM card is not properly preconfigured.

**Solution**

Check whether the correct SIM card is inserted.

## 8401001 Failed to Connect to the UT

**Error Message**

UT is not connected.

**Description**

This error code is reported if the UT is not connected.

**Cause**

The current carrier does not support sending of UT requests over a Wi-Fi network, but the device is connected to the Wi-Fi network.

**Solution**

Disconnect the Wi-Fi connection, and send a new UT request.
