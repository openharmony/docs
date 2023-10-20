# 如何编译full-SDK

**full-SDK**是提供OpenHarmony全量接口的SDK，包含了系统应用所需要的高权限API，用于厂商开发应用。

从OpenHarmony3.2Beta5版本开始，不再随版本提供**full-SDK**。如有需要，可通过全量源码自行编译。

## 编译full-SDK

**前提条件**

1. 需注册码云SSH公钥，具体请参考 http://gitee.com/help/articles/4191
2. 配置服务器环境，具体请参考[搭建开发环境](../../device-dev/quick-start/quickstart-ide-env-ubuntu.md)

**下载和编译命令**

1. 初始化manifest：repo init -u https://gitee.com/openharmony/manifest.git -b $manifest_branch --no-repo-verify --repo-url=https://gitee.com/oschina/repo --no-clone-bundle 
2. 根据上面下载的manifest仓进行下载代码：repo sync -c -d --force-sync
3. 预编译：yes y | apt install libxinerama-dev libxcursor-dev libxrandr-dev libxi-dev && rm -rf prebuilts/clang/ohos/darwin-x86_64/clang-480513 && rm -rf prebuilts/clang/ohos/windows-x86_64/clang-480513 && rm -rf prebuilts/clang/ohos/linux-x86_64/clang-480513 && apt-get update -qqy && apt-get install doxygen -y --force-yes
4. 编译windows：./build.sh --product-name ohos-sdk
5. 编译mac：./build.sh --product-name ohos-sdk --gn-args full_mini_debug=false --keep-ninja-going --gn-args=is_use_check_deps=false

编译成功后导出out/sdk/packages/ohos-sdk/目录下的文件即可

## 替换SDK

full-SDK编译完成后需要在DevEcoStudio替换使用，具体请参考[full-SDK替换指南](full-sdk-switch-guide.md)。
