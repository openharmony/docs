# 文件管理<a name="ZH-CN_TOPIC_0000001209412151"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="zh-cn_topic_0000001208447259_s56d19203690d4782bfc74069abb6bd71"></a>

```
import fileio from '@ohos.fileio';
```

## 权限列表<a name="zh-cn_topic_0000001208447259_section11257113618419"></a>

无

## 使用说明<a name="zh-cn_topic_0000001208447259_section17323786612"></a>

使用该功能模块对文件/目录进行操作前，需要先获取其绝对路径。

<a name="zh-cn_topic_0000001208447259_table859142263817"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row165922243812"><th class="cellrowborder" valign="top" width="21.6%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001208447259_p20593226383"><a name="zh-cn_topic_0000001208447259_p20593226383"></a><a name="zh-cn_topic_0000001208447259_p20593226383"></a>目录类型</p>
</th>
<th class="cellrowborder" valign="top" width="53.57000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001208447259_p125911229389"><a name="zh-cn_topic_0000001208447259_p125911229389"></a><a name="zh-cn_topic_0000001208447259_p125911229389"></a>说明</p>
</th>
<th class="cellrowborder" valign="top" width="24.830000000000002%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001208447259_p1177425414331"><a name="zh-cn_topic_0000001208447259_p1177425414331"></a><a name="zh-cn_topic_0000001208447259_p1177425414331"></a>相关接口</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001208447259_row14604221386"><td class="cellrowborder" valign="top" width="21.6%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001208447259_p0605228382"><a name="zh-cn_topic_0000001208447259_p0605228382"></a><a name="zh-cn_topic_0000001208447259_p0605228382"></a>内部存储的缓存目录</p>
</td>
<td class="cellrowborder" valign="top" width="53.57000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001208447259_p76010229385"><a name="zh-cn_topic_0000001208447259_p76010229385"></a><a name="zh-cn_topic_0000001208447259_p76010229385"></a>可读写，随时可能清除，不保证持久性。一般用作下载临时目录或缓存目录。</p>
</td>
<td class="cellrowborder" valign="top" width="24.830000000000002%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001208447259_p1677525420331"><a name="zh-cn_topic_0000001208447259_p1677525420331"></a><a name="zh-cn_topic_0000001208447259_p1677525420331"></a>getCacheDir</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row20601622183813"><td class="cellrowborder" valign="top" width="21.6%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001208447259_p166062273813"><a name="zh-cn_topic_0000001208447259_p166062273813"></a><a name="zh-cn_topic_0000001208447259_p166062273813"></a>内部存储目录</p>
</td>
<td class="cellrowborder" valign="top" width="53.57000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001208447259_p19601522103813"><a name="zh-cn_topic_0000001208447259_p19601522103813"></a><a name="zh-cn_topic_0000001208447259_p19601522103813"></a>随应用卸载删除。</p>
</td>
<td class="cellrowborder" valign="top" width="24.830000000000002%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001208447259_p147753546339"><a name="zh-cn_topic_0000001208447259_p147753546339"></a><a name="zh-cn_topic_0000001208447259_p147753546339"></a>getFilesDir</p>
</td>
</tr>
</tbody>
</table>

“文件/目录绝对路径”=“应用目录路径”+“文件/目录名”

通过上述接口获取到应用目录路径dir，文件名为“xxx.txt”，文件所在绝对路径为：

```
let path = dir + "xxx.txt"
```

文件描述符fd：

```
let fd = fileio.openSync(path);
```

## fileio.statSync<a name="zh-cn_topic_0000001208447259_section014281412198"></a>

statSync\(path:string\): Stat

以同步方法获取文件的信息。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table21431314201914"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row15143151416194"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1214311146190"><a name="zh-cn_topic_0000001208447259_p1214311146190"></a><a name="zh-cn_topic_0000001208447259_p1214311146190"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p181441142194"><a name="zh-cn_topic_0000001208447259_p181441142194"></a><a name="zh-cn_topic_0000001208447259_p181441142194"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p514421417190"><a name="zh-cn_topic_0000001208447259_p514421417190"></a><a name="zh-cn_topic_0000001208447259_p514421417190"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p41441514181911"><a name="zh-cn_topic_0000001208447259_p41441514181911"></a><a name="zh-cn_topic_0000001208447259_p41441514181911"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row15144214191910"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p18144111417199"><a name="zh-cn_topic_0000001208447259_p18144111417199"></a><a name="zh-cn_topic_0000001208447259_p18144111417199"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p9144111415196"><a name="zh-cn_topic_0000001208447259_p9144111415196"></a><a name="zh-cn_topic_0000001208447259_p9144111415196"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p414410149199"><a name="zh-cn_topic_0000001208447259_p414410149199"></a><a name="zh-cn_topic_0000001208447259_p414410149199"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p106911349133411"><a name="zh-cn_topic_0000001208447259_p106911349133411"></a><a name="zh-cn_topic_0000001208447259_p106911349133411"></a>待获取文件的绝对路径。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="zh-cn_topic_0000001208447259_table131441014111919"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row19144101418196"><th class="cellrowborder" valign="top" width="22.93%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p614513143191"><a name="zh-cn_topic_0000001208447259_p614513143191"></a><a name="zh-cn_topic_0000001208447259_p614513143191"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.07000000000001%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p1514517145192"><a name="zh-cn_topic_0000001208447259_p1514517145192"></a><a name="zh-cn_topic_0000001208447259_p1514517145192"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row5145191421914"><td class="cellrowborder" valign="top" width="22.93%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p11145141481918"><a name="zh-cn_topic_0000001208447259_p11145141481918"></a><a name="zh-cn_topic_0000001208447259_p11145141481918"></a><a href="#zh-cn_topic_0000001208447259_section7315249105116">Stat</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="77.07000000000001%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p0145171491910"><a name="zh-cn_topic_0000001208447259_p0145171491910"></a><a name="zh-cn_topic_0000001208447259_p0145171491910"></a>表示文件的具体信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let stat = fileio.statSync(path);
    ```


## fileio.opendirSync<a name="zh-cn_topic_0000001208447259_section7741145112216"></a>

opendirSync\(path: string\): Dir

以同步方法打开文件目录。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table57421045122215"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row187421459221"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1974244516221"><a name="zh-cn_topic_0000001208447259_p1974244516221"></a><a name="zh-cn_topic_0000001208447259_p1974244516221"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p774294592214"><a name="zh-cn_topic_0000001208447259_p774294592214"></a><a name="zh-cn_topic_0000001208447259_p774294592214"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.81%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p137424459229"><a name="zh-cn_topic_0000001208447259_p137424459229"></a><a name="zh-cn_topic_0000001208447259_p137424459229"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.52%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p274212459222"><a name="zh-cn_topic_0000001208447259_p274212459222"></a><a name="zh-cn_topic_0000001208447259_p274212459222"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1674284511223"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p197431458224"><a name="zh-cn_topic_0000001208447259_p197431458224"></a><a name="zh-cn_topic_0000001208447259_p197431458224"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p774318454226"><a name="zh-cn_topic_0000001208447259_p774318454226"></a><a name="zh-cn_topic_0000001208447259_p774318454226"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.81%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p27437452221"><a name="zh-cn_topic_0000001208447259_p27437452221"></a><a name="zh-cn_topic_0000001208447259_p27437452221"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p144181369362"><a name="zh-cn_topic_0000001208447259_p144181369362"></a><a name="zh-cn_topic_0000001208447259_p144181369362"></a>待打开文件目录的绝对路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table1743134517224"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row14743145202214"><th class="cellrowborder" valign="top" width="22.93%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p127431245192220"><a name="zh-cn_topic_0000001208447259_p127431245192220"></a><a name="zh-cn_topic_0000001208447259_p127431245192220"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.07000000000001%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p137430454222"><a name="zh-cn_topic_0000001208447259_p137430454222"></a><a name="zh-cn_topic_0000001208447259_p137430454222"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row10743545202213"><td class="cellrowborder" valign="top" width="22.93%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p17445459222"><a name="zh-cn_topic_0000001208447259_p17445459222"></a><a name="zh-cn_topic_0000001208447259_p17445459222"></a><a href="#zh-cn_topic_0000001208447259_section189341937163212">Dir</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="77.07000000000001%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p16808111123618"><a name="zh-cn_topic_0000001208447259_p16808111123618"></a><a name="zh-cn_topic_0000001208447259_p16808111123618"></a>返回Dir对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(path);
    ```


## fileio.accessSync<a name="zh-cn_topic_0000001208447259_section9627104782212"></a>

accessSync\(path: string, mode?: number\): void

以同步方法检查当前进程是否可访问某文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table2062810475226"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row06284478229"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p56281747182210"><a name="zh-cn_topic_0000001208447259_p56281747182210"></a><a name="zh-cn_topic_0000001208447259_p56281747182210"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p17628144762211"><a name="zh-cn_topic_0000001208447259_p17628144762211"></a><a name="zh-cn_topic_0000001208447259_p17628144762211"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p156281547192217"><a name="zh-cn_topic_0000001208447259_p156281547192217"></a><a name="zh-cn_topic_0000001208447259_p156281547192217"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1862824714222"><a name="zh-cn_topic_0000001208447259_p1862824714222"></a><a name="zh-cn_topic_0000001208447259_p1862824714222"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row262816476222"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p196281347182217"><a name="zh-cn_topic_0000001208447259_p196281347182217"></a><a name="zh-cn_topic_0000001208447259_p196281347182217"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1462816472225"><a name="zh-cn_topic_0000001208447259_p1462816472225"></a><a name="zh-cn_topic_0000001208447259_p1462816472225"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p16629104792216"><a name="zh-cn_topic_0000001208447259_p16629104792216"></a><a name="zh-cn_topic_0000001208447259_p16629104792216"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p15367141141116"><a name="zh-cn_topic_0000001208447259_p15367141141116"></a><a name="zh-cn_topic_0000001208447259_p15367141141116"></a>待访问文件的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row204438428415"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p14444342104112"><a name="zh-cn_topic_0000001208447259_p14444342104112"></a><a name="zh-cn_topic_0000001208447259_p14444342104112"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p144413421414"><a name="zh-cn_topic_0000001208447259_p144413421414"></a><a name="zh-cn_topic_0000001208447259_p144413421414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p344414217412"><a name="zh-cn_topic_0000001208447259_p344414217412"></a><a name="zh-cn_topic_0000001208447259_p344414217412"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p642032043011"><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p642032043011"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p642032043011"></a>访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。</p>
    <p id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p164812171258"><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p164812171258"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p164812171258"></a>确认当前进程是否具有对应权限：</p>
    <a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul133214146476"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul133214146476"></a><ul id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul133214146476"><li>0：确认文件是否存在。</li></ul>
    <a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul2629143710241"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul2629143710241"></a><ul id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul2629143710241"><li>1：确认当前进程是否具有可执行权限。</li><li>2：确认当前进程是否具有写权限。</li><li>4：确认当前进程是否具有读权限。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.accessSync(path);
    ```


## fileio.closeSync<a name="zh-cn_topic_0000001208447259_section11518951152211"></a>

closeSync\(fd: number\): void

以同步方法关闭文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table165187512224"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row125192051162212"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p45191851192213"><a name="zh-cn_topic_0000001208447259_p45191851192213"></a><a name="zh-cn_topic_0000001208447259_p45191851192213"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.65%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p05198514224"><a name="zh-cn_topic_0000001208447259_p05198514224"></a><a name="zh-cn_topic_0000001208447259_p05198514224"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p9519125152210"><a name="zh-cn_topic_0000001208447259_p9519125152210"></a><a name="zh-cn_topic_0000001208447259_p9519125152210"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.22%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p6519115182214"><a name="zh-cn_topic_0000001208447259_p6519115182214"></a><a name="zh-cn_topic_0000001208447259_p6519115182214"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row45191051182219"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1851945110224"><a name="zh-cn_topic_0000001208447259_p1851945110224"></a><a name="zh-cn_topic_0000001208447259_p1851945110224"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.65%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p12519115116220"><a name="zh-cn_topic_0000001208447259_p12519115116220"></a><a name="zh-cn_topic_0000001208447259_p12519115116220"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p135191851142216"><a name="zh-cn_topic_0000001208447259_p135191851142216"></a><a name="zh-cn_topic_0000001208447259_p135191851142216"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.22%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p8519951152218"><a name="zh-cn_topic_0000001208447259_p8519951152218"></a><a name="zh-cn_topic_0000001208447259_p8519951152218"></a>待关闭文件的文件描述符。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.closeSync(fd);
    ```


## fileio.copyFileSync<a name="zh-cn_topic_0000001208447259_section752155117222"></a>

fileio.copyFileSync\(src: string, dest: string, mode?:number\): void

