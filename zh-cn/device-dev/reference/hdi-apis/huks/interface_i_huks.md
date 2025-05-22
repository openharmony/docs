# IHuks


## 概述

定义了HUKS的驱动接口，用于进行密钥管理。

**起始版本：** 4.0

**相关模块：**[HdfHuks](_hdf_huks.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ModuleInit](#moduleinit) () | HUKS驱动初始化。  | 
| [GenerateKey](#generatekey) ([in] struct [HuksBlob](_huks_blob.md) keyAlias,[in] struct [HuksParamSet](_huks_param_set.md) paramSet,[in] struct [HuksBlob](_huks_blob.md) keyIn, [out] struct [HuksBlob](_huks_blob.md) encKeyOut) | 根据待生成密钥的属性生成对应的密钥材料，并返回加密后的密钥材料密文。  | 
| [ImportKey](#importkey) ([in] struct [HuksBlob](_huks_blob.md) keyAlias, [in] struct [HuksBlob](_huks_blob.md) key, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out] struct [HuksBlob](_huks_blob.md) encKeyOut) | 导入明文密钥。  | 
| [ImportWrappedKey](#importwrappedkey) ([in] struct [HuksBlob](_huks_blob.md) wrappingKeyAlias, [in] struct [HuksBlob](_huks_blob.md) wrappingEncKey, [in] struct [HuksBlob](_huks_blob.md) wrappedKeyData, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out] struct [HuksBlob](_huks_blob.md) encKeyOut) | 导入加密密钥。  | 
| [ExportPublicKey](#exportpublickey) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out] struct [HuksBlob](_huks_blob.md) keyOut) | 导出密钥对的公钥。  | 
| [Init](#init) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out]struct [HuksBlob](_huks_blob.md) handle, [out] struct [HuksBlob](_huks_blob.md) token) | 初始化密钥会话，解密密钥材料到内存中，并返回一个句柄和令牌。  | 
| [Update](#update) ([in] struct [HuksBlob](_huks_blob.md) handle, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) inData, [out] struct [HuksBlob](_huks_blob.md) outData) | 分段操作数据或分段传参，根据密码算法的本身的要求需要对数据进行分段操作或传参（密钥协商场景）。  | 
| [Finish](#finish) ([in] struct [HuksBlob](_huks_blob.md) handle, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) inData, [out] struct [HuksBlob](_huks_blob.md) outData) | 结束密钥会话和操作数据。  | 
| [Abort](#abort) ([in] struct [HuksBlob](_huks_blob.md) handle, [in] struct [HuksParamSet](_huks_param_set.md) paramSet) | 中止密钥会话，并释放会话内部的数据，中止后不能操作会话。  | 
| [CheckKeyValidity](#checkkeyvalidity) ([in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) encKey) | 校验密钥材料的有效性（密钥和属性的完整性）。  | 
| [AttestKey](#attestkey) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out] struct [HuksBlob](_huks_blob.md) certChain) | 获取密钥证书链。  | 
| [GenerateRandom](#generaterandom) ([in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out]struct [HuksBlob](_huks_blob.md) random) | 生成随机数。  | 
| [Sign](#sign) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) srcData, [out]struct [HuksBlob](_huks_blob.md) signature) | 使用密钥对数据进行签名。  | 
| [Verify](#verify) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) srcData, [in] struct [HuksBlob](_huks_blob.md) signature) | 校验数据的签名。  | 
| [Encrypt](#encrypt) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) plainText, [out] struct [HuksBlob](_huks_blob.md) cipherText) | 使用密钥对数据进行加密。  | 
| [Decrypt](#decrypt) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) cipherText, [out] struct [HuksBlob](_huks_blob.md) plainText) | 使用密钥对数据的密文进行解密。  | 
| [AgreeKey](#agreekey) ([in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) encPrivateKey, [in] struct [HuksBlob](_huks_blob.md) peerPublicKey, [out] struct [HuksBlob](_huks_blob.md) agreedKey) | 使用HUKS存储的私钥和业务的公钥进行密钥协商。  | 
| [DeriveKey](#derivekey) ([in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) encKdfKey, [out] struct [HuksBlob](_huks_blob.md) derivedKey) | 使用HUKS存储的密钥进行派生。  | 
| [Mac](#mac) ([in] struct [HuksBlob](_huks_blob.md) encKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [in] struct [HuksBlob](_huks_blob.md) srcData, [out] struct [HuksBlob](_huks_blob.md) mac) | 使用HUKS存储的密钥做数据的消息认证码。  | 
| [UpgradeKey](#upgradekey) ([in] struct [HuksBlob](_huks_blob.md) encOldKey, [in] struct [HuksParamSet](_huks_param_set.md) paramSet, [out] struct [HuksBlob](_huks_blob.md) encNewKey) | 升级密钥，包括升级加密方式和加密材料。当密钥文件版本号小于最新版本号时，HUKS Service触发该升级能力。  | 
| [ExportChipsetPlatformPublicKey](#exportchipsetplatformpublickey) ([in] struct [HuksBlob](_huks_blob.md) salt, [in] enum [HuksChipsetPlatformDecryptScene](_hdf_huks.md#hukschipsetplatformdecryptscene) scene, [out] struct [HuksBlob](_huks_blob.md) publicKey) | 导出芯片平台级密钥对的公钥。  | 


## 成员函数说明


### Abort()

```
IHuks::Abort ([in] struct HuksBlob handle, [in] struct HuksParamSet paramSet )
```
**描述**

中止密钥会话，并释放会话内部的数据，中止后不能操作会话。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 密钥会话句柄[HuksBlob](_huks_blob.md)。 | 
| paramSet | 操作密钥的参数集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。 | 

**参见：**

[Init](#init) | [Update](#update) | [Finish](#finish)

**返回：**

0 表示操作成功

非0表示操作失败


### AgreeKey()

```
IHuks::AgreeKey ([in] struct HuksParamSet paramSet, [in] struct HuksBlob encPrivateKey, [in] struct HuksBlob peerPublicKey, [out] struct HuksBlob agreedKey )
```
**描述**

使用HUKS存储的私钥和业务的公钥进行密钥协商。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 用于协商的参数[HuksParamSet](_huks_param_set.md)。 | 
| encPrivateKey | HUKS存储的密钥对材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| peerPublicKey | 待协商的公钥[HuksBlob](_huks_blob.md)。  | 
| agreedKey | 协商出的密钥明文[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### AttestKey()

```
IHuks::AttestKey ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [out] struct HuksBlob certChain )
```
**描述**

获取密钥证书链。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 用于获取密钥证书链的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| certChain | 密钥证书链[HuksBlob](_huks_blob.md)，证书链结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示操作成功

非0表示操作失败


### CheckKeyValidity()

```
IHuks::CheckKeyValidity ([in] struct HuksParamSet paramSet, [in] struct HuksBlob encKey )
```
**描述**

校验密钥材料的有效性（密钥和属性的完整性）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 校验密钥有效性的参数集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示密钥材料有效

非0表示密钥材料无效


### Decrypt()

```
IHuks::Decrypt ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [in] struct HuksBlob cipherText, [out] struct HuksBlob plainText )
```
**描述**

使用密钥对数据的密文进行解密。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 用于加密的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| cipherText | 数据的密文[HuksBlob](_huks_blob.md)。  | 
| plainText | 数据的明文[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### DeriveKey()

```
IHuks::DeriveKey ([in] struct HuksParamSet paramSet, [in] struct HuksBlob encKdfKey, [out] struct HuksBlob derivedKey )
```
**描述**

使用HUKS存储的密钥进行派生。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 用于派生的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| encKdfKey | HUKS存储的密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| derivedKey | 派生出的密钥明文[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### Encrypt()

```
IHuks::Encrypt ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [in] struct HuksBlob plainText, [out] struct HuksBlob cipherText )
```
**描述**

使用密钥对数据进行加密。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 用于加密的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| plainText | 待加密的数据[HuksBlob](_huks_blob.md)。  | 
| cipherText | 数据的密文[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### ExportChipsetPlatformPublicKey()

```
IHuks::ExportChipsetPlatformPublicKey ([in] struct HuksBlob salt, [in] enum HuksChipsetPlatformDecryptScene scene, [out] struct HuksBlob publicKey )
```
**描述**

导出芯片平台级密钥对的公钥。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| salt | 用来派生芯片平台密钥对时的派生因子[HuksBlob](_huks_blob.md)。  | 
| scene | 业务预期进行芯片平台解密的场景[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| publicKey | 公钥材料，如出参为ECC-P256的x、y轴值裸数据，各32字节[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### ExportPublicKey()

```
IHuks::ExportPublicKey ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [out] struct HuksBlob keyOut )
```
**描述**

导出密钥对的公钥。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 加密的密钥对材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 导出密钥密钥属性集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| keyOut | 公钥材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示导出密钥成功

非0表示导出密钥失败


### Finish()

```
IHuks::Finish ([in] struct HuksBlob handle, [in] struct HuksParamSet paramSet, [in] struct HuksBlob inData, [out] struct HuksBlob outData )
```
**描述**

结束密钥会话和操作数据。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 密钥会话句柄[HuksBlob](_huks_blob.md)。 | 
| paramSet | 操作密钥的参数集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| inData | 分段数据或者参数[HuksBlob](_huks_blob.md)。  | 
| outData | 操作完成的数据[HuksBlob](_huks_blob.md)。 | 

**参见：**

[Init](#init) | [Update](#update) | [Abort](#abort)

**返回：**

0 表示操作成功

非0表示操作失败


### GenerateKey()

```
IHuks::GenerateKey ([in] struct HuksBlob keyAlias, [in] struct HuksParamSet paramSet, [in] struct HuksBlob keyIn, [out] struct HuksBlob encKeyOut )
```
**描述**

根据待生成密钥的属性生成对应的密钥材料，并返回加密后的密钥材料密文。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 待生成密钥的别名[HuksBlob](_huks_blob.md)。  | 
| paramSet | 待生成密钥的密钥属性参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| keyIn | 待生成密钥的密钥材料[HuksBlob](_huks_blob.md)，可选。  | 
| encKeyOut | 生成密钥的密文材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示生成密钥成功

非0表示生成密钥失败


### GenerateRandom()

```
IHuks::GenerateRandom ([in] struct HuksParamSet paramSet, [out] struct HuksBlob random )
```
**描述**

生成随机数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 用于生成随机数的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| random | 生成的随机数[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示生成成功

非0表示生成失败


### ImportKey()

```
IHuks::ImportKey ([in] struct HuksBlob keyAlias, [in] struct HuksBlob key, [in] struct HuksParamSet paramSet, [out] struct HuksBlob encKeyOut )
```
**描述**

导入明文密钥。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 待导入密钥的别名[HuksBlob](_huks_blob.md)。  | 
| key | 待导入密钥的明文密钥材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 待导入密钥的密钥属性集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| encKeyOut | 导入密钥的密文材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示导入密钥成功

非0表示导入密钥失败


### ImportWrappedKey()

```
IHuks::ImportWrappedKey ([in] struct HuksBlob wrappingKeyAlias, [in] struct HuksBlob wrappingEncKey, [in] struct HuksBlob wrappedKeyData, [in] struct HuksParamSet paramSet, [out] struct HuksBlob encKeyOut )
```
**描述**

导入加密密钥。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| wrappingKeyAlias | 用于做加密导入的中间密钥别名[HuksBlob](_huks_blob.md)。  | 
| wrappingEncKey | 用于做加密导入的中间密钥密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| wrappedKeyData | 待导入密钥的密文密钥材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 待导入密钥的密钥属性集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| encKeyOut | 导入密钥的密文材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示导入密钥成功

非0表示导入密钥失败


### Init()

```
IHuks::Init ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [out] struct HuksBlob handle, [out] struct HuksBlob token )
```
**描述**

初始化密钥会话，解密密钥材料到内存中，并返回一个句柄和令牌。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 加密的密钥材料[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 操作密钥的参数集[HuksParamSet](_huks_param_set.md)，用于指定该次密钥操作的参数。  | 
| handle | 密钥会话句柄[HuksBlob](_huks_blob.md)，用于后续操作密钥会话。  | 
| token | 密钥会话令牌[HuksBlob](_huks_blob.md)，用于密钥访问控制使用。 | 

**参见：**

[Init](#init) | [Update](#update) | [Finish](#finish)

**返回：**

0 表示初始化会话成功

非0表示初始化失败


### Mac()

```
IHuks::Mac ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [in] struct HuksBlob srcData, [out] struct HuksBlob mac )
```
**描述**

使用HUKS存储的密钥做数据的消息认证码。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 用于做MAC的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| srcData | 用于做MAC的数据[HuksBlob](_huks_blob.md)。  | 
| mac | 消息认证码[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### ModuleInit()

```
IHuks::ModuleInit ()
```
**描述**

HUKS驱动初始化。

**起始版本：** 4.0

**返回：**

0 表示初始化成功

非0表示初始化失败


### Sign()

```
IHuks::Sign ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [in] struct HuksBlob srcData, [out] struct HuksBlob signature )
```
**描述**

使用密钥对数据进行签名。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 用于签名的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| srcData | 待签名的数据[HuksBlob](_huks_blob.md)。  | 
| signature | 数据的签名[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败


### Update()

```
IHuks::Update ([in] struct HuksBlob handle, [in] struct HuksParamSet paramSet, [in] struct HuksBlob inData, [out] struct HuksBlob outData )
```
**描述**

分段操作数据或分段传参，根据密码算法的本身的要求需要对数据进行分段操作或传参（密钥协商场景）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 密钥会话句柄[HuksBlob](_huks_blob.md)，通过初始化密钥会话接口获取。  | 
| paramSet | 操作密钥的参数集[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| inData | 分段数据或者参数[HuksBlob](_huks_blob.md)。  | 
| outData | 操作完成的数据[HuksBlob](_huks_blob.md)。 | 

**参见：**

[Init](#init) | [Finish](#finish) | [Abort](#abort)

**返回：**

0 表示操作成功

非0表示操作失败


### UpgradeKey()

```
IHuks::UpgradeKey ([in] struct HuksBlob encOldKey, [in] struct HuksParamSet paramSet, [out] struct HuksBlob encNewKey )
```
**描述**

升级密钥，包括升级加密方式和加密材料。当密钥文件版本号小于最新版本号时，HUKS Service触发该升级能力。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encOldKey | 待升级密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 升级密钥的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| encNewKey | 升级后的密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。 | 

**返回：**

0 表示成功

非0表示失败


### Verify()

```
IHuks::Verify ([in] struct HuksBlob encKey, [in] struct HuksParamSet paramSet, [in] struct HuksBlob srcData, [in] struct HuksBlob signature )
```
**描述**

校验数据的签名。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| encKey | 密钥材料密文[HuksBlob](_huks_blob.md)，密钥材料结构参见《HUKS设备开发指南》。  | 
| paramSet | 用于校验签名的参数[HuksParamSet](_huks_param_set.md)，属性集结构参见《HUKS设备开发指南》。  | 
| srcData | 待验签的数据[HuksBlob](_huks_blob.md)。  | 
| signature | 待校验数据的签名[HuksBlob](_huks_blob.md)。 | 

**返回：**

0 表示成功

非0表示失败
