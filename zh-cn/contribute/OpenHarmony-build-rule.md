# 开源构建规范

## 概述

为指导OpenHarmony的开发者开展构建工作，提升构建系统的可重复性、可维护性，提高产品构建质量，构建规范工作组分析总结了各种典型的构建问题，提炼相应的构建规则和建议，制订了本规范。

## 构建总体原则

**P01 构建过程自动化，从构建启动开始到构建最终结束，中间过程不能手工干预。** 
手工操作容易出错，且浪费时间。将所有的构建操作变成自动化的，从而使构建变得高效、可靠。

**P02 构建工程和构建环境代码化。** 
使用高阶构建框架CMake/Maven/Gradle等描述构建工程；使用Ansible/Dockerfile等描述构建环境。
使用高阶构建框架的目的是向构建人员隐藏构建系统的复杂性。

**P03 构建过程可重复、可追溯。** 
管理构建依赖，始终显式指定固定依赖版本号，确保构建依赖版本一致；将构建环境信息/构建工程作为配置项纳入配置管理，确保构建工程可追溯。

**P04 构建脚本简洁清晰，易于维护。** 
构建脚本也是代码，构建脚本首先是为阅读它的人而编写的，好的脚本应当可以像故事一样发声朗诵出来。

**P05 构建标准化** 
构建目录结构、构建依赖、构建初始化、构建入口、命名等进行标准化约束，使得公司所有产品、平台和组件的构建风格一致，便于构建管理和维护。

## 构建工程

### 公共规则

#### 一键式构建

##### G.COM.01 采用构建脚本，按照交付单元实现一键式自动化构建。

一键式自动化构建是指同一个构建环境下，从构建启动开始到最终结束（最终交付的包生成），中间过程禁止人工干预。
人工干预活动包括但不限于：构建过程中，使用IDE界面进行手工设置、创建或者删除文件目录、创建文件、复制文件、移动文件、删除或者重命名文件、手工设置文件属性、压缩/解压缩文件等。
交付单元是指可独立编译、加载、部署和运行的产品/平台/组件。

【级别】要求

【描述】一键式构建大幅降低构建人员操作复杂度。

【错误示例】某组件的一键式构建只能通过CI系统触发，没有一键式的本地构建。

【错误示例】某组件需要在Xplorer IDE界面手工设置内存映射地址后，再手工编译。

【错误示例】某组件需要手工创建r6c03_view\r6c03_client_view目录。

【正确示例】使用python脚本自动化创建目录：

```python
dir_src = os.getcwd()
dir_client_view = r"r6c03_client_view"
# 处理路径使用os.path可以屏蔽系统差异
dir_mk = os.path.join(dir_src, dir_client_view)

cmd = "{0} {1}".format("mkdir", dir_mk)
cmd_re = subprocess.run(cmd)
```

#### 构建目录

##### G.COM.02 构建过程中禁止删除或修改源代码文件及其目录结构。

【级别】禁止

【描述】

- 构建过程中删除或修改源代码目录结构，会导致构建过程不可重复。

- 构建过程中，构建输出（包括目标文件、临时文件和构建日志）不能污染源码目录；

- 构建过程中，避免修改源文件，包括但不限于拷贝、移动、执行dos2unix进行了源代码的格式转换等，源文件的修改应该在构建前的代码准备阶段完成；

- 工具自动生成源代码应该在构建前的准备阶段完成，如果构建过程中使用工具自动生成源代码，工具自动生成的源代码必须和已有源代码目录隔离，以便区分高价值的源代码和低价值的可重新生成的代码，降低构建系统的复杂性。

【例外】构建补丁时，可能会新增或调整部分源代码。

##### G.COM.12 构建过程中创建的文件和目录应提供合适的权限。

【级别】要求

【描述】构建过程中可能需要创建目标系统的目录或文件，这些目录和文件应符合权限最小化的设计。
例如，构建过程中应尽量避免在Linux系统中创建“777”权限的目录或文件。

Linux系统中常见的目录文件和权限可以参考《Linux安全配置操作规范》。

