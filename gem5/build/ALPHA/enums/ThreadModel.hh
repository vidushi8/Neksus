#ifndef __ENUM__Enums__ThreadModel__
#define __ENUM__Enums__ThreadModel__

namespace Enums {
    enum ThreadModel {
        Single = 0,
        SMT = 1,
        SwitchOnCacheMiss = 2,
        Num_ThreadModel = 3
    };
extern const char *ThreadModelStrings[Num_ThreadModel];
}

#endif // __ENUM__Enums__ThreadModel__
