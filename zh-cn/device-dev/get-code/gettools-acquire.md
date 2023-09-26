# Docker编译环境


## Docker环境介绍

OpenHarmony为开发者提供了两种Docker环境，以帮助开发者快速完成复杂的开发环境准备工作。两种Docker环境及适用场景如下：

- 独立Docker环境：适用于直接基于Ubuntu、Windows操作系统平台进行版本编译的场景。

- 基于HPM的Docker环境：适用于使用HPM工具进行发行版编译的场景。

**表1** Docker镜像介绍

| 系统类型 | 运行平台 | Docker镜像仓库 | 标签 | 
| -------- | -------- | -------- | -------- |
| 标准系统（独立Docker环境） | Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard | 3.2 | 
| 小型系统（独立Docker环境） | Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small | 3.2 | 
| 轻量系统（独立Docker环境） | Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini | 3.2 | 
| 轻量和小型系统（HPM Docker环境） | Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker | 0.0.3 | 


## 环境准备

在使用Docker环境前，需要准备源码和一些基本工具，以Ubuntu为例，您需要执行以下步骤：

1. 安装Docker
   - 在Ubuntu中，可以使用下面的命令来安装Docker：
      ```
      sudo apt install docker.io
      ```
   - 其他系统的Docker安装请参考[Docker指导](https://docs.docker.com/engine/install/)。

2. 获取OpenHarmony源码

   请参考[获取源码](sourcecode-acquire.md)。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
   > HPM Docker环境无需单独获取源码。

3. 获取使用权限

   为了能够使用Docker，请使用具备root权限的用户，或已被授予Docker使用权限的用户进行后续操作。在Ubuntu系统中，通常可以通过在命令前加sudo来获取root权限。在Windows系统中，您可能需要在管理员模式下运行cmd或PowerShell。

## 独立Docker环境

Docker镜像是包含了运行环境和应用程序的轻量级、可执行的软件包，OpenHarmony的Docker镜像托管在HuaweiCloud SWR上。开发者可以通过该镜像在很大程度上简化编译前的环境配置。这一部分将引导您如何在Docker环境中配置和使用OpenHarmony，下文将介绍具体使用步骤。

### 搭建Docker环境（轻量系统和小型系统）

1. 获取Docker镜像

   获取小型系统镜像的命令为：

   ```
   docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2
   ```
   获取轻量系统镜像的命令为：
   ```
   docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini:3.2
   ```

2. 进入Docker构建环境

   在获取了镜像之后，您需要创建一个新的Docker容器，并进入该容器中。进入OpenHarmony源码根目录执行如下命令，从而进入Docker构建环境。

   - Ubuntu系统
     
      ```
      # 进入小型系统Docker构建环境
      docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2

      # 进入轻量系统Docker构建环境
      docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini:3.2
      ```

   - Windows系统（假设源码目录为`D:\OpenHarmony`）：

      ```
      # 进入小型系统Docker构建环境
      docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2

      # 进入轻量系统Docker构建环境
      docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini:3.2
      ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
   > `docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2` 这个命令的含义是，创建并运行一个新的OpenHarmony的Docker容器，这个容器运行在交互模式下，并且将当前目录映射到容器的/home/openharmony目录。

### 编译源码（轻量系统和小型系统）

1. 启动编译脚本

   执行`docker run`命令进入Docker容器后（此时位于`/home/openharmony`路径下），您可以通过如下编译脚本启动轻量系统类设备（参考内存≥128KiB）和小型系统类设备（参考内存≥1MiB）的编译。

   ```
   python3 build.py -p {product_name}@{company}
   ```

   其中，`{product_name}`为当前版本支持的平台，`{company}`为`{product_name}`对应的公司名。
   
   举个例子，如果您要编译的产品为`hisilicon`下的`ipcamera_hispark_taurus`，您可以输入以下命令来启动编译：

   ```
   python3 build.py -p ipcamera_hispark_taurus@hisilicon
   ```

   同样，如果您要编译的产品是`ohemu`下的`qemu_small_system_demo`，那么您可以输入以下命令来启动编译：

   ```
   python3 build.py -p qemu_small_system_demo@ohemu
   ```

2. 查看编译结果

   在编译结束后，编译所生成的文件都会被存放在`out/{device_name}/`目录下，结果镜像输出在`out/{device_name}/packages/phone/images/`目录下。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
> 如需退出Docker，执行`exit`命令即可。这个命令会停止当前的Docker容器，并返回到您的操作系统。

### 搭建Docker环境（标准系统）

1. 获取Docker镜像

   在搭建标准系统的Docker环境前，我们也需要先获取对应的Docker镜像。具体的命令如下：
     
   ```
   docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard:3.2
   ```

2. 进入Docker构建环境

   与之前的步骤相同，我们需要创建一个新的Docker容器，并进入该容器中。进入openharmony源码根目录执行如下命令，从而进入Docker构建环境。
     
   - Ubuntu系统

      ```
      docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard:3.2
      ```

   - Windows系统（假设源码目录为`D:\OpenHarmony`）

      ```
      docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard:3.2
      ```

### 编译源码（标准系统）

1. 启动编译脚本

   执行`docker run`命令进入Docker容器后（此时位于`/home/openharmony`路径下），您可以通过如下编译脚本启动标准系统类设备（参考内存≥128MB）的编译。
  
   ```
   ./build.sh --product-name {product_name} --ccache
   ```

   `{product_name}`为当前版本支持的平台。例如，您要编译的产品是`rk3568`，那么您可以输入以下命令来启动编译：

   ```
   ./build.sh --product-name rk3568 --ccache
   ```

2. 查看编译结果\
   编译所生成的文件都归档在`out/{device_name}/`目录下，结果镜像输出在`out/{device_name}/packages/phone/images/`目录下。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
> 如需退出Docker，执行`exit`命令即可。这个命令会停止当前的Docker容器，并返回到您的操作系统。


## 基于HPM的Docker环境

docker_dist是一个[HPM](https://hpm.harmonyos.com/)系统中的模板组件，能够帮助用户快速初始化HPM工程，利用docker镜像来快速编译OpenHarmony发行版，在很大程度上简化了编译前的环境配置。开发者在配置好Ubuntu和[hpm-cli](https://device.harmonyos.com/cn/docs/documentation/guide/hpm-part-development-install-0000001178291102)开发环境后，可以通过以下步骤来使用我们提供的Docker环境。


### 搭建Docker环境

1. 初始化安装模板

   在任意工作目录中执行以下命令
     
   ```
   hpm init -t @ohos/docker_dist
   ```

2. 修改publishAs

   因为获取到的是模板类型的包，要把包的类型改为需要的类型。 在当前目录下打开bundle.json文件，把"publishAs"字段的值由"template"改为"distribution"。


### 获取及编译源码

执行编译。自动安装docker只能在Ubuntu环境下执行，如果其他环境，需要用户自行安装docker，然后拉取镜像，执行编译。

- 自动安装docker（Ubuntu环境）<br>
  以下命令可以帮助用户自动安装docker, 拉取镜像，并且在容器中开始运行对应解决方案的拉取和编译。

  方式一：

  命令后接参数指定解决方案，格式如下：

    
  ```
  hpm run docker solution={product}
  ```

  {product}为需编译的解决方案，如：\@ohos/hispark_taurus、\@ohos/hispark_aries、\@ohos/hispark_pegasus。

  方式二：

  设置环境变量来选择解决方案，再执行编译命令。

  1. 选择解决方案。
        
      ```
      export solution={product}
      ```

      {product}为需编译的解决方案，如：\@ohos/hispark_taurus、\@ohos/hispark_aries、\@ohos/hispark_pegasus。
  2. 获取源码及执行编译。
        
      ```
      hpm run docker
      ```

    以上两种方式以\@ohos/hispark_taurus为例，执行成功结果如下：
    
  ```
  ......
  ohos ipcamera_hispark_taurus build success!
  @ohos/hispark_taurus: distribution building completed.
  ```

- 自行安装docker（非Ubuntu环境）<br>
  自行安装docker相关操作如下：

    
  ```
  # 拉取镜像 
  docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3# linux环境下的编译 
  hpm run distWithDocker solution={product}
  # windows下的编译，需要配置gitbash 
  hpm config set shellPath "gitbash路径"
  hpm run distWithDocker solution={product}
  ```
