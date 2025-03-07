# security变更说明

## cl.security.1 通用密钥库SystemCapability变更

**访问级别**

公开接口。

**变更原因**

通用密钥库为了满足未来mini平台算法能力扩展诉求，将加解密算法相关TAG的SystemCapability由SystemCapability.Security.Huks.Extension调整为SystemCapability.Security.Huks.Core。且由于mini平台算法能力较弱，部分算法当前返回不支持，待后续扩展。

**变更影响**

该变更为不兼容变更。

对接口所属的SystemCapability进行调整，对接口本身的使用方式无影响。

变更前：

相关接口的系统能力要求为“SystemCapability.Security.Huks.Extension”。判断设备是否支持本次变更涉及算法需使用canIUse("SystemCapability.Security.Huks.Extension")。

变更后：

相关接口的系统能力要求为“SystemCapability.Security.Huks.Core”。判断设备是否支持本次变更涉及算法需改为使用canIUse("SystemCapability.Security.Huks.Core")。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.39开始。

**变更的接口/组件**


@ohos.security.huks模块中的加解密算法相关接口。详细接口如下：
| 序号 | 接口名                    | 接口说明     |
| ---- | ------------------------- | ------------ |
| 1    | huks.importKeyItem        | 导入明文密钥 |
| 2    | huks.importWrappedKeyItem | 导入加密密钥 |
| 3    | huks.exportKeyItem        | 导出密钥     |
| 4    | huks.getKeyItemProperties | 获取密钥属性 |
| 5    | huks.deleteKey            | 删除密钥     |

@ohos.security.huks模块中的相关枚举类型。详细如下：
| 序号 | 枚举名                | 枚举说明                                              |
| ---- | --------------------- | ----------------------------------------------------- |
| 1    | HuksKeyPurpose        | 表示密钥用途                                          |
| 2    | HuksKeyDigest         | 表示摘要算法                                          |
| 3    | HuksKeyPadding        | 表示补齐算法                                          |
| 4    | HuksCipherMode        | 表示加密模式                                          |
| 5    | HuksKeySize           | 表示密钥长度                                          |
| 6    | HuksKeyAlg            | 表示密钥使用的算法                                    |
| 7    | HuksUnwrapSuite       | 表示导入加密密钥的算法套件                            |
| 8    | HuksKeyStorageType    | 表示密钥存储方式                                      |
| 9    | HuksImportKeyType     | 表示导入密钥的密钥类型                                |
| 10   | HuksRsaPssSaltLenType | 表示Rsa在签名验签、padding为pss时需指定的salt_len类型 |
| 11   | HuksAuthStorageLevel  | 表示生成或导入密钥时，指定该密钥的存储安全等级        |
| 12   | HuksSendType          | 表示发送Tag的方式                                     |
| 13   | HuksTagType           | 表示Tag的数据类型                                     |

HuksTag中的枚举值。详细如下：
| 序号 | 枚举值                                   | 枚举值说明                      |
| ---- | ---------------------------------------- | ------------------------------- |
| 1    | HUKS_TAG_DIGEST                          | 表示摘要算法的Tag               |
| 2    | HUKS_TAG_SALT                            | 表示密钥派生时的盐值            |
| 3    | HUKS_TAG_ITERATION                       | 表示密钥派生时的迭代次数        |
| 4    | HUKS_TAG_AGREE_ALG                       | 表示密钥协商时的算法类型        |
| 5    | HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS   | 表示密钥协商时的公钥别名        |
| 6    | HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS         | 表示密钥协商时的私钥别名        |
| 7    | HUKS_TAG_AGREE_PUBLIC_KEY                | 表示密钥协商时的公钥            |
| 8    | HUKS_TAG_DERIVE_KEY_SIZE                 | 表示派生密钥的大小              |
| 9    | HUKS_TAG_IMPORT_KEY_TYPE                 | 表示导入的密钥类型              |
| 10   | HUKS_TAG_UNWRAP_ALGORITHM_SUITE          | 表示导入加密密钥的套件          |
| 11   | HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG | 表示派生密钥/协商密钥的存储类型 |
| 12   | HUKS_TAG_RSA_PSS_SALT_LEN_TYPE           | 表示rsa_pss_salt_length的类型   |
| 13   | HUKS_TAG_ALL_USERS                       | 预留                            |
| 14   | HUKS_TAG_USER_ID                         | 表示当前密钥属于哪个userID      |
| 15   | HUKS_TAG_NO_AUTH_REQUIRED                | 预留                            |
| 16   | HUKS_TAG_IS_ALLOWED_WRAP                 | 预留                            |
| 17   | HUKS_TAG_KEY_WRAP_TYPE                   | 预留                            |
| 18   | HUKS_TAG_KEY_ROLE                        | 预留                            |
| 19   | HUKS_TAG_IS_ASYNCHRONIZED                | 预留                            |
| 20   | HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA      | 预留                            |
| 21   | HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA     | 预留                            |

