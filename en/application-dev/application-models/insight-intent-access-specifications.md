# Appendix: Standard Intent Access Specifications
## Media Domain
### Playing Videos 
Requests to play a video. It supports parameters such as video entities and episode information, and returns the playback result status.

**Intent name**: PlayVideo

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description              | Example Data|
|-------------|--------|------|------------------|---------|
| entityId    | string | Yes  | Intent entity ID, with a maximum of 64 characters.| "12949589" |
| episodeId   | string | No | Episode ID.        | "285786" |
| episodeNumber | number | No | Target episode number. Unit: episode.      | 5 |
| extras      | object |  No | Other extended parameters, which can be customized. | - |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Playing a Playlist  

Requests to play music from a specified playlist, with filtering options by scene, city, and other criteria, and returns the playback result status.

**Intent name**: PlayMusicList

**Since**: 1.0.2

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                                      | Example Data|
|--------------|-----------|-------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------|
| entityId | string | No| Intent entity ID, with a maximum of 64 characters.                                                                                                                                                                                                                                                                      | "C10194368" |
| entityGroupId | string | No| UI form of the playlist. The value can be customized and cannot exceed 64 characters.                                                                                                                                                                                                                  | "C10194321312" |
| sceneType | string | No | Scene type.<br>- MORNING_SCENE: morning.<br>- MIDDAY_SCENE: midday.<br>- EVENING_SCENE: evening.<br>- NIGHT_SCENE: night.<br>- WEEKEND_SCENE: weekend.<br>- FESTIVAL_SCENE: holiday.<br>- BIRTHDAY_SCENE: birthday.<br>- ANNIVERSARY_SCENE: anniversary.<br>- DRIVE_SCENE: driving.<br>- SUBWAY_SCENE: subway.<br>- TRAVEL_SCENE: travel.<br>- CITY_SCENE: inter-city travel.| "MORNING_SCENE" |
|city | string | No| City name. | "Beijing"|

**Return value**

| Name| Type | Mandatory| Description                                                                                                                                                                                                                                    | Example Data|
| ------ | ---- | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-|
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. The details are as follows:<br>- 100060101: Playing member-only or paid songs is not supported.<br>- 100060102: The account has expired and there are no preview clips for the song.<br>- 100060201: Playback is not supported for songs that have child protection enabled, are associated with a child account, or are marked as inappropriate.<br>- 100060202: The playlist has been removed and cannot be played.<br>- 100060203: The song's copyright on this platform has expired and therefore the song cannot be played.<br>- 100060301: The song/artist has been added to the blocklist and therefore the song cannot be played.<br>- 100060401: The software is faulty.| 100060101 |
| result | object | Yes  | Result object, which is returned in the form of key-value pairs, with a maximum of 8000 characters.                                                                                                                                                                         | {"musicSize":"4M","dataReceiveTime":1704868765000} |

### Playing Audio Programs

Requests to play a specified audio program, with filtering options by intent entity ID and audio program ID, and returns the playback result status.

**Intent name**: PlayAudio

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description | Example Data|
|---------|----------|--------|-------------------------------------------------------------|----------|
| entityId | string | Yes| Intent entity ID, with a maximum of 64 characters.| "AD1019465754" |
| soundId | string | No| Audio program ID, with a maximum of 64 characters. This parameter is mandatory for an attempt to access the second version of the framework.| "324535435" |

**Return value**

| Name| Type | Mandatory| Description                                                                                                                                                   | Example Data|
| ------| ----- | ---- |-------------------------------------------------------------------------------------------------------------------------------------------------------| -------- |
| code  | number  | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.<br>[Error type 1] No resources:<br>- 100070101: The software is faulty.| 100070101  |
| result  | object | Yes  | Result object, which is returned in the form of key-value pairs, with a maximum of 8000 characters.                                  | {"AudioSize":"4M","dataReceiveTime":102154151} |


## Entertainment Domain
### Playing Games 

Initiates or queries game-related operations, such as starting a game, obtaining game status, and executing in-game actions. It returns the operation result status and data, enabling users to interact with games or retrieve game-related information.

**Intent name**: PlayGame

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description              | Example Data|
|-------------|--------|------|------------------|---------|
| entityId    | string | Yes  | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Navigation Domain
### Starting Navigation
Initiates a navigation request. You can set the departure location, destination, waypoints, destination type, and transportation mode. It is suitable for various travel scenarios including driving, walking, cycling, bus, and subway.

**Intent name**: StartNavigate

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description                                                                              | Example Data|
|-------------|-----|--------|----------------------------------------------------------------------------------|---------|
| entityId    | string | No  | Intent entity ID, with a maximum of 64 characters.                                                                 | "12949589" |
| srcLocation | object | No  | Departure location information, which contains the following fields:<br>- **locationSystem**: coordinate system (GCJ-02 by default).<br>- **poiId**: unique ID of a POI.<br>- **locationName**: location name.<br>- **longitude**: longitude.<br>- **latitude**: latitude.<br>- **address**: detailed address information.     | {<br>  "locationSystem": "GCJ02",<br>  "poiId": "1236",<br>  "locationName": "Beijing Railway Station",<br>  "latitude": "39.902895",<br>  "longitude": "116.427915",<br>  "address": "Beijing Railway Station, Dongcheng District, Beijing"<br>} |
| dstLocation | object | No  | Destination information, which contains the following fields:<br>- **locationSystem**: coordinate system (GCJ-02 by default).<br>- **poiId**: unique ID of a POI.<br>- **locationName**: location name.<br>- **longitude**: longitude.<br>- **latitude**: latitude.<br>- **address**: detailed address information.    | {<br>  "locationSystem": "GCJ02",<br>  "poiId": "1248",<br>  "locationName": "Beijing West Railway Station",<br>  "latitude": "39.89534",<br>  "longitude": "116.32128",<br>  "address": "Beijing West Railway Station, Fengtai District, Beijing"<br>} |
| wayPoints   | array | No  | Waypoints array. When invoked via the voice entry, Array\<PoiLocation> is mandatory. The fields contained in the waypoints are the same as those in **srcLocation**. A maximum of five waypoints can be passed.                                     | [{<br>  "locationSystem": "GCJ02",<br>  "poiId": "1445",<br>  "locationName": "Qianmen East Street Community",<br>  "latitude": "39.89995",<br>  "longitude": "116.35628",<br>  "address": "Qianmen Street, Dongcheng District, Beijing"<br>}] |
| dstLocationType | string | No  | Destination type, for example, "home" or "company".                                                              | "Home"|
| trafficType | string | No  | Mode of transportation.<br>- Drive: driving (default value).<br>- Walk: walking.<br>- Cycle: cycling.<br>- Bus: bus.<br>- Subway: subway.| "Cycle" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----  | ---- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object| Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Transportation Card Code 
Requests to display the user's subway or bus transportation card QR code, with options to specify the transportation type (subway or bus) and city code. It is suitable for public transportation scenarios.

**Intent name**: ViewTravelCardCode

**Since**: 1.0.1

**Parameters** 

| Name| Type   | Mandatory| Description                                                                                                                                                  | Example Data|
|-------------|---------|-------|----------------------------------------------------------------------------------------------|---------|
| travelCardType | string | No| Type of transportation. By default, the type last viewed by the user is used (implementation-dependent).<br>- Metro: subway.<br>- Bus: bus.  | "Metro" |
| adminCode    | number  | No| City code where the user is located. The default value is the user's current city. The city codes of China are used. For details, see [City Codes and Administrative Division Codes](https://developer.huawei.com/consumer/en/doc/harmonyos-references-V5/map-citycode-V5).| 320500 |

**Return value**

| Name | Type | Mandatory| Description                                                              | Example Data|
| ------ | ------| ---- |------------------------------------------------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0 |
| result | object | Yes  | Result object, which is returned in the form of key-value pairs, with a maximum of 8000 characters.| -       |

### Ride Hailing 
Initiates a ride-hailing request. You can set the pick-up location, destination, vehicle type, and entry channel ID. It is suitable for multiple ride-hailing scenarios, such as economy cars, taxis, and carpooling.

**Intent name**: RideHailing

**Since**: 1.0.1

**Parameters** 

