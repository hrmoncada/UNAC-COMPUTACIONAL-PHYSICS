/*https://www.ibm.com/support/knowledgecenter/SSGH4D_15.1.3/com.ibm.xlf1513.aix.doc/proguide/cwrap.html */
 #include <stdio.h>
 #include "cplus.h"

 extern "C" void cfun(int *idim){
   printf("%%%Inside C function before creating C++ Object\n");
   int i = *idim;
   junk<int>* jj= new junk<int>(10,30);
   jj->store(idim);
   jj->print();
   printf("%%%Inside C function after creating C++ Object\n");
   delete jj;
   return;
 }

 extern "C" void cfun1(int *idim1) {
   printf("%%%Inside C function cfun1 before creating C++ Object\n");
   int i = *idim1;
   temp<double> *tmp = new temp<double>(40, 50.54);
   tmp->print();
   printf("%%%Inside C function after creating C++ temp object\n");
   delete tmp;
   return;
 }