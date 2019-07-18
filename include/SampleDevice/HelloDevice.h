#ifndef HELLODEVICE_H_
#define HELLODEVICE_H_

#include <FairMQDevice.h>
#include <boost/property_tree/ptree.hpp>

class HelloDevice : public FairMQDevice
{
  public:
    HelloDevice();
    virtual ~HelloDevice();

  protected:
    boost::property_tree::ptree fTree;
    virtual void InitTask();
    virtual bool ConditionalRun();
};

#endif /* HELLODEVICE_H_ */
