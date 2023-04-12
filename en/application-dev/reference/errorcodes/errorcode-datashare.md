# DataShare Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 15700010 Failed to Create a DataShareHelper

**Error Message**

The dataShareHelper is not initialized successfully.

**Description**

The **DataShareHelper** class fails to be created.

**Possible Causes**

1. The **uri** specified in **createDataHelper** is incorrect.
2. The **context** specified in **createDataHelper** is incorrect. **DataShare** supports only the stage model.

**Solution**

1. Obtain the correct URI.
2. Check that the context of the stage model is used.
