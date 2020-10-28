# Openharmony docerimage

### Docker镜像

Openharmony的Docker镜像托管在[HuaweiCloud SWR](https://console.huaweicloud.com/swr/?region=cn-south-1#/app/warehouse/warehouseMangeDetail/goldensir/openharmony-docker/openharmony-docker?type=ownImage)上。
目前容器化构建选项支持情况如下：

| 硬件平台   | Docker镜像仓库                | 标签                       | 说明                                       |
| :----- | :------------------------ | :----------------------- | :--------------------------------------- |
| 3861/3516/3518    | `swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker` | `0.0.1`                  | 已经预安装Openharmony `0.0.1` 版本的编译环境。       |


* Ubuntu/Windows 平台使用说明

    对于`Ubuntu/Windows`平台，可以直接使用以下命令获取并运行最新的稳定镜像：
    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.1
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.1
    python build.py wifiiot/ipcamera_hi3516dv300/ipcamera_hi3518ev300
    ```

#### 通过Dockerfile 构建本地Docker image
    ```
    git clone https://gitee.com/openharmony/docs.git 
    cd docs/docker
    ./build.sh
    ```
