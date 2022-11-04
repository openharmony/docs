# Native API使用常见问题

## Native API是否有类似Canvas绘制接口

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

Native API中的[Drawing](../reference/native-apis/_drawing.md)接口可以提供2D绘制功能。

## 运行Native HAP的时候，导入的命名空间报错Obj is not a valid object

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

检查模块根目录（注意不是工程根目录）下的build-profile.json5文件，如果设备是32位，需要在abiFilters参数中配置armeabi-v7a，如果设备是64位，需要在abiFilters参数中配置arm64-v8a。

## 运行Native HAP的时候，报错install parse profile prop check error

适用于：OpenHarmony SDK 3.2.6.3版本，API9 Stage模型

检查模块根目录（注意不是工程根目录）下的build-profile.json5文件，如果设备是32位，需要在abiFilters参数中配置armeabi-v7a，如果设备是64位，需要在abiFilters参数中配置arm64-v8a。

## 在Native代码中使用OH_LOG_Print打印日志，报错undefined symbol: OH_LOG_Print

适用于：OpenHarmony SDK 3.2.6.3版本，API9 Stage模型

需要修改CMakeLists.txt文件，在target_link_libraries最后追加libhilog_ndk.z.so。

## 如何获取到模块 package.json 文件中的 “version” 值

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 在编译工具Hvigor脚本文件hvigorfile.js中，通过subModule.getPackageJsonPath方法获取module中package.json文件位置；

2. 使用nodejs能力读取package.json文件中version字段，写入build-profile.json5文件buildOption.cppFlags字段；

示例：

  
```
// module hvigorfile.js
const subModule = require('@ohos/hvigor')(__filename)

const fs = require("fs-extra")
const path = require("path")

const packageJsonPath = subModule.getPackageJsonPath()
const buildProfilePath = path.resolve(packageJsonPath, '../build-profile.json5')
const packageJsonData = JSON.parse(fs.readFileSync(packageJsonPath, 'utf8'))
let buildProfileData = fs.readFileSync(buildProfilePath, 'utf8')
buildProfileData = buildProfileData.replace(/\"cppFlags\"\:(.*)\,/, `"cppFlags": "-D NWEBEX_VERSION=${packageJsonData.version}",`)
fs.writeFileSync(buildProfilePath, buildProfileData, 'utf8')

const ohosPlugin = require('@ohos/hvigor-ohos-plugin').hapTasks(subModule) // 该插件执行了C++编译任务，读取了build-profile.json5文件

module.exports = {
  ohos: ohosPlugin
}
```

  
```
// hello.cpp 读取
#define _NWEBEX_VERSION(v) #v
#define _NWEBEX_VER2STR(v) _NWEBEX_VERSION(v)

static napi_value Add(napi_env env, napi_callback_info info)
{

    napi_value fixed_version_value = nullptr;
    napi_create_string_utf8(env, _NWEBEX_VER2STR(NWEBEX_VERSION), NAPI_AUTO_LENGTH, &fixed_version_value);

    return fixed_version_value;
}
```

## 如何遍历rawfiles中的文件

适用于：OpenHarmony SDK 3.2版本以上，API9 Stage模型

使用Native API中的OH_ResourceManager_OpenRawDir()方法获取到rawfile的根目录，然后对其进行遍历。可参考文档：[Native开发指导](../reference/native-apis/rawfile.md)

<!--no_check--> 