以同步方法复制文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table154591869574"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1146006185710"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p34601364573"><a name="zh-cn_topic_0000001208447259_p34601364573"></a><a name="zh-cn_topic_0000001208447259_p34601364573"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.470000000000002%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p114609615719"><a name="zh-cn_topic_0000001208447259_p114609615719"></a><a name="zh-cn_topic_0000001208447259_p114609615719"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.139999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p646056165718"><a name="zh-cn_topic_0000001208447259_p646056165718"></a><a name="zh-cn_topic_0000001208447259_p646056165718"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.36%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p194601269577"><a name="zh-cn_topic_0000001208447259_p194601269577"></a><a name="zh-cn_topic_0000001208447259_p194601269577"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row184604645713"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p11460863575"><a name="zh-cn_topic_0000001208447259_p11460863575"></a><a name="zh-cn_topic_0000001208447259_p11460863575"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p44603616575"><a name="zh-cn_topic_0000001208447259_p44603616575"></a><a name="zh-cn_topic_0000001208447259_p44603616575"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.139999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p64614615714"><a name="zh-cn_topic_0000001208447259_p64614615714"></a><a name="zh-cn_topic_0000001208447259_p64614615714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.36%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p16668162211811"><a name="zh-cn_topic_0000001208447259_p16668162211811"></a><a name="zh-cn_topic_0000001208447259_p16668162211811"></a>待复制文件的路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1646119675719"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1446117665719"><a name="zh-cn_topic_0000001208447259_p1446117665719"></a><a name="zh-cn_topic_0000001208447259_p1446117665719"></a>dest</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p2461765571"><a name="zh-cn_topic_0000001208447259_p2461765571"></a><a name="zh-cn_topic_0000001208447259_p2461765571"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.139999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p546166135717"><a name="zh-cn_topic_0000001208447259_p546166135717"></a><a name="zh-cn_topic_0000001208447259_p546166135717"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.36%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p3461136125713"><a name="zh-cn_topic_0000001208447259_p3461136125713"></a><a name="zh-cn_topic_0000001208447259_p3461136125713"></a>目标文件路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row134617611577"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p446110617571"><a name="zh-cn_topic_0000001208447259_p446110617571"></a><a name="zh-cn_topic_0000001208447259_p446110617571"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p2046218615711"><a name="zh-cn_topic_0000001208447259_p2046218615711"></a><a name="zh-cn_topic_0000001208447259_p2046218615711"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.139999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p14462116155713"><a name="zh-cn_topic_0000001208447259_p14462116155713"></a><a name="zh-cn_topic_0000001208447259_p14462116155713"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.36%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p14434113012329"><a name="zh-cn_topic_0000001208447259_p14434113012329"></a><a name="zh-cn_topic_0000001208447259_p14434113012329"></a>mode提供覆盖文件的选项，当前仅支持0，且默认为0。</p>
    <p id="zh-cn_topic_0000001208447259_p20644174510189"><a name="zh-cn_topic_0000001208447259_p20644174510189"></a><a name="zh-cn_topic_0000001208447259_p20644174510189"></a>0：完全覆盖目标文件，未覆盖部分将被裁切掉。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.copyFileSync(src, dest);
    ```


## fileio.mkdirSync<a name="zh-cn_topic_0000001208447259_section11419920164917"></a>

fileio.mkdirSync\(path: string, mode?: number\): void

以同步方法创建目录。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table19694163952110"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row126941539202111"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1769483917215"><a name="zh-cn_topic_0000001208447259_p1769483917215"></a><a name="zh-cn_topic_0000001208447259_p1769483917215"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p14694203922119"><a name="zh-cn_topic_0000001208447259_p14694203922119"></a><a name="zh-cn_topic_0000001208447259_p14694203922119"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p1069463922116"><a name="zh-cn_topic_0000001208447259_p1069463922116"></a><a name="zh-cn_topic_0000001208447259_p1069463922116"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1169483913211"><a name="zh-cn_topic_0000001208447259_p1169483913211"></a><a name="zh-cn_topic_0000001208447259_p1169483913211"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row3694639142118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p769473962120"><a name="zh-cn_topic_0000001208447259_p769473962120"></a><a name="zh-cn_topic_0000001208447259_p769473962120"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p12694153919217"><a name="zh-cn_topic_0000001208447259_p12694153919217"></a><a name="zh-cn_topic_0000001208447259_p12694153919217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p9694203932115"><a name="zh-cn_topic_0000001208447259_p9694203932115"></a><a name="zh-cn_topic_0000001208447259_p9694203932115"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p86940398219"><a name="zh-cn_topic_0000001208447259_p86940398219"></a><a name="zh-cn_topic_0000001208447259_p86940398219"></a>待创建目录的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1317135692118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p6171656102116"><a name="zh-cn_topic_0000001208447259_p6171656102116"></a><a name="zh-cn_topic_0000001208447259_p6171656102116"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1017155614211"><a name="zh-cn_topic_0000001208447259_p1017155614211"></a><a name="zh-cn_topic_0000001208447259_p1017155614211"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p1917110566213"><a name="zh-cn_topic_0000001208447259_p1917110566213"></a><a name="zh-cn_topic_0000001208447259_p1917110566213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001144081254_p1049717244222"><a name="zh-cn_topic_0000001144081254_p1049717244222"></a><a name="zh-cn_topic_0000001144081254_p1049717244222"></a>创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。</p>
    <a name="zh-cn_topic_0000001144081254_ul1958851172210"></a><a name="zh-cn_topic_0000001144081254_ul1958851172210"></a><ul id="zh-cn_topic_0000001144081254_ul1958851172210"><li>0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。</li><li>0o700：所有者具有读、写及可执行权限。</li><li>0o400：所有者具有读权限。</li><li>0o200：所有者具有写权限。</li><li>0o100：所有者具有可执行权限。</li><li>0o070：所有用户组具有读、写及可执行权限。</li><li>0o040：所有用户组具有读权限。</li><li>0o020：所有用户组具有写权限。</li><li>0o010：所有用户组具有可执行权限。</li><li>0o007：其余用户具有读、写及可执行权限。</li><li>0o004：其余用户具有读权限。</li><li>0o002：其余用户具有写权限。</li><li>0o001：其余用户具有可执行权限。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.mkdirSync(path);
    ```


## fileio.openSync<a name="zh-cn_topic_0000001208447259_section7431145402220"></a>

openSync\(path: string, flags?: number, mode?: number\): number

以同步方法打开文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table83121919193718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1231219198379"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p631213194378"><a name="zh-cn_topic_0000001208447259_p631213194378"></a><a name="zh-cn_topic_0000001208447259_p631213194378"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.67%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p1631261963711"><a name="zh-cn_topic_0000001208447259_p1631261963711"></a><a name="zh-cn_topic_0000001208447259_p1631261963711"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.260000000000002%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p2312111913373"><a name="zh-cn_topic_0000001208447259_p2312111913373"></a><a name="zh-cn_topic_0000001208447259_p2312111913373"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.58%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p10312171919378"><a name="zh-cn_topic_0000001208447259_p10312171919378"></a><a name="zh-cn_topic_0000001208447259_p10312171919378"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row12312101993717"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1313151963712"><a name="zh-cn_topic_0000001208447259_p1313151963712"></a><a name="zh-cn_topic_0000001208447259_p1313151963712"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.67%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p831311198371"><a name="zh-cn_topic_0000001208447259_p831311198371"></a><a name="zh-cn_topic_0000001208447259_p831311198371"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p6313161913379"><a name="zh-cn_topic_0000001208447259_p6313161913379"></a><a name="zh-cn_topic_0000001208447259_p6313161913379"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.58%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p143141819183716"><a name="zh-cn_topic_0000001208447259_p143141819183716"></a><a name="zh-cn_topic_0000001208447259_p143141819183716"></a>待打开文件的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1194614489373"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1494624819379"><a name="zh-cn_topic_0000001208447259_p1494624819379"></a><a name="zh-cn_topic_0000001208447259_p1494624819379"></a>flags</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.67%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p17946448103710"><a name="zh-cn_topic_0000001208447259_p17946448103710"></a><a name="zh-cn_topic_0000001208447259_p17946448103710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p139471148183717"><a name="zh-cn_topic_0000001208447259_p139471148183717"></a><a name="zh-cn_topic_0000001208447259_p139471148183717"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.58%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p0315175720016"><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p0315175720016"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p0315175720016"></a>打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：</p>
    <a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul13154571407"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul13154571407"></a><ul id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul13154571407"><li>0o0：只读打开。</li><li>0o1：只写打开。</li><li>0o2：读写打开。</li></ul>
    <p id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p431616571208"><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p431616571208"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p431616571208"></a>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：</p>
    <a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul73162575015"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul73162575015"></a><ul id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul73162575015"><li>0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数 mode。</li><li>0o200：如果追加了0o100选项，且文件已经存在，则出错。</li><li>0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。</li><li>0o2000：以追加方式打开，后续写将追加到文件末尾。</li><li>0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续 IO 进行非阻塞操作。</li><li>0o200000：如果path指向目录，则出错。</li><li>0o400000：如果path指向符号链接，则出错。</li><li>0o4010000：以同步IO的方式打开文件。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1452413112392"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p19524171115397"><a name="zh-cn_topic_0000001208447259_p19524171115397"></a><a name="zh-cn_topic_0000001208447259_p19524171115397"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.67%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p10524811193913"><a name="zh-cn_topic_0000001208447259_p10524811193913"></a><a name="zh-cn_topic_0000001208447259_p10524811193913"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p1752419113399"><a name="zh-cn_topic_0000001208447259_p1752419113399"></a><a name="zh-cn_topic_0000001208447259_p1752419113399"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.58%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p03171057708"><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p03171057708"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_p03171057708"></a>若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o666。</p>
    <a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul1554605585712"></a><a name="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul1554605585712"></a><ul id="zh-cn_topic_0000001208447259_zh-cn_topic_0000001144081254_ul1554605585712"><li>0o666：所有者具有读、写权限，所有用户组具有读、写权限，其余用户具有读、写权限。</li><li>0o700：所有者具有读、写及可执行权限。</li><li>0o400：所有者具有读权限。</li><li>0o200：所有者具有写权限。</li><li>0o100：所有者具有可执行权限。</li><li>0o070：所有用户组具有读、写及可执行权限。</li><li>0o040：所有用户组具有读权限。</li><li>0o020：所有用户组具有写权限。</li><li>0o010：所有用户组具有可执行权限。</li><li>0o007：其余用户具有读、写及可执行权限。</li><li>0o004：其余用户具有读权限。</li><li>0o002：其余用户具有写权限。</li><li>0o001：其余用户具有可执行权限。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table10314619113717"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1131431917373"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p14314201914373"><a name="zh-cn_topic_0000001208447259_p14314201914373"></a><a name="zh-cn_topic_0000001208447259_p14314201914373"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p2314119103714"><a name="zh-cn_topic_0000001208447259_p2314119103714"></a><a name="zh-cn_topic_0000001208447259_p2314119103714"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1314151920378"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p163146199374"><a name="zh-cn_topic_0000001208447259_p163146199374"></a><a name="zh-cn_topic_0000001208447259_p163146199374"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p8314151912376"><a name="zh-cn_topic_0000001208447259_p8314151912376"></a><a name="zh-cn_topic_0000001208447259_p8314151912376"></a>打开文件的文件描述符。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.openSync(path);
    ```


## fileio.readSync<a name="zh-cn_topic_0000001208447259_section1682515612227"></a>

readSync\(fd: number, buffer: ArrayBuffer, options?: Object\): number

以同步方法从文件读取数据。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table17441612151511"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row124410129159"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1944119126156"><a name="zh-cn_topic_0000001208447259_p1944119126156"></a><a name="zh-cn_topic_0000001208447259_p1944119126156"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p14411312121519"><a name="zh-cn_topic_0000001208447259_p14411312121519"></a><a name="zh-cn_topic_0000001208447259_p14411312121519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p9441101241511"><a name="zh-cn_topic_0000001208447259_p9441101241511"></a><a name="zh-cn_topic_0000001208447259_p9441101241511"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1744111125158"><a name="zh-cn_topic_0000001208447259_p1744111125158"></a><a name="zh-cn_topic_0000001208447259_p1744111125158"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1644111211159"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p344191214156"><a name="zh-cn_topic_0000001208447259_p344191214156"></a><a name="zh-cn_topic_0000001208447259_p344191214156"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p7441121219152"><a name="zh-cn_topic_0000001208447259_p7441121219152"></a><a name="zh-cn_topic_0000001208447259_p7441121219152"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p20441121231516"><a name="zh-cn_topic_0000001208447259_p20441121231516"></a><a name="zh-cn_topic_0000001208447259_p20441121231516"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1044214122155"><a name="zh-cn_topic_0000001208447259_p1044214122155"></a><a name="zh-cn_topic_0000001208447259_p1044214122155"></a>待读取文件的文件描述符。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1944211231512"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p134429128159"><a name="zh-cn_topic_0000001208447259_p134429128159"></a><a name="zh-cn_topic_0000001208447259_p134429128159"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p184424121155"><a name="zh-cn_topic_0000001208447259_p184424121155"></a><a name="zh-cn_topic_0000001208447259_p184424121155"></a>ArrayBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p144214127151"><a name="zh-cn_topic_0000001208447259_p144214127151"></a><a name="zh-cn_topic_0000001208447259_p144214127151"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p6442181219155"><a name="zh-cn_topic_0000001208447259_p6442181219155"></a><a name="zh-cn_topic_0000001208447259_p6442181219155"></a>用于读取文件的缓冲区。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1444211281512"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p84421812181516"><a name="zh-cn_topic_0000001208447259_p84421812181516"></a><a name="zh-cn_topic_0000001208447259_p84421812181516"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1544217123151"><a name="zh-cn_topic_0000001208447259_p1544217123151"></a><a name="zh-cn_topic_0000001208447259_p1544217123151"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p124421812131517"><a name="zh-cn_topic_0000001208447259_p124421812131517"></a><a name="zh-cn_topic_0000001208447259_p124421812131517"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p15442141216157"><a name="zh-cn_topic_0000001208447259_p15442141216157"></a><a name="zh-cn_topic_0000001208447259_p15442141216157"></a>支持如下选项：</p>
    <a name="zh-cn_topic_0000001208447259_ul1644261221514"></a><a name="zh-cn_topic_0000001208447259_ul1644261221514"></a><ul id="zh-cn_topic_0000001208447259_ul1644261221514"><li>offset，number 类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。</li><li>length，number 类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。</li><li>position，number 类型，表示期望读取文件的位置。可选，默认从当前位置开始读。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table13442121215151"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1844261201511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p10442101212158"><a name="zh-cn_topic_0000001208447259_p10442101212158"></a><a name="zh-cn_topic_0000001208447259_p10442101212158"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p1444241251511"><a name="zh-cn_topic_0000001208447259_p1444241251511"></a><a name="zh-cn_topic_0000001208447259_p1444241251511"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row104429125154"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p14422012101515"><a name="zh-cn_topic_0000001208447259_p14422012101515"></a><a name="zh-cn_topic_0000001208447259_p14422012101515"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p244314126154"><a name="zh-cn_topic_0000001208447259_p244314126154"></a><a name="zh-cn_topic_0000001208447259_p244314126154"></a>实际读取的长度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let fd = fileio.openSync(path, 0o2);
    let buf = new ArrayBuffer(4096);
    fileio.readSync(fd, buf);
    console.log(String.fromCharCode.apply(null, new Uint8Array(buf)));
    ```


