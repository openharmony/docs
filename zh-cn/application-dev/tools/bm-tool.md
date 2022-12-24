# bm工具


Bundle Manager（包管理工具，简称bm）是实现应用安装、卸载、更新、查询等功能的工具，bm为开发者提供基本的应用安装包的调试能力，开发者可以在hdc shell中，执行bm命令以触发各种系统操作，例如：安装应用，卸载应用，查询安装包信息等。


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
| -p | 是 | 安装HAP包路径，支持指定路径和多个HAP同时安装 |
| -u | 否，默认安装到当前所有用户上 | 给指定用户安装一个HAP包 |
| -r | 否，默认值为覆盖安装 | 覆盖安装一个HAP包 |
| -w | 否，默认等待5s | 安装HAP包时指定bm工具等待时间，最小的等待时长为5s，最大的等待时长为600s,&nbsp;默认缺省为5s |


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


示例：

```bash
bm uninstall -n com.ohos.app -m com.ohos.app.MainAbility -u 100 -k
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
bm enable -n com.ohos.app -a com.ohos.app.MainAbility -u 100
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
bm disable -n com.ohos.app -a com.ohos.app.MainAbility -u 100
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
