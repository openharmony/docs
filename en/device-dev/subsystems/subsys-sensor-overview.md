# Sensor Overview<a name="EN-US_TOPIC_0000001092893507"></a>

## Introduction<a name="section667413271505"></a>

The pan-sensor service subsystem provides a lightweight sensor service framework. You can call APIs offered by this framework to query the sensor list, enable or disable a sensor, and subscribe to or unsubscribe from sensor data. The following figure shows the architecture of the lightweight sensor framework.

**Figure 1**  Sensor service framework

![](figure/en-us_image_0000001077724150.png)

-   Sensor API: provides APIs for performing basic operations on sensors, including querying the sensor list, subscribing to or unsubscribing from sensor data, and executing control commands. This module makes application development simpler.
-   Sensor Framework: manages sensor data subscription, creates and destroys data channels, and implements communication with the Sensor Service module.
-   Sensor Service: interacts with the HDF module to receive, parse, and distribute data, manages sensors on hardware and sensor data reporting, and controls sensor permissions.

## Available APIs<a name="section7255104114110"></a>

**Table  1**  APIs of the sensor framework

<a name="table203963834718"></a>
<table><thead align="left"><tr id="row173964834716"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p20921103144918"><a name="p20921103144918"></a><a name="p20921103144918"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="25.722572257225725%" id="mcps1.2.4.1.2"><p id="p109216317495"><a name="p109216317495"></a><a name="p109216317495"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="40.94409440944094%" id="mcps1.2.4.1.3"><p id="p1192112316497"><a name="p1192112316497"></a><a name="p1192112316497"></a>Parameter</p>
</th>
</tr>
</thead>
<tbody><tr id="row4397198154712"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11001322173912"><a name="p11001322173912"></a><a name="p11001322173912"></a>int32_t <strong id="b792815314396"><a name="b792815314396"></a><a name="b792815314396"></a>GetAllSensors</strong>(SensorInfo **sensorInfo, int32_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a>Obtains information about all sensors in the system.</p>
<p id="p9922153110492"><a name="p9922153110492"></a><a name="p9922153110492"></a><strong id="b2922183114917"><a name="b2922183114917"></a><a name="b2922183114917"></a>Return value</strong>: Returns <strong id="b15367115154516"><a name="b15367115154516"></a><a name="b15367115154516"></a>0</strong> if the information is obtained; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p4922173116498"><a name="p4922173116498"></a><a name="p4922173116498"></a><strong id="b633817407478"><a name="b633817407478"></a><a name="b633817407478"></a>sensorInfo</strong> (not NULL): information about all sensors in the system</p>
<p id="p18922931134919"><a name="p18922931134919"></a><a name="p18922931134919"></a><strong id="b8845650154711"><a name="b8845650154711"></a><a name="b8845650154711"></a>count</strong> (not NULL): total number of sensors in the system</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p38874252376"><a name="p38874252376"></a><a name="p38874252376"></a>int32_t <strong id="b17835184513919"><a name="b17835184513919"></a><a name="b17835184513919"></a>SubscribeSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p14922113114914"><a name="p14922113114914"></a><a name="p14922113114914"></a>Subscribes to sensor data. The system will report the obtained sensor data to the subscriber.</p>
<p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a><strong id="b7756437172"><a name="b7756437172"></a><a name="b7756437172"></a>Return value</strong>: Returns <strong id="b37618371173"><a name="b37618371173"></a><a name="b37618371173"></a>0</strong> if the subscription is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p17922183120490"><a name="p17922183120490"></a><a name="p17922183120490"></a><strong id="b383183812561"><a name="b383183812561"></a><a name="b383183812561"></a>sensorTypeId</strong>: ID of a sensor type</p>
<p id="p8922193154917"><a name="p8922193154917"></a><a name="p8922193154917"></a><strong id="b15825101814564"><a name="b15825101814564"></a><a name="b15825101814564"></a>user</strong> (not NULL): sensor subscriber that requests sensor data. A subscriber can obtain data from only one sensor.</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int32_t <strong id="b338673044313"><a name="b338673044313"></a><a name="b338673044313"></a>UnsubscribeSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p792383116495"><a name="p792383116495"></a><a name="p792383116495"></a>Unsubscribes from sensor data. The system will no longer report sensor data to the subscriber.</p>
<p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a><strong id="b1698214914415"><a name="b1698214914415"></a><a name="b1698214914415"></a>Return value</strong>: Returns <strong id="b20983690447"><a name="b20983690447"></a><a name="b20983690447"></a>0</strong> if the unsubscription is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p178981446572"><a name="p178981446572"></a><a name="p178981446572"></a><strong id="b5189141634413"><a name="b5189141634413"></a><a name="b5189141634413"></a>sensorTypeId</strong>: ID of a sensor type</p>
<p id="p178988410573"><a name="p178988410573"></a><a name="p178988410573"></a><strong id="b56761418164417"><a name="b56761418164417"></a><a name="b56761418164417"></a>user</strong> (not NULL): sensor subscriber that requests sensor data. A subscriber can obtain data from only one sensor.</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int32_t <strong id="b16691194511438"><a name="b16691194511438"></a><a name="b16691194511438"></a>SetBatch</strong>(int32_t sensorTypeId, SensorUser *user, int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p14924831124913"><a name="p14924831124913"></a><a name="p14924831124913"></a>Sets the data sampling interval and data reporting interval for the specified sensor.</p>
<p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a><strong id="b181731732463"><a name="b181731732463"></a><a name="b181731732463"></a>Return value</strong>: Returns <strong id="b417363104616"><a name="b417363104616"></a><a name="b417363104616"></a>0</strong> if the setting is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p189243318494"><a name="p189243318494"></a><a name="p189243318494"></a><strong id="b4102102264610"><a name="b4102102264610"></a><a name="b4102102264610"></a>sensorTypeId</strong>: ID of a sensor type</p>
<p id="p167364493594"><a name="p167364493594"></a><a name="p167364493594"></a><strong id="b930712416461"><a name="b930712416461"></a><a name="b930712416461"></a>user</strong> (not NULL): sensor subscriber that requests sensor data. A subscriber can obtain data from only one sensor.</p>
<p id="p1692403115493"><a name="p1692403115493"></a><a name="p1692403115493"></a><strong id="b1866310191589"><a name="b1866310191589"></a><a name="b1866310191589"></a>samplingInterval</strong>: sensor data sampling interval, in nanoseconds</p>
<p id="p392443174917"><a name="p392443174917"></a><a name="p392443174917"></a><strong id="b851892113817"><a name="b851892113817"></a><a name="b851892113817"></a>reportInterval</strong>: sensor data reporting interval, in nanoseconds</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17925631194911"><a name="p17925631194911"></a><a name="p17925631194911"></a>int32_t <strong id="b12311455154316"><a name="b12311455154316"></a><a name="b12311455154316"></a>ActivateSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p1892583174920"><a name="p1892583174920"></a><a name="p1892583174920"></a>Enables the specified sensor that has been subscribed to.</p>
<p id="p16925113119497"><a name="p16925113119497"></a><a name="p16925113119497"></a><strong id="b1190011547620"><a name="b1190011547620"></a><a name="b1190011547620"></a>Return value</strong>: Returns <strong id="b1690019543620"><a name="b1690019543620"></a><a name="b1690019543620"></a>0</strong> if the sensor is successfully enabled; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p59255313493"><a name="p59255313493"></a><a name="p59255313493"></a><strong id="b269629475"><a name="b269629475"></a><a name="b269629475"></a>sensorTypeId</strong>: ID of a sensor type</p>
<p id="p1692517314499"><a name="p1692517314499"></a><a name="p1692517314499"></a><strong id="b1739417117716"><a name="b1739417117716"></a><a name="b1739417117716"></a>user</strong> (not NULL): sensor subscriber that requests sensor data. A subscriber can obtain data from only one sensor.</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int32_t <strong id="b1612146204413"><a name="b1612146204413"></a><a name="b1612146204413"></a>DeactivateSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p12925143118492"><a name="p12925143118492"></a><a name="p12925143118492"></a>Disables an enabled sensor.</p>
<p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a><strong id="b13736235877"><a name="b13736235877"></a><a name="b13736235877"></a>Return value</strong>: Returns <strong id="b273720356714"><a name="b273720356714"></a><a name="b273720356714"></a>0</strong> if the sensor is successfully disabled; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p1692683112499"><a name="p1692683112499"></a><a name="p1692683112499"></a><strong id="b1452911411574"><a name="b1452911411574"></a><a name="b1452911411574"></a>sensorTypeId</strong>: ID of a sensor type</p>
<p id="p1081949113"><a name="p1081949113"></a><a name="p1081949113"></a><strong id="b11188443178"><a name="b11188443178"></a><a name="b11188443178"></a>user</strong> (not NULL): sensor subscriber that requests sensor data. A subscriber can obtain data from only one sensor.</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11530101054411"><a name="p11530101054411"></a><a name="p11530101054411"></a>int32_t <strong id="b1999420216444"><a name="b1999420216444"></a><a name="b1999420216444"></a>SetMode</strong>(int32_t sensorTypeId, SensorUser *user, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a>Sets the data reporting mode for the specified sensor.</p>
<p id="p1927031114910"><a name="p1927031114910"></a><a name="p1927031114910"></a><strong id="b456216221484"><a name="b456216221484"></a><a name="b456216221484"></a>Return value</strong>: Returns <strong id="b12562112214811"><a name="b12562112214811"></a><a name="b12562112214811"></a>0</strong> if the sensor data reporting mode is successfully set; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p119277312492"><a name="p119277312492"></a><a name="p119277312492"></a><strong id="b19747144015816"><a name="b19747144015816"></a><a name="b19747144015816"></a>sensorTypeId</strong>: ID of a sensor type</p>
<p id="p159271031184915"><a name="p159271031184915"></a><a name="p159271031184915"></a><strong id="b1367209917"><a name="b1367209917"></a><a name="b1367209917"></a>user</strong> (not NULL): sensor subscriber that requests sensor data. A subscriber can obtain data from only one sensor.</p>
<p id="p0927173154916"><a name="p0927173154916"></a><a name="p0927173154916"></a><strong id="b3914356101520"><a name="b3914356101520"></a><a name="b3914356101520"></a>mode</strong>: data reporting mode of the sensor</p>
</td>
</tr>
</tbody>
</table>

