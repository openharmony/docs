# 加解密算法库框架开发指导

> **说明**
>
> 本开发指导基于API version 9，OH SDK版本3.2.7.3，适用于JS语言开发

## 使用密钥对象生成与转换操作

**场景说明**

使用密钥生成操作中，典型的场景有：

1. 随机生成算法库密钥对象。该对象可用于后续的加解密等操作。
2. 根据指定数据生成算法库密钥对象（也就是将外部或存储的二进制数据转换为算法库的密钥对象）。该对象可用于后续的加解密等操作。
3. 获取算法库密钥对象的二进制数据，用于存储或传输。
> **说明**：密钥对象Key包括对称密钥SymKey和非对称密钥（公钥PubKey和私钥PriKey），其中公钥和私钥组成密钥对KeyPair。密钥之间的具体关系可参考[接口声明](../reference/apis/js-apis-cryptoFramework.md)。


**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

以上场景涉及的常用接口如下表所示：

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createAsyKeyGenerator(algName : string) : AsyKeyGenerator|根据algName设置的非对称密钥规格，创建非对称密钥生成器对象|
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

**开发步骤**

示例1：随机生成非对称密钥KeyPair，并获得二进制数据（场景1、3）

1. 创建非对称密钥生成器；
2. 通过非对称密钥生成器随机生成非对称密钥；
3. 获取密钥对象的二进制数据；

以使用Promise方式随机生成RSA密钥（1024位，素数个数为2）为例：

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateAsyKey() {
  // 创建非对称密钥生成器
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // 通过非对称密钥生成器，随机生成非对称密钥
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
    globalKeyPair = keyPair;
    let pubKey = globalKeyPair.pubKey;
    let priKey = globalKeyPair.priKey;
    // 获取非对称密钥的二进制数据
    pkBlob = pubKey.getEncoded();
    skBlob = priKey.getEncoded();
    AlertDialog.show({ message : "pk bin data" + pkBlob.data} );
    AlertDialog.show({ message : "sk bin data" + skBlob.data} );
  })
}
```

示例2：随机生成对称密钥SymKey，并获得二进制数据（场景1、3）

1. 创建对称密钥生成器；
2. 通过对称密钥生成器随机生成对称密钥；
3. 获取算法库密钥对象的二进制数据；

以使用Promise方式随机生成AES密钥（256位）为例：

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

// 字节流以16进制输出
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

function testGenerateAesKey() {
  // 创建对称密钥生成器
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  // 通过密钥生成器随机生成对称密钥
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then( key => {
    // 获取对称密钥的二进制数据，输出长度为256bit的字节流
    let encodedKey = key.getEncoded();
    console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
  })
}
```

示例3：根据指定的RSA非对称密钥二进制数据，生成KeyPair对象（场景2）

1. 获取RSA公钥或私钥二进制数据，公钥需满足ASN.1语法、X.509规范、DER编码格式，私钥需满足ASN.1语法、PKCS#8规范、DER编码格式。
2. 创建AsyKeyGenerator对象，调用convertKey方法，传入公钥二进制和私钥二进制（二者非必选项，可只传入其中一个），转换为KeyPair对象。

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

function convertAsyKey() {
  let rsaGenerator = cfm.createAsyKeyGenerator("RSA1024");
  let pkval = new Uint8Array([48,129,159,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,141,0,48,129,137,2,129,129,0,174,203,113,83,113,3,143,213,194,79,91,9,51,142,87,45,97,65,136,24,166,35,5,179,42,47,212,79,111,74,134,120,73,67,21,19,235,80,46,152,209,133,232,87,192,140,18,206,27,106,106,169,106,46,135,111,118,32,129,27,89,255,183,116,247,38,12,7,238,77,151,167,6,102,153,126,66,28,253,253,216,64,20,138,117,72,15,216,178,37,208,179,63,204,39,94,244,170,48,190,21,11,73,169,156,104,193,3,17,100,28,60,50,92,235,218,57,73,119,19,101,164,192,161,197,106,105,73,2,3,1,0,1]);
  let pkBlob = {data : pkval};
  rsaGenerator.convertKey(pkBlob, null, function(err, keyPair) {
    if (keyPair == null) {
      AlertDialog.show({message : "Convert keypair fail"});
    }
    AlertDialog.show({message : "Convert KeyPair success"});
  })
}
```

**说明**

 当前convertKey操作，公钥只支持转换满足X.509规范的DER格式，私钥只支持PKCS#8规范的DER格式；

示例4：根据指定的ECC非对称密钥二进制数据，生成KeyPair对象（场景2、3）

1. 获取ECC二进制密钥数据，封装成DataBlob对象。
2. 调用convertKey方法，传入公钥二进制和私钥二进制（二者非必选项，可只传入其中一个），转换为KeyPair对象。

```javascript
function convertEccAsyKey() {
    let pubKeyArray = new Uint8Array([4,196,55,233,100,227,224,38,38,5,128,81,53,112,129,7,59,189,116,105,182,87,190,85,31,248,172,116,213,7,206,85,190,65,169,193,138,173,232,187,74,54,78,251,29,131,192,223,251,227,170,138,80,7,98,193,216,168,235,114,255,188,70,134,104]);
    let priKeyArray = new Uint8Array([255,70,89,220,189,19,41,157,175,173,83,60,74,216,195,96,24,181,231,23,112,247,150,126,15,155,24,79,33,97,31,225]);
    let pubKeyBlob = { data: pubKeyArray };
    let priKeyBlob = { data: priKeyArray };
    let generator = cryptoFrameWork.createAsyKeyGenerator("ECC256");
    generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
        if (error) {
            AlertDialog.show({message : "Convert keypair fail"});
        }
        AlertDialog.show({message : "Convert KeyPair success"});
    })
}
```

示例5：根据指定的对称密钥二进制数据，生成SymKey对象（场景2、3）

1. 创建对称密钥生成器；
2. 通过对称密钥生成器，根据指定的对称密钥二进制数据，生成SymKey对象；
3. 获取算法库密钥对象的二进制数据；

以使用callback方式生成3DES密钥（3DES密钥只能为192位）为例：

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

// 字节流以16进制输出
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}

function testConvertAesKey() {
  // 生成对称密钥生成器
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  // 根据用户指定的数据，生成对称密钥
  let keyMaterialBlob = genKeyMaterialBlob();
  try {
    symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
      if (error) {    // 业务逻辑执行错误通过callback的第一个参数返回错误信息
        console.error(`convertKey error, ${error.code}, ${error.message}`);
        return;
      }
      console.info(`key algName: ${key.algName}`);
      console.info(`key format: ${key.format}`);
      let encodedKey = key.getEncoded();    // 获取对称密钥的二进制数据，输出长度为192bit的字节流
      console.info('key getEncoded hex: ' + uint8ArrayToShowStr(encodedKey.data));
    })
  } catch (error) {    // 参数检查的错误以同步的方式立即抛出异常
    console.error(`convertKey failed, ${error.code}, ${error.message}`);
    return;
  }
}
```

