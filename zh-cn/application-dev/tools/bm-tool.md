# bm工具


Bundle Manager（包管理工具，简称bm）是实现应用安装、卸载、更新、查询等功能的工具，bm为开发者提供基本的应用安装包的调试能力，例如：安装应用，卸载应用，查询安装包信息等。

> **说明：**
>
> 在使用本工具前，开发者需要先获取[hdc工具](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)，执行hdc shell。


  **表1** bm工具命令列表

| 命令 | 描述 |
| -------- | -------- |
| help | 帮助命令，显示bm支持的命令信息 |
| install | 安装命令，用来安装应用 |
| uninstall | 卸载命令，用来卸载应用 |
| dump | 查询命令，用来查询应用的相关信息 |
| clean | 清理命令，用来清理应用的缓存和数据 |
| enable | 使能命令，用来使能应用，使能后应用可以继续使用 |
| disable | 禁用命令，用来禁用应用，禁用后应用无法使用 |
| get | 获取udid命令，用来获取设备的udid |
| quickfix | 快速修复相关命令，用来执行补丁相关操作，如补丁安装、补丁查询 |


## 帮助命令

  **表2** help命令列表

| 命令 | 描述 |
| -------- | -------- |
| bm&nbsp;help | 显示bm工具的能够支持的命令信息 |

示例：


```bash
# 显示帮助信息
bm help
```


## 安装命令

```bash
bm install [-h] [-p path] [-u userId] [-r] [-w waitting-time]
```


  **表3** 安装命令列表

| 命令 | 是否必选 | 描述 |
| -------- | -------- | -------- |
| -h | 否，默认输出帮助信息 | 显示install支持的命令信息 |
| -p | 是 | 安装HAP路径，支持指定路径和多个HAP同时安装 |
| -u | 否，默认安装到当前所有用户上 | 给指定用户安装一个HAP |
| -r | 否，默认值为覆盖安装 | 覆盖安装一个HAP |
| -w | 否，默认等待5s | 安装HAP时指定bm工具等待时间，最小的等待时长为5s，最大的等待时长为600s,&nbsp;默认缺省为5s |


示例：

```bash
bm install -p /data/app/ohosapp.hap -u 100 -w 5s -r
// 执行结果
install bundle successfully.
```


## 卸载命令

```bash
bm uninstall [-h help] [-n bundleName] [-m moduleName] [-u userId] [-k]
```


  **表4** 卸载命令列表

| 命令 | 是否必选 | 描述 |
| -------- | -------- | -------- |
| -h | 否，默认输出帮助信息 | 显示uninstall支持的命令信息 |
| -n | 是 | 指定Bundle名称卸载应用 |
| -m | 否，默认卸载所有模块 | 指定卸载应用的一个模块 |
| -u | 否，默认卸载当前所有用户下该应用 | 指定用户卸载应用 |
| -k | 否，默认卸载应用时不保存应用数据 | 卸载应用时保存应用数据 |
| -v | 否，默认卸载同包名的所有共享包 | 指示共享包的版本号 |


示例：

```bash
bm uninstall -n com.ohos.app -m com.ohos.app.EntryAbility -u 100 -k
// 执行结果
uninstall bundle successfully.
```


## 查询命令

```bash
bm dump [-h help] [-a] [-n bundleName] [-s shortcutInfo] [-u userId] [-d deviceId]
```


注：-u未指定情况下，默认为所有用户。


  **表5** 查询命令列表

| 命令 | 是否必选 | 描述 |
| -------- | -------- | -------- |
| -h | 否，默认输出帮助信息 | 显示dump支持的命令信息 |
| -a | 是 | 查询系统已经安装的所有应用 |
| -n | 是 | 查询指定Bundle名称的详细信息 |
| -s | 是 | 查询指定Bundle名称下的快捷方式信息 |
| -d | 否，默认查询当前设备 | 查询指定设备中的包信息 |
| -u | 否，默认查询当前设备上的所有用户 | 查询指定用户下指定Bundle名称的详细信息 |


示例：

```bash
# 显示所有已安装的Bundle名称
bm dump -a
# 查询该应用的详细信息
bm dump -n com.ohos.app -u 100
# 查询该应用的快捷方式信息
bm dump -s com.ohos.app -u 100
# 查询跨设备应用信息
bm dump -n com.ohos.app -d xxxxx
```


## 清理命令

```bash
bm clean [-h] [-c] [-n  bundleName] [-d] [-u userId]
```


注：-u未指定情况下，默认为当前活跃用户。


  **表6** 清理命令列表

