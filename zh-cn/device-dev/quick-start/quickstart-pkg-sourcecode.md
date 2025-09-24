# 获取源码


在Ubuntu环境下通过以下步骤获取OpenHarmony源码。


## 准备工作

1. 注册gitcode帐号。

2. 注册gitcode的SSH公钥，请参考[gitcode帮助中心](https://docs.gitcode.com/docs/help/home/user_center/security_management/ssh)。

3. 安装git客户端和git-lfs。（上述工具已在安装必要的库和工具小节安装。如已安装，请忽略）
   
   更新软件源：
   
   ```
   sudo apt-get update
   ```

   通过以下命令安装：
   
   ```
   sudo apt-get install git git-lfs
   ```

4. 配置用户信息。
   
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

5. 执行如下命令安装gitcode的repo工具。
   
   下述命令中的安装路径以"~/bin"为例，请用户自行创建所需目录。
   
   ```
   mkdir ~/bin
   curl https://raw.gitcode.com/gitcode-dev/repo/raw/main/repo-py3 -o ~/bin/repo 
   chmod a+x ~/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```

6. 将repo添加到环境变量。
   
   ```
   vim ~/.bashrc               # 编辑环境变量
   export PATH=~/bin:$PATH     # 在环境变量的最后添加一行repo路径信息
   source ~/.bashrc            # 应用环境变量
   ```


## 获取方式

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 发布分支代码相对比较稳定，开发者可基于发布分支代码进行商用功能开发。Master主干为开发分支，开发者可通过Master主干获取最新特性。

- **OpenHarmony发布分支代码获取**
  
   OpenHarmony各个版本发布分支的源码获取方式请参考[Release-Notes](../../release-notes/Readme.md)。


- **OpenHarmony主干代码获取**
  >获取代码时尽可能在根目录下新建路径中获取。
  
  ```
  cd ~
  mkdir ohos_master       #在根目录下新建ohos_master路径
  cd ohos_master          #进入ohos_master路径拉取代码
  ```
  

   方式一（推荐）：通过repo + ssh下载（需注册公钥，请参考[gitcode帮助中心](https://docs.gitcode.com/docs/help/home/user_center/security_management/ssh)）。
   
  ```
  repo init -u git@gitcode.com:openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

  方式二：通过repo + https下载（云计算服务器推荐用此方法）。

  
  ```
  repo init -u https://gitcode.com/openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```


## 执行prebuilts

  在源码根目录下执行prebuilts脚本，安装编译器及二进制工具。

```
bash build/prebuilts_download.sh
```