## 使用加解密操作

**场景说明**

在数据存储或传输场景中，可以使用加解密操作用于保证数据的机密性，防止敏感数据泄露。使用加解密操作中，典型的场景有：
1. 使用对称密钥的加解密操作
2. 使用非对称密钥的加解密操作

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

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

**开发步骤**

示例1：使用对称密钥的加解密操作

1. 创建对称密钥生成器。
2. 通过密钥生成器生成对称密钥。
3. 创建加解密生成器。
4. 通过加解密生成器加密或解密数据。

以AES GCM以Promise方式加解密为例：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;

function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0 , 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob = {data : dataIv};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob = {data : dataAad};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob = {data : dataTag};
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algoName : "GcmParamsSpec"};
  return gcmParamsSpec;
}

// 可理解的字符串转成字节流
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 字节流转成可理解的字符串
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// 字节流以16进制输出
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}


// AES GCM模式示例，自动生成密钥（promise写法）
function testAesGcm() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve('testAesGcm');
    }, 10)
  }).then(() => {
    // 生成对称密钥生成器
    let symAlgoName = 'AES128';
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
    if (symKeyGenerator == null) {
      console.error('createSymKeyGenerator failed');
      return;
    }
    console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);
    // 通过密钥生成器随机生成128位长度的对称密钥
    let promiseSymKey = symKeyGenerator.generateSymKey();
    // 构造参数
    globalGcmParams = genGcmParamsSpec();

    // 生成加解密生成器
    let cipherAlgoName = 'AES128|GCM|PKCS7';
    try {
      globalCipher = cryptoFramework.createCipher(cipherAlgoName);
      console.info(`cipher algName: ${globalCipher.algName}`);
    } catch (error) {
      console.error(`createCipher failed, ${error.code}, ${error.message}`);
      return;
    }
    return promiseSymKey;
  }).then(key => {
      let encodedKey = key.getEncoded();
      console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
      globalKey = key;
      return key;
  }).then(key => {
      // 初始化加解密操作环境:开始加密
      let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
      let promiseInit = globalCipher.init(mode, key, globalGcmParams);    // init
      return promiseInit;
  }).then(() => {
      let plainText = {data : stringToUint8Array('this is test!')};
      let promiseUpdate = globalCipher.update(plainText);   // update
      return promiseUpdate;
  }).then(updateOutput => {
      globalCipherText = updateOutput;
      let promiseFinal = globalCipher.doFinal(null);    // doFinal
      return promiseFinal;
  }).then(authTag => {
      // 获取加密后的认证信息
      globalGcmParams.authTag = authTag;
      return;
  }).then(() => {
      // 初始化加解密操作环境:开始解密
      let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
      let promiseInit = globalCipher.init(mode, globalKey, globalGcmParams);    // init
      return promiseInit;
  }).then(() => {
      let promiseUpdate = globalCipher.update(globalCipherText);    // update
      return promiseUpdate;
  }).then(updateOutput => {
      console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
      let promiseFinal = globalCipher.doFinal(null);    // doFinal
      return promiseFinal;
  }).then(finalOutput => {
      if (finalOutput == null) {
          console.info('GCM finalOutput is null');
      }
  }).catch(error => {
      console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

以3DES ECB以callback方式加解密（采用已有数据生成密钥）为例：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;

// 可理解的字符串转成字节流
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 字节流转成可理解的字符串
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// 字节流以16进制输出
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}

// 3DES ECB模式示例，采用已有数据生成密钥（callback写法）
function test3DesEcb() {
  // 生成对称密钥生成器
  let symAlgoName = '3DES192';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
  if (symKeyGenerator == null) {
    console.error('createSymKeyGenerator failed');
    return;
  }
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);

  // 生成加解密生成器
  let cipherAlgoName = '3DES192|ECB|PKCS7';
  try {
    globalCipher = cryptoFramework.createCipher(cipherAlgoName);
    console.info(`cipher algName: ${globalCipher.algName}`);
  } catch (error) {
    console.error(`createCipher failed, ${error.code}, ${error.message}`);
    return;
  }

  // 根据指定的数据，生成对称密钥
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
      console.info('key getEncoded hex: ' + uint8ArrayToShowStr(encodedKey.data));
      globalKey = key;

      // 初始化加解密操作环境:开始加密
      let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
      // init
      globalCipher.init(mode, key, null, (err, ) => {
        let plainText = {data : stringToUint8Array('this is test!')};
        // update
        globalCipher.update(plainText, (err, updateOutput) => {
          globalCipherText = updateOutput;
          //doFinal
          globalCipher.doFinal(null, (err, finalOutput) => {
            if (error) {
              console.error(`doFinal error, ${error.code}, ${error.message}`);
              return;
            }
            if (finalOutput != null) {
              globalCipherText = Array.from(globalCipherText.data);
              finalOutput = Array.from(finalOutput.data);
              globalCipherText = globalCipherText.concat(finalOutput);
              globalCipherText = new Uint8Array(globalCipherText);
              globalCipherText = {data : globalCipherText};
            }
            // 初始化加解密操作环境:开始解密
            let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
            // init
            globalCipher.init(mode, globalKey, null, (err, ) => {
              // update
              globalCipher.update(globalCipherText, (err, updateOutput) => {
                console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
                // doFinal
                globalCipher.doFinal(null, (error, finalOutput) => {
                  if (finalOutput != null) {
                    console.info("decrypt plainText:" + uint8ArrayToString(finalOutput.data));
                  }
                })
              })
            })
          })
        })
      })
    })
  } catch (error) {
    console.error(`convertKey failed, ${error.code}, ${error.message}`);
    return;
  }
}
```

示例2：使用非对称密钥的加解密操作

1. 生成RSA密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成RSA非对称密钥。
2. 生成Cipher对象。通过createCipher接口创建Cipher对象，执行初始化操作，设置密钥及加解密模式。
3. 执行加解密操作。通过调用Cipher对象提供的doFinal接口，执行加密操作生成密文或执行解密操作生成明文。

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let plan = "This is cipher test.";

function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  var tmpArray = new Uint8Array(arr);
  return tmpArray;
}

function encryptMessageProMise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(rsaKeyPair => {
    let pubKey = rsaKeyPair.pubKey;
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
  }).then(() => {
    let input = { data : stringToUint8Array(plan) };
    return cipher.doFinal(input);
  }).then(dataBlob => {
    console.info("EncryptOutPut is " + dataBlob.data);
  });
}

function encryptMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    let pubKey = keyPair.pubKey;
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, function (err, data) {
      let input = {data : stringToUint8Array(plan) };
      cipher.doFinal(input, function (err, data) {
        console.info("EncryptOutPut is " + data.data);
      })
    })
  })
}
```

