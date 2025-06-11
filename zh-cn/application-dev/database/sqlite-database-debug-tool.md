# SQLite调试工具指导

SQLite是一款轻量级、嵌入式、无服务器的关系型数据库管理系统，其核心优势在于将整个数据库存储于单一文件中，无需独立服务器进程，支持跨平台运行，被广泛应用于移动应用、嵌入式设备和桌面软件等场景。

本调试工具基于HDC命令实现对SQLite数据库的操作，提供一种通过命令行接口高效管理SQLite数据库的方式，适用于开发、调试和运维阶段对数据库的快速操作与验证。

## 环境要求

- 开发者在使用本工具前需开启开发者模式，且需要获取HDC工具，执行HDC shell。
- 正常连接设备。

## 操作准备

在使用SQLite之前需先切换至具备读写权限的目录。

```bash
# 打开 HDC 命令行
c:/users/zzz>hdc shell
# cd data
# mkdir temp
# cd temp
# SQLite3
SQLite version 3.40.1 2022-12-28 14:03:47
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
```

当在不具备读写权限的路径下尝试执行数据库和表的创建操作时，系统将抛出权限错误。  

使用SQL语句中的`CREATE TABLE`命令创建表，具体如下：

```bash
# 打开 HDC 命令行
c:/users/zzz>hdc shell
# 尝试打开或创建新的数据库
#SQLite3 a.db
SQLiteversion 3.40.1
2022-12-28 14:03:47
Enter ".help" for usage hints.
# 创建表
SQLite>create table t1(a int);
Error:unable to open
```

执行上述命令时，SQLite会尝试打开或创建该文件，但由于没有权限，会出现类似如下的错误信息：

```bash
Error:unable to open
```

## 命令列表

当前SQLite调试工具支持的命令如下表所示：

| 命令               | 功能描述                                |
| ------------------ | --------------------------------------- |
| `.help`            | 显示所有可用的SQLite命令及简要说明。    |
| `.open 数据库名称` | 打开或创建一个数据库文件。              |
| `.databases`       | 列出当前连接的所有数据库。              |
| `.tables`          | 列出当前数据库中的所有表。              |
| ` .show`           | 查看SQLite命令提示符的默认设置。        |
| `.schema`          | 获取表的完整信息                        |
| `.quit` 或 `.exit` | 退出SQLite命令行界面。                  |
| `.schema [TABLE]`  | 显示表的创建SQL语句（或所有表的结构）。 |

## 注意事项

- SQLite命令不需要分号：与SQL语句不同，SQLite命令直接回车执行，无需添加分号。
- 需确保`SQLite>`提示符与命令之间不存在空格，否则将导致命令无法正常执行。

## 命令的具体使用及示例

### 帮助命令（.help）

```SQLite
SQLite>.help
```
### 创建或打开已有的数据库

- 打开已有数据库

  若数据库文件已存在，可通过`.open`打开：

  ```SQLite
  SQLite3          # 进入SQLite交互式Shell
  .open mydb.db    # 在Shell内打开已有数据库
  ```

  或直接在命令行指定文件路径：

  ```SQLite
  SQLite3 mydb.db  # 直接打开数据库（跳过进入Shell步骤）
  ```


- 创建并打开新数据库	

  若指定的数据库文件不存在，SQLite将自动创建该文件：

  ```SQLite
  SQLite3          # 进入SQLite Shell
  .open newdb.db   # 在Shell内创建并打开新数据库
  ```

  或直接通过命令行创建：

  ```SQLite
  SQLite3 newdb.db  # 直接创建并打开新数据库
  ```

### 创建表

可通过SQL语句`create table`创建COMPANY表，将ID设置为主键，NOT NULL约束表示在表中创建记录时这些字段不可为空：

```SQL
SQLite>create table COMPANY(
   ID INT PRIMARY KEY     NOT NULL,
   NAME           TEXT    NOT NULL,
   AGE            INT     NOT NULL,
   ADDRESS        CHAR(50),
   SALARY         REAL
);
```

### 查询表

通过SQLite命令`.tables`命令验证表是否创建成功，该命令用于列出附加数据库中的所有表。

```SQLite
SQLite>.tables
COMPANY
```

在此处可查看到刚创建的表COMPANY。  

通过SQLite命令`.schema`命令可获取表的完整信息，具体如下：

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