| 命令 | 描述 |
| -------- | -------- |
| -h | 显示clean支持的命令信息 |
| -c&nbsp;-n | 清除指定Bundle名称的缓存数据 |
| -d&nbsp;-n | 清除指定Bundle名称的数据目录 |
| -u | 清除指定用户下Bundle名称的缓存数据 |


示例：

```bash
# 清理该应用下的缓存数据
bm clean -c -n com.ohos.app -u 100
// 执行结果
clean bundle cache files successfully.
# 清理该应用下的用户数据
bm clean -d -n com.ohos.app -u 100
// 执行结果
clean bundle data files successfully.
```


## 使能命令

```bash
bm enable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


注：-u未指定情况下，默认为当前活跃用户。


  **表7** 使能命令列表

| 命令 | 描述 |
| -------- | -------- |
| -h | 显示enable支持的命令信息 |
| -n | 使能指定Bundle名称的应用 |
| -a | 使能指定Bundle名称下的元能力模块 |
| -u | 使能指定用户和Bundle名称的应用 |


示例：

```bash
# 使能该应用
bm enable -n com.ohos.app -a com.ohos.app.EntryAbility -u 100
// 执行结果
enable bundle successfully.
```


## 禁用命令

```bash
bm disable [-h] [-n bundleName] [-a abilityName] [-u userId]
```


注：-u未指定情况下，默认为当前活跃用户。


  **表8** 禁用命令列表

| 命令 | 描述 |
| -------- | -------- |
| -h | 显示disable支持的命令信息 |
| -n | 禁用指定Bundle名称的应用 |
| -a | 禁用指定Bundle名称下的元能力模块 |
| -u | 禁用指定用户和Bundle名称下的应用 |

示例：

```bash
# 禁用该应用
bm disable -n com.ohos.app -a com.ohos.app.EntryAbility -u 100
// 执行结果
disable bundle successfully.
```


## 获取udid

```bash
bm get [-h] [-u]
```


  **表9** 获取udid命令列表

| 命令 | 描述 |
| -------- | -------- |
| -h | 显示get支持的命令信息 |
| -u | 获取设备的udid |


示例：

```bash
# 获取设备的udid
bm get -u
// 执行结果
udid of current device is :
23CADE0C
```


## 快速修复

```bash
bm quickfix [-h] [-a -f filePath] [-q -b bundleName]
```


  **表10** 快速修复命令列表

| 命令 | 描述 |
| -------- | -------- |
| -h | 显示quickfix支持的命令信息 |
| -a&nbsp;-f | 执行快速修复补丁安装命令，file-path对应hqf文件，支持传递1个或多个hqf文件，或传递hqf文件所在的目录。 |
| -q&nbsp;-b | 根据包名查询补丁信息，bundle-name对应包名。 |


示例：

```bash
# 根据包名查询补丁包信息
bm quickfix -q -b com.ohos.app
// 执行结果
// Information as follows:            
// ApplicationQuickFixInfo:           
//  bundle name: com.ohos.app 
//  bundle version code: xxx     
//  bundle version name: xxx       
//  patch version code: x            
//  patch version name:              
//  cpu abi:                          
//  native library path:             
//  type:                            
# 快速修复补丁安装
bm quickfix -a -f /data/app/
//执行结果
apply quickfix succeed.
```

## 共享库查询命令

```bash
bm dump-shared [-h help] [-a] [-n bundleName] [-m moudleName]
```

  **表11** 共享库查询命令列表

| 命令                                             | 描述                                   |
| ------------------------------------------------ | -------------------------------------- |
| bm dump-shared -h                                | 显示dump-shared支持的命令信息          |
| bm dump-shared -a                                | 查询系统中已安装所有共享库             |
| bm dump-shared -n                                | 查询指定共享库包名的详细信息           |
| bm dump-dependencies -h                          | 显示bm dump-dependencies支持的命令信息 |
| bm dump-dependencies -n bundleName -m moudleName | 查询指定应用指定模块依赖的共享库信息   |

示例：

```bash
# 显示所有已安装共享库包名
bm dump-shared -a
# 显示该共享库的详细信息
bm dump-shared -n com.ohos.lib
# 显示指定应用指定模块依赖的共享库信息
bm dump-dependencies -n com.ohos.app -m entry
```

## 常见问题

### 安装HAP时提示“code:9568320 error: no signature file”
**问题现象**

对HAP包签名后，在设备中运行HAP时提示“failed to install bundle. error: install no signature info”或“failed to install bundle. error: no signature file”。

![示例图](figures/zh-cn_image_0000001389116960.png)

**解决措施**

该问题是由于安装未签名的HAP导致，需要开发者对开发的HAP进行签名之后再安装。
1. 使用[自动签名](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/signing-0000001587684945-V3#section18815157237)。在连接设备后，重新为应用进行签名。
1. 如果使用的是手动签名，对于OpenHarmony应用，请参考[OpenHarmony应用手动签名](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/hapsigntool-guidelines.md)

### 安装HAP时提示“code:9568347 error: install parse native so failed”错误
**问题现象**

在启动调试或运行C++应用/服务时，安装HAP出现错误，提示“error: install parse native so failed”错误信息。

**解决措施**

该问题可能是由于设备支持的Abi类型与C++工程中配置的Abi类型不匹配，请通过如下步骤进行解决。

1. 将设备与DevEco Studio进行连接。
2. 打开命令行工具，并进入SDK安装目录下的toolchains\{版本号}目录下。
    ```
    若不清楚OpenHarmony SDK安装目录，可单击File > Settings > SDK界面查看安装路径。
    ```
3. 执行如下命令，查询设备支持的Abi列表，返回结果为default/armeabi-v7a/armeabi/arm64-v8a/x86/x86_64中的一个或多个Abi类型。
    ```
    hdc shell
    param get const.product.cpu.abilist
    ```
4. 根据查询返回结果，检查[模块级build-profile.json5](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/build_config-0000001052902431-V3#section6887184182020)文件中的“abiFilters”参数中的配置，规则如下：
    * 若返回结果为default，请执行如下命令，查询是否存在lib64文件夹。
      ```
      cd /system/
      ls
      ```
      ![示例图](figures/zh-cn_image_0000001609001262.png)
      * 存在lib64文件夹：则“abiFilters”参数中需要包含arm64-v8a类型。
      * 不存在lib64文件夹：则“abiFilters”参数中需要至少包含armeabi/armeabi-v7a中的一个类型。
    * 若返回结果为armeabi-v7a/armeabi/arm64-v8a/x86/x86_64中的一个或多个，需要在“abiFilters”参数中至少包含返回结果中的一个Abi类型。

### 安装HAP时提示“code:9568344 error: install parse profile prop check error”错误
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: install parse profile prop check error”错误信息。

![示例图](figures/zh-cn_image_0000001585361412.png)

**解决措施**

该问题可能是由于应用使用了应用特权，但应用的签名文件发生变化后未将新的签名指纹重新配置到设备的特权管控白名单文件install_list_capability.json中，请通过如下步骤进行解决。

1. 获取新的签名指纹。

    a. 在项目级build-profile.json5文件中，signingConfigs字段内的profile的值即为签名文件的存储路径。

    b. 打开该签名文件（后缀为.p7b），打开后在文件内搜索“development-certificate”，将“-----BEGIN CERTIFICATE-----”和“-----END CERTIFICATE-----”以及中间的信息拷贝到新的文本中，注意换行并去掉换行符，保存为一个新的.cer文件，如命名为xxx.cer。

    新的.cer文件格式如下图（仅作为格式示意，内容以实际为准）：

    ![示例图](figures/zh-cn_image_0000001585521364.png)



    c. 使用keytool工具（在DevEco Studio安装目录下的jbr/bin文件夹内），执行如下命令通过.cer文件获取证书指纹的SHA256值。
      ```
      keytool -printcert -file xxx.cer
      ```
    d. 将证书指纹中SHA256的内容去掉冒号，即为最终要获得的签名指纹。
    
    如SHA256值为下图（仅作为格式示意，内容以实际为准）：
    ![示例图](figures/zh-cn_image_0000001635921233.png)

    去掉冒号后的签名指纹为：5753DDBC1A8EF88A62058A9FC4B6AFAFC1C5D8D1A1B86FB3532739B625F8F3DB

2. 获取设备的特权管控白名单文件install_list_capability.json。

    a. 连接设备。

    b. 执行如下命令查看设备的特权管控白名单文件install_list_capability.json。
    ```
    find /system -name install_list_capability.json
    ```
    设备上install_list_capability.json的位置通常为以下目录地址，通过bundleName找到对应的配置文件：
    ```
    /system/etc/app/install_list_capability.json
    ```
    c. 执行如下命令拉取install_list_capability.json。
    ```
    hdc shell mount -o rw,remount /
    hdc file recv /system/etc/app/install_list_capability.json
    ```

3. 将步骤1获取到的签名指纹配置到install_list_capability.json文件的app_signature中，注意要配置到对应的bundleName下。
![示例图](figures/zh-cn_image_0000001635641893.png)
4. 将修改后的install_list_capability.json文件重新推到设备上，并重启设备。

    ```
    hdc shell mount -o rw,remount / 
    hdc file send install_list_capability.json /system/etc/app/install_list_capability.json 
    hdc shell chmod 777 /system/etc/app/install_list_capability.json 
    hdc shell reboot
    ```
5. 设备重启后，重新安装新的应用即可。

### 安装HAP时提示“code:9568305 error: dependent module does not exist”错误
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: dependent module does not exist”错误信息。

![示例图](figures/zh-cn_image_0000001560338986.png)

**解决措施**

该问题是由于运行/调试的应用依赖的动态共享包（SharedLibrary）模块未安装导致安装报错，您可以通过如下方式进行解决：

* 先安装依赖的动态共享包（SharedLibrary）模块，再在应用运行配置页勾选Keep Application Data，点击OK保存配置，再运行/调试。
![示例图](figures/zh-cn_image_0000001560201786.png)

* 在运行配置页，选择Deploy Multi Hap标签页，勾选Deploy Multi Hap Packages，选择依赖的模块，点击OK保存配置，再进行运行/调试。
![示例图](figures/zh-cn_image_0000001610761941.png)

### 安装HAP时提示“code:9568259 error: install parse profile missing prop”
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: install parse profile missing prop”错误信息。

![示例图](figures/zh-cn_image_0000001559130596.png)

**解决措施**

出现该问题的原因是配置文件app.json5和module.json5中必填字段缺失。

* 方法1：请参考[app.json5配置文件](../../application-dev/quick-start/app-configuration-file.md)和[module.json5配置文件](../../application-dev/quick-start/module-configuration-file.md)查看并补充必填字段。
* 方法2：通过hilog日志判断缺失字段。

    开启落盘命令：
    ```
    hilog -w start
    ```

    落盘位置：/data/log/hilog

    打开日志查看“profile prop %{public}s is mission”。如“profile prop icon is mission”表示“icon”字段缺失。

### 安装HAP时提示“code:9568258 error: install releaseType target not same”
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: install releaseType target not same”错误信息。

![示例图](figures/zh-cn_image_0000001609976041.png)

**解决措施**

出现该问题的原因是设备上已安装的旧HAP和现在要安装的新HAP所使用的SDK中的releaseType值不一样。请先卸载设备上已安装的HAP，再安装新的HAP。

### 安装HAP时提示“code:9568322 error: signature verification failed due to not trusted app source”
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: signature verification failed due to not trusted app source”错误信息。

![示例图](figures/zh-cn_image_0000001585042216.png)

**解决措施**

该问题是由于签名中未包含该调试设备的UDID，请通过如下步骤进行解决。

* 使用[自动签名](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/signing-0000001587684945-V3#section18815157237)。在连接设备后，重新为应用进行签名。
* 如果使用的是手动签名，对于OpenHarmony应用，请参考[OpenHarmony应用手动签名](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/hapsigntool-guidelines.md)，在UnsgnedDebugProfileTemplate.json文件中添加该调试设备的**UDID**
```
//UDID获取命令
hdc shell bm get -u
```

### 安装HAP时提示“code:9568289 error: install failed due to grant request permissions failed”
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: install failed due to grant request permissions failed”错误信息。

![示例图](figures/zh-cn_image_0000001585201996.png)

**解决措施**

该问题是由于默认应用等级为normal，只能使用normal等级的权限，如果使用了system_basic或system_core等级的权限，将导致报错。

在UnsgnedDebugProfileTemplate.json文件中修改apl等级，调整成system_basic或system_core等级，重新签名打包即可。

### 安装HAP时提示“code:9568297 error: install failed due to older sdk version in the device”
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: install failed due to older sdk version in the device”错误信息。

![示例图](figures/zh-cn_image_0000001635521909.png)

**解决措施**

该问题是由于编译打包所使用的SDK版本与设备镜像版本不匹配。不匹配的场景包括：

* 场景一：设备上的镜像版本低于编译打包的SDK版本，请更新设备镜像版本。查询设备镜像版本命令：
  ```
  hdc shell param get const.ohos.apiversion
  ```
  如果镜像提供的api版本为10，且应用编译所使用的SDK版本也为10，仍出现该报错，可能是由于镜像版本较低，未兼容新版本SDK校验规则，请将镜像版本更新为最新版本。

* 场景二：对于需要运行在OpenHarmony设备上的应用，请确认runtimeOS已改为OpenHarmony。

### 安装HAP时提示“code:9568332 error: install sign info inconsistent”
**问题现象**

在启动调试或运行应用/服务时，安装HAP出现错误，提示“error: install sign info inconsistent”错误信息。

![示例图](figures/zh-cn_image_0000001635761329.png)

**解决措施**

该问题是由于设备上已安装的应用与新安装的应用中签名不一致。如果在**Edit Configurations**中勾选了“Keep Application Data”（不卸载应用，覆盖安装），并且重新进行了签名，将导致该报错。

请卸载设备上已安装的应用，或取消勾选“Keep Application Data”后，重新安装新的应用。