**说明**

1. 使用RSA加解密时，Cipher对象不可重复调用init方法初始化，在创建了一个加密Cipher对象后，如果要进行解密，则需要重新创建另一个Cipher对象执行解密操作。
2. RSA加密有长度限制，允许加密明文的最大长度见[加解密算法库框架概述](cryptoFramework-overview.md)中的基本概念章节。
3. RSA解密每次允许解密的密文长度为，RSA密钥的位数/8。

## 使用签名验签操作

**场景说明**

当需要判断接收的数据是否被篡改且是否为指定对象发送的数据时，可以使用签名验签操作。使用签名验签操作中，典型的场景有：
1. 使用RSA签名验签操作
2. 使用ECC签名验签操作

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createSign(algName : string) : Sign|根据String设置的参数创建Sign对象|
|Sign|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|使用callback方式设置密钥并初始化Sign对象|
|Sign|init(priKey : PriKey) : Promise\<void>|使用Promise方式设置密钥并初始化Sign对象|
|Sign|update(data : DataBlob, callback : AsyncCallback\<void>) : void|使用callback方式添加签名数据|
|Sign|update(data : DataBlob) : Promise\<void>|用Promise方式添加签名数据|
|Sign|sign(data : DataBlob, callback : AsyncCallback<DataBlob>) : void|使用callback方式签名所有数据|
|Sign|sign(data : DataBlob) : Promise<DataBlob>|使用Promise方式签名所有数据|
|cryptoFramework|function createVerify(algName : string) : Verify|根据String设置的参数创建Verify对象|
|Verify|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|使用callback方式设置密钥并初始化Verify对象|
|Verify|init(priKey : PriKey) : Promise\<void>|使用Promise方式设置密钥并初始化Verify对象|
|Verify|update(data : DataBlob, callback : AsyncCallback\<void>) : void|使用callback方式添加验签数据|
|Verify|update(data : DataBlob) : Promise\<void>|用Promise方式添加验签数据|
|Verify|verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback<boolean>) : void|使用callback方式验签所有数据|
|Verify|verify(data : DataBlob, signatureData : DataBlob) : Promise<boolean>|使用Promise方式验签所有数据|

**开发步骤**

示例1：使用RSA签名验签操作
1. 生成RSA密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成RSA非对称密钥。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥。
3. 执行签名操作。通过Sign类提供的update接口，添加签名数据，并调用sign接口生成数据的签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥。
5. 执行验签操作。通过Verify类提供的update接口，添加签名数据，并调用verify接口传入签名进行验签。
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
	var arr = [];
	for (var i = 0, j = str.length; i < j; ++i) {
		arr.push(str.charCodeAt(i));
	}
	var tmpArray = new Uint8Array(arr);
	return tmpArray;
}

let globalKeyPair;
let SignMessageBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1 = { data : stringToUint8Array(plan1) };
let input2 = { data : stringToUint8Array(plan2) };

function signMessagePromise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    SignMessageBlob = dataBlob;
    console.info("sign output is " + SignMessageBlob.data);
  });
}

function verifyMessagePromise() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
  verifyInitPromise.then(() => {
    return verifyer.update(input1);
  }).then(() => {
    return verifyer.verify(input2, SignMessageBlob);
  }).then(res => {
    console.log("Verify result is " + res);
  });
}

function signMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, function (err, data) {
      signer.update(input1, function (err, data) {
        signer.sign(input2, function (err, data) {
          SignMessageBlob = data;
          console.info("sign output is " + SignMessageBlob.data);
        });
      });
    });
  });
}

function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  verifyer.init(globalKeyPair.pubKey, function (err, data) {
    verifyer.update(input1, function(err, data) {
      verifyer.verify(input2, SignMessageBlob, function(err, data) {
        console.info("verify result is " + data);
      });
    });
  })
}
```

示例2：使用ECDSA操作
1. 生成ECC密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成ECC非对称密钥。
2. 生成Sign对象。通过createSign接口创建Sign对象，执行初始化操作并设置签名私钥。
3. 执行签名操作。通过Sign类提供的update接口，添加签名数据，并调用doFinal接口生成数据的签名。
4. 生成Verify对象。通过createVerify接口创建Verify对象，执行初始化操作并设置验签公钥。
5. 执行验签操作。通过Verify类提供的update接口，添加签名数据，并调用doFinal接口传入签名进行验签。

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
	var arr = [];
	for (var i = 0, j = str.length; i < j; ++i) {
		arr.push(str.charCodeAt(i));
	}
	var tmpArray = new Uint8Array(arr);
	return tmpArray;
}

let globalKeyPair;
let SignMessageBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1 = { data : stringToUint8Array(plan1) };
let input2 = { data : stringToUint8Array(plan2) };

function signMessagePromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    SignMessageBlob = dataBlob;
    console.info("sign output is " + SignMessageBlob.data);
  });
}

function verifyMessagePromise() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
  verifyInitPromise.then(() => {
    return verifyer.update(input1);
  }).then(() => {
    return verifyer.verify(input2, SignMessageBlob);
  }).then(res => {
    console.log("Verify result is " + res);
  });
}

function signMessageCallback() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  eccGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, function (err, data) {
      signer.update(input1, function (err, data) {
        signer.sign(input2, function (err, data) {
          SignMessageBlob = data;
          console.info("sign output is " + SignMessageBlob.data);
        });
      });
    });
  });
}

function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  verifyer.init(globalKeyPair.pubKey, function (err, data) {
    verifyer.update(input1, function(err, data) {
      verifyer.verify(input2, SignMessageBlob, function(err, data) {
        console.info("verify result is " + data);
      });
    });
  })
}
```

## 使用摘要操作

**场景说明**

用户指定摘要算法（如SHA256）生成Md实例，并输入单段或多段需要摘要的信息，进行摘要计算更新，并返回消息摘要计算结果，在指定算法后可获取当前算法名与摘要计算长度（字节）

使用摘要操作的主要场景为：

