# app.js<a name="EN-US_TOPIC_0000001173164711"></a>

## Application Lifecycle<a name="section597315421776"></a>

You can customize the  [lifecycle](js-framework-lifecycle.md)  implementation logic on an application-by-application basis in  **app.js**. The following example only prints the corresponding logs in the  **lifecycle**  function:

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

## Application Object<sup>6+</sup><a name="section61671730771"></a>

<a name="table2114112717810"></a>
<table><thead align="left"><tr id="r03f71ea1fd1245fd80e907a22a315e99"><th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.4.1.1"><p id="ae816119c3e0143c892512012c7927037"><a name="ae816119c3e0143c892512012c7927037"></a><a name="ae816119c3e0143c892512012c7927037"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="9.370000000000001%" id="mcps1.1.4.1.2"><p id="ab72e901bb3ef4657b303513b8fa5ec1f"><a name="ab72e901bb3ef4657b303513b8fa5ec1f"></a><a name="ab72e901bb3ef4657b303513b8fa5ec1f"></a>Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="82%" id="mcps1.1.4.1.3"><p id="ae95f3df496fc41939ac6c1cf74aef9d8"><a name="ae95f3df496fc41939ac6c1cf74aef9d8"></a><a name="ae95f3df496fc41939ac6c1cf74aef9d8"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16114627482"><td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.4.1.1 "><p id="p1311416272810"><a name="p1311416272810"></a><a name="p1311416272810"></a>getApp</p>
</td>
<td class="cellrowborder" valign="top" width="9.370000000000001%" headers="mcps1.1.4.1.2 "><p id="p171148271181"><a name="p171148271181"></a><a name="p171148271181"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.4.1.3 "><p id="p1111420275815"><a name="p1111420275815"></a><a name="p1111420275815"></a>Obtains the object exposed in the <strong id="b18467112117297"><a name="b18467112117297"></a><a name="b18467112117297"></a>app.js</strong> file from the custom <strong id="b2399945121212"><a name="b2399945121212"></a><a name="b2399945121212"></a>.js</strong> file.</p>
</td>
</tr>
</tbody>
</table>

The following is a sample code snippet:

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
// test.js Customize the logic code.
export var appData = getApp().data;
```

