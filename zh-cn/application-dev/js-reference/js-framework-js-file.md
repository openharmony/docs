# app.js<a name="ZH-CN_TOPIC_0000001209210691"></a>

-   [应用生命周期](#zh-cn_topic_0000001173164711_section597315421776)
-   [应用对象6+](#zh-cn_topic_0000001173164711_section61671730771)

## 应用生命周期<a name="zh-cn_topic_0000001173164711_section597315421776"></a>

每个应用可以在app.js自定义应用级[生命周期](js-framework-lifecycle.md#ZH-CN_TOPIC_0000001209252155)的实现逻辑，以下示例仅在生命周期函数中打印对应日志：

```
// app.js
export default {
    onCreate() {
        console.info('Application onCreate');
    },

    onDestroy() {
        console.info('Application onDestroy');
    },
}
```

## 应用对象<sup>6+</sup><a name="zh-cn_topic_0000001173164711_section61671730771"></a>

<a name="zh-cn_topic_0000001173164711_table2114112717810"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164711_r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164711_ae816119c3e0143c892512012c7927037"><a name="zh-cn_topic_0000001173164711_ae816119c3e0143c892512012c7927037"></a><a name="zh-cn_topic_0000001173164711_ae816119c3e0143c892512012c7927037"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="16.12%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164711_ab72e901bb3ef4657b303513b8fa5ec1f"><a name="zh-cn_topic_0000001173164711_ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="zh-cn_topic_0000001173164711_ab72e901bb3ef4657b303513b8fa5ec1f"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70.26%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164711_ae95f3df496fc41939ac6c1cf74aef9d8"><a name="zh-cn_topic_0000001173164711_ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="zh-cn_topic_0000001173164711_ae95f3df496fc41939ac6c1cf74aef9d8"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164711_row16114627482"><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164711_p1311416272810"><a name="zh-cn_topic_0000001173164711_p1311416272810"></a><a name="zh-cn_topic_0000001173164711_p1311416272810"></a>getApp</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164711_p171148271181"><a name="zh-cn_topic_0000001173164711_p171148271181"></a><a name="zh-cn_topic_0000001173164711_p171148271181"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="70.26%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164711_p1111420275815"><a name="zh-cn_topic_0000001173164711_p1111420275815"></a><a name="zh-cn_topic_0000001173164711_p1111420275815"></a>提供getApp()全局方法，可以在自定义js文件中获取app.js中暴露的对象。</p>
</td>
</tr>
</tbody>
</table>

示例如下：

```
// app.js
export default {
    data: {
        test: "by getAPP"
    },
    onCreate() {
        console.info('AceApplication onCreate');
    },
    onDestroy() {
        console.info('AceApplication onDestroy');
    },
};
```

```
// test.js 自定义逻辑代码
export var appData = getApp().data;
```

