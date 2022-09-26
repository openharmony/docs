# HPM Part开发指导


## HPM Part开发指导概述

通常情况下，[DevEco Marketplace](https://repo.harmonyos.com)中能找到您开发常用的资源，可以通过依赖将所需的资源引入工程中。若现有的资源不能完全满足，可以自己开发并将其以HPM Part的格式发布。安装好hpm-cli工具后，就可以进行Part的开发了。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 下述操作建议在Ubuntu 18.04及以上版本运行。


## 安装HPM命令行工具

在进行HPM Part开发之前，首先需要安装包管理器命令行工具hpm-cli。Hpm-cli是一个基于Node.js开发的跨平台的命令行工具，而要运行hpm命令，需要先安装Node.js，然后使用npm来安装hpm。


### 安装Node.js及hpm-cli

1. 安装Node.js。
   从官网下载并在本地安装Node.js.

   推荐安装[Node.js](https://nodejs.org/)最新的LTS版本 (不低于12.x)。

2. 通过Node.js自带的npm安装hpm-cli命令行工具。执行以下命令：
     
   ```
   npm install -g @ohos/hpm-cli
   ```

3. 安装完成后执行如下命令，显示hpm版本，即安装成功。
     
   ```
   hpm -V  或 hpm --version
   ```

4. （可选）如果需要升级hpm版本，请执行如下命令：
     
   ```
   npm update -g @ohos/hpm-cli
   ```


### 配置hpm-cli（可选）

安装完hpm命令行工具后，如果需要更改配置信息（如代理，shell路径），可执行以下命令可以查看hpm配置：

  
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


## 创建HPM Part

创建HPM Part有以下两种方式，开发者可根据自己的需要选择使用。


### 使用模板创建HPM Part

1. 请执行如下命令创建目录：
     
   ```
   hpm init -t default  mybundle
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > -t后的default表示使用名为'default'模板创建（也可以换作其他的模板，如simple、dist等）

     生成目录结构如下：
     
   ```
   /
   ├── headers            # 头文件（样例）
   │   └── main.h
   └── src                # 源代码（样例）
   │    └─ main.c
   ├── bundle.json        # 元数据声明文件
   └── LICENSE            # 许可协议文本
   └── Makefile           # 编译描述文件（样例）
   └── README.md          # Part的自述文件
   
   ```

2. 接下来根据需要，实现Part内部的功能代码，以及编译脚本。
     
   ```
   hpm init -t {templatename} -d {dir} {name}
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > - -t {templatename} ：指的是模板名称。
   > 
   > - -d {dir}：是要创建的Part所存放的路径。
   > 
   > - name：为要创建的Part名称。

hpm-cli除了提供了少量默认模板之外，其他模板均存储在[DevEco Marketplace](https://repo.harmonyos.com)，可以使用命令hpm search -t template从[DevEco Marketplace](https://repo.harmonyos.com)搜索模板。

![zh-cn_image_0000001217486680](figures/zh-cn_image_0000001217486680.png)


### 将现有工程定义为Part

如果您已经有了代码工程，需要分发的hpm平台，只需要在当前工程目录下（例如mybundle2），执行如下命令，系统会引导您输入组件名称和版本等信息。

  
```
hpm init
```

1. 输入名称后回车（如mybundle2）。

2. 接下来依次输入版本、描述等信息后，会在当前目录下会生成一个bundle.json文件。

3. 也可以打开bundle.json文件。
     
   ```
   $ hpm init
   Your bundle will be created in directory ~\demo\mybundle2
   ? bundle name mybundle2
   ? version 1.0.0
   ...
   Initialization finished.
   ```

4. 打开bundle.json文件修改其他信息（如作者、代码仓库、代码目录、命令脚本、依赖组件等），如下（仅示意）：
     
   ```
   {
   "name": "mybundle2",
   "version": "1.0.0",
   "publishAs": "code-segment",
   "dirs":{
       ".":["README.md"],
       "src":["test.c"],
       "header":["header/test.h" ],    
       "src/common":["src/common/foobar.txt"]
     },
   "scripts": {
       "build": "make -${args}"
     },
   "dependencies": {
       "@ohos/cjson": "^1.0.0",
       "@ohos/foobar": "^1.2.0"
     }
   }
   ```


## 定义发行版

发行版的元数据文件中定义了其依赖的Parts，以及如何编译、链接这些Parts，生成镜像文件的编译脚本。

下方以bundle.json中定义为示例，以下示例的编译命令dist，采用hb编译框架描述。

  
```
{
  "name": "@your/dist_name",
  "version": "2.2.0",
  "publishAs": "distribution",
  "description": "describe it",
  "scripts": {
    "config_hb": "hb set -root $DEP_BUNDLE_BASE",
    "dist": "PATH=/root/.local/bin:${DEP_OHOS_gn}:${DEP_OHOS_ninja}/ninja:${DEP_OHOS_llvm}/llvm/bin:${DEP_OHOS_hc_gen}/hc-gen:${PATH} && ./scripts/dist.sh"
  },
  "envs": {
    "debug": false
  },
  "dirs": {
    "scripts": "scripts/*"
  },
  "dependencies": {
    "@ohos/build_lite": "2.2.0",
    "@ohos/gn": "1.1.1",
    "@ohos/llvm": "1.1.1",
    "@ohos/hc_gen": "1.1.0",
    "@ohos/ninja": "1.1.0",
    ......
  },
  "ohos": {
    "os": "2.2-Beta",
    "board": "hi3516",
    "kernel": "liteos-a"
  },
  "keywords": ["hispark", "hi3516"],
  "repository": "https://gitee.com/openharmony/your-project",
  "license": "Apache V2"
}
```


## 编译构建

完成代码开发后，如果Part的代码是可以独立编译的，可以配置编译工具和脚本以完成二进制的生成。

hpm-cli具备命令集成的能力，开发者可以选择任意的适合项目所采用的语言编译工具（如make，gcc，gn等）。只需在当前项目的bundle.json文件中定义scripts脚本中的build命令，就可以通过执行hpm build执行编译。


### 定义编译脚本

以编译一个app目录下helloworld可执行文件为例：

  
```
app
├── BUILD.gn
├── include
│   └── helloworld.h
└── src
    └── helloworld.c
```

在helloworld.c同级目录下新建一个BUILD.gn

  
```
touch BUILD.gn
vim BUILD.gn
```

以下是BUILD.gn的样例，仅供参考

  
```
executable("hello_world") {
    sources = [
        "src/helloworld.c"
    ]

    include_dirs = [
        "include"
    ]
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - “executable”是gn内置模板，可以用“gn help executable ”查看使用方法。
> 
> - “sources ”是源码路径，“include_dirs ”是头文件路径。


### 执行编译

在当前文件夹下，执行编译命令：

  
```
hpm build
```

在完成一系列的编译动作后，显示build succeed。检查编译的输出结果：

![zh-cn_image_0000001262166533](figures/zh-cn_image_0000001262166533.png)


### 编译image

在当前发行版根目录下，执行如下命令。

  
```
hpm dist
```

hpm-cli工具会自动执行编译，生成镜像文件，如：

  
```
out
|-xxdist.img
|-xx.file
```


## 发布上架

要发布Part到hpm，你需要先具备账号，并创建组织，创建组织的条件及详细步骤请参考[DevEco Marketplace](https://repo.harmonyos.com)上的帮助说明。

完成账号申请和组织创建（或者加入一个现有的组织）后，您需要根据个人的邀请码（在[DevEco Marketplace](https://repo.harmonyos.com)的个人中心页查看），在本机生成公钥，并在[DevEco Marketplace](https://repo.harmonyos.com)的个人中心进行配置。

  
```
hpm config set loginUser {your-invitation-code}
hpm gen-keys
```

生成的文件将会存放在~\Users\yourname\.hpm\key下，将公钥文件(publicKey_your-accout.pem)中内容拷贝到hpm个人中心的SSH公钥中。

完成上述操作后，你就具备了在您的组织内发布Part的权限了。

在Part所在目录，执行命令hpm publish，将会完成组件的打包发布操作。

  
```
hpm publish
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 为避免Part名称冲突，发布的Part的名称需限定在组织范围内，即命名为\@org_name/bundle_name的格式。
> 
> - 你的账号也必须是org_name内的成员，才可以发布或更新组织内的Part。
> 
> - 发布的组件，需要通过安全及内容审核，才能正式生效。


## 使用HPM Part


### 使用Part

通常开发一个项目，需要引用其他的组件以加快特定功能的开发，可以采用安装依赖的方式。

首先去[DevEco Marketplace](https://repo.harmonyos.com)，根据关键字去搜索满足您的需求的组件，找到合适的组件后，将其引入到您的工程。典型的操作步骤包括：

1. 使用hpm init命令创建一个包描述文件（名为bundle.json，包含了依赖和一些其他的元数据，如名称、版本等）。

2. 使用hpm install &lt;name&gt;命令安装依赖（依赖写入bundle.json的dependencies字段）。

3. 代码中共引用头文件，实现功能。

4. 使用hpm build命令执行编译，输出编译结果。

  在您的Part工程中（工程目录中必须包含bundle.json文件）执行如下命令：
  
```
$ hpm install @scope/the_bundle
```

  引用的Part将会被安装到你的工程所在的目录的ohos_bundle下
  
```
project
├── ohos_bundle            
│   └── scope
│    └─ the_bundle     # <---引用的组件将会出现在这
└── src                
│    └─ main.c
├── bundle.json        # 元数据声明文件
└── LICENSE            
└── Makefile           
└── README.md          
```

打开bundle.json文件，可以看到Part已经被引入到您的工程的依赖中。

  
```
{
  "dependencies": {
    "@scope/the_bundle": "^1.0.0"
  }
}
```

您也可以一次性在此文件中编辑多个Part的依赖

  
```
{
  "dependencies": {
    "@scope/the_bundle1": "^1.0.0",
    "@scope/the_bundle2": "^2.0.0",
    "@scope/the_bundle3": "^3.0.0",
    "@scope/the_bundle4": "^1.1.0"
  }
}
```

再执行hpm install命令，将会一次性将所有未安装的Part一次性全部下载并安装完成。


### 安装全局Part

如果引用的Part是多个项目共用的组件（如编译工具链），你可以全局安装

  在您的Part工程中（工程目录中必须包含bundle.json文件）执行如下命令：
  
```
$ hpm install -g @scope/the_tool
```

  引用的Part将会被安装到你在hpm config中设置的globalRepo所指定的目录下：
  
```
~\.hpm\global\ohos_bundles            
│   └── scope
│    └─ the_tool     # <---引用的组件将会出现在这
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 在项目安装的Part，在执行hpm编译命令时可以通过引用环境变量DEP_SCOPE_bundle_name，例如：
>     通过hpm i \@opensource/gn安装后，可以编辑bundle.json中的编译脚本，如下：
>     
>   ```
>   "scripts": {
>       "build": "${DEP_OPENSOURCE_gn}/gn  --version"
>     },
>   ```
> 
>   然后就可以通过执行hpm build将调用gn的功能。
> 
> - 在全局安装的Part，可以通过设置系统环境变量，直接调用，或者hpm config set key value的方式，通过${key}/tool_name的方式引用，例如：
>     
>   ```
>   hpm i -g @ohos/opensource/gn
>   hpm config BUILD_SYS_GN ~/.hpm/global/ohos_bundles/opensource/gn
>   ```
> 
>     可以编辑bundle.json中的编译脚本，如下：
>     
>   ```
>   "scripts": {
>       "build": "${BUILD_SYS_GN}/gn  --version"
>     },
>   ```
> 
>   然后就可以通过执行hpm build将调用gn的功能。
