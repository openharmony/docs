# File Management

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import fileio from '@ohos.fileio';
```

## Required Permissions

None

## Usage

Before using this module to perform operations on a file or directory, you must obtain the absolute path of the file or directory. For details, see  **getOrCreateLocalDir** in the **Context** module.


Absolute file or directory path = Application directory path + File name or directory name

For example, if the application directory obtained by using the API is  _dir_  and the file name is  _file name_**.txt**, the absolute path of the file is as follows:

```
let path = dir + "file name.txt"
```

The file descriptor is as follows:

```
let fd = fileio.openSync(path);
```

## fileio.statSync<a name="section014281412198"></a>

statSync\(path:string\): Stat

Synchronously obtains file information.

-   Parameters

    <a name="table21431314201914"></a>
    <table><thead align="left"><tr id="row15143151416194"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1214311146190"><a name="p1214311146190"></a><a name="p1214311146190"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p181441142194"><a name="p181441142194"></a><a name="p181441142194"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p514421417190"><a name="p514421417190"></a><a name="p514421417190"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p41441514181911"><a name="p41441514181911"></a><a name="p41441514181911"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15144214191910"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p18144111417199"><a name="p18144111417199"></a><a name="p18144111417199"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p9144111415196"><a name="p9144111415196"></a><a name="p9144111415196"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p414410149199"><a name="p414410149199"></a><a name="p414410149199"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p106911349133411"><a name="p106911349133411"></a><a name="p106911349133411"></a>Absolute path of the target file.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table131441014111919"></a>
    <table><thead align="left"><tr id="row19144101418196"><th class="cellrowborder" valign="top" width="22.93%" id="mcps1.1.3.1.1"><p id="p614513143191"><a name="p614513143191"></a><a name="p614513143191"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.07000000000001%" id="mcps1.1.3.1.2"><p id="p1514517145192"><a name="p1514517145192"></a><a name="p1514517145192"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5145191421914"><td class="cellrowborder" valign="top" width="22.93%" headers="mcps1.1.3.1.1 "><p id="p11145141481918"><a name="p11145141481918"></a><a name="p11145141481918"></a><a href="#section7315249105116">Stat</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="77.07000000000001%" headers="mcps1.1.3.1.2 "><p id="p0145171491910"><a name="p0145171491910"></a><a name="p0145171491910"></a>Detailed file information.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let stat = fileio.statSync(path);
    ```


## fileio.opendirSync<a name="section7741145112216"></a>

opendirSync\(path: string\): Dir

Synchronously opens a directory.

-   Parameters

    <a name="table57421045122215"></a>
    <table><thead align="left"><tr id="row187421459221"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1974244516221"><a name="p1974244516221"></a><a name="p1974244516221"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p774294592214"><a name="p774294592214"></a><a name="p774294592214"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.81%" id="mcps1.1.5.1.3"><p id="p137424459229"><a name="p137424459229"></a><a name="p137424459229"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.52%" id="mcps1.1.5.1.4"><p id="p274212459222"><a name="p274212459222"></a><a name="p274212459222"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1674284511223"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p197431458224"><a name="p197431458224"></a><a name="p197431458224"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p774318454226"><a name="p774318454226"></a><a name="p774318454226"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.81%" headers="mcps1.1.5.1.3 "><p id="p27437452221"><a name="p27437452221"></a><a name="p27437452221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="p144181369362"><a name="p144181369362"></a><a name="p144181369362"></a>Absolute path of the directory to open.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1743134517224"></a>
    <table><thead align="left"><tr id="row14743145202214"><th class="cellrowborder" valign="top" width="22.93%" id="mcps1.1.3.1.1"><p id="p127431245192220"><a name="p127431245192220"></a><a name="p127431245192220"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.07000000000001%" id="mcps1.1.3.1.2"><p id="p137430454222"><a name="p137430454222"></a><a name="p137430454222"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10743545202213"><td class="cellrowborder" valign="top" width="22.93%" headers="mcps1.1.3.1.1 "><p id="p17445459222"><a name="p17445459222"></a><a name="p17445459222"></a><a href="#section189341937163212">Dir</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="77.07000000000001%" headers="mcps1.1.3.1.2 "><p id="p16808111123618"><a name="p16808111123618"></a><a name="p16808111123618"></a>An instance of the <strong id="b13216191522416"><a name="b13216191522416"></a><a name="b13216191522416"></a>Dir</strong> class corresponding to a directory.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(path);
    ```


## fileio.accessSync<a name="section9627104782212"></a>

accessSync\(path: string, mode?: number\): void

Synchronously checks whether the current process can access a file.

-   Parameters

    <a name="table2062810475226"></a>
    <table><thead align="left"><tr id="row06284478229"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p56281747182210"><a name="p56281747182210"></a><a name="p56281747182210"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p17628144762211"><a name="p17628144762211"></a><a name="p17628144762211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p156281547192217"><a name="p156281547192217"></a><a name="p156281547192217"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p1862824714222"><a name="p1862824714222"></a><a name="p1862824714222"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row262816476222"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p196281347182217"><a name="p196281347182217"></a><a name="p196281347182217"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p1462816472225"><a name="p1462816472225"></a><a name="p1462816472225"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p16629104792216"><a name="p16629104792216"></a><a name="p16629104792216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p15367141141116"><a name="p15367141141116"></a><a name="p15367141141116"></a>Absolute path of the target file.</p>
    </td>
    </tr>
    <tr id="row204438428415"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p14444342104112"><a name="p14444342104112"></a><a name="p14444342104112"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p144413421414"><a name="p144413421414"></a><a name="p144413421414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p344414217412"><a name="p344414217412"></a><a name="p344414217412"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001144081254_p642032043011"><a name="en-us_topic_0000001144081254_p642032043011"></a><a name="en-us_topic_0000001144081254_p642032043011"></a>Options for accessing the file. You can specify multiple options, separated with a bitwise OR operator (|). The default value is <strong id="b16902114218239"><a name="b16902114218239"></a><a name="b16902114218239"></a>0</strong>.</p>
    <p id="en-us_topic_0000001144081254_p164812171258"><a name="en-us_topic_0000001144081254_p164812171258"></a><a name="en-us_topic_0000001144081254_p164812171258"></a>The options are as follows:</p>
    <a name="en-us_topic_0000001144081254_ul133214146476"></a><a name="en-us_topic_0000001144081254_ul133214146476"></a><ul id="en-us_topic_0000001144081254_ul133214146476"><li><strong id="b192238321113"><a name="b192238321113"></a><a name="b192238321113"></a>0</strong>: Check whether the file exists.</li></ul>
    <a name="en-us_topic_0000001144081254_ul2629143710241"></a><a name="en-us_topic_0000001144081254_ul2629143710241"></a><ul id="en-us_topic_0000001144081254_ul2629143710241"><li><strong id="b18974183318324"><a name="b18974183318324"></a><a name="b18974183318324"></a>1</strong>: Check whether the current process has the execute permission on the file.</li><li><strong id="b2092351053319"><a name="b2092351053319"></a><a name="b2092351053319"></a>2</strong>: Check whether the current process has the write permission on the file.</li><li><strong id="b96446972411"><a name="b96446972411"></a><a name="b96446972411"></a>4</strong>: Check whether the process has the read permission on the file.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.accessSync(path);
    ```


## fileio.closeSync<a name="section11518951152211"></a>

closeSync\(fd: number\): void

Synchronously closes a file.

-   Parameters

    <a name="table165187512224"></a>
    <table><thead align="left"><tr id="row125192051162212"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p45191851192213"><a name="p45191851192213"></a><a name="p45191851192213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.65%" id="mcps1.1.5.1.2"><p id="p05198514224"><a name="p05198514224"></a><a name="p05198514224"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1%" id="mcps1.1.5.1.3"><p id="p9519125152210"><a name="p9519125152210"></a><a name="p9519125152210"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.22%" id="mcps1.1.5.1.4"><p id="p6519115182214"><a name="p6519115182214"></a><a name="p6519115182214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row45191051182219"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1851945110224"><a name="p1851945110224"></a><a name="p1851945110224"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.65%" headers="mcps1.1.5.1.2 "><p id="p12519115116220"><a name="p12519115116220"></a><a name="p12519115116220"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1%" headers="mcps1.1.5.1.3 "><p id="p135191851142216"><a name="p135191851142216"></a><a name="p135191851142216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.22%" headers="mcps1.1.5.1.4 "><p id="p8519951152218"><a name="p8519951152218"></a><a name="p8519951152218"></a>File descriptor of the file to close.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.closeSync(fd);
    ```


## fileio.copyFileSync<a name="section752155117222"></a>

fileio.copyFileSync\(src: string, dest: string, mode?:number\): void

Synchronously copies a file.

-   Parameters

    <a name="table154591869574"></a>
    <table><thead align="left"><tr id="row1146006185710"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p34601364573"><a name="p34601364573"></a><a name="p34601364573"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.470000000000002%" id="mcps1.1.5.1.2"><p id="p114609615719"><a name="p114609615719"></a><a name="p114609615719"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.139999999999999%" id="mcps1.1.5.1.3"><p id="p646056165718"><a name="p646056165718"></a><a name="p646056165718"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.36%" id="mcps1.1.5.1.4"><p id="p194601269577"><a name="p194601269577"></a><a name="p194601269577"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row184604645713"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p11460863575"><a name="p11460863575"></a><a name="p11460863575"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.2 "><p id="p44603616575"><a name="p44603616575"></a><a name="p44603616575"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.139999999999999%" headers="mcps1.1.5.1.3 "><p id="p64614615714"><a name="p64614615714"></a><a name="p64614615714"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.36%" headers="mcps1.1.5.1.4 "><p id="p16668162211811"><a name="p16668162211811"></a><a name="p16668162211811"></a>Path of the file to copy.</p>
    </td>
    </tr>
    <tr id="row1646119675719"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1446117665719"><a name="p1446117665719"></a><a name="p1446117665719"></a>dest</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.2 "><p id="p2461765571"><a name="p2461765571"></a><a name="p2461765571"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.139999999999999%" headers="mcps1.1.5.1.3 "><p id="p546166135717"><a name="p546166135717"></a><a name="p546166135717"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.36%" headers="mcps1.1.5.1.4 "><p id="p3461136125713"><a name="p3461136125713"></a><a name="p3461136125713"></a>Target file path.</p>
    </td>
    </tr>
    <tr id="row134617611577"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p446110617571"><a name="p446110617571"></a><a name="p446110617571"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.2 "><p id="p2046218615711"><a name="p2046218615711"></a><a name="p2046218615711"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.139999999999999%" headers="mcps1.1.5.1.3 "><p id="p14462116155713"><a name="p14462116155713"></a><a name="p14462116155713"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.36%" headers="mcps1.1.5.1.4 "><p id="p14434113012329"><a name="p14434113012329"></a><a name="p14434113012329"></a>Option for overwriting the file of the same name in the destination path. The default value is <strong id="b556042710713"><a name="b556042710713"></a><a name="b556042710713"></a>0</strong>, which is the only value supported.</p>
    <p id="p20644174510189"><a name="p20644174510189"></a><a name="p20644174510189"></a><strong id="b7419959572"><a name="b7419959572"></a><a name="b7419959572"></a>0</strong>: Overwrite the file with the same name completely and truncate the part that is not overwritten.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.copyFileSync(src, dest);
    ```


