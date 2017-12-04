#ifndef HELLODEVICE_H_
#define HELLODEVICE_H_

#include <FairMQDevice.h>

class HelloDevice : public FairMQDevice
{
  public:
    HelloDevice();
    virtual ~HelloDevice();

  protected:
    virtual void InitTask();
};

#endif /* HELLODEVICE_H_ */
