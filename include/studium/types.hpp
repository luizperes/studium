#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>
#include <cmath>
#include <cstdint>

namespace studium
{
    namespace types
    {
        typedef uint8_t   u8;
        typedef uint16_t  u16;
        typedef uint32_t  u32;
        typedef uint64_t  u64;

        typedef int8_t   i8;
        typedef int16_t  i16;
        typedef int32_t  i32;
        typedef int64_t  i64;
    }

    namespace consts
    {
        // "Sufficiently small" number for
        // general error correction
        const float EPSILON = 1e-8;
    }
}
