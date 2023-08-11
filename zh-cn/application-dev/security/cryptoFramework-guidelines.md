# 加解密算法库框架开发指导

> **说明**
>
> 本开发指导基于API version 9，OH SDK版本3.2.7以上，适用于JS语言开发

## 使用密钥对象生成与转换操作

**场景说明**

使用密钥生成操作中，典型的场景有：

1. 随机生成算法库密钥对象。该对象可用于后续的加解密等操作。
2. 根据指定数据生成算法库密钥对象（也就是将外部或存储的二进制数据转换为算法库的密钥对象）。该对象可用于后续的加解密等操作。
3. 获取算法库密钥对象的二进制数据，用于存储或传输。
> **说明**：密钥对象Key包括对称密钥SymKey和非对称密钥（公钥PubKey和私钥PriKey），其中公钥和私钥组成密钥对KeyPair。密钥之间的具体关系可参考[API参考](../reference/apis/js-apis-cryptoFramework.md)。


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
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024");
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
import cryptoFramework from "@ohos.security.cryptoFramework"

function convertEccAsyKey() {
    let pubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,72,206,61,3,1,7,3,66,0,4,83,96,142,9,86,214,126,106,247,233,92,125,4,128,138,105,246,162,215,71,81,58,202,121,26,105,211,55,130,45,236,143,55,16,248,75,167,160,167,106,2,152,243,44,68,66,0,167,99,92,235,215,159,239,28,106,124,171,34,145,124,174,57,92]);
    let priKeyArray = new Uint8Array([48,49,2,1,1,4,32,115,56,137,35,207,0,60,191,90,61,136,105,210,16,27,4,171,57,10,61,123,40,189,28,34,207,236,22,45,223,10,189,160,10,6,8,42,134,72,206,61,3,1,7]);
    let pubKeyBlob = { data: pubKeyArray };
    let priKeyBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator("ECC256");
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
  let tagBlob = {data : dataTag};  // GCM的authTag在加密时从doFinal结果中获取，在解密时填入init函数的params参数中
  
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algName : "GcmParamsSpec"};
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

