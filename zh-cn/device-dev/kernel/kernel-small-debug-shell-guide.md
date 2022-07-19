# Shell命令开发指导

新增Shell命令的典型开发流程如下：

1. 包含如下头文件：

     
   ```
   #include "shell.h"
   #include "shcmd.h"
   ```

2. 注册命令。用户可以选择静态注册命令方式和系统运行时动态注册命令方式，静态注册命令方式一般用在系统常用命令注册，动态注册命令方式一般用在用户命令注册。

   1. 静态注册命令方式：

       1. 通过宏的方式注册。
           这个宏的原型为：

             
           ```
           SHELLCMD_ENTRY(l, cmdType, cmdKey, paraNum, cmdHook)
           ```

             **表1** SHELLCMD_ENTRY参数详解
           
           | 参数 | 描述 | 
           | -------- | -------- |
           | l | 静态注册全局变量名（注意：不与系统中其他symbol重名）。 | 
           | cmdType | 命令类型：<br/>-&nbsp;CMD_TYPE_EX：不支持标准命令参数输入，会把用户填写的命令关键字屏蔽掉，例如：输入ls&nbsp;&nbsp;/ramfs，传入给注册函数的参数只有/ramfs，而ls命令关键字并不会被传入。<br/>-&nbsp;CMD_TYPE_STD：支持的标准命令参数输入，所有输入的字符都会通过命令解析后被传入。 | 
           | cmdKey | 命令关键字，函数在Shell中访问的名称。 | 
           | paraNum | 调用的执行函数的入参最大个数，暂不支持。 | 
           | cmdHook | 命令执行函数地址，即命令实际执行函数。 | 

           如：

             
           ```
           SHELLCMD_ENTRY(ls_shellcmd,  CMD_TYPE_EX, "ls", XARGS,  (CMD_CBK_FUNC)osShellCmdLs)
           ```
       2. 在build/mk/liteos_tables_ldflags.mk中添加相应选项：
           如：上述“ls”命令注册时，需在build/mk/liteos_tables_ldflags.mk中添加“-uls_shellcmd”。其中-u后面跟SHELLCMD_ENTRY的第一个参数。
   2. 动态注册命令方式：

       注册函数原型：

         
       ```
       UINT32 osCmdReg(CmdT ype cmdType, CHAR *cmdKey, UINT32 paraNum, CmdCallBackFunc cmdProc)
       ```

         **表2** UINT32 osCmdReg参数详解
       
       | 参数 | 描述 | 
       | -------- | -------- |
       | cmdType | 命令类型：<br/>-&nbsp;CMD_TYPE_EX：不支持标准命令参数输入，会把用户填写的命令关键字屏蔽掉，例如：输入ls&nbsp;&nbsp;/ramfs，传入给注册函数的参数只有/ramfs，而ls命令关键字并不会被传入。<br/>-&nbsp;CMD_TYPE_STD：支持的标准命令参数输入，所有输入的字符都会通过命令解析后被传入。 | 
       | cmdKey | 命令关键字，函数在Shell中访问的名称。 | 
       | paraNum | 调用的执行函数的入参最大个数，暂不支持该参数；当前为默认值XARGS(0xFFFFFFFF)。 | 
       | cmdHook | 命令执行函数地址，即命令实际执行函数。 | 

       如：

         
       ```
       osCmdReg(CMD_TYPE_EX, "ls", XARGS,  (CMD_CBK_FUNC)osShellCmdLs)
       ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 命令关键字必须是唯一的，也即两个不同的命令项不能拥有相同的命令关键字，否则只会执行其中一个。
   > 
   > Shell在执行用户命令时，如果存在多个命令关键字相同的命令，只会执行其中在"help"命令中排序在最前面的一个。

3. 添加内置命令函数原型。

     
   ```
   UINT32 osShellCmdLs(UINT32 argc,  CHAR **argv)
   ```

     **表3** osShellCmdLs参数说明
   
   | 参数 | 参数描述 | 
   | -------- | -------- |
   | argc | Shell命令中，参数个数。 | 
   | argv | 为指针数组，每个元素指向一个字符串，可以根据选择命令类型，决定是否要把命令关键字传入给注册函数。 | 

4. 输入Shell命令，有两种输入方式：

   - 在串口工具中直接输入Shell命令。
   - 在telnet工具中输入Shell命令（telnet使用方式详见[telnet](../kernel/kernel-small-debug-shell-net-telnet.md)）。
