# tftp


## 命令功能

TFTP（Trivial File Transfer Protocol，简单文件传输协议）是TCP/IP协议族中的一个用来在客户机与服务器之间进行简单文件传输的协议，提供简单、低开销的文件传输服务。端口号为69。

tftp命令可以从TFTP服务器上下载文件。


## 命令格式

./bin/tftp _&lt;-g/-p&gt;__-l__[FullPathLocalFile] -r [RemoteFile] [Host]_


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| -g/-p | 文件传输方向：<br/>-&nbsp;-g&nbsp;从TFTP服务器获取文件。<br/>-&nbsp;-p&nbsp;上传文件到TFTP服务器。 | N/A | 
| -l&nbsp;FullPathLocalFile | 本地文件完整路径。 | N/A | 
| -r&nbsp;RemoteFile | 服务端文件名。 | N/A | 
| Host | 服务端IP。 | N/A | 


## 使用指南

1. 在服务器端搭建TFTP服务器，并进行正确配置。

2. OpenHarmony单板使用tftp命令上传、下载文件。

3. 传输的文件大小是有限制的不能大于32M。
   > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
   > tftp属于调测功能，默认配置为关闭，正式产品中禁止使用该功能。


## 使用实例

举例：从服务器下载out文件。


## 输出说明

  
```
OHOS # ./bin/tftp -g -l /nfs/out -r out 192.168.1.2
TFTP transfer finish
```

tftp命令执行后，传输正常完成会显示TFTP transfer finish， 失败的话会显示其他的打印信息帮助定位问题。
