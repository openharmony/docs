# Pushing Files to an Application Sandbox Directory

During the development and debugging process of an application, you may need to push files to the application sandbox directory for intra-application access or for testing purposes. You can use either of the following methods to push files:

- Use DevEco Studio to push the files to the application installation directory. For details, see [Application Installation Resource Access](../quick-start/resource-categories-and-access.md#resource-access).

- Use the hdc tool to push files to the application sandbox directory on the device, which is described below.

The directories displayed in the hdc shell in the debugging process are different from the application sandbox paths visible to the application. You need to understand the mappings between them.

## Mappings Between Application Sandbox Paths and Physical Paths

The read and write operations performed based on the application sandbox paths via APIs are performed on the files in the physical directories after address conversion. The following table lists their mappings.

**Table 1** Mappings between application sandbox paths and physical paths

| Application Sandbox Path| Physical Path in hdc| Description|
| -------- | -------- | -------- |
| /data/storage/el1/bundle | /data/app/el1/bundle/public/&lt;PACKAGENAME&gt; | Application installation package directory.|
| /data/storage/el1/base | /data/app/el1/&lt;USERID&gt;/base/&lt;PACKAGENAME&gt; | Application directory of encryption level 1.|
| /data/storage/el2/base | /data/app/el2/&lt;USERID&gt;/base/&lt;PACKAGENAME&gt; | Application directory of encryption level 2.|
| /data/storage/el1/database | /data/app/el1/&lt;USERID&gt;/database/&lt;PACKAGENAME&gt; | Database directory of the application under **el1/**.|
| /data/storage/el2/database | /data/app/el2/&lt;USERID&gt;/database/&lt;PACKAGENAME&gt; | Database directory of the application under **el2/**.|
| /data/storage/el2/distributedfiles | /mnt/hmdfs/&lt;USERID&gt;/account/merge_view/data/&lt;PACKAGENAME&gt; | Distributed data directory of the application under **el2/**.|

## Development Example

The following uses the bundle **com.ohos.example** as an example. If the application sandbox path is **/data/storage/el1/bundle**, the physical path is **/data/app/el1/bundle/public/com.ohos.example**.

Run the following command to push a file:

```
hdc file send ${Path of the local file to send}/data/app/el1/bundle/public/com.ohos.example/
```

After the file is pushed, set **user_id** and **group_id** of the file to **user_id** of the application. You can run the following command to query **user_id** of the application, which is the value in the first column of the process.

```
hdc shell ps -ef | grep com.ohos.example
```

Run the following command to set **user_id** and **group_id**:
```
hdc shell chown ${user_id}:${user_id} ${ file_path}
```

## Switching to the Application View

During the debugging process, if the required permission is unavailable or the file does not exist, you need to switch from the process view to the application view and further analyze permission and directory problems. To switch to the application view, run the following commands:

```
hdc shell                         // Switch to shell.
ps -ef|grep [hapName]             // Obtain the process identifier (PID) of the application.
nsenter -t [hapPid] -m /bin/sh    // Enter the application sandbox environment based on the PID.
```

Now the application view is in use, and the paths you see are the application sandbox paths.
