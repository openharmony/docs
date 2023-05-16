# 全球化子系统ChangeLog

## cl.resourceManager.1  资源获取rawfile文件描述符接口含义变更

相较于之前的版本，在4.0.2.2 版本中，新增不解压特性，rawfile文件描述符接口返回值的含义发生了变化。接口用于返回获取的rawfile文件的descriptor：RawFileDescriptor {fd，offset, length}，由于不解压特性变更，返回值没发生变化，但返回值的含义发生了变化, 变化如下：

**新增不解压特性前**：

fd: 访问rawfile文件的文件描述符；

offset: 访问rawfile文件的偏移量，此时为0；

length: 访问rawfile文件的大小。

**新增不解压特性后**：

fd: 访问rawfile文件所在hap的文件描述符；

offset: 访问rawfile文件相对于hap的偏移量；

length: 访问rawfile文件的大小。

**变更影响**

之前只通过fd可以访问到rawfile文件，在4.0.2.2 及以上版本需要通过{fd, offset, length}三个参数才能访问到。

**关键接口/组件变更**

| **涉及接口**                            | 
| ----------------                         | 
| getRawFd(path: string, callback: AsyncCallback\<RawFileDescriptor>): void   | 
| getRawFd(path: string): Promise\<RawFileDescriptor>  |
| getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void|
| getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>|
||

**示例代码**

以调用接口getRawFd为例：
```
try {
    this.context.resourceManager.getRawFd("test.ogg", (error, value) => {
        if (error != null) {
            console.log(`callback getRawFd failed error code: ${error.code}, message: ${error.message}.`);
        } else {
            let fileDescriptor = {
                fd = value.fd,
                offset = value.offset,
                length = value.length
            }
            this.avPlayer.fdSrc(fileDescriptor); // 以音频播放为例，调用fdSrc时需要传fileDescriptor，不能仅传fd。
        }
    });
  } catch (error) {
      console.error(`callback getRawFd failed, error code: ${error.code}, message: ${error.message}.`)
  };
```
