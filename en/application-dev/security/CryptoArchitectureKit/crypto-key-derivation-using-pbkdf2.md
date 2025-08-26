# Key Derivation Using PBKDF2 (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the corresponding algorithm specifications, see [PBKDF2](crypto-key-derivation-overview.md#pbkdf2).

## How to Develop

1. Create a [PBKDF2Spec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pbkdf2spec11) object and use it as a parameter for key derivation.

   **PBKDF2Spec** is a child class of [KdfSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#kdfspec11). You need to specify the following:

   - **algName**: algorithm to use, which is **'PBKDF2'**.
   - **password**: original password used to generate the derived key.
      If **key** is of the string type, pass in the data used for key derivation instead of the string type such as HexString or base64. In addition, ensure that the string is encoded in UTF-8 format. Otherwise, the derived key may be different from what you expected.
   - **salt**: specifies the salt value.
   - **iterations**: number of iterations. The value must be a positive integer.
   - **keySize**: length of the key to derive, in bytes. The value must be a positive integer.

2. Call [cryptoFramework.createKdf](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekdf11) with the string parameter **'PBKDF2|SHA256'** to create a **Kdf** object. The key derivation algorithm is **PBKDF2**, and HMAC algorithm is **SHA256**.

3. Call [Kdf.generateSecret](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesecret11) with the **PBKDF2Spec** object to generate a derived key.

   The following table lists how **Kdf.generateSecret** delivers the return value.

   | API| Return Mode|
   | -------- | -------- |
   | generateSecret(params: KdfSpec, callback: AsyncCallback&lt;DataBlob&gt;): void | This API uses an asynchronous callback to return the result.|
   | generateSecret(params: KdfSpec): Promise&lt;DataBlob&gt; | This API uses a promise to return the result.|
   | generateSecretSync(params: KdfSpec): DataBlob | This API returns the result synchronously.|

- Return the result using **await**:

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  async function kdfAwait() {
    let spec: cryptoFramework.PBKDF2Spec = {
      algName: 'PBKDF2',
      password: '123456',
      salt: new Uint8Array(16),
      iterations: 10000,
      keySize: 32
    };
    let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
    let secret = await kdf.generateSecret(spec);
    console.info("key derivation output is " + secret.data);
  }
  ```

- Return the result using a promise:

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function kdfPromise() {
    let spec: cryptoFramework.PBKDF2Spec = {
      algName: 'PBKDF2',
      password: '123456',
      salt: new Uint8Array(16),
      iterations: 10000,
      keySize: 32
    };
    let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
    let kdfPromise = kdf.generateSecret(spec);
    kdfPromise.then((secret) => {
      console.info("key derivation output is " + secret.data);
    }).catch((error: BusinessError) => {
      console.error("key derivation error.");
    });
  }
  ```

- Return the result synchronously:

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function kdfSync() {
    let spec: cryptoFramework.PBKDF2Spec = {
      algName: 'PBKDF2',
      password: '123456',
      salt: new Uint8Array(16),
      iterations: 10000,
      keySize: 32
    };
    let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
    let secret = kdf.generateSecretSync(spec);
    console.info("[Sync]key derivation output is " + secret.data);
  }
  ```
