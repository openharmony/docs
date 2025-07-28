# Generating an Asymmetric Key Pair Based on Key Parameters (ArkTS)

This topic walks you through on how to generate an RSA, an ECC, and an SM2 asymmetric key pair (**KeyPair**) based on the specified key parameters and obtain the key parameter properties.

The **KeyPair** object created can be used for subsequent operations, such as encryption and decryption. The obtained key parameter properties can be used for key storage and transfer.

## Generating an RSA Public Key Based on Key Parameters

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Create an [RSACommonParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#rsacommonparamsspec10) object to specify the common parameter (**n**) of both the public and private keys of the RSA algorithm.
   
   **RSACommonParamsSpec** is a child class of **AsyKeySpec**. Specify the RSA algorithm in the **algName** parameter, and set the key parameter type to **AsyKeySpecType.COMMON_PARAMS_SPEC**, which indicates the common parameter for both the public and private keys.

   When key parameters are specified for generating a key, the bigint value must be a positive number in big-endian format.

2. Create an [RSAPubKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#rsapubkeyspec10) object to specify the parameters (**n**, **pk**) contained in the public key of the RSA algorithm.
   
   **RSAPubKeySpec** is a child class of **AsyKeySpec**. Specify the RSA algorithm in the **algName** parameter, and set the key parameter type to **AsyKeySpecType.PUBLIC_KEY_SPEC**, which indicates the parameters of the public key.

3. Call [cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10) with the **RSAPubKeySpec** object to create an asymmetric key generator (**AsyKeyGeneratorBySpec**) object.

4. Call [AsyKeyGeneratorBySpec.generatePubKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatepubkey-1) to generate the public key (**PubKey**).

5. Call [PubKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10) to obtain the modulus **n** and the public key exponent **pk** (expressed as e in the formula).

- Example: Generate an RSA public key based on key parameters (using callback-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  // Generate an RSA public key parameter (RsaPubKeySpec).
  function genRsaPubKeySpec(nIn: bigint, eIn: bigint): cryptoFramework.RSAPubKeySpec {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaPubKeySpec: cryptoFramework.RSAPubKeySpec = {
      params: rsaCommSpec,
      pk: eIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC
    };
    return rsaPubKeySpec;
  }
  // Construct an RSA public key specification object based on the key parameter.
  function genRsa2048PubKeySpec() {
    let nIn = BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
    let eIn = BigInt('0x010001');
    return genRsaPubKeySpec(nIn, eIn);
  }
  // Compare the RSA public key specifications with the expected value.
  function compareRsaPubKeyBySpec(rsaKeySpec: cryptoFramework.RSAPubKeySpec, n: bigint | string | number, e: bigint | string | number) {
    if (typeof n === 'string' || typeof e === 'string') {
      console.error('type is string');
      return false;
    }
    if (typeof n === 'number' || typeof e === 'number') {
      console.error('type is number');
      return false;
    }
    if (rsaKeySpec.params.n !== n) {
      return false;
    }
    if (rsaKeySpec.pk !== e) {
      return false;
    }
    return true;
  }
  // Generate an RSA public key based on the RSA public key specifications, obtain the key specifications, and compare it with the expected value.
  function rsaUsePubKeySpecGetCallback() {
    let rsaPubKeySpec = genRsa2048PubKeySpec();
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaPubKeySpec);
    rsaGeneratorSpec.generatePubKey((error, key) => {
      if (error) {
        console.error('generate pubKey error' + 'error code: ' + error.code + 'error message' + error.message);
      }
      let pubKey = key;
      let nBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_N_BN);
      let eBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_PK_BN);
      if (compareRsaPubKeyBySpec(rsaPubKeySpec, nBN, eBN) !== true) {
        console.error('error pub key big number');
      } else {
        console.info('n, e in the pubKey are same as the spec.');
      }
    });
  }
  ```

- Synchronously return the result ([generatePubKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatepubkeysync12)):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  // Generate an RSA public key parameter (RsaPubKeySpec).
  function genRsaPubKeySpec(nIn: bigint, eIn: bigint): cryptoFramework.RSAPubKeySpec {
    let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
      n: nIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
    };
    let rsaPubKeySpec: cryptoFramework.RSAPubKeySpec = {
      params: rsaCommSpec,
      pk: eIn,
      algName: 'RSA',
      specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC
    };
    return rsaPubKeySpec;
  }
  // Construct an RSA public key specification object based on the key parameter.
  function genRsa2048PubKeySpec() {
    let nIn = BigInt('0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25');
    let eIn = BigInt('0x010001');
    return genRsaPubKeySpec(nIn, eIn);
  }
  // Compare the RSA public key specifications with the expected value.
  function compareRsaPubKeyBySpec(rsaKeySpec: cryptoFramework.RSAPubKeySpec, n: bigint | string | number, e: bigint | string | number) {
    if (typeof n === 'string' || typeof e === 'string') {
      console.error('type is string');
      return false;
    }
    if (typeof n === 'number' || typeof e === 'number') {
      console.error('type is number');
      return false;
    }
    if (rsaKeySpec.params.n !== n) {
      return false;
    }
    if (rsaKeySpec.pk !== e) {
      return false;
    }
    return true;
  }
  // Generate an RSA public key based on the RSA public key specifications, obtain the key specifications, and compare it with the expected value.
  function rsaUsePubKeySpecGetSync() {
    let rsaPubKeySpec = genRsa2048PubKeySpec();
    let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaPubKeySpec);
    try {
      let pubKey = rsaGeneratorSpec.generatePubKeySync();
      if (pubKey !== null) {
        let nBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_N_BN);
        let eBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_PK_BN);
        if (compareRsaPubKeyBySpec(rsaPubKeySpec, nBN, eBN) !== true) {
          console.error('error pub key big number');
        } else {
          console.info('n, e in the pubKey are same as the spec.');
        }
      } else {
        console.error('get pub key result fail!');
      }
    } catch (e) {
      console.error(`get pub key result fail, ${e.code}, ${e.message}`);
    }
  }
  ```