## fileio.rmdirSync<a name="zh-cn_topic_0000001208447259_section1420012610423"></a>

rmdirSync\(path: string\): void

以同步方法删除目录。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table172741614151417"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row4274514181420"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p7274161461418"><a name="zh-cn_topic_0000001208447259_p7274161461418"></a><a name="zh-cn_topic_0000001208447259_p7274161461418"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p0274111414143"><a name="zh-cn_topic_0000001208447259_p0274111414143"></a><a name="zh-cn_topic_0000001208447259_p0274111414143"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p1127471451416"><a name="zh-cn_topic_0000001208447259_p1127471451416"></a><a name="zh-cn_topic_0000001208447259_p1127471451416"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1827414149145"><a name="zh-cn_topic_0000001208447259_p1827414149145"></a><a name="zh-cn_topic_0000001208447259_p1827414149145"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row15274161461412"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1027421431410"><a name="zh-cn_topic_0000001208447259_p1027421431410"></a><a name="zh-cn_topic_0000001208447259_p1027421431410"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p182741014181418"><a name="zh-cn_topic_0000001208447259_p182741014181418"></a><a name="zh-cn_topic_0000001208447259_p182741014181418"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p14274161431417"><a name="zh-cn_topic_0000001208447259_p14274161431417"></a><a name="zh-cn_topic_0000001208447259_p14274161431417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p827414142144"><a name="zh-cn_topic_0000001208447259_p827414142144"></a><a name="zh-cn_topic_0000001208447259_p827414142144"></a>待删除目录的绝对路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.rmdirSync(path);
    ```


## fileio.unlinkSync<a name="zh-cn_topic_0000001208447259_section1659112267472"></a>

unlinkSync\(path: string\): void

以同步方法删除文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table10902246174"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row13903174617711"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p99031146778"><a name="zh-cn_topic_0000001208447259_p99031146778"></a><a name="zh-cn_topic_0000001208447259_p99031146778"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p79034461674"><a name="zh-cn_topic_0000001208447259_p79034461674"></a><a name="zh-cn_topic_0000001208447259_p79034461674"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p149030464710"><a name="zh-cn_topic_0000001208447259_p149030464710"></a><a name="zh-cn_topic_0000001208447259_p149030464710"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1790334610714"><a name="zh-cn_topic_0000001208447259_p1790334610714"></a><a name="zh-cn_topic_0000001208447259_p1790334610714"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row49035468712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1390316468713"><a name="zh-cn_topic_0000001208447259_p1390316468713"></a><a name="zh-cn_topic_0000001208447259_p1390316468713"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p2090384611710"><a name="zh-cn_topic_0000001208447259_p2090384611710"></a><a name="zh-cn_topic_0000001208447259_p2090384611710"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p159031846575"><a name="zh-cn_topic_0000001208447259_p159031846575"></a><a name="zh-cn_topic_0000001208447259_p159031846575"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p7903124619711"><a name="zh-cn_topic_0000001208447259_p7903124619711"></a><a name="zh-cn_topic_0000001208447259_p7903124619711"></a>待删除文件的绝对路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.unlinkSync(path);
    ```


## fileio.writeSync<a name="zh-cn_topic_0000001208447259_section144923345218"></a>

writeSync\(fd: number, buffer: ArrayBuffer | string, options?:Object\): number

以同步方法将数据写入文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table13943194014108"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row6944940101012"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p149447402107"><a name="zh-cn_topic_0000001208447259_p149447402107"></a><a name="zh-cn_topic_0000001208447259_p149447402107"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p1944184011102"><a name="zh-cn_topic_0000001208447259_p1944184011102"></a><a name="zh-cn_topic_0000001208447259_p1944184011102"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p11944174001010"><a name="zh-cn_topic_0000001208447259_p11944174001010"></a><a name="zh-cn_topic_0000001208447259_p11944174001010"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p894554017109"><a name="zh-cn_topic_0000001208447259_p894554017109"></a><a name="zh-cn_topic_0000001208447259_p894554017109"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row199459404101"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p16945440121019"><a name="zh-cn_topic_0000001208447259_p16945440121019"></a><a name="zh-cn_topic_0000001208447259_p16945440121019"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p194517403109"><a name="zh-cn_topic_0000001208447259_p194517403109"></a><a name="zh-cn_topic_0000001208447259_p194517403109"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p14945204017104"><a name="zh-cn_topic_0000001208447259_p14945204017104"></a><a name="zh-cn_topic_0000001208447259_p14945204017104"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p094584020101"><a name="zh-cn_topic_0000001208447259_p094584020101"></a><a name="zh-cn_topic_0000001208447259_p094584020101"></a>待写入文件的文件描述符。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row7946174015104"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p094610401102"><a name="zh-cn_topic_0000001208447259_p094610401102"></a><a name="zh-cn_topic_0000001208447259_p094610401102"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p5946144012109"><a name="zh-cn_topic_0000001208447259_p5946144012109"></a><a name="zh-cn_topic_0000001208447259_p5946144012109"></a>ArrayBuffer | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p1794674018108"><a name="zh-cn_topic_0000001208447259_p1794674018108"></a><a name="zh-cn_topic_0000001208447259_p1794674018108"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p129466403102"><a name="zh-cn_topic_0000001208447259_p129466403102"></a><a name="zh-cn_topic_0000001208447259_p129466403102"></a>待写入文件的数据，可来自缓冲区或字符串。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row16946204012103"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1946840141012"><a name="zh-cn_topic_0000001208447259_p1946840141012"></a><a name="zh-cn_topic_0000001208447259_p1946840141012"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p69477400104"><a name="zh-cn_topic_0000001208447259_p69477400104"></a><a name="zh-cn_topic_0000001208447259_p69477400104"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p4947164021013"><a name="zh-cn_topic_0000001208447259_p4947164021013"></a><a name="zh-cn_topic_0000001208447259_p4947164021013"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p16947154021011"><a name="zh-cn_topic_0000001208447259_p16947154021011"></a><a name="zh-cn_topic_0000001208447259_p16947154021011"></a>支持如下选项：</p>
    <a name="zh-cn_topic_0000001208447259_ul14947144014103"></a><a name="zh-cn_topic_0000001208447259_ul14947144014103"></a><ul id="zh-cn_topic_0000001208447259_ul14947144014103"><li>offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。</li><li>length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。</li><li>position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。</li><li>encoding，string类型，当数据是 string 类型时有效，表示数据的编码方式，默认 'utf-8'，仅支持 'utf-8'。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table13948204031017"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row4948204031017"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p11948540191013"><a name="zh-cn_topic_0000001208447259_p11948540191013"></a><a name="zh-cn_topic_0000001208447259_p11948540191013"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p894954091017"><a name="zh-cn_topic_0000001208447259_p894954091017"></a><a name="zh-cn_topic_0000001208447259_p894954091017"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row149491940101010"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p20949184091011"><a name="zh-cn_topic_0000001208447259_p20949184091011"></a><a name="zh-cn_topic_0000001208447259_p20949184091011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1494984011100"><a name="zh-cn_topic_0000001208447259_p1494984011100"></a><a name="zh-cn_topic_0000001208447259_p1494984011100"></a>实际写入的长度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let fd = fileio.openSync(path, 0o102, 0o666);
    fileio.writeSync(fd, "hello, world");
    ```


## fileio.chmodSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section199971741181414"></a>

chmodSync\(path: string, mode: number\): void

以同步方法基于文件路径改变文件权限。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table7498121613156"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row2498151631511"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p4498171610155"><a name="zh-cn_topic_0000001208447259_p4498171610155"></a><a name="zh-cn_topic_0000001208447259_p4498171610155"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.58%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p13498151611512"><a name="zh-cn_topic_0000001208447259_p13498151611512"></a><a name="zh-cn_topic_0000001208447259_p13498151611512"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.37%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p1849841621512"><a name="zh-cn_topic_0000001208447259_p1849841621512"></a><a name="zh-cn_topic_0000001208447259_p1849841621512"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.23%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p104981716121516"><a name="zh-cn_topic_0000001208447259_p104981716121516"></a><a name="zh-cn_topic_0000001208447259_p104981716121516"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row94981416121519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p749991610154"><a name="zh-cn_topic_0000001208447259_p749991610154"></a><a name="zh-cn_topic_0000001208447259_p749991610154"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.58%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p3499151613151"><a name="zh-cn_topic_0000001208447259_p3499151613151"></a><a name="zh-cn_topic_0000001208447259_p3499151613151"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.37%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p11499101618154"><a name="zh-cn_topic_0000001208447259_p11499101618154"></a><a name="zh-cn_topic_0000001208447259_p11499101618154"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.23%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p174992161153"><a name="zh-cn_topic_0000001208447259_p174992161153"></a><a name="zh-cn_topic_0000001208447259_p174992161153"></a>待改变文件权限的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1349981621513"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p6499191661513"><a name="zh-cn_topic_0000001208447259_p6499191661513"></a><a name="zh-cn_topic_0000001208447259_p6499191661513"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.58%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1649961671518"><a name="zh-cn_topic_0000001208447259_p1649961671518"></a><a name="zh-cn_topic_0000001208447259_p1649961671518"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.37%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p11499121631517"><a name="zh-cn_topic_0000001208447259_p11499121631517"></a><a name="zh-cn_topic_0000001208447259_p11499121631517"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.23%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001144081254_p598318203228"><a name="zh-cn_topic_0000001144081254_p598318203228"></a><a name="zh-cn_topic_0000001144081254_p598318203228"></a>改变文件权限，可给定如下权限，以按位或的方式追加权限。</p>
    <a name="zh-cn_topic_0000001144081254_ul14983162018222"></a><a name="zh-cn_topic_0000001144081254_ul14983162018222"></a><ul id="zh-cn_topic_0000001144081254_ul14983162018222"><li>0o700：所有者具有读、写及可执行权限。</li><li>0o400：所有者具有读权限。</li><li>0o200：所有者具有写权限。</li><li>0o100：所有者具有可执行权限。</li><li>0o070：所有用户组具有读、写及可执行权限。</li><li>0o040：所有用户组具有读权限。</li><li>0o020：所有用户组具有写权限。</li><li>0o010：所有用户组具有可执行权限。</li><li>0o007：其余用户具有读、写及可执行权限。</li><li>0o004：其余用户具有读权限。</li><li>0o002：其余用户具有写权限。</li><li>0o001：其余用户具有可执行权限。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.chmodSync(fpath, mode);
    ```


## fileio.fstatSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section14821537102219"></a>

fstatSync\(fd: number\): Stat

