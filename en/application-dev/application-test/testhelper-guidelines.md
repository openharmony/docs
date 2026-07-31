# Testhelper Usage Guide

<!--Kit: Test Kit-->
<!--Subsystem: Test-->
<!--Owner: @inter515-->
<!--Designer: @inter515-->
<!--Tester: @laonie666-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=61c79120c699ac5e30edda72b78659f62c6aaf57 translatedAt=2026-07-28T07:30:14.259Z pushedAt=2026-07-30T06:47:38.861Z -->

## Overview

The testhelper provides developers with system state management and environment simulation capabilities, supporting functions such as time setting, clipboard management, input method management, font management, display mode switching, and location simulation, helping developers quickly configure test environments.

Devices running OpenHarmony 7.0.0 or later support this tool.

## Function Overview

The functional architecture design of testhelper is shown below:


testhelper is divided into two parts: the command-line tool layer and the core capability layer, relying on underlying system services for functional support.

**Command-line tool layer:** Serves as the user interaction entry point, responsible for receiving and processing user-input commands.

**Core capability layer:** Includes three parts: parameter parsing and validation, command execution processing, and service communication management, responsible for the core function processing of testhelper.

**System service dependency:** testhelper relies on underlying system services to implement specific functions, including time and time zone service, clipboard service, input method framework, font management, ArkUI framework, location service, etc. testhelper invokes these services through IPC.

## Detailed command description

### testhelper help

Displays the help information of the testhelper tool, including all available commands and their usage.

**Usage example:**

```bash
hdc shell testhelper help
```

Output example:

```bash
Usage:
  testhelper <command> [options]

Commands:
  get-time           Get current system time
  set-time <time>    Set system time (format: YYYY-MM-DD HH:MM:SS)
  get-timezone       Get current system timezone
  set-timezone <timezone>  Set system timezone (e.g., Asia/Shanghai)
  get-pastedata      Get pasteboard text content
  set-pastedata <text>     Set pasteboard text content
  clear-pastedata    Clear pasteboard content
  hide-keyboard      Hide input method keyboard
  get-fontname <font-path> Get font name from font file (/data/local/* files only)
  install-font <font-path>  Install font from font file (/data/local/* files only)
  uninstall-font <font-name>  Uninstall font by font name
  set-viewmode <dark|light>  Set view mode (dark or light)
  enable-location-mock     Enable location mock functionality
  disable-location-mock    Disable location mock and restore real location
  set-mocked-locations <path> [interval] Set mocked locations from GPX file
  help               Show this help message
  --version          Show version information
```

### testhelper --version

Displays the version information of the testhelper tool.

**Usage example:**

```bash
hdc shell testhelper --version
```

Output example: `1.0.1`

### testhelper get-time

Gets the current system time.

**Usage example:**

```bash
hdc shell testhelper get-time
```

Output example: `Current system time: 2026-05-16 14:30:00`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Time service unavailable. | `Error: Service is not available.` |

### testhelper set-time

Sets the system time.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| time | Yes | Time string in the `YYYY-MM-DD HH:MM:SS` format.<br>**Value range:**<br>- Year: `1970-2038`.<br>- Month: `1-12`.<br>- Day: `1-31`, must conform to the actual calendar (e.g., February has no 30th).<br>- Hour: `0-23`.<br>- Minute: `0-59`.<br>- Second: `0-59`.|

**Usage example:**

```bash
hdc shell testhelper set-time 2026-05-16 14:30:00
```

Output example: `Set time to 2026-05-16 14:30:00 successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Invalid time format. | `Error: Invalid time format. Time must be in 'YYYY-MM-DD HH:MM:SS' format.` |
| Invalid time value (e.g., month is 13). | `Error: Invalid time value. 2026-13-01 00:00:00 is not a valid date and time.` |
| Time service unavailable. | `Error: Service is not available.` |

### testhelper get-timezone

Gets the current system timezone.

**Usage example:**

```bash
hdc shell testhelper get-timezone
```

Output example: `Current timezone: Asia/Shanghai`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Time service unavailable. | `Error: Service is not available.` |

### testhelper set-timezone

Sets the system time zone.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| timezone | Yes | Timezone identifier, for example, `Asia/Shanghai`. For valid values, see [Supported System Time Zones](../reference/apis-basic-services-kit/js-apis-system-time.md#supported-system-time-zones). |

**Usage example:**

```bash
hdc shell testhelper set-timezone Asia/Shanghai
```

Output example: `Set timezone to Asia/Shanghai successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Invalid timezone value. | `Error: Invalid timezone value. xxx is not a valid timezone identifier.` |
| Time service unavailable. | `Error: Service is not available.` |

### testhelper get-pastedata

Gets the text content of the clipboard.

**Usage example:**

```bash
hdc shell testhelper get-pastedata
```

Output example: `Pasteboard text: hello world`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Device does not support the clipboard feature. | `Error: Operation is not supported. Pasteboard is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper set-pastedata

Sets the clipboard text content.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| text | Yes | Text content to set. Maximum length: 128 MB. |

**Usage example:**

```bash
hdc shell testhelper set-pastedata "hello world"
```

Output example: `Pasteboard text set successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| The text is too long (exceeds 128 MB). | `Error: Text is too long. Maximum length is 128MB.` |
| The device does not support the clipboard feature. | `Error: Operation is not supported. Pasteboard is not supported on this device.` |
| The service is unavailable. | `Error: Service is not available.` |

