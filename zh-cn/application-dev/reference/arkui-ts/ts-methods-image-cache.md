# 图片缓存<a name="ZH-CN_TOPIC_0000001192915092"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

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

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>内存中解码后图片的缓存数量。</p>
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

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>内存中解码前图片数据的缓存大小，单位为字节。</p>
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

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>图片文件的缓存大小，单位为字节。</p>
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


