# CLI-based Quick Fix Development

You can use the command-line tool to develop a quick fix file, an expeditious approach to resolve application bugs. In this document, an application with the bundle name of **com.ohos.quickfix** in version 1000000 is used as an example to describe how to develop a quick fix file with the command-line tool.

## Writing the patch.json File

Write a **patch.json** file that meets your project requirements and place it in any directory of the project. (Configuring the **patch.json** file is not supported in DevEco Studio.) Create a **patch.json** file on the local computer. Below is an example of the file content:
```json
{
    "app" : {
        "bundleName" : "com.ohos.quickfix",
        "versionCode": 1000000, // Application version
        "versionName" : "1.0.0.1",
        "patchVersionCode": 1000000, // Patch version
        "patchVersionName" : "1.0.0.1"
    },
    "module" : {
        "name" : "entry",
        "type" : "patch",
        "deviceTypes" : [
            "default",
            "tablet"
        ],
        "originalModuleHash": "11223344556677889900" // SHA-256 value of the HAP file to restore
    }
}
```

## Generating a Quick Fix File
### Quick Fix for TS Code
* After modifying the TS code file in DevEco Studio and build it into a HAP file, you can find the corresponding .abc file in the project directory, for example, **build\default\cache\default\LegacyCompileETS\jsbundle\temporary\pages\index.abc**.

### Quick Fix for C++ Code

* In DevEco Studio, build the original C++ code into a .so file. Fix bugs in the code and rebuild the code into a new .so file. You can find this .so file in the project directory, for example, **build\default\intermediates\libs\default\arm64-v8a\libentry.so**.
* Locate the **diff.exe** tool in the **toolchains** folder in the local OpenHarmony SDK path. Use this tool to generate a quick fix .so file based on the old and new .so files. The command is as follows:
```shell
$ diff.exe -s Example.z.so -d Example.z.so -p Example.z.so.diff
```
The command contains the following options:
- -**s**: path to the old .so file
- -**d**: path to the new .so file
- -**p**: path of the generated differential file

## Generating a Quick Fix File in .hqf Format

With the preceding **patch.json**, .abc, and .so files, run the following command to generate an .hqf file using the **app_packing_tool.jar** tool in the **toolchains** folder in the local OpenHarmony SDK path:
```shell
$ java -jar app_packing_tool.jar --mode hqf --json-path patch.json --lib-path libs --ets-path patchs --out-path entry-default-unsigned.hqf --force true
```

The command contains the following options.
| Option|Description | Remarks|
| --- | --- |---|
| mode  |Mode. | Mandatory|
| json-path|Path to the **patch.json** file.|Mandatory|
| lib-path|Path to the quick fix .so file. For details about the path, see [Structure of the Quick Fix Package](quickfix-principles.md#structure-of-the-quick-fix-package).|Optional|
| ets-path|Path to the quick fix .abc file.|Optional|

## Signing the Quick Fix File

Use the [hapsigner](../security/hapsigntool-guidelines.md) tool to sign the **entry-default-unsigned.hqf** file, in the same way you sign a HAP file. To be specific, run the following command to use **hap-sign-tool.jar** in the **toolchains** folder in the local OpenHarmony SDK path:

```shell
$ java -jar hap-sign-tool.jar sign-app -keyAlias "OpenHarmony Application Release" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "OpenHarmonyApplication.pem" -profileFile "ohos_provision_release.p7b" -inFile "entry-default-unsigned.hqf" -keystoreFile "OpenHarmony.p12" -outFile "entry-signed-release.hqf" -keyPwd "123456" -keystorePwd "123456"
```

## Installing the Quick Fix File

Push the **entry-signed-release.hqf** file to the device.
```shell
hdc.exe file send .\entry-signed-release.hqf /data/
```

Run the following command to install the quick fix file as a patch:
```shell
$ bm quickfix -a -f /data/entry-signed-release.hqf
```

The complete commands are as follows:
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
