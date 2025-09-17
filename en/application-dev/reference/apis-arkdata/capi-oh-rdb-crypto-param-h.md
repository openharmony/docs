# oh_rdb_crypto_param.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines functions and enums related to encryption parameters of the RDB store.

**File to include**: <database/rdb/oh_rdb_crypto_param.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 20

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                            | typedef Keyword     | Description                                |
| ------------------------------------------------ | ------------------ | ------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) | OH_Rdb_CryptoParam | Defines the encryption parameters used to open an encrypted database.|

### Enums

| Name                                     | typedef Keyword     | Description                        |
| ----------------------------------------- | ------------------ | ---------------------------- |
| [Rdb_EncryptionAlgo](#rdb_encryptionalgo) | Rdb_EncryptionAlgo | Enumerates database encryption algorithms.            |
| [Rdb_HmacAlgo](#rdb_hmacalgo)             | Rdb_HmacAlgo       | Enumerates HMAC algorithms.|
| [Rdb_KdfAlgo](#rdb_kdfalgo)               | Rdb_KdfAlgo        | Enumerates KDF algorithms. |

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam *OH_Rdb_CreateCryptoParam(void)](#oh_rdb_createcryptoparam) | Creates an [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| [int OH_Rdb_DestroyCryptoParam(OH_Rdb_CryptoParam *param)](#oh_rdb_destroycryptoparam) | Destroys an [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| [int OH_Crypto_SetEncryptionKey(OH_Rdb_CryptoParam *param, const uint8_t *key, int32_t length)](#oh_crypto_setencryptionkey) | Sets the key data of an [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| [int OH_Crypto_SetIteration(OH_Rdb_CryptoParam *param, int64_t iteration)](#oh_crypto_setiteration) | Sets the number of iterations of the KDF algorithm used when opening an encrypted database.                 |
| [int OH_Crypto_SetEncryptionAlgo(OH_Rdb_CryptoParam *param, int32_t algo)](#oh_crypto_setencryptionalgo) | Sets the encryption algorithm used when opening an encrypted database.                        |
| [int OH_Crypto_SetHmacAlgo(OH_Rdb_CryptoParam *param, int32_t algo)](#oh_crypto_sethmacalgo) | Sets the HMAC algorithm used when opening an encrypted database.                        |
| [int OH_Crypto_SetKdfAlgo(OH_Rdb_CryptoParam *param, int32_t algo)](#oh_crypto_setkdfalgo) | Sets the KDF algorithm used when opening an encrypted database.                         |
| [int OH_Crypto_SetCryptoPageSize(OH_Rdb_CryptoParam *param, int64_t size)](#oh_crypto_setcryptopagesize) | Sets the page size used when opening an encrypted database.                          |

## Enum Description

### Rdb_EncryptionAlgo

```
enum Rdb_EncryptionAlgo
```

**Description**

Enumerates database encryption algorithms.

**Since**: 20

| Enum Item             | Description                               |
| ------------------- | ----------------------------------- |
| RDB_AES_256_GCM = 0 | RDB_AES_256_GCM.|
| RDB_AES_256_CBC     | RDB_AES_256_CBC.|

### Rdb_HmacAlgo

```
enum Rdb_HmacAlgo
```

**Description**

Enumerates HMAC algorithms.

**Since**: 20

| Enum Item           | Description                 |
| ----------------- | --------------------- |
| RDB_HMAC_SHA1 = 0 | RDB_HMAC_SHA1.  |
| RDB_HMAC_SHA256   | RDB_HMAC_SHA256.|
| RDB_HMAC_SHA512   | RDB_HMAC_SHA512.|

### Rdb_KdfAlgo

```
enum Rdb_KdfAlgo
```

**Description**

Enumerates KDF algorithms.

**Since**: 20

| Enum Item          | Description                |
| ---------------- | -------------------- |
| RDB_KDF_SHA1 = 0 | RDB_KDF_SHA1.  |
| RDB_KDF_SHA256   | RDB_KDF_SHA256.|
| RDB_KDF_SHA512   | RDB_KDF_SHA512.|


## Function Description

### OH_Rdb_CreateCryptoParam()

```
OH_Rdb_CryptoParam *OH_Rdb_CreateCryptoParam(void)
```

**Description**

Creates an [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.

**Since**: 20

**Returns**

| Type                                                 | Description                                                  |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) | Returns a pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance if the operation is successful; returns **nullptr** otherwise. Use [OH_Rdb_DestroyCryptoParam](capi-oh-rdb-crypto-param-h.md#oh_rdb_destroycryptoparam) to release the memory in time. |

### OH_Rdb_DestroyCryptoParam()

```
int OH_Rdb_DestroyCryptoParam(OH_Rdb_CryptoParam *param)
```

**Description**

Destroys an [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Crypto_SetEncryptionKey()

```
int OH_Crypto_SetEncryptionKey(OH_Rdb_CryptoParam *param, const uint8_t *key, int32_t length)
```

**Description**

Sets the key data of an [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| const uint8_t *key                                      | Pointer to the array data.                                    |
| int32_t length                                          | Size of the key array.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Crypto_SetIteration()

```
int OH_Crypto_SetIteration(OH_Rdb_CryptoParam *param, int64_t iteration)
```

**Description**

Sets the number of iterations of the KDF algorithm used when opening an encrypted database.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| int64_t iteration                                       | Number of iterations.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Crypto_SetEncryptionAlgo()

```
int OH_Crypto_SetEncryptionAlgo(OH_Rdb_CryptoParam *param, int32_t algo)
```

**Description**

Sets the encryption algorithm used when opening an encrypted database.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| int32_t algo                                            | Encryption algorithm.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Crypto_SetHmacAlgo()

```
int OH_Crypto_SetHmacAlgo(OH_Rdb_CryptoParam *param, int32_t algo)
```

**Description**

Sets the HMAC algorithm used when opening an encrypted database.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| int32_t algo                                            | HMAC algorithm.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Crypto_SetKdfAlgo()

```
int OH_Crypto_SetKdfAlgo(OH_Rdb_CryptoParam *param, int32_t algo)
```

**Description**

Sets the KDF algorithm used when opening an encrypted database.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| int32_t algo                                            | KDF algorithm.                                               |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Crypto_SetCryptoPageSize()

```
int OH_Crypto_SetCryptoPageSize(OH_Rdb_CryptoParam *param, int64_t size)
```

**Description**

Sets the page size used when opening an encrypted database.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *param | Pointer to the [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) instance.|
| int64_t size                                            | Page size, in bytes. The value must be a power of 2 and ranges from 1024 to 65536.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|