// 字节流以16进制输出
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// 字节流转成可理解的字符串
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
    let symAlgName = 'AES128';
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
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
    let cipherAlgName = 'AES128|GCM|PKCS7';
    try {
      globalCipher = cryptoFramework.createCipher(cipherAlgName);
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
      // GCM模式需要从doFinal的输出中取出加密后的认证信息并填入globalGcmParams，在解密时传入init()
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
      if (finalOutput == null) {  // 使用finalOutput.data前，先判断结果是否为null
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

// 字节流以16进制输出
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// 字节流转成可理解的字符串
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
  let symAlgName = '3DES192';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
  if (symKeyGenerator == null) {
    console.error('createSymKeyGenerator failed');
    return;
  }
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);

  // 生成加解密生成器
  let cipherAlgName = '3DES192|ECB|PKCS7';
  try {
    globalCipher = cryptoFramework.createCipher(cipherAlgName);
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
                  if (finalOutput != null) {  // 使用finalOutput.data前，先判断结果是否为null
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
以AES GCM以promise方式，分段update()实现加解密为例：

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;
var globalPlainText;

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
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algName : "GcmParamsSpec"};
  return gcmParamsSpec;
}

// 字节流以16进制输出
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// 字节流转成可理解的字符串
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// 算法库不限定update的次数和每次加解密的数据量，业务可根据自身内存情况对明文/密文进行多次分段。
function testAesMultiUpdate() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve('testAesMultiUpdate');
    }, 10)
  }).then(() => {
    // 生成对称密钥生成器
    let symAlgName = 'AES128';
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
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
    let cipherAlgName = 'AES128|GCM|PKCS7';
    try {
      globalCipher = cryptoFramework.createCipher(cipherAlgName);
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
  }).then(async () => {
    let plainText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee";   // 假设明文总共43字节
    let messageArr = [];
    let updateLength = 20;  // 假设每20字节分段update一次
    globalCipherText = [];
    
    for (let i = 0; i <= plainText.length; i++) {
      if ((i % updateLength == 0 || i == plainText.length) && messageArr.length != 0) {
        let message = new Uint8Array(messageArr);
        let messageBlob = { data : message };
        let updateOutput = await globalCipher.update(messageBlob);    // 分段update
        // 把update的结果拼接起来，得到密文（有些情况下还需拼接doFinal的结果，这取决于分组模式
        // 和填充模式，本例中GCM模式的doFinal结果只包含authTag而不含密文，所以不需要拼接）
        globalCipherText = globalCipherText.concat(Array.from(updateOutput.data));
        messageArr = [];
      }
      if (i < plainText.length) {
        messageArr.push(plainText.charCodeAt(i));
      }
    }
    return;
  }).then(() => {
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
  }).then(async () => {
    let updateLength = 20;
    let updateTimes = Math.ceil(globalCipherText.length / updateLength);  // 上取整
    globalPlainText = "";
    for (let i = 0; i < updateTimes; i++) {
      let messageArr = globalCipherText.slice(i * updateLength, (i + 1) * updateLength);
      let message = new Uint8Array(messageArr);
      let messageBlob = { data : message };
      let updateOutput = await globalCipher.update(messageBlob);    // 分段update
      globalPlainText += uint8ArrayToString(updateOutput.data);     // 恢复出原始明文
    }
    return;
  }).then(() => {
    let promiseFinal = globalCipher.doFinal(null);      // doFinal
    return promiseFinal;
  }).then(finalOutput => {
    if (finalOutput == null) {
      console.info('GCM finalOutput is null');
    }
    console.info(`decrypt output: ${globalPlainText}`);
  }).catch(error => {
      console.error(`catch error, ${error.code}, ${error.message}`);
  })
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

function decryptMessageProMise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  let keyGenPromise = rsaGenerator.generateKeyPair();
  let keyPair;
  let cipherDataBlob;
  let input = { data : stringToUint8Array(plan) };
  keyGenPromise.then(rsaKeyPair => {
    keyPair = rsaKeyPair;
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  }).then(() => {
    return cipher.doFinal(input);
  }).then(dataBlob => {
    console.info("EncryptOutPut is " + dataBlob.data);
    AlertDialog.show({message : "output" + dataBlob.data});
    cipherDataBlob = dataBlob;
    return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
  }).then(() => {
    return decoder.doFinal(cipherDataBlob);
  }).then(decodeData => {
    if (decodeData.data.toString() === input.data.toString()) {
      AlertDialog.show({message : "decrypt success"});
      return;
    }
    AlertDialog.show({message : "decrypt fail"});
  });
}

function decryptMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  let plainText = "this is cipher text";
  let input = {data : stringToUint8Array(plainText) };
  let cipherData;
  let keyPair;
  rsaGenerator.generateKeyPair(function (err, newKeyPair) {
    keyPair = newKeyPair;
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null, function (err, data) {
      cipher.doFinal(input, function (err, data) {
        AlertDialog.show({ message : "EncryptOutPut is " + data.data} );
        cipherData = data;
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null, function (err, data) {
          decoder.doFinal(cipherData, function (err, data) {
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message : "decrype success"} );
              return;
            }
            AlertDialog.show({ message : "decrype fail"} );
          });
        });
      });
    });
  });
}
```
以RSA非对称加解密（多次调用doFinal实现分段）为例：
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

// 字节流转成可理解的字符串
function uint8ArrayToString(array) {
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
  let globalCipherOutput;
  let globalDecodeOutput;
  var globalKeyPair;
  let plainTextSplitLen = 64; // RSA每次加解密允许的原文长度大小与密钥位数和填充模式等有关，详细规格内容见overview文档
  let cipherTextSplitLen = 128; // RSA密钥每次加密生成的密文数据长度计算方式：密钥位数/8
  let keyGenName = "RSA1024";
  let cipherAlgName = "RSA1024|PKCS1";
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator(keyGenName); // 创建非对称密钥生成器对象
  let cipher = cryptoFramework.createCipher(cipherAlgName); // 创建加密Cipher对象
  let decoder = cryptoFramework.createCipher(cipherAlgName); // 创建解密Decoder对象
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve("testRsaMultiDoFinal");
    }, 10);
  }).then(() => {
    return asyKeyGenerator.generateKeyPair(); // 生成rsa密钥
  }).then(keyPair => {
    globalKeyPair = keyPair; // 保存到密钥对全局变量
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, globalKeyPair.pubKey, null);
  }).then(async () => {
    globalCipherOutput = [];
    // 将原文按64字符进行拆分，循环调用doFinal进行加密，使用1024bit密钥时，每次加密生成128B长度的密文
    for (let i = 0; i < (globalPlainText.length / plainTextSplitLen); i++) {
      let tempStr = globalPlainText.substr(i * plainTextSplitLen, plainTextSplitLen);
      let tempBlob = { data : stringToUint8Array(tempStr) };
      let tempCipherOutput = await cipher.doFinal(tempBlob);
      globalCipherOutput = globalCipherOutput.concat(Array.from(tempCipherOutput.data));
    }
    console.info(`globalCipherOutput len is ${globalCipherOutput.length}, data is: ${globalCipherOutput.toString()}`);
    return;
  }).then(() =>{
    return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, globalKeyPair.priKey, null);
  }).then(async() => {
    globalDecodeOutput = [];
    // 将密文按128B进行拆分解密，得到原文后进行拼接
    for (let i = 0; i < (globalCipherOutput.length / cipherTextSplitLen); i++) {
      let tempBlobData = globalCipherOutput.slice(i * cipherTextSplitLen, (i + 1) * cipherTextSplitLen);
      let message = new Uint8Array(tempBlobData);
      let tempBlob = { data : message };
      let tempDecodeOutput = await decoder.doFinal(tempBlob);
      globalDecodeOutput += uint8ArrayToString(tempDecodeOutput.data);
    }
    if (globalDecodeOutput === globalPlainText) {
      console.info(`encode and decode success`);
    } else {
      console.info(`encode and decode error`);
    }
    return;
  }).catch(error => {
    console.error(`catch error, ${error.code}, ${error.message}`);
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
|cryptoFramework|function createVerify(algName : string) : Verify|根据String设置的参数创建Verify对象|
|Verify|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|使用callback方式设置密钥并初始化Verify对象|
|Verify|init(priKey : PriKey) : Promise\<void>|使用Promise方式设置密钥并初始化Verify对象|
|Verify|update(data : DataBlob, callback : AsyncCallback\<void>) : void|使用callback方式添加验签数据|
|Verify|update(data : DataBlob) : Promise\<void>|用Promise方式添加验签数据|
|Verify|verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void|使用callback方式验签所有数据|
|Verify|verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>|使用Promise方式验签所有数据|

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
以执行签名、验签操作时多次调用update实现分段为例：

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

function signLongMessagePromise() {
  let globalPlainText = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
  let globalSignData;
  let textSplitLen = 64; // 自定义的数据拆分长度
  let keyGenName = "RSA1024";
  let signAlgName = "RSA1024|PKCS1|SHA256";
  let globalKeyPair;
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator(keyGenName); // 创建非对称密钥生成器对象
  let signer = cryptoFramework.createSign(signAlgName); // 创建签名Signer对象
  let verifier = cryptoFramework.createVerify(signAlgName); // 创建验签Verifier对象
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve("testRsaMultiUpdate");
    }, 10);
  }).then(() => {
    return asyKeyGenerator.generateKeyPair(); // 生成RSA密钥
  }).then(keyPair => {
    globalKeyPair = keyPair; // 保存到密钥对全局变量
    return signer.init(globalKeyPair.priKey);
  }).then(async () => {
    // 当原文过大时，可将原文按理想长度进行拆分，循环调用update添加原文
    for (let i = 0; i < (globalPlainText.length / textSplitLen); i++) {
      let tempStr = globalPlainText.substr(i * textSplitLen, textSplitLen);
      let tempBlob = { data : stringToUint8Array(tempStr) };
      await signer.update(tempBlob);
    }
    return signer.sign(null);
  }).then(data =>{
    globalSignData = data.data;
    console.info(`globalSignOutput len is ${globalSignData.length}, data is: ${globalSignData.toString()}`);
    return verifier.init(globalKeyPair.pubKey);
  }).then(async() => {
    // 当原文过大时，可将原文按理想长度进行拆分，循环调用update添加原文
    for (let i = 0; i < (globalPlainText.length / textSplitLen); i++) {
      let tempData = globalPlainText.slice(i * textSplitLen, (i + 1) * textSplitLen);
      let tempBlob = { data : stringToUint8Array(tempData) };
      await verifier.update(tempBlob);
    }
    return verifier.verify(null, { data : globalSignData});
  }).then(res => {
    console.info(`verify res is ${res}`);
  }).catch(error => {
    console.error(`catch error, ${error.code}, ${error.message}`);
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
| Md              | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | 接受用户输入数据，通过Callback的方式，异步更新摘要 |
| Md              | update(input : DataBlob) : Promise\<void>;                  | 接受用户输入数据，通过Promise的方式，异步更新摘要  |
| Md              | digest(callback : AsyncCallback\<DataBlob>) : void;         | 通过Callback的方式，返回结果                       |
| Md              | digest() : Promise\<DataBlob>;                              | 通过Promise的方式，返回结果                        |
| Md              | getMdLength() : number;                                      | 获取摘要的长度（由指定的摘要算法决定）             |
| Md              | readonly algName : string;                                   | 获取当前设置的摘要算法名                           |

**开发步骤**

1. 设置算法，通过接口`createMd`生成摘要操作实例
2. 接受用户数据，通过接口`update`，更新摘要，此步骤可重复
3. 通过接口`digest`，返回摘要计算结果
4. 获取当前摘要算法名与摘要计算长度

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// 可理解的字符串转成字节流
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 以Promise方式完成摘要
function doMdByPromise() {
  let mdAlgName = "SHA256"; // 摘要算法名
  let message = "mdTestMessgae"; // 待摘要数据
  let md;
  let mdOutput;
  try {
    md = cryptoFramework.createMd(mdAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    return;
  }
  console.info("[Promise]: Md algName is: " + md.algName);
  // 数据量较少时，可以只做一次update，将数据全部传入，接口未对入参长度做限制
  let promiseMdUpdate = md.update({ data: stringToUint8Array(message) });
  promiseMdUpdate.then(() => {
    // 通过digest，返回摘要结果
    let PromiseMdDigest = md.digest();
    return PromiseMdDigest;
  }).then(digestOutput => {
    mdOutput = digestOutput;
    console.info("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("[Promise]: MD len: " + mdLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// 以Callback方式完成摘要
function doMdByCallback() {
  let mdAlgName = "SHA256"; // 摘要算法名
  let message = "mdTestMessgae"; // 待摘要数据
  let md;
  let mdOutput;
  try {
    md = cryptoFramework.createMd(mdAlgName);
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Callback]: Md algName is: " + md.algName);
  // 数据量较少时，可以只做一次update，将数据全部传入，接口未对入参长度做限制
  md.update({ data: stringToUint8Array(message) }, (err,) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    md.digest((err1, digestOutput) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      } else {
        mdOutput = digestOutput;
        console.info("[Callback]: MD result: " + mdOutput.data);
        let mdLen = md.getMdLength();
        console.info("[Callback]: MD len: " + mdLen);
      }
    });
  });
}
```
以MD更新时多次调用update实现分段为例：
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// 可理解的字符串转成字节流
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}


