# Cross-Application Data Sharing

## Introduction

OpenHarmony provides APIs for an application to manage its own data and share data with other applications.

Data needs to be shared in a wealth of scenarios. For example, the Contacts, short message service (SMS), and Gallery data always needs to be shared with other applications. However, certain data, such as accounts and passwords, cannot be shared. Some data, such as SMS messages, can be queried but not modified by other applications. Therefore, a secure and efficient cross-application data sharing mechanism for different data sharing scenarios and data privacy protection is very important.

Currently, OpenHarmony supports one-to-many and many-to-many cross-application data sharing, based on the number of the data provider applications involved.

## Basic Concepts

Before you start, understand the following concepts:

- **Data provider**: an application that provides data and implements related services. It is also called the producer or server.

- **Data consumer**: an application that accesses the data or services provided by the data provider. It is also called the client.

- **ValuesBucket**: a set of data to be inserted. It can be one or more data records in key-value (KV) pairs. In each KV pair, the key must be of the string type, and the value can be a number, a string, a Boolean value, or an unsigned integer array.

- **ResultSet**: a set of query results. It provides flexible modes for users to obtain various data.

- **Predicates**: an object that specifies the conditions for updating, deleting, or querying data in a database.

## One-to-Many Cross-Application Data Sharing
<!--RP1-->
You can use **DataShare** to implement one-to-many data sharing across applications. Two implementation modes are provided, depending on whether the data provider is started in the cross-application data sharing.  
<!--RP1End-->
<!--Del-->
### Implementation

The data provider can directly use **DataShare** to share data with other applications without complex encapsulation. The data consumer only needs to use a set of APIs because the **DataShare** access mode does not vary with the data provision mode. This greatly reduces the learning time and development difficulty.

**DataShare** implements cross-application data sharing in either of the following ways:

- [Using DataShareExtensionAbility](share-data-by-datashareextensionability.md)

  You need to implement an ExtensionAbility with callbacks in the HAP. When the data consumer calls an API, the ExtensionAbility of the data provider will be automatically started to invoke the registered callback.

  You can use **DataShareExtensionAbility** when the cross-application data access involves service operations other than mere addition, deletion, modification, and query of data in databases.

- [Using Silent Access via the DatamgrService](share-data-by-silent-access.md)

  You need to configure database access rules in the HAP. When the data consumer calls an API, the system ability automatically obtains the access rules in the HAP and returns data without starting the data provider.

  You can use this mode when the cross-application data access involves only database operations (data addition, deletion, modification, and query) or data hosted to the DatamgrService.
  
If your application is signed with a system signature, you can use both methods. When data is created for the first time, use **DataShareExtensionAbility**. When data is accessed and modified later, use the **DatamgrService** to share data. That is, the data provider is started only when the data is accessed for the first time.

### Restrictions

- **DataShare** is subject to the limitations on the database used by the data provider. For example, the supported data models, length of the keys and values, and maximum number of databases that can be accessed at a time by each application vary with the database in use.

- The payloads of **ValuesBucket**, **Predicates**, and **ResultSet** are restricted by IPC.

- Currently, **dataShare** supports development based on the stage model only.
<!--DelEnd-->

## Many-to-Many Cross-Application Data Sharing

In one-to-many cross-application data sharing, there is only one data provider. In many-to-many cross-application data sharing, you need to consider data definition, data exchange, and permission management. The UDMF provides a new data sharing and interaction mode to implement many-to-many cross-application data sharing.

### Implementation

[Sharing Data via Unified Data Channels](unified-data-channels.md)

Applications can call the APIs provided by the UDMF to write data that complies with the unified data definition to different data sharing channels of the UDMF. The data in these channels can be read by other applications. The data written into the UDMF is managed based on the permissions of the application, permissions of the data channels, and the permission management logic of the UDMF. Lifecycle management is also performed on the data written into the channels in the same way. In this way, the data scattered in each application is aggregated via different channels of the UDMF, improving the development efficiency and data experience of users.