#### 构建初始化

##### G.COM.03 每个组件提供clean命令。

- 当clean不带任何参数时，清除该层级构建工程下的所有目标文件、临时文件和构建日志，并递归调用下层构建工程的clean，使该构建工程恢复到初始状态；
- 当clean带参数时，只清除与之对应的构建生成的目标文件、临时文件和构建日志。

【级别】要求

【描述】构建前进行clean是为了避免本次构建受到历史构建残留文件和构建日志的影响，确保构建可重复。必须支持不带任何参数clean；带参数的clean，是为了满足日常交付过程和开发人员本地构建的诉求，不作强制要求。

【正确示例】

```
base_dir
 |---build.suffix
 |---logs
 |---component_depository_1
    |---build.suffix
    |---logs
 |---component_depository_2
    |---build.suffix
    |---logs

#不带参数
base_dir/build.suffix clean
#....分别调用component_depository_1和component_depository_2的clean

#带参数：组件名
base_dir/build.suffix clean component_depository_1
#....调用component_depository_1的clean

#带参数 
component_depository_1/build.suffix clean makebin hert umpt
#....调用component_depository_1的umpt单板链接任务的clean，支持详细参数的clean主要应用于内部开发和构建。
```

##### G.COM.04 每个组件发布构建，必须保证构建环境中没有历史构建遗留件。

【级别】要求

【描述】首次下载代码，构建环境已经初始化，构建环境本身确保没有历史构建遗留件，可以不用执行clean命令；如果执行过构建的，必须使用clean命令清除历史构建遗留件。

#### 全量构建

##### G.COM.05 对于版本发布构建，归档的产品全量交付件（含所依赖的所有平台和组件）必须全部重新编译，禁止使用增量编译，禁止使用手工替换文件等方式修改安装盘。

版本发布构建是指产品（含所依赖的所有平台和组件）对外正式发布版本的构建。

【级别】要求

【描述】修改文件后增量编译，会导致部分二进制文件没有更新，造成新的安全编译选项未集成到版本，编译结果不一致。手工替换文件可能会造成构建不可重复、不一致。


#### 构建配置

构建配置数据和构建脚本分离，避免构建工程架构腐化。源码路径、编译选项、目标文件路径等配置与构建脚本放到不同的文件，降低构建脚本维护成本。

##### G.COM.06 禁止使用与操作系统强绑定的文件（如excel）作为构建配置文件。建议使用跨平台的标准配置文件（如XML）来存放配置选项。

【级别】要求

【描述】使用excel作为配置文件带来的问题：

- 产品和平台编译过程中，使用excel作为配置文件，都将调用微软的OfficeAPI，每次访问excel表格都会在后台打开excel，处理速度慢。

- 大量的excel配置需要手动点界面进行操作，可管理性差。

#### 构建日志

##### G.COM.07 构建输出的日志简洁明晰，构建日志的格式为时间戳+模块名（可选）+日志信息等级+日志内容。
【级别】要求

【描述】建议时间戳格式采取“日期和时间”，如"MM/dd/yyyy HH:mm:ss"。

日志信息等级分为error/warning/informational，级别可以全写，也可以简写；对应的简写为：

| 级别（大小写都可以）| 简写（大小写都可以）|
| :---------: | :--------------------------: |
| error | ERROR |
| warning | WARN |
| information | INFO |

建议使用“[]”作分隔符。

【正确示例】
[05/21/2020 00:12:40] [ERROR] mkdir: cannot create directory Permission denied.

【例外】整个日志由工具自动输出的，可用使用以下方式跳过整个日志文件：在日志的最前方（尽可能靠前）输出"This project is built using "+工具名，如"This project is built using CMake."。

##### G.COM.08 构建日志出现error信息表示构建失败，必须终止构建。

【级别】要求

【描述】出现error信息一般是需要人工干预的构建错误，例如配置的环境变量错误，工具的版本错误，操作系统错误等等；或者软件源代码不对。对于版本发布构建，必须消除构建过程中所有的error消息，不允许屏蔽构建error信息。

