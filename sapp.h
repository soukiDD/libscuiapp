#ifndef __SAPP_SAPP_H__
#define __SAPP_SAPP_H__

#include "sobj.h"
#if defined(WIN32_OS) || defined(WIN64_OS)
#else
#include <dlfcn.h>
#endif

namespace slib {
    namespace sapp {
        
        #if defined(MAC_OS)
        #define DEFAULT_PREF_PATH "~/Library/Preferences"
        #define DEFAULT_LOG_PATH "~/Library/Logs"
        #define DEFAULT_APPDATA_PATH "~/Documents"
        #elif defined(WIN32_OS) || defined(WIN64_OS)
        #define DEFAULT_PREF_PATH "~/AppData/Preferences"
        #define DEFAULT_LOG_PATH "~/Logs"
        #define DEFAULT_APPDATA_PATH "~/AppData"
        #elif defined(UNIX_OS) || defined(LINUX_OS)
        #define DEFAULT_PREF_PATH "~/Preferences"
        #define DEFAULT_LOG_PATH "~/Logs"
        #define DEFAULT_APPDATA_PATH "~/Documents"
        #endif
        
        #define SAPP_ERROR 0x0A00
        #define SAPP_ERROR_EXIT 0x0A01
        #define SAPP_INIT_ERROR 0x0A02
        
        #define INSUFFICIENT_ARGS_ERROR 0x0A11
        #define INSUFFICIENT_OPT_ERROR 0x0A12
        #define COMMAND_NOT_EXIST_ERROR 0x0A13
        #define OPTION_NOT_EXIST_ERROR 0x0A14
        
        #define PLUGIN_LOAD_ERROR 0x0A21
        #define PLUGIN_EXEC_ERROR 0x0A22
        #define PLUGIN_NOT_EXIST_ERROR 0x0A23
        
        #define SAPP_LAUNCH 0x0AF0
        #define SAPP_TERMINATE 0x0AF1
        #define SAPP_PROGRESS 0x0AF2
        
        #define SAPP_EXECTED 0x0AFF
        
        
        class SAppException : public SException {
        public:
            SAppException(const char* f, sint l, const char* func, sint e = 0, const char* target = nullptr, const char* note = nullptr);
            ~SAppException();
        };
        
        class SApp {
        public:
            SDictionary profile, preference;
            
        public:
            SApp();
            SApp(const char *path);
            SApp(SDictionary &&prof);
            virtual ~SApp();
            
            virtual int run(int argc, const char **argv) = 0;
            virtual int init(int argc, const char **argv) = 0;
            virtual int exec() = 0;
        };
        
    }
}

#endif