## fileio.mkdirSync<a name="section11419920164917"></a>

fileio.mkdirSync\(path: string, mode?: number\): void

Synchronously creates a directory.

-   Parameters

    <a name="table19694163952110"></a>
    <table><thead align="left"><tr id="row126941539202111"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1769483917215"><a name="p1769483917215"></a><a name="p1769483917215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p14694203922119"><a name="p14694203922119"></a><a name="p14694203922119"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1069463922116"><a name="p1069463922116"></a><a name="p1069463922116"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1169483913211"><a name="p1169483913211"></a><a name="p1169483913211"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3694639142118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p769473962120"><a name="p769473962120"></a><a name="p769473962120"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p12694153919217"><a name="p12694153919217"></a><a name="p12694153919217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p9694203932115"><a name="p9694203932115"></a><a name="p9694203932115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p86940398219"><a name="p86940398219"></a><a name="p86940398219"></a>Absolute path of the directory to create.</p>
    </td>
    </tr>
    <tr id="row1317135692118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6171656102116"><a name="p6171656102116"></a><a name="p6171656102116"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1017155614211"><a name="p1017155614211"></a><a name="p1017155614211"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1917110566213"><a name="p1917110566213"></a><a name="p1917110566213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001144081254_p1049717244222"><a name="en-us_topic_0000001144081254_p1049717244222"></a><a name="en-us_topic_0000001144081254_p1049717244222"></a>Permission on the directory to create. You can specify multiple permissions, separated using a bitwise OR operator (|). The default value is <strong id="en-us_topic_0000001144081254_b098801584115"><a name="en-us_topic_0000001144081254_b098801584115"></a><a name="en-us_topic_0000001144081254_b098801584115"></a>0o775</strong>.</p>
    <a name="en-us_topic_0000001144081254_ul1958851172210"></a><a name="en-us_topic_0000001144081254_ul1958851172210"></a><ul id="en-us_topic_0000001144081254_ul1958851172210"><li><strong id="en-us_topic_0000001144081254_b1190412714347"><a name="en-us_topic_0000001144081254_b1190412714347"></a><a name="en-us_topic_0000001144081254_b1190412714347"></a>0o775</strong>: The owner has the read, write, and execute permissions, and other users have the read and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1249671103614"><a name="en-us_topic_0000001144081254_b1249671103614"></a><a name="en-us_topic_0000001144081254_b1249671103614"></a>0o700</strong>: The owner has the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b79581111271"><a name="en-us_topic_0000001144081254_b79581111271"></a><a name="en-us_topic_0000001144081254_b79581111271"></a>0o400</strong>: The owner has the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b012182612274"><a name="en-us_topic_0000001144081254_b012182612274"></a><a name="en-us_topic_0000001144081254_b012182612274"></a>0o200</strong>: The owner has the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1529414585270"><a name="en-us_topic_0000001144081254_b1529414585270"></a><a name="en-us_topic_0000001144081254_b1529414585270"></a>0o100</strong>: The owner has the execute permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b32181650152814"><a name="en-us_topic_0000001144081254_b32181650152814"></a><a name="en-us_topic_0000001144081254_b32181650152814"></a>0o070</strong>: The user group has the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b786783913720"><a name="en-us_topic_0000001144081254_b786783913720"></a><a name="en-us_topic_0000001144081254_b786783913720"></a>0o040</strong>: The user group has the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b931995043716"><a name="en-us_topic_0000001144081254_b931995043716"></a><a name="en-us_topic_0000001144081254_b931995043716"></a>0o020</strong>: The user group has the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b104271314183817"><a name="en-us_topic_0000001144081254_b104271314183817"></a><a name="en-us_topic_0000001144081254_b104271314183817"></a>0o010</strong>: The user group has the execute permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b81321023391"><a name="en-us_topic_0000001144081254_b81321023391"></a><a name="en-us_topic_0000001144081254_b81321023391"></a>0o007</strong>: Other users have the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b490663819391"><a name="en-us_topic_0000001144081254_b490663819391"></a><a name="en-us_topic_0000001144081254_b490663819391"></a>0o004</strong>: Other users have the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1820614983917"><a name="en-us_topic_0000001144081254_b1820614983917"></a><a name="en-us_topic_0000001144081254_b1820614983917"></a>0o002</strong>: Other users have the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b145721888402"><a name="en-us_topic_0000001144081254_b145721888402"></a><a name="en-us_topic_0000001144081254_b145721888402"></a>0o001</strong>: Other users have the execute permission on the directory.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.mkdirSync(path);
    ```


## fileio.openSync<a name="section7431145402220"></a>

openSync\(path: string, flags?: number, mode?: number\): number

Synchronously opens a file.

-   Parameters

    <a name="table83121919193718"></a>
    <table><thead align="left"><tr id="row1231219198379"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.5.1.1"><p id="p631213194378"><a name="p631213194378"></a><a name="p631213194378"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.67%" id="mcps1.1.5.1.2"><p id="p1631261963711"><a name="p1631261963711"></a><a name="p1631261963711"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.260000000000002%" id="mcps1.1.5.1.3"><p id="p2312111913373"><a name="p2312111913373"></a><a name="p2312111913373"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.58%" id="mcps1.1.5.1.4"><p id="p10312171919378"><a name="p10312171919378"></a><a name="p10312171919378"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12312101993717"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p1313151963712"><a name="p1313151963712"></a><a name="p1313151963712"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.67%" headers="mcps1.1.5.1.2 "><p id="p831311198371"><a name="p831311198371"></a><a name="p831311198371"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.1.5.1.3 "><p id="p6313161913379"><a name="p6313161913379"></a><a name="p6313161913379"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.58%" headers="mcps1.1.5.1.4 "><p id="p143141819183716"><a name="p143141819183716"></a><a name="p143141819183716"></a>Absolute path of the file to open.</p>
    </td>
    </tr>
    <tr id="row1194614489373"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p1494624819379"><a name="p1494624819379"></a><a name="p1494624819379"></a>flags</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.67%" headers="mcps1.1.5.1.2 "><p id="p17946448103710"><a name="p17946448103710"></a><a name="p17946448103710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.1.5.1.3 "><p id="p139471148183717"><a name="p139471148183717"></a><a name="p139471148183717"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.58%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001144081254_p0315175720016"><a name="en-us_topic_0000001144081254_p0315175720016"></a><a name="en-us_topic_0000001144081254_p0315175720016"></a>Option for opening the file. You must specify one of the following options. By default, the file is open in read-only mode.</p>
    <a name="en-us_topic_0000001144081254_ul13154571407"></a><a name="en-us_topic_0000001144081254_ul13154571407"></a><ul id="en-us_topic_0000001144081254_ul13154571407"><li><strong id="b12723114754815"><a name="b12723114754815"></a><a name="b12723114754815"></a>0o0</strong>: Open file in read-only mode.</li><li><strong id="b10871178134912"><a name="b10871178134912"></a><a name="b10871178134912"></a>0o1</strong>: Open file in write-only mode.</li><li><strong id="b146881625174911"><a name="b146881625174911"></a><a name="b146881625174911"></a>0o2</strong>: Open file in read/write mode.</li></ul>
    <p id="en-us_topic_0000001144081254_p431616571208"><a name="en-us_topic_0000001144081254_p431616571208"></a><a name="en-us_topic_0000001144081254_p431616571208"></a>In addition, you can specify the following options using a bitwise OR operator (|). By default, no additional option is specified.</p>
    <a name="en-us_topic_0000001144081254_ul73162575015"></a><a name="en-us_topic_0000001144081254_ul73162575015"></a><ul id="en-us_topic_0000001144081254_ul73162575015"><li><strong id="b387810288259"><a name="b387810288259"></a><a name="b387810288259"></a>0o100</strong>: If the file does not exist, create a file. If you use this option, you must also specify <strong id="b13674740172511"><a name="b13674740172511"></a><a name="b13674740172511"></a>mode</strong>.</li><li><strong id="b12810204472510"><a name="b12810204472510"></a><a name="b12810204472510"></a>0o200</strong>: If <strong id="b4811194432516"><a name="b4811194432516"></a><a name="b4811194432516"></a>0o100</strong> is added and the file already exists, throw an exception.</li><li><strong id="b17202452142511"><a name="b17202452142511"></a><a name="b17202452142511"></a>0o1000</strong>: If the file exists and is open in write-only or read/write mode, truncate the file length to 0.</li><li><strong id="b15411255281"><a name="b15411255281"></a><a name="b15411255281"></a>0o2000</strong>: Open the file in append mode. New data will be appended to the file (written to the end of the file).</li><li><strong id="b168051621102813"><a name="b168051621102813"></a><a name="b168051621102813"></a>0o4000</strong>: If <strong id="b1680632142811"><a name="b1680632142811"></a><a name="b1680632142811"></a>path</strong> points to a named pipe (also known as a FIFO), block special file, or character special file, perform non-blocking operations on the open file and in subsequent I/Os.</li><li><strong id="b1489124712819"><a name="b1489124712819"></a><a name="b1489124712819"></a>0o200000</strong>: If <strong id="b08912473283"><a name="b08912473283"></a><a name="b08912473283"></a>path</strong> points to a directory, throw an exception.</li><li><strong id="b155311519288"><a name="b155311519288"></a><a name="b155311519288"></a>0o400000</strong>: If <strong id="b455325116284"><a name="b455325116284"></a><a name="b455325116284"></a>path</strong> points to a symbolic link, throw an exception.</li><li><strong id="b867455318285"><a name="b867455318285"></a><a name="b867455318285"></a>0o4010000</strong>: Open the file in synchronous I/O mode.</li></ul>
    </td>
    </tr>
    <tr id="row1452413112392"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p19524171115397"><a name="p19524171115397"></a><a name="p19524171115397"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.67%" headers="mcps1.1.5.1.2 "><p id="p10524811193913"><a name="p10524811193913"></a><a name="p10524811193913"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.1.5.1.3 "><p id="p1752419113399"><a name="p1752419113399"></a><a name="p1752419113399"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.58%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001144081254_p03171057708"><a name="en-us_topic_0000001144081254_p03171057708"></a><a name="en-us_topic_0000001144081254_p03171057708"></a>Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (|). The default value is <strong id="b119503032918"><a name="b119503032918"></a><a name="b119503032918"></a>0o666</strong>.</p>
    <a name="en-us_topic_0000001144081254_ul1554605585712"></a><a name="en-us_topic_0000001144081254_ul1554605585712"></a><ul id="en-us_topic_0000001144081254_ul1554605585712"><li><strong id="b1741519902917"><a name="b1741519902917"></a><a name="b1741519902917"></a>0o666</strong>: The owner, user group, and other users have the read and write permissions on the file.</li><li><strong id="b7928151316294"><a name="b7928151316294"></a><a name="b7928151316294"></a>0o700</strong>: The owner has the read, write, and execute permissions on the file.</li><li><strong id="b79581111271"><a name="b79581111271"></a><a name="b79581111271"></a>0o400</strong>: The owner has the read permission on the directory.</li><li><strong id="b012182612274"><a name="b012182612274"></a><a name="b012182612274"></a>0o200</strong>: The owner has the write permission on the directory.</li><li><strong id="b1529414585270"><a name="b1529414585270"></a><a name="b1529414585270"></a>0o100</strong>: The owner has the execute permission on the directory.</li><li><strong id="b32181650152814"><a name="b32181650152814"></a><a name="b32181650152814"></a>0o070</strong>: All user groups have the read, write, and execute permissions on the directory.</li><li><strong id="b786783913720"><a name="b786783913720"></a><a name="b786783913720"></a>0o040</strong>: All user groups have the read permission on the directory.</li><li><strong id="b931995043716"><a name="b931995043716"></a><a name="b931995043716"></a>0o020</strong>: All user groups have the write permission on the directory.</li><li><strong id="b104271314183817"><a name="b104271314183817"></a><a name="b104271314183817"></a>0o010</strong>: All user groups have the execute permission on the directory.</li><li><strong id="b81321023391"><a name="b81321023391"></a><a name="b81321023391"></a>0o007</strong>: Other users have the read, write, and execute permissions on the directory.</li><li><strong id="b490663819391"><a name="b490663819391"></a><a name="b490663819391"></a>0o004</strong>: Other users have the read permission on the directory.</li><li><strong id="b1820614983917"><a name="b1820614983917"></a><a name="b1820614983917"></a>0o002</strong>: Other users have the write permission on the directory.</li><li><strong id="b145721888402"><a name="b145721888402"></a><a name="b145721888402"></a>0o001</strong>: Other users have the execute permission on the directory.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table10314619113717"></a>
    <table><thead align="left"><tr id="row1131431917373"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p14314201914373"><a name="p14314201914373"></a><a name="p14314201914373"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p2314119103714"><a name="p2314119103714"></a><a name="p2314119103714"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1314151920378"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p163146199374"><a name="p163146199374"></a><a name="p163146199374"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p8314151912376"><a name="p8314151912376"></a><a name="p8314151912376"></a>File descriptor of the file opened.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.openSync(path);
    ```


