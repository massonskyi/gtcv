#ifndef _GTCV_OBJECTS_H_
#define _GTCV_OBJECTS_H_

#define GTCV_API_VERSION_MAJOR 0
#define GTCV_API_VERSION_MINOR 1
#define GTCV_API_VERSION_PATCH 0

#define GTCV_API_VERSION "0.1.0"
#define GTCV_API_VERSION_MAJOR_MINOR "0.1"
#define GTCV_API_VERSION_MAJOR_MINOR_PATCH "0.1.0"

#define GTCV_API_VERSION_MAJOR_OR_GREATER(major) (GTCV_API_VERSION_MAJOR >= major)
#define GTCV_API_VERSION_MINOR_OR_GREATER(minor) (GTCV_API_VERSION_MINOR >= minor)
#define GTCV_API_VERSION_PATCH_OR_GREATER(patch) (GTCV_API_VERSION_PATCH >= patch)

#define GTCV_API_DECLARE_ 
#define GTCV_API_IMPLEMENT_
#define GTCV_API_DEFINE_
#define GTCV_API_DECLARE_IMPLEMENT_
#define GTCV_API_DECLARE_DEFINE_
#define GTCV_API_IMPLEMENT_DEFINE_

#define GTCV_API_EXPORT extern "C" {
#define GTCV_API_IMPORT extern "C"
#define GTCV_API_UNUSED [[maybe_unused]]
#define GTCV_API_NORETURN [[noreturn]]
#define GTCV_API_DEPRECATED [[deprecated]]
#define GTCV_API_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#define GTCV_API_DEPRECATED_REPL(repl) [[deprecated(repl)]]
#define GTCV_API_DEPRECATED_REPL_MSG(repl, msg) [[deprecated(repl, msg)]]
#define GTCV_API_DEPRECATED_SINCE(since) [[deprecated(since)]]
#define GTCV_API_DEPRECATED_SINCE_MSG(since, msg) [[deprecated(since, msg)]]
#define GTCV_API_DEPRECATED_SINCE_REPL(since, repl) [[deprecated(since, repl)]]
#define GTCV_API_DEPRECATED_SINCE_REPL_MSG(since, repl, msg) [[deprecated(since, repl, msg)]]

#define GTCV_API_FALLTHROUGH [[fallthrough]]
#define GTCV_API_LIKELY [[likely]]
#define GTCV_API_UNLIKELY [[unlikely]]

#define GTCV_API_NOEXCEPT noexcept
#define GTCV_API_TEMPLATE template
#define GTCV_API_INLINE inline
#define GTCV_API_STATIC static
#define GTCV_API_CONSTEXPR constexpr
#define GTCV_API_CONSTEXPR_INLINE GTCV_API_CONSTEXPR GTCV_API_INLINE
#define GTCV_API_CONSTEXPR_STATIC GTCV_API_CONSTEXPR GTCV_API_STATIC
#define GTCV_API_CONSTEXPR_STATIC_INLINE GTCV_API_CONSTEXPR GTCV_API_STATIC GTCV_API_INLINE

#define GTCV_API_NULL NULL

#define GTCV_API_NULLPTR nullptr
#define GTCV_API_NULLPTR_T nullptr_t
#define GTCV_API_NULLPTR_T_DECL std::nullptr_t
#define GTCV_API_NULLPTR_T_DEF std::nullptr_t GTCV_API_NULLPTR

#define GTCV_API_CPP __cplusplus
#define GTCV_API_CPP_98 199711L
#define GTCV_API_CPP_03 199711L
#define GTCV_API_CPP_11 201103L
#define GTCV_API_CPP_14 201402L
#define GTCV_API_CPP_17 201703L
#define GTCV_API_CPP_20 202002L
#define GTCV_API_CPP_23 202300L

#define GTCV_API_CPP_98_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_98)
#define GTCV_API_CPP_03_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_03)
#define GTCV_API_CPP_11_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_11)
#define GTCV_API_CPP_14_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_14)
#define GTCV_API_CPP_17_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_17)
#define GTCV_API_CPP_20_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_20)
#define GTCV_API_CPP_23_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_23)

#define GTCV_API_C 199409L
#define GTCV_API_C_98 199409L
#define GTCV_API_C_99 199901L
#define GTCV_API_C_11 201112L
#define GTCV_API_C_17 201710L
#define GTCV_API_C_23 202300L

#define GTCV_API_C_98_OR_GREATER (GTCV_API_C >= GTCV_API_C_98)
#define GTCV_API_C_99_OR_GREATER (GTCV_API_C >= GTCV_API_C_99)
#define GTCV_API_C_11_OR_GREATER (GTCV_API_C >= GTCV_API_C_11)
#define GTCV_API_C_17_OR_GREATER (GTCV_API_C >= GTCV_API_C_17)
#define GTCV_API_C_23_OR_GREATER (GTCV_API_C >= GTCV_API_C_23)

#ifdef GTCV_API_CPP_11_OR_GREATER
    #define GTCV_API_AVAILABLE_BOOST __has_include(<boost/version.hpp>)
    #define GTCV_API_AVAILABLE_OPENCV __has_include(<opencv2/core/version.hpp>)
    #define GTCV_API_AVAILABLE_QT __has_include(<QtCore/QCoreApplication>)

    #if GTCV_API_AVAILABLE_BOOST
        #include <boost/version.hpp>
        #define GTCV_API_BOOST_AVAILABLE
    #endif /* GTCV_API_AVAILABLE_BOOST */

    #if GTCV_API_AVAILABLE_OPENCV
        #include <opencv2/opencv.hpp>
        #define GTCV_API_OPENCV_AVAILABLE
    #endif /* GTCV_API_AVAILABLE_OPENCV */

    #if GTCV_API_AVAILABLE_QT
        #include <QtCore/QCoreApplication>
        #define GTCV_API_QT_AVAILABLE
    #endif /* GTCV_API_AVAILABLE_QT */

    #define GTCV_OBJECT(className) GTCV_API_STATIC std::string getClassName() { return #className; }

    #define GTCV_API_NAMESPACE namespace GTCV_API {
    #define GTCV_API_NAMESPACE_END }

    #define GTCV_API ::GTCV_API::

    #define USING_GTCV_API using namespace GTCV_API;

#endif /* GTCV_API_CPP_11_OR_GREATER */

#endif /* _GTCV_OBJECTS_H_ */