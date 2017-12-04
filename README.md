# Sample Device with Built-in Plugin

## Installation

1. Install `O2`/`FairRoot`
```
aliBuild build O2 --defaults o2-daq
```

2. Load env
```
alienv load O2/latest-o2-daq
```

3. Compile device with built-in plugin
```
git clone git@github.com:awegrzyn/SampleDevice.git
mkdir -p SampleDevice/build; cd SampleDevice/build
cmake ..
make -j
```

4. Run device
```
./bin/HelloDevice
```

### Based on:
- [FairMQPlugin_example](https://github.com/FairRootGroup/FairMQPlugin_example)
- [Sampler-Sink example](https://github.com/FairRootGroup/FairRoot/tree/master/examples/MQ/1-sampler-sink)
