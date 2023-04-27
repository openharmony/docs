# DataShare Overview


## Function

The **DataShare** module allows an application to share its data with other applications. Currently, data can be shared only between applications on the same device.

Data needs to be shared in a wealth of scenarios. For example, the Contacts, short message service (SMS), and Gallery data always needs to be shared with other applications. However, certain data, such as accounts and passwords, cannot be shared. Some data, such as SMS messages, can be queried but not modified by other applications. **DataShare** provides a secure and convenient sharing mechanism for application data.

The data provider can directly use **DataShare** to share data with other applications without complex encapsulation. The data consumer only needs to use a set of APIs because the DataShare access mode does not vary with the data provision mode. This greatly reduces the learning time and development difficulty.

Data can be shared across applications in either of the following ways:

- Using **DataShareExtensionAbility**
  An extension ability is implemented in the HAP to invoke a callback. When the data consumer calls an API, the extension ability of the data provider will be automatically started to invoke the registered callback.

  You can use **DataShareExtensionAbility** when the cross-application data access involves service operations other than mere addition, deletion, modification, and query of data in databases.

- Using Silent Access
  Database access rules are configured in the HAP. When the data consumer calls an API, the system ability automatically obtains the access rules in the HAP and returns data without starting the data provider.

  You can use the silent access feature when the cross-application data access involves only the operations for adding, deleting, modifying, and querying data in databases.


## Basic Concepts

Before developing cross-application data sharing on a device, understand the following concepts:

- Data provider: an application that provides data and implements related services. It is also called the producer or server.

- Data consumer: an application that accesses the data or services provided by the data provider. It is also called the client.

- **ValuesBucket**: a set of data to be inserted. It can be one or more data records in KV pairs. In each KV pair, the key must be of the string type, and the value can be a number, a string, a Boolean value, or an unsigned integer array.

- **ResultSet**: a set of query results. It provides flexible modes for users to obtain various data.

- **Predicates**: an object that specifies the conditions for updating, deleting, or querying data in a database.


## Constraints

- **DataShare** is subject to the limitations on the database used by the data provider. For example, the supported data models, length of the keys and values, and maximum number of databases that can be accessed at a time by each application vary with the database in use.

- The payloads of **ValuesBucket**, **Predicates**, and **ResultSet** are restricted by IPC.

- Currently, **dataShare** supports development based on the stage model only.
