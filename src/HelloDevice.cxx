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
  string* text = new string(fText);

  FairMQMessagePtr msg(NewMessage(const_cast<char*>(text->c_str()),
    text->length(),
    [](void* /*data*/, void* object) { delete static_cast<string*>(object); },
    text));

  if (Send(msg, "data") < 0) {
    return false;
  }

  LOG(INFO) << "From device: " << "custom-example-option = " << (fText.empty() ? "<empty>" : fText);

  for (const auto& mi : fChannels) {
    for (const auto& vi : mi.second) {
      LOG(DEBUG) << "BytesTx = " << vi.GetBytesTx();
      LOG(DEBUG) << "BytesRx = " << vi.GetBytesRx();
      LOG(DEBUG) << "MessagesTx = " << vi.GetMessagesTx();
      LOG(DEBUG) << "MessagesRx = " << vi.GetMessagesRx();
    }
  }

  this_thread::sleep_for(chrono::seconds(1));
  return true;
}

HelloDevice::~HelloDevice()
{
}