以同步方法基于文件描述符获取文件状态信息。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table1318758152213"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row431955802216"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p931935832210"><a name="zh-cn_topic_0000001208447259_p931935832210"></a><a name="zh-cn_topic_0000001208447259_p931935832210"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p1431925872217"><a name="zh-cn_topic_0000001208447259_p1431925872217"></a><a name="zh-cn_topic_0000001208447259_p1431925872217"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p632065812228"><a name="zh-cn_topic_0000001208447259_p632065812228"></a><a name="zh-cn_topic_0000001208447259_p632065812228"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p143202586223"><a name="zh-cn_topic_0000001208447259_p143202586223"></a><a name="zh-cn_topic_0000001208447259_p143202586223"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1432015811226"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p11321115832213"><a name="zh-cn_topic_0000001208447259_p11321115832213"></a><a name="zh-cn_topic_0000001208447259_p11321115832213"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p113211588229"><a name="zh-cn_topic_0000001208447259_p113211588229"></a><a name="zh-cn_topic_0000001208447259_p113211588229"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p113211658192212"><a name="zh-cn_topic_0000001208447259_p113211658192212"></a><a name="zh-cn_topic_0000001208447259_p113211658192212"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1032135842220"><a name="zh-cn_topic_0000001208447259_p1032135842220"></a><a name="zh-cn_topic_0000001208447259_p1032135842220"></a>待获取文件的文件描述符。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="zh-cn_topic_0000001208447259_table1432119586228"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row232195820224"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p4322658182215"><a name="zh-cn_topic_0000001208447259_p4322658182215"></a><a name="zh-cn_topic_0000001208447259_p4322658182215"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p03222058162215"><a name="zh-cn_topic_0000001208447259_p03222058162215"></a><a name="zh-cn_topic_0000001208447259_p03222058162215"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1032275817222"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p75973654013"><a name="zh-cn_topic_0000001208447259_p75973654013"></a><a name="zh-cn_topic_0000001208447259_p75973654013"></a>Promise&lt;Stat&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p12597269404"><a name="zh-cn_topic_0000001208447259_p12597269404"></a><a name="zh-cn_topic_0000001208447259_p12597269404"></a>表示文件的具体信息。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    let fd = fileio.openSync(path);
    let stat = fileio.fstatSync(fd);
    ```


## fileio.ftruncateSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section514613516446"></a>

ftruncateSync\(fd: number, len?: number\): void

以同步方法基于文件描述符截断文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table171461935114413"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row15147113510445"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1614753518444"><a name="zh-cn_topic_0000001208447259_p1614753518444"></a><a name="zh-cn_topic_0000001208447259_p1614753518444"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p1314783574414"><a name="zh-cn_topic_0000001208447259_p1314783574414"></a><a name="zh-cn_topic_0000001208447259_p1314783574414"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p3147133512441"><a name="zh-cn_topic_0000001208447259_p3147133512441"></a><a name="zh-cn_topic_0000001208447259_p3147133512441"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1514753513442"><a name="zh-cn_topic_0000001208447259_p1514753513442"></a><a name="zh-cn_topic_0000001208447259_p1514753513442"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1514716354442"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p94460314520"><a name="zh-cn_topic_0000001208447259_p94460314520"></a><a name="zh-cn_topic_0000001208447259_p94460314520"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1044616334513"><a name="zh-cn_topic_0000001208447259_p1044616334513"></a><a name="zh-cn_topic_0000001208447259_p1044616334513"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p15446639458"><a name="zh-cn_topic_0000001208447259_p15446639458"></a><a name="zh-cn_topic_0000001208447259_p15446639458"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p2446103114518"><a name="zh-cn_topic_0000001208447259_p2446103114518"></a><a name="zh-cn_topic_0000001208447259_p2446103114518"></a>待截断文件的文件描述符。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row614812359442"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1644610344516"><a name="zh-cn_topic_0000001208447259_p1644610344516"></a><a name="zh-cn_topic_0000001208447259_p1644610344516"></a>len</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p184461931459"><a name="zh-cn_topic_0000001208447259_p184461931459"></a><a name="zh-cn_topic_0000001208447259_p184461931459"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p64469311451"><a name="zh-cn_topic_0000001208447259_p64469311451"></a><a name="zh-cn_topic_0000001208447259_p64469311451"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1946656171316"><a name="zh-cn_topic_0000001208447259_p1946656171316"></a><a name="zh-cn_topic_0000001208447259_p1946656171316"></a>文件截断后的长度，以字节为单位。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
     fileio.ftruncate(fd, len);
    ```


## fileio.fchmodSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section16345147182418"></a>

fchmodSync\(existingPath: string, newPath: string\): void

以同步方法基于文件描述符改变文件权限。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table134612718249"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row934607172416"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p63468792413"><a name="zh-cn_topic_0000001208447259_p63468792413"></a><a name="zh-cn_topic_0000001208447259_p63468792413"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p1234719722417"><a name="zh-cn_topic_0000001208447259_p1234719722417"></a><a name="zh-cn_topic_0000001208447259_p1234719722417"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p93476716246"><a name="zh-cn_topic_0000001208447259_p93476716246"></a><a name="zh-cn_topic_0000001208447259_p93476716246"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p83472714248"><a name="zh-cn_topic_0000001208447259_p83472714248"></a><a name="zh-cn_topic_0000001208447259_p83472714248"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1534710711248"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p634719710243"><a name="zh-cn_topic_0000001208447259_p634719710243"></a><a name="zh-cn_topic_0000001208447259_p634719710243"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p17348147122417"><a name="zh-cn_topic_0000001208447259_p17348147122417"></a><a name="zh-cn_topic_0000001208447259_p17348147122417"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p15348207152417"><a name="zh-cn_topic_0000001208447259_p15348207152417"></a><a name="zh-cn_topic_0000001208447259_p15348207152417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p91788493584"><a name="zh-cn_topic_0000001208447259_p91788493584"></a><a name="zh-cn_topic_0000001208447259_p91788493584"></a>待改变文件的文件描述符。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row103484712416"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1834817711241"><a name="zh-cn_topic_0000001208447259_p1834817711241"></a><a name="zh-cn_topic_0000001208447259_p1834817711241"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p13481762412"><a name="zh-cn_topic_0000001208447259_p13481762412"></a><a name="zh-cn_topic_0000001208447259_p13481762412"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p83484702415"><a name="zh-cn_topic_0000001208447259_p83484702415"></a><a name="zh-cn_topic_0000001208447259_p83484702415"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001144081254_p19508174455411"><a name="zh-cn_topic_0000001144081254_p19508174455411"></a><a name="zh-cn_topic_0000001144081254_p19508174455411"></a>若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。</p>
    <a name="zh-cn_topic_0000001144081254_ul74723715117"></a><a name="zh-cn_topic_0000001144081254_ul74723715117"></a><ul id="zh-cn_topic_0000001144081254_ul74723715117"><li>0o700：所有者具有读、写及可执行权限。</li><li>0o400：所有者具有读权限。</li><li>0o200：所有者具有写权限。</li><li>0o100：所有者具有可执行权限。</li><li>0o070：所有用户组具有读、写及可执行权限。</li><li>0o040：所有用户组具有读权限。</li><li>0o020：所有用户组具有写权限。</li><li>0o010：所有用户组具有可执行权限。</li><li>0o007：其余用户具有读、写及可执行权限。</li><li>0o004：其余用户具有读权限。</li><li>0o002：其余用户具有写权限。</li><li>0o001：其余用户具有可执行权限。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
     fileio.fchmodSync(fd, mode);
    ```


## fileio.truncateSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section2759113014567"></a>

truncateSync\(fpath: string, len?: number\): void

以同步方法基于文件路径截断文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table20760730115615"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1676023035614"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p16760163085614"><a name="zh-cn_topic_0000001208447259_p16760163085614"></a><a name="zh-cn_topic_0000001208447259_p16760163085614"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p7760530145610"><a name="zh-cn_topic_0000001208447259_p7760530145610"></a><a name="zh-cn_topic_0000001208447259_p7760530145610"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p12761830125613"><a name="zh-cn_topic_0000001208447259_p12761830125613"></a><a name="zh-cn_topic_0000001208447259_p12761830125613"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p976117306565"><a name="zh-cn_topic_0000001208447259_p976117306565"></a><a name="zh-cn_topic_0000001208447259_p976117306565"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row5761123020566"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p62014513569"><a name="zh-cn_topic_0000001208447259_p62014513569"></a><a name="zh-cn_topic_0000001208447259_p62014513569"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1120125175619"><a name="zh-cn_topic_0000001208447259_p1120125175619"></a><a name="zh-cn_topic_0000001208447259_p1120125175619"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p17201151145613"><a name="zh-cn_topic_0000001208447259_p17201151145613"></a><a name="zh-cn_topic_0000001208447259_p17201151145613"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1320155155611"><a name="zh-cn_topic_0000001208447259_p1320155155611"></a><a name="zh-cn_topic_0000001208447259_p1320155155611"></a>待截断文件的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row5762153019567"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1020351135614"><a name="zh-cn_topic_0000001208447259_p1020351135614"></a><a name="zh-cn_topic_0000001208447259_p1020351135614"></a>len</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p02075175616"><a name="zh-cn_topic_0000001208447259_p02075175616"></a><a name="zh-cn_topic_0000001208447259_p02075175616"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p620115112567"><a name="zh-cn_topic_0000001208447259_p620115112567"></a><a name="zh-cn_topic_0000001208447259_p620115112567"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p5924834141415"><a name="zh-cn_topic_0000001208447259_p5924834141415"></a><a name="zh-cn_topic_0000001208447259_p5924834141415"></a>文件截断后的长度，以字节为单位。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    fileio.ftruncate(path, len);
    ```


## fileio.renameSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section153395523116"></a>

renameSync\(oldPath: string, newPath: string\): void

以同步方法重命名文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table1933195515319"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row734105543113"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p534555163120"><a name="zh-cn_topic_0000001208447259_p534555163120"></a><a name="zh-cn_topic_0000001208447259_p534555163120"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p63419553317"><a name="zh-cn_topic_0000001208447259_p63419553317"></a><a name="zh-cn_topic_0000001208447259_p63419553317"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p1134255173110"><a name="zh-cn_topic_0000001208447259_p1134255173110"></a><a name="zh-cn_topic_0000001208447259_p1134255173110"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p4342551315"><a name="zh-cn_topic_0000001208447259_p4342551315"></a><a name="zh-cn_topic_0000001208447259_p4342551315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row63425513314"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p935105518312"><a name="zh-cn_topic_0000001208447259_p935105518312"></a><a name="zh-cn_topic_0000001208447259_p935105518312"></a>oldPath</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p193535583114"><a name="zh-cn_topic_0000001208447259_p193535583114"></a><a name="zh-cn_topic_0000001208447259_p193535583114"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p173565513112"><a name="zh-cn_topic_0000001208447259_p173565513112"></a><a name="zh-cn_topic_0000001208447259_p173565513112"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p168006618555"><a name="zh-cn_topic_0000001208447259_p168006618555"></a><a name="zh-cn_topic_0000001208447259_p168006618555"></a>目标文件的当前绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row183525593115"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1835185583116"><a name="zh-cn_topic_0000001208447259_p1835185583116"></a><a name="zh-cn_topic_0000001208447259_p1835185583116"></a>Newpath</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p63675553116"><a name="zh-cn_topic_0000001208447259_p63675553116"></a><a name="zh-cn_topic_0000001208447259_p63675553116"></a>String</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p23616551319"><a name="zh-cn_topic_0000001208447259_p23616551319"></a><a name="zh-cn_topic_0000001208447259_p23616551319"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p9801362555"><a name="zh-cn_topic_0000001208447259_p9801362555"></a><a name="zh-cn_topic_0000001208447259_p9801362555"></a>目标文件的新绝对路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.rename(oldpath，newpath);
    ```


## fileio.fsyncSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section11863111112544"></a>

fsyncSync\(fd: number\): void

以同步方法同步文件数据。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table159491205546"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1995170195414"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p119529085410"><a name="zh-cn_topic_0000001208447259_p119529085410"></a><a name="zh-cn_topic_0000001208447259_p119529085410"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p129521607543"><a name="zh-cn_topic_0000001208447259_p129521607543"></a><a name="zh-cn_topic_0000001208447259_p129521607543"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p895270195410"><a name="zh-cn_topic_0000001208447259_p895270195410"></a><a name="zh-cn_topic_0000001208447259_p895270195410"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p69524012549"><a name="zh-cn_topic_0000001208447259_p69524012549"></a><a name="zh-cn_topic_0000001208447259_p69524012549"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row129528012540"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p295230155415"><a name="zh-cn_topic_0000001208447259_p295230155415"></a><a name="zh-cn_topic_0000001208447259_p295230155415"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p19953106545"><a name="zh-cn_topic_0000001208447259_p19953106545"></a><a name="zh-cn_topic_0000001208447259_p19953106545"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p139532010546"><a name="zh-cn_topic_0000001208447259_p139532010546"></a><a name="zh-cn_topic_0000001208447259_p139532010546"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p79461816143220"><a name="zh-cn_topic_0000001208447259_p79461816143220"></a><a name="zh-cn_topic_0000001208447259_p79461816143220"></a>待同步文件的文件描述符。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    fileio.fyncsSync)(fd);
    ```


