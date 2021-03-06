/**********************************************************\
|                                                          |
|                          hprose                          |
|                                                          |
| Official WebSite: http://www.hprose.com/                 |
|                   http://www.hprose.org/                 |
|                                                          |
\**********************************************************/

/**********************************************************\
 *                                                        *
 * hprose/formatter.h                                     *
 *                                                        *
 * hprose formatter library for php-cpp.                  *
 *                                                        *
 * LastModified: Jul 13, 2014                             *
 * Author: Ma Bingyao <andot@hprose.com>                  *
 *                                                        *
\**********************************************************/

#ifndef HPROSE_FORMATTER_H_
#define HPROSE_FORMATTER_H_

#include <phpcpp.h>

namespace Hprose {
    class Formatter : public Php::Base {
    public:
        inline static Php::Value serialize(Php::Parameters &params) {
            return Hprose::serialize(params);
        }
        inline static Php::Value unserialize(Php::Parameters &params) {
            return Hprose::unserialize(params);
        }
    };

    inline void publish_formatter(Php::Extension &ext) {
        Php::Class<Hprose::Formatter> c("HproseFormatter");
        c.method("__construct", Php::Private )
        .method("serialize",
                &Hprose::Formatter::serialize,
                Php::Static | Php::Public,
                {
                    Php::ByVal("v", Php::Type::Null),
                    Php::ByVal("simple", Php::Type::Bool, false)
                })
        .method("unserialize",
                &Hprose::Formatter::unserialize,
                Php::Static | Php::Public,
                {
                    Php::ByVal("s", Php::Type::String),
                    Php::ByVal("simple", Php::Type::Bool, false)
                },
                true);
        ext.add(std::move(c));
    }
}

#endif /* HPROSE_FORMATTER_H_ */