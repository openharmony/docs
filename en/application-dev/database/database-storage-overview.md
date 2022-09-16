# Lightweight Data Store Overview

The lightweight data store is applicable to access and persistence of data in the key-value structure.

After an application obtains a lightweight store instance, the data in the instance will be cached in the memory for faster access. The cached data can also be written back to the text file for persistent storage. Since file read and write consume system resources, you are advised to minimize the frequency of reading and writing persistent files.

You do not need to care about the implementation of the database lock mechanism.

## Basic Concepts

- **Key-value structure**

  A type of data structure. The key is the unique identifier for a piece of data, and the value is the specific data being identified.

- **Non-relational database**

  A database not in compliance with the atomicity, consistency, isolation, and durability (ACID) properties of relational data transactions. The data in a non-relational database is independent.

## Working Principles

1. An application can load data from a specified **Storage** file to a **Storage** instance. The system stores the instance in the memory through a static container. Each file of an application or process has only one **Storage** instance in the memory, till the application removes the instance from the memory or deletes the **Storage** file.
2. When obtaining a **Storage** instance, the application can read data from or write data to the instance. The data in the **Storage** instance can be flushed to its **Storage** file by calling the **flush** or **flushSync** method.

**Figure 1** Working mechanism

![](figures/en-us_image_0000001199139454.png)

## Constraints

- **Storage** instances are loaded to the memory. To minimize non-memory overhead, the number of data records stored in a **Storage** instance cannot exceed 10,000. Delete the instances that are no longer used in a timely manner.
- The key in the key-value pairs is of the string type. It cannot be empty or exceed 80 bytes.
- The value of the string type can be empty, but cannot exceed 8192 bytes if not empty.
