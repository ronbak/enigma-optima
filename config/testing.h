#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

#ifndef SIMPLESCORE
//# define SIMPLESCORE
#endif

#ifndef TESTING
//# define TESTING
#endif

#ifdef TESTING
# define CONSTANT_SEED
#endif

#if !defined PROFILING && !defined TESTING && !defined DEBUG
#  define  LOW_PRIORITY
#endif

#endif // TESTING_H_INCLUDED
