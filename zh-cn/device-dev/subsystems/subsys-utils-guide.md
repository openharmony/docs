# 公共基础库开发指导


## 接口说明

  **表1** 文件操作接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| int&nbsp;UtilsFileOpen(const&nbsp;char\*&nbsp;path,&nbsp;int&nbsp;oflag,&nbsp;int&nbsp;mode) | 打开或创建文件 | 
| int&nbsp;UtilsFileClose(int&nbsp;fd) | 关闭文件 | 
| int&nbsp;UtilsFileRead(int&nbsp;fd,&nbsp;char&nbsp;\*buf,&nbsp;unsigned&nbsp;int&nbsp;len) | 读取特定长度的文件数据 | 
| int&nbsp;UtilsFileWrite(int&nbsp;fd,&nbsp;const&nbsp;char&nbsp;\*buf,&nbsp;unsigned&nbsp;int&nbsp;len) | 向文件写入特定大小的数据 | 
| int&nbsp;UtilsFileDelete(const&nbsp;char&nbsp;\*path) | 删除指定文件 | 
| int&nbsp;UtilsFileStat(const&nbsp;char&nbsp;\*path,&nbsp;unsigned&nbsp;int&nbsp;\*fileSize) | 获取文件大小 | 
| int&nbsp;UtilsFileSeek(int&nbsp;fd,&nbsp;int&nbsp;offset,&nbsp;unsigned&nbsp;int&nbsp;whence) | 重新定位文件读/写偏移量 | 
| int&nbsp;UtilsFileCopy(const&nbsp;char\*&nbsp;src,&nbsp;const&nbsp;char\*&nbsp;dest) | 将源文件复制一份并存储到目标文件 | 
| int&nbsp;UtilsFileMove(const&nbsp;char\*&nbsp;src,&nbsp;const&nbsp;char\*&nbsp;dest) | 将源文件移动到指定目标文件 | 

文件操作使用示例：

  
```
// open && write
char fileName[] = "testfile";
static const char def[] = "utils_file_operation implement.";
int fd = UtilsFileOpen(fileName, O_RDWR_FS | O_CREAT_FS | O_TRUNC_FS, 0);
printf("file handle = %d\n", fd);
int ret = UtilsFileWrite(fd, def, strlen(def));
printf("write ret = %d\n", ret);

// seek
ret = UtilsFileSeek(fd, 5, SEEK_SET_FS);
printf("lseek ret = %d\n", ret);

// read && close
char buf[64] = {0};
int readLen = UtilsFileRead(fd, buf, 64);
ret = UtilsFileClose(fd);
printf("read len = %d : buf = %s\n", readLen, buf);

// stat
int fileLen = 0;
ret = UtilsFileStat(fileName, &fileLen);
printf("file size = %d\n", fileLen);

// delete
ret = UtilsFileDelete(fileName);
printf("delete ret = %d\n", ret);
```

  **表2** KV存储接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| int&nbsp;UtilsGetValue(const&nbsp;char\*&nbsp;key,&nbsp;char\*&nbsp;value,&nbsp;unsigned&nbsp;int&nbsp;len) | 提供给上层应用根据key获取对应数据项 | 
| int&nbsp;UtilsSetValue(const&nbsp;char\*&nbsp;key,&nbsp;const&nbsp;char\*&nbsp;value) | 提供给上层应用用于存储/更新key对应数据项 | 
| int&nbsp;UtilsDeleteValue(const&nbsp;char\*&nbsp;key) | 提供给上层应用删除key对应数据项 | 

KV存储使用示例：

  
```
// set
char key[] = "rw.sys.version_100";
char value[] = "Hello kv operation implement!";
int ret = UtilsSetValue(key, value);
printf("UtilsSetValue set ret = %d\n", ret);

// get
char temp[128] = {0};
ret = UtilsGetValue(key, temp, 128);
printf("UtilsGetValue get ret = %d, temp = %s\n", ret, temp);

// delete
ret = UtilsDeleteValue(key);
printf("UtilsDeleteValue delete ret = %d\n", ret);
```



## 开发步骤