【错误示例】某组件构建成功，但构建日志中包含大量的fail、Critical、cannot、not found、missing、no input files等异常信息，令人困惑。

##### G.COM.09 构建日志文件只保留本次构建的日志，避免本次构建的日志与历史构建的日志混淆。

【级别】要求

【描述】构建日志文件保留历史构建日志会导致混淆错误，比如：最新构建是失败的，由于保留有历史成功构建日志，会误认为最新这次构建是成功的。

##### G.COM.10 每条日志建议增加对应的模块名，用于问题的快速定界。

【级别】建议

【描述】在日志量较大时，很难快速锁定问题责任模块，需要在日志上加以区分。

【例外】CMake等工具的原生日志，因为输出带有对应模块路径，可以界定问题边界，不用特殊增加模块名维测信息。

#### 构建用户

##### G.COM.11 禁止使用超级管理员用户root和系统用户执行构建，应该使用普通user账户执行构建。

【级别】要求

【描述】超级管理员用户root和系统用户具有比较高的系统权限，使用此类账户执行构建可能导致构建环境被篡改。

安装态可以使用root用户；执行态使用普通user账户，如果需要使用sudo提升权限的，请遵守《身份和访问管理安全设计规范》。

#### 构建输出文件

##### G.COM.12 构建输出文件命名后缀遵守业界约定。

【级别】要求

【描述】错误的后缀命名令人误解。

对lib库、obj等构建输出文件的文件缀，应遵从构建工具默认的命名规则。

【错误示例】某文本文件命名为XXX.lib。

【错误示例】某object文件命名为XXX.a。

【错误示例】某静态库命名无后缀，命名为libxxx。

【正确示例】业界如下网址可以查询常见的文件后缀命名约定：http://www.fileextension.org/ ,  https://fileinfo.com/ , https://www.file-extensions.org/, http://file-extension.net/ 。 

下面是一些常见的文件后缀的命名约定：

| 文件后缀名 | 类型约定             | 文件后缀名 | 类型约定        |
| ---------- | -------------------- | ---------- | --------------- |
| .a         | 静态库               | .so        | 动态库          |
| .o         | object文件           | .7z        | 7zip压缩文件    |
| .tar       | tar存档文件          | .gz/.gzip  | GNU压缩存档文件 |
| .pack      | java pack200压缩文件 | .rar/.rar5 | rar压缩包       |

### C/C++构建工程

#### 构建目录

##### G.C&C++.01 构建目录结构标准化。

构建目录按用途分为源树Source Tree、构建中间件树Build Tree、构建安装树Install Tree三种。

- Source Tree是保存源码和构建脚本的目录。
- Build Tree是保存构建中间件的目录，目录名称一般为"build"。
- Install Tree是保存构建发布件的目录，目录名称固定为"output"。

Source Tree、Build Tree和Install Tree目录隔离，互相不重叠，没有交集，即不允许一个目录同时承担两种及以上的用途，譬如一个目录既作为Source Tree存放源码，又作为Build Tree存放编译中间件，这是不允许的。

Source Tree包含下列文件和目录：

- 构建工具入口文件，如CMakeLists.txt，CMakeLists.txt中通过add_subdirectory()命令添加子目录，CMake将自动迭代调用子目录中的CMakeLists.txt，并逐级向下展开。
- build.suffix脚本文件，该文件是一键式构建入口，仅调用该脚本即可完成构建。".suffix"表示对应的构建脚本语言后缀，譬如".bat",".sh",".py"等。
- config.suffix配置文件，该文件用于存放构建配置项，是唯一的配置文件入口。
- 构建脚本目录，可选，如cmake目录，用于保存CMake脚本文件。CMake脚本文件包括宏、函数、toolchain等, CMakeLists.txt通过include()命令包含CMake脚本文件，并调用其中的宏、函数等。
- 组件代码目录，用于存放各组件的源码及构建脚本。
- 上述文件和目录，只有CMakeLists.txt、build.suffix、config.suffix这三个文件是必需的，其它文件或者目录仅用作示例，不强制要求。

Build Tree包含下列目录：

