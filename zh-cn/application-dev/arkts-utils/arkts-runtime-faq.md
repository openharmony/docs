# ArkTS运行时常见问题

## 方舟正则运算与预期输出结果不一致场景

如果使用方舟正则运算时结果与期望不符，请检查以下场景。

### 方舟正则运算对于\b处理与预期不一致

   ```ts
   let str = "\u2642";
   let res = str.replace(/\b/g, "/");
   console.log("res = " + res);
   // 期望输出: res = ♂
   // 实际输出: res = /♂/
   ```

   规避方案：暂无。
   > **说明：**
   > 
   > 正则匹配\b（单词边界）遇到某些ASCII编码之外的字符时，会将其当成ASCII字符来处理，从而将不是单词边界匹配识别成单词边界。

### 方舟正则运算对于先行断言((?=pattern)或(?!pattern)) 嵌套在后行断言((?<=pattern)或(?<!pattern))内部的场景与预期不一致

   ```ts
   console.log('res:${"abcdef".match(/(?<=ab(?=c)cd)ef/)}');
   // 期望输出: res:ef
   // 实际输出: res:null
   ```

   规避方案：使用/(?<=abcd)ef/代替/(?<=ab(?=c)cd)ef/。

### 方舟正则运算对于大小写的处理与预期不一致

   ```ts
   let res = /\u{10400}/ui.test("\u{10428}");
   console.log("res = " + res);
   // 期望输出: res = true
   // 实际输出: res = false
   ```

   规避方案：暂无。

### 方舟正则运算/()/ug匹配时lastIndex与预期不一致

   ```ts
   let L = "\ud800";
   let T = "\udc00";
   let x = "x";
   let u = /()/ug;
   u.lastIndex = 1;
   u.exec(L + T + L + T);
   console.log("u.lastIndex = " + u.lastIndex);
   // 期望输出: u.lastIndex = 0
   // 实际输出: u.lastIndex = 1
   ```

   规避方案：暂无。

### 方舟正则运算[]内部使用'-'与预期不一致

   ```ts
   let str =  "a-b";
   let reg = /[+-\s]/;
   console.log("reg.exec(str) = " + reg.exec(str));
   // 期望输出: reg.exec(str) = -
   // 实际输出: reg.exec(str) = null
   ```

   规避方案：使用转义后的"-"。
   ```ts
   let str =  "a-b";
   let reg = /[+\-\s]/;
   console.log("reg.exec(str) = " + reg.exec(str));
   ```

### 方舟正则运算具名捕获组获取与预期不一致

   ```ts
   let reg = new RegExp("(a)(?<b>b)");
   let res = reg.exec("ab");
   console.log("JSON.stringify(res?.groups) = " + JSON.stringify(res?.groups));
   // 期望输出: JSON.stringify(res?.groups) = {"b":"b"}
   // 实际输出: JSON.stringify(res?.groups) = {"b":"a"}
   ```

   规避方案：计算具名捕获组位置获取具名捕获组匹配的内容。

   ```ts
   let reg = new RegExp("(a)(?<b>b)");
   let res = reg.exec("ab");
   console.log(JSON.stringify(res[2]));
   ```

### 方舟正则匹配使用'|'与预期不一致

   在使用正则匹配时，如果'|'前是一个空匹配，会导致'|'后的匹配不成功。

   ```ts
   let reg = /a(?:|x)$/;
   let res = reg.exec("ax");
   console.log("JSON.stringify(res) = " + JSON.stringify(res));
   // 期望输出: JSON.stringify(res) = ["ax"]
   // 实际输出: JSON.stringify(res) = null
   ```

   规避方案：使用reg2或reg3替换reg1。

   ```ts
   let reg1 = /a(?:|x)$/;
   let reg2 = /a(?:x)?$/;
   let reg3 = /a(?:x){0,1}$/;
   ```

## Async函数内部异常的处理机制

**场景**

如果在Async函数内部产生了异常，且没有使用catch捕获该异常，在ArkTS中不会导致进程退出。其本质是Async函数返回了一个rejected状态的Promise对象，没有被处理，使得Promise的rejected状态没有被捕获。Async函数内部的异常会变成 unhandledRejection，表现为异常未抛出。

**Async函数内部异常的捕获方式**

1. 使用[errorManager.on()](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror)捕获到Async函数产生的unhandledrejection事件，再通过编写errorManager.on()注册的回调函数，来进行异常处理操作。

   ```ts
      errorManager.on("unhandledRejection", (a:ESObject, b:Promise<ESObject>) => {
         console.log("Async test", a);
      })
   ```

2. 在Async函数内部，针对可能发生异常的代码块添加try-catch逻辑，直接捕获可能出现的异常。

> **注意：**
> 
> 注意必须在Async函数内部，外部无法捕获Async函数内部的异常，外部只能通过errorManager.on()监听。


**查看Async函数内部是否有异常的方式**

若开发者仅需要查看Async函数内部是否产生异常，首先需要在DevEco Studio终端执行以下hilog命令开启debug级别日志打印：

```shell
   hilog -b D
```

然后点击DevEco Studio下方HiLog选项卡，输入过滤条件“Throw error:”，即可查看到Async函数内产生的异常信息。
![alt text](image.png)