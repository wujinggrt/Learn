/*
测试编译器的常量设定
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
#if defined(__sgi)
    cout << "__sgi" << endl;
#endif

#if defined(__GNUC__)
cout << "__GNUC__" << endl;
cout << __GNUC__ << ' ' << __GNUC_MINOR__ << endl;
#endif

#ifdef __STL_NO_DRAND48
    cout << "__STL_NO_DRAND48 defined" << endl;
#else
    cout << "__STL_NO_DRAND48 undefined" << endl;
#endif

#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
    cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG" << " defined" << endl;
#else
    cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG"  << " undefined" << endl; 
#endif

#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
    cout << "__STL_CLASS_PARTIAL_SPECIALIZATION" << " defined" << endl;
#else
    cout << "__STL_CLASS_PARTIAL_SPECIALIZATION" << " undefined" << endl;
#endif

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
    cout << "__STL_FUNCTION_TMPL_PARTIAL_ORDER" << " defined" << endl;
#else
    cout << "__STL_FUNCTION_TMPL_PARTIAL_ORDER" << " undefined" << endl;
#endif

cout << "__STL_EXPLICIT_FUNCTION_TMPL_ARGS"
#ifdef __STL_EXPLICIT_FUNCTION_TMPL_ARGS
<< " defined"
#else
<< " notdefined"
#endif
<< endl;

cout << "__STL_MEMBER_TEMPLATES"
#ifdef __STL_MEMBER_TEMPLATES
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_LIMITED_DEFAULT_TEMPLATES"
#ifdef __STL_LIMITED_DEFAULT_TEMPLATES
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_NON_TYPE_TMPL_PARAM_BUG"
#ifdef __STL_NON_TYPE_TMPL_PARAM_BUG
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__SGI_STL_NO_ARROW_OPERATOR"
#ifdef __SGI_STL_NO_ARROW_OPERATOR
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_USE_EXCEPTIONS"
#ifdef __STL_USE_EXCEPTIONS
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_USE_NAMESPACES"
#ifdef __STL_USE_NAMESPACES
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_SGI_THREADS"
#ifdef __STL_SGI_THREADS
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_WIN32THREADS"
#ifdef __STL_WIN32THREADS
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << endl;


cout << "__STL_NO_NAMESPACES"
#ifdef __STL_NO_NAMESPACES
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_NEED_TYPENAME"
#ifdef __STL_NEED_TYPENAME
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_NEED_BOOL"
#ifdef __STL_NEED_BOOL
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_NEED_EXPLICIT"
#ifdef __STL_NEED_EXPLICIT
<< " defined"
#else
<< " undefined"
#endif
<< endl;

cout << "__STL_ASSERTIONS"
#ifdef __STL_ASSERTIONS
<< " defined"
#else
<< " undefined"
#endif
<< endl;

/*
all of them are undefined
*/

return 0;
}
