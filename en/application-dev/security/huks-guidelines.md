# HUKS Development

## When to Use

 Openharmony Universal KeyStore (HUKS) provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations. HUKS also provides APIs for applications to import or generate keys.


## Available APIs

| API                                                      | Description            |
| ------------------------------------------------------------ | ---------------- |
| function generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void; | Generates a private key. This method uses an asynchronous callback to return the result.        |
| function generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Generates a private key. This method uses a promise to return the result.        |
| function exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void; | Exports the public key. This method uses an asynchronous callback to return the result.        |
| function exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Exports the public key. This method uses a promise to return the result.        |
| function isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void; | Check whether a key exists. This method uses an asynchronous callback to return the result.|
| function isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>; | Check whether a key exists. This method uses a promise to return the result.|
| function deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void; | Deletes a key. This method uses an asynchronous callback to return the result.        |
| function deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Deletes a key. This method uses a promise to return the result.        |

## How to Develop

1. Import the HUKS module.

   ```js
   import huks from '@ohos.security.huks'
   ```

2. Call **generateKey()** to generate a private key.

   **keyAlias** indicates the alias of the key generated. **options** indicates the parameters used for generating the key. Set **options** based on the actual situation.

   The value returned indicates whether the key is successfully generated.

   ```js
   var alias = 'testAlias';
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_ECC
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_224
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[3] = {
     tag: huks.HuksTag.HUKS_TAG_DIGEST,
     value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
   };
   var options = {
     properties: properties
   }
   var resultA = huks.generateKey(alias, options);
   ```

3. Call **Init()** to initialize the key.

   **Alias** indicates the alias of the key to initialize, and **options** indicates the parameters used for initializing the key.

   The value returned indicates whether the **Init** operation is successful.

   ```js
   var alias = 'test001'
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   huks.init(alias, options, function(err, data) {
       if (err.code !== 0) {
           console.log("test init err information: " + JSON.stringify(err));
       } else {
           console.log(`test init data: ${JSON.stringify(data)}`);
       }
   })
   ```
   
4. Call **update()** to update the key.

   **handle** indicates the session ID for updating the key. **options** indicates the parameters used for updating the key.

   The value returned indicates whether the **Update** operation is successful.

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.update(handle, options)
   ```
   
5. Call **finish()** to complete the operation.

   **handle** indicates the session ID of the **Finish** operation. **options** indicates the parameters used for this operation.

   The value returned indicates whether the **Finish** operation is successful.

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.finish(handle, options) 
   ```
