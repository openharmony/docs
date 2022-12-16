# @system.package (应用管理)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> - 从API version 9开始不再维护，推荐使用该模块[@ohos.bundle.bundleManager](js-apis-bundleManager.md)。
>
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import package from '@system.package';
```


## package.hasInstalled<sup>(deprecated)</sup>
> 从API version 9开始不再维护，推荐使用该模块[@ohos.bundle.bundleManager](js-apis-bundleManager.md)。

hasInstalled(Object): void

查询指定应用是否存在，或者原生应用是否安装。

**需要权限：** ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|options | [CheckPackageHasInstalledOptions](#checkpackagehasinstalledoptions) | 是 | 选项参数。 |

**返回值：**

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| result | boolean | 表示查询的应用是否存在，或者原生应用是否安装。 |

**示例：**

``` ts
export default {
  hasInstalled() {
    package.hasInstalled({
      bundleName: 'com.example.bundlename',
      success: function(data) {
        console.log('package has installed: ' + data);
      },
      fail: function(data, code) {
        console.log('query package fail, code: ' + code + ', data: ' + data);
      },
    });
  },
}
```

## CheckPackageHasInstalledResponse

> 从API version 9开始不再维护。

指示应用包是否已安装。

**系统能力:** SystemCapability.BundleManager.BundleFramework。

| 名称 | 类型 | 说明 |
| --- | --- | ---- |
| result | boolean | 指示应用是否已安装。 |

## CheckPackageHasInstalledOptions

> 从API version 9开始不再维护。

查询包是否已安装时的选项。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |