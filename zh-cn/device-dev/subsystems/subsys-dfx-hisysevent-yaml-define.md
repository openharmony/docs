# HiSysEvent打点管理配置指导<a name="ZH-CN_TOPIC_0000001080478132"></a>

-   [概述](#section315316685115)
-   [yaml文件的编写](#section123181432175113)
    -   [yaml文件编写规则](#section123181432175133)
	-   [yaml文件样例](#section123181432175123)
-   [yaml文件的验证流程](#section123181432175115)
    -   [yaml文件的路径配置](#section123181432175135)
    -   [yaml文件的编译](#section123181432175137)
    -   [打点验证](#section123181432175139)
	
## 概述<a name="section315316685115"></a>

部件若有HiSysEvent事件的打点需求，则需要先定义yaml文件并在bundle.js文件中配置这些文件的路径。OpenHarmony编译框架在编译过程中则会通过python编译脚本解析校验bundle.js文件指定的所有yaml文件。在解析校验之后，编译框架会将这些yaml文件中配置的信息汇总转换成名为hisysevent.def的json文件。最后，将此json文件打包到系统指定路径下。

## yaml文件的编写<a name="section123181432175113"></a>

### yaml文件编写规则<a name="section123181432175133"></a>

1.  每个部件可定义一个或多个yaml文件，每个yaml文件只能有一个事件领域domain，且不能与其他事件领域重名，事件领域的命名规则如下：
    -   字母开头，且只能由大写字母/数字/下划线组成；
    -   字符串长度取值范围为1~16。

2.  每个事件领域可定义零个或多个事件名称event，同一个事件领域内部的事件名称不能重名，事件名称的命名规则如下：
    -   字母开头，且只能由大写字母/数字/下划线组成；
    -   字符串长度取值范围1~32；
    -   单个事件领域内部事件名称的不能超过4096个。

3.  每个事件名称可定义多个参数param，同一个事件名称内部的参数不能重名，参数的命名规则如下：
    -   字母开头，且只能由大写字母/数字/下划线组成；
    -   字符串长度取值范围1~32；
    -   单个事件名称内包含的参数的个数不能超过128个。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>每个事件名称**有且只有**一个名称为```__BASE```的参数，此参数字段组成如表1，其他自定义名称的参数，具体字段组成如表2：

**表 1**

<a name="table1844019587513"></a>
<table><thead align="left"><tr id="row1440058186118"><th class="cellrowborder" valign="top" id="mcps1.2.3.1.1"><p id="p19441135865020"><a name="p19441135845020"></a><a name="p19441135865020"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.3.1.2"><p id="p13441195865593"><a name="p13441195865593"></a><a name="p13441195865593"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155868499">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877916438213"><a name="p877916438613"></a><a name="p877916438613"></a>type</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727325136218"><a name="p14727325136218"></a><a name="p14727325136218"></a>字段说明：<br>&emsp;&emsp;必选字段，用来标识该事件名称的类型。</p>
<p id="p167271525203615"><a name="p167271525203615"></a><a name="p167271525203615"></a>取值范围：</p>
<a name="ul6717142214621"></a><a name="ul6717142214621"></a>
<ul id="ul6717142214621">
<li>FAULT：错误类型。</li>
<li>STATISTIC：统计类型。</li>
<li>SECURITY：安全性。</li>
<li>BEHAVIOR：用户行为。</li>
</ul>
</td>
</tr>
<tr id="row16441155818699">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877916438616"><a name="p877916438616"></a><a name="p877916438616"></a>level</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727325153218"><a name="p14727325153218"></a><a name="p14727325153218"></a>字段作用：<br>&emsp;&emsp;必选字段，用来标识该事件名称的级别。</p>
<p id="p167271525213215"><a name="p167271525213215"></a><a name="p167271525213215"></a>取值范围：</p>
<a name="ul6717142215021"></a><a name="ul6717142215021"></a>
<ul id="ul6717142215021">
<li>CRITICAL：严重。</li>
<li>MINOR：一般。</li>
</ul>
</td>
</tr>
<tr id="row16441155818519">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877916458213"><a name="p877916458213"></a><a name="p877916458213"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727327733218"><a name="p14727327733218"></a><a name="p14727327733218"></a>字段作用：<br>&emsp;&emsp;可选字段，用来标识该事件名称的标签。</p>
<p id="p167271395203215"><a name="p167271395203215"></a><a name="p167271395203215"></a>定义规则：</p>
<a name="ul6717143414921"></a><a name="ul6717143414921"></a>
<ul id="ul6717143414921">
<li>最多可同时定义5个标签，标签之间使用空格来分隔。</li>
<li>单个标签最多包含16个字符，字符范围[a-zA-Z0-9]。</li>
</ul>
</td>
</tr>
<tr id="row16441155817799">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877916477213"><a name="p877916477213"></a><a name="p877916477213"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727725133218"><a name="p14727725133218"></a><a name="p14727725133218"></a>字段作用：<br>&emsp;&emsp;必选字段，用来对该event进行描述。</p>
<p id="p167277525203215"><a name="p167277525203215"></a><a name="p167277525203215"></a>定义规则：</p>
<a name="ul6777142214921"></a><a name="ul6777142214921"></a>
<ul id="ul6777142214921">
<li>至少包含3个字符，最多包含128个字符，字符范围[a-zA-Z0-9 _]</li>
</ul>
</td>
</tr>
</tbody>
</table>

**表 2**

<a name="table1844019587523"></a>
<table><thead align="left"><tr id="row1440060185118"><th class="cellrowborder" valign="top" id="mcps1.2.3.1.1"><p id="p19442235845020"><a name="p19442235845020"></a><a name="p19442235845020"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.3.1.2"><p id="p13331195815593"><a name="p13331195815593"></a><a name="p13331195815593"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441232818499">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p8779163453213"><a name="p8779163453213"></a><a name="p8779163453213"></a>type</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727325235218"><a name="p14727325235218"></a><a name="p14727325235218"></a>字段说明：<br>&emsp;&emsp;必选字段，用来该参数的类型。</p>
<p id="p167271372203215"><a name="p167271372203215"></a><a name="p167271372203215"></a>取值范围：</p>
<a name="ul6717342214921"></a><a name="ul6717342214921"></a>
<ul id="ul6717134514921">
<li>BOOL</li>
<li>INT8</li>
<li>UINT8</li>
<li>INT16</li>
<li>UINT16</li>
<li>INT32</li>
<li>UINT32</li>
<li>INT64</li>
<li>UINT64</li>
<li>FLOAT</li>
<li>DOUBLE</li>
<li>STRING</li>
</ul>
</td>
</tr>
<tr id="row16326155818499">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877567438213"><a name="p877567438213"></a><a name="p877567438213"></a>arrsize</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727324893218"><a name="p14727324893218"></a><a name="p14727324893218"></a>字段作用：<br>&emsp;&emsp;可选字段，用来标识数组类型参数的长度。</p>
<p id="p1672715498703215"><a name="p1672715498703215"></a><a name="p1672715498703215"></a>取值范围：<br>&emsp;&emsp; 1~100</p>
</ul>
</td>
</tr>
<tr id="row16556155818499">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p845916438213"><a name="p845916438213"></a><a name="p845916438213"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727343133218"><a name="p14727343133218"></a><a name="p14727343133218"></a>字段作用：<br>&emsp;&emsp;必选字段，用来对该参数进行描述。</p>
<p id="p167271524323215"><a name="p167271524323215"></a><a name="p167271524323215"></a>定义规则：</p>
<a name="ul6717142111921"></a><a name="ul6717142111921"></a>
<ul id="ul6717156714921">
<li>至少包含3个字符，最多包含128个字符，字符范围[a-zA-Z0-9 _]</li>
</ul>
</td>
</tr>
</tbody>
</table>

### yaml文件样例及说明<a name="section123181432175123"></a>

```
##########################################
# the hisysevent definition for module a #
##########################################

domain: MODULEA

EVENT_NAMEA:
    __BASE: {type: FAULT, level: CRITICAL, desc: event name a}
    NAME1: {type: STRING, desc: name1}
    NAME2: {type: STRING, desc: name2}
    NAME3: {type: UINT16, desc: name3}

EVENT_NAMEB:
    __BASE: {type: STATISTIC, level: MINOR, tag: tag1 tag2, desc: event name b}
    NAME1: {type: UINT16, desc: name1}
    NAME2: {type: INT32, desc: name2}

```

**样例说明**：
-   该yaml文件指定的事件领域名称为MODULEA，该事件领域包含两个事件，名称分别是EVENT_NAMEA和EVENT_NAMEB。
-   EVENT_NAMEA被定义成错误类型的严重事件，该事件包含类型为字符串类型的NAME1参数、字符串类型的NAME2参数及无符号短整型类型的NAME3参数，可以通过事件领域MODULEA和事件名称EVENT_NAMEA对其进行[实时订阅](subsys-dfx-hisysevent-read.md)。
-   EVENT_NAMEB被定义成统计类型的一般事件，EVENT_NAMEB包含类型为无符号短整型类型的NAME1参数及整型类型的NAME2参数。因为EVENT_NAMEB在__BASE参数中定义了名称为tag1和tag2的两个事件标签，所以不仅可以通过事件领域MODULEA和事件名称EVENT_NAMEB对其进行[实时订阅](subsys-dfx-hisysevent-read.md)，，所以还可以通过事件标签对该事件进行[实时订阅](subsys-dfx-hisysevent-read.md)。

## yaml文件的验证流程<a name="section123181432175115"></a>

### yaml文件的路径配置<a name="section123181432175135"></a>

-   在bundle.js文件中通过```hisysevent_config```属性完成yaml文件的路径指定：

```
{
    "name": "@ohos/moduel_a",
    "description": "module a",
    "version": "3.1",
    "license": "Apache License 2.0",
    "publishAs": "code-segment",
    "segment": {
        "destPath": "moduel_a_path"
    },
    "dirs": {},
    "scripts": {},
    "component": {
        "name": "hisysevent_native",
        "subsystem": "hiviewdfx",
        "adapted_system_type": [
            "standard"
        ],
        "rom": "",
        "ram": "",
        "hisysevent_config": [
            "//moduel_a_path/yaml_file1.yaml",
            "//moduel_a_path/yaml_file2.yaml"
        ],
        "deps": {
            "components": [
                "hilog_native",
                "hitrace_native",
                "ipc",
                "safwk",
                "samgr_standard",
                "utils_base"
            ],
            "third_party": []
        },
        "build": {
        }
    }
}
```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>yaml文件可根据实际需求置于部件工程的任意目录下，只要在bundle.js文件指定即可。

### yaml文件的编译<a name="section123181432175137"></a>

-   全量编译：

    -   全量编译整个系统，会将所有部件配置的yaml文件中的配置进行汇总，正常完成系统编译后，指定目录下就会生成hisysevent.def文件。

    ```
    cd 工程根目录的绝对路径 | ./build --product-name <product name>
    ```

    -   全量编译生成的hisysevent.def文件可以通过以下命令获取：

    ```
    cd 工程根目录的绝对路径 | find out -name hisysevent.def -type f
    ```

-   单文件编译：

    也可以只编译单个部件的yaml文件，命令如下：

    ```
    cd 工程根目录的绝对路径 | ./build/ohos/hisysevent/gen_def_from_all_yaml.py --yaml-list <yaml file list> --def-path <file store directory>
    ```

**表 3**

<a name="table1844019587534"></a>
<table><thead align="left"><tr id="row1440056575118"><th class="cellrowborder" valign="top" id="mcps1.2.3.1.1"><p id="p19432435845020"><a name="p19432435845020"></a><a name="p19432435845020"></a>选项名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.3.1.2"><p id="p13441196715593"><a name="p13441196715593"></a><a name="p13441196715593"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155854499">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877916558213"><a name="p877916558213"></a><a name="p877916558213"></a>--yaml-list</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727325133218"><a name="p14727325133218"></a><a name="p14727325133218"></a>指定需要编译的yaml文件路径列表，多个yaml文件路径之间用空格分隔。</p>
</td><tr id="row16441155832499">
<td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 ">
<p id="p877916421213"><a name="p877916421213"></a><a name="p877916421213"></a>--def-path</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 ">
<p id="p14727323533218"><a name="p14727323533218"></a><a name="p14727323533218"></a>指定编译生成的hisysevent.def文件的生成路径。</p>
</td>
</tr>
</tbody>
</table>

### 打点验证<a name="section123181432175139"></a>

1.  通过[hdc工具](subsys-toolchain-hdc-guide.md)将hisysevent.def文件推送到至设备的//system/etc/hiview/目录下;

2.  触发HiSysEvent事件打点，通过[hisysevent工具](subsys-dfx-hisysevent-tool.md)查询历史HiSysEvent事件，确认触发的HiSysEvent事件是否打点成功。
