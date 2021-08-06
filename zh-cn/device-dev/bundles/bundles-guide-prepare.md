# 安装hpm命令行工具<a name="ZH-CN_TOPIC_0000001051770836"></a>

-   [安装](#section14480912380)
-   [配置hpm（可选）](#section138983413013)
-   [下载OpenHarmony代码](#section669905815300)

要进行Bundle的开发，需要安装包管理器hpm（HarmonyOS Package Manager），这是一个基于Node.js开发的跨平台的命令行工具，所以要运行hpm，需要先安装Node.js，然后可以npm 来安装hpm。

## 安装<a name="section14480912380"></a>

1.  安装Node.js。

    从官网下载并在本地安装Node.js.

    推荐安装  [Node.js](https://nodejs.org/)  12.x \(包含 npm 6.14.4\)或更高版本 \(推荐 12.13.0+\)。

2.  通过Node.js自带的npm安装hpm-cli命令行工具。执行以下命令：

    ```
    npm install -g @ohos/hpm-cli
    ```

3.  安装完成后执行如下命令，显示hpm版本，即安装成功。

    ```
    hpm -V  或 hpm --version
    ```

4.  （可选）如果需要升级hpm版本，请执行如下命令：

    ```
    npm update -g @ohos/hpm-cli
    ```


## 配置hpm（可选）<a name="section138983413013"></a>

安装完hpm-cli命令行工具后，如果需要更改配置信息（如代理，shell），执行以下命令可以查看hpm配置：

```
hpm config
```

上述命令执行后将会显示hpm的默认配置，您可以根据自己需要对默认配置进行修改，以下是hpm的常用配置：

```
registry = https://hpm.harmonyos.com
### login Settings
# loginUser = invitation_code

#### Path Settings
shellPath = C:\WINDOWS\System32\cmd.exe
# shellPath = C:\Program Files\Git\bin\sh.exe
# globalRepo = C:\Users\username\.hpm\global

#### Network Settings
# no_proxy = *.server.com
# http_proxy = http://user:pwd@proxy_server:port
# https_proxy = http://user:pwd@proxy_server:port
# strictSsl = true

#### Other Settings
# privateSupport = true|false
# ignoreBundles = @ohos/llvm,@ohos/gn,
# OSPlatform = Auto|linux|darwin|win32
```

hpm-cli的命令介绍可以参考：[hpm操作命令](bundles-guide-overview.md)

## 下载OpenHarmony代码<a name="section669905815300"></a>

参考[《源码获取》](../get-code/sourcecode-acquire.md)。