## fileio.chownSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section1717097183517"></a>

chownSync\(path: string, uid: number, gid: number\): void

以同步的方法基于文件路径改变文件所有者。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table1262234217377"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row20773134243715"><th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1677374219379"><a name="zh-cn_topic_0000001208447259_p1677374219379"></a><a name="zh-cn_topic_0000001208447259_p1677374219379"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p18774144214370"><a name="zh-cn_topic_0000001208447259_p18774144214370"></a><a name="zh-cn_topic_0000001208447259_p18774144214370"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.07%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p77741142163719"><a name="zh-cn_topic_0000001208447259_p77741142163719"></a><a name="zh-cn_topic_0000001208447259_p77741142163719"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.71%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p1277418426378"><a name="zh-cn_topic_0000001208447259_p1277418426378"></a><a name="zh-cn_topic_0000001208447259_p1277418426378"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row20774742203717"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p16774124273718"><a name="zh-cn_topic_0000001208447259_p16774124273718"></a><a name="zh-cn_topic_0000001208447259_p16774124273718"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p67741042183716"><a name="zh-cn_topic_0000001208447259_p67741042183716"></a><a name="zh-cn_topic_0000001208447259_p67741042183716"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p977404214375"><a name="zh-cn_topic_0000001208447259_p977404214375"></a><a name="zh-cn_topic_0000001208447259_p977404214375"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p197811961391"><a name="zh-cn_topic_0000001208447259_p197811961391"></a><a name="zh-cn_topic_0000001208447259_p197811961391"></a>待改变文件的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row16774124283717"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p077414218379"><a name="zh-cn_topic_0000001208447259_p077414218379"></a><a name="zh-cn_topic_0000001208447259_p077414218379"></a>uid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p13774184214377"><a name="zh-cn_topic_0000001208447259_p13774184214377"></a><a name="zh-cn_topic_0000001208447259_p13774184214377"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p187745428377"><a name="zh-cn_topic_0000001208447259_p187745428377"></a><a name="zh-cn_topic_0000001208447259_p187745428377"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p577524263713"><a name="zh-cn_topic_0000001208447259_p577524263713"></a><a name="zh-cn_topic_0000001208447259_p577524263713"></a>新的UID。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row11775114273711"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p47751542133715"><a name="zh-cn_topic_0000001208447259_p47751542133715"></a><a name="zh-cn_topic_0000001208447259_p47751542133715"></a>gid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p67751742143712"><a name="zh-cn_topic_0000001208447259_p67751742143712"></a><a name="zh-cn_topic_0000001208447259_p67751742143712"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p19775154263711"><a name="zh-cn_topic_0000001208447259_p19775154263711"></a><a name="zh-cn_topic_0000001208447259_p19775154263711"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p977544219372"><a name="zh-cn_topic_0000001208447259_p977544219372"></a><a name="zh-cn_topic_0000001208447259_p977544219372"></a>新的GID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let stat = fileio.statSync(fpath)
    fileio.chownSync(path, stat.uid, stat.gid);
    ```


## fileio.createStreamSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section1956102153713"></a>

createStreamSync\(path: string, mode: string\): Stream

以同步方法基于文件路径打开文件流。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table125718213375"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1857621153710"><th class="cellrowborder" valign="top" width="9.08%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p125811212376"><a name="zh-cn_topic_0000001208447259_p125811212376"></a><a name="zh-cn_topic_0000001208447259_p125811212376"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p0581121113714"><a name="zh-cn_topic_0000001208447259_p0581121113714"></a><a name="zh-cn_topic_0000001208447259_p0581121113714"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.01%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p115832113375"><a name="zh-cn_topic_0000001208447259_p115832113375"></a><a name="zh-cn_topic_0000001208447259_p115832113375"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.97%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p18589215373"><a name="zh-cn_topic_0000001208447259_p18589215373"></a><a name="zh-cn_topic_0000001208447259_p18589215373"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row125815214372"><td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1696272519446"><a name="zh-cn_topic_0000001208447259_p1696272519446"></a><a name="zh-cn_topic_0000001208447259_p1696272519446"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1396202534413"><a name="zh-cn_topic_0000001208447259_p1396202534413"></a><a name="zh-cn_topic_0000001208447259_p1396202534413"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p12962425144415"><a name="zh-cn_topic_0000001208447259_p12962425144415"></a><a name="zh-cn_topic_0000001208447259_p12962425144415"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.97%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p179623257441"><a name="zh-cn_topic_0000001208447259_p179623257441"></a><a name="zh-cn_topic_0000001208447259_p179623257441"></a>待打开文件的绝对路径。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row66780382444"><td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p1534517513466"><a name="zh-cn_topic_0000001208447259_p1534517513466"></a><a name="zh-cn_topic_0000001208447259_p1534517513466"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p18345115194618"><a name="zh-cn_topic_0000001208447259_p18345115194618"></a><a name="zh-cn_topic_0000001208447259_p18345115194618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p634505174615"><a name="zh-cn_topic_0000001208447259_p634505174615"></a><a name="zh-cn_topic_0000001208447259_p634505174615"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.97%" headers="mcps1.1.5.1.4 "><a name="zh-cn_topic_0000001208447259_ul141401653154518"></a><a name="zh-cn_topic_0000001208447259_ul141401653154518"></a><ul id="zh-cn_topic_0000001208447259_ul141401653154518"><li>r：打开只读文件，该文件必须存在。</li><li>r+：打开可读写的文件，该文件必须存在。</li><li>w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。</li><li>w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。</li><li>a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。</li><li>a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="zh-cn_topic_0000001208447259_table82181442114718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row11377134234713"><th class="cellrowborder" valign="top" width="21.21%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p5377144217477"><a name="zh-cn_topic_0000001208447259_p5377144217477"></a><a name="zh-cn_topic_0000001208447259_p5377144217477"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.79%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p9377134211472"><a name="zh-cn_topic_0000001208447259_p9377134211472"></a><a name="zh-cn_topic_0000001208447259_p9377134211472"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row537794234717"><td class="cellrowborder" valign="top" width="21.21%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p23779423475"><a name="zh-cn_topic_0000001208447259_p23779423475"></a><a name="zh-cn_topic_0000001208447259_p23779423475"></a><a href="#zh-cn_topic_0000001208447259_section109771933162919">Stream</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.79%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1349516611613"><a name="zh-cn_topic_0000001208447259_p1349516611613"></a><a name="zh-cn_topic_0000001208447259_p1349516611613"></a>返回文件流的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let ss = fileio.createStream(path, "r+");
    ```


## fileio.fdopenStreamSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section185160523522"></a>

fdopenStreamSync\(fd: number, mode: string\): Stream

以同步方法基于文件描述符打开文件流。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table1151765215216"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row55171523524"><th class="cellrowborder" valign="top" width="9.09%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1852145275216"><a name="zh-cn_topic_0000001208447259_p1852145275216"></a><a name="zh-cn_topic_0000001208447259_p1852145275216"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.43%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p9521175215213"><a name="zh-cn_topic_0000001208447259_p9521175215213"></a><a name="zh-cn_topic_0000001208447259_p9521175215213"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.84%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p1521115212529"><a name="zh-cn_topic_0000001208447259_p1521115212529"></a><a name="zh-cn_topic_0000001208447259_p1521115212529"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.64%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p152119524526"><a name="zh-cn_topic_0000001208447259_p152119524526"></a><a name="zh-cn_topic_0000001208447259_p152119524526"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row16522052105215"><td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p2052265216521"><a name="zh-cn_topic_0000001208447259_p2052265216521"></a><a name="zh-cn_topic_0000001208447259_p2052265216521"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.43%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p15225527528"><a name="zh-cn_topic_0000001208447259_p15225527528"></a><a name="zh-cn_topic_0000001208447259_p15225527528"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p952225219523"><a name="zh-cn_topic_0000001208447259_p952225219523"></a><a name="zh-cn_topic_0000001208447259_p952225219523"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.64%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p18953103165913"><a name="zh-cn_topic_0000001208447259_p18953103165913"></a><a name="zh-cn_topic_0000001208447259_p18953103165913"></a>待打开文件的文件描述符。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row115221452175217"><td class="cellrowborder" valign="top" width="9.09%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p9523155285212"><a name="zh-cn_topic_0000001208447259_p9523155285212"></a><a name="zh-cn_topic_0000001208447259_p9523155285212"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.43%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p12523752105216"><a name="zh-cn_topic_0000001208447259_p12523752105216"></a><a name="zh-cn_topic_0000001208447259_p12523752105216"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p752315529529"><a name="zh-cn_topic_0000001208447259_p752315529529"></a><a name="zh-cn_topic_0000001208447259_p752315529529"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.64%" headers="mcps1.1.5.1.4 "><a name="zh-cn_topic_0000001208447259_ul141557537457"></a><a name="zh-cn_topic_0000001208447259_ul141557537457"></a><ul id="zh-cn_topic_0000001208447259_ul141557537457"><li>r：打开只读文件，该文件必须存在。</li><li>r+：打开可读写的文件，该文件必须存在。</li><li>w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。</li><li>w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。</li><li>a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。</li><li>a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="zh-cn_topic_0000001208447259_table9524115217526"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row17525125205211"><th class="cellrowborder" valign="top" width="21.21%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p552585219523"><a name="zh-cn_topic_0000001208447259_p552585219523"></a><a name="zh-cn_topic_0000001208447259_p552585219523"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.79%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p85251152105216"><a name="zh-cn_topic_0000001208447259_p85251152105216"></a><a name="zh-cn_topic_0000001208447259_p85251152105216"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row195259523527"><td class="cellrowborder" valign="top" width="21.21%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p1552618520529"><a name="zh-cn_topic_0000001208447259_p1552618520529"></a><a name="zh-cn_topic_0000001208447259_p1552618520529"></a><a href="#zh-cn_topic_0000001208447259_section109771933162919">Stream</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.79%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p10526165225216"><a name="zh-cn_topic_0000001208447259_p10526165225216"></a><a name="zh-cn_topic_0000001208447259_p10526165225216"></a>返回文件流的结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let ss = fileio.fdopenStreamSync(fd, "r+");
    ```


## fileio.fchownSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section118619326160"></a>

fchownSync\(fd: number, uid: number, gid: number\): void

以同步方法基于文件描述符改变文件所有者。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table131861032131617"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1187143214167"><th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1518763271613"><a name="zh-cn_topic_0000001208447259_p1518763271613"></a><a name="zh-cn_topic_0000001208447259_p1518763271613"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.110000000000001%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p12187183210161"><a name="zh-cn_topic_0000001208447259_p12187183210161"></a><a name="zh-cn_topic_0000001208447259_p12187183210161"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.07%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p918773211164"><a name="zh-cn_topic_0000001208447259_p918773211164"></a><a name="zh-cn_topic_0000001208447259_p918773211164"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.71%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p718814323161"><a name="zh-cn_topic_0000001208447259_p718814323161"></a><a name="zh-cn_topic_0000001208447259_p718814323161"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row12188113213167"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p218819328165"><a name="zh-cn_topic_0000001208447259_p218819328165"></a><a name="zh-cn_topic_0000001208447259_p218819328165"></a>fd</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1918814327166"><a name="zh-cn_topic_0000001208447259_p1918814327166"></a><a name="zh-cn_topic_0000001208447259_p1918814327166"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p131881732171618"><a name="zh-cn_topic_0000001208447259_p131881732171618"></a><a name="zh-cn_topic_0000001208447259_p131881732171618"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p780313572596"><a name="zh-cn_topic_0000001208447259_p780313572596"></a><a name="zh-cn_topic_0000001208447259_p780313572596"></a>待改变文件的文件描述符。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row1618883221612"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p10188183218161"><a name="zh-cn_topic_0000001208447259_p10188183218161"></a><a name="zh-cn_topic_0000001208447259_p10188183218161"></a>uid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p1918917326163"><a name="zh-cn_topic_0000001208447259_p1918917326163"></a><a name="zh-cn_topic_0000001208447259_p1918917326163"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p151892321164"><a name="zh-cn_topic_0000001208447259_p151892321164"></a><a name="zh-cn_topic_0000001208447259_p151892321164"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1418993241611"><a name="zh-cn_topic_0000001208447259_p1418993241611"></a><a name="zh-cn_topic_0000001208447259_p1418993241611"></a>文件所有者的UID。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row5189143201618"><td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p618923201615"><a name="zh-cn_topic_0000001208447259_p618923201615"></a><a name="zh-cn_topic_0000001208447259_p618923201615"></a>gid</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.110000000000001%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p41891332131619"><a name="zh-cn_topic_0000001208447259_p41891332131619"></a><a name="zh-cn_topic_0000001208447259_p41891332131619"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p19397151815357"><a name="zh-cn_topic_0000001208447259_p19397151815357"></a><a name="zh-cn_topic_0000001208447259_p19397151815357"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p47382016132620"><a name="zh-cn_topic_0000001208447259_p47382016132620"></a><a name="zh-cn_topic_0000001208447259_p47382016132620"></a>文件所有组的GID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let stat = fileio.statSync(fpath);
    fileio.fchownSync(fd, stat.uid, stat.gid);
    ```


