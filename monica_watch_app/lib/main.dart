import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutter_blue_plus/flutter_blue_plus.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // TRY THIS: Try running your application with "flutter run". You'll see
        // the application has a purple toolbar. Then, without quitting the app,
        // try changing the seedColor in the colorScheme below to Colors.green
        // and then invoke "hot reload" (save your changes or press the "hot
        // reload" button in a Flutter-supported IDE, or press "r" if you used
        // the command line to start the app).
        //
        // Notice that the counter didn't reset back to zero; the application
        // state is not lost during the reload. To reset the state, use hot
        // restart instead.
        //
        // This works for code too, not just values: Most code changes can be
        // tested with just a hot reload.
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const MyHomePage(title: 'Flutter - Monica OTA Tools'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

extension SplitWrite on BluetoothCharacteristic {
  Future<void> splitWrite(List<int> value, {int timeout = 15}) async {
    int chunk = device.mtuNow - 3; // 3 bytes ble overhead
    print(device.mtuNow); // 515
    for (int i = 0; i < value.length; i += chunk) {
      List<int> subValue = value.sublist(i, min(i + chunk, value.length));
      await write(subValue, withoutResponse: false, timeout: timeout);
    }
  }
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;
  BluetoothDevice? _connectedDevice;

  Future<void> _onButtonClicked() async {
    if (_connectedDevice == null) {
      await _startScanAndConnect();
    } else {
      await _connectedDevice!.disconnect();
      _connectedDevice = null;
    }
    setState(() {
      // This call to setState tells the Flutter framework that something has
      // changed in this State, which causes it to rerun the build method below
      // so that the display can reflect the updated values. If we changed
      // _counter without calling setState(), then the build method would not be
      // called again, and so nothing would appear to happen.
      _counter++;
    });
  }

  Future<void> _startScanAndConnect() async {
    // listen to scan results
    // Note: `onScanResults` only returns live scan results, i.e. during scanning
    // Use: `scanResults` if you want live scan results *or* the results from a previous scan
    var subscription = FlutterBluePlus.onScanResults.listen(
      (results) async {
        if (results.isNotEmpty) {
          ScanResult r = results.last; // the most recently found device
          print(
              '${r.device.remoteId}: "${r.advertisementData.advName}" found!');
          var device = r.device;
          var subscription = device.connectionState.listen((state) async {
            if (state == BluetoothConnectionState.disconnected) {
              print("${device.disconnectReason}");
            }
          });
          device.cancelWhenDisconnected(subscription,
              delayed: true, next: true);
          await device.connect();
          _connectedDevice = device;
          List<BluetoothService> services = await device.discoverServices();
          for (var service in services) {
            // Reads all characteristics
            var characteristics = service.characteristics;
            for (BluetoothCharacteristic c in characteristics) {
              if (c.properties.read) {
                List<int> value = await c.read();
                print(value);
              } else if (c.properties.write) {
                var intList = List<int>.generate(513, (index) => index);
                await c.splitWrite(intList);
              }
            }
          }
        }
      },
      onError: (e) => print(e),
    );

    // cleanup: cancel subscription when scanning stops
    FlutterBluePlus.cancelWhenScanComplete(subscription);

    // Wait for Bluetooth enabled & permission granted
    // In your real app you should use `FlutterBluePlus.adapterState.listen` to handle all states
    await FlutterBluePlus.adapterState
        .where((val) => val == BluetoothAdapterState.on)
        .first;

    // Start scanning w/ timeout
    // Optional: you can use `stopScan()` as an alternative to using a timeout
    // Note: scan filters use an *or* behavior. i.e. if you set `withServices` & `withNames`
    //   we return all the advertisments that match any of the specified services *or* any
    //   of the specified names.
    await FlutterBluePlus.startScan(
        // withServices: [Guid("180D")],
        withNames: ["UART Service"],
        timeout: const Duration(seconds: 15));

    // wait for scanning to stop
    await FlutterBluePlus.isScanning.where((val) => val == false).first;
  }

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        // TRY THIS: Try changing the color here to a specific color (to
        // Colors.amber, perhaps?) and trigger a hot reload to see the AppBar
        // change color while the other colors stay the same.
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: Text(widget.title),
      ),
      body: Center(
        // Center is a layout widget. It takes a single child and positions it
        // in the middle of the parent.
        child: Column(
          // Column is also a layout widget. It takes a list of children and
          // arranges them vertically. By default, it sizes itself to fit its
          // children horizontally, and tries to be as tall as its parent.
          //
          // Column has various properties to control how it sizes itself and
          // how it positions its children. Here we use mainAxisAlignment to
          // center the children vertically; the main axis here is the vertical
          // axis because Columns are vertical (the cross axis would be
          // horizontal).
          //
          // TRY THIS: Invoke "debug painting" (choose the "Toggle Debug Paint"
          // action in the IDE, or press "p" in the console), to see the
          // wireframe for each widget.
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              'Click to upgrade Monica firmware over BLE:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
          ],
        ),
      ),
      floatingActionButton:
          buildButtons(), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }

  Widget buildButtons() {
    // return Padding(
    //     padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 12),
    //     child: Row(
    //       children: [
    //         FloatingActionButton(
    //           onPressed: _onButtonClicked,
    //           tooltip: "Stop",
    //           backgroundColor: Colors.accents.first,
    //           child: const Icon(Icons.stop),
    //         ),
    //         const Spacer(),
    //         FloatingActionButton(
    //           onPressed: () {},
    //           child: const Icon(Icons.add),
    //         ),
    //       ],
    //     ));
    return FloatingActionButton(
      onPressed: _onButtonClicked,
      tooltip: 'Connect/Disconnect',
      child: const Icon(Icons.add),
    );
  }
}
