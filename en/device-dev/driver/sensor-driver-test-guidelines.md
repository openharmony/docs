# Sensor Driver Test Guidelines<a name="EN-US_TOPIC_0000001078029794"></a>

After the driver is developed, you can develop self-test cases in the sensor unit test to verify the basic functions of the driver. The developer self-test platform is used as the test environment.

```
/* Specify whether to report sensor data. */
static int32_t g_sensorDataFlag = 0;
/* Retain the address of the sensor interface instance. */
static const struct SensorInterface *g_sensorDev = nullptr;

/* Register the data reporting function. */
static int SensorTestDataCallback(struct SensorEvents *event)
{
    if (event == nullptr) {
        return -1;
    }
    float *data = (float*)event->data;
    printf("time [%lld] sensor id [%d] x-[%f] y-[%f] z-[%f]\n\r", event->timestamp,
        event->sensorId, (*data), *(data + 1), *(data + g_axisZ));
    if (*data > 1e-5) {
        g_sensorDataFlag = 1;
    }
    return 0;
}
/* Initialize the sensor interface instance before executing the test cases. */
void HdfSensorTest::SetUpTestCase()
{
    g_sensorDev = NewSensorInterfaceInstance();
    if (g_sensorDev == nullptr) {
        printf("test sensorHdi get Module instace failed\n\r");
    }
}
/* Release case resources. */
void HdfSensorTest::TearDownTestCase()
{
    if (g_sensorDev != nullptr) {
        FreeSensorInterfaceInstance();
        g_sensorDev = nullptr;
    }
}
/* Verify the sensor driver. */
HWTEST_F(HdfSensorTest,TestAccelDriver_001, TestSize.Level0)
{
    int32_t sensorInterval = 1000000000; /* Data sampling interval, in nanoseconds */
    int32_t pollTime = 5; /* Data sampling duration, in seconds */
    int32_t accelSensorId = 1; /* Acceleration sensor type ID, which is 1 */
    int32_t count = 0;
    int ret;
    struct SensorInformation *sensorInfo = nullptr;

    ret = g_sensorDev->Register(SensorTestDataCallback)
    EXPECT_EQ(SENSOR_NULL_PTR, ret);

    ret = g_sensorDev->GetAllSensors(&sensorInfo, &count);
    EXPECT_EQ(0, ret);
    if (sensorInfo == nullptr) {
        EXPECT_NE(nullptr, sensorInfo);
        return;
    }
    /* Print the obtained sensor list. */
    for (int i = 0; i < count; i++) {
        printf("get sensoriId[%d], info name[%s]\n\r", sensorInfo[i]->sensorId, sensorInfo[i]->sensorName);
    }
    ret = g_sensorDev->Enable(accelSensorId);
    EXPECT_EQ(0, ret);
    g_sensorDataFlag = 0;

    ret = g_sensorDev->SetBatch(accelSensorId, sensorInterval, pollTime);
    EXPECT_EQ(0, ret);
    /* Observe the printed data within the period specified by pollTime. */
    OsalSleep(pollTime);
    EXPECT_EQ(1, g_sensorDataFlag);

    ret = g_sensorDev->Disable(accelSensorId);
    g_sensorDataFlag = 0;
    EXPECT_EQ(0, ret);

    ret = g_sensorDev->Unregister();
    EXPECT_EQ(0, ret);
}
```

