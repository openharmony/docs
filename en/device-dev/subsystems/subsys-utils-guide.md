# Utils Development<a name="EN-US_TOPIC_0000001059307279"></a>

## Available APIs<a name="section1633115419401"></a>

**Table  1**  APIs for file operations

<a name="table1171894475019"></a>
<table><thead align="left"><tr id="row1471814441508"><th class="cellrowborder" valign="top" width="45.540000000000006%" id="mcps1.2.3.1.1"><p id="p11718174425016"><a name="p11718174425016"></a><a name="p11718174425016"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="54.459999999999994%" id="mcps1.2.3.1.2"><p id="p6718124475013"><a name="p6718124475013"></a><a name="p6718124475013"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row671818445506"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p871814441501"><a name="p871814441501"></a><a name="p871814441501"></a>int UtilsFileOpen(const char* path, int oflag, int mode)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p127181444165016"><a name="p127181444165016"></a><a name="p127181444165016"></a>Opens or creates a file.</p>
</td>
</tr>
<tr id="row1171874420507"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p1671884419509"><a name="p1671884419509"></a><a name="p1671884419509"></a>int UtilsFileClose(int fd)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p1071884416504"><a name="p1071884416504"></a><a name="p1071884416504"></a>Closes a file with a specified file descriptor.</p>
</td>
</tr>
<tr id="row6718744105017"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p137181644145015"><a name="p137181644145015"></a><a name="p137181644145015"></a>int UtilsFileRead(int fd, char *buf, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p1171854410509"><a name="p1171854410509"></a><a name="p1171854410509"></a>Reads a specified length of data from a file with the specified file descriptor and writes the data into the buffer.</p>
</td>
</tr>
<tr id="row2071817440509"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p17718144465012"><a name="p17718144465012"></a><a name="p17718144465012"></a>int UtilsFileWrite(int fd, const char *buf, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p67191444145012"><a name="p67191444145012"></a><a name="p67191444145012"></a>Writes a specified length of data into a file with the specified file descriptor.</p>
</td>
</tr>
<tr id="row471974425019"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p11719174475016"><a name="p11719174475016"></a><a name="p11719174475016"></a>int UtilsFileDelete(const char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p2071919446507"><a name="p2071919446507"></a><a name="p2071919446507"></a>Deletes a specified file.</p>
</td>
</tr>
<tr id="row1071964425013"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p20719114405010"><a name="p20719114405010"></a><a name="p20719114405010"></a>int UtilsFileStat(const char *path, unsigned int *fileSize)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p8719144435015"><a name="p8719144435015"></a><a name="p8719144435015"></a>Obtains the file size.</p>
</td>
</tr>
<tr id="row2071924417504"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p57193447501"><a name="p57193447501"></a><a name="p57193447501"></a>int UtilsFileSeek(int fd, int offset, unsigned int whence)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p1071934495014"><a name="p1071934495014"></a><a name="p1071934495014"></a>Adjusts the read and write position offset in a file.</p>
</td>
</tr>
<tr id="row1135017417557"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p2350184112554"><a name="p2350184112554"></a><a name="p2350184112554"></a>int UtilsFileCopy(const char* src, const char* dest)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p113501041155511"><a name="p113501041155511"></a><a name="p113501041155511"></a>Copies the source file to a target file.</p>
</td>
</tr>
<tr id="row11216645145517"><td class="cellrowborder" valign="top" width="45.540000000000006%" headers="mcps1.2.3.1.1 "><p id="p192171345105519"><a name="p192171345105519"></a><a name="p192171345105519"></a>int UtilsFileMove(const char* src, const char* dest)</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.2.3.1.2 "><p id="p921744595517"><a name="p921744595517"></a><a name="p921744595517"></a>Moves the source file into a target file.</p>
</td>
</tr>
</tbody>
</table>

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

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p980953910190"><a name="p980953910190"></a><a name="p980953910190"></a>int UtilsGetValue(const char* key, char* value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p13562171015712"><a name="p13562171015712"></a><a name="p13562171015712"></a>Obtains the value matching a specified key from the file system or cache.</p>
</td>
</tr>
<tr id="row1746172917474"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p242913617818"><a name="p242913617818"></a><a name="p242913617818"></a>int UtilsSetValue(const char* key, const char* value)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p2431455765"><a name="p2431455765"></a><a name="p2431455765"></a>Adds or updates the value matching a specified key in the file system or cache.</p>
</td>
</tr>
<tr id="row10992232154714"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p118151439111910"><a name="p118151439111910"></a><a name="p118151439111910"></a>int UtilsDeleteValue(const char* key)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p126575774517"><a name="p126575774517"></a><a name="p126575774517"></a>Deletes the value matching a specified key from the file system or cache.</p>
</td>
</tr>
</tbody>
</table>

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

        ![](figure/unnaming.png)

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
    ![](figure/output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-m-kernel.png "output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-m-kernel")


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
    ![](figure/output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-a-kernel.png "output-of-the-system-attribute-dumping-command-for-the-liteos-cortex-a-kernel")


