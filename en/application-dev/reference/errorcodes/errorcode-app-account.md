#  App Account Error Codes

## 12400001 Application Not Exist

**Error Message**

The application does not exist.

**Possible Causes**

The possible causes are as follows:
1. The target application does not exist when the app permission is set.
2. The target application does not exist when the app permission is authorized.

**Solution**

Check that the target app has been installed and use the bundle of the app.

## 12400002 Custom Data Not Exist

**Error Message**

The custom data does not exist.

**Possible Causes**

The possible causes are as follows:
The key does not exist when you query the custom data of the account.

**Solution**

Query the custom data with a key that is already defined.

## 12400003 The Number of Custom Data Records Has Reached the Limit

**Error Message**

The number of custom data records has reached the limit.

**Possible Causes**

The possible causes are as follows:
The number of custom data records of the target account has reached 512.

**Solution**

Delete the custom data records that are no longer used.

## 12400004 The Number of Tokens Has Reached the Limit

**Error Message**

The number of tokens has reached the limit.

**Possible Causes**

The possible causes are as follows:
The number of tokens of the target account has reached 1024.

**Solution**

Delete the tokens that are not longer used, and try again.

## 12400005 The Number of Bundles in the OAuth List Has Reached the Limit

**Error Message**

The number of bundles in the OAuth list has reached the limit.

**Possible Causes**

The possible causes are as follows:
The number of bundles in the authorization list has reached 1024.

**Solution**

1. Revoke authorization from the apps that do not require the authorization, and try again.
