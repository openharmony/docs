# SM2签名数据格式转换(ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

当前支持DER格式与（r、s）格式互转的能力。
开发者可指定SM2签名数据，将其转换成DER格式密文。反之，也可以从DER格式密文中取出具体的SM2签名数据。

**指定密文参数，转换为DER格式**
1. 构造[EccSignatureSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#eccsignaturespec20)对象，用于指定SM2密文参数。

2. 调用[genEccSignature](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#geneccsignature20)，将EccSignatureSpec对象传入，转换为DER格式的SM2密文。

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

**指定DER格式，转换为（r、s）格式**
1. 指定DER格式的SM2密文参数。

2. 调用[genEccSignatureSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#geneccsignaturespec20)，将DER格式数据传入，转换为(r、s)格式的SM2密文。

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
