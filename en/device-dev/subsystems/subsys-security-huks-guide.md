# Development on HUKS

## Overview

### Introduction

OpenHarmony Universal KeyStore (HUKS) provides system-level key management capabilities, ensuring secure management and use of keys throughout their entire lifecycle (generation, storage, use, and destruction). The environment where a key is stored and used is of the most importance to key security. For example, a key in plaintext must be used in a secure environment, such as a Trusted Execution Environment (TEE) or a security chip.

This document describes how to adapt Hardware Device Interface (HDI) APIs for secure key storage and use environment based on the OpenHarmony HUKS architecture and how to verify these APIs.

HUKS supports key lifecycle management, which covers the following:

1. Generation and import of the key

2. Storage of the key

3. Use of the key (including encryption and decryption, signing and verification, key derivation and agreement, hash, and key access control)

4. Destruction of the key

### Basic Concepts

- HUKS Service

  An independent OpenHarmony service that supports key management. It belongs to the huks_service process. Instead of handling key calculation, the HUKS Service depends on the HUKS Core to provide services for the upper layer.

- HUKS Core

  A functional module that provides the key management service. This module must run in a secure environment, and the keys in plaintext must be kept inside the HUKS Core module throughout the lifecycle.

- TEE

  A secure area created by isolating software and hardware resources to protect the applications and data in the secure area from unauthorized access. This isolation mechanism yields two execution environments: TEE and Rich Execution Environment (REE). Each execution environment has independent internal data path and memory, protecting the data inside the TEEs from being disclosed. The applications in an REE cannot access resources in a TEE. The applications in a TEE cannot access resources in another TEE without authorization.

- Init-Update-Finish

   **Init**: initializes data for a key operation.

   **Update**: operates data by segment and returns the result, or appends data.

   **Finish**: stops operating data by segment or appending data, and returns the result.

### Working Principles

The following uses the key generation process as an example to describe the communication between the HUKS Service and HUKS Core. Other key operations are similar.
The upper-layer application invokes the HUKS Service through the key management SDK. The HUKS Service invokes the HUKS Core, which invokes the key management module to generate a key. The HUKS Core uses a work key derived from the root key to encrypt the generated key and sends the encrypted key to the HUKS Service. The HUKS Service stores the encrypted key in a file.

![](figures/HUKS-GenerateKey1.png)

### Constraints

* HUKS must be implemented in a TEE for security purposes.

* The certificate chain returned by **HuksHdiAttestKey** must be in the sequence of the application certificate, device certificate, CA certificate, and root certificate, with the certificate length added before each certificate. The certificate chain and its length are assembled in the binary large object (BLOB) format. If you want to define the certificate format, the format must be the same as that parsed by the server.

![CertChain format](figures/HUKS-CertChain.png)