### LiteOS-A内核(Hi3516、Hi3518平台)KV存储的native应用开发：


1. 基于AbilityKit开发KV存储的native应用。
   - 基于KV存储提供的接口编写用户程序，并编译出so（libLauncher.so）文件。
        
      ```
      // set
      char key[] = "rw.sys.version_100";
      char value[] = "Hello kv operation implement!";
      int ret = UtilsSetValue(key, value);
      printf("UtilsSetValue set ret = %d\n", ret);
      
      // get
      char temp[128] = {0};
      ret = UtilsGetValue(key, temp, 128);
      printf("UtilsGetValue get ret = %d, temp = %s\n", ret, temp);
      
      // delete
      ret = UtilsDeleteValue(key);
      printf("UtilsDeleteValue delete ret = %d\n", ret);
      ```
   - 编写config.json文件，内容如下：
        
      ```
      {
          "app": {
              "bundleName": "com.example.launcher",
              "vendor": "example",
              "version": {
                  "code": 1,
                  "name": "1.0"
              }
          },
          "deviceConfig": {
              "default": {
                  "reqSdk": {
                      "compatible": "zsdk 1.0.0",
                      "target": "zsdk 1.0.1"
                  },
                  "keepAlive": false
              },
              "smartCamera": {
                  "reqSdk": {
                      "compatible": "zsdk 1.0.0",
                      "target": "zsdk 1.0.1"
                  },
                  "keepAlive": false
              }
          },
          "module": {
              "package": "com.example.launcher",
              "name": ".MyOpenHarmonyAbilityPackage",
              "deviceType": [
                  "phone", "tv","tablet", "pc","car","smartWatch","sportsWatch","smartCamera"
              ], 
              "distro": {
                  "deliveryWithInstall": true, 
                  "moduleName": "Launcher", 
                  "moduleType": "entry"
              },
              "abilities": [{
                  "name": "MainAbility",
                  "icon": "res/drawable/phone.png",
                  "label": "test app 1", 
                  "launchType": "standard",
                  "type": "page"
              },
              {
                  "name": "SecondAbility",
                  "icon": "res/drawable/phone.png",
                  "label": "test app 2", 
                  "launchType": "standard",
                  "type": "page"
              },
              {
                  "name": "ServiceAbility",
                  "icon": "res/drawable/phone.png",
                  "label": "test app 2", 
                  "launchType": "standard",
                  "type": "service"
              }
              ]
          }
      }
      ```

   - 生成hap包。
      - 按照如下目录结构存放文件，res/drawable下面放置资源文件：

        **图1** 资源文件路径图

        ![zh-cn_image_0000001154153558](figures/zh-cn_image_0000001154153558.png)

      - 将上述文件打包生成zip包，修改后缀为.hap，例如Launcher.hap

2. 连接单板，通过串口向单板发送安装KV存储native应用的命令。
     
   ```
   ./nfs/dev_tools/bin/bm install -p /nfs/Launcher.hap
   ```

3. 通过串口向单板发送运行KV存储native应用的命令。
     
   ```
   ./nfs/dev_tools/bin/aa start -p com.example.launcher -n ServiceAbility
   ```


### Dump系统属性在LiteOS-M内核平台使用：

1. 连接单板，通过串口向单板发送AT+SYSPARA命令。
     
   ```
   AT+SYSPARA
   ```

     **图2** LiteOS-M平台dump系统属性输出

     ![zh-cn_image_0000001115123966](figures/zh-cn_image_0000001115123966.png)


### Dump系统属性在LiteOS-A内核平台使用：

1. 连接单板，运行bin路径下的os_dump加参数--help，查看os_dump使用指导。
     
   ```
   ./bin/os_dump --help
   ```

2. os_dump加参数-l，查看当前系统有哪些模块支持获取属性。
     
   ```
   ./bin/os_dump -l
   ```

3. os_dump加参数syspara，查看当前系统属性。
     
   ```
   ./bin/os_dump syspara
   ```

     **图3** LiteOS-A平台dump系统属性输出

     ![zh-cn_image_0000001197369959](figures/zh-cn_image_0000001197369959.png)
