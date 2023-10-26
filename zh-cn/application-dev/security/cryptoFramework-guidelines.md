# 加解密算法库框架开发指导

> **说明：**
>
> 本开发指导需使用API version 9及以上版本SDK，仅适用于JS语言开发。

## 密钥对象生成与转换操作

### 场景说明

使用密钥生成操作中，典型的场景有：

1. 随机生成算法库密钥对象。该对象可用于后续的加解密等操作。
2. 根据密钥参数生成指定的算法库密钥对象。该对象可用于后续的加解密等操作。
3. 根据指定数据生成算法库密钥对象（也就是将外部或存储的二进制数据转换为算法库的密钥对象）。该对象可用于后续的加解密等操作。
4. 获取算法库密钥对象的二进制数据，用于存储或传输。
5. 对于非对称密钥，获取密钥对象的参数属性，用于存储或运输。

> **说明：**
>
> 密钥对象Key包括对称密钥SymKey和非对称密钥（公钥PubKey和私钥PriKey），其中公钥和私钥组成密钥对KeyPair。密钥之间的具体关系可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

以上场景涉及的常用接口如下表所示：

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createAsyKeyGenerator(algName : string) : AsyKeyGenerator|根据algName设置的非对称密钥规格，创建非对称密钥生成器对象|
|cryptoFramework|createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec;|根据密钥参数设置的非对称密钥规格，创建非对称密钥生成器对象|
|cryptoFramework|createSymKeyGenerator(algName : string) : SymKeyGenerator|根据algName设置的对称密钥规格，创建对称密钥生成器对象|
|AsyKeyGenerator|generateKeyPair(callback : AsyncCallback\<KeyPair>) : void|使用callback方式，随机生成非对称密钥对象KeyPair|
|AsyKeyGenerator|generateKeyPair() : Promise\<KeyPair>|使用Promise方式，随机生成非对称密钥对象KeyPair|
|SymKeyGenerator|generateSymKey(callback : AsyncCallback\<SymKey>) : void|使用callback方式，随机生成对称密钥对象SymKey|
|SymKeyGenerator|generateSymKey() : Promise\<SymKey>|使用Promise方式，随机生成对称密钥对象SymKey|
| AsyKeyGenerator          | convertKey(pubKey : DataBlob, priKey : DataBlob, callback : AsyncCallback\<KeyPair>) : void | 使用callback方式，根据指定的公钥和私钥二进制数据生成KeyPair对象<br/>（允许公钥/私钥为null，即只传入单一公钥或私钥，生成只携带公钥或私钥的KeyPair对象） |
| AsyKeyGenerator          | convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair> | 使用Promise方式，根据指定的公钥和私钥二进制数据生成KeyPair对象<br/>（允许公钥/私钥为null，即只传入单一公钥或私钥，生成只携带公钥或私钥的KeyPair对象） |
| SymKeyGenerator         | convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void| 使用callback方式，根据指定的二进制数据，生成对称密钥对象SymKey |
| SymKeyGenerator         |convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair>| 使用Promise方式，根据指定的二进制数据，生成对称密钥对象SymKey |
| Key | getEncoded() : DataBlob;  | 获取Key密钥对象的二进制数据（Key的子类实例包括对称密钥SymKey、公钥PubKey、私钥PriKey） |

### 随机生成RSA密钥对，并获得二进制数据

示例1：随机生成非对称密钥KeyPair，并获得二进制数据（场景1、3）

1. 创建非对称密钥生成器。
2. 通过非对称密钥生成器随机生成非对称密钥。
3. 获取密钥对象的二进制数据。

以使用Promise方式随机生成RSA密钥（1024位，素数个数为2）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function generateAsyKey() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_2');
  // Use the key generator to randomly generate an asymmetric key pair.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: 'pk bin data' + pkBlob.data });
    AlertDialog.show({ message: 'sk bin data' + skBlob.data });
  })
}
```

### 随机生成AES密钥，并获得二进制数据

示例2：随机生成对称密钥SymKey，并获得二进制数据（场景1、3）

1. 创建对称密钥生成器。
2. 通过对称密钥生成器随机生成对称密钥。
3. 获取算法库密钥对象的二进制数据。

以使用Promise方式随机生成AES密钥（256位）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function testGenerateAesKey() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  // Use the key generator to randomly generate a symmetric key.
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Obtain the binary data of the symmetric key and output the 256-bit key. The length is 32 bytes.
    let encodedKey = key.getEncoded();
    console.info('key hex:' + encodedKey.data);
  })
}
```

### 根据RSA密钥二进制数据，生成密钥对

示例3：根据指定的RSA非对称密钥二进制数据，生成KeyPair对象（场景2）

1. 获取RSA公钥或私钥二进制数据，公钥需满足ASN.1语法、X.509规范、DER编码格式，私钥需满足ASN.1语法、PKCS#8规范、DER编码格式。
2. 创建AsyKeyGenerator对象，调用convertKey方法，传入公钥二进制和私钥二进制（二者非必选项，可只传入其中一个），转换为KeyPair对象。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function convertAsyKey() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let pkVal = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 174, 203, 113, 83, 113, 3, 143, 213, 194, 79, 91, 9, 51, 142, 87, 45, 97, 65, 136, 24, 166, 35, 5, 179, 42, 47, 212, 79, 111, 74, 134, 120, 73, 67, 21, 19, 235, 80, 46, 152, 209, 133, 232, 87, 192, 140, 18, 206, 27, 106, 106, 169, 106, 46, 135, 111, 118, 32, 129, 27, 89, 255, 183, 116, 247, 38, 12, 7, 238, 77, 151, 167, 6, 102, 153, 126, 66, 28, 253, 253, 216, 64, 20, 138, 117, 72, 15, 216, 178, 37, 208, 179, 63, 204, 39, 94, 244, 170, 48, 190, 21, 11, 73, 169, 156, 104, 193, 3, 17, 100, 28, 60, 50, 92, 235, 218, 57, 73, 119, 19, 101, 164, 192, 161, 197, 106, 105, 73, 2, 3, 1, 0, 1]);
  let pkBlob: cryptoFramework.DataBlob = { data: pkVal };
  rsaGenerator.convertKey(pkBlob, null, (err, keyPair) => {
    if (err) {
      AlertDialog.show({ message: 'Convert keyPair fail' });
      return;
    }
    AlertDialog.show({ message: 'Convert keyPair success' });
  })
}
```

> **说明：**
>
> 当前convertKey操作，公钥只支持转换满足X.509规范的DER格式，私钥只支持PKCS#8规范的DER格式。

### 根据ECC密钥二进制数据，生成密钥对

示例4：根据指定的ECC非对称密钥二进制数据，生成KeyPair对象（场景2、3）

1. 获取ECC二进制密钥数据，封装成DataBlob对象。
2. 调用convertKey方法，传入公钥二进制和私钥二进制（二者非必选项，可只传入其中一个），转换为KeyPair对象。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function convertEccAsyKey() {
  let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
  let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray };
  let generator = cryptoFramework.createAsyKeyGenerator('ECC256');
  generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
    if (error) {
      AlertDialog.show({ message: 'Convert keyPair fail' });
      return;
    }
    AlertDialog.show({ message: 'Convert keyPair success' });
  })
}
```

### 根据3DES密钥二进制数据，生成密钥

示例5：根据指定的对称密钥二进制数据，生成SymKey对象（场景2、3）

1. 创建对称密钥生成器。
2. 通过对称密钥生成器，根据指定的对称密钥二进制数据，生成SymKey对象。
3. 获取算法库密钥对象的二进制数据。

以使用callback方式生成3DES密钥（3DES密钥只能为192位）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function genKeyMaterialBlob(): cryptoFramework.DataBlob {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

function testConvertSymKey() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  // Generate a symmetric key based on the specified data.
  let keyMaterialBlob = genKeyMaterialBlob();
  try {
    symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
      if (error) { // If the service logic fails to be executed, the first parameter of callback returns error information, that is, an exception is thrown asynchronously.
        let e: BusinessError = error as BusinessError;
        console.error(`convertKey error, ${e.code}, ${e.message}`);
        return;
      }
      console.info(`key algName: ${key.algName}`);
      console.info(`key format: ${key.format}`);
      let encodedKey = key.getEncoded(); // Obtain the binary data of the symmetric key and output in bytes array. The length is 24 bytes.
      console.info('key getEncoded hex: ' + encodedKey.data);
    })
  } catch (error) { // Throw an exception immediately when an error is detected in parameter check.
    let e: BusinessError = error as BusinessError;
    console.error(`convertKey failed, ${e.code}, ${e.message}`);
    return;
  }
}
```

### 随机生成SM2密钥对，并获得二进制数据

> **说明：**
>
> 从API version 10开始， 支持SM2非对称密钥随机生成。

示例6：随机生成非对称密钥KeyPair，并获得二进制数据（场景1、3）

1. 创建非对称密钥生成器。
2. 通过非对称密钥生成器随机生成非对称密钥。
3. 获取密钥对象的二进制数据。

以使用Promise方式随机生成SM2密钥（256位）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function generateSM2Key() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Use the key generator to randomly generate an asymmetric key pair.
  let keyGenPromise = sm2Generator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: "pk bin data" + pkBlob.data });
    AlertDialog.show({ message: "sk bin data" + skBlob.data });
  })
}
```

### 随机生成SM4密钥，并获得二进制数据

 > **说明：**
 >
 > 从API version 10开始， 支持SM4密钥随机生成。

示例7：随机生成对称密钥SymKey，并获得二进制数据（场景1、3）

1. 创建对称密钥生成器。
2. 通过对称密钥生成器随机生成对称密钥。
3. 获取算法库密钥对象的二进制数据。

