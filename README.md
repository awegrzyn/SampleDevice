# Sample Device with Built-in Plugin

## Installation

1. Install `FairMQ`
```
aliBuild build FairMQ --defaults o2-dataflow
```

2. Load env
```
alienv load FairMQ/latest-o2-dataflow
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
./bin/HelloDevice --id hello --custom-example-option sample-value
```

### Based on:
- [FairMQPlugin_example](https://github.com/FairRootGroup/FairMQPlugin_example)
- [Sampler-Sink example](https://github.com/FairRootGroup/FairRoot/tree/master/examples/MQ/1-sampler-sink)
