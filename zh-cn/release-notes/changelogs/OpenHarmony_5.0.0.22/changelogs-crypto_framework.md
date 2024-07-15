# 加解密算法库框架变更说明

## cl.crypto_architecture.1 Sign.update和Verify.update接口变更

**访问级别**

公开接口

**变更原因**

当使用DSA算法进行签名或验签，并设置了摘要算法为NoHash时，则不支持update操作，实际该接口返回了成功。

**变更影响**

该变更为非兼容性变更。

变更前，当使用DSA算法进行签名，并设置了摘要算法为NoHash时，如果调用了update接口（即使用了分段签名），该接口会返回成功，但最终得到的签名值是错误的。

变更后，当使用DSA算法进行签名，并设置了摘要算法为NoHash时，如果调用了update接口（即使用了分段签名），该接口会抛出异常，错误码为ERR_CRYPTO_OPERATION。

变更前，当使用DSA算法对正确的签名数据进行验签，并设置了摘要算法为NoHash时，如果调用了update接口，该接口会返回成功，但最终会验签失败。

变更后，当使用DSA算法对正确的签名数据进行验签，并设置了摘要算法为NoHash时，如果调用了update接口，该接口会抛出异常，错误码为ERR_CRYPTO_OPERATION。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.22 版本开始。

**变更的接口/组件**

@ohos.security.cryptoFramework.d.ts中Sign.update和Verify.update接口

**适配指导**

当使用DSA算法进行签名或验签，并设置了摘要算法为NoHash时，则不能调用update接口。签名时应该调用Sign.init和Sign.sign接口，验签时应该调用Verify.init和Verify.verify接口，或对应的同步接口。