/*https://riptutorial.com/c/example/13401/--cplusplus-for-using-c-externals-in-cplusplus-code-compiled-with-cplusplus---name-mangling
*/

float cppfunction(float *); // C++ prototype
 
extern "C" {
   int cfunction(int *); // C prototype
}