* The key returned by the API must be assembled into a **KeyBlob** based on the key storage status. For details about the APIs that must comply with this constraint, see [Available APIs](#available-apis).

   The **KeyBlob** stores both the key and its attributes. The figure below shows the **KeyBlob** structure. For details about how to construct a **KeyBlob**, see [hks_keyblob.c/HksBuildKeyBlob](https://gitee.com/openharmony/security_huks/blob/master/services/huks_standard/huks_engine/main/core/src/hks_keyblob.c).

![KeyBlob format](figures/HUKS-KeyBlob.png)

## Development Guidelines

### When to Use

The HUKS Core provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations. If you want to replace the HUKS Core with your own implementation, you need to implement the following APIs:

### Available APIs

**Table 1** Available APIs

| API                                                      | Description                                 | Constraints                    | Corresponding JS API                                       |
| ------------------------------------------------------------ | ---------------------------------------- | ----------------------------- | ------------------------------------------------------------ |
| [HuksHdiModuleInit()](#hukshdimoduleinit)                   | Initializes the HUKS Core.                           |  –                          | –|
| [HuksHdiRefresh()](#hukshdirefresh)                          | Refreshes the root key.                             |  –                           | –|
| [HuksHdiGenerateKey()](#hukshdigeneratekey)                  | Generates a key.                               |  The key generated must be in the **KeyBlob** format.         |generateKey(keyAlias: string, options: HuksOptions)|
| [HuksHdiImportKey()](#hukshdiimportkey)                     | Import a key in plaintext.                           |  The output parameter must be in the **KeyBlob** format.          | importKey(keyAlias: string, options: HuksOptions)|
| [HuksHdiImportWrappedKey()](#hukshdiimportwrappedkey)        |Import an encrypted key.                             |  The output parameter must be in the **KeyBlob** format.         | importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions)|
| [HuksHdiExportPublicKey()](#hukshdiexportpublickey)         | Exports a public key.                                |–                            | exportKey(keyAlias: string, options: HuksOptions) |
| [HuksHdiInit()](#hukshdiinit)                              | Initializes data for a key operation. This API is of the Init-Update-Final model.                      |–                             | init(keyAlias: string, options: HuksOptions) |
| [HuksHdiUpdate()](#hukshdiupdate)                           | Operates data by segment or appends data for the key operation. This API is of the Init-Update-Final model.                    |The input parameter for signing and signature verification must be the raw data.         | update(handle: number, token?: Uint8Array, options: HuksOptions) |
| [HuksHdiFinish()](#hukshdifinish)                           | Finishes the key operation. This API is of the Init-Update-Final model.                    |The input parameter for signing and signature verification must be the signed data.       | finish(handle: number, options: HuksOptions) |
| [HuksHdiAbort()](#hukshdiabort)                         | Aborts Init-Update-Finish.                              |–                            | abort(handle: number, options: HuksOptions) |
| [HuksHdiGetKeyProperties()](#hukshdigetkeyproperties)        | Obtains key properties.                             |–                           | getKeyProperties(keyAlias: string, options: HuksOptions)|
| [HuksHdiAttestKey()](#hukshdiattestkey)        | Obtain the key certificate.                             |The output parameter must be in the **certChain** format.                     | attestKey(keyAlias: string, options: HuksOptions)|

- - -

#### HuksHdiModuleInit

**API description**

Initializes the HUKS Core, including the lock, encryption algorithm library, authtoken key, and root key.

**Prototype**
<pre><code>int32_t HuksHdiModuleInit();</code></pre>
<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiRefresh

**API description**

Refreshes the root key.

**Prototype**
<pre><code>int32_t HuksHdiRefresh();</code></pre>
<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiGenerateKey

**API description**

Generates a key based on **paramSet**.

**Prototype**
<pre><code>int32_t HuksHdiGenerateKey(const struct HksBlob *keyAlias, const struct HksParamSet *paramSet, const struct HksBlob *keyIn, struct HksBlob *keyOut);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *keyAlias</strong>
  Pointer to the alias of the key to generate. The value must meet the following requirements:
  1. keyAlias != null
  2. keyAlias -> data != null
  3. keyAlias -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters for generating the key.
  <br></br>
  <strong>const struct HksBlob *keyIn</strong>
  This parameter is used in key agreement.
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  Pointer to the output parameter, which holds **paramSet** and the key generated.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Constraints</strong></summary>

  1. Check parameters in the API. For example, check for null pointers and whether the key algorithm is supported.

  2. **keyOut** must be in the **KeyBlob** format.

</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiImportKey

**API description**

Imports a key in plaintext.

**Prototype**
<pre><code>int32_t HuksHdiImportKey(const struct HksBlob *keyAlias, const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *keyOut);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *msg</strong>
  Pointer to the alias of the key to import. The value must meet the following requirements:
  1. keyAlias != null
  2. keyAlias -> data != null
  3. keyAlias -> size != 0
  <br></br>
  <strong>const struct HksBlob *key</strong>
  Pointer to the key to import. The value must meet the following requirements:
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters for importing the key.
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  Pointer to the output parameter, which holds **paramSet** and the key.
  <br></br>
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Constraints</strong></summary>

  1. Check parameters in the API. For example, check for null pointers and whether the key algorithm is supported.

  2. **keyOut** must be in the **KeyBlob** format.

</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiImportWrappedKey

**API description**

Imports an encrypted key.

**Prototype**
<pre><code>int32_t HuksHdiImportWrappedKey(const struct HksBlob *keyAlias, const struct HksBlob *wrappingUsedkey, const struct HksBlob *wrappedKeyData, const struct HksParamSet *paramSet, struct HksBlob *keyOut);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *KeyAlias</strong>
  Pointer to the alias of the key to import. The value must meet the following requirements:
  1. keyAlias != null
  2. keyAlias -> data != null
  3. keyAlias -> size != 0
  <br></br>
  <strong>const struct HksBlob *key</strong>
  Pointer to the key used to encrypt the key to import. The value must meet the following requirements:
  1. wrappingUsedkey != null
  2. wrappingUsedkey -> data != null
  3. wrappingUsedkey -> size != 0
  <br></br>
  <strong>const struct HksBlob *wrappedKeyData</strong>
  Pointer to the encrypted data of the key to import. The value must meet the following requirements:
  1. wrappedKeyData != null
  2. wrappedKeyData -> data != null
  3. wrappedKeyData -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters for importing the key.
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  Pointer to the output parameter, which holds **paramSet** and the key imported.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Constraints</strong></summary>

  1. Check parameters in the API. For example, check for null pointers and whether the key algorithm is supported.

  2. **keyOut** must be in the **KeyBlob** format.

</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiExportPublicKey

**API description**

Exports a public key.

**Prototype**
<pre><code>int32_t HuksHdiExportPublicKey(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *keyOut);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  Pointer to the private key corresponding to the public key to export. The value must meet the following requirements:
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameter set, which is empty.
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  Pointer to the output parameter, which holds the public key exported.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiInit

**API description**

Initializes data for a key operation. This API is of the Init-Update-Final model.

**Prototype**
<pre><code>int32_t HuksHdiInit(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *handle, struct HksBlob *token);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  Pointer to the key, on which the **Init** operation is to perform. The value must meet the following requirements:
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters of the **Init** operation.
  <br></br>
  <strong>struct HksBlob *handle</strong>
  Pointer to the handle of Init-Update-Finish.
  <br></br>
  <strong>struct HksBlob *token</strong>
  Pointer to the challenge used for secure access control.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiUpdate

**API description**

Operates data by segment or appends data for the key operation. This API is of the Init-Update-Final model.

**Prototype**
<pre><code>int32_t HuksHdiUpdate(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData, struct HksBlob *outData);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *handle</strong>
  Pointer to the handle of Init-Update-Finish.
  <br></br>
  <strong> const struct HksParamSet *paramSet</strong>
  Pointer to the parameters of the **Update** operation.
  <br></br>
  <strong> const struct HksBlob *inData</strong>
  Pointer to the input of the **Update** operation.
  <br></br>
  <strong> struct HksBlob *outData</strong>
  Pointer to the result of the **Update** operation.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Constraints</strong></summary>

  1. **inData** must pass in the raw data when signing and signature verification are performed.

</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiFinish

**API description**

Finishes the key operation. This API is of the Init-Update-Final model.

**Prototype**
<pre><code>int32_t HuksHdiFinish(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData, struct HksBlob *outData);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *handle</strong>
  Pointer to the handle of Init-Update-Finish.
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters of the **Finish** operation.
  <br></br>
  <strong>const struct HksBlob *inData</strong>
  Pointer to the input of the **Finish** operation.
  <br></br>
  <strong>struct HksBlob *outData</strong>
  Pointer to the result of the **Finish** operation.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Constraints</strong></summary>

  1. In signing and signature verification, **inData** must pass in the signature data to be verified. The return value indicates whether the operation is successful.

</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiAbort

**API description**

Aborts Init-Update-Finish. When an error occurs in any of the **Init**, **Update**, and **Finish** operations, call this API to terminate the use of the key.

**Prototype**
<pre><code>int32_t HuksHdiAbort(const struct HksBlob *handle, const struct HksParamSet *paramSet);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *handle</strong>
  Pointer to the handle of Init-Update-Finish.
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters of the **Abort** operation.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiGetKeyProperties

**API description**

Obtains key properties.

**Prototype**
<pre><code>int32_t HuksHdiGetKeyProperties(const struct HksParamSet *paramSet, const struct HksBlob *key);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameter set, which is empty.
  <br></br>
  <strong>const struct HksBlob *key</strong>
  Pointer to the target key.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

#### HuksHdiAttestKey

**API description**

Obtains the key certificate.

**Prototype**
<pre><code>int32_t (*HuksHdiAttestKey)(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *certChain);</code></pre>
<details>
  <summary><strong>Parameters</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  Pointer to the target key.
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Pointer to the parameters for the operation.
  <br></br>
  <strong>struct HksBlob *certChain</strong>
  Pointer to the output parameter, which holds the certificate obtained.
  </pre>
</details>
<br></br>

<details>
  <summary><strong>Constraints</strong></summary>

  1. **certChain** must comply with the certificate chain described in [Constraints](#constraints).

</details>
<br></br>

<details>
  <summary><strong>Return value</strong></summary>

  - **HKS_SUCCESS**: The operation is successful.

  - Other value: The operation failed.
</details>

- - -

### Development Procedure

The directory structure is as follows:

```undefined
// base/security/user_auth/services/huks_standard/huks_engine/main
├── BUILD.gn # Build script
├── core_dependency # Dependencies of the implementation
└── core # Software implementation of the HUKS Core
    ├── BUILD.gn # Build script
    ├── include 
    └── src
        ├── hks_core_interfaces.c # Adaptation of the HDI to the HUKS Core
        └── hks_core_service.c # Specific implementation
        └── ... # Other function code
```

Init-Update-Finish must be used to implement HUKS Core APIs. The following provides the development procedure of Init-Update-Finish and sample code of the HUKS Core. You can refer to the following code to implement all HDI APIs.

For the code of other HUKS Core APIs, see [hks_core_service.c](https://gitee.com/openharmony/security_huks/blob/master/services/huks_standard/huks_engine/main/core/src/hks_core_service.c).

1. Create a handle to enable the information about the operations on a key to be stored in a session. With this handle, multiple operations on the same key can be performed.

   ```c

   // Implement Init().

   int32_t HksCoreInit(const struct  HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *handle,
    struct HksBlob *token)
   {
       HKS_LOG_D("HksCoreInit in Core start");
       uint32_t pur = 0;
       uint32_t alg = 0;
       // Check parameters.
       if (key == NULL || paramSet == NULL || handle == NULL || token == NULL) {
           HKS_LOG_E("the pointer param entered is invalid");
           return HKS_FAILURE;
        }

        if (handle->size < sizeof(uint64_t)) {
            HKS_LOG_E("handle size is too small, size : %u", handle->size);
            return HKS_ERROR_INSUFFICIENT_MEMORY;
        }
        // Decrypt the key file.
        struct HuksKeyNode *keyNode = HksCreateKeyNode(key, paramSet);
        if (keyNode == NULL || handle == NULL) {
            HKS_LOG_E("the pointer param entered is invalid");
            return HKS_ERROR_BAD_STATE;
        }
        // Store information in a session based on the handle. The information stored can be used for the Update and Finish operations on the key.
        handle->size = sizeof(uint64_t);
        (void)memcpy_s(handle->data, handle->size, &(keyNode->handle), handle->size);
        // Obtain the algorithm from the parameters.
        int32_t ret = GetPurposeAndAlgorithm(paramSet, &pur, &alg);
        if (ret != HKS_SUCCESS) {
            HksDeleteKeyNode(keyNode->handle);
            return ret;
        }
        // Check the key parameters.
        ret = HksCoreSecureAccessInitParams(keyNode, paramSet, token);
        if (ret != HKS_SUCCESS) {
            HKS_LOG_E("init secure access params failed");
            HksDeleteKeyNode(keyNode->handle);
            return ret;
        }
        // Obtain the initialization handler from the algorithm library based on the usage of the key. 
        uint32_t i;
        uint32_t size = HKS_ARRAY_SIZE(g_hksCoreInitHandler);
        for (i = 0; i < size; i++) {
           if (g_hksCoreInitHandler[i].pur == pur) {
               HKS_LOG_E("Core HksCoreInit [pur] = %d, pur = %d", g_hksCoreInitHandler[i].pur, pur);
               ret = g_hksCoreInitHandler[i].handler(keyNode, paramSet, alg);
               break;
        }
        }
        // Check exception results.
        if (ret != HKS_SUCCESS) {
            HksDeleteKeyNode(keyNode->handle);
            HKS_LOG_E("CoreInit failed, ret : %d", ret);
            return ret;
        }
    
        if (i == size) {
            HksDeleteKeyNode(keyNode->handle);
            HKS_LOG_E("don't found purpose, pur : %u", pur);
            return HKS_FAILURE;
        }
    
        HKS_LOG_D("HksCoreInit in Core end");
        return ret;
    }
   ```

2. Obtain the context based on the handle, and pass in data slices to obtain the operation result or append data.
   
    ```c
    // Implement Update().
    int32_t HksCoreUpdate(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData,
        struct HksBlob *outData)
    {
        HKS_LOG_D("HksCoreUpdate in Core start");
        uint32_t pur = 0;
        uint32_t alg = 0;
        // Check parameters.
        if (handle == NULL || paramSet == NULL || inData == NULL) {
            HKS_LOG_E("the pointer param entered is invalid");
            return HKS_FAILURE;
        }
        
        uint64_t sessionId;
        struct HuksKeyNode *keyNode = NULL;
        // Obtain the context based on the handle.
        int32_t ret = GetParamsForUpdateAndFinish(handle, &sessionId, &keyNode, &pur, &alg);
        if (ret != HKS_SUCCESS) {
            HKS_LOG_E("GetParamsForCoreUpdate failed");
            return ret;
        }
        // Verify key parameters.
        ret = HksCoreSecureAccessVerifyParams(keyNode, paramSet);
        if (ret != HKS_SUCCESS) {
            HksDeleteKeyNode(sessionId);
            HKS_LOG_E("HksCoreUpdate secure access verify failed");
            return ret;
        }
        // Call the key handler from the corresponding algorithm library.
        uint32_t i;
        uint32_t size = HKS_ARRAY_SIZE(g_hksCoreUpdateHandler);
        for (i = 0; i < size; i++) {
            if (g_hksCoreUpdateHandler[i].pur == pur) {
                struct HksBlob appendInData = { 0, NULL };
                ret = HksCoreAppendAuthInfoBeforeUpdate(keyNode, pur, paramSet, inData, &appendInData);
                if (ret != HKS_SUCCESS) {
                    HKS_LOG_E("before update: append auth info failed");
                    break;
                }
                ret = g_hksCoreUpdateHandler[i].handler(keyNode, paramSet,
                     appendInData.data == NULL ? inData : &appendInData, outData, alg);
                if (appendInData.data != NULL) {
                    HKS_FREE_BLOB(appendInData);
                }
                break;
            }
        }
        // Check exception results.
        if (ret != HKS_SUCCESS) {
            HksDeleteKeyNode(keyNode->handle);
            HKS_LOG_E("CoreUpdate failed, ret : %d", ret);
            return ret;
        }
        
        if (i == size) {
            HksDeleteKeyNode(sessionId);
            HKS_LOG_E("don't found purpose, pur : %u", pur);
            return HKS_FAILURE;
        }
        return ret;
    }
    ```

3. Finish the key operation to obtain the result, and destroy the handle.

   ```c
   // Implement Finish().
   int32_t HksCoreFinish(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData,
    struct HksBlob *outData)
   {
       HKS_LOG_D("HksCoreFinish in Core start");
       uint32_t pur = 0;
       uint32_t alg = 0;
       // Check parameters.
       if (handle == NULL || paramSet == NULL || inData == NULL) {
           HKS_LOG_E("the pointer param entered is invalid");
           return HKS_FAILURE;
       }
    
       uint64_t sessionId;
       struct HuksKeyNode *keyNode = NULL;
       // Obtain the context based on the handle.
       int32_t ret = GetParamsForUpdateAndFinish(handle, &sessionId, &keyNode, &pur, &alg);
       if (ret != HKS_SUCCESS) {
           HKS_LOG_E("GetParamsForCoreUpdate failed");
           return ret;
       }
       // Verify key parameters.
       ret = HksCoreSecureAccessVerifyParams(keyNode, paramSet);
       if (ret != HKS_SUCCESS) {
           HksDeleteKeyNode(sessionId);
           HKS_LOG_E("HksCoreFinish secure access verify failed");
           return ret;
       }
       // Call the key handler from the corresponding algorithm library.
       uint32_t i;
       uint32_t size = HKS_ARRAY_SIZE(g_hksCoreFinishHandler);
       for (i = 0; i < size; i++) {
           if (g_hksCoreFinishHandler[i].pur == pur) {
               uint32_t outDataBufferSize = (outData == NULL) ? 0 : outData->size;
               struct HksBlob appendInData = { 0, NULL };
               ret = HksCoreAppendAuthInfoBeforeFinish(keyNode, pur, paramSet, inData, &appendInData);
               if (ret != HKS_SUCCESS) {
                   HKS_LOG_E("before finish: append auth info failed");
                   break;
               }
               ret = g_hksCoreFinishHandler[i].handler(keyNode, paramSet,
                   appendInData.data == NULL ? inData : &appendInData, outData, alg);
               if (appendInData.data != NULL) {
                   HKS_FREE_BLOB(appendInData);
               }
               if (ret != HKS_SUCCESS) {
                   break;
               }
               // Append the end label of the key operation.
               ret = HksCoreAppendAuthInfoAfterFinish(keyNode, pur, paramSet, outDataBufferSize, outData);
               break;
           }
       }
       if (i == size) {
           HKS_LOG_E("don't found purpose, pur : %d", pur);
           ret = HKS_FAILURE;
       }
       // Delete the session.
       HksDeleteKeyNode(sessionId);
       HKS_LOG_D("HksCoreFinish in Core end");
       return ret;
   }
   ```

### Verification

Use the [HUKS JS APIs](https://gitee.com/openharmony/security_huks/blob/master/interfaces/kits/js/@ohos.security.huks.d.ts) to develop a JavaScript application to verify HUKS capabilities.

The JS API corresponding to each HDI API is provided in [Available APIs](#available-apis). You can invoke the JS APIs to verify the capabilities of the corresponding HDI APIs or perform complete key operations to verify the capabilities of the APIs.

The JS test code is as follows. If the entire process is successful, the HDI APIs are functioning. For more information about key operations, see [HUKS Development](../../application-dev/security/huks-guidelines.md).

**Generating and Encrypting an AES Key**

1. Import the HUKS module.

   ```js
   import huks from '@ohos.security.huks'
   ```

2. Call **generateKey()** to generate a key.

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

3. Call **Init()** to perform initialization.

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
   
4. Call **update()** to perform the **Update** operation.

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
   
5. Call **finish()** to finish the operation.

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
