# 配置代理


### 配置Python代理

1. 新建代理配置文件。
     
   ```
   mkdir ~/.pip
   vim ~/.pip/pip.conf
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