## fileio.readSync<a name="section1682515612227"></a>

readSync\(fd: number, buffer: ArrayBuffer, options?: Object\): number

Synchronously reads data from a file.

-   Parameters

    <a name="table17441612151511"></a>
    <table><thead align="left"><tr id="row124410129159"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1944119126156"><a name="p1944119126156"></a><a name="p1944119126156"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p14411312121519"><a name="p14411312121519"></a><a name="p14411312121519"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p9441101241511"><a name="p9441101241511"></a><a name="p9441101241511"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1744111125158"><a name="p1744111125158"></a><a name="p1744111125158"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1644111211159"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p344191214156"><a name="p344191214156"></a><a name="p344191214156"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p7441121219152"><a name="p7441121219152"></a><a name="p7441121219152"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p20441121231516"><a name="p20441121231516"></a><a name="p20441121231516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1044214122155"><a name="p1044214122155"></a><a name="p1044214122155"></a>File descriptor of the file to read.</p>
    </td>
    </tr>
    <tr id="row1944211231512"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p134429128159"><a name="p134429128159"></a><a name="p134429128159"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p184424121155"><a name="p184424121155"></a><a name="p184424121155"></a>ArrayBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p144214127151"><a name="p144214127151"></a><a name="p144214127151"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6442181219155"><a name="p6442181219155"></a><a name="p6442181219155"></a>Buffer used for reading the file.</p>
    </td>
    </tr>
    <tr id="row1444211281512"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p84421812181516"><a name="p84421812181516"></a><a name="p84421812181516"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1544217123151"><a name="p1544217123151"></a><a name="p1544217123151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p124421812131517"><a name="p124421812131517"></a><a name="p124421812131517"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p15442141216157"><a name="p15442141216157"></a><a name="p15442141216157"></a>The options are as follows:</p>
    <a name="ul1644261221514"></a><a name="ul1644261221514"></a><ul id="ul1644261221514"><li><strong id="b81613454117"><a name="b81613454117"></a><a name="b81613454117"></a>offset</strong> (number): position of the buffer to which the data will be read in reference to the start address of the buffer. It is optional. The default value is <strong id="b183714580336"><a name="b183714580336"></a><a name="b183714580336"></a>0</strong>.</li><li><strong id="b1573710171419"><a name="b1573710171419"></a><a name="b1573710171419"></a>length</strong> (number): length of the data to read. It is optional. The default value is the buffer length minus the offset.</li><li><strong id="b4255104118448"><a name="b4255104118448"></a><a name="b4255104118448"></a>position</strong> (number): position of the data to read in the file. It is optional. By default, data is read from the current position.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table13442121215151"></a>
    <table><thead align="left"><tr id="row1844261201511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p10442101212158"><a name="p10442101212158"></a><a name="p10442101212158"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1444241251511"><a name="p1444241251511"></a><a name="p1444241251511"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row104429125154"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p14422012101515"><a name="p14422012101515"></a><a name="p14422012101515"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p244314126154"><a name="p244314126154"></a><a name="p244314126154"></a>Length of the data read.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let fd = fileio.openSync(path, 0o2);
    let buf = new ArrayBuffer(4096);
    fileio.readSync(fd, buf);
    console.log(String.fromCharCode.apply(null, new Uint8Array(buf)));
    ```


## fileio.rmdirSync<a name="section1420012610423"></a>

rmdirSync\(path: string\): void

Synchronously removes a directory.

-   Parameters

    <a name="table172741614151417"></a>
    <table><thead align="left"><tr id="row4274514181420"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7274161461418"><a name="p7274161461418"></a><a name="p7274161461418"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p0274111414143"><a name="p0274111414143"></a><a name="p0274111414143"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1127471451416"><a name="p1127471451416"></a><a name="p1127471451416"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1827414149145"><a name="p1827414149145"></a><a name="p1827414149145"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15274161461412"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1027421431410"><a name="p1027421431410"></a><a name="p1027421431410"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p182741014181418"><a name="p182741014181418"></a><a name="p182741014181418"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p14274161431417"><a name="p14274161431417"></a><a name="p14274161431417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p827414142144"><a name="p827414142144"></a><a name="p827414142144"></a>Absolute path of the directory to remove.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.rmdirSync(path);
    ```


## fileio.unlinkSync<a name="section1659112267472"></a>

unlinkSync\(path: string\): void

Synchronously deletes a file.

-   Parameters

    <a name="table10902246174"></a>
    <table><thead align="left"><tr id="row13903174617711"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p99031146778"><a name="p99031146778"></a><a name="p99031146778"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p79034461674"><a name="p79034461674"></a><a name="p79034461674"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p149030464710"><a name="p149030464710"></a><a name="p149030464710"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1790334610714"><a name="p1790334610714"></a><a name="p1790334610714"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row49035468712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1390316468713"><a name="p1390316468713"></a><a name="p1390316468713"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2090384611710"><a name="p2090384611710"></a><a name="p2090384611710"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p159031846575"><a name="p159031846575"></a><a name="p159031846575"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p7903124619711"><a name="p7903124619711"></a><a name="p7903124619711"></a>Absolute path of the file to delete.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.unlinkSync(path);
    ```


## fileio.writeSync<a name="section144923345218"></a>

writeSync\(fd: number, buffer: ArrayBuffer | string, options?:Object\): number

Synchronously writes data to a file.

-   Parameters

    <a name="table13943194014108"></a>
    <table><thead align="left"><tr id="row6944940101012"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p149447402107"><a name="p149447402107"></a><a name="p149447402107"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="p1944184011102"><a name="p1944184011102"></a><a name="p1944184011102"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="p11944174001010"><a name="p11944174001010"></a><a name="p11944174001010"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="p894554017109"><a name="p894554017109"></a><a name="p894554017109"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row199459404101"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16945440121019"><a name="p16945440121019"></a><a name="p16945440121019"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p194517403109"><a name="p194517403109"></a><a name="p194517403109"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p14945204017104"><a name="p14945204017104"></a><a name="p14945204017104"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p094584020101"><a name="p094584020101"></a><a name="p094584020101"></a>File descriptor of the file to write.</p>
    </td>
    </tr>
    <tr id="row7946174015104"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p094610401102"><a name="p094610401102"></a><a name="p094610401102"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p5946144012109"><a name="p5946144012109"></a><a name="p5946144012109"></a>ArrayBuffer | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p1794674018108"><a name="p1794674018108"></a><a name="p1794674018108"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p129466403102"><a name="p129466403102"></a><a name="p129466403102"></a>A string or data from a buffer to be written to the file.</p>
    </td>
    </tr>
    <tr id="row16946204012103"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1946840141012"><a name="p1946840141012"></a><a name="p1946840141012"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p69477400104"><a name="p69477400104"></a><a name="p69477400104"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p4947164021013"><a name="p4947164021013"></a><a name="p4947164021013"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p16947154021011"><a name="p16947154021011"></a><a name="p16947154021011"></a>The options are as follows:</p>
    <a name="ul14947144014103"></a><a name="ul14947144014103"></a><ul id="ul14947144014103"><li><strong id="b16450196204713"><a name="b16450196204713"></a><a name="b16450196204713"></a>offset</strong> (number): position of the data to write in reference to the start address of the data. It is optional. The default value is <strong id="b128318586337"><a name="b128318586337"></a><a name="b128318586337"></a>0</strong>.</li><li><strong id="b222210554321"><a name="b222210554321"></a><a name="b222210554321"></a>length</strong> (number): length of the data to write. It is optional. The default value is the buffer length minus the offset.</li><li><strong id="b1432162913348"><a name="b1432162913348"></a><a name="b1432162913348"></a>position</strong> (number): position of the data to be written in the file. It is optional. By default, data is written from the current position.</li><li><strong id="b20604341122510"><a name="b20604341122510"></a><a name="b20604341122510"></a>encoding</strong> (string): format of the data to be encoded. You must set it when the data is a string. The default value is <strong id="b86116418256"><a name="b86116418256"></a><a name="b86116418256"></a>utf-8</strong>. Only <strong id="b1639842362615"><a name="b1639842362615"></a><a name="b1639842362615"></a>utf-8</strong> is supported.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table13948204031017"></a>
    <table><thead align="left"><tr id="row4948204031017"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p11948540191013"><a name="p11948540191013"></a><a name="p11948540191013"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p894954091017"><a name="p894954091017"></a><a name="p894954091017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row149491940101010"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p20949184091011"><a name="p20949184091011"></a><a name="p20949184091011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1494984011100"><a name="p1494984011100"></a><a name="p1494984011100"></a>Length of the data written in the file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let fd = fileio.openSync(path, 0o102, 0o666);
    fileio.writeSync(fd, "hello, world");
    ```


## fileio.chmodSync<sup>7+</sup><a name="section199971741181414"></a>

chmodSync\(path: string, mode: number\): void

Synchronously changes the file permissions based on its path.

