# Converting Binary Data into an Asymmetric Key Pair (ArkTS)


This topic uses RSA, ECC, and SM2 as an example to describe how to convert binary data into an asymmetric key pair (**KeyPair**). That is, convert a piece of external or internal binary data into a **KeyPair** object for subsequent operations, such as encryption and decryption.


> **NOTE**
>
> The asymmetric key conversion must comply with the following requirements: 
>
> - The public key must use the ASN.1 syntax and DER encoding format and comply with X.509 specifications.
>
> - The private key must use the ASN.1 syntax and DER encoding format and comply with PKCS\#8 specifications.


## Converting Binary Data into an RSA Key Pair

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Obtain the binary data of the RSA public key or private key and encapsulate the data into a **DataBlob** object.

   Either the public key or private key can be passed in. In this example, the public key is passed in.

2. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'RSA1024'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 1024-bit RSA key with two primes.

   The default number of primes for creating an RSA asymmetric key is **2**. The **PRIMES_2** parameter is omitted in the string parameter here.

3. Use [AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3) to convert the binary data into an asymmetric key pair (**KeyPair**).

- Example: Convert binary data into an RSA key pair (using callback-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function convertAsyKey() {
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
    let pkVal = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 174, 203, 113, 83, 113, 3, 143, 213, 194, 79, 91, 9, 51, 142, 87, 45, 97, 65, 136, 24, 166, 35, 5, 179, 42, 47, 212, 79, 111, 74, 134, 120, 73, 67, 21, 19, 235, 80, 46, 152, 209, 133, 232, 87, 192, 140, 18, 206, 27, 106, 106, 169, 106, 46, 135, 111, 118, 32, 129, 27, 89, 255, 183, 116, 247, 38, 12, 7, 238, 77, 151, 167, 6, 102, 153, 126, 66, 28, 253, 253, 216, 64, 20, 138, 117, 72, 15, 216, 178, 37, 208, 179, 63, 204, 39, 94, 244, 170, 48, 190, 21, 11, 73, 169, 156, 104, 193, 3, 17, 100, 28, 60, 50, 92, 235, 218, 57, 73, 119, 19, 101, 164, 192, 161, 197, 106, 105, 73, 2, 3, 1, 0, 1]);
    let pkBlob: cryptoFramework.DataBlob = { data: pkVal };
    rsaGenerator.convertKey(pkBlob, null, (err, keyPair) => {
      if (err) {
        console.error(`convertKey failed, ${err.code}, ${err.message}`);
        return;
      }
      console.info('convertKey success');
    });
  }
  ```

- Example: Convert binary data into an RSA key pair (using the synchronous API [convertKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkeysync12)).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function convertAsyKeySync() {
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
    let pkVal = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 174, 203, 113, 83, 113, 3, 143, 213, 194, 79, 91, 9, 51, 142, 87, 45, 97, 65, 136, 24, 166, 35, 5, 179, 42, 47, 212, 79, 111, 74, 134, 120, 73, 67, 21, 19, 235, 80, 46, 152, 209, 133, 232, 87, 192, 140, 18, 206, 27, 106, 106, 169, 106, 46, 135, 111, 118, 32, 129, 27, 89, 255, 183, 116, 247, 38, 12, 7, 238, 77, 151, 167, 6, 102, 153, 126, 66, 28, 253, 253, 216, 64, 20, 138, 117, 72, 15, 216, 178, 37, 208, 179, 63, 204, 39, 94, 244, 170, 48, 190, 21, 11, 73, 169, 156, 104, 193, 3, 17, 100, 28, 60, 50, 92, 235, 218, 57, 73, 119, 19, 101, 164, 192, 161, 197, 106, 105, 73, 2, 3, 1, 0, 1]);
    let pkBlob: cryptoFramework.DataBlob = { data: pkVal };
    try {
      let keyPair = rsaGenerator.convertKeySync(pkBlob, null);
      if (keyPair != null) {
        console.info('convertKeySync success');
      }
    } catch (e) {
      console.error(`get key pair failed, ${e.code}, ${e.message}`);
    }
  }
  ```


## Converting Binary Data into an ECC Key Pair

For details about the algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).

1. Obtain the binary data of the ECC public key or private key and encapsulate the data into a **DataBlob** object.

   Either the public key or private key can be passed in. As shown in the following example, the public key and private key are passed in separately.

2. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'ECC256'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 256-bit ECC key pair.

3. Use [AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3) to convert the binary data into an asymmetric key pair (**KeyPair**).

