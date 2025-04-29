# Application Data Persistence Overview


The application data in the memory is persisted after being saved to a file or database on a device. The data in the memory is usually saved in the forms of data structs or data objects, and the data in storage media can be saved in the forms of text, binary file, or database file.


The OpenHarmony standard system supports typical data storage forms, including user preferences (**Preferences**), key-value databases (**KV-Store**), and relational databases (**RelationalStore**).


You can use proper data storage forms to implement data persistence:


- **Preferences**: used to store application configuration data. Data is stored as text files on a device. When the application is used, it loads all the data from the text file to the memory. **Preferences** allow fast and efficient data access, but are not suitable when a large amount of data needs to be stored.

- **KV-Store**: used to store data in KV pairs, in which the key uniquely identifies the data. A KV store is a kind of non-relational database. It is ideal for storing service data with few data and service relationships. It has been widely used because it poses fewer database version compatibility issues in distributed scenarios and simplifies conflict handling in data sync. KV databases feature higher cross-device and cross-version compatibility than relational databases.

- **RelationalStore**: used to store data in rows and columns. It is widely used to process relational data in applications. RelationalStore provides a set of APIs for adding, deleting, modifying, and querying data. You can also define and use SQL statements for complex service scenarios. **RelationalStore** also provides the vector store capabilities to calculate the similarity between vector data. It is applicable to recommendation scenarios, similar image retrieval, and natural language processing.

<!--Del-->
- **GraphStore**: Used to store and query graph data in vertexes and edges. It provides APIs for read, write, and transaction operations and can run customized GQL statements to meet the requirements of complex service scenarios. Compared with RDB stores, graph stores can process a large number of complex relational operations more efficiently. Common use cases include social network and relationship analysis, knowledge graph, and real-time recommendation systems.
<!--DelEnd-->
