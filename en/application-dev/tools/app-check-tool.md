# App Check Tool

## Overview

The app check tool is used to analyze and detect application installation packages. Based on the parameter settings, it scans the HAP, HSP, or APP file in the specified path and generates detection reports, providing data support for you to optimize the package structure or locate problems. The tool provides the following functions:
- Scans for duplicate files.
- Scans for large files (files that exceed the specified size).
- Collects statistics on the size and proportion of each type of file.

By default, the tool generates detection reports in JSON and HTML format.

The **app_check_tool.jar** package of the tool is stored in the **toolchains** directory of the SDK.

![App check tool architecture](figures/app-check-tool-construct.png)

## Constraints
The app check tool must run in Java 8 or later.

## Scanning for Duplicate Files

**Command example**

```
java -jar app_check_tool.jar --input ./test.app --out-path ./test --stat-duplicate true
```

**Parameters of the command**

| Parameter            | Mandatory| Description                                                              |
| ---------------- | ---------- | ------------------------------------------------------------------ |
| --input          | Yes        | Path of the HAP, HSP, or APP file.                               |
| --out-path       | Yes        | Path of the detection reports.                                          |
| --stat-duplicate | No        | Whether to scan for duplicate files. The default value is **false**.<br>- **true**: Scanning is enabled.<br>- **false**: Scanning is disabled. |

**Detection report in JSON format**

```
[{
    "taskType":1,
    "taskDesc":"find the duplicated files",
    "param":"--stat-duplicate",
    "startTime":"2023-11-17 14:48:01:265",
    "stopTime":"2023-11-17 14:48:01:434",
	"result":[{
        "md5":"975c41f5727b416b1ffefa5bb0f073b",
        "size":1108880,
        "files":[
            "/application-entry-default.hap/libs/armeabi-v7a/example.so",
            "/entry-default.hap/libs/armeabi-v7a/example.so"
        ]
    }]
}]
```

**Detection report in HTML format**

<div id="box">
        <table>
            <tr>
                <td>taskType</td>
                <td colspan="2">1</td>
            </tr>
            <tr>
                <td>taskDesc</td>
                <td colspan="2">find the duplicated files</td>
            </tr>
            <tr>
                <td>param</td>
                <td colspan="2">--stat-duplicate</td>
            </tr>
            <tr>
                <td>startTime</td>
                <td colspan="2">2023-11-17 14:48:01:265</td>
            </tr>
            <tr>
                <td>stopTime</td>
                <td colspan="2">2023-11-17 14:48:01:434</td>
            </tr>
            <tr>
                <td rowspan="5">result</td>
            </tr>
            <tr>
                <td>md5</td>
                <td>975c41f5727b416b1ffefa5bb0f073b</td>
            </tr>
            <tr>
                <td>size</td>
                <td>1108880</td>
            </tr>
            <tr>
                <td rowspan="2">files</td>
                <td>/application-entry-default.hap/libs/armeabi-v7a/example.so</td>
            </tr>
            <tr>
                <td>/entry-default.hap/libs/armeabi-v7a/example.so</td>
            </tr>
        </table>
</div>

**Fields of the output**