以使用Promise方式随机生成SM4密钥（128位）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function testGenerateSM4Key() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("SM4_128");
  // Use the key generator to randomly generate a symmetric key.
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Obtain the binary data of the symmetric key and output a 128-bit byte stream. The length is 16 bytes.
    let encodedKey = key.getEncoded();
    console.info('key hex:' + encodedKey.data);
  })
}
```

### 根据SM2密钥二进制数据，生成密钥对

 > **说明：**
 >
 > 从API version 10开始， 支持SM2密钥转换。

示例8：根据指定的SM2非对称密钥二进制数据，生成KeyPair对象（场景2、3）

1. 获取SM2二进制密钥数据，封装成DataBlob对象。
2. 调用convertKey方法，传入公钥二进制和私钥二进制（二者非必选项，可只传入其中一个），转换为KeyPair对象。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function convertSM2AsyKey() {
  let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45, 3, 66, 0, 4, 90, 3, 58, 157, 190, 248, 76, 7, 132, 200, 151, 208, 112, 230, 96, 140, 90, 238, 211, 155, 128, 109, 248, 40, 83, 214, 78, 42, 104, 106, 55, 148, 249, 35, 61, 32, 221, 135, 143, 100, 45, 97, 194, 176, 52, 73, 136, 174, 40, 70, 70, 34, 103, 103, 161, 99, 27, 187, 13, 187, 109, 244, 13, 7]);
  let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 54, 41, 239, 240, 63, 188, 134, 113, 31, 102, 149, 203, 245, 89, 15, 15, 47, 202, 170, 60, 38, 154, 28, 169, 189, 100, 251, 76, 112, 223, 156, 159, 160, 10, 6, 8, 42, 129, 28, 207, 85, 1, 130, 45]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray };
  let generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
    if (error) {
      AlertDialog.show({ message: "Convert keypair fail" });
      return;
    }
    AlertDialog.show({ message: "Convert KeyPair success" });
  })
}
```

### 随机生成HMAC密钥，并获得二进制数据

 > **说明：**
 >
 > 从API version 11开始， 支持HMAC密钥随机生成。

示例9：随机生成HMAC算法中使用的对称密钥SymKey，并获得二进制数据（场景1、3）

1. 创建对称密钥生成器。
2. 通过对称密钥生成器随机生成HMAC算法中使用的对称密钥。
3. 获取算法库密钥对象的二进制数据。

以使用Promise方式随机生成HMAC密钥（256位）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';

function testGenerateHmacKey() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("HMAC|SHA256");
  // Use the key generator to randomly generate a symmetric key.
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Obtain the binary data of the symmetric key and output a 256-bit byte stream. The length is 32 bytes.
    let encodedKey = key.getEncoded();
    console.info('key hex:' + encodedKey.data);
  })
}
```

### 根据HMAC密钥二进制数据，生成密钥

 > **说明：**
 >
 > 从API version 11开始， 支持HMAC密钥转换。

示例10：根据指定的HMAC对称密钥二进制数据，生成HMAC算法中使用的对称密钥SymKey（场景1、3）

1. 创建对称密钥生成器。
2. 通过对称密钥生成器，根据指定的HMAC二进制密钥数据，生成SymKey对象。

> **说明：**
>
> 1. 当传入“HMAC”创建对称密钥生成器时，支持传入长度在[1,4096]范围内（单位为byte）的二进制密钥数据生成symKey。
> 2. 当传入“HMAC|SHA512”创建对称密钥生成器时，需要传入64-byte长度的二进制密钥数据生成symKey。

以使用callback方式生成HMAC密钥（使用SHA512作为哈希函数）为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  let tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}

function testConvertHmacKey() {
  let keyBlob = {
    // The length is 512-bit (64 bytes).
    data : stringToUint8Array("12345678abcdefgh12345678abcdefgh12345678abcdefgh12345678abcdefgh")
  }
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("HMAC");
  symKeyGenerator.convertKey(keyBlob, (error, symKey) => {
    if (error) {
      console.info('Convert symKey fail!');
      return;
    }
    console.info('Convert symKey success!');
  })
}
```

## 非对称密钥对象根据参数生成与获取参数

### 场景说明

使用密钥生成操作中，典型的场景有：
1. 根据非对称密钥参数生成指定的算法库密钥对象。该对象可用于后续的加解密等操作。
2. 对于非对称密钥，获取密钥对象的参数属性，用于存储或运输。

> **说明：**
>
> 1. 从API version 10开始， 支持使用密钥参数来生成非对称密钥。
> 2. 非对称密钥（公钥PubKey和私钥PriKey），其中公钥和私钥组成密钥对KeyPair。非对称密钥参数具体可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md#asykeygeneratorbyspec10)。

以上场景涉及的常用接口如下表所示：

|实例名|接口名|描述|
|---|---|---|
|AsyKeyGeneratorBySpec|generateKeyPair(callback: AsyncCallback\<KeyPair>): void;|使用callback方式，根据密钥参数生成非对称密钥对象KeyPair
|AsyKeyGeneratorBySpec|generateKeyPair(): Promise\<KeyPair>;|使用Promise方式，根据密钥参数生成非对称密钥对象KeyPair
|AsyKeyGeneratorBySpec|generatePriKey(callback: AsyncCallback\<KeyPair>): void;|使用callback方式，根据密钥参数生成非对称私钥对象PriKey
|AsyKeyGeneratorBySpec|generatePriKey(): Promise\<KeyPair>;|使用Promise方式，根据密钥参数生成非对称私钥对象PriKey
|AsyKeyGeneratorBySpec|generatePubKey(callback: AsyncCallback\<KeyPair>): void;|使用callback方式，根据密钥参数生成非对称公钥对象PubKey
|AsyKeyGeneratorBySpec|generatePubKey(): Promise\<KeyPair>;|使用Promise方式，根据密钥参数生成非对称公钥对象PubKey
| PriKey | getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;  | 获取非对称密钥私钥对象的密钥参数属性 |
| PubKey | getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;  | 获取非对称密钥公钥对象的密钥参数属性 |

### 根据参数生成ECC密钥对，并获得密钥参数开发步骤

示例1：根据参数生成ECC密钥对，并获得密钥参数（场景1、2）

1. 创建根据密钥参数的非对称密钥生成器。
2. 通过根据密钥参数的非对称密钥生成器由指定密钥参数生成非对称密钥对。
3. 获取密钥对象的密钥参数属性。

以使用Promise方式根据密钥参数生成ECC密钥为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

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
  console.info(bnName + ":");
  console.info(". Decimal: " + bnValue.toString());
  console.info(". Hexadecimal: " + bnValue.toString(16));
  console.info(". Length (bits): " + bnValue.toString(2).length);
}

// Construct the EccCommonSpec struct based on the key specifications. The EccCommonSpec struct defines the common parameters of the ECC private key and public key.
function genEccCommonSpec(): cryptoFramework.ECCCommonParamsSpec {
  let fieldFp: cryptoFramework.ECFieldFp = {
    fieldType: "Fp",
    p: BigInt("0xffffffffffffffffffffffffffffffff000000000000000000000001")
  }

  let G: cryptoFramework.Point = {
    x: BigInt("0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21"),
    y: BigInt("0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34")
  }

  let eccCommonSpec: cryptoFramework.ECCCommonParamsSpec = {
    algName: "ECC",
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    field: fieldFp,
    a: BigInt("0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe"),
    b: BigInt("0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4"),
    g: G,
    n: BigInt("0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d"),
    h: 1
  }
  return eccCommonSpec;
}

// Print the ECC key specifications.
function showEccSpecDetailInfo(key: cryptoFramework.PubKey | cryptoFramework.PriKey, keyType: string) {
  console.info("show detail of " + keyType + ":");
  try {
    let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
    showBigIntInfo("--- p", p); // length is 224, hex : ffffffffffffffffffffffffffffffff000000000000000000000001

    let a = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_A_BN);
    showBigIntInfo("--- a", a); // length is 224, hex : fffffffffffffffffffffffffffffffefffffffffffffffffffffffe

    let b = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_B_BN);
    showBigIntInfo("--- b", b); // length is 224, hex : b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4

    let gX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_X_BN);
    showBigIntInfo("--- gX", gX); // length is 224, hex : b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21

    let gY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_Y_BN);
    showBigIntInfo("--- gY", gY); // length is 224, hex : bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34

    let n = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_N_BN);
    showBigIntInfo("--- n", n); // length is 224, hex : ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d

    let h = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_H_NUM);
    console.warn("--- h: " + h); // key h: 1

    let fieldType = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_TYPE_STR);
    console.warn("--- field type: " + fieldType); // key field type: Fp

    let fieldSize = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_SIZE_NUM);
    console.warn("--- field size: " + fieldSize); // key field size: 224

    let curveName = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
    console.warn("--- curve name: " + curveName); // key curve name: NID_secp224r1

    if (keyType == "priKey") {
      let sk = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_SK_BN);
      showBigIntInfo("--- sk", sk);
    } else if (keyType == "pubKey") {
      let pkX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
      showBigIntInfo("--- pkX", pkX);
      let pkY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
      showBigIntInfo("--- pkY", pkY);
    }
  } catch (error) {
    console.error("getAsyKeySpec error");
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
    keyPairPromise.then(keyPair => {
      showEccSpecDetailInfo(keyPair.priKey, "priKey"); // Obtain the ECC specifications of the private key.
      showEccSpecDetailInfo(keyPair.pubKey, "pubKey"); // Obtain the ECC specifications of the public key.
    }).catch((error: BusinessError) => {
      // Capture exceptions such as logic errors asynchronously here.
      console.error("generateComm error");
      console.error("error code: " + error.code + ", message is: " + error.message);
    })
  } catch (error) {
    // Capture parameter errors synchronously here.
    console.error("testEccUseCommSpec error");
    let e: BusinessError = error as BusinessError;
    console.error(`ecc comm spec failed, ${e.code}, ${e.message}`);
  }
}
```

### 根据参数生成RSA公钥，并获得密钥参数属性

示例2：根据参数生成RSA公钥，并获得密钥参数（场景1、2）

1. 创建根据密钥参数的非对称密钥生成器。
2. 通过根据密钥参数的非对称密钥生成器由指定密钥参数生成非对称密钥的公钥。
3. 获取密钥对象的密钥参数属性。

以使用Callback方式根据密钥参数生成RSA公钥为例：
```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';
// RSA公钥密钥参数生成函数
function genRsaPubKeySpec(nIn: bigint, eIn: bigint): cryptoFramework.RSAPubKeySpec {
  let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
    n: nIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
  };
  let rsaPubKeySpec: cryptoFramework.RSAPubKeySpec = {
    params: rsaCommSpec,
    pk: eIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC
  };
  return rsaPubKeySpec;
}

