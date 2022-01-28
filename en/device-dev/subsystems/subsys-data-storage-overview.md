# Lightweight Data Store Overview

The lightweight data store is applicable to access and persistence operations on the data in key-value pairs. When an application accesses a lightweight store instance, the data in the instance will be cached in the memory for faster access. The cached data can also be written back to the text file for persistent storage. Since file read and write consume system resources, you are advised to minimize the frequency of reading and writing persistent files.

## Basic Concepts

-   **Key-Value data structure**

    A type of data structure. The key is the unique identifier for a piece of data, and the value is the specific data being identified.

-   **Non-relational databases**

    A database not in compliance with the atomicity, consistency, isolation, and durability (ACID) database management properties of relational data transactions. The data in a non-relational database is independent.


## Working Principles

When an application loads data from a specified Preferences file to a **Preferences** instance, the system stores the instance in the memory through a static container. Each file of an application or process has only one **Preferences** instance in the memory, till the application removes the instance from the memory or deletes the **Preferences** file.

When obtaining a **Preferences** instance, the application can read data from or write data to the instance. The data in the instance can be flushed to its **Preferences** file by calling the **flush()** or **flushSync()** method.

**Figure 1** How lightweight data store works<a name="fig1657785713509"></a>


![](figure/en-us_image_0000001192123772.png)

## Constraints

-   **Preferences** instances are loaded to the memory. To minimize non-memory overhead, the number of data records stored in a Preferences instance cannot exceed 10,000. Delete the instances that are no longer used in a timely manner.
-   The key in the key-value pairs is of the string type. It cannot be empty or exceed 80 characters.
-   If the value in the key-value pairs is of the string type, it can be empty or contain a maximum of 8192 characters.
