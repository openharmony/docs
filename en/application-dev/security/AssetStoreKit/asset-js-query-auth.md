# Querying an Asset with User Authentication (ArkTS)

## Available APIs

The following table describes the APIs used for querying an asset with user authentication. For more information, see the API reference.

| Asynchronous API| Synchronous API| Description|
| ----- | ------ | ------- |
| [preQuery(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetprequery) | [preQuerySync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetprequerysync12) | Performs preprocessing.|
| [query(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquery) | [querySync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquerysync12) | Queries the asset.|
| [postQuery(handle: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetpostquery) | [postQuerySync(handle: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetpostquerysync12) | Performs postprocessing.|

The following table describes the attributes of **AssetMap** used for querying an asset with user authentication.

>**NOTE**
>
>In the following table, the attributes starting with **DATA_LABEL** are custom asset attributes reserved for services. These attributes are not encrypted. Therefore, do not put personal data in these attributes.

- **preQuery()** parameters

  | Attribute Name (Tag)       | Value          | Mandatory | Description                 |
  | --------------------- | ---------------------------| -------- | -------------------------- |
  | ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | No    | Asset alias, which uniquely identifies an asset.         |
  | ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.                                    |
  | REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.    |
  | AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.                 |
  | AUTH_VALIDITY_PERIOD  | Type: number<br>Value range: 1-600 seconds       | No    | Validity period of the user authentication.            |
  | SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Type of sync supported by the asset.                          |
  | IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.                |
  | DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-2048 bytes                      | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-2048 bytes                     | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_3 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_4 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: bool| No| Whether to query the customized asset attribute information that is encrypted. By default, the unencrypted, customized asset attribute information is queried.|
  | GROUP_ID<sup>18+</sup> | Type: Uint8Array<br>Length: 7-127 bytes| No| Group to which the asset to be queried belongs. By default, this parameter is not specified.|

- **query()** parameters

  | Attribute Name (Tag)       | Value                                            | Mandatory | Description                                            |
  | --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
  | ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | Yes    | Asset alias, which uniquely identifies an asset.      |
  | AUTH_CHALLENGE        | Type: Uint8Array<br>Length: 32 bytes                              | Yes    | Challenge for the user authentication.                             |
  | AUTH_TOKEN            | Type: Uint8Array<br>Length: 148 bytes                             | Yes    | Authorization token obtained after the user authentication is successful.                        |
  | RETURN_TYPE           | Type: number                          | Yes    | Type of the asset query result to return.                   |
  | ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.                                    |
  | REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.    |
  | AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.                 |
  | SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Type of sync supported by the asset.                          |
  | IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.                |
  | DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_3 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_4 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: bool| No| Whether to query the customized asset attribute information that is encrypted. By default, the unencrypted, customized asset attribute information is queried.|
  | GROUP_ID<sup>18+</sup> | Type: Uint8Array<br>Length: 7-127 bytes| No| Group to which the asset to be queried belongs. By default, this parameter is not specified.|

- **postQuery()** parameters

  | Attribute Name (Tag)     | Value              | Mandatory | Description                |
  | ------------------- | ------------------------------ | -------- | -------------------- |
  | AUTH_CHALLENGE      | Type: Uint8Array<br>Length: 32 bytes| Yes    | Challenge for the user authentication.|
  | GROUP_ID<sup>18+</sup> | Type: Uint8Array<br>Length: 7-127 bytes| No| Group to which the asset to be cleared belongs. By default, the assets that do not belong to any group in the memory are cleared.|

## Example

> **NOTE**
>
> The **asset** module provides asynchronous and synchronous APIs. The following uses the asynchronous APIs as an example. For more information about the APIs, see [Asset Store Service](../../reference/apis-asset-store-kit/js-apis-asset.md).

Query asset **demo_alias** with user authentication.

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import userAuth from '@ohos.userIAM.userAuth';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

function arrayToString(arr: Uint8Array): string {
  let textDecoder = util.TextDecoder.create("utf-8", { ignoreBOM: true });
  let str = textDecoder.decodeToString(arr, { stream: false })
  return str;
}

async function userAuthenticate(challenge: Uint8Array): Promise<Uint8Array> {
  return new Promise((resolve, reject) => {
    const authParam: userAuth.AuthParam = {
      challenge: challenge,
      authType: [userAuth.UserAuthType.PIN],
      authTrustLevel: userAuth.AuthTrustLevel.ATL1,
    };
    const widgetParam: userAuth.WidgetParam = { title:' Enter the lock screen password. '};
    try {
      let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
      userAuthInstance.on('result', {
        onResult(result) {
          if (result.result == userAuth.UserAuthResultCode.SUCCESS) {
            console.info(`User identity authentication succeeded.`);
            resolve(result.token);
          } else {
            console.error(`User identity authentication failed.`);
            reject();
          }
        }
      });
      userAuthInstance.start();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`User identity authentication failed. Code is ${err.code}, message is ${err.message}`);
      reject();
    }
  })
}

function preQueryAsset(): Promise<Uint8Array> {
  return new Promise((resolve, reject) => {
    try {
      let query: asset.AssetMap = new Map();
      query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
      asset.preQuery(query).then((challenge: Uint8Array) => {
        resolve(challenge);
      }).catch(() => {
        reject();
      })
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to pre-query Asset. Code is ${err.code}, message is ${err.message}`);
      reject();
    }
  });
}

async function postQueryAsset(challenge: Uint8Array) {
  let handle: asset.AssetMap = new Map();
  handle.set(asset.Tag.AUTH_CHALLENGE, challenge);
  try {
    await asset.postQuery(handle);
    console.info(`Succeeded in post-querying Asset.`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to post-query Asset. Code is ${err.code}, message is ${err.message}`);
  }
}

async function queryAsset() {
  // step1. Call asset.preQuery to obtain the challenge value.
  preQueryAsset().then(async (challenge: Uint8Array) => {
    try {
      // Step 2. Pass in the challenge value to start the user authentication dialog box.
      let authToken: Uint8Array = await userAuthenticate(challenge);
      // Step 3 After the user authentication is successful, pass in the challenge value and authorization token to query the plaintext of the asset.
      let query: asset.AssetMap = new Map();
      query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
      query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL);
      query.set(asset.Tag.AUTH_CHALLENGE, challenge);
      query.set(asset.Tag.AUTH_TOKEN, authToken);
      let res: Array<asset.AssetMap> = await asset.query(query);
      for (let i = 0; i < res.length; i++) {
        // parse the secret.
        let secret: Uint8Array = res[i].get(asset.Tag.SECRET) as Uint8Array;
        // parse uint8array to string
        let secretStr: string = arrayToString(secret);
      }
      // Step 4. After the plaintext is obtained, call asset.postQuery to perform postprocessing.
      postQueryAsset(challenge);
    } catch (error) {
      // Step 5. If the operation after preQuery() fails, call asset.postQuery to perform postprocessing.
      postQueryAsset(challenge);
    }
  }).catch ((err: BusinessError) => {
    console.error(`Failed to pre-query Asset. Code is ${err.code}, message is ${err.message}`);
  })
}
```