**适配指导**

SystemCapability.Security.Huks.Core为必选基础能力，SystemCapability.Security.Huks.Extension为可选扩展能力。当前SDK默认定义的device-define都包含SystemCapability.Security.Huks.Core必选能力，因此涉及Universal Keystore组件的功能代码原则上无需适配。但如果代码中涉及调用canIUse()方法对本次变更涉及算法支持情况进行判断，则应修改canIUse()方法传入的SystemCapability，同时参考资料，结合API level判断。

## cl.security.2 @ohos.security.cryptoFramework 接口SysCap变更

**访问级别**

公开接口

**变更原因**

加解密算法库框架为了灵活适配不同平台，按照算法类型对接口重新划分SysCap。

**变更影响**

此变更为不兼容变更。

变更前：

加解密算法库框架所有接口的SysCap均是SystemCapability.Security.CryptoFramework。

（1）可以使用canIUse("SystemCapability.Security.CryptoFramework")判断设备是否支持加解密算法库能力。

（2）若自定义设备支持加解密算法库能力能力，只需在设备的能力集配置中配置SystemCapability.Security.CryptoFramework。

变更后：

加解密算法库框架按照算法类型对接口重新划分SysCap，如随机数相关接口SysCap变更为SystemCapability.Security.CryptoFramework.Rand。

（1）应该使用具体的Syscap判断设备的加解密算法库是否支持对应算法，如使用canIUse("SystemCapability.Security.CryptoFramework.Rand")判断设备的加解密算法库能力是否支持随机数能力。

（2）若自定义设备原本就支持加解密算法库能力，则需在设备的能力集配置中添加加解密算法库框架的所有SysCap，具体SysCap名见“变更的接口/组件”。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.39 版本开始。

**变更的接口/组件**

@ohos.security.cryptoFramework按照算法类型对接口重新划分SysCap，具体划分如下，其中序号为2到11的10个SysCap是新增的：

| 序号 | SysCap名 | SysCap描述 |
| ------- | ----- | ------ |
| 1 | SystemCapability.Security.CryptoFramework | 原有的SysCap，变更后不包含任何算法能力，仅包含公共能力 |
| 2 | SystemCapability.Security.CryptoFramework.Key | 密钥基础类型 |
| 3 | SystemCapability.Security.CryptoFramework.Key.SymKey | 对称密钥 |
| 4 | SystemCapability.Security.CryptoFramework.Key.AsymKey | 非对称密钥 |
| 5 | SystemCapability.Security.CryptoFramework.Signature | 签名验签 |
| 6 | SystemCapability.Security.CryptoFramework.Cipher | 对称、非对称加解密 |
| 7 | SystemCapability.Security.CryptoFramework.KeyAgreement | 密钥协商 |
| 8 | SystemCapability.Security.CryptoFramework.MessageDigest | 消息摘要 |
| 9 | SystemCapability.Security.CryptoFramework.Mac | 消息验证码 |
| 10 | SystemCapability.Security.CryptoFramework.Kdf | 密钥派生 |
| 11 | SystemCapability.Security.CryptoFramework.Rand | 随机数 |

**适配指导**

（1）判断设备是否支持加解密算法库框架的随机数能力需使用canIUse("SystemCapability.Security.CryptoFramework.Rand")，其他算法类型类似。

（2）若自定义设备的能力集配置文件中包含了SystemCapability.Security.CryptoFramework，则需要添加此次变更新增的10个SysCap。