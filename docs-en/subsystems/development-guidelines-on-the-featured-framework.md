# Development Guidelines on the featured Framework<a name="EN-US_TOPIC_0000001062713987"></a>

-   [Available APIs](#section20840587473)
-   [How to Develop](#section32781532131314)
-   [Use Case](#section1210915266154)

The featured framework provides comprehensive DFX features. By default, logs are output to the serial port and the file in  **/storage/data/log/**  in debug versions.

## Available APIs<a name="section20840587473"></a>

```
HILOG_DEBUG(type, ...)
HILOG_INFO(type, ...)
HILOG_WARN(type, ...)
HILOG_ERROR(type, ...)
HILOG_FATAL(type, ...)
```

**Table  1**  Parameters

<a name="table1872515171474"></a>
<table><thead align="left"><tr id="row772491734711"><th class="cellrowborder" valign="top" width="25.05%" id="mcps1.2.3.1.1"><p id="p1272431714477"><a name="p1272431714477"></a><a name="p1272431714477"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="74.95%" id="mcps1.2.3.1.2"><p id="p472451724716"><a name="p472451724716"></a><a name="p472451724716"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15416155714297"><td class="cellrowborder" valign="top" width="25.05%" headers="mcps1.2.3.1.1 "><p id="p041617572292"><a name="p041617572292"></a><a name="p041617572292"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="74.95%" headers="mcps1.2.3.1.2 "><p id="p74161557172912"><a name="p74161557172912"></a><a name="p74161557172912"></a>Used for compatibility with the parameters in the mini framework. The featured framework ignores any value passed to this parameter.</p>
</td>
</tr>
<tr id="row19724161794719"><td class="cellrowborder" valign="top" width="25.05%" headers="mcps1.2.3.1.1 "><p id="p1072431724710"><a name="p1072431724710"></a><a name="p1072431724710"></a>domainId</p>
</td>
<td class="cellrowborder" valign="top" width="74.95%" headers="mcps1.2.3.1.2 "><p id="p14724181724719"><a name="p14724181724719"></a><a name="p14724181724719"></a>Domain ID, which is a hidden parameter and needs to be defined</p>
</td>
</tr>
<tr id="row5724131714718"><td class="cellrowborder" valign="top" width="25.05%" headers="mcps1.2.3.1.1 "><p id="p2724191724716"><a name="p2724191724716"></a><a name="p2724191724716"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" width="74.95%" headers="mcps1.2.3.1.2 "><p id="p11724917114715"><a name="p11724917114715"></a><a name="p11724917114715"></a>Log tag, which is a hidden parameter and needs to be defined</p>
</td>
</tr>
<tr id="row137243177475"><td class="cellrowborder" valign="top" width="25.05%" headers="mcps1.2.3.1.1 "><p id="p1772461754718"><a name="p1772461754718"></a><a name="p1772461754718"></a>fmt</p>
</td>
<td class="cellrowborder" valign="top" width="74.95%" headers="mcps1.2.3.1.2 "><p id="p131236352304"><a name="p131236352304"></a><a name="p131236352304"></a>Format specifier</p>
<p id="p2072401710475"><a name="p2072401710475"></a><a name="p2072401710475"></a>Parameters labeled {private} are private data, and those labeled {public} are public data.</p>
</td>
</tr>
<tr id="row11725161719477"><td class="cellrowborder" valign="top" width="25.05%" headers="mcps1.2.3.1.1 "><p id="p172591734710"><a name="p172591734710"></a><a name="p172591734710"></a>args</p>
</td>
<td class="cellrowborder" valign="top" width="74.95%" headers="mcps1.2.3.1.2 "><p id="p8725617194715"><a name="p8725617194715"></a><a name="p8725617194715"></a>Parameters to be displayed using the format specifier.</p>
</td>
</tr>
</tbody>
</table>

Privacy rules \(only for logs in release mode\):

1.  The format specifier is labeled \{public\} by default.

    ```
    HILOG_INFO(0, "Hello World\n"); >> Hello World
    ```

2.  The formatted parameter is labeled \{private\} by default.

    ```
    HILOG_INFO(0, "Age is %d\n", 10); >> Age is <private>
    ```

3.  Parameters labeled %\{private\} are private data.

    ```
    HILOG_INFO(0, "Age is %{private}d\n", 10); >> Age is <private>
    ```

4.  Parameters labeled %\{public\} are public data.

    ```
    HILOG_INFO(0, "Age is %{public}d\n", 10); >>Age is 10
    ```


## How to Develop<a name="section32781532131314"></a>

1.  Include the dynamic library dependencies in the  **Build.gn**  file.

    ```
    public_deps = [ "//base/hiviewdfx/frameworks/hilog_lite/featured:hilog_shared"]
    ```

2.  Add the  **log.h**  header file to define the  **TAG**  and  **Domain**  values for the module.

    ```
    #include<log.h>
    #undef LOG_TAG
    #undef LOG_DOMAIN
    #define LOG_TAG "MyModule"
    #define LOG_DOMAIN 0xD00000
    ```

3.  Run the log printing code.

    ```
    HILOG_INFO(0,"Hello World\n"); 
    ```


## Use Case<a name="section1210915266154"></a>

The following steps describe how the  **samgr\_lite**  module \(an example\) uses the featured framework.

1.  Reference the  **hilog**  header file and dependency library by using dependency statements in  **foundation/distributedschedule/services/samgr\_lite/samgr/source/BUILD.gn**  in the source code path.

    ```
    public_deps = [ "//base/hiviewdfx/frameworks/hilog_lite/featured:hilog_shared" ]
    ```

2.  Reference the header file in the source code file and call the  **HILOG**  function.

    Refer to the following source code file  **distributedschedule/services/samgr\_lite/samgr\_server/source/samgr\_server.c**.

    ```
    #include<log.h>
    
    #undef LOG_TAG
    #undef LOG_DOMAIN
    #define LOG_TAG "Samgr"
    #define LOG_DOMAIN 0xD001800
    
    static void InitializeRegistry(void)
    {
        HILOG_INFO(HILOG_MODULE_SAMGR, "Initialize Registry!");
        ...
    }
    ```

    As shown in the file, the header file <log.h\> or <hilog/log.h\> is included, and the domain ID and tag \(Samgr\) are added.

3.  Call the  **InitializeRegistry**  function to print the log content, including the date, PID \(**6**\), task ID \(**23**\), level \(**I**\), domain ID \(**01800**, the least five bits of the defined value  **0xD001800**\), module name \(**Samgr**\), and statement \(**Initialize Registry!**\).

    **Figure  1**  Information printed during system startup<a name="fig418242621511"></a>  
    ![](figures/information-printed-during-system-startup.png "information-printed-during-system-startup")


