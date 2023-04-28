# Data Reliability and Security Overview

## Introduction

During system running, a database fault may occur due to storage damage, insufficient storage space, file system permission, or system power-off. The database fault may cause data loss. For example, the database corruption of Contacts causes the loss of Contacts data. The data management subsystem provides the following solutions and capabilities to ensure data reliability and security:

- Data backup and restoration: Critical data (such as the bank information) can be backed up and restored from the backup to prevent data loss.

- Database encryption: The database that stores sensitive information, such as authentication credentials and financial data, can be encrypted to improve data security.

- Access control by device and data level: The access to data across devices is controlled based on the device security level and data security labels.

In addition, the backup database is stored in the application sandbox. When the storage space is insufficient, you can delete the local database backup to release space.


## Basic Concepts

Before developing functions related to data reliability and security, understand the following concepts.


### Database Backup and Restoration

- Database backup: OpenHarmony provides full backup of database files.
  When backing up a database, you only need to invoke the backup API of the database, without closing the database.

- Database restoration: You can restore a database from a database backup file.


### Database Encryption

The entire database file can be encrypted to enhance the database security.


### Data Rating

In distributed scenarios, the access to data is controlled based on the device security level and data security labels.

A higher data security label and device security level indicate stricter encryption and access control measures and higher data security.


## Working Principles


### Database Backup and Restoration Mechanism

The data of a database is backed up to the specified file. Subsequent operations on the database do not affect the backup file. The database is overwritten by the specified backup file only when a restoration is performed.

- KV store backup directory: **/data/service/el1(el2)/public/database/...{appId}/kvdb/backup/...{storeId}**

- RDB store backup directory: **/data/app/el1(el2)/100/database/...{bundlename}/rdb**


### Database Encryption Mechanism

When encrypting a database, you do not need to pass in the key for encryption. The only thing you need to do is set the database encryption status. The system automatically calls the [HUKS APIs](../reference/apis/js-apis-huks.md) to generate a key and encrypt the database.


## Constraints

- The database encryption key is automatically changed once a year.

- A maximum of five backup files can be retained for a KV store.

- Automatic backup of a KV store must be performed when the device is charging and the screen is off.
