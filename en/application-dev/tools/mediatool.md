# mediatool

mediatool is a lightweight collection of command line utilities, by which you can manage media assets The media library provides and manages data for the gallery. Images and videos in the media library are displayed on the gallery screen.

The mediatool is a built-in tool of the system and does not need to be installed. It is stored in the /bin folder and can be called by the hdc shell.

## Prerequisites

- The device is connected properly.
- The developer mode is enabled.
- You have run the **hdc shell** command to enter the command line execution mode.

## Commands

<!--Del-->

### mediatool send
  
```shell
mediatool send <path-to-local-media-file> [-ts] [-tas] [-rf] [-urf]
```

Sends images, audios, and videos in **\<path-to-local-media-file>** of the device to the media library for storage.  The original file names are used. If **\<path-to-local-media-file>** indicates a folder, all files in the folder are sent to the media library. After a file is successfully saved, the URI of the file is displayed.

By default, a thumbnail is generated in synchronous mode when a media file is being saved to the media library, and the source file in **\<path-to-local-media-file>** is deleted once the saving process is complete.

  | Parameter              | Description            |
| ---- |--------------- |
| -ts | Creates a thumbnail in synchronous mode when an image or a video is being saved. The media file is displayed after the thumbnail is generated. However, the saving takes a longer time. This parameter is used by default.|
| -tas | Creates a thumbnail in asynchronous mode when an image or a video is being saved. This parameter conflicts with **-ts**. The media file is displayed before the thumbnail is generated, and the saving takes a shorter time.|
| -rf | Deletes the source file after a media file is saved. This parameter is used by default.|
| -urf | Retains the source file after a media file is saved. This parameter conflicts with **-rf**.|

**Example**

```shell
> mediatool send /data/tmp/MyImage.jpg
file://media/Photo/3/IMG_1721381297_001/MyImage.jpg # The image is saved successfully, and the URI of the image is displayed.
```

### mediatool list

```shell
mediatool list <resource-uri>
```

Displays the information of a resource file specified by **\<resource-uri>** in the media library in CSV format.
For example, if the URI of image A in the media library is **file://media/Photo/3/IMG_1721381297_001/MyImage.jpg**, you can run **mediatool list file://media/Photo/3** or **mediatool list file://media/Photo/3/IMG_1721381297_001/MyImage.jpg** to display the resource information.

The following resource information is contained:

- uri: URI of the media resource.
- display_name: name of the media resource.
- data: path of the source file of the media resource on the device.

You can also set **\<resource-uri>** to **all**, which displays the information about all the resource files in the media library.

**Example**

```shell
# Use a valid URI for query.
> mediatool list file://media/Photo/3
Table Name: Photos
uri, display_name, data
"file://media/Photo/3/IMG_1721381297_001/MyImage.jpg", "MyImage.jpg", "/storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg"

# Use an invalid URI for query.
> mediatool list file://media/Photo/
[FAIL] uri invalid. uri:file://media/Photo/
```

<!--DelEnd-->

### mediatool recv

```shell
mediatool recv <media-target> <dest-path>
```

This command is used to export the source file content of the media library resource specified by `<media-target>` to the device path specified by `<dest-path>`.

