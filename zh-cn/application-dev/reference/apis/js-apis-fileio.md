# 文件管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import fileio from '@ohos.fileio';
```


## 权限列表

无


## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其绝对路径，获取方式及其接口用法请参考：[Context模块的接口getOrCreateLocalDir](js-apis-Context.md)。

“文件/目录绝对路径”=“应用目录路径”+“文件/目录名”

通过上述接口获取到应用目录路径dir，文件名为“xxx.txt”，文件所在绝对路径为：

```
let path = dir + "xxx.txt"
```


文件描述符fd：


```
let fd = fileio.openSync(path);
```


## fileio.statSync

statSync(path:string): Stat

以同步方法获取文件的信息。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待获取文件的绝对路径。 |


- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [Stat](#stat) | 表示文件的具体信息。 |

- 示例：
  ```
  let stat = fileio.statSync(path);
  ```


## fileio.opendirSync

opendirSync(path: string): Dir

以同步方法打开文件目录。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待打开文件目录的绝对路径。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [Dir](#dir) | 返回Dir对象。 |

- 示例：
  ```
  let dir = fileio.opendirSync(path);
  ```


## fileio.accessSync

accessSync(path: string, mode?: number): void

以同步方法检查当前进程是否可访问某文件。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待访问文件的绝对路径。 |
  | mode | number | 否 | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-&nbsp;0：确认文件是否存在。<br/>-&nbsp;1：确认当前进程是否具有可执行权限。<br/>-&nbsp;2：确认当前进程是否具有写权限。<br/>-&nbsp;4：确认当前进程是否具有读权限。 |

- 示例：
  ```
  fileio.accessSync(path);
  ```


## fileio.closeSync

closeSync(fd: number): void

以同步方法关闭文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待关闭文件的文件描述符。 |

- 示例：
  ```
  fileio.closeSync(fd);
  ```


## fileio.copyFileSync

fileio.copyFileSync(src: string, dest: string, mode?:number): void

以同步方法复制文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | src | string | 是 | 待复制文件的路径。 |
  | dest | string | 是 | 目标文件路径。 |
  | mode | number | 否 | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |

- 示例：
  ```
  fileio.copyFileSync(src, dest);
  ```


## fileio.mkdirSync

fileio.mkdirSync(path: string, mode?: number): void

以同步方法创建目录。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待创建目录的绝对路径。 |
  | mode | number | 否 | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-&nbsp;0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

- 示例：
  ```
  fileio.mkdirSync(path);
  ```


## fileio.openSync

openSync(path: string, flags?: number, mode?: number): number

以同步方法打开文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待打开文件的绝对路径。 |
  | flags | number | 否 | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;0o0：只读打开。<br/>-&nbsp;0o1：只写打开。<br/>-&nbsp;0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数&nbsp;mode。<br/>-&nbsp;0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-&nbsp;0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-&nbsp;0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;0o200000：如果path指向目录，则出错。<br/>-&nbsp;0o400000：如果path指向符号链接，则出错。<br/>-&nbsp;0o4010000：以同步IO的方式打开文件。 |
  | mode | number | 否 | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o666。<br/>-&nbsp;0o666：所有者具有读、写权限，所有用户组具有读、写权限，其余用户具有读、写权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 打开文件的文件描述符。 |

- 示例：
  ```
  fileio.openSync(path);
  ```


## fileio.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: Object): number

以同步方法从文件读取数据。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待读取文件的文件描述符。 |
  | buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;offset，number&nbsp;类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number&nbsp;类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number&nbsp;类型，表示期望读取文件的位置。可选，默认从当前位置开始读。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 实际读取的长度。 |

- 示例：
  ```
  let fd = fileio.openSync(path, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.readSync(fd, buf);
  console.log(String.fromCharCode.apply(null, new Uint8Array(buf)));
  ```


## fileio.rmdirSync

rmdirSync(path: string): void

以同步方法删除目录。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待删除目录的绝对路径。 |

- 示例：
  ```
  fileio.rmdirSync(path);
  ```


## fileio.unlinkSync

unlinkSync(path: string): void

以同步方法删除文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待删除文件的绝对路径。 |

- 示例：
  ```
  fileio.unlinkSync(path);
  ```


## fileio.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?:Object): number

以同步方法将数据写入文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待写入文件的文件描述符。 |
  | buffer | ArrayBuffer&nbsp;\|&nbsp;string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 实际写入的长度。 |

- 示例：
  ```
  let fd = fileio.openSync(path, 0o102, 0o666);
  fileio.writeSync(fd, "hello, world");
  ```


## fileio.chmodSync<sup>7+</sup>

chmodSync(path: string, mode: number): void

以同步方法基于文件路径改变文件权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待改变文件权限的绝对路径。 |
  | mode | number | 是 | 改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

- 示例：
  ```
  fileio.chmodSync(fpath, mode);
  ```


## fileio.fstatSync<sup>7+</sup>

fstatSync(fd: number): Stat

以同步方法基于文件描述符获取文件状态信息。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待获取文件的文件描述符。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Stat&gt; | 表示文件的具体信息。 |

- 示例：
  ```
  let fd = fileio.openSync(path);
  let stat = fileio.fstatSync(fd);
  ```


## fileio.ftruncateSync<sup>7+</sup>

ftruncateSync(fd: number, len?: number): void

以同步方法基于文件描述符截断文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待截断文件的文件描述符。 |
  | len | number | 否 | 文件截断后的长度，以字节为单位。 |

- 示例：
  ```
   fileio.ftruncate(fd, len);
  ```


## fileio.fchmodSync<sup>7+</sup>

fchmodSync(existingPath: string, newPath: string): void

以同步方法基于文件描述符改变文件权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待改变文件的文件描述符。 |
  | mode | number | 是 | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

- 示例：
  ```
   fileio.fchmodSync(fd, mode);
  ```


## fileio.truncateSync<sup>7+</sup>

truncateSync(fpath: string, len?: number): void

以同步方法基于文件路径截断文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待截断文件的绝对路径。 |
  | len | number | 否 | 文件截断后的长度，以字节为单位。 |

- 示例：
  ```
  fileio.ftruncate(path, len);
  ```


## fileio.renameSync<sup>7+</sup>

renameSync(oldPath: string, newPath: string): void

以同步方法重命名文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | oldPath | string | 是 | 目标文件的当前绝对路径。 |
  | Newpath | String | 是 | 目标文件的新绝对路径。 |

- 示例：
  ```
  fileio.renameSync(oldpath, newpath);
  ```


## fileio.fsyncSync<sup>7+</sup>

fsyncSync(fd: number): void

以同步方法同步文件数据。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待同步文件的文件描述符。 |

- 示例：
  ```
  fileio.fyncsSync(fd);
  ```


## fileio.chownSync<sup>7+</sup>

chownSync(path: string, uid: number, gid: number): void

以同步的方法基于文件路径改变文件所有者。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待改变文件的绝对路径。 |
  | uid | number | 是 | 新的UID。 |
  | gid | number | 是 | 新的GID。 |

- 示例：
  ```
  let stat = fileio.statSync(fpath)
  fileio.chownSync(path, stat.uid, stat.gid);
  ```


## fileio.createStreamSync<sup>7+</sup><a name="fileio.createstreamsync"></a>

createStreamSync(path: string, mode: string): Stream

以同步方法基于文件路径打开文件流。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 待打开文件的绝对路径。 |
  | mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | [Stream](#stream7-) | 返回文件流的结果。 |

- 示例：
  ```
  let ss = fileio.createStream(path, "r+");
  ```


## fileio.fdopenStreamSync<sup>7+</sup>

fdopenStreamSync(fd: number, mode: string): Stream

以同步方法基于文件描述符打开文件流。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待打开文件的文件描述符。 |
  | mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | [Stream](#stream7-) | 返回文件流的结果。 |

- 示例：
  ```
  let ss = fileio.fdopenStreamSync(fd, "r+");
  ```


## fileio.fchownSync<sup>7+</sup>

fchownSync(fd: number, uid: number, gid: number): void

以同步方法基于文件描述符改变文件所有者。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 待改变文件的文件描述符。 |
  | uid | number | 是 | 文件所有者的UID。 |
  | gid | number | 是 | 文件所有组的GID。 |

- 示例：
  ```
  let stat = fileio.statSync(fpath);
  fileio.fchownSync(fd, stat.uid, stat.gid);
  ```


## Stat

文件具体信息，在调用Stat的方法前，需要先通过[fileio.statSync](#fileio.statsync)来构建一个Stat实例。


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| dev | number | 是 | 否 | 标识包含该文件的主设备号。 |
| ino | number | 是 | 否 | 标识该文件。通常同设备上的不同文件的INO不同。 |
| mode | number | 是 | 否 | 表示文件类型及权限，其首&nbsp;4&nbsp;位表示文件类型，后&nbsp;12&nbsp;位表示权限。各特征位的含义如下：<br/>-&nbsp;0o170000：可用于获取文件类型的掩码。<br/>-&nbsp;0o140000：文件是套接字。<br/>-&nbsp;0o120000：文件是符号链接。<br/>-&nbsp;0o100000：文件是一般文件。<br/>-&nbsp;0o060000：文件属于块设备。<br/>-&nbsp;0o040000：文件是目录。<br/>-&nbsp;0o020000：文件是字符设备。<br/>-&nbsp;0o010000：文件是具名管道，即FIFO。<br/>-&nbsp;0o0700：可用于获取用户权限的掩码。<br/>-&nbsp;0o0400：用户读，对于普通文件，所有者可读取文件；对于目录，所有者可读取目录项。<br/>-&nbsp;0o0200：用户写，对于普通文件，所有者可写入文件；对于目录，所有者可创建/删除目录项。<br/>-&nbsp;0o0100：用户执行，对于普通文件，所有者可执行文件；对于目录，所有者可在目录中搜索给定路径名。<br/>-&nbsp;0o0070：可用于获取用户组权限的掩码。<br/>-&nbsp;0o0040：用户组读，对于普通文件，所有用户组可读取文件；对于目录，所有用户组可读取目录项。<br/>-&nbsp;0o0020：用户组写，对于普通文件，所有用户组可写入文件；对于目录，所有用户组可创建/删除目录项。<br/>-&nbsp;0o0010：用户组执行，对于普通文件，所有用户组可执行文件；对于目录，所有用户组是否可在目录中搜索给定路径名。<br/>-&nbsp;0o0007：可用于获取其他用户权限的掩码。<br/>-&nbsp;0o0004：其他读，对于普通文件，其余用户可读取文件；对于目录，其他用户组可读取目录项。<br/>-&nbsp;0o0002：其他写，对于普通文件，其余用户可写入文件；对于目录，其他用户组可创建/删除目录项。<br/>-&nbsp;0o0001：其他执行，对于普通文件，其余用户可执行文件；对于目录，其他用户组可在目录中搜索给定路径名。 |
| nlink | number | 是 | 否 | 文件的硬链接数。 |
| uid | number | 是 | 否 | 文件所有者的ID。 |
| gid | number | 是 | 否 | 文件所有组的ID。 |
| rdev | number | 是 | 否 | 标识包含该文件的从设备号。 |
| size | number | 是 | 否 | 文件的大小，以字节为单位。仅对普通文件有效。 |
| blocks | number | 是 | 否 | 文件占用的块数，计算时块大小按512B计算。 |
| atime | number | 是 | 否 | 上次访问该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |
| mtime | number | 是 | 否 | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |
| ctime | number | 是 | 否 | 最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的秒数。 |


### isBlockDevice

isBlockDevice(): boolean

用于判断当前目录项是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是块特殊设备。 |

- 示例：
  ```
  let isBLockDevice = fileio.statSync(path).isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

用于判断当前目录项是否是字符特殊文件。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是字符特殊设备。 |

- 示例：
  ```
  let isCharacterDevice = fileio.statSync(path).isCharacterDevice();
  ```


### isDirectory

isDirectory(): boolean

用于判断当前目录项是否是目录。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是目录。 |

- 示例：
  ```
  let isDirectory= fileio.statSync(path).isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

用于判断当前目录项是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是&nbsp;FIFO。 |

- 示例：
  ```
  let isFIFO= fileio.statSync(path).isFIFO(); 
  ```


### isFile

isFile(): boolean

用于判断当前目录项是否是普通文件。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是普通文件。 |

- 示例：
  ```
  let isFile= fileio.statSync(fpath).isFile();
  ```


### isSocket

isSocket(): boolean

用于判断当前目录项是否是套接字。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是套接字。 |

- 示例：
  ```
  let isSocket = fileio.statSync(path).isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

用于判断当前目录项是否是符号链接。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是符号链接。 |

- 示例：
  ```
  let isSymbolicLink = fileio.statSync(path).isSymbolicLink(); 
  ```


## Stream<sup>7+</sup>

文件流，在调用Stream的方法前，需要先通过[fileio.createStreamSync](#fileio.createstreamsync)方法来构建一个Stream实例。


### closeSync<sup>7+</sup>

closeSync(): void

同步关闭文件流。

- 示例：
  ```
  let ss= fileio.createStreamSync(path);
  ss.closeSync();
  ```


### flushSync<sup>7+</sup>

flushSync(): void

同步刷新文件流。

- 示例：
  ```
  let ss= fileio.createStreamSync(path);
  ss.flushSync();
  ```


### writeSync<sup>7+</sup>

writeSync(buffer: ArrayBuffer | string, options?:Object): number

以同步方法将数据写入流文件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | buffer | ArrayBuffer&nbsp;\|&nbsp;string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 实际写入的长度。 |

- 示例：
  ```
  let ss= fileio.createStreamSync(fpath,"r+");
  ss.writeSync("hello, world",{offset: 1,length: 5,position: 5,encoding :'utf-8'});
  ```


### readSync<sup>7+</sup>

readSync(buffer: ArrayBuffer, options?: Object): number

以同步方法从流文件读取数据。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;offset，number&nbsp;类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number&nbsp;类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number&nbsp;类型，表示期望读取文件的位置。可选，默认从当前位置开始读。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 实际读取的长度。 |

- 示例：
  ```
  let ss = fileio.createStreamSync(fpath, "r+");
  ss.readSync(new ArrayBuffer(4096),{offset: 1,length: FILE_CONTENT.length,position: 5});
  ```


## Dir

管理目录，在调用Dir的方法前，需要先通过[fileio.opendirSync](#fileio.opendirsync)方法来构建一个Dir实例。


### readSync

readSync(): Dirent

同步读取下一个目录项。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [Dirent](#dirent) | 表示一个目录项。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let dirent = dir.readSync();
  console.log(dirent.name);
  ```


### closeSync

closeSync(): void

用于关闭目录。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  dir.closeSync();
  ```


## Dirent

在调用Dirent的方法前，需要先通过[readSync](#readsync)方法来构建一个Dirent实例。


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 是 | 否 | 目录项的名称。 |


### isBlockDevice

isBlockDevice(): boolean

用于判断当前目录项是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是块特殊设备。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isBLockDevice = dir.readSync().isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

用于判断当前目录项是否是字符特殊设备。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是字符特殊设备。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isCharacterDevice = dir.readSync().isCharacterDevice(); 
  ```


### isDirectory

isDirectory(): boolean

用于判断当前目录项是否是目录。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是目录。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isDirectory = dir.readSync().isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

用于判断当前目录项是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是FIFO。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isFIFO = dir.readSync().isFIFO(); 
  ```


### isFile

isFile(): boolean

用于判断当前目录项是否是普通文件。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是普通文件。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isFile = dir.readSync().isFile(); 
  ```


### isSocket

isSocket(): boolean

用于判断当前目录项是否是套接字。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是套接字。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isSocket = dir.readSync().isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

用于判断当前目录项是否是符号链接。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前目录项是否是符号链接。 |

- 示例：
  ```
  let dir = fileio.opendirSync(dpath);
  let isSymbolicLink = dir.readSync().isSymbolicLink();
  ```