### 删除表

SQL语句`DROP TABLE`语句用于删除表定义及其关联的所有数据、索引、触发器、约束和权限规范。

示例：若数据库中已存在 `COMPANY` 表，可通过以下操作将其删除：

```SQLite
SQLite>DROP TABLE COMPANY;
```

执行后，使用 `.tables` 命令将无法查询到 `COMPANY` 表，显示结果为空即表示删除成功。

```SQLite
SQLite>.tables
```

### 插入数据

- 在 SQLite> 提示符下，输入以下SQL语句插入单条数据：

  ```sql
  INSERT INTOCOMPANY(name, age,) VALUES ('张三', 25);
  ```

  通过SQL语句`SELECT * FROM 表的名称`可获取表的完整信息，具体如下：

  ```sql
  SQLite> SELECT * FROM COMPANY;
  1|张三|28|北京市朝阳区|20000.5
  ```


- 输入以下SQL语句`INSERT INTOCOMPANY(字段)values()`语句插入多条数据：

  ```sql
  SQLite> INSERT INTOCOMPANY(ID, NAME, AGE, ADDRESS, SALARY)
     ...> VALUES
     ...> (3, '王五', 25, '广州市天河区', 18000.75),
     ...> (4, '赵六', 40, '深圳市南山区', 30000.25);
  ```

  通过SQL语句`SELECT * FROM 表的名称`可获取表的完整信息，具体如下：

  ```sql
  SQLite> SELECT * FROM COMPANY;
  1|张三|28|北京市朝阳区|20000.5
  3|王五|25|广州市天河区|18000.75
  4|赵六|40|深圳市南山区|30000.25
  ```

### 查询数据

在SQLite>提示符下,可通过` SELECT`查询数据，支持以下几种数据查询：

- 可通过SQL语句`SELECT * FROM 表的名称`查询所有数据

  ```sql
  SQLite> SELECT * FROM COMPANY;
  1|张三|28|北京市朝阳区|20000.5
  3|王五|25|广州市天河区|18000.75
  4|赵六|40|深圳市南山区|30000.25
  ```

- 可通过SQL语句`SELECT 指定字段, 指定字段 FROM 表的名称`查询指定字段的数据

  ```sql
  SQLite> SELECT name, age FROM COMPANY;
  张三|28
  王五|25
  赵六|40
  ```

- 可通过SQL语句`SELECT * FROM 表的名称 WHERE 指定字段 > 30;`指定条件查询

  ```sql
  SQLite> SELECT * FROM COMPANY WHERE age > 30;
  4|赵六|40|深圳市南山区|30000.25
  ```

- 可通过SQL语句`SELECT * FROM 表的名称 ORDER BY 指定字段 ASC;`指定字段排序查询

  ```sql
  SQLite>SELECT * FROM COMPANY ORDER BY age ASC;
  3|王五|25|广州市天河区|18000.75
  1|张三|28|北京市朝阳区|20000.5
  4|赵六|40|深圳市南山区|30000.25
  ```

### 更新数据

在SQLite>提示符下，可通过SQL语句`UPDATE 表名称 SET age = 31 WHERE name = '张三';`语句插入单条数据

```sql
SQLite>UPDATE COMPANY SET age = 31 WHERE name = '张三';
SQLite>SELECT * FROM COMPANY;
1|张三|31|北京市朝阳区|20000.5
3|王五|25|广州市天河区|18000.75
4|赵六|40|深圳市南山区|30000.25
```

### 删除数据

在SQLite>提示符下，可通过SQL语句`DELETE FROM 表名称 WHERE name = '王五';`语句删除数据

```sql
SQLite> DELETE FROM COMPANY WHERE name = '王五';
SQLite> SELECT * FROM COMPANY;
1|张三|28|北京市朝阳区|20000.5
4|赵六|40|深圳市南山区|30000.25
```

## 相关参考

[SQLite官方网站](https://SQLite.org/docs.html)提供了丰富的示例代码，包括创建数据库、创建表、插入数据和查询数据等操作，开发者可以进行参考和查看。

## 常见问题

### 查询结果为空时的问题处理

在实际的数据库操作中，有时会遇到查询结果为空的情况，这是因为表中没有数据。

为了避免这种情况，需确保已在表中插入相关数据，再进行查询操作。
