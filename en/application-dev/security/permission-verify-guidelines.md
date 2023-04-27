# Verifying API Access Permissions

## When to Use

To protect sensitive data and eliminate security threats on core abilities, you can use the permissions in the [Application Permission List](permission-list.md) to protect the related API from unauthorized calling. Each time before the API is called, a permission verification is performed to check whether the caller has the required permission.

## Available APIs

The following table lists only the API used in this guide. For more information, see [Application Access Control](../reference/apis/js-apis-abilityAccessCtrl.md).

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Token ID of the application. You can obtain the value from the [ApplicationInfo](../reference/apis/js-apis-bundleManager-applicationInfo.md) of the application.            |
| permissionName | Permissions | Yes  | Name of the permission to verify. Valid permission names are defined in the [Application Permission List](permission-list.md).|


## Example

The procedure is as follows:

1. Obtain the caller's identity (**tokenId**).
   > **NOTE**<br>
   > You can use **getCallingTokenId** to obtain the caller's **tokenId**. For details, see [RPC](../reference/apis/js-apis-rpc.md).
2. Determine the permission to verify, which is **ohos.permission.PERMISSION** in this example.
3. Call **checkAccessToken()** to perform a permission verification of the caller.
4. Proceed based on the permission verification result.

```js
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
  import rpc from '@ohos.rpc'

  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
          console.log("RpcServer: getCallingTokenId result: " + callerTokenId);
          var atManager = abilityAccessCtrl.createAtManager();
          try {
              atManager.checkAccessToken(callerTokenId, "ohos.permission.ACCELEROMETER").then((data) => {
                  console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);
              }).catch((err) => {
                  console.log(`checkAccessToken fail, err->${JSON.stringify(err)}`);
              });
          } catch(err) {
              console.log(`catch err->${JSON.stringify(err)}`);
          }
          return true;
      }
  }

```
