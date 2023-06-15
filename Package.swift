// swift-tools-version:5.7
import PackageDescription


let package = Package(
    name: "EstimoteBluetoothScanning",
    platforms: [
        .iOS(.v10)
    ],
    products: [
        .library(
            name: "EstimoteBluetoothScanning",
            targets: [
                "EstimoteBluetoothScanning"
            ]
        )
    ],
    targets: [
        .binaryTarget(
            name: "EstimoteBluetoothScanning",
            path: "./EstimoteBluetoothScanning/EstimoteBluetoothScanning.xcframework"
        )
    ]
)