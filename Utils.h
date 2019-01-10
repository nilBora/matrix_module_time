#ifndef UTILS_H
#define UTILS_H
    
#if ARDUINO >= 100
 #include <Arduino.h>
 #include <string.h>
#else
 #include <WProgram.h>
#endif
    
class Utils {
    public:
        Utils();
        ~Utils();
        String utf8rus(String source);
};

#endif