// Construct an RSA public key specifications object based on the key parameters.
function genRsa2048PubKeySpec() {
  let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
  let eIn = BigInt("0x010001");
  return genRsaPubKeySpec(nIn, eIn);
}

// Compare the RSA public key specifications with the expected values.
function compareRsaPubKeyBySpec(rsaKeySpec: cryptoFramework.RSAPubKeySpec, n: bigint | string | number, e: bigint | string | number) {
  if (typeof n === 'string' || typeof e === 'string') {
    console.error('type is string');
    return false;
  }
  if (typeof n === 'number' || typeof e === 'number') {
    console.error('type is number');
    return false;
  }
  if (rsaKeySpec.params.n != n) {
    return false;
  }
  if (rsaKeySpec.pk != e) {
    return false;
  }
  return true;
}

// Generate an RSA public key based on the RSA public key specifications, obtain the key specifications, and compare the key specifications with the expected values.
function rsaUsePubKeySpecGetCallback() {
  let rsaPubKeySpec = genRsa2048PubKeySpec();
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaPubKeySpec);
  rsaGeneratorSpec.generatePubKey((error, key) => {
    let pubKey = key;
    let nBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_N_BN);
    let eBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_PK_BN);
    if (compareRsaPubKeyBySpec(rsaPubKeySpec, nBN, eBN) != true) {
      AlertDialog.show({ message: "error pub key big number" });
    } else {
      console.info("n, e in the pubKey are same as the spec.");
    }
    if (error) {
      console.error("generate pubKey error" + "error code: " + error.code + "error message" + error.message);
    }
  });
}
```

## 使用加解密操作

### 场景说明

在数据存储或传输场景中，可以使用加解密操作用于保证数据的机密性，防止敏感数据泄露。使用加解密操作中，典型的场景有：
1. 使用对称密钥的加解密操作。
2. 使用非对称密钥的加解密操作。
3. 使用RSA, PKCS1_OAEP填充模式时，获取、设置CipherSpecItem参数。

> **说明：**
>
> 1. 从API version 10开始， 支持RSA使用PKCS1_OAEP填充模式时，获取、设置[CipherSpecItem](../reference/apis/js-apis-cryptoFramework.md#cipherspecitem10)参数。
> 2. 从API version 10开始，支持加解密时字符串参数不带密钥长度。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。<br/>由于密码算法的复杂性，在选取不同规格和参数时，开发差异较大，无法通过代码示例一一列举，请仔细阅读API参考资料中的相关接口，确保使用正确。

以上场景设计的常用接口如下表所示：

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createCipher(transformation : string) : Cipher|根据transformation设置的算法参数创建Cipher对象|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void|使用callback方式设置密钥并初始化Cipher对象|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>|使用Promise方式设置密钥并初始化Cipher对象|
|Cipher|update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|使用callback方式添加加解密数据|
|Cipher|update(data : DataBlob) : Promise\<DataBlob>|使用Promise方式添加加解密数据|
|Cipher|doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|使用callback方式结束对所有数据的加解密|
|Cipher|doFinal(data : DataBlob) : Promise\<DataBlob>|使用Promise方式结束对所有数据的加解密|
|Cipher|getCipherSpec(itemType: CipherSpecItem): string \| Uint8Array|获取加解密的参数，当前仅支持RSA算法|
|Cipher|setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void|设置加解密的参数，当前仅支持RSA算法|

### AES GCM以Promise方式加解密开发步骤：

示例1：使用AES对称密钥的加解密操作

1. 创建对称密钥生成器。
2. 通过密钥生成器随机生成对称密钥。
3. 创建加解密生成器。
4. 通过加解密生成器加密或解密数据。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob: cryptoFramework.DataBlob = { data: dataIv };

  arr = [0, 0, 0, 0, 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob: cryptoFramework.DataBlob = { data: dataAad };

  arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob: cryptoFramework.DataBlob = {
    data: dataTag
  }; // The GCM authTag is obtained by doFinal() in encryption and passed in params of init() in decryption.

  let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
    iv: ivBlob,
    aad: aadBlob,
    authTag: tagBlob,
    algName: "GcmParamsSpec"
  };
  return gcmParamsSpec;
}

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array: Uint8Array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// AES GCM模式示例，自动生成密钥（promise写法）
function testAesGcm() {
  let symAlgName = 'AES128';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);
  // Generate GCM parameter specifications.
  let globalGcmParams = genGcmParamsSpec();
  // Create a Cipher instance.
  let cipherAlgName = 'AES128|GCM|PKCS7';
  let globalCipher = cryptoFramework.createCipher(cipherAlgName);
  console.info(`cipher algName: ${globalCipher.algName}`);
  // Use the key generator to randomly generate a 128-bit symmetric key.
  let globalCipherText: cryptoFramework.DataBlob;
  let globalKey: cryptoFramework.SymKey;
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Initialize the Cipher instance and start encryption.
    globalKey = key;
    let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
    return globalCipher.init(mode, globalKey, globalGcmParams);
  })
    .then(() => {
      let plainText: cryptoFramework.DataBlob = { data: stringToUint8Array('this is test!') };
      return globalCipher.update(plainText);
    })
    .then((updateOutput: cryptoFramework.DataBlob): Promise<cryptoFramework.DataBlob> => {
      globalCipherText = updateOutput;
      return globalCipher.doFinal(null);
    })
    .then(tag => {
      // In GCM mode, the encrypted authentication information needs to be obtained from the output of doFinal() and passed in globalGcmParams of init() in decryption.
      globalGcmParams.authTag = tag;
      return;
    })
    .then(() => {
      // Initialize the Cipher instance and start decryption.
      let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
      return globalCipher.init(mode, globalKey, globalGcmParams);
    })
    .then(() => {
      return globalCipher.update(globalCipherText); // update
    })
    .then((updateOutput: cryptoFramework.DataBlob): Promise<cryptoFramework.DataBlob> => {
      console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
      return globalCipher.doFinal(null);
    })
    .then(finalOutput => {
      if (finalOutput == null) { // Check whether the result is null before using finalOutput.data.
        console.info('GCM finalOutput is null');
      }
    })
    .catch((error: BusinessError) => {
      console.error(`catch error, ${error.code}, ${error.message}`);
    })
}
```

### 3DES ECB以callback方式加解密开发步骤：

示例2：使用3DES对称密钥的加解密操作

1. 创建对称密钥生成器。
2. 通过已有二进制数据生成密钥。
3. 创建加解密生成器。
4. 通过加解密生成器加密或解密数据。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array: Uint8Array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function genKeyMaterialBlob(): cryptoFramework.DataBlob {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

// Generate a 3DES ECB key from the existing data in callback mode.
function test3DesEcb() {
  // Create a SymKeyGenerator instance.
  let symAlgName = '3DES192';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
  if (symKeyGenerator == null) {
    console.error('createSymKeyGenerator failed');
    return;
  }
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);

  // Create a Cipher instance.
  let cipherAlgName = '3DES192|ECB|PKCS7';
  let globalCipher = cryptoFramework.createCipher(cipherAlgName);

  // Generate a symmetric key based on the specified data.
  let keyMaterialBlob = genKeyMaterialBlob();
  try {
    symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
      if (error) {
        console.error(`convertKey error, ${error.code}, ${error.message}`);
        return;
      }
      console.info(`key algName: ${key.algName}`);
      console.info(`key format: ${key.format}`);
      let encodedKey = key.getEncoded();
      console.info('key getEncoded: ' + encodedKey.data);
      let globalKey = key;

      // Initialize the Cipher instance and start encryption.
      let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
      // init
      globalCipher.init(mode, key, null, (err,) => {
        let plainText: cryptoFramework.DataBlob = { data: stringToUint8Array('this is test!') };
        // update
        globalCipher.update(plainText, (err, updateOutput) => {
          let globalCipherText = updateOutput;
          //doFinal
          globalCipher.doFinal(null, (err, finalOutput) => {
            if (err) {
              console.error(`doFinal error, ${err.code}, ${err.message}`);
              return;
            }
            if (finalOutput != null) {
              let tmpCipherText = Array.from(globalCipherText.data);
              let tmpFinalOutput = Array.from(finalOutput.data);
              tmpCipherText = tmpCipherText.concat(tmpFinalOutput);
              globalCipherText = { data: new Uint8Array(tmpCipherText) };
            }
            // Initialize the Cipher instance and start decryption.
            let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
            // init
            globalCipher.init(mode, globalKey, null, (err,) => {
              // update
              globalCipher.update(globalCipherText, (err, updateOutput) => {
                console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
                // doFinal
                globalCipher.doFinal(null, (error, finalOutput) => {
                  if (finalOutput != null) { // Check whether the result is null before using finalOutput.data.
                    console.info('decrypt plainText: ' + uint8ArrayToString(finalOutput.data));
                  }
                })
              })
            })
          })
        })
      })
    })
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`3des failed, ${e.code}, ${e.message}`);
    return;
  }
}
```

### AES GCM以promise方式，分段update()加解密开发步骤：

示例3：使用AES对称密钥的分段update()加解密操作

1. 创建对称密钥生成器。
2. 通过已有二进制数据生成密钥。
3. 创建加解密生成器。
4. 通过加解密生成器加密或解密数据。

以AES GCM以promise方式，分段update()实现加解密为例：

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob: cryptoFramework.DataBlob = { data: dataIv };

  arr = [0, 0, 0, 0, 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob: cryptoFramework.DataBlob = { data: dataAad };

  arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob: cryptoFramework.DataBlob = {
    data: dataTag
  }; // The GCM authTag is obtained by doFinal() in encryption and passed in params of init() in decryption.

  let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
    iv: ivBlob,
    aad: aadBlob,
    authTag: tagBlob,
    algName: "GcmParamsSpec"
  };
  return gcmParamsSpec;
}

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array: Uint8Array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function testAesMultiUpdate() {
  let symAlgName = 'AES128';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);
  // Generate GCM parameter specifications.
  let globalGcmParams = genGcmParamsSpec();
  // Create a Cipher instance.
  let cipherAlgName = 'AES128|GCM|PKCS7';
  let globalCipher = cryptoFramework.createCipher(cipherAlgName);
  console.info(`cipher algName: ${globalCipher.algName}`);
  // Use the key generator to randomly generate a 128-bit symmetric key.
  let globalCipherText: cryptoFramework.DataBlob;
  let globalKey: cryptoFramework.SymKey;
  let globalPlainText = '';
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Initialize the Cipher instance and start encryption.
    globalKey = key;
    let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
    return globalCipher.init(mode, globalKey, globalGcmParams);
  })
    .then(async () => {
      let plainText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the plaintext is of 43 bytes.
      let messageArr: number[] = [];
      let updateLength = 20; // Pass in 20 bytes by update() each time.
      let tmpCipherText = new Uint8Array();

      for (let i = 0; i <= plainText.length; i++) {
        if ((i % updateLength == 0 || i == plainText.length) && messageArr.length != 0) {
          let message = new Uint8Array(messageArr);
          let messageBlob: cryptoFramework.DataBlob = { data: message };
          let updateOutput = await globalCipher.update(messageBlob); // Update by segment.
          // Combine the result of each update() to obtain the ciphertext. In certain cases, the doFinal() results need to be combined, which depends on the cipher block mode
          // and padding mode you use. In this example, the doFinal() result in GCM mode contains authTag but not ciphertext. Therefore, there is no need to combine the results.
          let mergeText = new Uint8Array(tmpCipherText.length + updateOutput.data.length);
          mergeText.set(tmpCipherText);
          mergeText.set(updateOutput.data, tmpCipherText.length);
          tmpCipherText = mergeText;
          // tmpCipherText = tmpCipherText.concat(Array.from(updateOutput.data));
          messageArr = [];
        }
        if (i < plainText.length) {
          messageArr.push(plainText.charCodeAt(i));
        }
      }
      globalCipherText = { data: tmpCipherText };
      return;
    })
    .then((): Promise<cryptoFramework.DataBlob> => {
      return globalCipher.doFinal(null);
    })
    .then(tag => {
      // In GCM mode, the encrypted authentication information needs to be obtained from the output of doFinal() and passed in globalGcmParams of init() in decryption.
      globalGcmParams.authTag = tag;
      return;
    })
    .then(() => {
      // Initialize the Cipher instance and start decryption.
      let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
      return globalCipher.init(mode, globalKey, globalGcmParams);
    })
    .then(async () => {
      let updateLength = 20;
      let updateTimes = Math.ceil(globalCipherText.data.length / updateLength); // Round up to the nearest integer.
      for (let i = 0; i < updateTimes; i++) {
        let messageArr = globalCipherText.data.slice(i * updateLength, (i + 1) * updateLength);
        let message = new Uint8Array(messageArr);
        let messageBlob: cryptoFramework.DataBlob = { data: message };
        let updateOutput = await globalCipher.update(messageBlob); // Update by segment.
        globalPlainText += uint8ArrayToString(updateOutput.data); // Restore the original plaintext.
      }
      return;
    })
    .then((): Promise<cryptoFramework.DataBlob> => {
      return globalCipher.doFinal(null);
    })
    .then(finalOutput => {
      if (finalOutput == null) { // Check whether the result is null before using finalOutput.data.
        console.info('GCM finalOutput is null');
      }
      console.info(`decrypt output: ${globalPlainText}`);
    })
    .catch((error: BusinessError) => {
      console.error(`catch error, ${error.code}, ${error.message}`);
    })
}
```

