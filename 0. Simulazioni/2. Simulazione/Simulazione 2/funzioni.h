
#include "list.h"

Time timeDifference(Time t1, Time t2);

Time getTranslatedTime(Time t1, int min);

list readWorkers(char* nomeFile);

Worker insertNewEvent(Request* req, list l);