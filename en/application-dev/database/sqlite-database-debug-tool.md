# SQLite Debugging Tool

SQLite is a lightweight, embedded, serverless relational database management system. Its core advantage is that the entire database is stored in a single file, without the need for an independent server process. It supports cross-platform operation and is widely used in mobile applications, embedded devices, and desktop software.

This debugging tool implements operations on the SQLite database based on the hdc command. It provides an efficient way to manage the SQLite database through the CLI, which is applicable to quick database operations and verification in the development, debugging, and O&M phases.

## Environment Requirements

- Before using this tool, you should enable the developer mode, obtain the hdc tool, and run **hdc shell**.
- The devices are properly connected.

## Preparations

Before using SQLite, switch to a directory that has read and write permissions.

```bash
# Open the hdc CLI.
c:/users/zzz>hdc shell
# cd data
# mkdir temp
# cd temp
# SQLite3
SQLiteversion 3.40.1 2022-12-28 14:03:47
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
```

If you attempt to create a database or table in a path that does not have read and write permissions, the system throws a permission error. 

Run the **CREATE TABLE** command in the SQL statement to create a table.

```bash
# Open the hdc CLI.
c:/users/zzz>hdc shell
# Open or create a database.
#SQLite3 a.db
SQLiteversion 3.40.1
2022-12-28 14:03:47
Enter ".help" for usage hints.
# Create a table.
SQLite>create table t1(a int);
Error:unable to open
```

When the preceding command is run, SQLite attempts to open or create the file. However, due to the lack of permissions, an error is reported:

```bash
Error:unable to open
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
| .schema         | Obtains complete information about a table.                       |
| .quit or .exit| Exits the SQLite CLI.                 |
| .schema [TABLE] | Displays the SQL statement for creating a table (or the structure of all tables).|

## Notes

- Semicolons are not required in SQLite commands. Unlike SQL statements, SQLite commands can be run by pressing the **Enter** key.
- Ensure that there is no space between the **SQLite>** prompt and the command. Otherwise, the command cannot be run.

## Command Usage and Examples

### Displaying All Commands and Descriptions

```SQLite
SQLite>.help
```
### Creating or Opening an Existing Database

- Open an existing database.

  If the database file already exists, you can run the **.open** command to open it.

  ```SQLite
  SQLite3          # Enter the SQLite shell.
  .open mydb.db    # Open the existing database in the shell.
  ```

  Alternatively, specify the file path in the command line.

  ```SQLite
  SQLite3 mydb.db  # Open the database directly.
  ```


- Create and open a database.

  If the specified database file does not exist, SQLite automatically creates one.

  ```SQLite
  SQLite3          # Enter the SQLite shell.
  .open newdb.db   # Create and open a database in the shell.
  ```

  Alternatively, create a database directly through a command.

  ```SQLite
  SQLite3 newdb.db # Create and open a database directly.
  ```

### Creating a Table

You can run the SQL statement **create table** to create a **COMPANY** table, set **ID** as the primary key, and set **NOT NULL** to ensure that the fields cannot be empty when records are created in the table.

```SQL
SQLite>create table COMPANY(
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
SQLite>.tables
COMPANY
```

After the **.tables** command is run, the created **COMPANY** table is listed. 

Run the SQLite command **.schema** to obtain the complete information about the table.

```SQLite
SQLite>.schema COMPANY
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
SQLite>DROP TABLE COMPANY;
```

After the command is run, the **COMPANY** table cannot be queried using the **.tables** command. If the command output is empty, the table is deleted successfully.

```SQLite
SQLite>.tables
```

### Inserting Data

- Enter the following SQL statement under the **SQLite>** prompt to insert a single data record:

  ```sql
  INSERT INTO COMPANY(name, age,) VALUES ('Zhang San', 25);
  ```

  Run **SELECT * FROM *Table name*** to obtain the complete information about the table.

  ```sql
  SQLite> SELECT * FROM COMPANY;
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  ```


- Run **INSERT INTO COMPANY (field) values ()** to insert multiple data records.

  ```sql
  SQLite> INSERT INTOCOMPANY(ID, NAME, AGE, ADDRESS, SALARY)
     ...> VALUES
     ...> (3, 'Wang Wu', 25, 'Tianhe District, Guangzhou', 18000.75),
     ...> (4, 'Zhao Liu', 40, 'Nanshan District, Shenzhen', 30000.25);
  ```

  Run **SELECT * FROM *Table name*** to obtain the complete information about the table.

  ```sql
  SQLite> SELECT * FROM COMPANY;
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

### Querying Data

Run the **SELECT** command in either of the following manners to query data:

- Run **SELECT * FROM *Table name*** to query all data.

  ```sql
  SQLite> SELECT * FROM COMPANY;
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

- Run **SELECT *specified field*, *specified field* FROM *Table name*** to query data of specified fields.

  ```sql
  SQLite> SELECT name, age FROM COMPANY;
  Zhang San|28
  Wang Wu|25
  Zhao Liu|40
  ```

- Run **SELECT * FROM *Table name* WHERE *Specified field* > 30;** to query the table by specified condition.

  ```sql
  SQLite> SELECT * FROM COMPANY WHERE age > 30;
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

- Run **SELECT * FROM *Table name* ORDER BY *Specified field* ASC;** to query data by specified field order.

  ```sql
  SQLite>SELECT * FROM COMPANY ORDER BY age ASC;
  3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
  1|Zhang San|28|Chaoyang District, Beijing|20000.5
  4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
  ```

### Updating Data

Run **UPDATE *Table name* SET age = 31 WHERE name = 'Zhang San';** after the **SQLite>** prompt to update a single data record.

```sql
SQLite>UPDATE COMPANY SET age = 31 WHERE name = 'Zhang San';
SQLite>SELECT * FROM COMPANY;
1|Zhang San|31|Chaoyang District, Beijing|20000.5
3|Wang Wu|25|Tianhe District, Guangzhou|18000.75
4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
```

### Deleting Data

Run **DELETE FROM *Table name* WHERE name = 'Wang Wu';** after the **SQLite>** prompt to delete data.

```sql
SQLite> DELETE FROM COMPANY WHERE name = 'Wang Wu';
SQLite> SELECT * FROM COMPANY;
1|Zhang San|28|Chaoyang District, Beijing|20000.5
4|Zhao Liu|40|Nanshan District, Shenzhen|30000.25
```

## References

The [SQLite website](https://SQLite.org/docs.html) provides rich sample code, including creating a database, creating a table, inserting data, and querying data.

## FAQs

### What Should I Do If the Query Result Is Empty?

In actual database operations, the query result may be empty because no data exists in the table.

To avoid this, you should ensure that related data is inserted to the table before running the query command.
