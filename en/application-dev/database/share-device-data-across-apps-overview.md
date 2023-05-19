# Cross-Application Data Sharing Overview

## Function

The application data on a device, such as the Contacts, short message service (SMS), and Gallery data, always needs to be shared with other applications. However, certain data, such as the accounts and passwords, cannot be shared. Certain data, such as SMS messages, can be accessed but not modified by other applications. The **DataShare**  module provides a secure and easy-to-use mechanism for sharing data of an application with other applications on the same device.

## Basic Concepts

Before developing cross-application data sharing on a device, understand the following concepts:

- Data provider: an application that provides data and implements related services. It is also called the data producer or server.

- Data consumer: an application that accesses the data or services provided by the data provider. It is also called the client.

- **ValuesBucket**: a set of data to be inserted. It can be one or more data records in KV pairs. In each KV pair, the key must be of the string type, and the value can be a number, a string, a Boolean value, or an unsigned integer array.

- **ResultSet**: a set of query results. It provides flexible modes for obtaining various data.

- **Predicates**: an object that specifies the conditions for updating, deleting, or querying data in a database.


## Implementation

The data provider can directly use **DataShare** to share data with other applications without complex encapsulation. The data consumer only needs to use a set of APIs to access the data, because the **DataShare** access mode does not vary with the data provisioning mode. This greatly reduces the learning time and development difficulty.

The cross-application data sharing can be implemented in either of the following ways:

- **DataShareExtensionAbility**

  You can implement an ExtensionAbility with a callback in the HAP. When the data consumer calls an API, the ExtensionAbility of the data provider will be automatically started to invoke the registered callback.

  This method is recommended when the cross-application data access involves service operations other than mere addition, deletion, modification, and query of data in databases.

- Silent access

  You can configure database access rules in the HAP. When the data consumer calls an API, the system ability automatically obtains the access rules in the HAP and returns data without starting the data provider.

  This method is recommended when the cross-application data access involves only the operations for adding, deleting, modifying, and querying data in databases.


## Constraints

- **DataShare** is subject to the limitations on the database used by the data provider. The supported data models, length of the keys and values, and maximum number of databases that can be accessed at a time by each application vary with the database in use.

- The payloads of **ValuesBucket**, **Predicates**, and **ResultSet** are restricted by inter-process communication (IPC).

- Currently, **dataShare** supports development based on the stage model only.
