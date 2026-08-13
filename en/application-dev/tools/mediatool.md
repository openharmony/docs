# mediatool

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=2845f22b3a6c7c573421bce7ff3e32f73246613d translatedAt=2026-07-20T10:51:22.477Z pushedAt=2026-07-21T03:32:30.706Z -->

You can use [mediatool](#mediatool-1) or [hdc commands](#hdc-commands) to operate media library resources. The media library provides and manages data for the gallery. Images and videos in the media library are displayed on the gallery screen.

## mediatool

mediatool is a lightweight command line tool set built in the **/bin** folder. You can run the **hdc shell** command to invoke it.

### Prerequisites

- The devices are properly connected.

- **Developer options** is enabled in system settings.

- The **hdc shell** command is executed to enter the command line execution mode.

<!--DelEnd-->

### mediatool recv

```shell
mediatool recv <media-target> <dest-path>
```

Exports the source file specified by **\<media-target>** in the media library to the device path specified by **\<dest-path>**.

**\<media-target>** can be in either of the following formats:

* File path in the system media directory. You can obtain the file path by running the [mediatool ls -l](#mediatool-ls--l) command. The folder path cannot be specified.

* URI of the media library. (For details, see [Media Library URI Introduction and Obtaining Method](#media-library-uri-introduction-and-obtaining-method).)

If **\<media-target>** specifies a file path, only the following paths are supported; they are mapped to one another and all resolve to the current user's system media directory.

* **/storage/media/local/files/Photo** and lower file paths.

* **/storage/media/\<uid\>/local/files/Photo** and lower file paths. **\<uid\>** must be the current user ID. Otherwise, an error message is displayed, indicating that the path is invalid.

**\<dest-path>** is the path of the file to be created or the folder path. If it is set to a folder path, the file will be exported to the folder, and the file name remains the same as that in the media library. If it is set to a file path, do not use the path of an existing file. <!--Del-->The **<dest-path>** parameter must specify a path that can be accessed.<!--DelEnd--><!--RP1--><!--RP1End-->

After the file is exported successfully, the path of the exported file is displayed.

If **\<media-target>** is set to **all**, all resource files in the media library are exported. In this case, **\<dest-path>** must be a folder path.

This command cannot be used to export media assets from hidden albums.

**Example**

```shell
# Export the corresponding media resource based on the URI.
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg

# Export the corresponding media resource based on the path.
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

For details about how to obtain the media library resource URI, see [Media Library URI Introduction and Obtaining Method](#media-library-uri-introduction-and-obtaining-method).

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

Lists all the files in the system media path specified by **\<media-path>**. The effect is similar to that of **ls -l** in the file system.

**\<media-path>** supports only the following paths; they are mapped to one another and all resolve to the current user's system media directory.

* **/storage/media/local/files/Photo** and its subdirectories.

* **/storage/media/\<uid\>/local/files/Photo** and its subdirectories. **\<uid\>** must be the current user ID. Otherwise, an error message is displayed, indicating that the path is invalid.

The **-l** option is mandatory. If **-l** is not specified, an error is reported.

This command cannot be used to query media assets in hidden albums.

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

### Exporting a Specific Media Library Asset

The following example shows how to export a JPG image named **MyImage** from Gallery.

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

The following example exports media library assets based on the media file path.

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

The following example shows how to delete a JPG image named **MyImage** from Gallery.

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

### Media Library URI Introduction and Obtaining Method

The URI uniquely identifies a media library asset. mediatool uses the URI to determine the media asset object to be operated.

To obtain the URI, perform the following steps:

* Add the **-u** option to **mediatool query** to return the URI of the corresponding media asset. You need to enter the display name of the corresponding asset (the name displayed in Gallery contains the extension).

The media library URI can be used in the **mediatool recv** command to export a specific media library asset or in the **mediatool delete** command to delete a specific media library asset.

Example URI: **file://media/Photo/1/IMG_1743078145_000/MyImage.jpg**.

When the preceding URIs are used during mediatool operations, the target asset can be correctly located regardless of whether **file://media/Photo/1/IMG_1743078145_000/MyImage.jpg** or **file://media/Photo/1** is used.

## hdc Commands

Since API version 21, the hdc command can be used to access media library file paths, including the **/mnt/data/\<uid\>/media_fuse/Photo/** directory and its subdirectories. **\<uid\>** indicates the ID of the current user.

### Querying Media Library Files

Images and videos that are not hidden in a specified path can be queried.

Run the following command:

```shell
hdc shell ls -l DEST
```

**Example**

```shell
$ hdc shell ls -l /mnt/data/100/media_fuse/Photo # Return the album list.
drwxrwxrwx 2 user_data_rw user_data_rw 3440 1970-01-01 00:00 Others
drwxrwxrwx 2 user_data_rw user_data_rw 3440 1970-01-01 00:00 Camera

$ hdc shell ls -l /mnt/data/100/media_fuse/Photo/Camera # List all local images and videos that are not hidden in the camera folder.
total 32813056
-rw-rw-rw- 1 user_data_rw user_data_rw 7085591 1970-01-01 00:00 1.jpg
-rw-rw-rw- 1 user_data_rw user_data_rw 6217442 1970-01-01 00:00 2.jpg

$ hdc shell ls -l /mnt/data/100/media_fuse/Photo/Camera/1.jpg # Return the details about 1.jpg.
-rw-rw-rw- 1 user_data_rw user_data_rw 7085591 1970-01-01 00:00 /mnt/data/100/media_fuse/Photo/Camera/1.jpg
```

### Exporting Media Library Files

You can export all local files and directories that are not hidden in a specified path.

Run the following command:

```shell
hdc file recv DEST SOURCE
```

**Example**

```shell
$ hdc file recv /mnt/data/100/media_fuse/Photo/Camera/File A # Export file A.
FileTransfer finish, Size:xxx, File...

$ hdc file recv /mnt/data/100/media_fuse/Photo/Camera # Export the Camera directory and files in the directory.
FileTransfer finish, Size:xxx, File...

$ hdc file recv /mnt/data/100/media_fuse/Photo/ # Export the Photo directory and its subfiles.
FileTransfer finish, Size:xxx, File...
```

### Importing Media Library Files

You can import media files (such as images and videos) and directories, but cannot create directories. If the directory names are the same, the content is combined (all files with different names are retained). If the file names are the same, the target file is overwritten.

```shell
hdc file send SOURCE DEST
```

**Example**

```shell
$ hdc file send D:\dest\Camera/mnt/data/100/media_fuse/Photo/ # Import all files in D:\dest\Camera to /mnt/data/100/media_fuse/Photo/camera/.
FileTransfer finish, Size:xxx, File...

$ hdc file send D:\dest\New directory/mnt/data/100/media_fuse/Photo/Camera/ # Directory creation is not supported.
[Fail][E005005] Error create directory: operation not permitted, path:/mnt/data/100/media_fuse/Photo/Camera//New directory

$ hdc file send D:\dest\Camera\File A/mnt/data/100/media_fuse/Photo/Camera/ # Import file A to /mnt/data/100/media_fuse/Photo/Camera/.
FileTransfer finish, Size:xxx, File...
```

### Deleting Media Library Files

You can delete specified files in an album, but cannot delete directories.

```shell
hdc shell rm DEST
```

**Example**

```shell
$ hdc shell rm /mnt/data/100/media_fuse/Photo/Camera/ # Return failure.
rm: /mnt/data/100/media_fuse/Photo/Camera: Is a directory

$ hdc shell rm /mnt/data/100/media_fuse/Photo/Camera/File A # No information is returned, and the deletion is successful.
```