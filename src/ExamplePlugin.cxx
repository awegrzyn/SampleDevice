#include "SampleDevice/ExamplePlugin.h"

namespace example
{

ExamplePlugin::ExamplePlugin(
  const std::string name,
  const fair::mq::Plugin::Version version,
  const std::string maintainer,
  const std::string homepage,
  fair::mq::PluginServices* pluginServices)
  : fair::mq::Plugin(name, version, maintainer, homepage, pluginServices)
{
  // Read "custom-example-option" in InitializingDevice device state
  SubscribeToDeviceStateChange(
    [&](DeviceState newState) {
      switch (newState) {
        case DeviceState::InitializingDevice:
        {
          std::string anOption = GetPropertyAsString("custom-example-option");
          LOG(INFO) << "custom-example-option = " << (anOption.empty() ? "<empty>" : anOption);
        }
        break;
        case DeviceState::Exiting:
          UnsubscribeFromDeviceStateChange();
        break;
      }
    }
  );

  SubscribeToPropertyChange<int>([](const std::string& key, int value) {
    LOG(INFO) << "Key: " << key << ", Value: " << value;
  });
}

// define additional options required by plugin ("custom-example-option")
auto ExamplePluginProgramOptions() -> fair::mq::Plugin::ProgOptions
{
    auto plugin_options = boost::program_options::options_description{"Example Plugin"};
    plugin_options.add_options()
        ("custom-example-option", boost::program_options::value<std::string>(), "Custom option.");
    return plugin_options;
}

} /* namespace example */