| Name| Type  | Mandatory| Description                                                                            | Example Data|
|-------------|--------|---------|--------------------------------------------------------------------------------|---------|
| entityId    | string | No   | Intent entity ID, with a maximum of 64 characters.                                                               | "12949589" |
| srcLocation | object | No  | Pick-up location information, which contains the following fields:<br>- **locationSystem**: coordinate system (GCJ-02 by default).<br>- **poiId**: unique ID of a POI.<br>- **locationName**: location name.<br>- **longitude**: longitude.<br>- **latitude**: latitude.<br>- **address**: detailed address information.| {<br>  "locationSystem": "GCJ02",<br>  "poiId": "1245",<br>  "locationName": "Beijing Railway Station",<br>  "latitude": "39.902895",<br>  "longitude": "116.427915",<br>  "address": "Beijing Railway Station, Dongcheng District, Beijing"<br>} |
| dstLocation | object | No   | Destination information, which contains the following fields:<br>- **locationSystem**: coordinate system (GCJ-02 by default).<br>- **poiId**: unique ID of a POI.<br>- **locationName**: location name.<br>- **longitude**: longitude.<br>- **latitude**: latitude.<br>- **address**: detailed address information.| {<br>  "locationSystem": "GCJ02",<br>  "poiId": "1232",<br>  "locationName": "Beijing West Railway Station",<br>  "latitude": "39.89534",<br>  "longitude": "116.32128",<br>  "address": "Beijing West Railway Station, Fengtai District, Beijing"<br>} |
| dstLocationType | string | No  | Destination type, for example, "home" or "company".                                                             | "Home"|
| hwChannelId | string | No  | Channel ID for the entry point.<br>- "0x00000100": Celia Suggestions.<br>- "0x00000200": Celia Voice.<br>- "0x00000300": drag-and-drop entry.| "0x00000100" |
| taxiType    | number | No  | Vehicle type. The default value is **0**.<br>- 0: default.<br>- 1: economy car.<br>- 2: taxi.<br>- 3: carpooling.<br>- 4: hitchhiking.<br>- 5: premium car.  | 1 |

**Return value**

| Name | Type| Mandatory| Description                                | Example Data|
| ------ | -----| ---- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Flight Tickets 
Requests detailed information about a flight ticket, including basic information such as cabin class. 

**Intent name**: ViewFlightTicket

**Since**: 1.0.1

**Parameters**

| Name  | Type| Mandatory| Description                   | Example Data  |
| -------- | -------- | ---- |-----------------------| ---------- |
| entityId | number   | Yes  | Intent entity ID, which is the ID of the flight ticket.       | 1 |
| cabin    | string   | No  | Cabin class.<br>- Economy class.<br>- First class.<br>- Business class.<br>- Premium economy class.| "Economy class"  |

**Return value**

| Name | Type  | Mandatory| Description                                | Example Data|
| ------ | ------| ---- |------------------------------------------------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### View Train Tickets 
Requests detailed information about a train ticket, including basic information such as seat type.

**Intent name**: ViewTrainTicket

**Since**: 1.0.1

**Parameters** 

| Name| Type  | Mandatory| Description                                                                                              | Example Data|
|---------|--------|---------|--------------------------------------------------------------------------------------------------|---------|
| entityId | number | Yes  | Intent entity ID, which is the ID of the train ticket.                                                                                 | 1 |
| seatLevelShow | string | No  | Seat type.<br>- Second-class seat.<br>- Second-class sleeper.<br>- First class seat.<br>- First-class sleeper.<br>- Business class seat.<br>- Hard seat.<br>- Soft seat.<br>- Hard sleeper.<br>- Soft sleeper.<br>- Deluxe soft sleeper.<br>- Standing room only.| "Second class seat"|

**Return value**

| Name | Type| Mandatory| Description                                | Example Data|
| ------ | -----| ---- |------------------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing a Map  
Requests map data of a specified type, supporting multiple map types (for example, satellite, standard, and 3D maps) and returning map-related information. 

**Intent name**: ViewMap

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description                                                           | Example Data|
|---------|-------|-------|---------------------------------------------------------------|---------|
| mapType | string | No | Map type.<br>- Satellite: satellite map.<br>- Standard: standard map (default).<br>- 3D: 3D map.| "Satellite" |

**Return value**

| Name | Type| Mandatory| Description                                | Example Data|
| ------ | -----| ---- |------------------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Subway Crowding Information

Obtains real-time crowding information for subway lines or stations to assist with trip planning.

**Intent name**: ViewMetroCrowdingInfo

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name| Type | Mandatory| Description                                                           | Example Data                                                                                               |
|------|----|----|---------------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.                  | 0                                                                                                |
| result | object | Yes | Result object, which is returned in the form of key-value pairs, with a maximum of 8000 characters.| {"lines": <br>[{"name": "Line 1", "crowding": "Lightly crowded"},<br>{"name": "Line 2", "crowding": "Moderately crowded"}]<br>} |

### Viewing Real-Time Bus Route

Queries real-time arrival information for specified bus lines in a city or area, helping users plan their trips by providing bus operation status.

**Intent name**: ViewRealTimeBusRoute

**Since**: 1.0.2

**Parameters**

| Name| Type| Mandatory| Description| Example Data|
|-----|--------|----|------|----------|
| lineName | string   | No | Bus line name/number.| "1", "Zicun Line 4"|
| province | string   | No | Province name.| "Guangdong"|
| city | string | No | City name.| "Shenzhen"|
| district | string   | No | District or county name.| "Bao'an District"|

**Return value**

| Name| Type| Mandatory| Description                                | Example Data                                                                                                 |
|-------|-----|----|------------------------------------|-------------------------------------------------------------------------------------------------------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0                                                                                                  |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Finding Electric Bicycles

Queries and locates nearby electric bicycles, returning a list of available bicycles with basic information and status to help users quickly find usable electric bicycles.

**Intent name**: FindEBicycle

**Since**: 1.0.2

**Parameters**

N/A

**Return value**

| Name| Type| Mandatory| Description                                | Example Data                                  |
|--------|---------|--------|------------------------------------|----------------------------------------|
| code | number | Yes| Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0                                   |
| result | object | Yes| Result list object. If the result list is empty, an empty value is returned.| -                                 |
| entityId | string | Yes| Execution instance ID.                         | "E11112222"                              |
| entityName | string | Yes| Execution result entity name, which is fixed.                    | "ExecutionResult"                        |
| entityLogoURL | string  | Yes| URL of the main image for the execution result.                          | `"https://example.com/bike_image.jpg"`   |
| entityDisplayName | string  | Yes| Display name (main title) of the execution result.                    | "XXX Street, Dongcheng District, Beijing"                         |
| entityDescription | string | No| Description of the execution result entity.                         | -                                    |
| statusImageUrl | string | No| URL of the status image for the execution result.                      | `"https://example.com/status_image.jpg"` |

### Viewing the Airport Large Screen

Obtains flight dynamics of a specified airport. It supports filtering of flight data by airport code and arrival/departure status, providing users with real-time airport flight operation status.

**Intent name**: ViewAirportLargeScreen

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description                                      | Example Data|
|----------|----------|----|------------------------------------------|----------|
| entityId | string | No | Intent entity ID, with a maximum of 64 characters.      | "C1132342432" |
| airportCode | string | No| Three-letter airport code.                                | "PEK" |
| inOutStatus | string | No| Arrival/Departure status.<br>- Arr: arrival.<br>- Dep: departure (default value).| "Dep" |

**Return value**

| Name| Type| Mandatory| Description  | Example Data  |
|--------|--------|----------|------------------------------------|-----------|
| code | number | Yes| Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0   |
| result | object | Yes| Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing the Real-Time Airport Status

Obtains real-time operation status information of a specified airport, including flight dynamics and arrival/departure status. It helps passengers stay informed about airport operations and plan their trips accordingly.

**Intent name**: ViewAirportStatus

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description                                    | Example Data|
|----------|----------|----|----------------------------------------|----------|
| entityId | string | No | Unique ID of the airport entity.                             | "2132432432" |
| airportCode | string | No| Three-letter airport code.                                | "PEK" |
| inOutStatus | string | No| Arrival/Departure status.<br>- Arr: arrival.<br>- Dep: departure (default value).| "Dep" |

**Return value**

| Name| Type| Mandatory| Description                                | Example Data  |
|------|-----|-----|------------------------------------|--------|
| code | number | Yes| Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0   |
| result | object | Yes| Result list object. If the result list is empty, an empty value is returned.| - |

### Setting an Electric Bicycle Lock
Remotely locks or unlocks an electric bicycle, returning the operation result in real time and providing bicycle status information (such as the main title, description, and status image) to help users conveniently manage bicycle security.

**Intent name**: SetEBicycleLock

**Since**: 1.0.2

**Parameters**

