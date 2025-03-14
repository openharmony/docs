# @ohos.security.cert (证书模块)

证书算法库框架提供证书相关接口。其中，依赖加解密算法库框架的基础算法能力的部分，详细接口说明可参考[cryptoFramework API参考](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md)。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
```

## CertResult

 表示执行结果的枚举。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                  | 值   | 说明                          |
| --------------------------------------| -------- | -----------------------------|
| INVALID_PARAMS                        | 401      | 非法入参。                    |
| NOT_SUPPORT                           | 801      | 操作不支持。                  |
| ERR_OUT_OF_MEMORY                     | 19020001 | 内存错误。                    |
| ERR_RUNTIME_ERROR                     | 19020002 | 运行时外部错误。              |
| ERR_CRYPTO_OPERATION                  | 19030001 | 调用三方算法库API出错。       |
| ERR_CERT_SIGNATURE_FAILURE            | 19030002 | 证书签名验证错误。            |
| ERR_CERT_NOT_YET_VALID                | 19030003 | 证书尚未生效。                |
| ERR_CERT_HAS_EXPIRED                  | 19030004 | 证书过期。                   |
| ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY | 19030005 | 无法获取证书的颁发者。        |
| ERR_KEYUSAGE_NO_CERTSIGN              | 19030006 | 证书的秘钥用途不含证书签名。   |
| ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE     | 19030007 |  证书的秘钥用途不含数字签名。  |
| ERR_MAYBE_WRONG_PASSWORD<sup>18+</sup>              | 19030008 | 私钥密码错误。                |

## DataBlob
buffer数组。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert
| 名称           | 类型           | 可读 | 可写 | 说明              |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | 是   | 是   | 数据。    |

## DataArray

buffer数组的列表。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert
| 名称           | 类型           | 可读 | 可写 | 说明               |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Array\<Uint8Array>     | 是   | 是   | 数据列表。    |

## EncodingFormat

 表示证书编码格式的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| FORMAT_DER | 0      | DER格式。 |
| FORMAT_PEM | 1      | PEM格式。 |
| FORMAT_PKCS7<sup>11+</sup> | 2 | PKCS7格式。 |

## EncodingBaseFormat<sup>18+</sup>

 表示生成CSR的编码格式的枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| PEM | 0      | PEM格式。 |
| DER | 1      | DER格式。 |

## CsrAttribute<sup>18+</sup>
 表示生成CSR的编码格式配置参数中的拓展。

openssl中规定了拓展类型，例如challengePassword、keyUsage等。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| type | 指定的拓展类型 | openssl指定的拓展类型。 |
| value | 拓展值 | 拓展值。 |

## CsrGenerationConfig<sup>18+</sup>
RSA私钥生成CSR时的配置参数，包含主体、拓展、摘要算法、输出格式等。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| subject | [X500DistinguishedName](#x500distinguishedname12) | 是   | 是   | X509定义的Name类型的对象。 |
| mdName | string | 是   | 是   | 摘要算法名。 |
| attributes | [CsrAttribute](#csrattribute18) | 是   | 是   | 拓展。 |
| outFormat | [EncodingBaseFormat](#encodingbaseformat18) | 是   | 是   | 输出类型。 |

> **说明：**
>
> - subject是X509定义的Name类型的对象。
>
> - mdName是摘要算法名，当前支持SHA1、SHA256、SHA384、SHA512。
>
> - attributes是可选参数，可以指定openssl中规定的拓展类型跟拓展值生成CSR。例如challengePassword、keyUsage等。
>
> - outFormat指定输出CSR的格式，若不指定默认为PEM格式。

## CertItemType<sup>10+</sup>

 表示获取证书字段的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                             | 值   | 说明                           |
| -------------------------------- | ---- | ------------------------------ |
| CERT_ITEM_TYPE_TBS               | 0    | 表示获取证书的待签名信息。     |
| CERT_ITEM_TYPE_PUBLIC_KEY        | 1    | 表示获取证书的公钥信息。       |
| CERT_ITEM_TYPE_ISSUER_UNIQUE_ID  | 2    | 表示获取证书的颁发者唯一编号。 |
| CERT_ITEM_TYPE_SUBJECT_UNIQUE_ID | 3    | 表示获取证书的主体唯一编号。   |
| CERT_ITEM_TYPE_EXTENSIONS        | 4    | 表示获取证书的扩展域信息。     |

## ExtensionOidType<sup>10+</sup>

 表示获取扩展域中对象标识符类型的枚举。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                          | 值   | 说明                                          |
| ----------------------------- | ---- | --------------------------------------------- |
| EXTENSION_OID_TYPE_ALL        | 0    | 表示获取扩展域中所有的对象标识符。            |
| EXTENSION_OID_TYPE_CRITICAL   | 1    | 表示获取扩展域中critical为true的对象标识符。  |
| EXTENSION_OID_TYPE_UNCRITICAL | 2    | 表示获取扩展域中critical为false的对象标识符。 |

## ExtensionEntryType<sup>10+</sup>

 表示获取扩展域中对象类型的枚举。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                | 值   | 说明                         |
| ----------------------------------- | ---- | ---------------------------- |
| EXTENSION_ENTRY_TYPE_ENTRY          | 0    | 表示获取整个对象。           |
| EXTENSION_ENTRY_TYPE_ENTRY_CRITICAL | 1    | 表示获取对象的critical属性。 |
| EXTENSION_ENTRY_TYPE_ENTRY_VALUE    | 2    | 表示获取对象的数据。         |

## EncodingType<sup>12+</sup>

 表示获取X509证书主体名称编码格式的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| ENCODING_UTF8 | 0      | UTF8编码格式。 |

## EncodingBlob

带编码格式的证书二进制数组。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 可读 | 可写 | 说明                           |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------ |
| data           | Uint8Array                        | 是   | 是   | 传入的证书数据。 |
| encodingFormat | [EncodingFormat](#encodingformat) | 是   | 是   | 指明证书编码格式。             |


## CertChainData

证书链数据，在证书链校验时，作为入参传入。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| data           | Uint8Array                        | 是   | 是   | 证书数据，按照长度(2字节)-数据的形式传入，如：08ABCDEFGH07ABCDEFG,第一本证书，前2个字节表示证书的长度为8字节，后面附加8字节的证书数据；第2本证书前2个字节表示证书的长度为7字节，后面附加7字节的证书数据。 |
| count          | number                            | 是   | 是   | 传入的数据中，包含的证书数量。                               |
| encodingFormat | [EncodingFormat](#encodingformat) | 是   | 是   | 指明证书编码格式。                                           |

## GeneralNameType<sup>12+</sup>

表示证书主体用途的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 值                              | 说明               |
| -------------- | --------------------------------- | ------------------ |
| GENERAL_NAME_TYPE_OTHER_NAME | 0 |  表示其他名称。  |
| GENERAL_NAME_TYPE_RFC822_NAME | 1 |  表示电子邮件地址。  |
| GENERAL_NAME_TYPE_DNS_NAME | 2 |  表示一个DNS名称。  |
| GENERAL_NAME_TYPE_X400_ADDRESS | 3 |  表示X.400地址。  |
| GENERAL_NAME_TYPE_DIRECTORY_NAME | 4 |  表示一个目录名称。  |
| GENERAL_NAME_TYPE_EDI_PARTY_NAME | 5 |  表示特定的EDI实体。  |
| GENERAL_NAME_TYPE_UNIFORM_RESOURCE_ID | 6 |  表示一个统一资源标识符。  |
| GENERAL_NAME_TYPE_IP_ADDRESS | 7 |  表示一个IP地址。  |
| GENERAL_NAME_TYPE_REGISTERED_ID | 8 |  表示一个已注册的对象标识符。  |

## GeneralName<sup>12+</sup>

用于表示证书主体信息对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| type | [GeneralNameType](#generalname12)    | 是 |  指定具体的证书主体类型。  |
| name | Uint8Array    | 否  |  指定具体的证书主体DER格式内容。  |

## X509CertMatchParameters<sup>11+</sup>

用于匹配证书的过滤参数。如果参数中任一项都未指定，则匹配所有证书。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| x509Cert | [X509Cert](#x509cert)    | 否 |  指定具体的证书对象。  |
| validDate | string    | 否  |  指定证书有效期。  |
| issuer | Uint8Array | 否  | 指定证书颁发者，为DER编码格式。 |
| keyUsage | Array\<boolean> | 否  | 指定是否需要匹配密钥用途。 |
| serialNumber | bigint    | 否  |  指定证书的序列号。  |
| subject | Uint8Array | 否  | 指定证书主题，DER编码格式。 |
| publicKey | [DataBlob](#datablob) | 否  | 指定证书公钥，DER编码格式。 |
| publicKeyAlgID | string | 否  | 指定证书公钥的算法。 |
| subjectAlternativeNames<sup>12+</sup> | Array\<[GeneralName](#generalname12)> | 否  | 指定证书主体名称。 |
| matchAllSubjectAltNames<sup>12+</sup> | boolean | 否  | 指定是否需要匹配证书主体名称。 |
| authorityKeyIdentifier<sup>12+</sup> | Uint8Array | 否  | 指定证书颁发机构秘钥。 |
| minPathLenConstraint<sup>12+</sup> | number | 否  | 指定证书CA路径长度。 |
| extendedKeyUsage<sup>12+</sup> | Array\<string> | 否  | 指定证书扩展用途。 |
| nameConstraints<sup>12+</sup> | Uint8Array | 否  | 指定证书的使用者名称。 |
| certPolicy<sup>12+</sup> | Array\<string> | 否  | 指定证书策略。 |
| privateKeyValid<sup>12+</sup> | string | 否  | 指定证书私钥有效期。 |
| subjectKeyIdentifier<sup>12+</sup> | Uint8Array | 否  | 指定证书公钥。 |

## X509CRLMatchParameters<sup>11+</sup>

用于匹配证书吊销列表的过滤参数。如果参数中任一项都未指定，则匹配所有证书吊销列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| issuer | Array\<Uint8Array> | 否  | 指定颁发者作为过滤条件, 至少要匹配到其中一个issuer。 |
| x509Cert | [X509Cert](#x509cert) | 否  | 指定具体的证书对象作为过滤条件, 判断该证书是否在CRL列表中。 |
| updateDateTime<sup>12+</sup> | string | 否  | 指定证书更新时间。 |
| maxCRL<sup>12+</sup> | bigint | 否  | 指定CRL个数最大值。 |
| minCRL<sup>12+</sup> | bigint | 否  | 指定CRL个数最小值。 |

## CertChainBuildParameters<sup>12+</sup>

用于指定证书链创建参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| certMatchParameters | [X509CertMatchParameters](#x509certmatchparameters11) | 是  | 指定过滤条件。 |
| maxLength | number | 否  | 指定最终证书链中CA证书的最大长度。 |
| validationParameters | [CertChainValidationParameters](#certchainvalidationparameters11) | 是  | 指定验证条件。 |

## CertChainBuildResult<sup>12+</sup>

用于指定证书链创建结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称           | 类型                              | 必填 | 说明               |
| -------------- | --------------------------------- | ---- | ------------------ |
| certChain | [X509CertChain](#x509certchain11) | 是  | 生成的证书链对象。 |
| validationResult | [CertChainValidationResult](#certchainvalidationresult11) | 是  | 指定最终证书链的最大长度。 |

## X509TrustAnchor<sup>11+</sup>

表示X509信任锚，用于校验证书链。使用信任锚中的证书或者公钥作为可信根，对证书链进行校验。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称      | 类型                  | 可读 | 可写 | 说明                        |
| --------- | --------------------- | ---- | ---- | --------------------------- |
| CACert    | [X509Cert](#x509cert) | 是   | 是   | 信任的CA证书。              |
| CAPubKey  | Uint8Array            | 是   | 是   | 信任的CA证书公钥, DER格式。 |
| CASubject | Uint8Array            | 是   | 是   | 信任的CA证书主题, DER格式。 |
| nameConstraints<sup>12+</sup> | Uint8Array      | 是   | 是   | 名称约束, DER格式。 |

## RevocationCheckOptions<sup>12+</sup>

 表示证书链在线校验证书吊销状态选项的枚举。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                  | 值   | 说明                          |
| --------------------------------------| -------- | -----------------------------|
| REVOCATION_CHECK_OPTION_PREFER_OCSP | 0 | 优先采用OCSP进行校验，默认采用CRL校验。 |
| REVOCATION_CHECK_OPTION_ACCESS_NETWORK | 1 | 支持通过访问网络获取CRL或OCSP响应进行吊销状态的校验，默认为关闭。 |
| REVOCATION_CHECK_OPTION_FALLBACK_NO_PREFER | 2 | 当ACCESS_NETWORK选项打开时有效，如果优选的校验方法由于网络原因导致无法校验证书状态，则采用备选的方案进行校验。 |
| REVOCATION_CHECK_OPTION_FALLBACK_LOCAL | 3 | 当ACCESS_NETWORK选项打开时有效，如果在线获取CRL和OCSP响应都由于网络的原因导致无法校验证书状态，则采用本地设置的CRL和OCSP响应进行校验。 |

## ValidationPolicyType<sup>12+</sup>

 表示证书链在线校验策略的枚举。

 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                  | 值   | 说明                          |
| --------------------------------------| -------- | -----------------------------|
| VALIDATION_POLICY_TYPE_X509 | 0 | 默认值，不需要校验证书中的sslHostname或dNSName。 |
| VALIDATION_POLICY_TYPE_SSL | 1 | 需要校验证书中的sslHostname或dNSName。 |

## KeyUsageType<sup>12+</sup>

 表示证书中密钥用途的枚举。
 **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

 **系统能力：** SystemCapability.Security.Cert

| 名称                                  | 值   | 说明                          |
| --------------------------------------| -------- | -----------------------------|
| KEYUSAGE_DIGITAL_SIGNATURE | 0 | 证书持有者可以用证书中包含的私钥进行数字签名操作。 |
| KEYUSAGE_NON_REPUDIATION | 1 | 证书持有者不可否认使用证书中包含的私钥进行的数字签名操作。 |
| KEYUSAGE_KEY_ENCIPHERMENT | 2 | 证书持有者可以使用证书中包含的公钥进行密钥加密操作。 |
| KEYUSAGE_DATA_ENCIPHERMENT | 3 | 证书持有者可以使用证书中包含的公钥进行数据加密操作。 |
| KEYUSAGE_KEY_AGREEMENT | 4 | 证书持有者可以使用证书中包含的私钥进行密钥协商操作。 |
| KEYUSAGE_KEY_CERT_SIGN | 5 | 证书持有者可以使用证书中包含的私钥对其他证书进行签名。 |
| KEYUSAGE_CRL_SIGN | 6 | 证书持有者可以使用证书中包含的私钥对证书吊销列表（CRL）进行签名。 |
| KEYUSAGE_ENCIPHER_ONLY | 7 | 证书持有者只能进行加密操作，不能进行解密操作。 |
| KEYUSAGE_DECIPHER_ONLY | 8 | 证书持有者只能进行解密操作，不能进行加密操作。 |

## RevocationCheckParameter<sup>12+</sup>

表示证书链校验证书吊销状态的参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                              | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| ocspRequestExtension | Array\<Uint8Array> | 否   | 表示发送OCSP请求的扩展字段。|
| ocspResponderURI | string | 否   | 表示用于OCSP请求的备选服务器URL地址，支持HTTP/HTTPS，具体配置由与服务器协商决定。 |
| ocspResponderCert | [X509Cert](#x509cert)  | 否   | 表示用于OCSP响应的签名校验的签名证书。 |
| ocspResponses | Uint8Array | 否   | 表示用于OCSP服务器响应的备选数据。 |
| crlDownloadURI | string | 否   | 表示用于CRL请求的备选下载地址。 |
| options | Array\<[RevocationCheckOptions](#revocationcheckoptions12)> | 否   | 表示证书吊销状态查询的策略组合。 |
| ocspDigest | string | 否   | 表示OCSP通信时创建证书ID使用的哈希算法。默认为SHA256，支持可配置MD5、SHA1、SHA224、SHA256、SHA384、SHA512算法。 |

## CertChainValidationParameters<sup>11+</sup>

表示证书链校验的参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                              | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| date         | string                                            | 否   | 表示需要校验证书的有效期。             |
| trustAnchors | Array\<[X509TrustAnchor](#x509trustanchor11)>     | 是   | 表示信任锚列表。                       |
| certCRLs     | Array\<[CertCRLCollection](#certcrlcollection11)> | 否   | 表示需要校验证书是否在证书吊销列表中。 |
| revocationCheckParam<sup>12+</sup>      | [RevocationCheckParameter](#revocationcheckparameter12) | 否   | 表示需要在线校验证证书吊销状态的参数对象。 |
| policy<sup>12+</sup>     | [ValidationPolicyType](#validationpolicytype12) | 否   | 表示需要校验证书的策略类型。 |
| sslHostname<sup>12+</sup> | string | 否   | 表示需要校验证书中主机名，与policy配合使用。 |
| keyUsage<sup>12+</sup>     | Array\<[KeyUsageType](#keyusagetype12)> | 否   | 表示需要校验证书中的密钥用途。 |

## CertChainValidationResult<sup>11+</sup>

表示证书链校验的返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称        | 类型                                  | 可读 | 可写 | 说明           |
| ----------- | ------------------------------------- | ---- | ---- | -------------- |
| trustAnchor | [X509TrustAnchor](#x509trustanchor11) | 是   | 否   | 表示信任锚。   |
| entityCert  | [X509Cert](#x509cert)                 | 是   | 否   | 表示实体证书。 |

## EncodingBaseFormat<sup>18+</sup>

编码基础格式。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称 | 值 | 说明               |
| ---- | --- | ------------------ |
| PEM  | 0   | 表示PEM格式。      |
| DER  | 1   | 表示DER格式。      |

## Pkcs12Data<sup>18+</sup>

表示返回P12文件的解析后的证书、私钥及其他证书合集。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                              | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| privateKey   | string \| Uint8Array                              | 否   | 表示P12文件解析后的私钥。             |
| cert         | [X509Cert](#x509cert)                             | 否   | 表示P12文件解析后的证书。                       |
| otherCerts   | Array\<[X509Cert](#x509cert)>                     | 否   | 表示P12文件解析后的其他证书合集。 |

## Pkcs12ParsingConfig<sup>18+</sup>

表示解析P12文件的配置。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                              | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| password     | string                                            | 是   | 表示P12文件的密码。             |
| needsPrivateKey  | boolean                                       | 否   | 表示是否获取私钥。默认为true。                       |
| privateKeyFormat |  [EncodingBaseFormat](#encodingbaseformat18)                      | 否   | 表示获取私钥的格式。默认为PEM。 |
| needsCert    | boolean                                           | 否   | 表示是否获取证书。默认为true。 |
| needsOtherCerts  | boolean                                       | 否   | 表示是否获取其他证书合集。默认为false。 |

## CmsContentType<sup>18+</sup>

表示Cms内容类型的枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称                                  | 值   | 说明                          |
| --------------------------------------| -------- | -----------------------------|
| SIGNED_DATA | 0 | 签名数据。 |

## CmsContentDataFormat<sup>18+</sup>

表示Cms内容数据格式的枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称   | 值 | 说明                     |
| ------ | --- | ------------------------ |
| BINARY | 0   | 表示二进制数据格式。     |
| TEXT   | 1   | 表示文本数据格式。       |

## CmsFormat<sup>18+</sup>

表示Cms签名格式的枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称 | 值 | 说明               |
| ---- | --- | ------------------ |
| PEM  | 0   | 表示PEM格式。      |
| DER  | 1   | 表示DER格式。      |

## PrivateKeyInfo<sup>18+</sup>

表示私钥信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                              | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| key          | string \| Uint8Array                     | 是   | 未加密或加密的私钥，支持PEM或DER格式。 |
| password     | string                                  | 否   | 私钥的密码，如果私钥是加密的。         |

## CmsSignerConfig<sup>18+</sup>

表示Cms签名者的配置选项。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称         | 类型                                                  | 必填 | 说明                                   |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| mdName                | string              | 是   | 消息摘要算法的名称，例如 "SHA384", 当前支持"SHA1"、"SHA256"、"SHA384"、"SHA512"。                 |
| addCert               | boolean            | 否   | 是否添加证书。默认为true。                             |
| addAttr               | boolean            | 否   | 是否添加签名属性。默认为true。           |
| addSmimeCapAttr       | boolean            | 否   | 是否将SMIME能力添加到Cms对象。默认为true。            |

## CmsGeneratorOptions<sup>18+</sup>

表示生成Cms签名结果的配置选项。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称                  | 类型                          | 必填 | 说明                                                   |
| --------------------- | ----------------------------- | ---- | ------------------------------------------------------ |
| contentDataFormat     | [CmsContentDataFormat](#cmscontentdataformat18)               | 否   | 内容数据的格式。默认为CmsContentDataFormat.BINARY。   |
| outFormat             | [CmsFormat](#cmsformat18)                          | 否   | Cms最终数据的输出格式。默认为DER。         |
| isDetached     | boolean                            | 否   | Cms最终数据是否不包含原始数据。默认为false。         |

## cert.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

表示创建X509证书对象，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | 是   | X509证书序列化数据。         |
| callback | AsyncCallback\<[X509Cert](#x509cert)> | 是   | 回调函数，表示X509证书对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
  }
});
```

## cert.createX509Cert

createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>

表示创建X509证书对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明               |
| -------- | ----------------------------- | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据。 |

**返回值：**

