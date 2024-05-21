# Key Derivation


A key derivation function (KDF) is a cryptographic algorithm that derives one or more secrete keys from a secret value (such as a master key) by using a pseudorandom function. It can be used to stretch keys into longer keys or to obtain keys in the required format.


For example, you can use a KDF to convert the passwords entered by users to the specified length.


## Supported Algorithms and Specifications

Currently, only the PBKDF Function 2 (PBKDF2) algorithm is supported.

Password-Based Key Derivation Function (PBKDF) is a key derivation function with a sliding computational cost. PBKDF2 is part of the PKCS series.

PBKDF2 applies a pseudorandom function (PRF), such as [HMAC](crypto-compute-mac.md), to an input password together with a salt value, and repeats the process multiple times to generate a derived key.

When creating a **kDF** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the KDF algorithm and HMAC algorithm with a vertical bar (|) in between.
| KDF Algorithm| HMAC Algorithm| String Parameter| API Version| 
| -------- | -------- | -------- | -------- |
| PBKDF2 | SHA1 | PBKDF2\|SHA1 | 11+ | 
| PBKDF2 | SHA224 | PBKDF2\|SHA224 | 11+ | 
| PBKDF2 | SHA256 | PBKDF2\|SHA256 | 11+ | 
| PBKDF2 | SHA384 | PBKDF2\|SHA384 | 11+ | 
| PBKDF2 | SHA512 | PBKDF2\|SHA512 | 11+ | 
| PBKDF2 | SM3 | PBKDF2\|SM3 | 11+ | 


## How to Develop

1. Create a [PBKDF2Spec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pbkdf2spec11) object and use it as a parameter for key derivation.
   
   **PBKDF2Spec** is a child class of **KdfSpec**. You need to specify the following:

   - **algName**: algorithm to used, which is **'PBKDF2'**.
   - **password**: original password used to generate the derived key.
      If the password is of the string type, pass in the data used for key derivation instead of the string type such as HexString or base64. In addition, ensure that the string is encoded in UTF-8 format. Otherwise, the derived key may be different from what you expected.
   - **salt**: salt value.
   - **iterations**: number of iterations. The value must be a positive integer.
   - **keySize**: length of the derived key, in bytes. The value must be a positive integer.

2. Use [cryptoFramework.createKdf](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatekdf11) with the string parameter **'PBKDF2|SHA256'** to create a **Kdf** object.

3. Use [Kdf.generateSecret](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatesecret-2) with the **PBKDF2Spec** object to generate a derived key.
   
   The following table lists how **Kdf.generateSecret** delivers the return value.
   
   | API| Return Mode| 
   | -------- | -------- |
   | generateSecret(params: KdfSpec, callback: AsyncCallback&lt;DataBlob&gt;): void | This API uses an asynchronous callback to return the result.| 
   | generateSecret(params: KdfSpec): Promise&lt;DataBlob&gt; | This API uses a promise to return the result.| 

- Return the result using **await**:
  ```ts
  import cryptoFramework from '@ohos.security.cryptoFramework';
  
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
  import cryptoFramework from '@ohos.security.cryptoFramework';
  import { BusinessError } from '@ohos.base';
  
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
