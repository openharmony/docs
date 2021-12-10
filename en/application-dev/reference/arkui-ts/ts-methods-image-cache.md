# Image Cache<a name="EN-US_TOPIC_0000001164050290"></a>

## Modules to Import<a name="section5628811168"></a>

```
import app from '@system.app'
```

## Required Permissions<a name="section137491348987"></a>

None

## app.setImageCacheCount<a name="section11154121091314"></a>

setImageCacheCount\(value: number\): void

Sets the maximum number of decoded images that can be cached in the memory to speed up the loading of images from the same sources. If the input parameter is not set, the default value  **0**  is used, indicating that images are not cached. The built-in Least Recently Used \(LRU\) policy is used for caching. After new images are loaded, if the upper limit of the cache is exceeded, the images that have not been updated for the longest time will be replaced. You are advised to set the input parameter based on the application memory requirements. If the number of images is too large, the memory usage may be too high.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>Number of decoded images that are cached in the memory.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // app.ets
    import app from '@system.app';
    
    export default {
        onCreate() { 
            app.setImageCacheCount(100)    // Set the maximum number of decoded images that can be cached in the memory to 100.
            console.info('Application onCreate')
        },
        onDestroy() {
            console.info('Application onDestroy')
        },
    }
    ```


## app.setImageRawDataCacheSize<a name="section14955104018114"></a>

setImageRawDataCacheSize\(value: number\): void

Sets the maximum size \(in bytes\) of the image data cached in the memory before decoding to speed up the loading of images from the same sources. If the input parameter is not set, the default value  **0**  is used, indicating that images are not cached. The LRU policy is used for caching. After new images are loaded, if the upper limit of the cache is exceeded, the images that have not been updated for the longest time will be replaced. You are advised to set the input parameter based on the application memory requirements. If the image cache is too large, the memory usage may be too high.

-   Parameters

    <a name="table5694170152416"></a>
    <table><thead align="left"><tr id="row86942002415"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1769418002417"><a name="p1769418002417"></a><a name="p1769418002417"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p76944082418"><a name="p76944082418"></a><a name="p76944082418"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p3694609246"><a name="p3694609246"></a><a name="p3694609246"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p116940032414"><a name="p116940032414"></a><a name="p116940032414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7694150172412"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p146942062411"><a name="p146942062411"></a><a name="p146942062411"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p196947013244"><a name="p196947013244"></a><a name="p196947013244"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p56956012242"><a name="p56956012242"></a><a name="p56956012242"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2069540182411"><a name="p2069540182411"></a><a name="p2069540182411"></a>Size of the image data cached before decoding, in bytes.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // app.ets
    import app from '@system.app';
    
    export default {
        onCreate() {
            app.setImageRawDataCacheSize(104,857,600) // Set the upper limit of the memory for caching image data before decoding to 100 MB.
            console.info('Application onCreate')
        },
        onDestroy() {
            console.info('Application onDestroy')
        },
    }
    ```


## app.setImageFileCacheSize<a name="section182498527405"></a>

setImageFileCacheSize\(value: number\): void

Sets the maximum size of the image file cache \(in bytes\) to speed up the loading of images from the same sources, especially online image sources and thumbnails. If the input parameter is not set, the default value 100 MB is used. The LRU policy is used for caching. After new images are loaded, if the upper limit of the cache is exceeded, the images that have not been updated for the longest time will be replaced. You are advised to set the input parameter based on the application memory requirements. If the image cache is too large, the disk usage may be too high.

-   Parameters

    <a name="table1319132705612"></a>
    <table><thead align="left"><tr id="row419152719562"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p11194271563"><a name="p11194271563"></a><a name="p11194271563"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p619122712565"><a name="p619122712565"></a><a name="p619122712565"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p81919277561"><a name="p81919277561"></a><a name="p81919277561"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1619427175614"><a name="p1619427175614"></a><a name="p1619427175614"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row31912271562"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p121952717562"><a name="p121952717562"></a><a name="p121952717562"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10191527125610"><a name="p10191527125610"></a><a name="p10191527125610"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p101962718567"><a name="p101962718567"></a><a name="p101962718567"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18191527115615"><a name="p18191527115615"></a><a name="p18191527115615"></a>Size of the image file cache, in bytes.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // app.ets
    import app from '@system.app';
    
    export default {  
        onCreate() {    
            app.setImageFileCacheSize(209,715,200) // Set the upper limit of the image file cache to 200 MB.
            console.info('Application onCreate')
        },  
        onDestroy() {
            console.info('Application onDestroy')
        },
    }
    ```


