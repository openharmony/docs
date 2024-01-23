# Randomly Generating an Asymmetric Key Pair


This topic uses RSA and SM2 as an example to describe how to generate an asymmetric key pair (**KeyPair**) and obtain the binary data.


The **KeyPair** object created can be used for subsequent encryption and decryption operations, and the binary data can be used for key storage and transfer.


## Randomly Generating an RSA Key Pair

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'RSA1024|PRIMES_2'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 1024-bit RSA key with two primes.

2. Use [AsyKeyGenerator.generateKeyPair](../../reference/apis/js-apis-cryptoFramework.md#generatekeypair-1) to randomly generate an asymmetric key pair.
   
   The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

3. Use [PubKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the public key, and use [PriKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the private key.

Example: Randomly generate an RSA key pair in promise mode.

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateAsyKey() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_2');
  // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: 'pk bin data' + pkBlob.data });
    AlertDialog.show({ message: 'sk bin data' + skBlob.data });
  });
}
```


## Randomly Generating an SM2 Key Pair

For details about the algorithm specifications, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2).

1. Use [cryptoFramework.createAsyKeyGenerator](../../reference/apis/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator) with the string parameter **'SM2_256'** to create an asymmetric key generator (**AsyKeyGenerator**) object for a 256-bit SM2 key pair.

2. Use [AsyKeyGenerator.generateKeyPair](../../reference/apis/js-apis-cryptoFramework.md#generatekeypair-1) to randomly generate an asymmetric key pair.
   
   The **KeyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

3. Use [PubKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the public key, and use [PriKey.getEncoded](../../reference/apis/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the private key.

Example: Randomly generate an SM2 key pair in promise mode.

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateSM2Key() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator('SM2_256');
  // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
  let keyGenPromise = sm2Generator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: 'pk bin data' + pkBlob.data });
    AlertDialog.show({ message: 'sk bin data' + skBlob.data });
  });
}
```
