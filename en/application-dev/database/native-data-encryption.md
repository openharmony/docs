# Database Encryption (C/C++)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## When to Use

The database encryption capability is provided to effectively protect the data stored in a database.
Database encryption allows data to be stored and used in ciphertext, ensuring data confidentiality and integrity.

The encrypted database can be accessed only using an API, and the database file cannot be opened in other ways. Whether a database is encrypted is set when the database is created, and the setting cannot be changed.

Currently, only RDB stores (C/C++) support database encryption.

## How to Develop

Call **OH_Rdb_SetEncrypted** to set whether to encrypt an RDB store. If **isEncrypted** is set to **true**, the database is encrypted; otherwise, the database is not encrypted. This parameter is set to **false** by default.

When **isEncrypted** is set to **true**, call **OH_Rdb_SetCryptoParam** to set custom keys and algorithms for encryption or decryption.

1. Add the following library to **CMakeLists.txt**.

    ```txt
    libnative_rdb_ndk.z.so
    ```

2. Include header files.

    ```c
    #include "database/rdb/relational_store.h"
    ```

3. You can set encryption/decryption parameters as follows:

    * Scenario 1: If no custom encryption/decryption parameter is configured, the default configuration is used.

        ```c
        OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        // Set the database to be created or opened in encryption mode.
        OH_Rdb_SetEncrypted(config, true);
        
        int errCode = 0;
        
        // Create an OH_Rdb_Store instance.
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        ```

    * Scenario 2: Call **OH_Rdb_SetCryptoParam** to configure encryption parameters. The database is encrypted and decrypted using the custom key and algorithm parameters.
    
      If custom configuration is not required, you can use the default encryption configuration.

        ```c
        OH_Rdb_ConfigV2* config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
        OH_Rdb_SetStoreName(config, "RdbTestConfigEncryptParam.db");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        // Set the database to be created or opened in encryption mode.
        OH_Rdb_SetEncrypted(config, true);
        // Create a custom encryption parameter object.
        OH_Rdb_CryptoParam *cryptoParam = OH_Rdb_CreateCryptoParam();
        
        uint8_t key[6] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36 };
        // Use the specified key to open the encrypted database. If no key is specified, the database generates and saves the key and uses the generated key.
        OH_Crypto_SetEncryptionKey(cryptoParam, key, 6);
        // Set the number of iterations of the KDF algorithm, which must be greater than 0. If the value is not specified or the number of iterations is 0, the default value 10000 and the default encryption algorithm are used.
        OH_Crypto_SetIteration(cryptoParam, 64000);
        // Set the encryption algorithm. If it is not specified, AES_256_GCM is used by default.
        OH_Crypto_SetEncryptionAlgo(cryptoParam, Rdb_EncryptionAlgo::RDB_AES_256_CBC);
        // Set the HMAC algorithm. If it is not specified, SHA-256 is used by default.
        OH_Crypto_SetHmacAlgo(cryptoParam, RDB_HMAC_SHA512);
        // Set the KDF algorithm. If it is not specified, SHA-256 is used by default.
        OH_Crypto_SetKdfAlgo(cryptoParam, RDB_KDF_SHA512);
        // Set the page size used when the database is encrypted. The value must be an integer ranging from 1024 to 65536 and be a power of 2. If it is not specified, the default value 1024 is used.
        OH_Crypto_SetCryptoPageSize(cryptoParam, 4096);
        // Set the custom encryption parameters.
        OH_Rdb_SetCryptoParam(config, cryptoParam);
           
        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        // Destroy the custom encryption parameter object.
        OH_Rdb_DestroyCryptoParam(cryptoParam);
        OH_Rdb_CloseStore(store);
        ```
