# Converting Compressed or Uncompressed ECC Point Data (ArkTS)

You can convert compressed or uncompressed point data into a **Point** object for generating a key object, or convert a **Point** object into compressed or uncompressed point data. 
For details about the ECC algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc). 
You can pass in the string parameter **format** to specify the format of the point data to obtain. To obtain compressed point data, set **format** to **COMPRESSED**. To obtain uncompressed point data, set **format** to **UNCOMPRESSED**.

## Converting Uncompressed Point Data into Compressed Point Data

1. Call [ECCKeyUtil.convertPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpoint12) to convert uncompressed ECC point data of the Uint8Array type into a [Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10) object.
2. Call [ECCKeyUtil.getEncodedPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpoint12) to obtain compressed point data.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function eccPointUncompressedToCompressed() {
  let pkData = new Uint8Array([4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
  let returnPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', pkData);
  console.info('convertPoint success');
  let returnData = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'COMPRESSED');
  console.info('returnData: ' + returnData); // returnData is 2,143,39,57,249,145,50,63,222,35,70,178,121,202,154,21,146,129,75,76,63,8,195,157,111,40,217,215,148,120,224,205,82 (the prefix of the compressed point data is 02 because y is an even number). 
}
```

## Converting Compressed Point Data into a Key Object

1. Call [ECCKeyUtil.convertPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpoint12) to convert the compressed ECC point data of the Uint8Array type into a [Point](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#point10) object.
2. Call [ECCKeyUtil.genECCCommonParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#genecccommonparamsspec11) with the curve name set to **NID_brainpoolP256r1** to generate the common key parameters for the ECC key pair.
3. Construct a [ECCPubKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#eccpubkeyspec10) object to specify the parameters for the ECC public key. **ECCPubKeySpec** is a child class of **AsyKeySpec**. Set **algName** to **ECC**, specify [AsyKeySpecType.PUBLIC_KEY_SPEC](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#asykeyspectype10), and set **pk** to the **Point** object obtained in step 1.
4. Call [createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10) with the public key parameters to create an asymmetric key generator (**AsyKeyGeneratorBySpec**) object.
5. Call [AsyKeyGeneratorBySpec.generatePubKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatepubkey-1) to generate the public key.
6. Call [ECCKeyUtil.getEncodedPoint](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpoint12) to obtain uncompressed point data.
7. Call [PubKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10) to obtain the x coordinate of the ECC public key **pk**.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function eccPointCompressedToPoint() {
  let pkData = new Uint8Array([2, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82]);
  let returnPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', pkData);
  console.info('convertPoint success');
  let eccCommonParamsSpec = cryptoFramework.ECCKeyUtil.genECCCommonParamsSpec('NID_brainpoolP256r1');
  let eccPubKeySpec: cryptoFramework.ECCPubKeySpec = {
    algName: "ECC",
    specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC,
    params: eccCommonParamsSpec,
    pk: returnPoint
  };
  let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(eccPubKeySpec);
  let pubKey = await generatorBySpec.generatePubKey();
  let returnData = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'UNCOMPRESSED');
  console.info('returnData: ' + returnData); // 4,143,39,57,249,145,50,63,222,35,70,178,121,202,154,21,146,129,75,76,63,8,195,157,111,40,217,215,148,120,224,205,82,83,92,185,21,211,184,5,19,114,33,86,85,228,123,242,206,200,98,178,184,130,35,232,45,5,202,189,11,46,163,156,152
  let eccPkX = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
  console.info('returnPoint x data: ' + returnPoint.x); // 64750044510792891439269945828433327517677381559622384455951527515863444933970
  console.info('ECC_PK_X_BN: ' + eccPkX); // 64750044510792891439269945828433327517677381559622384455951527515863444933970
}
```
