# 轻量级存储<a name="ZH-CN_TOPIC_0000001163812238"></a>

轻量级数据库为应用提供key-value键值型的文件数据处理能力，支持应用对数据进行轻量级存储及查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型。

## 导入模块<a name="zh-cn_topic_0000001117163542_s56d19203690d4782bfc74069abb6bd71"></a>

```
import data_storage from '@ohos.data.storage';
```

## 权限<a name="zh-cn_topic_0000001117163542_section11257113618419"></a>

无

## 属性<a name="zh-cn_topic_0000001117163542_section7299123218370"></a>

<a name="zh-cn_topic_0000001117163542_table1540155452420"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1947713549244"><th class="cellrowborder" valign="top" width="21.86%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001117163542_p74771754102410"><a name="zh-cn_topic_0000001117163542_p74771754102410"></a><a name="zh-cn_topic_0000001117163542_p74771754102410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.15%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001117163542_p1047755412411"><a name="zh-cn_topic_0000001117163542_p1047755412411"></a><a name="zh-cn_topic_0000001117163542_p1047755412411"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001117163542_p34782054192412"><a name="zh-cn_topic_0000001117163542_p34782054192412"></a><a name="zh-cn_topic_0000001117163542_p34782054192412"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.62%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001117163542_p1847865452413"><a name="zh-cn_topic_0000001117163542_p1847865452413"></a><a name="zh-cn_topic_0000001117163542_p1847865452413"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="46.03%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001117163542_p12478954132419"><a name="zh-cn_topic_0000001117163542_p12478954132419"></a><a name="zh-cn_topic_0000001117163542_p12478954132419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1247811541240"><td class="cellrowborder" valign="top" width="21.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001117163542_p51525360147"><a name="zh-cn_topic_0000001117163542_p51525360147"></a><a name="zh-cn_topic_0000001117163542_p51525360147"></a>MAX_KEY_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="11.15%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001117163542_p9478135414243"><a name="zh-cn_topic_0000001117163542_p9478135414243"></a><a name="zh-cn_topic_0000001117163542_p9478135414243"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001117163542_p1247885492411"><a name="zh-cn_topic_0000001117163542_p1247885492411"></a><a name="zh-cn_topic_0000001117163542_p1247885492411"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.62%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001117163542_p3478054192416"><a name="zh-cn_topic_0000001117163542_p3478054192416"></a><a name="zh-cn_topic_0000001117163542_p3478054192416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.03%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001117163542_p12478654172415"><a name="zh-cn_topic_0000001117163542_p12478654172415"></a><a name="zh-cn_topic_0000001117163542_p12478654172415"></a>key的最大长度限制，大小为80字节。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row184789546249"><td class="cellrowborder" valign="top" width="21.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001117163542_p1971014525154"><a name="zh-cn_topic_0000001117163542_p1971014525154"></a><a name="zh-cn_topic_0000001117163542_p1971014525154"></a>MAX_VALUE_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="11.15%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001117163542_p1392172791820"><a name="zh-cn_topic_0000001117163542_p1392172791820"></a><a name="zh-cn_topic_0000001117163542_p1392172791820"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001117163542_p1870905231512"><a name="zh-cn_topic_0000001117163542_p1870905231512"></a><a name="zh-cn_topic_0000001117163542_p1870905231512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.62%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001117163542_p137081152141516"><a name="zh-cn_topic_0000001117163542_p137081152141516"></a><a name="zh-cn_topic_0000001117163542_p137081152141516"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.03%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001117163542_p1470645211154"><a name="zh-cn_topic_0000001117163542_p1470645211154"></a><a name="zh-cn_topic_0000001117163542_p1470645211154"></a>string类型value的最大长度限制，大小为8192字节。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001117163542_section88091318127"></a>

## getStorageSync\(path: string\)<a name="zh-cn_topic_0000001117163542_section172447329132"></a>

读取指定文件，将数据加载到Storage实例，用于数据操作。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table2720134112170"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row18721041131710"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p19721184111716"><a name="zh-cn_topic_0000001117163542_p19721184111716"></a><a name="zh-cn_topic_0000001117163542_p19721184111716"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p672184171715"><a name="zh-cn_topic_0000001117163542_p672184171715"></a><a name="zh-cn_topic_0000001117163542_p672184171715"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p972174116173"><a name="zh-cn_topic_0000001117163542_p972174116173"></a><a name="zh-cn_topic_0000001117163542_p972174116173"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1372134161712"><a name="zh-cn_topic_0000001117163542_p1372134161712"></a><a name="zh-cn_topic_0000001117163542_p1372134161712"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row11721541121717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1472154117175"><a name="zh-cn_topic_0000001117163542_p1472154117175"></a><a name="zh-cn_topic_0000001117163542_p1472154117175"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p372134110175"><a name="zh-cn_topic_0000001117163542_p372134110175"></a><a name="zh-cn_topic_0000001117163542_p372134110175"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p19721134101713"><a name="zh-cn_topic_0000001117163542_p19721134101713"></a><a name="zh-cn_topic_0000001117163542_p19721134101713"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1068312615010"><a name="zh-cn_topic_0000001117163542_p1068312615010"></a><a name="zh-cn_topic_0000001117163542_p1068312615010"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table372204131719"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row8722124116175"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p4722041171712"><a name="zh-cn_topic_0000001117163542_p4722041171712"></a><a name="zh-cn_topic_0000001117163542_p4722041171712"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p072234114173"><a name="zh-cn_topic_0000001117163542_p072234114173"></a><a name="zh-cn_topic_0000001117163542_p072234114173"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row4722144111715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p16723164161713"><a name="zh-cn_topic_0000001117163542_p16723164161713"></a><a name="zh-cn_topic_0000001117163542_p16723164161713"></a><a href="#zh-cn_topic_0000001117163542_section12882825611">Storage</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p12723741161713"><a name="zh-cn_topic_0000001117163542_p12723741161713"></a><a name="zh-cn_topic_0000001117163542_p12723741161713"></a>获取到要操作的Storage实例，用于进行数据库的操作。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const PATH = '/data/accounts/account_0/appdata/com.example.myapplication/database/{storage_name}';
let store = data_storage.getStorageSync(PATH);
```

## getStorage\(path: string, callback: AsyncCallback<Storage\>\)<a name="zh-cn_topic_0000001117163542_section192192415554"></a>

读取指定文件，将数据加载到Storage实例，用于数据操作。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table69661135912"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row149668318915"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p7966738914"><a name="zh-cn_topic_0000001117163542_p7966738914"></a><a name="zh-cn_topic_0000001117163542_p7966738914"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p296713699"><a name="zh-cn_topic_0000001117163542_p296713699"></a><a name="zh-cn_topic_0000001117163542_p296713699"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p196718315911"><a name="zh-cn_topic_0000001117163542_p196718315911"></a><a name="zh-cn_topic_0000001117163542_p196718315911"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p9967231197"><a name="zh-cn_topic_0000001117163542_p9967231197"></a><a name="zh-cn_topic_0000001117163542_p9967231197"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row99671533914"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p79671633910"><a name="zh-cn_topic_0000001117163542_p79671633910"></a><a name="zh-cn_topic_0000001117163542_p79671633910"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p11967433914"><a name="zh-cn_topic_0000001117163542_p11967433914"></a><a name="zh-cn_topic_0000001117163542_p11967433914"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p19671336916"><a name="zh-cn_topic_0000001117163542_p19671336916"></a><a name="zh-cn_topic_0000001117163542_p19671336916"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p98628113304"><a name="zh-cn_topic_0000001117163542_p98628113304"></a><a name="zh-cn_topic_0000001117163542_p98628113304"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row128961021101812"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p6897172121814"><a name="zh-cn_topic_0000001117163542_p6897172121814"></a><a name="zh-cn_topic_0000001117163542_p6897172121814"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p9897102181813"><a name="zh-cn_topic_0000001117163542_p9897102181813"></a><a name="zh-cn_topic_0000001117163542_p9897102181813"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001117163542_section12882825611">Storage</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p188982219189"><a name="zh-cn_topic_0000001117163542_p188982219189"></a><a name="zh-cn_topic_0000001117163542_p188982219189"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p989815213187"><a name="zh-cn_topic_0000001117163542_p989815213187"></a><a name="zh-cn_topic_0000001117163542_p989815213187"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table16391145317913"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row2391145319910"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p13911353991"><a name="zh-cn_topic_0000001117163542_p13911353991"></a><a name="zh-cn_topic_0000001117163542_p13911353991"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p193911531395"><a name="zh-cn_topic_0000001117163542_p193911531395"></a><a name="zh-cn_topic_0000001117163542_p193911531395"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1339114531391"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p1777116115195"><a name="zh-cn_topic_0000001117163542_p1777116115195"></a><a name="zh-cn_topic_0000001117163542_p1777116115195"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p1039217531898"><a name="zh-cn_topic_0000001117163542_p1039217531898"></a><a name="zh-cn_topic_0000001117163542_p1039217531898"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
data_storage.getStorage(PATH, function(err, data) {    
   strore = data;
});
```

## getStorage\(path: string\)<a name="zh-cn_topic_0000001117163542_section761705115251"></a>

