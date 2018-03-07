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
   fText = fConfig->GetValue<string>("text");
}

bool HelloDevice::ConditionalRun() {
  string* text = new string(fText);

  FairMQMessagePtr msg(NewMessage(const_cast<char*>(text->c_str()),
    text->length(),
    [](void* /*data*/, void* object) { delete static_cast<string*>(object); },
    text));

  if (Send(msg, "data") < 0) {
    return false;
  }
  std::string option = fConfig->GetValue<string>("custom-example-option");
  LOG(INFO) << "From device: " << "custom-example-option = " << (option.empty() ? "<empty>" : option);
  this_thread::sleep_for(chrono::seconds(1));
  return true;
}

HelloDevice::~HelloDevice()
{
}
