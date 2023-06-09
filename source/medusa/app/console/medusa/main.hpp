///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 10/18/2018, 10/17/2022
///////////////////////////////////////////////////////////////////////
#ifndef _MEDUSA_APP_CONSOLE_MEDUSA_MAIN_HPP
#define _MEDUSA_APP_CONSOLE_MEDUSA_MAIN_HPP

#include "medusa/app/console/medusa/main_opt.hpp"
#include "medusa/lib/medusa/version.hpp"

namespace medusa {
namespace app {
namespace console {
namespace medusa {

typedef ::medusa::app::console::medusa::main_opt::Implements main_implement;
typedef ::medusa::app::console::medusa::main_opt main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual protected main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char** argv, char** env) {
        int err = 0;
        if (!(err = version_run(argc, argv, env))) {
            this->outln();
            if (!(err = Extends::usage(argc, argv, env))) {
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int version_run(int argc, char** argv, char** env) {
        const lib::version& version = lib::medusa::version::which();
        this->outl(version.name(), " version = ", version.to_string().chars(), NULL);
        this->outln();
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} /// namespace medusa
} /// namespace console
} /// namespace app
} /// namespace medusa

#endif /// _MEDUSA_APP_CONSOLE_MEDUSA_MAIN_HPP 
