# Data Sharing Through Silent Access


## When to Use

In a typical cross-application data access scenario, an application may be started multiple times.

To reduce the number of application startup times and improve the access speed, OpenHarmony provides the silent access feature, which allows direct access to the database without starting the data provider.

Silent access supports only basic database access. If service processing is required, implement service processing in the data consumer.

If the service processing is complex, use **DataShareExtensionAbility** to start the data provider.


## Working Principles

**Figure 1** Silent access

![silent_dataShare](figures/silent_dataShare.jpg)

- In silent access, **DatamgrService** obtains the access rules configured by the data provider through directory mapping, performs preprocessing based on rules, and accesses the database.

- To use silent access, the URIs must be in the following format:
  datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}?Proxy=true

  "Proxy=true" means to access data without starting the data provider. If **Proxy** is not set to **true**, the data provider is started.

  The **DatamgrService** obtains the data provider application based on **bundleName**, reads the configuration, verifies the permission, and accesses data.


## Constraints

- Currently, only RDB stores support silent access.

- The system supports a maximum of 16 concurrent query operations. Excess query requests need to be queued for processing.

- A proxy cannot be used to create a database. If a database needs to be created, the data provider must be started.


## How to Develop

The URI must be in the following format:

datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}?Proxy=true

For details about the development procedure and implementation, see [Sharing Data Using DataShareExtensionAbility](share-data-by-datashareextensionability.md).
