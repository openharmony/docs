# 图片缓存

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从 API Version 7 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import app from '@system.app'
```


## 权限

无


## app.setImageCacheCount

setImageCacheCount(value: number): void

设置内存中缓存解码后图片的数量上限，提升再次加载同源图片的加载速度。如果不设置则默认为0，不进行缓存。缓存采用内置的LRU策略，新图片加载后，如果超过缓存上限，会删除最久未再次加载的缓存。建议根据应用内存需求，设置合理缓存数量，数字过大可能导致内存使用过高。
- 参数
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 内存中解码后图片的缓存数量。 | 

- 示例
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


## app.setImageRawDataCacheSize

setImageRawDataCacheSize(value: number): void

设置内存中缓存解码前图片数据的大小上限，单位为字节，提升再次加载同源图片的加载速度。如果不设置则默认为0，不进行缓存。缓存采用内置的LRU策略，新图片加载后，如果解码前数据超过缓存上限，会删除最久未再次加载的图片数据缓存。建议根据应用内存需求，设置合理缓存上限，过大可能导致应用内存使用过高。

- 参数
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 内存中解码前图片数据的缓存大小，单位为字节。 | 

- 示例
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


## app.setImageFileCacheSize

setImageFileCacheSize(value: number): void

设置图片文件缓存的大小上限，单位为字节，提升再次加载同源图片的加载速度，特别是对网络图源、缩略图会有较明显提升。如果不设置则默认为100MB。缓存采用内置的LRU策略，新图片加载后，如果超过文件缓存上限，会按照时间由远到近删除缓存图片文件直到缓存图片大小满足缓存上限。建议根据应用实际需求，设置合理文件缓存上限，数字过大可能导致磁盘空间占用过高。

- 参数
  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 图片文件的缓存大小，单位为字节。 | 

- 示例
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
