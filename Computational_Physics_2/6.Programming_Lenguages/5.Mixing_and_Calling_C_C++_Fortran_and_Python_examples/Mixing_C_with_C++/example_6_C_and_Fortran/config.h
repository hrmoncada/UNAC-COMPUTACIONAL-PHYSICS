#ifdef __cplusplus
extern "C" {
#endif

#define fooNew FCFUNC(foo_new,FOO_NEW)
void fooNew(void *, int *);

#define fooSetX FCFUNC(foo_setx,FOO_SETX)
void fooSetX(void *, float *, int *);

#define fooGetX FCFUNC(foo_getx,FOO_GETX)
void fooGetX(void *, float *, int *);

#define fooDel FCFUNC(foo_del,FOO_DEL)
void fooDel(void *);


#ifdef __cplusplus
}
#endif
