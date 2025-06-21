# mediatool工具

mediatool是一个轻量级的命令行工具集合，开发者可通过此工具操作媒体库资源。媒体库为图库提供和管理数据，媒体库中的图片视频会在图库界面呈现。

mediatool工具为系统自带工具，不需要安装，内置在/bin文件夹中，可以通过hdc shell直接调用。

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

该命令能够将设备`<path-to-local-media-file>`路径下的图片视频文件推入媒体库中保存。支持保存图片、视频和音频文件。文件在媒体库中会保留原有的名字。`<path-to-local-media-file>`可以为文件夹，mediatool会将文件夹里的所有文件置入媒体库中。保存成功后会打印成功置入的资源的uri。

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

该命令能够将`<resource-uri>`指定uri对应的媒体库内资源信息以csv格式打印出来。
例如媒体库内图片资源A的uri为file://media/Photo/3/IMG_1721381297_001/MyImage.jpg, `mediatool list file://media/Photo/3`或者`mediatool list file://media/Photo/3/IMG_1721381297_001/MyImage.jpg`都能成功打印出该资源信息。

所打印信息包含：

- uri: 媒体资源的uri。
- display_name: 媒体资源的名字。
- data: 媒体资源的源文件在设备中的物理路径。

还可以将`<resource-uri>`指定为`all`。`mediatool list all`会将媒体库内所有资源的信息打印出来。

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

<!--DelEnd-->

### mediatool recv

```shell
mediatool recv <media-target> <dest-path>
```

该命令能够将`<media-target>`指定的媒体库资源的源文件内容导出到`<dest-path>`指定的设备路径下。