### RSA加解密开发步骤

示例4：使用RSA非对称密钥的加解密操作

1. 生成RSA密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成RSA非对称密钥。
2. 生成Cipher对象。通过createCipher接口创建Cipher对象，执行初始化操作，设置密钥及加解密模式。
3. 执行加解密操作。通过调用Cipher对象提供的doFinal接口，执行加密操作生成密文或执行解密操作生成明文。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

let plan = "This is cipher test.";

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Encrypt the message in promise mode.
function encryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
    let pubKey = rsaKeyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
  }).then(() => {
    // doFinal
    let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
    return cipher.doFinal(input);
  }).then(dataBlob => {
    // Obtain the encrypted data.
    console.info("EncryptOutPut is " + dataBlob.data);
  });
}

// Encrypt the message in callback mode.
function encryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  rsaGenerator.generateKeyPair((err, keyPair) => {
    let pubKey = keyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, (err, data) => {
      let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
      // doFinal
      cipher.doFinal(input, (err, data) => {
        // Obtain the encrypted data.
        console.info("EncryptOutPut is " + data.data);
      })
    })
  })
}

// Encrypt and decrypt the message in promise mode.
function decryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  let keyPair: cryptoFramework.KeyPair;
  let cipherDataBlob: cryptoFramework.DataBlob;
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
  keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
    keyPair = rsaKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the message.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  })
    .then(() => {
      // Call doFinal() to encrypt data.
      return cipher.doFinal(input);
    })
    .then((dataBlob: cryptoFramework.DataBlob): Promise<void> => {
      // Obtain the encrypted information and use it as the input parameter for decryption.
      console.info("EncryptOutPut is " + dataBlob.data);
      AlertDialog.show({ message: "output" + dataBlob.data });
      cipherDataBlob = dataBlob;
      // Initialize the Cipher instance and use the private key to decrypt the message.
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    })
    .then(() => {
      // Call doFinal() to decrypt the message.
      return decoder.doFinal(cipherDataBlob);
    })
    .then(decodeData => {
      // Check whether the decrypted data is consistent with the original data.
      if (decodeData.data.toString() === input.data.toString()) {
        AlertDialog.show({ message: "decrypt success" });
        return;
      }
      AlertDialog.show({ message: "decrypt fail" });
    });
}

// Encrypt and decrypt the message in callback mode.
function decryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  let plainText = "this is cipher text";
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plainText) };
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  rsaGenerator.generateKeyPair((err, newKeyPair) => {
    let keyPair = newKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the message.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null, (err, data) => {
      // Call doFinal() to encrypt the message.
      cipher.doFinal(input, (err, data) => {
        // Obtain the encrypted information and use it as the input parameter for decryption.
        AlertDialog.show({ message: "EncryptOutPut is " + data.data });
        let cipherData = data;
        // Initialize the Cipher instance and use the private key to decrypt the message.
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null, (err, data) => {
          // Call doFinal() to decrypt the message.
          decoder.doFinal(cipherData, (err, data) => {
            // Check whether the decrypted data is consistent with the original data.
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message: "decrype success" });
              return;
            }
            AlertDialog.show({ message: "decrype fail" });
          });
        });
      });
    });
  });
}
```

### RSA分段加解密开发步骤

示例5：使用RSA非对称密钥的分段加解密操作

1. 生成RSA密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成RSA非对称密钥。
2. 生成Cipher对象。通过createCipher接口创建Cipher对象，执行初始化操作，设置密钥及加解密模式。
3. 执行加解密操作。通过调用Cipher对象提供的doFinal接口，执行加密操作生成密文或执行解密操作生成明文，多次调用doFinal实现分段。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array: Uint8Array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function encryptLongMessagePromise() {
  let globalPlainText = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
  let globalKeyPair: cryptoFramework.KeyPair;
  let plainTextSplitLen = 64; // The length of the plaintext to be encrypted or decrypted each time by RSA depends on the number of key bits and padding mode. For details, see the Crypto Framework Overview.
  let cipherTextSplitLen = 128; // Length of the ciphertext = Number of key bits/8
  let keyGenName = "RSA1024";
  let cipherAlgName = "RSA1024|PKCS1";
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator(keyGenName); // Create an AsyKeyGenerator object.
  let cipher = cryptoFramework.createCipher(cipherAlgName); // Create a Cipher object.
  let decoder = cryptoFramework.createCipher(cipherAlgName); // Create a Decoder object.
  let keyGenPromise = asyKeyGenerator.generateKeyPair(); // Generate an RSA key pair.
  let globalCipherText: cryptoFramework.DataBlob;

  keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
    globalKeyPair = rsaKeyPair; // Save the key pair as a global variable.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, globalKeyPair.pubKey, null);
  })
    .then(async () => {
      let tmpCipherText = new Uint8Array();
      // Split the plaintext by 64 characters and cyclically call doFinal() to encrypt the plaintext. If a 1024-bit key is used, 128-byte ciphertext is generated each time.
      for (let i = 0; i < (globalPlainText.length / plainTextSplitLen); i++) {
        let tempStr = globalPlainText.substr(i * plainTextSplitLen, plainTextSplitLen);
        let tempBlob: cryptoFramework.DataBlob = { data: stringToUint8Array(tempStr) };
        let tempCipherOutput = await cipher.doFinal(tempBlob);
        let mergeText = new Uint8Array(tmpCipherText.length + tempCipherOutput.data.length);
        mergeText.set(tmpCipherText);
        mergeText.set(tempCipherOutput.data, tmpCipherText.length);
        tmpCipherText = mergeText;
      }
      globalCipherText = { data: tmpCipherText };
      console.info(`globalCipherOutput len is ${tmpCipherText.length}, data is: ${tmpCipherText.toString()}`);
      return;
    })
    .then((): Promise<void> => {
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, globalKeyPair.priKey, null);
    })
    .then(async () => {
      let tmpDecodeText = new Uint8Array();
      // Split and decrypt the ciphertext by 128 bytes, and combine the plaintext obtained each time.
      for (let i = 0; i < (globalCipherText.data.length / cipherTextSplitLen); i++) {
        let tempBlobData = globalCipherText.data.slice(i * cipherTextSplitLen, (i + 1) * cipherTextSplitLen);
        let message = new Uint8Array(tempBlobData);
        let tempBlob: cryptoFramework.DataBlob = { data: message };
        let tempDecodeOutput = await decoder.doFinal(tempBlob);
        let mergeText = new Uint8Array(tmpDecodeText.length + tempDecodeOutput.data.length);
        mergeText.set(tmpDecodeText);
        mergeText.set(tempDecodeOutput.data, tmpDecodeText.length);
        tmpDecodeText = mergeText;
      }
      let globalDecodeOutput = uint8ArrayToString(tmpDecodeText);
      if (globalDecodeOutput === globalPlainText) {
        console.info(`encode and decode success`);
      } else {
        console.info(`encode and decode error`);
      }
      return;
    })
    .catch((error: BusinessError) => {
      console.error(`catch error, ${error.code}, ${error.message}`);
    })
}
```