| Name| Type    | Mandatory| Description                                 | Example Data       |
|-------------|--------|----|-------------------------------------|-------------|
| operationType    | string | Yes | Operation type.<br>- Lock: Lock the bicycle.<br>- Unlock: Unlock the bicycle.| "Lock" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data               |
| ------ | ----- |----- |------------------------------------|---------------------|
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |
| entityId   | string | Yes | Intent entity ID.       | "E11112222"         |
| entityName | string | Yes | Execution result entity name, which is fixed.           | "ExecutionResult"   |
| entityLogoURL   | string | Yes | URL of the main image for the execution result.          | `"http://xxxx.png"` |
| entityDisplayName | string | Yes | Display name (main title) of the execution result.          | "Bicycle status"           |
| entityDescription   | string  | No | Description of the execution result entity.             | "Unlocked"              |
| statusImageUrl | string | No | URL of the status image for the execution result.| `"http://xxxx.png"` |

### Setting an Electric Bicycle Seat
Remotely locks or unlocks an electric bicycle seat, returning the operation result in real time and providing seat status information (such as the main title, description, and status image) to help users conveniently manage the seat status.

**Intent name**: SetEBicycleSeat

**Since**: 1.0.2

**Parameters**

| Name| Type    | Mandatory| Description                                 | Example Data       |
|-------------|--------|----|-------------------------------------|-------------|
| operationType    | string | Yes | Operation type.<br>- Lock: Lock the seat.<br>- Unlock: Unlock the seat.| "Unlock" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data               |
| ------ | ----- |----- |------------------------------------|---------------------|
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |
| entityId   | string | Yes | Intent entity ID.       | "E11112222"         |
| entityName | string | Yes | Execution result entity name, which is fixed.           | "ExecutionResult"   |
| entityLogoURL   | string | Yes | URL of the main image for the execution result.          | `"http://xxxx.png"` |
| entityDisplayName | string | Yes | Display name (main title) of the execution result.          | "Bicycle status"           |
| entityDescription   | string  | No | Description of the execution result entity.             | "Unlocked"              |
| statusImageUrl | string | No | URL of the status image for the execution result.| `"http://xxxx.png"` |

### Obtaining Electric Bicycle Device Information
Queries the device status information of an electric bicycle, allowing users to obtain basic vehicle information (such as battery level and mileage) or tire pressure details to help users monitor real-time vehicle operation status and handle exceptions promptly.

**Intent name**: GetEBicycleDeviceInfo

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                                                          | Example Data       |
|-------------|--------|----|------------------------------------------------------------------------------|-------------|
| infoType    | string | No | Type of information to retrieve.<br>- CarInfo: bicycle information (including the mileage and battery level). This is the default value.<br>- TirePressureInfo: tire pressure information (device name + tire pressure information).| "CarInfo" |

**Return value**

