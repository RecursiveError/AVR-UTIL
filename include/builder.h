#ifndef __builder_H
#define __builder_H

#define invoke(T) new_##T
#define builder(T,...) invoke(T)(__VA_ARGS__);

#endif