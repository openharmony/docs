# Signing and Signature Verification Using ML-DSA Key Pairs (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-15T02:43:48.997Z pushedAt=2026-07-15T09:52:44.538Z -->

Starting from API version 26.0.0, the signing and signature verification operations support the ML-DSA algorithm. For algorithm specifications, see [Signature Verification Algorithm Specifications: ML-DSA](crypto-sign-sig-verify-overview.md#ml-dsa).

**Signing**

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a key pair (**KeyPair**) with the asymmetric key algorithm ML-DSA.

2. Call [cryptoFramework.createSign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesign) with the string parameter **ML-DSA** to create a **Sign** instance of the ML-DSA asymmetric key type for performing signing operations.

3. (Optional) Call [Sign.setSignSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setsignspec) to set ML-DSA signature parameters, such as deterministic signature (**ML_DSA_DETERMINISTIC_BOOL**), external μ hash mode (**ML_DSA_MU_BOOL**), or context string (**ML_DSA_CONTEXT_UINT8ARR**). When the external μ hash mode (**ML_DSA_MU_BOOL**) is set to **true**, the context string (**ML_DSA_CONTEXT_UINT8ARR**) is invalid.

4. Call [Sign.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-3) to initialize the **Sign** instance with the private key (**PriKey**).

   The ML-DSA signature algorithm does not support the update API.

5. Call [Sign.sign](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign-1) to generate a data signature.

**Signature Verification**

1. Call [cryptoFramework.createVerify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify) with the string parameter **'ML-DSA'** to create a **Verify** instance of the ML-DSA asymmetric key type for signature verification.

2. (Optional) Call [Verify.setVerifySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#setverifyspec) to set ML-DSA verification parameters, such as the external μ hash mode (**ML_DSA_MU_BOOL**) or the context string (**ML_DSA_CONTEXT_UINT8ARR**). The verification parameters must be consistent with the signing parameters. The deterministic signature parameter (**ML_DSA_DETERMINISTIC_BOOL**) is not required during verification.

3. Call [Verify.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-5) to initialize the **Verify** instance with the public key (**PubKey**).

   The ML-DSA verification algorithm does not support the **update** API.

4. Call [Verify.verify](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify-1) to verify the signature of the data.

- Asynchronous method example:

  <!-- @[signature_verification_with_ml_dsa_key_pair_ark_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/ml_dsa_signature_verification/ml_dsa_signature_verification_asynchronous.ets) -->

  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let input: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan', 'utf-8').buffer) };
  let context: Uint8Array = new Uint8Array(buffer.from('test', 'utf-8').buffer);
  
  async function signMessagePromise(priKey: cryptoFramework.PriKey) {
    let signer = cryptoFramework.createSign('ML-DSA');
    signer.setSignSpec(cryptoFramework.SignSpecItem.ML_DSA_DETERMINISTIC_BOOL, true);
    signer.setSignSpec(cryptoFramework.SignSpecItem.ML_DSA_CONTEXT_UINT8ARR, context);
    await signer.init(priKey);
    let signData = await signer.sign(input);
    return signData;
  }
  
  async function verifyMessagePromise(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifier = cryptoFramework.createVerify('ML-DSA');
    verifier.setVerifySpec(cryptoFramework.SignSpecItem.ML_DSA_CONTEXT_UINT8ARR, context);
    await verifier.init(pubKey);
    let res = await verifier.verify(input, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  async function main() {
    try {
      let generator = cryptoFramework.createAsyKeyGenerator('ML-DSA-87');
      let keyPair = await generator.generateKeyPair();
      let signData = await signMessagePromise(keyPair.priKey);
      let verifyResult = await verifyMessagePromise(signData, keyPair.pubKey);
      if (verifyResult === true) {
        console.info('verify result: success.');
        return 'Success';
      } else {
        console.error('verify result: failed.');
        return 'Fail';
      }
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`verify failed: errCode: ${e.code}, errMessage: ${e.message}`);
      return 'Fail';
    }
  }
  ```

- Synchronous method example:

  <!-- @[signature_verification_with_ml_dsa_key_pair_ark_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SignatureVerification/SigningSignatureVerificationArkTs/entry/src/main/ets/pages/ml_dsa_signature_verification/ml_dsa_signature_verification_synchronous.ets) -->

  ``` TypeScript
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let input: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('This is Sign test plan', 'utf-8').buffer) };
  let context: Uint8Array = new Uint8Array(buffer.from('test', 'utf-8').buffer);
  
  function signMessageSync(priKey: cryptoFramework.PriKey) {
    let signer = cryptoFramework.createSign('ML-DSA');
    signer.setSignSpec(cryptoFramework.SignSpecItem.ML_DSA_DETERMINISTIC_BOOL, true);
    signer.setSignSpec(cryptoFramework.SignSpecItem.ML_DSA_CONTEXT_UINT8ARR, context);
    signer.initSync(priKey);
    let signData = signer.signSync(input);
    return signData;
  }
  
  function verifyMessageSync(signMessageBlob: cryptoFramework.DataBlob, pubKey: cryptoFramework.PubKey) {
    let verifier = cryptoFramework.createVerify('ML-DSA');
    verifier.setVerifySpec(cryptoFramework.SignSpecItem.ML_DSA_CONTEXT_UINT8ARR, context);
    verifier.initSync(pubKey);
    let res = verifier.verifySync(input, signMessageBlob);
    console.info('verify result: ' + res);
    return res;
  }
  
  function main() {
    try {
      let generator = cryptoFramework.createAsyKeyGenerator('ML-DSA-87');
      let keyPair = generator.generateKeyPairSync();
      let signData = signMessageSync(keyPair.priKey);
      let verifyResult = verifyMessageSync(signData, keyPair.pubKey);
      if (verifyResult === true) {
        console.info('verify result: success.');
        return 'Success';
      } else {
        console.error('verify result: failed.');
        return 'Fail';
      }
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`verify failed: errCode: ${e.code}, errMessage: ${e.message}`);
      return 'Fail';
    }
  }
  ```

  <!--no_check-->