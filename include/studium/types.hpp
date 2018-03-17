#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>
#include <cmath>
#include <cstdint>

namespace studium
{
    //! Unsigned integer sized at least 8 bits.
    typedef uint8_t   u8;
    //! Unsigned integer sized at least 16 bits.
    typedef uint16_t  u16;
    //! Unsigned integer sized at least 32 bits.
    typedef uint32_t  u32;
    //! Unsigned integer sized at least 64 bits.
    typedef uint64_t  u64;

    //! Signed integer sized at least 8 bits.
    typedef int8_t   i8;
    //! Signed integer sized at least 16 bits.
    typedef int16_t  i16;
    //! Signed integer sized at least 32 bits.
    typedef int32_t  i32;
    //! Signed integer sized at least 64 bits.
    typedef int64_t  i64;

    //! Wraps useful constant values.
    namespace consts
    {
        //! A sufficiently small number for general error correction.
        const float EPSILON = 1e-8;
        //! Float representation for the value of Pi.
        const float PI      = 3.14159265358979323846;
        //! Float representation for the value of Tau.
        //  Represents two times the value of Pi.
        const float TAU     = 6.28318530717958647692;
    }
}