读取指定文件，将数据加载到Storage实例，用于数据操作。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table206180511253"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row126181951152513"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p20618155112513"><a name="zh-cn_topic_0000001117163542_p20618155112513"></a><a name="zh-cn_topic_0000001117163542_p20618155112513"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p561885114256"><a name="zh-cn_topic_0000001117163542_p561885114256"></a><a name="zh-cn_topic_0000001117163542_p561885114256"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p561814519259"><a name="zh-cn_topic_0000001117163542_p561814519259"></a><a name="zh-cn_topic_0000001117163542_p561814519259"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1861845120252"><a name="zh-cn_topic_0000001117163542_p1861845120252"></a><a name="zh-cn_topic_0000001117163542_p1861845120252"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row6619751162515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p196192514253"><a name="zh-cn_topic_0000001117163542_p196192514253"></a><a name="zh-cn_topic_0000001117163542_p196192514253"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p36191951162515"><a name="zh-cn_topic_0000001117163542_p36191951162515"></a><a name="zh-cn_topic_0000001117163542_p36191951162515"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p16191051162511"><a name="zh-cn_topic_0000001117163542_p16191051162511"></a><a name="zh-cn_topic_0000001117163542_p16191051162511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p48655421106"><a name="zh-cn_topic_0000001117163542_p48655421106"></a><a name="zh-cn_topic_0000001117163542_p48655421106"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table2619551122516"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row46201751152513"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p1162075110255"><a name="zh-cn_topic_0000001117163542_p1162075110255"></a><a name="zh-cn_topic_0000001117163542_p1162075110255"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p46202512251"><a name="zh-cn_topic_0000001117163542_p46202512251"></a><a name="zh-cn_topic_0000001117163542_p46202512251"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row562015514258"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p146201551122516"><a name="zh-cn_topic_0000001117163542_p146201551122516"></a><a name="zh-cn_topic_0000001117163542_p146201551122516"></a>Promise&lt;Storage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p1062005172514"><a name="zh-cn_topic_0000001117163542_p1062005172514"></a><a name="zh-cn_topic_0000001117163542_p1062005172514"></a>Promise实例，用于异步获取结果。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = data_storage.getStorage(PATH);
promise.then((data) => {   
   data.clearSync();
   }).catch((err) => {
});
```

## deleteStorageSync\(path: string\)<a name="zh-cn_topic_0000001117163542_section1396463815379"></a>

从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table99651538193711"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1296553843712"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p19965183833714"><a name="zh-cn_topic_0000001117163542_p19965183833714"></a><a name="zh-cn_topic_0000001117163542_p19965183833714"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p9965153863713"><a name="zh-cn_topic_0000001117163542_p9965153863713"></a><a name="zh-cn_topic_0000001117163542_p9965153863713"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p15965133819375"><a name="zh-cn_topic_0000001117163542_p15965133819375"></a><a name="zh-cn_topic_0000001117163542_p15965133819375"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p496518383377"><a name="zh-cn_topic_0000001117163542_p496518383377"></a><a name="zh-cn_topic_0000001117163542_p496518383377"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row6965238143718"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p18965163816378"><a name="zh-cn_topic_0000001117163542_p18965163816378"></a><a name="zh-cn_topic_0000001117163542_p18965163816378"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p10965193816372"><a name="zh-cn_topic_0000001117163542_p10965193816372"></a><a name="zh-cn_topic_0000001117163542_p10965193816372"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p896623833719"><a name="zh-cn_topic_0000001117163542_p896623833719"></a><a name="zh-cn_topic_0000001117163542_p896623833719"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1461995119256"><a name="zh-cn_topic_0000001117163542_p1461995119256"></a><a name="zh-cn_topic_0000001117163542_p1461995119256"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table13966838153711"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row89664383379"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p169661638163716"><a name="zh-cn_topic_0000001117163542_p169661638163716"></a><a name="zh-cn_topic_0000001117163542_p169661638163716"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p29661138123715"><a name="zh-cn_topic_0000001117163542_p29661138123715"></a><a name="zh-cn_topic_0000001117163542_p29661138123715"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row796614387378"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p696653853714"><a name="zh-cn_topic_0000001117163542_p696653853714"></a><a name="zh-cn_topic_0000001117163542_p696653853714"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p11966103843716"><a name="zh-cn_topic_0000001117163542_p11966103843716"></a><a name="zh-cn_topic_0000001117163542_p11966103843716"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const PATH = '/data/accounts/account_0/appdata/com.example.myapplication/database/{storage_name}';
data_storage.deleteStorageSync(PATH);
```

## deleteStorage\(path: string, callback: AsyncCallback<Storage\>\)<a name="zh-cn_topic_0000001117163542_section17967123883712"></a>

从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table1296893843713"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row5968193863710"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p99681338103714"><a name="zh-cn_topic_0000001117163542_p99681338103714"></a><a name="zh-cn_topic_0000001117163542_p99681338103714"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p1968838123715"><a name="zh-cn_topic_0000001117163542_p1968838123715"></a><a name="zh-cn_topic_0000001117163542_p1968838123715"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p14968123803720"><a name="zh-cn_topic_0000001117163542_p14968123803720"></a><a name="zh-cn_topic_0000001117163542_p14968123803720"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p7968238143715"><a name="zh-cn_topic_0000001117163542_p7968238143715"></a><a name="zh-cn_topic_0000001117163542_p7968238143715"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row129691538133719"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p14969438143718"><a name="zh-cn_topic_0000001117163542_p14969438143718"></a><a name="zh-cn_topic_0000001117163542_p14969438143718"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p9969123873716"><a name="zh-cn_topic_0000001117163542_p9969123873716"></a><a name="zh-cn_topic_0000001117163542_p9969123873716"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p159691438173711"><a name="zh-cn_topic_0000001117163542_p159691438173711"></a><a name="zh-cn_topic_0000001117163542_p159691438173711"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p06171654601"><a name="zh-cn_topic_0000001117163542_p06171654601"></a><a name="zh-cn_topic_0000001117163542_p06171654601"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row9969173819374"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p69691238153715"><a name="zh-cn_topic_0000001117163542_p69691238153715"></a><a name="zh-cn_topic_0000001117163542_p69691238153715"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p149691380378"><a name="zh-cn_topic_0000001117163542_p149691380378"></a><a name="zh-cn_topic_0000001117163542_p149691380378"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001117163542_section12882825611">Storage</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p2969103843715"><a name="zh-cn_topic_0000001117163542_p2969103843715"></a><a name="zh-cn_topic_0000001117163542_p2969103843715"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p396915388374"><a name="zh-cn_topic_0000001117163542_p396915388374"></a><a name="zh-cn_topic_0000001117163542_p396915388374"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table15970938123715"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row3970638173711"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p12970183811375"><a name="zh-cn_topic_0000001117163542_p12970183811375"></a><a name="zh-cn_topic_0000001117163542_p12970183811375"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p159701938143717"><a name="zh-cn_topic_0000001117163542_p159701938143717"></a><a name="zh-cn_topic_0000001117163542_p159701938143717"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row9970438123710"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p139701038103712"><a name="zh-cn_topic_0000001117163542_p139701038103712"></a><a name="zh-cn_topic_0000001117163542_p139701038103712"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p997073811371"><a name="zh-cn_topic_0000001117163542_p997073811371"></a><a name="zh-cn_topic_0000001117163542_p997073811371"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
data_storage.deleteStorage(PATH, function(err, data) {    
});
```

## deleteStorage\(path: string\)<a name="zh-cn_topic_0000001117163542_section1497163823719"></a>

从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table597293815378"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row29721938203716"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p19972173883714"><a name="zh-cn_topic_0000001117163542_p19972173883714"></a><a name="zh-cn_topic_0000001117163542_p19972173883714"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p49721938103718"><a name="zh-cn_topic_0000001117163542_p49721938103718"></a><a name="zh-cn_topic_0000001117163542_p49721938103718"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p17972113863711"><a name="zh-cn_topic_0000001117163542_p17972113863711"></a><a name="zh-cn_topic_0000001117163542_p17972113863711"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p15972838123714"><a name="zh-cn_topic_0000001117163542_p15972838123714"></a><a name="zh-cn_topic_0000001117163542_p15972838123714"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1972163818374"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p597373833717"><a name="zh-cn_topic_0000001117163542_p597373833717"></a><a name="zh-cn_topic_0000001117163542_p597373833717"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p11973173814378"><a name="zh-cn_topic_0000001117163542_p11973173814378"></a><a name="zh-cn_topic_0000001117163542_p11973173814378"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p209732388379"><a name="zh-cn_topic_0000001117163542_p209732388379"></a><a name="zh-cn_topic_0000001117163542_p209732388379"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p20324115919012"><a name="zh-cn_topic_0000001117163542_p20324115919012"></a><a name="zh-cn_topic_0000001117163542_p20324115919012"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table5973738153710"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row17973238123713"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p17973538183719"><a name="zh-cn_topic_0000001117163542_p17973538183719"></a><a name="zh-cn_topic_0000001117163542_p17973538183719"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p109731385374"><a name="zh-cn_topic_0000001117163542_p109731385374"></a><a name="zh-cn_topic_0000001117163542_p109731385374"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row89731838173711"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p34467362719"><a name="zh-cn_topic_0000001117163542_p34467362719"></a><a name="zh-cn_topic_0000001117163542_p34467362719"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p15446536474"><a name="zh-cn_topic_0000001117163542_p15446536474"></a><a name="zh-cn_topic_0000001117163542_p15446536474"></a>Promise实例，用于异步获取结果。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = data_storage.deleteStorage(PATH);
promise.then((data) => {   
    }).catch((err) => {
});
```

## removeStorageFromCacheSync\(path: string\)<a name="zh-cn_topic_0000001117163542_section1212418572425"></a>

