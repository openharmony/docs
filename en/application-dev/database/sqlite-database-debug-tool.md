# SQLite Debugging Tool
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @MyLinChi-->
<!--Designer: @csuxsh-->
<!--Tester: @zhujieliang-->
<!--Adviser: @ge-yafang-->

SQLite is a lightweight, embedded, serverless relational database management system. Its core advantage is that the entire database is stored in a single file, without the need for an independent server process. It supports cross-platform operation and is widely used in mobile applications, embedded devices, and desktop software.

This debugging tool implements operations on the SQLite database based on the hdc command. It provides an efficient way to manage the SQLite database through the CLI, which is applicable to quick database operations and verification in the development, debugging, and O&M phases.

## Environment Requirements

- Before using SQLite debugging tool, you should enable the [developer mode](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-developer-mode#section530763213432), obtain the [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc) tool, and run **hdc shell**.
- The devices are properly connected.

## Preparations

Before using SQLite, switch to the target application path and then run the command to access the SQLite debugging tool.

```bash
# Open the hdc CLI.
c:/users/zzz>hdc shell
$ cd /data/app/el1/100/base/com.test.myapplication   // Go to the target application path. (The current path is an example. Use the path based on your actual needs.)
$ ls -lZ                                             // Check the database files in the path. If a file is labeled with debug_hap_data_file, the file is the target application file.
total 9531
drwxrwsr-x 2 20020197 ddms o:object_r:debug_hap_data_file:s0:x229,x334,x512,x868,x1024     3440 2025-08-08 16:54 lock
-rw-rw---- 1 20020197 ddms o:object_r:debug_hap_data_file:s0:x229,x334,x512,x868,x1024  9228288 2025-08-08 16:55 rdbPerfTest.db
-rw-rw---- 1 20020197 ddms o:object_r:debug_hap_data_file:s0:x229,x334,x512,x868,x1024      343 2025-08-08 16:54 rdbPerfTest.db-compare
-rw-rw---- 1 20020197 ddms o:object_r:debug_hap_data_file:s0:x229,x334,x512,x868,x1024    12288 2025-08-08 16:55 rdbPerfTest.db-dwr
-rw-rw---- 1 20020197 ddms o:object_r:debug_hap_data_file:s0:x229,x334,x512,x868,x1024    32768 2025-08-08 16:55 rdbPerfTest.db-shm
-rw-rw---- 1 20020197 ddms o:object_r:debug_hap_data_file:s0:x229,x334,x512,x868,x1024   444992 2025-08-08 16:55 rdbPerfTest.db-wal
$ sqlite3 rdbPerfTest.db                             // Open the database file.
SQLite version 3.44.4 2025-02-19 00:18:53
Enter ".help" for usage hints.
sqlite>
```

If you create a database and table in the path of a non-target application, the system throws a permission error. 

Run the **CREATE TABLE** command in the SQL statement to create a table.

```bash
# Open the hdc CLI.
c:/users/zzz>hdc shell
# Open or create a database.
$ sqlite3 a.db
SQLite version 3.44.4 2025-02-19 00:18:53
Enter ".help" for usage hints.
# Create a table.
sqlite>create table t1(a int);
Error: unable to open database "a.db": unable to open database file
# Open the asd.db database.
sqlite> .open asd.db
Error: unable to open database "asd.db": unable to open database file
Notice: using substitute in-memory database instead of "asd.db"
```

When the preceding command is run, SQLite attempts to open or create a table and the asd.db database. However, the following error is reported due to insufficient permission:

```bash
# Create a table.
sqlite>create table t1(a int);
Error: unable to open database "a.db": unable to open database file
# Open the asd.db database.
sqlite> .open asd.db
Error: unable to open database "asd.db": unable to open database file
Notice: using substitute in-memory database instead of "asd.db"
```
After SQLite accesses the encryption database, the following error information is displayed:
```sqlite
# sqlite3 ./wallet_personal_info_data_relational_store
SQLite version 3.44.4 2025-02-19 00:18:53
Enter ".help" for usage hints.
sqlite> select * from sqlite_master;
Parse error: file is not a database (26)
sqlite> .table
Error: file is not a database
sqlite> .q
```

## Command List

The following table lists the commands supported by the SQLite debugging tool.

| Command              | Description                               |
| ------------------ | --------------------------------------- |
| .help           | Displays all available SQLite commands and brief descriptions.   |
| .open *database name*| Opens or creates a database.             |
| .databases      | Lists all connected databases.             |
| .tables         | Lists all tables in a database.             |
| .show          | Displays the default settings of the SQLite command prompt.       |
| .schema         | Obtains complete information about a table.                    |
| .quit or .exit| Exits the SQLite CLI.                 |
| .schema [TABLE] | Displays the SQL statement for creating a table (or the structure of all tables).|

## Notes

- Semicolons are not required in SQLite commands. Unlike SQL statements, SQLite commands can be run by pressing the **Enter** key.
- Ensure that there is no space between the **sqlite>** prompt and the command. Otherwise, the command cannot be run.

## Command Usage and Examples

### Displaying All Commands and Descriptions

```SQLite
sqlite>.help
```
### Creating or Opening an Existing Database

- Open an existing database.

  If the database file already exists, you can run the **.open** command to open it.

  ```SQLite
  sqlite3                                                        # Enter the SQLite interactive shell.
  .open /data/app/el1/100/base/com.test.myapplication/mydb.db    # Open an existing database in the shell.
  ```

  Alternatively, specify the file path in the command line.

  ```SQLite
  sqlite3 /data/app/el1/100/base/com.test.myapplication/mydb.db # Open a database without accessing to the shell.
  ```


- Create and open a database.

  If the specified database file does not exist, SQLite automatically creates one.

  ```SQLite
  sqlite3                                                        # Access to the SQLite shell.
  .open /data/app/el1/100/base/com.test.myapplication/newdb.db    # Open an existing database in the shell.
  ```

  Alternatively, create a database directly through a command.

  ```SQLite
  sqlite3 /data/app/el1/100/base/com.test.myapplication/newdb.db # Create and open a database without accessing to the shell.
  ```

### Creating a Table

You can run the SQL statement **create table** to create a **COMPANY** table, set **ID** as the primary key, and set **NOT NULL** to ensure that the fields cannot be empty when records are created in the table.

```SQL
sqlite>create table COMPANY(
   ID INT PRIMARY KEY     NOT NULL,
   NAME           TEXT    NOT NULL,
   AGE            INT     NOT NULL,
   ADDRESS        CHAR(50),
   SALARY         REAL
);
```

### Querying a Table

Run the SQLite command **.tables** to check whether the table is created. This command is used to list all tables in a database.

```SQLite
sqlite>.tables
COMPANY
```

After the **.tables** command is run, the created **COMPANY** table is listed. 

Run the SQLite command **.schema** to obtain the complete information about the table.

```SQLite
sqlite>.schema COMPANY
CREATE TABLE COMPANY(
   ID INT PRIMARY KEY     NOT NULL,
   NAME           TEXT    NOT NULL,
   AGE            INT     NOT NULL,
   ADDRESS        CHAR(50),
   SALARY         REAL
);
```

### Deleting a Table

The SQL statement **DROP TABLE** is used to delete a table definition and all associated data, indexes, triggers, constraints, and permission specifications.

For example, if the **COMPANY** table already exists in the database, you can run the following command to delete it:

```SQLite
sqlite>DROP TABLE COMPANY;
```

After the command is run, the **COMPANY** table cannot be queried using the **.tables** command. If the command output is empty, the table is deleted successfully.

```SQLite
sqlite>.tables
```

### Inserting Data

- Enter the following SQL statement under the **sqlite>** prompt to insert a single data record:

  ```sql
  INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) VALUES (1, 'Zhang San', 28, 'Chaoyang District, Beijing', 20000.5);
  ```

  Run **SELECT * FROM *table name*** to obtain the complete information about the table.

  ```sql
  sqlite> SELECT * FROM COMPANY;
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  ```


- Run **INSERT INTO COMPANY (*fields*) values()** to insert multiple data records.

  ```sql
  sqlite> INSERT INTO COMPANY(ID, NAME, AGE, ADDRESS, SALARY)
     ...> VALUES
     ...> (3, 'Wang Wu', 25, 'Tianhe District, Guangzhou', 18000.75),
     ...> (4, 'Zhao Liu', 40, 'Nanshan District, Shenzhen', 30000.25);
  ```

  Run **SELECT * FROM *table name*** to query all data.

  ```sql
  sqlite> SELECT * FROM COMPANY;
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

### Querying Data

Run the **sqlite> SELECT** command in either of the following manners to query data:

- Run **SELECT * FROM *table name*** to query all data.

  ```sql
  sqlite> SELECT * FROM COMPANY;
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

- Run **SELECT *specified field*, *specified field* FROM *table name*** to query data of specified fields.

  ```sql
  sqlite> SELECT name, age FROM COMPANY;
  Zhang San|28
  Wang Wu|25
  Zhao Liu|40
  ```

- Run **SELECT * FROM *table name* WHERE *specified field* > 30;** to query the table by specified condition.

  ```sql
  sqlite> SELECT * FROM COMPANY WHERE age > 30;
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

- Run **SELECT * FROM *table name* ORDER BY *specified field* ASC;** to query data by specified field order.

  ```sql
  sqlite>SELECT * FROM COMPANY ORDER BY age ASC;
  3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

### Updating Data

Run **UPDATE *table name* SET age = 31 WHERE name = 'Zhang San';** after the **SQLite>** prompt to update a single data record.

```sql
sqlite>UPDATE COMPANY SET age = 31 WHERE name = 'Zhang San';
sqlite>SELECT * FROM COMPANY;
1|Zhang San|31|Chaoyang District, Beijing|20000.5
3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
```

### Deleting Data

Run **DELETE FROM *table name* WHERE name = 'Wang Wu';** after the **sqlite>** prompt to delete data.

```sql
sqlite> DELETE FROM COMPANY WHERE name = 'Wang Wu';
sqlite> SELECT * FROM COMPANY;
1|Zhang San|28|Chaoyang District, Beijing|20000.5
4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
```

## References

The [SQLite website](https://SQLite.org/docs.html) provides rich sample code, including creating a database, creating a table, inserting data, and querying data.

## FAQs

### What should I do if the query result is empty?

In actual database operations, the query result may be empty because no data exists in the table.

To avoid this, you should ensure that related data is inserted to the table before running the query command.

### How do I delete characters?
You can press **Ctrl+Backspace** to delete a single character and press **Ctrl+U** to delete all characters.
