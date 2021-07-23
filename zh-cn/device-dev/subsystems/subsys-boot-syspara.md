# syspara系统属性组件<a name="ZH-CN_TOPIC_0000001063362360"></a>

-   [syspara系统接口说明](#section775916468231)
-   [开发实例](#section118404913233)

负责提供获取与设置操作系统相关的系统属性。

LiteOS-M内核和LiteOS-A内核的平台，包括：Hi3861平台，Hi3516DV300平台，Hi3518EV300平台。支持的系统属性包括：默认系统属性、OEM厂商系统属性和自定义系统属性。OEM厂商部分仅提供默认值，具体值需OEM产品方按需进行调整。

## syspara系统接口说明<a name="section775916468231"></a>

**表 1**  系统属性接口说明

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.29%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="42.71%" id="mcps1.2.3.1.2"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p15146174185515"><a name="p15146174185515"></a><a name="p15146174185515"></a>int GetParameter(const char* key, const char* def, char* value, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p13562171015712"><a name="p13562171015712"></a><a name="p13562171015712"></a>获取系统参数。</p>
</td>
</tr>
<tr id="row57882012954"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p77897122517"><a name="p77897122517"></a><a name="p77897122517"></a>int SetParameter(const char* key, const char* value)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p8150164120555"><a name="p8150164120555"></a><a name="p8150164120555"></a>设置/更新系统参数。</p>
</td>
</tr>
<tr id="row1746172917474"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1315210414552"><a name="p1315210414552"></a><a name="p1315210414552"></a>char* GetProductType(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p12366194110514"><a name="p12366194110514"></a><a name="p12366194110514"></a>返回当前设备类型。</p>
</td>
</tr>
<tr id="row10992232154714"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p19154174135517"><a name="p19154174135517"></a><a name="p19154174135517"></a>char* GetManufacture(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p191521415555"><a name="p191521415555"></a><a name="p191521415555"></a>返回当前设备生产厂家信息。</p>
</td>
</tr>
<tr id="row137112185917"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p16371201145918"><a name="p16371201145918"></a><a name="p16371201145918"></a>char* GetBrand(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p2371719599"><a name="p2371719599"></a><a name="p2371719599"></a>返回当前设备品牌信息。</p>
</td>
</tr>
<tr id="row981535875818"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p18151586589"><a name="p18151586589"></a><a name="p18151586589"></a>char* GetMarketName(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1081545865810"><a name="p1081545865810"></a><a name="p1081545865810"></a>返回当前设备传播名。</p>
</td>
</tr>
<tr id="row45019563583"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p3501195617581"><a name="p3501195617581"></a><a name="p3501195617581"></a>char* GetProductSeries(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p65011156165811"><a name="p65011156165811"></a><a name="p65011156165811"></a>返回当前设备产品系列名。</p>
</td>
</tr>
<tr id="row732525410585"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p10325125465819"><a name="p10325125465819"></a><a name="p10325125465819"></a>char* GetProductModel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p332565412582"><a name="p332565412582"></a><a name="p332565412582"></a>返回当前设备认证型号。</p>
</td>
</tr>
<tr id="row5746145116588"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p20746145145812"><a name="p20746145145812"></a><a name="p20746145145812"></a>char* GetSoftwareModel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p14746175165810"><a name="p14746175165810"></a><a name="p14746175165810"></a>返回当前设备内部软件子型号。</p>
</td>
</tr>
<tr id="row536404914589"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1364749135819"><a name="p1364749135819"></a><a name="p1364749135819"></a>char* GetHardwareModel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1536424935819"><a name="p1536424935819"></a><a name="p1536424935819"></a>返回当前设备硬件版本号。</p>
</td>
</tr>
<tr id="row453414616584"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p15534164685817"><a name="p15534164685817"></a><a name="p15534164685817"></a>char* GetHardwareProfile(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p15534154619588"><a name="p15534154619588"></a><a name="p15534154619588"></a>返回当前设备硬件profile。</p>
</td>
</tr>
<tr id="row3279655002"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p112791755204"><a name="p112791755204"></a><a name="p112791755204"></a>char* GetSerial(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1827910551901"><a name="p1827910551901"></a><a name="p1827910551901"></a>返回当前设备序列号（SN号）。</p>
</td>
</tr>
<tr id="row101032053602"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p810395319016"><a name="p810395319016"></a><a name="p810395319016"></a>char* GetOsName(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p181037531301"><a name="p181037531301"></a><a name="p181037531301"></a>返回操作系统名。</p>
</td>
</tr>
<tr id="row081175112010"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p13821151707"><a name="p13821151707"></a><a name="p13821151707"></a>char* GetDisplayVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p582251708"><a name="p582251708"></a><a name="p582251708"></a>返回当前设备用户可见的软件版本号。</p>
</td>
</tr>
<tr id="row19112249108"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1411224911016"><a name="p1411224911016"></a><a name="p1411224911016"></a>char* GetBootloaderVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p11122497014"><a name="p11122497014"></a><a name="p11122497014"></a>返回当前设备Bootloader版本号。</p>
</td>
</tr>
<tr id="row138384461706"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p20839194620019"><a name="p20839194620019"></a><a name="p20839194620019"></a>char* GetSecurityPatchTag(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p118393469018"><a name="p118393469018"></a><a name="p118393469018"></a>返回安全补丁标签。</p>
</td>
</tr>
<tr id="row58521914120"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p48527149215"><a name="p48527149215"></a><a name="p48527149215"></a>char* GetAbiList(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p8852114628"><a name="p8852114628"></a><a name="p8852114628"></a>返回当前设备支持的指令集（Abi）列表。</p>
</td>
</tr>
<tr id="row394071216210"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p9940111212216"><a name="p9940111212216"></a><a name="p9940111212216"></a>char* GetSdkApiLevel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p18940171215214"><a name="p18940171215214"></a><a name="p18940171215214"></a>返回与当前系统软件匹配的SDK API level。</p>
</td>
</tr>
<tr id="row138205101425"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p1382010101328"><a name="p1382010101328"></a><a name="p1382010101328"></a>char* GetFirstApiLevel(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p3820810521"><a name="p3820810521"></a><a name="p3820810521"></a>返回系统软件首版本SDK API level。</p>
</td>
</tr>
<tr id="row156198627"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p75622084212"><a name="p75622084212"></a><a name="p75622084212"></a>char* GetIncrementalVersion(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p95621087211"><a name="p95621087211"></a><a name="p95621087211"></a>返回差异版本号。</p>
</td>
</tr>
<tr id="row138721511320"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p28715156318"><a name="p28715156318"></a><a name="p28715156318"></a>char* GetVersionId(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p148761512312"><a name="p148761512312"></a><a name="p148761512312"></a>返回版本id。</p>
</td>
</tr>
<tr id="row18749712234"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p10749912738"><a name="p10749912738"></a><a name="p10749912738"></a>char* GetBuildType(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p67491212437"><a name="p67491212437"></a><a name="p67491212437"></a>返回构建类型。</p>
</td>
</tr>
<tr id="row178451710639"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p58461810136"><a name="p58461810136"></a><a name="p58461810136"></a>char* GetBuildUser(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p178466109315"><a name="p178466109315"></a><a name="p178466109315"></a>返回构建账户用户名。</p>
</td>
</tr>
<tr id="row126721685315"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p9673781832"><a name="p9673781832"></a><a name="p9673781832"></a>char* GetBuildHost(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p12673089315"><a name="p12673089315"></a><a name="p12673089315"></a>返回构建主机名。</p>
</td>
</tr>
<tr id="row146494315815"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p565184335811"><a name="p565184335811"></a><a name="p565184335811"></a>char* GetBuildTime(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p1466114365814"><a name="p1466114365814"></a><a name="p1466114365814"></a>返回构建时间。</p>
</td>
</tr>
<tr id="row933265824817"><td class="cellrowborder" valign="top" width="57.29%" headers="mcps1.2.3.1.1 "><p id="p18200134111553"><a name="p18200134111553"></a><a name="p18200134111553"></a>char* GetBuildRootHash(void)</p>
</td>
<td class="cellrowborder" valign="top" width="42.71%" headers="mcps1.2.3.1.2 "><p id="p7945171118466"><a name="p7945171118466"></a><a name="p7945171118466"></a>返回当前版本hash。</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section118404913233"></a>

系统属性使用实例

```
// set && get
char key1[] = "rw.sys.version";
char value1[] = "10.1.0";
int ret = SetParameter(key1, value1);
char valueGet1[128] = {0};
ret = GetParameter(key1, "version=10.1.0", valueGet1, 128);

// get sysparm
char* value1 = GetProductType();
printf("Product type =%s\n", value1);
free(value1);
char* value2 = GetManufacture();
printf("Manufacture =%s\n", value2);
free(value2);
char* value3 = GetBrand();
printf("GetBrand =%s\n", value3);
free(value3);
char* value4 = GetMarketName();
printf("MarketName =%s\n", value4);
free(value4);
char* value5 = GetProductSeries();
printf("ProductSeries =%s\n", value5);
free(value5);
char* value6 = GetProductModel();
printf("ProductModel =%s\n", value6);
free(value6);
char* value7 = GetSoftwareModel();
printf("SoftwareModel =%s\n", value7);
free(value7);
char* value8 = GetHardwareModel();
printf("HardwareModel =%s\n", value8);
free(value8);
char* value9 = GetHardwareProfile();
printf("Software profile =%s\n", value9);
free(value9);
char* value10 = GetSerial();
printf("Serial =%s\n", value10);
free(value10);
char* value11 = GetOsName();
printf("OS name =%s\n", value11);
free(value11);
char* value12 = GetDisplayVersion();
printf("Display version =%s\n", value12);
free(value12);
char* value13 = GetBootloaderVersion();
printf("bootloader version =%s\n", value13);
free(value13);
char* value14 = GetSecurityPatchTag();
printf("secure patch level =%s\n", value14);
free(value14);
char* value15 = GetAbiList();
printf("abi list =%s\n", value15);
free(value15);
char* value16 = GetFirstApiLevel();
printf("first api level =%s\n", value16);
free(value16);
char* value17 = GetIncrementalVersion();
printf("Incremental version = %s\n", value17);
free(value17);
char* value187 = GetVersionId();
printf("formal id =%s\n", value187);
free(value187);
char* value18 = GetBuildType();
printf("build type =%s\n", value18);
free(value18);
char* value19 = GetBuildUser();
printf("build user =%s\n", value19);
free(value19);
char* value20 = GetBuildHost();
printf("Build host = %s\n", value20);
free(value20);
char* value21 = GetBuildTime();
printf("build time =%s\n", value21);
free(value21);
char* value22 = GetBuildRootHash();
printf("build root later..., %s\n", value22);
free(value22);
```

