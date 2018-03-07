#ifndef HELLODEVICE_H_
#define HELLODEVICE_H_

#include <FairMQDevice.h>

class HelloDevice : public FairMQDevice
{
  public:
    HelloDevice();
    virtual ~HelloDevice();

  protected:
    std::string fText;
    virtual void InitTask();
    virtual bool ConditionalRun();
};

#endif /* HELLODEVICE_H_ */
