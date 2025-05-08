# ArkData (Ark Data Management)

- [Introduction to ArkData](data-mgmt-overview.md)
- Unified Data Definition<!--uniform-data-definition-->
  - [Unified Data Definition Overview](unified-data-definition-overview.md)
  - [UTDs](uniform-data-type-descriptors.md)
  - [Uniform Data Structs](uniform-data-structure.md)
  - [Prebuilt UTDs](uniform-data-type-list.md)
- Application Data Persistence<!--app-data-persistence-->
  - [Application Data Persistence Overview](app-data-persistence-overview.md)
  - [Persisting User Preferences (ArkTS)](data-persistence-by-preferences.md)
  - [Persisting User Preferences (C/C++)](preferences-guidelines.md)
  - [Persisting KV Store Data](data-persistence-by-kv-store.md)
  - [Persisting RDB Store Data](data-persistence-by-rdb-store.md)
  - [Persisting Vector Store Data (ArkTS)](data-persistence-by-vector-store.md)
  - [Persisting Vector Store Data (C/C++)](native-vector-store-guidelines.md)
  <!--Del-->
  - [Persisting Graph Store Data (for System Applications Only)](data-persistence-by-graph-store.md)
  <!--DelEnd-->
- Distributed Application Data Sync<!--distributed-data-sync-->
  - [Overview of Distributed Application Data Sync](sync-app-data-across-devices-overview.md)
  - [Cross-Device Sync of KV Stores](data-sync-of-kv-store.md)
  - [Cross-Device Sync of RDB Stores](data-sync-of-rdb-store.md)
  - [Cross-Device Sync of Distributed Data Objects](data-sync-of-distributed-data-object.md)
- Data Reliability and Security<!--data-reliability-security-->
  - [Data Reliability and Security Overview](data-reliability-security-overview.md)
  - [Database Backup and Restore](data-backup-and-restore.md)
  - [Database Encryption](data-encryption.md)
  - [Access Control by Device and Data Level](access-control-by-device-and-data-level.md)
  - [Using an EL5 Database](encrypted_estore_guidelines.md)
- Cross-Application Data Sharing<!--cross-app-data-share-->
  - [Overview of Cross-Application Data Sharing](data-share-overview.md)
  <!--Del-->
  - One-to-Many Data Sharing (for System Applications Only)<!--one-to-many-data-share-->
    - [Sharing Data via DataShareExtensionAbility](share-data-by-datashareextensionability.md)
    - [Silent Access via DatamgrService](share-data-by-silent-access.md)
  <!--DelEnd-->
  - Many-to-Many Data Sharing<!--many-to-many-data-share-->
    - [Sharing Data via Unified Data Channels](unified-data-channels.md)
- Intelligent Data Construction and Retrieval<!--intelligence-data-->
  - [AIP Overview](aip-data-intelligence-overview.md)
  - [Application Data Vectorization](aip-data-intelligence-embedding.md)
- [RelationalStore Development (C/C++)](native-relational-store-guidelines.md)
- [UDMF Development (C/C++)](native-unified-data-management-framework-guidelines.md)