`<media-target>`可以为以下两种形式：
* 系统媒体目录下的文件路径。（可通过[mediatool ls -l](#mediatool-ls--l)获取。不支持指定文件夹路径。）
* 媒体库uri。（参考[媒体库uri介绍/获取方式](#媒体库uri介绍获取方式)）

如果`<media-target>`指定文件路径，只支持以下几种路径，以下几种路径存在映射关系，访问的目录相同，均访问当前用户的系统媒体目录：
* /storage/media/local/files/Photo 及以下的文件路径。
* /storage/media/\<uid\>/local/files/Photo 及以下的文件路径。\<uid\>必须为当前用户的id，否则报错路径不合法。

`<dest-path>`为待创建文件路径或者文件夹路径。若为文件夹路径则会导出到该文件夹下，文件保留媒体库中的名字。当`<dest-path>`指定待创建文件路径时，不能是已经存在文件的路径。<!--Del-->`<dest-path>`需要指定有权限访问的路径。<!--DelEnd--><!--RP1--><!--RP1End-->

文件导出成功后会打印导出文件的路径。

将`<media-target>`指定为`all`则能够将所有媒体库资源的源文件导出。当`<media-target>`为`all`时，`<dest-path>`必须为文件夹路径。

该命令无法导出隐藏相册内的媒体资产。

**使用示例：**

```shell
# 使用uri将对应媒体资源导出
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

# 使用路径将对应媒体资源导出
> mediatool recv /storage/media/local/files/Photo/16/IMG_1748435796_000.jpg /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

# 导出所有媒体资源文件
> mkdir /data/local/tmp/outmedia
> mediatool recv all /data/local/tmp/outmedia
Table Name: Photos
/data/local/tmp/outmedia/IMG_20250528_203454.jpg
/data/local/tmp/outmedia/IMG_20250528_221028.jpg
/data/local/tmp/outmedia/IMG_20250528_221851.jpg
/data/local/tmp/outmedia/IMG_20250528_221930.jpg
/data/local/tmp/outmedia/IMG_20250528_221944.jpg
...

Table Name: Audios

```

### mediatool delete

```shell
mediatool delete <resource-uri>
```

该命令能够彻底删除`<resource-uri>`指定uri的媒体库资源。被删除的资源无法恢复，请谨慎执行。

媒体库资源uri的获取可参考[媒体库uri介绍/获取方式](#媒体库uri介绍获取方式)。

将`<resource-uri>`指定为`all`则指定删除所有媒体库资源，并重置媒体库的所有数据。

**使用示例：**

```shell
> mediatool delete file://media/Photo/3
[SUCCESS] delete success.

> mediatool delete all # delete all 执行成功不会有任何打印
```

### mediatool query

```shell
mediatool query <display-name> [-p] [-u]
```

该命令能够查询出所有图库中显示名字为`<display-name>`的媒体库资源，返回资源源文件真实路径或媒体资源uri。默认返回源文件真实路径。

该命令无法查询出隐藏相册内的媒体资产。

  | 选项               | 说明             |
| ---- |--------------- |
| -p | 返回媒体资源源文件在设备中的真实路径。（默认） |
| -u | 返回媒体资源uri。不能与-p选项同时使用。 |

**使用示例：**

```shell
# 所查询媒体资源存在
> mediatool query MyImage.jpg
find 1 result:
path
/storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

# 所查询媒体资源不存在
> mediatool query non_exist.jpg
find 0 result

# 查询的名字格式不正确
> mediatool query IMG_001
find 0 result
The displayName format is not correct!

# 查询媒体资源源文件路径
> mediatool query MyImage.jpg -p
find 1 result:
path
/storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

# 查询媒体资源uri
> mediatool query MyImage.jpg -u
find 1 result:
uri
"file://media/Photo/2/IMG_1721381297_001/MyImage.jpg"
```

### mediatool ls -l

```shell
mediatool ls -l <media-path>
```

列举出`<media-path>`所指定的系统媒体路径下的所有文件。效果类似文件系统`ls -l`。

`<media-path>`只支持以下几种路径，以下几种路径存在映射关系，访问的目录相同，均访问当前用户的系统媒体目录：

* /storage/media/local/files/Photo 及以下的路径。
* /storage/media/\<uid\>/local/files/Photo 及以下的路径。\<uid\>必须为当前用户的id，否则报错路径不合法。

`-l`为强制选项。不指定`-l`选项命令会报错。

该命令不可见用户隐藏相册内的媒体资产。

**使用示例：**

```shell
> mediatool ls -l /storage/media/local/files/Photo
drwxrwx--x 2 user_data_rw user_data_rw 3440 2025-05-29 05:45 16
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:45 1
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 11:15 2
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:56 3
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:56 4
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 11:21 5
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 11:59 6
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:57 7
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:59 8
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 06:00 9
```

## 使用指导

以下使用指导说明了一些常见的mediatool使用场景。

### 导出特定媒体库资产

示例导出图库中名字叫MyImage的jpg图片：

```shell
> hdc shell mediatool query -u MyImage.jpg
find 1 result
uri
"file://media/Photo/1/IMG_1743078145_000/MyImage.jpg"

> hdc shell mediatool recv file://media/Photo/1 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

> hdc file recv /data/local/tmp/out.jpg .
FileTransfer finish, Size:10015455, File count = 1, time:679ms rate:14750.30kB/s
```

示例根据媒体文件路径导出媒体库资产：

```shell
> hdc shell mediatool ls -l /storage/media/local/files/Photo
drwxrwx--x 2 user_data_rw user_data_rw 3440 2025-05-29 05:45 16
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:45 1
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 11:15 2
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:56 3
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 05:56 4
drwxrwx--x 2 user_data_rw user_data_rw 0 2025-05-29 11:21 5

> hdc shell mediatool ls -l /storage/media/local/files/Photo/16
-rw-rw---- 1 user_data_rw user_data_rw 6107481 2025-05-28 20:34 IMG_1748435794_000.jpg
-rw-rw---- 1 user_data_rw user_data_rw 839323 2025-05-28 23:06 IMG_1748444892_016.jpg
-rw-rw---- 1 user_data_rw user_data_rw 9614937 2025-05-28 23:41 IMG_1748446677_032.jpg
-rw-rw---- 1 user_data_rw user_data_rw 3004885 2025-05-29 00:43 IMG_1748450699_048.jpg
-rw-rw---- 1 user_data_rw user_data_rw 1915961 2025-05-29 01:18 IMG_1748452814_064.jpg
-rw-rw---- 1 user_data_rw user_data_rw 13078 2025-05-29 02:41 IMG_1748457806_080.jpeg

> hdc shell mediatool recv /storage/media/local/files/Photo/16/IMG_1748435794_000.jpg /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

> hdc file recv /data/local/tmp/out.jpg .
FileTransfer finish, Size:10015455, File count = 1, time:679ms rate:14750.30kB/s
```

### 导出所有媒体库资产

```shell
> hdc shell mkdir /data/local/tmp/media
> hdc shell mediatool recv all /data/local/tmp/media
Table Name: Photos
/data/local/tmp/media/MyImage.jpg

Table Name: Audios

> hdc shell tar -cvf /data/local/tmp/media.tar /data/local/tmp/media/*
removing leading '/' from member names
data/local/tmp/media/MyImage.jpg

> hdc file recv /data/local/tmp/media.tar .
FileTransfer finish, Size:10017280, File count = 1, time:664ms rate:15086.27kB/s
```

### 删除特定媒体库资产

示例删除图库中名字叫MyImage的jpg图片：

```shell
> hdc shell mediatool query -u MyImage.jpg
find 1 result
uri
"file://media/Photo/1/IMG_1743078145_000/MyImage.jpg"

> hdc shell mediatool delete file://media/Photo/1/IMG_1743078145_000/MyImage.jpg
[SUCCESS] delete success.
```

### 彻底重置媒体库数据库
```shell
> hdc shell mediatool delete all
```

## 媒体库uri介绍/获取方式

uri是媒体库资产的唯一标识符，每个uri都对应一个媒体资产。mediatool使用uri来判断需要操作的媒体资产对象。

可使用以下方式获取uri：
* mediatool query 加上 -u 的选项可以返回对应媒体资产的uri。需要输入对应资产的显示名（在图库中展示的名字带后缀名）。
<!--Del-->
* mediatool list all可以获取到所有媒体库资产的uri列表，以及对应的资产的显示名。
<!--DelEnd-->

媒体库uri可以用于mediatool recv命令导出特定媒体库资产，也可以用于mediatool delete删除特定媒体库资产。

uri样例：`file://media/Photo/1/IMG_1743078145_000/MyImage.jpg`。
在mediatool操作中，需要使用以上uri时，无论使用`file://media/Photo/1/IMG_1743078145_000/MyImage.jpg`还是`file://media/Photo/1`都能够正确的定位到目标资产。