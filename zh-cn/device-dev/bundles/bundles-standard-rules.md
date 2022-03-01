# 开发规范<a name="ZH-CN_TOPIC_0000001051452141"></a>

-   [概述](#section16820114352316)
    -   [定义](#section123361236249)
    -   [Bundle划分原则](#section1918162512419)
    -   [Bundle依赖](#section1687484311240)

-   [Bundle构成](#section18351162611254)
    -   [代码文件](#section1575645102513)
    -   [说明文件](#section15300198132611)
    -   [元数据描述文件](#section10956525102613)

-   [Bundle管理](#section32061634104110)
    -   [依赖关系](#section37361058192610)
    -   [hpm操作命令参考](#section72383420271)

-   [Bundle版本](#section162921336288)
    -   [版本号命名规范](#section176561816172819)
    -   [版本发布](#section8683417284)

-   [发行版](#section243845052819)
-   [环境变量说明](#section19567181517299)

## 概述<a name="section16820114352316"></a>

本文档将介绍Bundle的基本概念以及如何按照规范定义Bundle。

### 定义<a name="section123361236249"></a>

OpenHarmony软件以bundle作为基本单元，从系统角度看，凡是运行在OpenHarmony上的软件都可以定义为Bundle；一般来讲，根据Bundle的应用范围，可以分为：

-   板级Bundle：如board、arch、mcu这些与设备硬件相关的Bundle。
-   系统Bundle：一组独立功能的集合，如内核、文件系统、框架等。
-   应用Bundle：直接面向用户提供服务的应用\(如wifi\_iot，ip\_camera\)。

从形式上看，Bundle是为复用而生，一切可以复用的模块都可以定义为Bundle，可以分为：

-   源代码
-   二进制
-   代码片段
-   发行版

### Bundle划分原则<a name="section1918162512419"></a>

原则上应尽可能划分为细颗粒度的Bundle，以满足最大限度的复用。主要考虑以下几点：

-   独立性：Bundle的功能应该相对独立，支持独立编译，可以单独对外提供接口和服务；
-   耦合性：如果Bundle必须依赖其他的Bundle，才能对外提供服务，应考虑和被依赖的Bundle合并为一个Bundle。
-   相关性：如果一组Bundle共同完成一项功能，且没有被其他Bundle依赖，未来也没有被依赖的可能，则可以考虑合并为一个Bundle。

### Bundle依赖<a name="section1687484311240"></a>

Bundle的依赖关系分为两种：必选依赖和可选依赖。

-   必选依赖：是指BundleA在完成某个功能时，必须引入BundleB，调用B的接口或服务配合才能完成。称B为A的必选依赖。
-   可选依赖：是在BundleA在完成某个功能时，可以引入BundleC，也可以引入BundleD。C和D可以相互替换，称C和D为A的可选依赖。

## Bundle构成<a name="section18351162611254"></a>

一个Bundle包一般包含如下内容：

-   Bundle包的代码或库（src目录下的代码文件）
-   ohos\_bundles文件夹（存放依赖的Bundle，安装Bundle时自动生成，无需提交到代码库）
-   Bundle包的说明文件\(README.md\)
-   Bundle包元数据声明文件\(bundle.json\)
-   开源许可文件\(LICENSE\)

    ```
    my-bundle
       |_ohos_bundles
       |_src
       |_bundle.json
       |_README.md
       |_LICENSE
    ```


### 代码文件<a name="section1575645102513"></a>

Bundle的代码文件和普通的代码目录没有差异。但要注意的是，Bundle中对外暴露的接口（头文件），会被其他Bundle所引用，需要单独在bundle.json的dirs中声明。

### 说明文件<a name="section15300198132611"></a>

README.md，为markdown格式的描述关于Bundle自述说明文件。（[语法参考](https://www.markdownguide.org/getting-started/)\)

为了帮助他人在hpm上找到该Bundle，并更方便的使用它，在Bundle的根目录中包含一个README文件。

README文件可能包括如何安装，配置和使用Bundle包中的实例代码说明，以及可能会对用户有所帮助的任何其他信息。

每个Bundle的自述文件将显示在hpm系统的Bundle详情页面的描述中。

### 元数据描述文件<a name="section10956525102613"></a>

bundle.json文件是对当前Bundle的元数据描述，每个Bundle中必须包含一个bundle.json文件。

```
{
  "name": "@myorg/demo-bundle",
  "version": "1.0.0",
  "license": "MIT",
  "description": "bundle description",
  "keywords": ["hos"],
  "tags": ["applications", "drivers"],
  "author": {"name":"","email":"","url":""},
  "contributors":[{"name":"","email":"","url":""},{"name":"","email":"","url":""}],
  "homepage": "http://www.foo.bar.com",
  "repository": "https://git@gitee.com:foo/bar.git",
  "publishAs": "code-segment",
  "segment":{
     "destPath":"/the/dest/path"
  },
  "dirs": {
    "src": ["src/**/*.c"],
    "headers": ["headers/**/*.h"],
    "bin": ["bin/**/*.o"]
  },
  "scripts": {
    "build": "make"
  },
  "envs": {},
  "ohos": {
    "os": "2.0.0",
    "board": "hi3516",
    "kernel": "liteos-a"
  },
 "rom": "10240",
 "ram": "1024",
 "dependencies": {
    "@myorg/net":"1.0.0"
 }
}
```

bundle.json文件具有如下功能：

-   name：定义Bundle的名称，放到组织下， 以@开头，/分割，如：@myorg/mybundle

-   version：定义Bundle版本号，如1.0.0，需满足semver的标准。

-   description：一句话对Bundle进行简要的描述。
-   dependencies：定义Bundle的依赖Bundle。

-   envs： 定义Bundle编译时所需要的参数，包括全局参数以及依赖所需的参数。

-   scripts：定义在当前Bundle下能够执行的命令（如编译，构建，测试，烧录等）。

-   publishAs：定义Bundle的发布类型（source：源码，binary：二进制，distribution：发行版，code-segment：代码片段）。

-   segment: 仅针对code-segment类型的Bundle，定义Bundle的目标路径（即安装后，Bundle包中包含的文件复制到的目标路径）
-   dirs：定义发布时打包的目录结构（如头文件）。

-   ram&rom：统计相关信息：预计占用ROM和RAM信息。
-   ohos：描述OpenHarmony系统版本、开发板及内核的匹配关系（多个请用英文逗号的“,”分割）。
-   定义其他扩展信息：作者，主页，代码仓库，许可协议，标签，关键字。
-   对于发行版类型，还有个base，可以定义继承自的发行版。

## Bundle管理<a name="section32061634104110"></a>

### 依赖关系<a name="section37361058192610"></a>

生成基础bundle.json以后，需要继续添加Bundle依赖来实现更复杂的功能。此时需要知道所依赖Bundle的名称和版本号，并且把它们定义在bundle.json里面的dependencies字段中。

```
{
    "name": "my-bundle",
    "version": "1.0.0",
    "dependencies": {
        "net": "1.0.0"
    }
}
```

上述示例中，my-bundleBundle依赖于net 1.0.0Bundle。在全局安装了 hpm CLI 工具之后，执行如下命令可以从远端仓库获取到依赖：

```
hpm install 
```

依赖获取以后，会保存到当前Bundle根目录下到ohos\_bundles文件夹中。Bundle以及依赖之间会形成一个依赖关系的树状结构。全局安装了 hpm CLI 工具之后，在Bundle根目录下执行如下命令：

```
username@server MINGW64 /f/showcase/demo/demo
$ hpm list
+--demo@1.0.0
| +--@demo/media@1.0.2
| +--@demo/sport_hi3518ev300_liteos_a@1.0.0
| | +--@demo/app@4.0.1
| | | +--@demo/build@4.0.1
| | | +--@demo/arm_harmonyeabi_gcc@4.0.0   
| | +--@demo/liteos_a@4.0.0
| | | +--@demo/third_party_fatfs@4.0.0     
| | | +--@demo/arm_harmonyeabi_gcc@4.0.0   
| | +--@demo/init@4.0.0
| | +--@demo/dist_tools@4.0.0
```

还可以使用可视化的形式，来查看当前Bundle的依赖关系，执行如下命令：

```
hpm ui
```

会在本地启动一个web服务（默认会打开浏览器并进入项目页），点击侧边栏的项目依赖图标，打开页面，可以看到项目的依赖Bundle列表，点击右侧按钮切换到树状视图，就可以看到依赖关系的图形化展示\(如下图\)。

**图 1**  Bundle包依赖关系图<a name="fig4306113315312"></a>  


![](figure/zh-cn_image_0000001188040429.png)

### hpm操作命令参考<a name="section72383420271"></a>

Bundle的全生命周期管理，可以通过hpm命令工具进行操作，hpm的操作命令如下（详细帮助可以执行 hpm -h学习）：

**表 1**  hpm操作命令

<a name="table10510164515371"></a>
<table><thead align="left"><tr id="row125101745103718"><th class="cellrowborder" valign="top" width="20.95209520952095%" id="mcps1.2.4.1.1"><p id="p1451014454371"><a name="p1451014454371"></a><a name="p1451014454371"></a>命令类别</p>
</th>
<th class="cellrowborder" valign="top" width="30.623062306230626%" id="mcps1.2.4.1.2"><p id="p17510144553716"><a name="p17510144553716"></a><a name="p17510144553716"></a>命令行</p>
</th>
<th class="cellrowborder" valign="top" width="48.42484248424842%" id="mcps1.2.4.1.3"><p id="p65102452371"><a name="p65102452371"></a><a name="p65102452371"></a>含义说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row25106453375"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p151044514378"><a name="p151044514378"></a><a name="p151044514378"></a>版本查询</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p1653795113472"><a name="p1653795113472"></a><a name="p1653795113472"></a>hpm -V 或 hpm --version</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p399295684713"><a name="p399295684713"></a><a name="p399295684713"></a>查看hpm-cli 版本号。</p>
</td>
</tr>
<tr id="row651017455374"><td class="cellrowborder" rowspan="2" align="left" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p551054516372"><a name="p551054516372"></a><a name="p551054516372"></a>帮助查询</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p18648167124812"><a name="p18648167124812"></a><a name="p18648167124812"></a>hpm -h 或 hpm --version</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1464811794817"><a name="p1464811794817"></a><a name="p1464811794817"></a>查看命令列表及帮助。</p>
</td>
</tr>
<tr id="row1751016452379"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16778111111487"><a name="p16778111111487"></a><a name="p16778111111487"></a>hpm -h</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1877811154818"><a name="p1877811154818"></a><a name="p1877811154818"></a>查看命令帮助。</p>
</td>
</tr>
<tr id="row2511945123715"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p3955174864810"><a name="p3955174864810"></a><a name="p3955174864810"></a>创建</p>
<p id="p14511184518374"><a name="p14511184518374"></a><a name="p14511184518374"></a></p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p2046811558481"><a name="p2046811558481"></a><a name="p2046811558481"></a>hpm init bundle</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1646818557481"><a name="p1646818557481"></a><a name="p1646818557481"></a>创建Bundle工程。</p>
</td>
</tr>
<tr id="row351184593713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18991313496"><a name="p18991313496"></a><a name="p18991313496"></a>hpm init -t template</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p109912104911"><a name="p109912104911"></a><a name="p109912104911"></a>根据模板创建脚手架工程。</p>
</td>
</tr>
<tr id="row1751164511374"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1351111454374"><a name="p1351111454374"></a><a name="p1351111454374"></a>安装</p>
<p id="p251144513715"><a name="p251144513715"></a><a name="p251144513715"></a></p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p8896182914913"><a name="p8896182914913"></a><a name="p8896182914913"></a>hpm install 或hpm i</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1289692919493"><a name="p1289692919493"></a><a name="p1289692919493"></a>安装bundle.json中依赖的Bundle。</p>
</td>
</tr>
<tr id="row15511194563712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17917436134911"><a name="p17917436134911"></a><a name="p17917436134911"></a>hpm install bundle@version</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1891723611494"><a name="p1891723611494"></a><a name="p1891723611494"></a>安装指定Bundle版本。</p>
</td>
</tr>
<tr id="row21051110155011"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1630384435010"><a name="p1630384435010"></a><a name="p1630384435010"></a>卸载</p>
<p id="p83417161509"><a name="p83417161509"></a><a name="p83417161509"></a></p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p288195017502"><a name="p288195017502"></a><a name="p288195017502"></a>hpm uninstall bundle</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p2088450165014"><a name="p2088450165014"></a><a name="p2088450165014"></a>删除depedencies依赖的Bundle。</p>
</td>
</tr>
<tr id="row73341617507"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p934161613508"><a name="p934161613508"></a><a name="p934161613508"></a>hpm remove 或hpm rm bundlename</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p234111685016"><a name="p234111685016"></a><a name="p234111685016"></a>删除depedencies依赖的Bundle。</p>
</td>
</tr>
<tr id="row166449214501"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p8645421125016"><a name="p8645421125016"></a><a name="p8645421125016"></a>查看</p>
<p id="p12645202115014"><a name="p12645202115014"></a><a name="p12645202115014"></a></p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p679412535211"><a name="p679412535211"></a><a name="p679412535211"></a>hpm list 或者 hpm ls</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p07941451526"><a name="p07941451526"></a><a name="p07941451526"></a>显示当前Bundle/发行版所有的Bundle树。</p>
</td>
</tr>
<tr id="row1764552105017"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p035818131525"><a name="p035818131525"></a><a name="p035818131525"></a>hpm dependencies</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19358413135217"><a name="p19358413135217"></a><a name="p19358413135217"></a>生成当前Bundle/发行版依赖关系数据（在hpm ui也集成了该命令的调用，可以图形化的展示）</p>
</td>
</tr>
<tr id="row1553428145020"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p353202845014"><a name="p353202845014"></a><a name="p353202845014"></a>搜索</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p1423903005211"><a name="p1423903005211"></a><a name="p1423903005211"></a>hpm search name</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p17239163018524"><a name="p17239163018524"></a><a name="p17239163018524"></a>搜索Bundle，--json，可以以json格式输出 -type 可以设置搜索Bundle的类型，包括bundle,distribution,code-segment三种。</p>
</td>
</tr>
<tr id="row135482855018"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p38201311174016"><a name="p38201311174016"></a><a name="p38201311174016"></a>设置hpm配置项</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p279915013522"><a name="p279915013522"></a><a name="p279915013522"></a>hpm config set key value</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p157991450205211"><a name="p157991450205211"></a><a name="p157991450205211"></a>设置配置值，如服务器地址，网络代理。</p>
</td>
</tr>
<tr id="row454172810509"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p111125615215"><a name="p111125615215"></a><a name="p111125615215"></a>hpm config delete key</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p171156105215"><a name="p171156105215"></a><a name="p171156105215"></a>删除配置。</p>
</td>
</tr>
<tr id="row3925233115011"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1250314020555"><a name="p1250314020555"></a><a name="p1250314020555"></a>更新</p>
<p id="p59251633105018"><a name="p59251633105018"></a><a name="p59251633105018"></a></p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p1127981305516"><a name="p1127981305516"></a><a name="p1127981305516"></a>hpm update</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p427971311555"><a name="p427971311555"></a><a name="p427971311555"></a>更新当前Bundle依赖的Bundle的版本。</p>
</td>
</tr>
<tr id="row692503385015"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p627961317557"><a name="p627961317557"></a><a name="p627961317557"></a>hpm check-update</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3279121315557"><a name="p3279121315557"></a><a name="p3279121315557"></a>检查依赖的Bundle版本是否有更新。</p>
</td>
</tr>
<tr id="row1925173385019"><td class="cellrowborder" rowspan="2" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p2925133305014"><a name="p2925133305014"></a><a name="p2925133305014"></a>编译</p>
<p id="p692515335501"><a name="p692515335501"></a><a name="p692515335501"></a></p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p2058919655611"><a name="p2058919655611"></a><a name="p2058919655611"></a>hpm build</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1958920625619"><a name="p1958920625619"></a><a name="p1958920625619"></a>编译Bundle/发行版。</p>
</td>
</tr>
<tr id="row18925233115016"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1958912618563"><a name="p1958912618563"></a><a name="p1958912618563"></a>hpm dist</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2058936115611"><a name="p2058936115611"></a><a name="p2058936115611"></a>针对发行版（distribution），发行版编译构建（依赖bundle.json的scripts中的dist脚本)。</p>
</td>
</tr>
<tr id="row59261233155013"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p3926123305011"><a name="p3926123305011"></a><a name="p3926123305011"></a>打包</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p1785810219574"><a name="p1785810219574"></a><a name="p1785810219574"></a>hpm pack</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1485872165714"><a name="p1485872165714"></a><a name="p1485872165714"></a>本地Bundle打包依赖。</p>
</td>
</tr>
<tr id="row1592653305016"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p84251810125716"><a name="p84251810125716"></a><a name="p84251810125716"></a>烧录</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p7973616175716"><a name="p7973616175716"></a><a name="p7973616175716"></a>hpm run flash</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p20973111612575"><a name="p20973111612575"></a><a name="p20973111612575"></a>烧录固件（依赖bundle.json的scripts中的flash脚本）。</p>
</td>
</tr>
<tr id="row992615339504"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1225172310576"><a name="p1225172310576"></a><a name="p1225172310576"></a>发布</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p198081455105712"><a name="p198081455105712"></a><a name="p198081455105712"></a>hpm publish</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p880885516574"><a name="p880885516574"></a><a name="p880885516574"></a>发布Bundle，发布的Bundle在仓库中必须唯一，且版本唯一(需要账号登录）。</p>
</td>
</tr>
<tr id="row5926333135014"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p39267336504"><a name="p39267336504"></a><a name="p39267336504"></a>执行扩展命令</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p9933172588"><a name="p9933172588"></a><a name="p9933172588"></a>hpm run</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p18933476584"><a name="p18933476584"></a><a name="p18933476584"></a>执行bundle.json文件中定义的scripts脚本命令，支持多个命令可用 &amp;&amp; 连接。</p>
</td>
</tr>
<tr id="row51431053122610"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p7143155332618"><a name="p7143155332618"></a><a name="p7143155332618"></a>解压包</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p71438531269"><a name="p71438531269"></a><a name="p71438531269"></a>hpm extract</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1214317539267"><a name="p1214317539267"></a><a name="p1214317539267"></a>解压文件. 支持格式'zip','tar','tgz' 和'.tar.gz'</p>
</td>
</tr>
<tr id="row2144175352615"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p014425315267"><a name="p014425315267"></a><a name="p014425315267"></a>启动图形化界面</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p614411533260"><a name="p614411533260"></a><a name="p614411533260"></a>hpm ui</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p13144135382611"><a name="p13144135382611"></a><a name="p13144135382611"></a>本地启动HPM UI，可通过-p参数指定端口，Windows平台下会启动默认的浏览器打开</p>
</td>
</tr>
<tr id="row616119173278"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1716118170279"><a name="p1716118170279"></a><a name="p1716118170279"></a>多语言切换</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p171616172277"><a name="p171616172277"></a><a name="p171616172277"></a>hpm lang</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1216121752712"><a name="p1216121752712"></a><a name="p1216121752712"></a>切换中英文操作界面（同时支持命令行和UI）</p>
</td>
</tr>
<tr id="row81611717182720"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1816181792712"><a name="p1816181792712"></a><a name="p1816181792712"></a>转换为hpm包格式</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p616191713276"><a name="p616191713276"></a><a name="p616191713276"></a>hpm x2h</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1116121712711"><a name="p1116121712711"></a><a name="p1116121712711"></a>将一个maven格式或npm格式包转换成hpm的包格式，并发布到HPM</p>
</td>
</tr>
<tr id="row1177713643711"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p877719363374"><a name="p877719363374"></a><a name="p877719363374"></a>代码段还原或清理</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p6778236153710"><a name="p6778236153710"></a><a name="p6778236153710"></a>hpm code clean|restore</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p1277843613376"><a name="p1277843613376"></a><a name="p1277843613376"></a>针对依赖的代码段(code-segment)Bundle，执行清理或还原操作（即根据segment.destPath执行拷贝/删除操作）</p>
</td>
</tr>
<tr id="row122864915206"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p1529124912207"><a name="p1529124912207"></a><a name="p1529124912207"></a>生成秘钥</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p9291492204"><a name="p9291492204"></a><a name="p9291492204"></a>hpm gen-keys</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p429249182012"><a name="p429249182012"></a><a name="p429249182012"></a>生成公钥/私钥对，将公钥配置到HPM服务端，可以实现hpm-cli 免密登录，发布Bundle。</p>
</td>
</tr>
<tr id="row3556450102011"><td class="cellrowborder" valign="top" width="20.95209520952095%" headers="mcps1.2.4.1.1 "><p id="p35561850172015"><a name="p35561850172015"></a><a name="p35561850172015"></a>生成第三方开源说明</p>
</td>
<td class="cellrowborder" valign="top" width="30.623062306230626%" headers="mcps1.2.4.1.2 "><p id="p1155625018209"><a name="p1155625018209"></a><a name="p1155625018209"></a>hpm gen-notice</p>
</td>
<td class="cellrowborder" valign="top" width="48.42484248424842%" headers="mcps1.2.4.1.3 "><p id="p11557175015205"><a name="p11557175015205"></a><a name="p11557175015205"></a>根据每个Bundle的说明，生成一份合并后的第三方开源说明的合并文件。</p>
</td>
</tr>
</tbody>
</table>

## Bundle版本<a name="section162921336288"></a>

### 版本号命名规范<a name="section176561816172819"></a>

名称需要为全小写字母，中间可以使用中划线或者下划线分隔。比如 "bundle", "my\_bundle"。

版本号的格式为 "主版本号.次版本号.修订号" 或 "主版本号.次版本号.修订号-先行版本号"，比如 "1.0.0"， "1.0.0-beta"，详细规格可以参考  [https://semver.org](https://semver.org/)。

### 版本发布<a name="section8683417284"></a>

为了使Bundle能被其他开发者使用，Bundle需要上传到远端仓库。Bundle上传使用如下命令：

```
hpm publish
```

命令执行以后，系统会对的整个依赖关系进行检查，下载缺失依赖Bundle。依赖检查完成后，如果发布类型为binary，系统会对整个Bundle进行编译，生成二进制文件，然后打包上传。如果使其他上传类型，则直接根据定义的打包规则进行打包，然后上传。

注意：发布Bundle需要用户账号登录，需要先拥有hpm的系统账号后，并注册组织，申请组织认证通过后，才拥有发布的权限。

## 发行版<a name="section243845052819"></a>

发行版通常是将一系列Bundle组合起来，成为编译可以运行的OpenHarmony解决方案镜像，里面包含了多个依赖的Bundle，以及脚本，用于描述如何完整编译、链接这些Bundle。

发行版本身通常不需要包含功能实现代码，仅包含bundle.json描述（设置publishAs为distribution）和一些编译脚本组成。

因为发行版编译的过程需要系统提供环境变量，所以发行版使用scripts脚本中内置的dist命令：

```
{
    "publishAs":"distribution",
    "scripts": {
        "dist": "script compile command"
    }
}
```

编译执行使用如下命令：

```
hpm dist 
```

重新定义一个发行版所具有的功能是一个复杂的过程，所以系统允许对发行版进行继承，从而在现有功能的基础上进行定制。继承发行版需要在bundle.json中定义base字段。

```
{
    "base": {
        "name": "dist_wifi_iot",
        "version": "1.0.0"
    }
}
```

上述定义表明当前Bundle继承自发行版Bundledist-wifi-iot 1.0.0。

发行版由很多的依赖Bundle组成，通过bundle.json中的dependencies段来描述，有些依赖是必须的，有些依赖则是根据可以需求增加或删除的。bundle.json中名称前带有？的依赖表示可选依赖，继承它的发行版，可以移除掉该可选Bundle，再增加别的Bundle进行替换。

```
{
    "dependencies": {
        "?my_bundle": "1.0.0"
    }
}
```

上述声明表示my\_bundle依赖可以被移除。如果想要移除my\_bundle，在上层依赖方需要使用excludes关键字来进行定义

```
{
    "excludes": [ "my_bundle" ]
}
```

依赖被移除后，就不会参入Bundle的构建过程。只有标记为可选的依赖才能够被移除，强行移除未被标记的依赖会出现错误提示。

## 环境变量说明<a name="section19567181517299"></a>

Bundle在编译的过程中需要依赖系统提供的环境变量来自定义输出，链接所需二进制文件等等。这里提出的环境变量均指根据需求把所需变量注入脚本执行的上下文中。所以在脚本中可以直接获取到变量的值。下面介绍当前系统存在的几种环境变量。

全局变量由bundle.json中的envs属性来定义。整个Bundle中的依赖都可以获取到全局变量定义的值。

```
{
    "envs": {
        "compileEnv": "arm"
    }
}
```

不同Bundle在引入依赖的过程中可以传入不同的参数，从而使依赖的编译可以满足当前Bundle的需求。依赖中定义的参数可以在对应依赖脚本执行的上下文中获取到。

```
{
    "dependencies": {
        "my-bundle": {
            "version": "1.0.0",
            "mode": "debug"
        }
    }
}
```

Bundle在链接二进制文件的时候，需要知道二进制文件在依赖中的路径，所以依赖的路径会作为环境变量传入编译Bundle中。

传入的环境变量的格式为DEP\_BundleName，BundleName为依赖的名称，例如 DEP\_first\_bundle。

依赖中可以定义标签，对引入的依赖进行分组。在脚本中可以根据标签，获得这一组依赖的路径。定义的标签以\#开头，具体定义的方式为：

```
{
    "dependencies": {
        "#tool": {
            "first-bundle": "1.0.0",
            "second-bundle": "1.0.0"
        },
        "#drivers": {
            "xx-bundle": "1.0.0",
            "yy-bundle": "1.0.0"
        }
    }
}
```

系统中存在两个固定环境变量：

-   DEP\_OHOS\_BUNDLES：表示ohos\_bundles文件夹所在的路径。
-   DEP\_BUNDLE\_BASE：表示最外层Bundle的路径。

