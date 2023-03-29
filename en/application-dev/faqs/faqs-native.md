# Native API Usage

## Is there a native API that provides functions similar to Canvas?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Yes. The native API **Drawing** provides similar functions. It can be used for 2D drawing.

## When a native HAP is running, the error message "Obj is not a valid object" is displayed for the imported namespace. What should I do?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Check the **abiFilters** parameter value in the **build-profile.json5** file in the root directory of the module (not the root directory of the project). If the device is 32-bit, the value must be **armeabi-v7a**. If the device is 64-bit, the value must be **arm64-v8a**.

## What should I do when the error message "install parse profile prop check error" is displayed during the running of a native HAP?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

Check the **abiFilters** parameter value in the **build-profile.json5** file in the root directory of the module (not the root directory of the project). If the device is 32-bit, the value must be **armeabi-v7a**. If the device is 64-bit, the value must be **arm64-v8a**.

## What should I do when the error message "undefined symbol: OH_LOG_Print" is displayed during log printing by **OH_LOG_Print**?

Applicable to: OpenHarmony SDK 3.2.6.3, stage model of API version 9

Modify the **CMakeLists.txt** file by adding **libhilog_ndk.z.so** to the end of **target_link_libraries**.

## How do I obtain the value of version in the package.json file of a module?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. In the script file **hvigorfile.js** of Hvigor, use **subModule.getPackageJsonPath** to obtain the location of the **package.json** file in the module.

2. Use Node.js to read the **version** field in the **package.json** file and write the value to the **buildOption.cppFlags** field in the **build-profile.json5** file.

Example


```
// Module-level hvigorfile.js
const subModule = require('@ohos/hvigor')(__filename)

const fs = require("fs-extra")
const path = require("path")

const packageJsonPath = subModule.getPackageJsonPath()
const buildProfilePath = path.resolve(packageJsonPath, '../build-profile.json5')
const packageJsonData = JSON.parse(fs.readFileSync(packageJsonPath, 'utf8'))
let buildProfileData = fs.readFileSync(buildProfilePath, 'utf8')
buildProfileData = buildProfileData.replace(/\"cppFlags\"\:(.*)\,/, `"cppFlags": "-D NWEBEX_VERSION=${packageJsonData.version}",`)
fs.writeFileSync(buildProfilePath, buildProfileData, 'utf8')

const ohosPlugin = require('@ohos/hvigor-ohos-plugin').hapTasks(subModule) // The plug-in executes the C++ build task and reads the build-profile.json5 file.

module.exports = {
  ohos: ohosPlugin
}
```


```
// Read the hello.cpp file.
#define _NWEBEX_VERSION(v) #v
#define _NWEBEX_VER2STR(v) _NWEBEX_VERSION(v)

static napi_value Add(napi_env env, napi_callback_info info)
{

    napi_value fixed_version_value = nullptr;
    napi_create_string_utf8(env, _NWEBEX_VER2STR(NWEBEX_VERSION), NAPI_AUTO_LENGTH, &fixed_version_value);

    return fixed_version_value;
}
```

## How do I traverse files in rawfile?

Applicable to: OpenHarmony SDK 3.2 or later, stage model of API version 9

Use the native API **OH_ResourceManager_OpenRawDir()** to obtain the root directory of **rawfile** and traverse the root directory.  
