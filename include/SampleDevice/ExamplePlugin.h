#ifndef EXAMPLE_PLUGIN
#define EXAMPLE_PLUGIN

#include <fairmq/Plugin.h>

namespace example
{
class ExamplePlugin : public fair::mq::Plugin
{
  public:
    ExamplePlugin(
      const std::string name,
      const fair::mq::Plugin::Version version,
      const std::string maintainer,
      const std::string homepage,
      fair::mq::PluginServices* pluginServices
    );
    ~ExamplePlugin() = default;

};

auto ExamplePluginProgramOptions() -> fair::mq::Plugin::ProgOptions;

REGISTER_FAIRMQ_PLUGIN(
  ExamplePlugin, 					// Class name
  example, 						// Plugin name (string, lower case chars only)
  (fair::mq::Plugin::Version{1,0,0}), 			// Version
  "Adam Wegrzynek <adam.wegrzynek@cern.ch>", 		// Maintainer
  "https://github.com/awegrzyn/SampleDevice.git", 	// Homepage
  example::ExamplePluginProgramOptions 			// Free function which declares custom program options for the plugin
)

} /* namespace example */

#endif /* EXAMPLE_PLUGIN */