从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table121245571424"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row61241257164218"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p13125165744216"><a name="zh-cn_topic_0000001117163542_p13125165744216"></a><a name="zh-cn_topic_0000001117163542_p13125165744216"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p141259575429"><a name="zh-cn_topic_0000001117163542_p141259575429"></a><a name="zh-cn_topic_0000001117163542_p141259575429"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p1312515724213"><a name="zh-cn_topic_0000001117163542_p1312515724213"></a><a name="zh-cn_topic_0000001117163542_p1312515724213"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p6125157124212"><a name="zh-cn_topic_0000001117163542_p6125157124212"></a><a name="zh-cn_topic_0000001117163542_p6125157124212"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1112595715421"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1712610572429"><a name="zh-cn_topic_0000001117163542_p1712610572429"></a><a name="zh-cn_topic_0000001117163542_p1712610572429"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p5126457164217"><a name="zh-cn_topic_0000001117163542_p5126457164217"></a><a name="zh-cn_topic_0000001117163542_p5126457164217"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p19126457134212"><a name="zh-cn_topic_0000001117163542_p19126457134212"></a><a name="zh-cn_topic_0000001117163542_p19126457134212"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p2188654116"><a name="zh-cn_topic_0000001117163542_p2188654116"></a><a name="zh-cn_topic_0000001117163542_p2188654116"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table1412655711424"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row4126257104216"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p10126757144216"><a name="zh-cn_topic_0000001117163542_p10126757144216"></a><a name="zh-cn_topic_0000001117163542_p10126757144216"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p3127195720429"><a name="zh-cn_topic_0000001117163542_p3127195720429"></a><a name="zh-cn_topic_0000001117163542_p3127195720429"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row312795754210"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p15127105794220"><a name="zh-cn_topic_0000001117163542_p15127105794220"></a><a name="zh-cn_topic_0000001117163542_p15127105794220"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p11127857164219"><a name="zh-cn_topic_0000001117163542_p11127857164219"></a><a name="zh-cn_topic_0000001117163542_p11127857164219"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const PATH = '/data/accounts/account_0/appdata/com.example.myapplication/database/{storage_name}';
data_storage.removeStorageFromCacheSync(PATH);
```

## removeStorageFromCache\(path: string, callback: AsyncCallback<Storage\>\)<a name="zh-cn_topic_0000001117163542_section141288570429"></a>

从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table12128115713423"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row131291857124212"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p181291157174220"><a name="zh-cn_topic_0000001117163542_p181291157174220"></a><a name="zh-cn_topic_0000001117163542_p181291157174220"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p20129205715426"><a name="zh-cn_topic_0000001117163542_p20129205715426"></a><a name="zh-cn_topic_0000001117163542_p20129205715426"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p21294574428"><a name="zh-cn_topic_0000001117163542_p21294574428"></a><a name="zh-cn_topic_0000001117163542_p21294574428"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p512965716425"><a name="zh-cn_topic_0000001117163542_p512965716425"></a><a name="zh-cn_topic_0000001117163542_p512965716425"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row21299574423"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p17129105714421"><a name="zh-cn_topic_0000001117163542_p17129105714421"></a><a name="zh-cn_topic_0000001117163542_p17129105714421"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p7129185794217"><a name="zh-cn_topic_0000001117163542_p7129185794217"></a><a name="zh-cn_topic_0000001117163542_p7129185794217"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p813075717426"><a name="zh-cn_topic_0000001117163542_p813075717426"></a><a name="zh-cn_topic_0000001117163542_p813075717426"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p3442141014113"><a name="zh-cn_topic_0000001117163542_p3442141014113"></a><a name="zh-cn_topic_0000001117163542_p3442141014113"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row1813015717423"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p813085711421"><a name="zh-cn_topic_0000001117163542_p813085711421"></a><a name="zh-cn_topic_0000001117163542_p813085711421"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p013085719427"><a name="zh-cn_topic_0000001117163542_p013085719427"></a><a name="zh-cn_topic_0000001117163542_p013085719427"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001117163542_section12882825611">Storage</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p181301457184219"><a name="zh-cn_topic_0000001117163542_p181301457184219"></a><a name="zh-cn_topic_0000001117163542_p181301457184219"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p191301575425"><a name="zh-cn_topic_0000001117163542_p191301575425"></a><a name="zh-cn_topic_0000001117163542_p191301575425"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table16130857134217"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1313118572427"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p14131145715426"><a name="zh-cn_topic_0000001117163542_p14131145715426"></a><a name="zh-cn_topic_0000001117163542_p14131145715426"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p51311957184213"><a name="zh-cn_topic_0000001117163542_p51311957184213"></a><a name="zh-cn_topic_0000001117163542_p51311957184213"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row5131185717420"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p111311557154213"><a name="zh-cn_topic_0000001117163542_p111311557154213"></a><a name="zh-cn_topic_0000001117163542_p111311557154213"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p3131857174214"><a name="zh-cn_topic_0000001117163542_p3131857174214"></a><a name="zh-cn_topic_0000001117163542_p3131857174214"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
data_storage.removeStorageFromCache(PATH, function(err, data) {
});
```

## removeStorageFromCache\(path: string\)<a name="zh-cn_topic_0000001117163542_section1813245718422"></a>

从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table2133125713429"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row9133857194218"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p813355716423"><a name="zh-cn_topic_0000001117163542_p813355716423"></a><a name="zh-cn_topic_0000001117163542_p813355716423"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p213495712420"><a name="zh-cn_topic_0000001117163542_p213495712420"></a><a name="zh-cn_topic_0000001117163542_p213495712420"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p713465724210"><a name="zh-cn_topic_0000001117163542_p713465724210"></a><a name="zh-cn_topic_0000001117163542_p713465724210"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p413425734218"><a name="zh-cn_topic_0000001117163542_p413425734218"></a><a name="zh-cn_topic_0000001117163542_p413425734218"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row0134105716421"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p14134135744212"><a name="zh-cn_topic_0000001117163542_p14134135744212"></a><a name="zh-cn_topic_0000001117163542_p14134135744212"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p613417578427"><a name="zh-cn_topic_0000001117163542_p613417578427"></a><a name="zh-cn_topic_0000001117163542_p613417578427"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p313555724217"><a name="zh-cn_topic_0000001117163542_p313555724217"></a><a name="zh-cn_topic_0000001117163542_p313555724217"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p4728181510119"><a name="zh-cn_topic_0000001117163542_p4728181510119"></a><a name="zh-cn_topic_0000001117163542_p4728181510119"></a>应用程序内部数据存储路径。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table513585718424"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row191352576429"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p51351257104220"><a name="zh-cn_topic_0000001117163542_p51351257104220"></a><a name="zh-cn_topic_0000001117163542_p51351257104220"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p113611571421"><a name="zh-cn_topic_0000001117163542_p113611571421"></a><a name="zh-cn_topic_0000001117163542_p113611571421"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row0136165744213"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p159416454718"><a name="zh-cn_topic_0000001117163542_p159416454718"></a><a name="zh-cn_topic_0000001117163542_p159416454718"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p13941645472"><a name="zh-cn_topic_0000001117163542_p13941645472"></a><a name="zh-cn_topic_0000001117163542_p13941645472"></a>Promise实例，用于异步获取结果。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = data_storage.removeStorageFromCache(PATH);
promise.then((data) => {   
     }).catch((err) => {
});
```

## 附录<a name="zh-cn_topic_0000001117163542_section1933416317165"></a>

## Storage<a name="zh-cn_topic_0000001117163542_section12882825611"></a>

提供获取和修改存储数据的接口。

## 方法<a name="zh-cn_topic_0000001117163542_section1442928184214"></a>

## getSync\(key: string, defValue: ValueType\)<a name="zh-cn_topic_0000001117163542_section175783467507"></a>

获取键对应的值，如果值为null或者非默认值类型，返默认数据

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table20579646175015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row5579164695016"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p7579174612503"><a name="zh-cn_topic_0000001117163542_p7579174612503"></a><a name="zh-cn_topic_0000001117163542_p7579174612503"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p6579164685015"><a name="zh-cn_topic_0000001117163542_p6579164685015"></a><a name="zh-cn_topic_0000001117163542_p6579164685015"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p7580144625010"><a name="zh-cn_topic_0000001117163542_p7580144625010"></a><a name="zh-cn_topic_0000001117163542_p7580144625010"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p6580446195018"><a name="zh-cn_topic_0000001117163542_p6580446195018"></a><a name="zh-cn_topic_0000001117163542_p6580446195018"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row958034616501"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p2580144610505"><a name="zh-cn_topic_0000001117163542_p2580144610505"></a><a name="zh-cn_topic_0000001117163542_p2580144610505"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p175802469504"><a name="zh-cn_topic_0000001117163542_p175802469504"></a><a name="zh-cn_topic_0000001117163542_p175802469504"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p11580124614504"><a name="zh-cn_topic_0000001117163542_p11580124614504"></a><a name="zh-cn_topic_0000001117163542_p11580124614504"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p155801846185019"><a name="zh-cn_topic_0000001117163542_p155801846185019"></a><a name="zh-cn_topic_0000001117163542_p155801846185019"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row0459124213526"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p14460114212525"><a name="zh-cn_topic_0000001117163542_p14460114212525"></a><a name="zh-cn_topic_0000001117163542_p14460114212525"></a>defValue</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p8460114255218"><a name="zh-cn_topic_0000001117163542_p8460114255218"></a><a name="zh-cn_topic_0000001117163542_p8460114255218"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p24601842125212"><a name="zh-cn_topic_0000001117163542_p24601842125212"></a><a name="zh-cn_topic_0000001117163542_p24601842125212"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1246094210525"><a name="zh-cn_topic_0000001117163542_p1246094210525"></a><a name="zh-cn_topic_0000001117163542_p1246094210525"></a>给定key的存储不存在，则要返回的默认值。支持number 、 string 、boolean。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table6580194685018"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row165817461506"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p6581124635014"><a name="zh-cn_topic_0000001117163542_p6581124635014"></a><a name="zh-cn_topic_0000001117163542_p6581124635014"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p155812466505"><a name="zh-cn_topic_0000001117163542_p155812466505"></a><a name="zh-cn_topic_0000001117163542_p155812466505"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row158144625016"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p1458174605020"><a name="zh-cn_topic_0000001117163542_p1458174605020"></a><a name="zh-cn_topic_0000001117163542_p1458174605020"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p9581174695017"><a name="zh-cn_topic_0000001117163542_p9581174695017"></a><a name="zh-cn_topic_0000001117163542_p9581174695017"></a>键对应的值，如果值为null或者非默认值类型，返默认数据</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
let ret = store.getSync(key, ‘defValue’);
```

## get\(key: string, defValue: ValueType, callback: AsyncCallback<ValueType\>\)<a name="zh-cn_topic_0000001117163542_section858234618501"></a>

