# 分段加解密说明

在加解密的过程中，算法库没有对单次或累计的传入数据量设置大小限制，但在传入的数据量较大时（如数据量大于2M），建议开发者将数据分段，完成分段加解密，提高效率。

## 对称密钥

对称密钥的分段加解密，通过调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)实现。

开发者可自定义单次传入的数据量（示例中的updateLength），多次调用update传入数据。

当前单次传入的长度没有限制。

**建议对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。**

**开发示例：** [使用AES对称密钥（GCM模式）分段加解密](crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md)

## 非对称密钥

非对称密钥的分段加解密，不通过update实现，仅需要实现Cipher.init和Cipher.doFinal。

严格意义上说，是数据的拆分加解密，此时单次传入的数据量长度与密钥规格的长度相关。

- RSA：填充模式不同，输入的数据的规则不同。请根据[RSA算法规格](crypto-asym-encrypt-decrypt-spec.md#rsa)确认单次传入的数据量长度。
- SM2：无具体限制。

**建议对每次doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。**

**开发示例：** [使用RSA非对称密钥分段加解密](crypto-rsa-asym-encrypt-decrypt-by-segment.md)

## 常见问题

- 分段加解密中，每次更新的数据量，与加密模式是否有关？

   每次更新的数据量，由开发者自定义，与加密模式无关。

   不同的加密模式，仅对加解密参数产生影响，不同的加密模式使用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

