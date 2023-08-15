# Pushing Files to an Application Sandbox

During the development and debugging process of an application, you may need to push files to the application sandbox for intra-application access or for testing purposes. In this case, you can use either of the following methods:

- Use DevEco Studio to push the files to the application installation directory. For details, see [Application Installation Resource Access](../quick-start/resource-categories-and-access.md#resource-access).

- Use the hdc tool to push files to the application sandbox directory on the device. This section describes the second method.

However, the file directories visible to the debugged process in the hdc shell are different from the application sandbox directories visible to the application. You need to understand the mappings between the application sandbox directories and the physical (real) directories.

## Mappings Between Application Sandbox Directories and Physical Directories

The read and write operations performed based on the application sandbox paths via APIs are performed on the files in the physical directories after address conversion. The following table lists the mappings between application sandbox paths and physical paths.

**Table 1** Mapping between application sandbox paths and physical paths

| Application Sandbox Path| Physical Path in hdc| Description|
| -------- | -------- | -------- |
| /data/storage/el1/bundle | /data/app/el1/bundle/public/&lt;PACKAGENAME&gt; | Application installation package directory.|
| /data/storage/el1/base | /data/app/el1/&lt;USERID&gt;/base/&lt;PACKAGENAME&gt; | Application directory of encryption level (el) 1.|
| /data/storage/el2/base | /data/app/el2/&lt;USERID&gt;/base/&lt;PACKAGENAME&gt; | Application directory of el 2.|
| /data/storage/el1/database | /data/app/el1/&lt;USERID&gt;/database/&lt;PACKAGENAME&gt; | Database directory of the application under **el1/**.|
| /data/storage/el2/database | /data/app/el2/&lt;USERID&gt;/database/&lt;PACKAGENAME&gt; | Database directory of the application under **el2/**.|
| /data/storage/el2/distributedfiles | /mnt/hmdfs/&lt;USERID&gt;/account/merge_view/data/&lt;PACKAGENAME&gt; | Distributed data directory of the application under **el2/**.|

## Development Example

The following uses the application bundle **com.ohos.example** as an example. If the application sandbox path is **/data/storage/el1/bundle**, the physical path is **/data/app/el1/bundle/public/<PACKAGENAME>**, that is, **/data/app/el1/bundle/public/com.ohos.example**.

Run the following command to push files:

```
hdc file send ${Path of the local files to send} /data/app/el1/bundle/public/com.ohos.example/
```

## Switching to the Application View

During the debugging process, if the required permission is unavailable or the file does not exist, you need to switch from the process view to the application view and further analyze permission and directory problems. To switch to the application view, run the following commands:

```
hdc shell                         // Switch to shell.
ps -ef|grep [hapName]             // Obtain the process identifier (PID) of the application.
nsenter -t [hapPid] -m /bin/sh    // Enter the application sandbox environment based on the PID.
```

The application view is in use, and the path you see is the application sandbox path.
