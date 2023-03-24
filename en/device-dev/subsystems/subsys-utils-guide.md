# Utils Development<a name="EN-US_TOPIC_0000001059307279"></a>

## Available APIs<a name="section1633115419401"></a>

**Table  1**  APIs for file operations

| Function | Description |
| ---------- | ------------- |
| int UtilsFileOpen(const char* path, int oflag, int mode) | Opens or creates a file. |
| int UtilsFileClose(int fd) | Closes a file with a specified file descriptor. |
| int UtilsFileRead(int fd, char *buf, unsigned int len) | Reads a specified length of data from a file with the specified file descriptor and writes the data into the buffer. |
| int UtilsFileWrite(int fd, const char *buf, unsigned int len) | Writes a specified length of data into a file with the specified file descriptor. |
| int UtilsFileDelete(const char *path) | Deletes a specified file. |
| int UtilsFileStat(const char *path, unsigned int *fileSize) | Obtains the file size. |
| int UtilsFileSeek(int fd, int offset, unsigned int whence) | Adjusts the read and write position offset in a file. |
| int UtilsFileCopy(const char* src, const char* dest) | Copies the source file to a target file. |
| int UtilsFileMove(const char* src, const char* dest) | Moves the source file into a target file. |


Sample code for file operations:

```
// Open a file and write data.
char fileName[] = "testfile";
static const char def[] = "utils_file_operation implement.";
int fd = UtilsFileOpen(fileName, O_RDWR_FS | O_CREAT_FS | O_TRUNC_FS, 0);
printf("file handle = %d\n", fd);
int ret = UtilsFileWrite(fd, def, strlen(def));
printf("write ret = %d\n", ret);

// Adjust the position offset in the file.
ret = UtilsFileSeek(fd, 5, SEEK_SET_FS);
printf("lseek ret = %d\n", ret);

// Read data and close the file.
char buf[64] = {0};
int readLen = UtilsFileRead(fd, buf, 64);
ret = UtilsFileClose(fd);
printf("read len = %d : buf = %s\n", readLen, buf);

// Obtain the file size.
int fileLen = 0;
ret = UtilsFileStat(fileName, &fileLen);
printf("file size = %d\n", fileLen);

// Delete the file.
ret = UtilsFileDelete(fileName);
printf("delete ret = %d\n", ret);
```

**Table  2**  APIs for KV store operations

| Function | Description |
| ----------- | ---------------- |
| int UtilsGetValue(const char* key, char* value, unsigned int len) | Obtains the value matching a specified key from the file system or cache. |
| int UtilsSetValue(const char* key, const char* value) | Adds or updates the value matching a specified key in the file system or cache. |
| int UtilsDeleteValue(const char* key) | Deletes the value matching a specified key from the file system or cache. |


Sample code for the KV store:

```
// Set the value matching the specified key.
char key[] = "rw.sys.version_100";
char value[] = "Hello kv operation implement!";
int ret = UtilsSetValue(key, value);
printf("UtilsSetValue set ret = %d\n", ret);

// Obtain the value matching the specified key.
char temp[128] = {0};
ret = UtilsGetValue(key, temp, 128);
printf("UtilsGetValue get ret = %d, temp = %s\n", ret, temp);

// Delete the value matching the specified key.
ret = UtilsDeleteValue(key);
printf("UtilsDeleteValue delete ret = %d\n", ret);
```

## How to Develop<a name="section17450172710292"></a>

### Developing a Native Application for the KV Store That Uses the LiteOS Cortex-A Kernel \(Hi3516 or Hi3518\)<a name="section258354119295"></a>

