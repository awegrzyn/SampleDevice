#include "SampleDevice/HelloDevice.h"
#include <fairmq/options/FairMQProgOptions.h>
#include <FairMQLogger.h>
#include <thread>
#include <chrono>

using namespace std;

HelloDevice::HelloDevice()
  : fText()
{
}

void HelloDevice::InitTask()
{
   fText = fConfig->GetValue<string>("custom-example-option");
}

bool HelloDevice::ConditionalRun() {
  LOG(INFO) << "From device: " << "custom-example-option = " << (fText.empty() ? "<empty>" : fText);

  this_thread::sleep_for(chrono::seconds(1));
  return true;
}

HelloDevice::~HelloDevice()
{
}