- build目录，用于存放构建中间件。该目录可能在构建过程中创建，在git库上可能没有该目录。
- 有的工程已经将build目录用于保存构建脚本，可以创建别的目录作为Build Tree。

Install Tree包含下列目录：

- output目录，用于存放交付件。该目录可能在构建过程中创建，在git库上可能没有该目录。

【级别】要求

【描述】

典型目录结构如下：

```
base_dir
 |---CMakeLists.txt      ---|
 |---build.suffix           |
 |---config.suffix          |
 |---cmake                  |--> Source Tree
 |---component_1            |
 |---component_2            |
 |---......                 |
 |---component_n         ---|
 |---build               ------> Build Tree
 |---output              ------> Install Tree
```

各组件的目录结构与顶层的目录结构类似，譬如：

```
component_1
 |---CMakeLists.txt      ---|
 |---build.suffix           |
 |---config.suffix          |
 |---cmake                  |--> Source Tree
 |---module_1               |
 |---module_2               |
 |---......                 |
 |---module_n            ---|
 |---build               ------> Build Tree
 |---output              ------> Install Tree
```

##### G.C&C++.02 构建过程中禁止以任何形式修改Source Tree。

【级别】建议

【描述】构建过程中修改Source Tree会导致构建过程不可重复。

常见的修改Source Tree的操作有：
1）打补丁
2）打点
3）裁剪
4）自动生成源码
5）先修改源码然后还原
6）增加/修改/删除临时文件或者目录
7）修改文件/目录属性或者格式，譬如修改文件可执行权限、dos2unix等

建议解决方案如下：
1）将代码拷贝到Build Tree，然后打补丁，编译。
2）打点工具修改源码，使得构建过程不可信，因此禁止在构建过程中使用打点工具。应将打点后的代码上传到代码库，使用打点后的代码进行构建。
3）裁剪是独立的源码交付需求，裁剪可以看做是代码准备阶段。裁剪前的版本和裁剪后的版本都必须满足在构建过程中不修改Source Tree。
4）自动生成的源码应放在Build Tree下。
5）先修改源码然后还原是掩耳盗铃，构建过程中源码已经发生了变更。
6）临时文件或者目录都应该放在Build Tree下。
7）必须保证代码库中的文件属性和格式是正确的，而不是构建时修改。

检验Source Tree是否发生变化的方法之一：编译完成后在源码目录下执行git status命令，不能有任何变更。先修改后还原导致的Source Tree变更，通过git status可能检测不出来。

【例外】
1）git status检测到Build Tree和Install Tree这两个目录的变更是允许的。
2）git status检测到由于裁剪导致的变更是允许的。

##### G.C&C++.03 Windows构建根目录建议为D:\交付单元的名称+版本号（可选）；Linux构建根目录建议为/usr1/交付单元的名称+版本号（可选）。

【级别】建议

【描述】构建根目录按交付单元的名称+版本号命名，禁止使用build或code等无法区分交付单元的目录名称。
清晰的构建目录结构，便于测试人员配置构建参数、执行一键式构建入口和对比构建结果。
根目录示例如下：

```
D:\Offering [Version，可选]或/usr1/Offering [Version，可选]
```

##### G.C&C++.04 构建过程中生成的所有中间件保存在Build Tree中。

【级别】要求

【描述】构建过程中产生的中间件包括构建工具CMake自动生成的makefile、构建脚本自动生成的源码、构建脚本拷贝的源码及补丁、编译产生的object文件、库文件、可执行程序、构建日志等等。如果中间件放在Build Tree以外的目录，势必污染Source Tree或者Install Tree。因此，所有中间件都要保存在Build Tree中。Build Tree仅用于保存构建中间件，不能将Source Tree下某个放置源码或者构建脚本的目录用作Build Tree。
Build Tree下创建构建日志子目录logs，构建日志后缀文件命名为.log。

##### G.C&C++.05 支持指定Source Tree和Install Tree以外的任意目录作为Build Tree。

【级别】要求

