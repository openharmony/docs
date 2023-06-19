# 快速修复命令行调试开发指导

当前阶段，OpenHarmony为开发者提供了命令行的调试开发工具可供使用。比如，包名为com.ohos.quickfix的示例应用，版本号为1000000。该应用的当前版本运行中有某问题需要修复，此时，开发者可参考如下指导使用快速修复能力解决应用问题。

## 编写配置文件patch.json

目前DevEco Studio中还不支持patch.json的配置，因此开发者可根据项目需要编写好该文件后，放到的项目任意目录，方便后续打包工具能够找到该文件即可。在本地新建一个patch.json文件，配置编写示例如下：
```json
{
    "app" : {
        "bundleName" : "com.ohos.quickfix",
        "versionCode" : 1000000, // 应用版本号
        "versionName" : "1.0.0.1",
        "patchVersionCode" : 1000000, // 补丁版本号
        "patchVersionName" : "1.0.0.1"
    },
    "module" : {
        "name" : "entry",
        "type" : "patch",
        "deviceTypes" : [
            "default",
            "tablet"
        ],
        "originalModuleHash" : "11223344556677889900" // 待修复hap包的sha256值
    }
}
```

## 生成快速修复文件
### 快速修复TS文件的代码
* 在DevEco Studio中修改TS文件后，编译HAP，可以在工程目录下找到对应的abc文件，如`build\default\cache\default\LegacyCompileETS\jsbundle\temporary\pages\index.abc`。

### 快速修复C++中的代码

* 在DevEco Studio中编译原C++的代码生成.so文件；修复原C++的代码，编译生成新的.so文件。可以在工程目录中找到该so，如`build\default\intermediates\libs\default\arm64-v8a\libentry.so`。
* 在本地OpenHarmony SDK路径的`toolchains`文件夹下查看`diff.exe`。通过该工具，基于新.so文件和旧的.so文件，生成.so的快速修复文件，命令如下：
```shell
$ diff.exe -s Example.z.so -d Example.z.so -p Example.z.so.diff
```
命令行参数含义：
- -s：旧so的路径
- -d：新so的路径
- -p：生成的差分文件的路径

## 生成.hqf的快速修复包

基于上述的patch.json、.abc快速修复文件和.so快速修复文件，可以通过本地OpenHarmony SDK路径的`toolchains`文件夹下的`app_packing_tool.jar`生成.hqf包，执行打包命令如下：
```shell
$ java -jar app_packing_tool.jar --mode hqf --json-path patch.json --lib-path libs --ets-path patchs --out-path entry-default-unsigned.hqf --force true
```

命令行参数介绍：
| 命令 |说明  | 备注|
| --- | --- |---|
| mode  |模式  | 必选|
| json-path|patch.json路径|必选|
| lib-path|.so快速修复文件路径，该路径可参考[快速修复包结构](quickfix-principles.md#快速修复包结构)|可选|
| ets-path|.abc快速修复文件路径|可选|

## 快速修复包的签名

签名与hap签名相同，将上述生成的entry-default-unsigned.hqf包，通过[签名工具](../security/hapsigntool-guidelines.md)进行签名。可以使用本地OpenHarmony SDK路径的`toolchains`文件夹下的`hap-sign-tool.jar`，命令如下：

```shell
$ java -jar hap-sign-tool.jar sign-app -keyAlias "OpenHarmony Application Release" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "OpenHarmonyApplication.pem" -profileFile "ohos_provision_release.p7b" -inFile "entry-default-unsigned.hqf" -keystoreFile "OpenHarmony.p12" -outFile "entry-signed-release.hqf" -keyPwd "123456" -keystorePwd "123456"
```

## 安装快速修复包

将上述entry-signed-release.hqf包推送到设备上
```shell
hdc.exe file send .\entry-signed-release.hqf /data/
```

在设备上通过下述命令行安装补丁包
```shell
$ bm quickfix -a -f /data/entry-signed-release.hqf
```

快速修复相关完整命令行参考如下：
```
$ bm quickfix -h
usage: bm quickfix <options>
options list:
-h, --help                                   list available commands
-q, --query                                  indicates query quickfix, used with -b or --bundle-name
-b, --bundle-name <bundle-name>              query quickfix status and information by a specified bundle name
-a, --apply                                  indicates apply quickfix, used with -f or --file-path
-f, --file-path <file-path>                  apply a quickfix file by a specified path
-f, --file-path <file-path> <file-path> ...  apply some quickfix files of one bundle
-f, --file-path <bundle-direction>           apply quickfix files by direction, under which are quickfix files
```
