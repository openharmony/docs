# 获取源码<a name="ZH-CN_TOPIC_0000001177086414"></a>


## 前提条件<a name="section21887149017"></a>

1.  注册码云gitee帐号。
2.  注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。
3.  安装[git客户端](https://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%AE%89%E8%A3%85-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  安装码云repo工具，可以执行如下命令。

    ```
    curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 -o /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```


## 操作步骤<a name="section349724435812"></a>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>Master主干为开发分支，开发者可通过Master主干获取最新特性。发布版本代码相对比较稳定，开发者可基于发布版本代码进行商用功能开发。

-   **OpenHarmony主干代码获取**

    方式一（推荐）：通过repo + ssh下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

    ```
    repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
    repo sync -c
    repo forall -c 'git lfs pull'
    ```

    方式二：通过repo + https下载。

    ```
    repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
    repo sync -c
    repo forall -c 'git lfs pull'
    ```

-   **OpenHarmony发布版本代码获取**

    OpenHarmony发布版本获取源码方式请参考[Release-Notes](../get-code/../../release-notes/OpenHarmony-v3.0.2-LTS.md)。


