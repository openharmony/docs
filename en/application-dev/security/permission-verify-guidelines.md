# Permission Verification Guide

## When to Use

To protect sensitive data and eliminate security threads on core abilities, you can use the permissions in the [App Permission List](permission-list.md) to protect the related API from unauthorized calling. Each time before the API is called, a permission verification is performed to check whether the caller has the required permission.

## Available APIs

The table below lists only the API used in this guide. For more information, see [AbilityContext](../reference/apis/js-apis-ability-context.md).

| API                                                      | Description                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt; | Checks whether an application process has the specified permission.|


## Example

The procedure is as follows:

1. Obtain the caller's identity (**tokenId**).
2. Determine the permission to verify, which is **ohos.permission.PERMISSION** in this example.
3. Call **verifyAccessToken()** to perform a permission verification of the caller.
4. Proceed based on the permission verification result.

```js
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
  import rpc from '@ohos.rpc'

  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
          console.log("RpcServer: getCallingTokenId result: " + callerTokenId);
          var atManager = abilityAccessCtrl.createAtManager();
          var result = await atManager.verifyAccessToken(tokenID, "ohos.permission.PERMISSION");
          if (result == abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
            // Allow the caller to invoke the API provided by the app.
          } else {
            // Deny the caller's access to the API.
          }
          return true;
      }
  }

```
> **NOTE**<br>
> You can use **getCallingTokenId** to obtain the caller's **tokenId**. For details, see [RPC](../reference/apis/js-apis-rpc.md#getcallingtokenid8).
