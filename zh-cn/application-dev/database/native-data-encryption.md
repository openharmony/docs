# 数据库加密（C/C++）

## 场景介绍

为了增强数据库的安全性，数据库提供了安全的加密功能，以有效保护存储的内容。
通过数据库加密，实现了数据库数据存储的保密性和完整性要求，使得数据库以密文方式存储并在密态方式下工作，确保了数据安全。

加密后的数据库只能通过接口进行访问，无法通过其它方式打开数据库文件。数据库的加密属性在创建数据库时确认，无法变更。

当前仅支持使用关系型数据库（C/C++）进行数据库加密。

## 开发步骤

关系型数据库通过调用OH_Rdb_SetEncrypted方法来设置是否加密。isEncrypted参数为true时表示加密，为false时表示不加密，默认不加密。

当isEncrypted为true时，可调用OH_Rdb_SetCryptoParam方法设置自定义的加密/解密密钥和算法等参数。





1. CMakeLists.txt中添加以下lib。

    ```txt
    libnative_rdb_ndk.z.so
    ```

2. 导入头文件。

    ```c
    #include "database/rdb/relational_store.h"
    ```

3. 针对是否配置自定义加密/解密参数，有如下两种场景：

    * 场景1：不配置自定义加密/解密参数，此时会使用默认的配置进行数据库的加密/解密。

        ```c
        OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        // 设置为使用加密方式创建或打开数据库
        OH_Rdb_SetEncrypted(config, true);
        
        int errCode = 0;
        
        // 获取OH_Rdb_Store实例
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        ```

    * 场景2：使用OH_Rdb_SetCryptoParam接口配置加密参数，此时会使用开发者自定义的密钥和算法参数进行数据库的加密/解密。
    
      如果开发者不关心加密算法及参数，使用默认加密配置即可，无需创建和配置自定义加密参数。

        ```c
        OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
        OH_Rdb_SetStoreName(config, "RdbTestConfigEncryptParam.db");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        // 设置为使用加密方式创建或打开数据库
        OH_Rdb_SetEncrypted(config, true);
        // 创建自定义加密参数对象
        OH_Rdb_CryptoParam *cryptoParam = OH_Rdb_CreateCryptoParam();
        
        uint8_t key[6] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36 };
        // 使用指定的密钥打开加密数据库。不指定则由数据库负责生成并保存密钥，并使用生成的密钥。
        OH_Crypto_SetEncryptionKey(cryptoParam, key, 6);
        // 设置KDF算法迭代次数。迭代次数必须大于零。不指定或等于零则使用默认值10000和默认加密算法。
        OH_Crypto_SetIteration(cryptoParam, 64000);
        // 设置加密算法，如不设置默认为AES_256_GCM
        OH_Crypto_SetEncryptionAlgo(cryptoParam, Rdb_EncryptionAlgo::RDB_AES_256_CBC);
        // 设置HMAC算法，如不设置默认为SHA256
        OH_Crypto_SetHmacAlgo(cryptoParam, RDB_HMAC_SHA512);
        // 设置KDF算法，如不设置默认为SHA256
        OH_Crypto_SetKdfAlgo(cryptoParam, RDB_KDF_SHA512);
        // 设置打开加密数据库时使用的页大小，须为1024到65536之间的整数且为2的幂，如不设置默认为1024
        OH_Crypto_SetCryptoPageSize(cryptoParam, 4096);
        // 设置自定义加密参数
        OH_Rdb_SetCryptoParam(config, cryptoParam);
           
        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        // 销毁自定义加密参数对象
        OH_Rdb_DestroyCryptoParam(cryptoParam);
        OH_Rdb_CloseStore(store);
        ```
