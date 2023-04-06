# Account Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

The following includes the error codes for OS accounts, distributed accounts, and app accounts.

## 12300001 System Service Abnormal

**Error Message**

System service works abnormally.

**Possible Causes**

The possible causes are as follows:
1. The account management service cannot start properly.
2. The IPC object for account management cannot be obtained.
3. The services on which the account management depends cannot start properly, or the IPC object on which the account management depends cannot be obtained.
4. The service is not initialized.
5. The disk space is insufficient.
6. The file read or write fails.
7. Directories cannot be created. 
8. Files cannot be created or deleted.
9. The database cannot be read or written.

**Solution**

Try again later or restart the device.

## 12300002 Invalid Parameter

**Error Message**

Invalid parameter. 

**Possible Causes**

The possible causes are as follows:
1. The user name is empty.
2. The user name of the OS account exceeds 1024 characters.
3. The user name of the distributed account exceeds 256 characters.
4. The OS account ID is less than 0 or 100, or greater than 1099.
5. The distributed account ID exceeds 512 characters.
6. The event type passed in for the distributed account is not supported.
7. The domain name is empty.
8. The domain name exceeds 128 characters.
9. The domain account is empty.
10. The domain account exceeds 512 characters.
11. The constraint is empty.
12. The constraint exceeds 128 characters.
13. Invalid authentication or query parameters are passed in.
14. The profile photo string of the OS account exceeds 4 KB.
15. The profile photo string of the distributed account exceeds 2 MB.
16. The images are not in .jpg or .png format.
17. The app account name exceeds 512 characters.
18. The authentication type exceeds 1024 characters.
19. The token exceeds 1024 characters.
20. The key exceeds 1024 characters.
21. The custom data exceeds 1024 characters.
22. The token is invalid.
23. The context ID is invalid.
24. The credential ID is invalid.

**Solution**

Set parameters correctly.

## 12300003 Account Not Exist

**Error Message**

The account does not exist.

**Possible Causes**

The possible causes are as follows:
1. The account to query, activate, or delete is not created.
2. The account to query, activate, or delete has been deleted.
3. The constraint, user name, or profile photo is set for an account that has been deleted.
4. The account to update is not created.
5. The access permission is to be set for an account that does not exist.
6. The password is to be set, deleted, or queried for an account that does not exist.
7. The token is to be set or deleted for an account that does not exist.
8. Additional information is to be set for an account that does not exist.
9. Credentials are to be set for an account that does not exist.
10. Custom data is to be set for an account that does not exist.
11. Distributed synchronization is to be enabled for an account that does not exist.

**Solution**

Check whether the account exists.

## 12300004 Account Already Exists

**Error Message**

The account already exists.

**Possible Causes**

The account to create already exists.

**Solution**

Rename the account.

## 12300005 Multiple Users Not Supported

**Error Message**

Multi-user is not supported.

**Possible Causes**

The device does not support multiple users.

**Solution**

Cancel the operation.

## 12300006 Account Type Not Supported

**Error Message**

The account type is not supported.

**Possible Causes**

The device does not support the account type.

**Solution**

Create an account of the type supported by the device.

## 12300007 The Number of Accounts Has Reached the Limit

**Error Message**

The number of accounts has reached the limit.  

**Possible Causes**

A maximum of 1,000 OS accounts or app accounts can be created.

**Solution**

Delete the accounts that are no longer used, and try again.

## 12300008 The Account Is Restricted

**Error Message**

The specified account is restricted.

**Possible Causes**

The possible causes are as follows:
1. The account to delete is a reserved account of the system.
2. The constraint source type to query belongs to a reserved account.
3. The ID of the account to create is 0 to 100.

**Solution**

Operations cannot be performed on the reserved account of the system.

## 12300009 Account Already Activated

**Error Message**

The account has been activated.

**Possible Causes**

The account to activate is already activated.

**Solution**

No further action is required.

## 12300010 Account Service Not Respond

**Error Message**

The account service does not respond.

**Possible Causes**

The possible causes are as follows:
1. Repeated requests, such as the requests for activating an account or applying the same settings, are submitted in a short period of time.
2. When the number of authentication sessions for app accounts reaches 256, new authentication requests cannot be processed.

**Solution**

Wait for a while and try again.

## 12300011 Event Listener Already Registered

**Error Message**

The event listener has been registered.

**Possible Causes**

The listener to register has been registered with the system already.

**Solution**

Cancel the operation or register an unregistered listener.

## 12300012 Event Listener Not Registered

**Error Message**

The event listener has not been registered.

**Possible Causes**

The event listener to unregister has not been registered.

**Solution**

Only registered event listeners can be unregistered.

## 12300101 Incorrect Credential

**Error Message**

The credential is incorrect.

**Possible Causes**

