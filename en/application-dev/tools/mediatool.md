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
mediatool recv <resource-uri> <dest-path>
```

This command is used to export the source file content of the media library resource specified by `<resource-uri>` to the device path specified by `<dest-path>`.

`<dest-path>` indicates the path of the file or folder to be created. If the value is a folder path, the file is exported to the folder, and the file name in the media library is retained. If it is set to a file path, do not use the path of an existing file. The <!--Del--> `<dest-path>` parameter must specify a path that can be accessed.<!--DelEnd--><!--RP1--><!--RP1End-->

If it is set to a file path, do not use the path of an existing file.
<!--Del-->
In addition, **\<dest-path>** must be accessible.
<!--DelEnd-->
After the file is exported successfully, the path of the exported file is displayed.



If **\<resource-uri>** is set to **all**, all resource files in the media library are exported. If `\<resource-uri>` is set to `all`, `<dest-path>` must be set to a folder path.

This command cannot be used to export media assets from hidden albums.
<!--RP1--><!--RP1End-->

**Example**

```shell
> mediatool recv file://media/Photo/3 /data/local/tmp/out.jpg
Table Name: Photos
/data/local/tmp/out.jpg
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

### Exporting All Media Library Assets

```shell
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
