#ifndef WJ_ALLOCATOR_H__
#define WJ_ALLOCATOR_H__

#include <cstddef>
#include <cstdlib>
#include <climits>

namespace wj
{
    template<int inst>
    class __malloc_alloc_template
    {
    private:
        static void *oom_malloc(size_t);
    };
}

# endif