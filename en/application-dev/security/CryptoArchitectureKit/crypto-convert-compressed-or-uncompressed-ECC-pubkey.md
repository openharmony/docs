# Converting a Compressed or Uncompressed ECC Public Key (ArkTS)

You can generate a public key object (**PubKey**) from ECC public key data or obtain the ECC public key data from a public key (**PubKey**) object. 
Currently, only the compressed/uncompressed public key data that complies with the ECC X.509 standard is supported. <br>The public key data mentioned in this topic is a complete X509 public key. For details about the operations on point data, see [Converting Compressed or Uncompressed ECC Point Data](crypto-convert-compressed-or-uncompressed-ECC-point.md). 
<br>For details about the ECC algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc). 
<br>You can specify the string parameter **format** to set the format of the ECC public key to obtain. To obtain a compressed public key that complies with the X.509 standard, set **format** to **X509|COMPRESSED**. To obtain an uncompressed public key, set **format** to **X509|UNCOMPRESSED**.

##  Converting Uncompressed Public Key Data to Compressed Public Key Data

1. Encapsulate uncompressed ECC public key data of the Uint8Array type into a **DataBlob** object.
Either the public key or private key can be passed in. In this example, an uncompressed public key is passed in.
2. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'ECC_BrainPoolP256r1'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 256-bit ECC key pair.
3. Call [AsyKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3) to convert the **DataBlob** object into an asymmetric key (**KeyPair**) object.
4. Call [PubKey.getEncodedDer](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedder12) with **format** set to **'X509|COMPRESSED'** to obtain the byte stream of the compressed public key.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function eccPubUncompressedToCompressed() {
  let pkData = new Uint8Array([48, 90, 48, 20, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 9, 43, 36, 3, 3, 2, 8, 1, 1, 7, 3, 66, 0, 4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let generator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await generator.convertKey(pubKeyBlob, null);
  let returnBlob = keyPair.pubKey.getEncodedDer('X509|COMPRESSED');
  console.info('returnBlob data:' + returnBlob.data);
}
```
