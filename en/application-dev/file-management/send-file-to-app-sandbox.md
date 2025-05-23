# Pushing Files to an Application Sandbox Directory

During the development and debugging process of an application, you may need to push files to the application sandbox directory for intra-application access or for testing purposes. You can use either of the following methods to push files:

- Use DevEco Studio to push the files to the application installation directory. For details, see [Application Installation Resource Access](../quick-start/resource-categories-and-access.md#resource-access).

- Use the hdc tool to push files to the application sandbox directory on the device, which is described below.

However, the file paths viewed on the hdc shell are different from the application sandbox paths in the application view. You need to understand the [mappings between application sandbox paths and physical paths](app-sandbox-directory.md#mappings-between-application-sandbox-paths-and-physical-paths).

## Development Example

The application package **com.ohos.example** is used as an example. If files are read and written in the application sandbox directory **/data/storage/el1/bundle** of **example**, the physical path is **/data/app/el1/bundle/public/&lt;PACKAGENAME&gt;**, that is, **/data/app/el1/bundle/public/com.ohos.example**, according to the [mappings between application sandbox paths and physical paths](app-sandbox-directory.md#mappings-between-application-sandbox-paths-and-physical-paths).

Run the following command to push a file:

```
hdc file send ${Path of the local file to send}/data/app/el1/bundle/public/com.ohos.example/
```

After the file is pushed, set **user_id** and **group_id** of the file to **user_id** of the application. You can run the following command to query **user_id** of the application, which is the value in the first column of the process.

```
hdc shell ps -ef | grep com.ohos.example
```

Run the following command to set **user_id** and **group_id** of the file based on **user_id** of the application process:
```
hdc shell chown ${user_id}:${user_id} ${File path}
```

## Switching to the Application View

During the debugging process, if the required permission is unavailable or the file does not exist, you need to switch from the process view to the application view and further analyze permission and directory problems. To switch to the application view, run the following commands:

```
hdc shell                         // Switch to shell.
ps -ef|grep [hapName]             // Obtain the process identifier (PID) of the application.
nsenter -t [hapPid] -m /bin/sh    // Enter the application sandbox environment based on the PID.
```

Now the application view is in use, and the paths you see are the application sandbox paths.
