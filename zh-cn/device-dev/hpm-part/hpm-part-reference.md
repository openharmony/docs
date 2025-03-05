# HPM Part参考


本文档将介绍HPM的Part的构成，包类型、划分原则、元数据字段以及相关命令行工具的常用命令等。


### Part划分原则

原则上应尽可能划分为细颗粒度的Part，以满足最大限度的复用。主要考虑以下几点：

- 独立性：Part的功能应该相对独立，支持独立编译，可以单独对外提供接口和服务。

- 耦合性：如果Part必须依赖其他的Part，才能对外提供服务，应考虑和被依赖的Part合并为一个Part。

- 相关性：如果一组Part共同完成一项功能，且没有被其他Part依赖，未来也没有被依赖的可能，则可以考虑合并为一个Part。


### Part类型

Part是为复用而生，一切可以复用的部件都可以定义为Part，可以分为：

  **表1** HPM Part分类

| 部件 | 说明 | 
| -------- | -------- |
| source | 以源码形式分发，被目标工程依赖、可独立编译。 | 
| binary | 以二进制形式分发，不包含源代码，例如编译工具。 | 
| code-segment | 以代码片段形式分发，无法独立编译，安装后还原到指定目录，在目标工程参与其他代码编译。 | 
| distribution | 以发行版形式分发，依赖其他Part，不包含源码（编译脚本除外），编译输出为系统镜像。 | 
| template | 以模板形态分发，用于hpm&nbsp;init创建模板。 | 
| plugin | 以插件形态分发，作为hpm&nbsp;cli的插件，扩展hpm&nbsp;cli的功能。 | 


### Part构成

一个Part包一般包含如下内容：

- Part包的代码或库（src目录下的代码文件）

- ohos_bundles文件夹（存放依赖的Part，安装Part时自动生成，无需提交到代码库）

- Part包的说明文件(README.md)

- Part包元数据声明文件(bundle.json)

- 开源许可文件(LICENSE)
    
  ```
  my-bundle
     |_ohos_bundles
     |_headers
     |_src
     |_bundle.json
     |_README.md
     |_LICENSE
  ```


### src源代码

Part的代码文件和普通的代码目录没有差异。但要注意的是，Part中对外暴露的接口（头文件），会被其他Part所引用，需要单独在bundle.json的dirs中声明。


### README文件

