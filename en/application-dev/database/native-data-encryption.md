# Database Encryption (C/C++)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @htt1997-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=b370e209c091d2372f3f4630d52668e908547bd5 translatedAt=2026-07-27T08:15:58.083Z pushedAt=2026-07-27T09:47:25.848Z -->

## When to Use

The database encryption capability is provided to effectively protect the data stored in a database.

Database encryption allows data to be stored and used in ciphertext, ensuring data confidentiality and integrity.

An encrypted database can only be accessed through APIs. The database file cannot be opened in other ways. The encryption attributes of a database are determined when the database is created and cannot be changed. Starting from API version 22, RDB stores support adjusting their encryption attributes through the [OH_Rdb_RekeyEx](../reference/apis-arkdata/capi-relational-store-h.md#oh_rdb_rekeyex) API.

Currently, only RDB stores (C/C++) support database encryption.

## How to Develop

Call **OH_Rdb_SetEncrypted** to set whether to encrypt an RDB store. If **isEncrypted** is set to **true**, the database is encrypted; otherwise, the database is not encrypted. This parameter is set to **false** by default.

When **isEncrypted** is set to **true**, call **OH_Rdb_SetCryptoParam** to set custom keys and algorithms for encryption or decryption.

1. Add the following library to **CMakeLists.txt**.

    ```txt
    libnative_rdb_ndk.z.so
    ```

2. Include header files.

    <!-- @[encryption_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) --> 

    ``` C++
    #include <cstring>
    #include "database/rdb/relational_store.h"
    #include "hilog/log.h"
    ```

3. You can set encryption/decryption parameters as follows:

    * Scenario 1: If no custom encryption/decryption parameter is configured, the default configuration is used.

      <!-- @[DefaultConfigRdbStore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) -->

      ``` C++
      OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
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
      OH_Rdb_CloseStore(store);
      store = nullptr;
      OH_Rdb_DestroyConfig(config);
      config = nullptr;
      ```

    * Scenario 2: Call **OH_Rdb_SetCryptoParam** to configure encryption parameters. The database is encrypted and decrypted using the custom key and algorithm parameters.

      If custom configuration is not required, you can use the default encryption configuration.

      <!-- @[CustomizedConfigRdbStore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) --> 

      ``` C++
      OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
      OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
      OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
      OH_Rdb_SetStoreName(config, "RdbTestConfigEncryptParam.db");
      OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
      OH_Rdb_SetBundleName(config, "com.example.nativedemo");
      // Set the database to be created or opened in encryption mode.
      OH_Rdb_SetEncrypted(config, true);
      // Create a custom encryption parameter object.
      OH_Rdb_CryptoParam *cryptoParam = OH_Rdb_CreateCryptoParam();
          
      // Hard-coded keys are used as an example. You should use a secure key management service in actual development.
      uint8_t key[6] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36};
      // Use the specified key to open the encrypted database. If no key is specified, the database generates and saves the key and uses the generated key.
      const int32_t length = 6;
      OH_Crypto_SetEncryptionKey(cryptoParam, key, length);
      // Clear the key information after use.
      for (size_t i = 0; i < sizeof(key); i++) {
          key[i] = 0;
      }
      // Set the number of iterations of the KDF algorithm, which must be greater than 0. If the value is not specified or the number of iterations is 0, the default value 10000 and the default encryption algorithm are used.
      const int64_t iteration = 64000;
      OH_Crypto_SetIteration(cryptoParam, iteration);
      // Set the encryption algorithm. If it is not specified, AES_256_GCM is used by default.
      OH_Crypto_SetEncryptionAlgo(cryptoParam, Rdb_EncryptionAlgo::RDB_AES_256_CBC);
      // Set the HMAC algorithm. If it is not specified, SHA-256 is used by default.
      OH_Crypto_SetHmacAlgo(cryptoParam, RDB_HMAC_SHA512);
      // Set the KDF algorithm. If it is not specified, SHA-256 is used by default.
      OH_Crypto_SetKdfAlgo(cryptoParam, RDB_KDF_SHA512);
      // Set the page size used when the database is encrypted. The value must be an integer ranging from 1024 to 65536 and be a power of 2. If it is not specified, the default value 1024 is used.
      const int64_t pageSize = 4096;
      OH_Crypto_SetCryptoPageSize(cryptoParam, pageSize);
      // Set the custom encryption parameters.
      OH_Rdb_SetCryptoParam(config, cryptoParam);
          
      int errCode = 0;
      OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
      // Destroy the custom encryption parameter object.
      OH_Rdb_DestroyCryptoParam(cryptoParam);
      cryptoParam = nullptr;
      OH_Rdb_CloseStore(store);
      store = nullptr;
      OH_Rdb_DestroyConfig(config);
      config = nullptr;
      ```

4. Since API version 22, you can use **OH_Rdb_RekeyEx** to change the key or encryption parameters of an encrypted database as required.

   The database key and encryption parameters can be changed in the following scenarios:
    > **NOTE**
    >
    > Exercise caution when changing encryption parameters. After **OH_Rdb_RekeyEx** is used, you must use the new parameters to open the database. Otherwise, the database may fail to be opened. If the rekey process is interrupted due to device power-off or other reasons, the operation may succeed or fail. Therefore, it is recommended that the service party perform a redundancy retry based on the parameters modified before and after **OH_Rdb_RekeyEx** is used to ensure the database status is correctly determined and the database can be opened.

    * Scenario 1: The original database is encrypted using default parameters. Change the key and encryption parameters.

        ```c
        OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el3/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL3);
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetModuleName(config, "entry");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetEncrypted(config, true);
        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        if (store == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create store failed, errCode: %{public}d", errCode);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        OH_Rdb_CryptoParam *crypto = OH_Rdb_CreateCryptoParam();
        if (crypto == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create crypto failed.");
            OH_Rdb_DestroyConfig(config);
            OH_Rdb_CloseStore(store);
            config = NULL;
            store = NULL;
            return;
        }
        OH_Crypto_SetEncryptionAlgo(crypto, RDB_AES_256_CBC);
        OH_Crypto_SetHmacAlgo(crypto, RDB_HMAC_SHA512);
        OH_Crypto_SetKdfAlgo(crypto, RDB_KDF_SHA512);
        OH_Crypto_SetCryptoPageSize(crypto, 2048);
        errCode = OH_Rdb_RekeyEx(store, crypto);

        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "RekeyEx failed, errCode: %{public}d", errCode);
        }
        // After OH_Rdb_RekeyEx is used, use new parameters to reopen the database.
        OH_Rdb_DestroyConfig(config);
        OH_Rdb_CloseStore(store);
        OH_Rdb_DestroyCryptoParam(crypto);
        config = NULL;
        store = NULL;
        crypto = NULL;
        ```

    * Scenario 2: The original database is encrypted using custom parameters. Change the custom key and encryption parameters.

        ```c
        OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el3/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL3);
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetModuleName(config, "entry");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetEncrypted(config, true);
        OH_Rdb_CryptoParam *crypto = OH_Rdb_CreateCryptoParam();
        if (crypto == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create crypto failed.");
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        uint8_t encryptionKey[] = "12345678";
        OH_Crypto_SetEncryptionKey(crypto, encryptionKey, sizeof(encryptionKey));
        memset(encryptionKey, 0, sizeof(encryptionKey));
        OH_Rdb_SetCryptoParam(config, crypto);

        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        if (store == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create store failed, errCode: %{public}d", errCode);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        OH_Rdb_CryptoParam *newCryptoParam = OH_Rdb_CreateCryptoParam();
        if (newCryptoParam == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create newCryptoParam failed.");
            OH_Rdb_DestroyConfig(config);
            OH_Rdb_CloseStore(store);
            OH_Rdb_DestroyCryptoParam(crypto);
            config = NULL;
            store = NULL;
            crypto = NULL;
            return;
        }
        // Note: Hard-coded keys are used as an example. You should use a secure key management service in actual development. After using the keys, clear them in a timely manner.
        uint8_t key[] = "87654321";
        OH_Crypto_SetEncryptionKey(newCryptoParam, key, sizeof(key));
        memset(key, 0, sizeof(key));
        OH_Crypto_SetEncryptionAlgo(newCryptoParam, RDB_AES_256_CBC);
        OH_Crypto_SetHmacAlgo(newCryptoParam, RDB_HMAC_SHA512);
        OH_Crypto_SetKdfAlgo(newCryptoParam, RDB_KDF_SHA512);
        OH_Crypto_SetCryptoPageSize(newCryptoParam, 4096);
        errCode = OH_Rdb_RekeyEx(store, newCryptoParam);

        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "RekeyEx failed, errCode: %{public}d", errCode);
        }
        // After OH_Rdb_RekeyEx is used, use new parameters to reopen the database.
        OH_Rdb_DestroyConfig(config);
        OH_Rdb_CloseStore(store);
        OH_Rdb_DestroyCryptoParam(crypto);
        OH_Rdb_DestroyCryptoParam(newCryptoParam);
        config = NULL;
        store = NULL;
        crypto = NULL;
        newCryptoParam = NULL;
        ```

    * Scenario 3: The original database is encrypted using default parameters. Change the default key and parameters to the custom key and encryption parameters.

        ```c
        OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el3/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL3);
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetModuleName(config, "entry");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetEncrypted(config, true);
        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        if (store == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create store failed, errCode: %{public}d", errCode);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        OH_Rdb_CryptoParam *crypto = OH_Rdb_CreateCryptoParam();
        if (crypto == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create crypto failed.");
            OH_Rdb_CloseStore(store);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            store = NULL;
            return;
        }
        // Note: Hard-coded keys are used as an example. You should use a secure key management service in actual development. After using the keys, clear them in a timely manner.
        uint8_t key[] = "12345678";
        errCode = OH_Crypto_SetEncryptionKey(crypto, key, sizeof(key));
        memset(key, 0, sizeof(key));
        OH_Crypto_SetEncryptionAlgo(crypto, RDB_AES_256_CBC);
        OH_Crypto_SetHmacAlgo(crypto, RDB_HMAC_SHA512);
        OH_Crypto_SetKdfAlgo(crypto, RDB_KDF_SHA512);
        OH_Crypto_SetCryptoPageSize(crypto, 2048);
        errCode = OH_Rdb_RekeyEx(store, crypto);

        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "RekeyEx failed, errCode: %{public}d", errCode);
        }
        // After OH_Rdb_RekeyEx is used, use new parameters to reopen the database.
        OH_Rdb_DestroyConfig(config);
        OH_Rdb_CloseStore(store);
        OH_Rdb_DestroyCryptoParam(crypto);
        config = NULL;
        store = NULL;
        crypto = NULL;
        ```

    * Scenario 4: The original database is encrypted using custom parameters. Change the key generated by database and custom encryption parameters.

        ```c
        OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el3/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL3);
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetModuleName(config, "entry");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetEncrypted(config, true);
        OH_Rdb_CryptoParam *crypto = OH_Rdb_CreateCryptoParam();
        if (crypto == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create crypto failed.");
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        // Note: Hard-coded keys are used as an example. You should use a secure key management service in actual development. After using the keys, clear them in a timely manner.
        uint8_t encryptionKey[] = "12345678";
        OH_Crypto_SetEncryptionKey(crypto, encryptionKey, sizeof(encryptionKey));
        memset(encryptionKey, 0, sizeof(encryptionKey));
        OH_Rdb_SetCryptoParam(config, crypto);

        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        if (store == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create store failed, errCode: %{public}d", errCode);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        OH_Rdb_CryptoParam *newCryptoParam = OH_Rdb_CreateCryptoParam();
        if (newCryptoParam == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create newCryptoParam failed.");
            OH_Rdb_DestroyConfig(config);
            OH_Rdb_CloseStore(store);
            OH_Rdb_DestroyCryptoParam(crypto);
            config = NULL;
            store = NULL;
            crypto = NULL;
            return;
        }
        OH_Crypto_SetEncryptionAlgo(newCryptoParam, RDB_AES_256_CBC);
        OH_Crypto_SetHmacAlgo(newCryptoParam, RDB_HMAC_SHA512);
        OH_Crypto_SetKdfAlgo(newCryptoParam, RDB_KDF_SHA512);
        OH_Crypto_SetCryptoPageSize(newCryptoParam, 4096);
        errCode = OH_Rdb_RekeyEx(store, newCryptoParam);

        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "RekeyEx failed, errCode: %{public}d", errCode);
        }
        // After OH_Rdb_RekeyEx is used, use new parameters to reopen the database.
        OH_Rdb_DestroyConfig(config);
        OH_Rdb_CloseStore(store);
        OH_Rdb_DestroyCryptoParam(crypto);
        OH_Rdb_DestroyCryptoParam(newCryptoParam);
        config = NULL;
        store = NULL;
        crypto = NULL;
        newCryptoParam = NULL;
        ```

    * Scenario 5: The original database is an encrypted database. Change it to a non-encrypted database.

        ```c
        OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el3/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL3);
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetModuleName(config, "entry");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetEncrypted(config, true);

        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        if (store == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create store failed, errCode: %{public}d", errCode);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        OH_Rdb_CryptoParam *crypto = OH_Rdb_CreateCryptoParam();
        if (crypto == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create crypto failed.");
            OH_Rdb_DestroyConfig(config);
            OH_Rdb_CloseStore(store);
            config = NULL;
            store = NULL;
            return;
        }
        OH_Crypto_SetEncryptionAlgo(crypto, RDB_PLAIN_TEXT);
        errCode = OH_Rdb_RekeyEx(store, crypto);

        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "RekeyEx failed, errCode: %{public}d", errCode);
        }
        // After OH_Rdb_RekeyEx is used, use new parameters to reopen the database.
        OH_Rdb_DestroyConfig(config);
        OH_Rdb_CloseStore(store);
        OH_Rdb_DestroyCryptoParam(crypto);
        config = NULL;
        store = NULL;
        crypto = NULL;
        ```

    * Scenario 6: The original database is a non-encrypted database. Change it to an encrypted database.

        ```c
        OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
        OH_Rdb_SetDatabaseDir(config, "/data/storage/el3/database");
        OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL3);
        OH_Rdb_SetStoreName(config, "RdbTest.db");
        OH_Rdb_SetBundleName(config, "com.example.nativedemo");
        OH_Rdb_SetModuleName(config, "entry");
        OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
        OH_Rdb_SetEncrypted(config, false);

        int errCode = 0;
        OH_Rdb_Store *store = OH_Rdb_CreateOrOpen(config, &errCode);
        if (store == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create store failed, errCode: %{public}d", errCode);
            OH_Rdb_DestroyConfig(config);
            config = NULL;
            return;
        }
        OH_Rdb_CryptoParam *crypto = OH_Rdb_CreateCryptoParam();
        if (crypto == NULL) {
            OH_LOG_ERROR(LOG_APP, "Create crypto failed.");
            OH_Rdb_DestroyConfig(config);
            OH_Rdb_CloseStore(store);
            config = NULL;
            store = NULL;
            return;
        }
        OH_Crypto_SetEncryptionAlgo(crypto, RDB_AES_256_CBC);
        OH_Crypto_SetHmacAlgo(crypto, RDB_HMAC_SHA512);
        OH_Crypto_SetKdfAlgo(crypto, RDB_KDF_SHA512);
        OH_Crypto_SetCryptoPageSize(crypto, 2048);
        errCode = OH_Rdb_RekeyEx(store, crypto);

        if (errCode != 0) {
            OH_LOG_ERROR(LOG_APP, "RekeyEx failed, errCode: %{public}d", errCode);
        }
        // After OH_Rdb_RekeyEx is used, use new parameters to reopen the database.
        OH_Rdb_DestroyConfig(config);
        OH_Rdb_CloseStore(store);
        OH_Rdb_DestroyCryptoParam(crypto);
        config = NULL;
        store = NULL;
        crypto = NULL;
        ```