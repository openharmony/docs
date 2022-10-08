# 加解密算法库框架开发指导
## 使用加解密操作
**场景说明**

使用加解密操作中，典型的场景有：
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

1. 生成对称密钥生成器。
2. 通过密钥生成器生成对称密钥。
3. 生成加解密生成器。
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

## 使用签名验签操作

**场景说明**
使用签名验签操作中，典型的场景有：
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
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA25");
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

使用签名验签操作中，典型的场景有：

使用ECDH操作。

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

function stringToUint8Array(str) {
	var arr = [];
	for (var i = 0, j = str.length; i < j; ++i) {
		arr.push(str.charCodeAt(i));
	}
	var tmpArray = new Uint8Array(arr);
	return tmpArray;
}

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

使用消息认证码操作的主要场景为：

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
