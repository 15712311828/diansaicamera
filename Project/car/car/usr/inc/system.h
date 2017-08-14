#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include"pit.h"

class System{
public:
  System();
  void interruptCallbackInstall(PIT_CallBackType callback);
  void interruptStart();
};


#endif  //_SYSTEM_H_