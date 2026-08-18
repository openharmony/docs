# SourceMap Splitter工具
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @jokerxd-liu-->
<!--Designer: @huyunhui1; @k1ngqaquuu-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 概述

DevEco Studio编译构建后，会将各模块内所有源文件的SourceMap信息打包进一个聚合SourceMap文件`sourceMaps.map`中。由于该文件未采用标准的[SourceMap v3](https://tc39.es/ecma426/#sec-source-map-format)格式，Chrome DevTools、`source-map`库等标准工具无法直接识别，给开发者还原崩溃堆栈、定位源码带来了困难。

SourceMap Splitter是一款专为此场景设计的命令行工具，可将聚合的`sourceMaps.map`快速拆分为独立的、符合SourceMap v3规范的`.map`文件，并自动按源码目录结构导出，便于使用标准工具链定位问题。该工具零外部运行时依赖，从[SourceMap拆分工具](https://gitcode.com/OpenHarmonyToolkitsPlaza/OpenHarmony-SourceMap-Splitter/releases)下载单文件`split-sourcemaps.js`后即可直接运行。

## 环境要求

使用本工具前，请确认运行环境满足以下要求：

- 操作系统：支持 Windows、macOS、Linux 全平台。
- 运行环境：Node.js 20 及以上版本。
- 依赖：零外部运行时依赖，无需安装任何第三方包。
- 工具文件：单一 JS 文件`split-sourcemaps.js`，下载后无需额外配置即可直接运行。

## 工具规格

本章节介绍工具的命令格式、参数、输入文件路径、输出目录规则及退出码。

### 拆分命令

读取一个或多个模块的聚合SourceMap文件，将其拆分为独立的、符合SourceMap v3规范的`.map`文件，并按源码目录结构输出。指定多个模块时，拆分结果会合并到同一输出目录，并自动跨模块去重。命令格式如下：

```bash
node split-sourcemaps.js [--project <path>] [--module <name>] [--output <path>]
```

**参数说明**：

| 选项 | 必选 | 描述 |
| -------- | --- | ----------------- |
| --project &lt;path&gt; | 否 | OpenHarmony项目根目录。<br>参数缺省时，默认为当前执行命令的目录。 |
| --module &lt;name&gt; | 否 | 模块名，支持指定多个。可使用逗号分隔（如`entry,feature`），也可重复传入`--module`，两种写法等价，并按首次出现顺序自动去重。单个模块名不能为空或`.`，不能包含`..`或路径分隔符（`/`、`\`），也不能为绝对路径。<br>参数缺省时，默认为`entry`。 |
| --output &lt;path&gt; | 否 | 拆分结果的输出目录，支持绝对路径和相对路径。<br>参数缺省时，默认为`.split-sourcemaps`。 |
| --help、-h | 否 | 显示帮助信息。 |

### 输入文件路径

工具会在以下路径查找由DevEco Studio构建生成的聚合SourceMap文件：

```text
{project}/{module}/build/default/outputs/default/mapping/sourceMaps.map
```

### 输出目录安全规则

为避免误删用户数据，工具在写入输出目录时遵循以下规则：

- 输出目录不存在时，自动创建。
- 输出目录存在且为空时，直接写入。
- 输出目录由本工具创建（目录中包含`.split-sourcemaps-manifest`标记文件）时，会先清空再写入，以保证重复运行结果的一致性。
- 输出目录已存在、非空，且不是由本工具创建时，工具会拒绝清空并报错退出，此时需手动删除该目录，或通过`--output`指定其他目录。

### 退出码

工具执行结束后会返回退出码，用于反映本次执行的结果，可在脚本或CI流程中据此判断拆分是否成功。

| 退出码 | 说明 |
| -------- | ----------------- |
| 0 | 拆分成功。 |
| 1 | 发生错误，例如参数无效、项目目录或聚合SourceMap文件不存在、JSON解析失败、输出目录非空且非本工具创建等。 |

## 工具使用示例

### 基本用法

拆分`entry`模块的聚合SourceMap文件，使用默认输出目录`.split-sourcemaps`。

```bash
node split-sourcemaps.js --project /path/to/project --module entry
```

### 指定输出目录

通过`--output`将拆分结果输出到自定义目录，而非默认的`.split-sourcemaps`。该参数支持绝对路径与相对路径。

```bash
node split-sourcemaps.js --project /path/to/project --module entry --output ./sourcemap-output
```

### 在项目根目录下直接运行

`--project`缺省时默认为当前目录，`--module`缺省时默认为`entry`，因此在项目根目录下可直接运行。

```bash
node split-sourcemaps.js
```

### 一次拆分多个模块

通过逗号分隔或重复`--module`指定多个模块，两种写法等价，拆分结果会合并到同一输出目录。

```bash
# 以下两种写法等价，选择其一即可
# 写法一：逗号分隔
node split-sourcemaps.js --project /path/to/project --module entry,feature,library
# 写法二：重复传入--module
node split-sourcemaps.js --project /path/to/project --module entry --module feature
```

由于`entry`等模块的聚合SourceMap文件通常包含其所依赖模块的源映射，不同模块之间可能出现指向同一源文件的重复条目。工具会按模块的给定顺序自动去重：首个出现的条目写入，后续指向相同输出路径的条目被跳过。若后续模块存在相同路径但内容不同的条目，工具会在标准错误中打印`WARNING: potential version conflict ...`提示，但不会中断，仍以首个为准。

此外，若任一指定模块缺少构建产物，工具会在写入任何文件之前一次性列出全部缺失的模块并报错退出，不会破坏已有的输出目录。

### 参考输出

拆分成功后，标准输出会打印拆分的条目数与输出目录：

```bash
Split 5/5 sourcemap entries to .split-sourcemaps
```

其中`5/5`表示聚合SourceMap文件共有5个条目，且全部拆分成功。如果部分条目的路径无法解析或存在重复，工具会跳过这些条目并在标准错误中给出提示，此时成功数会小于总数。

一次拆分多个模块时，标准输出会额外打印参与拆分的模块列表；若发生跨模块去重，还会打印被去重的条目数：

```bash
Split 8/10 sourcemap entries to .split-sourcemaps
Modules: entry, feature
Deduplicated 2 cross-module path(s) (first module wins).
```

### 输出结构示例

假设输入聚合SourceMap文件`sourceMaps.map`中包含以下5个条目：

```text
sourceMaps.map
├── entry|entry|1.0.0|src/main/ets/pages/Index.ts
├── entry|entry|1.0.0|src/main/ets/entryability/EntryAbility.ts
├── entry|library|2.0.0|src/main/ets/components/MainPage.ts
├── entry|entry|1.0.0|generated/ets/routerMap.ts
└── entry|entry|1.0.0|src/main/ets/utils/Helper.no-sources.ts
```

拆分后将按模块与源码目录结构生成独立的`.map`文件：

```text
.split-sourcemaps/
├── entry/
│   ├── src/main/ets/pages/Index.ts.map
│   ├── src/main/ets/entryability/EntryAbility.ts.map
│   ├── generated/ets/routerMap.ts.map
│   └── src/main/ets/utils/Helper.no-sources.ts.map
└── library/
    └── src/main/ets/components/MainPage.ts.map
```

> **输出文件命名规则**：每个条目的输出文件在其原始源文件名的基础上，于原始扩展名后追加`.map`。例如源文件`Index.ts`对应`Index.ts.map`，`Helper.no-sources.ts`对应`Helper.no-sources.ts.map`，即原扩展名保留不变，仅在末尾追加`.map`。

## 常见问题

### 找不到聚合SourceMap文件

**问题现象**<br>
工具运行时报错`Aggregated sourcemap not found for ... module(s): ...`。<br>
**可能原因**<br>
项目尚未构建，或`--project`、`--module`参数不正确，导致一个或多个指定模块的路径下不存在聚合SourceMap文件。<br>
**处理措施**<br>
先使用DevEco Studio完成模块构建，并确认`--project`指向项目根目录、`--module`为正确的模块名。

### 项目目录不存在

**问题现象**<br>
工具运行时报错`Project directory does not exist: ...`。<br>
**可能原因**<br>
`--project`指定的目录不存在。<br>
**处理措施**<br>
确认`--project`参数为有效的项目根目录路径。

### 模块名非法

**问题现象**<br>
工具运行时报错`Invalid module name: ...`。<br>
**可能原因**<br>
`--module`参数为`.`、包含`..`、包含路径分隔符（`/`、`\`）或为绝对路径。非法示例：`.`、`..`、`my/module`、`/entry`、`C:\entry`。<br>
**处理措施**<br>
将`--module`修改为不含路径分隔符的合法模块名，例如`entry`。

### 输出目录非空且非本工具创建

**问题现象**<br>
工具运行时报错`Output directory is not empty and was not created by this tool: ...`。<br>
**可能原因**<br>
为防止误删用户数据，对于非空、且不是由本工具生成的目录，工具会拒绝清空。<br>
**处理措施**<br>
手动删除该目录，或通过`--output`指定一个空目录或专门用于存放输出的目录。

### 聚合SourceMap文件解析失败

**问题现象**<br>
工具运行时报错`Failed to parse aggregated sourcemap: ...`或`Aggregated sourcemap must be a JSON object ...`。<br>
**可能原因**<br>
聚合SourceMap文件内容不是合法的JSON对象，文件可能损坏或被截断。<br>
**处理措施**<br>
重新使用DevEco Studio构建项目以生成完整的聚合SourceMap文件。

### 部分条目被跳过

**问题现象**<br>
拆分成功，但标准错误中出现`Skipping entry with unresolvable path ...`或`Skipping duplicate output path ...`，且打印的拆分数量小于总数。<br>
**可能原因**<br>
个别条目的路径无法解析，或多个条目还原后映射到相同的输出路径，工具会跳过这些条目。<br>
**处理措施**<br>
这属于工具的正常容错处理，被跳过的条目不会影响其余条目的拆分结果。如需排查具体条目，可参考标准错误中提示的`key`信息。
