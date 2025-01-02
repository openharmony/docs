# mediatool

mediatool is a lightweight collection of command line utilities, by which you can manage media assets such as images and videos in the system gallery.

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

### mediatool recv

```shell
mediatool recv <resource-uri> <dest-path>
```
Exports the source file specified by **\<resource-uri>** in the media library to the device path specified by **\<dest-path>**. You can set **\<dest-path>** to the path of a file or folder. If it is set to a folder path, the file is exported to the folder and the source file name is used. If it is set to a file path, do not use the path of an existing file. In addition, **\<dest-path>** must be accessible. After the file is exported successfully, the path of the exported file is displayed.

You can run **mediatool list all** or [mediatool query](#mediatool-query) to obtain the URI of a resource file in the media library.

If **\<resource-uri>** is set to **all**, all resource files in the media library are exported. In this case, **\<dest-path>** must be a folder path.

**Example**
```shell
> mediatool recv file://media/Photo/3 /data/out.jpg
Table Name: Photos
/data/out.jpg
```

### mediatool delete

```shell
mediatool delete <resource-uri>
```

Deletes a resource file specified by **\<resource-uri>** from the media library. Since the deleted resource cannot be recovered, exercise caution when use this command.

You can run **mediatool list all** or **[mediatool query](#mediatool-query)** to obtain the URI of a resource file in the media library.

If **\<resource-uri>** is set to **all**, all resource files in the media library are deleted and all data in the media library is reset.

**Example**
```shell
> mediatool delete file://media/Photo/3
[SUCCESS] delete success.

> mediatool delete all # No information is displayed when the delete all command is executed successfully.
```

<!--DelEnd-->

### mediatool query

```shell
mediatool query <display-name>
```
  Queries the path of a resource file specified by **\<display-name>** in the media library.
  
  **Example**

  ```shell
  # Query the media file that exists.
  > mediatool query MyImage.jpg
  find 1 result:
  /storage/cloud/100/files/Photo/2/IMG_1721381297_001.jpg

  # Query the media file that does not exist.
  > mediatool query non_exist.jpg
  The displayName you want to query do not exist!
  find 0 result
  
  # Use an name in incorrect format for query.
  > mediatool query IMG_001
  The displayName format is not correct!
  ```