`<media-target>` can be in either of the following formats:
* File path in the system media directory. (You can obtain the value from [mediatool ls -l](#mediatool-ls--l). The folder path cannot be specified.)
* URI of the media library. (For details, see Media Library URI Description/Obtaining Method.)

If `<media-target>` specifies a file path, only the following paths are supported. The following paths have mapping relationships and access the same directory. The system media directory of the current user is accessed.
* /storage/media/local/files/Photo and lower file paths.
* /storage/media/\<uid\>/local/files/Photo and lower file paths. \<uid\> must be the ID of the current user. Otherwise, an error message is displayed, indicating that the path is invalid.

`<dest-path>` indicates the path of the file or folder to be created. If the value is a folder path, the file is exported to the folder, and the file name in the media library is retained. If it is set to a file path, do not use the path of an existing file. The <!--Del--> `<dest-path>` parameter must specify a path that can be accessed.<!--DelEnd--><!--RP1--><!--RP1End-->

After the file is exported successfully, the path of the exported file is displayed.

If **\<resource-uri>** is set to **all**, all resource files in the media library are exported. If `<media-target>` is set to `all`, `<dest-path>` must be set to a folder path.

This command cannot be used to export media assets from hidden albums.

**Example**

```shell
# Use the URI to export the corresponding media resource.
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

# Use the path to export the corresponding media resource.
> mediatool recv /storage/media/local/files/Photo/16/IMG_1748435796_000.jpg /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

# Export all media resource files.
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

Deletes a resource file specified by **\<resource-uri>** from the media library. Since the deleted resource cannot be recovered, exercise caution when using this command.

For details about how to obtain the media library resource URI, see Media Library URI Introduction/Obtaining Method.

If **\<resource-uri>** is set to **all**, all resource files in the media library are deleted and all data in the media library is reset.

**Example**

```shell
> mediatool delete file://media/Photo/3
[SUCCESS] delete success.

> mediatool delete all # No information is displayed when the delete all command is executed successfully.
```

### mediatool query

```shell
mediatool query <display-name> [-p] [-u]
```

Queries the path or URI of a resource file specified by **\<display-name>** in the media library. By default, the path is returned.

This command cannot be used to query media assets in hidden albums.

  | Parameter              | Description            |
| ---- |--------------- |
| -p | Obtains the path of the media resource file. This parameter is used by default.|
| -u | Obtains the URI of the media resource. This parameter conflicts with **-p**.|

**Example**

```shell
# Query the media file that exists.
> mediatool query MyImage.jpg
find 1 result:
path
/storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

# Query the media file that does not exist.
> mediatool query non_exist.jpg
find 0 result

# Use a name in incorrect format for query.
> mediatool query IMG_001
find 0 result
The displayName format is not correct!

# Query the path of the media resource file.
> mediatool query MyImage.jpg -p
find 1 result:
path
/storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

# Query the URI of the media resource.
> mediatool query MyImage.jpg -u
find 1 result:
uri
"file://media/Photo/2/IMG_1721381297_001/MyImage.jpg"
```

### mediatool ls -l

```shell
mediatool ls -l <media-path>
```

Lists all the files in the system media path specified by `<media-path>`. The effect is similar to that of the file system `ls -l`.

The `<media-path>` supports only the following paths. The following paths have mapping relationships and access the same directory. That is, the system media directory of the current user is accessed.

* /storage/media/local/files/Photo and lower paths.
* /storage/media/\<uid\>/local/files/Photo or lower. \<uid\> must be the ID of the current user. Otherwise, an error message is displayed, indicating that the path is invalid.

`-l` is a mandatory option. If `-l` is not specified, an error is reported.

This command cannot be used to hide media assets in the album.

**Example**

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

## Usage Guide

The following describes some common application scenarios of the MediaTool.

### Exporting a Specific Media Library Asset

Example: Export a JPG image named MyImage from Gallery.

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

The following is an example of exporting media library assets based on the media file path:

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

### Exporting All Media Library Assets

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

### Deleting a Specific Media Library Asset

The following example shows how to delete a JPG image named MyImage from Gallery.

```shell
> hdc shell mediatool query -u MyImage.jpg
find 1 result
uri
"file://media/Photo/1/IMG_1743078145_000/MyImage.jpg"

> hdc shell mediatool delete file://media/Photo/1/IMG_1743078145_000/MyImage.jpg
[SUCCESS] delete success.
```

### Deleting All Media Library Databases
```shell
> hdc shell mediatool delete all
```

## Media Library URI Introduction/Obtaining Method

URI is the unique identifier of a media library asset. Each URI corresponds to a media asset. The mediatool uses the URI to determine the media asset object to be operated.

To obtain the URI, perform the following steps:
* If the -u option is added to the mediatool query command, the URI of the corresponding media asset can be returned. You need to enter the display name of the corresponding asset (the name displayed in the gallery contains the suffix).
<!--Del-->
* The mediatool list all command can be used to obtain the URI list of all media library assets and the display names of the assets.
<!--DelEnd-->

The media library URI can be used by the mediatool recv command to export a specific media library asset or used by the mediatool delete command to delete a specific media library asset.

Example URI: file://media/Photo/1/IMG_1743078145_000/MyImage.jpg.
When the preceding URIs are used during mediatool operations, the target asset can be correctly located regardless of whether file://media/Photo/1/IMG_1743078145_000/MyImage.jpg or file://media/Photo/1 is used.
