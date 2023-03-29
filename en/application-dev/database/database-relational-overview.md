# RDB Overview

A relational database (RDB) store manages data based on relational models. With the underlying SQLite database, the RDB store provides a complete mechanism for managing data as in a local database. To satisfy different needs in complicated scenarios, the RDB store offers APIs for performing operations, such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements. After an application is uninstalled, the related RDB store will be automatically deleted.

You do not need to care about the implementation of the database locking mechanism.

## Basic Concepts

- **RDB store**

  A type of database created on the basis of relational models. A RDB store holds data in rows and columns.

- **Predicate**

  A representation of the property or feature of a data entity, or the relationship between data entities. Predicates are used to define operation conditions.

- **Result set**

  A set of query results used to access data. You can access the required data in a result set in flexible modes.

- **SQLite database**

  A lightweight open-source relational database management system that complies with Atomicity, Consistency, Isolation, and Durability (ACID).

## Working Principles

The RDB store provides common operation APIs for external systems. It uses the SQLite as the underlying persistent storage engine, which supports all SQLite database features.

**Figure 1** Working mechanism

![how-rdb-works](figures/how-rdb-works.png)

## Default Settings

- The default RDB logging mode is Write Ahead Log (WAL).
- The default data flushing mode is **FULL** mode.
- The default size of the shared memory used by an OpenHarmony database is 2 MB.

## Constraints

- An RDB store can be connected to a maximum of four connection pools to manage read and write operations.

- To ensure data accuracy, the RDB store supports only one write operation at a time.
