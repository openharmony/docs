# DataShare Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 15700010 Failed to Create a DataShareHelper

**Error Message**

The DataShareHelper is not initialized successfully.

**Description**

The **DataShareHelper** class fails to be created.

**Possible Causes**

1. The **uri** specified in **createDataHelper** is incorrect.
2. The **context** specified in **createDataHelper** is incorrect. **DataShare** supports only the stage model.

**Solution**

1. Obtain the correct URI.
2. Check that the context of the stage model is used.

## 15700011 Failed to Add or Delete a Template

**Error Message**

The uri is not exist.

**Description**

This error code is returned when a template fails to be added or deleted.

**Possible Causes**

1. The input parameter **uri** of **addTemplate()** is incorrect.
2. The input parameter **uri** of **delTemplate()** is incorrect.

**Solution**

Obtain the correct URI.

## 15700012 Data Area Not Exist

**Error Message**

The data area is not exist.

**Description**

This error code is returned when a data update fails.

**Possible Causes**

The input parameter **bundleName** of **publish()** is incorrect.

**Solution**

Obtain the correct **bundleName** value from the DataShare server provider.