为了帮助他人在[DevEco Marketplace](https://repo.harmonyos.com)上找到该Part，并更方便的使用它，在Part的根目录中包含一个README文件。

README.md，为markdown格式的描述关于Part自述说明文件。

README文件应包括如何安装，配置和使用Part包中的实例代码说明，以及可能会对用户有所帮助的任何其他信息。

自述文件将显示在[DevEco Marketplace](https://repo.harmonyos.com)的Part的详情页面中。


## bundle.json文件

bundle.json文件是对当前Part的元数据描述，每个Part中必须包含一个bundle.json文件。主要内容如下：

  
```
{
  "name": "@myorg/demo-bundle",
  "version": "1.0.0",
  "license": "MIT",
  "description": "bundle description",
  "keywords": ["hos"],
  "tags": ["applications", "drivers"],
  "author": {"name":"","email":"","url":""},
  "contributors":[{"name":"","email":"","url":""},{"name":"","email":"","url":""}],
  "homepage": "http://www.foo.bar.com",
  "repository": "https://git@gitee.com:foo/bar.git",
  "private": false,
  "publishAs": "code-segment",
  "segment":{
     "destPath":"/the/dest/path"
  },
  "dirs": {
    "src": ["src/**/*.c"],
    "headers": ["headers/**/*.h"],
    "bin": ["bin/**/*.o"]
  },
  "scripts": {
    "build": "make"
  },
  "envs": {},
  "ohos": {
    "os": "2.0.0",
    "board": "hi3516",
    "kernel": "liteos-a"
  },
 "rom": "10240",
 "ram": "1024",
 "dependencies": {
    "@myorg/net":"1.0.0"
 }
}
```

bundle.json文件具有如下功能：

- name：定义Part的名称，放到组织下， 以\@开头，/分割，如：\@myorg/mybundle

- version：定义Part版本号，如1.0.0，需满足semver的标准。

- description：一句话对Part进行简要的描述。

- dependencies：定义Part的依赖Part。

- envs： 定义Part编译时所需要的参数，包括全局参数以及依赖所需的参数。

- scripts：定义在当前Part下能够执行的命令（如编译，构建，测试，烧录等）。

- publishAs：定义Part的发布类型（source：源码，binary：二进制，distribution：发行版，code-segment：代码片段）。

- segment: 仅针对code-segment类型的Part，定义Part的目标路径（即安装后，Part包中包含的文件复制到的目标路径）

- dirs：定义发布时打包的目录结构（如头文件）。

- ram&amp;rom：统计相关信息：预计占用ROM和RAM信息。

- ohos：描述OpenHarmony操作系统版本、开发板及内核的匹配关系（多个请用英文逗号的“,”分割）。

- 定义其他扩展信息：作者，主页，代码仓库，许可协议，标签，关键字。

- 对于发行版类型，可以定义继承关系，用base字段描述继承自的基础发行版及版本。

- private:定义是否为私有包，私有包在公共的注册中心中无法被其他用户搜索到，默认为false（只有组织的类型为）。


## HPM CLI命令

Part的全生命周期管理，可以通过hpm命令工具进行操作，hpm的操作命令如下（详细帮助可以执行hpm -h学习）：

  **表2** hpm操作命令

| 命令类别 | 命令行 | 含义说明 | 
| -------- | -------- | -------- |
| 版本查询 | hpm&nbsp;-V或hpm&nbsp;--version | 查看hpm-cli版本号。 | 
| 帮助查询 | hpm&nbsp;-h或hpm&nbsp;--version | 查看命令列表及帮助。 | 
|| hpm&nbsp;-h | 查看命令帮助。 | 
| 创建 | hpm&nbsp;init&nbsp;bundle | 创建Part工程。 | 
|| hpm&nbsp;init&nbsp;-t&nbsp;template | 根据模板创建脚手架工程。 | 
| 安装 | hpm&nbsp;install或hpm&nbsp;i | 安装bundle.json中依赖的Part。 | 
|| hpm&nbsp;install&nbsp;bundle\@version | 安装指定Part版本。 | 
| 卸载 | hpm&nbsp;uninstall&nbsp;bundle | 删除depedencies依赖的Part。 | 
|| hpm&nbsp;remove或hpm&nbsp;rm&nbsp;bundlename | 删除depedencies依赖的Part。 | 
| 查看 | hpm&nbsp;list或者hpm&nbsp;ls | 显示当前HPM&nbsp;Part的依赖树。 | 
|| hpm&nbsp;dependencies | 生成当前HPM&nbsp;Part依赖关系数据（在hpm&nbsp;ui也集成了该命令的调用，可以图形化的展示）。 | 
| 搜索 | hpm&nbsp;search&nbsp;name | 搜索Bundle，--json，可以以json格式输出&nbsp;-type&nbsp;可以设置搜索Bundle的类型，包括part、distribution、code-segment三种。 | 
| 设置hpm配置项 | hpm&nbsp;config&nbsp;set&nbsp;key&nbsp;value | 设置配置值，如服务器地址，网络代理。 | 
|| hpm&nbsp;config&nbsp;delete&nbsp;key | 删除配置。 | 
| 更新 | hpm&nbsp;update | 更新当前Part依赖的Part的版本。 | 
|| hpm&nbsp;check-update | 检查依赖的Part版本是否有更新。 | 
| 编译 | hpm&nbsp;build | 编译HPM&nbsp;Part。 | 
|| hpm&nbsp;dist | 针对发行版（distribution），发行版编译构建（依赖bundle.json的scripts中的dist脚本）。 | 
| 打包 | hpm&nbsp;pack | 本地Part打包依赖。 | 
| 烧录 | hpm&nbsp;run&nbsp;flash | 烧录固件（依赖bundle.json的scripts中的flash脚本）。 | 
| 发布 | hpm&nbsp;publish | 发布Part，发布的Part在仓库中必须唯一，且版本唯一（需要账号登录）。 | 
| 执行扩展命令 | hpm&nbsp;run | 执行bundle.json文件中定义的scripts脚本命令，支持多个命令可用&nbsp;&amp;&amp;&nbsp;连接。 | 
| 解压包 | hpm&nbsp;extract | 解压文件，支持格式'zip'、'tar','tgz'&nbsp;和'.tar.gz'。 | 
| 启动图形化界面 | hpm&nbsp;ui | 本地启动HPM&nbsp;UI，可通过-p参数指定端口，Windows平台下会启动默认的浏览器打开。 | 
| 多语言切换 | hpm&nbsp;lang | 切换中英文操作界面（同时支持命令行和UI）。 | 
| 转换为hpm包格式 | hpm&nbsp;x2h | 将一个maven格式或npm格式包转换成hpm的包格式，并发布到HPM。 | 
| 代码段还原或清理 | hpm&nbsp;code&nbsp;clean\|restore | 针对依赖的代码段(code-segment)Part，执行清理或还原操作（即根据segment.destPath执行拷贝/删除操作）。 | 
| 生成秘钥 | hpm&nbsp;gen-keys | 生成公钥/私钥对，将公钥配置到[DevEco&nbsp;Marketplace](https://repo.harmonyos.com)，可以实现hpm-cli免密登录，发布Part。 | 
| 生成第三方开源说明 | hpm&nbsp;gen-notice | 根据每个Part的说明，生成一份合并后的第三方开源说明的合并文件。 | 


## 关于依赖

Part的依赖分为必选依赖和可选依赖。

- 必选依赖：是指Part A在完成某个功能时，必须引入Part B，调用B的接口或服务配合才能完成。称B为A的必选依赖。

- 可选依赖：是在Part A在完成某个功能时，可以引入Part C，也可以引入Part D。C和D可以相互替换，称C和D为A的可选依赖。

  
```
"dependencies": {
    "@myorg/core":"1.0.0",
    "?@myorg/plugin1":"1.0.0",
    "?@myorg/plugin2":"1.1.0"
 }
```

Part的依赖关系分为编译依赖和开发依赖。

- 编译依赖：运行时需要的依赖。

- 开发依赖：非运行时需要的依赖，如静态检查、编译、打包、测试、格式化工具等。

  
```
"dependencies": {
    "@myorg/core":"1.0.0"
 },
"devDependencies": {
    "@myorg/tool":"1.0.0"
 }
```

  依赖中可以定义标签，对引入的依赖进行分组。在脚本中可以根据标签，获得这一组依赖的路径。定义的标签以\#开头，具体定义的方式为：
  
```
{
    "dependencies": {
        "#tool": {
            "first_bundle": "1.0.0",
            "second_bundle": "1.0.0"
        },
        "#drivers": {
            "xx_bundle": "1.0.0",
            "yy_bundle": "1.0.0"
        }
    }
}
```

Part的依赖关系（包括间接依赖）可以通过hpm list命令显示（也可以通过hpm ui命令在可视化的页面中显示）

  
```
$ hpm list
+--demo@1.0.0
| +--@example/media@1.0.2
| +--@demo/sport_hi3518ev300_liteos_a@1.0.0
| | +--@demo/app@4.0.1
| | | +--@demo/build@4.0.1
| | | +--@demo/arm_harmonyeabi_gcc@4.0.0   
| | +--@demo/liteos_a@4.0.0
| | | +--@demo/third_party_fatfs@4.0.0     
| | | +--@demo/arm_harmonyeabi_gcc@4.0.0   
| | +--@demo/init@4.0.0
| | +--@demo/dist_tools@4.0.0
```


## 关于环境变量

Part在编译的过程中需要依赖系统提供的环境变量来自定义输出，链接所需二进制文件等。

这里提出的环境变量均指根据需求把所需变量注入脚本执行的上下文中。

所以在脚本中可以直接获取到变量的值。下面介绍当前系统存在的几种环境变量。

**内置环境变量**：

- DEP_OHOS_BUNDLES：表示ohos_bundles文件夹所在的路径。

- DEP_BUNDLE_BASE：表示最外层Part的路径。

**全局环境变量**

全局环境变量由bundle.json中的envs属性来定义。整个Part中的依赖都可以获取到全局变量定义的值。

  
```
{
    "envs": {
        "compileEnv": "arm"
    }
}
```

不同Part在引入依赖的过程中可以传入不同的参数，从而使依赖的编译可以满足当前Part的需求。依赖中定义的参数可以在对应依赖脚本执行的上下文中获取到。

  
```
{
    "dependencies": {
        "my-bundle": {
            "version": "1.0.0",
            "mode": "debug"
        }
    }
}
```

Part在链接二进制文件的时候，需要知道二进制文件在依赖中的路径，所以依赖的路径会作为环境变量传入编译Part中。

传入的环境变量的格式为DEP_BundleName，BundleName为依赖的名称，例如DEP_first_bundle。


## 关于命名和版本号

1. 名称需要为全小写的英文字母或数字，中间可以使用下划线分隔。如 "bundle"、 "my_bundle"、"json2"。

2. 发布到[DevEco Marketplace](https://repo.harmonyos.com)的Part的名称，需要以\@开头，通过组织名用/隔离， 如\@my_org/part_name

3. 组织名+Part名称，需要是唯一的，且不容易和其他作者的Part名称混淆。

4. 名称应该是容易理解，而非无意义的字母组合。

5. 版本号应该遵循语义化命令格式：即 "主版本号.次版本号.修订号" 或 "主版本号.次版本号.修订号-先行版本号"，比如 "1.0.0"， "1.0.0-beta"，详细规格可以参考 [https://semver.org](https://semver.org/)。
