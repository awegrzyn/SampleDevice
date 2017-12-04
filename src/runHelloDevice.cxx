#include <fairmq/DeviceRunner.h>
#include "SampleDevice/HelloDevice.h"
#include "SampleDevice/ExamplePlugin.h"

int main(int argc, char* argv[]) {
  using namespace fair::mq;
  using namespace fair::mq::hooks;

  fair::mq::DeviceRunner runner{argc, argv};

  // load buil-in example plugin
  // 's:' - means static and it can only be used for plugins linked into the library at build time
  runner.AddHook<LoadPlugins>([](DeviceRunner& r){
    r.fPluginManager->LoadPlugin("s:example");
    // By default plugins are loaded dynamically
    // r.fPluginManager->LoadPlugin("example");
  });

  // start device
  runner.AddHook<InstantiateDevice>([](DeviceRunner& r){
    r.fDevice = std::make_shared<HelloDevice>();
  });

  return runner.RunWithExceptionHandlers();
}