1.  Develop the native application for the KV store using  **AbilityKit**  APIs.
    -   Write the user program by calling the APIs provided by the KV store and compile the  **libLauncher.so**  file.

        ```
        // Set the value matching the specified key.
        char key[] = "rw.sys.version_100";
        char value[] = "Hello kv operation implement!";
        int ret = UtilsSetValue(key, value);
        printf("UtilsSetValue set ret = %d\n", ret);
        
        // Obtain the value matching the specified key.
        char temp[128] = {0};
        ret = UtilsGetValue(key, temp, 128);
        printf("UtilsGetValue get ret = %d, temp = %s\n", ret, temp);
        
        // Delete the value matching the specified key.
        ret = UtilsDeleteValue(key);
        printf("UtilsDeleteValue delete ret = %d\n", ret);
        ```

    -   Edit the  **config.json**  file as follows:

        ```
        {
            "app": {
                "bundleName": "com.example.launcher",
                "vendor": "example,
                "version": {
                    "code": 1,
                    "name": "1.0"
                }
            },
            "deviceConfig": {
                "default": {
                    "reqSdk": {
                        "compatible": "zsdk 1.0.0",
                        "target": "zsdk 1.0.1"
                    },
                    "keepAlive": false
                },
                "smartCamera": {
                    "reqSdk": {
                        "compatible": "zsdk 1.0.0",
                        "target": "zsdk 1.0.1"
                    },
                    "keepAlive": false
                }
            },
            "module": {
                "package": "com.example.launcher",
                "name": ".MyHarmonyAbilityPackage",
                "deviceType": [
                    "phone", "tv","tablet", "pc","car","smartWatch","sportsWatch","smartCamera"
                ], 
                "distro": {
                    "deliveryWithInstall": true, 
                    "moduleName": "Launcher", 
                    "moduleType": "entry"
                },
                "abilities": [{
                    "name": "MainAbility",
                    "icon": "res/drawable/phone.png",
                    "label": "test app 1", 
                    "launchType": "standard",
                    "type": "page"
                },
                {
                    "name": "SecondAbility",
                    "icon": "res/drawable/phone.png",
                    "label": "test app 2", 
                    "launchType": "standard",
                    "type": "page"
                },
                {
                    "name": "ServiceAbility",
                    "icon": "res/drawable/phone.png",
                    "label": "test app 2", 
                    "launchType": "standard",
                    "type": "service"
                }
                ]
            }
        }
        ```

    -   Generate a HAP file.

        -   Add resource files in the  **res/drawable**  directory based on the following directory structure.

        ![](figures/unnaming.png)

        -   Compress the  **libLauncher.so**,  **config.json**, and resource files into a ZIP package and change the file name extension to  **.hap**, for example,  **Launcher.hap**.

2.  Connect the development board and send the command for installing the native KV store application to the board through the serial port.

    ```
    ./nfs/dev_tools/bin/bm install -p /nfs/Launcher.hap
    ```

3.  Send the command for running the native KV store application to the board through the serial port.

    ```
    ./nfs/dev_tools/bin/aa start -p com.example.launcher -n ServiceAbility
    ```


### Dumping System Attributes on the Platform That Uses the LiteOS Cortex-M Kernel<a name="section9179161863014"></a>

1.  Connect the development board and send the  **AT+SYSPARA**  command to the board through the serial port.

    ```
    AT+SYSPARA
    ```

    **Figure  1**  Output of the system attribute dumping command for the LiteOS Cortex-M kernel<a name="fig15179161863016"></a>  
    ![](figures/output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-m-kernel.png "output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-m-kernel")


### Dumping System Attributes on the Platform That Uses the LiteOS Cortex-A Kernel<a name="section3179121853017"></a>

1.  Connect the development board and run the  **os\_dump --help**  command in the  **bin**  directory to view the  **os\_dump**  help information.

    ```
    ./bin/os_dump --help
    ```

2.  Run the  **os\_dump -l**  command in the  **bin**  directory to view system modules that support attribute dumping.

    ```
    ./bin/os_dump -l
    ```

3.  Run the  **os\_dump syspara**  command in the  **bin**  directory to dump the current system attributes.

    ```
    ./bin/os_dump syspara
    ```

    **Figure  2**  Output of the system attribute dumping command for the LiteOS Cortex-A kernel<a name="fig2179718143018"></a>  
    ![](figures/output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-a-kernel.png "output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-a-kernel")