> **说明：**
>
> 1. 使用RSA加解密时，Cipher对象不可重复调用init方法初始化，在创建了一个加密Cipher对象后，如果要进行解密，则需要重新创建另一个Cipher对象执行解密操作。
> 2. RSA加密有长度限制，允许加密明文的最大长度见[加解密算法库框架概述](cryptoFramework-overview.md)中的基本概念加解密章节。
> 3. RSA解密每次允许解密的密文长度为，RSA密钥的位数/8。

### RSA加解密PKCS1_OAEP模式开发步骤

示例6：使用RSA非对称密钥使用PKCS1_OAEP模式的以Promise形式的加解密操作

1. 根据密钥参数生成RSA密钥。通过createAsyKeyGeneratorBySpec接口创建AsyKeyGeneratorBySpec对象，并生成RSA非对称密钥对（也可以使用createAsyKeyGenerator接口随机生成或转换得到RSA密钥对象）。
2. 生成Cipher对象。通过createCipher接口创建Cipher对象，执行初始化操作，设置密钥及加解密模式，在Update前通过setCipherSpec设置PKCS1_OAEP填充字节流P。
3. 执行加解密操作。通过调用Cipher对象提供的doFinal接口，执行加密操作生成密文或执行解密操作生成明文，需要加解密Cipher对象的字节流P一致。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 可理解的字符串转成字节流
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// 根据密钥参数属性构造RSA非对称密钥对密钥参数
function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
  let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
    n: nIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
  };
  let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
    params: rsaCommSpec,
    sk: dIn,
    pk: eIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
  };
  return rsaKeyPairSpec;
}

// 生成RSA2048密钥对参数
function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
  let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
  let eIn = BigInt("0x010001");
  let dIn = BigInt("0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1");
  return genRsaKeyPairSpec(nIn, eIn, dIn);
}

function rsaUseSpecDecryptOAEPPromise() {
  let plan = "This is cipher test.";
  // Obtain the key parameter object of the RSA key pair.
  let rsaKeyPairSpec = genRsa2048KeyPairSpec();
  // Generate an RSA key pair based on the RSA key parameters.
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
  let keyGenPromise = rsaGeneratorSpec.generateKeyPair();
  let cipher = cryptoFramework.createCipher("RSA|PKCS1_OAEP|SHA256|MGF1_SHA1");
  let decoder = cryptoFramework.createCipher("RSA|PKCS1_OAEP|SHA256|MGF1_SHA1");
  let keyPair: cryptoFramework.KeyPair;
  let cipherDataBlob: cryptoFramework.DataBlob;
  // Set the pSource, which defines the encoding input P filled by OAEP.
  let pSource = new Uint8Array([1, 2, 3, 4]);
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
  // Generate the key pair.
  keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
    keyPair = rsaKeyPair;
    // Initialize the Cipher instance for encryption.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  })
    .then(() => {
      // Set and obtain the cipher specifications after the initialization.
      cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
      let retP = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
      // Check whether the obtained PSource is the same as the PSource set.
      if (retP.toString() != pSource.toString()) {
        AlertDialog.show({ message: "error init pSource" + retP });
      } else {
        console.info("pSource changed ==" + retP);
      }
      // Obtain other OAEP parameters.
      let md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
      console.info("md == " + md);
      let mgf = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
      console.info("mgf == " + mgf);
      let mgf1Md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
      console.info("mgf1Md == " + mgf1Md);
      return cipher.doFinal(input);
    })
    .then((dataBlob: cryptoFramework.DataBlob): Promise<void> => {
      console.info("EncryptOutPut is " + dataBlob.data);
      cipherDataBlob = dataBlob;
      // The get() and set() operations can be performed before the init() operation of the Cipher object and are equivalent to those after the init() operation. For example, set and get the decoder.
      decoder.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
      let retP = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
      // Check whether the obtained PSource is the same as the PSource set.
      if (retP.toString() != pSource.toString()) {
        AlertDialog.show({ message: "error init pSource" + retP });
      } else {
        console.info("pSource changed ==" + retP);
      }
      // Obtain other OAEP parameters.
      let md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
      console.info("md == " + md);
      let mgf = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
      console.info("mgf == " + mgf);
      let mgf1Md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
      console.info("mgf1Md == " + mgf1Md);
      // Initialize the decryption operation.
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    })
    .then(() => {
      return decoder.doFinal(cipherDataBlob);
    })
    .then(decodeData => {
      // The decryption is successful.
      if (decodeData.data.toString() === input.data.toString()) {
        console.info("oaep decrypt success");
        AlertDialog.show({ message: " oaep decrypt success" });
      } else {
        AlertDialog.show({ message: "oeap decrypt fail" });
      }
    });
}
```

### SM2加解密开发步骤

> **说明：**
>
> 从API version 10开始， 支持SM2加解密。

示例7：使用SM2非对称密钥的加解密操作

1. 生成SM2密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成SM2非对称密钥。
2. 生成Cipher对象。通过createCipher接口创建Cipher对象，执行初始化操作，设置密钥及加解密模式。
3. 执行加解密操作。通过调用Cipher对象提供的doFinal接口，执行加密操作生成密文或执行解密操作生成明文。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

let plan = "This is cipher test.";

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// 以Promise方式加密
function encryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = sm2Generator.generateKeyPair();
  keyGenPromise.then((sm2KeyPair: cryptoFramework.KeyPair): Promise<void> => {
    let pubKey = sm2KeyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the message.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
  }).then(() => {
    // doFinal
    let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
    return cipher.doFinal(input);
  }).then(dataBlob => {
    // Obtain the encrypted data.
    console.info("EncryptOutPut is " + dataBlob.data);
  });
}

// Encrypt the message in callback mode.
function encryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  sm2Generator.generateKeyPair((err, keyPair) => {
    let pubKey = keyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the message.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, (err, data) => {
      let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
      // doFinal
      cipher.doFinal(input, (err, data) => {
        // Obtain the encrypted data.
        console.info("EncryptOutPut is " + data.data);
      })
    })
  })
}

// Encrypt and decrypt data in promise mode.
function decryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("SM2_256|SM3");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = sm2Generator.generateKeyPair();
  let keyPair: cryptoFramework.KeyPair;
  let cipherDataBlob: cryptoFramework.DataBlob;
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plan) };
  keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
    keyPair = rsaKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  })
    .then(() => {
      // Call doFinal() to encrypt data.
      return cipher.doFinal(input);
    })
    .then((dataBlob: cryptoFramework.DataBlob): Promise<void> => {
      // Obtain the encrypted information and use it as the input parameter for decryption.
      console.info("EncryptOutPut is " + dataBlob.data);
      AlertDialog.show({ message: "output" + dataBlob.data });
      cipherDataBlob = dataBlob;
      // Initialize the Cipher instance and use the private key to decrypt the data.
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    })
    .then(() => {
      // Call doFinal() to decrypt data.
      return decoder.doFinal(cipherDataBlob);
    })
    .then(decodeData => {
      // Check whether the decrypted data is consistent with the original data.
      if (decodeData.data.toString() === input.data.toString()) {
        AlertDialog.show({ message: "decrypt success" });
        return;
      }
      AlertDialog.show({ message: "decrypt fail" });
    });
}

// Encrypt and decrypt data in callback mode.
function decryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("SM2_256|SM3");
  let plainText = "this is cipher text";
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plainText) };
  let cipherData: cryptoFramework.DataBlob;
  let keyPair: cryptoFramework.KeyPair;
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  sm2Generator.generateKeyPair((err, newKeyPair) => {
    keyPair = newKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null, (err, data) => {
      // Call doFinal() to encrypt data.
      cipher.doFinal(input, (err, data) => {
        // Obtain the encrypted information and use it as the input parameter for decryption.
        AlertDialog.show({ message: "EncryptOutPut is " + data.data });
        cipherData = data;
        // Initialize the Cipher instance and use the private key to decrypt the data.
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null, (err, data) => {
          // Call doFinal() to decrypt data.
          decoder.doFinal(cipherData, (err, data) => {
            // Check whether the decrypted data is consistent with the original data.
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message: "decrypt success" });
              return;
            }
            AlertDialog.show({ message: "decrypt fail" });
          });
        });
      });
    });
  });
}
```

### SM4 ECB以callback方式加解密开发步骤：

> **说明：**
>
> 从API version 10开始， 支持SM4加解密。

示例8：使用SM4对称密钥的加解密操作

