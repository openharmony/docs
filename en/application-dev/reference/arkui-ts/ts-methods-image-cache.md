# Image Cache


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

  
```
import app from '@system.app'
```


## Required Permissions

None


## app.setImageCacheCount

setImageCacheCount(value: number): void

  Sets the maximum number of decoded images that can be cached in the memory to speed up the loading of images from the same sources. If the input parameter is not set, the default value **0** is used, indicating that images are not cached. The built-in Least Recently Used (LRU) policy is used for caching. After new images are loaded, if the upper limit of the cache is exceeded, the images that have not been updated for the longest time will be replaced. You are advised to set the input parameter based on the application memory requirements. If the number of images is too large, the memory usage may be too high.
- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | number | Yes | Number&nbsp;of&nbsp;decoded&nbsp;images&nbsp;that&nbsp;are&nbsp;cached&nbsp;in&nbsp;the&nbsp;memory. | 

- Example
    
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


## app.setImageRawDataCacheSize

setImageRawDataCacheSize(value: number): void

Sets the maximum size (in bytes) of the image data cached in the memory before decoding to speed up the loading of images from the same sources. If the input parameter is not set, the default value **0** is used, indicating that images are not cached. The LRU policy is used for caching. After new images are loaded, if the upper limit of the cache is exceeded, the images that have not been updated for the longest time will be replaced. You are advised to set the input parameter based on the application memory requirements. If the image cache is too large, the memory usage may be too high.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | number | Yes | Size&nbsp;of&nbsp;the&nbsp;image&nbsp;data&nbsp;cached&nbsp;before&nbsp;decoding,&nbsp;in&nbsp;bytes. | 

- Example
    
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


## app.setImageFileCacheSize

setImageFileCacheSize(value: number): void

Sets the maximum size of the image file cache (in bytes) to speed up the loading of images from the same sources, especially online image sources and thumbnails. If the input parameter is not set, the default value 100 MB is used. The LRU policy is used for caching. After new images are loaded, if the upper limit of the cache is exceeded, the images that have not been updated for the longest time will be replaced. You are advised to set the input parameter based on the application memory requirements. If the image cache is too large, the disk usage may be too high.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | value | number | Yes | Size&nbsp;of&nbsp;the&nbsp;image&nbsp;file&nbsp;cache,&nbsp;in&nbsp;bytes. | 

- Example
    
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
