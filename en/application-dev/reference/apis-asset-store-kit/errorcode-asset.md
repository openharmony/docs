# Asset Store Service Error Code

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 24000001 Asset Store Service Unavailable

**Error Message**

The ASSET service is unavailable.

**Possible Cause**

The asset store service (ASSET) is unavailable due to a system exception.

**Solution**

Re-initiate a request for processing the asset.

## 24000002 Asset Not Found

**Error Message**

The asset is not found.

**Possible Cause**

1. The asset does not exist.
2. The asset has been removed.

**Solution**

1. Check whether the asset exists or is removed based on the asset alias.
2. Add the asset.

## 24000003 Asset Already Exists

**Error Message**

The asset already exists.

**Possible Cause**

An asset with the same alias (**asset.Tag.ALIAS**) already exists.

**Solution**

Check whether the alias of the asset to add is correct. If the alias is incorrect, use the correct alias. If the alias is correct, perform either of the following operations:

1. Use [asset.remove](js-apis-asset.md#assetremove) to remove the asset with the same alias, and use [asset.add](js-apis-asset.md#assetadd) to add the asset.
2. Call [asset.add](js-apis-asset.md#assetadd) with **asset.Tag.CONFLICT_RESOLUTION** set to **asset.ConflictResolution.OVERWRITE**.

## 24000004 Access to Asset Denied

**Error Message**

Access denied.

**Possible Cause**

1. The user authentication required before the access to the asset fails.

2. The challenge value does not match the authorization token.

**Solution**

1. Perform user authentication.

2. Pass in the challenge value and authorization token that are matched with each other.

## 24000005 Incorrect Screen Lock Status

**Error Message**

The screen lock status does not match.

**Possible Cause**

1. The lock screen password required for accessing the asset is not set.
2. The device has not been unlocked for the asset that is accessible only after the device is unlocked for the first.
3. The device is not unlocked for the asset that is accessible only after the device is unlocked.

**Solution**

Set a lock screen password or unlock the screen before accessing the asset.

## 24000006 Insufficient Memory

**Error Message**

Insufficient memory.

**Possible Cause**

The system memory is insufficient.

**Solution**

Close unnecessary applications to release memory and initiate a processing request again.

## 24000007 Asset Corrupted

**Error Message**

The asset is corrupted.

**Possible Cause**

The asset file is corrupted due to device power-off or storage system exceptions.

**Solution**

Restore factory settings.

## 24000008 Database Operation Failed

**Error Message**

The database operation failed.

**Possible Cause**

1. The asset store, from which data is being queried, has not been created yet.
2. The access to the database fails.

**Solution**

1. Use **add()** to create an asset store first.
2. Locate the cause of the database access failure based on error information.

## 24000009 Cryptographic Operation Failed 

**Error Message**

The cryptography operation failed.

**Possible Cause**

The cryptographic operation fails.

**Solution**

Locate the cause of the operation failure based on error information.

## 24000010 IPC Failed

**Error Message**

IPC failed.

**Possible Cause**

The IPC failed.

**Solution**

Locate the cause of the IPC failure based on error information.

## 24000011 Bundle Manager Service Abnormal

**Error Message**

Calling the Bundle Manager service failed.

**Possible Cause**

The Bundle Manager service is abnormal.

**Solution**

Locate the cause of the exception based on error information.

## 24000012 Account Service Abnormal

**Error Message**

Calling the OS Account service failed.

**Possible Cause**

The account service is abnormal.

**Solution**

Locate the cause of the exception based on error information.

## 24000013 Access Token Service Abnormal

**Error Message**

Calling the Access Token service failed.

**Possible Cause**

The Access Token service is abnormal.

**Solution**

Locate the cause of the exception based on error information.

## 24000014 File Operation Failed

**Error Message**

The file operation failed.

**Possible Cause**

1. The folder in the **data/service/el1/public/asset_service** directory is manually deleted from the device.
2. The file system is corrupted.

**Solution**

Restart the device. If the problem persists, restore factory settings of the device.

## 24000015 Failed to Obtain the System Time

**Error Message**

Getting the system time failed.

**Possible Cause**

The system time is tampered with.

**Solution**

Correct the system time.

## 24000016 Cached Assets Reaches the Limit

**Error Message**

The cache exceeds the limit.

**Possible Cause**

[asset.postQuery](js-apis-asset.md#assetpostquery) is not called to release resources after [asset.preQuery](js-apis-asset.md#assetprequery) is called.

**Solution**

Call [asset.postQuery](js-apis-asset.md#assetpostquery) to release resources after [asset.preQuery](js-apis-asset.md#assetprequery) is called.

## 24000017 Function Not Supported

**Error Message**

The capability is not supported.

**Possible Cause**

The API is supported, but certain sub-features of the API, for example, querying plaintext of assets in batches, are not supported.

**Solution**

Adjust API parameters and use alternative APIs, for example, invoking the alternative API multiple times to query assets.

## 24000018 Parameter Check Failed

**Error Message**

Parameter verify failed.

**Possible Cause**

The input argument is invalid.

**Solution**

Adjust the API arguments based on the error information and call the API again.
