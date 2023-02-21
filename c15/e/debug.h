//
// Created by martin on 24/10/2021.
//

#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef DEBUG
#define PRINT_DEBUG(n) printf("value of " #n ": %d\n", n)
#else
#define PRINT_DEBUG(n)
#endif

#endif //_DEBUG_H_