## Generating an ECC Key Pair Based on Key Parameters

For details about the algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).

1. Create an [ECCCommonParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ecccommonparamsspec10) object to specify the common parameters of both the public and private keys of the ECC algorithm.
   **ECCCommonParamsSpec** is a child class of **AsyKeySpec**. Specify the ECC algorithm in the **algName** parameter, and set the key parameter type to **AsyKeySpecType.COMMON_PARAMS_SPEC**, which indicates the common parameter for both the public and private keys.

   When key parameters are specified for generating a key, the bigint value must be a positive number in big-endian format.

2. Call [cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10) with the **ECCCommonParamsSpec** object to create an asymmetric key generator (**AsyKeyGeneratorBySpec**) object.

3. Call [AsyKeyGeneratorBySpec.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-3) to generate a key pair (**KeyPair**).

4. Call [PriKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10-1) to obtain the private key specifications, and call [PubKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10) to obtain the public key specifications of the ECC.

- Example: Generate an ECC key pair based on key parameters (using promise-based APIs).
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Print bigint information.
  function showBigIntInfo(bnName: string, bnValue: bigint | string | number) {
    if (typeof bnValue === 'string') {
      console.error('type is string');
      return;
    }
    if (typeof bnValue === 'number') {
      console.error('type is number');
      return;
    }
    console.info(bnName + ':');
    console.info('. Decimal: ' + bnValue.toString());
    console.info('. Hexadecimal: ' + bnValue.toString(16));
    console.info('. Length (bits): ' + bnValue.toString(2).length);
  }
  // Construct the EccCommonSpec struct, which defines the common parameters of the ECC public and private keys.
  function genEccCommonSpec(): cryptoFramework.ECCCommonParamsSpec {
    let fieldFp: cryptoFramework.ECFieldFp = {
      fieldType: 'Fp',
      p: BigInt('0xffffffffffffffffffffffffffffffff000000000000000000000001')
    }
    let G: cryptoFramework.Point = {
      x: BigInt('0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21'),
      y: BigInt('0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34')
    }
    let eccCommonSpec: cryptoFramework.ECCCommonParamsSpec = {
      algName: 'ECC',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
      field: fieldFp,
      a: BigInt('0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe'),
      b: BigInt('0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4'),
      g: G,
      n: BigInt('0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d'),
      h: 1
    }
    return eccCommonSpec;
  }
  // Print the ECC key specifications.
  function showEccSpecDetailInfo(key: cryptoFramework.PubKey | cryptoFramework.PriKey, keyType: string) {
    console.info('show detail of ' + keyType + ':');
    try {
      let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
      showBigIntInfo('--- p', p); // length is 224, hex : ffffffffffffffffffffffffffffffff000000000000000000000001
      let a = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_A_BN);
      showBigIntInfo('--- a', a); // length is 224, hex : fffffffffffffffffffffffffffffffefffffffffffffffffffffffe
      let b = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_B_BN);
      showBigIntInfo('--- b', b); // length is 224, hex : b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4
      let gX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_X_BN);
      showBigIntInfo('--- gX', gX); // length is 224, hex : b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21
      let gY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_Y_BN);
      showBigIntInfo('--- gY', gY); // length is 224, hex : bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34
      let n = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_N_BN);
      showBigIntInfo('--- n', n); // length is 224, hex : ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d
      let h = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_H_NUM);
      console.warn('--- h: ' + h); // key h: 1
      let fieldType = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_TYPE_STR);
      console.warn('--- field type: ' + fieldType); // key field type: Fp
      let fieldSize = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_SIZE_NUM);
      console.warn('--- field size: ' + fieldSize); // key field size: 224
      let curveName = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
      console.warn('--- curve name: ' + curveName); // key curve name: NID_secp224r1
      if (keyType === 'priKey') {
        let sk = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_SK_BN);
        showBigIntInfo('--- sk', sk);
      } else if (keyType === 'pubKey') {
        let pkX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
        showBigIntInfo('--- pkX', pkX);
        let pkY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
        showBigIntInfo('--- pkY', pkY);
      }
    } catch (error) {
      console.error('getAsyKeySpec error');
      let e: BusinessError = error as BusinessError;
      console.error(`getAsyKeySpec failed, ${e.code}, ${e.message}`);
    }
  }
  // Generate an ECC key pair based on the EccCommonSpec instance and obtain the key specifications.
  function testEccUseCommKeySpecGet() {
    try {
      let commKeySpec = genEccCommonSpec(); // Construct the EccCommonSpec object.
      let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(commKeySpec); // Create an AsyKeyGenerator instance based on the EccCommonSpec object.
      let keyPairPromise = generatorBySpec.generateKeyPair(); // Generate an ECC key pair.
      keyPairPromise.then(keyPair => {// Use AsyKeyGenerator to create an ECC key pair.
        showEccSpecDetailInfo(keyPair.priKey, "priKey"); // Obtain the ECC private key specifications.
        showEccSpecDetailInfo(keyPair.pubKey, "pubKey"); // Obtain the ECC public key specifications.
      }).catch((error: BusinessError) => {
        // Capture exceptions such as logic errors asynchronously.
        console.error('generateComm error');
        console.error('error code: ' + error.code + ', message is: ' + error.message);
      })
    } catch (error) {
      // Capture parameter errors synchronously.
      console.error('testEccUseCommSpec error');
      let e: BusinessError = error as BusinessError;
      console.error(`ecc comm spec failed, ${e.code}, ${e.message}`);
    }
  }
  ```

- Synchronously return the result ([generateKeyPairSync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypairsync12)):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function showBigIntInfo(bnName: string, bnValue: bigint | string | number) {
    if (typeof bnValue === 'string') {
      console.error('type is string');
      return;
    }
    if (typeof bnValue === 'number') {
      console.error('type is number');
      return;
    }
    console.info(bnName + ':');
    console.info('. Decimal: ' + bnValue.toString());
    console.info('. Hexadecimal: ' + bnValue.toString(16));
    console.info('. Length (bits): ' + bnValue.toString(2).length);
  }
  // Construct the EccCommonSpec struct, which defines the common parameters of the ECC public and private keys.
  function genEccCommonSpec(): cryptoFramework.ECCCommonParamsSpec {
    let fieldFp: cryptoFramework.ECFieldFp = {
      fieldType: 'Fp',
      p: BigInt('0xffffffffffffffffffffffffffffffff000000000000000000000001')
    }
    let G: cryptoFramework.Point = {
      x: BigInt('0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21'),
      y: BigInt('0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34')
    }
    let eccCommonSpec: cryptoFramework.ECCCommonParamsSpec = {
      algName: 'ECC',
      specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
      field: fieldFp,
      a: BigInt('0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe'),
      b: BigInt('0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4'),
      g: G,
      n: BigInt('0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d'),
      h: 1
    }
    return eccCommonSpec;
  }
  // Print the ECC key specifications.
  function showEccSpecDetailInfo(key: cryptoFramework.PubKey | cryptoFramework.PriKey, keyType: string) {
    console.info('show detail of ' + keyType + ':');
    try {
      let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
      showBigIntInfo('--- p', p); // length is 224, hex : ffffffffffffffffffffffffffffffff000000000000000000000001
      let a = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_A_BN);
      showBigIntInfo('--- a', a); // length is 224, hex : fffffffffffffffffffffffffffffffefffffffffffffffffffffffe
      let b = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_B_BN);
      showBigIntInfo('--- b', b); // length is 224, hex : b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4
      let gX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_X_BN);
      showBigIntInfo('--- gX', gX); // length is 224, hex : b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21
      let gY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_Y_BN);
      showBigIntInfo('--- gY', gY); // length is 224, hex : bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34
      let n = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_N_BN);
      showBigIntInfo('--- n', n); // length is 224, hex : ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d
      let h = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_H_NUM);
      console.warn('--- h: ' + h); // key h: 1
      let fieldType = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_TYPE_STR);
      console.warn('--- field type: ' + fieldType); // key field type: Fp
      let fieldSize = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_SIZE_NUM);
      console.warn('--- field size: ' + fieldSize); // key field size: 224
      let curveName = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
      console.warn('--- curve name: ' + curveName); // key curve name: NID_secp224r1
      if (keyType === 'priKey') {
        let sk = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_SK_BN);
        showBigIntInfo('--- sk', sk);
      } else if (keyType === 'pubKey') {
        let pkX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
        showBigIntInfo('--- pkX', pkX);
        let pkY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
        showBigIntInfo('--- pkY', pkY);
      }
    } catch (e) {
      console.error(`getAsyKeySpec failed, ${e.code}, ${e.message}`);
    }
  }
  // Generate an ECC key pair based on the EccCommonSpec instance and obtain the key specifications.
  function testEccUseCommKeySpecGetSync() {
    try {
      let commKeySpec = genEccCommonSpec(); // Construct the EccCommonSpec object.
      let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(commKeySpec); // Create an AsyKeyGenerator instance based on the EccCommonSpec object.
      let keyPair = generatorBySpec.generateKeyPairSync(); // Generate an ECC key pair.
      if (keyPair !== null) {
        showEccSpecDetailInfo(keyPair.priKey, "priKey"); // Obtain the ECC private key specifications.
        showEccSpecDetailInfo(keyPair.pubKey, "pubKey"); // Obtain the ECC public key specifications.
      } else {
        console.error('get key pair result fail!');
      }
    } catch (e) {
      // Capture exceptions such as logic errors here.
      console.error(`get key pair result fail, ${e.code}, ${e.message}`);
    }
  }
  ```