获取键对应的值，如果值为null或者非默认值类型，返默认数据。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table16582546105019"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row35829466507"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p1758324675012"><a name="zh-cn_topic_0000001117163542_p1758324675012"></a><a name="zh-cn_topic_0000001117163542_p1758324675012"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p05833469507"><a name="zh-cn_topic_0000001117163542_p05833469507"></a><a name="zh-cn_topic_0000001117163542_p05833469507"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p558344615503"><a name="zh-cn_topic_0000001117163542_p558344615503"></a><a name="zh-cn_topic_0000001117163542_p558344615503"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1958314614504"><a name="zh-cn_topic_0000001117163542_p1958314614504"></a><a name="zh-cn_topic_0000001117163542_p1958314614504"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row95831446165019"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1958354695012"><a name="zh-cn_topic_0000001117163542_p1958354695012"></a><a name="zh-cn_topic_0000001117163542_p1958354695012"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p2583174615017"><a name="zh-cn_topic_0000001117163542_p2583174615017"></a><a name="zh-cn_topic_0000001117163542_p2583174615017"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p758314617509"><a name="zh-cn_topic_0000001117163542_p758314617509"></a><a name="zh-cn_topic_0000001117163542_p758314617509"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p8583846195019"><a name="zh-cn_topic_0000001117163542_p8583846195019"></a><a name="zh-cn_topic_0000001117163542_p8583846195019"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row178702311721"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p118713316216"><a name="zh-cn_topic_0000001117163542_p118713316216"></a><a name="zh-cn_topic_0000001117163542_p118713316216"></a>defValue</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p8871133118215"><a name="zh-cn_topic_0000001117163542_p8871133118215"></a><a name="zh-cn_topic_0000001117163542_p8871133118215"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p1387173113211"><a name="zh-cn_topic_0000001117163542_p1387173113211"></a><a name="zh-cn_topic_0000001117163542_p1387173113211"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p6871153116215"><a name="zh-cn_topic_0000001117163542_p6871153116215"></a><a name="zh-cn_topic_0000001117163542_p6871153116215"></a>默认返回值。支持number 、 string 、boolean。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row13583144610506"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p658384675012"><a name="zh-cn_topic_0000001117163542_p658384675012"></a><a name="zh-cn_topic_0000001117163542_p658384675012"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p18583144605020"><a name="zh-cn_topic_0000001117163542_p18583144605020"></a><a name="zh-cn_topic_0000001117163542_p18583144605020"></a>AsyncCallback&lt;ValueType&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p17583104665016"><a name="zh-cn_topic_0000001117163542_p17583104665016"></a><a name="zh-cn_topic_0000001117163542_p17583104665016"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p758334625010"><a name="zh-cn_topic_0000001117163542_p758334625010"></a><a name="zh-cn_topic_0000001117163542_p758334625010"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table19584154619506"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row3584546205017"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p2584546135015"><a name="zh-cn_topic_0000001117163542_p2584546135015"></a><a name="zh-cn_topic_0000001117163542_p2584546135015"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p7584164665013"><a name="zh-cn_topic_0000001117163542_p7584164665013"></a><a name="zh-cn_topic_0000001117163542_p7584164665013"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row35847461505"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p1258410462501"><a name="zh-cn_topic_0000001117163542_p1258410462501"></a><a name="zh-cn_topic_0000001117163542_p1258410462501"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p12584946115012"><a name="zh-cn_topic_0000001117163542_p12584946115012"></a><a name="zh-cn_topic_0000001117163542_p12584946115012"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.get(key, 'test', function(err, data) {    
      console.info(data);
});
```

## get\(key: string, defValue: ValueType\)<a name="zh-cn_topic_0000001117163542_section20585144614501"></a>

获取键对应的值，如果值为null或者非默认值类型，返默认数据。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table65864463507"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row65862461509"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p95861446125014"><a name="zh-cn_topic_0000001117163542_p95861446125014"></a><a name="zh-cn_topic_0000001117163542_p95861446125014"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p17586154611509"><a name="zh-cn_topic_0000001117163542_p17586154611509"></a><a name="zh-cn_topic_0000001117163542_p17586154611509"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p10586184616503"><a name="zh-cn_topic_0000001117163542_p10586184616503"></a><a name="zh-cn_topic_0000001117163542_p10586184616503"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p16586184613509"><a name="zh-cn_topic_0000001117163542_p16586184613509"></a><a name="zh-cn_topic_0000001117163542_p16586184613509"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row125869461500"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1036113511718"><a name="zh-cn_topic_0000001117163542_p1036113511718"></a><a name="zh-cn_topic_0000001117163542_p1036113511718"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p5586164645012"><a name="zh-cn_topic_0000001117163542_p5586164645012"></a><a name="zh-cn_topic_0000001117163542_p5586164645012"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p8587134612503"><a name="zh-cn_topic_0000001117163542_p8587134612503"></a><a name="zh-cn_topic_0000001117163542_p8587134612503"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p144662048512"><a name="zh-cn_topic_0000001117163542_p144662048512"></a><a name="zh-cn_topic_0000001117163542_p144662048512"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row523692017711"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p923722011713"><a name="zh-cn_topic_0000001117163542_p923722011713"></a><a name="zh-cn_topic_0000001117163542_p923722011713"></a>defValue</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p623720207718"><a name="zh-cn_topic_0000001117163542_p623720207718"></a><a name="zh-cn_topic_0000001117163542_p623720207718"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p1423712012715"><a name="zh-cn_topic_0000001117163542_p1423712012715"></a><a name="zh-cn_topic_0000001117163542_p1423712012715"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p72371420979"><a name="zh-cn_topic_0000001117163542_p72371420979"></a><a name="zh-cn_topic_0000001117163542_p72371420979"></a>默认返回值。支持number 、 string 、boolean。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table155871846155019"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row658774619501"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p058744635010"><a name="zh-cn_topic_0000001117163542_p058744635010"></a><a name="zh-cn_topic_0000001117163542_p058744635010"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p55871846165014"><a name="zh-cn_topic_0000001117163542_p55871846165014"></a><a name="zh-cn_topic_0000001117163542_p55871846165014"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row125871346115018"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p1161215410715"><a name="zh-cn_topic_0000001117163542_p1161215410715"></a><a name="zh-cn_topic_0000001117163542_p1161215410715"></a>Promise&lt;ValueType&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p156121754178"><a name="zh-cn_topic_0000001117163542_p156121754178"></a><a name="zh-cn_topic_0000001117163542_p156121754178"></a>Promise实例，用于异步获取结果。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = store.get(key, 'test');
promise.then((data) => {   
    console.info(data);
    }).catch((err) => {
});
```

## putSync\(key: string, value: ValueType\)<a name="zh-cn_topic_0000001117163542_section428912524119"></a>

首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table229055221119"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row329017524114"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p629055213110"><a name="zh-cn_topic_0000001117163542_p629055213110"></a><a name="zh-cn_topic_0000001117163542_p629055213110"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p18290145251111"><a name="zh-cn_topic_0000001117163542_p18290145251111"></a><a name="zh-cn_topic_0000001117163542_p18290145251111"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p1429114526111"><a name="zh-cn_topic_0000001117163542_p1429114526111"></a><a name="zh-cn_topic_0000001117163542_p1429114526111"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p929125218119"><a name="zh-cn_topic_0000001117163542_p929125218119"></a><a name="zh-cn_topic_0000001117163542_p929125218119"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row829195216111"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p629135261117"><a name="zh-cn_topic_0000001117163542_p629135261117"></a><a name="zh-cn_topic_0000001117163542_p629135261117"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p52911852101111"><a name="zh-cn_topic_0000001117163542_p52911852101111"></a><a name="zh-cn_topic_0000001117163542_p52911852101111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p829117529115"><a name="zh-cn_topic_0000001117163542_p829117529115"></a><a name="zh-cn_topic_0000001117163542_p829117529115"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1292752131120"><a name="zh-cn_topic_0000001117163542_p1292752131120"></a><a name="zh-cn_topic_0000001117163542_p1292752131120"></a>要修改的存储的key。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row192924526111"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p6292165215113"><a name="zh-cn_topic_0000001117163542_p6292165215113"></a><a name="zh-cn_topic_0000001117163542_p6292165215113"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p12292155201112"><a name="zh-cn_topic_0000001117163542_p12292155201112"></a><a name="zh-cn_topic_0000001117163542_p12292155201112"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p1629255217118"><a name="zh-cn_topic_0000001117163542_p1629255217118"></a><a name="zh-cn_topic_0000001117163542_p1629255217118"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p16293145217114"><a name="zh-cn_topic_0000001117163542_p16293145217114"></a><a name="zh-cn_topic_0000001117163542_p16293145217114"></a>存储的新值。支持number 、 string 、boolean。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table82931952151110"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row729314527114"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p1229355220111"><a name="zh-cn_topic_0000001117163542_p1229355220111"></a><a name="zh-cn_topic_0000001117163542_p1229355220111"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p7294105261117"><a name="zh-cn_topic_0000001117163542_p7294105261117"></a><a name="zh-cn_topic_0000001117163542_p7294105261117"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row5294252171116"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p15294155220112"><a name="zh-cn_topic_0000001117163542_p15294155220112"></a><a name="zh-cn_topic_0000001117163542_p15294155220112"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p1294145271120"><a name="zh-cn_topic_0000001117163542_p1294145271120"></a><a name="zh-cn_topic_0000001117163542_p1294145271120"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
let data = store.putSync(key, ‘defValue’);
```

## put\(key: string, value: ValueType, callback: AsyncCallback<void\>\)<a name="zh-cn_topic_0000001117163542_section92951552111117"></a>

首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table1329585231117"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row122969526117"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p029695210117"><a name="zh-cn_topic_0000001117163542_p029695210117"></a><a name="zh-cn_topic_0000001117163542_p029695210117"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p102961152141113"><a name="zh-cn_topic_0000001117163542_p102961152141113"></a><a name="zh-cn_topic_0000001117163542_p102961152141113"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p2296195251119"><a name="zh-cn_topic_0000001117163542_p2296195251119"></a><a name="zh-cn_topic_0000001117163542_p2296195251119"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1829695214114"><a name="zh-cn_topic_0000001117163542_p1829695214114"></a><a name="zh-cn_topic_0000001117163542_p1829695214114"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1029717529113"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p629715219113"><a name="zh-cn_topic_0000001117163542_p629715219113"></a><a name="zh-cn_topic_0000001117163542_p629715219113"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p10297952101120"><a name="zh-cn_topic_0000001117163542_p10297952101120"></a><a name="zh-cn_topic_0000001117163542_p10297952101120"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p329785218115"><a name="zh-cn_topic_0000001117163542_p329785218115"></a><a name="zh-cn_topic_0000001117163542_p329785218115"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p15240135384910"><a name="zh-cn_topic_0000001117163542_p15240135384910"></a><a name="zh-cn_topic_0000001117163542_p15240135384910"></a>要修改的存储的key。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row16297052141116"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p14297185211116"><a name="zh-cn_topic_0000001117163542_p14297185211116"></a><a name="zh-cn_topic_0000001117163542_p14297185211116"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p6297852181115"><a name="zh-cn_topic_0000001117163542_p6297852181115"></a><a name="zh-cn_topic_0000001117163542_p6297852181115"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p0298752101117"><a name="zh-cn_topic_0000001117163542_p0298752101117"></a><a name="zh-cn_topic_0000001117163542_p0298752101117"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p12298165211113"><a name="zh-cn_topic_0000001117163542_p12298165211113"></a><a name="zh-cn_topic_0000001117163542_p12298165211113"></a>存储的新值。支持number 、 string 、boolean。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row029835211117"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p15298115216111"><a name="zh-cn_topic_0000001117163542_p15298115216111"></a><a name="zh-cn_topic_0000001117163542_p15298115216111"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p1729815220113"><a name="zh-cn_topic_0000001117163542_p1729815220113"></a><a name="zh-cn_topic_0000001117163542_p1729815220113"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p22981152141120"><a name="zh-cn_topic_0000001117163542_p22981152141120"></a><a name="zh-cn_topic_0000001117163542_p22981152141120"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p529865281113"><a name="zh-cn_topic_0000001117163542_p529865281113"></a><a name="zh-cn_topic_0000001117163542_p529865281113"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table1329935291111"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row129915281114"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p1129918526117"><a name="zh-cn_topic_0000001117163542_p1129918526117"></a><a name="zh-cn_topic_0000001117163542_p1129918526117"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p1429985291110"><a name="zh-cn_topic_0000001117163542_p1429985291110"></a><a name="zh-cn_topic_0000001117163542_p1429985291110"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row4299205231112"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p1129905201116"><a name="zh-cn_topic_0000001117163542_p1129905201116"></a><a name="zh-cn_topic_0000001117163542_p1129905201116"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p1629935211116"><a name="zh-cn_topic_0000001117163542_p1629935211116"></a><a name="zh-cn_topic_0000001117163542_p1629935211116"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.put(key, 'test', function(err, data) {    
});
```

