# Distributed File System Overview

OpenHarmony distributed file system (hmdfs) provides cross-device file access capabilities applicable to the following scenarios:

- The user can use the editing software on one device to edit the files on another device.

- Music stored on a tablet can be directly viewed and played by a in-car system.

- The user can use a tablet to view the photos taken by another device.

The hmdfs provides a globally consistent access view for each device dynamically connected to a network via DSoftBus and allows you to implement high-performance read and write operations on files with low latency by using basic file system APIs.

## Distributed File System Architecture

![Distributed File System Architecture](figures/distributed-file-system-architecture.png)

- distributedfile_daemon: listens for device online status, establishes links over DSoftBus, and applies data transfer policies based on the security level of the device.

- hmdfs: implements a network file system in the kernel, providing cache management, file access, metadata management, and conflict management.
  - Buffer management
    - After devices are connected to form a Virtual Device, hmdfs provides file access capabilities, but does not proactively transmit or copy files. Active copy is required when an application needs to save data to a local directory.
    - The hmdfs ensures close-to-open cache consistency, which allows data to flushed when a client closes a file. Then, the latest data can be read when the file is opened on any other client. The hmdfs does not ensure real-time consistency of the file content.
    - If data written at the peer end has not been flushed to the local end in a timely manner due to network problems, the file system flushes the data to the local end upon the next network access. However, if the data has been modified on the remote end, only the latest data can be flushed.
  - File access
    - OpenHarmony provides the same interface, [ohos.file.fs](../reference/apis/js-apis-file-fs.md), for accessing files in the local and distributed file systems.
    - The files in the local file system are accessed in overlay mode.
    - The files on another device are accessed over a synchronous network.
        > **NOTE**
        >
        > symlink is not supported.
  - Metadata management
    - In distributed networking, when a file is created, deleted, or modified on a client, the latest file can be viewed on another client. The speed varies depending on the network status.
    - If a device goes offline, its data is no longer visible to other devices. However, due to the delay in sensing the device offline, the files of some offline devices may also be visible to other devices. Therefore, you need to consider the network delay in application development.
  - Conflict handling
    - If a file on the local end and a file on the remote end have the same name, the file on the remote end will be renamed.
    - If multiple remote devices have files of the same name, the name of the file with the smallest device access ID is retained and the files on other devices will be renamed.
    - In the networking scenario, the directory tree has remote files. If "duplicate file name" is displayed when a file is created,
    - the conflict file is renamed "_conflict_dev_ID". The ID automatically increases from 1.
    - If a local directory has the same name as a remote directory, "_remote_directory" will be added to the end of the peer directory.
