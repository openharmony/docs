# Multimodal Input<a name="EN-US_TOPIC_0000001086316185"></a>

## Overview<a name="section11660541593"></a>

OpenHarmony provides a Natural User Interface \(NUI\) for you to interact with your users. Unlike conventional categorization of input methods, OpenHarmony combines input methods of different dimensions into multimodal inputs, so you can easily arm your application with multi-dimensional, natural interaction features by using the application framework and system built-in UI components or APIs.

Specifically, OpenHarmony currently supports traditional input methods such as key and touch inputs.

## Directory Structure<a name="section14408467105"></a>

```
/foundation/multimodalinput/input
├── common                       # Common code
├── interfaces                   # External APIs
│   └── native                   # Native APIs
│       └── innerkits            # Native APIs provided for internal subsystems
├── service                      # Service framework code
├── sa_profile                   # Service startup configuration file
├── uinput                       # Input event injection module
```

## Usage<a name="section18111235161011"></a>

Available APIs of Multimodal Input are event injection ones, which are open only to system apps currently.

## Repositories Involved<a name="section135327891219"></a>

**Multimodal input subsystem**

[multimodalinput\_input](https://gitee.com/openharmony/multimodalinput_input)

