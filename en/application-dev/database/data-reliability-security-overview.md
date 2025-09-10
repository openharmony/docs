# Data Reliability and Security Overview
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997; @dboy190-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Introduction

A database fault may be caused by storage corruption, insufficient storage space, lack of file system permission, or system power-off. The database fault may cause data loss or even malfunction of the system. For example, the database corruption of Contacts causes the loss of Contacts data, and the database corruption of Calendar may cause loss of Calendar reminders. ArkData management provides the following solutions and capabilities to ensure data reliability and security:

- Data backup and restore: Critical data (such as bank information) can be backed up and restored from the backup to prevent data loss.

- Database encryption: The database that stores sensitive information, such as authentication credentials and financial data, can be encrypted to improve data security.

- Access control by device and data level: The access to data across devices is controlled based on the device security level and data security labels.

- EL5 database: The database in the **el5/** directory stores sensitive user information. To protect the data in such as database, the key will be destroyed when the screen is locked and certain conditions are met, and the database cannot be operated. After the screen is unlocked, the key is restored and the read and write operations on the database are restored. This feature ensures the security of sensitive information.

In addition, the backup database is stored in the application sandbox. When the storage space is insufficient, you can delete the local database backup to release space.


## Basic Concepts

Before developing functions related to data reliability and security, understand the following concepts:


### Database Backup and Restore

- Database backup: A full backup is performed for OpenHarmony database files.
  The related API is called to perform the backup, without closing the database.

- Database restore: Database data can be restored from a database backup file. After the data restore is complete, the database is restored to the state when the data was backed up.


### Database Encryption

The entire database file can be encrypted to enhance database security.


### Access Control by Data Level

Distributed data management implements access control based on data security labels and device security levels.

A higher data security label and device security level indicate stricter encryption and access control measures and higher data security.


## Working Principles


### Database Backup and Restore Mechanism

The data of a database is backed up to the specified file. Subsequent operations on the database do not affect the backup file. The database is overwritten by the specified backup file only when a restore is performed.

- KV store backup directory: **/data/service/el1(el2)/public/database/...{appId}/kvdb/backup/...{storeId}**

- RDB store backup directory: **/data/app/el1(el2)/100/database/...{bundlename}/rdb**


### Database Encryption Mechanism

When encrypting a database, you do not need to pass in the key for encryption. All you need to do is set the database encryption status. The system automatically calls the [HUKS APIs](../reference/apis-universal-keystore-kit/js-apis-huks.md) to generate a key and encrypt the database.


## Constraints

- The database encryption key is automatically changed once a year.

- A maximum of five backup files can be retained for a KV store.

- Automatic backup of a KV store must be performed when the device is charging and the screen is off.
