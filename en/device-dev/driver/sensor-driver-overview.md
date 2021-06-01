# Sensor Driver Overview<a name="EN-US_TOPIC_0000001078401780"></a>

-   [Introduction](#section667413271505)
-   [Available APIs](#section7255104114110)

## Introduction<a name="section667413271505"></a>

The sensor driver module provides APIs for upper-layer sensor services to implement basic sensor capabilities, including querying the sensor list, enabling or disabling a sensor, subscribing to or unsubscribing from sensor data, and setting sensor options. The sensor driver model is developed based on the Hardware Driver Foundation \(HDF\) and supports functions such as cross-OS migration and differentiated device configuration. The following figure shows the architecture of the sensor driver model.

**Figure  1**  Architecture of the sensor driver model<a name="fig10451455446"></a>  
![](figures/architecture-of-the-sensor-driver-model.png "architecture-of-the-sensor-driver-model")

The sensor driver model offers the following APIs:

-   Hardware Driver Interfaces \(HDIs\) for sensors: Facilitate service development.
-   APIs for implementing sensor driver model capabilities: Implement the capabilities of registering, loading, and unregistering sensor drivers as well as detecting sensor devices depending on the HDF, normalize APIs for sensor devices of the same type, and offer APIs for parsing register configurations, abstract APIs for bus access, and abstract platform APIs.
-   APIs to be implemented by developers: Based on the HDF Configuration Source \(HCS\), implement differentiated configuration for sensors of the same type and serialized configuration of sensor device parameters, and offer APIs for some sensor device operations to simplify sensor driver development.

## Available APIs<a name="section7255104114110"></a>

The following table lists the APIs provided by the sensor driver model.

**Table  1**  External APIs provided by the sensor driver model

<a name="table203963834718"></a>
<table><thead align="left"><tr id="row173964834716"><th class="cellrowborder" valign="top" width="8.260000000000002%" id="mcps1.2.4.1.1"><p id="p17401913133218"><a name="p17401913133218"></a><a name="p17401913133218"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="45.4%" id="mcps1.2.4.1.2"><p id="p20921103144918"><a name="p20921103144918"></a><a name="p20921103144918"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="46.339999999999996%" id="mcps1.2.4.1.3"><p id="p109216317495"><a name="p109216317495"></a><a name="p109216317495"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4397198154712"><td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p8437193673211"><a name="p8437193673211"></a><a name="p8437193673211"></a>Query</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p11001322173912"><a name="p11001322173912"></a><a name="p11001322173912"></a>int32_t <strong id="b935414557240"><a name="b935414557240"></a><a name="b935414557240"></a>GetAllSensors</strong>(struct SensorInformation **sensorInfo, int32_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a>Obtains information about all sensors in the system. The information about a sensor generally includes the sensor name, sensor vendor, firmware version, hardware version, sensor type ID, sensor ID, maximum measurement range, accuracy, and power.</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" rowspan="5" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p06071477324"><a name="p06071477324"></a><a name="p06071477324"></a>Setting</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p38874252376"><a name="p38874252376"></a><a name="p38874252376"></a>int32_t <strong id="b199602219271"><a name="b199602219271"></a><a name="b199602219271"></a>Enable</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a>Enables the sensor that has been subscribed to. The subscriber can obtain the sensor data only after the sensor is enabled.</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int32_t <strong id="b84601875330"><a name="b84601875330"></a><a name="b84601875330"></a>Disable</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a>Disables a sensor.</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int32_t <strong id="b16691194511438"><a name="b16691194511438"></a><a name="b16691194511438"></a>SetBatch</strong>(iint32_t sensorId, int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a>Sets the data sampling interval and data reporting interval for the specified sensor.</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p170411511281"><a name="p170411511281"></a><a name="p170411511281"></a>int32_t <strong id="b170414153284"><a name="b170414153284"></a><a name="b170414153284"></a>SetMode</strong>(int32_t sensorTypeId, SensorUser *user, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107051159281"><a name="p107051159281"></a><a name="p107051159281"></a>Sets the data reporting mode for the specified sensor.</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int32_t <strong id="b7501191019330"><a name="b7501191019330"></a><a name="b7501191019330"></a>SetOption</strong>(int32_t sensorId, uint32_t option)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a>Sets options for the specified sensor, including its measurement range and accuracy.</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" rowspan="2" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p1039815743211"><a name="p1039815743211"></a><a name="p1039815743211"></a>Data subscription and unsubscription</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p11530101054411"><a name="p11530101054411"></a><a name="p11530101054411"></a>int32_t <strong id="b0569161217334"><a name="b0569161217334"></a><a name="b0569161217334"></a>Register</strong>(RecordDataCallback cb)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a>Registers the callback for reporting sensor data to the subscriber.</p>
</td>
</tr>
<tr id="row10716713314"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p196491214133110"><a name="p196491214133110"></a><a name="p196491214133110"></a>int32_t <strong id="b13758151483317"><a name="b13758151483317"></a><a name="b13758151483317"></a>Unregister</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5817133119"><a name="p5817133119"></a><a name="p5817133119"></a>Unregisters the callback for reporting sensor data.</p>
</td>
</tr>
<tr id="row15679121655614"><td class="cellrowborder" rowspan="2" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p6596162112564"><a name="p6596162112564"></a><a name="p6596162112564"></a>Instance creation</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p13679191616561"><a name="p13679191616561"></a><a name="p13679191616561"></a>const struct SensorInterface *<strong id="b292451515"><a name="b292451515"></a><a name="b292451515"></a>NewSensorInterfaceInstance</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p19679181612563"><a name="p19679181612563"></a><a name="p19679181612563"></a>Creates a <strong id="b10138658185717"><a name="b10138658185717"></a><a name="b10138658185717"></a>SensorInterface</strong> instance.</p>
</td>
</tr>
<tr id="row9680191675612"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15680111655611"><a name="p15680111655611"></a><a name="p15680111655611"></a>int32_t <strong id="b1144297156"><a name="b1144297156"></a><a name="b1144297156"></a>FreeSensorInterfaceInstance</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18680916165620"><a name="p18680916165620"></a><a name="p18680916165620"></a>Releases the <strong id="b4150124205810"><a name="b4150124205810"></a><a name="b4150124205810"></a>SensorInterface</strong> instance.</p>
</td>
</tr>
</tbody>
</table>

The following table lists the APIs provided by the sensor driver model for driver developers. You can directly call these APIs without any implementations.

**Table  2**  APIs provided by the sensor driver model for driver developers

<a name="table1156812588320"></a>
<table><thead align="left"><tr id="row756817584327"><th class="cellrowborder" valign="top" width="8.550855085508552%" id="mcps1.2.4.1.1"><p id="p7568125873219"><a name="p7568125873219"></a><a name="p7568125873219"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="45.53455345534553%" id="mcps1.2.4.1.2"><p id="p1756812582328"><a name="p1756812582328"></a><a name="p1756812582328"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="45.91459145914592%" id="mcps1.2.4.1.3"><p id="p35681558183210"><a name="p35681558183210"></a><a name="p35681558183210"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row756875811329"><td class="cellrowborder" rowspan="3" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p5974193991911"><a name="p5974193991911"></a><a name="p5974193991911"></a>Device management</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p18569158173210"><a name="p18569158173210"></a><a name="p18569158173210"></a>int32_t <strong id="b4994112595516"><a name="b4994112595516"></a><a name="b4994112595516"></a>AddSensorDevice</strong>(const struct SensorDeviceInfo *deviceInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p356935816328"><a name="p356935816328"></a><a name="p356935816328"></a>Adds a sensor of the current type to the sensor management module.</p>
</td>
</tr>
<tr id="row195691858113219"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1156945883215"><a name="p1156945883215"></a><a name="p1156945883215"></a>int32_t <strong id="b1736762975518"><a name="b1736762975518"></a><a name="b1736762975518"></a>DeleteSensorDevice</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2569145833214"><a name="p2569145833214"></a><a name="p2569145833214"></a>Deletes a specified sensor from the sensor management module.</p>
</td>
</tr>
<tr id="row15699589321"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6569105811328"><a name="p6569105811328"></a><a name="p6569105811328"></a>int32_t <strong id="b1174510321555"><a name="b1174510321555"></a><a name="b1174510321555"></a>ReportSensorEvent</strong>(const struct SensorReportEvent *events)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15691858193220"><a name="p15691858193220"></a><a name="p15691858193220"></a>Reports data of a specified sensor type.</p>
</td>
</tr>
<tr id="row17569145814329"><td class="cellrowborder" rowspan="4" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p10589113932619"><a name="p10589113932619"></a><a name="p10589113932619"></a>Abstract bus and platform operations</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p145705585322"><a name="p145705585322"></a><a name="p145705585322"></a>int32_t <strong id="b15560203515558"><a name="b15560203515558"></a><a name="b15560203515558"></a>ReadSensor</strong>(struct SensorBusCfg *busCfg, uint16_t regAddr, uint8_t *data, uint16_t dataLen)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p1657018586322"><a name="p1657018586322"></a><a name="p1657018586322"></a>Reads sensor configuration data from the sensor register based on the bus configuration.</p>
</td>
</tr>
<tr id="row28712021112011"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p38722218200"><a name="p38722218200"></a><a name="p38722218200"></a>int32_t <strong id="b573774595514"><a name="b573774595514"></a><a name="b573774595514"></a>WriteSensor</strong>(struct SensorBusCfg *busCfg, uint8_t *writeData, uint16_t len)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6872112112201"><a name="p6872112112201"></a><a name="p6872112112201"></a>Writes sensor configuration data to the sensor register based on the bus configuration.</p>
</td>
</tr>
<tr id="row1667512682014"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p146751426192014"><a name="p146751426192014"></a><a name="p146751426192014"></a>int32_t <strong id="b4725135865517"><a name="b4725135865517"></a><a name="b4725135865517"></a>CreateSensorThread</strong>(struct OsalThread *thread, OsalThreadEntry threadEntry, char *name, void *entryPara)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10676112612013"><a name="p10676112612013"></a><a name="p10676112612013"></a>Creates a scheduled thread for a specified sensor to process sensor data reporting.</p>
</td>
</tr>
<tr id="row1594017462410"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p49401442414"><a name="p49401442414"></a><a name="p49401442414"></a>void <strong id="b17586316565"><a name="b17586316565"></a><a name="b17586316565"></a>DestroySensorThread</strong>(struct OsalThread *thread, uint8_t *status);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p69406415243"><a name="p69406415243"></a><a name="p69406415243"></a>Destroys the scheduled thread created for the sensor.</p>
</td>
</tr>
<tr id="row19401042245"><td class="cellrowborder" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p694020492417"><a name="p694020492417"></a><a name="p694020492417"></a>Common configuration</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p1794064142418"><a name="p1794064142418"></a><a name="p1794064142418"></a>int32_t <strong id="b1740939195611"><a name="b1740939195611"></a><a name="b1740939195611"></a>SetSensorRegCfgArray</strong>(struct SensorBusCfg *busCfg, const struct SensorRegCfgGroupNode *group);</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p49409417249"><a name="p49409417249"></a><a name="p49409417249"></a>Sets the sensor register group configuration based on the sensor bus type.</p>
</td>
</tr>
<tr id="row1494015418246"><td class="cellrowborder" rowspan="5" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p185291624202618"><a name="p185291624202618"></a><a name="p185291624202618"></a>Configuration parsing</p>
<p id="p978482418524"><a name="p978482418524"></a><a name="p978482418524"></a></p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p994194132410"><a name="p994194132410"></a><a name="p994194132410"></a>int32_t <strong id="b109631149171514"><a name="b109631149171514"></a><a name="b109631149171514"></a>GetSensorBaseConfigData</strong>(const struct DeviceResourceNode *node, struct SensorCfgData *config)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p79411640248"><a name="p79411640248"></a><a name="p79411640248"></a>Obtains basic configuration information such as sensor, bus, and attribute configurations based on the HCS resource configuration of the sensor device, and initializes the basic configuration data structure.</p>
</td>
</tr>
<tr id="row1171817565518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7718165615113"><a name="p7718165615113"></a><a name="p7718165615113"></a>int32_t <strong id="b14392155271515"><a name="b14392155271515"></a><a name="b14392155271515"></a>ParseSensorRegConfig</strong>(struct SensorCfgData *config)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p171885685120"><a name="p171885685120"></a><a name="p171885685120"></a>Parses the register group information based on the HCS resource configuration of the sensor device and initializes the configuration data structure.</p>
</td>
</tr>
<tr id="row394144192414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p99411144241"><a name="p99411144241"></a><a name="p99411144241"></a>void <strong id="b1322165619152"><a name="b1322165619152"></a><a name="b1322165619152"></a>ReleaseSensorAllRegConfig</strong>(struct SensorCfgData *config)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17941154152419"><a name="p17941154152419"></a><a name="p17941154152419"></a>Releases the resources allocated to the sensor configuration data structure.</p>
</td>
</tr>
<tr id="row10589154102611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4557141217521"><a name="p4557141217521"></a><a name="p4557141217521"></a>int32_t <strong id="b1206195914157"><a name="b1206195914157"></a><a name="b1206195914157"></a>GetSensorBusHandle</strong>(struct SensorBusCfg *busCfg)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p953821245219"><a name="p953821245219"></a><a name="p953821245219"></a>Obtains the sensor bus handle information.</p>
</td>
</tr>
<tr id="row6784142455212"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p478492410522"><a name="p478492410522"></a><a name="p478492410522"></a>int32_t <strong id="b9443344101610"><a name="b9443344101610"></a><a name="b9443344101610"></a>ReleaseSensorBusHandle</strong>(struct SensorBusCfg *busCfg)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1878422485212"><a name="p1878422485212"></a><a name="p1878422485212"></a>Releases the sensor bus handle information.</p>
</td>
</tr>
</tbody>
</table>

The following table lists the APIs that need to be implemented by driver developers.

**Table  3**  APIs that need to be implemented by driver developers

<a name="table1083014911336"></a>
<table><thead align="left"><tr id="row208301997332"><th class="cellrowborder" valign="top" width="8.41084108410841%" id="mcps1.2.4.1.1"><p id="p1777364318152"><a name="p1777364318152"></a><a name="p1777364318152"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="45.77457745774577%" id="mcps1.2.4.1.2"><p id="p5773174317157"><a name="p5773174317157"></a><a name="p5773174317157"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="45.81458145814582%" id="mcps1.2.4.1.3"><p id="p1777319437155"><a name="p1777319437155"></a><a name="p1777319437155"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1880425111572"><td class="cellrowborder" rowspan="8" valign="top" width="8.41084108410841%" headers="mcps1.2.4.1.1 "><p id="p598171454520"><a name="p598171454520"></a><a name="p598171454520"></a>Basic functions</p>
</td>
<td class="cellrowborder" valign="top" width="45.77457745774577%" headers="mcps1.2.4.1.2 "><p id="p880485195711"><a name="p880485195711"></a><a name="p880485195711"></a>int32_t <strong id="b16497123107"><a name="b16497123107"></a><a name="b16497123107"></a>init</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" width="45.81458145814582%" headers="mcps1.2.4.1.3 "><p id="p1480465165710"><a name="p1480465165710"></a><a name="p1480465165710"></a>Initializes the configuration of a sensor device after it is detected successfully.</p>
</td>
</tr>
<tr id="row10831296333"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1783115910333"><a name="p1783115910333"></a><a name="p1783115910333"></a>int32_t <strong id="b146831650010"><a name="b146831650010"></a><a name="b146831650010"></a>GetInfo</strong>(struct SensorBasicInfo *info)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4831139153316"><a name="p4831139153316"></a><a name="p4831139153316"></a>Obtains the basic information about the current sensor device from the HCS of sensor devices.</p>
</td>
</tr>
<tr id="row178311493339"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p208318963320"><a name="p208318963320"></a><a name="p208318963320"></a>int32_t <strong id="b189921571402"><a name="b189921571402"></a><a name="b189921571402"></a>Enable</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p68310953312"><a name="p68310953312"></a><a name="p68310953312"></a>Enables the current sensor device by delivering the register configuration in the operation group based on the HCS of the current sensor device.</p>
</td>
</tr>
<tr id="row0831129153318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p0831169183314"><a name="p0831169183314"></a><a name="p0831169183314"></a>int32_t <strong id="b13541291106"><a name="b13541291106"></a><a name="b13541291106"></a>Disable</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p138314912336"><a name="p138314912336"></a><a name="p138314912336"></a>Disables the current sensor device by delivering the register configuration in the operation group based on the HCS of the current sensor device.</p>
</td>
</tr>
<tr id="row178311093334"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p583118920338"><a name="p583118920338"></a><a name="p583118920338"></a>int32_t <strong id="b111117118017"><a name="b111117118017"></a><a name="b111117118017"></a>SetBatch</strong>(int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p08311903315"><a name="p08311903315"></a><a name="p08311903315"></a>Sets the processing time of the data reporting thread for the current sensor device based on the data sampling interval and data reporting interval.</p>
</td>
</tr>
<tr id="row1356419421422"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9565174218421"><a name="p9565174218421"></a><a name="p9565174218421"></a>int32_t <strong id="b13702551143412"><a name="b13702551143412"></a><a name="b13702551143412"></a>SetMode</strong>(int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p356524224213"><a name="p356524224213"></a><a name="p356524224213"></a>Sets the data reporting mode of the current sensor device.</p>
</td>
</tr>
<tr id="row12565104264215"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17565104210429"><a name="p17565104210429"></a><a name="p17565104210429"></a>int32_t <strong id="b96811512011"><a name="b96811512011"></a><a name="b96811512011"></a>SetOption</strong>(uint32_t option)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4565104214213"><a name="p4565104214213"></a><a name="p4565104214213"></a>Sets the register configuration such as the measurement range and accuracy based on sensor options.</p>
</td>
</tr>
<tr id="row380240111218"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1181184016120"><a name="p1181184016120"></a><a name="p1181184016120"></a>void <strong id="b1613451717016"><a name="b1613451717016"></a><a name="b1613451717016"></a>ReadSensorData</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p7815401121"><a name="p7815401121"></a><a name="p7815401121"></a>Reads sensor data.</p>
</td>
</tr>
</tbody>
</table>

For details about the API implementation, see the  [sensor driver development example](sensor-driver-development-example.md).

