 #include <iostream.h>

 template<class T> class junk {

   private:
    int inter;
    T   templ_mem;
    T   stor_val;

   public:
    junk(int i,T j): inter(i),templ_mem(j)
                     {cout <<"***Inside C++ constructor" << endl;}

     ~junk()          {cout <<"***Inside C++ Destructor"  <<	endl;}

    void store(T *val){ stor_val = *val;}

    void print(void) {cout << inter << "\t" << templ_mem ;
                      cout <<"\t" << stor_val << endl; }};

 template<class T> class temp {

   private:
     int internal;
     T temp_var;

   public:
     temp(int i, T j): internal(i),temp_var(j)
                      {cout <<"***Inside C++ temp Constructor" <<endl;}

      ~temp()          {cout <<"***Inside C++ temp destructor"  <<endl;}

     void print(void) {cout << internal << "\t" << temp_var << endl;}};