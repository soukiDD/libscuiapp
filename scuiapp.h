#ifndef SAPP_SCUIAPP_H
#define SAPP_SCUIAPP_H

#include "sapp/sapp.h"

namespace slib {
    namespace sapp {

		class SCuiApp : public SApp {
			static stringarray PREDEFINED_COMMAND;

        public:
            SCuiApp();
            SCuiApp(const char *path);
            SCuiApp(SDictionary &&prof);
            virtual ~SCuiApp();
            
            int init(int argc, const char **argv);
            virtual int exec() = 0;
            int run(int argc, const char **argv);
        };
    }
}

#endif