| Field     | Type  | Description                       |
| --------- | ------ | --------------------------- |
| taskType  | int    | Type of the task. The value **1** means a task for scanning for duplicate files.|
| taskDesc  | String | Description of the task.           |
| param     | String | Parameter passed in by the scanning program.         |
| startTime | String | Start time of the task.             |
| stopTime  | String | End time of the task.             |
| result    | Struct | [Fields of result](#section1).      |

**Fields of result**<a name="section1"></a>

| Field | Type           | Description                      |
| ----- | --------------- | -------------------------- |
| md5   | String          | MD5 value of the duplicate files.         |
| size  | int             | Size of the duplicate files, in bytes.|
| files | Vector\<String> | Paths of the duplicate files.    |

## Scanning for Large Files

**Command example**

```
java -jar app_check_tool.jar --input ./test.app --out-path ./test --stat-file-size 4
```

**Parameters of the command**

| Parameter            | Mandatory| Description                                                       |
| ---------------- | ---------- | ----------------------------------------------------------- |
| --input          | Yes        | Path of the HAP, HSP, or APP file.                        |
| --out-path       | Yes        | Path of the detection reports.                                   |
| --stat-file-size | No        | File size, in KB. A file with the size larger than this value is treated as a large file.<br>The value ranges from 0 to 4294967295, in KB.|

**Detection report in JSON format**

```
[{
    "taskType":2,
    "taskDesc":"find files whose size exceed the limit size",
    "param":"--stat-file-size 4",
    "startTime":"2023-11-17 14:48:01:458",
    "stopTime":"2023-11-17 14:48:01:491",
    "result":[{
            "file":"/application-entry-default.hap/libs/x86_64/example.so",
            "size":1292840
    }]
}]
```
**Detection report in HTML format**

<div id="box">
    <table>
        <tr>
            <td>taskType</td>
            <td colspan="2">2</td>
        </tr>
        <tr>
            <td>taskDesc</td>
            <td colspan="2">find files whose size exceed the limit size</td>
        </tr>
        <tr>
            <td>param</td>
            <td colspan="2">--stat-file-size 4</td>
        </tr>
        <tr>
            <td>startTime</td>
            <td colspan="2">2023-11-17 14:48:01:458</td>
        </tr>
        <tr>
            <td>stopTime</td>
            <td colspan="2">2023-11-17 14:48:01:491</td>
        </tr>
        <tr>
            <td rowspan="4">result</td>
        </tr>
        <tr>
            <td>file</td> <td>size</td>
        </tr>
        <tr>
            <td>/application-entry-default.hap/libs/x86_64/example.so</td>
            <td>1292840</td>
        </tr>
    </table>
</div>

**Fields of the output**

| Field     | Type  | Description                               |
| --------- | ------ | ----------------------------------- |
| taskType  | int    | Type of the task. The value **2** means a task for scanning for large files.|
| taskDesc  | String | Description of the task.                   |
| param     | String | Parameter passed in by the scanning program.                 |
| startTime | String | Start time of the task.                     |
| stopTime  | String | End time of the task.                     |
| result    | Struct | [Fields of result](#section2).              |

**Fields of result**<a name="section2"></a>

| Field| Type  | Description                                |
| ---- | ------ | ------------------------------------ |
| file | String | Path of a file.            |
| size | int    | Size of the file, in bytes.|

## Collecting Statistics on the Size and Proportion by File Type

**Command example**

```
java -jar app_check_tool.jar --input ./test.app --out-path ./test --stat-suffix true
```

**Parameters of the command**

| Parameter         | Mandatory| Description                                                                     |
| ------------- | ---------- | ------------------------------------------------------------------------- |
| --input       | Yes        | Path of the HAP, HSP, or APP file.                                      |
| --out-path    | Yes        | Path of the detection reports.                                                 |
| --stat-suffix | No        | Whether to collect statistics on the size and proportion of each type of file. The default value is **false**.<br>- **true**: Statistics collection is enabled.<br>- **false**: Statistics collection is disabled. |

**Detection report in JSON format**

```
[{
    "taskType":3,
    "taskDesc":"show files group by file type[.suffix]",
    "param":"--stat-suffix",
    "startTime":"2023-11-17 14:48:01:497",
    "stopTime":"2023-11-17 14:48:01:537",
    "pathList":[
        "test.app/application-entry-default.hap",
        "test.app/entry-default.hap"
    ],
    "result":[{
        "suffix":"so",
        "totalSize":1292840,
        "files":[{
            "compress":"false",
            "file":"/application-entry-default.hap/libs/x86_64/example.so",
            "size":1292840
        }]
    },
    {
        "suffix":"abc",
        "totalSize":84852,
        "files":[{
            "file":"/application-entry-default.hap/ets/modules.abc",
            "size":76304
        },
        {
            "file":"/entry-default.hap/ets/modules.abc",
            "size":8548
        }]
    }]
}]
```

**Detection report in HTML format**

<div>
  <table  >
        <tr>
            <td>taskType</td>
            <td colspan="2">3</td>
        </tr>
        <tr>
            <td>taskDesc</td>
            <td colspan="2">show files group by file type[.suffix]</td>
        </tr>
        <tr>
            <td>param</td>
            <td colspan="2">--stat-suffix</td>
        </tr>
        <tr>
            <td>startTime</td>
            <td colspan="2">2023-11-17 14:48:01:497</td>
        </tr>
        <tr>
            <td>stopTime</td>
            <td colspan="2">2023-11-17 14:48:01:537</td>
        </tr>
        <tr>
			<td >pathList</td>
			<td colspan="2">
                test.app/application-entry-default.hap<br>test.app/entry-default.hap
			</td>
		</tr>
        <tr >
            <td rowspan="30" width="10%">result</td>
            <td width="10%">suffix</td>
            <td width="50%">so</td>
        </tr>
        <tr>
            <td>totalSize</td>
            <td>1292840</td>
        </tr>
        <tr>
            <td rowspan="2">files</td>
        </tr>
        <tr>
            <td>compress:false<br>size:1292840<br>file:/application-entry-default.hap/libs/x86_64/example.so </td>
        </tr>
        <tr>
            <td width="10%">suffix</td>
            <td width="50%">abc</td>
        </tr>
        <tr>
            <td>totalSize</td>
            <td>84852</td>
        </tr>
        <tr>
            <td rowspan="2">files</td>
        </tr>
        <tr>
            <td>            
                size:8548<br>file:/entry-default.hap/ets/modules.abc<br>size:76304<br>file:/application-entry-default.hap/ets/modules.abc<br>
            </td>
        </tr>
    </table>
</div>

**Fields of the output**

| Field     | Type           | Description                                                                                  |
| --------- | --------------- | -------------------------------------------------------------------------------------- |
| taskType  | int             | Type of the task. The value **3** means a task for collecting statistics on the size and proportion of each type of file.                                                 |
| taskDesc  | String          | Description of the task.                                                                      |
| param     | String          | Parameter passed in by the scanning program.                                                                    |
| startTime | String          | Start time of the task.                                                                        |
| stopTime  | String          | End time of the task.                                                                        |
| pathList  | Vector\<String> | Paths of multiple HAP and HSP files.                                                                 |
| result    | Struct          | [Fields of result](#section3).                                                                |

**Fields of result**<a name="section3"></a>

| Field     | Type  | Description                                      |
| --------- | ------ | ------------------------------------------ |
| suffix    | String | File name extension.                        |
| totalSize | int    | Total size of the files with the same file name extension, in bytes. |
| files     | Stuct  | [Fields of files](#section4).                     |

**Fields of files**<a name="section4"></a>
| Field    | Type  | Description                                                               |
| -------- | ------ | ------------------------------------------------------------------- |
| file     | String | Path of a file.                                                         |
| size     | int    | Size of the file.                                                       |
| compress | bool   | Whether the file is compressed. This field is displayed only for .so files.<br>- **true**: The file is compressed.<br>- **false**: The file is not compressed. |
