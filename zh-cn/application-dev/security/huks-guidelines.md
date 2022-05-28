# HUKS开发指导

## 场景介绍

 HUKS（OpenHarmony Universal KeyStore，OpenHarmony通用密钥库系统）向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。 


## 接口说明

| 接口名                                                       | 描述        |
| ------------------------------------------------------------ | ---------------- |
| generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;HuksResult&gt;) : void| 生成密钥         |
| generateKey(keyAlias: string, options: HuksOptions) : Promise&lt;HuksResult&gt;| 生成密钥         |
| exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;HuksResult&gt;) : void| 导出公钥         |
| exportKey(keyAlias: string, options: HuksOptions) : Promise&lt;HuksResult&gt;| 导出公钥         |
| isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;boolean&gt;) : void | 查询密钥是否存在 |
| isKeyExist(keyAlias: string, options: HuksOptions) : Promise&lt;boolean> | 查询密钥是否存在 |
| deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback&lt;HuksResult&gt;) : void| 删除密钥         |
| deleteKey(keyAlias: string, options: HuksOptions) : Promise&lt;HuksResult&gt;| 删除密钥         |

## 开发步骤

1. 引入HUKS模块

   ```js
   import huks from '@ohos.security.huks'
   ```

2. 使用generateKey接口生成密钥。

   keyAlias为生成的密钥别名，options为生成密钥时使用到的参数，需根据具体需要到的算法设定options中的参数。

   generateKey接口会返回密钥的生成是否成功。

   ```js
   var alias = 'testAlias';
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_ECC
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_224
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[3] = {
     tag: huks.HuksTag.HUKS_TAG_DIGEST,
     value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
   };
   var options = {
     properties: properties
   }
   var resultA = huks.generateKey(alias, options);
   ```

3. 使用Init接口进行init操作。

   Alias为初始化密钥的别名，options为初始化密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   init接口会返回init操作是否成功。

   ```js
   var alias = 'test001'
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   huks.init(alias, options, function(err, data) {
       if (err.code !== 0) {
           console.log("test init err information: " + JSON.stringify(err));
       } else {
           console.log(`test init data: ${JSON.stringify(data)}`);
       }
   })
   ```
   
4. 使用Update接口进行update操作。

   handle为更新密钥的session id，options为更新密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   update接口会返回update操作是否成功。

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.update(handle, options)
   ```
   
5. 使用Finish接口进行finish操作。

   handle为 结束密钥的session id，options为结束密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   finish接口会返回finish操作是否成功。

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.finish(handle, options) 
   ```