// 使用Promise方式，完成分段摘要
async function doLoopMdPromise() {
  let mdAlgName = "SHA256"; // 摘要算法名
  let md;
  let mdOutput;
  try {
    md = cryptoFramework.createMd(mdAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    return;
  }
  console.info("[Promise]: Md algName is: " + md.algName);
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // 假设信息总共43字节
  let messageArr = [];
  let updateLength = 20; // 假设每20字节分段update一次，实际并无要求

  for (let i = 0; i <= messageText.length; i++) {
    if ((i % updateLength == 0 || i == messageText.length) && messageArr.length != 0) {
      let message = new Uint8Array(messageArr);
      let messageBlob = { data : message };
      // 使用await处理for循环里的update
      try {
        await md.update(messageBlob); // 分段update
      } catch (error) {
        console.error("await update error code: " + error.code + ", message is: " + error.message);
        return;
      }
      messageArr = [];
    }
    // 按分割长度，填充messageArr
    if (i < messageText.length) {
      messageArr.push(messageText.charCodeAt(i));
    }
  }
  let PromiseMdDigest = md.digest();
  PromiseMdDigest.then(digestOutput => {
    mdOutput = digestOutput;
    console.info("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("[Promise]: MD len: " + mdLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
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

1. 通过createKeyAgreement接口创建KeyAgreement对象，用于后续的密钥协商操作。
2. 调用KeyAgreement对象提供的generateSecret方法，传入对端的ECC公钥对象，以及本地生成的ECC私钥对象。

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalSelfPriKey;
let globalPeerPubKey;

function ecdhPromise() {
  let peerPubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,72,206,61,3,1,7,3,66,0,4,83,96,142,9,86,214,126,106,247,233,92,125,4,128,138,105,246,162,215,71,81,58,202,121,26,105,211,55,130,45,236,143,55,16,248,75,167,160,167,106,2,152,243,44,68,66,0,167,99,92,235,215,159,239,28,106,124,171,34,145,124,174,57,92]);
  let peerPubKeyBlob = { data: peerPubKeyArray };
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.convertKey(peerPubKeyBlob, null).then((peerKeyPair) => {
    globalPeerPubKey = peerKeyPair.pubKey;
    return eccGenerator.generateKeyPair();
  }).then((keyPair) => {
    globalSelfPriKey = keyPair.priKey;
    return eccKeyAgreement.generateSecret(globalSelfPriKey, globalPeerPubKey);
  }).then((secret) => {
    console.info("ecdh promise output is " + secret.data);
  }).catch((error) => {
    console.error("ecdh error.");
  });
}

function ecdhCallback() {
  let peerPubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,72,206,61,3,1,7,3,66,0,4,83,96,142,9,86,214,126,106,247,233,92,125,4,128,138,105,246,162,215,71,81,58,202,121,26,105,211,55,130,45,236,143,55,16,248,75,167,160,167,106,2,152,243,44,68,66,0,167,99,92,235,215,159,239,28,106,124,171,34,145,124,174,57,92]);
  let peerPubKeyBlob = { data: peerPubKeyArray };
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.convertKey(peerPubKeyBlob, null, function (err, peerKeyPair) {
    globalPeerPubKey = peerKeyPair.pubKey;
    eccGenerator.generateKeyPair(function (err, keyPair) {
      globalSelfPriKey = keyPair.priKey;
      eccKeyAgreement.generateSecret(globalSelfPriKey, globalPeerPubKey, function (err, secret) {
        if (err) {
          console.error("ecdh error.");
          return;
        }
        console.info("ecdh callback output is " + secret.data);
      });
    });
  })
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
| cryptoFramework | function createMac(algName : string) : Mac;                  | 指定摘要算法，生成消息认证码实例Mac                 |
| Mac             | init(key : SymKey, callback : AsyncCallback\<void>) : void; | 接收输入对称密钥，通过Callback的方式，异步初始化MAC |
| Mac             | init(key : SymKey) : Promise\<void>;                        | 接收输入对称密钥，通过Promise的方式，异步初始化MAC  |
| Mac             | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | 接受输入数据，通过Callback的方式，异步更新MAC       |
| Mac             | update(input : DataBlob) : Promise\<void>;                  | 接受输入数据，通过Promise的方式，异步更新MAC        |
| Mac             | doFinal(callback : AsyncCallback\<DataBlob>) : void;        | 通过Callback的方式，返回MAC计算结果                 |
| Mac             | doFinal() : Promise\<DataBlob>;                             | 通过Promise的方式，返回MAC计算结果                  |
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

// 可理解的字符串转成字节流
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 以Promise方式完成HMAC
function doHmacByPromise() {
  let macAlgName = "SHA256"; // 摘要算法名
  let message = "hmacTestMessgae"; // 待hmac数据
  let macOutput;
  let mac;
  try {
    mac = cryptoFramework.createMac(macAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128位密钥
    data : stringToUint8Array("12345678abcdefgh")
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // 将二进制密钥转换为算法库密钥
  let promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  }).then(() => {
    // 数据量较少时，可以只做一次update，将数据全部传入，接口未对入参长度做限制
    let promiseMacUpdate = mac.update({ data: stringToUint8Array(message) });
    return promiseMacUpdate;
  }).then(() => {
    let PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
  }).then(output => {
    macOutput = output;
    console.info("[Promise]: HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
    console.info("[Promise]: MAC len: " + macLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// 以Callback方式完成HMAC
function doHmacByCallback() {
  let macAlgName = "SHA256"; // 摘要算法名
  let message = "hmacTestMessgae"; // 待hmac数据
  let macOutput;
  let mac;
  try {
    mac = cryptoFramework.createMac(macAlgName);
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128位密钥
    data : stringToUint8Array("12345678abcdefgh")
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // 将二进制密钥转换为算法库密钥
  symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      }
      // 数据量较少时，可以只做一次update，将数据全部传入，接口未对入参长度做限制
      mac.update({ data: stringToUint8Array(message) }, (err2, ) => {
        if (err2) {
          console.error("[Callback]: err: " + err2.code);
        }
        mac.doFinal((err3, output) => {
          if (err3) {
            console.error("[Callback]: err: " + err3.code);
          } else {
            macOutput = output;
            console.info("[Callback]: HMAC result: " + macOutput.data);
            let macLen = mac.getMacLength();
            console.info("[Callback]: MAC len: " + macLen);
          }
        });
      });
    });
  });
}
```
以HMAC更新MAC时多次调用update实现分段为例：
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function doLoopHmacPromise() {
  let macAlgName = "SHA256"; // 摘要算法名
  let macOutput;
  let mac;
  try {
    mac = cryptoFramework.createMac(macAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    return;
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128位密钥
    data : stringToUint8Array("12345678abcdefgh")
  }
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // 假设信息总共43字节
  let updateLength = 20; // 假设每20字节分段update一次，实际并无要求
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // 将二进制密钥转换为算法库密钥
  let promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  }).then(async () => {
    let promiseMacUpdate;
    let messageArr = [];
    for (let i = 0; i <= messageText.length; i++) {
      if ((i % updateLength == 0 || i == messageText.length) && messageArr.length != 0) {
        let message = new Uint8Array(messageArr);
        let messageBlob = { data : message };
        // 使用await处理for循环里的update
        try {
          promiseMacUpdate = await mac.update(messageBlob); // 分段update
        } catch (error) {
          console.error("await update error code: " + error.code + ", message is: " + error.message);
          return;
        }
        messageArr = [];
      }
      // 按分割长度，填充messageArr
      if (i < messageText.length) {
        messageArr.push(messageText.charCodeAt(i));
      }
    }
    return promiseMacUpdate;
  }).then(() => {
    let PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
  }).then(output => {
    macOutput = output;
    console.log("[Promise]: HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
    console.log("[Promise]: MAC len: " + macLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
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
| Random          | generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void; | 接受输入长度，通过Callback，异步生成随机数   |
| Random          | generateRandom(len : number) : Promise\<DataBlob>;          | 接受输入长度，通过Promise，异步生成随机数      |
| Random          | setSeed(seed : DataBlob) : void;                            | 接受输入Blob，设置种子  |

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
      try {
          rand.setSeed(randData);
      } catch (error) {
          console.log("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
      }
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
      try {
          rand.setSeed(randData);
      } catch (error) {
          console.log("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
      }
    }
  });
}
```

## 相关实例

针对加解密算法开发，有以下相关实例可供参考：

- [加解密（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/BasicFeature/Security/Cipher)