-   Parameters

    <a name="table7498121613156"></a>
    <table><thead align="left"><tr id="row2498151631511"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p4498171610155"><a name="p4498171610155"></a><a name="p4498171610155"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.58%" id="mcps1.1.5.1.2"><p id="p13498151611512"><a name="p13498151611512"></a><a name="p13498151611512"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.37%" id="mcps1.1.5.1.3"><p id="p1849841621512"><a name="p1849841621512"></a><a name="p1849841621512"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.23%" id="mcps1.1.5.1.4"><p id="p104981716121516"><a name="p104981716121516"></a><a name="p104981716121516"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row94981416121519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p749991610154"><a name="p749991610154"></a><a name="p749991610154"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.58%" headers="mcps1.1.5.1.2 "><p id="p3499151613151"><a name="p3499151613151"></a><a name="p3499151613151"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.37%" headers="mcps1.1.5.1.3 "><p id="p11499101618154"><a name="p11499101618154"></a><a name="p11499101618154"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.23%" headers="mcps1.1.5.1.4 "><p id="p174992161153"><a name="p174992161153"></a><a name="p174992161153"></a>Absolute path of the target file.</p>
    </td>
    </tr>
    <tr id="row1349981621513"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6499191661513"><a name="p6499191661513"></a><a name="p6499191661513"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.58%" headers="mcps1.1.5.1.2 "><p id="p1649961671518"><a name="p1649961671518"></a><a name="p1649961671518"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.37%" headers="mcps1.1.5.1.3 "><p id="p11499121631517"><a name="p11499121631517"></a><a name="p11499121631517"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.23%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001144081254_p598318203228"><a name="en-us_topic_0000001144081254_p598318203228"></a><a name="en-us_topic_0000001144081254_p598318203228"></a>Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (|).</p>
    <a name="en-us_topic_0000001144081254_ul14983162018222"></a><a name="en-us_topic_0000001144081254_ul14983162018222"></a><ul id="en-us_topic_0000001144081254_ul14983162018222"><li><strong id="en-us_topic_0000001144081254_b1416554467"><a name="en-us_topic_0000001144081254_b1416554467"></a><a name="en-us_topic_0000001144081254_b1416554467"></a>0o700</strong>: The owner has the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b102811142205113"><a name="en-us_topic_0000001144081254_b102811142205113"></a><a name="en-us_topic_0000001144081254_b102811142205113"></a>0o400</strong>: The owner has the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b195091329524"><a name="en-us_topic_0000001144081254_b195091329524"></a><a name="en-us_topic_0000001144081254_b195091329524"></a>0o200</strong>: The owner has the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b118222975217"><a name="en-us_topic_0000001144081254_b118222975217"></a><a name="en-us_topic_0000001144081254_b118222975217"></a>0o100</strong>: The owner has the execute permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1894816320539"><a name="en-us_topic_0000001144081254_b1894816320539"></a><a name="en-us_topic_0000001144081254_b1894816320539"></a>0o070</strong>: The user group has the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1263922015538"><a name="en-us_topic_0000001144081254_b1263922015538"></a><a name="en-us_topic_0000001144081254_b1263922015538"></a>0o040</strong>: The user group has the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b131401137145316"><a name="en-us_topic_0000001144081254_b131401137145316"></a><a name="en-us_topic_0000001144081254_b131401137145316"></a>0o020</strong>: The user group has the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b15120155535312"><a name="en-us_topic_0000001144081254_b15120155535312"></a><a name="en-us_topic_0000001144081254_b15120155535312"></a>0o010</strong>: The user group has the execute permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b108725179544"><a name="en-us_topic_0000001144081254_b108725179544"></a><a name="en-us_topic_0000001144081254_b108725179544"></a>0o007</strong>: Other users have the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b12893143417546"><a name="en-us_topic_0000001144081254_b12893143417546"></a><a name="en-us_topic_0000001144081254_b12893143417546"></a>0o004</strong>: Other users have the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b17222165213543"><a name="en-us_topic_0000001144081254_b17222165213543"></a><a name="en-us_topic_0000001144081254_b17222165213543"></a>0o002</strong>: Other users have the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b153517619558"><a name="en-us_topic_0000001144081254_b153517619558"></a><a name="en-us_topic_0000001144081254_b153517619558"></a>0o001</strong>: Other users have the execute permission on the directory.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.chmodSync(fpath, mode);
    ```


## fileio.fstatSync<sup>7+</sup><a name="section14821537102219"></a>

fstatSync\(fd: number\): Stat

Synchronously obtains file status information based on the file descriptor.

-   Parameters

    <a name="table1318758152213"></a>
    <table><thead align="left"><tr id="row431955802216"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p931935832210"><a name="p931935832210"></a><a name="p931935832210"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="p1431925872217"><a name="p1431925872217"></a><a name="p1431925872217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="p632065812228"><a name="p632065812228"></a><a name="p632065812228"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="p143202586223"><a name="p143202586223"></a><a name="p143202586223"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1432015811226"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11321115832213"><a name="p11321115832213"></a><a name="p11321115832213"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p113211588229"><a name="p113211588229"></a><a name="p113211588229"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p113211658192212"><a name="p113211658192212"></a><a name="p113211658192212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p1032135842220"><a name="p1032135842220"></a><a name="p1032135842220"></a>File descriptor of the target file.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table1432119586228"></a>
    <table><thead align="left"><tr id="row232195820224"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p4322658182215"><a name="p4322658182215"></a><a name="p4322658182215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p03222058162215"><a name="p03222058162215"></a><a name="p03222058162215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1032275817222"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p75973654013"><a name="p75973654013"></a><a name="p75973654013"></a>Promise&lt;Stat&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p12597269404"><a name="p12597269404"></a><a name="p12597269404"></a>File status information obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    let fd = fileio.openSync(path);
    let stat = fileio.fstatSync(fd);
    ```


## fileio.ftruncateSync<sup>7+</sup><a name="section514613516446"></a>

ftruncateSync\(fd: number, len?: number\): void

Synchronously truncates a file based on the file descriptor.

-   Parameters

    <a name="table171461935114413"></a>
    <table><thead align="left"><tr id="row15147113510445"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1614753518444"><a name="p1614753518444"></a><a name="p1614753518444"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="p1314783574414"><a name="p1314783574414"></a><a name="p1314783574414"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="p3147133512441"><a name="p3147133512441"></a><a name="p3147133512441"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="p1514753513442"><a name="p1514753513442"></a><a name="p1514753513442"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1514716354442"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p94460314520"><a name="p94460314520"></a><a name="p94460314520"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p1044616334513"><a name="p1044616334513"></a><a name="p1044616334513"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p15446639458"><a name="p15446639458"></a><a name="p15446639458"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p2446103114518"><a name="p2446103114518"></a><a name="p2446103114518"></a>File descriptor of the file to truncate.</p>
    </td>
    </tr>
    <tr id="row614812359442"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1644610344516"><a name="p1644610344516"></a><a name="p1644610344516"></a>len</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p184461931459"><a name="p184461931459"></a><a name="p184461931459"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p64469311451"><a name="p64469311451"></a><a name="p64469311451"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p1946656171316"><a name="p1946656171316"></a><a name="p1946656171316"></a>File length, in bytes, after truncation.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
     fileio.ftruncate(fd, len);
    ```


## fileio.fchmodSync<sup>7+</sup><a name="section16345147182418"></a>

fchmodSync\(existingPath: string, newPath: string\): void

Synchronously changes the file permissions based on the file descriptor.

-   Parameters

    <a name="table134612718249"></a>
    <table><thead align="left"><tr id="row934607172416"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p63468792413"><a name="p63468792413"></a><a name="p63468792413"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1234719722417"><a name="p1234719722417"></a><a name="p1234719722417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p93476716246"><a name="p93476716246"></a><a name="p93476716246"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p83472714248"><a name="p83472714248"></a><a name="p83472714248"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1534710711248"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p634719710243"><a name="p634719710243"></a><a name="p634719710243"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p17348147122417"><a name="p17348147122417"></a><a name="p17348147122417"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p15348207152417"><a name="p15348207152417"></a><a name="p15348207152417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p91788493584"><a name="p91788493584"></a><a name="p91788493584"></a>File descriptor of the target file.</p>
    </td>
    </tr>
    <tr id="row103484712416"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1834817711241"><a name="p1834817711241"></a><a name="p1834817711241"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13481762412"><a name="p13481762412"></a><a name="p13481762412"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p83484702415"><a name="p83484702415"></a><a name="p83484702415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001144081254_p19508174455411"><a name="en-us_topic_0000001144081254_p19508174455411"></a><a name="en-us_topic_0000001144081254_p19508174455411"></a>Permissions on the file. You can specify multiple permissions, separated using a bitwise OR operator (|).</p>
    <a name="en-us_topic_0000001144081254_ul74723715117"></a><a name="en-us_topic_0000001144081254_ul74723715117"></a><ul id="en-us_topic_0000001144081254_ul74723715117"><li><strong id="en-us_topic_0000001144081254_b9419550585"><a name="en-us_topic_0000001144081254_b9419550585"></a><a name="en-us_topic_0000001144081254_b9419550585"></a>0o700</strong>: The owner has the read, write, and execute permissions on the file.</li><li><strong id="en-us_topic_0000001144081254_b928354235111"><a name="en-us_topic_0000001144081254_b928354235111"></a><a name="en-us_topic_0000001144081254_b928354235111"></a>0o400</strong>: The owner has the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b45122021522"><a name="en-us_topic_0000001144081254_b45122021522"></a><a name="en-us_topic_0000001144081254_b45122021522"></a>0o200</strong>: The owner has the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b178532925211"><a name="en-us_topic_0000001144081254_b178532925211"></a><a name="en-us_topic_0000001144081254_b178532925211"></a>0o100</strong>: The owner has the execute permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1395053185319"><a name="en-us_topic_0000001144081254_b1395053185319"></a><a name="en-us_topic_0000001144081254_b1395053185319"></a>0o070</strong>: The user group has the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1464352085318"><a name="en-us_topic_0000001144081254_b1464352085318"></a><a name="en-us_topic_0000001144081254_b1464352085318"></a>0o040</strong>: The user group has the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1014323765312"><a name="en-us_topic_0000001144081254_b1014323765312"></a><a name="en-us_topic_0000001144081254_b1014323765312"></a>0o020</strong>: The user group has the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b1112355515312"><a name="en-us_topic_0000001144081254_b1112355515312"></a><a name="en-us_topic_0000001144081254_b1112355515312"></a>0o010</strong>: The user group has the execute permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b14875617145413"><a name="en-us_topic_0000001144081254_b14875617145413"></a><a name="en-us_topic_0000001144081254_b14875617145413"></a>0o007</strong>: Other users have the read, write, and execute permissions on the directory.</li><li><strong id="en-us_topic_0000001144081254_b3897834105415"><a name="en-us_topic_0000001144081254_b3897834105415"></a><a name="en-us_topic_0000001144081254_b3897834105415"></a>0o004</strong>: Other users have the read permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b32263523547"><a name="en-us_topic_0000001144081254_b32263523547"></a><a name="en-us_topic_0000001144081254_b32263523547"></a>0o002</strong>: Other users have the write permission on the directory.</li><li><strong id="en-us_topic_0000001144081254_b103919625512"><a name="en-us_topic_0000001144081254_b103919625512"></a><a name="en-us_topic_0000001144081254_b103919625512"></a>0o001</strong>: Other users have the execute permission on the directory.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
     fileio.fchmodSync(fd, mode);
    ```


