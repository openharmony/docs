# 使用硬件熵源生成安全随机数(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

从API version 21开始，可以选择使用硬件熵源生成安全随机数。

随机数主要用于临时会话密钥生成和非对称加密算法密钥生成等场景。在加解密场景中，安全随机数生成器需要具备随机性、不可预测性和不可重现性。
使用更安全的熵源，对随机数而言，就意味着 “结果难以被猜测或复现”，是 “真随机性” 的量化体现。
<!--Del-->当前硬件熵源随机数的实现依赖HUKS。对于具备安全环境（如TEE、安全芯片）的系统或设备，开启硬件熵源后，将通过HUKS从TEE中获取安全随机数（其熵源为硬件熵源）作为算法库生成随机数的熵源。由于安全环境依赖硬件支持，在开源仓中仅为模拟实现，需OEM厂商适配。<!--DelEnd-->

当前硬件熵源的实现是通过调用[HUKS](../../../application-dev/security/UniversalKeystoreKit/huks-overview.md)的相关接口完成的。

开发者可以调用接口，完成以下具体功能：

- 生成指定长度的安全随机数，并将其用于生成对应的密钥。

- 开启硬件熵源。

- 指定随机种子，生成一系列的随机序列。

在开发前，开发者应该先对加解密基础知识有一定了解，并熟知以下随机数相关的基本概念：

- **内部状态**

  代表随机数生成器内存中的数值，当内部状态相同时，随机数生成器会生成固定的随机数序列。

- **随机种子**

  一个用来对伪随机数的内部状态进行初始化的数据，随机数生成器通过种子来生成一系列的随机序列。

  当前OpenSSL实现方式，随机数生成器内部状态是不断变化的，即使设置相同的种子，生成的随机数序列也不会相同。

## 支持的算法与规格

安全随机数生成，设置硬件熵源之后，使用OpenSSL的RAND_priv_bytes接口生成。

| 算法 | 长度（Byte） |
| -------- | -------- |
| CTR_DRBG | [1, INT_MAX] |

## 开发步骤

1. 调用[OH_CryptoRand_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-rand-h.md#oh_cryptorand_create)，创建随机数生成器。

2. 调用[OH_CryptoRand_EnableHardwareEntropy](../../reference/apis-crypto-architecture-kit/capi-crypto-rand-h.md#oh_cryptorand_enablehardwareentropy)，开启硬件熵源。

3. （可选）调用[OH_CryptoRand_SetSeed](../../reference/apis-crypto-architecture-kit/capi-crypto-rand-h.md#oh_cryptorand_setseed)，为随机数生成器设置种子。

4. 调用[OH_CryptoRand_GenerateRandom](../../reference/apis-crypto-architecture-kit/capi-crypto-rand-h.md#oh_cryptorand_generaterandom)，生成指定长度的安全随机数。指定字节长度范围为1~INT_MAX。

5. 调用[OH_CryptoRand_GetAlgoName](../../reference/apis-crypto-architecture-kit/capi-crypto-rand-h.md#oh_cryptorand_getalgoname)，获取随机数生成器使用的算法名称。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <stdio.h>

static OH_Crypto_ErrCode doTestRandomNumber()
{
    // 创建随机数生成器。
    OH_CryptoRand *rand = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoRand_Create(&rand);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // 开启硬件熵源。
    ret = OH_CryptoRand_EnableHardwareEntropy(rand);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoRand_Destroy(rand);
        return ret;
    }

    // 设置随机种子（可选）。
    uint8_t seedData[12] = {0x25, 0x65, 0x58, 0x89, 0x85, 0x55, 0x66, 0x77, 0x88, 0x99, 0x11, 0x22};
    Crypto_DataBlob seed = {
        .data = seedData,
        .len = sizeof(seedData)
    };
    ret = OH_CryptoRand_SetSeed(rand, &seed);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoRand_Destroy(rand);
        return ret;
    }

    // 生成指定长度的随机数。
    Crypto_DataBlob out = {0};
    uint32_t randomLength = 24; // 生成24字节的随机数。
    ret = OH_CryptoRand_GenerateRandom(rand, randomLength, &out);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoRand_Destroy(rand);
        return ret;
    }

    // 获取并打印随机数生成器的算法名称。
    const char *algoName = OH_CryptoRand_GetAlgoName(rand);
    if (algoName != nullptr) {
        printf("Random number generator algorithm: %s\n", algoName);
    }

    printf("Generated random number length: %u\n", out.len);

    // 清理资源。
    OH_Crypto_FreeDataBlob(&out);
    OH_CryptoRand_Destroy(rand);
    return CRYPTO_SUCCESS;
}
```