## put\(key: string, value: ValueType\)<a name="zh-cn_topic_0000001117163542_section230117522119"></a>

首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table12302052171118"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row83028525117"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p1302105251110"><a name="zh-cn_topic_0000001117163542_p1302105251110"></a><a name="zh-cn_topic_0000001117163542_p1302105251110"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p030255215112"><a name="zh-cn_topic_0000001117163542_p030255215112"></a><a name="zh-cn_topic_0000001117163542_p030255215112"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p2303125281116"><a name="zh-cn_topic_0000001117163542_p2303125281116"></a><a name="zh-cn_topic_0000001117163542_p2303125281116"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p33030523118"><a name="zh-cn_topic_0000001117163542_p33030523118"></a><a name="zh-cn_topic_0000001117163542_p33030523118"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row11303135212119"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p3303115281110"><a name="zh-cn_topic_0000001117163542_p3303115281110"></a><a name="zh-cn_topic_0000001117163542_p3303115281110"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p16303195221112"><a name="zh-cn_topic_0000001117163542_p16303195221112"></a><a name="zh-cn_topic_0000001117163542_p16303195221112"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p230435211116"><a name="zh-cn_topic_0000001117163542_p230435211116"></a><a name="zh-cn_topic_0000001117163542_p230435211116"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p258165814496"><a name="zh-cn_topic_0000001117163542_p258165814496"></a><a name="zh-cn_topic_0000001117163542_p258165814496"></a>要修改的存储的key。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row7304205213110"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p230412521118"><a name="zh-cn_topic_0000001117163542_p230412521118"></a><a name="zh-cn_topic_0000001117163542_p230412521118"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p930485251119"><a name="zh-cn_topic_0000001117163542_p930485251119"></a><a name="zh-cn_topic_0000001117163542_p930485251119"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p830445201113"><a name="zh-cn_topic_0000001117163542_p830445201113"></a><a name="zh-cn_topic_0000001117163542_p830445201113"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p20305105261112"><a name="zh-cn_topic_0000001117163542_p20305105261112"></a><a name="zh-cn_topic_0000001117163542_p20305105261112"></a>存储的新值。支持number 、 string 、boolean。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table23054526111"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row113051252131111"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p3305552171115"><a name="zh-cn_topic_0000001117163542_p3305552171115"></a><a name="zh-cn_topic_0000001117163542_p3305552171115"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p13061052181112"><a name="zh-cn_topic_0000001117163542_p13061052181112"></a><a name="zh-cn_topic_0000001117163542_p13061052181112"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1630610528116"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p066915611810"><a name="zh-cn_topic_0000001117163542_p066915611810"></a><a name="zh-cn_topic_0000001117163542_p066915611810"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p176691961886"><a name="zh-cn_topic_0000001117163542_p176691961886"></a><a name="zh-cn_topic_0000001117163542_p176691961886"></a>Promise实例，用于异步处理。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = store.put(key, 'test');
promise.then((data) => {   
     }).catch((err) => {
});
```

## hasSync\(key: string\)<a name="zh-cn_topic_0000001117163542_section0884174321910"></a>

检查存储对象是否包含名为给定key的存储。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table6884134310199"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1888514331911"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p1188534311198"><a name="zh-cn_topic_0000001117163542_p1188534311198"></a><a name="zh-cn_topic_0000001117163542_p1188534311198"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p788534310194"><a name="zh-cn_topic_0000001117163542_p788534310194"></a><a name="zh-cn_topic_0000001117163542_p788534310194"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p98857435197"><a name="zh-cn_topic_0000001117163542_p98857435197"></a><a name="zh-cn_topic_0000001117163542_p98857435197"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p28851643161916"><a name="zh-cn_topic_0000001117163542_p28851643161916"></a><a name="zh-cn_topic_0000001117163542_p28851643161916"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row7885114301920"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1188574311190"><a name="zh-cn_topic_0000001117163542_p1188574311190"></a><a name="zh-cn_topic_0000001117163542_p1188574311190"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p2088664320193"><a name="zh-cn_topic_0000001117163542_p2088664320193"></a><a name="zh-cn_topic_0000001117163542_p2088664320193"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p18861943111912"><a name="zh-cn_topic_0000001117163542_p18861943111912"></a><a name="zh-cn_topic_0000001117163542_p18861943111912"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p103221766219"><a name="zh-cn_topic_0000001117163542_p103221766219"></a><a name="zh-cn_topic_0000001117163542_p103221766219"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table12887134318193"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row158872043101914"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p0887174314197"><a name="zh-cn_topic_0000001117163542_p0887174314197"></a><a name="zh-cn_topic_0000001117163542_p0887174314197"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p1988744314199"><a name="zh-cn_topic_0000001117163542_p1988744314199"></a><a name="zh-cn_topic_0000001117163542_p1988744314199"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row16887443131910"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p0888184310199"><a name="zh-cn_topic_0000001117163542_p0888184310199"></a><a name="zh-cn_topic_0000001117163542_p0888184310199"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p3888124331919"><a name="zh-cn_topic_0000001117163542_p3888124331919"></a><a name="zh-cn_topic_0000001117163542_p3888124331919"></a>true 表示存在，false表示不存在</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
let ret = store.hasSync(key);
```

## has\(key: string, callback: AsyncCallback<boolean\>\)<a name="zh-cn_topic_0000001117163542_section1889144312199"></a>

检查存储对象是否包含名为给定key的存储。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table12889114351915"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1289014316196"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p18890144381915"><a name="zh-cn_topic_0000001117163542_p18890144381915"></a><a name="zh-cn_topic_0000001117163542_p18890144381915"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p11890164341910"><a name="zh-cn_topic_0000001117163542_p11890164341910"></a><a name="zh-cn_topic_0000001117163542_p11890164341910"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p9890184312190"><a name="zh-cn_topic_0000001117163542_p9890184312190"></a><a name="zh-cn_topic_0000001117163542_p9890184312190"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p198907438198"><a name="zh-cn_topic_0000001117163542_p198907438198"></a><a name="zh-cn_topic_0000001117163542_p198907438198"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row18890104361917"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p7890184317194"><a name="zh-cn_topic_0000001117163542_p7890184317194"></a><a name="zh-cn_topic_0000001117163542_p7890184317194"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p14890114314192"><a name="zh-cn_topic_0000001117163542_p14890114314192"></a><a name="zh-cn_topic_0000001117163542_p14890114314192"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p98919431199"><a name="zh-cn_topic_0000001117163542_p98919431199"></a><a name="zh-cn_topic_0000001117163542_p98919431199"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p13891174310191"><a name="zh-cn_topic_0000001117163542_p13891174310191"></a><a name="zh-cn_topic_0000001117163542_p13891174310191"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row1989114312192"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p989104361918"><a name="zh-cn_topic_0000001117163542_p989104361918"></a><a name="zh-cn_topic_0000001117163542_p989104361918"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p789224351918"><a name="zh-cn_topic_0000001117163542_p789224351918"></a><a name="zh-cn_topic_0000001117163542_p789224351918"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p13892134315194"><a name="zh-cn_topic_0000001117163542_p13892134315194"></a><a name="zh-cn_topic_0000001117163542_p13892134315194"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1089284318198"><a name="zh-cn_topic_0000001117163542_p1089284318198"></a><a name="zh-cn_topic_0000001117163542_p1089284318198"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table178921243171920"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row48921643151917"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p188921843111911"><a name="zh-cn_topic_0000001117163542_p188921843111911"></a><a name="zh-cn_topic_0000001117163542_p188921843111911"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p1989304317191"><a name="zh-cn_topic_0000001117163542_p1989304317191"></a><a name="zh-cn_topic_0000001117163542_p1989304317191"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row489374371912"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p12893104331913"><a name="zh-cn_topic_0000001117163542_p12893104331913"></a><a name="zh-cn_topic_0000001117163542_p12893104331913"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p389312439198"><a name="zh-cn_topic_0000001117163542_p389312439198"></a><a name="zh-cn_topic_0000001117163542_p389312439198"></a>true 表示存在，false表示不存在。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.has(key, function(err, data) {   
       console.info(data);
});
```

## has\(key: string\)<a name="zh-cn_topic_0000001117163542_section19894343121917"></a>

检查存储对象是否包含名为给定key的存储。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table389515434199"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row489504371914"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p12895443151919"><a name="zh-cn_topic_0000001117163542_p12895443151919"></a><a name="zh-cn_topic_0000001117163542_p12895443151919"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p10895144316197"><a name="zh-cn_topic_0000001117163542_p10895144316197"></a><a name="zh-cn_topic_0000001117163542_p10895144316197"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p1789584317196"><a name="zh-cn_topic_0000001117163542_p1789584317196"></a><a name="zh-cn_topic_0000001117163542_p1789584317196"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p8896144391910"><a name="zh-cn_topic_0000001117163542_p8896144391910"></a><a name="zh-cn_topic_0000001117163542_p8896144391910"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row189684331913"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p4896154311919"><a name="zh-cn_topic_0000001117163542_p4896154311919"></a><a name="zh-cn_topic_0000001117163542_p4896154311919"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p08962043161920"><a name="zh-cn_topic_0000001117163542_p08962043161920"></a><a name="zh-cn_topic_0000001117163542_p08962043161920"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p089634311911"><a name="zh-cn_topic_0000001117163542_p089634311911"></a><a name="zh-cn_topic_0000001117163542_p089634311911"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p7246147162517"><a name="zh-cn_topic_0000001117163542_p7246147162517"></a><a name="zh-cn_topic_0000001117163542_p7246147162517"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table489720437190"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row48978431190"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p189754341915"><a name="zh-cn_topic_0000001117163542_p189754341915"></a><a name="zh-cn_topic_0000001117163542_p189754341915"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p2898443141917"><a name="zh-cn_topic_0000001117163542_p2898443141917"></a><a name="zh-cn_topic_0000001117163542_p2898443141917"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row1389884318191"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p118141810812"><a name="zh-cn_topic_0000001117163542_p118141810812"></a><a name="zh-cn_topic_0000001117163542_p118141810812"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p418114181385"><a name="zh-cn_topic_0000001117163542_p418114181385"></a><a name="zh-cn_topic_0000001117163542_p418114181385"></a>Promise实例，用于异步处理。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = store.has(key);
promise.then((data) => {   
    console.info(data);
    }).catch((err) => {
});
```