【描述】支持指定Source Tree和Install Tree以外的任意目录作为Build Tree，做到构建过程与目录无关。在哪个目录下执行构建，哪个目录就是Build Tree，编译中间件就保存在哪个目录下。Build Tree的目录名称一般为“build”，也可以使用其它名称。

【正确示例】使用CMake系统变量CMAKE_BINARY_DIR和CMAKE_CURRENT_BINARY_DIR访问Build Tree，避免Build Tree与Source Tree产生耦合。

##### G.C&C++.06 所有发布件保存在Install Tree中。

【级别】要求

【描述】本地编译场景下，发布件直接"install"到HOST Computer上并运行。交叉编译场景下，发布件并不在HOST Computer上运行，而是在TARGET Computer上运行。

发布件包括库文件、可执行程序、包文件、头文件等，是组件对外的二进制接口。所有发布件都保存在Install Tree中，不应将发布件放在Install Tree以外的目录下。

Install Tree只用于保存发布件，不应将编译中间件放在Install Tree中。

##### G.C&C++.07 支持指定Source Tree和Build Tree以外的任意目录作为Install Tree。

【级别】要求

【描述】支持指定Source Tree和Build Tree以外的任意目录作为Install Tree，做到构建过程与目录无关。Install Tree的目录名称固定为“output”。

【正确示例】CMake构建工程应支持通过系统变量CMAKE_INSTALL_PREFIX指定Install Tree的根目录。

#### 构建入口

##### G.C&C++.08 每个交付单元的构建入口单一。构建脚本入口名称统一命名为build.suffix，并且路径要求在构建根目录下。

【级别】要求

【描述】通过使用一致的构建入口点，构建过程可以变得更加高效和可自动执行。每个交付单元只有单一构建入口，便于一键式自动构建。

【错误示例】如下构建有多个入口点，如果没有说明文档，无法确认哪一个入口是正确的，造成选择困难。
build.bat 
build_all.sh 
build_v6.sh 

【正确示例】一键式构建脚本build.sh的典型写法如下：

```bash
#!/bin/bash

if [ -d "build" ]; then
    rm -fr build/*
else
    mkdir build
fi

if [ -d "output" ]; then
    rm -fr output/*
else
    mkdir output
fi

cd build
cmake ..

cpu_processor_num=$(grep processor /proc/cpuinfo | wc -l)
job_num=$(expr "$cpu_processor_num" \* 2)
echo Parallel job num is "$job_num"
make -j"$job_num"
```

##### G.C&C++.09 支持指定target进行构建。

【级别】要求

【描述】日常开发场景下，通过指定target编译，开发人员只需要编译修改了的代码，不需要编译全部代码，达到快速验证的目的。编译工程应支持指定target进行构建，从而满足灵活多变的编译调试需求。

【正确示例】典型命令如下：

```
base_dir # cd build
base_dir/build # cmake ..
# 编译全部目标
base_dir/build # make
# 编译特定目标
base_dir/build # make target_name
```

##### G.C&C++.10 支持重复编译。

【级别】要求

【描述】编译成功后，不对源代码做任何修改，不清理上次编译的中间件和发布件，不修改编译环境，再次执行编译，必须能重复编译成功。

##### G.C&C++.11 支持增量编译。

【级别】建议

【描述】日常开发场景下，增量编译可以缩短编译时间，提高开发效率，因此建议支持增量编译。

##### G.C&C++.12 支持并行编译。

【级别】要求

【描述】通过"make -jN"命令进行并行编译，可以提高编译速度。本规则仅适用于使用make工具的工程。

支持jobserver统一调度，使整个工程的负载最优。不能出现下面两个告警：

```
warning: jobserver unavailable: using -j1.  Add '+' to parent make rule.
warning: -jN forced in submake: disabling jobserver mode.
```

支持jobserver的方法如下：

1. 通过$(MAKE)直接调用make命令

    ```cmake
    ExternalProject_Add(foo
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
        CONFIGURE_COMMAND sh configure_ext.sh
        BUILD_COMMAND $(MAKE)
    )
    ```

