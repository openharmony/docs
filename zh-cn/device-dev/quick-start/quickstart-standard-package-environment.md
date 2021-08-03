# 搭建Ubuntu环境及编译（安装包方式）<a name="ZH-CN_TOPIC_0000001119804790"></a>

-   [安装依赖工具](#section18431165519244)
-   [获取标准系统源码](#section113751052102517)
    -   [前提条件](#section102871547153314)
    -   [操作步骤](#section429012478331)

-   [执行prebuilts](#section0495320152619)
-   [编译](#section1664835963517)

## 安装依赖工具<a name="section18431165519244"></a>

安装命令如下：

```
sudo apt-get update && sudo apt-get install binutils git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip
```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>以上安装命令适用于Ubuntu18.04，其他版本请根据安装包名称采用对应的安装命令。

## 获取标准系统源码<a name="section113751052102517"></a>

### 前提条件<a name="section102871547153314"></a>

1.  注册码云gitee账号。
2.  注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。
3.  安装[git客户端](http://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%AE%89%E8%A3%85-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  安装码云repo工具，可以执行如下命令。

    ```
    curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```


### 操作步骤<a name="section429012478331"></a>

方式一（推荐）：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

```
repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

方式二：通过repo + https 下载。

```
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## 执行prebuilts<a name="section0495320152619"></a>

在源码根目录下执行脚本，安装编译器及二进制工具。

```
bash build/prebuilts_download.sh
```

下载的prebuilts二进制默认存放在与OpenHarmony同目录下的OpenHarmony\_2.0\_canary\_prebuilts下。

## 编译<a name="section1664835963517"></a>

在Linux环境进行如下操作:

1.  进入源码根目录，执行如下命令进行版本编译。

    ```
    ./build.sh --product-name {product_name}
    ```

    \{product\_name\}为当前版本支持的平台，比如：Hi3516DV300

2.  检查编译结果。编译完成后，log中显示如下：

    ```
     build system image successful.
    =====build Hi3516DV300 successful.
    ```

    编译所生成的文件都归档在out/ohos-arm-release/目录下，结果镜像输出在 out/ohos-arm-release/packages/phone/images/ 目录下。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >其他模块化编译操作，可参见[编译构建指导](../subsystems/subsys-build-standard-large.md)。

3.  编译源码完成，请进行镜像烧录，具体请参见[镜像烧录](quickstart-standard-burn.md)。