## Generating an SM2 Key Pair Based on the Elliptic Curve Name

For details about the algorithm specifications, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2).

1. Create an [ECCCommonParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ecccommonparamsspec10) object to specify common parameters of the private and public keys. Call [genECCCommonParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#genecccommonparamsspec11) with an NID string to generate the common parameters for the SM2 key pair.

    When key parameters are specified for generating a key, the bigint value must be a positive number in big-endian format.

2. Create an [ECCKeyPairSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ecckeypairspec10) object with **algName** set to **SM2** to specify the SM2 key pair parameters.

3. Call [cryptoFramework.createAsyKeyGeneratorBySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygeneratorbyspec10) with the **ECCKeyPairSpec** object to create an asymmetric key generator object.

4. Call [AsyKeyGeneratorBySpec.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-3) to generate an SM2 key pair (**KeyPair**).

5. Call [PriKey.getAsyKeySpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getasykeyspec10-1) to obtain elliptic curve parameters of SM2.

- Example: Generate an SM2 key based on the elliptic curve name (using promise-based APIs)
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function genSM2KeyPairSpec() {
    let sm2CommonParamsSpec = cryptoFramework.ECCKeyUtil.genECCCommonParamsSpec('NID_sm2');
    let sm2KeyPairSpec: cryptoFramework.ECCKeyPairSpec = {
      algName: "SM2",
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
      params: sm2CommonParamsSpec,
      sk: BigInt('0x6330B599ECD23ABDC74B9A5B7B5E00E553005F72743101C5FAB83AEB579B7074'),
      pk: {
        x: BigInt('0x67F3B850BDC0BA5D3A29D8A0883C4B17612AB84F87F18E28F77D824A115C02C4'),
        y: BigInt('0xD48966CE754BBBEDD6501A1385E1B205C186E926ADED44287145E8897D4B2071')
      },
    };
    return sm2KeyPairSpec;
  }

  async function sm2Test() {
    let sm2KeyPairSpec = genSM2KeyPairSpec();
    let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(sm2KeyPairSpec);
    let keyPair = await generatorBySpec.generateKeyPair();
    let sm2CurveName = keyPair.priKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
    console.info('ECC_CURVE_NAME_STR: ' + sm2CurveName); // NID_sm2
  }
  ```

- Synchronously return the result ([generateKeyPairSync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypairsync12)):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function genSM2KeyPairSpec() {
    let sm2CommonParamsSpec = cryptoFramework.ECCKeyUtil.genECCCommonParamsSpec('NID_sm2');
    let sm2KeyPairSpec: cryptoFramework.ECCKeyPairSpec = {
      algName: "SM2",
      specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
      params: sm2CommonParamsSpec,
      sk: BigInt('0x6330B599ECD23ABDC74B9A5B7B5E00E553005F72743101C5FAB83AEB579B7074'),
      pk: {
        x: BigInt('0x67F3B850BDC0BA5D3A29D8A0883C4B17612AB84F87F18E28F77D824A115C02C4'),
        y: BigInt('0xD48966CE754BBBEDD6501A1385E1B205C186E926ADED44287145E8897D4B2071')
      },
    };
    return sm2KeyPairSpec;
  }
  function sm2TestSync() {
    let sm2KeyPairSpec = genSM2KeyPairSpec();
    let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(sm2KeyPairSpec);
    try {
      let keyPair = generatorBySpec.generateKeyPairSync();
      if (keyPair !== null) {
        let sm2CurveName = keyPair.priKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
        console.info('ECC_CURVE_NAME_STR: ' + sm2CurveName); // NID_sm2
      } else {
        console.error('get key pair result fail!');
      }
    } catch (e) {
      console.error(`get key pair result fail, ${e.code}, ${e.message}`);
    }
  }
  ```