### testhelper clear-pastedata

Clears the clipboard content.

**Usage example:**

```bash
hdc shell testhelper clear-pastedata
```

Output example: `Pasteboard text cleared successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Device does not support clipboard. | `Error: Operation is not supported. Pasteboard is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper hide-keyboard

Hide the input method keyboard.

**Usage example:**

```bash
hdc shell testhelper hide-keyboard
```

Output example: `Keyboard hidden successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| The device does not support the IMF feature.| `Error: Operation is not supported. IMF is not supported on this device.` |
| No active input method keyboard.| `Error: No active input method keyboard.` |
| Service unavailable.| `Error: Service is not available.` |

### testhelper get-fontname

Retrieves the font name from a font file.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| font-path | Yes | Absolute path of the font file.<br>**Path Requirement:**<br>- Path must be an absolute path under `/data/local/tmp`.<br>- File Format: Only supports `.ttf` and `.ttc`.<br>- Does not support paths containing `..`. |

**Usage example:**

```bash
hdc shell testhelper get-fontname /data/local/tmp/myfont.ttf
```

Output example: `Font name: MyFont`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Invalid path (not an absolute path under `/data/local/tmp`). | `Error: Invalid font path. Please provide a valid absolute path under the /data/local/tmp` |
| Invalid font file format (not `.ttf` or `.ttc`). | `Error: Invalid font file format. Only supports .ttf and .ttc files.` |
| Font file not found. | `Error: Font file not found: /data/local/tmp/myfont.ttf` |
| Device does not support font management feature (font management feature only supports Phone, PC/2in1, and Tablet devices). | `Error: Operation is not supported. Font management is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper install-font

Installs a font from a font file.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| font-path | Yes | Absolute path of the font file.<br>**Path Requirement:**<br>- The path must be an absolute path under `/data/local/tmp`.<br>- File format: Only supports `.ttf` and `.ttc`.<br>- Paths containing `..` are not supported.|

**Usage example:**

```bash
hdc shell testhelper install-font /data/local/tmp/myfont.ttf
```

Output example: `Font installed successfully from /data/local/tmp/myfont.ttf`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Invalid path (not an absolute path under `/data/local/tmp`). | `Error: Invalid font path. Please provide a valid absolute path under the /data/local/tmp` |
| Invalid font file format (not `.ttf` or `.ttc`). | `Error: Invalid font file format. Only supports .ttf and .ttc files.` |
| Font file not found. | `Error: Font file not found: /data/local/tmp/myfont.ttf` |
| Font is already installed. | `Error: Font is already installed.` |
| Device does not support font management feature (font management feature only supports Phone, PC/2in1, and Tablet devices). | `Error: Operation is not supported. Font management is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper uninstall-font

Uninstalls a font.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| font-name | Yes | Font name. You can obtain the font name corresponding to an installed font file using the [testhelper get-fontname](#testhelper-get-fontname) command. |

**Usage example:**

```bash
hdc shell testhelper uninstall-font MyFont
```

Output example: `Font uninstalled successfully: MyFont`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| The font name is empty. | `Error: Font not found: ` |
| The font is not found. | `Error: Font not found: MyFont` |
| The device does not support the font management feature (the font management feature only supports Phone, PC/2in1, and Tablet devices). | `Error: Operation is not supported. Font management is not supported on this device.` |
| The service is unavailable. | `Error: Service is not available.` |

### testhelper set-viewmode

Sets the display mode (dark/light mode).

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| mode | Yes | Display mode. The value can be `dark` (dark mode) or `light` (light mode). |

**Usage example:**

```bash
hdc shell testhelper set-viewmode dark
```

Output example: `Set view mode to dark successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| The mode value is invalid (not `dark` or `light`). | `Error: Invalid view mode. Mode must be 'dark' or 'light'.` |
| The device does not support display mode. | `Error: Operation is not supported. View mode is not supported on this device.` |
| The display mode is already set to the specified value. | `Error: View mode is already set to dark.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper enable-location-mock

Enables the location simulation function. After enabling, you can use the [testhelper set-mocked-locations](#testhelper-set-mocked-locations) command to set simulated location information.

**Usage example:**

```bash
hdc shell testhelper enable-location-mock
```

Output example: `Enable location mock successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| The device does not support the location simulation feature. | `Error: Operation is not supported. Location mock is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper disable-location-mock

Disable the location simulation function and restore the real location.

**Usage example:**

```bash
hdc shell testhelper disable-location-mock
```

Output example: `Disable location mock successfully.`

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Device does not support the location simulation feature. | `Error: Operation is not supported. Location mock is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

### testhelper set-mocked-locations

Sets a mocked location from a GPX file.

**Parameter description:**