## deleteSync\(key: string\)<a name="zh-cn_topic_0000001117163542_section1360034110271"></a>

从此对象中删除名为给定key的存储。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table0601144116279"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1760118411270"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p560110414271"><a name="zh-cn_topic_0000001117163542_p560110414271"></a><a name="zh-cn_topic_0000001117163542_p560110414271"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p12602174114274"><a name="zh-cn_topic_0000001117163542_p12602174114274"></a><a name="zh-cn_topic_0000001117163542_p12602174114274"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p160224117275"><a name="zh-cn_topic_0000001117163542_p160224117275"></a><a name="zh-cn_topic_0000001117163542_p160224117275"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p060234114274"><a name="zh-cn_topic_0000001117163542_p060234114274"></a><a name="zh-cn_topic_0000001117163542_p060234114274"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row560218415279"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1660204119276"><a name="zh-cn_topic_0000001117163542_p1660204119276"></a><a name="zh-cn_topic_0000001117163542_p1660204119276"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p56021341112718"><a name="zh-cn_topic_0000001117163542_p56021341112718"></a><a name="zh-cn_topic_0000001117163542_p56021341112718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p9602104182714"><a name="zh-cn_topic_0000001117163542_p9602104182714"></a><a name="zh-cn_topic_0000001117163542_p9602104182714"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1260394118270"><a name="zh-cn_topic_0000001117163542_p1260394118270"></a><a name="zh-cn_topic_0000001117163542_p1260394118270"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table156033413277"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row96033415277"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p660317411279"><a name="zh-cn_topic_0000001117163542_p660317411279"></a><a name="zh-cn_topic_0000001117163542_p660317411279"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p14603194118271"><a name="zh-cn_topic_0000001117163542_p14603194118271"></a><a name="zh-cn_topic_0000001117163542_p14603194118271"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row176041541202715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p4604154114274"><a name="zh-cn_topic_0000001117163542_p4604154114274"></a><a name="zh-cn_topic_0000001117163542_p4604154114274"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p7604941142719"><a name="zh-cn_topic_0000001117163542_p7604941142719"></a><a name="zh-cn_topic_0000001117163542_p7604941142719"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.deleteSync(key);
```

## delete\(key: string, callback: AsyncCallback<void\>\)<a name="zh-cn_topic_0000001117163542_section1960515413272"></a>

从此对象中删除名为给定key的存储。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table16065416278"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row86062416270"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p260704122716"><a name="zh-cn_topic_0000001117163542_p260704122716"></a><a name="zh-cn_topic_0000001117163542_p260704122716"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p17607241192711"><a name="zh-cn_topic_0000001117163542_p17607241192711"></a><a name="zh-cn_topic_0000001117163542_p17607241192711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p11607194162719"><a name="zh-cn_topic_0000001117163542_p11607194162719"></a><a name="zh-cn_topic_0000001117163542_p11607194162719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1607441172716"><a name="zh-cn_topic_0000001117163542_p1607441172716"></a><a name="zh-cn_topic_0000001117163542_p1607441172716"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row760774112719"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p14607541182716"><a name="zh-cn_topic_0000001117163542_p14607541182716"></a><a name="zh-cn_topic_0000001117163542_p14607541182716"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p1560864112717"><a name="zh-cn_topic_0000001117163542_p1560864112717"></a><a name="zh-cn_topic_0000001117163542_p1560864112717"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p13608134192710"><a name="zh-cn_topic_0000001117163542_p13608134192710"></a><a name="zh-cn_topic_0000001117163542_p13608134192710"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p156083412274"><a name="zh-cn_topic_0000001117163542_p156083412274"></a><a name="zh-cn_topic_0000001117163542_p156083412274"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row1160874110276"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p19608164120277"><a name="zh-cn_topic_0000001117163542_p19608164120277"></a><a name="zh-cn_topic_0000001117163542_p19608164120277"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p20608114162717"><a name="zh-cn_topic_0000001117163542_p20608114162717"></a><a name="zh-cn_topic_0000001117163542_p20608114162717"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p1660884118272"><a name="zh-cn_topic_0000001117163542_p1660884118272"></a><a name="zh-cn_topic_0000001117163542_p1660884118272"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p060804115270"><a name="zh-cn_topic_0000001117163542_p060804115270"></a><a name="zh-cn_topic_0000001117163542_p060804115270"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table8609104192715"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row106094412279"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p260917416271"><a name="zh-cn_topic_0000001117163542_p260917416271"></a><a name="zh-cn_topic_0000001117163542_p260917416271"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p660912415279"><a name="zh-cn_topic_0000001117163542_p660912415279"></a><a name="zh-cn_topic_0000001117163542_p660912415279"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row061044192715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p11610241122714"><a name="zh-cn_topic_0000001117163542_p11610241122714"></a><a name="zh-cn_topic_0000001117163542_p11610241122714"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p1610124110277"><a name="zh-cn_topic_0000001117163542_p1610124110277"></a><a name="zh-cn_topic_0000001117163542_p1610124110277"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.delete(key, function(err, data) {   
});
```

## delete\(key: string\)<a name="zh-cn_topic_0000001117163542_section36125414279"></a>

从此对象中删除名为给定key的存储。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table1761224113272"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row3613341182713"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p16131241182716"><a name="zh-cn_topic_0000001117163542_p16131241182716"></a><a name="zh-cn_topic_0000001117163542_p16131241182716"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p10613241192711"><a name="zh-cn_topic_0000001117163542_p10613241192711"></a><a name="zh-cn_topic_0000001117163542_p10613241192711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p7614541142718"><a name="zh-cn_topic_0000001117163542_p7614541142718"></a><a name="zh-cn_topic_0000001117163542_p7614541142718"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1961416411279"><a name="zh-cn_topic_0000001117163542_p1961416411279"></a><a name="zh-cn_topic_0000001117163542_p1961416411279"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row161424110272"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p10614144152720"><a name="zh-cn_topic_0000001117163542_p10614144152720"></a><a name="zh-cn_topic_0000001117163542_p10614144152720"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p76141341182712"><a name="zh-cn_topic_0000001117163542_p76141341182712"></a><a name="zh-cn_topic_0000001117163542_p76141341182712"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p16145416275"><a name="zh-cn_topic_0000001117163542_p16145416275"></a><a name="zh-cn_topic_0000001117163542_p16145416275"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1961464114278"><a name="zh-cn_topic_0000001117163542_p1961464114278"></a><a name="zh-cn_topic_0000001117163542_p1961464114278"></a>要获取的存储key名称。它不能为空。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table196151841182710"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row7615124182719"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p1561534182710"><a name="zh-cn_topic_0000001117163542_p1561534182710"></a><a name="zh-cn_topic_0000001117163542_p1561534182710"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p16615154111277"><a name="zh-cn_topic_0000001117163542_p16615154111277"></a><a name="zh-cn_topic_0000001117163542_p16615154111277"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row461674113277"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p8999525989"><a name="zh-cn_topic_0000001117163542_p8999525989"></a><a name="zh-cn_topic_0000001117163542_p8999525989"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p09991256820"><a name="zh-cn_topic_0000001117163542_p09991256820"></a><a name="zh-cn_topic_0000001117163542_p09991256820"></a>Promise实例，用于异步处理。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = store.delete(key);
promise.then((data) => {   
    }).catch((err) => {
});
```

## flushSync\(\)<a name="zh-cn_topic_0000001117163542_section1593555103112"></a>

将当前storage对象中的修改保存到当前的storage，并同步存储到文件中。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table1493675113313"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row4936451113115"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p2936205143120"><a name="zh-cn_topic_0000001117163542_p2936205143120"></a><a name="zh-cn_topic_0000001117163542_p2936205143120"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p29372514313"><a name="zh-cn_topic_0000001117163542_p29372514313"></a><a name="zh-cn_topic_0000001117163542_p29372514313"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p19937135118318"><a name="zh-cn_topic_0000001117163542_p19937135118318"></a><a name="zh-cn_topic_0000001117163542_p19937135118318"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p179371451193118"><a name="zh-cn_topic_0000001117163542_p179371451193118"></a><a name="zh-cn_topic_0000001117163542_p179371451193118"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row209371951163114"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p561845563915"><a name="zh-cn_topic_0000001117163542_p561845563915"></a><a name="zh-cn_topic_0000001117163542_p561845563915"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p1859616074011"><a name="zh-cn_topic_0000001117163542_p1859616074011"></a><a name="zh-cn_topic_0000001117163542_p1859616074011"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p129383519316"><a name="zh-cn_topic_0000001117163542_p129383519316"></a><a name="zh-cn_topic_0000001117163542_p129383519316"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p13938125118319"><a name="zh-cn_topic_0000001117163542_p13938125118319"></a><a name="zh-cn_topic_0000001117163542_p13938125118319"></a>无</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table20938175115319"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row493918511318"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p12939145114318"><a name="zh-cn_topic_0000001117163542_p12939145114318"></a><a name="zh-cn_topic_0000001117163542_p12939145114318"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p193975173112"><a name="zh-cn_topic_0000001117163542_p193975173112"></a><a name="zh-cn_topic_0000001117163542_p193975173112"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row10939135116313"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p1394095153116"><a name="zh-cn_topic_0000001117163542_p1394095153116"></a><a name="zh-cn_topic_0000001117163542_p1394095153116"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p99401451123115"><a name="zh-cn_topic_0000001117163542_p99401451123115"></a><a name="zh-cn_topic_0000001117163542_p99401451123115"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.flushSync();
```