1. 创建对称密钥生成器。
2. 通过已有二进制数据生成密钥。
3. 创建加解密生成器。
4. 通过加解密生成器加密或解密数据。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array: Uint8Array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// SM4 ECB模式示例，callback写法
function testSM4Ecb() {
  // Create an AsyKeyGenerator instance.
  let sm4Generator = cryptoFramework.createSymKeyGenerator('SM4_128');
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("SM4_128|ECB|PKCS7");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("SM4_128|ECB|PKCS7");
  let plainText = "this is cipher text";
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plainText) };
  let cipherData: cryptoFramework.DataBlob;
  let key: cryptoFramework.SymKey;
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  sm4Generator.generateSymKey((err, newKey) => {
    key = newKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, key, null, (err, data) => {
      // Call doFinal() to encrypt data.
      cipher.doFinal(input, (err, data) => {
        // Obtain the encrypted information and use it as the input parameter for decryption.
        AlertDialog.show({ message: "EncryptOutPut is " + data.data });
        cipherData = data;
        // Initialize the Cipher instance and use the private key to decrypt the data.
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, key, null, (err, data) => {
          // Call doFinal() to decrypt data.
          decoder.doFinal(cipherData, (err, data) => {
            // Check whether the decrypted data is consistent with the original data.
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message: "decrypt success" });
              return;
            }
            AlertDialog.show({ message: "decrypt fail" });
          });
        });
      });
    });
  });
}
```

## 使用签名验签操作

### 场景说明

当需要判断接收的数据是否被篡改且是否为指定对象发送的数据时，可以使用签名验签操作。使用签名验签操作中，典型的场景有：
1. 使用RSA签名验签操作
2. 使用ECC签名验签操作
3. 使用RSA签名验签，PSS模式时，获取、设置SignSpecItem参数。
4. 使用SM2签名验签操作

> **说明：**
>
> 1. 从API version 10开始，支持RSA使用PSS填充模式时，获取、设置[SignSpecItem](../reference/apis/js-apis-cryptoFramework.md#signspecitem10)参数。
> 2. 从API version 10开始，支持签名验签时字符串参数不带密钥长度。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。<br/>由于密码算法的复杂性，在选取不同规格和参数时，开发差异较大，无法通过代码示例一一列举，请仔细阅读API参考资料中的相关接口，确保使用正确。

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createSign(algName : string) : Sign|根据String设置的参数创建Sign对象|
|Sign|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|使用callback方式设置密钥并初始化Sign对象|
|Sign|init(priKey : PriKey) : Promise\<void>|使用Promise方式设置密钥并初始化Sign对象|
|Sign|update(data : DataBlob, callback : AsyncCallback\<void>) : void|使用callback方式添加签名数据|
|Sign|update(data : DataBlob) : Promise\<void>|用Promise方式添加签名数据|
|Sign|sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|使用callback方式签名所有数据|
|Sign|sign(data : DataBlob) : Promise\<DataBlob>|使用Promise方式签名所有数据|
|Sign|getSignSpec(itemType: SignSpecItem): string \| number|获得签名的参数，当前仅支持RSA算法|
|Sign|setSignSpec(itemType: SignSpecItem, itemValue: number): void|设置签名的参数，当前仅支持RSA算法|
|cryptoFramework|function createVerify(algName : string) : Verify|根据String设置的参数创建Verify对象|
|Verify|init(pubKey : PubKey, callback : AsyncCallback\<void>) : void|使用callback方式设置密钥并初始化Verify对象|
|Verify|init(pubKey : PubKey) : Promise\<void>|使用Promise方式设置密钥并初始化Verify对象|
|Verify|update(data : DataBlob, callback : AsyncCallback\<void>) : void|使用callback方式添加验签数据|
|Verify|update(data : DataBlob) : Promise\<void>|用Promise方式添加验签数据|
|Verify|verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void|使用callback方式验签所有数据|
|Verify|verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>|使用Promise方式验签所有数据|
|Verify|getVerifySpec(itemType: SignSpecItem): string \| number|获得验签的参数，当前仅支持RSA算法|
|Verify|setVerifySpec(itemType: SignSpecItem, itemValue: number): void|设置验签的参数，当前仅支持RSA算法|

### RSA签名验签开发步骤

示例1：使用RSA签名验签操作

1. 生成RSA密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成RSA非对称密钥。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥。
3. 执行签名操作。通过Sign类提供的update接口，添加签名数据，并调用sign接口生成数据的签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥。
5. 执行验签操作。通过Verify类提供的update接口，添加签名数据，并调用verify接口传入签名进行验签。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 可理解的字符串转成字节流
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let globalKeyPair: cryptoFramework.KeyPair;
let signMessageBlob: cryptoFramework.DataBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1: cryptoFramework.DataBlob = { data: stringToUint8Array(plan1) };
let input2: cryptoFramework.DataBlob = { data: stringToUint8Array(plan2) };

function signMessagePromise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256"); // From API version 10, a Sign instance can be created by specifying a string parameter defining the key specifications.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    signMessageBlob = dataBlob;
    console.info("sign output is " + signMessageBlob.data);
  });
}

// Call verify() after sign() is called.
function verifyMessagePromise() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
  verifyInitPromise.then(() => {
    return verifyer.update(input1);
  }).then(() => {
    return verifyer.verify(input2, signMessageBlob);
  }).then(res => {
    console.log("Verify result is " + res);
  });
}

function signMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256"); // From API version 10, a Sign instance can be created by specifying a string parameter defining the key specifications.
  rsaGenerator.generateKeyPair((err, keyPair) => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => {
        signer.sign(input2, (err, data) => {
          signMessageBlob = data;
          console.info("sign output is " + signMessageBlob.data);
        });
      });
    });
  });
}

// Call verify() after sign() is called.
function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  verifyer.init(globalKeyPair.pubKey, err => {
    verifyer.update(input1, err => {
      verifyer.verify(input2, signMessageBlob, (err, data) => {
        console.info("verify result is " + data);
      });
    });
  })
}
```

### ECDSA签名验签开发步骤

示例2：使用ECDSA操作

1. 生成ECC密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成ECC非对称密钥。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥。
3. 执行签名操作。通过Sign类提供的update接口，添加签名数据，并调用doFinal接口生成数据的签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥。
5. 执行验签操作。通过Verify类提供的update接口，添加签名数据，并调用doFinal接口传入签名进行验签。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 可理解的字符串转成字节流
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let globalKeyPair: cryptoFramework.KeyPair;
let signMessageBlob: cryptoFramework.DataBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1: cryptoFramework.DataBlob = { data: stringToUint8Array(plan1) };
let input2: cryptoFramework.DataBlob = { data: stringToUint8Array(plan2) };

function signMessagePromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    signMessageBlob = dataBlob;
    console.info("sign output is " + signMessageBlob.data);
  });
}

function verifyMessagePromise() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
  verifyInitPromise.then(() => {
    return verifyer.update(input1);
  }).then(() => {
    return verifyer.verify(input2, signMessageBlob);
  }).then(res => {
    console.log("Verify result is " + res);
  });
}

function signMessageCallback() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  eccGenerator.generateKeyPair((err, keyPair) => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => {
        signer.sign(input2, (err, data) => {
          signMessageBlob = data;
          console.info("sign output is " + signMessageBlob.data);
        });
      });
    });
  });
}

function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  verifyer.init(globalKeyPair.pubKey, err => {
    verifyer.update(input1, err => {
      verifyer.verify(input2, signMessageBlob, (err, data) => {
        console.info("verify result is " + data);
      });
    });
  })
}
```

### RSA分段签名验签开发步骤

示例3：使用RSA签名验签操作

1. 生成RSA密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成RSA非对称密钥。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥。
3. 执行签名操作。通过Sign类提供的update接口，多次添加签名数据，并调用sign接口生成数据的签名，完成分段签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥。
5. 执行验签操作。多次通过Verify类提供的update接口，添加签名数据，并调用verify接口传入签名进行验签，完成分段验签。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 可理解的字符串转成字节流
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

function signLongMessagePromise() {
  let globalPlainText = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
    "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
  let globalSignData: Uint8Array;
  let textSplitLen = 64; // Customized data splitting length.
  let keyGenName = "RSA1024";
  let signAlgName = "RSA1024|PKCS1|SHA256";
  let globalKeyPair: cryptoFramework.KeyPair;
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator(keyGenName); // Create an AsyKeyGenerator object.
  let signer = cryptoFramework.createSign(signAlgName); // Create a Signer instance.
  let verifier = cryptoFramework.createVerify(signAlgName); // Create a Verifier instance.
  let keyGenPromise = asyKeyGenerator.generateKeyPair();
  keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
    globalKeyPair = rsaKeyPair; // Save the key pair as a global variable.
    return signer.init(globalKeyPair.priKey);
  })
    .then(async (): Promise<void> => {
      // If the plaintext is too large, split the plaintext based on the specified length and cyclically call update() to pass in the plaintext.
      for (let i = 0; i < (globalPlainText.length / textSplitLen); i++) {
        let tempStr = globalPlainText.substr(i * textSplitLen, textSplitLen);
        let tempBlob: cryptoFramework.DataBlob = { data: stringToUint8Array(tempStr) };
        await signer.update(tempBlob);
      }
    })
    .then((): Promise<cryptoFramework.DataBlob> => {
      return signer.sign(null);
    })
    .then((signData: cryptoFramework.DataBlob): Promise<void> => {
      globalSignData = signData.data;
      console.info(`globalSignOutput len is ${globalSignData.length}, data is: ${globalSignData.toString()}`);
      return verifier.init(globalKeyPair.pubKey);
    })
    .then(async () => {
      // If the plaintext is too large, split the plaintext based on the specified length and cyclically call update() to pass in the plaintext.
      for (let i = 0; i < (globalPlainText.length / textSplitLen); i++) {
        let tempData = globalPlainText.slice(i * textSplitLen, (i + 1) * textSplitLen);
        let tempBlob: cryptoFramework.DataBlob = { data: stringToUint8Array(tempData) };
        await verifier.update(tempBlob);
      }
      return;
    })
    .then((): Promise<boolean> => {
      return verifier.verify(null, { data: globalSignData });
    })
    .then(res => {
      console.info(`verify res is ${res}`);
    })
    .catch((error: BusinessError) => {
      console.error(`catch error, ${error.code}, ${error.message}`);
    })
}
```

### RSA签名验签PSS模式开发步骤

示例4：使用RSA签名验签PSS模式，以Callback形式完成签名验签流程。

1. 根据密钥参数生成RSA密钥。通过createAsyKeyGeneratorBySpec接口创建AsyKeyGeneratorBySpec对象，并生成RSA非对称密钥对。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥，可以获得、设置PSS模式相关参数。
3. 执行签名操作。通过Sign类提供的update接口，添加签名数据，并调用sign接口生成数据的签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥，可以获得、设置PSS模式相关参数，验签成功需要保证盐值长度一致。
5. 执行验签操作。通过Verify类提供的update接口，添加签名数据，并调用verify接口传入签名进行验签。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array: Uint8Array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// 根据密钥参数属性构造RSA非对称密钥对密钥参数
function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
  let rsaCommSpec: cryptoFramework.RSACommonParamsSpec = {
    n: nIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC
  };
  let rsaKeyPairSpec: cryptoFramework.RSAKeyPairSpec = {
    params: rsaCommSpec,
    sk: dIn,
    pk: eIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
  };
  return rsaKeyPairSpec;
}

// 生成RSA2048密钥对参数
function genRsa2048KeyPairSpec(): cryptoFramework.RSAKeyPairSpec {
  let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
  let eIn = BigInt("0x010001");
  let dIn = BigInt("0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1");
  return genRsaKeyPairSpec(nIn, eIn, dIn);
}