## Stat<a name="zh-cn_topic_0000001208447259_section7315249105116"></a>

文件具体信息，在调用Stat的方法前，需要先通过[fileio.statSync](#zh-cn_topic_0000001208447259_section014281412198)来构建一个Stat实例。

### 属性<a name="zh-cn_topic_0000001208447259_section23751576140"></a>

<a name="zh-cn_topic_0000001208447259_table728861911417"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row62887198149"><th class="cellrowborder" valign="top" width="11.66%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001208447259_p928811911410"><a name="zh-cn_topic_0000001208447259_p928811911410"></a><a name="zh-cn_topic_0000001208447259_p928811911410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001208447259_p8288191916149"><a name="zh-cn_topic_0000001208447259_p8288191916149"></a><a name="zh-cn_topic_0000001208447259_p8288191916149"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001208447259_p14288131911418"><a name="zh-cn_topic_0000001208447259_p14288131911418"></a><a name="zh-cn_topic_0000001208447259_p14288131911418"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="6.63%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001208447259_p1928861921411"><a name="zh-cn_topic_0000001208447259_p1928861921411"></a><a name="zh-cn_topic_0000001208447259_p1928861921411"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="62.32%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001208447259_p728815191149"><a name="zh-cn_topic_0000001208447259_p728815191149"></a><a name="zh-cn_topic_0000001208447259_p728815191149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001208447259_row528891919142"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p3288191991414"><a name="zh-cn_topic_0000001208447259_p3288191991414"></a><a name="zh-cn_topic_0000001208447259_p3288191991414"></a>dev</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p3288121901418"><a name="zh-cn_topic_0000001208447259_p3288121901418"></a><a name="zh-cn_topic_0000001208447259_p3288121901418"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p182881319191414"><a name="zh-cn_topic_0000001208447259_p182881319191414"></a><a name="zh-cn_topic_0000001208447259_p182881319191414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p1928801914148"><a name="zh-cn_topic_0000001208447259_p1928801914148"></a><a name="zh-cn_topic_0000001208447259_p1928801914148"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p1428811192144"><a name="zh-cn_topic_0000001208447259_p1428811192144"></a><a name="zh-cn_topic_0000001208447259_p1428811192144"></a>标识包含该文件的主设备号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row17111195311346"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p10288419131415"><a name="zh-cn_topic_0000001208447259_p10288419131415"></a><a name="zh-cn_topic_0000001208447259_p10288419131415"></a>ino</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p626711397284"><a name="zh-cn_topic_0000001208447259_p626711397284"></a><a name="zh-cn_topic_0000001208447259_p626711397284"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p1726743912812"><a name="zh-cn_topic_0000001208447259_p1726743912812"></a><a name="zh-cn_topic_0000001208447259_p1726743912812"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p326733942818"><a name="zh-cn_topic_0000001208447259_p326733942818"></a><a name="zh-cn_topic_0000001208447259_p326733942818"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p1228991915144"><a name="zh-cn_topic_0000001208447259_p1228991915144"></a><a name="zh-cn_topic_0000001208447259_p1228991915144"></a>标识该文件。通常同设备上的不同文件的INO不同。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row1918562340"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p209120568349"><a name="zh-cn_topic_0000001208447259_p209120568349"></a><a name="zh-cn_topic_0000001208447259_p209120568349"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p19794751113514"><a name="zh-cn_topic_0000001208447259_p19794751113514"></a><a name="zh-cn_topic_0000001208447259_p19794751113514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p17122185403519"><a name="zh-cn_topic_0000001208447259_p17122185403519"></a><a name="zh-cn_topic_0000001208447259_p17122185403519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p11319595358"><a name="zh-cn_topic_0000001208447259_p11319595358"></a><a name="zh-cn_topic_0000001208447259_p11319595358"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p49119568343"><a name="zh-cn_topic_0000001208447259_p49119568343"></a><a name="zh-cn_topic_0000001208447259_p49119568343"></a>表示文件类型及权限，其首 4 位表示文件类型，后 12 位表示权限。各特征位的含义如下：</p>
<a name="zh-cn_topic_0000001208447259_ul3882122236"></a><a name="zh-cn_topic_0000001208447259_ul3882122236"></a><ul id="zh-cn_topic_0000001208447259_ul3882122236"><li>0o170000：可用于获取文件类型的掩码。</li><li>0o140000：文件是套接字。</li><li>0o120000：文件是符号链接。</li><li>0o100000：文件是一般文件。</li><li>0o060000：文件属于块设备。</li><li>0o040000：文件是目录。</li><li>0o020000：文件是字符设备。</li><li>0o010000：文件是具名管道，即FIFO。</li><li>0o0700：可用于获取用户权限的掩码。</li><li>0o0400：用户读，对于普通文件，所有者可读取文件；对于目录，所有者可读取目录项。</li><li>0o0200：用户写，对于普通文件，所有者可写入文件；对于目录，所有者可创建/删除目录项。</li><li>0o0100：用户执行，对于普通文件，所有者可执行文件；对于目录，所有者可在目录中搜索给定路径名。</li><li>0o0070：可用于获取用户组权限的掩码。</li><li>0o0040：用户组读，对于普通文件，所有用户组可读取文件；对于目录，所有用户组可读取目录项。</li><li>0o0020：用户组写，对于普通文件，所有用户组可写入文件；对于目录，所有用户组可创建/删除目录项。</li><li>0o0010：用户组执行，对于普通文件，所有用户组可执行文件；对于目录，所有用户组是否可在目录中搜索给定路径名。</li><li>0o0007：可用于获取其他用户权限的掩码。</li><li>0o0004：其他读，对于普通文件，其余用户可读取文件；对于目录，其他用户组可读取目录项。</li><li>0o0002：其他写，对于普通文件，其余用户可写入文件；对于目录，其他用户组可创建/删除目录项。</li><li>0o0001：其他执行，对于普通文件，其余用户可执行文件；对于目录，其他用户组可在目录中搜索给定路径名。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row11288719111417"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p179541859193413"><a name="zh-cn_topic_0000001208447259_p179541859193413"></a><a name="zh-cn_topic_0000001208447259_p179541859193413"></a>nlink</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p7812951193514"><a name="zh-cn_topic_0000001208447259_p7812951193514"></a><a name="zh-cn_topic_0000001208447259_p7812951193514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p912275418354"><a name="zh-cn_topic_0000001208447259_p912275418354"></a><a name="zh-cn_topic_0000001208447259_p912275418354"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p629559143510"><a name="zh-cn_topic_0000001208447259_p629559143510"></a><a name="zh-cn_topic_0000001208447259_p629559143510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p89331759153410"><a name="zh-cn_topic_0000001208447259_p89331759153410"></a><a name="zh-cn_topic_0000001208447259_p89331759153410"></a>文件的硬链接数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row819112311341"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p1319117373415"><a name="zh-cn_topic_0000001208447259_p1319117373415"></a><a name="zh-cn_topic_0000001208447259_p1319117373415"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p178301751203519"><a name="zh-cn_topic_0000001208447259_p178301751203519"></a><a name="zh-cn_topic_0000001208447259_p178301751203519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p1075695613358"><a name="zh-cn_topic_0000001208447259_p1075695613358"></a><a name="zh-cn_topic_0000001208447259_p1075695613358"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p447125963517"><a name="zh-cn_topic_0000001208447259_p447125963517"></a><a name="zh-cn_topic_0000001208447259_p447125963517"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p31921839340"><a name="zh-cn_topic_0000001208447259_p31921839340"></a><a name="zh-cn_topic_0000001208447259_p31921839340"></a>文件所有者的ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row5209203920349"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p520953913418"><a name="zh-cn_topic_0000001208447259_p520953913418"></a><a name="zh-cn_topic_0000001208447259_p520953913418"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p1983814516358"><a name="zh-cn_topic_0000001208447259_p1983814516358"></a><a name="zh-cn_topic_0000001208447259_p1983814516358"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p1376416564354"><a name="zh-cn_topic_0000001208447259_p1376416564354"></a><a name="zh-cn_topic_0000001208447259_p1376416564354"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p135545943518"><a name="zh-cn_topic_0000001208447259_p135545943518"></a><a name="zh-cn_topic_0000001208447259_p135545943518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p820933917349"><a name="zh-cn_topic_0000001208447259_p820933917349"></a><a name="zh-cn_topic_0000001208447259_p820933917349"></a>文件所有组的ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row987683412343"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p15877734143414"><a name="zh-cn_topic_0000001208447259_p15877734143414"></a><a name="zh-cn_topic_0000001208447259_p15877734143414"></a>rdev</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p1684585183518"><a name="zh-cn_topic_0000001208447259_p1684585183518"></a><a name="zh-cn_topic_0000001208447259_p1684585183518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p97711556193513"><a name="zh-cn_topic_0000001208447259_p97711556193513"></a><a name="zh-cn_topic_0000001208447259_p97711556193513"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p196235953510"><a name="zh-cn_topic_0000001208447259_p196235953510"></a><a name="zh-cn_topic_0000001208447259_p196235953510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p1287793463415"><a name="zh-cn_topic_0000001208447259_p1287793463415"></a><a name="zh-cn_topic_0000001208447259_p1287793463415"></a>标识包含该文件的从设备号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row1825315322344"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p92531132163419"><a name="zh-cn_topic_0000001208447259_p92531132163419"></a><a name="zh-cn_topic_0000001208447259_p92531132163419"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p485275173512"><a name="zh-cn_topic_0000001208447259_p485275173512"></a><a name="zh-cn_topic_0000001208447259_p485275173512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p177781156183511"><a name="zh-cn_topic_0000001208447259_p177781156183511"></a><a name="zh-cn_topic_0000001208447259_p177781156183511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p46995917359"><a name="zh-cn_topic_0000001208447259_p46995917359"></a><a name="zh-cn_topic_0000001208447259_p46995917359"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p82531332103418"><a name="zh-cn_topic_0000001208447259_p82531332103418"></a><a name="zh-cn_topic_0000001208447259_p82531332103418"></a>文件的大小，以字节为单位。仅对普通文件有效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row15419937153410"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p2042033717340"><a name="zh-cn_topic_0000001208447259_p2042033717340"></a><a name="zh-cn_topic_0000001208447259_p2042033717340"></a>blocks</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p16860135123512"><a name="zh-cn_topic_0000001208447259_p16860135123512"></a><a name="zh-cn_topic_0000001208447259_p16860135123512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p4785115611354"><a name="zh-cn_topic_0000001208447259_p4785115611354"></a><a name="zh-cn_topic_0000001208447259_p4785115611354"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p14761599359"><a name="zh-cn_topic_0000001208447259_p14761599359"></a><a name="zh-cn_topic_0000001208447259_p14761599359"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p134203373346"><a name="zh-cn_topic_0000001208447259_p134203373346"></a><a name="zh-cn_topic_0000001208447259_p134203373346"></a>文件占用的块数，计算时块大小按512B计算。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row757852116342"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p105797211348"><a name="zh-cn_topic_0000001208447259_p105797211348"></a><a name="zh-cn_topic_0000001208447259_p105797211348"></a>atime</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p7867105133518"><a name="zh-cn_topic_0000001208447259_p7867105133518"></a><a name="zh-cn_topic_0000001208447259_p7867105133518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p14792145612357"><a name="zh-cn_topic_0000001208447259_p14792145612357"></a><a name="zh-cn_topic_0000001208447259_p14792145612357"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p18445903518"><a name="zh-cn_topic_0000001208447259_p18445903518"></a><a name="zh-cn_topic_0000001208447259_p18445903518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p7579202117348"><a name="zh-cn_topic_0000001208447259_p7579202117348"></a><a name="zh-cn_topic_0000001208447259_p7579202117348"></a>上次访问该文件的时间，表示距1970年1月1日0时0分0秒的秒数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row7331132814341"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p23311828143417"><a name="zh-cn_topic_0000001208447259_p23311828143417"></a><a name="zh-cn_topic_0000001208447259_p23311828143417"></a>mtime</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p188741518359"><a name="zh-cn_topic_0000001208447259_p188741518359"></a><a name="zh-cn_topic_0000001208447259_p188741518359"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p2799115633517"><a name="zh-cn_topic_0000001208447259_p2799115633517"></a><a name="zh-cn_topic_0000001208447259_p2799115633517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p14911659103510"><a name="zh-cn_topic_0000001208447259_p14911659103510"></a><a name="zh-cn_topic_0000001208447259_p14911659103510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p16332122819345"><a name="zh-cn_topic_0000001208447259_p16332122819345"></a><a name="zh-cn_topic_0000001208447259_p16332122819345"></a>上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001208447259_row1047914304341"><td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p947913020342"><a name="zh-cn_topic_0000001208447259_p947913020342"></a><a name="zh-cn_topic_0000001208447259_p947913020342"></a>ctime</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p4881155110359"><a name="zh-cn_topic_0000001208447259_p4881155110359"></a><a name="zh-cn_topic_0000001208447259_p4881155110359"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p88061956113520"><a name="zh-cn_topic_0000001208447259_p88061956113520"></a><a name="zh-cn_topic_0000001208447259_p88061956113520"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.63%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p109845983513"><a name="zh-cn_topic_0000001208447259_p109845983513"></a><a name="zh-cn_topic_0000001208447259_p109845983513"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="62.32%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p347915303344"><a name="zh-cn_topic_0000001208447259_p347915303344"></a><a name="zh-cn_topic_0000001208447259_p347915303344"></a>最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的秒数。</p>
</td>
</tr>
</tbody>
</table>

### isBlockDevice<a name="zh-cn_topic_0000001208447259_section1041074182716"></a>

isBlockDevice\(\): boolean

用于判断当前目录项是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table1241064122713"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row5410174202717"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p14101249279"><a name="zh-cn_topic_0000001208447259_p14101249279"></a><a name="zh-cn_topic_0000001208447259_p14101249279"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p104104410278"><a name="zh-cn_topic_0000001208447259_p104104410278"></a><a name="zh-cn_topic_0000001208447259_p104104410278"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row164101142272"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p14410347278"><a name="zh-cn_topic_0000001208447259_p14410347278"></a><a name="zh-cn_topic_0000001208447259_p14410347278"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p3410947271"><a name="zh-cn_topic_0000001208447259_p3410947271"></a><a name="zh-cn_topic_0000001208447259_p3410947271"></a>表示当前目录项是否是块特殊设备。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isBLockDevice = fileio.statSync(path).isBlockDevice();
    ```


### isCharacterDevice<a name="zh-cn_topic_0000001208447259_section154111646277"></a>

isCharacterDevice\(\): boolean

用于判断当前目录项是否是字符特殊文件。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table184113412717"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row94111942272"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p3411194132713"><a name="zh-cn_topic_0000001208447259_p3411194132713"></a><a name="zh-cn_topic_0000001208447259_p3411194132713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p04116472711"><a name="zh-cn_topic_0000001208447259_p04116472711"></a><a name="zh-cn_topic_0000001208447259_p04116472711"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row194111544271"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p04111245272"><a name="zh-cn_topic_0000001208447259_p04111245272"></a><a name="zh-cn_topic_0000001208447259_p04111245272"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p041104132717"><a name="zh-cn_topic_0000001208447259_p041104132717"></a><a name="zh-cn_topic_0000001208447259_p041104132717"></a>表示当前目录项是否是字符特殊设备。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isCharacterDevice = fileio.statSync(path).isCharacterDevice();
    ```


### isDirectory<a name="zh-cn_topic_0000001208447259_section2041115418271"></a>

isDirectory\(\): boolean

用于判断当前目录项是否是目录。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table841113472714"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row14114412719"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p641194102713"><a name="zh-cn_topic_0000001208447259_p641194102713"></a><a name="zh-cn_topic_0000001208447259_p641194102713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p104111847275"><a name="zh-cn_topic_0000001208447259_p104111847275"></a><a name="zh-cn_topic_0000001208447259_p104111847275"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row5411164192714"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p24114412720"><a name="zh-cn_topic_0000001208447259_p24114412720"></a><a name="zh-cn_topic_0000001208447259_p24114412720"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p11412134132718"><a name="zh-cn_topic_0000001208447259_p11412134132718"></a><a name="zh-cn_topic_0000001208447259_p11412134132718"></a>表示当前目录项是否是目录。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isDirectory= fileio.statSync(path).isDirectory(); 
    ```


### isFIFO<a name="zh-cn_topic_0000001208447259_section1941244122719"></a>

isFIFO\(\): boolean

用于判断当前目录项是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table11412845271"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1641220416272"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p1641210415279"><a name="zh-cn_topic_0000001208447259_p1641210415279"></a><a name="zh-cn_topic_0000001208447259_p1641210415279"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p3412548273"><a name="zh-cn_topic_0000001208447259_p3412548273"></a><a name="zh-cn_topic_0000001208447259_p3412548273"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row441224142717"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p741218402714"><a name="zh-cn_topic_0000001208447259_p741218402714"></a><a name="zh-cn_topic_0000001208447259_p741218402714"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p154121840272"><a name="zh-cn_topic_0000001208447259_p154121840272"></a><a name="zh-cn_topic_0000001208447259_p154121840272"></a>表示当前目录项是否是 FIFO。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isFIFO= fileio.statSync(path).isFIFO(); 
    ```


### isFile<a name="zh-cn_topic_0000001208447259_section341284192710"></a>

isFile\(\): boolean

用于判断当前目录项是否是普通文件。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table10412124152720"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row34124412272"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p20412144152718"><a name="zh-cn_topic_0000001208447259_p20412144152718"></a><a name="zh-cn_topic_0000001208447259_p20412144152718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p1941374112718"><a name="zh-cn_topic_0000001208447259_p1941374112718"></a><a name="zh-cn_topic_0000001208447259_p1941374112718"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row2041384102711"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p184131045270"><a name="zh-cn_topic_0000001208447259_p184131045270"></a><a name="zh-cn_topic_0000001208447259_p184131045270"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1241316412277"><a name="zh-cn_topic_0000001208447259_p1241316412277"></a><a name="zh-cn_topic_0000001208447259_p1241316412277"></a>表示当前目录项是否是普通文件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isFile= fileio.statSync(fpath).isFile();
    ```


### isSocket<a name="zh-cn_topic_0000001208447259_section154131413278"></a>

isSocket\(\): boolean

用于判断当前目录项是否是套接字。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table144131842271"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1841304192716"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p154133422714"><a name="zh-cn_topic_0000001208447259_p154133422714"></a><a name="zh-cn_topic_0000001208447259_p154133422714"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p12413144275"><a name="zh-cn_topic_0000001208447259_p12413144275"></a><a name="zh-cn_topic_0000001208447259_p12413144275"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row441310418272"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p141319432718"><a name="zh-cn_topic_0000001208447259_p141319432718"></a><a name="zh-cn_topic_0000001208447259_p141319432718"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1541319482714"><a name="zh-cn_topic_0000001208447259_p1541319482714"></a><a name="zh-cn_topic_0000001208447259_p1541319482714"></a>表示当前目录项是否是套接字。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isSocket = fileio.statSync(path).isSocket(); 
    ```


### isSymbolicLink<a name="zh-cn_topic_0000001208447259_section241317413274"></a>

isSymbolicLink\(\): boolean

用于判断当前目录项是否是符号链接。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table13413114122717"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row14147472718"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p14143472712"><a name="zh-cn_topic_0000001208447259_p14143472712"></a><a name="zh-cn_topic_0000001208447259_p14143472712"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p1241417442710"><a name="zh-cn_topic_0000001208447259_p1241417442710"></a><a name="zh-cn_topic_0000001208447259_p1241417442710"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row134146472715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p64144418275"><a name="zh-cn_topic_0000001208447259_p64144418275"></a><a name="zh-cn_topic_0000001208447259_p64144418275"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p24142419279"><a name="zh-cn_topic_0000001208447259_p24142419279"></a><a name="zh-cn_topic_0000001208447259_p24142419279"></a>表示当前目录项是否是符号链接。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let isSymbolicLink = fileio.statSync(path).isSymbolicLink(); 
    ```


## Stream<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section109771933162919"></a>

文件流，在调用Stream的方法前，需要先通过[fileio.createStreamSync](#zh-cn_topic_0000001208447259_section1956102153713)方法来构建一个Stream实例。

### closeSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section45453128524"></a>

closeSync\(\): void

同步关闭文件流。

-   示例：

    ```
    let ss= fileio.createStreamSync(path);
    ss.closeSync();
    ```


### flushSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section55111014181917"></a>

flushSync\(\): void

同步刷新文件流。

-   示例：

    ```
    let ss= fileio.createStreamSync(path);
    ss.flushSync();
    ```


### writeSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section1959319151511"></a>

writeSync\(buffer: ArrayBuffer | string, options?:Object\): number

以同步方法将数据写入流文件。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table25121946162517"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row1651474618253"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p1514124642518"><a name="zh-cn_topic_0000001208447259_p1514124642518"></a><a name="zh-cn_topic_0000001208447259_p1514124642518"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.62%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p1251494613252"><a name="zh-cn_topic_0000001208447259_p1251494613252"></a><a name="zh-cn_topic_0000001208447259_p1251494613252"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p1151434632511"><a name="zh-cn_topic_0000001208447259_p1151434632511"></a><a name="zh-cn_topic_0000001208447259_p1151434632511"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p18515124622520"><a name="zh-cn_topic_0000001208447259_p18515124622520"></a><a name="zh-cn_topic_0000001208447259_p18515124622520"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row19516124618251"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p135161346172518"><a name="zh-cn_topic_0000001208447259_p135161346172518"></a><a name="zh-cn_topic_0000001208447259_p135161346172518"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p10516164619254"><a name="zh-cn_topic_0000001208447259_p10516164619254"></a><a name="zh-cn_topic_0000001208447259_p10516164619254"></a>ArrayBuffer | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p1551710465250"><a name="zh-cn_topic_0000001208447259_p1551710465250"></a><a name="zh-cn_topic_0000001208447259_p1551710465250"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1551710467254"><a name="zh-cn_topic_0000001208447259_p1551710467254"></a><a name="zh-cn_topic_0000001208447259_p1551710467254"></a>待写入文件的数据，可来自缓冲区或字符串。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row551754611254"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p75171846182515"><a name="zh-cn_topic_0000001208447259_p75171846182515"></a><a name="zh-cn_topic_0000001208447259_p75171846182515"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.62%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p2051844618257"><a name="zh-cn_topic_0000001208447259_p2051844618257"></a><a name="zh-cn_topic_0000001208447259_p2051844618257"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p15518124612513"><a name="zh-cn_topic_0000001208447259_p15518124612513"></a><a name="zh-cn_topic_0000001208447259_p15518124612513"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p0518114652511"><a name="zh-cn_topic_0000001208447259_p0518114652511"></a><a name="zh-cn_topic_0000001208447259_p0518114652511"></a>支持如下选项：</p>
    <a name="zh-cn_topic_0000001208447259_ul6518134616252"></a><a name="zh-cn_topic_0000001208447259_ul6518134616252"></a><ul id="zh-cn_topic_0000001208447259_ul6518134616252"><li>offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。</li><li>length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。</li><li>position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。</li><li>encoding，string类型，当数据是 string 类型时有效，表示数据的编码方式，默认 'utf-8'，仅支持 'utf-8'。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table10520446162513"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row652084611250"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p125211946122520"><a name="zh-cn_topic_0000001208447259_p125211946122520"></a><a name="zh-cn_topic_0000001208447259_p125211946122520"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p6521146152512"><a name="zh-cn_topic_0000001208447259_p6521146152512"></a><a name="zh-cn_topic_0000001208447259_p6521146152512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row2522174652520"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p1522114617255"><a name="zh-cn_topic_0000001208447259_p1522114617255"></a><a name="zh-cn_topic_0000001208447259_p1522114617255"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p152234632520"><a name="zh-cn_topic_0000001208447259_p152234632520"></a><a name="zh-cn_topic_0000001208447259_p152234632520"></a>实际写入的长度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let ss= fileio.createStreamSync(fpath,"r+");
    ss.writeSync("hello, world",{offset: 1,length: 5,position: 5,encoding :'utf-8'});
    ```


### readSync<sup>7+</sup><a name="zh-cn_topic_0000001208447259_section547517381167"></a>

readSync\(buffer: ArrayBuffer, options?: Object\): number

以同步方法从流文件读取数据。

-   参数：

    <a name="zh-cn_topic_0000001208447259_table834818156483"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row73491515164815"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001208447259_p334911584819"><a name="zh-cn_topic_0000001208447259_p334911584819"></a><a name="zh-cn_topic_0000001208447259_p334911584819"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001208447259_p12349141518486"><a name="zh-cn_topic_0000001208447259_p12349141518486"></a><a name="zh-cn_topic_0000001208447259_p12349141518486"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001208447259_p143501153489"><a name="zh-cn_topic_0000001208447259_p143501153489"></a><a name="zh-cn_topic_0000001208447259_p143501153489"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001208447259_p7350151519489"><a name="zh-cn_topic_0000001208447259_p7350151519489"></a><a name="zh-cn_topic_0000001208447259_p7350151519489"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row16351191514489"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p53511515154811"><a name="zh-cn_topic_0000001208447259_p53511515154811"></a><a name="zh-cn_topic_0000001208447259_p53511515154811"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p193515154487"><a name="zh-cn_topic_0000001208447259_p193515154487"></a><a name="zh-cn_topic_0000001208447259_p193515154487"></a>ArrayBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p3351715114812"><a name="zh-cn_topic_0000001208447259_p3351715114812"></a><a name="zh-cn_topic_0000001208447259_p3351715114812"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1035220156485"><a name="zh-cn_topic_0000001208447259_p1035220156485"></a><a name="zh-cn_topic_0000001208447259_p1035220156485"></a>用于读取文件的缓冲区。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001208447259_row143521315134810"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001208447259_p635212150484"><a name="zh-cn_topic_0000001208447259_p635212150484"></a><a name="zh-cn_topic_0000001208447259_p635212150484"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001208447259_p19352131524811"><a name="zh-cn_topic_0000001208447259_p19352131524811"></a><a name="zh-cn_topic_0000001208447259_p19352131524811"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001208447259_p3353201520481"><a name="zh-cn_topic_0000001208447259_p3353201520481"></a><a name="zh-cn_topic_0000001208447259_p3353201520481"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001208447259_p1935319155480"><a name="zh-cn_topic_0000001208447259_p1935319155480"></a><a name="zh-cn_topic_0000001208447259_p1935319155480"></a>支持如下选项：</p>
    <a name="zh-cn_topic_0000001208447259_ul135351513487"></a><a name="zh-cn_topic_0000001208447259_ul135351513487"></a><ul id="zh-cn_topic_0000001208447259_ul135351513487"><li>offset，number 类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。</li><li>length，number 类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。</li><li>position，number 类型，表示期望读取文件的位置。可选，默认从当前位置开始读。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table5354151584811"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row18355161514482"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p1355111514810"><a name="zh-cn_topic_0000001208447259_p1355111514810"></a><a name="zh-cn_topic_0000001208447259_p1355111514810"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p16355515194816"><a name="zh-cn_topic_0000001208447259_p16355515194816"></a><a name="zh-cn_topic_0000001208447259_p16355515194816"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row83551515164815"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p1235651511484"><a name="zh-cn_topic_0000001208447259_p1235651511484"></a><a name="zh-cn_topic_0000001208447259_p1235651511484"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p835651513487"><a name="zh-cn_topic_0000001208447259_p835651513487"></a><a name="zh-cn_topic_0000001208447259_p835651513487"></a>实际读取的长度。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let ss = fileio.createStreamSync(fpath, "r+");
    ss.readSync(new ArrayBuffer(4096),{offset: 1,length: FILE_CONTENT.length,position: 5});
    ```


## Dir<a name="zh-cn_topic_0000001208447259_section189341937163212"></a>

管理目录，在调用Dir的方法前，需要先通过[fileio.opendirSync](#zh-cn_topic_0000001208447259_section7741145112216)方法来构建一个Dir实例。

### readSync<a name="zh-cn_topic_0000001208447259_section10198204912710"></a>

readSync\(\): Dirent

同步读取下一个目录项。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table91985491870"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row131981491775"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p181983491370"><a name="zh-cn_topic_0000001208447259_p181983491370"></a><a name="zh-cn_topic_0000001208447259_p181983491370"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p10198114918711"><a name="zh-cn_topic_0000001208447259_p10198114918711"></a><a name="zh-cn_topic_0000001208447259_p10198114918711"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row121981049275"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p1519812491376"><a name="zh-cn_topic_0000001208447259_p1519812491376"></a><a name="zh-cn_topic_0000001208447259_p1519812491376"></a><a href="#zh-cn_topic_0000001208447259_section92331215118">Dirent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1919818491075"><a name="zh-cn_topic_0000001208447259_p1919818491075"></a><a name="zh-cn_topic_0000001208447259_p1919818491075"></a>表示一个目录项。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let dirent = dir.readSync();
    console.log(dirent.name);
    ```


### closeSync<a name="zh-cn_topic_0000001208447259_section1140053017119"></a>

closeSync\(\): void

用于关闭目录。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    dir.closeSync();
    ```


## Dirent<a name="zh-cn_topic_0000001208447259_section92331215118"></a>

在调用Dirent的方法前，需要先通过[readSync](#zh-cn_topic_0000001208447259_section10198204912710)方法来构建一个Dirent实例。

### 属性<a name="zh-cn_topic_0000001208447259_section152315121617"></a>

<a name="zh-cn_topic_0000001208447259_table15231112515"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row4232012216"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001208447259_p5237121715"><a name="zh-cn_topic_0000001208447259_p5237121715"></a><a name="zh-cn_topic_0000001208447259_p5237121715"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001208447259_p12313127119"><a name="zh-cn_topic_0000001208447259_p12313127119"></a><a name="zh-cn_topic_0000001208447259_p12313127119"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001208447259_p192381217113"><a name="zh-cn_topic_0000001208447259_p192381217113"></a><a name="zh-cn_topic_0000001208447259_p192381217113"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001208447259_p122320120117"><a name="zh-cn_topic_0000001208447259_p122320120117"></a><a name="zh-cn_topic_0000001208447259_p122320120117"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001208447259_p62310121212"><a name="zh-cn_topic_0000001208447259_p62310121212"></a><a name="zh-cn_topic_0000001208447259_p62310121212"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001208447259_row122317124115"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001208447259_p323612718"><a name="zh-cn_topic_0000001208447259_p323612718"></a><a name="zh-cn_topic_0000001208447259_p323612718"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001208447259_p152314121810"><a name="zh-cn_topic_0000001208447259_p152314121810"></a><a name="zh-cn_topic_0000001208447259_p152314121810"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001208447259_p1243123110"><a name="zh-cn_topic_0000001208447259_p1243123110"></a><a name="zh-cn_topic_0000001208447259_p1243123110"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001208447259_p02410125111"><a name="zh-cn_topic_0000001208447259_p02410125111"></a><a name="zh-cn_topic_0000001208447259_p02410125111"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001208447259_p924212212"><a name="zh-cn_topic_0000001208447259_p924212212"></a><a name="zh-cn_topic_0000001208447259_p924212212"></a>目录项的名称。</p>
</td>
</tr>
</tbody>
</table>

### isBlockDevice<a name="zh-cn_topic_0000001208447259_section121576105554"></a>

isBlockDevice\(\): boolean

用于判断当前目录项是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table1215761019558"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row515717101557"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p111571110175511"><a name="zh-cn_topic_0000001208447259_p111571110175511"></a><a name="zh-cn_topic_0000001208447259_p111571110175511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p17157110185519"><a name="zh-cn_topic_0000001208447259_p17157110185519"></a><a name="zh-cn_topic_0000001208447259_p17157110185519"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row715701065518"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p1115761035510"><a name="zh-cn_topic_0000001208447259_p1115761035510"></a><a name="zh-cn_topic_0000001208447259_p1115761035510"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p17157131020556"><a name="zh-cn_topic_0000001208447259_p17157131020556"></a><a name="zh-cn_topic_0000001208447259_p17157131020556"></a>表示当前目录项是否是块特殊设备。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isBLockDevice = dir.readSync().isBlockDevice();
    ```


### isCharacterDevice<a name="zh-cn_topic_0000001208447259_section20158121011550"></a>

isCharacterDevice\(\): boolean

用于判断当前目录项是否是字符特殊设备。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table315818109559"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row71588108555"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p1415812103558"><a name="zh-cn_topic_0000001208447259_p1415812103558"></a><a name="zh-cn_topic_0000001208447259_p1415812103558"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p7158151085510"><a name="zh-cn_topic_0000001208447259_p7158151085510"></a><a name="zh-cn_topic_0000001208447259_p7158151085510"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row715812103557"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p915871035513"><a name="zh-cn_topic_0000001208447259_p915871035513"></a><a name="zh-cn_topic_0000001208447259_p915871035513"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1415815107557"><a name="zh-cn_topic_0000001208447259_p1415815107557"></a><a name="zh-cn_topic_0000001208447259_p1415815107557"></a>表示当前目录项是否是字符特殊设备。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isCharacterDevice = dir.readSync().isCharacterDevice(); 
    ```


### isDirectory<a name="zh-cn_topic_0000001208447259_section181581010165520"></a>

isDirectory\(\): boolean

用于判断当前目录项是否是目录。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table51580109551"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row121581910155511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p1615821065511"><a name="zh-cn_topic_0000001208447259_p1615821065511"></a><a name="zh-cn_topic_0000001208447259_p1615821065511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p111581104550"><a name="zh-cn_topic_0000001208447259_p111581104550"></a><a name="zh-cn_topic_0000001208447259_p111581104550"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1515851014554"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p15158121011553"><a name="zh-cn_topic_0000001208447259_p15158121011553"></a><a name="zh-cn_topic_0000001208447259_p15158121011553"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p0158151019551"><a name="zh-cn_topic_0000001208447259_p0158151019551"></a><a name="zh-cn_topic_0000001208447259_p0158151019551"></a>表示当前目录项是否是目录。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isDirectory = dir.readSync().isDirectory(); 
    ```


### isFIFO<a name="zh-cn_topic_0000001208447259_section615811095517"></a>

isFIFO\(\): boolean

用于判断当前目录项是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table1015911017551"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row19159610125512"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p2159810135510"><a name="zh-cn_topic_0000001208447259_p2159810135510"></a><a name="zh-cn_topic_0000001208447259_p2159810135510"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p1315951055512"><a name="zh-cn_topic_0000001208447259_p1315951055512"></a><a name="zh-cn_topic_0000001208447259_p1315951055512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row1159151085517"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p15159201018555"><a name="zh-cn_topic_0000001208447259_p15159201018555"></a><a name="zh-cn_topic_0000001208447259_p15159201018555"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1715912105558"><a name="zh-cn_topic_0000001208447259_p1715912105558"></a><a name="zh-cn_topic_0000001208447259_p1715912105558"></a>表示当前目录项是否是FIFO。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isFIFO = dir.readSync().isFIFO(); 
    ```


### isFile<a name="zh-cn_topic_0000001208447259_section91591310195520"></a>

isFile\(\): boolean

用于判断当前目录项是否是普通文件。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table10159710185513"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row13159210195517"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p31595100554"><a name="zh-cn_topic_0000001208447259_p31595100554"></a><a name="zh-cn_topic_0000001208447259_p31595100554"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p115919106551"><a name="zh-cn_topic_0000001208447259_p115919106551"></a><a name="zh-cn_topic_0000001208447259_p115919106551"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row715916105550"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p141591310105518"><a name="zh-cn_topic_0000001208447259_p141591310105518"></a><a name="zh-cn_topic_0000001208447259_p141591310105518"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p1016041011559"><a name="zh-cn_topic_0000001208447259_p1016041011559"></a><a name="zh-cn_topic_0000001208447259_p1016041011559"></a>表示当前目录项是否是普通文件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isFile = dir.readSync().isFile(); 
    ```


### isSocket<a name="zh-cn_topic_0000001208447259_section216031020555"></a>

isSocket\(\): boolean

用于判断当前目录项是否是套接字。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table7160131085517"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row6160101045511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p716015109555"><a name="zh-cn_topic_0000001208447259_p716015109555"></a><a name="zh-cn_topic_0000001208447259_p716015109555"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p1316041075518"><a name="zh-cn_topic_0000001208447259_p1316041075518"></a><a name="zh-cn_topic_0000001208447259_p1316041075518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row2016071005519"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p131601210115514"><a name="zh-cn_topic_0000001208447259_p131601210115514"></a><a name="zh-cn_topic_0000001208447259_p131601210115514"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p6160191085520"><a name="zh-cn_topic_0000001208447259_p6160191085520"></a><a name="zh-cn_topic_0000001208447259_p6160191085520"></a>表示当前目录项是否是套接字。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isSocket = dir.readSync().isSocket(); 
    ```


### isSymbolicLink<a name="zh-cn_topic_0000001208447259_section1216010104553"></a>

isSymbolicLink\(\): boolean

用于判断当前目录项是否是符号链接。

-   返回值：

    <a name="zh-cn_topic_0000001208447259_table61602105554"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001208447259_row191601510125517"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001208447259_p121601510175510"><a name="zh-cn_topic_0000001208447259_p121601510175510"></a><a name="zh-cn_topic_0000001208447259_p121601510175510"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001208447259_p01611410175518"><a name="zh-cn_topic_0000001208447259_p01611410175518"></a><a name="zh-cn_topic_0000001208447259_p01611410175518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001208447259_row716116106551"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001208447259_p216171020556"><a name="zh-cn_topic_0000001208447259_p216171020556"></a><a name="zh-cn_topic_0000001208447259_p216171020556"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001208447259_p131614106554"><a name="zh-cn_topic_0000001208447259_p131614106554"></a><a name="zh-cn_topic_0000001208447259_p131614106554"></a>表示当前目录项是否是符号链接。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dir = fileio.opendirSync(dpath);
    let isSymbolicLink = dir.readSync().isSymbolicLink();
    ```


