# Lightweight Data Store Overview<a name="EN-US_TOPIC_0000001230752103"></a>

Lightweight data store is applicable to access and persistence operations on the data in key-value pairs. When an application accesses a lightweight  **Storage**  instance, data in the  **Storage**  instance will be cached in the memory for faster access. The cached data can also be written back to the text file for persistent storage. Since file read and write consume system resources, you are advised to minimize the frequency of reading and writing persistent files.

## Basic Concepts<a name="section1055404171115"></a>

-   **Key-Value data structure**

    A type of data structure. The key is the unique identifier for a piece of data, and the value is the specific data being identified.

-   **Non-relational database**

    A database not in compliance with the atomicity, consistency, isolation, and durability \(ACID\) database management properties of relational data transactions. The data in a non-relational database is independent.


## Working Principles<a name="section682631371115"></a>

1.  When an application loads data from a specified  **Storage**  file to a  **Storage**  instance, the system stores the instance in the memory through a static container. Each file of an application or process has only one  **Storage**  instance in the memory, till the application removes the instance from the memory or deletes the  **Storage**  file.
2.  When obtaining a  **Storage**  instance, the application can read data from or write data to the instance. The data in the  **Storage**  instance can be flushed to its  **Storage**  file by calling the  **flush**  or  **flushSync**  method.

**Figure  1**  How lightweight data store works<a name="fig1657785713509"></a>  


![](figures/en-us_image_0000001199139454.png)

## Constraints<a name="section17243172883219"></a>

-   **Storage**  instances are loaded to the memory. To minimize non-memory overhead, the number of data records stored in a  **Storage**  instance cannot exceed 10,000. Delete the instances that are no longer used in a timely manner.
-   The key in the key-value pairs is of the string type. It cannot be empty or exceed 80 characters.
-   If the value in the key-value pairs is of the string type, it can be empty or contain a maximum of 8192 characters.