## fileio.truncateSync<sup>7+</sup><a name="section2759113014567"></a>

truncateSync\(fpath: string, len?: number\): void

Synchronously truncates a file based on the file path.

-   Parameters

    <a name="table20760730115615"></a>
    <table><thead align="left"><tr id="row1676023035614"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p16760163085614"><a name="p16760163085614"></a><a name="p16760163085614"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="p7760530145610"><a name="p7760530145610"></a><a name="p7760530145610"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="p12761830125613"><a name="p12761830125613"></a><a name="p12761830125613"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="p976117306565"><a name="p976117306565"></a><a name="p976117306565"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5761123020566"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p62014513569"><a name="p62014513569"></a><a name="p62014513569"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p1120125175619"><a name="p1120125175619"></a><a name="p1120125175619"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p17201151145613"><a name="p17201151145613"></a><a name="p17201151145613"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p1320155155611"><a name="p1320155155611"></a><a name="p1320155155611"></a>Absolute path of the file to truncate.</p>
    </td>
    </tr>
    <tr id="row5762153019567"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1020351135614"><a name="p1020351135614"></a><a name="p1020351135614"></a>len</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p02075175616"><a name="p02075175616"></a><a name="p02075175616"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p620115112567"><a name="p620115112567"></a><a name="p620115112567"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p5924834141415"><a name="p5924834141415"></a><a name="p5924834141415"></a>File length, in bytes, after truncation.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    fileio.ftruncate(path, len);
    ```


## fileio.renameSync<sup>7+</sup><a name="section153395523116"></a>

renameSync\(oldPath: string, newPath: string\): void

Synchronously renames a file.

-   Parameters

    <a name="table1933195515319"></a>
    <table><thead align="left"><tr id="row734105543113"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p534555163120"><a name="p534555163120"></a><a name="p534555163120"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p63419553317"><a name="p63419553317"></a><a name="p63419553317"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1134255173110"><a name="p1134255173110"></a><a name="p1134255173110"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p4342551315"><a name="p4342551315"></a><a name="p4342551315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row63425513314"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p935105518312"><a name="p935105518312"></a><a name="p935105518312"></a>oldPath</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p193535583114"><a name="p193535583114"></a><a name="p193535583114"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p173565513112"><a name="p173565513112"></a><a name="p173565513112"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p168006618555"><a name="p168006618555"></a><a name="p168006618555"></a>Absolute path of the file to rename.</p>
    </td>
    </tr>
    <tr id="row183525593115"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1835185583116"><a name="p1835185583116"></a><a name="p1835185583116"></a>Newpath</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p63675553116"><a name="p63675553116"></a><a name="p63675553116"></a>String</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p23616551319"><a name="p23616551319"></a><a name="p23616551319"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p9801362555"><a name="p9801362555"></a><a name="p9801362555"></a>Absolute path of the file renamed.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.renameSync(oldpath, newpath);
    ```


## fileio.fsyncSync<sup>7+</sup><a name="section11863111112544"></a>

fsyncSync\(fd: number\): void

Synchronizes a file in synchronous mode. 

-   Parameters

    <a name="table159491205546"></a>
    <table><thead align="left"><tr id="row1995170195414"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p119529085410"><a name="p119529085410"></a><a name="p119529085410"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p129521607543"><a name="p129521607543"></a><a name="p129521607543"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p895270195410"><a name="p895270195410"></a><a name="p895270195410"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p69524012549"><a name="p69524012549"></a><a name="p69524012549"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row129528012540"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p295230155415"><a name="p295230155415"></a><a name="p295230155415"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p19953106545"><a name="p19953106545"></a><a name="p19953106545"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p139532010546"><a name="p139532010546"></a><a name="p139532010546"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p79461816143220"><a name="p79461816143220"></a><a name="p79461816143220"></a>File descriptor of the file to synchronize.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    fileio.fyncsSync(fd);
    ```


## fileio.chownSync<sup>7+</sup><a name="section1717097183517"></a>

chownSync\(path: string, uid: number, gid: number\): void

Synchronously changes the file owner based on its path.

-   Parameters

    <a name="table1262234217377"></a>
    <table><thead align="left"><tr id="row20773134243715"><th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.1"><p id="p1677374219379"><a name="p1677374219379"></a><a name="p1677374219379"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.2"><p id="p18774144214370"><a name="p18774144214370"></a><a name="p18774144214370"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.07%" id="mcps1.1.5.1.3"><p id="p77741142163719"><a name="p77741142163719"></a><a name="p77741142163719"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.71%" id="mcps1.1.5.1.4"><p id="p1277418426378"><a name="p1277418426378"></a><a name="p1277418426378"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20774742203717"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p16774124273718"><a name="p16774124273718"></a><a name="p16774124273718"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="p67741042183716"><a name="p67741042183716"></a><a name="p67741042183716"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p977404214375"><a name="p977404214375"></a><a name="p977404214375"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="p197811961391"><a name="p197811961391"></a><a name="p197811961391"></a>Absolute path of the target file.</p>
    </td>
    </tr>
    <tr id="row16774124283717"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p077414218379"><a name="p077414218379"></a><a name="p077414218379"></a>uid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="p13774184214377"><a name="p13774184214377"></a><a name="p13774184214377"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p187745428377"><a name="p187745428377"></a><a name="p187745428377"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="p577524263713"><a name="p577524263713"></a><a name="p577524263713"></a>New UID.</p>
    </td>
    </tr>
    <tr id="row11775114273711"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p47751542133715"><a name="p47751542133715"></a><a name="p47751542133715"></a>gid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="p67751742143712"><a name="p67751742143712"></a><a name="p67751742143712"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p19775154263711"><a name="p19775154263711"></a><a name="p19775154263711"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="p977544219372"><a name="p977544219372"></a><a name="p977544219372"></a>New GID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let stat = fileio.statSync(fpath)
    fileio.chownSync(path, stat.uid, stat.gid);
    ```


## fileio.createStreamSync<sup>7+</sup><a name="section1956102153713"></a>

createStreamSync\(path: string, mode: string\): Stream

Synchronously opens a stream based on the file path.

-   Parameters

    <a name="table125718213375"></a>
    <table><thead align="left"><tr id="row1857621153710"><th class="cellrowborder" valign="top" width="9.08%" id="mcps1.1.5.1.1"><p id="p125811212376"><a name="p125811212376"></a><a name="p125811212376"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.2"><p id="p0581121113714"><a name="p0581121113714"></a><a name="p0581121113714"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.01%" id="mcps1.1.5.1.3"><p id="p115832113375"><a name="p115832113375"></a><a name="p115832113375"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.97%" id="mcps1.1.5.1.4"><p id="p18589215373"><a name="p18589215373"></a><a name="p18589215373"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row125815214372"><td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.1 "><p id="p1696272519446"><a name="p1696272519446"></a><a name="p1696272519446"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.2 "><p id="p1396202534413"><a name="p1396202534413"></a><a name="p1396202534413"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p12962425144415"><a name="p12962425144415"></a><a name="p12962425144415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.97%" headers="mcps1.1.5.1.4 "><p id="p179623257441"><a name="p179623257441"></a><a name="p179623257441"></a>Absolute path of the target file.</p>
    </td>
    </tr>
    <tr id="row66780382444"><td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.1 "><p id="p1534517513466"><a name="p1534517513466"></a><a name="p1534517513466"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.2 "><p id="p18345115194618"><a name="p18345115194618"></a><a name="p18345115194618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p634505174615"><a name="p634505174615"></a><a name="p634505174615"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.97%" headers="mcps1.1.5.1.4 "><a name="ul141401653154518"></a><a name="ul141401653154518"></a><ul id="ul141401653154518"><li><strong id="b1617354153716"><a name="b1617354153716"></a><a name="b1617354153716"></a>r</strong>: Open a file for reading. The file must exist.</li><li><strong id="b95691158113716"><a name="b95691158113716"></a><a name="b95691158113716"></a>r+</strong>: Open a file for both reading and writing. The file must exist.</li><li><strong id="b725815573815"><a name="b725815573815"></a><a name="b725815573815"></a>w</strong>: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.</li><li><strong id="b38701934103812"><a name="b38701934103812"></a><a name="b38701934103812"></a>w+</strong>: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.</li><li><strong id="b10438104023813"><a name="b10438104023813"></a><a name="b10438104023813"></a>a</strong>: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).</li><li><strong id="b9537148183918"><a name="b9537148183918"></a><a name="b9537148183918"></a>a+</strong>: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table82181442114718"></a>
    <table><thead align="left"><tr id="row11377134234713"><th class="cellrowborder" valign="top" width="21.21%" id="mcps1.1.3.1.1"><p id="p5377144217477"><a name="p5377144217477"></a><a name="p5377144217477"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.79%" id="mcps1.1.3.1.2"><p id="p9377134211472"><a name="p9377134211472"></a><a name="p9377134211472"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row537794234717"><td class="cellrowborder" valign="top" width="21.21%" headers="mcps1.1.3.1.1 "><p id="p23779423475"><a name="p23779423475"></a><a name="p23779423475"></a><a href="#section109771933162919">Stream</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.79%" headers="mcps1.1.3.1.2 "><p id="p1349516611613"><a name="p1349516611613"></a><a name="p1349516611613"></a>Stream operation result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ss = fileio.createStream(path, "r+");
    ```


## fileio.fdopenStreamSync<sup>7+</sup><a name="section185160523522"></a>

fdopenStreamSync\(fd: number, mode: string\): Stream

Synchronously opens a stream based on the file descriptor.

-   Parameters

    <a name="table1151765215216"></a>
    <table><thead align="left"><tr id="row55171523524"><th class="cellrowborder" valign="top" width="9.09%" id="mcps1.1.5.1.1"><p id="p1852145275216"><a name="p1852145275216"></a><a name="p1852145275216"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.43%" id="mcps1.1.5.1.2"><p id="p9521175215213"><a name="p9521175215213"></a><a name="p9521175215213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.84%" id="mcps1.1.5.1.3"><p id="p1521115212529"><a name="p1521115212529"></a><a name="p1521115212529"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.64%" id="mcps1.1.5.1.4"><p id="p152119524526"><a name="p152119524526"></a><a name="p152119524526"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16522052105215"><td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.1 "><p id="p2052265216521"><a name="p2052265216521"></a><a name="p2052265216521"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.43%" headers="mcps1.1.5.1.2 "><p id="p15225527528"><a name="p15225527528"></a><a name="p15225527528"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.3 "><p id="p952225219523"><a name="p952225219523"></a><a name="p952225219523"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.64%" headers="mcps1.1.5.1.4 "><p id="p18953103165913"><a name="p18953103165913"></a><a name="p18953103165913"></a>File descriptor of the target file.</p>
    </td>
    </tr>
    <tr id="row115221452175217"><td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.1 "><p id="p9523155285212"><a name="p9523155285212"></a><a name="p9523155285212"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.43%" headers="mcps1.1.5.1.2 "><p id="p12523752105216"><a name="p12523752105216"></a><a name="p12523752105216"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.3 "><p id="p752315529529"><a name="p752315529529"></a><a name="p752315529529"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.64%" headers="mcps1.1.5.1.4 "><a name="ul141557537457"></a><a name="ul141557537457"></a><ul id="ul141557537457"><li><strong id="b194721144124112"><a name="b194721144124112"></a><a name="b194721144124112"></a>r</strong>: Open a file for reading. The file must exist.</li><li><strong id="b813654734113"><a name="b813654734113"></a><a name="b813654734113"></a>r+</strong>: Open a file for both reading and writing. The file must exist.</li><li><strong id="b446619504415"><a name="b446619504415"></a><a name="b446619504415"></a>w</strong>: Open a file for writing. If the file exists, clear its content. If the file does not exist, create a file.</li><li><strong id="b11214115411411"><a name="b11214115411411"></a><a name="b11214115411411"></a>w+</strong>: Open a file for both reading and writing. If the file exists, clear its content. If the file does not exist, create a file.</li><li><strong id="b2567145644113"><a name="b2567145644113"></a><a name="b2567145644113"></a>a</strong>: Open a file in append mode for writing at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).</li><li><strong id="b219318597412"><a name="b219318597412"></a><a name="b219318597412"></a>a+</strong>: Open a file in append mode for reading or updating at the end of the file. If the file does not exist, create a file. If the file exists, write data to the end of the file (the original content of the file is reserved).</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table9524115217526"></a>
    <table><thead align="left"><tr id="row17525125205211"><th class="cellrowborder" valign="top" width="21.21%" id="mcps1.1.3.1.1"><p id="p552585219523"><a name="p552585219523"></a><a name="p552585219523"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.79%" id="mcps1.1.3.1.2"><p id="p85251152105216"><a name="p85251152105216"></a><a name="p85251152105216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195259523527"><td class="cellrowborder" valign="top" width="21.21%" headers="mcps1.1.3.1.1 "><p id="p1552618520529"><a name="p1552618520529"></a><a name="p1552618520529"></a><a href="#section109771933162919">Stream</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.79%" headers="mcps1.1.3.1.2 "><p id="p10526165225216"><a name="p10526165225216"></a><a name="p10526165225216"></a>Stream operation result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ss = fileio.fdopenStreamSync(fd, "r+");
    ```


