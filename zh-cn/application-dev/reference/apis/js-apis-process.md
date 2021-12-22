# 获取进程相关的信息

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import process from '@ohos.process';
```


## 权限

无


## 属性

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| egid | number | 是 | 否 | 获取进程的有效组标识。 |
| euid | number | 是 | 否 | 获取进程的有效用户身份。 |
| gid | number | 是 | 否 | 获取进程的组标识。 |
| uid | number | 是 | 否 | 获取进程的用户标识。 |
| groups | number[] | 是 | 否 | 获取一个带有补充组id的数组。 |
| pid | number | 是 | 否 | 获取当前进程的pid。 |
| ppid | number | 是 | 否 | 获取当前进程的父进程的pid。 |


## ChildProcess

主进程可以获取子进程的标准输入输出，以及发送信号和关闭子进程。


### 属性

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 是 | 否 | 子进程的pid。 |
| ppid | number | 是 | 否 | 子进程的父进程的pid。 |
| exitCode | number | 是 | 否 | 子进程的退出码。 |
| killed | boolean | 是 | 否 | 父进程给子进程发信号是否成功。 |


### wait

wait(): Promise&lt;number&gt;

等待子进程运行结束，返回promise对象，其值为子进程的退出码。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | 异步返回子进程的退出码。 |

- 示例：
  ```
  import process from '@ohos.process';
  var child = process.runCmd('ls');
  var result = child.wait();
  result.then(val=>{
      console.log("result = " + val);
  })
  ```


### getOutput

getOutput(): Promise&lt;Uint8Array&gt;

获取子进程的标准输出。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Uint8Array&gt; | 异步返回标准输出的字节流。 |

- 示例：
  ```
  import process from '@ohos.process';
  var child = process.runCmd('ls');
  var result = child.wait();
  child.getOutput.then(val=>{
      console.log("child.getOutput = " + val);
  })
  ```


### getErrorOutput

getErrorOutput(): Promise&lt;Uint8Array&gt;

getErrorOutput函数用来获取子进程的标准错误输出。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Uint8Array&gt; | 异步返回标准错误输出的字节流。 |

- 示例：
  ```
  import process from '@ohos.process';
  var child = process.runCmd('madir test.text');
  var result = child.wait();
  child.getErrorOutput.then(val=>{
      console.log("child.getErrorOutput= " + val);
  })
  ```


### close

close():  void

关闭正在运行的子进程。

- 示例：
  ```
  import process from '@ohos.process';
  var child = process.runCmd('sleep 5; ls');
  child.close();
  ```


### kill

kill(signal: number | string): void

kill函数用来发送信号给子进程，结束指定进程。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | signal | number&nbsp;\|&nbsp;string | 是 | 数字或字符串。 |

- 示例：
  ```
  import process from '@ohos.process';
  var child = process.runCmd('sleep 5; ls');
  child.kill(9);
  ```


## process.runCmd

runCmd(command: string, options?: { timeout : number, killSignal ：number | string, maxBuffer : number }) : ChildProcess

通过runcmd可以fork一个新的进程来运行一段shell，并返回ChildProcess对象。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | command | string | 是 | shell命令。 |
  | options | Object | 否 | 相关选项参数。 |

  **表1** options
  
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | timeout | number | 否 | 子进程运行的ms数，当子进程运行时间超出此时间，则父进程发送killSignal信号给子进程。timeout默认为0。 |
  | killSignal | number&nbsp;&nbsp;\|&nbsp;string | 否 | 子进程运行时间超出timeout时，父进程发送killSignal&nbsp;信号给子进程。killSignal&nbsp;默认为'SIGTERM'。 |
  | maxBuffer | number | 否 | 子进程标准输入输出的最大缓冲区大小，当超出此大小时则终止子进程。maxBuffer默认1024\*1024。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [ChildProcess](#childprocess) | 子进程对象。 |

- 示例：
  ```
  import process from '@ohos.process';
  var child = process.runCmd('ls', { maxBuffer : 2 });
  var result = child.wait();
  child.getOutput.then(val=>{
      console.log("child.getOutput = " + val);
  }
  ```


## process.abort

abort(): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

- 示例：
  ```
  import process from '@ohos.process';
  process.abort();
  ```


## process.on

on(type: string, listener: EventListener): void

用该方法来存储用户所触发的事件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 存储事件的type。 |
  | listener | EventListener | 是 | 回调的事件。 |

  **表2** EventListener
  
  | 名称 | 说明 |
  | -------- | -------- |
  | EventListener&nbsp;=&nbsp;(evt:&nbsp;Object)&nbsp;=&gt;&nbsp;void | 用户存储的事件。 |

- 示例：
  ```
  import process from '@ohos.process';
  process.on("data", (e)=>{
      console.log("data callback");
  })
  ```


## process.off

off(type: string): boolean

用该方法来删除用户存储的事件。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 删除事件的type。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 事件是否删除成功。 |

- 示例：
  ```
  import process from '@ohos.process';
  process.on("data", (e)=>{
      console.log("data callback");
  })
  var result = process.off("data");
  ```


## process.exit

exit(code: number): void

用该方法终止程序，谨慎使用。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 进程的退出码。 |

- 示例：
  ```
  import process from '@ohos.process';
  process.exit(0);
  ```


## process.cwd

cwd(): string

用该方法获取进程的工作目录。

- 示例：
  ```
  import process from '@ohos.process';
  var path = process.cwd();
  ```


## process.chdir

chdir(dir: string): void

用该方法更改进程的当前工作目录。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dir | string | 是 | 路径。 |

- 示例：
  ```
  import process from '@ohos.process';
  process.chdir('/system');
  ```


## process.uptime

uptime(): number

获取当前系统已运行的秒数。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 当前系统已运行的秒数。 |

- 示例：
  ```
  import process from '@ohos.process';
  var time = process.uptime();
  ```


## process.kill

kill(pid: number，signal: number ): boolean

用该方法发送signal到指定的进程，结束指定进程。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | pid | number | 是 | 进程的id。 |
  | signal | number | 是 | 发送的信号。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 信号是否发送成功。 |

- 示例：
  ```
  import process from '@ohos.process'
  var pres = process.pid
  var result = that.kill(pres, 28)
  ```
