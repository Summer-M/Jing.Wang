
#include "../Variable/Variable.h"
#include "../Thread/Thread.h"

// static 
unsigned int MYThread<SortType>::sortindex(0);
vector<SortType> MYThread<SortType>::sortnums(0);
string MYThread<SortType>::modelinSort("");