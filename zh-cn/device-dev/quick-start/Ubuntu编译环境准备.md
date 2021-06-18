# Ubuntu编译环境准备<a name="ZH-CN_TOPIC_0000001105407498"></a>

-   [获取软件](#section1897711811517)
-   [获取源码](#section1545225464016)
-   [安装和配置Python](#section1238412211211)
-   [安装gn](#section29216201423)
-   [安装ninja](#section8762358731)
-   [安装LLVM](#section12202192215415)
-   [安装hb](#section15794154618411)
    -   [前提条件](#section1083283711515)
    -   [安装方法](#section11518484814)
    -   [卸载方法](#section3512551574)


系统要求：Ubuntu16.04及以上64位系统版本。

编译环境搭建分为如下几步：

1.  获取源码
2.  安装和配置python
3.  安装gn
4.  安装ninja
5.  安装LLVM
6.  安装hb

>![](public_sys-resources/icon-notice.gif) **须知：** 
>-   针对Ubuntu编译环境我们提供了对应的Docker，该Docker封装了相关编译工具，选择使用Docker的开发者可跳过此章节。Docker使用可参考[Docker方式获取编译环境](../get-code/获取工具.md)。
>-   通常系统默认安装samba、vim等常用软件，需要做适当适配以支持Linux服务器与Windows工作台之间的文件共享。
>-   想要详细了解OpenHarmony编译构建模块功能的开发者可参考[编译构建使用指南](../subsystems/编译构建概述.md)。

## 获取软件<a name="section1897711811517"></a>

Linux服务器通用环境配置需要的工具及其获取途径如下表所示：

**表 1**  Linux服务器开发工具及获取途径

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="13.350000000000001%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>开发工具</p>
</th>
<th class="cellrowborder" valign="top" width="24.65%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>用途</p>
</th>
<th class="cellrowborder" valign="top" width="62%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>获取途径</p>
</th>
</tr>
</thead>
<tbody><tr id="row45863354112"><td class="cellrowborder" valign="top" width="13.350000000000001%" headers="mcps1.2.4.1.1 "><p id="p3587173513117"><a name="p3587173513117"></a><a name="p3587173513117"></a>源码</p>
</td>
<td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.4.1.2 "><p id="p258713581118"><a name="p258713581118"></a><a name="p258713581118"></a>功能开发</p>
</td>
<td class="cellrowborder" valign="top" width="62%" headers="mcps1.2.4.1.3 "><p id="p16587835171114"><a name="p16587835171114"></a><a name="p16587835171114"></a>参考<a href="../get-code/源码获取.md">源码获取</a></p>
</td>
</tr>
<tr id="row430016273514"><td class="cellrowborder" valign="top" width="13.350000000000001%" headers="mcps1.2.4.1.1 "><p id="p330015271158"><a name="p330015271158"></a><a name="p330015271158"></a>Python3.7+</p>
</td>
<td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.4.1.2 "><p id="p43003270510"><a name="p43003270510"></a><a name="p43003270510"></a>编译构建工具</p>
</td>
<td class="cellrowborder" valign="top" width="62%" headers="mcps1.2.4.1.3 "><p id="p34760459518"><a name="p34760459518"></a><a name="p34760459518"></a>通过互联网获取</p>
</td>
</tr>
<tr id="row1711946154018"><td class="cellrowborder" valign="top" width="13.350000000000001%" headers="mcps1.2.4.1.1 "><p id="p15588165684216"><a name="p15588165684216"></a><a name="p15588165684216"></a>gn</p>
</td>
<td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.4.1.2 "><p id="p4588135634213"><a name="p4588135634213"></a><a name="p4588135634213"></a>产生ninja编译脚本</p>
</td>
<td class="cellrowborder" valign="top" width="62%" headers="mcps1.2.4.1.3 "><p id="p14131813191712"><a name="p14131813191712"></a><a name="p14131813191712"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz</a></p>
</td>
</tr>
<tr id="row16990164213404"><td class="cellrowborder" valign="top" width="13.350000000000001%" headers="mcps1.2.4.1.1 "><p id="p1858825613428"><a name="p1858825613428"></a><a name="p1858825613428"></a>ninja</p>
</td>
<td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.4.1.2 "><p id="p15844174611816"><a name="p15844174611816"></a><a name="p15844174611816"></a>执行ninja编译脚本</p>
</td>
<td class="cellrowborder" valign="top" width="62%" headers="mcps1.2.4.1.3 "><p id="p1923373393515"><a name="p1923373393515"></a><a name="p1923373393515"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar</a></p>
</td>
</tr>
<tr id="row7531362055"><td class="cellrowborder" rowspan="2" valign="top" width="13.350000000000001%" headers="mcps1.2.4.1.1 "><p id="p1467122152710"><a name="p1467122152710"></a><a name="p1467122152710"></a></p>
<p id="p15217227174016"><a name="p15217227174016"></a><a name="p15217227174016"></a>LLVM</p>
<p id="p689515112108"><a name="p689515112108"></a><a name="p689515112108"></a></p>
</td>
<td class="cellrowborder" rowspan="2" valign="top" width="24.65%" headers="mcps1.2.4.1.2 "><p id="p1739432372718"><a name="p1739432372718"></a><a name="p1739432372718"></a></p>
<p id="p122171727184019"><a name="p122171727184019"></a><a name="p122171727184019"></a>编译工具链</p>
<p id="p108951116109"><a name="p108951116109"></a><a name="p108951116109"></a></p>
</td>
<td class="cellrowborder" valign="top" width="62%" headers="mcps1.2.4.1.3 "><p id="p5445144091417"><a name="p5445144091417"></a><a name="p5445144091417"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/10.0.1-62608/linux/llvm.tar.gz" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/clang/10.0.1-62608/linux/llvm.tar.gz</a></p>
</td>
</tr>
<tr id="row78941113109"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1974322421510"><a name="p1974322421510"></a><a name="p1974322421510"></a>针对OpenHarmony_1.0.1_release分支使用以下链接下载：</p>
<p id="p198321032101412"><a name="p198321032101412"></a><a name="p198321032101412"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar</a></p>
</td>
</tr>
<tr id="row1644079184919"><td class="cellrowborder" valign="top" width="13.350000000000001%" headers="mcps1.2.4.1.1 "><p id="p744115914493"><a name="p744115914493"></a><a name="p744115914493"></a>hb</p>
</td>
<td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.4.1.2 "><p id="p1244114913492"><a name="p1244114913492"></a><a name="p1244114913492"></a><span id="text565372520148"><a name="text565372520148"></a><a name="text565372520148"></a>OpenHarmony</span>编译构建命令行工具</p>
</td>
<td class="cellrowborder" valign="top" width="62%" headers="mcps1.2.4.1.3 "><p id="p1463918124619"><a name="p1463918124619"></a><a name="p1463918124619"></a>通过互联网获取</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-notice.gif) **须知：** 
>-   如果后续通过“HPM组件方式”或“HPM包管理器命令行工具方式”获取源码，不需要安装gn、ninja编译工具。
>-   （推荐）如果后续通过“镜像站点方式”或“代码仓库方式”获取源码，需要安装gn、ninja、LLVM编译工具。安装gn、ninja、LLVM编译工具时，请确保编译工具的环境变量路径唯一。

## 获取源码<a name="section1545225464016"></a>

开发者需要在Linux服务器上下载并解压一套源代码，请参见[源码获取](../get-code/源码获取.md)。

## 安装和配置Python<a name="section1238412211211"></a>

1.  打开Linux编译服务器终端。
2.  输入如下命令，查看python版本号，需使用python3.7以上版本。

    ```
    python3 --version
    ```

    如果低于python3.7版本，不建议直接升级，请按照如下步骤重新安装。以python3.8为例，按照以下步骤安装python。

    1.  运行如下命令，查看Ubuntu版本：

    ```
    cat /etc/issue
    ```

    1.  根据Ubuntu不同版本，安装python。
        -   如果Ubuntu 版本为18+，运行如下命令。

            ```
            sudo apt-get install python3.8
            ```

        -   如果Ubuntu版本为16。

            a. 安装依赖包

            ```
            sudo apt update && sudo apt install software-properties-common
            ```

            b. 添加deadsnakes PPA 源，然后按回车键确认安装。

            ```
            sudo add-apt-repository ppa:deadsnakes/ppa
            ```

            c. 安装python3.8

            ```
            sudo apt upgrade && sudo apt install python3.8
            ```



3.  设置python和python3软链接为python3.8。

    ```
    sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.8 1
    sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 1
    ```

4.  安装并升级Python包管理工具（pip3），任选如下一种方式。
    -   **命令行方式：**

        ```
        sudo apt-get install python3-setuptools python3-pip -y
        sudo pip3 install --upgrade pip
        ```

    -   **安装包方式：**

        ```
        curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
        python get-pip.py
        ```



## 安装gn<a name="section29216201423"></a>

1.  打开Linux编译服务器终端。
2.  [下载gn工具](https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz)。
3.  在根目录下创建gn文件夹。

    ```
    mkdir ~/gn
    ```

4.  解压gn安装包至\~/gn路径下。

    ```
    tar -xvf gn-linux-x86-1717.tar.gz -C ~/gn
    ```

5.  设置环境变量。

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/gn:$PATH
    ```

6.  生效环境变量。

    ```
    source ~/.bashrc
    ```


## 安装ninja<a name="section8762358731"></a>

1.  打开Linux编译服务器终端。
2.  [下载ninja工具](https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar)。
3.  解压ninja安装包至\~/ninja路径下。

    ```
    tar -xvf ninja.1.9.0.tar -C ~/
    ```

4.  设置环境变量。

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/ninja:$PATH
    ```

5.  生效环境变量。

    ```
    source ~/.bashrc
    ```


## 安装LLVM<a name="section12202192215415"></a>

1.  打开Linux编译服务器终端。
2.  [下载LLVM工具](https://repo.huaweicloud.com/harmonyos/compiler/clang/10.0.1-62608/linux/llvm.tar.gz)。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >针对OpenHarmony\_1.0.1\_release分支使用此链接[下载LLVM工具](https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar)。

3.  解压LLVM安装包至\~/llvm路径下。

    ```
    tar -zxvf llvm.tar.gz -C ~/
    ```

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >针对OpenHarmony\_1.0.1\_release分支使用如下命令解压：
    >```
    >tar -xvf llvm-linux-9.0.0-36191.tar -C ~/
    >```

4.  设置环境变量。

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/llvm/bin:$PATH
    ```

5.  生效环境变量。

    ```
    source ~/.bashrc
    ```


## 安装hb<a name="section15794154618411"></a>

### 前提条件<a name="section1083283711515"></a>

请先安装Python 3.7.4及以上版本，请见[安装和配置Python](#section1238412211211)。

### 安装方法<a name="section11518484814"></a>

1.  运行如下命令安装hb

    ```
    python3 -m pip install --user ohos-build
    ```

2.  设置环境变量

    ```
    vim ~/.bashrc
    ```

    将以下命令拷贝到.bashrc文件的最后一行，保存并退出。

    ```
    export PATH=~/.local/bin:$PATH
    ```

    执行如下命令更新环境变量。

    ```
    source ~/.bashrc
    ```

3.  执行"hb -h"，有打印以下信息即表示安装成功：

    ```
    usage: hb
    
    OHOS build system
    
    positional arguments:
      {build,set,env,clean}
        build               Build source code
        set                 OHOS build settings
        env                 Show OHOS build env
        clean               Clean output
    
    optional arguments:
      -h, --help            show this help message and exit
    ```


### 卸载方法<a name="section3512551574"></a>

```
python3 -m pip uninstall ohos-build
```

>![](public_sys-resources/icon-notice.gif) **须知：** 
>如果安装hb的过程中遇到问题，请参见下文[常见问题](常见问题.md)进行解决。

