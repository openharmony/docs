# Distributed Data Object Overview

The distributed data object management framework provides object-oriented in-memory data management. It provides basic data management capabilities, such as creating, querying, deleting, and modifying distributed data objects, and observing data and status changes of the distributed data objects. This management framework also provides distributed capabilities to implement data object collaboration for the same application between multiple devices that form a Super Device.


## Basic Concepts

- **Distributed in-memory database**
  
  The distributed in-memory database caches data in the memory so that applications can quickly access data. This database, however, does not store data persistently. If the database is closed, the data is not retained.


- **Distributed data object**

  A distributed data object is an encapsulation of the JS object type. Each distributed data object instance creates a data table in the in-memory database. The in-memory databases created for different applications are isolated from each other. Reading data from and writing data to a distributed data object are mapped to the **get** and **put** operations in the corresponding database, respectively.

  The distributed data object can be in the following states in its lifecycle:

  - **Uninitialized**: The distributed data object is not instantiated or has been destroyed.
  - **Local**: The data table is created, but the data cannot be synchronized.
  - **Distributed**: The data table is created, and there are at least two online devices with the same session ID. In this case, data can be synchronized across devices. If a device is offline or the session ID is empty, the distributed data object changes to the local state.


## Working Principles

The distributed data objects are encapsulated into JS objects in distributed in-memory databases. This allows the distributed data objects to be operated in the same way as local variables. The system automatically implements cross-device data synchronization.

**Figure 1** Working mechanism

![how-distributedobject-works](figures/how-distributedobject-works.png)




## Constraints

- Data synchronization can be implemented across devices only for the applications with the same **bundleName**.

- Each distributed data object occupies 100 KB to 150 KB of memory. Therefore, you are advised not to create too many distributed data objects.

- The maximum size of a distributed data object is 500 KB.

- For the distributed data object of the complex type, only the root attribute can be modified. The subordinate attributes cannot be modified.
  
- Only JS APIs are supported.