- Example: Convert binary data into an ECC key pair (using callback-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function convertEccAsyKey() {
    let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
    let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator('ECC256');
    generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
      if (error) {
        console.error(`convertKey failed, ${error.code}, ${error.message}`);
        return;
      }
      console.info('convertKey success');
    });
  }
  ```

- Example: Convert binary data into an ECC key pair (using the synchronous API [convertKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkeysync12)).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function convertECCAsyKeySync() {
    let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
    let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator('ECC256');
    try {
      let keyPair = generator.convertKeySync(pubKeyBlob, priKeyBlob);
      if (keyPair != null) {
        console.info('convertKeySync success');
      }
    } catch (e) {
      console.error(`get key pair failed, ${e.code}, ${e.message}`);
    }
  }
  ```

## Converting PKCS#8 Binary Data into an ECC Private Key

For details about the algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).

Obtain the binary data of the ECC public or private key, encapsulate the data into a **DataBlob** object, and convert the data into the ECC key format.

1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'ECC256'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 256-bit ECC key pair.

2. Use [PubKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the byte stream of the public key data, and use [PriKey.getEncodeDer](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedder12-1) with **format** set to **'PKCS8'** to obtain the byte stream of the private key data. The binary data of the key object is obtained.

3. Use [AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3) to convert the binary data into an asymmetric key pair.
**Example**

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  async function main() {
    // Create an AsyKeyGenerator instance.
    let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
    // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
    let keyGenPromise = eccGenerator.generateKeyPair();
    keyGenPromise.then(keyPair => {
      let pubKey = keyPair.pubKey;
      let priKey = keyPair.priKey;
      // Obtain the binary data of the ECC asymmetric key pair.
      let pubBlob = pubKey.getEncoded();
      let skBlob = priKey.getEncodedDer('PKCS8');
      let generator = cryptoFramework.createAsyKeyGenerator('ECC256');
      generator.convertKey(pubBlob, skBlob, (error, data) => {
        if (error) {
          console.error(`convertKey failed, ${error.code}, ${error.message}`);
          return;
        }
        console.info('convertKey success');
      });
    });
  }
  ```

## Converting Binary Data into an SM2 Key Pair

For details about the algorithm specifications, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2).

1. Obtain the binary data of the SM2 public key or private key and encapsulate the data into a **DataBlob** object.

   Either the public key or private key can be passed in. As shown in the following example, the public key and private key are passed in separately.

2. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'SM2_256'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 256-bit SM2 key pair.

3. Use [AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3) to convert the binary data into an asymmetric key pair (**KeyPair**).

- Example: Convert binary data into an SM2 key pair (using callback-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function convertSM2AsyKey() {
    let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45, 3, 66, 0, 4, 90, 3, 58, 157, 190, 248, 76, 7, 132, 200, 151, 208, 112, 230, 96, 140, 90, 238, 211, 155, 128, 109, 248, 40, 83, 214, 78, 42, 104, 106, 55, 148, 249, 35, 61, 32, 221, 135, 143, 100, 45, 97, 194, 176, 52, 73, 136, 174, 40, 70, 70, 34, 103, 103, 161, 99, 27, 187, 13, 187, 109, 244, 13, 7]);
    let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 54, 41, 239, 240, 63, 188, 134, 113, 31, 102, 149, 203, 245, 89, 15, 15, 47, 202, 170, 60, 38, 154, 28, 169, 189, 100, 251, 76, 112, 223, 156, 159, 160, 10, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45]);
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
    generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
      if (error) {
        console.error(`convertKey failed, ${error.code}, ${error.message}`);
        return;
      }
      console.info('convertKey success');
    });
  }
  ```

- Example: Convert binary data into an SM2 key pair (using the synchronous API [convertKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkeysync12)).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function convertSM2AsyKeySync() {
    let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45, 3, 66, 0, 4, 90, 3, 58, 157, 190, 248, 76, 7, 132, 200, 151, 208, 112, 230, 96, 140, 90, 238, 211, 155, 128, 109, 248, 40, 83, 214, 78, 42, 104, 106, 55, 148, 249, 35, 61, 32, 221, 135, 143, 100, 45, 97, 194, 176, 52, 73, 136, 174, 40, 70, 70, 34, 103, 103, 161, 99, 27, 187, 13, 187, 109, 244, 13, 7]);
    let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 54, 41, 239, 240, 63, 188, 134, 113, 31, 102, 149, 203, 245, 89, 15, 15, 47, 202, 170, 60, 38, 154, 28, 169, 189, 100, 251, 76, 112, 223, 156, 159, 160, 10, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45]);
    let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray };
    let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
    try {
      let keyPair = generator.convertKeySync(pubKeyBlob, priKeyBlob);
      if (keyPair != null) {
        console.info('convertKeySync success');
      }
    } catch (e) {
      console.error(`get key pair failed, ${e.code}, ${e.message}`);
    }
  }
  ```
