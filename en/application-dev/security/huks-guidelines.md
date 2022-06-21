# HUKS Development

## When to Use

 OpenHarmony Universal KeyStore (HUKS) provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations. HUKS also provides APIs for applications to import or generate keys.


## Available APIs

| API                                                      | Description       |
| ------------------------------------------------------------ | ---------------- |
| generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;HuksResult&gt;) : void| Generates a key. This method uses an asynchronous callback to return the result.        |
| generateKey(keyAlias: string, options: HuksOptions) : Promise&lt;HuksResult&gt;| Generates a key. This method uses a promise to return the result.        |
| exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;HuksResult&gt;) : void| Exports the public key. This method uses an asynchronous callback to return the result.        |
| exportKey(keyAlias: string, options: HuksOptions) : Promise&lt;HuksResult&gt;| Exports the public key. This method uses a promise to return the result.        |
| isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;boolean&gt;) : void | Checks whether a key exists. This method uses an asynchronous callback to return the result.|
| isKeyExist(keyAlias: string, options: HuksOptions) : Promise&lt;boolean> | Checks whether a key exists. This method uses a promise to return the result.|
| deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;HuksResult&gt;) : void| Deletes a key. This method uses an asynchronous callback to return the result.        |
| deleteKey(keyAlias: string, options: HuksOptions) : Promise&lt;HuksResult&gt;| Deletes a key. This method uses a promise to return the result.        |

## How to Develop

1. Import the HUKS module.

   ```js
   import huks from '@ohos.security.huks'
   ```

2. Call **generateKey()** to generate a key.

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

   **Alias** indicates the alias of the key to initialize, and **options** indicates the parameters used for initializing the key. Set **options** based on the actual situation.

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

   **handle** indicates the session ID for updating the key. **options** indicates the parameters used for updating the key. Set **options** based on the actual situation.

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

   **handle** indicates the session ID of the **Finish** operation. **options** indicates the parameters used for this operation. Set **options** based on the actual situation.

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
