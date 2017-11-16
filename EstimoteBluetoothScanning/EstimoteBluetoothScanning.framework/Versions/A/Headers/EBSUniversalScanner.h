//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "EBSScanInfo.h"


/**
 The possible errors returned during scanning Estimote Devices.
 */
typedef NS_ENUM(NSInteger, EBSUniversalScannerError)
{
    /** The platform does not support Bluetooth low energy. */
    EBSUniversalScannerErrorBluetoothNotSupported,

    /** The app is not authorized to use Bluetooth low energy. */
    EBSUniversalScannerErrorUnauthorizedToUseBluetooth,

    /** Bluetooth is currently powered off. */
    EBSUniversalScannerErrorBluetoothOff,
};

/**
 Restart interval value that causes Universal Scanner to restart scanning
 with each received packet automatically.
 */
#define EBSUniversalScannerRestartIntervalRestartAlways -INFINITY

/**
 Restart interval value that causes Universal Scanner to never restart automatically.
 */
#define EBSUniversalScannerRestartIntervalRestartNever INFINITY

@class EBSUniversalScanner;
@class EBSScanRestarter;

/**
 Defines the methods to receive info about scanned Estimote devices.
 */
@protocol EBSUniversalScannerDelegate <NSObject>

@optional

/**
 Invoked when a new scan info is available.
 
 @param universalScanner The scanner object that generated the event.
 @param ecoScanInfo The info about scanned device.
 */
- (void)universalScanner:(EBSUniversalScanner *)universalScanner
        didScanEstimoteDevice:(EBSScanInfo *)ecoScanInfo;

/**
 Invoked when an error occurred while scanning.
 
 @param universalScanner The scanner object that generated the event.
 @param error The error object containing information why scanning failed.
 */
- (void)universalScanner:(EBSUniversalScanner *)universalScanner
       didFailToScanWithError:(NSError *)error;

@end


/**
 `EBSUniversalScanner` objects are used to scan for Estimote logical devices.
 In order to scan for a specific logical device or a set of such, there should
 exist for each a subclass of `ECOScanInfo` implementing parsing logic.
 To start scan simply implement EBSUniversalScannerDelegate and invoke:
 NSArray *devicesToScan = @[ [`EBSScanInfoLogicalDevice1` class],
                             [`EBSScanInfoLogicalDevice2` class],
                             [`EBSScanInfoLogicalDevice3` class]];
 EBSUniversalScanner *universalScanner = [EBSUniversalScanner new];
 universalScanner.delegate = myEBSUniversalScannerDelegate;
 [universalScanner startScanForDevicesRepresentedByClasses:devicesToScan];
 */
@interface EBSUniversalScanner : NSObject

#pragma mark Properties

/**
 The delegate object to receive scan info events.
 */
@property (nonatomic, weak, readwrite) id<EBSUniversalScannerDelegate> delegate;

/**
 Informs if scan is in progress.
 */
@property (nonatomic, assign, readonly) BOOL isScanning;

/**
 An array of `ECOScanInfo` subclasses representing device types
 for which `EBSUniversalScanner` is scanning.
 */
@property (nonatomic, strong, readonly) NSArray<Class> *deviceTypesToScan;

/**
 Core Bluetooth Central Manager state.
 */
@property (nonatomic, assign, readonly) CBManagerState state;

/**
 Shared dispatch queue passed to CBCentralManagers upon creation.
 */
@property (nonatomic, strong, readonly, class) dispatch_queue_t defaultCBCentralManagerQueue;


#pragma mark Creating and Initializing

/**
 Designated initializer.
 Useful for testing. In production, use -initWithMinRestartInterval.

 @param cbCentralManager Central manager to be used to scan for peripherals.
 @param scanRestarter Restarter used to determine whether a scan restart should happen.
 */
- (instancetype)initWithCBCentralManager:(CBCentralManager *)cbCentralManager
                           scanRestarter:(EBSScanRestarter *)scanRestarter NS_DESIGNATED_INITIALIZER;

/**
 Convenience initializer.
 Creates a CBCentralManager object operating at +defaultCBCentralManagerQueue queue, a new EBSScanRestarter object
 with provided restartInterval and calls -initWithCBCentralManager:scanRestarter:.

 @param restartInterval The interval after which a restart would be triggered with a new packet.
                        Pass in EBSUniversalScannerRestartIntervalRestartAlways to set restarting with every packet,
                        EBSUniversalScannerRestartIntervalRestartNever to disable automatic restarting at all.
 */
- (instancetype)initWithMinRestartInterval:(NSTimeInterval)restartInterval;

/**
 Convenience initializer.
 Calls -initWithMinRestartInterval: with EBSUniversalScannerRestartIntervalRestartNever.

 @return Initialized object.
 */
- (instancetype)init;

#pragma mark Scanning for CB Devices

/**
 Start a scan for Estimote devices of specified types.
 Will override previous scan settings if scanner is scanning when the method is called.
 If at least one device type has no service defined `EBSUniversalScanner` won't scan in background.

 @param classesRepresentingDevices An array of `EBSScanInfo` subclasses representing device types to scan.
 */
- (void)startScanForDevicesRepresentedByClasses:(NSArray<Class> *)classesRepresentingDevices;

/**
 Stops the delivery of scan info.
 */
- (void)stopScan;

@end
