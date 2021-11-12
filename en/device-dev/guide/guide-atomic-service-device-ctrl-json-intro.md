# Overview<a name="EN-US_TOPIC_0000001205747225"></a>

The JSON configuration file in the template is the basis for the device control UI. The JSON configuration file of the intelligent fan is stored in  **control/src/main/resources/rawfile/FAN**. The configuration is as follows:

```
{
  "devName": "Intelligent fan",
  "devType": "0",
  "prodId": "FAN",       -- prodId specifies the product name displayed on the device control UI.
  "templateUIInfo": [    -- Place preset Control components under templateUIInfo, with one component per line.
    {"name": "Power supply"...},
    {"name": "Mode"...},
    {"name": "Speed control"...},
    {"name": "Scheduled shutdown"...}
  ],
  "dialogUIInfo": [      -- Dialog components can be declared under dialogUIInfo. They are displayed only upon click events.
    {"name": "Shutdown time"...}
  ]
}
```

Two types of components \(**Control**  and  **Dialog**  components\) are provided in the template. \(The  **Control**  components are directly displayed on the UI, and the  **Dialog**  components are displayed only after being triggered.\) You need to declare these components in the JSON configuration file.

**After modifying the JSON configuration file, reinstall and run the atomic service for the modification to take effect.**