用户指定摘要算法（如SHA256）生成Md实例，并输入单段或多段需要摘要的信息，进行摘要计算更新，并返回消息摘要计算结果，在指定算法后可获取当前算法名与摘要计算长度（字节）

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

| 实例名          | 接口名                                                       | 描述                                               |
| --------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| cryptoFramework | function createMd(algName : string) : Md;                    | 指定摘要算法，生成摘要操作实例Md                   |
| Md              | update(input : DataBlob, callback : AsyncCallback\<void\>) : void; | 接受用户输入数据，通过Callback的方式，异步更新摘要 |
| Md              | update(input : DataBlob) : Promise\<void\>;                  | 接受用户输入数据，通过Promise的方式，异步更新摘要  |
| Md              | digest(callback : AsyncCallback\<DataBlob\>) : void;         | 通过Callback的方式，返回结果                       |
| Md              | digest() : Promise\<DataBlob\>;                              | 通过Promise的方式，返回结果                        |
| Md              | getMdLength() : number;                                      | 获取摘要的长度（由指定的摘要算法决定）             |
| Md              | readonly algName : string;                                   | 获取当前设置的摘要算法名                           |

**开发步骤**

1. 设置算法，通过接口`createMd`生成摘要操作实例
2. 接受用户数据，通过接口`update`，更新摘要，此步骤可重复
3. 通过接口`digest`，返回摘要计算结果
4. 获取当前摘要算法名与摘要计算长度

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// turn string into uint8Arr
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
      arr.push(str.charCodeAt(i));
  }
  var tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}

// generate dataBlob with given length
function GenDataBlob(dataBlobLen) {
  var dataBlob;
  if (dataBlobLen == 12) {
      dataBlob = {data: stringToUint8Array("my test data")};
  } else {
      console.error("GenDataBlob: dataBlobLen is invalid");
      dataBlob = {data: stringToUint8Array("my test data")};
  }
  return dataBlob;
}