function verifyMessageCallbackPSS() {
  let plan1 = "This is Sign test plan1";
  let plan2 = "This is Sign test plan1";
  let input1: cryptoFramework.DataBlob = { data: stringToUint8Array(plan1) };
  let input2: cryptoFramework.DataBlob = { data: stringToUint8Array(plan2) };
  let globalKeyPair: cryptoFramework.KeyPair;
  let signMessageBlob: cryptoFramework.DataBlob;
  // Obtain the key parameter object of the RSA key pair.
  let rsaKeyPairSpec = genRsa2048KeyPairSpec();
  // Create an RSA key pair generator.
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
  // Both sign() and verify() support the RSA key with or without the length.
  let signer = cryptoFramework.createSign("RSA|PSS|SHA256|MGF1_SHA256");
  let verifyer = cryptoFramework.createVerify("RSA2048|PSS|SHA256|MGF1_SHA256");
  rsaGeneratorSpec.generateKeyPair((err, keyPair) => {
    globalKeyPair = keyPair;
    signer.init(globalKeyPair.priKey, err => {
      // After the initialization, set and obtain the PSS parameters.
      let setN = 32;
      signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
      let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
      console.info("SaltLen == " + saltLen);
      let tf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
      console.info("trailer field == " + tf);
      let md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
      console.info("md == " + md);
      let mgf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
      console.info("mgf == " + mgf);
      let mgf1Md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
      console.info("mgf1Md == " + mgf1Md);
      signer.update(input1, err => {
        signer.sign(input2, (err, data) => {
          // Before signature verification initialization, set and obtain PSS parameters. The functions are the same as those after initialization.
          signMessageBlob = data;
          AlertDialog.show({ message: "res" + signMessageBlob.data });
          let setN = 32;
          verifyer.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
          let saltLen = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
          console.info("SaltLen == " + saltLen);
          let tf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
          console.info("trailer field == " + tf);
          let md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
          console.info("md == " + md);
          let mgf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
          console.info("mgf == " + mgf);
          let mgf1Md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
          console.info("mgf1Md == " + mgf1Md);
          verifyer.init(globalKeyPair.pubKey, err => {
            verifyer.update(input1, err => {
              verifyer.verify(input2, signMessageBlob, (err, data) => {
                AlertDialog.show({ message: "res " + data });
              })
            });
          });
        });
      });
    });
  });
}
```

### SM2签名验签开发步骤

> **说明：**
>
> 从API version 10开始， 支持SM2签名验签。

示例5：使用SM2操作

1. 生成SM2密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成SM2非对称密钥。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥。
3. 执行签名操作。通过Sign类提供的update接口，添加签名数据，并调用doFinal接口生成数据的签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥。
5. 执行验签操作。通过Verify类提供的update接口，添加签名数据，并调用doFinal接口传入签名进行验签。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan2";
let input1: cryptoFramework.DataBlob = { data: stringToUint8Array(plan1) };
let input2: cryptoFramework.DataBlob = { data: stringToUint8Array(plan2) };

function signAndVerify() {
  let signMessageBlob: cryptoFramework.DataBlob;
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  let signer = cryptoFramework.createSign("SM2_256|SM3");
  sm2Generator.generateKeyPair((err, keyPair) => {
    let priKey = keyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => {
        signer.sign(input2, (err, data) => {
          signMessageBlob = data;
          console.info("sign output is " + signMessageBlob.data);
          let verifyer = cryptoFramework.createVerify("SM2_256|SM3");
          verifyer.init(keyPair.pubKey, err => {
            verifyer.update(input1, err => {
              verifyer.verify(input2, signMessageBlob, (err, data) => {
                console.info("verify result is " + data);
                AlertDialog.show({ message: "verify success" })
              });
            });
          })
        });
      });
    });
  });
}
```

## 使用密钥协商操作

### 场景说明

使用密钥协商操作中，典型的场景有：

通信双方可以在一个公开的信道上通过相互传送一些消息，共同建立一个安全的共享秘密密钥。

> **说明：**
>
> 从API version 10开始，支持密钥协商时字符串参数不带密钥长度。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createKeyAgreement(algName : string) : KeyAgreement|根据String设置的参数创建KeyAgreement对象|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void|使用callback方式进行密钥协商|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>|使用Promise方式进行密钥协商|

### 开发步骤

1. 生成ECC密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成ECC非对称密钥。
2. 基于ECC密钥的私钥及公钥执行ECDH操作。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

let globalKeyPair: cryptoFramework.KeyPair;

function ecdhPromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256"); // ECC is supported for key agreement from API version 10.
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    return eccKeyAgreement.generateSecret(keyPair.priKey, keyPair.pubKey);
  }).then((secret) => {
    console.info("ecdh output is " + secret.data);
  }).catch((error: BusinessError) => {
    console.error("ecdh error.");
  });
}

function ecdhCallback() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.generateKeyPair((err, keyPair) => {
    globalKeyPair = keyPair;
    eccKeyAgreement.generateSecret(keyPair.priKey, keyPair.pubKey, (err, secret) => {
      if (err) {
        console.error("ecdh error.");
        return;
      }
      console.info("ecdh output is " + secret.data);
    });
  });
}
```

## 使用摘要操作

### 场景说明

用户指定摘要算法（如SHA256）生成Md实例，并输入单段或多段需要摘要的信息，进行摘要计算更新，并返回消息摘要计算结果，在指定算法后可获取当前算法名与摘要计算长度（字节）

使用摘要操作的主要场景为：

用户指定摘要算法（如SHA256）生成Md实例，并输入单段或多段需要摘要的信息，进行摘要计算更新，并返回消息摘要计算结果，在指定算法后可获取当前算法名与摘要计算长度（字节）

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

| 实例名          | 接口名                                                       | 描述                                               |
| --------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| cryptoFramework | function createMd(algName : string) : Md;                    | 指定摘要算法，生成摘要操作实例Md                   |
| Md              | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | 接受用户输入数据，通过Callback的方式，异步更新摘要 |
| Md              | update(input : DataBlob) : Promise\<void>;                  | 接受用户输入数据，通过Promise的方式，异步更新摘要  |
| Md              | digest(callback : AsyncCallback\<DataBlob>) : void;         | 通过Callback的方式，返回结果                       |
| Md              | digest() : Promise\<DataBlob>;                              | 通过Promise的方式，返回结果                        |
| Md              | getMdLength() : number;                                      | 获取摘要的长度（由指定的摘要算法决定）             |
| Md              | readonly algName : string;                                   | 获取当前设置的摘要算法名                           |

### 摘要算法开发步骤

1. 设置算法，通过接口`createMd`生成摘要操作实例。
2. 接受用户数据，通过接口`update`，更新摘要，此步骤可重复，算法库不限制单次update的长度。
3. 通过接口`digest`，返回摘要计算结果。
4. 获取当前摘要算法名与摘要计算长度。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// 以Promise方式完成摘要
function doMdByPromise() {
  let mdAlgName = "SHA256"; // Digest algorithm name.
  let message = "mdTestMessgae"; // Data to be digested.
  let md = cryptoFramework.createMd(mdAlgName);
  console.info("[Promise]: Md algName is: " + md.algName);
  // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
  let promiseMdUpdate = md.update({ data: stringToUint8Array(message) });
  promiseMdUpdate.then(() => {
    // Call digest() to return the result.
    let PromiseMdDigest = md.digest();
    return PromiseMdDigest;
  }).then(digestOutput => {
    let mdOutput = digestOutput;
    console.info("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("[Promise]: MD len: " + mdLen);
  }).catch((error: BusinessError) => {
    console.error("[Promise]: error: " + error.message);
  });
}

// 以Callback方式完成摘要
function doMdByCallback() {
  let mdAlgName = "SHA256"; // Digest algorithm name.
  let message = "mdTestMessgae"; // Data to be digested.
  let md = cryptoFramework.createMd(mdAlgName);
  console.info("[Callback]: Md algName is: " + md.algName);
  // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
  md.update({ data: stringToUint8Array(message) }, (err,) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    md.digest((err1, digestOutput) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      } else {
        let mdOutput = digestOutput;
        console.info("[Callback]: MD result: " + mdOutput.data);
        let mdLen = md.getMdLength();
        console.info("[Callback]: MD len: " + mdLen);
      }
    });
  });
}
```

### 分段摘要算法开发步骤

