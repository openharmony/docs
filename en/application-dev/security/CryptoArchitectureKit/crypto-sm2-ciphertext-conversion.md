# Converting SM2 Ciphertext


The Crypto framework supports the SM2 ciphertext in ASN.1 format. The SM2 ciphertext consists of C1, C3 (the hash value), and C2 (the encrypted data). For details about the specifications, see [SM2 Ciphertext Format](crypto-asym-encrypt-decrypt-spec.md#sm2-ciphertext-format).

You can convert the SM2 ciphertext into ASN.1 format based on the SM2 parameters specified or obtain SM2 parameters from the SM2 ciphertext in ASN.1 format.


**Generating SM2 Ciphertext in ASN.1 Format**


1. Create an [SM2CipherTextSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sm2ciphertextspec12) instance to specify SM2 ciphertext parameters. If the ciphertext is not in ASN.1 format, you need to obtain the required parameters.

2. Use [genCipherTextBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#genciphertextbyspec12) with the **SM2CipherTextSpec** instance to generate the SM2 ciphertext in ASN.1 format.

3. Decrypt the SM2 ciphertext using the **cryptoFramework** APIs.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function testGenCipherTextBySpec() {
  let spec : cryptoFramework.SM2CipherTextSpec = {
      xCoordinate: BigInt('20625015362595980457695435345498579729138244358573902431560627260141789922999'),
      yCoordinate: BigInt('48563164792857017065725892921053777369510340820930241057309844352421738767712'),
      cipherTextData: new Uint8Array([100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169, 10, 65, 123]),
      hashData: new Uint8Array([87, 167, 167, 247, 88, 146, 203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111, 143, 115, 169, 125, 128, 42, 157, 31, 114, 198, 109, 244]),
  }
  // The data can be decrypted using cryptoFramework APIs.
  let data = cryptoFramework.SM2CryptoUtil.genCipherTextBySpec(spec, 'C1C3C2');
  console.info('genCipherTextBySpec success');
}
```


**Obtaining SM2 Parameters from Ciphertext in ASN.1 Format**


1. Check that the SM2 ciphertext is in ASN.1 format.

2. Use [getCipherTextSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#genciphertextbyspec12) to obtain SM2 parameters from the ciphertext.

3. You can combine SM2 parameters based on service requirements to generate SM2 ciphertext in other formats.

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function testGetCipherTextSpec() {
  let cipherTextArray = new Uint8Array([48, 118, 2, 32, 45, 153, 88, 82, 104, 221, 226, 43, 174, 21, 122, 248, 5, 232, 105, 41, 92, 95, 102, 224, 216, 149, 85, 236, 110, 6, 64, 188, 149, 70, 70, 183, 2, 32, 107, 93, 198, 247, 119, 18, 40, 110, 90, 156, 193, 158, 205, 113, 170, 128, 146, 109, 75, 17, 181, 109, 110, 91, 149, 5, 110, 233, 209, 78, 229, 96, 4, 32, 87, 167, 167, 247, 88, 146, 203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111, 143, 115, 169, 125, 128, 42, 157, 31, 114, 198, 109, 244, 4, 14, 100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169, 10, 65, 123]);
  let cipherText : cryptoFramework.DataBlob = {data : cipherTextArray};
  let spec : cryptoFramework.SM2CipherTextSpec = cryptoFramework.SM2CryptoUtil.getCipherTextSpec(cipherText, 'C1C3C2');
  console.info('getCipherTextSpec success');
}
```
<!--RP1-->
<!--RP1End-->