## fileio.fchownSync<sup>7+</sup><a name="section118619326160"></a>

fchownSync\(fd: number, uid: number, gid: number\): void

Synchronously changes the file owner based on the file descriptor.

-   Parameters

    <a name="table131861032131617"></a>
    <table><thead align="left"><tr id="row1187143214167"><th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.1"><p id="p1518763271613"><a name="p1518763271613"></a><a name="p1518763271613"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.2"><p id="p12187183210161"><a name="p12187183210161"></a><a name="p12187183210161"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.07%" id="mcps1.1.5.1.3"><p id="p918773211164"><a name="p918773211164"></a><a name="p918773211164"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.71%" id="mcps1.1.5.1.4"><p id="p718814323161"><a name="p718814323161"></a><a name="p718814323161"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12188113213167"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p218819328165"><a name="p218819328165"></a><a name="p218819328165"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="p1918814327166"><a name="p1918814327166"></a><a name="p1918814327166"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p131881732171618"><a name="p131881732171618"></a><a name="p131881732171618"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="p780313572596"><a name="p780313572596"></a><a name="p780313572596"></a>File descriptor of the target file.</p>
    </td>
    </tr>
    <tr id="row1618883221612"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p10188183218161"><a name="p10188183218161"></a><a name="p10188183218161"></a>uid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="p1918917326163"><a name="p1918917326163"></a><a name="p1918917326163"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p151892321164"><a name="p151892321164"></a><a name="p151892321164"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="p1418993241611"><a name="p1418993241611"></a><a name="p1418993241611"></a>New UID.</p>
    </td>
    </tr>
    <tr id="row5189143201618"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p618923201615"><a name="p618923201615"></a><a name="p618923201615"></a>gid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="p41891332131619"><a name="p41891332131619"></a><a name="p41891332131619"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p19397151815357"><a name="p19397151815357"></a><a name="p19397151815357"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="p47382016132620"><a name="p47382016132620"></a><a name="p47382016132620"></a>New GID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let stat = fileio.statSync(fpath);
    fileio.fchownSync(fd, stat.uid, stat.gid);
    ```


## Stat<a name="section7315249105116"></a>

Provides detailed file information. Before invoking a method of the  **Stat**  class, use the  [fileio.statSync](#section014281412198)  method to create a  **Stat**  instance.

### Attributes<a name="section23751576140"></a>

<a name="table728861911417"></a>
<table><thead align="left"><tr id="row62887198149"><th class="cellrowborder" valign="top" width="11.66%" id="mcps1.1.6.1.1"><p id="p928811911410"><a name="p928811911410"></a><a name="p928811911410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.1.6.1.2"><p id="p8288191916149"><a name="p8288191916149"></a><a name="p8288191916149"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.6.1.3"><p id="p14288131911418"><a name="p14288131911418"></a><a name="p14288131911418"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="6.63%" id="mcps1.1.6.1.4"><p id="p1928861921411"><a name="p1928861921411"></a><a name="p1928861921411"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="62.32%" id="mcps1.1.6.1.5"><p id="p728815191149"><a name="p728815191149"></a><a name="p728815191149"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row528891919142"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p3288191991414"><a name="p3288191991414"></a><a name="p3288191991414"></a>dev</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p3288121901418"><a name="p3288121901418"></a><a name="p3288121901418"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p182881319191414"><a name="p182881319191414"></a><a name="p182881319191414"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p1928801914148"><a name="p1928801914148"></a><a name="p1928801914148"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p1428811192144"><a name="p1428811192144"></a><a name="p1428811192144"></a>Major device number.</p>
</td>
</tr>
<tr id="row17111195311346"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p10288419131415"><a name="p10288419131415"></a><a name="p10288419131415"></a>ino</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p626711397284"><a name="p626711397284"></a><a name="p626711397284"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p1726743912812"><a name="p1726743912812"></a><a name="p1726743912812"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p326733942818"><a name="p326733942818"></a><a name="p326733942818"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p1228991915144"><a name="p1228991915144"></a><a name="p1228991915144"></a>File ID. Different files on the same device have different <strong id="b1559355543514"><a name="b1559355543514"></a><a name="b1559355543514"></a>ino</strong>s.</p>
</td>
</tr>
<tr id="row1918562340"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p209120568349"><a name="p209120568349"></a><a name="p209120568349"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p19794751113514"><a name="p19794751113514"></a><a name="p19794751113514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p17122185403519"><a name="p17122185403519"></a><a name="p17122185403519"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p11319595358"><a name="p11319595358"></a><a name="p11319595358"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p49119568343"><a name="p49119568343"></a><a name="p49119568343"></a>File type and permission. The first four bits indicate the file type, and the last 12 bits indicate the permission. The bit fields are described follows:</p>
<a name="ul3882122236"></a><a name="ul3882122236"></a><ul id="ul3882122236"><li><strong id="b8746161216397"><a name="b8746161216397"></a><a name="b8746161216397"></a>0o170000</strong>: mask used to obtain the file type.</li><li><strong id="b35003445396"><a name="b35003445396"></a><a name="b35003445396"></a>0o140000</strong>: The file is a socket.</li><li><strong id="b053171420401"><a name="b053171420401"></a><a name="b053171420401"></a>0o120000</strong>: The file is a symbolic link.</li><li><strong id="b12316132934117"><a name="b12316132934117"></a><a name="b12316132934117"></a>0o100000</strong>: The file is a regular file.</li><li><strong id="b1563937124117"><a name="b1563937124117"></a><a name="b1563937124117"></a>0o060000</strong>: The file is a block device.</li><li><strong id="b163315924217"><a name="b163315924217"></a><a name="b163315924217"></a>0o040000</strong>: The file is a directory.</li><li><strong id="b1672351834219"><a name="b1672351834219"></a><a name="b1672351834219"></a>0o020000</strong>: The file is a character device.</li><li><strong id="b18386193074219"><a name="b18386193074219"></a><a name="b18386193074219"></a>0o010000</strong>: The file is a named pipe (also known as a FIFO).</li><li><strong id="b858719619449"><a name="b858719619449"></a><a name="b858719619449"></a>0o0700</strong>: mask used to obtain owner permissions.</li><li><strong id="b02431527114419"><a name="b02431527114419"></a><a name="b02431527114419"></a>0o0400</strong>: The owner has the read permission on a regular file or a directory entry.</li><li><strong id="b1822815327446"><a name="b1822815327446"></a><a name="b1822815327446"></a>0o0200</strong>: The owner has the permission to write a regular file or has the permission to create and delete a directory entry.</li><li><strong id="b141011537164418"><a name="b141011537164418"></a><a name="b141011537164418"></a>0o0100</strong>: The owner has the permission to execute a regular file or has the permission to search for the specified path in a directory.</li><li><strong id="b1981942174419"><a name="b1981942174419"></a><a name="b1981942174419"></a>0o0070</strong>: mask used to obtain user group permissions.</li><li><strong id="b284317110453"><a name="b284317110453"></a><a name="b284317110453"></a>0o0040</strong>: The user group has the read permission on a regular file or a directory entry.</li><li><strong id="b1241742717324"><a name="b1241742717324"></a><a name="b1241742717324"></a>0o0020</strong>: The user group has the permission to write a regular file or has the permission to create and delete a directory entry.</li><li><strong id="b3250182344415"><a name="b3250182344415"></a><a name="b3250182344415"></a>0o0010</strong>: The user group has the permission to execute a regular file or has the permission to search for the specified path in a directory.</li><li><strong id="b1164713581363"><a name="b1164713581363"></a><a name="b1164713581363"></a>0o0007</strong>: mask used to obtain permissions of other users.</li><li><strong id="b88341496717"><a name="b88341496717"></a><a name="b88341496717"></a>0o0004</strong>: Other user groups have the read permission on a regular file or a directory entry.</li><li><strong id="b8109183915812"><a name="b8109183915812"></a><a name="b8109183915812"></a>0o0002</strong>: Other user groups have the permission to write a regular file or have the permission to create and delete a directory entry.</li><li><strong id="b0720521093"><a name="b0720521093"></a><a name="b0720521093"></a>0o0001</strong>: Other user groups have the permission to execute a regular file or have the permission to search for the specified path in a directory.</li></ul>
</td>
</tr>
<tr id="row11288719111417"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p179541859193413"><a name="p179541859193413"></a><a name="p179541859193413"></a>nlink</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p7812951193514"><a name="p7812951193514"></a><a name="p7812951193514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p912275418354"><a name="p912275418354"></a><a name="p912275418354"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p629559143510"><a name="p629559143510"></a><a name="p629559143510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p89331759153410"><a name="p89331759153410"></a><a name="p89331759153410"></a>Number of hard links in the file.</p>
</td>
</tr>
<tr id="row819112311341"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p1319117373415"><a name="p1319117373415"></a><a name="p1319117373415"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p178301751203519"><a name="p178301751203519"></a><a name="p178301751203519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p1075695613358"><a name="p1075695613358"></a><a name="p1075695613358"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p447125963517"><a name="p447125963517"></a><a name="p447125963517"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p31921839340"><a name="p31921839340"></a><a name="p31921839340"></a>ID of the file owner.</p>
</td>
</tr>
<tr id="row5209203920349"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p520953913418"><a name="p520953913418"></a><a name="p520953913418"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p1983814516358"><a name="p1983814516358"></a><a name="p1983814516358"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p1376416564354"><a name="p1376416564354"></a><a name="p1376416564354"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p135545943518"><a name="p135545943518"></a><a name="p135545943518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p820933917349"><a name="p820933917349"></a><a name="p820933917349"></a>ID of the user group of the file.</p>
</td>
</tr>
<tr id="row987683412343"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p15877734143414"><a name="p15877734143414"></a><a name="p15877734143414"></a>rdev</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p1684585183518"><a name="p1684585183518"></a><a name="p1684585183518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p97711556193513"><a name="p97711556193513"></a><a name="p97711556193513"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p196235953510"><a name="p196235953510"></a><a name="p196235953510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p1287793463415"><a name="p1287793463415"></a><a name="p1287793463415"></a>Minor device number.</p>
</td>
</tr>
<tr id="row1825315322344"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p92531132163419"><a name="p92531132163419"></a><a name="p92531132163419"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p485275173512"><a name="p485275173512"></a><a name="p485275173512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p177781156183511"><a name="p177781156183511"></a><a name="p177781156183511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p46995917359"><a name="p46995917359"></a><a name="p46995917359"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p82531332103418"><a name="p82531332103418"></a><a name="p82531332103418"></a>File size, in bytes. This parameter is valid only for regular files.</p>
</td>
</tr>
<tr id="row15419937153410"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p2042033717340"><a name="p2042033717340"></a><a name="p2042033717340"></a>blocks</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p16860135123512"><a name="p16860135123512"></a><a name="p16860135123512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p4785115611354"><a name="p4785115611354"></a><a name="p4785115611354"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p14761599359"><a name="p14761599359"></a><a name="p14761599359"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p134203373346"><a name="p134203373346"></a><a name="p134203373346"></a>Number of blocks occupied by a file. Each block is 512 bytes.</p>
</td>
</tr>
<tr id="row757852116342"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p105797211348"><a name="p105797211348"></a><a name="p105797211348"></a>atime</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p7867105133518"><a name="p7867105133518"></a><a name="p7867105133518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p14792145612357"><a name="p14792145612357"></a><a name="p14792145612357"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p18445903518"><a name="p18445903518"></a><a name="p18445903518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p7579202117348"><a name="p7579202117348"></a><a name="p7579202117348"></a>Time of the last access of file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.</p>
</td>
</tr>
<tr id="row7331132814341"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p23311828143417"><a name="p23311828143417"></a><a name="p23311828143417"></a>mtime</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p188741518359"><a name="p188741518359"></a><a name="p188741518359"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p2799115633517"><a name="p2799115633517"></a><a name="p2799115633517"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p14911659103510"><a name="p14911659103510"></a><a name="p14911659103510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p16332122819345"><a name="p16332122819345"></a><a name="p16332122819345"></a>Time of the last modification of the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.</p>
</td>
</tr>
<tr id="row1047914304341"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="p947913020342"><a name="p947913020342"></a><a name="p947913020342"></a>ctime</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="p4881155110359"><a name="p4881155110359"></a><a name="p4881155110359"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="p88061956113520"><a name="p88061956113520"></a><a name="p88061956113520"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="p109845983513"><a name="p109845983513"></a><a name="p109845983513"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="p347915303344"><a name="p347915303344"></a><a name="p347915303344"></a>Time of the last status change of the file. The value is the number of seconds elapsed since 00:00:00 on January 1, 1970.</p>
</td>
</tr>
</tbody>
</table>

### isBlockDevice<a name="section1041074182716"></a>

isBlockDevice\(\): boolean

Checks whether a directory entry is a block special file. A block special file supports access by block only, and it is cached when accessed.

-   Return values

    <a name="table1241064122713"></a>
    <table><thead align="left"><tr id="row5410174202717"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p14101249279"><a name="p14101249279"></a><a name="p14101249279"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p104104410278"><a name="p104104410278"></a><a name="p104104410278"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row164101142272"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p14410347278"><a name="p14410347278"></a><a name="p14410347278"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p3410947271"><a name="p3410947271"></a><a name="p3410947271"></a>Whether the directory entry is a block special file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isBLockDevice = fileio.statSync(path).isBlockDevice();
    ```