1. 设置算法，通过接口`createMd`生成摘要操作实例。
2. 接受用户数据，多次通过接口`update`，更新摘要，实现分段。
3. 通过接口`digest`，返回摘要计算结果。
4. 获取当前摘要算法名与摘要计算长度。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 可理解的字符串转成字节流
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// 使用Promise方式，完成分段摘要
async function doLoopMdPromise() {
  let mdAlgName = "SHA256"; // Digest algorithm name.
  let md = cryptoFramework.createMd(mdAlgName);
  console.info("[Promise]: Md algName is: " + md.algName);
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the message is of 43 bytes.
  let messageArr: number[] = [];
  let updateLength = 20; // For example, pass in 20 bytes in each update().

  for (let i = 0; i <= messageText.length; i++) {
    if ((i % updateLength == 0 || i == messageText.length) && messageArr.length != 0) {
      let message = new Uint8Array(messageArr);
      let messageBlob: cryptoFramework.DataBlob = { data: message };
      // Use await to process the update() in the for() loop.
      try {
        await md.update(messageBlob); // Use update() to process data by segment.
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`await update error, ${e.code}, ${e.message}`);
        return;
      }
      messageArr = [];
    }
    // Pad messageArr based on the segment length.
    if (i < messageText.length) {
      messageArr.push(messageText.charCodeAt(i));
    }
  }
  let PromiseMdDigest = md.digest();
  PromiseMdDigest.then(digestOutput => {
    let mdOutput = digestOutput;
    console.info("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("[Promise]: MD len: " + mdLen);
  }).catch((error: BusinessError) => {
    console.error("[Promise]: error: " + error.message);
  });
}
```

## 使用消息认证码操作

### 场景说明

消息认证码操作主要应用于身份认证的场景：

Mac(message authentication code)可以对消息进行完整性校验，通过使用双方共享的密钥，识别出信息伪装篡改等行为。

用户指定摘要算法（如SHA256）生成消息认证码Mac实例，输入对称密钥初始化Mac，并传入单段或多段需要摘要的信息，进行消息认证码计算，并获取消息认证码计算结果，在指定算法后可获取当前算法名与消息认证码计算长度（字节）。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

| 实例名          | 接口名                                                       | 描述                                                |
| --------------- | ------------------------------------------------------------ | --------------------------------------------------- |
| cryptoFramework | function createMac(algName : string) : Mac;                  | 指定摘要算法，生成消息认证码实例Mac                 |
| Mac             | init(key : SymKey, callback : AsyncCallback\<void>) : void; | 接收输入对称密钥，通过Callback的方式，异步初始化MAC |
| Mac             | init(key : SymKey) : Promise\<void>;                        | 接收输入对称密钥，通过Promise的方式，异步初始化MAC  |
| Mac             | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | 接受输入数据，通过Callback的方式，异步更新MAC       |
| Mac             | update(input : DataBlob) : Promise\<void>;                  | 接受输入数据，通过Promise的方式，异步更新MAC        |
| Mac             | doFinal(callback : AsyncCallback\<DataBlob>) : void;        | 通过Callback的方式，返回MAC计算结果                 |
| Mac             | doFinal() : Promise\<DataBlob>;                             | 通过Promise的方式，返回MAC计算结果                  |
| Mac             | getMacLength() : number;                                     | 获取MAC的长度（由指定的摘要算法决定）               |
| Mac             | readonly algName : string;                                   | 获取当前设置的摘要算法名                            |

### HMAC开发步骤

1. 设置算法，通过接口`createMac`生成消息认证码操作实例。
2. 接受输入对称密钥，通过接口`init`，初始化Mac。
3. 接受数据，通过接口`update`，更新Mac，此步骤可重复。
4. 通过接口`doFinal`，返回Mac计算结果。
5. 获取当前摘要算法名与Mac计算长度。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// 可理解的字符串转成字节流
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

// Generate an HMAC in promise mode.
function doHmacByPromise() {
  let macAlgName = "SHA256"; // Digest algorithm name.
  let message = "hmacTestMessgae"; // Data used to generate an HMAC.
  let mac = cryptoFramework.createMac(macAlgName);
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob: cryptoFramework.DataBlob = {
    // 128-bit key
    data: stringToUint8Array("12345678abcdefgh")
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // Convert the binary data into a key.
  let promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  })
    .then(() => {
      // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
      let promiseMacUpdate = mac.update({ data: stringToUint8Array(message) });
      return promiseMacUpdate;
    })
    .then(() => {
      let PromiseMacDoFinal = mac.doFinal();
      return PromiseMacDoFinal;
    })
    .then(output => {
      let macOutput = output;
      console.info("[Promise]: HMAC result: " + macOutput.data);
      let macLen = mac.getMacLength();
      console.info("[Promise]: MAC len: " + macLen);
    })
    .catch((error: BusinessError) => {
      console.error("[Promise]: error: " + error.message);
    });
}

// Generate an HMAC in callback mode.
function doHmacByCallback() {
  let macAlgName = "SHA256"; // Digest algorithm name.
  let message = "hmacTestMessgae"; // Data used to generate an HMAC.
  let mac = cryptoFramework.createMac(macAlgName);
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob: cryptoFramework.DataBlob = {
    // 128-bit key
    data: stringToUint8Array("12345678abcdefgh")
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // Convert the binary data into a key.
  symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    mac.init(symKey, (err1,) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      }
      // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
      mac.update({ data: stringToUint8Array(message) }, (err2,) => {
        if (err2) {
          console.error("[Callback]: err: " + err2.code);
        }
        mac.doFinal((err3, output) => {
          if (err3) {
            console.error("[Callback]: err: " + err3.code);
          } else {
            let macOutput = output;
            console.error("[Callback]: HMAC result: " + macOutput.data);
            let macLen = mac.getMacLength();
            console.error("[Callback]: MAC len: " + macLen);
          }
        });
      });
    });
  });
}
```

### 分段HMAC开发步骤

以HMAC更新MAC时多次调用update实现分段为例：

1. 设置算法，通过接口`createMac`生成消息认证码操作实例。
2. 接受输入对称密钥，通过接口`init`，初始化Mac。
3. 接受数据，多次通过接口`update`，以实现分段。
4. 通过接口`doFinal`，返回Mac计算结果。
5. 获取当前摘要算法名与Mac计算长度。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

function doLoopHmacPromise() {
  let macAlgName = "SHA256"; // Digest algorithm name.
  let mac = cryptoFramework.createMac(macAlgName);
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob: cryptoFramework.DataBlob = {
    // 128-bit key
    data: stringToUint8Array("12345678abcdefgh")
  }
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the message is of 43 bytes.
  let updateLength = 20; // For example, pass in 20 bytes in each update().
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // Convert the binary data into a key.
  let promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then((symKey: cryptoFramework.SymKey): Promise<void> => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  })
    .then(async () => {
      let messageArr: number[] = [];
      for (let i = 0; i <= messageText.length; i++) {
        if ((i % updateLength == 0 || i == messageText.length) && messageArr.length != 0) {
          let message = new Uint8Array(messageArr);
          let messageBlob: cryptoFramework.DataBlob = { data: message };
          // Use await to process the update() in the for() loop.
          try {
            await mac.update(messageBlob); // Invoke update() multiple times.
          } catch (error) {
            let e: BusinessError = error as BusinessError;
            console.error(`await update error, ${e.code}, ${e.message}`);
            return;
          }
          messageArr = [];
        }
        // Pad messageArr based on the segment length.
        if (i < messageText.length) {
          messageArr.push(messageText.charCodeAt(i));
        }
      }
      return;
    })
    .then(() => {
      let PromiseMacDoFinal = mac.doFinal();
      return PromiseMacDoFinal;
    })
    .then(output => {
      let macOutput = output;
      console.log("[Promise]: HMAC result: " + macOutput.data);
      let macLen = mac.getMacLength();
      console.log("[Promise]: MAC len: " + macLen);
    })
    .catch((error: BusinessError) => {
      console.error("[Promise]: error: " + error.message);
    });
}
```

## 使用随机数操作

### 场景说明

使用随机数操作的主要场景为：

- 用户生成随机数Random实例，输入随机数生成的长度（字节），生成指定长度（范围为1~INT_MAX）的安全随机数。
- 用户使用生成的随机数作为参数，进行种子设置。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

| 实例名          | 接口名                                                       | 描述                                       |
| --------------- | ------------------------------------------------------------ | ------------------------------------------ |
| cryptoFramework | function createRandom() : Random;                            | 生成随机数Random实例                       |
| Random          | generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void; | 接受输入长度，通过Callback，异步生成随机数 |
| Random          | generateRandom(len : number) : Promise\<DataBlob>;           | 接受输入长度，通过Promise，异步生成随机数  |
| Random          | generateRandomSync(len: number): DataBlob;                   | 接受输入长度，同步生成随机数               |
| Random          | setSeed(seed : DataBlob) : void;                             | 接受输入Blob，设置种子                     |

### 开发步骤

1. 通过接口`createRandom`生成随机数操作实例。
2. 接受输入长度，通过接口`generateRandom`，生成指定长度的随机数。
3. 接受DataBlob数据，通过接口`setSeed`，为随机数生成池设置种子。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Generate a random number in promise mode.
function doRandByPromise() {
  let rand = cryptoFramework.createRandom();
  let len = 4; // Generate a 4-byte random number.
  let promiseGenerateRand = rand.generateRandom(len);
  promiseGenerateRand.then(randData => {
    console.info("[Promise]: rand result: " + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`setSeed failed, ${e.code}, ${e.message}`);
    }
  }).catch((error: BusinessError) => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate a random number in callback mode.
function doRandByCallback() {
  let rand = cryptoFramework.createRandom();
  let len = 4; // Generate a 4-byte random number.
  rand.generateRandom(len, (err, randData) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    } else {
      console.info("[Callback]: generate random result: " + randData.data);
      try {
        rand.setSeed(randData);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`setSeed failed, ${e.code}, ${e.message}`);
      }
    }
  });
}

// Generate a random number synchronously.
function doRandBySync() {
  let rand = cryptoFramework.createRandom();
  let len = 24; // Generate a 24-byte random number.
  try {
    let randData = rand.generateRandomSync(len);
    if (randData != null) {
      console.info("[Sync]: rand result: " + randData.data);
    } else {
      console.error("[Sync]: get rand result fail!");
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`do rand failed, ${e.code}, ${e.message}`);
  }
}
```

## 使用密钥派生算法操作

### 场景说明

使用密钥派生算法时，典型的场景有：

用户输入指定的密码，通过密钥派生函数，生成指定长度的密钥。

> **说明：**
>
> 从API version 11开始，支持密钥派生函数操作。

### 接口及参数说明

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|creatKdf(algName : string) : Kdf|根据String设置的参数创建Kdf对象|
|Kdf|generateSecret(params: KdfSpec, callback: AsyncCallback\<DataBlob>): void |使用callback方式进行密钥派生|
|Kdf|generateSecret(params: KdfSpec): Promise<DataBlob>;|使用Promise方式进行密钥派生|

### 开发步骤

1. 构造密钥派生函数的参数对象（如PKBDF2Spec）。
2. 通过接口`creatKdf`生成密钥派生函数实例。
3. 接受密钥派生函数参数，进行密钥派生操作。

```ts
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

function kdfPromise() {
  let spec: cryptoFramework.PBKDF2Spec = {
    algName: 'PBKDF2',
    password: '123456',
    salt: new Uint8Array(16),
    iterations: 10000,
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
  let kdfPromise = kdf.generateSecret(spec);
  kdfPromise.then((secret) => {
    console.info("key derivation output is " + secret.data);
  }).catch((error: BusinessError) => {
    console.error("key derivation error.");
  });
}

function kdfCallback() {
  let spec: cryptoFramework.PBKDF2Spec = {
    algName: 'PBKDF2',
    password: '123456',
    salt: new Uint8Array(16),
    iterations: 10000,
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
  kdf.generateSecret(spec, (err, secret) => {
    if (err) {
      console.error("key derivation error.");
      return;
    }
    console.info("key derivation output is " + secret.data);
  });
}
```

## 相关实例

针对加解密算法开发，有以下相关实例可供参考：

- [支付（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/PaySecurely)

- [通用密钥库系统（cryptoFramework）（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/CryptoFramework)

- [加解密（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/Cipher)

- [字符串加解密（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Security/StringCipherArkTS)