// md with promise async
function doMdByPromise(algName) {
  var md;
  try {
    md = cryptoFramework.createMd(algName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  console.error("[Promise]: Md algName is: " + md.algName);
  var promiseMdUpdate = md.update(GenDataBlob(12));
  promiseMdUpdate.then(() => {
    var PromiseMdDigest = md.digest();
    return PromiseMdDigest;
  }).then(mdOutput => {
    console.error("[Promise]: MD result: " + mdOutput.data);
    var mdLen = md.getMdLength();
    console.error("[Promise]: MD len: " + mdLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// md with callback async
function doMdByCallback(algName) {
  var md;
  try {
    md = cryptoFramework.createMd(algName);
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.error("[Callback]: Md algName is: " + md.algName);
  md.update(GenDataBlob(12), (err,) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    md.digest((err1, mdOutput) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      } else {
        console.error("[Callback]: MD result: " + mdOutput.data);
        var mdLen = md.getMdLength();
        console.error("[Callback]: MD len: " + mdLen);
      }
    });
  });
}
```

## 使用密钥协商操作

**场景说明**

使用密钥协商操作中，典型的场景有：

通信双方可以在一个公开的信道上通过相互传送一些消息，共同建立一个安全的共享秘密密钥。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

|实例名|接口名|描述|
|---|---|---|
|cryptoFramework|createKeyAgreement(algName : string) : KeyAgreement|根据String设置的参数创建KeyAgreement对象|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void|使用callback方式进行密钥协商|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>|使用Promise方式进行密钥协商|

**开发步骤**

1. 生成ECC密钥。通过createAsyKeyGenerator接口创建AsyKeyGenerator对象，并生成ECC非对称密钥。
2. 基于ECC密钥的私钥及公钥执行ECDH操作。

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair;

function ecdhPromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
    globalKeyPair = keyPair;
    return eccKeyAgreement.generateSecret(keyPair.priKey, keyPair.pubKey);
  }).then((secret) => {
    console.info("ecdh output is " + secret.data);
  }).catch((error) => {
    console.error("ecdh error.");
  });
}

function ecdhCallback() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    eccKeyAgreement.generateSecret(keyPair.priKey, keyPair.pubKey, function (err, secret) {
      if (err) {
        console.error("ecdh error.");
        return;
      }
      console.info("ecdh output is " + secret.data);
    });
  });
}
```

## 使用消息认证码操作

**场景说明**

消息认证码操作主要应用于身份认证的场景：

Mac(message authentication code)可以对消息进行完整性校验，通过使用双方共享的密钥，识别出信息伪装篡改等行为

用户指定摘要算法（如SHA256）生成消息认证码Mac实例，输入对称密钥初始化Mac，并传入单段或多段需要摘要的信息，进行消息认证码计算，并获取消息认证码计算结果，在指定算法后可获取当前算法名与消息认证码计算长度（字节）。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

| 实例名          | 接口名                                                       | 描述                                                |
| --------------- | ------------------------------------------------------------ | --------------------------------------------------- |
| cryptoFramework | function createMd(algName : string) : Md;                    | 指定摘要算法，生成消息认证码实例Mac                 |
| Mac             | init(key : SymKey, callback : AsyncCallback\<void\>) : void; | 接收输入对称密钥，通过Callback的方式，异步初始化MAC |
| Mac             | init(key : SymKey) : Promise\<void\>;                        | 接收输入对称密钥，通过Promise的方式，异步初始化MAC  |
| Mac             | update(input : DataBlob, callback : AsyncCallback\<void\>) : void; | 接受输入数据，通过Callback的方式，异步更新MAC       |
| Mac             | update(input : DataBlob) : Promise\<void\>;                  | 接受输入数据，通过Promise的方式，异步更新MAC        |
| Mac             | doFinal(callback : AsyncCallback\<DataBlob\>) : void;        | 通过Callback的方式，返回MAC计算结果                 |
| Mac             | doFinal() : Promise\<DataBlob\>;                             | 通过Promise的方式，返回MAC计算结果                  |
| Mac             | getMacLength() : number;                                     | 获取MAC的长度（由指定的摘要算法决定）               |
| Mac             | readonly algName : string;                                   | 获取当前设置的摘要算法名                            |

**开发步骤**

1. 设置算法，通过接口`createMac`生成消息认证码操作实例
2. 接受输入对称密钥，通过接口`init`，初始化Mac
3. 接受数据，通过接口`update`，更新Mac，此步骤可重复
4. 通过接口`doFinal`，返回Mac计算结果
5. 获取当前摘要算法名与Mac计算长度

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// turn string into uint8Arr
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
      arr.push(str.charCodeAt(i));
  }
  var tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}

// generate blob with this func
function GenDataBlob(dataBlobLen) {
  var dataBlob;
  if (dataBlobLen == 12) {
      dataBlob = {data: stringToUint8Array("my test data")};
  } else {
      console.error("GenDataBlob: dataBlobLen is invalid");
      dataBlob = {data: stringToUint8Array("my test data")};
  }
  return dataBlob;
}

// process by promise
function doHmacByPromise(algName) {
  var mac;
  try {
    mac = cryptoFramework.createMac(algName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  console.error("[Promise]: Mac algName is: " + mac.algName);
  var KeyBlob = {
    data : stringToUint8Array("12345678abcdefgh")
  }
  var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  var promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    var promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  }).then(() => {
    var promiseMacUpdate = mac.update(GenDataBlob(12));
    return promiseMacUpdate;
  }).then(() => {
    var PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
  }).then(macOutput => {
    console.error("[Promise]: HMAC result: " + macOutput.data);
    var macLen = mac.getMacLength();
    console.error("[Promise]: MAC len: " + macLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// process by callback
function doHmacByCallback(algName) {
  var mac;
  try {
    mac = cryptoFramework.createMac(algName);
  } catch (error) {
    AlertDialog.show({message: "[Callback]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  var KeyBlob = {
    data : stringToUint8Array("12345678abcdefgh")
  }
  var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      }
      mac.update(GenDataBlob(12), (err2, ) => {
        if (err2) {
          console.error("[Callback]: err: " + err2.code);
        }
        mac.doFinal((err3, macOutput) => {
          if (err3) {
            console.error("[Callback]: err: " + err3.code);
          } else {
            console.error("[Callback]: HMAC result: " + macOutput.data);
            var macLen = mac.getMacLength();
            console.error("[Callback]: MAC len: " + macLen);
          }
        });
      });
    });
  });
}
```



## 使用随机数操作

**场景说明**

使用随机数操作的主要场景为：

- 用户生成随机数Random实例，输入随机数生成的长度（字节），生成指定长度的随机数。
- 用户使用生成的随机数作为参数，进行种子设置。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

| 实例名          | 接口名                                                       | 描述                                           |
| --------------- | ------------------------------------------------------------ | ---------------------------------------------- |
| cryptoFramework | function createRandom() : Random;                            | 生成随机数Random实例                           |
| Random          | generateRandom(len : number, callback: AsyncCallback\<DataBlob\>) : void; | 接受输入长度，通过Callback，异步生成随机数     |
| Random          | generateRandom(len : number) : Promise\<DataBlob\>;          | 接受输入长度，通过Promise，异步生成随机数      |
| Random          | setSeed(seed : DataBlob, callback : AsyncCallback\<void\>) : void; | 接受输入Blob，通过Callback的方式，异步设置种子 |
| Random          | setSeed(seed : DataBlob) : Promise\<void\>;                  | 接受输入Blob，通过Promise的方式，异步设置种子  |

**开发步骤**

1. 通过接口`createRandom`生成随机数操作实例
2. 接受输入长度，通过接口`generateRandom`，生成指定长度的随机数
3. 接受DataBlob数据，通过接口`setSeed`，为随机数生成池设置种子

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// process by promise
function doRandByPromise(len) {
  var rand;
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  var promiseGenerateRand = rand.generateRandom(len);
  promiseGenerateRand.then(randData => {
    console.error("[Promise]: rand result: " + randData.data);
    var promiseSetSeed = rand.setSeed(randData);
    return promiseSetSeed;
  }).then(() => {
    console.error("[Promise]: setSeed success");
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// process by callback
function doRandByCallback(len) {
  var rand;
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  rand.generateRandom(len, (err, randData) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    } else {
      console.error("[Callback]: generate random result: " + randData.data);
      rand.setSeed(randData, (err1,) => {
        if (err1) {
          console.error("[Callback] err: " + err1.code);
        } else {
          console.error("[Callback]: setSeed success");
        }
      });
    }
  });
}
```

## 使用证书操作

**场景说明**

使用证书操作中，典型的场景有：

1. 解析X509证书数据生成证书对象。
2. 获取证书信息，比如：证书版本、证书序列号等。
3. 获取证书对象的序列化数据。
4. 获取证书公钥。
5. 证书验签。
6. 校验证书有效期。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

以上场景涉及的常用接口如下表所示：

| 实例名          | 接口名                                                       | 描述                                         |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| cryptoFramework | createX509Cert(inStream : EncodingBlob, callback : AsyncCallback<X509Cert>) : void | 使用callback方式解析X509证书数据生成证书对象 |
| cryptoFramework | createX509Cert(inStream : EncodingBlob) : Promise<X509Cert>  | 使用promise方式解析X509证书数据生成证书对象  |
| X509Cert        | verify(key : PubKey, callback : AsyncCallback<void>) : void  | 使用callback方式进行证书验签                 |
| X509Cert        | verify(key : PubKey) : Promise<void>                         | 使用promise方式进行证书验签                  |
| X509Cert        | getEncoded(callback : AsyncCallback<EncodingBlob>) : void    | 使用callback方式获取证书序列化数据           |
| X509Cert        | getEncoded() : Promise<EncodingBlob>                         | 使用promise方式获取证书序列化数据            |
| X509Cert        | getPublicKey(callback : AsyncCallback<PubKey>) : void        | 使用callback方式获取证书公钥                 |
| X509Cert        | getPublicKey() : Promise<PubKey>                             | 使用Promise方式获取证书公钥                  |
| X509Cert        | checkValidityWithDate(date: string, callback : AsyncCallback<void>) : void | 使用callback方式校验证书有效期               |
| X509Cert        | checkValidityWithDate(date: string) : Promise<void>          | 使用Promise方式校验证书有效期                |
| X509Cert        | getVersion() : number                                        | 获取证书版本                                 |
| X509Cert        | getSerialNumber() : number                                   | 获取证书序列号                               |
| X509Cert        | getIssuerName() : DataBlob                                   | 获取证书颁发者名称                           |
| X509Cert        | getSubjectName() : DataBlob                                  | 获取证书主体名称                             |
| X509Cert        | getNotBeforeTime() : string                                  | 获取证书有效期起始时间                       |
| X509Cert        | getNotAfterTime() : string                                   | 获取证书有效期截至时间                       |
| X509Cert        | getSignature() : DataBlob                                    | 获取证书签名                                 |
| X509Cert        | getSignatureAlgName() : string                               | 获取证书签名算法名称                         |
| X509Cert        | getSignatureAlgOid() : string                                | 获取证书签名算法OID                          |
| X509Cert        | getSignatureAlgParams() : DataBlob                           | 获取证书签名算法参数                         |
| X509Cert        | getKeyUsage() : DataBlob                                     | 获取证书秘钥用途                             |
| X509Cert        | getExtKeyUsage() : DataArray                                 | 获取证书扩展秘钥用途                         |
| X509Cert        | getBasicConstraints() : number                               | 获取证书基本约束                             |
| X509Cert        | getSubjectAltNames() : DataArray                             | 获取证书主体可选名称                         |
| X509Cert        | getIssuerAltNames() : DataArray                              | 获取证书颁发者可选名称                       |

**开发步骤**

示例：解析X509证书数据生成证书对象，并调用对象方法（包含场景1-6）

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书数据，此处仅示例，业务需根据场景自行设置
let certData = "-----BEGIN CERTIFICATE-----\n"
+ "IBzTCCAXCgAwIBAgIGAXKnMKNyMAwGCCqBHM9VAYN1BQAwSTELMAkGA1UEBhMC\n"
+ "04xDjAMBgNVBAoTBUdNU1NMMRAwDgYDVQQLEwdQS0kvU00yMRgwFgYDVQQDEw9S\n"
+ "290Q0EgZm9yIFRlc3QwIhgPMjAxNTEyMzExNjAwMDBaGA8yMDM1MTIzMDE2MDAw\n"
+ "FowSTELMAkGA1UEBhMCQ04xDjAMBgNVBAoTBUdNU1NMMRAwDgYDVQQLEwdQS0kv\n"
+ "00yMRgwFgYDVQQDEw9Sb290Q0EgZm9yIFRlc3QwWTATBgcqhkjOPQIBBggqgRzP\n"
+ "QGCLQNCAATj+apYlL+ddWXZ7+mFZXZJGbcJFXUN+Fszz6humeyWZP4qEEr2N0+a\n"
+ "dwo/21ft232yo0jPLzdscKB261zSQXSoz4wPDAZBgNVHQ4EEgQQnGnsD7oaOcWv\n"
+ "CTrspwSBDAPBgNVHRMBAf8EBTADAQH/MA4GA1UdDwEB/wQEAwIAxjAMBggqgRzP\n"
+ "QGDdQUAA0kAMEYCIQCEnW5BlQh0vmsOLxSoXYc/7zs++wWyFc1tnBHENR4ElwIh\n"
+ "I1Lwu6in1ruflZhzseWulXwcITf3bm/Y5X1g1XFWQUH\n"
+ "-----END CERTIFICATE-----\n";

// string转Uint8Array
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// 证书示例
function certSample() {
    let encodingBlob = {
        // 将string类型证书数据转为Uint8Array
        data: stringToUint8Array(certData),
        // 证书格式：支持PEM和DER，此例中对应PEM
        encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
    };
    
    // 创建证书对象
	cryptoFramework.createX509Cert(encodingBlob, function (err, x509Cert) {
		if (err != null) {
			// 创建证书对象失败
			Console.log("createX509Cert failed, errCode: " + err.code + ", errMsg: " + err.message);
			return;
		}
		// 创建证书对象成功
		Console.log("createX509Cert success");

		// 获取证书版本
		let version = x509Cert.getVersion();
        
		// 获取证书对象的序列化数据
		x509Cert.getEncoded(function (err, data) {
			if (err != null) {
				// 获取序列化数据失败
				Console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
			} else {
				// 获取序列化数据成功
				Console.log("getEncoded success");
			}
		});
        
		// 获取证书公钥对象
		x509Cert.getPublicKey(function (err, pubKey) {
			if (err != null) {
				// 获取证书公钥失败
				Console.log("getPublicKey failed, errCode: " + err.code + ", errMsg: " + err.message);
			} else {
				// 获取证书公钥成功
				Console.log("getPublicKey success");
			}
		});
        
        // 业务需通过上级证书对象或本证书对象(自签名)的getPublicKey接口获取公钥对象，此处省略
        let pubKey = null;
        
        // 证书验签
		x509Cert.verify(pubKey, function (err, data) {
            if (err == null) {
                // 验签成功
                Console.log("verify success");
            } else {
                // 验签失败
                Console.log("verify failed, errCode: " + err.code + ", errMsg: " + err.message);
            }
		});
        
        // 时间字符串
        let date = "150527000001Z";
        
        // 校验证书有效期
		x509Cert.checkValidityWithDate(date, function (err, data) {
			if (err != null) {
                // 证书有效期校验失败
				Console.log("checkValidityWithDate failed, errCode: " + err.code + ", errMsg: " + err.message);
			} else {
                // 证书有效期校验成功
				Console.log("checkValidityWithDate success");
			}
		});
	});
}
```

## 使用证书吊销列表操作

**场景说明**

使用证书吊销列表操作中，典型的场景有：

1. 解析X509证书吊销列表数据生成吊销列表对象。
2. 获取证书吊销列表信息，比如：证书吊销列表版本、证书吊销列表类型等。
3. 获取证书吊销列表对象的序列化数据。
4. 检查证书是否被吊销。
5. 证书吊销列表验签。
6. 获取被吊销证书。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

以上场景涉及的常用接口如下表所示：

| 实例名          | 接口名                                                       | 描述                                                         |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| cryptoFramework | createX509Crl(inStream : EncodingBlob, callback : AsyncCallback<X509Crl>) : void | 使用callback方式解析X509证书吊销列表数据生成证书吊销列表对象 |
| cryptoFramework | createX509Crl(inStream : EncodingBlob) : Promise<X509Crl>    | 使用promise方式解析X509证书吊销列表数据生成证书吊销列表对象  |
| X509Crl         | isRevoked(cert : X509Cert, callback : AsyncCallback<boolean>) : void | 使用callback方式检查证书是否被吊销                           |
| X509Crl         | isRevoked(cert : X509Cert) : Promise<boolean>                | 使用promise方式检查证书是否被吊销                            |
| X509Crl         | getType() : string                                           | 获取证书吊销列表类型                                         |
| X509Crl         | getEncoded(callback : AsyncCallback<EncodingBlob>) : void    | 使用callback方式获取证书吊销列表序列化数据                   |
| X509Crl         | getEncoded() : Promise<EncodingBlob>                         | 使用promise方式获取证书吊销列表序列化数据                    |
| X509Crl         | verify(key : PubKey, callback : AsyncCallback<void>) : void  | 使用callback方式进行证书吊销列表验签                         |
| X509Crl         | verify(key : PubKey) : Promise<void>                         | 使用Promise方式进行证书吊销列表验签                          |
| X509Crl         | getVersion() : number                                        | 获取证书吊销列表版本                                         |
| X509Crl         | getIssuerName() : DataBlob                                   | 获取证书吊销列表颁发者名称                                   |
| X509Crl         | getLastUpdate() : string                                     | 获取证书吊销列表lastUpdate日期                               |
| X509Crl         | getNextUpdate() : string                                     | 获取证书吊销列表nextUpdate日期                               |
| X509Crl         | getRevokedCert(serialNumber : number, callback : AsyncCallback<X509CrlEntry>) : void | 使用callback方式通过序列号获取证书吊销列表中的被吊销证书     |
| X509Crl         | getRevokedCert(serialNumber : number) : Promise<X509CrlEntry> | 使用Promise方式通过序列号获取证书吊销列表中的被吊销证书      |
| X509Crl         | getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback<X509CrlEntry>) : void | 使用callback方式通过X509证书获取证书吊销列表中的被吊销证书   |
| X509Crl         | getRevokedCertWithCert(cert : X509Cert) : Promise<X509CrlEntry> | 使用Promise方式通过X509证书获取证书吊销列表中的被吊销证书    |
| X509Crl         | getRevokedCerts(callback : AsyncCallback<Array<X509CrlEntry>>) : void | 使用callback方式获取证书吊销列表的所有被吊销证书             |
| X509Crl         | getRevokedCerts() : Promise<Array<X509CrlEntry>>             | 使用Promise方式获取证书吊销列表的所有被吊销证书              |
| X509Crl         | getTbsInfo(callback : AsyncCallback<DataBlob>) : void        | 使用callback方式获取证书吊销列表的tbsCertList                |
| X509Crl         | getTbsInfo() : Promise<DataBlob>                             | 使用Promise方式获取证书吊销列表的tbsCertList                 |
| X509Crl         | getSignature() : DataBlob                                    | 获取证书吊销列表的签名                                       |
| X509Crl         | getSignatureAlgName() : string                               | 获取证书吊销列表的签名算法名称                               |
| X509Crl         | getSignatureAlgOid() : string                                | 获取证书吊销列表的签名算法OID                                |
| X509Crl         | getSignatureAlgParams() : DataBlob                           | 获取证书吊销列表的签名算法参数                               |

**开发步骤**

示例：解析X509证书吊销列表数据生成证书吊销列表对象，并调用对象方法（包含场景1-6）

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表数据，此处仅示例，业务需根据场景自行设置
let crlData = "-----BEGIN X509 CRL-----\n"
+ "MIIBijB0AgEBMA0GCSqGSIb3DQEBCwUAMBMxETAPBgNVBAMMCHJvb3QtY2ExFw0y\n"
+ "MDA2MTkxNjE1NDhaFw0yMDA3MTkxNjE1NDhaMBwwGgIJAMsozRATnap1Fw0yMDA2\n"
+ "MTkxNjEyMDdaoA8wDTALBgNVHRQEBAICEAIwDQYJKoZIhvcNAQELBQADggEBACPs\n"
+ "9gQB+djaXPHHRmAItebZpD3iJ/e36Dxr6aMVkn9FkI8OVpUI4RNcCrywyCZHQJte\n"
+ "995bbPjP7f1sZstOTZS0fDPgJ5SPAxkKOQB+SQnBFrlZSsxoUNU60gRqd2imR0Rn\n"
+ "1r09rP69F6E4yPc9biEld+llLGgoImP3zPOVDD6fbfcvVkjStY3bssVEQ/vjp4a3\n"
+ "/I12U7ZnSe3jaKqaQBoVJppkTFOIOq7IOxf5/IkMPmvRHDeC2IzDMzcUxym0dkny\n"
+ "EowHrjzo0bZVqpHMA2YgKZuwTpVLHk9GeBEK2hVkIoPVISkmiU4HFg0S6z68C5yd\n"
+ "DrAA7hErVgXhtURLbAI=\n"
+ "-----END X509 CRL-----\n";

// string转Uint8Array
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// 证书吊销列表示例
function crlSample() {
    let encodingBlob = {
        // 将string类型证书吊销列表数据转为Uint8Array
        data: stringToUint8Array(crlData),
        // 证书吊销列表格式：支持PEM和DER，此例中对应PEM
        encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
    };
    
    // 创建证书吊销列表对象
	cryptoFramework.createX509Crl(encodingBlob, function (err, x509Crl) {
		if (err != null) {
			// 创建证书吊销列表对象失败
			Console.log("createX509Crl failed, errCode: " + err.code + ", errMsg: " + err.message);
			return;
		}
		// 创建证书吊销列表对象成功
		Console.log("createX509Crl success");

		// 获取证书吊销列表版本
		let version = x509Crl.getVersion();
        
		// 获取证书吊销列表对象的序列化数据
		x509Crl.getEncoded(function (err, data) {
			if (err != null) {
				// 获取序列化数据失败
				Console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
			} else {
				// 获取序列化数据成功
				Console.log("getEncoded success");
			}
		});
        
		// 业务需通过cryptoFramework的createX509Cert生成X509Cert证书对象，此处省略
        let x509Cert = null;
        
        // 检查证书是否被吊销
		x509Crl.isRevoked(x509Cert, function (err, isRevoked) {
			if (err != null) {
				// 检查证书是否被吊销失败
				Console.log("isRevoked failed, errCode: " + err.code + ", errMsg: " + err.message);
			} else {
				// 检查证书是否被吊销成功
				Console.log("isRevoked success, isRevoked? " + isRevoked);
			}
		});
        
		// 业务需通过AsyKeyGenerator的generateKeyPair或convertKey接口获取PubKey对象，此处省略
        let pubKey = null;
        
        // 证书吊销列表验签
		x509Crl.verify(pubKey, function (err, data) {
            if (err == null) {
                // 验签成功
                Console.log("verify success");
            } else {
                // 验签失败
                Console.log("verify failed, errCode: " + err.code + ", errMsg: " + err.message);
            }
		});
        
        // 证书序列号，业务需自行设置
        let serialNumber = 1000;
        
        // 获取被吊销证书对象
		x509Crl.getRevokedCert(serialNumber, function (err, entry) {
			if (err != null) {
                // 获取被吊销证书对象失败
				Console.log("getRevokedCert failed, errCode: " + err.code + ", errMsg: " + err.message);
			} else {
                // 获取被吊销证书对象成功
				Console.log("getRevokedCert success");
			}
		});
	});
}
```

## 使用证书链校验器操作

**场景说明**

使用证书链校验器操作中，典型的场景有：

1. 证书链校验。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

以上场景涉及的常用接口如下表所示：

| 实例名             | 接口名                                                       | 描述                             |
| ------------------ | ------------------------------------------------------------ | -------------------------------- |
| cryptoFramework    | createCertChainValidator(algorithm :string) : CertChainValidator | 使用指定算法生成证书链校验器对象 |
| CertChainValidator | validate(certChain : CertChainData, callback : AsyncCallback<void>) : void | 使用callback方式校验证书链       |
| CertChainValidator | validate(certChain : CertChainData) : Promise<void>          | 使用promise方式校验证书链        |
| CertChainValidator | algorithm : string                                           | 证书链校验器算法名称             |

**开发步骤**

示例：创建证书链校验器对象，并对证书链数据进行校验（场景1）

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

// 一级证书数据，此处仅示例，业务需自行设置真实数据
let caCertData = "-----BEGIN CERTIFICATE-----\n"
+ "...\n"
+ "...\n"
+ "...\n"
+ "-----END CERTIFICATE-----\n";

// 二级证书数据，此处仅示例，业务需自行设置真实数据
let secondCaCertData = "-----BEGIN CERTIFICATE-----\n"
+ "...\n"
+ "...\n"
+ "...\n"
+ "-----END CERTIFICATE-----\n";

// string转Uint8Array
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// 证书链校验器示例：此示例中以校验二级证书链为例，业务需根据场景自行修改
function certChainValidatorSample() {
    // 证书链校验器算法，当前仅支持PKIX
    let algorithm = "PKIX";
    
    // 创建证书链校验器对象
    let validator = cryptoFramework.createCertChainValidator(algorithm);
    
    // 一级证书数据
    let uint8ArrayOfCaCertData = stringToUint8Array(caCertData);
    
    // 一级证书数据长度
    let uint8ArrayOfCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOfCaCertData.byteLength]).buffer);
    
    // 二级证书数据
    let uint8ArrayOf2ndCaCertData = stringToUint8Array(secondCaCertData);
    
    // 二级证书数据长度
    let uint8ArrayOf2ndCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOf2ndCaCertData.byteLength]).buffer);
    
    // 证书链二进制数据：二级证书数据长度+二级证书数据+一级证书数据长度+一级证书数据（L-V格式）
    let encodingData = new Uint8Array(uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
                                     uint8ArrayOfCaCertDataLen.length + uint8ArrayOfCaCertData.length);
    for (var i = 0; i < uint8ArrayOf2ndCaCertDataLen.length; i++) {
        encodingData[i] = uint8ArrayOf2ndCaCertDataLen[i];
    }
    for (var i = 0; i < uint8ArrayOf2ndCaCertData.length; i++) {
        encodingData[uint8ArrayOf2ndCaCertDataLen.length + i] = uint8ArrayOf2ndCaCertData[i];
    }
    for (var i = 0; i < uint8ArrayOfCaCertDataLen.length; i++) {
        encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length + i] = uint8ArrayOfCaCertDataLen[i];
    }
    for (var i = 0; i < uint8ArrayOfCaCertData.length; i++) {
        encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
                     uint8ArrayOfCaCertDataLen.length + i] = uint8ArrayOfCaCertData[i];
    }
    
    let certChainData = {
        // Uint8Array类型：L-V格式(证书数据长度-证书数据)
        data: encodingData,
        // 证书数量，此示例中为2
        count: 2,
        // 证书格式：支持PEM和DER，此例中对应PEM
        encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
    };
    
    // 校验证书链
    validator.validate(certChainData, function (err, data) {
        if (err != null) {
            // 证书链校验失败
            Console.log("validate failed, errCode: " + err.code + ", errMsg: " + err.message);
        } else {
            // 证书链校验成功
            Console.log("validate success");
        }
	});
}
```

## 使用被吊销证书操作

**场景说明**

使用被吊销证书操作中，典型的场景有：

1. 获取被吊销证书对象。
2. 获取被吊销证书信息，比如：序列号、证书颁发者、证书吊销日期。
3. 获取被吊销证书对象的序列化数据。

**接口及参数说明**

详细接口说明可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。

以上场景涉及的常用接口如下表所示：

| 实例名       | 接口名                                                      | 描述                                       |
| ------------ | ----------------------------------------------------------- | ------------------------------------------ |
| X509CrlEntry | getEncoded(callback : AsyncCallback<EncodingBlob>) : void;  | 使用callback方式获取被吊销证书的序列化数据 |
| X509CrlEntry | getEncoded() : Promise<EncodingBlob>;                       | 使用promise方式获取被吊销证书的序列化数据  |
| X509CrlEntry | getSerialNumber() : number;                                 | 获取被吊销证书的序列号                     |
| X509CrlEntry | getCertIssuer(callback : AsyncCallback<DataBlob>) : void;   | 使用callback方式获取被吊销证书颁发者       |
| X509CrlEntry | getCertIssuer() : Promise<DataBlob>;                        | 使用promise方式获取被吊销证书颁发者        |
| X509CrlEntry | getRevocationDate(callback : AsyncCallback<string>) : void; | 使用callback方式获取被吊销证书的吊销日期   |
| X509CrlEntry | getRevocationDate() : Promise<string>;                      | 使用promise方式获取被吊销证书的吊销日期    |

**开发步骤**

示例：获取被吊销证书对象，并调用对象方法（包含场景1-3）

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

// 被吊销证书示例
function crlEntrySample() {
    // 业务需自行通过cryptoFramework的createX509Crl接口创建X509Crl对象，此处省略
    let x509Crl = null;
    
    // 获取被吊销证书对象，业务需根据场景调用X509Crl的接口获取，此示例使用getRevokedCert获取
    let serialNumber = 1000;
    x509Crl.getRevokedCert(serialNumber, function (err, crlEntry) {
        if (err != null) {
            // 获取被吊销证书对象失败
            Console.log("getRevokedCert failed, errCode: " + err.code + ", errMsg: " + err.message);
            return;
        }
        // 获取被吊销证书对象成功
        Console.log("getRevokedCert success");
        
        // 获取被吊销证书的序列号
        let serialNumber = crlEntry.getSerialNumber();
        
        // 获取被吊销证书的吊销日期
        crlEntry.getRevocationDate(function (err, date) {
            if (err != null) {
                // 获取吊销日期失败
                Console.log("getRevocationDate failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // 获取吊销日期成功
                Console.log("getRevocationDate success, date is: " + date);
            }
        });
        
        // 获取被吊销证书对象的序列化数据
        crlEntry.getEncoded(function (err, data) {
            if (err != null) {
                // 获取序列化数据失败
                Console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // 获取序列化数据成功
                Console.log("getEncoded success");
            }
        });
    });
}
```