## flush\(callback: AsyncCallback<void\>\)<a name="zh-cn_topic_0000001117163542_section1994165173117"></a>

将当前storage对象中的修改保存到当前的storage，并异步存储到文件中。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table15942115183115"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row109421151173115"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p13942251143112"><a name="zh-cn_topic_0000001117163542_p13942251143112"></a><a name="zh-cn_topic_0000001117163542_p13942251143112"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p9943351133114"><a name="zh-cn_topic_0000001117163542_p9943351133114"></a><a name="zh-cn_topic_0000001117163542_p9943351133114"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p1694355143116"><a name="zh-cn_topic_0000001117163542_p1694355143116"></a><a name="zh-cn_topic_0000001117163542_p1694355143116"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p149431451133110"><a name="zh-cn_topic_0000001117163542_p149431451133110"></a><a name="zh-cn_topic_0000001117163542_p149431451133110"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row59444519317"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p7944195119316"><a name="zh-cn_topic_0000001117163542_p7944195119316"></a><a name="zh-cn_topic_0000001117163542_p7944195119316"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p494435110315"><a name="zh-cn_topic_0000001117163542_p494435110315"></a><a name="zh-cn_topic_0000001117163542_p494435110315"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p15945651123113"><a name="zh-cn_topic_0000001117163542_p15945651123113"></a><a name="zh-cn_topic_0000001117163542_p15945651123113"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p394505193117"><a name="zh-cn_topic_0000001117163542_p394505193117"></a><a name="zh-cn_topic_0000001117163542_p394505193117"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table109451651113119"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row14946451103117"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p12946551123115"><a name="zh-cn_topic_0000001117163542_p12946551123115"></a><a name="zh-cn_topic_0000001117163542_p12946551123115"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p2094685116313"><a name="zh-cn_topic_0000001117163542_p2094685116313"></a><a name="zh-cn_topic_0000001117163542_p2094685116313"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row59461151163116"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p394695110317"><a name="zh-cn_topic_0000001117163542_p394695110317"></a><a name="zh-cn_topic_0000001117163542_p394695110317"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p09478516313"><a name="zh-cn_topic_0000001117163542_p09478516313"></a><a name="zh-cn_topic_0000001117163542_p09478516313"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.flush(function(err, data) {   
});
```

## flush\(\)<a name="zh-cn_topic_0000001117163542_section169491651163113"></a>

将当前storage对象中的修改保存到当前的storage，并异步存储到文件中。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table1394975113117"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row159501951183113"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p595075113112"><a name="zh-cn_topic_0000001117163542_p595075113112"></a><a name="zh-cn_topic_0000001117163542_p595075113112"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p695085111316"><a name="zh-cn_topic_0000001117163542_p695085111316"></a><a name="zh-cn_topic_0000001117163542_p695085111316"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p4950165153113"><a name="zh-cn_topic_0000001117163542_p4950165153113"></a><a name="zh-cn_topic_0000001117163542_p4950165153113"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p195075112313"><a name="zh-cn_topic_0000001117163542_p195075112313"></a><a name="zh-cn_topic_0000001117163542_p195075112313"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row17951195163119"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p179511251193116"><a name="zh-cn_topic_0000001117163542_p179511251193116"></a><a name="zh-cn_topic_0000001117163542_p179511251193116"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p17951551183118"><a name="zh-cn_topic_0000001117163542_p17951551183118"></a><a name="zh-cn_topic_0000001117163542_p17951551183118"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p129526519318"><a name="zh-cn_topic_0000001117163542_p129526519318"></a><a name="zh-cn_topic_0000001117163542_p129526519318"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p595245120316"><a name="zh-cn_topic_0000001117163542_p595245120316"></a><a name="zh-cn_topic_0000001117163542_p595245120316"></a>无</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table1795245183114"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1595215113117"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p14952151103113"><a name="zh-cn_topic_0000001117163542_p14952151103113"></a><a name="zh-cn_topic_0000001117163542_p14952151103113"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p79531051103116"><a name="zh-cn_topic_0000001117163542_p79531051103116"></a><a name="zh-cn_topic_0000001117163542_p79531051103116"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row495395113110"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p15337433587"><a name="zh-cn_topic_0000001117163542_p15337433587"></a><a name="zh-cn_topic_0000001117163542_p15337433587"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p2337193319813"><a name="zh-cn_topic_0000001117163542_p2337193319813"></a><a name="zh-cn_topic_0000001117163542_p2337193319813"></a>Promise实例，用于异步处理。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = store.flush();
promise.then((data) => {   
    }).catch((err) => {
});
```

## clearSync\(\)<a name="zh-cn_topic_0000001117163542_section890817195434"></a>

清除此存储对象中的所有存储。

此方法为同步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table8908131915433"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row290915193434"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p79091619124316"><a name="zh-cn_topic_0000001117163542_p79091619124316"></a><a name="zh-cn_topic_0000001117163542_p79091619124316"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p19092019184313"><a name="zh-cn_topic_0000001117163542_p19092019184313"></a><a name="zh-cn_topic_0000001117163542_p19092019184313"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p19909101964314"><a name="zh-cn_topic_0000001117163542_p19909101964314"></a><a name="zh-cn_topic_0000001117163542_p19909101964314"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1991041954313"><a name="zh-cn_topic_0000001117163542_p1991041954313"></a><a name="zh-cn_topic_0000001117163542_p1991041954313"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row10910171910431"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p169101019114312"><a name="zh-cn_topic_0000001117163542_p169101019114312"></a><a name="zh-cn_topic_0000001117163542_p169101019114312"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p9910319194315"><a name="zh-cn_topic_0000001117163542_p9910319194315"></a><a name="zh-cn_topic_0000001117163542_p9910319194315"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p7910419174310"><a name="zh-cn_topic_0000001117163542_p7910419174310"></a><a name="zh-cn_topic_0000001117163542_p7910419174310"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p1910141994316"><a name="zh-cn_topic_0000001117163542_p1910141994316"></a><a name="zh-cn_topic_0000001117163542_p1910141994316"></a>无</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table17911131904316"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row189110197437"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p7911819184312"><a name="zh-cn_topic_0000001117163542_p7911819184312"></a><a name="zh-cn_topic_0000001117163542_p7911819184312"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p59111419144310"><a name="zh-cn_topic_0000001117163542_p59111419144310"></a><a name="zh-cn_topic_0000001117163542_p59111419144310"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row18912171954318"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p491213191431"><a name="zh-cn_topic_0000001117163542_p491213191431"></a><a name="zh-cn_topic_0000001117163542_p491213191431"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p59124198434"><a name="zh-cn_topic_0000001117163542_p59124198434"></a><a name="zh-cn_topic_0000001117163542_p59124198434"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.clearSync();
```

## clear\(callback: AsyncCallback<void\>\)<a name="zh-cn_topic_0000001117163542_section291391994316"></a>

清除此存储对象中的所有存储。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table139131919154315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row12914171916439"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p209141519204311"><a name="zh-cn_topic_0000001117163542_p209141519204311"></a><a name="zh-cn_topic_0000001117163542_p209141519204311"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p991418192433"><a name="zh-cn_topic_0000001117163542_p991418192433"></a><a name="zh-cn_topic_0000001117163542_p991418192433"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p11914101918437"><a name="zh-cn_topic_0000001117163542_p11914101918437"></a><a name="zh-cn_topic_0000001117163542_p11914101918437"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p1491512198430"><a name="zh-cn_topic_0000001117163542_p1491512198430"></a><a name="zh-cn_topic_0000001117163542_p1491512198430"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row491551911431"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p16915171914436"><a name="zh-cn_topic_0000001117163542_p16915171914436"></a><a name="zh-cn_topic_0000001117163542_p16915171914436"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p169157196434"><a name="zh-cn_topic_0000001117163542_p169157196434"></a><a name="zh-cn_topic_0000001117163542_p169157196434"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p16915319174318"><a name="zh-cn_topic_0000001117163542_p16915319174318"></a><a name="zh-cn_topic_0000001117163542_p16915319174318"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p491613199436"><a name="zh-cn_topic_0000001117163542_p491613199436"></a><a name="zh-cn_topic_0000001117163542_p491613199436"></a>回调函数。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table79165196436"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row79171119194314"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p6917119144317"><a name="zh-cn_topic_0000001117163542_p6917119144317"></a><a name="zh-cn_topic_0000001117163542_p6917119144317"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p189171919184312"><a name="zh-cn_topic_0000001117163542_p189171919184312"></a><a name="zh-cn_topic_0000001117163542_p189171919184312"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row29174199437"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p8917171954317"><a name="zh-cn_topic_0000001117163542_p8917171954317"></a><a name="zh-cn_topic_0000001117163542_p8917171954317"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p2917191910431"><a name="zh-cn_topic_0000001117163542_p2917191910431"></a><a name="zh-cn_topic_0000001117163542_p2917191910431"></a>无</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
store.clear(function(err, data) {   
});
```

