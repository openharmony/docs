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
3. The client application does not have the permission to start **DataShareExtension** from the background when the client attempts to start **DataShareExtension** from the background to create **DataShareHelper**.

**Solution**

1. Obtain the correct URI.

2. Check that the context of the stage model is used.

3. Check whether the client has the read or write permission on data. Perform the following steps:
    
    (1) Obtain the data provider bundle name in the path of the URI. For example, the bundle name in uri = "datashare:///com.acts.datasharetest" is **com.acts.datasharetest**.
    
    (2) Obtain the configuration based on the bundle name. For example, run **bm dump --bundle-name com.acts.datasharetest** to obtain the **DataShareExtension** configuration, and check whether the data consumer has **readPermission** or **writePermission**.

