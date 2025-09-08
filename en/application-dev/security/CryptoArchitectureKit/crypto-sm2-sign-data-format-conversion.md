# Converting SM2 Signature Formats (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

HarmonyOS supports the conversion between the DER and R|S formats.
You can specify SM2 signature parameters and convert them to DER ciphertext. You can also extract SM2 signature data from DER ciphertext.

**Converting Ciphertext Parameters to DER Ciphertext**
1. Create an [EccSignatureSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#eccsignaturespec20) instance to specify SM2 ciphertext parameters.

2. Call [genEccSignature](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#geneccsignature20) to pass the **EccSignatureSpec** object to convert it to SM2 ciphertext in DER format.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function testGenEccSignature() {
  try {
    let spec: cryptoFramework.EccSignatureSpec = {
      r: BigInt('97726608965854271693043443511967021777934035174185659091642456228829830775155'),
      s: BigInt('23084224202834231287427338597254751764391338275617140205467537273296855150376'),
    };

    let data = cryptoFramework.SignatureUtils.genEccSignature(spec);
    console.info('genEccSignature success');
    console.info('data is ' + data);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`ecc error, ${e.code}, ${e.message}`);
  }
}
```

**Converting DER Ciphertext to the R and S Parameters**
1. Specifies the SM2 ciphertext parameters in DER format.

2. Call [genEccSignatureSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#geneccsignaturespec20) to pass data in DER format and convert the data into SM2 ciphertext in R|S format.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function testGenEccSignatureSpec() {
  try {
    let data =
      new Uint8Array([48, 69, 2, 33, 0, 216, 15, 76, 238, 158, 165, 108, 76, 72, 63, 115, 52, 255, 51, 149, 54, 224,
        179, 49, 225, 70, 36, 117, 88, 154, 154, 27, 194, 161, 3, 1, 115, 2, 32, 51, 9, 53, 55, 248, 82, 7, 159, 179,
        144, 57, 151, 195, 17, 31, 106, 123, 32, 139, 219, 6, 253, 62, 240, 181, 134, 214, 107, 27, 230, 175, 40]);
    let spec: cryptoFramework.EccSignatureSpec = cryptoFramework.SignatureUtils.genEccSignatureSpec(data);
    console.info('genEccSignatureSpec success');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`ecc error, ${e.code}, ${e.message}`);
  }
}
```