| Name | Mandatory | Description |
|-----|------|------|
| path | Yes | Absolute path of the GPX file.<br>**Path Requirement:**<br>- Path must be an absolute path under `/data/local/tmp`.<br>- File Format: Only the `.gpx` extension is supported.<br>- Paths containing `..` are not supported.<br>- Maximum number of locations: 1000.|
| interval | No | Location update interval, in seconds.<br>- Value range: 1–3600 (integer).<br>- Default value: 1.|

**Usage example:**

```bash
hdc shell testhelper set-mocked-locations /data/local/tmp/locations.gpx 2
```

Output example: `Set mocked locations successfully.`

**GPX file format:**

testhelper supports the standard GPX 1.1 format and the following three types of location points:

- `<wpt>` (waypoint): A waypoint.

- `<trk>` (track): A track, containing `<trkseg>` and `<trkpt>`.

- `<rte>` (route): A route, containing `<rtept>`.

Each location point supports the following attributes:

- `lat` and `lon`: Latitude and longitude coordinates (Required), latitude range -90 to 90, longitude range -180 to 180.

- `<ele>`: Elevation (Optional, Unit: meters).

- `<time>`: Timestamp (Optional, ISO 8601 format).

- `<speed>`: Speed (Optional, Unit: meters/second, must be ≥0).

- `<direction>` or `<course>`: Direction (Optional, Unit: degrees, range 0-360).

**GPX file template example:**
`<wpt>` (waypoint) template example:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<gpx version="1.1" creator="TestHelper" xmlns="http://www.topografix.com/GPX/1/1">
  <wpt lat="22.5431" lon="114.0579">
    <ele>8.0</ele>
    <time>2024-01-15T09:00:00Z</time>
    <speed>25.0</speed>
    <direction>90.0</direction>
  </wpt>
  <wpt lat="22.5531" lon="114.0679">
    <ele>10.0</ele>
    <time>2024-01-15T09:01:00Z</time>
    <speed>28.0</speed>
    <direction>95.0</direction>
  </wpt>
</gpx>
```

`<trk>` (track) template example:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<gpx version="1.1" creator="TestHelper" xmlns="http://www.topografix.com/GPX/1/1">
  <metadata>
    <name>Location Simulation Track</name>
  </metadata>
  <trk>
    <name>Simulation Track</name>
    <trkseg>
      <trkpt lat="22.5431" lon="114.0579">
        <ele>8.0</ele>
        <time>2024-01-15T09:00:00Z</time>
        <speed>25.0</speed>
        <direction>90.0</direction>
      </trkpt>
      <trkpt lat="22.5531" lon="114.0679">
        <ele>10.0</ele>
        <time>2024-01-15T09:01:00Z</time>
        <speed>28.0</speed>
        <direction>95.0</direction>
      </trkpt>
    </trkseg>
  </trk>
</gpx>
```

`<rte>` (route) template example:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<gpx version="1.1" creator="TestHelper" xmlns="http://www.topografix.com/GPX/1/1">
  <rte>
    <rtept lat="22.5431" lon="114.0579">
      <ele>8.0</ele>
      <speed>25.0</speed>
      <direction>90.0</direction>
    </rtept>
    <rtept lat="22.5531" lon="114.0679">
      <ele>10.0</ele>
      <speed>28.0</speed>
      <direction>95.0</direction>
    </rtept>
  </rte>
</gpx>
```

**Exception scenario introduction:**

| Scenario | Print Information |
|-----|----------|
| Invalid Path (not an absolute path under `/data/local/tmp`). | `Error: Invalid path. Please provide a valid gpx file path under the /data/local/tmp` |
| Invalid GPX file extension (not `.gpx`). | `Error: Invalid path. Please provide a valid gpx file path under the /data/local/tmp` |
| Invalid GPX file format (XML format error, root element error, missing valid location points, etc.). | `Error: The parameter validation in gpx file has failed. xxx` (specific error message) |
| Invalid time interval (≤0 or >3600). | `Error: The parameter validation has failed. timeInterval must be greater than 0.` or `timeInterval must be less than 3600.` |
| Number of GPX file locations exceeds the limit (>1000). | `Error: The parameter validation in gpx file has failed. locations size must be less than 1000.` |
| The device does not support the location simulation feature. | `Error: Operation is not supported. Location mock is not supported on this device.` |
| Service unavailable. | `Error: Service is not available.` |

## FAQ

### Service unavailable (Error: Service is not available)

**Symptom**

When executing a command, the service unavailable (`Error: Service is not available.`) error message is returned.

**Possible Causes**

1. The related service is not started or has exited abnormally.

2. Device resources are insufficient, and the service cannot run normally.

**Solution**

Restart the device and try again.

### Parameter validation failure

**Symptom**

An error message related to parameter validation is returned when executing the command.

**Possible Causes**

1. Incorrect parameter format (such as time format, file path format, etc.).

2. Parameter value exceeds the limit range (such as time value, text length, number of locations, etc.).

3. File path does not meet the requirements (such as path prefix, file extension, etc.).

**Solution**

1. Check whether the parameter format meets the requirements.

2. Confirm that the parameter value is within the allowed range.

3. Ensure that the file path meets the requirements (for example, an absolute path under `/data/local/tmp` with the correct extension).