### isCharacterDevice<a name="section154111646277"></a>

isCharacterDevice\(\): boolean

Checks whether a directory entry is a character special file. A character special file supports random access, and it is not cached when accessed.

-   Return values

    <a name="table184113412717"></a>
    <table><thead align="left"><tr id="row94111942272"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p3411194132713"><a name="p3411194132713"></a><a name="p3411194132713"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p04116472711"><a name="p04116472711"></a><a name="p04116472711"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row194111544271"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p04111245272"><a name="p04111245272"></a><a name="p04111245272"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p041104132717"><a name="p041104132717"></a><a name="p041104132717"></a>Whether the directory entry is a character special file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isCharacterDevice = fileio.statSync(path).isCharacterDevice();
    ```


### isDirectory<a name="section2041115418271"></a>

isDirectory\(\): boolean

Checks whether a directory entry is a directory.

-   Return values

    <a name="table841113472714"></a>
    <table><thead align="left"><tr id="row14114412719"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p641194102713"><a name="p641194102713"></a><a name="p641194102713"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p104111847275"><a name="p104111847275"></a><a name="p104111847275"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5411164192714"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p24114412720"><a name="p24114412720"></a><a name="p24114412720"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p11412134132718"><a name="p11412134132718"></a><a name="p11412134132718"></a>Whether the directory entry is a directory.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isDirectory= fileio.statSync(path).isDirectory(); 
    ```


### isFIFO<a name="section1941244122719"></a>

isFIFO\(\): boolean

Checks whether a directory entry is a named pipe \(or FIFO\). Named pipes are used for inter-process communication.

-   Return values

    <a name="table11412845271"></a>
    <table><thead align="left"><tr id="row1641220416272"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1641210415279"><a name="p1641210415279"></a><a name="p1641210415279"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p3412548273"><a name="p3412548273"></a><a name="p3412548273"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row441224142717"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p741218402714"><a name="p741218402714"></a><a name="p741218402714"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p154121840272"><a name="p154121840272"></a><a name="p154121840272"></a>Whether the directory entry is a FIFO.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isFIFO= fileio.statSync(path).isFIFO(); 
    ```


### isFile<a name="section341284192710"></a>

isFile\(\): boolean

Checks whether a directory entry is a regular file.

-   Return values

    <a name="table10412124152720"></a>
    <table><thead align="left"><tr id="row34124412272"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p20412144152718"><a name="p20412144152718"></a><a name="p20412144152718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1941374112718"><a name="p1941374112718"></a><a name="p1941374112718"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2041384102711"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p184131045270"><a name="p184131045270"></a><a name="p184131045270"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1241316412277"><a name="p1241316412277"></a><a name="p1241316412277"></a>Whether the directory entry is a regular file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isFile= fileio.statSync(fpath).isFile();
    ```


### isSocket<a name="section154131413278"></a>

isSocket\(\): boolean

Checks whether a directory entry is a socket.

-   Return values

    <a name="table144131842271"></a>
    <table><thead align="left"><tr id="row1841304192716"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p154133422714"><a name="p154133422714"></a><a name="p154133422714"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p12413144275"><a name="p12413144275"></a><a name="p12413144275"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row441310418272"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p141319432718"><a name="p141319432718"></a><a name="p141319432718"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1541319482714"><a name="p1541319482714"></a><a name="p1541319482714"></a>Whether the directory entry is a socket.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isSocket = fileio.statSync(path).isSocket(); 
    ```


### isSymbolicLink<a name="section241317413274"></a>

isSymbolicLink\(\): boolean

Checks whether a directory entry is a symbolic link.

-   Return values

    <a name="table13413114122717"></a>
    <table><thead align="left"><tr id="row14147472718"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p14143472712"><a name="p14143472712"></a><a name="p14143472712"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1241417442710"><a name="p1241417442710"></a><a name="p1241417442710"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row134146472715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p64144418275"><a name="p64144418275"></a><a name="p64144418275"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p24142419279"><a name="p24142419279"></a><a name="p24142419279"></a>Whether the directory entry is a symbolic link.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let isSymbolicLink = fileio.statSync(path).isSymbolicLink(); 
    ```


## Stream<sup>7+</sup><a name="section109771933162919"></a>