The possible causes are as follows:
1. An incorrect password is entered.
2. The biological feature does not match the feature enrolled.
2. The token is invalid.

**Solution**

Enter a correct credential and try again.

## 12300102 Credential Not Exist

**Error Message**

The credential does not exist.

**Possible Causes**

The possible causes are as follows:
1. The credential to authenticate has not been enrolled.
2. The credential to query has not been enrolled.
3. The credential to delete has not been enrolled.

**Solution**

Check whether the credential has been enrolled.

## 12300103 Credential Inputer Already Exists

**Error Message**

The crdential inputer already exists.

**Possible Causes**

The PIN inputer has been registered and cannot be registered again before deregistration.

**Solution**

No further action is required.

## 12300104 Credential Inputer Not Exist

**Error Message**

The credential inputer is not found.

**Possible Causes**

No credential inputer is registered when a credential is authenticated, added or modified.

**Solution**

Register a credential inputer.

## 12300105 Trust Level Not Supported

**Error Message**

The trust level is not supported.

**Possible Causes**

The trust level passed in is not supported.

**Solution**

Use a trust level supported by the system.

## 12300106 Authentication Type Not Supported

**Error Message**

The authentication type is not supported.

**Possible Causes**

The authentication type passed in is not supported.

**Solution**

Use an authentication type supported by the system.

## 12300107 Authentication Type Not Exist

**Error Message**

The authentication type does not exist.

**Possible Causes**

The specified authentication type does not exist when a token is queried or deleted.

**Solution**

Use an existing authentication type.

## 12300108 Authentication Session Not Exist

**Error Message**

The authentication session does not exist.

**Possible Causes**

The session callback to query does not exist.

**Solution**

Use an opened session to query session callbacks.

## 12300109 Authentication Canceled

**Error Message**

The authentication is canceled.

**Possible Causes**

The user cancels the authentication.

**Solution**

No further action is required.

## 12300110 Authentication Locked

**Error Message**

The authentication is locked.

**Possible Causes**

The number of authentication type errors exceeds the limit.

**Solution**

Try again after the freezing time.

## 12300111 Authentication Timed Out

**Error Message**

The authentication timed out.

**Possible Causes**

The possible causes are as follows:
1. The authentication or credential enrollment of an OS account takes more than three minutes.
2. The authentication service does not respond in time due to network problems.

**Solution**

1. Try again if the authentication or credential enrollment times out.
2. Check and rectify network problems, and try again.

## 12300112 Authentication Service Not Respond

**Error Message**

The authentication service does not respond.

**Possible Causes**

The possible causes are as follows:
The total number of OS accounts being authenticated exceeds 5.
The authentication service of the third-party app does not respond.

**Solution**

Try again later.

## 12300113 Authentication Service Not Exist

**Error Message**

The account authentication service does not exist.

**Possible Causes**

For app accounts:
1. When an authentication is requested, the app does not support the authentication service.
2. When an account is added implicitly, the app does not support the authentication service.
3. When the credential of a specified account is verified, the app does not support the authentication service.
4. When the authenticator attributes are set for an app, the app does not support the authentication service.
5. When the account tags are checked, the specified app does not support the authentication service.

**Solution**

Cancel the operation or authenticate an app that supports the authentication service.

## 12300114 Authentication Service Abnormal

**Error Message**

The account authentication service works abnormally.

**Possible Causes**

The possible causes are as follows:
1. An unknown error occurs in the identity authentication service.
2. The app authenticator does not comply with specifications.

**Solution**

1. Try again or restart the system.
2. Use the app authenticator that complies with specifications.

## 12400001 Application Not Exist

**Error Message**

The application does not exist.

**Possible Causes**

The possible causes are as follows:
1. The target app does not exist when the app permission is set.
2. The target app does not exist when the app permission is authorized.

**Solution**

Check that the target app has been installed and use the bundle of the app.

## 12400002 Custom Data Not Exist

**Error Message**

The custom data does not exist.

**Possible Causes**

The key does not exist when you query the custom data of the account.

**Solution**

Query the custom data with a key that is already defined.

## 12400003 Custom Data Records Reached the Limit

**Error Message**

The number of custom data reaches upper limit.

**Possible Causes**

The number of custom data records of the target account has reached 512.

**Solution**

Delete the custom data records that are no longer used.

## 12400004 Token Count Reached the Limit

**Error Message**

The number of token reaches upper limit.

**Possible Causes**

The number of tokens of the target account has reached 1024.

**Solution**

Delete the tokens that are not longer used, and try again.

## 12400005 Bundles in the OAuth List Reached the Limit

**Error Message**

The size of authorization list reaches upper limit.

**Possible Causes**

The number of bundles in the authorization list has reached 1024.

**Solution**

Revoke authorization from the apps that do not require the authorization and try again.

