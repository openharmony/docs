# 搭建Ubuntu环境及编译（Docker方式）<a name="ZH-CN_TOPIC_0000001119805112"></a>

-   [获取标准系统源码](#section8761819202511)
    -   [前提条件](#section102871547153314)
    -   [操作步骤](#section429012478331)

-   [获取Docker环境](#section181431248132513)
-   [编译](#section92391739152318)

OpenHarmony标准系统为开发者提供的Docker环境已经将对应的编译工具链进行了封装，开发者可省略对应工具的安装。

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   在使用Docker前需要先安装Docker，Docker安装请参考[官方指导](https://docs.docker.com/engine/install/ubuntu/)。
>-   Docker方式和安装包方式二选一即可。选择Docker方式的开发者可跳过[安装包方式](搭建Ubuntu环境及编译（安装包方式）.md)的内容。

## 获取标准系统源码<a name="section8761819202511"></a>

### 前提条件<a name="section102871547153314"></a>

1.  注册码云gitee账号。
2.  注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。
3.  安装[git客户端](http://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%AE%89%E8%A3%85-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading))并配置用户信息。

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

## 获取Docker环境<a name="section181431248132513"></a>

**方式一：从HuaweiCloud SWR上直接获取Docker镜像进行构建：**

1.  获取Docker镜像。

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.1
    ```

2.  进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.1
    ```


**方式二：通过Dockerfile 构建本地Docker镜像进行构建**

1.  获取Dockerfile脚本文件，用来构建本地Docker镜像。

    ```
    git clone https://gitee.com/openharmony/docs.git
    ```

2.  进入Dockerfile代码目录路径执行Docker镜像构建命令。

    ```
    cd docs/docker/standard
    ./build.sh
    ```

3.  进入OpenHarmony代码根目录执行如下命令，从而进入Docker构建环境。

    ```
    docker run -it -v $(pwd):/home/openharmony openharmony-docker-standard:0.0.1
    ```


## 编译<a name="section92391739152318"></a>

1.  在源码的根目录执行预处理脚本。

    ```
    ../scripts/prepare.sh
    ```

2.  通过如下编译脚本启动标准系统类设备（参考内存≥128MB）的编译。

    ```
    ./build.sh --product-name {product_name}
    ```

    \{product\_name\}为当前版本支持的平台，比如：Hi3516DV300

    编译所生成的文件都归档在out/ohos-arm-release/目录下，结果镜像输出在 out/ohos-arm-release/packages/phone/images/ 目录下。

3.  编译源码完成，请进行镜像烧录，具体请参见[镜像烧录](镜像烧录.md)。

>![](public_sys-resources/icon-note.gif) **说明：** 
>退出Docker执行exit命令即可。