2. 通过shell脚本调用make命令

    ```cmake
    ExternalProject_Add(foo
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
        CONFIGURE_COMMAND sh configure_ext.sh
        BUILD_COMMAND sh build_ext.sh $(MAKE)
    )
    ```

   build_ext.sh内容如下：

    ```bash
    #!/bin/bash

    make
    ```

   注意：build_ext.sh不需要解析和使用参数$(MAKE)。

3. 通过python脚本调用make命令

    ```cmake
    ExternalProject_Add(foo
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
        CONFIGURE_COMMAND sh configure_ext.sh
        BUILD_COMMAND python build_ext.py $(MAKE)
    )
    ```

   build_ext.py内容如下：

    ```bash
    #!/usr/bin/python
    # -*- coding: UTF-8 -*-

    import subprocess

    def main():
        child = subprocess.Popen("make", close_fds=False)
        ret = child.wait()
        return
            
    if __name__ == '__main__':
        main()
    ```

    注意：build_ext.py不需要解析和使用参数$(MAKE)。


#### 构建依赖

##### G.C&C++.13 定义一个构建依赖文件dependence.xml，文件中描述构建依赖的所有组件。构建脚本自动读取该依赖文件，用于制作最终的软件包。

【级别】建议

【描述】按照依赖文件进行软件包制作，避免在构建脚本中定义依赖组件，提高构建过程可维护性。

#### 构建配置

##### G.C&C++.14 构建根目录的config.suffix配置文件是整个交付项目唯一的配置入口。

【级别】要求

【描述】顶层的config.suffix中，应暴露最少的配置项，只需要用户配置的构建环境、构建工具相关的信息。

【例外】如果构建配置的内容非常少，采取系统键值对配置项，配置文件可以命名成config.conf。

### GN 编写规范

#### 编译规范

##### 规则1.1 禁止在gn中调用外部编译工具编译软件模块

【级别】禁止

【描述】需要将外部组件移植成gn的编译形式，避免编译过程对环境产生不必要的依赖，而且可获得编译框架提供的公共能力，包括不限于：安全编译选项，ASAN等。

【反例】在gn中使用action调用automake和Make来编译三方组件。

【例外】Linux Kernel 编译框架实际完成的用户态程序编译，内核完全可以在编译框架之外完成独立编译。某些平台实现为了实现一键编译，使用gn将内核编译加在编译过程中，是可以接受的。

##### 规则1.2 禁止在模块的gn文件中，再次添加编译系统已经添加的安全编译选项

【级别】禁止

【描述】对于全局已经添加的默认选项，模块开发者应当知晓，不需要为了满足内外部规则再次添加。

| 编译选项 | 编译参数    | 默认值     |
|---------|------------|------------|
| 栈保护   | -fstack-protector-strong| 开 |
| Fortify Source | -D_FORTIFY_SOURCE=2 -O2	| 开 |

【反例】在模块的编译添加 -fstack-protector-strong

##### 规则1.3 禁止在gn中添加和默认编译选项相反的编译选项

【级别】禁止

【描述】默认的编译选项代表了系统的默认能力，自研模块有特殊情况需要去掉部分能力，必须有足有的理由。

【反例】在自研模块中添加 -wno-unused 以消除编译告警。

【例外】移植三方组件，或者使用因为三方组件时，可根据三方组件的要求覆盖默认的编译选项。

##### 规则 2.1 使用gn format 对添加或者修改的gn文件进行格式化，满足格式和排版的需求

【级别】要求

##### 规则 2.2 编写action时，使用python而不是shell

【级别】建议

【描述】python 环境更容易保持统一，可以比较容易的多重操作系统上运行，并且扩展性可读性可测试更好。

##### 规则 2.3 禁止在gn和ninja执行过程修改源码目录的内容

【级别】禁止

【描述】包括但不限于给源码目录打patch，向源码目录中拷贝，在源码目录中执行编译，在源码目录生成中间文件等。

##### 规则 2.4 编译脚本的编码格式设置为utf-8，换行符设置为unix格式

【级别】要求

【反例】在windows上编写脚本后，使用了中文注释并保存为本地编码。

