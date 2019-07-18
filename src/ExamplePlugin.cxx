#include "SampleDevice/ExamplePlugin.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

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
          std::string withArray = "{ \"id\" : \"123\", \"array\" : [{ \"name\" : \"alice\" }, { \"name\" : \"bob\" }] }";
          using boost::property_tree::ptree;
          ptree pt;
          std::istringstream is(withArray);
          read_json(is, pt);
          SetProperty("array", pt);
        }
        break;
        case DeviceState::Exiting:
          UnsubscribeFromDeviceStateChange();
        break;
      }
    }
  );
}

auto ExamplePluginProgramOptions() -> fair::mq::Plugin::ProgOptions
{
  auto plugin_options = boost::program_options::options_description{"Example Plugin"};
  return plugin_options;
}

} /* namespace example */
