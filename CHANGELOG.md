# Estimote Bluetooth Scanning Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).


## [0.1.1] - 2018-02-07

### Added

- Added `EBSScanInfoEstimoteEncrypted`. It allows scanning for frames encrypted with Estimote Secure Monitoring.


## [0.1.0] - 2018-01-22

### Added

- Added `EBSScanInfoGeneric` that scans for any packet with Estimote Service UUID that wasn't deserialized by other ScanInfo classes.


## [0.0.5] - 2018-01-04

### Changed

- Changed type of EstimoteBluetoothScanning to dynamic framework with slices for both iOS Simulator & iOS Device architectures.


## [0.0.4] - 2018-01-04

### Added

- Universal scanner has a protocol now (`EBSUniversalScannerProtocol`).
- The framework now contains a module map so it should be visible by dynamic frameworks.

### Changed

- `EBSUniversalScannerDelegate` methods changed the first parameter type from `EBSUniversalScanner *` to `id<EBSUniversalScannerProtocol>`.
- Scanning uses a different restarting rule now. It should result in more data when the app is in the background.