| 类型     | 说明             |
| ------- | ---------------- |
| Promise\<[X509Cert](#x509cert)> | 表示X509证书对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## X509Cert

X509证书类。

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对证书验签，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| key      | [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | 是   | 用于验签的公钥对象。                                           |
| callback | AsyncCallback\<void> | 是   | 回调函数，使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19030001 | crypto operation error.      |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');

    // 业务需通过上级X509Cert证书对象（或当前证书对象为自签名的证书）的getPublicKey获取PubKey。
    try {
      let pubKey = x509Cert.getPublicKey();

      // 验证证书签名。
      x509Cert.verify(pubKey, (err, data) => {
        if (err) {
          console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        } else {
          console.log('verify success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对证书验签，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| key    | [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | 是   | 用于验签的公钥对象。 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19030001 | crypto operation error.      |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');

  try {
    // 业务需通过上级X509Cert证书对象（或当前证书对象为自签名的证书）的getPublicKey获取PubKey。
    let pubKey = x509Cert.getPublicKey();
    x509Cert.verify(pubKey).then(result => {
      console.log('verify success');
    }).catch((error: BusinessError) => {
      console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    });
  } catch (err) {
    console.error('get public key failed');
  }
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书序列化数据，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                             |
| -------- | --------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数，表示X509证书序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    x509Cert.getEncoded((error, data) => {
      if (error) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书序列化数据，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                   |
| --------------------------------------- | ---------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示X509证书序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};
cert.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');
  x509Cert.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getPublicKey

getPublicKey() : cryptoFramework.PubKey

表示获取X509证书公钥。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | X509证书公钥对象：仅用于X509Cert的verify接口。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let pubKey = x509Cert.getPublicKey();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### checkValidityWithDate

checkValidityWithDate(date: string) : void

表示检查X509证书有效期。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型            | 必填 | 说明        |
| -------- | -------------- | ---- | ---------- |
| date     | string         | 是   | 日期，为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|
| 19030003 | the certificate has not taken effect.                                     |
| 19030004 | the certificate has expired.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');

    let date = '231001000001Z';
    // Verify the certificate validity period.
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('checkValidityWithDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getVersion

getVersion() : number

表示获取X509证书版本。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| number | 表示X509证书版本。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};
cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let version = x509Cert.getVersion();
  }
});
```

### getSerialNumber<sup>(deprecated)</sup>

getSerialNumber() : number

表示获取X509证书序列号。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[getCertSerialNumber](#getcertserialnumber10)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 表示X509证书序列号。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let serialNumber = x509Cert.getSerialNumber();
  }
});
```

### getCertSerialNumber<sup>10+</sup>

getCertSerialNumber() : bigint

表示获取X509证书序列号。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| bigint | 表示X509证书序列号。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020002 | runtime error.                                    |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let serialNumber = x509Cert.getCertSerialNumber();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getCertSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getIssuerName

getIssuerName() : DataBlob

表示获取X509证书颁发者名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                   |
| --------------------- | ---------------------- |
| [DataBlob](#datablob) | 表示X509证书颁发者名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let issuerName = x509Cert.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSubjectName

getSubjectName(encodingType?: EncodingType) : DataBlob

表示获取X509证书主体名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| encodingType | [EncodingType](#encodingtype12)     | 否   |  编码类型。设置参数表示获取UTF8格式编码；不设置默认获取ASCII格式编码。<br>API 12后支持设置此参数。  |

**返回值**：

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书主体名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Incorrect parameter types;<br>2. Parameter verification failed.           |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let subjectName = x509Cert.getSubjectName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
    try {
      let subjectNameutf8 = x509Cert.getSubjectName(cert.EncodingType.ENCODING_UTF8);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectNameUtf8 failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNotBeforeTime

getNotBeforeTime() : string

表示获取X509证书有效期起始时间。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 表示X509证书有效期起始时间，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let notBefore = x509Cert.getNotBeforeTime();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNotAfterTime

getNotAfterTime() : string

表示获取X509证书有效期截止时间。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 表示X509证书有效期截止时间，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let notAfter = x509Cert.getNotAfterTime();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotAfterTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignature

getSignature() : DataBlob

表示获取X509证书签名数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书签名数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let signature = x509Cert.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName

getSignatureAlgName() : string

表示获取X509证书签名算法名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 表示X509证书签名算法名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgName = x509Cert.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid

getSignatureAlgOid() : string

表示获取X509证书签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                              |
| ------ | --------------------------------- |
| string | 表示X509证书签名算法对象标志符OID。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgOid = x509Cert.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

表示获取X509证书签名算法参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 表示X509证书签名算法参数。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 801 | this operation is not supported. |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgParams = x509Cert.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getKeyUsage

getKeyUsage() : DataBlob

表示获取X509证书秘钥用途。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书秘钥用途。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let keyUsage = x509Cert.getKeyUsage();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getKeyUsage failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getExtKeyUsage

getExtKeyUsage() : DataArray

表示获取X509证书扩展秘钥用途。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                     |
| ----------------------- | ------------------------ |
| [DataArray](#dataarray) | 表示X509证书扩展秘钥用途。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let extKeyUsage = x509Cert.getExtKeyUsage();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getBasicConstraints

getBasicConstraints() : number

表示获取X509证书基本约束。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 表示X509证书基本约束。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let basicConstraints = x509Cert.getBasicConstraints();
  }
});
```

### getSubjectAltNames

getSubjectAltNames() : DataArray

表示获取X509证书主体可选名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                     |
| ----------------------- | ------------------------ |
| [DataArray](#dataarray) | 表示X509证书主体可选名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let subjectAltNames = x509Cert.getSubjectAltNames();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectAltNames failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getIssuerAltNames

getIssuerAltNames() : DataArray

表示获取X509证书颁发者可选名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                       |
| ----------------------- | -------------------------- |
| [DataArray](#dataarray) | 表示X509证书颁发者可选名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let issuerAltNames = x509Cert.getIssuerAltNames();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerAltNames failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getItem<sup>10+</sup>

getItem(itemType: CertItemType) : DataBlob

表示获取X509证书对应的字段。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| itemType | [CertItemType](#certitemtype10) | 是   | 表示需要获取的证书字段。 |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [DataBlob](#datablob) | 表示X509证书对应的字段，返回值为DER格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let tbs = x509Cert.getItem(cert.CertItemType.CERT_ITEM_TYPE_TBS);
      let pubKey = x509Cert.getItem(cert.CertItemType.CERT_ITEM_TYPE_PUBLIC_KEY);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getItem failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```
### match<sup>11+</sup>

match(param: X509CertMatchParameters): boolean

判断证书是否与输入参数匹配。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | 是   | 表示需要匹配的参数。 |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| boolean | 当参数匹配时，该方法返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<cert.X509Cert> {
  let certData =  '-----BEGIN CERTIFICATE-----\n' +
  'MIIDTTCCAjWgAwIBAgIBAzANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
  'IENBMB4XDTI0MDMxOTAyMDM1NFoXDTM0MDMxNzAyMDM1NFowETEPMA0GA1UEAwwG\n' +
  'ZGV2aWNlMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAuoGk2J0aKWTP\n' +
  'J3D7lS3oFdME3MMA1z0Y0ftthrtUKybE2xh8P90ztMV73bewmgAPqiApqhaWEZM/\n' +
  '6DSLc/MxbOeYjg6njveJIu721gchiuB2PFikDFSWlcLOJNw+CgBx77Ct3KllivHs\n' +
  'oi/gjuxrWiF/3VhbBErPNj/fw9se3pVrFRXIFdkcybtom2mUmkcxDfSg587SO14i\n' +
  'ZzXGM6nhMzYWXxLho6SJrsnzfs4pD6ifksWmY4089zitqsN+9jQXafY1+/sh1mgu\n' +
  'FvAwg9IbigGOBIiF8t5qdNGpqCHXbEHblNCWfT4fVNDV0Vc9pByjZaMYEGMhpz+6\n' +
  'lxlc2CqbNQIDAQABo4GuMIGrMAkGA1UdEwQCMAAwHQYDVR0OBBYEFAEVpuP+pPpg\n' +
  'kr3dA3aV2XdFZ9rGMB8GA1UdIwQYMBaAFHRb+SgJu8O0UYdRBkszePocqxbYMB0G\n' +
  'A1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjALBgNVHQ8EBAMCB4AwMgYIKwYB\n' +
  'BQUHAQEEJjAkMCIGCCsGAQUFBzABhhZodHRwczovLzEyNy4wLjAuMTo5OTk5MA0G\n' +
  'CSqGSIb3DQEBCwUAA4IBAQBjM1agcDcgVHsD0dS39gxtlyRbZRvDcW3YsdwgpN6S\n' +
  'e4wGzdZbhsiZv7y3+PSuozKwp5Yjn+UqnnEz7QuTGJRt/pzHDVY3QceNvlx2HPRe\n' +
  'fECS4bpGLcM5B17oZZjE4HenIrGmigXnnwYL5TjhC4ybtddXPYv/M6z2eFCnfQNa\n' +
  'zFwz8LJ7ukWvf5koBqcHq2zsuVByOIPXLIrAJPtMmBb/pHCFt8hxOxwqujdrxz16\n' +
  'pe5LQUYzvG1YCxw3Ye9OrM1yXJQr/4KYncQC1yQQo+UK7NsDRK30PsMEYxhierLA\n' +
  'JKyPn1xSlOJiGa2rRn/uevmEOhfagj5TtprU9Gu1+nZo\n' +
  '-----END CERTIFICATE-----\n';

  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function matchX509Cert() {
  const x509Cert = await createX509Cert();
  try {
    // 需业务自行赋值。
    const param: cert.X509CertMatchParameters = {
      x509Cert,
      validDate: '20241121074700Z',
      keyUsage: [true, false, false, false, false, false, false, false, false],
      publicKeyAlgID: '1.2.840.113549.1.1.1'
    };
    const result = x509Cert.match(param);
    console.log('call x509Cert match success');
  } catch (err) {
    console.error('call x509Cert match failed');
  }
}
```

### getCRLDistributionPoint<sup>12+</sup>

getCRLDistributionPoint(): DataArray

获取X509证书CRL的分发点统一资源标识符。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                    | 说明                       |
| ----------------------- | -------------------------- |
| [DataArray](#dataarray) | 表示X509证书CRL的分发点统一资源标识符。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certData = "-----BEGIN CERTIFICATE-----\n" +
  "MIIB/jCCAaSgAwIBAgICA+gwCgYIKoZIzj0EAwIwLDELMAkGA1UEBhMCQ04xDTAL\n" +
  "BgNVBAoMBHRlc3QxDjAMBgNVBAMMBXN1YmNhMB4XDTIzMTAwNzA0MDEwOFoXDTMz\n" +
  "MTAwNDA0MDEwOFowLDELMAkGA1UEBhMCQ04xDTALBgNVBAoMBHRlc3QxDjAMBgNV\n" +
  "BAMMBWxvY2FsMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEZDPvdlJI6Yv4fiaR\n" +
  "nQHcusXVbukk90mQ0rBGOYRikFvgvm5cjTdaUGcQKEtwYIKDQl5n6Pf7ElCJ7GRz\n" +
  "raWZ+qOBtTCBsjAJBgNVHRMEAjAAMCwGCWCGSAGG+EIBDQQfFh1PcGVuU1NMIEdl\n" +
  "bmVyYXRlZCBDZXJ0aWZpY2F0ZTAdBgNVHQ4EFgQU63Gbl8gIsUn0VyZ4rya3PCjm\n" +
  "sfEwHwYDVR0jBBgwFoAU77mynM0rz1SD43DQjleWM7bF+MEwNwYDVR0fBDAwLjAs\n" +
  "oCqgKIYmaHR0cDovL3Rlc3QudGVzdENSTGRwLmNvbS9DUkxfRFBfMS5jcmwwCgYI\n" +
  "KoZIzj0EAwIDSAAwRQIhAISKHH9u221mBgdDWfll3loLvEHJ3or9NUO5Zn6SrX6L\n" +
  "AiAtRlOa6/mTD68faQTdhsAaQP955QfW34B4yFqU2Bq72A==\n" +
  "-----END CERTIFICATE-----\n";

  // 证书二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certGetCRLDistributionPoint() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
    console.log('createX509Cert success');
    let point = x509Cert.getCRLDistributionPoint();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getIssuerX500DistinguishedName<sup>12+</sup>

getIssuerX500DistinguishedName(): X500DistinguishedName

获取颁发者的X509可分辨名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [X500DistinguishedName](#x500distinguishedname12) | X509的可分辨对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID1TCCAr2gAwIBAgIITXr1++kFUU4wDQYJKoZIhvcNAQELBQAwcDELMAkGA1UE\n" +
    "BhMCQ04xEjAQBgNVBAgTCWd1YW5nZG9uZzERMA8GA1UEBxMIc2hlbnpoZW4xEjAQ\n" +
    "BgNVBAoTCXRlc3RTZWNDYTESMBAGA1UECxMJdGVzdFNlY0NhMRIwEAYDVQQDEwl0\n" +
    "ZXN0U2VjQ2EwHhcNMjMxMjIxMDAwMDAwWhcNMjcxMjIwMjM1OTU5WjBxMQswCQYD\n" +
    "VQQGEwJDTjEOMAwGA1UECBMFZ2Fuc3UxEDAOBgNVBAcTB2xhbnpob3UxFDASBgNV\n" +
    "BAoTC3Rlc3RUaGlyZENhMRQwEgYDVQQLEwt0ZXN0VGhpcmRDYTEUMBIGA1UEAxML\n" +
    "dGVzdFRoaXJkQ2EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDJMKSq\n" +
    "Fn4G4EJATauw+4s+n/JbINBAiuhzURzzdt2T8JJQLDV9RHj4mZt84yv6lqEpl2fm\n" +
    "gIClfu173pEV51/PSq5IaV481u/Dz/OTy9TwfxmIXAWdNpyodDOg4I9K7LC01ge8\n" +
    "xxyKFi7k7m2eTGA4dYQM0E0AEXzCpg2JN3IIIPhzHCIVJmYjcbVxiaFkvT4ZFFUk\n" +
    "4rDSbAQdn6dJ29msrFm8iGhMGC/bzq9Bii38Qg4y4o89QYiboRWCxv3XfuibT+jw\n" +
    "O3pmfsFuT8/bKOWVm94FmRxiKuj6iE8UVewxtByzDgAsBtJKDjaCv3IkqfbIu+sq\n" +
    "/eeJkVJRJXAP3ZpLAgMBAAGjcjBwMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYE\n" +
    "FIxvPSwEmjOMW10H+gn2gy5HvMmMMAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEE\n" +
    "BAMCAAcwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTANBgkqhkiG9w0B\n" +
    "AQsFAAOCAQEAWu0u72g5y1weexPoJQnUgcwVtuC+/tTS9YvyCtKYE91gn97LSWn9\n" +
    "mXXGmLceU27B8JwhER9JeiQO1SUdDcvlfb5vt6eB+5cbZcgeERUBP8t0znh7DbMg\n" +
    "4TFjt9gZ970PZ1OlTBNPoZNRBKIox61KVUhiVKTVSbXlVP1yUF1uSlSq+0NYayHw\n" +
    "MnX1BeLxbAcAsTPYHjoeFJIrGkKlydLyt/8hDQzpLRW5uEUTjjqLh7vef0OaOP80\n" +
    "MmADt6ojRYvwdMDHF0ASJyupLQ+hiRLVadciK8Z5W34JGN2jwEw5X3nXyAgErIJZ\n" +
    "pqdTflnFLnSwy5M3QHB+xjYAcS9l1br2LA==\n" +
    "-----END CERTIFICATE-----\n"

  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

async function certGetIssuerX500DistinguishedName() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
    console.log('createX509Cert success');
    let name = x509Cert.getIssuerX500DistinguishedName();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getSubjectX500DistinguishedName<sup>12+</sup>

getSubjectX500DistinguishedName(): X500DistinguishedName

获取证书主题的X509可分辨名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [X500DistinguishedName](#x500distinguishedname12) | X509的可分辨对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID1TCCAr2gAwIBAgIITXr1++kFUU4wDQYJKoZIhvcNAQELBQAwcDELMAkGA1UE\n" +
    "BhMCQ04xEjAQBgNVBAgTCWd1YW5nZG9uZzERMA8GA1UEBxMIc2hlbnpoZW4xEjAQ\n" +
    "BgNVBAoTCXRlc3RTZWNDYTESMBAGA1UECxMJdGVzdFNlY0NhMRIwEAYDVQQDEwl0\n" +
    "ZXN0U2VjQ2EwHhcNMjMxMjIxMDAwMDAwWhcNMjcxMjIwMjM1OTU5WjBxMQswCQYD\n" +
    "VQQGEwJDTjEOMAwGA1UECBMFZ2Fuc3UxEDAOBgNVBAcTB2xhbnpob3UxFDASBgNV\n" +
    "BAoTC3Rlc3RUaGlyZENhMRQwEgYDVQQLEwt0ZXN0VGhpcmRDYTEUMBIGA1UEAxML\n" +
    "dGVzdFRoaXJkQ2EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDJMKSq\n" +
    "Fn4G4EJATauw+4s+n/JbINBAiuhzURzzdt2T8JJQLDV9RHj4mZt84yv6lqEpl2fm\n" +
    "gIClfu173pEV51/PSq5IaV481u/Dz/OTy9TwfxmIXAWdNpyodDOg4I9K7LC01ge8\n" +
    "xxyKFi7k7m2eTGA4dYQM0E0AEXzCpg2JN3IIIPhzHCIVJmYjcbVxiaFkvT4ZFFUk\n" +
    "4rDSbAQdn6dJ29msrFm8iGhMGC/bzq9Bii38Qg4y4o89QYiboRWCxv3XfuibT+jw\n" +
    "O3pmfsFuT8/bKOWVm94FmRxiKuj6iE8UVewxtByzDgAsBtJKDjaCv3IkqfbIu+sq\n" +
    "/eeJkVJRJXAP3ZpLAgMBAAGjcjBwMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYE\n" +
    "FIxvPSwEmjOMW10H+gn2gy5HvMmMMAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEE\n" +
    "BAMCAAcwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTANBgkqhkiG9w0B\n" +
    "AQsFAAOCAQEAWu0u72g5y1weexPoJQnUgcwVtuC+/tTS9YvyCtKYE91gn97LSWn9\n" +
    "mXXGmLceU27B8JwhER9JeiQO1SUdDcvlfb5vt6eB+5cbZcgeERUBP8t0znh7DbMg\n" +
    "4TFjt9gZ970PZ1OlTBNPoZNRBKIox61KVUhiVKTVSbXlVP1yUF1uSlSq+0NYayHw\n" +
    "MnX1BeLxbAcAsTPYHjoeFJIrGkKlydLyt/8hDQzpLRW5uEUTjjqLh7vef0OaOP80\n" +
    "MmADt6ojRYvwdMDHF0ASJyupLQ+hiRLVadciK8Z5W34JGN2jwEw5X3nXyAgErIJZ\n" +
    "pqdTflnFLnSwy5M3QHB+xjYAcS9l1br2LA==\n" +
    "-----END CERTIFICATE-----\n"

  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

async function certGetSubjectX500DistinguishedName() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
    console.log('createX509Cert success');
    let name = x509Cert.getSubjectX500DistinguishedName();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### toString<sup>12+</sup>

toString(): string

获取对象的字符串类型数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| string | 对象的字符串类型数据。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID1TCCAr2gAwIBAgIITXr1++kFUU4wDQYJKoZIhvcNAQELBQAwcDELMAkGA1UE\n" +
    "BhMCQ04xEjAQBgNVBAgTCWd1YW5nZG9uZzERMA8GA1UEBxMIc2hlbnpoZW4xEjAQ\n" +
    "BgNVBAoTCXRlc3RTZWNDYTESMBAGA1UECxMJdGVzdFNlY0NhMRIwEAYDVQQDEwl0\n" +
    "ZXN0U2VjQ2EwHhcNMjMxMjIxMDAwMDAwWhcNMjcxMjIwMjM1OTU5WjBxMQswCQYD\n" +
    "VQQGEwJDTjEOMAwGA1UECBMFZ2Fuc3UxEDAOBgNVBAcTB2xhbnpob3UxFDASBgNV\n" +
    "BAoTC3Rlc3RUaGlyZENhMRQwEgYDVQQLEwt0ZXN0VGhpcmRDYTEUMBIGA1UEAxML\n" +
    "dGVzdFRoaXJkQ2EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDJMKSq\n" +
    "Fn4G4EJATauw+4s+n/JbINBAiuhzURzzdt2T8JJQLDV9RHj4mZt84yv6lqEpl2fm\n" +
    "gIClfu173pEV51/PSq5IaV481u/Dz/OTy9TwfxmIXAWdNpyodDOg4I9K7LC01ge8\n" +
    "xxyKFi7k7m2eTGA4dYQM0E0AEXzCpg2JN3IIIPhzHCIVJmYjcbVxiaFkvT4ZFFUk\n" +
    "4rDSbAQdn6dJ29msrFm8iGhMGC/bzq9Bii38Qg4y4o89QYiboRWCxv3XfuibT+jw\n" +
    "O3pmfsFuT8/bKOWVm94FmRxiKuj6iE8UVewxtByzDgAsBtJKDjaCv3IkqfbIu+sq\n" +
    "/eeJkVJRJXAP3ZpLAgMBAAGjcjBwMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYE\n" +
    "FIxvPSwEmjOMW10H+gn2gy5HvMmMMAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEE\n" +
    "BAMCAAcwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTANBgkqhkiG9w0B\n" +
    "AQsFAAOCAQEAWu0u72g5y1weexPoJQnUgcwVtuC+/tTS9YvyCtKYE91gn97LSWn9\n" +
    "mXXGmLceU27B8JwhER9JeiQO1SUdDcvlfb5vt6eB+5cbZcgeERUBP8t0znh7DbMg\n" +
    "4TFjt9gZ970PZ1OlTBNPoZNRBKIox61KVUhiVKTVSbXlVP1yUF1uSlSq+0NYayHw\n" +
    "MnX1BeLxbAcAsTPYHjoeFJIrGkKlydLyt/8hDQzpLRW5uEUTjjqLh7vef0OaOP80\n" +
    "MmADt6ojRYvwdMDHF0ASJyupLQ+hiRLVadciK8Z5W34JGN2jwEw5X3nXyAgErIJZ\n" +
    "pqdTflnFLnSwy5M3QHB+xjYAcS9l1br2LA==\n" +
    "-----END CERTIFICATE-----\n"

  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

async function certToString() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
    console.log('createX509Cert success');
    console.info('certToString success: ' + JSON.stringify(x509Cert.toString()));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### hashCode<sup>12+</sup>

hashCode(): Uint8Array

获取DER格式数据的哈希值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Uint8Array | DER格式数据的哈希值。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID1TCCAr2gAwIBAgIITXr1++kFUU4wDQYJKoZIhvcNAQELBQAwcDELMAkGA1UE\n" +
    "BhMCQ04xEjAQBgNVBAgTCWd1YW5nZG9uZzERMA8GA1UEBxMIc2hlbnpoZW4xEjAQ\n" +
    "BgNVBAoTCXRlc3RTZWNDYTESMBAGA1UECxMJdGVzdFNlY0NhMRIwEAYDVQQDEwl0\n" +
    "ZXN0U2VjQ2EwHhcNMjMxMjIxMDAwMDAwWhcNMjcxMjIwMjM1OTU5WjBxMQswCQYD\n" +
    "VQQGEwJDTjEOMAwGA1UECBMFZ2Fuc3UxEDAOBgNVBAcTB2xhbnpob3UxFDASBgNV\n" +
    "BAoTC3Rlc3RUaGlyZENhMRQwEgYDVQQLEwt0ZXN0VGhpcmRDYTEUMBIGA1UEAxML\n" +
    "dGVzdFRoaXJkQ2EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDJMKSq\n" +
    "Fn4G4EJATauw+4s+n/JbINBAiuhzURzzdt2T8JJQLDV9RHj4mZt84yv6lqEpl2fm\n" +
    "gIClfu173pEV51/PSq5IaV481u/Dz/OTy9TwfxmIXAWdNpyodDOg4I9K7LC01ge8\n" +
    "xxyKFi7k7m2eTGA4dYQM0E0AEXzCpg2JN3IIIPhzHCIVJmYjcbVxiaFkvT4ZFFUk\n" +
    "4rDSbAQdn6dJ29msrFm8iGhMGC/bzq9Bii38Qg4y4o89QYiboRWCxv3XfuibT+jw\n" +
    "O3pmfsFuT8/bKOWVm94FmRxiKuj6iE8UVewxtByzDgAsBtJKDjaCv3IkqfbIu+sq\n" +
    "/eeJkVJRJXAP3ZpLAgMBAAGjcjBwMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYE\n" +
    "FIxvPSwEmjOMW10H+gn2gy5HvMmMMAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEE\n" +
    "BAMCAAcwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTANBgkqhkiG9w0B\n" +
    "AQsFAAOCAQEAWu0u72g5y1weexPoJQnUgcwVtuC+/tTS9YvyCtKYE91gn97LSWn9\n" +
    "mXXGmLceU27B8JwhER9JeiQO1SUdDcvlfb5vt6eB+5cbZcgeERUBP8t0znh7DbMg\n" +
    "4TFjt9gZ970PZ1OlTBNPoZNRBKIox61KVUhiVKTVSbXlVP1yUF1uSlSq+0NYayHw\n" +
    "MnX1BeLxbAcAsTPYHjoeFJIrGkKlydLyt/8hDQzpLRW5uEUTjjqLh7vef0OaOP80\n" +
    "MmADt6ojRYvwdMDHF0ASJyupLQ+hiRLVadciK8Z5W34JGN2jwEw5X3nXyAgErIJZ\n" +
    "pqdTflnFLnSwy5M3QHB+xjYAcS9l1br2LA==\n" +
    "-----END CERTIFICATE-----\n"

  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

async function certHashCode() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
    console.log('createX509Cert success');
    console.info('certHashCode success: ' + JSON.stringify(x509Cert.hashCode()));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getExtensionsObject<sup>12+</sup>

getExtensionsObject(): CertExtension

获取对应实体的扩展域DER格式数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [CertExtension](#certextension10) | 证书扩展域段类对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID1TCCAr2gAwIBAgIITXr1++kFUU4wDQYJKoZIhvcNAQELBQAwcDELMAkGA1UE\n" +
    "BhMCQ04xEjAQBgNVBAgTCWd1YW5nZG9uZzERMA8GA1UEBxMIc2hlbnpoZW4xEjAQ\n" +
    "BgNVBAoTCXRlc3RTZWNDYTESMBAGA1UECxMJdGVzdFNlY0NhMRIwEAYDVQQDEwl0\n" +
    "ZXN0U2VjQ2EwHhcNMjMxMjIxMDAwMDAwWhcNMjcxMjIwMjM1OTU5WjBxMQswCQYD\n" +
    "VQQGEwJDTjEOMAwGA1UECBMFZ2Fuc3UxEDAOBgNVBAcTB2xhbnpob3UxFDASBgNV\n" +
    "BAoTC3Rlc3RUaGlyZENhMRQwEgYDVQQLEwt0ZXN0VGhpcmRDYTEUMBIGA1UEAxML\n" +
    "dGVzdFRoaXJkQ2EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDJMKSq\n" +
    "Fn4G4EJATauw+4s+n/JbINBAiuhzURzzdt2T8JJQLDV9RHj4mZt84yv6lqEpl2fm\n" +
    "gIClfu173pEV51/PSq5IaV481u/Dz/OTy9TwfxmIXAWdNpyodDOg4I9K7LC01ge8\n" +
    "xxyKFi7k7m2eTGA4dYQM0E0AEXzCpg2JN3IIIPhzHCIVJmYjcbVxiaFkvT4ZFFUk\n" +
    "4rDSbAQdn6dJ29msrFm8iGhMGC/bzq9Bii38Qg4y4o89QYiboRWCxv3XfuibT+jw\n" +
    "O3pmfsFuT8/bKOWVm94FmRxiKuj6iE8UVewxtByzDgAsBtJKDjaCv3IkqfbIu+sq\n" +
    "/eeJkVJRJXAP3ZpLAgMBAAGjcjBwMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYE\n" +
    "FIxvPSwEmjOMW10H+gn2gy5HvMmMMAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEE\n" +
    "BAMCAAcwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTANBgkqhkiG9w0B\n" +
    "AQsFAAOCAQEAWu0u72g5y1weexPoJQnUgcwVtuC+/tTS9YvyCtKYE91gn97LSWn9\n" +
    "mXXGmLceU27B8JwhER9JeiQO1SUdDcvlfb5vt6eB+5cbZcgeERUBP8t0znh7DbMg\n" +
    "4TFjt9gZ970PZ1OlTBNPoZNRBKIox61KVUhiVKTVSbXlVP1yUF1uSlSq+0NYayHw\n" +
    "MnX1BeLxbAcAsTPYHjoeFJIrGkKlydLyt/8hDQzpLRW5uEUTjjqLh7vef0OaOP80\n" +
    "MmADt6ojRYvwdMDHF0ASJyupLQ+hiRLVadciK8Z5W34JGN2jwEw5X3nXyAgErIJZ\n" +
    "pqdTflnFLnSwy5M3QHB+xjYAcS9l1br2LA==\n" +
    "-----END CERTIFICATE-----\n"

  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

async function certGetExtensionsObject() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
    console.log('createX509Cert success');
    let object = x509Cert.getExtensionsObject();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.createCertExtension<sup>10+</sup>

createCertExtension(inStream : EncodingBlob, callback : AsyncCallback\<CertExtension>) : void

表示创建证书扩展域段的对象，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)                     | 是   | 表示证书扩展域段序列化数据。 |
| callback | AsyncCallback\<[CertExtension](#certextension10)> | 是   | 回调函数，表示扩展域段对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// 证书扩展域段二进制数据，需业务自行赋值。
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: cert.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob, (error, certExt) => {
  if (error) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
  }
});
```

## cert.createCertExtension<sup>10+</sup>

createCertExtension(inStream : EncodingBlob) : Promise\<CertExtension>

表示创建证书扩展域段的对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书扩展域段序列化数据。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CertExtension](#certextension10)> | 表示证书扩展域段对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 证书扩展域段二进制数据，需业务自行赋值。
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: cert.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob).then(certExt => {
  console.log('createCertExtension success');
}).catch((error: BusinessError) => {
  console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## CertExtension<sup>10+</sup>

证书扩展域段类。

### getEncoded<sup>10+</sup>

getEncoded() : EncodingBlob

表示获取证书扩展域段序列化数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                          | 说明                         |
| ----------------------------- | ---------------------------- |
| [EncodingBlob](#encodingblob) | 表示证书扩展域段序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 证书扩展域段二进制数据，需业务自行赋值。
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: cert.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob, (error, certExt) => {
  if (error) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let extEncodedBlob = certExt.getEncoded();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getEncoded failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getOidList<sup>10+</sup>

getOidList(valueType : ExtensionOidType) : DataArray

表示获取证书扩展域段对象标识符列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                                  | 必填 | 说明                           |
| --------- | ------------------------------------- | ---- | ------------------------------ |
| valueType | [ExtensionOidType](#extensionoidtype10) | 是   | 表示证书扩展域段对象标识符类型。 |

**返回值**：

| 类型                    | 说明                             |
| ----------------------- | -------------------------------- |
| [DataArray](#dataarray) | 表示证书扩展域段对象标识符列表。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 证书扩展域段二进制数据，需业务自行赋值。
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: cert.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob, (error, certExt) => {
  if (error) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let oidList = certExt.getOidList(cert.ExtensionOidType.EXTENSION_OID_TYPE_ALL);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getOidList failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getEntry<sup>10+</sup>

getEntry(valueType: ExtensionEntryType, oid : DataBlob) : DataBlob

表示获取证书扩展域段对象信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                                      | 必填 | 说明                             |
| --------- | ----------------------------------------- | ---- | -------------------------------- |
| valueType | [ExtensionEntryType](#extensionentrytype10) | 是   | 表示证书扩展域段获取的类型。       |
| oid       | [DataBlob](#datablob)                     | 是   | 表示证书扩展域段获取的对象标识符。 |

**返回值**：

| 类型                  | 说明                         |
| --------------------- | ---------------------------- |
| [DataBlob](#datablob) | 表示证书扩展域段对象的数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 证书扩展域段二进制数据，需业务自行赋值。
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: cert.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob, (error, certExt) => {
  if (error) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    let oid = new Uint8Array([0x32, 0x2e, 0x35, 0x2e, 0x32, 0x39, 0x2e, 0x31, 0x35]);
    let oidBlob: cert.DataBlob = {
      data: oid
    }
    try {
      let entry = certExt.getEntry(cert.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oidBlob);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getEntry failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```


### checkCA<sup>10+</sup>

checkCA() : number

表示校验证书是否为CA证书。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 当证书扩展域段中密钥用途包含签名用途，并且基本约束中cA字段为true时，表示证书为CA证书。如果不是CA，则返回-1；否则返回基本约束中的路径长度。如果证书是CA证书，但是基本约束中未给定路径长度，则返回-2，表示无路径长度限制。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 证书扩展域段二进制数据，需业务自行赋值。
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: cert.EncodingBlob = {
  data: extData,
  // 根据encodingData的格式进行赋值，仅支持FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};
cert.createCertExtension(encodingBlob, (error, certExt) => {
  if (error) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let res = certExt.checkCA();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext checkCA failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### hasUnsupportedCriticalExtension<sup>11+</sup>

hasUnsupportedCriticalExtension(): boolean

判断是否存在不支持的关键扩展。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                    |
| ------- | ------------------------------------------------------- |
| boolean | 当存在不支持的关键扩展时，该方法返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let encodingData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);
let encodingBlob: cert.EncodingBlob = {
  data: new Uint8Array(encodingData),
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob).then((extensionObj) => {
  console.log('createCertExtension success!');
  const result = extensionObj.hasUnsupportedCriticalExtension()
  console.log('has unsupported critical extension result is:' + result);
}).catch((err: BusinessError) => {
  console.error('createCertExtension failed');
});
```

## cert.createX509Crl<sup>(deprecated)</sup>

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

表示创建X509证书吊销列表的对象，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[cert.createX509CRL](#certcreatex509crl11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                | 必填 | 说明                           |
| -------- | ----------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)       | 是   | 表示证书吊销列表序列化数据。     |
| callback | AsyncCallback\<[X509Crl](#x509crldeprecated)> | 是   | 回调函数，表示证书吊销列表对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
  }
});
```

## cert.createX509Crl<sup>(deprecated)</sup>

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

表示创建X509证书吊销列表的对象，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[cert.createX509CRL](#certcreatex509crl11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据。 |

**返回值**：

| 类型                          | 说明                 |
| ----------------------------- | -------------------- |
| Promise\<[X509Crl](#x509crldeprecated)> | 表示证书吊销列表对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## cert.createX509CRL<sup>11+</sup>

createX509CRL(inStream : EncodingBlob, callback : AsyncCallback\<X509CRL>) : void

表示创建X509证书吊销列表的对象，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)         | 是   | 表示证书吊销列表序列化数据。     |
| callback | AsyncCallback\<[X509CRL](#x509crl11)> | 是   | 回调函数，表示证书吊销列表对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, X509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
  }
});
```

## cert.createX509CRL<sup>11+</sup>

createX509CRL(inStream : EncodingBlob) : Promise\<X509CRL>

表示创建X509证书吊销列表的对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                          | 必填 | 说明                       |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据。 |

**返回值**：

| 类型                            | 说明                 |
| ------------------------------- | -------------------- |
| Promise\<[X509CRL](#x509crl11)> | 表示证书吊销列表对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob).then(X509CRL => {
  console.log('createX509CRL success');
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## X509Crl<sup>(deprecated)</sup>

X509证书吊销列表对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL](#x509crl11)替代。

### isRevoked<sup>(deprecated)</sup>

isRevoked(cert : X509Cert) : boolean

表示检查证书是否吊销。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.isRevoked](#isrevoked11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型     | 必填 | 说明                 |
| ------ | -------- | ---- | -------------------- |
| cert   | X509Cert | 是   | 表示被检查的证书对象。 |

**返回值**：

| 类型      | 说明                                           |
| --------- | --------------------------------------------- |
| boolean   | 表示证书吊销状态，true表示已吊销，false表示未吊销。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

let certEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    // Create an X509Cert instance.
    cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error) {
        console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        try {
          let revokedFlag = x509Crl.isRevoked(x509Cert);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
});
```

### getType<sup>(deprecated)</sup>

getType() : string

表示获取证书吊销列表类型。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getType](#gettype11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书吊销列表类型。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let type = x509Crl.getType();
  }
});
```

### getEncoded<sup>(deprecated)</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书吊销列表的序列化数据，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getEncoded](#getencoded11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                         | 必填 | 说明                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<EncodingBlob> | 是   | 回调函数，表示X509证书吊销列表的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    x509Crl.getEncoded((error, data) => {
      if (error) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded<sup>(deprecated)</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书吊销列表的序列化数据，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getEncoded](#getencoded11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                   | 说明                             |
| ---------------------- | -------------------------------- |
| Promise\<EncodingBlob> | 表示X509证书吊销列表的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
  x509Crl.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### verify<sup>(deprecated)</sup>

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对X509证书吊销列表进行验签，使用Callback回调异步返回结果。验签支持RSA算法。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.verify](#verify11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| key      | [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | 是   | 表示用于验签的公钥对象。                                       |
| callback | AsyncCallback\<void> | 是   | 回调函数,使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      // Generate the public key by AsyKeyGenerator.
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let priEncodingBlob: cryptoFramework.DataBlob = {
        data: priKeyData,
      };
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob, (e, keyPair) => {
        if (e) {
          console.error('convert key failed, message: ' + e.message + 'code: ' + e.code);
        } else {
          console.log('convert key success');
          x509Crl.verify(keyPair.pubKey, (err, data) => {
            if (err) {
              console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
            } else  {
              console.log('verify success');
            }
          });
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify<sup>(deprecated)</sup>

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对X509证书吊销列表进行验签，使用Promise方式异步返回结果。验签支持RSA算法。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.verify](#verify11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| key    | [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | 是   | 表示用于验签的公钥对象。 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit'
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');

  try {
    // 生成公钥对象。
    let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
    console.log('createAsyKeyGenerator success');
    let priEncodingBlob: cryptoFramework.DataBlob = {
      data: priKeyData,
    };
    let pubEncodingBlob: cryptoFramework.DataBlob = {
      data: pubKeyData,
    };
    keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob).then((keyPair) => {
      console.log('convert key success');
      x509Crl.verify(keyPair.pubKey).then(result => {
        console.log('verify success');
      }).catch((error: BusinessError) => {
        console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    }).catch((error: BusinessError) => {
      console.error('convert key failed, message: ' + error.message + 'code: ' + error.code);
    });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

表示获取X509证书吊销列表的版本号。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getVersion](#getversion11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 表示获取X509证书吊销列表的版本号。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let version = x509Crl.getVersion();
  }
});
```

### getIssuerName<sup>(deprecated)</sup>

getIssuerName() : DataBlob

表示获取X509证书吊销列表颁发者名称。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getIssuerName](#getissuername11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表颁发者名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let issuerName = x509Crl.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getLastUpdate<sup>(deprecated)</sup>

getLastUpdate() : string

表示获取X509证书吊销列表最后一次更新日期，日期为ASN.1时间格式。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getLastUpdate](#getlastupdate11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表最后一次更新日期，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let lastUpdate = x509Crl.getLastUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLastUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNextUpdate<sup>(deprecated)</sup>

getNextUpdate() : string

表示获取证书吊销列表下一次更新的日期，日期为ASN.1时间格式。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getNextUpdate](#getnextupdate11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表下一次更新的日期，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let nextUpdate = x509Crl.getNextUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNextUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCert<sup>(deprecated)</sup>

getRevokedCert(serialNumber : number) : X509CrlEntry

表示通过指定证书序列号获取被吊销X509证书对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCert](#getrevokedcert11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| serialNumber | number | 是   | 表示证书序列号。 |

**返回值**:

| 类型                   | 说明                   |
| ---------------------- | --------------------- |
| [X509CrlEntry](#x509crlentrydeprecated) | 表示被吊销X509证书对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let serialNumber = 1000;
    try {
      let entry = x509Crl.getRevokedCert(serialNumber);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCertWithCert<sup>(deprecated)</sup>

getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry

表示通过指定证书对象获取被吊销X509证书对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCertWithCert](#getrevokedcertwithcert11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型                  | 必填 | 说明         |
| ------ | --------------------- | ---- | ------------ |
| cert   | [X509Cert](#x509cert) | 是   | 表示证书对象。 |

**返回值**:

| 类型         | 说明                  |
| ------------ | -------------------- |
| [X509CrlEntry](#x509crlentrydeprecated) | 表示被吊销X509证书对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIIBjjB4AgEBMA0GCSqGSIb3DQEBCwUAMBIxEDAOBgNVBAMMB1Jvb3QgQ0EXDTI0\n' +
  'MDMxOTAyMDQwN1oXDTI0MDQxODAyMDQwN1owIjAgAgEEFw0yNDAzMTkwMjA0MDZa\n' +
  'MAwwCgYDVR0VBAMKAQGgDjAMMAoGA1UdFAQDAgEAMA0GCSqGSIb3DQEBCwUAA4IB\n' +
  'AQCbjvmHxC8dW6WCS/ga73kx2b7f8I/2eVuDYyReuBiGWeJ9vDmGqimJ9VwOk+ph\n' +
  'LvG/2Zvh9I8qXxnOWeseA2C0bEshJGvXpquIjm00OUyLlK6jdfRbhXT8OyvDjqZs\n' +
  'e1IsMV7Zo11SUc8nR2d0QQ7EVDCN/XFKPsmoK7PhJnRh5gc8W3FKQ6b8H9kdjgTa\n' +
  'KQUap1OIDReVsjPBmRAbwMMLtbrAMllF7E6x7uHgHTGaK1ZPJDtsnCJ45ur3mk/o\n' +
  'HAJFwHNjNDltiEfvMSs76/X0cwitpeW4dFk6c3QtqhxJrHDD4gl8di+xHOyHXpzX\n' +
  '+i2osvdPWRia0dJCL1PCA14k\n' +
  '-----END X509 CRL-----\n';

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDTjCCAjagAwIBAgIBBDANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
  'IENBMB4XDTI0MDMxOTAyMDQwMVoXDTM0MDMxNzAyMDQwMVowEjEQMA4GA1UEAwwH\n' +
  'ZGV2aWNlMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMIXL3e7UE/c\n' +
  'Z1dPVgRZ5L8gsQ/azuYVBvoFf7o8ksYrL7G1+qZIJjVRqZkuTirLW4GicbkIkPNW\n' +
  'eix5cDhkjkC+q5SBCOrSSTTlvX3xcOY1gMlA5MgeBfGixFusq4d5VPF2KceZ20/a\n' +
  'ygwGD0Uv0X81OERyPom/dYdJUvfaD9ifPFJ1fKIj/cPFG3yJK/ojpEfndZNdESQL\n' +
  'TkoDekilg2UGOLtY6fb9Ns37ncuIj33gCS/R9m1tgtmqCTcgOQ4hwKhjVF3InmPO\n' +
  '2BbWKvD1RUX+rHC2a2HHDQILOOtDTy8dHvE+qZlK0efrpRgoFEERJAGPi1GDGWiA\n' +
  '7UX1c4MCxIECAwEAAaOBrjCBqzAJBgNVHRMEAjAAMB0GA1UdDgQWBBQbkAcMT7ND\n' +
  'fGp3VPFzYHppZ1zxLTAfBgNVHSMEGDAWgBR0W/koCbvDtFGHUQZLM3j6HKsW2DAd\n' +
  'BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwCwYDVR0PBAQDAgeAMDIGCCsG\n' +
  'AQUFBwEBBCYwJDAiBggrBgEFBQcwAYYWaHR0cHM6Ly8xMjcuMC4wLjE6OTk5OTAN\n' +
  'BgkqhkiG9w0BAQsFAAOCAQEAF1OTzTmbklFOdZCxrF3zg9owUPJR5RB+PbuBlUfI\n' +
  '8tkGXkMltQ8PN1dv6Cq+d8BluiJdWEzqVoJa/e5SHHJyYQSOhlurRG0GBXllVQ1I\n' +
  'n1PFaI40+9X2X6wrEcdC5nbzogR1jSiksCiTcARMddj0Xrp5FMrFaaGY8M/xqzdW\n' +
  'LTDl4nfbuxtA71cIjnE4kOcaemly9/S2wYWdPktsPxQPY1nPUOeJFI7o0sH3rK0c\n' +
  'JSqtgAG8vnjK+jbx9RpkgqCsXgUbIahL573VTgxrNrsRjCuVal7XVxl/xOKXr6Er\n' +
  'Gpc+OCrXbHNZkUQE5fZH3yL2tXd7EASEb6J3aEWHfF8YBA==\n' +
  '-----END CERTIFICATE-----\n';

let certEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    // 创建X509证书对象。
    cert.createX509Cert(certEncodingBlob).then((x509Cert) => {
      try {
        let entry = x509Crl.getRevokedCertWithCert(x509Cert);
        console.log('getRevokedCertWithCert success');
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('getRevokedCertWithCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }).catch((error: BusinessError) => {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    })
  }
});
```

### getRevokedCerts<sup>(deprecated)</sup>

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

表示获取被吊销X509证书列表，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCerts](#getrevokedcerts11)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                                 | 必填 | 说明                             |
| -------- | ---------------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CrlEntry](#x509crlentrydeprecated)>> | 是   | 回调函数，表示被吊销X509证书列表。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    x509Crl.getRevokedCerts((error, array) => {
      if (error) {
        console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getRevokedCerts success');
      }
    });
  }
});
```

### getRevokedCerts<sup>(deprecated)</sup>

getRevokedCerts() : Promise<Array\<X509CrlEntry>>

表示获取被吊销X509证书列表，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getRevokedCerts](#getrevokedcerts11-1)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                                           | 说明                   |
| ---------------------------------------------- | ---------------------- |
| Promise<Array\<[X509CrlEntry](#x509crlentrydeprecated)>> | 表示被吊销X509证书列表。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
  x509Crl.getRevokedCerts().then(array => {
    console.log('getRevokedCerts success');
  }).catch((error: BusinessError) => {
    console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getTbsInfo<sup>(deprecated)</sup>

getTbsInfo() : DataBlob

表示获取证书吊销列表的tbsCertList信息。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getTBSInfo](#gettbsinfo11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| [DataBlob](#datablob) | 表示证书吊销列表的tbsCertList信息。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let tbsInfo = x509Crl.getTbsInfo();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getTbsInfo failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignature<sup>(deprecated)</sup>

getSignature() : DataBlob

表示获取X509证书吊销列表的签名数据。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignature](#getsignature11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表的签名数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let signature = x509Crl.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName<sup>(deprecated)</sup>

getSignatureAlgName() : string

表示获取X509证书吊销列表签名的算法名称。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignatureAlgName](#getsignaturealgname11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 表示X509证书吊销列表签名的算法名。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgName = x509Crl.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid<sup>(deprecated)</sup>

getSignatureAlgOid() : string

表示获取X509证书吊销列表签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignatureAlgOid](#getsignaturealgoid11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | 表示X509证书吊销列表签名算法的对象标志符OID。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgOid = x509Crl.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams<sup>(deprecated)</sup>

getSignatureAlgParams() : DataBlob

表示获取X509证书吊销列表签名的算法参数。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRL.getSignatureAlgParams](#getsignaturealgparams11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | 表示X509证书吊销列表签名的算法参数。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 801 | this operation is not supported. |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgParams = x509Crl.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```
## X509CRL<sup>11+</sup>

被吊销证书列表对象。

### isRevoked<sup>11+</sup>

isRevoked(cert : X509Cert) : boolean

表示检查证书是否吊销。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型     | 必填 | 说明                 |
| ------ | -------- | ---- | -------------------- |
| cert   | [X509Cert](#x509cert) | 是   | 表示被检查的证书对象。 |

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 表示证书吊销状态，true表示已吊销，false表示未吊销。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

let certEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    // Create an X509Cert instance.
    cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error) {
        console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        try {
          let revokedFlag = x509CRL.isRevoked(x509Cert);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
});
```

### getType<sup>11+</sup>

getType() : string

表示获取证书吊销列表类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书吊销列表类型。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let type = x509CRL.getType();
  }
});
```

### getEncoded<sup>11+</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书吊销列表的序列化数据，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数，表示X509证书吊销列表的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    x509CRL.getEncoded((error, data) => {
      if (error) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded<sup>11+</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书吊销列表的序列化数据，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                             |
| --------------------------------------- | -------------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示X509证书吊销列表的序列化数据。 |
**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509CRL success');
  x509CRL.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### verify<sup>11+</sup>

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

表示对X509证书吊销列表进行验签，使用Callback回调异步返回结果。验签支持RSA算法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | 是   | 表示用于验签的公钥对象。                                       |
| callback | AsyncCallback\<void>                                        | 是   | 回调函数,使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      // Generate the public key by AsyKeyGenerator.
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let priEncodingBlob: cryptoFramework.DataBlob = {
        data: priKeyData,
      };
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob, (e, keyPair) => {
        if (e) {
          console.error('convert key failed, message: ' + e.message + 'code: ' + e.code);
        } else {
          console.log('convert key success');
          x509CRL.verify(keyPair.pubKey, (err, data) => {
            if (err) {
              console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
            } else {
              console.log('verify success');
            }
          });
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify<sup>11+</sup>

verify(key : cryptoFramework.PubKey) : Promise\<void>

表示对X509证书吊销列表进行验签，使用Promise方式异步返回结果。验签支持RSA算法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型                                                        | 必填 | 说明                     |
| ------ | ----------------------------------------------------------- | ---- | ------------------------ |
| key    | [cryptoFramework.PubKey](../apis-crypto-architecture-kit/js-apis-cryptoFramework.md#pubkey) | 是   | 表示用于验签的公钥对象。 |

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit'
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509Crl success');

  try {
    // 生成公钥对象。
    let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
    console.log('createAsyKeyGenerator success');
    let priEncodingBlob: cryptoFramework.DataBlob = {
      data: priKeyData,
    };
    let pubEncodingBlob: cryptoFramework.DataBlob = {
      data: pubKeyData,
    };
    keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob).then((keyPair) => {
      console.log('convert key success');
      x509CRL.verify(keyPair.pubKey).then(result => {
        console.log('verify success');
      }).catch((error: BusinessError) => {
        console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    }).catch((error: BusinessError) => {
      console.error('convert key failed, message: ' + error.message + 'code: ' + error.code);
    });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getVersion<sup>11+</sup>

getVersion() : number

表示获取X509证书吊销列表的版本号。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 表示获取X509证书吊销列表的版本号。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let version = x509CRL.getVersion();
  }
});
```

### getIssuerName<sup>11+</sup>

getIssuerName() : DataBlob

表示获取X509证书吊销列表颁发者名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表颁发者名称。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let issuerName = x509CRL.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getLastUpdate<sup>11+</sup>

getLastUpdate() : string

表示获取X509证书吊销列表最后一次更新日期，日期为ASN.1时间格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表最后一次更新日期，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let lastUpdate  = x509CRL.getLastUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLastUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNextUpdate<sup>11+</sup>

getNextUpdate() : string

表示获取证书吊销列表下一次更新的日期，日期为ASN.1时间格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表下一次更新的日期，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let nextUpdate = x509CRL.getNextUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNextUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCert<sup>11+</sup>

getRevokedCert(serialNumber : bigint) : X509CRLEntry

表示通过指定证书序列号获取被吊销X509证书对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| serialNumber | bigint | 是   | 表示证书序列号。 |

**返回值**:

| 类型                            | 说明                   |
| ------------------------------- | ---------------------- |
| [X509CRLEntry](#x509crlentry11) | 表示被吊销X509证书对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let serialNumber = BigInt(1000);
    try {
      let entry = x509CRL.getRevokedCert(serialNumber);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCertWithCert<sup>11+</sup>

getRevokedCertWithCert(cert : X509Cert) : X509CRLEntry

表示通过指定证书对象获取被吊销X509证书对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名 | 类型                  | 必填 | 说明         |
| ------ | --------------------- | ---- | ------------ |
| cert   | [X509Cert](#x509cert) | 是   | 表示证书对象。 |

**返回值**:

| 类型                            | 说明                   |
| ------------------------------- | ---------------------- |
| [X509CRLEntry](#x509crlentry11) | 表示被吊销X509证书对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIIBjjB4AgEBMA0GCSqGSIb3DQEBCwUAMBIxEDAOBgNVBAMMB1Jvb3QgQ0EXDTI0\n' +
  'MDMxOTAyMDQwN1oXDTI0MDQxODAyMDQwN1owIjAgAgEEFw0yNDAzMTkwMjA0MDZa\n' +
  'MAwwCgYDVR0VBAMKAQGgDjAMMAoGA1UdFAQDAgEAMA0GCSqGSIb3DQEBCwUAA4IB\n' +
  'AQCbjvmHxC8dW6WCS/ga73kx2b7f8I/2eVuDYyReuBiGWeJ9vDmGqimJ9VwOk+ph\n' +
  'LvG/2Zvh9I8qXxnOWeseA2C0bEshJGvXpquIjm00OUyLlK6jdfRbhXT8OyvDjqZs\n' +
  'e1IsMV7Zo11SUc8nR2d0QQ7EVDCN/XFKPsmoK7PhJnRh5gc8W3FKQ6b8H9kdjgTa\n' +
  'KQUap1OIDReVsjPBmRAbwMMLtbrAMllF7E6x7uHgHTGaK1ZPJDtsnCJ45ur3mk/o\n' +
  'HAJFwHNjNDltiEfvMSs76/X0cwitpeW4dFk6c3QtqhxJrHDD4gl8di+xHOyHXpzX\n' +
  '+i2osvdPWRia0dJCL1PCA14k\n' +
  '-----END X509 CRL-----\n';

// 证书二进制数据，需业务自行赋值。
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDTjCCAjagAwIBAgIBBDANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
  'IENBMB4XDTI0MDMxOTAyMDQwMVoXDTM0MDMxNzAyMDQwMVowEjEQMA4GA1UEAwwH\n' +
  'ZGV2aWNlMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMIXL3e7UE/c\n' +
  'Z1dPVgRZ5L8gsQ/azuYVBvoFf7o8ksYrL7G1+qZIJjVRqZkuTirLW4GicbkIkPNW\n' +
  'eix5cDhkjkC+q5SBCOrSSTTlvX3xcOY1gMlA5MgeBfGixFusq4d5VPF2KceZ20/a\n' +
  'ygwGD0Uv0X81OERyPom/dYdJUvfaD9ifPFJ1fKIj/cPFG3yJK/ojpEfndZNdESQL\n' +
  'TkoDekilg2UGOLtY6fb9Ns37ncuIj33gCS/R9m1tgtmqCTcgOQ4hwKhjVF3InmPO\n' +
  '2BbWKvD1RUX+rHC2a2HHDQILOOtDTy8dHvE+qZlK0efrpRgoFEERJAGPi1GDGWiA\n' +
  '7UX1c4MCxIECAwEAAaOBrjCBqzAJBgNVHRMEAjAAMB0GA1UdDgQWBBQbkAcMT7ND\n' +
  'fGp3VPFzYHppZ1zxLTAfBgNVHSMEGDAWgBR0W/koCbvDtFGHUQZLM3j6HKsW2DAd\n' +
  'BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwCwYDVR0PBAQDAgeAMDIGCCsG\n' +
  'AQUFBwEBBCYwJDAiBggrBgEFBQcwAYYWaHR0cHM6Ly8xMjcuMC4wLjE6OTk5OTAN\n' +
  'BgkqhkiG9w0BAQsFAAOCAQEAF1OTzTmbklFOdZCxrF3zg9owUPJR5RB+PbuBlUfI\n' +
  '8tkGXkMltQ8PN1dv6Cq+d8BluiJdWEzqVoJa/e5SHHJyYQSOhlurRG0GBXllVQ1I\n' +
  'n1PFaI40+9X2X6wrEcdC5nbzogR1jSiksCiTcARMddj0Xrp5FMrFaaGY8M/xqzdW\n' +
  'LTDl4nfbuxtA71cIjnE4kOcaemly9/S2wYWdPktsPxQPY1nPUOeJFI7o0sH3rK0c\n' +
  'JSqtgAG8vnjK+jbx9RpkgqCsXgUbIahL573VTgxrNrsRjCuVal7XVxl/xOKXr6Er\n' +
  'Gpc+OCrXbHNZkUQE5fZH3yL2tXd7EASEb6J3aEWHfF8YBA==\n' +
  '-----END CERTIFICATE-----\n';

let certEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    // 创建X509证书对象。
    cert.createX509Cert(certEncodingBlob).then((x509Cert) => {
      try {
        let entry = x509CRL.getRevokedCertWithCert(x509Cert);
        console.log('getRevokedCertWithCert success');
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('getRevokedCertWithCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }).catch((error: BusinessError) => {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    })
  }
});
```

### getRevokedCerts<sup>11+</sup>

getRevokedCerts(callback : AsyncCallback<Array\<X509CRLEntry>>) : void

表示获取被吊销X509证书列表，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                                   | 必填 | 说明                             |
| -------- | ------------------------------------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CRLEntry](#x509crlentry11)>> | 是   | 回调函数，表示被吊销X509证书列表。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    x509CRL.getRevokedCerts((error, array) => {
      if (error) {
        console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getRevokedCerts success');
      }
    });
  }
});
```

### getRevokedCerts<sup>11+</sup>

getRevokedCerts() : Promise<Array\<X509CRLEntry>>

表示获取被吊销X509证书列表，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                                             | 说明                   |
| ------------------------------------------------ | ---------------------- |
| Promise<Array\<[X509CRLEntry](#x509crlentry11)>> | 表示被吊销X509证书列表。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509CRL success');
  x509CRL.getRevokedCerts().then(array => {
    console.log('getRevokedCerts success');
  }).catch((error: BusinessError) => {
    console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getSignature<sup>11+</sup>

getSignature() : DataBlob

表示获取X509证书吊销列表的签名数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                           |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表的签名数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let signature = x509CRL.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName<sup>11+</sup>

getSignatureAlgName() : string

表示获取X509证书吊销列表签名的算法名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 表示X509证书吊销列表签名的算法名。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgName = x509CRL.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid<sup>11+</sup>

getSignatureAlgOid() : string

表示获取X509证书吊销列表签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | 表示X509证书吊销列表签名算法的对象标志符OID。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgOid = x509CRL.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams<sup>11+</sup>

getSignatureAlgParams() : DataBlob

表示获取X509证书吊销列表签名的算法参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | 表示X509证书吊销列表签名的算法参数。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 801 | this operation is not supported. |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgParams = x509CRL.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getTBSInfo<sup>11+</sup>

getTBSInfo() : DataBlob

表示获取证书吊销列表的tbsCertList信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**:

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| [DataBlob](#datablob) | 表示证书吊销列表的tbsCertList信息。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let tbsInfo = x509CRL.getTBSInfo();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getTBSInfo failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getExtensions<sup>11+</sup>

getExtensions(): DataBlob

表示获取CRL的扩展。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                |
| --------------------- | ------------------- |
| [DataBlob](#datablob) | 表示X509CRL扩展用途。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIIBjjB4AgEBMA0GCSqGSIb3DQEBCwUAMBIxEDAOBgNVBAMMB1Jvb3QgQ0EXDTI0\n' +
  'MDMxOTAyMDQwN1oXDTI0MDQxODAyMDQwN1owIjAgAgEEFw0yNDAzMTkwMjA0MDZa\n' +
  'MAwwCgYDVR0VBAMKAQGgDjAMMAoGA1UdFAQDAgEAMA0GCSqGSIb3DQEBCwUAA4IB\n' +
  'AQCbjvmHxC8dW6WCS/ga73kx2b7f8I/2eVuDYyReuBiGWeJ9vDmGqimJ9VwOk+ph\n' +
  'LvG/2Zvh9I8qXxnOWeseA2C0bEshJGvXpquIjm00OUyLlK6jdfRbhXT8OyvDjqZs\n' +
  'e1IsMV7Zo11SUc8nR2d0QQ7EVDCN/XFKPsmoK7PhJnRh5gc8W3FKQ6b8H9kdjgTa\n' +
  'KQUap1OIDReVsjPBmRAbwMMLtbrAMllF7E6x7uHgHTGaK1ZPJDtsnCJ45ur3mk/o\n' +
  'HAJFwHNjNDltiEfvMSs76/X0cwitpeW4dFk6c3QtqhxJrHDD4gl8di+xHOyHXpzX\n' +
  '+i2osvdPWRia0dJCL1PCA14k\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let extensions = x509CRL.getExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### match<sup>11+</sup>

match(param: X509CRLMatchParameters): boolean

判断证书吊销列表是否与输入参数匹配。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11)| 是   | 表示需要匹配的参数。 |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| boolean | 当参数匹配时，该方法返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.  |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let crlEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

const certData = "-----BEGIN CERTIFICATE-----\r\n" +
  "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
  "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
  "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
  "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
  "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
  "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
  "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
  "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
  "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
  "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
  "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
  "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
  "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
  "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
  "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
  "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
  "-----END CERTIFICATE-----\r\n";
const certEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certData),
  encodingFormat: cert.EncodingFormat.FORMAT_PEM,
};

async function crlMatch() {
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }

  cert.createX509CRL(crlEncodingBlob, (error, x509CRL) => {
    if (error) {
      console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      console.log('createX509CRL success');
      try {
        const param: cert.X509CRLMatchParameters = {
          issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
          x509Cert: x509Cert
        }
        const result = x509CRL.match(param);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('x509CRL match failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }
  });
}
```

### getIssuerX500DistinguishedName<sup>12+</sup>

getIssuerX500DistinguishedName(): X500DistinguishedName

获取颁发者的X509可分辨名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [X500DistinguishedName](#x500distinguishedname12) | X509的可分辨对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let crlEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function crlGetIssuerX500DistinguishedName() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(crlEncodingBlob);
    console.log('createX509CRL success');
    let name = x509Crl.getIssuerX500DistinguishedName();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### toString<sup>12+</sup>

toString(): string

获取对象的字符串类型数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| string | 对象的字符串类型数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let crlEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function crlToString() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(crlEncodingBlob);
    console.log('createX509CRL success');
    console.info('crlToString success: ' + JSON.stringify(x509Crl.toString()));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### hashCode<sup>12+</sup>

hashCode(): Uint8Array

获取DER格式数据的哈希值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Uint8Array | DER格式数据的哈希值。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let crlEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function crlHashCode() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(crlEncodingBlob);
    console.log('createX509CRL success');
    console.info('crlHashCode success: ' + JSON.stringify(x509Crl.hashCode()));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getExtensionsObject<sup>12+</sup>

getExtensionsObject(): CertExtension

获取对应实体的扩展域DER格式数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| [CertExtension](#certextension10) | 证书扩展域段类对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIIB6DCB0QIBATANBgkqhkiG9w0BAQsFADCBjjELMAkGA1UEBhMCUlUxFTATBgNV\n' +
    'BAgMDNCc0L7RgdC60LLQsDELMAkGA1UECgwC0K8xCzAJBgNVBAsMAtCvMSowKAYD\n' +
    'VQQDDCHQlNC80LjRgtGA0LjQuSDQkdC10LvRj9Cy0YHQutC40LkxIjAgBgkqhkiG\n' +
    '9w0BCQEWE2JlbGRtaXRAZXhhbXBsZS5jb20XDTE3MDQyNDEzMjUzMVoXDTE3MDUy\n' +
    'NDEzMjUzMVqgDjAMMAoGA1UdFAQDAgEBMA0GCSqGSIb3DQEBCwUAA4IBAQCF5eX+\n' +
    '1BM/BxoHU2/3pQHJgPSKevN0/K/daiFHiJl7Kb9GCwKY14B1RvbN2rUP/58Mt+aq\n' +
    'jvauf1yBzlaJQeJKZcsCmG9p6Tr1y0BJXhrq5kC0SLyNDsfGUTfuxnwmo+clHXRU\n' +
    '+gKuk+h0WkJL022ZYbJ38w588k4NT3CWVHeE23EDC264p942mlDE7en6MyL152Pe\n' +
    'Ld9YrWiq5iOIOrIbQLErq0EjwxvHG9sMiYFUa6VrwmRf26nyZ7u9RKJDP+o2dltw\n' +
    'diBaSXC3Qt3pZ8BIfv/l81lwp8Dr63SwCII2pIRplyICdQqmX/a+1q8kThXIP2Kx\n' +
    '+X48g7VE2o2X4cfy\n' +
    '-----END X509 CRL-----\n';

// 证书吊销列表二进制数据，需业务自行赋值。
let crlEncodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function crlHashCode() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(crlEncodingBlob);
    console.log('createX509CRL success');
    let object = x509Crl.getExtensionsObject();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.createCertChainValidator

createCertChainValidator(algorithm :string) : CertChainValidator

表示创建证书链校验器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| algorithm | string | 是   | 表示证书链校验器算法。当前仅支持输入“PKIX”。 |

**返回值**：

| 类型               | 说明                 |
| ------------------ | -------------------- |
| [CertChainValidator](#certchainvalidator) | 表示证书链校验器对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let validator = cert.createCertChainValidator('PKIX');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('createCertChainValidator failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

## CertChainValidator

证书链校验器对象。


### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | -------------------------- |
| algorithm  | string | 是   | 否   | X509证书链校验器算法名称。 |


### validate

validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void

表示校验X509证书链，使用Callback回调异步返回结果。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/DeviceCertificateKit/certificate-framework-overview.md#证书规格)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据。                                    |
| callback  | AsyncCallback\<void>            | 是   | 回调函数，使用AsyncCallback的第一个error参数判断是否校验成功，error为null表示成功，error不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书链二进制数据。
let certPem = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDTjCCAjagAwIBAgIBBDANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
  'IENBMB4XDTI0MDMxOTAyMDQwMVoXDTM0MDMxNzAyMDQwMVowEjEQMA4GA1UEAwwH\n' +
  'ZGV2aWNlMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMIXL3e7UE/c\n' +
  'Z1dPVgRZ5L8gsQ/azuYVBvoFf7o8ksYrL7G1+qZIJjVRqZkuTirLW4GicbkIkPNW\n' +
  'eix5cDhkjkC+q5SBCOrSSTTlvX3xcOY1gMlA5MgeBfGixFusq4d5VPF2KceZ20/a\n' +
  'ygwGD0Uv0X81OERyPom/dYdJUvfaD9ifPFJ1fKIj/cPFG3yJK/ojpEfndZNdESQL\n' +
  'TkoDekilg2UGOLtY6fb9Ns37ncuIj33gCS/R9m1tgtmqCTcgOQ4hwKhjVF3InmPO\n' +
  '2BbWKvD1RUX+rHC2a2HHDQILOOtDTy8dHvE+qZlK0efrpRgoFEERJAGPi1GDGWiA\n' +
  '7UX1c4MCxIECAwEAAaOBrjCBqzAJBgNVHRMEAjAAMB0GA1UdDgQWBBQbkAcMT7ND\n' +
  'fGp3VPFzYHppZ1zxLTAfBgNVHSMEGDAWgBR0W/koCbvDtFGHUQZLM3j6HKsW2DAd\n' +
  'BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwCwYDVR0PBAQDAgeAMDIGCCsG\n' +
  'AQUFBwEBBCYwJDAiBggrBgEFBQcwAYYWaHR0cHM6Ly8xMjcuMC4wLjE6OTk5OTAN\n' +
  'BgkqhkiG9w0BAQsFAAOCAQEAF1OTzTmbklFOdZCxrF3zg9owUPJR5RB+PbuBlUfI\n' +
  '8tkGXkMltQ8PN1dv6Cq+d8BluiJdWEzqVoJa/e5SHHJyYQSOhlurRG0GBXllVQ1I\n' +
  'n1PFaI40+9X2X6wrEcdC5nbzogR1jSiksCiTcARMddj0Xrp5FMrFaaGY8M/xqzdW\n' +
  'LTDl4nfbuxtA71cIjnE4kOcaemly9/S2wYWdPktsPxQPY1nPUOeJFI7o0sH3rK0c\n' +
  'JSqtgAG8vnjK+jbx9RpkgqCsXgUbIahL573VTgxrNrsRjCuVal7XVxl/xOKXr6Er\n' +
  'Gpc+OCrXbHNZkUQE5fZH3yL2tXd7EASEb6J3aEWHfF8YBA==\n' +
  '-----END CERTIFICATE-----';

let caPem = '-----BEGIN CERTIFICATE-----\n' +
'MIIC/zCCAeegAwIBAgIBATANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
'IENBMB4XDTI0MDMxOTAyMDIyNFoXDTM0MDMxNzAyMDIyNFowEjEQMA4GA1UEAwwH\n' +
'Um9vdCBDQTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALxI5SDvRfKU\n' +
'6XaTeyh2LHlUK0rVSeYfXkYf5Mc3Pgucg+ewzQjxkACMx5NYaW1zfGDNPG1i5IZl\n' +
'cPeWNz1Tm2g6wTd+LyNoNOOmwfLV8pLXSfAukgNrBREf3BzVrbu7hvPd2MmLH23H\n' +
'OBM9uDPTIqu3n2CDN2EzwULjaSk2g+jvhVKsDLInu5uKPmZBFhs1FWKgcnVnlbi1\n' +
'AyAx4efheits6EO70oV6UufCEtS1VsBXQHZRAG4ogshWldRBVNxkU6yHAfg0mM/5\n' +
'EhrZsfh51fWqlrhNWrInjgNV3xIt5ebTIgKZWUlSVHEA/UqDoGfY+CsAJdteZWOW\n' +
'KjsrC/DK2O0CAwEAAaNgMF4wHQYDVR0OBBYEFHRb+SgJu8O0UYdRBkszePocqxbY\n' +
'MB8GA1UdIwQYMBaAFHRb+SgJu8O0UYdRBkszePocqxbYMA8GA1UdEwEB/wQFMAMB\n' +
'Af8wCwYDVR0PBAQDAgEGMA0GCSqGSIb3DQEBCwUAA4IBAQAKOT1ObfQNMN2wdfHq\n' +
'PQgFDDp6rBMbZe70LswPirSXljo4S/vfbG+gBoWCdu/SfsV+lyP75kg1wX0IQvzW\n' +
'xYNh864dgqPmGd0v8TIfM0UT0PpnowUyBHQ+E7LNYIOh/kjHbl3oERdEFA2PUyE9\n' +
'j3GLdg8oe/LqhEQCSAlH+v2RQgBZ9eVN+mSdUxwywm9U3acb0uqVkGiWK/ywumpg\n' +
'AmIZLMJtMVvg8uDkfy16Z4lChTEdNaJVUqPczUNk2kHXIF4we4be9HoOuTVz/SD/\n' +
'IsOhXn/BjS3jnhyS9fxo+opJf9zVTWI02Hlh1WVVtH/m3nIZblyAJhcjCHA2wZSz\n' +
'sSus\n' +
'-----END CERTIFICATE-----';

let certPemData = stringToUint8Array(certPem);
let caPemData = stringToUint8Array(caPem);

let certPemDataLenData = new Uint8Array(new Uint16Array([certPemData.length]).buffer)
let caPemDataLenData = new Uint8Array(new Uint16Array([caPemData.length]).buffer)

let certChainBuff = new Uint8Array(certPemDataLenData.length + certPemData.length + caPemDataLenData.length + caPemData.length)
certChainBuff.set(certPemDataLenData)
certChainBuff.set(certPemData, certPemDataLenData.length)
certChainBuff.set(caPemDataLenData, certPemDataLenData.length + certPemData.length)
certChainBuff.set(caPemData, certPemDataLenData.length + certPemData.length + caPemDataLenData.length)

let certChainData: cert.CertChainData = {
  data: certChainBuff,
  // 证书链包含的证书个数，需业务自行赋值。
  count: 2,
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

try {
  let validator = cert.createCertChainValidator('PKIX');
  validator.validate(certChainData, (error, data) => {
    if (error) {
      console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      console.log('validate success');
    }
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

### validate

validate(certChain : CertChainData) : Promise\<void>

表示校验X509证书链，使用Promise方式异步返回结果。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/DeviceCertificateKit/certificate-framework-overview.md#证书规格)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明                       |
| --------- | ------------------------------- | ---- | -------------------------- |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据。 |

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书链数据。
let certPem = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDTjCCAjagAwIBAgIBBDANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
  'IENBMB4XDTI0MDMxOTAyMDQwMVoXDTM0MDMxNzAyMDQwMVowEjEQMA4GA1UEAwwH\n' +
  'ZGV2aWNlMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMIXL3e7UE/c\n' +
  'Z1dPVgRZ5L8gsQ/azuYVBvoFf7o8ksYrL7G1+qZIJjVRqZkuTirLW4GicbkIkPNW\n' +
  'eix5cDhkjkC+q5SBCOrSSTTlvX3xcOY1gMlA5MgeBfGixFusq4d5VPF2KceZ20/a\n' +
  'ygwGD0Uv0X81OERyPom/dYdJUvfaD9ifPFJ1fKIj/cPFG3yJK/ojpEfndZNdESQL\n' +
  'TkoDekilg2UGOLtY6fb9Ns37ncuIj33gCS/R9m1tgtmqCTcgOQ4hwKhjVF3InmPO\n' +
  '2BbWKvD1RUX+rHC2a2HHDQILOOtDTy8dHvE+qZlK0efrpRgoFEERJAGPi1GDGWiA\n' +
  '7UX1c4MCxIECAwEAAaOBrjCBqzAJBgNVHRMEAjAAMB0GA1UdDgQWBBQbkAcMT7ND\n' +
  'fGp3VPFzYHppZ1zxLTAfBgNVHSMEGDAWgBR0W/koCbvDtFGHUQZLM3j6HKsW2DAd\n' +
  'BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwCwYDVR0PBAQDAgeAMDIGCCsG\n' +
  'AQUFBwEBBCYwJDAiBggrBgEFBQcwAYYWaHR0cHM6Ly8xMjcuMC4wLjE6OTk5OTAN\n' +
  'BgkqhkiG9w0BAQsFAAOCAQEAF1OTzTmbklFOdZCxrF3zg9owUPJR5RB+PbuBlUfI\n' +
  '8tkGXkMltQ8PN1dv6Cq+d8BluiJdWEzqVoJa/e5SHHJyYQSOhlurRG0GBXllVQ1I\n' +
  'n1PFaI40+9X2X6wrEcdC5nbzogR1jSiksCiTcARMddj0Xrp5FMrFaaGY8M/xqzdW\n' +
  'LTDl4nfbuxtA71cIjnE4kOcaemly9/S2wYWdPktsPxQPY1nPUOeJFI7o0sH3rK0c\n' +
  'JSqtgAG8vnjK+jbx9RpkgqCsXgUbIahL573VTgxrNrsRjCuVal7XVxl/xOKXr6Er\n' +
  'Gpc+OCrXbHNZkUQE5fZH3yL2tXd7EASEb6J3aEWHfF8YBA==\n' +
  '-----END CERTIFICATE-----';

let caPem = '-----BEGIN CERTIFICATE-----\n' +
'MIIC/zCCAeegAwIBAgIBATANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
'IENBMB4XDTI0MDMxOTAyMDIyNFoXDTM0MDMxNzAyMDIyNFowEjEQMA4GA1UEAwwH\n' +
'Um9vdCBDQTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALxI5SDvRfKU\n' +
'6XaTeyh2LHlUK0rVSeYfXkYf5Mc3Pgucg+ewzQjxkACMx5NYaW1zfGDNPG1i5IZl\n' +
'cPeWNz1Tm2g6wTd+LyNoNOOmwfLV8pLXSfAukgNrBREf3BzVrbu7hvPd2MmLH23H\n' +
'OBM9uDPTIqu3n2CDN2EzwULjaSk2g+jvhVKsDLInu5uKPmZBFhs1FWKgcnVnlbi1\n' +
'AyAx4efheits6EO70oV6UufCEtS1VsBXQHZRAG4ogshWldRBVNxkU6yHAfg0mM/5\n' +
'EhrZsfh51fWqlrhNWrInjgNV3xIt5ebTIgKZWUlSVHEA/UqDoGfY+CsAJdteZWOW\n' +
'KjsrC/DK2O0CAwEAAaNgMF4wHQYDVR0OBBYEFHRb+SgJu8O0UYdRBkszePocqxbY\n' +
'MB8GA1UdIwQYMBaAFHRb+SgJu8O0UYdRBkszePocqxbYMA8GA1UdEwEB/wQFMAMB\n' +
'Af8wCwYDVR0PBAQDAgEGMA0GCSqGSIb3DQEBCwUAA4IBAQAKOT1ObfQNMN2wdfHq\n' +
'PQgFDDp6rBMbZe70LswPirSXljo4S/vfbG+gBoWCdu/SfsV+lyP75kg1wX0IQvzW\n' +
'xYNh864dgqPmGd0v8TIfM0UT0PpnowUyBHQ+E7LNYIOh/kjHbl3oERdEFA2PUyE9\n' +
'j3GLdg8oe/LqhEQCSAlH+v2RQgBZ9eVN+mSdUxwywm9U3acb0uqVkGiWK/ywumpg\n' +
'AmIZLMJtMVvg8uDkfy16Z4lChTEdNaJVUqPczUNk2kHXIF4we4be9HoOuTVz/SD/\n' +
'IsOhXn/BjS3jnhyS9fxo+opJf9zVTWI02Hlh1WVVtH/m3nIZblyAJhcjCHA2wZSz\n' +
'sSus\n' +
'-----END CERTIFICATE-----';

let certPemData = stringToUint8Array(certPem);
let caPemData = stringToUint8Array(caPem);

let certPemDataLenData = new Uint8Array(new Uint16Array([certPemData.length]).buffer)
let caPemDataLenData = new Uint8Array(new Uint16Array([caPemData.length]).buffer)

let certChainBuff = new Uint8Array(certPemDataLenData.length + certPemData.length + caPemDataLenData.length + caPemData.length)
certChainBuff.set(certPemDataLenData)
certChainBuff.set(certPemData, certPemDataLenData.length)
certChainBuff.set(caPemDataLenData, certPemDataLenData.length + certPemData.length)
certChainBuff.set(caPemData, certPemDataLenData.length + certPemData.length + caPemDataLenData.length)

let certChainData: cert.CertChainData = {
  data: certChainBuff,
  // 证书链包含的证书个数，需业务自行赋值。
  count: 2,
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

try {
  let validator = cert.createCertChainValidator('PKIX');
  validator.validate(certChainData).then(result => {
    console.log('validate success');
  }).catch((error: BusinessError) => {
    console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

## X509CrlEntry<sup>(deprecated)</sup>

被吊销证书对象。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CrlEntry](#x509crlentry11)替代。

### getEncoded<sup>(deprecated)</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取被吊销证书的序列化数据，使用Callback回调异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getEncoded](#getencoded11-2)替代。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                 |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数，表示被吊销证书的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      crlEntry.getEncoded((error, data) => {
        if (error) {
          console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getEncoded<sup>(deprecated)</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取被吊销证书的序列化数据，使用Promise方式异步返回结果。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getEncoded](#getencoded11-3)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示被吊销证书的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      crlEntry.getEncoded().then(result => {
        console.log('getEncoded success');
      }).catch((error: BusinessError) => {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getSerialNumber<sup>(deprecated)</sup>

getSerialNumber() : number

表示获取被吊销证书的序列号。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getSerialNumber](#getserialnumber11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 表示被吊销证书的序列号。 |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      serialNumber = crlEntry.getSerialNumber();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuer<sup>(deprecated)</sup>

getCertIssuer() : DataBlob

表示获取被吊销证书的颁发者信息。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getCertIssuer](#getcertissuer11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ----------------------- |
| [DataBlob](#datablob) | 表示被吊销证书的颁发者信息。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 801 | this operation is not supported. |
| 19020001 | memory error.  |
| 19020002 | runtime error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      let issuer = crlEntry.getCertIssuer();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getCertIssuer failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getRevocationDate<sup>(deprecated)</sup>

getRevocationDate() : string

表示获取证书被吊销的日期，日期为ASN.1时间格式。

> **说明：**
>
> 从API version 11开始废弃，建议使用[X509CRLEntry.getRevocationDate](#getrevocationdate11)替代。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                |
| ------ | ------------------ |
| string | 表示证书被吊销的日期，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      let date = crlEntry.getRevocationDate();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getRevocationDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

## X509CRLEntry<sup>11+</sup>

被吊销证书对象。

### getEncoded<sup>11+</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取被吊销证书的序列化数据，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                 |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 是   | 回调函数，表示被吊销证书的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      crlEntry.getEncoded((error, data) => {
        if (error) {
          console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getEncoded<sup>11+</sup>

getEncoded() : Promise\<EncodingBlob>

表示获取被吊销证书的序列化数据，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示被吊销证书的序列化数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types.|
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      crlEntry.getEncoded().then(result => {
        console.log('getEncoded success');
      }).catch((error: BusinessError) => {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getSerialNumber<sup>11+</sup>

getSerialNumber() : bigint

表示获取被吊销证书的序列号。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                   |
| ------ | ---------------------- |
| bigint | 表示被吊销证书的序列号。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      serialNumber = crlEntry.getSerialNumber();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuer<sup>11+</sup>

getCertIssuer() : DataBlob

表示获取被吊销证书的颁发者信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                       |
| --------------------- | -------------------------- |
| [DataBlob](#datablob) | 表示被吊销证书的颁发者信息。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 801 | this operation is not supported. |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let issuer = crlEntry.getCertIssuer();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getCertIssuer failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getRevocationDate<sup>11+</sup>

getRevocationDate() : string

表示获取证书被吊销的日期，日期为ASN.1时间格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书被吊销的日期，日期为ASN.1时间格式。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let date = crlEntry.getRevocationDate();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getRevocationDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getExtensions<sup>11+</sup>

getExtensions(): DataBlob

表示获取CRL的扩展。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 表示X509CRLEntry扩展用途。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIIBjjB4AgEBMA0GCSqGSIb3DQEBCwUAMBIxEDAOBgNVBAMMB1Jvb3QgQ0EXDTI0\n' +
  'MDMxOTAyMDQwN1oXDTI0MDQxODAyMDQwN1owIjAgAgEEFw0yNDAzMTkwMjA0MDZa\n' +
  'MAwwCgYDVR0VBAMKAQGgDjAMMAoGA1UdFAQDAgEAMA0GCSqGSIb3DQEBCwUAA4IB\n' +
  'AQCbjvmHxC8dW6WCS/ga73kx2b7f8I/2eVuDYyReuBiGWeJ9vDmGqimJ9VwOk+ph\n' +
  'LvG/2Zvh9I8qXxnOWeseA2C0bEshJGvXpquIjm00OUyLlK6jdfRbhXT8OyvDjqZs\n' +
  'e1IsMV7Zo11SUc8nR2d0QQ7EVDCN/XFKPsmoK7PhJnRh5gc8W3FKQ6b8H9kdjgTa\n' +
  'KQUap1OIDReVsjPBmRAbwMMLtbrAMllF7E6x7uHgHTGaK1ZPJDtsnCJ45ur3mk/o\n' +
  'HAJFwHNjNDltiEfvMSs76/X0cwitpeW4dFk6c3QtqhxJrHDD4gl8di+xHOyHXpzX\n' +
  '+i2osvdPWRia0dJCL1PCA14k\n' +
  '-----END X509 CRL-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(4);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let extensions = crlEntry.getExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### hasExtensions<sup>11+</sup>

hasExtensions(): boolean

表示判断CRL Entry是否有扩展。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| boolean | 返回true则表示CRL Entry有扩展，返回false则表示无扩展。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let hasExtensions = crlEntry.hasExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or hasExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuerX500DistinguishedName<sup>12+</sup>

getCertIssuerX500DistinguishedName(): X500DistinguishedName

获取证书颁发者的X509可分辨名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| [X500DistinguishedName](#x500distinguishedname12) | X509的可分辨对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certGetCertIssuerX500DistinguishedName() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(encodingBlob);
    console.log('createX509CRL success');
    let name = x509Crl.getRevokedCert(BigInt(1000)).getCertIssuerX500DistinguishedName();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### toString<sup>12+</sup>

toString(): string

获取对象的字符串类型数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| string | 对象的字符串类型数据。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certToString() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(encodingBlob);
    console.log('createX509CRL success');
    console.info('toString success: ' + JSON.stringify(x509Crl.getRevokedCert(BigInt(1000)).toString()));
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### hashCode<sup>12+</sup>

hashCode(): Uint8Array

获取DER格式数据的哈希值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| Uint8Array | DER格式数据的哈希值。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certHashCode() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(encodingBlob);
    console.log('createX509CRL success');
    console.info('hashCode success: ' + JSON.stringify(x509Crl.getRevokedCert(BigInt(1000)).hashCode()));
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getExtensionsObject<sup>12+</sup>

getExtensionsObject(): CertExtension

获取对应实体的扩展域DER格式数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| [CertExtension](#certextension10) | 证书扩展域段类对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIINlTCCDH0CAQEwDQYJKoZIhvcNAQELBQAwTDELMAkGA1UEBhMCVVMxFTATBgNV\n' +
  'BAoTDERpZ2lDZXJ0IEluYzEmMCQGA1UEAxMdRGlnaUNlcnQgU2VjdXJlIFNpdGUg\n' +
  'Q04gQ0EgRzMXDTI0MDMxMjE4NDQ0NVoXDTI0MDMxOTE4NDQ0NVowggvJMCECEAbk\n' +
  'wC/+N2YXfpw7vgDJ2xAXDTIzMDIwNzA1NTg1OFowIQIQDonqcHww7uhlmWH+OfIe\n' +
  'PhcNMjMwMzA5MDcwMzI1WjAvAhAM4CTrULrJUEinWgT9AFPvFw0yMzAzMjAxOTE4\n' +
  'NTRaMAwwCgYDVR0VBAMKAQQwIQIQBQP4xflKkcRehoJ2NaA/jhcNMjMwMzIyMDk0\n' +
  'NTI5WjAvAhAOmgzoiIqznAaFec53PVPUFw0yMzAzMjcyMDI4MDNaMAwwCgYDVR0V\n' +
  'BAMKAQQwLwIQBaC2Z3D4dcQ/O7HnzFU9KBcNMjMwMzI5MTc1OTQ1WjAMMAoGA1Ud\n' +
  'FQQDCgEFMCECEAlz9Rg1b+9La4oFqsHUc4AXDTIzMDMzMTAyMzk0MVowIQIQD9yW\n' +
  '92pX6BinUKVBVSSTmBcNMjMwNDExMDExNjI5WjAvAhAIIarHUWWee4V9W/Yzm86k\n' +
  'Fw0yMzA0MTQyMDE5MTJaMAwwCgYDVR0VBAMKAQQwIQIQC2OiM3VIJX2dEe8/pf8f\n' +
  'hRcNMjMwNDIxMDMzMDIyWjAhAhAP0ueyg5n/7b2Hotml7f42Fw0yMzA0MjYwMjU3\n' +
  'NDJaMCECEAqMu61nkOEmTOdMbUZTMrkXDTIzMDUxNzAxMzI0NVowLwIQDYv1rt0K\n' +
  'olvP+nQoi5LeLRcNMjMwNTIzMTc0MDE4WjAMMAoGA1UdFQQDCgEEMC8CEA8WMKlw\n' +
  'iCK36PruJvup5bUXDTIzMDUyMzE3NDA1M1owDDAKBgNVHRUEAwoBBDAvAhAJ5uwT\n' +
  'aqwgLzNVpxh4u9EPFw0yMzA1MjUxNzEwNTBaMAwwCgYDVR0VBAMKAQQwIQIQCg0k\n' +
  '5UadwDH5xm14yxcgLRcNMjMwNjA3MDcyNDAwWjAhAhAEByUhbBR6/pZRFUH2PTxE\n' +
  'Fw0yMzA2MDgwMjIwMzBaMCECEATquAQcy3W1kUOkb4VoOvEXDTIzMDYyNjA5MDIw\n' +
  'NlowIQIQBrF5sueIjk1snKdO0ISOXhcNMjMwNjMwMDI0MDA0WjAhAhAJEG72WQtV\n' +
  'lTOYiA0xjVk5Fw0yMzA3MDUwMjEyMzdaMCECEAmXIuCMJv9gllYuKfCHm5EXDTIz\n' +
  'MDcwNTAyMTIzN1owIQIQAotQots0ngzRwACzrS9mCBcNMjMwNzA2MDU0NDU3WjAh\n' +
  'AhAG2hyGc9SfXrLc0Uk2J1BeFw0yMzA3MjQwMTUwNDBaMCECEAJhm5FSlVyTG9UK\n' +
  'zS+ecUgXDTIzMDcyNjA2NDQzM1owIQIQC4mlxBQuFxWC4pF7/P8BDxcNMjMwNzMx\n' +
  'MTAzMjU0WjAhAhADCEp333/avF3m6HZtBImOFw0yMzA3MzExMDMzNTBaMCECEAKd\n' +
  'P7fydlXUcS4v/YnZMMwXDTIzMDczMTEwMzQzOFowIQIQC+m5EUcRd1E0lEIPj17Z\n' +
  'rRcNMjMwODAxMDYwNDE4WjAvAhAF4QcgQQlWpAi4FVflzbKxFw0yMzA4MDMxNjIz\n' +
  'MTdaMAwwCgYDVR0VBAMKAQQwIQIQAn01GEZ50Y5ugIcEuGfF9BcNMjMwODA4MDE1\n' +
  'NzM1WjAhAhAFHj3FDKeP9q9CM924d8RIFw0yMzA4MDgwMTU5NDhaMC8CEAnkNPSD\n' +
  'U5yiMsV3fU06a6oXDTIzMDgwODE5MjIwMlowDDAKBgNVHRUEAwoBBDAvAhAETU4z\n' +
  '13iMKiwQujsxJDRhFw0yMzA4MTAyMDU4NDdaMAwwCgYDVR0VBAMKAQQwIQIQB1oD\n' +
  'M2mOYuse7e/nTqx+8xcNMjMwOTA0MDUwOTU3WjAhAhALf3Bp63so6O+R5QbWPWu6\n' +
  'Fw0yMzEwMDkwNjE5NTVaMCECEAKFHdXcy/zBXRtMj3BVhO0XDTIzMTAwOTA2MTk1\n' +
  'N1owIQIQDNNmVHN4tMu1xth6IAe4ZhcNMjMxMDEyMDc0MjQ1WjAhAhACNNJA2oMM\n' +
  'pr+giIgczvHOFw0yMzEwMTYwNTEyMzdaMCECEAoQun7uSHhvy6GBoxG7XOkXDTIz\n' +
  'MTExNjA3MDAzN1owLwIQA1NsI22PLvohCvKwdtAJwBcNMjMxMjA2MTgyNzUzWjAM\n' +
  'MAoGA1UdFQQDCgEEMCECEAWagozDt4jfBzi+aDGFr88XDTIzMTIxMTA3MjM1OFow\n' +
  'IQIQD1g7NdEk7t05zg6yweYc5hcNMjMxMjExMDcyNTM3WjAhAhAMJnRjUQAzFQFH\n' +
  'kwIguRz2Fw0yMzEyMTEwNzI2NDJaMCECEAT0bVxyPKkeTV8JQuPxfcwXDTIzMTIx\n' +
  'MTA3MjcyNlowIQIQA/5BlE0Ushtw24Ol9L2sexcNMjMxMjExMDcyODA2WjAhAhAL\n' +
  'Ij6FAKVJDnKAwwt19+/RFw0yMzEyMTEwNzI5MDJaMCECEAmPyfX3FuOHgryS2i8c\n' +
  'SrUXDTIzMTIxMTA3Mjk0M1owIQIQC+uGa6tmPRPCB0jW+6WWUhcNMjMxMjExMDcz\n' +
  'MDIzWjAhAhAJCq59mFZj6SWLH/m18Fq2Fw0yMzEyMTEwNzMwNTJaMCECEAp0Po24\n' +
  'WHmdEMTVyp9AMssXDTIzMTIxMTA3MzEyNlowIQIQAcf+793qPEHipkAhjf7MghcN\n' +
  'MjMxMjExMDczMTQ5WjAhAhAElLuCARMBoDIH0Y2D1DpSFw0yMzEyMTEwNzMyMTla\n' +
  'MCECEAWlgWhTXqKOB61zA7Ao8vQXDTIzMTIxMTA3MzI0OFowIQIQAeZqfkFYc/6t\n' +
  'zO7j/FVYwBcNMjMxMjExMDczMzM1WjAhAhAHzftyRhskxV6opTfHb59OFw0yMzEy\n' +
  'MTEwNzM0MDNaMCECEASXrBHdRYUm9VIZ1wN4qAsXDTIzMTIxMTA3MzQyN1owIQIQ\n' +
  'BDFb/OY65CZ1sTdMPAc+IhcNMjMxMjExMDczNTEzWjAhAhAFg7mRyWvWXc+KT014\n' +
  'Ro5AFw0yMzEyMTEwNzM1NDhaMCECEA+wAstqfBUEkSvinYlWeOwXDTIzMTIxMTA3\n' +
  'MzYyNVowIQIQB3Z75ksHGnvGmuHbvwbheRcNMjMxMjExMDczNjU5WjAhAhALfrIn\n' +
  'OGRVeePivKkJ+d1xFw0yMzEyMTEwNzM4MDFaMCECEAnm5NfU36m+FXNlJiUsXpMX\n' +
  'DTIzMTIxMTA3MzgzNVowIQIQCrBoHo4X2md3Amteqh7h3RcNMjMxMjExMDczOTA3\n' +
  'WjAhAhAGxHlqrHu66ifOwTTMhHHFFw0yMzEyMTEwNzM5NDNaMCECEA2BDG1SI7Se\n' +
  '2GAt+b9UnF8XDTIzMTIxMTA3NDAyNFowLwIQDZvl5jkmAwjTweDCtrXbLRcNMjMx\n' +
  'MjExMjA0NDQ3WjAMMAoGA1UdFQQDCgEEMCECEAzgcwGVpyXXZSmLLF4MExQXDTIz\n' +
  'MTIxOTE3MjczMlowIQIQARB9nVoMuE5GSFeb3U553hcNMjMxMjE5MTcyODA1WjAh\n' +
  'AhAD+JIH7lFcX9UNqTogrMcPFw0yMzEyMTkxNzI5MDZaMCECEAux1kd8ugXs4mI+\n' +
  'xMfXgpsXDTIzMTIxOTE3MjkyOFowIQIQCUO5VqAmbxA8Jdly97msLhcNMjMxMjE5\n' +
  'MTcyOTU0WjAhAhAFyzrU1JtsiPNPeWrfdvGvFw0yMzEyMTkxNzMwNDlaMCECEAwT\n' +
  'tMq5EsBTUhQwm6nWhnAXDTIzMTIyMDE3NDc1NlowIQIQBx3qL8rMclE9gxamaa14\n' +
  'xBcNMjMxMjIwMTc0ODM2WjAhAhAOnKUlrCaxs+lRqLrBmk2PFw0yNDAxMzAxOTMw\n' +
  'MTVaMCECEAtYs/5ZRsrMAxQVDA44eWYXDTI0MDIwNjA2MjYwMFowIQIQDjrMV1d3\n' +
  '0NhxngX5rqqxjBcNMjQwMjIxMDc0ODEwWjAhAhAPGohz3+JyS6H4JzHCjLrXFw0y\n' +
  'NDAyMjgyMDQxMjZaMC8CEAqZ2QktAMprzZmtolbOXlgXDTI0MDIyOTE4MDYzMVow\n' +
  'DDAKBgNVHRUEAwoBBDAhAhAMAHgNfiburtKDp8OJuzRCFw0yNDAzMDQwNjA3MzJa\n' +
  'MCECEA/HgrXcSBqkb2JdfrFDAfgXDTI0MDMwNDA2MDczMlqgMDAuMB8GA1UdIwQY\n' +
  'MBaAFETZyEozjtNSjaeSlGEfmsilt+zLMAsGA1UdFAQEAgIFrDANBgkqhkiG9w0B\n' +
  'AQsFAAOCAQEAJ5rSr0Av5sH59J2LXW5hZ8SJTzDbR8ADdi/CCLolbUUnE0oaAZ+2\n' +
  '9z0niAD5m8HQikNz8K+FKAsQatN/CAj4bzRMeF37hQCiZpqNtxP69JDGeWpGPiH2\n' +
  'K/YfpzL9iSbBOxFmosxUX8J/iX36mCUl+3OUHh+qSYeElboxeAmTCnY5Pl5Bq9is\n' +
  'gp0MmzNYCo7GEFrtS03p2msK25uRqQl6Qn0NZS0yGjdUG7RTZe4xua5drjEkB1o/\n' +
  '15f+mtYj6DtWM1twi1q3VYVxhRSsk6XmmS0BViTEl+MT0BRAPwBSdlyt++1Pnnrd\n' +
  'BsQoO8O2EVpJ54fxKMCSDOkJf1hNCxi3eQ==\n' +
  '-----END X509 CRL-----\n';

let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certGetExtensionsObject() {
  let x509Crl: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509Crl = await cert.createX509CRL(encodingBlob);
    console.log('createX509CRL success');
    let object = x509Crl.getRevokedCert(BigInt('14091103387070223745671018446433705560')).getExtensionsObject();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.createCertCRLCollection<sup>11+</sup>

createCertCRLCollection(certs: Array\<X509Cert>, crls?: Array\<X509CRL>): CertCRLCollection

表示创建证书和证书吊销列表集合对象，并返回相应的结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| certs | Array\<[X509Cert](#x509cert)>    | 是   |  X509Cert数组。  |
| crls | Array\<[X509CRL](#x509crl11)>     | 否   |  X509CRL数组。  |

**返回值**：

| 类型               | 说明                 |
| ------------------ | -------------------- |
| [CertCRLCollection](#certcrlcollection11) | 表示证书和证书吊销列表集合对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<cert.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // 证书吊销列表二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509CRL = await cert.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<cert.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function createCollection() {
  const x509Cert = await createX509Cert();
  const x509CRL = await createX509CRL();
  try {
    const collection: cert.CertCRLCollection = cert.createCertCRLCollection([x509Cert], [x509CRL]);
    console.log('createCertCRLCollection success');
  } catch (err) {
    console.error('createCertCRLCollection failed');
  }
}
```

## CertCRLCollection<sup>11+</sup>

证书和证书吊销列表集合对象。

### selectCerts<sup>11+</sup>

selectCerts(param: X509CertMatchParameters): Promise\<Array\<X509Cert>>

查找证书和证书吊销列表集合中所有与参数匹配的证书对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明      |
| --------- | ------------------------------- | ---- | ------------ |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | 是   | 表示证书需匹配的参数。  |

**返回值**：

| 类型                                    | 说明                                    |
| --------------------------------------- | --------------------------------------- |
| Promise\<Array\<[X509Cert](#x509cert)>> | Promise对象。表示匹配到的证书对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<cert.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function selectCerts() {
  const x509Cert = await createX509Cert();
  const collection = cert.createCertCRLCollection([x509Cert]);

  try {
    const param: cert.X509CertMatchParameters = {
      x509Cert,
      validDate: '20231121074700Z',
      issuer: new Uint8Array([0x30, 0x1a, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41]),
      subject: new Uint8Array([0x30, 0x1a, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41]),
      publicKeyAlgID: '1.2.840.10045.2.1'
    };
    const certs = await collection.selectCerts(param);
    console.log('call selectCerts success');
  } catch (err) {
    console.error('call selectCerts failed');
  }
}
```

### selectCerts<sup>11+</sup>

selectCerts(param: X509CertMatchParameters, callback: AsyncCallback\<Array\<X509Cert>>): void

查找证书和证书吊销列表集合中所有与参数匹配的证书对象, 使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明            |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | 是   | 表示证书需匹配的参数。   |
| callback  | AsyncCallback\<Array\<[X509Cert](#x509cert)>>    | 是   | 回调函数，表示匹配到的证书对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<cert.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function selectCerts() {
  const x509Cert = await createX509Cert();
  const collection = cert.createCertCRLCollection([x509Cert]);
  // 需业务自行赋值。
    const param: cert.X509CertMatchParameters = {
      x509Cert,
      validDate: '20231121074700Z',
      issuer: new Uint8Array([0x30, 0x1a, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41]),
      subject: new Uint8Array([0x30, 0x1a, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0F, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41]),
      publicKeyAlgID: '1.2.840.10045.2.1'
    };
  collection.selectCerts(param, (err, certs) => {
    if (err) {
      console.error('selectCerts failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      console.log('selectCerts success');
    }
  });
}
```

### selectCRLs<sup>11+</sup>

selectCRLs(param: X509CRLMatchParameters): Promise\<Array\<X509CRL>>

查找证书和证书吊销列表集合中所有与参数匹配的证书吊销列表对象, 使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明      |
| --------- | ------------------------------- | ---- | ------------ |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11) | 是   | 表示证书吊销列表需匹配的参数。   |

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<Array\<[X509CRL](#x509crl11)>> | Promise对象，表示匹配到的证书吊销列表对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<cert.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // 证书吊销列表二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509CRL = await cert.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<cert.X509Cert> {
  const certData = "-----BEGIN CERTIFICATE-----\r\n" +
    "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
    "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
    "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
    "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
    "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
    "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
    "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
    "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
    "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
    "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
    "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
    "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
    "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
    "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
    "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
    "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
    "-----END CERTIFICATE-----\r\n";
  const certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    encodingFormat: cert.EncodingFormat.FORMAT_PEM,
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }
  return x509Cert;
}

async function selectCRLs() {
  const x509CRL = await createX509CRL();
  const x509Cert = await createX509Cert();
  const collection = cert.createCertCRLCollection([], [x509CRL]);

  const param: cert.X509CRLMatchParameters = {
    issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
    x509Cert: x509Cert
  }
  try {
    const crls = await collection.selectCRLs(param);
    console.log('selectCRLs success');
  } catch (err) {
    console.error('selectCRLs failed');
  }
}
```

### selectCRLs<sup>11+</sup>

selectCRLs(param: X509CRLMatchParameters, callback: AsyncCallback\<Array\<X509CRL>>): void

查找证书和证书吊销列表集合中所有与参数匹配的证书吊销列表对象, 使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明            |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11) | 是   | 表示证书吊销列表需匹配的参数对象。 |
| callback  | AsyncCallback\<Array\<[X509CRL](#x509crl11)>>    | 是   | 回调函数，表示匹配到的证书吊销列表对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<cert.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // 证书吊销列表二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509CRL = await cert.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<cert.X509Cert> {
  const certData = "-----BEGIN CERTIFICATE-----\r\n" +
    "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
    "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
    "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
    "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
    "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
    "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
    "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
    "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
    "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
    "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
    "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
    "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
    "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
    "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
    "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
    "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
    "-----END CERTIFICATE-----\r\n";
  const certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    encodingFormat: cert.EncodingFormat.FORMAT_PEM,
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }
  return x509Cert;
}

async function selectCRLs() {
  const x509CRL = await createX509CRL();
  const x509Cert = await createX509Cert();
  const collection = cert.createCertCRLCollection([], [x509CRL]);

  const param: cert.X509CRLMatchParameters = {
    issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
    x509Cert: x509Cert
  }
  collection.selectCRLs(param, (err, crls) => {
    if (err) {
      console.error('selectCRLs failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      console.log('selectCRLs success');
    }
  });
}
```

## cert.createX509CertChain<sup>11+</sup>

createX509CertChain(inStream: EncodingBlob): Promise\<X509CertChain>

表示创建X509证书链对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                 |
| -------- | ----------------------------- | ---- | -------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据。 |

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| Promise\<[X509CertChain](#x509certchain11)> | 表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CertChain(): Promise<cert.X509CertChain> {
  let certChainData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
    "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
    "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
    "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
    "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
    "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
    "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
    "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
    "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
    "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
    "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
    "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
    "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
    "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
    "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
    "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
    "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
    "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
    "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
    "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
    "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n" +
    "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
    "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
    "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
    "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
    "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
    "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
    "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
    "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
    "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
    "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
    "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
    "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
    "uKPWR9dKBA==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n"  +
    "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
    "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
    "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
    "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
    "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
    "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
    "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
    "xjoE\n" +
    "-----END CERTIFICATE-----\n";

  // 证书链二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certChainData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

createX509CertChain();
```

## cert.createX509CertChain<sup>11+</sup>

createX509CertChain(inStream: EncodingBlob, callback: AsyncCallback\<X509CertChain>): void

表示创建X509证书链对象，使用Callback回调异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | 是   | X509证书序列化数据。        |
| callback | AsyncCallback\<[X509CertChain](#x509certchain11)> | 是   | 回调函数，表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// 证书链二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
  }
});
```

## cert.createX509CertChain<sup>11+</sup>

createX509CertChain(certs: Array\<X509Cert>): X509CertChain

表示使用X509Cert数组方式创建X509证书链对象，并同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                       |
| -------- | -------------------- | ---- | -------------------------- |
| certs    | Array\<[X509Cert](#x509cert)> | 是   | X509证书对象数组。 |

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [X509CertChain](#x509certchain11) | 表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<cert.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function createX509CertChain(): Promise<cert.X509CertChain> {
  const x509Cert = await createX509Cert();
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = cert.createX509CertChain([x509Cert]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

createX509CertChain();
```

## cert.buildX509CertChain<sup>12+</sup>

buildX509CertChain(param: [CertChainBuildParameters](#certchainbuildparameters12)): Promise\<CertChainBuildResult>

表示使用CertChainBuildParameters对象方式创建X509证书链对象，并用Promise方式返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                       |
| -------- | -------------------- | ---- | -------------------------- |
| param | [CertChainBuildParameters](#certchainbuildparameters12) | 是   | 构建证书链的参数对象。 |

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [CertChainBuildResult](#certchainbuildresult12) | 表示X509证书链对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// 证书链数据。
let certPem = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDTjCCAjagAwIBAgIBBDANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
  'IENBMB4XDTI0MDMxOTAyMDQwMVoXDTM0MDMxNzAyMDQwMVowEjEQMA4GA1UEAwwH\n' +
  'ZGV2aWNlMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMIXL3e7UE/c\n' +
  'Z1dPVgRZ5L8gsQ/azuYVBvoFf7o8ksYrL7G1+qZIJjVRqZkuTirLW4GicbkIkPNW\n' +
  'eix5cDhkjkC+q5SBCOrSSTTlvX3xcOY1gMlA5MgeBfGixFusq4d5VPF2KceZ20/a\n' +
  'ygwGD0Uv0X81OERyPom/dYdJUvfaD9ifPFJ1fKIj/cPFG3yJK/ojpEfndZNdESQL\n' +
  'TkoDekilg2UGOLtY6fb9Ns37ncuIj33gCS/R9m1tgtmqCTcgOQ4hwKhjVF3InmPO\n' +
  '2BbWKvD1RUX+rHC2a2HHDQILOOtDTy8dHvE+qZlK0efrpRgoFEERJAGPi1GDGWiA\n' +
  '7UX1c4MCxIECAwEAAaOBrjCBqzAJBgNVHRMEAjAAMB0GA1UdDgQWBBQbkAcMT7ND\n' +
  'fGp3VPFzYHppZ1zxLTAfBgNVHSMEGDAWgBR0W/koCbvDtFGHUQZLM3j6HKsW2DAd\n' +
  'BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwCwYDVR0PBAQDAgeAMDIGCCsG\n' +
  'AQUFBwEBBCYwJDAiBggrBgEFBQcwAYYWaHR0cHM6Ly8xMjcuMC4wLjE6OTk5OTAN\n' +
  'BgkqhkiG9w0BAQsFAAOCAQEAF1OTzTmbklFOdZCxrF3zg9owUPJR5RB+PbuBlUfI\n' +
  '8tkGXkMltQ8PN1dv6Cq+d8BluiJdWEzqVoJa/e5SHHJyYQSOhlurRG0GBXllVQ1I\n' +
  'n1PFaI40+9X2X6wrEcdC5nbzogR1jSiksCiTcARMddj0Xrp5FMrFaaGY8M/xqzdW\n' +
  'LTDl4nfbuxtA71cIjnE4kOcaemly9/S2wYWdPktsPxQPY1nPUOeJFI7o0sH3rK0c\n' +
  'JSqtgAG8vnjK+jbx9RpkgqCsXgUbIahL573VTgxrNrsRjCuVal7XVxl/xOKXr6Er\n' +
  'Gpc+OCrXbHNZkUQE5fZH3yL2tXd7EASEb6J3aEWHfF8YBA==\n' +
  '-----END CERTIFICATE-----';

let caPem = '-----BEGIN CERTIFICATE-----\n' +
'MIIC/zCCAeegAwIBAgIBATANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290\n' +
'IENBMB4XDTI0MDMxOTAyMDIyNFoXDTM0MDMxNzAyMDIyNFowEjEQMA4GA1UEAwwH\n' +
'Um9vdCBDQTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALxI5SDvRfKU\n' +
'6XaTeyh2LHlUK0rVSeYfXkYf5Mc3Pgucg+ewzQjxkACMx5NYaW1zfGDNPG1i5IZl\n' +
'cPeWNz1Tm2g6wTd+LyNoNOOmwfLV8pLXSfAukgNrBREf3BzVrbu7hvPd2MmLH23H\n' +
'OBM9uDPTIqu3n2CDN2EzwULjaSk2g+jvhVKsDLInu5uKPmZBFhs1FWKgcnVnlbi1\n' +
'AyAx4efheits6EO70oV6UufCEtS1VsBXQHZRAG4ogshWldRBVNxkU6yHAfg0mM/5\n' +
'EhrZsfh51fWqlrhNWrInjgNV3xIt5ebTIgKZWUlSVHEA/UqDoGfY+CsAJdteZWOW\n' +
'KjsrC/DK2O0CAwEAAaNgMF4wHQYDVR0OBBYEFHRb+SgJu8O0UYdRBkszePocqxbY\n' +
'MB8GA1UdIwQYMBaAFHRb+SgJu8O0UYdRBkszePocqxbYMA8GA1UdEwEB/wQFMAMB\n' +
'Af8wCwYDVR0PBAQDAgEGMA0GCSqGSIb3DQEBCwUAA4IBAQAKOT1ObfQNMN2wdfHq\n' +
'PQgFDDp6rBMbZe70LswPirSXljo4S/vfbG+gBoWCdu/SfsV+lyP75kg1wX0IQvzW\n' +
'xYNh864dgqPmGd0v8TIfM0UT0PpnowUyBHQ+E7LNYIOh/kjHbl3oERdEFA2PUyE9\n' +
'j3GLdg8oe/LqhEQCSAlH+v2RQgBZ9eVN+mSdUxwywm9U3acb0uqVkGiWK/ywumpg\n' +
'AmIZLMJtMVvg8uDkfy16Z4lChTEdNaJVUqPczUNk2kHXIF4we4be9HoOuTVz/SD/\n' +
'IsOhXn/BjS3jnhyS9fxo+opJf9zVTWI02Hlh1WVVtH/m3nIZblyAJhcjCHA2wZSz\n' +
'sSus\n' +
'-----END CERTIFICATE-----';

async function createX509Cert(certData: string): Promise<cert.X509Cert> {
  // 证书二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function buildX509CertChain() {
  try {
    const caCert = await createX509Cert(caPem);
    const x509Cert = await createX509Cert(certPem);
    let certCrlCollection = await cert.createCertCRLCollection([x509Cert]);
    let param: cert.CertChainBuildParameters = {
      certMatchParameters: {validDate:'20240812080000Z'},
      maxLength: 3,
      validationParameters: {
        date: '20240812080000Z',
        certCRLs: [certCrlCollection],
        trustAnchors: [{CACert:caCert}, {CACert:caCert}],
      }
    }
    let certChainBuildResult = await cert.buildX509CertChain(param);
    console.info("cert issuer name: " + certChainBuildResult.validationResult.entityCert.getIssuerName().data)
    console.info("ca subject name: " + certChainBuildResult.validationResult.trustAnchor.CACert?.getSubjectName().data)
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}

buildX509CertChain();
```

## cert.parsePkcs12<sup>18+</sup>

parsePkcs12(data: Uint8Array, config: Pkcs12ParsingConfig): Pkcs12Data

表示从P12文件中解析证书、私钥及其他证书合集，并返回结果。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                       |
| -------- | -------------------- | ---- | -------------------------- |
| data | Uint8Array | 是 | P12文件，DER格式。 |
| config | [Pkcs12ParsingConfig](#pkcs12parsingconfig18) | 是 | P12文件的解析配置。 |

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [Pkcs12Data](#pkcs12data18) | 表示P12文件解析后的证书、私钥及其他证书合集。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030008 | maybe wrong password.            |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

function doTestParsePkcs12() {
  try {
    let p12_cert = new Uint8Array([0x30, 0x82, 0x09, 0x51, 0x02, 0x01, 0x03, 0x30, 0x82, 0x09, 0x17, 0x06, 0x09, 0x2a, 0x86, 0x48,
      0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0xa0, 0x82, 0x09, 0x08, 0x04, 0x82, 0x09, 0x04, 0x30, 0x82,
      0x09, 0x00, 0x30, 0x82, 0x03, 0xb7, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07,
      0x06, 0xa0, 0x82, 0x03, 0xa8, 0x30, 0x82, 0x03, 0xa4, 0x02, 0x01, 0x00, 0x30, 0x82, 0x03, 0x9d,
      0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0x30, 0x1c, 0x06, 0x0a, 0x2a,
      0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x0c, 0x01, 0x06, 0x30, 0x0e, 0x04, 0x08, 0x7c, 0xd8, 0x60,
      0x3a, 0x07, 0xfb, 0x87, 0x8b, 0x02, 0x02, 0x08, 0x00, 0x80, 0x82, 0x03, 0x70, 0x4d, 0x64, 0xbe,
      0x82, 0xc2, 0x59, 0x58, 0x65, 0xf0, 0x37, 0x46, 0x4f, 0x6b, 0xfa, 0x43, 0x2e, 0x9d, 0xd9, 0x4f,
      0xd3, 0x54, 0x71, 0x69, 0x6e, 0x03, 0xf8, 0xb8, 0xf9, 0x05, 0xa2, 0x70, 0xa8, 0x70, 0xfb, 0xe6,
      0xda, 0x73, 0xdb, 0x4e, 0xdf, 0x72, 0xcd, 0xb6, 0x88, 0x81, 0xec, 0x3f, 0x8d, 0x7b, 0xdc, 0xa6,
      0x62, 0xd3, 0xd1, 0xdc, 0xef, 0xb9, 0x76, 0xb5, 0xd3, 0xb3, 0xfb, 0x61, 0x50, 0xeb, 0x22, 0x9b,
      0x72, 0x20, 0xb4, 0xe9, 0x7c, 0x5e, 0xaf, 0xa9, 0xb6, 0x40, 0x69, 0x70, 0xea, 0x79, 0x02, 0x1d,
      0x66, 0x71, 0x62, 0x39, 0x31, 0xd3, 0x31, 0xb1, 0x6f, 0x2a, 0x2d, 0x13, 0x59, 0xe9, 0xb7, 0x98,
      0xbe, 0x67, 0xfa, 0x5d, 0x6f, 0x8f, 0x7a, 0x43, 0x10, 0x5a, 0x3f, 0x13, 0xda, 0xb0, 0x94, 0x08,
      0x82, 0xf4, 0x39, 0x1d, 0x42, 0x26, 0x4a, 0xbe, 0x13, 0xe9, 0x89, 0x55, 0x52, 0xa4, 0x16, 0x3d,
      0x50, 0x83, 0x5c, 0xb9, 0x00, 0x5e, 0x03, 0x35, 0x65, 0x13, 0x1f, 0xd8, 0xf8, 0xeb, 0x28, 0xe5,
      0x00, 0x09, 0x9a, 0x62, 0x65, 0xab, 0x28, 0x21, 0x2e, 0x55, 0x11, 0x77, 0x7e, 0x64, 0xae, 0x12,
      0xc1, 0x5e, 0x85, 0xf2, 0xe7, 0xf7, 0x2b, 0x51, 0x46, 0xa6, 0xf8, 0x55, 0x2c, 0xc4, 0x0a, 0x80,
      0x6a, 0xc2, 0xa8, 0xba, 0x94, 0xf8, 0xee, 0x18, 0xf7, 0x32, 0x50, 0x53, 0xcc, 0x1e, 0x53, 0x85,
      0xeb, 0x0d, 0x1e, 0xec, 0xe2, 0xbb, 0xc2, 0xf3, 0xf7, 0x80, 0xfd, 0x81, 0x63, 0x8f, 0x87, 0x98,
      0x09, 0x47, 0x72, 0xee, 0x2d, 0x5a, 0x18, 0x89, 0x6b, 0x95, 0xef, 0x52, 0xde, 0x4d, 0xf5, 0x48,
      0x2a, 0x38, 0x6f, 0x4b, 0x98, 0x3c, 0x6d, 0x41, 0xdd, 0x1b, 0xfd, 0x65, 0x1b, 0x87, 0x8a, 0xcf,
      0xec, 0x47, 0xe3, 0x7a, 0xa0, 0x56, 0xd9, 0x36, 0x36, 0xcb, 0x17, 0xaa, 0x1b, 0x24, 0x79, 0x96,
      0xc6, 0x60, 0xd4, 0xe4, 0xa8, 0x59, 0x35, 0x5e, 0x4e, 0x00, 0xbf, 0x9a, 0xf5, 0x5c, 0x2a, 0xd7,
      0xd7, 0x92, 0x98, 0x79, 0xad, 0x13, 0xda, 0xea, 0xde, 0xcd, 0x65, 0x81, 0x26, 0xbd, 0x55, 0x0f,
      0xa4, 0x73, 0x54, 0x7b, 0x2f, 0x55, 0x2a, 0x2f, 0xb9, 0x2d, 0x6e, 0x04, 0xc8, 0x37, 0x5e, 0x93,
      0x09, 0xa7, 0x7f, 0xb1, 0x6b, 0x4a, 0x9f, 0xea, 0x59, 0x19, 0x57, 0xd0, 0xc1, 0xa1, 0x6b, 0xaf,
      0x27, 0x2b, 0xac, 0x81, 0xec, 0xcd, 0x2e, 0xa2, 0xa6, 0x08, 0x01, 0xfc, 0xa1, 0xbc, 0xc9, 0xdc,
      0x97, 0xb9, 0x48, 0xa8, 0x65, 0x5d, 0x63, 0xdb, 0x5c, 0x7e, 0x55, 0xe7, 0x47, 0xf2, 0x74, 0x17,
      0x67, 0xfe, 0x56, 0x20, 0x54, 0x65, 0x11, 0xdf, 0xec, 0x75, 0x70, 0x49, 0x59, 0xd1, 0xea, 0x6b,
      0x8f, 0x39, 0xec, 0x5d, 0x81, 0x82, 0x9a, 0xec, 0xce, 0x6c, 0x0c, 0x32, 0x14, 0xbd, 0xef, 0xac,
      0xae, 0x04, 0xd0, 0x75, 0x62, 0xf5, 0x82, 0x16, 0xd1, 0xa8, 0xfb, 0x22, 0x2a, 0xc2, 0xe7, 0x7a,
      0x75, 0x08, 0x59, 0x99, 0x34, 0x3d, 0xd9, 0xd7, 0x66, 0xb8, 0xcd, 0xaa, 0xf4, 0x48, 0xcc, 0x21,
      0x25, 0x83, 0xae, 0xad, 0x55, 0x0e, 0xff, 0x44, 0xf3, 0xcc, 0xd1, 0x89, 0x72, 0x0f, 0x9f, 0xe3,
      0xe5, 0xc7, 0xd4, 0x53, 0x94, 0xd6, 0xfb, 0x35, 0xd5, 0xd8, 0x2f, 0xa7, 0x4b, 0xf9, 0x50, 0x15,
      0x1e, 0x35, 0xfc, 0x3d, 0xca, 0xad, 0xb6, 0x49, 0x16, 0xee, 0xff, 0xd7, 0x8a, 0xcc, 0xf0, 0x96,
      0x11, 0x97, 0x22, 0xf3, 0xf7, 0x7c, 0x7a, 0x50, 0x49, 0x12, 0x68, 0x6e, 0x0e, 0x62, 0x32, 0xc7,
      0xe9, 0xc3, 0xa0, 0x1b, 0xfe, 0x29, 0x8c, 0x46, 0xc2, 0x7e, 0xe1, 0xea, 0xc3, 0xcb, 0x30, 0xaf,
      0xe4, 0x60, 0xe5, 0xa5, 0xa5, 0xb8, 0xf4, 0x16, 0xfa, 0x19, 0xd0, 0x1c, 0x14, 0xce, 0xf9, 0xa8,
      0x0b, 0x3f, 0x87, 0x89, 0xd3, 0xed, 0x9e, 0x16, 0x14, 0xbb, 0xd3, 0x64, 0xeb, 0x00, 0xe7, 0x48,
      0x1f, 0xd4, 0x47, 0xbc, 0xa9, 0x6f, 0x03, 0xe0, 0x0e, 0xaf, 0xb9, 0xad, 0x05, 0xa0, 0x1d, 0xee,
      0x0a, 0xcd, 0x0f, 0xd0, 0xb8, 0xf1, 0x35, 0x80, 0xa7, 0x72, 0xcd, 0x36, 0x8e, 0xce, 0x72, 0xf9,
      0x9f, 0xd5, 0x29, 0xae, 0x02, 0xb7, 0xbe, 0x65, 0xff, 0x38, 0x45, 0xf8, 0x8d, 0x87, 0x2f, 0xf8,
      0xdd, 0xc1, 0x72, 0x17, 0x2b, 0xdd, 0x3e, 0xfe, 0x01, 0xa0, 0x59, 0xb3, 0x19, 0x92, 0xf0, 0x59,
      0xf5, 0x06, 0x77, 0x8b, 0x1a, 0x41, 0x1d, 0x8b, 0x80, 0x74, 0x95, 0x8b, 0x30, 0x03, 0x18, 0xdd,
      0x1e, 0x1b, 0x21, 0x36, 0xdf, 0xde, 0xc3, 0xa2, 0x68, 0xe0, 0x3d, 0x94, 0x37, 0x6b, 0x48, 0xb2,
      0xb9, 0x41, 0x53, 0xd6, 0x65, 0xef, 0x7a, 0x3d, 0xdc, 0x09, 0x17, 0x66, 0xb4, 0x05, 0x58, 0x8a,
      0x5d, 0x2f, 0x40, 0x4a, 0x91, 0x8a, 0xa5, 0xb7, 0x29, 0xfb, 0x37, 0x81, 0x71, 0x77, 0x50, 0x8d,
      0x34, 0x80, 0x7e, 0xab, 0xb9, 0xc8, 0xdc, 0xb7, 0x2c, 0x7e, 0xbc, 0xad, 0x7c, 0x14, 0x5c, 0xf6,
      0x90, 0x88, 0x0e, 0x0d, 0x50, 0x7a, 0x4e, 0xa6, 0x85, 0xe4, 0x2a, 0xe7, 0x67, 0x21, 0x53, 0xbb,
      0x73, 0xd5, 0x30, 0x78, 0xbd, 0x08, 0x2b, 0x42, 0x44, 0x3e, 0x5d, 0x2b, 0x2f, 0x09, 0x8e, 0x82,
      0xc3, 0x5b, 0x9e, 0xd8, 0x20, 0xc6, 0xb7, 0x42, 0xe5, 0xb3, 0x60, 0x0b, 0x9b, 0x01, 0x76, 0x26,
      0xf7, 0xc1, 0xf7, 0xe1, 0xd1, 0x46, 0xf7, 0x9c, 0x21, 0xfd, 0x66, 0xb7, 0x14, 0x1d, 0x89, 0xb5,
      0xd3, 0xa1, 0x4e, 0x57, 0x97, 0xe7, 0xe4, 0x63, 0x96, 0xe2, 0x6f, 0x10, 0x6a, 0xb7, 0x8e, 0x83,
      0x64, 0x22, 0x10, 0x02, 0x27, 0x87, 0x6d, 0xb6, 0x11, 0x51, 0xe9, 0xe6, 0x68, 0x1a, 0xc8, 0xd3,
      0x6b, 0x23, 0x33, 0x68, 0x66, 0xab, 0x4d, 0xf9, 0x92, 0x11, 0x67, 0x9d, 0x24, 0xee, 0x18, 0xa8,
      0x3c, 0x5a, 0xfe, 0x79, 0x76, 0x99, 0xeb, 0x9f, 0x19, 0x9d, 0x74, 0xee, 0x13, 0xd9, 0xb1, 0x7b,
      0x4e, 0xcf, 0x30, 0x05, 0xdb, 0x5a, 0x3e, 0x00, 0x7e, 0x0a, 0xed, 0x6f, 0xaf, 0x0d, 0x1b, 0xf3,
      0x61, 0x24, 0x06, 0xe7, 0xf2, 0x57, 0x72, 0xf8, 0x61, 0x4d, 0x5f, 0x00, 0x78, 0x1f, 0x4d, 0xc7,
      0x28, 0x5e, 0xc4, 0x9b, 0xed, 0xac, 0x4f, 0x16, 0xaf, 0x81, 0x85, 0x33, 0x16, 0xbd, 0x6a, 0xb9,
      0xb2, 0x8e, 0x25, 0xbc, 0xaf, 0xfd, 0xea, 0xb7, 0x20, 0x32, 0x15, 0x62, 0x77, 0x52, 0xa1, 0xf2,
      0xd0, 0x9d, 0x12, 0x4c, 0x85, 0x71, 0x08, 0x03, 0xa7, 0x94, 0x34, 0xb4, 0x96, 0x30, 0x82, 0x05,
      0x41, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0xa0, 0x82, 0x05, 0x32,
      0x04, 0x82, 0x05, 0x2e, 0x30, 0x82, 0x05, 0x2a, 0x30, 0x82, 0x05, 0x26, 0x06, 0x0b, 0x2a, 0x86,
      0x48, 0x86, 0xf7, 0x0d, 0x01, 0x0c, 0x0a, 0x01, 0x02, 0xa0, 0x82, 0x04, 0xee, 0x30, 0x82, 0x04,
      0xea, 0x30, 0x1c, 0x06, 0x0a, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x0c, 0x01, 0x03, 0x30,
      0x0e, 0x04, 0x08, 0x30, 0xee, 0xbd, 0x7c, 0xcb, 0xb5, 0xa5, 0x1b, 0x02, 0x02, 0x08, 0x00, 0x04,
      0x82, 0x04, 0xc8, 0x1e, 0xd0, 0x7f, 0x7e, 0x86, 0x1c, 0x6f, 0x0e, 0xac, 0x6c, 0xe3, 0x35, 0xcb,
      0xff, 0xe4, 0x84, 0x88, 0x97, 0x45, 0xf3, 0x48, 0xa9, 0x98, 0xeb, 0x74, 0x91, 0x53, 0x07, 0x7a,
      0xe4, 0x78, 0x89, 0x13, 0xe7, 0xce, 0xa3, 0xc5, 0xab, 0x2c, 0x16, 0xe5, 0x02, 0x64, 0xc6, 0xb5,
      0x11, 0x36, 0x69, 0x0b, 0x5f, 0x7e, 0x95, 0x27, 0x59, 0x9a, 0xac, 0x98, 0x12, 0x76, 0x39, 0x31,
      0xaa, 0x4f, 0x22, 0x55, 0x21, 0x71, 0x20, 0xeb, 0x4e, 0x5e, 0x2d, 0xd8, 0xab, 0xd9, 0x64, 0x38,
      0x13, 0x9a, 0x14, 0x48, 0x7f, 0x48, 0x05, 0xec, 0x49, 0x55, 0x80, 0x49, 0xaf, 0x4e, 0x29, 0xdf,
      0x4a, 0xfb, 0xa1, 0x20, 0x2f, 0x98, 0x35, 0xf7, 0x8f, 0xb9, 0x41, 0x8b, 0x00, 0x14, 0x23, 0x9a,
      0x43, 0xfe, 0x55, 0xfc, 0xe5, 0x57, 0x19, 0xa9, 0x74, 0x44, 0x1f, 0xdd, 0xc3, 0xc8, 0x9f, 0xfa,
      0x9f, 0x67, 0x93, 0xed, 0x79, 0x11, 0xe1, 0x4e, 0xed, 0xd6, 0x20, 0x82, 0xc8, 0x85, 0xdf, 0x4e,
      0xa0, 0xcd, 0xd8, 0x36, 0x37, 0x4f, 0x67, 0x9d, 0x84, 0x44, 0x14, 0xce, 0xc0, 0xc9, 0xa6, 0xbd,
      0x73, 0x06, 0x27, 0xb7, 0x16, 0x97, 0x8c, 0x61, 0xd9, 0x63, 0xb2, 0x56, 0x8d, 0x28, 0x9e, 0x2e,
      0xcf, 0xa3, 0xfe, 0x8d, 0xaa, 0xef, 0x69, 0x32, 0x7b, 0x32, 0xbe, 0xd5, 0x62, 0x2c, 0x2e, 0x7f,
      0x72, 0xdb, 0x3c, 0x4b, 0xe4, 0x76, 0xa3, 0xa9, 0xa1, 0x67, 0x84, 0x86, 0xea, 0x14, 0x15, 0x6c,
      0x74, 0xd2, 0xac, 0x0e, 0xe2, 0x54, 0x54, 0xd4, 0x31, 0xa3, 0x88, 0x66, 0x89, 0x31, 0x7b, 0xf7,
      0x3c, 0x92, 0xce, 0x3e, 0x86, 0xfb, 0x57, 0xc8, 0x65, 0xae, 0x85, 0x6d, 0x48, 0xf6, 0xe6, 0x37,
      0xeb, 0x77, 0xcf, 0x06, 0xd6, 0x9e, 0x54, 0xb4, 0xd8, 0x9a, 0x5f, 0xdd, 0xc5, 0xa5, 0x05, 0xa0,
      0x4b, 0xd1, 0x54, 0xab, 0x4f, 0xd0, 0x3e, 0x6b, 0x8f, 0x03, 0x66, 0xd4, 0xe2, 0x90, 0xea, 0x2d,
      0x9b, 0x6a, 0x2b, 0xc4, 0x7b, 0x9d, 0xf1, 0xb5, 0x22, 0xdf, 0x86, 0xc2, 0xfd, 0x13, 0x0a, 0x69,
      0x29, 0x59, 0xe9, 0x45, 0xcd, 0xdf, 0xcd, 0xa5, 0x71, 0x7e, 0x70, 0xc3, 0x60, 0x9e, 0x47, 0x5d,
      0xd4, 0x6c, 0xcc, 0x15, 0x51, 0x23, 0x5b, 0x4e, 0xee, 0x72, 0x80, 0x49, 0xd6, 0xac, 0x89, 0x16,
      0x65, 0xf4, 0x95, 0x57, 0x19, 0x13, 0xab, 0x9c, 0x08, 0xe8, 0xdf, 0x0a, 0xe2, 0x39, 0xfc, 0xff,
      0x42, 0x02, 0xac, 0xaf, 0xf1, 0xb6, 0x56, 0xef, 0x75, 0x60, 0x2f, 0xc2, 0x5d, 0xef, 0xf5, 0x79,
      0xb5, 0x46, 0xa0, 0xb5, 0x03, 0x67, 0xef, 0x78, 0x3d, 0x49, 0xd0, 0xc5, 0x0e, 0xff, 0x42, 0x72,
      0x02, 0x86, 0x99, 0x93, 0xaa, 0xa3, 0x9e, 0x2c, 0xc7, 0xec, 0xa2, 0xdf, 0x25, 0x4e, 0x28, 0x81,
      0x82, 0x3e, 0x29, 0xd3, 0x37, 0xfd, 0x32, 0xf4, 0x85, 0x46, 0x42, 0xb9, 0x94, 0x44, 0x8a, 0xbf,
      0xd9, 0x14, 0xcb, 0xb6, 0xd3, 0xc5, 0xe7, 0x6b, 0x28, 0x70, 0xc3, 0x9c, 0xc2, 0x93, 0x9d, 0x2f,
      0xab, 0xd6, 0xb2, 0x19, 0x28, 0x9a, 0xda, 0x0d, 0x90, 0x5b, 0xba, 0x64, 0x6f, 0xcc, 0x11, 0xef,
      0x6c, 0x88, 0x18, 0x4f, 0x86, 0x6e, 0xed, 0xcf, 0xde, 0x0d, 0xec, 0xe2, 0x12, 0xc3, 0x89, 0x0a,
      0x3f, 0xbb, 0x3d, 0x8c, 0x8f, 0xa9, 0x40, 0xe6, 0xf8, 0xd1, 0x1a, 0x9a, 0x7e, 0x8a, 0xd7, 0x7b,
      0x56, 0xf4, 0x5d, 0x80, 0x64, 0xd5, 0x88, 0x86, 0x85, 0x18, 0x30, 0x5d, 0x64, 0x04, 0xb3, 0xc2,
      0xc7, 0x80, 0xda, 0x3e, 0xc4, 0xd6, 0xf6, 0xc4, 0x95, 0x56, 0xd5, 0xad, 0x82, 0x86, 0xcc, 0x1a,
      0x05, 0x69, 0x06, 0x08, 0x5b, 0x19, 0xea, 0x10, 0xc5, 0xcd, 0x67, 0x93, 0xab, 0x0f, 0xe3, 0xba,
      0xb0, 0x0d, 0xac, 0x99, 0x0d, 0x35, 0x6f, 0xe5, 0x41, 0xb2, 0x7c, 0x87, 0x91, 0x6c, 0xe2, 0x75,
      0x9b, 0x64, 0x62, 0x06, 0x2a, 0x8b, 0xd9, 0x4d, 0x23, 0xcd, 0x2b, 0xef, 0xf5, 0x61, 0x82, 0x8e,
      0x3f, 0xf6, 0x2b, 0xe1, 0x6f, 0xcf, 0xbd, 0xaa, 0x07, 0x97, 0x49, 0x4e, 0x02, 0x9d, 0xa5, 0x9e,
      0xc5, 0xd7, 0x8b, 0xd3, 0xe1, 0xd9, 0x35, 0x96, 0x9d, 0x1f, 0xa2, 0xf6, 0x91, 0xee, 0xd1, 0x3b,
      0xa8, 0xfe, 0x4d, 0xeb, 0xf9, 0xfc, 0xe4, 0xab, 0x60, 0xb7, 0x86, 0x9d, 0x2a, 0x35, 0xb0, 0x00,
      0xd4, 0x3c, 0x2a, 0x7e, 0x6d, 0x65, 0x5f, 0xf3, 0x7c, 0x23, 0x57, 0x52, 0x2a, 0x8c, 0x5b, 0x36,
      0x74, 0xb7, 0x61, 0x49, 0xf0, 0xdf, 0xcf, 0x8a, 0x28, 0xc5, 0x8d, 0xbc, 0x20, 0xcc, 0xac, 0x86,
      0x20, 0xd8, 0x2d, 0x86, 0x99, 0xf5, 0xf0, 0xdb, 0xed, 0x8d, 0xf9, 0xd7, 0x4e, 0xa8, 0xde, 0x84,
      0x35, 0x50, 0xc1, 0x7c, 0xbd, 0xdf, 0xc2, 0x24, 0x1a, 0x49, 0x24, 0x9a, 0x37, 0x93, 0xca, 0x2d,
      0x73, 0x47, 0x8f, 0x83, 0xed, 0x4d, 0xca, 0xf8, 0xf0, 0xd3, 0x9b, 0xe0, 0x4b, 0x3b, 0xf1, 0x86,
      0xeb, 0x78, 0x7b, 0x42, 0xa1, 0xb9, 0x36, 0x15, 0xde, 0x63, 0xab, 0x8b, 0x8b, 0x5d, 0xa2, 0x92,
      0x10, 0x95, 0xdf, 0xda, 0xd7, 0xba, 0xa0, 0x26, 0xb9, 0xdc, 0x83, 0xeb, 0xdc, 0xd2, 0x1f, 0xf1,
      0xb1, 0x8d, 0x21, 0x51, 0x71, 0x59, 0x0e, 0xe8, 0x7e, 0xf1, 0x53, 0x08, 0x98, 0x79, 0x05, 0x3b,
      0x22, 0xf1, 0xda, 0x07, 0x0d, 0xf7, 0x89, 0x5e, 0xc4, 0x62, 0x8c, 0xf9, 0x19, 0xc8, 0xbc, 0xa4,
      0x0c, 0x6f, 0x41, 0x34, 0x56, 0x22, 0x6b, 0xe6, 0xee, 0x7c, 0x4a, 0xd9, 0x26, 0x8c, 0x56, 0x12,
      0xf3, 0x03, 0x12, 0x1c, 0x5b, 0x8d, 0x64, 0x5c, 0x1c, 0xb6, 0x0f, 0x93, 0xaf, 0xb1, 0x67, 0x6f,
      0x13, 0xdd, 0xe3, 0xcf, 0x0e, 0xe6, 0x06, 0xf3, 0xb2, 0xbc, 0x99, 0xf5, 0xb0, 0xd7, 0xe9, 0x7e,
      0xb0, 0x6a, 0xb9, 0xb5, 0xda, 0xcf, 0x88, 0xf1, 0xc5, 0x58, 0x54, 0x05, 0x5c, 0x9d, 0x79, 0xc2,
      0xcd, 0xbb, 0xc6, 0xf2, 0x69, 0xa9, 0xe3, 0x4e, 0x05, 0x0d, 0x02, 0xb6, 0x4d, 0x8e, 0x7d, 0x60,
      0x8e, 0xda, 0x4d, 0x28, 0xd2, 0xec, 0x8a, 0x11, 0xe3, 0xe7, 0x17, 0x20, 0x07, 0x7b, 0xfc, 0x9b,
      0x4e, 0xf7, 0x79, 0xf5, 0x0a, 0x6e, 0xd1, 0x1e, 0x7b, 0x83, 0x66, 0x5e, 0x1b, 0x9d, 0x36, 0x32,
      0x89, 0xf6, 0x72, 0xa5, 0x58, 0x54, 0x42, 0xba, 0x90, 0xf3, 0xbb, 0x05, 0x46, 0xa4, 0x91, 0x1c,
      0xdb, 0xab, 0xf3, 0x68, 0x56, 0x7a, 0xd3, 0xff, 0x3f, 0x9f, 0xc5, 0x4a, 0x47, 0xbd, 0x89, 0x46,
      0xf6, 0x94, 0x3a, 0x94, 0xd4, 0x30, 0xd3, 0xae, 0x0d, 0x99, 0x95, 0xf7, 0x75, 0xfe, 0x14, 0x10,
      0x9e, 0xed, 0x21, 0x0f, 0x0d, 0x54, 0x7d, 0x54, 0xc5, 0x80, 0x21, 0x4d, 0xf2, 0xaf, 0x67, 0xaf,
      0x8a, 0x76, 0x9e, 0x34, 0x32, 0x74, 0x89, 0x2a, 0x32, 0xf9, 0x48, 0x20, 0x90, 0xe6, 0x4a, 0xa3,
      0x7f, 0xf2, 0x2a, 0x51, 0x22, 0x93, 0xe5, 0xdd, 0x59, 0xb3, 0x83, 0xa8, 0x47, 0xf5, 0x6b, 0x38,
      0x24, 0xc2, 0xac, 0x2d, 0x03, 0xda, 0xb1, 0x17, 0x19, 0xe0, 0x38, 0x2c, 0xb3, 0xa6, 0x4c, 0x8e,
      0xae, 0x63, 0xa7, 0xae, 0x96, 0xb1, 0x07, 0x8c, 0x8f, 0x6a, 0x08, 0x32, 0x15, 0x1f, 0x33, 0x97,
      0x21, 0x3b, 0x51, 0x70, 0xc5, 0x1f, 0xa6, 0xa3, 0x8a, 0xd0, 0x8f, 0x0b, 0xda, 0x64, 0xab, 0xbe,
      0xee, 0x4b, 0x14, 0xfd, 0x32, 0x87, 0x9e, 0xa7, 0x19, 0x75, 0xc9, 0xaa, 0xd3, 0xed, 0xa7, 0xa0,
      0x01, 0xe7, 0xa0, 0xe5, 0x28, 0xdd, 0x3b, 0x7c, 0x49, 0xe4, 0x24, 0x7d, 0x92, 0x86, 0x25, 0x03,
      0xb3, 0x66, 0x04, 0xf3, 0xa1, 0x40, 0x11, 0x35, 0x3a, 0x1d, 0xbf, 0x1c, 0x02, 0x83, 0x3d, 0x37,
      0x51, 0x88, 0xa3, 0x2b, 0x10, 0x8c, 0x8e, 0x10, 0xdd, 0xdc, 0xef, 0xa4, 0xe9, 0x14, 0x77, 0xb6,
      0x8e, 0x75, 0xb6, 0x8e, 0xea, 0xaa, 0x57, 0x16, 0x1f, 0xb0, 0x0c, 0xbc, 0x44, 0xed, 0x92, 0x94,
      0x9a, 0xb4, 0xf3, 0x31, 0x64, 0x02, 0x5c, 0xa1, 0x51, 0x63, 0x39, 0x42, 0x74, 0x7a, 0x1d, 0xf2,
      0xf5, 0x92, 0x50, 0xf1, 0x5a, 0x8a, 0xde, 0xb3, 0x4e, 0xf1, 0x6e, 0x67, 0xd9, 0x5b, 0x00, 0xa7,
      0xd1, 0x90, 0x58, 0x36, 0xc4, 0x15, 0x80, 0xbb, 0xa5, 0xbb, 0x98, 0xc0, 0x8a, 0x9b, 0x17, 0x35,
      0x36, 0x3b, 0x62, 0x0f, 0x29, 0xcd, 0xe9, 0x04, 0x0e, 0x9d, 0xca, 0x43, 0x04, 0xdf, 0x17, 0x49,
      0xbf, 0xb6, 0x7a, 0x7a, 0x3c, 0xdb, 0x0d, 0x6d, 0xd5, 0x89, 0xb9, 0x69, 0x94, 0xd8, 0xb2, 0xd6,
      0x38, 0x8a, 0xcc, 0x78, 0x44, 0x40, 0x63, 0x9f, 0x1e, 0x0e, 0x40, 0x33, 0x51, 0xd3, 0x65, 0xf8,
      0xf1, 0x42, 0x06, 0x75, 0x84, 0xe7, 0xb1, 0xe9, 0xd6, 0xa4, 0x5e, 0x7f, 0xb0, 0x48, 0x6f, 0x80,
      0x92, 0xf8, 0xfc, 0x2a, 0xdb, 0x18, 0x97, 0xe5, 0xe7, 0xc7, 0x46, 0xb6, 0x59, 0x8c, 0x3a, 0x09,
      0x91, 0xc1, 0x49, 0x55, 0xf9, 0xf3, 0x87, 0x19, 0xdc, 0x72, 0x56, 0xd3, 0x20, 0x5e, 0xc5, 0x3d,
      0xfb, 0x19, 0xea, 0x6a, 0xdf, 0x09, 0xb2, 0x8f, 0xb6, 0xdd, 0x26, 0x31, 0x25, 0x30, 0x23, 0x06,
      0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x15, 0x31, 0x16, 0x04, 0x14, 0x3b, 0xd2,
      0xb3, 0x51, 0x4c, 0x57, 0xd0, 0xca, 0x34, 0xa4, 0xf0, 0x06, 0xdd, 0xe9, 0x76, 0x08, 0xdb, 0x7b,
      0x3a, 0xb0, 0x30, 0x31, 0x30, 0x21, 0x30, 0x09, 0x06, 0x05, 0x2b, 0x0e, 0x03, 0x02, 0x1a, 0x05,
      0x00, 0x04, 0x14, 0x8e, 0x7f, 0x87, 0x67, 0x78, 0x64, 0x93, 0x36, 0x35, 0xe5, 0x93, 0x9d, 0xac,
      0x61, 0x09, 0x4f, 0xdc, 0x95, 0xd7, 0x4f, 0x04, 0x08, 0x23, 0xc2, 0xc0, 0xc6, 0x8d, 0x5f, 0x70,
      0x7e, 0x02, 0x02, 0x08, 0x00]);

    let conf: cert.Pkcs12ParsingConfig = {
      password: "123456",
      needsCert: false,
      needsPrivateKey: true,
      privateKeyFormat: cert.EncodingBaseFormat.DER,
      needsOtherCerts: false,
    };
    let p12: cert.Pkcs12Data = cert.parsePkcs12(p12_cert, conf);
    console.info("parsePKCS12 succeed.");
    if (p12.privateKey) {
      console.info("privateKey:" + p12.privateKey.toString())
    }
  } catch (error) {
    console.error('parsePKCS12 failed:' + JSON.stringify(error));
  }
}
```

## cert.createTrustAnchorsWithKeyStore<sup>12+</sup>

createTrustAnchorsWithKeyStore(keystore: Uint8Array, pwd: string): Promise<Array\<[X509TrustAnchor](#x509trustanchor11)>>

表示从P12文件中读取ca证书来构造[TrustAnchor](#x509trustanchor11)对象数组，并用Promise方式返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                  | 必填 | 说明                       |
| -------- | -------------------- | ---- | -------------------------- |
| keystore | Uint8Array | 是 | P12文件，DER格式。 |
| pwd | string | 是 | P12文件的密码。 |

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| Array\<[X509TrustAnchor](#x509trustanchor11)> | 表示X509TrustAnchor对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cert.createTrustAnchorsWithKeyStore(
    new Uint8Array([0x30, 0x82, 0x07, 0x5C, 0x02, 0x01, 0x03, 0x30, 0x82, 0x07, 0x12, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01, 0xA0, 0x82, 0x07, 0x03, 0x04, 0x82, 0x06, 0xFF, 0x30, 0x82, 0x06, 0xFB, 0x30, 0x82, 0x05, 0xB2, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x06, 0xA0, 0x82, 0x05, 0xA3, 0x30, 0x82, 0x05, 0x9F, 0x02, 0x01, 0x00, 0x30, 0x82, 0x05, 0x98, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01, 0x30, 0x57, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x05, 0x0D, 0x30, 0x4A, 0x30, 0x29, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x05, 0x0C, 0x30, 0x1C, 0x04, 0x08, 0xA9, 0x1C, 0x1B, 0x19, 0x36, 0xDE, 0xD4, 0x20, 0x02, 0x02, 0x08, 0x00, 0x30, 0x0C, 0x06, 0x08, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x02, 0x09, 0x05, 0x00, 0x30, 0x1D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x01, 0x2A, 0x04, 0x10, 0x7D, 0xE5, 0x23, 0x96, 0x18, 0x8B, 0xF4, 0xBC, 0x9F, 0x4E, 0xE8, 0xE9, 0xAA, 0x52, 0x18, 0x39, 0x80, 0x82, 0x05, 0x30, 0x02, 0x2D, 0x59, 0xA9, 0x96, 0x5A, 0xFE, 0x20, 0x18, 0xB2, 0x25, 0xEA, 0xFC, 0x86, 0x0F, 0xA8, 0x3C, 0x2B, 0x26, 0x2F, 0x44, 0x6E, 0xF3, 0x15, 0xB7, 0x94, 0xE4, 0x43, 0xEE, 0xE6, 0xC3, 0xBB, 0x3C, 0x9E, 0x60, 0x08, 0xF8, 0x15, 0x61, 0x44, 0xD0, 0xEA, 0xD5, 0x6D, 0x1A, 0x3B, 0x9F, 0x4E, 0x2A, 0x1E, 0xBB, 0xB9, 0x4E, 0x15, 0x43, 0xB8, 0x68, 0xDB, 0x1A, 0x4E, 0x41, 0xBA, 0x29, 0x8E, 0x75, 0xEB, 0x12, 0xC1, 0xF0, 0x4B, 0x0D, 0x13, 0xB2, 0xC2, 0x48, 0x6F, 0xC4, 0xC4, 0x82, 0xF2, 0x26, 0xD4, 0x3D, 0x1F, 0x42, 0x7D, 0x67, 0xB0, 0x37, 0x55, 0x9E, 0xD9, 0x46, 0x99, 0x98, 0xB4, 0xE7, 0x4B, 0x07, 0x08, 0x3F, 0xD3, 0x96, 0x9A, 0xC5, 0xDA, 0x37, 0x74, 0x08, 0x5D, 0x3B, 0x06, 0x8A, 0x16, 0x6D, 0x81, 0x63, 0x01, 0x83, 0x94, 0xDA, 0x1B, 0x0E, 0x04, 0xCE, 0x18, 0xF0, 0x51, 0x22, 0xD8, 0x2D, 0xF1, 0x69, 0x0C, 0xCB, 0xC9, 0x51, 0x17, 0x07, 0x1F, 0x2B, 0xCF, 0x74, 0x26, 0xD7, 0x73, 0xB3, 0x2D, 0xF2, 0x82, 0xF0, 0x38, 0x5B, 0x8A, 0x8F, 0xCD, 0x84, 0x69, 0x40, 0x59, 0xCE, 0xB3, 0x39, 0xFE, 0xF6, 0xB7, 0x24, 0x89, 0x34, 0xFF, 0xF4, 0x40, 0x50, 0x06, 0x4D, 0xC6, 0x13, 0x82, 0xAF, 0x7F, 0x84, 0xB1, 0x67, 0x3C, 0x89, 0xBB, 0x5D, 0x32, 0xC3, 0xA6, 0xF1, 0x7D, 0xF5, 0x72, 0x68, 0x75, 0xCE, 0x69, 0xAB, 0x6C, 0x32, 0xDA, 0x16, 0x3B, 0xC4, 0xCA, 0x47, 0x45, 0xE9, 0x59, 0x1E, 0xB1, 0x70, 0xDA, 0x8A, 0x00, 0x69, 0x80, 0x40, 0xCA, 0x60, 0xE6, 0x07, 0x16, 0xF0, 0xA2, 0xF9, 0x12, 0x7D, 0x09, 0x43, 0x66, 0x46, 0x78, 0x35, 0xA6, 0x94, 0x35, 0x60, 0x82, 0xFC, 0xB8, 0x5E, 0x39, 0xE7, 0xA1, 0x22, 0xAD, 0xCC, 0x6F, 0x5E, 0xCE, 0x01, 0x6B, 0xA1, 0xDD, 0xE5, 0xDD, 0x79, 0x9B, 0xA1, 0x28, 0xC4, 0x03, 0x84, 0x8D, 0x6C, 0x07, 0xD4, 0xFE, 0x57, 0xFB, 0x89, 0x3F, 0x43, 0x44, 0x69, 0xF1, 0x9E, 0x53, 0x6C, 0x11, 0x11, 0x96, 0x79, 0xE4, 0xB8, 0x3B, 0x49, 0x2E, 0xF6, 0x3B, 0xC5, 0x6C, 0x76, 0x21, 0x22, 0x15, 0x85, 0x77, 0x8A, 0xDD, 0xD2, 0x43, 0x85, 0x73, 0x39, 0x77, 0x9F, 0xFA, 0x8F, 0xCF, 0xCB, 0xEA, 0x62, 0xBD, 0x5C, 0x66, 0x45, 0xCD, 0xB0, 0xCA, 0x42, 0xCC, 0xB9, 0xCF, 0xE3, 0x84, 0x63, 0x9F, 0x63, 0xCE, 0x49, 0xE9, 0x74, 0x26, 0xCC, 0x26, 0x78, 0xCE, 0x9F, 0x4E, 0x38, 0xA2, 0x9C, 0xEB, 0x75, 0xC5, 0x33, 0x6B, 0x00, 0x83, 0x85, 0xA3, 0x0F, 0xE7, 0xE1, 0x11, 0xA6, 0x48, 0xDC, 0xEF, 0x0C, 0x05, 0xB3, 0xDE, 0x94, 0xB9, 0x69, 0xCB, 0x27, 0x09, 0xAB, 0x27, 0xD8, 0x06, 0xED, 0x25, 0xBC, 0xA6, 0x2E, 0xB7, 0xF9, 0x2E, 0xAD, 0x84, 0x1D, 0xDD, 0x73, 0xD8, 0xC0, 0x46, 0x8A, 0xFE, 0x9A, 0xDF, 0x07, 0xE1, 0x33, 0xE2, 0x1C, 0x37, 0x6A, 0x8E, 0xA2, 0x91, 0x0B, 0xD7, 0x76, 0xEF, 0x3C, 0x87, 0x4A, 0x53, 0x84, 0xFA, 0xFA, 0xC5, 0x71, 0x76, 0xC0, 0x75, 0x70, 0x67, 0x67, 0x71, 0x9D, 0x8B, 0x81, 0x6F, 0x68, 0xC5, 0xB1, 0xFC, 0xA3, 0x59, 0xB5, 0xD0, 0x03, 0x56, 0xE7, 0x89, 0x03, 0xD7, 0x99, 0xDE, 0x66, 0x33, 0xFA, 0x53, 0x50, 0x5F, 0xB4, 0x9D, 0xB3, 0x90, 0x8F, 0x57, 0x20, 0xF0, 0x8B, 0xDB, 0x73, 0xCA, 0xA4, 0x71, 0x61, 0x67, 0x6A, 0x6D, 0xA5, 0xCA, 0x88, 0xD4, 0xCC, 0x82, 0x34, 0xC9, 0x3E, 0x10, 0x10, 0x57, 0xD1, 0x08, 0x96, 0x80, 0x09, 0xA8, 0xBB, 0x6F, 0x53, 0x8F, 0xFD, 0x87, 0xCF, 0x73, 0xFC, 0xE1, 0x3A, 0x92, 0x2E, 0x78, 0x66, 0xFB, 0x86, 0x5D, 0x62, 0xE0, 0xC4, 0x58, 0x55, 0x3F, 0xA4, 0xEA, 0xA1, 0xBE, 0x5B, 0x5E, 0x8E, 0x46, 0x50, 0x5E, 0x7C, 0x01, 0xD6, 0x63, 0xAA, 0x6F, 0xD5, 0xFD, 0xAF, 0xC5, 0x1D, 0xB3, 0x90, 0x9C, 0xD8, 0x5F, 0x8D, 0xF2, 0x81, 0xEB, 0xBF, 0xA1, 0xDE, 0xB7, 0x9D, 0xCD, 0x24, 0x82, 0x06, 0x0B, 0x63, 0xE6, 0xBF, 0x57, 0x51, 0xF0, 0xB6, 0xE9, 0x7F, 0xAA, 0x7B, 0x10, 0xBD, 0xCD, 0x85, 0x41, 0xE0, 0xD7, 0xF1, 0x53, 0xB7, 0xF8, 0x46, 0x91, 0x9E, 0x8D, 0x4B, 0xCB, 0x28, 0x35, 0x40, 0x37, 0x1E, 0x83, 0x64, 0x6A, 0x70, 0x01, 0x9D, 0xBF, 0xF1, 0x0E, 0xB6, 0x2E, 0x7A, 0xB7, 0x8F, 0x0F, 0x8C, 0x69, 0xD6, 0xF2, 0xD1, 0xF6, 0x1E, 0xCD, 0x08, 0xA8, 0xD4, 0x1B, 0xCB, 0x38, 0xEA, 0x26, 0x37, 0x5C, 0x60, 0x3A, 0x38, 0x5B, 0x12, 0x1D, 0x00, 0x7B, 0xEC, 0xCE, 0xFB, 0x89, 0x23, 0x8A, 0x11, 0xE1, 0x1B, 0xDE, 0x54, 0x91, 0x6A, 0x26, 0x22, 0xD0, 0x1C, 0x2E, 0xBA, 0xD0, 0x92, 0x87, 0xDA, 0xF0, 0x93, 0xBB, 0x3A, 0x2C, 0x52, 0xFB, 0xB2, 0xA9, 0xA8, 0x92, 0x19, 0xE3, 0x19, 0xDC, 0xB0, 0x0E, 0xC5, 0xE7, 0x9D, 0xFB, 0xF9, 0xA3, 0x23, 0x32, 0xD0, 0x4E, 0x2C, 0x05, 0x2D, 0x76, 0xDB, 0x93, 0x53, 0x5B, 0x0E, 0x2A, 0xA3, 0xDD, 0x5F, 0xD3, 0x1A, 0x3B, 0x1E, 0x1F, 0x26, 0x88, 0x43, 0xAD, 0x10, 0x1F, 0xA9, 0xC4, 0xF9, 0x1F, 0xCD, 0xA5, 0xD2, 0xDC, 0x24, 0x95, 0x1D, 0xE7, 0x57, 0xE1, 0x02, 0x0A, 0x20, 0xEA, 0x6A, 0x78, 0x4E, 0x96, 0xE2, 0xE5, 0x6D, 0x6F, 0xFD, 0x81, 0x7B, 0x61, 0x85, 0xA3, 0x3D, 0xC5, 0x7B, 0xEF, 0xAE, 0x58, 0xA2, 0xDB, 0x91, 0x73, 0xDB, 0x47, 0x8E, 0xD1, 0x7D, 0xD7, 0x8F, 0x56, 0x06, 0x28, 0x8C, 0x78, 0x73, 0x02, 0x65, 0xB0, 0x16, 0x4B, 0xE6, 0xA3, 0xD7, 0x06, 0x7C, 0xEA, 0x7D, 0xE2, 0xAE, 0xBB, 0xE5, 0xD2, 0xEB, 0xF0, 0x91, 0x71, 0x7C, 0xBC, 0xA6, 0x1A, 0xE8, 0x9F, 0xD3, 0xA9, 0x3C, 0x5D, 0x60, 0xCF, 0x59, 0x26, 0x46, 0x45, 0xF2, 0x7F, 0x85, 0x6B, 0xE7, 0xC2, 0x58, 0x52, 0x90, 0x12, 0x07, 0xBA, 0xE6, 0xB8, 0xE5, 0xD7, 0x24, 0x93, 0xD5, 0x6E, 0xB1, 0x74, 0x6C, 0xAA, 0xA0, 0x60, 0xBF, 0xF3, 0x32, 0x41, 0x0B, 0xA2, 0x01, 0x84, 0x0D, 0x83, 0xE4, 0x43, 0xD1, 0xBA, 0xC1, 0x92, 0x84, 0x26, 0xF8, 0xF2, 0x77, 0x20, 0x1B, 0xF2, 0x8F, 0x00, 0x69, 0x18, 0x2F, 0x6C, 0xA8, 0x58, 0xB5, 0x5D, 0xFA, 0x27, 0xD2, 0x38, 0xD2, 0x49, 0x6E, 0xDF, 0x55, 0x79, 0xAF, 0x1C, 0x44, 0xDA, 0x5A, 0xD7, 0x44, 0x53, 0x50, 0x8B, 0x77, 0x70, 0x4D, 0x91, 0xEC, 0x07, 0xA5, 0x64, 0x21, 0x3C, 0x31, 0x09, 0x68, 0x65, 0xB4, 0xFA, 0xBE, 0x23, 0xF9, 0xDF, 0x77, 0x46, 0xA2, 0x9A, 0x5D, 0xE3, 0xBE, 0x1E, 0xE3, 0x84, 0xEF, 0xAE, 0x7D, 0xF8, 0x1C, 0x54, 0xE8, 0x4E, 0xAE, 0xB5, 0xBB, 0xD6, 0xC3, 0x8D, 0x56, 0x79, 0xE8, 0x7C, 0x43, 0xDC, 0xF3, 0xB3, 0x7A, 0x30, 0x22, 0x09, 0xBC, 0x10, 0xD6, 0x84, 0xC4, 0x0F, 0x4C, 0x0B, 0xA2, 0xD1, 0xCB, 0xCD, 0x1F, 0x50, 0x3D, 0xF7, 0x23, 0x45, 0x55, 0x18, 0x21, 0x3D, 0x64, 0x05, 0x2E, 0x52, 0x3A, 0x73, 0xFD, 0xF2, 0xA9, 0xCA, 0x3F, 0xF6, 0x7F, 0x87, 0xE8, 0x56, 0x9B, 0x68, 0x6B, 0x20, 0xB0, 0x1D, 0x83, 0x04, 0x2F, 0x59, 0xFD, 0x84, 0x57, 0x7D, 0x82, 0x97, 0x96, 0xE8, 0xFB, 0xDF, 0x71, 0x8C, 0x26, 0x47, 0x85, 0xA5, 0xBE, 0xFB, 0xF5, 0x05, 0x4C, 0xD3, 0x3D, 0x73, 0xF4, 0xA5, 0xF1, 0xA3, 0x99, 0x98, 0x1B, 0x84, 0x8B, 0xB3, 0x53, 0xCE, 0x4D, 0xEA, 0x5A, 0x48, 0xD2, 0xB9, 0x7E, 0xB6, 0xEB, 0x9B, 0x94, 0x6F, 0xDD, 0x44, 0x80, 0x89, 0xD2, 0x78, 0x6D, 0xB9, 0xDA, 0x8B, 0x83, 0x49, 0xE0, 0x4D, 0x49, 0xDF, 0x6B, 0xFF, 0xF7, 0x04, 0x00, 0x32, 0xAA, 0x1D, 0x4F, 0x8D, 0x4B, 0xDE, 0xB8, 0x0D, 0xC6, 0x54, 0x1C, 0xB2, 0xCD, 0x60, 0x29, 0x72, 0x0A, 0x7E, 0xE7, 0xEB, 0x7A, 0xF6, 0x5B, 0x04, 0x3F, 0x5B, 0x93, 0x12, 0x0D, 0xD5, 0xFF, 0x7A, 0x41, 0x44, 0x0B, 0x37, 0x12, 0x82, 0x3D, 0xDD, 0x1E, 0x59, 0xB9, 0xBE, 0x0F, 0x9E, 0xD6, 0xD0, 0x68, 0x69, 0x74, 0xF9, 0xB1, 0x21, 0xA3, 0x70, 0x4F, 0xDA, 0xF8, 0x9F, 0xB9, 0x49, 0x3F, 0xC6, 0xB2, 0x69, 0xC8, 0xD8, 0x60, 0xF1, 0x6A, 0x52, 0x07, 0xFA, 0x42, 0xFD, 0xA9, 0x06, 0xCF, 0x97, 0x4A, 0x0E, 0xC5, 0xFC, 0x63, 0x27, 0x54, 0xC8, 0xBE, 0x8B, 0x4F, 0xB6, 0x42, 0xBC, 0xA2, 0xCC, 0x70, 0x4A, 0x6B, 0x24, 0x5B, 0x68, 0x28, 0x47, 0xFA, 0x6B, 0x89, 0x28, 0x07, 0x5D, 0xE0, 0x2C, 0x4A, 0xD9, 0x22, 0xE3, 0xB3, 0x2F, 0xAA, 0xC2, 0xA0, 0x7C, 0x0F, 0x92, 0xC5, 0xDD, 0xB6, 0x23, 0x8F, 0x73, 0x73, 0x0F, 0xD7, 0x73, 0x71, 0x2F, 0x0A, 0x78, 0xE8, 0x5B, 0xDB, 0xC2, 0xE0, 0xDB, 0xC9, 0x3E, 0xC3, 0x72, 0x9C, 0x14, 0xD7, 0xD1, 0x28, 0xFD, 0xF4, 0xEE, 0xBC, 0x0E, 0x13, 0x37, 0xCA, 0x85, 0x9F, 0xB9, 0xA2, 0x0E, 0xF6, 0xE7, 0x49, 0xD1, 0xD0, 0x11, 0x76, 0x53, 0xA3, 0x73, 0x95, 0x2A, 0x23, 0xC8, 0x0E, 0x97, 0x83, 0x07, 0x64, 0xB2, 0x51, 0xB7, 0xC8, 0x51, 0x9F, 0xA4, 0x3E, 0x7B, 0xA4, 0x18, 0x6D, 0x99, 0xF0, 0x6E, 0xC3, 0x97, 0xAE, 0xF4, 0xB7, 0x66, 0x37, 0xFA, 0x65, 0xFC, 0x5E, 0xE2, 0x57, 0xFA, 0x8B, 0x4C, 0x86, 0x10, 0xB4, 0x5C, 0xA4, 0xD2, 0x60, 0x83, 0x69, 0x1E, 0xFF, 0x36, 0x9B, 0xF9, 0x84, 0xFB, 0xB8, 0x83, 0x64, 0xF1, 0x41, 0xA5, 0x25, 0x56, 0x21, 0xBA, 0x13, 0x98, 0x0C, 0x3B, 0x04, 0xAA, 0x6C, 0x9A, 0xD4, 0xE3, 0x13, 0x15, 0x54, 0x05, 0x4C, 0x5C, 0xE1, 0x7A, 0x31, 0x5E, 0x90, 0xCF, 0x48, 0x4E, 0x83, 0xD7, 0x7F, 0xED, 0x93, 0x22, 0xAB, 0x67, 0xE7, 0x76, 0x32, 0x64, 0xBA, 0x5A, 0x21, 0x3E, 0x30, 0x82, 0x01, 0x41, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01, 0xA0, 0x82, 0x01, 0x32, 0x04, 0x82, 0x01, 0x2E, 0x30, 0x82, 0x01, 0x2A, 0x30, 0x82, 0x01, 0x26, 0x06, 0x0B, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x0C, 0x0A, 0x01, 0x02, 0xA0, 0x81, 0xEF, 0x30, 0x81, 0xEC, 0x30, 0x57, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x05, 0x0D, 0x30, 0x4A, 0x30, 0x29, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x05, 0x0C, 0x30, 0x1C, 0x04, 0x08, 0xED, 0x3E, 0xED, 0x07, 0x5C, 0x1F, 0x71, 0xAD, 0x02, 0x02, 0x08, 0x00, 0x30, 0x0C, 0x06, 0x08, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x02, 0x09, 0x05, 0x00, 0x30, 0x1D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x01, 0x2A, 0x04, 0x10, 0xA7, 0x49, 0xA4, 0x6E, 0x00, 0x19, 0x75, 0x59, 0x75, 0x59, 0xBA, 0x4B, 0xC7, 0x24, 0x88, 0x34, 0x04, 0x81, 0x90, 0xCA, 0x23, 0x82, 0xAA, 0x16, 0x57, 0x99, 0xFA, 0x94, 0x9F, 0xAE, 0x32, 0x5C, 0x5B, 0xE7, 0x01, 0xD0, 0xED, 0xA7, 0x58, 0x57, 0x52, 0xBF, 0x57, 0x13, 0xD4, 0x15, 0xB0, 0x06, 0xF5, 0x38, 0xCC, 0x64, 0x23, 0x09, 0xD5, 0x8C, 0x0D, 0x64, 0x31, 0xFA, 0x74, 0xAA, 0x96, 0x7E, 0x9B, 0x16, 0xCA, 0x21, 0xFD, 0xC0, 0x54, 0x91, 0x40, 0x7F, 0xB3, 0xF2, 0xA3, 0xEC, 0xA1, 0x4A, 0x07, 0xF0, 0x87, 0x22, 0xDB, 0x8A, 0x49, 0x89, 0xF7, 0xF2, 0x6A, 0xFC, 0x8D, 0x03, 0x6E, 0x32, 0x4F, 0xD0, 0xD8, 0x93, 0x92, 0xA5, 0xF1, 0x41, 0xBD, 0xEA, 0xE1, 0x38, 0xA9, 0xD8, 0x9D, 0xAB, 0xB4, 0x8E, 0x4A, 0x40, 0x0E, 0xC7, 0xE3, 0xE9, 0xBF, 0x0E, 0xBA, 0x8D, 0xAA, 0x3E, 0x93, 0x53, 0x88, 0xEE, 0x0A, 0x2C, 0x71, 0xF1, 0x61, 0x44, 0xA5, 0xAD, 0xED, 0x3E, 0xAB, 0x32, 0x9A, 0x32, 0x85, 0x08, 0xF5, 0x8B, 0xCC, 0x15, 0x35, 0xEE, 0xFA, 0x17, 0x27, 0x97, 0x8D, 0xD9, 0x1C, 0x5E, 0x74, 0x9D, 0x7B, 0x31, 0x25, 0x30, 0x23, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x15, 0x31, 0x16, 0x04, 0x14, 0x5F, 0x8E, 0xAB, 0x9C, 0x5F, 0xE2, 0x3B, 0xB1, 0x5C, 0x1A, 0x36, 0x1D, 0x7D, 0xCB, 0x90, 0x45, 0x20, 0x3C, 0x3B, 0xAC, 0x30, 0x41, 0x30, 0x31, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x04, 0x20, 0x93, 0x25, 0xC4, 0x3E, 0x2A, 0x6D, 0x4C, 0x30, 0x87, 0x0F, 0xE3, 0x5A, 0x95, 0xB0, 0xF2, 0x6C, 0xBA, 0x07, 0x89, 0x7D, 0xFB, 0xCF, 0xCF, 0x1D, 0x54, 0xA3, 0x36, 0x24, 0x7B, 0x30, 0x97, 0xB5, 0x04, 0x08, 0xE7, 0x96, 0x59, 0xCC, 0x42, 0x9F, 0xEF, 0xFC, 0x02, 0x02, 0x08, 0x00]),
    '123456').then((data) => {
      console.log('createTrustAnchorsWithKeyStore sucess, number of the result is: ' + JSON.stringify(data.length));
  }).catch((err : BusinessError) => {
    console.error('createTrustAnchorsWithKeyStore failed:' + JSON.stringify(err));
  })
} catch (error) {
  console.error('createTrustAnchorsWithKeyStore failed:' + JSON.stringify(error));
}
```

## X509CertChain<sup>11+</sup>

X509证书链对象。

### getCertList<sup>11+</sup>

getCertList(): Array\<X509Cert>

获取X509证书列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型           | 说明        |
| -------------- | ----------- |
| Array\<[X509Cert](#x509cert)> | X509证书数组。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// 证书链二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

cert.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
    try {
      let certList = certChain.getCertList();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('X509CertChain getCertList failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### validate<sup>11+</sup>

validate(param: CertChainValidationParameters): Promise\<CertChainValidationResult>

校验证书链，并使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明            |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [CertChainValidationParameters](#certchainvalidationparameters11) | 是   | 表示校验X509证书链的参数。 |

**返回值**：

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[CertChainValidationResult](#certchainvalidationresult11)> | Promise对象，返回证书链校验结果。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19020002 | runtime error. |
| 19030001 | crypto operation error.           |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect.           |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer.           |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.      |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CertChain(): Promise<cert.X509CertChain> {
  let certChainData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
    "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
    "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
    "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
    "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
    "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
    "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
    "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
    "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
    "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
    "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
    "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
    "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
    "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
    "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
    "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
    "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
    "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
    "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
    "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
    "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n" +
    "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
    "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
    "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
    "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
    "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
    "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
    "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
    "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
    "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
    "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
    "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
    "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
    "uKPWR9dKBA==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n"  +
    "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
    "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
    "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
    "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
    "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
    "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
    "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
    "xjoE\n" +
    "-----END CERTIFICATE-----\n";

  // 证书链二进制数据，需业务自行赋值。
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certChainData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
  }
  catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

async function validate() {
  const certChain = await createX509CertChain();
  // 证书链校验数据，需业务自行赋值。
  const param: cert.CertChainValidationParameters = {
    date: '20231212080000Z',
    trustAnchors: [{
        CAPubKey: new Uint8Array([0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03, 0x21, 0x00, 0xbb, 0x16,0x9d, 0x8f, 0x5c, 0x30, 0xd0, 0xba, 0x8f, 0x37, 0x6e, 0x33, 0xaf, 0x6f, 0x23, 0x71, 0x23, 0xa5, 0x49, 0x60,0x1e, 0xd1, 0x07, 0x4b, 0xc9, 0x11, 0x7e, 0x66, 0x01, 0xba, 0x92, 0x52]),
        CASubject: new Uint8Array([0x30, 0x5a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x45,0x4e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x45, 0x6e, 0x67, 0x6c, 0x61, 0x6e,0x64, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x06, 0x4c, 0x6f, 0x6e, 0x64, 0x6f, 0x6e,0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a,0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04,0x03, 0x13, 0x03, 0x74, 0x73, 0x31]),
    }]
  }
  try {
    const validationRes = await certChain.validate(param);
    console.log('X509CertChain validate success');
  }
  catch (err) {
    console.error('X509CertChain validate failed');
  }
}

validate();
```

### validate<sup>11+</sup>

validate(param: CertChainValidationParameters, callback: AsyncCallback\<CertChainValidationResult>): void

使用校验参数校验证书链并使用callback方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名    | 类型                            | 必填 | 说明      |
| --------- | ------------------------------- | ---- | ------------ |
| param | [CertChainValidationParameters](#certchainvalidationparameters11) | 是   | 表示校验X509证书链的参数。 |
| callback  | AsyncCallback\<[CertChainValidationResult](#certchainvalidationresult11)> | 是   | 回调函数，返回证书链校验结果。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error.           |
| 19020002 | runtime error. |
| 19030001 | crypto operation error.           |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect.           |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer.           |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.      |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// 证书链二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

// 证书链校验数据，需业务自行赋值。
let param: cert.CertChainValidationParameters = {
  date: '20231212080000Z',
  trustAnchors: [{
    CAPubKey: new Uint8Array([0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03, 0x21, 0x00, 0xbb, 0x16,0x9d, 0x8f, 0x5c, 0x30, 0xd0, 0xba, 0x8f, 0x37, 0x6e, 0x33, 0xaf, 0x6f, 0x23, 0x71, 0x23, 0xa5, 0x49, 0x60,0x1e, 0xd1, 0x07, 0x4b, 0xc9, 0x11, 0x7e, 0x66, 0x01, 0xba, 0x92, 0x52]),
    CASubject: new Uint8Array([0x30, 0x5a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x45,0x4e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x45, 0x6e, 0x67, 0x6c, 0x61, 0x6e,0x64, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x06, 0x4c, 0x6f, 0x6e, 0x64, 0x6f, 0x6e,0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a,0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04,0x03, 0x13, 0x03, 0x74, 0x73, 0x31]),
  }]
};

cert.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
    certChain.validate(param, (error, validationRes) => {
      if (error) {
        console.error('X509CertChain validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('X509CertChain validate success');
      }
    });
  }
});
```

### toString<sup>12+</sup>

toString(): string

获取对象的字符串类型数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| string | 对象的字符串类型数据。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIGVjCCBT6gAwIBAgIQBMO0W3CU9LWVw1bE/jqYojANBgkqhkiG9w0BAQsFADBE\n' +
  'MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMR4wHAYDVQQDExVH\n' +
  'ZW9UcnVzdCBSU0EgQ04gQ0EgRzIwHhcNMjMwMzIzMDAwMDAwWhcNMjQwNDIyMjM1\n' +
  'OTU5WjB1MQswCQYDVQQGEwJDTjERMA8GA1UECBMIemhlamlhbmcxETAPBgNVBAcT\n' +
  'CGhhbmd6aG91MSwwKgYDVQQKEyNOZXRFYXNlIChIYW5nemhvdSkgTmV0d29yayBD\n' +
  'by4sIEx0ZDESMBAGA1UEAwwJKi4xNjMuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOC\n' +
  'AQ8AMIIBCgKCAQEAwELks0Q1Z81u1OpbGdEFE2Snm/WpLfmiC5YFj5nFrinSX+UZ\n' +
  'MIk42euBdjYSsWFxbljmWDdUCjstMhG8vRAjz3Nt1QniMCunHHFGujR5rSNLWYHE\n' +
  'vCPhfptIhqOaE/rvkWGZZr2KjTQQN0dRf8dm9Oewy8DHu95c9jW6c9AVgKWUVOni\n' +
  'tTOcJCnrndWjgCIPfKmKgrwaNaMnuQyy5nPIUHl/5EGzuGHrwjwlF+w+cT+Fwdix\n' +
  'C3msEOCwX6wzo6baDs4og2EzuPNyTp4n4UqH5aHhLePgBFboOAyJwWp3+XJNpNGw\n' +
  'GkU56cUUy7+AAn268EVvUNr7uQ65t2t+Ys32bQIDAQABo4IDETCCAw0wHwYDVR0j\n' +
  'BBgwFoAUJG+RP4mHhw4ywkAY38VM60/ISTIwHQYDVR0OBBYEFD1HyRYJ5jqkvYL7\n' +
  'C6TSt8/y3e7hMB0GA1UdEQQWMBSCCSouMTYzLmNvbYIHMTYzLmNvbTAOBgNVHQ8B\n' +
  'Af8EBAMCBaAwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMD0GA1UdHwQ2\n' +
  'MDQwMqAwoC6GLGh0dHA6Ly9jcmwuZGlnaWNlcnQuY24vR2VvVHJ1c3RSU0FDTkNB\n' +
  'RzIuY3JsMD4GA1UdIAQ3MDUwMwYGZ4EMAQICMCkwJwYIKwYBBQUHAgEWG2h0dHA6\n' +
  'Ly93d3cuZGlnaWNlcnQuY29tL0NQUzBxBggrBgEFBQcBAQRlMGMwIwYIKwYBBQUH\n' +
  'MAGGF2h0dHA6Ly9vY3NwLmRpZ2ljZXJ0LmNuMDwGCCsGAQUFBzAChjBodHRwOi8v\n' +
  'Y2FjZXJ0cy5kaWdpY2VydC5jbi9HZW9UcnVzdFJTQUNOQ0FHMi5jcnQwCQYDVR0T\n' +
  'BAIwADCCAX4GCisGAQQB1nkCBAIEggFuBIIBagFoAHUA7s3QZNXbGs7FXLedtM0T\n' +
  'ojKHRny87N7DUUhZRnEftZsAAAGHDSE15QAABAMARjBEAiBRpmsJ3F9AI8wFxqOQ\n' +
  'bHp+RL6F8cvNydajQ0Bqxjvd3AIgefAU/po3jBm+96dFVdbX+AG1uss67DL3VL5I\n' +
  'nUmVva8AdgBz2Z6JG0yWeKAgfUed5rLGHNBRXnEZKoxrgBB6wXdytQAAAYcNITZS\n' +
  'AAAEAwBHMEUCID/sUP12odF7uTTEyE0PjCpKo3nF7A3ba3b5wJJsZrDrAiEAxrat\n' +
  'W2eeZTD458LPSPrMMBb1/o6zibWXqJCQye+bVFwAdwBIsONr2qZHNA/lagL6nTDr\n' +
  'HFIBy1bdLIHZu7+rOdiEcwAAAYcNITYeAAAEAwBIMEYCIQCCJ2ktM1F+d1I5mQju\n' +
  'Tn7oDYxy3GCGyG3u/yhu8k7EaAIhANSP8cAaMQFV6y8B2tubKY5eSQtgkF3a6NNq\n' +
  'QJjtPnoHMA0GCSqGSIb3DQEBCwUAA4IBAQC8dK/G4nvs/SyQe/mnK+rUYIdSFs+4\n' +
  'lgzatmq8V/I1tBly+Sv/FPhnn4F3iCrqy9j8y202FP51ev95DGbjlJRTIFPqVAO8\n' +
  'ywYrLhvl1SJhV0b/8NF0Pr3dZVnK5Vfn11+LSBUg0cBB2hcVV30nv3IuVhz3d12n\n' +
  'P+VseYQgMpQf7ad+ttpZtA7yqHzrUm4fzr03G7q88GztACRSHoYiPbOlz99SeTgW\n' +
  '7bzZl1I4taxy2Q3b0ZBGfUt/kPY05tpKzKwDTbbqSErYszCt5X1RfVvf3coxF8Mo\n' +
  '9bHbs2wYIzQBdujDQ/hU0u6ItERer3SUItZoxaSIxdrZ9eXFwVvXsT/g\n' +
  '-----END CERTIFICATE-----\n' +
  '-----BEGIN CERTIFICATE-----\n' +
  'MIIFDzCCA/egAwIBAgIQCxNitu5qnT6WiTDxbiB9OTANBgkqhkiG9w0BAQsFADBh\n' +
  'MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n' +
  'd3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n' +
  'QTAeFw0yMDAzMDQxMjA0NDBaFw0zMDAzMDQxMjA0NDBaMEQxCzAJBgNVBAYTAlVT\n' +
  'MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxHjAcBgNVBAMTFUdlb1RydXN0IFJTQSBD\n' +
  'TiBDQSBHMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANA1OZJJtZUI\n' +
  '7zj4qFHT79g+Otks4TEfmUEDhrNKBEEjb/i29GBfnpvFdT36azCg2VODJRSjIzFn\n' +
  '4qADcc84EmfKiDEM97HFsQPp9RRkqxH5cB51EU2eBE9Ua95x+wQp/KSdCqITCQ/v\n' +
  'yvm3J4Upjl0wlW8wRCPCWcYw3pKClGRkNzVtI1KXnfpn7fG3N84n7wlBb9IGKJFa\n' +
  'c/6+hxvZx2qnfLsxdIKR0Q/biGoU6Z8Iy/R/p7GoPO8vamV090+QHEL5AdSzKtEh\n' +
  'U9vdvcuWjjLxVnaJLfj/6WoGZj8UWn3zFbEoTVaAfp2xqdzW7yRvi2r148m9ev7l\n' +
  'jDqHo8UX69sCAwEAAaOCAd4wggHaMB0GA1UdDgQWBBQkb5E/iYeHDjLCQBjfxUzr\n' +
  'T8hJMjAfBgNVHSMEGDAWgBQD3lA1VtFMu2bwo+IbG8OXsj3RVTAOBgNVHQ8BAf8E\n' +
  'BAMCAYYwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMBIGA1UdEwEB/wQI\n' +
  'MAYBAf8CAQAwMwYIKwYBBQUHAQEEJzAlMCMGCCsGAQUFBzABhhdodHRwOi8vb2Nz\n' +
  'cC5kaWdpY2VydC5jbjBABgNVHR8EOTA3MDWgM6Axhi9odHRwOi8vY3JsLmRpZ2lj\n' +
  'ZXJ0LmNuL0RpZ2lDZXJ0R2xvYmFsUm9vdENBLmNybDCB3QYDVR0gBIHVMIHSMIHF\n' +
  'BglghkgBhv1sAQEwgbcwKAYIKwYBBQUHAgEWHGh0dHBzOi8vd3d3LmRpZ2ljZXJ0\n' +
  'LmNvbS9DUFMwgYoGCCsGAQUFBwICMH4MfEFueSB1c2Ugb2YgdGhpcyBDZXJ0aWZp\n' +
  'Y2F0ZSBjb25zdGl0dXRlcyBhY2NlcHRhbmNlIG9mIHRoZSBSZWx5aW5nIFBhcnR5\n' +
  'IEFncmVlbWVudCBsb2NhdGVkIGF0IGh0dHBzOi8vd3d3LmRpZ2ljZXJ0LmNvbS9y\n' +
  'cGEtdWEwCAYGZ4EMAQICMA0GCSqGSIb3DQEBCwUAA4IBAQCzkcXq0TN0oSn4UeXp\n' +
  'FBW7U8zrHBIhH9MXHNBp+Yy/yN19133UY05uuHXHaU2Uv0hxefckjPdkaX7ARso+\n' +
  'O3Ar6nf7YfBwCqSpqsNckKT7KKtf3Ot95wYFpKDa64jcRUfxzRWnmq12IVzczqHI\n' +
  'sIvUZQINw/UHSQcWekdUnMg58bQSHyTjwkj9jcX2RURxaVZkr15wxo/Z3Ydo2PVK\n' +
  '3afEr0/vcuFvE7QeGXiI2DJdVt3JefatZ3rj4VTW2aUZwHGUiWWIUudBfQKR0JEp\n' +
  'lJ8MFaKDh4/A2VEJnXILu1iwvc1m3jCaPuzZKdoHM/1234bznJI2aAfhfIhoHw90\n' +
  'tPO+\n' +
  '-----END CERTIFICATE-----\n';

// 证书链二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certChainToString() {
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
    console.log('createX509CertChain success');
    console.info('toString success: ' + JSON.stringify(x509CertChain.toString()));
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```
### hashCode<sup>12+</sup>

hashCode(): Uint8Array

获取DER格式数据的哈希值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| Uint8Array | DER格式数据的哈希值。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIGVjCCBT6gAwIBAgIQBMO0W3CU9LWVw1bE/jqYojANBgkqhkiG9w0BAQsFADBE\n' +
  'MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMR4wHAYDVQQDExVH\n' +
  'ZW9UcnVzdCBSU0EgQ04gQ0EgRzIwHhcNMjMwMzIzMDAwMDAwWhcNMjQwNDIyMjM1\n' +
  'OTU5WjB1MQswCQYDVQQGEwJDTjERMA8GA1UECBMIemhlamlhbmcxETAPBgNVBAcT\n' +
  'CGhhbmd6aG91MSwwKgYDVQQKEyNOZXRFYXNlIChIYW5nemhvdSkgTmV0d29yayBD\n' +
  'by4sIEx0ZDESMBAGA1UEAwwJKi4xNjMuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOC\n' +
  'AQ8AMIIBCgKCAQEAwELks0Q1Z81u1OpbGdEFE2Snm/WpLfmiC5YFj5nFrinSX+UZ\n' +
  'MIk42euBdjYSsWFxbljmWDdUCjstMhG8vRAjz3Nt1QniMCunHHFGujR5rSNLWYHE\n' +
  'vCPhfptIhqOaE/rvkWGZZr2KjTQQN0dRf8dm9Oewy8DHu95c9jW6c9AVgKWUVOni\n' +
  'tTOcJCnrndWjgCIPfKmKgrwaNaMnuQyy5nPIUHl/5EGzuGHrwjwlF+w+cT+Fwdix\n' +
  'C3msEOCwX6wzo6baDs4og2EzuPNyTp4n4UqH5aHhLePgBFboOAyJwWp3+XJNpNGw\n' +
  'GkU56cUUy7+AAn268EVvUNr7uQ65t2t+Ys32bQIDAQABo4IDETCCAw0wHwYDVR0j\n' +
  'BBgwFoAUJG+RP4mHhw4ywkAY38VM60/ISTIwHQYDVR0OBBYEFD1HyRYJ5jqkvYL7\n' +
  'C6TSt8/y3e7hMB0GA1UdEQQWMBSCCSouMTYzLmNvbYIHMTYzLmNvbTAOBgNVHQ8B\n' +
  'Af8EBAMCBaAwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMD0GA1UdHwQ2\n' +
  'MDQwMqAwoC6GLGh0dHA6Ly9jcmwuZGlnaWNlcnQuY24vR2VvVHJ1c3RSU0FDTkNB\n' +
  'RzIuY3JsMD4GA1UdIAQ3MDUwMwYGZ4EMAQICMCkwJwYIKwYBBQUHAgEWG2h0dHA6\n' +
  'Ly93d3cuZGlnaWNlcnQuY29tL0NQUzBxBggrBgEFBQcBAQRlMGMwIwYIKwYBBQUH\n' +
  'MAGGF2h0dHA6Ly9vY3NwLmRpZ2ljZXJ0LmNuMDwGCCsGAQUFBzAChjBodHRwOi8v\n' +
  'Y2FjZXJ0cy5kaWdpY2VydC5jbi9HZW9UcnVzdFJTQUNOQ0FHMi5jcnQwCQYDVR0T\n' +
  'BAIwADCCAX4GCisGAQQB1nkCBAIEggFuBIIBagFoAHUA7s3QZNXbGs7FXLedtM0T\n' +
  'ojKHRny87N7DUUhZRnEftZsAAAGHDSE15QAABAMARjBEAiBRpmsJ3F9AI8wFxqOQ\n' +
  'bHp+RL6F8cvNydajQ0Bqxjvd3AIgefAU/po3jBm+96dFVdbX+AG1uss67DL3VL5I\n' +
  'nUmVva8AdgBz2Z6JG0yWeKAgfUed5rLGHNBRXnEZKoxrgBB6wXdytQAAAYcNITZS\n' +
  'AAAEAwBHMEUCID/sUP12odF7uTTEyE0PjCpKo3nF7A3ba3b5wJJsZrDrAiEAxrat\n' +
  'W2eeZTD458LPSPrMMBb1/o6zibWXqJCQye+bVFwAdwBIsONr2qZHNA/lagL6nTDr\n' +
  'HFIBy1bdLIHZu7+rOdiEcwAAAYcNITYeAAAEAwBIMEYCIQCCJ2ktM1F+d1I5mQju\n' +
  'Tn7oDYxy3GCGyG3u/yhu8k7EaAIhANSP8cAaMQFV6y8B2tubKY5eSQtgkF3a6NNq\n' +
  'QJjtPnoHMA0GCSqGSIb3DQEBCwUAA4IBAQC8dK/G4nvs/SyQe/mnK+rUYIdSFs+4\n' +
  'lgzatmq8V/I1tBly+Sv/FPhnn4F3iCrqy9j8y202FP51ev95DGbjlJRTIFPqVAO8\n' +
  'ywYrLhvl1SJhV0b/8NF0Pr3dZVnK5Vfn11+LSBUg0cBB2hcVV30nv3IuVhz3d12n\n' +
  'P+VseYQgMpQf7ad+ttpZtA7yqHzrUm4fzr03G7q88GztACRSHoYiPbOlz99SeTgW\n' +
  '7bzZl1I4taxy2Q3b0ZBGfUt/kPY05tpKzKwDTbbqSErYszCt5X1RfVvf3coxF8Mo\n' +
  '9bHbs2wYIzQBdujDQ/hU0u6ItERer3SUItZoxaSIxdrZ9eXFwVvXsT/g\n' +
  '-----END CERTIFICATE-----\n' +
  '-----BEGIN CERTIFICATE-----\n' +
  'MIIFDzCCA/egAwIBAgIQCxNitu5qnT6WiTDxbiB9OTANBgkqhkiG9w0BAQsFADBh\n' +
  'MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n' +
  'd3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n' +
  'QTAeFw0yMDAzMDQxMjA0NDBaFw0zMDAzMDQxMjA0NDBaMEQxCzAJBgNVBAYTAlVT\n' +
  'MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxHjAcBgNVBAMTFUdlb1RydXN0IFJTQSBD\n' +
  'TiBDQSBHMjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANA1OZJJtZUI\n' +
  '7zj4qFHT79g+Otks4TEfmUEDhrNKBEEjb/i29GBfnpvFdT36azCg2VODJRSjIzFn\n' +
  '4qADcc84EmfKiDEM97HFsQPp9RRkqxH5cB51EU2eBE9Ua95x+wQp/KSdCqITCQ/v\n' +
  'yvm3J4Upjl0wlW8wRCPCWcYw3pKClGRkNzVtI1KXnfpn7fG3N84n7wlBb9IGKJFa\n' +
  'c/6+hxvZx2qnfLsxdIKR0Q/biGoU6Z8Iy/R/p7GoPO8vamV090+QHEL5AdSzKtEh\n' +
  'U9vdvcuWjjLxVnaJLfj/6WoGZj8UWn3zFbEoTVaAfp2xqdzW7yRvi2r148m9ev7l\n' +
  'jDqHo8UX69sCAwEAAaOCAd4wggHaMB0GA1UdDgQWBBQkb5E/iYeHDjLCQBjfxUzr\n' +
  'T8hJMjAfBgNVHSMEGDAWgBQD3lA1VtFMu2bwo+IbG8OXsj3RVTAOBgNVHQ8BAf8E\n' +
  'BAMCAYYwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMBIGA1UdEwEB/wQI\n' +
  'MAYBAf8CAQAwMwYIKwYBBQUHAQEEJzAlMCMGCCsGAQUFBzABhhdodHRwOi8vb2Nz\n' +
  'cC5kaWdpY2VydC5jbjBABgNVHR8EOTA3MDWgM6Axhi9odHRwOi8vY3JsLmRpZ2lj\n' +
  'ZXJ0LmNuL0RpZ2lDZXJ0R2xvYmFsUm9vdENBLmNybDCB3QYDVR0gBIHVMIHSMIHF\n' +
  'BglghkgBhv1sAQEwgbcwKAYIKwYBBQUHAgEWHGh0dHBzOi8vd3d3LmRpZ2ljZXJ0\n' +
  'LmNvbS9DUFMwgYoGCCsGAQUFBwICMH4MfEFueSB1c2Ugb2YgdGhpcyBDZXJ0aWZp\n' +
  'Y2F0ZSBjb25zdGl0dXRlcyBhY2NlcHRhbmNlIG9mIHRoZSBSZWx5aW5nIFBhcnR5\n' +
  'IEFncmVlbWVudCBsb2NhdGVkIGF0IGh0dHBzOi8vd3d3LmRpZ2ljZXJ0LmNvbS9y\n' +
  'cGEtdWEwCAYGZ4EMAQICMA0GCSqGSIb3DQEBCwUAA4IBAQCzkcXq0TN0oSn4UeXp\n' +
  'FBW7U8zrHBIhH9MXHNBp+Yy/yN19133UY05uuHXHaU2Uv0hxefckjPdkaX7ARso+\n' +
  'O3Ar6nf7YfBwCqSpqsNckKT7KKtf3Ot95wYFpKDa64jcRUfxzRWnmq12IVzczqHI\n' +
  'sIvUZQINw/UHSQcWekdUnMg58bQSHyTjwkj9jcX2RURxaVZkr15wxo/Z3Ydo2PVK\n' +
  '3afEr0/vcuFvE7QeGXiI2DJdVt3JefatZ3rj4VTW2aUZwHGUiWWIUudBfQKR0JEp\n' +
  'lJ8MFaKDh4/A2VEJnXILu1iwvc1m3jCaPuzZKdoHM/1234bznJI2aAfhfIhoHw90\n' +
  'tPO+\n' +
  '-----END CERTIFICATE-----\n';

// 证书链二进制数据，需业务自行赋值。
let encodingBlob: cert.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
  encodingFormat: cert.EncodingFormat.FORMAT_PEM
};

async function certChainHashCode() {
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
    console.log('createX509CertChain success');
    console.info('hashCode success: ' + JSON.stringify(x509CertChain.hashCode()));
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.generateCsr<sup>18+</sup>

generateCsr(keyInfo: PrivateKeyInfo, config: CsrGenerationConfig): string | Uint8Array

表示使用指定的RSA私钥，传入主体、拓展、摘要算法、输出格式等配置参数去生成CSR。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                 |
| -------- | ----------------------------- | ---- | -------------------- |
| keyInfo | [PrivateKeyInfo](#privatekeyinfo18) | 是 | 包含私钥跟口令的配置参数。 |
| config | [CsrGenerationConfig](#csrgenerationconfig18) | 是 | 包含生成CSR的配置参数。 |

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| string \| Uint8Array | 表示生成的CSR数据。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect. |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer. |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';

async function createCsrTest() {
  let nameStr = '/CN=John Doe/OU=IT Department/O=ACME Inc./L=San Francisco/ST=California/C=US/CN=ALN C/CN=XTS';
  let prikeyEnstr: string =
    '-----BEGIN RSA PRIVATE KEY-----\n'                                  +
      'Proc-Type: 4,ENCRYPTED\n'                                           +
      'DEK-Info: AES-128-CBC,B5FFA3AEEE7176106FDDB0988B532F07\n\n'         +
      't3zNRGKp5X4BNkcsYATad/Le+94yMIX9CoNAGsBIDzQw+773UMGIoeGEYVlXWc8x\n' +
      'N1XWDinn4ytWw9x9OfUYgmNnrdkWRSaIuw+SpQfBgJip+MsNERYOHZ5TYWTR8n3k\n' +
      '7/jHY8eCgTsP3hbNtyaePIrtbTLZGZAHG1YWY5UmLaYoI1O6/Vvobx72lx3b43Tx\n' +
      '4j5lkknpLl85fcs1s4TYMOd8vEwhdpouR4VY8kfRSm44WQLtGXrce0An3MG3pXyZ\n' +
      'GhpmJyTcg0epTEYVzglENlBJrBVDL+bJ8uvHGH4tmeQb77e6ILXoxZntM7zQMMFo\n' +
      'A7dilqO6FBxu20n2TidVGCa0Yn+DZLpry2OdwVUC2nXyCHCehr3jAZz6k20FWg5B\n' +
      'EsU16yOIB+bp9BUKdTpJVtc/pmZJtnlA9pSCUVmWdltOsjjxkE94wfAUOYhO3Mvz\n' +
      'gF9KR1/bdAbLw4t7bGeuyV4N2iYr83FodLLXpupM6Qfb51+HVgHvm2aaHv2Q4sf3\n' +
      'poCVTNlegoVV9x3+7HqXY6MjlG8aU6LcWqH34ySqRBQrKL1PuDzQSY5/RmP7PUhG\n' +
      'ym4l6KbEaRC2H/XS2qKa4VCMgBCgA0hoiw4s48Xd4h2GUTuxLM9wGyW89OEaHky7\n' +
      'VE7t3O9a2zhkRTYDDYQ8QCycKhNrsKySyItRUWn/w2lXvuKM7PpAzYH7Ey3W1eZG\n' +
      'PyyeGG9exjpdIvD3tx5Hl/OWwBkW1DAzO40gT6sdD5FXzRv4fCHuCrIow5QMLF4T\n' +
      'd5Y4a6q13V4O5b73T5INmKl8rEbPGIw7WLR7BNj05QuzNcn5kA1aBFIJqsxQv46l\n' +
      '-----END RSA PRIVATE KEY-----\n';
  let priKeyInfo: cert.PrivateKeyInfo = {
    key: prikeyEnstr,
    password : "123abc"
  }
  let keyUsage: cert.CsrAttribute = {
    type: "keyUsage",
    value: "digitalSignature, keyEncipherment"
  };

  let challengePassword: cert.CsrAttribute = {
    type:"challengePassword",
    value: "123456"
  };
  let attribute: cert.CsrAttribute[] = [
    keyUsage,challengePassword
  ];
  try {
    let data = await cert.createX500DistinguishedName(nameStr);
    console.info('createX500DistinguishedName success' + data.getName("CN").toString());
    let conf: cert.CsrGenerationConfig = {
      subject: data,
      mdName: "SHA256",
      outFormat: cert.EncodingBaseFormat.PEM,
      attributes: attribute
    }
    try {
      let csrStr = cert.generateCsr(priKeyInfo, conf)
      console.log('generateCsr success return str is' + csrStr.toString())
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('generateCsr failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX500DistinguishedName catch, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.createX500DistinguishedName<sup>12+</sup>

createX500DistinguishedName(nameStr: string): Promise\<X500DistinguishedName>

表示使用字符串格式的名称创建X500DistinguishedName对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                 |
| -------- | ----------------------------- | ---- | -------------------- |
| nameStr | string | 是 |X509定义的string类型的Name字符串格式数据。|

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| Promise\<[X500DistinguishedName](#x500distinguishedname12)> | 表示X509的可分辨对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect. |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer. |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let nameStr = '/CN=John Doe/OU=IT Department/O=ACME Inc./L=San Francisco/ST=California/C=US/CN=ALN C/CN=XTS';
async function createX500DistinguishedName() {
  try {
    cert.createX500DistinguishedName(nameStr)
      .then((data) => {
        console.log('createX500DistinguishedName success');
      })
      .catch((err: BusinessError) => {
        console.error('createX500DistinguishedName catch, errCode: ' + err.code + ', errMsg: ' + err.message);
      })
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX500DistinguishedName catch, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.createX500DistinguishedName<sup>12+</sup>

createX500DistinguishedName(nameDer: Uint8Array): Promise\<X500DistinguishedName>

表示使用DER格式的名称创建X500DistinguishedName对象，使用Promise方式异步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                 |
| -------- | ----------------------------- | ---- | -------------------- |
| nameDer | Uint8Array | 是 |X509定义的Uint8Array类型的DER格式数据。|

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| Promise\<[X500DistinguishedName](#x500distinguishedname12)> | 表示X509的可分辨对象。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect. |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer. |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let nameDer = new Uint8Array([48,41,49,11,48,9,6,3,85,4,3,12,2,67,65,49,13,48,11,6,3,85,4,10,12,4,116,101,115,116,49,11,48,9,6,3,85,4,6,19,2,67,78]);
async function createX500DistinguishedName() {
  try {
    cert.createX500DistinguishedName(nameDer)
      .then((data) => {
        console.log('createX500DistinguishedName success');
      })
      .catch((err: BusinessError) => {
        console.error('createX500DistinguishedName catch, errCode: ' + err.code + ', errMsg: ' + err.message);
      })
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX500DistinguishedName catch, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```
## X500DistinguishedName<sup>12+</sup>

X509定义的Name类型的对象。

### getName<sup>12+</sup>

getName(): string

获取可分辨名的字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| string | 可分辨名的字符串。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let nameDer = new Uint8Array([48,41,49,11,48,9,6,3,85,4,3,12,2,67,65,49,13,48,11,6,3,85,4,10,12,4,116,101,115,116,49,11,48,9,6,3,85,4,6,19,2,67,78]);
async function getName() {
  try {
    cert.createX500DistinguishedName(nameDer)
      .then((data) => {
        console.log('createX500DistinguishedName success');
        console.info('createX500DistinguishedName getName: ' + JSON.stringify(data.getName()))
      })
      .catch((err: BusinessError) => {
        console.error('createX500DistinguishedName catch, errCode: ' + err.code + ', errMsg: ' + err.message);
      })
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX500DistinguishedName catch, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getName<sup>12+</sup>

getName(type: string): Array\<string>

按类型获取可分辨名的字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| type | string | 是 | 指定类型的名称。|

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| Array\<string> | 可分辨名的字符串数组。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let nameStr = '/CN=Example CA/OU=test cert/O=test/L=XA/ST=SX/C=CN/CN=RSA CA/CN=XTS';
async function getName() {
  try {
    cert.createX500DistinguishedName(nameStr)
      .then((data) => {
        console.log('createX500DistinguishedName success');
        console.info('createX500DistinguishedName getName: ' + JSON.stringify(data.getName("CN")))
      })
      .catch((err: BusinessError) => {
        console.error('createX500DistinguishedName catch, errCode: ' + err.code + ', errMsg: ' + err.message);
      })
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX500DistinguishedName catch, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

### getEncoded<sup>12+</sup>

getEncoded(): EncodingBlob

获取X509证书扩展域的数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| [EncodingBlob](#encodingblob) | X509证书序列化数据。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let nameStr = '/CN=Example CA/OU=test cert/O=test/L=XA/ST=SX/C=CN/CN=RSA CA/CN=XTS';
async function getEncoded() {
  try {
    cert.createX500DistinguishedName(nameStr)
      .then((data) => {
        console.log('createX500DistinguishedName success');
        let encodingBlobData = data.getEncoded();
      })
      .catch((err: BusinessError) => {
        console.error('createX500DistinguishedName catch, errCode: ' + err.code + ', errMsg: ' + err.message);
      })
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX500DistinguishedName catch, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}
```

## cert.createCmsGenerator<sup>18+</sup>

createCmsGenerator(contentType: CmsContentType): CmsGenerator

表示创建CmsGenerator对象。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名   | 类型                          | 必填 | 说明                 |
| -------- | ----------------------------- | ---- | -------------------- |
| contentType | [CmsContentType](#cmscontenttype18) | 是 | 指定CMS内容类型。|

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| [CmsGenerator](#cmsgenerator18) | CmsGenerator对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
  'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
  'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
  'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
  'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
  'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
  'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
  '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
  'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
  'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
  'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
  'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
  'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
  '-----END CERTIFICATE-----\n';

function testcreateCmsGenerator() {
  let certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
    if (error) {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
        try {
          let cmsContentType = cert.CmsContentType.SIGNED_DATA;
          let cmsGenerator = cert.createCmsGenerator(cmsContentType);
          console.info('testcreateCmsGenerator createCmsGenerator success.');
        } catch (err) {
          let e: BusinessError = err as BusinessError;
          console.error('createCmsGenerator failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
    }
  });
}
```

## CmsGenerator<sup>18+</sup>

CmsGenerator对象用于生成CMS（Cryptographic Message Syntax）格式的消息。

> **说明：**
>
> PKCS#7是用于存储签名或加密数据的标准语法。注意CMS是PKCS#7的扩展，PKCS#7支持的数据类型包括数据、签名数据、信封数据、
> 签名和信封数据、摘要数据、加密数据。常用于保护数据的完整性和机密性。

### addSigner<sup>18+</sup>

addSigner(cert: X509Cert, keyInfo: PrivateKeyInfo, config: CmsSignerConfig): void;

用于添加签名者信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| cert |  [X509Cert](#x509cert) | 是 | 指定X509证书。|
| keyInfo | [PrivateKeyInfo](#privatekeyinfo18) | 是 | 指定私钥信息。|
| config | [CmsSignerConfig](#cmssignerconfig18) | 是 | 指定签名者选项。|

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |
| 19030008 | maybe wrong password. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
  'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
  'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
  'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
  'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
  'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
  'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
  '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
  'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
  'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
  'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
  'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
  'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
  '-----END CERTIFICATE-----\n';

let rsaStr1024: string  =
  '-----BEGIN RSA PRIVATE KEY-----\n' +
    'Proc-Type: 4,ENCRYPTED\n' +
    'DEK-Info: DES-EDE3-CBC,DB0AC6E3BEE16420\n\n' +
    '1N5xykdckthZnswMV7blxXm2RCqe/OByBfMwFI7JoXR8STtMiStd4xA3W405k1Ma\n' +
    'ExpsHgWwZaS23x+sQ1sL1dsqIPMrw1Vr+KrL20vQcCVjXPpGKauafVbtcWQ1r2PZ\n' +
    'QJ4KWP6FhUp+sGt2ItODW3dK+1GdqL22ZtANrgFzS42Wh8FSn0UMCf6RG62DK62J\n' +
    'z2jtf4XaorrGSjdTeY+fyyGfSyKidIMMBe+IXwlhCgAe7aHSaqXtMsv+BibB7PJ3\n' +
    'XmEp1D/0ptL3r46txyYcuy8jSNCkW8er93KKnlRN6KbuYZPvPNncWkzZBzV17t5d\n' +
    'QgtvVh32AKgqk5jm8YVnspOFiPrbrK9UN3IW15juFkfnhriM3IrKap4/kW+tfawZ\n' +
    'DmHkSyl8xqFK413Rv0UvYBTjOcGbs2BSJYEvp8CIjtA17SvLmNw70K2nXWuQYutY\n' +
    '+HyucPtHfEqUPQRzWTAMMntTru77u7dxo2WMMMxOtMJO5h7MAnZH9bAFiuO3ewcY\n' +
    'eEePg10d8Owcfh9G6kc0HIGT9MMLMi0mTXhpoQTuWPYuSx6uUZL1fsp1x2fuM0qn\n' +
    'bdf3+UnATYUu4tgvBHrMV7405Y6Y3PnqOFxVMeAHeOTo6UThtJ10mfeCPXGcUaHo\n' +
    'P5enw7h4145cha3+S4hNrUwj3skrtavld7tY74p4DvgZSlCMF3JAm3DhpnEMVcYP\n' +
    'Y6TkSevvxOpBvEHE41Y4VBCBwd9clcixI6cSBJKPUU4A/sc/kkNdGFcbzLQCg/zR\n' +
    '1m7YmBROb2qy4w3lv/uwVnPGLg/YV465irRaN3hgz7/1lm8STKQhmQ==\n' +
    '-----END RSA PRIVATE KEY-----\n';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function testAddSigner() {
  let certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
    if (error) {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
        try {
          let cmsContentType = cert.CmsContentType.SIGNED_DATA;
          let cmsGenerator = cert.createCmsGenerator(cmsContentType);
          console.info('testAddSigner createCmsGenerator success.');
          let privateKeyInfo: cert.PrivateKeyInfo = {
            key: rsaStr1024,
            password: '123456'
          };
          // addCert设置为true时，第二次addSigner增加相同的证书，会报错。
          let config: cert.CmsSignerConfig = {
            mdName:'SHA256',
            addCert:false,
            addAttr:false,
            addSmimeCapAttr:false
          }
          cmsGenerator.addSigner(x509Cert, privateKeyInfo, config);
          console.info('testAddSigner addSigner success.');
        } catch (err) {
          let e: BusinessError = err as BusinessError;
          console.error('testAddSigner failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
    }
  });
}
```

### addCert<sup>18+</sup>

addCert(cert: X509Cert): void

用于添加证书，例如签名证书的颁发者证书。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名 | 类型      | 必填 | 说明                     |
| ------ | --------- | ---- | ------------------------ |
| cert   | [X509Cert](#x509cert)  | 是   | 要添加的X509证书。      |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
  'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
  'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
  'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
  'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
  'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
  'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
  '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
  'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
  'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
  'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
  'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
  'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
  '-----END CERTIFICATE-----\n';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function testAddCert() {
  let certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
    if (error) {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
        try {
          let cmsContentType = cert.CmsContentType.SIGNED_DATA;
          let cmsGenerator = cert.createCmsGenerator(cmsContentType);
          console.info('testAddCert createCmsGenerator success.');
          // 第二次addCert增加相同的证书，会报错。
          cmsGenerator.addCert(x509Cert);
          console.info('testAddCert addCert success.');
        } catch (err) {
          let e: BusinessError = err as BusinessError;
          console.error('testAddCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
    }
  });
}
```

### doFinal<sup>18+</sup>

doFinal(data: Uint8Array, options?: CmsGeneratorOptions): Promise<Uint8Array | string>

用于获取Cms最终数据，例如Cms签名数据。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名      | 类型                | 必填 | 说明                                       |
| ----------- | ------------------- | ---- | ------------------------------------------ |
| data        | Uint8Array         | 是   | Cms操作的内容。                           |
| options     | [CmsGeneratorOptions](#cmsgeneratoroptions18)  | 否   | Cms操作的配置选项。                       |

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| Promise<Uint8Array \| string> | 返回Cms最终数据的Promise。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
  'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
  'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
  'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
  'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
  'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
  'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
  '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
  'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
  'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
  'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
  'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
  'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
  '-----END CERTIFICATE-----\n';

let rsaStr1024: string  =
  '-----BEGIN RSA PRIVATE KEY-----\n' +
    'Proc-Type: 4,ENCRYPTED\n' +
    'DEK-Info: DES-EDE3-CBC,DB0AC6E3BEE16420\n\n' +
    '1N5xykdckthZnswMV7blxXm2RCqe/OByBfMwFI7JoXR8STtMiStd4xA3W405k1Ma\n' +
    'ExpsHgWwZaS23x+sQ1sL1dsqIPMrw1Vr+KrL20vQcCVjXPpGKauafVbtcWQ1r2PZ\n' +
    'QJ4KWP6FhUp+sGt2ItODW3dK+1GdqL22ZtANrgFzS42Wh8FSn0UMCf6RG62DK62J\n' +
    'z2jtf4XaorrGSjdTeY+fyyGfSyKidIMMBe+IXwlhCgAe7aHSaqXtMsv+BibB7PJ3\n' +
    'XmEp1D/0ptL3r46txyYcuy8jSNCkW8er93KKnlRN6KbuYZPvPNncWkzZBzV17t5d\n' +
    'QgtvVh32AKgqk5jm8YVnspOFiPrbrK9UN3IW15juFkfnhriM3IrKap4/kW+tfawZ\n' +
    'DmHkSyl8xqFK413Rv0UvYBTjOcGbs2BSJYEvp8CIjtA17SvLmNw70K2nXWuQYutY\n' +
    '+HyucPtHfEqUPQRzWTAMMntTru77u7dxo2WMMMxOtMJO5h7MAnZH9bAFiuO3ewcY\n' +
    'eEePg10d8Owcfh9G6kc0HIGT9MMLMi0mTXhpoQTuWPYuSx6uUZL1fsp1x2fuM0qn\n' +
    'bdf3+UnATYUu4tgvBHrMV7405Y6Y3PnqOFxVMeAHeOTo6UThtJ10mfeCPXGcUaHo\n' +
    'P5enw7h4145cha3+S4hNrUwj3skrtavld7tY74p4DvgZSlCMF3JAm3DhpnEMVcYP\n' +
    'Y6TkSevvxOpBvEHE41Y4VBCBwd9clcixI6cSBJKPUU4A/sc/kkNdGFcbzLQCg/zR\n' +
    '1m7YmBROb2qy4w3lv/uwVnPGLg/YV465irRaN3hgz7/1lm8STKQhmQ==\n' +
    '-----END RSA PRIVATE KEY-----\n';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function testDoFinalByPromise() {
  let certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
    if (error) {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      try {
        let cmsContentType = cert.CmsContentType.SIGNED_DATA;
        let cmsGenerator = cert.createCmsGenerator(cmsContentType);
        console.info('testDoFinalByPromise createCmsGenerator success.');
        let privateKeyInfo: cert.PrivateKeyInfo = {
          key: rsaStr1024,
          password: '123456'
        };
        // addCert设置为true时，第二次addSigner或者addCert增加相同的证书，会报错。
        let config: cert.CmsSignerConfig = {
          mdName:'SHA256',
          addCert:false,
          addAttr:true,
          addSmimeCapAttr:true
        }
        cmsGenerator.addSigner(x509Cert, privateKeyInfo, config);
        console.info('testDoFinalByPromise addSigner success.');
        cmsGenerator.addCert(x509Cert);
        console.info('testDoFinalByPromise addCert success.');
        let content = new Uint8Array([1,2,3,4]);
        let optionsFinal: cert.CmsGeneratorOptions = {
          contentDataFormat : cert.CmsContentDataFormat.BINARY,
          outFormat : cert.CmsFormat.PEM,
          isDetached : true
        };
        cmsGenerator.doFinal(content, optionsFinal).then(result => {
          console.log('testDoFinalByPromise doFinal success, resullt = %s', result);
        }).catch((error: BusinessError) => {
          console.error('testDoFinalByPromise failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        });
      } catch (err) {
        let e: BusinessError = err as BusinessError;
        console.error('testDoFinalByPromise failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }
  });
}
```

### doFinalSync<sup>18+</sup>

doFinalSync(data: Uint8Array, options?: CmsGeneratorOptions): Uint8Array | string

用于获取Cms最终数据，例如Cms签名数据（同步方法）。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.Cert

**参数：**

| 参数名      | 类型                | 必填 | 说明                                       |
| ----------- | ------------------- | ---- | ------------------------------------------ |
| data        | Uint8Array         | 是   | Cms操作的内容。                           |
| options     | [CmsGeneratorOptions](#cmsgeneratoroptions18)  | 否   | Cms操作的配置选项。                       |

**返回值：**

| 类型                            | 说明             |
| ------------------------------- | ---------------- |
| Uint8Array \| string            | 返回Cms最终数据。 |

**错误码：**

以下错误码的详细介绍请参见[证书错误码](errorcode-cert.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 19020001 | memory error. |
| 19020002 | runtime error. |
| 19030001 | crypto operation error. |

**示例：**

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
  'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
  'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
  'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
  'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
  'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
  'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
  '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
  'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
  'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
  'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
  'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
  'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
  '-----END CERTIFICATE-----\n';

let rsaStr1024: string  =
  '-----BEGIN RSA PRIVATE KEY-----\n' +
    'Proc-Type: 4,ENCRYPTED\n' +
    'DEK-Info: DES-EDE3-CBC,DB0AC6E3BEE16420\n\n' +
    '1N5xykdckthZnswMV7blxXm2RCqe/OByBfMwFI7JoXR8STtMiStd4xA3W405k1Ma\n' +
    'ExpsHgWwZaS23x+sQ1sL1dsqIPMrw1Vr+KrL20vQcCVjXPpGKauafVbtcWQ1r2PZ\n' +
    'QJ4KWP6FhUp+sGt2ItODW3dK+1GdqL22ZtANrgFzS42Wh8FSn0UMCf6RG62DK62J\n' +
    'z2jtf4XaorrGSjdTeY+fyyGfSyKidIMMBe+IXwlhCgAe7aHSaqXtMsv+BibB7PJ3\n' +
    'XmEp1D/0ptL3r46txyYcuy8jSNCkW8er93KKnlRN6KbuYZPvPNncWkzZBzV17t5d\n' +
    'QgtvVh32AKgqk5jm8YVnspOFiPrbrK9UN3IW15juFkfnhriM3IrKap4/kW+tfawZ\n' +
    'DmHkSyl8xqFK413Rv0UvYBTjOcGbs2BSJYEvp8CIjtA17SvLmNw70K2nXWuQYutY\n' +
    '+HyucPtHfEqUPQRzWTAMMntTru77u7dxo2WMMMxOtMJO5h7MAnZH9bAFiuO3ewcY\n' +
    'eEePg10d8Owcfh9G6kc0HIGT9MMLMi0mTXhpoQTuWPYuSx6uUZL1fsp1x2fuM0qn\n' +
    'bdf3+UnATYUu4tgvBHrMV7405Y6Y3PnqOFxVMeAHeOTo6UThtJ10mfeCPXGcUaHo\n' +
    'P5enw7h4145cha3+S4hNrUwj3skrtavld7tY74p4DvgZSlCMF3JAm3DhpnEMVcYP\n' +
    'Y6TkSevvxOpBvEHE41Y4VBCBwd9clcixI6cSBJKPUU4A/sc/kkNdGFcbzLQCg/zR\n' +
    '1m7YmBROb2qy4w3lv/uwVnPGLg/YV465irRaN3hgz7/1lm8STKQhmQ==\n' +
    '-----END RSA PRIVATE KEY-----\n';

// string转Uint8Array。
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function testDoFinalSync() {
  let certEncodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
    if (error) {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
        try {
          let cmsContentType = cert.CmsContentType.SIGNED_DATA;
          let cmsGenerator = cert.createCmsGenerator(cmsContentType);
          console.info('testDoFinalSync createCmsGenerator success.');
          let privateKeyInfo: cert.PrivateKeyInfo = {
            key: rsaStr1024,
            password: '123456'
          };
          // addCert设置为true时，第二次addSigner或者addCert增加相同的证书，会报错。
          let config: cert.CmsSignerConfig = {
            mdName:'SHA256',
            addCert:false,
            addAttr:false,
            addSmimeCapAttr:false
          }
          cmsGenerator.addSigner(x509Cert, privateKeyInfo, config);
          console.info('testDoFinalSync addSigner success.');
          cmsGenerator.addCert(x509Cert);
          console.info('testDoFinalSync addCert success.');
          let content = new Uint8Array([1,2,3,4]);
          let optionsFinal: cert.CmsGeneratorOptions = {
            contentDataFormat : cert.CmsContentDataFormat.BINARY,
            outFormat : cert.CmsFormat.DER,
            isDetached : false
          };
          let output = cmsGenerator.doFinalSync(content, optionsFinal);
          console.info('testDoFinalSync doFinalSync success, output = %s.',output);
        } catch (err) {
          let e: BusinessError = err as BusinessError;
          console.error('testDoFinalSync failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
    }
  });
}
```
