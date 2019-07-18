#include "SampleDevice/HelloDevice.h"
#include <fairmq/options/FairMQProgOptions.h>
#include <FairMQLogger.h>
#include <thread>
#include <chrono>

using namespace std;

HelloDevice::HelloDevice()
{
}

void HelloDevice::InitTask()
{
  fTree = fConfig->GetValue<boost::property_tree::ptree>("array");
}

bool HelloDevice::ConditionalRun() {
  LOG(INFO) << fTree.get<int>("id");
  auto anArray = fTree.get_child("array");
  for (auto const &it: anArray) {
    LOG(INFO) << it.second.get<std::string>("name");
  }
  this_thread::sleep_for(chrono::seconds(1));
  return true;
}

HelloDevice::~HelloDevice()
{
}