File stream. Before calling a method of the  **Stream**  class, use the  [fileio.createStreamSync](#section1956102153713)  method to create a  **Stream**  instance.

### closeSync<sup>7+</sup><a name="section45453128524"></a>

closeSync\(\): void

Synchronously closes the stream.

-   Example

    ```
    let ss= fileio.createStreamSync(path);
    ss.closeSync();
    ```


### flushSync<sup>7+</sup><a name="section55111014181917"></a>

flushSync\(\): void

Synchronously flushes the stream.

-   Example

    ```
    let ss= fileio.createStreamSync(path);
    ss.flushSync();
    ```


### writeSync<sup>7+</sup><a name="section1959319151511"></a>

writeSync\(buffer: ArrayBuffer | string, options?:Object\): number

Synchronously writes data into the stream.

-   Parameters

    <a name="table25121946162517"></a>
    <table><thead align="left"><tr id="row1651474618253"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1514124642518"><a name="p1514124642518"></a><a name="p1514124642518"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="p1251494613252"><a name="p1251494613252"></a><a name="p1251494613252"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="p1151434632511"><a name="p1151434632511"></a><a name="p1151434632511"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="p18515124622520"><a name="p18515124622520"></a><a name="p18515124622520"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19516124618251"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p135161346172518"><a name="p135161346172518"></a><a name="p135161346172518"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p10516164619254"><a name="p10516164619254"></a><a name="p10516164619254"></a>ArrayBuffer | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p1551710465250"><a name="p1551710465250"></a><a name="p1551710465250"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p1551710467254"><a name="p1551710467254"></a><a name="p1551710467254"></a>A string or data from a buffer to be written to the file.</p>
    </td>
    </tr>
    <tr id="row551754611254"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p75171846182515"><a name="p75171846182515"></a><a name="p75171846182515"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="p2051844618257"><a name="p2051844618257"></a><a name="p2051844618257"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="p15518124612513"><a name="p15518124612513"></a><a name="p15518124612513"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p0518114652511"><a name="p0518114652511"></a><a name="p0518114652511"></a>The options are as follows:</p>
    <a name="ul6518134616252"></a><a name="ul6518134616252"></a><ul id="ul6518134616252"><li><strong id="b19328182652911"><a name="b19328182652911"></a><a name="b19328182652911"></a>offset</strong> (number): position of the data to write in reference to the start address of the data. It is optional. The default value is <strong id="b45510583333"><a name="b45510583333"></a><a name="b45510583333"></a>0</strong>.</li><li><strong id="b826164713325"><a name="b826164713325"></a><a name="b826164713325"></a>length</strong> (number): length of the data to write. It is optional. The default value is the buffer length minus the offset.</li><li><strong id="b37301526183312"><a name="b37301526183312"></a><a name="b37301526183312"></a>position</strong> (number): position of the data to be written in the file. It is optional. By default, data is written from the current position.</li><li><strong id="b1585192377"><a name="b1585192377"></a><a name="b1585192377"></a>encoding</strong> (string): format of the data to be encoded. You must set it when the data is a string. The default value is <strong id="b366012244"><a name="b366012244"></a><a name="b366012244"></a>utf-8</strong>. Only <strong id="b1902013443"><a name="b1902013443"></a><a name="b1902013443"></a>utf-8</strong> is supported.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table10520446162513"></a>
    <table><thead align="left"><tr id="row652084611250"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p125211946122520"><a name="p125211946122520"></a><a name="p125211946122520"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p6521146152512"><a name="p6521146152512"></a><a name="p6521146152512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2522174652520"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1522114617255"><a name="p1522114617255"></a><a name="p1522114617255"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p152234632520"><a name="p152234632520"></a><a name="p152234632520"></a>Length of the data written in the file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ss= fileio.createStreamSync(fpath,"r+");
    ss.writeSync("hello, world",{offset: 1,length: 5,position: 5,encoding :'utf-8'});
    ```


### readSync<sup>7+</sup><a name="section547517381167"></a>

readSync\(buffer: ArrayBuffer, options?: Object\): number

Synchronously reads data from the stream.

-   Parameters

    <a name="table834818156483"></a>
    <table><thead align="left"><tr id="row73491515164815"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p334911584819"><a name="p334911584819"></a><a name="p334911584819"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p12349141518486"><a name="p12349141518486"></a><a name="p12349141518486"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p143501153489"><a name="p143501153489"></a><a name="p143501153489"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p7350151519489"><a name="p7350151519489"></a><a name="p7350151519489"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16351191514489"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p53511515154811"><a name="p53511515154811"></a><a name="p53511515154811"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p193515154487"><a name="p193515154487"></a><a name="p193515154487"></a>ArrayBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p3351715114812"><a name="p3351715114812"></a><a name="p3351715114812"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1035220156485"><a name="p1035220156485"></a><a name="p1035220156485"></a>Buffer used for reading the file.</p>
    </td>
    </tr>
    <tr id="row143521315134810"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p635212150484"><a name="p635212150484"></a><a name="p635212150484"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p19352131524811"><a name="p19352131524811"></a><a name="p19352131524811"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p3353201520481"><a name="p3353201520481"></a><a name="p3353201520481"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1935319155480"><a name="p1935319155480"></a><a name="p1935319155480"></a>The options are as follows:</p>
    <a name="ul135351513487"></a><a name="ul135351513487"></a><ul id="ul135351513487"><li><strong id="b19784113218403"><a name="b19784113218403"></a><a name="b19784113218403"></a>offset</strong> (number): position of the buffer to which the data will be read in reference to the start address of the buffer. It is optional. The default value is <strong id="b42215584338"><a name="b42215584338"></a><a name="b42215584338"></a>0</strong>.</li><li><strong id="b481016913411"><a name="b481016913411"></a><a name="b481016913411"></a>length</strong> (number): length of the data to read. It is optional. The default value is the buffer length minus the offset.</li><li><strong id="b133081022184112"><a name="b133081022184112"></a><a name="b133081022184112"></a>position</strong> (number): position of the data to read in the file. It is optional. By default, data is read from the current position.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table5354151584811"></a>
    <table><thead align="left"><tr id="row18355161514482"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1355111514810"><a name="p1355111514810"></a><a name="p1355111514810"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p16355515194816"><a name="p16355515194816"></a><a name="p16355515194816"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row83551515164815"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1235651511484"><a name="p1235651511484"></a><a name="p1235651511484"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p835651513487"><a name="p835651513487"></a><a name="p835651513487"></a>Length of the data read.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ss = fileio.createStreamSync(fpath, "r+");
    ss.readSync(new ArrayBuffer(4096),{offset: 1,length: FILE_CONTENT.length,position: 5});
    ```


## Dir<a name="section189341937163212"></a>

Manages directories. Before calling a method of the  **Dir**  class, use the  [fileio.opendirSync](#section7741145112216)  method to create a  **Dir**  instance.

### readSync<a name="section10198204912710"></a>

readSync\(\): Dirent

Synchronously reads the next directory entry.

-   Return values

    <a name="table91985491870"></a>
    <table><thead align="left"><tr id="row131981491775"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p181983491370"><a name="p181983491370"></a><a name="p181983491370"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p10198114918711"><a name="p10198114918711"></a><a name="p10198114918711"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row121981049275"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1519812491376"><a name="p1519812491376"></a><a name="p1519812491376"></a><a href="#section92331215118">Dirent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1919818491075"><a name="p1919818491075"></a><a name="p1919818491075"></a>Directory entry read.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let dirent = dir.readSync();
    console.log(dirent.name);
    ```


### closeSync<a name="section1140053017119"></a>

closeSync\(\): void

Closes a directory. After a directory is closed, the file descriptor in  **Dir**  will be released and the directory entry cannot be read from  **Dir**.

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    dir.closeSync();
    ```


## Dirent<a name="section92331215118"></a>

Provides information about files and directories. Before calling a method of the  **Dirent**  class, use the  [readSync](#section10198204912710)  method to create a  **Dirent**  instance.

### Attributes<a name="section152315121617"></a>

<a name="table15231112515"></a>
<table><thead align="left"><tr id="row4232012216"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p5237121715"><a name="p5237121715"></a><a name="p5237121715"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p12313127119"><a name="p12313127119"></a><a name="p12313127119"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p192381217113"><a name="p192381217113"></a><a name="p192381217113"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p122320120117"><a name="p122320120117"></a><a name="p122320120117"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p62310121212"><a name="p62310121212"></a><a name="p62310121212"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row122317124115"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p323612718"><a name="p323612718"></a><a name="p323612718"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p152314121810"><a name="p152314121810"></a><a name="p152314121810"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1243123110"><a name="p1243123110"></a><a name="p1243123110"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p02410125111"><a name="p02410125111"></a><a name="p02410125111"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p924212212"><a name="p924212212"></a><a name="p924212212"></a>Directory entry name.</p>
</td>
</tr>
</tbody>
</table>

### isBlockDevice<a name="section121576105554"></a>

isBlockDevice\(\): boolean

Checks whether a directory entry is a block device file. A block special file supports access by block only, and it is cached when accessed.

-   Return values

    <a name="table1215761019558"></a>
    <table><thead align="left"><tr id="row515717101557"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p111571110175511"><a name="p111571110175511"></a><a name="p111571110175511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p17157110185519"><a name="p17157110185519"></a><a name="p17157110185519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row715701065518"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1115761035510"><a name="p1115761035510"></a><a name="p1115761035510"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p17157131020556"><a name="p17157131020556"></a><a name="p17157131020556"></a>Whether the directory entry is a block device file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isBLockDevice = dir.readSync().isBlockDevice();
    ```


### isCharacterDevice<a name="section20158121011550"></a>

isCharacterDevice\(\): boolean

Checks whether a directory entry is a character device file. A character special file supports random access, and it is not cached when accessed.

-   Return values

    <a name="table315818109559"></a>
    <table><thead align="left"><tr id="row71588108555"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1415812103558"><a name="p1415812103558"></a><a name="p1415812103558"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p7158151085510"><a name="p7158151085510"></a><a name="p7158151085510"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row715812103557"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p915871035513"><a name="p915871035513"></a><a name="p915871035513"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1415815107557"><a name="p1415815107557"></a><a name="p1415815107557"></a>Whether the directory entry is a character device file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isCharacterDevice = dir.readSync().isCharacterDevice(); 
    ```


### isDirectory<a name="section181581010165520"></a>

isDirectory\(\): boolean

Checks whether a directory entry is a directory.

-   Return values

    <a name="table51580109551"></a>
    <table><thead align="left"><tr id="row121581910155511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1615821065511"><a name="p1615821065511"></a><a name="p1615821065511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p111581104550"><a name="p111581104550"></a><a name="p111581104550"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1515851014554"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p15158121011553"><a name="p15158121011553"></a><a name="p15158121011553"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p0158151019551"><a name="p0158151019551"></a><a name="p0158151019551"></a>Whether the directory entry is a directory.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isDirectory = dir.readSync().isDirectory(); 
    ```


### isFIFO<a name="section615811095517"></a>

isFIFO\(\): boolean

Checks whether a directory entry is a named pipe \(or FIFO\). Named pipes are used for inter-process communication.

-   Return values

    <a name="table1015911017551"></a>
    <table><thead align="left"><tr id="row19159610125512"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p2159810135510"><a name="p2159810135510"></a><a name="p2159810135510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1315951055512"><a name="p1315951055512"></a><a name="p1315951055512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1159151085517"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p15159201018555"><a name="p15159201018555"></a><a name="p15159201018555"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1715912105558"><a name="p1715912105558"></a><a name="p1715912105558"></a>Whether the directory entry is a FIFO.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isFIFO = dir.readSync().isFIFO(); 
    ```


### isFile<a name="section91591310195520"></a>

isFile\(\): boolean

Checks whether a directory entry is a regular file.

-   Return values

    <a name="table10159710185513"></a>
    <table><thead align="left"><tr id="row13159210195517"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p31595100554"><a name="p31595100554"></a><a name="p31595100554"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p115919106551"><a name="p115919106551"></a><a name="p115919106551"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row715916105550"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p141591310105518"><a name="p141591310105518"></a><a name="p141591310105518"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1016041011559"><a name="p1016041011559"></a><a name="p1016041011559"></a>Whether the directory entry is a regular file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isFile = dir.readSync().isFile(); 
    ```


### isSocket<a name="section216031020555"></a>

isSocket\(\): boolean

Checks whether a directory entry is a socket.

-   Return values

    <a name="table7160131085517"></a>
    <table><thead align="left"><tr id="row6160101045511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p716015109555"><a name="p716015109555"></a><a name="p716015109555"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1316041075518"><a name="p1316041075518"></a><a name="p1316041075518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2016071005519"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p131601210115514"><a name="p131601210115514"></a><a name="p131601210115514"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p6160191085520"><a name="p6160191085520"></a><a name="p6160191085520"></a>Whether the directory entry is a socket.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isSocket = dir.readSync().isSocket(); 
    ```


### isSymbolicLink<a name="section1216010104553"></a>

isSymbolicLink\(\): boolean

Checks whether a directory entry is a symbolic link.

-   Return values

    <a name="table61602105554"></a>
    <table><thead align="left"><tr id="row191601510125517"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p121601510175510"><a name="p121601510175510"></a><a name="p121601510175510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p01611410175518"><a name="p01611410175518"></a><a name="p01611410175518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row716116106551"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p216171020556"><a name="p216171020556"></a><a name="p216171020556"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p131614106554"><a name="p131614106554"></a><a name="p131614106554"></a>Whether the directory entry is a symbolic link.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let dir = fileio.opendirSync(dpath);
    let isSymbolicLink = dir.readSync().isSymbolicLink();
    ```


