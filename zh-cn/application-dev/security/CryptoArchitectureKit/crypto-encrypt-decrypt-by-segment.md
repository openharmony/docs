# 分段加解密说明

在加解密的过程中，算法库没有对单次或累计的传入数据量设置大小限制，但在传入的数据量较大时（如数据量大于2M），建议开发者将数据分段，完成分段加解密，提高效率。

## 对称加解密

对称密钥的分段加解密，通过调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)实现。

开发者可自定义单次传入的数据量（示例中的updateLength），多次调用update传入数据。

当前单次支持传入的最大长度为INT_MAX（Uint8Array类型的最大长度）。

**开发者应当对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。**

**开发示例：** [使用AES对称密钥（GCM模式）分段加解密](crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md)

**开发示例：** [使用SM4对称密钥（GCM模式）分段加解密](crypto-sm4-sym-encrypt-decrypt-gcm-by-segment.md)

## 非对称加解密

非对称加解密，不支持update操作，仅需要调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)和[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)完成加解密。

非对称密钥的分段加密是指当明文大于单次加密支持的数据长度时（具体长度请查[非对称密钥加解密算法规格](crypto-asym-encrypt-decrypt-spec.md)），需要将待加密数据分为合适长度的数据段，并对每个数据段执行加密操作，即创建Cipher，然后调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)和[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)接口。

严格意义上说，是数据的拆分加解密，此时单次传入的数据量长度与密钥规格的长度相关。

- RSA：填充模式不同，输入的数据的规则不同。请根据[RSA算法规格](crypto-asym-encrypt-decrypt-spec.md#rsa)确认单次传入的数据量长度。
- SM2：加密长度需要在固定长度进行。具体请查阅[SM2算法规格](crypto-asym-encrypt-decrypt-spec.md#sm2)。

**开发者应当对每次doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。**

**开发示例：** [使用RSA非对称密钥分段加解密](crypto-rsa-asym-encrypt-decrypt-by-segment.md)

## 常见问题

- 分段加解密中，每次更新的数据量，与加密模式是否有关？

   每次更新的数据量，由开发者自定义，与加密模式无关。

   不同的加密模式，仅对加解密参数产生影响，不同的加密模式使用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

