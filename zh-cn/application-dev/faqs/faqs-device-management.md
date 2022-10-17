# 设备管理开发常见问题



## 如何获取设备的dpi值

适用于：OpenHarmony SDK 3.2.2.5版本，API9 Stage模型

导入@ohos.display包，通过getDefaultDisplay方法获取。

示例：


```
import display from '@ohos.display'; 
display.getDefaultDisplay((err, data) => { 
  if (err.code) { 
    console.error('Test Failed to obtain the default display object. Code: ' + JSON.stringify(err)); 
    return; 
  } 
  console.info('Test Succeeded in obtaining the default display object. Data:' + JSON.stringify(data)); 
  console.info('Test densityDPI:' + JSON.stringify(data.densityDPI)); 
});
```
