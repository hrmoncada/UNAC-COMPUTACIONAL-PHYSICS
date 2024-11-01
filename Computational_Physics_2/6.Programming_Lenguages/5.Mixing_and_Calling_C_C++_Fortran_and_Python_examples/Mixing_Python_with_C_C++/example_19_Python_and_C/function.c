/* https://www.geeksforgeeks.org/how-to-call-a-c-function-in-python/?ref=lbp
 * 
 * gcc -fPIC -shared -o libfun.so function.c
 */

int myFunction(int num) {
    if (num == 0)

        // if number is 0, do not perform any operation.
        return 0;
    else
        // if number is power of 2, return 1 else return 0
        return ((num & (num - 1)) == 0 ? 1 : 0) ;

}
