# OH_Rdb_Config

## Overview

Defines the RDB store configuration.

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                   | Description                                                        |
| ----------------------- | ------------------------------------------------------------ |
| int selfSize            | Size of the struct.                                            |
| const char* dataBaseDir | Path of the database file.                                            |
| const char* storeName   | Name of the RDB store.                                                |
| const char* bundleName  | Bundle name of the application.                                                  |
| const char* moduleName  | Module name.                                                |
| bool isEncrypt          | Whether to encrypt the RDB store.                                        |
| int securityLevel       | Database security level ([OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)).|
| int area                | Database security area level ([Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)).<br>**Since**: 11|