## clear\(\)<a name="zh-cn_topic_0000001117163542_section19192196432"></a>

清除此存储对象中的所有存储。

此方法为异步方法。

**参数：**

<a name="zh-cn_topic_0000001117163542_table13920619114319"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1092011934310"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p79201719104316"><a name="zh-cn_topic_0000001117163542_p79201719104316"></a><a name="zh-cn_topic_0000001117163542_p79201719104316"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p14921191954318"><a name="zh-cn_topic_0000001117163542_p14921191954318"></a><a name="zh-cn_topic_0000001117163542_p14921191954318"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p69211199438"><a name="zh-cn_topic_0000001117163542_p69211199438"></a><a name="zh-cn_topic_0000001117163542_p69211199438"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p15921181910436"><a name="zh-cn_topic_0000001117163542_p15921181910436"></a><a name="zh-cn_topic_0000001117163542_p15921181910436"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row15921151913439"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p1592191914432"><a name="zh-cn_topic_0000001117163542_p1592191914432"></a><a name="zh-cn_topic_0000001117163542_p1592191914432"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p149211193439"><a name="zh-cn_topic_0000001117163542_p149211193439"></a><a name="zh-cn_topic_0000001117163542_p149211193439"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p192111934310"><a name="zh-cn_topic_0000001117163542_p192111934310"></a><a name="zh-cn_topic_0000001117163542_p192111934310"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p792261974313"><a name="zh-cn_topic_0000001117163542_p792261974313"></a><a name="zh-cn_topic_0000001117163542_p792261974313"></a>无</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="zh-cn_topic_0000001117163542_table2092201916435"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row1992221919433"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001117163542_p1192311197439"><a name="zh-cn_topic_0000001117163542_p1192311197439"></a><a name="zh-cn_topic_0000001117163542_p1192311197439"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001117163542_p109231196438"><a name="zh-cn_topic_0000001117163542_p109231196438"></a><a name="zh-cn_topic_0000001117163542_p109231196438"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row129231619134314"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001117163542_p6721740583"><a name="zh-cn_topic_0000001117163542_p6721740583"></a><a name="zh-cn_topic_0000001117163542_p6721740583"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001117163542_p1972740688"><a name="zh-cn_topic_0000001117163542_p1972740688"></a><a name="zh-cn_topic_0000001117163542_p1972740688"></a>Promise实例，用于异步处理。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
const promise = store.clear();
promise.then((data) => {   
    }).catch((err) => {
});
```

## on\(type: 'change', callback: Callback<StorageObserver\>\)<a name="zh-cn_topic_0000001117163542_section19353521332"></a>

监听者类需要实现StorageObserver接口，当数据发生改变时,监听者的 StorageObserver\#onChange会被回调。

<a name="zh-cn_topic_0000001117163542_table1993675218315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row129362521838"><th class="cellrowborder" valign="top" width="24.060000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001117163542_p1193711521037"><a name="zh-cn_topic_0000001117163542_p1193711521037"></a><a name="zh-cn_topic_0000001117163542_p1193711521037"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25.25%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001117163542_p79372521430"><a name="zh-cn_topic_0000001117163542_p79372521430"></a><a name="zh-cn_topic_0000001117163542_p79372521430"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001117163542_p09376524315"><a name="zh-cn_topic_0000001117163542_p09376524315"></a><a name="zh-cn_topic_0000001117163542_p09376524315"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row652511191284"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001117163542_p115269191082"><a name="zh-cn_topic_0000001117163542_p115269191082"></a><a name="zh-cn_topic_0000001117163542_p115269191082"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001117163542_p105268194810"><a name="zh-cn_topic_0000001117163542_p105268194810"></a><a name="zh-cn_topic_0000001117163542_p105268194810"></a>'change'</p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001117163542_p1852671914819"><a name="zh-cn_topic_0000001117163542_p1852671914819"></a><a name="zh-cn_topic_0000001117163542_p1852671914819"></a>事件类型，表示数据变更。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row893735215313"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001117163542_p199389521136"><a name="zh-cn_topic_0000001117163542_p199389521136"></a><a name="zh-cn_topic_0000001117163542_p199389521136"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001117163542_p89388521431"><a name="zh-cn_topic_0000001117163542_p89388521431"></a><a name="zh-cn_topic_0000001117163542_p89388521431"></a>Callback&lt;StorageObserver&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001117163542_p1938135211315"><a name="zh-cn_topic_0000001117163542_p1938135211315"></a><a name="zh-cn_topic_0000001117163542_p1938135211315"></a>当数据发生改变时,监听者的onChange会被回调。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
var observer = function (data) {  
  console.info(data);  
  };
store.on('change', observer);
```

## off\(type: 'change', callback: Callback<StorageObserver\>\)<a name="zh-cn_topic_0000001117163542_section1194235213313"></a>

监听者类需要实现StorageObserver接口，当不再进行数据监听时，使用此接口取消监听。

<a name="zh-cn_topic_0000001117163542_table1094217520311"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row89431552536"><th class="cellrowborder" valign="top" width="24.060000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001117163542_p1994325218317"><a name="zh-cn_topic_0000001117163542_p1994325218317"></a><a name="zh-cn_topic_0000001117163542_p1994325218317"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25.25%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001117163542_p194315521133"><a name="zh-cn_topic_0000001117163542_p194315521133"></a><a name="zh-cn_topic_0000001117163542_p194315521133"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001117163542_p3943185217317"><a name="zh-cn_topic_0000001117163542_p3943185217317"></a><a name="zh-cn_topic_0000001117163542_p3943185217317"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row143551524181011"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001117163542_p6686113141017"><a name="zh-cn_topic_0000001117163542_p6686113141017"></a><a name="zh-cn_topic_0000001117163542_p6686113141017"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001117163542_p1468618310103"><a name="zh-cn_topic_0000001117163542_p1468618310103"></a><a name="zh-cn_topic_0000001117163542_p1468618310103"></a>'change'</p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001117163542_p2687193120109"><a name="zh-cn_topic_0000001117163542_p2687193120109"></a><a name="zh-cn_topic_0000001117163542_p2687193120109"></a>事件类型，表示数据变更。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001117163542_row594485217318"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001117163542_p1294410521536"><a name="zh-cn_topic_0000001117163542_p1294410521536"></a><a name="zh-cn_topic_0000001117163542_p1294410521536"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001117163542_p18944152831"><a name="zh-cn_topic_0000001117163542_p18944152831"></a><a name="zh-cn_topic_0000001117163542_p18944152831"></a>Callback&lt;StorageObserver&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001117163542_p29445522317"><a name="zh-cn_topic_0000001117163542_p29445522317"></a><a name="zh-cn_topic_0000001117163542_p29445522317"></a>需要取消的回调对象实例</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
var observer = function (data) {  
  console.info(data);  
  };
store.off('change', observer);
```

## 事件<a name="zh-cn_topic_0000001117163542_section335774517218"></a>

### change<a name="zh-cn_topic_0000001117163542_section1151314331741"></a>

**表 1**  回调函数的参数说明（可选，如不涉及可删除）

<a name="zh-cn_topic_0000001117163542_table851413312410"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row951483314412"><th class="cellrowborder" valign="top" width="24.060000000000002%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001117163542_p451416338418"><a name="zh-cn_topic_0000001117163542_p451416338418"></a><a name="zh-cn_topic_0000001117163542_p451416338418"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25.25%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001117163542_p1551416333415"><a name="zh-cn_topic_0000001117163542_p1551416333415"></a><a name="zh-cn_topic_0000001117163542_p1551416333415"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001117163542_p145142338415"><a name="zh-cn_topic_0000001117163542_p145142338415"></a><a name="zh-cn_topic_0000001117163542_p145142338415"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row18514113314414"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001117163542_p1651413331542"><a name="zh-cn_topic_0000001117163542_p1651413331542"></a><a name="zh-cn_topic_0000001117163542_p1651413331542"></a>observer</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001117163542_p195145331840"><a name="zh-cn_topic_0000001117163542_p195145331840"></a><a name="zh-cn_topic_0000001117163542_p195145331840"></a><a href="#zh-cn_topic_0000001117163542_section256244135613">StorageObserver</a></p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001117163542_p95141333546"><a name="zh-cn_topic_0000001117163542_p95141333546"></a><a name="zh-cn_topic_0000001117163542_p95141333546"></a>当有数据变化时会收到此回调</p>
</td>
</tr>
</tbody>
</table>

## StorageObserver<a name="zh-cn_topic_0000001117163542_section256244135613"></a>

<a name="zh-cn_topic_0000001117163542_table0103172561814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001117163542_row12103152513185"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001117163542_p1610322561817"><a name="zh-cn_topic_0000001117163542_p1610322561817"></a><a name="zh-cn_topic_0000001117163542_p1610322561817"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.271227122712272%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001117163542_p20103132551816"><a name="zh-cn_topic_0000001117163542_p20103132551816"></a><a name="zh-cn_topic_0000001117163542_p20103132551816"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.551055105510551%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001117163542_p1103172518188"><a name="zh-cn_topic_0000001117163542_p1103172518188"></a><a name="zh-cn_topic_0000001117163542_p1103172518188"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001117163542_p19103125141812"><a name="zh-cn_topic_0000001117163542_p19103125141812"></a><a name="zh-cn_topic_0000001117163542_p19103125141812"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001117163542_row201031125101812"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001117163542_p5549181319415"><a name="zh-cn_topic_0000001117163542_p5549181319415"></a><a name="zh-cn_topic_0000001117163542_p5549181319415"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001117163542_p39351925253"><a name="zh-cn_topic_0000001117163542_p39351925253"></a><a name="zh-cn_topic_0000001117163542_p39351925253"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001117163542_p8935162182512"><a name="zh-cn_topic_0000001117163542_p8935162182512"></a><a name="zh-cn_topic_0000001117163542_p8935162182512"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001117163542_p109351224253"><a name="zh-cn_topic_0000001117163542_p109351224253"></a><a name="zh-cn_topic_0000001117163542_p109351224253"></a>变更的数据内容</p>
</td>
</tr>
</tbody>
</table>

