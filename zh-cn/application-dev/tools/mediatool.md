# mediatool工具

mediatool是一个轻量级的命令行工具集合，开发者可通过此工具操作媒体库资源。媒体库中的图片视频资源会在系统图库中显示。

## 前置条件

- 正常连接设备
- 系统设置中开启开发者模式
- 使用hdc shell进入命令行执行模式

## 命令行说明

<!--Del-->

### mediatool send
  
  ```shell
  mediatool send <path-to-local-media-file> [-ts] [-tas] [-rf] [-urf]
  ```
  该命令能够将设备```<path-to-local-media-file>```路径下的图片视频文件推入媒体库中保存。支持保存图片、视频和音频文件。文件在媒体库中会保留原有的名字。```<path-to-local-media-file>```可以为文件夹，mediatool会将文件夹里的所有文件置入媒体库中。保存成功后会打印成功置入的资源的uri。

  默认情况下，将媒体文件保存进媒体库是以同步方式创建缩略图，并且置入后```<path-to-local-media-file>```下的文件会被删除。
   | 选项               | 说明             |
  | ---- |--------------- |
  | -ts | 保存图片视频时以同步方式创建缩略图。能够保证缩略图正常生成之后图片视频才会显示，但是会导致保存耗时较长。（默认） |
  | -tas | 保存图片视频时以异步方式创建缩略图。不能与-ts选项同时使用。图片视频保存后会立即显示，不会等待缩略图先生成。保存耗时较短。 |
  | -rf | 媒体文件置入后删除源文件。（默认） |
  | -urf | 媒体文件置入后不删除源文件。不能与-rf选项同时使用。 |

  **使用示例：**
  ```shell
  > mediatool send /data/tmp/MyImage.jpg
  file://media/Photo/3/IMG_1721381297_001/MyImage.jpg # 推图成功，打印推入资源的uri
  ```

### mediatool list
  ```shell
  mediatool list <resource-uri>
  ```
  该命令能够将```<resource-uri>```指定uri对应的媒体库内资源信息以csv格式打印出来。
  例如媒体库内图片资源A的uri为file://media/Photo/3/IMG_1721381297_001/MyImage.jpg, ```mediatool list file://media/Photo/3```或者```mediatool list file://media/Photo/3/IMG_1721381297_001/MyImage.jpg```都能成功打印出该资源信息。

  所打印信息包含：
  - uri: 媒体资源的uri。
  - display_name: 媒体资源的名字。
  - data: 媒体资源的源文件在设备中的物理路径。

  还可以将```<resource-uri>```指定为```all```。```mediatool list all```会将媒体库内所有资源的信息打印出来。

  **使用示例：**
  ```shell
  # 使用存在的uri查询
  > mediatool list file://media/Photo/3
  Table Name: Photos
  uri, display_name, data
  "file://media/Photo/3/IMG_1721381297_001/MyImage.jpg", "MyImage.jpg", "/storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg"

  # 使用格式错误的uri查询
  > mediatool list file://media/Photo/
  [FAIL] uri invalid. uri:file://media/Photo/
  ```

### mediatool recv

```shell
mediatool recv <resource-uri> <dest-path>
```
该命令能够将```<resource-uri>```指定uri对应的媒体库资源的源文件内容导出到```<dest-path>```指定的设备路径下。```<dest-path>```可以指定为待创建文件路径或者文件夹路径，若为文件夹路径则会导出到该文件夹下，文件保留媒体库中的名字。当```<dest-path>```指定待创建文件路径时，不能是已经存在文件的路径。```<dest-path>```需要指定有权限访问的路径。文件导出成功后会打印导出文件的路径。

媒体库资源uri可以通过```mediatool list all```或者[mediatool query](#mediatool-query)获取。

将```<resource-uri>```指定为```all```则能够将所有媒体库资源的源文件导出。当```<resource-uri>```为```all```时，```<dest-path>```必须为文件夹路径。

```<dest-path>```只支持/data/local/tmp下的路径。

**使用示例：**
```shell
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg
```

### mediatool delete

```shell
mediatool delete <resource-uri>
```

该命令能够彻底删除```<resource-uri>```指定uri的媒体库资源。被删除的资源无法恢复，请谨慎执行。

媒体库资源uri可以通过```mediatool list all```或者[mediatool query](#mediatool-query)获取。

将```<resource-uri>```指定为```all```则指定删除所有媒体库资源，并重置媒体库的所有数据。

**使用示例：**
```shell
> mediatool delete file://media/Photo/3
[SUCCESS] delete success.

> mediatool delete all # delete all 执行成功不会有任何打印
```

<!--DelEnd-->

### mediatool query

```shell
mediatool query <display-name> [-p] [-u]
```
  该命令能够查询出所有名字为```<display-name>```的媒体库资源，返回资源源文件真实路径或媒体资源uri。默认返回源文件真实路径。

   | 选项               | 说明             |
  | ---- |--------------- |
  | -p | 返回媒体资源源文件在设备中的真实路径。（默认） |
  | -u | 返回媒体资源uri。不能与-p选项同时使用。 |

  **使用示例：**

  ```shell
  # 所查询媒体资源存在
  > mediatool query MyImage.jpg
  find 1 result:
  /storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

  # 所查询媒体资源不存在
  > mediatool query non_exist.jpg
  The displayName you want to query do not exist!
  find 0 result
  
  # 查询的名字格式不正确
  > mediatool query IMG_001
  The displayName format is not correct!

  # 查询媒体资源源文件路径
  > mediatool query MyImage.jpg -p
  find 1 result:
  /storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

  # 查询媒体资源uri
  > mediatool query MyImage.jpg -u
  find 1 result:
  uri
  "file://media/Photo/2/IMG_1721381297_001/MyImage.jpg"
  ```
