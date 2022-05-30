# 参考信息


## 使用build.sh脚本编译源码

1. 进入源码根目录，执行如下命令进行版本编译。
     
   ```
   ./build.sh --product-name name --ccache
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > _name_为产品名称，例如Hi3516DV300、rk3568等。

2. 检查编译结果。编译完成后，log中显示如下：
     
   ```
   post_process
   =====build name successful.
   ```

     编译所生成的文件都归档在out/{device_name}/目录下，结果镜像输出在out/{device_name}/packages/phone/images/ 目录下。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 其他模块化编译操作，可参见[编译构建指南](../subsystems/subsys-build-standard-large.md)。


## 配置代理


### 配置Python代理

1. 新建代理配置文件。
     
   ```
   mkdir ~/.pipvim ~/.pip/pip.conf
   ```

2. 在文件中写入如下代理信息并保存退出。
     
   ```
   [global]
   index-url = http://代理网址
   trusted-host = 可信任的镜像地址
   timeout = 120
   ```


### 配置NPM代理

1. 新建代理配置文件。
     
   ```
   vim ~/.npmrc
   ```

2. 在文件中写入如下代理信息并保存退出。
     
   ```
   registry=http://代理网址
   strict-ssl=false
   ```

3. 将以下内容添加到.bashrc中并保存退出。
     
   ```
   export NPM_REGISTRY=http://代理网址
   source .bashrc
   ```