| Name | Type    | Mandatory| Description                                         | Example Data                |
| ------ |--------|----|---------------------------------------------|----------------------|
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |
| entityId   | string | Yes | Intent entity ID.                      | "C10194368"          |
| entityName | string | Yes | Name of the execution result entity, BicycleInfo.                       | "EBicycleDeviceInfo" |
| deviceName   | string | Yes | Device name.                                      | "My Niu Bike"              |
| batteryLevel | number | No | Remaining battery level, in units of percentage (%).                              | 30                   |
| remainingMileage   | number | No | Remaining mileage, in units of KM.                                 | 20                   |
| tirePressureInfo | object | No | Tire pressure information, including recommended tire pressure, overall status, and individual tire pressure details (tire name/pressure value/unit).| {<br>"status":"Normal", // Normal if all tire pressures are normal; Abnormal otherwise.<br> "suggestedTirePressureInfo": "Officially recommended tire pressure range is xx BAR - xx BAR",<br>"items": [{<br>"tireName": "Front tire",<br>"tirePressureValue": 1.4,<br>"unit": "BAR"<br>},<br>{<br>"tireName": "Rear tire",<br>"tirePressureValue": 1.6,<br>"unit": "BAR"<br>}]}  |

### Viewing Electric Bicycle Battery
Queries the remaining battery level of an electric bicycle, helping users learn the battery level in real time for trip planning or timely charging.

**Intent name**: ViewEBicycleBattery

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                   | Example Data       |
|-------------|--------|----|-----------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Lifestyle Domain
### Viewing Logistics  
Queries express delivery logistics information. It supports searches by tracking number or express ID, and returns the latest logistics status of the delivery.

**Intent name**: ViewLogistics

**Since**: 1.0.1

**Parameters**    

| Name| Type| Mandatory| Description                              | Example Data|
|-------------|-------|-------|----------------------------------|---------|
| trackingNo  | string  | No| Express tracking number, with a maximum of 64 characters. If empty, the home page is always displayed.           | "784314526686"|
| entityId    | string  | No| Intent entity ID, with a maximum of 64 characters. In query scenarios, this field is used by default.| "784314526686"|

**Return value**

| Name | Type| Mandatory| Description                                    | Example Data|
| ------ | ---- | ---- |----------------------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.              | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Sending Packages 
Initiates a courier service request. The system parses the request and returns the shipping operation result. 

**Intent name**: SendLogistics

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description  | Example Data|
|-------------|--------|-------|------|---------|
| sendContent | string  | No| Shipping information.| "Send a package to Zhang San via Kuaidi 100. Address: Happy Community, Chaoyang District, Beijing. Phone: 12345678901"|

**Return value**

| Name | Type| Mandatory| Description                                    | Example Data|
| ------ | -----| ---- |----------------------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.              | 0 |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Recharging Phone Bills 
Provides mobile phone top-up services. It supports recharge operations via phone number and specified amount, and returns the result of the recharge.

**Intent name**: RechargeCallFee

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description | Example Data|
|-------------|--------|-------|-----|---------|
| phoneNumber | number | No| Phone number.| 12345678901 |
| amount      | number | No| Amount, in units of CNY. | 100 |

**Return value**

| Name | Type| Mandatory| Description                      | Example Data|
| ------ | ---- | ---- |--------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0 |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Obtaining Dinning Numbers

Retrieves available table numbers from a restaurant's reservation or queuing system. Table numbers can be filtered by party size and table type, helping users quickly find suitable dining spots.

**Intent name**: GetDinningNumber

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description                                                          | Example Data|
|----------|--------|----|--------------------------------------------------------------|----------|
| number | number | No | Number of diners. Unit: person.                                                      | 5 |
| tableType | number | No | Table type.<br>- 1: small table.<br>- 2: medium table type.<br>- 3: large table.<br>- 4: private room.| 3 |

**Return value**

| Name| Type| Mandatory| Description                                | Example Data|
|-----|-----|----|------------------------------------|----------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| {"items": [{"tableNumber": "A12", "tableType": 3, "capacity": 6}]} |

### Reserving Dinning Tables

Reserves a dining table in a restaurant system for a specified date and time. Tables can be filtered by party size, table type, date, and time slot to meet personalized dining needs.

**Intent name**: ReserveDinningTable

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description                                             | Example Data|
|---------|----------|----|-------------------------------------------------|----------|
| number | number | No | Number of diners. Unit: person.                                         | 5 |
| tableType | number | No| Table type.<br>- 1: small table.<br>- 2: medium table type.<br>- 3: large table.<br>- 4: private room.| 3 |
| date | string | No| Dining date.                                         | "2024-11-30" |
| timeInterval | array | No| Dining time period, including the timestamp of the start time and end time.<br>Field type: number.           | [1637393200000, 1637396800020] |
| remark | string | No| Dining remarks, such as dining preferences.                              | - |

**Return value**

| Name| Type| Mandatory| Description                                | Example Data|
|-----|-----|----|------------------------------------|---|
| code  | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -|

### Recharging Data Bills

Provides mobile data recharge services, supporting recharge operations via phone number and amount to meet the mobile data needs of individual and enterprise users.

**Intent name**: RechargeTraffic

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description  | Example Data|
|---------|----------|-----|------|----------|
| phoneNumber | number | No  | Phone number.| 12345678901 |
| amount | number | No  | Amount, in units of CNY. | 100 |

**Return value**

|Name| Type| Mandatory| Description                                | Example Data|
|-----|-----|----|------------------------------------|----|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Phone Bills

Queries the user's phone bill information, supporting bill record filtering by date to help users track their usage of calls, SMS, and data.

**Intent name**: ViewPhoneBill

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description| Example Data|
|------|--------|----|------|----------|
| date | string | No | Query date.| "2024-05-01" |

**Return value**

|Name| Type| Mandatory| Description                                | Example Data|
|-----|-----|----|------------------------------------|----|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Phone Number Benefits

Queries the benefits and services associated with a specified phone number, including package discounts, value-added services, and bonus points, to help users fully understand the benefits of their phone number.

**Intent name**: ViewPhoneNumberBenefits

**Since**: 1.0.1

**Parameters**

N/A 

**Return value**

| Name| Type| Mandatory| Description                                | Example Data|
|--------|------|----|------------------------------------|----------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Provident Fund Information

Queries detailed information about an individual's housing provident fund account, including account balance, contribution records, and loan status. This helps users comprehensively grasp their provident fund status and supports decision-making for related services.

**Intent name**: ViewProvidentFundInfo

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name| Type| Mandatory| Description| Example Data|
|-------|-----|----|----------|------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Social Security Information

Queries multi-dimensional information about an individual's social insurance account, including pension income and expenditure, social security contribution records, account balance, and insurance certificates. This helps users fully understand their social security entitlements and status.

**Intent name**: ViewSocialSecurityInfo

**Since**: 1.0.2

**Parameters**

| Name      | Type  | Mandatory| Description                                                                                                                                                                                                                                                                                     | Example Data     |
|----------|--------|----|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------|
| type | string | No | Social security function.<br>- "ProofOfPension": pension income certificate.<br>- "PensionPaymentDetails": pension payment details.<br>- "SocialSecurityPaymentRecord": social security contribution records.<br>- "SocialSecurityBalance": social security balance.<br>- "SupplementaryPension": pension supplementary payment.<br>- "PensionInsurance": pension insurance (home page).<br>- "SocialSecurityCertificate": certificate of social security.| "ProofOfPension" |

**Return value**

| Name | Type| Mandatory| Description                                | Example Data|
| ------ | ---- | ---- |------------------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Marriage Registration

Provides access to marriage registration-related information for a specific city, including marriage registration procedures, required materials, processing locations, and divorce registration services. This function offers guidance and support to users handling marriage registration matters.

**Intent name**: ViewMarriageRegistration

**Since**: 1.0.1

**Parameters**

| Name  | Type  | Mandatory| Description                                                 | Example Data     |
|------|--------|----|-----------------------------------------------------|-----------|
| city | string | No | City information for the query.      | "Guiyang"|
| type | string | No | Marriage registration type.<br>- "Marriage": marriage (default value).<br>- "Divorce": divorce.| "Marriage" |

**Return value**

| Name | Type| Mandatory| Description                                | Example Data|
| ------ | ---- | ---- |------------------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Special Additional Deduction

Displays detailed information about special additional deductions for individual income tax, covering deduction categories such as children's education, continuing education, major illness medical expenses, housing loan interest, housing rent, elderly care, and childcare for children under 3 years old. It helps users reasonably plan their individual income tax relief.

**Intent name**: ViewSpecialAdditionalDeduction

**Since**: 1.0.1

**Parameters**

| Name     | Type  | Mandatory| Description                                        | Example Data               |
|------------|--------|----|--------------------------------------------|---------------------|
| category   | string | No | Type of special additional deduction.| "ChildrenEducation" |
| annualTime | number | No | Year. By default, the current year is used. Unit: year.                              | 2025                |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | -----| ---- |------------------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Annual Settlement

Enables users to check the comprehensive annual settlement of individual income tax for a specified year. It helps users understand key financial details such as annual income, taxable amount, taxes paid, and tax refund or supplementary payment amounts, supporting tax planning and personal financial management.

**Intent name**: ViewAnnualAccount

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory | Description          | Example Data|
|---------|--------|-----|--------------|----------|
| annualTime | number  | No  | Year. By default, the last year is used. Unit: year.| 2024 |

**Return value**

| Name| Type| Mandatory| Description| Example Data|
|-------|----|----|----------|------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Searching for Local Charging Piles

Searches for the distribution of charging piles near the user's current location or a specified area. This helps electric vehicle users quickly find available charging facilities, plan charging routes, and ease range anxiety.

**Intent name**: SearchChargingStationLocal

**Since**: 1.0.2

**Parameters**

| Name| Type| Mandatory| Description| Example Data|
|----|----------|----|------|------|
| location | string | No | Location information.| -     |

**Return value**

| Name| Type| Mandatory| Description| Example Data|
|-------|-----|----|----------|------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Utility Bills

Obtains detailed information about various utility bills for users, including but not limited to water, electricity, gas, phone, internet, and heating bills. The function supports precise location of payment accounts through multiple conditions (such as account number, community, or city), helping users quickly obtain key details like pending bill amounts, payment deadlines, and billing units. This prevents late fees or negative impacts on credit records due to overdue payments.

**Intent name**: ViewPayment

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description                                                                                 | Example Data|
|-------|--------|----|-------------------------------------------------------------------------------------|----------|
| entityId | string |No | Intent entity ID, which is used to accurately locate a specific payment record.                                                                | "C10194368" |
| entityName | string |Yes | Payment type name. Enumerated value: **Payment**.                                                             | "Payment" |
| accountNumber | number |No | Payment account number.                                                                   | 6399998888 |
| billType | number |No | Utility bill type.<br>- 0: water bill.<br>- 1: electricity bill.<br>- 2: gas bill.<br>- 3: phone bill.<br>- 4: data bill.<br>- 5: heating bill.| 0 |
| cell | string |No | Community name.                                                                               | "xx community"|
| company | string |No | Payment service provider.                                                                            | "State Grid"|
| city | string |No | City where the payment is made.                                                                             | "Nanjing"|
| address | string |No | Detailed residential address.                                                                             | "Room 501, Building ****, Longgang District, Shenzhen"|
| belongingAccount | string |Yes | Unique ID of the HUAWEI ID.                                                                         | - |

**Return value**

| Name| Type| Mandatory| Description| Example Data|
|-------|----|----|----------|------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Searching for Local Smart Devices

Supports multi-dimensional filtering by device name, type, location, and keywords to quickly locate target devices, while displaying device control options or status information.

**Intent name**: SearchSmartDeviceLocal

**Since**: 1.0.1

**Parameters**

| Name            | Type  | Mandatory| Description                            | Example Data    |
|----------------|--------|----|--------------------------------|----------|
| deviceName     | string | No | Device name.                        | "Camera 11" |
| deviceType     | string | No | Device type.<br>- Camera (default value).<br>- Lamp.| "Camera"   |
| deviceLocation | string | No | Device location.                        | "Balcony"    |
| keywords       | string | No | Search keywords.                        | "Camera inside"|

**Return value**

| Name         | Type| Mandatory| Description                               | Example Data        |
|----------------| ---- | ---- |-----------------------------------|--------------|
| code          | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0       |
| result        | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -     |
| entityId      | string | Yes  | Intent entity ID.              | "C145236"    |
| entityName    | string | Yes  | The value is fixed at "SmartDevice".             | "SmartDevice" |
| deviceName    | string | Yes  | Device name.            | "Camera in living room"    |
| deviceType    | string | Yes  | Device type.             | "Camera"       |
| deviceLocation | string | Yes  | Device location.             | "Living room"        |
| logoURL        | string | Yes  | Icon URL, which is used to display the icon of the Celia dialog card.             | -  |

### Viewing Smart Devices

Allows remote access and management of real-time footage or historical recordings from smart devices (such as cameras and monitoring devices). It supports locating target devices via unique identifiers and specifying viewing modes (real-time footage or playback), meeting users' needs for real-time monitoring of device status and tracing historical records.  

**Intent name**: ViewSmartDevice

**Since**: 1.0.1

**Parameters**

| Name          | Type  | Mandatory| Description                                                            | Example Data     |
|--------------|--------|----|----------------------------------------------------------------|-----------|
| entityId     | string | No | Unique identifier of the device.                                                      | "C145236" |
| functionType | object | No | Device function type, such as playback and real-time footage.<br>- Playback: View historical recordings.<br>- LiveVideo: real-time footage (default value).| "Playback"  |

**Return value**

| Name | Type | Mandatory| Description                     | Example Data|
| ------ | -----| ---- |-------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.  | -    |

### Viewing Rental Information

Searches for detailed information about specific rental listings, including basic property details, rental prices, geographical locations, and amenities, to assist users in making informed rental decisions.

**Intent name**: ViewRentingHouseInfo

**Since**: 1.0.1

**Parameters**

| Name      | Type  | Mandatory| Description             | Example Data     |
|----------|--------|----|-----------------|-----------|
| entityId | string | No | Intent entity ID, with a maximum of 64 characters.| "12949589" |
| extras | object | No | Other information, specified by the service that accesses the framework.| -        |

**Return value**

| Name | Type| Mandatory| Description                     | Example Data|
| ------ | ---- | ---- |-------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.  | -    |

### Viewing Property Purchase Information

Provides access to property purchase-related information, supporting the retrieval of real estate data by specific entities (such as property IDs) or additional filtering conditions (such as area or price).

**Intent name**: ViewBuyingHouseInfo

**Since**: 1.0.1

**Parameters**

| Name      | Type  | Mandatory| Description             | Example Data     |
|----------|--------|----|-----------------|-----------|
| entityId | string | No | Intent entity ID, with a maximum of 64 characters.| "12949589" |
| extras | object | No | Other information, specified by the service that accesses the framework.| -        |

**Return value**

| Name | Type | Mandatory| Description                     | Example Data|
| ------ | -----| ---- |-------------------------| -------- |
| code   | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.| 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.  | -    |

### Viewing Utility Bills
Queries detailed information about the user's utility bills, supporting filtering by payment type (such as water, electricity, or gas bills). It returns the result status to help users monitor the real-time payment status of various utilities and avoid additional fees due to overdue payments.

**Intent name**: ViewUtilityBill

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                   | Example Data     |
|-------------|--------|----|---------------------------------------|-----------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.                  | "E123456" |
| billType    | number | No | Payment type.<br>- 0: water bill.<br>- 1: electricity bill.<br>- 2: gas bill.<br>- 3: phone bill.<br>- 4: data bill.| 3         |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Searching for Local Power Bank Locations
Searches for nearby power bank rental or return locations, supporting filtering by keywords and distinguishing between rentable, returnable, or all types of locations. This helps users quickly find the nearest power bank services.

**Intent name**: SearchPowerBankStationLocal

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                              | Example Data   |
|-------------|--------|----|--------------------------------------------------|---------|
| location    | object | No | Longitude and latitude of the location. Latitude range: [-90, 90]; longitude range: [-180, 180]. | {locationSystem:"GCJ02/BD09LL",latitude:"22.33",longitude:"12.33"} |
| keywords    | string | No | Search keywords.| "Near Tian'an Cloud Valley, Bantian Street"       |
| category    | string | No | Category of the power bank location.<br>- Rentable: Users can rent power banks.<br>- Returnable: Users can return power banks.<br>- All: all locations.| "Rentable"        |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Power Bank Locations
Queries the location information of power bank rental or return outlets. It supports precise searches using the unique identifier of the intent entity, as well as filtering nearby outlets by geographical location and category, helping users quickly find available power bank services.

**Intent name**: ViewPowerBankStation

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                              | Example Data   |
|-------------|--------|----|----------------------------------|---------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.             | "145236"        |
| location    | object | No | Longitude and latitude of the location. Latitude range: [-90, 90]; longitude range: [-180, 180].| {locationSystem:"GCJ02/BD09LL",latitude:"22.33",longitude:"12.33"} |
| category    | string | No | Category of the power bank location.<br>- Rentable: Users can rent power banks.<br>- Returnable: Users can return power banks.<br>- All: all locations.| "Rentable"        |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Reserved Tickets
Searches for ticket information that users have reserved or are in the process of snatching (such as for performances, transportation, or events), and returns details including reservation status, ticket specifics, and snatching results.

**Intent name**: ViewReservedTicket

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                   | Example Data       |
|-------------|--------|----|---------------------------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.                  | "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Business Districts
Retrieves detailed information about a specified business district, such as merchant distribution, events, and location. It supports precise searches using the unique identifier of the intent entity and returns basic business district data and status.

**Intent name**: ViewMall

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                   | Example Data       |
|-------------|--------|----|---------------------------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.                  | "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Government Services
Obtains lists of local government services or specific administrative handling information (such as service guidelines, reservation status, and policy announcements). It supports filtering by service type as needed and returns government service data results.

**Intent name**: ViewGovernmentService

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### View Living Index
Queries specified types of living index information (such as air quality, ultraviolet intensity, clothing suggestions, and comfort index), helping users understand current and future living environment indicators to assist in daily decision-making.

**Intent name**: ViewLivingIndex

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                   | Example Data       |
|-------------|--------|----|---------------------------------------|-------------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.                  | "C245885" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## News Domain
### Viewing the Ranking List

Retrieves the content list of a specific ranking. It supports filtered queries by ranking content ID, or fetches default ranking content when no ranking content ID is specified.

**Intent name**: ViewRankingList

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description             | Example Data|
|-----|--------|--------|-----------------|----------|
| entityId | string | No| Intent entity ID, with a maximum of 64 characters.| "C10194368" |
| rankingContentId | number | No| Ranking content ID.        | 1234567 |

**Return value**

| Name | Type | Mandatory| Description                                    | Example Data|
| ------ | ------| ---- |----------------------------------------| -------- |
| code  | number  | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.              | 0  |
| result | object  | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Columns

Obtains the content list of a specific column. It allows filtered queries by column title, or retrieves default column content when no title is specified.

**Intent name**: ViewColumn

**Since**: 1.0.1

**Parameters**

| Name| Type| Mandatory| Description             | Example Data|
|------|-------|--------|-----------------|----------|
| entityId | string | No| Intent entity ID, with a maximum of 64 characters.| "C10194368" |
| columnTitle | string | No| Column title.          | "ETF" |

**Return value**

| Name | Type| Mandatory| Description                                   | Example Data|
| ------ |-----| ---- |---------------------------------------| -------- |
| code  | number  | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.              | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Blogs

Obtains the list of news blog content under a specific category. It supports queries by blog channel category, and returns default blog content when no category is specified.

**Intent name**: ViewBlog

**Since**: 1.0.1

**Parameters**

| Name| Type   | Mandatory| Description                              | Example Data|
|--------------|---------|---|----------------------------------|----------|
| entityId | string  | No| Intent entity ID, with a maximum of 64 characters.  | "C10194368" |
| blogCategory | string  | No| News blog channel category. Example:<br>- Travel.<br>- Life.<br>- Military.<br>- Technology.<br>- Culture.<br>- Food.<br>- Automobile.| "Travel"|

**Return value**

| Name| Type| Mandatory| Description                                | Example Data                                                          |
|-------|-------|---|------------------------------------|----------------------------------------------------------------|
| code | number | Yes| Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0                                                           |
| result | object | Yes| Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Column Updates 

Checks the latest updated content of a specific column. It can accurately locate details of a single update via the update ID or retrieve a batch update list for the column, helping users track updates of interested columns in a timely manner.

**Intent name**: ViewColumnUpdate

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description              | Example Data|
|-------------|--------|------|------------------|---------|
| entityId    | string | No  | Intent entity ID, which is the column update ID. The value contains a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Books Domain
### Reading Books   

Obtains the reading permission and content data of a specified book. It supports accurate queries by book ID and returns the reading result status along with book metadata information.

**Intent name**: ReadBook

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description                     | Example Data|
|-----|--------|----|-------------------------|----------------|
| entityId | string | Yes | Intent entity ID, which is the book ID. The value contains a maximum of 64 characters.| "C10194368" |

**Return value**

| Name| Type| Mandatory| Description                                                                                                                                                                                                                                                                                                                                             | Example Data|
|---------|----|----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------|
| code | number  | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.<br>[Error type 1] User reasons:<br>- 100060101: Member articles and paid articles cannot be read.<br>- 100060102: The membership has expired, and there are no preview chapters in the article.<br>[Error type 2] Content range restrictions:<br>- 100060201: Reading is not supported for articles that have child protection enabled, are associated with a child account, or are marked as inappropriate.<br>- 100060202: The article has been removed and cannot be read.<br>- 100060203: The copyright of the article on this platform has expired and therefore the article cannot be read.<br>[Error type 3] Internal service exceptions:<br>- 100060301: The article/author has been added to the blocklist and therefore the article cannot be read.<br>[Error type 4] Internal system exceptions:<br>- 100060401: The software is faulty.| 100060101 |
| result | object  | Yes | Result object, which is returned in the form of key-value pairs, with a maximum of 8000 characters.                                                                                                                                                                                                                                                                                       | {"bookSize":"4M","dataReceiveTime":1704868765000} |

## ShoppingPlatformsDomain
### Viewing Commodities

Queries detailed information of specified commodities through commodity links or intent entity IDs, catering to needs in various scenarios.

**Intent name**: ViewCommodity

**Since**: 1.0.2

**Parameters**

| Name| Type| Mandatory| Description                          | Example Data|
|--------------|----------|---|------------------------------|----------|
| entityId | string | No| Intent entity ID, with a maximum of 64 characters.             | "C10194368" |
| shareLink | string | No| Commodity link text (no more than 1500 characters). Choose either this parameter or **entityId**.| `"https://example.com/product/12345"` |

**Return value**

| Name| Type| Mandatory| Description                                | Example Data|
|-------|------|----|------------------------------------|----------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| {"items": [{"productId": "12345", "name": "Sample product","price":99.99}]}|

### Viewing Shopping Guides

Retrieves guide information for specific shopping scenarios or commodities via the intent entity ID, providing users with professional shopping guidance.

**Intent name**: ViewShoppingGuide

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description             | Example Data|
|--------------|--------|----|-----------------|----------|
| entityId | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name| Type| Mandatory| Description                                | Example Data  |
|-----|-----|----|------------------------------------|-------------------------|
| code | number | Yes | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0  |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

## Health Domain
### Viewing Medical Insurance Code

Triggers the system to query and display the currently valid medical insurance code. It is suitable for offline medical expense settlement or other medical insurance-related services.

**Intent name**: ViewMedicalInsuranceCode

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type| Mandatory| Description                        | Example Data|
| ------ | ---- | ---- |----------------------------| -------- |
| code | number | Yes | Result code. Customization is supported.          | 0  |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| - |

### Viewing Medical Insurance Information

Queries basic information, participation status, payment records, and benefit entitlement status of the medical insurance account, making it easy to keep track of account dynamics and rights in real time.

**Intent name**: ViewMedicalInsuranceInfo

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type| Mandatory| Description                                | Example Data|
| ------ | ---- | ---- |------------------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Hospitals

Searches for detailed information of specified medical institutions, including basic information, department services, and geographical location, facilitating understanding of the hospital or informed medical decision-making.

**Intent name**: ViewHospital

**Since**: 1.0.1

**Parameters**

| Name   | Type  | Mandatory| Description             | Example Data       |
|----------|--------|----|-----------------|-------------|
| entityId | string | Yes | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | -----| ---- |------------------------------------| -------- |
| code  | number | Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.          | 0  |
| result | object | Yes  | Result list object. If the result list is empty, an empty value is returned.| -       |

### Searching for Hospitals
Queries hospital information within a specified city and region, supports precise filtering by keywords, and returns detailed hospital information (such as address, business hours, and tags), helping users quickly locate target medical institutions.

**Intent name**: SearchHospital

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description              | Example Data|
|-------------|--------|----|------------------|---------|
| city    | string | Yes |City where the physical examination center is located.| "Beijing"|
| district    | string | No | District.| "Fengtai District"|
| keywords    | string | No | Keywords.| "Jianguomen"|

**Return value**

| Name | Type    | Mandatory| Description               | Example Data     |
| ------ |--------|----|-------------------|-----------|
| entityId   | string | Yes | Intent entity ID.       | "C10194368" |
| entityName | string | Yes | Entity name.            | "Hospital" |
| hospitalName   | string | Yes | Hospital name.            | "Ankang**** Branch"|
| description | string | Yes | Hospital description.            | "Great experience"      |
| tags   | array  | No | Tags.              | ["Free Wi-Fi," "With VIP inspection area"]       |
| openingTime | string | No | Business hours.| "Monday to Wednesday, Friday to Sunday: 07:40-15:00"         |
| hospitalAddress   | string | No | Hospital address.| "2nd Floor, **** Building, Dongcheng District, Beijing"       |
| distance | number | No | Distance, in units of meters. The input parameter depends on the latitude and longitude information passed in the parameters.| 2520       |
| logoURL   | string | No | Image path.| `"http://xxxx.png"`          |

### Viewing Follow-Up Appointments
Queries patients' follow-up appointment details, including key information like follow-up time, department, and attending doctor, helping patients stay informed and manage subsequent medical arrangements.

**Intent name**: ViewFollowUpVisit

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                   | Example Data       |
|-------------|--------|----|-----------------------|-------------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Outpatient Registration
Checks users' outpatient registration records, including key details such as the registered department, doctor, and visit time, assisting users in managing their medical plans and staying updated on registration status.

**Intent name**: ViewOutpatientRegistration

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                   | Example Data       |
|-------------|--------|----|-----------------------|-------------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Tools Domain
### Viewing Payment Code

Retrieves and displays currently valid payment code information. It is suitable for offline payment scenarios.

**Intent name**: ViewPaymentCodes

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | -------| -------- |------------------------------------| -------- |
| code  | number | Yes      | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.           | 0  |
| result | object | Yes      | Result list object. If the result list is empty, an empty value is returned.| -       |

### Starting Scanning

Triggers the system to activate the device camera for code scanning or image recognition, then displays the scan results. It supports multiple modes, including general code scanning, text extraction, translation, object recognition, and document scanning.

**Intent name**: OpenScan

**Since**: 1.0.1

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                                                                                                                                                                              | Example Data|
|----|--------|----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------|
|  scanFunction  | string | No| Scanning function.<br>- General: general scanning.<br>- "RecognizeText": text extraction/recognition.<br>- "RecognizeTranslation": recognition and translation.<br>- "RecognizeObjects": object recognition.<br>- "ScanCertificate": certificate scanning.<br>- "ScanIDCard": ID card scanning.<br>- "ScanHouseholdRegistrationRecord": household registration record scanning.<br>- "ScanPassport": passport scanning.<br>- "ScanDriverLicense": driver's license scanning.<br>- "ScanVehicleLicense": vehicle license scanning.<br>- "ScanBankCard": bank card scanning.<br>- "ScanHousePropertyCard": house property certificate scanning.<br>- "ScanBusinessLicense": business license scanning.<br>- "EraseHandwriting": handwriting erasing or test paper restoration.| "General" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ------- | -------- |------------------------------------| -------- |
| code  | number | Yes      | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.           | 0  |
| result | object | Yes      | Result list object. If the result list is empty, an empty value is returned.| -       |

### Contact Customer Service

Connects to the customer service system to obtain support, resolve usage issues, or consult relevant information.

**Intent name**: ContactCustomerService

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- | -------- |------------------------------------| -------- |
| code  | number | Yes      | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.           | 0  |
| result | object | Yes      | Result list object. If the result list is empty, an empty value is returned.| -       |

### Creating Accounts

Creates an account, including completing information verification and initialization procedures.

**Intent name**: CreateNewAccount

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ------- | -------- |------------------------------------| -------- |
| code  | number | Yes      | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.           | 0  |
| result | object | Yes      | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Account Balance

Queries categorized account balance information (such as data traffic, voice minutes, SMS allowances, and phone bill balance).

**Intent name**: ViewRemain

**Since**: 1.0.1

**Parameters**

| Name      | Type  | Mandatory| Description                                                                                                                                                                                                                                                                                                                                                                                                                         | Example Data|
|----------|--------|----|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------|
| category | string | No| Balance category.<br>- DataTraffic: data traffic.<br>- VoiceTraffic: voice traffic.<br>- SMSTraffic: SMS traffic.<br>- MobileAccountBalance: phone bill balance.| "DataTraffic" |


**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ------ | -------- |------------------------------------|------|
| code  | number | Yes      | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.           | 0 |
| result | object | Yes      | Result list object. If the result list is empty, an empty value is returned.| -  |

### Viewing Ordered Services 
Retrieves information about services users have subscribed to. It supports filtering by service category (such as data traffic, voice minutes, and SMS allowances), and returns subscription details.

**Intent name**: ViewOrderedBusiness

**Since**: 1.0.1

**Parameters** 

| Name| Type | Mandatory| Description              | Example Data|
|-------------|--------|------|------------------|---------|
| category    | string | No  | Balance category.<br>- DataTraffic: data traffic.<br>- VoiceTraffic: voice traffic.<br>- SMSTraffic: SMS traffic.| "DataTraffic" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Cloud Backup
Checks the status and content of current cloud backups, including backup types (such as photo albums and contacts).

**Intent name**: ViewCloudBackup

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description                                                                                                                | Example Data|
|-------------|--------|------|--------------------------------------------------------------------------------------------------------------------|---------|
| backupType    | string | No  | Backup type.<br>- Gallery: album.<br>- Contact: contacts.| "Contact" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Sending Red Packets
Initiates a red packet distribution operation, allowing users to specify the total amount, individual red packet amount, number of red packets, red packet type (ordinary, lucky draw, or good luck), and remarks (blessings).

**Intent name**: SendRedPacket

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description    | Example Data      |
|-------------|--------|------|--------|------------|
| totalAmount    | number | No  | Total amount of red packets. in units of CNY.| 88.88   |
| amount    | number | No  | Amount of a single red packet. in units of CNY.| 2.00    |
| packetNumber    | number | No  | Number of red packets. Unit: piece.| 2       |
| type    | string | No  | Red packet type.<br>- Ordinary: ordinary red packet.<br>- FightingLuck: lucky draw red packet.<br>- GoodLuck: good luck red packet.| "Ordinary" |
| remarks    | string | No  | Red packet blessing.| "Happy Birthday"    |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Opening Search Pages
Opens the in-application search page, supports inputting initial search content, and returns the operation result status along with possible search suggestions or historical records.

**Intent name**: ViewSearchPageLocal

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description   | Example Data|
|-------------|--------|----|-------|------|
| query    | string | Yes | Search content.| -    |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Jumping to Function Pages
Triggers the client to navigate to a specified in-application function page. It supports passing the target page identifier via standardized parameters and returns the operation execution status.

**Intent name**: JumpFunctionPage

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description   | Example Data|
|-------------|--------|----|-------|------|
| pageId    | string | Yes | Identifier of a specific function.| -    |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Check In
Completes check-in operations (such as sign-in or task completion marking) within the application. It allows passing an entity's unique identifier for precise check-in and returns the operation result status and related data.

**Intent name**: PunchIn

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description        | Example Data|
|-------------|--------|----|------------|------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Business Domain
### Joining Meetings
Joins a specified meeting. It supports precise targeting of the meeting through parameters such as meeting ID, participant list, and meeting type, and returns the operation result status and data.

**Intent name**: StartMeeting

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                        | Example Data|
|-------------|--------|------|----------------------------|---------|
| conferenceId    | string | No  | Unique ID of a meeting.                   | "A10194368" |
| participantIds    | array  | No  | List of participants, corresponding to **entityId** of the contact entity.   | ["C111", "C112","C114"]|
| conferenceType    | string | No  | Meeting type.<br>- Video: video.<br>- Audio: audio.| "Video" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Job Information
Queries work-related information associated with a user or enterprise, including key data like position, company, employment date, and salary, and returns the operation result status and data. It ensures users can track work dynamics in real time or enterprises can efficiently manage employee records, supporting scenarios such as recruitment, career planning, and personnel management.

**Intent name**: ViewJobInfo

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                        | Example Data|
|-------------|--------|------|----------------------------|---------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Education Domain
### Viewing School Timetable
Retrieves the user's class schedule, supports returning course arrangements for the current cycle (such as week/month), and returns the operation status.

**Intent name**: ViewSchoolTimetable

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing the School Calendar
Obtains the current school's academic calendar, including semester schedules, holidays, and key dates (such as the start of the school year and exam weeks), and returns the operation result status and data.

**Intent name**: ViewSchoolCalendar

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Finance Domain
### Viewing Repayment
Queries the user's repayment plans or records, supports precise targeting of a specific repayment item via the specified repayment entity ID, or returns all pending repayment records, and provides the operation result status and data.

**Intent name**: ViewRepayment

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                        | Example Data|
|-------------|--------|----|----------------------------|---------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Account Changes
Queries transaction details or fund movement records of the user's bank account. It supports multi-dimensional filtering of target transactions by intent entity ID, last four digits of the bank card, card type, and time period, and returns the operation result status and movement records.

**Intent name**: ViewAccountChange

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                     | Example Data       |
|-------------|--------|----|-----------------------------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.                    | "C10194368" |
| cardTailNumber    | string | No | Last four digits of the bank card.                             | "1234"        |
| cardType    | string | No | Bank card type.<br>- CreditCard: credit card.<br>- SavingsCard: debit card.| "CreditCard" |
| timeInterval    | array  | No | Transaction time range, which is an array of start and end timestamps (UTC timestamp).        | [163739320000,163739320000] |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Account Change Functions
Queries transaction details or fund movement records of the user's bank account. It supports multi-dimensional filtering of target transactions by intent entity ID, last four digits of the bank card, card type, and time period, and returns the operation result status and movement records.

**Intent name**: ViewAccountChangeFunc

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                               | Example Data       |
|-------------|--------|----|---------------------------------------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.                              | "C10194368" |
| cardTailNumber    | string | No | Last four digits of the bank card.                                       | "1234"        |
| cardType    | string | No | Bank card type.<br>- CreditCard: credit card.<br>- SavingsCard: debit card.| "CreditCard" |
| timeInterval    | array  | No | Transaction time range, which is an array of start and end timestamps (UTC timestamp).                  | [163739320000,163739320000] |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Paying Repayment
Initiates a repayment payment or queries repayment records. It supports precise targeting of the repayment account and business type via the last four digits of the bank card and repayment type (credit card/consumer loan), and returns the operation result status and repayment data.

**Intent name**: PayRepayment

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                               | Example Data       |
|-------------|--------|----|---------------------------------------------------|-------------|
| cardTailNumber    | string | No | Last four digits of a bank card, with a maximum of 16 characters.           | "1234"        |
| repaymentType    | string | No | Repayment type.<br>- CreditCard: credit card.<br>- ConsumerLoan: consumer loan.| "CreditCard" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Wealth Management Products
Queries a list of wealth management products or retrieves details of specific products. It supports precise filtering by product name and type (current/term), and returns the operation result status and product data.

**Intent name**: ViewWealthManageProduct

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description      | Example Data    |
|-------------|--------|----|----------|----------|
| wealthManageName    | string | No | Name of the wealth management product.   | "Chaochao Ying"   |
| wealthManageType    | string | No | Type of wealth management product.<br>- Current: current wealth management.<br>- Regular: regular wealth management.| "Current" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Applying for Credit Cards
Submits a credit card application, supports passing necessary application information, and returns the operation result status.

**Intent name**: ApplyCreditCard

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Initiating Transfers
Initiates a transfer to a specified payee. It supports fund transfers via payee information (including name, card number, last four digits, and bank name) and transfer amount, and returns the result status and transaction details.

**Intent name**: InitiateFundsTransfer

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description           | Example Data          |
|-------------|--------|----|---------------|----------------|
| payee    | string | No | Payee.         | "Zhang San"          |
| amount    | number | No | Amount,          | 1000           |
| cardNumber    | string | No | Payee's card number.       | "11223344556677" |
| cardTailNumber    | string | No | Last four digits of the payee's bank card.| "1234"           |
| openingBank    | string | No | Payee's bank name.      | "Bank XX Branch XX"  |
| remark    | string | No | Remarks.          | -              |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Account Balance
Queries the user's account balance, supports returning the total available funds in the current account, and returns the operation result status.

**Intent name**: ViewAccountBalance

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Private Pension
Queries key information of the user's private pension account, including total account balance, contribution records, and income status, and returns the result status. This ensures users can timely and accurately grasp the latest status of their private pension accounts, providing data support for retirement planning.

**Intent name**: ViewPrivatePension

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Credit Reports
Queries the user's personal credit report, covering key information such as credit score, loan records, and overdue status, and returns the result status. It ensures users can securely obtain their credit status in a timely manner, offering a reliable basis for financial decisions.

**Intent name**: ViewCreditReport

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Bank Branch Information
Queries bank branch information within a specified area or under specific conditions, including key data such as branch address, business hours, and contact number, and returns the result status. This helps users quickly obtain accurate information about target branches, enhancing offline service experience.

**Intent name**: ViewBankBranchInfo

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Stock Issuance Updates
Queries the latest issuance information of new stocks and bonds, including key data such as issuance lists, subscription periods, and issue prices, and returns the result status. It ensures investors stay updated on market dynamics to support efficient subscription decisions.

**Intent name**: ViewStockIssuedUpdated

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                        | Example Data|
|-------------|--------|----|----------------------------|---------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Selected Stocks
Queries detailed information of the user's selected stocks, including key data such as real-time stock price, price change percentage, and trading volume, and returns the result status. This allows users to timely track dynamic changes in their selected stocks, aiding investment decisions.

**Intent name**: ViewSelectedStock

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                        | Example Data|
|-------------|--------|----|----------------------------|---------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Stock Issuance Calendar
Queries the calendar of upcoming new stock issuance, including key data such as issuance date, stock name, subscription code, and issue price, and returns the result status. It ensures investors obtain the new stock issuance schedule in a timely manner, supporting informed subscription decisions.

**Intent name**: ViewStockIssuedCalendar

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Buying Stocks
Submits a stock purchase order to the securities trading platform. It supports precise targeting of the stock via the stock name or the combination of stock market and stock code, allows specifying the purchase price and quantity, and returns the result status.

**Intent name**: BuyStock

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                                                                                                   | Example Data      |
|-------------|--------|----|-----------------------------------------------------------------------------------------------------------------------|------------|
| stockName    | string | No | Stock name. Example:<br>- Shanghai Composite Index.<br>Enter either the stock name or the combination of the stock market and stock code must be specified.     | "Shanghai Composite Index"    |
| stockSymbol    | string | No | Stock code, which is unique globally. Example:<br>- 000001: stock code for the Shanghai Composite Index.<br>Enter either the stock name or the combination of the stock market and stock code must be specified.      | "SH000001" |
| stockMarket    | string | No | Stock market. Example:<br>- SH: Shanghai Stock Exchange.<br>- SZ: Shenzhen Stock Exchange.<br>- BJ: Beijing Stock Exchange.<br>This parameter must be used together with the stock code.| "SH"       |
| purchasePrice    | number | No | Purchase price of the stock. in units of CNY.| 15.11      |
| purchaseQuantity    | number | No | Quantity of stocks to buy. Unit: share.| 2000       |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Selling Stocks
Submits a stock sale order to the securities trading platform. It supports precise targeting of the stock via the stock name or the combination of stock market and stock code, allows specifying the selling price and quantity, and returns the result status.

**Intent name**: SellStock

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                                                                                       | Example Data      |
|-------------|--------|----|-----------------------------------------------------------------------------------------------------------|------------|
| stockName    | string | No | Stock name. Example:<br>- Shanghai Composite Index.<br>Enter either the stock name or the combination of the stock market and stock code must be specified.   | "Shanghai Composite Index"    |
| stockSymbol    | string | No | Stock code, which is unique globally. Example:<br>- 000001: stock code for the Shanghai Composite Index.<br>Enter either the stock name or the combination of the stock market and stock code must be specified.| "SH000001" |
| stockMarket    | string | No | Stock market. Example:<br>- SH: Shanghai Stock Exchange.<br>- SZ: Shenzhen Stock Exchange.<br>- BJ: Beijing Stock Exchange.<br>This parameter must be used together with the stock code. | "SH"       |
| sellingPrice    | number | No | Selling price of the stock. in units of CNY.            | 15.11      |
| sellQuantity    | number | No | Quantity of stocks to sell. Unit: share.      | 2000       |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Stock Market Quotes
Queries real-time quote data of major global stock markets, including core indicators such as index points, price change percentage, and trading volume, and returns the result status. It ensures users can quickly grasp the overall market trend, aiding investment decisions.

**Intent name**: ViewStockMarketQuote

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                 | Example Data|
|-------------|--------|----|-------------------------------|------|
| marketArea    | string | No | Market area of the market index.<br>- CN: China market (Shanghai and Shenzhen A-shares)<br>- US: US market.<br>- HK: Hong Kong market. | "CN" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Fund Details
Queries detailed information of a specified fund, including core data such as net asset value, historical performance, fund manager, and asset allocation, and returns the result status. This enables investors to fully understand the characteristics of fund products, supporting investment decisions.

**Intent name**: ViewFund

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                        | Example Data|
|-------------|--------|----|----------------------------|---------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.| "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Fund Returns
Queries the return status of a specified fund or the user's held funds, including key data such as cumulative returns, stage gains (such as past 1 month/past 1 year), and dividend records. It returns the result status, ensuring that investors can timely grasp the fund return performance and assist in investment evaluation and decision-making.

**Intent name**: ViewFundReturns

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Insurance Policies
Queries user insurance policy information, supports precise filtering of target policies via policy entity ID or insurance type, and returns the result status and policy data. It ensures users can quickly obtain key policy information, with clear and transparent rights and interests.

**Intent name**: ViewInsurancePolicy

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                                                                                             | Example Data       |
|-------------|--------|----|-----------------------------------------------------------------------------------------------------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.                                                                                            | "C10194368" |
| insuranceType    | string | No | Insurance type.<br>- Car: car insurance.<br>- TrafficCompulsory: compulsory traffic insurance.<br>- Health: health insurance.<br>- Accident: accident insurance.<br>- Property: property insurance.<br>- Travel: travel insurance.<br>- Pet: pet insurance.<br>- Enterprise: enterprise insurance.| "Car"       |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Overdrafts
Queries the usage and credit limit information of a user's overdraft facility (a credit payment tool), including key data such as available limit, used limit, and bill details, and returns the result status. This helps users real-time track their overdraft account status, facilitating rational planning of credit consumption.

**Intent name**: ViewOverdraft

**Since**: 1.0.1

**Parameters**

N/A

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Applying for Insurance Claims
Submits an insurance claim application, supports precise targeting of the policy via policy entity ID or insurance type, and allows submitting key claim information (such as accident description/amount), and returns the result status.

**Intent name**: ApplyInsuranceClaim

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description                                                                                                             | Example Data       |
|-------------|--------|----|-----------------------------------------------------------------------------------------------------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.                                                                                            | "C10194368" |
| insuranceType    | string | No | Insurance type.<br>- Car: car insurance.<br>- TrafficCompulsory: compulsory traffic insurance.<br>- Health: health insurance.<br>- Accident: accident insurance.<br>- Property: property insurance.<br>- Travel: travel insurance.<br>- Pet: pet insurance.<br>- Enterprise: enterprise insurance.| "Car"       |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Buying Vehicle Insurance
Initiates the online vehicle insurance purchase process, supports submitting a vehicle insurance application via the policy entity ID (for example, for renewal) or in a new insurance mode, and returns the result status and policy data.

**Intent name**: BuyVehicleInsurance

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description     | Example Data       |
|-------------|--------|----|-------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.  | "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Travel Domain
### Searching for Local Travel Guides
Searches for local travel guide information (such as attraction introductions, travel routes, city recommendations) based on user-input keywords, geographic location, city scope, or guide type, and returns the result status. It ensures users quickly obtain accurate travel guides, improving travel planning efficiency.

**Intent name**: SearchTravelLocal

**Since**: 1.0.1

**Parameters**

| Name| Type | Mandatory| Description                                              | Example Data                                                                                                                       |
|-------------|--------|------|--------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------|
| keywords    | string | No  | Search keywords, such as attraction names. Use commas (,) to separate multiple search keywords.                     | "Palace Museum","What's fun in Jiangning"                                                                                                            |
| location    | object | No  | Longitude and latitude of the location. Latitude range: [-90, 90]; longitude range: [-180, 180]. | {"locationSystem":"GCJ02/BD09LL","locationName": "xxxx","latitude": "120.785645", "longitude": "33.039635", "address":"xxx"}|
| city    | string | No  | Used to filter non-local records by city in scenarios such as searching for attraction names.                       | "Shenzhen"                             |
| travelGuidesType    | string | No  | Type of travel guide.<br>- Scenic: Scenic spot guide.<br>- CitySelection: city selection.| "CitySelection"      |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Travel Guides
Queries detailed information of specified travel guides, including guide content, applicable scenarios, and associated attractions or cities, and returns the result status. This allows users to quickly access complete information about target guides, aiding travel decisions.

**Intent name**: ViewTravelGuides

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description     | Example Data       |
|-------------|--------|----|-------------------|-------------|
| entityId    | string | No | Intent entity ID, with a maximum of 64 characters.  | "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

### Viewing Scenery Orders
Queries detailed information of a user's purchased scenic spot ticket orders, including key data such as attraction name, admission time, ticket type, and order status, and returns the result status. It ensures users real-time track order status and admission information, enhancing the visiting experience.

**Intent name**: ViewSceneryOrder

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description     | Example Data       |
|-------------|--------|----|-------------------|-------------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.  | "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |

## Lodging Domain
### Viewing Hotel Appointment Information
Queries detailed information of a user's hotel booking orders, including key data such as hotel name, check-in time, room type, and order status, and returns the result status. It ensures users real-time track order status and hotel service information, improving the check-in experience. 

**Intent name**: ViewHotelAppointmentInfo

**Since**: 1.0.1

**Parameters**

| Name| Type    | Mandatory| Description     | Example Data       |
|-------------|--------|----|-------------------|-------------|
| entityId    | string | Yes | Intent entity ID, with a maximum of 64 characters.  | "C10194368" |

**Return value**

| Name | Type | Mandatory| Description                                | Example Data|
| ------ | ----- |----- |------------------------------------| -------- |
| code   | number| Yes  | Result code. The value **0** indicates success while other values indicate failure. Customization is supported.    | 0 |
| result | object | Yes | Result list object. If the result list is empty, an empty value is returned.| -       |
