# 图片缓存<a name="ZH-CN_TOPIC_0000001164050290"></a>

## 导入模块<a name="section5628811168"></a>

```
import app from '@system.app'
```

## 权限<a name="section137491348987"></a>

无

## app.setImageCacheCount<a name="section11154121091314"></a>

setImageCacheCount\(value: number\): void

设置内存中缓存解码后图片的数量上限，提升再次加载同源图片的加载速度。如果不设置则默认为0，不进行缓存。缓存采用内置的LRU策略，新图片加载后，如果超过缓存上限，会删除最久未再次加载的缓存。建议根据应用内存需求，设置合理缓存数量，数字过大可能导致内存使用过高。

-   参数

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>内存中解码后图片的缓存数量。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // app.ets
    import app from '@system.app';
    
    export default {
        onCreate() { 
            app.setImageCacheCount(100)    // 设置解码后图片内存缓存上限为100张
            console.info('Application onCreate')
        },
        onDestroy() {
            console.info('Application onDestroy')
        },
    }
    ```


## app.setImageRawDataCacheSize<a name="section14955104018114"></a>

setImageRawDataCacheSize\(value: number\): void

设置内存中缓存解码前图片数据的大小上限，单位为字节，提升再次加载同源图片的加载速度。如果不设置则默认为0，不进行缓存。缓存采用内置的LRU策略，新图片加载后，如果解码前数据超过缓存上限，会删除最久未再次加载的图片数据缓存。建议根据应用内存需求，设置合理缓存上限，过大可能导致应用内存使用过高。

-   参数

    <a name="table5694170152416"></a>
    <table><thead align="left"><tr id="row86942002415"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1769418002417"><a name="p1769418002417"></a><a name="p1769418002417"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p76944082418"><a name="p76944082418"></a><a name="p76944082418"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p3694609246"><a name="p3694609246"></a><a name="p3694609246"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p116940032414"><a name="p116940032414"></a><a name="p116940032414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7694150172412"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p146942062411"><a name="p146942062411"></a><a name="p146942062411"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p196947013244"><a name="p196947013244"></a><a name="p196947013244"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p56956012242"><a name="p56956012242"></a><a name="p56956012242"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2069540182411"><a name="p2069540182411"></a><a name="p2069540182411"></a>内存中解码前图片数据的缓存大小，单位为字节。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // app.ets
    import app from '@system.app';
    
    export default {
        onCreate() {
            app.setImageRawDataCacheSize(104,857,600) // 设置解码前图片数据内存缓存上限为100MB
            console.info('Application onCreate')
        },
        onDestroy() {
            console.info('Application onDestroy')
        },
    }
    ```


## app.setImageFileCacheSize<a name="section182498527405"></a>

setImageFileCacheSize\(value: number\): void

设置图片文件缓存的大小上限，单位为字节，提升再次加载同源图片的加载速度，特别是对网络图源、缩略图会有较明显提升。如果不设置则默认为100MB。缓存采用内置的LRU策略，新图片加载后，如果超过文件缓存上限，会按照时间由远到近删除缓存图片文件直到缓存图片大小满足缓存上限。建议根据应用实际需求，设置合理文件缓存上限，数字过大可能导致磁盘空间占用过高。

-   参数

    <a name="table1319132705612"></a>
    <table><thead align="left"><tr id="row419152719562"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p11194271563"><a name="p11194271563"></a><a name="p11194271563"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p619122712565"><a name="p619122712565"></a><a name="p619122712565"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p81919277561"><a name="p81919277561"></a><a name="p81919277561"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1619427175614"><a name="p1619427175614"></a><a name="p1619427175614"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row31912271562"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p121952717562"><a name="p121952717562"></a><a name="p121952717562"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10191527125610"><a name="p10191527125610"></a><a name="p10191527125610"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p101962718567"><a name="p101962718567"></a><a name="p101962718567"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18191527115615"><a name="p18191527115615"></a><a name="p18191527115615"></a>图片文件的缓存大小，单位为字节。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    // app.ets
    import app from '@system.app';
    
    export default {  
        onCreate() {    
            app.setImageFileCacheSize(209,715,200) // 设置图片文件数据缓存上限为200MB   
            console.info('Application onCreate')
        },  
        onDestroy() {
            console.info('Application onDestroy')
        },
    }
    ```


