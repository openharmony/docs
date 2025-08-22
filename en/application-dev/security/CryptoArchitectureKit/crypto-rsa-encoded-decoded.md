# Encoding and Decoding with an RSA Private Key (ArkTS)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

**Encoding**

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) and [AsyKeyGenerator.generateKeyPair](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#generatekeypair-1) to generate a 1024-bit RSA asymmetric key pair (**KeyPair**) with two primes. The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

   In addition to the example in this topic, [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md) may help you better understand how to generate an RSA asymmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.

2. Call [prikey.getEncodedPem](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencodedpem18) with the [KeyEncodingConfig](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#keyencodingconfig18) and **PKCS1/PKCS8** parameters to generate an encoded private key string.

**Decoding**

1. Call [cryptoFramework.createAsyKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) to create an RSA asymmetric key generator (**asyKeyGenerator**) instance.

   For details about how to generate an RSA asymmetric key pair, see the following example and [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

   > **NOTE**
   > The algorithm passed in for encoding must be the same as that used in encoding.

2. Call [asyKeyGenerator.convertPemKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpemkey18) or [asyKeyGenerator.convertPemKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertpemkeysync18) to pass in the encoded private key string and password. The private key string before encoding is returned.

- Encoding example:
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function TestPriKeyPkcs1Encoded() {
    let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
    let keyPair = rsaGenerator.generateKeyPairSync();
    let options : cryptoFramework.KeyEncodingConfig = {
        password: "123456",
        cipherName: "AES-128-CBC"
    }
    let priPemKey = keyPair.priKey;
    let priString = priPemKey.getEncodedPem('PKCS1', options);
    console.info("[sync]TestPriKeyPkcs1Encoded priString output is " + priString);
  }

  ```

- Decoding example:
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let priKeyPkcs1EncodingStr : string =
  "-----BEGIN RSA PRIVATE KEY-----\n"
    +"Proc-Type: 4,ENCRYPTED\n"
    +"DEK-Info: AES-128-CBC,815A066131BF05CF87CE610A59CC69AE\n\n"
    +"7Jd0vmOmYGFZ2yRY8fqRl3+6rQlFtNcMILvcb5KWHDSrxA0ULmJE7CW0DSRikHoA\n"
    +"t0KgafhYXeQXh0dRy9lvVRAFSLHCLJVjchx90V7ZSivBFEq7+iTozVp4AlbgYsJP\n"
    +"vx/1sfZD2WAcyMJ7IDmJyft7xnpVSXsyWGTT4f3eaHJIh1dqjwrso7ucAW0FK6rp\n"
    +"/TONyOoXNfXtRbVtxNyCWBxt4HCSclDZFvS9y8fz9ZwmCUV7jei/YdzyQI2wnE13\n"
    +"W8cKlpzRFL6BWi8XPrUtAw5MWeHBAPUgPWMfcmiaeyi5BJFhQCrHLi+Gj4EEJvp7\n"
    +"mP5cbnQAx6+paV5z9m71SKrI/WSc4ixsYYdVmlL/qwAK9YliFfoPl030YJWW6rFf\n"
    +"T7J9BUlHGUJ0RB2lURNNLakM+UZRkeE9TByzCzgTxuQtyv5Lwsh2mAk3ia5x0kUO\n"
    +"LHg3Eoabhdh+YZA5hHaxnpF7VjspB78E0F9Btq+A41rSJ6zDOdToHey4MJ2nxdey\n"
    +"Z3bi81TZ6Fp4IuROrvZ2B/Xl3uNKR7n+AHRKnaAO87ywzyltvjwSh2y3xhJueiRs\n"
    +"BiYkyL3/fnocD3pexTdN6h3JgQGgO5GV8zw/NrxA85mw8o9im0HreuFObmNj36T9\n"
    +"k5N+R/QIXW83cIQOLaWK1ThYcluytf0tDRiMoKqULiaA6HvDMigExLxuhCtnoF8I\n"
    +"iOLN1cPdEVQjzwDHLqXP2DbWW1z9iRepLZlEm1hLRLEmOrTGKezYupVv306SSa6J\n"
    +"OA55lAeXMbyjFaYCr54HWrpt4NwNBX1efMUURc+1LcHpzFrBTTLbfjIyq6as49pH\n"
    +"-----END RSA PRIVATE KEY-----\n"

  async function TestConvertPemKeyByPromise() {
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
    asyKeyGenerator.convertPemKey(null, priKeyPkcs1EncodingStr, "123456")
      .then(keyPair => {
        let priKey = keyPair.priKey;
        if (priKey) {
          console.info('convertPemKey success.');
        }
      }).catch((error: BusinessError) => {
      console.error("convertPemKey error, error message is " + error.message);
    });
  }

  ```
