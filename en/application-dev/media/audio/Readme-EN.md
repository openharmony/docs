# Audio Kit

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=fd8ed1a59024b16bfd80938b476bae38fb83db08 translatedAt=2026-08-06T13:40:56.247Z pushedAt=2026-08-07T02:13:07.577Z -->

- [About This Kit](audio-kit-intro.md)

- Audio Focus and Audio Session Management<!--audio-session-->

  - [Audio Focus and Audio Session Overview](audio-playback-concurrency-audio-session-overview.md)

  - [Introduction to Audio Focus](audio-playback-concurrency.md)

  - [Audio Session Management (ArkTS)](audio-session-management.md)

  - [Using OHAudio for Audio Session (C/C++)](using-ohaudio-for-session.md)

- Audio Playback<!--audio-playback-->

  - [Audio Playback Development](audio-playback-overview.md)

  - [Choosing the Right Playback Stream Type](using-right-streamusage-for-playback.md)

  - [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md)

  - [Using AudioRenderer for Audio Playback (ArkTS)](using-audiorenderer-for-playback.md)

  <!--Del-->

  - [Using TonePlayer for Audio Playback (for System Applications Only)](using-toneplayer-for-playback-sys.md)

  <!--DelEnd-->

  - [Low-Latency Audio Playback (C/C++)](audio-fast-playback.md)

  - [Low-Power Audio Playback](power-saving-for-playback.md)

  - [Using AudioHaptic for Audio-Haptic Playback (ArkTS)](using-audiohaptic-for-playback.md)

  - [Using SoundPlayer for System Sound Effect Playback](using-soundplayer-for-playback.md)

  - [Volume Management](volume-management.md)

  - [Spatial Audio Capability Query and Status Subscription](public-audio-spatialization-management.md)

  <!--Del-->

  - [Spatial Audio Management (for System Applications Only)](audio-spatialization-management-sys.md)

  <!--DelEnd-->

  - [Audio Playback Stream Management](audio-playback-stream-management.md)

  <!--Del-->

  - [Distributed Audio Playback (for System Applications Only)](distributed-audio-playback-sys.md)

  <!--DelEnd-->
  <!--Del-->

  - [Collaborative Audio Management (for System Applications Only)](audio-collaborative-management-sys.md)

  <!--DelEnd-->

- Audio Recording<!--audio-recording-->

  - [Audio Recording Development](audio-recording-overview.md)

  - [Choosing the Right Recording Stream Type](using-right-sourcetype-for-recording.md)

  - [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md)

  - [Using AudioCapturer for Audio Recording (ArkTS)](using-audiocapturer-for-recording.md)

  - [Low-Latency Audio Recording (C/C++)](audio-fast-recording.md)

  - [Implementing Background Recording](background-recording.md)

  - [Managing Microphone Mute State](mic-management.md)

  - [Querying and Listening for the Recording Status of Other Applications](audio-recording-stream-management.md)

  - [Recording Concurrency Strategy Description](audio-recording-concurrency.md)

  - [Implementing Custom Audio Monitoring](audio-ear-monitor.md)

  - [Implementing Low-Latency Audio Monitoring](audio-ear-monitor-loopback.md)

- Audio Device Routing Management<!--audio-device-->

  - [Querying and Listening for Audio Input Devices](audio-input-device-management.md)

  - [Querying and Listening for Audio Output Devices](audio-output-device-management.md)

  - [Switching Audio Input Devices](audio-input-device-switcher.md)

  - [Switching Audio Output Devices](audio-output-device-switcher.md)

  - [Handling Output Device Changes Gracefully](audio-output-device-change.md)

- Audio Call<!--audio-call-->

  - [Audio Call Overview](audio-call-overview.md)

  - [Developing Audio Call](audio-call-development.md)

- Audio Performance Optimization<!--audio-performance-optimization-->

  - [Enhancing Audio Performance Experience](audio-performance.md)

  - [Audio Workgroup Management](audio-workgroup.md)

- Audio Creation<!--audio-production-creation-->

  - [Audio Creation Overview (C/C++)](audio-suite.md)

  - [Offline Editing (C/C++)](audio-suite-manual-rendering.md)

  - [Real-Time Preview (C/C++)](audio-suite-real-time-rendering.md)

  - [Audio Format Conversion (C/C++)](audio-suite-format-converter.md)

  - [Spatial Rendering (C/C++)](audio-suite-space-render.md)

- MIDI Device Communication<!--midi-->

  - [OH_MIDI Overview (C/C++)](midi-overview.md)

  - [Using OH_MIDI for MIDI Development (C/C++)](using-ohmidi.md)

- OpenSL ES Development (Not Recommended)<!--not-recommended-->

  - [Switching from OpenSL ES to OHAudio (C/C++)](replace-opensles-by-ohaudio.md)

  - [Using OpenSL ES for Audio Playback (C/C++)](using-opensl-es-for-playback.md)

  - [Using OpenSL ES for Audio Recording (C/C++)](using-opensl-es-for-recording.md)

- Audio Kit FAQs<!--audio-issues-->

  - [Using Audio Snapshots for Troubleshooting](audio-runtime-debugging-info.md)

  - [Troubleshooting Silent Playback Issues](audio-playback-no-sound-troubleshooting.md)

  - [Troubleshooting Playback Stuttering and Noise Issues](audio-playback-performance-troubleshooting.md)

  - [Troubleshooting Silent Recording Issues](audio-recording-no-audio-troubleshooting.md)

- [Glossary](audio-glossary.md)