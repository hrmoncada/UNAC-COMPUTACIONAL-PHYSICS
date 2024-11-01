/** https://nesi.github.io/perf-training/python-scatter/ctypes
 * Compute the sum an array
 * @param n number of elements
 * @param array input array
 * @return sum

$ bash Compile.sh
  mkdir build_2
  g++ -c -fPIC src/mysum.cpp -o build_2/mysum.so
  g++ -shared -Wl,-soname,libmysum.so -o build_2/libmysum.so  build_2/mysum.so
 */

extern "C" // required when using C++ compiler

long long mysum(int n, int* array) {
    // return type is 64 bit integer
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += array[i];
    }
    return res;
}
